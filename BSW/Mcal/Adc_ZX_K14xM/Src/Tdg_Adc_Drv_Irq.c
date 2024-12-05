/**************************************************************************************************/
/**
 * @file      : Tdg_Adc_Drv_Irq.c
 * @brief     : Tdg Adc low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/**
 * @file  Tdg_Adc_Drv_Irq.c
 * @brief Tdg Adc low level driver interrupt source file.
 *
 */

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Tdg_Adc_Drv
 *  @brief Tdg Adc low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Tdg_Adc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TDG_ADC_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define TDG_ADC_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define TDG_ADC_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define TDG_ADC_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define TDG_ADC_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define TDG_ADC_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define TDG_ADC_DRV_IRQ_C_SW_PATCH_VERSION            2U

/* Check if current file and Tdg_Adc_Drv.h are the same vendor */
#if (TDG_ADC_DRV_IRQ_C_VENDOR_ID != TDG_ADC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Tdg_Adc_Drv_Irq.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Autosar version */
#if ((TDG_ADC_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (TDG_ADC_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION) ||     \
     (TDG_ADC_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tdg_Adc_Drv_Irq.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Software version */
#if ((TDG_ADC_DRV_IRQ_C_SW_MAJOR_VERSION != TDG_ADC_DRV_H_SW_MAJOR_VERSION) ||                     \
     (TDG_ADC_DRV_IRQ_C_SW_MINOR_VERSION != TDG_ADC_DRV_H_SW_MINOR_VERSION) ||                     \
     (TDG_ADC_DRV_IRQ_C_SW_PATCH_VERSION != TDG_ADC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Tdg_Adc_Drv_Irq.c and Tdg_Adc_Drv.h are different"
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

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (TDG_ADC_DRV_0_ENABLE == STD_ON)
ISR(Tdg_Drv_0_TcoIrqHandler);
ISR(Tdg_Drv_0_ErrIrqHandler);
#endif /* (TDG_ADC_DRV_0_ENABLE == STD_ON) */

#if (TDG_ADC_DRV_1_ENABLE == STD_ON)
ISR(Tdg_Drv_1_TcoIrqHandler);
ISR(Tdg_Drv_1_ErrIrqHandler);
#endif /* (TDG_ADC_DRV_1_ENABLE == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (TDG_ADC_DRV_0_ENABLE == STD_ON)
ISR(Tdg_Drv_0_TcoIrqHandler)
{
    Tdg_Adc_Drv_TcoIntHandler(0U);
}

ISR(Tdg_Drv_0_ErrIrqHandler)
{
    Tdg_Adc_Drv_ErrIntHandler(0U);
}
#endif /* (TDG_ADC_DRV_0_ENABLE == STD_ON) */

#if (TDG_ADC_DRV_1_ENABLE == STD_ON)
ISR(Tdg_Drv_1_TcoIrqHandler)
{
    Tdg_Adc_Drv_TcoIntHandler(1U);
}

ISR(Tdg_Drv_1_ErrIrqHandler)
{
    Tdg_Adc_Drv_ErrIntHandler(1U);
}
#endif /* (TDG_ADC_DRV_1_ENABLE == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv */

/** @} end of group Adc_Module */
