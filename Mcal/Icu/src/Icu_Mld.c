/*
* @file    Icu_Mld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Mld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif
/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0488 Rule 18.4: The +, -, += and -= operators sho uld not be applied to anexpression of pointer type
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Icu.h"
#include "Std_Types.h"
#include "SchM_Icu.h"
#include "Icu_Mld.h"
#include "OsIf.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_MLD_VENDOR_ID_C                      (180)
#define ICU_MLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ICU_MLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define ICU_MLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define ICU_MLD_SW_MAJOR_VERSION_C               (2)
#define ICU_MLD_SW_MINOR_VERSION_C               (3)
#define ICU_MLD_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU_MLD header file are of the same vendor */
#if (ICU_MLD_VENDOR_ID_C != ICU_MLD_VENDOR_ID)
#error "Icu_Mld.c and Icu_Mld.h have different vendor ids"
#endif

/* Check if source file and ICU_MLD header file are of the same Autosar version */
#if ((ICU_MLD_AR_RELEASE_MAJOR_VERSION_C != ICU_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_MLD_AR_RELEASE_MINOR_VERSION_C != ICU_MLD_AR_RELEASE_MINOR_VERSION) || \
     (ICU_MLD_AR_RELEASE_REVISION_VERSION_C != ICU_MLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Mld.c and Icu_Mld.h are different"
#endif

/* Check if source file and ICU_MLD header file are of the same Software version */
#if ((ICU_MLD_SW_MAJOR_VERSION_C != ICU_MLD_SW_MAJOR_VERSION) || \
     (ICU_MLD_SW_MINOR_VERSION_C != ICU_MLD_SW_MINOR_VERSION) || \
     (ICU_MLD_SW_PATCH_VERSION_C != ICU_MLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Mld.c and Icu_Mld.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_CLEARED_32
#include "Icu_MemMap.h"
ICU_VAR Icu_ChannelInfoType Icu_gChannelInfo[ICU_MAX_CHANNEL];
#define ICU_STOP_SEC_VAR_CLEARED_32
#include "Icu_MemMap.h"
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/

#if (ICU_ETMR_USED == STD_ON)
static inline void Icu_Mld_EnableNotificationHandle(Icu_MeasurementModeType IcuSignalMode, uint16 ChannelIndex)
{
    switch (IcuSignalMode)
    {
        case ICU_MODE_SIGNAL_EDGE_DETECT:
#if (ICU_EDGE_DETECT_API == STD_ON)
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_EnableEdgeDetectionNotification, ChannelIndex);
#else
            Icu_Lld_Etmr_EnableEdgeDetectionNotification(ChannelIndex);
#endif
#endif
            break;
        case ICU_MODE_SIGNAL_MEASUREMENT:
            Icu_gChannelInfo[ChannelIndex].IsNotificationEnable = TRUE;
            break;
        case ICU_MODE_TIMESTAMP:
#if (ICU_TIMESTAMP_API == STD_ON)
            Etmr_Icu_TimeStampInfo[ChannelIndex].IsNotificationEnable = TRUE;
#endif
            break;
        default:
            /*nothing to do*/
            break;
    }
}
static inline void Icu_Mld_DisableNotificationHandle(Icu_MeasurementModeType IcuSignalMode, uint16 ChannelIndex)
{
    switch (IcuSignalMode)
    {
        case ICU_MODE_SIGNAL_EDGE_DETECT:
            Etmr_Icu_gEdgeNotification[ChannelIndex].IsNotificationEnable = FALSE;
            break;
        case ICU_MODE_SIGNAL_MEASUREMENT:
            Icu_gChannelInfo[ChannelIndex].IsNotificationEnable = FALSE;
            break;
        case ICU_MODE_TIMESTAMP:
#if (ICU_TIMESTAMP_API == STD_ON)
            Etmr_Icu_TimeStampInfo[ChannelIndex].IsNotificationEnable = FALSE;
#endif
            break;
        default:
            /*nothing to do*/
            break;
    }
}
#endif
/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

ICU_FUNC static uint16 IcuChannelToHwIndex_Mld(uint16 Channel)
{
    Icu_ConfigType const *ConfigPtr = Icu_gConfigPtr;

    uint16 ChannelIndex = (uint16)ConfigPtr->IcuChannelCount;
    uint16 ChannelCount = 0;
    for (ChannelCount = 0; ChannelCount < ChannelIndex; ++ChannelCount)
    {
        if (ConfigPtr->ChannelConfigPtr[ChannelCount].IcuChannelId == Channel)
        {
            break;
        }
    }
    return ChannelCount;
}

ICU_FUNC void Icu_Mld_Init(void)
{
#if (ICU_ETMR_USED == STD_ON)
    if (Icu_gConfigPtr->IcuEtmrConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Etmr_Init);
#else
        Icu_Lld_Etmr_Init();
#endif
    }
#endif

#if (ICU_MPWM_USED == STD_ON)
    if (Icu_gConfigPtr->IcuMpwmConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Mpwm_Init);
#else
        Icu_Lld_Mpwm_Init();
#endif
    }
