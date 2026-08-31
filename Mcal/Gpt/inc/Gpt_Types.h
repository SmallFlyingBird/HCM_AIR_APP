/**
 * @file    Gpt_Types.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Gpt module date types header file.
 * @details This file contains the Gpt module date types.
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

#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/* PRQA S 0288 EOF */
/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_Lld_Lptmr_Types.h"
#include "Gpt_Lld_Ptmr_Types.h"
#if (GPT_TMR_MODULE_USED == STD_ON)
#include "Gpt_Lld_Tmr_Types.h"
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
#include "Gpt_Lld_Rtc_Types.h"
#endif

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_TYPES_VENDOR_ID                      (180)
#define GPT_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_TYPES_SW_MAJOR_VERSION               (2)
#define GPT_TYPES_SW_MINOR_VERSION               (3)
#define GPT_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief   Gpt driver mode type
 */
typedef enum
{
    GPT_MODE_NORMAL = 0U,   /**< GPT Normal Mode */
    GPT_MODE_SLEEP  = 1U    /**< GPT Sleep Mode */
} Gpt_ModeType;

/**
 * @brief   Gpt channel mode type
 */
typedef enum
{
    GPT_CH_MODE_CONTINUOUS  = 0U,   /**< GPT Continuous Mode */
    GPT_CH_MODE_ONESHOT     = 1U    /**< GPT One Shot Mode */
} Gpt_ChannelModeType;

/**
 * @brief Type for GPT Predef Timers
 */
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT      = 1U,   /**< GPT Predef Timer with tick duration 1µs and range 16bit */
    GPT_PREDEF_TIMER_1US_24BIT      = 1U,   /**< GPT Predef Timer with tick duration 1µs and range 24bit */
    GPT_PREDEF_TIMER_1US_32BIT      = 3U,   /**< GPT Predef Timer with tick duration 1µs and range 32bit */
    GPT_PREDEF_TIMER_100US_32BIT    = 4U    /**< GPT Predef Timer with tick duration 100µs and range 32bit */
} Gpt_PredefTimerType;                              /* PRQA S 1535 */

/**
 * @brief Type for GPT hardware modules
 */
typedef enum
{
    GPT_HW_MODULE_TMR   = 0U,   /**< GPT Hardware Module TMR */
    GPT_HW_MODULE_PTMR  = 1U,   /**< GPT Hardware Module PTMR */
    GPT_HW_MODULE_LPTMR = 2U,   /**< GPT Hardware Module LPTMR */
    GPT_HW_MODULE_ETMR  = 3U,   /**< GPT Hardware Module ETMR */
    GPT_HW_MODULE_RTC   = 4U,   /**< GPT Hardware Module RTC */
    GPT_HW_MODULE_NONE  = 0xFFU /**< GPT Hardware Module None */
} Gpt_HwTimerModuleType;

/*==================================================================================================
 *                                     STRUCTURES AND OTHER TYPES
==================================================================================================*/
/**
 * @brief Gpt channel ID data type
 */
typedef uint16 Gpt_ChannelType;

/**
 * @brief Gpt hardware channel ID data type
 */
typedef uint16 Gpt_HwChannelType;

/**
 * @brief Gpt timeout value type
 */
typedef uint32 Gpt_ValueType;

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief Gpt notification function pointer type
 */
typedef void (*Gpt_NotificationType)(void);
#endif


/**
* @internal
* @brief    HwChannelConfigType  - this is the type of the data structure including the
*           informations of a channel.
* @details  It contains the information like instanceType, instance, channel.
*/
typedef struct                              /*PRQA S 3630 */
{
    Gpt_HwTimerModuleType InstanceType;                     /**< @brief IP type */
    uint8 HwInstanceId;                                     /**< @brief IP instance  */
    uint8 HwChannelId;                                      /**< @brief IP channel */
}Gpt_HwChannelConfigType;

/**
 * @brief Gpt channel configuration type
 */
typedef struct                              /*PRQA S 3630 */
{
    uint8 ChannelId;                                       /**< Channel ID */
    const Gpt_HwChannelConfigType *GptHwChannelConfig;     /**< Hardware channel */
    Gpt_ChannelModeType CountMode;                         /**< Count mode for the timer channel */
    float32 TickFrequency;                                 /**< The tick frequency of the timer channel in Hz. */
    Gpt_ValueType TickValueMax;                            /**< Maximum value in ticks, the timer channel is able to count */
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    boolean EnableWakeup;                                  /**< Enable wakeup capability for the timer channel */
#endif
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    Gpt_NotificationType NotificationPtr;                  /**< Pointer to notification function */
#endif
#if(GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint32 WakeupSource;                                   /**< WakeupSource ID */
#endif
} Gpt_ChannelConfigType;

/**
 * @brief Gpt instance configuration type
 */
typedef struct
{
    Gpt_HwTimerModuleType InstanceType;                /**< Instance Type */
    uint8 HwInstanceId;                                /**< Instance ID */
    const Lptmr_InstanceConfigType *LptmrInstCfg;      /**< Lptmr instance Configuration */
    const Ptmr_InstanceConfigType *PtmrInstCfg;        /**< Ptmr instance Configuration */
#if (GPT_TMR_MODULE_USED == STD_ON)
    const Tmr_InstanceConfigType *TmrInstCfg;          /**< Tmr instance Configuration */
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    const Rtc_InstanceConfigType *RtcInstCfg;          /**< Rtc instance Configuration */
#endif
}Gpt_InstanceConfigType;


/**
 * @brief Gpt configuration type.
 */
typedef struct                              /*PRQA S 3630 */
{
    Gpt_ChannelType UsedInstanceCount;                    /**< number of GPT instances */
    Gpt_ChannelType UsedChannelCount;                     /**< number of GPT channels */
    const Gpt_InstanceConfigType (*InstanceConfig)[];     /**< pointer to GPT instance configuration */
    const Gpt_ChannelConfigType (*ChannelConfig)[];       /**< pointer to GPT channel configuration */
    const uint8 (*ChannelIdToIndexMap)[];                 /** channel index in each partition map table*/
} Gpt_ConfigType;


/**
 * @brief This enumerated type contain the Gpt driver's possible status.
 */
typedef enum
{
    GPT_UNINIT  = 0U,   /**< @brief GPT driver status - uninitialized */
    GPT_IDLE    = 1U    /**< @brief GPT driver status - idle */
} Gpt_StatusType;

/**
 * @brief This enumerated type allows the selection of channel status type.
 */
typedef enum
{
    GPT_STATUS_UNINITIALIZED    = 0U,   /**< @brief GPT channel status - uninitialized */
    GPT_STATUS_INITIALIZED      = 1U,   /**< @brief GPT channel status - initialized */
    GPT_STATUS_RUNNING          = 2U,   /**< @brief GPT channel status - stopped */
    GPT_STATUS_STOPPED          = 3U,   /**< @brief GPT channel status - expired */
    GPT_STATUS_EXPIRED          = 4U    /**< @brief GPT channel status - running */
} Gpt_ChannelStatusType;

#ifdef __cplusplus
}
#endif

#endif /*GPT_TYPES_H*/

/** @} */

