# Nash Navigation — Multi-Agent TurtleBot3 with Nash Equilibrium

Multi-robot navigation for **ROS2 Jazzy** using **Game Theory** to resolve
conflicts at intersections — no hardcoded priorities, purely emergent rational behaviour.

## Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                         Gazebo World                            │
│            (cross-intersection, 3 TurtleBot3 Burgers)           │
└────────────────────────┬────────────────────────────────────────┘
                         │ /robotN/odom
           ┌─────────────▼─────────────┐
           │      Robot Agent ×3       │  /robotN/state ──►
           │  (proportional navigation │  /robotN/cmd_vel ◄──
           │   + Nash obedience)       │
           └──────────────────────────►│
                                       │
                 /nash/decision ◄──────┤
           ┌─────────────────────────  │
           │   Conflict Resolver       │◄─── /robotN/state
           │  (detects proximity,      │
           │   runs Nash solver)       │
           └──────────────────────────►│
                                       │
           ┌─────────────────────────  │
           │   Nash Visualizer         │◄─── /robotN/state
           │  (RViz2 marker overlays)  │◄─── /nash/decision
           └─────────────────────────  │
```

## The Game

When two robots come within **1.2 m** of each other:

```
                  Robot B: Go        Robot B: Yield
Robot A: Go    (-10+ua, -10+ub)     ( 5+ua,   -1  )
Robot A: Yield (  -1,    5+ub )     (  -3,    -3  )
```

**ua, ub** = urgency scores [0–9].  Three cases:
- **Unique pure NE** → use it directly
- **Two pure NE (tie)** → higher urgency wins
- **No pure NE** → mixed strategy: `p = (ub+8)/17`, `q = (ua+8)/17`

## Packages

| Package | Purpose |
|---|---|
| `nash_interfaces` | Custom ROS2 messages |
| `nash_solver` | Game theory + conflict resolver node |
| `robot_navigator` | Per-robot navigation + Nash obedience |
| `nash_visualizer` | RViz2 overlays (markers, conflict zones) |
| `simulation` | Gazebo world + launch file |

## Setup

```bash
# 1. Install dependencies
sudo apt update
sudo apt install -y \
  ros-jazzy-turtlebot3 \
  ros-jazzy-turtlebot3-simulations \
  ros-jazzy-turtlebot3-gazebo \
  ros-jazzy-gazebo-ros-pkgs \
  python3-colcon-common-extensions

echo "export TURTLEBOT3_MODEL=burger" >> ~/.bashrc
source ~/.bashrc

# 2. Build
cd ~/nash_nav_ws
colcon build --symlink-install
source install/setup.bash

# 3. Run
ros2 launch simulation nash_nav.launch.py
```

## Tests

```bash
pip3 install pytest numpy
python -m pytest tests/ -v
```

## Key Topics

| Topic | Type | Description |
|---|---|---|
| `/robotN/state` | `RobotState` | Position, urgency, goal |
| `/nash/decision` | `NashDecision` | Nash outcome per conflict |
| `/nash/visualization` | `MarkerArray` | RViz2 overlays |
| `/robotN/cmd_vel` | `Twist` | Robot velocity commands |

## RViz2 Visualisation

After launching, open RViz2 and add:
- **MarkerArray** → topic: `/nash/visualization`
- Fixed Frame: `map`
- Use **TopDownOrtho** view for best overview

You will see:
- 🔵🟠🟢 Coloured spheres per robot with urgency labels
- → Goal arrows
- ⭕ Conflict detection radius circles
- 🔴 Pulsing red sphere when conflict detected
- 📝 Nash decision text overlay (strategy type + actions)
