// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nash_interfaces:msg/NashDecision.idl
// generated code does not contain a copyright notice
#include "nash_interfaces/msg/detail/nash_decision__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_a_id`
// Member `robot_b_id`
// Member `robot_a_action`
// Member `robot_b_action`
// Member `strategy_type`
#include "rosidl_runtime_c/string_functions.h"

bool
nash_interfaces__msg__NashDecision__init(nash_interfaces__msg__NashDecision * msg)
{
  if (!msg) {
    return false;
  }
  // robot_a_id
  if (!rosidl_runtime_c__String__init(&msg->robot_a_id)) {
    nash_interfaces__msg__NashDecision__fini(msg);
    return false;
  }
  // robot_b_id
  if (!rosidl_runtime_c__String__init(&msg->robot_b_id)) {
    nash_interfaces__msg__NashDecision__fini(msg);
    return false;
  }
  // robot_a_action
  if (!rosidl_runtime_c__String__init(&msg->robot_a_action)) {
    nash_interfaces__msg__NashDecision__fini(msg);
    return false;
  }
  // robot_b_action
  if (!rosidl_runtime_c__String__init(&msg->robot_b_action)) {
    nash_interfaces__msg__NashDecision__fini(msg);
    return false;
  }
  // strategy_type
  if (!rosidl_runtime_c__String__init(&msg->strategy_type)) {
    nash_interfaces__msg__NashDecision__fini(msg);
    return false;
  }
  // robot_a_prob_go
  // robot_b_prob_go
  // urgency_a
  // urgency_b
  return true;
}

void
nash_interfaces__msg__NashDecision__fini(nash_interfaces__msg__NashDecision * msg)
{
  if (!msg) {
    return;
  }
  // robot_a_id
  rosidl_runtime_c__String__fini(&msg->robot_a_id);
  // robot_b_id
  rosidl_runtime_c__String__fini(&msg->robot_b_id);
  // robot_a_action
  rosidl_runtime_c__String__fini(&msg->robot_a_action);
  // robot_b_action
  rosidl_runtime_c__String__fini(&msg->robot_b_action);
  // strategy_type
  rosidl_runtime_c__String__fini(&msg->strategy_type);
  // robot_a_prob_go
  // robot_b_prob_go
  // urgency_a
  // urgency_b
}

bool
nash_interfaces__msg__NashDecision__are_equal(const nash_interfaces__msg__NashDecision * lhs, const nash_interfaces__msg__NashDecision * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_a_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_a_id), &(rhs->robot_a_id)))
  {
    return false;
  }
  // robot_b_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_b_id), &(rhs->robot_b_id)))
  {
    return false;
  }
  // robot_a_action
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_a_action), &(rhs->robot_a_action)))
  {
    return false;
  }
  // robot_b_action
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_b_action), &(rhs->robot_b_action)))
  {
    return false;
  }
  // strategy_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->strategy_type), &(rhs->strategy_type)))
  {
    return false;
  }
  // robot_a_prob_go
  if (lhs->robot_a_prob_go != rhs->robot_a_prob_go) {
    return false;
  }
  // robot_b_prob_go
  if (lhs->robot_b_prob_go != rhs->robot_b_prob_go) {
    return false;
  }
  // urgency_a
  if (lhs->urgency_a != rhs->urgency_a) {
    return false;
  }
  // urgency_b
  if (lhs->urgency_b != rhs->urgency_b) {
    return false;
  }
  return true;
}

bool
nash_interfaces__msg__NashDecision__copy(
  const nash_interfaces__msg__NashDecision * input,
  nash_interfaces__msg__NashDecision * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_a_id
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_a_id), &(output->robot_a_id)))
  {
    return false;
  }
  // robot_b_id
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_b_id), &(output->robot_b_id)))
  {
    return false;
  }
  // robot_a_action
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_a_action), &(output->robot_a_action)))
  {
    return false;
  }
  // robot_b_action
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_b_action), &(output->robot_b_action)))
  {
    return false;
  }
  // strategy_type
  if (!rosidl_runtime_c__String__copy(
      &(input->strategy_type), &(output->strategy_type)))
  {
    return false;
  }
  // robot_a_prob_go
  output->robot_a_prob_go = input->robot_a_prob_go;
  // robot_b_prob_go
  output->robot_b_prob_go = input->robot_b_prob_go;
  // urgency_a
  output->urgency_a = input->urgency_a;
  // urgency_b
  output->urgency_b = input->urgency_b;
  return true;
}

nash_interfaces__msg__NashDecision *
nash_interfaces__msg__NashDecision__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nash_interfaces__msg__NashDecision * msg = (nash_interfaces__msg__NashDecision *)allocator.allocate(sizeof(nash_interfaces__msg__NashDecision), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nash_interfaces__msg__NashDecision));
  bool success = nash_interfaces__msg__NashDecision__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nash_interfaces__msg__NashDecision__destroy(nash_interfaces__msg__NashDecision * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nash_interfaces__msg__NashDecision__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nash_interfaces__msg__NashDecision__Sequence__init(nash_interfaces__msg__NashDecision__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nash_interfaces__msg__NashDecision * data = NULL;

  if (size) {
    data = (nash_interfaces__msg__NashDecision *)allocator.zero_allocate(size, sizeof(nash_interfaces__msg__NashDecision), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nash_interfaces__msg__NashDecision__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nash_interfaces__msg__NashDecision__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
nash_interfaces__msg__NashDecision__Sequence__fini(nash_interfaces__msg__NashDecision__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nash_interfaces__msg__NashDecision__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

nash_interfaces__msg__NashDecision__Sequence *
nash_interfaces__msg__NashDecision__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nash_interfaces__msg__NashDecision__Sequence * array = (nash_interfaces__msg__NashDecision__Sequence *)allocator.allocate(sizeof(nash_interfaces__msg__NashDecision__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nash_interfaces__msg__NashDecision__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nash_interfaces__msg__NashDecision__Sequence__destroy(nash_interfaces__msg__NashDecision__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nash_interfaces__msg__NashDecision__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nash_interfaces__msg__NashDecision__Sequence__are_equal(const nash_interfaces__msg__NashDecision__Sequence * lhs, const nash_interfaces__msg__NashDecision__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nash_interfaces__msg__NashDecision__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nash_interfaces__msg__NashDecision__Sequence__copy(
  const nash_interfaces__msg__NashDecision__Sequence * input,
  nash_interfaces__msg__NashDecision__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nash_interfaces__msg__NashDecision);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nash_interfaces__msg__NashDecision * data =
      (nash_interfaces__msg__NashDecision *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nash_interfaces__msg__NashDecision__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nash_interfaces__msg__NashDecision__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nash_interfaces__msg__NashDecision__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
