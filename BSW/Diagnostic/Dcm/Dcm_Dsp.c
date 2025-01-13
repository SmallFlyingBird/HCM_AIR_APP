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
**  FILENAME    : Dcm_Dsp.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS    **
**               services which used for bootloader project.                  **
**                                                                            **
**  SPECIFICATION(S) :  UDS Service - ISO14229.      	                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0    20121109  Gary        Initial version
 *  V1.0.1    20160801  cywang      update
 *  V1.0.2    20180511  CChen       update
 *  V1.0.3    20200413  Lianren.Wu  optimization
 *  V1.0.4    20200420  Lianren.Wu  delete micro DCM_SERVICE_22_ENABLE
                                    and DCM_SERVICE_11_ENABLE
 *  V1.0.5    20200425  Lianren.Wu  update 27 service
 *  V1.0.6    20200425  Lianren.Wu  update NRC sequence of 22 service
 *  V1.0.7    20200505  Lianren.Wu  update NRC sequence of 28 34 36 service
 *  V1.0.8    20200512  Lianren.Wu  update NRC sequence of 34 service, and
 *                                  the condition for NRC 31
 *  V1.0.9    20200526  Lianren.Wu  Modify the 34 service, just in the positive
 *                                  response, can operate the service.
 *                                  Modify the 36 service, just in the positive
 *                                  response, can operate the service.
 *  V1.0.10   20200526  Lianren.Wu  Modify the 36 service, if get the same blockID
 *                                  with before, send positive response, no matter
 *                                  the same blockID is the middle or last blockID.
 *  V1.0.11   20231025  Long.Zhu  	1.ajust 2E write interface return condition incorrect value back to NRC22
 *                                  with before, send positive response, no matter
 *                                  2.ajust 34 The service address length overlaps, no wipe is performed
 *                                  , and the address range beyond the wipe responds NRC70.
 *                                  3. NRC12 strong data type error logic
 *                                  4.Dcm_SendPending is changed to a synchronization handler
 *									5.27 Service logic reconstruction.
 *									6.31 Service add check routine control condition.
 *									7.22 The service reads multiple did logical adjustments.
 *									8.31 Service NRC24 is changed to NRC22.
 *									9.34 Use the FL ERR MEMORY service to determine the logical modification.
 *  V1.0.12   20231218  Chunjun.Hua add error code to Dcm_RoutineControlCalloutFct
 *
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:Dcm_Dsp .<br>
  RuleSorce:puhua-rule2024.rcf 1.0.2

    \li PRQA S 3673  Rule 8.13 .<br>
    Reason: The function definition is fixed, including parameter type.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_Dsp.h"
