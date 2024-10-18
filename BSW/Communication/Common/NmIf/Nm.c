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
**  FILENAME    : Nm.c                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    2020-08-11  lili.wang    R19_11 initial version.
 *  V2.0.1    2020-10-19  lili.wang    QAC check,code update
 *  V2.0.2    2020-12-11  lili.wang    cantata check,code update
 *  V2.0.3    2021-03-12  lili.wang    NmUnitTest bug update
 *  V2.0.4    2021-04-25  lili.wang
 *      1.Integration test modification.
 *  V2.0.5    2021-08-05  lili.wang
 *      1.Nm coordinate redundant calls Nm_BusNmNetworkRelease when the network is released.
 *  V2.0.6    2021-08-010  lili.wang
 *      1.Nm coordinate bug modify,clear coorRSB when BusNm call Nm_BusSleepMode function.
 *      2.Nm_CoorShutdownReady judge network ready to sleep condition modify
 * V2.0.7    2022-04-24  darren.zhang
 *      1.Adjust the header file inclusion order
 * V2.0.8     2023-01-12  shengnan.sun
 *      1.NmPassiveModeEnabled is set to TRUE,it shall raise the error NM_E_INVALID_CHANNEL.
 * V2.0.9     2023-02-21  shengnan.sun
 *      1.Modify Nm_LocalCfgPtr section
 * V2.0.10    2023-03-28  darren.zhang
 *      1.coordinator call busnm sync logic modify
 * V2.0.11    2023-10-26  xiaojian.liang
 *      1. Let API Nm_GetPduData, Nm_RepeatMessageRequest, Nm_GetNodeIdentifier and Nm_GetLocalNodeIdentifier always
 *         compiled.
 * V2.0.12    2023-11-20  xiaojian.liang
 *      1. CPD-33590 Performance optimization.
 */

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:Nm<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 1531, 1532, 1533 MISRA Rule 8.7, 8.9.<br>
    Reason:The exception is global configuration data(1531, 1533) and API(1532).
*/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define NM_C_AR_RELEASE_MAJOR_VERSION 4u
#define NM_C_AR_RELEASE_MINOR_VERSION 5u
#define NM_C_AR_RELEASE_PATCH_VERSION 0u
#define NM_C_SW_MAJOR_VERSION         2u
#define NM_C_SW_MINOR_VERSION         0u
#define NM_C_SW_PATCH_VERSION         12u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm.h"
#include "Nm_Internal.h"
#include "SchM_Nm.h"
#include "ComM_Nm.h"
#if (STD_ON == NM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#if (STD_ON == NM_STATE_CHANGE_IND_ENABLED)
#include "Com.h"
#endif /* #if (STD_ON == NM_STATE_CHANGE_IND_ENABLED)*/
#include "Nm_Cbk.h"

#ifdef GEELY20_SPECIFICATION_USED
#include "NmHistoryState.h"
#endif
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (NM_C_AR_RELEASE_MAJOR_VERSION != NM_H_AR_RELEASE_MAJOR_VERSION)
#error "Nm.c : Mismatch in Specification Major Version"
#endif
#if (NM_C_AR_RELEASE_MINOR_VERSION != NM_H_AR_RELEASE_MINOR_VERSION)
#error "Nm.c : Mismatch in Specification _MINOR Version"
#endif
#if (NM_C_AR_RELEASE_PATCH_VERSION != NM_H_AR_RELEASE_PATCH_VERSION)
#error "Nm.c : Mismatch in Specification PATCH Version"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/* nm upper layer NetworkHandleType data link nm channel index */
#define NM_START_SEC_CODE
#include "Nm_MemMap.h"
static FUNC(boolean, NM_CODE) Nm_FindChannelIndex(NetworkHandleType NetworkHandle, uint8* chIndexPtr);

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/* find nm local map to cluster index */
static FUNC(Std_ReturnType, NM_CODE) Nm_FindClusterIndex(
    uint8 chIndex,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) clusterIndexPtr
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
);

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
static FUNC(void, NM_CODE) Nm_CoorReadySleepBitHandle(
    P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr,
    boolean ReqCSRBitFlag);
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT*/

static FUNC(boolean, NM_CODE)
    Nm_CoorShutdownReady(P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr);

/* coordinator shutdown timer load default value */
static FUNC(Std_ReturnType, NM_CODE)
    Nm_CoorShutdownTimerLoader(P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr);

/* coordinator shutdown timer handle function */
static FUNC(Std_ReturnType, NM_CODE) Nm_CoorShutDownTimerHandle(
    P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, NM_APPL_DATA) sleepAllowPtr
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
);

/* coordinator shutdown abort handle function */
static FUNC(void, NM_CODE)
    Nm_CoorShutdownAbortHandle(P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr);
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#if ((STD_OFF == NM_PASSIVE_MODE_ENABLED) && (0u < NM_NUMBER_OF_CHANNELS))
/* special bus nm network request */
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmNetworkRequest(uint8 chIndex);

/* special bus network release */
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmNetworkRelease(uint8 chIndex);
#endif /* (STD_OFF == NM_PASSIVE_MODE_ENABLED)&& \
    (0u < NM_NUMBER_OF_CHANNELS) */

#if ((STD_ON == NM_COORDINATOR_SUPPORT_ENABLED) && (STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED))
/* special bus nm request sync */
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmRequestBusSynchronization(uint8 chIndex);
#endif /* (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)&& \
 (STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED) */

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
/* special bus nm set coordinator ready sleep bit */
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmSetSleepReadyBit(uint8 chIndex, boolean nmSleepReadyBit);
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT */

#define NM_STOP_SEC_CODE
#include "Nm_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*Module initialize status, TRUE initialized, FALSE not initialized*/
#define NM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Nm_MemMap.h"
static VAR(boolean, NM_VAR_CLEARED_BOOLEAN) Nm_InitStatus = FALSE;
#define NM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Nm_MemMap.h"

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
#if (0u < NM_NUMBER_OF_CHANNELS)
/* per nm channel have a struct verial ro management status */
#define NM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Nm_MemMap.h"
static VAR(Nm_InnerChannelType, NM_VAR_NO_INIT_UNSPECIFIED) Nm_InnerChannel[NM_NUMBER_OF_CHANNELS];
#define NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Nm_MemMap.h"
#endif /* 0u < NM_NUMBER_OF_CHANNELS */

#if (0u < NM_NUMBER_OF_CLUSTERS)
/* per nm cluster have a struct verial ro management status */
#define NM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Nm_MemMap.h"
static VAR(Nm_InnerClusterType, NM_VAR_NO_INIT_UNSPECIFIED) Nm_InnerCluster[NM_NUMBER_OF_CLUSTERS];
#define NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Nm_MemMap.h"
#endif /* 0u < NM_NUMBER_OF_CLUSTERS */

/* store nm post build configuration data pointer */
#define NM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Nm_MemMap.h"
static P2CONST(Nm_ConfigType, NM_CONST, NM_APPL_DATA) Nm_LocalCfgPtr = NULL_PTR;
#define NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Nm_MemMap.h"

