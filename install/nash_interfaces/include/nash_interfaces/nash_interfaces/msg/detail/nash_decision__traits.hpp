// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nash_interfaces:msg/NashDecision.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nash_interfaces/msg/nash_decision.hpp"


#ifndef NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__TRAITS_HPP_
#define NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nash_interfaces/msg/detail/nash_decision__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace nash_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const NashDecision & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_a_id
  {
    out << "robot_a_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_a_id, out);
    out << ", ";
  }

  // member: robot_b_id
  {
    out << "robot_b_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_b_id, out);
    out << ", ";
  }

  // member: robot_a_action
  {
    out << "robot_a_action: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_a_action, out);
    out << ", ";
  }

  // member: robot_b_action
  {
    out << "robot_b_action: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_b_action, out);
    out << ", ";
  }

  // member: strategy_type
  {
    out << "strategy_type: ";
    rosidl_generator_traits::value_to_yaml(msg.strategy_type, out);
    out << ", ";
  }

  // member: robot_a_prob_go
  {
    out << "robot_a_prob_go: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_a_prob_go, out);
    out << ", ";
  }

  // member: robot_b_prob_go
  {
    out << "robot_b_prob_go: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_b_prob_go, out);
    out << ", ";
  }

  // member: urgency_a
  {
    out << "urgency_a: ";
    rosidl_generator_traits::value_to_yaml(msg.urgency_a, out);
    out << ", ";
  }

  // member: urgency_b
  {
    out << "urgency_b: ";
    rosidl_generator_traits::value_to_yaml(msg.urgency_b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NashDecision & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_a_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_a_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_a_id, out);
    out << "\n";
  }

  // member: robot_b_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_b_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_b_id, out);
    out << "\n";
  }

  // member: robot_a_action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_a_action: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_a_action, out);
    out << "\n";
  }

  // member: robot_b_action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_b_action: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_b_action, out);
    out << "\n";
  }

  // member: strategy_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "strategy_type: ";
    rosidl_generator_traits::value_to_yaml(msg.strategy_type, out);
    out << "\n";
  }

  // member: robot_a_prob_go
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_a_prob_go: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_a_prob_go, out);
    out << "\n";
  }

  // member: robot_b_prob_go
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_b_prob_go: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_b_prob_go, out);
    out << "\n";
  }

  // member: urgency_a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "urgency_a: ";
    rosidl_generator_traits::value_to_yaml(msg.urgency_a, out);
    out << "\n";
  }

  // member: urgency_b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "urgency_b: ";
    rosidl_generator_traits::value_to_yaml(msg.urgency_b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NashDecision & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace nash_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nash_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nash_interfaces::msg::NashDecision & msg,
  std::ostream & out, size_t indentation = 0)
{
  nash_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nash_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nash_interfaces::msg::NashDecision & msg)
{
  return nash_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nash_interfaces::msg::NashDecision>()
{
  return "nash_interfaces::msg::NashDecision";
}

template<>
inline const char * name<nash_interfaces::msg::NashDecision>()
{
  return "nash_interfaces/msg/NashDecision";
}

template<>
struct has_fixed_size<nash_interfaces::msg::NashDecision>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nash_interfaces::msg::NashDecision>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nash_interfaces::msg::NashDecision>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__TRAITS_HPP_
