
#include "temp_i2c.h"

#include "32mz_interrupt_control.h"
#include "error_handler.h"

/**
  I2C Driver Queue Status Type
  @Summary
    Defines the type used for the transaction queue status.
  @Description
    This defines type used to keep track of the queue status.
 */

typedef union
{
    struct
    {
            uint8_t full:1;
            uint8_t empty:1;
            uint8_t reserved:6;
    }s;
    uint8_t status;
}I2C_TR_QUEUE_STATUS;

/**
  I2C Driver Queue Entry Type
  @Summary
    Defines the object used for an entry in the i2c queue items.
  @Description
    This defines the object in the i2c queue. Each entry is a composed
    of a list of TRBs, the number of the TRBs and the status of the
    currently processed TRB.
 */
typedef struct
{
    uint8_t                             count;          // a count of trb's in the trb list
    TEMP_I2C_TRANSACTION_REQUEST_BLOCK *ptrb_list;     // pointer to the trb list
    TEMP_I2C_MESSAGE_STATUS            *pTrFlag;       // set with the error of the last trb sent.
                                                        // if all trb's are sent successfully,
                                                        // then this is TEMP_I2C_MESSAGE_COMPLETE
} I2C_TR_QUEUE_ENTRY;

/**
  I2C Master Driver Object Type
  @Summary
    Defines the object that manages the i2c master.
  @Description
    This defines the object that manages the sending and receiving of
    i2c master transactions.
  */

typedef struct
{
    /* Read/Write Queue */
    I2C_TR_QUEUE_ENTRY          *pTrTail;       // tail of the queue
    I2C_TR_QUEUE_ENTRY          *pTrHead;       // head of the queue
    I2C_TR_QUEUE_STATUS         trStatus;       // status of the last transaction
    uint8_t                         i2cDoneFlag;    // flag to indicate the current
                                                    // transaction is done
    uint8_t                         i2cErrors;      // keeps track of errors


} I2C_OBJECT ;

/**
  I2C Master Driver State Enumeration
  @Summary
    Defines the different states of the i2c master.
  @Description
    This defines the different states that the i2c master
    used to process transactions on the i2c bus.
*/

typedef enum
{
    S_MASTER_IDLE,
    S_MASTER_RESTART,
    S_MASTER_SEND_ADDR,
    S_MASTER_SEND_DATA,
    S_MASTER_SEND_STOP,
    S_MASTER_ACK_ADDR,
    S_MASTER_RCV_DATA,
    S_MASTER_RCV_STOP,
    S_MASTER_ACK_RCV_DATA,
    S_MASTER_NOACK_STOP,
    S_MASTER_SEND_ADDR_10BIT_LSB,
    S_MASTER_10BIT_RESTART,
    
} I2C_MASTER_STATES;

/**
 Section: Macro Definitions
*/

/* defined for TEMP_I2C */

#ifndef TEMP_I2C_CONFIG_TR_QUEUE_LENGTH
        #define TEMP_I2C_CONFIG_TR_QUEUE_LENGTH 1
#endif


#define TEMP_I2C_TRANSMIT_REG                       I2C1TRN                 // Defines the transmit register used to send data.
#define TEMP_I2C_RECEIVE_REG                        I2C1RCV                 // Defines the receive register used to receive data.

// The following control bits are used in the I2C state machine to manage
// the I2C module and determine next states.
#define TEMP_I2C_WRITE_COLLISION_STATUS_BIT         I2C1STATbits.IWCOL     // Defines the write collision status bit.
// #define TEMP_I2C_MODE_SELECT_BITS                   SSP2CON1bits.SSPM     // I2C Master Mode control bit.
//#define TEMP_I2C_MASTER_ENABLE_CONTROL_BITS         SSP2CON1bits.SSPEN    // I2C port enable control bit.

