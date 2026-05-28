"""
game_theory.py
==============
Nash Equilibrium solver for two-robot navigation conflicts.

The Game
--------
Two robots are approaching a conflict zone. Each chooses independently:
  Action 0 = Go    (proceed through the zone)
  Action 1 = Yield (stop and wait)

Payoff matrix  (rows = Robot A action, cols = Robot B action)
---------------------------------------------------------------
                B = Go          B = Yield
A = Go     (-10+ua, -10+ub)   ( 5+ua,   -1  )
A = Yield  (  -1,   5+ub  )   (  -3,    -3  )

ua, ub = urgency scores in [0, 9]  (higher = more urgent to reach goal)

Nash Equilibria
---------------
  Equal urgency → 2 pure NE: (Go,Yield) and (Yield,Go)
                              resolved by urgency tie-break
  A dominant    → 1 pure NE: (Go, Yield)   when ua >> ub
  B dominant    → 1 pure NE: (Yield, Go)   when ub >> ua
  Edge cases    → Mixed NE:  p = (ub+8)/17, q = (ua+8)/17

Derivation of mixed NE
----------------------
A is indifferent between Go/Yield when B mixes with probability q (Go):
  q(-10+ua) + (1-q)(5+ua)  =  q(-1) + (1-q)(-3)
  ua + 5 - 15q = 2q - 3
  q = (ua + 8) / 17

Similarly for p (probability A plays Go): p = (ub + 8) / 17
"""

import numpy as np
from dataclasses import dataclass
from typing import List, Tuple


@dataclass
class GameResult:
    robot_a_action: str       # 'go' | 'yield'
    robot_b_action: str       # 'go' | 'yield'
    strategy_type: str        # 'pure' | 'pure_tie_broken' | 'mixed'
    robot_a_prob_go: float    # p(A=Go) in mixed NE, else 0 or 1
    robot_b_prob_go: float    # p(B=Go) in mixed NE, else 0 or 1


def build_payoff_matrices(ua: float, ub: float) -> Tuple[np.ndarray, np.ndarray]:
    """
    Construct 2×2 payoff matrices for the navigation game.
    payoff_x[i, j] = payoff to robot X when A plays i and B plays j.
    """
    payoff_a = np.array([
        [-10.0 + ua,   5.0 + ua],   # A=Go:    [B=Go, B=Yield]
        [ -1.0,       -3.0     ],   # A=Yield: [B=Go, B=Yield]
    ])

    payoff_b = np.array([
        [-10.0 + ub,  -1.0     ],   # A=Go:    [B=Go, B=Yield]
        [  5.0 + ub,  -3.0     ],   # A=Yield: [B=Go, B=Yield]
    ])

    return payoff_a, payoff_b


def find_pure_nash(pa: np.ndarray, pb: np.ndarray) -> List[Tuple[int, int]]:
    """
    Return all pure strategy Nash Equilibria of the 2×2 game.
    (i, j) is a NE iff neither player can improve by deviating unilaterally.
    """
    ne = []
    for i in range(2):
        for j in range(2):
            a_best = pa[i, j] >= np.max(pa[:, j]) - 1e-9
            b_best = pb[i, j] >= np.max(pb[i, :]) - 1e-9
            if a_best and b_best:
                ne.append((i, j))
    return ne


def solve_mixed_nash(ua: float, ub: float) -> Tuple[float, float]:
    """
    Compute mixed strategy NE probabilities analytically.
    Returns (p, q) where:
      p = P(Robot A plays Go) — makes B indifferent (depends on ub)
      q = P(Robot B plays Go) — makes A indifferent (depends on ua)
    """
    p = np.clip((ub + 8.0) / 17.0, 0.0, 1.0)
    q = np.clip((ua + 8.0) / 17.0, 0.0, 1.0)
    return float(p), float(q)


def solve_conflict(urgency_a: float, urgency_b: float) -> GameResult:
    """
    Main entry point: solve the two-robot navigation conflict.

    Decision tree:
      1. Unique pure NE   → use it directly.
      2. Two pure NE (tie) → urgency selects: higher urgency = Go.
      3. No pure NE        → mixed strategy with collision guard.
    """
    pa, pb = build_payoff_matrices(urgency_a, urgency_b)
    pure = find_pure_nash(pa, pb)
    actions = ['go', 'yield']

    # ── Case 1: Unique pure Nash Equilibrium ────────────────────
    if len(pure) == 1:
        i, j = pure[0]
        return GameResult(
            robot_a_action=actions[i],
            robot_b_action=actions[j],
            strategy_type='pure',
            robot_a_prob_go=float(i == 0),
            robot_b_prob_go=float(j == 0),
        )

    # ── Case 2: Two pure NE — break symmetry with urgency ───────
    if len(pure) == 2:
        if urgency_a >= urgency_b:
            return GameResult('go', 'yield', 'pure_tie_broken', 1.0, 0.0)
        return GameResult('yield', 'go', 'pure_tie_broken', 0.0, 1.0)

    # ── Case 3: Mixed strategy Nash Equilibrium ──────────────────
    p, q = solve_mixed_nash(urgency_a, urgency_b)
    a_go = np.random.random() < p
    b_go = np.random.random() < q

    # Safety guard: prevent simultaneous Go (collision)
    if a_go and b_go:
        if urgency_a >= urgency_b:
            b_go = False
        else:
            a_go = False

    return GameResult(
        robot_a_action='go' if a_go else 'yield',
        robot_b_action='go' if b_go else 'yield',
        strategy_type='mixed',
        robot_a_prob_go=p,
        robot_b_prob_go=q,
    )
