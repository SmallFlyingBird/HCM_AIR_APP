/**
 * @file    Lin_Mld.c
 * @version V2.3.0
 *
 * @brief   AUTOSAR Lin Driver Interface
 * @details API implementation for LIN driver
 *
 * @addtogroup LIN_DRIVER
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

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Lin_Cfg.h"
#if (LIN_IP_LINFLEXD == STD_ON)
#include "Lin_Lld.h"
#endif
#if (LIN_IP_UART == STD_ON)
#include "Lin_Lld_Uart.h"
#endif
#include "Lin_Mld.h"
#if (LIN_IP_UART == STD_ON)
#include "Gpt.h"
#endif
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
#include "OsIf.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_MLD_VENDOR_ID_C                      (180)
#define LIN_MLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define LIN_MLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define LIN_MLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define LIN_MLD_SW_MAJOR_VERSION_C               (2)
#define LIN_MLD_SW_MINOR_VERSION_C               (3)
#define LIN_MLD_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#if (LIN_IP_LINFLEXD == STD_ON)
/* Check if source file and LIN header file are of the same vendor */
#if (LIN_MLD_VENDOR_ID_C != LIN_LLD_VENDOR_ID)
#error "Lin_Mld.c have different vendor ids"
#endif

/* Check if source file and LIN header file are of the same Autosar version */
#if ((LIN_MLD_AR_RELEASE_MAJOR_VERSION_C != LIN_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_MLD_AR_RELEASE_MINOR_VERSION_C != LIN_LLD_AR_RELEASE_MINOR_VERSION) || \
     (LIN_MLD_AR_RELEASE_REVISION_VERSION_C != LIN_LLD_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Lin_Mld.c are different"
#endif

/* Check if source file and LIN header file are of the same Software version */
#if ((LIN_MLD_SW_MAJOR_VERSION_C != LIN_LLD_SW_MAJOR_VERSION) || \
     (LIN_MLD_SW_MINOR_VERSION_C != LIN_LLD_SW_MINOR_VERSION) || \
     (LIN_MLD_SW_PATCH_VERSION_C != LIN_LLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lin_Mld.c are different"
#endif
#endif /* (LIN_IP_LINFLEXD == STD_ON) */

#if (LIN_IP_UART == STD_ON)
/* Check if source file and LIN header file are of the same vendor */
#if (LIN_MLD_VENDOR_ID_C != LIN_LLD_UART_VENDOR_ID)
#error "Lin_Mld.c have different vendor ids"
#endif

/* Check if source file and LIN header file are of the same Autosar version */
#if ((LIN_MLD_AR_RELEASE_MAJOR_VERSION_C != LIN_LLD_UART_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_MLD_AR_RELEASE_MINOR_VERSION_C != LIN_LLD_UART_AR_RELEASE_MINOR_VERSION) || \
     (LIN_MLD_AR_RELEASE_REVISION_VERSION_C != LIN_LLD_UART_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Lin_Mld.c are different"
#endif

/* Check if source file and LIN header file are of the same Software version */
#if ((LIN_MLD_SW_MAJOR_VERSION_C != LIN_LLD_UART_SW_MAJOR_VERSION) || \
     (LIN_MLD_SW_MINOR_VERSION_C != LIN_LLD_UART_SW_MINOR_VERSION) || \
     (LIN_MLD_SW_PATCH_VERSION_C != LIN_LLD_UART_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lin_Mld.c are different"
#endif
#endif /* (LIN_IP_UART == STD_ON) */

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (LIN_MASTER_API_SUPPORT == STD_ON)
LOCAL_INLINE Lin_StatusType Lin_Mld_LocGetFrameState(const uint8 Channel, uint8* LinSduPtr);
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */
/*==================================================================================================
 *                                     LOCAL INLINE FUNCTION
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
#if (LIN_MASTER_API_SUPPORT == STD_ON)
/**
 * @brief            Gets the status of the LIN frame state when LIN status is idle.
 * @details          This function returns the state of the current transmission, reception or
 *                   operation status.
 *                   If the reception of a Slave response was successful then this service provides
 *                   a pointer to the buffer where the data is stored.
 * @param[in]        Channel LIN channel to be addressed
 * @param[out]       LinSduPtr Pointer to point a shadow SDU stored buffer or memory mapped LIN
 *                      hardware receive buffer
 * @return           Lin_StatusType
 * @retval LIN_NOT_OK           Development or production error occurred.
 * @retval LIN_TX_OK            Successful transmission.
 * @retval LIN_TX_HEADER_ERROR  Error happens on header transmission.
 * @retval LIN_TX_ERROR         Error happens on transmission.
 * @retval LIN_RX_OK            Reception of correct response.
 * @retval LIN_RX_ERROR         Error happens on reception.
 * @retval LIN_RX_NO_RESPONSE   No response byte has been received so far.
 * @retval LIN_OPERATIONAL      Normal operation.
 */
LIN_FUNC LOCAL_INLINE Lin_StatusType Lin_Mld_LocGetFrameState(const uint8 Channel, uint8* LinSduPtr)
{
    Lin_StatusType RetVal = LIN_NOT_OK;
    Lin_DrvErrorType ErrStates;
    Lin_DrvStateType FrameStates;
#if (LIN_IP_LINFLEXD == STD_ON)
    boolean WurqDoneState;
    ErrStates = Lin_Lld_GetFrameErrStates(Channel);
    FrameStates = Lin_Lld_GetFrameStates(Channel);
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    WurqDoneState = (boolean)OsIf_Trusted_Call_Return1param(Lin_Lld_GetWurqDoneStates, Channel);
#else
    WurqDoneState = Lin_Lld_GetWurqDoneStates(Channel);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
    boolean BuffNotEmpty = FALSE;
    BuffNotEmpty = Lin_Lld_Uart_GetRxEmptyState(Channel);
    ErrStates = Lin_Lld_Uart_GetFrameErrStates(Channel);
    FrameStates = Lin_Lld_Uart_GetFrameStates(Channel);
#endif
    /* Check frame error status */
    switch(ErrStates)
    {
    case LIN_DRV_NOISE_ERROR:
    case LIN_DRV_CHECKSUM_ERROR:
    case LIN_DRV_FRAMING_ERROR:
    case LIN_DRV_OVERRUN_ERROR:
        RetVal = LIN_RX_ERROR;
        break;
#if (LIN_IP_UART == STD_ON)
    case LIN_DRV_ID_PARITY_ERROR:
    case LIN_DRV_BREAK_FIELD_ERROR:
    case LIN_DRV_SYNCH_FIELD_ERROR:
    case LIN_DRV_HEADER_FRAMING_ERROR:
        RetVal = LIN_TX_HEADER_ERROR;
        break;
#endif
    case LIN_DRV_NO_ERROR:
        /* return frame status */
        switch (FrameStates)
        {
        case LIN_DRV_CH_TX_COMPLETE:
        case LIN_DRV_CH_STS_HEADER_SENT:
            RetVal = LIN_TX_OK;
            break;
        case LIN_DRV_CH_RX_COMPLETE:
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Lin_Lld_CopyData, Channel, LinSduPtr);
#else
            Lin_Lld_CopyData(Channel, LinSduPtr);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Lin_Lld_Uart_CopyData, Channel, LinSduPtr);
#else
            Lin_Lld_Uart_CopyData(Channel, LinSduPtr);
#endif
#endif
            RetVal = LIN_RX_OK;
            break;
#if (LIN_IP_LINFLEXD == STD_ON)
        case LIN_DRV_CH_NOT_READY:
            if(TRUE == WurqDoneState)
            {
                RetVal = LIN_OPERATIONAL;
                Lin_Lld_SetDrvReady(Channel);
            }
            else
            {
                RetVal = LIN_NOT_OK;
            }
            break;
#endif
        default:
            /* LIN_DRV_CH_READY */
            RetVal = LIN_OPERATIONAL;
            break;
        }
        break;
#if (LIN_FRAME_TIMEOUT_DISABLE == STD_OFF)
    case LIN_DRV_TIMEOUT_ERROR:
#if (LIN_IP_LINFLEXD == STD_ON)
        RetVal = LIN_RX_NO_RESPONSE;
#endif
#if (LIN_IP_UART == STD_ON)
        if (TRUE == BuffNotEmpty)
        {
            /* Timeout happens when LIN hardware already received some data */
            RetVal = LIN_RX_ERROR;
        }
        else
        {
            /* Timeout happens when LIN hardware received no data */
            RetVal = LIN_RX_NO_RESPONSE;
        }
#endif
        break;
#endif
    default:    /*LIN_DRV_BIT_ERROR*/
        RetVal = LIN_TX_ERROR;
        break;
    }
    return RetVal;
}
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
LIN_FUNC void Lin_Mld_SetInstMap(const uint8 * LinInstMapPtr)
{
#if (LIN_IP_LINFLEXD == STD_ON)
    Lin_Lld_SetInstMap(LinInstMapPtr);
#endif
#if (LIN_IP_UART == STD_ON)
    Lin_Lld_Uart_SetInstMap(LinInstMapPtr);
#endif
}

LIN_FUNC void Lin_Mld_InitChannel(const uint8 Channel, const Lin_ConfigType * LinCfgPtr)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call2params(Lin_Lld_InitChannel, Channel, LinCfgPtr);
#else
    Lin_Lld_InitChannel(Channel, LinCfgPtr);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call2params(Lin_Lld_Uart_InitChannel, Channel, LinCfgPtr);
#else
    Lin_Lld_Uart_InitChannel(Channel, LinCfgPtr);
#endif
#endif
}

#if (LIN_DEINIT_API_SUPPORT == STD_ON)
LIN_FUNC void Lin_Mld_DeInitChannel(const uint8 Channel)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Lin_Lld_DeInitChannel, Channel);
#else
    Lin_Lld_DeInitChannel(Channel);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Lin_Lld_Uart_DeInitChannel, Channel);
