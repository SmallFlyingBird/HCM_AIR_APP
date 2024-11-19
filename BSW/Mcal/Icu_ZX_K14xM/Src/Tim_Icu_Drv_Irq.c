/**************************************************************************************************/
/**
 * @file      : Tim_Icu_Drv_Irq.c
 * @brief     : AUTOSAR Tim Icu hardware interrupt driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Tim_Icu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_ICU_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define TIM_ICU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_ICU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_ICU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_ICU_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define TIM_ICU_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define TIM_ICU_DRV_IRQ_C_SW_PATCH_VERSION            2U

#if (TIM_ICU_DRV_IRQ_C_VENDOR_ID != TIM_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Tim_Icu_Drv_Irq.c and Tim_Icu_Drv.h have different"
#endif
            
#if ((TIM_ICU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (TIM_ICU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Tim_Icu_Drv_Irq.c and Tim_Icu_Drv.h are different"
#endif

#if ((TIM_ICU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != TIM_ICU_DRV_H_AR_RELEASE_REVISION_VERSION) || \
        (TIM_ICU_DRV_IRQ_C_SW_PATCH_VERSION != TIM_ICU_DRV_H_SW_PATCH_VERSION))
    #error "AutoSar version of Tim_Icu_Drv_Irq.c and Tim_Icu_Drv.h are different"
#endif

#if ((TIM_ICU_DRV_IRQ_C_SW_MAJOR_VERSION != TIM_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (TIM_ICU_DRV_IRQ_C_SW_MINOR_VERSION != TIM_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Tim_Icu_Drv_Irq.c and Tim_Icu_Drv.h are different"
#endif

/** @} end of group Private_MacroDefinition */

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

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#ifdef TIM_ICU_DRV_0_ENABLE
    #if (TIM_ICU_DRV_0_ENABLE == STD_ON)
    ISR(Tim_Drv_0_ChIrqHandler);
    ISR(Tim_Drv_0_OverflowIrqHandler);
    #endif
#endif

#ifdef TIM_ICU_DRV_1_ENABLE
    #if (TIM_ICU_DRV_1_ENABLE == STD_ON)
    ISR(Tim_Drv_1_ChIrqHandler);
    ISR(Tim_Drv_1_OverflowIrqHandler);
    #endif
#endif

#ifdef TIM_ICU_DRV_2_ENABLE
    #if (TIM_ICU_DRV_2_ENABLE == STD_ON)
    ISR(Tim_Drv_2_ChIrqHandler);
    ISR(Tim_Drv_2_OverflowIrqHandler);
    #endif
#endif

#ifdef TIM_ICU_DRV_3_ENABLE
    #if (TIM_ICU_DRV_3_ENABLE == STD_ON)
    ISR(Tim_Drv_3_ChIrqHandler);
    ISR(Tim_Drv_3_OverflowIrqHandler);
    #endif
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#ifdef TIM_ICU_DRV_0_ENABLE
    #if (TIM_ICU_DRV_0_ENABLE == STD_ON)
/**
 * @brief  Icu instances 0 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_0_ChIrqHandler)
{
    Tim_Icu_Drv_ChIntHandler(TIM_ICU_DRV_ID_0);
    EXIT_INTERRUPT();
}

/**
 * @brief  Icu instances 0 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_0_OverflowIrqHandler)
{
    Tim_Icu_Drv_OverflowIntHandler(TIM_ICU_DRV_ID_0);
    EXIT_INTERRUPT();
}
    #endif
#endif

#ifdef TIM_ICU_DRV_1_ENABLE
    #if (TIM_ICU_DRV_1_ENABLE == STD_ON)
/**
 * @brief  Icu instances 1 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_1_ChIrqHandler)
{
    Tim_Icu_Drv_ChIntHandler(TIM_ICU_DRV_ID_1);
    EXIT_INTERRUPT();
}

/**
 * @brief  Icu instances 1 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_1_OverflowIrqHandler)
{
    Tim_Icu_Drv_OverflowIntHandler(TIM_ICU_DRV_ID_1);
    EXIT_INTERRUPT();
}
    #endif
#endif

#ifdef TIM_ICU_DRV_2_ENABLE
    #if (TIM_ICU_DRV_2_ENABLE == STD_ON)
/**
 * @brief  Icu instances 2 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_2_ChIrqHandler)
{
    Tim_Icu_Drv_ChIntHandler(TIM_ICU_DRV_ID_2);
    EXIT_INTERRUPT();
}

/**
 * @brief  Icu instances 2 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_2_OverflowIrqHandler)
{
    Tim_Icu_Drv_OverflowIntHandler(TIM_ICU_DRV_ID_2);
    EXIT_INTERRUPT();
}
    #endif
#endif

#ifdef TIM_ICU_DRV_3_ENABLE
    #if (TIM_ICU_DRV_3_ENABLE == STD_ON)
/**
 * @brief  Icu instances 3 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_3_ChIrqHandler)
{
    Tim_Icu_Drv_ChIntHandler(TIM_ICU_DRV_ID_3);
    EXIT_INTERRUPT();
}

/**
 * @brief  Icu instances 3 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Tim_Drv_3_OverflowIrqHandler)
{
    Tim_Icu_Drv_OverflowIntHandler(TIM_ICU_DRV_ID_3);
    EXIT_INTERRUPT();
}
    #endif
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu_Drv */
/** @} end of group Icu_Module */