#endif

#if (ICU_PORT_USED == STD_ON)
    if (Icu_gConfigPtr->IcuPortConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Port_Init);
#else
        Icu_Lld_Port_Init();
#endif
    }
#endif

#if (ICU_ACMP_USED == STD_ON)
    if (Icu_gConfigPtr->IcuLpCmpConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Cmp_Init);
#else
        Icu_Lld_Cmp_Init();
#endif
    }
#endif
}
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
ICU_FUNC void Icu_Mld_StartSignalMeasurement(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_StartSignalMeasurement, ChannelIndex);
#else
            Icu_Lld_Etmr_StartSignalMeasurement(ChannelIndex);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
            Icu_Lld_Mpwm_StartSignalMeasurement(ChannelIndex);
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}

ICU_FUNC void Icu_Mld_StopSignalMeasurement(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_StopSignalMeasurement, ChannelIndex);
#else
            Icu_Lld_Etmr_StopSignalMeasurement(ChannelIndex);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_StopSignalMeasurement, ChannelIndex);
#else
            Icu_Lld_Mpwm_StopSignalMeasurement(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
#endif
#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
ICU_FUNC void Icu_Mld_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType *DutyCycleValues)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call2params(Icu_Lld_Etmr_GetDutyCycleValues, ChannelIndex, DutyCycleValues);
#else
            Icu_Lld_Etmr_GetDutyCycleValues(ChannelIndex, DutyCycleValues);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call2params(Icu_Lld_Mpwm_GetDutyCycleValues, ChannelIndex, DutyCycleValues);
#else
            Icu_Lld_Mpwm_GetDutyCycleValues(ChannelIndex, DutyCycleValues);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
#endif
#if (ICU_GET_INPUT_STATE_API == STD_ON)
ICU_FUNC Icu_InputStateType Icu_Mld_GetInputState(Icu_ChannelType InChannel)
{
    Icu_InputStateType ReturnValue = ICU_IDLE;
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)InChannel);

    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp) /* NOSONAR */
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:      /* NOSONAR */
#if (ICU_ENABLE_USER_MODE == STD_ON)
            ReturnValue = (Icu_InputStateType)OsIf_Trusted_Call_Return1param(Icu_Lld_Etmr_GetInputState, ChannelIndex);
#else
            ReturnValue = Icu_Lld_Etmr_GetInputState(ChannelIndex);
#endif
            break;
#endif
#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:      /* NOSONAR */
#if (ICU_ENABLE_USER_MODE == STD_ON)
            ReturnValue = OsIf_Trusted_Call_Return1param(Icu_Lld_Mpwm_GetInputState, ChannelIndex);
#else
            ReturnValue = Icu_Lld_Mpwm_GetInputState(ChannelIndex);
