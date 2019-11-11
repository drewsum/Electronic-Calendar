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

// PORTED FROM 8 BIT WORLD

#ifndef _TEMP_I2C_H    /* Guard against multiple inclusion */
#define _TEMP_I2C_H


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <xc.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>


/**
 Section: Data Type Definitions
*/

/**
  I2C Driver Message Status Type Enumeration
  @Summary
    Defines the different message status when processing
    TRBs.
  @Description
    This type enumeration specifies the different types of status
    that an i2c request will have. For every submission of an i2c
    transaction, the status of that transaction is available.
    Based on the status, new transactions can be requested to the
    driver or a recovery can be performed to resend the transaction.
 */

typedef enum
{
    TEMP_I2C_MESSAGE_COMPLETE,
    TEMP_I2C_MESSAGE_FAIL,
    TEMP_I2C_MESSAGE_PENDING,
    TEMP_I2C_STUCK_START,
    TEMP_I2C_MESSAGE_ADDRESS_NO_ACK,
    TEMP_I2C_DATA_NO_ACK,
    TEMP_I2C_LOST_STATE
} TEMP_I2C_MESSAGE_STATUS;

TEMP_I2C_MESSAGE_STATUS I2C_STATUS;

/**
  I2C Driver Transaction Request Block (TRB) type definition.
  @Summary
    This defines the Transaction Request Block (TRB) used by the
    i2c master in sending/receiving data to the i2c bus.
  @Description
    This data type is the i2c Transaction Request Block (TRB) that
    the needs to be built and sent to the driver to handle each i2c requests.
    Using the TRB, simple to complex i2c transactions can be constructed
    and sent to the i2c bus. This data type is only used by the master mode.
 */
typedef struct
{
    uint16_t  address;          // Bits <10:1> are the 10 bit address.
                                // Bits <7:1> are the 7 bit address
                                // Bit 0 is R/W (1 for read)
    uint8_t   length;           // the # of bytes in the buffer
    uint8_t   *pbuffer;         // a pointer to a buffer of length bytes
} TEMP_I2C_TRANSACTION_REQUEST_BLOCK;
        
/**
  Section: Interface Routines
*/
/**
  @Summary
    Initializes the MSSP instance : 2
  @Description
    This routine initializes the i2c2 driver instance for : 2
    index, making it ready for clients to open and use it.
    This routine must be called before any other TEMP_I2C routine is called.
    This routine should only be called once during system initialization.
  @Preconditions
    None.
  @Param
    None.
  @Returns
    None.
  @Example
    <code>
        #define SLAVE_I2C_GENERIC_RETRY_MAX     100
 
        // initialize the module
        TEMP_I2C_Initialize();
        // write to an EEPROM Device
        
        uint16_t        dataAddress;
        uint8_t         sourceData[16] = {  0xA0, 0xA1, 0xA2, 0xA3, 
                                            0xA4, 0xA5, 0xA6, 0xA7, 
                                            0xA8, 0xA9, 0xAA, 0xAB, 
                                            0xAC, 0xAD, 0xAE, 0xAF }; 
        uint8_t         *pData;
        uint16_t        nCount;
        uint8_t         writeBuffer[3];
        uint8_t         *pD;
        uint16_t        counter, timeOut;
        TEMP_I2C_MESSAGE_STATUS status = TEMP_I2C_MESSAGE_PENDING;
        dataAddress = 0x10;             // starting EEPROM address 
        pD = sourceData;                // initialize the source of the data
        nCount = 16;                    // number of bytes to write
        for (counter = 0; counter < nCount; counter++)
        {
            // build the write buffer first
            // starting address of the EEPROM memory
            writeBuffer[0] = (dataAddress >> 8);                // high address
            writeBuffer[1] = (uint8_t)(dataAddress);            // low low address
            // data to be written
            writeBuffer[2] = *pD++;
            // Now it is possible that the slave device will be slow.
            // As a work around on these slaves, the application can
            // retry sending the transaction
            timeOut = 0;
            while(status != TEMP_I2C_MESSAGE_FAIL)
            {
                // write one byte to EEPROM (3 is the number of bytes to write)
                TEMP_I2C_MasterWrite(  writeBuffer,
                                        3,
                                        slaveDeviceAddress,
                                        &status);
                // wait for the message to be sent or status has changed.
                while(status == TEMP_I2C_MESSAGE_PENDING);
                if (status == TEMP_I2C_MESSAGE_COMPLETE)
                    break;
                // if status is  TEMP_I2C_MESSAGE_ADDRESS_NO_ACK,
                //               or TEMP_I2C_DATA_NO_ACK,
                // The device may be busy and needs more time for the last
                // write so we can retry writing the data, this is why we
                // use a while loop here
                // check for max retry and skip this byte
                if (timeOut == SLAVE_I2C_GENERIC_RETRY_MAX)
                    break;
                else
                    timeOut++;
            }
            if (status == TEMP_I2C_MESSAGE_FAIL)
            {
                break;
            }
            dataAddress++;
        }
    </code>
*/
        
