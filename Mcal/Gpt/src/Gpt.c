/**
 * @file    Gpt.c
 * @version V2.3.0
 *
 * @brief   AUTOSAR Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr, Ptmr, Tmr, Rtc
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Types.h"
#include "Gpt_Mld.h"
#include "Gpt.h"
#if (GPT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_C                      (180)
#define GPT_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_SW_MAJOR_VERSION_C               (2)
#define GPT_SW_MINOR_VERSION_C               (3)
#define GPT_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID)
#error "Gpt.c and Gpt.h have different vendor ids"
#endif

/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt.c and Gpt.h are different"
#endif

/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt.c and Gpt.h are different"
#endif

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

extern GPT_CONST const Gpt_ConfigType Gpt_Config;

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

extern GPT_VAR Gpt_ModeType Gpt_Mode;
extern GPT_VAR Gpt_StatusType Gpt_State;

/**
 * @brief Global variable used for storing the GPT driver configuration data.
 */
GPT_VAR static const Gpt_ConfigType * Gpt_ConfigPtr = NULL_PTR;

/**
 * @brief Global variable used for indicating the current GPT driver mode.
 */
GPT_VAR Gpt_ModeType Gpt_Mode = GPT_MODE_NORMAL;

/**
 * @brief GPT initialize state
 */
GPT_VAR Gpt_StatusType Gpt_State = GPT_UNINIT;  /* PRQA S 1504 */

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       Initializes the GPT driver.
 * @param[in]   ConfigPtr Pointer to a selected configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != ConfigPtr)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_INIT,
            (uint8)GPT_E_INIT_FAILED
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
#else
    if (NULL_PTR == ConfigPtr)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_INIT,
            (uint8)GPT_E_INIT_FAILED
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
#endif
        /* If the GPT driver is not in operation mode "uninitialized",
            the function Gpt_Init shall raise the error GPT_E_ALREADY_INITIALIZED.
            Trace :  SWS_Gpt_00307 */
        if (GPT_UNINIT != Gpt_State)
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError
            (
                (uint16)GPT_MODULE_ID,
                GPT_INSTANCE_ID,
                (uint8)GPT_SID_INIT,
                (uint8)GPT_E_ALREADY_INITIALIZED
            );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
            Gpt_ConfigPtr = &Gpt_Config;
            (void)(ConfigPtr); /* To avoid compiler warning */
#else
            Gpt_ConfigPtr = ConfigPtr;
#endif

            Gpt_Mld_InitInstances(Gpt_ConfigPtr);

            /*Initialize for each channel the runtime status informations.*/
            for (uint16 ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr->UsedChannelCount; ++ChannelIndex)
            {
                /*Initialize hardware timer channel.*/
                Gpt_Mld_Init(&(*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex]);
            }

            Gpt_State = GPT_IDLE;
            /* The function Gpt_Init shall set the operation mode of the GPT driver to "normal mode".
                Trace :  SWS_Gpt_00339 */
            Gpt_Mode = GPT_MODE_NORMAL;
        }
}

#if (GPT_DEINIT_API == STD_ON)
/**
 * @brief       Deinitializes the GPT driver.
 * @return      void
 */
GPT_FUNC void Gpt_DeInit(void)
{
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_DE_INIT,
            (uint8)GPT_E_UNINIT
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        Gpt_Mld_DeInit(Gpt_ConfigPtr);
        Gpt_ConfigPtr = NULL_PTR;
        Gpt_State = GPT_UNINIT;
        Gpt_Mode = GPT_MODE_NORMAL;
    }
}
#endif /* (GPT_DEINIT_API == STD_ON) */

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief       Disables the interrupt notification for a channel (relevant in normal mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
GPT_FUNC void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    /* If the driver is not initialized, the function  Gpt_DisableNotification shall raise the error
       GPT_E_UNINIT
       Trace :  SWS_Gpt_00227 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_DISABLE_NOTIFICATION,
            (uint8)GPT_E_UNINIT
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If the parameter Channel is invalid (not within the range specified by
       configuration), the function  Gpt_DisableNotification shall raise the error
       GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00217 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_DISABLE_NOTIFICATION,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If no valid notification function is configured (GptNotification), the function
        Gpt_DisableNotification shall raise the error GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00379 */
    else if (NULL_PTR == (*Gpt_ConfigPtr->ChannelConfig)[(*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel]].NotificationPtr)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_DISABLE_NOTIFICATION,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
        Gpt_Mld_DisableNotification((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig);
    }
}

