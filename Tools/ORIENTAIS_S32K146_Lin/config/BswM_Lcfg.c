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
**  FILENAME    : BswM_Lcfg.c                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : stanleyluo                                                  **
**  Vendor      :                                                             **
**  DESCRIPTION : link time configure parameter definitions of BSWM           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platfrom 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#include "BswM_Cfg.h"
#include "BswM_Lcfg.h"
#include "user_cbk.h"


#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
/*argument item of expression definition*/
static CONST(BswM_ExpArgumentItemType, BSWM_CONST)
BswM_ExpArgumentItem_BswMConfig[] =
{

	/*Cond_LIN_VOLTAGE_NORMAL*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_GENERIC_REQUEST,
		/* itemIdx */
		0U,				
	},
	/*Cond_LIN_VOLTAGE_L_7_500*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_GENERIC_REQUEST,
		/* itemIdx */
		1U,				
	},
	/*Cond_LIN_VOLTAGE_H_16_5_500*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_GENERIC_REQUEST,
		/* itemIdx */
		2U,				
	},
	/*Cond_DTC_VOLTAGE_NORMAL*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_GENERIC_REQUEST,
		/* itemIdx */
		3U,				
	},
	/*Cond_DTC_VOLTAGE_L_8_5_500*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_GENERIC_REQUEST,
		/* itemIdx */
		4U,				
	},
	/*Cond_DTC_VOLTAGE_H_18_500*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_GENERIC_REQUEST,
		/* itemIdx */
		5U,				
	},
	/*Cond_LinSMIndication_EQ_COMM_NO_COMMUNICATION*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_LINSM_INDICATION,
		/* itemIdx */
		0U,				
	},
	/*Cond_LinSMIndication_EQ_COMM_FULL_COMMUNICATION*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_LINSM_INDICATION,
		/* itemIdx */
		1U,				
	},
	/*Cond_EcuMWakeupIndication_EcuMRequstRun_EQ_ECUM_RUNSTATUS_REQUESTED*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_ECUM_RUN_REQUEST_INDICATION,
		/* itemIdx */
		2U,				
	},
	/*Cond_EcuMWakeupIndication_EcuMRequstRun_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_ECUM_RUN_REQUEST_INDICATION,
		/* itemIdx */
		3U,				
	},
	/*Cond_EcuMWakeupIndication_EcuMRequstPostRun_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_ECUM_RUN_REQUEST_INDICATION,
		/* itemIdx */
		1U,				
	},
	/*Cond_EcuMWakeupIndication_EcuMRequstShutDown_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_ECUM_RUN_REQUEST_INDICATION,
		/* itemIdx */
		4U,				
	},
	/*Cond_EcuMWakeupIndication_EcuMRequstPostRun_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_ECUM_RUN_REQUEST_INDICATION,
		/* itemIdx */
		1U,				
	},
	/*Cond_EcuMWakeupIndication_EcuMRequstRun_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_ECUM_RUN_REQUEST_INDICATION,
		/* itemIdx */
		3U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NORM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		0U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NORM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		1U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		8U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		9U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NORM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		2U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NORMAL*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		3U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		10U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		11U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NORM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		0U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NORM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		2U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		8U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		10U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NORM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		1U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NORMAL*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		3U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		9U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		11U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		4U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		6U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		8U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		10U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		5U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		7U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		9U,				
	},
	/*Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NORM_NM*/
	{
		/* argType */
		BSWM_EXP_ARGUMENT_CONDITION,
		/* conditionSource */
		BSWM_DCM_COM_MODE_REQUEST,
		/* itemIdx */
		11U,				
	},
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
/* expression configure */
static CONST(BswM_ExpressionLCfgType, BSWM_CONST) BswM_ExpressionLCfg_BswMConfig[] =
{
	/*LE_LIN_VOLTAGE_NORMAL */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[0],	
	},	
	/*LE_LIN_VOLTAGE_L_7_500 */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[1],							
	},	
	/*LE_LIN_VOLTAGE_H_16_5_500 */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[2],							
	},	
	/*LE_DTC_VOLTAGE_NORMAL */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[3],							
	},	
	/*LE_DTC_VOLTAGE_L_8_5_500 */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[4],							
	},	
	/*LE_DTC_VOLTAGE_H_18_500 */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[5],							
	},	
	/*LE_NO_COM_Channel_Lin */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[6],							
	},	
	/*LE_FULL_COM_Channel_Lin */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[7],							
	},	
	/*LE_EcuM_RequestStatus_RUN_REQUEST */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[8],							
	},	
	/*LE_EcuM_RequestStatus_RUN_RELEASE */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[9],							
	},	
	/*LE_EcuM_RequestStatus_POSTRUN_RELEASE */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		1U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[10],							
	},	
	/*LE_EcuM_RequestStatus_SHUTDOWN_RELEASE */
	{
		/* operator */
		BSWM_AND,
		/* numOfArgument */
		3U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[11],							
	},	
	/*LE_DCM_Normal_Rx_Enable_Channel_Lin */
	{
		/* operator */
		BSWM_OR,
		/* numOfArgument */
		4U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[14],							
	},	
	/*LE_DCM_Normal_Rx_Disable_Channel_Lin */
	{
		/* operator */
		BSWM_OR,
		/* numOfArgument */
		4U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[18],							
	},	
	/*LE_DCM_Normal_Tx_Enable_Channel_Lin */
	{
		/* operator */
		BSWM_OR,
		/* numOfArgument */
		4U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[22],							
	},	
	/*LE_DCM_Normal_Tx_Disable_Channel_Lin */
	{
		/* operator */
		BSWM_OR,
		/* numOfArgument */
		4U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[26],							
	},	
	/*LE_DCM_NmCtrol_Enable_Channel_Lin */
	{
		/* operator */
		BSWM_OR,
		/* numOfArgument */
		4U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[30],							
	},	
	/*LE_DCM_NmCtrol_Disable_Channel_Lin */
	{
		/* operator */
		BSWM_OR,
		/* numOfArgument */
		4U,		
		/* arguments */
		&BswM_ExpArgumentItem_BswMConfig[34],							
	},
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

