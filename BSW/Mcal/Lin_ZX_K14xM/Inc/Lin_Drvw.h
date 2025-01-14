/**************************************************************************************************/
/**
 * @file      : Lin_Drvw.h
 * @brief     : Lin driver wrapper header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef LIN_DRVW_H
#define LIN_DRVW_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @defgroup Lin_Drvw
 *  @brief Lin driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif


#include "Lin_Drvw_Types.h"
#include "LinIf.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define LIN_DRVW_H_VENDOR_ID                   0x00B3U
#define LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define LIN_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define LIN_DRVW_H_SW_MAJOR_VERSION            1U
#define LIN_DRVW_H_SW_MINOR_VERSION            2U
#define LIN_DRVW_H_SW_PATCH_VERSION            2U


/* Check if current file and Lin_Drvw_Types header file are of the same vendor */
#if (LIN_DRVW_H_VENDOR_ID != LIN_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Lin_Drvw.h and Lin_Drvw_Types.h are different"
#endif
/* Check if current file and Lin_Drvw_Types header file are of the same Autosar version */
#if ((LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (LIN_DRVW_H_AR_RELEASE_MINOR_VERSION != LIN_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (LIN_DRVW_H_AR_RELEASE_REVISION_VERSION != LIN_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Drvw.h and Lin_Drvw_Types.h are different"
#endif
/* Check if current file and Lin_Drvw_Types header file are of the same Software version */
#if ((LIN_DRVW_H_SW_MAJOR_VERSION != LIN_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (LIN_DRVW_H_SW_MINOR_VERSION != LIN_DRVW_TYPES_H_SW_MINOR_VERSION) ||                         \
     (LIN_DRVW_H_SW_PATCH_VERSION != LIN_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Lin_Drvw.h and Lin_Drvw_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE

    #if((LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION != LINIF_AR_RELEASE_MAJOR_VERSION) || \
        (LIN_DRVW_H_AR_RELEASE_MINOR_VERSION != LINIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Lin_Drvw.h and LinIf.h are different"
    #endif
#endif

/**
* @brief          Define none ecum wakeup source
*/
#if (STD_ON  == LIN_DRVW_WAKEUP_DETECTION)
#define LIN_DRVW_NONE_ECUM_WAKEUP_SOURCE_REF     (0UL)
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/**
* @brief   Export DRVW configurations.
*/
LIN_DRVW_CONFIG_EXT

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"
/** @} end of group Global_VariableDeclaration */      


/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/**
 *
 * @brief       Initialize a LIN channel.
 *
 * @param[in]   Channel: initial channel.
 * @param[in]   HwUnitConfigPtr: Global configuration pointer.
 *
 * @return      None
 *
 */
void Lin_Drvw_ChannelInit(uint8 Channel, const Lin_Drvw_HwConfigType *HwUnitConfigPtr);

/**
 *
 * @brief       The function check wakeup.
 *
 * @param[in]   Channel: initial channel.
 *
 * @return      Std_ReturnType.
 * @retval      -E_OK:If the LIN Channel has the wake up flag set and the wake up ISR disabled
 * @retval      -E_NOT_OK:Otherwise.
 *
 */
Std_ReturnType Lin_Drvw_CheckWakeup(uint8 Channel);

#if (STD_ON == LIN_DRVW_MASTER_SUPPORT)
/**
 *
 * @brief       Get lin channel or frame status.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 * @param[in]   LinSduPtr: pointer to  memory mapped LIN hardware receive buffer
 *                       where the current SDU is stored.
 *
 * @return      Lin_StatusType
 * @retval      LIN_NOT_OK - Development or production error occurred.
 * @retval      LIN_TX_OK - Successful transmission.
 * @retval      LIN_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      LIN_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		        - Identifier parity error or Physical bus error
 * @retval	    LIN_TX_ERROR: Erroneous response transmission such as:
 *			        - Mismatch between sent and read back data
 *			        - Physical bus error
 * @retval	    LIN_RX_OK: Reception of correct response.
 * @retval	    LIN_RX_BUSY: Ongoing reception: at least one response byte has been received,
 *              but the checksum byte has not been received.
 * @retval	    LIN_RX_ERROR: Erroneous response reception such as:
 *			        - Framing error
 *			        - Overrun error
 *			        - Checksum error or Short response
 * @retval	    LIN_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval	    LIN_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval	    LIN_CH_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
Lin_StatusType Lin_Drvw_GetStatus(uint8 Channel, uint8 **LinSduPtr);

/**
 *
 * @brief       Send LIN frame
 *
 * @param[in]   Channel: LIN channel to be addressed.
 * @param[in]   PduInfoPtr: Pointer to PDU containing the PID, checksum model, response
 *              type, Dl and SDU data pointer.
 *
 * @return      Std_ReturnType
 * @retval      -E_NOT_OK:n case of a time-out situation only.
 * @retval      -E_OK:no error.
 * @retval      -LIN_DRVW_TIMEOUT_ERROR: timeout
 *
 */
Std_ReturnType Lin_Drvw_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr);

/**
 *
 * @brief       This API command the node to go to sleep, which ID = 0x3C.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      Std_ReturnType
 * @retval      -E_NOT_OK:n case of a time-out situation only.
 * @retval      -E_OK:no error.
 * @retval      -LIN_DRVW_TIMEOUT_ERROR: timeout
 *
 */
Std_ReturnType Lin_Drvw_GoToSleep(uint8 Channel);
#endif /* ( STD_ON == LIN_DRVW_MASTER_SUPPORT) */

/**
 *
 * @brief       This API set channel to sleep state and wait wakeup signal.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      Std_ReturnType
 * @retval      -E_NOT_OK:n case of a time-out situation only.
 * @retval      -E_OK:no error.
 * @retval      -LIN_DRVW_TIMEOUT_ERROR: timeout
 *
 */
Std_ReturnType Lin_Drvw_GoToSleepInternal(uint8 Channel);

/**
 *
 * @brief       Sends a wake up signal to the LIN bus.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      None.
 *
 */
Std_ReturnType Lin_Drvw_Wakeup(const uint8 Channel);

/**
 *
 * @brief       Set instance to idle state.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      None.
 *
 */
void Lin_Drvw_WakeupInternal(uint8 Channel);

/**
 *
 * @brief       De-init Lin instance.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Deinit ok.
 * @retval     E_NOT_OK: Deinit error.
 */
Std_ReturnType Lin_Drvw_Deinit(uint8 Channel);



#if (STD_ON == LIN_DRVW_SOFTWARE_POLLING )
/**
 *
 * @brief       Lin poll handle line state.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      None.
 *
 */
void Lin_Drvw_Poll(uint8 Channel);

#endif


#if (STD_ON == LIN_DRVW_SOFTWARE_SIMULATION_TIMEOUT )
/**
 *
 * @brief       Set Lin software simulation status to idle.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      None.
 *
 */
void Lin_Drvw_SetSimulationStatusToIdle(uint8 Channel);
#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Lin_Drvw */

/** @} end of group Lin_Module */

#endif /* LIN_DRVW_H */
