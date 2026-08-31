/**
 * @file    Gpt_Lld_Rtc_Types.h
 * @version V2.3.0
 *
 * @brief   Gpt_Lld_Rtc_Types header file
 * @details This file contains the Gpt_Lld_Rtc_Types header file.
 *
 * @addtogroup GPT_LLD_RTC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Rtc
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

#ifndef GPT_LLD_RTC_TYPES_H
#define GPT_LLD_RTC_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/* PRQA S 3630 EOF */
/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_RTC_TYPES_VENDOR_ID                      (180)
#define GPT_LLD_RTC_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_RTC_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_RTC_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_RTC_TYPES_SW_MAJOR_VERSION               (2)
#define GPT_LLD_RTC_TYPES_SW_MINOR_VERSION               (3)
#define GPT_LLD_RTC_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief   RTC Mode
 */
typedef enum
{
    RTC_MODE_CONTINUOUS   = 0U,   /**< RTC Mode Continuous */
    RTC_MODE_ONESHOT      = 1U    /**< RTC Mode One Shot */
} Rtc_ModeType;

/**
 * @brief   RTC State
 */
typedef enum
{
    RTC_STATE_UNINIT      = 0U,   /**< RTC State Uninitialized */
    RTC_STATE_INITIALIZED = 1U,   /**< RTC State Initialized */
    RTC_STATE_RUNNING     = 2U,   /**< RTC State Running */
    RTC_STATE_STOPPED     = 3U,   /**< RTC State Stopped */
    RTC_STATE_EXPIRED     = 4U    /**< RTC State Expired */
} Rtc_StatesType;

typedef enum
{
#if defined(CPU_YTM32B1MD1)
    RTC_CLOCK_SOURCE_BUS        = 0U,    /**< RTC Clock Source BUS */
    RTC_CLOCK_SOURCE_RTC_CLKIN  = 1U,    /**< RTC Clock Source RTC_CLKIN */
    RTC_CLOCK_SOURCE_SIRC       = 2U,    /**< RTC Clock Source SIRC */
    RTC_CLOCK_SOURCE_IPC        = 3U,    /**< RTC Clock Source IPC */
#elif defined(CPU_YTM32B1ME0)
    RTC_CLOCK_SOURCE_SXOSC      = 0U,    /**< RTC Clock Source SXOSC */
    RTC_CLOCK_SOURCE_RTC_CLKIN  = 1U,    /**< RTC Clock Source RTC_CLKIN */
#elif defined(CPU_YTM32B1HA0)
    RTC_CLOCK_SOURCE_SXOSC      = 0U,    /**< RTC Clock Source SXOSC */
    RTC_CLOCK_SOURCE_RTC_CLKIN  = 1U,    /**< RTC Clock Source RTC_CLKIN */
    RTC_CLOCK_SOURCE_SIRC_DIV4  = 2U,    /**< RTC Clock Source SIRC_DIV4 */
    RTC_CLOCK_SOURCE_BUS        = 3U,    /**< RTC Clock Source BUS */
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
} Rtc_ClockSourceType;

/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/
/**
 * @brief   RTC Value Type
 */
typedef uint32 Rtc_ValueType;

/**
 * @brief   RTC Notification Type
 */
typedef void (*Rtc_NotificationType)(void);

/**
 * @brief   Rtc Info Type
 */
typedef struct
{
    Rtc_StatesType State;                    /**< RTC State */
    boolean IsNotificationEnabled;           /**< Notification Enabled Flag */
    Rtc_NotificationType NotificationPtr;    /**< Notification Pointer */
    Rtc_ModeType CountMode;                  /**< RTC Mode */
    Rtc_ValueType PeriodTickValue;           /**< RTC Period Tick Value */
    Rtc_ValueType TargetCompareValue;        /**< RTC target compare value */
    Rtc_ValueType StopValue;                 /**< RTC Stop Value */
    boolean IsWakeupEnabled;                 /**< RTC Wakeup Enabled Flag */
    uint32 WakeupSource;                     /**< RTC WakeupSourceID */
    boolean IsWakeupGenerated;               /**< RTC Wakeup Generated Flag */
} Rtc_InfoType;

/** @brief Lptmr module config type */
typedef struct
{
    uint8 InstanceId;                       /**< Hardware instance ID */
    boolean StopInDebugMode;                /**< Stop in debug mode */
    Rtc_ClockSourceType ClockSource;        /**< RTC ClockSource */
} Rtc_InstanceConfigType;

/**
 * @brief   RTC Configuration Type
 */
typedef struct
{
    Rtc_ClockSourceType ClockSource;                      /**< RTC ClockSource */
    Rtc_ModeType CountMode;                               /**< RTC Mode */
    boolean EnableNotification;                           /**< Enable Notification Flag */
    Rtc_NotificationType NotificationPtr;                 /**< RTC Notification Pointer */
    boolean StopInDebugMode;                              /**< Stop in debug mode */
    boolean EnableWakeup;                                 /**< Enable Wakeup Flag */
    uint32 WakeupSource;                                  /**< RTC WakeupSourceID */
} Rtc_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* GPT_LLD_RTC_TYPES_H */

/** @} */

