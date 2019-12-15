/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _MCP9804_TEMP_SENSOR_H    /* Guard against multiple inclusion */
#define _MCP9804_TEMP_SENSOR_H

#include <xc.h>
#include <stdbool.h>

#include "temp_i2c.h"

// I2C sensor addresses
#define INPUT_TEMP_SENS_ADDR        0x18
#define POS3P3_TEMP_SENS_ADDR       0x19
#define AMB_TEMP_SENS_ADDR          0x1A
#define BCKP_TEMP_SENS_ADDR         0x1B

// MCP9804 register pointers
// from register 5-1 of MCP9804 datasheet
#define MCP9804_CONFIG_REG          0b0001
#define MCP9804_TUPPER_REG          0b0010
#define MCP9804_TLOWER_REG          0b0011
#define MCP9804_TCRIT_REG           0b0100
#define MCP9804_TA_REG              0b0101
#define MCP9804_MANF_ID_REG         0b0110
#define MCP9804_DEV_ID_REG          0b0111
#define MCP9804_RES_REG             0b1000

// these macros hold hardcoded config data for the sensors
#define MCP9804_CONFIG_LSB          0
#define MCP9804_CONFIG_MSB          0


// This structure holds calculated temperatures and raw 14 bit conversion results
struct MCP9804_temp_results_s {
    
    uint8_t input_temp_raw[2];
    uint8_t pos3p3_temp_raw[2];
    uint8_t amb_temp_raw[2];
    uint8_t bckp_temp_raw[2];

} MCP9804_temp_results;

// This is a flag that starts the acquisition of data from the MCP9804 sensors
volatile uint32_t MCP9804_start_flag;

// This function initializes the three temperature sensors
void MCP9804TempSensorInitialize(void);

// this function converts the ray two byte data return from MCP9804 to a double representing temperature
double MCP9804BytesToFloat(uint8_t input_array[2]);

// This function accesses temperature sensor data over I2C
void MCP9804AcquisitionHandler(void);

// This function converts all raw byte value of temperature into floats for telemetry
void MCP9804BatchConvert(void);

#endif /* _MCP9804_TEMP_SENSOR_H */

/* *****************************************************************************
 End of File
 */
