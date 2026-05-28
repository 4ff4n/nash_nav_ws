"""
conflict_resolver_node.py
=========================
Central ROS2 node that watches all robot positions, detects conflicts,
runs the Nash Equilibrium solver, and publishes decisions.
"""

import rclpy
from rclpy.node import Node
from nash_interfaces.msg import RobotState, NashDecision
from .game_theory import solve_conflict
import math

CONFLICT_DIST = 1.2   # metres — trigger conflict resolution
CLEAR_DIST    = 2.0   # metres — mark conflict as resolved
NUM_ROBOTS    = 3


class ConflictResolverNode(Node):
    def __init__(self):
        super().__init__('conflict_resolver')

        self.robot_states: dict[str, RobotState] = {}
        self.active_conflicts: set[tuple] = set()

        # Subscribe to every robot's state
        for i in range(1, NUM_ROBOTS + 1):
            rid = f'robot{i}'
            self.create_subscription(
                RobotState,
                f'/{rid}/state',
                lambda msg, r=rid: self._on_state(msg, r),
                10,
            )

        # Publish Nash decisions (all agents subscribe)
        self.decision_pub = self.create_publisher(NashDecision, '/nash/decision', 10)

        # Check at 10 Hz
        self.create_timer(0.1, self._check_conflicts)

        self.get_logger().info(
            f'[ConflictResolver] Online | robots={NUM_ROBOTS} | '
            f'conflict_dist={CONFLICT_DIST}m | clear_dist={CLEAR_DIST}m'
        )

    # ── Callbacks ─────────────────────────────────────────────────

    def _on_state(self, msg: RobotState, robot_id: str):
        self.robot_states[robot_id] = msg

    def _check_conflicts(self):
        robots = list(self.robot_states.keys())

        for i in range(len(robots)):
            for j in range(i + 1, len(robots)):
                rid_a, rid_b = robots[i], robots[j]
                sa = self.robot_states[rid_a]
                sb = self.robot_states[rid_b]
                dist = math.hypot(sa.x - sb.x, sa.y - sb.y)
                key = (rid_a, rid_b)

                if dist < CONFLICT_DIST and key not in self.active_conflicts:
                    self.active_conflicts.add(key)
                    self._resolve(rid_a, rid_b, sa, sb)

                elif dist > CLEAR_DIST and key in self.active_conflicts:
                    self.active_conflicts.discard(key)
                    self.get_logger().info(
                        f'[CLEAR] {rid_a} <-> {rid_b} | dist={dist:.2f}m'
                    )

    # ── Nash resolution ───────────────────────────────────────────

    def _resolve(self, rid_a: str, rid_b: str,
                 sa: RobotState, sb: RobotState):

        self.get_logger().info(
            f'[CONFLICT] {rid_a}(u={sa.urgency:.1f}) \u2194 '
            f'{rid_b}(u={sb.urgency:.1f})'
        )

        result = solve_conflict(sa.urgency, sb.urgency)

        msg = NashDecision()
        msg.robot_a_id      = rid_a
        msg.robot_b_id      = rid_b
        msg.robot_a_action  = result.robot_a_action
        msg.robot_b_action  = result.robot_b_action
        msg.strategy_type   = result.strategy_type
        msg.robot_a_prob_go = result.robot_a_prob_go
        msg.robot_b_prob_go = result.robot_b_prob_go
        msg.urgency_a       = sa.urgency
        msg.urgency_b       = sb.urgency

        self.decision_pub.publish(msg)

        self.get_logger().info(
            f'[NASH/{result.strategy_type.upper()}] '
            f'{rid_a}={result.robot_a_action.upper()} | '
            f'{rid_b}={result.robot_b_action.upper()}'
        )


def main(args=None):
    rclpy.init(args=args)
    node = ConflictResolverNode()
    rclpy.spin(node)
    rclpy.shutdown()
