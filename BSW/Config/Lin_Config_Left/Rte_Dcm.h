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
**  FILENAME    : Rte_Dcm.h                                                   **
**                                                                            **
**  Created on  : 2023/12/7 16:21:42                                          **
**  Author      : chunjun.hua                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Callout function for Dcm                                    **
**                                                                            **
**  SPECIFICATION(S) :   NONE                                                 **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20231207   chunjun.hua       Initial Version
 */

#ifndef RTEDCM_H
#define RTEDCM_H

/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "FL.h"
#include "Dcm.h"
#include "Appl_Dcm.h"
#include <Rte_DcmDid.h>
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/*==============================22 Service ===================================*/
extern FL_ResultType Rte_Dcm_0xF186_ReadData(uint8 *readData, uint16* readLength);
extern FL_ResultType Rte_Dcm_0xD01C_ReadData(uint8 *readData, uint16* readLength);
extern FL_ResultType Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength);
extern FL_ResultType Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength);
/*==============================2E Service ===================================*/

extern FL_ResultType Rte_Dcm_PublicKey_0xD01C_WriteData(const uint8 *data, const uint16 length);

/*==============================27 Service ===================================*/
/******************************************************************************/
/**
 * @brief               <compute key>
 *
 * <compute key before compute key> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <seed (IN), k (IN)>
 * @param[out]          <key (OUT)>
 * @param[in/out]       <NONE>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
extern SecM_StatusType Rte_Dcm_SecMComputeKey(const SecM_SeedType* seed, SecM_WordType mask, SecM_KeyType* key);
/*==============================31 Service ===================================*/
extern void Rte_Dcm_CheckCompleteAndCompatible_0x205(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_EraseMemory_0xff00(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_CheckMemory_0x212(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_GotoSBL_0x301_Callout(const FL_ResultType errorCode, const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff);

extern void Rte_Dcm_ActivateSBL_0x301(const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff);

#endif /*RTEDCM_H*/
