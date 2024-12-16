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
**  FILENAME    : BswM_Cfg.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : stanleyluo                                                  **
**  Vendor      :                                                             **
**  DESCRIPTION : pre-compile configure parameter definitions of BSWM         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platfrom 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#include "BswM.h"

static CONST(BswM_PartitionPCCfgType, BSWM_CONST) BswM_PartitionPCCfg[] =
{
	/* BswMConfig*/
	{
		/* numOfPort */  
		{					
			/* numOfComMIndi */                                                
            1U,
            /* numOfComMInitReset */                                            
            1U,
            /* numOfComMPncReq */                                               
            0U,			
			/* numOfDcmAppUpdatedIndi */                                        
            1U,
            /* numOfDcmComModeReq */                                            
            1U,			
			/* numOfEcuMIndi */                                                 
            0U,
            /* numOfEcuMRUNReqIndi */                                           
            3U,
            /* numOfEcuMWakeupSource */                                        
            0U,			
			/* numOfGenericReq */                                               
            2U,			
			/* numOfLinSMIndi */                                               
            1U,
            /* numOfLinSchIndi */                                              
            0U,
		},
		/* numOfCondition */
		{			
			/* numOfComMIndiCond */                                          
            0U,
            /* numOfComMInitResetCond */                                       
            0U,
            /* numOfComMPncReqCond */                                          
            0U,			
			/* numOfDcmAppUpdatedIndiCond */                                   
            0U,
            /* numOfDcmComModeReqCond */                                     
            12U,			
			/* numOfEcuMIndiCond */                                            
            0U,
            /* numOfEcuMRUNReqIndiCond */                                     
            5U,
            /* numOfEcuMWakeupSourceCond */                                     
            0U,			
			/* numOfGenericReqCond */                                          
            6U,			
			/* numOfLinSMIndiCond */                                            
            2U,
            /* numOfLinSchIndiCond */                                           
            0U,			
		},
		/* numOfExpression */ 
        18U,
		/* numOfAction */  
		{			
			/* numOfComMAllowCom */                                             
            2U,
            /* numOfComMModeLimit */                                            
            0U,
            /* numOfComMModeSwitch */                                          
            0U,				
			/* numOfEcuMGoDown */                                              
            1U,
            /* numOfEcuMSelectShutTgt */                                        
            0U,
            /* numOfEcuMStateSwitch */                                          
            3U,			
			/* numOfLinSCheduleSwitch */                                       
            0U,		
			/* numOfUserCallout */                                              
            22U,
		}
	},
};

/* -------------------------------
^^^^^^^^^^runtime var ^^^^^^^^^^^
---------------------------------*/
/*BswMComMIndication*/
static VAR(ComM_ModeType, BSWM_VAR_CLEARED)
BswM_comMIndiStatus_BswMConfig[1];  
/*BswMDcmComModeRequest*/
static VAR(Dcm_CommunicationModeType, BSWM_VAR_CLEARED)
BswM_dcmComModeReqStatus_BswMConfig[1];    
/*BswMEcuMRUNRequestIndication*/
static VAR(EcuM_RunStatusType, BSWM_VAR_CLEARED)
BswM_ecuMRUNReqIndiStatus_BswMConfig[3]; 
/*BswMGenericRequest*/
static VAR(BswM_ModeType, BSWM_VAR_CLEARED) 
BswM_genericReqStatus_BswMConfig[2];    
/*BswMLinSMIndication*/
static VAR(LinSM_ModeType, BSWM_VAR_CLEARED) 
BswM_linSMIndiStatus_BswMConfig[1];         
/* ipdu group vector Com_ReceptionDMControl */
static VAR(Com_IpduGroupVector, BSWM_VAR_CLEARED)
BswM_comRxDmIpduGroupVector_BswMConfig[1];                                                
/* ipdu group vector Com_IpduGroupControl */
static VAR(Com_IpduGroupVector, BSWM_VAR_CLEARED)
BswM_comTxIpduGroupVecotr_BswMConfig[1];    

static VAR(BswM_PartitionRuntimeType, BSWM_VAR_CLEARED) 
BswM_PartitionRuntime[1] =
{
   /* BswMConfig */
  {
	/* comMIndiStatus */
    BswM_comMIndiStatus_BswMConfig, 
    /* comMInitResetStatus */
    FALSE,
	NULL_PTR, 
	/* dcmAppUpdatedIndiStatus */
    FALSE,
    /* dcmComModeReqStatus */
    BswM_dcmComModeReqStatus_BswMConfig,     	
	/* ecuMState */
    ECUM_STATE_RUN,
    /* ecuMRUNReqIndiStatus */
    BswM_ecuMRUNReqIndiStatus_BswMConfig, 
	NULL_PTR,
	/* genericReqStatus */
    BswM_genericReqStatus_BswMConfig,  	
	/* linSMIndiStatus */
    BswM_linSMIndiStatus_BswMConfig, 
	NULL_PTR,      
	/* ruleStatus */
    {
        0u,                             
    },
    /* ruleNeedArbitrate */
    {
        FALSE,                         
    },
  },
};

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
CONST(BswM_PCCfgType, BSWM_CONST) BswM_PCCfg =
{
    /* numOfPartitions */
    1U,                                                                         
    /* bswmPartPCCfgs */
    BswM_PartitionPCCfg,
    /* bswmPartsRunPtr */
    BswM_PartitionRuntime,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
