/*============================================================================*/
/*  Copyright (C) 2021, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       <FlsTst.h>
 *  brief      <Containing the entire or parts of Flash test code.>
 *
 *  <Compiler: S32DS 2.2 with GreenHills  MCU:S32K146>
 *
 *  author     <yin.Huang>
 *  date       <2021-9-16>
 */
/*============================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>      <AUTHOR>         <REVISION LOG>
 *   V1.0.0     20210916     Huangyin         Initial version
 */
/*============================================================================*/
#ifndef FLSTST_H
#define FLSTST_H

/*============================[I N C L U D E S]===============================*/
#include "FlsTst_Cfg.h"
/*============================================================================*/


/*===================[V E R S I O N  I N F O R M A T I O N]===================*/
#define FLSTST_VENDOR_ID 62U
#define FLSTST_MODULE_ID 104U
#define FLSTST_H_AR_MAJOR_VERSION 4U
#define FLSTST_H_AR_MINOR_VERSION 2U
#define FLSTST_H_AR_PATCH_VERSION 2U
#define FLSTST_H_SW_MAJOR_VERSION 1U
#define FLSTST_H_SW_MINOR_VERSION 0U
#define FLSTST_H_SW_PATCH_VERSION 1U
#define FLSTST_INSTANCE_ID              0U
/*============================================================================*/


/*==============================[M A C R O S]=================================*/
/*================ ServiceID ==============*/
#define FLSTST_INIT_ID                  0x00U
#define FLSTST_DEINIT_ID                0x01U
#define FLSTST_STARTFGND_ID             0x02U
#define FLSTST_ABORT_ID                 0x03U
#define FLSTST_SUSPEND_ID               0x04U
#define FLSTST_RESUME_ID                0x05U
#define FLSTST_GETCURRENTSTATE_ID       0x06U
#define FLSTST_GETTESTRESULTBGND_ID     0x07U
#define FLSTST_GETTESTRESULTFGND_ID     0x0FU
#define FLSTST_GETVERSIONINFO_ID        0x08U
#define FLSTST_GETTESTSIGNATUREBGND_ID  0x09U
#define FLSTST_GETTESTSIGNATUREFGND_ID  0x0AU
#define FLSTST_GETERRORDETAILS_ID       0x0BU
#define FLSTST_TESTECC_ID               0x0CU
#define FLSTST_MAINFUNCTION_ID          0x0DU
#define FLSTST_TESTCOMPLETENOTIFY_ID    0x0EU

/*============== DET Error Number===========*/
#define FLSTST_E_STATE_FAILURE          0x01U
#define FLSTST_E_PARAM_INVALID          0x02U
#define FLSTST_E_UNINIT                 0x03U
#define FLSTST_E_ALREADY_INITIALIZED    0x04U
#define FLSTST_E_INIT_FAILED            0x05U
#define FLSTST_E_PARAM_POINTER          0x06U
#define FLSTST_E_DATA_CRRUPTED			0x07U
#define FLSTST_E_SUSPEND_OVERTIME		0x08U

#define FlsTst_GetResource()
#define FlsTst_FreeResource()
/*============================================================================*/

extern uint8 CrcCompleted;

/*===============[F U N C T I O N   D E C L A R A T I O N]===============*/
/*************************************************************************/
/*
 * Brief               Service for Flash Test initialization.
 * ServiceId           0x00
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to configuration set.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern void FlsTst_Init (const FlsTst_ConfigType* ConfigPtr);

/*************************************************************************/
/*
 * Brief               Service for Flash Test De-Initialization.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern void FlsTst_DeInit(void);

/*************************************************************************/
/*
 * Brief               Service for executing foreground Flash Test.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      FgndBlockId: Number of the foreground test to be 
 *                     executed. This is dependent on configuration.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                       E_OK: Foreground test processed
 *                       E_NOT_OK: Foreground test not accepte
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_START_FGND_API) && (0 != FLSTST_FGND_BLOCK_NUM))
extern Std_ReturnType FlsTst_StartFgnd (FlsTst_BlockIdFgndType FgndBlockId);
#endif
/*************************************************************************/
/*
 * Brief               Service for aborting the Flash Test.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 */
/*************************************************************************/
#if(0U != FLSTST_BGND_BLOCK_NUM)
extern void FlsTst_Abort (void);
#endif
/*************************************************************************/
/*
 * Brief               Service for suspending current operation of the 
 *                     Flash Test, until FlsTst_Resume is called.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_SUSPEND_RESUME_API)&&(0U != FLSTST_BGND_BLOCK_NUM))
extern void FlsTst_Suspend (void);
#endif /* STD_ON == FLSTST_SUSPEND_RESUME_API */

