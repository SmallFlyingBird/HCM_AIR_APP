/**************************************************************************************************/
/**
 * @file      : Gpt.c
 * @brief     : AUTOSAR Gpt driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Gpt
 *  @brief Gpt AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt.h"
#include "Det.h"
#include "Gpt_Drvw.h"
#include "Gpt_Irq.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_C_VENDOR_ID                   0x00B3U
#define GPT_C_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_C_AR_RELEASE_MINOR_VERSION    6U
#define GPT_C_AR_RELEASE_REVISION_VERSION 0U
#define GPT_C_SW_MAJOR_VERSION            1U
#define GPT_C_SW_MINOR_VERSION            2U
#define GPT_C_SW_PATCH_VERSION            2U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((GPT_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                       \
         (GPT_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Gpt.c and Det.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/* Check if current file and Gpt.h are of the same vendor */
#if (GPT_C_VENDOR_ID != GPT_VENDOR_ID)
    #error "Vendor ID of Gpt.c and Gpt.h are different"
#endif

/* Check if current file and Gpt header file are of the same Autosar version */
#if ((GPT_C_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) ||                           \
     (GPT_C_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION) ||                           \
     (GPT_C_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt.c and Gpt.h are different"
#endif
/* Check if current file and Gpt header file are of the same Software version */
#if ((GPT_C_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION) ||                                           \
     (GPT_C_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION) ||                                           \
     (GPT_C_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION))
    #error "Software Version of Gpt.c and Gpt.h are different"
#endif

/* Check if current file and Gpt_Drvw.h are of the same vendor */
#if (GPT_C_VENDOR_ID != GPT_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Gpt.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same Autosar
 * version */
#if ((GPT_C_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (GPT_C_AR_RELEASE_MINOR_VERSION != GPT_DRVW_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (GPT_C_AR_RELEASE_REVISION_VERSION != GPT_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same Software
 * version */
#if ((GPT_C_SW_MAJOR_VERSION != GPT_DRVW_H_SW_MAJOR_VERSION) ||                                    \
     (GPT_C_SW_MINOR_VERSION != GPT_DRVW_H_SW_MINOR_VERSION) ||                                    \
     (GPT_C_SW_PATCH_VERSION != GPT_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt.c and Gpt_Drvw.h are different"
#endif

#if (GPT_MULTICORE_ENABLED == STD_ON)
    #define Gpt_GetCoreID() (uint32) McalLib_GetCoreID()
#else
    #define Gpt_GetCoreID() ((uint32)0UL)
#endif

/**
 * @brief Defines MACRO for Det report error.
 */
#define GPT_DET_REPORT_ERROR(ServiceId, ErrorId)                                                   \
    (void)Det_ReportError((uint16)GPT_MODULE_ID, (uint8)0, (uint8)(ServiceId), (uint8)(ErrorId))

#define GPT_DET_RUNTIME_REPORT_ERROR(ServiceId, ErrorId)                                           \
    (void)Det_ReportRuntimeError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID,                    \
                                 (uint8)(ServiceId), (uint8)(ErrorId))

#define GPT_CHANNEL_ID_TO_INDEX(CoreId, Channel)                                                   \
    (*(Gpt_ConfigPtr[(CoreId)]->GptChannelIdToIndexMap))[(Channel)]

#define GPT_CHANNEL_CONFIG(CoreId, Channel)                                                        \
    (*(Gpt_ConfigPtr[(CoreId)]->GptChannelConfig))[(Channel)]
/** @} end of Private_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

#if (GPT_MULTICORE_ENABLED == STD_ON)
static const Gpt_ConfigType *Gpt_ConfigPtr[GPT_MAX_PARTITIONS];
#else
static const Gpt_ConfigType *Gpt_ConfigPtr[1U];
#endif

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 * @brief  Indicate the current Gpt driver mode.
 */
static volatile Gpt_ModeType Gpt_Mode = GPT_MODE_NORMAL;

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 * @brief   Store for each channel the time value when it is stopped.
 */
static volatile Gpt_ValueType Gpt_StopTime[GPT_HW_CHANNEL_NUM];
/**
 * @brief   Store runtime internal context of each logic channel.
 */
static Gpt_ChannelInfoType Gpt_ChannelInfo[GPT_HW_CHANNEL_NUM];

static Gpt_Drvw_HwChannelInfoType ReturnHwChannelInfo;

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_CheckChannel(uint8 ServiceId, Gpt_ChannelType Channel,
                                             uint32 GptCoreId);

LOCAL_INLINE Std_ReturnType Gpt_CheckInitialStatus(uint8 ServiceId, uint32 GptCoreId);
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_CheckInit(uint8 ServiceId, uint32 GptCoreId,
                                          const Gpt_ConfigType *ConfigPtr);
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_CheckTargetTimeValue(uint8 ServiceId, Gpt_ChannelType Channel,
                                                     Gpt_ValueType Value, uint32 GptCoreId);
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_CheckChannelStatus(uint8 ServiceId, Gpt_ChannelType Channel,
                                                   uint32 GptCoreId);
#endif

LOCAL_INLINE Std_ReturnType Gpt_CheckStartTimer(uint8 ServiceId, Gpt_ChannelType Channel,
                                                Gpt_ValueType Value, uint32 GptCoreId);

#if ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
LOCAL_INLINE Std_ReturnType Gpt_CheckNotification(uint8 ServiceId, Gpt_ChannelType Channel,
                                                  uint32 GptCoreId);
#endif

