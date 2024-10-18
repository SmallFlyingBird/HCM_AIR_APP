/**************************************************************************************************/
/**
 * @file      : Rtc_Drv_Types.h
 * @brief     : Rtc module type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef RTC_DRV_TYPES_H
#define RTC_DRV_TYPES_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Rtc_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Rtc_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define RTC_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define RTC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define RTC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define RTC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define RTC_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define RTC_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define RTC_DRV_TYPES_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((RTC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (RTC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Rtc_Drv_Types.h and Std_Types.h are different"
    #endif
    /* Check if current file and McalLib header file are of the same Autosar version */
    #if ((RTC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (RTC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Rtc_Drv_Types.h and McalLib.h are different"
    #endif
#endif

/* Check if current file and Rtc_Drv_Cfg header file are of the same vendor */
#if (RTC_DRV_TYPES_H_VENDOR_ID != RTC_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Rtc_Drv_Types.h and Rtc_Drv_Cfg.h are different"
#endif
/* Check if current file and Rtc_Drv_Cfg header file are of the same Autosar version */
#if ((RTC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != RTC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (RTC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != RTC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (RTC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != RTC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Rtc_Drv_Types.h and Rtc_Drv_Cfg.h are different"
#endif
/* Check if current file and Rtc_Drv_Cfg header file are of the same software version */
#if ((RTC_DRV_TYPES_H_SW_MAJOR_VERSION != RTC_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (RTC_DRV_TYPES_H_SW_MINOR_VERSION != RTC_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (RTC_DRV_TYPES_H_SW_PATCH_VERSION != RTC_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Rtc_Drv_Types.h and Rtc_Drv_Cfg.h are different"
#endif

#if (RTC_DRV_ENABLE == STD_ON)
    /**
     * @brief RTC Channels defines
     */
    #define SECONDS_IN_A_DAY    (86400UL)
    #define SECONDS_IN_A_HOUR   (3600U)
    #define SECONDS_IN_A_MIN    (60U)
    #define MINS_IN_A_HOUR      (60U)
    #define HOURS_IN_A_DAY      (24U)
    #define DAYS_IN_A_YEAR      (365U)
    #define DAYS_IN_A_LEAP_YEAR (366U)
    #define YEAR_RANGE_START    (1970U)
    #define YEAR_RANGE_END      (2099U)
    #define MAX_VALUE           (0xFFFFFFFFUL)

#endif

/**
 * @brief RTC module's instance number
 */
#define RTC_DRV_INSTANCE_COUNT (1u)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief  Callback type for each channel
 */
typedef void (*Rtc_Drv_CallbackType)(uint8 CallbackParam);

/**
 *  @brief Enum defining the output clock type
 */
typedef enum
{
    RTC_DRV_SECONDS = 0U, /*!< RTC internal seconds counter */
    RTC_DRV_32K_CLK       /*!< RTC osc32k/lpo32k */
} Rtc_Drv_ClockOutType;

/**
 *  @brief Enum defining the rtc source type
 */
typedef enum
{
    RTC_DRV_CLK_OSC32K_INT = 0U, /*!< internal OSC32K  */
    RTC_DRV_CLK_OSC32K_EXT,      /*!< external OSC32K */
    RTC_DRV_CLK_LPO32K           /*!< lpo32k  */
} Rtc_Drv_ClockSourceType;

/**
 *  @brief Enum defining the rtc interrupt type
 */
typedef enum
{
    RTC_DRV_INT_OVERFLOW = 0U, /*!< RTC overflow interrupt*/
    RTC_DRV_INT_ALARM,         /*!< RTC alarm interrupt, frequency is 1Hz */
    RTC_DRV_INT_SECOND,        /*!< RTC second interrupt */
    RTC_DRV_INT_PERIODIC,      /*!< RTC periodic interrupt, frequency is 32kHz */
    RTC_DRV_INT_ALL            /*!< RTC all interrupts */
} Rtc_Drv_InterruptType;
/**
 *  @brief Enum defining the rtc status error type
 */
typedef enum
{
    RTC_DRV_SUCCESS = E_OK,  /*!< Status value is SUCCESS */
    RTC_DRV_ERROR = E_NOT_OK /*!< Status value is ERROR */
} Rtc_Drv_StatusType;

/**
 *  @brief Enum defining the rtc second interrupt mux type
 */
