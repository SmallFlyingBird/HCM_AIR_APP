/**************************************************************************************************/
/**
 * @file      : Wdg_179_Ewdt_Types.h
 * @brief     : Wdg_179_Ewdt AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_179_EWDT_TYPES_H
#define WDG_179_EWDT_TYPES_H

/** @addtogroup  Wdg_179_Ewdt_Module
 *  @{
 */

/** @addtogroup Wdg_179_Ewdt_Types
 *  @brief Wdg_179_Ewdt AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_179_Ewdt_Cfg.h"
#include "Ewdt_Drv_Types.h"
#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
#include "Gpt.h"
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_179_EWDT_TYPES_H_VENDOR_ID                   0x00B3U
#define WDG_179_EWDT_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_179_EWDT_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_179_EWDT_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_179_EWDT_TYPES_H_SW_MAJOR_VERSION            1U
#define WDG_179_EWDT_TYPES_H_SW_MINOR_VERSION            2U
#define WDG_179_EWDT_TYPES_H_SW_PATCH_VERSION            1U

/* Check if Wdg_179_Ewdt_Types.h and Ewdt_Drv_Types.h are of the same vendor */
#if (WDG_179_EWDT_TYPES_H_VENDOR_ID != EWDT_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Wdg_179_Ewdt_Types.h and Ewdt_Drv_Types.h are different"
#endif
/* Check if Wdg_179_Ewdt_Types.h and Ewdt_Drv_Types.h file are of the same Autosar version */
#if ((WDG_179_EWDT_TYPES_H_AR_RELEASE_MAJOR_VERSION != EWDT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_AR_RELEASE_MINOR_VERSION != EWDT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_AR_RELEASE_REVISION_VERSION != EWDT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdg_179_Ewdt_Types.h and Ewdt_Drv_Types.h are different"
#endif
/* Check if Wdg_179_Ewdt_Types.h and Ewdt_Drv_Types.h file are of the same software version */
#if ((WDG_179_EWDT_TYPES_H_SW_MAJOR_VERSION != EWDT_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_SW_MINOR_VERSION != EWDT_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_SW_PATCH_VERSION != EWDT_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Wdg_179_Ewdt_Types.h and Ewdt_Drv_Types.h are different"
#endif

/* Check if Wdg_179_Ewdt_Types.h and Wdg_179_Ewdt_Cfg.h are of the same vendor */
#if (WDG_179_EWDT_TYPES_H_VENDOR_ID != WDG_179_EWDT_CFG_H_VENDOR_ID)
    #error "Vendor ID of Wdg_179_Ewdt_Types.h and Wdg_179_Ewdt_Cfg.h are different"
#endif
/* Check if Wdg_179_Ewdt_Types.h and Wdg_179_Ewdt_Cfg.h file are of the same Autosar version */
#if ((WDG_179_EWDT_TYPES_H_AR_RELEASE_MAJOR_VERSION != WDG_179_EWDT_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_AR_RELEASE_MINOR_VERSION != WDG_179_EWDT_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_AR_RELEASE_REVISION_VERSION != WDG_179_EWDT_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdg_179_Ewdt_Types.h and Wdg_179_Ewdt_Cfg.h are different"
#endif
/* Check if Wdg_179_Ewdt_Types.h and Wdg_179_Ewdt_Cfg.h file are of the same software version */
#if ((WDG_179_EWDT_TYPES_H_SW_MAJOR_VERSION != WDG_179_EWDT_CFG_H_SW_MAJOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_SW_MINOR_VERSION != WDG_179_EWDT_CFG_H_SW_MINOR_VERSION) || \
     (WDG_179_EWDT_TYPES_H_SW_PATCH_VERSION != WDG_179_EWDT_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Wdg_179_Ewdt_Types.h and Wdg_179_Ewdt_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
    /* Check if current file and Gpt.h are the same Autosar version */
    #if ((WDG_179_EWDT_TYPES_H_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) ||         \
         (WDG_179_EWDT_TYPES_H_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdg_179_Ewdt_Types.h and Gpt.h are different"
    #endif
#endif
#endif

#define     WDG_179_EWDT_RUN_IN_ROM             EWDT_DRV_RUN_IN_ROM
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
* @brief  Defines the ewdt configuration type structure
*/
typedef struct
{
#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
    const Gpt_ChannelType GptChannel;
    const uint32 GptClock;
#endif
    uint32 TimerTriggerPeriod;
    Ewdt_Drv_CallbackPtrType   CbBeforeRefreshPtr;
    Ewdt_Drv_CallbackPtrType   CbAfterRefreshPtr;
    const Ewdt_Drv_ConfigType *EwdtDrvConfig;
} Wdg_179_Ewdt_ConfigType;

/**
* @brief  Wdg_179_Ewdt state definition
*/
typedef enum
{
    WDG_179_EWDT_UNINIT    = 0x01,  /*!< The Wdg_179_Ewdt is not uninitialized */
    WDG_179_EWDT_IDLE      = 0x02,  /*!< The Wdg_179_Ewdt is idle */
    WDG_179_EWDT_BUSY      = 0x03,  /*!< The Wdg_179_Ewdt is busy */
} Wdg_179_Ewdt_StateType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdg_179_Ewdt_Types */

/** @} end of group Wdg_179_Ewdt_Module */