#define TEMP_I2C_START_CONDITION_ENABLE_BIT         I2C1CONbits.SEN      // I2C START control bit.
#define TEMP_I2C_REPEAT_START_CONDITION_ENABLE_BIT  I2C1CONbits.RSEN     // I2C Repeated START control bit.
#define TEMP_I2C_RECEIVE_ENABLE_BIT                 I2C1CONbits.RCEN     // I2C Receive enable control bit.
#define TEMP_I2C_STOP_CONDITION_ENABLE_BIT          I2C1CONbits.PEN      // I2C STOP control bit.
#define TEMP_I2C_ACKNOWLEDGE_ENABLE_BIT             I2C1CONbits.ACKEN    // I2C ACK start control bit.
#define TEMP_I2C_ACKNOWLEDGE_DATA_BIT               I2C1CONbits.ACKDT    // I2C ACK data control bit.
#define TEMP_I2C_ACKNOWLEDGE_STATUS_BIT             I2C1STATbits.ACKSTAT  // I2C ACK status bit.


#define TEMP_I2C_7bit    true

 /**
 Section: Local Functions
*/

void TEMP_I2C_FunctionComplete(void);
void TEMP_I2C_Stop(TEMP_I2C_MESSAGE_STATUS completion_code);

/**
 Section: Local Variables
*/

static I2C_TR_QUEUE_ENTRY                  temp_i2c_tr_queue[TEMP_I2C_CONFIG_TR_QUEUE_LENGTH];
static I2C_OBJECT                          temp_i2c_object;
static I2C_MASTER_STATES                   temp_i2c_state = S_MASTER_IDLE;
static uint8_t                             temp_i2c_trb_count = 0;

static TEMP_I2C_TRANSACTION_REQUEST_BLOCK      *p_temp_i2c_trb_current = NULL;
static volatile I2C_TR_QUEUE_ENTRY         *p_temp_i2c_current = NULL;


/**
  Section: Driver Interface
*/

void TEMP_I2C_Initialize(void)
{
    temp_i2c_object.pTrHead = temp_i2c_tr_queue;
    temp_i2c_object.pTrTail = temp_i2c_tr_queue;
    temp_i2c_object.trStatus.s.empty = true;
    temp_i2c_object.trStatus.s.full = false;

    temp_i2c_object.i2cErrors = 0;

    disableInterrupt(I2C1_Master_Event);
    setInterruptPriority(I2C1_Master_Event, 4);
    setInterruptSubpriority(I2C1_Master_Event, 0);
    
    disableInterrupt(I2C1_Bus_Collision_Event);
    setInterruptPriority(I2C1_Bus_Collision_Event, 4);
    setInterruptSubpriority(I2C1_Bus_Collision_Event, 1);
    
    // setup I2C1 CON register
    //I2C1CONbits.PCIE = 0;       // disable stop condition interrupt (slave mode only)
    //I2C1CONbits.SCIE = 0;       // disable start condition interrupt (slave mode only)
    //I2C1CONbits.BOEN = 0;       // disable buffer overwrite interrupt (slave mode only)
    I2C1CONbits.SDAHT = 0;      // 100 ns hold time after falling edge of SCL
    //I2C1CONbits.SBCDE = 0;      // disable slave bus collision interrupt
    I2C1CONbits.SIDL = 1;       // disable in IDLE mode
    I2C1CONbits.DISSLW = 0;     // enable slew rate control
    I2C1CONbits.SMEN = 0;       // disable SMBus threshold levels
    
    // setup I2C clocking
    // clock source is PBCLK2
    I2C1BRG = 0x0021;
    
    // clear the interrupt flags
    clearInterruptFlag(I2C1_Bus_Collision_Event);
    clearInterruptFlag(I2C1_Master_Event);
	
    // enable the interrupts
    enableInterrupt(I2C1_Master_Event);
    enableInterrupt(I2C1_Bus_Collision_Event);
    
    // enable I2C1 module
    I2C1CONbits.ON = 1;
    
}

        
uint8_t TEMP_I2C_ErrorCountGet(void)
{
    uint8_t ret;

    ret = temp_i2c_object.i2cErrors;
    return ret;
}

