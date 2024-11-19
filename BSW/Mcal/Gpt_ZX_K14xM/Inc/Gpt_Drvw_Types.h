/**************************************************************************************************/
/**
 * @file      : Gpt_Drvw_Types.h
 * @brief     : AUTOSAR Gpt drvw driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef GPT_DRVW_TYPES_H
#define GPT_DRVW_TYPES_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drvw
 *  @brief Gpt driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Drvw_Cfg.h"
#include "Rtc_Drv_Types.h"
#include "Stim_Drv_Types.h"
#include "Tim_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define GPT_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define GPT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define GPT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define GPT_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define GPT_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define GPT_DRVW_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Gpt_Drvw_Cfg header file are of the same vendor */
#if (GPT_DRVW_TYPES_H_VENDOR_ID != GPT_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_Types.h and Gpt_Drvw_Cfg.h are different"
#endif
/* Check if current file and Gpt_Drvw_Cfg header file are of the same Autosar version */
#if ((GPT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (GPT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != GPT_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (GPT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != GPT_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_Types.h and Gpt_Drvw_Cfg.h are different"
#endif
/* Check if current file and Gpt_Drvw_Cfg header file are of the same Software version */
#if ((GPT_DRVW_TYPES_H_SW_MAJOR_VERSION != GPT_DRVW_CFG_H_SW_MAJOR_VERSION) ||                     \
     (GPT_DRVW_TYPES_H_SW_MINOR_VERSION != GPT_DRVW_CFG_H_SW_MINOR_VERSION) ||                     \
     (GPT_DRVW_TYPES_H_SW_PATCH_VERSION != GPT_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_Types.h and Gpt_Drvw_Cfg.h are different"
#endif

/* Check if current file and Tim_Drv_Types header file are of the same vendor */
#if (GPT_DRVW_TYPES_H_VENDOR_ID != TIM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_Types.h and Stim_Drv_Types.h have different"
#endif
/* Check if current file and Tim_Drv_Types header file are of the same Autosar version */
#if ((GPT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != TIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (GPT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != TIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||   \
     (GPT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      STIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_Types.h and Tim_Drv_Types.h are different"
#endif
/* Check if current file and Tim_Drv_Types header file are of the same Software version */
#if ((GPT_DRVW_TYPES_H_SW_MAJOR_VERSION != TIM_DRV_TYPES_H_SW_MAJOR_VERSION) ||                   \
     (GPT_DRVW_TYPES_H_SW_MINOR_VERSION != TIM_DRV_TYPES_H_SW_MINOR_VERSION) ||                   \
     (GPT_DRVW_TYPES_H_SW_PATCH_VERSION != TIM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_Types.h and Tim_Drv_Types.h are different"
#endif

/* Check if current file and Stim_Drv_Types header file are of the same vendor */
#if (GPT_DRVW_TYPES_H_VENDOR_ID != STIM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_Types.h and Stim_Drv_Types.h have different"
#endif
/* Check if current file and Stim_Drv_Types header file are of the same Autosar version */
#if ((GPT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != STIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (GPT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != STIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||   \
     (GPT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      STIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_Types.h and Stim_Drv_Types.h are different"
#endif
/* Check if current file and Stim_Drv_Types header file are of the same Software version */
#if ((GPT_DRVW_TYPES_H_SW_MAJOR_VERSION != STIM_DRV_TYPES_H_SW_MAJOR_VERSION) ||                   \
     (GPT_DRVW_TYPES_H_SW_MINOR_VERSION != STIM_DRV_TYPES_H_SW_MINOR_VERSION) ||                   \
     (GPT_DRVW_TYPES_H_SW_PATCH_VERSION != STIM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_Types.h and Stim_Drv_Types.h are different"
#endif

/* Check if current file and Rtc_Drv_Types header file are of the same vendor */
#if (GPT_DRVW_TYPES_H_VENDOR_ID != RTC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_Types.h and Rtc_Drv_Types.h have different"
#endif
/* Check if current file and Rtc_Drv_Types header file are of the same Autosar version */
#if ((GPT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != RTC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (GPT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != RTC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (GPT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      RTC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_Types.h and Rtc_Drv_Types.h are different"
#endif
/* Check if current file and Rtc_Drv_Types header file are of the same Software version */
#if ((GPT_DRVW_TYPES_H_SW_MAJOR_VERSION != RTC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (GPT_DRVW_TYPES_H_SW_MINOR_VERSION != RTC_DRV_TYPES_H_SW_MINOR_VERSION) ||                    \
     (GPT_DRVW_TYPES_H_SW_PATCH_VERSION != RTC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_Types.h and Rtc_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief Specifies the identification (ID) for Gpt prescaler value.
 */
typedef uint8 Gpt_Drvw_PrescalerType;

/**
 * @brief Specifies the identification (ID) for Gpt clock source.
 */
typedef uint8 Gpt_Drvw_ClockSourceType;

/**
 * @brief   Enum defining the supported Ip.
 */
typedef enum
{
    GPT_DRVW_TIM_MODULE= 0,       /*!< TIM_MODULE */
    GPT_DRVW_RTC_MODULE,          /*!< RTC_MODULE */
    GPT_DRVW_STIM_MODULE,         /*!< STIM_MODULE */
} Gpt_Drvw_ModuleType;

/**
* @brief   Structure defining the pointer of timer instance
*
*/
typedef struct
{
    const Tim_Drv_InstanceConfigType * Tim_Drv_InstanceConfig;  /*!< Pointer to timer instance configuration */
} Gpt_Drvw_InstanceConfigType;

/**
 * @brief   Structure defining the pointer of the rtc ,stim and timer channel.
 */
typedef struct
{
    const Tim_Drv_ChannelConfigType  *TimChannelConfig;  /*!< Pointer to timer configuration*/
    const Rtc_Drv_ConfigType         *RtcChannelConfig;  /*!< Pointer to rtc configuration */
    const Stim_Drv_ChannelConfigType *StimChannelConfig; /*!< Pointer to stim configuration*/
} Gpt_Drvw_ChannelConfigType;

/**
 * @brief   Structure defining the configuration of instance.
 */
typedef struct
{
    Gpt_Drvw_ModuleType         InstanceType;         /*!< IP type */
    uint8                       Instance;             /*!< Instance */
    const Gpt_Drvw_InstanceConfigType InstanceConfig;       /*!< Pointer of the instance configuration*/
} Gpt_Drvw_HwInstanceConfigType;

/**
 * @brief   Structure defining the configuration of a hw channel.
 */
typedef struct
{
    Gpt_Drvw_ModuleType        InstanceType;  /*!< IP type */
    uint8                      Instance;      /*!< Instance */
    uint8                      Channel;       /*!< Channel */
    const Gpt_Drvw_ChannelConfigType ChannelConfig; /*!< Pointer of the channel configuration*/
} Gpt_Drvw_HwChannelConfigType;

/**
 * @brief  Enum defining type of prescaler that configurs the clock
 */
#if (GPT_DRVW_SET_DUAL_CLOCK_MODE == STD_ON)
typedef enum
{
    GPT_DRVW_CLOCKMODE_NORMAL = 0U, /*!< Configure prescaler by noraml*/
    GPT_DRVW_CLOCKMODE_ALTERNATE    /*!< Configure prescaler by alternate */
} Gpt_Drvw_DualClockModeType;
#endif /* GPT_DRVW_SET_DUAL_CLOCK_MODE */

#if (GPT_DRVW_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/** @brief   Structure defining the configuration for channel.
 *
 */
typedef struct
{
    Gpt_Drvw_ModuleType      InstanceType; /*!< Instance type */
    uint8                    Instance;     /*!< Instance */
    uint8                    Channel;      /*!< Channel */
    Gpt_Drvw_PrescalerType   Prescaler;    /*!< Channel prescaler value */
    Gpt_Drvw_ClockSourceType ClockSource;  /*!< Channel clock source */
} Gpt_Drvw_HwPredefChannelConfigType;
#endif

/**
 * @brief   Structure defining Gpt channel hardware runtime information.
 */
typedef struct
{
    boolean ChannelRollover; /*!< Rollover information for channel*/
    uint32  TargetTime;      /*!< Target time value */
} Gpt_Drvw_HwChannelInfoType;

#if (GPT_DRVW_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief  Type for GPT Predef Timers.
 *
 */
typedef enum
{
    GPT_DRVW_PREDEF_TIMER_1US_16BIT = 0U, /*!< GPT Predef Timer with tick duration 1us and range
                                               16bit  */
    GPT_DRVW_PREDEF_TIMER_1US_24BIT, /*!< GPT Predef Timer with tick duration 1us and range 24bit */
    GPT_DRVW_PREDEF_TIMER_1US_32BIT, /*!< GPT Predef Timer with tick duration 1us and range 32bit */
    GPT_DRVW_PREDEF_TIMER_100US_32BIT /*!< GPT Predef Timer with tick duration 100us and range
                                           32bit */
} Gpt_Drvw_PredefTimerType;
#endif

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
/** @} end of group Gpt_Drvw */

/** @} end of group Gpt_Module */

#endif /*GPT_DRVW_TYPES_H*/