/*********************BswMConfig*****************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"


/************* BswMComMIndication ************************/
/*COMM indication ports*/
static CONST(BswM_ComMIndiPortLCfgType, BSWM_CONST)
BswM_ComMIndiPortLCfg_BswMConfig[] =   
{	
	/* ReqPort_ComM_Ch_Channel_Lin*/
	{
		/* comMChnl */
			
		ComMChannel_HCML,
		/* process */
		BSWM_DEFERRED,		
	},
};
/************ BswMComMInitiateReset *******************/
/*COMM initiate reset ports*/
static CONST(BswM_ComMInitRstPortLCfgType, BSWM_CONST)
BswM_ComMInitRstPortLCfg_BswMConfig[] =  
{	
	/* ReqPort_ComM_InitRest*/
	{		
		/* process */
		BSWM_DEFERRED,		
	},
};
/************ BswMDcmApplicationUpdatedIndication*******/
/*DCM application updated indication ports*/
static CONST(BswM_DcmAppUpdatedIndiPortLCfgType, BSWM_CONST)
BswM_DcmAppUpdatedIndiPortLCfg_BswMConfig[] =
{	
	/* ReqPort_Dcm_AppUpdate*/
	{		
		/* process */
		BSWM_IMMEDIATE,		
	},
};
/************* BswMDcmComModeRequest *******************/
/*DCM COM mode request ports*/
static CONST(BswM_DcmComModeReqPortLCfgType, BSWM_CONST)
BswM_DcmComModeReqPortLCfg_BswMConfig[] =
{	
	/* ReqPort_Dcm_Channel_Lin*/
	{
		/* comMChnl */   
		ComMChannel_HCML,
		/* process */
		BSWM_IMMEDIATE,		
	},
};
/*BswMDcmComModeRequest condition configure*/
static CONST(BswM_DcmComModeReqCondLCfgType, BSWM_CONST)
BswM_DcmComModeReqCondLCfg_BswMConfig[] =
{	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NORM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_ENABLE_RX_TX_NORM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NORM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_ENABLE_RX_DISABLE_TX_NORM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NORM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_DISABLE_RX_ENABLE_TX_NORM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NORMAL*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_DISABLE_RX_TX_NORMAL,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_ENABLE_RX_TX_NM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_ENABLE_RX_DISABLE_TX_NM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_DISABLE_RX_ENABLE_TX_NM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_DISABLE_RX_TX_NM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_TX_NORM_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_ENABLE_RX_TX_NORM_NM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_ENABLE_RX_DISABLE_TX_NORM_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_ENABLE_RX_DISABLE_TX_NORM_NM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_ENABLE_TX_NORM_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_DISABLE_RX_ENABLE_TX_NORM_NM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DcmIndication_Channel_Lin_EQ_DCM_DISABLE_RX_TX_NORM_NM*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DCM_DISABLE_RX_TX_NORM_NM,      
	    /* portIdx */ 
		0U,   
	},
};
/****************** BswMEcuMRUNRequestIndication **************/
/*ECUM RUN request indication ports*/
static CONST(BswM_EcuMRUNReqIndiPortLCfgType, BSWM_CONST)
BswM_EcuMRUNReqIndiPortLCfg_BswMConfig[] =
{	
	/* ReqPort_EcuM_ReqPostRun*/
	{
		/* state */
		ECUM_STATE_APP_POST_RUN,
		/* process */
		BSWM_DEFERRED,		
	},	
	/* ReqPort_EcuM_ReqRun*/
	{
		/* state */
		ECUM_STATE_APP_RUN,
		/* process */
		BSWM_IMMEDIATE,		
	},	
	/* ReqPort_EcuM_ReqShutdown*/
	{
		/* state */
		ECUM_STATE_SHUTDOWN,
		/* process */
		BSWM_DEFERRED,		
	},
};
/*BswMEcuMRUNRequestIndication condition configure*/
static CONST(BswM_EcuMRUNReqIndiCondLCfgType, BSWM_CONST)
BswM_EcuMRUNReqIndiCondLCfg_BswMConfig[] =
{	
	/* Cond_EcuMWakeupIndication_EcuMRequstPostRun_EQ_ECUM_RUNSTATUS_REQUESTED*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		ECUM_RUNSTATUS_REQUESTED,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_EcuMWakeupIndication_EcuMRequstPostRun_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		ECUM_RUNSTATUS_RELEASED,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_EcuMWakeupIndication_EcuMRequstRun_EQ_ECUM_RUNSTATUS_REQUESTED*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		ECUM_RUNSTATUS_REQUESTED,      
	    /* portIdx */ 
		1U,   
	},	
	/* Cond_EcuMWakeupIndication_EcuMRequstRun_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		ECUM_RUNSTATUS_RELEASED,      
	    /* portIdx */ 
		1U,   
	},	
	/* Cond_EcuMWakeupIndication_EcuMRequstShutDown_EQ_ECUM_RUNSTATUS_RELEASED*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		ECUM_RUNSTATUS_RELEASED,      
	    /* portIdx */ 
		2U,   
	},
};

