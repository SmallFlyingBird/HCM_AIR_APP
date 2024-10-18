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
#define PROFILE_01_3_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_3_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_01_4_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_4_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_01_5_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_5_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_01_6_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_6_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_01_7_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_7_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_VehSpdLgt_BCM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_OutdBri_RLSM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_SteerWhlSnsr(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_AccrPedlRat(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_BrkPedlSnsr(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_VehSpdLgt_BCM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_OutdBri_RLSM_HCML(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_SteerWhlSnsr(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_AccrPedlRat(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_BrkPedlSnsr(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
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
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_AccrPedlRat;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_AccrPedlRat;
static VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_SteerWhlSnsr;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_AccrPedlRat;
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_BrkPedlSnsr;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_VehSpdLgt_BCM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_OutdBri_RLSM_HCML;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_SteerWhlSnsr;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_AccrPedlRat;
static VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_BrkPedlSnsr;
static VAR(E2E_PCheckStatusType, E2EXF_VAR)  E2E_PCheckStatus;
#define RTE_E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED      /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Rte_E2EXf_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

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
        E2EXf_ConfigDataInit_E2ETransformer_VehSpdLgt_BCM_HCML();
        E2EXf_ConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML();
        E2EXf_ConfigDataInit_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML();
        E2EXf_ConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML();
        E2EXf_ConfigDataInit_E2ETransformer_OutdBri_RLSM_HCML();
        E2EXf_ConfigDataInit_E2ETransformer_SteerWhlSnsr();
        E2EXf_ConfigDataInit_E2ETransformer_AccrPedlRat();
        E2EXf_ConfigDataInit_E2ETransformer_BrkPedlSnsr();
        E2EXf_SMConfigDataInit_E2ETransformer_VehSpdLgt_BCM_HCML();
        E2EXf_SMConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML();
        E2EXf_SMConfigDataInit_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML();
        E2EXf_SMConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML();
        E2EXf_SMConfigDataInit_E2ETransformer_OutdBri_RLSM_HCML();
        E2EXf_SMConfigDataInit_E2ETransformer_SteerWhlSnsr();
        E2EXf_SMConfigDataInit_E2ETransformer_AccrPedlRat();
        E2EXf_SMConfigDataInit_E2ETransformer_BrkPedlSnsr();
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_SteerWhlSnsr);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_AccrPedlRat);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_BrkPedlSnsr);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_VehSpdLgt_BCM_HCML,&E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML,&E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_OutdBri_RLSM_HCML,&E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_SteerWhlSnsr,&E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_AccrPedlRat,&E2EXf_SMConfigData_E2ETransformer_AccrPedlRat);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_BrkPedlSnsr,&E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr);
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
        E2EXf_SMCheckState_E2ETransformer_VehSpdLgt_BCM_HCML.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_OutdBri_RLSM_HCML.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_SteerWhlSnsr.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_AccrPedlRat.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_BrkPedlSnsr.SMState = E2E_SM_DEINIT;
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
E2EXf_Inv_igVehSpdLgt
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
            E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGVEHSPDLGT)
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
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_0_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u))))) )
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
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML,&E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML,&E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_0_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_0_HEADERLENGTH_DIV8) + (PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
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
                    E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML,&E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML,&E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML,inputBuffer);
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
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_VehSpdLgt_BCM_HCML.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML,&E2EXf_SMCheckState_E2ETransformer_VehSpdLgt_BCM_HCML) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_VehSpdLgt_BCM_HCML.SMState) << 4u;
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
E2EXf_Inv_igVehModMngtGlbSafe1
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
            E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGVEHMODMNGTGLBSAFE1)
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
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_2_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_2_UPPERHEADERBITSTOSHIFT >> 3u))))) )
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
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_2_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_2_HEADERLENGTH_DIV8) + (PROFILE_01_2_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_2_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
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
                    E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,inputBuffer);
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
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML,&E2EXf_SMCheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.SMState) << 4u;
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
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u);
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
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfTechnology->E2EXfDescription->profileBehavior)
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
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_3_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u)))) )
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
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&E2EXf_CheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3].E2EXfISignalProps->dataLength >> 3u))
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
                uint16 shiftLen = (PROFILE_01_3_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_3_HEADERLENGTH_DIV8) + shiftLen;
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
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_3_HEADERLENGTH_DIV8);
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
E2EXf_Inv_igOutdBri
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_4_UPPERHEADERBITSTOSHIFT >> 3u);
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
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGOUTDBRI)
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
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_4_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_4_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_4_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML,&E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML,&E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_4_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_4_HEADERLENGTH_DIV8) + (PROFILE_01_4_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_4_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
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
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_4_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_4_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_4_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML,&E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML,&E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML,inputBuffer);
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
                uint16 shiftLen = (PROFILE_01_4_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_4_HEADERLENGTH_DIV8) + shiftLen;
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
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_OutdBri_RLSM_HCML.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML,&E2EXf_SMCheckState_E2ETransformer_OutdBri_RLSM_HCML) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_OutdBri_RLSM_HCML.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_4_HEADERLENGTH_DIV8);
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
E2EXf_Inv_igSteerWhlSnsr
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_5_UPPERHEADERBITSTOSHIFT >> 3u);
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
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_SteerWhlSnsr.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGSTEERWHLSNSR)
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
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_5_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_5_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_5_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_SteerWhlSnsr.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr,&E2EXf_CheckState_E2ETransformer_SteerWhlSnsr,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_SteerWhlSnsr.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_SteerWhlSnsr.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr,&E2EXf_CheckState_E2ETransformer_SteerWhlSnsr,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_5_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_5_HEADERLENGTH_DIV8) + (PROFILE_01_5_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_5_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
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
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_5_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_5_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_5_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_SteerWhlSnsr.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr,&E2EXf_CheckState_E2ETransformer_SteerWhlSnsr,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_SteerWhlSnsr.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr,&E2EXf_CheckState_E2ETransformer_SteerWhlSnsr,inputBuffer);
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
                uint16 shiftLen = (PROFILE_01_5_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_5_HEADERLENGTH_DIV8) + shiftLen;
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
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_SteerWhlSnsr.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr,&E2EXf_SMCheckState_E2ETransformer_SteerWhlSnsr) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_SteerWhlSnsr.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_5_HEADERLENGTH_DIV8);
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
E2EXf_Inv_igAccrPedlRat
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_6_UPPERHEADERBITSTOSHIFT >> 3u);
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
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_AccrPedlRat.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_AccrPedlRat.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGACCRPEDLRAT)
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
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_6_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_6_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_6_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_AccrPedlRat.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_AccrPedlRat,&E2EXf_CheckState_E2ETransformer_AccrPedlRat,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_AccrPedlRat.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_AccrPedlRat.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_AccrPedlRat.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_AccrPedlRat,&E2EXf_CheckState_E2ETransformer_AccrPedlRat,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_6_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_6_HEADERLENGTH_DIV8) + (PROFILE_01_6_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_6_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
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
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_6_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_6_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_6_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_AccrPedlRat.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_AccrPedlRat,&E2EXf_CheckState_E2ETransformer_AccrPedlRat,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_AccrPedlRat.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_AccrPedlRat,&E2EXf_CheckState_E2ETransformer_AccrPedlRat,inputBuffer);
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
                uint16 shiftLen = (PROFILE_01_6_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_6_HEADERLENGTH_DIV8) + shiftLen;
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
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_AccrPedlRat.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_AccrPedlRat,&E2EXf_SMCheckState_E2ETransformer_AccrPedlRat) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_AccrPedlRat.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_6_HEADERLENGTH_DIV8);
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
E2EXf_Inv_igBrkPedlSnsr
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,  /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_7_UPPERHEADERBITSTOSHIFT >> 3u);
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
        if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_BrkPedlSnsr.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
        #if (STD_ON == IN_PLACE_IGBRKPEDLSNSR)
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
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_01_7_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_7_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_7_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_BrkPedlSnsr.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr,&E2EXf_CheckState_E2ETransformer_BrkPedlSnsr,&bufTemp);

                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_BrkPedlSnsr.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if(PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_BrkPedlSnsr.MaxDeltaCounter = E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr,&E2EXf_CheckState_E2ETransformer_BrkPedlSnsr,buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_7_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_7_HEADERLENGTH_DIV8) + (PROFILE_01_7_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_7_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
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
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_01_7_HEADERLENGTH_DIV8) + ((uint32)PROFILE_01_7_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_7_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp = 0;
                    E2EXf_CheckState_E2ETransformer_BrkPedlSnsr.NewDataAvailable = FALSE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr,&E2EXf_CheckState_E2ETransformer_BrkPedlSnsr,&bufTemp);
                }
                else if(E2E_dataLength == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_BrkPedlSnsr.NewDataAvailable = TRUE;
                    checkRet = E2E_P01Check(&E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr,&E2EXf_CheckState_E2ETransformer_BrkPedlSnsr,inputBuffer);
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
                uint16 shiftLen = (PROFILE_01_7_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len = (PROFILE_01_7_HEADERLENGTH_DIV8) + shiftLen;
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
            E2E_PCheckStatus = E2E_P01MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_BrkPedlSnsr.Status,profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr,&E2EXf_SMCheckState_E2ETransformer_BrkPedlSnsr) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_BrkPedlSnsr.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_7_HEADERLENGTH_DIV8);
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
E2EXf_ConfigDataInit_E2ETransformer_VehSpdLgt_BCM_HCML(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0];
    E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
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
E2EXf_ConfigDataInit_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2];
    E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_2_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
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
E2EXf_ConfigDataInit_E2ETransformer_ActnOfLedLoBeam_BGM_HCML(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3];
    E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_3_UPPERHEADERBITSTOSHIFT;
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
E2EXf_ConfigDataInit_E2ETransformer_OutdBri_RLSM_HCML(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4];
    E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_4_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
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
E2EXf_ConfigDataInit_E2ETransformer_SteerWhlSnsr(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5];
    E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_5_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_SteerWhlSnsr.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
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
E2EXf_ConfigDataInit_E2ETransformer_AccrPedlRat(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6];
    E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_6_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_AccrPedlRat.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_AccrPedlRat.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_AccrPedlRat.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
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
E2EXf_ConfigDataInit_E2ETransformer_BrkPedlSnsr(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7];
    E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataID = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataLength = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength + PROFILE_01_7_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.CounterOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.CRCOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataIDNibbleOffset = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if(NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.MaxDeltaCounterInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.MaxNoNewOrRepeatedData = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.SyncCounterInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_BrkPedlSnsr.MaxDeltaCounterInit =(uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter -1u;
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
E2EXf_SMConfigDataInit_E2ETransformer_VehSpdLgt_BCM_HCML(void)
{
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0];
    E2EXf_SMCheckState_E2ETransformer_VehSpdLgt_BCM_HCML.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_VehSpdLgt_BCM_HCML.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehSpdLgt_BCM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
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
E2EXf_SMConfigDataInit_E2ETransformer_ActvnOfIndcr_BGM_HCML(void)
{
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1];
    E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_ActvnOfIndcr_BGM_HCML.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActvnOfIndcr_BGM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
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
E2EXf_SMConfigDataInit_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML(void)
{
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[2];
    E2EXf_SMCheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_VehModMngtGlbSafe1_BGM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
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
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[3];
    E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_ActnOfLedLoBeam_BGM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
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
E2EXf_SMConfigDataInit_E2ETransformer_OutdBri_RLSM_HCML(void)
{
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[4];
    E2EXf_SMCheckState_E2ETransformer_OutdBri_RLSM_HCML.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_OutdBri_RLSM_HCML.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_OutdBri_RLSM_HCML.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
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
E2EXf_SMConfigDataInit_E2ETransformer_SteerWhlSnsr(void)
{
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[5];
    E2EXf_SMCheckState_E2ETransformer_SteerWhlSnsr.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_SteerWhlSnsr.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_SteerWhlSnsr.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
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
E2EXf_SMConfigDataInit_E2ETransformer_AccrPedlRat(void)
{
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[6];
    E2EXf_SMCheckState_E2ETransformer_AccrPedlRat.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_AccrPedlRat.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_AccrPedlRat.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
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
E2EXf_SMConfigDataInit_E2ETransformer_BrkPedlSnsr(void)
{
    static uint8 window[1];
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[7];
    E2EXf_SMCheckState_E2ETransformer_BrkPedlSnsr.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_BrkPedlSnsr.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.WindowSizeInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.WindowSizeValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.WindowSizeInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.ClearToInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MinOkStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MaxErrorStateInit = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MinOkStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MinOkStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MaxErrorStateValid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_BrkPedlSnsr.MaxErrorStateInvalid = E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
/* PRQA S 0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */
