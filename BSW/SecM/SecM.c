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
**  FILENAME    :  SecM.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION :  seed and key generate for UDS                              **
**                                                                            **
**  SPECIFICATION(S) : NONE                       		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20121109    Gary         Initial version
 *  V1.0.1      20130517    liuyp        modify the generate key algorithm
 *  V1.0.2      20130913    ccl          update
 *  V1.0.3      20180511    CChen        update
 *  V1.0.4      20200426    Lianren.wu   modify function: SecM_ProcessCal
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:SecM .<br>
  RuleSorce:puhua-rule2024.rcf 1.0.2

	\li PRQA S 0306  Rule 11.4 .<br>
    Reason: The integral type expression address

    \li PRQA S 2741  Rule 14.3 .<br>
    Reason: The macro is configurable in Secm_Cfg.h
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "SecM.h"
#include "Appl.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static SecM_StatusType SecM_Verify_SegmentList(uint8 VBTSegmentNo,
											   const SecM_VerifyParamType *verifyParam,
											   const FL_SegmentInfoType* VBFInfo);

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*Transmits data to calculate CRC values in real time. */
static SecM_CRCParamType crcParamCal;
#if(STD_ON == SECM_HSM_ENABLED)
static hseHashData_t HseHashData;
static uint8 gHse_hashValue[32];
#else
static Sha256Calc Sha256CalcValue;
#endif

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <compute CRC>
 *
 * <process CRC compute,include init,compute and finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <crcParam (IN/OUT)>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
