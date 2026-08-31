/**
 * @file    Gpt_Lld_Ptmr_Types.h
 * @version V2.3.0
 *
 * @brief   Gpt_Lld_Ptmr_Types header file
 * @details This file contains the Gpt_Lld_Ptmr_Types header file.
 *
 * @addtogroup GPT_LLD_PTMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Ptmr
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

#ifndef GPT_LLD_PTMR_TYPES_H
#define GPT_LLD_PTMR_TYPES_H

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
#define GPT_LLD_PTMR_TYPES_VENDOR_ID                      (180)
#define GPT_LLD_PTMR_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_PTMR_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_PTMR_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_PTMR_TYPES_SW_MAJOR_VERSION               (2)
#define GPT_LLD_PTMR_TYPES_SW_MINOR_VERSION               (3)
#define GPT_LLD_PTMR_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define PTMR_CHANNEL_COUNT (4U)


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/** @brief Ptmr channel mode type */
typedef enum
{
    PTMR_CH_MODE_CONTINUOUS = 0U,   /**< Continuous mode */
    PTMR_CH_MODE_ONESHOT    = 1U    /**< One shot mode */
} Ptmr_ChannelModeType;

/** @brief Ptmr channel state type */
typedef enum
{
    PTMR_CHANNEL_STATE_UNINIT       = 0U,   /**< Uninitialized state */
    PTMR_CHANNEL_STATE_INITIALIZED  = 1U,   /**< Initialized state */
    PTMR_CHANNEL_STATE_RUNNING      = 2U,   /**< Running state */
    PTMR_CHANNEL_STATE_STOPPED      = 3U,   /**< Stopped state */
    PTMR_CHANNEL_STATE_EXPIRED      = 4U    /**< Expired state */
} Ptmr_ChannelStatesType;

/*==================================================================================================
 *                                           TYPEDEFS
==================================================================================================*/
/** @brief Ptmr channel value type */
typedef uint32 Ptmr_ValueType;

/** @brief Ptmr channel notification type */
typedef void (*Ptmr_NotificationType)(void);

/** @brief Ptmr channel info type */
typedef struct
{
    Ptmr_ChannelStatesType State;           /**< Channel state */
    boolean IsNotificationEnabled;          /**< Notification enabled */
    Ptmr_NotificationType NotificationPtr;  /**< Pointer to notification function */
    Ptmr_ChannelModeType CountMode;         /**< Channel mode */
    Ptmr_ValueType PeriodTickValue;         /**< Period tick value */
    Ptmr_ValueType StopValue;               /**< Stop value */
} Ptmr_ChannelInfoType;

/** @brief Ptmr channel config type */
typedef struct
{
    uint8 HwInstanceId;                     /**< Hardware instance ID */
    uint8 HwChannelId;                      /**< Hardware channel ID */
    Ptmr_ChannelModeType CountMode;         /**< Channel mode */
    boolean EnableNotification;             /**< Notification enabled */
    Ptmr_NotificationType NotificationPtr;  /**< Pointer to notification function */
} Ptmr_ChannelConfigType;

/** @brief Ptmr module config type */
typedef struct
{
    uint8 InstanceId;                       /**< Hardware instance ID */
    boolean StopInDebugMode;                /**< Stop in debug mode */
} Ptmr_InstanceConfigType;

/** @brief Ptmr config type */
typedef struct
{
    uint8 InstanceId;                                  /**< Hardware instance ID */
    boolean StopInDebugMode;                           /**< Stop in debug mode */
    uint8 UsedChannel;                                 /**< Number of used channels */
    const Ptmr_ChannelConfigType * ChannelConfigPtr;   /**< Pointer to channel config */
} Ptmr_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* GPT_LLD_PTMR_TYPES_H */

/** @} */

