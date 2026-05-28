// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nash_interfaces:msg/NashDecision.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nash_interfaces/msg/nash_decision.hpp"


#ifndef NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__STRUCT_HPP_
#define NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__nash_interfaces__msg__NashDecision __attribute__((deprecated))
#else
# define DEPRECATED__nash_interfaces__msg__NashDecision __declspec(deprecated)
#endif

namespace nash_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NashDecision_
{
  using Type = NashDecision_<ContainerAllocator>;

  explicit NashDecision_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_a_id = "";
      this->robot_b_id = "";
      this->robot_a_action = "";
      this->robot_b_action = "";
      this->strategy_type = "";
      this->robot_a_prob_go = 0.0;
      this->robot_b_prob_go = 0.0;
      this->urgency_a = 0.0;
      this->urgency_b = 0.0;
    }
  }

  explicit NashDecision_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_a_id(_alloc),
    robot_b_id(_alloc),
    robot_a_action(_alloc),
    robot_b_action(_alloc),
    strategy_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_a_id = "";
      this->robot_b_id = "";
      this->robot_a_action = "";
      this->robot_b_action = "";
      this->strategy_type = "";
      this->robot_a_prob_go = 0.0;
      this->robot_b_prob_go = 0.0;
      this->urgency_a = 0.0;
      this->urgency_b = 0.0;
    }
  }

  // field types and members
  using _robot_a_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_a_id_type robot_a_id;
  using _robot_b_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_b_id_type robot_b_id;
  using _robot_a_action_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_a_action_type robot_a_action;
  using _robot_b_action_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_b_action_type robot_b_action;
  using _strategy_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _strategy_type_type strategy_type;
  using _robot_a_prob_go_type =
    double;
  _robot_a_prob_go_type robot_a_prob_go;
  using _robot_b_prob_go_type =
    double;
  _robot_b_prob_go_type robot_b_prob_go;
  using _urgency_a_type =
    double;
  _urgency_a_type urgency_a;
  using _urgency_b_type =
    double;
  _urgency_b_type urgency_b;

  // setters for named parameter idiom
  Type & set__robot_a_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_a_id = _arg;
    return *this;
  }
  Type & set__robot_b_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_b_id = _arg;
    return *this;
  }
  Type & set__robot_a_action(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_a_action = _arg;
    return *this;
  }
  Type & set__robot_b_action(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_b_action = _arg;
    return *this;
  }
  Type & set__strategy_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->strategy_type = _arg;
    return *this;
  }
  Type & set__robot_a_prob_go(
    const double & _arg)
  {
    this->robot_a_prob_go = _arg;
    return *this;
  }
  Type & set__robot_b_prob_go(
    const double & _arg)
  {
    this->robot_b_prob_go = _arg;
    return *this;
  }
  Type & set__urgency_a(
    const double & _arg)
  {
    this->urgency_a = _arg;
    return *this;
  }
  Type & set__urgency_b(
    const double & _arg)
  {
    this->urgency_b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nash_interfaces::msg::NashDecision_<ContainerAllocator> *;
  using ConstRawPtr =
    const nash_interfaces::msg::NashDecision_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nash_interfaces::msg::NashDecision_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nash_interfaces::msg::NashDecision_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nash_interfaces__msg__NashDecision
    std::shared_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nash_interfaces__msg__NashDecision
    std::shared_ptr<nash_interfaces::msg::NashDecision_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NashDecision_ & other) const
  {
    if (this->robot_a_id != other.robot_a_id) {
      return false;
    }
    if (this->robot_b_id != other.robot_b_id) {
      return false;
    }
    if (this->robot_a_action != other.robot_a_action) {
      return false;
    }
    if (this->robot_b_action != other.robot_b_action) {
      return false;
    }
    if (this->strategy_type != other.strategy_type) {
      return false;
    }
    if (this->robot_a_prob_go != other.robot_a_prob_go) {
      return false;
    }
    if (this->robot_b_prob_go != other.robot_b_prob_go) {
      return false;
    }
    if (this->urgency_a != other.urgency_a) {
      return false;
    }
    if (this->urgency_b != other.urgency_b) {
      return false;
    }
    return true;
  }
  bool operator!=(const NashDecision_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NashDecision_

// alias to use template instance with default allocator
using NashDecision =
  nash_interfaces::msg::NashDecision_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nash_interfaces

#endif  // NASH_INTERFACES__MSG__DETAIL__NASH_DECISION__STRUCT_HPP_