#include "Dcm_Types.h"
#include "Dcm_Internel.h"
#include "Rte_Dcm.h"
#include "PduR_Cfg.h"
#include "Os_User.h"
#include <string.h>
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* data structure for security access */
typedef struct
{
    /* if seed has requested */
    boolean seedReq;
    /* the last requested seed Id */
    uint8 seedIdReq;

    uint8 seedReqCount[DCM_SECURITY_NUM];
    /* seed which generated by SecM module */
    uint8 seed[DCM_27_RANDOMMSG_LEN];
} Dcm_DspSecurityType;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static boolean Dcm_CheckMsgLength(const PduLengthType standardlength, const PduLengthType receivedLength);
static boolean Dcm_CheckMsgLessThanLength(const PduLengthType standardlength, const PduLengthType receivedLength);
static boolean Dcm_CheckSecurityCondition(const Dcm_SecurityType* securitySupportPtr, const uint8 securitySupportNum);
static boolean Dcm_CheckRoutineControlCondition(const Dcm_RoutineControlType *routineControlSupportPtr, const uint8 routineControlSupportNum,Dcm_RoutineControlType routineControlId);
static boolean Dcm_ConditionCheck(void);
static uint8 Dcm_GetSecurityLevelIndex(Dcm_SecurityType secAccessLevel);
static void Dcm_RequestSeed(const Dcm_SecurityRowType* secTablePtr, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
static void Dcm_SendKey(const Dcm_SecurityRowType* secTablePtr, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static Dcm_DspSecurityType dcmDspSec;

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
Dcm_DspProgramType dcmDspProgram;

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <DCM module dsp initialize>
 *
 * <DCM module dsp initialize> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_DspInit(void) 
{
    /* set program condition is allowed */
    dcmDspProgram.condition = (boolean)TRUE;
    /* clear erase block id */
    dcmDspProgram.blockId = (uint8)0x00U;
    /* clear program address */
    dcmDspProgram.address = (uint32)0u;
    dcmDspProgram.First36Service = (boolean)FALSE;
    dcmDspProgram.LastProgRamSize = (uint32)0u;
    /* set seed has not requested */
    dcmDspSec.seedReq = (boolean)FALSE;
    /* clear erase address */
    dcmDspProgram.ErasedAddress = (uint32)0u;
    /* clear erase Length */
    dcmDspProgram.ErasedLength = (uint32)0u;
    dcmDspProgram.Dcm_Requst = DCM_REQ_NONE;
    dcmDspProgram.contionForActiveSBL = FALSE;
}

/******************************************************************************/
/**
 * @brief               <handle service 0x10 session control>
 *
 * <handle service 0x10 session control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>h
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg10(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    uint8 subFunc;
    Dcm_SessionType curSession;
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    boolean positiveRspReq = (boolean)TRUE;
#endif
    boolean sessionFind = (boolean)FALSE;
    Dcm_SessionType sessionValue = (uint8)0x00u;
    boolean processContinue;
    const Dcm_SessionRowType* sessionTablePtr = NULL_PTR;

    /* judge the message is response or not */
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    if ((rxBuff->pduInfo.SduDataPtr[1u] & (uint8)DCM_RSP_NOT_REQUIRED) > (uint8)0x00u)
    {
        positiveRspReq = (boolean)FALSE;
    }
#endif

    /* get sub function */
    subFunc = (rxBuff->pduInfo.SduDataPtr[1u] & (uint8)DCM_RSP_CLEAR_REQUIRED);
    /* find the session */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_SESSION_NUM; iloop++)
    {
        if (subFunc == Dcm_SessionRow[iloop].sessionType)
        {
            sessionTablePtr = &Dcm_SessionRow[iloop];
            sessionValue = subFunc;
            sessionFind = (boolean)TRUE;
            break;
        }
    }

    /* check if received message length is less than two bytes,
     * NRC 13(less length): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    /* if the received message length is Meeting the minimum requirements */
    if ((boolean)TRUE == processContinue)
    {
        /* if did not find sub function, send NRC */
        /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
        processContinue = Dcm_PhyAddrSendNrc(sessionFind, rxBuff->pduId, DCM_E_12_SUBFUNC_NOT_SUPPORTED);
    }
    /* NRC 7E: DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION */
    if ((boolean)TRUE == processContinue)
    {
        /* check if sub function is supported in current session, otherwise send NRC */
        processContinue = Dcm_CheckSessionSupp(
            sessionTablePtr->sessionSupportPtr,
            sessionTablePtr->sessionSupportNbr); 
        /* NRC 7E  DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION */
        processContinue =
            Dcm_PhyAddrSendNrc(processContinue, rxBuff->pduId, DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION);
    }
    /* NRC 13(length not equal): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        /* check if the RX message is equal to the configure value, if not send NRC */
        processContinue = Dcm_CheckMsgLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    }
    /* NRC 33: DCM_E_33_SECURITY_ACCESS_DENIED */
    if ((boolean)TRUE == processContinue)
    {
        /* check if sub-function is supported in current security level, other wise send NRC */
        processContinue = Dcm_CheckSecurityCondition(
            sessionTablePtr->securitySupportPtr,
            sessionTablePtr->securitySupportNbr); 
    }
    /* receive success of 10 service - session control */
    if ((boolean)TRUE == processContinue)
    {
        /* get current security level */
        /* see 14229 V2013 Page 382, Serch KeyWord "Lock ECU" */
        /* end the current send-key sequence */
        dcmDspSec.seedReq = (boolean)FALSE;
        /* Initialize security level */
        Dcm_SetSecurityLevel((uint8)DCM_SECURITY_LOCKED);
        /* get the current session */
        curSession = Dcm_GetSessionMode();
        /* set the session of this request */
        Dcm_SetSessionMode(sessionValue);
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        if ((boolean)TRUE == positiveRspReq)
        {
#endif
            /* set positive response message */
            txBuff->pduInfo.SduDataPtr[0u] = (uint8)0x50u;
            txBuff->pduInfo.SduDataPtr[1u] = (uint8)(rxBuff->pduInfo.SduDataPtr[1u]);
            if (sessionValue == DCM_SESSION_PROGRAMMING)
            {
                txBuff->pduInfo.SduDataPtr[2u] = (uint8)(((uint16) DCM_P2MAX_TIME) >> 8u);
                txBuff->pduInfo.SduDataPtr[3u] = (uint8)(DCM_P2MAX_TIME & 0xFFu) ;
                /* set positive response message */
                dcmDspProgram.Dcm_Requst = DCM_REQ_NONE;
                dcmDspProgram.blockId = (uint8)0x00U;
                dcmDspProgram.LastProgRamSize = (uint32)0U;
                dcmDspProgram.First36Service = FALSE;
            }
            else if (sessionValue == DCM_SESSION_DEFAULT)
            {
                txBuff->pduInfo.SduDataPtr[2u] = (uint8)(((uint16) 50U) >> 8u);
                txBuff->pduInfo.SduDataPtr[3u] = (uint8)(50U & 0xFFu) ;
            }
            else
            {
                /* empty */
            }
            txBuff->pduInfo.SduDataPtr[4u] = (uint8)(((uint16)(DCM_P2SMAX_TIME / 10u)) >> 8u);
            txBuff->pduInfo.SduDataPtr[5u] = (uint8)((DCM_P2SMAX_TIME / 10u) & 0xFFu);
            txBuff->pduInfo.SduLength = (PduLengthType)0x06u;
            Dcm_SendRsp();
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        }
        else
        {
            /* reset service process */
            Dcm_Service_RxFinish();
            Dcm_ServiceFinish();
        }
#endif
		if (sessionValue == DCM_SESSION_PROGRAMMING)
		{
			/* ECU will reset after setting time */
			Rte_Dcm_Appl_EcuReset();
		}
    }
}

/******************************************************************************/
/**
 * @brief               <handle service 0x11 ECU reset>
 *
 * <handle service 0x11 ECU reset> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg11(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    Dcm_ResetType resetValue;
    boolean resetFind = (boolean)FALSE;
    boolean processContinue = (boolean)TRUE;
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    boolean positiveRspReq = (boolean)TRUE;
#endif
    const Dcm_ResetRowType* resetTablePtr = NULL_PTR;

#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    /* check if response is needed */
    if ((rxBuff->pduInfo.SduDataPtr[1u] & (uint8)DCM_RSP_NOT_REQUIRED) > (uint8)0x00u)
    {
        positiveRspReq = (boolean)FALSE;
    }
#endif

    /* get sub function */
    resetValue = (rxBuff->pduInfo.SduDataPtr[1u] & (uint8)DCM_RSP_CLEAR_REQUIRED);
    /* find the session */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_RESET_NUM; iloop++) 
    {
        if (resetValue == Dcm_ResetRow[iloop].resetType)
        {
            resetTablePtr = &Dcm_ResetRow[iloop];
            resetFind = (boolean)TRUE;
            break;
        }
    }
    if ((boolean)TRUE == resetFind)
    {
        processContinue = Dcm_CheckSessionSupp(resetTablePtr->sessionSupportPtr, resetTablePtr->sessionSupportNbr);
        /* NRC 7E  DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION */
        processContinue =
            Dcm_PhyAddrSendNrc(processContinue, rxBuff->pduId, DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION);
    }

    /* check if received message length is less than two bytes,
     * NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        /* check if the length of the message received is right, otherwise send NRC */
        processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    }
    /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
    if ((boolean)TRUE == processContinue)
    {
        /* if did not find sub function, send NRC */
        /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
        processContinue = Dcm_PhyAddrSendNrc(resetFind, rxBuff->pduId, DCM_E_12_SUBFUNC_NOT_SUPPORTED);
    }
    /* NRC 22: DCM_E_22_CONDITIONS_NOT_CORRECT */
    if ((boolean)TRUE == processContinue)
    {
        /* check if condition is correct, otherwise send NRC */
        processContinue = Dcm_ConditionCheck();
    }
    /* NRC 13(length not equal): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        /* check if the RX message is equal to the configure value, if not send NRC */
        processContinue = Dcm_CheckMsgLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    }
    /* NRC 33: DCM_E_33_SECURITY_ACCESS_DENIED */
    if ((boolean)TRUE == processContinue)
    {
        /* check if sub-function is supported in current security level, other wise send NRC */
        processContinue = Dcm_CheckSecurityCondition(
            resetTablePtr->securitySupportPtr,
            resetTablePtr->securitySupportNbr); 
    }
    /* receive success */
    if ((boolean)TRUE == processContinue)
    {
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        if ((boolean)TRUE == positiveRspReq)
        {
#endif
            /* set positive response message */
            txBuff->pduInfo.SduDataPtr[0u] = (uint8)0x51u;
            txBuff->pduInfo.SduDataPtr[1u] = resetValue;
            txBuff->pduInfo.SduLength = (PduLengthType)0x02u;
            Dcm_SendRsp();
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        }
        else
        {
            /* reset service process */
            Dcm_Service_RxFinish();
            Dcm_ServiceFinish();
        }
#endif
        Dcm_StartResetTimer((uint16)10u);
    }
}

