
#include <stdio.h>

#include "rtcc.h"

#include "device_control.h"
#include "32mz_interrupt_control.h"

// This function unlocks the RTCC for writing
void rtccUnlock(void) {
 
    // Example 29-3 in PIC32 reference manual
    
    // disable global interrupts
    disableGlobalInterrupts();
    
    // unlock device
    deviceUnlock();     // may have to explicitly write SYSKEY values instead
    
    // Suspend any DMA transactions
    DMACONbits.SUSPEND = 1;
    while (DMACONbits.DMABUSY);
    
    // set RTCWREN in RTCCONSET
    // MUST BE ONE INSTRUCTION, SO _SET REGISTER MACRO IS USED
    RTCCONSET = 0x8;
    
    // re-enable interrupts
    enableGlobalInterrupts();
    
    // re-enable the DMA controller
    DMACONbits.SUSPEND = 0;
    
}

// This function locks the RTCC so that time and date registers are not modifiable
void rtccLock(void) {
 
    // Inverse of Example 29-3 in PIC32 reference manual
    
    // disable global interrupts
    disableGlobalInterrupts();
    
    // unlock device
    deviceUnlock();     // may have to explicitly write SYSKEY values instead
    
    // Suspend any DMA transactions
    DMACONbits.SUSPEND = 1;
    while (DMACONbits.DMABUSY);
    
    // clear RTCWREN in RTCCONSET
    // MUST BE ONE INSTRUCTION, SO _CLR REGISTER MACRO IS USED
    RTCCONCLR = 0x8;
    
    // re-enable interrupts
    enableGlobalInterrupts();
    
    // re-enable the DMA controller
    DMACONbits.SUSPEND = 0;
    
    // lock the device
    deviceLock();
    
}

// This function initializes the RTCC on reset
void rtccInitialize(void) {
    
    // configure RTCC for writing
    rtccUnlock();
    
    // Disable RTCC for setup
    RTCCONbits.ON = 0;
    
    // continue RTCC in idle mode
    RTCCONbits.SIDL = 0;
    
    // Set clock source as INTOSC
    RTCCONbits.RTCCLKSEL = 0b00;
    
    // Disable RTCC clock
    RTCCONbits.RTCCLKON = 0;
    
    // Disable output pin
    RTCCONbits.RTCOE = 0;
    
    // Disable alarm (seconds IRQ)
    RTCALRMbits.ALRMEN = 0;
    
    while (RTCALRM & 0x1000); // wait ALRMSYNC to be off
    RTCALRMCLR = 0xCFFF; // clear ALRMEN, CHIME, AMASK, ARPT;
    
    // Program random stuff into alarm registers
    ALRMTIME = 0x76543210;
    ALRMDATE = 0x76543210;
    
    // Enable continuous rollover of alarm
    RTCALRMbits.CHIME = 1;
    
    // Setup alarm to trigger every second
    RTCALRMbits.AMASK = 0b0001;
    
    // Setup RTCC interrupts
    setInterruptPriority(Real_Time_Clock, 2);
    setInterruptSubpriority(Real_Time_Clock, 0);
    clearInterruptFlag(Real_Time_Clock);
    enableInterrupt(Real_Time_Clock);
    
    // Enable RTCC clock
    RTCCONbits.RTCCLKON = 1;
    
    // Unlock RTCC
    rtccUnlock();
    
    // Enable RTCC
    RTCCONbits.ON = 1;
    
    // Enable alarm (seconds IRQ)
    RTCALRMbits.ALRMEN = 1;
    
    // Lock RTCC
    rtccLock();
    
    // Clear the real time clock value
    rtccClear();
    
}

// This function clears all values in the RTCC
void rtccClear(void) {
 
    // configure RTCC for writing
    rtccUnlock();
    
    // Turn off RTCC
    RTCCONbits.ON = 0;
    
    // wait for RTCC to turn off
    while (RTCCONbits.RTCCLKON);
    
    // Write 0's everywhere
    RTCTIME = 0x00000000;
    RTCDATE = 0x00000000;
    
    // Turn on RTCC
    RTCCONbits.ON = 1;
    
    // wait for RTCC to turn on
    while (RTCCONbits.RTCCLKON == 0);
    
    // lock RTCC
    rtccLock();
    
}

