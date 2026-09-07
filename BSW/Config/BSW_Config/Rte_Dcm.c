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
#include <string.h>
#include "Rte_Dcm.h"
#include "Mcu.h"
#include "Os_User.h"
#include "Dcm_Internel.h"
#include "NvM.h"
#include "HcmPlatform.h"
#include "DID_Interface.h"
#include "PduR_Callout.h"
#include "Rte_Dcm_Callout.h"
#include "EOL_Interface.h"
#include "NtcRcod_Interface.h"
#include "Rte_E2E_Callout.h"
#include "Parameter_Interface.h"
#include "ParaMgr.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define RTE_DCM_RID
#define DataLength_DcmDspData_0xF186 1U
#define DataLength_DcmDspData_0xD01C 32U

uint8 EOLSetCH1BSwitchStatus=0;  /* 0:close  1:open */

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

typedef enum
{
	P171_L = 0,
	P171_R,
	P177_L,
	P177_R
}CarStyle_ENUM;
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define SERVICE10_NO_RESP_FLAG (0x49)
const uint8 Appl_extprogrequestreceived[] = {0x6E, 0x67, 0x69, 0x53, 0x67, 0x6F, 0x72, 0x50};
const uint8 Appl_extprogrequestreceived_Nrsp[] = {0x6E, 0x67, 0x69, 0x53, 0x67, 0x6F, 0x72, 0x49};
static const uint8 Buffer_DcmDspData_0xF18A[DataLength_DcmDspData_0xF18A] =
{/* System Supplier Identifier */
	0x35, 0x31, 0x39, 0x30, 0x37, 0x35
};

