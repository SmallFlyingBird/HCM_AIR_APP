/*
 * @file    Icu.h
 * @version
 *
 * @brief   AUTOSAR Port module interface
 * @details API implementation for ICU driver
 *
 * @addtogroup ICU_MODULE
 *
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Icu
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
/**
 *     @file
 *
 *     @addtogroup icu Icu Driver
 *
 */

#include "Platform_Types.h"
#ifdef __cplusplus
extern "C"
{
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Icu_Cfg.h"
#include "Icu.h"
#include "Icu_Mld.h"
#include "SchM_Icu.h"
#include "Det.h"

/*==================================================================================================
 *                                   FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID_C                      (0xB4)
#define ICU_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ICU_AR_RELEASE_MINOR_VERSION_C       (4)
#define ICU_AR_RELEASE_REVISION_VERSION_C    (0)
#define ICU_SW_MAJOR_VERSION_C               (2)
#define ICU_SW_MINOR_VERSION_C               (3)
#define ICU_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_VENDOR_ID)
#error "Icu.c and Icu.h have different vendor ids"
#endif

/* Check if source file and ICU header file are of the same Autosar version */
#if (( ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
      ( ICU_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION) || \
      ( ICU_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu.c and Icu.h are different"
#endif

/* Check if source file and ICU header file are of the same Software version */
#if (( ICU_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION) || \
      ( ICU_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION) || \
      ( ICU_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu.h are different"
#endif
/****************************************************************************************/
/* Check if source file and ICU_BASE header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_BASE_VENDOR_ID)
#error "Icu.c and Icu_Base.h have different vendor ids"
#endif

/* Check if source file and ICU_BASE header file are of the same Autosar version */
#if (( ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_BASE_AR_RELEASE_MAJOR_VERSION) || \
      ( ICU_AR_RELEASE_MINOR_VERSION_C != ICU_BASE_AR_RELEASE_MINOR_VERSION) || \
      ( ICU_AR_RELEASE_REVISION_VERSION_C != ICU_BASE_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu.c and Icu_Base.h are different"
#endif

/* Check if source file and ICU_BASE header file are of the same Software version */
#if (( ICU_SW_MAJOR_VERSION_C != ICU_BASE_SW_MAJOR_VERSION) || \
      ( ICU_SW_MINOR_VERSION_C != ICU_BASE_SW_MINOR_VERSION) || \
      ( ICU_SW_PATCH_VERSION_C != ICU_BASE_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu_Base.h are different"
#endif
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#if (ICU_FIXED_PB_CONFIG == STD_ON)
#define ICU_UNUSED_PARAM(parma) ((void)parma)
#endif
/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
typedef enum
{
    ICU_UNINIT,
    ICU_INIT_OK,
} Icu_InitStateType;

typedef enum
{
    ICU_FUNCTION_MODE_STOPPED,
    ICU_FUNCTION_MODE_RUNNING,
} Icu_FunctionModeStateType;

/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/

/*==================================================================================================
 *                                          VARIATES
==================================================================================================*/

#define ICU_START_SEC_VAR_CLEARED_8
#include "Icu_MemMap.h"
/** @brief Stores actual state and configuration of ICU Channels. */
ICU_VAR Icu_ChannelStateType Icu_WKUChannelState[ICU_WKUP_PORT_MAX];/*PRQA S 1504*/

#define ICU_STOP_SEC_VAR_CLEARED_8
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_32
#include "Icu_MemMap.h"
/** @brief Saves the current Icu mode. */
#if (ICU_SET_MODE_API == STD_ON)
ICU_VAR static Icu_ModeType Icu_CurrentMode = ICU_MODE_NORMAL;
#endif
#define ICU_STOP_SEC_VAR_INIT_32
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"
#if (ICU_TIMESTAMP_API == STD_ON)
ICU_VAR static Icu_FunctionModeStateType Icu_FunctionModeState[ICU_MAX_CHANNEL]; /*> @brief Stores actual state and configuration of ICU Channels. */
#endif
/*> @brief Saves the current Icu mode. */
#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"
/**
 * @brief Port initializes state variable
 */
#define ICU_START_SEC_VAR_INIT_32
#include "Icu_MemMap.h"

ICU_VAR static Icu_InitStateType IcuInitState = ICU_UNINIT;

#define ICU_STOP_SEC_VAR_INIT_32
#include "Icu_MemMap.h"


#define ICU_START_SEC_VAR_INIT_32
#include "Icu_MemMap.h"

#if (ICU_FIXED_PB_CONFIG == STD_ON)
extern const Icu_ConfigType Icu_PreCompileConfig;
ICU_VAR Icu_ConfigType const *Icu_gConfigPtr = &Icu_PreCompileConfig;
#else
extern const Icu_ConfigType Icu_Config;
ICU_VAR Icu_ConfigType const *Icu_gConfigPtr = &Icu_Config;
#endif

#define ICU_STOP_SEC_VAR_INIT_32
#include "Icu_MemMap.h"

#if (ICU_SET_MODE_API == STD_ON)
static void SetModeFunc(Icu_ChannelConfigType const *ChannelConfig, uint32 Channel, Icu_ModeType Mode);
#endif
/*==================================================================================================
 *                                   LOCAL FUNCTION DECLARATION
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

ICU_FUNC static uint16 IcuChannelToHwIndex(uint16 Channel)
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
        else
        {
            /*do nothing*/
        }
    }
    return ChannelCount;
}
ICU_FUNC static uint16 IcuChannelToWKUIndex(uint16 Channel)
{
    uint8 Index = 0U;
    uint16 PortID = 0U;
    uint16 PinID = 0U;
    uint16 WkuPinValue = 0U;
    uint16 WkuErrorMask = 0X0F00U;
    if (Icu_gConfigPtr->ChannelConfigPtr[Channel].IcuHwIp == ICU_LPCMP)
    {
        WkuPinValue = WkuErrorMask;
    }
    else
    {
        PortID = Icu_gConfigPtr->ChannelConfigPtr[Channel].IcuHwIpInstance;
        PinID = Icu_gConfigPtr->ChannelConfigPtr[Channel].IcuHwChannel;
        WkuPinValue = (uint16)(PortID << 8U) | PinID;
    }

    for (Index = 0; Index < ICU_WKUP_PORT_MAX; ++Index)
    {
        if (IcuWkupPortBuff[Index] == WkuPinValue)
        {
            break;
        }
    }
    return Index;
}


ICU_FUNC static inline void Icu_SetBitChState(uint8 Channel, Icu_ChannelStateType Mask)
{
    uint16 WkuIndex = IcuChannelToWKUIndex(Channel);
    if (WkuIndex < ICU_WKUP_PORT_MAX)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
        Icu_WKUChannelState[WkuIndex] |= Mask;
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
    }
}
ICU_FUNC static inline void Icu_ClearBitChState(uint8 Channel, Icu_ChannelStateType Mask)
{
    uint16 WkuIndex = IcuChannelToWKUIndex(Channel);
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_01();
    if (WkuIndex < ICU_WKUP_PORT_MAX)
    {
        Icu_WKUChannelState[WkuIndex] &= ((Icu_ChannelStateType)(~Mask));
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_01();
}
ICU_FUNC static inline Icu_ChannelStateType Icu_GetBitChState(Icu_ChannelType Channel, Icu_ChannelStateType Mask)
{
    uint16 WkuIndex = IcuChannelToWKUIndex((uint16)Channel);
    return (uint8)(Icu_WKUChannelState[WkuIndex] & Mask);
}
#if (ICU_SET_MODE_API == STD_ON)
#if(ICU_DEV_ERROR_DETECT == STD_ON)
ICU_FUNC static Std_ReturnType Icu_ValidateCallSetMode(Icu_ModeType Mode)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;
    boolean ChWakeupState = FALSE;

    /*Check that there is no channel that is not wake-up capable*/
    if (Mode != Icu_CurrentMode)
    {

        for (Icu_ChannelType ChannelIndex = 0U; ChannelIndex < Icu_gConfigPtr->IcuChannelCount; ++ChannelIndex)
        {
            /* Call low level function. */
            if (TRUE == Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuWakeupCapability)
            {
                if ((uint8)ICU_CHANNEL_STATE_WKUP == Icu_GetBitChState(ChannelIndex, ICU_CHANNEL_STATE_WKUP))
                {
                    ChWakeupState = TRUE;
                    break;
                }
                else
                {
                    /*do nothing*/
                }
            }
        }
        if (TRUE == ChWakeupState)
        {
            Valid = (Std_ReturnType)E_OK;
        }
        else
        {
            Valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    return Valid;
}
#endif
static void SetModeFunc(Icu_ChannelConfigType const *ChannelConfig, uint32 Channel, Icu_ModeType Mode)
{
    if (ICU_MODE_SLEEP == Mode)
    {
        if ((ICU_CHANNEL_STATE_WKUP == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_WKUP)) &&
                (Icu_CurrentMode != Mode))
        {
            Icu_Mld_SetSleepMode(ChannelConfig);
            Icu_gChannelInfo[Channel].CurrentMode = ICU_MODE_SLEEP;
        }
    }
    else
    {
        if ((Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING) == ICU_CHANNEL_STATE_RUNNING) &&
                (Icu_CurrentMode != Mode))
        {
#if(WKU_SUPPORT == STD_ON)
            Icu_Mld_SetNormalMode(ChannelConfig);
#endif
            Icu_gChannelInfo[Channel].CurrentMode = ICU_MODE_NORMAL;
        }
    }
}

#endif
/*==================================================================================================
                                        GLOBAL FUNCTIONS
==================================================================================================*/

ICU_FUNC void Icu_Init(const Icu_ConfigType *ConfigPtr)
{
#if (ICU_FIXED_PB_CONFIG == STD_ON)
    ICU_UNUSED_PARAM(ConfigPtr); /* To avoid compiler warning */
    ConfigPtr = &Icu_PreCompileConfig;
#else
    Icu_gConfigPtr = ConfigPtr;
#endif
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameters
       Trace : */
    if (NULL_PTR == ConfigPtr)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_INIT_ID, ICU_E_INIT_FAILED);
    }
    else if (ICU_UNINIT != IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_INIT_ID, ICU_E_INIT_FAILED);
    }
    else
