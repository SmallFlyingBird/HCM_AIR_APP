/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Rte_COMCbk.h                                                **
**                                                                            **
**  Created on  :2024/12/12 15:24:14                                                             
**  Author      : ISOFT                                                       **
**  Vendor      :                                                             **
**  DESCRIPTION : Notification function declaration                           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

#ifndef  RTE_COMCBK_H
#define  RTE_COMCBK_H

#include "Com.h"
#include "ComM.h"
#include "CanIf.h"

boolean IPDU_COM_RLM_RS_BCM_01(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_BCM_RLM_01(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BCM_RLM_02(PduIdType PduId, const PduInfoType* PduInfoPtr);

      
void Rte_COMCbk_BCMResponseErr_BCM_RLM_01(void);

void Rte_COMCbk_LiLanguageCtrl_8_BCM_RLM_02(void);

void Rte_COMCbkTAck_RLM_R_ChrgSyncIndcn_RLM_RS_BCM_01(void);



#endif

