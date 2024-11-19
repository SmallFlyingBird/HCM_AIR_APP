/**************************************************************************************************/
/**
 * @file      : I2c_Drv_Types.h
 * @brief     : AUTOSAR I2c hardware types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef I2C_DRV_TYPES_H
#define I2C_DRV_TYPES_H

/** @addtogroup  I2c_Module
 *  @{
 */

/** @addtogroup  I2c_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "I2c_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define I2C_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define I2C_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define I2C_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define I2C_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define I2C_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define I2C_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define I2C_DRV_TYPES_H_SW_PATCH_VERSION            2U

#if (I2C_DRV_TYPES_H_VENDOR_ID != I2C_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of I2c_Drv_Types.h and I2c_Drv_Cfg.h are different"
#endif

#if ((I2C_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != I2C_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (I2C_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != I2C_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (I2C_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != I2C_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of I2c_Drv_Types.h and I2c_Drv_Cfg.h are different"
#endif

#if ((I2C_DRV_TYPES_H_SW_MAJOR_VERSION != I2C_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (I2C_DRV_TYPES_H_SW_MINOR_VERSION != I2C_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (I2C_DRV_TYPES_H_SW_PATCH_VERSION != I2C_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software version of I2c_Drv_Types.h and I2c_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((I2C_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (I2C_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of I2c_Drv_Types.h and McalLib.h are different"
    #endif

    #if ((I2C_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (I2C_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of I2c_Drv_Types.h and Std_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Define the enum of the events which can trigger I2C slave callback
 *
 */
typedef enum
{
    I2C_DRV_SLAVE_EVENT_ERROR_BIT = 0x00U,
    I2C_DRV_SLAVE_EVENT_UNDERRUN = 0x01U,
    I2C_DRV_SLAVE_EVENT_OVERRUN = 0x02U, /* no room in buffer or master transmit too fast */
    I2C_DRV_SLAVE_EVENT_RX_FULL = 0x03U,
    I2C_DRV_SLAVE_EVENT_TX_EMPTY = 0x04U,
    I2C_DRV_SLAVE_EVENT_TX_REQ = 0x05U,
    I2C_DRV_SLAVE_EVENT_RX_REQ = 0x06U,
    I2C_DRV_SLAVE_EVENT_STOP = 0x07U,
    I2C_DRV_SLAVE_EVENT_RESTART = 0x0FU
#if ((STD_ON == I2C_DRV_DMA_FEATURE_AVAILABLE) && (STD_ON == I2C_DRV_DMA_TRANSFER_ERROR_DETECT))
    ,
    I2C_DRV_SLAVE_EVENT_DMA_TRANSFER_ERROR = 0x10U
#endif
} I2c_Drv_SlaveEventType;

/**
 * @brief Define the enum of the events which can trigger I2C master callback
 *
 * @note One transmission, one event(except for I2C_DRV_MASTER_EVENT_HOLD_LOW_TIMEOUT)
 */
typedef enum
{
    I2C_DRV_MASTER_EVENT_NACK = 0x08U, /* addr or data NACK received from slave */
    I2C_DRV_MASTER_EVENT_TRANSFER_ERROR = 0x09U, /* current transmission not completed
                                                    excluding the cause of NACK or timeout */
    I2C_DRV_MASTER_EVENT_END_TRANSFER = 0x0AU,      /*  finish with STOP condition */
    I2C_DRV_MASTER_EVENT_STUCK_LOW_TIMEOUT = 0x0BU, /* stuck low timeout */
#if ((STD_ON == I2C_DRV_DMA_FEATURE_AVAILABLE) && (STD_ON == I2C_DRV_DMA_TRANSFER_ERROR_DETECT))
    I2C_DRV_MASTER_EVENT_DMA_TRANSFER_ERROR = 0x0CU, /* DMA transfer error */
#endif
    I2C_DRV_MASTER_EVENT_RESTART_TRANSFER = 0x0DU /* finish with re-START condition */
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    ,
    I2C_DRV_MASTER_EVENT_HOLD_LOW_TIMEOUT = 0x0EU /* master hold SCL low timeout,
                                                     no effect on other transmissions */
#endif
} I2c_Drv_MasterEventType;

