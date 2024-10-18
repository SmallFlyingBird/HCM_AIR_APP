/**************************************************************************************************/
/**
 * @file      : Wdog_Drv.h
 * @brief     : Wdg low level file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDOG_DRV_H
#define WDOG_DRV_H

/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdog_Drv
 *  @brief Wdg hardware access of low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdog_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDOG_DRV_H_VENDOR_ID                   0x00B3U
#define WDOG_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDOG_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define WDOG_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define WDOG_DRV_H_SW_MAJOR_VERSION            1U
#define WDOG_DRV_H_SW_MINOR_VERSION            2U
#define WDOG_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Wdog_Drv_Types.h are of the same vendor */
#if (WDOG_DRV_H_VENDOR_ID != WDG_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Wdog_Drv.h and Wdog_Drv_Types.h are different"
#endif
/* Check if current file file and Wdog_Drv_Types.h file are of the same Autosar version */
#if ((WDOG_DRV_H_AR_RELEASE_MAJOR_VERSION != WDG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||       \
        (WDOG_DRV_H_AR_RELEASE_MINOR_VERSION != WDG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||       \
        (WDOG_DRV_H_AR_RELEASE_REVISION_VERSION != WDG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Wdog_Drv.h and Wdog_Drv_Types.h are different"
#endif
#if ((WDOG_DRV_H_SW_MAJOR_VERSION != WDG_DRV_TYPES_H_SW_MAJOR_VERSION) ||                       \
        (WDOG_DRV_H_SW_MINOR_VERSION != WDG_DRV_TYPES_H_SW_MINOR_VERSION) ||                       \
        (WDOG_DRV_H_SW_PATCH_VERSION != WDG_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Wdog_Drv.h and Wdog_Drv_Types.h are different"
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
WDOG_DRV_CONFIG_EXT

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#if (WDG_DRV_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/**
 * @brief Wdog initialization.
 *
 * @param[in] ConfigPtr Wdog_Drv_ConfigType pointer.
 * 
 * @return the status of the wdog:
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_ERROR 
 * @retval WDOG_DRV_STATUS_TIMEOUT
 * 
 */
Wdog_Drv_StatusType Wdog_Drv_Init(const Wdog_Drv_ConfigType * const ConfigPtr);

#if (WDOG_DRV_DISABLE_ALLOWED == STD_ON)
/**
 * @brief Wdog de-initialization. It resets the register values and disable the WDOG
 *
 * @param[in] None
 * 
 * @return the deinit status of the wdog
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_ERROR 
 * @retval WDOG_DRV_STATUS_TIMEOUT
 * 
 */
Wdog_Drv_StatusType Wdog_Drv_DeInit(void);
#endif

/**
 * @brief Refresh the Wdog
 *
 * @param[in] CbBeforeRefresh: call back function before refresh
 * @param[in] CbAfterRefresh: call back function after refresh
 * 
 * @return   None
 */
void Wdog_Drv_Refresh(Wdog_Drv_CallbackPtrType CbBeforeRefresh,
                      Wdog_Drv_CallbackPtrType CbAfterRefresh);

/**
 * @brief Set WDOG timeout value.
 *
 * @param[in] WindowValue wdog window value.
 * @param[in] Timeout wdog timeout value
 * 
 * @return the status of the wdog:
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_ERROR 
 * @retval WDOG_DRV_STATUS_TIMEOUT
 * 
 */
Wdog_Drv_StatusType Wdog_Drv_SetTimeout(uint32 Timeout, uint32 WindowValue);

/**
* @brief    This function handles the WDOG interrupt request.
*
* @param[in] None
* 
* @return   None     
*/
void Wdog_Drv_IntHandler(void);

#if (WDG_DRV_RUN_IN_ROM == 1U)
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

/** @} end of group Wdog_Drv */

/** @} end of group Wdg_Module */
