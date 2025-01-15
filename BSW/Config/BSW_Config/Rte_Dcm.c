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
const uint8 Appl_extprogrequestreceived[] = {0x6E, 0x67, 0x69, 0x53, 0x67, 0x6F, 0x72, 0x50};
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*==============================10 Service ===================================*/
void Rte_Dcm_Appl_EcuReset(void)
{
	uint8 index;

	/* Reset marker because of 10 02 */
    for(index=0;index<8;index++)
    {
    	Boot_UninitRam[index] = Appl_extprogrequestreceived[index];
    }
	Dcm_StartResetTimer((uint16)10u);
}

/*==============================22 Service ===================================*/

uint8 Rte_Dcm_0xD0B5_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF120_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF121_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF125_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF12A_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF12B_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF12E_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF186_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF18A_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF18C_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1A0_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1A1_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1A5_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1AA_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1AB_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1AE_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x4359_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x435B_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x435C_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x435D_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x435E_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x435F_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x437C_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x43CF_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x43D2_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x43DA_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x4351_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1F0_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1F1_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xD900_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength)
{
	uint8 index;
	
	*readLength = 0x30;
	for(index=0;index<*readLength;index++)
	{
		readData[index] = index;
	}

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
void Rte_Dcm_CheckProgrammingPreConditions_0x0206(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
//todo.....
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