#if (DCM_READDID_NUM > 0u)
/******************************************************************************/
/**
 * @brief               <handle service 0x22 read data by identifier>
 *
 * <handle service 0x22 read data by identifier> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg22(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint16 readDid;
    uint16 readLength = 0;
    uint16 actualReadLength;
    boolean processContinue;
    const  Dcm_ReadDidRowType* readTablePtr[DCM_READDID_MAX_NUM];
    uint8 requestRet = E_OK;
    PduLengthType iloop,jloop;
    PduLengthType Did_ReveiveNum = 0;
    uint16 Did_FindNum = 0;
    /* check if received message length is less than request bytes,
     * NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH. */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)3u, rxBuff->pduInfo.SduLength);
    if ((boolean)TRUE == processContinue)
    {
        /* if total length not match, send NRC13 */
        /* NRC 13: DCM_E_31_REQUEST_OUT_OF_RANGE */
        if ((rxBuff->pduInfo.SduLength % 2U) == 0U)
        {
            processContinue = Dcm_PhyAddrSendNrc(FALSE, rxBuff->pduId, (uint8)DCM_E_13_INCORRECT_MESSAGE_LENGTH);
        }
    }
    /* get read data Id */
    Did_ReveiveNum = (rxBuff->pduInfo.SduLength-1u)/2u ;
	if( (((rxBuff->pduInfo.SduLength-1u)/2u) >= (uint16)DCM_READDID_MAX_NUM)
	 && (((rxBuff->pduInfo.SduLength-1u)%2u) == 0x0u) )
	{
		Dcm_SendNrc((uint8)DCM_E_13_INCORRECT_MESSAGE_LENGTH);
        processContinue = (boolean)FALSE;
	}
    if ((boolean)TRUE == processContinue)
    {
        processContinue = (boolean)FALSE;
        for(jloop = 0 ; jloop < Did_ReveiveNum;jloop++)
        {
            readDid = (uint16)(((uint16)rxBuff->pduInfo.SduDataPtr[(jloop * 2u) +1u]) << 8u);
            readDid += (uint16)(rxBuff->pduInfo.SduDataPtr[(jloop*2u) + 2u]);
            
            for (iloop = 0u; iloop < (PduLengthType)DCM_READDID_NUM; iloop++)
            {
                if (readDid == Dcm_ReadDidRow[iloop].DID)
                {
                    readTablePtr[Did_FindNum] = &Dcm_ReadDidRow[iloop];
                    Did_FindNum ++;
                    processContinue = (boolean)TRUE;
                    break;
                }
            }
            if ((boolean)TRUE != processContinue)
            {
                /* if  DID is not find, send NRC31 */
                /* NRC 31: DCM_E_31_REQUEST_OUT_OF_RANGE */
                processContinue = Dcm_PhyAddrSendNrc(FALSE, rxBuff->pduId, (uint8)DCM_E_31_REQUEST_OUT_OF_RANGE);
                break;
            }
        }
    }
    if ((boolean)TRUE == processContinue)
    {
        /* NRC 33: DCM_E_33_SECURITY_ACCESS_DENIED */
        for(iloop = 0 ;iloop < Did_FindNum; iloop++)
        {
            if ((boolean)TRUE == processContinue)
            {
                /* check if DID is supported in current security level, other wise send NRC */
                processContinue = Dcm_CheckSecurityCondition(
                    readTablePtr[iloop]->securitySupportPtr,
                    readTablePtr[iloop]->securitySupportNbr);
            }
            else
            {
                break;
            }
        }
    }

    /* NRC 22: DCM_E_22_CONDITIONS_NOT_CORRECT */
    if ((boolean)TRUE == processContinue)
    {
        /* check if condition is correct, otherwise send NRC */
        processContinue = Dcm_ConditionCheck();
    }
    if ((boolean)TRUE == processContinue)
    {
        /* execute read API, return the read length */
        for(iloop = 0 ;iloop < Did_FindNum; iloop++)
        {
            if ((NULL_PTR != readTablePtr[iloop]->readDataFct))
            {
                txBuff->pduInfo.SduDataPtr[1u + readLength] = (uint8)(readTablePtr[iloop]->DID >> 8u);
                txBuff->pduInfo.SduDataPtr[2u + readLength] = (uint8)(readTablePtr[iloop]->DID  & 0xffu);
                requestRet = readTablePtr[iloop]->readDataFct(&txBuff->pduInfo.SduDataPtr[3u + readLength],&actualReadLength);
                readLength += actualReadLength;

            }
            if(E_OK != requestRet)
            {
                processContinue = (boolean)FALSE ;
				break;
            }
			readLength +=  2u;
            if(readLength >= DCM_TX_BUF_SIZE)
			{
				Dcm_SendNrc((uint8)DCM_E_14_RESPONSE_TOO_LONG);
				processContinue = (boolean)FALSE ;
				break;
			}
            
			
        }
        if (((boolean)TRUE == processContinue) && (E_OK == requestRet))
        {
            /* set positive response message */
            txBuff->pduInfo.SduDataPtr[0u] = (uint8)0x62u;
            txBuff->pduInfo.SduLength = (PduLengthType)((PduLengthType)1u + (PduLengthType)readLength);
            Dcm_SendRsp();
        }
        
    }
}
#endif

