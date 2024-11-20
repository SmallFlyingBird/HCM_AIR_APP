/**************************************************************************************************/
/**
 * @file      : Uart_Drv.h
 * @brief     : Uart low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef UART_DRV_H
#define UART_DRV_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @defgroup Uart_Drv
 *  @brief Internal uart in low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Uart_Drv_Types.h"
#include "common_drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define UART_DRV_H_VENDOR_ID                   0x00B3U
#define UART_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define UART_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define UART_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define UART_DRV_H_SW_MAJOR_VERSION            1U
#define UART_DRV_H_SW_MINOR_VERSION            2U
#define UART_DRV_H_SW_PATCH_VERSION            2U

/* Check if current file and Uart_Drv_Types header file are of the same vendor */
#if (UART_DRV_H_VENDOR_ID != UART_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Uart_Drv.h and Uart_Drv_Types.h are different"
#endif
/* Check if current file and Uart_Drv_Types header file are of the same Autosar version */
#if ((UART_DRV_H_AR_RELEASE_MAJOR_VERSION != UART_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (UART_DRV_H_AR_RELEASE_MINOR_VERSION != UART_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (UART_DRV_H_AR_RELEASE_REVISION_VERSION != UART_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Uart_Drv.h and Uart_Drv_Types.h are different"
#endif
/* Check if current file and Uart_Drv_Types header file are of the same Software version */
#if ((UART_DRV_H_SW_MAJOR_VERSION != UART_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (UART_DRV_H_SW_MINOR_VERSION != UART_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (UART_DRV_H_SW_PATCH_VERSION != UART_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Uart_Drv.h and Uart_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_MacroDefinition
 *  @{
 */



/**
 * @brief  Maximum Length of Data
 */
#define UART_DRV_LIN_MAX_DATA_LENGTH    ((uint8)0x8U)



/**
 * @brief Six bits are reserved for the frame identifier.
 */
#define UART_DRV_LIN_FRAME_ID_MASK      ((uint8)0x3FU)


/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

UART_DRV_EXT

#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"
   
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/**
* @brief   Export UART_DRV configurations.
*/
UART_DRV_CONFIG_EXT

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/** @} end of group Global_VariableDeclaration */


/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
/**
* @brief   Export UART_DRV callback function.
*/
UART_DRV_CALLBACK_EXT

/**
 *
 * @brief       Initialize a LIN channel.
 *
 * @param[in]   InstanceId: initial channel.
 * @param[in]   ConfigPtr: initial configuration.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_Init(uint8 InstanceId, const Uart_Drv_ConfigType *ConfigPtr);

/**
 *
 * @brief       Deinit a LIN channel.
 *
 * @param[in]   InstanceId: initial channel.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_Deinit(uint8 InstanceId);

/**
 *
 * @brief       Get master status
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   LinSduPtr: pointer to  memory mapped LIN hardware receive buffer
 *                       where the current SDU is stored.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte 
 *              has been received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval	    UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval	    UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
Uart_Drv_TransferStateType Uart_Drv_GetMasterStatus(uint8 InstanceId, uint8 **LinSduPtr);

/**
 *
 * @brief       Get slave status
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   LinSduPtr: pointer to  memory mapped LIN hardware receive buffer
 *                       where the current SDU is stored.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte 
 *              has been received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval	    UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval	    UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
Uart_Drv_TransferStateType Uart_Drv_GetSlaveStatus(uint8 InstanceId, uint8 **LinSduPtr);

/**
 *
 * @brief       LIN master send header or slave send response.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   PduInfoPtr: Pointer to PDU containing the PID, checksum model, response
 *              type, Dl and SDU data pointer.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR,
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_SendFrame(uint8                       InstanceId,
                                               const Uart_Drv_PduType *PduInfoPtr);

/**
 *
 * @brief       Stop transmission, abort on-going transmission/reception.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR,
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_StopTransfer(const uint8 InstanceId);

/**
 *
 * @brief       This API command the node to go to sleep, which ID = 0x3C, without sending a go to
 *              sleep command on the bus.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_GoToSleepInternal(uint8 InstanceId);

/**
 *
 * @brief       Sends a wake up signal to the LIN bus.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_StatusType.
 * @retval       UART_DRV_STATUS_SUCCESS
 * @retval       UART_DRV_STATUS_ERROR
 * @retval       UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_Wakeup(const uint8 InstanceId);

/**
 *
 * @brief       Set channel to operation state.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
void Uart_Drv_SetIdleState(const uint8 InstanceId);

/**
 *
 * @brief      This function is called by Lin ISRs.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
void Uart_Drv_IntHandler(uint8 InstanceId);

/**
 *
 * @brief       It checks the parity bits or computes the parity bits.
 *
 * @param[in]   Pid: PID byte in case of checking parity bits or ID byte in case of making parity
 *              bits.
 * @param[in]   ParityType: 1 for Checking parity bits, 0 for making parity bits
 *
 * @return uint8 -   Value has 8 bit:
 * @retval 0xFF :    Parity bits are incorrect,
 * @retval Other   : Checking parity bits are correct,return PID.
 *
 */
uint8 Uart_Drv_ParityCalc(const uint8 Pid, const Uart_Drv_ParityType ParityType);

/**
 *
 * @brief      Initializes the UART.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  UartConfig:  Pointer to a UART configuration structure.
 *
 * @return     None
 *
 */
void Uart_Drv_UartModeInit(Uart_Drv_IdType UartId, 
                                     const Uart_Drv_InitConfigType* UartConfig);

/**
 *
 * @brief      Set UART rts enable .
 *
 * @param[in]  UartId:  UART peripheral selected.
 * @param[in]  NewState: Enable/Disable function state.
 *
 * @return     None
 *
 */
void Uart_Drv_RtsEnable(Uart_Drv_IdType UartId, boolean NewState);

/**
 *
 * @brief      idle detect config.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  Config: config idle detect. 
 *
 * @return     None
 *
 */
void Uart_Drv_IdleDetectConfig(Uart_Drv_IdType UartId, 
                                          const Uart_Drv_IdleDetectConfigType *Config);

/**
 *
 * @brief      Config UART FIFO function.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  FifoConfig:  Pointer to a FIFO configuration.
 *
 * @return     None
 *
 */
void Uart_Drv_FifoConfig(Uart_Drv_IdType UartId,const Uart_Drv_FifoConfigType* FifoConfig);

/**
 *
 * @brief      Get current value of Line Status register.
 * @param[in]  UartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
* @param[in]  LineStatus:
 *                       - UART_DRV_LINESTA_DR
 *                       - UART_DRV_LINESTA_OE
 *                       - UART_DRV_LINESTA_PE
 *                       - UART_DRV_LINESTA_FE
 *                       - UART_DRV_LINESTA_BI
 *                       - UART_DRV_LINESTA_THRE
 *                       - UART_DRV_LINESTA_TEMT
 *                       - UART_DRV_LINESTA_RFE
 *                       - UART_DRV_LINESTA_TRANS_ERR
 *                       - UART_DRV_LINESTA_ADDR_RCVD
 *                       - UART_DRV_LINESTA_ASYNC
 *                       - UART_DRV_LINESTA_FIELD_ERR
 *                       - UART_DRV_LINESTA_PID_ERR
 *                       - UART_DRV_LINESTA_CHECKSUM_ERR
 *                       - UART_DRV_LINESTA_TO_ERR
 *                       - UART_DRV_LINESTA_HEADER_DONE
 *                       - UART_DRV_LINESTA_RSP_DONE
 * 
 * @note       This function returns only one line status. However,  once call 
 *             this function, all line status will be cleared. If user
 *             needs to read more than one line status, it is suggested to use 
 *             Uart_Drv_GetAllLineStatus() to get all line status and handle them 
 *             one by one.
 *
 * @return     The state value of UART Line Status register.
 *
 */
boolean Uart_Drv_GetLineStatus(Uart_Drv_IdType UartId,Uart_Drv_LineStatusType LineStatus);

/**
 *
 * @brief      Set receive 9 bits data mode 0.
 *
 * @param[in]  UartId: Select the UART port.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM0Rx(Uart_Drv_IdType UartId);

/**
 *
 * @brief      Program the address of  receive 9 bits data, mode 1.
 *
 * @param[in]  UartId: Select the UART port.
 * @param[in]  Addr: set address.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM1SetAddr(Uart_Drv_IdType UartId, uint8 Addr);

/**
 *
 * @brief      Select 9 bits hardware receive mode 1.
 *
 * @param[in]  UartId: Select the UART port.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsHWRecvEnable(Uart_Drv_IdType UartId);

/**
 *
 * @brief      Receive address from the UART peripheral, mode 1.
 *
 * @param[in]  UartId: Select the UART port.
 *
 * @return     The received address.
 *
 */
uint16 Uart_Drv_9BitsM1RxAddr(Uart_Drv_IdType UartId);

/**
 *
 * @brief      Receive one byte data from the UART peripheral, mode 1.
 *
 * @param[in]  UartId:  Select the UART port.
 *
 * @return     The received data.
 *
 */
uint16 Uart_Drv_9BitsM1RxData(Uart_Drv_IdType UartId);

/**
 *
 * @brief      Program the transmit target address, 9bits, mode 0.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  Addr:  program the address.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM0SetAddr(Uart_Drv_IdType UartId, uint8 Addr);

/**
 *
 * @brief      Set send address bit, mode 0.
 *
 * @param[in]  UartId:  Select the UART port.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM0SendAddr(Uart_Drv_IdType UartId);

/**
 *
 * @brief      Send 9 bits data to the UART peripheral, mode 1.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  Data:  The data to be sent.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM1TxData(Uart_Drv_IdType UartId, uint16 Data);


#if (STD_ON == UART_DRV_SOFTWARE_POLLING )

/**
 *
 * @brief      This function is polling handle status flag.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
void Uart_Drv_PollingHandler(uint8 InstanceId);
#endif


#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT )
/**
 *
 * @brief      Set Lin software simulation status to idle.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
 void Uart_Drv_SetSimulationStatusToIdle(const uint8 InstanceId);
#endif

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */

/** @addtogroup  UART
 *  @{
 */

/** @defgroup UART_Public_Types
 *  @{
 */

/**
 *  @brief UART ID type definition
 */
typedef enum
{
    UART0_ID = 0U, /*!< UART0  */
    UART1_ID,      /*!< UART1  */
    UART2_ID,      /*!< UART2  */
    UART3_ID,      /*!< UART3  */
    UART4_ID,      /*!< UART4  */
    UART5_ID,      /*!< UART5  */
} UART_ID_t;

/**
 *  @brief UART mode type definition
 */
typedef enum
{
    UART_MODE_UART = 0U, /*!< UART mode */
    UART_MODE_LIN,       /*!< LIN mode */
} UART_Mode_t;

/**
 *  @brief UART parity type definition
 */
typedef enum
{
    UART_PARITY_NONE = 0U, /*!< UART parity none */
    UART_PARITY_ODD,       /*!< UART parity odd  */
    UART_PARITY_EVEN       /*!< UART parity even */
} UART_Parity_t;

/**
 *  @brief UART data bits type definition
 */
typedef enum
{
    UART_DATABITS_5 = 0U, /*!< UART data bits length: 5 bits */
    UART_DATABITS_6,      /*!< UART data bits length: 6 bits */
    UART_DATABITS_7,      /*!< UART data bits length: 7 bits */
    UART_DATABITS_8,      /*!< UART data bits length: 8 bits */
    UART_DATABITS_9       /*!< UART data bits length: 9 bits */
} UART_DataBits_t;

/**
 *  @brief UART stop bits type definition
 */
typedef enum
{
    UART_STOPBITS_1 = 0U, /*!< UART stop bits length: 1 bit */
    UART_STOPBITS_1P5_2   /*!< UART stop bits length: 1.5 or 2 bits */
} UART_StopBits_t;

/**
 *  @brief UART TX FIFO level type definition
 */
typedef enum
{
    UART_TX_FIFO_EMPTY = 0U, /*!< UART FIFO empty */
    UART_TX_FIFO_CHAR_2,     /*!< UART 2 characters in the FIFO */
    UART_TX_FIFO_QUARTER,    /*!< UART FIFO 1/4 full */
    UART_TX_FIFO_HALF        /*!< UART FIFO 1/2 full */
} UART_TxFIFOLvl_t;

/**
 *  @brief UART RX FIFO level type definition
 */
typedef enum
{
    UART_RX_FIFO_CHAR_1 = 0U, /*!< UART 1 character in the FIFO */
    UART_RX_FIFO_QUARTER,     /*!< UART 1/4 full*/
    UART_RX_FIFO_HALF,        /*!< UART 1/2 full */
    UART_RX_FIFO_LESS_2       /*!< UART FIFO 2 less than full */
} UART_RxFIFOLvl_t;

/**
 *  @brief UART IDLE detect length type definition
 */
typedef enum
{
    UART_IDLE_DETECT_LENGTH_1 = 0U, /*!< idle detect length: 1 16-bit character */
    UART_IDLE_DETECT_LENGTH_2,      /*!< idle detection length: 2 16-bit characters   */
    UART_IDLE_DETECT_LENGTH_4,      /*!< UART idle detection length: 4 16-bit characters  */
    UART_IDLE_DETECT_LENGTH_8,      /*!< UART idle detection length: 8 16-bit characters  */
    UART_IDLE_DETECT_LENGTH_16,     /*!< UART idle detection length: 16 16-bit characters */
    UART_IDLE_DETECT_LENGTH_32,     /*!< UART idle detection length: 32 16-bit characters */
    UART_IDLE_DETECT_LENGTH_64,     /*!< UART idle detection length: 64 16-bit characters */
    UART_IDLE_DETECT_LENGTH_128     /*!< UART idle detection length: 128 16-bit characters */
} UART_IdleDetectLength_t;

/**
 *  @brief UART Line status bit type definition
 */
typedef enum
{
    UART_LINESTA_DR = 0U,      /*!< Data ready */
    UART_LINESTA_OE,           /*!< Overrun error */
    UART_LINESTA_PE,           /*!< Parity error */
    UART_LINESTA_FE,           /*!< Framing Error */
    UART_LINESTA_BI,           /*!< Break interrupt */
    UART_LINESTA_THRE,         /*!< Transmit holding register empty */
    UART_LINESTA_TEMT,         /*!< Transmit empty */
    UART_LINESTA_RFE,          /*!< RCV FIFO error */
    UART_LINESTA_TRANS_ERR,    /*!< Indicate whether any of 'OE','PE',
                               'FE','BI' and 'RFE' happens */
    UART_LINESTA_ADDR_RCVD,    /*!< Address receive */
    UART_LINESTA_ASYNC,        /*!< async interrupt */
    UART_LINESTA_FIELD_ERR,    /*!< sync field error */
    UART_LINESTA_PID_ERR,      /*!< PID error */
    UART_LINESTA_CHECKSUM_ERR, /*!< checksum error */
    UART_LINESTA_TO_ERR,       /*!< time out error in LIN mode*/
    UART_LINESTA_HEADER_DONE,  /*!< header done in LIN mode*/
    UART_LINESTA_RSP_DONE      /*!< response done in LIN mode*/
} UART_LineStatus_t;

/**
 *  @brief UART interrupt type definition
 */
typedef enum
{
    UART_INT_RBFI = 0U,   /*!< Received data available interrupt.*/
    UART_INT_TBEI,        /*!< Transmit holding register empty
                               interrupt */
    UART_INT_LSI,         /*!< RX line status interrupt*/
    UART_INT_MODEM,       /*!< CTS interrupt */
    UART_INT_BYDET,       /*!< Busy detect interrupt, cannot be
                                masked */
    UART_INT_RCVRTO,      /*!< Character timeout interrupt, it is
                              effective only when enable the fifo */
    UART_INT_HEADER_DONE, /*!< only LIN can generate Header done
                               interrupt */
    UART_INT_RSP_DONE,    /*!< only LIN can generate response done
                               interrupt */
    UART_INT_ASYNC,       /*!< stop mode wake up: Async interrupt */
    UART_INT_ALL          /*!< All the interrupt */
} UART_Int_t;

/**
 *  @brief UART LIN mode type definition
 */
typedef enum
{
    UART_LIN_SLAVE = 0U, /*!< work as a LIN slave */
    UART_LIN_MASTER,     /*!< work as a LIN master */
} UART_LinMode_t;

/**
 *  @brief UART LIN checksum type definition
 */
typedef enum
{
    UART_LIN_CHECKSUM_CLASSIC = 0U, /*!< classic checksum */
    UART_LIN_CHECKSUM_ENHANCED,     /*!< enhanced checksum */
} UART_LinCheckSum_t;

/**
 *  @brief UART Configuration Structure type definition
 */
typedef struct
{
    uint32 baudRate;                /*!< baud rate */
    UART_DataBits_t dataBits;       /*!< Data size, 5/6/7/8/9 bits */
    UART_Parity_t parity;           /*!< Parity Enable */
    UART_StopBits_t stopBits;       /*!< Number of stop bits */
    ControlState_t autoFlowControl; /*!< Auto flow control enable */
    uint32 oscFreq;                 /*!< the frequency of the OSC clock source*/
} UART_Config_t;

/**
 *  @brief UART FIFO Configuration Structure type definition
 */
typedef struct
{
    ControlState_t fifoEnable;  /*!< Enable/disable FIFO function*/
    ControlState_t txFifoReset; /*!< Reset tx FIFO */
    ControlState_t rxFifoReset; /*!< Reset rx FIFO */
    UART_TxFIFOLvl_t fifoTet;   /*!< Set TX Empty trigger level */
    UART_RxFIFOLvl_t fifoRt;    /*!< Set RCVR trigger level */
} UART_FIFOConfig_t;

/**
 *  @brief UART idle detect Structure type definition
 */
typedef struct
{
    ControlState_t Cmd;          /*!< Enable/disable idle detect*/
    UART_IdleDetectLength_t len; /*!< IDLE detect length */
} UART_IdleDetectConfig_t;

/**
 *  @brief UART LIN Configuration Structure type definition
 */
typedef struct
{
    uint32 baudRate;           /*!< baud rate */
    uint32 oscFreq;            /*!< the frequency of OSC40M crystal*/
    UART_LinMode_t mode;       /*!< LIN mode */
    ControlState_t autoSyncEn; /*!< auto sync enable flag, if is set to
                                     ENABLE, it will detect the baudrate
                                    through the sync part of header and set
                                     the baudrate automatically */
    ControlState_t idFilterEn; /*!< whether enable ID filter when it
                                        receives header  */
} UART_LinConfig_t;

/**
 *  @brief UART LIN header Structure type definition
 */
typedef struct
{
    uint32 id;       /*!< 6-bit ID */
    uint32 breakLen; /*!< break field length */
    uint32 deleLen;  /*!< delemiter length */
} UART_LinHeader_t;

/**
 *  @brief UART LIN header Structure type definition
 */
typedef struct
{
    UART_LinCheckSum_t checkType; /*!< checksum type */
    uint32 len;                   /*!< response length exclude checksum */
    uint8 data[8];                /*!< the response payload exclude checksum*/
} UART_LinResponse_t;

/** @}end of group UART_Public_Types */

/** @defgroup UART_Public_Constants
 *  @{
 */

/** @}end of group UART_Public_Constants */

/** @defgroup UART_Public_Macro
 *  @{
 */

#define UART_NUM 6U
#define UART_INT_NUM 9U

/** @}end of group UART_Public_Macro */

/** @defgroup UART_Public_FunctionDeclaration
 *  @brief UART functions declaration
 *  @{
 */

/**
 * @brief      Initializes the UART
 * @param[in]  uartId:  Select the UART port,should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  uartConfig:  Pointer to a UART configuration structure
 * @return     none
 */
void UART_Init(UART_ID_t uartId, const UART_Config_t *uartConfig);

/**
 * @brief      Set UART rts enable
 *
 * @param[in]  uartId:  UART peripheral selected, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  newState: Enable/Disable function state
 *
 * @return     none
 *
 */
void UART_RtsEnable(UART_ID_t uartId, ControlState_t newState);

/**
 * @brief      Reset uart receive fifo
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     none
 */
void UART_ResetRxFifo(UART_ID_t uartId);

/**
 * @brief      Reset uart transmit fifo
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     none
 */
void UART_ResetTxFifo(UART_ID_t uartId);

/**
 * @brief      Enable/Disable debug enable. If enabled, hardware will not clean
 *             the recevier fifo automaticlly
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @param[in]  ControlState_t: ENABLE/DISABLE
 *
 * @return     none
 *
 */
void UART_DebugCmd(UART_ID_t uartId, ControlState_t Cmd);

/**
 * @brief      idle detect config
 *
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @param[in]  config: config idle detect
 *
 * @return     none
 *
 */
void UART_IdleDetectConfig(UART_ID_t uartId, UART_IdleDetectConfig_t *config);

/**
 * @brief      Send break function, user can choose the length of break,
 *             the length should not be less than eleven
 *
 * @param[in]  uartId:  UART peripheral selected, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  len:     the length of break
 *
 * @return
 *             - SUCC : break is sent
 *             - ERR : break length is invalid
 *
 */
ResultStatus_t UART_SendBreak(UART_ID_t uartId, uint8 len);

/**
 * @brief      Set UART loopback mode
 * @param[in]  uartId:  UART peripheral selected, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  newState: Enable/Disable function state
 * @return     none
 */
void UART_SetLoopBackMode(UART_ID_t uartId, ControlState_t newState);

/**
 * @brief     Wait for UART busy bit clear
 *
 * @param[in]  uartId:  UART peripheral selected, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  cycle: the software cycles to be waited. User decides how many
 *                     cycles need to be waited.
 * @return ResultStatus_t
 *                       - SUCC: busy bit is cleared
 *                       - ERR: UART is still busy
 *
 */
ResultStatus_t UART_WaitBusyClear(UART_ID_t uartId, uint32 cycle);

/**
 * @brief      Receive one byte data from the UART peripheral
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     The received data
 */
uint8 UART_ReceiveByte(UART_ID_t uartId);

/**
 * @brief      Read received bytes from the RX FIFO
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  length:  the number of bytes to be read. When call this function,
 *                      the user needs to make sure that the "length" is not
 *                      greater than the number of bytes that is available in
 *                      RX FIFO
 * @param[out]  data:  points to the memory where the data to be stored
 *.
 * @return     none
 */
void UART_ReceiveBytes(UART_ID_t uartId, uint32 length, uint8 data[]);

/**
 * @brief      Empty the RX FIFO. This function reads received data until RX
 *             FIFO is empty
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @return     None
 */
void UART_EmptyRxFifo(UART_ID_t uartId);

/**
 * @brief      Send one byte data to the UART peripheral
 * @param[in]  uartId:  Select the UART port,should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  data:  The data to be sent
 * @return     none
 */
void UART_SendByte(UART_ID_t uartId, uint8 data);

/**
 * @brief      Config UART FIFO function
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  fifoConfig:  Pointer to a FIFO configuration
 * @return     none
 */
void UART_FIFOConfig(UART_ID_t uartId, const UART_FIFOConfig_t *fifoConfig);

/**
 * @brief      Get current value of Line Status register
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  lineStatus:
 *                       - UART_LINESTA_DR
 *                       - UART_LINESTA_OE
 *                       - UART_LINESTA_PE
 *                       - UART_LINESTA_FE
 *                       - UART_LINESTA_BI
 *                       - UART_LINESTA_THRE
 *                       - UART_LINESTA_TEMT
 *                       - UART_LINESTA_RFE
 *                       - UART_LINESTA_TRANS_ERR
 *                       - UART_LINESTA_ADDR_RCVD
 *                       - UART_LINESTA_ASYNC
 *                       - UART_LINESTA_FIELD_ERR
 *                       - UART_LINESTA_PID_ERR
 *                       - UART_LINESTA_CHECKSUM_ERR
 *                       - UART_LINESTA_TO_ERR
 *                       - UART_LINESTA_HEADER_DONE
 *                       - UART_LINESTA_RSP_DONE
 *
 * @note       This function returns only one line status. However,  once call
 *             this function, all line status will be cleared. If user
 *             needs to read more than one line status, it is suggested to use
 *             UART_GetAllLineStatus() to get all line status and handle them
 *             one by one.
 *
 * @return     The state value of UART Line Status register
 */
FlagStatus_t UART_GetLineStatus(UART_ID_t uartId, UART_LineStatus_t lineStatus);

/**
 * @brief      Get all Line Status
 *
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @note       Once call the function, line status will be cleared
 *
 * @return     The state value of UART Line Status register
 *
 */
uint32 UART_GetAllLineStatus(UART_ID_t uartId);

/**
 * @brief      Get busy status
 *
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @return     The busy Status
 *
 */
FlagStatus_t UART_GetBusyStatus(UART_ID_t uartId);

/**
 * @brief      Get current UART interrupt status, except async status
 *
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  intType: select one interrupt
 *
 * @note       If only need async status, can use UART_GetLineStatus function.
 *
 * @return     The state value of UART Status register

 */
IntStatus_t UART_GetIntStatus(UART_ID_t uartId, UART_Int_t intType);

/**
 * @brief      Config the ID filter values for ID filter 0-15. It will config
 *             the ID filter values for ID filter 0 - (idNum-1) in order. The
 *             value to be configed is stored in the memory that idValues points
 *             to.
 * @param[in]  uartId:  Select the UART port.It should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  idNum:  the number of IDs to be configured. The range is 1-16.
 * @param[in]  idValues:  a pointer to the ID filter value that will be used to
 *                        config the ID filters. The size of the memory must
 *                        not smaller than idNum
 * @return
 *            - SUCC
 *            - ERR : parameter error
 *
 */
ResultStatus_t UART_LinConfigIdFilters(UART_ID_t uartId, uint8 idNum,
                                       const uint8 idValues[]);

/**
 * @brief      Enable/Disable ID filters
 * @param[in]  uartId:  Select the UART port.It should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  ids:  the IDs to be enabled/disabled. The bit0-15 correspond to
 *                   ID filter 0-15. Bit 16 corresponds to the vague ID filter.
 *                   If a bit is 1,the corresponding ID filter is enabled;
 *                   otherwise is disabled.
 * @return    none
 *
 */
void UART_LinIdFiltersCmd(UART_ID_t uartId, uint32 idIndex);

/**
 * @brief      Disable the vague ID filter
 * @param[in]  uartId:  Select the UART port.It should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     none
 *
 */
void UART_LinDisableVagueIdFilter(UART_ID_t uartId);

/**
 * @brief      Enable and config the ID vague filter
 * @param[in]  uartId:  Select the UART port.It should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  idFilterValue:  the value of ID filter. It is range is 0 - 0x3F.
 * @param[in]  idFilterMask:  the mask of the vague ID filter. If a bit of
 *                            idFilterMask is 0, this bit in the vague ID filter
 *                            is ignored. Only bit0-5 is valid.
 * @return     none
 *
 */
void UART_LinEnableVagueIdFilter(UART_ID_t uartId,
                                 uint8 idFilterValue,
                                 uint8 idFilterMask);

/**
 * @brief      Disable a ID filter
 * @param[in]  uartId:  Select the UART port.It should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  idIndex:  the index of ID filter. It indicates which ID filter
 *                       will be disabled. Its range is 0-15
 * @return
 *            - SUCC
 *            - ERR : parameter error
 *
 */
ResultStatus_t UART_LinDisableIdFilter(UART_ID_t uartId, uint32 idIndex);

/**
 * @brief      Enable a ID filter and config the ID filter value
 * @param[in]  uartId:  Select the UART port.It should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  idIndex:  the index of ID filter. It indicates which ID filter
 *                       will be enabled. Its range is 0-15
 * @param[in]  idFilterValue:  the value of ID filter.
 * @return
 *            - SUCC
 *            - ERR : parameter error
 *
 */
ResultStatus_t UART_LinEnableIdFilter(UART_ID_t uartId, uint8 idIndex,
                                      uint8 idFilterValue);

/**
 * @brief      install call back function for interrupts
 *
 * @param[in]  uartId: Select the UART port,should be UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  intType: select the interrupt
 * @param[in]  cbFun: pointer to callback function
 *
 * @return     none
 */
void UART_InstallCallBackFunc(UART_ID_t uartId, UART_Int_t intType,
                              isr_cb_t *cbFun);

/**
 * @brief      Get line status buffer in interrupt call back functions. The line
 *             status will be stored into line status buffer in UART_IRQHandler.
 *             If the call back functions which are installed through
 *             UART_InstallCallBackFunc()  needs to get the line status, please
 *             use this function instead of UART_GetAllLineStatus or
 *             UART_GetLineStatus.
 *
 * @param[in]  uartId: Select the UART port,should be UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @return     linestatus
 *
 */
uint32 UART_GetLineStatusBufForCbf(UART_ID_t uartId);

/**
 * @brief     Mask/Unmask the UART interrupt
 *            UART_INT_RCVRTO and UART_INT_RBFI are controlled by the same bit,
 *            so they are masked/unmasked at the same time. But UART_INT_RCVRTO
 *            is only generated when it in fifo mode and fifo is enabled
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  intType:  Specifies the interrupt type
 * @param[in]  intMask:  Enable/Disable Specified interrupt type
 * @return     none
 */
void UART_IntMask(UART_ID_t uartId, UART_Int_t intType, IntMask_t intMask);

/**
 * @brief      Get UART FIFO status
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     status
 */
ControlState_t UART_GetFifoStatus(UART_ID_t uartId);

/**
 * @brief      Set receive 9 bits data mode 0
 * @param[in]  uartId: Select the UART port, should be UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     none
 */
void UART_9BitsM0Rx(UART_ID_t uartId);

/**
 * @brief      Program the address of  receive 9 bits data, mode 1
 * @param[in]  uartId: Select the UART port, should be UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     none
 */
void UART_9BitsM1SetAddr(UART_ID_t uartId, uint8 addr);

/**
 * @brief      Select 9 bits hardware receive mode 1
 * @param[in]  uartId: Select the UART port, should be UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     none
 */
void UART_9BitsHWRecvEnable(UART_ID_t uartId);

/**
 * @brief      Receive address from the UART peripheral, mode 1
 * @param[in]  uartId: Select the UART port, should be UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     the received address
 */
uint16 UART_9BitsM1RxAddr(UART_ID_t uartId);

/**
 * @brief      Receive one byte data from the UART peripheral, mode 1
 * @param[in]  uartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     The received data
 */
uint16 UART_9BitsM1RxData(UART_ID_t uartId);

/**
 * @brief      Program the transmit target address, 9bits, mode 0
 * @param[in]  uartId:  Select the UART port,should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  addr:  program the address
 * @return     none
 */
void UART_9BitsM0SetAddr(UART_ID_t uartId, uint8 addr);

/**
 * @brief      Set send address bit, mode 0
 * @param[in]  uartId:  Select the UART port,should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     none
 */
void UART_9BitsM0SendAddr(UART_ID_t uartId);

/**
 * @brief      Send 9 bits data to the UART peripheral, mode 1
 * @param[in]  uartId:  Select the UART port,should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  data:  The data to be sent
 * @return     none
 */
void UART_9BitsM1TxData(UART_ID_t uartId, uint16 data);

/**
 * @brief      Config UART in LIN mode
 * @param[in]  uartId:  Select the UART port. It should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  config:  points to the configuration of LIN mode
 * @return     none
 */
void UART_LinConfig(UART_ID_t uartId, const UART_LinConfig_t *config);

/**
 * @brief      Set UART in LIN mode as a LIN master and start to send the header
 * @param[in]  uartId:  Select the UART port.It should be  UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  header:  points to the header to be send
 * @return     status
 *             - SUCC : header is sent
 *             - ERR : header is not sent due to UART is busy
 */
ResultStatus_t UART_LinSendHeader(UART_ID_t uartId,
                                  const UART_LinHeader_t *header);

/**
 * @brief       This function stops receiving/sending header/response of LIN.
 *
 * @param[in]   uartId:  Select the UART port.It should be  UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @return     none
 */
void UART_LinStopTransmission(UART_ID_t uartId);

/**
 * @brief       If LIN is sending/receiving header/response
 *                this function returns SET, otherwise, return RESET.
 *
 * @param[in]   uartId:  Select the UART port.It should be  UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 *
 * @return     SET/RESET
 */
FlagStatus_t UART_LinGetTransmissionStatus(UART_ID_t uartId);

/**
 * @brief      Set LIN as a slave and start to receive a header.
 *             FIFO is disabled before it starts to receive a header
 *
 * @param[in]  uartId:  Select the UART port.It should be  UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return
 *            - SUCC : it starts to receive header
 *            - ERR : it dose not start to receive header due to UART is busy
 */
ResultStatus_t UART_LinStartReceiveHeader(UART_ID_t uartId);

/**
 * @brief      read the 6-bit ID(exclude parity bits) of header
 * @param[in]  uartId:  Select the UART port.UART0_ID, UART1_ID,
 *                     UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @return     ID
 */
uint32 UART_LinGetId(UART_ID_t uartId);

/**
 * @brief      start to send a response
 * @param[in]  uartId:  Select the UART port.It should be  UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  rsp:  Points to reponse structure to be sent.
 * @return
 *             - SUCC : response is sent
 *             - ERR : resoponse is not sent due to UART is busy

 */
ResultStatus_t UART_LinSendResponse(UART_ID_t uartId,
                                    const UART_LinResponse_t *rsp);

/**
 * @brief      start to receive a response
 * @param[in]  uartId:  Select the UART port.It should be  UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  check:  checksum type.
 * @param[in]  len:  response length.
 * @return
 *            - SUCC : it starts to receive response
 *            - ERR : it dose not start to receive response due to UART is busy
 */
ResultStatus_t UART_LinStartReceiveResponse(UART_ID_t uartId,
                                            UART_LinCheckSum_t check,
                                            uint32 len);

/**
 * @brief      read a response. if a reponse is received, this function can be
 *             called to get the data of response. This function is called
 *             after UART_LinStartReceiveResponse() and UART_INTSTA_RSP_DONE
 *             status is set.
 * @param[in]  uartId:  Select the UART port.It should be  UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  len:  response length to be read.
 * @param[in]  data:  points to the memory where the response data to be stored.
 *                    the memory size must not be smaller than len
 * @return     none
 */
void UART_LinReadResponse(UART_ID_t uartId, uint32 len, uint8 data[]);

/** @}end of group UART_Public_FunctionDeclaration */

/** @}end of group UART  */

/** @}end of group Z20K14XM_Peripheral_Driver */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Uart_Drv */

/** @} end of group Lin_Module */

#endif /* UART_DRV_H */
