/**************************************************************************************************/
/**
 * @file      : Wdog_Drv_PBcfg.c  
 * @brief     : Wdg low level driver - Post-Build(PB) configuration file
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

/** @addtogroup Wdog_Drv_Configuration
 *  @brief Wdg low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Wdog_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define WDOG_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define WDOG_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDOG_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define WDOG_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define WDOG_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define WDOG_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define WDOG_DRV_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Wdog_Drv header file are of the same vendor */
#if (WDOG_DRV_PBCFG_C_VENDOR_ID != WDOG_DRV_H_VENDOR_ID)
#error "Vendor ID of Wdog_Drv_PBcfg.c and Wdog_Drv.h are different"
#endif

/* Check if current file and Wdog_Drv header file are of the same Autosar version */
#if ((WDOG_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != WDOG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDOG_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != WDOG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (WDOG_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != WDOG_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdog_Drv_PBcfg.c and Wdog_Drv.h are different"
#endif

/* Check if current file and Wdog_Drv header file are of the same software version */
#if ((WDOG_DRV_PBCFG_C_SW_MAJOR_VERSION != WDOG_DRV_H_SW_MAJOR_VERSION) || \
     (WDOG_DRV_PBCFG_C_SW_MINOR_VERSION != WDOG_DRV_H_SW_MINOR_VERSION) || \
     (WDOG_DRV_PBCFG_C_SW_PATCH_VERSION != WDOG_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Wdog_Drv_PBcfg.c and Wdog_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_VariableDefinition
 *  @{
 */

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"



/**
* @brief Defines the watchdog config type of slow mode setting 
*/
const Wdog_Drv_ConfigType Wdog_Drv_SlowModeConfig=
{

    .ClkSource = (Wdog_Drv_ClkSourceType)WDOG_DRV_CLOCK_LPO, 
    .OpMode = 
    {
        .WaitMode = (boolean)FALSE,
        .StopMode = (boolean)FALSE,           
        .DebugMode = (boolean)FALSE
    },
    .UpdateEnable = (boolean)TRUE,
    .IntEnable = (boolean)FALSE,
    .WindowEnable = (boolean)FALSE, 
    .WindowValue = (uint32)0x00U, 
    .TimeoutValue = (uint32)0x0004e200U,
    (Wdog_Drv_CallbackPtrType)NULL_PTR
};

/**
* @brief Defines the watchdog config type of fast mode setting 
*/
const Wdog_Drv_ConfigType Wdog_Drv_FastModeConfig= 
{

    .ClkSource = (Wdog_Drv_ClkSourceType)WDOG_DRV_CLOCK_LPO, 
    .OpMode = 
    {
        .WaitMode = (boolean)FALSE,
        .StopMode = (boolean)FALSE,           
        .DebugMode = (boolean)FALSE
    },
    .UpdateEnable = (boolean)TRUE,
    .IntEnable = (boolean)FALSE,
    .WindowEnable = (boolean)FALSE, 
    .WindowValue = (uint32)0x00U, 
    .TimeoutValue = (uint32)0x0004e200U,
    (Wdog_Drv_CallbackPtrType)NULL_PTR
};

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/** @} end of group Public_VariableDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Wdog_Drv_Configuration */

/** @} end of group Wdg_Module */
