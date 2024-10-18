/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-03-21 10:57:32>
 */
/*============================================================================*/

/*=======[I N C L U D E S]================================*/
#include "CanTp.h"
#include "CanIf_Cfg.h"
#include "PduR_Cfg.h"

/*=======[I N T E R N A L   D A T A]=======================*/
/* PRQA S 0779,0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
/*CanTpChannel RxSdu address information*/

/* PRQA S 0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_Nar = 1000u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_Ncr = 1000u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_Bs = 0u;

static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_STmin = 15u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_Nar = 1000u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_Ncr = 1000u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_Bs = 0u;

static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_STmin = 15u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_RxNSduType, CANTP_CONST) CanTp_Ch0RxNSdus[2] =
{
    {
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_Bs,
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_Nar,
        10u,
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CanTp_Rx_Phy,
        CANTP_CanTp_Rx_Phy,
        CANTP_CemToHcmlBodyCanExpDiagReqNpdu,
        CANTP_HcmlToCemBodyCanExpDiagResNpdu,
        CANIF_TXPDU_HcmlToCemBodyCanExpDiagResNpdu,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_RX,
        NULL_PTR,
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Phy_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CANTP_CAN_20,
    },
    {
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_Bs,
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_Nar,
        10u,
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CanTp_Rx_Fun,
        CANTP_CanTp_Rx_Fun,
        CANTP_CemToAllFuncBodyCanExpDiagReqNpdu,
        0xFFu,
        0xFFu,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_FUNCTIONAL_RX,
        NULL_PTR,
        &CanTp_Ch0RxSdu_CANTP_CanTp_Rx_Fun_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CANTP_CAN_20,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*CanTpChannel TxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CanTp_Tx_Nbs = 1000u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CanTp_Tx_Ncs = 100u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_TxNSduType, CANTP_CONST) CanTp_Ch0TxNSdus[1] =
{
    {
        1000u,
        &CanTp_Ch0TxSdu_CANTP_CanTp_Tx_Nbs,
        &CanTp_Ch0TxSdu_CANTP_CanTp_Tx_Ncs,
        CANTP_STANDARD,
        PDUR_DESTPDU_CanTp_Tx,
        CANTP_CanTp_Tx,
        CANTP_HcmlToCemBodyCanExpDiagResNpdu,
        CANTP_CemToHcmlBodyCanExpDiagReqNpdu,
        CANIF_TXPDU_HcmlToCemBodyCanExpDiagResNpdu,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_TX,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CANTP_CAN_20,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3,Rule 5.2 */

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_ChannelType, CANTP_CONST) CanTp_CfgChannel[CANTP_CHANNEL_NUMBER] =
{
    {
        CANTP_MODE_FULL_DUPLEX,
        FALSE,
        50u,
        5000u,
        0u,
        0x2u,
        &CanTp_Ch0RxNSdus[0],
        0x1u,
        &CanTp_Ch0TxNSdus[0]
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
CONST(CanTp_ConfigType, CANTP_CONST) CanTp_Config =
{
    CANTP_CHANNEL_NUMBER,
    &CanTp_CfgChannel[0]
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*=======[E X T E R N A L   D A T A]===========================*/
/*=======[E N D   O F   F I L E]==============================*/

