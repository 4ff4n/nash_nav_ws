"""
visualizer_node.py
==================
Publishes RViz2 MarkerArrays to visualise:
  • Robot spheres (coloured per robot)
  • Robot ID + urgency labels
  • Goal arrows
  • Conflict detection radius discs
  • Active conflict zone (red pulsing sphere)
  • Nash decision text overlay
"""

import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point
from nash_interfaces.msg import RobotState, NashDecision
import math

# Colour palette (R, G, B) per robot
ROBOT_COLORS = {
    'robot1': (0.20, 0.80, 1.00),   # cyan
    'robot2': (1.00, 0.55, 0.10),   # amber
    'robot3': (0.30, 1.00, 0.40),   # lime
}
CONFLICT_DIST      = 1.2    # must match conflict_resolver_node
CLEAR_DIST         = 2.0    # must match conflict_resolver_node
DECISION_SHOW_SECS = 2.5    # how long to display Nash decision text
TIMER_HZ           = 10.0
MARKER_LIFETIME    = 0.3    # > 1 / TIMER_HZ so refreshes are seamless

# Stable per-robot offset so each robot's markers keep the same IDs
# every cycle. With 16 namespaces × 100 robots max we never overlap.
ROBOT_INDEX = {'robot1': 0, 'robot2': 1, 'robot3': 2}
NS_ROBOT = {
    'robot_body':      100,
    'robot_label':     200,
    'goal_arrow':      300,
    'conflict_radius': 400,
}
NS_PAIR = {
    'conflict_zone':   500,
    'nash_decision':   600,
    'conflict_line':   700,
}


