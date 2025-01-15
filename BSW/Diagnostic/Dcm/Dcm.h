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
**  FILENAME    : Dcm.h                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : Macro and function declarations for Dcm Module.             **
**                                                                            **
**  SPECIFICATION(S) :  UDS Service - ISO14229.     	                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *   V1.0.0    20121109     Gary            Initial version
 *   V1.0.1    20160801    cywang           update
 *   V1.0.2    20180511    CChen            update
 *   V1.0.3    20191211    LianRen.wu       optimization
 */
#ifndef DCM_H
#define DCM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_Types.h"
#include "PduR_Cfg.h"
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/** Negative response code */
typedef uint8 Dcm_NrcType;
#define DCM_E_10_GENERAL_REJECT                            0x10u
#define DCM_E_11_SERVICE_NOT_SUPPORTED                     0x11u
#define DCM_E_12_SUBFUNC_NOT_SUPPORTED                     0x12u
#define DCM_E_13_INCORRECT_MESSAGE_LENGTH                  0x13u
#define DCM_E_14_RESPONSE_TOO_LONG                         0x14u
#define DCM_E_21_BUSY_REPEAT_REQUEST                       0x21u
#define DCM_E_22_CONDITIONS_NOT_CORRECT                    0x22u
#define DCM_E_24_REQUEST_SEQUENCE_ERROR                    0x24u
#define DCM_E_31_REQUEST_OUT_OF_RANGE                      0x31u
#define DCM_E_33_SECURITY_ACCESS_DENIED                    0x33u
#define DCM_E_35_INVALID_KEY                               0x35u
#define DCM_E_36_EXCEED_NUMBER_OF_ATTEMPTS                 0x36u
#define DCM_E_37_REQUIRED_TIME_DELAY_NOT_EXPIRED           0x37u
#define DCM_E_70_UPLOAD_DOWNLOAD_NOT_ACCEPTED              0x70u
#define DCM_E_71_TRANSFER_DATA_SUSPENDED                   0x71u
#define DCM_E_72_GENERAL_PROGRAMMING_FAILURE               0x72u
#define DCM_E_73_WRONG_BLOCK_SEQUENCE_COUNTER              0x73u
#define DCM_E_78_PENDING                                   0x78u
#define DCM_E_7E_SUBFUNCTION_NOT_SUPPORT_IN_ACTIVE_SESSION 0x7Eu
#define DCM_E_7F_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION   0x7Fu
#define DCM_E_83_ENGINE_IS_RUNNING                         0x83u
#define DCM_E_84_ENGINE_IS_NOT_RUNNING                     0x84u
#define DCM_E_85_ENGINE_RUN_TIME_TOO_LOW                   0x85u
#define DCM_E_92_VOLTAGE_TOO_LOW                           0x92u
#define DCM_E_93_VOLTAGE_TOO_HIGH                          0x93u

/** SID negative response */
#define DCM_RSP_SID_NRC 0x7Fu

/** if response needed */
#define DCM_RSP_REQUIRED       0x00u
#define DCM_RSP_NOT_REQUIRED   0x80u
#define DCM_RSP_CLEAR_REQUIRED 0x7Fu

/** address mode support mask type
 * physical addressing  :0x01u
 * functional addressing: 0x02
 */
#define DCM_PHYSICAL_ADDRESSING   0x01u
#define DCM_FUNCTIONAL_ADDRESSING 0x02u
#define DCM_PHY_FUNC_ADDRESSING   0x03u
#define DCM_INVALID_ADDRESSING    0x04u

/** service 10 diagnosticSessionType */
#define DCM_SESSION_DEFAULT     0x01u
#define DCM_SESSION_PROGRAMMING 0x02u
#define DCM_SESSION_EXTEND      0x03u

/** service 11 resetType */
#define DCM_HARD_RESET 0x01u

/** service 31 routine control type */
#define DCM_START_ROUTINE    0x01u
#define DCM_STOP_ROUTINE     0x02u
#define DCM_RESULT_ROUTINE   0x03u

/** service 28 communication control */
#define DCM_ENABLE_RXANDTX           0x00u
#define DCM_ENABLE_RXANDDISTX        0x01u
#define DCM_DISABLE_RXANDTX          0x03u

#define DCM_NORMAL_COM_MESSAGES      0x01u
#define DCM_NMANDNORMAL_COM_MESSAGES 0x03u

/** service 3E test present type */
#define DCM_ZERO_SUB_FUNC 0x00u

/** service 85 DTC setting type */
#define DCM_DTC_SETTING_ON  0x01u
#define DCM_DTC_SETTING_OFF 0x02u

/** service 27 security access lock type */
#define DCM_SECURITY_LOCKED 0x00u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** Dcm communicate status */
typedef struct
{
    /* DCM main rx buffer */
    Dcm_BuffType rxBuff;
    /* DCM main tx buffer */
    Dcm_BuffType txBuff;
    /* DCM current service */
    const Dcm_ServiceTableType* curServicePtr;
    /* if there is a new service request is not processed */
    boolean reqNew;
    /* if there is response is finished */
    boolean respFinished;
    /* DCM P3C timer */
    uint16 p3cTimer;
    /* DCM P2e timer */
    uint16 p2eTimer;
    /* DCM P4s timer */
    sint32 p4sTimer;
    /* DCM P4s max timer */
    uint32 p4sTimer_Max;
} Dcm_ComType;
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Functions                                      **
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
extern void Dcm_Init(void);
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
extern Dcm_BuffStatusType Dcm_GetTxStatus(void);
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
extern void Dcm_MainFunction(void);
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
extern BufReq_ReturnType Dcm_ProvideRxBuffer(PduIdType pduId, PduLengthType pduLen, PduInfoType** sduInfo);
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
extern void Dcm_RxIndication(PduIdType pduId, NotifResultType result);
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
extern BufReq_ReturnType Dcm_ProvideTxBuffer(PduIdType pduId, PduInfoType** sduInfo);
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
extern void Dcm_TxConfirmation(PduIdType pduId, NotifResultType result);
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
extern void Dcm_Service_RxFinish(void);
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
extern Dcm_SessionType Dcm_GetSessionMode(void);
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
extern Dcm_SecurityType Dcm_GetSecurityLevel(void);
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
extern void Dcm_StartSecurityTimer(uint8 attemptId, uint32 timeOut);
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
extern void Dcm_StartP3cTimer(void);
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
extern void Dcm_ForcePending(void);
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
extern void Dcm_StartP2eTimer(const uint16 timeout);
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
extern Dcm_ComType* Dcm_GetComStatus(void);
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
extern Dcm_BuffStatusType Dcm_GetRxStatus(void);
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
extern BufReq_ReturnType Dcm_TakeTxBuffer(void);
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
extern void Dcm_GiveTxBuffer(void);

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
extern void Dcm_SendPending(void);

#endif/* endif of DCM_H */