/*******************BswMGenericRequest****************************/
/*Generic request ports*/
static CONST(BswM_GenericReqPortLCfgType, BSWM_CONST)
BswM_GenericReqPortLCfg_BswMConfig[] = 
{	
	/* ReqPort_LIN_VOLTAGE*/
	{
		/* requestedId */    
		241U,
		/* process */
		BSWM_IMMEDIATE,	
		/* modeMax */	
		3U,
	},	
	/* ReqPort_DTC_VOLTAGE*/
	{
		/* requestedId */    
		242U,
		/* process */
		BSWM_IMMEDIATE,	
		/* modeMax */	
		3U,
	},
};
/*BswMGenericRequest condition configure*/
static CONST(BswM_GenericReqCondLCfgType, BSWM_CONST)
BswM_GenericReqCondLCfg_BswMConfig[] =
{	
	/* Cond_LIN_VOLTAGE_NORMAL*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		LIN_VOLTAGE_NORMAL,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_LIN_VOLTAGE_L_7_500*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		LIN_VOLTAGE_L_7_500,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_LIN_VOLTAGE_H_16_5_500*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		LIN_VOLTAGE_H_16_5_500,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_DTC_VOLTAGE_NORMAL*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DTC_VOLTAGE_NORMAL,      
	    /* portIdx */ 
		1U,   
	},	
	/* Cond_DTC_VOLTAGE_L_8_5_500*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DTC_VOLTAGE_L_8_5_500,      
	    /* portIdx */ 
		1U,   
	},	
	/* Cond_DTC_VOLTAGE_H_18_500*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		DTC_VOLTAGE_H_18_500,      
	    /* portIdx */ 
		1U,   
	},
};
/********************** BswMLinSMIndication ***********************/
/*LINSM indication ports*/
static CONST(BswM_LinSMIndiPortLCfgType, BSWM_CONST)
BswM_LinSMIndiPortLCfg_BswMConfig[] = 
{	
	/* ReqPort_LinSm_Channel_Lin*/
	{
		/* linSMChnl */
		ComMChannel_HCML,
		/* process */
		BSWM_IMMEDIATE,			
	},
};
/*BswMLinSMIndication condition configure*/
static CONST(BswM_LinSMIndiCondLCfgType, BSWM_CONST)
BswM_LinSMIndiCondLCfg_BswMConfig[] =
{	
	/* Cond_LinSMIndication_EQ_COMM_NO_COMMUNICATION*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		LINSM_NO_COM,      
	    /* portIdx */ 
		0U,   
	},	
	/* Cond_LinSMIndication_EQ_COMM_FULL_COMMUNICATION*/
	{
		/* conditionType */
		BSWM_EQUALS,		
		/* conditionV */
		LINSM_FULL_COM,      
	    /* portIdx */ 
		0U,   
	},
};

