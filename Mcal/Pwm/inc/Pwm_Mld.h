/**
 * @file    Pwm_Mld.h
 * @version V2.3.0
 *
 * @brief   YUNTU Pwm_Mld module interface
 * @details API implementation for Pwm_Mld driver
 *
 * @addtogroup PWM_MLD_MODULE
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

#ifndef PWM_MLD_H
#define PWM_MLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Mld_Types.h"
#include "Pwm_Types.h"
#include "Pwm_Cfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_MLD_VENDOR_ID                      (180)
#define PWM_MLD_MODULE_ID           (121)
#define PWM_MLD_AR_RELEASE_MAJOR_VERSION       (4)
#define PWM_MLD_AR_RELEASE_MINOR_VERSION       (4)
#define PWM_MLD_AR_RELEASE_REVISION_VERSION    (0)
#define PWM_MLD_SW_MAJOR_VERSION               (2)
#define PWM_MLD_SW_MINOR_VERSION               (3)
#define PWM_MLD_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Mld.h and Pwm_Mld_Types.h are of the same vendor */
#if (PWM_MLD_VENDOR_ID != PWM_MLD_TYPES_VENDOR_ID)
#error "Pwm_Mld.h and Pwm_Mld_Types.h have different vendor ids"
#endif

/* Check if Pwm_Mld.h and Pwm_Mld_Types.h are of the same Autosar version */
#if ((PWM_MLD_AR_RELEASE_MAJOR_VERSION != PWM_MLD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_MINOR_VERSION != PWM_MLD_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_REVISION_VERSION != PWM_MLD_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Mld.h and Pwm_Mld_Types.h are different"
#endif

/* Check if Pwm_Mld.h and Pwm_Mld_Types.h are of the same software version */
#if ((PWM_MLD_SW_MAJOR_VERSION != PWM_MLD_TYPES_SW_MAJOR_VERSION) || \
     (PWM_MLD_SW_MINOR_VERSION != PWM_MLD_TYPES_SW_MINOR_VERSION) || \
     (PWM_MLD_SW_PATCH_VERSION != PWM_MLD_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Mld.h and Pwm_Mld_Types.h are different"
#endif

/* Check if Pwm_Mld.h and Pwm_Cfg.h are of the same vendor */
#if (PWM_MLD_VENDOR_ID != PWM_VENDOR_ID_CFG)
#error "Pwm_Mld.h and Pwm_Cfg.h have different vendor ids"
#endif

/* Check if Pwm_Mld.h and Pwm_Cfg.h are of the same Autosar version */
#if ((PWM_MLD_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (PWM_MLD_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (PWM_MLD_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Pwm_Mld.h and Pwm_Cfg.h are different"
#endif

/* Check if Pwm_Mld.h and Pwm_Cfg.h are of the same software version */
#if ((PWM_MLD_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION_CFG) || \
     (PWM_MLD_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION_CFG) || \
     (PWM_MLD_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Pwm_Mld.h and Pwm_Cfg.h are different"
#endif

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 * @brief       This function initializes the PWM MLD instance.
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_InitInstance(const Pwm_Mld_InstCfgType *const InstCfg);

/**
 * @brief       This function initializes the PWM MLD channel.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_InitChannel(const Pwm_Mld_ChCfgType *const ChCfg);

#if (PWM_DEINIT_API == STD_ON)
/**
 * @brief       This function de-initializes the PWM MLD instance.
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_DeInitInstance(const Pwm_Mld_InstCfgType *const InstCfg);

/**
 * @brief       This function de-initializes the specified PWM MLD channel.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_DeInitChannel(const Pwm_Mld_ChCfgType *const ChCfg);
#endif

#if (PWM_SET_DUTY_CYCLE == STD_ON)
/**
 * @brief       This function sets the duty cycle of the specified PWM MLD channel.
 * @param[in]   DutyCycle The duty cycle value.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_SetDutyCycle(uint16 DutyCycle, const Pwm_Mld_ChCfgType *const ChCfg);
#endif

#if (PWM_SET_PERIOD_AND_DUTY == STD_ON)
/**
 * @brief       This function sets the period and duty cycle of the specified PWM MLD channel.
 * @param[in]   Period The period value.
 * @param[in]   DutyCycle The duty cycle value.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_SetPeriodAndDuty
(
    Pwm_PeriodType Period,
    uint16 DutyCycle,
    const Pwm_Mld_ChCfgType *const ChCfg
);
#endif

#if (PWM_SET_OUTPUT_TO_IDLE == STD_ON)
/**
 * @brief       This function sets the output to idle state.
 * @param[in]   IdleState The output state.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_SetOutputToIdle
(
    Pwm_OutputStateType IdleState,
    const Pwm_Mld_ChCfgType *const ChCfg
);
#endif

#if (PWM_GET_OUTPUT_STATE == STD_ON)
/**
 * @brief       This function gets the output state of the specified PWM MLD channel.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      The output state.
 * @retval      PWM_LOW The output is low.
 * @retval      PWM_HIGH The output is high.
 */
PWM_FUNC Pwm_OutputStateType Pwm_Mld_GetOutputState(const Pwm_Mld_ChCfgType *const ChCfg);
#endif

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
 * @brief       This function is used to update the dead time at runtime for Pwm channels.
 * @param[in]   DeadTimeTicks dead time value
 * @param[in]   ChCfg Pointer to PWM top configuration structure
 * @return      void
 */
void Pwm_Mld_SetChannelDeadTime(uint16 DeadTimeTicks, const Pwm_Mld_ChCfgType *const ChCfg);
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
#if (PWM_SET_OUTPUT_TO_IDLE == STD_ON)
/**
 * @brief       This function will check the validation when calling the Pwm_SetOutputToIdle api.
 * @param[in]   ChCfg Pointer to PWM top configuration structure
 * @return      Std_ReturnType
 * @retval      E_NOT_OK Set output to idle is not valid
 * @retval      E_OK Set output to idle is valid
 */
PWM_FUNC Std_ReturnType Pwm_Mld_ValidateSetOutPutToIdle(const Pwm_Mld_ChCfgType *const ChCfg);
#endif

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
 * @brief       This function will check validate operation mode of current channel to use
 *              dead time feature.
 * @param[in]   ChCfg Pointer to PWM top configuration structure
 * @return      Std_ReturnType
 * @retval      E_NOT_OK Current channel mode is invalid
 * @retval      E_OK Current channel mode is valid
 */
PWM_FUNC Std_ReturnType Pwm_Mld_ValidateDeadTime(const Pwm_Mld_ChCfgType *const ChCfg);
#endif
#endif  /* PWM_DEV_ERROR_DETECT == STD_ON */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PWM_MLD_H */

/** @} */