/**
 * @brief       Enables the interrupt notification for a channel (relevant in normal mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
GPT_FUNC void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    /* If the driver is not initialized, the function Gpt_EnableNotification shall raise the error
       GPT_E_UNINIT
       Trace :  SWS_Gpt_00226 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_ENABLE_NOTIFICATION,
            (uint8)GPT_E_UNINIT
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If the parameter Channel is invalid (not within the range specified by
       configuration), the function Gpt_EnableNotification shall raise the error
       GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00214 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_ENABLE_NOTIFICATION,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If no valid notification function is configured (GptNotification), the function
       Gpt_EnableNotification shall raise the error GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00377 */
    else if (NULL_PTR == (*(Gpt_ConfigPtr->ChannelConfig))[(*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel]].NotificationPtr)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_ENABLE_NOTIFICATION,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
        Gpt_Mld_EnableNotification((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig);
    }
}
#endif /* #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Disables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
GPT_FUNC void Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)

    /* If the driver is not initialized, the function Gpt_DisableWakeup shall raise the error
       GPT_E_UNINIT
       Trace :  SWS_Gpt_00229 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_DISABLE_WAKEUP,
            (uint8)GPT_E_UNINIT
        );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
    }
    /* If the parameter Channel is invalid (not within the range specified by
       configuration), the function Gpt_DisableWakeup shall raise the error
       GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00229 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_DISABLE_WAKEUP,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
        Gpt_HwTimerModuleType HwModule = (*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->InstanceType;
        if ((GPT_HW_MODULE_LPTMR != HwModule)&&(GPT_HW_MODULE_RTC != HwModule))
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError
            (
                (uint16)GPT_MODULE_ID,
                GPT_INSTANCE_ID,
                (uint8)GPT_SID_DISABLE_WAKEUP,
                (uint8)GPT_E_PARAM_CHANNEL
            );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
        }
        else
        {
            Gpt_Mld_DisableWakeup((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig);
        }
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}

/**
 * @brief       Enables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
GPT_FUNC void Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)

    /* If the driver is not initialized, the function Gpt_EnableWakeup shall raise the error
       GPT_E_UNINIT
       Trace :  SWS_Gpt_00230 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_ENABLE_WAKEUP,
            (uint8)GPT_E_UNINIT
        );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
    }
    /* If the parameter Channel is invalid (not within the range specified by
       configuration), the function Gpt_EnableWakeup shall raise the error
       GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00216 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_ENABLE_WAKEUP,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
        Gpt_HwTimerModuleType HwModule = (*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->InstanceType;
        if ((GPT_HW_MODULE_LPTMR != HwModule)&&(GPT_HW_MODULE_RTC != HwModule))
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError
            (
                (uint16)GPT_MODULE_ID,
                GPT_INSTANCE_ID,
                (uint8)GPT_SID_ENABLE_WAKEUP,
                (uint8)GPT_E_PARAM_CHANNEL
            );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
        }
        else
        {
            Gpt_Mld_EnableWakeup((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig);
        }
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}

/**
 * @brief       Sets the operation mode of the GPT.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* If the driver is not initialized, the function Gpt_SetMode shall raise the error
       GPT_E_UNINIT
       Trace :  SWS_Gpt_00228 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_SET_MODE,
            (uint8)GPT_E_UNINIT
        );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
    }
    /* The function Gpt_SetMode shall raise the error GPT_E_PARAM_MODE if the parameter Mode is invalid.
       Trace :  SWS_Gpt_00231 */
    else if ((GPT_MODE_NORMAL != Mode)&&(GPT_MODE_SLEEP != Mode))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_SET_MODE,
            (uint8)GPT_E_PARAM_MODE
        );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        Gpt_Mld_SetMode(Mode);
        Gpt_Mode = Mode;
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}

/**
 * @brief       Checks if a wakeup capable GPT channel is the source for a wakeup event and calls
 *              the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel
 *              wakeup event.
 * @param[in]   WakeupSource Information on wakeup source to be checked. The associated GPT channel
 *  can be determined from configuration data.
 * @return      void
 */
GPT_FUNC void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* If the driver is not initialized, the function Gpt_CheckWakeup shall raise the error
       GPT_E_UNINIT
       Trace :  SWS_Gpt_00325 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_CHECK_WAKEUP,
            (uint8)GPT_E_UNINIT
        );
#endif /* GPT_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        Gpt_Mld_CheckWakeup(WakeupSource);
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API == STD_ON */

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Delivers the current value of the desired GPT Predef Timer.
 * @param[in]   PredefTimer GPT Predef Timer
 * @param[out]  TimeValuePtr Pointer to time value destination data in RAM
 * @return      Std_ReturnType
 */
GPT_FUNC Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
{
    (void)PredefTimer;
    (void)TimeValuePtr;
    return (Std_ReturnType)TRUE;
}
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief       Returns the time already elapsed.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      Gpt_ValueType
 */
GPT_FUNC Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_ValueType TimeElapsed = 0U;

    /* If the driver is not initialized, the function Gpt_GetTimeElapsed shall raise the error
       GPT_E_UNINIT.
       Trace : SWS_Gpt_00222 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_GET_TIME_ELAPSED,
            (uint8)GPT_E_UNINIT
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If the parameter Channel is invalid (not within the range specified by
       configuration), the function Gpt_GetTimeElapsed shall raise the error
       GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00210 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_GET_TIME_ELAPSED,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
        TimeElapsed = Gpt_Mld_GetTimeElapsed((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig);
    }

    return TimeElapsed;
}
#endif /* (GPT_TIME_ELAPSED_API == STD_ON) */

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief       Returns the time remaining until the target time is reached.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      Gpt_ValueType
 */
