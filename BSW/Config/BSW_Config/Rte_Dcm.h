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
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define DataLength_DcmDspData_0xF120 7U
#define DataLength_DcmDspData_0xF121 7U
#define DataLength_DcmDspData_0xF125 7U
#define DataLength_DcmDspData_0xF12A 7U
#define DataLength_DcmDspData_0xF12B 7U
#define DataLength_DcmDspData_0xF12E 15U

#define DataLength_DcmDspData_0xF1A0 8U
#define DataLength_DcmDspData_0xF1A1 8U
#define DataLength_DcmDspData_0xF1A5 8U
#define DataLength_DcmDspData_0xF1AA 8U
#define DataLength_DcmDspData_0xF1AB 8U
#define DataLength_DcmDspData_0xF1AE 17U

#define DataLength_DcmDspData_0xF18A 6U
#define DataLength_DcmDspData_0xF18C 4U

#define DataLength_DcmDspData_0xF1F0 12U

#define DataLength_DcmDspData_0x437C 18U

#define DataLength_DcmDspData_0xB107 45U
#define DataLength_DcmDspData_0xB108 54U

#define DataLength_DcmDspData_0xD0B5 3U

#define DataLength_DcmDspData_0xED20 55U
#define DataLength_DcmDspData_0xEDA0 50U

#define NVM_DIDF1AA_StartPos 0
#define NVM_DIDF1AB_StartPos 8
#define NVM_DIDF18C_StartPos 16

#define DFLASH_DID437CData_START_ADDRESS (0x0101A1A4U)
/*==============================APP Service ===================================*/
#define DataLength_DcmDspData_0x4359_0x435F 11U
#define DataLength_DcmDspData_0x43CF 1U
#define DataLength_DcmDspData_0x43DA 2U
#define DataLength_DcmDspData_0x4351 1U
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/*==============================10 Service ===================================*/
extern void Rte_Dcm_Appl_EcuReset(void);
extern void Rte_Dcm_Appl_EcuReset_NoResp(void);
/*==============================22 Service ===================================*/
extern uint8 Rte_Dcm_0xD0B5_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF120_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF121_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF125_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF12A_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF12B_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF12E_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF186_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF18A_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF18C_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF1A0_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF1A1_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF1A5_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF1AA_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF1AB_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF1AE_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xF1F0_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x4359_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x435B_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x435C_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x435D_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x435E_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x435F_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x437C_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x43CF_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x43D2_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x43DA_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xB107_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xB108_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0x4351_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xD900_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength);
extern uint8 Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength);
/*==============================27 Service ===================================*/
extern uint8 Rte_Dcm_27_GenerateSeed(uint8 *randomMsgOutput, uint32 randomMsgOutputLength);
extern uint8 Rte_Dcm_27_CompareKey(uint8* signature, uint32 signatureLength, uint8* randomMsgInput, uint32 randomMsgInputLength);

/*==============================2E Service ===================================*/
extern uint8 Rte_Dcm_0xF1AA_WriteData(const uint8 *Data, uint16* Length);
extern uint8 Rte_Dcm_0xF1AB_WriteData(const uint8 *Data, uint16* Length);
extern uint8 Rte_Dcm_0xF18C_WriteData(const uint8 *Data, uint16* Length);
extern uint8 Rte_Dcm_0xF1AA_WriteDataPending(const uint8 *rxBuff, uint8 *txBuff, uint32* txLength);
extern uint8 Rte_Dcm_0xF1AB_WriteDataPending(const uint8 *rxBuff, uint8 *txBuff, uint32* txLength);
extern uint8 Rte_Dcm_0xF18C_WriteDataPending(const uint8 *rxBuff, uint8 *txBuff, uint32* txLength);

/*==============================31 Service ===================================*/
extern void Rte_Dcm_CheckProgrammingPreConditions_0x0206(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
extern void Rte_Dcm_EOL_0xFD01(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
extern void Rte_Dcm_EOL_0xFD02(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
/*==============================Initilization Operation ===================================*/
extern void Rte_Dcm_SecTimer_Init(void);

#endif /*RTEDCM_H*/
