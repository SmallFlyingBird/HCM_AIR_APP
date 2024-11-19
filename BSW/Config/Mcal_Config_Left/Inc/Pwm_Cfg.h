/**************************************************************************************************/
/**
 * @file      : Pwm_Cfg.h  
 * @brief     : Pwm AUTOSAR level - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PWM_CFG_H
#define PWM_CFG_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Configuration
 *  @brief Pwm AUTOSAR level Configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif




#include "Pwm_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PWM_CFG_H_VENDOR_ID                   0x00B3U
#define PWM_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PWM_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PWM_CFG_H_SW_MAJOR_VERSION            1U
#define PWM_CFG_H_SW_MINOR_VERSION            2U
#define PWM_CFG_H_SW_PATCH_VERSION            2U


/* Check if header file and PWM configuration header file are of the same vendor */
#if (PWM_CFG_H_VENDOR_ID != PWM_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Cfg.h and PWM_PBcfg.h are different"
#endif
    /* Check if header file and Pwm configuration header file are of the same Autosar version */
#if ((PWM_CFG_H_AR_RELEASE_MAJOR_VERSION != PWM_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_CFG_H_AR_RELEASE_MINOR_VERSION != PWM_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_CFG_H_AR_RELEASE_REVISION_VERSION != PWM_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Pwm_Cfg.h and Pwm_PBcfg.h are different"
#endif
/* Check if header file and Pwm configuration header file are of the same software version */
#if ((PWM_CFG_H_SW_MAJOR_VERSION != PWM_PBCFG_H_SW_MAJOR_VERSION) || \
     (PWM_CFG_H_SW_MINOR_VERSION != PWM_PBCFG_H_SW_MINOR_VERSION) || \
     (PWM_CFG_H_SW_PATCH_VERSION != PWM_PBCFG_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Pwm_Cfg.h and Pwm_PBcfg.h are different"
#endif


/**
 * @brief Maximum number of configured partitions.
 */
#define PWM_MAX_PARTITIONS                        (1U)

/**
 * @brief Specifies the InstanceId of this module instance.
 * @note  If only one instance is present it shall have the Id 0.
 */
#define PWM_INDEX                                 (0U)

/**
 * @brief Total number of Pwm logic channels configured.
 */
#define PWM_CONFIG_LOGIC_CHANNELS                 (4U)

/**
 * @brief Maximum number of channels supported by hardware.
 */
#define PWM_HW_CHANNEL_NO                         (48U)

/**
 * @brief Pre-compile configuration constants.
 */
#define PWM_PRECOMPILE_SUPPORT                    (STD_ON)

/**
 * @brief Switch to indicate that Pwm_GetVersionInfo API is supported.
 */
#define PWM_VERSION_INFO_API                      (STD_ON)

/**
 * @brief Switch to enable that power state mode is supported.
 */
#define PWM_LOW_POWER_STATE_SUPPORTED             (STD_ON)

/**
* @brief Switch to enable the development error detection.
*/
#define PWM_DEV_ERROR_DETECT                      (STD_ON)

/**
* @brief Switch to indicate that Pwm_DeInit API is supported.
*/
#define PWM_DE_INIT_API                           (STD_ON)

/**
* @brief Switch to indicate that Pwm_GetOutputState API is supported
*/
#define PWM_GET_OUTPUT_STATE_API                  (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetDutyCycle API is supported.
*/
#define PWM_SET_DUTY_CYCLE_API                    (STD_ON)

/**
* @brief Switch to indicate that Pwm_EnableTriggerOutput API is supported.
*/
#define PWM_ENABLE_TRIGGER_OUTPUT_API             (STD_ON)

/**
* @brief Switch to indicate that Pwm_DisableTriggerOutput API is supported.
*/
#define PWM_DISABLE_TRIGGER_OUTPUT_API            (STD_ON)

/**
* @brief Switch to enable the mask output feature (Pwm_MaskOutput and Pwm_UnMaskOutput API).
*/
#define PWM_ENABLE_MASKING_OPERATIONS             (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetPeriodAndDuty API is supported.
*/
#define PWM_SET_PERIOD_AND_DUTY_API               (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetOutputToIdle API is supported.
*/
#define PWM_SET_OUTPUT_TO_IDLE_API                (STD_ON)

/**
* @brief Switch to indicate that Pwm_ForceOutputToLowLevel API is supported.
*/
#define PWM_FORCE_OUTPUT_TO_LOW_LEVEL_API         (STD_ON)

/**
* @brief Add/remove the service Pwm_SetChannelDeadTimeTicks() from the code.
*/
#define PWM_SET_CHANNEL_DEAD_TIME_TICKS_API       (STD_ON)

/**
* @brief Switch to indicate that Pwm_WritePhaseShiftTicksToBuffer API is supported.
*/
#define PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetPhaseShift API is supported.
*/
#define PWM_SET_PHASE_SHIFT_TICKS_API             (STD_ON)

/**
* @brief Switch to indicate that Pwm_WriteDutyCycleToBuffer API is supported.
*/
#define PWM_WRITE_DUTY_CYCLE_TO_BUFFER_API        (STD_ON)

/**
* @brief Switch to indicate that Pwm_SetDutyPhaseShiftTicks API is supported.
*/
#define PWM_SET_DUTY_AND_PHASE_SHIFT_TICKS_API    (STD_ON)

/**
* @brief Switch to indicate that Pwm_SyncUpdate API is supported.
*/
#define PWM_SYNC_UPDATE_API                       (STD_ON)

/**
* @brief Switch to indicate that Pwm_WritePeriodAndDutyToBuffer API is supported.
*/
#define PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API   (STD_ON)

/**
* @brief Switch to indicate that Pwm_GetChannelDutyCycle API is supported.
*/
#define PWM_GET_CHANNEL_DUTYCYCLE_API             (STD_ON)

/**
* @brief Switch to indicate that the notifications are supported
*/
#define PWM_NOTIFICATION_SUPPORTED                (STD_ON)

/**
* @brief Switch to indicate that platform-specific validation of the period is supported.
*/
#define PWM_MAX_PERIOD_PLAUSABILITY               (STD_OFF)

/**
* @brief Maximum number of all hardware Mcpwm modules available on this platform.
*/
#define PWM_HW_MODULE_MCPWM_NO_MAX                ((uint8)2U)

/**
* @brief Maximum number of all hardware Tim modules available on this platform.
*/
#define PWM_HW_MODULE_TIM_NO_MAX                  ((uint8)4U)

/**
* @brief Switch to indicate that Mcpwm is used.
*/
#define PWM_MCPWM_USED                            (STD_OFF)

/**
* @brief Switch to indicate that Tim is used.
*/
#define PWM_TIM_USED                              (STD_ON)

/**
* @brief Total number of configured PWM Module instances
*/
#define PWM_HW_MODULE_NO_USED                     (2U)


/**
* @brief ID of all Tim hardware modules available on this platform.
*/
#define PWM_TIM_INSTANCE_0                        (uint8)(0U)
#define PWM_TIM_INSTANCE_1                        (uint8)(1U)
#define PWM_TIM_INSTANCE_2                        (uint8)(2U)
#define PWM_TIM_INSTANCE_3                        (uint8)(3U)

/**
* @brief Symbolic Names for configured channels.
*/
#define PwmConf_PwmChannel_PTE8_PWM_OUT           ((Pwm_ChannelType)0U)
#define PwmConf_PwmChannel_HSD_EN2           ((Pwm_ChannelType)1U)
#define PwmConf_PwmChannel_HSD_EN1           ((Pwm_ChannelType)2U)
#define PwmConf_PwmChannel_DC_Ctr           ((Pwm_ChannelType)3U)

#if (PWM_PRECOMPILE_SUPPORT == STD_OFF)
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
/**
 * @brief Post Build configuration constants.
 */
#define PWM_CONFIG_EXT \
                PWM_CONFIG_PB

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif

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

#endif /* PWM_CFG_H */
