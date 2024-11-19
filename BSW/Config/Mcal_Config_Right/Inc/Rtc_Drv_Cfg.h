/**************************************************************************************************/
/**
 * @file      : Rtc_Drv_Cfg.h  
 * @brief     : Rtc module - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef RTC_DRV_CFG_H
#define RTC_DRV_CFG_H

/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Configuration
 *  @brief Gpt low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
#include "Rtc_Drv_PBcfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define RTC_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define RTC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define RTC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define RTC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define RTC_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define RTC_DRV_CFG_H_SW_MINOR_VERSION            2U
#define RTC_DRV_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Rtc_Drv_PBcfg.h are the same vendor */
#if (RTC_DRV_CFG_H_VENDOR_ID != RTC_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Rtc_Drv_Cfg.h and Rtc_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Rtc_Drv_PBcfg.h are the same Autosar version */
#if ((RTC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != RTC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (RTC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != RTC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (RTC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != RTC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Rtc_Drv_Cfg.h and Rtc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Rtc_Drv_PBcfg.h are the same software version */
#if ((RTC_DRV_CFG_H_SW_MAJOR_VERSION != RTC_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (RTC_DRV_CFG_H_SW_MINOR_VERSION != RTC_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (RTC_DRV_CFG_H_SW_PATCH_VERSION != RTC_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Rtc_Drv_Cfg.h and Rtc_Drv_PBcfg.h are different"
#endif

/** 
 * @brief Defines Rtc Driver configuration.
 */
#define RTC_DRV_CONFIG_EXT \
    RTC_DRV_CONFIG_PB

/**
 * @brief Dev error detect switch
 */
#define RTC_DRV_DEV_ERROR_DETECT           (STD_OFF)

/**
 * @brief Switches the Rtc user mode functionality ON or OFF.  
 * @details If it is STD_ON, then the Rtc driver code can be executed in both supervisor and 
 *          user mode.
 */
#define RTC_DRV_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/**
 * @brief Switches the Rtc standby mode functionality ON or OFF. 
 */
#define RTC_DRV_STANDBY_WAKEUP_SUPPORT    (STD_OFF)

/**
* @brief Rtc timeout type
*/
#define RTC_DRV_TIMEOUT_TYPE    (MCALLIB_COUNTER_SOFTWARE)

/**
* @brief Number of loops before returning RTC_STATUS_TIMEOUT.
*/
#define RTC_DRV_TIMEOUT_VALUE    (800U)


/**
 * @brief Defines if Rtc channel is used in all configurations.
 */
#define RTC_DRV_ENABLE        (STD_OFF)

/**
* @brief IRQ Defines for each channel used
*/
#define RTC_DRV_ISR_ENABLE  (STD_OFF)

/**
* @brief  Switches the Rtc compensation functionality ON or OFF.
*/
#define RTC_DRV_ENABLE_COMPENSATION_SUPPORT    STD_OFF

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */


#ifdef __cplusplus
}
#endif

/** @} end of group Rtc_Drv_Configuration */

/** @} end of group Rtc_Module */

#endif 
