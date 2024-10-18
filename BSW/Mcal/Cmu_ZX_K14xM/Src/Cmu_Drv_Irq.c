/**************************************************************************************************/
/**
 * @file      : Cmu_Drv_Irq.c
 * @brief     : Cmu low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu_Drv
 *  @brief Cmu low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Cmu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CMU_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define CMU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define CMU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define CMU_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define CMU_DRV_IRQ_C_SW_MINOR_VERSION            1U
#define CMU_DRV_IRQ_C_SW_PATCH_VERSION            0U

/* Check if current file and Cmu_Drv.h file are of the same vendor */
#if (CMU_DRV_IRQ_C_VENDOR_ID != CMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Cmu_Drv_Irq.c and Cmu_Drv.h are different"
#endif
/* Check if current file and Cmu_Drv.h file are of the same Autosar version */
#if ((CMU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != CMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (CMU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != CMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (CMU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != CMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu_Drv_Irq.c and Cmu_Drv.h are different"
#endif
/* Check if current file and Cmu_Drv.h file are of the same Software version */
#if ((CMU_DRV_IRQ_C_SW_MAJOR_VERSION != CMU_DRV_H_SW_MAJOR_VERSION) ||                             \
     (CMU_DRV_IRQ_C_SW_MINOR_VERSION != CMU_DRV_H_SW_MINOR_VERSION) ||                             \
     (CMU_DRV_IRQ_C_SW_PATCH_VERSION != CMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Cmu_Drv_Irq.c and Cmu_Drv.h are different"
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

#define CMU_START_SEC_CODE
#include "Cmu_MemMap.h"

/**
 * @brief  This function will process CMU0 interrupt.

 *
 * @return  None
 */
ISR(Cmu_Drv_0_IrqHandler);

/**
 * @brief  This function will process CMU1 interrupt.

 *
 * @return  None
 */
ISR(Cmu_Drv_1_IrqHandler);

/**
 * @brief  This function will process CMU2 interrupt.

 *
 * @return  None
 */
ISR(Cmu_Drv_2_IrqHandler);

#define CMU_STOP_SEC_CODE
#include "Cmu_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define CMU_START_SEC_CODE
#include "Cmu_MemMap.h"

/**
 * @brief  CMU0 interrupt handler.

 *
 * @return  None
 */
ISR(Cmu_Drv_0_IrqHandler)
{
    Cmu_Drv_IrqHandler(CMU_DRV_ID_0);
    EXIT_INTERRUPT();
}

/**
 * @brief  CMU1 interrupt handler.

 *
 * @return  None
 */
ISR(Cmu_Drv_1_IrqHandler)
{
    Cmu_Drv_IrqHandler(CMU_DRV_ID_1);
    EXIT_INTERRUPT();
}

/**
 * @brief  CMU2 interrupt handler.

 *
 * @return  None
 */
ISR(Cmu_Drv_2_IrqHandler)
{
    Cmu_Drv_IrqHandler(CMU_DRV_ID_2);
    EXIT_INTERRUPT();
}

#define CMU_STOP_SEC_CODE
#include "Cmu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Cmu_Drv */

/** @} end of group Cmu_Module */
