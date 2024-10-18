/**************************************************************************************************/
/**
 * @file      : HTMSS_Types.h
 * @brief     : AUTOSAR HTMSS header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef HTMSS_TYPES_H
#define HTMSS_TYPES_H

/** @addtogroup HTMSS_Module
 *  @{
 */

/** @addtogroup HTMSS
 *  @brief HTMSS high level interface
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "HTMSS_Cfg.h"
#include "Std_Types.h"
#include "Mstp.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define HTMSS_TYPES_H_VENDOR_ID                   0x00B3U
#define HTMSS_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define HTMSS_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define HTMSS_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define HTMSS_TYPES_H_SW_MAJOR_VERSION            1U
#define HTMSS_TYPES_H_SW_MINOR_VERSION            1U
#define HTMSS_TYPES_H_SW_PATCH_VERSION            0U

/* Check if current file and HTMSS_Cfg header file are of the same vendor */
#if (HTMSS_TYPES_H_VENDOR_ID != HTMSS_CFG_H_VENDOR_ID)
    #error "Vendor ID of HTMSS_Types.h and HTMSS_Cfg.h are different"
#endif

/* Check if current file and HTMSS_Cfg header file are of the same Autosar version */
#if ((HTMSS_TYPES_H_AR_RELEASE_MAJOR_VERSION != HTMSS_CFG_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (HTMSS_TYPES_H_AR_RELEASE_MINOR_VERSION != HTMSS_CFG_H_AR_RELEASE_MINOR_VERSION) ||           \
     (HTMSS_TYPES_H_AR_RELEASE_REVISION_VERSION != HTMSS_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of HTMSS_Types.h and HTMSS_Cfg.h are different"
#endif

/* Check if current file and HTMSS_Cfg header file are of the same software version */
#if ((HTMSS_TYPES_H_SW_MAJOR_VERSION != HTMSS_CFG_H_SW_MAJOR_VERSION) ||                           \
     (HTMSS_TYPES_H_SW_MINOR_VERSION != HTMSS_CFG_H_SW_MINOR_VERSION) ||                           \
     (HTMSS_TYPES_H_SW_PATCH_VERSION != HTMSS_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of HTMSS_Types.h and HTMSS_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types header file are of the same Autosar version */
    #if ((HTMSS_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||               \
         (HTMSS_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of HTMSS_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and Mstp header file are of the same Autosar version */
    #if ((HTMSS_TYPES_H_AR_RELEASE_MAJOR_VERSION != MSTP_AR_RELEASE_MAJOR_VERSION) ||              \
         (HTMSS_TYPES_H_AR_RELEASE_MINOR_VERSION != MSTP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of HTMSS_Types.h and Mstp.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of the test group
 */
typedef enum
{
    HTMSS_STARTUP,         /*!< Test to be executed at startup only */
    HTMSS_SHUTDOWN,        /*!< Test to be executed at shutdown only */
    HTMSS_STARTUP_SHUTDOWN /*!< Test to be executed at startup and shutdown */
} HTMSS_TestGroupType;

/**
 *  @brief Type of the status of the test
 */
typedef enum
{
    HTMSS_STATUS_OK,      /*!< Test status PASS */
    HTMSS_STATUS_NOK,     /*!< Test status FAIL */
    HTMSS_STATUS_INVALID, /*!< Test status is Invalid */
    HTMSS_STATUS_UNINIT   /*!< Test status is not initialized */
} HTMSS_TestStatusType;

/* Pointer to module configuration function */
typedef void (*HTMSS_ModuleConfigFuncPtrType)(void);

/* Pointer to self test function */
typedef void (*HTMSS_ModuleTestFuncPtrType)(void);

/* Pointer to self test function */
typedef Mstp_SelfTestResultType (*HTMSS_GetTestResultFuncPtrType)(void);

/**
 *  @brief Configuration data structure of module self-test
 */
typedef struct
{
    /*!< Identifies the tested resource */
    Mstp_SelfTestModuleIdType TestId;
    /*!< Pointer to module configuration function */
    HTMSS_ModuleConfigFuncPtrType ConfigFuncPtr;
    /*!< Pointer to module self-test function */
    HTMSS_ModuleTestFuncPtrType SelfTestFuncPtr;
    /*!< Pointer to get test result function */
    HTMSS_GetTestResultFuncPtrType GetTestResultFuncPtr;
} HTMSS_TestModuleConfigType;

/**
 *  @brief Configuration data structure of HTMSS module
 */
typedef struct
{
    /*!< Start up test group */
    const HTMSS_TestModuleConfigType *StartUpTestGrpPtr;
    /*!< Shut down test group */
    const HTMSS_TestModuleConfigType *ShutDownTestGrpPtr;
    /* Number of tests to be executed at startup */
    uint8 NumberOfStartUpTests;
    /*!< Number of tests to be executed at shutdown */
    uint8 NumberOfShutDownTests;
} HTMSS_TestCfgType;

/**
 * @brief Type of the current test result
 */
typedef struct
{
    uint8 TestResult;    /*!< Self-test error code */
    uint8 TestSignature; /*!< Test id, identifier of the tested resource */
} HTMSS_TestResultType;

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

/** @} end of group HTMSS */

/** @} end of group HTMSS_Module */

#endif /* HTMSS_TYPES_H */
