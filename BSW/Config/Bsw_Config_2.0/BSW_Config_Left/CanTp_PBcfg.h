/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-03-21 10:57:32>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H

/*======== [I N C L U D E S]========================*/
#include "Std_Types.h"

/*========[V E R S I O N  I N F O R M A T I O N]=========*/
#define CANTP_CFG_H_AR_MAJOR_VERSION 4U
#define CANTP_CFG_H_AR_MINOR_VERSION 5U
#define CANTP_CFG_H_AR_PATCH_VERSION 0U
#define CANTP_CFG_H_SW_MAJOR_VERSION 2U
#define CANTP_CFG_H_SW_MINOR_VERSION 1U
#define CANTP_CFG_H_SW_PATCH_VERSION 1U

/*========[M A C R O S] ==========================*/
/* Total number of channel used in CanTp module. */
#define CANTP_CHANNEL_NUMBER                        0x1u

/*configuration MACRO addressing mode for cutting*/
#define CANTP_EXTENDED_ADDRESSING_SUPPORT           STD_OFF
#define CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT       STD_OFF
#define CANTP_MIXED_ADDRESSING_SUPPORT              STD_OFF
#define CANTP_MIXED29_ADDRESSING_SUPPORT            STD_OFF

/* -------------------- CanTpChannel -------------------- */

/* CanTpRxNSdu_Phy */  
#define CANTP_CanTp_Rx_Phy                                0x0u/*RxNSdu Id*/
#define CANTP_CemToHcmlBodyCanExpDiagReqNpdu                                 0x1u/*RxNPdu Id*/
#define CANTP_HcmlToCemBodyCanExpDiagResNpdu                               0x2u/*TxFcNPdu Id*/

/* CanTpRxNSdu_Func */  
#define CANTP_CanTp_Rx_Fun                                0x3u/*RxNSdu Id*/
#define CANTP_CemToAllFuncBodyCanExpDiagReqNpdu                                 0x4u/*RxNPdu Id*/

/* CanTpTxNSdu_Resp */   
#define CANTP_CanTp_Tx                                0x0u/*TxNSdu Id*/

#endif /* CANTP_PBCFG_H */
