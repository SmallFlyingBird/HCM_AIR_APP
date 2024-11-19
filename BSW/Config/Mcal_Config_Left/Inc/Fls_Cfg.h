/**************************************************************************************************/
/**
 * @file      : Fls_Cfg.h  
 * @brief     : Fls configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLS_CFG_H
#define FLS_CFG_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls_Cfg
 *  @brief Fls AUTOSAR level configuration 
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Fls_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_CFG_H_VENDOR_ID                   0x00B3U
#define FLS_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define FLS_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define FLS_CFG_H_SW_MAJOR_VERSION            1U
#define FLS_CFG_H_SW_MINOR_VERSION            2U
#define FLS_CFG_H_SW_PATCH_VERSION            2U


/* Check if current file and Fls_PBcfg.h are the same vendor */
#if (FLS_CFG_H_VENDOR_ID != FLS_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Fls_Cfg.h and Fls_PBcfg.h are different"
#endif
/* Check if current file and Fls_PBcfg.h are the same Autosar version */
#if((FLS_CFG_H_AR_RELEASE_MAJOR_VERSION != FLS_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
    (FLS_CFG_H_AR_RELEASE_MINOR_VERSION != FLS_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
    (FLS_CFG_H_AR_RELEASE_REVISION_VERSION != FLS_PBCFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_Cfg.h and Fls_PBcfg.h are different"
#endif
/* Check if current file and Fls_PBcfg.h are the same software version */
#if((FLS_CFG_H_SW_MAJOR_VERSION != FLS_PBCFG_H_SW_MAJOR_VERSION) || \
    (FLS_CFG_H_SW_MINOR_VERSION != FLS_PBCFG_H_SW_MINOR_VERSION) || \
    (FLS_CFG_H_SW_PATCH_VERSION != FLS_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Cfg.h and Fls_PBcfg.h are different"
#endif

#define FlsConf_FlsGeneral_FlsDriverIndex    (0U)
#define FLS_INSTANCE                         (0U)
#define FLS_DEV_ERROR_DETECT                 (STD_ON)

#define FLS_CANCEL_API                       (STD_ON)
#define FLS_COMPARE_API                      (STD_ON)
#define FLS_BLANK_CHECK_API                  (STD_OFF)
#define FLS_GET_JOB_RESULT_API               (STD_ON)
#define FLS_GET_STATUS_API                   (STD_ON)
#define FLS_SET_MODE_API                     (STD_ON)
#define FLS_VERSION_INFO_API                 (STD_OFF)

#define FLS_PRECOMPILE_SUPPORT               (STD_ON)
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *	@{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Fls_Cfg */

/** @} end of group Fls_Module */

#endif /* FLS_CFG_H */
