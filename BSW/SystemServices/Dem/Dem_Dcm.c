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
**  FILENAME    : Dem_Dcm.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : API definitions of DEM for DCM                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Internal.h"
#include "Dem_Dcm.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/* FreezeFrameRecordFilter */
typedef struct
{
    /* Filter */
    Dem_DTCFormatType DTCFormat;
    /* Result */
    uint16 NumberOfFilteredRecords;
    uint16 GetNum;
    uint8 EntryIndex;
    uint8 FFIndex;
} Dem_FreezeFrameRecordFilterInfoType;

typedef struct
{
    /* All Group */
    boolean AllGroupIsEnabled;
    Dem_DTCKindType DTCKind;
#if (DEM_GROUP_OF_DTC_NUM > 0)
    uint8 DTCGroupStatus[DEM_GROUP_OF_DTC_NUM_BYTE];
#endif
} Dem_DTCSettingInfoType;

typedef struct
{
    uint16 DTCIndex;
    Dem_DTCOriginType DTCOrigin;
} Dem_DTCRecordUpdateStatusInfoType;

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_DTCFilterInfoType, AUTOMATIC) DemDTCFilterInfo;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
DEM_LOCAL VAR(Dem_DTCSettingInfoType, AUTOMATIC) DemDTCSettingInfo;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_DTCByOccurrenceTimeType, AUTOMATIC) DemDTCByOccurrenceTimeInfo;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
DEM_LOCAL VAR(Dem_DTCRecordUpdateStatusInfoType, AUTOMATIC) DTCRecordUpdateStatusInfo;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
DEM_LOCAL VAR(Dem_FreezeFrameRecordFilterInfoType, AUTOMATIC) DemFreezeFrameRecordFilterInfo;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#include "Dem_MemMap.h"
VAR(boolean, AUTOMATIC) DemDTCStatusChangedInd = FALSE;
#define DEM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#include "Dem_MemMap.h"
DEM_LOCAL VAR(boolean, AUTOMATIC) DemDTCDisable = FALSE;
#define DEM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Private Function Definitions                         **
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(void, DEM_CODE) Dem_SetDTCSettingProcess(void);
DEM_LOCAL FUNC(uint8, DEM_CODE) Dem_CheckEventInternalMemDest(Dem_DTCOriginType DTCOrigin, uint16 IntId);
DEM_LOCAL FUNC(boolean, DEM_CODE) Dem_CheckDTCFormat(uint8 dtcFormat, uint16 dtcRef);
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               BRIEF DESCRIPTION
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
FUNC(void, DEM_CODE) Dem_DcmInit(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    DemDTCStatusChangedInd = TRUE;
    DemDTCSettingInfo.AllGroupIsEnabled = TRUE;
#if (DEM_GROUP_OF_DTC_NUM > 0)
    Dem_MemSet((uint8*)&DemDTCSettingInfo.DTCGroupStatus, 0xFFu, DEM_GROUP_OF_DTC_NUM_BYTE);
#endif
    Dem_MemSet((uint8*)&DemDTCFilterInfo, 0x00u, sizeof(Dem_DTCFilterInfoType));
    Dem_MemSet((uint8*)&DemFreezeFrameRecordFilterInfo, 0x00u, sizeof(Dem_FreezeFrameRecordFilterInfoType));

    DemDTCByOccurrenceTimeInfo.FirstDtcConfirmed = DEM_EVENT_PARAMETER_INVALID;
    DemDTCByOccurrenceTimeInfo.FirstFailed = DEM_EVENT_PARAMETER_INVALID;
    DemDTCByOccurrenceTimeInfo.MostRecDtcConfirmed = DEM_EVENT_PARAMETER_INVALID;
    DemDTCByOccurrenceTimeInfo.MostRecentFailed = DEM_EVENT_PARAMETER_INVALID;

    DemClearDTCInfo.ClearAllGroup = FALSE;
    DemClearDTCInfo.DTCGroupIndex = DEM_GROUP_OF_DTC_INVALID;
    DemClearDTCInfo.DTCIndex = DEM_DTC_REF_INVALID;
    DemClearDTCInfo.memDest = DEM_MEM_DEST_INVALID;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the supported DTC formats of the ECU.
 * ServiceId           0x3c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Returns the configured DTC translation format. Acombination of
 *                              different DTC formats is not possible.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_DTCTranslationFormatType, DEM_CODE)
Dem_DcmGetTranslationType(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETTRANSLATIONTYPE, DEM_E_UNINIT);
    }
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    return DEM_TYPE_OF_DTCSUPPORTED;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the DTC Status availability mask.
 * ServiceId           0x16
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     DTCStatusMask:The value DTCStatusMask indicates the supported DTC status
 *                              bits from the Dem.
 * Param-Name[in/out]  none
 * Return              E_OK: get of DTC status mask was successful
 *                       E_NOT_OK: get of DTC status mask failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
Dem_DcmGetDTCStatusAvailabilityMask(P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
    Std_ReturnType ret;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    ret = E_NOT_OK;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETDTCSTATUSAVAILABILITYMASK, DEM_E_UNINIT);
    }
    else if (DTCStatusMask == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETDTCSTATUSAVAILABILITYMASK, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        *DTCStatusMask = DEM_DTC_STATUS_AVAILABILITY_MASK;
        ret = E_OK;
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the status of a DTC.
 * ServiceId           0x15
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC:Diagnostic Trouble Code in UDS format.
 *                       DTCOrigin: If the Dem supports more than one event memory this
 *                              parameter is used to select the source memory
 *                              the DTCs shall be read from.
 * Param-Name[out]     DTCStatus: This parameter receives the status information of the
 *                          requested DTC. If the return value of the function call is
 *                          other than DEM_STATUS_OK this parameter does not contain valid
 *                          data. 0x00...0xFF match DTCStatusMask as defined in ISO14229-1
 * Param-Name[in/out]  none
 * Return              Status of the operation of type Dem_ReturnGetStatusOfDTCType.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dem_DcmGetStatusOfDTC(uint32 DTC, Dem_DTCOriginType DTCOrigin, P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    Dem_ReturnGetStatusOfDTCType ret;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    ret = DEM_STATUS_FAILED;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSTATUSOFDTC, DEM_E_UNINIT);
    }
    else if (DTCStatus == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSTATUSOFDTC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        /*SWS_Dem_01100*/
        uint16 dtcIndex = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS);
        if ((dtcIndex != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcIndex].SuppressionStatus == FALSE))
        {
            /* return status of DTC which not been stored */
            /* PRQA S 2985++ */ /* MISRA Rule 2.2 */
            *DTCStatus = (DemDTCGeneralStatus[dtcIndex].CbUdsStatus & DEM_DTC_STATUS_AVAILABILITY_MASK);
            /* PRQA S 2985-- */ /* MISRA Rule 2.2 */
            ret = DEM_STATUS_OK;
        }
        else
        {
            ret = DEM_STATUS_WRONG_DTC;
        }
        DEM_UNUSED(DTCOrigin);
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the severity of the requested DTC.
                        For large configurations and DTC-calibration, the interface behavior can
                        be asynchronous (splitting the DTC-search into segments).
 * ServiceId           0x0e
 * Sync/Async          Synchronous or Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC : Diagnostic Trouble Code in UDS format.
 * Param-Name[out]     DTCSeverity:This parameter contains the DTCSeverity according to ISO 14229-1.
 * Param-Name[in/out]  none
 * Return              Status of the operation of type Dem_ReturnGetSeverityOfDTCType.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_DcmGetSeverityOfDTC(uint32 DTC, P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetSeverityOfDTCType ret = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSEVERITYOFDTC, DEM_E_UNINIT);
    }
    else if (DTCSeverity == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSEVERITYOFDTC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {  /*SWS_Dem_01100*/
        uint16 dtcIndex = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS);
        if ((dtcIndex != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcIndex].SuppressionStatus == FALSE))
        {
            *DTCSeverity = DemPbCfgPtr->DemDTC[dtcIndex].DemDTCSeverity;
            ret = DEM_GET_SEVERITYOFDTC_OK;
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the functional unit of the requested DTC.
 * ServiceId           0x34
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC:Diagnostic Trouble Code in UDS format.
 * Param-Name[out]     DTCFunctionalUnit:Functional unit value of this DTC
 * Param-Name[in/out]  none
 * Return              Status of the operation of type Dem_ReturnGetFunctionalUnitOfDTCType.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_DcmGetFunctionalUnitOfDTC(uint32 DTC, P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetFunctionalUnitOfDTCType ret;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    ret = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETFUNCTIONALUNITOFDTC, DEM_E_UNINIT);
    }
    else if (DTCFunctionalUnit == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETFUNCTIONALUNITOFDTC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        /*SWS_Dem_00593*/ /*SWS_Dem_01100*/
        uint16 dtcIndex = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS);
        if ((dtcIndex != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcIndex].SuppressionStatus == FALSE))
        {
            *DTCFunctionalUnit = DemPbCfgPtr->DemDTC[dtcIndex].DemDTCFunctionalUnit;
            ret = DEM_GET_FUNCTIONALUNITOFDTC_OK;
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Sets the DTC Filter.
 * ServiceId           0x13
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTCStatusMask:Status-byte mask for DTC status-byte filtering Values
 *                       DTCKind: Defines the functional group of DTCs to be reported
 *                       DTCFormat: Defines the output-format of the requested DTC values for the
 *                              sub-sequent API calls.
 *                       DTCOrigin: If the Dem supports more than one event memory this parameter
 *                              is used to select the source memory the DTCs shall be read from.
 *                       FilterWithSeverity: This flag defines whether severity information (ref.
 *                              to parameter below) shall be used for filtering
 *                       DTCSeverityMask: This parameter contains the DTCSeverityMask according
 *                              to ISO14229-1
 *                       FilterForFaultDetectionCounter: This flag defines whether the fault
 *                              detection counter information shall be used for filtering.
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Status of the operation to (re-)set a DTC filter.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnSetFilterType, DEM_CODE)
Dem_DcmSetDTCFilter(
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter)
{
    Dem_ReturnSetFilterType ret;
    DTCOrigin = Dem_GetInternalMemDest(DTCOrigin);
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    ret = DEM_WRONG_FILTER;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMSETDTCFILTER, DEM_E_UNINIT);
    }
    else if (
        ((DEM_DTC_FORMAT_OBD == DTCFormat) && (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT))
        || ((DEM_DTC_FORMAT_J1939 == DTCFormat) && (DEM_J1939_SUPPORT == STD_OFF))
        || ((DEM_DTC_REF_EMISSION_NUM == 0u) && (DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS))
        || (DTCOrigin == DEM_MEM_DEST_INVALID))
    {
        DEM_DET_REPORT(DEM_SID_DCMSETDTCFILTER, DEM_E_WRONG_CONFIGURATION);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON)
        /*SWS_Dem_00410*/
        if (((DTCStatusMask & 0xCu) != 0u) && ((DTCStatusMask & 0xF3u) == 0x00u))
        {
            DemDTCFilterInfo.TimeOrder = TRUE;
            DemDTCFilterInfo.LastTime = DemMemDestCfg[DTCOrigin].EntryNum + 1u;
        }
        else
        {
            DemDTCFilterInfo.TimeOrder = FALSE;
        }