typedef enum
{
    RTC_DRV_SECOND_1 = 0U, /*!< RTC select 1Hz to generate second interrupt */
    RTC_DRV_SECOND_64,     /*!< RTC select 64Hz to generate second interrupt */
    RTC_DRV_SECOND_32,     /*!< RTC select 32Hz to generate second interrupt */
    RTC_DRV_SECOND_16,     /*!< RTC select 16Hz to generate second interrupt */
    RTC_DRV_SECOND_8,      /*!< RTC select 8Hz to generate second interrupt */
    RTC_DRV_SECOND_4,      /*!< RTC select 4Hz to generate second interrupt */
    RTC_DRV_SECOND_2,      /*!< RTC select 2Hz to generate second interrupt */
    RTC_DRV_SECOND_128     /*!< RTC select 128Hz to generate second interrupt */
} Rtc_Drv_SecondIntMuxSelType;

#if (defined(RTC_DRV_ENABLE_COMPENSATION_SUPPORT) &&                                               \
     (RTC_DRV_ENABLE_COMPENSATION_SUPPORT == STD_ON))
/**
 *  @brief Enum defining the rtc
 */
typedef enum
{
    RTC_DRV_COMP_UP = 0U, /*!< Compensation direction up,  seconds frequency faster */
    RTC_DRV_COMP_DOWN     /*!< Compensation direction down,  seconds frequency  slower */
} Rtc_Drv_CompDirectionType;
#endif

/**
 * @brief  Structure defining the configuration for rtc.
 */
typedef struct
{
    Rtc_Drv_ClockSourceType ClockSource;    /*!< RTC clock source */
    Rtc_Drv_ClockOutType    ClockOutSelect; /*!< RTC clock output type */
    Rtc_Drv_InterruptType ModeSelect; /*!< RTC interrupt mode type */
#if (defined(RTC_DRV_ENABLE_COMPENSATION_SUPPORT) &&                                               \
     (RTC_DRV_ENABLE_COMPENSATION_SUPPORT == STD_ON))
    uint8                     CompensationInterval;  /*!< RTC Compensation Interval */
    Rtc_Drv_CompDirectionType CompensationDirection; /*!< RTC Compensation Direction */
    uint8                     Compensation;          /*!< RTC Compensation Value */
#endif
    Rtc_Drv_CallbackType Callback;      /*!< Rtc interrupt callback */
    uint8                CallbackParam; /*!< Pointer to callback parameters */
} Rtc_Drv_ConfigType;

/**
 * @brief  Structure defining the time date for rtc
 */
typedef struct
{
    uint16 Year;    /*!< Year */
    uint16 Month;   /*!< Month */
    uint16 Day;     /*!< Day */
    uint16 Hour;    /*!< Hour */
    uint16 Minutes; /*!< Minutes */
    uint8  Seconds; /*!< Seconds */
} Rtc_Drv_TimedateType;

/**
 * @brief  Structure defining the alarm configuration for rtc
 */
typedef struct
{
    Rtc_Drv_TimedateType AlarmTime;          /*!< Alarm time */
    uint32               AlarmRepetitionInterval; /*!< Interval of repetition in seconds */
    uint32               AlarmRepeatsNumber;      /*!< Alarm repeats number */
    boolean              RepeatForever;  /*!< If set to repeat forever, the number of repetitions
                                             is discarded */
    boolean              AlarmIntEnable; /*!< Enable alarm interrupt */
    Rtc_Drv_CallbackType AlarmCallback;  /*!< Pointer to callback. */
    uint8                AlarmCallbackParams; /*!< Pointer to the Callback parameters. */
} Rtc_Drv_AlarmConfigType;

/**
 * @brief  Structure defining the state for rtc
 */
typedef struct
{
    Rtc_Drv_InterruptType ModeSelect;    /*!< RTC interrupt mode type */
    boolean         AlarmInit;           /*!< Alarm initial */
    uint32          AlarmRepetitionInterval;  /*!< Interval of repetition in seconds */
    volatile uint32 AlarmRepeatsNumber;       /*!< Alarm repeats number */
    boolean         RepeatForever;       /*!< If set to repeat forever, the number of repetitions
                                              is discarded  */
    boolean              AlarmIntEnable; /*!< Enable alarm interrupt */
    Rtc_Drv_CallbackType AlarmCallback;  /*!< Pointer to callback. */
    uint8                AlarmCallbackParams; /*!< Pointer to the Callback parameters. */
    volatile boolean     IsAlarmMatchTimeNew; /*!< Check if there is a new alarm match */
    boolean              ChannelInit;         /*!< Channel initial */
    Rtc_Drv_CallbackType Callback;            /*!< Callback */
    uint8                CallbackParam;       /*!< CallbackParam */
} Rtc_Drv_StateType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Rtc_Drv_Types */

/** @} end of group Rtc_Module */

#endif /* RTC_DRV_TYPES_H */
