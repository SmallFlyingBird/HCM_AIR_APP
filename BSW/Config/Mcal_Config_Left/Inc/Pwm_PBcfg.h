/*************************************************************************************/
/**
 * @file      : Pwm_PBcfg.h  
 * @brief     : Pwm AUTOSAR level - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

#ifndef PWM_PB_CFG_H
#define PWM_PB_CFG_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Configuration
 *  @brief Pwm AUTOSAR level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
/** @defgroup Public_MacroDefinition
 *  @{
 */

#define PWM_PBCFG_H_VENDOR_ID                   0x00B3U
#define PWM_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PWM_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PWM_PBCFG_H_SW_MAJOR_VERSION            1U
#define PWM_PBCFG_H_SW_MINOR_VERSION            2U
#define PWM_PBCFG_H_SW_PATCH_VERSION            2U

/**
* @brief Defines PWM configuration
*/
#define PWM_PB_CFG_CHANNELS_COUNT           ((uint8)4U)

/**
* @brief Total number of configured PWM instances
*/
#define PWM_PB_CFG_INSTANCES_COUNT          ((uint8)2U)

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


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

/** @} */

#ifdef __cplusplus
}
#endif


#endif /* PWM_PB_CFG_H */


/** @} end of group Pwm_Configuration */

/** @} end of group Pwm_Module */
