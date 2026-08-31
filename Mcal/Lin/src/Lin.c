
/**
 * @file    Lin.c
 * @version V2.3.0
 *
 * @brief   AUTOSAR Lin module interface
 * @details API implementation for LIN driver
 *
 * @addtogroup LIN_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lin
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Dio_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Dio_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "LinIf.h"
#include "Lin.h"
#include "Lin_Mld.h"
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_VENDOR_ID_C                      (180)
#define LIN_AR_RELEASE_MAJOR_VERSION_C       (4)
#define LIN_AR_RELEASE_MINOR_VERSION_C       (4)
#define LIN_AR_RELEASE_REVISION_VERSION_C    (0)
#define LIN_SW_MAJOR_VERSION_C               (2)
#define LIN_SW_MINOR_VERSION_C               (3)
#define LIN_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and LIN header file are of the same vendor */
#if (LIN_VENDOR_ID_C != LIN_MLD_VENDOR_ID)
#error "Lin.c and Lin.h have different vendor ids"
#endif

/* Check if source file and LIN header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_C != LIN_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_C != LIN_MLD_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_C != LIN_MLD_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Lin.c and Lin.h are different"
#endif

/* Check if source file and LIN header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_C != LIN_MLD_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_C != LIN_MLD_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_C != LIN_MLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lin.c and Lin.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"
/**
 * @brief          LIN SDU buffer.
 */
LIN_VAR static uint8 Lin_LocSduBuffAddrs[LIN_CHANNEL_USED_NUM][LIN_CONST_MAX_FRAME_BYTES_NUM];

/**
 * @brief          LIN driver state variable.
 */
LIN_VAR static uint8 Lin_LocDrvState;

/**
 * @brief          LIN driver states array for all channels.
 */
LIN_VAR Lin_DrvStateType Lin_ChStates[LIN_CHANNEL_USED_NUM];

#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"/*memory map finish*/

#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"
/**
 * @brief          LIN global configuration pointer
 */
LIN_VAR static const Lin_ConfigType * Lin_LocCfgPtr;

#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"/*memory map finish*/
/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                                           MCAL API
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
/**
 * @brief            This function checks if a wakeup has occurred on the addressed LIN channel.
 * @details          This function identifies if the addressed LIN channel
 *                   has been woken up by the LIN bus transceiver. It checks
 *                   the wake up flag from the addressed LIN channel which
 *                   must be in sleep mode and have the wake up signal.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval E_NOT_OK  If the LIN Channel is not valid or
 *                   LIN driver is not initialized or
 *                   the addressed LIN Channel is not
 *                   in sleep state.
 * @retval E_OK      LIN Channel is in sleep mode
 */
LIN_FUNC Std_ReturnType Lin_CheckWakeup (uint8 Channel)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if (LIN_INIT != Lin_LocDrvState)
    {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* LIN module is not initialized yet */
        /* [SWS_Lin_00107]
         If development error detection for the LIN module is enabled: if the function Lin_CheckWakeup
         is called before the LIN module was initialized, the function Lin_CheckWakeup shall raise the
         development error LIN_E_UNINIT. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID, Channel,
                               (uint8)LIN_SID_CHECK_WAKEUP, LIN_E_UNINIT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Lin_LocCfgPtr->LinChCount <= Channel)
    {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* The channel parameter is invalid */
        /* [SWS_Lin_00251]
         If default error detection for the LIN module is enabled: if the channel parameter is invalid,
         the function Lin_CheckWakeup shall raise the default error LIN_E_INVALID_CHANNEL and return
         with E_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_CHECK_WAKEUP,LIN_E_INVALID_CHANNEL);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Default return value */
        RetVal = E_OK;
        /* Check sleep mode */
        if (LIN_DRV_CH_SLEEP == Lin_ChStates[Channel])
        {
            /* Lin channel is under sleep mode */
            if (TRUE == Lin_Mld_CheckWakeup(Channel))
            {
                /* [SWS_Lin_00098]
                The function Lin_CheckWakeup shall evaluate the wakeup on the addressed LIN channel.
                When a wake-up event on the addressed LIN channel (e.g. RxD pin has constant low level)
                is detected, the function Lin_CheckWakeup shall notify the ECU State Manager module
                immediately via the EcuM_SetWakeupEvent and the Lin Interface module via */
                /* notify the ECU State Manager module WakeupEvent */
                EcuM_SetWakeupEvent(Lin_LocCfgPtr->LinChConfigPtrs[Channel].LinChEcuMWakeupSource);
                /* Report the wakeup source to LIN interface */
                LinIf_WakeupConfirmation(Lin_LocCfgPtr->LinChConfigPtrs[Channel].LinChEcuMWakeupSource);
            }
        }
        else
        {
            /* nothing to do here */
        }
    }
    return RetVal;
}

