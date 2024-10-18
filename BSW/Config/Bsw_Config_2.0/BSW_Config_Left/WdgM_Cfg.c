/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
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
**  Created on  : 2024/08/06 09:28:31                                         **
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
#include "WdgM_MemMap.h"

/* PRQA S 0779 ++ */ /* MISRA Rule1.3 */ /* PRQA S 0779 ++ */ /* MISRA Rule5.2 */
static CONST(WdgM_CheckpointCfgType, WDGM_CONST) WdgMMode_0WdgMSupervisedEntity_0CPID[]=
/* PRQA S 0779 -- */ /* MISRA Rule1.3 */ /* PRQA S 0779 -- */ /* MISRA Rule5.2 */
{
    /*SE0_WdgMCheckpoint_Alive_10ms in WdgMMode_0WdgMSupervisedEntity_0*/
      {
          0,/*WdgMCheckpointId*/
          0x1,/*Supervision Support type*/
          0,    /*AliveSup ID*/
          0,/*Quantity of the DeadlineSupervision supported by the CP*/
          NULL_PTR,/*The start address of the DeadlineSupervision ID array*/
          0xFFFF
      },
};

/* PRQA S 0779 ++ */ /* MISRA Rule1.3 */ /* PRQA S 0779 ++ */ /* MISRA Rule5.2 */
static CONST(WdgM_AliveSupCfgType, WDGM_CONST) WdgMMode_0WdgMSupervisedEntity_0AliveSup[]=
/* PRQA S 0779 -- */ /* MISRA Rule1.3 */ /* PRQA S 0779 -- */ /* MISRA Rule5.2 */
{
    /*WdgMAliveSupervision_0*/
    {
        0,        /*AliveSupervision ID*/
        20,        /*WdgMExpectedAliveIndications*/
        40,        /*WdgMSupervisionReferenceCycle*/
        10,        /*WdgMMaxMargin*/
        18,        /*WdgMMinMargin*/
    },

};

/*The Transition route related to WdgMMode_0WdgMSupervisedEntity_0 InternalLogicalSupervison */

static CONST(WdgM_SECfgType, WDGM_CONST) WdgMMode_0SE[]=
{
    /* WdgMSupervisedEntity_0 in WdgMMode_0*/
    {
        1,    /*WdgMSEId*/
        1,    /*Quantity of the CPs in this SE*/
        &WdgMMode_0WdgMSupervisedEntity_0CPID[0],    /*The start address of the CP arraies*/
        1,/*Quantity of the AliveSupervisions in this SE*/
        &WdgMMode_0WdgMSupervisedEntity_0AliveSup[0],   /*The start address of the AliveSupervision arraies*/
        0,/*Quantity of the DeadlineSupervisions in this SE*/
        NULL_PTR,/*The start address of the DeadLineSupervision arraies*/
        0,/*Quantity of the InterLogicalSupervisions in this SE*/
        NULL_PTR,  /*The start address of the InterLogicalSupervision arraies*/
        0,/*WdgMFailedAliveSupervisionRefCycleTol:Acceptable quantity of the WdgM_Mainfunction cycle in incorrect/failed status*/
        0xFF,/*WdgMEcucPartitionRef:EcucPartition Symboic name*/
        0xFFFF,    /*WdgMOsApplicationRef:The OS_Application ID*/
    },
};

static CONST(WdgM_TriggerType, WDGM_CONST) WdgMMode_0Trigger[]=
{
    /*WdgMTrigger_0*/
    {
        WDGIF_SLOW_MODE,    /*OFF/SLOW/FAST Mode*/
        3000,                    /*Parameter passed to the WdgIf_SetTriggerCondition*/
        WDGM_WATCHDOG_0,        /*Trigger Watchdog Ref*/
    },
};

static CONST(WdgM_TriggerType, WDGM_CONST) OFFModeTrigger[]=
{

    /*Trigger 0*/
    {
        WDGIF_OFF_MODE,
        3000,                    /*Parameter passed to the WdgIf_SetTriggerCondition*/
        WDGM_WATCHDOG_0,        /*Trigger Watchdog Ref*/
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
    /*WdgMMode_0*/
    {
        1,    /*ModeID*/
        0,    /*WdgMExpiredSupervisionCycleTol*/
        1,    /*Quantity of WdgMLocalStatusParams*/
        &WdgMMode_0SE[0],    /*WdgMSECfgRelated*/
        0,    /*Quantity of all the ExternalLogicalSupervisions in this Mode*/
        NULL_PTR,       /*ExternalLogicalSupervision*/
        1,    /*Quantity of all the Triggers in this Mode*/
        &WdgMMode_0Trigger[0],    /*WdgMTrigger*/
    },
};

/* Declaration of WdgM Post Build Configuration */
/* PRQA S 1533 ++ */ /* MISRA Rule8.9 */
const WdgM_ConfigType WdgMConfigRoot[] =
{
    {
        0,                /*Initial Mode Id*/
        2,                /*Quantity of all Mode*/
        &WdgMMode[0],       /*The start address of the Mode array*/
    }
};

const WdgM_SupervisedEntityIdType WdgM_SupervisedEntityToTabIndex[]={1};
const uint16 WdgM_CheckpointQuantityInSE[]={1};
/* PRQA S 1533 -- */ /* MISRA Rule8.9 */

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "WdgM_MemMap.h"

