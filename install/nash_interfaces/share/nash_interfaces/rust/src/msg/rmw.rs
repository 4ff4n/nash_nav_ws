#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "nash_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nash_interfaces__msg__RobotState() -> *const std::ffi::c_void;
}

#[link(name = "nash_interfaces__rosidl_generator_c")]
extern "C" {
    fn nash_interfaces__msg__RobotState__init(msg: *mut RobotState) -> bool;
    fn nash_interfaces__msg__RobotState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotState>, size: usize) -> bool;
    fn nash_interfaces__msg__RobotState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotState>);
    fn nash_interfaces__msg__RobotState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotState>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotState>) -> bool;
}

// Corresponds to nash_interfaces__msg__RobotState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub urgency: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_moving: bool,

}



impl Default for RobotState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nash_interfaces__msg__RobotState__init(&mut msg as *mut _) {
        panic!("Call to nash_interfaces__msg__RobotState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nash_interfaces__msg__RobotState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nash_interfaces__msg__RobotState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nash_interfaces__msg__RobotState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotState where Self: Sized {
  const TYPE_NAME: &'static str = "nash_interfaces/msg/RobotState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nash_interfaces__msg__RobotState() }
  }
}


#[link(name = "nash_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nash_interfaces__msg__NashDecision() -> *const std::ffi::c_void;
}

#[link(name = "nash_interfaces__rosidl_generator_c")]
extern "C" {
    fn nash_interfaces__msg__NashDecision__init(msg: *mut NashDecision) -> bool;
    fn nash_interfaces__msg__NashDecision__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NashDecision>, size: usize) -> bool;
    fn nash_interfaces__msg__NashDecision__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NashDecision>);
    fn nash_interfaces__msg__NashDecision__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NashDecision>, out_seq: *mut rosidl_runtime_rs::Sequence<NashDecision>) -> bool;
}

// Corresponds to nash_interfaces__msg__NashDecision
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NashDecision {

    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_a_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_b_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_a_action: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_b_action: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub strategy_type: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_a_prob_go: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_b_prob_go: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub urgency_a: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub urgency_b: f64,

}



impl Default for NashDecision {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nash_interfaces__msg__NashDecision__init(&mut msg as *mut _) {
        panic!("Call to nash_interfaces__msg__NashDecision__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NashDecision {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nash_interfaces__msg__NashDecision__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nash_interfaces__msg__NashDecision__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nash_interfaces__msg__NashDecision__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NashDecision {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NashDecision where Self: Sized {
  const TYPE_NAME: &'static str = "nash_interfaces/msg/NashDecision";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nash_interfaces__msg__NashDecision() }
  }
}