static const uint8 Buffer_DcmDspData_0xF1A0[DataLength_DcmDspData_0xF1A0] =
{/* Application Diagnostic Database Part Number - Geely */
	0x66, 0x08, 0x52, 0x77, 0x40, 0x20, 0x20 ,0x41
};
static const uint8 Buffer_DcmDspData_0xF1A1[DataLength_DcmDspData_0xF1A1] =
{/* Primary Bootloader Diagnostic Database Part Number - Geely */
	0x66, 0x08, 0x52, 0x77, 0x39, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xF1A5[DataLength_DcmDspData_0xF1A5] =
{/* Primary Bootloader Software Part Number:   */
	0x66, 0x08, 0x60, 0x24, 0x12, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xF1AE[4][DataLength_DcmDspData_0xF1AE] =
{/* ECU Software Part Numbers - Geely */
	/*P171 L*/
	{
		0x02, \
		0x66, 0x08, 0x60, 0x24, 0x09, 0x20, 0x20 ,0x43, \
		0x66, 0x08, 0x60, 0x24, 0x08, 0x20, 0x20 ,0x41
	},
	/*P171 R*/
	{
		0x02, \
		0x66, 0x08, 0x60, 0x24, 0x10, 0x20, 0x20 ,0x43, \
		0x66, 0x08, 0x60, 0x24, 0x07, 0x20, 0x20 ,0x41
	},
	/*P177 L*/
	{
		0x02, \
		0x66, 0x08, 0x56, 0x15, 0x03, 0x20, 0x20 ,0x43, \
		0x66, 0x08, 0x52, 0x77, 0x44, 0x20, 0x20 ,0x41
	},
	/*P177 R*/
	{
		0x02, \
		0x66, 0x08, 0x56, 0x15, 0x04, 0x20, 0x20 ,0x43, \
		0x66, 0x08, 0x52, 0x77, 0x45, 0x20, 0x20 ,0x41
	}

};

static const uint8 Buffer_DcmDspData_0xD0B5[DataLength_DcmDspData_0xD0B5] =
{/* SDB */
	0X24,0X36,0X01
};

uint8_t eolSessionActive = EOLSession_NotActive;
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*==============================10 Service ===================================*/
#define FL_BOOT_MODE_ADDR ((volatile void *)0x40061000U) 
#define APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH (sizeof(Appl_extprogrequestreceived))
void Rte_Dcm_Appl_EcuReset(void)
{
	uint8 index;

	/* Reset marker because of 10 02 */
    // for(index=0;index<8;index++)
    // {
    // 	Boot_UninitRam[index] = Appl_extprogrequestreceived[index];
    // }
	memcpy((void*)FL_BOOT_MODE_ADDR,Appl_extprogrequestreceived,APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH);
	Dcm_StartResetTimer((uint16)10u);
}
void Rte_Dcm_Appl_EcuReset_NoResp(void)
{
	uint8 index;

	/* Reset marker because of 10 02 */
    // for(index=0;index<8;index++)
    // {
    // 	Boot_UninitRam[index] = Appl_extprogrequestreceived[index];
    // }
	// Boot_UninitRam[7] = SERVICE10_NO_RESP_FLAG;
	memcpy((void*)FL_BOOT_MODE_ADDR,Appl_extprogrequestreceived_Nrsp,APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH);
	Dcm_StartResetTimer((uint16)10u);
}

/*==============================22 Service ===================================*/

uint8 Rte_Dcm_0xD0B5_ReadData(uint8 *readData, uint16* readLength)
{
	for(uint8 i=0;i<DataLength_DcmDspData_0xD0B5;i++)
    {
        readData[i]=Buffer_DcmDspData_0xD0B5[i];
    }  
	*readLength = (uint16)DataLength_DcmDspData_0xD0B5;
	return E_OK;
}

uint8 Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength)
{
	uint8 index;
	uint8 errorCode;
	uint8 Side = 0;
	uint8 carconfig = 0;

	if(AIR_437C_Direction_RIGHT == PduR_GetLightSide())
	{/* Right side */
		Side = 1;
	}

	if((Get_VehicleW() == 3) && (Side == 0))
	{/* P171 Left*/
		carconfig = P171_L;
	}
	else if((Get_VehicleW() == 3) && (Side == 1))
	{/* P171 Right*/
		carconfig = P171_R;
	}
	else if((Side == 0))
	{/* P177 Left*/
		carconfig = P177_L;
	}
	else
	{/* P177 Right*/
		carconfig = P177_R;
	}
	errorCode = NvM_ReadBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);
	/* F18C 2+4bytes */
	readData[0] = 0xF1;
	readData[1] = 0x8C;
	for(index=0;index < DataLength_DcmDspData_0xF18C;index++)
	{
		readData[index+2] = NvMBlockRamBuffer3[NVM_DIDF18C_StartPos + index];
	}

	/* F1A0 2+8bytes */
	readData[DataLength_DcmDspData_0xF18C+2] = 0xF1;
	readData[DataLength_DcmDspData_0xF18C+3] = 0xA0;
	for (index = 0; index < DataLength_DcmDspData_0xF1A0;index++)
	{
		readData[DataLength_DcmDspData_0xF18C+4+index] = Buffer_DcmDspData_0xF1A0[index];
	}

	/* F1AA 2+8bytes*/
	readData[DataLength_DcmDspData_0xF18C+DataLength_DcmDspData_0xF1A0+4] = 0xF1;
	readData[DataLength_DcmDspData_0xF18C+DataLength_DcmDspData_0xF1A0+5] = 0xAA;
	for (index = 0;index < DataLength_DcmDspData_0xF1AA;index++)
	{
		readData[DataLength_DcmDspData_0xF18C + DataLength_DcmDspData_0xF1A0 + 6 +index] \
		= NvMBlockRamBuffer3[NVM_DIDF1AA_StartPos + index];
	}
	
	/* F1AB 8bytes*/
	readData[DataLength_DcmDspData_0xF18C+DataLength_DcmDspData_0xF1A0+DataLength_DcmDspData_0xF1AA+6] = 0xF1;
	readData[DataLength_DcmDspData_0xF18C+DataLength_DcmDspData_0xF1A0+DataLength_DcmDspData_0xF1AA+7] = 0xAB;
	for (index = 0;index < DataLength_DcmDspData_0xF1AB;index++)
	{
		readData[DataLength_DcmDspData_0xF18C + DataLength_DcmDspData_0xF1A0 + DataLength_DcmDspData_0xF1AA + 8 +index] \
		= NvMBlockRamBuffer3[NVM_DIDF1AB_StartPos + index];
	}

	/* F1AE 17bytes*/
	readData[DataLength_DcmDspData_0xF18C+DataLength_DcmDspData_0xF1A0+DataLength_DcmDspData_0xF1AA+DataLength_DcmDspData_0xF1AB+8] = 0xF1;
	readData[DataLength_DcmDspData_0xF18C+DataLength_DcmDspData_0xF1A0+DataLength_DcmDspData_0xF1AA+DataLength_DcmDspData_0xF1AB+9] = 0xAE;
    for(index = 0;index < DataLength_DcmDspData_0xF1AE;index++)
    {
        readData[DataLength_DcmDspData_0xF18C + DataLength_DcmDspData_0xF1A0 + \
		DataLength_DcmDspData_0xF1AA + DataLength_DcmDspData_0xF1AB + 10 + index] =Buffer_DcmDspData_0xF1AE[carconfig][index];
    }

	if(AIR_437C_Direction_RIGHT == PduR_GetLightSide())
	{/* Right side */
		/*F1A0*/
		readData[DataLength_DcmDspData_0xF18C + 8] = 0x41;		
	}

	*readLength = (uint16)DataLength_DcmDspData_0xED20;
	return E_OK;

}