#endif
    {

        Icu_Mld_Init();
        for (uint32 IcuChannelCount = 0; IcuChannelCount < ICU_MAX_CHANNEL; ++IcuChannelCount)
        {
            Icu_gChannelInfo[IcuChannelCount].CurrentMode = ICU_MODE_NORMAL;
        }
        IcuInitState = ICU_INIT_OK;
    }
}

#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
ICU_FUNC void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_CHANNEL_STATE_WKUP, ICU_E_ALREADY_INITIALIZED);
    }
    else
#endif
    {
        for (uint8 Index = 0; Index < Icu_gConfigPtr->IcuChannelCount; ++Index)   /* RTC\RTC_Seconds\LPTMR0\ACMP0 are not supported*/
        {
            if ((Icu_ChannelStateType)( ICU_CHANNEL_STATE_WKUP_HAPPENED) == Icu_GetBitChState(Icu_gConfigPtr->ChannelConfigPtr[Index].IcuChannelId, ICU_CHANNEL_STATE_WKUP_HAPPENED))
            {
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
                if (WakeupSource == (EcuM_WakeupSourceType)Icu_gConfigPtr->ChannelConfigPtr[Index].IcuWakeupSource)
                {
                    EcuM_SetWakeupEvent(WakeupSource);
                    Icu_ClearBitChState(Icu_gConfigPtr->ChannelConfigPtr[Index].IcuChannelId, ICU_CHANNEL_STATE_WKUP_HAPPENED);
                }
#else
                Icu_ClearBitChState(Icu_gConfigPtr->ChannelConfigPtr[Index].IcuChannelId, ICU_CHANNEL_STATE_WKUP_HAPPENED);
#endif
                break;
            }
        }
    }
}
#endif