#endif
        /* PRQA S 2985++ */ /* MISRA Rule 2.2 */
        DemDTCFilterInfo.DTCStatusMask = (0u == DTCStatusMask) ? (0xFFu & DEM_DTC_STATUS_AVAILABILITY_MASK)
                                                               : (DTCStatusMask & DEM_DTC_STATUS_AVAILABILITY_MASK);
        /* PRQA S 2985-- */ /* MISRA Rule 2.2 */
        DemDTCFilterInfo.RequestDTCStatusMask = DTCStatusMask;
        /* SWS_Dem_01058 */
        DemDTCFilterInfo.DTCKind = DTCKind;
        DemDTCFilterInfo.DTCFormat = DTCFormat;
        DemDTCFilterInfo.DTCOrigin = DTCOrigin;
        DemDTCFilterInfo.FilterWithSeverity = FilterWithSeverity;
        DemDTCFilterInfo.DTCSeverityMask = DTCSeverityMask;
        DemDTCFilterInfo.FilterForFaultDetectionCounter = FilterForFaultDetectionCounter;
        DemDTCFilterInfo.CurrentIndex = 0;
        DemDTCFilterInfo.NumberOfFilteredDTC = 0;
        DemDTCFilterInfo.IsSet = TRUE;
        ret = DEM_FILTER_ACCEPTED;
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the number of a filtered DTC.
 *                      (((statusOfDTC & DTCStatusMask) != 0) && ((severity & DTCSeverityMask) != 0)) == TRUE
 * ServiceId           0x17
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     NumberOfFilteredDTC:The number of DTCs matching the defined status mask.
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a number of DTC from the Dem
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dem_DcmGetNumberOfFilteredDTC(P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    Dem_DTCFilterInfoType* pFilter = &DemDTCFilterInfo;
    Dem_ReturnGetNumberOfFilteredDTCType ret = DEM_NUMBER_FAILED;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNUMBEROFFILTEREDDTC, DEM_E_UNINIT);
    }
    else if (NumberOfFilteredDTC == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNUMBEROFFILTEREDDTC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        if (DemDTCFilterInfo.IsSet == TRUE)
        {
#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON)
            /*SWS_Dem_00410*/
            if (DemDTCFilterInfo.TimeOrder == TRUE)
            {
                Dem_DTCOriginType DTCOrigin = pFilter->DTCOrigin;
                uint8 entryNum = DemMemDestCfg[DTCOrigin].EntryNum;
                Dem_EventMemEntryType* pEntry = DemMemDestCfg[DTCOrigin].EntryList;
                const Dem_DTCType* pDemDTC = DemPbCfgPtr->DemDTC;
                /* PRQA S 2982 */ /* MISRA Rule 2.2 */
                for (uint8 iloop = 0; iloop < entryNum; iloop++)
                {
                    Dem_EventMemEntryType Entry = pEntry[iloop];
                    if (Entry.EventId != 0x00u)
                    {
                        Dem_EventIdType IntId = Dem_GetEventInternalId(Entry.EventId);
                        uint16 dtcRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
                        Dem_DTCGeneralStatusType* pDemDTCGeneralStatus = &DemDTCGeneralStatus[iloop];
                        /* PRQA S 3415++ */ /* MISRA Rule 13.5 */
                        if ((dtcRef != DEM_DTC_REF_INVALID)
                            && ((0x00u != (pDemDTCGeneralStatus->CbUdsStatus & pFilter->DTCStatusMask))
                                || (0u == pFilter->RequestDTCStatusMask))
                            && (DEM_MEM_DEST_INVALID != Dem_CheckEventInternalMemDest(DTCOrigin, IntId))
                            && (TRUE == Dem_CheckDTCFormat(pFilter->DTCFormat, dtcRef))
                            && ((pFilter->FilterWithSeverity == FALSE)
                                || ((0x00u != (pFilter->DTCSeverityMask & pDemDTC[dtcRef].DemDTCSeverity))))
                            && (pFilter->FilterForFaultDetectionCounter == FALSE)
                            && (pDemDTC[dtcRef].DemDtcValue != DEM_DTC_CFG_INVALID)
                            && (FALSE == pDemDTCGeneralStatus->SuppressionStatus))
                        /* PRQA S 3415-- */ /* MISRA Rule 13.5 */
                        {
                            pFilter->NumberOfFilteredDTC++;
                        }
                    }
                }
            }
            else
#endif
            {
                const Dem_DTCType* pDemDTC = DemPbCfgPtr->DemDTC;
                /*SWS_Dem_00410*/
                for (uint8 iloop = 0; iloop < DEM_DTC_NUM; iloop++)
                {
                    Dem_DTCGeneralStatusType* pDemDTCGeneralStatus = &DemDTCGeneralStatus[iloop];
                    /* PRQA S 3415++ */ /* MISRA Rule 13.5 */
                    if (((0x00u != (pDemDTCGeneralStatus->CbUdsStatus & pFilter->DTCStatusMask))
                         || (0u == pFilter->RequestDTCStatusMask))
                        && (TRUE == Dem_CheckDTCFormat(pFilter->DTCFormat, iloop))
                        && ((pFilter->FilterWithSeverity == FALSE)
                            || ((0x00u != (pFilter->DTCSeverityMask & pDemDTC[iloop].DemDTCSeverity))))
                        && (pFilter->FilterForFaultDetectionCounter == FALSE)
                        && (pDemDTC[iloop].DemDtcValue != DEM_DTC_CFG_INVALID)
                        && (FALSE == pDemDTCGeneralStatus->SuppressionStatus))
                    /* PRQA S 3415-- */ /* MISRA Rule 13.5 */
                    {
                        pFilter->NumberOfFilteredDTC++;
                    }
                }
            }
            DemDTCFilterInfo.IsSet = FALSE;
            *NumberOfFilteredDTC = pFilter->NumberOfFilteredDTC;
            ret = DEM_NUMBER_OK;
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the next filtered DTC matching the filter criteria.
 * ServiceId           0x18
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     DTC : Receives the DTC value in respective format of the filter
 *                          returned by this function.
 *                       DTCStatus: This parameter receives the status information of
 *                          the requested DTC.
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a DTC from the Dem.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTC(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
    Dem_DTCFilterInfoType* pFilter = &DemDTCFilterInfo;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTC, DEM_E_UNINIT);
    }
    else if ((DTCStatus == NULL_PTR) || (DTC == NULL_PTR))
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        if ((pFilter->DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS)
            && ((pFilter->DTCStatusMask == DEM_UDS_STATUS_CDTC) || (pFilter->DTCStatusMask == DEM_UDS_STATUS_PDTC)
                || (pFilter->DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)))
        {
            /*idle*/
        }
        else
        {
            if (Dem_Pending == TRUE)
            {
                ret = DEM_FILTERED_PENDING;
            }
        }
        if (ret == DEM_FILTERED_NO_MATCHING_ELEMENT)
        {
#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON)
            /*SWS_Dem_00410,SWS_Dem_00411
             *the most recent event memory entry shall be reported at first.*/
            if (DemDTCFilterInfo.TimeOrder == TRUE)
            {
                uint8 entryNum = DemMemDestCfg[pFilter->DTCOrigin].EntryNum;
                Dem_EventMemEntryType* pEntry = DemMemDestCfg[pFilter->DTCOrigin].EntryList;
                const Dem_EventParameterType* pDemEventParameter = DemPbCfgPtr->DemEventParameter;
                for (uint8 index = 0; (index < entryNum) && (ret != DEM_FILTERED_OK); index++)
                {
                    uint8 Dem_time = 0;
                    boolean Find = FALSE;
                    for (uint8 iloop = 0; (iloop < entryNum) && (pEntry[iloop].EventId != 0u); iloop++)
                    {
                        Dem_EventRelateInformationType* pEvent =
                            Dem_GetEventInfo(Dem_GetEventInternalId(pEntry[iloop].EventId));
                        uint16 dtcRef = pDemEventParameter[pEvent->IntId].DemDTCRef;
                        uint8 AbsTime = pEntry[iloop].AbsTime;
                        /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                        if ((dtcRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcRef].SuppressionStatus == FALSE)
                            && (TRUE == Dem_CheckDTCFormat(pFilter->DTCFormat, dtcRef)) && (Dem_time < AbsTime)
                            && (AbsTime < pFilter->LastTime))
                        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                        {
                            pFilter->CurrentIndex = iloop;
                            Dem_time = AbsTime;
                            Find = TRUE;
                        }
                    }
                    if (Find == TRUE)
                    {
                        pFilter->LastTime = Dem_time;
                        Dem_EventRelateInformationType* pEvent =
                            Dem_GetEventInfo(Dem_GetEventInternalId(pEntry[pFilter->CurrentIndex].EventId));
                        uint16 dtcRef = pDemEventParameter[pEvent->IntId].DemDTCRef;
                        Dem_GetEventDTC(dtcRef, pFilter->DTCFormat, DTC);
                        /* PRQA S 2985++ */ /* MISRA Rule 2.2 */
                        *DTCStatus = DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_DTC_STATUS_AVAILABILITY_MASK;
                        /* PRQA S 2985-- */ /* MISRA Rule 2.2 */
                        if ((0u != (*DTCStatus & pFilter->DTCStatusMask)) && (0u != *DTC))
                        {
                            ret = DEM_FILTERED_OK;
                        }
                    }
                }
            }
            else
#endif
            {
                for (; pFilter->CurrentIndex < DEM_DTC_NUM; pFilter->CurrentIndex++)
                {
                    if (ret != DEM_FILTERED_OK)
                    {
                        uint16 dtcRef = pFilter->CurrentIndex;
                        if (dtcRef != DEM_DTC_REF_INVALID)
                        {
                            Dem_DTCGeneralStatusType* pDemDTCGeneralStatus = &DemDTCGeneralStatus[dtcRef];
                            /*SWS_Dem_01101*/
                            if ((pDemDTCGeneralStatus->SuppressionStatus == TRUE)
                                /* PRQA S 3415++ */ /* MISRA Rule 13.5 */
                                || (FALSE == Dem_CheckDTCFormat(pFilter->DTCFormat, dtcRef)))
                            /* PRQA S 3415-- */ /* MISRA Rule 13.5 */
                            {
                                ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
                            }
                            else
                            {
                                /*guarantee the event index the new dtc */
                                Dem_GetEventDTC(dtcRef, pFilter->DTCFormat, DTC);
                                /* PRQA S 2985++ */ /* MISRA Rule 2.2 */
                                *DTCStatus = pDemDTCGeneralStatus->CbUdsStatus & DEM_DTC_STATUS_AVAILABILITY_MASK;
                                /* PRQA S 2985-- */ /* MISRA Rule 2.2 */
                                if (((0u != (*DTCStatus & pFilter->DTCStatusMask))
                                     || (0u == DemDTCFilterInfo.RequestDTCStatusMask))
                                    && (0u != *DTC))
                                {
                                    ret = DEM_FILTERED_OK;
                                }
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the next filtered DTC and its associated Fault Detection Counter
 *                      (FDC) matching the filter criteria.
 * ServiceId           0x3b
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     DTC: Receives the DTC value in respective format of the filter
 *                          returned by this function.
 *                       DTCFaultDetectionCounter:This parameter receives the Fault Detection
 *                          Counter information of the requested DTC.
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a DTC from the Dem.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTCAndFDC(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
    Dem_DTCFilterInfoType* pFilter = &DemDTCFilterInfo;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDFDC, DEM_E_UNINIT);
    }
    else if ((DTCFaultDetectionCounter == NULL_PTR) || (DTC == NULL_PTR))
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDFDC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        for (; pFilter->CurrentIndex < DEM_DTC_NUM; pFilter->CurrentIndex++)
        {
            if (ret != DEM_FILTERED_OK)
            {
                uint16 dtcRef = pFilter->CurrentIndex;
                /*SWS_Dem_01101*/
                if ((dtcRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcRef].SuppressionStatus == FALSE)
                    && (TRUE == Dem_CheckDTCFormat(pFilter->DTCFormat, dtcRef)))
                {
                    /*guarantee the event index the new dtc */
                    Dem_GetEventDTC(dtcRef, pFilter->DTCFormat, DTC);
                    *DTCFaultDetectionCounter = FDCInfo[dtcRef].FDC;
                    /*SWS_Dem_00788 SWS_Dem_00789 SWS_Dem_00792 SWS_Dem_00793*/
                    /* PRQA S 2985++ */ /* MISRA Rule 2.2 */
                    if (0u != (DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_DTC_STATUS_AVAILABILITY_MASK))
                    /* PRQA S 2985-- */ /* MISRA Rule 2.2 */
                    {
                        ret = DEM_FILTERED_OK;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the next filtered DTC and its associated Severity matching the filter
                        criteria. The interface has an asynchronous behavior, because a large
                        number of DTCs has to be processed.
 * ServiceId           0x3d
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     DTC:Receives the DTC value in respective format of the
                            filter returned by this function. If the return value of
                            the function is other than DEM_FILTERED_OK this
                            parameter does not contain valid data.
 *                       DTCStatus:This parameter receives the status information of
                            the requested DTC.
                            It follows the format as defined in ISO14229-1
                            If the return value of the function call is other than
                            DEM_FILTERED_OK this parameter does not contain valid data.
 *                       DTCSeverity: Receives the severity value returned by the function.
 *                          If the return value of the function is other than
                            DEM_FILTERED_OK this parameter does not contain valid data
 *                       DTCFunctionalUnit: Receives the functional unit value returned by the
                            function. If the return value of the function is other
                            than DEM_FILTERED_OK this parameter does not
                            contain valid data.
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a DTC from the Dem.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTCAndSeverity(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
    Dem_DTCFilterInfoType* pFilter = &DemDTCFilterInfo;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDSEVERITY, DEM_E_UNINIT);
    }
    else if (
        (DTC == NULL_PTR) || (DTCStatus == NULL_PTR) || (DTCSeverity == NULL_PTR) || (DTCFunctionalUnit == NULL_PTR))
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDSEVERITY, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        for (; pFilter->CurrentIndex < DEM_DTC_NUM; pFilter->CurrentIndex++)
        {
            if (ret != DEM_FILTERED_OK)
            {
                uint16 dtcRef = pFilter->CurrentIndex;
                /*SWS_Dem_01101*/
                if ((dtcRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcRef].SuppressionStatus == FALSE)
                    && (TRUE == Dem_CheckDTCFormat(pFilter->DTCFormat, dtcRef)))
                {
                    const Dem_DTCType* pDemDTC = &DemPbCfgPtr->DemDTC[dtcRef];
                    /*guarantee the event index the new dtc */
                    Dem_GetEventDTC(dtcRef, pFilter->DTCFormat, DTC);
                    /* PRQA S 2985++ */ /* MISRA Rule 2.2 */
                    *DTCStatus = DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_DTC_STATUS_AVAILABILITY_MASK;
                    /* PRQA S 2985-- */ /* MISRA Rule 2.2 */
                    *DTCSeverity = pDemDTC->DemDTCSeverity;
                    *DTCFunctionalUnit = pDemDTC->DemDTCFunctionalUnit;
                    if ((0u != (*DTCStatus & pFilter->DTCStatusMask)) && (0u != *DTC))
                    {
                        ret = DEM_FILTERED_OK;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Sets a freeze frame record filter.
 * ServiceId           0x3f
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTCFormat: Defines the output-format of the requested DTC values for the
 *                           sub-sequent API calls.
 * Param-Name[out]     NumberOfFilteredRecords:Number of freeze frame records currently stored
 *                           in the event memory.
 * Param-Name[in/out]  none
 * Return              Status of the operation to (re-)set a freeze frame record filter.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnSetFilterType, DEM_CODE)
Dem_DcmSetFreezeFrameRecordFilter(
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Dem_ReturnSetFilterType ret = DEM_WRONG_FILTER;
#if (DEM_FREEZE_FRAME_CLASS_NUM > 0u)
    Dem_FreezeFrameRecordFilterInfoType* pFilter = &DemFreezeFrameRecordFilterInfo;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    ret = DEM_WRONG_FILTER;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMSETFREEZEFRAMERECORDFILTER, DEM_E_UNINIT);
    }
    else if (DEM_DTC_FORMAT_UDS != DTCFormat)
    {
        DEM_DET_REPORT(DEM_SID_DCMSETFREEZEFRAMERECORDFILTER, DEM_E_WRONG_CONFIGURATION);
    }
    else if (NumberOfFilteredRecords == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMSETFREEZEFRAMERECORDFILTER, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        Dem_DTCOriginType DTCOrigin = Dem_GetInternalMemDest(DEM_DTC_ORIGIN_PRIMARY_MEMORY);
        const Dem_MemDestConfigType* pDemMemDestCfg = &DemMemDestCfg[DTCOrigin];
        Dem_EventMemEntryType* pEntry = pDemMemDestCfg->EntryList; /*SWS_Dem_00210*/
        const uint8 EntryNum = pDemMemDestCfg->EntryNum;
        *NumberOfFilteredRecords = 0;
        for (uint8 iloop = 0; iloop < EntryNum; iloop++)
        {
            if (pEntry->EventId != 0x00u)
            {
                *NumberOfFilteredRecords += pEntry->FFNum;
            }
            pEntry++;
        }
        pFilter->DTCFormat = DTCFormat;
        pFilter->GetNum = 0;
        pFilter->EntryIndex = 0;
        pFilter->FFIndex = 0;
        pFilter->NumberOfFilteredRecords = *NumberOfFilteredRecords;
        ret = DEM_FILTER_ACCEPTED;
    }
#else
    DEM_UNUSED(DTCFormat);
    DEM_UNUSED(NumberOfFilteredRecords);
    ret = DEM_WRONG_FILTER;
#endif /* DEM_FREEZE_FRAME_CLASS_NUM > 0u */
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the next freeze frame record number and its associated DTC
 *                          stored in the event memory.
 * ServiceId           0x3a
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     DTC:Receives the DTC value in respective format of the filter
 *                          returned by this function.
 *                       RecordNumber:Freeze frame record number of the reported DTC
 *                          (relative addressing).
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a DTC and its associated
 *                          snapshot record number from the Dem.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredRecord(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetNextFilteredElementType ret;
#if (DEM_FREEZE_FRAME_CLASS_NUM > 0)
    Dem_FreezeFrameRecordFilterInfoType* pFilter = &DemFreezeFrameRecordFilterInfo;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDRECORD, DEM_E_UNINIT);
    }
    else if (DTC == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDRECORD, DEM_E_PARAM_POINTER);
    }
    else if (RecordNumber == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETNEXTFILTEREDRECORD, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        Dem_DTCOriginType DTCOrigin = Dem_GetInternalMemDest(DEM_DTC_ORIGIN_PRIMARY_MEMORY);
        const uint8 EntryNum = DemMemDestCfg[DTCOrigin].EntryNum;
        for (; pFilter->GetNum < pFilter->NumberOfFilteredRecords;)
        {
            if (pFilter->EntryIndex >= EntryNum) /*SWS_Dem_00210*/
            {
                pFilter->EntryIndex = 0;
                pFilter->FFIndex = 0;
            }
            else
            {
                Dem_EventMemEntryType* pEntry = &DemMemDestCfg[DTCOrigin].EntryList[pFilter->EntryIndex];
                if (pFilter->FFIndex >= DEM_MAX_NUMBER_FF_RECORDS)
                {
                    pFilter->FFIndex = 0;
                    pFilter->EntryIndex++;
                }
                else
                {
                    if (pEntry->FFList[pFilter->FFIndex].RecordNum != 0xFFu)
                    {
                        /*SWS_Dem_01101*/
                        Dem_EventIdType IntId = Dem_GetEventInternalId(pEntry->EventId);
                        uint16 DTCRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
                        if ((DTCRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[DTCRef].SuppressionStatus == TRUE))
                        {
                            ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
                        }
                        else
                        {
                            Dem_GetEventDTC(DTCRef, pFilter->DTCFormat, DTC);
                            *RecordNumber = pEntry->FFList[pFilter->FFIndex].RecordNum;
                            ret = DEM_FILTERED_OK;
                            break;
                        }
                        pFilter->GetNum++;
                    }
                    pFilter->FFIndex++;
                }
            }
        }
    }
#else
    DEM_UNUSED(DTC);
    DEM_UNUSED(RecordNumber);
    ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
#endif
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the DTC by occurrence time.
 * ServiceId           0x19
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTCRequest:This parameter defines the request type of the DTC.
 * Param-Name[out]     DTC: Receives the DTC value in UDS format returned by the function.
 * Param-Name[in/out]  none
 * Return              Status of the operation of type Dem_ReturnGetDTCByOccurrenceTimeType.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dem_DcmGetDTCByOccurrenceTime(Dem_DTCRequestType DTCRequest, P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    Dem_EventIdType IntId;
    Dem_ReturnGetDTCByOccurrenceTimeType ret = DEM_OCCURR_NOT_AVAILABLE;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETDTCBYOCCURRENCETIME, DEM_E_UNINIT);
    }
    else if (DTC == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETDTCBYOCCURRENCETIME, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        switch (DTCRequest)
        {
        case DEM_FIRST_FAILED_DTC:
            IntId = DemDTCByOccurrenceTimeInfo.FirstFailed;
            break;
        case DEM_MOST_RECENT_FAILED_DTC:
            IntId = DemDTCByOccurrenceTimeInfo.MostRecentFailed;
            break;
        case DEM_FIRST_DET_CONFIRMED_DTC:
            IntId = DemDTCByOccurrenceTimeInfo.FirstDtcConfirmed;
            break;
        case DEM_MOST_REC_DET_CONFIRMED_DTC:
            IntId = DemDTCByOccurrenceTimeInfo.MostRecDtcConfirmed;
            break;
        default:
            IntId = DEM_EVENT_PARAMETER_INVALID;
            break;
        }
        if (IntId != DEM_EVENT_PARAMETER_INVALID)
        {
            uint16 DTCRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
            /*SWS_Dem_01101*/
            if ((DTCRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[DTCRef].SuppressionStatus == FALSE))
            {
                Dem_GetEventDTC(DTCRef, DEM_DTC_FORMAT_UDS, DTC);
                ret = DEM_OCCURR_OK;
            }
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 * ServiceId           0xb0
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TriggerNotification:This parameter specifies whether the triggering of
 *                          the notification shall be enabled (TRUE) or disabled (FALSE).
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DcmControlDTCStatusChangedNotification(boolean TriggerNotification)
{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMCONTROLDTCSTATUSCHANGEDNOTIFICATION, DEM_E_UNINIT);
    }
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    DemDTCStatusChangedInd = TriggerNotification;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**      Access extended data records and FreezeFrame data                     **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Disables the event memory update of a specific DTC
 *                          (only one at one time).
 * ServiceId           0x1a
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC:Selects the DTC in UDS format, for which DTC record update
 *                          shall be disabled.
 *                       DTCOrigin: If the Dem supports more than one event memory,
 *                          this parameter is used to select the source memory
 *                          for which DTC record update shall be disabled.
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Status of the operation to disable the event memory
 *                          update of a specific DTC.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE)
Dem_DcmDisableDTCRecordUpdate(uint32 DTC, Dem_DTCOriginType DTCOrigin) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Dem_ReturnDisableDTCRecordUpdateType ret = DEM_DISABLE_DTCRECUP_WRONG_DTC;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMDISABLEDTCRECORDUPDATE, DEM_E_UNINIT);
    }
    else if (DemDTCDisable == TRUE)
    {
        DEM_DET_REPORT(DEM_SID_DCMDISABLEDTCRECORDUPDATE, DEM_E_WRONG_CONDITION);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        uint16 dtcIndex = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS);
        if (dtcIndex != DEM_DTC_REF_INVALID)
        {
            Dem_DTCOriginType InOrigin = Dem_GetInternalMemDest(DTCOrigin);
            if (InOrigin == DEM_MEM_DEST_INVALID)
            {
                ret = DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN;
            }
            else
            {
                DemDTCDisable = TRUE;
                DTCRecordUpdateStatusInfo.DTCIndex = dtcIndex;
                DTCRecordUpdateStatusInfo.DTCOrigin = InOrigin;
                DEM_BITS_SET(DemMemDestInfo[InOrigin].DisableDTCRecordUpdate, dtcIndex);
                ret = DEM_DISABLE_DTCRECUP_OK;
            }
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Enables the event memory update of the DTC disabled by
 *                          Dem_DcmDisableDTCRecordUpdate() before.
 * ServiceId           0x1b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Always E_OK is returned.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmEnableDTCRecordUpdate(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    ret = E_NOT_OK;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMENABLEDTCRECORDUPDATE, DEM_E_UNINIT);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        DemDTCDisable = FALSE;
        DEM_BITS_CLR(
            DemMemDestInfo[DTCRecordUpdateStatusInfo.DTCOrigin].DisableDTCRecordUpdate,
            DTCRecordUpdateStatusInfo.DTCIndex);
        ret = E_OK;
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets freeze frame data by DTC. The function stores the data
 *                          in the provided DestBuffer.
 * ServiceId           0x1d
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC : Diagnostic Trouble Code in UDS format.
 *                       DTCOrigin:If the Dem supports more than one event memory,
 *                          this parameter is used to select the source memory
 *                          the DTCs shall be read from.
 *                       RecordNumber:This parameter is a unique identifier for a freeze
 *                          frame record as defined in ISO 15031-5 and ISO 14229-1.
 * Param-Name[out]     DestBuffer:This parameter contains a byte pointer that points
 *                          to the buffer, to which the freeze frame data record
 *                          shall be written to.
 * Param-Name[in/out]  BufSize:When the function is called this parameter contains
 *                          the maximum number of data bytes that can be written to the buffer.
 * Return              Status of the operation to retrieve freeze frame data by DTC.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dem_DcmGetFreezeFrameDataByDTC(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    Dem_ReturnGetFreezeFrameDataByDTCType ret = DEM_GET_FFDATABYDTC_WRONG_DTC;
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0u) && (DEM_DID_CLASS_NUM > 0u))
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETFREEZEFRAMEDATABYDTC, DEM_E_UNINIT);
    }
    else if ((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
    {
        DEM_DET_REPORT(DEM_SID_DCMGETFREEZEFRAMEDATABYDTC, DEM_E_PARAM_POINTER);
    }
    else if (RecordNumber == 0xFFu)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETFREEZEFRAMEDATABYDTC, DEM_E_PARAM_DATA);
        ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        /*SWS_Dem_01100 SWS_Dem_01101*/
        uint16 dtcIndex = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS);
        if ((dtcIndex != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcIndex].SuppressionStatus == FALSE))
        {
            uint8 memDest = Dem_GetInternalMemDest(DTCOrigin);
            ret = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
            if (memDest != DEM_MEM_DEST_INVALID)
            {
                const Dem_DTCType* pDemDTC = &DemPbCfgPtr->DemDTC[dtcIndex];
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                const Dem_EventIdType EventRefNum = pDemDTC->EventRefNum;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                const Dem_EventIdType EventRefStart = pDemDTC->EventRefStart;
                const Dem_EventIdType* pDTCMapping = &DemPbCfgPtr->DemDTCMapping[EventRefStart];
                *BufSize = 0u;
                ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                for (uint16 iloop = 0; iloop < EventRefNum; iloop++)
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                {
                    const Dem_DTCAttributesType* pDTCAttrCfg = Dem_EventDTCAttributesCfg(*pDTCMapping);
                    uint16 FFClassRef = pDTCAttrCfg->DemFreezeFrameClassRef;
                    if (FFClassRef != DEM_FREEZE_FRAME_INVALID)
                    {
#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
                        boolean Find = FALSE;
                        const Dem_FreezeFrameRecNumClassType* PDemFFRecNumClass =
                            &DemFreezeFrameRecNumClass[pDTCAttrCfg->DemFreezeFrameRecNumClassRef];
                        const uint8 RefNum = PDemFFRecNumClass->RefNum;
                        const uint8* pFFRecordIndex = &DemFreezeFrameRecordClassRef[PDemFFRecNumClass->StartIndex];
                        for (uint8 index = 0u; (index < RefNum) && (Find == FALSE); index++)
                        {
                            if (((*pFFRecordIndex) != DEM_FREEZE_FRAME_RECORD_INVALID)
                                && (DemFreezeFrameRecordClass[*pFFRecordIndex].DemFreezeFrameRecordNumber
                                    == RecordNumber))
                            {
                                Find = TRUE;
                            }
                            pFFRecordIndex++;
                        }
                        if (Find == TRUE)
                        {
#endif /* DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED */
                            Dem_EventMemEntryType* pEntry =
                                Dem_MemEntryGet(Dem_GetEventExternalId(*pDTCMapping), memDest);
                            ret = DEM_GET_FFDATABYDTC_FAILED;
                            if (pEntry != NULL_PTR)
                            {
                                Dem_FreezeFrameInfoType* pFF = Dem_FreezeFrameGetByRecordNum(pEntry, RecordNumber);
                                if (pFF != NULL_PTR)
                                {
                                    const Dem_FreezeFrameClassType* pFFClass = &DemFreezeFrameClass[FFClassRef];
                                    uint8* pFFData = pFF->Data;
                                    uint16 offset = 0;
                                    const uint16* pDidIndex = &DemDidClassRef[pFFClass->StartIndex];
                                    const uint8 FFRefNum = pFFClass->RefNum;
                                    DestBuffer[*BufSize] = FFRefNum;
                                    (*BufSize) += 1u;
                                    for (uint8 didRefNum = 0u; didRefNum < FFRefNum; didRefNum++)
                                    {
                                        const Dem_DidClassType* pDid = &DemDidClass[*pDidIndex];
                                        /* DemIdentifier */
                                        DestBuffer[*BufSize] = (uint8)((pDid->DemDidIdentifier) >> 8u);
                                        (*BufSize) += 1u;
                                        DestBuffer[*BufSize] = (uint8)(pDid->DemDidIdentifier);
                                        (*BufSize) += 1u;
#if (DEM_DATA_ELEMENT_CLASS_NUM > 0u)
                                        uint16 dataSize = pDid->DataSize;
                                        Dem_MemCopy(&DestBuffer[*BufSize], &pFFData[offset], dataSize);
                                        offset += dataSize;
                                        (*BufSize) += dataSize;
#endif /* DEM_DATA_ELEMENT_CLASS_NUM > 0u */
                                        pDidIndex++;
                                    }
                                    ret = DEM_GET_FFDATABYDTC_OK;
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                                    break;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                                }
                            }
                        }
                    }
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                    pDTCMapping++;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                }
            }
        }
    }
