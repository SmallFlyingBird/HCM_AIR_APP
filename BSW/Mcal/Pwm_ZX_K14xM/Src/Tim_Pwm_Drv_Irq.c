/*************************************************************************************/
/**
 * @file      : Tim_Pwm_Drv_Irq.c
 * @brief     : AUTOSAR Pwm low level interrupt handler source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Drv
 *  @brief Pwm low level driver interrupt handler
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Tim_Pwm_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_PWM_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define TIM_PWM_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_PWM_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_PWM_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_PWM_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define TIM_PWM_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define TIM_PWM_DRV_IRQ_C_SW_PATCH_VERSION            2U

/* Check if current file and Tim_Pwm_Drv.h are the same vendor */
#if (TIM_PWM_DRV_IRQ_C_VENDOR_ID != TIM_PWM_DRV_H_VENDOR_ID)
    #error "Vector Id of Tim_Pwm_Drv_Irq.c and Tim_Pwm_Drv.h are different"
#endif
/* Check if current file and Tim_Pwm_Drv.h are the same AutoSar version*/
#if ((TIM_PWM_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != TIM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_PWM_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != TIM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_PWM_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Tim_Pwm_Drv_Irq.c and Tim_Pwm_Drv.h are different"
#endif

/* Check if current file and Tim_Pwm_Drv.h are the same Software version*/
#if ((TIM_PWM_DRV_IRQ_C_SW_MAJOR_VERSION != TIM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (TIM_PWM_DRV_IRQ_C_SW_MINOR_VERSION != TIM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (TIM_PWM_DRV_IRQ_C_SW_PATCH_VERSION != TIM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Pwm_Drv_Irq.c and Tim_Pwm_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef TIM_PWM_DRV_0_ENABLE
#if (TIM_PWM_DRV_0_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_0_OverflowIrqHandler);
#endif

#if (TIM_PWM_DRV_0_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_0_ChIrqHandler);
#endif
#endif

#ifdef TIM_PWM_DRV_1_ENABLE
#if (TIM_PWM_DRV_1_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_1_OverflowIrqHandler);
#endif

#if (TIM_PWM_DRV_1_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_1_ChIrqHandler);
#endif
#endif

#ifdef TIM_PWM_DRV_2_ENABLE
#if (TIM_PWM_DRV_2_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_2_OverflowIrqHandler);
#endif

#if (TIM_PWM_DRV_2_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_2_ChIrqHandler);
#endif
#endif

#ifdef TIM_PWM_DRV_3_ENABLE
#if (TIM_PWM_DRV_3_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_3_OverflowIrqHandler);
#endif

#if (TIM_PWM_DRV_3_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_3_ChIrqHandler);
#endif
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/** @} end of Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

#ifdef TIM_PWM_DRV_0_ENABLE
#if (TIM_PWM_DRV_0_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_0_OverflowIrqHandler)
{
    Tim_Pwm_Drv_ProcessTofInterrupt(0U);

    EXIT_INTERRUPT();
}
#endif

#if (TIM_PWM_DRV_0_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_0_ChIrqHandler)
{
    Tim_Pwm_Drv_ProcessCommonInterrupt(0U);

    EXIT_INTERRUPT();
}
#endif
#endif

#ifdef TIM_PWM_DRV_1_ENABLE
#if (TIM_PWM_DRV_1_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_1_OverflowIrqHandler)
{
    Tim_Pwm_Drv_ProcessTofInterrupt(1U);

    EXIT_INTERRUPT();
}
#endif

#if (TIM_PWM_DRV_1_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_1_ChIrqHandler)
{
    Tim_Pwm_Drv_ProcessCommonInterrupt(1U);

    EXIT_INTERRUPT();
}
#endif
#endif

#ifdef TIM_PWM_DRV_2_ENABLE
#if (TIM_PWM_DRV_2_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_2_OverflowIrqHandler)
{
    Tim_Pwm_Drv_ProcessTofInterrupt(2U);

    EXIT_INTERRUPT();
}
#endif

#if (TIM_PWM_DRV_2_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_2_ChIrqHandler)
{
    Tim_Pwm_Drv_ProcessCommonInterrupt(2U);

    EXIT_INTERRUPT();
}
#endif
#endif

#ifdef TIM_PWM_DRV_3_ENABLE
#if (TIM_PWM_DRV_3_OVF_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_3_OverflowIrqHandler)
{
    Tim_Pwm_Drv_ProcessTofInterrupt(3U);

    EXIT_INTERRUPT();
}
#endif

#if (TIM_PWM_DRV_3_CH_ISR_ENABLE == STD_ON)
ISR(Tim_Drv_3_ChIrqHandler)
{
    Tim_Pwm_Drv_ProcessCommonInterrupt(3U);

    EXIT_INTERRUPT();
}
#endif
#endif

/** @} end of group Public_FunctionDefinition */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Pwm_Drv */

/** @} end of group Pwm_Module */