/*************************************************************************/
/*
 * Brief               Service for continuing the Flash Test at the point
 *                     it was suspended.
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_SUSPEND_RESUME_API)&&(0U != FLSTST_BGND_BLOCK_NUM))
extern void FlsTst_Resume (void);
#endif /* STD_ON == FLSTST_SUSPEND_RESUME_API */

/*************************************************************************/
/*
 * Brief               Service for continuing the Flash Test at the point
 *                     it was suspended.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              FlsTst_StateType
 *                  FLSTST_UNINIT:
 *                     The Flash Test is not initialized or not usable.
 *                  FLSTST_INIT:
 *                     The Flash Test is initialized and ready to be started.
 *                  FLSTST_RUNNING:
 *                     The Flash Test is currently running.
 *                  FLSTST_ABORTED:
 *                     The Flash Test is aborted.
 *                  FLSTST_SUSPENDED:
 *                     The Flash Test is waiting to be resumed or is waiting 
 *                     to start forground mode test.
 * PreCondition        None
 */
/*************************************************************************/
#if(STD_ON == FLSTST_GET_CURRENT_STATE_API)
extern FlsTst_StateType FlsTst_GetCurrentState (void);
#endif /* STD_ON == FLSTST_GET_CURRENT_STATE_API */

/*************************************************************************/
/*
 * Brief               Service returns the Background Flash Test result.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              FlsTst_TestResultBgndType
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_GET_TEST_RESULT_BGND_API) && (0 != FLSTST_BGND_BLOCK_NUM))
extern FlsTst_TestResultBgndType FlsTst_GetTestResultBgnd (void);
#endif /* STD_ON == FLSTST_GET_TEST_RESULT_BGND_API */

/*************************************************************************/
/*
 * Brief               Service returns the Foreground Flash Test result.
 * ServiceId           0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              FlsTst_TestResultFgndType
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_GET_TEST_RESULT_FGND_API) && (0 != FLSTST_FGND_BLOCK_NUM))
extern FlsTst_TestResultFgndType FlsTst_GetTestResultFgnd (void);
#endif /* STD_ON == FLSTST_GET_TEST_RESULT_FGND_API */

/*************************************************************************/
/*
 * Brief               Service returns the version information of this module.
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     versioninfo:Pointer to where to store the version 
 *                     information of this module.
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 */
/*************************************************************************/
#if(STD_ON == FLSTST_VERSION_INFO_API)
extern void FlsTst_GetVersionInfo (Std_VersionInfoType* versionInfo);
#endif /* STD_ON == FLSTST_VERSION_INFO_API */

/*************************************************************************/
/*
 * Brief               Service returns the Flash Test result in background 
 *                     mode.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              FlsTst_TestSignatureBgndType
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_GET_TEST_SIGNATURE_BGND_API)&&(0 != FLSTST_BGND_BLOCK_NUM ))
extern FlsTst_TestSignatureBgndType FlsTst_GetTestSignatureBgnd (void);
#endif /* STD_ON == FLSTST_GET_TEST_SIGNATURE_BGND_API */

/*************************************************************************/
/*
 * Brief               Service returns the Flash Test result in background 
 *                     mode.
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              FlsTst_TestSignatureFgndType
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_GET_TEST_SIGNATURE_FGND_API)&&(0 != FLSTST_FGND_BLOCK_NUM))
extern FlsTst_TestSignatureFgndType FlsTst_GetTestSignatureFgnd (void);
#endif /* STD_ON == FLSTST_GET_TEST_SIGNATURE_FGND_API */

/*************************************************************************/
/*
 * Brief               Service returns error detais monitored from the 
 *                     Flash module.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              FlsTst_ErrorDetailsType
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_GET_ERRORD_ETAILS_API)&&\
((0U != FLSTST_BGND_BLOCK_NUM)||(0U != FLSTST_FGND_BLOCK_NUM)))
extern FlsTst_ErrorDetailsType FlsTst_GetErrorDetails (void);
#endif /* STD_ON == FLSTST_GET_ERRORD_ETAILS_API */

/*************************************************************************/
/*
 * Brief               Service executes a test of ECC hardware. This is 
 *                     only applicable in case the hardware provices 
 *                     such functionality.
 * ServiceId           0x0c
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 * PreCondition        None
 */
/*************************************************************************/
#if((STD_ON == FLSTST_TEST_ECC_API)&&\
((0U != FLSTST_BGND_BLOCK_NUM)||(0U != FLSTST_FGND_BLOCK_NUM)))
extern Std_ReturnType FlsTst_TestEcc (void);
#endif /* STD_ON == FLSTST_TEST_ECC_API */

/*************************************************************************/
/*
 * Brief               Service for executing the Flash Test in background 
 *                     mode.
 * ServiceId           0x0d
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 */
/*************************************************************************/
#if(0U != FLSTST_BGND_BLOCK_NUM)
extern void FlsTst_MainFunction(void);
#endif

#endif 
