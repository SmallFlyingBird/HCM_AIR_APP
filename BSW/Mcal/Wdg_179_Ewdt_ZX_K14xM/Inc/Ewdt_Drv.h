/**************************************************************************************************/
/**
 * @file      : Ewdt_Drv.h
 * @brief     : Wdg_179_Ewdt low level file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef EWDT_DRV_H
#define EWDT_DRV_H

/** @addtogroup  Wdg_179_Ewdt_Module
 *  @{
 */

/** @addtogroup Ewdt_Drv
 *  @brief Wdg_179_Ewdt hardware access of low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Ewdt_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define EWDT_DRV_H_VENDOR_ID                   0x00B3U
#define EWDT_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define EWDT_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define EWDT_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define EWDT_DRV_H_SW_MAJOR_VERSION            1U
#define EWDT_DRV_H_SW_MINOR_VERSION            2U
#define EWDT_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Ewdt_Drv_Types.h are of the same vendor */
#if (EWDT_DRV_H_VENDOR_ID != EWDT_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Ewdt_Drv.h and Ewdt_Drv_Types.h are different"
#endif
/* Check if current file file and Ewdt_Drv_Types.h file are of the same Autosar version */
#if ((EWDT_DRV_H_AR_RELEASE_MAJOR_VERSION != EWDT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||       \
        (EWDT_DRV_H_AR_RELEASE_MINOR_VERSION != EWDT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||       \
        (EWDT_DRV_H_AR_RELEASE_REVISION_VERSION != EWDT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ewdt_Drv.h and Ewdt_Drv_Types.h are different"
#endif
#if ((EWDT_DRV_H_SW_MAJOR_VERSION != EWDT_DRV_TYPES_H_SW_MAJOR_VERSION) ||                       \
        (EWDT_DRV_H_SW_MINOR_VERSION != EWDT_DRV_TYPES_H_SW_MINOR_VERSION) ||                       \
        (EWDT_DRV_H_SW_PATCH_VERSION != EWDT_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Ewdt_Drv.h and Ewdt_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define WDG_179_EWDT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_179_Ewdt_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
EWDT_DRV_CONFIG_EXT

#define WDG_179_EWDT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_179_Ewdt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_START_SEC_CODE
#else
#define WDG_179_EWDT_START_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

/**
 * @brief Ewdt initialization.
 *
 * @param[in] ConfigPtr Ewdt_Drv_ConfigType pointer.
 * 
 * @return the Status of the Ewdt:
 * @retval EWDT_DRV_STATUS_SUCCESS
 * @retval EWDT_DRV_STATUS_ERROR
 */
Ewdt_Drv_StatusType Ewdt_Drv_Init(const Ewdt_Drv_ConfigType * const ConfigPtr);

/**
 * @brief Refresh the Ewdt
 *
 * @param[in] CbBeforeRefresh: call back function before refresh
 * @param[in] CbAfterRefresh: call back function after refresh
 * 
 * @return   None
 */
void Ewdt_Drv_Refresh(Ewdt_Drv_CallbackPtrType CbBeforeRefresh,
                      Ewdt_Drv_CallbackPtrType CbAfterRefresh);

/**
* @brief    This function handles the EWDT interrupt request.
*
* @param[in] None
* 
* @return   None     
*/
void Ewdt_Drv_IntHandler(void);

#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_STOP_SEC_CODE
#else
#define WDG_179_EWDT_STOP_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

/** @} end of Public_FunctionDeclaration */
#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Ewdt_Drv */

/** @} end of group Wdg_179_Ewdt_Module */
