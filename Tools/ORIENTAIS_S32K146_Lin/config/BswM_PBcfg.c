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
**  FILENAME    : BswM_PBCfg.c                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : stanleyluo                                                  **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build parameter definitions of  BSWM                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#include "BswM_Cfg.h"
#include "BswM_PBCfg.h"

/* signal core config */
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h" 
/*BswMComMIndication request port PB configure*/
static CONST(BswM_ComMIndiPortPBCfgType, BSWM_CONST)
BswM_ComMIndiPortPBCfg_BswMConfig[] =
{  
	/* ReqPort_ComM_Ch_Channel_Lin */
	{
		/* initMode */
		COMM_NO_COMMUNICATION,
		/* numberOfRules */
		0U,
		NULL_PTR,	
	},		
};		
static CONST(BswM_ComMInitRstPortPBCfgType, BSWM_CONST)
BswM_ComMInitRstPortPBCfg_BswMConfig[] =
{  
	/* ReqPort_ComM_InitRest */
	{
		/* initValue */
		FALSE,
		/* numberOfRules */
		0U,
		NULL_PTR,
	},		
};	
static CONST(BswM_DcmAppUpdatedIndiPortPBCfgType, BSWM_CONST)
BswM_DcmAppUpdatedIndiPortPBCfg_BswMConfig[] =
{  
	/* ReqPort_Dcm_AppUpdate */
	{
		/* initValue */
		FALSE,
		/* numberOfRules */
		0U,
		NULL_PTR,	
	},		
};	
/*BswMDcmComModeRequest request port PB configure*/
static CONST(uint8, BSWM_CONST)
BswM_DcmComModeReqPortRulNumPBCfg_BswMConfig[] =
{
	12U,13U,14U,15U,16U,17U,
  
};	
static CONST(BswM_DcmComModeReqPortPBCfgType, BSWM_CONST)
BswM_DcmComModeReqPortPBCfg_BswMConfig[] =
{  
	/* ReqPort_Dcm_Channel_Lin */
	{
		/* initMode */
		DCM_ENABLE_RX_TX_NORM_NM,
		/* numberOfRules */
		6U,
		/* rules */
		&BswM_DcmComModeReqPortRulNumPBCfg_BswMConfig[0],		
	},		
};	
/*BswMEcuMRUNRequestIndication request port PB configure*/
static CONST(uint8, BSWM_CONST)
BswM_EcuMRUNReqIndiPortRulNumPBCfg_BswMConfig[] =
{
	8U,9U,
6U,7U,9U,
9U,
 
};	
static CONST(BswM_EcuMRUNReqIndiPortPBCfgType, BSWM_CONST)
BswM_EcuMRUNReqIndiPortPBCfg_BswMConfig[] =
{  
	/* ReqPort_EcuM_ReqPostRun */
	{
		/* initState */
		ECUM_RUNSTATUS_UNKNOWN,
		/* numberOfRules */
		2U,
		/* rules */
		&BswM_EcuMRUNReqIndiPortRulNumPBCfg_BswMConfig[0],	
	},	
	/*ReqPort_EcuM_ReqRun */
	{
		/* initStatus */
		ECUM_RUNSTATUS_UNKNOWN,
		/* numberOfRules */
		3U,		
		/* rules */
		&BswM_EcuMRUNReqIndiPortRulNumPBCfg_BswMConfig[2],							
	},	
	/*ReqPort_EcuM_ReqShutdown */
	{
		/* initStatus */
		ECUM_RUNSTATUS_UNKNOWN,
		/* numberOfRules */
		1U,		
		/* rules */
		&BswM_EcuMRUNReqIndiPortRulNumPBCfg_BswMConfig[5],							
	},		
};
/*BswMGenericRequest request port PB configure*/
static CONST(uint8, BSWM_CONST)
BswM_GenericReqPortRulNumPBCfg_BswMConfig[] =
{
	0U,1U,2U,
3U,4U,5U,

};
static CONST(BswM_GenericReqPortPBCfgType, BSWM_CONST)
BswM_GenericReqPortPBCfg_BswMConfig[] =
{  
	/* ReqPort_LIN_VOLTAGE */
	{
		/* initState */
		0xFF,
		/* numberOfRules */
		3U,
		/* rules */
		&BswM_GenericReqPortRulNumPBCfg_BswMConfig[0],	
	},	
	/*ReqPort_DTC_VOLTAGE */
	{
		/* initState */
		0xFF,
		/* numberOfRules */
		3U,		
		/* rules */
		&BswM_GenericReqPortRulNumPBCfg_BswMConfig[3],								
	},		
};
static CONST(uint8, BSWM_CONST)
BswM_LinSMIndiPortRulNumPBCfg_BswMConfig[] =
{
	10U,11U,

};
static CONST(BswM_LinSMIndiPortPBCfgType, BSWM_CONST)
BswM_LinSMIndiPortPBCfg_BswMConfig[] =
{  
	/* ReqPort_LinSm_Channel_Lin */
	{
		/* initState */
		LINSM_NO_COM,
		/* numberOfRules */
		2U,
		/* rules */
		&BswM_LinSMIndiPortRulNumPBCfg_BswMConfig[0],	
	},		
};	
/************************************************
***************Action******************************
**************************************************/





