/**************************************************************************************************/
/**
 * @file      : Uart_Drv.h
 * @brief     : Uart low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
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
#define UART_DRV_H_SW_PATCH_VERSION            1U

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
 * @return uint8 - Value has 8 bit:
 * @retval 0xFF : Parity bits are incorrect,
 * @retval ID   : Checking parity bits are correct.
 * @retval PID  : parityType is making parity bits.
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


#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Uart_Drv */

/** @} end of group Lin_Module */

#endif /* UART_DRV_H */