#if ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) &&               \
     (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
LOCAL_INLINE Std_ReturnType Gpt_CheckGptWakeup(uint8 ServiceId, Gpt_ChannelType Channel,
                                               uint32 GptCoreId);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
LOCAL_INLINE void Gpt_SetSleepMode(void);
LOCAL_INLINE void Gpt_SetNormalMode(void);
#endif

#if ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) &&               \
     (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
LOCAL_INLINE Std_ReturnType Gpt_CheckSetMode(uint8 ServiceId, Gpt_ModeType Mode, uint32 GptCoreId);
#endif

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_CheckPredefTimerType(Gpt_PredefTimerType PredefTimer,
                                                     uint32              GptCoreId);

LOCAL_INLINE Std_ReturnType Gpt_CheckPredefTimerPointer(const uint32 *PredefTimerPtr);
LOCAL_INLINE Std_ReturnType Gpt_CheckGetPredefTimerValue(uint8 ServiceId, uint32 GptCoreId,
                                                         const uint32 *PredefTimerPtr);
    #endif
    #if (GPT_SET_DUAL_CLOCK_MODE == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_CheckSetClockMode(uint8 ServiceId, Gpt_ClockModeType ClockMode,
                                                  uint32 GptCoreId);
    #endif
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_CheckMode(uint8 ServiceId);
    #endif
LOCAL_INLINE Gpt_Drvw_PredefTimerType Gpt_ConvertPredefTimerType(Gpt_PredefTimerType PredefTimer);
#endif

LOCAL_INLINE Gpt_ChannelType Gpt_ConvertChannelIndexToChannel(Gpt_ChannelType ChannelIndex,
                                                              uint32          GptCoreId);
LOCAL_INLINE void            Gpt_ChangeChannelStatus(Gpt_ChannelType       Channel,
                                                     Gpt_ChannelStatusType ChannelStatus);
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
LOCAL_INLINE void Gpt_ChangeNotificationStatus(Gpt_ChannelType Channel, boolean NotificationStatus);
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
LOCAL_INLINE void Gpt_ChangeWakeupEnabledStatus(Gpt_ChannelType Channel,
                                                boolean         WakeupEnableStatus);
LOCAL_INLINE void Gpt_ChangeWakeupGeneratedStatus(Gpt_ChannelType Channel,
                                                  boolean         WakeupGenerateStatus);
#endif

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function checks calls to functions that use a channel.
 *
 * @param[in]  Channel       Gpt channel Id
 * @param[in]  ServiceId     Service Id
 * @param[in]  GptCoreId        Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckChannel(uint8 ServiceId, Gpt_ChannelType Channel,
                                             uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    /* Report an error if the driver is not initialized */
    if (NULL_PTR != Gpt_ConfigPtr[GptCoreId])
    {
        /* Check that the channel is within the valid range */
        if (GPT_HW_CHANNEL_NUM > Channel)
        {
            /* Check that the channel is in use on the current core */
            if (255U == GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel))
            {
                GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_PARAM_CONFIG);
            }
            else
            {
                ReturnValue = (Std_ReturnType)E_OK;
            }
        }
        else
        {
            GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_PARAM_CHANNEL);
        }
    }
    else
    {
        GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_UNINIT);
    }

    return ReturnValue;
}
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function check the Gpt initialization pointer.
 *
 * @param[in]  ServiceId    Service Id
 * @param[in]  GptCoreId    Core Id
 * @param[in]  ConfigPtr    Pointer to a selected configuration structure.
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckInit(uint8 ServiceId, uint32 GptCoreId,
                                          const Gpt_ConfigType *ConfigPtr)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    ReturnValue = Gpt_CheckInitialStatus(ServiceId, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR == ConfigPtr)
        {
            GPT_DET_REPORT_ERROR((uint8)GPT_SID_INIT, (uint8)GPT_E_INIT_FAILED);
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
    #endif
#elif (GPT_PRECOMPILE_SUPPORT == STD_ON)
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR != ConfigPtr)
        {
            GPT_DET_REPORT_ERROR((uint8)GPT_SID_INIT, (uint8)GPT_E_INIT_FAILED);
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
    #endif
#endif
    }
    return ReturnValue;
}
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function validates the Gpt init.
 * @details    The calls for functions that uses all the channels.
 *
 * @param[in]  ServiceId    Service Id
 * @param[in]  GptCoreId       Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckInitialStatus(uint8 ServiceId, uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR != Gpt_ConfigPtr[GptCoreId])
    {
        if (GPT_SID_INIT == ServiceId)
        {
            GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_ALREADY_INITIALIZED);
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        if (GPT_SID_INIT == ServiceId)
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_UNINIT);
        }
    }
    return ReturnValue;
}
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function checks the target time value for a channel.
 *
 * @param[in]  ServiceId   Service Id
 * @param[in]  Channel     Gpt channel Id
 * @param[in]  GptCoreId   Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckTargetTimeValue(uint8 ServiceId, Gpt_ChannelType Channel,
                                                     Gpt_ValueType Value, uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    uint8          ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);

    if ((Value > GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelTickValueMax) ||
        ((Gpt_ValueType)0U == Value))
    {
        GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_PARAM_VALUE);
    }
    else
    {
        ReturnValue = (Std_ReturnType)E_OK;
    }

    return ReturnValue;
}
#endif

/**
 * @brief      This function check the caller function's channel status.
 *
 * @param[in]  ServiceId   Service Id
 * @param[in]  Channel     Gpt channel Id
 * @param[in]  GptCoreId      Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckChannelStatus(uint8 ServiceId, Gpt_ChannelType Channel,
                                                   uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON && GPT_DEV_ERROR_DETECT == STD_ON)
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Do not enable the channel in sleep mode when the wakeup function is not
     * enabled */
    if ((GPT_MODE_SLEEP == Gpt_Mode) &&
        ((boolean)FALSE == Gpt_ChannelInfo[Channel].WakeupEnabled) &&
        (GPT_SID_START_TIMER == ServiceId))
    {
        GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_INVALID_CALL);
    }
    else
    {
    #endif
#endif /* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_DEV_ERROR_DETECT ==                     \
          STD_ON) */

        if (GPT_STATUS_RUNNING == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            GPT_DET_RUNTIME_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_BUSY);
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    }
    #endif
#endif

    (void)GptCoreId;
    return ReturnValue;
}

