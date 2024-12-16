/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinSM_cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/12/12 15:33:32                                 **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile parameter definition of LinSM                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                 Includes                                   **
*******************************************************************************/
#include "LinSM.h"

/*******************************************************************************
**                               Configuration                                **
*******************************************************************************/
#define LINSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinSM_MemMap.h"
static CONST(LinSM_ScheduleType, LINSM_CONST)  LinSM_ScheduleData[]=
{
};

static CONST(LinSM_ChannelType, LINSM_CONST)  LinSM_ChannelCfg[LINSM_CHANNEL_NUM] =
{
    
    {
        1000u,                     /* LinSMConfirmationTimeout */
        LINSM_SLAVE,               /* LinSMNodeType */
        0u,  /* LinSMSilenceAfterWakeupTimeout */ 
        STD_OFF,                /* LinSMTransceiverPassiveModeSupport */    
        FALSE,                    /* LinSMTransceiverPassiveMode */        
        ComMChannel_RLM_RS,                        /* LinSMComMNetworkHandleRef */
        NULL_PTR,    /* LinSMSchedule */
        0u                        /* LinSMScheduleNum */    
    },    
    {
        1000u,                     /* LinSMConfirmationTimeout */
        LINSM_SLAVE,               /* LinSMNodeType */
        0u,  /* LinSMSilenceAfterWakeupTimeout */ 
        STD_OFF,                /* LinSMTransceiverPassiveModeSupport */    
        FALSE,                    /* LinSMTransceiverPassiveMode */        
        ComMChannel_HCML,                        /* LinSMComMNetworkHandleRef */
        NULL_PTR,    /* LinSMSchedule */
        0u                        /* LinSMScheduleNum */    
    },
};

CONST(LinSM_ConfigType, LINSM_CONST)  LinSM_PCConfig =
{
    2,                  /* LinSMModeRequestRepetitionMax */
    LinSM_ChannelCfg    /* LinSMChannel */
};
#define LINSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinSM_MemMap.h"

