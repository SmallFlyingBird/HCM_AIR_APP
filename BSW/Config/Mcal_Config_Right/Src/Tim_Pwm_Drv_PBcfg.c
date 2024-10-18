/*************************************************************************************/
/**
 * @file      : Tim_Pwm_Drv_PBcfg.c  
 * @brief     : Pwm low level driver - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Tim_Pwm_Drv_Configuration
 *  @brief Pwm low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tim_Pwm_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_PWM_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_PWM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_PWM_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define TIM_PWM_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define TIM_PWM_DRV_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if source file and Tim_Pwm_Drv.h header file are of the same vendor */
#if (TIM_PWM_DRV_PBCFG_C_VENDOR_ID != TIM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor IDs of Tim_Pwm_Drv_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/* Check if source file and Tim_Pwm_Drv.h header file are of the same AUTOSAR version */
#if ((TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Tim_Pwm_Drv_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/* Check if source file and Tim_Pwm_Drv.h header file are of the same software version */
#if ((TIM_PWM_DRV_PBCFG_C_SW_MAJOR_VERSION != TIM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_SW_MINOR_VERSION != TIM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (TIM_PWM_DRV_PBCFG_C_SW_PATCH_VERSION != TIM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software version numbers of Tim_Pwm_Drv_PBcfg.c and Tim_Pwm_Drv.h are different."
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#ifndef TIM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"







#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#endif  /*TIM_PWM_DRV_PRECOMPILE_SUPPORT */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Pwm_Drv_Configuration */

/** @} end of group Pwm_Module */