GPT_FUNC Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Gpt_ValueType TimeRemaining = 0;

    /* If the driver is not initialized, the function Gpt_GetTimeRemaining shall raise the error
       GPT_E_UNINIT.
       Trace : SWS_Gpt_00223 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_GET_TIME_REMAINING,
            (uint8)GPT_E_UNINIT
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If the parameter Channel is invalid (not within the range specified by
       configuration), the function Gpt_GetTimeRemaining shall raise the error
       GPT_E_PARAM_CHANNEL.
       Trace :  SWS_Gpt_00211 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_GET_TIME_REMAINING,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
        TimeRemaining = Gpt_Mld_GetTimeRemaining((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig);
    }

    return TimeRemaining;
}
#endif /* (GPT_TIME_REMAINING_API == STD_ON) */

/**
 * @brief       Starts a timer channel.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @param[in]   Value Target time in number of ticks.
 * @return      void
 */
GPT_FUNC void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{

    /* If the driver is not initialized, the function Gpt_StartTimer shall raise the error
       GPT_E_UNINIT
       Trace :  SRS_BSW_00406 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_START_TIMER,
            (uint8)GPT_E_UNINIT
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If the parameter Channel is invalid (not within the range specified by configuration),
       the function Gpt_StartTimer shall raise the error GPT_E_PARAM_CHANNEL
       Trace :  SWS_Gpt_00212 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_START_TIMER,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* The function Gpt_StartTimer shall raise the error GPT_E_PARAM_VALUE if the
       arameter Value is "0" or not within the allowed range
       Trace :  SWS_Gpt_00218 */
    else if (((*(Gpt_ConfigPtr->ChannelConfig))[(*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel]].TickValueMax < Value) ||
             (0U == Value))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_START_TIMER,
            (uint8)GPT_E_PARAM_VALUE
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        /* If the function Gpt_StartTimer is called on a channel in state
            "running", the function shall raise the runtime error GPT_E_BUSY.
            Trace :  SWS_Gpt_00084 */
        if (GPT_STATUS_RUNNING == Gpt_Mld_GetChannelState((*(Gpt_ConfigPtr->ChannelConfig))[(*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel]].GptHwChannelConfig))
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportRuntimeError
            (
                (uint16)GPT_MODULE_ID,
                GPT_INSTANCE_ID,
                (uint8)GPT_SID_START_TIMER,
                (uint8)GPT_E_BUSY
            );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
            Gpt_Mld_StartTimer(((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig), Value);
        }
    }
}

/**
 * @brief       Stops a timer channel.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
GPT_FUNC void Gpt_StopTimer(Gpt_ChannelType Channel)
{

    /* If the driver is not initialized, the function Gpt_StopTimer shall raise the error
       GPT_E_UNINIT.
       Trace :  SWS_Gpt_00225 */
    if (GPT_UNINIT == Gpt_State)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_STOP_TIMER,
            (uint8)GPT_E_UNINIT
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    /* If the parameter Channel is invalid (not within the range specified by configuration),
       the function Gpt_StartTimer shall raise the error GPT_E_PARAM_CHANNEL
       Trace :  SWS_Gpt_00213 */
    else if ((Std_ReturnType)E_NOT_OK == Gpt_Mld_CheckChannel(Gpt_ConfigPtr, Channel))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_STOP_TIMER,
            (uint8)GPT_E_PARAM_CHANNEL
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        Gpt_HwChannelType ChannelIndex = (*(Gpt_ConfigPtr->ChannelIdToIndexMap))[Channel];
        Gpt_Mld_StopTimer((*(Gpt_ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig);
    }
}

#if (GPT_VERSION_INFO_API == STD_ON)
/**
 * @brief       Returns the version information of this module.
 * @param[out]  VersionInfo Pointer to where to store version information of this module
 * @return      none
 */
GPT_FUNC void Gpt_GetVersionInfo(Std_VersionInfoType * VersionInfo)
{
    /* If the parameter VersionInfo is NULL_PTR, the function Gpt_GetVersionInfo shall raise
       the error GPT_E_PARAM_POINTER.
       Trace :  SWS_Gpt_00338 */
    if (NULL_PTR == VersionInfo)
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)GPT_MODULE_ID,
            GPT_INSTANCE_ID,
            (uint8)GPT_SID_GET_VERSION_INFO,
            (uint8)GPT_E_PARAM_POINTER
        );
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        VersionInfo->vendorID = (uint16)GPT_VENDOR_ID;
        VersionInfo->moduleID = (uint16)GPT_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
    }
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

