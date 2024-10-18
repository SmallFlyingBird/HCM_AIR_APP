/**************************************************************************************************/
/**
 * @file      : HTMSS_Cfg.c 
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
 *  @brief HTMSS driver configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"
{
#endif

#include "HTMSS.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define HTMSS_CFG_C_VENDOR_ID                   0x00B3U
#define HTMSS_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define HTMSS_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define HTMSS_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define HTMSS_CFG_C_SW_MAJOR_VERSION            1U
#define HTMSS_CFG_C_SW_MINOR_VERSION            1U
#define HTMSS_CFG_C_SW_PATCH_VERSION            0U

/* Check if current file and HTMSS.h file are of the same vendor */
#if (HTMSS_CFG_C_VENDOR_ID != HTMSS_VENDOR_ID)
    #error "Vendor ID of HTMSS_Cfg.c and HTMSS.h are different"
#endif

/* Check if current file and HTMSS.h are of the same Autosar version */
#if ((HTMSS_CFG_C_AR_RELEASE_MAJOR_VERSION    != HTMSS_AR_RELEASE_MAJOR_VERSION) || \
     (HTMSS_CFG_C_AR_RELEASE_MINOR_VERSION    != HTMSS_AR_RELEASE_MINOR_VERSION) || \
     (HTMSS_CFG_C_AR_RELEASE_REVISION_VERSION != HTMSS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of HTMSS_Cfg.c and HTMSS.h are different"
#endif

/* Check if current file and HTMSS.h are of the same Software version */
#if ((HTMSS_CFG_C_SW_MAJOR_VERSION != HTMSS_SW_MAJOR_VERSION) || \
     (HTMSS_CFG_C_SW_MINOR_VERSION != HTMSS_SW_MINOR_VERSION) || \
     (HTMSS_CFG_C_SW_PATCH_VERSION != HTMSS_SW_PATCH_VERSION) )
    #error "Software Version of HTMSS_Cfg.c and HTMSS.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define HTMSS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "HTMSS_MemMap.h"

#ifdef HTMSS_NUMBER_OF_START_UP_TESTS
/* HTMSS startup test results */
HTMSS_TestResultType HTMSS_StartUpTestResult[HTMSS_NUMBER_OF_START_UP_TESTS];
#endif

#ifdef HTMSS_NUMBER_OF_SHUTDOWN_TESTS
/* HTMSS shutdown test results */
HTMSS_TestResultType HTMSS_ShutDownTestResult[HTMSS_NUMBER_OF_SHUTDOWN_TESTS];
#endif

#define HTMSS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "HTMSS_MemMap.h"

#define HTMSS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Htmss_MemMap.h"


static const HTMSS_TestModuleConfigType HTMSS_StartUpTestGrp[] = 
{
    {
        MSTP_SELFTEST_CRC, /* Test Id */
        NULL_PTR, /* Pointer to module configuration function */
        Mstp_CrcSelfTest, /* Pointer to module self-test function */
        Mstp_GetCrcSelfTestResult /* Pointer to get test result function */
    },
    {
        MSTP_SELFTEST_CMU, /* Test Id */
        NULL_PTR, /* Pointer to module configuration function */
        Mstp_CmuSelfTest, /* Pointer to module self-test function */
        Mstp_GetCmuSelfTestResult /* Pointer to get test result function */
    },
    {
        MSTP_SELFTEST_SERU, /* Test Id */
        NULL_PTR, /* Pointer to module configuration function */
        Mstp_SeruSelfTest, /* Pointer to module self-test function */
        Mstp_GetSeruSelfTestResult /* Pointer to get test result function */
    },
    {
        MSTP_SELFTEST_PARCC, /* Test Id */
        NULL_PTR, /* Pointer to module configuration function */
        Mstp_ParccSelfTest, /* Pointer to module self-test function */
        Mstp_GetParccSelfTestResult /* Pointer to get test result function */
    },
    {
        MSTP_SELFTEST_SRAMECC, /* Test Id */
        NULL_PTR, /* Pointer to module configuration function */
        Mstp_SramEccSelfTest, /* Pointer to module self-test function */
        Mstp_GetSramEccSelfTestResult /* Pointer to get test result function */
    },
    {
        MSTP_SELFTEST_FLASHECC, /* Test Id */
        NULL_PTR, /* Pointer to module configuration function */
        Mstp_FlashEccSelfTest, /* Pointer to module self-test function */
        Mstp_GetFlashEccSelfTestResult /* Pointer to get test result function */
    }
};


static const HTMSS_TestModuleConfigType HTMSS_ShutDownTestGrp[] = 
{
    {
        MSTP_SELFTEST_CRC, /* Test Id */
        NULL_PTR, /* Pointer to module configuration function */
        Mstp_CrcSelfTest, /* Pointer to module self-test function */
        Mstp_GetCrcSelfTestResult /* Pointer to get test result function */
    }
};


/**
* @brief   Initialization data for the HTMSS driver.
* @details A pointer to such a structure is provided to the HTMSS initialization routines for configuration.
*
*/
static const HTMSS_TestCfgType HTMSS_Config =
{
    /*!< Start up test group*/
    HTMSS_StartUpTestGrp,    
    /*!< Shut down test group */
    HTMSS_ShutDownTestGrp,    
    /* Number of test to be executed at startup */
    6U,
    /* Number of tests to be executed at shutdown */
    1U
};

#define HTMSS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Htmss_MemMap.h"

#define HTMSS_START_SEC_CONFIG_DATA_PTR
#include "Htmss_MemMap.h"

/**
* @brief HTMSS configuration data for HTMSS_PreDefinedConfigPtr.
*
*/
const HTMSS_TestCfgType * const HTMSS_PreDefinedConfigPtr = &HTMSS_Config;

#define HTMSS_STOP_SEC_CONFIG_DATA_PTR
#include "Htmss_MemMap.h"


/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group HTMSS_Configuration */

/** @} end of group HTMSS_Module */
