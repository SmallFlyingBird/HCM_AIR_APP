/**************************************************************************************************/
/**
 * @file      : Wdog_Drv_Types.h
 * @brief     : Wdg low level types header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_DRV_TYPES_H
#define WDG_DRV_TYPES_H

/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdog_Drv_Types
 *  @brief Wdg low level types
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdog_Drv_Cfg.h"
#include "SchM_Wdg.h"
#include "McalLib.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define WDG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define WDG_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define WDG_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Wdog_Drv_Cfg.h are of the same vendor */
#if (WDG_DRV_TYPES_H_VENDOR_ID != WDOG_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Wdog_Drv_Types.h and Wdog_Drv_Cfg.h are different"
#endif
/* Check if current file file and Wdog_Drv_Cfg.h file are of the same Autosar version */
#if ((WDG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != WDOG_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != WDOG_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
        (WDG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                           \
        WDOG_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdog_Drv_Types.h and Wdog_Drv_Cfg.h are different"
#endif
/* Check if current file and Wdog_Drv_Cfg.h are of the same software version */
#if ((WDG_DRV_TYPES_H_SW_MAJOR_VERSION != WDOG_DRV_CFG_H_SW_MAJOR_VERSION) ||                 \
        (WDG_DRV_TYPES_H_SW_MINOR_VERSION != WDOG_DRV_CFG_H_SW_MINOR_VERSION) ||                 \
        (WDG_DRV_TYPES_H_SW_PATCH_VERSION != WDOG_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Wdog_Drv_Types.h and Wdog_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file file and McalLib.h file are of the same Autosar version */
    #if ((WDG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (WDG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdog_Drv_Types.h and McalLib.h are different"
    #endif
    /* Check if current file file and SchM_Wdg.h file are of the same Autosar version */
    #if ((WDG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != SCHM_WDG_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != SCHM_WDG_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdog_Drv_Types.h and SchM_Wdg.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief WDOG callback type
 */
typedef void (*Wdog_Drv_CallbackPtrType)(void);

/**
 * @brief Clock sources for the WDOG.
 */
typedef enum
{
    WDOG_DRV_CLOCK_LPO = 0x00U,
    WDOG_DRV_CLOCK_BUS = 0x01U,
    WDOG_DRV_CLOCK_FIRC = 0x02U,
    WDOG_DRV_CLOCK_OSC = 0x03U
} Wdog_Drv_ClkSourceType;

/**
 * @brief WDOG option mode configuration structure
 */
typedef struct
{
    boolean WaitMode;
    boolean StopMode;
    boolean DebugMode;
} Wdog_Drv_OperationModeType;

/**
 *  @brief    defines the return status of Wdog
 */
typedef enum
{
    WDOG_DRV_STATUS_SUCCESS = 0x00,
    WDOG_DRV_STATUS_ERROR = 0x01,
    WDOG_DRV_STATUS_TIMEOUT = 0x02
} Wdog_Drv_StatusType;

/**
 * @brief WDOG user configuration structure
 */
typedef struct
{
    Wdog_Drv_ClkSourceType              ClkSource;
    Wdog_Drv_OperationModeType          OpMode;
    boolean                             UpdateEnable;
    boolean                             IntEnable;
    boolean                             WindowEnable;
    uint32                              WindowValue;
    uint32                              TimeoutValue;
    Wdog_Drv_CallbackPtrType            IntCallbackPtr;
} Wdog_Drv_ConfigType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdog_Drv_Types */

/** @} end of group Wdg_Module */
