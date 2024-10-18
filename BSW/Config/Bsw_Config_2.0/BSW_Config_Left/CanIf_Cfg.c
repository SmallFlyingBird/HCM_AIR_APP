
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
**  FILENAME    : CanIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/09/19 08:15:01                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :parameter declaration of CanIf                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define CANIF_CFG_C_AR_MAJOR_VERSION  4u
#define CANIF_CFG_C_AR_MINOR_VERSION  2u
#define CANIF_CFG_C_AR_PATCH_VERSION  2u
#define CANIF_CFG_C_SW_MAJOR_VERSION  2u
#define CANIF_CFG_C_SW_MINOR_VERSION  0u
#define CANIF_CFG_C_SW_PATCH_VERSION  0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"
#include "CanSM_Cbk.h"
#include "PduR_CanIf.h"
#include "CanNm_Cbk.h"
#include "XcpOnCan_Cbk.h"
#include "CanTp_Cbk.h"
#include "CanTp.h"
#include "Can.h"
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_CFG_C_AR_MAJOR_VERSION != CANIF_CFG_H_AR_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_AR_MINOR_VERSION != CANIF_CFG_H_AR_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
#endif

#if (CANIF_CFG_C_AR_PATCH_VERSION != CANIF_CFG_H_AR_PATCH_VERSION)
    #error "CanIf.c:Mismatch in Specification Patch Version"
#endif

