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

#ifndef _MISC_IO_FUNCTIONS_H    /* Guard against multiple inclusion */
#define _MISC_IO_FUNCTIONS_H

#include <xc.h>

struct pgood_status_s {
    
    uint8_t POS3P3_PGOOD;
    uint8_t POS12_PGOOD;
    uint8_t POS5_USB_PGOOD;
    uint8_t BCKP_PGOOD;
    uint8_t VBAT_ISOLATE;
    
} pgood_status;

// this function checks the state of the power good signals
void powerGoodCheck(void);

// this function prints current PGOOD status
void printPGOODStatus(void);

#endif /* _MISC_IO_FUNCTIONS_H */

/* *****************************************************************************
 End of File
 */
