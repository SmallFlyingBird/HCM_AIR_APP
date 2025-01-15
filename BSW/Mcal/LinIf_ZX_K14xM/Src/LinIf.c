/**************************************************************************************************/
/**
 * @file      : LinIf.c
 * @brief     : LinIf AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
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
#include "LinIf_Cbk.h"
#include "LinIf_Internal.h"
#include "LinIf_Slave.h"
#include "LinTp_Slave.h"
#include "LinTp_Internal.h"
#include "Ex_SleepWakeup.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define LINIF_C_VENDOR_ID                   0x00B3U
#define LINIF_C_AR_RELEASE_MAJOR_VERSION    4U
#define LINIF_C_AR_RELEASE_MINOR_VERSION    6U
#define LINIF_C_AR_RELEASE_REVISION_VERSION 0U
#define LINIF_C_SW_MAJOR_VERSION            1U
#define LINIF_C_SW_MINOR_VERSION            2U
#define LINIF_C_SW_PATCH_VERSION            2U

/* Check if current file and Lin header file are of the same vendor */
#if (LINIF_C_VENDOR_ID != LINIF_VENDOR_ID)
    #error "Vendor ID of LinIf.c and LinIf.h are different"
#endif

/* Check if current file and Lin header file are of the same Autosar version */
#if ((LINIF_C_AR_RELEASE_MAJOR_VERSION != LINIF_H_AR_RELEASE_MAJOR_VERSION) || \
     (LINIF_C_AR_RELEASE_MINOR_VERSION != LINIF_H_AR_RELEASE_MINOR_VERSION) || \
     (LINIF_C_AR_RELEASE_REVISION_VERSION != LINIF_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of LinIf.c and LinIf.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LINIF_C_SW_MAJOR_VERSION != LINIF_H_SW_MAJOR_VERSION) || \
     (LINIF_C_SW_MINOR_VERSION != LINIF_SW_MINOR_VERSION) || \
     (LINIF_C_SW_PATCH_VERSION != LINIF_H_SW_PATCH_VERSION) \
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
#define LINIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"
/* The status of LINIF */
VAR(LinIf_StatusType, LINIF_VAR) LinIf_Status = LINIF_UNINIT;
#define LINIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"
/* Global configuration pointer of LINIF */
P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST)
LinIf_ConfigPtr = NULL_PTR;
#define LINIF_STOP_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(
     NetworkHandleType channel
);

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(
     NetworkHandleType channel
);

static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle( void );

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the LIN Interface.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the LIN Interface configuration
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_Init
(
    P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr
)
{
    /*@req <SWS_LinIf_00371>,<SWS_LinIf_00373>*/
    LinIf_ConfigPtr = ConfigPtr;

    LinIf_SlaveInit();

    /*@req <SWS_LinIf_00381>*/
    /* Set the status of LINIF */
    LinIf_Status = LINIF_INIT;
}

/******************************************************************************/
/*
 * Brief               Initiates a transition into the Sleep Mode on the 
 *                     selected channel.
 * ServiceId           0x06
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Channel:  Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     Request to go to sleep has been accepted or
 *                               sleep transition is already in progress or
 *                               controller is already in sleep state.
 *                     E_NOT_OK: Request to go to sleep has not been accepted. 
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GotoSleep
(
    NetworkHandleType Channel
)
{
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);

    LinIf_SlaveGotoSleep(ch);

    return E_OK;
}

#if (LINIF_WAKEUP_SUPPORT == STD_ON)
/******************************************************************************/
/*
 * Brief               Initiates the wake up process.
 * ServiceId           0x07
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel:  Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     Request to wake up has been accepted or the 
 *                               controller is not in sleep state.
 *                     E_NOT_OK: Request to wake up has not been accepted. 
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup
(
    NetworkHandleType Channel
)
{
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    Std_ReturnType ret = E_NOT_OK;

    ret = LinIf_SlaveWakeUp(ch);

    return ret;
}
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
/******************************************************************************/
/*
 * Brief               The main processing function of the LIN Interface.
 * ServiceId           0x80
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_MainFunction(void)
{
    LinIf_SlaveMainHandle();
}
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
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

    ret = LinIf_SlaveHeaderIndication(ch, PduPtr);

    return ret;
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
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

    LinIf_SlaveRxIndication(ch, Lin_SduPtr);
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
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

    LinIf_SlaveTxConfirmation(ch);
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
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

    LinIf_SlaveLinErrorIndication(ch, ErrorStatus);
}


/** @} end of group Public_FunctionDefinition */


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief: Get LinIf channel id by network(ComM Channel id) 
 * Param-Name[in]: channel: Lin channel index
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: uint8
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(
     NetworkHandleType channel
)
{
     NetworkHandleType idx = LINIF_NUMBER_OF_CHANNELS;

    if (LINIF_INIT == LinIf_Status)
    {
        for (idx = 0; idx < LINIF_NUMBER_OF_CHANNELS; idx++)
        {
        	if (LINIF_GET_COMM_NETWORK(idx) == channel)
            {
                return idx;
            }
        }
    }

    return idx;
}

/******************************************************************************/
/*
 * Brief: Get LinIf channel id by Lin Driver channel Id
 * Param-Name[in]: channel: Lin channel index
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: uint8
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(
     NetworkHandleType channel
)
{
     NetworkHandleType idx = LINIF_NUMBER_OF_CHANNELS;

    if (LINIF_INIT == LinIf_Status)
    {
        for (idx = 0; idx < LINIF_NUMBER_OF_CHANNELS; idx++)
        {
        	if (LINIF_GET_LIN_CHANNEL_ID(idx) == channel)
            {
                return idx;
            }
        }
    }

    return idx;
}

/******************************************************************************/
/*
 * Brief: LinIf slave main function
 * Param-Name[in]: None
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle( void )
{
    uint8 ch;

    for (ch = 0u; ch < LINIF_NUMBER_OF_CHANNELS; ch++)
    {
        LinIf_SlaveMainFunction(ch);
        LinTp_SlaveMainFunction(ch);
    }
}



#ifdef __cplusplus
}
#endif

/* End of File */

/** @}*/
