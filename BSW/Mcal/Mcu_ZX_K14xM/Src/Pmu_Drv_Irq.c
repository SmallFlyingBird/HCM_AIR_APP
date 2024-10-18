/***************************************************************************************************/
/**
 * @file      : Pmu_Drv_Irq.c
 * @brief     : PMU Interrupt Source file
 *                - Platform: Z20K14xM
 *                - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Mcu_Module
 *  @{
 */

/** @addtogroup Pmu_Drv
 *  @brief Mcu low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pmu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define PMU_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define PMU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define PMU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define PMU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define PMU_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define PMU_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define PMU_DRV_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Pmu_Drv.h are the same vendor */
#if (PMU_DRV_IRQ_C_VENDOR_ID != PMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Pmu_Drv_Irq.c and Pmu_Drv.h are different"
#endif
/* Check if current file and Pmu_Drv.h are of the same Autosar version */
#if ((PMU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != PMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (PMU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != PMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (PMU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != PMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Pmu_Drv_Irq.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h are of the same Software version */
#if ((PMU_DRV_IRQ_C_SW_MAJOR_VERSION != PMU_DRV_H_SW_MAJOR_VERSION) ||                             \
     (PMU_DRV_IRQ_C_SW_MINOR_VERSION != PMU_DRV_H_SW_MINOR_VERSION) ||                             \
     (PMU_DRV_IRQ_C_SW_PATCH_VERSION != PMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Pmu_Drv_Irq.c and Pmu_Drv.h are different"
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
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

ISR(Pmu_Drv_IrqHandler);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

ISR(Pmu_Drv_IrqHandler)
{
    Pmu_Drv_IntHandler();
    EXIT_INTERRUPT();
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Pmu_Drv */

/** @} end of group Mcu_Module */
