import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from nash_interfaces.msg import RobotState, NashDecision
import math
import random

GOAL_TOL    = 0.25
MAX_LINEAR  = 0.22
MAX_ANGULAR = 2.84

# Reactive avoidance: bend trajectory around any peer robot that comes
# closer than AVOID_DIST. Lower MIN_SLOWDOWN slows down near a peer.
AVOID_DIST    = 0.9   # m — start steering away inside this radius
AVOID_GAIN    = 1.6   # how hard to steer away (heading bias, rad)
MIN_SLOWDOWN  = 0.35  # speed multiplier when right on top of a peer
NUM_ROBOTS    = 3

# Cardinal endpoints around the centre — each robot cycles through them
# so straight-line paths always pass through the origin (the conflict zone).
ARM_REACH = 2.5
CARDINAL_GOALS = [
    ( ARM_REACH,  0.0),   # East
    (-ARM_REACH,  0.0),   # West
    ( 0.0,  ARM_REACH),   # North
    ( 0.0, -ARM_REACH),   # South
]


class RobotAgentNode(Node):
    def __init__(self):
        super().__init__('robot_agent')

        self.declare_parameter('robot_id',  'robot1')
        self.declare_parameter('goal_x',    2.0)
        self.declare_parameter('goal_y',    0.0)
        self.declare_parameter('start_x',   0.0)   # spawn world X
        self.declare_parameter('start_y',   0.0)   # spawn world Y
        self.declare_parameter('start_yaw', 0.0)   # spawn world yaw (rad)

        self.robot_id  = self.get_parameter('robot_id').value
        self.goal_x    = self.get_parameter('goal_x').value
        self.goal_y    = self.get_parameter('goal_y').value
        self.start_x   = self.get_parameter('start_x').value
        self.start_y   = self.get_parameter('start_y').value
        self.start_yaw = self.get_parameter('start_yaw').value

        # Pose as reported by /robotN/odom (frame: initial-body of the spawn).
        self.ox = self.oy = self.otheta = 0.0

        self.action      = 'go'
        self.yield_ticks = 0
        self.urgency     = random.uniform(1.0, 9.0)

        # Latest world-frame poses of peer robots, keyed by robot_id.
        self.peers: dict[str, tuple[float, float]] = {}

        self.cmd_pub   = self.create_publisher(Twist,      f'/{self.robot_id}/cmd_vel', 10)
        self.state_pub = self.create_publisher(RobotState, f'/{self.robot_id}/state',   10)

        self.create_subscription(Odometry,     f'/{self.robot_id}/odom',    self._odom_cb,     10)
        self.create_subscription(NashDecision, '/nash/decision',             self._decision_cb, 10)

        # Listen to every other robot's published state for avoidance.
        for i in range(1, NUM_ROBOTS + 1):
            other = f'robot{i}'
            if other == self.robot_id:
                continue
            self.create_subscription(
                RobotState, f'/{other}/state',
                lambda msg, r=other: self._on_peer_state(msg, r), 10)

        self.create_timer(0.1, self._control_loop)

        self.get_logger().info(
            f'[{self.robot_id}] Ready | spawn=({self.start_x},{self.start_y}) | '
            f'goal=({self.goal_x:.1f},{self.goal_y:.1f}) | urgency={self.urgency:.2f}'
        )

    # ── world-frame helpers ───────────────────────────────────────
    # gz-sim's OdometryPublisher reports pose in the model's initial-body
    # frame (axes rotated by the spawn yaw). We transform back to world:
    #   world_pos   = R(start_yaw) * odom_pos + (start_x, start_y)
    #   world_theta = odom_theta + start_yaw

    @property
    def wx(self):
        c, s = math.cos(self.start_yaw), math.sin(self.start_yaw)
        return c * self.ox - s * self.oy + self.start_x

    @property
    def wy(self):
        c, s = math.cos(self.start_yaw), math.sin(self.start_yaw)
        return s * self.ox + c * self.oy + self.start_y

    @property
    def wtheta(self):
        return self._wrap(self.otheta + self.start_yaw)

    # ── Callbacks ─────────────────────────────────────────────────

    def _odom_cb(self, msg: Odometry):
        self.ox = msg.pose.pose.position.x
        self.oy = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        self.otheta = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y ** 2 + q.z ** 2),
        )
        self._publish_state()

    def _on_peer_state(self, msg: RobotState, robot_id: str):
        self.peers[robot_id] = (msg.x, msg.y)

    def _decision_cb(self, msg: NashDecision):
        if msg.robot_a_id == self.robot_id:
            self.action = msg.robot_a_action
        elif msg.robot_b_id == self.robot_id:
            self.action = msg.robot_b_action
        else:
            return

        if self.action == 'yield':
            self.yield_ticks = 40
            self.get_logger().info(f'[{self.robot_id}] YIELD')
        else:
            self.yield_ticks = 0
            self.get_logger().info(f'[{self.robot_id}] GO')

    # ── Control loop ──────────────────────────────────────────────

    def _control_loop(self):
        if self.yield_ticks > 0:
            self.yield_ticks -= 1
            self.cmd_pub.publish(Twist())
            return
        self._navigate()

    def _navigate(self):
        # Navigate using world-frame position toward world-frame goal
        dx   = self.goal_x - self.wx
        dy   = self.goal_y - self.wy
        dist = math.hypot(dx, dy)

        if dist < GOAL_TOL:
            self._new_goal()
            return

        target = math.atan2(dy, dx)

        # ── Reactive avoidance ──────────────────────────────────
        # Bias the heading away from any peer inside AVOID_DIST and
        # slow down proportionally to how close the nearest peer is.
        heading_bias = 0.0
        speed_scale  = 1.0
        for px, py in self.peers.values():
            rx = self.wx - px
            ry = self.wy - py
            d  = math.hypot(rx, ry)
            if d >= AVOID_DIST or d < 1e-6:
                continue

            # Strength: 1 when overlapping, 0 at AVOID_DIST.
            strength = 1.0 - (d / AVOID_DIST)

            # Bias heading perpendicular to the peer-to-self direction,
            # choosing the side that points more toward the goal.
            ang_from_peer = math.atan2(ry, rx)
            left_side  = self._wrap(ang_from_peer + math.pi / 2 - target)
            right_side = self._wrap(ang_from_peer - math.pi / 2 - target)
            side_ang   = (ang_from_peer + math.pi / 2
                          if abs(left_side) < abs(right_side)
                          else ang_from_peer - math.pi / 2)

            heading_bias += AVOID_GAIN * strength * self._wrap(side_ang - target)
            speed_scale  = min(speed_scale,
                               MIN_SLOWDOWN + (1.0 - MIN_SLOWDOWN) * (1.0 - strength))

        biased_target = self._wrap(target + heading_bias)
        err = self._wrap(biased_target - self.wtheta)

        cmd = Twist()
        if abs(err) > 0.35:
            cmd.angular.z = float(max(-MAX_ANGULAR, min(MAX_ANGULAR, 1.8 * err)))
            cmd.linear.x  = 0.05
        else:
            cmd.linear.x  = float(speed_scale * min(MAX_LINEAR, 0.3 * dist))
            cmd.angular.z = float(max(-MAX_ANGULAR, min(MAX_ANGULAR, 1.2 * err)))

        self.cmd_pub.publish(cmd)

    def _new_goal(self):
        # Pick a cardinal endpoint on the OPPOSITE side of origin
        # from the robot's current position. Guarantees the straight-line
        # path goes through the centre, generating frequent Nash conflicts.
        candidates = [
            (gx, gy) for (gx, gy) in CARDINAL_GOALS
            if (gx * self.wx + gy * self.wy) < 0
            and math.hypot(gx - self.wx, gy - self.wy) > 1.5
        ]
        if not candidates:
            candidates = CARDINAL_GOALS
        self.goal_x, self.goal_y = random.choice(candidates)
        self.urgency = random.uniform(1.0, 9.0)
        self.get_logger().info(
            f'[{self.robot_id}] New goal ({self.goal_x:.1f},{self.goal_y:.1f}) '
            f'urgency={self.urgency:.2f}'
        )

    def _publish_state(self):
        s = RobotState()
        s.robot_id  = self.robot_id
        s.x         = self.wx          # world-frame X
        s.y         = self.wy          # world-frame Y
        s.theta     = self.wtheta      # world-frame yaw
        s.urgency   = self.urgency
        s.goal_x    = self.goal_x
        s.goal_y    = self.goal_y
        s.is_moving = self.yield_ticks == 0
        self.state_pub.publish(s)

    @staticmethod
    def _wrap(a):
        while a >  math.pi: a -= 2 * math.pi
        while a < -math.pi: a += 2 * math.pi
        return a


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(RobotAgentNode())
    rclpy.shutdown()
