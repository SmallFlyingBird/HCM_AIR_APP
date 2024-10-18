/**************************************************************************************************/
/**
 * @file      : Wdg_Drvw_PBcfg.c
 * @brief     : Wdg driver wrapper - Post-Build(PB) configuration file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drvw_Configuration
 *  @brief Wdg driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_Drvw.h"
#include "Wdog_Drv.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define WDG_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define WDG_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define WDG_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define WDG_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define WDG_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define WDG_DRVW_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_Drvw header file are of the same vendor */
#if (WDG_DRVW_PBCFG_C_VENDOR_ID != WDG_DRVW_H_VENDOR_ID)
#error "Vendor ID of Wdg_Drvw_PBcfg.c and Wdg_Drvw.h are different"
#endif

/* Check if current file and Wdg_Drvw header file are of the same Autosar version */
#if ((WDG_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION     != WDG_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION     != WDG_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION  != WDG_DRVW_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_Drvw_PBcfg.c and Wdg_Drvw.h are different"
#endif

/* Check if current file and Wdg_Drvw header file are of the same software version */
#if ((WDG_DRVW_PBCFG_C_SW_MAJOR_VERSION != WDG_DRVW_H_SW_MAJOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_SW_MINOR_VERSION != WDG_DRVW_H_SW_MINOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_SW_PATCH_VERSION != WDG_DRVW_H_SW_PATCH_VERSION))
#error "Software Version of Wdg_Drvw_PBcfg.c and Wdg_Drvw.h are different"
#endif

/* Check if current file and Wdog_Drv header file are of the same vendor */
#if (WDG_DRVW_PBCFG_C_VENDOR_ID != WDOG_DRV_H_VENDOR_ID)
#error "Vendor ID of Wdg_Drvw_PBcfg.c and Wdog_Drv.h are different"
#endif

/* Check if current file and Wdog_Drv header file are of the same Autosar version */
#if ((WDG_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION     != WDOG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION     != WDOG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION  != WDOG_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_Drvw_PBcfg.c and Wdog_Drv.h are different"
#endif

/* Check if current file and Wdog_Drv header file are of the same software version */
#if ((WDG_DRVW_PBCFG_C_SW_MAJOR_VERSION != WDOG_DRV_H_SW_MAJOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_SW_MINOR_VERSION != WDOG_DRV_H_SW_MINOR_VERSION) || \
     (WDG_DRVW_PBCFG_C_SW_PATCH_VERSION != WDOG_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Wdg_Drvw_PBcfg.c and Wdog_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_VariableDefinition
 *  @{
 */
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/**
* @brief Callback pointer before the watchdog refresh
*/

/**
* @brief Callback pointer after the watchdog refresh
*/


/**
* @brief Defines the watchdog slow mode setting configure struct
*/
static const Wdg_Drvw_ModeType Wdg_Drvw_SlowModeSetting=
{
    
        (uint32)0x0,    
    &Wdog_Drv_SlowModeConfig

};

/**
* @brief Defines the watchdog fast mode setting configure struct
*/
static const Wdg_Drvw_ModeType Wdg_Drvw_FastModeSetting=
{
    
        (uint32)0x0,    
    &Wdog_Drv_FastModeConfig

};

/**
* @brief Defines the watchdog config type in drvw level
*/
const Wdg_Drvw_ConfigType Wdg_Drvw_Config =
{
    .DefaultMode = WDGIF_OFF_MODE,
    .CbBeforeRefreshPtr = NULL_PTR,
    .CbAfterRefreshPtr = NULL_PTR,
    .ModeConfigPtr[0] = NULL_PTR,
    .ModeConfigPtr[1] = &Wdg_Drvw_SlowModeSetting, 
    .ModeConfigPtr[2] = &Wdg_Drvw_FastModeSetting
};

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"
/** @} end of group Public_VariableDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Wdg_Drvw_Configuration */

/** @} end of group Wdg_Module */