#if (ICU_DE_INIT_API == STD_ON)

ICU_FUNC void Icu_DeInit(void)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameters
       Trace : */
    if (NULL_PTR == Icu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DEINIT_ID, ICU_E_UNINIT);
    }
    else if (ICU_UNINIT == IcuInitState)
    {
        /* The users of the Pwm module shall not call the function
           Icu_Init during a running operation.
           Trace :  SWS_Icu_00093 */

        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DEINIT_ID, ICU_E_ALREADY_INITIALIZED);
    }
    else
#endif
    {
#if (ICU_FIXED_PB_CONFIG == STD_ON)
        ICU_UNUSED_PARAM(Icu_PreCompileConfig); /* To avoid compiler warning */
#else
        (void)Icu_gConfigPtr;

#endif
        Icu_Mld_DeInit();
        for (uint32 IcuChannelCount = 0; IcuChannelCount < (ICU_MAX_CHANNEL); ++IcuChannelCount)
        {
            Icu_DisableNotification(IcuChannelCount);
        }
        IcuInitState = ICU_UNINIT;
    }
}
#endif

ICU_FUNC void Icu_DisableNotification(Icu_ChannelType Channel)/*PRQA S 1505*/
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00160 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLENOTIFICATION_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLENOTIFICATION_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_DisableNotification(Channel);
    }
}