uint8 Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength)
{
	uint8 index;
	uint8 errorCode;

	errorCode = NvM_ReadBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);
	/* F120 F12A F12B F12E 36+8bytes */
    for(index=0;index<44;index++)
    {
        readData[index]=0x00;
    } 
	readData[0] = 0xF1;
	readData[1] = 0x20;
	readData[9] = 0xF1;
	readData[10] = 0x2A;
	readData[18] = 0xF1;
	readData[19] = 0x2B;
	readData[27] = 0xF1;
	readData[28] = 0x2E;
	readData[44] = 0xF1;
	readData[45] = 0x8C;
	/* F18C */
	for(index=0;index < DataLength_DcmDspData_0xF18C;index++)
	{
		readData[46+index] = NvMBlockRamBuffer3[NVM_DIDF18C_StartPos + index];
	}


	*readLength = (uint16)DataLength_DcmDspData_0xEDA0;
	return E_OK;
}

uint8 Rte_Dcm_0xF120_ReadData(uint8 *readData, uint16* readLength)
{
	for(uint8 i=0;i<DataLength_DcmDspData_0xF120;i++)
    {
        readData[i]=0x00;
    }  
	*readLength = (uint16)DataLength_DcmDspData_0xF120;
	return E_OK;
}

uint8 Rte_Dcm_0xF121_ReadData(uint8 *readData, uint16* readLength)
{
    for(uint8 i=0;i<DataLength_DcmDspData_0xF121;i++)
    {
        readData[i]=0x00;
    }  
	*readLength = (uint16)DataLength_DcmDspData_0xF121;
	return E_OK;
}