/**
 *  @brief The I2C notification function type definition
 */
typedef void (*I2c_Drv_NotificationType)(uint8 Event, uint8 InstId);

/**
 *  @brief The I2C error notification function type definition
 */
typedef void (*I2c_Drv_ErrNotificationType)(uint8 Event, uint8 InstId);

/**
 *  @brief I2c ID type definition
 */
typedef enum
{
    I2C_DRV_ID_0 = 0U, /*!< I2C0  */
    I2C_DRV_ID_1       /*!< I2C1  */
} I2c_Drv_IdType;

/**
 *  @brief I2C interrupt type definition
 */
typedef enum
{
    I2C_DRV_INT_GEN_CALL = 0U,    /*!< A General Call address is received and it is acknowledged. */
    I2C_DRV_INT_TX_OVER,          /*!< Transmit FIFO above TX FIFO depth and CPU attempts to issue
                                  another I2C command by writing to the I2C_COMMAND_DATA register. */
    I2C_DRV_INT_ERROR_ABORT,      /*!< Error abort interrupt. */
    I2C_DRV_INT_ACTIVITY,         /*!< I2C activity interrupt. There are four ways to clear it:
                                          - Disabling the I2C module
                                          - Writing 1 to the I2C_STATUS0[ACTIVITY]
                                          - Writing 0 to the I2C_INT_ENABLE[I2C_ACTIVITY_DET_IE]
                                          - System reset */
    I2C_DRV_INT_STOP_DET,         /*!< A STOP signal generated interrupt. */
    I2C_DRV_INT_START_DET,        /*!< A START or RESTART signal generated interrupt. */
    I2C_DRV_INT_RD_REQ,           /*!< Slave read request interrupt. */
    I2C_DRV_INT_RX_DONE,          /*!< The transmission done interrupt,
                                                     only valid for I2C as a slave transmitter. */
    I2C_DRV_INT_RX_UNDER,         /*!< Receive FIFO underflow interrupt. */
    I2C_DRV_INT_RX_OVER,          /*!< Received FIFO overflow interrupt. */
    I2C_DRV_INT_RESTART_DET,      /*!< A RESTART signal generated interrupt,
                                  operating in slave mode and the slave is the addressed slave. */
    I2C_DRV_INT_SCL_STUCK_AT_LOW, /*!< SCL stuck at low interrupt. */
    I2C_DRV_INT_RX_FULL,          /*!< Received FIFO full interrupt. */
    I2C_DRV_INT_TX_EMPTY,         /*!< Transmit FIFO empty interrupt.
                                  - When TXFIFO_EMPTY_EN = 0:
                                  This bit is set to 1 when the transmit buffer is at or below the
                                  threshold value set in the I2C_TXFIFO_WATER_MARK register.
                                  - When TXFIFO_EMPTY_EN = 1:
                                  This bit is set to 1 when the transmit buffer is at or below the
                                  threshold value set in the I2C_TXFIFO_WATER_MARK register and
                                  the transmission of the address/data from the internal shift
                                  register for the most recently popped command is completed. */
    I2C_DRV_INT_ALL               /*!< All the interrupt. */
} I2c_Drv_IntType;

/**
 *  @brief I2C master and slave type definition
 */
typedef enum
{
    I2C_DRV_MASTER_MODE = 0U, /*!< I2C master mode define.*/
    I2C_DRV_SLAVE_MODE        /*!< I2C slave mode define.*/
} I2c_Drv_ModeType;

/**
 *  @brief I2C speed type definition
 */
typedef enum
{
    I2C_DRV_SPEED_STANDARD = 1U, /*!< I2C standard speed define.(0 to 100 Kb/s)*/
    I2C_DRV_SPEED_FAST = 2U,     /*!< I2C fast speed define.(up to 400 Kb/s)*/
    I2C_DRV_SPEED_HIGH = 3U,     /*!< I2C high speed define.(up to 1.6 Mb/s)*/
    I2C_DRV_SPEED_FAST_PLUS = 6U /*!< I2C fast mode plus define.(up to 1000 Kb/s)*/
} I2c_Drv_SpeedType;

