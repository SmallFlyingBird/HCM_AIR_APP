/***************************************************************************************************/
/**
 * @file      : Scc_Drv_Irq.c
 * @brief     : SCC Interrupt Source file
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

/** @addtogroup Scc_Drv
 *  @brief Mcu low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Scc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCC_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define SCC_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCC_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define SCC_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define SCC_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define SCC_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define SCC_DRV_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Scc_Drv.h are the same vendor */
#if (SCC_DRV_IRQ_C_VENDOR_ID != SCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Scc_Drv_Irq.c and Scc_Drv.h are different"
#endif
/* Check if current file and Scc_Drv.h are of the same Autosar version */
#if ((SCC_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != SCC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (SCC_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != SCC_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (SCC_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != SCC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Scc_Drv_Irq.c and Scc_Drv.h are different"
#endif

/* Check if current file and Scc_Drv.h are of the same Software version */
#if ((SCC_DRV_IRQ_C_SW_MAJOR_VERSION != SCC_DRV_H_SW_MAJOR_VERSION) ||                             \
     (SCC_DRV_IRQ_C_SW_MINOR_VERSION != SCC_DRV_H_SW_MINOR_VERSION) ||                             \
     (SCC_DRV_IRQ_C_SW_PATCH_VERSION != SCC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Scc_Drv_Irq.c and Scc_Drv.h are different"
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

ISR(Scc_Drv_IrqHandler);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

ISR(Scc_Drv_IrqHandler)
{
    Scc_Drv_IntHandler();
    EXIT_INTERRUPT();
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Scc_Drv */

/** @} end of group Mcu_Module */
