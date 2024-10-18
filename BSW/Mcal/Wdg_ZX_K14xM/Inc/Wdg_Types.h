/**************************************************************************************************/
/**
 * @file      : Wdg_Types.h
 * @brief     : Wdg AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_TYPES_H
#define WDG_TYPES_H

/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Types
 *  @brief Wdg AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_Cfg.h"
#include "Wdg_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_TYPES_H_VENDOR_ID                   0x00B3U
#define WDG_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_TYPES_H_SW_MAJOR_VERSION            1U
#define WDG_TYPES_H_SW_MINOR_VERSION            2U
#define WDG_TYPES_H_SW_PATCH_VERSION            1U

/* Check if Wdg_Types.h and Wdg_Drvw_Types.h are of the same vendor */
#if (WDG_TYPES_H_VENDOR_ID != WDG_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Types.h and Wdg_Drvw_Types.h are different"
#endif
/* Check if Wdg_Types.h and Wdg_Drvw_Types.h file are of the same Autosar version */
#if ((WDG_TYPES_H_AR_RELEASE_MAJOR_VERSION != WDG_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_TYPES_H_AR_RELEASE_MINOR_VERSION != WDG_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_TYPES_H_AR_RELEASE_REVISION_VERSION != WDG_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdg_Types.h and Wdg_Drvw_Types.h are different"
#endif
/* Check if Wdg_Types.h and Wdg_Drvw_Types.h file are of the same software version */
#if ((WDG_TYPES_H_SW_MAJOR_VERSION != WDG_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
     (WDG_TYPES_H_SW_MINOR_VERSION != WDG_DRVW_TYPES_H_SW_MINOR_VERSION) || \
     (WDG_TYPES_H_SW_PATCH_VERSION != WDG_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Wdg_Types.h and Wdg_Drvw_Types.h are different"
#endif

/* Check if Wdg_Types.h and Wdg_Cfg.h are of the same vendor */
#if (WDG_TYPES_H_VENDOR_ID != WDG_CFG_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Types.h and Wdg_Cfg.h are different"
#endif
/* Check if Wdg_Types.h and Wdg_Cfg.h file are of the same Autosar version */
#if ((WDG_TYPES_H_AR_RELEASE_MAJOR_VERSION != WDG_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_TYPES_H_AR_RELEASE_MINOR_VERSION != WDG_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_TYPES_H_AR_RELEASE_REVISION_VERSION != WDG_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdg_Types.h and Wdg_Cfg.h are different"
#endif
/* Check if Wdg_Types.h and Wdg_Cfg.h file are of the same software version */
#if ((WDG_TYPES_H_SW_MAJOR_VERSION != WDG_CFG_H_SW_MAJOR_VERSION) || \
     (WDG_TYPES_H_SW_MINOR_VERSION != WDG_CFG_H_SW_MINOR_VERSION) || \
     (WDG_TYPES_H_SW_PATCH_VERSION != WDG_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Wdg_Types.h and Wdg_Cfg.h are different"
#endif

#define     WDG_RUN_IN_ROM             WDG_DRVW_RUN_IN_ROM
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
* @brief  Defines the watchdog configuration type structure
*/
typedef struct
{
#if (WDG_DIRECT_SERVICE == STD_OFF)
    const Gpt_ChannelType GptChannel;
    const uint32 GptClock;
#endif
    const Wdg_Drvw_ConfigType * DrvwConfigPtr;
} Wdg_ConfigType;

/**
* @brief  Wdg state definition
*/
typedef enum
{
    WDG_UNINIT    = 0x01,  /*!< The Wdg is not uninitialized */
    WDG_IDLE      = 0x02,  /*!< The Wdg is idle */
    WDG_BUSY      = 0x03,  /*!< The Wdg is busy */
} Wdg_StateType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdg_Types */

/** @} end of group Wdg_Module */