/**
 * @brief Definition for different state and errors of Operation Status for I2C Driver
 *
 */
typedef enum
{
    I2C_DRV_SUCCESS_STATUS = 0x00U,       /*!<  Status success */
    I2C_DRV_ERROR_STATUS = 0x01U,         /*!<  Error occurred, transfer was not successful */
    I2C_DRV_BUSY_STATUS = 0x02U,          /*!<  I2c module is busy, transfer is in progress */
    I2C_DRV_TIMEOUT_STATUS = 0x03U,       /*!<  Timeout occurred */
    I2C_DRV_RECEIVED_NACK_STATUS = 0x04U, /*!<  NACK signal received  */
    I2C_DRV_TX_UNDERRUN_STATUS = 0x05U,   /*!<  TX underrun error */
    I2C_DRV_RX_OVERRUN_STATUS = 0x06U,    /*!<  RX overrun error */
#if ((STD_ON == I2C_DRV_DMA_FEATURE_AVAILABLE) && (STD_ON == I2C_DRV_DMA_TRANSFER_ERROR_DETECT))
    I2C_DRV_DMA_ERROR_STATUS = 0x07U, /*!<  Error occurred on dma transfer,
                                            the transfer was not successful */
#endif
    I2C_DRV_BUS_BUSY_STATUS = 0x08U /*!<  I2c module is busy, transfer is in progress */
} I2c_Drv_StatusType;

/**
 *  @brief I2C tx error abort source type definition
 */
typedef enum
{
    I2C_DRV_ERR_GEN_CALL_NO_ACK = 0U, /*!< I2C in master mode sent a General Call and no slave
                                      on the bus acknowledged the General Call. */
    I2C_DRV_ERR_GEN_CALL_READ,        /*!< I2C in master mode sent a General Call but the user
                                      programmed the byte following the General Call to be
                                      a read from the bus */
    I2C_DRV_ERR_START_BYTE_ACK_DET,   /*!< Master has sent a START Byte and the START Byte was
                                      acknowledged (wrong behavior) */
    I2C_DRV_ERR_SBYTE_NORSTRT,        /*!< The start is disabled and the user is trying to send
                                      a START Byte */
    I2C_DRV_ERR_H_NO_RSTRT,           /*!< The restart is disabled and the user is trying to use
                                      the master to transfer data in high speed mode. */
    I2C_DRV_ERR_H_MCODE_ACK_DET,      /*!< Master is in High Speed mode and the High Speed
                                      Master code was acknowledged (wrong behavior). */
    I2C_DRV_ERR_7BIT_ADDR_NO_ACK,     /*!< Master is in 7-bit addressing mode and the address
                                      sent was not acknowledged by any slave */
    I2C_DRV_ERR_10BIT_ADDR1_NO_ACK,   /*!< Master is in 10-bit address mode and the first 10-bit
                                      address byte was not acknowledged by any slave. */
    I2C_DRV_ERR_10BIT_ADDR2_NO_ACK,   /*!< Master is in 10-bit address mode and the second
                                      address byte of the 10-bit address was not
                                      acknowledged by any slave. */
    I2C_DRV_ERR_10BIT_READ_NO_RSTRT,  /*!< Will assert 1 when read 10 bit under EN_RESTART = 0. */
    I2C_DRV_ERR_DATA_NO_ACK,          /*!< This is a master-mode only bit. Master has received
                                      an acknowledgement for the address, but when it sent
                                      data byte(s) following the address, it did not
                                      receive an acknowledge from the remote slave(s). */
    I2C_DRV_ERR_MASTER_LOST,          /*!< Master has lost arbitration, or if
                                      I2C_ERROR_STATUS[13] is also set, then the slave
                                      transmitter has lost arbitration. */
    I2C_DRV_ERR_MASTER_DIS,           /*!< User tries to initiate a Master operation with the
                                      Master mode disabled */
    I2C_DRV_ERR_SLAVE_ARBLOST,        /*!< Slave lost the bus while transmitting data to a
                                      remote master.I2C_ERROR_STATUS[14] is set at the same
                                      time. */
    I2C_DRV_ERR_MASTER_ABRT,          /*!< This is a master-mode-only bit. Master has detected
                                      the transfer abort. */
    I2C_DRV_ERR_SLAVE_READ_REQ,       /*!< When the processor side responds to a slave mode
                                      request for data to be transmitted to a remote master
                                      and user writes a 1 in CMD_MASTER_DIRECTION (bit 8)
                                      of I2C_COMMAND_REG register. */
    I2C_DRV_ERR_SLAVE_FLUSH_TXFIFO,   /*!< Slave has received a read command and some data
                                      exists in the TX FIFO so the slave issues a
                                      ERROR_ABORT interrupt to flush old data in TX FIFO. */
    I2C_DRV_ERR_SDA_LOW_TIMEOUT       /*!< SDA stuck at low and timeout error. */
} I2c_Drv_ErrorStatusType;

