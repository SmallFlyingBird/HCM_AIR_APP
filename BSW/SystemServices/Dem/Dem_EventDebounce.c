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
**  FILENAME    : Dem_EventDebounce.c                                         **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : DEM EventDebounce API definitions                           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Internal.h"
#if (STD_ON == DEM_TRIGGER_FIM_REPORTS)
#include "FiM.h"
#endif

/*******************************************************************************
**                      macros  define                                        **
*******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(FDCInfoType, AUTOMATIC) FDCInfo[DEM_DTC_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
/* Debounce Counter Base Info Define */

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_DebounceCounterInfoType, AUTOMATIC) DemDebounceCounterInfo[DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM];
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
VAR(Dem_DebounceTimeInfoType, AUTOMATIC) DemDebounceTimerInfo[DEM_DEBOUNCE_TIME_BASED_EVENT_NUM];
#endif
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DEM_LOCAL FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessCounter(
    Dem_EventDataBufferType pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg);
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
DEM_LOCAL FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessTimer(
    Dem_EventDataBufferType pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg);
#endif
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Dem_DebounceInit
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceInit(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
    for (uint16 iloop = 0; iloop < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM; iloop++)
    {
        Dem_DebounceCounterInfoType* pDemDebounceCounterInfo = &DemDebounceCounterInfo[iloop];
        pDemDebounceCounterInfo->InternalDebounceCounter = 0;
    }
#endif /* DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u */
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
    for (uint16 iloop = 0; iloop < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM; iloop++)
    {
        Dem_DebounceTimeInfoType* pDemDebounceTimerInfo = &DemDebounceTimerInfo[iloop];
        pDemDebounceTimerInfo->Timeout = 0x00;
        pDemDebounceTimerInfo->Triggered = FALSE;
        pDemDebounceTimerInfo->CurStatus = DEM_EVENT_STATUS_PREPASSED;
    }
#endif /* DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u */
    Dem_MemSet((uint8*)FDCInfo, 0x00u, (sizeof(FDCInfoType) * DEM_DTC_NUM));
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_DebounceReset
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceReset(Dem_EventIdType IntId)
{
    const Dem_EventParameterType* pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];

#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
    Dem_DebounceCounterInfoType* pCounter;
#endif /* DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u */
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
    Dem_DebounceTimeInfoType* pTimer;
#endif /*DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u */
#if ((DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u) || (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u))
    const uint16 AlgorithmIndex = pEventCfg->AlgorithmIndex;
#endif /* (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)||(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u) */
    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    case DEM_DEBOUNCE_COUNTER_BASED:
        if (AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
        {
            pCounter = &DemDebounceCounterInfo[AlgorithmIndex];
            pCounter->InternalDebounceCounter = 0;
        }
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    case DEM_DEBOUNCE_TIME_BASE:
        if (AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
        {
            pTimer = &DemDebounceTimerInfo[AlgorithmIndex];
            pTimer->Timeout = 0;
            pTimer->Triggered = FALSE;
            pTimer->CurStatus = DEM_EVENT_STATUS_PREPASSED;
        }
        break;
#endif
    default:
        /*idle*/
        break;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_GetInteralFDC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              sint8
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetInteralFDC(Dem_EventIdType IntId, P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    const Dem_EventParameterType* pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
    Std_ReturnType ret = E_NOT_OK;
#if (                                                                                      \
    (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u) || (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u) \
    || (DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0u))
    uint16 AlgorithmRef = pEventCfg->AlgorithmRef;
#endif /* (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u) || (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u) || \
          (DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0u) */
    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_COUNTER_BASED: /*SWS_Dem_00415*/
        if ((AlgorithmRef < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)
            && ((pEventCfg->AlgorithmIndex) < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
        {
            const Dem_DebounceCounterBasedClassType* pCfgCounter =
                &DemPbCfgPtr->DemDebounceCounterBasedClass[AlgorithmRef];
            Dem_DebounceCounterInfoType* pCounter = &DemDebounceCounterInfo[pEventCfg->AlgorithmIndex];
            sint16 InternalDebounceCounter = pCounter->InternalDebounceCounter;
            if (InternalDebounceCounter > 0)
            {
                *FaultDetectionCounter =
                    (sint8)((InternalDebounceCounter * 127) / pCfgCounter->DemDebounceCounterFailedThreshold);
            }
            else
            {
                *FaultDetectionCounter =
                    (sint8)((InternalDebounceCounter * (-128)) / pCfgCounter->DemDebounceCounterPassedThreshold);
            }
            ret = E_OK;
        }
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_TIME_BASE: /*SWS_Dem_00427*/
        if ((AlgorithmRef < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM)
            && ((pEventCfg->AlgorithmIndex) < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
        {
            Dem_DebounceTimeInfoType* pTimer = &DemDebounceTimerInfo[pEventCfg->AlgorithmIndex];
            const Dem_DebounceTimeBaseClassType* pTimerCfg = &DemPbCfgPtr->DemDebounceTimeBaseClass[AlgorithmRef];
            uint64 Timeout = pTimer->Timeout;

            /* PRQA S 4394++ */ /* MISRA Rule 10.8 */
            switch (pTimer->CurStatus)
            {
            case DEM_EVENT_STATUS_FAILED:
            case DEM_EVENT_STATUS_PREFAILED:
                *FaultDetectionCounter = (sint8)((Timeout * 127UL) / (uint64)pTimerCfg->DemDebounceTimeFailedThreshold);
                break;
            default:
                *FaultDetectionCounter =
                    ((sint8)(-1)) * ((sint8)((Timeout * 128UL) / (uint64)pTimerCfg->DemDebounceTimePassedThreshold));
                break;
            }
            /* PRQA S 4394-- */ /* MISRA Rule 10.8 */
            ret = E_OK;
        }
        break;
#endif
#if (DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0u)
    case DEM_DEBOUNCE_MONITOR_INTERNAL: /*SWS_Dem_00264] */
        if (AlgorithmRef < DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM)
        {
            Dem_GetFDCFncType GetFnc = DemGetFDCFncs[AlgorithmRef];
            *FaultDetectionCounter = 0;
            if (GetFnc != NULL_PTR)
            { /*SWS_Dem_00439] */
                ret = GetFnc(FaultDetectionCounter);
                if (E_OK != ret)
                {
                    *FaultDetectionCounter = 0;
                }
            }
            else
            {
                ret = DEM_E_NO_FDC_AVAILABLE;
            }
        }
        break;
#endif
    default:
        *FaultDetectionCounter = 0;
        break;
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_DebounceProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEventBuffer
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_EventStatusType, DEM_CODE)
/* PRQA S 1532，3432++ */ /* MISRA Rule 8.7，Rule 20.7 */
Dem_DebounceProcess(Dem_EventDataBufferType pEventBuffer)
/* PRQA S 1532，3432-- */ /* MISRA Rule 8.7，Rule 20.7 */
{
    Dem_EventIdType IntId = Dem_GetEventInternalId(pEventBuffer.ExtId);
    const Dem_EventParameterType* pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
    Dem_EventStatusType Status = pEventBuffer.Status;
    Dem_EventRelateInformationType* pEvent = Dem_GetEventInfo(IntId);
    uint8 AlgorithmType = pEventCfg->AlgorithmType;
#if (DEM_TRIGGERONFDCTHRESHOLDEANLE == STD_ON)
    uint16 DemDTCRef = pEventCfg->DemDTCRef;
    sint8 FDC;
#endif /* DEM_TRIGGERONFDCTHRESHOLDEANLE == STD_ON */
    switch (AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_COUNTER_BASED:
        Status = Dem_DebounceProcessCounter(pEventBuffer, pEventCfg);
        break;
#endif /* DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u */
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_TIME_BASE:
        Status = Dem_DebounceProcessTimer(pEventBuffer, pEventCfg);
        break;
#endif /* DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u */
    default:
        /*idle*/
        break;
    }
    /* if event failed clear anging counter*/
    if (DEM_EVENT_STATUS_FAILED == Status)
    {
        pEvent->AgingCounter = 0u;
        Dem_EventQueueAddDebounceFailed(pEvent);
    }
#if (DEM_TRIGGERONFDCTHRESHOLDEANLE == STD_ON)
    /*SWS_Dem_00786][SWS_Dem_01068][SWS_Dem_00811] [SWS_Dem_01069]*/
    Dem_UpdateFDC(IntId);
    FDC = FDCInfo[DemDTCRef].FDC;

#if (DEM_OCC4EANLE == STD_ON)
    if ((DemDTCRef != DEM_DTC_REF_INVALID) && (FDC > 0) &&
         (127 <= (uint8)FDC)
        && (DEM_DEBOUNCE_COUNTER_BASED == AlgorithmType))
        {
            if(pEvent->OCC4_Increased == FALSE)
            {
                pEvent->OCC4_Increased = TRUE;
                /* In each operaƟon cycle the counter shall be incremented as soon as FDC10 has reached a value that is equal to
                * or greater than its unconﬁrmedDTCLimit for the ﬁrst Ɵme. */
                if (pEvent->OCC4 < 0xFFu)
                {
                    pEvent->OCC4++;
                }
            }
        }
#endif /* DEM_OCC4EANLE == STD_ON */

    if ((DemDTCRef != DEM_DTC_REF_INVALID) && (FDC > 0)
         /* (DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[DemDTCRef].DemDTCAttributesRef]
                .DemEventMemoryEntryFdcThresholdStorageValue
            <= (uint8)FDC) */
        && (DEM_DEBOUNCE_COUNTER_BASED == AlgorithmType))
    {
        /*SWS_Dem_00799]*/
        DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_FDC_TRIGGERED);
        Dem_EventDataStorageTrigger(IntId, DEM_TRIGGER_ON_FDC_THRESHOLD);
    }
#endif /* DEM_TRIGGERONFDCTHRESHOLDEANLE == STD_ON */
    return Status;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if ((DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u) && (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u))
/*************************************************************************/
/*
 * Brief               Dem_DebounceFreeze
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceFreeze(Dem_EventIdType IntId)
{
    const Dem_EventParameterType* pEventCfg = &DemPbCfg.DemEventParameter[IntId];
    uint8 AlgorithmType = pEventCfg->AlgorithmType;
    uint16 AlgorithmRef = pEventCfg->AlgorithmRef;
    uint16 AlgorithmIndex = pEventCfg->AlgorithmIndex;
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
    /*[SWS_Dem_00654]  [SWS_Dem_00677] */
    if ((AlgorithmType == DEM_DEBOUNCE_TIME_BASE) && (AlgorithmRef < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM)
        && (AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
    {
        Dem_DebounceTimeInfoType* pDemDebounceTimerInfo = &DemDebounceTimerInfo[AlgorithmIndex];
        if (DemPbCfg.DemDebounceTimeBaseClass[AlgorithmRef].DemDebounceBehavior == DEM_DEBOUNCE_FREEZE)
        {
            pDemDebounceTimerInfo->IsFreezing = TRUE;
        }
        else
        {
            pDemDebounceTimerInfo->CurStatus = DEM_EVENT_STATUS_PREPASSED;
            pDemDebounceTimerInfo->Timeout = 0;
            pDemDebounceTimerInfo->Triggered = FALSE;
        }
    }
    else
#endif /* (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
        if ((AlgorithmType == DEM_DEBOUNCE_COUNTER_BASED) && (AlgorithmRef < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)
            && (AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
    {
        if (DemPbCfg.DemDebounceCounterBasedClass[AlgorithmRef].DemDebounceBehavior == DEM_DEBOUNCE_RESET)
        {
            DemDebounceCounterInfo[AlgorithmIndex].InternalDebounceCounter = 0;
        }
    }
    else
#endif /* (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u) */
    {
        /*idle*/
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u) && (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u) */

#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
/*************************************************************************/
/*
 * Brief               Dem_DebounceTimerMain
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceTimerMain(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    for (uint16 iloop = 0; (iloop < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM); iloop++)
    {
        Dem_DebounceTimeInfoType* pTimer = &DemDebounceTimerInfo[iloop];
        if ((pTimer->Triggered == TRUE) && (pTimer->IsFreezing == FALSE))
        {
            Dem_EventIdType IntId = pTimer->IntId;
            Dem_EventStatusType CurStatus = pTimer->CurStatus;
            const Dem_EventParameterType* pEventParameter = &DemPbCfgPtr->DemEventParameter[IntId];
            uint16 AlgorithmRef = pEventParameter->AlgorithmRef;
            const Dem_DebounceTimeBaseClassType* pTimerCfg = &DemPbCfgPtr->DemDebounceTimeBaseClass[AlgorithmRef];
            uint8 DemOperationCycleRef = pEventParameter->DemOperationCycleRef;
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
            uint8 OldStatus = pTimer->CurStatus;
            uint8 NewStatus;
#endif
            if ((CurStatus != DEM_EVENT_STATUS_FAILED) && (CurStatus != DEM_EVENT_STATUS_PASSED))
            {
                pTimer->Timeout += DEM_TASK_TIME;
            }
            if ((CurStatus == DEM_EVENT_STATUS_PREFAILED)
                && (pTimer->Timeout >= pTimerCfg->DemDebounceTimeFailedThreshold))
            {
                pTimer->CurStatus = DEM_EVENT_STATUS_FAILED;
                pTimer->Triggered = FALSE;
                if ((0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, DemOperationCycleRef))
                    || (DemOperationCycle[DemOperationCycleRef].DemOperationCycleType == DEM_OPCYC_OBD_DCY))
                {
                    Dem_EventQueueAddDebounceFailed(Dem_GetEventInfo(IntId));
                    Dem_EventTestFailed(IntId);
                }
            }
            else if (
                (CurStatus == DEM_EVENT_STATUS_PREPASSED)
                && (pTimer->Timeout >= pTimerCfg->DemDebounceTimePassedThreshold))
            {
                pTimer->CurStatus = DEM_EVENT_STATUS_PASSED;
                pTimer->Triggered = FALSE;
                if ((0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, DemOperationCycleRef))
                    || (DemOperationCycle[DemOperationCycleRef].DemOperationCycleType == DEM_OPCYC_OBD_DCY))
                {
                    Dem_EventTestPassed(IntId);
                }
            }
            else
            {
                /*idle*/
            }
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
            NewStatus = pTimer->CurStatus;
            if (OldStatus != NewStatus)
            {
                (void)FiM_DemTriggerOnEventStatus(Dem_GetEventExternalId(IntId), OldStatus, NewStatus);
            }
#endif
        }
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u */
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)

DEM_LOCAL FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebouceProcessPrePassedCounter(
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter,
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Dem_EventStatusType status = DEM_EVENT_STATUS_PREPASSED;
    sint16 JumpDownValue = pCfgCounter->DemDebounceCounterJumpDownValue;
    sint16 OldCounter = pCounter->InternalDebounceCounter;
    sint16 PassedThreshold = pCfgCounter->DemDebounceCounterPassedThreshold;
    uint16 StepSize = pCfgCounter->DemDebounceCounterDecrementStepSize;
    if (OldCounter > JumpDownValue)
    {
        if (pCfgCounter->DemDebounceCounterJumpDown == TRUE) /*SWS_Dem_00423*/
        {
            pCounter->InternalDebounceCounter = JumpDownValue;
        }
    }

    OldCounter = pCounter->InternalDebounceCounter;

    if ((PassedThreshold + (sint16)StepSize) >= OldCounter)
    {
        pCounter->InternalDebounceCounter = PassedThreshold;
        status = DEM_EVENT_STATUS_PASSED;
    }
    else
    {
        pCounter->InternalDebounceCounter -= (sint16)StepSize;
    }
    return status;
}

DEM_LOCAL FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebouceProcessPreFailedCounter(
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter,
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Dem_EventStatusType status = DEM_EVENT_STATUS_PREFAILED;
    sint16 JumpUpValue = pCfgCounter->DemDebounceCounterJumpUpValue;
    sint16 OldCounter = pCounter->InternalDebounceCounter;
    sint16 FailedThreshold = pCfgCounter->DemDebounceCounterFailedThreshold;
    uint16 StepSize = pCfgCounter->DemDebounceCounterIncrementStepSize;
    if (OldCounter < JumpUpValue)
    {
        if (pCfgCounter->DemDebounceCounterJumpUp == TRUE) /*SWS_Dem_00425*/
        {
            pCounter->InternalDebounceCounter = JumpUpValue;
        }
    }

    OldCounter = pCounter->InternalDebounceCounter;

    if ((FailedThreshold - (sint16)StepSize) <= OldCounter)
    {
        pCounter->InternalDebounceCounter = FailedThreshold;
        status = DEM_EVENT_STATUS_FAILED;
    }
    else
    {
        pCounter->InternalDebounceCounter += (sint16)StepSize;
    }
    return status;
}

/*************************************************************************/
/*
 * Brief               Dem_DebounceProcessCounter
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEventBuffer && pEventCfg
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DEM_LOCAL FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessCounter(
    Dem_EventDataBufferType pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    const Dem_DebounceCounterBasedClassType* pCfgCounter =
        &DemPbCfgPtr->DemDebounceCounterBasedClass
             [DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pEventBuffer.ExtId)].AlgorithmRef];
    Dem_DebounceCounterInfoType* pCounter = &DemDebounceCounterInfo[pEventCfg->AlgorithmIndex];
    Dem_EventStatusType Status = pEventBuffer.Status;

    switch (Status)
    {
    case DEM_EVENT_STATUS_PASSED: /*SWS_Dem_00421*/
        pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterPassedThreshold;
        break;
    case DEM_EVENT_STATUS_FAILED: /*SWS_Dem_00420] */
        pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterFailedThreshold;
        break;
    case DEM_EVENT_STATUS_PREPASSED:
        Status = Dem_DebouceProcessPrePassedCounter(pCfgCounter, pCounter);
        break;
    default: /* DEM_EVENT_STATUS_PREFAILED */
        Status = Dem_DebouceProcessPreFailedCounter(pCfgCounter, pCounter);
        break;
    }
    return Status;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u */

#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
/*************************************************************************/
/*
 * Brief               Dem_DebounceProcessTimer
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEventBuffer && pEventCfg
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DEM_LOCAL FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessTimer(
    Dem_EventDataBufferType pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_EventIdType IntId = Dem_GetEventInternalId(pEventBuffer.ExtId);
    Dem_EventStatusType Status = pEventBuffer.Status;
    Dem_DebounceTimeInfoType* pTimer = &DemDebounceTimerInfo[pEventCfg->AlgorithmIndex];
    const Dem_DebounceTimeBaseClassType* pTimerCfg = &DemPbCfgPtr->DemDebounceTimeBaseClass[pEventCfg->AlgorithmRef];
    Dem_EventRelateInformationType* pEvent = Dem_GetEventInfo(IntId);
    Dem_EventStatusType CurStatus = pTimer->CurStatus;
    if (pTimer->IsFreezing != FALSE)
    {
        /*SWS_Dem_00656*/
        if (0x00u
            != DEM_FLAGS_ISSET(pEvent->Status, (DEM_EVENT_STATUS_ENABLED_CONDICTION | DEM_EVENT_STATUS_DTC_SETTING)))
        {
            pTimer->IsFreezing = FALSE;
        }
    }
    switch (Status)
    {
    case DEM_EVENT_STATUS_PASSED:
        pTimer->CurStatus = DEM_EVENT_STATUS_PASSED; /*SWS_Dem_00435*/
        pTimer->Timeout = pTimerCfg->DemDebounceTimePassedThreshold;
        break;
    case DEM_EVENT_STATUS_FAILED:
        pTimer->CurStatus = DEM_EVENT_STATUS_FAILED; /*SWS_Dem_00431*/
        pTimer->Timeout = pTimerCfg->DemDebounceTimeFailedThreshold;
        break;
    case DEM_EVENT_STATUS_PREPASSED: /*SWS_Dem_00432*/
        if ((CurStatus == DEM_EVENT_STATUS_FAILED) || (CurStatus == DEM_EVENT_STATUS_PREFAILED)
            || (CurStatus == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED) || (pTimer->Triggered == FALSE)) /*SWS_Dem_00433*/
        {
            pTimer->CurStatus = DEM_EVENT_STATUS_PREPASSED;
            pTimer->Triggered = TRUE;
            pTimer->Timeout = 0;
        }
        break;
    case DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED:
        break;
    case DEM_EVENT_STATUS_PREFAILED: /* Prefailed */
        if ((CurStatus == DEM_EVENT_STATUS_PASSED) || (CurStatus == DEM_EVENT_STATUS_PREPASSED)
            || (pTimer->Triggered == FALSE)) /*SWS_Dem_00429*/
        {
            pTimer->CurStatus = DEM_EVENT_STATUS_PREFAILED;
            pTimer->Triggered = TRUE;
            pTimer->Timeout = 0;
        }
        break;
    default:
        /*idle*/
        break;
    }
    return Status;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u */

/*************************************************************************/
/*
 * Brief               Dem_UpdateFDC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_UpdateFDC(Dem_EventIdType IntId)
{
    const Dem_EventParameterType* pEventCfg = &DemPbCfg.DemEventParameter[IntId];
#if ((DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u) || (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u))
    uint16 AlgorithmRef = pEventCfg->AlgorithmRef;
    uint16 AlgorithmIndex = pEventCfg->AlgorithmIndex;
#endif /* DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u */
    sint8 FDC = 0;
    uint16 DemDTCRef = pEventCfg->DemDTCRef;

    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_COUNTER_BASED:

        if ((AlgorithmRef < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)
            && (AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
        {
            const Dem_DebounceCounterBasedClassType* pCfgCounter = &DemPbCfg.DemDebounceCounterBasedClass[AlgorithmRef];
            Dem_DebounceCounterInfoType* pCounter = &DemDebounceCounterInfo[AlgorithmIndex];
            if (pCounter->InternalDebounceCounter == 0)
            {
                FDC = 0;
            }
            else if (pCounter->InternalDebounceCounter > 0)
            {
                FDC =
                    (sint8)((pCounter->InternalDebounceCounter * 127) / pCfgCounter->DemDebounceCounterFailedThreshold);
            }
            else
            {
                FDC = (sint8)((pCounter->InternalDebounceCounter * ((sint8)(-128)))
                              / pCfgCounter->DemDebounceCounterPassedThreshold);
            }
        }
        break;
#endif /* DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u */
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_TIME_BASE:
        if ((AlgorithmRef < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM) && (AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
        {
            Dem_DebounceTimeInfoType* pTimer = &DemDebounceTimerInfo[AlgorithmIndex];
            const Dem_DebounceTimeBaseClassType* pTimerCfg = &DemPbCfg.DemDebounceTimeBaseClass[AlgorithmRef];
            switch (pTimer->CurStatus)
            {
            case DEM_EVENT_STATUS_PASSED:
                FDC = -128;
                break;
            case DEM_EVENT_STATUS_FAILED:
                FDC = 127;
                break;
            case DEM_EVENT_STATUS_PREFAILED:
                FDC = (sint8)((pTimer->Timeout * 127UL) /* PRQA S 4394 */ /* MISRA Rule 10.8 */
                              / (uint64)pTimerCfg->DemDebounceTimeFailedThreshold);
                break;
            default:
                FDC = ((sint8)(-1))
                      * ((sint8)((pTimer->Timeout * 128UL) /* PRQA S 4394 */ /* MISRA Rule 10.8 */
                                 / (uint64)pTimerCfg->DemDebounceTimePassedThreshold));
                break;
            }
        }
        break;
#endif /* DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u */
    default:
        /*idle*/
        break;
    }
    if (DemDTCRef != DEM_DTC_REF_INVALID)
    {
        FDCInfoType* pFDCInfo = &FDCInfo[DemDTCRef];
        if (FDC > 0) /* SWS_Dem_00795 */
        {
            uint8 CurFDC = (uint8)FDC;
            if (CurFDC > pFDCInfo->MaxFDCSinceLastClear)
            {
                pFDCInfo->MaxFDCSinceLastClear = CurFDC;
            }
            if (CurFDC > pFDCInfo->MaxFDCDuringCurrentCycle)
            {
                pFDCInfo->MaxFDCDuringCurrentCycle = CurFDC;
            }
        }
        pFDCInfo->FDC = FDC;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