#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               Initializes the NM Interface.
 * ServiceId           0x00
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr, Pointer to the selected configuration set.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#define NM_START_SEC_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_Init(P2CONST(Nm_ConfigType, AUTOMATIC, NM_APPL_DATA) ConfigPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
/* @SWS_Nm_00127
this Service Function to be call after the Initializes of
respective bus Interface */
/* @SWS_Nm_00283
ConfigPtr always have NULL_PTR value */
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
#if (STD_ON == NM_DEV_ERROR_DETECT)
    if ((NULL_PTR == ConfigPtr) || ((0u < ConfigPtr->numOfClu) && (NULL_PTR == ConfigPtr->perCluPtr)))
    {
        NM_DET_REPORT(NM_SERVICE_ID_INIT, NM_E_PARAM_POINTER);
    }
    else if (ConfigPtr->numOfClu > NM_NUMBER_OF_CLUSTERS)
    {
        NM_DET_REPORT(NM_SERVICE_ID_INIT, NM_E_INVALID_CHANNEL);
    }
    else
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    {
        Nm_LocalCfgPtr = ConfigPtr;
        uintx index;
#if (0u < NM_NUMBER_OF_CHANNELS)
        for (index = 0u; index < NM_NUMBER_OF_CHANNELS; index++)
        {
            Nm_InnerChannel[index].remoteSleepIndFlg = FALSE;
            Nm_InnerChannel[index].busAwakeFlg = FALSE;
            Nm_InnerChannel[index].lowLayNetRequest = FALSE;
            Nm_InnerChannel[index].upLayNetRequest = FALSE;
            Nm_InnerChannel[index].allowShutdown = FALSE;
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
            Nm_InnerChannel[index].coorRSB = FALSE;
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
            Nm_InnerChannel[index].lowLayBusSyncPoint = FALSE;
            Nm_InnerChannel[index].shutdownTimer = 0u;
        }
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
#if (0u < NM_NUMBER_OF_CLUSTERS)
        for (index = 0u; index < NM_NUMBER_OF_CLUSTERS; index++)
        {
            Nm_InnerCluster[index].shutdownStatus = NM_SHUTDOWN_STU_INIT;
        }
#endif /* 0u < NM_NUMBER_OF_CLUSTERS */
        Nm_InitStatus = TRUE;
    }
#else
    (void)ConfigPtr;
    Nm_InitStatus = TRUE;
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
}