#endif
            break;
#endif
        default:    /* NOSONAR */
            /*nothing to do*/
            break;
    }

    return ReturnValue;
}
#endif

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
ICU_FUNC Icu_ValueType Icu_Mld_GetTimeElapsed(Icu_ChannelType Channel)
{
    Icu_ValueType ReturnValue = 0;
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            ReturnValue = OsIf_Trusted_Call_Return1param(Icu_Lld_Etmr_GetTimeElapsed, ChannelIndex);
#else
            ReturnValue = Icu_Lld_Etmr_GetTimeElapsed(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
    return ReturnValue;
}
#endif

ICU_FUNC void Icu_Mld_DisableNotification(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);

    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
            Icu_Mld_DisableNotificationHandle(Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode, ChannelIndex);
            break;
#endif

#if (ICU_PORT_USED == STD_ON)
        case ICU_PORT:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Port_DisableNotification, ChannelIndex);
#else
            Icu_Lld_Port_DisableNotification((uint8)ChannelIndex);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_DisableNotification, ChannelIndex);
#else
            Icu_Lld_Mpwm_DisableNotification(ChannelIndex);
#endif
            break;
#endif

#if (ICU_ACMP_USED == STD_ON)
        case ICU_LPCMP:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Cmp_DisableNotification, ChannelIndex);
#else
            Icu_Lld_Cmp_DisableNotification((uint8)ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}

ICU_FUNC void Icu_Mld_EnableNotification(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);

    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
            Icu_Mld_EnableNotificationHandle(Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode, ChannelIndex);
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_EnableNotification, ChannelIndex);
#else
            Icu_Lld_Mpwm_EnableNotification(ChannelIndex);
#endif
            break;
#endif

#if (ICU_PORT_USED == STD_ON)
        case ICU_PORT:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Port_EnableNotification, ChannelIndex);
#else
            Icu_Lld_Port_EnableNotification((uint8)ChannelIndex);
#endif
            break;
#endif

#if (ICU_ACMP_USED == STD_ON)
        case ICU_LPCMP:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Cmp_EnableNotification, ChannelIndex);
#else
            Icu_Lld_Cmp_EnableNotification((uint8)ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}

#if (ICU_DE_INIT_API == STD_ON)
ICU_FUNC void Icu_Mld_DeInit(void)
{
#if (ICU_ETMR_USED == STD_ON)
    if (Icu_gConfigPtr->IcuEtmrConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Etmr_DeInit);
#else
        Icu_Lld_Etmr_DeInit();
#endif
    }
#endif

#if (ICU_PORT_USED == STD_ON)
    if (Icu_gConfigPtr->IcuPortConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Port_DeInit);
#else
        Icu_Lld_Port_DeInit();
#endif
    }
#endif

#if (ICU_MPWM_USED == STD_ON)
    if (Icu_gConfigPtr->IcuMpwmConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Mpwm_DeInit);
#else
        Icu_Lld_Mpwm_DeInit();
#endif
    }
#endif

#if (ICU_ACMP_USED == STD_ON)
    if (Icu_gConfigPtr->IcuLpCmpConfigPtr != NULL_PTR)
    {
#if (ICU_ENABLE_USER_MODE == STD_ON)
        OsIf_Trusted_Call(Icu_Lld_Cmp_DeInit);
#else
        Icu_Lld_Cmp_DeInit();
#endif
    }
#endif
}
#endif
#if (ICU_TIMESTAMP_API == STD_ON)
ICU_FUNC void Icu_Mld_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType *BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call4params(Icu_Lld_Etmr_StartTimestamp, ChannelIndex, BufferPtr, BufferSize, NotifyInterval);
#else
            Icu_Lld_Etmr_StartTimestamp(ChannelIndex, BufferPtr, BufferSize, NotifyInterval);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call4params(Icu_Lld_Mpwm_StartTimestamp, ChannelIndex, BufferPtr, BufferSize, NotifyInterval);