// This function writes the date to the RTCC
void rtccWriteDate(uint8_t month, uint8_t day, uint16_t year) {
 
    // configure RTCC for writing
    rtccUnlock();
    
    // Turn off RTCC
    RTCCONbits.ON = 0;
    
    // wait for RTCC to turn off
    while (RTCCONbits.RTCCLKON);
    
    // Set month
    RTCDATEbits.MONTH10 = (month / 10) % 10;
    RTCDATEbits.MONTH01 = month % 10;
    
    // Set day
    RTCDATEbits.DAY10 = (day / 10) % 10;
    RTCDATEbits.DAY01 = day % 10;
    
    // Set year
    year -= 2000;
    RTCDATEbits.YEAR10 = (year / 10) % 10;
    RTCDATEbits.YEAR01 = year % 10;
    
    // Turn on RTCC
    RTCCONbits.ON = 1;
    
    // wait for RTCC to turn on
    while (RTCCONbits.RTCCLKON == 0);
    
    // lock RTCC
    rtccLock();
    
}

// This function writes the time to the RTCC
void rtccWriteTime(uint8_t hour, uint8_t minute, uint8_t second) {
    
    // configure RTCC for writing
    rtccUnlock();
    
    // Turn off RTCC
    RTCCONbits.ON = 0;
    
    // wait for RTCC to turn off
    while (RTCCONbits.RTCCLKON);
    
    // Set month
    RTCTIMEbits.HR10 = (hour / 10) % 10;
    RTCTIMEbits.HR01 = hour % 10;
    
    // Set day
    RTCTIMEbits.MIN10 = (minute / 10) % 10;
    RTCTIMEbits.MIN01 = minute % 10;
    
    // Set year
    RTCTIMEbits.SEC10 = (second / 10) % 10;
    RTCTIMEbits.SEC01 = second % 10;
    
    // Turn on RTCC
    RTCCONbits.ON = 1;
    
    // wait for RTCC to turn on
    while (RTCCONbits.RTCCLKON == 0);
    
    // lock RTCC
    rtccLock();
    
}

// This function writes weekday to the RTCC
void rtccWriteWeekday(weekday_t weekday) {
 
    // configure RTCC for writing
    rtccUnlock();
    
    // Turn off RTCC
    RTCCONbits.ON = 0;
    
    // wait for RTCC to turn off
    while (RTCCONbits.RTCCLKON);
    
    // Set weekday
    RTCDATEbits.WDAY01 = weekday;
    
    // Turn on RTCC
    RTCCONbits.ON = 1;
    
    // wait for RTCC to turn on
    while (RTCCONbits.RTCCLKON == 0);
    
    // lock RTCC
    rtccLock();
    
    
}



// This function returns a string of the day of the week, given the RTCC value encoding this
char * getDayOfWeek(uint8_t day_of_week_enum) {

    switch (day_of_week_enum) {
    
        case 0:
            return "Sunday";
            break;
            
        case 1:
            return "Monday";
            break;
            
        case 2:
            return "Tuesday";
            break;
            
        case 3:
            return "Wednesday";
            break;
            
        case 4:
            return "Thursday";
            break;
            
        case 5:
            return "Friday";
            break;
            
        case 6:
            return "Saturday";
            break;
            
        default:
            return "error";
            break;
        
    }
    
}

// This function prints the current time and date to stdout
void printTimeAndDate(void) {
    
    printf("Time: %u:%u:%u    ",
            rtcc_shadow.hours,
            rtcc_shadow.minutes,
            rtcc_shadow.seconds);
    
    printf("Date: %s, %u/%u/%u\r\n",
            getDayOfWeek(rtcc_shadow.weekday),
            rtcc_shadow.month,
            rtcc_shadow.day,
            rtcc_shadow.year
            );
    
}

// Real Time Clock-Calendar interrupt service routine
void __ISR(_RTCC_VECTOR, ipl2SRS) rtccISR(void) {
 
    // Wait for sync to go low, signifying we can do an RTCC read
    while (RTCCONbits.RTCSYNC == 1);
    
    // Copy values from RTCC into ram shadow register
    rtcc_shadow.weekday = RTCDATEbits.WDAY01;
    rtcc_shadow.day     = (RTCDATEbits.DAY10 * 10) + RTCDATEbits.DAY01;
    rtcc_shadow.month   = (RTCDATEbits.MONTH10 * 10) + RTCDATEbits.MONTH01;
    rtcc_shadow.year    = (RTCDATEbits.YEAR10 * 10) + RTCDATEbits.YEAR01 + 2000;
    rtcc_shadow.hours   = (RTCTIMEbits.HR10 * 10) + RTCTIMEbits.HR01;
    rtcc_shadow.minutes = (RTCTIMEbits.MIN10 * 10) + RTCTIMEbits.MIN01;
    rtcc_shadow.seconds = (RTCTIMEbits.SEC10 * 10) + RTCTIMEbits.SEC01;
    
    // Clear IRQ flag
    clearInterruptFlag(Real_Time_Clock);
    
}