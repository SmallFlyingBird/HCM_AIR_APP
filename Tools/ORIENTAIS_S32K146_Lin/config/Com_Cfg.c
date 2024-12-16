
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
**  FILENAME    : Com_Cfg.c                                                   **
**                                                                            **
**  Created on  :2024/12/12 15:33:33                                                             
**  Author      : zhiqiang.huang                                              **
**  Vendor      :                                                             **
**  DESCRIPTION : parameter declaration of Com                                **
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

#define COM_CFG_C_AR_MAJOR_VERSION  4
#define COM_CFG_C_AR_MINOR_VERSION  2
#define COM_CFG_C_AR_PATCH_VERSION  2
#define COM_CFG_C_SW_MAJOR_VERSION  1
#define COM_CFG_C_SW_MINOR_VERSION  0
#define COM_CFG_C_SW_PATCH_VERSION  0

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Com.h"
#include "Rte_COMCbk.h"


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(COM_CFG_C_AR_MAJOR_VERSION != COM_CFG_H_AR_MAJOR_VERSION)
    #error "Com.c:Mismatch in Specification Major Version"
#endif

#if(COM_CFG_C_AR_MINOR_VERSION != COM_CFG_H_AR_MINOR_VERSION)
    #error "Com.c:Mismatch in Specification Minor Version"
#endif

#if(COM_CFG_C_AR_PATCH_VERSION != COM_CFG_H_AR_PATCH_VERSION)
    #error "Com.c:Mismatch in Specification Patch Version"
#endif

#if(COM_CFG_C_SW_MAJOR_VERSION != COM_CFG_H_SW_MAJOR_VERSION)
    #error "Com.c:Mismatch in Specification Major Version"
#endif

#if(COM_CFG_C_SW_MINOR_VERSION != COM_CFG_H_SW_MINOR_VERSION)
    #error "Com.c:Mismatch in Specification Minor Version"
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
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_TxIPduRuntimeBuff[COM_TXIPDUBUFF_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(uint8,COM_CONST_PBCFG) Com_TxIPduInitValue[COM_TXIPDUBUFF_SIZE] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00
};	
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_RxIPduRuntimeBuff[COM_RXIPDUBUFF_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(uint8,COM_CONST_PBCFG) Com_RxIPduInitValue[COM_RXIPDUBUFF_SIZE]= {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00
};	
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_SignalBoolRuntimeBuff[COM_SIGNAL_BOOLBUFF_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(boolean,COM_CONST_PBCFG) Com_SignalBoolInitValue[COM_SIGNAL_BOOLBUFF_SIZE] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_Signal8BitRuntimeBuff[COM_SIGNAL_8BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(uint8,COM_CONST_PBCFG) Com_Signal8BitInitValue[COM_SIGNAL_8BITBUFF_SIZE] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint16, COM_VAR, AUTOMATIC) Com_Signal16BitRuntimeBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint16, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal16BitInitValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint32, COM_VAR, AUTOMATIC) Com_Signal32BitRuntimeBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint32, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal32BitInitValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint64, COM_VAR, AUTOMATIC) Com_Signal64BitRuntimeBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint64, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal64BitInitValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(boolean, COM_VAR, AUTOMATIC) Com_RxGroupSignalBoolShadowBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint8, COM_VAR, AUTOMATIC) Com_RxGroupSignal8BitShadowBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint16, COM_VAR, AUTOMATIC) Com_RxGroupSignal16BitShadowBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint32, COM_VAR, AUTOMATIC) Com_RxGroupSignal32BitShadowBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"


