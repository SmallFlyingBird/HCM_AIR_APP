/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Rte_E2EXf.c                                                 **
**                                                                            **
**  Created on  : 2024/04/10 11:04:11                                         **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>     <DATE>       <AUTHOR>       <REVISION LOG>
 *  V1.0.0       20200610     Wanglili       Initial version
 *  V1.0.1       20201130     Wanglili       QAC check version and bug fix
 *  V1.0.2       20201217     Wanglili
 *  1.modify the scenarios when multiple signals use the same technology.
 *  2.rename the E2EXf_PBCfg and E2EXf_PBCfg.h to E2EXf_Lcfg.c and E2EXf_Lcfg.h.
 *  3.In E2EXf_SMConfigDataInit_E2ETransformerXX:the size of window should be
 *  configuration parameter WindowSizeValid.
 *    V1.0.3       20210527     Wanglili
 *    1.Modify the processing of each profile using upperheader
 ******************************************************************************/
 /**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:Tcp<br>
  RuleSorce:puhua-rule.rcf 2.3.1

   \li PRQA S 0779 MISRA Rule 1.3, Rule 5.2 .<br>
    Reason:Since the variable name is dynamically generated, the previous name
       is consistent.

    \li PRQA S 0777 MISRA Rule 1.3, Rule 5.2 .<br>
    Reason:Since the variable name is dynamically generated, the previous name
        is consistent.

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:The company compiles abstract macro definitions where data types
       cannot be enclosed in parentheses.

    \li PRQA S 0791 MISRA Rule 5.4 .<br>
    Reason: According to the segment name definition rules of the autosar specification, segment names may be
            very long and only a few characters may differ between segment names.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define E2EXF_C_AR_RELEASE_MAJOR_VERSION  4u
#define E2EXF_C_AR_RELEASE_MINOR_VERSION  5u
#define E2EXF_C_AR_RELEASE_PATCH_VERSION  0u
#define E2EXF_C_SW_MAJOR_VERSION  2u
#define E2EXF_C_SW_MINOR_VERSION  1u
#define E2EXF_C_SW_PATCH_VERSION  0u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* PRQA S 0779 ++ */ /* MISRA Rule 1.3,Rule 5.2 */
/* @Req<SWS_E2EXf_00047> */
#include "Rte_E2EXf.h"
#include "DTC_Interface.h"
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
#include "Det.h"
#endif/*STD_ON == E2EXF_DEV_ERROR_DETECT*/
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (E2EXF_C_AR_RELEASE_MAJOR_VERSION != E2EXF_H_AR_RELEASE_MAJOR_VERSION)
  #error "Rte_E2EXf.c : Mismatch in Specification Major Version"
#endif
#if (E2EXF_C_AR_RELEASE_MINOR_VERSION != E2EXF_H_AR_RELEASE_MINOR_VERSION)
  #error "Rte_E2EXf.c : Mismatch in Specification _MINOR Version"
#endif
#if (E2EXF_C_AR_RELEASE_PATCH_VERSION != E2EXF_H_AR_RELEASE_PATCH_VERSION)
  #error "Rte_E2EXf.c : Mismatch in Specification PATCH Version"
#endif
#if (E2EXF_C_SW_MAJOR_VERSION != E2EXF_H_SW_MAJOR_VERSION)
  #error "Rte_E2EXf.c : Mismatch in Software Major Version"
#endif
#if (E2EXF_C_SW_MINOR_VERSION != E2EXF_H_SW_MINOR_VERSION)
  #error "Rte_E2EXf.c : Mismatch in Software MINOR Version"
#endif
#if (E2EXF_C_SW_PATCH_VERSION != E2EXF_H_SW_PATCH_VERSION)
  #error "Rte_E2EXf.c : Mismatch in Software PATCH Version"