#else
    Lin_Lld_Uart_DeInitChannel(Channel);
#endif
#endif
}
#endif /* LIN_DEINIT_API_SUPPORT == STD_ON */

LIN_FUNC void Lin_Mld_Wakeup(const uint8 Channel)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Lin_Lld_Wakeup, Channel);
#else
    Lin_Lld_Wakeup(Channel);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Lin_Lld_Uart_Wakeup, Channel);
#else
    Lin_Lld_Uart_Wakeup(Channel);
#endif
#endif
}
/**
 * @brief            Wakeup LIN Channel
 * @details          This  and put LIN channel into LIN_DRV_CH_OPERATIONAL state.
 * @param[in]        Channel LIN channel.
 * @return           void.
 */
LIN_FUNC void Lin_Mld_WakeupInternal(const uint8 Channel)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Lin_Lld_WakeupInternal, Channel);
#else
    Lin_Lld_WakeupInternal(Channel);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Lin_Lld_Uart_WakeupInternal, Channel);
#else
    Lin_Lld_Uart_WakeupInternal(Channel);
#endif
#endif
}

LIN_FUNC boolean Lin_Mld_CheckWakeup(const uint8 Channel)
{
    boolean RetVal;
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    RetVal = (boolean)OsIf_Trusted_Call_Return1param(Lin_Lld_CheckWakeup, Channel);
#else
    RetVal = Lin_Lld_CheckWakeup(Channel);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    RetVal = OsIf_Trusted_Call_Return1param(Lin_Lld_Uart_CheckWakeup, Channel);
#else
    RetVal = Lin_Lld_Uart_CheckWakeup(Channel);
#endif
#endif
    return RetVal;
}

