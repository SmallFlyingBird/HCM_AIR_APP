/**************************************************************************************************/
/**
 * @file      : Pmu_Drv.h
 * @brief     : PMU low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PMU_DRV_H
#define PMU_DRV_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Pmu_Drv
 *  @brief PMU low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pmu_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PMU_DRV_H_VENDOR_ID                   0x00B3U
#define PMU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define PMU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define PMU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define PMU_DRV_H_SW_MAJOR_VERSION            1U
#define PMU_DRV_H_SW_MINOR_VERSION            2U
#define PMU_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Pmu_Drv_Types.h file are of the same vendor */
#if (PMU_DRV_H_VENDOR_ID != PMU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Pmu_Drv.h and Pmu_Drv_Types.h are different"
#endif

/* Check if current file and Pmu_Drv_Types.h file are of the same Autosar version */
#if ((PMU_DRV_H_AR_RELEASE_MAJOR_VERSION != PMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (PMU_DRV_H_AR_RELEASE_MINOR_VERSION != PMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (PMU_DRV_H_AR_RELEASE_REVISION_VERSION != PMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pmu_Drv.h and Pmu_Drv_Types.h are different"
#endif

/* Check if current file and Pmu_Drv_Types.h file are of the same software version */
#if ((PMU_DRV_H_SW_MAJOR_VERSION != PMU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (PMU_DRV_H_SW_MINOR_VERSION != PMU_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (PMU_DRV_H_SW_PATCH_VERSION != PMU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Pmu_Drv.h and Pmu_Drv_Types.h are different"
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
PMU_DRV_CONFIG_EXT

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief       Initializes PMU configuration.
 *
 * @param[in]   ConfigPtr: Pointer to the PMU configuration.
 *
 * @return      None
 *
 */
void Pmu_Drv_Init(const Pmu_Drv_ConfigType *ConfigPtr);

/**
 * @brief       Clears isolation clear register.
 *
 * @param[in]   None
 *
 * @return      None
 *
 */
void Pmu_Drv_ClearIsolationClear(void);

/**
 * @brief      PMU interrupt handler
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Pmu_Drv_IntHandler(void);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Pmu_Drv */

/** @} end of group Mcu_Module */

#endif /* PMU_DRV_H */
