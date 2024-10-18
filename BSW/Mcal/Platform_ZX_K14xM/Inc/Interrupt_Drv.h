/**************************************************************************************************/
/**
 * @file      : Interrupt_Drv.h
 * @brief     : Interrupt Control low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef INTERRUPT_DRV_H
#define INTERRUPT_DRV_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Interrupt_Drv
 *  @brief Interrupt Control low level driver header file.
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Interrupt_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define INTERRUPT_DRV_H_VENDOR_ID                   0x00B3U
#define INTERRUPT_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define INTERRUPT_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define INTERRUPT_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define INTERRUPT_DRV_H_SW_MAJOR_VERSION            1U
#define INTERRUPT_DRV_H_SW_MINOR_VERSION            2U
#define INTERRUPT_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Interrupt_Drv_Types.h are the same vendor */
#if (INTERRUPT_DRV_H_VENDOR_ID != INTERRUPT_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Interrupt_Drv.h and Interrupt_Drv_Types.h are different"
#endif
/* Check if current file and Interrupt_Drv_Types.h are the same Autosar version */
#if ((INTERRUPT_DRV_H_AR_RELEASE_MAJOR_VERSION !=                                                  \
      INTERRUPT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                                           \
     (INTERRUPT_DRV_H_AR_RELEASE_MINOR_VERSION !=                                                  \
      INTERRUPT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                                           \
     (INTERRUPT_DRV_H_AR_RELEASE_REVISION_VERSION !=                                               \
      INTERRUPT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Interrupt_Drv.h and Interrupt_Drv_Types.h are different"
#endif
/* Check if current file and Interrupt_Drv_Types.h are the same Software version */
#if ((INTERRUPT_DRV_H_SW_MAJOR_VERSION != INTERRUPT_DRV_TYPES_H_SW_MAJOR_VERSION) ||               \
     (INTERRUPT_DRV_H_SW_MINOR_VERSION != INTERRUPT_DRV_TYPES_H_SW_MINOR_VERSION) ||               \
     (INTERRUPT_DRV_H_SW_PATCH_VERSION != INTERRUPT_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Interrupt_Drv.h and Interrupt_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (STD_ON == INTERRUPT_DRV_ISR_ENABLE)
    #define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Platform_MemMap.h"

INTERRUPT_DRV_CONFIG_EXT

    #define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Platform_MemMap.h"
#endif /* (STD_ON == INTERRUPT_DRV_ISR_ENABLE) */
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief     This function initializes the configured interrupts.
 *
 * @param[in] ConfigPtr: pointer to configuration structure for interrupts.
 *
 * @return    None.
 */
void Interrupt_Drv_Init(const Interrupt_Drv_ConfigType *ConfigPtr);

/**
 * @brief      This function installs a handler for an IRQ.
 * @details    This function is non-reentrant; it installs an new ISR for an interrupt line.
 * This function works only when the interrupt vector table resides in RAM.
 *
 * @param[in]  IrqNumber: Interrupt Number.
 * @param[in]  NewHandler: Pointer to the new interrupt handler.
 * @param[out] OldHandlerPtr: Pointer to store the old interrupt handler. Pass NULL_PTR if not used.
 *
 * @return     None.
 */
void Interrupt_Drv_InstallHandler(IRQn_Type                           IrqNumber,
                                  const Interrupt_Drv_IrqHandlerType  NewHandler,
                                  Interrupt_Drv_IrqHandlerType *const OldHandlerPtr);

/**
 * @brief     This function enable an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    None.
 */
void Interrupt_Drv_EnableIrq(IRQn_Type IrqNumber);

/**
 * @brief     This function disables an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    None.
 */
void Interrupt_Drv_DisableIrq(IRQn_Type IrqNumber);

/**
 * @brief     This function sets the priority for an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 * @param[in] Priority: Priority to be set.
 *
 * @return    None.
 */
void Interrupt_Drv_SetPriority(IRQn_Type IrqNumber, uint32 Priority);

/**
 * @brief     This function gets the priority for an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    uint32: the priority of the interrupt.
 */
uint32 Interrupt_Drv_GetPriority(IRQn_Type IrqNumber);

/**
 * @brief     This function clears the pending flag for an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    None.
 */
void Interrupt_Drv_ClearPending(IRQn_Type IrqNumber);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Interrupt_Drv */

/** @} end of group Platform_Module */

#endif /* INTERRUPT_DRV_H */
