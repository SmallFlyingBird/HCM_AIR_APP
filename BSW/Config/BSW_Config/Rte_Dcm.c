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
**  FILENAME    : Rte_Dcm.c                                                   **
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
/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "Rte_Dcm.h"
#include "Mcu.h"
#include "Os_User.h"
#include "Dcm_Internel.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define DataLength_DcmDspData_0xF186 1U
#define DataLength_DcmDspData_0xD01C 32U
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
#if(CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
	uint32 reserve1:8;
	uint32 bit24:1;
	uint32 reserve2:2;
	uint32 bit21:1;
	uint32 reserve3:4;
	uint32 bit16:1;
	uint32 reserve4:2;
	uint32 bit13:1;
	uint32 reserve5:6;
	uint32 bit6:1;
	uint32 reserve6:1;
	uint32 bit4:1;
	uint32 reserve7:2;
	uint32 bit1:1;
#else
	uint32 bit1:1;
	uint32 reserve7:2;
	uint32 bit4:1;
	uint32 reserve6:1;
	uint32 bit6:1;
	uint32 reserve5:6;
	uint32 bit13:1;
	uint32 reserve4:2;
	uint32 bit16:1;
	uint32 reserve3:4;
	uint32 bit21:1;
	uint32 reserve2:2;
	uint32 bit24:1;
	uint32 reserve1:8;
#endif
}BIT32;

typedef union
{
	uint32 bytes;
	BIT32 bits;
}POSITION_HANDLE;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*==============================10 Service ===================================*/
void Rte_Dcm_Appl_EcuReset(void)
{
	/* perform Mcu Reset */
	Mcu_PerformReset();
}

/*==============================22 Service ===================================*/
uint8 Rte_Dcm_0xF186_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xD01C_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}
/*==============================27 Service ===================================*/
uint8 Rte_Dcm_27_GenerateSeed(uint8 *randomMsgOutput, uint32 randomMsgOutputLength)
{
	return E_OK;
}
uint8 Rte_Dcm_27_CompareKey(uint8* signature, uint32 signatureLength, uint8* randomMsgInput, uint32 randomMsgInputLength)
{
	return E_OK;
}

/*==============================2E Service ===================================*/



/*==============================31 Service ===================================*/
void Rte_Dcm_CheckCompleteAndCompatible_0x205(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
}

void Rte_Dcm_EraseMemory_0xff00(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
}

void Rte_Dcm_CheckMemory_0x212(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
}

void Rte_Dcm_GotoSBL_0x301_Callout(const uint8 errorCode, const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff)/*PRQA S 3673,3206*/
{
}

void Rte_Dcm_ActivateSBL_0x301(const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff)/*PRQA S 3206*/
{
}


/*==============================Initilization Operation ===================================*/
void Rte_Dcm_SecTimer_Init(void)
{
	uint8 SecAttemptId;

	for(SecAttemptId = 0x00u;SecAttemptId < DCM_SECURITY_NUM; SecAttemptId++)
	{
		if(App_UninitRam[SecAttemptId] >= DCM_SECURITY_ATTEMPT_NUM)
		{
			Dcm_StartSecurityTimer(SecAttemptId, (uint32)DCM_SECURITY_TIME);
		}
		else
		{
			Dcm_StartSecurityTimer(SecAttemptId, (uint32)0);
		}
	}
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*=======[E N D   O F   F I L E]==============================================*/
