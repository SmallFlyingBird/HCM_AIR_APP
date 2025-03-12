/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Dcm.c                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS    **
**  			 services which used for bootloader project.                  **
**                                                                            **
**  SPECIFICATION(S) :   UDS Service - ISO14229. 		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *    V1.0.0    20121109    Gary            Initial version
 *    V1.0.1    20130913    ccl             update
 *    V1.0.2    20160801    cywang          update
 *    V1.0.3    20180511    CChen           update
 *    V1.0.4    20200413    Lianren.Wu      optimization
 *    V1.0.5    20200426    Lianren.Wu      optimization Dcm_ProgramInit Function,
 *                                          add the operate of MICRO
 *                                          APPL_RESPONSE_IN_BOOT_AFTER_RESET.
 *    V1.0.6    20200506    Lianren.Wu      optimization Dcm_Init Function.
 *    V1.0.7    20200519    Lianren.Wu      set the init of rxBuff.pduInfo.SduDataPtr
 *                                          and txBuff.pduInfo.SduDataPtr in Dcm_Init.
 *    V1.0.8    20200913    Lianren.Wu      optimization function.
 *    V1.0.9    20210326    Lianren.Wu      add the security in the Dcm_ServiceHandle.
 *    V1.0.10   20231214    Long.Zhu      	1.27 Service logic reconstruction.
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:Dcm .<br>
  RuleSorce:puhua-rule2024.rcf 1.0.2

    \li PRQA S 3218  Rule 8.9 .<br>
    Reason: File scope static, '%s', is only accessed in one function.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_Cfg.h"
#include "Dcm.h"
#include "Dcm_Internel.h"
#include "PduR_Callout.h"
#include "PduR_Cfg.h"
#include "McalLib_Compiler.h"
#include "Os.h"
#include "LinTp.h"
#include "Os_User.h"
#include "Rte_Dcm.h"
#include "Mcu.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/** Session runtime status */
typedef struct
{
    /* DCM current session type */
    Dcm_SessionType curSession;
    /* ECU reset Timer */
    uint16 resetTimer;
    /* if security access is unlocked */
    Dcm_SecurityType securityLevel;
    /* DCM security access timer */
    uint32 securityTimer[DCM_SECURITY_NUM];
} Dcm_RunTimeType;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void Dcm_ClearRxBuff(void);
static void Dcm_ServiceStart(void);
static void Dcm_ServiceHandle(void);
static void Dcm_ServiceProcess(void);
static void Dcm_StopP3cTimer(void);
static void Dcm_P3cTimerCheck(void);
static void Dcm_StopP4sTimer(void);
static void Dcm_StartP4sTimer(void);
static void Dcm_P4sTimerCheck(void);
static void Dcm_StopP2eTimer(void);
static void Dcm_P2eTimerCheck(void);
static void Dcm_StartTransmit(void);
static void Dcm_SecurityTimerCheck(void);
static void Dcm_StopResetTimer(void);
static void Dcm_ResetTimerCheck(void);
static void Dcm_TimerProc(void);

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/** use static memory for service */
static uint8 Dcm_MainRxBuff[DCM_RX_BUF_SIZE];
static uint8 Dcm_MainTxBuff[DCM_TX_BUF_SIZE]; /*PRQA S 3218*/

/** dcm communication status about service */
static Dcm_ComType dcmComStatus;
/** dcm runtime status about session and security access */
static Dcm_RunTimeType dcmRunTime;

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <DCM module initialize>
 *
 * <DCM module initialize> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_Init(void) 
{
    /* set session to program session */
    Dcm_SetSessionMode((uint8)DCM_SESSION_DEFAULT);

    /* reset to security access level */
    Dcm_SetSecurityLevel((uint8)DCM_SECURITY_LEV1);

    /* stop ECU reset timer */
    Dcm_StopResetTimer();

    /* initialize tx and rx buffer */
    dcmComStatus.rxBuff.pduInfo.SduDataPtr = Dcm_MainRxBuff;
    dcmComStatus.txBuff.pduInfo.SduDataPtr = Dcm_MainTxBuff;

    /* reset service process */
    Dcm_ServiceFinish();

    /* initialize rx buffer */
    Dcm_Service_RxFinish();

    /* initialize DSP */
    Dcm_DspInit();

    /* set the security timer based on attemp time */
    Rte_Dcm_SecTimer_Init();
}
/******************************************************************************/
/**
 * @brief               <Get Dcm Tx Status>
 *<return dcm TX Status>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <Dcm_BuffStatusType:txstatus>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
Dcm_BuffStatusType Dcm_GetTxStatus(void)
{
	return dcmComStatus.txBuff.buffStatus ;
}
/******************************************************************************/
/**
 * @brief               <DCM main task function>
 *
 * <DCM main task function> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_MainFunction(void) 
{
    /* process P2E, P3C, P4S, security timer, reset timer */
    Dcm_TimerProc();

    /* process service */
    Dcm_ServiceProcess();
}