#if (LIN_MASTER_API_SUPPORT == STD_ON)
/**
 * @brief            Sends a LIN header and a LIN response, if necessary.
 * @details          The direction of the frame response (master response, slave response,
 *                   slave-to-slave communication) is provided by the PduInfoPtr.
 * @param[in]        Channel LIN channel to be addressed
 * @param[in]        PduInfoPtr Pointer to PDU containing the PID, checksum model,
 *                               response type, Dl and SDU data pointer
 * @return           Std_ReturnType
 * @retval           E_OK LIN header and response were sent successfully
 * @retval           E_NOT_OK LIN header and response were not sent successfully
 */
LIN_FUNC Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType * PduInfoPtr)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Check if LIN already initialized */
    if (LIN_INIT != Lin_LocDrvState)
    {
        /* LIN driver not initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00141]
        If default error detection for the LIN module is enabled:
        if the function Lin_GetStatus is called before the LIN module was initialized,
        the function Lin_GetStatus shall raise the default error
        LIN_E_UNINIT and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_SEND_FRAME,LIN_E_UNINIT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    /* Check if channel valid */
    else if (Lin_LocCfgPtr->LinChCount <= Channel)
    {
        /* Invalid Channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00143]
        If default error detection for the LIN module is enabled:
        if the channel parameter is invalid or the channel is inactive,
        the function Lin_GetStatus shall raise the default error
        LIN_E_INVALID_CHANNEL and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_SEND_FRAME,LIN_E_INVALID_CHANNEL);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == PduInfoPtr)
    {
        /* Invalid pointer */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_SEND_FRAME,LIN_E_PARAM_POINTER);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    else if (LIN_MASTER_MODE != Lin_LocCfgPtr->LinChConfigPtrs[Channel].LinNodeMode)
    {
        /* LIN channel is not MASTER node */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_SEND_FRAME,LIN_E_INVALID_LINNODETYPE);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    else if (LIN_DRV_CH_SLEEP == Lin_ChStates[Channel])
    {
        /* LIN channel is in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_SEND_FRAME,LIN_E_STATE_TRANSITION);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* LIN master device send header first */
        if (E_NOT_OK == Lin_Mld_SendHeader(Channel, PduInfoPtr))
        {
            /* Report production error */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                                   (uint8)LIN_SID_SEND_FRAME,LIN_E_TIMEOUT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
#if (LIN_DEM_DISABLE == STD_OFF)
            (void) Dem_SetEventStatus(Lin_LocCfgPtr->LinDemConfigPtr->EventId, DEM_EVENT_STATUS_FAILED);
#endif
        }
        else
        {
            /* Header sent successfully */
            /* Set header status to TRUE if master need to send response frame */
            if (LIN_FRAMERESPONSE_TX == PduInfoPtr->Drc)
            {
                Lin_Mld_SendResponse(Channel, PduInfoPtr);
                RetVal = (uint8)E_OK;
            }
            /* Note: need to call Lin_SendHeader() first */
            RetVal = (uint8)E_OK;
        }
    }
    return RetVal;
}

/**
 * @brief            Gets the status of the LIN driver.
 * @param[in]        Channel LIN channel to be checked
 * @param[out]       Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *                          receive buffer where the current SDU is stored.
 *
 * @return           Lin_StatusType
 *
 * @retval LIN_NOT_OK           Development or production error occurred.
 * @retval LIN_TX_OK            Successful transmission.
 * @retval LIN_TX_BUSY          Ongoing transmission (Header or Response).
 * @retval LIN_TX_HEADER_ERROR  Error happens on header transmission.
 * @retval LIN_TX_ERROR         Error happens on transmission.
 * @retval LIN_RX_OK            Reception of correct response.
 * @retval LIN_RX_BUSY          Ongoing reception.
 * @retval LIN_RX_ERROR         Error happens on reception.
 * @retval LIN_RX_NO_RESPONSE   No response byte has been received so far.
 * @retval LIN_OPERATIONAL      Normal operation.
 * @retval LIN_CH_SLEEP         Sleep mode operation.
 *
 */
