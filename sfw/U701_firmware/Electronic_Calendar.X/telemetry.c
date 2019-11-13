

#include "telemetry.h"

// this function sets up all min and max values of telemetry parameters
void telemetryInitialize(void) {
 
    // loop over all max telemetry params and set to maximum negative number
    // they will be reset later
    uint32_t index;
    for (index = 0; index < TEL_NUM_PARAMS; index++) {
     
        telemetry.max.param_array[index] = DBL_MAX_NEG;
        
    }

    // loop over all min telemetry params and set to maximum positive number
    // they will be reset later
    for (index = 0; index < TEL_NUM_PARAMS; index++) {
     
        telemetry.min.param_array[index] = DBL_MAX_POS;
        
    }
    
}

// this function updates the min and max telemetry records based on the current record
void telemetryUpdateExtremes(void) {
 
    // loop over all max telemetry params and set to current param value if needing update
    uint32_t index;
    for (index = 0; index < TEL_NUM_PARAMS; index++) {
     
        if (telemetry.current.param_array[index] > telemetry.max.param_array[index]) {
            
            telemetry.max.param_array[index] = telemetry.current.param_array[index];
            
        }
        
    }

    // loop over all min telemetry params and set to current param value if needing update
    for (index = 0; index < TEL_NUM_PARAMS; index++) {
     
        if ((telemetry.current.param_array[index] < telemetry.min.param_array[index]) && 
        telemetry.current.param_array[index] != 0.0) {
            
            telemetry.min.param_array[index] = telemetry.current.param_array[index];
            
        }
        
    }
    
    telemetry_update_flag_adc = 0;
    telemetry_update_flag_i2c = 0;
    
}