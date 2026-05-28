// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nash_interfaces:msg/NashDecision.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nash_interfaces/msg/nash_decision.h"


#ifndef NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__STRUCT_H_
#define NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'robot_a_id'
// Member 'robot_b_id'
// Member 'robot_a_action'
// Member 'robot_b_action'
// Member 'strategy_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/NashDecision in the package nash_interfaces.
typedef struct nash_interfaces__msg__NashDecision
{
  rosidl_runtime_c__String robot_a_id;
  rosidl_runtime_c__String robot_b_id;
  rosidl_runtime_c__String robot_a_action;
  rosidl_runtime_c__String robot_b_action;
  rosidl_runtime_c__String strategy_type;
  double robot_a_prob_go;
  double robot_b_prob_go;
  double urgency_a;
  double urgency_b;
} nash_interfaces__msg__NashDecision;

// Struct for a sequence of nash_interfaces__msg__NashDecision.
typedef struct nash_interfaces__msg__NashDecision__Sequence
{
  nash_interfaces__msg__NashDecision * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nash_interfaces__msg__NashDecision__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__STRUCT_H_
