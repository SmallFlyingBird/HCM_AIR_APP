/**************************************************************************************************/
/**
 * @file      : Fls_Drvw_Cfg.h  
 * @brief     : Fls driver wrapper - Pre-Compile(PC) configuration file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLS_DRVW_CFG_H
#define FLS_DRVW_CFG_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls_Drvw_Cfg
 *  @brief Fls driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define FLS_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define FLS_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define FLS_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define FLS_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define FLS_DRVW_CFG_H_SW_PATCH_VERSION            2U

#define FLS_DRVW_AC_LOAD_ON_JOB_START             (STD_ON)
#define FLS_DRVW_CANCEL_API                       (STD_ON)
#define FLS_DRVW_COMPARE_API                      (STD_ON)
#define FLS_DRVW_BLANK_CHECK_API                  (STD_OFF)

#define FLS_DRVW_ERASE_VERIFICATION_ENABLED       (STD_ON)
#define FLS_DRVW_WRITE_VERIFICATION_ENABLED       (STD_ON)

#define FLS_DRVW_CONFIG_EXT \
        extern const Fls_Drvw_ConfigType Fls_DrvwConfig;
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
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Fls_Drvw_Cfg */

/** @} end of group Fls_Module */

#endif 