uint8 Rte_Dcm_0xF125_ReadData(uint8 *readData, uint16* readLength)
{    
	for(uint8 i=0;i<DataLength_DcmDspData_0xF125;i++)
    {
        readData[i]=0x00;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF125;
	return E_OK;
}

uint8 Rte_Dcm_0xF12A_ReadData(uint8 *readData, uint16* readLength)
{
	for(uint8 i=0;i<DataLength_DcmDspData_0xF12A;i++)
    {
        readData[i]=0x00;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF12A;
	return E_OK;
}

uint8 Rte_Dcm_0xF12B_ReadData(uint8 *readData, uint16* readLength)
{
    for(uint8 i=0;i<DataLength_DcmDspData_0xF12B;i++)
    {
        readData[i]=0x00;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF12B;
	return E_OK;
}

uint8 Rte_Dcm_0xF12E_ReadData(uint8 *readData, uint16* readLength)
{
    for(uint8 i=0;i<DataLength_DcmDspData_0xF12E;i++)
    {
        readData[i]=0x00;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF12E;
	return E_OK;
}

uint8 Rte_Dcm_0xF186_ReadData(uint8 *readData, uint16* readLength)
{
	*readData = Dcm_GetSessionMode();
	*readLength = DataLength_DcmDspData_0xF186;
	return E_OK;
}

uint8 Rte_Dcm_0xF18A_ReadData(uint8 *readData, uint16* readLength)
{
    for(uint8 i=0;i<DataLength_DcmDspData_0xF18A;i++)
    {
        readData[i]=Buffer_DcmDspData_0xF18A[i];
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF18A;

	return E_OK;
}

uint8 Rte_Dcm_0xF18C_ReadData(uint8 *readData, uint16* readLength)
{/* ECU Serial Number */
	//read from flash
	uint8 index;
	uint8 errorCode;
	uint8 ret = E_OK;
	errorCode = NvM_ReadBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);

	for(index=0;index<DataLength_DcmDspData_0xF18C;index++)
	{
		readData[index] = NvMBlockRamBuffer3[NVM_DIDF18C_StartPos + index];
	}
	
	
	if(errorCode == E_OK)
	{
		*readLength = DataLength_DcmDspData_0xF18C;
	}
	else
	{
		ret = E_NOT_OK;
	}
	return ret;
}

uint8 Rte_Dcm_0xF1A0_ReadData(uint8 *readData, uint16* readLength)
{
    for(uint8 i=0;i<DataLength_DcmDspData_0xF1A0;i++)
    {
        readData[i]=Buffer_DcmDspData_0xF1A0[i];
    }

	if(AIR_437C_Direction_RIGHT == PduR_GetLightSide())
	{/* Right side */
		readData[4] = 0x41;
	}

	*readLength = (uint16)DataLength_DcmDspData_0xF1A0;

	return E_OK;
}

uint8 Rte_Dcm_0xF1A1_ReadData(uint8 *readData, uint16* readLength)
{
	for(uint8 i=0;i<DataLength_DcmDspData_0xF1A1;i++)
    {
        readData[i]=Buffer_DcmDspData_0xF1A1[i];
    }
	if(AIR_437C_Direction_RIGHT == PduR_GetLightSide())
	{/* Right side */
		readData[3] = 0x99;	
		readData[4] = 0x32;
	}
	*readLength = (uint16)DataLength_DcmDspData_0xF1A1;

	return E_OK;
}

uint8 Rte_Dcm_0xF1A5_ReadData(uint8 *readData, uint16* readLength)
{
    for(uint8 i=0;i<DataLength_DcmDspData_0xF1A5;i++)
    {
        readData[i]=Buffer_DcmDspData_0xF1A5[i];
    }

	*readLength = (uint16)DataLength_DcmDspData_0xF1A5;
	return E_OK;
}

uint8 Rte_Dcm_0xF1AA_ReadData(uint8 *readData, uint16* readLength)
{/* ECU Core Assembly Part Number : HWSD */
//read from flash
	uint8 index;
	uint8 errorCode;
	uint8 ret = E_OK;
	errorCode = NvM_ReadBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);

	for(index=0;index<DataLength_DcmDspData_0xF1AA;index++)
	{
		readData[index] = NvMBlockRamBuffer3[NVM_DIDF1AA_StartPos + index];
	}
	
	
	if(errorCode == E_OK)
	{
		*readLength = DataLength_DcmDspData_0xF1AA;
	}
	else
	{
		ret = E_NOT_OK;
	}
	return ret;
}

uint8 Rte_Dcm_0xF1AB_ReadData(uint8 *readData, uint16* readLength)
{/* ECU delivery Assembly Part Number : DU */
	//read from flash
	uint8 index;
	uint8 errorCode;
	uint8 ret = E_OK;
	errorCode = NvM_ReadBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);

	for(index=0;index<DataLength_DcmDspData_0xF1AB;index++)
	{
		readData[index] = NvMBlockRamBuffer3[NVM_DIDF1AB_StartPos + index];
	}
	
	
	if(errorCode == E_OK)
	{
		*readLength = DataLength_DcmDspData_0xF1AB;
	}
	else
	{
		ret = E_NOT_OK;
	}
	return ret;
	return E_OK;
}

uint8 Rte_Dcm_0xF1AE_ReadData(uint8 *readData, uint16* readLength)
{/* ECU Software Part Numbers - Geely */
	uint8 Side = 0;
	uint8 carconfig = 0;
	uint8 startIndex = 9;
	if(AIR_437C_Direction_RIGHT == PduR_GetLightSide())
	{/* Right side */
		Side = 1;
	}

	if((3==Get_VehicleW()) && (Side == 0))
	{/* P171 Left*/
		carconfig = P171_L;
	}
	else if((Get_VehicleW() == 3) && (Side == 1))
	{/* P171 Right*/
		carconfig = P171_R;
	}
	else if((Side == 0))
	{/* P177 Left*/
		carconfig = P177_L;
	}
	else
	{/* P177 Right*/
		carconfig = P177_R;
	}

	for(uint8 i=0;i<DataLength_DcmDspData_0xF1AE;i++)
	{
		readData[i]=Buffer_DcmDspData_0xF1AE[carconfig][i];
	}

	if(Side == 0)
	{
		for(uint8 i = 0; i < 8; i++) 
		{
			readData[startIndex + i] = (ParaMgr_Left_Part_Number_QW >> ((7 - i) * 8)) & 0xFF;
		}
	}
	else
	{
		for(uint8 i = 0; i < 8; i++) 
		{
			readData[startIndex + i] = (ParaMgr_Right_Part_Number_QW >> ((7 - i) * 8)) & 0xFF;
		}
	}

	*readLength = (uint16)DataLength_DcmDspData_0xF1AE;

	return E_OK;
}
/* Read NTC1-6 */
uint8 Rte_Dcm_0xF1F0_ReadData(uint8 *readData, uint16* readLength)
{
	uint8 ret = E_NOT_OK;
	uint8 ntcid=0;
	uint16 datatmp;
	if(EOLSession_Active == Rte_Dcm_GetEolSessionStatus())
	{
		*readLength = (uint16)DataLength_DcmDspData_0xF1F0;
		for(ntcid=0;ntcid<MAX_NTCRCOD_NUM;ntcid++)
		{
			Interface_GetAdcDigitalValue(ntcid, &datatmp);
			readData[2*ntcid]=(datatmp>>8)&0xff;
			readData[2*ntcid+1]=datatmp&0xff;
		}
		ret = E_OK;
	}
	else
	{
		ret = E_NOT_OK;
	}

	return ret;
}

//CHANNEL 1
uint8 Rte_Dcm_0x4359_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID1,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 2
uint8 Rte_Dcm_0x435B_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID1_Tap,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 3
uint8 Rte_Dcm_0x435C_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID2,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 4
uint8 Rte_Dcm_0x435D_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID2_Alt,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 5
uint8 Rte_Dcm_0x435E_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID3,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 6
uint8 Rte_Dcm_0x435F_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID4,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}

uint8 Rte_Dcm_0x437C_ReadData(uint8 *readData, uint16* readLength)
{/* read from flash*/

	/* Get 437cdata start address */
	const uint8* DID437C_Data_Addr = (const uint8*)DFLASH_DID437CData_START_ADDRESS; 

	/* Read data */
	memcpy(readData, DID437C_Data_Addr, DataLength_DcmDspData_0x437C);
	*readLength = DataLength_DcmDspData_0x437C;

	return (uint8)E_OK;
}
/* buck temp */
uint8 Rte_Dcm_0x43CF_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_43CF(readData);
	*readLength = (uint16)DataLength_DcmDspData_0x43CF;
	return E_OK;
}
/* boost temp */
uint8 Rte_Dcm_0x43D2_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_43D2(readData);
	*readLength = (uint16)DataLength_DcmDspData_0x43D2;
	return E_OK;
}

