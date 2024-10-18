/**************************************************************************************************/
/**
 * @file      : LinIf.c
 * @brief     : LinIf AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup LinIf_Module
 *  @{
 */

/** @addtogroup LinIf
 *  @brief LinIf AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif




#include "LinIf.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */
#define LINIF_C_VENDOR_ID                   0x00B3U
#define LINIF_C_AR_RELEASE_MAJOR_VERSION    4U
#define LINIF_C_AR_RELEASE_MINOR_VERSION    6U
#define LINIF_C_AR_RELEASE_REVISION_VERSION 0U
#define LINIF_C_SW_MAJOR_VERSION            1U
#define LINIF_C_SW_MINOR_VERSION            2U
#define LINIF_C_SW_PATCH_VERSION            1U

/* Check if current file and Lin header file are of the same vendor */
#if (LINIF_C_VENDOR_ID != LINIF_VENDOR_ID)
    #error "Vendor ID of LinIf.c and LinIf.h are different"
#endif

/* Check if current file and Lin header file are of the same Autosar version */
#if ((LINIF_C_AR_RELEASE_MAJOR_VERSION != LINIF_AR_RELEASE_MAJOR_VERSION) || \
     (LINIF_C_AR_RELEASE_MINOR_VERSION != LINIF_AR_RELEASE_MINOR_VERSION) || \
     (LINIF_C_AR_RELEASE_REVISION_VERSION != LINIF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of LinIf.c and LinIf.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LINIF_C_SW_MAJOR_VERSION != LINIF_SW_MAJOR_VERSION) || \
     (LINIF_C_SW_MINOR_VERSION != LINIF_SW_MINOR_VERSION) || \
     (LINIF_C_SW_PATCH_VERSION != LINIF_SW_PATCH_VERSION) \
    )
    #error "Software Version of LinIf.c and LinIf.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#if (LINIF_WAKEUP_SUPPORT == STD_ON)
/**
* @brief   The LIN Driver or LIN Transceiver Driver will call this function to report the wake up 
*          source after the successful wakeup detection during CheckWakeup or after power on by bus. 
* @details This is a function stub only. 
*     
* @param[in]  WakeupSource - Source device which initiated the wakeup event: LIN controller
*                            or LIN transceiver.
*
* @Requirements
*/
void LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource)
{
    /* Cast to avoid CW */
    (void)WakeupSource;
    return;
}

/** 
* @brief   Will be called when the EcuM has been notified about a wakeup on a specific LIN channel. 
*
* @details This is a function stub only. 
*     
* @param[in]  WakeupSource - Source device which initiated the wakeup event: LIN controller
*                            or LIN transceiver.
*
* @Requirements
*/
Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    /* Cast to avoid CW */
    (void)WakeupSource;

    return E_OK;
}
#endif

/**
* @brief   The LIN Driver will call this function to report a received LIN header. This function is 
*          only applicable for LIN slave nodes (available only if the ECU has any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]    Channel  Identification of the LIN channel.
*
* @param[inout] PduPtr   Pointer to PDU providing the received PID and pointer to the SDU data buffer
*                        as in parameter. Upon return, the length, checksum type and frame response 
*                        type are received as out parameter. If the frame response type is 
*                        LIN_FRAMERESPONSE_TX, then the SDU data buffer contains the transmission data.
*
* @return                Lin_StatusType.
* @retval E_OK           Request has been accepted.
* @retval E_NOT_OK       Request has not been accepted, development or production error occurred.
*
* @Requirements
*/
Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType * PduPtr)
{
    /* Cast to avoid CW */
    (void)Channel;
    PduPtr->Pid = 0U;
    return E_OK;
}

/**
* @brief   The LIN Driver will call this function to report a successfully received response and
*          provides the reception data to the LIN Interface. This function is only applicable for
*          LIN slave nodes (available only if the ECU has any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]  Channel    Identification of the LIN channel.
* @param[in]  Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive
*                        buffer where the current SDU is stored. This pointer is only valid if the 
*                        response is received.
*
* @Requirements
*/
void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr)
{
    /* Cast to avoid CW */
    (void)Channel;
    *Lin_SduPtr = 0U;
}

/** 
* @brief   The LIN Driver will call this function to report a successfully transmitted response.
*          This function is only applicable for LIN slave nodes (available only if the ECU has
*          any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]  Channel    Identification of the LIN channel.
*
* @Requirements
*/
void LinIf_TxConfirmation(NetworkHandleType Channel)
{
    /* Cast to avoid CW */
    (void)Channel;
}

/**
* @brief   The LIN Driver will call this function to report a detected error event during header
*          or response processing. This function is only applicable for LIN slave nodes (available 
*          only if the ECU has any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]  Channel    Identification of the LIN channel.
* @param[in]  ErrorStatus Type of detected error
*
* @Requirements
*/
void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus)
{
    /* Cast to avoid CW */
    uint32 ModuleId = LINIF_MODULE_ID;
    (void) ModuleId;
    (void)Channel;
    (void)ErrorStatus;
}


/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/* End of File */

/** @}*/
