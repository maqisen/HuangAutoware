// NearEncounterListener:   
//    gps = GET_CURRENT_GPS_POSITION()
//    speed = GET_CURRENT_SPEED()
//    heading = GET_CURRENT_HEADING()
//    planned_path = GET_CURRENT_PATH()

//    check_for_reroute_zone(gps, heading) -> TakeOverRecord:
//      FOR EACH record IN database.alternative_routes:
//         dis = distance(gps.latitude, gps.longitude,   
//            record.latitude, record.longitude)
//         proximity = proximity(distance, position, speed, heading)
//         IF dis <= threshold_dis AND proximity >= threshold_prox:
//            RETURN record    // Vehicle is in a reroute zone
//         ELSE RETURN NULL    // No matching reroute zone found
   
//    distance(lat_current, lon_current, lat_compare, lon_compare)-> Double:
//       RETURN distance between (lat_current, lon_current) and (lat_compare, lon_compare)
   
//    proximity(distance, position, speed, heading) -> Double:
//    **Key idea: smaller difference = higher score = higher probability paths   
//      match = more likely to necessitate intervention 
//       heading_diff = ABS(heading - record.heading)
//       position_diff = TODO - how can we compare these?
//       speed_diff = ABS(speed - record.speed)
//       distance_score = normalize(distance, max_distance) 
//       heading_score = normalize(heading_diff, max_heading_diff) 
//       position_score = normalize(position_diff, max_position_diff)
//       speed_score = normalize(speed_diff, max_speed_diff) 
//       //Get combined score using weighted sum of alls factors 
//       //TODO: Determine weights w1, w2, w3, and w4       
//       proximity_score = (w1 * (1 - distance_score)) + 
//                           (w2 * (1 - heading_score)) + 
//                           (w3 * (1 - postion_score) + 
//                           (w4 * (1 - speed_score))
// 	RETURN normalize(proximity_score)