#else
    DEM_UNUSED(DTC);
    DEM_UNUSED(DTCOrigin);
    DEM_UNUSED(RecordNumber);
    DEM_UNUSED(DestBuffer);
    DEM_UNUSED(BufSize);
#endif
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Gets the size of freeze frame data by DTC.
 * ServiceId           0x1f
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC : Diagnostic Trouble Code in UDS format
 *                       DTCOrigin : If the Dem supports more than one event memory,
 *                          this parameter is used to select the source memory
 *                          the DTCs shall be read from.
 *                       RecordNumber: This parameter is a unique identifier for a freeze
 *                          frame record as defined in ISO 15031-5 and ISO 14229-1.
 * Param-Name[out]     SizeOfFreezeFrame:
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)
Dem_DcmGetSizeOfFreezeFrameByDTC(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_WRONG_DTC;
#if (DEM_FREEZE_FRAME_CLASS_NUM > 0u)
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSIZEOFFREEZEFRAMEBYDTC, DEM_E_UNINIT);
    }
    else if (SizeOfFreezeFrame == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSIZEOFFREEZEFRAMEBYDTC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {  /*SWS_Dem_01100 SWS_Dem_01101 */
        uint16 dtcRef = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS);
        if ((dtcRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcRef].SuppressionStatus == FALSE))
        {
            uint8 memDest = Dem_GetInternalMemDest(DTCOrigin);
            ret = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
            if (memDest != DEM_MEM_DEST_INVALID)
            {
                const Dem_DTCType* pDemDTC = &DemPbCfgPtr->DemDTC[dtcRef];
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                const Dem_EventIdType EventRefNum = pDemDTC->EventRefNum;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                const Dem_EventIdType EventRefStart = pDemDTC->EventRefStart;
                const Dem_EventIdType* pDTCMapping = &DemPbCfgPtr->DemDTCMapping[EventRefStart];
                *SizeOfFreezeFrame = 0u;
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                for (uint16 iloop = 0u; iloop < EventRefNum; iloop++)
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                {
                    Dem_EventMemEntryType* pEntry = Dem_MemEntryGet(Dem_GetEventExternalId(*pDTCMapping), memDest);
                    if (pEntry != NULL_PTR)
                    {
                        const Dem_DTCAttributesType* pDTCAttr = Dem_EventDTCAttributesCfg(*pDTCMapping);
                        uint16 DataSize = DemFreezeFrameClass[pDTCAttr->DemFreezeFrameClassRef].DataSize;
                        if (RecordNumber == 0xFFu)
                        {
                            Dem_FreezeFrameInfoType* FFList = pEntry->FFList;
#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
                            const uint8 RefNum =
                                DemFreezeFrameRecNumClass[pDTCAttr->DemFreezeFrameRecNumClassRef].RefNum;
                            for (uint8 index = 0; index < RefNum; index++)
#else
                            for (uint8 index = 0; index < pDTCAttr->DemMaxNumberFreezeFrameRecords; index++)
#endif /* DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED */
                            {
                                if (FFList->RecordNum != 0xFFu)
                                {
                                    *SizeOfFreezeFrame += DataSize;
                                }
                                FFList++;
                            }
                        }
                        else
                        {
                            *SizeOfFreezeFrame += DataSize;
                        }
                        ret = DEM_GETSIZEBYDTC_OK;
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                        break;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                    }
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                    pDTCMapping++;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                }
            }
        }
    }
