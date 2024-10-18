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
**  FILENAME    : BswM_EthSM.c                                                **
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
#include "BswM_EthSM.h"
#if (BSWM_ETHSM_ENABLED == STD_ON)
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
/*Initialize BswMEthSMIndication request port*/
FUNC(void, BSWM_ETHSM_CODE)
BswM_InitEthSMRequestPorts(void)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    P2CONST(BswM_PartitionPCCfgType, TYPEDEF, BSWM_CONST) bswmPartPCCfgs;
    ApplicationType partIdx;
    boolean result;
    NetworkHandleType numOfEthSMInd;
    NetworkHandleType ethsmIdx;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        bswmPartPCCfgs = &(BswM_RuntimeStatus.bswmPartPCCfgs[partIdx]);
        modeRqstPCfgPtr = bswmPartPCCfgs->modeRqstPCCfg;
        modeRqstPtr = bswmPartPCCfgs->modeRqstPortRunPtr;
        numOfEthSMInd = modeRqstPCfgPtr->numOfEthSMInd;
        for (ethsmIdx = 0u; ethsmIdx < numOfEthSMInd; ethsmIdx++)
        {
            if (NULL_PTR != modeRqstPCfgPtr->ethsmInitState)
            {
                modeRqstPtr->ethSMIndiStatus[ethsmIdx] = *(modeRqstPCfgPtr->ethsmInitState);
            }
            else
            {
                break;
            }
        }
    }
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError(BSWM_MODULE_ID, BSWM_INSTANCE_ID, BSWM_API_ID_INIT, BSWM_E_INIT_FAILED);
    }
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
}

/**
 * Function called by EthSM to indicate its current state.
 * Service ID: 0x0d
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, the Ethernet channel that the indicated state corresponds to
 *                 CurrentState, the current state of the Ethernet channel
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_ETHSM_CODE)
BswM_EthSM_CurrentState(NetworkHandleType Network, EthSM_NetworkModeStateType CurrentState)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortLCfgType, AUTOMATIC, BSWM_CONST) modeRqstLCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    P2CONST(BswM_PartitionPCCfgType, TYPEDEF, BSWM_CONST) bswmPartPCCfgs;
    P2CONST(BswM_PartitionLCfgType, TYPEDEF, BSWM_CONST) bswmPartLCfgs;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType idx;
    BswM_RuleIndexType ruleIdx;
    ApplicationType partIdx;
    boolean result;
    NetworkHandleType numOfEthsmCh;
    NetworkHandleType chIdx;

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == BswM_DetChkEthSMInd(CurrentState))
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            bswmPartPCCfgs = &(BswM_RuntimeStatus.bswmPartPCCfgs[partIdx]);
            bswmPartLCfgs = &(BswM_RuntimeStatus.bswmPartLCfgs[partIdx]);
            modeRqstPCfgPtr = bswmPartPCCfgs->modeRqstPCCfg;
            modeRqstLCfgPtr = bswmPartLCfgs->modeRqstLCfg;
            numOfEthsmCh = modeRqstPCfgPtr->numOfEthSMInd;
            for (chIdx = 0u; chIdx < numOfEthsmCh; chIdx++)
            {
                if (Network == modeRqstLCfgPtr->ethsmChRef[chIdx])
                {
                    modeRqstPtr = bswmPartPCCfgs->modeRqstPortRunPtr;
                    modeRqstPtr->ethSMIndiStatus[chIdx] = CurrentState;
                    if (BSWM_IMMEDIATE == modeRqstLCfgPtr->ethsmInd[chIdx].process)
                    {
                        numOfRules = modeRqstLCfgPtr->ethsmInd[chIdx].belongToRlueNum;
                        ruleLCfgPtr = bswmPartLCfgs->ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = modeRqstLCfgPtr->ethsmInd[chIdx].belongToRlue[idx];
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
}

/*Get ethsm indicate status*/
FUNC(EthSM_NetworkModeStateType, BSWM_ETHSM_CODE)
BswM_GetEthSmIndStatus(NetworkHandleType ethsmChIdx)
{
    EthSM_NetworkModeStateType retStatus = ETHSM_STATE_OFFLINE;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        retStatus = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr->ethSMIndiStatus[ethsmChIdx];
    }
    return retStatus;
}
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#endif /*(BSWM_ETHSM_ENABLED == STD_ON)*/
