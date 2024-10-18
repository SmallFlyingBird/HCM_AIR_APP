/**************************************************************************************************/
/**
 * @file      : Platform.h
 * @brief     : Platform high level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PLATFORM_H
#define PLATFORM_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Platform
 *  @brief Platform high level header file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_TypesDef.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PLATFORM_MODULE_ID                   255U
#define PLATFORM_VENDOR_ID                   0x00B3U
#define PLATFORM_AR_RELEASE_MAJOR_VERSION    4U
#define PLATFORM_AR_RELEASE_MINOR_VERSION    6U
#define PLATFORM_AR_RELEASE_REVISION_VERSION 0U
#define PLATFORM_SW_MAJOR_VERSION            1U
#define PLATFORM_SW_MINOR_VERSION            2U
#define PLATFORM_SW_PATCH_VERSION            1U

/* Check if current file and Platform_TypesDef.h are the same vendor */
#if (PLATFORM_VENDOR_ID != PLATFORM_TYPESDEF_H_VENDOR_ID)
    #error "Vendor ID of Platform.h and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_TypesDef.h are the same Autosar version */
#if ((PLATFORM_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPESDEF_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (PLATFORM_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPESDEF_H_AR_RELEASE_MINOR_VERSION) ||        \
     (PLATFORM_AR_RELEASE_REVISION_VERSION != PLATFORM_TYPESDEF_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Platform.h and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_TypesDef.h are the same Software version */
#if ((PLATFORM_SW_MAJOR_VERSION != PLATFORM_TYPESDEF_H_SW_MAJOR_VERSION) ||                        \
     (PLATFORM_SW_MINOR_VERSION != PLATFORM_TYPESDEF_H_SW_MINOR_VERSION) ||                        \
     (PLATFORM_SW_PATCH_VERSION != PLATFORM_TYPESDEF_H_SW_PATCH_VERSION))
    #error "Software Version of Platform.h and Platform_TypesDef.h are different"
#endif

#ifndef MCAL_SUPPORT_USER_MODE
    #if (STD_OFF != PLATFORM_SUPPORT_USER_MODE)
        #error PLATFORM_SUPPORT_USER_MODE == STD_ON when MCAL_SUPPORT_USER_MODE is not defined.    \
        For running McalLib in user mode, MCAL_SUPPORT_USER_MODE needs to be defined.
    #endif /* (STD_OFF != PLATFORM_SUPPORT_USER_MODE */
#endif     /* ifndef MCAL_SUPPORT_USER_MODE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

PLATFORM_CONFIG_EXT

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief         This function initializes the interrupts based on configuration.
 *
 * @param[in]     ConfigPtr: Pointer to platform configuration.
 *
 * @return        None
 *
 */
void Platform_Init(const Platform_ConfigType *ConfigPtr);

/**
 * @brief         This function enables/disables an interrupt request.
 *
 * @param[in]     IrqNumber: Interrupt Number.
 * @param[in]     Enable: TRUE - enable interrupt, FALSE - disable interrupt.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_SetIrq(IRQn_Type IrqNumber, boolean Enable);

/**
 * @brief         This function sets the priority of an interrupt request.
 *
 * @param[in]     IrqNumber: Interrupt Number.
 * @param[in]     Priority: Priority to be set.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_SetIrqPriority(IRQn_Type IrqNumber, uint32 Priority);

/**
 * @brief         This function gets the priority of an interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which priority is returned.
 * @param[out]    PriorityPtr: output parameter storing the priority of the interrupt.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_GetIrqPriority(IRQn_Type IrqNumber, uint32 *PriorityPtr);

/**
 * @brief         This function installs a new handler for an interrupt request.
 *
 * @param[in]     IrqNumber: Interrupt Number.
 * @param[in]     NewHandler: Pointer for the new handler.
 * @param[out]    OldHandlerPtr: Pointer to store the old handler. Pass NULL_PTR if not used.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_InstallIrqHandler(IRQn_Type                      IrqNumber,
                                          const Platform_IrqHandlerType  NewHandler,
                                          Platform_IrqHandlerType *const OldHandlerPtr);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Platform */

/** @} end of group Platform_Module */

#endif /* PLATFORM_H */
