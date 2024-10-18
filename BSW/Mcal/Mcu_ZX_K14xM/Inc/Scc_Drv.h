/**************************************************************************************************/
/**
 * @file      : Scc_Drv.h
 * @brief     : SCC low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCC_DRV_H
#define SCC_DRV_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Scc_Drv
 *  @brief SCC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Scc_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SCC_DRV_H_VENDOR_ID                   0x00B3U
#define SCC_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCC_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define SCC_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define SCC_DRV_H_SW_MAJOR_VERSION            1U
#define SCC_DRV_H_SW_MINOR_VERSION            2U
#define SCC_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Scc_Drv_Types.h file are of the same vendor */
#if (SCC_DRV_H_VENDOR_ID != SCC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Scc_Drv.h and Scc_Drv_Types.h are different"
#endif

/* Check if current file and Scc_Drv_Types.h file are of the same Autosar version */
#if ((SCC_DRV_H_AR_RELEASE_MAJOR_VERSION != SCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (SCC_DRV_H_AR_RELEASE_MINOR_VERSION != SCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (SCC_DRV_H_AR_RELEASE_REVISION_VERSION != SCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Scc_Drv.h and Scc_Drv_Types.h are different"
#endif

/* Check if current file and Scc_Drv_Types.h file are of the same software version */
#if ((SCC_DRV_H_SW_MAJOR_VERSION != SCC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (SCC_DRV_H_SW_MINOR_VERSION != SCC_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (SCC_DRV_H_SW_PATCH_VERSION != SCC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Scc_Drv.h and Scc_Drv_Types.h are different"
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
SCC_DRV_CONFIG_EXT

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief      Enables OSC clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Scc_Drv_EnableOscClockMonitor(Scc_Drv_OscClockLossActType Act);

/**
 * @brief      Disables OSC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_DisableOscClockMonitor(void);

/**
 * @brief      Enables FIRC64M clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Scc_Drv_EnableFirc64MClockMonitor(Scc_Drv_Firc64MClockLossActType Act);

/**
 * @brief      Disables FIRC64M clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_DisableFirc64MClockMonitor(void);

#if (SCC_DRV_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 * @brief      Enables PLL clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Scc_Drv_EnablePllClockMonitor(Scc_Drv_PllClockLossActType Act);
#endif

/**
 * @brief      Selects PLL referenced clock source.
 *
 * @param[in]  PllRefClk: PLL referenced clock.
 *
 * @return     None
 *
 */
void Scc_Drv_SelectPllClockRefSrc(Scc_Drv_PllRefClockType PllRefClk);

/**
 * @brief       Configs SCC clock.
 *
 * @param[in]   ClockConfigPtr: Pointer to the SCC clock configuration.
 *
 * @return      None
 *
 */
void Scc_Drv_ConfigSccClock(const Scc_Drv_ClockConfigType *ClockConfigPtr);

/**
 * @brief       Gets PLL clock status.
 *
 * @param[in]   None
 *
 * @return      boolean
 * @retval      TRUE:  PLL is enabled and ready.
 * @retval      FALSE: PLL is not enabled or not ready.
 *
 */
boolean Scc_Drv_GetPllClockStatus(void);

/**
 * @brief       Gets whether the PLL clock has been selected system clock source.
 *
 * @param[in]   None
 *
 * @return      boolean
 * @retval      TRUE:  PLL is the system clock source.
 * @retval      FALSE: PLL is not the system clock source.
 *
 */
boolean Scc_Drv_GetPllClockSelectedState(void);

/**
 * @brief       Gets FIRC64M clock status.
 *
 * @param[in]   None
 *
 * @return      boolean
 * @retval      TRUE:  FIRC64M clock is enabled and ready.
 * @retval      FALSE: FIRC64M clock is not enabled or not ready.
 */
boolean Scc_Drv_GetFirc64MClockStatus(void);

/**
 * @brief     Sets the system clock source and update RWSC in Flash module according to system
 * clock frequency.
 * @note      The selected clock source has to be ready before call this function.
 *
 * @param[in] ClockSrc: Selected clock source.
 * @param[in] SysClockFreq: System clock frequency.
 *
 * @return    boolean
 * @retval    TRUE:  System clock source has been set with the given clock source.
 * @retval    FALSE: Set system clock source with given clock source failed, e.g. given clock source
 *                   is not ready.
 */
boolean Scc_Drv_SetSysClockSrc(Scc_Drv_SystemClockType ClockSrc, uint32 SysClockFreq);

/**
 * @brief      Returns PLL clock frequency.
 *
 * @param[in]  None
 *
 * @return     uint32: PLL clock frequency
 *
 */
uint32 Scc_Drv_GetPllClockFreq(void);

/**
 * @brief      Enables FIRC64M clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_EnableFirc64MClock(void);

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
boolean Scc_Drv_GetClockReadyState(Scc_Drv_ClockSrcType ClockSource);

/**
 * @brief      SCC interrupt handler
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_IntHandler(void);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Scc_Drv */

/** @} end of group Mcu_Module */

#endif /* SCC_DRV_H */
