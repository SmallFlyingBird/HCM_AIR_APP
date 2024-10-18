/**************************************************************************************************/
/**
 * @file      : Wdg_Drvw_Cfg.h  
 * @brief     : Wdg driver wrapper - Pre-Compile(PC) configuration file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef WDG_DRVW_CFG_H
#define WDG_DRVW_CFG_H

/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drvw_Configuration
 *  @brief Wdg driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
#include "Wdg_Drvw_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define WDG_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define WDG_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define WDG_DRVW_CFG_H_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_Drvw_PBcfg.h are the same vendor */
#if (WDG_DRVW_CFG_H_VENDOR_ID != WDG_DRVW_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Drvw_Cfg.h and Wdg_Drvw_PBcfg.h are different"
#endif
    /* Check if current file and Wdg_Drvw_PBcfg.h are the same Autosar version */
#if ((WDG_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION != WDG_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION != WDG_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION != WDG_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_Drvw_Cfg.h and Wdg_Drvw_PBcfg.h are different"
#endif
/* Check if current file and Wdg_Drvw_PBcfg.h are the same software version */
#if ((WDG_DRVW_CFG_H_SW_MAJOR_VERSION != WDG_DRVW_PBCFG_H_SW_MAJOR_VERSION) || \
     (WDG_DRVW_CFG_H_SW_MINOR_VERSION != WDG_DRVW_PBCFG_H_SW_MINOR_VERSION) || \
     (WDG_DRVW_CFG_H_SW_PATCH_VERSION != WDG_DRVW_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Wdg_Drvw_Cfg.h and Wdg_Drvw_PBcfg.h are different"
#endif

/** 
 * @brief Defines Wdg Driver Wrapper configuration.
 */
#define WDG_DRVW_CONFIG_EXT \
        WDG_DRVW_CONFIG_PB

/**
* @brief   Defines the watchdog disable allowed switch in Drvw level
*/
#define WDG_DRVW_DISABLE_ALLOWED       (WDOG_DRV_DISABLE_ALLOWED)

/**
* @brief   Defines the watchdog direct service switch in Drvw level
*/
#define WDG_DRVW_DIRECT_SERVICE        (STD_ON)

/** @} end of Public_MacroDefinition */

#ifdef __cplusplus
}
#endif
/** @} */
#endif /* WDG_DRVW_CFG_H */