#if (ICU_DISABLE_WAKEUP_API == STD_ON)

ICU_FUNC void Icu_DisableWakeup(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00024 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLEWAKEUP_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00059 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLEWAKEUP_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        /* The function should called after Icu_Init has been called
          Trace : SWS_Icu_00022 */
        Icu_ClearBitChState((uint8)Channel, ICU_CHANNEL_STATE_WKUP);
    }
}
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)

ICU_FUNC void Icu_EnableEdgeDetection(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLEEDGEDETECTION_ID, ICU_E_UNINIT);
    }
    else if (ICU_MAX_CHANNEL <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLEEDGEDETECTION_ID, ICU_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
        Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;/*PRQA S 0488*/
        if (TRUE == ChannelConfigPtr->IcuWakeupCapability)
        {
            Icu_SetBitChState((uint8)Channel, ICU_CHANNEL_STATE_RUNNING);
        }
        Icu_Mld_EnableEdgeDetection(Channel);
    }
}

ICU_FUNC void Icu_DisableEdgeDetection(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLEEDGEDETECTION_ID, ICU_E_UNINIT);
    }
    else if (ICU_MAX_CHANNEL <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLEEDGEDETECTION_ID, ICU_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
        Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;/*PRQA S 0488*/
        if (TRUE == ChannelConfigPtr->IcuWakeupCapability)
        {
            Icu_ClearBitChState((uint8)Channel, ICU_CHANNEL_STATE_RUNNING);
        }
        Icu_Mld_DisableEdgeDetection(Channel);
    }
}
#endif

ICU_FUNC void Icu_EnableNotification(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00160 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLENOTIFICATION_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLENOTIFICATION_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_EnableNotification(Channel);
    }
}


#if (ICU_ENABLE_WAKEUP_API == STD_ON)

ICU_FUNC void Icu_EnableWakeup(Icu_ChannelType Channel)
{

#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00155 */
    if (ICU_MAX_CHANNEL <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLEWAKEUP_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00156 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLEWAKEUP_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        /* The function should called after Icu_Init has been called
          Trace : SWS_Icu_00022 */
        Icu_SetBitChState((uint8)Channel, ICU_CHANNEL_STATE_WKUP);
    }
}
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)

