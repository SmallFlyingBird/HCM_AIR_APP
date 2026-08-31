/**
 * @file    Gpt_Lld_Tmr_Types.h
 * @version V2.3.0
 *
 * @brief   Gpt_Lld_Tmr_Types header file
 * @details This file contains the Gpt_Lld_Tmr_Types header file.
 *
 * @addtogroup GPT_LLD_TMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Tmr
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

#ifndef GPT_LLD_TMR_TYPES_H
#define GPT_LLD_TMR_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/* PRQA S 3630 EOF */
/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_TMR_TYPES_VENDOR_ID                      (180)
#define GPT_LLD_TMR_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_TMR_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_TMR_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_TMR_TYPES_SW_MAJOR_VERSION               (2)
#define GPT_LLD_TMR_TYPES_SW_MINOR_VERSION               (3)
#define GPT_LLD_TMR_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define TMR_CHANNEL_COUNT (4U)


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/** @brief Tmr channel type */
typedef enum
{
    TMR_CH_0  = 0U,   /**< Tmr Channel 0 */
    TMR_CH_1  = 1U,   /**< Tmr Channel 1 */
    TMR_CH_2  = 2U,   /**< Tmr Channel 2 */
    TMR_CH_3  = 3U    /**< Tmr Channel 3 */
} Tmr_ChannelType;

/** @brief Tmr channel mode type */
typedef enum
{
    TMR_CH_MODE_CONTINUOUS  = 0U,   /**< Continuous mode */
    TMR_CH_MODE_ONESHOT     = 1U    /**< One shot mode */
} Tmr_ChannelModeType;

/** @brief Tmr channel state type */
typedef enum
{
    TMR_CHANNEL_STATE_UNINIT        = 0U,   /**< Uninitialized state */
    TMR_CHANNEL_STATE_INITIALIZED   = 1U,   /**< Initialized state */
    TMR_CHANNEL_STATE_RUNNING       = 2U,   /**< Running state */
    TMR_CHANNEL_STATE_STOPPED       = 3U,   /**< Stopped state */
    TMR_CHANNEL_STATE_EXPIRED       = 4U    /**< Expired state */
} Tmr_ChannelStatesType;

/*==================================================================================================
 *                                           TYPEDEFS
==================================================================================================*/
/** @brief Tmr value type */
typedef uint32 Tmr_ValueType;

/** @brief Tmr notification type */
typedef void (*Tmr_NotificationType)(void);

/** @brief Tmr channel info type */
typedef struct
{
    boolean IsEnabled;                      /**< Channel enabled flag */
    Tmr_ChannelStatesType State;            /**< Channel state */
    boolean IsNotificationEnabled;          /**< Notification enabled flag */
    Tmr_NotificationType NotificationPtr;   /**< Pointer to notification function */
    Tmr_ChannelModeType CountMode;          /**< Channel mode */
    Tmr_ValueType PeriodTickValue;          /**< Channel period value */
    Tmr_ValueType TargetCompareValue;       /**< Channel target compare value */
    Tmr_ValueType StopValue;                /**< Channel stop value */
} Tmr_ChannelInfoType;

/** @brief Tmr channel config type */
typedef struct
{
    uint8 HwInstanceId;                     /**< Hardware instance ID */
    uint8 HwChannelId;                      /**< Hardware channel ID */
    Tmr_ChannelModeType CountMode;          /**< Channel mode */
    boolean EnableNotification;             /**< Notification enabled flag */
    Tmr_NotificationType NotificationPtr;   /**< Pointer to notification function */
} Tmr_ChannelConfigType;

/** @brief Tmr module config type */
typedef struct
{
    uint8 InstanceId;                       /**< Hardware instance ID */
    uint8 Prescaler;                        /**< Prescaler value */
    boolean StopInDebugMode;                /**< Stop in debug mode flag */
} Tmr_InstanceConfigType;

/** @brief Tmr config type */
typedef struct
{
    uint8 InstanceId;                           /**< Hardware instance ID */
    uint8 Prescaler;                            /**< Prescaler value */
    boolean StopInDebugMode;                    /**< Stop in debug mode flag */
    uint8 UsedChannel;                          /**< Number of used channels */
    Tmr_ChannelConfigType * ChannelConfigPtr;   /**< Pointer to channel config */
} Tmr_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* GPT_TMR_TYPES_H */

/** @} */

