/**************************************************************************************************/
/**
 * @file      : Srmc_Drv.h
 * @brief     : SRMC low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SRMC_DRV_H
#define SRMC_DRV_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Srmc_Drv
 *  @brief SRMC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Srmc_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SRMC_DRV_H_VENDOR_ID                   0x00B3U
#define SRMC_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define SRMC_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define SRMC_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define SRMC_DRV_H_SW_MAJOR_VERSION            1U
#define SRMC_DRV_H_SW_MINOR_VERSION            2U
#define SRMC_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Srmc_Drv_Types.h file are of the same vendor */
#if (SRMC_DRV_H_VENDOR_ID != SRMC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Srmc_Drv.h and Srmc_Drv_Types.h are different"
#endif

/* Check if current file and Srmc_Drv_Types.h file are of the same Autosar version */
#if ((SRMC_DRV_H_AR_RELEASE_MAJOR_VERSION != SRMC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (SRMC_DRV_H_AR_RELEASE_MINOR_VERSION != SRMC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (SRMC_DRV_H_AR_RELEASE_REVISION_VERSION != SRMC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Srmc_Drv.h and Srmc_Drv_Types.h are different"
#endif

/* Check if current file and Srmc_Drv_Types.h file are of the same software version */
#if ((SRMC_DRV_H_SW_MAJOR_VERSION != SRMC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (SRMC_DRV_H_SW_MINOR_VERSION != SRMC_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (SRMC_DRV_H_SW_PATCH_VERSION != SRMC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Srmc_Drv.h and Srmc_Drv_Types.h are different"
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
SRMC_DRV_CONFIG_EXT

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief      Gets current MCU mode.
 *
 * @param[in]  None
 *
 * @return     Srmc_Drv_PowerModeType: Current MCU mode.
 *
 */
Srmc_Drv_PowerModeType Srmc_Drv_GetCurrentPowerMode(void);

/**
 * @brief      Initializes reset configuration of SRMC module.
 *
 * @param[in]  ConfigPtr: Pointer to SRMC Reset configuration.
 *
 * @return     None
 *
 */
void Srmc_Drv_InitResetConfiguration(const Srmc_Drv_ResetConfigType *ConfigPtr);

/**
 * @brief      Initializes power mode configuration of SRMC module.
 *
 * @param[in]  ConfigPtr: Pointer to SRMC Power mode configuration.
 *
 * @return     None
 *
 */
void Srmc_Drv_InitPowerMode(const Srmc_Drv_PowerModeConfigType *ConfigPtr);

/**
 * @brief      Reads reset reason value from SRMC module.
 *
 * @param[in]  None
 *
 * @return     uint32: Reset reason value.
 *
 */
uint32 Srmc_Drv_GetResetReasonValue(void);

/**
 * @brief      Reads reset interrupt configuration.
 *
 * @param[in]  None
 *
 * @return     uint32: Settings of reset interrupt configuration.
 *
 */
uint32 Srmc_Drv_GetSysResetInterruptConfig(void);

/**
 * @brief      Sets reset interrupts in SRMC.
 *
 * @param[in]  ResetInterruptConfig: Settings of reset interrupt configuration.
 *
 * @return     None
 *
 */
void Srmc_Drv_SetSysResetInterruptConfig(uint32 ResetInterruptConfig);

/**
 * @brief      Sets MCU mode.
 *
 * @param[in]  PowerMode: MCU power mode.
 *
 * @return     None
 *
 */
void Srmc_Drv_SetMode(const Srmc_Drv_PowerModeType PowerMode);

/**
 * @brief      Configs wakeup sources in SRMC.
 *
 * @param[in]  WakeupSource: Given wakeup source.
 * @param[in]  Enable: Enable/disable this source to wakeup the MCU.
 *
 * @return     None
 *
 */
void Srmc_Drv_SetWakeupSource(Srmc_Drv_WakeupSourceType WakeupSource, boolean Enable);

/**
 * @brief      Configs the polarity of given source to wakeup the MCU.
 *
 * @param[in]  WakeupSource: Given wakeup source.
 * @param[in]  ActivePolarity: Wakeup MCU if polarity low or high.
 *
 * @return     None
 *
 */
void Srmc_Drv_ConfigWakeupSource(Srmc_Drv_WakeupSourceType WakeupSource,
                                 Srmc_Drv_WupPolarityType  ActivePolarity);

/**
 * @brief      Gets whether the given source is enabled or not to wakeup the MCU.
 *
 * @param[in]  WakeupSource: Given wakeup source.
 *
 * @return     boolean
 * @retval     TRUE:  Given wakeup source is enabled to wakeup the MCU.
 * @retval     FALSE: Given wakeup source is not enabled to wakeup the MCU.
 *
 */
boolean Srmc_Drv_GetWakeupSourceStatus(Srmc_Drv_WakeupSourceType WakeupSource);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Srmc_Drv */

/** @} end of group Mcu_Module */

#endif /* SRMC_DRV_H */
