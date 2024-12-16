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
**  FILENAME    : WdgM_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2024/12/16 14:21:13                                         **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of WdgM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "WdgM_CfgType.h"
#include "WdgM_Cfg.h"
#include "WdgM.h"
#include "Os.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



static CONST(WdgM_CPSupprotDeadLineInfoType,WDGM_CONST) WdgMMode_SlowWdgMSE_0SE0_WdgMCP_2SupprotDeadLineInfo[] =
{ 
	{0,2}
};
static CONST(WdgM_CPSupprotDeadLineInfoType,WDGM_CONST) WdgMMode_SlowWdgMSE_0SE0_WdgMCP_1SupprotDeadLineInfo[] =
{ 
	{0,1}
};
static CONST(WdgM_CheckpointCfgType, WDGM_CONST) WdgMMode_SlowWdgMSupervisedEntity_0CPID[]=
{
	/*SE0_WdgMCheckpoint_0 in WdgMMode_SlowWdgMSupervisedEntity_0*/
  	{
  		0,/*WdgMCheckpointId*/  	
      	0x1,/*Supervision Support type*/      	
		0,    /*AliveSup ID*/
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/  
		0xFFFF
  	},
	/*SE0_WdgMCheckpoint_1 in WdgMMode_SlowWdgMSupervisedEntity_0*/
  	{
  		1,/*WdgMCheckpointId*/  	
      	0x2,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	1,/*Quantity of the DeadlineSupervision supported by the CP*/
      	&WdgMMode_SlowWdgMSE_0SE0_WdgMCP_1SupprotDeadLineInfo[0],/*The start address of the DeadlineSupervision ID array*/  
		0xFFFF
  	},
	/*SE0_WdgMCheckpoint_2 in WdgMMode_SlowWdgMSupervisedEntity_0*/
  	{
  		2,/*WdgMCheckpointId*/  	
      	0x2,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	1,/*Quantity of the DeadlineSupervision supported by the CP*/
      	&WdgMMode_SlowWdgMSE_0SE0_WdgMCP_2SupprotDeadLineInfo[0],/*The start address of the DeadlineSupervision ID array*/  
		0xFFFF
  	},
	/*SE0_WdgMCheckpoint_3 in WdgMMode_SlowWdgMSupervisedEntity_0*/
  	{
  		3,/*WdgMCheckpointId*/  	
      	0x1c,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/
		0,  
  	},
	/*SE0_WdgMCheckpoint_4 in WdgMMode_SlowWdgMSupervisedEntity_0*/
  	{
  		4,/*WdgMCheckpointId*/  	
      	0x2c,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/
		0,  
  	},
};

static CONST(WdgM_AliveSupCfgType, WDGM_CONST) WdgMMode_SlowWdgMSupervisedEntity_0AliveSup[]=
{
	/*WdgMAliveSupervision_0*/
	{
		0,		/*AliveSupervision ID*/
		0,		/*WdgMExpectedAliveIndications*/
		1,		/*WdgMSupervisionReferenceCycle*/
		3,		/*WdgMMaxMargin*/
		1,		/*WdgMMinMargin*/
	},

};

static CONST(WdgM_DeadlineSupCfgType, WDGM_CONST) WdgMMode_SlowWdgMSupervisedEntity_0DeadlineSup[]=
{
	/*WdgMDeadlineSupervision_0*/
	{		
		0,					/*DeadlineSupervision ID*/
		1,		/*WdgMDeadlineStartRef*/
		2,		/*WdgMDeadlineStopRef*/
		0.006f,					/*WdgMDeadlineMax*/
		0.004f,					/*WdgMDeadlineMin*/	
		TRUE					/* WdgMEnableTimeoutDetection */	
	},
};


/*The Transition route related to WdgMMode_SlowWdgMSupervisedEntity_0 InternalLogicalSupervison */
static CONST(WdgM_IntTransitionType,WDGM_CONST) WdgMMode_SlowWdgMSupervisedEntity_0IntLogSupTransition[]=
{
	/*WdgMInternalTransition_0*/
	{
		3,/*WdgMTransitionSourceCheckpointID*/
		4,/*WdgMTransitionDestinationCheckpointID*/	
	},
};

static CONST(WdgM_IntLogSupCfgType, WDGM_CONST) WdgMMode_SlowWdgMSupervisedEntity_0IntLogSup[]=
{
	{
		0,/*InternalLogicalSupervision ID*/
		1,
		&WdgMMode_SlowWdgMSupervisedEntity_0IntLogSupTransition[0],
	},
};


static CONST(WdgM_SECfgType, WDGM_CONST) WdgMMode_SlowSE[]=
{
	/* WdgMSupervisedEntity_0 in WdgMMode_Slow*/
	{
		1,	/*WdgMSEId*/		
		5,	/*Quantity of the CPs in this SE*/
		&WdgMMode_SlowWdgMSupervisedEntity_0CPID[0],	/*The start address of the CP arraies*/		
		1,/*Quantity of the AliveSupervisions in this SE*/
 		&WdgMMode_SlowWdgMSupervisedEntity_0AliveSup[0],		/*The start address of the AliveSupervision arraies*/			
		1,/*Quantity of the DeadlineSupervisions in this SE*/
		&WdgMMode_SlowWdgMSupervisedEntity_0DeadlineSup[0],		/*The start address of the DeadLineSupervision arraies*/		
		1,/*Quantity of the InterLogicalSupervisions in this SE*/
		&WdgMMode_SlowWdgMSupervisedEntity_0IntLogSup[0],
		0,/*WdgMFailedAliveSupervisionRefCycleTol:Acceptable quantity of the WdgM_Mainfunction cycle in incorrect/failed status*/
		0xFF,/*WdgMEcucPartitionRef:EcucPartition Symboic name*/		 
		0xFFFF,	/*WdgMOsApplicationRef:The OS_Application ID*/	
	},
};


static CONST(WdgM_TriggerType, WDGM_CONST) WdgMMode_SlowTrigger[]=
{    
	/*WdgMTrigger_0*/
	{
		WDGIF_SLOW_MODE,	/*OFF/SLOW/FAST Mode*/
		10000,					/*Parameter passed to the WdgIf_SetTriggerCondition*/
		WDGM_WATCHDOG_0,		/*Trigger Watchdog Ref*/	
	},
};


static CONST(WdgM_CheckpointCfgType, WDGM_CONST) WdgMMode_FastWdgMSupervisedEntity_0CPID[]=
{
	/*SE0_WdgMCheckpoint_0 in WdgMMode_FastWdgMSupervisedEntity_0*/
  	{
  		0,/*WdgMCheckpointId*/  	
      	0x1,/*Supervision Support type*/      	
		0,    /*AliveSup ID*/
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/  
		0xFFFF
  	},
	/*SE0_WdgMCheckpoint_1 in WdgMMode_FastWdgMSupervisedEntity_0*/
  	{
  		1,/*WdgMCheckpointId*/  	
      	0x0,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/  
		0xFFFF
  	},
	/*SE0_WdgMCheckpoint_2 in WdgMMode_FastWdgMSupervisedEntity_0*/
  	{
  		2,/*WdgMCheckpointId*/  	
      	0x0,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/  
		0xFFFF
  	},
	/*SE0_WdgMCheckpoint_3 in WdgMMode_FastWdgMSupervisedEntity_0*/
  	{
  		3,/*WdgMCheckpointId*/  	
      	0x1c,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/
		0,  
  	},
	/*SE0_WdgMCheckpoint_4 in WdgMMode_FastWdgMSupervisedEntity_0*/
  	{
  		4,/*WdgMCheckpointId*/  	
      	0x2c,/*Supervision Support type*/ 		
		0xFFFF,	/*AliveSup ID*/        	
      	0,/*Quantity of the DeadlineSupervision supported by the CP*/
      	NULL_PTR,/*The start address of the DeadlineSupervision ID array*/
		0,  
  	},
};

static CONST(WdgM_AliveSupCfgType, WDGM_CONST) WdgMMode_FastWdgMSupervisedEntity_0AliveSup[]=
{
	/*WdgMAliveSupervision_0*/
	{
		0,		/*AliveSupervision ID*/
		4,		/*WdgMExpectedAliveIndications*/
		1,		/*WdgMSupervisionReferenceCycle*/
		1,		/*WdgMMaxMargin*/
		1,		/*WdgMMinMargin*/
	},

};



/*The Transition route related to WdgMMode_FastWdgMSupervisedEntity_0 InternalLogicalSupervison */
static CONST(WdgM_IntTransitionType,WDGM_CONST) WdgMMode_FastWdgMSupervisedEntity_0IntLogSupTransition[]=
{
	/*WdgMInternalTransition_0*/
	{
		3,/*WdgMTransitionSourceCheckpointID*/
		4,/*WdgMTransitionDestinationCheckpointID*/	
	},
};

