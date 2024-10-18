/**************************************************************************************************/
/**
 * @file      : Seru_Drv_Irq.c
 * @brief     : Meh Extended MicroController Error Handle interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Meh_Module
 *  @{
 */

/** @addtogroup Meh_Seru
 *  @brief Meh Seru ISR handle
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Seru_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SERU_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define SERU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define SERU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define SERU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define SERU_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define SERU_DRV_IRQ_C_SW_MINOR_VERSION            1U
#define SERU_DRV_IRQ_C_SW_PATCH_VERSION            0U
/**
 *  @brief Check if current file and Seru_Drv.h are of the same vendor
 */
#if (SERU_DRV_IRQ_C_VENDOR_ID != SERU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv_Irq.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same Autosar version
 */
#if ((SERU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != SERU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (SERU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != SERU_DRV_H_AR_RELEASE_MINOR_VERSION) ||           \
     (SERU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != SERU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Seru_Drv_Irq.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same SW version
 */
#if ((SERU_DRV_IRQ_C_SW_MAJOR_VERSION != SERU_DRV_H_SW_MAJOR_VERSION) ||                           \
     (SERU_DRV_IRQ_C_SW_MINOR_VERSION != SERU_DRV_H_SW_MINOR_VERSION) ||                           \
     (SERU_DRV_IRQ_C_SW_PATCH_VERSION != SERU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Seru_Drv_Irq.c and Seru_Drv.h are different"
#endif
/** @} end of group Private_MacroDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU Parity Error interrupt handler.
 *
 * @return none
 */
ISR(Seru_Drv_ParityErrIrqHandler);
#endif

#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU channel Error interrupt handler.
 *
 * @return none
 */
ISR(Seru_Drv_ChErrIrqHandler);
#endif

#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"
#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU Parity Error interrupt handler.
 *
 * @return none
 */
ISR(Seru_Drv_ParityErrIrqHandler)
{
    Seru_Drv_ParityIrqHandler();
    EXIT_INTERRUPT();
}
#endif

#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU channel Error interrupt handler.
 *
 * @return none
 */
ISR(Seru_Drv_ChErrIrqHandler)
{
    Seru_Drv_IrqHandler();
    EXIT_INTERRUPT();
}
#endif

/** @} end of group Public_FunctionDefinition */

#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Seru_Drv */

/** @} end of group Seru_Module */