#endif
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*used to mark disable the action of E2E check*/
#define E2EXf_DISCHECK  2u
#define PROFILE_01_0_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_0_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_01_1_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_1_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_01_2_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_2_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static FUNC(void, E2EXF_CODE)E2EXf_ConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML(void);
static FUNC(void, E2EXF_CODE)E2EXf_ConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML(void);
static FUNC(void, E2EXF_CODE)E2EXf_ConfigDataInit_E2ETransformer_LvlgSwtSetReq_BGM_HCML(void);
static FUNC(void, E2EXF_CODE)E2EXf_SMConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML(void);
static FUNC(void, E2EXF_CODE)E2EXf_SMConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML(void);
static FUNC(void, E2EXF_CODE)E2EXf_SMConfigDataInit_E2ETransformer_LvlgSwtSetReq_BGM_HCML(void);
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define RTE_E2EXF_START_SEC_VAR_CLEARED_BOOLEAN
#include "Rte_E2EXf_MemMap.h"
/* represent E2EXf init or not */
static VAR(boolean, E2EXF_VAR_POWER_ON_INIT) E2EXf_InitFlag = FALSE;
#define RTE_E2EXF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED/* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Rte_E2EXf_MemMap.h"
/* @Req<SWS_E2EXf_00126> */
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML;
static VAR(E2E_PCheckStatusType, E2EXF_VAR)  E2E_PCheckStatus;
#define RTE_E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED      /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Rte_E2EXf_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
S_E2EStateForFailSafe gs_E2EStateForFailSafe;
#define RTE_E2EXF_START_SEC_VAR_INIT_PTR
#include "Rte_E2EXf_MemMap.h"
static P2CONST(E2EXf_ConfigType, E2E_CONST_UNSPECIFIED, E2EXF_CONST) E2EXf_ConfigPtr = NULL_PTR;
#define RTE_E2EXF_STOP_SEC_VAR_INIT_PTR
#include "Rte_E2EXf_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               This service initializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* <SWS_E2EXf_00035> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE)
E2EXf_Init
(
    P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_CONST) config
)
{
    if(NULL_PTR == config)
    {
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INIT_SERVICEID, E2EXF_E_PARAM_POINTER);
        #endif/*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        E2EXf_InitFlag = FALSE;
    }
    else
    {
        Std_ReturnType initRet =E_OK;
        E2EXf_ConfigPtr = config;
        /* @Req<SWS_E2EXf_00021> */        

        E2EXf_ConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML();
        E2EXf_ConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML();
        E2EXf_ConfigDataInit_E2ETransformer_LvlgSwtSetReq_BGM_HCML();

        E2EXf_SMConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML();
        E2EXf_SMConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML();
        E2EXf_SMConfigDataInit_E2ETransformer_LvlgSwtSetReq_BGM_HCML();

        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML);
        }
        if(E_OK == initRet)
        {/* ActvnOfIndcr */
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML);
        }
        
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML);
        }
        if(E_OK == initRet)
        {/* ActvnOfIndcr */
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML,&E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML,&E2EXf_SMConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            /* @Req<SWS_E2EXf_00130> */
            E2EXf_InitFlag = TRUE;
        }
      }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               This service deinitializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* <SWS_E2EXf_00138> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE)
E2EXf_DeInit(void)
{
    /* @Req<SWS_E2EXf_00148> */
    if(TRUE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00132> */
        E2EXf_InitFlag = FALSE;
        E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.SMState = E2E_SM_DEINIT;
    }
    else
    {
        /* @Req<SWS_E2EXf_00137>, <SWS_E2EXf_00146> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_DEINIT_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

#if (STD_ON == E2EXF_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service returns the version information of
 *                     this module
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Versioninfo: Pointer to where to store the version
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00036> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
void E2EXf_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if (NULL_PTR == (VersionInfo))
    {
        /* @Req<SWS_E2EXf_00149> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_GETVERSIONINFO_ID, E2EXF_E_PARAM_POINTER);
        #endif/*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        /*do nothing*/
    }
    else
    {
        (VersionInfo)->vendorID = E2EXF_VENDOR_ID;
        (VersionInfo)->moduleID = E2EXF_MODULE_ID;
        (VersionInfo)->sw_major_version = E2EXF_C_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = E2EXF_C_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = E2EXF_C_SW_PATCH_VERSION;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#endif/* STD_ON == E2EXF_VERSION_INFO_API */



/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_igActnOfLedLoBeam
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u);
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        boolean profileBehavior;
        /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGACTNOFLEDLOBEAM)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_3_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_3_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_3_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_3_HEADERLENGTH_DIV8) + (PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_0_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_0_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,inputBuffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer))
            {
                uint16 shiftLen = (PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_0_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;
                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_0_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_igActvnOfIndcr
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u);
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        boolean profileBehavior;
        /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGACTVNOFINDCR)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_1_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_1_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_1_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_1_HEADERLENGTH_DIV8) + (PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_1_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_1_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML,inputBuffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer))
            {
                uint16 shiftLen = (PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_1_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;
                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML,&E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_1_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_igLvlgSwtSetReq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_2_UPPERHEADERBITSTOSHIFT >> 3u);
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        boolean profileBehavior;
        /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGACTNOFLEDLOBEAM)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_3_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_3_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_3_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_3_HEADERLENGTH_DIV8) + (PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_2_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_2_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_2_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML,&E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML,&E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML,inputBuffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer))
            {
                uint16 shiftLen = (PROFILE_01_2_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_2_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;
                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML,&E2EXf_SMCheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_2_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/    
/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0];
    E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
    }
}
/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1];
    E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_1_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"


