/**************************************************************************************************/
/**
 * @file      : Gpt_Types.h
 * @brief     : AUTOSAR Gpt driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

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

#include "Gpt_Drvw_Types.h"
#include "Gpt_Cfg.h"

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    #include "EcuM.h"
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_TYPES_H_VENDOR_ID                   0x00B3U
#define GPT_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define GPT_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define GPT_TYPES_H_SW_MAJOR_VERSION            1U
#define GPT_TYPES_H_SW_MINOR_VERSION            2U
#define GPT_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and EcuM.h file are of the same Autosar version */
#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        #if ((GPT_TYPES_H_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) ||            \
             (GPT_TYPES_H_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Gpt_Types.h and EcuM.h are different"
        #endif
    #endif
#endif

/* Check if current file and Gpt_Cfg header file are of the same vendor */
#if (GPT_TYPES_H_VENDOR_ID != GPT_CFG_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Types.h and Gpt_Cfg.h are different"
#endif
/* Check if current file and Gpt_Cfg header file are of the same Autosar version */
#if ((GPT_TYPES_H_AR_RELEASE_MAJOR_VERSION != GPT_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (GPT_TYPES_H_AR_RELEASE_MINOR_VERSION != GPT_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (GPT_TYPES_H_AR_RELEASE_REVISION_VERSION != GPT_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Types.h and Gpt_Cfg.h are different"
#endif
/* Check if current file and Gpt_Cfg header file are of the same Software version */
#if ((GPT_TYPES_H_SW_MAJOR_VERSION != GPT_CFG_H_SW_MAJOR_VERSION) ||                               \
     (GPT_TYPES_H_SW_MINOR_VERSION != GPT_CFG_H_SW_MINOR_VERSION) ||                               \
     (GPT_TYPES_H_SW_PATCH_VERSION != GPT_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Types.h and Gpt_Cfg.h are different"
#endif
/* Check if current file and Gpt_Drvw_Types header file are of the same vendor */
#if (GPT_TYPES_H_VENDOR_ID != GPT_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Types.h and Gpt_Drvw_Types.h have different"
#endif
/* Check if current file and Gpt_Drvw_Types header file are of the same Autosar version */
#if ((GPT_TYPES_H_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (GPT_TYPES_H_AR_RELEASE_MINOR_VERSION != GPT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
     (GPT_TYPES_H_AR_RELEASE_REVISION_VERSION != GPT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Types.h and Gpt_Drvw_Types.h are different"
#endif
/* Check if current file and Gpt_Drvw_Types header file are of the same Software version */
#if ((GPT_TYPES_H_SW_MAJOR_VERSION != GPT_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                        \
     (GPT_TYPES_H_SW_MINOR_VERSION != GPT_DRVW_TYPES_H_SW_MINOR_VERSION) ||                        \
     (GPT_TYPES_H_SW_PATCH_VERSION != GPT_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Types.h and Gpt_Drvw_Types.h are different"
#endif

/** @defgroup Private_TypeDefinition
 *  @{
 */
/**
 * @brief This enumeration defines the channel status type for Gpt
 */
typedef enum
{
    GPT_STATUS_UNINITIALIZED = 0, /*!< Gpt channel status is uninitialized */
    GPT_STATUS_INITIALIZED,       /*!< Gpt channel status is initialized */
    GPT_STATUS_STOPPED,           /*!< Gpt channel status is stopped */
    GPT_STATUS_EXPIRED,           /*!< Gpt channel status is expired */
    GPT_STATUS_RUNNING            /*!< Gpt channel status is running */
} Gpt_ChannelStatusType;

/**
 * @brief The type of data structure for channel runtime status information.
 *
 */
typedef struct
{
    Gpt_ChannelStatusType ChannelStatus; /*!< Gpt channel runtime status */
    /*  */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    boolean NotificationEnabled; /*!< Notifications has enabled at runtime */
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    boolean WakeupEnabled;   /*!< Wakeup has enabled at runtime */
    boolean WakeupGenerated; /*!< Wakeup has generated at runtime */
#endif
} Gpt_ChannelInfoType;
/** @} end of group Private_TypeDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief  Numeric ID of a GPT channel.
 *
 */
typedef uint32 Gpt_ChannelType;

/**
 * @brief  Type for reading and setting the timer values (in number of ticks).
 *
 */
/* SWS_Gpt_00359 */
typedef uint32 Gpt_ValueType;

/**
 * @brief Gpt channel notification type.The Callback notifications shall be configurable
 *        as pointers to user defined functions within the configuration structure.
 *
 */
typedef void (*Gpt_NotificationType)(void);

/**
 * @brief  Modes of the GPT driver.
 */
/* SWS_Gpt_00360 */
typedef enum
{
    GPT_MODE_NORMAL = 0U, /*!< Normal operation mode of the GPT. */
    GPT_MODE_SLEEP        /*!< Operation for reduced power operation mode. In sleep mode only wakeup
                               capable channels are available. */
} Gpt_ModeType;

/**
 * @brief  Specifies the behavior of the timer channel after the target time is reached.
 */
typedef enum
{
    GPT_CH_MODE_CONTINUOUS = 0U, /*!< After reaching the target time, the timer continues running
                                      with the value "zero" again. */
    GPT_CH_MODE_ONESHOT          /*!< After reaching the target time, the timer stops automatically
                                      (timer expired). */
} Gpt_ChannelModeType;

/**
 * @brief  Enum defining type of prescaler that configurs the clock.
 */
#if (GPT_SET_DUAL_CLOCK_MODE == STD_ON)
typedef enum
{
    GPT_CLOCKMODE_NORMAL = 0U, /*!< Configure prescaler by noraml */
    GPT_CLOCKMODE_ALTERNATE    /*!< Configure prescaler by alternate */
} Gpt_ClockModeType;
#endif /* GPT_SET_DUAL_CLOCK_MODE */

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief  Type for GPT Predef Timers.
 */
/* SWS_Gpt_00389 */
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 0U, /*!< GPT Predef Timer with tick duration 1us and range 16bit */
    GPT_PREDEF_TIMER_1US_24BIT,  /*!< GPT Predef Timer with tick duration 1us and range 24bit */
    GPT_PREDEF_TIMER_1US_32BIT,  /*!< GPT Predef Timer with tick duration 1us and range 32bit */
    GPT_PREDEF_TIMER_100US_32BIT /*!< GPT Predef Timer with tick duration 100us and range 32bit */
} Gpt_PredefTimerType;
#endif

/**
 * @brief This structure contains all the needed data to configure Gpt channel.
 *
 */
typedef struct
{
    boolean              GptEnableWakeup; /*!< Wakeup capability of MCU for a channel */
    Gpt_NotificationType GptNotification; /*!< Function pointer to callback function (for
                                               non-wakeup notification) */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    EcuM_WakeupSourceType GptWakeupSource; /*!< In case the wakeup-capability is true this value is
                                                transmitted to the Ecu State Manager. */
#endif
    float64 GptChannelTickFrequency;      /*!< Specifies the tick frequency of the timer channel in
                                               Hz. */
    Gpt_ValueType GptChannelTickValueMax; /*!< Maximum value in ticks, the timer channel is able to
                                               count. With the next tick, the timer rolls over to
                                               zero */
    Gpt_ChannelModeType GptChannelMode;   /*!< Specifies the behavior of the timer channel after
                                               the target time is reached*/
    const Gpt_Drvw_HwChannelConfigType
        *GptDrvwHwChannelConfigPtr; /*!< The configuration of a hw channel*/
} Gpt_ChannelConfigType;

/**
 * @brief This structure contains all the needed data to configure Gpt.
 *
 */
/* SWS_Gpt_00357 */
typedef struct
{
    Gpt_ChannelType ChannelCount; /*!< Total number of channels defined in configuration*/
    const Gpt_ChannelConfigType (*GptChannelConfig)[]; /*!< A pointer to the GPT channel
                                                         configuration defined in configuration*/
    uint8 InstanceCount; /*!< Total number of instances defined in configuration*/
    /*!< A pointer to the instance configuration defined in configuration*/
    const Gpt_Drvw_HwInstanceConfigType (*GptInstanceConfig)[];
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    /*!< A pointer to the predeftimer configuration defined in configuration*/
    const Gpt_Drvw_HwPredefChannelConfigType *const(*GptChannelPredefConfigType);
#endif
    const uint8 (*GptChannelIdToIndexMap)[]; /*!< Hardware-to-logical channel mapping table*/
} Gpt_ConfigType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt */

/** @} end of group Gpt_Module */

#endif /* GPT_TYPES_H */
