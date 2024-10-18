/**************************************************************************************************/
/**
 * @file      : Parcc_Drv.h
 * @brief     : PARCC low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PARCC_DRV_H
#define PARCC_DRV_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Parcc_Drv
 *  @brief PARCC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Parcc_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PARCC_DRV_H_VENDOR_ID                   0x00B3U
#define PARCC_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define PARCC_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define PARCC_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define PARCC_DRV_H_SW_MAJOR_VERSION            1U
#define PARCC_DRV_H_SW_MINOR_VERSION            2U
#define PARCC_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Parcc_Drv_Types.h file are of the same vendor */
#if (PARCC_DRV_H_VENDOR_ID != PARCC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Parcc_Drv.h and Parcc_Drv_Types.h are different"
#endif

/* Check if current file and Parcc_Drv_Types.h file are of the same Autosar version */
#if ((PARCC_DRV_H_AR_RELEASE_MAJOR_VERSION != PARCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (PARCC_DRV_H_AR_RELEASE_MINOR_VERSION != PARCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||       \
     (PARCC_DRV_H_AR_RELEASE_REVISION_VERSION != PARCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Parcc_Drv.h and Parcc_Drv_Types.h are different"
#endif

/* Check if current file and Parcc_Drv_Types.h file are of the same software version */
#if ((PARCC_DRV_H_SW_MAJOR_VERSION != PARCC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                       \
     (PARCC_DRV_H_SW_MINOR_VERSION != PARCC_DRV_TYPES_H_SW_MINOR_VERSION) ||                       \
     (PARCC_DRV_H_SW_PATCH_VERSION != PARCC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Parcc_Drv.h and Parcc_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/**
 * @brief   Export Post-Build configurations.
 */
PARCC_DRV_CONFIG_EXT

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief       Initializes the PARCC configuration.
 *
 * @param[in]   ConfigPtr: Pointer to the PARCC configuration.
 *
 * @return      None
 *
 */
void Parcc_Drv_Init(const Parcc_Drv_SystemParccConfigType *ConfigPtr);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Parcc_Drv */

/** @} end of group Mcu_Module */

#endif /* PARCC_DRV_H */