ICU_FUNC void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType *DutyCycleValues)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00178 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETDUTYCYCLEVALUES_ID, ICU_E_PARAM_CHANNEL);
    }
    /* If DutyCycleValues is invalid, the function shall raise
       development error ICU_E_PARAM_POINTER
       Trace : SWS_Icu_00181 */
    else if (NULL_PTR == DutyCycleValues)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETDUTYCYCLEVALUES_ID, ICU_E_PARAM_POINTER);
    }
    /* The function Icu_GetTimeElapsed shall read the elapsed
       Signal In  [Signal Measurement, Signal Low Time], [Signal Measurement, Duty Cycle Values]
       Measurement Mode
       Trace : SWS_Icu_000084 */
    else if (ICU_MODE_SIGNAL_MEASUREMENT != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETDUTYCYCLEVALUES_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETDUTYCYCLEVALUES_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_GetDutyCycleValues(Channel, DutyCycleValues);
    }
}
#endif

#if (ICU_GET_INPUT_STATE_API == STD_ON)
ICU_FUNC Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel)
{
    Icu_InputStateType ReturnValue = ICU_IDLE;
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00171 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETINPUTSTATE_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function shall be supported the following
       IcuMeasurementMode
         - ICU_MODE_SIGNAL_EDGE_DETECT
         - ICU_MODE_SIGNAL_MEASUREMENT
       Trace : SWS_Icu_00030 */
    else if ((ICU_MODE_SIGNAL_EDGE_DETECT == Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode) ||
             (ICU_MODE_SIGNAL_MEASUREMENT != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETINPUTSTATE_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETINPUTSTATE_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        ReturnValue = Icu_Mld_GetInputState(Channel);
    }
    return ReturnValue;
}
#endif

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)

ICU_FUNC Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
    /* If development error detection is enabled and an error is
       detected this service shall return [0]
       Trace : SWS_Icu_00179 */
    Icu_ValueType ReturnValue = 0;
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00178 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETTIMEELAPSED_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function Icu_GetTimeElapsed shall read the elapsed
       Signal In  [Signal Measurement, Signal Low Time], [Signal Measurement, Signal High Time] and
       [signal Measurement, Signal Period Time]  Measurement Mode
       Trace : SWS_Icu_000081, SWS_Icu_000082, SWS_Icu_000083 */
    else if (ICU_MODE_SIGNAL_MEASUREMENT != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETTIMEELAPSED_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETTIMEELAPSED_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        ReturnValue = Icu_Mld_GetTimeElapsed(Channel);
    }
    return ReturnValue;
}
#endif

#if (ICU_EDGE_COUNT_API == STD_ON)

ICU_FUNC void Icu_ResetEdgeCount(Icu_ChannelType Channel)
{

#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00171 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_RESETEDGECOUNT_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_RESETEDGECOUNT_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_ResetEdgeCount(Channel);
    }
}

ICU_FUNC void Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00172 */
    if (((Icu_ChannelType)ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLEEDGECOUNT_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function shall be available for each ICU channel in Measurement Mode [Edge Counter]
       Trace : SWS_Icu_00074 */
    else if (ICU_MODE_EDGE_COUNTER != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLEEDGECOUNT_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_ENABLEEDGECOUNT_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_EnableEdgeCount(Channel);
    }
}

ICU_FUNC void Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00376 */
    if (((Icu_ChannelType)ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLEEDGECOUNT_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLEEDGECOUNT_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_DisableEdgeCount(Channel);
    }
}

ICU_FUNC Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
    Icu_EdgeNumberType ReturnValue = 0;
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00174 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETEDGENUMBERS_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETEDGENUMBERS_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        ReturnValue = Icu_Mld_GetEdgeNumbers(Channel);
    }
    return ReturnValue;
}
#endif

