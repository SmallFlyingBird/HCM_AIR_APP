/**
 * @file    Gpt.h
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

#ifndef GPT_H
#define GPT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_PBcfg.h"
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM.h"
#endif

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID                      (180)
#define GPT_MODULE_ID           (100)
#define GPT_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_SW_MAJOR_VERSION               (2)
#define GPT_SW_MINOR_VERSION               (3)
#define GPT_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT configuration header file are of the same vendor */
#if (GPT_VENDOR_ID != GPT_VENDOR_ID_CFG)
#error "Gpt.h and Gpt_Cfg.h have different vendor ids"
#endif

/* Check if source file and GPT configuration header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Gpt.h and Gpt_Cfg.h are different"
#endif

/* Check if source file and GPT configuration header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Gpt.h and Gpt_Cfg.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief GPT MODULE INSTANCE ID */
#define GPT_INSTANCE_ID ((uint8)0U)

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        Gpt_DEV_ERROR
 * @brief           GPT development errors
 * @{
 */
/** @brief API service called without module initialization */
#define GPT_E_UNINIT                    (0x0AU)
/** @brief API service for initialization called when already initialized */
#define GPT_E_ALREADY_INITIALIZED       (0x0DU)
/** @brief API error return code: Init function failed */
#define GPT_E_INIT_FAILED               (0x0EU)
/** @brief API parameter checking: invalid channel */
#define GPT_E_PARAM_CHANNEL             (0x14U)
/** @brief API parameter checking: invalid value */
#define GPT_E_PARAM_VALUE               (0x15U)
/** @brief API parameter checking: invalid pointer */
#define GPT_E_PARAM_POINTER             (0x16U)
/** @brief API parameter checking: invalid Predef Timer */
#define GPT_E_PARAM_PREDEF_TIMER        (0x17U)       /* PRQA S 1534 */
/** @brief API parameter checking: invalid mode */
#define GPT_E_PARAM_MODE                (0x1FU)
/** @} */
#endif

/** @brief API service called when timer channel is still busy (running) */
#define GPT_E_BUSY                      (0x0BU)
/** @brief API service called when driver is in wrong mode */
#define GPT_E_MODE                      (0x0CU)       /* PRQA S 1534 */

/**
 * @defgroup        Gpt_SID
 * @brief           Service ID number for all GPT driver services
 */
/** @{ */
/** @brief API Service ID for Gpt_CheckWakeup */
#define GPT_SID_CHECK_WAKEUP            (0x0cU)
/** @brief API Service ID for Gpt_DeInit */
#define GPT_SID_DE_INIT                 (0x02U)
/** @brief API Service ID for Gpt_DisableNotification */
#define GPT_SID_DISABLE_NOTIFICATION    (0x08U)
/** @brief API Service ID for Gpt_DisableWakeup */
#define GPT_SID_DISABLE_WAKEUP          (0x0aU)
/** @brief API Service ID for Gpt_EnableNotification */
#define GPT_SID_ENABLE_NOTIFICATION     (0x07U)
/** @brief API Service ID for Gpt_EnableWakeup */
#define GPT_SID_ENABLE_WAKEUP           (0x0bU)
/** @brief API Service ID for Gpt_GetPredefTimerValue */
#define GPT_SID_GET_PREDEF_TIMER_VALUE  (0x0dU)       /* PRQA S 1534 */
/** @brief API Service ID for Gpt_GetTimeElapsed */
#define GPT_SID_GET_TIME_ELAPSED        (0x03U)
/** @brief API Service ID for Gpt_GetTimeRemaining */
#define GPT_SID_GET_TIME_REMAINING      (0x04U)
/** @brief API Service ID for Gpt_GetVersionInfo */
#define GPT_SID_GET_VERSION_INFO        (0x00U)
/** @brief API Service ID for Gpt_Init */
#define GPT_SID_INIT                    (0x01U)
/** @brief API Service ID for Gpt_SetMode */
#define GPT_SID_SET_MODE                (0x09U)
/** @brief API Service ID for Gpt_StartTimer */
#define GPT_SID_START_TIMER             (0x05U)
/** @brief API Service ID for Gpt_StopTimer */
#define GPT_SID_STOP_TIMER              (0x06U)
/** @} */

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/

#if (GPT_DEINIT_API == STD_ON)
/**
 * @brief       Deinitializes the GPT driver.
 * @return      void
 */
void Gpt_DeInit(void);
#endif /* (GPT_DEINIT_API == STD_ON) */

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief       Disables the interrupt notification for a channel (relevant in normal mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
void Gpt_DisableNotification(Gpt_ChannelType Channel);

/**
 * @brief       Enables the interrupt notification for a channel (relevant in normal mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
void Gpt_EnableNotification(Gpt_ChannelType Channel);
#endif /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Disables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
void Gpt_DisableWakeup(Gpt_ChannelType Channel);

/**
 * @brief       Enables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
void Gpt_EnableWakeup(Gpt_ChannelType Channel);

/**
 * @brief       Sets the operation mode of the GPT.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
void Gpt_SetMode(Gpt_ModeType Mode);

/**
 * @brief       Checks if a wakeup capable GPT channel is the source for a wakeup event and calls 
 *              the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel
 *              wakeup event.
 * @param[in]   WakeupSource Information on wakeup source to be checked. The associated GPT channel
 *  can be determined from configuration data.
 * @return      void
 */
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Delivers the current value of the desired GPT Predef Timer.
 * @param[in]   PredefTimer GPT Predef Timer
 * @param[out]  TimeValuePtr Pointer to time value destination data in RAM
 * @return      Std_ReturnType
 */
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 * TimeValuePtr);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief       Returns the time already elapsed.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      Gpt_ValueType
 */
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
#endif /* (GPT_TIME_ELAPSED_API == STD_ON) */

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief       Returns the time remaining until the target time is reached.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      Gpt_ValueType
 */
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
#endif /* (GPT_TIME_REMAINING_API == STD_ON) */

/**
 * @brief       Initializes the GPT driver.
 * @param[in]   ConfigPtr Pointer to a selected configuration structure
 * @return      void
 */
void Gpt_Init(const Gpt_ConfigType *ConfigPtr);

/**
 * @brief       Starts a timer channel.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @param[in]   Value Target time in number of ticks.
 * @return      void
 */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/**
 * @brief       Stops a timer channel.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      void
 */
void Gpt_StopTimer(Gpt_ChannelType Channel);

#if (GPT_VERSION_INFO_API == STD_ON)
/**
 * @brief       Returns the version information of this module.
 * @param[out]  VersionInfo Pointer to where to store version information of this module
 * @return      none
 */
void Gpt_GetVersionInfo(Std_VersionInfoType * VersionInfo);
#endif

#ifdef __cplusplus
}
#endif

#endif /* GPT_H */

/** @} */

