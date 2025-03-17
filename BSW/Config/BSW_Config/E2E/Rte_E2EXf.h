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
**  FILENAME    : Rte_E2EXf.h                                                 **
**                                                                            **
**  Created on  : 2024/04/22 11:37:58                                         **
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
 ******************************************************************************/
#ifndef E2EXF_H_
#define E2EXF_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_E2EXf_Cfg.h"
#include "Rte_E2EXf_LCfg.h"
#include "Rte_Xf_Cfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define E2EXF_CONST
#define E2EXF_CODE
#define E2EXF_VAR_POWER_ON_INIT
#define E2EXF_VAR
#define E2EXF_MODULE_ID                     176u
#define E2EXF_VENDOR_ID                     62u
#define E2EXF_H_AR_RELEASE_MAJOR_VERSION    4u
#define E2EXF_H_AR_RELEASE_MINOR_VERSION    5u
#define E2EXF_H_AR_RELEASE_PATCH_VERSION    0u
#define E2EXF_H_SW_MAJOR_VERSION            2u
#define E2EXF_H_SW_MINOR_VERSION            1u
#define E2EXF_H_SW_PATCH_VERSION            0u
#define E2EXf_INSTANCE_ID   0u
#define E2EXF_GETVERSIONINFO_ID   5u
/* E2EXf service ID */
#define E2EXF_INIT_SERVICEID 0x01u
#define E2EXF_DEINIT_SERVICEID 0x02u
#define E2EXF_TRANSFORMERID_SERVICEID 0x03u
#define E2EXF_INV_TRANSFORMERID_SERVICEID 0x04u
#define E2EXF_GETVERSIONINFO_SERVICEID 0x05u
/* E2EXf error code, Req<SWS_E2EXf_00137> */
#define E2EXF_E_UNINIT            1u
#define E2EXF_E_INIT_FAILED       2u
#define E2EXF_E_PARAM             3u
#define E2EXF_E_PARAM_POINTER     4u
#define E_SAFETY_SOFT_RUNTIMEERROR 0x77u
#define E_SAFETY_HARD_RUNTIMEERROR 0xFFu
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum {
    PROFILE_INDEX_ACTNOFLEDLOBEAM = 0,
    PROFILE_INDEX_ACTVNOFINDCR = 1,
    PROFILE_INDEX_LVLGSWTSETREQ = 2
} ProfileIndex;

typedef union{
    struct{
        uint32 ActnOfLedLoBeamTimeout :1;
        uint32 ActnOfLedLoBeamCntErr  :1;
        uint32 ActnOfLedLoBeamCrcErr  :1;
        uint32 ActvnOfIndcrTimeout    :1;
        uint32 ActvnOfIndcrCntErr     :1;
        uint32 ActvnOfIndcrCrcErr     :1;
        uint32 LvlgSwtSetReqTimeout    :1;
        uint32 LvlgSwtSetReqCntErr     :1;
        uint32 LvlgSwtSetReqCrcErr     :1;
    }bits;
    uint32 E2EErrFlag;
}U_E2EErrorFlag;

typedef struct{
    U_E2EErrorFlag E2EErrorFlagForFailSafe;
    uint8 ActnOfLedLoBeamCrcErrResumeCnt;
    uint8 ActnOfLedLoBeamCounterErrResumeCnt;
    uint8 ActvnOfIndcrCrcErrResumeCnt;
    uint8 ActvnOfIndcrCounterErrResumeCnt;
    uint8 LvlgSwtSetReqCrcErrResumeCnt;
    uint8 LvlgSwtSetReqCounterErrResumeCnt;
}S_E2EStateForFailSafe;

typedef unsigned char  		uint8_t;
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern S_E2EStateForFailSafe gs_E2EStateForFailSafe;
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
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
/* Req<SWS_E2EXf_00036> */
extern FUNC(void, E2EXF_CODE)E2EXf_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif/* STD_ON == E2EXF_VERSION_INFO_API */
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
extern FUNC(void, E2EXF_CODE)
E2EXf_Init
(
    P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_CONST) config
);
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
extern FUNC(void, E2EXF_CODE)
E2EXf_DeInit(void);

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
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
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_igActnOfLedLoBeam   /* PRQA S 0777 */ /* MISRA Rule 1.3,5.1 */
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,/* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,/* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
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
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_igActvnOfIndcr      /* PRQA S 0777 */ /* MISRA Rule 1.3,5.1 */
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,/* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,/* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);



/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
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
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_igLvlgSwtSetReq   /* PRQA S 0777 */ /* MISRA Rule 1.3,5.1 */
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,/* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,/* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);

static FUNC(void, E2EXF_CODE) E2EXf_SMConfigDataInitCommon(uint8 profileIndex, E2E_SMCheckStateType *checkState, E2E_SMConfigType *configData);
void RTE_COM_E2E_ZcudZcud_Lin2Fr01_Handle(uint8 *Lin_SduPtr);
void RTE_COM_E2E_ZcudZcud_Lin2Fr02_Handle(uint8 *Lin_SduPtr);
void Rte_COMCbk_igActnOfLedLoBeam(uint8 *Lin_SduPtr);
void Rte_COMCbk_igActvnOfIndcr(uint8* Lin_SduPtr);
void Rte_COMCbk_igLvlgSwtSetReq(uint8 *Lin_SduPtr);
U_E2EErrorFlag Rbk_U_E2EErrorFlag(void);
#endif/* E2EXF_H_ */

