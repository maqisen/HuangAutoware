// GenerateCorrectedPath:
//    get_corrected_path(second_inv_record, planned_path) -> Path:
//       GET generated_path from alternative_routes
//       GET first_inv_record from alternative_routes           
//       IF generated_path exists 
//       //TODO: Throw error here? shouldn’t call this class if generated_path is      
//       //already in alternative_routes as that would mean there have already      
//       //been at least 2 takeovers at this scenario for it to have been saved 
//          new_path = generated_path (from database)
//       ELSE:
//          new_path = calculate_alternative_path(first_inv_record,  
//             second_inv_record, planned_path)
//          save_path_to_database(second_inv_record.id, new_path)
//       RETURN new_path
   
//    calculate_alternative_path(first_inv_record,second_inv_record,planned_path)    
//       -> Path:
//       //TODO: Calc a new path
//       RETURN new_path
