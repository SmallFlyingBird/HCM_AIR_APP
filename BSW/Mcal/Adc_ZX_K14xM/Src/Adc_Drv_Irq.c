/**************************************************************************************************/
/**
 * @file      : Adc_Drv_Irq.c
 * @brief     : Adc low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Drv
 *  @brief Adc low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "CpuLoad.h"
#include "Adc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ADC_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define ADC_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define ADC_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define ADC_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define ADC_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define ADC_DRV_IRQ_C_SW_PATCH_VERSION            2U

/* Check if current file and Adc_Drv.h are the same vendor */
#if (ADC_DRV_IRQ_C_VENDOR_ID != ADC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Adc_Drv_Irq.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same Autosar version */
#if ((ADC_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (ADC_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != ADC_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (ADC_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != ADC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Drv_Irq.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same Software version */
#if ((ADC_DRV_IRQ_C_SW_MAJOR_VERSION != ADC_DRV_H_SW_MAJOR_VERSION) ||                             \
     (ADC_DRV_IRQ_C_SW_MINOR_VERSION != ADC_DRV_H_SW_MINOR_VERSION) ||                             \
     (ADC_DRV_IRQ_C_SW_PATCH_VERSION != ADC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Drv_Irq.c and Adc_Drv.h are different"
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

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_DRV_0_ENABLE == STD_ON)
ISR(Adc_Drv_0_IrqHandler);
#endif /* (ADC_DRV_0_ENABLE == STD_ON) */

#if (ADC_DRV_1_ENABLE == STD_ON)
ISR(Adc_Drv_1_IrqHandler);
#endif /* (ADC_DRV_1_ENABLE == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_DRV_0_ENABLE == STD_ON)
ISR(Adc_Drv_0_IrqHandler)
{
	CpuLoad_EntryTime(CpuLoad_Index_Adc_Drv_0_Irq);

    Adc_Drv_IntHandler(0U);
    EXIT_INTERRUPT();
	
	CpuLoad_ExitTime(CpuLoad_Index_Adc_Drv_0_Irq);
}
#endif /* (ADC_DRV_0_ENABLE == STD_ON) */

#if (ADC_DRV_1_ENABLE == STD_ON)
ISR(Adc_Drv_1_IrqHandler)
{
	CpuLoad_EntryTime(CpuLoad_Index_Adc_Drv_1_Irq);

    Adc_Drv_IntHandler(1U);
    EXIT_INTERRUPT();
	
	CpuLoad_ExitTime(CpuLoad_Index_Adc_Drv_1_Irq);
}
#endif /* (ADC_DRV_1_ENABLE == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv */

/** @} end of group Adc_Module */
