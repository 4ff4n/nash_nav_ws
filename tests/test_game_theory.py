"""
test_game_theory.py
===================
Comprehensive unit tests for the Nash Equilibrium solver.

Run with:  cd nash_nav_ws && python -m pytest tests/ -v
"""

import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__),
                                '..', 'src', 'nash_solver'))

import pytest
import numpy as np
from nash_solver.game_theory import (
    build_payoff_matrices,
    find_pure_nash,
    solve_mixed_nash,
    solve_conflict,
    GameResult,
)


# ═══════════════════════════════════════════════════════════════════
#  1. Payoff Matrix Construction
# ═══════════════════════════════════════════════════════════════════

class TestPayoffMatrices:

    def test_shape(self):
        pa, pb = build_payoff_matrices(0, 0)
        assert pa.shape == (2, 2)
        assert pb.shape == (2, 2)

    def test_zero_urgency_values(self):
        pa, pb = build_payoff_matrices(0.0, 0.0)
        # (Go, Go) = collision
        assert pa[0, 0] == -10.0
        assert pb[0, 0] == -10.0
        # (Go, Yield) = A passes
        assert pa[0, 1] ==  5.0
        assert pb[0, 1] == -1.0
        # (Yield, Go) = B passes
        assert pa[1, 0] == -1.0
        assert pb[1, 0] ==  5.0
        # (Yield, Yield) = deadlock
        assert pa[1, 1] == -3.0
        assert pb[1, 1] == -3.0

    def test_urgency_bonus_robot_a(self):
        pa, _ = build_payoff_matrices(4.0, 0.0)
        assert pa[0, 0] == -6.0    # -10 + 4
        assert pa[0, 1] ==  9.0    #   5 + 4
        # Yield rows unaffected by ua
        assert pa[1, 0] == -1.0
        assert pa[1, 1] == -3.0

    def test_urgency_bonus_robot_b(self):
        _, pb = build_payoff_matrices(0.0, 3.0)
        assert pb[0, 0] == -7.0    # -10 + 3
        assert pb[1, 0] ==  8.0    #   5 + 3
        # Yield col unaffected by ub
        assert pb[0, 1] == -1.0
        assert pb[1, 1] == -3.0

    def test_max_urgency(self):
        pa, pb = build_payoff_matrices(9.0, 9.0)
        assert pa[0, 0] == -1.0    # -10 + 9
        assert pa[0, 1] == 14.0    #   5 + 9
        assert pb[1, 0] == 14.0    #   5 + 9


# ═══════════════════════════════════════════════════════════════════
#  2. Pure Strategy Nash Equilibria
# ═══════════════════════════════════════════════════════════════════

class TestPureNash:

    def test_symmetric_has_two_ne(self):
        """Equal urgency → exactly 2 pure NE: (Go,Yield) and (Yield,Go)."""
        pa, pb = build_payoff_matrices(0.0, 0.0)
        ne = find_pure_nash(pa, pb)
        assert len(ne) == 2
        assert (0, 1) in ne    # (Go, Yield)
        assert (1, 0) in ne    # (Yield, Go)

    def test_high_urgency_a_preferred_ne(self):
        """With ua=9, (Go,Yield) IS a pure NE and urgency tie-break picks it."""
        pa, pb = build_payoff_matrices(9.0, 0.0)
        ne = find_pure_nash(pa, pb)
        # Symmetric payoff structure → always at least 2 pure NE
        assert (0, 1) in ne    # (Go, Yield) must be a NE when A is urgent
        # Tie-break: solve_conflict should pick A=go, B=yield
        r = solve_conflict(9.0, 0.0)
        assert r.robot_a_action == 'go'
        assert r.robot_b_action == 'yield' 

    def test_high_urgency_b_preferred_ne(self):
        """With ub=9, (Yield,Go) IS a pure NE and urgency tie-break picks it."""
        pa, pb = build_payoff_matrices(0.0, 9.0)
        ne = find_pure_nash(pa, pb)
        assert (1, 0) in ne    # (Yield, Go) must be a NE when B is urgent
        # Tie-break: solve_conflict should pick A=yield, B=go
        r = solve_conflict(0.0, 9.0)
        assert r.robot_a_action == 'yield'
        assert r.robot_b_action == 'go' 

    def test_go_go_never_ne(self):
        """(Go,Go) is never a NE — collision always avoidable.
        Note: at exact boundary ua=ub=9, -10+9=-1 equals Yield payoff,
        creating a degenerate tie; we exclude that boundary point."""
        for ua in np.linspace(0, 8.9, 10):
            for ub in np.linspace(0, 8.9, 10):
                pa, pb = build_payoff_matrices(ua, ub)
                ne = find_pure_nash(pa, pb)
                assert (0, 0) not in ne, \
                    f"(Go,Go) incorrectly a NE at ua={ua:.1f}, ub={ub:.1f}"

    def test_yield_yield_never_ne(self):
        """(Yield,Yield) is never a NE — deadlock always avoidable."""
        for ua in np.linspace(0, 9, 10):
            for ub in np.linspace(0, 9, 10):
                pa, pb = build_payoff_matrices(ua, ub)
                ne = find_pure_nash(pa, pb)
                assert (1, 1) not in ne, \
                    f"(Yield,Yield) incorrectly a NE at ua={ua:.1f}, ub={ub:.1f}"

    def test_incentive_compatibility(self):
        """Verify NE definition: no player can improve by deviating."""
        for ua in np.linspace(0, 9, 5):
            for ub in np.linspace(0, 9, 5):
                pa, pb = build_payoff_matrices(ua, ub)
                for i, j in find_pure_nash(pa, pb):
                    # A cannot improve
                    assert pa[i, j] >= pa[1-i, j] - 1e-9, \
                        f"A improves at NE ({i},{j}) ua={ua} ub={ub}"
                    # B cannot improve
                    assert pb[i, j] >= pb[i, 1-j] - 1e-9, \
                        f"B improves at NE ({i},{j}) ua={ua} ub={ub}"