LIN_FUNC Lin_StatusType Lin_GetStatus(uint8 Channel, uint8 ** Lin_SduPtr)
{
    Lin_StatusType RetVal = LIN_NOT_OK;
    Lin_DrvStateType LinChannelState;
    /* Check if LIN already initialized */
    if (LIN_INIT != Lin_LocDrvState)
    {
        /* LIN driver not initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00141]
        If default error detection for the LIN module is enabled:
        if the function Lin_GetStatus is called before the LIN module was initialized,
        the function Lin_GetStatus shall raise the default error
        LIN_E_UNINIT and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GET_STATUS,LIN_E_UNINIT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = LIN_NOT_OK;
    }
    /* Check if channel valid */
    else if (Lin_LocCfgPtr->LinChCount <= Channel)
    {
        /* Invalid Channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00143]
        If default error detection for the LIN module is enabled:
        if the channel parameter is invalid or the channel is inactive,
        the function Lin_GetStatus shall raise the default error
        LIN_E_INVALID_CHANNEL and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GET_STATUS,LIN_E_INVALID_CHANNEL);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = LIN_NOT_OK;
    }
    else if (NULL_PTR == Lin_SduPtr)
    {
        /* Invalid SduPtr */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00144]
        If default error detection for the LIN module is enabled:
        the function Lin_GetStatus shall check the parameter Lin_SduPtr for not being
        a NULL pointer. If Lin_SduPtr is a NULL pointer, the function Lin_GetStatus
        shall raise the default error LIN_E_PARAM_POINTER and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GET_STATUS,LIN_E_PARAM_POINTER);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = LIN_NOT_OK;
    }
    else if (LIN_MASTER_MODE != Lin_LocCfgPtr->LinChConfigPtrs[Channel].LinNodeMode)
    {
        /* LIN channel is not MASTER node */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GET_STATUS,LIN_E_INVALID_LINNODETYPE);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = LIN_NOT_OK;
    }
    else
    {
        LinChannelState = Lin_ChStates[Channel];
        /* Convert LIN channel state to LIN Status */
        switch(LinChannelState)
        {
        case LIN_DRV_CH_OPERATIONAL:
            /* LIN channel is processing frame */
            *Lin_SduPtr = Lin_LocSduBuffAddrs[Channel];
            RetVal = Lin_Mld_HardwareGetStatus(Channel, Lin_LocSduBuffAddrs[Channel]);
            break;
        case LIN_DRV_CH_SLEEP_PENDING:
            Lin_ChStates[Channel] = LIN_DRV_CH_SLEEP;
            RetVal = LIN_CH_SLEEP;
            break;
        default:
            /* LIN_DRV_CH_SLEEP */
            RetVal = LIN_CH_SLEEP;
            break;
        }
    }
    return RetVal;
}

/**
 * @brief            The service instructs the driver to transmit a go-to-sleep-command on the addressed LIN channel.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval E_OK      Sleep command has been accepted
 * @retval E_NOT_OK: Sleep command has not been accepted, development or production error occurred
 */