#if (DCM_WRITEDID_NUM > 0u)
/*****************************************************************************/
/**
 * @brief               <handle service 0x2E write data by identifier>
 *
 * <handle service 0x2E write data by identifier> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg2E(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)/*PRQA S 3673*/
{
    (void)txBuff;
    uint8 iloop;
    uint16 writeDid;
    uint8 writeRet;
    boolean didFind = (boolean)FALSE;
    boolean processContinue;
    const Dcm_WriteDidRowType* writeTablePtr = NULL_PTR;

    /* get write data Id */
    writeDid = ((uint16)rxBuff->pduInfo.SduDataPtr[1] << 8u);
    writeDid += (uint16)rxBuff->pduInfo.SduDataPtr[2];
    /* find write data Id in configured write data table */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_WRITEDID_NUM; iloop++) 
    {
        if (writeDid == Dcm_WriteDidRow[iloop].DID)
        {
            writeTablePtr = &Dcm_WriteDidRow[iloop];
            didFind = (boolean)TRUE;
            break;
        }
    }

    /* check if received message length is less than request bytes,`
     * NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH. */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)4u, rxBuff->pduInfo.SduLength);
    if ((boolean)TRUE == processContinue)
    {
        /* if did not find DID, send NRC31 */
        /* NRC 31: DCM_E_31_REQUEST_OUT_OF_RANGE */
        processContinue = Dcm_PhyAddrSendNrc(didFind, rxBuff->pduId, (uint8)DCM_E_31_REQUEST_OUT_OF_RANGE);
    }
    /* NRC 13(length not equal): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        /* check if the RX message is equal to the configure value, if not send NRC */
        processContinue =
            Dcm_CheckMsgLength((PduLengthType)writeTablePtr->dataLength + 0x03u, rxBuff->pduInfo.SduLength); 
    }
    /* NRC 33: DCM_E_33_SECURITY_ACCESS_DENIED */
    if ((boolean)TRUE == processContinue)
    {
        /* check if sub function is supported in current security level, otherwise send NRC33 */
        processContinue = Dcm_CheckSecurityCondition(
            writeTablePtr->securitySupportPtr,
            writeTablePtr->securitySupportNbr); 
    }
    /* NRC 22: DCM_E_22_CONDITIONS_NOT_CORRECT */
    if ((boolean)TRUE == processContinue)
    {
        /* check if condition is correct, otherwise send NRC */
        processContinue = Dcm_ConditionCheck();
    }
    if ((boolean)TRUE == processContinue)
    {
        /* execute write API, return read length */
        if (NULL_PTR != writeTablePtr->writeDataFct) 
        {
            writeRet =
                writeTablePtr->writeDataFct(&rxBuff->pduInfo.SduDataPtr[3], writeTablePtr->dataLength); 
        }
        else
        {
            writeRet = (uint8)FL_FAILED;
        }

        if ((uint8)FL_CONDITIONS_NOT_CORRECT == writeRet)
        {
            /* set negative response message */
            /* NRC 22  DCM_E_22_CONDITIONS_NOT_CORRECT */
            Dcm_SendNrc((uint8)DCM_E_22_CONDITIONS_NOT_CORRECT); 
        }
        else if((uint8)E_OK != writeRet)
        {
            /* program finger print failure */
            /* set negative response message */
            /* NRC 72 DCM_E_72_GENERAL_PROGRAMMING_FAILURE */
            Dcm_SendNrc((uint8)DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
        }
        else
        {
        	/*empty*/
        }
    }
}
#endif

/******************************************************************************/
/**
 * @brief               <handle service 0x27 security access>
 *
 * <handle service 0x27 security access> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg27(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    boolean secDelayTime;
    uint16 checkLength;
    Dcm_SessionType secId;
    boolean secIdFind = (boolean)FALSE;
    boolean processContinue;
    const Dcm_SecurityRowType* secTablePtr = NULL_PTR;
    uint8 secAcLevIndex;
/*     const FL_SecurityAccessNvmInfoType *FL_SecurityAccessNvmInfoPtr;

    FL_SecurityAccessNvmInfoPtr = FL_GetSecAcNvmInfo(); */

    secId = rxBuff->pduInfo.SduDataPtr[1u];
    /* find sub function Id in configured security table */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_SECURITY_NUM; iloop++) 
    {
        /* the request Security Id always can be reqSeedId or sendKeyId*/
        if ((secId == Dcm_SecurityRow[iloop].reqSeedId) || (secId == Dcm_SecurityRow[iloop].sendKeyId))
        {
            secTablePtr = &Dcm_SecurityRow[iloop];
            secIdFind = (boolean)TRUE;
            break;
        }
    }

    /* check if received message length is less than two bytes,
     * NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH. */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)2u, rxBuff->pduInfo.SduLength);
    if ((boolean)TRUE == processContinue)
    {
        /* if did not find sub function, send NRC */
        /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
        processContinue = Dcm_PhyAddrSendNrc(secIdFind, rxBuff->pduId, DCM_E_12_SUBFUNC_NOT_SUPPORTED);
    }
    /* if find the reqSeedId or sendKeyId */
    if ((boolean)TRUE == processContinue)
    {
        secAcLevIndex = Dcm_GetSecurityLevelIndex(secTablePtr->secAccessLevel);
        /* if find is reqSeedId */
        if (secId == secTablePtr->reqSeedId) 
        {
            /* the length of Seed*/
            checkLength = (uint16)2u;
            /* NRC 13(length not equal): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
            /* check if the length of message received is right, otherwise send NRC 13 */
            processContinue = Dcm_CheckMsgLength((PduLengthType)checkLength, rxBuff->pduInfo.SduLength);
            
            if ((boolean)TRUE == processContinue)
            {
	            secDelayTime = Dcm_GetSecurityTimerExpired(secAcLevIndex);
	            /* check if security timer is expired */
	            if ((boolean)FALSE == secDelayTime)
	            {
	                /* security access timer delay is not expired */
	                /* set negative response message */
	                /* NRC 37 DCM_E_37_REQUIRED_TIME_DELAY_NOT_EXPIRED */
	                Dcm_SendNrc((uint8)DCM_E_37_REQUIRED_TIME_DELAY_NOT_EXPIRED);
	                processContinue = (boolean)FALSE;
	            }
            }
            /* execute generate seed */
            if ((boolean)TRUE == processContinue)
            {
                Dcm_RequestSeed(secTablePtr, rxBuff, txBuff);
            }
        }
        /* if find is sendKeyId */
        else if (secId == secTablePtr->sendKeyId) 
        {
            /* the length of key */
            checkLength = (uint16)secTablePtr->KeyLength + 2u; 
            /* NRC 13(length not equal): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
            /* check if the length of message received is right, otherwise send NRC 13 */
            processContinue = Dcm_CheckMsgLength((PduLengthType)checkLength, rxBuff->pduInfo.SduLength);
            if ((boolean)TRUE == processContinue)
            {
          		Dcm_SendKey(secTablePtr, rxBuff, txBuff);
            }
        }
        else
        {
            /* empty */
        }
    }
}

