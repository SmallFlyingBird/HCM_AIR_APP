/**
 * @file    Pwm_Lld_Etmr.C
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

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                         INCLUDE FILES
=================================================================================================*/
#include "Pwm_Lld_Etmr.h"
#include "OsIf.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_ETMR_IRQ_VENDOR_ID_C                      (180)
#define PWM_LLD_ETMR_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PWM_LLD_ETMR_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define PWM_LLD_ETMR_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define PWM_LLD_ETMR_IRQ_SW_MAJOR_VERSION_C               (2)
#define PWM_LLD_ETMR_IRQ_SW_MINOR_VERSION_C               (3)
#define PWM_LLD_ETMR_IRQ_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Lld_Etmr_Irq.c and Pwm_Lld_Etmr.h are of the same vendor */
#if (PWM_LLD_ETMR_IRQ_VENDOR_ID_C != PWM_LLD_ETMR_VENDOR_ID)
#error "Pwm_Lld_Etmr_Irq.c and Pwm_Lld_Etmr.h have different vendor ids"
#endif

/* Check if Pwm_Lld_Etmr_Irq.c and Pwm_Lld_Etmr.h are of the same Autosar version */
#if ((PWM_LLD_ETMR_IRQ_AR_RELEASE_MAJOR_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_IRQ_AR_RELEASE_MINOR_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION) || \
     (PWM_LLD_ETMR_IRQ_AR_RELEASE_REVISION_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Lld_Etmr_Irq.c and Pwm_Lld_Etmr.h are different"
#endif

/* Check if Pwm_Lld_Etmr_Irq.c and Pwm_Lld_Etmr.h are of the same Software version */
#if ((PWM_LLD_ETMR_IRQ_SW_MAJOR_VERSION_C != PWM_LLD_ETMR_SW_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_IRQ_SW_MINOR_VERSION_C != PWM_LLD_ETMR_SW_MINOR_VERSION) || \
     (PWM_LLD_ETMR_IRQ_SW_PATCH_VERSION_C != PWM_LLD_ETMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Lld_Etmr_Irq.c and Pwm_Lld_Etmr.h are different"
#endif

/*==================================================================================================
 *                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if defined(PWM_LLD_ETMR_0_OVF_ISR_USED)
PWM_FUNC  ISR(eTMR0_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_ETMR_1_OVF_ISR_USED)
PWM_FUNC  ISR(eTMR1_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_ETMR_2_OVF_ISR_USED)
PWM_FUNC  ISR(eTMR2_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_ETMR_3_OVF_ISR_USED)
PWM_FUNC  ISR(eTMR3_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_ETMR_4_OVF_ISR_USED)
PWM_FUNC  ISR(eTMR4_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_ETMR_5_OVF_ISR_USED)
PWM_FUNC  ISR(eTMR5_Ovf_IRQHandler);
#endif

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if defined(PWM_LLD_ETMR_0_OVF_ISR_USED)
/**
 * @brief   eTMR_0 overflow interrupt handler.
 * @details This function handles the eTMR_0 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(eTMR0_Ovf_IRQHandler)
{
    Pwm_Lld_Etmr_Ovf_IrqHandler(0U);
}
#endif

#if defined(PWM_LLD_ETMR_1_OVF_ISR_USED)
/**
 * @brief   eTMR_1 overflow interrupt handler.
 * @details This function handles the eTMR_1 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(eTMR1_Ovf_IRQHandler)
{
    Pwm_Lld_Etmr_Ovf_IrqHandler(1U);
}
#endif

#if defined(PWM_LLD_ETMR_2_OVF_ISR_USED)
/**
 * @brief   eTMR_2 overflow interrupt handler.
 * @details This function handles the eTMR_2 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(eTMR2_Ovf_IRQHandler)
{
    Pwm_Lld_Etmr_Ovf_IrqHandler(2U);
}
#endif

#if defined(PWM_LLD_ETMR_3_OVF_ISR_USED)
/**
 * @brief   eTMR_3 overflow interrupt handler.
 * @details This function handles the eTMR_3 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(eTMR3_Ovf_IRQHandler)
{
    Pwm_Lld_Etmr_Ovf_IrqHandler(3U);
}
#endif

#if defined(PWM_LLD_ETMR_4_OVF_ISR_USED)
/**
 * @brief   eTMR_4 overflow interrupt handler.
 * @details This function handles the eTMR_4 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(eTMR4_Ovf_IRQHandler)
{
    Pwm_Lld_Etmr_Ovf_IrqHandler(4U);
}
#endif

#if defined(PWM_LLD_ETMR_5_OVF_ISR_USED)
/**
 * @brief   eTMR_5 overflow interrupt handler.
 * @details This function handles the eTMR_5 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(eTMR5_Ovf_IRQHandler)
{
    Pwm_Lld_Etmr_Ovf_IrqHandler(5U);
}
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

