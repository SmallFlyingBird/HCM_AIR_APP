/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2017)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinIf_Cfg.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of LinIf                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

#ifndef LINIF_CFG_H
#define LINIF_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Dcm_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Switches the TP ON or OFF */
#define LINIF_TP_SUPPORTED STD_ON

/* Null-schedule index */
#define LINIF_NULL_SCHEDULE_INDEX       0u

#define LINIF_NUMBER_OF_CHANNELS        1u
#define LINIF_MASTER_CHANNEL_NUMBER     0u
#define LINIF_SLAVE_CHANNEL_NUMBER      1u

#define LINIF_MASTER_FRAME_NUM          0u
#define LINIF_SLAVE_FRAME_NUM           5u

#define LINIF_LIN_CHANNEL_WAKEUP_SUPPORT  STD_ON

#define LINIF_LIN_TRCV_WAKEUP_SUPPORT     STD_ON

/* LinChannelWakeupSupport || LinTrcvWakeUpSupport */
#define LINIF_WAKEUP_SUPPORT              STD_ON

#define LINIF_SLAVE_SUPPORT      STD_ON
#define LINIF_MASTER_SUPPORT     STD_OFF

#define LINTP_PADDING_VALUE             0xFF

#define LINTP_NUMBER_OF_CHANNELS        1u
#define LINTP_MASTER_CHANNEL_NUMBER     0u
#define LINTP_SLAVE_CHANNEL_NUMBER      1u

/* LINTP Timing define */
#define LINTP_TIME_P2       50u
#define LINTP_TIME_P2MAX    5000u
#define LINTP_TIME_NCR      1000u
#define LINTP_TIME_NAS      1000u
#define LINTP_TIME_NCS      900u

/* NAD define */
//#define LINTP_PHY_NAD       0x61u
#define LINTP_FUN_NAD       0x7Eu

#define LINTP_PHY_NAD_L       0x2Au
#define LINTP_PHY_NAD_R       0x2Bu
// #define LINTP_PHY_NAD_M       0x47u

/* PduId define */
#define LINTP_RXPDU_Lin_S_Diag_Phy_Rx   DCM_RX_PHY_PDU_ID
#define LINTP_RXPDU_Lin_S_Diag_Fun_Rx   DCM_RX_FUNC_PDU_ID

#define LINTP_TXPDU_Lin_S_Diag_Tx       DCM_TX_PDU_ID

#endif /* LINIF_CFG_H */
