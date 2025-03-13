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
#include "NvM.h"
#include "HcmPlatform.h"
#include "DID_Interface.h"
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
#define SERVICE10_NO_RESP_FLAG (0x49)
const uint8 Appl_extprogrequestreceived[] = {0x6E, 0x67, 0x69, 0x53, 0x67, 0x6F, 0x72, 0x50};
static const uint8 Buffer_DcmDspData_0xF18A[DataLength_DcmDspData_0xF18A] =
{/* System Supplier Identifier */
	0x35, 0x31, 0x39, 0x30, 0x37, 0x35
};

#ifdef LeftAir
static const uint8 Buffer_DcmDspData_0xF1A0[DataLength_DcmDspData_0xF1A0] =
{/* Application Diagnostic Database Part Number - Geely */
	0x66, 0x08, 0x34, 0x25, 0x60, 0x20, 0x20 ,0x41
};
static const uint8 Buffer_DcmDspData_0xF1A1[DataLength_DcmDspData_0xF1A1] =
{/* Primary Bootloader Diagnostic Database Part Number - Geely */
	0x66, 0x08, 0x34, 0x25, 0x62, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xF1A5[DataLength_DcmDspData_0xF1A5] =
{/* Primary Bootloader Software Part Number */
	0x66, 0x08, 0x34, 0x25, 0x62, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xF1AE[DataLength_DcmDspData_0xF1AE] =
{/* ECU Software Part Numbers - Geely */
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF ,0xFF, 0x20, \
	0x66, 0x08, 0x34, 0x25, 0x62, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xD0B5[DataLength_DcmDspData_0xD0B5] =
{/* SDB */
	 0x00, 0x00, 0x00
};

#elif RightAir
static const uint8 Buffer_DcmDspData_0xF1A0[DataLength_DcmDspData_0xF1A0] =
{/* Application Diagnostic Database Part Number - Geely */
	0x66, 0x08, 0x34, 0x25, 0x61, 0x20, 0x20 ,0x41
};
static const uint8 Buffer_DcmDspData_0xF1A1[DataLength_DcmDspData_0xF1A1] =
{/* Primary Bootloader Diagnostic Database Part Number - Geely */
	0x66, 0x08, 0x34, 0x25, 0x63, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xF1A5[DataLength_DcmDspData_0xF1A5] =
{/* Primary Bootloader Software Part Number */
	0x66, 0x08, 0x34, 0x25, 0x62, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xF1AE[DataLength_DcmDspData_0xF1AE] =
{/* ECU Software Part Numbers - Geely */
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF ,0xFF, 0x20, \
	0x66, 0x08, 0x34, 0x25, 0x62, 0x20, 0x20 ,0x41
};

static const uint8 Buffer_DcmDspData_0xD0B5[DataLength_DcmDspData_0xD0B5] =
{/* SDB */
	 0x00, 0x00, 0x00
};
#endif

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
void Rte_Dcm_Appl_EcuReset_NoResp(void)
{
	uint8 index;

	/* Reset marker because of 10 02 */
    for(index=0;index<8;index++)
    {
    	Boot_UninitRam[index] = Appl_extprogrequestreceived[index];
    }
	Boot_UninitRam[7] = SERVICE10_NO_RESP_FLAG;
	Dcm_StartResetTimer((uint16)10u);
}

/*==============================22 Service ===================================*/

uint8 Rte_Dcm_0xD0B5_ReadData(uint8 *readData, uint16* readLength)
{
	for(uint8 i=0;i<DataLength_DcmDspData_0xD0B5;i++)
    {
        readData[i]=Buffer_DcmDspData_0xD0B5[i];
    }  
	*readLength = (uint16)DataLength_DcmDspData_0xF120;
	return E_OK;
}

uint8 Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength)
{
	uint8 index;
	uint8 errorCode;

	errorCode = NvM_ReadBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);
	/* F18C 4bytes */
	for(index=0;index < DataLength_DcmDspData_0xF18C;index++)
	{
		readData[index] = NvMBlockRamBuffer3[NVM_DIDF18C_StartPos + index];
	}

	/* F1A0 8bytes */
	for (index = 0; index < DataLength_DcmDspData_0xF1A0;index++)
	{
		readData[DataLength_DcmDspData_0xF18C+index] = Buffer_DcmDspData_0xF1A0[index];
	}

	/* F1AA 8bytes*/
	for (index = 0;index < DataLength_DcmDspData_0xF1AA;index++)
	{
		readData[DataLength_DcmDspData_0xF18C + DataLength_DcmDspData_0xF1A0 + index] \
		= NvMBlockRamBuffer3[NVM_DIDF1AA_StartPos + index];
	}
	
	/* F1AB 8bytes*/
	for (index = 0;index < DataLength_DcmDspData_0xF1AB;index++)
	{
		readData[DataLength_DcmDspData_0xF18C + DataLength_DcmDspData_0xF1A0 + DataLength_DcmDspData_0xF1AA + index] \
		= NvMBlockRamBuffer3[NVM_DIDF1AB_StartPos + index];
	}

	/* F1AE 17bytes*/
    for(index = 0;index < DataLength_DcmDspData_0xF1AE;index++)
    {
        readData[DataLength_DcmDspData_0xF18C + DataLength_DcmDspData_0xF1A0 + \
		DataLength_DcmDspData_0xF1AA + DataLength_DcmDspData_0xF1AB + index] =Buffer_DcmDspData_0xF1AE[index];
    }
	*readLength = (uint16)DataLength_DcmDspData_0xED20;
	return E_OK;

}

uint8 Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength)
{
	uint8 index;
	uint8 errorCode;

	errorCode = NvM_ReadBlock(NvMBlock_All_EventEntry,NvMBlockRamBuffer3);
	/* F120 F12A F12B F12E 36bytes */
    for(index=0;index<36;index++)
    {
        readData[index]=0x00;
    } 

	/* F18C */
	for(index=0;index < DataLength_DcmDspData_0xF18C;index++)
	{
		readData[36+index] = NvMBlockRamBuffer3[NVM_DIDF18C_StartPos + index];
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
	*readLength = (uint16)DataLength_DcmDspData_0xF1A0;

	return E_OK;
}

uint8 Rte_Dcm_0xF1A1_ReadData(uint8 *readData, uint16* readLength)
{
	for(uint8 i=0;i<DataLength_DcmDspData_0xF1A1;i++)
    {
        readData[i]=Buffer_DcmDspData_0xF1A1[i];
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
    for(uint8 i=0;i<DataLength_DcmDspData_0xF1AB;i++)
    {
        readData[i]=0;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF1AB;

	return E_OK;
}

uint8 Rte_Dcm_0xF1AE_ReadData(uint8 *readData, uint16* readLength)
{/* ECU Software Part Numbers - Geely */

    for(uint8 i=0;i<DataLength_DcmDspData_0xF1AE;i++)
    {
        readData[i]=Buffer_DcmDspData_0xF1AE[i];
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF1AE;

	return E_OK;
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
	DID_Interface_Read_4359to435F(ChannelID2,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 3
uint8 Rte_Dcm_0x435C_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID3,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 4
uint8 Rte_Dcm_0x435D_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID4,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 5
uint8 Rte_Dcm_0x435E_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID1_Tap,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}
//CHANNEL 6
uint8 Rte_Dcm_0x435F_ReadData(uint8 *readData, uint16* readLength)
{
	DID_Interface_Read_4359to435F(ChannelID2_Alt,readData);
	* readLength = (uint16)DataLength_DcmDspData_0x4359_0x435F;
	return E_OK;
}

uint8 Rte_Dcm_0x437C_ReadData(uint8 *readData, uint16* readLength)
{
    DID_Interface_Read_437C(readData);
	*readLength = (uint16)DataLength_DcmDspData_0x437C;
	return E_OK;
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

	(void)rxBuff;
	txBuff->pduInfo.SduLength = (uint8)0x06u;
	txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
	txBuff->pduInfo.SduDataPtr[1] = (uint8)txBuff->pduInfo.SduDataPtr[1];
	txBuff->pduInfo.SduDataPtr[2] = (uint8)txBuff->pduInfo.SduDataPtr[2];
	txBuff->pduInfo.SduDataPtr[3] = (uint8)txBuff->pduInfo.SduDataPtr[3];
	txBuff->pduInfo.SduDataPtr[4] = (uint8)0x10u;
	txBuff->pduInfo.SduDataPtr[5] = (uint8)0x01u;
	Dcm_SendRsp();
}

/*==============================Initilization Operation ===================================*/
void Rte_Dcm_SecTimer_Init(void)
{
	uint8 SecAttemptId;

	for(SecAttemptId = 0x00u;SecAttemptId < DCM_SECURITY_NUM; SecAttemptId++)
	{
		// if(App_UninitRam[SecAttemptId] >= DCM_SECURITY_ATTEMPT_NUM)
		// {
		// 	Dcm_StartSecurityTimer(SecAttemptId, (uint32)DCM_SECURITY_TIME);
		// }
		// else
		// {
			Dcm_StartSecurityTimer(SecAttemptId, (uint32)0);
		// }
	}
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*=======[E N D   O F   F I L E]==============================================*/