/*
link time configure for actions
*/
/*BswMComMAllowCom action: ComM_CommunicationAllowed*/
static CONST(BswM_ActionComMAllowComLCfgType, BSWM_CONST)
BswM_ActionComMAllowComLCfg_BswMConfig[] =  
{
	/* Action_ComMAllow_Channel_Lin*/
	{
		/* comAllowed */
		TRUE,	
		/* channel */	
		ComMChannel_HCML,					
	},
	/* Action_ComMDisAllowCom_Channel_Lin*/
	{
		/* comAllowed */
		FALSE,	
		/* channel */	
		ComMChannel_HCML,					
	},
}; 
/*BswMEcuMGoDown action:EcuM_GoDown*/
static CONST(BswM_ActionEcuMGoDownLCfgType, BSWM_CONST)
BswM_ActionEcuMGoDownLCfg_BswMConfig[] =
{
	/* Action_EcuM_GoDown*/
	{	
		/* callerId */
		EcuMFlexUserConfig_0,					
	},
}; 
/*BswMEcuMStateSwitch action: EcuM_SetState*/
static CONST(BswM_ActionEcuMStateSwitchLCfgType,BSWM_CONST)
BswM_ActionEcuMStateSwitchLCfg_BswMConfig[] = 
{
	/* Action_EcuM_SetStatus_RUN*/
	{
		/* ecuMState */
		ECUM_STATE_APP_RUN,						
	},
	/* Action_EcuM_SetStatus_POST_RUN*/
	{
		/* ecuMState */
		ECUM_STATE_APP_POST_RUN,						
	},
	/* Action_EcuM_SetStatus_SHUTDOWN*/
	{
		/* ecuMState */
		ECUM_STATE_SHUTDOWN,						
	},
}; 
/*BswMUserCallout action: user custom call out function*/
static CONST(BswM_ActionUserCalloutLCfgType,BSWM_CONST)
BswM_ActionUserCalloutLCfg_BswMConfig[] =
{
	/* Action_CAN_VOLTAGE_NORMAL*/
	{
		/* userCalloutFctPtr */
		GenericRequest_CanVoltage_Normal,							
	},
	/* Action_CAN_VOLTAGE_L_6_5*/
	{
		/* userCalloutFctPtr */
		GenericRequest_CanVoltage_L65,							
	},
	/* Action_CAN_VOLTAGE_L_6_5_500*/
	{
		/* userCalloutFctPtr */
		GenericRequest_CanVoltage_L65_500,							
	},
	/* Action_CAN_VOLTAGE_H_18*/
	{
		/* userCalloutFctPtr */
		GenericRequest_CanVoltage_H18,							
	},
	/* Action_CAN_VOLTAGE_H_18_500*/
	{
		/* userCalloutFctPtr */
		GenericRequest_CanVoltage_H18_500,							
	},
	/* Action_LIN_VOLTAGE_NORMAL*/
	{
		/* userCalloutFctPtr */
		GenericRequest_LinVoltage_Normal,							
	},
	/* Action_LIN_VOLTAGE_L_7_500*/
	{
		/* userCalloutFctPtr */
		GenericRequest_LinVoltage_L7_500,							
	},
	/* Action_LIN_VOLTAGE_H_16_5_500*/
	{
		/* userCalloutFctPtr */
		GenericRequest_LinVoltage_H165_500,							
	},
	/* Action_DTC_VOLTAGE_NORMAL*/
	{
		/* userCalloutFctPtr */
		GenericRequest_DtcVoltage_Normal,							
	},
	/* Action_DTC_VOLTAGE_L_8_5_500*/
	{
		/* userCalloutFctPtr */
		GenericRequest_DtcVoltage_L85_500,							
	},
	/* Action_DTC_VOLTAGE_H_18_500*/
	{
		/* userCalloutFctPtr */
		GenericRequest_DtcVoltage_H18_500,							
	},
	/* Action_NvM_WriteAll*/
	{
		/* userCalloutFctPtr */
		NvM_Action_WriteAll,							
	},
	/* Action_EcuM_RequestRun*/
	{
		/* userCalloutFctPtr */
		BswM_EcuM_RequestRun,							
	},
	/* Action_EcuM_ReleaseRun*/
	{
		/* userCalloutFctPtr */
		BswM_EcuM_ReleaseRun,							
	},
	/* Action_NO_COM_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		NO_COM_Channel_Lin,							
	},
	/* Action_FULL_COM_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		FULL_COM_Channel_Lin,							
	},
	/* Action_DCM_RxEnableGroupSwitch_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		RxEnableGroupSwitch_Channel_Lin,							
	},
	/* Action_DCM_RxDisabledGroupSwitch_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		RxDisabledGroupSwitch_Channel_Lin,							
	},
	/* Action_DCM_TxEnableGroupSwitch_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		TxEnableGroupSwitch_Channel_Lin,							
	},
	/* Action_DCM_TxDisabledGroupSwitch_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		TxDisabledGroupSwitch_Channel_Lin,							
	},
	/* Action_DCM_NmCtrol_Enable_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		DCM_NmCtrol_Enable_Channel_Lin,							
	},
	/* Action_DCM_NmCtrol_Disable_Channel_Lin*/
	{
		/* userCalloutFctPtr */
		DCM_NmCtrol_Disable_Channel_Lin,							
	},
}; 
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
/*type definition for link time configure of partition*/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_PartitionLCfgType, BSWM_CONST) 
BswM_PartLCfg[] =
{
	/*BswMConfig*/
	{
		/* requestPorts */
		{				
			/* comMIndiPortLCfgs */
            BswM_ComMIndiPortLCfg_BswMConfig,              
            /* comMInitRstPortLCfg */
            BswM_ComMInitRstPortLCfg_BswMConfig,  
			NULL_PTR,  			
			/* dcmAppUpdatedIndiPortLCfg */
            BswM_DcmAppUpdatedIndiPortLCfg_BswMConfig,            
            /* dcmComModeReqPortLCfgs */
            BswM_DcmComModeReqPortLCfg_BswMConfig,
			NULL_PTR,            
            /* ecuMRUNReqIndiPortLCfgs */
            BswM_EcuMRUNReqIndiPortLCfg_BswMConfig,
			NULL_PTR,            			
			/* genericReqPortLCfgs */
            BswM_GenericReqPortLCfg_BswMConfig,              			
			/* linSMIndiPortLCfgs */
            BswM_LinSMIndiPortLCfg_BswMConfig,
			NULL_PTR,            	
		},
		/* conditions */
		{	
			NULL_PTR,  
			NULL_PTR, 
			NULL_PTR,            
			NULL_PTR,            
            /* dcmComModeReqCondLCfgs */
            BswM_DcmComModeReqCondLCfg_BswMConfig,            	
			NULL_PTR,               
            /* ecuMRUNReqIndiCondLCfgs */
            BswM_EcuMRUNReqIndiCondLCfg_BswMConfig,
			NULL_PTR,            			
			/* genericReqCondLCfgs */
            BswM_GenericReqCondLCfg_BswMConfig,            			
			/* linSMIndiCondLCfgs */
            BswM_LinSMIndiCondLCfg_BswMConfig,  
			NULL_PTR,              		
		},
		/* expressions */		
        BswM_ExpressionLCfg_BswMConfig,         
		/* actions */
		{			
			/* comMAllowComActions */
            BswM_ActionComMAllowComLCfg_BswMConfig, 
			NULL_PTR, 
			NULL_PTR,             			
			/* ecuMGoDownActions */
            BswM_ActionEcuMGoDownLCfg_BswMConfig,
			NULL_PTR,            
            /* ecuMStateSwitchActions */
            BswM_ActionEcuMStateSwitchLCfg_BswMConfig,            	
			/* userCalloutActions */
            BswM_ActionUserCalloutLCfg_BswMConfig,	             			
		}
	},
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
/*link time BSWM partition configuration*/
CONST(BswM_LCfgType, BSWM_CONST) BswM_LCfg =
{
    /* bswmPartLCfgs */
    BswM_PartLCfg,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