/**
 * @brief      This function check start timer.
 *
 * @param[in]  ServiceId   Service Id
 * @param[in]  Channel     Gpt channel Id
 * @param[in]  GptCoreId   Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckStartTimer(uint8 ServiceId, Gpt_ChannelType Channel,
                                                Gpt_ValueType Value, uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckChannel(GPT_SID_START_TIMER, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif
        ReturnValue = Gpt_CheckChannelStatus(GPT_SID_START_TIMER, Channel, GptCoreId);
        if ((Std_ReturnType)E_OK == ReturnValue)
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            ReturnValue = Gpt_CheckTargetTimeValue(GPT_SID_START_TIMER, Channel, Value, GptCoreId);
            if ((Std_ReturnType)E_OK == ReturnValue)
            {
                ReturnValue = (Std_ReturnType)E_OK;
            }
            else
            {
                ReturnValue = (Std_ReturnType)E_NOT_OK;
            }
#endif
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    (void)ServiceId;
    return ReturnValue;
}

#if (GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief      This function checks the channel notification enabled.

 * @param[in]  ServiceId   Service Id
 * @param[in]  Channel     Gpt channel Id
 * @param[in]  GptCoreId      Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckNotification(uint8 ServiceId, Gpt_ChannelType Channel,
                                                  uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    ReturnValue = Gpt_CheckChannel(ServiceId, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        uint8 ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);

        if (NULL_PTR != GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptNotification)
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_PARAM_CHANNEL);
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnValue;
}
#endif

#if ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) &&               \
     (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief      This function check the channel wakeup enabled.
 *
 * @param[in]  ServiceId   Service Id
 * @param[in]  Channel     Gpt channel Id
 * @param[in]  GptCoreId   Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckGptWakeup(uint8 ServiceId, Gpt_ChannelType Channel,
                                               uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    ReturnValue = Gpt_CheckChannel(ServiceId, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        uint8 ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);

        if ((boolean)TRUE == GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptEnableWakeup)
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            GPT_DET_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_PARAM_CHANNEL);
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnValue;
}
#endif

#if ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) &&               \
     (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief      This function check the mode.
 *
 * @param[in]  ServiceId   Service Id
 * @param[in]  Channel     Gpt channel Id
 * @param[in]  GptCoreId      Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckSetMode(uint8 ServiceId, Gpt_ModeType Mode, uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    ReturnValue = Gpt_CheckInitialStatus(ServiceId, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        if ((GPT_MODE_SLEEP == Mode) || (GPT_MODE_NORMAL == Mode))
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            GPT_DET_REPORT_ERROR((uint8)GPT_SID_SET_MODE, (uint8)GPT_E_PARAM_MODE);
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnValue;
}
#endif

#if ((GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief      This function check prede timer's parameter.
 *
 * @param[in]  PredefTimer   PredefTimer type
 * @param[in]  GptCoreId        Core Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckPredefTimerType(Gpt_PredefTimerType PredefTimer,
                                                     uint32              GptCoreId)
{
    Std_ReturnType  ReturnValue = (Std_ReturnType)E_NOT_OK;
    Gpt_ChannelType Channel;

    if ((PredefTimer == GPT_PREDEF_TIMER_1US_16BIT) ||
        (PredefTimer == GPT_PREDEF_TIMER_1US_24BIT) ||
        (PredefTimer == GPT_PREDEF_TIMER_1US_32BIT) ||
        (PredefTimer == GPT_PREDEF_TIMER_100US_32BIT))
    {
        Channel = (Gpt_ChannelType)PredefTimer;
        if (NULL_PTR == ((Gpt_ConfigPtr[GptCoreId]->GptChannelPredefConfigType)[Channel]))
        {
            GPT_DET_REPORT_ERROR((uint8)GPT_SID_GET_PREDEFTIMER_VALUE,
                                 (uint8)GPT_E_PARAM_PREDEF_TIMER);
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        GPT_DET_REPORT_ERROR((uint8)GPT_SID_GET_PREDEFTIMER_VALUE, (uint8)GPT_E_PARAM_PREDEF_TIMER);
    }
    return ReturnValue;
}

/**
 * @brief      This function checks a pointer for GetPredefTimer.
 *
 * @param[in]  PredefTimerPtr    Pointer to the configuration structure of
 * predef timer.
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckPredefTimerPointer(const uint32 *PredefTimerPtr)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == PredefTimerPtr)
    {
        GPT_DET_REPORT_ERROR((uint8)GPT_SID_GET_PREDEFTIMER_VALUE, (uint8)GPT_E_PARAM_POINTER);
    }
    else
    {
        ReturnValue = (Std_ReturnType)E_OK;
    }
    return ReturnValue;
}

/**
 * @brief      This function checks a pointer for GetPredefTimer.
 *
 * @param[in]  PredefTimerPtr    Pointer to the configuration structure of
 * predef timer.
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckGetPredefTimerValue(uint8 ServiceId, uint32 GptCoreId,
                                                         const uint32 *PredefTimerPtr)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    if ((Std_ReturnType)E_OK == Gpt_CheckInitialStatus(ServiceId, GptCoreId))
    {
        if ((Std_ReturnType)E_OK == Gpt_CheckPredefTimerPointer(PredefTimerPtr))
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnValue;
}
#endif

#if (GPT_SET_DUAL_CLOCK_MODE == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function check the dual clock Mode.
 *
 * @param[in]  ClockMode  Dual clock mode.
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckSetClockMode(uint8 ServiceId, Gpt_ClockModeType ClockMode,
                                                  uint32 GptCoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    ReturnValue = Gpt_CheckInitialStatus(ServiceId, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        if ((GPT_CLOCKMODE_NORMAL != ClockMode) && (GPT_CLOCKMODE_ALTERNATE != ClockMode))
        {
            GPT_DET_REPORT_ERROR((uint8)GPT_SID_SET_CLOCK_MODE, (uint8)GPT_E_PARAM_CLOCK_MODE);
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_OK;
        }
    }
    return ReturnValue;
}
#endif

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief      This function check the Gpt mode.
 *
 * @param[in]  ServiceId  Service Id.
 *
 * @return     Std_ReturnType
 * @retval     E_OK            No error was reported.
 * @retval     E_NOT_OK        Error was reported.
 */
