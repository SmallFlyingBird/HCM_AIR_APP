/**************************************************************************************************/
/**
 * @file      : Mstp.h
 * @brief     : Mstp AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MSTP_H
#define MSTP_H

/** @addtogroup Mstp_Module
 *  @{
 */

/** @addtogroup Mstp
 *  @brief Mstp AUTOSAR level
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Mstp_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define MSTP_VENDOR_ID                   0x00B3U
#define MSTP_MODULE_ID                   MSTP_CFG_H_MODULE_ID
#define MSTP_AR_RELEASE_MAJOR_VERSION    4U
#define MSTP_AR_RELEASE_MINOR_VERSION    6U
#define MSTP_AR_RELEASE_REVISION_VERSION 0U
#define MSTP_SW_MAJOR_VERSION            1U
#define MSTP_SW_MINOR_VERSION            1U
#define MSTP_SW_PATCH_VERSION            0U

/* Check if current file and Mstp_Types header file are of the same vendor */
#if (MSTP_VENDOR_ID != MSTP_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mstp.h and Mstp_Types.h are different"
#endif

/* Check if current file and Mstp_Types header file are of the same Autosar version */
#if ((MSTP_AR_RELEASE_MAJOR_VERSION != MSTP_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                   \
     (MSTP_AR_RELEASE_MINOR_VERSION != MSTP_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                   \
     (MSTP_AR_RELEASE_REVISION_VERSION != MSTP_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mstp.h and Mstp_Types.h are different"
#endif

/* Check if current file and Mstp_Types header file are of the same software version */
#if ((MSTP_SW_MAJOR_VERSION != MSTP_TYPES_H_SW_MAJOR_VERSION) ||                                   \
     (MSTP_SW_MINOR_VERSION != MSTP_TYPES_H_SW_MINOR_VERSION) ||                                   \
     (MSTP_SW_PATCH_VERSION != MSTP_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mstp.h and Mstp_Types.h are different"
#endif

/**
 * @brief Specifies the wait counter for self-test related interrupt.
 */
#define MSTP_WAITCOUNTER (100000U)
/**
 * @brief Specifies the tolerance for bandgap.
 */
#define MSTP_PMU_BANDGAP_TOLERANCE (0.03f)
/**
 * @brief Specifies the InstanceId of this module instance.
 */
#define MSTP_INSTANCE_ID ((uint8)0x0U)

/**
 * @brief Service Ids for MSTP APIs
 */
#define MSTP_SID_INIT                           ((uint8)0x01U)
#define MSTP_SID_SET_TEST_FLAG                  ((uint8)0x02U)
#define MSTP_SID_GET_TEST_FLAG                  ((uint8)0x03U)
#define MSTP_SID_CLEAR_TEST_FLAG                ((uint8)0x04U)
#define MSTP_SID_GET_VERSION_INFO               ((uint8)0x05U)
#define MSTP_SID_CMU_SELFTEST                   ((uint8)0x06U)
#define MSTP_SID_GET_CMU_SELFTEST_RESULT        ((uint8)0x07U)
#define MSTP_SID_EWDT_SELFTEST                  ((uint8)0x08U)
#define MSTP_SID_GET_EWDT_SELFTEST_RESULT       ((uint8)0x09U)
#define MSTP_SID_FLASHECC_SELFTEST              ((uint8)0x0AU)
#define MSTP_SID_GET_FLASHECC_SELFTEST_RESULT   ((uint8)0x0BU)
#define MSTP_SID_PARCC_SELFTEST                 ((uint8)0x0CU)
#define MSTP_SID_GET_PARCC_SELFTEST_RESULT      ((uint8)0x0DU)
#define MSTP_SID_SERU_SELFTEST                  ((uint8)0x0EU)
#define MSTP_SID_GET_SERU_SELFTEST_RESULT       ((uint8)0x0FU)
#define MSTP_SID_SMPU_SELFTEST                  ((uint8)0x10U)
#define MSTP_SID_GET_SMPU_SELFTEST_RESULT       ((uint8)0x11U)
#define MSTP_SID_SRAMECC_SELFTEST               ((uint8)0x12U)
#define MSTP_SID_GET_SRAMECC_SELFTEST_RESULT    ((uint8)0x13U)
#define MSTP_SID_WDOG_SELFTEST                  ((uint8)0x14U)
#define MSTP_SID_GET_WDOG_SELFTEST_RESULT       ((uint8)0x15U)
#define MSTP_SID_PMU_SELFTEST                   ((uint8)0x16U)
#define MSTP_SID_GET_PMU_SELFTEST_RESULT        ((uint8)0x17U)
#define MSTP_SID_CRC_SELFTEST                   ((uint8)0x18U)
#define MSTP_SID_GET_CRC_SELFTEST_RESULT        ((uint8)0x19U)
#define MSTP_SID_SERU_SELFTEST_CALLBACK_FUNC    ((uint8)0x1AU)
#define MSTP_SID_SMPU_SELFTEST_CALLBACK_FUNC    ((uint8)0x1BU)
#define MSTP_SID_TRIGGER_REG_CHECK              ((uint8)0x1CU)
#define MSTP_SID_GET_REG_CHECK_RESULT           ((uint8)0x1DU)
#define MSTP_SID_GET_RAM_TEST_RESULT_PER_BLOCK  ((uint8)0x1EU)
#define MSTP_SID_GET_RAM_TEST_RESULT            ((uint8)0x1FU)
#define MSTP_SID_RAM_TEST_MAIN_FUNCTION         ((uint8)0x20U)
#define MSTP_SID_CLEAR_SELFTEST_RESULT          ((uint8)0x21U)
#define MSTP_SID_READ_FLASH_DELAY_REG           ((uint8)0x22U)
#define MSTP_SID_SRAMECC_SELFTEST_CALLBACK_FUNC ((uint8)0x23U)

/**
 * @brief Development errors
 */
#define MSTP_E_NULL_POINTER        ((uint8)0x02U)
#define MSTP_E_PARAM_INVALID       ((uint8)0x03U)
#define MSTP_E_ALREADY_INITIALIZED ((uint8)0x04U)
#define MSTP_E_NOT_INIT            ((uint8)0x05U)
#define MSTP_E_STATUS_INVALID      ((uint8)0x06U)

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define MSTP_START_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"
extern const Mstp_ConfigType *const Mstp_PreDefinedConfigPtr;
#define MSTP_STOP_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"

#define MSTP_START_SEC_VAR_CLEARED_32
#include "Mstp_MemMap.h"

MSTP_RAM_TEST_RESULT_EXT

#define MSTP_STOP_SEC_VAR_CLEARED_32
#include "Mstp_MemMap.h"

/** @} end of group Global_VariableDeclaration */

#define MSTP_START_SEC_CODE
#include "Mstp_MemMap.h"

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/**
 * @brief     Mstp Init.
 *
 * @details   Initializes MSTP module.
 *
 * @return    None
 * 
 */
void Mstp_Init(void);

/**
 * @brief     Sets current self-test state to busy.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_SetSelfTestFlag(void);

/**
 * @brief     Returns current self-test state.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestStateType
 * @retval    MSTP_SELFTEST_STATE_IDLE: no test is executing now.
 * @retval    MSTP_SELFTEST_STATE_BUSY: test is ongoing.
 * 
 */
Mstp_SelfTestStateType Mstp_GetSelfTestFlag(void);

/**
 * @brief     Clears/Resets current self-test state.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_ClearSelfTestFlag(void);

/**
 * @brief      Returns MSTP module version info.
 *
 * @param[out] Versioninfo: Pointer to where to store the version information of this module.
 *
 * @return     None
 * 
 */
void Mstp_GetVersioninfo(Std_VersionInfoType *Versioninfo);

/**
 * @brief     CMU module self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_CmuSelfTest(void);

/**
 * @brief     Returns CMU module self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetCmuSelfTestResult(void);

/**
 * @brief     EWDT module self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_EwdtSelfTest(void);

/**
 * @brief     Returns EWDT module self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetEwdtSelfTestResult(void);

/**
 * @brief     Flash ecc self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_FlashEccSelfTest(void);

/**
 * @brief     Returns flash ecc self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetFlashEccSelfTestResult(void);

/**
 * @brief     Peripheral write lock self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_ParccSelfTest(void);

/**
 * @brief     Returns peripheral write lock function self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetParccSelfTestResult(void);

/**
 * @brief     SERU module self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_SeruSelfTest(void);

/**
 * @brief     Returns SERU module self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetSeruSelfTestResult(void);

/**
 * @brief     SMPU module self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_SmpuSelfTest(void);

/**
 * @brief     Returns SMPU module self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetSmpuSelfTestResult(void);

/**
 * @brief     SRAM ecc self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_SramEccSelfTest(void);

/**
 * @brief     Returns SRAM ecc function self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetSramEccSelfTestResult(void);

/**
 * @brief     WDOG module self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_WdogSelfTest(void);

/**
 * @brief     Returns WDOG module self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetWdogSelfTestResult(void);

/**
 * @brief     PMU bandgap self test function.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Mstp_PmuSelfTest(void);

/**
 * @brief     Returns PMU bandgap self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: Module self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED:  Module self-test is failed.
 *
 */
Mstp_SelfTestResultType Mstp_GetPmuSelfTestResult(void);

/**
 * @brief      SERU self-test callback function
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  SERU self-test is executing now.
 * @retval     FALSE: SERU self-test is not triggered.
 *
 */
boolean Mstp_SeruSelfTestCallbackFunction(void);

/**
 * @brief      SMPU self-test error callback function
 *
 * @param[in]  None
 *
 * @return     None
 * 
 */
void Mstp_SmpuSelfTestCallbackFunction(void);

/**
 * @brief     Trigger the MSTP Reg Check.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Mstp_TriggerRegCheck(void);

/**
 * @brief      Get register check result.
 *
 * @param[out] ResultBufferPtr: Pointer to the module CRC check result buffer.
 * @param[in]  TotalModuleNum: Number of configured module that being checked.
 *
 * @return     boolean
 * @retval     TRUE: Succeed in getting CRC result.
 * @retval     FALSE: Failed in getting CRC result.
 *
 */
boolean Mstp_GetRegCheckResult(uint32 *ResultBufferPtr, uint32 TotalModuleNum);

/**
 * @brief     Mstp Crc module self test
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Mstp_CrcSelfTest(void);

/**
 * @brief     Get CRC self test result
 * @details   This function provide api to get CRC self test result.
 *
 * @param[in] None
 *
 * @return    Mstp_SelfTestResultType: Status of CRC self test
 * @retval    MSTP_SELFTEST_RESULT_SUCCESS: specified self-test is passed.
 * @retval    MSTP_SELFTEST_RESULT_FAILED: specified self-test is MSTP_SELFTEST_RESULT_FAILED.
 * 
 */
Mstp_SelfTestResultType Mstp_GetCrcSelfTestResult(void);

/**
 * @brief     Read flash module delay register value.
 *
 * @param[in] None
 *
 * @return    uint32: Delay register value.
 * @retval    0xFFFFFFFF: Invalid value indicates Flash peripheral is not enabled.
 *
 */
uint32 Mstp_ReadFlashDelayReg(void);

/**
 * @brief     Returns the current RAM Test result for the specified block.
 *
 * @param[in] BlockId: Test RAM block id.
 *
 * @return    Mstp_RamTestResultType
 * @retval    MSTP_RAMTST_RESULT_NOT_TESTED: The RAM Test is not executed.
 * @retval    MSTP_RAMTST_RESULT_OK: The RAM Test has been tested with OK result.
 * @retval    MSTP_RAMTST_RESULT_NOT_OK: The RAM Test has been tested with NOT-OK result.
 * @retval    MSTP_RAMTST_RESULT_UNDEFINED: The RAM Test is currently running.
 *
 */
Mstp_RamTestResultType Mstp_GetRamTestResultPerBlock(uint32 BlockId);

/**
 * @brief     Returns the current RAM Test result.
 *
 * @param[in] None
 *
 * @return    Mstp_RamTestResultType
 * @retval    MSTP_RAMTST_RESULT_NOT_TESTED: The RAM Test is not executed.
 * @retval    MSTP_RAMTST_RESULT_OK: The RAM Test has been tested with OK result.
 * @retval    MSTP_RAMTST_RESULT_NOT_OK: The RAM Test has been tested with NOT-OK result.
 * @retval    MSTP_RAMTST_RESULT_UNDEFINED: The RAM Test is currently running.
 *
 */
Mstp_RamTestResultType Mstp_GetRamTestResult(void);

/**
 * @brief     Scheduled function for executing the RAM Test in the background.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Mstp_RamTstMainFunction(void);

/**
 * @brief     Clears modules self test result.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Mstp_ClearSelfTestResults(void);

/**
 * @brief      SRAM ECC self-test callback function
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  SRAM ECC self-test is executing now.
 * @retval     FALSE: SRAM ECC self-test is not triggered.
 *
 */
boolean Mstp_SramEccSelfTestCallbackFunction(void);

#define MSTP_STOP_SEC_CODE
#include "Mstp_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Mstp */

/** @} end of group Mstp_Module */

#endif /* MSTP_H */