#else
    DEM_UNUSED(DTC);
    DEM_UNUSED(DTCOrigin);
    DEM_UNUSED(RecordNumber);
    DEM_UNUSED(SizeOfFreezeFrame);
#endif /* DEM_FREEZE_FRAME_CLASS_NUM > 0u */
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets extended data by DTC. The function stores the data in
 *                          the provided DestBuffer.
 * ServiceId           0x20
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC:Diagnostic Trouble Code in UDS format.
 *                       DTCOrigin:If the Dem supports more than one event memory,
 *                          this parameter is used to select the source memory
 *                          the DTCs shall be read from.
 *                       ExtendedDataNumber:dentification/Number of requested extended data
 *                       record. The values 0xFE and 0xFF are not allowed.
 * Param-Name[out]     DestBuffer:This parameter contains a byte pointer that points to
 *                          the buffer, to which the extended data record shall
 *                          be written to.
 * Param-Name[in/out]  BufSize:When the function is called this parameter contains
 *                          the maximum number of data bytes that can be written to the buffer.
 * Return              Status of the operation to retrieve extended data by DTC.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dem_DcmGetExtendedDataRecordByDTC(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    Dem_ReturnGetExtendedDataRecordByDTCType ret = DEM_RECORD_WRONG_DTC;
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0u)
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETEXTENDEDDATARECORDBYDTC, DEM_E_UNINIT);
    }
    else if ((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
    {
        DEM_DET_REPORT(DEM_SID_DCMGETEXTENDEDDATARECORDBYDTC, DEM_E_PARAM_POINTER);
    }
    else if (ExtendedDataNumber >= 0xFEu)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETEXTENDEDDATARECORDBYDTC, DEM_E_PARAM_DATA);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
        uint16 dtcRef = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS); /*SWS_Dem_01100 SWS_Dem_01101*/
        if ((dtcRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcRef].SuppressionStatus == FALSE))
        {
            uint8 memDest = Dem_GetInternalMemDest(DTCOrigin);
            ret = DEM_RECORD_WRONG_DTCORIGIN; /*SWS_Dem_00171*/
            if (memDest != DEM_MEM_DEST_INVALID)
            {
                const Dem_DTCAttributesType* pDTCAttrCfg =
                    &DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[dtcRef].DemDTCAttributesRef];
                const uint16 EDClassRef = pDTCAttrCfg->DemExtendedDataClassRef;
                ret = DEM_RECORD_WRONG_NUMBER;
                if (DEM_EXTENDED_DATA_INVALID != EDClassRef)
                {
                    ret = DEM_RECORD_OK;
                    const Dem_DTCType* pDemDTC = &DemPbCfgPtr->DemDTC[dtcRef];
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                    const Dem_EventIdType EventRefNum = pDemDTC->EventRefNum;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                    const Dem_EventIdType EventRefStart = pDemDTC->EventRefStart;
                    const Dem_EventIdType* pDTCMapping = &DemPbCfgPtr->DemDTCMapping[EventRefStart];
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                    for (uint16 iloop = 0u; (iloop < EventRefNum) && (ret == DEM_RECORD_OK); iloop++)
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                    {
                        Dem_EventMemEntryType* pEntry = Dem_MemEntryGet(Dem_GetEventExternalId(*pDTCMapping), memDest);
                        if (pEntry != NULL_PTR)
                        {
                            ret = Dem_ExtendedDataGetFromEntry(pEntry, ExtendedDataNumber, DestBuffer, BufSize);
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                            break;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                        }
                        else
                        {
                            *BufSize = 0u;
                            ret = DEM_RECORD_WRONG_NUMBER;
                            const Dem_ExtendedDataClassType* pEDClass = &DemExtendedDataClass[EDClassRef];
                            uint8 RefNum = pEDClass->RefNum;
                            const uint8* pExtIndex = &DemExtendedDataRecordClassRef[pEDClass->StartIndex];
                            for (uint8 index = 0; index < RefNum; index++)
                            {
                                if (*pExtIndex != DEM_EXTENDED_DATA_RECORD_INVALID)
                                {
                                    const Dem_ExtendedDataRecordClassType* pExtRecord =
                                        &DemExtendedDataRecordClass[index];
                                    if (pExtRecord->DemExtendedDataRecordNumber == ExtendedDataNumber)
                                    {
                                        ret = DEM_RECORD_OK;
                                        break;
                                    }
                                }
                            }
                        }
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                        pDTCMapping++;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                    }
                }
            }
        }
    }