# ═══════════════════════════════════════════════════════════════════
#  3. Mixed Strategy Nash Equilibrium
# ═══════════════════════════════════════════════════════════════════

class TestMixedNash:

    def test_probabilities_in_unit_interval(self):
        for ua in np.linspace(0, 9, 10):
            for ub in np.linspace(0, 9, 10):
                p, q = solve_mixed_nash(ua, ub)
                assert 0.0 <= p <= 1.0, f"p={p} out of [0,1]"
                assert 0.0 <= q <= 1.0, f"q={q} out of [0,1]"

    def test_symmetric_equal_probabilities(self):
        """Equal urgency → p == q."""
        p, q = solve_mixed_nash(0.0, 0.0)
        assert abs(p - q) < 1e-9
        assert abs(p - 8.0/17.0) < 1e-9

    def test_analytical_formula(self):
        """Verify p = (ub+8)/17 and q = (ua+8)/17."""
        ua, ub = 3.5, 6.0
        p, q = solve_mixed_nash(ua, ub)
        assert abs(p - (ub + 8) / 17) < 1e-9
        assert abs(q - (ua + 8) / 17) < 1e-9

    def test_higher_ub_increases_p(self):
        """Higher B urgency → A goes more often (p increases)."""
        p1, _ = solve_mixed_nash(5.0, 2.0)
        p2, _ = solve_mixed_nash(5.0, 8.0)
        assert p2 > p1

    def test_higher_ua_increases_q(self):
        """Higher A urgency → B goes more often (q increases)."""
        _, q1 = solve_mixed_nash(2.0, 5.0)
        _, q2 = solve_mixed_nash(8.0, 5.0)
        assert q2 > q1

    def test_a_indifferent_at_mixed_ne(self):
        """
        At mixed NE, A should be indifferent between Go and Yield
        (expected payoffs equal given B mixes with prob q).
        """
        ua, ub = 2.0, 4.0
        pa, _  = build_payoff_matrices(ua, ub)
        _, q   = solve_mixed_nash(ua, ub)

        eu_go    = q * pa[0, 0] + (1 - q) * pa[0, 1]
        eu_yield = q * pa[1, 0] + (1 - q) * pa[1, 1]
        assert abs(eu_go - eu_yield) < 1e-6, \
            f"A not indifferent: EU_go={eu_go:.4f} EU_yield={eu_yield:.4f}"

    def test_b_indifferent_at_mixed_ne(self):
        """At mixed NE, B should be indifferent between Go and Yield."""
        ua, ub = 2.0, 4.0
        _, pb  = build_payoff_matrices(ua, ub)
        p, _   = solve_mixed_nash(ua, ub)

        eu_go    = p * pb[0, 0] + (1 - p) * pb[1, 0]
        eu_yield = p * pb[0, 1] + (1 - p) * pb[1, 1]
        assert abs(eu_go - eu_yield) < 1e-6, \
            f"B not indifferent: EU_go={eu_go:.4f} EU_yield={eu_yield:.4f}"


# ═══════════════════════════════════════════════════════════════════
#  4. Full Conflict Solver
# ═══════════════════════════════════════════════════════════════════