LIN_FUNC Std_ReturnType Lin_Mld_GoToSleepInternal(const uint8 Channel)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    Std_ReturnType RetVal = OsIf_Trusted_Call_Return1param(Lin_Lld_GoToSleepInternal, Channel);
#else
    Std_ReturnType RetVal = Lin_Lld_GoToSleepInternal(Channel);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    Std_ReturnType RetVal = OsIf_Trusted_Call_Return1param(Lin_Lld_Uart_GoToSleepInternal, Channel);
#else
    Std_ReturnType RetVal =  Lin_Lld_Uart_GoToSleepInternal(Channel);
#endif
#endif
    return RetVal;
}

#if (LIN_MASTER_API_SUPPORT == STD_ON)
LIN_FUNC Std_ReturnType Lin_Mld_GoToSleep(const uint8 Channel)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    Std_ReturnType RetVal = OsIf_Trusted_Call_Return1param(Lin_Lld_SendGoToSleep, Channel);
#else
    Std_ReturnType RetVal = Lin_Lld_SendGoToSleep(Channel);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    Std_ReturnType RetVal = OsIf_Trusted_Call_Return1param(Lin_Lld_Uart_SendGoToSleep, Channel);
#else
    Std_ReturnType RetVal = Lin_Lld_Uart_SendGoToSleep(Channel);