/******************************************************************************/
/**
 * @brief               <DCM provide rx buffer for CanTp>
 *
 * <DCM provide rx buffer for CanTp, mean an request is receiving> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <pduId (IN), pduLen (IN)>
 * @param[out]          <sduInfo (OUT)>
 * @param[in/out]       <NONE>
 * @return              <CanTp_BufReq_RetType>
 */
/******************************************************************************/
BufReq_ReturnType Dcm_ProvideRxBuffer(PduIdType pduId, PduLengthType pduLen, PduInfoType** sduInfo) 
{
    BufReq_ReturnType retVal = BUFREQ_OK;
    /* Rx buffer is free state and pduid is correct */
    if ((DCM_BUFF_FREE == dcmComStatus.rxBuff.buffStatus)
        && ((DCM_RX_PHY_PDU_ID == pduId) || (DCM_RX_FUNC_PDU_ID == pduId)))
    {
        /* Main Buffer should be free */
        if (pduLen <= (PduLengthType)DCM_RX_BUF_SIZE)
        {
            /* allocate MainRxBuff */
            dcmComStatus.rxBuff.buffStatus = DCM_BUFF_FOR_TP;
            dcmComStatus.rxBuff.pduId = pduId;
            dcmComStatus.rxBuff.pduInfo.SduLength = pduLen;
            *sduInfo = &dcmComStatus.rxBuff.pduInfo;
        }
        else
        {
            /* main buffer provided fail */
            retVal = BUFREQ_E_OVFL;
        }
    }
    else
    {
        /* No buffer available */
        retVal = BUFREQ_E_NOT_OK;
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <DCM rx indication from CanTp>
 *
 * <DCM rx indication from CanTp,mean an request is received> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <pduId (IN), result (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RxIndication(PduIdType pduId, NotifResultType result) 
{
    /* check if Rx buffer is provide for CanTp */
    if (DCM_BUFF_FOR_TP == dcmComStatus.rxBuff.buffStatus)
    {
        /* Indication for MainBuff */
        if (((uint8)NTFRSLT_OK == result) && (pduId == dcmComStatus.rxBuff.pduId))
        {
            /* receive Ok */
            Dcm_ServiceStart();
        }
        else
        {
            /* receive failed */
            Dcm_Service_RxFinish();
            Dcm_ServiceFinish();
        }
    }
}

/******************************************************************************/
/**
 * @brief               <DCM provide tx buffer for CanTp>
 *
 * <DCM provide rx buffer for CanTp,mean a response is sending> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <pduId (IN)>
 * @param[out]          <sduInfo (OUT)>
 * @param[in/out]       <NONE>
 * @return              <CanTp_BufReq_RetType>
 */
/******************************************************************************/
BufReq_ReturnType Dcm_ProvideTxBuffer(PduIdType pduId, PduInfoType** sduInfo) 
{
    BufReq_ReturnType retVal = BUFREQ_OK;
    /* check if Tx Buffer is provide for service process */
    if ((DCM_BUFF_FOR_SERVICE == dcmComStatus.txBuff.buffStatus) && (pduId == dcmComStatus.txBuff.pduId))
    {
        /* send MainTXBuff */
        *sduInfo = &dcmComStatus.txBuff.pduInfo;
        dcmComStatus.txBuff.buffStatus = DCM_BUFF_FOR_TP;
    }
    else
    {
        /* if tx error, should clear rxBuff, for receive next frame */
        Dcm_Service_RxFinish();
        Dcm_ServiceFinish();
        retVal = BUFREQ_E_NOT_OK;
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <DCM tx confirmation from CanTp>
 *
 * <DCM rx indication from CanTp,mean a response is sended> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <pduId (IN), result (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_TxConfirmation(PduIdType pduId, NotifResultType result) 
{
    /* service response finished */
    if (((uint8)NTFRSLT_OK == result) && (pduId == dcmComStatus.txBuff.pduId)
        && ((boolean)FALSE == dcmComStatus.respFinished))
    {
        /* this case is only appear when send pending message and service is not finished */
        dcmComStatus.txBuff.buffStatus = DCM_BUFF_FREE;
    }
    else
    {
        Dcm_ServiceFinish();
    }
}

/******************************************************************************/
/**
 * @brief               <set service process finish>
 *
 * <set service process finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_ServiceFinish(void)
{
    /* set current service */
    dcmComStatus.curServicePtr = NULL_PTR;

    /* initialize tx and rx buffer status */
    dcmComStatus.txBuff.buffStatus = DCM_BUFF_FREE;

    /* initialize no new service request */
    dcmComStatus.reqNew = (boolean)FALSE;
    dcmComStatus.respFinished = (boolean)TRUE;

    /* stop P2E timer */
    Dcm_StopP2eTimer();
    /* stop P4s timer */
    Dcm_StopP4sTimer();

    /* process P3C timer in extended and programming session */
    if ((uint8)DCM_SESSION_DEFAULT == dcmRunTime.curSession)
    {
        Dcm_StopP3cTimer();
    }
    else
    {
        Dcm_StartP3cTimer();
    }
}

/******************************************************************************/
/**
 * @brief               <set service rx process finish>
 *
 * <set service process finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_Service_RxFinish(void)
{
    /* initialize rx buffer status */
    dcmComStatus.rxBuff.buffStatus = DCM_BUFF_FREE;
    /* initialize  rx buffer */
    Dcm_ClearRxBuff();
}

/******************************************************************************/
/**
 * @brief               <set session mode>
 *
 * <set session mode> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <sessMode (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_SetSessionMode(const Dcm_SessionType sessMode)
{
    /* set current session */
    dcmRunTime.curSession = sessMode;
}

/******************************************************************************/
/**
 * @brief               <get session mode>
 *
 * <get session mode> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <Dcm_SessionType>
 */
/******************************************************************************/
Dcm_SessionType Dcm_GetSessionMode(void)
{
    /* get current session */
    return dcmRunTime.curSession;
}

/******************************************************************************/
/**
 * @brief               <check if session mode is support>
 *
 * <check if session mode is support> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <sessionTable (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
boolean Dcm_CheckSessionSupp(const Dcm_SessionType* sessionSupportPtr, const uint8 sessionSupportNum)
{
    uint8 iloop;
    boolean retVal = (boolean)FALSE;
    /* Loop until all members of the configuration table are iterated */
    for (iloop = (uint8)0U; iloop < sessionSupportNum; iloop++)
    {
        /* Check if the current session mode matches the current configuration item */
        if (dcmRunTime.curSession == sessionSupportPtr[iloop])
        {
            retVal = (boolean)TRUE;
        }
        else
        {
            /* do nothing */
        }
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <set security level>
 *
 * <set security level> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <secLev (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_SetSecurityLevel(const Dcm_SecurityType secLev)
{
    /* set current security level */
    dcmRunTime.securityLevel = secLev;
}

/******************************************************************************/
/**
 * @brief               <get security level>
 *
 * <get security level> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <Dcm_SecurityType>
 */
/******************************************************************************/
Dcm_SecurityType Dcm_GetSecurityLevel(void) 
{
    /* get current security level */
    return dcmRunTime.securityLevel;
}

/******************************************************************************/
/**
 * @brief               <check if security timer is expired>
 *
 * <check if security timer is expired> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
boolean Dcm_GetSecurityTimerExpired(uint8 attemptId)
{
    boolean retVal = (boolean)TRUE;
    /* check if security timer expired */
    if (dcmRunTime.securityTimer[attemptId] > (uint32)0U)
    {
        retVal = (boolean)FALSE;
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <check if security level if supportted>
 *
 * <check if security level if supportted> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <secLevTable (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
boolean Dcm_CheckSecuritySupp(const Dcm_SecurityType* securitySupportPtr, const uint8 securitySupportNum)
{
    uint8 index;
    boolean retVal = (boolean)FALSE;
    /* Loop until all members of the configuration table are iterated */
    for (index = (uint8)0U; index < securitySupportNum; index++)
    {
        /* Check if the security level matches the current configuration item */
        if (dcmRunTime.securityLevel == securitySupportPtr[index])
        {
            retVal = (boolean)TRUE;
        }
        else
        {
            /* do nothing */
        }
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <start security timer>
 *
 * <start security timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <timeOut (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_StartSecurityTimer(uint8 attemptId, uint32 timeOut)
{
    /* set to config value */
    dcmRunTime.securityTimer[attemptId]  = (uint32)(timeOut / (uint32)DCM_MAIN_TICK);
}

/******************************************************************************/
/**
 * @brief               <start reset timer>
 *
 * <start reset timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <timeOut (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_StartResetTimer(uint16 timeOut) 
{
    /* set reset timer value */
    dcmRunTime.resetTimer = (uint16)(timeOut / (uint16)DCM_MAIN_TICK);
}

/******************************************************************************/
/**
 * @brief               <send response>
 *
 * <send response> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_SendRsp(void)
{
    /* service process is finished */
    dcmComStatus.respFinished = (boolean)TRUE;

    /* transmit message */
    Dcm_StartTransmit();

    /* initialize rx buffer status */
    Dcm_Service_RxFinish();
}

/******************************************************************************/
/**
 * @brief               <transmit negative response>
 *
 * <transmit negative response> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <nrcCode (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_SendNrc(uint8 nrcCode)
{
    uint8* const pduData = &(dcmComStatus.txBuff.pduInfo.SduDataPtr[0]);

    /* check if send pending */
    if ((uint8)DCM_E_78_PENDING != nrcCode)
    {
        /* if send NRC, service process is finished */
        dcmComStatus.respFinished = (boolean)TRUE;
    }
    /* set negative response message */
    /* The message format is: 0x7E, ServiceId, NRC*/
    pduData[0] = (uint8)DCM_RSP_SID_NRC;
    pduData[1] = dcmComStatus.rxBuff.pduInfo.SduDataPtr[0];
    pduData[2] = nrcCode;
    dcmComStatus.txBuff.pduInfo.SduLength = (PduLengthType)0x03u;
    Dcm_StartTransmit();
    if ((boolean)TRUE == dcmComStatus.respFinished)
    {
        /* initialize rx buffer status */
        Dcm_Service_RxFinish();
    }
}

/******************************************************************************/
/**
 * @brief               <Phy addressing send negative response>
 *
 * <Phy addressing send negative response> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <condition (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
boolean Dcm_PhyAddrSendNrc(boolean result, const PduIdType curPduId, uint8 nrcCode)
{
    if ((boolean)FALSE == result)
    {
        /*only phy address need response*/
        if (((uint8)DCM_RX_PHY_PDU_ID == curPduId)
            || (((uint8)DCM_RX_FUNC_PDU_ID == curPduId)
                /*Function addressing only allow these NRC*/
                && ((nrcCode != DCM_E_11_SERVICE_NOT_SUPPORTED) && (nrcCode != DCM_E_12_SUBFUNC_NOT_SUPPORTED)
                    && (nrcCode != DCM_E_31_REQUEST_OUT_OF_RANGE)
                    && (nrcCode != DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION)
                    && (nrcCode != DCM_E_7F_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION))))
        {
            Dcm_SendNrc(nrcCode);
        }
        else
        {
            /* reset service process */
            Dcm_Service_RxFinish();
            Dcm_ServiceFinish();
        }
    }

    return result;
}

/******************************************************************************/
/**
 * @brief               <start P3C timer by config value>
 *
 * <start P3C timer by config value> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_StartP3cTimer(void)
{
    if ((uint8)DCM_SESSION_DEFAULT != dcmRunTime.curSession)
    {
        dcmComStatus.p3cTimer = (uint16)(DCM_P3MAX_TIME / DCM_MAIN_TICK);
    }
}

/******************************************************************************/
/**
 * @brief               <start P2e timer by config value.>
 *
 * <start P2e timer by config value.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_ForcePending(void) 
{
    Dcm_StartP2eTimer((uint16)1U);
}

/******************************************************************************/
/**
 * @brief               <start P4s max timer by config value>
 *
 * <start P4s max timer by config value> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_StartP4sTimer_Max(uint32 timerMax) 
{
    dcmComStatus.p4sTimer_Max = ((uint32)timerMax / DCM_MAIN_TICK);
}

/******************************************************************************/
/**
 * @brief               <start P2E timer by given value>
 *
 * <start P2E timer by given value> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <timeout (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_StartP2eTimer(const uint16 timeout)
{
    dcmComStatus.p2eTimer = (uint16)(timeout / DCM_MAIN_TICK);
}
/******************************************************************************/
/**
 * @brief               <get dcm status> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
Dcm_ComType* Dcm_GetComStatus(void)
{
    return &dcmComStatus;
}

/******************************************************************************/
/**
 * @brief               <Dcm_GetRxStatus.>
 * 
 * <Dcm_GetRxStatus.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <TXRXStatus : Dcm TX RX Status.>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <ret: Buff Status >    
 */
/******************************************************************************/
Dcm_BuffStatusType Dcm_GetRxStatus(void)
{
	return dcmComStatus.rxBuff.buffStatus;
}

/******************************************************************************/
/**
 * @brief               <GET bUFFER > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
BufReq_ReturnType Dcm_TakeTxBuffer(void)
{
    BufReq_ReturnType ret = BUFREQ_OK;

    /* check if Tx Buffer is provide for service process */
    if ((DCM_BUFF_FREE == dcmComStatus.txBuff.buffStatus))
    {
        dcmComStatus.txBuff.buffStatus = DCM_BUFF_FOR_TP;
    }
    else
    {
        ret = BUFREQ_E_NOT_OK;
    }

    return ret;
}

/******************************************************************************/
/**
 * @brief               <Give Tx buffer. > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_GiveTxBuffer(void)
{
    dcmComStatus.txBuff.buffStatus = DCM_BUFF_FREE;
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <clear rx buffer>
 *
 * <clear rx buffer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_ClearRxBuff(void)
{
    uint16 iloop;
    for (iloop = (uint16)0u; iloop < (uint16)DCM_RX_BUF_SIZE; iloop++)
    {
        Dcm_MainRxBuff[iloop] = (uint8)0xFFu;
    }
}

/******************************************************************************/
/**
 * @brief               <start service process when received message>
 *
 * <start service process when received message> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_ServiceStart(void)
{
    /* Rx buffer in service status */
    dcmComStatus.rxBuff.buffStatus = DCM_BUFF_FOR_SERVICE;

    /* start P2E timer */
    Dcm_StartP2eTimer((uint16)DCM_P2MAX_TIME);

    /* start P4s timer */
    Dcm_StartP4sTimer();

    /* stop P3C timer */
    Dcm_StopP3cTimer();

    /* a new service request is received */
    dcmComStatus.reqNew = (boolean)TRUE;

    dcmComStatus.respFinished = (boolean)FALSE;
}

/******************************************************************************/
/**
 * @brief               <handle requested service>
 *
 * <handle requested service> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_ServiceHandle(void)
{
    boolean sesSupp;
    boolean secSupp;
    uint8 nrcCode = 0u;
    uint8 index;
    const Dcm_ServiceTableType* pServiceTable = &Dcm_ServiceTable[0];

    /* dcmComStatus.curServicePtr = NULL_PTR;  excute when service finished, not need here */
    /* find service table */
    for (index = 0; index < (uint8)DCM_SERVICE_NUM; index++)
    {
        if (pServiceTable->SID == dcmComStatus.rxBuff.pduInfo.SduDataPtr[0])
        {
            /*phy addressing*/
            if (((((uint16)DCM_RX_PHY_PDU_ID == dcmComStatus.rxBuff.pduId)
                  && ((uint8)0U != (uint8)(pServiceTable->addressSupportMask & DCM_PHYSICAL_ADDRESSING))))
                ||
                /*function addressing*/
                (((uint16)DCM_RX_FUNC_PDU_ID == dcmComStatus.rxBuff.pduId)
                 && ((uint8)0U != (uint8)(pServiceTable->addressSupportMask & DCM_FUNCTIONAL_ADDRESSING))))
            {
                dcmComStatus.curServicePtr = pServiceTable;
            }
            break;
        }
        pServiceTable++;
    }

    /* check if service table is found */
    if ((NULL_PTR != dcmComStatus.curServicePtr) && (NULL_PTR != dcmComStatus.curServicePtr->serviceFct))
    {
        /* check if service is supported in current session*/
        sesSupp = Dcm_CheckSessionSupp(
            dcmComStatus.curServicePtr->sessionSupportPtr,
            dcmComStatus.curServicePtr->sessionSupportNbr);
        /* check if service is supported in current security*/
        secSupp = Dcm_CheckSecuritySupp(
            dcmComStatus.curServicePtr->securitySupportPtr,
            dcmComStatus.curServicePtr->securitySupportNbr);
        if ((boolean)FALSE == sesSupp)
        {
            /* set negative response message */
            /* NRC 7F  DCM_E_7F_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION */
            nrcCode = DCM_E_7F_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION;
        }
        else if ((boolean)FALSE == secSupp)
        {
            /* set negative response message */
            /* NRC 33  DCM_E_33_SECURITY_ACCESS_DENIED */
            nrcCode = DCM_E_33_SECURITY_ACCESS_DENIED;
        }
        else
        {
            /* execute service process */
            dcmComStatus.curServicePtr->serviceFct(&dcmComStatus.rxBuff, &dcmComStatus.txBuff);
        }
    }
    else
    {
        /* if received PDU ID is physical address, service is not supported */
        /* set negative response message */
        /* NRC 11  DCM_E_11_SERVICE_NOT_SUPPORTED */
        nrcCode = DCM_E_11_SERVICE_NOT_SUPPORTED;
    }
    if (0u != nrcCode)
    {
        (void)Dcm_PhyAddrSendNrc(FALSE, dcmComStatus.rxBuff.pduId, nrcCode);
    }
}

/******************************************************************************/
/**
 * @brief               <process new requested service>
 *
 * <process new requested service> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_ServiceProcess(void)
{
    uint8 errorCode;
    boolean serviceFinished;
    /* check if tx buffer is free */
    if (DCM_BUFF_FREE == dcmComStatus.txBuff.buffStatus)
    {
        /* check if there if a new request service */
        if ((boolean)TRUE == dcmComStatus.reqNew)
        {
            dcmComStatus.reqNew = (boolean)FALSE;
            Dcm_ServiceHandle();
        }
        else
        {
            /* check service process for pending */
            if ((boolean)FALSE == dcmComStatus.respFinished)
            {
                if (NULL_PTR != dcmComStatus.curServicePtr->pendingFct)
                {
                    dcmComStatus.curServicePtr->pendingFct(errorCode, &dcmComStatus.rxBuff, &dcmComStatus.txBuff);
                }
            }
        }
    }
}


/******************************************************************************/
/**
 * @brief               <stop P3C timer>
 *
 * <stop P3C timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_StopP3cTimer(void)
{
    dcmComStatus.p3cTimer = (uint16)0U;
}

/******************************************************************************/
/**
 * @brief               <process P3C timer>
 *
 * <process P3C timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_P3cTimerCheck(void)
{
    if (dcmComStatus.p3cTimer > (uint16)0U)
    {
        dcmComStatus.p3cTimer--;
        if ((uint16)0U == dcmComStatus.p3cTimer)
        {
            Dcm_SetSessionMode(DCM_SESSION_DEFAULT);
        }
    }
}

/******************************************************************************/
/**
 * @brief               <stop P4s timer>
 *
 * <stop P4s timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_StopP4sTimer(void)
{
    dcmComStatus.p4sTimer = (sint32)(-0xFF);
}

/******************************************************************************/
/**
 * @brief               <start P4s timer by config value>
 *
 * <start P4s timer by config value> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_StartP4sTimer(void) 
{
    dcmComStatus.p4sTimer = (sint32)0;
    dcmComStatus.p4sTimer_Max = ((uint32)DCM_P4MAX_TIME / DCM_MAIN_TICK);
}

/******************************************************************************/
/**
 * @brief               <process P4s timer>
 *
 * <process P4s timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_P4sTimerCheck(void)
{
    /* the p4sTimer is sint32 , so should compare to 0 (signed value 0 )*/
    if (dcmComStatus.p4sTimer >= (sint32)0)
    {
        dcmComStatus.p4sTimer++;
    }
}

