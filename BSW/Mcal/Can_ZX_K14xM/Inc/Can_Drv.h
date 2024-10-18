/***************************************************************************************************/
/**
 * @file      : Can_Drv.h
 * @brief     : Can low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_DRV_H
#define CAN_DRV_H

/** @addtogroup  Can_Module
 *  @{
 */

/** @addtogroup Can_Drv
 *  @brief Can low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Can_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CAN_DRV_H_VENDOR_ID                   0x00B3U
#define CAN_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_DRV_H_SW_MAJOR_VERSION            1U
#define CAN_DRV_H_SW_MINOR_VERSION            2U
#define CAN_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Can_Drv_Types.h are the same vendor */
#if (CAN_DRV_H_VENDOR_ID != CAN_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Can_Drv.h and Can_Drv_Types.h are different"
#endif
/* Check if current file and Can_Drv_Types.h are of the same Software version */
#if ((CAN_DRV_H_AR_RELEASE_MAJOR_VERSION != CAN_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (CAN_DRV_H_AR_RELEASE_MINOR_VERSION != CAN_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (CAN_DRV_H_AR_RELEASE_REVISION_VERSION != CAN_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Can_Drv.h and Can_Drv_Types.h are different"
#endif
/* Check if current file and Can_Drv_Types.h are of the same Software version */
#if ((CAN_DRV_H_SW_MAJOR_VERSION != CAN_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (CAN_DRV_H_SW_MINOR_VERSION != CAN_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (CAN_DRV_H_SW_PATCH_VERSION != CAN_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Can_Drv_Types.h and Can_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

CAN_DRV_CONFIG_EXT

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

/**
* @brief      This function cancels transmission of the given MB.

* @param[in]  Id: Channel id.
* @param[in]  MbIdx: Message buffer id.
*
* @return     Can_Drv_ControllerStatus
* @retval     CAN_DRV_SUCCESS: Abort command success
* @retval     CAN_DRV_ERROR:  Abort command error
* @retval     CAN_DRV_ENTER_BUSY: Abort command busy
* @retval     CAN_DRV_NO_TRANSMIT:  command is idle

*/
Can_Drv_ControllerStatus Can_Drv_AbortTransfer(uint8 Id, uint8 MbIdx);

/**
 * @brief      Configures a Rx message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  IdType: Message type (standard or extended).
 * @param[in]  MsgId: Message id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Configure command success
 * @retval     CAN_DRV_ERROR:  Configure command error
 * @retval     CAN_DRV_ENTER_BUSY: Configure command busy
 * @retval     CAN_DRV_NO_TRANSMIT:  idle Status
 *
 */
Can_Drv_ControllerStatus Can_Drv_ConfigRxMb(uint8 Id, uint8 MbIdx, Can_Drv_MsgIdType IdType,
                                            uint32 MsgId);

/**
 * @brief      Initializes controller.
 *
 * @param[in]  Id: Channel id.
 * @param[out] CanStatePtr: Channel configuration.
 * @param[in]  CanConfigPtr: Controller configuration parameters.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Channel initialized success.
 * @retval     CAN_DRV_ERROR: Channel initialized failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_Init(uint8 Id, Can_Drv_StateType *CanStatePtr,
                                      const Can_Drv_ConfigType *CanConfigPtr);

/**
  * @brief      De-inits the CAN peripheral. This function disables all CAN
                interrupts, and Disable the CAN
  *
  * @param[in]  Id: Channel id.
  *
  * @return     Can_Drv_ControllerStatus
  * @retval     CAN_DRV_SUCCESS: DeInit command success
  * @retval     CAN_DRV_ERROR:  DeInit command error
  *
  */
Can_Drv_ControllerStatus Can_Drv_Deinit(uint8 Id);

/**
 * @brief      Disables MB interrupts of the given controller.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: MB interrupts of the given controller disabled success.
 * @retval     CAN_DRV_ERROR: MB interrupts of the given controller disabled failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_DisableMbInterrupts(uint8 Id);

/**
 * @brief      This function receives a CAN frame into a configured message buffer via normal mode.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  DataPtr: Pointer to store the received data.
 * @param[in]  IsPolling: Polling mode/Interrupt mode.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Receive can frame success
 * @retval     CAN_DRV_ERROR:   Receive can frame has not been accepted.
 *
 */
Can_Drv_ControllerStatus Can_Drv_Receive(uint8 Id, uint8 MbIdx, Can_Drv_MsgBufType *DataPtr,
                                         boolean IsPolling);

