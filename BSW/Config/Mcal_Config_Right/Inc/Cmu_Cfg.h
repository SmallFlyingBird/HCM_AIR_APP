/**************************************************************************************************/
/**
 * @file      : Cmu_Cfg.h
 * @brief     : AUTOSAR Cmu - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu_Configuration
 *  @brief Cmu driver configuration
 *  @{
 */

#ifndef CMU_CFG_H
#define CMU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Cmu_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CMU_CFG_H_MODULE_ID                   2050U
#define CMU_CFG_H_VENDOR_ID                   0x00B3U
#define CMU_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CMU_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CMU_CFG_H_SW_MAJOR_VERSION            1U
#define CMU_CFG_H_SW_MINOR_VERSION            1U
#define CMU_CFG_H_SW_PATCH_VERSION            0U

/* Check if current file and Cmu_PBcfg header file are of the same vendor */
#if (CMU_CFG_H_VENDOR_ID != CMU_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Cmu_Cfg.h and Cmu_PBcfg.h are different"
#endif
    /* Check if current file and Cmu_PBcfg header file are of the same Autosar version */
#if ((CMU_CFG_H_AR_RELEASE_MAJOR_VERSION != CMU_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (CMU_CFG_H_AR_RELEASE_MINOR_VERSION != CMU_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (CMU_CFG_H_AR_RELEASE_REVISION_VERSION != CMU_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Cmu_Cfg.h and Cmu_PBcfg.h are different"
#endif
/* Check if current file and Cmu_PBcfg header file are of the same software version */
#if ((CMU_CFG_H_SW_MAJOR_VERSION != CMU_PBCFG_H_SW_MAJOR_VERSION) || \
     (CMU_CFG_H_SW_MINOR_VERSION != CMU_PBCFG_H_SW_MINOR_VERSION) || \
     (CMU_CFG_H_SW_PATCH_VERSION != CMU_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Cmu_Cfg.h and Cmu_PBcfg.h are different"
#endif

/**
* @brief Pre-processor switch for enabling the default error detection and reporting to the DET.
*        The detection of default errors is configurable (ON / OFF) at pre-compile time.
*/
#define CMU_DEV_ERROR_DETECT (STD_ON)

/**
* @brief Pre-processor switch to enable/disable the API to read out the modules version information.
*/
#define CMU_VERSION_INFO_API (STD_OFF)

/**
* @brief Pre-compile Support.
*/
#define CMU_PRECOMPILE_SUPPORT    (STD_OFF)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */


#define CMU_CONFIG_EXT \
    CMU_CONFIG_PB



/** @} end of group Global_VariableDeclaration */


/**
* @brief Symbolic Names for configured cmu id.
*/

#define CmuConf_CmuSettingConfig_CmuSettingConfig_BusClock                              ((Cmu_IdType)0U)

#define CmuConf_CmuSettingConfig_CmuSettingConfig_FIRC64                              ((Cmu_IdType)1U)

#define CmuConf_CmuSettingConfig_CmuSettingConfig_LPO32K                              ((Cmu_IdType)2U)




/** @defgroup Public_FunctionDeclaration
 *  @{
 */


/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CMU_CFG_H */

/** @} end of group Cmu_Configuration */

/** @} end of group Cmu_Module */