void __ISR(_I2C1_MASTER_VECTOR, IPL4SRS) TEMP_I2C_MASTER_ISR ( void )
{
  
    static uint8_t  *pi2c_buf_ptr;
    static uint16_t i2c_address         = 0;
    static uint8_t  i2c_bytes_left      = 0;
    static uint8_t  i2c_10bit_address_restart = 0;

    clearInterruptFlag(I2C1_Master_Event);
    
    // Check first if there was a collision.
    // If we have a Write Collision, reset and go to idle state */
    if(TEMP_I2C_WRITE_COLLISION_STATUS_BIT)
    {
        // clear the Write colision
        TEMP_I2C_WRITE_COLLISION_STATUS_BIT = 0;
        temp_i2c_state = S_MASTER_IDLE;
        *(p_temp_i2c_current->pTrFlag) = TEMP_I2C_MESSAGE_FAIL;

        // reset the buffer pointer
        p_temp_i2c_current = NULL;

        return;
    }

    /* Handle the correct i2c state */
    switch(temp_i2c_state)
    {
        case S_MASTER_IDLE:    /* In reset state, waiting for data to send */

            if(temp_i2c_object.trStatus.s.empty != true)
            {
                // grab the item pointed by the head
                p_temp_i2c_current     = temp_i2c_object.pTrHead;
                temp_i2c_trb_count     = temp_i2c_object.pTrHead->count;
                p_temp_i2c_trb_current = temp_i2c_object.pTrHead->ptrb_list;

                temp_i2c_object.pTrHead++;

                // check if the end of the array is reached
                if(temp_i2c_object.pTrHead == (temp_i2c_tr_queue + TEMP_I2C_CONFIG_TR_QUEUE_LENGTH))
                {
                    // adjust to restart at the beginning of the array
                    temp_i2c_object.pTrHead = temp_i2c_tr_queue;
                }

                // since we moved one item to be processed, we know
                // it is not full, so set the full status to false
                temp_i2c_object.trStatus.s.full = false;

                // check if the queue is empty
                if(temp_i2c_object.pTrHead == temp_i2c_object.pTrTail)
                {
                    // it is empty so set the empty status to true
                    temp_i2c_object.trStatus.s.empty = true;
                }

                // send the start condition
                TEMP_I2C_START_CONDITION_ENABLE_BIT = 1;
                
                // start the i2c request
                temp_i2c_state = S_MASTER_SEND_ADDR;
            }

            break;

        case S_MASTER_RESTART:

            /* check for pending i2c Request */

            // ... trigger a REPEATED START
            TEMP_I2C_REPEAT_START_CONDITION_ENABLE_BIT = 1;

            // start the i2c request
            temp_i2c_state = S_MASTER_SEND_ADDR;

            break;

        case S_MASTER_SEND_ADDR_10BIT_LSB:

            if(TEMP_I2C_ACKNOWLEDGE_STATUS_BIT)
            {
                temp_i2c_object.i2cErrors++;
                TEMP_I2C_Stop(TEMP_I2C_MESSAGE_ADDRESS_NO_ACK);
            }
            else
            {
                // Remove bit 0 as R/W is never sent here
                TEMP_I2C_TRANSMIT_REG = (i2c_address >> 1) & 0x00FF;

                // determine the next state, check R/W
                if(i2c_address & 0x01)
                {
                    // if this is a read we must repeat start
                    // the bus to perform a read
                    temp_i2c_state = S_MASTER_10BIT_RESTART;
                }
                else
                {
                    // this is a write continue writing data
                    temp_i2c_state = S_MASTER_SEND_DATA;
                }
            }

            break;

        case S_MASTER_10BIT_RESTART:

            if(TEMP_I2C_ACKNOWLEDGE_STATUS_BIT)
            {
                temp_i2c_object.i2cErrors++;
                TEMP_I2C_Stop(TEMP_I2C_MESSAGE_ADDRESS_NO_ACK);
            }
            else
            {
                // ACK Status is good
                // restart the bus
                TEMP_I2C_REPEAT_START_CONDITION_ENABLE_BIT = 1;

                // fudge the address so S_MASTER_SEND_ADDR works correctly
                // we only do this on a 10-bit address resend
                i2c_address = 0x00F0 | ((i2c_address >> 8) & 0x0006);

                // set the R/W flag
                i2c_address |= 0x0001;

                // set the address restart flag so we do not change the address
                i2c_10bit_address_restart = 1;

                // Resend the address as a read
                temp_i2c_state = S_MASTER_SEND_ADDR;
            }

            break;

        case S_MASTER_SEND_ADDR:

            /* Start has been sent, send the address byte */

            /* Note: 
                On a 10-bit address resend (done only during a 10-bit
                device read), the original i2c_address was modified in
                S_MASTER_10BIT_RESTART state. So the check if this is
                a 10-bit address will fail and a normal 7-bit address
                is sent with the R/W bit set to read. The flag
                i2c_10bit_address_restart prevents the  address to
                be re-written.
             */
            if(i2c_10bit_address_restart != 1)
            {
                // extract the information for this message
                i2c_address    = p_temp_i2c_trb_current->address;
                pi2c_buf_ptr   = p_temp_i2c_trb_current->pbuffer;
                i2c_bytes_left = p_temp_i2c_trb_current->length;
            }

            // check for 10-bit address
            if(!TEMP_I2C_7bit && (0x0 != i2c_address))
            {  
                if (0 == i2c_10bit_address_restart)
                {
                    // we have a 10 bit address
                    // send bits<9:8>
                    // mask bit 0 as this is always a write                    
                    TEMP_I2C_TRANSMIT_REG = 0xF0 | ((i2c_address >> 8) & 0x0006);
                    temp_i2c_state = S_MASTER_SEND_ADDR_10BIT_LSB;
                }
                else
                {
                    // resending address bits<9:8> to trigger read
                    TEMP_I2C_TRANSMIT_REG = i2c_address;
                    temp_i2c_state = S_MASTER_ACK_ADDR;
                    // reset the flag so the next access is ok
                    i2c_10bit_address_restart = 0;
                }
            }
            else
            {
                // Transmit the address
                TEMP_I2C_TRANSMIT_REG = i2c_address;
                if(i2c_address & 0x01)
                {
                    // Next state is to wait for address to be acked
                    temp_i2c_state = S_MASTER_ACK_ADDR;
                }
                else
                {
                    // Next state is transmit
                    temp_i2c_state = S_MASTER_SEND_DATA;
                }
            }
            break;

        case S_MASTER_SEND_DATA:

            // Make sure the previous byte was acknowledged
            if(TEMP_I2C_ACKNOWLEDGE_STATUS_BIT)
            {
                // Transmission was not acknowledged
                temp_i2c_object.i2cErrors++;

                // Reset the Ack flag
                TEMP_I2C_ACKNOWLEDGE_STATUS_BIT = 0;

                // Send a stop flag and go back to idle
                TEMP_I2C_Stop(TEMP_I2C_DATA_NO_ACK);

            }
            else
            {
                // Did we send them all ?
                if(i2c_bytes_left-- == 0U)
                {
                    // yup sent them all!

                    // update the trb pointer
                    p_temp_i2c_trb_current++;

                    // are we done with this string of requests?
                    if(--temp_i2c_trb_count == 0)
                    {
                        TEMP_I2C_Stop(TEMP_I2C_MESSAGE_COMPLETE);
                    }
                    else
                    {
                        // no!, there are more TRB to be sent.
                        //TEMP_I2C_START_CONDITION_ENABLE_BIT = 1;

                        // In some cases, the slave may require
                        // a restart instead of a start. So use this one
                        // instead.
                        TEMP_I2C_REPEAT_START_CONDITION_ENABLE_BIT = 1;

                        // start the i2c request
                        temp_i2c_state = S_MASTER_SEND_ADDR;

                    }
                }
                else
                {
                    // Grab the next data to transmit
                    TEMP_I2C_TRANSMIT_REG = *pi2c_buf_ptr++;
                }
            }
            break;

        case S_MASTER_ACK_ADDR:

            /* Make sure the previous byte was acknowledged */
            if(TEMP_I2C_ACKNOWLEDGE_STATUS_BIT)
            {

                // Transmission was not acknowledged
                temp_i2c_object.i2cErrors++;

                // Send a stop flag and go back to idle
                TEMP_I2C_Stop(TEMP_I2C_MESSAGE_ADDRESS_NO_ACK);

                // Reset the Ack flag
                TEMP_I2C_ACKNOWLEDGE_STATUS_BIT = 0;
            }
            else
            {
                TEMP_I2C_RECEIVE_ENABLE_BIT = 1;
                temp_i2c_state = S_MASTER_ACK_RCV_DATA;
            }
            break;

        case S_MASTER_RCV_DATA:

            /* Acknowledge is completed.  Time for more data */

            // Next thing is to ack the data
            temp_i2c_state = S_MASTER_ACK_RCV_DATA;

            // Set up to receive a byte of data
            TEMP_I2C_RECEIVE_ENABLE_BIT = 1;

            break;

        case S_MASTER_ACK_RCV_DATA:

            // Grab the byte of data received and acknowledge it
            *pi2c_buf_ptr++ = TEMP_I2C_RECEIVE_REG;

            // Check if we received them all?
            if(--i2c_bytes_left)
            {

                /* No, there's more to receive */

                // No, bit 7 is clear.  Data is ok
                // Set the flag to acknowledge the data
                TEMP_I2C_ACKNOWLEDGE_DATA_BIT = 0;

                // Wait for the acknowledge to complete, then get more
                temp_i2c_state = S_MASTER_RCV_DATA;
            }
            else
            {

                // Yes, it's the last byte.  Don't ack it
                // Flag that we will nak the data
                TEMP_I2C_ACKNOWLEDGE_DATA_BIT = 1;

                TEMP_I2C_FunctionComplete();
            }

            // Initiate the acknowledge
            TEMP_I2C_ACKNOWLEDGE_ENABLE_BIT = 1;
            break;

        case S_MASTER_RCV_STOP:                
        case S_MASTER_SEND_STOP:

            // Send the stop flag
            TEMP_I2C_Stop(TEMP_I2C_MESSAGE_COMPLETE);
            break;

        default:

            // This case should not happen, if it does then
            // terminate the transfer
            temp_i2c_object.i2cErrors++;
            TEMP_I2C_Stop(TEMP_I2C_LOST_STATE);
            break;

    }
}