SecM_StatusType SecM_ComputeCRC(SecM_CRCParamType* crcParam)
{
    SecM_StatusType retVal = (uint8)SECM_OK;

    switch (crcParam->crcState)
    {
    case SECM_CRC_INIT:
        /* CRC value initialize */
        Cal_CrcInit(&crcParam->currentCRC);
        break;
    case SECM_CRC_COMPUTE:
        /* CRC value compute */
        Cal_CrcCal(&crcParam->currentCRC, crcParam->crcSourceBuffer, (uint32)crcParam->crcByteCount);
        break;
    case SECM_CRC_FINALIZE:
        /* CRC value finish */
        Cal_CrcFinalize(&crcParam->currentCRC);
        break;
    default:
        retVal = (uint8)SECM_NOT_OK;
        break;
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <Real time compute CRC.>
 *
 * <process CRC compute,include init,compute and finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <crcState
 * 						crcByteCount
 * 						crcSourceBuffer>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void SecM_RealTimeComputeCRC(const uint8* crcSourceBuffer,uint32 crcByteCount,uint8 crcState)
{
    switch (crcState)
    {
		case SECM_CRC_INIT:
			/* CRC value initialize */
			crcParamCal.currentCRC = 0;
			Cal_CrcInit(&crcParamCal.currentCRC);
			break;
		case SECM_CRC_COMPUTE:
			/* CRC value compute */
			crcParamCal.crcSourceBuffer = crcSourceBuffer;
			crcParamCal.crcByteCount = crcByteCount;
			Cal_CrcCal(&crcParamCal.currentCRC, crcParamCal.crcSourceBuffer, crcParamCal.crcByteCount);
			break;
		case SECM_CRC_FINALIZE:
			/* CRC value finish */
			Cal_CrcFinalize(&crcParamCal.currentCRC);
			break;
		default:
			/*empty*/
			break;
    }
}
/******************************************************************************/
/**
 * @brief               <verificate CRC value>
 * <verificate if transfered CRC is equal to computed CRC> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <verifyParam (IN/OUT)>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
SecM_StatusType SecM_Verification(const SecM_VerifyParamType* verifyParam) 
{
    SecM_StatusType retVal = (uint8)SECM_OK;
    SecM_CRCType transferedCrc;

    if (NULL_PTR == verifyParam->segmentList)
    {
        /* if segment list is NULL, verification is failed */
        retVal = (uint8)SECM_NOT_OK;
    }

    if ((uint8)SECM_OK == retVal)
    {
        /* get CRC transfered from client */
#if (CAL_CRC32 == CAL_METHOD)
        /* CRC32 */
        transferedCrc = DP_Get4Byte(verifyParam->verificationData);
#elif (CAL_CRC16 == CAL_METHOD)
        /* CRC16 */
        transferedCrc = ((SecM_CRCType)verifyParam->verificationData[0] << 8U);
        transferedCrc += (SecM_CRCType)verifyParam->verificationData[1];
#else
        /* CRC8 */
#endif
        /* compare CRC */
        if (transferedCrc != crcParamCal.currentCRC)
        {
            retVal = (uint8)SECM_NOT_OK;
        }
        else
        {
            /* do nothing */
        }
    }
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <verificate RSA value>
 *
 * <verificate if transfered RSA is equal to computed RSA> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <verifyParam (IN/OUT)>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
SecM_StatusType SecM_Verification_RSA(const SecM_VerifyParamType *verifyParam)
{
	SecM_StatusType   	ret = SECM_VERIFICATION_PASSED;
	uint8             	segmentIndex;
	boolean 		  	processContinue = FALSE;

#if(STD_ON == SECM_HSM_ENABLED)
	uint8 hashValue[32];
	hseHashData_t hseHashData;
	uint8 hse_hashValue[32];
	uint32 len = 32;
#else
	Sha256Calc			sha256CalcValue;
#endif
	uint8 				VBTSegmentNo = 0u;
	const FL_SegmentInfoType  * VBFInfo;

	uint8				tempbuf[4u];
	uint32				tempAddr;

	uint32 				CurrentVBTAddress = 0u;
	uint32				calculatedLength;
	uint32              roundupLength;



#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
#else
    uint8 index = FL_GetFldownloadStatusIndex();
#endif

	if ((NULL_PTR == verifyParam->segmentList)
	 || (0u == verifyParam->segmentList->nrOfSegments))
	{
		/* if segment list is NULL, verification is failed */
		ret = SECM_NO_DATA_DOWNLOADED_AT_ALL_NOTHING_TO_VERIFY;
		processContinue = FALSE;
	}
	else
	{
		/* find & get the VBT data-block*/
		for (segmentIndex = (uint8)0;
			segmentIndex < verifyParam->segmentList->nrOfSegments;
			segmentIndex++)
		{

#if (APPL_BOOT_MODE == APPL_BOOT_MODE_SBL)
		CurrentVBTAddress = Appl_ConvertAddress(FL_essInfo.logicalBlockLayoutStruct[index].verificationBlockTableAddress);
#elif(APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
		CurrentVBTAddress = (uint32)FL_SBL_VBT_ADDRESS;
#endif
			if(CurrentVBTAddress == verifyParam->segmentList->segmentInfo[segmentIndex].address)
			{
				/* get the index of the VBT block in the segment */
				VBTSegmentNo = segmentIndex;
				processContinue = TRUE;
				break;
			}
			else
			{
				/*if not find the VBT info, that means can't to verify,(nothing to verify)*/
				ret = SECM_CERTIFICATE_VERIFICATION_FAILED;
				processContinue = FALSE;
			}
		}
	}
	/*if the VBT is valid, and the segment check is right,
	 */
	/*check the complete of the VBT */
	if(processContinue == TRUE)
	{
		calculatedLength = ((((uint32)verifyParam->segmentList->nrOfSegments - 1u) * 40U) + 4U);
#if (FL_VBT_ALIGN_SIZE > 0)
		/* in case of alignment, round up VBT length */
		roundupLength = FL_VBT_ALIGN_SIZE * (((calculatedLength-1u) / FL_VBT_ALIGN_SIZE) + 1u);
#else
		roundupLength = calculatedLength;
#endif
		if(verifyParam->segmentList->segmentInfo[VBTSegmentNo].length != roundupLength)
		{
			/* processContinue is FALSE */
			ret = SECM_INVALIDFORMAT_OR_LENGTH_OF_THE_VERIFICATION_BLOCK_TABLE;
			processContinue = FALSE;
		}
		/*The address or hash values of the downloaded data blocks does not match the expected values*/
		else
		{
#if (FL_VBT_ALIGN_SIZE > 0)
			uint32 				i;
			for(i=0u; i<(roundupLength-calculatedLength); i++)
			{
				/* check if padding value equals to configured value */
				if(*((const uint8*)(verifyParam->segmentList->segmentInfo[VBTSegmentNo].address)+calculatedLength+i) != (uint8)FL_VBT_ALIGN_VALUE)/*PRQA S 0488,0306*/
				{
					/* processContinue is FALSE */
					ret = SECM_INVALIDFORMAT_OR_LENGTH_OF_THE_VERIFICATION_BLOCK_TABLE;
					processContinue = FALSE;
					break;
				}
			}
#endif
			if(processContinue == TRUE)
			{
				/* get the start address of first data-block info except the VBT data-block*/
				VBFInfo = (FL_SegmentInfoType*)(CurrentVBTAddress + 4u);/*PRQA S 0306*/

				/*process verify-param SegmentList NrOfSegments data*/
				ret = SecM_Verify_SegmentList(VBTSegmentNo, verifyParam, VBFInfo);
				if(ret != SECM_VERIFICATION_PASSED)
				{
					processContinue = FALSE;
				}
			}
		}
	}

	/*
	 * then verify the sign��
	 * The signed data could be authenticate
	 */
	if(processContinue == TRUE)
	{
		/* initialize Hash */
#if(STD_ON == SECM_HSM_ENABLED)
        (void)hse_hashif_init(&hseHashData);
#else
		(void)Sha256Calc_init(&sha256CalcValue);
#endif
		/* fixme:  because the address of VBT is 0x8000000,
		 * so should change 0xAxxxxxxx to 0x8xxxxxxx */
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
		tempAddr = verifyParam->segmentList->segmentInfo[VBTSegmentNo].address;
#else
		tempAddr = verifyParam->segmentList->segmentInfo[VBTSegmentNo].address & 0xDFFFFFFFu;
#endif

		/* get the hash value of the address of the VBT data-block */
		DP_Set4Byte(tempAddr, tempbuf);
#if(STD_ON == SECM_HSM_ENABLED)
		(void)hse_hashif_updata(&hseHashData,tempbuf,4u);
#else
		(void)Sha256Calc_calculate(&sha256CalcValue, tempbuf, 4u);
#endif

		/* get the hash value of the length of the VBT data-block */
		DP_Set4Byte(calculatedLength, tempbuf);
#if(STD_ON == SECM_HSM_ENABLED)
		(void)hse_hashif_updata(&hseHashData,tempbuf,4u);
#else
		(void)Sha256Calc_calculate(&sha256CalcValue, tempbuf, 4u);
#endif

		/* get the hash value of the data of VBT data-block */
#if(STD_ON == SECM_HSM_ENABLED)
		(void)hse_hashif_updata(&hseHashData,(uint8*)CurrentVBTAddress, calculatedLength);		
#else
		(void)Sha256Calc_calculate(&sha256CalcValue, (uint8*)CurrentVBTAddress, calculatedLength);/*PRQA S 0306*/
#endif

		/* verify the sw_signature*/
#if(STD_ON == SECM_HSM_ENABLED)
		uint32 signlen0 = 0x100;
		(void)hse_hashif_finish(&hseHashData,hse_hashValue,&len);
        DP_Memcpy(hashValue,hse_hashValue,32);
		if((Std_ReturnType)E_OK != HSEIf_Rsa2048Ver(SHA256_LENGTH,hashValue,&signlen0,verifyParam->verificationData))
#else
		if(TRUE != Rsa_verify(sha256CalcValue.Value, SHA256_LENGTH, verifyParam->verificationData, 0x100u))
#endif
		{
			ret = SECM_THE_SIGNED_DATA_COULD_NOT_BE_AUTHENTICATED;
		}
	}

	return ret;
}
/******************************************************************************/
/**
 * @brief               <Sha256 Calc init>
 *
 * <Sha256 Calc init> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE)>
 * @return              <NONE>
 */
/******************************************************************************/
void SecM_Sha256CalcInit(void)
{
#if(STD_ON == SECM_HSM_ENABLED)
	(void)hse_hashif_init(&HseHashData);
#else
	(void)Sha256Calc_init(&Sha256CalcValue);
#endif
}
/******************************************************************************/
/**
 * @brief               <Sha256 Calc Calculate>
 *
 * <Sha256 Calc Calculate> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE)>
 * @return              <NONE>
 */
/******************************************************************************/
void SecM_Sha256CalcCalculate(const uint8* dp, uint32 dl)
{
#if(STD_ON == SECM_HSM_ENABLED)
	(void)hse_hashif_updata(&HseHashData,dp,dl);
#else
	(void)Sha256Calc_calculate(&Sha256CalcValue, dp, dl);
#endif
}
/******************************************************************************/
/**
 * @brief               <Get Sha256 Calc Calculate Value>
 *
 * <Get Sha256 Calc Calculate Value> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE)>
 * @return              <NONE>
 */
/******************************************************************************/
uint8 * SecM_GetSha256CalcCalculateValue(void)
{
#if(STD_ON == SECM_HSM_ENABLED)
	uint32 len = 32;
    (void)hse_hashif_finish(&HseHashData,gHse_hashValue,&len);
    return gHse_hashValue;
#else
	return Sha256CalcValue.Value;
#endif
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <process>
 *
 * <process verifyparam SegmentList NrOfSegments data> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <VBTSegmentNo(IN) verifyParam(IN) VBFInfo(IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <ret >
 */
/******************************************************************************/
static SecM_StatusType SecM_Verify_SegmentList(uint8 VBTSegmentNo, const SecM_VerifyParamType *verifyParam, const FL_SegmentInfoType* VBFInfo)
{
	SecM_StatusType   	ret = SECM_VERIFICATION_PASSED;
	uint8			  	segmentIndex;
	boolean 		  	processContinue = FALSE;
	uint8				addrbuf[4u];
	uint8				lenbuf[4u];
	uint32				tempAddr;
	const FL_SegmentInfoType* inputVBFInfo = VBFInfo;
	for (segmentIndex = 0u;
		 segmentIndex < verifyParam->segmentList->nrOfSegments;
		 segmentIndex++)
	{
		if( segmentIndex == VBTSegmentNo)
		{
			/* jump the VBT Data-block(segment) */
			continue;
		}
		else
		{
			/* fixme:  because the address of VBT is 0x8000000,
			 * so should change 0xAxxxxxxx to 0x8xxxxxxx */
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
			tempAddr = verifyParam->segmentList->segmentInfo[segmentIndex].address;
#else
			tempAddr = verifyParam->segmentList->segmentInfo[segmentIndex].address;
#endif
			/*because the data store mode is difference, so need to change one */
			DP_Set4Byte(tempAddr, addrbuf);
			DP_Set4Byte(verifyParam->segmentList->segmentInfo[segmentIndex].length,  lenbuf);

			/* compare the address of vbfInfo */
			processContinue = DP_Memcompare((const uint8*)&(inputVBFInfo->address) , addrbuf, 4u);

			if(processContinue == TRUE)
			{
				/* compare the length of vbfInfo */
				processContinue = DP_Memcompare((const uint8*)&(inputVBFInfo->length),  lenbuf,	4u);
			}

			if(processContinue == TRUE)
			{
				/* compare the sha256Info of vbfInfo, 32bytes */
				processContinue =DP_Memcompare(inputVBFInfo->sha256Info,
												 verifyParam->segmentList->segmentInfo[segmentIndex].sha256Info,
												 (uint32)SHA256_LENGTH);
			}

			if(processContinue == TRUE)
			{
				/*if is the same, to check the next segment
				 *else return is not OK.
				 **/
				inputVBFInfo++;
			}
			else
			{
				ret = SECM_THE_ADDR_OR_HASH_OF_THE_DOWN_DATA_BLOCKS_DONOT_MATCH_THE_EXPECTED_VALUSE;
				break;
			}
		}
	}
	return ret;
}


