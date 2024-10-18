/**************************************************************************************************/
/**
 * @file      : HTMSS.c
 * @brief     : AUTOSAR HTMSS driver source file
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

/** @addtogroup HTMSS
 *  @brief HTMSS high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "HTMSS.h"
#include "Mstp.h"
#include "Mcu.h"

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* (HTMSS_DEV_ERROR_DETECT == STD_ON) */

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define HTMSS_C_VENDOR_ID                   0x00B3U
#define HTMSS_C_AR_RELEASE_MAJOR_VERSION    4U
#define HTMSS_C_AR_RELEASE_MINOR_VERSION    6U
#define HTMSS_C_AR_RELEASE_REVISION_VERSION 0U
#define HTMSS_C_SW_MAJOR_VERSION            1U
#define HTMSS_C_SW_MINOR_VERSION            1U
#define HTMSS_C_SW_PATCH_VERSION            0U

/* Check if current file and HTMSS header file are of the same vendor */
#if (HTMSS_C_VENDOR_ID != HTMSS_VENDOR_ID)
    #error "Vendor ID of HTMSS.c and HTMSS.h are different"
#endif

/* Check if current file and HTMSS header file are of the same Autosar version */
#if ((HTMSS_C_AR_RELEASE_MAJOR_VERSION != HTMSS_AR_RELEASE_MAJOR_VERSION) ||                       \
     (HTMSS_C_AR_RELEASE_MINOR_VERSION != HTMSS_AR_RELEASE_MINOR_VERSION) ||                       \
     (HTMSS_C_AR_RELEASE_REVISION_VERSION != HTMSS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of HTMSS.c and HTMSS.h are different"
#endif

/* Check if current file and HTMSS header file are of the same Software version */
#if ((HTMSS_C_SW_MAJOR_VERSION != HTMSS_SW_MAJOR_VERSION) ||                                       \
     (HTMSS_C_SW_MINOR_VERSION != HTMSS_SW_MINOR_VERSION) ||                                       \
     (HTMSS_C_SW_PATCH_VERSION != HTMSS_SW_PATCH_VERSION))
    #error "Software Version of HTMSS.c and HTMSS.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (HTMSS_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Det header file are of the same Autosar version */
        #if ((HTMSS_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                 \
             (HTMSS_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of HTMSS.c and Det.h are different"
        #endif
    #endif /* (HTMSS_DEV_ERROR_DETECT == STD_ON) */

    /* Check if current file and Mstp header file are of the same Autosar version */
    #if ((HTMSS_C_AR_RELEASE_MAJOR_VERSION != MSTP_AR_RELEASE_MAJOR_VERSION) ||                    \
         (HTMSS_C_AR_RELEASE_MINOR_VERSION != MSTP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of HTMSS.c and Mstp.h are different"
    #endif

    /* Check if current file and Mcu header file are of the same Autosar version */
    #if ((HTMSS_C_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) ||                     \
         (HTMSS_C_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of HTMSS.c and Mcu.h are different"
    #endif

#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define HTMSS_PARAM_UNUSED(param) ((void)((param)))

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/**
 *  @brief Type definition of HTMSS states
 */
typedef enum
{
    /*!< HTMSS module uninitialized. */
    HTMSS_UINIT = 0x01,
    /*!< HTMSS module initialized. */
    HTMSS_INIT,
    /*!< The HTMSS requested tests are progressing/initiated/not completed/. */
    HTMSS_BUSY,
    /*!< The HTMSS requested tests are completed/NO pending tests are running. */
    HTMSS_IDLE
} HTMSS_StateType;

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#if (HTMSS_DEV_ERROR_DETECT == STD_ON)

#define HTMSS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Htmss_MemMap.h"

/**
 *  @brief Variable that indicates the state of the HTMSS.
 */
static HTMSS_StateType HTMSS_State = HTMSS_UINIT;

#define HTMSS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Htmss_MemMap.h"

#endif

#define HTMSS_START_SEC_VAR_INIT_PTR
#include "Htmss_MemMap.h"

/**
 * @brief Local copy of the pointer store the configuration data
 */
static const HTMSS_TestCfgType *HTMSS_ConfigPtr = NULL_PTR;

#define HTMSS_STOP_SEC_VAR_INIT_PTR
#include "Htmss_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#define HTMSS_START_SEC_CODE
#include "Htmss_MemMap.h"

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks input parameter of HTMSS init service.
 *
 * @param[in]  ConfigPtr: Pointer to the HTMSS configuration.
 *
 * @return     boolean
 * @retval     TRUE: ConfigPtr is NULL_PTR.
 * @retval     FALSE: ConfigPtr is not NULL_PTR.
 */
static boolean HTMSS_CheckInit(const HTMSS_TestCfgType *ConfigPtr)
{
    boolean CheckResult = TRUE;

    if (NULL_PTR != ConfigPtr)
    {
        CheckResult = FALSE;
        (void)Det_ReportError((uint16)HTMSS_MODULE_ID, HTMSS_INSTANCE_ID, HTMSS_SID_INIT,
                              HTMSS_E_NULL_POINTER);
    }

    return CheckResult;
}

/**
 * @brief      Checks to execute start test service.
 *
 * @param[in]  GrpId: The test group type(e.g. start up or shut down).
 *
 * @return     boolean
 * @retval     TRUE: Start test service is ready to execute.
 * @retval     FALSE: Start test service is not ready to execute.
 *
 */
static boolean HTMSS_CheckStartTest(HTMSS_TestGroupType GrpId)
{
    boolean CheckResult = TRUE;

    if (HTMSS_UINIT == HTMSS_State)
    {
        (void)Det_ReportError((uint16)HTMSS_MODULE_ID, HTMSS_INSTANCE_ID,
                              (uint8)HTMSS_SID_START_TEST, HTMSS_E_NOT_INIT);
        CheckResult = FALSE;
    }
    else if (HTMSS_BUSY == HTMSS_State)
    {
        (void)Det_ReportError((uint16)HTMSS_MODULE_ID, HTMSS_INSTANCE_ID,
                              (uint8)HTMSS_SID_START_TEST, HTMSS_E_BUSY);
        CheckResult = FALSE;
    }
    else
    {
        if ((HTMSS_STARTUP != GrpId) && (HTMSS_SHUTDOWN != GrpId))
        {
            (void)Det_ReportError((uint16)HTMSS_MODULE_ID, HTMSS_INSTANCE_ID,
                                  (uint8)HTMSS_SID_START_TEST, HTMSS_E_PARAM_INVALID);
            CheckResult = FALSE;
        }
    }

    return CheckResult;
}

/**
 * @brief      Checks to execute get test status service.
 *
 * @param[in]  GrpId: The test group type(e.g. start up or shut down).
 *
 * @return     boolean
 * @retval     TRUE: Get test status service is ready to execute.
 * @retval     FALSE: Get test status service is not ready to execute.
 *
 */
static HTMSS_TestStatusType HTMSS_CheckGetTestStatus(HTMSS_TestGroupType GrpId)
{
    HTMSS_TestStatusType CheckResult = HTMSS_STATUS_OK;

    if (HTMSS_UINIT == HTMSS_State)
    {
        (void)Det_ReportError((uint16)HTMSS_MODULE_ID, HTMSS_INSTANCE_ID,
                              (uint8)HTMSS_SID_GET_TEST_RESULT, HTMSS_E_NOT_INIT);
        CheckResult = HTMSS_STATUS_UNINIT;
    }
    else
    {
        if ((HTMSS_STARTUP != GrpId) && (HTMSS_SHUTDOWN != GrpId))
        {
            (void)Det_ReportError((uint16)HTMSS_MODULE_ID, HTMSS_INSTANCE_ID,
                                  (uint8)HTMSS_SID_GET_TEST_RESULT, HTMSS_E_PARAM_INVALID);
            CheckResult = HTMSS_STATUS_INVALID;
        }
    }

    return CheckResult;
}
#endif /* ( HTMSS_DEV_ERROR_DETECT == STD_ON ) */

/**
 * @brief      Starts already configured MSTP self tests.
 *
 * @param[in]  GrpId: The test group type (e.g. start up or shut down).
 *
 * @return     None.
 *
 */
static void HTMSS_StartMstpSelfTests(HTMSS_TestGroupType GrpId)
{
    const HTMSS_TestModuleConfigType *TestSetPtr = NULL_PTR;
    uint8                             NumberOfTest = 0U;
    uint8                             Index = 0U;

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    HTMSS_State = HTMSS_BUSY;
#endif
    Mstp_ClearSelfTestResults();

    if (HTMSS_STARTUP == GrpId)
    {
        TestSetPtr = HTMSS_ConfigPtr->StartUpTestGrpPtr;
        NumberOfTest = HTMSS_ConfigPtr->NumberOfStartUpTests;
    }
    else
    {
        TestSetPtr = HTMSS_ConfigPtr->ShutDownTestGrpPtr;
        NumberOfTest = HTMSS_ConfigPtr->NumberOfShutDownTests;
    }

    /* Update test flag in case of WDOG self test is configured in startup test group */
    if (NumberOfTest > 0U)
    {
        if (MSTP_SELFTEST_WDOG == TestSetPtr[NumberOfTest - 1U].TestId)
        {
            Mstp_SetSelfTestFlag();
        }
    }

    for (; Index < NumberOfTest; ++Index)
    {
        if (NULL_PTR != TestSetPtr[Index].SelfTestFuncPtr)
        {
            TestSetPtr[Index].SelfTestFuncPtr();
        }
    }
}

/**
 * @brief      Gets test results from MSTP.
 *
 * @param[in]  GrpId: The test group type (e.g. start up or shut down).
 * @param[out] RequestTestResultPtr: Pointer to store configured MSTP self test results.
 *
 * @return     boolean
 * @retval     TRUE: Self test result of all configured modules are passed.
 * @retval     FALSE: At least one of the modules' self test result is failed.
 *
 */
static boolean HTMSS_GetMstpTestsResult(HTMSS_TestGroupType   GrpId,
                                        HTMSS_TestResultType *RequestTestResultPtr)
{
    boolean                           Ret = TRUE;
    uint8                             Index = 0U;
    const HTMSS_TestModuleConfigType *TestSetPtr = NULL_PTR;
    uint8                             NumberOfTest = 0U;
    Mstp_SelfTestResultType           TmpResult = MSTP_SELFTEST_RESULT_SUCCESS;

    if (HTMSS_STARTUP == GrpId)
    {
        TestSetPtr = HTMSS_ConfigPtr->StartUpTestGrpPtr;
        NumberOfTest = HTMSS_ConfigPtr->NumberOfStartUpTests;
    }
    else
    {
        TestSetPtr = HTMSS_ConfigPtr->ShutDownTestGrpPtr;
        NumberOfTest = HTMSS_ConfigPtr->NumberOfShutDownTests;
    }

    for (; Index < NumberOfTest; ++Index)
    {
        if (NULL_PTR != TestSetPtr[Index].GetTestResultFuncPtr)
        {
            TmpResult = TestSetPtr[Index].GetTestResultFuncPtr();

            if (NULL_PTR != RequestTestResultPtr)
            {
                RequestTestResultPtr[Index].TestResult = (uint8)TmpResult;
                RequestTestResultPtr[Index].TestSignature = (uint8)TestSetPtr[Index].TestId;
            }
        }

        if (MSTP_SELFTEST_RESULT_SUCCESS != TmpResult)
        {
            Ret = FALSE;
        }
    }

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    /* Reset test state */
    HTMSS_State = HTMSS_IDLE;
#endif

    if (MSTP_SELFTEST_STATE_BUSY == Mstp_GetSelfTestFlag())
    {
        Mstp_ClearSelfTestFlag();
    }
    return Ret;
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief     Initializes the HTMSS driver.
 *
 * @param[in] ConfigPtr: Pointer to configuration set in Variant PB (Variant PC requires a NULL_PTR)
 *
 * @return    None
 *
 */
void HTMSS_Init(const HTMSS_TestCfgType *ConfigPtr)
{
    Mcu_ResetType ResetReason = MCU_RESET_UNDEFINED;

    HTMSS_PARAM_UNUSED(ConfigPtr);

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == HTMSS_CheckInit(ConfigPtr))
    {
#endif
        HTMSS_ConfigPtr = HTMSS_PreDefinedConfigPtr;

        Mstp_Init();

        ResetReason = Mcu_GetResetReason(); 
        if (MCU_HW_TEST_RESET == ResetReason)
        {
#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
            HTMSS_State = HTMSS_BUSY;
#endif
        }
        else
        {
#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
            HTMSS_State = HTMSS_INIT;
#endif
        }

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* Clean the configuration pointer in case of an error. */
        HTMSS_ConfigPtr = NULL_PTR;
    }
#endif
}

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
Std_ReturnType HTMSS_StartTest(HTMSS_TestGroupType GrpId)
{
    Std_ReturnType StartTestStatus = (Std_ReturnType)E_OK;
#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == HTMSS_CheckStartTest(GrpId))
    {
#endif /* (HTMSS_DEV_ERROR_DETECT == STD_ON) */

        /* Start MSTP tests */
        if ((HTMSS_STARTUP == GrpId) || (HTMSS_SHUTDOWN == GrpId))
        {
            HTMSS_StartMstpSelfTests(GrpId);
        }
        /* Invalid test group id */
        else
        {
            StartTestStatus = (Std_ReturnType)E_NOT_OK;
        }

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        StartTestStatus = (Std_ReturnType)E_NOT_OK;
    }
#endif /*( HTMSS_DEV_ERROR_DETECT == STD_ON )*/

    return StartTestStatus;
}

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
                                         HTMSS_TestResultType *RequestTestResultPtr)
{
    HTMSS_TestStatusType RetTestStatus = HTMSS_STATUS_OK;

#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    RetTestStatus = HTMSS_CheckGetTestStatus(GrpId);

    if (HTMSS_STATUS_OK == RetTestStatus)
    {
#endif /* (HTMSS_DEV_ERROR_DETECT == STD_ON) */
        if ((HTMSS_STARTUP == GrpId) || (HTMSS_SHUTDOWN == GrpId))
        {

            if (TRUE == HTMSS_GetMstpTestsResult(GrpId, RequestTestResultPtr))
            {
                RetTestStatus = HTMSS_STATUS_OK;
            }
            else
            {
                RetTestStatus = HTMSS_STATUS_NOK;
            }
        }
        /* Invalid test group id */
        else
        {
            RetTestStatus = HTMSS_STATUS_INVALID;
        }
#if (HTMSS_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (HTMSS_DEV_ERROR_DETECT == STD_ON) */

    return RetTestStatus;
}

#if (HTMSS_VERSION_INFO_API == STD_ON)
/**
 * @brief      Gets the version information of this module.
 *
 * @param[out] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return     None.
 *
 */
void HTMSS_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    if (NULL_PTR != versioninfo)
    {
        (versioninfo)->vendorID = (uint16)HTMSS_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)HTMSS_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)HTMSS_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)HTMSS_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)HTMSS_SW_PATCH_VERSION;
    }
    else
    {
    #if (HTMSS_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)HTMSS_MODULE_ID, HTMSS_INSTANCE_ID,
                              HTMSS_SID_GET_VERSION_INFO, HTMSS_E_NULL_POINTER);
    #endif /* (HTMSS_DEV_ERROR_DETECT == STD_ON) */
    }
}
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
void HTMSS_StartupTestErrorHook(void)
{
#if (HTMSS_STARTUP_TEST_ERROR_CALLOUT_SUPPORT == STD_ON)
    HTMSS_STARTUP_TEST_ERROR_CALLOUT_FUNC();
#endif
}

/**
 * @brief     The ECU State Manager will call the error hook if the HTMSS provided shutdown test
 *            results have a failure.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void HTMSS_ShutdownTestErrorHook(void)
{
#if (HTMSS_SHUTDOWN_TEST_ERROR_CALLOUT_SUPPORT == STD_ON)
    HTMSS_SHUTDOWN_TEST_ERROR_CALLOUT_FUNC();
#endif
}

#define HTMSS_STOP_SEC_CODE
#include "Htmss_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group HTMSS */

/** @} end of group HTMSS_Module */