LOCAL_INLINE Std_ReturnType Gpt_CheckMode(uint8 ServiceId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    if (GPT_MODE_SLEEP == Gpt_Mode)
    {
        GPT_DET_RUNTIME_REPORT_ERROR((uint8)ServiceId, (uint8)GPT_E_MODE);
    }
    else
    {
        ReturnValue = (Std_ReturnType)E_OK;
    }
    return ReturnValue;
}

/**
 * @brief      Convet Gpt perdertimer type.
 *
 * @param[in]  PredefTimer Predef timer type.
 *
 * @return     Gpt_Drvw_PredefTimerType
 * @retval     Gpt predeftimer type.
 */
LOCAL_INLINE Gpt_Drvw_PredefTimerType Gpt_ConvertPredefTimerType(Gpt_PredefTimerType PredefTimer)
{
    Gpt_Drvw_PredefTimerType PredefTimerType = GPT_DRVW_PREDEF_TIMER_1US_16BIT;
    switch (PredefTimer)
    {
        case GPT_PREDEF_TIMER_1US_16BIT:
            PredefTimerType = GPT_DRVW_PREDEF_TIMER_1US_16BIT;
            break;
        case GPT_PREDEF_TIMER_1US_24BIT:
            PredefTimerType = GPT_DRVW_PREDEF_TIMER_1US_24BIT;
            break;
        case GPT_PREDEF_TIMER_1US_32BIT:
            PredefTimerType = GPT_DRVW_PREDEF_TIMER_1US_32BIT;
            break;
        case GPT_PREDEF_TIMER_100US_32BIT:
            PredefTimerType = GPT_DRVW_PREDEF_TIMER_100US_32BIT;
            break;
        default:
            PredefTimerType = GPT_DRVW_PREDEF_TIMER_1US_16BIT;
            break;
    }
    return PredefTimerType;
}
#endif

/**
 * @brief      This function converts the channel index to the corresponding
 * channel number.
 *
 * @param[in]   ChannelIndex   Channel Index
 * @param[in]   GptCoreId      Core Id
 *
 * @return     Gpt_ChannelType
 * @retval     The channel number corresponds to the channel in the core
 */
LOCAL_INLINE Gpt_ChannelType Gpt_ConvertChannelIndexToChannel(Gpt_ChannelType ChannelIndex,
                                                              uint32          GptCoreId)
{
    Gpt_ChannelType Channel = 0U;

    while (Channel < GPT_HW_CHANNEL_NUM)
    {
        if (ChannelIndex == GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel))
        {
            break;
        }
        Channel++;
    }
    return Channel;
}

/**
 * @brief     This function changes channel status at runtime.
 *
 * @param[in] ChannelStatus: ChannelStatus.
 *
 * @return    None.
 */
LOCAL_INLINE void Gpt_ChangeChannelStatus(Gpt_ChannelType       Channel,
                                          Gpt_ChannelStatusType ChannelStatus)
{
    Gpt_ChannelInfo[Channel].ChannelStatus = ChannelStatus;
}

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief     This function changes Gpt notification status at runtime.
 *
 * @param[in] NotificationStatus: Notifications whether has enabled.
 *
 * @return    None.
 */
LOCAL_INLINE void Gpt_ChangeNotificationStatus(Gpt_ChannelType Channel, boolean NotificationStatus)
{
    Gpt_ChannelInfo[Channel].NotificationEnabled = NotificationStatus;
}
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief     This function changes Gpt wakeup enabled status at runtime.
 *
 * @param[in] WakeupEnableStatus: Wakeup whether has enabled.
 *
 * @return    None.
 */
LOCAL_INLINE void Gpt_ChangeWakeupEnabledStatus(Gpt_ChannelType Channel, boolean WakeupEnableStatus)
{
    Gpt_ChannelInfo[Channel].WakeupEnabled = WakeupEnableStatus;
}

/**
 * @brief     This function changes Gpt wakeup generated status at runtime.
 *
 * @param[in] WakeupGenerateStatus: Wakeup whether has generated.
 *
 * @return    None.
 */
