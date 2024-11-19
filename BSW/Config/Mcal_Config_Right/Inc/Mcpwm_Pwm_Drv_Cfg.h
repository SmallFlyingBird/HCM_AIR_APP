/*************************************************************************************/
/**
 * @file      : Mcpwm_Pwm_Drv_Cfg.h
 * @brief     : Pwm low level driver - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef MCPWM_PWM_DRV_CFG_H
#define MCPWM_PWM_DRV_CFG_H

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


#include "Mcpwm_Pwm_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define MCPWM_PWM_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define MCPWM_PWM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCPWM_PWM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MCPWM_PWM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MCPWM_PWM_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define MCPWM_PWM_DRV_CFG_H_SW_MINOR_VERSION            2U
#define MCPWM_PWM_DRV_CFG_H_SW_PATCH_VERSION            2U


/* Check if header file and Pwm_EnvCfg header file are of the same vendor */
#if (MCPWM_PWM_DRV_CFG_H_VENDOR_ID != MCPWM_PWM_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Mcpwm_Pwm_Drv_Cfg.h and Mcpwm_Pwm_Drv_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((MCPWM_PWM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    != MCPWM_PWM_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    != MCPWM_PWM_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mcpwm_Pwm_Drv_Cfg.h and Mcpwm_Pwm_Drv_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((MCPWM_PWM_DRV_CFG_H_SW_MAJOR_VERSION != MCPWM_PWM_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_CFG_H_SW_MINOR_VERSION != MCPWM_PWM_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_CFG_H_SW_PATCH_VERSION != MCPWM_PWM_DRV_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version of Mcpwm_Pwm_Drv_Cfg.h and Mcpwm_Pwm_Drv_PBcfg.h are different."
#endif


/** 
 * @brief Defines PWM MCPWM_0 used config.
 */
#ifndef MCPWM_0_USED
    #define MCPWM_0_USED
    #define MCPWM_PWM_DRV_0_ENABLE                          (STD_ON)
#else
    #error "MCPWM_0 may be used by other module, please check it !"
#endif
/** 
 * @brief Defines PWM MCPWM_1 used config.
 */
#ifndef MCPWM_1_USED
    #define MCPWM_1_USED
    #define MCPWM_PWM_DRV_1_ENABLE                          (STD_ON)
#else
    #error "MCPWM_1 may be used by other module, please check it !"
#endif


/**
 * @brief Device Error Detect Switch.
 */
#define MCPWM_PWM_DRV_DEV_ERROR_DETECT                      (STD_OFF)

/**
 * @brief Switch to indicate that the notifications are supported.
 */
#define MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED                (STD_ON)

/**
 * @brief Add/remove the service Pwm_SetChannelDeadTimeTicks() from the code.
 */
#define MCPWM_PWM_DRV_SET_CHANNEL_DEAD_TIME_TICKS_API       (STD_OFF)

/**
 * @brief Number of MCPWM instances.
 */
#define MCPWM_PWM_DRV_INSTANCE_NUM                          (2U)

/**
 * @brief Number of MCPWM channels.
 */
#define MCPWM_PWM_DRV_CHANNEL_NUM                           (8U)

/**
 * @brief Number of MCPWM pairs.
 */
#define MCPWM_PWM_DRV_PAIR_CHANNEL_NUM                      (MCPWM_PWM_DRV_CHANNEL_NUM >> 1U)

/**
 * @brief Number of MCPWM Counters.
 */
#define MCPWM_PWM_DRV_COUNTER_NUM                           (MCPWM_PWM_DRV_CHANNEL_NUM >> 1U)

/**
 * @brief Defines MCPWM Driver configuration.
 */
#define MCPWM_PWM_DRV_CONFIG_EXT \
    MCPWM_PWM_DRV_CONFIG_PB

/**
 * @brief Defines MCPWM interrupt enanble or not.
 */
#define MCPWM_PWM_DRV_0_OVF_ISR_ENABLE                      (STD_ON)
#define MCPWM_PWM_DRV_0_CH_ISR_ENABLE                       (STD_ON)
#define MCPWM_PWM_DRV_1_OVF_ISR_ENABLE                      (STD_ON)
#define MCPWM_PWM_DRV_1_CH_ISR_ENABLE                       (STD_ON)

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