/**
 *  @brief I2C status type definition
 */
typedef enum
{
    I2C_DRV_MST_ACTIVITY = 0U, /*!< When master is not under idle bit, this bit will be set 1.
                                           - 0: means MASTER FSM is idle
                                           - 1: means MASTER FSM is not idle */
    I2C_DRV_SLV_ACTIVITY,      /*!< When slave is not under idle bit, this bit will be set 1.
                                                 - 0: means SLAVE FSM is idle
                                                 - 1: means SLAVE FSM is not idle */
    I2C_DRV_TXFIFO_EMPTY_MASTER_HOLD, /*!< This bit indicates Tx FIFO is empty, and the the previous
                                           transferred command does not have Stop bit,so master hold
                                           the bus. */
    I2C_DRV_TXFIFO_EMPTY_SLAVE_HOLD,  /*!< This bit indicates when the Tx FIFO is empty, slave will
                                            hold the bus until slave TX FIFO has data to Transmit for
                                            the read request. */
    I2C_DRV_RXFIFO_FULL_MASTER_HOLD,  /*!< This bit indicates RX FIFO is full and receive new data,
                                            so master will hold the bus. */
    I2C_DRV_RXFIFO_FULL_SLAVE_HOLD,   /*!< This bit indicates RX FIFO is full and receive new data,
                                             so slave will hold the bus. */
    I2C_DRV_STATUS_TFNF,              /*!< Transmit FIFO not full,means TX FIFO still has one or
                                                     more empty locations. */
    I2C_DRV_STATUS_TFE,               /*!< Transmit FIFO empty,means TX FIFO is completely empty. */
    I2C_DRV_STATUS_RFNE,              /*!< Receive FIFO not empty.When RX FIFO has one or more
                                       entries already. This bit will be set to 1. */
    I2C_DRV_STATUS_RFF,               /*!< Receive FIFO full.When RX FIFO is completely full,
                                       this bit will be set 1. */
    I2C_DRV_SDA_ERR_RECOVER_STUCK_LOW,   /*!< SDA error recover from stuck at low phase.This bit is
                                      set when SDA fail to recover,and still stuck at low phase. */
    I2C_DRV_SLAVE_IS_DISABLED_UNDER_ACT, /*!< Slave is disabled under active state.When read as 1,
                                          it means slave is potentially disabled during slave
                                          transfer phase. */
    I2C_DRV_SLAVE_RX_DATA_DISCARD, /*!< Slave receive data discard.When read as 1, it means I2C
                                          slave is aborted with at least one data byte from I2C
                                          transfer due to MODULE_EN from 1 to 0. */
    I2C_DRV_ENABLE                 /*!< I2C enable flag.
                                     - 0: means I2C is disable
                                     - 1: means I2C is enabled */
} I2c_Drv_ConfigStatusType;

/**
 *  @brief I2C SDA hold time type definition
 */