static CONST(WdgM_IntLogSupCfgType, WDGM_CONST) WdgMMode_FastWdgMSupervisedEntity_0IntLogSup[]=
{
	{
		0,/*InternalLogicalSupervision ID*/
		1,
		&WdgMMode_FastWdgMSupervisedEntity_0IntLogSupTransition[0],
	},
};


static CONST(WdgM_SECfgType, WDGM_CONST) WdgMMode_FastSE[]=
{
	/* WdgMSupervisedEntity_0 in WdgMMode_Fast*/
	{
		1,	/*WdgMSEId*/		
		5,	/*Quantity of the CPs in this SE*/
		&WdgMMode_FastWdgMSupervisedEntity_0CPID[0],	/*The start address of the CP arraies*/		
		1,/*Quantity of the AliveSupervisions in this SE*/
 		&WdgMMode_FastWdgMSupervisedEntity_0AliveSup[0],		/*The start address of the AliveSupervision arraies*/	
		0,/*Quantity of the DeadlineSupervisions in this SE*/
		NULL_PTR,/*The start address of the DeadLineSupervision arraies*/	
		1,/*Quantity of the InterLogicalSupervisions in this SE*/
		&WdgMMode_FastWdgMSupervisedEntity_0IntLogSup[0],
		0,/*WdgMFailedAliveSupervisionRefCycleTol:Acceptable quantity of the WdgM_Mainfunction cycle in incorrect/failed status*/
		0xFF,/*WdgMEcucPartitionRef:EcucPartition Symboic name*/		 
		0xFFFF,	/*WdgMOsApplicationRef:The OS_Application ID*/	
	},
};


static CONST(WdgM_TriggerType, WDGM_CONST) WdgMMode_FastTrigger[]=
{    
	/*WdgMTrigger_0*/
	{
		WDGIF_FAST_MODE,	/*OFF/SLOW/FAST Mode*/
		100,					/*Parameter passed to the WdgIf_SetTriggerCondition*/
		WDGM_WATCHDOG_0,		/*Trigger Watchdog Ref*/	
	},
};


static CONST(WdgM_TriggerType, WDGM_CONST) OFFModeTrigger[]=
{
	/*Trigger 0*/
	{
		WDGIF_OFF_MODE,
		1,					/*Parameter passed to the WdgIf_SetTriggerCondition*/
		WDGM_WATCHDOG_0,		/*Trigger Watchdog Ref*/		
	},
};

static CONST(WdgM_ModeCfgType, WDGM_CONST) WdgMMode[]=
{
	/*WdgMMode_OffMode*/
	{
		0,  
		0,	
		0,	
		NULL_PTR,	         
		0,
		NULL_PTR,  
		1,
		&OFFModeTrigger[0],			    
	},
	/*WdgMMode_Slow*/
	{
		1,	/*ModeID*/
		0,	/*WdgMExpiredSupervisionCycleTol*/
	    1,	/*Quantity of WdgMLocalStatusParams*/
	    &WdgMMode_SlowSE[0],	/*WdgMSECfgRelated*/
	    0,	/*Quantity of all the ExternalLogicalSupervisions in this Mode*/
	    NULL_PTR, 	/*ExternalLogicalSupervision*/
	    1,	/*Quantity of all the Triggers in this Mode*/
	    &WdgMMode_SlowTrigger[0],	/*WdgMTrigger*/	
	},
	/*WdgMMode_Fast*/
	{
		2,	/*ModeID*/
		0,	/*WdgMExpiredSupervisionCycleTol*/
	    1,	/*Quantity of WdgMLocalStatusParams*/
	    &WdgMMode_FastSE[0],	/*WdgMSECfgRelated*/
	    0,	/*Quantity of all the ExternalLogicalSupervisions in this Mode*/
	    NULL_PTR, 	/*ExternalLogicalSupervision*/
	    1,	/*Quantity of all the Triggers in this Mode*/
	    &WdgMMode_FastTrigger[0],	/*WdgMTrigger*/	
	},
};

/* Declaration of WdgM Post Build Configuration */
const WdgM_ConfigType WdgMConfigRoot[] =
{
	{
		1,				/*Initial Mode Id*/
		3,				/*Quantity of all Mode*/
		&WdgMMode[0],  	 /*The start address of the Mode array*/
	}
};

const WdgM_SupervisedEntityIdType WdgM_SupervisedEntityToTabIndex[]={1};
const uint16 WdgM_CheckpointQuantityInSE[]={5};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
