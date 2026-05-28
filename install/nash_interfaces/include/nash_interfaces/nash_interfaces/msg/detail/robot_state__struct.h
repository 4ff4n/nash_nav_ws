// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nash_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nash_interfaces/msg/robot_state.h"


#ifndef NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'robot_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotState in the package nash_interfaces.
typedef struct nash_interfaces__msg__RobotState
{
  rosidl_runtime_c__String robot_id;
  double x;
  double y;
  double theta;
  double urgency;
  double goal_x;
  double goal_y;
  bool is_moving;
} nash_interfaces__msg__RobotState;

// Struct for a sequence of nash_interfaces__msg__RobotState.
typedef struct nash_interfaces__msg__RobotState__Sequence
{
  nash_interfaces__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nash_interfaces__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
