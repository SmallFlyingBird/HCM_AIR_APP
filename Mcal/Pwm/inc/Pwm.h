/**
 * @file    Pwm.h
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

#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C"
{
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Pwm_Cfg.h"
#include "Pwm_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID                      (180)
#define PWM_MODULE_ID           (121)
#define PWM_AR_RELEASE_MAJOR_VERSION       (4)
#define PWM_AR_RELEASE_MINOR_VERSION       (4)
#define PWM_AR_RELEASE_REVISION_VERSION    (0)
#define PWM_SW_MAJOR_VERSION               (2)
#define PWM_SW_MINOR_VERSION               (3)
#define PWM_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm.h and Pwm_Cfg.h are of the same vendor */
#if (PWM_VENDOR_ID != PWM_VENDOR_ID_CFG)
#error "Pwm.h and Pwm_Cfg.h have different vendor ids"
#endif

/* Check if Pwm.h and Pwm_Cfg.h are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (PWM_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif

/* Check if Pwm.h and Pwm_Cfg.h are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION_CFG) || \
     (PWM_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION_CFG) || \
     (PWM_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif

/* Check if Pwm.h and Pwm_Types.h are of the same vendor */
#if (PWM_VENDOR_ID != PWM_TYPES_VENDOR_ID)
#error "Pwm.h and Pwm_Types.h have different vendor ids"
#endif

/* Check if Pwm.h and Pwm_Types.h are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION != PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm.h and Pwm_Types.h are different"
#endif

/* Check if Pwm.h and Pwm_Types.h are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION != PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION != PWM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm.h and Pwm_Types.h are different"
#endif

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 * @brief       Service for PWM initialization.
 * @param[in]   ConfigPtr Pointer to configuration set
 * @return      void
 */
PWM_FUNC void Pwm_Init(const Pwm_ConfigType *ConfigPtr);

#if (PWM_DEINIT_API == STD_ON)
/**
 * @brief       Service for PWM De-Initialization.
 * @return      void
 */
PWM_FUNC void Pwm_DeInit(void);
#endif

#if (PWM_SET_DUTY_CYCLE == STD_ON)
/**
 * @brief       Service sets the duty cycle of the PWM channel.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @param[in]   DutyCycle 0x0000 for 0%, 0x8000 for 100%
 * @return      void
 */
PWM_FUNC void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
#endif

#if (PWM_SET_PERIOD_AND_DUTY == STD_ON)
/**
 * @brief       Service sets the period and the duty cycle of a PWM channel
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @param[in]   Period Period of the PWM signal
 * @param[in]   DutyCycle 0x0000 for 0%, 0x8000 for 100%
 * @return      void
 */
PWM_FUNC void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle);
#endif

#if (PWM_SET_OUTPUT_TO_IDLE == STD_ON)
/**
 * @brief       Service sets the PWM output to the configured Idle state.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @return      void
 */
PWM_FUNC void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_GET_OUTPUT_STATE == STD_ON)
/**
 * @brief       Service to read the internal state of the PWM output signal.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @return      Pwm_OutputStateType
 */
PWM_FUNC Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        This function is used to update the dead time at runtime for Pwm channels.
* @param[in]    ChannelNumber Pwm channel id
* @param[in]    DeadTimeTicks Dead Time value
* @return       void
*/
void Pwm_SetChannelDeadTime(Pwm_ChannelType ChannelNumber, uint16 DeadTimeTicks);
#endif

#if (PWM_VERSION_INFO_API == STD_ON)
/**
 * @brief       This function returns Pwm driver version details
 * @details     The function Pwm_GetVersionInfo shall return the version information of this module.
 *              The version information includes: Module Id, Vendor Id, Vendor specific version number.
 * @param[out]  VersionInfo Pointer to Std_VersionInfoType output variable
 * @return      void
 */
PWM_FUNC void Pwm_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
#if 0
/**
 * @brief       Service to disable the PWM signal edge notification.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @return      void
 */
PWM_FUNC void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);

/**
 * @brief       Service to enable the PWM signal edge notification according to notification parameter.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @param[in]   Notification Type of notification
 * @return      void
 */
PWM_FUNC void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);
#endif
#endif

#if (PWM_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief       This API is cyclically called and supervises the power state transitions.
 * @return      void
 */
PWM_FUNC void Pwm_Main_PowerTransitionManager(void);

/**
 * @brief       This API returns the current power state of the PWM HW unit.
 * @param[out]  CurrentPowerState The current power mode of the PWM HW Unit is returned in this parameter
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED:Current power mode was returned.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * @return  Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType *CurrentPowerState, Pwm_PowerStateRequestResultType *Result);

/**
 * @brief       This API returns the Target power state of the PWM HW unit.
 * @param[out]  TargetPowerState The Target power mode of the PWM HW Unit is returned in this parameter
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED:Target power mode was returned.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * @return      Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType *TargetPowerState, Pwm_PowerStateRequestResultType *Result);

/**
 * @brief       This API starts the needed process to allow the PWM HW module to enter the requested power state.
 * @param[in]   PowerState The target power state intended to be attained
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED: PWM Module power state preparation was started.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * PWM_SEQUENCE_ERROR: wrong API call sequence (Current Power State = Target Power State).
 * PWM_POWER_STATE_NOT_SUPP: PWM Module does not support the requested power state.
 * PWM_TRANS_NOT_POSSIBLE: PWM Module cannot transition directly from the current power state to
 * the requested power state or the HW peripheral is still busy.
 * @return      Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType PowerState, Pwm_PowerStateRequestResultType *Result);

/**
 * @brief       This API configures the Pwm module so that it enters the already prepared power state, chosen between a predefined set of configured ones.
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED:Power state change executed.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * PWM_SEQUENCE_ERROR: wrong API call sequence.
 * PWM_HW_FAILURE: the HW module has a failure which prevents it to enter the required power state.
 * @return      Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType *Result);
#endif /* PWM_LOW_POWER_STATES_SUPPORT == STD_ON */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PWM_H */

/** @} */

