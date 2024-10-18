/**************************************************************************************************/
/**
 * @file      : Wdg_Cfg.h  
 * @brief     : Wdg AUTOSAR level - Pre-Compile(PC) configuration file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef WDG_CFG_H
#define WDG_CFG_H

/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Configuration
 *  @brief Wdg AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define WDG_CFG_H_VENDOR_ID                   0x00B3U
#define WDG_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_CFG_H_SW_MAJOR_VERSION            1U
#define WDG_CFG_H_SW_MINOR_VERSION            2U
#define WDG_CFG_H_SW_PATCH_VERSION            1U

/* Check if  header file and Wdg_PBcfg.h file are of the same vendor */
#if (WDG_CFG_H_VENDOR_ID != WDG_PBCFG_H_VENDOR_ID)
    #error " Vendor id of Wdg_Cfg.h and Wdg_PBcfg.h are different"
#endif
/* Check if  header file and Wdg_PBcfg.h file are of the same Autosar version */
#if ((WDG_CFG_H_AR_RELEASE_MAJOR_VERSION    != WDG_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_CFG_H_AR_RELEASE_MINOR_VERSION    != WDG_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
    (WDG_CFG_H_AR_RELEASE_REVISION_VERSION != WDG_PBCFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Cfg.h and Wdg_PBcfg.h are different"
#endif
/* Check if header file and Wdg_PBcfg.h file are of the same Software version */
#if ((WDG_CFG_H_SW_MAJOR_VERSION != WDG_PBCFG_H_SW_MAJOR_VERSION) || \
    (WDG_CFG_H_SW_MINOR_VERSION != WDG_PBCFG_H_SW_MINOR_VERSION) || \
    (WDG_CFG_H_SW_PATCH_VERSION != WDG_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Cfg.h and Wdg_PBcfg.h are different"
#endif


/**
* @brief Report switch of reporting that disabling watchdog mode failed 
*/
#define   WDG_E_DISABLE_REJECTED_ENABLE       STD_OFF

/**
* @brief Defines the watchdog extended production error switch
*/
#define   WDG_E_MODE_FAILED_ENABLE       STD_OFF


/**
 * @brief  It indicates if disabling the Wdg hardware is allowed
 */
#define WDG_DISABLE_ALLOWED    (WDG_DRVW_DISABLE_ALLOWED)

/**
* @brief  switch to enable/disable development error detection
*/
#define WDG_DEV_ERROR_DETECT (STD_OFF)

/**
* @brief  switch to enable/disable watchdog direct service.
*/
#define WDG_DIRECT_SERVICE        (STD_ON)

/**
* @brief  switch to enable/disable the get version information  API
*/
#define WDG_VERSION_INFO_API (STD_ON)


/**
* @brief  Defines the watchdog hardware index of the MCU
*/
#define WDG_INSTANCE_WDOG                   ((uint8)0U) 
/**
* @brief  Defines the wdg index symbolic name
*/
#define WdgConf_WdgGeneral_WdgGeneral         (WDG_INSTANCE_WDOG)

/**
* @brief  Defines the watchdog pre-compile switch
*/
#define WDG_PRECOMPILE_SUPPORT (STD_OFF)

/**
* @brief Defines WDG configuration
*/
#define WDG_CONFIG_EXT \
    WDG_CONFIG_PB


/** @} end of Public_MacroDefinition */

#ifdef __cplusplus
}
#endif
/** @} */
#endif /* WDG_CFG_H */
