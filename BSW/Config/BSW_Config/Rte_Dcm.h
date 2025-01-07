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
#include "Dcm.h"
#include <Rte_DcmDid.h>
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
	/*==============================10 Service ===================================*/
	extern void Rte_Dcm_Appl_EcuReset(void);

/*==============================22 Service ===================================*/
extern uint8 Rte_Dcm_0xF186_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xD01C_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength);

/*==============================27 Service ===================================*/
extern uint8 Rte_Dcm_27_GenerateSeed(uint8 *randomMsgOutput, uint32 randomMsgOutputLength);
extern uint8 Rte_Dcm_27_CompareKey(uint8* signature, uint32 signatureLength, uint8* randomMsgInput, uint32 randomMsgInputLength);

/*==============================2E Service ===================================*/


/*==============================31 Service ===================================*/
extern void Rte_Dcm_CheckCompleteAndCompatible_0x205(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_EraseMemory_0xff00(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_CheckMemory_0x212(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_GotoSBL_0x301_Callout(const uint8 errorCode, const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff);

extern void Rte_Dcm_ActivateSBL_0x301(const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff);

/*==============================Initilization Operation ===================================*/
extern void Rte_Dcm_SecTimer_Init(void);

#endif /*RTEDCM_H*/
