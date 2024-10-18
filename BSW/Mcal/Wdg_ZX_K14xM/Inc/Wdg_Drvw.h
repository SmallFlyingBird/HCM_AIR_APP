/**************************************************************************************************/
/**
 * @file      : Wdg_Drvw.h
 * @brief     : Wdg driver wrapper header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_DRVW_H
#define WDG_DRVW_H

/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drvw
 *  @brief Wdg middle level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_DRVW_H_VENDOR_ID                   0x00B3U
#define WDG_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_DRVW_H_SW_MAJOR_VERSION            1U
#define WDG_DRVW_H_SW_MINOR_VERSION            2U
#define WDG_DRVW_H_SW_PATCH_VERSION            1U

/* Check if Wdg_Drvw.h and Wdg_Drvw_Types.h are of the same vendor */
#if (WDG_DRVW_H_VENDOR_ID != WDG_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Drvw.h and Wdg_Drvw_Types.h are different"
#endif
/* Check if Wdg_Drvw.h file and Wdg_Drvw_Types.h file are of the same Autosar version */
#if ((WDG_DRVW_H_AR_RELEASE_MAJOR_VERSION != WDG_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_DRVW_H_AR_RELEASE_MINOR_VERSION != WDG_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_DRVW_H_AR_RELEASE_REVISION_VERSION != WDG_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdg_Drvw.h and Wdg_Drvw_Types.h are different"
#endif
/* Check if Wdg_Drvw.h and Wdg_Drvw_Types.h file are of the same software version */
#if ((WDG_DRVW_H_SW_MAJOR_VERSION != WDG_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
     (WDG_DRVW_H_SW_MINOR_VERSION != WDG_DRVW_TYPES_H_SW_MINOR_VERSION) || \
     (WDG_DRVW_H_SW_PATCH_VERSION != WDG_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Wdg_Drvw.h and Wdg_Drvw_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
WDG_DRVW_CONFIG_EXT

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#if (WDG_DRVW_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif

#include "Wdg_MemMap.h"

/**
 * @brief   On the basis of the Config structure pointer, initializes the wathchdog module
 *
 * @param[in] ConfigPtr: Configuration structure of the watchdog module.
 *
 *
 * @return   The init status
 * @retval   E_OK 
 * @retval   E_NOT_OK
 */
Std_ReturnType Wdg_Drvw_Init(const Wdg_Drvw_ConfigType *ConfigPtr);

/**
 * @brief    Config the watchdog Fast/Slow/Off mode.
 *
 * @param[in] Mode: The accessible watchdog mode(Fast/Slow/Off).
 * @param[in] ConfigPtr: Watchdog module configuration structure of different mode.
 * 
 * @return   the setmode result status
 * @retval   E_OK
 * @retval   E_NOT_OK
 * 
 */
Std_ReturnType Wdg_Drvw_SetMode(const WdgIf_ModeType Mode, const Wdg_Drvw_ConfigType *ConfigPtr);

/**
 * @brief   This function can refresh the watchdog counter.
 * 
 * @param[in]  ConfigPtr: Watchdog configuration structure pointer.
 * 
 * @return   None
 *
 */
void Wdg_Drvw_Refresh(const Wdg_Drvw_ConfigType *ConfigPtr);

#if (WDG_DRVW_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/** @} end of Public_FunctionDeclaration */
#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdg_Drvw */

/** @} end of group Wdg_Module */
