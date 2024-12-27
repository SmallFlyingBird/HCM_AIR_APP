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
**  FILENAME    : user_cbk.h                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION : BswM pre-compile configuration MACROs                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef USER_CBK_H
#define USER_CBK_H

void GenericRequest_CanVoltage_Normal(void);
void GenericRequest_CanVoltage_L65(void);
void GenericRequest_CanVoltage_L65_500(void);
void GenericRequest_CanVoltage_H18(void);
void GenericRequest_CanVoltage_H18_500(void);
void GenericRequest_LinVoltage_Normal(void);
void GenericRequest_LinVoltage_L7_500(void);
void GenericRequest_LinVoltage_H165_500(void);
void GenericRequest_DtcVoltage_Normal(void);
void GenericRequest_DtcVoltage_L85_500(void);
void GenericRequest_DtcVoltage_H18_500(void);
void NvM_Action_WriteAll(void);
void BswM_EcuM_RequestRun(void);
void BswM_EcuM_ReleaseRun(void);
void NO_COM_Channel_Lin(void);
void FULL_COM_Channel_Lin(void);
void RxEnableGroupSwitch_Channel_Lin(void);
void RxDisabledGroupSwitch_Channel_Lin(void);
void TxEnableGroupSwitch_Channel_Lin(void);
void TxDisabledGroupSwitch_Channel_Lin(void);
void DCM_NmCtrol_Enable_Channel_Lin(void);
void DCM_NmCtrol_Disable_Channel_Lin(void);

#endif
