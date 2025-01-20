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
/*==============================22 Service ===================================*/
FL_ResultType Rte_Dcm_0xF186_ReadData(uint8 *readData, uint16* readLength)
{
	/* Active Diag Session Identification, 1 DEC code */
	*readData = Dcm_GetSessionMode();
	
	*readLength = DataLength_DcmDspData_0xF186;
	return FL_OK;
}

FL_ResultType Rte_Dcm_0xD01C_ReadData(uint8 *readData, uint16* readLength)
{
	FL_ResultType ret = FL_OK;
	uint8	i;
	const 	FL_PublicKeyAndSecConstInfoType *PublicKeyAndSecConstInfo;
	uint8*  readDataInput = readData;

    /* get the point of nvmInfo */
	PublicKeyAndSecConstInfo = FL_GetPublicKeyAndSecConstNvmInfo();

    /* NRC22 DCM_E_CONDITIONS_NOT_CORRECT for not write DO1C */
	/* if public is not write already send NRC 22*/
	if (PublicKeyAndSecConstInfo->PublicKeyWritten != FL_OPERATE_SUCCEESSD_FLAG)
	{
		Dcm_SendNrc(DCM_E_22_CONDITIONS_NOT_CORRECT);
		ret = FL_FAILED;
	}
	else
	{
		for (i = 0; i < (uint8)DataLength_DcmDspData_0xD01C; i++)
		{
			*readDataInput = (uint8)PublicKeyAndSecConstInfo->PublicKey[i + 260u];
			readDataInput++;
		}
		ret = FL_OK;
	}

	*readLength = (uint16)DataLength_DcmDspData_0xD01C;
	return ret;
}


FL_ResultType Rte_Dcm_0xED20_ReadData(uint8 *readData, uint16* readLength)
{
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
	uint16 did[]={0xF1A1, 0xF1AA, 0xF1AB, 0xF18C, 0xF1A5};
#else
	uint16 did[]={0xF1A2 ,0xF1AA ,0xF1AB ,0xF18C ,0xF124};
#endif
	uint16 iloop,jloop;
	uint16 len =0;
	for (jloop = 0u; jloop < (uint16)(sizeof(did)/sizeof(did[0])); jloop++)
	{
		for (iloop = 0u; iloop < DCM_READDID_NUM; iloop++)
		{
			if(did[jloop] == Dcm_ReadDidRow[iloop].DID)
			{
				readData[len++] = (uint8)(did[jloop]>>8);
				readData[len++] = (uint8)(did[jloop]&0xFF);
				(void) Dcm_ReadDidRow[iloop].readDataFct(&readData[len],readLength);
				len+=readLength[0];
			}
		}
	}
	*readLength = (uint16)len;
	return FL_OK;
}

FL_ResultType Rte_Dcm_0xEDA0_ReadData(uint8 *readData, uint16* readLength)
{
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
	uint16 did[]={0xF121, 0xF12A, 0xF12B, 0xF18C, 0xF125};
#else
	uint16 did[]={0xF122 ,0xF12A ,0xF12B ,0xF18C ,0xF124};
#endif
	uint16 iloop,jloop;
	uint16 len =0;
	for (jloop = 0u; jloop < (uint16)(sizeof(did)/sizeof(did[0])); jloop++)
	{
		for (iloop = 0u; iloop < DCM_READDID_NUM; iloop++)
		{
			if(did[jloop] == Dcm_ReadDidRow[iloop].DID)
			{
				readData[len++] = (uint8)(did[jloop]>>8);
				readData[len++] = (uint8)(did[jloop]&0xFF);
				(void)Dcm_ReadDidRow[iloop].readDataFct(&readData[len],readLength);
				len+=readLength[0];
			}
		}
	}
	*readLength = (uint16)len;
	return FL_OK;
}

/*==============================2E Service ===================================*/

