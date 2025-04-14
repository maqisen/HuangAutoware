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