/**
 * @brief      This function receives a CAN frame into a configured message buffer via FIFO mode.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  DataPtr: Pointer to store the received data.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS:  Receive can frame success
 * @retval     CAN_DRV_ERROR:   Receive can frame has not been accepted.
 * @retval     CAN_DRV_ENTER_BUSY:   Receive Status is busy
 *
 */
Can_Drv_ControllerStatus Can_Drv_RxFIFO(uint8 Id, Can_Drv_MsgBufType *DataPtr);

/**
 * @brief     Clears error status.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Mask: error Mask
 *
 * @return     None
 *
 */
void Can_Drv_ClearErrorStatus(uint8 Id, uint32 Mask);

/**
 * @brief      Enables controller interrupts.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Interrupts enabled success.
 * @retval     CAN_DRV_ERROR: The controller is not enabled.
 *
 */
Can_Drv_ControllerStatus Can_Drv_EnableInterrupts(uint8 Id);

/**
 * @brief      Disables controller interrupts.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Interrupts disabled success.
 * @retval     CAN_DRV_ERROR: The controller is not enabled.
 *
 */
Can_Drv_ControllerStatus Can_Drv_DisableInterrupts(uint8 Id);

/**
 * @brief     Gets controller fault confinement state.
 *
 * @param[in] Id: Channel id.
 *
 * @return    uint32: Controller fault confinement state.
 * @retval    0x00: Error active.
 * @retval    0x01: Error passive.
 * @retval    0x1X: Bus off.
 *
 */
uint32 Can_Drv_GetControllerErrorState(uint8 Id);

/**
 * @brief      Returns controller Rx error counter.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     uint32: Rx error counter.
 *
 */
uint32 Can_Drv_GetControllerRxErrorCounter(uint8 Id);

/**
 * @brief     Returns controller Tx error counter.
 *
 * @param[in] Id: Channel id.
 *
 * @return    uint32: Tx error counter.
 *
 */
uint32 Can_Drv_GetControllerTxErrorCounter(uint8 Id);

/**
 * @brief      Returns mailbox transfer status.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Data transferred success.
 * @retval     CAN_DRV_ERROR: Data transferred failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_GetTransferStatus(uint8 Id, uint8 MbIdx);

/**
 * @brief      Manually recovers from bus-off if possible.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Recover from bus off state success.
 * @retval     CAN_DRV_ERROR: Recover from bus off state failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_ManualBusOffRecovery(uint8 Id);

/**
 * @brief      Processes the transmission of the corresponding message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
void Can_Drv_WriteMainFunction(uint8 Id, uint8 MbIdx);

/**
 * @brief      Processes the reception of the corresponding message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
void Can_Drv_ReadMainFunction(const uint8 Id, uint8 MbIdx);

/**
 * @brief      Processes bus off event.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Bus off event processed successfully.
 * @retval     CAN_DRV_ERROR: Bus off event processed failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_BusOffMainFunction(uint8 Id);

/**
 * @brief      Processes wakeup event.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Wakeup event processed successfully.
 * @retval     CAN_DRV_ERROR: Wakeup event processed failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_WakeupMainFunction(uint8 Id);

/**
 * @brief      Configures error interrupt(enable/disable).
 *
 * @param[in]  Id: Channel id.
 * @param[in]  IntType: Error interrupt type.
 * @param[in]  Enable: Enable/Disable.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Error interrupt configured success.
 * @retval     CAN_DRV_ERROR:  Error interrupt configured failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_ConfigErrorInterrupt(uint8 Id, Can_Drv_IntType IntType, boolean Enable);

/**
 * @brief      Sets CAN standard bit timing.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  RatePtr: Pointer to store the bit timing settings.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: CAN standard bit timing set success.
 * @retval     CAN_DRV_ERROR: CAN standard bit timing set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetStdBitTiming(uint8 Id, const Can_Drv_BitTimingType *RatePtr);

/**
 * @brief     Sets CANFD arbitration phase.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  RatePtr: Pointer to store the CANFD bit timing configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: CANFD arbitration phase set success.
 * @retval     CAN_DRV_ERROR: CANFD arbitration phase set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetFdArbBitTiming(uint8 Id, const Can_Drv_BitTimingType *RatePtr);

/**
 * @brief      Sets CANFD data phase.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  RatePtr: Pointer to store the CANFD bit timing configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: CANFD data phase set success.
 * @retval     CAN_DRV_ERROR: CANFD data phase set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetFdDataBitTiming(uint8 Id, const Can_Drv_BitTimingType *RatePtr);

/**
 * @brief      Enables/Disables individual Rx masking and queue.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MaskType: Rx mask type.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Enables/Disables individual Rx masking and queue success.
 * @retval     CAN_DRV_ERROR: Enables/Disables individual Rx masking and queue failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetRxMaskType(uint8 Id, Can_Drv_RxMaskType MaskType);

/**
 * @brief      Returns MB interrupt flag.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: The corresponding buffer has successfully completed transmission or reception.
 * @retval     FALSE: The corresponding buffer has no occurrence of successfully completed
 * transmission or reception.
 *
 */
