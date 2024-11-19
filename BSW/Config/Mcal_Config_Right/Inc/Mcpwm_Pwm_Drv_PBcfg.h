/*************************************************************************************/
/**
 * @file      : Mcpwm_Pwm_Drv_PBcfg.h  
 * @brief     : Pwm low level driver - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef MCPWM_PWM_DRV_PBCFG_H
#define MCPWM_PWM_DRV_PBCFG_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Mcpwm_Pwm_Drv_Configuration
 *  @brief Pwm low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define MCPWM_PWM_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define MCPWM_PWM_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCPWM_PWM_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MCPWM_PWM_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MCPWM_PWM_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define MCPWM_PWM_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define MCPWM_PWM_DRV_PBCFG_H_SW_PATCH_VERSION            2U


/**
 * @brief Mcpwm instance index for configuration McpwmCh_FAN_CTR.
 */
#define MCPWM_PWM_DRV_I0_CH0_CFG      (0U)
/**
 * @brief Mcpwm instance index for configuration McpwmCh_DC_Ctr.
 */
#define MCPWM_PWM_DRV_I0_CH2_CFG      (0U)
/**
 * @brief Mcpwm instance index for configuration Pwm_ALS_NXT.
 */
#define MCPWM_PWM_DRV_I1_CH0_CFG      (1U)
/**
 * @brief Mcpwm instance index for configuration Pwm_AFS_NXT.
 */
#define MCPWM_PWM_DRV_I1_CH6_CFG      (1U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define MCPWM_PWM_DRV_CONFIG_PB \
    extern const Mcpwm_Pwm_Drv_UserCfgType Mcpwm_Pwm_Drv_User0_Cfg; \
    extern const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I0_Ch0_Cfg; \
    extern const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I0_Ch2_Cfg; \
    extern const Mcpwm_Pwm_Drv_UserCfgType Mcpwm_Pwm_Drv_User1_Cfg; \
    extern const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I1_Ch0_Cfg; \
    extern const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I1_Ch6_Cfg; \


/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */


#ifdef __cplusplus
}
#endif

/** @} */

/** @} end of group Mcpwm_Pwm_Drv_Configuration */

/** @} end of group Pwm_Module */
#endif 

