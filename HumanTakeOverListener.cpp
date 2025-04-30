// HumanTakeOverListener:
//    gps = GET_CURRENT_GPS_POSITION()
//    heading = GET_CURRENT_HEADING()
//    speed = GET_CURRENT_SPEED()
//    planned_path = GET_CURRENT_PATH()

//    check_takeover_occurrence(gps, speed, heading, position) -> INT:
//       existing_takeover = database.find_similar_takeover(gps, heading,
//          position, speed)
//       IF existing_takeover != NULL 
//          RETURN existing_takeover.occurrence_count
//       ELSE RETURN 0

//    handle_takeover_event(gps, heading, position, speed, planned_path):
//       occurrences = check_takeover_occurrence()
//          IF occurrences = 0
//             database.save_takeover_event()
//          IF occurrences = 1	
//             database.update_takeover_count(existing_takeover.id)
//             alert_gen_path()
//          IF occurrences >= 2                   
//             THROW ERROR

//    subscribe_to_ros_topic():
//       LISTEN to takeover_event_topic
//       WHEN takeover event DETECTED
//       handle_takeover_event(gps, heading, position, speed, planned_path)

//    alerts_gen_path():
//       TODO!


// START OF CODE
#include <rviz_common/display_context.hpp>
#include "autoware/control_evaluator/control_evaluator_node.hpp"
#include <rviz_common/ros_integration/ros_node_abstraction_iface.hpp>

#include "autoware/control_evaluator/metrics/metrics_utils.hpp"
void subscribe_to_ros_topic() {
  raw_node_ = this->getDisplayContext()->getRosNodeAbstraction().lock()->get_raw_node();

  sub_operation_mode_ = raw_node_->create_subscription<OperationModeState>(
    "/api/operation_mode/state", rclcpp::QoS{1}.transient_local(),
    std::bind(&on_takeover, this, std::placeholders::_1));
}
    
void on_takeover(const OperationModeState::ConstSharedPtr msg) {
 if (msg->is_autoware_control_enabled) {
    const auto odom = odometry_sub_.take_data(); // from control_evaluator_node
    handle_takeover_event(odom->pose.pose);
  }
}

void handle_takeover_event(const geometry_msgs::msg::Pose event_pose) {
  occurrences = check_takeover_occurrence(event_pose);
  if (occurences == 0) {
    TakeOverRecord.insertRecord(event_pose);
  } else {
    TakeOverRecord.updateCount(event_pose);
    // TODO: generate path
  }
}

int check_takeover_occurence(const geometry_msgs::msg::Pose event_pose) {
  //TODO: implement method
}