boolean Can_Drv_GetMbInterruptFlag(uint8 Id, uint8 MbIdx);

/**
 * @brief     Clears MB interrupt flag.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
void Can_Drv_ClearMbIntStatus(uint8 Id, uint8 MbIdx);

/**
 * @brief      Checks whether the channel is in started mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     boolean
 * @retval     TRUE: The channel is in started mode.
 * @retval     FALSE: The channel is not in started mode.
 *
 */
boolean Can_Drv_CheckStartedMode(uint8 Id);

/**
 * @brief      Checks whether the channel is in stopped mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @retval     TRUE: The channel is in stopped mode.
 * @retval     FALSE: The channel is not in stopped mode.
 *
 */
boolean Can_Drv_CheckStoppedMode(uint8 Id);

/**
 * @brief      Sets the channel to started mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Mode transmission succeed.
 * @retval     CAN_DRV_ERROR: Mode transmission failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetStartMode(uint8 Id);

/**
 * @brief      Sets the channel to stop mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: The controller set to stop mode succeed.
 * @retval     CAN_DRV_ERROR: The controller set to stop mode failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetStopMode(uint8 Id);

/**
 * @brief      Configures Rx FIFO filters.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Element: Acceptance type.
 * @param[in]  FilterTablePtr: Pointer to store the filter table.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx FIFO filter configured succeed.
 * @retval     CAN_DRV_ERROR: Rx FIFO filter configured failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_ConfigRxFifo(uint8 Id, Can_Drv_RxAcceptanceType Element,
                                              const Can_Drv_IdFilterType *FilterTablePtr);

/**
 * @brief      This function sends out a CAN frame using a configured message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  TxInfoPtr: Tx message info.
 * @param[in]  IsPolling: Polling mode or not.
 * @param[in]  MsgId: Message id.
 * @param[in]  MsgDataPtr: Pointer to store the message data.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Message sent out succeed.
 * @retval     CAN_DRV_ERROR: Message buffer is invalid.
 * @retval     CAN_DRV_ENTER_BUSY: The message buffer is in invalid state.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SendData(uint8 Id, uint8 MbIdx,
                                          const Can_Drv_MessageInfoType *TxInfoPtr,
                                          boolean IsPolling, uint32 MsgId, const uint8 *MsgDataPtr);

/**
 * @brief      Sets Rx MB individual mask.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  IdType: Message type(standard or extended).
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Mask: Mask Value. 11-bit standard Mask or 29-bit extended Mask
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx MB individual mask set succeed.
 * @retval     CAN_DRV_ERROR: Rx MB individual mask set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetRxIndividualMask(uint8 Id, Can_Drv_MsgIdType IdType,
                                                     uint32 MbIdx, uint32 Mask);

/**
 * @brief      Sets Rx FIFO global Mask. It masks the Rx FIFO ID Filter Table
 *             elements that do not have a corresponding individual Mask.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Mask:Mask Value. Its Format depends on the RX FIFO Id filter Format.
               It should be set as follows:

              Format A ID Mask:
                bit31 | bit30 |      bit29 ... 1             | bit0
                RTR   | IDE(0)| IDmask(std:29-19, ext:29-1)  | reserved

              Format B ID Mask:
                bit31 | bit30 |       bit29 ... 16         | bit 15 | bit 14 | bit13 ... 0
                RTR   | IDE   | ID0(std:29-19, ext:29-16)  | RTR    | IDE    | ID1(std:13-3,
 ext:13-0)

              Format C ID Mask:
                bit31...bit 24 | bit23...bit16 |  bit15 ...bit8 | bit7 ... bit0
                IDmask0        | IDmask1       |    IDmask2     |    IDmask3

 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx FIFO global mask set succeed.
 * @retval     CAN_DRV_ERROR: Rx FIFO global mask set failed.
 *
*/
Can_Drv_ControllerStatus Can_Drv_SetRxFifoGlobalMask(uint8 Id, uint32 Mask);