LIN_FUNC Std_ReturnType Lin_GoToSleep (uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Check if LIN already initialized */
    if (LIN_INIT != Lin_LocDrvState)
    {
        /* LIN driver not initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00141]
        If default error detection for the LIN module is enabled:
        if the function Lin_GetStatus is called before the LIN module was initialized,
        the function Lin_GetStatus shall raise the default error
        LIN_E_UNINIT and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GO_TO_SLEEP,LIN_E_UNINIT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    /* Check if channel valid */
    else if (Lin_LocCfgPtr->LinChCount <= Channel)
    {
        /* Invalid Channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00143]
        If default error detection for the LIN module is enabled:
        if the channel parameter is invalid or the channel is inactive,
        the function Lin_GetStatus shall raise the default error
        LIN_E_INVALID_CHANNEL and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GO_TO_SLEEP,LIN_E_INVALID_CHANNEL);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    else if (LIN_MASTER_MODE != Lin_LocCfgPtr->LinChConfigPtrs[Channel].LinNodeMode)
    {
        /* LIN channel is not MASTER node */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GO_TO_SLEEP,LIN_E_INVALID_LINNODETYPE);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    else if (LIN_DRV_CH_SLEEP == Lin_ChStates[Channel])
    {
        /* Channel already under sleep mode */
        RetVal = E_OK;
    }
    else
    {
        if ((uint8)E_NOT_OK == Lin_Mld_GoToSleep(Channel))
        {
            /* Report production error */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                                   (uint8)LIN_SID_GO_TO_SLEEP,LIN_E_TIMEOUT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
#if (LIN_DEM_DISABLE == STD_OFF)
            (void) Dem_SetEventStatus(Lin_LocCfgPtr->LinDemConfigPtr->EventId, DEM_EVENT_STATUS_FAILED);
#endif
        }
        else
        {
            RetVal = E_OK;
        }
        /* [SWS_Lin_00266]
        The function Lin_GoToSleep shall set the channel state to LIN_CH_SLEEP_PENDING, even in
        case of an erroneous transmission of the go-to-sleep-command. */
        Lin_ChStates[Channel] = LIN_DRV_CH_SLEEP_PENDING;
    }
    return RetVal;
}
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */

/**
 * @brief            Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection
 *                   and optionally sets the LIN hardware unit to reduced power operation
 *                   mode (if supported by HW).
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval           E_OK      Command has been accepted
 * @retval           E_NOT_OK  Command has not been accepted, development or production error occurred
 */
LIN_FUNC Std_ReturnType Lin_GoToSleepInternal (uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Check if LIN already initialized */
    if (LIN_INIT != Lin_LocDrvState)
    {
        /* LIN driver not initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00141]
        If default error detection for the LIN module is enabled:
        if the function Lin_GetStatus is called before the LIN module was initialized,
        the function Lin_GetStatus shall raise the default error
        LIN_E_UNINIT and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GO_TO_SLEEP_INTERNAL,LIN_E_UNINIT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    /* Check if channel valid */
    else if (Lin_LocCfgPtr->LinChCount <= Channel)
    {
        /* Invalid Channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00143]
        If default error detection for the LIN module is enabled:
        if the channel parameter is invalid or the channel is inactive,
        the function Lin_GetStatus shall raise the default error
        LIN_E_INVALID_CHANNEL and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_GO_TO_SLEEP_INTERNAL,LIN_E_INVALID_CHANNEL);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
    }
    else if (LIN_DRV_CH_SLEEP == Lin_ChStates[Channel])
    {
        /* Channel already under sleep mode */
        RetVal = E_OK;
    }
    else
    {
        if ((uint8)E_NOT_OK == Lin_Mld_GoToSleepInternal(Channel))
        {
            /* Report production error */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                                   (uint8)LIN_SID_GO_TO_SLEEP_INTERNAL,LIN_E_TIMEOUT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
#if (LIN_DEM_DISABLE == STD_OFF)
            (void) Dem_SetEventStatus(Lin_LocCfgPtr->LinDemConfigPtr->EventId, DEM_EVENT_STATUS_FAILED);
#endif
        }
        else
        {
            /* Update LIN channel state */
            Lin_ChStates[Channel] = LIN_DRV_CH_SLEEP;
            RetVal = E_OK;
        }
    }
    return RetVal;
}

/**
 * @brief            Initializes the LIN module.
 * @param[in]        Config Pointer to LIN driver configuration set.
 * @return           void
 */
LIN_FUNC void Lin_Init (const Lin_ConfigType * Config)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    /* Check if LIN is under uninitialized state */
    if (LIN_UNINIT != Lin_LocDrvState)
    {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00105]
        If default error detection for the Lin module is enabled:
        the function Lin_Init shall check the Lin driver for being in the state LIN_UNINIT.
        If the Lin driver is not in the state LIN_UNINIT, the function Lin_Init shall
        raise the default error LIN_E_STATE_TRANSITION. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,LIN_INSTANCE_ALL_ID,
                               (uint8)LIN_SID_INIT,LIN_E_STATE_TRANSITION);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    if((Std_ReturnType)E_OK == RetVal)
    {
        /* Check Config for not being a null pointer */
#if (LIN_FIXED_PB_CONFIG == STD_ON)
        if (NULL_PTR != Config)
        {
            LIN_UNUSED_PARAM(Config); /* To avoid compiler warning */
        }
        Lin_LocCfgPtr = &Lin_PBPreCompileConfig;
#else /* LIN_FIXED_PB_CONFIG == STD_OFF */
        if (NULL_PTR == Config)
        {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void) Det_ReportError((uint16)LIN_MODULE_ID,LIN_INSTANCE_ALL_ID,
                                   (uint8)LIN_SID_INIT,LIN_E_INVALID_POINTER);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Lin_LocCfgPtr = Config;
        }
#endif /* LIN_FIXED_PB_CONFIG == STD_ON */
    }