#if (CANIF_CFG_C_SW_MAJOR_VERSION != CANIF_CFG_H_SW_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_SW_MINOR_VERSION != CANIF_CFG_H_SW_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
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
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(CanIf_DispatchConfigType,CANIF_CONST) CanIf_DispatchConfigData =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    /* void XXX_ControllerBusOff(uint8 ControllerId) */
    &CanSM_ControllerBusOff,
    /* void XXX_ControllerModeIndication(uint8 ControllerId,CanIf_ControllerModeType ControllerMode)  */
    &CanSM_ControllerModeIndication,
    /* void XXX_TransceiverModeIndication(uint8 TransceiverId,CanTrcv_TrcvModeType TransceiverMode) */
    NULL_PTR,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(Can_DriverApiType,CANIF_CONST_PBCFG) Can_DriverApi[CANIF_CANDRIVER_NUMBER] =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    {
        &Can_SetControllerMode,
        &Can_Write,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfCtrlCanCtrlRefType,CANIF_CONST_PBCFG) CanIf_CtrlRef[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        0u,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_ControllerCfgType,CANIF_CONST) CanIf_CtrlCfgData[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[0],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHrhIdSymRefType,CANIF_CONST_PBCFG) CanIf_HrhRef[CANIF_HRH_NUMBER] =
{
    {
        0u,
        CANIF_FULL_CAN,
    },
    {
        1u,
        CANIF_FULL_CAN,
    },
    {
        2u,
        CANIF_FULL_CAN,
    },
    {
        3u,
        CANIF_FULL_CAN,
    },
    {
        4u,
        CANIF_FULL_CAN,
    },
    {
        67u,
        CANIF_FULL_CAN,
    },
    {
        66u,
        CANIF_FULL_CAN,
    },
    {
        65u,
        CANIF_FULL_CAN,
    },
    {
        5u,
        CANIF_FULL_CAN,
    },
    {
        6u,
        CANIF_FULL_CAN,
    },
    {
        7u,
        CANIF_FULL_CAN,
    },
    {
        8u,
        CANIF_FULL_CAN,
    },
    {
        9u,
        CANIF_FULL_CAN,
    },
    {
        10u,
        CANIF_FULL_CAN,
    },
    {
        11u,
        CANIF_FULL_CAN,
    },
    {
        12u,
        CANIF_FULL_CAN,
    },
    {
        13u,
        CANIF_FULL_CAN,
    },
    {
        14u,
        CANIF_FULL_CAN,
    },
    {
        15u,
        CANIF_FULL_CAN,
    },
    {
        16u,
        CANIF_FULL_CAN,
    },
    {
        18u,
        CANIF_FULL_CAN,
    },
    {
        19u,
        CANIF_FULL_CAN,
    },
    {
        20u,
        CANIF_FULL_CAN,
    },
    {
        21u,
        CANIF_FULL_CAN,
    },
    {
        23u,
        CANIF_FULL_CAN,
    },
    {
        24u,
        CANIF_FULL_CAN,
    },
    {
        25u,
        CANIF_FULL_CAN,
    },
    {
        27u,
        CANIF_FULL_CAN,
    },
    {
        28u,
        CANIF_FULL_CAN,
    },
    {
        29u,
        CANIF_FULL_CAN,
    },
    {
        30u,
        CANIF_FULL_CAN,
    },
    {
        31u,
        CANIF_FULL_CAN,
    },
    {
        32u,
        CANIF_FULL_CAN,
    },
    {
        33u,
        CANIF_FULL_CAN,
    },
    {
        36u,
        CANIF_FULL_CAN,
    },
    {
        37u,
        CANIF_FULL_CAN,
    },
    {
        38u,
        CANIF_FULL_CAN,
    },
    {
        39u,
        CANIF_FULL_CAN,
    },
    {
        40u,
        CANIF_FULL_CAN,
    },
    {
        41u,
        CANIF_FULL_CAN,
    },
    {
        42u,
        CANIF_FULL_CAN,
    },
    {
        43u,
        CANIF_FULL_CAN,
    },
    {
        44u,
        CANIF_FULL_CAN,
    },
    {
        45u,
        CANIF_FULL_CAN,
    },
    {
        46u,
        CANIF_FULL_CAN,
    },
    {
        47u,
        CANIF_FULL_CAN,
    },
    {
        48u,
        CANIF_FULL_CAN,
    },
    {
        49u,
        CANIF_FULL_CAN,
    },
    {
        50u,
        CANIF_FULL_CAN,
    },
    {
        51u,
        CANIF_FULL_CAN,
    },
    {
        52u,
        CANIF_FULL_CAN,
    },
    {
        53u,
        CANIF_FULL_CAN,
    },
    {
        54u,
        CANIF_FULL_CAN,
    },
    {
        55u,
        CANIF_FULL_CAN,
    },
    {
        56u,
        CANIF_FULL_CAN,
    },
    {
        57u,
        CANIF_FULL_CAN,
    },
    {
        58u,
        CANIF_FULL_CAN,
    },
    {
        59u,
        CANIF_FULL_CAN,
    },
    {
        60u,
        CANIF_FULL_CAN,
    },
    {
        61u,
        CANIF_FULL_CAN,
    },
    {
        62u,
        CANIF_FULL_CAN,
    },
    {
        63u,
        CANIF_BASIC_CAN,
    },
    {
        64u,
        CANIF_FULL_CAN,
    },
    {
        26u,
        CANIF_FULL_CAN,
    },
    {
        34u,
        CANIF_FULL_CAN,
    },
    {
        22u,
        CANIF_FULL_CAN,
    },
    {
        17u,
        CANIF_FULL_CAN,
    },
    {
        35u,
        CANIF_FULL_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef0[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu09,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef1[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu10,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef2[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu19,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef3[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu17,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef4[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPDU05,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef5[1] =
{
    CANIF_RXPDU_CemToAllFuncBodyCanExpDiagReqNpdu,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef6[1] =
{
    CANIF_RXPDU_CemToHcmlBodyCanExpDiagReqNpdu,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef7[1] =
{
    CANIF_RXPDU_EtcToHcmlXcpPdu01,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef8[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu21,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef9[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu20,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef10[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu42,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef11[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu30,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef12[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu34,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef13[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu15,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef14[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu02,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef15[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu14,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef16[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu18,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef17[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPDU07,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef18[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPDU08,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef19[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPDU06,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef20[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu25,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef21[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu13,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef22[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu16,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef23[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu28,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef24[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu01,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef25[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu26,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef26[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu36,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef27[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu51,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef28[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu11,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef29[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu12,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef30[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu45,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef31[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu50,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef32[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu01,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef33[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPdu22,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef34[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu65,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef35[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu67,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef36[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu68,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef37[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu69,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef38[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu70,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef39[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu71,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef40[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu72,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef41[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu73,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef42[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu74,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef43[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu75,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef44[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu76,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef45[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu77,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef46[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu78,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef47[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu79,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef48[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu81,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef49[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu80,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef50[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu82,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef51[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu83,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef52[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu84,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef53[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu85,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef54[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu86,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef55[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu87,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef56[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu88,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef57[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu89,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef58[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu90,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef59[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu115,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef60[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu116,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef61[1] =
{
    CANIF_RXPDU_HcmrBodyExposedCanNmPdu1,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef62[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu63,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef63[1] =
{
    CANIF_RXPDU_CemBodyExpoCommonSignalIPDU04,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef64[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu59,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef65[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu27,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef66[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu32,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef67[1] =
{
    CANIF_RXPDU_CemBodyExpoSignalIPdu60,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHrhCfgType,CANIF_CONST) CanIf_HrhCfgData[CANIF_HRH_NUMBER] =
{
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef0[0],

        &CanIf_HrhRef[0],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef1[0],

        &CanIf_HrhRef[1],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef2[0],

        &CanIf_HrhRef[2],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef3[0],

        &CanIf_HrhRef[3],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef4[0],

        &CanIf_HrhRef[4],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef5[0],

        &CanIf_HrhRef[5],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef6[0],

        &CanIf_HrhRef[6],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef7[0],

        &CanIf_HrhRef[7],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef8[0],

        &CanIf_HrhRef[8],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef9[0],

        &CanIf_HrhRef[9],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef10[0],

        &CanIf_HrhRef[10],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef11[0],

        &CanIf_HrhRef[11],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef12[0],

        &CanIf_HrhRef[12],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef13[0],

        &CanIf_HrhRef[13],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef14[0],

        &CanIf_HrhRef[14],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef15[0],

        &CanIf_HrhRef[15],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef16[0],

        &CanIf_HrhRef[16],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef17[0],

        &CanIf_HrhRef[17],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef18[0],

        &CanIf_HrhRef[18],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef19[0],

        &CanIf_HrhRef[19],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef20[0],

        &CanIf_HrhRef[20],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef21[0],

        &CanIf_HrhRef[21],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef22[0],

        &CanIf_HrhRef[22],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef23[0],

        &CanIf_HrhRef[23],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef24[0],

        &CanIf_HrhRef[24],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef25[0],

        &CanIf_HrhRef[25],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef26[0],

        &CanIf_HrhRef[26],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef27[0],

        &CanIf_HrhRef[27],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef28[0],

        &CanIf_HrhRef[28],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef29[0],

        &CanIf_HrhRef[29],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef30[0],

        &CanIf_HrhRef[30],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef31[0],

        &CanIf_HrhRef[31],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef32[0],

        &CanIf_HrhRef[32],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef33[0],

        &CanIf_HrhRef[33],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef34[0],

        &CanIf_HrhRef[34],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef35[0],

        &CanIf_HrhRef[35],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef36[0],

        &CanIf_HrhRef[36],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef37[0],

        &CanIf_HrhRef[37],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef38[0],

        &CanIf_HrhRef[38],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef39[0],

        &CanIf_HrhRef[39],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef40[0],

        &CanIf_HrhRef[40],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef41[0],

        &CanIf_HrhRef[41],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef42[0],

        &CanIf_HrhRef[42],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef43[0],

        &CanIf_HrhRef[43],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef44[0],

        &CanIf_HrhRef[44],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef45[0],

        &CanIf_HrhRef[45],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef46[0],

        &CanIf_HrhRef[46],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef47[0],

        &CanIf_HrhRef[47],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef48[0],

        &CanIf_HrhRef[48],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef49[0],

        &CanIf_HrhRef[49],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef50[0],

        &CanIf_HrhRef[50],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef51[0],

        &CanIf_HrhRef[51],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef52[0],

        &CanIf_HrhRef[52],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef53[0],

        &CanIf_HrhRef[53],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef54[0],

        &CanIf_HrhRef[54],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef55[0],

        &CanIf_HrhRef[55],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef56[0],

        &CanIf_HrhRef[56],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef57[0],

        &CanIf_HrhRef[57],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef58[0],

        &CanIf_HrhRef[58],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef59[0],

        &CanIf_HrhRef[59],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef60[0],

        &CanIf_HrhRef[60],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef61[0],

        &CanIf_HrhRef[61],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef62[0],

        &CanIf_HrhRef[62],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef63[0],

        &CanIf_HrhRef[63],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef64[0],

        &CanIf_HrhRef[64],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef65[0],

        &CanIf_HrhRef[65],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef66[0],

        &CanIf_HrhRef[66],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,

        1u,
        &CanIf_HrhRxPduRef67[0],

        &CanIf_HrhRef[67],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHthIdSymRefType,CANIF_CONST_PBCFG) CanIf_HthRef[CANIF_HTH_NUMBER] =
{
    {
        68u,
        CANIF_BASIC_CAN,
    },
    {
        69u,
        CANIF_BASIC_CAN,
    },
    {
        70u,
        CANIF_BASIC_CAN,
    },
    {
        71u,
        CANIF_BASIC_CAN,
    },
    {
        72u,
        CANIF_BASIC_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHthCfgType,CANIF_CONST) CanIf_HthCfgData[CANIF_HTH_NUMBER] =
{
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,
        &CanIf_HthRef[0],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,
        &CanIf_HthRef[1],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,
        &CanIf_HthRef[2],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,
        &CanIf_HthRef[3],
    },
    {
        CANIF_CANDRV_0_BodyExposedCAN_HCML,
        &CanIf_HthRef[4],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_InitHohCfgType,CANIF_CONST) CanIf_InitHohCfgData =
{
    CanIf_HrhCfgData,
    CanIf_HthCfgData,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfRxPduRefType,CANIF_CONST_PBCFG) CanIf_RxPduRef[CANIF_RXPDU_NUMBER] =
{
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu09,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu10,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu17,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05,
        FALSE
    },
    {
        CANTP_CemToAllFuncBodyCanExpDiagReqNpdu,
        FALSE
    },
    {
        CANTP_CemToHcmlBodyCanExpDiagReqNpdu,
        FALSE
    },
    {
        XCP_EtcToHcmlXcpPdu01,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu21,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu42,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu30,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu34,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu15,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu14,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU07,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU08,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu25,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu16,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu28,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu26,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu36,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu51,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu11,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu12,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu45,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu50,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu01,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu22,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu65,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu67,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu68,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu69,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu70,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu71,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu72,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu73,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu74,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu75,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu76,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu77,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu78,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu79,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu81,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu80,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu82,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu83,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu84,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu85,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu86,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu87,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu88,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu89,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu90,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu115,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu116,
        FALSE
    },
    {
        CANNM_RX_PDU_0,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu63,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU04,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu59,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu27,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu32,
        FALSE
    },
    {
        PDUR_SRCPDU_CemBodyExpoSignalIPdu60,
        FALSE
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_RxPduConfigType,CANIF_CONST) CanIf_RxPduConfigData[CANIF_RXPDU_NUMBER] =
{
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu09,
        0x183u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_0,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[0]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu10,
        0x185u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_1,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[1]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu19,
        0x18eu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_2,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[2]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu17,
        0x18cu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_3,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[3]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU05,
        0x180u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_4,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[4]
    },
    {
        CANIF_RXPDU_CemToAllFuncBodyCanExpDiagReqNpdu,
        0x7ffu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_5,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[5]
    },
    {
        CANIF_RXPDU_CemToHcmlBodyCanExpDiagReqNpdu,
        0x7b3u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_6,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[6]
    },
    {
        CANIF_RXPDU_EtcToHcmlXcpPdu01,
        0x596u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_7,
        FALSE,
        &Xcp_CanIfRxIndication,
        &CanIf_RxPduRef[7]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu21,
        0x40u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_8,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[8]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu20,
        0x18fu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_9,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[9]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu42,
        0x17du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_10,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[10]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu30,
        0x13bu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_11,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[11]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu34,
        0x13fu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_12,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[12]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu15,
        0x18au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_13,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[13]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu02,
        0x300u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_14,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[14]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu14,
        0x189u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_15,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[15]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu18,
        0x18du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_16,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[16]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU07,
        0x220u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_17,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[17]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU08,
        0x80u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_18,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[18]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU06,
        0x200u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_19,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[19]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu25,
        0x78u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_20,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[20]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu13,
        0x188u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_21,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[21]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu16,
        0x18bu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_22,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[22]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu28,
        0x139u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_23,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[23]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu01,
        0x52u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_24,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[24]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu26,
        0x137u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_25,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[25]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu36,
        0x141u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_26,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[26]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu51,
        0x21au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_27,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[27]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu11,
        0x186u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_28,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[28]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu12,
        0x187u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_29,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[29]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu45,
        0x264u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_30,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[30]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu50,
        0x20au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_31,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[31]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu01,
        0x1cu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_32,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[32]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPdu22,
        0x190u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_33,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[33]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu65,
        0x150u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_34,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[34]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu67,
        0x321u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_35,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[35]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu68,
        0x322u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_36,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[36]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu69,
        0x323u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_37,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[37]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu70,
        0x324u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_38,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[38]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu71,
        0x325u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_39,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[39]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu72,
        0x326u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_40,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[40]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu73,
        0x327u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_41,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[41]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu74,
        0x328u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_42,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[42]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu75,
        0x329u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_43,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[43]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu76,
        0x32au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_44,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[44]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu77,
        0x32bu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_45,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[45]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu78,
        0x32cu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_46,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[46]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu79,
        0x32du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_47,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[47]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu81,
        0x32fu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_48,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[48]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu80,
        0x32eu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_49,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[49]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu82,
        0x330u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_50,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[50]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu83,
        0x331u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_51,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[51]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu84,
        0x332u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_52,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[52]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu85,
        0x333u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_53,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[53]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu86,
        0x334u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_54,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[54]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu87,
        0x335u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_55,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[55]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu88,
        0x336u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_56,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[56]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu89,
        0x337u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_57,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[57]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu90,
        0x338u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_58,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[58]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu115,
        0x310u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_59,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[59]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu116,
        0x480u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_60,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[60]
    },
    {
        CANIF_RXPDU_HcmrBodyExposedCanNmPdu1,
        0x532u,
        0x7c0u,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_61,
        TRUE,
        &CanNm_RxIndication,
        &CanIf_RxPduRef[61]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu63,
        0x315u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_62,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[62]
    },
    {
        CANIF_RXPDU_CemBodyExpoCommonSignalIPDU04,
        0x50u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_63,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[63]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu59,
        0x18u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_64,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[64]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu27,
        0x138u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_65,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[65]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu32,
        0x13du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_66,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[66]
    },
    {
        CANIF_RXPDU_CemBodyExpoSignalIPdu60,
        0x14du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_67,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[67]
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfTxPduRefType,CANIF_CONST_PBCFG) CanIf_TxPduRef[CANIF_TXPDU_NUMBER] =
{
    {
        PDUR_DESTPDU_HcmlBodyExpoSignalIPDU02,
        FALSE,
        3u
    },
    {
        CANNM_TX_PDU_0,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_HcmlBodyExpoSignalIPDU04,
        FALSE,
        8u
    },
    {
        XCP_HcmlToEtcXcpPdu01,
        FALSE,
        8u
    },
    {
        CANTP_HcmlToCemBodyCanExpDiagResNpdu,
        FALSE,
        8u
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_TxPduConfigType,CANIF_CONST) CanIf_TxPduConfigData[CANIF_TXPDU_NUMBER] =
{
    {
        CANIF_TXPDU_HcmlBodyExpoSignalIPDU02,
        0x251u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_0,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[0],
    },
    {
        CANIF_TXPDU_HcmlBodyExposedCanNmPdu1,
        0x531u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_2,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &CanNm_TxConfirmation,
        &CanIf_TxPduRef[1],
    },
    {
        CANIF_TXPDU_HcmlBodyExpoSignalIPDU04,
        0x7cu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[2],
    },
    {
        CANIF_TXPDU_HcmlToEtcXcpPdu01,
        0x590u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &Xcp_CanIfTxConfirmation,
        &CanIf_TxPduRef[3],
    },
    {
        CANIF_TXPDU_HcmlToCemBodyCanExpDiagResNpdu,
        0x6b3u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_3,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &CanTp_TxConfirmation,
        &CanIf_TxPduRef[4],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(CanIf_ConfigType,CANIF_CONST) CanIf_InitCfgSet =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    NULL_PTR,
    CanIf_CtrlCfgData,
    &CanIf_InitHohCfgData,
    CanIf_RxPduConfigData,
    CanIf_TxPduConfigData,
    NULL_PTR,
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#if (STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER)
#define CANIF_START_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"
static CONST(uint16,CANIF_CONST_PBCFG) CanIf_Can0Hoh2HrhId[68u] =
{
    0x0u,0x1u,0x2u,0x3u,0x4u,0x8u,0x9u,0xAu,0xBu,0xCu,
    0xDu,0xEu,0xFu,0x10u,0x11u,0x12u,0x13u,0x42u,0x14u,0x15u,
    0x16u,0x17u,0x41u,0x18u,0x19u,0x1Au,0x3Fu,0x1Bu,0x1Cu,0x1Du,
    0x1Eu,0x1Fu,0x20u,0x21u,0x40u,0x43u,0x22u,0x23u,0x24u,0x25u,
    0x26u,0x27u,0x28u,0x29u,0x2Au,0x2Bu,0x2Cu,0x2Du,0x2Eu,0x2Fu,
    0x30u,0x31u,0x32u,0x33u,0x34u,0x35u,0x36u,0x37u,0x38u,0x39u,
    0x3Au,0x3Bu,0x3Cu,0x3Du,0x3Eu,0x7u,0x6u,0x5u
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1533 ++ */ /* MISRA Rule 8.9 */
CONST(CanIf_CanHOH2HRHType,CANIF_CONST) CanIf_CanHoh2Hrh[1] =
/* PRQA S 1533 -- */ /* MISRA Rule 8.9 */
{
    {
        CanIf_Can0Hoh2HrhId,
        68u
    }
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif/*STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER*/
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
