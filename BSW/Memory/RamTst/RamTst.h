/*  Copyright (C) 2021, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       <RamTst.c>
 *  brief
 *
 *  <Compiler: GHS 202014  MCU:XX>
 *
 *  author     <Xin.Liu>
 *  date       <2021-09-14>
 */
/*============================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>    <AUTHOR>   <REVISION LOG>
 *  V1.0.0     20210914     Xin.Liu   Initial version
 */
/*============================================================================*/
#ifndef RAMTST_H_
#define RAMTST_H_

/******************************INCLUDE*********************************/
#include "RamTst_Cfg.h"
#include "Std_Types.h"
#include "RamTst_Types.h"
#include "MemMap.h"

/*********************************WDGM Version Definition*************************************/
#define RAMTST_VENDOR_ID 62u  /* Vendor ID*/
#define RAMTST_INSTANCE_ID 0u /* Instance ID*/
#define RAMTST_MODULE_ID 93u

#define RAMTST_H_SW_MAJOR_VERSION 1u /*Major Version*/
#define RAMTST_H_SW_MINOR_VERSION 0u /*Minor Version*/
#define RAMTST_H_SW_PATCH_VERSION 0u /*Patch Version*/
#define RAMTST_H_AR_MAJOR_VERSION 4u /*Autosar Major Version*/
#define RAMTST_H_AR_MINOR_VERSION 2u /*Autosar Minor Version*/
#define RAMTST_H_AR_PATCH_VERSION 2u /*Autosar Patch Version*/

/******************************API ID Definition *********************************/
#define RAMTST_INIT_ID (0x00u) /* RamTst_Init()*/
#define RAMTST_STOP_ID (0x01u) /* RamTst_Stop()*/
#define RAMTST_ALLOW_ID (0x02u) /* RamTst_Allow()*/
#define RAMTST_SUSPEND_ID (0x03u) /* RamTst_Suspend()*/
#define RAMTST_RESUME_ID (0x04u) /* RamTst_Suspend()*/
#define RAMTST_GET_TEST_RESULT_PER_BLOCK_ID (0x05u) /* RamTst_GetTestResultPerBlock(RamTst_NumberOfBlocksType BlockID) */
#define RAMTST_GET_VERSION_INFO_ID (0x06)/* RamTst_GetVersionInfo */
#define RAMTST_SELECT_ALGPARAMS_ID (0x07) /* RamTst_SelectAlgParams(RamTst_AlgParamsIdType NewAlgParamsId) */
#define RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_ID (0x08) /* RamTst_ChangeNumberOfTestedCells(RamTst_NumberOfTestedCellsType NewNumberOfTestedCells) */
#define RAMTST_RUN_FULL_TEST_ID (0x09) /* RamTst_RunFullTest */
#define RAMTST_RUN_PARTIAL_TEST_ID (0x0A) /* RamTst_RunPartialTest */
#define RAMTST_GET_EXECUTION_STATUS_ID (0x0B) /* RamTst_GetExecutionStatus */
#define RAMTST_GET_TEST_RESULT_ID (0x0C) /* RamTst_GetTestResult */
#define RAMTST_GET_ALG_PARAMS_ID (0x0D) /* RamTst_GetAlgParams */
#define RAMTST_GET_TEST_ALGORITHM_ID (0x0E) /* RamTst_GetTestAlgorithm */
#define RAMTST_GET_NUMBER_OF_TESTED_CELLS_ID (0x0F) /* RamTst_GetNumberOfTestedCells */
#define RAMTST_GET_MAIN_FUNCTION_ID (0x10) /* RamTst_MainFunction */
#define RAMTST_DEINIT_ID (0x11u) /* RamTst_DeInit()*/


/******************************Det Error Definition*********************************/
#define RAMTST_E_STATUS_FAILURE (0x01u) /* A particular API is called in an unexpected state */
#define RAMTST_E_OUT_OF_RANGE (0x02u)   /* API parameter out of specified range */
#define RAMTST_E_UNINIT (0x03u)         /* API service used without module initialization */
#define RAMTST_E_PARAM_POINTER (0x04u)  /* API service called with a NULL pointer */
#define RAMTST_E_SELF_CHECK_ERR (0x05u) /* RAMTst Self Check Err */



/****************************************         RamTst define         **********************************************/
#define BCKGRND     ((uint32)0x00000000uL)
#define INV_BCKGRND ((uint32)0xFFFFFFFFuL)


/***************************extern variable********************************************/
#define RAMTST_START_SEC_CONST_UNSPECIFIED
#include "RamTst_MemMap.h"
/*RamTst configuration. Used by RamTst_Init()*/
extern const RamTst_ConfigType RamTstConfigRoot[1];  
#define RAMTST_STOP_SEC_CONST_UNSPECIFIED
#include "RamTst_MemMap.h"

