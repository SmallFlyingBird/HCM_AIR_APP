/**************************************************************************************************/
/**
 * @file      : Scm_Mcu_Drv.h
 * @brief     : SCM low level driver header file for Autosar Mcu
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCM_MCU_DRV_H
#define SCM_MCU_DRV_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Mcu_Drv
 *  @brief SCM low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Scm_Mcu_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SCM_MCU_DRV_H_VENDOR_ID                   0x00B3U
#define SCM_MCU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCM_MCU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define SCM_MCU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define SCM_MCU_DRV_H_SW_MAJOR_VERSION            1U
#define SCM_MCU_DRV_H_SW_MINOR_VERSION            2U
#define SCM_MCU_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Scm_Mcu_Drv_Types.h file are of the same vendor */
#if (SCM_MCU_DRV_H_VENDOR_ID != SCM_MCU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Scm_Mcu_Drv.h and Scm_Mcu_Drv_Types.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv_Types.h file are of the same Autosar version */
#if ((SCM_MCU_DRV_H_AR_RELEASE_MAJOR_VERSION != SCM_MCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (SCM_MCU_DRV_H_AR_RELEASE_MINOR_VERSION != SCM_MCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||   \
     (SCM_MCU_DRV_H_AR_RELEASE_REVISION_VERSION !=                                                 \
      SCM_MCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Scm_Mcu_Drv.h and Scm_Mcu_Drv_Types.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv_Types.h file are of the same software version */
#if ((SCM_MCU_DRV_H_SW_MAJOR_VERSION != SCM_MCU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                   \
     (SCM_MCU_DRV_H_SW_MINOR_VERSION != SCM_MCU_DRV_TYPES_H_SW_MINOR_VERSION) ||                   \
     (SCM_MCU_DRV_H_SW_PATCH_VERSION != SCM_MCU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Scm_Mcu_Drv.h and Scm_Mcu_Drv_Types.h are different"
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
SCM_MCU_DRV_CONFIG_EXT

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief      Initializes the SCM configure.
 *
 * @param[in]  ConfigPtr: Pointer to the SCM configuration.
 *
 * @return     None
 *
 */
void Scm_Mcu_Drv_Init(const Scm_Mcu_Drv_ConfigType *ConfigPtr);

/**
 * @brief    Initializes the SCM clock.
 *
 * @param[in]  ScmClockConfigPtr: Pointer to the SCM clock configuration.
 *
 * @return     None
 *
 */
void Scm_Mcu_Drv_InitClockOut(const Scm_Mcu_Drv_ClockConfigType *ScmClockConfigPtr);

/**
 * @brief    Updates clock out configuration if core clock selected as clock out source and core
 * clock source changed.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scm_Mcu_Drv_UpdateClockOut(void);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Scm_Mcu_Drv */

/** @} end of group Mcu_Module */

#endif /* SCM_MCU_DRV_H */