#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_ActionListItemType, BSWM_CONST)
BswM_ActionListItem_BswMConfig[] =
{
	/*Item_Action_CAN_VOLTAGE_NORMAL*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		0U,	
	},
	/*Item_Action_CAN_VOLTAGE_L_6_5*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		1U,	
	},
	/*Item_Action_CAN_VOLTAGE_L_6_5_500*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		2U,	
	},
	/*Item_Action_CAN_VOLTAGE_H_18*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		3U,	
	},
	/*Item_Action_CAN_VOLTAGE_H_18_500*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		4U,	
	},
	/*Item_Action_LIN_VOLTAGE_NORMAL*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		5U,	
	},
	/*Item_Action_LIN_VOLTAGE_L_7_500*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		6U,	
	},
	/*Item_Action_LIN_VOLTAGE_H_16_5_500*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		7U,	
	},
	/*Item_Action_DTC_VOLTAGE_NORMAL*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		8U,	
	},
	/*Item_Action_DTC_VOLTAGE_L_8_5_500*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		9U,	
	},
	/*Item_Action_DTC_VOLTAGE_H_18_500*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		10U,	
	},
	/*Item_Action_EcuM_Request_RUN*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		12U,	
	},
	/*Item_Action_EcuM_SetStatus_POST_RUN*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_ECUM_STATE_SWITCH,
		/* actionItemIdx */
		1U,	
	},
	/*Item_Action_EcuM_SetStatus_POST_RUN*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_ECUM_STATE_SWITCH,
		/* actionItemIdx */
		1U,	
	},
	/*Item_Action_EcuM_SetStatus_SHUTDOWN*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_ECUM_STATE_SWITCH,
		/* actionItemIdx */
		2U,	
	},
	/*Item_Action_EcuM_GoDown*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_ECUM_GO_DOWN,
		/* actionItemIdx */
		0U,	
	},
	/*Item_Action_NO_COM_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		14U,	
	},
	/*Item_Action_FULL_COM_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		15U,	
	},
	/*Item_Action_EcuM_ReleaseRun*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		13U,	
	},
	/*Item_Action_NvM_WriteAll*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		11U,	
	},
	/*Item_Action_DCM_RxEnableGroupSwitch_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		16U,	
	},
	/*Item_Action_DCM_RxDisabledGroupSwitch_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		17U,	
	},
	/*Item_Action_DCM_TxEnableGroupSwitch_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		18U,	
	},
	/*Item_Action_DCM_TxDisabledGroupSwitch_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		19U,	
	},
	/*Item_Action_DCM_NmCtrol_Enable_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		20U,	
	},
	/*Item_Action_DCM_NmCtrol_Disable_Channel_FlexCan_A*/
	{
		/* abortOnFail */
		FALSE,
		/* actionItemType */
		BSWM_ACTIONITEM_ACTION,
		/* actionType */
		BSWM_USER_CALLOUT,
		/* actionItemIdx */
		21U,	
	},
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_ActionListType, BSWM_CONST)
BswM_ActionListPBCfg_BswMConfig[] =
{  	
	/* AL_CAN_VOLTAGE_NORMAL */
	{
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[0],
	},	
	/*AL_CAN_VOLTAGE_L_6_5 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[1],							
	},	
	/*AL_CAN_VOLTAGE_L_6_5_500 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[2],							
	},	
	/*AL_CAN_VOLTAGE_H_18 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[3],							
	},	
	/*AL_CAN_VOLTAGE_H_18_500 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[4],							
	},	
	/*AL_LIN_VOLTAGE_NORMAL */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[5],							
	},	
	/*AL_LIN_VOLTAGE_L_7_500 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[6],							
	},	
	/*AL_LIN_VOLTAGE_H_16_5_500 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[7],							
	},	
	/*AL_DTC_VOLTAGE_NORMAL */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[8],							
	},	
	/*AL_DTC_VOLTAGE_L_8_5_500 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[9],							
	},	
	/*AL_DTC_VOLTAGE_H_18_500 */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[10],							
	},	
	/*AL_EcuM_RequestStatus_RUN_REQUEST */
	{		
		/* executeType */
		BSWM_CONDITION,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[11],							
	},	
	/*AL_EcuM_RequestStatus_RUN_RELEASE */
	{		
		/* executeType */
		BSWM_CONDITION,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[12],							
	},	
	/*AL_EcuM_RequestStatus_POSTRUN_RELEASE */
	{		
		/* executeType */
		BSWM_CONDITION,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[13],							
	},	
	/*AL_EcuM_RequestStatus_SHUTDOWN_RELEASE */
	{		
		/* executeType */
		BSWM_CONDITION,
		/* numOfActionItem */
		2U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[14],							
	},	
	/*AL_NO_COM_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[16],							
	},	
	/*AL_FULL_COM_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[17],							
	},	
	/*AL_ComM_AllChanel_NO_COM */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		2U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[18],							
	},	
	/*AL_DCM_Normal_Rx_Enable_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[20],							
	},	
	/*AL_DCM_Normal_Rx_Disable_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[21],							
	},	
	/*AL_DCM_Normal_Tx_Enable_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[22],							
	},	
	/*AL_DCM_Normal_Tx_Disable_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[23],							
	},	
	/*AL_DCM_NmCtrol_Enable_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[24],							
	},	
	/*AL_DCM_NmCtrol_Disable_Channel_Lin */
	{		
		/* executeType */
		BSWM_TRIGGER,
		/* numOfActionItem */
		1U,		
		/* actionItems */
		&BswM_ActionListItem_BswMConfig[25],							
	},	  
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"	

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_RuleType, BSWM_CONST)
BswM_RulePBCfg_BswMConfig[] =
{
	/*Rule_LIN_VOLTAGE_NORMAL*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		0U,
		/* trueActListId */
		5U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_LIN_VOLTAGE_L_7_500*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		1U,
		/* trueActListId */
		6U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_LIN_VOLTAGE_H_16_5_500*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		2U,
		/* trueActListId */
		7U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DTC_VOLTAGE_NORMAL*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		3U,
		/* trueActListId */
		8U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DTC_VOLTAGE_L_8_5_500*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		4U,
		/* trueActListId */
		9U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DTC_VOLTAGE_H_18_500*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		5U,
		/* trueActListId */
		10U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_EcuM_RequestStatus_RUN_REQUEST*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		8U,
		/* trueActListId */
		11U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_EcuM_RequestStatus_RUN_RELEASE*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		9U,
		/* trueActListId */
		12U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_EcuM_RequestStatus_POSTRUN_RELEASE*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		10U,
		/* trueActListId */
		13U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_EcuM_RequestStatus_SHUTDOWN_RELEASE*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		11U,
		/* trueActListId */
		14U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_NO_COM_Channel_Lin*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		6U,
		/* trueActListId */
		15U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_FULL_COM_Channel_Lin*/
	{
		/* initState */
		BSWM_FALSE,
		/* expressionId */
		7U,
		/* trueActListId */
		16U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DCM_Normal_Rx_Enable_Channel_Lin*/
	{
		/* initState */
		BSWM_TRUE,
		/* expressionId */
		12U,
		/* trueActListId */
		18U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DCM_Normal_Rx_Disable_Channel_Lin*/
	{
		/* initState */
		BSWM_TRUE,
		/* expressionId */
		13U,
		/* trueActListId */
		19U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DCM_Normal_Tx_Enable_Channel_Lin*/
	{
		/* initState */
		BSWM_TRUE,
		/* expressionId */
		14U,
		/* trueActListId */
		20U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DCM_Normal_Tx_Disable_Channel_Lin*/
	{
		/* initState */
		BSWM_TRUE,
		/* expressionId */
		15U,
		/* trueActListId */
		21U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DCM_Nm_Tx_Enable_Channel_Lin*/
	{
		/* initState */
		BSWM_TRUE,
		/* expressionId */
		16U,
		/* trueActListId */
		22U,
		/* falseActListId */
		0xFFU,
	},
	/*Rule_DCM_Nm_Tx_Disable_Channel_Lin*/
	{
		/* initState */
		BSWM_TRUE,
		/* expressionId */
		17U,
		/* trueActListId */
		23U,
		/* falseActListId */
		0xFFU,
	},
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_PartitionPBCfgType, BSWM_CONST)
BswM_PartitionPBCfg[1] =
{
	/*BswMConfig*/
	{
		/* portPBCfgs */
		{			
			/* comMIndiPortPBCfgs */
            BswM_ComMIndiPortPBCfg_BswMConfig,             
            /* comMInitRstPortPBCfg */
            BswM_ComMInitRstPortPBCfg_BswMConfig, 
			NULL_PTR,             			
			/* dcmAppUpdateIndiPortPBCfg */
            BswM_DcmAppUpdatedIndiPortPBCfg_BswMConfig,             
            /* dcmComModeReqPortPBCfgs */
            BswM_DcmComModeReqPortPBCfg_BswMConfig,             	
			NULL_PTR,             
            /* ecuMRUNReqIndiPortPBCfgs */
            BswM_EcuMRUNReqIndiPortPBCfg_BswMConfig, 
			NULL_PTR,             			
			/* genericReqPortPBCfgs */
            BswM_GenericReqPortPBCfg_BswMConfig,             			
			/* linSMIndiPortPBCfgs */
            BswM_LinSMIndiPortPBCfg_BswMConfig,  
			NULL_PTR,             
		},	
		/* numOfActionList */                                                  
        24U,                                                                    
        /* actionLists */ /*action lists*/
         BswM_ActionListPBCfg_BswMConfig,
        /* numOfRules */                                                       
        18U,                                                                             
        /* rules */  /*rules in this partition*/
        BswM_RulePBCfg_BswMConfig,         
	},
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"


#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
/*post-build configurable parameters*/
CONST(BswM_ConfigType,BSWM_CONST)  BswMPBCfg =
{
    /* bswmPartPBCfgs */
    BswM_PartitionPBCfg,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