void TEMP_I2C_Initialize(void);

/**
    @Summary
        Handles one i2c master write transaction with the
        supplied parameters.
    @Description
        This function prepares a TRB, then inserts it on the i2c queue.
        Finally, it waits for the transaction to complete and returns
        the result.
    @Preconditions
        None
    @Param
        address - The address of the i2c peripheral to be accessed
    @Param
        length - The length of the data block to be sent
    
    @Param
        *pdata - A pointer to the block of data to be sent
    
    @Param
        *pstatus - A pointer to the status variable that the i2c driver
            updates during the execution of the message.
    @Returns
        TEMP_I2C_MESSAGE_STATUS
     @Example
        <code>
            Refer to TEMP_I2C_Initialize() and 
            TEMP_I2C_MasterRead() for an examples	
        </code>
*/

void TEMP_I2C_MasterWrite(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                TEMP_I2C_MESSAGE_STATUS *pstatus);

/**
    @Summary
        Handles one i2c master read transaction with the
        supplied parameters.
    @Description
        This function prepares a TRB, then inserts it on the i2c queue.
        Finally, it waits for the transaction to complete and returns
        the result.
    @Preconditions
        None
    @Param
        address - The address of the i2c peripheral to be accessed
    
    @Param
        length - The length of the data block to be sent
    
    @Param
        *pdata - A pointer to the memory location where received data will
                 be stored
    @Param
        *pstatus - A pointer to the status variable that the i2c driver
            updates during the execution of the message.
    @Returns
        TEMP_I2C_MESSAGE_STATUS
    @Example
        <code>
 
            #define MCHP24AA512_RETRY_MAX  100  // define the retry count
            #define MCHP24AA512_ADDRESS    0x50 // slave device address
            uint8_t MCHP24AA512_Read(
                                            uint16_t address,
                                            uint8_t *pData,
                                            uint16_t nCount)
            {
                TEMP_I2C_MESSAGE_STATUS status;
                uint8_t     writeBuffer[3];
                uint16_t    timeOut;
                uint16_t    counter;
                uint8_t     *pD, ret;
                pD = pData;
                for (counter = 0; counter < nCount; counter++)
                {
                    // build the write buffer first
                    // starting address of the EEPROM memory
                    writeBuffer[0] = (address >> 8);                // high address
                    writeBuffer[1] = (uint8_t)(address);            // low low address
                    // Now it is possible that the slave device will be slow.
                    // As a work around on these slaves, the application can
                    // retry sending the transaction
                    timeOut = 0;
                    while(status != TEMP_I2C_MESSAGE_FAIL)
                    {
                        // write one byte to EEPROM (2 is the count of bytes to write)
                        TEMP_I2C_MasterWrite(   writeBuffer,
                                                2,
                                                MCHP24AA512_ADDRESS,
                                                &status);
                        // wait for the message to be sent or status has changed.
                        while(status == TEMP_I2C_MESSAGE_PENDING);
                        if (status == TEMP_I2C_MESSAGE_COMPLETE)
                            break;
                        // if status is  TEMP_I2C_MESSAGE_ADDRESS_NO_ACK,
                        //               or TEMP_I2C_DATA_NO_ACK,
                        // The device may be busy and needs more time for the last
                        // write so we can retry writing the data, this is why we
                        // use a while loop here
                        // check for max retry and skip this byte
                        if (timeOut == MCHP24AA512_RETRY_MAX)
                            break;
                        else
                            timeOut++;
                    }
                    if (status == TEMP_I2C_MESSAGE_COMPLETE)
                    {
                        // this portion will read the byte from the memory location.
                        timeOut = 0;
                        while(status != TEMP_I2C_MESSAGE_FAIL)
                        {
                            // write one byte to EEPROM (2 is the count of bytes to write)
                            TEMP_I2C_MasterRead(    pD,
                                                    1,
                                                    MCHP24AA512_ADDRESS,
                                                    &status);
                            // wait for the message to be sent or status has changed.
                            while(status == TEMP_I2C_MESSAGE_PENDING);
                            if (status == TEMP_I2C_MESSAGE_COMPLETE)
                                break;
                            // if status is  TEMP_I2C_MESSAGE_ADDRESS_NO_ACK,
                            //               or TEMP_I2C_DATA_NO_ACK,
                            // The device may be busy and needs more time for the last
                            // write so we can retry writing the data, this is why we
                            // use a while loop here
                            // check for max retry and skip this byte
                            if (timeOut == MCHP24AA512_RETRY_MAX)
                                break;
                            else
                                timeOut++;
                        }
                    }
                    // exit if the last transaction failed
                    if (status == TEMP_I2C_MESSAGE_FAIL)
                    {
                        ret = 0;
                        break;
                    }
                    pD++;
                    address++;
                }
                return (ret);
            }
   
  
        </code>
*/

