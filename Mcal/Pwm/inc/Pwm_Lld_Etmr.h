/**
 * @file    Pwm_Lld_Etmr.h
 * @version V2.3.0
 *
 * @brief   YUNTU Pwm_Lld_Etmr module interface
 * @details API implementation for Pwm_Lld_Etmr driver
 *
 * @addtogroup PWM_LLD_ETMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR
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

#ifndef PWM_LLD_ETMR_H
#define PWM_LLD_ETMR_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Lld_Etmr_Types.h"
#include "Pwm_Lld_Etmr_Reg.h"
#include "Pwm_Lld_Etmr_Cfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_ETMR_VENDOR_ID                      (180)
#define PWM_LLD_ETMR_MODULE_ID              (121)
#define PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION       (4)
#define PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION       (4)
#define PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION    (0)
#define PWM_LLD_ETMR_SW_MAJOR_VERSION               (2)
#define PWM_LLD_ETMR_SW_MINOR_VERSION               (3)
#define PWM_LLD_ETMR_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Types.h are of the same vendor */
#if (PWM_LLD_ETMR_VENDOR_ID != PWM_LLD_ETMR_TYPES_VENDOR_ID)
#error "Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Types.h have different vendor ids"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Types.h are of the same Autosar version */
#if ((PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION != PWM_LLD_ETMR_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION != PWM_LLD_ETMR_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION != PWM_LLD_ETMR_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Types.h are different"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Types.h are of the same software version */
#if ((PWM_LLD_ETMR_SW_MAJOR_VERSION != PWM_LLD_ETMR_TYPES_SW_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_SW_MINOR_VERSION != PWM_LLD_ETMR_TYPES_SW_MINOR_VERSION) || \
     (PWM_LLD_ETMR_SW_PATCH_VERSION != PWM_LLD_ETMR_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Types.h are different"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Reg.h are of the same vendor */
#if (PWM_LLD_ETMR_VENDOR_ID != PWM_LLD_ETMR_REG_VENDOR_ID)
#error "Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Reg.h have different vendor ids"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Reg.h are of the same Autosar version */
#if ((PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION != PWM_LLD_ETMR_REG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION != PWM_LLD_ETMR_REG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION != PWM_LLD_ETMR_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Reg.h are different"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Reg.h are of the same software version */
#if ((PWM_LLD_ETMR_SW_MAJOR_VERSION != PWM_LLD_ETMR_REG_SW_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_SW_MINOR_VERSION != PWM_LLD_ETMR_REG_SW_MINOR_VERSION) || \
     (PWM_LLD_ETMR_SW_PATCH_VERSION != PWM_LLD_ETMR_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Reg.h are different"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Cfg.h are of the same vendor */
#if (PWM_LLD_ETMR_VENDOR_ID != PWM_LLD_ETMR_VENDOR_ID_CFG)
#error "Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Cfg.h have different vendor ids"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Cfg.h are of the same Autosar version */
#if ((PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION != PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION != PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION_CFG) || \
     (PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION != PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Cfg.h are different"
#endif

/* Check if Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Cfg.h are of the same software version */
#if ((PWM_LLD_ETMR_SW_MAJOR_VERSION != PWM_LLD_ETMR_SW_MAJOR_VERSION_CFG) || \
     (PWM_LLD_ETMR_SW_MINOR_VERSION != PWM_LLD_ETMR_SW_MINOR_VERSION_CFG) || \
     (PWM_LLD_ETMR_SW_PATCH_VERSION != PWM_LLD_ETMR_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Pwm_Lld_Etmr.h and Pwm_Lld_Etmr_Cfg.h are different"
#endif

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 * @brief       This function initializes the eTMR instance.
 * @param[in]   Instance The instance number.
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_InitInstance(uint8 Instance, const Pwm_Lld_Etmr_InstCfgType *InstCfg);

/**
 * @brief       This function initializes the eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_InitChannel(uint8 Instance, const Pwm_Lld_Etmr_ChCfgType *ChCfg);

/**
 * @brief       This function de-initializes the eTMR module.
 * @param[in]   Instance The instance number.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_DeInitInstance(uint8 Instance);

/**
 * @brief       This function de-initializes the eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_DeInitChannel(uint8 Instance, const Pwm_Lld_Etmr_ChCfgType *ChCfg);

/**
 * @brief       This function sets the duty cycle of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   DutyCycle The duty cycle value. The value should be in the range of [0, 0x8000].
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetDutyCycle(uint8 Instance, uint8 Channel, uint16 DutyCycle);

/**
 * @brief       This function sets the period and duty cycle of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   Period The period value.
 * @param[in]   DutyCycle The duty cycle value. The value should be in the range of [0, 0x8000].
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetPeriodAndDuty
(
    uint8 Instance,
    uint8 Channel,
    uint32 Period,
    uint16 DutyCycle
);

/**
 * @brief       This function sets the output to idle state.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   IdleState The idle state.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetOutputToIdle
(
    uint8 Instance,
    uint8 Channel,
    Pwm_Lld_Etmr_OutputStateType IdleState
);

/**
 * @brief       This function gets the output state of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @return      The output state.
 * @retval      PWM_LLD_ETMR_OUTPUT_STATE_LOW The output is low.
 * @retval      PWM_LLD_ETMR_OUTPUT_STATE_HIGH The output is high.
 */
PWM_FUNC Pwm_Lld_Etmr_OutputStateType Pwm_Lld_Etmr_GetOutputState(uint8 Instance, uint8 Channel);

/**
 * @brief       This function sets the dead time of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   DeadTimeTicks The dead time value.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetChannelDeadTime(uint8 Instance, uint8 Channel, uint16 DeadTimeTicks);

/**
 * @brief       eTMR overflow interrupt handler.
 * @details     This function handles the different eTMR instances overflow interrupt.
 * @param[in]   Instance eTMR hardware instance
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_Ovf_IrqHandler(uint8 Instance);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_ETMR_H */

/** @} */

