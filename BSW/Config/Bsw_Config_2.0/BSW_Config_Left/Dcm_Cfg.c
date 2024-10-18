/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-09-25 15:11:22>
 */
/*============================================================================*/

/******************************* references ************************************/
#include "Dcm_Types.h"
#include "Rte_Dcm.h"
#include "Dcm_Cfg.h"
#if (STD_ON == DCM_UDS_FUNC_ENABLED)
#include "UDS.h"
#endif
#if (STD_ON == DCM_OBD_FUNC_ENABLED)
#include "OBD.h"
#endif

/**********************Clear DTC**************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspClearDTCType, DCM_CONST) Dcm_DspClearDTCCfg =
{
    Rte_ClearDTCCheck, /*DcmDsp_ClearDTCCheckFnc*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Control DTC Setting********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspControlDTCSettingType, DCM_CONST) Dcm_DspControlDTCSettingCfg =
{
    FALSE, /*DcmSupportDTCSettingControlOptionRecord*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Com Control********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannelCfg[1] =
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
static CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControlCfg =
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
/* PRQA S 0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_0103_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3,Rule 5.2 */
/* PRQA S 0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_03_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3,Rule 5.2 */

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspCommonAuthorizationType, DCM_CONST) Dcm_DspCommonAuthorizationCfg[2] =
{
    {
        0u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
        2u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_0103_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        0u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_03_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/* PRQA S 0674++ */ /* MISRA Rule 1.1 */
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspDataCfg[64] =
{
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4351_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4357_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        24u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x4368_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x437C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        192u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A8_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A8_WriteData, /*DcmDspDataWriteFnc*/
        800u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        24u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CA_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        24u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CE_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CF_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D0_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D1_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D2_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D3_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D4_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D5_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D7_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D8_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D9_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43DA_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x43E0_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        48u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        672u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xD03A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        256u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xD134_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xD214_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        400u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD00_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD01_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        24u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD02_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xE103_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        248u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF120_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        56u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF126_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        280u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        56u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        56u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12E_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        120u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF13F_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        104u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF186_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1A0_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AA_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AB_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AE_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        136u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1F0_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        360u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1F1_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        432u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xED20_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        440u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xEDA0_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        400u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD07_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        48u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0674-- */ /* MISRA Rule 1.1 */

/********************Dsp Did******************************/
/******************************************
 *DcmDspDidRead container configration
 *****************************************/                                                                        
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_0_ReadCfg =
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
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_3_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u, /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidWrite container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/                                                                
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_2_WriteCfg=
{
    0u,/*DcmDspDidWriteSecurityLevelRefNum*/
    NULL_PTR,    /*pDcmDspDidWriteSecurityLevelRow*/
    1u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_2_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidControl container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(uint8,DCM_CONST)Dcm_DidInfo_0_Control_SesRefCfg[1]={3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidControlType,DCM_CONST) Dcm_DidInfo_0_ControlCfg =
{
    DCM_CONTROLMASK_EXTERNAL, /*DcmDspDidControlMask*/
    1u, /*DcmDspDidControlMaskSize*/
    0u, /*DcmDspDidControlSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidControlSecurityLevelRow*/
    1u, /*DcmDspDidControlSessionRefNum*/
    &Dcm_DidInfo_0_Control_SesRefCfg[0], /*pDcmDspDidControlSessionRow*/
    TRUE, /*DcmDspDidFreezeCurrentState*/
    TRUE, /*DcmDspDidResetToDefault*/
    TRUE, /*DcmDspDidShortTermAdjustement*/
    NULL_PTR, /*DcmDspDidControlEnableMask*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(uint8,DCM_CONST)Dcm_DidInfo_3_Control_SesRefCfg[1]={3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidControlType,DCM_CONST) Dcm_DidInfo_3_ControlCfg =
{
    DCM_CONTROLMASK_NO, /*DcmDspDidControlMask*/
    0u, /*DcmDspDidControlMaskSize*/
    0u, /*DcmDspDidControlSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidControlSecurityLevelRow*/
    1u, /*DcmDspDidControlSessionRefNum*/
    &Dcm_DidInfo_3_Control_SesRefCfg[0], /*pDcmDspDidControlSessionRow*/
    TRUE, /*DcmDspDidFreezeCurrentState*/
    TRUE, /*DcmDspDidResetToDefault*/
    TRUE, /*DcmDspDidShortTermAdjustement*/
    NULL_PTR, /*DcmDspDidControlEnableMask*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/******************************************
 *DcmDspDidInfo container Configuration ***
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidInfoType,DCM_CONST)Dcm_DspDidInfoCfg[4] =
{
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        &Dcm_DidInfo_0_ControlCfg, /*pDcmDspDidControl*/
        &Dcm_DidInfo_0_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
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
        &Dcm_DidInfo_3_ControlCfg, /*pDcmDspDidControl*/
        &Dcm_DidInfo_3_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_434B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[0],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4351_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[1],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4357_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[2],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4358_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[3],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4359_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[4],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_435B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[5],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_435C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[6],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_435D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[7],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_435E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[8],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_435F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[9],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4360_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[10],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4361_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[11],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4362_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[12],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4363_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[13],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4364_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[14],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4365_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[15],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4366_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[16],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4367_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[17],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_4368_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[18],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_437C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[19],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43A8_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[20],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43A9_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[21],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43CA_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[22],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43CE_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[23],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43CF_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[24],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D0_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[25],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D1_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[26],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D2_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[27],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D3_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[28],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D4_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[29],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D5_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[30],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D7_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[31],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D8_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[32],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43D9_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[33],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43DA_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[34],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_43E0_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[35],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_7022_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[36],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_D03A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[37],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_D134_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[38],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_D214_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[39],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_DD00_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[40],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_DD01_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[41],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_DD02_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[42],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_DD0A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[43],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_DD0B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[44],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_DD0C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[45],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_E103_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[46],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F120_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[47],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F126_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[48],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F12A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[49],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F12B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[50],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F12E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[51],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F13F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[52],     /*pDcmDspDidData*/
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
        &Dcm_DspDataCfg[53],     /*pDcmDspDidData*/
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
        &Dcm_DspDataCfg[54],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1A0_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[55],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AA_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[56],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AB_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[57],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AE_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[58],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1F0_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[59],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1F1_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[60],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_ED20_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[61],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_EDA0_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[62],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_DD07_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[63],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************
 *DcmDspDid container configration*************
 **********************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidType,DCM_CONST)Dcm_DspDidCfg[64] =
{
    { /* Did_0x434B */
        0x434Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_434B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4351 */
        0x4351u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4351_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4357 */
        0x4357u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4357_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4358 */
        0x4358u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4358_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4359 */
        0x4359u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4359_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x435B */
        0x435Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_435B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x435C */
        0x435Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_435C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x435D */
        0x435Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_435D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x435E */
        0x435Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_435E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x435F */
        0x435Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_435F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4360 */
        0x4360u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4360_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4361 */
        0x4361u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4361_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4362 */
        0x4362u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4362_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4363 */
        0x4363u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4363_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4364 */
        0x4364u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4364_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4365 */
        0x4365u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4365_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4366 */
        0x4366u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4366_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4367 */
        0x4367u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4367_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x4368 */
        0x4368u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_4368_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x437C */
        0x437Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_437C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43A8 */
        0x43A8u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43A8_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43A9 */
        0x43A9u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43A9_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43CA */
        0x43CAu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43CA_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43CE */
        0x43CEu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43CE_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43CF */
        0x43CFu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43CF_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D0 */
        0x43D0u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D0_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D1 */
        0x43D1u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D1_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D2 */
        0x43D2u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D2_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D3 */
        0x43D3u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D3_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D4 */
        0x43D4u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D4_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D5 */
        0x43D5u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D5_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D7 */
        0x43D7u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D7_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D8 */
        0x43D8u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D8_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43D9 */
        0x43D9u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43D9_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43DA */
        0x43DAu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43DA_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x43E0 */
        0x43E0u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_43E0_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x7022 */
        0x7022u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_7022_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xD03A */
        0xD03Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_D03A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xD134 */
        0xD134u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_D134_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xD214 */
        0xD214u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_D214_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xDD00 */
        0xDD00u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_DD00_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xDD01 */
        0xDD01u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_DD01_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xDD02 */
        0xDD02u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_DD02_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xDD0A */
        0xDD0Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_DD0A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xDD0B */
        0xDD0Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_DD0B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xDD0C */
        0xDD0Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_DD0C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xE103 */
        0xE103u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_E103_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF120 */
        0xF120u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F120_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF126 */
        0xF126u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F126_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF12A */
        0xF12Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F12A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF12B */
        0xF12Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F12B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF12E */
        0xF12Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F12E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF13F */
        0xF13Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F13F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF186 */
        0xF186u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F186_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF18C */
        0xF18Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F18C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1A0 */
        0xF1A0u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1A0_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AA */
        0xF1AAu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AA_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AB */
        0xF1ABu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AB_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AE */
        0xF1AEu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AE_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1F0 */
        0xF1F0u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1F0_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1F1 */
        0xF1F1u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1F1_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xED20 */
        0xED20u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_ED20_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xEDA0 */
        0xEDA0u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_EDA0_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xDD07 */
        0xDD07u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_DD07_SignalCfg[0],     /*pDcmDspDidSignal*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Routine**************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x206_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF100_SignalCfg[3] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF101_SignalCfg[3] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF102_SignalCfg[4] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF103_SignalCfg[4] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF104_SignalCfg[3] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        56u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF106_SignalCfg[3] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF100_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF100_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF100_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_RequestResults, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF100_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF101_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF101_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF101_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_RequestResults, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF101_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF102_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF102_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF102_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_RequestResults, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF102_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF103_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF103_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF103_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_RequestResults, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF103_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF104_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF104_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF104_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_RequestResults, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF104_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF106_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF106_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF106_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_RequestResults, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF106_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRoutineStart container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x206_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x206_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x206_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x0206_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x206_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF100_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF100_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF100_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF100_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF101_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF101_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF101_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF101_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF102_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF102_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF102_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF102_SignalCfg[2],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF102_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xF102_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF102_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF103_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF103_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF103_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF103_SignalCfg[2],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF103_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xF103_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF103_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF104_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF104_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF104_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF104_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF106_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF106_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF106_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF106_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************
 *DcmDspRoutineStop container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0xF100_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0xF100_SignalCfg[2],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF100_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_Stop, /*DcmDspRoutineStopFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0xF100_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0xF101_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0xF101_SignalCfg[2],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF101_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_Stop, /*DcmDspRoutineStopFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0xF101_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0xF102_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0xF102_SignalCfg[3],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF102_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_Stop, /*DcmDspRoutineStopFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0xF102_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0xF103_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0xF103_SignalCfg[3],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF103_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_Stop, /*DcmDspRoutineStopFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0xF103_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0xF104_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0xF104_SignalCfg[2],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF104_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_Stop, /*DcmDspRoutineStopFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0xF104_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0xF106_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0xF106_SignalCfg[2],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF106_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_Stop, /*DcmDspRoutineStopFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0xF106_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRoutine container configration
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineType,DCM_CONST)Dcm_DspRoutineCfg[7] =
{
    { /* DcmDspRoutine_0x0206 */
        0x206u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x206_StartCfg, /*DcmDspStartRoutine*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF100 */
        0xF100u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF100_ResultsCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0xF100_StartCfg, /*DcmDspStartRoutine*/
        &Dcm_RoutineInfo_0xF100_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF101 */
        0xF101u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF101_ResultsCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0xF101_StartCfg, /*DcmDspStartRoutine*/
        &Dcm_RoutineInfo_0xF101_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF102 */
        0xF102u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF102_ResultsCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0xF102_StartCfg, /*DcmDspStartRoutine*/
        &Dcm_RoutineInfo_0xF102_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF103 */
        0xF103u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF103_ResultsCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0xF103_StartCfg, /*DcmDspStartRoutine*/
        &Dcm_RoutineInfo_0xF103_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF104 */
        0xF104u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF104_ResultsCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0xF104_StartCfg, /*DcmDspStartRoutine*/
        &Dcm_RoutineInfo_0xF104_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF106 */
        0xF106u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF106_ResultsCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0xF106_StartCfg, /*DcmDspStartRoutine*/
        &Dcm_RoutineInfo_0xF106_StopCfg, /*DcmDspStopRoutine*/
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
static CONST(Dcm_DspSecurityRowType,DCM_CONST)Dcm_DspSecurityRow[1] =
{
    { /* DcmDspSecurityRow_0 */
        1u,          /*DcmDspSecurityLevel*/
        3u,          /*DcmDspSecuritySeedSize*/
        3u,          /*DcmDspSecurityKeySize*/
        0u,          /*DcmDspSecurityADRSize*/
        TRUE,        /*DcmDspSecurityAttemptCounterEnabled*/
        2u,    /*DcmDspSecurityNumAttDelay*/
        10000u,  /*DcmDspSecurityDelayTime,10s */
        5000u,/*DcmDspSecurityDelayTimeOnBoot*/
        /* PRQA S 0674++ */ /* MISRA Rule 1.1 */                
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_GetSeed,    /*Dcm_GetSeedFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_CompareKey,    /*Dcm_CompareKeyFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_GetSecurityAttemptCounter,    /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_SetSecurityAttemptCounter,    /*DcmDspSecurityUsePort*/
        /* PRQA S 0674-- */ /* MISRA Rule 1.1 */
        USE_ASYNCH_CLIENT_SERVER,    /*DcmDspSecurityUsePort*/
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
    &Dcm_DspSecurityRow[0],    /*pDcm_DspSecurityRow*/
    1u,    /*DcmDspSecurityRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Session Row**************/
/************************************************
 ****DcmDspSessionRow container(Multiplicity=0..31)
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSessionRowType,DCM_CONST)Dcm_DspSessionRow[3] =
{
    { /* DcmDspSessionRow_1001 */
        DCM_NO_BOOT,    /*DcmDspSessionForBoot*/
        1u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    },
    { /* DcmDspSessionRow_1002 */
        DCM_SYS_BOOT_RESPAPP,    /*DcmDspSessionForBoot*/
        2u,    /*DcmDspSessionLevel*/
        25u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    },
    { /* DcmDspSessionRow_1003 */
        DCM_NO_BOOT,    /*DcmDspSessionForBoot*/
        3u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
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
    &Dcm_DspSessionRow[0],    /*pDcmDspSessionRow*/
    3u,        /*DcmDspSessionRow_Num*/
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
    NULL_PTR,    /*DcmDspDDDIDcheckPerSourceDID*/
    DCM_BIG_ENDIAN,    /*DcmDspDataDefaultEndianness*/
    FALSE,/*DcmDspEnableObdMirror*/
    0,/*DcmDspMaxDidToRead*/
    DCM_DSP_MAX_PERIODIC_DID_TO_READ,/*DcmDspMaxPeriodicDidToRead*/
    0u,/*DcmDspPowerDownTime*/
    AFTER_RESET,    /*DcmResponseToEcuReset*/
    &Dcm_DspClearDTCCfg,        /*pDcmDspClearDTC*/
    &Dcm_DspComControlCfg,        /*pDcmDspComControl*/
    &Dcm_DspCommonAuthorizationCfg[0],        /*pDcmDspCommonAuthorization*/
    &Dcm_DspControlDTCSettingCfg,    /*pDcmDspControlDTCSetting*/
    &Dcm_DspDataCfg[0],    /*pDcmDspData*/    NULL_PTR,    /*pDcmDspDataInfo*/
    64u,    /*DcmDspDidNum*/
    &Dcm_DspDidCfg[0],        /*pDcmDspDid*/
    4u,    /*DcmDspDidInfoNum*/
    &Dcm_DspDidInfoCfg[0],        /*pDcmDspDidInfo*/
    0u,    /*DcmDspDidRangeNum*/
    NULL_PTR,        /*pDcmDspDidRange*/
    NULL_PTR, /*pDcmDspMemory*/

    NULL_PTR,    /*DcmDspRequestFileTransfer*/

    7u,        /*DcmDspRoutineNum*/
    &Dcm_DspRoutineCfg[0],    /*pDcmDspRoutine*/

    &Dcm_DspSecurity,  /* pDcm_DspSecurity */
    &Dcm_DspSession,  /* pDcm_DspSession */

    DCM_DSP_MAX_PERIODIC_DID_SCHEDULER,
    NULL_PTR,

};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSD container configration*****************************
 *****************************************************************************************/

/*DcmDsdService_0x10 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x10[3] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x11 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x11[1] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x19 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x19[6] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x4u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x6u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0xAu,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x15u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x31 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x31[1] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x0u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x3E SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x3E[1] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x0u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*UDS Service session and security configuration*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2F_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/*DcmDsdService DcmDsdServiceTable*/    
static  CONST(Dcm_DsdServiceCfgType,DCM_CONST)DcmDsdServiceTable_Service[9] =
{
    { /*DiagnosticSessionControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x10,    /*DcmDsdSidTabFnc*/
        0x10u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        3u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x10[0],    /*DcmDsdSubService*/
    },
    { /*ECUReset*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x11,    /*DcmDsdSidTabFnc*/
        0x11u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        1u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x11[0],    /*DcmDsdSubService*/
    },
    { /*ClearDiagnosticInformation*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x14,    /*DcmDsdSidTabFnc*/
        0x14u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*ReadDTCInformation*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x19,    /*DcmDsdSidTabFnc*/
        0x19u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        6u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x19[0],    /*DcmDsdSubService*/
    },
    { /*ReadDataByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x22,    /*DcmDsdSidTabFnc*/
        0x22u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*WriteDataByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2E,    /*DcmDsdSidTabFnc*/
        0x2Eu,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*RoutineControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x31,    /*DcmDsdSidTabFnc*/
        0x31u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        1u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x31[0],    /*DcmDsdSubService*/
    },
    { /*TesterPresent*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x3E,    /*DcmDsdSidTabFnc*/
        0x3Eu,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        1u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x3E[0],    /*DcmDsdSubService*/
    },
    { /*InputOutputControlByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2F,    /*DcmDsdSidTabFnc*/
        0x2Fu,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2F_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/
/*DCM Support Service Table(Multiplicity=1..256)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdServiceTableCfgType,DCM_CONST)Dcm_DsdServiceTable[DCM_SERVICE_TAB_NUM]=
{
    {
        0x0u,    /*DcmDsdSidTabId*/
        &DcmDsdServiceTable_Service[0],    /*pDcmDsdService*/
        9u    /*DcmDsdSidTab_ServiceNum*/
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

    &Dcm_DsdServiceTable[0],    /*pDcmDsdServiceTable*/
    DCM_SERVICE_TAB_NUM        /*DcmDsdServiceTable_Num*/
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
        0x0u,    /*Dcm_DslBufferId*/
        1024u,    /*Dcm_DslBufferSize*/
        0u    /*offset*/
    },
    {/* DcmDslBuffer_Tx*/
        0x1u,    /*Dcm_DslBufferId*/
        1024u,    /*Dcm_DslBufferSize*/
        1024u    /*offset*/
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
    FALSE,        /*DcmDslDiagRespOnSecondDeclinedRequest*/
    0u        /*DcmDslDiagRespMaxNumRespPend*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslCallbackDCMRequestService port configuration(Multiplicity=1..*)
 *****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static  CONST(Dcm_DslCallbackDCMRequestServiceType,DCM_CONST)Dcm_DslCallbackDCMRequestServiceCfg[1] =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
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
        0x0u,              /*DcmDslParentMainConnectionCtrlId*/
        DCM_PHYSICAL,    /*DcmDslProtocolRxAddrType*/
        DCM_VgmToHcmlDiagDcmIpdu,       /*DcmDslProtocolRxPduId*/

    },
    {
        0x0u,              /*DcmDslParentMainConnectionCtrlId*/
        DCM_FUNCTIONAL,    /*DcmDslProtocolRxAddrType*/
        DCM_VgmToAllFuncDiagDcmIpdu,       /*DcmDslProtocolRxPduId*/

    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolTxType,DCM_CONST)Dsl_Protocol_Connection_TxCfg[DCM_DSL_TX_ID_NUM]=
{
    {
        0x0u,            /*DcmDslParentMainConnectionCtrlId*/
        DCM_HcmlToVgmDiagDcmIpdu,       /*DcmDslProtocolTxPduId*/
        DCM_PDUR_HcmlToVgmDiagDcmIpdu,  /*DcmDslProtocolTx Pdu Id of PduR*/
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
        0x00000000u,                            /*DcmDslProtocolRxTesterSourceAddr*/
        NULL_PTR,  /*pDcmDslPeriodicTranmissionConRef*/
        0u,                                     /*DcmDslProtocolComMChannelId*/
        NULL_PTR,  /*pDcmDslROEConnectionRef*/
        &Dsl_Protocol_Connection_RxCfg[0],    /*pDcmDslProtocolRx*/
        2u,                                   /*DcmDslProtocolRx_Num*/
        &Dsl_Protocol_Connection_TxCfg[0],  /*pDcmDslProtocolTx*/
        1u                                    /*DcmDslProtocolTx_Num*/
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
        0x0u,                                /*parent protocolRow id*/
        &Dsl_Protocol_MainConnectionCfg[0],    /*pDcmDslMainConnection*/
        NULL_PTR,                             /*pDcmDslPeriodicTransmission*/
        NULL_PTR                              /*pDcmDslResponseOnEvent*/
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
        DCM_UDS_ON_CAN,        /*DcmDslProtocolID*/
        0u,                    /*DcmDslProtocolPreemptTimes*/
        0u,                    /*DcmDslProtocolPriority*/
        TRUE,                /*true-protocol is available*/
        DCM_PROTOCAL_TRAN_NOT_VALID,
        FALSE,                /*True-send 0x78 before transitioning to the bootloader */
        0u,                     /*DcmTimStrP2ServerAdjust*/
        0u,                /*DcmTimStrP2StarServerAdjust*/
        &Dcm_DslBufferCfg[0],/*DcmDslProtocolRxBuffer*/
        &Dcm_DslBufferCfg[1],/*DcmDslProtocolTxBuffer*/
        0u,                 /*DcmDslServiceTableId*/
        &Dsl_Protocol_ConnectionCfg[0], /*DcmDslConnection*/
        FALSE,              /*DcmDslProtocolRequestQueued*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslProtocol container configration(Multiplicity=1)
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DslProtocolType,DCM_CONST)Dcm_DslProtocol =
{
    &Dsl_ProtocolRowCfg[0],    /*pDcmDslProtocolRow*/
    DCM_DSLPROTOCOLROW_NUM_MAX,    /*DcmDslProtocolRow_Num*/
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
    DCM_CHANNEL_NUM,        /*Number of Channel configration*/
    &Dcm_DslBufferCfg[0],    /*DcmDslBuffer*/
    0u,                        /*Number of DslCallbackDCMRequestService port*/
    &Dcm_DslCallbackDCMRequestServiceCfg[0],    /*pDcmDslCallback_DCMRequestService*/
    &Dcm_DslDiagRespCfg,       /*reference to DcmDslDiagResp configration*/
    &Dcm_DslProtocol,        /*reference to DcmDslProtocol configration*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_CfgType,DCM_CONST)Dcm_Cfg =
{
    &Dcm_DslCfg,    /*pDcmDslCfg*/
    &Dcm_DsdCfg,    /*pDcmDsdCfg*/
    &Dcm_DspCfg,    /*pDcmDspCfg*/
    NULL_PTR,        /*pDcmPageBufferCfg*/
    NULL_PTR,        /*pDcmProcessingConditionsCfg*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************
 ***********************DcmGeneral Container***************************
 **********************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_GeneralCfgType,DCM_CONST)Dcm_GeneralCfg =
{
    TRUE, /*DcmDDDIDStorage*/
    DCM_DEV_ERROR_DETECT, /*DcmDevErrorDetect*//* PRQA S 1295 */ /* MISRA Rule 10.3 */
    NULL_PTR, /*DcmHeaderFileInclusion*/
    DCM_RESPOND_ALL_REQUEST, /*DcmRespondAllRequest*//* PRQA S 1295 */ /* MISRA Rule 10.3 */
    DCM_VERSION_INFO_API, /*DcmVersionInfoApi*//* PRQA S 1295 */ /* MISRA Rule 10.3 */
    10, /*DcmTaskTime*/
    NULL_PTR, /*DcmVinRef*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

