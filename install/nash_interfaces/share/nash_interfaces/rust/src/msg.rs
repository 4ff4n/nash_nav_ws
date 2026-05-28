#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to nash_interfaces__msg__RobotState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_id: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RobotState::default())
  }
}

impl rosidl_runtime_rs::Message for RobotState {
  type RmwMsg = super::msg::rmw::RobotState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_id: msg.robot_id.as_str().into(),
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
        urgency: msg.urgency,
        goal_x: msg.goal_x,
        goal_y: msg.goal_y,
        is_moving: msg.is_moving,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_id: msg.robot_id.as_str().into(),
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      urgency: msg.urgency,
      goal_x: msg.goal_x,
      goal_y: msg.goal_y,
      is_moving: msg.is_moving,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      robot_id: msg.robot_id.to_string(),
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      urgency: msg.urgency,
      goal_x: msg.goal_x,
      goal_y: msg.goal_y,
      is_moving: msg.is_moving,
    }
  }
}


// Corresponds to nash_interfaces__msg__NashDecision

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NashDecision {

    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_a_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_b_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_a_action: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_b_action: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub strategy_type: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NashDecision::default())
  }
}

impl rosidl_runtime_rs::Message for NashDecision {
  type RmwMsg = super::msg::rmw::NashDecision;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_a_id: msg.robot_a_id.as_str().into(),
        robot_b_id: msg.robot_b_id.as_str().into(),
        robot_a_action: msg.robot_a_action.as_str().into(),
        robot_b_action: msg.robot_b_action.as_str().into(),
        strategy_type: msg.strategy_type.as_str().into(),
        robot_a_prob_go: msg.robot_a_prob_go,
        robot_b_prob_go: msg.robot_b_prob_go,
        urgency_a: msg.urgency_a,
        urgency_b: msg.urgency_b,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_a_id: msg.robot_a_id.as_str().into(),
        robot_b_id: msg.robot_b_id.as_str().into(),
        robot_a_action: msg.robot_a_action.as_str().into(),
        robot_b_action: msg.robot_b_action.as_str().into(),
        strategy_type: msg.strategy_type.as_str().into(),
      robot_a_prob_go: msg.robot_a_prob_go,
      robot_b_prob_go: msg.robot_b_prob_go,
      urgency_a: msg.urgency_a,
      urgency_b: msg.urgency_b,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      robot_a_id: msg.robot_a_id.to_string(),
      robot_b_id: msg.robot_b_id.to_string(),
      robot_a_action: msg.robot_a_action.to_string(),
      robot_b_action: msg.robot_b_action.to_string(),
      strategy_type: msg.strategy_type.to_string(),
      robot_a_prob_go: msg.robot_a_prob_go,
      robot_b_prob_go: msg.robot_b_prob_go,
      urgency_a: msg.urgency_a,
      urgency_b: msg.urgency_b,
    }
  }
}


