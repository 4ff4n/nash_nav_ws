// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nash_interfaces:msg/NashDecision.idl
// generated code does not contain a copyright notice

#include "nash_interfaces/msg/detail/nash_decision__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nash_interfaces
const rosidl_type_hash_t *
nash_interfaces__msg__NashDecision__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfa, 0x00, 0xb3, 0xa6, 0xe6, 0xf4, 0xa0, 0x32,
      0xb4, 0x5b, 0xdb, 0x50, 0x71, 0xa0, 0x08, 0x1e,
      0x37, 0x04, 0x88, 0x99, 0x50, 0x88, 0xe2, 0x0a,
      0x66, 0x4d, 0x79, 0x8d, 0xad, 0x8d, 0x64, 0xfc,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char nash_interfaces__msg__NashDecision__TYPE_NAME[] = "nash_interfaces/msg/NashDecision";

// Define type names, field names, and default values
static char nash_interfaces__msg__NashDecision__FIELD_NAME__robot_a_id[] = "robot_a_id";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__robot_b_id[] = "robot_b_id";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__robot_a_action[] = "robot_a_action";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__robot_b_action[] = "robot_b_action";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__strategy_type[] = "strategy_type";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__robot_a_prob_go[] = "robot_a_prob_go";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__robot_b_prob_go[] = "robot_b_prob_go";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__urgency_a[] = "urgency_a";
static char nash_interfaces__msg__NashDecision__FIELD_NAME__urgency_b[] = "urgency_b";

static rosidl_runtime_c__type_description__Field nash_interfaces__msg__NashDecision__FIELDS[] = {
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__robot_a_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__robot_b_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__robot_a_action, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__robot_b_action, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__strategy_type, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__robot_a_prob_go, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__robot_b_prob_go, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__urgency_a, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nash_interfaces__msg__NashDecision__FIELD_NAME__urgency_b, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nash_interfaces__msg__NashDecision__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nash_interfaces__msg__NashDecision__TYPE_NAME, 32, 32},
      {nash_interfaces__msg__NashDecision__FIELDS, 9, 9},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string  robot_a_id\n"
  "string  robot_b_id\n"
  "string  robot_a_action\n"
  "string  robot_b_action\n"
  "string  strategy_type\n"
  "float64 robot_a_prob_go\n"
  "float64 robot_b_prob_go\n"
  "float64 urgency_a\n"
  "float64 urgency_b";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nash_interfaces__msg__NashDecision__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nash_interfaces__msg__NashDecision__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 190, 190},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nash_interfaces__msg__NashDecision__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nash_interfaces__msg__NashDecision__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