FL_ResultType Rte_Dcm_PublicKey_0xD01C_WriteData(const uint8 *data, const uint16 length)
{
    FL_ResultType ret = (uint8)FL_OK;
    
	ret = FL_WritePublicKey(data, length);

    return ret;
}

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
SecM_StatusType Rte_Dcm_SecMComputeKey(const SecM_SeedType* seed, SecM_WordType mask, SecM_KeyType* key)
{
    /* Geely Security Access Specification*/
	uint8 i,j;
	uint8 seed_byte[8];
	uint8 Key_Byte[3];
	POSITION_HANDLE PositionA;
	POSITION_HANDLE PositionB;
	POSITION_HANDLE PositionC;
	uint8* u8Ptr;
	const FL_PublicKeyAndSecConstInfoType *PublicKeyAndSecConstInfo;

	PublicKeyAndSecConstInfo = FL_GetPublicKeyAndSecConstNvmInfo();
	/*3 Bytes seed and 5 fixed Bytes seed*/
	seed_byte[0] =  (uint8)(seed[0] & 0xFFu);    /*S1*/
	seed_byte[1] =  (uint8)(seed[1] & 0xFFu);    /*S2*/
	seed_byte[2] =  (uint8)(seed[2] & 0xFFu);        /*S3*/
	seed_byte[3] =  (uint8)(PublicKeyAndSecConstInfo->security[0]);   /*change security constant 1*/
	seed_byte[4] =  (uint8)(PublicKeyAndSecConstInfo->security[1]);   /*change security constant 2*/
	seed_byte[5] =  (uint8)(PublicKeyAndSecConstInfo->security[2]);   /*change security constant 3*/
	seed_byte[6] =  (uint8)(PublicKeyAndSecConstInfo->security[3]);   /*change security constant 4*/
	seed_byte[7] =  (uint8)(PublicKeyAndSecConstInfo->security[4]);   /*change security constant 5*/

	/*Please refer to the specific algorithm: Geely(Security Access Specification(Legacy ID=362857v0,353878v0).pdf)*/
	PositionA.bytes = mask;   /*The first PositionA value is Mask value*/

	for(i = 0u; i < 8u; i++)      /*8 bytes seed,every seed is 8 bits,so loop two,each loop has 8 times*/
	{
		for(j = 0u; j < 8u; j++)
		{
			PositionB.bytes = PositionA.bytes;   /*PositionA value whole load PositionB address*/

			PositionB.bytes = PositionB.bytes >> 1u;    /*PositionB need change bit24 value,So whole PositionB value right shift 1 bit,make PositionB bit24 is blank*/
			PositionB.bits.bit24 = PositionA.bits.bit1 ^ ((seed_byte[i] >> j) & 0x01u);  /*Each loop PositionA value bit1 Xor Each seed every bit,Then place PositionB bit24 address*/

			PositionC.bytes = PositionB.bytes; /*PositionB value whole load PositionC address*/

			PositionC.bits.bit21 = PositionB.bits.bit24 ^ PositionB.bits.bit21;  /*PositionB bit24 Xor PositionB bit21,then place PositionC bit21 address*/
			PositionC.bits.bit16 = PositionB.bits.bit24 ^ PositionB.bits.bit16;  /*PositionB bit24 Xor PositionB bit16,then place PositionC bit16 address*/
			PositionC.bits.bit13 = PositionB.bits.bit24 ^ PositionB.bits.bit13;  /*PositionB bit24 Xor PositionB bit13,then place PositionC bit13 address*/
			PositionC.bits.bit6 = PositionB.bits.bit24 ^ PositionB.bits.bit6;    /*PositionB bit24 Xor PositionB bit6,then place PositionC bit6 address*/
			PositionC.bits.bit4 = PositionB.bits.bit24 ^ PositionB.bits.bit4;    /*PositionB bit24 Xor PositionB bit4,then place PositionC bit4 address*/

			PositionA.bytes = PositionC.bytes;  /*64 times not end,Then PositionC value whole load PositionA address,Then continue the Loop*/
		}
	}

	Key_Byte[0] = (uint8)(PositionC.bytes >> 4u);                                                      /*R1; C12 C11,C10,C9,C8,C7,C6,C5*/
	Key_Byte[1] = (uint8)((PositionC.bytes >> 8u) & 0xF0u) | ((uint8)(PositionC.bytes >> 20u) & 0x0Fu);   /*R2; C16 C15 C14 C13(place MSB)     C24 C23 C22 C21(place LSB)*/
	Key_Byte[2] = (uint8)(PositionC.bytes << 4u) | ((uint8)(PositionC.bytes >> 16u) & 0x0Fu);            /*R3; C4 C3 C2 C1(Place MSB)         C20 C19 C18 C17(Place LSB)*/

	u8Ptr = (uint8*)key;
	u8Ptr[0] = Key_Byte[0u];     /*R3*/
	u8Ptr[1] = Key_Byte[1u];     /*R2*/
	u8Ptr[2] = Key_Byte[2u];     /*R1*/

    return SECM_OK;
}