/* Boot L=1 R=2 ;APP L=1 R=2 */
uint8 Rte_Dcm_0x43DA_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_43DA(readData);
	*readLength = (uint16)DataLength_DcmDspData_0x43DA;
	return E_OK;
}

uint8 Rte_Dcm_0xB107_ReadData(uint8 *readData, uint16* readLength)
{
	for (uint8 i = 0; i < DataLength_DcmDspData_0xB107 ;i++)
	{
		readData[i] = 0x00;
	}
	*readLength = DataLength_DcmDspData_0xB107;
	return E_OK;
}

uint8 Rte_Dcm_0xB108_ReadData(uint8 *readData, uint16* readLength)
{
	for (uint8 i = 0; i < DataLength_DcmDspData_0xB108;i++)
	{
		readData[i] = 0x00;
	}
	*readLength = DataLength_DcmDspData_0xB108;
	return E_OK;
}
/* module temp */
uint8 Rte_Dcm_0x4351_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4351(readData);
	*readLength = DataLength_DcmDspData_0x4351;
	return E_OK;
}

uint8 Rte_Dcm_0xD900_ReadData(uint8 *readData, uint16* readLength)
{
	for (uint8 i = 0; i < DataLength_DcmDspData_0xD900 ;i++)
	{
		readData[i] = 0;
	}
	DID_Interface_Read_D900(readData);
	*readLength = DataLength_DcmDspData_0xD900;
	return E_OK;
}