#else
            Icu_Lld_Mpwm_StartTimestamp(ChannelIndex, BufferPtr, BufferSize, NotifyInterval);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
#endif
ICU_FUNC void Icu_Mld_StopTimestamp(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_TIMESTAMP_API == STD_ON)
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_StopTimestamp, ChannelIndex);
#else
            Icu_Lld_Etmr_StopTimestamp(ChannelIndex);
#endif
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_TIMESTAMP_API == STD_ON)
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_StopTimestamp, ChannelIndex);
#else
            Icu_Lld_Mpwm_StopTimestamp(ChannelIndex);
#endif
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}

#if (ICU_TIMESTAMP_API == STD_ON)
ICU_FUNC Icu_IndexType Icu_Mld_GetTimestampIndex(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    Icu_IndexType ReturnValue = 0U;
    /* The function Icu_GetTimestampIndex shall read the
       timestamp index of the given channel, which is the next to be written.
       Trace : SWS_Icu_00071 */
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
            ReturnValue = Etmr_Icu_TimeStampInfo[ChannelIndex].TimestampIndex;
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            ReturnValue = OsIf_Trusted_Call_Return1param(Icu_Lld_Mpwm_GetTimestampIndex, ChannelIndex);
#else
            ReturnValue = Icu_Lld_Mpwm_GetTimestampIndex(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
    return ReturnValue;
}
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)
ICU_FUNC void Icu_Mld_EnableEdgeCount(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_EnableEdgeCount, ChannelIndex);
#else
            Icu_Lld_Etmr_EnableEdgeCount(ChannelIndex);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_EnableEdgeCount, ChannelIndex);
#else
            Icu_Lld_Mpwm_EnableEdgeCount(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}

ICU_FUNC void Icu_Mld_DisableEdgeCount(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_DisableEdgeCount, ChannelIndex);
#else
            Icu_Lld_Etmr_DisableEdgeCount(ChannelIndex);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_DisableEdgeCount, ChannelIndex);