typedef struct
{
    uint32 SdaReceiveHoldTime;  /*!< Sets the required SDA hold time in units of I2C function
                                       clock period, when I2C module acts as a receiver.
                                       SDA data hold time after SCL negative edge. */
    uint32 SdaTransmitHoldTime; /*!< Sets the required SDA hold time in units of I2C function
                                       clock period, when I2C module acts as a transmitter.
                                       SDA data hold time after SCL negative edge. */
} I2c_Drv_SdaHoldTimeType;

/**
 * @brief Structure that driver master configuration
 */
typedef struct
{
    uint32 TotalBufferSize; /*!< Total size of tx/rx buffer in bytes of current transmission */
    uint32 RemainingSize;   /*!< Remaining bytes of tx data in buffer or rx read command to send,
                                 which is dynamically modified during transmission */
    uint32 ReceivedSize;    /*!< Received bytes of rx data, which is dynamically modified during
                                 transmission */
    uint8 *DataBuffer;      /*!< Pointer to start address of data buffer,
                                 which is dynamically modified during transmission */
    uint32 SlaveAddr;       /*!< Target slave address when the I2C is operating as a master.
                                      This parameter can be a 7-bit or 10-bit address. */
    boolean AddrBitMode;    /*!< I2C start its transfer in 7 or 10 bits address mode
                                               - TRUE: 10 bits address mode
                                               - FALSE: 7 bits address mode */
    uint8 MasterCode;       /*!< Master code for High-speed mode. Valid range: 0-7.
                                                                    Unused in other operating modes */
    I2c_Drv_SpeedType           SpeedMode; /*!<Speed mode of operation */
    volatile I2c_Drv_StatusType Status;    /*!< Status of last driver operation */
    volatile boolean            I2cIdle;   /*!< Idle/busy state of the driver */
    boolean SendStop; /*!< Specifies if STOP condition must be generated after current transfer */
    boolean SendData; /* Master is in send or receive mode*/
    I2c_Drv_NotificationType    I2cCallback;    /*!< The master notification function */
    I2c_Drv_ErrNotificationType I2cErrCallback; /*!< The master error notification function */
} I2c_Drv_MasterStateType;

/**
 * @brief Structure that driver master configuration
 */
typedef struct
{
    I2c_Drv_SdaHoldTimeType I2cSdaHoldTiming;      /*!< I2C SDA hold time */
    uint16                  SclHighCount;          /*!< I2C speed mode scl high count */
    uint16                  SclLowCount;           /*!< I2C speed mode scl low count */
    uint32                  SclLowTimeout;         /*!< I2C Scl low time out */
    uint32                  SdaLowTimeout;         /*!< I2C SDA low time out */
    uint16                  SpikeSuppressionLimit; /*!< I2C Spike Suppression Limit */
    uint8                   MCode;                 /*!< I2C supports up to 8 high-speed masters */
    I2c_Drv_SpeedType       SpeedMode;             /*!< Specifies the I2C speed mode.
                                            - I2C_SPEED_STANDARD: standard speed (0 to 100 Kb/s)
                                            - I2C_SPEED_FAST: fast speed (<= 400 Kb/s)
                                            - I2C_SPEED_HIGH: high speed (<= 1.6 Mb/s)
                                            - I2C_SPEED_FAST_PLUS: fast plus speed(<= 1000 Kb/s) */
    I2c_Drv_NotificationType    I2cCallback;       /*!< The master notification function */
    I2c_Drv_ErrNotificationType I2cErrCallback;    /*!< The master error notification function */
} I2c_Drv_MasterConfigType;

/**
 * @brief Structure that driver slave configuration
 */