#else
    DEM_UNUSED(DTC);
    DEM_UNUSED(DTCOrigin);
    DEM_UNUSED(RecordNumber);
    DEM_UNUSED(SizeOfFreezeFrame);
#endif
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the size of extended data by DTC.
 * ServiceId           0x21
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC:Diagnostic Trouble Code in UDS format.
 *                      DTCOrigin:If the Dem supports more than one event memory ,
 *                          this parameter is used to select the source memory
 *                          the DTCs shall be read from.
 *                      ExtendedDataNumber:Identification/Number of requested extended
 *                          data record.
 * Param-Name[out]     SizeOfExtendedDataRecord:Size of the requested extended data record(s)
 *                          including record number size
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve the size of extended data.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)
Dem_DcmGetSizeOfExtendedDataRecordByDTC(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_WRONG_DTC;
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0u)
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSIZEOFEXTENDEDDATARECORDBYDTC, DEM_E_UNINIT);
    }
    else if (SizeOfExtendedDataRecord == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_DCMGETSIZEOFEXTENDEDDATARECORDBYDTC, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {  /*SWS_Dem_01100 SWS_Dem_01101*/
        uint16 dtcRef = Dem_GetDTCIndex(DTC, DEM_DTC_FORMAT_UDS);
        if ((dtcRef != DEM_DTC_REF_INVALID) && (DemDTCGeneralStatus[dtcRef].SuppressionStatus == FALSE))
        {
            uint8 memDest = Dem_GetInternalMemDest(DTCOrigin);
            ret = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
            if (memDest != DEM_MEM_DEST_INVALID)
            {
                *SizeOfExtendedDataRecord = 0;
                uint8 Start;
                uint8 End;
                if (ExtendedDataNumber == 0xFEu)
                {
                    Start = 0x90u;
                    End = 0xEFu;
                }
                else if (ExtendedDataNumber == 0xFFu)
                {
                    Start = 0x01u;
                    End = 0xEFu;
                }
                else
                {
                    Start = ExtendedDataNumber;
                    End = ExtendedDataNumber + 1u;
                }
                ret = DEM_GETSIZEBYDTC_OK;
                for (; (Start < End) && (DEM_GETSIZEBYDTC_OK == ret); Start++)
                {
                    const Dem_ExtendedDataRecordClassType* pExtDataCfg = NULL_PTR;
                    const Dem_DTCType* pDemDTC = &DemPbCfgPtr->DemDTC[dtcRef];
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                    const Dem_EventIdType EventRefNum = pDemDTC->EventRefNum;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                    const Dem_EventIdType EventRefStart = pDemDTC->EventRefStart;
                    const Dem_EventIdType* pDTCMapping = &DemPbCfgPtr->DemDTCMapping[EventRefStart];
                    /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
                    for (uint8 iloop = 0; iloop < DEM_EXTENDED_DATA_RECORD_CLASS_NUM; iloop++)
                    /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
                    {
                        if (DemExtendedDataRecordClass[iloop].DemExtendedDataRecordNumber == ExtendedDataNumber)
                        {
                            pExtDataCfg = &(DemExtendedDataRecordClass[iloop]);
                            break;
                        }
                    }
                    if (pExtDataCfg == NULL_PTR)
                    {
                        ret = DEM_GETSIZEBYDTC_WRONG_RECNUM;
                    }
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                    for (uint16 iloop = 0u; iloop < EventRefNum; iloop++)
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                    {
                        Dem_EventMemEntryType* pEntry = Dem_MemEntryGet(Dem_GetEventExternalId(*pDTCMapping), memDest);
                        if (pEntry != NULL_PTR)
                        {
                            *SizeOfExtendedDataRecord += pExtDataCfg->DataSize;
                        }
#if (DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON)
                        pDTCMapping++;
#endif /* DEM_ONEDTCMAPPINGMUTILEVENT == STD_ON */
                    }
                }
            }
        }
    }
#else
    DEM_UNUSED(DTC);
    DEM_UNUSED(DTCOrigin);
    DEM_UNUSED(ExtendedDataNumber);
    DEM_UNUSED(SizeOfExtendedDataRecord);
#endif /* DEM_EXTENDED_DATA_CLASS_NUM > 0u */
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/********[DTC storage]*********/

/*************************************************************************/
/*
 * Brief               Performs a parameter check and gives the result which would also be
                        returned by calling clear with same parameters.
 * ServiceId           0x7b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTC:Defines the DTC in respective format, that shall be
 *                          cleared from the event memory. If the DTC fits to a
 *                          DTC group number, all DTCs of the group shall be cleared.
 *                       DTCFormat:Defines the input-format of the provided DTC value.
 *                       DTCOrigin:If the Dem supports more than one event memory
 *                          this parameter is used to select the source memory
 *                          the DTCs shall be read from.
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Returns the result of the parameter check when performing a
 *                      clear command with same parameters (refer to Dem_DcmClearDTC).
                        Only the following return values will be used:
                        DEM_CLEAR_OK: DTC successfully cleared
                        DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format)
                        DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin
                        DEM_CLEAR_FAILED: In case of general errors
with clear parameters
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnClearDTCType, DEM_CODE)
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
Dem_DcmCheckClearParameter(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    Dem_ReturnClearDTCType ret;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMCHECKCLEARPARAMETER, DEM_E_UNINIT);
        ret = DEM_GETSIZEBYDTC_WRONG_DTC;
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
        if (DemClearDTCLock == DEM_CLEAR_LOCK)
        {
            ret = DEM_CLEAR_PENDING;
        }
        else
        {
            ret = DEM_CLEAR_WRONG_DTCORIGIN;
            if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)
            {
                ret = DEM_CLEAR_WRONG_DTC;
                /* PRQA S 3415++ */ /* MISRA Rule 13.5 */
                if ((DTC == DEM_DTC_GROUP_ALL_DTCS)
#if (DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS)
                    || (Dem_GetDTCIndex(DTC, DTCFormat) != DEM_DTC_REF_INVALID)
                /* PRQA S 3415-- */ /* MISRA Rule 13.5 */
#if (DEM_GROUP_OF_DTC_NUM > 0u)
                    /* PRQA S 3415++ */ /* MISRA Rule 13.5 */
                    || (DEM_GROUP_OF_DTC_INVALID != Dem_GetDTCGroupIndex(DTC))
                /* PRQA S 3415-- */ /* MISRA Rule 13.5 */
#endif                              /* DEM_GROUP_OF_DTC_NUM > 0u */
#endif                              /* DEM_CLEAR_DTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS */
                )
                {
#if (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_VOLATILE)
                    /*SWS_Dem_00570*/
                    DemClearDTCLock = DEM_CLEAR_NOT_LOCK;
                    ret = DEM_CLEAR_OK;
#elif (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
                /*SWS_Dem_00571*/
                DemClearDTCLock = DEM_CLEAR_NOT_LOCK;
                DemClearNonvolatile = TRUE;
                ret = DEM_CLEAR_OK;
#elif (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_NONVOLATILE_FINISH)
                DemClearNonvolatile = TRUE;
                if (DemClearNonvolatileOK == 0x00u)
                {
                    /*SWS_Dem_00572*/
                    DemClearDTCLock = DEM_CLEAR_NOT_LOCK;
                    DemClearNonvolatileOK = 0x02;
                    ret = DEM_CLEAR_OK;
                }
                else if (DemClearNonvolatileOK == 0x01u)
                {
                    /*SWS_Dem_01057*/
                    DemClearDTCLock = DEM_CLEAR_NOT_LOCK;
                    DemClearNonvolatileOK = 0x02;
                    ret = DEM_CLEAR_MEMORY_ERROR;
                }
                else
                {
                    /*SWS_Dem_00662 SWS_Dem_00664*/
                    Dem_ClearDTCInfoType* pClr = &DemClearDTCInfo;
                    ret = DEM_CLEAR_OK;
                    if ((pClr->DTCIndex == Dem_GetDTCIndex(DTC, DTCFormat)) && (pClr->DTCFormat == DTCFormat)
                        && (pClr->DTCOrigin == DTCOrigin) && (pClr->SID == DEM_SID_DCMCLEARDTC))
                    {
                        /*SWS_Dem_00663*/
                        ret = DEM_CLEAR_PENDING;
                    }
                }
#endif /* DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_VOLATILE */
                }
            }
        }

