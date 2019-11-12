
#include "mcp9804_temp_sensor.h"

#include "temp_i2c.h"

#include "error_handler.h"

#include "telemetry.h"

// This function initializes the three temperature sensors
void MCP9804TempSensorInitialize(void) {
    
    // Write config data to config register on input temp sensor
    uint8_t length;
    uint8_t output_data_array[3];
    output_data_array[0] = MCP9804_CONFIG_REG;
    output_data_array[1] = MCP9804_CONFIG_MSB;
    output_data_array[3] = MCP9804_CONFIG_LSB;
    length = 3;    
    TEMP_I2C_MasterWrite(output_data_array, length, INPUT_TEMP_SENS_ADDR, &I2C_STATUS);
    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (    I2C_STATUS == TEMP_I2C_MESSAGE_FAIL ||
            I2C_STATUS == TEMP_I2C_STUCK_START ||
            I2C_STATUS == TEMP_I2C_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == TEMP_I2C_DATA_NO_ACK ||
            I2C_STATUS == TEMP_I2C_LOST_STATE      ) {
        error_handler.flags.input_temp_sens_I2C_fault = 1;
    }
    
    // Write config data to config register on pos3p3 power supply temp sensor
    TEMP_I2C_MasterWrite(output_data_array, length, POS3P3_TEMP_SENS_ADDR, &I2C_STATUS);
    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (    I2C_STATUS == TEMP_I2C_MESSAGE_FAIL ||
            I2C_STATUS == TEMP_I2C_STUCK_START ||
            I2C_STATUS == TEMP_I2C_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == TEMP_I2C_DATA_NO_ACK ||
            I2C_STATUS == TEMP_I2C_LOST_STATE      ) {
        error_handler.flags.pos3p3_temp_sens_I2C_fault = 1;
    }
    
    // Write config data to config register on ambient temp sensor
    TEMP_I2C_MasterWrite(output_data_array, length, AMB_TEMP_SENS_ADDR, &I2C_STATUS);
    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (    I2C_STATUS == TEMP_I2C_MESSAGE_FAIL ||
            I2C_STATUS == TEMP_I2C_STUCK_START ||
            I2C_STATUS == TEMP_I2C_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == TEMP_I2C_DATA_NO_ACK ||
            I2C_STATUS == TEMP_I2C_LOST_STATE      ) {
        error_handler.flags.amb_temp_sens_I2C_fault = 1;
    }
    
    // Write config data to config register on bckp temp sensor
    TEMP_I2C_MasterWrite(output_data_array, length, BCKP_TEMP_SENS_ADDR, &I2C_STATUS);
    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (    I2C_STATUS == TEMP_I2C_MESSAGE_FAIL ||
            I2C_STATUS == TEMP_I2C_STUCK_START ||
            I2C_STATUS == TEMP_I2C_MESSAGE_ADDRESS_NO_ACK ||
            I2C_STATUS == TEMP_I2C_DATA_NO_ACK ||
            I2C_STATUS == TEMP_I2C_LOST_STATE      ) {
        error_handler.flags.bckp_temp_sens_I2C_fault = 1;
    }
    
}

// this function converts the ray two byte data return from MCP9804 to a double representing temperature
double MCP9804BytesToFloat(uint8_t input_array[2]) {
    
    input_array[0] = input_array[0] & 0x1F;
    // if we read a negative temperature
    if ((input_array[0] & 0x10) == 0x10) {

        input_array[0] = input_array[0] & 0x0F; //Clear SIGN
        // convert to floating point number
        return 256.0 - ((input_array[0] * 16.0) + (input_array[1] / 16.0));
        
    }
    
    // else if we read a positive temperature
    else {
     
        return ((input_array[0] * 16.0) + (input_array[1] / 16.0));
        
    }

}

// This function accesses temperature sensor data over I2C
void MCP9804AcquisitionHandler(void) {
    
    // we're done acquiring new data
    MCP9804_start_flag = 0;
    
    // input temp sensor
    // Write temp reg addr to read back temp sensor data
    uint8_t data_reg_pointer[1];
    data_reg_pointer[0] = MCP9804_TA_REG;
    TEMP_I2C_MasterWrite(data_reg_pointer, 1, INPUT_TEMP_SENS_ADDR, &I2C_STATUS);
    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.input_temp_sens_I2C_fault = 1;
    // Read two bytes from temp reg
    TEMP_I2C_MasterRead(MCP9804_temp_results.input_temp_raw, 2, INPUT_TEMP_SENS_ADDR, &I2C_STATUS);
    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.input_temp_sens_I2C_fault = 1;
    telemetry.current.params.input_temperature = MCP9804BytesToFloat(MCP9804_temp_results.input_temp_raw);
    
//    // pos3p3 temp sensor
//    // Write temp reg addr to read back temp sensor data
//    data_reg_pointer[0] = MCP9804_TA_REG;
//    TEMP_I2C_MasterWrite(data_reg_pointer, 1, POS3P3_TEMP_SENS_ADDR, &I2C_STATUS);
//    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
//    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.pos3p3_temp_sens_I2C_fault = 1;
//    // Read two bytes from temp reg
//    TEMP_I2C_MasterRead(MCP9804_temp_results.pos3p3_temp_raw, 2, POS3P3_TEMP_SENS_ADDR, &I2C_STATUS);
//    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
//    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.pos3p3_temp_sens_I2C_fault = 1;
//    telemetry.current.params.pos3p3_temperature = MCP9804BytesToFloat(MCP9804_temp_results.pos3p3_temp_raw);
    
//    // amb temp sensor
//    // Write temp reg addr to read back temp sensor data
//    data_reg_pointer[0] = MCP9804_TA_REG;
//    TEMP_I2C_MasterWrite(data_reg_pointer, 1, AMB_TEMP_SENS_ADDR, &I2C_STATUS);
//    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
//    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.amb_temp_sens_I2C_fault = 1;
//    // Read two bytes from temp reg
//    TEMP_I2C_MasterRead(MCP9804_temp_results.amb_temp_raw, 2, AMB_TEMP_SENS_ADDR, &I2C_STATUS);
//    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
//    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.amb_temp_sens_I2C_fault = 1;
//    telemetry.current.params.input_temperature = MCP9804BytesToFloat(MCP9804_temp_results.amb_temp_raw);
    
//    // bckp temp sensor
//    // Write temp reg addr to read back temp sensor data
//    data_reg_pointer[0] = MCP9804_TA_REG;
//    TEMP_I2C_MasterWrite(data_reg_pointer, 1, BCKP_TEMP_SENS_ADDR, &I2C_STATUS);
//    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
//    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.bckp_temp_sens_I2C_fault = 1;
//    // Read two bytes from temp reg
//    TEMP_I2C_MasterRead(MCP9804_temp_results.bckp_temp_raw, 2, BCKP_TEMP_SENS_ADDR, &I2C_STATUS);
//    while(I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
//    if (I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.bckp_temp_sens_I2C_fault = 1;
//    telemetry.current.params.input_temperature = MCP9804BytesToFloat(MCP9804_temp_results.bckp_temp_raw);
    
    
}