ICU_FUNC void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00043 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_SETACTIVATIONCONDITION_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function shall check the parameter Activation
       Trace : SWS_Icu_00043 */
    else if ((ICU_RISING_EDGE != Activation) && (ICU_FALLING_EDGE != Activation) &&
             (ICU_BOTH_EDGES != Activation))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_SETACTIVATIONCONDITION_ID, ICU_E_PARAM_ACTIVATION);
    }
    /* This service shall support channels which are configured for the following
       IcuMeasurementMode :
         - ICU_MODE_SIGNAL_EDGE_DETECT
         - ICU_MODE_TIMESTAMP
         - ICU_MODE_EDGE_COUNTER
       Trace : SWS_Icu_00090 */
    else if (ICU_MODE_SIGNAL_MEASUREMENT == Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_SETACTIVATIONCONDITION_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_SETACTIVATIONCONDITION_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_SetActivationCondition(Channel, Activation);
    }
}
#if (ICU_SET_MODE_API == STD_ON)
ICU_FUNC void Icu_SetMode(Icu_ModeType Mode)
{
    const Icu_ChannelConfigType *ChannelConfig = Icu_gConfigPtr->ChannelConfigPtr;

    Icu_ChannelType Channel;
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00376 */

    if ((ICU_MODE_SLEEP != Mode) && (ICU_MODE_NORMAL != Mode))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_SETMODE_ID, ICU_E_PARAM_MODE);
    }
    else if ((Std_ReturnType)E_OK != Icu_ValidateCallSetMode(Mode))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_SETMODE_ID, ICU_E_BUSY_OPERATION);
    }
    else
#endif
    {
        for (Icu_ChannelType ChannelIndex = 0U; ChannelIndex < Icu_gConfigPtr->IcuChannelCount; ++ChannelIndex)
        {
            if (TRUE == ChannelConfig->IcuWakeupCapability)
            {
                /* Channel configuration for actual ChannelIndex in this core. */
                Channel = ChannelConfig->IcuChannelId;
                SetModeFunc(ChannelConfig, Channel, Mode);
            }
            ++ChannelConfig;
        }
        Icu_CurrentMode = Mode;
    }
}
#endif
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)

ICU_FUNC void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00176 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTSIGNALMEASUREMENT_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function shall only be
       available in Measurement Mode [ICU_MODE_SIGNAL_MEASUREMENT]
       Trace : SWS_Icu_00141 */
    else if (ICU_MODE_SIGNAL_MEASUREMENT != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTSIGNALMEASUREMENT_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTSIGNALMEASUREMENT_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_StartSignalMeasurement(Channel);
    }
}

ICU_FUNC void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00177 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STOPSIGNALMEASUREMENT_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function shall only be
       available in Measurement Mode [ICU_MODE_SIGNAL_MEASUREMENT]
       Trace : SWS_Icu_00144 */
    else if (ICU_MODE_SIGNAL_MEASUREMENT != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STOPSIGNALMEASUREMENT_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STOPSIGNALMEASUREMENT_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_Mld_StopSignalMeasurement(Channel);
    }
}
#endif

#if (ICU_TIMESTAMP_API == STD_ON)

ICU_FUNC void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType *BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00163 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == BufferPtr)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_POINTER);
    }
    /* The function Icu_StartTimestamp shall raise the error
       if BufferSize is invalid
       Trace : SWS_Icu_00108 */
    else if (0U == BufferSize)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_BUFFER_SIZE);
    }
    /* The function shall check the parameter NotifyInterval for validity
       and raise the error ICU_E_PARAM_NOTIFY_INTERVAL if the parameter
       NotifyInterval is [0].
       Trace : SWS_Icu_00354 */
    else if ((uint16)0 == NotifyInterval)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_NOTIFY_INTERVAL);
    }
    /* The function shall only be available in
       Measurement Mode [ICU_MODE_TIMESTAMP].
       Trace : SWS_Icu_00066 */
    else if (ICU_MODE_TIMESTAMP != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTTIMESTAMP_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STARTTIMESTAMP_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        Icu_FunctionModeState[ChannelIndex] = ICU_FUNCTION_MODE_RUNNING;
        Icu_Mld_StartTimestamp(Channel, BufferPtr, BufferSize, NotifyInterval);
    }
}

