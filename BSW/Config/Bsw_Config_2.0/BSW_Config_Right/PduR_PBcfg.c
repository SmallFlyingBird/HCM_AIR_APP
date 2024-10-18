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
**  FILENAME    : PduR_PBcfg.c                                                **
**                                                                            **
**  Created on  : 2024/05/10 11:01:44                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "CanIf.h"
#include "CanTp.h"
#include "Com_Cbk.h"
#include "Dcm.h"
#include "Dcm_Cbk.h"
#include "CanNm.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_PBCFG_C_AR_MAJOR_VERSION  4u
#define PDUR_PBCFG_C_AR_MINOR_VERSION  2u
#define PDUR_PBCFG_C_AR_PATCH_VERSION  2u

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PDUR_PBCFG_C_AR_MAJOR_VERSION != PDUR_PBCFG_H_AR_MAJOR_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_PBCFG_C_AR_MINOR_VERSION != PDUR_PBCFG_H_AR_MINOR_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_PBCFG_C_AR_PATCH_VERSION != PDUR_PBCFG_H_AR_PATCH_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRDestPduType,PDUR_CONST)
PduR_DestPduConfigData[PDUR_DEST_PDU_SUM] =
{
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu01,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu01,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu02,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu02,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU04,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU04,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU04,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU05,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU05,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU06,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU06,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU07,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU07,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU07,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU08,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU08,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU08,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu09,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu09,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu09,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu10,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu10,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu10,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu11,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu11,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu11,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu12,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu12,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu12,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu13,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu13,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu14,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu14,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu14,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu15,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu15,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu15,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu16,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu16,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu16,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu17,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu17,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu17,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu18,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu18,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu19,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu19,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu20,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu20,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu21,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu21,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu21,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu22,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu22,
        COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu22,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu01,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu01,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu01,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu25,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu25,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu25,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu42,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu42,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu42,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu45,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu45,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu45,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu50,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu50,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu50,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu51,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu51,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu51,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu59,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu59,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu59,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu67,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu67,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu67,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu115,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu115,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu115,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu116,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu116,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu116,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_HcmlBodyExpoSignalIPDU02,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU02,
        CANIF_TXPDU_HcmlBodyExpoSignalIPDU02,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_HcmlBodyExpoSignalIPDU04,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU04,
        CANIF_TXPDU_HcmlBodyExpoSignalIPDU04,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VgmToHcmlDiagDcmIpdu,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CanTp_Rx_Phy,
        DCM_VgmToHcmlDiagDcmIpdu,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VgmToAllFuncDiagDcmIpdu,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CanTp_Rx_Fun,
        DCM_VgmToAllFuncDiagDcmIpdu,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CanTp_Tx,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HcmlToVgmDiagDcmIpdu,
        CANTP_CanTp_Tx,
        PDUR_CANTP,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ComCanNmEiraRxPdu,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        FALSE,
        PDUR_SRCPDU_CanNmEiraRxPdu,
        COM_RXPDU_ComCanNmEiraRxPdu,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ComCanNmEraRxPdu_BodyExposedCAN_HCML,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        FALSE,
        PDUR_SRCPDU_CanNmEraRxPdu_BodyExposedCAN_HCML,
        COM_RXPDU_ComCanNmEraRxPdu_BodyExposedCAN_HCML,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CanNmUserDataTxPdu_BodyExposedCAN_HCML,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML,
        CANNM_USER_TX_PDU_0,
        PDUR_CANNM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu07,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu07,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu07,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu100,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu100,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu100,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu101,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu101,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu101,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu102,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu102,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu102,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu103,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu103,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu103,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu104,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu104,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu104,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu105,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu105,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu105,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu106,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu106,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu106,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu107,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu107,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu107,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu108,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu108,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu108,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu109,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu109,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu109,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu110,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu110,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu110,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu111,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu111,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu111,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu112,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu112,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu112,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu113,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu113,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu113,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu114,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu114,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu114,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu29,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu29,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu29,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu31,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu31,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu31,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu33,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu33,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu33,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu35,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu35,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu35,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu37,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu37,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu37,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu38,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu38,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu38,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu61,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu61,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu61,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu66,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu66,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu66,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu91,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu91,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu91,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu92,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu92,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu92,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu93,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu93,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu93,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu94,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu94,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu94,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu95,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu95,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu95,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu96,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu96,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu96,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu97,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu97,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu97,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu98,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu98,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu98,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu99,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu99,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu99,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRSrcPduType,PDUR_CONST)
PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu01,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu02,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU04,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU04,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU05,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU06,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU07,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU07,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU08,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU08,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu09,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu09,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu10,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu10,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu11,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu11,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu12,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu12,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu13,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu14,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu14,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu15,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu15,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu16,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu16,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu17,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu17,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu18,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu19,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu20,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu21,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu21,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu22,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu22,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu01,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu01,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu25,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu25,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu42,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu42,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu45,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu45,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu50,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu50,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu51,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu51,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu59,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu59,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu67,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu67,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu115,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu115,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu116,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu116,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU02,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_HcmlBodyExpoSignalIPDU02,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU04,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_HcmlBodyExpoSignalIPDU04,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_CanTp_Rx_Phy,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CanTp_Rx_Phy,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_CanTp_Rx_Fun,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CanTp_Rx_Fun,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_HcmlToVgmDiagDcmIpdu,
        TRUE,
        PDUR_UNUSED_UINT16,
        DCM_HcmlToVgmDiagDcmIpdu,
        PDUR_DCM,

    },
    {
        PDUR_SRCPDU_CanNmEiraRxPdu,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANNM_PNEIRARXNSDU,
        PDUR_CANNM,

    },
    {
        PDUR_SRCPDU_CanNmEraRxPdu_BodyExposedCAN_HCML,
        TRUE,
        PDUR_UNUSED_UINT16,
        BODYEXPOSEDCANNMCLUSTER_CANNMERARXPDU_BODYEXPOSEDCAN_HCML,
        PDUR_CANNM,

    },
    {
        PDUR_SRCPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu07,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu07,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu100,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu100,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu101,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu101,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu102,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu102,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu103,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu103,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu104,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu104,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu105,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu105,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu106,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu106,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu107,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu107,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu108,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu108,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu109,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu109,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu110,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu110,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu111,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu111,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu112,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu112,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu113,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu113,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu114,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu114,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu29,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu29,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu31,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu31,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu33,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu33,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu35,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu35,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu37,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu37,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu38,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu38,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu61,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu61,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu66,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu66,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu91,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu91,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu92,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu92,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu93,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu93,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu94,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu94,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu95,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu95,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu96,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu96,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu97,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu97,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu98,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu98,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu99,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu99,
        PDUR_CANIF,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

/* PRQA S 0779,0779 ++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu01[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu01,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu02[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu02,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU04[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU04,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU05[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU05,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU06[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU06,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU07[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU07,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU08[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU08,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu09[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu09,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu10[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu10,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu11[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu11,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu12[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu12,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu13[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu13,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu14[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu14,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu15[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu15,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu16[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu16,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu17[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu17,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu18[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu18,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu19[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu19,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu20[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu20,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu21[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu21,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu22[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu22,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu01[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu01,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu25[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu25,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu42[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu42,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu45[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu45,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu50[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu50,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu51[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu51,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu59[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu59,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu67[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu67,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu115[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu115,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu116[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu116,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HcmlBodyExpoSignalIPDU02[1] =
{
    PDUR_DESTPDU_HcmlBodyExpoSignalIPDU02,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HcmlBodyExpoSignalIPDU04[1] =
{
    PDUR_DESTPDU_HcmlBodyExpoSignalIPDU04,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CANT2DCM_PHY[1] =
{
    PDUR_DESTPDU_VgmToHcmlDiagDcmIpdu,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CANT2DCM_FUN[1] =
{
    PDUR_DESTPDU_VgmToAllFuncDiagDcmIpdu,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_DCM2CANTP[1] =
{
    PDUR_DESTPDU_CanTp_Tx,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CANNM_EIRA_RX[1] =
{
    PDUR_DESTPDU_ComCanNmEiraRxPdu,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CANNM_ERA_RX_BodyExposedCAN_HCML[1] =
{
    PDUR_DESTPDU_ComCanNmEraRxPdu_BodyExposedCAN_HCML,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CANNM_USERDATA_TX_BodyExposedCAN_HCML[1] =
{
    PDUR_DESTPDU_CanNmUserDataTxPdu_BodyExposedCAN_HCML,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu07[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu07,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu100[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu100,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu101[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu101,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu102[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu102,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu103[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu103,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu104[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu104,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu105[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu105,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu106[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu106,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu107[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu107,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu108[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu108,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu109[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu109,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu110[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu110,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu111[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu111,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu112[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu112,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu113[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu113,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu114[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu114,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu29[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu29,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu31[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu31,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu33[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu33,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu35[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu35,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu37[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu37,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu38[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu38,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu61[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu61,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu66[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu66,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu91[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu91,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu92[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu92,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu93[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu93,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu94[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu94,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu95[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu95,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu96[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu96,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu97[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu97,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu98[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu98,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu99[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu99,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
/* PRQA S 0779,0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */
#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingPathType,PDUR_CONST)
PduR_RoutingPathConfigData0[72] =
{
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu01,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu02,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU04,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU04,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU05,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU06,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU07,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU07,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU08,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU08,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu09,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu09,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu10,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu10,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu11,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu11,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu12,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu12,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu13,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu14,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu14,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu15,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu15,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu16,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu16,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu17,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu17,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu18,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu19,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu20,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu21,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu21,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu22,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu22,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu01,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu01,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu25,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu25,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu42,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu42,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu45,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu45,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu50,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu50,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu51,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu51,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu59,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu59,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu67,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu67,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu115,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu115,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu116,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu116,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU02,
        1u,
        PduR_PDUR_ROUTING_HcmlBodyExpoSignalIPDU02,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU04,
        1u,
        PduR_PDUR_ROUTING_HcmlBodyExpoSignalIPDU04,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CanTp_Rx_Phy,
        1u,
        PduR_PDUR_ROUTING_CANT2DCM_PHY,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CanTp_Rx_Fun,
        1u,
        PduR_PDUR_ROUTING_CANT2DCM_FUN,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HcmlToVgmDiagDcmIpdu,
        1u,
        PduR_PDUR_ROUTING_DCM2CANTP,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CanNmEiraRxPdu,
        1u,
        PduR_PDUR_ROUTING_CANNM_EIRA_RX,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CanNmEraRxPdu_BodyExposedCAN_HCML,
        1u,
        PduR_PDUR_ROUTING_CANNM_ERA_RX_BodyExposedCAN_HCML,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML,
        1u,
        PduR_PDUR_ROUTING_CANNM_USERDATA_TX_BodyExposedCAN_HCML,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu07,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu07,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu100,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu100,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu101,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu101,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu102,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu102,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu103,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu103,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu104,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu104,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu105,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu105,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu106,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu106,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu107,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu107,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu108,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu108,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu109,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu109,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu110,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu110,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu111,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu111,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu112,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu112,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu113,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu113,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu114,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu114,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu29,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu29,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu31,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu31,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu33,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu33,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu35,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu35,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu37,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu37,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu38,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu38,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu61,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu61,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu66,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu66,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu91,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu91,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu92,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu92,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu93,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu93,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu94,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu94,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu95,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu95,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu96,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu96,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu97,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu97,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu98,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu98,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu99,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu99,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingTableType,PDUR_CONST)
PduR_RoutingTableConfigData[1] =
{
    {
        PduR_RoutingPathConfigData0
    }
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(PduR_PBConfigType, PDUR_CONST_PBCFG) PduR_PBConfigData =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    0u,
    0u,
    72u,
    72u,
    NULL_PTR,
    PduR_RoutingTableConfigData,
    PduR_SrcPduConfigData,
    PduR_DestPduConfigData,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