/**
 * @brief      Enables EACEN(Entire Frame Arbitration Field Comparison Enable for Rx mailboxes).
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Enable EACEN succeed.
 * @retval     CAN_DRV_ERROR: Enable EACEN failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_EnableArbitrationFiledCompare(uint8 Id);

/**
 * @brief      Sets Rx FIFO individual Mask for the specific ID filter table element.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  ElementIdx: ID filter table Element index. It indicates which
 *                         filter table Element the Mask is corresponding to.
 *                         It should not exceeds the MB number that is occupied
 *                         by Rx FIFO.
 * @param[in]  Mask: Mask Value. Its Format depends on the RX FIFO Id filter Format.
               It should be set as follows:

              Format A ID Mask:
                bit31 | bit30 |      bit29 ... 1             | bit0
                RTR   | IDE(0)| IDmask(std:29-19, ext:29-1)  | reserved

              Format B ID Mask:
                bit31 | bit30 |       bit29 ... 16           | bit 15 | bit 14 | bit13 ... 0
                RTR   | IDE   | IDmask0(std:29-19, ext:29-16)| RTR    | IDE    |
 IDmask1(std:13-3, ext:13-0) In the extended frame Format B, IDmask0/IDmask1 corresponds to the
 14 most significant bits of the received ID

              Format C ID Mask:
                bit31...bit 24 | bit23...bit16 |  bit15 ...bit8 | bit7 ... bit0
                IDmask0        | IDmask1       |    IDmask2     |    IDmask3
              For Format C IDmask corresponds to the 8 most significant bits of
              the received ID

 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx FIFO individual mask set succeed.
 * @retval     CAN_DRV_ERROR: Rx FIFO individual mask set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetRxFifoIndividualMask(uint8 Id, uint32 ElementIdx, uint32 Mask);

/**
 * @brief      Enables the Transceiver Delay Compensation feature in CAN FD Mode
 *             and sets the Transceiver Delay Compensation Offset (Offset Value
 *             to be added to the measured transceiver's loop delay in order to
 *             define the position of the delayed comparison point when bit Rate
 *             switching is active).
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Enable: Offset Enable Status
 * @param[in]  Offset: Transceiver Delay Compensation Offset
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Enable TDC feature and set TDC offset success.
 * @retval     CAN_DRV_ERROR: Enable TDC feature and set TDC offset failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetFdTdc(uint8 Id, boolean Enable, uint8 Offset);

/**
 * @brief      Sets Tx Arbitration Start Delay.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Value: Delay Value
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Sets Tx Arbitration Start Delay success.
 * @retval     CAN_DRV_ERROR: Sets Tx Arbitration Start Delay failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetTxArbitrationDelay(uint8 Id, uint8 Value);

/**
 * @brief      Enable self wakeup function.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Self wakeup enabled succeed.
 * @retval     CAN_DRV_ERROR: Self wakeup enabled failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_EnableSelfWakeup(uint8 Id);

/**
 * @brief      Disables self wakeup function.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Self wakeup disabled succeed.
 * @retval     CAN_DRV_ERROR: Self wakeup disabled failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_DisableSelfWakeup(uint8 Id);

/**
 * @brief      Inject correctable error
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: succeed.
 * @retval     CAN_DRV_ERROR: failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_InjectCorrectableAddress(uint8 Id);

/**
 * @brief      Inject non-correctable error
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: succeed.
 * @retval     CAN_DRV_ERROR: failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_InjectAddress(uint8 Id);

/**
 * @brief      Clear injection error
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: succeed.
 * @retval     CAN_DRV_ERROR: failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_ClearInjection(uint8 Id);
/**
 * @brief     MB interrupt handler.
 *
 * @param[in] Id: Channel id.
 * @param[in] StartMbIdx: Start message buffer.
 * @param[in] EndMbIdx: End message buffer.
 *
 * @return    None
 *
 */
void Can_Drv_IntHandler(uint8 Id, uint32 StartMbIdx, uint32 EndMbIdx);

/**
 * @brief     Bus off interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_BusOffIntHandler(uint8 Id);

/**
 * @brief     TX warning interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_TxWarnIntHandler(uint8 Id);

/**
 * @brief     RX warning interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_RxWarnIntHandler(uint8 Id);

/**
 * @brief     Error interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_ErrorIntHandler(uint8 Id);

/**
 * @brief     Error fast interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_FdErrorIntHandler(uint8 Id);

/**
 * @brief     Self wakeup interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_WakeUpIntHandler(uint8 Id);

/**
 * @brief     ECC error interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_EccIntHandler(uint8 Id);

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Can_Drv */

/** @} end of group Can_Module */

#endif /* CAN_DRV_TYPES_H */
