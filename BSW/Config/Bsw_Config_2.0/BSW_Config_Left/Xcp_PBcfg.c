/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Xcp_PBcfg.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-09-13 15:41:46>
 */
/*============================================================================*/

#include "Xcp.h"
#include "CanIf_Cfg.h"

/*
 *  Tx & Rx Pdu Config
 */
#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"
static const Xcp_TxPduType Xcp_TxPdu[XCP_TX_PDU_NUMBER_MAX] =
{
    {
        XCP_HcmlToEtcXcpPdu01,    /* XcpLocalTxPduId */
        CANIF_TXPDU_HcmlToEtcXcpPdu01                /* LowLayerTxPduId */
    }
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONST_PBCFG_16
#include "Xcp_MemMap.h"
static const Xcp_RxPduType Xcp_RxPdu[XCP_RX_PDU_NUMBER_MAX] =
{
    {
        XCP_EtcToHcmlXcpPdu01    /* XcpLocalRxPduId */
    }
};
#define XCP_STOP_SEC_CONST_PBCFG_16
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"
static const Xcp_PduType Xcp_Pdu =
{
    &Xcp_RxPdu[0],
    &Xcp_TxPdu[0]
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"
const Xcp_PduType Xcp_Daq_Pdu[XCP_MAX_DAQ] =
{
    {
        NULL_PTR,
        &Xcp_TxPdu[0]
    },
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"
const Xcp_ConfigType Xcp_PBConfig = /* PRQA S 1531 */     /* MISRA Rule 8.7 */
{
    XCP_RX_PDU_NUMBER_MAX,
    XCP_TX_PDU_NUMBER_MAX,
    &Xcp_Pdu
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"
