/*************************************************************************************/
/**
 * @file      : Tim_Pwm_Drv_PBcfg.h  
 * @brief     : Pwm low level driver - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef TIM_PWM_DRV_PBCFG_H
#define TIM_PWM_DRV_PBCFG_H

/** @addtogroup  Tim_Pwm_Module
 *  @{
 */

/** @addtogroup Tim_Pwm_Drv_Configuration
 *  @brief Pwm low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define TIM_PWM_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define TIM_PWM_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_PWM_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_PWM_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_PWM_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define TIM_PWM_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define TIM_PWM_DRV_PBCFG_H_SW_PATCH_VERSION            2U


/**
 * @brief Tim instance index for configuration PwmTimCh_6.
 */
#define TIM_PWM_DRV_I0_CH6_CFG      (0U)
/**
 * @brief Tim instance index for configuration PwmTimCh_7.
 */
#define TIM_PWM_DRV_I0_CH7_CFG      (0U)
/**
 * @brief Tim instance index for configuration PwmTimCh_0.
 */
#define TIM_PWM_DRV_I1_CH0_CFG      (1U)
/**
 * @brief Tim instance index for configuration PwmTimCh_7.
 */
#define TIM_PWM_DRV_I1_CH7_CFG      (1U)
/**
 * @brief Tim instance index for configuration PwmTimCh_6.
 */
#define TIM_PWM_DRV_I1_CH6_CFG      (1U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define TIM_PWM_DRV_CONFIG_PB \
    extern const Tim_Pwm_Drv_UserCfgType Tim_Pwm_Drv_User0_Cfg; \
    extern const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch6_Cfg; \
    extern const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I0_Ch7_Cfg; \
    extern const Tim_Pwm_Drv_UserCfgType Tim_Pwm_Drv_User1_Cfg; \
    extern const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch0_Cfg; \
    extern const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch7_Cfg; \
    extern const Tim_Pwm_Drv_ChannelConfigType Tim_Pwm_Drv_I1_Ch6_Cfg; \


/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */


#ifdef __cplusplus
}
#endif

/** @} */

/** @} end of group Tim_Pwm_Drv_Configuration */

/** @} end of group Tim_Pwm_Module */
#endif 