void TEMP_I2C_FunctionComplete(void)
{

    // update the trb pointer
    p_temp_i2c_trb_current++;

    // are we done with this string of requests?
    if(--temp_i2c_trb_count == 0)
    {
        temp_i2c_state = S_MASTER_SEND_STOP;
    }
    else
    {
        temp_i2c_state = S_MASTER_RESTART;
    }

}

void TEMP_I2C_Stop(TEMP_I2C_MESSAGE_STATUS completion_code)
{
    // then send a stop
    TEMP_I2C_STOP_CONDITION_ENABLE_BIT = 1;

    // make sure the flag pointer is not NULL
    if (p_temp_i2c_current->pTrFlag != NULL)
    {
        // update the flag with the completion code
        *(p_temp_i2c_current->pTrFlag) = completion_code;
    }

    // Done, back to idle
    temp_i2c_state = S_MASTER_IDLE;
    
}

void TEMP_I2C_MasterWrite(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                TEMP_I2C_MESSAGE_STATUS *pflag)
{
    static TEMP_I2C_TRANSACTION_REQUEST_BLOCK   trBlock;

    // check if there is space in the queue
    if (temp_i2c_object.trStatus.s.full != true)
    {
        TEMP_I2C_MasterWriteTRBBuild(&trBlock, pdata, length, address);
        TEMP_I2C_MasterTRBInsert(1, &trBlock, pflag);
    }
    else
    {
        *pflag = TEMP_I2C_MESSAGE_FAIL;
    }

}