#if (LIN_FRAME_TIMEOUT_DISABLE == STD_OFF)  /* timeout update*/
#if (LIN_IP_UART == STD_ON)
    if((Std_ReturnType)E_OK == RetVal)
    {
        Gpt_StopTimer(Lin_LocCfgPtr->LinTimerSourceId);
        Gpt_EnableNotification(Lin_LocCfgPtr->LinTimerSourceId);
        Gpt_StartTimer(Lin_LocCfgPtr->LinTimerSourceId, Lin_LocCfgPtr->LinTimerClockRef / LIN_CONST_GPT_500US_DIVISOR);
    }
#endif
#endif
    if((Std_ReturnType)E_OK == RetVal)
    {
        Lin_Mld_SetInstMap(Lin_LocCfgPtr->LinInstMapPtr);
        for (uint8 Index = 0U; Index < (uint8)LIN_CHANNEL_USED_NUM; ++Index)
        {
            for (uint8 LinDataLengthLoop = 0U; LinDataLengthLoop < LIN_CONST_MAX_FRAME_BYTES_NUM; ++LinDataLengthLoop)
            {
                Lin_LocSduBuffAddrs[Index][LinDataLengthLoop] = (uint8)0U;
            }
            /* Hardware driver init */
            Lin_Mld_InitChannel(Index, Lin_LocCfgPtr);
            /* Set LIN channel state to default LIN_DRV_CH_SLEEP */
            Lin_ChStates[Index] = LIN_DRV_CH_SLEEP;
            /* Map configured hardware channels to logical channels */
        }
        /* Update LIN status */
        Lin_LocDrvState = LIN_INIT;
    }
}

#if (LIN_DEINIT_API_SUPPORT == STD_ON)
/**
 * @brief            Initializes the LIN module.
 * @return           void
 */
