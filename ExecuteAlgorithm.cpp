// ExecuteAlgorithm:
//    run_algorithm(current_gps, current_heading):
//       IF near_takeover_record
//          //Reroute needed
//           new_path = path_generator.calculate_alternative_path (near_takeover_record)
//         database.save_new_path(takeover_record.id, new_path)
//         update_planning_module(new_path)

//    update_planning_module(new_path):
//    TODO!

// requires:
// #include <autoware/motion_utils/trajectory/conversion.hpp>
// #include <autoware/motion_utils/trajectory/trajectory.hpp>
// #include <tf2_geometry_msgs/tf2_geometry_msgs.h>
//
// run with obj.kinematics.initial_pose_with_covariance.pose
// Pose near_takeover_record (const Pose & current_pose) {
//   const distTolerance = 1;
//   const yawTolerance = 0.2;
//   const double cur_x = current_pose.position.x;
//   const double cur_y = current_pose.position.y;
//   const double cur_yaw = tf2::getYaw(current_pose.orientation);
//   for (Pose prev_pose : storedPoses) {
//     const double prev_x = prev_pose.position.x;
//     const double prev_y = prev_pose.position.y;
//     const double pev_yaw = tf2::getYaw(prev_pose.orientation);
//     const Pose dist = hypot((prev_x-cur_x), (prev_y-cur_y));
//     const double yaw_dif = abs(cur_yaw-prev_yaw);
//     if (dist < distTolerance && yaw_dif < yawTolerance) return prev_pose;
//   }
//  return null;
// }