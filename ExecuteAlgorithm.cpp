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
//
// run with obj.kinematics.initial_pose_with_covariance.pose
// Pose near_takeover_record (const Pose & current_pose) {
//   const tolerance = 1;
//   const double cur_x = current_pose.position.x;
//   const double cur_y = current_pose.position.y;
//   for (Pose prev_pose : storedPoses) {
//     const double prev_x = prev_pose.position.x;
//     const double prev_y = prev_pose.position.y;
//     const Pose dist = hypot((prev_x-cur_x), (prev_y-cur_y));
//     if (dist < tolerance) return prev_pose; TODO: ensure that direction also matches (pose.orientation)
//   }
//  return null;
// }