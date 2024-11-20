/**************************************************************************************************/
/**
 * @file      : Uart_Drv_Types.h
 * @brief     : Lin low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef UART_DRV_TYPES_H
#define UART_DRV_TYPES_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @defgroup Uart_Drv_Types
 *  @brief Internal uart in low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Uart_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define UART_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define UART_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define UART_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define UART_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define UART_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define UART_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define UART_DRV_TYPES_H_SW_PATCH_VERSION            2U


#if (UART_DRV_TYPES_H_VENDOR_ID != UART_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Uart_Drv_Types.h and Uart_Drv_Cfg.h are different"
#endif
/* Check if current file and Uart_Drv_Cfg header file are of the same Autosar version */
#if ((UART_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != UART_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (UART_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != UART_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (UART_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=UART_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "Software Version of Uart_Drv_Types.h and Uart_Drv_Cfg.h are different"
#endif
/* Check if current file and Uart_Drv_Cfg header file are of the same Software version */
#if ((UART_DRV_TYPES_H_SW_MAJOR_VERSION != UART_DRV_CFG_H_SW_MAJOR_VERSION) ||                     \
    (UART_DRV_TYPES_H_SW_MINOR_VERSION != UART_DRV_CFG_H_SW_MINOR_VERSION) ||                      \
    (UART_DRV_TYPES_H_SW_PATCH_VERSION != UART_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Uart_Drv_Types.h and Uart_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((UART_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||            \
        (UART_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Uart_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((UART_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||        \
        (UART_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION) )
        #error "AutoSar Version of Uart_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
#define UART_DRV_EVENT_RECEIVE_HEADER               (0U)
#define UART_DRV_EVENT_RECEIVE_RESPONSE             (1U)
#define UART_DRV_EVENT_SEND_RESPONSE                (2U)
#endif

/**
 *  @brief UART ID type definition
 */
typedef enum
{
    UART_DRV_ID_0 = 0U,
    UART_DRV_ID_1 ,
    UART_DRV_ID_2 ,
    UART_DRV_ID_3 ,
    UART_DRV_ID_4 ,
    UART_DRV_ID_5 
} Uart_Drv_IdType;

/**
 *  @brief UART interrupt type definition
 */
typedef enum
{
    UART_DRV_INT_RBFI = 0U,   /*!< Received data available interrupt.*/
    UART_DRV_INT_TBEI,        /*!< Transmit holding register empty interrupt */
    UART_DRV_INT_LSI,         /*!< RX line status interrupt*/
    UART_DRV_INT_MODEM,       /*!< CTS interrupt */
    UART_DRV_INT_BYDET,       /*!< Busy detect interrupt, cannot be masked */
    UART_DRV_INT_RCVRTO,      /*!< Character timeout interrupt, it is
                                              effective only when enable the fifo */
    UART_DRV_INT_HEADER_DONE, /*!< only LIN can generate Header done interrupt */
    UART_DRV_INT_RSP_DONE,    /*!< only LIN can generate response done interrupt */
    UART_DRV_INT_ASYNC,       /*!< stop mode wake up: Async interrupt */
    UART_DRV_INT_ALL          /*!< All the interrupt */
} Uart_Drv_IntType;


/**
 *  @brief UART interrupt type definition
 */
typedef enum
{
    UART_DRV_POLL_RBFI = 0U,   /*!< Received data available interrupt.*/
    UART_DRV_POLL_HEADER_DONE, /*!< only LIN can generate Header done interrupt */
    UART_DRV_POLL_RSP_DONE,    /*!< only LIN can generate response done interrupt */
    UART_DRV_POLL_ASYNC,       /*!< stop mode wake up: Async interrupt */
    UART_DRV_POLL_ALL          /*!< All the interrupt */
} Uart_Drv_PollType;

/**
 * @brief Define LIN event id
 *
 */
typedef enum
{
    UART_DRV_NO_EVENT = 0x00U,             /*!<  No event */
    UART_DRV_EVENT_WAKEUP_SIGNAL ,        /*!<  Wakeup signal detected */
    UART_DRV_EVENT_SEND_HEADER_OK ,       /*!<  send header ok */
    UART_DRV_EVENT_RECV_HEADER_OK ,       /*!<  receive header ok */   
    UART_DRV_EVENT_RECV_HEADER_ERR,       /*!< Receive header error */
    UART_DRV_EVENT_FRAME_ERROR ,          /*!  Frame transfer has errors */
    UART_DRV_EVENT_READBACK_ERROR ,       /*!<  Readback error, including header and response */
    UART_DRV_EVENT_CHECKSUM_ERROR ,       /*!<  Checksum error */
    UART_DRV_EVENT_TX_COMPLETED ,         /*!<  Tx completed */
    UART_DRV_EVENT_RX_COMPLETED ,         /*!<  Rx completed */
    UART_DRV_EVENT_RX_OVERRUN_ERROR ,     /*!<  Rx overrun error */
    UART_DRV_EVENT_TIMEOUT_ERROR          /*!<  Timeout error */
} Uart_Drv_EventIdType;

/**
 * @brief Define LIN Node state.
 */
typedef enum
{
    UART_DRV_NODE_STATE_UNINIT = 0x00U,           /*!<  The node uninitialized */
    UART_DRV_NODE_STATE_SLEEP_MODE ,              /*!<  The node in sleep mode  */
    UART_DRV_NODE_STATE_IDLE ,                    /*!< The node is Idle  */
    UART_DRV_NODE_STATE_SEND_BREAK_FIELD ,        /*!<  The node send break field  */
    UART_DRV_NODE_STATE_SEND_SYNC ,               /*!< The node receive the synchronization field */
    UART_DRV_NODE_STATE_SEND_PID ,                /*!< The node send PID  */
    UART_DRV_NODE_STATE_RECV_BREAK ,              /*!< The node receive break  */
    UART_DRV_NODE_STATE_RECV_SYNC ,               /*!< The node receive sync  */
    UART_DRV_NODE_STATE_RECV_HEADER ,             /*!< The node receive header */
    UART_DRV_NODE_STATE_SEND_RESPONSE ,           /*!< The node send data  */
    UART_DRV_NODE_STATE_RECV_RESPONSE             /*!< The node receive data */
} Uart_Drv_NodeStateType;

/**
 * @brief UART status type
 */
typedef enum
{
    UART_DRV_STATUS_SUCCESS = 0x00,
    UART_DRV_STATUS_ERROR,
    UART_DRV_STATUS_BUSY
} Uart_Drv_StatusType;

/**
 * @brief Define type for checksum type of the frame.
 */
typedef enum
{
    UART_DRV_CLASSIC_CS = 0U,   /*!<  Classic checkSum model: data.*/
    UART_DRV_ENHANCED_CS        /*!<  Enhanced checkSum model: data and pid*/    
} Uart_Drv_FrameCsModelType;

/**
 * @brief Define type for poll type of the frame.
 */
typedef enum
{
    UART_DRV_INTERRUPT = 0U,   /*!<  interrupt handle mode */
    UART_DRV_POLLING         /*!<  poll handle mode */
} Uart_Drv_PollModelType;


/**
 *  @brief UART LIN mode type definition
 */
typedef enum
{
    UART_DRV_NODE_SLAVE = 0U, /*!<  Slave node */
    UART_DRV_NODE_MASTER,     /*!<  Master node */
} Uart_Drv_NodeType;

/**
 * @brief Define two parity type
 *
 */
typedef enum
{
    UART_DRV_SOFTWARE_CHECK_PARITY = 0U, /*!< Check get parity whether correct*/
    UART_DRV_SOFTWARE_CAL_PARITY            /*!< Calculating parity  */
} Uart_Drv_ParityType;

/**
 * @brief This defines frame transfer direction.
 */
typedef enum
{
    UART_DRV_FRAMERESPONSE_TX = 0U, /*!<  Master send the response.*/
    UART_DRV_FRAMERESPONSE_RX,     /*!<  Slave send the response.*/
    UART_DRV_FRAMERESPONSE_IGNORE  /*!<  Slave send the response to another slave.*/
} Uart_Drv_FrameResponseType;

/**
 * @brief This defines LIN transfer state.
 */
typedef enum
{
    UART_DRV_STATE_NOT_OK = 0U,    /*!<  Command has not been accepted. */
    UART_DRV_STATE_TX_OK,           /*!<  Transmission successfully. */
    UART_DRV_STATE_TX_BUSY,         /*!<  Transmission is ongoing. */
    UART_DRV_STATE_TX_HEADER_ERROR, /*!<  Erroneous header transmission. */
    UART_DRV_STATE_TX_ERROR,        /*!<  Erroneous response transmission. */
    UART_DRV_STATE_RX_OK,           /*!<  Reception of correct response. */
    UART_DRV_STATE_RX_BUSY,  /*!<  Ongoing reception. At least one response byte has been
                                     received. */
    UART_DRV_STATE_RX_ERROR, /*!<  Erroneous response reception. */
    UART_DRV_STATE_RX_NO_RESPONSE,  /*!<  No response byte has been received so
                                            far(timeout occurred). */
    UART_DRV_STATE_OPERATIONAL,     /*!<  Normal operation. */
    UART_DRV_STATE_SLEEP,           /*!<  Sleep state operation. */
    UART_DRV_STATE_RX_HEADER_OK,    /*!<  Slave received a correct header. */
    UART_DRV_STATE_RX_HEADER_ERROR, /*!<  Erroneous header reception of slave. */
} Uart_Drv_TransferStateType;

/**
 * @brief This type is used to specify whether the frame processor is required to
 *         transmit the response part of the LIN frame.
 */
typedef struct
{
    uint8                              Pid;    /*!<  LIN frame identifier.*/
    Uart_Drv_FrameCsModelType          Cs;     /*!<  Checksum model type.*/
    Uart_Drv_FrameResponseType         Drc;    /*!<  Response type.*/
    uint8                              Dl;     /*!<  Data length.*/
    uint8                              *SduPtr; /*!<  Pointer to Sdu.*/
} Uart_Drv_PduType;

/**
 * @brief This defines lin transfer configuration.
 *
 */
typedef struct
{
    const uint8   *TxBuff;  /*!<  The buffer of data being sent.SWS_Lin_00026 */
    uint8         *RxBuff;  /*!<  The buffer of received data. SWS_Lin_00026*/
    uint8          CntByte; /*!<  To count number of bytes already transmitted or received. */
    volatile uint8 TxSize;  /*!<  The remaining number of bytes to be transmitted. */
    volatile uint8 RxSize;  /*!<  The remaining number of bytes to be received. */
    uint8          Checksum; /*!<  Checksum byte */
    volatile boolean
          IsBusBusy;  /*!<  True if there are data, frame headers being transferred on bus */
    uint8 CurrentPid; /*!<  Current PID */
    volatile Uart_Drv_EventIdType   CurrentEventId;   /*!<  Current ID Event */
    volatile Uart_Drv_NodeStateType CurrentNodeState; /*!<  Current Node state */
    volatile Uart_Drv_NodeStateType
        PreviousNodeState; /*!<  Store previous node state when set Lin channel to idle for
                              further processing.*/
    Uart_Drv_PollModelType PollMode;       /*!<  Enable poll  mode */
} Uart_Drv_TransferConfigType;

/**
 * @brief This defines LIN callback function.
 */
typedef void (*Uart_Drv_Lin_CallbackType)(const uint8                            InstanceId,
                                          const Uart_Drv_TransferConfigType *LinStatePtr);

/**
 * @brief This defines LIN hardware configuration structure.
 *
 */
typedef struct
{
    uint8  InstanceId;              /*!<  Hardware Instance */
    uint32 BaudRateDivisor;         /*!<  Baudrate divider to be configured in hardware */
    uint32 FranctionDivisor;        /*!<  Baudrate divider to be configured in hardware */
    Uart_Drv_NodeType NodeType; /*!<  Node function as Master or Slave */
    uint8   BreakLen;       /*!<  Length of break character master will be transmitted */
    uint8   DelLen;         /*!<  Length of break delimiter master will be transmitted */
    boolean AutosyncEnable; /*!<  Enable Autobaud feature */
    Uart_Drv_Lin_CallbackType LinCallbackPtr; /*!<  Callback function to invoke after receiving a
                                           byte or transmitting a byte. */
    Uart_Drv_TransferConfigType *TransferConfigPtr;
                                           
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    uint32 HeaderTimer;/*!< Header timeout duration(in bit time) after receive break,converted to micro seconds. */
    uint32 ResponseTimeoutValue;/*!<  @brief Response timeout duration(in bit time) for len+1  byte converted to micro seconds. */
#endif

    uint8 WakeupByte; /*!<  Byte will be sent to generate wakeup pulse [250us->5ms] */
#if (STD_ON == UART_DRV_WAKEUP_DETECTION )
    /*   data length should be (8,100), hardware only support greater than 11 bits     */
    uint8 CalWakeupLen; /*!<  Byte use to check detection of wake up pulse
                                           longer than 150us */
#endif
    uint32 ChannelClock;
} Uart_Drv_ConfigType;

/**
 *  @brief UART data bits type definition
 */
typedef enum
{
    UART_DRV_DATABITS_5 = 0U,           /*!< UART data bits length: 5 bits */
    UART_DRV_DATABITS_6,                /*!< UART data bits length: 6 bits */
    UART_DRV_DATABITS_7,                /*!< UART data bits length: 7 bits */
    UART_DRV_DATABITS_8,                /*!< UART data bits length: 8 bits */
    UART_DRV_DATABITS_9                 /*!< UART data bits length: 9 bits */
} Uart_Drv_DataBitsType;

/**
 *  @brief UART Line status bit type definition
 */
typedef enum
{
    UART_DRV_LINESTA_DR = 0U,                   /*!< Data ready */
    UART_DRV_LINESTA_OE,                        /*!< Overrun error */
    UART_DRV_LINESTA_PE,                        /*!< Parity error */
    UART_DRV_LINESTA_FE,                        /*!< Framing Error */
    UART_DRV_LINESTA_BI,                        /*!< Break interrupt */
    UART_DRV_LINESTA_THRE,                      /*!< Transmit holding register empty */
    UART_DRV_LINESTA_TEMT,                      /*!< Transmit empty */
    UART_DRV_LINESTA_RFE,                       /*!< RCV FIFO error */
    UART_DRV_LINESTA_TRANS_ERR,                 /*!< Indicate whether any of 'OE','PE',
                                            'FE','BI' and 'RFE' happens */
    UART_DRV_LINESTA_ADDR_RCVD,                 /*!< Address receive */
    UART_DRV_LINESTA_ASYNC,                     /*!< async interrupt */
    UART_DRV_LINESTA_FIELD_ERR,                 /*!< sync field error */
    UART_DRV_LINESTA_PID_ERR,                   /*!< PID error */
    UART_DRV_LINESTA_CHECKSUM_ERR,              /*!< checksum error */
    UART_DRV_LINESTA_TO_ERR,                    /*!< time out error in LIN mode*/
    UART_DRV_LINESTA_HEADER_DONE,               /*!< header done in LIN mode*/
    UART_DRV_LINESTA_RSP_DONE                   /*!< response done in LIN mode*/
} Uart_Drv_LineStatusType;


/**
 *  @brief UART parity type definition
 */
typedef enum
{
    UART_DRV_PARITY_NONE = 0U,                  /*!< UART parity none */
    UART_DRV_PARITY_ODD,                        /*!< UART parity odd  */
    UART_DRV_PARITY_EVEN                        /*!< UART parity even */
} Uart_Drv_HwParityType;

/**
 *  @brief UART stop bits type definition
 */
typedef enum
{
    UART_DRV_STOPBITS_1 = 0U,           /*!< UART stop bits length: 1 bit */
    UART_DRV_STOPBITS_1P5_2             /*!< UART stop bits length: 1.5 or 2 bits */
} Uart_Drv_StopBitsType;

/**
 *  @brief UART TX FIFO level type definition
 */
typedef enum
{
    UART_DRV_TX_FIFO_EMPTY = 0U,        /*!< UART FIFO empty */
    UART_DRV_TX_FIFO_CHAR_2,            /*!< UART 2 characters in the FIFO */
    UART_DRV_TX_FIFO_QUARTER,           /*!< UART FIFO 1/4 full */
    UART_DRV_TX_FIFO_HALF               /*!< UART FIFO 1/2 full */
} Uart_Drv_TxFifoLevelType;

/**
 *  @brief UART RX FIFO level type definition
 */
typedef enum
{
    UART_DRV_RX_FIFO_CHAR_1 = 0U,       /*!< UART 1 character in the FIFO */
    UART_DRV_RX_FIFO_QUARTER,           /*!< UART 1/4 full*/
    UART_DRV_RX_FIFO_HALF,              /*!< UART 1/2 full */
    UART_DRV_RX_FIFO_LESS_2             /*!< UART FIFO 2 less than full */
} Uart_Drv_RxFifoLevelType;

/**
 *  @brief UART IDLE detect length type definition
 */
typedef enum
{
    UART_DRV_IDLE_DETECT_LENGTH_1 = 0U, /*!< idle detect length: 1 16-bit character */
    UART_DRV_IDLE_DETECT_LENGTH_2,      /*!< idle detection length: 2 16-bit characters   */
    UART_DRV_IDLE_DETECT_LENGTH_4,      /*!< UART idle detection length: 4 16-bit characters  */
    UART_DRV_IDLE_DETECT_LENGTH_8,      /*!< UART idle detection length: 8 16-bit characters  */
    UART_DRV_IDLE_DETECT_LENGTH_16,     /*!< UART idle detection length: 16 16-bit characters */
    UART_DRV_IDLE_DETECT_LENGTH_32,     /*!< UART idle detection length: 32 16-bit characters */
    UART_DRV_IDLE_DETECT_LENGTH_64,     /*!< UART idle detection length: 64 16-bit characters */
    UART_DRV_IDLE_DETECT_LENGTH_128     /*!< UART idle detection length: 128 16-bit characters */
} Uar_Drv_IdleDetectLengthType;

/**
 * @brief This defines UART hardware configuration structure.
 *
 */
typedef struct
{
    uint32 BaudRate;              /*!< baud rate */
    Uart_Drv_DataBitsType DataBits;       /*!< Data size, 5/6/7/8/9 bits */
    Uart_Drv_HwParityType Parity;           /*!< Parity Enable */
    Uart_Drv_StopBitsType StopBits;       /*!< Number of stop bits */
    boolean AutoFlowControl; /*!< Auto flow control enable */
    uint32 OscFreq;               /*!< the frequency of the OSC clock source*/
} Uart_Drv_InitConfigType;

/**
 *  @brief UART FIFO Configuration Structure type definition
 */
typedef struct
{
    boolean FifoEnable;      /*!< Enable/disable FIFO function*/
    boolean TxFifoReset;     /*!< Reset tx FIFO */
    boolean RxFifoReset;     /*!< Reset rx FIFO */
    Uart_Drv_TxFifoLevelType FifoTet;       /*!< Set TX Empty trigger level */
    Uart_Drv_RxFifoLevelType FifoRt;        /*!< Set RCVR trigger level */
} Uart_Drv_FifoConfigType;

/**
 *  @brief UART idle detect Structure type definition
 */
typedef struct
{
    boolean Cmd;             /*!< Enable/disable idle detect*/
    Uar_Drv_IdleDetectLengthType Len;            /*!< IDLE detect length */
} Uart_Drv_IdleDetectConfigType;

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

/** @} end of group Uart_Drv_Types*/

/** @} end of group Lin_Module */

#endif /* UART_DRV_TYPES_H */
