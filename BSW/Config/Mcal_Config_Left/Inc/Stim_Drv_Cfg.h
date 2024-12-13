/**************************************************************************************************/
/**
 * @file      : Stim_Drv_Cfg.h  
 * @brief     : Stim module - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef STIM_DRV_CFG_H
#define STIM_DRV_CFG_H

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
#include "Stim_Drv_PBcfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define STIM_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define STIM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define STIM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define STIM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define STIM_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define STIM_DRV_CFG_H_SW_MINOR_VERSION            2U
#define STIM_DRV_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Stim_Drv_PBcfg.h are the same vendor */
#if (STIM_DRV_CFG_H_VENDOR_ID != STIM_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Stim_Drv_Cfg.h and Stim_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Stim_Drv_PBcfg.h are the same Autosar version */
#if ((STIM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != STIM_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (STIM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != STIM_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (STIM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != STIM_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Stim_Drv_Cfg.h and Stim_Drv_PBcfg.h are different"
#endif
/* Check if current file and Stim_Drv_PBcfg.h are the same software version */
#if ((STIM_DRV_CFG_H_SW_MAJOR_VERSION != STIM_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (STIM_DRV_CFG_H_SW_MINOR_VERSION != STIM_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (STIM_DRV_CFG_H_SW_PATCH_VERSION != STIM_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Stim_Drv_Cfg.h and Stim_Drv_PBcfg.h are different"
#endif

/** 
 * @brief Defines Stim Driver configuration.
 */
#define STIM_DRV_CONFIG_EXT \
    STIM_DRV_CONFIG_PB
/**
* @brief Dev error detect switch 
*/
#define STIM_DRV_DEV_ERROR_DETECT   (STD_OFF)

/**
* @brief Switches the stim predfined timer functionality ON or OFF.
*/
#define STIM_DRV_PREDEFTIMER_FUNCTIONALITY_API (STD_OFF)

/**
* @brief Switches the stim standby wakeup functionality ON or OFF. 
* @details This not supported in this release
*/
#define STIM_DRV_STANDBY_WAKEUP_SUPPORT   (STD_OFF)


/**
 * @brief Defines if Stim channel is used in all configurations.
 */
#define STIM_DRV_ENABLE      (STD_ON)

/**
 * @brief IRQ Defines for each channel used
 */
#define STIM_DRV_ISR_ENABLE    (STD_ON)

/**
* @brief Switches the stim dual mode functionality ON or OFF. 
*/
#define STIM_DRV_SET_DUAL_CLOCK_MODE    (STD_OFF)

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

/** @} end of group Stim_Drv_Configuration */

/** @} end of group Stim_Module */

#endif 