#if (DCM_COM_CONTROL_NUM > 0u)
/******************************************************************************/
/**
 * @brief               <handle service 0x28 communication control>
 *
 * <handle service 0x28 communication control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg28(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    Dcm_ComControlType controlValue;
    boolean controlTypeFind = (boolean)FALSE;
    boolean processContinue;
    Dcm_CommunicationType communicationType;
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    boolean positiveRspReq = (boolean)TRUE;
#endif
    const Dcm_ComControlRowType* comTablePtr = NULL_PTR;

#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    /* check if response is needed */
    if ((rxBuff->pduInfo.SduDataPtr[1u] & (uint8)DCM_RSP_NOT_REQUIRED) > (uint8)0x00u)
    {
        positiveRspReq = (boolean)FALSE;
    }
#endif

    controlValue = (uint8)(rxBuff->pduInfo.SduDataPtr[1u] & DCM_RSP_CLEAR_REQUIRED);
    /* find the control type */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_COM_CONTROL_NUM; iloop++)
    {
        if (controlValue == Dcm_ComControlRow[iloop].controlType)
        {
            comTablePtr = &Dcm_ComControlRow[iloop];
            controlTypeFind = (boolean)TRUE;
            break;
        }
    }

    /*  NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    /* check if the length of message received is right, otherwise send NRC */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
    if ((boolean)TRUE == processContinue)
    {
        /* if did not find sub function, send NRC */
        /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
        processContinue = Dcm_PhyAddrSendNrc(controlTypeFind, rxBuff->pduId, DCM_E_12_SUBFUNC_NOT_SUPPORTED);
    }
    /* NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        /* check if the RX message is equal to the configure value, if not send NRC */
        processContinue = Dcm_CheckMsgLength((PduLengthType)3u, rxBuff->pduInfo.SduLength);
    }
    /* NRC 33:DCM_E_33_SECURITY_ACCESS_DENIED */
    if ((boolean)TRUE == processContinue)
    {
        /* check if sub-function is supported in current security level, other wise send NRC */
        processContinue = Dcm_CheckSecurityCondition(
            comTablePtr->securitySupportPtr,
            comTablePtr->securitySupportNbr); 
    }
    /* NRC 31:DCM_E_31_REQUEST_OUT_OF_RANGE */
    if ((boolean)TRUE == processContinue)
    {
        communicationType = rxBuff->pduInfo.SduDataPtr[2];
        controlTypeFind = (boolean)FALSE;
        /* check if communication type is correct */
        for (iloop = (uint8)0u; iloop < (uint8)DCM_COM_CONTROL_NUM; iloop++)
        {
            if (communicationType == Dcm_ComControlRow[iloop].communicationType)
            {
                controlTypeFind = (boolean)TRUE;
                break;
            }
        }
        /* if communicationType is error, send NRC31 */
        /* NRC 31: DCM_E_31_REQUEST_OUT_OF_RANGE */
        processContinue = Dcm_PhyAddrSendNrc(controlTypeFind, rxBuff->pduId, (uint8)DCM_E_31_REQUEST_OUT_OF_RANGE);
        if ((boolean)TRUE == processContinue)
        {
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
            if ((boolean)TRUE == positiveRspReq)
            {
#endif
                /* set positive response message */
                txBuff->pduInfo.SduDataPtr[0u] = (uint8)0x68u;
                txBuff->pduInfo.SduDataPtr[1u] = rxBuff->pduInfo.SduDataPtr[1u];
                txBuff->pduInfo.SduLength = (PduLengthType)0x02u;
                Dcm_SendRsp();
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
            }
            else
            {
                /* reset service process */
                Dcm_Service_RxFinish();
                Dcm_ServiceFinish();
            }
#endif
        }
    }
}
#endif

#if (DCM_ROUTINE_CONTROL_NUM > 0u)
/******************************************************************************/
/**
 * @brief               <handle service 0x31 routine control>
 *
 * <handle service 0x31 routine control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg31(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    uint8 routineControlValue;
    uint16 routineIdValue;
    boolean processContinue;
    boolean routineIdFind = (boolean)FALSE;
    const Dcm_RoutineControlRowType* routineTablePtr = NULL_PTR;

    /* get routine Id */
    routineIdValue = ((uint16)rxBuff->pduInfo.SduDataPtr[2] << 8U);
    routineIdValue += (uint16)rxBuff->pduInfo.SduDataPtr[3];
    /* find routine Id in routine table */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_ROUTINE_CONTROL_NUM; iloop++)
    {
        if (routineIdValue == Dcm_RoutineControlRow[iloop].routineId)
        {
            routineTablePtr = &Dcm_RoutineControlRow[iloop];
            routineIdFind = (boolean)TRUE;
            break;
        }
    }

    /* check if received message length is less than needed bytes,
     * NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)0x04u, rxBuff->pduInfo.SduLength);
    /* NRC 31: DCM_E_SUBFUNCTION_NOT_FIND */
    if ((boolean)TRUE == processContinue)
    {
        /* if routine Id is not find, send NRC31 */
        processContinue = Dcm_PhyAddrSendNrc(routineIdFind, rxBuff->pduId, (uint8)DCM_E_31_REQUEST_OUT_OF_RANGE);
    }
    /* NRC 31: DCM_E_31_REQUEST_OUT_OF_RANGE */
    if ((boolean)TRUE == processContinue)
    {
        /* check if RoutineID is supported in current session, otherwise send NRC31 */
        processContinue = Dcm_CheckSessionSupp(
            routineTablePtr->sessionSupportPtr,
            routineTablePtr->sessionSupportNbr); 
        processContinue = Dcm_PhyAddrSendNrc(processContinue, rxBuff->pduId, DCM_E_31_REQUEST_OUT_OF_RANGE);
    }
    /* NRC 33: DCM_E_33_SECURITY_ACCESS_DENIED */
    if ((boolean)TRUE == processContinue)
    {
        /* check if sub function is supported in current security level, otherwise send NRC33 */
        processContinue = Dcm_CheckSecurityCondition(
            routineTablePtr->securitySupportPtr,
            routineTablePtr->securitySupportNbr); 
    }
    /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
    if ((boolean)TRUE == processContinue)
    {
        /* get routine control type */
        routineControlValue = rxBuff->pduInfo.SduDataPtr[1];

        /* Check routine control condition.*/
        processContinue = Dcm_CheckRoutineControlCondition(
        		routineTablePtr->routineControlSupportPtr,
                routineTablePtr->routineControlSupportNbr,
				routineControlValue);

        /* check if sub function is start routine */
        if ((boolean)FALSE == processContinue)
        {
            /* sub function is not supported,send NRC0x12 */
            processContinue =
                Dcm_PhyAddrSendNrc((boolean)FALSE, rxBuff->pduId, DCM_E_12_SUBFUNC_NOT_SUPPORTED);
        }
    }
    /* NRC 13(length not equal): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        /* check if the length of message received is right, otherwise send NRC0x13*/
        processContinue = Dcm_CheckMsgLength(
            0x04u + (PduLengthType)routineTablePtr->optionLength,
            rxBuff->pduInfo.SduLength); 
    }
    processContinue = TRUE; /*for debug*/
    /* receive success */
    if ((boolean)TRUE == processContinue)
    {
        /* set positive response message */
        txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
        txBuff->pduInfo.SduDataPtr[1] = rxBuff->pduInfo.SduDataPtr[1];
        txBuff->pduInfo.SduDataPtr[2] = rxBuff->pduInfo.SduDataPtr[2];
        txBuff->pduInfo.SduDataPtr[3] = rxBuff->pduInfo.SduDataPtr[3];
        /* execute routine */
        routineTablePtr->routineControl(rxBuff, txBuff); 
    }
}
#endif
/******************************************************************************/
/**
 * @brief               <handle service 0x3E test precent>
 *
 * <handle service 0x3E test present> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg3E(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    uint8 subFunc;
    boolean processContinue;
    boolean testPresentFind = (boolean)FALSE;
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    boolean positiveRspReq = (boolean)TRUE;
#endif

#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    /* check if response is needed */
    if ((rxBuff->pduInfo.SduDataPtr[1u] & (uint8)DCM_RSP_NOT_REQUIRED) > (uint8)0x00u)
    {
        positiveRspReq = (boolean)FALSE;
    }
