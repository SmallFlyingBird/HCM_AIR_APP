/**************************************************************************************************/
/**
 * @file      : Meh_PBcfg.c
 * @brief     : Meh Extended MicroController Error Handle configuration source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Meh_Module
 *  @{
 */

/** @addtogroup Meh configuration
 *  @brief Meh configuration source file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Meh.h"
#include "Eiru_Drv.h"
#include "Seru_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MEH_PBCFG_C_VENDOR_ID                   0x00B3U
#define MEH_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define MEH_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define MEH_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define MEH_PBCFG_C_SW_MAJOR_VERSION            1U
#define MEH_PBCFG_C_SW_MINOR_VERSION            1U
#define MEH_PBCFG_C_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Meh.h are of the same vendor
 */
#if (MEH_PBCFG_C_VENDOR_ID != MEH_VENDOR_ID)
    #error "Vendor ID of Meh_PBcfg.c and Meh.h are different"
#endif

/**
 *  @brief Check if current file and Meh.h are of the same Autosar version
 */
#if ((MEH_PBCFG_C_AR_RELEASE_MAJOR_VERSION != MEH_AR_RELEASE_MAJOR_VERSION) ||                 \
     (MEH_PBCFG_C_AR_RELEASE_MINOR_VERSION != MEH_AR_RELEASE_MINOR_VERSION) ||                 \
     (MEH_PBCFG_C_AR_RELEASE_REVISION_VERSION != MEH_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh_PBcfg.c and Meh.h are different"
#endif

/**
 *  @brief Check if current file and Meh.h are of the same SW version
 */
#if ((MEH_PBCFG_C_SW_MAJOR_VERSION != MEH_SW_MAJOR_VERSION) ||                                 \
     (MEH_PBCFG_C_SW_MINOR_VERSION != MEH_SW_MINOR_VERSION) ||                                 \
     (MEH_PBCFG_C_SW_PATCH_VERSION != MEH_SW_PATCH_VERSION))
    #error "Software Version of Meh_PBcfg.c and Meh.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv.h are of the same vendor
 */
#if (MEH_PBCFG_C_VENDOR_ID != EIRU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Meh_PBcfg.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv.h are of the same Autosar version
 */
#if ((MEH_PBCFG_C_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (MEH_PBCFG_C_AR_RELEASE_MINOR_VERSION != EIRU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (MEH_PBCFG_C_AR_RELEASE_REVISION_VERSION != EIRU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh_PBcfg.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv.h are of the same SW version
 */
#if ((MEH_PBCFG_C_SW_MAJOR_VERSION != EIRU_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (MEH_PBCFG_C_SW_MINOR_VERSION != EIRU_DRV_H_SW_MINOR_VERSION) ||                                 \
     (MEH_PBCFG_C_SW_PATCH_VERSION != EIRU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Meh_PBcfg.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same vendor
 */
#if (MEH_PBCFG_C_VENDOR_ID != SERU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Meh_PBcfg.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same Autosar version
 */
#if ((MEH_PBCFG_C_AR_RELEASE_MAJOR_VERSION != SERU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (MEH_PBCFG_C_AR_RELEASE_MINOR_VERSION != SERU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (MEH_PBCFG_C_AR_RELEASE_REVISION_VERSION != SERU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh_PBcfg.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same SW version
 */
#if ((MEH_PBCFG_C_SW_MAJOR_VERSION != SERU_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (MEH_PBCFG_C_SW_MINOR_VERSION != SERU_DRV_H_SW_MINOR_VERSION) ||                                 \
     (MEH_PBCFG_C_SW_PATCH_VERSION != SERU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Meh_PBcfg.c and Seru_Drv.h are different"
#endif

/** @} end of group Public_MacroDefinition */
#define MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"
/** @defgroup Global_VariableDefinition
 *  @{
 */

/**
* @brief Meh configuration.
*
*/
static const Meh_ConfigType Meh_Config = {
    &Eiru_Drv_Config,
    &Seru_Drv_Config
};

#define MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"

#define MEH_START_SEC_CONFIG_DATA_PTR
#include "Meh_MemMap.h"
/**
* @brief Meh configuration data for Meh_PreDefinedConfigPtr.
*
*/
const Meh_ConfigType * const Meh_PreDefinedConfigPtr = &Meh_Config;
#define MEH_STOP_SEC_CONFIG_DATA_PTR
#include "Meh_MemMap.h"
/** @} end of group Global_VariableDefinition */
#ifdef __cplusplus
}
#endif

/** @} end of group Meh configuration */

/** @} end of group Meh_Module */
