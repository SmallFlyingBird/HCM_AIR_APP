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
**  FILENAME    : BswM_WdgM.c                                                 **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_WdgM.h"

#if (BSWM_WDGM_ENABLED == STD_ON)
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

/**
 * Function called by WdgM to request a partition reset.
 * Service ID: 0x11
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Application, The identifier of an OS-Application
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_WDGM_CODE)
BswM_WdgM_RequestPartitionReset(ApplicationType Application)
{
#if (BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)
    P2CONST(BswM_EventRqstPortLCfgType, AUTOMATIC, BSWM_CONST) evRqstLCfgPtr;
    P2VAR(BswM_EventRquestPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) evRqstPtr;
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    P2CONST(BswM_PartitionPCCfgType, TYPEDEF, BSWM_CONST) bswmPartPCCfgs;
    P2CONST(BswM_PartitionLCfgType, TYPEDEF, BSWM_CONST) bswmPartLCfgs;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType idx;
    BswM_RuleIndexType ruleIdx;
    BswM_EventRqstPortIdxType evIdx;
    ApplicationType partIdx;
    boolean result;
    uint8 numOfWdgmRstEv;
    uint8 wdgIdx;

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == BswM_DetChkWgmParRst())
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            bswmPartPCCfgs = &(BswM_RuntimeStatus.bswmPartPCCfgs[partIdx]);
            bswmPartLCfgs = &(BswM_RuntimeStatus.bswmPartLCfgs[partIdx]);
            numOfWdgmRstEv = bswmPartPCCfgs->evRqstPCCfg->numOfWdgmRstEv;
            evRqstLCfgPtr = bswmPartLCfgs->evRqstLCfg;
            for (wdgIdx = 0u; wdgIdx < numOfWdgmRstEv; wdgIdx++)
            {
                if (Application == evRqstLCfgPtr->wdgAppRef[wdgIdx])
                {
                    evIdx = bswmPartPCCfgs->evRqstPCCfg->wdgmRqstParRstEvIdxPtr[wdgIdx];
                    evRqstPtr = bswmPartPCCfgs->eventRqstPortRunPtr;
                    evRqstPtr[evIdx] = BSWM_EVENT_IS_SET;
                    if (BSWM_IMMEDIATE == evRqstLCfgPtr->wdgMRqstParReset[wdgIdx].process)
                    {
                        numOfRules = evRqstLCfgPtr->wdgMRqstParReset[wdgIdx].belongToRlueNum;
                        ruleLCfgPtr = bswmPartLCfgs->ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = evRqstLCfgPtr->wdgMRqstParReset[wdgIdx].belongToRlue[idx];
                            if ((boolean)FALSE == ruleLCfgPtr[ruleIdx].isNestExe)
                            {
                                /* An Independent rule,to be evaluated each time applicable*/
                                BswM_ArbitrateRule(ruleIdx, partIdx);
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
#else
    BSWM_PARA_UNUSED(Application);
#endif /*(BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)*/
}

#if (BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)
/*Get BswM_WdgM_RequestPartitionReset*/
FUNC(BswM_EventRquestPortRuntimeType, BSWM_NMIF_CODE)
BswM_GetWgmParReset(uint8 wdgIdx)
{
    BswM_EventRquestPortRuntimeType ret = BSWM_INVALID_U8;
    ApplicationType partIdx;
    boolean result;
    BswM_EventRquestPortRuntimeType evIdx;
    P2CONST(BswM_PartitionPCCfgType, TYPEDEF, BSWM_CONST) bswmPartPCCfgs;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        bswmPartPCCfgs = &(BswM_RuntimeStatus.bswmPartPCCfgs[partIdx]);
        evIdx = bswmPartPCCfgs->evRqstPCCfg->wdgmRqstParRstEvIdxPtr[wdgIdx];
        ret = bswmPartPCCfgs->eventRqstPortRunPtr[evIdx];
    }
    return ret;
}
#endif /*(BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)*/

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#endif /*(BSWM_WDGM_ENABLED == STD_ON)*/