void TEMP_I2C_MasterRead(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                TEMP_I2C_MESSAGE_STATUS *pflag)
{
    static TEMP_I2C_TRANSACTION_REQUEST_BLOCK   trBlock;


    // check if there is space in the queue
    if (temp_i2c_object.trStatus.s.full != true)
    {
        TEMP_I2C_MasterReadTRBBuild(&trBlock, pdata, length, address);
        TEMP_I2C_MasterTRBInsert(1, &trBlock, pflag);
    }
    else
    {
        *pflag = TEMP_I2C_MESSAGE_FAIL;
    }

}


inline void TEMP_I2C_WaitForLastPacketToComplete()
{
    while(temp_i2c_state != S_MASTER_IDLE)
    {
        // If your code gets stuck here it is because the last packet is never completing
        // Most likely cause is that your interrupt is not firing as it should. Check if you have
        //   correctly enabled all MSSP, Peripheral and GIE interrupt settings.
    }
}

void TEMP_I2C_MasterTRBInsert(
                                uint8_t count,
                                TEMP_I2C_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                                TEMP_I2C_MESSAGE_STATUS *pflag)
{

    // check if there is space in the queue
    if (temp_i2c_object.trStatus.s.full != true)
    {
        *pflag = TEMP_I2C_MESSAGE_PENDING;

        temp_i2c_object.pTrTail->ptrb_list = ptrb_list;
        temp_i2c_object.pTrTail->count     = count;
        temp_i2c_object.pTrTail->pTrFlag   = pflag;
        temp_i2c_object.pTrTail++;

        // check if the end of the array is reached
        if (temp_i2c_object.pTrTail == (temp_i2c_tr_queue + TEMP_I2C_CONFIG_TR_QUEUE_LENGTH))
        {
            // adjust to restart at the beginning of the array
            temp_i2c_object.pTrTail = temp_i2c_tr_queue;
        }

        // since we added one item to be processed, we know
        // it is not empty, so set the empty status to false
        temp_i2c_object.trStatus.s.empty = false;

        // check if full
        if (temp_i2c_object.pTrHead == temp_i2c_object.pTrTail)
        {
            // it is full, set the full status to true
            temp_i2c_object.trStatus.s.full = true;
        }

    }
    else
    {
        *pflag = TEMP_I2C_MESSAGE_FAIL;
    }

    // for interrupt based
    if (*pflag == TEMP_I2C_MESSAGE_PENDING)
    {
        TEMP_I2C_WaitForLastPacketToComplete();
        
        // The state machine has to be started manually because it runs only in the ISR.
        // If we called the ISR function here function duplication would double the code size
        //    because this function would be called both from interrupt and from mainline code.
        setInterruptFlag(I2C1_Master_Event, 1);

    }   // block until request is complete

}

void TEMP_I2C_MasterReadTRBBuild(
                                TEMP_I2C_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address)
{
    ptrb->address  = address << 1;
    // make this a read
    ptrb->address |= 0x01;
    ptrb->length   = length;
    ptrb->pbuffer  = pdata;
}

void TEMP_I2C_MasterWriteTRBBuild(
                                TEMP_I2C_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address)
{
    ptrb->address = address << 1;
    ptrb->length  = length;
    ptrb->pbuffer = pdata;
}

bool TEMP_I2C_MasterQueueIsEmpty(void)
{
    return(temp_i2c_object.trStatus.s.empty);
}

bool TEMP_I2C_MasterQueueIsFull(void)
{
    return(temp_i2c_object.trStatus.s.full);
}        
        
void __ISR(_I2C1_BUS_VECTOR, IPL4SRS) TEMP_I2C_BusCollisionISR( void )
{
    // enter bus collision handling code here
	clearInterruptFlag(I2C1_Bus_Collision_Event);
    error_handler.flags.temp_I2C_bus_collision = 1;
}