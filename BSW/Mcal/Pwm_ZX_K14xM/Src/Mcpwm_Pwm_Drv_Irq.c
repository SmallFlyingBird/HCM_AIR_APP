/*************************************************************************************/
/**
 * @file      : Mcpwm_Pwm_Drv_Irq.c
 * @brief     : AUTOSAR Pwm low level interrupt handler source file
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

/** @addtogroup Pwm_Drv
 *  @brief Pwm low level driver interrupt handler
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcpwm_Pwm_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define MCPWM_PWM_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define MCPWM_PWM_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCPWM_PWM_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define MCPWM_PWM_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define MCPWM_PWM_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define MCPWM_PWM_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define MCPWM_PWM_DRV_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Mcpwm_Pwm_Drv.h are the same vendor */
#if (MCPWM_PWM_DRV_IRQ_C_VENDOR_ID != MCPWM_PWM_DRV_H_VENDOR_ID)
    #error "Vector Id of Mcpwm_Pwm_Drv_Irq.c and Mcpwm_Pwm_Drv.h are different"
#endif
/* Check if current file and Mcpwm_Pwm_Drv.h are the same AutoSar version*/
#if ((MCPWM_PWM_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != MCPWM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != MCPWM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mcpwm_Pwm_Drv_Irq.c and Mcpwm_Pwm_Drv.h are different"
#endif

/* Check if current file and Mcpwm_Pwm_Drv.h are the same Software version*/
#if ((MCPWM_PWM_DRV_IRQ_C_SW_MAJOR_VERSION != MCPWM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_IRQ_C_SW_MINOR_VERSION != MCPWM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_IRQ_C_SW_PATCH_VERSION != MCPWM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcpwm_Pwm_Drv_Irq.c and Mcpwm_Pwm_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef MCPWM_PWM_DRV_0_ENABLE
#if (MCPWM_PWM_DRV_0_OVF_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_0_OverflowIrqHandler);
#endif

#if (MCPWM_PWM_DRV_0_CH_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_0_ChIrqHandler);
#endif
#endif

#ifdef MCPWM_PWM_DRV_1_ENABLE
#if (MCPWM_PWM_DRV_1_OVF_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_1_OverflowIrqHandler);
#endif

#if (MCPWM_PWM_DRV_1_CH_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_1_ChIrqHandler);
#endif
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/** @} end of Public_FunctionDeclaration */


#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#ifdef MCPWM_PWM_DRV_0_ENABLE
#if (MCPWM_PWM_DRV_0_OVF_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_0_OverflowIrqHandler)
{
    Mcpwm_Pwm_Drv_ProcessTofInterrupt(0U);

    EXIT_INTERRUPT();
}
#endif

#if (MCPWM_PWM_DRV_0_CH_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_0_ChIrqHandler)
{
    Mcpwm_Pwm_Drv_ProcessCommonInterrupt(0U);

    EXIT_INTERRUPT();
}
#endif
#endif

#ifdef MCPWM_PWM_DRV_1_ENABLE
#if (MCPWM_PWM_DRV_1_OVF_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_1_OverflowIrqHandler)
{
    Mcpwm_Pwm_Drv_ProcessTofInterrupt(1U);

    EXIT_INTERRUPT();
}
#endif

#if (MCPWM_PWM_DRV_1_CH_ISR_ENABLE == STD_ON)
ISR(Mcpwm_Drv_1_ChIrqHandler)
{
    Mcpwm_Pwm_Drv_ProcessCommonInterrupt(1U);
 
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