#if ((DEM_CLEAR_DTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS) && (DEM_CLEAR_DTCBEHAVIOR != DEM_CLRRESP_NONVOLATILE_FINISH))
    DEM_UNUSED(DTCFormat);
#endif /* (DEM_CLEAR_DTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS) && (DEM_CLEAR_DTCBEHAVIOR != \
          DEM_CLRRESP_NONVOLATILE_FINISH) */
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Clears single DTCs, as well as groups of DTCs. This API is intended
                       for the Dcm. It can only be used through the RTE (due to work-around
                       described below SWS_Dem_00009), and therefore no declaration is exported via Dem_Dcm.h.
 * ServiceId           0x22
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTC:Defines the DTC in respective format, that shall be
 *                          cleared from the event memory. If the DTC fits to a
 *                          DTC group number, all DTCs of the group shall be cleared.
 *                       DTCFormat:Defines the input-format of the provided DTC value.
 *                       DTCOrigin:If the Dem supports more than one event memory
 *                          this parameter is used to select the source memory
 *                          the DTCs shall be read from.
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Status of the operation of type Dem_ReturnClearDTCType.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 0624++ */ /* MISRA Rule 8.3 */
FUNC(Dem_ReturnClearDTCType, DEM_CODE)
Dem_DcmClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
/* PRQA S 0624-- */ /* MISRA Rule 8.3 */
{
    Dem_ReturnClearDTCType ret = DEM_CLEAR_WRONG_DTCORIGIN;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMCLEARDTC, DEM_E_UNINIT);
        ret = DEM_CLEAR_FAILED;
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
        if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)
        {
#if (DEM_DTR_NUM > 0u)
            if ((DTC == DEM_DTC_GROUP_ALL_DTCS) && (DEM_DTC_FORMAT_OBD == DTCFormat))
            {
                const DTRType* pDTR = DemPbCfgPtr->DTR;
                for (uint16 iloop = 0; iloop < DEM_DTR_NUM; iloop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
                {
                    if (pDTR[iloop].DemDtrEventRef == DEM_EVENT_PARAMETER_INVALID)
                    {
                        Dem_ClearDTRInfoByDTRID(iloop); /*SWS_Dem_00764*/
                    }
                }
            }
#endif /* DEM_DTR_NUM > 0u */
            Dem_ClearDTCInfoType* pClr = &DemClearDTCInfo;
            uint16 dtcRef = Dem_GetDTCIndex(DTC, DTCFormat);
            boolean ProcessOn = TRUE;
            if (DemClearDTCLock == DEM_CLEAR_LOCK)
            {
                /*SWS_Dem_00662 SWS_Dem_00664*/
                ret = DEM_CLEAR_BUSY;
                if ((pClr->SaveDTCIndex == dtcRef) && (pClr->SaveDTCFormat == DTCFormat)
                    && (pClr->SaveDTCOrigin == DTCOrigin) && (pClr->SID == DEM_SID_DCMCLEARDTC))
                {
                    /*SWS_Dem_00663*/
                    ret = DEM_CLEAR_PENDING;
                }
                ProcessOn = FALSE;
            }
            else if (DemClearDTCLock == DEM_CLEAR_NOT_LOCK)
            {
                DemClearDTCLock = DEM_CLEAR_LOCK; /*SWS_Dem_00661*/
                pClr->DTCIndex = dtcRef;
                pClr->DTCFormat = DTCFormat;
                pClr->DTCOrigin = DTCOrigin;
                pClr->SaveDTCIndex = dtcRef;
                pClr->SaveDTCFormat = DTCFormat;
                pClr->SaveDTCOrigin = DTCOrigin;
                pClr->SID = DEM_SID_CLEARDTC;
            }
            else
            {
                /*idle*/
            }
            /*SWS_Dem_00670] */
            if (ProcessOn == TRUE)
            {
#if (DEM_CLEAR_DTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
                if (DTCFormat != DEM_DTC_FORMAT_UDS || DTC != DEM_DTC_GROUP_ALL_DTCS)
                {
                    ret = DEM_CLEAR_WRONG_DTC;
                }
                else
#endif /* DEM_CLEAR_DTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS */
                {
                    ret = DEM_CLEAR_WRONG_DTCORIGIN;
                    if (Dem_GetInternalMemDest(DTCOrigin) != DEM_MEM_DEST_INVALID)
                    {
                        ProcessOn = TRUE;
                        if (DTC == DEM_DTC_GROUP_ALL_DTCS)
                        {
                            pClr->ClearAllGroup = TRUE;
                        }
#if (DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS)
                        else
                        {
                            ret = DEM_CLEAR_WRONG_DTC;
                            pClr->ClearAllGroup = FALSE;
#if (DEM_GROUP_OF_DTC_NUM > 0u)
                            pClr->DTCGroupIndex = Dem_GetDTCGroupIndex(DTC);
                            if ((DEM_GROUP_OF_DTC_INVALID == pClr->DTCGroupIndex)
                                && ((dtcRef == DEM_DTC_REF_INVALID)
                                    || (DemDTCGeneralStatus[dtcRef].SuppressionStatus == TRUE)))
#else
                            if ((dtcRef == DEM_DTC_REF_INVALID)
                                || (DemDTCGeneralStatus[dtcRef].SuppressionStatus == TRUE))
#endif /* DEM_GROUP_OF_DTC_NUM > 0u */
                            {
                                Dem_ResetDemClearDTCInfo();
                                ProcessOn = FALSE;
                            }
                        }
                        if (ProcessOn == TRUE)
#endif /* DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS */
                        {
                            pClr->memDest = Dem_GetInternalMemDest(DTCOrigin);
                            Dem_Pending = TRUE;
                            Dem_ClearDTCProcess();
#if (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_VOLATILE)
                            /*SWS_Dem_00570*/
                            Dem_ResetDemClearDTCInfo();
                            ret = DEM_CLEAR_OK;
#elif (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
                        /*SWS_Dem_00571*/
                        DemClearNonvolatile = TRUE;
                        Dem_ResetDemClearDTCInfo();
                        ret = DEM_CLEAR_OK;
#elif (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_NONVOLATILE_FINISH)
                        DemClearNonvolatile = TRUE;
                        ret = DEM_CLEAR_OK;
                        if (DemClearNonvolatileOK == 0x00u)
                        {
                            /*SWS_Dem_00572*/
                            DemClearNonvolatileOK = 0x02;
                            Dem_ResetDemClearDTCInfo();
                        }
                        else if (DemClearNonvolatileOK == 0x01u)
                        {
                            /*SWS_Dem_01057*/
                            DemClearNonvolatileOK = 0x02;
                            ret = DEM_CLEAR_MEMORY_ERROR;
                        }
                        else
                        {
                            /*SWS_Dem_00663*/
                            ret = DEM_CLEAR_PENDING;
                        }
#endif /* DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_VOLATILE */
                        }
                    }
                }
            }
        }
#if (STD_ON == DEM_DEV_ERROR_DETECT)
        else
        {
            /*idle*/
        }
#endif
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Disables the DTC setting for a DTC group.
 * ServiceId           0x24
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTCGroup:Defines the group of DTC that shall be disabled to
 *                          store in event memory.
 *                       DTCKind:This parameter defines the requested DTC kind, either
 *                          only OBD-relevant DTCs or all DTCs>
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Returns status of the operation>
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)
Dem_DcmDisableDTCSetting(uint32 DTCGroup, Dem_DTCKindType DTCKind) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Dem_ReturnControlDTCSettingType ret;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMDISABLEDTCSETTING, DEM_E_UNINIT);
        ret = DEM_CONTROL_DTC_SETTING_N_OK;
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
#if (DEM_GROUP_OF_DTC_NUM > 0u)
        ret = DEM_CONTROL_DTC_SETTING_OK;
        if (DTCGroup == DEM_DTC_GROUP_ALL_DTCS)
        {
            DemDTCSettingInfo.AllGroupIsEnabled = FALSE;
            Dem_MemSet(DemDTCSettingInfo.DTCGroupStatus, 0x00u, DEM_GROUP_OF_DTC_NUM_BYTE);
        }
        else
        {
            uint8 Group = Dem_GetDTCGroupIndex(DTCGroup);
            if (Group == DEM_GROUP_OF_DTC_INVALID)
            {
                ret = DEM_CONTROL_DTC_WRONG_DTCGROUP;
            }
            else
            {
                DEM_BITS_CLR(DemDTCSettingInfo.DTCGroupStatus, Group);
            }
        }
        if (DEM_CONTROL_DTC_SETTING_OK == ret)
        {
            DemDTCSettingInfo.DTCKind = DTCKind;
            Dem_SetDTCSettingProcess();
        }
