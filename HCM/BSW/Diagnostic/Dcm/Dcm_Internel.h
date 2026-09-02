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
**  FILENAME    : Dcm_Internel.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                                    **
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
 *  V1.0.0     20121109    Gary              Initial version
 *  V1.0.1     20180511    CChen              update
 *  V1.0.2     20200413    Lianren.Wu         optimization
 *  V1.0.3     20231214    Long.Zhu           delete Appl_SecurityAccessUpdated.
 */
#ifndef DCM_INTERNEL_H
#define DCM_INTERNEL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
    DCM_REQ_NONE,
    DCM_0X34_REQ,
    DCM_0X38_REQ,
} Dcm_RequstTypes;

/* data structure for program */
typedef struct
{
    /* data program start address */
    uint32 address;
    /* data program block Index(compare with parameter transfered by test) */
    uint8 blockId;
    /* if program condition is passed */
    boolean condition;
    /* fixme */
    boolean First36Service;
    Dcm_RequstTypes Dcm_Requst;
    /*length of last program size,to compare same block request length*/
    uint32 LastProgRamSize;
    /* Erase start address */
    uint32 ErasedAddress;
    /* Erase address length*/
    uint32 ErasedLength;

    /* below are Geely2P0 sepecified components */
    boolean contionForActiveSBL;

    uint32 decompcount;

    uint32 compcount;

    boolean DownloadCompDataFlag;

    boolean DownloadVetificationDataFlag;

    boolean ErrorBlock;

} Dcm_DspProgramType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern Dcm_DspProgramType dcmDspProgram;

/*******************************************************************************
**                      Global Functions                                      **
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
extern void Dcm_DspInit(void);

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
extern void Dcm_ServiceFinish(void);

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
extern void Dcm_SetSessionMode(const Dcm_SessionType sessMode);

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
extern boolean Dcm_CheckSessionSupp(const Dcm_SessionType* sessionSupportPtr, const uint8 sessionSupportNum);

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
extern void Dcm_SetSecurityLevel(const Dcm_SecurityType secLev);

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
extern boolean Dcm_GetSecurityTimerExpired(uint8 attemptId);

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
extern boolean Dcm_CheckSecuritySupp(const Dcm_SecurityType* securitySupportPtr, const uint8 securitySupportNum);

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
extern void Dcm_StartResetTimer(uint16 timeOut);

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
extern void Dcm_SendRsp(void);

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
extern void Dcm_SendNrc(uint8 nrcCode);

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
extern boolean Dcm_PhyAddrSendNrc(boolean result, const PduIdType curPduId, uint8 nrcCode);

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
extern void Dcm_StartP4sTimer_Max(uint32 timerMax);

#endif /* end of DCM_INTERNEL_H */
