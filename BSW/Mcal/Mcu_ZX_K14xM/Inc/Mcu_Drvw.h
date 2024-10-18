/**************************************************************************************************/
/**
 * @file      : Mcu_Drvw.h
 * @brief     : AUTOSAR Mcu driver wrapper header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef MCU_DRVW_H
#define MCU_DRVW_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Mcu_Drvw
 *  @brief Mcu middle level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define MCU_DRVW_H_VENDOR_ID                   0x00B3U
#define MCU_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define MCU_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define MCU_DRVW_H_SW_MAJOR_VERSION            1U
#define MCU_DRVW_H_SW_MINOR_VERSION            2U
#define MCU_DRVW_H_SW_PATCH_VERSION            1U

/* Check if current file and Mcu_Drvw_Types.h file are of the same vendor */
#if (MCU_DRVW_H_VENDOR_ID != MCU_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.h and Mcu_Drvw_Types.h are different"
#endif

/* Check if current file and Mcu_Drvw_Types.h file are of the same Autosar version */
#if ((MCU_DRVW_H_AR_RELEASE_MAJOR_VERSION != MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (MCU_DRVW_H_AR_RELEASE_MINOR_VERSION != MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (MCU_DRVW_H_AR_RELEASE_REVISION_VERSION != MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.h and Mcu_Drvw_Types.h are different"
#endif

/* Check if current file and Mcu_Drvw_Types.h file are of the same software version */
#if ((MCU_DRVW_H_SW_MAJOR_VERSION != MCU_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (MCU_DRVW_H_SW_MINOR_VERSION != MCU_DRVW_TYPES_H_SW_MINOR_VERSION) ||                         \
     (MCU_DRVW_H_SW_PATCH_VERSION != MCU_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.h and Mcu_Drvw_Types.h are different"
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

MCU_DRVW_CLOCK_CONFIG_EXT

MCU_DRVW_CONFIG_EXT

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

/**
 * @brief     Initializes SRMC, SCM and PMU modules.
 *
 * @param[in] HwConfigPtr: Pointer to configuration of SRMC, SCM and PMU modules.
 *
 * @return    None
 *
 */
void Mcu_Drvw_Init(const Mcu_Drvw_HwConfigType *HwConfigPtr);

#ifndef MCU_DRVW_MAX_NORAMCONFIGS
/**
 * @brief     Initializes a given RAM section.
 *
 * @param[in] RamConfigPtr: Pointer to RAM section configuration.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     RAM section initialized success.
 * @retval    E_NOT_OK: RAM section initialized failed, e.g. given parameters are invalid.
 *
 */
Std_ReturnType Mcu_Drvw_InitRamSection(const Ram_Drv_ConfigType *RamConfigPtr);
#endif /* ifndef MCU_DRVW_MAX_NORAMCONFIGS */

#if (MCU_DRVW_INIT_CLOCK == STD_ON)
/**
 * @brief     Initializes the clock.
 *
 * @param[in] ClockConfigPtr: Pointer to clock configuration.
 *
 * @return    None
 *
 */
void Mcu_Drvw_InitClock(const Mcu_Drvw_ClockConfigType *ClockConfigPtr);
#endif /* (MCU_DRVW_INIT_CLOCK == STD_ON) */

#if (MCU_DRVW_NO_PLL == STD_OFF)
/**
 * @brief      Activates the main PLL as the system clock source.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_DistributePllClock(void);
#endif /* (MCU_DRVW_NO_PLL == STD_OFF) */

#if (MCU_DRVW_NO_PLL == STD_OFF)
/**
 * @brief      Gets PLL clock status.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  PLL is enabled and ready.
 * @retval     FALSE: PLL is not enabled or not ready.
 *
 */
boolean Mcu_Drvw_GetPllStatus(void);
#endif /* (MCU_DRVW_NO_PLL == STD_OFF) */

/**
 * @brief      Sets MCU mode.
 *
 * @param[in]  PowerMode: Selected MCU power mode.
 *
 * @return     None
 *
 */
void Mcu_Drvw_SetMode(const Mcu_Drvw_PowerModeType PowerMode);

#if MCU_DRVW_PERFORM_RESET_API == STD_ON
/**
 * @brief      Performs a microcontroller reset.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_PerformReset(void);
#endif /* (MCU_DRVW_PERFORM_RESET_API == STD_ON) */

/**
 * @brief      Gets MCU reset reason.
 *
 * @param[in]  None
 *
 * @return     Mcu_Drvw_ResetType: Reset reason.
 *
 */
Mcu_Drvw_ResetType Mcu_Drvw_GetResetReason(void);

/**
 * @brief      Gets reset reason raw value.
 *
 * @param[in]  None
 *
 * @return     uint32: reset reason raw value.
 *
 */
uint32 Mcu_Drvw_GetResetRawValue(void);

#if (MCU_DRVW_POWERMODE_STATE_API == STD_ON)
/**
 * @brief      Gets current power mode.
 *
 * @param[in]  None
 *
 * @return     Mcu_Drvw_PowerModeType: Current power mode.
 *
 */
Mcu_Drvw_PowerModeType Mcu_Drvw_GetPowerModeState(void);
#endif /* (MCU_DRVW_POWERMODE_STATE_API == STD_ON) */

/**
 * @brief      Enables OSC clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Mcu_Drvw_EnableOscClockMonitor(Mcu_Drvw_OscClockLossActType Act);

/**
 * @brief      Disables OSC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_DisableOscClockMonitor(void);

/**
 * @brief      Enables FIRC64M clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Mcu_Drvw_EnableFirc64MClockMonitor(Mcu_Drvw_Firc64MClockLossActType Act);

/**
 * @brief      Disables FIRC64M clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_DisableFirc64MClockMonitor(void);

#if (MCU_DRVW_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 * @brief      Enables PLL clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Mcu_Drvw_EnablePllClockMonitor(Mcu_Drvw_PllClockLossActType Act);
#endif

/**
 * @brief      Configs wakeup source.
 *
 * @param[in]  WakeupSource: Wakeup source.
 * @param[in]  ActiveHigh: Wakeup MCU if polarity is high.
 * @param[in]  Enable: Enable/disable.
 *
 * @return     None
 *
 */
void Mcu_Drvw_SetWakeupSource(Mcu_Drvw_WakeupSourceType WakeupSource, boolean ActiveHigh,
                              boolean Enable);

/**
 * @brief      Get the given clock source ready state.
 *
 * @param[in]  ClockSource: Given clock source.
 *
 * @return     boolean
 * @retval     TRUE:  Given clock is ready.
 * @retval     FALSE: Given clock is not ready.
 *
 */
boolean Mcu_Drvw_GetClockReadyState(Mcu_Drvw_ClockSrcType ClockSource);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Mcu_Drvw */

/** @} end of group Mcu_Module */

#endif /* MCU_DRVW_H */