/*==============================31 Service ===================================*/
void Rte_Dcm_CheckCompleteAndCompatible_0x205(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    FL_ResultType consistencyStatus;
	FL_ResultType compatibilityStatus;
    (void)rxBuff;
	consistencyStatus = Appl_CheckblkValid();
    compatibilityStatus = Appl_CheckDependence();
    /* execute routine for check application software dependency */
	txBuff->pduInfo.SduDataPtr[4] = (uint8)0x10u;
    txBuff->pduInfo.SduDataPtr[5] = (uint8)0x00u;
    txBuff->pduInfo.SduDataPtr[6] = (uint8)0x00u;
    txBuff->pduInfo.SduDataPtr[7] = (uint8)0x00u;
    txBuff->pduInfo.SduDataPtr[8] = (uint8)0x00u;
	if (consistencyStatus != FL_OK)
	{
		txBuff->pduInfo.SduDataPtr[8] = (uint8)((1<<(consistencyStatus - 1))|0x1);
	}else if(compatibilityStatus!= FL_OK)
	{
		/*txBuff->pduInfo.SduDataPtr[8] = (uint8)((1<<(compatibilityStatus - 1))|0x2);*/
        /*Èí¼þ²»¼æÈÝ*/
        txBuff->pduInfo.SduDataPtr[8] = (txBuff->pduInfo.SduDataPtr[8] | (1<<1));
	}
	
	txBuff->pduInfo.SduLength = 0x09u;

    /* set response message */
    if (FL_OK == consistencyStatus && FL_OK == compatibilityStatus)
    {
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_SBL)
		/* fixme update program cnt or other*/
		/* FL_updateProgCnt() */
		FL_SetProDependenciesValid((boolean)TRUE);
		(void)FL_UpdateBlockIntergrityNvm();
#endif
		Dcm_SendRsp();

    }
    /* CheckCompleteAndCompatible not OK */
    else
    {
    	/* if check not OK and the downloadStep is check step ,
    	 * set the FL state to the idle state: FL_REQUEST_STEP */
    	FL_Set_flStepInCheckStep();

	    Dcm_SendRsp();
    }

    return;
}


void Rte_Dcm_EraseMemory_0xff00(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    /* todo: code here */
	Dcm_EraseMemory(rxBuff,txBuff);
	/* end of todo */
}


void Rte_Dcm_CheckMemory_0x212(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    /* todo: code here */
	Dcm_CheckMemory(rxBuff,txBuff);
	/* end of todo */
}

void Rte_Dcm_GotoSBL_0x301_Callout(const FL_ResultType errorCode, const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff)/*PRQA S 3673,3206*/
{

    (void)txBuff;

    uint32 sblEnterAddr;
    /* get SBL Call address */
    sblEnterAddr = DP_Get4Byte(&rxBuff->pduInfo.SduDataPtr[4]);
    WdgIf_Deinit();
    /* Enter SBL software */
    //Appl_GotoSblSW(sblEnterAddr);

}

void Rte_Dcm_ActivateSBL_0x301(const Dcm_BuffType * rxBuff, Dcm_BuffType * txBuff)/*PRQA S 3206*/
{
	/* get SBL Call address */
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
	uint32 sblEnterAddr = DP_Get4Byte(&rxBuff->pduInfo.SduDataPtr[4]);
	if(dcmDspProgram.contionForActiveSBL == FALSE)
	{
		txBuff->pduInfo.SduDataPtr[4] = 0x11u;
		txBuff->pduInfo.SduLength 	  = 0x05u;
		Dcm_SendRsp();
	}
	else if(sblEnterAddr != FL_SBL_ACTIVE_ADDRESS)
	{
		Dcm_SendNrc(DCM_E_31_REQUEST_OUT_OF_RANGE);
	}
	else
	{
		/* wait for pending , Send nrc 78*/
		Dcm_SendPending();
	}
#else
	txBuff->pduInfo.SduDataPtr[4] = 0x10u;
	txBuff->pduInfo.SduLength 	  = 0x05u;
	Dcm_SendRsp();
#endif

}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*=======[E N D   O F   F I L E]==============================================*/
