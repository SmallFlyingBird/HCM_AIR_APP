/**************************************************************************************************/
/**
 * @file      : Icu_Drv_Irq.c
 * @brief     : AUTOSAR Cmp Icu hardware interrupt driver source file
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

#include "Cmp_Icu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CMP_ICU_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define CMP_ICU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define CMP_ICU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define CMP_ICU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define CMP_ICU_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define CMP_ICU_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define CMP_ICU_DRV_IRQ_C_SW_PATCH_VERSION            2U

#if (CMP_ICU_DRV_IRQ_C_VENDOR_ID != CMP_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Cmp_Icu_Drv_Irq.c and Cmp_Icu_Drv.h have different"
#endif
            
#if ((CMP_ICU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (CMP_ICU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Cmp_Icu_Drv_Irq.c and Cmp_Icu_Drv.h are different"
#endif

#if ((CMP_ICU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != CMP_ICU_DRV_H_AR_RELEASE_REVISION_VERSION) || \
        (CMP_ICU_DRV_IRQ_C_SW_PATCH_VERSION != CMP_ICU_DRV_H_SW_PATCH_VERSION))
    #error "AutoSar version of Cmp_Icu_Drv_Irq.c and Cmp_Icu_Drv.h are different"
#endif
            
#if ((CMP_ICU_DRV_IRQ_C_SW_MAJOR_VERSION != CMP_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (CMP_ICU_DRV_IRQ_C_SW_MINOR_VERSION != CMP_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Cmp_Icu_Drv_Irq.c and Cmp_Icu_Drv.h are different"
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

#ifdef CMP_ICU_DRV_0_ENABLE
    #if (CMP_ICU_DRV_0_ENABLE == STD_ON)
    ISR(Cmp_Drv_0_IrqHandler);
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

#ifdef CMP_ICU_DRV_0_ENABLE
    #if (CMP_ICU_DRV_0_ENABLE == STD_ON)
/**
 * @brief  Cmp instances 0 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(Cmp_Drv_0_IrqHandler)
{
    Cmp_Icu_Drv_ChIntHandler(CMP_ICU_DRV_ID_0);
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