#else
            Icu_Lld_Mpwm_DisableEdgeCount(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
ICU_FUNC void Icu_Mld_ResetEdgeCount(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    switch (Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
            Icu_gChannelInfo[ChannelIndex].EdgeNumber = 0U;
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_ResetEdgeCount, ChannelIndex);
#else
            Icu_Lld_Mpwm_ResetEdgeCount(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
Icu_EdgeNumberType Icu_Mld_GetEdgeNumbers(Icu_ChannelType Channel)
{
    Icu_EdgeNumberType ReturnValue = 0U;
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;    /*PRQA S 0488*/

    switch (ChannelConfigPtr->IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
            ReturnValue = Icu_gChannelInfo[ChannelIndex].EdgeNumber;
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            ReturnValue = OsIf_Trusted_Call_Return1param(Icu_Lld_Mpwm_GetEdgeNumbers, ChannelIndex);
#else
            ReturnValue = Icu_Lld_Mpwm_GetEdgeNumbers(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
    return (Icu_EdgeNumberType)ReturnValue;
}
#endif
ICU_FUNC void Icu_Mld_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;    /*PRQA S 0488*/

    switch (ChannelConfigPtr->IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call2params(Icu_Lld_Etmr_SetActivationCondition, ChannelIndex, Activation);
#else
            Icu_Lld_Etmr_SetActivationCondition(ChannelIndex, Activation);
#endif
            break;
#endif

#if (ICU_PORT_USED == STD_ON)
        case ICU_PORT:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call2params(Icu_Lld_Port_SetActivationCondition, ChannelIndex, Activation);
#else
            Icu_Lld_Port_SetActivationCondition((uint8)ChannelIndex, Activation);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call2params(Icu_Lld_Mpwm_SetActivationCondition, ChannelIndex, Activation);
#else
            Icu_Lld_Mpwm_SetActivationCondition(ChannelIndex, Activation);
#endif
            break;
#endif

#if (ICU_ACMP_USED == STD_ON)
        case ICU_LPCMP:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call2params(Icu_Lld_Cmp_SetActivationCondition, ChannelIndex, Activation);
#else
            Icu_Lld_Cmp_SetActivationCondition((uint8)ChannelIndex, Activation);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
ICU_FUNC void Icu_Mld_SetSleepMode(const Icu_ChannelConfigType *WkuChannelConfig)
{
    switch (WkuChannelConfig->IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
            /* Etmr Not Support Sleep Mode in wakeup*/
            break;
#endif

#if (ICU_PORT_USED == STD_ON)
        case ICU_PORT:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Port_SetSleepMode, WkuChannelConfig);
#else
            Icu_Lld_Port_SetSleepMode(WkuChannelConfig);
#endif
            break;
#endif

#if (ICU_ACMP_USED == STD_ON)
        case ICU_LPCMP:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Cmp_SetSleepMode, WkuChannelConfig);
#else
            Icu_Lld_Cmp_SetSleepMode(WkuChannelConfig);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
ICU_FUNC void Icu_Mld_SetNormalMode(const Icu_ChannelConfigType *WkuChannelConfig)
{
    switch (WkuChannelConfig->IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
            /* Etmr Not Support Sleep Mode in wakeup*/
            break;
#endif

#if (ICU_PORT_USED == STD_ON)
        case ICU_PORT:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Port_SetNormalMode, WkuChannelConfig);
#else
            Icu_Lld_Port_SetNormalMode(WkuChannelConfig);
#endif
            break;
#endif

#if (ICU_ACMP_USED == STD_ON)
        case ICU_LPCMP:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Cmp_SetNormalMode, WkuChannelConfig);
#else
            Icu_Lld_Cmp_SetNormalMode(WkuChannelConfig);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}

ICU_FUNC void Icu_Mld_EnableEdgeDetection(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;/*PRQA S 0488*/

    switch (ChannelConfigPtr->IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_EnableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Etmr_EnableEdgeDetection(ChannelIndex);
#endif
            break;
#endif

#if (ICU_PORT_USED == STD_ON)
        case ICU_PORT:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Port_EnableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Port_EnableEdgeDetection((uint8)ChannelIndex);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_EnableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Mpwm_EnableEdgeDetection(ChannelIndex);
#endif
            break;
#endif

#if (ICU_ACMP_USED == STD_ON)
        case ICU_LPCMP:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Cmp_EnableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Cmp_EnableEdgeDetection(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}
ICU_FUNC void Icu_Mld_DisableEdgeDetection(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex_Mld((uint16)Channel);
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;/*PRQA S 0488*/

    switch (ChannelConfigPtr->IcuHwIp)
    {
#if (ICU_ETMR_USED == STD_ON)
        case ICU_ETMR:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Etmr_DisableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Etmr_DisableEdgeDetection(ChannelIndex);
#endif
            break;
#endif

#if (ICU_PORT_USED == STD_ON)
        case ICU_PORT:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Port_DisableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Port_DisableEdgeDetection((uint8)ChannelIndex);
#endif
            break;
#endif

#if (ICU_MPWM_USED == STD_ON)
        case ICU_MPWM:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Mpwm_DisableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Mpwm_DisableEdgeDetection(ChannelIndex);
#endif
            break;
#endif

#if (ICU_ACMP_USED == STD_ON)
        case ICU_LPCMP:
#if (ICU_ENABLE_USER_MODE == STD_ON)
            OsIf_Trusted_Call1param(Icu_Lld_Cmp_DisableEdgeDetection, ChannelIndex);
#else
            Icu_Lld_Cmp_DisableEdgeDetection(ChannelIndex);
#endif
            break;
#endif

        default:
            /*nothing to do*/
            break;
    }
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Icu_Mld.c */