typedef struct
{
    uint32 TotalBufferSize;               /*!< Total size of tx/rx buffer */
    uint32 RemainingSize;                 /*!< Remaining size of tx/rx buffer, which is dynamically
                                                 modified during transmission */
    uint8 *DataBuffer;                    /*!< Pointer to start address of data buffer,
                                               which is dynamically modified during transmission */
    I2c_Drv_SpeedType SpeedMode;          /*!< Specifies the I2C speed mode.
                                                   - I2C_SPEED_STANDARD: standard speed (0 to 100 Kb/s)
                                                   - I2C_SPEED_FAST: fast speed (<= 400 Kb/s)
                                                   - I2C_SPEED_HIGH: high speed (<= 1.6 Mb/s)
                                                   - I2C_SPEED_FAST_PLUS: fast plus speed(<= 1000 Kb/s) */
    uint32 SlaveAddr;                     /*!< Slave address when the I2C is operating as a slave.
                                                    This parameter can be a 7-bit or 10-bit address. */
    boolean AddrBitMode;                  /*!< I2C start its transfer in 7 or 10 bits address mode
                                                             - TRUE: 10 bits address mode
                                                             - FALSE: 7 bits address mode */
    volatile I2c_Drv_StatusType Status;   /*!< Status of last driver operation */
    boolean SendStop; /*!< Specifies if STOP condition must be generated after current transfer */
    uint8   PaddingData; /*!< I2C padding data byte to send when a read command is received without
                              data in buffer */
    I2c_Drv_NotificationType    I2cCallback;    /*!< The slave notification function */
    I2c_Drv_ErrNotificationType I2cErrCallback; /*!< The slave error notification function */
} I2c_Drv_SlaveStateType;

/**
 * @brief Structure that driver slave configuration
 */
typedef struct
{
    I2c_Drv_SdaHoldTimeType I2cSdaHoldTiming;      /*!< I2C SDA hold time */
    uint16                  SpikeSuppressionLimit; /*!< I2C Spike Suppression Limit */
    uint8             SdaSetupTime; /*!< sda setup time when i2c is acting as a slave receiver */
    I2c_Drv_SpeedType SpeedMode;    /*!<Speed mode of operation */
    uint32            SlaveAddr;    /*!< Slave address when the I2C is operating as a slave.
                                              This parameter can be a 7-bit or 10-bit address. */

    boolean AddrBitMode; /*!< I2C start its transfer in 7 or 10 bits address mode
                                            - TRUE: 7 bits address mode
                                            - FALSE: 10 bits address mode */
    uint8 PaddingData;   /*!< I2C padding data byte to send when a read command is received without
                              data in buffer */
    I2c_Drv_NotificationType    I2cCallback;    /*!< The slave notification function */
    I2c_Drv_ErrNotificationType I2cErrCallback; /*!< The slave error notification function */
} I2c_Drv_SlaveConfigType;

/**
 * @brief Structure that store I2c parameters for each instance
 */
typedef struct
{
    uint8                           PhysChId;        /*!< Physical hardware instance ID */
    I2c_Drv_ModeType                MasterSlaveMode; /*!< type of function mode */
    const I2c_Drv_MasterConfigType *MasterCfgPtr;    /*!< I2c Master mode configuration */
    const I2c_Drv_SlaveConfigType  *SlaveCfgPtr;     /*!< I2c Slave mode configuration */
} I2c_Drv_PhyUnitConfigType;

/**
 * @brief Structure that definition for Request Buffer.
 */
typedef struct
{
    uint32 TargetAddr;   /*!< Target slave address when the I2C is operating as a master.
                                      This parameter can be a 7-bit or 10-bit address. */
    boolean AddrBitMode; /*!< I2C start its transfer in 7 or 10 bits address mode
                                             - TRUE: 10 bits address mode
                                             - FALSE: 7 bits address mode */
    boolean SendStop; /*!< Determines whether STOP conditions may be sent when acting as a master.
                         - TRUE: send STOP condition
                         - FALSE: do not send condition */
    uint16 BufferSize; /*!< Buffer Size : The number of bytes for reading or writing.*/
    boolean SendData;  /*!<Direction of the transmission. */
    uint8 *BufferPtr;  /*!< Buffer to Store or to transmit Serial data */

} I2c_Drv_RequestType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c_Drv  */
/** @} end of group I2c_Module */

#endif /* I2C_DRV_TYPES_H */