/******************************************************************************/
/**
 * @brief               <stop P2E timer>
 *
 * <stop P2E timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_StopP2eTimer(void)
{
    dcmComStatus.p2eTimer = (uint16)0U;
}

/******************************************************************************/
/**
 * @brief               <process P2E timer>
 *
 * <process P2E timer,and send pending> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_P2eTimerCheck(void)
{
    boolean retVal = (boolean)FALSE;
    if (dcmComStatus.p2eTimer > (uint16)0U)
    {
        dcmComStatus.p2eTimer--;
        if ((uint16)0U == dcmComStatus.p2eTimer)
        {
            /* tx success or not tx state */
            if (DCM_BUFF_FREE == dcmComStatus.txBuff.buffStatus)
            {
                retVal = (boolean)TRUE;
            }
        }
        if ((dcmComStatus.p4sTimer >= (sint32)0) && ((uint32)dcmComStatus.p4sTimer < dcmComStatus.p4sTimer_Max))
        {
            if ((boolean)TRUE == retVal)
            {
                /* set negative response message */
                /* NRC 78  DCM_E_78_PENDING */
                Dcm_SendNrc((uint8)DCM_E_78_PENDING);
                /* start P2E timer to DCM_P2SMAX_TIME timeout */
                Dcm_StartP2eTimer((uint16)DCM_P2SMAX_TIME);
            }
        }
        else
        {
            /* set negative response message */
            /* NRC 10  DCM_E_10_GENERAL_REJECT */
            Dcm_SendNrc((uint8)DCM_E_10_GENERAL_REJECT);
            Dcm_StopP4sTimer();
        }
    }
}