void TEMP_I2C_MasterRead(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                TEMP_I2C_MESSAGE_STATUS *pstatus);

/**
    @Summary
        Inserts a list of i2c transaction requests into the i2c
        transaction queue.
    @Description
        The i2c processes lists of transaction requests.  Each transaction
        list is handled as a string of i2c restarts.  When the list of
        transactions is complete, an i2c stop is produced, the flag is set
        with the correct condition code and the next list is processed
        from the queue.
        This function inserts lists of requests prepared by the user
        application into the queue along with a pointer to the completion
        flag.
        The transaction is inserted into the list only if there is space
        in the list. If there is no space, the function exits with the
        flag set to TEMP_I2C_MESSAGE_FAIL.
    @Preconditions
        None
    @Param
        count - The numer of transaction requests in the trb_list.
    @Param
        *ptrb_list - A pointer to an array of transaction requests (TRB).
            See TEMP_I2C_TRANSACTION_REQUEST_BLOCK definition for details.
    
    @Param
        *pflag - A pointer to a completion flag.
    @Returns
        None
    @Example
        <code>
  
            void EMULATED_EEPROM_Read(
                                           uint16_t slaveDeviceAddress,
                                           uint16_t dataAddress,
                                           uint8_t *pData,
                                           uint16_t nCount)
            {
                TEMP_I2C_MESSAGE_STATUS status;
                TEMP_I2C_TRANSACTION_REQUEST_BLOCK readTRB[2];
                uint8_t     writeBuffer[3];
                uint16_t    timeOut;
                // this initial value is important
                status = TEMP_I2C_MESSAGE_PENDING;
                // build the write buffer first
                // starting address of the EEPROM memory
                writeBuffer[0] = (dataAddress >> 8);                        // high address
                writeBuffer[1] = (uint8_t)(dataAddress);                    // low low address
                // we need to create the TRBs for a random read sequence to the EEPROM
                // Build TRB for sending address
                TEMP_I2C_MasterWriteTRBBuild(   &readTRB[0],
                                                writeBuffer,
                                                2,
                                                slaveDeviceAddress);
                // Build TRB for receiving data
                TEMP_I2C_MasterReadTRBBuild(    &readTRB[1],
                                                pData,
                                                nCount,
                                                slaveDeviceAddress);
                timeOut = 0;
                while(status != TEMP_I2C_MESSAGE_FAIL)
                {
                    // now send the transactions
                    TEMP_I2C_MasterTRBInsert(2, readTRB, &status);
                    // wait for the message to be sent or status has changed.
                    while(status == TEMP_I2C_MESSAGE_PENDING);
                    if (status == TEMP_I2C_MESSAGE_COMPLETE)
                        break;
                    // if status is  TEMP_I2C_MESSAGE_ADDRESS_NO_ACK,
                    //               or TEMP_I2C_DATA_NO_ACK,
                    // The device may be busy and needs more time for the last
                    // write so we can retry writing the data, this is why we
                    // use a while loop here
                    // check for max retry and skip this byte
                    if (timeOut == SLAVE_I2C_GENERIC_RETRY_MAX)
                        break;
                    else
                        timeOut++;
                }
            }   
  
        </code>
*/