/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_LvlgSwtSetReq_BGM_HCML(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2];
    E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_2_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"



/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML(void)
{
    E2EXf_SMConfigDataInitCommon(PROFILE_INDEX_ACTNOFLEDLOBEAM, 
                                 &E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML, 
                                 &E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML);
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML(void)
{
    E2EXf_SMConfigDataInitCommon(PROFILE_INDEX_ACTVNOFINDCR, 
                                 &E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML, 
                                 &E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML);
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"


/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_LvlgSwtSetReq_BGM_HCML(void)
{
    E2EXf_SMConfigDataInitCommon(PROFILE_INDEX_LVLGSWTSETREQ, 
                                 &E2EXf_SMCheckState_E2ETransformer_LvlgSwtSetReq_BGM_HCML, 
                                 &E2EXf_SMConfigData_E2ETransformer_LvlgSwtSetReq_BGM_HCML);
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

static FUNC(void, E2EXF_CODE) E2EXf_SMConfigDataInitCommon(uint8 profileIndex, E2E_SMCheckStateType* checkState, E2E_SMConfigType* configData) {
    if (NULL_PTR == E2EXf_ConfigPtr) {
        return; // Handle NULL pointer case
    }

    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[profileIndex];

    checkState->ProfileStatusWindow = window;
    checkState->SMState = E2E_SM_DEINIT;

    if (NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps) {
        configData->WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        configData->WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        configData->WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        configData->ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        configData->MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        configData->MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        configData->MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        configData->MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        configData->MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        configData->MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    } else {
        configData->WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        configData->WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        configData->WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        configData->ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        configData->MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        configData->MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        configData->MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        configData->MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        configData->MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        configData->MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
void RTE_COM_E2E_ZcudZcud_Lin2Fr01_Handle(uint8* Lin_SduPtr)
{
    Rte_COMCbk_igActnOfLedLoBeam(Lin_SduPtr);
    Rte_COMCbk_igActvnOfIndcr(Lin_SduPtr);
}

void RTE_COM_E2E_ZcudZcud_Lin2Fr02_Handle(uint8* Lin_SduPtr)
{
    Rte_COMCbk_igLvlgSwtSetReq(Lin_SduPtr);
}

void Rte_COMCbk_igActnOfLedLoBeam(uint8* Lin_SduPtr)
{
    Std_ReturnType ret = E_NOT_OK;
	uint8 inputData[3] = {0};
	uint32 inputLength = 3;
	uint32 outputLength;
	uint8 outputData[3] = {0};
    Std_ReturnType Ret = E2E_E_OK;


    /* ActnOfLedLoBeamChks */
    inputData[0] = Lin_SduPtr[3];

    /* ActnOfLedLoBeamCntr */
    inputData[1] = Lin_SduPtr[4] & 0x0F;

    /* ActnOfLedLoBeamActnOfLedLoBeam */
    inputData[2] = Lin_SduPtr[2] & 0x01;

    ret = E2EXf_Inv_igActnOfLedLoBeam(outputData, &outputLength, inputData, inputLength);

    /* clear timeout */
    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamTimeout=0;

    
    if (E2E_P_OK == (ret & 0x0F))
	{
		/*E2E_P_OK*/

        // Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CounterError, 0);
        // Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CrcError, 0);

        if(gs_E2EStateForFailSafe.ActnOfLedLoBeamCounterErrResumeCnt >0)
            gs_E2EStateForFailSafe.ActnOfLedLoBeamCounterErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCntErr=0;

        if(gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr=0;
	}
    else
    {

    }
	if (E2E_P_REPEATED == (ret & 0x0F))
	{
		/*E2E_P_REPEATED*/
        gs_E2EStateForFailSafe.ActnOfLedLoBeamCounterErrResumeCnt =2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCntErr=1;

        //Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CounterError, 1);

        /*clear CRC error*/
        if(gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr=0;

        //Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CrcError, 0);

	}
	if (E2E_P_WRONGSEQUENCE == (ret & 0x0F))
	{
		/*E2E_P_WRONGSEQUENCE*/
	}
	if (E2E_P_ERROR == (ret & 0x0F))
	{
		/*E2E_P_CRCERROR*/
        gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt=2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr=1;
        //Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CrcError, 1);
	}

}

void Rte_COMCbk_igActvnOfIndcr(uint8* Lin_SduPtr)
{
    Std_ReturnType ret = E_NOT_OK;
	uint8 inputData[3] = {0};
	uint32 inputLength = 3;
	uint32 outputLength;
	uint8 outputData[3] = {0};
    Std_ReturnType Ret = E2E_E_OK;


    /* ActvnOfIndcrChks */
    inputData[0] = Lin_SduPtr[6];

    /* ActvnOfIndcrCntr */
    inputData[1] = (Lin_SduPtr[5] & 0x3C) >> 2;

    /* ActvnOfIndcr */
    inputData[2] = (Lin_SduPtr[2] & 0xC0) >> 6;

    ret = E2EXf_Inv_igActvnOfIndcr(outputData, &outputLength, inputData, inputLength);

    /* clear timeout */
    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrTimeout=0;

    if (E2E_P_OK == (ret & 0x0F))
	{
		/*E2E_P_OK*/

        // Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CounterError, 0);
        // Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CrcError, 0);

        if(gs_E2EStateForFailSafe.ActvnOfIndcrCounterErrResumeCnt >0)
            gs_E2EStateForFailSafe.ActvnOfIndcrCounterErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCntErr=0;

        if(gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCrcErr=0;
	}
	if (E2E_P_REPEATED == (ret & 0x0F))
	{
		/*E2E_P_REPEATED*/
        gs_E2EStateForFailSafe.ActvnOfIndcrCounterErrResumeCnt =2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCntErr=1;

        // Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CounterError, 1);

        /*clear CRC error*/
        if(gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCrcErr=0;

        //Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CrcError, 0);

	}
	if (E2E_P_WRONGSEQUENCE == (ret & 0x0F))
	{
		/*E2E_P_WRONGSEQUENCE*/
	}
	if (E2E_P_ERROR == (ret & 0x0F))
	{
		/*E2E_P_CRCERROR*/
        gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt=2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr=1;
        //Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CrcError, 1);
	}
}

void Rte_COMCbk_igLvlgSwtSetReq(uint8* Lin_SduPtr)
{
	Std_ReturnType ret;
	uint32 SignalValue;
    uint8_t DataSrc[2];
    uint8_t crc;
    uint8_t crc_tmp;
    
    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqTimeout=0;
	if (ret == E_OK)
	{
        
        DataSrc[0] = Lin_SduPtr[1] & 0x0F;

        DataSrc[1] = (Lin_SduPtr[1] & 0x70 ) >> 4;
        
        crc = Lin_SduPtr[0];

        if(1)//(Interface_GetLvlgSwtSetReq_CRC_Detect_Flag() == 1)
        {
            crc_tmp = Crc_CalculateCRC8((uint8 *)DataSrc, 3, 0xFF, FALSE);
            if(crc == crc_tmp)
            {
                //Interface_SetDtcE2EError(E_E2EErrorType_LvlgSwtSetReq_ChksError, 0);
                if(gs_E2EStateForFailSafe.LvlgSwtSetReqCrcErrResumeCnt>0)
                    gs_E2EStateForFailSafe.LvlgSwtSetReqCrcErrResumeCnt--;
                else
                    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqCrcErr=0;
            }           
            else
            {
                //Interface_SetDtcE2EError(E_E2EErrorType_LvlgSwtSetReq_ChksError, 1);
                gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqCrcErr=1;
                gs_E2EStateForFailSafe.LvlgSwtSetReqCrcErrResumeCnt=2;
            }

        }
	}
}
/* PRQA S 0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */
