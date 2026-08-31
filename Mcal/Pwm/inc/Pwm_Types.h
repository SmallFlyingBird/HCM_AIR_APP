/**
 * @file    Pwm_Types.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Pwm module interface
 * @details API implementation for Pwm driver
 *
 * @addtogroup PWM_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR, MPWM
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifndef PWM_TYPES_H
#define PWM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Pwm_Mld_Types.h"
#include "Pwm_Cfg.h"

/*==================================================================================================
 *                                   FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_TYPES_VENDOR_ID                      (180)
#define PWM_TYPES_MODULE_ID             (121)
#define PWM_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define PWM_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define PWM_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define PWM_TYPES_SW_MAJOR_VERSION               (2)
#define PWM_TYPES_SW_MINOR_VERSION               (3)
#define PWM_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Types.h and Pwm_Mld_Types.h are of the same vendor */
#if (PWM_TYPES_VENDOR_ID != PWM_MLD_TYPES_VENDOR_ID)
#error "Pwm_Types.h and Pwm_Mld_Types.h have different vendor ids"
#endif

/* Check if Pwm_Types.h and Pwm_Mld_Types.h are of the same Autosar version */
#if ((PWM_TYPES_AR_RELEASE_MAJOR_VERSION != PWM_MLD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_TYPES_AR_RELEASE_MINOR_VERSION != PWM_MLD_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_TYPES_AR_RELEASE_REVISION_VERSION != PWM_MLD_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Types.h and Pwm_Mld_Types.h are different"
#endif

/* Check if Pwm_Types.h and Pwm_Mld_Types.h are of the same software version */
#if ((PWM_TYPES_SW_MAJOR_VERSION != PWM_MLD_TYPES_SW_MAJOR_VERSION) || \
     (PWM_TYPES_SW_MINOR_VERSION != PWM_MLD_TYPES_SW_MINOR_VERSION) || \
     (PWM_TYPES_SW_PATCH_VERSION != PWM_MLD_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Types.h and Pwm_Mld_Types.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief   Service ID number for all PWM driver services
 */
/** @brief API Service ID for Pwm_DeInit */
#define PWM_SID_DEINIT                          (0x01U)
/** @brief API Service ID for Pwm_DisableNotification */
#define PWM_SID_DISABLE_NOTIFICATION            (0x06U)
/** @brief API Service ID for Pwm_EnableNotification */
#define PWM_SID_ENABLE_NOTIFICATION             (0x07U)
/** @brief API Service ID for Pwm_GetCurrentPowerState */
#define PWM_SID_GET_CURRENT_POWER_STATE         (0x0AU)
/** @brief API Service ID for Pwm_GetOutputState */
#define PWM_SID_GET_OUTPUT_STATE                (0x05U)
/** @brief API Service ID for Pwm_GetTargetPowerState */
#define PWM_SID_GET_TARGET_POWER_STATE          (0x0BU)
/** @brief API Service ID for Pwm_GetVersionInfo */
#define PWM_SID_GET_VERSION_INFO                (0x08U)
/** @brief API Service ID for Pwm_Init */
#define PWM_SID_INIT                            (0x00U)
/** @brief API Service ID for Pwm_Main_PowerTransitionManager */
#define PWM_SID_MAIN_POWER_TRANSITION_MANAGER   (0x0DU)
/** @brief API Service ID for Pwm_PreparePowerState */
#define PWM_SID_PREPARE_POWER_STATE             (0x0CU)
/** @brief API Service ID for Pwm_SetDutyCycle */
#define PWM_SID_SET_DUTY_CYCLE                  (0x02U)
/** @brief API Service ID for Pwm_SetOutputToIdle */
#define PWM_SID_SET_OUTPUT_TO_IDLE              (0x04U)
/** @brief API Service ID for Pwm_SetPeriodAndDuty */
#define PWM_SID_SET_PERIOD_AND_DUTY             (0x03U)
/** @brief API Service ID for Pwm_SetPowerState */
#define PWM_SID_SET_POWER_STATE                 (0x09U)
/** @brief API Service ID for Pwm_SetChannelDeadTime */
#define PWM_SID_SET_CHANNEL_DEAD_TIME_ID        (0x2BU)

/**
 * @brief   PWM development errors
 * @ref     SWS_Pwm_00201
 */
/** @brief API Pwm_Init service called with wrong parameter. */
#define PWM_E_INIT_FAILED                       (0x10U)
/** @brief API service used without module initialization. */
#define PWM_E_UNINIT                            (0x11U)
/** @brief API service used with an invalid channel Identifier. */
#define PWM_E_PARAM_CHANNEL                     (0x12U)
/** @brief Usage of unauthorized PWM service on PWM channel configured a fixed period. */
#define PWM_E_PERIOD_UNCHANGEABLE               (0x13U)
/** @brief API Pwm_Init service called while the PWM driver has already been initialised. */
#define PWM_E_ALREADY_INITIALIZED               (0x14U)
/** @brief PWM API service is called using an invalid pointer (e.g. the pointer should not be NULL).  */
#define PWM_E_PARAM_POINTER                     (0x15U)
/** @brief API Pwm_SetPowerState is called while the PWM module is still in use.  */
#define PWM_E_NOT_DISENGAGED                    (0x16U)
/** @brief The requested power state is not supported by the PWM module.  */
#define PWM_E_POWER_STATE_NOT_SUPPORTED         (0x17U)
/** @brief The requested power state is not reachable from the current one.  */
#define PWM_E_TRANSITION_NOT_POSSIBLE           (0x18U)
/** @brief API Pwm_SetPowerState has been called without having called the API Pwm_PreparePowerState before.  */
#define PWM_E_PERIPHERAL_NOT_PREPARED           (0x19U)
/** @brief Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty called with invalid duty cycle range.  */
#define PWM_E_DUTYCYCLE_RANGE                   (0x32U)
/** @brief Pwm_SetOutputToIdle is not supported with the PWM IP. */
#define PWM_E_SETOUTPUTTOIDLE_NOT_SUPPORTED     (0x42U)

/**
 * @brief   100% duty cycle
 * @details Errors and exceptions that will be detected by the PWM driver generated when
 *          Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty are called with a value for duty cycle
 *          out of valid range [0x0000, 0x8000]
 */
#define PWM_DUTY_CYCLE_100  (0x8000U)

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
 * @brief   This enumerated type will contain the Pwm driver's possible states
 */
typedef enum
{
    PWM_UNINIT = 0x00U, /**< Pwm driver is not initialized */
    PWM_IDLE   = 0x01U  /**< Pwm driver is idle */
} Pwm_StatusType;

/**
 * @brief   This enumerated type will contain the Pwm channel class
 */
typedef enum
{
    PWM_VARIABLE_PERIOD      = 0x00U, /**< The PWM channel has a variable period. The duty cycle and the period can be changed */
    PWM_FIXED_PERIOD         = 0x01U, /**< The PWM channel has a fixed period. Only the duty cycle can be changed */
    PWM_FIXED_PERIOD_SHIFTED = 0x02U  /**< The PWM channel has a fixed shifted period */
} Pwm_ChannelClassType;

/**
 * @brief Definition of the type of edge notification of a PWM channel.
 */
typedef enum
{
    PWM_RISING_EDGE  = 0x00U, /**< Rising edge */
    PWM_FALLING_EDGE = 0x01U, /**< Falling edge */
    PWM_BOTH_EDGES   = 0x02U  /**< Both edges */
} Pwm_EdgeNotificationType;

/**
 * @brief Output state of a PWM channel
 */
typedef enum
{
    PWM_LOW  = 0x00U, /**< The PWM channel is in low state */
    PWM_HIGH = 0x01U  /**< The PWM channel is in high state */
} Pwm_OutputStateType;

#if (PWM_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief  This enumerated type will contain the Pwm driver's possible power states
 */
typedef enum
{
    PWM_FULL_POWER = 0x00U, /**< PWM full power state */
    PWM_LOW_POWER  = 0x01U  /**< PWM low power state */
} Pwm_PowerStateType;

/**
 * @brief   Result of the requests related to power state transitions.
 */
typedef enum
{
    PWM_SERVICE_ACCEPTED        = 0x00U, /**< Power state change executed. */
    PWM_NOT_INIT                = 0x01U, /**< Module not initialized. */
    PWM_SEQUENCE_ERROR          = 0x02U, /**< Wrong API call sequence. */
    PWM_HW_FAILURE              = 0x03U, /**< The HW module has a failure which prevents it to enter the required power state. */
    PWM_POWER_STATE_NOT_SUPP    = 0x04U, /**< Module does not support the requested power state. */
    PWM_TRANS_NOT_POSSIBLE      = 0x05U  /**< Module cannot transition directly from the current power state to the requested power state */
} Pwm_PowerStateRequestResultType;
#endif /* PWM_LOW_POWER_STATES_SUPPORT == STD_ON */

/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/
/**
 * @brief Definition of the period of a PWM channel.
 */
typedef uint32 Pwm_PeriodType;

/**
 * @brief Definition of the instance.
 */
typedef uint8 Pwm_InstanceType;

/**
 * @brief Numeric identifier of a PWM channel.
 */
typedef uint8 Pwm_ChannelType;

/**
 * @brief Pwm notification type.
 */
typedef void (*Pwm_NotificationType)(void);

/**
 * @brief Definition of the channel configuration structure for the PWM driver.
 */
typedef struct
{
    Pwm_ChannelType ChannelId;                      /**<  Id for the logical channel */
    Pwm_ChannelClassType ChannelClass;              /**<  Channel class type: Variable/Fixed period */
    Pwm_Mld_ChCfgType MldChCfg;                     /**<  The type of ip channel configured */
    Pwm_OutputStateType ChannelIdleState;           /**<  The state of the channel output in idle mode */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    const Pwm_NotificationType ChannelNotification; /**<  Pointer to notification function */
#endif
} Pwm_ChannelConfigType;

/**
 * @brief Definition of the configuration structure for the PWM driver.
 */
typedef struct
{
    Pwm_ChannelType ChannelCount;                       /**< Number of channels */
    const Pwm_ChannelConfigType(*PwmChannelsConfig)[];  /**< Channels configuration */
    Pwm_InstanceType InstanceCount;                     /**< Number of instances */
    const Pwm_Mld_InstCfgType(*PwmInstancesConfig)[];   /**< Instances configuration */
} Pwm_ConfigType;

/**
 * @brief   State structure for the PWM driver
 */
typedef struct
{
    Pwm_StatusType State;                                                   /**< Variable storing the current state of the Pwm driver */
    const Pwm_ConfigType *PwmConfig;                                        /**< Pointer to the top level configuration structure */
    const Pwm_ChannelConfigType *PwmChannelConfigs[PWM_LOGIC_CHANNEL_NUM];  /**< Array holding all channel configurations */
} Pwm_DriverStateType;

#ifdef __cplusplus
}
#endif

#endif /* PWM_TYPES_H */

/** @} */