class TestSolveConflict:

    def test_returns_game_result(self):
        assert isinstance(solve_conflict(5.0, 3.0), GameResult)

    def test_never_both_go(self):
        """Collision (both Go) must never happen."""
        for _ in range(500):
            r = solve_conflict(
                float(np.random.uniform(0, 9)),
                float(np.random.uniform(0, 9)),
            )
            assert not (r.robot_a_action == 'go' and r.robot_b_action == 'go'), \
                "COLLISION: both robots told to Go!"

    def test_never_both_yield(self):
        """Deadlock (both Yield) must never happen."""
        for _ in range(500):
            r = solve_conflict(
                float(np.random.uniform(0, 9)),
                float(np.random.uniform(0, 9)),
            )
            assert not (r.robot_a_action == 'yield' and
                        r.robot_b_action == 'yield'), \
                "DEADLOCK: both robots told to Yield!"

    def test_dominant_urgency_goes(self):
        """Robot with much higher urgency should always be assigned Go."""
        for _ in range(100):
            r = solve_conflict(9.0, 0.5)
            assert r.robot_a_action == 'go',   "High-urgency A should Go"
            assert r.robot_b_action == 'yield',"Low-urgency  B should Yield"

        for _ in range(100):
            r = solve_conflict(0.5, 9.0)
            assert r.robot_a_action == 'yield',"Low-urgency  A should Yield"
            assert r.robot_b_action == 'go',   "High-urgency B should Go"

    def test_equal_urgency_one_goes(self):
        """Equal urgency should still resolve cleanly (tie-break)."""
        for _ in range(100):
            r = solve_conflict(5.0, 5.0)
            actions = {r.robot_a_action, r.robot_b_action}
            assert actions == {'go', 'yield'}

    def test_strategy_type_valid(self):
        valid = {'pure', 'pure_tie_broken', 'mixed'}
        for _ in range(200):
            r = solve_conflict(
                float(np.random.uniform(0, 9)),
                float(np.random.uniform(0, 9)),
            )
            assert r.strategy_type in valid

    def test_prob_in_unit_interval(self):
        for _ in range(200):
            r = solve_conflict(
                float(np.random.uniform(0, 9)),
                float(np.random.uniform(0, 9)),
            )
            assert 0.0 <= r.robot_a_prob_go <= 1.0
            assert 0.0 <= r.robot_b_prob_go <= 1.0

    def test_pure_ne_at_boundary(self):
        """At ua=9 > ub, solver should pick A=go, B=yield.
        Strategy type may be pure_tie_broken since payoff structure
        always yields 2 symmetric pure NE within urgency range [0,9]."""
        r = solve_conflict(9.0, 0.0)
        assert r.strategy_type in ['pure', 'pure_tie_broken']
        assert r.robot_a_action == 'go'
        assert r.robot_b_action == 'yield'

    @pytest.mark.parametrize("ua,ub,exp_a,exp_b", [
        (9.0, 0.0, 'go',    'yield'),
        (0.0, 9.0, 'yield', 'go'  ),
        (9.0, 9.0, 'go',    'yield'),   # A >= B tie-break
    ])
    def test_parametrized_scenarios(self, ua, ub, exp_a, exp_b):
        r = solve_conflict(ua, ub)
        assert r.robot_a_action == exp_a
        assert r.robot_b_action == exp_b


# ═══════════════════════════════════════════════════════════════════
#  5. Game Theory Properties (economic correctness)
# ═══════════════════════════════════════════════════════════════════

class TestEconomicProperties:

    def test_pareto_efficiency_of_ne(self):
        """
        Nash outcome should not be Pareto-dominated:
        no other outcome strictly improves BOTH players simultaneously.
        """
        pa, pb = build_payoff_matrices(0.0, 0.0)
        for i, j in find_pure_nash(pa, pb):
            for i2 in range(2):
                for j2 in range(2):
                    if (i2, j2) != (i, j):
                        both_better = (
                            pa[i2, j2] > pa[i, j] + 1e-9 and
                            pb[i2, j2] > pb[i, j] + 1e-9
                        )
                        assert not both_better, \
                            f"NE ({i},{j}) Pareto-dominated by ({i2},{j2})"

    def test_social_welfare_go_yield_vs_deadlock(self):
        """
        (Go, Yield) outcome should have higher social welfare than deadlock
        for any urgency level.
        """
        for ua in np.linspace(0, 9, 10):
            pa, pb = build_payoff_matrices(ua, 0.0)
            welfare_go_yield   = pa[0, 1] + pb[0, 1]
            welfare_yield_go   = pa[1, 0] + pb[1, 0]
            welfare_deadlock   = pa[1, 1] + pb[1, 1]
            assert welfare_go_yield > welfare_deadlock
            assert welfare_yield_go > welfare_deadlock