ICU_FUNC void Icu_StopTimestamp(Icu_ChannelType Channel)
{
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00164 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STOPTIMESTAMP_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function shall only be available in
       Measurement Mode [ICU_MODE_TIMESTAMP].
       Trace : SWS_Icu_00165 */
    else if (ICU_MODE_TIMESTAMP != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STOPTIMESTAMP_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_STOPTIMESTAMP_ID, ICU_E_UNINIT);
    }
    else 
#endif
    /* The function shall raise runtime error
       ICU_E_NOT_STARTED if Channel is not active (has not started or is already
       stopped)
       Trace : SWS_Icu_00166 */
    if (ICU_FUNCTION_MODE_RUNNING != Icu_FunctionModeState[ChannelIndex])
    {
        (void)Det_ReportRuntimeError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                                     ICU_STOPTIMESTAMP_ID, ICU_E_NOT_STARTED);
    }
    else
    {
        Icu_FunctionModeState[ChannelIndex] = ICU_FUNCTION_MODE_STOPPED;
        Icu_Mld_StopTimestamp(Channel);
    }
}
ICU_FUNC void Icu_GetVersionInfo(Std_VersionInfoType *Versioninfo)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Versioninfo)
    {
        /* Report ICU_E_PARAM_POINTER DET if service called with          \
           NULL_PTR                                                       \
        */
        (void)Det_ReportError(
            (uint16)ICU_MODULE_ID,
            ICU_INSTANCE_ID,
            ICU_GETVERSIONINFO_ID,
            ICU_E_PARAM_VINFO);
    }
    else
#endif
    {
        Versioninfo->vendorID = (uint16)ICU_VENDOR_ID;
        Versioninfo->moduleID = (uint8)ICU_MODULE_ID;
        Versioninfo->sw_major_version = (uint8)ICU_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = (uint8)ICU_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = (uint8)ICU_SW_PATCH_VERSION;
    }
}
ICU_FUNC Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
    /* If development error detection is enabled the function
       shall return [0] if an error is detected
       Trace : SWS_Icu_00107 */
    Icu_IndexType ReturnValue = 0;
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    uint16 ChannelIndex = IcuChannelToHwIndex((uint16)Channel);
    /* The function should shall check the parameter Channel
       Trace : SWS_Icu_00169 */
    if ((Icu_ChannelType)(ICU_MAX_CHANNEL) <= Channel)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETTIMESTAMPINDEX_ID, ICU_E_PARAM_CHANNEL);
    }
    /* The function shall only be available in
       Measurement Mode [ICU_MODE_TIMESTAMP].
       Trace : SWS_Icu_00170 */
    else if (ICU_MODE_TIMESTAMP != Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuMeasurementMode)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETTIMESTAMPINDEX_ID, ICU_E_INIT_CONFIG_MEASUREMENT_MODE);
    }
    /* The function should called after Icu_Init has been called
       Trace : SWS_Icu_00022 */
    else if (ICU_UNINIT == IcuInitState)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GETTIMESTAMPINDEX_ID, ICU_E_UNINIT);
    }
    else
#endif
    {
        ReturnValue = Icu_Mld_GetTimestampIndex(Channel);
    }
    return ReturnValue;
}
#endif /* (ICU_TIMESTAMP_API == STD_ON) */
ICU_FUNC void Icu_ReportWakeup(uint32 ChannelIndex)
{
    if (ICU_CHANNEL_STATE_WKUP == Icu_GetBitChState(Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuChannelId, ICU_CHANNEL_STATE_WKUP))
    {
        Icu_SetBitChState(Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuChannelId, ICU_CHANNEL_STATE_WKUP_HAPPENED);
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        EcuM_CheckWakeup((EcuM_WakeupSourceType)Icu_gConfigPtr->ChannelConfigPtr[ChannelIndex].IcuWakeupSource);
#endif

    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

