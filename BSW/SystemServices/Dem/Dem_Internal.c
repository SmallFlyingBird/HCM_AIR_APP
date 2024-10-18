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
**  FILENAME    : Dem_Internal.c                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : API definitions of DEM for internal                         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Internal.h"
#include "Dem.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define DEM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dem_MemMap.h"
VAR(Dem_ClearLockStatus, AUTOMATIC) DemClearDTCLock = DEM_CLEAR_NOT_LOCK;
#define DEM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Dem_MemMap.h"
VAR(boolean, AUTOMATIC) DemClearNonvolatile = FALSE; /* PRQA S 1533 */ /* MISRA Rule 8.9 */
#define DEM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN /* PRQA S 0791 */       /* MISRA Rule 5.4 */
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dem_MemMap.h"
VAR(uint8, AUTOMATIC) DemClearNonvolatileOK = 0x02u; /* PRQA S 1533 */ /* MISRA Rule 8.9 */
#define DEM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_ClearDTCInfoType, AUTOMATIC) DemClearDTCInfo;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_InternalDataType, AUTOMATIC) DemInternalData;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_BOOLEAN
#include "Dem_MemMap.h"
VAR(boolean, AUTOMATIC) Dem_Pending = FALSE;
#define DEM_STOP_SEC_VAR_INIT_BOOLEAN
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                         **
*******************************************************************************/

#if (DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS)
#if (DEM_GROUP_OF_DTC_NUM > 0)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(void, DEM_CODE) Dem_ClearGroupDTC(uint8 memDest, uint8 GroupIndex);
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(void, DEM_CODE) Dem_ClearOneDTC(uint8 memDest, uint16 DTCIndex);
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

