/**************************************************************************************************/
/**
 * @file      : HTMSS.h
 * @brief     : AUTOSAR HTMSS header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef HTMSS_H
#define HTMSS_H

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

#include "HTMSS_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define HTMSS_MODULE_ID                   HTMSS_CFG_H_MODULE_ID
#define HTMSS_VENDOR_ID                   0x00B3U
#define HTMSS_AR_RELEASE_MAJOR_VERSION    4U
#define HTMSS_AR_RELEASE_MINOR_VERSION    6U
#define HTMSS_AR_RELEASE_REVISION_VERSION 0U
#define HTMSS_SW_MAJOR_VERSION            1U
#define HTMSS_SW_MINOR_VERSION            1U
#define HTMSS_SW_PATCH_VERSION            0U

/* Check if current file and HTMSS_Types header file are of the same vendor */
#if (HTMSS_VENDOR_ID != HTMSS_TYPES_H_VENDOR_ID)
    #error "Vendor ID of HTMSS.h and HTMSS_Types.h are different"
#endif

/* Check if current file and HTMSS_Types header file are of the same Autosar version */
#if ((HTMSS_AR_RELEASE_MAJOR_VERSION != HTMSS_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (HTMSS_AR_RELEASE_MINOR_VERSION != HTMSS_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (HTMSS_AR_RELEASE_REVISION_VERSION != HTMSS_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of HTMSS.h and HTMSS_Types.h are different"
#endif

/* Check if current file and HTMSS_Types header file are of the same software version */
#if ((HTMSS_SW_MAJOR_VERSION != HTMSS_TYPES_H_SW_MAJOR_VERSION) ||                                 \
     (HTMSS_SW_MINOR_VERSION != HTMSS_TYPES_H_SW_MINOR_VERSION) ||                                 \
     (HTMSS_SW_PATCH_VERSION != HTMSS_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of HTMSS.h and HTMSS_Types.h are different"
#endif

/**
 * @brief Specifies the InstanceId of this module instance.
 */
#define HTMSS_INSTANCE_ID ((uint8)0x0U)

/**
 * @brief Service Ids for HTMSS APIs
 */
#define HTMSS_SID_INIT                       ((uint8)0x01U)
#define HTMSS_SID_START_TEST                 ((uint8)0x03U)
#define HTMSS_SID_GET_TEST_RESULT            ((uint8)0x04U)
#define HTMSS_SID_GET_VERSION_INFO           ((uint8)0x06U)
#define HTMSS_SID_STARTUP_TEST_ERROR_HOOK    ((uint8)0x07U)
#define HTMSS_SID_SHUTDOWNUP_TEST_ERROR_HOOK ((uint8)0x08U)

/**
 * @brief Development errors
 */
#define HTMSS_E_NOT_INIT      ((uint8)0x01U)
#define HTMSS_E_NULL_POINTER  ((uint8)0x02U)
#define HTMSS_E_PARAM_INVALID ((uint8)0x03U)
#define HTMSS_E_BUSY          ((uint8)0x04U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define HTMSS_START_SEC_CONFIG_DATA_PTR
#include "Htmss_MemMap.h"

extern const HTMSS_TestCfgType *const HTMSS_PreDefinedConfigPtr;

#define HTMSS_STOP_SEC_CONFIG_DATA_PTR
#include "Htmss_MemMap.h"

#define HTMSS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Htmss_MemMap.h"

#ifdef HTMSS_NUMBER_OF_START_UP_TESTS
/* HTMSS startup test results */
HTMSS_STARTUP_TEST_RESULT
#endif

#ifdef HTMSS_NUMBER_OF_SHUTDOWN_TESTS
/* HTMSS shutdown test results */
HTMSS_SHUTDOWN_TEST_RESULT
#endif

#define HTMSS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Htmss_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define HTMSS_START_SEC_CODE
#include "Htmss_MemMap.h"

/**
 * @brief     Initializes the HTMSS driver.
 *
 * @param[in] ConfigPtr: Pointer to configuration set in Variant PB (Variant PC requires a NULL_PTR)
 *
 * @return    None
 *
 */
void HTMSS_Init(const HTMSS_TestCfgType *ConfigPtr);

/**
 * @brief     Starts the MSTP configured tests.
 *
 * @param[in] GrpId: The test group type (e.g. start up or shut down).
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Start test command executed success.
 * @retval    E_NOT_OK: Start test command executed failed.
 *
 */
Std_ReturnType HTMSS_StartTest(HTMSS_TestGroupType GrpId);

/**
 * @brief      Returns current test status on requested test.
 *
 * @param[in]  GrpId: The test group type (e.g. start up or shut down).
 * @param[out] RequestTestResultPtr: Pointer to store the request result.
 *
 * @return     HTMSS_TestStatusType: Test status.
 * @retval     HTMSS_STATUS_OK: Test status PASS
 * @retval     HTMSS_STATUS_NOK: Test status FAIL
 * @retval     HTMSS_STATUS_INVALID: Test status is Invalid
 * @retval     HTMSS_STATUS_UNINIT: Test status is not initialized
 *
 */
HTMSS_TestStatusType HTMSS_GetTestStatus(HTMSS_TestGroupType   GrpId,
                                         HTMSS_TestResultType *RequestTestResultPtr);

#if (HTMSS_VERSION_INFO_API == STD_ON)
/**
 * @brief      Gets the version information of this module.
 *
 * @param[out] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return     None.
 *
 */
void HTMSS_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* (HTMSS_VERSION_INFO_API == STD_ON) */

/**
 * @brief     The ECU State Manager will call the error hook if the HTMSS provided startup test
 *            results have a failure.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void HTMSS_StartupTestErrorHook(void);

/**
 * @brief     The ECU State Manager will call the error hook if the HTMSS provided shutdown test
 *            results have a failure.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void HTMSS_ShutdownTestErrorHook(void);

#define HTMSS_STOP_SEC_CODE
#include "Htmss_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group HTMSS */

/** @} end of group HTMSS_Module */

#endif /* HTMSS_H */
