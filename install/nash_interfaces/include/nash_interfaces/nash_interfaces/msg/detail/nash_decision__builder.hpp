// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nash_interfaces:msg/NashDecision.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nash_interfaces/msg/nash_decision.hpp"


#ifndef NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__BUILDER_HPP_
#define NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nash_interfaces/msg/detail/nash_decision__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nash_interfaces
{

namespace msg
{

namespace builder
{

class Init_NashDecision_urgency_b
{
public:
  explicit Init_NashDecision_urgency_b(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  ::nash_interfaces::msg::NashDecision urgency_b(::nash_interfaces::msg::NashDecision::_urgency_b_type arg)
  {
    msg_.urgency_b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_urgency_a
{
public:
  explicit Init_NashDecision_urgency_a(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  Init_NashDecision_urgency_b urgency_a(::nash_interfaces::msg::NashDecision::_urgency_a_type arg)
  {
    msg_.urgency_a = std::move(arg);
    return Init_NashDecision_urgency_b(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_robot_b_prob_go
{
public:
  explicit Init_NashDecision_robot_b_prob_go(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  Init_NashDecision_urgency_a robot_b_prob_go(::nash_interfaces::msg::NashDecision::_robot_b_prob_go_type arg)
  {
    msg_.robot_b_prob_go = std::move(arg);
    return Init_NashDecision_urgency_a(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_robot_a_prob_go
{
public:
  explicit Init_NashDecision_robot_a_prob_go(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  Init_NashDecision_robot_b_prob_go robot_a_prob_go(::nash_interfaces::msg::NashDecision::_robot_a_prob_go_type arg)
  {
    msg_.robot_a_prob_go = std::move(arg);
    return Init_NashDecision_robot_b_prob_go(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_strategy_type
{
public:
  explicit Init_NashDecision_strategy_type(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  Init_NashDecision_robot_a_prob_go strategy_type(::nash_interfaces::msg::NashDecision::_strategy_type_type arg)
  {
    msg_.strategy_type = std::move(arg);
    return Init_NashDecision_robot_a_prob_go(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_robot_b_action
{
public:
  explicit Init_NashDecision_robot_b_action(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  Init_NashDecision_strategy_type robot_b_action(::nash_interfaces::msg::NashDecision::_robot_b_action_type arg)
  {
    msg_.robot_b_action = std::move(arg);
    return Init_NashDecision_strategy_type(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_robot_a_action
{
public:
  explicit Init_NashDecision_robot_a_action(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  Init_NashDecision_robot_b_action robot_a_action(::nash_interfaces::msg::NashDecision::_robot_a_action_type arg)
  {
    msg_.robot_a_action = std::move(arg);
    return Init_NashDecision_robot_b_action(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_robot_b_id
{
public:
  explicit Init_NashDecision_robot_b_id(::nash_interfaces::msg::NashDecision & msg)
  : msg_(msg)
  {}
  Init_NashDecision_robot_a_action robot_b_id(::nash_interfaces::msg::NashDecision::_robot_b_id_type arg)
  {
    msg_.robot_b_id = std::move(arg);
    return Init_NashDecision_robot_a_action(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

class Init_NashDecision_robot_a_id
{
public:
  Init_NashDecision_robot_a_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NashDecision_robot_b_id robot_a_id(::nash_interfaces::msg::NashDecision::_robot_a_id_type arg)
  {
    msg_.robot_a_id = std::move(arg);
    return Init_NashDecision_robot_b_id(msg_);
  }

private:
  ::nash_interfaces::msg::NashDecision msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nash_interfaces::msg::NashDecision>()
{
  return nash_interfaces::msg::builder::Init_NashDecision_robot_a_id();
}

}  // namespace nash_interfaces

#endif  // NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__BUILDER_HPP_