/******************************************************************************/
/**
 * @brief               <transmit response>
 *
 * <transmit response, but not include pending> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_StartTransmit(void)
{
    /* set Dcm status */
    dcmComStatus.txBuff.buffStatus = DCM_BUFF_FOR_SERVICE;

    /* set PduId */
    dcmComStatus.txBuff.pduId = (uint8)DCM_TX_PDU_ID;

    /* call function of transport layer */
    //(void)PduR_TpTransmit(dcmComStatus.txBuff.pduId, &(dcmComStatus.txBuff.pduInfo));
    LinTp_Transmit(dcmComStatus.txBuff.pduId, &(dcmComStatus.txBuff.pduInfo));
}

/******************************************************************************/
/**
 * @brief               <process security timer>
 *
 * <process security timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_SecurityTimerCheck(void)
{
	uint8 secAttemptId;
	
    for(secAttemptId = 0; secAttemptId < DCM_SECURITY_NUM; secAttemptId ++)
    {
        if (dcmRunTime.securityTimer[secAttemptId] > 0UL)
        {
            dcmRunTime.securityTimer[secAttemptId]--;
            if(0u == dcmRunTime.securityTimer[secAttemptId])
            {
                /* store the count */
                if(App_UninitRam[secAttemptId] >= DCM_SECURITY_ATTEMPT_NUM)
                {
                	App_UninitRam[secAttemptId] = 0;

                }
            }
        }
    }
}

