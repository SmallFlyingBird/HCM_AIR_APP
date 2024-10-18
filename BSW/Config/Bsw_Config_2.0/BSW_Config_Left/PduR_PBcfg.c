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
**  Created on  : 2024/03/26 15:24:41                                         **
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
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu30,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu30,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu30,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu34,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu34,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu34,
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
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu32,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu32,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu32,
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
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu28,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu28,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu28,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu27,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu27,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu27,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
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
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu26,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu26,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu26,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu36,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu36,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu36,
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
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu60,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu60,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu60,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu65,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu65,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu65,
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
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu68,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu68,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu68,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu69,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu69,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu69,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu70,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu70,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu70,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu71,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu71,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu71,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu72,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu72,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu72,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu73,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu73,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu73,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu74,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu74,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu74,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu75,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu75,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu75,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu76,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu76,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu76,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu77,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu77,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu77,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu78,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu78,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu78,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu79,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu79,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu79,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu81,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu81,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu81,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu80,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu80,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu80,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu82,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu82,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu82,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu83,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu83,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu83,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu84,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu84,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu84,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu85,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu85,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu85,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu86,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu86,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu86,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu87,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu87,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu87,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu88,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu88,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu88,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu89,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu89,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu89,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu90,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu90,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu90,
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
        PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu63,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CemBodyExpoSignalIPdu63,
        COM_RXPDU_COM_CemBodyExpoSignalIPdu63,
        PDUR_COM,
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
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRSrcPduType,PDUR_CONST)
PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu19,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU05,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu20,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu30,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu30,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu34,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu34,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu02,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu18,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU06,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu32,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu32,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu13,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu28,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu28,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu27,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu27,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu01,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu26,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu26,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu36,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu36,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu51,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu51,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu01,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu01,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu59,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu59,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu60,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu60,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu65,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu65,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu68,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu68,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu69,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu69,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu70,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu70,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu71,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu71,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu72,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu72,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu73,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu73,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu74,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu74,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu75,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu75,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu76,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu76,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu77,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu77,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu78,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu78,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu79,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu79,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu81,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu81,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu80,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu80,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu82,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu82,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu83,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu83,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu84,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu84,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu85,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu85,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu86,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu86,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu87,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu87,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu88,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu88,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu89,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu89,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu90,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu90,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu63,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CemBodyExpoSignalIPdu63,
        PDUR_CANIF,

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
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

/* PRQA S 0779,0779 ++ */ /* MISRA Rule 1.3,Rule 5.2 */
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
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu19[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu19,
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
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU05[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU05,
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
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu20[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu20,
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu30[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu30,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu34[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu34,
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
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu02[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu02,
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
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu18[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu18,
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
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU06[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU06,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu32[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu32,
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
PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu13[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu13,
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu28[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu28,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu27[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu27,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu26[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu26,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu36[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu36,
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu51[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu51,
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu01[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu01,
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu59[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu59,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu60[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu60,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu65[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu65,
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu68[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu68,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu69[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu69,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu70[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu70,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu71[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu71,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu72[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu72,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu73[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu73,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu74[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu74,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu75[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu75,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu76[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu76,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu77[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu77,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu78[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu78,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu79[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu79,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu81[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu81,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu80[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu80,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu82[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu82,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu83[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu83,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu84[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu84,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu85[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu85,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu86[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu86,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu87[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu87,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu88[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu88,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu89[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu89,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu90[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu90,
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
PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu63[1] =
{
    PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu63,
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
/* PRQA S 0779,0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */
#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingPathType,PDUR_CONST)
PduR_RoutingPathConfigData0[72] =
{
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu19,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU05,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu20,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu30,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu30,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu34,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu34,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu02,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu18,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPDU06,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu32,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu32,
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
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu13,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu28,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu28,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu27,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu27,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoCommonSignalIPdu01,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu26,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu26,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu36,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu36,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu51,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu51,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu01,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu01,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu59,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu59,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu60,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu60,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu65,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu65,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu68,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu68,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu69,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu69,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu70,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu70,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu71,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu71,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu72,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu72,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu73,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu73,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu74,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu74,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu75,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu75,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu76,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu76,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu77,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu77,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu78,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu78,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu79,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu79,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu81,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu81,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu80,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu80,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu82,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu82,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu83,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu83,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu84,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu84,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu85,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu85,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu86,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu86,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu87,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu87,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu88,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu88,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu89,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu89,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu90,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu90,
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
        PDUR_SRCPDU_CemBodyExpoSignalIPdu63,
        1u,
        PduR_PDUR_ROUTING_CemBodyExpoSignalIPdu63,
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