#endif

    subFunc = (uint8)(rxBuff->pduInfo.SduDataPtr[1] & DCM_RSP_CLEAR_REQUIRED);
    /* find test present sub function */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_TESTPRESENT_NUM; iloop++) 
    {
        if (subFunc == Dcm_testPresentRow[iloop].zeroSubFunc)
        {
            testPresentFind = (boolean)TRUE;
            break;
        }
    }

    /* NRC 13: DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    /* check if the length of message received is right, otherwise send NRC */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    /* NRC 12:DCM_E_12_SUBFUNC_NOT_SUPPORTED */
    if ((boolean)TRUE == processContinue)
    {
        /* if did not find sub function, send NRC */
        /* NRC 12:DCM_E_12_SUBFUNC_NOT_SUPPORTED */
        processContinue = Dcm_PhyAddrSendNrc(testPresentFind, rxBuff->pduId, DCM_E_12_SUBFUNC_NOT_SUPPORTED);
    }
    /* NRC 13:DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        /* check if the length of message received is right, otherwise send NRC */
        processContinue = Dcm_CheckMsgLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    }
    if ((boolean)TRUE == processContinue)
    {
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        if ((boolean)TRUE == positiveRspReq)
        {
#endif
            /* set positive response message */
            txBuff->pduInfo.SduDataPtr[0u] = (uint8)0x7Eu;
            txBuff->pduInfo.SduDataPtr[1u] = rxBuff->pduInfo.SduDataPtr[1u];
            txBuff->pduInfo.SduLength = (PduLengthType)0x02u;
            Dcm_SendRsp();
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        }
        else
        {
            /* reset service process */
            Dcm_Service_RxFinish();
            Dcm_ServiceFinish();
        }
#endif
    }
}

#if (DCM_DTC_SET_NUM > 0u)
/******************************************************************************/
/**
 * @brief               <handle service 0x85 set DTC control>
 *
 * <handle service 0x85 set DTC control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_RecvMsg85(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    Dcm_DTCSettingType DTCsetType;
    boolean DTCsetTypeFind = (boolean)FALSE;
    boolean processContinue;
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    boolean positiveRspReq = (boolean)TRUE;
#endif

    const Dcm_DTCSettingRowType* DTCsetTablePtr = NULL_PTR;

#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
    /* check if response is needed */
    if ((rxBuff->pduInfo.SduDataPtr[1u] & (uint8)DCM_RSP_NOT_REQUIRED) > (uint8)0u)
    {
        positiveRspReq = (boolean)FALSE;
    }
#endif

    /* get sub function */
    DTCsetType = (uint8)(rxBuff->pduInfo.SduDataPtr[1u] & DCM_RSP_CLEAR_REQUIRED);
    /* find the session */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_DTC_SET_NUM; iloop++)
    {
        if (DTCsetType == Dcm_DTCSettingRow[iloop].DTCSet)
        {
            DTCsetTablePtr = &Dcm_DTCSettingRow[iloop];
            DTCsetTypeFind = (boolean)TRUE;
            break;
        }
    }

    /* NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    /* check if the length of message received is right, otherwise send NRC */
    processContinue = Dcm_CheckMsgLessThanLength((PduLengthType)0x02u, rxBuff->pduInfo.SduLength);
    /* if did not find sub function, send NRC */
    /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
    if ((boolean)TRUE == processContinue)
    {
        /* if did not find sub function, send NRC */
        /* NRC 12: DCM_E_12_SUBFUNC_NOT_SUPPORTED */
        processContinue = Dcm_PhyAddrSendNrc(DTCsetTypeFind, rxBuff->pduId, DCM_E_12_SUBFUNC_NOT_SUPPORTED);
    }
    if ((boolean)TRUE == processContinue)
    {
        /* check if condition is correct, otherwise send NRC */
        processContinue = Dcm_ConditionCheck();
    }
    if ((boolean)TRUE == processContinue)
    {
        processContinue =
            Dcm_CheckSessionSupp(DTCsetTablePtr->sessionSupportPtr, DTCsetTablePtr->sessionSupportNbr); 
        /* NRC 7E  DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION */
        processContinue =
            Dcm_PhyAddrSendNrc(processContinue, rxBuff->pduId, DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION);
    }
    /* NRC 13(less length ): DCM_E_13_INCORRECT_MESSAGE_LENGTH */
    if ((boolean)TRUE == processContinue)
    {
        processContinue = Dcm_CheckMsgLength((PduLengthType)2u, rxBuff->pduInfo.SduLength);
    }
    if ((boolean)TRUE == processContinue)
    {
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        if ((boolean)TRUE == positiveRspReq)
        {
#endif
            /* set positive response message */
            txBuff->pduInfo.SduDataPtr[0u] = (uint8)0xC5u;
            txBuff->pduInfo.SduDataPtr[1u] = rxBuff->pduInfo.SduDataPtr[1u];
            txBuff->pduInfo.SduLength = (PduLengthType)0x02u;
            Dcm_SendRsp();
#if (STD_ON == DCM_SUPPRESS_POS_SUPPORT)
        }
        else
        {
            /* reset service process */
            Dcm_Service_RxFinish();
            Dcm_ServiceFinish();
        }
#endif
    }
}
#endif