LOCAL_INLINE void Gpt_ChangeWakeupGeneratedStatus(Gpt_ChannelType Channel,
                                                  boolean         WakeupGenerateStatus)
{
    Gpt_ChannelInfo[Channel].WakeupGenerated = WakeupGenerateStatus;
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
/**
 * @brief     This function is related to Gpt processing of sleep mode.
 *
 * @param[in] None
 *
 * @return    None.
 */
LOCAL_INLINE void Gpt_SetSleepMode(void)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    uint32 GptCoreId = (uint32)Gpt_GetCoreID();

    Gpt_ValueType   ElapsedTime = 0U;
    Gpt_ChannelType ChannelIndex = 0U;
    Gpt_ChannelType Channel;
    ReturnHwChannelInfo.ChannelRollover = FALSE;
    ReturnHwChannelInfo.TargetTime = (Gpt_ValueType)0U;

    for (ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr[GptCoreId]->ChannelCount; ChannelIndex++)
    {
        Channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, GptCoreId);

        if (FALSE == Gpt_ChannelInfo[Channel].WakeupEnabled)
        {
            Gpt_Drvw_DisableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
            ElapsedTime = Gpt_Drvw_GetTimeElapsed(
                ((GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr)),
                &ReturnHwChannelInfo);
            if (GPT_STATUS_RUNNING == Gpt_ChannelInfo[Channel].ChannelStatus)
            {
                if ((TRUE == ReturnHwChannelInfo.ChannelRollover) &&
                    (GPT_CH_MODE_ONESHOT ==
                     GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode))
                {
                    Gpt_ChangeChannelStatus(Channel, GPT_STATUS_EXPIRED);
                }
                else
                {
                    Gpt_StopTime[Channel] = ElapsedTime;
                    Gpt_ChangeChannelStatus(Channel, GPT_STATUS_STOPPED);
                }
                Gpt_Drvw_StopTimer(
                    (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
            }
        }
        else
        {
            Gpt_Drvw_EnableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }
    }
#endif
}

/**
 * @brief     This function is related to Gpt processing of normal mode.
 *
 * @param[in] None
 *
 * @return    None.
 */
LOCAL_INLINE void Gpt_SetNormalMode(void)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    uint32 GptCoreId = (uint32)Gpt_GetCoreID();

    Gpt_ChannelType ChannelIndex = 0U;
    Gpt_ChannelType Channel;

    for (ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr[GptCoreId]->ChannelCount; ChannelIndex++)
    {
        Channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, GptCoreId);
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        if (TRUE == Gpt_ChannelInfo[Channel].NotificationEnabled)
        {
            Gpt_Drvw_EnableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }
        else
        {
    #endif
            if ((GPT_STATUS_RUNNING != Gpt_ChannelInfo[Channel].ChannelStatus) ||
                (GPT_CH_MODE_CONTINUOUS ==
                 GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode))
            {
                Gpt_Drvw_DisableInterrupt(
                    (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
            }
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        }
    #endif
    }
#endif
}
#endif

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#if (GPT_VERSION_INFO_API == STD_ON)
/**
 * @brief    This function get Gpt version information.
 *           - Service ID: 0x00U
 *           - Sync or Async: Synchronous
 *           - Reentrancy: Reentrant
 *
 * @param[out] VersionInfoPtr: Pointer to where to store the version information
 * of this module.
 *
 * @return     None
 */
void Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfoPtr)
    {
        GPT_DET_REPORT_ERROR((uint8)GPT_SID_GET_VERSION_INFO, (uint8)GPT_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID = (uint16)GPT_VENDOR_ID;
        VersionInfoPtr->moduleID = (uint16)GPT_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
    }
}
#endif

/**
 * @brief      This function initializes the Gpt driver.
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @param[in]  ConfigPtr: Pointer to a selected configuration structure.
 *
 * @return     None
 */
void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
    uint32 GptCoreId;
    uint8  InstanceIndex;
    GptCoreId = (uint32)Gpt_GetCoreID();
    Gpt_ChannelType ChannelIndex;
    Gpt_ChannelType Channel;
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    Gpt_ChannelType          PrdefTimerType;
    Gpt_Drvw_PredefTimerType ReturnPredefTimerType;
#endif
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckInit(GPT_SID_INIT, GptCoreId, ConfigPtr);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
        Gpt_ConfigPtr[GptCoreId] = Gpt_PreDefinedConfigPtr[GptCoreId];
        (void)ConfigPtr;
#else
    Gpt_ConfigPtr[GptCoreId] = ConfigPtr;
#endif
        for (InstanceIndex = 0; InstanceIndex < Gpt_ConfigPtr[GptCoreId]->InstanceCount;
             InstanceIndex++)
        {
            Gpt_Drvw_InitInstances(
                &((*(Gpt_ConfigPtr[GptCoreId]->GptInstanceConfig))[InstanceIndex]));
        }

        for (ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr[GptCoreId]->ChannelCount;
             ChannelIndex++)
        {
            Channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, GptCoreId);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
            Gpt_ChangeNotificationStatus(Channel, FALSE);
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
            Gpt_ChangeWakeupEnabledStatus(Channel, FALSE);
            Gpt_ChangeWakeupGeneratedStatus(Channel, FALSE);