/******************************************************************************/
/*
 * Brief               This function calls the <BusNm>_PassiveStartUp function
 * ServiceId           0x01
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Passive startup of network management has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_PassiveStartUp(NetworkHandleType NetworkHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
    /* @SWS_Nm_00128
    Check initialized correctly */
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(NetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            /*  @SWS_Nm_00245
             if this network is part of a coordinator cluster,shall translate
             nm_networkRequest */
            uint8 clusterIndex = 0x0u;
            if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
            {
                ret = Nm_NetworkRequest(NetworkHandle);
            }
            else
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
            {

                if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
                {
                    BusNm_PassiveStartUp_Type specific_PassiveStartUp =
                        Nm_ChLConfig[chIndex].busNmApi->BusNm_PassiveStartUp;
                    if (NULL_PTR != specific_PassiveStartUp)
                    {
                        ret = specific_PassiveStartUp(NetworkHandle);
                    }
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_PASSIVESTARTUP, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_PASSIVESTARTUP, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    return ret;
}

/******************************************************************************/
/*
 * Brief               This function calls the <BusNm>_NetworkRequest function
 * ServiceId           0x02
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Requesting of bus communication has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_NetworkRequest(NetworkHandleType NetworkHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
/*@req SWS_Nm_00130*/
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
    /* @SWS_Nm_00129
    Check initialized correctly */
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(NetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            if (0xff != Nm_ChLConfig[chIndex].NmCoordClusterIndex)
            {
                SchM_Enter_Nm_MsgContext();
                Nm_InnerChannel[chIndex].upLayNetRequest = TRUE;
                Nm_InnerChannel[chIndex].allowShutdown = FALSE;
                SchM_Exit_Nm_MsgContext();
#if (0u < NM_NUMBER_OF_CLUSTERS)
                uint8 clusterIndex = 0x0u;
                if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
                {
                    SchM_Enter_Nm_MsgContext();
                    if ((NM_SHUTDOWN_STU_RUN == Nm_InnerCluster[clusterIndex].shutdownStatus)
                        || (NM_SHUTDOWN_STU_ABORT == Nm_InnerCluster[clusterIndex].shutdownStatus))
                    {
                        Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_ABORT;
                    }
                    else
                    {
                        Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_START;
                    }
                    SchM_Exit_Nm_MsgContext();
                }
#endif /* 0u < NM_NUMBER_OF_CLUSTERS */
            }
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
            /*@req SWS_Nm_00483*/
            if (NM_BUSNM_LOCALNM == Nm_ChLConfig[chIndex].busNmType)
            {
                ComM_Nm_NetworkMode(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
                ret = E_OK;
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
                Nm_InnerChannel[chIndex].busAwakeFlg = TRUE;
                Nm_InnerChannel[chIndex].remoteSleepIndFlg = FALSE;
#endif
            }
            else
            {
                ret = Nm_BusNmNetworkRequest(chIndex);
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_NETWORKREQUEST, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_NETWORKREQUEST, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
#else /* STD_OFF != NM_PASSIVE_MODE_ENABLED*/
#if (STD_ON == NM_DEV_ERROR_DETECT)
    NM_DET_REPORT(NM_SERVICE_ID_NETWORKREQUEST, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED*/
    return ret;
}

/******************************************************************************/
/*
 * Brief               This function calls the <BusNm>_NetworkRelease function
 * ServiceId           0x03
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Releasing of bus communication has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_NetworkRelease(NetworkHandleType NetworkHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
    /* @SWS_Nm_00131
    Check initialized correctly */
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(NetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            if (0xff != Nm_ChLConfig[chIndex].NmCoordClusterIndex)
            {
                SchM_Enter_Nm_MsgContext();
                Nm_InnerChannel[chIndex].upLayNetRequest = FALSE;
                SchM_Exit_Nm_MsgContext();
            }
            else
            {
                ret = Nm_BusNmNetworkRelease(chIndex);
            }
            ret = E_OK;
#else
            ret = Nm_BusNmNetworkRelease(chIndex);
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_NETWORKRELEASE, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_NETWORKRELEASE, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
#else /* STD_OFF != NM_PASSIVE_MODE_ENABLED*/
#if (STD_ON == NM_DEV_ERROR_DETECT)
    NM_DET_REPORT(NM_SERVICE_ID_NETWORKRELEASE, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED */
    return ret;
}

/* @SWS_Nm_00134 */
#if (STD_ON == NM_COM_CONTROL_ENABLED)
/******************************************************************************/
/*
 * Brief               disables the NM PDU transmission ability.
 * ServiceId           0x04
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Disabling of NM PDU transmission ability has
 *                     failed.
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_DisableCommunication(NetworkHandleType NetworkHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
    /* @SWS_Nm_00133
    Check initialized correctly */
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(NetworkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_DisableCommunication_Type specific_DisableCommunication =
                    Nm_ChLConfig[chIndex].busNmApi->BusNm_DisableCommunication;
                if (NULL_PTR != specific_DisableCommunication)
                {
                    ret = specific_DisableCommunication(NetworkHandle);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_DISABLECOMMUNICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_DISABLECOMMUNICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
#else /* STD_OFF != NM_PASSIVE_MODE_ENABLED*/
#if (STD_ON == NM_DEV_ERROR_DETECT)
    NM_DET_REPORT(NM_SERVICE_ID_DISABLECOMMUNICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED */
    return ret;
}
#endif /* STD_ON == NM_COM_CONTROL_ENABLED */

/* @SWS_Nm_00136 */
#if (STD_ON == NM_COM_CONTROL_ENABLED)
/******************************************************************************/
/*
 * Brief               Enables the NM PDU transmission ability.
 * ServiceId           0x05
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Enabling of NM PDU transmission ability has
 *                     failed.
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_EnableCommunication(NetworkHandleType NetworkHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
    /* @SWS_Nm_00135
    Check initialized correctly */
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(NetworkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_EnableCommunication_Type specific_EnableCommunication =
                    Nm_ChLConfig[chIndex].busNmApi->BusNm_EnableCommunication;
                if (NULL_PTR != specific_EnableCommunication)
                {
                    ret = specific_EnableCommunication(NetworkHandle);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_ENABLECOMMUNICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_ENABLECOMMUNICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
#else /* STD_OFF != NM_PASSIVE_MODE_ENABLED*/
#if (STD_ON == NM_DEV_ERROR_DETECT)
    NM_DET_REPORT(NM_SERVICE_ID_ENABLECOMMUNICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED */
    return ret;
}
#endif /* STD_ON ==  NM_COM_CONTROL_ENABLED */

/* @SWS_Nm_00138,@SWS_Nm_00241 */
#if ((STD_OFF == NM_COM_USER_DATA_SUPPORT) && (STD_ON == NM_USER_DATA_ENABLED))
/******************************************************************************/
/*
 * Brief               Set user data for NM messages transmitted next on the bus.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 *                     nmUserDataPtr,User data for the next transmitted NM message
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Setting of user data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_SetUserData(NetworkHandleType NetworkHandle, P2CONST(uint8, AUTOMATIC, NM_APPL_DATA) nmUserDataPtr)
{
    Std_ReturnType ret = E_NOT_OK;
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)

    if (NULL_PTR == nmUserDataPtr)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_SETUSERDATA, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if (TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if (TRUE == Nm_FindChannelIndex(NetworkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_SetUserData_Type specific_SetUserData = Nm_ChLConfig[chIndex].busNmApi->BusNm_SetUserData;
                if (NULL_PTR != specific_SetUserData)
                {
                    ret = specific_SetUserData(NetworkHandle, nmUserDataPtr);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_SETUSERDATA, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_SETUSERDATA, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
#else /* STD_OFF != NM_PASSIVE_MODE_ENABLED*/
#if (STD_ON == NM_DEV_ERROR_DETECT)
    NM_DET_REPORT(NM_SERVICE_ID_SETUSERDATA, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED */
    return ret;
}
#endif /* ((STD_OFF == NM_COM_USER_DATA_SUPPORT)&& \
     (STD_ON == NM_USER_DATA_ENABLED)) */

/* @SWS_Nm_00140 */
#if (STD_ON == NM_USER_DATA_ENABLED)
/******************************************************************************/
/*
 * Brief               Get user data out of the last successfully received NM message
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmUserDataPtr,User data for the next transmitted NM message
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Getting of user data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_GetUserData(NetworkHandleType NetworkHandle, uint8* nmUserDataPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    /* @SWS_Nm_00139
    Check initialized correctly */
    if (NULL_PTR == nmUserDataPtr)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETUSERDATA, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(NetworkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_GetUserData_Type specific_GetUserData = Nm_ChLConfig[chIndex].busNmApi->BusNm_GetUserData;
                if (NULL_PTR != specific_GetUserData)
                {
                    ret = specific_GetUserData(NetworkHandle, nmUserDataPtr);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_GETUSERDATA, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETUSERDATA, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    return ret;
}
#endif /* STD_ON == NM_USER_DATA_ENABLED */

Std_ReturnType Nm_GetPduData(NetworkHandleType networkHandle, uint8* nmPduData)
{
    Std_ReturnType ret = E_NOT_OK;
    /* @SWS_Nm_00141
    Check initialized correctly */
    if (NULL_PTR == nmPduData)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETPDUDATA, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(networkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_GetPduData_Type specific_GetPduData = Nm_ChLConfig[chIndex].busNmApi->BusNm_GetPduData;
                if (NULL_PTR != specific_GetPduData)
                {
                    ret = specific_GetPduData(networkHandle, nmPduData);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_GETPDUDATA, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETPDUDATA, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    return ret;
}

Std_ReturnType Nm_RepeatMessageRequest(NetworkHandleType networkHandle)
{
    Std_ReturnType ret = E_NOT_OK;
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
    /* @SWS_Nm_00143
    Check initialized correctly */
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(networkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_RepeatMessageRequest_Type specific_RepeatMessageRequest =
                    Nm_ChLConfig[chIndex].busNmApi->BusNm_RepeatMessageRequest;
                if (NULL_PTR != specific_RepeatMessageRequest)
                {
                    ret = specific_RepeatMessageRequest(networkHandle);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_REPEATMESSAGEREQUEST, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_REPEATMESSAGEREQUEST, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
#else /* STD_OFF != NM_PASSIVE_MODE_ENABLED*/
#if (STD_ON == NM_DEV_ERROR_DETECT)
    NM_DET_REPORT(NM_SERVICE_ID_REPEATMESSAGEREQUEST, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED */
    return ret;
}

Std_ReturnType Nm_GetNodeIdentifier(NetworkHandleType networkHandle, uint8* nmNodeIdPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    /* @SWS_Nm_00145
    Check initialized correctly */
    if (NULL_PTR == nmNodeIdPtr)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETNODEIDENTIFIER, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(networkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_GetNodeIdentifier_Type specific_GetNodeIdentifier =
                    Nm_ChLConfig[chIndex].busNmApi->BusNm_GetNodeIdentifier;
                if (NULL_PTR != specific_GetNodeIdentifier)
                {
                    ret = specific_GetNodeIdentifier(networkHandle, nmNodeIdPtr);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_GETNODEIDENTIFIER, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETNODEIDENTIFIER, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    return ret;
}

Std_ReturnType Nm_GetLocalNodeIdentifier(NetworkHandleType networkHandle, uint8* nmNodeIdPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    /* @SWS_Nm_00147
    Check initialized correctly */
    if (NULL_PTR == nmNodeIdPtr)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETLOCALNODEIDENTIFIER, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(networkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_GetLocalNodeIdentifier_Type specific_GetLocalNodeIdentifier =
                    Nm_ChLConfig[chIndex].busNmApi->BusNm_GetLocalNodeIdentifier;
                if (NULL_PTR != specific_GetLocalNodeIdentifier)
                {
                    ret = specific_GetLocalNodeIdentifier(networkHandle, nmNodeIdPtr);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_GETLOCALNODEIDENTIFIER, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETLOCALNODEIDENTIFIER, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    return ret;
}

/* SWS_Nm_00150 */
#if (STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Check if remote sleep indication takes place or not
 * ServiceId           0x0d
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmRemoteSleepIndPtr,Pointer where check result of remote
 *                     sleep indication shall be copied to
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Checking of remote sleep indication bits has
 *                     failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_CheckRemoteSleepIndication(
    NetworkHandleType nmNetworkHandle,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, NM_APPL_DATA) nmRemoteSleepIndPtr
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
)
{
    Std_ReturnType ret = E_NOT_OK;
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
    /* @SWS_Nm_00149
    Check initialized correctly */
    if (NULL_PTR == nmRemoteSleepIndPtr)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_CheckRemoteSleepIndType spf_CheckRemoteSleepIndication =
                    Nm_ChLConfig[chIndex].busNmApi->BusNm_CheckRemoteSleepInd;
                if (NULL_PTR != spf_CheckRemoteSleepIndication)
                {
                    ret = spf_CheckRemoteSleepIndication(nmNetworkHandle, nmRemoteSleepIndPtr);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
#else /* STD_OFF != NM_PASSIVE_MODE_ENABLED*/
#if (STD_ON == NM_DEV_ERROR_DETECT)
    NM_DET_REPORT(NM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED */
    return ret;
}
#endif /* STD_ON == NM_REMOTE_SLEEP_IND_ENABLED */

/******************************************************************************/
/*
 * Brief               Check if remote sleep indication takes place or not
 * ServiceId           0x0e
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmStatePtr,Pointer where state of the network management
 *                     shall be copied to
 *                     nmModePtr,Pointer to the location where the mode of the
 *                     network management shall be copied to
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Getting of NM state has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_GetState(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr)
{
    Std_ReturnType ret = E_NOT_OK;
    /* @SWS_Nm_00151
    Check initialized correctly */
    if (NULL_PTR == nmStatePtr)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETSTATE, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == nmModePtr)
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETSTATE, NM_E_PARAM_POINTER);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    else if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
            if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
            {
                BusNm_GetState_Type specific_GetState = Nm_ChLConfig[chIndex].busNmApi->BusNm_GetState;
                if (NULL_PTR != specific_GetState)
                {
                    ret = specific_GetState(nmNetworkHandle, nmStatePtr, nmModePtr);
                }
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_GETSTATE, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_GETSTATE, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
    return ret;
}

#if (STD_ON == NM_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service returns the version information of this module.
 * ServiceId           0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      NA
 * Param-Name[out]     nmVerInfoPtr,Pointer to where to store the version information
 *                     of this module.
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_GetVersionInfo(Std_VersionInfoType* nmVerInfoPtr)
{
#if (STD_ON == NM_DEV_ERROR_DETECT)
    if (NULL_PTR == nmVerInfoPtr)
    {
        NM_DET_REPORT(NM_SERVICE_ID_GETVERSIONINFO, NM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    {
        nmVerInfoPtr->moduleID = NM_MODULE_ID;
        nmVerInfoPtr->vendorID = NM_VENDOR_ID;
        nmVerInfoPtr->sw_major_version = NM_C_SW_MAJOR_VERSION;
        nmVerInfoPtr->sw_minor_version = NM_C_SW_MINOR_VERSION;
        nmVerInfoPtr->sw_patch_version = NM_C_SW_PATCH_VERSION;
    }
}
#endif /* STD_ON == NM_VERSION_INFO_API */
#define NM_STOP_SEC_CODE
#include "Nm_MemMap.h"

/******************************************************************************/
/*
 * Brief               Notification that a NM-message has been received in the
 *                     Bus-Sleep Mode, what indicates that some nodes in the
 *                     network have already entered the Network Mode.
 * ServiceId           0x11
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_NetworkStartIndication(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
            /* @SWS_Nm_00155 */
            ComM_Nm_NetworkStartIndication(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_NETWORKSTARTINDICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_NETWORKSTARTINDICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"

/******************************************************************************/
/*
 * Brief               Notification that the network management has entered Network Mode.
 * ServiceId           0x12
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[in/out]  NA
 * Param-Name[out]     NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_NETWORKMODE_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_NetworkMode(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            Nm_InnerChannel[chIndex].busAwakeFlg = TRUE;
            Nm_InnerChannel[chIndex].remoteSleepIndFlg = FALSE;
#if (0u < NM_NUMBER_OF_CLUSTERS)
            uint8 clusterIndex = 0x0u;
            if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
            {
                if ((NM_SHUTDOWN_STU_RUN == Nm_InnerCluster[clusterIndex].shutdownStatus)
                    || (NM_SHUTDOWN_STU_ABORT == Nm_InnerCluster[clusterIndex].shutdownStatus))
                {
                    Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_ABORT;
                }
                else
                {
                    Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_START;
                }
            }
#endif /* 0u < NM_NUMBER_OF_CLUSTERS */
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
            /* @SWS_Nm_00158 */
            ComM_Nm_NetworkMode(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_NETWORKMODE, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_NETWORKMODE, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_NETWORKMODE_CALLBACK_CODE
#include "Nm_MemMap.h"

/******************************************************************************/
/*
 * Brief               Notification that the network management has entered Bus-Sleep
 *                     Mode.
 * ServiceId           0x14
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_BusSleepMode(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            /* clear All inner varilable */
            Nm_InnerChannel[chIndex].lowLayBusSyncPoint = FALSE;
            Nm_InnerChannel[chIndex].busAwakeFlg = FALSE;
            Nm_InnerChannel[chIndex].remoteSleepIndFlg = FALSE;

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
            Nm_InnerChannel[chIndex].coorRSB = FALSE;
#endif

/*@SWS_Nm_00293*/
#if (0u < NM_NUMBER_OF_CLUSTERS)
            uint8 clusterIndex = 0x0u;
            if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
            {
                if ((NM_SHUTDOWN_STU_START == Nm_InnerCluster[clusterIndex].shutdownStatus)
                    && (FALSE == Nm_InnerChannel[chIndex].upLayNetRequest))
                {
                    Nm_InnerChannel[chIndex].upLayNetRequest = FALSE;
                    Nm_BusNmNetworkRelease(chIndex);
                }
            }
#endif /*(0u < NM_NUMBER_OF_CLUSTERS)*/
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
            /* @SWS_Nm_00163 */
            ComM_Nm_BusSleepMode(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_BUSSLEEPMODE, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_BUSSLEEPMODE, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"

/******************************************************************************/
/*
 * Brief               Notification that the network management has entered Prepare
 *                     Bus-Sleep Mode.
 * ServiceId           0x13
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_PrepareBusSleepMode(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            Nm_InnerChannel[chIndex].lowLayBusSyncPoint = FALSE;
            Nm_InnerChannel[chIndex].remoteSleepIndFlg = FALSE;

/*@SWS_Nm_00293*/
#if (0u < NM_NUMBER_OF_CLUSTERS)
            uint8 clusterIndex = 0x0u;
            if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
            {
                if ((NM_SHUTDOWN_STU_START == Nm_InnerCluster[clusterIndex].shutdownStatus)
                    && (FALSE == Nm_InnerChannel[chIndex].upLayNetRequest))
                {
                    Nm_InnerChannel[chIndex].upLayNetRequest = FALSE;
                    Nm_BusNmNetworkRelease(chIndex);
                }
            }
#endif /*(0u < NM_NUMBER_OF_CLUSTERS)*/
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
            /* @SWS_Nm_00161 */
            ComM_Nm_PrepareBusSleepMode(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_PREPAREBUSSLEEPMODE, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_PREPAREBUSSLEEPMODE, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"

#if (STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Notification that the network management has detected that
 *                     all other nodes on the network are ready to enter Bus-Sleep
 *                     Mode.
 * ServiceId           0x17
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_RemoteSleepIndication(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            Nm_InnerChannel[chIndex].remoteSleepIndFlg = TRUE;
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_REMOTESLEEPINDICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_REMOTESLEEPINDICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif /* STD_ON ==  NM_REMOTE_SLEEP_IND_ENABLED */

#if (STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Notification that the network management has detected that
 *                     not all other nodes on the network are longer ready to enter
 *                     Bus-Sleep Mode
 * ServiceId           0x18
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_RemoteSleepCancellation(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            Nm_InnerChannel[chIndex].remoteSleepIndFlg = FALSE;
#if (0u < NM_NUMBER_OF_CLUSTERS)
            if ((boolean)FALSE == Nm_ChLConfig[chIndex].NmChannelSleepMaster)
            {
                uint8 clusterIndex = 0x0u;
                if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
                {
                    if ((NM_SHUTDOWN_STU_RUN == Nm_InnerCluster[clusterIndex].shutdownStatus)
                        || (NM_SHUTDOWN_STU_ABORT == Nm_InnerCluster[clusterIndex].shutdownStatus))
                    {
                        Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_ABORT;
                    }
                    else
                    {
                        Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_START;
                    }
                }
            }
#endif /* 0u < NM_NUMBER_OF_CLUSTERS */
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_REMOTESLEEPCANCELLATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_REMOTESLEEPCANCELLATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"

/******************************************************************************/
/*
 * Brief               Notification to the NM Coordinator functionality that this
 *                     is a suitable point in time to initiate the coordinated
 *                     shutdown on
 * ServiceId           0x19
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_SynchronizationPoint(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            if ((boolean)TRUE == Nm_ChLConfig[chIndex].NmSynchronizingNetwork)
            {
                /* avoid user config NmChannelSleepMaster and
                NmSynchronizingNetwork is common channel,
                although this not correct
                simple line
                Nm_InnerChannel[chIndex].lowLayBusSyncPoint =
                        Nm_InnerChannel[chIndex].remoteSleepInd;
                */
                if ((boolean)FALSE == Nm_ChLConfig[chIndex].NmChannelSleepMaster)
                {
                    Nm_InnerChannel[chIndex].lowLayBusSyncPoint = Nm_InnerChannel[chIndex].remoteSleepIndFlg;
                }
                else
                {
                    if ((boolean)TRUE != Nm_InnerChannel[chIndex].upLayNetRequest)
                    {
                        Nm_InnerChannel[chIndex].lowLayBusSyncPoint = TRUE;
                    }
                    else
                    {
                        Nm_InnerChannel[chIndex].lowLayBusSyncPoint = FALSE;
                    }
                }
            }
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_SYNCHRONIZATIONPOINT, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_SYNCHRONIZATIONPOINT, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif /* STD_ON ==  NM_REMOTE_SLEEP_IND_ENABLED */
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
/******************************************************************************/
/*
 * Brief               Sets an indication, when the NM Coordinator Sleep Ready
 *                     bit in the Control Bit Vector is set
 * ServiceId           0x1e
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_CoordReadyToSleepIndication(NetworkHandleType nmChannelHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmChannelHandle, &chIndex))
        {
            /*recv CSR=1 in passive channel,then set CSR=1 in active channel*/
            if ((boolean)FALSE == Nm_ChLConfig[chIndex].NmActiveCoordinator)
            {
                Nm_InnerChannel[chIndex].coorRSB = TRUE;
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_COORDREADYTOSLEEPINDICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_COORDREADYTOSLEEPINDICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */

/* @SWS_Nm_00273 */
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
/******************************************************************************/
/*
 * Brief               Cancels an indication, when the NM Coordinator Sleep Ready
 *                     bit in the Control Bit Vector is set back to 0
 * ServiceId           0x1f
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_CoordReadyToSleepCancellation(NetworkHandleType nmChannelHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmChannelHandle, &chIndex))
        {
            if ((boolean)FALSE == Nm_ChLConfig[chIndex].NmActiveCoordinator)
            {
                Nm_InnerChannel[chIndex].coorRSB = FALSE;
#if (0u < NM_NUMBER_OF_CLUSTERS)
                uint8 clusterIndex = 0x0u;
                if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
                {
                    if ((NM_SHUTDOWN_STU_RUN == Nm_InnerCluster[clusterIndex].shutdownStatus)
                        || (NM_SHUTDOWN_STU_ABORT == Nm_InnerCluster[clusterIndex].shutdownStatus))
                    {
                        Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_ABORT;
                    }
                    else
                    {
                        Nm_InnerCluster[clusterIndex].shutdownStatus = NM_SHUTDOWN_STU_START;
                    }
                }
#endif /* 0u < NM_NUMBER_OF_CLUSTERS */
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_COORDREADYTOSLEEPCANCELLATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_COORDREADYTOSLEEPCANCELLATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */

/* SWS_Nm_91002 */
/******************************************************************************/
/**
 * Brief               Notification that the network management has entered
 * Synchronize Mode.
 * ServiceId           0x21
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_SYNCHRONIZEMODE_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_SynchronizeMode(NetworkHandleType nmNetworkHandle)
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
            /* clear All inner varilable */
            Nm_InnerChannel[chIndex].lowLayBusSyncPoint = FALSE;
            Nm_InnerChannel[chIndex].busAwakeFlg = FALSE;
            Nm_InnerChannel[chIndex].remoteSleepIndFlg = FALSE;

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
            Nm_InnerChannel[chIndex].coorRSB = FALSE;
#endif /* (STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT) */

/*@SWS_Nm_00293*/
#if (0u < NM_NUMBER_OF_CLUSTERS)
            uint8 clusterIndex = 0x0u;
            if ((uint8)E_OK == Nm_FindClusterIndex(chIndex, &clusterIndex))
            {
                if ((NM_SHUTDOWN_STU_START == Nm_InnerCluster[clusterIndex].shutdownStatus)
                    && (FALSE == Nm_InnerChannel[chIndex].upLayNetRequest))
                {
                    Nm_InnerChannel[chIndex].upLayNetRequest = FALSE;
                    Nm_BusNmNetworkRelease(chIndex);
                }
            }
#endif /*(0u < NM_NUMBER_OF_CLUSTERS)*/
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_SYNCHRONIZEMODE, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
#else
        (void)nmNetworkHandle;
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_SYNCHRONIZEMODE, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_SYNCHRONIZEMODE_CALLBACK_CODE
#include "Nm_MemMap.h"

#if (STD_ON == NM_PDU_RX_INDICATION_ENABLED)
/******************************************************************************/
/*
 * Brief               Notification that a NM message has been received.
 * ServiceId           0x15
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_PDURXINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_PduRxIndication(NetworkHandleType nmNetworkHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    (void)nmNetworkHandle;
}
#define NM_STOP_SEC_NM_PDURXINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif /* STD_ON ==  NM_PDU_RX_INDICATION_ENABLED */

/* @SWS_Nm_00165 */
#if (STD_ON == NM_STATE_CHANGE_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Notification that a NM message has been received.
 * ServiceId           0x16
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 *                     nmPreviousState,Previous state of the NM-channel
 *                     nmCurrentState,Current (new) state of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(void, NM_CODE)
Nm_StateChangeNotification(NetworkHandleType nmNetworkHandle, Nm_StateType nmPreviousState, Nm_StateType nmCurrentState)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmNetworkHandle, &chIndex))
        {
#ifdef GEELY20_SPECIFICATION_USED
	        if(NM_STATE_BUS_SLEEP==nmCurrentState)
	        {
	            NmHistoryState_NodifyState(NHS_STATE_BUSSLEEPMODE);
	        }
	        else if(NM_STATE_PREPARE_BUS_SLEEP == nmCurrentState)
	        {
	            NmHistoryState_NodifyState(NHS_STATE_PREPAREBUSSLEEPMODE);
	        }
	        else if(NM_STATE_READY_SLEEP == nmCurrentState)
	        {
	            NmHistoryState_NodifyState(NHS_STATE_READYSLEEPSTATE);
	        }
	        else if(NM_STATE_NORMAL_OPERATION == nmCurrentState)
	        {
	            NmHistoryState_NodifyState(NHS_STATE_NORMALOPERATIONTATE);
	        }
	        else if(NM_STATE_REPEAT_MESSAGE == nmCurrentState)
	        {
	            NmHistoryState_NodifyState(NHS_STATE_REPEATMESSAGESTATE);
	        }
	        else if(NHS_STATE_BUSOFF_REC_LEVEL1 == nmCurrentState)
	        {
				NmHistoryState_NodifyState(NHS_STATE_BUSOFF_REC_LEVEL1);
	        }
			else if(NHS_STATE_BUSOFF_REC_LEVEL2 == nmCurrentState)
	        {
				NmHistoryState_NodifyState(NHS_STATE_BUSOFF_REC_LEVEL2);
	        }
			else
	        {
	            /* code */
	        }

#endif
            /* @SWS_Nm_00249
            state change Notification to comM */
            if ((boolean)TRUE == Nm_ChLConfig[chIndex].NmStateReportEnabled)
            {
#if (STD_ON == NM_SUPPORT_COM_SENDSIGNAL)
                /* NMS shall to set to signal value according to
                the followling table */
                const Nm_StateReportKindType Nm_StateReportKind[6] = {
                    {NM_STATE_BUS_SLEEP, NM_STATE_REPEAT_MESSAGE, 0x01u},
                    {NM_STATE_PREPARE_BUS_SLEEP, NM_STATE_REPEAT_MESSAGE, 0x02u},
                    {NM_STATE_REPEAT_MESSAGE, NM_STATE_NORMAL_OPERATION, 0x04u},
                    {NM_STATE_READY_SLEEP, NM_STATE_NORMAL_OPERATION, 0x08u},
                    {NM_STATE_READY_SLEEP, NM_STATE_REPEAT_MESSAGE, 0x10u},
                    {NM_STATE_NORMAL_OPERATION, NM_STATE_REPEAT_MESSAGE, 0x20u},
                };
                uintx index;
                boolean findflag = FALSE;
                for (index = 0u; (index < NM_UBOND(Nm_StateReportKind)) && ((boolean)FALSE == findflag); index++)
                {
                    if ((nmCurrentState == Nm_StateReportKind[index].nmCurSta)
                        && (nmPreviousState == Nm_StateReportKind[index].nmPreSta))
                    {
                        findflag = TRUE;
                    }
                }
                if ((boolean)TRUE == findflag)
                {
                    index--;
                    (void)Com_SendSignal(
                        Nm_ChLConfig[chIndex].NmStateReportSignalRef.sigId,
                        &Nm_StateReportKind[index].signalVal);
                }
#else
                (void)nmPreviousState;
                (void)nmCurrentState;
#endif /* STD_ON == NM_SUPPORT_COM_SENDSIGNAL */
            }
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_STATECHANGENOTIFICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_STATECHANGENOTIFICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif /* STD_ON == NM_STATE_CHANGE_IND_ENABLED */

/******************************************************************************/
/*
 * Brief               Service to indicate that an NM message with set Repeat
 *                     Message Request Bit has been received
 * ServiceId           0x1a
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_RepeatMessageIndication(NetworkHandleType nmNetworkHandle)
{
    (void)(nmNetworkHandle);
}
#define NM_STOP_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"

/******************************************************************************/
/*
 * Brief               Service to indicate that an attempt to send an NM message
 *                     failed.
 * ServiceId           0x1b
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_TxTimeoutException(NetworkHandleType nmNetworkHandle)
{
    (void)(nmNetworkHandle);
}
#define NM_STOP_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "Nm_MemMap.h"

/* @SWS_Nm_00251 */
#if (STD_ON == NM_CAR_WAKE_UP_RX_ENABLED)
/******************************************************************************/
/*
 * Brief               This function is called by a <Bus>Nm to indicate reception
 *                     of a CWU request
 * ServiceId           0x1d
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_CarWakeUpIndication(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    if ((boolean)TRUE == Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CHANNELS)
        uint8 chIndex = 0xffu;
        if ((boolean)TRUE == Nm_FindChannelIndex(nmChannelHandle, &chIndex))
        {
            /* @SWS_Nm_00252 */
            Nm_GlobalLConfig.NmCarWakeUpCallout(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
        }
        else
#endif /* 0u < NM_NUMBER_OF_CHANNELS */
        {
#if (STD_ON == NM_DEV_ERROR_DETECT)
            NM_DET_REPORT(NM_SERVICE_ID_CARWAKEUPINDICATION, NM_E_INVALID_CHANNEL);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
        }
    }
    else
    {
#if (STD_ON == NM_DEV_ERROR_DETECT)
        NM_DET_REPORT(NM_SERVICE_ID_CARWAKEUPINDICATION, NM_E_UNINIT);
#endif /* STD_ON == NM_DEV_ERROR_DETECT */
    }
}
#define NM_STOP_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif /* STD_ON == NM_CAR_WAKE_UP_RX_ENABLED */

/* @SWS_Nm_00279 */
#define NM_START_SEC_CODE
#include "Nm_MemMap.h"
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/******************************************************************************/
/*
 * Brief               This function implements the processes of the NM Interface,
 *                     which need a fix cyclic scheduling.
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      NA
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_MainFunction(void)
{
    if (Nm_InitStatus)
    {
#if (0u < NM_NUMBER_OF_CLUSTERS)
        uintx clusterIndex;
        for (clusterIndex = 0u; clusterIndex < NM_NUMBER_OF_CLUSTERS; clusterIndex++)
        {
            Std_ReturnType ret = E_OK;
            const Nm_PerClusterConfigType* perClusPtr = &Nm_LocalCfgPtr->perCluPtr[clusterIndex];
            Nm_ShutdownStatusType* shutdownStatus = &Nm_InnerCluster[clusterIndex].shutdownStatus;
            if (NM_SHUTDOWN_STU_START == *shutdownStatus)
            {
/*handle not topmost CSRBit change*/
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
                Nm_CoorReadySleepBitHandle(perClusPtr, FALSE);
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT*/

                /*all channel not in alive,shutdown ready*/
                if (Nm_CoorShutdownReady(perClusPtr))
                {
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
                    /*shutdown ready set topmost active channel CSRBit = 1*/
                    Nm_CoorReadySleepBitHandle(perClusPtr, TRUE);
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
                    /*start CSR=1 channel's coordinate shutdown,start
                     shutdown timer*/
                    if ((uint8)E_OK == Nm_CoorShutdownTimerLoader(perClusPtr))
                    {
                        *shutdownStatus = NM_SHUTDOWN_STU_RUN;
                    }
                }
            }
            if (NM_SHUTDOWN_STU_RUN == *shutdownStatus)
            {
                boolean sleepAllow = FALSE;
                if (Nm_CoorShutdownReady(perClusPtr))
                {
                    ret = Nm_CoorShutDownTimerHandle(perClusPtr, &sleepAllow);
                }
                if ((uint8)E_OK != ret)
                {
                    *shutdownStatus = NM_SHUTDOWN_STU_ABORT;
                }
                else
                {
                    if (sleepAllow)
                    {
                        *shutdownStatus = NM_SHUTDOWN_STU_STOP;
                    }
                }
            }
            if (NM_SHUTDOWN_STU_ABORT == *shutdownStatus)
            {
                Nm_CoorShutdownAbortHandle(perClusPtr);
                *shutdownStatus = NM_SHUTDOWN_STU_START;
            }
        }
#endif /* 0u < NM_NUMBER_OF_CLUSTERS */
    }
}
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (0u < NM_NUMBER_OF_CHANNELS)
/******************************************************************************/
/*
 * Brief               nm upper layer NetworkHandleType data link nm channel
 *                     index
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      NetworkHandle,Identification of the NM-channel
 * Param-Name[out]     chIndexPtr,Pointer the chIndex of the corresponding
 *                     configuration
 * Param-Name[in/out]  NA
 * Return              TRUE:find the corresponding
 *                     FALSE:not find the corresponding
 */
/******************************************************************************/
static FUNC(boolean, NM_CODE) Nm_FindChannelIndex(NetworkHandleType NetworkHandle, uint8* chIndexPtr)
{
    uint8 chIndex;
    boolean findChannelFlg = FALSE;
    for (chIndex = 0u; ((chIndex < NM_NUMBER_OF_CHANNELS) && (findChannelFlg == (boolean)FALSE)); chIndex++)
    {
        if (NetworkHandle == Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel)
        {
            *chIndexPtr = chIndex;
            findChannelFlg = TRUE;
        }
    }
    return findChannelFlg;
}
#endif /* 0u < NM_NUMBER_OF_CHANNELS */

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/******************************************************************************/
/*
 * Brief               find nm local map to cluster index
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      chIndex,Index of the corresponding configuration
 * Param-Name[out]     clusterIndexPtr,Pointer clusterIndex which chindex
 *                     belongs to
 * Param-Name[in/out]  NA
 * Return              E_OK:find the corresponding clusterIndex
 *                     E_NOT_OK:not find the corresponding clusterIndex
 */
/******************************************************************************/
static FUNC(Std_ReturnType, NM_CODE) Nm_FindClusterIndex(
    uint8 chIndex,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) clusterIndexPtr
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
)
{
    uint8 index;
    Std_ReturnType findFlg = E_NOT_OK;
    if (NULL_PTR != Nm_LocalCfgPtr->perCluPtr)
    {
        for (index = 0u; (index < NM_NUMBER_OF_CLUSTERS) && ((uint8)E_NOT_OK == findFlg); index++)
        {
            if (Nm_ChLConfig[chIndex].NmCoordClusterIndex == Nm_LocalCfgPtr->perCluPtr[index].coorClusterIndex)
            {
                findFlg = E_OK;
                *clusterIndexPtr = index;
            }
        }
    }
    return findFlg;
}
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
/******************************************************************************/
/*
 * Brief               topmost shutdown ready CSRBit set,and not topmost CSRBit
 *                     change handler
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      perClusPtr,Pointer to the current cluster
 *                     ReqCSRBitFlag,TRUE:topmost coorshutdown,set CSRBit=1
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(void, NM_CODE) Nm_CoorReadySleepBitHandle(
    P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr,
    boolean ReqCSRBitFlag)
{
    uint8 chIndex;
    uint8 index;
    boolean coorRsb = FALSE;
    boolean NeedHandle = FALSE;
    if (perClusPtr->topMostCoor)
    {
        if (ReqCSRBitFlag)
        {
            coorRsb = TRUE;
            NeedHandle = TRUE;
        }
    }
    else
    {
        NeedHandle = TRUE;
        uint8 incNumCh = perClusPtr->incNumCh;
        for (index = 0; index < incNumCh; index++)
        {
            chIndex = perClusPtr->incCh[index];
            if (!Nm_ChLConfig[chIndex].NmActiveCoordinator)
            {
                /*get passive channel CSRbit value*/
                coorRsb = Nm_InnerChannel[chIndex].coorRSB;
                break;
            }
        }
    }

    if (NeedHandle)
    {
        uint8 incNumCh = perClusPtr->incNumCh;
        for (index = 0; index < incNumCh; index++)
        {
            chIndex = perClusPtr->incCh[index];
            /*topmost set CSR=1 in active channel or not top most
             *forward CSR from passive channel to active channel*/
            if (Nm_ChLConfig[chIndex].NmActiveCoordinator)
            {
                if (coorRsb != Nm_InnerChannel[chIndex].coorRSB)
                {
                    /*forward CSRBit in all active channel*/
                    if (E_OK == Nm_BusNmSetSleepReadyBit(chIndex, coorRsb))
                    {
                        Nm_InnerChannel[chIndex].coorRSB = coorRsb;
                    }
                }
            }
        }
    }
}
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT*/

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/******************************************************************************/
/*
 * Brief               check alive channel in coordinator cluster,judge cluster
 *                     is ready to coor shutdown or not
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      perClusPtr,Pointer to the current cluster
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              TRUE:cluster ready to coor shutdown
 *                     FALSE:cluster not ready to coor shutdown
 */
/******************************************************************************/
static FUNC(boolean, NM_CODE) Nm_CoorShutdownReady(P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr)
{
    uintx index;
    uint8 incNumCh = perClusPtr->incNumCh;
    for (index = 0u; index < incNumCh; index++)
    {
        uint8 chIndex = perClusPtr->incCh[index];
        const Nm_ChannelLConfigType* chCfgPtr = &Nm_ChLConfig[chIndex];
        Nm_InnerChannelType* chRTPtr = &Nm_InnerChannel[chIndex];
        /* new check mode */
        /*  pre-condition,special bus is awake */
        if (chRTPtr->busAwakeFlg)
        {
            if (chRTPtr->upLayNetRequest)
            {
                break;
            }
            else
            {
                /* pre-condition: no sleep master
                next: active channel need check remote ind,
                but passive channel is not need remote ind
                next : coor rsb,
                */
                if ((!chCfgPtr->NmChannelSleepMaster &&
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
                     chCfgPtr->NmActiveCoordinator &&
#endif
                     !chRTPtr->remoteSleepIndFlg)
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
                    || (!perClusPtr->topMostCoor && chCfgPtr->NmActiveCoordinator && !chRTPtr->coorRSB)
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
                )
                {
                    break;
                }
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
                if (chRTPtr->remoteSleepIndFlg)
                {
                    if (perClusPtr->topMostCoor && (NM_BUSNM_LOCALNM != chCfgPtr->busNmType))
                    {
                        /*sync network not recv lowlayer sync ind */
                        if (chCfgPtr->NmSynchronizingNetwork && !chRTPtr->lowLayBusSyncPoint)
                        {
                            /*not ready to coor shutdown*/
                            break;
                        }
                    }
                }
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
            }
        }
        else
        {
            if (chRTPtr->upLayNetRequest)
            {
                break;
            }
        }
    }

    return index >= perClusPtr->incNumCh;
}
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/******************************************************************************/
/*
 * Brief               coordinator shutdown timer load default value.
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      perClusPtr,Pointer to the current cluster
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(Std_ReturnType, NM_CODE)
    Nm_CoorShutdownTimerLoader(P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr)
{
    uintx index;
    uint8 chIndex;
    Std_ReturnType ret = E_OK;
    /*syncNetFlg is generated by the configuration*/
    if (perClusPtr->syncNetFlg)
    {
        uint8 incNumCh = perClusPtr->incNumCh;
        for (index = 0; index < incNumCh; index++)
        {
            chIndex = perClusPtr->incCh[index];
            /* @SWS_Nm_00172 Synchronou network shall be delay until sync point */
            if (Nm_InnerChannel[chIndex].busAwakeFlg && Nm_ChLConfig[chIndex].NmSynchronizingNetwork
                && !Nm_InnerChannel[chIndex].lowLayBusSyncPoint)
            {
                ret = E_NOT_OK;
                break;
            }
        }
    }
    if (E_OK == ret)
    {
        uint8 incNumCh = perClusPtr->incNumCh;
        for (index = 0u; index < incNumCh; index++)
        {
            chIndex = perClusPtr->incCh[index];
            Nm_InnerChannelType* chRTPtr = &Nm_InnerChannel[chIndex];
            if (chRTPtr->busAwakeFlg)
            {
                /* @SWS_Nm_00175 reload shutdownTimer */
                SchM_Enter_Nm_MsgContext();
                chRTPtr->allowShutdown = TRUE;
                SchM_Exit_Nm_MsgContext();
                if ((NM_GLOBAL_COORDINATOR_TIME < Nm_ChLConfig[chIndex].busNmShutdownTime)
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
                    || !Nm_ChLConfig[chIndex].NmActiveCoordinator
#endif
                )
                {
                    chRTPtr->shutdownTimer = 0u;
                }
                else
                {
                    /*@req SWS_Nm_00175*/
                    if (NM_BUSNM_LOCALNM == Nm_ChLConfig[chIndex].busNmType)
                    {
                        chRTPtr->shutdownTimer = NM_GLOBAL_COORDINATOR_TIME;
                    }
                    else
                    {
                        chRTPtr->shutdownTimer = NM_GLOBAL_COORDINATOR_TIME - Nm_ChLConfig[chIndex].busNmShutdownTime;
                    }
                }
            }
        }
    }
    return ret;
}
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/******************************************************************************/
/*
 * Brief               coordinator shutdown timer handle function
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      perClusPtr,Pointer to the current cluster
 * Param-Name[out]     sleepAllowPtr,Pointer whether to allow sleep
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(Std_ReturnType, NM_CODE) Nm_CoorShutDownTimerHandle(
    P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, NM_APPL_DATA) sleepAllowPtr
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
)
{
    uintx index;
    uint8 chIndex;
    Std_ReturnType ret = E_OK;
    boolean sleepAllowFlg = TRUE;
    uint8 incNumCh = perClusPtr->incNumCh;
    /* check sync network point */
    for (index = 0u; index < incNumCh; index++)
    {
        chIndex = perClusPtr->incCh[index];
        Nm_InnerChannelType* chRTPtr = &Nm_InnerChannel[chIndex];
        if (chRTPtr->busAwakeFlg)
        {
            sleepAllowFlg = FALSE;
            if (0u < chRTPtr->shutdownTimer)
            {
                chRTPtr->shutdownTimer--;
            }
            /* @SWS_Nm_00176
            timer expiers for network ,whill be call busNetRelease */
            if ((0u == chRTPtr->shutdownTimer) && chRTPtr->allowShutdown)
            {
                SchM_Enter_Nm_MsgContext();
                chRTPtr->allowShutdown = FALSE;
                SchM_Exit_Nm_MsgContext();

                if (NM_BUSNM_LOCALNM == Nm_ChLConfig[chIndex].busNmType)
                {
                    /*@req SWS_Nm_00176*/
                    ComM_Nm_BusSleepMode(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
                    chRTPtr->lowLayBusSyncPoint = FALSE;
                    chRTPtr->busAwakeFlg = FALSE;
                    chRTPtr->remoteSleepIndFlg = FALSE;
                    chRTPtr->lowLayNetRequest = FALSE;
                }
                else
                {
#if (STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED)
                    ret = Nm_BusNmRequestBusSynchronization(chIndex);
                    if (ret != E_OK)
                    {
                        break;
                    }
#endif /* STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED */
                    if (chRTPtr->lowLayNetRequest)
                    {
                        ret = Nm_BusNmNetworkRelease(chIndex);
                        if (ret != E_OK)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    if (((uint8)E_OK == ret) && sleepAllowFlg)
    {
        *sleepAllowPtr = TRUE;
    }
    return ret;
}
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/******************************************************************************/
/*
 * Brief               coordinator shutdown abort handle function
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      perClusPtr,Pointer to the current cluster
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(void, NM_CODE)
    Nm_CoorShutdownAbortHandle(P2CONST(Nm_PerClusterConfigType, AUTOMATIC, NM_APPL_DATA) perClusPtr)
{
    uintx index;
    uint8 chIndex;

    uint8 incNumCh = perClusPtr->incNumCh;
    for (index = 0x0u; index < incNumCh; index++)
    {
        chIndex = perClusPtr->incCh[index];
        const Nm_ChannelLConfigType* chCfgPtr = &Nm_ChLConfig[chIndex];
        Nm_InnerChannelType* chRTPtr = &Nm_InnerChannel[chIndex];
        if (chRTPtr->busAwakeFlg)
        {
            if (!chRTPtr->lowLayNetRequest)
            {
                chRTPtr->allowShutdown = FALSE;
                /*@req SWS_Nm_00183*/
                if (NM_BUSNM_LOCALNM == chCfgPtr->busNmType)
                {
                    ComM_Nm_NetworkMode(chCfgPtr->NmComMChannelRef.comMChannel);
                }
                else
                {
                    (void)Nm_BusNmNetworkRequest(chIndex);
                }
            }
        }
        else
        {
            ComM_Nm_RestartIndication(chCfgPtr->NmComMChannelRef.comMChannel);
        }
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
        /* call low api to set coor Ready sleep bit in all active channel,
        passive channel only change local ver */
        if (!chCfgPtr->NmActiveCoordinator)
        {
            chRTPtr->coorRSB = FALSE;
        }
        else
        {
            if ((uint8)E_OK == Nm_BusNmSetSleepReadyBit(chIndex, FALSE))
            {
                chRTPtr->coorRSB = FALSE;
            }
        }
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
    }
}
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#if ((STD_OFF == NM_PASSIVE_MODE_ENABLED) && (0u < NM_NUMBER_OF_CHANNELS))
/******************************************************************************/
/*
 * Brief               special bus nm network request
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      chIndex,Configured channel index
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmNetworkRequest(uint8 chIndex)
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
    {
        BusNm_NetworkRequest_Type specific_NetworkRequest = Nm_ChLConfig[chIndex].busNmApi->BusNm_NetworkRequest;
        if (NULL_PTR != specific_NetworkRequest)
        {
            ret = specific_NetworkRequest(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            Nm_InnerChannel[chIndex].lowLayNetRequest = TRUE;
            if ((uint8)E_OK != ret)
            {
                /* @SWS_Nm_00235
                if BusNm_NetworkRequest return E_NOT_OK,that network shall not be
                considered awake */
                Nm_InnerChannel[chIndex].busAwakeFlg = FALSE;
            }
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
        }
    }
    return ret;
}
#endif /* (STD_OFF == NM_PASSIVE_MODE_ENABLED)&& \
    (0u < NM_NUMBER_OF_CHANNELS) */

#if ((STD_OFF == NM_PASSIVE_MODE_ENABLED) && (0u < NM_NUMBER_OF_CHANNELS))
/******************************************************************************/
/*
 * Brief               special bus network release
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      chIndex,Configured channel index
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmNetworkRelease(uint8 chIndex)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
    {
        BusNm_NetworkRequest_Type specific_NetworkRelease = Nm_ChLConfig[chIndex].busNmApi->BusNm_NetworkRelease;
        if (NULL_PTR != specific_NetworkRelease)
        {
            ret = specific_NetworkRelease(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
            Nm_InnerChannel[chIndex].lowLayNetRequest = FALSE;
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */
        }
    }
    return ret;
}
#endif /* (STD_OFF == NM_PASSIVE_MODE_ENABLED)&& \
    (0u < NM_NUMBER_OF_CHANNELS) */

#if ((STD_ON == NM_COORDINATOR_SUPPORT_ENABLED) && (STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED))
/******************************************************************************/
/*
 * Brief               special bus nm request sync
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      chIndex,Configured channel index
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmRequestBusSynchronization(uint8 chIndex)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
    {
        BusNm_RequestBusSynchronization_Type specific_RequestBusSynchronization =
            Nm_ChLConfig[chIndex].busNmApi->BusNm_RequestBusSynchronization;
        if (NULL_PTR != specific_RequestBusSynchronization)
        {
            ret = specific_RequestBusSynchronization(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel);
        }
    }
    return ret;
}
#endif /* (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)&& \
 (STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED) */

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
/******************************************************************************/
/*
 * Brief               special bus nm set coordinator ready sleep bit
 * ServiceId           NA
 * Sync/Async          NA
 * Reentrancy          NA
 * Param-Name[in]      chIndex,Configured channel index
 *                     nmSleepReadyBit,value of the SleepReadyBit
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
static FUNC(Std_ReturnType, NM_CODE) Nm_BusNmSetSleepReadyBit(uint8 chIndex, boolean nmSleepReadyBit)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL_PTR != Nm_ChLConfig[chIndex].busNmApi)
    {
        BusNm_SetSleepReadyBit_Type specific_SetSleepReadyBit = Nm_ChLConfig[chIndex].busNmApi->BusNm_SetSleepReadyBit;
        if (NULL_PTR != specific_SetSleepReadyBit)
        {
            ret = specific_SetSleepReadyBit(Nm_ChLConfig[chIndex].NmComMChannelRef.comMChannel, nmSleepReadyBit);
        }
    }

    if (NM_BUSNM_LOCALNM == Nm_ChLConfig[chIndex].busNmType)
    {
        ret = E_OK;
    }
    return ret;
}
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
#define NM_STOP_SEC_CODE
#include "Nm_MemMap.h"
