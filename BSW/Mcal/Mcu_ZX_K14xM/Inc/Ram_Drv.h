/**************************************************************************************************/
/**
 * @file      : Ram_Drv.h
 * @brief     : RAM low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef RAM_DRV_H
#define RAM_DRV_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Ram_Drv
 *  @brief RAM low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Ram_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define RAM_DRV_H_VENDOR_ID                   0x00B3U
#define RAM_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define RAM_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define RAM_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define RAM_DRV_H_SW_MAJOR_VERSION            1U
#define RAM_DRV_H_SW_MINOR_VERSION            2U
#define RAM_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Ram_Drv_Types.h file are of the same vendor */
#if (RAM_DRV_H_VENDOR_ID != RAM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Ram_Drv.h and Ram_Drv_Types.h are different"
#endif

/* Check if current file and Ram_Drv_Types.h file are of the same Autosar version */
#if ((RAM_DRV_H_AR_RELEASE_MAJOR_VERSION != RAM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (RAM_DRV_H_AR_RELEASE_MINOR_VERSION != RAM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (RAM_DRV_H_AR_RELEASE_REVISION_VERSION != RAM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ram_Drv.h and Ram_Drv_Types.h are different"
#endif

/* Check if current file and Ram_Drv_Types.h file are of the same software version */
#if ((RAM_DRV_H_SW_MAJOR_VERSION != RAM_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (RAM_DRV_H_SW_MINOR_VERSION != RAM_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (RAM_DRV_H_SW_PATCH_VERSION != RAM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Ram_Drv.h and Ram_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief       Initializes RAM section.
 *
 * @param[in]   RamConfigPtr: Pointer to RAM section configuration.
 *
 * @return      Ram_Drv_StatusType: RAM status.
 *
 */
Ram_Drv_StatusType Ram_Drv_Init(const Ram_Drv_ConfigType *RamConfigPtr);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Ram_Drv */

/** @} end of group Mcu_Module */

#endif /* RAM_DRV_H */
