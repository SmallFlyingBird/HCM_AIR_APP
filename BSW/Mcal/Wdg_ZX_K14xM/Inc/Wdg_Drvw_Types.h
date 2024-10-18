/**************************************************************************************************/
/**
 * @file      : Wdg_Drvw_Types.h
 * @brief     : Wdg driver wrapper header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_DRVW_TYPES_H
#define WDG_DRVW_TYPES_H

/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drvw_Types
 *  @brief Wdg middle level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Wdog_Drv_Types.h"
#include "Wdg_Drvw_Cfg.h"
#include "WdgIf.h"
#if (WDG_DRVW_DIRECT_SERVICE == STD_OFF)
#include "Gpt.h"
#endif
/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define WDG_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define WDG_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define WDG_DRVW_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_Drvw_Cfg.h are of the same vendor */
#if (WDG_DRVW_TYPES_H_VENDOR_ID != WDG_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Drvw_Types.h and Wdg_Drvw_Cfg.h are different"
#endif
/* Check if current file and Wdg_Drvw_Cfg.h file are of the same Autosar version */
#if ((WDG_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != WDG_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != WDG_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != WDG_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdg_Drvw_Types.h and Wdg_Drvw_Cfg.h are different"
#endif
/* Check if current file and Wdog_Drv_PBcfg.h file are of the same software version */
#if ((WDG_DRVW_TYPES_H_SW_MAJOR_VERSION != WDG_DRVW_CFG_H_SW_MAJOR_VERSION) || \
     (WDG_DRVW_TYPES_H_SW_MINOR_VERSION != WDG_DRVW_CFG_H_SW_MINOR_VERSION) || \
     (WDG_DRVW_TYPES_H_SW_PATCH_VERSION != WDG_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Wdg_Drvw_Types.h and Wdg_Drvw_Cfg.h are different"
#endif

/* Check if current file and Wdog_Drv_Types.h are of the same vendor */
#if (WDG_DRVW_TYPES_H_VENDOR_ID != WDG_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Drvw_Types.h and Wdog_Drv_Types.h are different"
#endif
/* Check if current file and Wdog_Drv_Types.h file are of the same Autosar version */
#if ((WDG_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != WDG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != WDG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != WDG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdg_Drvw_Types.h and Wdog_Drv_Types.h are different"
#endif
/* Check if current file and Wdog_Drv_PBcfg.h file are of the same software version */
#if ((WDG_DRVW_TYPES_H_SW_MAJOR_VERSION != WDG_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (WDG_DRVW_TYPES_H_SW_MINOR_VERSION != WDG_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (WDG_DRVW_TYPES_H_SW_PATCH_VERSION != WDG_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Wdg_Drvw_Types.h and Wdog_Drv_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
#if (WDG_DRVW_DIRECT_SERVICE == STD_OFF)
    /* Check if current file and Gpt.h are the same Autosar version */
    #if ((WDG_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) ||         \
         (WDG_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdg_Drvw_Types.h and Gpt.h are different"
    #endif
#endif
    /* Check if current file and WdgIf.h are the same Autosar version */
    #if ((WDG_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != WDGIF_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != WDGIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdg_Drvw_Types.h and WdgIf.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/**
 * @brief  extended return value for Std_ReturnType
 */
#define  WDG_DRVW_E_TIMEOUT        0x02U   

#define WDG_DRVW_RUN_IN_ROM  WDG_DRV_RUN_IN_ROM

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
* @brief Defines the watchdog mode type in drvw level
*/
typedef struct
{
    uint32 TimerTriggerPeriod;
    const Wdog_Drv_ConfigType *WdogDrvConfig;
} Wdg_Drvw_ModeType;

/**
* @brief Defines the watchdog config type in drvw level
*/
typedef struct
{
    const WdgIf_ModeType DefaultMode;
    Wdog_Drv_CallbackPtrType   CbBeforeRefreshPtr;
    Wdog_Drv_CallbackPtrType   CbAfterRefreshPtr;
    const Wdg_Drvw_ModeType *const ModeConfigPtr[3];
}Wdg_Drvw_ConfigType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdg_Drvw_Types */

/** @} end of group Wdg_Module */
