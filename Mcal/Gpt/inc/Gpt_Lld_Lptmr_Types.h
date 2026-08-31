/**
 * @file    Gpt_Lld_Lptmr_Types.h
 * @version V2.3.0
 *
 * @brief   Gpt_Lld_Lptmr_Types header file
 * @details This file contains the Gpt_Lld_Lptmr_Types header file.
 *
 * @addtogroup GPT_LLD_LPTMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr
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

#ifndef GPT_LLD_LPTMR_TYPES_H
#define GPT_LLD_LPTMR_TYPES_H

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
#define GPT_LLD_LPTMR_TYPES_VENDOR_ID                      (180)
#define GPT_LLD_LPTMR_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_LPTMR_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_LPTMR_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_LPTMR_TYPES_SW_MAJOR_VERSION               (2)
#define GPT_LLD_LPTMR_TYPES_SW_MINOR_VERSION               (3)
#define GPT_LLD_LPTMR_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief   LPTMR Pulse Counter Pin Selection
 */
typedef enum
{
    LPTMR_PLUSE_COUNTER_PIN_ALT0 = 0x00U,   /**< LPTMR Pulse Counter Pin Selection ALT0 */
    LPTMR_PLUSE_COUNTER_PIN_ALT1 = 0x01U,   /**< LPTMR Pulse Counter Pin Selection ALT1 */
    LPTMR_PLUSE_COUNTER_PIN_ALT2 = 0x02U,   /**< LPTMR Pulse Counter Pin Selection ALT2 */
    LPTMR_PLUSE_COUNTER_PIN_ALT3 = 0x03U    /**< LPTMR Pulse Counter Pin Selection ALT3 */
} Lptmr_PulseCounterPinSelType;

/**
 * @brief   LPTMR Pulse Counter Polarity
 */
typedef enum
{
    LPTMR_PLUSE_COUNTER_POLARITY_HIGH = 0x00U, /**< LPTMR Pulse Counter Polarity Active High */
    LPTMR_PLUSE_COUNTER_POLARITY_LOW  = 0x01U  /**< LPTMR Pulse Counter Polarity Active Low */
} Lptmr_PulseCounterPolarityType;

/**
 * @brief   LPTMR Clock Prescaler
 */
typedef enum
{
    LPTMR_CLOCK_PRESCALER_1     = 16U,  /**< LPTMR Clock Prescaler 1 */
    LPTMR_CLOCK_PRESCALER_2     = 0U,   /**< LPTMR Clock Prescaler 2 */
    LPTMR_CLOCK_PRESCALER_4     = 1U,   /**< LPTMR Clock Prescaler 4 */
    LPTMR_CLOCK_PRESCALER_8     = 2U,   /**< LPTMR Clock Prescaler 8 */
    LPTMR_CLOCK_PRESCALER_16    = 3U,   /**< LPTMR Clock Prescaler 16 */
    LPTMR_CLOCK_PRESCALER_32    = 4U,   /**< LPTMR Clock Prescaler 32 */
    LPTMR_CLOCK_PRESCALER_64    = 5U,   /**< LPTMR Clock Prescaler 64 */
    LPTMR_CLOCK_PRESCALER_128   = 6U,   /**< LPTMR Clock Prescaler 128 */
    LPTMR_CLOCK_PRESCALER_256   = 7U,   /**< LPTMR Clock Prescaler 256 */
    LPTMR_CLOCK_PRESCALER_512   = 8U,   /**< LPTMR Clock Prescaler 512 */
    LPTMR_CLOCK_PRESCALER_1024  = 9U,   /**< LPTMR Clock Prescaler 1024 */
    LPTMR_CLOCK_PRESCALER_2048  = 10U,  /**< LPTMR Clock Prescaler 2048 */
    LPTMR_CLOCK_PRESCALER_4096  = 11U,  /**< LPTMR Clock Prescaler 4096 */
    LPTMR_CLOCK_PRESCALER_8192  = 12U,  /**< LPTMR Clock Prescaler 8192 */
    LPTMR_CLOCK_PRESCALER_16384 = 13U,  /**< LPTMR Clock Prescaler 16384 */
    LPTMR_CLOCK_PRESCALER_32768 = 14U,  /**< LPTMR Clock Prescaler 32768 */
    LPTMR_CLOCK_PRESCALER_65536 = 15U   /**< LPTMR Clock Prescaler 65536 */
} Lptmr_PrescalerType;

