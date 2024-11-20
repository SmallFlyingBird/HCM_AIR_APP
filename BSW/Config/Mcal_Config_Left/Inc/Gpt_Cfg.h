/**************************************************************************************************/
/**
 * @file      : Gpt_Cfg.h
 * @brief     : AUTOSAR Gpt - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef GPT_CFG_H
#define GPT_CFG_H

/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Configuration
 *  @brief Gpt AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Gpt_PBcfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_CFG_H_VENDOR_ID                   0x00B3U
#define GPT_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define GPT_CFG_H_AR_RELEASE_REVISION_VERSION 0U       
#define GPT_CFG_H_SW_MAJOR_VERSION            1U
#define GPT_CFG_H_SW_MINOR_VERSION            2U
#define GPT_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Gpt_PBcfg.h are of the same vendor */
#if (GPT_CFG_H_VENDOR_ID != GPT_PBCFG_H_VENDOR_ID)
    #error "Vendor TD of Gpt_Cfg.h and Gpt_PBcfg.h are different"
#endif
/* Check if current file and Gpt_PBcfg.h are of the same Autosar version */
#if ((GPT_CFG_H_AR_RELEASE_MAJOR_VERSION != GPT_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_CFG_H_AR_RELEASE_MINOR_VERSION != GPT_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (GPT_CFG_H_AR_RELEASE_REVISION_VERSION != GPT_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Gpt_Cfg.h and Gpt_PBcfg.h are different"
#endif
/* Check if current file and Gpt_PBcfg.h are of the same software version */
#if ((GPT_CFG_H_SW_MAJOR_VERSION != GPT_PBCFG_H_SW_MAJOR_VERSION) || \
     (GPT_CFG_H_SW_MINOR_VERSION != GPT_PBCFG_H_SW_MINOR_VERSION) || \
     (GPT_CFG_H_SW_PATCH_VERSION != GPT_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Gpt_Cfg.h and Gpt_PBcfg.h are different"
#endif

/* Check if current file and Std_Types.h file are of the same Autosar version */
#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((GPT_CFG_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||                   \
         (GPT_CFG_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Cfg.h and Std_Types.h are different"
    #endif
#endif

/**
 * @brief    Switches the Development Error functionality ON or OFF.
 * @details  Switches the Development Error Detection and Notification ON or OFF.
 */

#define GPT_DEV_ERROR_DETECT         (STD_OFF)

/**
 * @brief  Switches the Gpt report wakeup source functionality ON or OFF.
 */
#define GPT_REPORT_WAKEUP_SOURCE     (STD_OFF)

/**
 * @brief  Switches the Gpt version information functionality ON or OFF.
 */
#define GPT_VERSION_INFO_API         (STD_OFF)

/**
 * @brief  Switches the Gpt deinit functionality ON or OFF.
 */
#define GPT_DEINIT_API               (STD_ON)

/**
 * @brief  Switches the Gpt time elapsed functionality ON or OFF.
 */
#define GPT_TIME_ELAPSED_API         (STD_ON)

/**
 * @brief  Switches the Gpt time remaininig functionality ON or OFF.
 */
#define GPT_TIME_REMAINING_API        (STD_ON)

/**
 * @brief  Switches the Gpt wakeup functionality ON or OFF.
 */ 
#define GPT_WAKEUP_FUNCTIONALITY_API      (STD_OFF)

/**
 * @brief  Switches the standby wakeup functionality ON or OFF.
 */
#define GPT_STANDBY_WAKEUP_SUPPORT    (STD_OFF)

/**
* @brief   Switches the Gpt enable/disable notification functionality ON or OFF.
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API    (STD_ON)

/**
 * @brief  Switches the dual mode functionality ON or OFF.
 */
#define GPT_SET_DUAL_CLOCK_MODE           (STD_OFF)

/**
 * @brief  Switches the predefined timer functionality ON or OFF.
 */
#define GPT_PREDEFTIMER_FUNCTIONALITY_API   (STD_OFF)

/**
 * @brief  Switches the user mode functionality ON or OFF.
 * @details If it is STD_ON, then the Gpt driver code can be executed in both supervisor and 
 *          user mode.
 */
#define GPT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

#ifndef MCAL_SUPPORT_USER_MODE
 #ifdef GPT_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_SUPPORT_USER_MODE is disabled. To run in user mode, you need to define 
          MCAL_SUPPORT_USER_MODE.
  #endif /* (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef GPT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_SUPPORT_USER_MODE */

/**
 * @brief    GPT_MULTICORE_ENABLED switch
 * @details  Enable/disable GPT_MULTICORE_ENABLED.
 */
#define GPT_MULTICORE_ENABLED                      (STD_OFF)

/**
 * @brief   Switches the Gpt precompile support functionality ON or OFF.
 */
#define GPT_PRECOMPILE_SUPPORT      (STD_ON)

/**
 * @brief Defines the symbolic name of the channel
 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_5MS  (0U)
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_10MS  (1U)
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_100MS  (2U)

/**
 * @brief Maximum number of HW channels
 */
#define GPT_HW_CHANNEL_NUM   (3U)

/**
 * @brief The maximum number of partitions configured.
 */
#define GPT_MAX_PARTITIONS_CFG         (0U)

/**
 * @brief Total number of partitions configured in Ecu.
 */
#define GPT_MAX_PARTITIONS    (1U)

/**
 * @brief Numbers of ChannelConfiguration
 */
#define GPT_NUM_CONFIG                 (3U)
/**
 * @brief Number of predefined timers
 */
#define GPT_HW_PREDEFTIMER_NUM (4U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_CONFIG_EXT \
    GPT_CONFIG_PB
/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt_Configuration */

/** @} end of group Gpt_Module */

#endif /*GPT_CFG_H*/

