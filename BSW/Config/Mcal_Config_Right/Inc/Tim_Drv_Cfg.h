/**************************************************************************************************/
/**
 * @file      : Tim_Drv_Cfg.h  
 * @brief     : Tim module - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TIM_DRV_CFG_H
#define TIM_DRV_CFG_H

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
#include "Tim_Drv_PBcfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define TIM_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define TIM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define TIM_DRV_CFG_H_SW_MINOR_VERSION            2U
#define TIM_DRV_CFG_H_SW_PATCH_VERSION            1U

/* Check if current file and Tim_Drv_PBcfg.h are the same vendor */
#if (TIM_DRV_CFG_H_VENDOR_ID != TIM_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Tim_Drv_Cfg.h and Tim_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Tim_Drv_PBcfg.h are the same Autosar version */
#if ((TIM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != TIM_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != TIM_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != TIM_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Tim_Drv_Cfg.h and Tim_Drv_PBcfg.h are different"
#endif
/* Check if current file and Tim_Drv_PBcfg.h are the same software version */
#if ((TIM_DRV_CFG_H_SW_MAJOR_VERSION != TIM_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (TIM_DRV_CFG_H_SW_MINOR_VERSION != TIM_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (TIM_DRV_CFG_H_SW_PATCH_VERSION != TIM_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Tim_Drv_Cfg.h and Tim_Drv_PBcfg.h are different"
#endif

/** 
 * @brief Defines Tim Driver configuration.
 */
#define TIM_DRV_CONFIG_EXT \
    TIM_DRV_CONFIG_PB
/**
* @brief Dev error detect switch 
*/
#define TIM_DRV_DEV_ERROR_DETECT   (STD_OFF)

/**
* @brief Switches the Tim predfined timer functionality ON or OFF.
*/
#define TIM_DRV_PREDEFTIMER_FUNCTIONALITY_API (STD_OFF)



/** 
 * @brief Defines TIM TIM_1 used config.
 */
#ifndef TIM_1_USED
    #define TIM_1_USED
    #define TIM_DRV_ENABLE      (STD_ON)
#else
    #error "TIM_1 may be used by other module, please check it !"
#endif


/**
 * @brief IRQ Defines for each channel used
*/
#define TIM_DRV_0_ISR_ENABLE    (STD_OFF)
#define TIM_DRV_1_ISR_ENABLE    (STD_ON)
#define TIM_DRV_2_ISR_ENABLE    (STD_OFF)
#define TIM_DRV_3_ISR_ENABLE    (STD_OFF)
/**
* @brief Switches the Tim dual mode functionality ON or OFF. 
*/
#define TIM_DRV_SET_DUAL_CLOCK_MODE    (STD_OFF)

#define TIM_DRV_CHANNEL_SUMCNT (8U)

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

/** @} end of group Tim_Drv_Configuration */

/** @} end of group Tim_Module */

#endif 
