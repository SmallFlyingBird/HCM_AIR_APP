/*************************************************************************************/
/**
 * @file      : Tim_Pwm_Drv_Cfg.h
 * @brief     : Pwm low level driver - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef TIM_PWM_DRV_CFG_H
#define TIM_PWM_DRV_CFG_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Configuration
 *  @brief Pwm low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif


#include "Tim_Pwm_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define TIM_PWM_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define TIM_PWM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_PWM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_PWM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_PWM_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define TIM_PWM_DRV_CFG_H_SW_MINOR_VERSION            2U
#define TIM_PWM_DRV_CFG_H_SW_PATCH_VERSION            2U


/* Check if header file and Pwm_EnvCfg header file are of the same vendor */
#if (TIM_PWM_DRV_CFG_H_VENDOR_ID != TIM_PWM_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Tim_Pwm_Drv_Cfg.h and Tim_Pwm_Drv_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((TIM_PWM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    != TIM_PWM_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_PWM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    != TIM_PWM_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_PWM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Tim_Pwm_Drv_Cfg.h and Tim_Pwm_Drv_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((TIM_PWM_DRV_CFG_H_SW_MAJOR_VERSION != TIM_PWM_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (TIM_PWM_DRV_CFG_H_SW_MINOR_VERSION != TIM_PWM_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (TIM_PWM_DRV_CFG_H_SW_PATCH_VERSION != TIM_PWM_DRV_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Pwm_Drv_Cfg.h and Tim_Pwm_Drv_PBcfg.h are different."
#endif



/**
 * @brief Device Error Detect Switch.
 */
#define TIM_PWM_DRV_DEV_ERROR_DETECT           (STD_OFF)

/**
 * @brief Switch to indicate that the notifications are supported.
 */
#define TIM_PWM_DRV_NOTIFICATION_SUPPORTED     (STD_ON)

/**
 * @brief Number of TIM instances.
 */
#define TIM_PWM_DRV_INSTANCE_NUM               (4U)

/**
 * @brief Number of TIM Channels.
 */
#define TIM_PWM_DRV_CHANNEL_NUM                (8U)

/**
 * @brief Number of TIM pairs.
 */
#define TIM_PWM_DRV_PAIR_CHANNEL_NUM           (TIM_PWM_DRV_CHANNEL_NUM >> 1U)

/**
 * @brief Defines TIM Driver configuration.
 */
#define TIM_PWM_DRV_CONFIG_EXT \
    TIM_PWM_DRV_CONFIG_PB

/**
 * @brief Defines TIM interrupt enanble or not.
 */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

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

/** @} end of group Pwm_Configuration */

/** @} end of group Pwm_Module */

#endif
