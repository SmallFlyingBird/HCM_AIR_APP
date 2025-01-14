/**************************************************************************************************/
/**
 * @file      : Wdog_Drv_Cfg.h  
 * @brief     : Wdg AUTOSAR level - Pre-Compile(PC) configuration file 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef WDOG_DRV_CFG_H
#define WDOG_DRV_CFG_H

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
#include "Wdog_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDOG_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define WDOG_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDOG_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define WDOG_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define WDOG_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define WDOG_DRV_CFG_H_SW_MINOR_VERSION            2U
#define WDOG_DRV_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Wdog_Drv_PBcfg.h are the same vendor */
#if (WDOG_DRV_CFG_H_VENDOR_ID != WDOG_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Wdog_Drv_Cfg.h and Wdog_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Wdog_Drv_PBcfg.h are the same Autosar version */
#if ((WDOG_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != WDOG_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDOG_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != WDOG_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (WDOG_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != WDOG_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdog_Drv_Cfg.h and Wdog_Drv_PBcfg.h are different"
#endif
/* Check if current file and Wdog_Drv_PBcfg.h are the same software version */
#if ((WDOG_DRV_CFG_H_SW_MAJOR_VERSION != WDOG_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (WDOG_DRV_CFG_H_SW_MINOR_VERSION != WDOG_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (WDOG_DRV_CFG_H_SW_PATCH_VERSION != WDOG_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Wdog_Drv_Cfg.h and Wdog_Drv_PBcfg.h are different"
#endif

/**
 * @brief Defines Wdg Driver configuration.
 */
#define WDOG_DRV_CONFIG_EXT \
        WDOG_DRV_CONFIG_PB

/** 
* @brief  Defines the development error detect switch
*/
#define WDOG_DRV_DEV_ERROR_DETECT    (STD_OFF)

/** 
* @brief  Defines the watchdog ISR switch in Drv level
*/
#define WDOG_DRV_ISR_ENABLED      (STD_OFF)

/**
* @brief  It indicates if disabled is allowed
*/
#define WDOG_DRV_DISABLE_ALLOWED    (STD_OFF)

/**
* @brief Defines the watchdog configuration complete timeout cycle
*/
#define WDOG_DRV_HW_WAIT_TIMEOUT_CYCLE     (104857U)

/**
* @brief  Defines the watchdog running area: RAM/ROM
*/
#define WDG_DRV_RUN_IN_ROM (1U)


/** @} end of Public_MacroDefinition */

#ifdef __cplusplus
}
#endif
#endif /* WDOG_DRV_CFG_H */
