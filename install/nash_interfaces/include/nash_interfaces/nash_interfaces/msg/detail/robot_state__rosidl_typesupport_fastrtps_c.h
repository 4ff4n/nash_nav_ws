// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from nash_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice
#ifndef NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "nash_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nash_interfaces/msg/detail/robot_state__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
bool cdr_serialize_nash_interfaces__msg__RobotState(
  const nash_interfaces__msg__RobotState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
bool cdr_deserialize_nash_interfaces__msg__RobotState(
  eprosima::fastcdr::Cdr &,
  nash_interfaces__msg__RobotState * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
size_t get_serialized_size_nash_interfaces__msg__RobotState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
size_t max_serialized_size_nash_interfaces__msg__RobotState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
bool cdr_serialize_key_nash_interfaces__msg__RobotState(
  const nash_interfaces__msg__RobotState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
size_t get_serialized_size_key_nash_interfaces__msg__RobotState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
size_t max_serialized_size_key_nash_interfaces__msg__RobotState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nash_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nash_interfaces, msg, RobotState)();

#ifdef __cplusplus
}
#endif

#endif  // NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
