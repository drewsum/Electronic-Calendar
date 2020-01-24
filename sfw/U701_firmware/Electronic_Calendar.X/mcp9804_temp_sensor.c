
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
    TEMP_I2C_MasterWrite(output_data_array, length, INPUT_TEMP_SENS_ADDR, &TEMP_I2C_STATUS);
    while(TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.pos12_temp_error = 1;
    
    // Write config data to config register on pos3p3 power supply temp sensor
    TEMP_I2C_MasterWrite(output_data_array, length, POS3P3_TEMP_SENS_ADDR, &TEMP_I2C_STATUS);
    while(TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.pos3p3_temp_error = 1;
    
    // Write config data to config register on ambient temp sensor
    TEMP_I2C_MasterWrite(output_data_array, length, AMB_TEMP_SENS_ADDR, &TEMP_I2C_STATUS);
    while(TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.ambient_temp_error = 1;
    
    // Write config data to config register on bckp temp sensor
    TEMP_I2C_MasterWrite(output_data_array, length, BCKP_TEMP_SENS_ADDR, &TEMP_I2C_STATUS);
    while(TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.bckp_temp_error = 1;
    
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
    
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) {
        
        // log the fault
        error_handler.flags.temp_i2c_stall = 1;
        
        // reset the I2C controller if it's enabled
        // if (getTempI2COnState) tempI2COnStateReset();
        
    }
    
    // input temp sensor
    telemetry.current.params.input_temperature = MCP9804GetTemperature(INPUT_TEMP_SENS_ADDR);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.pos12_temp_error = 1;
    
    // pos3p3 temp sensor
    telemetry.current.params.pos3p3_temperature = MCP9804GetTemperature(POS3P3_TEMP_SENS_ADDR);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.pos3p3_temp_error = 1;
    
    // amb temp sensor
    telemetry.current.params.ambient_temperature = MCP9804GetTemperature(AMB_TEMP_SENS_ADDR);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.ambient_temp_error = 1;
    
    // bckp temp sensor
    telemetry.current.params.backup_temperature = MCP9804GetTemperature(BCKP_TEMP_SENS_ADDR);
    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) error_handler.flags.bckp_temp_error = 1;
    
    // we're done acquiring new data
    MCP9804_start_flag = 0;
    
    telemetry_update_flag_i2c = 1;
    
}

// this function gets data over I2C from the given I2C address and returns the converted temperature
double MCP9804GetTemperature(uint8_t input_address) {

    if (TEMP_I2C_STATUS != TEMP_I2C_MESSAGE_COMPLETE) {
        
        // log the fault
        error_handler.flags.temp_i2c_stall = 1;
        
        // reset the I2C controller if it's enabled
        // if (getTempI2COnState) tempI2COnStateReset();
        
    }
    
    uint8_t data_reg_pointer[1];
    uint8_t temp[2];
    data_reg_pointer[0] = MCP9804_TA_REG;
    TEMP_I2C_MasterWrite(data_reg_pointer, 1, input_address, &TEMP_I2C_STATUS);
    while(TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    // Read two bytes from temp reg
    TEMP_I2C_MasterRead(temp, 2, input_address, &TEMP_I2C_STATUS);
    while(TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    
    if (TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_COMPLETE) return MCP9804BytesToFloat(temp);
    else return 0.0;
    
}