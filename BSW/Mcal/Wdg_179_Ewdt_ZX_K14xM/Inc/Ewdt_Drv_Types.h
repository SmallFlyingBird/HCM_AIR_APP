/**************************************************************************************************/
/**
 * @file      : Ewdt_Drv_Types.h
 * @brief     : Wdg_179_Ewdt low level types header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef EWDT_DRV_TYPES_H
#define EWDT_DRV_TYPES_H

/** @addtogroup  Wdg_179_Ewdt_Module
 *  @{
 */

/** @addtogroup Ewdt_Drv_Types
 *  @brief Ewdt low level types
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Ewdt_Drv_Cfg.h"
#include "McalLib.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define EWDT_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define EWDT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define EWDT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define EWDT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define EWDT_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define EWDT_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define EWDT_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Ewdt_Drv_Cfg.h are of the same vendor */
#if (EWDT_DRV_TYPES_H_VENDOR_ID != EWDT_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Ewdt_Drv_Types.h and Ewdt_Drv_Cfg.h are different"
#endif
/* Check if current file file and Ewdt_Drv_Cfg.h file are of the same Autosar version */
#if ((EWDT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != EWDT_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (EWDT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != EWDT_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
        (EWDT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                           \
        EWDT_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ewdt_Drv_Types.h and Ewdt_Drv_Cfg.h are different"
#endif
/* Check if current file and Ewdt_Drv_Cfg.h are of the same software version */
#if ((EWDT_DRV_TYPES_H_SW_MAJOR_VERSION != EWDT_DRV_CFG_H_SW_MAJOR_VERSION) ||                 \
        (EWDT_DRV_TYPES_H_SW_MINOR_VERSION != EWDT_DRV_CFG_H_SW_MINOR_VERSION) ||                 \
        (EWDT_DRV_TYPES_H_SW_PATCH_VERSION != EWDT_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Ewdt_Drv_Types.h and Ewdt_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file file and McalLib.h file are of the same Autosar version */
    #if ((EWDT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (EWDT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Ewdt_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief EWDT callback type
 */
typedef void (*Ewdt_Drv_CallbackPtrType)(void);

/**
 * @brief EWDT option mode configuration structure
 */
typedef struct
{
    boolean WaitMode;
    boolean DebugMode;
} Ewdt_Drv_OperationModeType;

/**
 *  @brief    defines the return status of EWDT
 */
typedef enum
{
    EWDT_DRV_STATUS_SUCCESS = 0x00,
    EWDT_DRV_STATUS_ERROR = 0x01,
} Ewdt_Drv_StatusType;

/**
 * @brief EWDT user configuration structure
 */
typedef struct
{
    Ewdt_Drv_OperationModeType          OpMode;
    boolean                             EwdtEnable;
    boolean                             IntEnable;
    boolean                             INPortEnable;
    boolean                             IsInPortHighActive;
    uint32                              WindowValue;
    uint32                              TimeoutValue;
    Ewdt_Drv_CallbackPtrType            IntCallbackPtr;
} Ewdt_Drv_ConfigType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Ewdt_Drv_Types */

/** @} end of group Wdg_179_Ewdt_Module */