uint8 Rte_Dcm_0xF1F2_ReadData(uint8 *readData, uint16* readLength)
{
	readData[0] = VER_SW_MAJOR;
	readData[1] = VER_SW_MINOR;
	readData[2] = VER_SW_FIX;
	*readLength = DataLength_DcmDspData_0xF1F2;
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
/* NvMBlockRamBuffer3 Bytes meaning:  */
/* Byte Position     DID      Length  */
/* Byte 0-7         0xF1AA    8 Bytes */
/* Byte 8-15        0xF1AB    8 Bytes */
/* Byte 16-47       0xF18C    32 Bytes */

uint8 Rte_Dcm_0xF1AA_WriteData(const uint8 *Data, uint16* Length)
{
	uint16 index;
	uint8 errorCode;
	uint8 ret = E_OK;
	
	if(EOLSession_Active == Rte_Dcm_GetEolSessionStatus())
	{
		for(index=0;index<DataLength_DcmDspData_0xF1AA;index++)
		{
			NvMBlockRamBuffer3[NVM_DIDF1AA_StartPos+index] = Data[index];
		}
		
		errorCode = NvM_WriteBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);
		if(errorCode == E_OK)
		{
			/* send NRC78 : Waiting for programming successfully */
			Dcm_SendPending();
		}
		else
		{
			ret = E_NOT_OK;
		}
	}
	else
	{
		ret = E_NOT_OK;
	}

	return ret;
}

uint8 Rte_Dcm_0xF1AA_WriteDataPending(const uint8 *rxBuff, uint8 *txBuff, uint32* txLength)
{
	uint8 ret = E_OK;
	uint8 errorCode;
	NvM_RequestResultType RequestResultPtr = NVM_REQ_NOT_OK;
	
	errorCode = NvM_GetErrorStatus(NvMBlock_All_EventEntry, &RequestResultPtr);

	/* check if write data successful */
	if (((uint8)NVM_REQ_OK == RequestResultPtr)&&(E_OK == errorCode))
	{
		/* set positive response message */
		txBuff[0] = (uint8)0x6Eu;
		txBuff[1] = rxBuff[1];
		txBuff[2] = rxBuff[2];
		*txLength = (PduLengthType)0x03u;
		Dcm_SendRsp();
	}
	else if(NVM_REQ_PENDING == RequestResultPtr)
	{
		/* Pending state */
	}
	else 
	{
		/* program finger print failure */
		/* set negative response message */
		/* NRC 72  DCM_E_72_GENERAL_PROGRAMMING_FAILURE */
		Dcm_SendNrc((uint8)DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
	}

	return ret;
}

uint8 Rte_Dcm_0xF1AB_WriteData(const uint8 *Data, uint16* Length)
{
	uint16 index;
	uint8 errorCode;
	uint8 ret = E_OK;
	
		
	if(EOLSession_Active == Rte_Dcm_GetEolSessionStatus())
	{
		for(index=0;index<DataLength_DcmDspData_0xF1AB;index++)
		{
			NvMBlockRamBuffer3[NVM_DIDF1AB_StartPos+index] = Data[index];
		}
		
		errorCode = NvM_WriteBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);
		if(errorCode == E_OK)
		{
			/* send NRC78 : Waiting for programming successfully */
			Dcm_SendPending();
		}
		else
		{
			ret = E_NOT_OK;
		}
	}
	else
	{
		ret = E_NOT_OK;
	}

	return ret;
}