class NashVisualizerNode(Node):
    def __init__(self):
        super().__init__('nash_visualizer')

        self.robot_states: dict[str, RobotState] = {}
        self.active_decisions: dict[tuple, NashDecision] = {}
        self.decision_countdown: dict[tuple, float] = {}

        # Subscribe to robot states
        for i in range(1, 4):
            rid = f'robot{i}'
            self.create_subscription(
                RobotState, f'/{rid}/state',
                lambda msg, r=rid: self._on_state(msg, r), 10)

        # Subscribe to Nash decisions
        self.create_subscription(
            NashDecision, '/nash/decision', self._on_decision, 10)

        # Publish all markers on one topic for RViz2
        self.marker_pub = self.create_publisher(
            MarkerArray, '/nash/visualization', 10)

        self.create_timer(1.0 / TIMER_HZ, self._publish)

        self.get_logger().info('[NashVisualizer] Ready — open RViz2 and add /nash/visualization')

    # ── Callbacks ─────────────────────────────────────────────────

    def _on_state(self, msg: RobotState, robot_id: str):
        self.robot_states[robot_id] = msg

    def _on_decision(self, msg: NashDecision):
        key = tuple(sorted([msg.robot_a_id, msg.robot_b_id]))
        self.active_decisions[key] = msg
        self.decision_countdown[key] = DECISION_SHOW_SECS

    # ── Marker builder ────────────────────────────────────────────

    def _publish(self):
        markers = MarkerArray()

        def mk(ns, mtype, mid):
            m = Marker()
            m.header.frame_id = 'map'
            m.header.stamp    = self.get_clock().now().to_msg()
            m.ns      = ns
            m.id      = mid
            m.type    = mtype
            m.action  = Marker.ADD
            # Lifetime > one publish period — markers self-delete if we
            # stop refreshing them, so no DELETEALL flash is needed.
            m.lifetime.sec     = int(MARKER_LIFETIME)
            m.lifetime.nanosec = int((MARKER_LIFETIME - int(MARKER_LIFETIME)) * 1e9)
            return m

        for rid, st in self.robot_states.items():
            r, g, b = ROBOT_COLORS.get(rid, (1.0, 1.0, 1.0))
            ridx = ROBOT_INDEX.get(rid, 0)

            # ── Robot body sphere ──────────────────────────────
            s = mk('robot_body', Marker.SPHERE, NS_ROBOT['robot_body'] + ridx)
            s.pose.position.x = st.x
            s.pose.position.y = st.y
            s.pose.position.z = 0.2
            s.scale.x = s.scale.y = s.scale.z = 0.32
            s.color.r = r; s.color.g = g; s.color.b = b; s.color.a = 1.0
            markers.markers.append(s)

            # ── Robot label (id + urgency) ─────────────────────
            lbl = mk('robot_label', Marker.TEXT_VIEW_FACING,
                     NS_ROBOT['robot_label'] + ridx)
            lbl.pose.position.x = st.x
            lbl.pose.position.y = st.y
            lbl.pose.position.z = 0.55
            lbl.text    = f'{rid}  u={st.urgency:.1f}'
            lbl.scale.z = 0.18
            lbl.color.r = 1.0; lbl.color.g = 1.0; lbl.color.b = 1.0; lbl.color.a = 1.0
            markers.markers.append(lbl)

            # ── Goal arrow (thin, faint) ──────────────────────
            arr = mk('goal_arrow', Marker.ARROW,
                     NS_ROBOT['goal_arrow'] + ridx)
            p0 = Point(); p0.x = st.x;      p0.y = st.y;      p0.z = 0.1
            p1 = Point(); p1.x = st.goal_x; p1.y = st.goal_y; p1.z = 0.1
            arr.points = [p0, p1]
            arr.scale.x = 0.02; arr.scale.y = 0.05; arr.scale.z = 0.08
            arr.color.r = r; arr.color.g = g; arr.color.b = b; arr.color.a = 0.35
            markers.markers.append(arr)

            # ── Conflict detection radius (very faint) ────────
            disc = mk('conflict_radius', Marker.CYLINDER,
                      NS_ROBOT['conflict_radius'] + ridx)
            disc.pose.position.x = st.x
            disc.pose.position.y = st.y
            disc.pose.position.z = 0.005
            disc.scale.x = disc.scale.y = CONFLICT_DIST * 2
            disc.scale.z = 0.005
            disc.color.r = r; disc.color.g = g; disc.color.b = b
            disc.color.a = 0.03
            markers.markers.append(disc)

        # ── Active conflict overlays ───────────────────────────
        expired = []
        for key, dec in self.active_decisions.items():
            self.decision_countdown[key] -= 1.0 / TIMER_HZ

            rid_a, rid_b = dec.robot_a_id, dec.robot_b_id
            if rid_a not in self.robot_states or rid_b not in self.robot_states:
                expired.append(key); continue

            sa, sb = self.robot_states[rid_a], self.robot_states[rid_b]
            dist  = math.hypot(sa.x - sb.x, sa.y - sb.y)

            # Drop the overlay once the robots have separated OR the
            # countdown expires — whichever happens first.
            if self.decision_countdown[key] <= 0 or dist > CLEAR_DIST:
                expired.append(key); continue

            mx = (sa.x + sb.x) / 2.0
            my = (sa.y + sb.y) / 2.0
            pair_idx = (ROBOT_INDEX.get(rid_a, 0) * 10
                        + ROBOT_INDEX.get(rid_b, 0))

            # Pulsing red sphere at midpoint
            alpha = 0.3 + 0.25 * math.sin(
                self.decision_countdown[key] * math.pi * 2)
            cz = mk('conflict_zone', Marker.SPHERE,
                    NS_PAIR['conflict_zone'] + pair_idx)
            cz.pose.position.x = mx; cz.pose.position.y = my
            cz.pose.position.z = 0.15
            cz.scale.x = cz.scale.y = cz.scale.z = 0.55
            cz.color.r = 1.0; cz.color.g = 0.15; cz.color.b = 0.15
            cz.color.a = float(max(0.1, min(0.9, alpha)))
            markers.markers.append(cz)

            # Decision text (single block above midpoint)
            strategy_tag = {'pure': '[P]', 'pure_tie_broken': '[T]',
                            'mixed': '[M]'}.get(dec.strategy_type, '?')
            dt = mk('nash_decision', Marker.TEXT_VIEW_FACING,
                    NS_PAIR['nash_decision'] + pair_idx)
            dt.pose.position.x = mx
            dt.pose.position.y = my
            dt.pose.position.z = 1.3
            dt.text = (
                f'CONFLICT {strategy_tag}\n'
                f'{rid_a}: {dec.robot_a_action.upper()}\n'
                f'{rid_b}: {dec.robot_b_action.upper()}'
            )
            dt.scale.z = 0.18
            dt.color.r = 1.0; dt.color.g = 0.95; dt.color.b = 0.2
            dt.color.a = 1.0
            markers.markers.append(dt)

            # Connection line between robots
            ln = mk('conflict_line', Marker.LINE_STRIP,
                    NS_PAIR['conflict_line'] + pair_idx)
            ln.points = [
                Point(x=sa.x, y=sa.y, z=0.1),
                Point(x=sb.x, y=sb.y, z=0.1),
            ]
            ln.scale.x = 0.04
            ln.color.r = 1.0; ln.color.g = 0.2; ln.color.b = 0.2
            ln.color.a = 0.7
            markers.markers.append(ln)

        for key in expired:
            self.active_decisions.pop(key, None)
            self.decision_countdown.pop(key, None)

        self.marker_pub.publish(markers)


def main(args=None):
    rclpy.init(args=args)
    node = NashVisualizerNode()
    rclpy.spin(node)
    rclpy.shutdown()