LIN_FUNC void Lin_DeInit (void)
{
    uint8 Index;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    /* Check if LIN is under uninitialized state */
    if (LIN_INIT != Lin_LocDrvState)
    {
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /*  If default error detection for the Lin module is enabled: the function Lin_DeInit shall
            check the Lin driver for being in the state LIN_INIT. If the Lin driver is not in
            the state LIN_UNINIT, the function Lin_Init shall raise the default error
            LIN_E_STATE_TRANSITION. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,LIN_INSTANCE_ALL_ID,
                               (uint8)LIN_SID_DEINIT,LIN_E_STATE_TRANSITION);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        for (Index = 0U; Index < (uint8)LIN_CHANNEL_USED_NUM; ++Index)
        {
            if(LIN_DRV_CH_SLEEP != Lin_ChStates[Index])
            {
                /* Channel is not in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Invalid pointer */
                (void) Det_ReportError((uint16)LIN_MODULE_ID,Index,
                                       (uint8)LIN_SID_DEINIT,LIN_E_STATE_TRANSITION);
#endif  /* LIN_DEV_ERROR_DETECT == STD_ON */
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    if((Std_ReturnType)E_OK == RetVal)
    {
#if (LIN_FRAME_TIMEOUT_DISABLE == STD_OFF)  /* timeout update*/
#if (LIN_IP_UART == STD_ON)
        Gpt_StopTimer(Lin_LocCfgPtr->LinTimerSourceId);
#endif
#endif
        for (Index = 0U; Index < (uint8)LIN_CHANNEL_USED_NUM; ++Index)
        {
            Lin_Mld_DeInitChannel(Index);
            Lin_ChStates[Index] = LIN_DRV_UNINIT;
        }
        Lin_LocCfgPtr = NULL_PTR;
        Lin_LocDrvState = LIN_UNINIT;
    }
}
#endif /* LIN_DEINIT_API_SUPPORT == STD_ON */

/**
 * @brief            Generates a wake up pulse and sets the channel state to LIN_DRV_CH_OPERATIONAL.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval E_OK      Wake-up request has been accepted
 * @retval E_NOT_OK  Wake-up request has not been accepted, development or production error occurred
 */
LIN_FUNC Std_ReturnType Lin_Wakeup (uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Check if LIN already initialized */
    if (LIN_INIT != Lin_LocDrvState)
    {
        /* LIN driver not initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00141]
        If default error detection for the LIN module is enabled:
        if the function Lin_GetStatus is called before the LIN module was initialized,
        the function Lin_GetStatus shall raise the default error
        LIN_E_UNINIT and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_WAKEUP,LIN_E_UNINIT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }
    /* Check if channel valid */
    else if (Lin_LocCfgPtr->LinChCount <= Channel)
    {
        /* Invalid Channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00143]
        If default error detection for the LIN module is enabled:
        if the channel parameter is invalid or the channel is inactive,
        the function Lin_GetStatus shall raise the default error
        LIN_E_INVALID_CHANNEL and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_WAKEUP,LIN_E_INVALID_CHANNEL);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }
    else if (LIN_DRV_CH_SLEEP != Lin_ChStates[Channel])
    {
        /* LIN channel is in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00140]
        If default error detection for the LIN module is enabled:
        the function Lin_Wakeup shall raise the default error
        LIN_E_STATE_TRANSITION if the LIN channel state-machine
        is not in the state LIN_CH_SLEEP. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_WAKEUP,LIN_E_STATE_TRANSITION);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }
    else
    {
        /* Call driver functions */
        Lin_Mld_Wakeup(Channel);
        /* Update LIN channel status */
        RetVal = (uint8)E_OK;
    }
    return RetVal;
}

/**
 * @brief            Sets the channel state to LIN_DRV_CH_OPERATIONAL without generating a wake up pulse.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval E_OK      Wake-up request has been accepted
 * @retval E_NOT_OK  Wake-up request has not been accepted
 */
LIN_FUNC Std_ReturnType Lin_WakeupInternal (uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Check if LIN already initialized */
    if (LIN_INIT != Lin_LocDrvState)
    {
        /* LIN driver not initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00141]
        If default error detection for the LIN module is enabled:
        if the function Lin_GetStatus is called before the LIN module was initialized,
        the function Lin_GetStatus shall raise the default error
        LIN_E_UNINIT and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_WAKEUP_INTERNAL,LIN_E_UNINIT);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }
    /* Check if channel valid */
    else if (Lin_LocCfgPtr->LinChCount <= Channel)
    {
        /* Invalid Channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00143]
        If default error detection for the LIN module is enabled:
        if the channel parameter is invalid or the channel is inactive,
        the function Lin_GetStatus shall raise the default error
        LIN_E_INVALID_CHANNEL and return LIN_NOT_OK. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_WAKEUP_INTERNAL,LIN_E_INVALID_CHANNEL);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }
    else if (LIN_DRV_CH_SLEEP != Lin_ChStates[Channel])
    {
        /* LIN channel is in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Lin_00140]
        If default error detection for the LIN module is enabled:
        the function Lin_Wakeup shall raise the default error
        LIN_E_STATE_TRANSITION if the LIN channel state-machine
        is not in the state LIN_CH_SLEEP. */
        (void) Det_ReportError((uint16)LIN_MODULE_ID,Channel,
                               (uint8)LIN_SID_WAKEUP_INTERNAL,LIN_E_STATE_TRANSITION);
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }
    else
    {
        /* Call driver function */
        Lin_Mld_WakeupInternal(Channel);
        /* Update LIN channel status */
        RetVal = (uint8)E_OK;
    }
    return RetVal;
}


#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

