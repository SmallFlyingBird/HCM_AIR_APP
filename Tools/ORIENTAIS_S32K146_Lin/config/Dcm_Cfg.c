/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-12 15:33:32>
 */
/*============================================================================*/

/******************************* references ************************************/
#include "Dcm_Types.h"
#include "Rte_Dcm.h"
#include "Dcm_Cfg.h"
#if(STD_ON == DCM_UDS_FUNC_ENABLED)
#include "UDS.h"
#endif
#if(STD_ON == DCM_OBD_FUNC_ENABLED)
#include "OBD.h"
#endif

/**********************************************************************
 ***********************DcmGeneral Container***************************
 **********************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_GeneralCfgType,DCM_CONST)Dcm_GeneralCfg =
{
    FALSE, /*DcmDDDIDStorage*/
	DCM_DEV_ERROR_DETECT, /*DcmDevErrorDetect*/			
	NULL_PTR, /*DcmHeaderFileInclusion*/							
	DCM_RESPOND_ALL_REQUEST, /*DcmRespondAllRequest*/			
	DCM_VERSION_INFO_API, /*DcmVersionInfoApi*/				
	10, /*DcmTaskTime*/
	NULL_PTR, /*DcmVinRef*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSP container configration*****************************
 *****************************************************************************************/


/**********************Clear DTC**************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspClearDTCType, DCM_CONST) Dcm_DspClearDTCCfg =
{
	NULL_PTR, /*DcmDsp_ClearDTCCheckFnc*/
	NULL_PTR, /*DcmDspClearDTCModeRuleRef*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Control DTC Setting********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspControlDTCSettingType, DCM_CONST) Dcm_DspControlDTCSettingCfg =	
{
	FALSE, /*DcmSupportDTCSettingControlOptionRecord*/
	NULL_PTR, /*DcmDspControlDTCSettingReEnableModeRuleRef*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Com Control********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannelCfg[1] = 
{
	{
		TRUE, /*DcmDspComControlAllChannelUsed*/
		0u, /*DcmDspComMChannelId*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControlCfg =
{
	1u, /*DcmDspComControlAllChannelNum*/
	&Dcm_DspComControlAllChannelCfg[0], /*DcmDspComControlAllChannel*/	
	NULL_PTR, /*DcmDspComControlSetting*/								
	0u, /*DcmDspComControlSpecificChannelNum*/								
	NULL_PTR, /*DcmDspComControlSpecificChannel*/	
	0u, /*DcmDspComControlSubNodeNum*/								
	NULL_PTR /*DcmDspComControlSubNode*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Common Authorization********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_0_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspCommonAuthorizationType, DCM_CONST) Dcm_DspCommonAuthorizationCfg[1] =
{
	{
		NULL_PTR, /*DcmDspCommonAuthorizationModeRuleRef*/
		0u,	 /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
		NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
		2u, /*DcmDspCommonAuthorizationSessionRefNum*/
		&DcmDspCommonAuthorization_0_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspDataCfg[21] =
{
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF193, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		32u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF195, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		32u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_OPAQUE, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataRead_4B40, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		Rte_ReturnControlToECU_4B40, /*DcmDspDataReturnControlToECUFnc*/		
		Rte_ShortTermAdjustment_4B40, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		8u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF010, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		32u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF110, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		Rte_WriteData_F110, /*DcmDspDataWriteFnc*/		
		88u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF111, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		Rte_WriteData_F111, /*DcmDspDataWriteFnc*/		
		16u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF118, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		88u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF119, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		16u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF15B, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		96u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF186, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		8u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF187, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		Rte_WriteData_F187, /*DcmDspDataWriteFnc*/		
		88u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_ASYNCH_FNC_ERROR, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF18A, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		64u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF18B, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		Rte_WriteData_F18B, /*DcmDspDataWriteFnc*/		
		24u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF18C, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		Rte_WriteData_F18C, /*DcmDspDataWriteFnc*/		
		80u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF192, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		66u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF194, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		68u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF197, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		64u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF199, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		24u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF19E, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		24u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		DcmDspDataReadF150, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		24u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	},
	{
		NULL_PTR,	 /*DcmDspDataConditionCheckReadFnc*/	
		FALSE, /*DcmConditionCheckReadFncUsed*/	
		NULL_PTR,	 /*DcmDspDataEcuSignalFnc*/	
		NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/	
		DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/	
		NULL_PTR,	 /*DcmDspDataFreezeCurrentsStateFnc*/	
		NULL_PTR,	 /*DcmDspDataGetScalingInfoFnc*/	
		NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/		
		NULL_PTR, /*DcmDspDataReadFnc*/		
		NULL_PTR, /*DcmDspDataResetToDefaultFnc*/	
		NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/		
		NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/		
		NULL_PTR, /*DcmDspDataWriteFnc*/		
		96u, /*DcmDspDataSize*/	
		DCM_UINT8, /*DcmDspDataType*/	
		USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/	
		0u, /*DcmDspDataBlockId*/
		0xffu, /*DcmDspDataInfoIndex*/	
		NULL_PTR, /*DcmDspDiagnosisScaling*/	
		NULL_PTR /*DcmDspExternalSRDataElementClass*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/********************Dsp Did******************************/
/******************************************
 *DcmDspDidRead container configration
 *****************************************/																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_0_Read_SesRefCfg[3] = {1u, 3u, 112u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_0_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    3u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_0_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_1_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u, /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_2_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u, /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Read_SecRefCfg[3] = {1u, 2u, 4u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Read_SesRefCfg[2] = {3u, 112u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_4_ReadCfg =
{
    3u, /*DcmDspDidReadSecurityLevelRefNum*/
    &Dcm_DidInfo_4_Read_SecRefCfg[0], /*pDcmDspDidReadSecurityLevelRow*/
    2u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_4_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_5_Read_SesRefCfg[3] = {1u, 3u, 112u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_5_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    3u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_5_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidWrite container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Write_SecRefCfg[3] = {1u, 2u, 4u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_2_WriteCfg= 
{
    3u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_2_Write_SecRefCfg[0],	/*pDcmDspDidWriteSecurityLevelRow*/
    1u,	/*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_2_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/						
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_3_Write_SecRefCfg[1] = {4u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_3_Write_SesRefCfg[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_3_WriteCfg= 
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_3_Write_SecRefCfg[0],	/*pDcmDspDidWriteSecurityLevelRow*/
    1u,	/*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_3_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/						
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_5_Write_SesRefCfg[1] = {112u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_5_WriteCfg= 
{
    0u,/*DcmDspDidWriteSecurityLevelRefNum*/
    NULL_PTR,	/*pDcmDspDidWriteSecurityLevelRow*/
    1u,	/*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_5_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/						
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidControl container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Control_SecRefCfg[1]= {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Control_SesRefCfg[1]={3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
																		
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidControlEnableMaskType,DCM_CONST)Dcm_DidInfo_1_ControlEnableMaskCfg[1]= 
{
	{
		0u, /*DcmDspDidControlMaskBitPosition*/
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidControlType,DCM_CONST) Dcm_DidInfo_1_ControlCfg = 
{
	DCM_CONTROLMASK_EXTERNAL, /*DcmDspDidControlMask*/
	1u, /*DcmDspDidControlMaskSize*/	
    1u, /*DcmDspDidControlSecurityLevelRefNum*/
    &Dcm_DidInfo_1_Control_SecRefCfg[0], /*pDcmDspDidControlSecurityLevelRow*/
    1u, /*DcmDspDidControlSessionRefNum*/
    &Dcm_DidInfo_1_Control_SesRefCfg[0], /*pDcmDspDidControlSessionRow*/
    FALSE, /*DcmDspDidFreezeCurrentState*/
	FALSE, /*DcmDspDidResetToDefault*/
    TRUE, /*DcmDspDidShortTermAdjustement*/	
	&Dcm_DidInfo_1_ControlEnableMaskCfg[0], /*DcmDspDidControlEnableMask*/	
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
	
/******************************************
 *DcmDspDidInfo container Configuration ***
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidInfoType,DCM_CONST)Dcm_DspDidInfoCfg[6] = 
{
    {
        0u, /*DcmDspDDDIDMaxElements*/	
    	FALSE, /*DcmDspDidDynamicallyDefined*/	
		NULL_PTR, /*pDcmDspDidControl*/	
		&Dcm_DidInfo_0_ReadCfg, /*pDcmDspDidRead*/	
		NULL_PTR, /*pDcmDspDidWrite*/	
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/	
    	FALSE, /*DcmDspDidDynamicallyDefined*/	
		&Dcm_DidInfo_1_ControlCfg, /*pDcmDspDidControl*/	
		&Dcm_DidInfo_1_ReadCfg, /*pDcmDspDidRead*/	
		NULL_PTR, /*pDcmDspDidWrite*/	
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/	
    	FALSE, /*DcmDspDidDynamicallyDefined*/	
		NULL_PTR, /*pDcmDspDidControl*/	
		&Dcm_DidInfo_2_ReadCfg, /*pDcmDspDidRead*/	
		&Dcm_DidInfo_2_WriteCfg, /*pDcmDspDidWrite*/	
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/	
    	FALSE, /*DcmDspDidDynamicallyDefined*/	
		NULL_PTR, /*pDcmDspDidControl*/	
		NULL_PTR, /*pDcmDspDidRead*/	
		&Dcm_DidInfo_3_WriteCfg, /*pDcmDspDidWrite*/	
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/	
    	FALSE, /*DcmDspDidDynamicallyDefined*/	
		NULL_PTR, /*pDcmDspDidControl*/	
		&Dcm_DidInfo_4_ReadCfg, /*pDcmDspDidRead*/	
		NULL_PTR, /*pDcmDspDidWrite*/	
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/	
    	FALSE, /*DcmDspDidDynamicallyDefined*/	
		NULL_PTR, /*pDcmDspDidControl*/	
		&Dcm_DidInfo_5_ReadCfg, /*pDcmDspDidRead*/	
		&Dcm_DidInfo_5_WriteCfg, /*pDcmDspDidWrite*/	
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F193_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[0],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F195_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[1],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4B40_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[2],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F010_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[3],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F110_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[4],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F111_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[5],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F118_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[6],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F119_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[7],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F15B_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[8],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F186_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[9],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F187_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[10],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18A_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[11],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18B_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[12],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18C_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[13],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F192_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[14],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F194_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[15],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F197_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[16],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F199_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[17],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F19E_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[18],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F150_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[19],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F15A_SignalCfg[1] = 
{
	{
		0u,                   /*DcmDspDidDataPos*/		
		&Dcm_DspDataCfg[20],	 /*pDcmDspDidData*/	
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/**********************************************
 *DcmDspDid container configration*************
 **********************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspDidType,DCM_CONST)Dcm_DspDidCfg[21] =
{
    { /* Did_0xF193 */
        0xF193u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F193_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF195 */
        0xF195u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F195_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0x4B40 */
        0x4B40u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        1u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_4B40_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF010 */
        0xF010u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F010_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF110 */
        0xF110u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        5u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F110_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF111 */
        0xF111u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        5u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F111_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF118 */
        0xF118u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F118_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF119 */
        0xF119u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F119_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF15B */
        0xF15Bu,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        4u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F15B_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF186 */
        0xF186u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F186_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF187 */
        0xF187u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        2u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F187_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF18A */
        0xF18Au,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F18A_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF18B */
        0xF18Bu,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        5u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F18B_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF18C */
        0xF18Cu,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        5u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F18C_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF192 */
        0xF192u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F192_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF194 */
        0xF194u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F194_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF197 */
        0xF197u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F197_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF199 */
        0xF199u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F199_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF19E */
        0xF19Eu,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F19E_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF150 */
        0xF150u,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        0u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F150_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    },
    { /* Did_0xF15A */
        0xF15Au,	 /*DcmDspDidId*/	
		TRUE,	 /*DcmDspDidUsed*/	
        3u,	 /*DcmDspDidInfoIndex*/		
        0u,	 /*DcmDspRefDidNum*/	
        NULL_PTR,	 /*pDcmDspRefDidIdArray*/	
        1u, /*DcmDspDidSignalNum*/	
        &Dcm_Did_F15A_SignalCfg[0],	 /*pDcmDspDidSignal*/	
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"






/******************Dsp Routine**************/
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x203_SignalCfg[2] = 
{
	{
		DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/	
		0u, /*DcmDspRoutineSignalLength*/	
		0u, /*DcmDspRoutineSignalPos*/
		DCM_SINT16, /*DcmDspRoutineSignalType*/	
		NULL_PTR, /*DcmDspArgumentScaling*/										
	},
	{
		DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/	
		8u, /*DcmDspRoutineSignalLength*/	
		0u, /*DcmDspRoutineSignalPos*/
		DCM_SINT32, /*DcmDspRoutineSignalType*/	
		NULL_PTR, /*DcmDspArgumentScaling*/										
	},	
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
/***********************************
 *DcmDspRoutineStart container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x203_StartRoutineInCfg =
{	
	1u,                                  /*RoutineInOutSignalNum*/	
	&Dcm_Routine_0x203_SignalCfg[0],	/*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x203_StartRoutineOutCfg = 
{	
	1u,                                  /*RoutineInOutSignalNum*/	
	&Dcm_Routine_0x203_SignalCfg[1],	/*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x203_StartCfg =
{
     Rte_DcmRoutineStart_0203, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0x203_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x203_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************
 *DcmDspRoutineStop container
 **********************************/


/***********************************
 *DcmDspRoutine container configration
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspRoutineType,DCM_CONST)Dcm_DspRoutineCfg[1] =
{
    { /* DcmDspRoutine_0203 */
        0x203u, /*DcmDspRoutineId*/
		0u, /*DcmDspRoutineInfoByte*/ 
		FALSE, /*DcmDspRoutineUsePort*/	
		TRUE,	 /*DcmDspRoutineUsed*/
		&Dcm_DspCommonAuthorizationCfg[0],	 /*DcmDspCommonAuthorizationRef*/	
		NULL_PTR, /*DcmDspStopRoutineIn*/					
		&Dcm_RoutineInfo_0x203_StartCfg, /*DcmDspRequestRoutineResults*/
		NULL_PTR, /*DcmDspStopRoutine*/			
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Security Row**************/
/************************************************
 ****DcmDspSecurityRow container(Multiplicity=0..31)****
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspSecurityRowType,DCM_CONST)Dcm_DspSecurityRow[3] =
{
    { /* DcmDspSecurityRow_1 */	
        1u,      	/*DcmDspSecurityLevel*/			
        4u,      	/*DcmDspSecuritySeedSize*/		
        4u,      	/*DcmDspSecurityKeySize*/		
        0u,      	/*DcmDspSecurityADRSize*/	
		TRUE,		/*DcmDspSecurityAttemptCounterEnabled*/
        3u,    /*DcmDspSecurityNumAttDelay*/	
        10000u,  /*DcmDspSecurityDelayTime,10s */			
        0u,/*DcmDspSecurityDelayTimeOnBoot*/				
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_GetSeed,	/*Dcm_GetSeedFnc*/	
		Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_CompareKey,	/*Dcm_CompareKeyFnc*/
		Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_GetSecurityAttemptCounter,	/*Dcm_GetSecurityAttemptCounterFnc*/
		Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_SetSecurityAttemptCounter,	/*DcmDspSecurityUsePort*/
		USE_ASYNCH_FNC,	/*DcmDspSecurityUsePort*/
    },
    { /* DcmDspSecurityRow_2 */	
        2u,      	/*DcmDspSecurityLevel*/			
        4u,      	/*DcmDspSecuritySeedSize*/		
        4u,      	/*DcmDspSecurityKeySize*/		
        0u,      	/*DcmDspSecurityADRSize*/	
		TRUE,		/*DcmDspSecurityAttemptCounterEnabled*/
        3u,    /*DcmDspSecurityNumAttDelay*/	
        10000u,  /*DcmDspSecurityDelayTime,10s */			
        0u,/*DcmDspSecurityDelayTimeOnBoot*/				
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_GetSeed,	/*Dcm_GetSeedFnc*/	
		Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_CompareKey,	/*Dcm_CompareKeyFnc*/
		Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_GetSecurityAttemptCounter,	/*Dcm_GetSecurityAttemptCounterFnc*/
		Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_SetSecurityAttemptCounter,	/*DcmDspSecurityUsePort*/
		USE_ASYNCH_FNC,	/*DcmDspSecurityUsePort*/
    },
    { /* DcmDspSecurityRow_4 */	
        4u,      	/*DcmDspSecurityLevel*/			
        4u,      	/*DcmDspSecuritySeedSize*/		
        4u,      	/*DcmDspSecurityKeySize*/		
        0u,      	/*DcmDspSecurityADRSize*/	
		TRUE,		/*DcmDspSecurityAttemptCounterEnabled*/
        3u,    /*DcmDspSecurityNumAttDelay*/	
        10000u,  /*DcmDspSecurityDelayTime,10s */			
        0u,/*DcmDspSecurityDelayTimeOnBoot*/				
        NULL_PTR,	/*Dcm_GetSeedFnc*/	
		NULL_PTR,	/*Dcm_CompareKeyFnc*/
		NULL_PTR,	/*Dcm_GetSecurityAttemptCounterFnc*/
		NULL_PTR,	/*DcmDspSecurityUsePort*/
		USE_ASYNCH_FNC,	/*DcmDspSecurityUsePort*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/************************************************
 ****DcmDspSecurity container(Multiplicity=1)****
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspSecurityType,DCM_CONST)Dcm_DspSecurity =
{
    &Dcm_DspSecurityRow[0],	/*pDcm_DspSecurityRow*/								
    3u,	/*DcmDspSecurityRow_Num*/	
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Session Row**************/
/************************************************
 ****DcmDspSessionRow container(Multiplicity=0..31)
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspSessionRowType,DCM_CONST)Dcm_DspSessionRow[4] =
{
    { /* DcmDspSessionRow_01 */
        DCM_NO_BOOT,	/*DcmDspSessionForBoot*/
    	1u,	/*DcmDspSessionLevel*/
        50u,	/*DcmDspSessionP2ServerMax*/	
        2000u,	/*DcmDspSessionP2StarServerMax*/	
    },
    { /* DcmDspSessionRow_02 */
        DCM_SYS_BOOT,	/*DcmDspSessionForBoot*/
    	2u,	/*DcmDspSessionLevel*/
        50u,	/*DcmDspSessionP2ServerMax*/	
        2000u,	/*DcmDspSessionP2StarServerMax*/	
    },
    { /* DcmDspSessionRow_03 */
        DCM_NO_BOOT,	/*DcmDspSessionForBoot*/
    	3u,	/*DcmDspSessionLevel*/
        50u,	/*DcmDspSessionP2ServerMax*/	
        2000u,	/*DcmDspSessionP2StarServerMax*/	
    },
    { /* DcmDspSessionRow_70 */
        DCM_NO_BOOT,	/*DcmDspSessionForBoot*/
    	112u,	/*DcmDspSessionLevel*/
        50u,	/*DcmDspSessionP2ServerMax*/	
        2000u,	/*DcmDspSessionP2StarServerMax*/	
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/************************************************
 *******Dcm_DspSession container(Multiplicity=1)*
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static CONST(Dcm_DspSessionType,DCM_CONST)Dcm_DspSession =
{
    &Dcm_DspSessionRow[0],	/*pDcmDspSessionRow*/								
    4u,		/*DcmDspSessionRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*****************************************************
 ****************DcmDsp container configration********
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DspCfgType,DCM_CONST) Dcm_DspCfg =
{
	NULL_PTR,	/*DcmDspDDDIDcheckPerSourceDID*/
	DCM_BIG_ENDIAN,	/*DcmDspDataDefaultEndianness*/								
	FALSE,/*DcmDspEnableObdMirror*/			
    0,/*DcmDspMaxDidToRead*/								
    DCM_DSP_MAX_PERIODIC_DID_TO_READ,/*DcmDspMaxPeriodicDidToRead*/						
	0u,/*DcmDspPowerDownTime*/								
	AFTER_RESET,	/*DcmResponseToEcuReset*/	

	&Dcm_DspClearDTCCfg,		/*pDcmDspClearDTC*/	
	&Dcm_DspComControlCfg,		/*pDcmDspComControl*/	
	&Dcm_DspCommonAuthorizationCfg[0],		/*pDcmDspCommonAuthorization*/	
	&Dcm_DspControlDTCSettingCfg,	/*pDcmDspControlDTCSetting*/	
	
	&Dcm_DspDataCfg[0],	/*pDcmDspData*/	
	NULL_PTR,	/*pDcmDspDataInfo*/	
	
	
	21u,	/*DcmDspDidNum*/	
    &Dcm_DspDidCfg[0],		/*pDcmDspDid*/									
	6u,	/*DcmDspDidInfoNum*/	
    &Dcm_DspDidInfoCfg[0],		/*pDcmDspDidInfo*/								
	0u,	/*DcmDspDidRangeNum*/	
	NULL_PTR,		/*pDcmDspDidRange*/								
	
	NULL_PTR, /*pDcmDspMemory*/
	
    NULL_PTR,	/*DcmDspRequestFileTransfer*/	
    
    1u,		/*DcmDspRoutineNum*/	
    &Dcm_DspRoutineCfg[0],	/*pDcmDspRoutine*/									
   
    &Dcm_DspSecurity,  /* pDcm_DspSecurity */				
    &Dcm_DspSession,  /* pDcm_DspSession */	
   					
    
    DCM_DSP_MAX_PERIODIC_DID_SCHEDULER,
    NULL_PTR
}; 
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSD container configration*****************************
 *****************************************************************************************/

/*DcmDsdService_10 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x10_2_SesRef[3] = {3u, 2u, 112u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x10_3_SesRef[3] = {1u, 3u, 112u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x10[4] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x1u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x2u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x10_2_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		3u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x3u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x10_3_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		3u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x70u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*DcmDsdService_11 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x11[1] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x1u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*DcmDsdService_19 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x19[4] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x1u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x2u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x6u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0xAu,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*DcmDsdService_27 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x27_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x27_2_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x27_3_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x27_4_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x27_7_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x27_8_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x27[6] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x1u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x27_1_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x2u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x27_2_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x3u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x27_3_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x4u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x27_4_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x7u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x27_7_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x8u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x27_8_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*DcmDsdService_28 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x28_0_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x28_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x28[2] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x0u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x28_0_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x1u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x28_1_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		1u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*DcmDsdService_31 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x31_1_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x31[1] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x1u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		&Dcm_UDS0x31_1_SesRef[0],	/*DcmDsdSubServiceSessionLevelRef*/	
		2u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*DcmDsdService_3E SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x3E[1] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x0u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*DcmDsdService_85 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)DcmDsdSubService_UDS0x85[2] =	
{
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x1u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	},
	{
		NULL_PTR,	/*DcmDsdSubServiceFnc*/	
		0x2u,	/*DcmDsdSubServiceId*/	
		TRUE,	/*DcmDsdSubServiceUsed*/	
		NULL_PTR,	/*DcmDsdSubServiceModeRuleRef*/	
		NULL_PTR,	/*DcmDsdSubServiceSecurityLevelRef*/	
		0u,	/*DcmDsdSubServiceSecurityLevel_Num*/		
		NULL_PTR,	/*DcmDsdSubServiceSessionLevelRef*/	
		0u	/*DcmDsdSubServiceSessionLevel_Num*/		
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*UDS Service session and security configuration*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x11_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x14_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x19_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x27_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x28_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x2E_SesRef[3] = {3u, 2u, 112u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x2F_SecRef[2] = {1u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x2F_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x31_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(uint8,DCM_CONST)Dcm_UDS0x85_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"



#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
/*DcmDsdService DcmDsdServiceTable*/	
CONST(Dcm_DsdServiceCfgType,DCM_CONST)DcmDsdServiceTable_Service[12] =
{
	{ /*DiagnosticSessionControl*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x10,	/*DcmDsdSidTabFnc*/
		0x10u,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		0u,	/*DcmDsdSessionLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSessionLevelRef*/
		4u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x10[0],	/*DcmDsdSubService*/
	},
	{ /*ECUReset*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x11,	/*DcmDsdSidTabFnc*/
		0x11u,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		1u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x11_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		1u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x11[0],	/*DcmDsdSubService*/
	},
	{ /*ClearDiagnosticInformation*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x14,	/*DcmDsdSidTabFnc*/
		0x14u,	/*DcmDsdServiceId*/
		FALSE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		3u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x14_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		0u,	/*DcmDsdSubService_Num*/
		NULL_PTR,	/*DcmDsdSubService*/
	},
	{ /*ReadDTCInformation*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x19,	/*DcmDsdSidTabFnc*/
		0x19u,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		3u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x19_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		4u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x19[0],	/*DcmDsdSubService*/
	},
	{ /*ReadDataByIdentifier*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x22,	/*DcmDsdSidTabFnc*/
		0x22u,	/*DcmDsdServiceId*/
		FALSE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		0u,	/*DcmDsdSessionLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSessionLevelRef*/
		0u,	/*DcmDsdSubService_Num*/
		NULL_PTR,	/*DcmDsdSubService*/
	},
	{ /*SecurityAccess*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x27,	/*DcmDsdSidTabFnc*/
		0x27u,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		2u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x27_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		6u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x27[0],	/*DcmDsdSubService*/
	},
	{ /*CommunicationControl*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x28,	/*DcmDsdSidTabFnc*/
		0x28u,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		1u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x28_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		2u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x28[0],	/*DcmDsdSubService*/
	},
	{ /*WriteDataByIdentifier*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x2E,	/*DcmDsdSidTabFnc*/
		0x2Eu,	/*DcmDsdServiceId*/
		FALSE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		3u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x2E_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		0u,	/*DcmDsdSubService_Num*/
		NULL_PTR,	/*DcmDsdSubService*/
	},
	{ /*InputOutputControlByIdentifier*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x2F,	/*DcmDsdSidTabFnc*/
		0x2Fu,	/*DcmDsdServiceId*/
		FALSE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		2u, /*DcmDsdSecurityLevel_Num*/	
		&Dcm_UDS0x2F_SecRef[0],	/*pDcmDsdSecurityLevelRef*/
		1u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x2F_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		0u,	/*DcmDsdSubService_Num*/
		NULL_PTR,	/*DcmDsdSubService*/
	},
	{ /*RoutineControl*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x31,	/*DcmDsdSidTabFnc*/
		0x31u,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		2u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x31_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		1u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x31[0],	/*DcmDsdSubService*/
	},
	{ /*TesterPresent*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x3E,	/*DcmDsdSidTabFnc*/
		0x3Eu,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		0u,	/*DcmDsdSessionLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSessionLevelRef*/
		1u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x3E[0],	/*DcmDsdSubService*/
	},
	{ /*ControlDTCSetting*/
		TRUE,	/*DcmDsdServiceUsed*/
		Dcm_UDS0x85,	/*DcmDsdSidTabFnc*/
		0x85u,	/*DcmDsdServiceId*/
		TRUE,	/*DcmDsdSubfuncAvial*/
		DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
		NULL_PTR,	/*DcmDsdModeRuleRef*/	
		0u, /*DcmDsdSecurityLevel_Num*/	
		NULL_PTR,	/*pDcmDsdSecurityLevelRef*/
		1u,	/*DcmDsdSessionLevel_Num*/	
		&Dcm_UDS0x85_SesRef[0],	/*pDcmDsdSessionLevelRef*/
		2u,	/*DcmDsdSubService_Num*/
		&DcmDsdSubService_UDS0x85[0],	/*DcmDsdSubService*/
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/**********************************************************************/
/*DCM Support Service Table(Multiplicity=1..256)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdServiceTableCfgType,DCM_CONST)Dcm_DsdServiceTable[DCM_SERVICE_TAB_NUM]=
{
    {
        0x0u,	/*DcmDsdSidTabId*/
        &DcmDsdServiceTable_Service[0],	/*pDcmDsdService*/
        12u	/*DcmDsdSidTab_ServiceNum*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/

/**********************************************************************/
/*Dsd container(Multiplicity=1)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DsdCfgType,DCM_CONST)Dcm_DsdCfg =
{
		/*DcmDsdServiceReqManufacturerNoti_PortNum*/
		/*DcmDsdServiceReqSupplierNoti_PortNum*/
    &Dcm_DsdServiceTable[0],	/*pDcmDsdServiceTable*/	
    DCM_SERVICE_TAB_NUM		/*DcmDsdServiceTable_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSL container configration*****************************
 *****************************************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
/*DcmDslBuffer container(Multiplicity=1..256)*/
static  CONST(Dcm_DslBufferType,DCM_CONST)Dcm_DslBufferCfg[DCM_CHANNEL_NUM] =
{	
    {/* DcmDslBuffer_Rx*/
    	0x0u,	/*Dcm_DslBufferId*/
		256u,	/*Dcm_DslBufferSize*/
		0u	/*offset*/
    },
    {/* DcmDslBuffer_Tx*/
    	0x1u,	/*Dcm_DslBufferId*/
		256u,	/*Dcm_DslBufferSize*/
		256u	/*offset*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************/
/*DcmDslDiagResp container(Multiplicity=1)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DslDiagRespType,DCM_CONST)Dcm_DslDiagRespCfg =
{	
    DCM_DSLDIAGRESP_FORCERESPENDEN,		/*DcmDslDiagRespOnSecondDeclinedRequest*/
    255u		/*DcmDslDiagRespMaxNumRespPend*/	
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslCallbackDCMRequestService port configuration(Multiplicity=1..*)
 *****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
static  CONST(Dcm_DslCallbackDCMRequestServiceType,DCM_CONST)Dcm_DslCallbackDCMRequestServiceCfg[1] =	
{	
	{
		NULL_PTR,	
		NULL_PTR
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/********************UDS protocol Connection configuration*******************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DslProtocolRxType,DCM_CONST)Dsl_Protocol_Connection_RxCfg[DCM_DSL_RX_ID_NUM]=
{
	{
    	0x0u,      		/*DcmDslParentConnectionCtrlId*/
        DCM_PHYSICAL,	/*DcmDslProtocolRxAddrType*/
        DCM_Dcm_RLM_RS_MasterReq,       /*DcmDslProtocolRxPduId*/	
		0x0u			/*DcmDslMetaDataLength*/	
    },
	{
    	0x0u,      		/*DcmDslParentConnectionCtrlId*/
        DCM_FUNCTIONAL,	/*DcmDslProtocolRxAddrType*/
        DCM_Dcm_RLM_RS_MasterReq_Fun,       /*DcmDslProtocolRxPduId*/	
		0x0u			/*DcmDslMetaDataLength*/	
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DslProtocolTxType,DCM_CONST)Dsl_Protocol_Connection_TxCfg[DCM_DSL_TX_ID_NUM]=
{
	{
    	0x0u,			/*parent connection id*/
        DCM_Dcm_RLM_RS_SlaveResp,       /*DcmDslProtocolTxPduId*/
		DCM_PDUR_Dcm_RLM_RS_SlaveResp,	/*DcmDslProtocolTx Pdu Id of PduR*/
    },
		
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


/*Connection1,Mainconnection,ProtocolTx configration(Multiplicity=1..*)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DslMainConnectionType,DCM_CONST) Dsl_Protocol_MainConnectionCfg[DCM_MAINCONNECTION_NUM] =
{
	{
		0x00000000u,							/*DcmDslProtocolRxTesterSourceAddr*/
		NULL_PTR,  /*pDcmDslPeriodicTranmissionConRef*/	
		0u, 									/*DcmDslProtocolComMChannelId*/	
		NULL_PTR,  /*pDcmDslROEConnectionRef*/	
		&Dsl_Protocol_Connection_RxCfg[0],	/*pDcmDslProtocolRx*/
		2u,                   				/*DcmDslProtocolRx_Num*/
		&Dsl_Protocol_Connection_TxCfg[0],  /*pDcmDslProtocolTx*/	
		1u									/*DcmDslProtocolTx_Num*/
	}
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Connection1 configration*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DslConnectionType,DCM_CONST)Dsl_Protocol_ConnectionCfg[DCM_CONNECTION_NUM]=
{
    {
    	0x0u,        						/*parent protocolRow id*/
        &Dsl_Protocol_MainConnectionCfg[0],	/*pDcmDslMainConnection*/
        NULL_PTR,         					/*pDcmDslPeriodicTransmission*/
        NULL_PTR          					/*pDcmDslResponseOnEvent*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****Dcm_DslProtocolRow container configration(Multiplicity=1..*)*******
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h" 
CONST(Dcm_DslProtocolRowType,DCM_CONST)Dsl_ProtocolRowCfg[DCM_DSLPROTOCOLROW_NUM_MAX] =
{	
    {
        DCM_UDS_ON_CAN,		/*DcmDslProtocolID*/
        0x0u,					/*This parameter is mandatory and defines the maximum length of the response message in case DcmPagedBufferEnabled == TRUE*/
        0u,					/*DcmDslProtocolPriority*/
		TRUE,				/*true-protocol is available*/
		DCM_PROTOCAL_TRAN_NOT_VALID,
		TRUE,				/*True-send 0x78 before transitioning to the bootloader */
		0u,	 				/*DcmTimStrP2ServerAdjust*/	
		0u,				/*DcmTimStrP2StarServerAdjust*/	
		&Dcm_DslBufferCfg[0],/*DcmDslProtocolRxBuffer*/
        &Dcm_DslBufferCfg[1],/*DcmDslProtocolTxBuffer*/
        0u, 				/*DcmDslServiceTableId*/
        &Dsl_Protocol_ConnectionCfg[0],/*DcmDslConnection*/
        1u,					/*Number of connection*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslProtocol container configration(Multiplicity=1)
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DslProtocolType,DCM_CONST)Dcm_DslProtocol =
{
    &Dsl_ProtocolRowCfg[0],	/*pDcmDslProtocolRow*/
    DCM_DSLPROTOCOLROW_NUM_MAX,	/*DcmDslProtocolRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****************DcmDsl container configration*****
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslCfgType,DCM_CONST)Dcm_DslCfg =
{
	DCM_CHANNEL_NUM,		/*Number of Channel configration*/					
    &Dcm_DslBufferCfg[0],	/*DcmDslBuffer*/									
	0u,						/*Number of DslCallbackDCMRequestService port*/
    &Dcm_DslCallbackDCMRequestServiceCfg[0],	/*pDcmDslCallback_DCMRequestService*/									
    &Dcm_DslDiagRespCfg,   	/*reference to DcmDslDiagResp configration*/		
    &Dcm_DslProtocol,		/*reference to DcmDslProtocol configration*/		
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_CfgType,DCM_CONST)Dcm_Cfg =
{
	&Dcm_DslCfg,	/*pDcmDslCfg*/
	&Dcm_DsdCfg,	/*pDcmDsdCfg*/
	&Dcm_DspCfg,	/*pDcmDspCfg*/
	NULL_PTR,	    /*pDcmPageBufferCfg*/
	NULL_PTR,	    /*pDcmProcessingConditionsCfg*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