#endif
            Gpt_ChangeChannelStatus(Channel, GPT_STATUS_INITIALIZED);
            Gpt_StopTime[Channel] = 0U;

            Gpt_Drvw_Init((GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
        for (PrdefTimerType = 0U; PrdefTimerType < GPT_HW_PREDEFTIMER_NUM; PrdefTimerType++)
        {
            ReturnPredefTimerType = Gpt_ConvertPredefTimerType((Gpt_PredefTimerType)PrdefTimerType);
            Gpt_Drvw_StartPredefTimer(
                (Gpt_ConfigPtr[GptCoreId]->GptChannelPredefConfigType)[PrdefTimerType],
                ReturnPredefTimerType);
        }
#endif
        Gpt_Mode = GPT_MODE_NORMAL;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

#if (GPT_DEINIT_API == STD_ON)
/**
 * @brief      This function de-initializes the Gpt driver.
 *             - Service ID: 0x02
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @return     None
 */
void Gpt_DeInit(void)
{
    Gpt_ChannelType Channel;
    Gpt_ChannelType ChannelIndex;
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    Gpt_ChannelType PrdefTimerType;
#endif
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    Std_ReturnType AllChannelStatus = (Std_ReturnType)E_OK;
    uint32         GptCoreId;
    GptCoreId = (uint32)Gpt_GetCoreID();

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckInitialStatus(GPT_SID_DEINIT, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif
        for (ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr[GptCoreId]->ChannelCount;
             ChannelIndex++)
        {
            Channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, GptCoreId);
            ReturnValue = Gpt_CheckChannelStatus(GPT_SID_DEINIT, Channel, GptCoreId);
            if ((Std_ReturnType)E_NOT_OK == ReturnValue)
            {
                AllChannelStatus = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
        if ((Std_ReturnType)E_OK == AllChannelStatus)
        {
            for (ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr[GptCoreId]->ChannelCount;
                 ChannelIndex++)
            {
                Channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, GptCoreId);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                Gpt_ChangeNotificationStatus(Channel, FALSE);
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
                Gpt_ChangeWakeupEnabledStatus(Channel, FALSE);
                Gpt_ChangeWakeupGeneratedStatus(Channel, FALSE);
#endif
                Gpt_StopTime[Channel] = 0U;
                Gpt_ChangeChannelStatus(Channel, GPT_STATUS_UNINITIALIZED);
                Gpt_Drvw_DeInit(
                    (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
            }

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
            for (PrdefTimerType = 0U; PrdefTimerType < GPT_HW_PREDEFTIMER_NUM; PrdefTimerType++)
            {
                Gpt_Drvw_StopPredefTimer(
                    (Gpt_ConfigPtr[GptCoreId]->GptChannelPredefConfigType)[PrdefTimerType]);
            }

#endif
            Gpt_ConfigPtr[GptCoreId] = NULL_PTR;
        }
        else
        {
            /* Nothing to do */
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief     This function returns the time already elapsed.
 *            - Service ID: 0x03
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the Gpt channel.
 *
 * @return    Gpt_ValueType
 * @retval    Elapsed timer value (in number of ticks).
 */
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    uint32        GptCoreId;
    uint8         ChannelIndex;
    Gpt_ValueType ReturnValue = (Gpt_ValueType)0;
    ReturnHwChannelInfo.ChannelRollover = FALSE;
    ReturnHwChannelInfo.TargetTime = (Gpt_ValueType)0U;
    GptCoreId = (uint32)Gpt_GetCoreID();
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Ret = Gpt_CheckChannel(GPT_SID_GET_TIME_ELAPSED, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == Ret)
    {
#endif
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);
        ReturnValue = Gpt_Drvw_GetTimeElapsed(
            ((GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr)),
            &ReturnHwChannelInfo);
        if (GPT_STATUS_RUNNING == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            if ((TRUE == ReturnHwChannelInfo.ChannelRollover) &&
                (GPT_CH_MODE_ONESHOT == GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode))
            {
                ReturnValue = ReturnHwChannelInfo.TargetTime;
            }
        }
        else if (GPT_STATUS_INITIALIZED == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            ReturnValue = (Gpt_ValueType)0U;
        }
        else if (GPT_STATUS_STOPPED == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            ReturnValue = Gpt_StopTime[Channel];
        }
        else if (GPT_STATUS_EXPIRED == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            ReturnValue = ReturnHwChannelInfo.TargetTime;
        }
        else
        {
            /* Nothing to do */
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return ReturnValue;
}
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief     This function returns the time remaining until the target time is
 *            reached.
 *            - Service ID: 0x04
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the Gpt channel.
 *
 * @return    Gpt_ValueType
 * @retval    Remaining timer value (in number of ticks).
 */
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    uint32 GptCoreId;
    uint8  ChannelIndex;
    ReturnHwChannelInfo.ChannelRollover = FALSE;
    ReturnHwChannelInfo.TargetTime = (Gpt_ValueType)0U;
    Gpt_ValueType ReturnValue = (Gpt_ValueType)0U;
    GptCoreId = (uint32)Gpt_GetCoreID();
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Ret = Gpt_CheckChannel(GPT_SID_GET_TIME_EMAINING, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == Ret)
    {
#endif
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);
        ReturnValue = Gpt_Drvw_GetTimeElapsed(
            ((GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr)),
            &ReturnHwChannelInfo);

        if (GPT_STATUS_RUNNING == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            if ((TRUE == ReturnHwChannelInfo.ChannelRollover) &&
                (GPT_CH_MODE_ONESHOT == GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode))
            {
                ReturnValue = (Gpt_ValueType)0U;
            }
            else
            {
                ReturnValue = ReturnHwChannelInfo.TargetTime - ReturnValue;
            }
        }
        else if (GPT_STATUS_INITIALIZED == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            ReturnValue = (Gpt_ValueType)0U;
        }
        else if (GPT_STATUS_STOPPED == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            ReturnValue = ReturnHwChannelInfo.TargetTime - Gpt_StopTime[Channel];
        }
        else if (GPT_STATUS_EXPIRED == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            ReturnValue = (Gpt_ValueType)0U;
        }
        else
        {
            /* Nothing to do */
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return ReturnValue;
}
#endif

/**
 * @brief     This function for starting a timer channel.
 *            - Service ID: 0x05
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 * @param[in] Value: Target time in number of ticks. This value is dependent on the specific GPT 
 *                   channel, the TIM (HW IP) channel should be less than or equal to 0xFFFF.
 *
 * @return    None.
 */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    uint32         GptCoreId;
    uint8          ChannelIndex;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    GptCoreId = (uint32)Gpt_GetCoreID();

    ReturnValue = Gpt_CheckStartTimer(GPT_SID_START_TIMER, Channel, Value, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);
        if (GPT_CH_MODE_ONESHOT == GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode)
        {
            Gpt_Drvw_EnableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }

        Gpt_ChangeChannelStatus(Channel, GPT_STATUS_RUNNING);
        ReturnValue = Gpt_Drvw_StartTimer(
            GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr, Value);
        if ((Std_ReturnType)E_OK != ReturnValue)
        {
            GPT_DET_RUNTIME_REPORT_ERROR((uint8)GPT_SID_START_TIMER, (uint8)GPT_E_TIMEOUT);
        }
    }
}

/**
 * @brief     This function for stopping a timer channel.
 *            - Service ID: 0x06
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    uint32        GptCoreId;
    uint8         ChannelIndex;
    Gpt_ValueType ElapsedTime;
    GptCoreId = (uint32)Gpt_GetCoreID();
    ReturnHwChannelInfo.ChannelRollover = FALSE;
    ReturnHwChannelInfo.TargetTime = (Gpt_ValueType)0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckChannel(GPT_SID_STOP_TIMER, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);

        ElapsedTime = Gpt_Drvw_GetTimeElapsed(
            ((GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr)),
            &ReturnHwChannelInfo);

        if (GPT_STATUS_RUNNING == Gpt_ChannelInfo[Channel].ChannelStatus)
        {
            Gpt_Drvw_StopTimer(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));

            if ((TRUE == ReturnHwChannelInfo.ChannelRollover) &&
                (GPT_CH_MODE_ONESHOT == GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode))
            {
                Gpt_ChangeChannelStatus(Channel, GPT_STATUS_EXPIRED);
            }
            else
            {
                Gpt_ChangeChannelStatus(Channel, GPT_STATUS_STOPPED);
                Gpt_StopTime[Channel] = ElapsedTime;
            }
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief     This function for enabling the interrupt notification for a
 *            channel (relevant in normal mode).
 *            - Service ID: 0x07
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    uint32 GptCoreId;
    uint8  ChannelIndex;
    GptCoreId = (uint32)Gpt_GetCoreID();
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckNotification(GPT_SID_ENABLE_NOTIFICATION, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);

        Gpt_ChangeNotificationStatus(Channel, TRUE);
        if (GPT_MODE_NORMAL == Gpt_Mode)
        {
            Gpt_Drvw_EnableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief     This function for disabling the interrupt notification for a
 *            channel (relevant in normal mode).
 *            - Service ID: 0x08
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    uint32 GptCoreId;
    uint8  ChannelIndex;
    GptCoreId = (uint32)Gpt_GetCoreID();
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckNotification(GPT_SID_DISABLE_NOTIFICATION, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);
        Gpt_ChangeNotificationStatus(Channel, FALSE);
        if ((GPT_MODE_NORMAL == Gpt_Mode) &&
            ((GPT_CH_MODE_CONTINUOUS ==
              GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode) ||
             (GPT_STATUS_RUNNING != Gpt_ChannelInfo[Channel].ChannelStatus)))
        {
            Gpt_Drvw_DisableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief     This function for setting the operation mode of the Gpt.
 *            - Service ID: 0x09
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Mode    operation mode :
 *                    - GPT_MODE_NORMAL: Normal operation mode of the GPT
 *                                       driver.
 *                    - GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup
 *                                      capable).
 *
 * @return    None.
 */
void Gpt_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    uint32 GptCoreId = (uint32)Gpt_GetCoreID();
#endif
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    Gpt_ChannelType          PrdefTimerType;
    Gpt_Drvw_PredefTimerType ReturnPredefTimerType;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)Mode;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
#endif
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckSetMode(GPT_SID_SET_MODE, Mode, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif
        if (GPT_MODE_SLEEP == Mode)
        {
            Gpt_SetSleepMode();
    #if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
            for (PrdefTimerType = 0U; PrdefTimerType < GPT_HW_PREDEFTIMER_NUM; PrdefTimerType++)
            {
                Gpt_Drvw_StopPredefTimer(
                    (Gpt_ConfigPtr[GptCoreId]->GptChannelPredefConfigType)[PrdefTimerType]);
            }
    #endif
            Gpt_Mode = GPT_MODE_SLEEP;
        }
        else if (GPT_MODE_NORMAL == Mode)
        {
    #if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
            if ((Gpt_ModeType)GPT_MODE_SLEEP == Gpt_Mode)
            {
                for (PrdefTimerType = 0U; PrdefTimerType < GPT_HW_PREDEFTIMER_NUM; PrdefTimerType++)
                {
                    ReturnPredefTimerType =
                        Gpt_ConvertPredefTimerType((Gpt_PredefTimerType)PrdefTimerType);
                    Gpt_Drvw_StartPredefTimer(
                        (Gpt_ConfigPtr[GptCoreId]->GptChannelPredefConfigType)[PrdefTimerType],
                        ReturnPredefTimerType);
                }
            }
    #endif
            Gpt_SetNormalMode();
            Gpt_Mode = GPT_MODE_NORMAL;
        }
        else
        {
            /* Do nothing */
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
#endif /*GPT_REPORT_WAKEUP_SOURCE*/
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief     This function for disabling the wakeup interrupt of a channel
 *            (relevant in sleep mode).
 *            - Service ID: 0x0A
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
void Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint32 GptCoreId = (uint32)Gpt_GetCoreID();
    uint8  ChannelIndex;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)Channel;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckGptWakeup(GPT_SID_DISABLE_WAKEUP, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
    #endif
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);

        Gpt_ChangeWakeupEnabledStatus(Channel, FALSE);
        if ((GPT_MODE_SLEEP == Gpt_Mode) &&
            ((GPT_CH_MODE_CONTINUOUS ==
              GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode) ||
             (GPT_STATUS_RUNNING != Gpt_ChannelInfo[Channel].ChannelStatus)))
        {
            Gpt_Drvw_DisableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
#endif /*GPT_REPORT_WAKEUP_SOURCE*/
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief     This function for enabling the wakeup interrupt  of a channel
 *            (relevant in sleep mode)
 *            - Service ID: 0x0B
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
void Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON && GPT_DEV_ERROR_DETECT == STD_ON)
    uint32         GptCoreId = (uint32)Gpt_GetCoreID();
    uint8          ChannelIndex;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)Channel;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckGptWakeup(GPT_SID_ENABLE_WAKEUP, Channel, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);

        Gpt_ChangeWakeupEnabledStatus(Channel, TRUE);

        if (GPT_MODE_SLEEP == Gpt_Mode)
        {
            Gpt_Drvw_EnableInterrupt(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
        }
    }
    #endif
#endif /*GPT_REPORT_WAKEUP_SOURCE*/
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief     The function for checking if a wakeup capable GPT channel is the
 *            source for a wakeup event.
 *            - Service ID: 0x0C
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] WakeupSource: Information on wakeup source to be checked. The
 * associated Gpt channel can be determined from configuration data.
 *
 * @return    None.
 */
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint32          GptCoreId = (uint32)Gpt_GetCoreID();
    Gpt_ChannelType Channel;
    uint32          ChannelIndex = 0U;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)WakeupSource;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Gpt_CheckInitialStatus(GPT_SID_CHECK_WAKEUP, GptCoreId);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
    #endif
        for (ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr[GptCoreId]->ChannelCount;
             ChannelIndex++)
        {
            Channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, GptCoreId);

            if (((GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptWakeupSource) == WakeupSource) &&
                (TRUE == Gpt_ChannelInfo[Channel].WakeupGenerated))
            {
                Gpt_ChangeWakeupGeneratedStatus(Channel, FALSE);

                EcuM_SetWakeupEvent(WakeupSource);

                break;
            }
        }
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief     The function delivers the current value of the desired GPT Predef
 * Timer.
 *            - Service ID: 0x0D
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in]  PredefTimer: GPT Predef Timer.
 * @param[out] TimeValuePtr: Pointer to time value destination data in RAM.
 *
 * @return     Std_ReturnType.
 * @retval     E_OK:      No error has been detected
 * @retval     E_NOT_OK:  Aborted due to errors
 */
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
{
    uint32                   GptCoreId;
    Std_ReturnType           ReturnValue = (Std_ReturnType)E_NOT_OK;
    Gpt_ChannelType          Channel;
    Gpt_Drvw_PredefTimerType ReturnPredefTimerType;
    GptCoreId = (uint32)Gpt_GetCoreID();

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    ReturnValue =
        Gpt_CheckGetPredefTimerValue(GPT_SID_GET_PREDEFTIMER_VALUE, GptCoreId, TimeValuePtr);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        ReturnValue = Gpt_CheckPredefTimerType(PredefTimer, GptCoreId);
        if ((Std_ReturnType)E_OK == ReturnValue)
        {
#endif
            ReturnValue = Gpt_CheckMode(GPT_SID_GET_PREDEFTIMER_VALUE);
            if ((Std_ReturnType)E_OK == ReturnValue)
            {
                Channel = (Gpt_ChannelType)PredefTimer;

                ReturnPredefTimerType = Gpt_ConvertPredefTimerType(PredefTimer);
                Gpt_Drvw_GetPredefTimerValue(
                    (Gpt_ConfigPtr[GptCoreId]->GptChannelPredefConfigType)[Channel],
                    ReturnPredefTimerType, TimeValuePtr);
            }
            else
            {
                *TimeValuePtr = 0U;
            }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            *TimeValuePtr = 0U;
        }
    }
    else
    {
    }
