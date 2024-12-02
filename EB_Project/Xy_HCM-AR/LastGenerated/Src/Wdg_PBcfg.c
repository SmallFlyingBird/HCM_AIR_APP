/**************************************************************************************************/
/**
 * @file      : Wdg_PBcfg.c
 * @brief     : Wdg AUTOSAR level - Post-Build(PB) configuration file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Configuration
 *  @brief Wdg AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_Drvw.h"
#include "Wdg.h"



/** @defgroup Public_MacroDefinition
 *  @{
 */
#define WDG_PBCFG_C_VENDOR_ID                   0x00B3U
#define WDG_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define WDG_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define WDG_PBCFG_C_SW_MAJOR_VERSION            1U
#define WDG_PBCFG_C_SW_MINOR_VERSION            2U
#define WDG_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Wdg_Drvw header file are of the same vendor */
#if (WDG_PBCFG_C_VENDOR_ID != WDG_DRVW_H_VENDOR_ID)
#error "Vendor ID of Wdg_PBcfg.c and Wdg_Drvw.h are different"
#endif

/* Check if current file and Wdg_Drvw header file are of the same Autosar version */
#if ((WDG_PBCFG_C_AR_RELEASE_MAJOR_VERSION     != WDG_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_PBCFG_C_AR_RELEASE_MINOR_VERSION     != WDG_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_PBCFG_C_AR_RELEASE_REVISION_VERSION  != WDG_DRVW_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_PBcfg.c and Wdg_Drvw.h are different"
#endif

/* Check if current file and Wdg_Drvw header file are of the same software version */
#if ((WDG_PBCFG_C_SW_MAJOR_VERSION != WDG_DRVW_H_SW_MAJOR_VERSION) || \
     (WDG_PBCFG_C_SW_MINOR_VERSION != WDG_DRVW_H_SW_MINOR_VERSION) || \
     (WDG_PBCFG_C_SW_PATCH_VERSION != WDG_DRVW_H_SW_PATCH_VERSION))
#error "Software Version of Wdg_PBcfg.c and Wdg_Drvw.h are different"
#endif

/* Check if current file and Wdg header file are of the same vendor */
#if (WDG_PBCFG_C_VENDOR_ID != WDG_VENDOR_ID)
#error "Vendor ID of Wdg_PBcfg.c and Wdg.h are different"
#endif

/* Check if current file and Wdg header file are of the same Autosar version */
#if ((WDG_PBCFG_C_AR_RELEASE_MAJOR_VERSION     != WDG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_PBCFG_C_AR_RELEASE_MINOR_VERSION     != WDG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_PBCFG_C_AR_RELEASE_REVISION_VERSION  != WDG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_PBcfg.c and Wdg.h are different"
#endif

/* Check if current file and Wdg header file are of the same software version */
#if ((WDG_PBCFG_C_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION) || \
     (WDG_PBCFG_C_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION) || \
     (WDG_PBCFG_C_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION))
#error "Software Version of Wdg_PBcfg.c and Wdg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_VariableDefinition
 *  @{
 */
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/**
* @brief Defines the watchdog configure type struct
*/
static const Wdg_ConfigType Wdg_Config=
{
    
    &Wdg_Drvw_Config

};


/**
* @brief Pointer to Wdg Configuration
*/
const Wdg_ConfigType * const Wdg_PreDefinedConfigPtr = &Wdg_Config;


#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"
/** @} end of group Public_VariableDefinition */

#ifdef __cplusplus
}
#endif
/** @} end of group Wdg_Configuration */

/** @} end of group Wdg_Module */
