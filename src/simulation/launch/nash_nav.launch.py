import os, math, random
from launch import LaunchDescription
from launch.actions import (IncludeLaunchDescription, TimerAction,
                             SetEnvironmentVariable)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

NUM_ROBOTS    = 3
SPAWN_RADIUS  = 4.0   # metres from origin where robots spawn
MIN_ANG_SEP   = math.radians(80)   # minimum angular gap between spawns
ARM_REACH     = 2.5   # must match CARDINAL_GOALS in robot_agent_node.py


def _random_spawns(n: int = NUM_ROBOTS):
    """
    Sample `n` spawn angles uniformly around the origin with a guaranteed
    minimum angular separation. Each robot:
      * spawns at radius SPAWN_RADIUS on the chosen angle
      * picks a random cardinal endpoint as its FIRST goal (so robots
        don't all aim for the origin simultaneously and collide at t=0)
      * faces its first goal at spawn time
    Returns a list of (rid, sx, sy, syaw_deg, gx, gy) tuples.
    """
    cardinals = [( ARM_REACH, 0.0), (-ARM_REACH, 0.0),
                 (0.0,  ARM_REACH), (0.0, -ARM_REACH)]

    angles: list[float] = []
    while len(angles) < n:
        cand = random.uniform(-math.pi, math.pi)
        if all(abs(((cand - a) + math.pi) % (2 * math.pi) - math.pi) >= MIN_ANG_SEP
               for a in angles):
            angles.append(cand)

    # Distinct first goals per robot so paths diverge initially.
    initial_goals = random.sample(cardinals, n)

    spawns = []
    for i, (a, (gx, gy)) in enumerate(zip(angles, initial_goals)):
        sx = SPAWN_RADIUS * math.cos(a)
        sy = SPAWN_RADIUS * math.sin(a)
        syaw = math.atan2(gy - sy, gx - sx)         # face the first goal
        spawns.append((f'robot{i + 1}', sx, sy, math.degrees(syaw), gx, gy))
    return spawns


ROBOTS = _random_spawns()

def generate_launch_description():
    os.environ['TURTLEBOT3_MODEL'] = 'burger'
    sim_dir = get_package_share_directory('simulation')
    viz_dir = get_package_share_directory('nash_visualizer')
    world_file = os.path.join(sim_dir, 'worlds', 'nash_world.world')
    rviz_cfg   = os.path.join(viz_dir, 'rviz', 'nash_nav.rviz')

    actions = [
        SetEnvironmentVariable('TURTLEBOT3_MODEL', 'burger'),
        # Static TF so RViz map frame exists
        Node(package='tf2_ros', executable='static_transform_publisher',
             name='static_tf_world_map',
             arguments=['0','0','0','0','0','0','world','map']),
    ]

    # ── Gazebo ───────────────────────────────────────────────────
    actions.append(IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(get_package_share_directory('ros_gz_sim'),
                         'launch', 'gz_sim.launch.py')]),
        launch_arguments={'gz_args': f'-r {world_file}',
                          'on_exit_shutdown': 'true'}.items()))

    # ── /clock bridge (sim time source for all ROS nodes) ────────
    actions.append(Node(
        package='ros_gz_bridge', executable='parameter_bridge',
        name='bridge_clock',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'))

    # ── Per-robot nodes ──────────────────────────────────────────
    for rid, sx, sy, syaw_deg, gx, gy in ROBOTS:
        syaw     = math.radians(syaw_deg)
        sdf_file = os.path.join(sim_dir, 'models', f'{rid}.sdf')

        actions.append(TimerAction(period=3.0, actions=[Node(
            package='ros_gz_sim', executable='create', name=f'spawn_{rid}',
            arguments=['-name', rid, '-file', sdf_file,
                       '-x', str(sx), '-y', str(sy), '-z', '0.08',
                       '-Y', str(syaw)],
            output='screen')]))

        actions.append(TimerAction(period=5.0, actions=[Node(
            package='ros_gz_bridge', executable='parameter_bridge',
            name=f'bridge_{rid}',
            arguments=[
                f'/model/{rid}/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry',
                f'/model/{rid}/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
                '--ros-args',
                '-r', f'/model/{rid}/odometry:=/{rid}/odom',
                '-r', f'/model/{rid}/cmd_vel:=/{rid}/cmd_vel',
            ],
            output='screen')]))

        actions.append(TimerAction(period=6.0, actions=[Node(
            package='robot_navigator', executable='robot_agent',
            name=f'agent_{rid}',
            parameters=[{
                'robot_id': rid,
                'start_x':   float(sx),    # spawn world X
                'start_y':   float(sy),    # spawn world Y
                'start_yaw': float(syaw),  # spawn world yaw (rad)
                'goal_x':    float(gx),
                'goal_y':    float(gy),
                'use_sim_time': True,
            }],
            output='screen')]))

    # ── Conflict resolver ────────────────────────────────────────
    actions.append(TimerAction(period=7.0, actions=[Node(
        package='nash_solver', executable='conflict_resolver',
        parameters=[{'use_sim_time': True}], output='screen')]))

    # ── Visualizer ───────────────────────────────────────────────
    actions.append(TimerAction(period=7.0, actions=[Node(
        package='nash_visualizer', executable='visualizer',
        parameters=[{'use_sim_time': True}], output='screen')]))

    # ── RViz2 ────────────────────────────────────────────────────
    actions.append(TimerAction(period=8.0, actions=[Node(
        package='rviz2', executable='rviz2',
        arguments=['-d', rviz_cfg],
        parameters=[{'use_sim_time': True}], output='screen')]))

    return LaunchDescription(actions)