#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint64, COM_VAR, AUTOMATIC) Com_RxGroupSignal64BitShadowBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(boolean, COM_VAR, AUTOMATIC) Com_GWSignalBoolBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint8, COM_VAR, AUTOMATIC) Com_GWSignal8BitBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint16, COM_VAR, AUTOMATIC) Com_GWSignal16BitBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint32, COM_VAR, AUTOMATIC) Com_GWSignal32BitBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(uint64, COM_VAR, AUTOMATIC) Com_GWSignal64BitBuff;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(boolean, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_SignalBoolTimeoutValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint8, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal8BitTimeoutValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint16, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal16BitTimeoutValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint32, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal32BitTimeoutValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint64, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal64BitTimeoutValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(boolean, COM_VAR, AUTOMATIC) TxSignalTMCRunTime;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(boolean, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_TxSignalInitTMC;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"
P2VAR(boolean, COM_VAR, AUTOMATIC) TxGroupSignalTMCBuffer;
#define COM_STOP_SEC_VAR_CLEARED_PTR
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(boolean, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_SignalBoolInvalidValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint8, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal8BitInvalidValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint16, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal16BitInvalidValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint32, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal32BitInvalidValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONSTP2CONST(uint64, COM_CONST_PBCFG, COM_CONST_PBCFG) Com_Signal64BitInvalidValue;
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxIPduRunTimeStateType, COM_VAR) Com_RxIPduRunTimeState[COM_RXIPDU_NUMBER];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxIPduRunTimeStateType, COM_CONST) Com_RxIPduInitState[COM_RXIPDU_NUMBER]=	
{
    {
    	FALSE,	/*ActiveEnable*/
		FALSE,	/*DMEnable*/
		FALSE,	/*Receiving*/
		8,	/*RxIpduLength*/
		0,	/*GWDynamicSignalLength*/
		FALSE,	/*NeedGW*/
		FALSE,	/*RxIndication*/
		0,	/*RxOffset*/
		FALSE,	/*RxAnyCounterPdu*/
		0,	/*RxIpduCounter*/
		0	/*RxReplicationNumber*/
	},
    {
    	FALSE,	/*ActiveEnable*/
		FALSE,	/*DMEnable*/
		FALSE,	/*Receiving*/
		8,	/*RxIpduLength*/
		0,	/*GWDynamicSignalLength*/
		FALSE,	/*NeedGW*/
		FALSE,	/*RxIndication*/
		0,	/*RxOffset*/
		FALSE,	/*RxAnyCounterPdu*/
		0,	/*RxIpduCounter*/
		0	/*RxReplicationNumber*/
	},
    {
    	FALSE,	/*ActiveEnable*/
		FALSE,	/*DMEnable*/
		FALSE,	/*Receiving*/
		7,	/*RxIpduLength*/
		0,	/*GWDynamicSignalLength*/
		FALSE,	/*NeedGW*/
		FALSE,	/*RxIndication*/
		0,	/*RxOffset*/
		FALSE,	/*RxAnyCounterPdu*/
		0,	/*RxIpduCounter*/
		0	/*RxReplicationNumber*/
	},
    {
    	FALSE,	/*ActiveEnable*/
		FALSE,	/*DMEnable*/
		FALSE,	/*Receiving*/
		7,	/*RxIpduLength*/
		0,	/*GWDynamicSignalLength*/
		FALSE,	/*NeedGW*/
		FALSE,	/*RxIndication*/
		0,	/*RxOffset*/
		FALSE,	/*RxAnyCounterPdu*/
		0,	/*RxIpduCounter*/
		0	/*RxReplicationNumber*/
	},
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"


#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxIPduRunTimeStateType, COM_VAR) Com_TxIPduRunTimeState[COM_TXIPDU_NUMBER];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxIPduRunTimeStateType, COM_CONST) Com_TxIPduInitState[COM_TXIPDU_NUMBER]=
{
    {
    	FALSE,/*ActiveEnable*/
		FALSE,/*TxConfirm*/
		TRUE,/*TMS*/
		FALSE,/*Transmitting*/
		8,/*TxIpduLength*/
		0,/*MDTCnt*/
		TX_MODE_NONE,/*ipduTxMode*/
		0,/*RptNum*/
		0,/*NTimeCnt*/
		0,/*DMCnt*/
		0,/*PeriodCnt*/
		FALSE,/*TxDelay*/
		0,/*TxOffset*/
		0/*TxIpduCounter*/
	},
    {
    	FALSE,/*ActiveEnable*/
		FALSE,/*TxConfirm*/
		TRUE,/*TMS*/
		FALSE,/*Transmitting*/
		7,/*TxIpduLength*/
		0,/*MDTCnt*/
		TX_MODE_NONE,/*ipduTxMode*/
		0,/*RptNum*/
		0,/*NTimeCnt*/
		0,/*DMCnt*/
		0,/*PeriodCnt*/
		FALSE,/*TxDelay*/
		0,/*TxOffset*/
		0/*TxIpduCounter*/
	},
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"


#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_1[1] = {0};
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_2[1] = {2};
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_1[1] = {1};
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_2[1] = {1};
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_3[1] = {3};
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_4[1] = {3};



CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_1[25] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_2[8] = {25,26,27,28,29,30,31,32};
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_3[31] = {33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_4[5] = {64,65,66,67,68};

CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_1[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_2[13] = {20,21,22,23,24,25,26,27,28,29,30,31,32};

#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxIPduType, COM_CONST) Com_RxIPdu[COM_RXIPDU_NUMBER]=
{
    {
    	&IPDU_COM_BCM_RLM_01,/*P2FUNC*/
    	
    	COM_RXPDU_Com_BCM_RLM_01,		/*ComIPduHandleId*/		
    	DEFERRED,			/*ComIPduSignalProcessing*/		
    	COM_PDU_NORMAL,			/*ComIPduType*/				
    	1,			/*ComIPduGroupsRefNumber*/  
    	&ComRxIPduGroupsRef_1[0], 		/*ComIPduGroupsRef*/
    	0,			/*ComIPduSignalGroupsRefNumber*/
    	NULL_PTR,			/*ComIPduSignalGroupsRef*/
    	25,			/*ComRxIPduSignalsRefNumber*/
    	&ComRxIPduSignalsRef_1[0],			/*ComRxIPduSignalsRef*/
    	0,			/*ComIPduSourceSignalsRefNumber*/
    	NULL_PTR,			/*ComIPduSourceSignalsRef*/
    	0,			/*MetaDataLength*/	
    	8,			/*IPduNoDynSignalLength*/	
    	0,			/*IPduMaxDynSignalLength*/	
    	0,			/*ComRxIPduBufIndex*/
    	NULL_PTR,			/*ComIPduCounter*/	
    	NULL_PTR,			/*ComIPduReplication*/	
    	FALSE		/*IPduGW*/		
	},
    {
    	&IPDU_COM_BCM_RLM_02,/*P2FUNC*/
    	
    	COM_RXPDU_Com_BCM_RLM_02,		/*ComIPduHandleId*/		
    	DEFERRED,			/*ComIPduSignalProcessing*/		
    	COM_PDU_NORMAL,			/*ComIPduType*/				
    	1,			/*ComIPduGroupsRefNumber*/  
    	&ComRxIPduGroupsRef_2[0], 		/*ComIPduGroupsRef*/
    	0,			/*ComIPduSignalGroupsRefNumber*/
    	NULL_PTR,			/*ComIPduSignalGroupsRef*/
    	8,			/*ComRxIPduSignalsRefNumber*/
    	&ComRxIPduSignalsRef_2[0],			/*ComRxIPduSignalsRef*/
    	0,			/*ComIPduSourceSignalsRefNumber*/
    	NULL_PTR,			/*ComIPduSourceSignalsRef*/
    	0,			/*MetaDataLength*/	
    	8,			/*IPduNoDynSignalLength*/	
    	0,			/*IPduMaxDynSignalLength*/	
    	8,			/*ComRxIPduBufIndex*/
    	NULL_PTR,			/*ComIPduCounter*/	
    	NULL_PTR,			/*ComIPduReplication*/	
    	FALSE		/*IPduGW*/		
	},
    {
    	NULL_PTR,/*P2FUNC*/
    	
    	COM_RXPDU_Com_ZcudZcud_Lin2Fr01,		/*ComIPduHandleId*/		
    	DEFERRED,			/*ComIPduSignalProcessing*/		
    	COM_PDU_NORMAL,			/*ComIPduType*/				
    	1,			/*ComIPduGroupsRefNumber*/  
    	&ComRxIPduGroupsRef_3[0], 		/*ComIPduGroupsRef*/
    	0,			/*ComIPduSignalGroupsRefNumber*/
    	NULL_PTR,			/*ComIPduSignalGroupsRef*/
    	31,			/*ComRxIPduSignalsRefNumber*/
    	&ComRxIPduSignalsRef_3[0],			/*ComRxIPduSignalsRef*/
    	0,			/*ComIPduSourceSignalsRefNumber*/
    	NULL_PTR,			/*ComIPduSourceSignalsRef*/
    	0,			/*MetaDataLength*/	
    	7,			/*IPduNoDynSignalLength*/	
    	0,			/*IPduMaxDynSignalLength*/	
    	16,			/*ComRxIPduBufIndex*/
    	NULL_PTR,			/*ComIPduCounter*/	
    	NULL_PTR,			/*ComIPduReplication*/	
    	FALSE		/*IPduGW*/		
	},
    {
    	NULL_PTR,/*P2FUNC*/
    	
    	COM_RXPDU_Com_ZcudZcud_Lin2Fr02,		/*ComIPduHandleId*/		
    	DEFERRED,			/*ComIPduSignalProcessing*/		
    	COM_PDU_NORMAL,			/*ComIPduType*/				
    	1,			/*ComIPduGroupsRefNumber*/  
    	&ComRxIPduGroupsRef_4[0], 		/*ComIPduGroupsRef*/
    	0,			/*ComIPduSignalGroupsRefNumber*/
    	NULL_PTR,			/*ComIPduSignalGroupsRef*/
    	5,			/*ComRxIPduSignalsRefNumber*/
    	&ComRxIPduSignalsRef_4[0],			/*ComRxIPduSignalsRef*/
    	0,			/*ComIPduSourceSignalsRefNumber*/
    	NULL_PTR,			/*ComIPduSourceSignalsRef*/
    	0,			/*MetaDataLength*/	
    	7,			/*IPduNoDynSignalLength*/	
    	0,			/*IPduMaxDynSignalLength*/	
    	23,			/*ComRxIPduBufIndex*/
    	NULL_PTR,			/*ComIPduCounter*/	
    	NULL_PTR,			/*ComIPduReplication*/	
    	FALSE		/*IPduGW*/		
	},
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxModeType, COM_CONST) ComTxModeTrue[2]=
{ 
    {
        TX_MODE_NONE,/*ComTxModeMode*/
        1,/*ComTxModeNumberOfRepetitions*/
        0,/*ComTxModeRepetitionPeriod*/
        0,/*ComTxModeTimeOffset*/
        0,/*ComTxModeTimePeriod*/
    }, 
    {
        TX_MODE_NONE,/*ComTxModeMode*/
        1,/*ComTxModeNumberOfRepetitions*/
        0,/*ComTxModeRepetitionPeriod*/
        0,/*ComTxModeTimeOffset*/
        0,/*ComTxModeTimePeriod*/
    },
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxIPduType, COM_CONST) Com_TxIPdu[COM_TXIPDU_NUMBER]=
{
	{
		&IPDU_COM_RLM_RS_BCM_01,/*P2FUNC*/	
		
		COM_TXPDU_Com_RLM_RS_BCM_01,		/*ComIPduHandleId*/		
		DEFERRED,			/*ComIPduSignalProcessing*/	
		NULL_PTR,/*P2FUNC*/		
		COM_PDU_NORMAL,			/*ComIPduType*/	
		1,			/*ComIPduGroupsRefNumber*/  
		&ComTxIPduGroupsRef_1[0], 		/*ComIPduGroupsRef*/
		0,			/*ComIPduSignalGroupsRefNumber*/
		NULL_PTR,			/*ComIPduSignalGroupsRef*/
		20,			/*ComtxIPduSignalsRefNumber*/
		&ComTxIPduSignalsRef_1[0],			/*ComTxIPduSignalsRef*/
		0,			/*ComIPduSourceSignalsRefNumber*/
		NULL_PTR,			/*ComIPduDestSignalsRef*/
		PDUR_SRCPDU_Com_RLM_RS_BCM_01,			/*ComPduIdRef*/	
		0,			/*MetaDataLength*/	
		8,			/*IPduNoDynSignalLength*/	
		0,			/*IPduMaxDynSignalLength*/	
		0,			/*ComTxIPduBufIndex*/
		NULL_PTR,			/*ComIPduCounter*/
		NULL_PTR,			/*ComIPduReplication*/	
		0,			/*ComMinimumDelayTime*/
		CONFIRMATION,		/*ComTxIPduClearUpdateBit*/
		&ComTxModeTrue[0],			/*ComTxModeTrue*/
		NULL_PTR,			/*ComTxModeFalse*/
		0			/*ComTxIpduDM*/
	},
	{
		NULL_PTR,/*P2FUNC*/	
		
		COM_TXPDU_Com_HcmlZcud_Lin2Fr01,		/*ComIPduHandleId*/		
		DEFERRED,			/*ComIPduSignalProcessing*/	
		NULL_PTR,/*P2FUNC*/		
		COM_PDU_NORMAL,			/*ComIPduType*/	
		1,			/*ComIPduGroupsRefNumber*/  
		&ComTxIPduGroupsRef_2[0], 		/*ComIPduGroupsRef*/
		0,			/*ComIPduSignalGroupsRefNumber*/
		NULL_PTR,			/*ComIPduSignalGroupsRef*/
		13,			/*ComtxIPduSignalsRefNumber*/
		&ComTxIPduSignalsRef_2[0],			/*ComTxIPduSignalsRef*/
		0,			/*ComIPduSourceSignalsRefNumber*/
		NULL_PTR,			/*ComIPduDestSignalsRef*/
		PDUR_SRCPDU_Com_HcmlZcud_Lin2Fr01,			/*ComPduIdRef*/	
		0,			/*MetaDataLength*/	
		7,			/*IPduNoDynSignalLength*/	
		0,			/*IPduMaxDynSignalLength*/	
		8,			/*ComTxIPduBufIndex*/
		NULL_PTR,			/*ComIPduCounter*/
		NULL_PTR,			/*ComIPduReplication*/	
		0,			/*ComMinimumDelayTime*/
		CONFIRMATION,		/*ComTxIPduClearUpdateBit*/
		&ComTxModeTrue[1],			/*ComTxModeTrue*/
		NULL_PTR,			/*ComTxModeFalse*/
		0			/*ComTxIpduDM*/
	},		
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxSignalType, COM_CONST) Com_TxSignal[COM_TXSIGNAL_NUMBER]=
{
        {
			0,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			RLM_RSResponseErr_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			19,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			2,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			RLM_RS_ErrEcu_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			14,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			4,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			RLM_RS_StVolt_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			15,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			8,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			PosnLiStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			20,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			9,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			PosnLiErrIndcnReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			21,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			10,		/*ComBitPosition*/	
			3,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			PosnLiErrStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			16,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			16,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			RvsLiStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			22,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			17,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			RvsLiErrIndcnReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			23,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			18,		/*ComBitPosition*/	
			3,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			RvsLiErrStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			17,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			24,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			BrkLiStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			24,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			25,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			BrkLiErrIndcnReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			25,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			26,		/*ComBitPosition*/	
			3,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			BrkLiErrStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			18,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			32,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			FogLiStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			26,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			33,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			FogLiErrIndcnReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			27,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			34,		/*ComBitPosition*/	
			3,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			FogLiErrStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			19,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			37,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			LilanguageSts_RLM_R_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			20,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			39,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			TurnLiStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			28,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			40,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			TurnLiErrIndcnReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			29,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			41,		/*ComBitPosition*/	
			3,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			TurnLiErrStsReRiSide_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			21,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			44,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			RLM_R_ChrgSyncIndcn_RLM_RS_BCM_01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			&Rte_COMCbkTAck_RLM_R_ChrgSyncIndcn_RLM_RS_BCM_01,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			22,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			0,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			16,		/*ComBitPosition*/	
			8,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			HCML2DTCGroup1_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			23,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			24,		/*ComBitPosition*/	
			8,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			HCML2DTCGroup2_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			24,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			32,		/*ComBitPosition*/	
			8,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			HCML2DTCGroup3_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			25,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			40,		/*ComBitPosition*/	
			8,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			HCML2DTCGroup4_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			26,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			0,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfLedCornrgLampwithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			27,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			2,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfLedDaytiRunngLampWithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			28,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			4,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfLedFrntFogLampWithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			29,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			6,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfLedFrntPosnLampWithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			30,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			8,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfLedFrntTurnIndcrWithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			31,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			10,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfLedHiBeamWithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			32,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			12,		/*ComBitPosition*/	
			2,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfLedLoBeamWithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			33,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_UINT8,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			14,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			StsOfWelGbyFrntWithLINLe_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			30,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
        {
			55,		/*ComBitPosition*/	
			1,		/*ComBitSize*/		
			NULL_PTR, 	/*Tx:Only valid on sender side: Name of Com_CbkTxErr callback function to be called*/
			ErrRespHCML_HcmlZcud_Lin2Fr01,		/*ComSignalId*/	
			FALSE,		/*ComInitialValueOnly*/
			NULL_PTR,		/*On sender side: Name of Com_CbkTxAck callback function to be called*/	
			0xffff,		/*ComSignalDataInvalidValueId*/	
			COM_LITTLE_ENDIAN,		/*ComSignalEndianness*/	
			31,	/*ComSignalInitValueId*/	
			0,		/*ComSignalLength*/		
			COM_BOOLEAN,   /*ComSignalType*/	
			0,		/*ComTimeout*/				
			1,		/*ComIpduRefIndex*/		
			NULL_PTR,		/*On sender side: Name of Com_CbkTxTOut callback function to be called*/ 
			PENDING,		/*ComTransferProperty*/	
			0xffffffff,		/*ComUpdateBitPosition*/		
			NULL_PTR,		/*ComFilter*/	
			0,			/*ComSignalDataInvalidValueLength*/	
			0		/*ComSignalDataInitValueLength*/ 
		},
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxSignalType, COM_CONST) Com_RxSignal[COM_RXSIGNAL_NUMBER]=
{
    {
		3,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		0,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		PosnLiOnOffReLeMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		0,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		2,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		1,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		PosnLiOnOffReRiMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		1,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		4,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		2,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		PosnLiOnOffBrilvl_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		2,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		5,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		3,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		FogLiOnOffReLeMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		3,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		8,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		4,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		FogLiOnOffReRiMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		4,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		22,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		5,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		RvsLiOnOffLeMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		5,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		25,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		6,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		RvsLiOnOffRiMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		6,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		11,	/*ComBitPosition*/
		2,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		7,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		BrkLampOnOffLeMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		0,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		17,	/*ComBitPosition*/
		2,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		8,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		BrkLampOnOffRiMid_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		1,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		21,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		9,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		TurnSweepingEna_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		7,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		30,	/*ComBitPosition*/
		4,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		10,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		LiLanguageMod_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		2,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		34,	/*ComBitPosition*/
		2,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		11,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		ChrgSyncIndcnSts_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		3,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		0,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		12,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		PosnLiOnOffReLeSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		8,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		1,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		13,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		PosnLiOnOffReRiSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		9,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		9,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		14,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		FogLiOnOffFrntLe_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		10,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		10,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		15,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		FogLiOnOffFrntRi_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		11,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		6,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		16,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		FogLiOnOffReLeSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		12,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		7,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		17,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		FogLiOnOffReRiSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		13,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		23,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		18,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		RvsLiOnOffLeSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		14,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		24,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		19,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		RvsLiOnOffRiSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		15,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		13,	/*ComBitPosition*/
		2,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		20,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		BrkLampOnOffLeSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		4,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		15,	/*ComBitPosition*/
		2,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		21,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		BrkLampOnOffRiSide_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		5,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		19,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		22,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		TurnLiOnOffLe_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		16,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		20,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		23,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		TurnLiOnOffRi_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		17,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		36,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		24,	/*ComTimeCntIndex*/	
		0,	/*ComIpduRefIndex*/	
		BCMResponseErr_BCM_RLM_01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		&Rte_COMCbk_BCMResponseErr_BCM_RLM_01,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		18,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		0,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		25,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_1_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		6,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		8,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		26,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_2_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		7,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		16,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		27,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_3_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		8,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		24,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		28,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_4_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		9,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		32,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		29,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_5_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		10,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		40,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		30,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_6_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		11,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		48,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		31,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_7_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		12,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		56,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		32,	/*ComTimeCntIndex*/	
		1,	/*ComIpduRefIndex*/	
		LiLanguageCtrl_8_BCM_RLM_02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		&Rte_COMCbk_LiLanguageCtrl_8_BCM_RLM_02,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		13,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		1,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		33,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfAssistantLi_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		32,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		0,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		34,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedCornrgLampLe_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		33,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		2,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		35,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedCornrgLampRi_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		34,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		3,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		36,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedDaytiRunngLamp_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		35,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		4,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		37,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedFrntCrossLamp_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		36,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		5,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		38,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedFrntCrossLampDyn_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		37,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		6,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		39,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedFrntFogLamp_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		38,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		7,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		40,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedGrilleLamp_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		39,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		8,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		41,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedGrilleLampDyn_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		40,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		9,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		42,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedHiBeam_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		41,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		10,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		43,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedLeLogoLamp_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		42,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		11,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		44,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedLeLogoLampDyn_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		43,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		23,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		45,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedLoBeamActnOfLedLoBeam_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		44,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		24,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		46,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedLoBeamChks_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		34,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		32,	/*ComBitPosition*/
		4,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		47,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedLoBeamCntr_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		35,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		12,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		48,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedPosnLamp_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		45,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		13,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		49,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedPosnLampDyn_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		46,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		14,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		50,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedRiLogoLamp_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		47,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		15,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		51,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActnOfLedRiLogoLampDyn_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		48,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		16,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		52,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfApproach_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		49,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		17,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		53,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfCarLoctr_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		50,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		18,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		54,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfGoodByeLi_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		51,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		46,	/*ComBitPosition*/
		2,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		55,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfIndcrIndcrOut_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		36,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		48,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		56,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfIndcrIndcrOutChks_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		37,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		42,	/*ComBitPosition*/
		4,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		57,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfIndcrIndcrOutCntr_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		38,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		19,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		58,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfShowModLi_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		52,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		20,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		59,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfWaitMode_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		53,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		21,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		60,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		ActvnOfWelcomeLi_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		54,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		22,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		61,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		IndcrNoSeq_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		55,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		40,	/*ComBitPosition*/
		2,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		62,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		IndcrSts_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		39,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		36,	/*ComBitPosition*/
		4,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		63,	/*ComTimeCntIndex*/	
		2,	/*ComIpduRefIndex*/	
		WelcomeGoodbyeModeReq_ZcudZcud_Lin2Fr01,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		40,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		15,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		64,	/*ComTimeCntIndex*/	
		3,	/*ComIpduRefIndex*/	
		ClrDTCOfLINHCML2_ZcudZcud_Lin2Fr02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		56,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		16,	/*ComBitPosition*/
		1,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		65,	/*ComTimeCntIndex*/	
		3,	/*ComIpduRefIndex*/	
		ClrDTCOfLINHCMR2_ZcudZcud_Lin2Fr02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		57,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_BOOLEAN,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		0,	/*ComBitPosition*/
		8,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		66,	/*ComTimeCntIndex*/	
		3,	/*ComIpduRefIndex*/	
		LvlgSwtSetReqChks_ZcudZcud_Lin2Fr02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		41,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		8,	/*ComBitPosition*/
		4,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		67,	/*ComTimeCntIndex*/	
		3,	/*ComIpduRefIndex*/	
		LvlgSwtSetReqCntr_ZcudZcud_Lin2Fr02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		42,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
    {
		12,	/*ComBitPosition*/
		3,	/*ComBitSize*/		
		0,	/*ComFirstTimeout*/	
		0,	/*ComTimeout*/		
		68,	/*ComTimeCntIndex*/	
		3,	/*ComIpduRefIndex*/	
		LvlgSwtSetReqLvlgSwtSetReq_ZcudZcud_Lin2Fr02,	/*ComSignalId*/		
		INVALID_ACTION_NOTIFY,	/*ComDataInvalidAction*/	
		NULL_PTR,/*Rx:Name of Com_CbkInv callback function to be called*/		
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxAck callback function to be called*/	
		TIMEOUT_ACTION_NONE,	/*ComRxDataTimeoutAction*/	
		0xffff,	/*ComSignalDataInvalidValueId*/
		COM_LITTLE_ENDIAN,	/*ComSignalEndianness*/		
		43,/*ComSignalInitValueId*/	
		0,	/*ComSignalLength*/		
		COM_UINT8,	/*ComSignalType*/	
		NULL_PTR,	/*On receiver side: Name of Com_CbkRxTOut callback function to be called.*/	
		0xffffffff,	/*ComUpdateBitPosition*/
		NULL_PTR, /*ComFilter*/	
		0,			/*ComSignalDataInvalidValueLength*/	
		0,			/*ComSignalDataInitValueLength*/ 
		0,		/*ComSignalDataTimeoutValueLength*/
		0xffff,	/*GWUpdataStateId*/	
		0xffff,	/*GWSignalBufferId*/ 
		0xffff,  /*ComSignalDataTimeoutValueId*/
	},
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"


#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_ConfigType, COM_CONST_PBCFG) Com_PBConfigData =
{
	&Com_RxIPdu[0],		/*ComRxIPdu,*/
	&Com_TxIPdu[0],		/*ComTxIPdu*/
	&Com_RxSignal[0],	/*ComRxSignal*/
	&Com_TxSignal[0],	/*ComTxSignal*/
	NULL_PTR,	/*ComRxSignalGroup*/
	NULL_PTR,	/*ComTxSignalGroup*/
	NULL_PTR,	/*ComRxGroupSignal*/
	NULL_PTR,	/*ComTxGroupSignal*/
	NULL_PTR,		/*ComGwMapping*/
	NULL_PTR,	/*ComSourceSignal*/
	NULL_PTR		/*ComDestSignal*/
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