/******************************************************************************/
/**
 * @brief               <stop reset timer>
 *
 * <stop reset timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_StopResetTimer(void)
{
    /* clear reset timer value */
    dcmRunTime.resetTimer = (uint16)0x00u;
}

/******************************************************************************/
/**
 * @brief               <process reset timer>
 *
 * <process reset timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_ResetTimerCheck(void)
{
    if (dcmRunTime.resetTimer > (uint16)0u)
    {
        dcmRunTime.resetTimer--;
        /* check if reset timer is timeout */
        if ((uint16)0u == dcmRunTime.resetTimer)
        {
            /* ECU reset */
            Mcu_PerformReset();
        }
    }
}

/******************************************************************************/
/**
 * @brief               <process session timer P2E,P3C,reset ,security timer>
 *
 * <process session timer P2E,P3C,reset,security timer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_TimerProc(void)
{
    /* Disable interrupt. */
	SuspendAllInterrupts();

    /* process security timer */
    Dcm_SecurityTimerCheck();

    /* process P3C timer */
    Dcm_P3cTimerCheck();

    /* process P2E timer */
    Dcm_P2eTimerCheck();

    /* process P4S timer */
    Dcm_P4sTimerCheck();

    /* process ECU reset timer */
    Dcm_ResetTimerCheck();

    /* Enable interrupt. */
    ResumeAllInterrupts();
}