/**********************************                 extern api                  *************************************/
#define RAMTST_START_SEC_CODE
#include "RamTst_MemMap.h"

/*************************************************************************/
/* RamTst
 * Brief               Service for RAM Test initialization
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr:Pointer to the selected configuration set.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_Init(const RamTst_ConfigType *ConfigPtr);

/*************************************************************************/
/* RamTst
 * Brief               Service for RAM Test deinitialization
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_DeInit(void);

#if RAMTST_STOP_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service for stopping the RAM Test
 * ServiceId           None
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_Stop(void);
#endif

#if RAMTST_ALLOW_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service for continuing the RAM Test after calling 'RamTst_Stop.
 * ServiceId           None
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_Allow(void);
#endif

#if RAMTST_SUSPEND_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service for suspending current operation of background RAM Test, until RESUME is called
 * ServiceId           None
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_Suspend(void);
#endif

#if RAMTST_RESUME_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service for allowing to continue the background RAM Test at the point is was suspended.
 * ServiceId           None
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_Resume(void);
#endif

#if RAMTST_GET_EXECUTION_STATUS_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service returns the current RAM Test execution status.
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              RamTst_ExecutionStatusTyp
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
RamTst_ExecutionStatusType RamTst_GetExecutionStatus (void);
#endif

#if RAMTST_GET_TEST_RESULT_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service returns the current RAM Test result.
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              RamTst_TestResultType
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
RamTst_TestResultType RamTst_GetTestResult(void);
#endif 

#if RAMTST_GET_TEST_RESULT_PER_BLOCK_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service returns the current RAM Test result for the specified block
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockID:Identifies the block
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              RamTst_TestResultType
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
RamTst_TestResultType RamTst_GetTestResultPerBlock(RamTst_NumberOfBlocksType BlockID);
#endif

#if RAMTST_VERSIONINFO_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service returns the version information of this module
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  versioninfo：Pointer to the location / address where to store the version information of this module.
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif

#if RAMTST_GET_ALGPARAMS_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service returns the ID of the current RAM Test algorithm parameter set.
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              RamTst_AlgParamsIdType
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
RamTst_AlgParamsIdType RamTst_GetAlgParams(void);
#endif

#if RAMTST_GET_TEST_ALGORITHM_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service returns the current RAM Test algorithm.
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              RamTst_AlgorithmType
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
RamTst_AlgorithmType RamTst_GetTestAlgorithm(void);
#endif

#if RAMTST_GET_NUMBER_OF_TESTED_CELLS_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service returns the current number of tested cells per main-function cycle.
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              RamTst_NumberOfTestedCellsType:Number of currently tested cells per cycle
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
RamTst_NumberOfTestedCellsType RamTst_GetNumberOfTestedCells(void);
#endif

#if RAMTST_SELECT_ALGPARAMS_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service used to set the test algorithm and its parameter set.
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      NewAlgParamsId:Identifies the parameter set to be used.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_SelectAlgParams(RamTst_AlgParamsIdType NewAlgParamsId);
#endif

#if RAMTST_CHANGE_NUM_OF_TESTED_CELLS_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service changes the current number of tested cells
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RamTst_NumberOfTestedCellsType
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_ChangeNumberOfTestedCells(RamTst_NumberOfTestedCellsType NewNumberOfTestedCells);
#endif

#if RAMTST_RUN_FULL_TEST_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service for executing the full RAM Test in the foreground.
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_RunFullTest(void);
#endif

#if RAMTST_RUN_PARTIAL_TEST_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               Service for testing one RAM block in the foreground
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockId：Identifies the single RAM block to be tested in the selected set of RamTstAlgParams.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_RunPartialTest(RamTst_NumberOfBlocksType BlockId);
#endif

/*************************************************************************/
/* RamTst
 * Brief               Scheduled function for executing the RAM Test in the background
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_MainFunction(void);

#if RAMTST_TEST_COMPLETE_NOTIFICATION_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               The function RamTst_TestCompleted shall be called every time when all RAM 
                        blocks of the current test configuration have been tested in the background
 * Sync/Async          --
 * Reentrancy          Dont care
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_TestCompletedNotification (void);
#endif

#if RAMTST_TEST_ERROR_NOTIFICATION_API_ENABLE
/*************************************************************************/
/* RamTst
 * Brief               The function RamTst_Error shall be called every time when a RAM failure has
                        been detected by the selected test algorithm in the background.
 * Sync/Async          --
 * Reentrancy          Dont care
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI
 */
/*************************************************************************/
void RamTst_ErrorNotification(void);
#endif

#define RAMTST_STOP_SEC_CODE
#include "RamTst_MemMap.h"

#endif /* RAMTST_H_ */


