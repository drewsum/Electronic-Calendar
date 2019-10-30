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

#ifndef _TELEMETRY_H    /* Guard against multiple inclusion */
#define _TELEMETRY_H

#include <xc.h>

// These macros define the largest representable number with a double
#define DBL_MAX_POS         1.0E+37
#define DBL_MAX_NEG         -1.0E+37

// These constants compensate for input voltage dividers/value scaling
#define POS3P3_CHANNEL_GAIN         2.0
#define POS12_CHANNEL_GAIN          9.3333333333333333333333
#define POS5_USB_CHANNEL_GAIN       2.0
#define POS12_ISNS_CHANNEL_GAIN     1.002004008
#define POS3P3_ISNS_CHANNEL_GAIN    2.50501002004
#define VBAT_CHANNEL_GAIN           2.0
#define ADC_TEMP_SENS_OFFSET        -100.0

// This flag keeps track of if we need to update min and max values
uint32_t telemetry_extremes_update_flag;

#define TEL_NUM_PARAMS              8

// This structure defines the parameters for telemetry
// unless otherwise noted, voltage measurements are in volts, and
// current measurements are in amps
// unionizing allows looping over all params
typedef union telemetry_paramaters_u {
    
    struct params_s {

        double pos3p3_voltage;              // output voltage of the +3.3V power supply
        double pos12_voltage;               // Input voltage measurement
        double pos5_usb_voltage;            // measured USB bus voltage
        double pos12_current;               // measured input current
        double pos3p3_current;              // measured output current of +3.3V power supply
        double vbat_voltage;                // measured battery voltage of backup battery
        double mcu_vref_voltage;            // internal voltage reference for MCU
        double mcu_die_temp;                // die temp of MCU

    } params;
    
    double param_array[TEL_NUM_PARAMS];

} telemetry_parameters_t;
    
// This structure holds minimum, maximum and current telemetry values
struct telemetry_s {
    
    telemetry_parameters_t max;
    telemetry_parameters_t current;
    telemetry_parameters_t min;
    
} telemetry;

// this function sets up all min and max values of telemetry parameters
void telemetryInitialize(void);

// this function updates the min and max telemetry records based on the current record
void telemetryUpdateExtremes(void);


#endif /* _TELEMETRY_H */

/* *****************************************************************************
 End of File
 */
