/*************************************************************************************/
/**
 * @file      : Pwm_Drvw_PBcfg.h  
 * @brief     : Pwm driver wrapper - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef PWM_DRVW_PBCFG_H
#define PWM_DRVW_PBCFG_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Mcpwm_Pwm_Drv_Configuration
 *  @brief Pwm driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define PWM_DRVW_PBCFG_H_VENDOR_ID                   0x00B3U
#define PWM_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PWM_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PWM_DRVW_PBCFG_H_SW_MAJOR_VERSION            1U
#define PWM_DRVW_PBCFG_H_SW_MINOR_VERSION            2U
#define PWM_DRVW_PBCFG_H_SW_PATCH_VERSION            2U


/**
* @brief Total number of configured Pwm_Drvw instances
*/
#define PWM_DRVW_PB_CFG_INSTANCES_COUNT          ((uint8)2U)

/**
* @brief Defines Pwm_Drvw configuration
*/
#define PWM_DRVW_CONFIG_PB \
    extern const Pwm_Drvw_HwConfigType Pwm_Instances[PWM_DRVW_PB_CFG_INSTANCES_COUNT]; \
    extern const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch0_Config; \
    extern const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch1_Config; \
    extern const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch2_Config; \
    extern const Pwm_Drvw_ChannelConfigType Pwm_Drvw_Ch3_Config; \

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

/** @} end of group Mcpwm_Pwm_Drv_Configuration */

/** @} end of group Pwm_Module */
#endif 