#endif
    return ReturnValue;
}
#endif

#if (GPT_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief     This function changes the channel prescaler.
 *            - Service ID: 0x10
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] ClockMode   Dual clock mode.
 *
 * @return    None
 */
void Gpt_SetDualClockMode(Gpt_ClockModeType ClockMode)
{
    uint32          GptCoreId = (uint32)Gpt_GetCoreID();
    Gpt_ChannelType ChannelIndex;
    uint32          InstanceIndex;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Gpt_CheckSetClockMode(GPT_SID_SET_CLOCK_MODE, ClockMode, GptCoreId))
    {
#endif
        for (InstanceIndex = 0U; InstanceIndex < Gpt_ConfigPtr[GptCoreId]->InstanceCount;
             InstanceIndex++)
        {
            if (GPT_CLOCKMODE_NORMAL == ClockMode)
            {
                Gpt_Drvw_SetInstanceDualClockMode(
                    (&((*Gpt_ConfigPtr[GptCoreId]->GptInstanceConfig))[InstanceIndex]),
                    GPT_DRVW_CLOCKMODE_NORMAL);
            }
            else
            {
                Gpt_Drvw_SetInstanceDualClockMode(
                    (&((*Gpt_ConfigPtr[GptCoreId]->GptInstanceConfig))[InstanceIndex]),
                    GPT_DRVW_CLOCKMODE_ALTERNATE);
            }
        }
        for (ChannelIndex = 0U; ChannelIndex < Gpt_ConfigPtr[GptCoreId]->ChannelCount;
             ChannelIndex++)
        {
            if (GPT_CLOCKMODE_NORMAL == ClockMode)
            {
                Gpt_Drvw_SetChannelDualClockMode(
                    GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr,
                    GPT_DRVW_CLOCKMODE_NORMAL);
            }
            else
            {
                Gpt_Drvw_SetChannelDualClockMode(
                    GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr,
                    GPT_DRVW_CLOCKMODE_ALTERNATE);
            }
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* GPT_SET_DUAL_CLOCK_MODE */

/**
 * @brief      Gpt interrupt handler and wakeup the EcuM.
 *
 * @param[in]  Channel Channel number
 *
 * @return     None
 */
void Gpt_TimeMatchCallback(uint8 Channel)
{
    uint32 GptCoreId;
    uint8  ChannelIndex;
    GptCoreId = (uint32)Gpt_GetCoreID();

    if (Gpt_ConfigPtr[GptCoreId] != NULL_PTR)
    {
        ChannelIndex = GPT_CHANNEL_ID_TO_INDEX(GptCoreId, Channel);
        if (GPT_CH_MODE_ONESHOT == GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptChannelMode)
        {
            Gpt_Drvw_StopTimer(
                (GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptDrvwHwChannelConfigPtr));
            Gpt_ChangeChannelStatus(Channel, GPT_STATUS_EXPIRED);
        }
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        if ((GPT_MODE_NORMAL == Gpt_Mode) &&
            (TRUE == Gpt_ChannelInfo[Channel].NotificationEnabled) &&
            (NULL_PTR != GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptNotification))
        {
            GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptNotification();
        }
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
        if ((GPT_MODE_SLEEP == Gpt_Mode) && (TRUE == Gpt_ChannelInfo[Channel].WakeupEnabled))
        {
            Gpt_ChangeWakeupGeneratedStatus(Channel, TRUE);

            EcuM_CheckWakeup(GPT_CHANNEL_CONFIG(GptCoreId, ChannelIndex).GptWakeupSource);
        }
    #endif
#endif
    }
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt */

/** @} end of group Gpt_Module */
