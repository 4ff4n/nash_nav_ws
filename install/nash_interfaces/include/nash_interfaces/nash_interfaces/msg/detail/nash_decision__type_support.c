// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nash_interfaces:msg/NashDecision.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nash_interfaces/msg/detail/nash_decision__rosidl_typesupport_introspection_c.h"
#include "nash_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nash_interfaces/msg/detail/nash_decision__functions.h"
#include "nash_interfaces/msg/detail/nash_decision__struct.h"


// Include directives for member types
// Member `robot_a_id`
// Member `robot_b_id`
// Member `robot_a_action`
// Member `robot_b_action`
// Member `strategy_type`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nash_interfaces__msg__NashDecision__init(message_memory);
}

void nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_fini_function(void * message_memory)
{
  nash_interfaces__msg__NashDecision__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_member_array[9] = {
  {
    "robot_a_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, robot_a_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_b_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, robot_b_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_a_action",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, robot_a_action),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_b_action",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, robot_b_action),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "strategy_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, strategy_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_a_prob_go",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, robot_a_prob_go),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_b_prob_go",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, robot_b_prob_go),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "urgency_a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, urgency_a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "urgency_b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nash_interfaces__msg__NashDecision, urgency_b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_members = {
  "nash_interfaces__msg",  // message namespace
  "NashDecision",  // message name
  9,  // number of fields
  sizeof(nash_interfaces__msg__NashDecision),
  false,  // has_any_key_member_
  nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_member_array,  // message members
  nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_init_function,  // function to initialize message memory (memory has to be allocated)
  nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_type_support_handle = {
  0,
  &nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_members,
  get_message_typesupport_handle_function,
  &nash_interfaces__msg__NashDecision__get_type_hash,
  &nash_interfaces__msg__NashDecision__get_type_description,
  &nash_interfaces__msg__NashDecision__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nash_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nash_interfaces, msg, NashDecision)() {
  if (!nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_type_support_handle.typesupport_identifier) {
    nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nash_interfaces__msg__NashDecision__rosidl_typesupport_introspection_c__NashDecision_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
