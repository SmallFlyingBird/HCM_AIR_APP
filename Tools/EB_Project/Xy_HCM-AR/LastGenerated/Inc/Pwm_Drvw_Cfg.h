/*************************************************************************************/
/**
 * @file      : Pwm_Drvw_Cfg.h
 * @brief     : Pwm driver wrapper - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef PWM_DRVW_CFG_H
#define PWM_DRVW_CFG_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Drvw_Configuration
 *  @brief Pwm driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pwm_Drvw_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PWM_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define PWM_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PWM_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PWM_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define PWM_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define PWM_DRVW_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and PWM_DRVW_PBcfg.h are the same vendor */
#if (PWM_DRVW_CFG_H_VENDOR_ID != PWM_DRVW_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of PWM_DRVW_Cfg.h and PWM_DRVW_PBcfg.h are different"
#endif
    /* Check if current file and PWM_DRVW_PBcfg.h are the same Autosar version */
#if ((PWM_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION != PWM_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION != PWM_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION != PWM_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of PWM_DRVW_Cfg.h and PWM_DRVW_PBcfg.h are different"
#endif
/* Check if current file and PWM_DRVW_PBcfg.h are the same software version */
#if ((PWM_DRVW_CFG_H_SW_MAJOR_VERSION != PWM_DRVW_PBCFG_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_CFG_H_SW_MINOR_VERSION != PWM_DRVW_PBCFG_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_CFG_H_SW_PATCH_VERSION != PWM_DRVW_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of PWM_DRVW_Cfg.h and PWM_DRVW_PBcfg.h are different"
#endif

#define PWM_DRVW_CONFIG_EXT \
    PWM_DRVW_CONFIG_PB 


/**
* @brief Switch to enable the development error detection.
*/
#define PWM_DRVW_DEV_ERROR_DETECT                      (STD_ON)

/**
* @brief Switch to indicate that Pwm_DeInit API is supported.
*/
#define PWM_DRVW_DE_INIT_API                           (STD_ON)

/**
* @brief Switch to indicate that Pwm_GetOutputState API is supported
*/
#define PWM_DRVW_GET_OUTPUT_STATE_API                  (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetDutyCycle API is supported.
*/
#define PWM_DRVW_SET_DUTY_CYCLE_API                    (STD_ON)

/**
 * @brief Switch to enable the update of the duty cycle parameter at the end of the current period.
 */
#define PWM_DRVW_DUTYCYCLE_UPDATED_ENDPERIOD           (STD_ON)

/**
 * @brief Switch to enable the update of the period parameter at the end of the current period.
 */
#define PWM_DRVW_DUTY_PERIOD_UPDATED_ENDPERIOD         (STD_ON)

/**
* @brief Switch to indicate that Pwm_EnableTriggerOutput API is supported.
*/
#define PWM_DRVW_ENABLE_TRIGGER_OUTPUT_API             (STD_ON)

/**
* @brief Switch to indicate that Pwm_DisableTriggerOutput API is supported.
*/
#define PWM_DRVW_DISABLE_TRIGGER_OUTPUT_API            (STD_ON)

/**
* @brief Switch to enable the mask output feature (Pwm_MaskOutput and Pwm_UnMaskOutput API).
*/
#define PWM_DRVW_ENABLE_MASKING_OPERATIONS             (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetPeriodAndDuty API is supported.
*/
#define PWM_DRVW_SET_PERIOD_AND_DUTY_API               (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetOutputToIdle API is supported.
*/
#define PWM_DRVW_SET_OUTPUT_TO_IDLE_API                (STD_ON)

/**
* @brief Switch to indicate that Pwm_ForceOutputToLowLevel API is supported.
*/
#define PWM_DRVW_FORCE_OUTPUT_TO_LOW_LEVEL_API         (STD_ON)

/**
* @brief Add/remove the service Pwm_SetChannelDeadTimeTicks() from the code.
*/
#define PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API       (STD_ON)

/**
* @brief Switch to indicate that Pwm_WritePhaseShiftTicksToBuffer API is supported.
*/
#define PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetPhaseShift API is supported.
*/
#define PWM_DRVW_SET_PHASE_SHIFT_TICKS_API             (STD_ON)

/**
* @brief Switch to indicate that Pwm_WriteDutyCycleToBuffer API is supported.
*/
#define PWM_DRVW_WRITE_DUTY_CYCLE_TO_BUFFER_API        (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetDutyPhaseShiftTicks API is supported.
*/
#define PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API    (STD_ON)

/**
* @brief Switch to indicate that Pwm_SyncUpdate API is supported.
*/
#define PWM_DRVW_SYNC_UPDATE_API                       (STD_ON)

/**
* @brief Switch to indicate that Pwm_WritePeriodAndDutyToBuffer API is supported.
*/
#define PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API   (STD_ON)

/**
* @brief Switch to indicate that Pwm_GetChannelDutyCycle API is supported.
*/
#define PWM_DRVW_GET_CHANNEL_DUTYCYCLE_API             (STD_ON)

/**
* @brief Switch to indicate that the notifications are supported
*/
#define PWM_DRVW_NOTIFICATION_SUPPORTED                (STD_ON)

/**
* @brief Switch to enable that power state mode is supported
*/
#define PWM_DRVW_LOW_POWER_STATE_SUPPORTED             (STD_ON)

/**
* @brief Switch to indicate that platform-specific validation of the period is supported.
*/
#define PWM_DRVW_MAX_PERIOD_PLAUSABILITY               (STD_OFF)

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

#endif

/** @} end of group Pwm_Drvw_Configuration */

/** @} end of group Pwm_Module */