DEM_LOCAL FUNC(void, DEM_CODE)
    Dem_Clear(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent, uint8 memDest);
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*************************************************************************/
/*
 * Brief               ClearAllDTC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant/Non Reentrant
 * Param-Name[in]      memDest
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(void, DEM_CODE) Dem_ClearAllDTC(uint8 memDest)
{
    Dem_EventRelateInformationType* pEvent = DemEventRelateInformation;
    const Dem_EventParameterType* pEventParameter = DemPbCfgPtr->DemEventParameter;
    Dem_ClearDTCInfoType* pClr = &DemClearDTCInfo;
    const Dem_DTCType* pDTC = DemPbCfgPtr->DemDTC;
    const DemObdDTCType* pObdDTC = DemPbCfgPtr->DemObdDTC;

    for (uint16 iloop = 0; iloop < DEM_EVENT_PARAMETER_NUM; iloop++)
    {
        boolean DoClear = TRUE;
        uint16 dtcRef = pEventParameter->DemDTCRef;
        if (dtcRef != DEM_DTC_REF_INVALID)
        {
            uint16 ObdDTCRef = pDTC[dtcRef].DemObdDTCRef;
            if ((ObdDTCRef != DEM_OBD_DTC_INVALID)
                && (pObdDTC[ObdDTCRef].DemJ1939DTCValue != DEM_J1939_DTC_CFG_INVALID))
            {
                DoClear = FALSE;
#if (DEM_J1939_NODE_NUM > 0u)
                if ((pClr->SID == DEM_SID_J1939DCMCLEARDTC)
                    && (((pClr->DTCTypeFilter == DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE)
                         && ((0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC))
                             && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF))))
                        || ((pClr->DTCTypeFilter == DEM_J1939DTC_CLEAR_ALL)
                            && (0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF)))))
                {
                    DoClear = Dem_J1939CeckNode(dtcRef, pClr->node);
                }
                else
#endif /* DEM_J1939_NODE_NUM > 0u */
                    if (pClr->SID != DEM_SID_J1939DCMCLEARDTC)
                    {
                        DoClear = TRUE;
                    }
                    else
                    {
                        /* do nothing */
                    }
            }
        }
        if (DoClear == TRUE)
        {
            Dem_Clear(pEvent, memDest);
        }
        pEvent++;
        pEventParameter++;
    }
    /*SWS_Dem_00399] */
    if (DemMemDestInfo[memDest].RecordNum == 0u)
    {
        DemMemDestInfo[memDest].OverFlow = FALSE;
    }
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    Dem_ClearOBDInfo();
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS)
#if (DEM_GROUP_OF_DTC_NUM > 0u)
/*************************************************************************/
/*
 * Brief               ClearGroupDTC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant/Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(void, DEM_CODE) Dem_ClearGroupDTC(uint8 memDest, uint8 GroupIndex)
{
    const Dem_EventParameterType* pEventParameter = DemPbCfgPtr->DemEventParameter;
    Dem_EventRelateInformationType* pEvent = DemEventRelateInformation;
    const Dem_DTCType* pDTC = DemPbCfgPtr->DemDTC;
    for (uint16 iloop = 0; iloop < DEM_EVENT_PARAMETER_NUM; iloop++)
    {
        uint16 Ref = pEventParameter->DemDTCRef;
        if ((Ref != DEM_DTC_REF_INVALID) && (pDTC[Ref].GroupRef == GroupIndex)
            && (0x00u != DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION)))
        {
            Dem_Clear(pEvent, memDest);
        }
        pEvent++;
        pEventParameter++;
    }
    /*SWS_Dem_00399] */
    if (DemMemDestInfo[memDest].RecordNum == 0u)
    {
        DemMemDestInfo[memDest].OverFlow = FALSE;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* DEM_GROUP_OF_DTC_NUM > 0u */
/*************************************************************************/
/*
 * Brief               ClearOneDTC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant/Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(void, DEM_CODE) Dem_ClearOneDTC(uint8 memDest, uint16 DTCIndex)
{
    const Dem_DTCType* pDemDTC = &DemPbCfgPtr->DemDTC[DTCIndex];
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
    const Dem_EventIdType EventRefNum = pDemDTC->EventRefNum;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
    const Dem_EventIdType EventRefStart = pDemDTC->EventRefStart;
    const Dem_EventIdType* pDTCMapping = &DemPbCfgPtr->DemDTCMapping[EventRefStart];
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
    for (uint16 iloop = 0u; iloop < EventRefNum; iloop++)
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
    {
        Dem_EventRelateInformationType* pEvent = Dem_GetEventInfo(*pDTCMapping);
        Dem_Clear(pEvent, memDest);
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
        pDTCMapping++;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
    }
    /*SWS_Dem_00399] */
    if (DemMemDestInfo[memDest].RecordNum == 0u)
    {
        DemMemDestInfo[memDest].OverFlow = FALSE;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS */

/*************************************************************************/
/*
 * Brief               ClearDTCProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant/Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_ClearDTCProcess(void)
{
    Dem_ClearDTCInfoType* pClr = &DemClearDTCInfo;
    uint8 memDest = pClr->memDest;
    /* SWS_Dem_00171 */
    if (memDest != DEM_MEM_DEST_INVALID)
    {
        if (pClr->ClearAllGroup == TRUE)
        {
            Dem_ClearAllDTC(memDest);
        }
#if (DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS)
        else
        {
#if (DEM_GROUP_OF_DTC_NUM > 0u)
            uint8 DTCGroupIndex = pClr->DTCGroupIndex;
            if (DTCGroupIndex != DEM_GROUP_OF_DTC_INVALID)
            {
                Dem_ClearGroupDTC(memDest, DTCGroupIndex);
            }
            else
#endif /* DEM_GROUP_OF_DTC_NUM > 0u */
            {
                uint16 DTCIndex = pClr->DTCIndex;
                if (DTCIndex != DEM_DTC_REF_INVALID)
                {
                    Dem_ClearOneDTC(memDest, DTCIndex);
                }
            }
        }
#endif /* DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS */
        Dem_Pending = FALSE;
        DemClearDTCLock = DEM_CLEAR_NOT_LOCK;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               BRIEF DESCRIPTION
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTC && DTCFormat
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              DTC Index
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(uint16, DEM_CODE) Dem_GetDTCIndex(uint32 DTC, Dem_DTCFormatType DTCFormat)
{
    uint16 ret = DEM_DTC_REF_INVALID;
    const Dem_DTCType* pDTC = DemPbCfgPtr->DemDTC;
    const DemObdDTCType* pObdDTC = DemPbCfgPtr->DemObdDTC;

    switch (DTCFormat)
    {
    case DEM_DTC_FORMAT_UDS:
        for (uint16 index = 0; index < DEM_DTC_NUM; index++)
        {
            if (pDTC->DemDtcValue == DTC)
            {
                ret = index;
                break;
            }
            pDTC++;
        }
        break;
    case DEM_DTC_FORMAT_OBD:
        for (uint16 index = 0; index < DEM_DTC_NUM; index++)
        {
            uint16 ObdDTCRef = pDTC->DemObdDTCRef;
            if ((ObdDTCRef != DEM_OBD_DTC_INVALID) && (pObdDTC[ObdDTCRef].DemDtcValue == DTC))
            {
                ret = index;
                break;
            }
            pDTC++;
        }
        break;
    case DEM_DTC_FORMAT_J1939:
        for (uint16 index = 0; index < DEM_DTC_NUM; index++)
        {
            uint16 ObdDTCRef = pDTC->DemObdDTCRef;
            if ((ObdDTCRef != DEM_OBD_DTC_INVALID) && (pObdDTC[ObdDTCRef].DemJ1939DTCValue == DTC))
            {
                ret = index;
                break;
            }
        }
        break;
    default:
        /*idle*/
        break;
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_Clear
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      memDest && pEntry && pEvent
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432,1505++ */ /* MISRA Rule 20.7,8.7 */
DEM_LOCAL FUNC(void, DEM_CODE)
    Dem_Clear(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent, uint8 memDest)
/* PRQA S 3432,1505-- */ /* MISRA Rule 20.7,8.7 */
{
    boolean clear = FALSE;
    Dem_EventIdType IntId = pEvent->IntId;
    const Dem_EventParameterType* pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
    const Dem_CallbackInitMForEType InitMForE = pEventCfg->DemCallbackInitMForE;
    const Dem_CallbackClearEventAllowedType* pClearEventAllowed = pEventCfg->DemCallbackClearEventAllowed;
    boolean allowed = FALSE;
#if ((DEM_INDICATOR_NUM > 0u) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0u))
    const Dem_IndicatorAttributeType* pWIRAttr = &DemIndicatorAttribute[pEventCfg->AttrStartIndex];
    uint8 AttrNum = pEventCfg->AttrNum;

#endif /* (DEM_INDICATOR_NUM > 0u) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0u) */

    /* SWS_Dem_00514 SWS_Dem_00515 */
    /* req SWS_Dem_00680 Monitor re-initialization  */
    if (InitMForE != NULL_PTR)
    {
        (*InitMForE)(DEM_INIT_MONITOR_CLEAR);
    }

    if ((pClearEventAllowed != NULL_PTR) && (pClearEventAllowed->ClearEventAllowed != NULL_PTR))
    {
        if (E_OK == pClearEventAllowed->ClearEventAllowed(&allowed))
        {
            if (allowed == TRUE)
            {
                /* SWS_Dem_00385 */
                pEvent->UdsStatus = 0x00;
                /* bit 4 6 the initialized value 0x50 */
                DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCSLC | DEM_UDS_STATUS_TNCTOC);
            }
            else
            {
                /* SWS_Dem_00667 */
                clear = TRUE;
                if (pClearEventAllowed->DemClearEventAllowedBehavior == DEM_ONLY_THIS_CYCLE_AND_READINESS)
                {
                    /* SWS_Dem_00669 SWS_Dem_00668 */
                    /* bit 4 6 reset */
                    DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCSLC | DEM_UDS_STATUS_TNCTOC);
                    /* bit 1 5 reset */
                    DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC | DEM_UDS_STATUS_TFSLC);
                }
            }
        }
        /* SWS_Dem_00516 */
        else
        {
            /* SWS_Dem_00385 */
            pEvent->UdsStatus = 0x00;
            /* bit 4 6 the initialized value 0x50 */
            DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCSLC | DEM_UDS_STATUS_TNCTOC);
        }
    }
    else
    {
        /* SWS_Dem_00385 */
        /* All other bits are set to 0 */
        pEvent->UdsStatus = 0x00;
        /* bit 4 6 set to 1 */
        DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCSLC | DEM_UDS_STATUS_TNCTOC);
    }
    /* update the combination event dtc status*/
    Dem_UpdateCombinedDtcStatus(IntId);
    Dem_ResponseOnDtcStatusChange(IntId);
    if (clear == FALSE)
    {
        Dem_EventMemEntryType* pEntry;
        uint16 DTCRef = pEventCfg->DemDTCRef;
#if ((DEM_OCC6EANLE == STD_ON) || (DEM_OCC4EANLE == STD_ON))
        pEvent->ThisOpIsFiled = FALSE;
        pEvent->OCC4_Increased = FALSE;
#endif /* (DEM_OCC6EANLE == STD_ON) || (DEM_OCC4EANLE == STD_ON) */
        /* SWS_Dem_00343 */
        Dem_DebounceReset(IntId);
        if (DTCRef != DEM_DTC_REF_INVALID)
        {
            /* SWS_Dem_00794 */
            FDCInfo[DTCRef].MaxFDCSinceLastClear = 0;
        }
#if (DEM_DTR_NUM > 0u)
        /* SWS_Dem_00763 */
        Dem_ClearDTRInfoByEventID(IntId);
#endif /* DEM_DTR_NUM > 0u */
#if ((DEM_INDICATOR_NUM > 0u) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0u))
        allowed = TRUE;
        for (uint8 kloop = 0; (kloop < AttrNum) && (TRUE == allowed); kloop++)
        {
            uint8 DemIndicatorRef = pWIRAttr->DemIndicatorRef;
            Dem_EventRelateInformationType* EventPtr = DemEventRelateInformation;
            const Dem_EventParameterType* pEventCfg2 = DemPbCfgPtr->DemEventParameter;
            for (uint16 iloop = 0; (iloop < DEM_EVENT_PARAMETER_NUM) && (TRUE == allowed); iloop++)
            {
                const Dem_IndicatorAttributeType* pIndicatorAttr = &DemIndicatorAttribute[pEventCfg2->AttrStartIndex];
                for (uint8 jloop = 0; (jloop < pEventCfg2->AttrNum) && (TRUE == allowed); jloop++)
                {
                    if ((DemIndicatorRef == pIndicatorAttr->DemIndicatorRef)
                        && (0x00u != DEM_FLAGS_ISSET(EventPtr->UdsStatus, DEM_UDS_STATUS_WIR)))
                    {
                        allowed = FALSE;
                    }
                    pIndicatorAttr++;
                }
                EventPtr++;
                pEventCfg2++;
            }
            if (TRUE == allowed)
            {
                DemWIRStatus[DemIndicatorRef] = DEM_INDICATOR_OFF;
            }
            pWIRAttr++;
        }
#endif /* (DEM_INDICATOR_NUM > 0u) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0u) */
        /*SWS_Dem_00667]*/
        pEntry = Dem_MemEntryGet(Dem_GetEventExternalId(IntId), memDest);
        if (pEntry != NULL_PTR)
        {
            Dem_MemEntryDelete(pEntry, memDest); /*SWS_Dem_00660] */
        }
    }
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0u)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Dem_CheckEventAllIndicator
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/*************************************************************************/
FUNC(boolean, DEM_CODE) Dem_CheckEventAllIndicator(uint16 IntId)
{
    const Dem_EventParameterType* pEventParameter = &DemPbCfgPtr->DemEventParameter[IntId];
    uint8 num = pEventParameter->AttrNum;
    uint16 start = pEventParameter->AttrStartIndex;
    const Dem_IndicatorAttributeType* pIndicatorAttr = &DemIndicatorAttribute[start];
    boolean ret = TRUE;

    for (uint16 iloop = 0; iloop < num; iloop++)
    {
        if (DemWIRStatus[pIndicatorAttr->DemIndicatorRef] != DEM_INDICATOR_OFF)
        {
            ret = FALSE;
            break;
        }
        pIndicatorAttr++;
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0u */

#if (DEM_DATA_ELEMENT_CLASS_NUM > 0u)
/*************************************************************************/
/*
 * Brief               Dem_GetFncData>
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DataReadFnc,DataSize
 * Param-Name[out]     pBuffer
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_GetFncData(DemDataElementReadFncType DataReadFnc, uint8* pBuffer, uint8 DataSize)
{
    if (DataReadFnc != NULL_PTR)
    {
        if (DataReadFnc(pBuffer) != E_OK)
        {
            Dem_MemSet(pBuffer, 0xFFu, DataSize);
            DEM_DET_REPORT(DEM_SID_MAINFUNCTION, DEM_E_NODATAAVAILABLE);
        }
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif /* DEM_DATA_ELEMENT_CLASS_NUM > 0u */

/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
