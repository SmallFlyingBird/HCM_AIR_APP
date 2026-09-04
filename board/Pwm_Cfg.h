/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */


#ifndef PWM_CFG_H
#define PWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Compiler.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID_CFG                      (180)
#define PWM_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define PWM_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define PWM_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define PWM_SW_MAJOR_VERSION_CFG               (2)
#define PWM_SW_MINOR_VERSION_CFG               (3)
#define PWM_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS                                       
==================================================================================================*/

/*==================================================================================================
 *                                          PwmPrecompile                                          
==================================================================================================*/
/**
 * @brief   Pre-compile configuration constants.
 */
#define PWM_PRECOMPILE_SUPPORT          (STD_OFF)

/*==================================================================================================
 *                                           PwmGeneral                                           
==================================================================================================*/
/**
 * @brief   Switch to enable the development error detection.
 */
#define PWM_DEV_ERROR_DETECT            (STD_OFF)

/**
 * @brief  ECUC_Pwm_00132: Switch to enable the update of the duty cycle parameter at the end of the current period.
 *     STD_ON/TRUE: update of duty cycle is done at the end of period of currently generated waveform (current waveform is finished).
 *     STD_OFF/FALSE: update of duty cycle is done immediately (just after service call,current waveform is cut).
 */
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD (STD_ON)

/**
 * @brief  ECUC_Pwm_00133: Switch to enable the update of the period parameter at the end of the current period.
 *    STD_ON/TRUE: update of period/duty cycle is done at the end of period of currently generated waveform (current waveform is finished).
 *    STD_OFF/FALSE: update of period/duty cycle is done immediately (just after service call,current waveform is cut).
 */
#define PWM_PERIOD_UPDATED_ENDPERIOD    (STD_ON)

/**
 * @brief   Switch to enable the notification mechanism. 
 */
#define PWM_NOTIFICATION_SUPPORTED      (STD_OFF)


#ifdef PWM_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if PWM_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

/**
 * @brief   Compile switch to enable / disable the SchM code.
 */
#define PWM_SCHM_SUPPORT                (STD_ON)

/**
 * @brief   Switch to enable the low power functionality.
 */
#define PWM_LOW_POWER_STATES_SUPPORT    (STD_OFF)

/**
 * @brief   Specifies the InstanceId of this module instance. If only one instance is present it 
 *          shall have the Id 0.
 */
#define PWM_INDEX                       (0U)

/*==================================================================================================
 *                                   PwmConfigurationOfOptApiServices
==================================================================================================*/
/**
 * @brief   PWM_DEINIT_API switch
 * @details Adds / removes the service Pwm_DeInit() from the code.
 * @ref     ECUC_Pwm_00141 
 */
#define PWM_DEINIT_API                  (STD_ON)

/**
 * @brief   PWM_GET_OUTPUT_STATE switch
 * @details Adds / removes the service Pwm_GetOutputState() from the code.
 * @ref     ECUC_Pwm_00127 
 */
#define PWM_GET_OUTPUT_STATE            (STD_OFF)

/**
 * @brief   PWM_SET_DUTY_CYCLE switch
 * @details Adds / removes the service Pwm_SetDutyCycle() from the code.
 * @ref     ECUC_Pwm_00128 
 */
#define PWM_SET_DUTY_CYCLE              (STD_ON)

/**
 * @brief   PWM_SET_OUTPUT_TO_IDLE switch
 * @details Adds / removes the service Pwm_SetOutputToIdle() from the code.
 * @ref     ECUC_Pwm_00129 
 */
#define PWM_SET_OUTPUT_TO_IDLE          (STD_OFF)

/**
 * @brief   PWM_SET_PERIOD_AND_DUTY switch
 * @details Adds / removes the service Pwm_SetPeriodAndDuty() from the code.
 * @ref     ECUC_Pwm_00130 
 */
#define PWM_SET_PERIOD_AND_DUTY         (STD_ON)

/**
 * @brief   PWM_VERSION_INFO_API switch
 * @details Adds / removes the service Pwm_GetVersionInfo() from the code.
 * @ref     ECUC_Pwm_00135 
 */
#define PWM_VERSION_INFO_API            (STD_OFF)

/** 
 * @brief   Adds / removes the service Pwm_SetChannelDeadTime() from the code.
 */
#define PWM_SET_CHANNEL_DEAD_TIME_API   (STD_OFF)

/*==================================================================================================
 *                                       PwmChannel
==================================================================================================*/
/**
 * @brief   Symbolic names of configured Pwm Channels.
 */
#define PwmConf_PwmChannel_TRK_CC_BOOST    (0U)
#define PwmConf_PwmChannel_DC_Ctr    (1U)
#define PwmConf_PwmChannel_HL_Ctrl    (2U)
#define PwmConf_PwmChannel_Trigger_Ctrl2    (3U)
#define PwmConf_PwmChannel_TL_Ctrl    (4U)

/**
 * @brief   PWM_LOGIC_CHANNEL_NUM
 * @details The maximum number of logical channels.
 */
#define PWM_LOGIC_CHANNEL_NUM   (5U)

#ifdef __cplusplus
}
#endif

#endif /* PWM_CFG_H */

