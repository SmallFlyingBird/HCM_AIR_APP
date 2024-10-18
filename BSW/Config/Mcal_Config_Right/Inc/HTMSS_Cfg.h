/**************************************************************************************************/
/**
 * @file      : HTMSS_Cfg.h
 * @brief     : AUTOSAR HTMSS - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup HTMSS_Module
 *  @{
 */

/** @addtogroup HTMSS_Configuration
 *  @brief HTMSS configuration
 *  @{
 */

#ifndef HTMSS_CFG_H
#define HTMSS_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define HTMSS_CFG_H_MODULE_ID                   2051U
#define HTMSS_CFG_H_VENDOR_ID                   0x00B3U
#define HTMSS_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define HTMSS_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define HTMSS_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define HTMSS_CFG_H_SW_MAJOR_VERSION            1U
#define HTMSS_CFG_H_SW_MINOR_VERSION            1U
#define HTMSS_CFG_H_SW_PATCH_VERSION            0U

/* Number of test to be executed at startup */
    #define HTMSS_NUMBER_OF_START_UP_TESTS  ((uint8)6U)
    
/* Number of test to be executed at shutdown */
    #define HTMSS_NUMBER_OF_SHUTDOWN_TESTS  ((uint8)1U)
    
/**
* @brief Pre-processor switch for enabling the default error detection and reporting to the DET.
*        The detection of default errors is configurable (ON / OFF) at pre-compile time.
*/
#define HTMSS_DEV_ERROR_DETECT (STD_OFF)

/**
* @brief Pre-processor switch to enable/disable the API to read out the modules version information.
*/
#define HTMSS_VERSION_INFO_API (STD_OFF)

/**
* @brief Enable/Disable HTMSS startup test error callout function support
*/
#define HTMSS_STARTUP_TEST_ERROR_CALLOUT_SUPPORT (STD_OFF)


/**
* @brief Define HTMSS startup test error callout function
*/
#define HTMSS_STARTUP_TEST_ERROR_CALLOUT_FUNC 
   

/**
* @brief Enable/Disable HTMSS shutdown test error callout function support
*/
#define HTMSS_SHUTDOWN_TEST_ERROR_CALLOUT_SUPPORT (STD_OFF)


/**
* @brief Define HTMSS shutdown test error callout function
*/
#define HTMSS_SHUTDOWN_TEST_ERROR_CALLOUT_FUNC 
   

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define HTMSS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "HTMSS_MemMap.h"

#ifdef HTMSS_NUMBER_OF_START_UP_TESTS
/* HTMSS startup test results */
#define HTMSS_STARTUP_TEST_RESULT \
    extern HTMSS_TestResultType HTMSS_StartUpTestResult[HTMSS_NUMBER_OF_START_UP_TESTS];
#endif

#ifdef HTMSS_NUMBER_OF_SHUTDOWN_TESTS
/* HTMSS shutdown test results */
#define HTMSS_SHUTDOWN_TEST_RESULT \
    extern HTMSS_TestResultType HTMSS_ShutDownTestResult[HTMSS_NUMBER_OF_SHUTDOWN_TESTS];
#endif

#define HTMSS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "HTMSS_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */



/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef HTMSS_CFG_H */

/** @} end of group HTMSS_Configuration */

/** @} end of group HTMSS_Module */
