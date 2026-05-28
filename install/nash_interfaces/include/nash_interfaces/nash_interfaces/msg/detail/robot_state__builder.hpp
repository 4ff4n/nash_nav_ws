// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nash_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nash_interfaces/msg/robot_state.hpp"


#ifndef NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nash_interfaces/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nash_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotState_is_moving
{
public:
  explicit Init_RobotState_is_moving(::nash_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::nash_interfaces::msg::RobotState is_moving(::nash_interfaces::msg::RobotState::_is_moving_type arg)
  {
    msg_.is_moving = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

class Init_RobotState_goal_y
{
public:
  explicit Init_RobotState_goal_y(::nash_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_is_moving goal_y(::nash_interfaces::msg::RobotState::_goal_y_type arg)
  {
    msg_.goal_y = std::move(arg);
    return Init_RobotState_is_moving(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

class Init_RobotState_goal_x
{
public:
  explicit Init_RobotState_goal_x(::nash_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_goal_y goal_x(::nash_interfaces::msg::RobotState::_goal_x_type arg)
  {
    msg_.goal_x = std::move(arg);
    return Init_RobotState_goal_y(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

class Init_RobotState_urgency
{
public:
  explicit Init_RobotState_urgency(::nash_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_goal_x urgency(::nash_interfaces::msg::RobotState::_urgency_type arg)
  {
    msg_.urgency = std::move(arg);
    return Init_RobotState_goal_x(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

class Init_RobotState_theta
{
public:
  explicit Init_RobotState_theta(::nash_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_urgency theta(::nash_interfaces::msg::RobotState::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_RobotState_urgency(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

class Init_RobotState_y
{
public:
  explicit Init_RobotState_y(::nash_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_theta y(::nash_interfaces::msg::RobotState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RobotState_theta(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

class Init_RobotState_x
{
public:
  explicit Init_RobotState_x(::nash_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_y x(::nash_interfaces::msg::RobotState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotState_y(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

class Init_RobotState_robot_id
{
public:
  Init_RobotState_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_x robot_id(::nash_interfaces::msg::RobotState::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotState_x(msg_);
  }

private:
  ::nash_interfaces::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nash_interfaces::msg::RobotState>()
{
  return nash_interfaces::msg::builder::Init_RobotState_robot_id();
}

}  // namespace nash_interfaces

#endif  // NASH_INTERFACES__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