typedef enum
{
#if defined(CPU_YTM32B1MD1)
    LPTMR_CLOCK_SOURCE_IPC             = 0U,   /**< LPTMR Clock Source IPC */
    LPTMR_CLOCK_SOURCE_SIRC            = 1U,   /**< LPTMR Clock Source SIRC */
#elif defined(CPU_YTM32B1ME0)
    LPTMR_CLOCK_SOURCE_IPC             = 0U,   /**< LPTMR Clock Source IPC */
    LPTMR_CLOCK_SOURCE_SIRC            = 1U,   /**< LPTMR Clock Source SIRC */
    LPTMR_CLOCK_SOURCE_SXOSC           = 2U,   /**< LPTMR Clock Source SXOSC */
#elif defined(CPU_YTM32B1HA0)
    LPTMR_CLOCK_SOURCE_IPC             = 0U,    /**< LPTMR Clock Source IPC */
    LPTMR_CLOCK_SOURCE_SIRC_DIV4       = 1U,    /**< LPTMR Clock Source SIRC_DIV4 */
    LPTMR_CLOCK_SOURCE_SXOSC           = 2U,    /**< LPTMR Clock Source SXOSC */
#elif defined(CPU_YTM32B1MC0)
    LPTMR_CLOCK_SOURCE_FIRC            = 0U,   /**< LPTMR Clock Source FIRC */
    LPTMR_CLOCK_SOURCE_SIRC            = 1U,   /**< LPTMR Clock Source SIRC */
    LPTMR_CLOCK_SOURCE_FXOSC           = 2U,   /**< LPTMR Clock Source FXOSC */
    LPTMR_CLOCK_SOURCE_LPOCLK          = 3U,   /**< LPTMR Clock Source LPO */
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
} Lptmr_ClockSourceType;

/**
 * @brief   LPTMR Mode
 */
typedef enum
{
    LPTMR_MODE_CONTINUOUS   = 0U,   /**< LPTMR Mode Continuous */
    LPTMR_MODE_ONESHOT      = 1U    /**< LPTMR Mode One Shot */
} Lptmr_ModeType;

/**
 * @brief   LPTMR State
 */
typedef enum
{
    LPTMR_STATE_UNINIT      = 0U,   /**< LPTMR State Uninitialized */
    LPTMR_STATE_INITIALIZED = 1U,   /**< LPTMR State Initialized */
    LPTMR_STATE_RUNNING     = 2U,   /**< LPTMR State Running */
    LPTMR_STATE_STOPPED     = 3U,   /**< LPTMR State Stopped */
    LPTMR_STATE_EXPIRED     = 4U    /**< LPTMR State Expired */
} Lptmr_StatesType;

/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/
/**
 * @brief   LPTMR Value Type
 */
typedef uint16 Lptmr_ValueType;

/**
 * @brief   LPTMR Notification Type
 */
typedef void (*Lptmr_NotificationType)(void);

/**
 * @brief   LPTMR Info Type
 */
typedef struct
{
    Lptmr_StatesType State;                 /**< LPTMR State */
    boolean IsNotificationEnabled;          /**< Notification Enabled Flag */
    Lptmr_NotificationType NotificationPtr; /**< Notification Pointer */
    Lptmr_ModeType CountMode;               /**< LPTMR Mode */
    Lptmr_ValueType PeriodTickValue;        /**< LPTMR Period Tick Value */
    Lptmr_ValueType StopValue;              /**< LPTMR Stop Value */
    boolean IsWakeupEnabled;                /**< LPTMR Wakeup Enabled Flag */
    uint32 WakeupSource;                    /**< LPTMR WakeupSourceID */
    boolean IsWakeupGenerated;              /**< LPTMR Wakeup Generated Flag */
} Lptmr_InfoType;

/**
 * @brief   LPTMR Pulse Counter Configuration Type
 */
typedef struct
{
    Lptmr_PulseCounterPinSelType PinSelect;         /**< LPTMR Pulse Counter Pin Selection */
    Lptmr_PulseCounterPolarityType ActivePolarity;  /**< LPTMR Pulse Counter Active Polarity */
} Lptmr_PulseCounterConfigType;

/** @brief Lptmr module config type */
typedef struct
{
    uint8 InstanceId;                       /**< Hardware instance ID */
    boolean PrescalerEnable;                /**< Prescaler Enable */
    Lptmr_PrescalerType PrescaleCode;       /**< LPTMR Prescaler Code */
    Lptmr_ClockSourceType ClockSource;      /**< LPTMR Clock Source */
} Lptmr_InstanceConfigType;

/**
 * @brief   LPTMR Configuration Type
 */
typedef struct
{
    Lptmr_ClockSourceType ClockSource;                      /**< LPTMR Clock Source */
    Lptmr_PrescalerType PrescaleCode;                       /**< LPTMR Prescaler Code */
    Lptmr_ModeType CountMode;                               /**< LPTMR Mode */
    boolean EnableNotification;                             /**< Enable Notification Flag */
    Lptmr_NotificationType NotificationPtr;                 /**< LPTMR Notification Pointer */
    Lptmr_PulseCounterConfigType * PulseCounterConfigPtr;   /**< LPTMR Pulse Counter Configuration Pointer */
    boolean EnableWakeup;                                   /**< Enable Wakeup Flag */
    uint32 WakeupSource;                                    /**< LPTMR WakeupSourceID */
} Lptmr_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* GPT_LLD_LPTMR_TYPES_H */

/** @} */

