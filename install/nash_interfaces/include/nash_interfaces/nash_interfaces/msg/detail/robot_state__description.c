// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nash_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

#include "nash_interfaces/msg/detail/robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nash_interfaces
const rosidl_type_hash_t *
nash_interfaces__msg__RobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x86, 0x70, 0x5c, 0xbd, 0x64, 0x3e, 0x12, 0x19,
      0x2f, 0x5a, 0x70, 0xb6, 0x6d, 0x30, 0x88, 0x40,
      0x63, 0x8f, 0x33, 0xb2, 0x03, 0xca, 0xbc, 0x58,
      0x6c, 0x47, 0xeb, 0x29, 0x45, 0xe5, 0xa2, 0xfc,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char nash_interfaces__msg__RobotState__TYPE_NAME[] = "nash_interfaces/msg/RobotState";

// Define type names, field names, and default values
static char nash_interfaces__msg__RobotState__FIELD_NAME__robot_id[] = "robot_id";
static char nash_interfaces__msg__RobotState__FIELD_NAME__x[] = "x";
static char nash_interfaces__msg__RobotState__FIELD_NAME__y[] = "y";
static char nash_interfaces__msg__RobotState__FIELD_NAME__theta[] = "theta";
static char nash_interfaces__msg__RobotState__FIELD_NAME__urgency[] = "urgency";
static char nash_interfaces__msg__RobotState__FIELD_NAME__goal_x[] = "goal_x";
static char nash_interfaces__msg__RobotState__FIELD_NAME__goal_y[] = "goal_y";
static char nash_interfaces__msg__RobotState__FIELD_NAME__is_moving[] = "is_moving";

static rosidl_runtime_c__type_description__Field nash_interfaces__msg__RobotState__FIELDS[] = {
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__urgency, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__goal_x, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__goal_y, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__RobotState__FIELD_NAME__is_moving, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nash_interfaces__msg__RobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nash_interfaces__msg__RobotState__TYPE_NAME, 30, 30},
      {nash_interfaces__msg__RobotState__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string  robot_id\n"
  "float64 x\n"
  "float64 y\n"
  "float64 theta\n"
  "float64 urgency\n"
  "float64 goal_x\n"
  "float64 goal_y\n"
  "bool    is_moving";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nash_interfaces__msg__RobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nash_interfaces__msg__RobotState__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 115, 115},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nash_interfaces__msg__RobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nash_interfaces__msg__RobotState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