#else
#if (STD_ON == DEM_DEV_ERROR_DETECT)
        if (DTCGroup != DEM_DTC_GROUP_ALL_DTCS)
        {
            DEM_DET_REPORT(DEM_SID_DCMDISABLEDTCSETTING, DEM_E_WRONG_CONFIGURATION);
            ret = DEM_CONTROL_DTC_WRONG_DTCGROUP;
        }
        else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
        {
            DemDTCSettingInfo.AllGroupIsEnabled = FALSE;
            DemDTCSettingInfo.DTCKind = DTCKind;
            Dem_SetDTCSettingProcess();
            ret = DEM_CONTROL_DTC_SETTING_OK;
        }
#endif /* DEM_GROUP_OF_DTC_NUM > 0u */
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Enables the DTC setting for a DTC group.
                        This API is intended for the Dcm. It can only be used through the RTE
                        (due to work-around described below SWS_Dem_00035), and therefore
                        no declaration is exported via Dem_Dcm.h.
 * ServiceId           0x25
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTCGroup:Defines the group of DTC that shall be enabled to
 *                          store in event memory.
 *                       DTCKind:This parameter defines the requested DTC kind,
 *                          either only OBD-relevant DTCs or all DTCs
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Returns the status of the operation
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 0624++ */ /* MISRA Rule 8.3 */
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)
Dem_DcmEnableDTCSetting(uint32 DTCGroup, Dem_DTCKindType DTCKind) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
/* PRQA S 0624-- */                                                                 /* MISRA Rule 8.3 */
{
    Dem_ReturnControlDTCSettingType ret;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_DCMENABLEDTCSETTING, DEM_E_UNINIT);
        ret = DEM_CONTROL_DTC_SETTING_N_OK;
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {
#if (DEM_GROUP_OF_DTC_NUM > 0)
        ret = DEM_CONTROL_DTC_SETTING_OK;
        if (DTCGroup == DEM_DTC_GROUP_ALL_DTCS)
        {
            DemDTCSettingInfo.AllGroupIsEnabled = TRUE;
            Dem_MemSet(DemDTCSettingInfo.DTCGroupStatus, 0xFFu, DEM_GROUP_OF_DTC_NUM_BYTE);
        }
        else
        {
            uint8 Group = Dem_GetDTCGroupIndex(DTCGroup);
            if (Group == DEM_GROUP_OF_DTC_INVALID)
            {
                ret = DEM_CONTROL_DTC_WRONG_DTCGROUP;
            }
            else
            {
                DEM_BITS_SET(DemDTCSettingInfo.DTCGroupStatus, Group);
            }
        }
        if (DEM_CONTROL_DTC_SETTING_OK == ret)
        {
            DemDTCSettingInfo.DTCKind = DTCKind;
            Dem_SetDTCSettingProcess();
        }
#else
#if (STD_ON == DEM_DEV_ERROR_DETECT)
        if (DTCGroup != DEM_DTC_GROUP_ALL_DTCS)
        {
            DEM_DET_REPORT(DEM_SID_DCMENABLEDTCSETTING, DEM_E_WRONG_CONFIGURATION);
            ret = DEM_CONTROL_DTC_WRONG_DTCGROUP;
        }
        else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
        {
            DemDTCSettingInfo.AllGroupIsEnabled = TRUE;
            DemDTCSettingInfo.DTCKind = DTCKind;
            Dem_SetDTCSettingProcess();
            ret = DEM_CONTROL_DTC_SETTING_OK;
        }
#endif
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Private Function Definitions                         **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(void, DEM_CODE) Dem_SetDTCSettingProcess(void)
{
    const Dem_EventParameterType* pEventCfg = DemPbCfgPtr->DemEventParameter;
    const Dem_DTCType* pDemDTC = DemPbCfgPtr->DemDTC;
    for (uint16 iloop = 0; iloop < DEM_EVENT_PARAMETER_NUM; iloop++)
    {
        Dem_EventRelateInformationType* pEvent = Dem_GetEventInfo(iloop);
        uint16 DemDTCRef = pEventCfg->DemDTCRef;
        if (DemDTCRef != DEM_DTC_REF_INVALID)
        {
            if ((DemDTCSettingInfo.DTCKind == pDemDTC[DemDTCRef].DTCKind)
                || (DEM_DTC_KIND_ALL_DTCS == DemDTCSettingInfo.DTCKind))
            {
#if (DEM_GROUP_OF_DTC_NUM > 0)
                uint8 GroupRef = pDemDTC[DemDTCRef].GroupRef;
                if (GroupRef != DEM_GROUP_OF_DTC_INVALID)
                {
                    if (0x00u == DEM_BITS_ISSET(DemDTCSettingInfo.DTCGroupStatus, GroupRef))
                    {
                        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING);
                        Dem_DebounceFreeze(iloop); /*SWS_Dem_00678*/
                    }
                    else
                    {
                        if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING))
                        {
                            const Dem_CallbackInitMForEType InitMForE = pEventCfg->DemCallbackInitMForE;
                            DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING);
                            /* req SWS_Dem_00682 Monitor re-initialization  */
                            if (InitMForE != NULL_PTR)
                            {
                                (*InitMForE)(DEM_INIT_MONITOR_REENABLED);
                            }
                        }
                    }
                }
                else
#endif
                {
                    if (DemDTCSettingInfo.AllGroupIsEnabled == FALSE)
                    {
                        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING); /* ControlDTCSetting is disabled*/
                        Dem_DebounceFreeze(iloop);                                   /*SWS_Dem_00678*/
                    }
                    else
                    {
                        if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING))
                        {
                            const Dem_CallbackInitMForEType InitMForE = pEventCfg->DemCallbackInitMForE;
                            DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING);
                            /* req SWS_Dem_00682 Monitor re-initialization  */
                            if (InitMForE != NULL_PTR)
                            {
                                (*InitMForE)(DEM_INIT_MONITOR_REENABLED);
                            }
                        }
                    }
                }
            }
        }
        pEventCfg++;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               BRIEF DESCRIPTION
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant/Non Reentrant
 * Param-Name[in]      IntId && DTCFormat
 * Param-Name[out]     DTC
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetEventDTC(uint16 DTCRef, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, DEM_VAR) DTC)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint16 DemObdDTCRef;
    const Dem_DTCType* pDemDTC = DemPbCfgPtr->DemDTC;
    const DemObdDTCType* pDemObdDTC = DemPbCfgPtr->DemObdDTC;
    uint32 DemDtcValue;
    *DTC = 0x00UL;
    if (DTCRef != DEM_DTC_REF_INVALID)
    {
        switch (DTCFormat)
        {
        case DEM_DTC_FORMAT_UDS:
            DemDtcValue = pDemDTC[DTCRef].DemDtcValue;
            if ((DemDtcValue != DEM_DTC_CFG_INVALID))
            {
                *DTC = DemDtcValue;
            }
            break;
        case DEM_DTC_FORMAT_J1939:
            DemObdDTCRef = pDemDTC[DTCRef].DemObdDTCRef;
            if ((DemObdDTCRef != DEM_OBD_DTC_INVALID)
                && (pDemObdDTC[DemObdDTCRef].DemJ1939DTCValue != DEM_J1939_DTC_CFG_INVALID))
            {
                *DTC = pDemObdDTC[DemObdDTCRef].DemJ1939DTCValue;
            }
            break;
        case DEM_DTC_FORMAT_OBD:
            DemObdDTCRef = pDemDTC[DTCRef].DemObdDTCRef;
            if ((DemObdDTCRef != DEM_OBD_DTC_INVALID)
                && (pDemObdDTC[DemObdDTCRef].DemDtcValue != DEM_OBD_DTC_CFG_INVALID))
            {
                *DTC = (uint32)pDemObdDTC[DemObdDTCRef].DemDtcValue;
            }
            break;
        default:
            /*idle*/
            break;
        }
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_CheckEventInternalMemDest
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTCOrigin
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              uint8
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(uint8, DEM_CODE) Dem_CheckEventInternalMemDest(Dem_DTCOriginType DTCOrigin, uint16 IntId)
{
    uint8 ret = DEM_MEM_DEST_INVALID;
    const Dem_DTCAttributesType* pDTCAttrCfg = Dem_EventDTCAttributesCfg(IntId);
    const uint8* pRef = pDTCAttrCfg->DemMemoryDestinationRef;
    for (uint8 iloop = 0; iloop < DEM_MEM_DEST_TOTAL_NUM; iloop++)
    {
        if (pRef[iloop] == DTCOrigin)
        {
            ret = iloop;
            break;
        }
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_CheckDTCFormat
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTCOrigin
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              uint8
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_LOCAL FUNC(boolean, DEM_CODE) Dem_CheckDTCFormat(uint8 dtcFormat, uint16 dtcRef)
{
    boolean ret = FALSE;
    const Dem_DTCType* pDemDTC = DemPbCfgPtr->DemDTC;
    const DemObdDTCType* pDemObdDTC = DemPbCfgPtr->DemObdDTC;
    uint16 obdDtcRef = pDemDTC[dtcRef].DemObdDTCRef;

    if ((DEM_DTC_FORMAT_UDS == dtcFormat) && (dtcRef != DEM_DTC_REF_INVALID)
        && (pDemDTC[dtcRef].DemDtcValue != DEM_DTC_CFG_INVALID))
    {
        ret = TRUE;
    }
    else if (
        (DEM_DTC_FORMAT_OBD == dtcFormat)
        && ((dtcRef != DEM_DTC_REF_INVALID) && (obdDtcRef != DEM_OBD_DTC_INVALID)
            && (pDemObdDTC[obdDtcRef].DemDtcValue != DEM_OBD_DTC_CFG_INVALID)))
    {
        ret = TRUE;
    }
    else if (
        (DEM_DTC_FORMAT_J1939 == dtcFormat)
        && ((dtcRef != DEM_DTC_REF_INVALID) && (obdDtcRef != DEM_OBD_DTC_INVALID)
            && (pDemObdDTC[obdDtcRef].DemJ1939DTCValue != DEM_J1939_DTC_CFG_INVALID)))
    {
        ret = TRUE;
    }
    else
    {
        /* idle */
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