#endif
#endif
    return RetVal;
}

LIN_FUNC Std_ReturnType Lin_Mld_SendHeader(const uint8 Channel, const Lin_PduType* PduInfoPtr)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    Std_ReturnType RetVal = OsIf_Trusted_Call_Return2param(Lin_Lld_SendHeader, Channel, PduInfoPtr);
#else
    Std_ReturnType RetVal = Lin_Lld_SendHeader(Channel, PduInfoPtr);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    Std_ReturnType RetVal = OsIf_Trusted_Call_Return2param(Lin_Lld_Uart_SendHeader, Channel, PduInfoPtr);
#else
    Std_ReturnType RetVal = Lin_Lld_Uart_SendHeader(Channel, PduInfoPtr);
#endif
#endif
    return RetVal;
}

LIN_FUNC void Lin_Mld_SendResponse(const uint8 Channel, const Lin_PduType* PduInfoPtr)
{
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call2params(Lin_Lld_SendResponse, Channel, PduInfoPtr);
#else
    Lin_Lld_SendResponse(Channel, PduInfoPtr);
#endif
#endif
#if (LIN_IP_UART == STD_ON)
    Lin_Lld_Uart_SendResponse(Channel, PduInfoPtr);
#endif
}

LIN_FUNC Lin_StatusType Lin_Mld_HardwareGetStatus(const uint8 Channel, uint8 * LinSduPtr)
{
    Lin_Drv_HwStatusType LinHwStatus;
    Lin_StatusType RetVal = LIN_NOT_OK;
#if (LIN_IP_LINFLEXD == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    LinHwStatus = (Lin_Drv_HwStatusType)OsIf_Trusted_Call_Return1param(Lin_Lld_GetLinState, Channel);
#else
    LinHwStatus = Lin_Lld_GetLinState(Channel);
#endif
    Lin_DrvCommandType LinDrvCommand = Lin_Lld_GetTxHeaderComands(Channel);
#endif
#if (LIN_IP_UART == STD_ON)
#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    LinHwStatus = (Lin_Drv_HwStatusType)OsIf_Trusted_Call_Return1param(Lin_Lld_Uart_GetLinState, Channel);
#else
    LinHwStatus = Lin_Lld_Uart_GetLinState(Channel);
#endif
    Lin_DrvCommandType LinDrvCommand = Lin_Lld_Uart_GetTxHeaderComands(Channel);
#endif
    switch(LinHwStatus)
    {
    case LIN_DRV_HW_BREAK:
    case LIN_DRV_HW_BREAK_DELIMITER:
    case LIN_DRV_HW_SYNC_FIELD:
    case LIN_DRV_HW_ID_FIELD:
    case LIN_DRV_HW_HEADER_FIELD:
        RetVal = LIN_TX_BUSY;
        break;
    case LIN_DRV_HW_DATA_FIELD:
    case LIN_DRV_HW_CHECKSUM_FIELD:
        if(LIN_DRV_TX_SLAVE_RES_CMD == LinDrvCommand)
        {
            RetVal = LIN_RX_BUSY;
        }
        else
        {
            RetVal = LIN_TX_BUSY;
        }
        break;
    case LIN_DRV_HW_IDLE_MODE:
        RetVal = Lin_Mld_LocGetFrameState(Channel, LinSduPtr);
        break;
    default:
        /* LIN_DRV_HW_IDLE_MODE, LIN_DRV_HW_WAKEUP_FIELD */
        break;
    }
    return RetVal;
}
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