void TEMP_I2C_MasterTRBInsert(
                                uint8_t count,
                                TEMP_I2C_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                                TEMP_I2C_MESSAGE_STATUS *pflag);

/**
    @Summary
        This function populates a trb supplied by the calling function
        with the parameters supplied by the calling function.
    @Description
        All i2c requests are in the form of TRB's. This helper function
        takes standard parameters and correctly formats the TRB. The R/W
        bit is set to ensure that the resulting TRB describes an i2c read
        operation.
        This function does not send the transaction. To send the transaction,
        the TRB insert function (TEMP_I2C_MasterTRBInsert()) must be called.
    @Preconditions
        None
    @Param
        *ptrb - A pointer to a caller supplied TRB.
    @Param
        *pdata - A pointer to the block of data to be received
    @Param
        length - The length of the data block to be received
    @Param
        address - The address of the i2c peripheral to be accessed
    @Returns
        None
    @Example
        <code>
            Refer to TEMP_I2C_MasterTRBInsert() for an example	
        </code>
*/

void TEMP_I2C_MasterReadTRBBuild(
                                TEMP_I2C_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address);

/**
    @Summary
        This function populates a trb supplied by the calling function
        with the parameters supplied by the calling function.
    @Description
        All i2c requests are in the form of TRB's.  This helper function
        takes standard parameters and correctly formats the TRB. The R/W
        bit is cleared to ensure that the resulting TRB describes an i2c
        write operation.
        This function does not send the transaction. To send the transaction,
        the TRB insert function (TEMP_I2C_MasterTRBInsert()) must be called.
    @Preconditions
        None
    @Param
        *ptrb - A pointer to a caller supplied TRB.
    @Param
        *pdata - A pointer to the block of data to be sent
    @Param
        length - The length of the data block to be sent
    @Param
        address - The address of the i2c peripheral to be accessed
    @Returns
        None
    @Example
        <code>
            Refer to TEMP_I2C_MasterTRBInsert() for an example	
        </code>
*/

void TEMP_I2C_MasterWriteTRBBuild(
                                TEMP_I2C_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address);

/**
    @Summary
        This function returns the empty status of the Master
        queue.
    @Description
        This function returns the empty status of the Master
        queue. Use this function to check if the queue is empty.
        This can verify if the Master is currently idle.
    @Preconditions
        None
    @Param
        None
    @Returns
        True if the queue is empty and false if the queue is not empty.
    @Example
        <code>
            #define MCHP24AA512_ADDRESS    0x50 // slave device address
            // check until queue is empty
            while(TEMP_I2C_MasterQueueIsEmpty() == false);
            
            // now send more data (assume readBuffer is initialized)
            TEMP_I2C_MasterRead(   readBuffer,
                                    3,
                                    MCHP24AA512_ADDRESS,
                                    &status);   
  
        </code>
*/

bool TEMP_I2C_MasterQueueIsEmpty(void);

/**
    @Summary
        This function returns the full status of the Master
        queue.
    @Description
        This function returns the full status of the Master
        queue. Use this function to check if the queue is full.
        This can verify if the Master will not be able to accept
        addition transactions.
    @Preconditions
        None
    @Param
        None
    @Returns
        True if the queue is full and false if the queue is not full.
    @Example
        <code>
            #define MCHP24AA512_ADDRESS    0x50 // slave device address
 
            // check until queue has space
            while(TEMP_I2C_MasterQueueIsFull() == true);
            
            // now send more data (assume readBuffer is initialized)
            TEMP_I2C_MasterRead(   readBuffer,
                                    3,
                                    MCHP24AA512_ADDRESS,
                                    &status); 
        </code>
*/

bool TEMP_I2C_MasterQueueIsFull(void);

void __ISR(_I2C1_BUS_VECTOR, IPL5SRS) TEMP_I2C_BusCollisionISR( void );
void __ISR(_I2C1_MASTER_VECTOR, IPL4SRS) TEMP_I2C_MASTER_ISR ( void );

// this function returns if the temp I2C peripheral is currently turned on
uint8_t getTempI2COnState(void);

// this function resets Temp I2C on state, a workaround for errata
void tempI2COnStateReset(void);

#endif /* _TEMP_I2C_H */

/* *****************************************************************************
 End of File
 */