uint8 Rte_Dcm_0xF1AB_WriteDataPending(const uint8 *rxBuff, uint8 *txBuff, uint32* txLength)
{
	uint8 ret = E_OK;
	uint8 errorCode;
	NvM_RequestResultType RequestResultPtr = NVM_REQ_NOT_OK;
	
	errorCode = NvM_GetErrorStatus(NvMBlock_All_EventEntry, &RequestResultPtr);

	/* check if write data successful */
	if (((uint8)NVM_REQ_OK == RequestResultPtr)&&(E_OK == errorCode))
	{
		/* set positive response message */
		txBuff[0] = (uint8)0x6Eu;
		txBuff[1] = rxBuff[1];
		txBuff[2] = rxBuff[2];
		*txLength = (PduLengthType)0x03u;
		Dcm_SendRsp();
	}
	else if(NVM_REQ_PENDING == RequestResultPtr)
	{
		/* Pending state */
	}
	else 
	{
		/* program finger print failure */
		/* set negative response message */
		/* NRC 72  DCM_E_72_GENERAL_PROGRAMMING_FAILURE */
		Dcm_SendNrc((uint8)DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
	}
	
	return ret;
}

uint8 Rte_Dcm_0xF18C_WriteData(const uint8 *Data, uint16* Length)
{
	uint16 index;
	uint8 errorCode;
	uint8 ret = E_OK;
	
	if(EOLSession_Active == Rte_Dcm_GetEolSessionStatus())
	{
		for(index=0;index<DataLength_DcmDspData_0xF18C;index++)
		{
			NvMBlockRamBuffer3[NVM_DIDF18C_StartPos+index] = Data[index];
		}
		
		errorCode = NvM_WriteBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);
		if(errorCode == E_OK)
		{
			/* send NRC78 : Waiting for programming successfully */
			Dcm_SendPending();
		}
		else
		{
			ret = E_NOT_OK;
		}
	}
	else
	{
		ret = E_NOT_OK;
	}
	return ret;
}
uint8 Rte_Dcm_0xF18C_WriteDataPending(const uint8 *rxBuff, uint8 *txBuff, uint32* txLength)
{
	uint8 ret = E_OK;
	uint8 errorCode;
	NvM_RequestResultType RequestResultPtr = NVM_REQ_NOT_OK;
	
	errorCode = NvM_GetErrorStatus(NvMBlock_All_EventEntry, &RequestResultPtr);

	/* check if write data successful */
	if (((uint8)NVM_REQ_OK == RequestResultPtr)&&(E_OK == errorCode))
	{
		/* set positive response message */
		txBuff[0] = (uint8)0x6Eu;
		txBuff[1] = rxBuff[1];
		txBuff[2] = rxBuff[2];
		*txLength = (PduLengthType)0x03u;
		Dcm_SendRsp();
	}
	else if(NVM_REQ_PENDING == RequestResultPtr)
	{
		/* Pending state */
	}
	else 
	{
		/* program finger print failure */
		/* set negative response message */
		/* NRC 72  DCM_E_72_GENERAL_PROGRAMMING_FAILURE */
		Dcm_SendNrc((uint8)DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
	}

	return ret;
}

/*==============================31 Service ===================================*/
void Rte_Dcm_CheckProgrammingPreConditions_0x0206(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{

	txBuff->pduInfo.SduLength = (uint8)0x06u;
	txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
	txBuff->pduInfo.SduDataPtr[1] = (uint8)rxBuff->pduInfo.SduDataPtr[1];
	txBuff->pduInfo.SduDataPtr[2] = (uint8)rxBuff->pduInfo.SduDataPtr[2];
	txBuff->pduInfo.SduDataPtr[3] = (uint8)rxBuff->pduInfo.SduDataPtr[3];
	txBuff->pduInfo.SduDataPtr[4] = (uint8)0x10u;
	txBuff->pduInfo.SduDataPtr[5] = (uint8)0x01u;
	Dcm_SendRsp();
}


/*

*/
void Rte_Dcm_EOL_0xFD01(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
	uint8 routineFunc = rxBuff->pduInfo.SduDataPtr[1];

	txBuff->pduInfo.SduLength = (uint8)0x05u;
	txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
	txBuff->pduInfo.SduDataPtr[1] = (uint8)rxBuff->pduInfo.SduDataPtr[1];
	txBuff->pduInfo.SduDataPtr[2] = (uint8)rxBuff->pduInfo.SduDataPtr[2];
	txBuff->pduInfo.SduDataPtr[3] = (uint8)rxBuff->pduInfo.SduDataPtr[3];
	switch(routineFunc)
	{
		case DCM_START_ROUTINE:
			Rte_Dcm_SetEolSessionStatus(EOLSession_Active);
			txBuff->pduInfo.SduDataPtr[4] = (uint8)EOLSession_Active;

			/* can shu biao need to be changed to eol */
			break;
		case DCM_STOP_ROUTINE:
			Rte_Dcm_SetEolSessionStatus(EOLSession_NotActive);
			txBuff->pduInfo.SduDataPtr[4] = (uint8)EOLSession_NotActive;

			/* can shu biao need to be changed to normal */
			break;
		case DCM_RESULT_ROUTINE:
			txBuff->pduInfo.SduDataPtr[4] = Rte_Dcm_GetEolSessionStatus();
			break;
		default:
			txBuff->pduInfo.SduLength = (uint8)0x03;
			txBuff->pduInfo.SduDataPtr[0] = (uint8)0x7Fu;
			txBuff->pduInfo.SduDataPtr[1] = (uint8)0x31u;
			txBuff->pduInfo.SduDataPtr[2] = (uint8)0x12u;
			break;
	}

}

/* 0:close  1:open */
void Interface_EOLSetCH1B_Switch(uint8 status)
{
	EOLSetCH1BSwitchStatus=status;
}

/* 0:close  1:open */
uint8 Interface_EOLGetCH1B_Switch(void)
{
	return EOLSetCH1BSwitchStatus;
}

void Rte_Dcm_EOL_0xFD02(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
	uint8 routineFunc = rxBuff->pduInfo.SduDataPtr[1];
	uint8 controlObj = rxBuff->pduInfo.SduDataPtr[4];

	txBuff->pduInfo.SduLength = (uint8)0x05u;
	txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
	txBuff->pduInfo.SduDataPtr[1] = (uint8)rxBuff->pduInfo.SduDataPtr[1];
	txBuff->pduInfo.SduDataPtr[2] = (uint8)rxBuff->pduInfo.SduDataPtr[2];
	txBuff->pduInfo.SduDataPtr[3] = (uint8)rxBuff->pduInfo.SduDataPtr[3];
	txBuff->pduInfo.SduDataPtr[4] = TRUE;

	if(EOLSession_Active == Rte_Dcm_GetEolSessionStatus())
	{/* EOL session */
		switch(routineFunc)
		{
			case DCM_START_ROUTINE:
				/* Control */
				if(EOLControl_Fan == controlObj)
				{
					/* turn on fan */
					Interface_SetFanSwitchOn();
				}
				else if(EOLSession_CH1B == controlObj)
				{
					/* turn on CH1B */
					Interface_EOLSetCH1B_Switch(1);
				}
				else
				{
					txBuff->pduInfo.SduDataPtr[4] = FALSE;
				}
				break;
			case DCM_STOP_ROUTINE:
				/* Stop */
				if(EOLControl_Fan == controlObj)
				{
					/* turn off fan */
					Interface_SetFanSwitchOff();
				}
				else if(EOLSession_CH1B == controlObj)
				{
					/* turn off CH1B */
					Interface_EOLSetCH1B_Switch(0);
				}
				else
				{
					txBuff->pduInfo.SduDataPtr[4] = FALSE;
				}
				break;
			case DCM_RESULT_ROUTINE:

				break;
		}
	}
	else
	{
		txBuff->pduInfo.SduLength = (uint8)0x03;
		txBuff->pduInfo.SduDataPtr[0] = (uint8)0x7Fu;
		txBuff->pduInfo.SduDataPtr[1] = (uint8)0x31u;
		txBuff->pduInfo.SduDataPtr[2] = (uint8)0x12u;
	}


}





/*==============================Initilization Operation ===================================*/
void Rte_Dcm_SecTimer_Init(void)
{
	uint8 SecAttemptId;

	for(SecAttemptId = 0x00u;SecAttemptId < DCM_SECURITY_NUM; SecAttemptId++)
	{
		Dcm_StartSecurityTimer(SecAttemptId, (uint32)0);
	}
}



/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*=======[E N D   O F   F I L E]==============================================*/