#if (DCM_WRITEDID_NUM > 0)
/******************************************************************************/
/**
 * @brief               <handle service 0x2E write data pending finish>
 *
 * <handle service 0x2E write data pending finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <errorCode (IN),rxBuff (IN),>
 * @param[out]          <NONE>
 * @param[in/out]       <txBuff (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_Pending2E(const uint8 errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    /* check if write data successful */
    if ((uint8)E_OK == errorCode)
    {
        /* set positive response message */
        txBuff->pduInfo.SduDataPtr[0] = (uint8)0x6Eu;
        txBuff->pduInfo.SduDataPtr[1] = rxBuff->pduInfo.SduDataPtr[1];
        txBuff->pduInfo.SduDataPtr[2] = rxBuff->pduInfo.SduDataPtr[2];
        txBuff->pduInfo.SduLength = (PduLengthType)0x03u;
        Dcm_SendRsp();
    }
    else
    {
        /* program finger print failure */
        /* set negative response message */
        /* NRC 72  DCM_E_72_GENERAL_PROGRAMMING_FAILURE */
        Dcm_SendNrc((uint8)DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
    }
}
#endif

/******************************************************************************/
/**
 * @brief               <handle service 0x31 routine control pending finish>
 *
 * <handle service 0x31 routine control pending finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <errorCode (IN),rxBuff (IN),>
 * @param[out]          <NONE>
 * @param[in/out]       <txBuff (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_Pending31(const uint8 errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff) 
{
    uint8 iloop;
    uint16 RoutineID;
    boolean routineIdFind = (boolean)FALSE;
    const Dcm_RoutineControlRowType* routineTablePtr;

    RoutineID = ((uint16)(rxBuff->pduInfo.SduDataPtr[2]) << 8u) + ((uint16)rxBuff->pduInfo.SduDataPtr[3]);

    /* find routine Id in routine table */
    for (iloop = (uint8)0u; iloop < (uint8)DCM_ROUTINE_CONTROL_NUM; iloop++)
    {
        if (RoutineID == Dcm_RoutineControlRow[iloop].routineId)
        {
            routineTablePtr = &Dcm_RoutineControlRow[iloop];
            routineIdFind = (boolean)TRUE;
            break;
        }
    }
    if ((boolean)TRUE == routineIdFind)
    {
        if (NULL_PTR != routineTablePtr->routineControlCallout)
        {
            routineTablePtr->routineControlCallout(errorCode, rxBuff, txBuff);
        }
    }
    else
    {
        /* set routine control execute failing */
        txBuff->pduInfo.SduDataPtr[4] = (uint8)0x01u;
    }
    txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
    txBuff->pduInfo.SduDataPtr[1] = rxBuff->pduInfo.SduDataPtr[1];
    txBuff->pduInfo.SduDataPtr[2] = rxBuff->pduInfo.SduDataPtr[2];
    txBuff->pduInfo.SduDataPtr[3] = rxBuff->pduInfo.SduDataPtr[3];
    
    Dcm_SendRsp();
}
/********************************************************************************/
/***
 * @brief           :Pending Fuc
 *
 * Service ID       : <Pending Fuc>
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <NONE>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
void Dcm_SendPending(void)
{
    /* set negative response message */
    /* NRC 78  DCM_E_78_PENDING */
    Dcm_SendNrc((uint8)DCM_E_78_PENDING);
    Dcm_StartP2eTimer((uint16)DCM_P2SMAX_TIME);
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <check if receive message length is correct>
 *
 * <check if receive message length is correct> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <minlength (IN),receivedLength (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
static boolean Dcm_CheckMsgLength(const PduLengthType standardlength, const PduLengthType receivedLength)
{
    boolean retVal = (boolean)TRUE;
    if (receivedLength != standardlength)
    {
        retVal = (boolean)FALSE;
        /* service length is not correct */
        /* set negative response message */
        /* NRC 13  DCM_E_13_INCORRECT_MESSAGE_LENGTH */
        Dcm_SendNrc((uint8)DCM_E_13_INCORRECT_MESSAGE_LENGTH);
    }
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <check if receive message length is correct>
 *
 * <check if receive message length is correct> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <minlength (IN),receivedLength (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
static boolean Dcm_CheckMsgLessThanLength(const PduLengthType standardlength, const PduLengthType receivedLength)
{
    boolean retVal = (boolean)TRUE;
    if (receivedLength < standardlength)
    {
        retVal = (boolean)FALSE;
        /* service length is not correct */
        /* set negative response message */
        /* NRC 13  DCM_E_13_INCORRECT_MESSAGE_LENGTH */
        Dcm_SendNrc((uint8)DCM_E_13_INCORRECT_MESSAGE_LENGTH);
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <check if service is supported in current security level>
 *
 * <check if service is supported in current security level> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <secLevTable (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
static boolean Dcm_CheckSecurityCondition(const Dcm_SecurityType* securitySupportPtr, const uint8 securitySupportNum)
{
    boolean retVal;
    retVal = Dcm_CheckSecuritySupp(securitySupportPtr, securitySupportNum);
    if ((boolean)FALSE == retVal)
    {
        /* security condition is not correct */
        /* set negative response message */
        /* NRC 33  DCM_E_33_SECURITY_ACCESS_DENIED */
        Dcm_SendNrc((uint8)DCM_E_33_SECURITY_ACCESS_DENIED);
    }
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <Check routine control condition.>
 *
 * <Check routine control condition.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <routineControlSupportPtr (IN)
 * 						routineControlSupportNum (IN)
 * 						routineControlId (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
static boolean Dcm_CheckRoutineControlCondition(const Dcm_RoutineControlType *routineControlSupportPtr, const uint8 routineControlSupportNum,Dcm_RoutineControlType routineControlId)
{
    uint8 iloop;
    boolean retVal = (boolean)FALSE;
    /* Loop until all members of the configuration table are iterated */
    for (iloop = (uint8)0U; iloop < routineControlSupportNum; iloop++)
    {
        /* Check if the current session mode matches the current configuration item */
        if (routineControlId == routineControlSupportPtr[iloop])
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
 * @brief               <check if condition is correct in service>
 *
 * <check if condition is correct in service> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <condition (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
static boolean Dcm_ConditionCheck(void)
{
    /* defined by user, the following is an example */
    boolean condition = (boolean)TRUE;
    if ((boolean)FALSE == condition) 
    {
        /* set negative response message */
        /* NRC 22  DCM_E_22_CONDITIONS_NOT_CORRECT */
        Dcm_SendNrc((uint8)DCM_E_22_CONDITIONS_NOT_CORRECT);
    }
    return (boolean)TRUE;
}

/******************************************************************************/
/**
 * @brief               <Gets the current security level index.>
 *
 * <Gets the current security level index> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <secAccessLevel (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint8>
 */
/******************************************************************************/
static uint8 Dcm_GetSecurityLevelIndex(Dcm_SecurityType secAccessLevel)
{
    uint8 iloop;
    uint8 secAcLevIndex = 0xffu;
    for (iloop = (uint8)0u; iloop < (uint8)DCM_SECURITY_NUM; iloop++) 
    {
        if (secAccessLevel == Dcm_SecurityRow[iloop].secAccessLevel)
        {
            secAcLevIndex = iloop;
            break;
        }
    }
    return secAcLevIndex;
}

/******************************************************************************/
/**
 * @brief               <execute generate seed>
 *
 * <execute generate seed> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <secTablePtr (IN),rxBuff (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <txBuff (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_RequestSeed(const Dcm_SecurityRowType* secTablePtr, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    Dcm_SecurityType secLevel;
    
    boolean processContinue = TRUE;
    secLevel = Dcm_GetSecurityLevel();
  
    /* check if seed has requested */
    if (secTablePtr->secAccessLevel == secLevel)
    {
        /* if seed has requested, seed is 0x00 */
        memset((uint8*)(&dcmDspSec.seed[0]), (uint8)0x0u, secTablePtr->SeedLength);
    }
    else
    {
        dcmDspSec.seedReq = (boolean)TRUE;
        /* record received seed Id */
        dcmDspSec.seedIdReq = secTablePtr->reqSeedId;
        /* execute generate seed */
        (void)secTablePtr->generateSeed(dcmDspSec.seed, secTablePtr->SeedLength);
    }
    if(processContinue == TRUE)
    {
        /* set positive response message */
        txBuff->pduInfo.SduDataPtr[0u] = (uint8)0x67u;
        txBuff->pduInfo.SduDataPtr[1u] = rxBuff->pduInfo.SduDataPtr[1u];
        memcpy(&txBuff->pduInfo.SduDataPtr[2u], dcmDspSec.seed, secTablePtr->SeedLength);
        txBuff->pduInfo.SduLength = (PduLengthType)0x02u + secTablePtr->SeedLength;
        Dcm_SendRsp();
    }
}

/******************************************************************************/
/**
 * @brief               <execute compare key>
 *
 * <execute compare key> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <secTablePtr (IN),rxBuff (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <txBuff (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_SendKey(const Dcm_SecurityRowType* secTablePtr, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    uint8 compareStatus;
    uint8 secAcLevIndex;

    secAcLevIndex = Dcm_GetSecurityLevelIndex(secTablePtr->secAccessLevel);
    /* Check if seed has requested */
    if ((dcmDspSec.seedIdReq == secTablePtr->reqSeedId)
    	&&(TRUE == dcmDspSec.seedReq))
    {
        dcmDspSec.seedReq = FALSE;
#if(BL_BUS_MODE == BL_BUS_MODE_LIN)
        while(Dcm_GetTxStatus() != DCM_BUFF_FREE){}   /* xzq:this type of statement is very dangerous.*/
#endif
        /* compare key
         * rxBuff->pduInfo.SduDataPtr[2u] is the start address of key. */
        compareStatus = secTablePtr->compareKey(
            &rxBuff->pduInfo.SduDataPtr[2u],
            secTablePtr->KeyLength,
            dcmDspSec.seed,
            secTablePtr->SeedLength);
        /* check if compare key successful */
        if ((uint8)E_OK == compareStatus)
        {
        	/* clear the attempt counter */
        	App_UninitRam[secAcLevIndex] = 0;
            /* set to requested security level */
            Dcm_SetSecurityLevel(secTablePtr->secAccessLevel);
            /* set positive response message */
            txBuff->pduInfo.SduDataPtr[0u] = (uint8)0x67u;
            txBuff->pduInfo.SduDataPtr[1u] = rxBuff->pduInfo.SduDataPtr[1u];
            txBuff->pduInfo.SduLength = (PduLengthType)0x02u;
            Dcm_SendRsp();
        }
        else /* compare key failed */
        {
            /* the invalid key triggers counter cumulation */
            App_UninitRam[secAcLevIndex]++;
            /* security access attempt num is overflow */
            if (App_UninitRam[secAcLevIndex] < (uint8)DCM_SECURITY_ATTEMPT_NUM)
            {
                /* NRC 35 DCM_E_35_INVALID_KEY*/
                Dcm_SendNrc((uint8)DCM_E_35_INVALID_KEY);
            }
            else
            {
                /* start security timer */
                Dcm_StartSecurityTimer(secAcLevIndex, (uint32)DCM_SECURITY_TIME);
                /* NRC 36 DCM_E_36_EXCEED_NUMBER_OF_ATTEMPTS*/
                Dcm_SendNrc((uint8)DCM_E_36_EXCEED_NUMBER_OF_ATTEMPTS);
            }
        }
        
    }
    else
    {
        /* key level not match to req seed level */
        /* NRC 24 DCM_E_24_REQUEST_SEQUENCE_ERROR */
        Dcm_SendNrc((uint8)DCM_E_24_REQUEST_SEQUENCE_ERROR);
    }
}
