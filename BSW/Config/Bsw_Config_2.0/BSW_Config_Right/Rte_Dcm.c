/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-03-21 10:57:33>
 */
/*============================================================================*/

#include "Rte_Dcm.h"
#include "Mcu.h"
#include "NvM.h"
#include "NmHistoryState.h"
#include "Fls.h"
#include "Fee.h"
#include <String.h>

#include "AswInterfaceManager.h"
#include "ParaMgr.h"
#include "Com_Cfg.h"
#include "Com.h"

#define DCM_UNUSED(a) (void)(a)

#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8  Buffer_FalseAcessCount_DcmDspSecurityRow_0  =  0x0;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"

#include "Dcm_Internal.h"
/***************************Security Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    DCM_UNUSED(Key);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,uint8*  AttemptCounter )
{
    (*AttemptCounter) = Buffer_FalseAcessCount_DcmDspSecurityRow_0;
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode)
{
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Seed);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter )
{
    DCM_UNUSED(OpStatus);
    Buffer_FalseAcessCount_DcmDspSecurityRow_0 = AttemptCounter;
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/***************************Did Part****************************************/
#define IO_MASK_CNT     1

#define  DataLength_DcmDspData_0x434B 4u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x434B[ DataLength_DcmDspData_0x434B ] = {0x0} ;
uint8 Buffer_DcmDspData_0x434B_Default[ DataLength_DcmDspData_0x434B ] = {0x0} ;
uint8 Buffer_DcmDspData_0x434B_OptionRecord[DataLength_DcmDspData_0x434B+IO_MASK_CNT] ={0x0};
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4351 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4351[ DataLength_DcmDspData_0x4351 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4351_Default[ DataLength_DcmDspData_0x4351 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4357 2u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4357[ DataLength_DcmDspData_0x4357 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4357_Default[ DataLength_DcmDspData_0x4357 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4358 3u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4358[ DataLength_DcmDspData_0x4358 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4358_Default[ DataLength_DcmDspData_0x4358 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4358_OptionRecord[ DataLength_DcmDspData_0x4358 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4359 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4359[ DataLength_DcmDspData_0x4359 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4359_Default[ DataLength_DcmDspData_0x4359 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4359_OptionRecord[ DataLength_DcmDspData_0x4359 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x435B 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x435B[ DataLength_DcmDspData_0x435B ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435B_Default[ DataLength_DcmDspData_0x435B ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435B_OptionRecord[ DataLength_DcmDspData_0x435B +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x435C 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x435C[ DataLength_DcmDspData_0x435C ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435C_Default[ DataLength_DcmDspData_0x435C ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435C_OptionRecord[ DataLength_DcmDspData_0x435C +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x435D 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x435D[ DataLength_DcmDspData_0x435D ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435D_Default[ DataLength_DcmDspData_0x435D ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435D_OptionRecord[ DataLength_DcmDspData_0x435D +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x435E 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x435E[ DataLength_DcmDspData_0x435E ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435E_Default[ DataLength_DcmDspData_0x435E ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435E_OptionRecord[ DataLength_DcmDspData_0x435E +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x435F 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x435F[ DataLength_DcmDspData_0x435F ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435F_Default[ DataLength_DcmDspData_0x435F ] = {0x0} ;
uint8 Buffer_DcmDspData_0x435F_OptionRecord[ DataLength_DcmDspData_0x435F +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4360 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4360[ DataLength_DcmDspData_0x4360 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4360_Default[ DataLength_DcmDspData_0x4360 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4360_OptionRecord[ DataLength_DcmDspData_0x4360 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4361 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4361[ DataLength_DcmDspData_0x4361 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4361_Default[ DataLength_DcmDspData_0x4361 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4361_OptionRecord[ DataLength_DcmDspData_0x4361 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4362 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4362[ DataLength_DcmDspData_0x4362 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4362_Default[ DataLength_DcmDspData_0x4362 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4362_OptionRecord[ DataLength_DcmDspData_0x4362 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4363 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4363[ DataLength_DcmDspData_0x4363 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4363_Default[ DataLength_DcmDspData_0x4363 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4363_OptionRecord[ DataLength_DcmDspData_0x4363 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4364 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4364[ DataLength_DcmDspData_0x4364 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4364_Default[ DataLength_DcmDspData_0x4364 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4364_OptionRecord[ DataLength_DcmDspData_0x4364 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4365 2u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4365[ DataLength_DcmDspData_0x4365 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4365_Default[ DataLength_DcmDspData_0x4365 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4365_OptionRecord[ DataLength_DcmDspData_0x4365 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4366 2u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4366[ DataLength_DcmDspData_0x4366 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4366_Default[ DataLength_DcmDspData_0x4366 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4366_OptionRecord[ DataLength_DcmDspData_0x4366 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4367 11u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4367[ DataLength_DcmDspData_0x4367 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4367_Default[ DataLength_DcmDspData_0x4367 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4367_OptionRecord[ DataLength_DcmDspData_0x4367 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x4368 4u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x4368[ DataLength_DcmDspData_0x4368 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x4368_Default[ DataLength_DcmDspData_0x4368 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x437C 24u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x437C[ DataLength_DcmDspData_0x437C ] = {0x0} ;
uint8 Buffer_DcmDspData_0x437C_Default[ DataLength_DcmDspData_0x437C ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43A8 100u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43A8[ DataLength_DcmDspData_0x43A8 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43A8_Default[ DataLength_DcmDspData_0x43A8 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43A9 3u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43A9[ DataLength_DcmDspData_0x43A9 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43A9_Default[ DataLength_DcmDspData_0x43A9 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43A9_OptionRecord[ DataLength_DcmDspData_0x43A9 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43CA 3u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43CA[ DataLength_DcmDspData_0x43CA ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43CA_Default[ DataLength_DcmDspData_0x43CA ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43CE 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43CE[ DataLength_DcmDspData_0x43CE ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43CE_Default[ DataLength_DcmDspData_0x43CE ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43CF 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43CF[ DataLength_DcmDspData_0x43CF ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43CF_Default[ DataLength_DcmDspData_0x43CF ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D0 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D0[ DataLength_DcmDspData_0x43D0 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D0_Default[ DataLength_DcmDspData_0x43D0 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D1 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D1[ DataLength_DcmDspData_0x43D1 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D1_Default[ DataLength_DcmDspData_0x43D1 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D2 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D2[ DataLength_DcmDspData_0x43D2 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D2_Default[ DataLength_DcmDspData_0x43D2 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D3 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D3[ DataLength_DcmDspData_0x43D3 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D3_Default[ DataLength_DcmDspData_0x43D3 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D4 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D4[ DataLength_DcmDspData_0x43D4 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D4_Default[ DataLength_DcmDspData_0x43D4 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D5 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D5[ DataLength_DcmDspData_0x43D5 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D5_Default[ DataLength_DcmDspData_0x43D5 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D7 2u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D7[ DataLength_DcmDspData_0x43D7 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D7_Default[ DataLength_DcmDspData_0x43D7 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D8 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D8[ DataLength_DcmDspData_0x43D8 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D8_Default[ DataLength_DcmDspData_0x43D8 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43D9 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43D9[ DataLength_DcmDspData_0x43D9 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43D9_Default[ DataLength_DcmDspData_0x43D9 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43DA 2u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43DA[ DataLength_DcmDspData_0x43DA ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43DA_Default[ DataLength_DcmDspData_0x43DA ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x43E0 6u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x43E0[ DataLength_DcmDspData_0x43E0 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x43E0_Default[ DataLength_DcmDspData_0x43E0 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x7022 84u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x7022[ DataLength_DcmDspData_0x7022 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x7022_Default[ DataLength_DcmDspData_0x7022 ] = {0x0} ;
uint8 Buffer_DcmDspData_0x7022_OptionRecord[ DataLength_DcmDspData_0x7022 +IO_MASK_CNT]={0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xD03A 32u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xD03A[ DataLength_DcmDspData_0xD03A ] = {0x0} ;
uint8 Buffer_DcmDspData_0xD03A_Default[ DataLength_DcmDspData_0xD03A ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xD134 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xD134[ DataLength_DcmDspData_0xD134 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xD134_Default[ DataLength_DcmDspData_0xD134 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xD214 50u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xD214[ DataLength_DcmDspData_0xD214 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xD214_Default[ DataLength_DcmDspData_0xD214 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xDD00 4u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xDD00[ DataLength_DcmDspData_0xDD00 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xDD00_Default[ DataLength_DcmDspData_0xDD00 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xDD01 3u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xDD01[ DataLength_DcmDspData_0xDD01 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xDD01_Default[ DataLength_DcmDspData_0xDD01 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xDD02 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xDD02[ DataLength_DcmDspData_0xDD02 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xDD02_Default[ DataLength_DcmDspData_0xDD02 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xDD0A 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xDD0A[ DataLength_DcmDspData_0xDD0A ] = {0x0} ;
uint8 Buffer_DcmDspData_0xDD0A_Default[ DataLength_DcmDspData_0xDD0A ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xDD0B 2u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xDD0B[ DataLength_DcmDspData_0xDD0B ] = {0x0} ;
uint8 Buffer_DcmDspData_0xDD0B_Default[ DataLength_DcmDspData_0xDD0B ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xDD0C 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xDD0C[ DataLength_DcmDspData_0xDD0C ] = {0x0} ;
uint8 Buffer_DcmDspData_0xDD0C_Default[ DataLength_DcmDspData_0xDD0C ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xE103 31u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xE103[ DataLength_DcmDspData_0xE103 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xE103_Default[ DataLength_DcmDspData_0xE103 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF120 7u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF120[ DataLength_DcmDspData_0xF120 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF120_Default[ DataLength_DcmDspData_0xF120 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF126 35u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF126[ DataLength_DcmDspData_0xF126 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF126_Default[ DataLength_DcmDspData_0xF126 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF12A 7u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF12A[ DataLength_DcmDspData_0xF12A ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF12A_Default[ DataLength_DcmDspData_0xF12A ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF12B 7u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF12B[ DataLength_DcmDspData_0xF12B ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF12B_Default[ DataLength_DcmDspData_0xF12B ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF12E 15u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF12E[ DataLength_DcmDspData_0xF12E ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF12E_Default[ DataLength_DcmDspData_0xF12E ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF13F 13u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF13F[ DataLength_DcmDspData_0xF13F ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF13F_Default[ DataLength_DcmDspData_0xF13F ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF186 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF186[ DataLength_DcmDspData_0xF186 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF186_Default[ DataLength_DcmDspData_0xF186 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF18C 4u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF18C[ DataLength_DcmDspData_0xF18C ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF18C_Default[ DataLength_DcmDspData_0xF18C ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF1A0 8u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#if (VEHICLE_PLATFORM == VEHICLE_SMART_HS11)
#if HCM_LEFT_SIDE
uint8 Buffer_DcmDspData_0xF1A0[ DataLength_DcmDspData_0xF1A0 ] = {0x66, 0x08, 0x27, 0x61, 0x20, 0x20, 0x20, 0x41} ;
#else
uint8 Buffer_DcmDspData_0xF1A0[ DataLength_DcmDspData_0xF1A0 ] = {0x66, 0x08, 0x27, 0x61, 0x29, 0x20, 0x20, 0x41} ;
#endif
#elif (VEHICLE_PLATFORM == VEHICLE_GEELY_G636)
#if HCM_LEFT_SIDE
uint8 Buffer_DcmDspData_0xF1A0[ DataLength_DcmDspData_0xF1A0 ] = {0x66, 0x08, 0x27, 0x61, 0x20, 0x20, 0x20, 0x41} ;
#else
uint8 Buffer_DcmDspData_0xF1A0[ DataLength_DcmDspData_0xF1A0 ] = {0x66, 0x08, 0x27, 0x61, 0x29, 0x20, 0x20, 0x41} ;
#endif
#endif
uint8 Buffer_DcmDspData_0xF1A0_Default[ DataLength_DcmDspData_0xF1A0 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF1AA 8u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF1AA[ DataLength_DcmDspData_0xF1AA ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF1AA_Default[ DataLength_DcmDspData_0xF1AA ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF1AB 8u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF1AB[ DataLength_DcmDspData_0xF1AB ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF1AB_Default[ DataLength_DcmDspData_0xF1AB ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF1AE 17u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#if (VEHICLE_PLATFORM == VEHICLE_SMART_HS11)
#if HCM_LEFT_SIDE
uint8 Buffer_DcmDspData_0xF1AE[ DataLength_DcmDspData_0xF1AE ] = {0x02, 0x66, 0x08, 0x34, 0x23, 0x01, 0x20, 0x20, 0x41} ;
#else
uint8 Buffer_DcmDspData_0xF1AE[ DataLength_DcmDspData_0xF1AE ] = {0x02, 0x66, 0x08, 0x34, 0x23, 0x00, 0x20, 0x20, 0x41} ;
#endif
#elif (VEHICLE_PLATFORM == VEHICLE_GEELY_G636)
#if HCM_LEFT_SIDE
uint8 Buffer_DcmDspData_0xF1AE[ DataLength_DcmDspData_0xF1AE ] = {0x02, 0x66, 0x08, 0x32, 0x86, 0x32, 0x20, 0x20, 0x41} ;
#else
uint8 Buffer_DcmDspData_0xF1AE[ DataLength_DcmDspData_0xF1AE ] = {0x02, 0x66, 0x08, 0x32, 0x86, 0x34, 0x20, 0x20, 0x41} ;
#endif
#endif
uint8 Buffer_DcmDspData_0xF1AE_Default[ DataLength_DcmDspData_0xF1AE ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF1F0 45u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF1F0[ DataLength_DcmDspData_0xF1F0 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF1F0_Default[ DataLength_DcmDspData_0xF1F0 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF1F1 54u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF1F1[ DataLength_DcmDspData_0xF1F1 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xF1F1_Default[ DataLength_DcmDspData_0xF1F1 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xED20 55u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xED20[ DataLength_DcmDspData_0xED20 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xED20_Default[ DataLength_DcmDspData_0xED20 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xEDA0 50u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xEDA0[ DataLength_DcmDspData_0xEDA0 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xEDA0_Default[ DataLength_DcmDspData_0xEDA0 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xDD07 6u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xDD07[ DataLength_DcmDspData_0xDD07 ] = {0x0} ;
uint8 Buffer_DcmDspData_0xDD07_Default[ DataLength_DcmDspData_0xDD07 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
DcmDspDataStruct *SharedData=( DcmDspDataStruct *)FL_BOOT_SHARE_DID_ADDRESS;


#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID434B_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4358_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4359_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435B_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435C_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435D_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435E_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435F_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4360_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4361_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4362_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4363_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4364_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    // Interface_DID4365_IoCtrCallback(E_IOCtrType_FreeCurState);
    // DCM_UNUSED(OpStatus);
    // DCM_UNUSED(ControlEnableMaskRecord);
    // DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    // Interface_DID4366_IoCtrCallback(E_IOCtrType_FreeCurState);
    // DCM_UNUSED(OpStatus);
    // DCM_UNUSED(ControlEnableMaskRecord);
    // DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4367_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID43A9_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID7022_IoCtrCallback(E_IOCtrType_FreeCurState);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x434B;index++)
    {
        Data[index] = Buffer_DcmDspData_0x434B[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4351_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4351;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4351[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4357_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4357;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4357[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4358;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4358[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4359;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4359[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435B;index++)
    {
        Data[index] = Buffer_DcmDspData_0x435B[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435C;index++)
    {
        Data[index] = Buffer_DcmDspData_0x435C[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435D;index++)
    {
        Data[index] = Buffer_DcmDspData_0x435D[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435E;index++)
    {
        Data[index] = Buffer_DcmDspData_0x435E[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435F;index++)
    {
        Data[index] = Buffer_DcmDspData_0x435F[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4360;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4360[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4361;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4361[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4362;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4362[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4363;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4363[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4364;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4364[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4365;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4365[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4366;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4366[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4367;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4367[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4368_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4368;index++)
    {
        Data[index] = Buffer_DcmDspData_0x4368[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x437C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
#if 0
    for(index = 0;index < DataLength_DcmDspData_0x437C;index++)
    {
        Data[index] = Buffer_DcmDspData_0x437C[index];
    }
#endif
    if(SharedData->Mask==DCMDSPDATAMASK)
    {
        for(index = 0;index < DataLength_DcmDspData_0x437C;index++)
        {
            Data[index] = SharedData->Buffer_DcmDspData_0x437C[index];
            Buffer_DcmDspData_0x437C[index] = SharedData->Buffer_DcmDspData_0x437C[index];
        }    
    }
    else
    {
        for(index = 0;index < DataLength_DcmDspData_0x437C;index++)
        {
            Data[index] = 0xFF;
            Buffer_DcmDspData_0x437C[index] = 0xFF;
        }     
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A8_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    /*NvM_ReadBlock(pDspDidData->DcmDspDataBlockId, (void*)&Dcm_Channel[*Dcm_0x22Type->ResOffset]);*/
    /* memcpy(Buffer_DcmDspData_0x43A8, NvM_BlockDescriptor[Nvm_Block_DCM - 1].NvmRamBlockDataAddress, DataLength_DcmDspData_0x43A8); */
    for(index = 0;index < DataLength_DcmDspData_0x43A8;index++)
    {
        Data[index] = NvM_BlockDescriptor[(Nvm_Block_DCM - 1)].NvmRamBlockDataAddress[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43A9;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43A9[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CA_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43CA;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43CA[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CE_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43CE;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43CE[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CF_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43CF;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43CF[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D0;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D0[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D1_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D1;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D1[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D2_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D2;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D2[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D3_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D3;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D3[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D4_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D4;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D4[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D5_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D5;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D5[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D7_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D7;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D7[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D8_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D8;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D8[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D9_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43D9;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43D9[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43DA_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43DA;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43DA[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43E0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43E0;index++)
    {
        Data[index] = Buffer_DcmDspData_0x43E0[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x7022;index++)
    {
        Data[index] = Buffer_DcmDspData_0x7022[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xD03A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8 index;
	boolean CheckResult = FALSE;
	uint32 CrcValue;
    /* get the point of PublicKeyAndSecConstNvmInfo */
    FL_PublicKeyAndSecConstInfoType  PublickKeyAndSecConstNvmInfo;
    #include "string.h"
    memcpy((uint8 *)&PublickKeyAndSecConstNvmInfo, (uint8 *)FL_PUBLICKEY_SECCONST_NVM_INFO_ADDRESS, (uint32)sizeof(FL_PublicKeyAndSecConstInfoType));

     if(PublickKeyAndSecConstNvmInfo.PublicKeyWritten == FL_OPERATE_SUCCEESSD_FLAG)
     {
		 CheckResult = TRUE;
     }

    if(CheckResult == FALSE)
    {
        if(ErrorCode != NULL_PTR)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        return E_NOT_OK;
    }
    else
    {
        for(index = 0;index < DataLength_DcmDspData_0xD03A;index++)
        {
            Data[index] = (uint8)PublickKeyAndSecConstNvmInfo.PublicKey[260+index];
        }
    }
    return E_OK;

}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xD134_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xD134;index++)
    {
        Data[index] = Buffer_DcmDspData_0xD134[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xD214_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;

    NmHistoryState_BaseDidReadBuf(Data);

    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD00_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xDD00;index++)
    {
        Data[index] = Buffer_DcmDspData_0xDD00[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD01_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xDD01;index++)
    {
        Data[index] = Buffer_DcmDspData_0xDD01[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD02_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xDD02;index++)
    {
        Data[index] = Buffer_DcmDspData_0xDD02[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xDD0A;index++)
    {
        Data[index] = Buffer_DcmDspData_0xDD0A[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  PNC_DATA[6];
    uint8 index;

    Com_ReceiveSignal(isCanNmEra_BodyExposedCAN_HCML, PNC_DATA);
       
    for(index = 0;index < DataLength_DcmDspData_0xDD0B;index++)
    {
        Data[index] = PNC_DATA[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xDD0C;index++)
    {
        Data[index] = Buffer_DcmDspData_0xDD0C[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xE103_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xE103;index++)
    {
        Data[index] = Buffer_DcmDspData_0xE103[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF120_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF120;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF120[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF126_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF126;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF126[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
#if 1
    for(index = 0;index < DataLength_DcmDspData_0xF12A;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF12A[index];
    }
#else
    if(SharedData->Mask==DCMDSPDATAMASK)
    {
        for(index = 0;index < DataLength_DcmDspData_0xF12A;index++)
        {
            Data[index] = SharedData->Buffer_DcmDspData_0xF12A[index];
        }    
    }
    else
    {
        for(index = 0;index < DataLength_DcmDspData_0xF12A;index++)
        {
            Data[index] = 0xFF;
        }     
    }
#endif
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
#if 1
    for(index = 0;index < DataLength_DcmDspData_0xF12B;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF12B[index];
    }
#else
    if(SharedData->Mask==DCMDSPDATAMASK)
    {
        for(index = 0;index < DataLength_DcmDspData_0xF12B;index++)
        {
            Data[index] = SharedData->Buffer_DcmDspData_0xF12B[index];
        }    
    }
    else
    {
        for(index = 0;index < DataLength_DcmDspData_0xF12B;index++)
        {
            Data[index] = 0xFF;
        }     
    }
#endif
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF12E;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF12E[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF13F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF13F;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF13F[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF186_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF186;index++)
    {
        Data[index]  = Dcm_MkCtrl.Dcm_ActiveSes;
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
#if 0
    for(index = 0;index < DataLength_DcmDspData_0xF18C;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF18C[index];
    }
#endif
    if(SharedData->Mask==DCMDSPDATAMASK)
    {
        for(index = 0;index < DataLength_DcmDspData_0xF18C;index++)
        {
            Data[index] = SharedData->Buffer_DcmDspData_0xF18C[index];
        }    
    }
    else
    {
        for(index = 0;index < DataLength_DcmDspData_0xF18C;index++)
        {
            Data[index] = 0xFF;
        }     
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1A0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF1A0;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF1A0[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AA_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
#if 0
    for(index = 0;index < DataLength_DcmDspData_0xF1AA;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF1AA[index];
    }
#endif
    if(SharedData->Mask==DCMDSPDATAMASK)
    {
        for(index = 0;index < DataLength_DcmDspData_0xF1AA;index++)
        {
            Data[index] = SharedData->Buffer_DcmDspData_0xF1AA[index];
        }    
    }
    else
    {
        for(index = 0;index < DataLength_DcmDspData_0xF1AA;index++)
        {
            Data[index] = 0xFF;
        }     
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AB_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
#if 0
    for(index = 0;index < DataLength_DcmDspData_0xF1AB;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF1AB[index];
    }
#endif
    if(SharedData->Mask==DCMDSPDATAMASK)
    {
        for(index = 0;index < DataLength_DcmDspData_0xF1AB;index++)
        {
            Data[index] = SharedData->Buffer_DcmDspData_0xF1AB[index];
        }    
    }
    else
    {
        for(index = 0;index < DataLength_DcmDspData_0xF1AB;index++)
        {
            Data[index] = 0xFF;
        }     
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AE_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    uint8 *PartNumberAddress;
#if 0
    for(index = 0;index < DataLength_DcmDspData_0xF1AE;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF1AE[index];
    }
#endif
#if HCM_LEFT_SIDE
    PartNumberAddress=Get_LeftPartNumber_Address();
#else
    PartNumberAddress=Get_RightPartNumber_Address();
#endif

    for(index = 0;index < 8;index++)
    {
        Buffer_DcmDspData_0xF1AE[(9+index)] = PartNumberAddress[(7-index)];
    }

    for(index = 0;index < DataLength_DcmDspData_0xF1AE;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF1AE[index];
    }


    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1F0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    Data[0]=1;
    Data[1]=FIF0_DATA_01;
    Data[2]=VER_SW_MAJOR;
    Data[3]=VER_SW_MINOR;
    Data[4]=VER_SW_REVIS;
    Data[5]=BASE_TECH_PLATFORM;
    Data[6]=VEHICLE_PLATFORM;
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1F1_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
#if 0
    for(index = 0;index < DataLength_DcmDspData_0xF1F1;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF1F1[index];
    }
#endif
    Data[0]=SharedData->LeftRightFlag;
    Data[1]=ParaMgr_Customer_B;
    Data[2]=(uint8)(ParaMgr_Vehicle_W>>8);
    Data[3]=(uint8)ParaMgr_Vehicle_W;
    Data[4]=ParaMgr_Variant_B;
    Data[5]=ParaMgr_TemV_H_B;
    Data[6]=ParaMgr_TemV_L_B;
    Data[7]=ParaMgr_DocV_H_B;
    Data[8]=ParaMgr_DocV_L_B;
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xED20_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    uint8 offset=0;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0xA0;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1A0_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF1A0;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0xAA;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AA_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF1AA;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0xAB;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AB_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF1AB;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0x8C;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF18C;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0xAE;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AE_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF1AE;


    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xEDA0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    uint8 offset=0;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0x20;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF120_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF120;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0x2A;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12A_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF12A;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0x2B;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12B_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF12B;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0x8C;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF18C;

    Data[offset] = 0xF1;
    Data[(++offset)] = 0x2E;
    offset++;
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12E_ReadData(0,&(Data[offset]),ErrorCode);
    offset+=DataLength_DcmDspData_0xF12E;

    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD07_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xDD07;index++)
    {
        Data[index] = Buffer_DcmDspData_0xDD07[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x434B;index++)
    {
        Buffer_DcmDspData_0x434B[index] = Buffer_DcmDspData_0x434B_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4358;index++)
    {
        Buffer_DcmDspData_0x4358[index] = Buffer_DcmDspData_0x4358_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4359;index++)
    {
        Buffer_DcmDspData_0x4359[index] = Buffer_DcmDspData_0x4359_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435B;index++)
    {
        Buffer_DcmDspData_0x435B[index] = Buffer_DcmDspData_0x435B_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435C;index++)
    {
        Buffer_DcmDspData_0x435C[index] = Buffer_DcmDspData_0x435C_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435D;index++)
    {
        Buffer_DcmDspData_0x435D[index] = Buffer_DcmDspData_0x435D_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435E;index++)
    {
        Buffer_DcmDspData_0x435E[index] = Buffer_DcmDspData_0x435E_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x435F;index++)
    {
        Buffer_DcmDspData_0x435F[index] = Buffer_DcmDspData_0x435F_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4360;index++)
    {
        Buffer_DcmDspData_0x4360[index] = Buffer_DcmDspData_0x4360_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4361;index++)
    {
        Buffer_DcmDspData_0x4361[index] = Buffer_DcmDspData_0x4361_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4362;index++)
    {
        Buffer_DcmDspData_0x4362[index] = Buffer_DcmDspData_0x4362_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4363;index++)
    {
        Buffer_DcmDspData_0x4363[index] = Buffer_DcmDspData_0x4363_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4364;index++)
    {
        Buffer_DcmDspData_0x4364[index] = Buffer_DcmDspData_0x4364_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4365;index++)
    {
        Buffer_DcmDspData_0x4365[index] = Buffer_DcmDspData_0x4365_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4366;index++)
    {
        Buffer_DcmDspData_0x4366[index] = Buffer_DcmDspData_0x4366_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x4367;index++)
    {
        Buffer_DcmDspData_0x4367[index] = Buffer_DcmDspData_0x4367_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x43A9;index++)
    {
        Buffer_DcmDspData_0x43A9[index] = Buffer_DcmDspData_0x43A9_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0x7022;index++)
    {
        Buffer_DcmDspData_0x7022[index] = Buffer_DcmDspData_0x7022_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID434B_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4358_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4359_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435B_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435C_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435D_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435E_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID435F_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4360_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4361_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4362_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4363_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4364_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    // Interface_DID4365_IoCtrCallback(E_IOCtrType_ReturnControl);
    // DCM_UNUSED(ControlEnableMaskRecord);
    // DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    // Interface_DID4366_IoCtrCallback(E_IOCtrType_ReturnControl);
    // DCM_UNUSED(ControlEnableMaskRecord);
    // DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID4367_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID43A9_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Interface_DID7022_IoCtrCallback(E_IOCtrType_ReturnControl);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x434B + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x434B_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID434B_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4358 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4358_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4358_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4359 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4359_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4359_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x435B + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x435B_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID435B_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x435C + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x435C_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID435C_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x435D + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x435D_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID435D_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x435E + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x435E_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID435E_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x435F + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x435F_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID435F_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4360 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4360_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4360_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4361 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4361_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4361_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4362 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4362_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4362_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4363 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4363_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4363_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4364 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4364_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4364_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    // uint8  index;
    // for(index = 0;index < (DataLength_DcmDspData_0x4365 + IO_MASK_CNT);index++)
    // {
    //     Buffer_DcmDspData_0x4365_OptionRecord[index] = ControlOptionRecord[index];
    // }
    // Interface_DID4365_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    // DCM_UNUSED(ControlOptionRecord);
    // DCM_UNUSED(DataLength);
    // DCM_UNUSED(OpStatus);
    // DCM_UNUSED(ControlEnableMaskRecord);
    // DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    // uint8  index;
    // for(index = 0;index < (DataLength_DcmDspData_0x4366 + IO_MASK_CNT);index++)
    // {
    //     Buffer_DcmDspData_0x4366_OptionRecord[index] = ControlOptionRecord[index];
    // }
    // Interface_DID4366_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    // DCM_UNUSED(ControlOptionRecord);
    // DCM_UNUSED(DataLength);
    // DCM_UNUSED(OpStatus);
    // DCM_UNUSED(ControlEnableMaskRecord);
    // DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x4367 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x4367_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID4367_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x43A9 + IO_MASK_CNT);index++)
    {
        Buffer_DcmDspData_0x43A9_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID43A9_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8  index;
    for(index = 0;index < (DataLength_DcmDspData_0x7022);index++)
    {
        Buffer_DcmDspData_0x7022_OptionRecord[index] = ControlOptionRecord[index];
    }
    Interface_DID7022_IoCtrCallback(E_IOCtrType_ShortTermAdjustment);
    DCM_UNUSED(ControlOptionRecord);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A8_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index = 0;
    for(index = 0; index < DataLength_DcmDspData_0x43A8; index++)
    {
        Buffer_DcmDspData_0x43A8[index] = Data[index];
    }

    memcpy(NvM_BlockDescriptor[Nvm_Block_DCM - 1].NvmRamBlockDataAddress, Buffer_DcmDspData_0x43A8, DataLength_DcmDspData_0x43A8);

    NvM_WriteBlock(Nvm_Block_DCM, NULL_PTR);
    Interface_SetDid43A8WriteFlag(1);
    DCM_UNUSED(Data);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/***************************Routine Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion_LevelingMotorReferenceRun, InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion_SwivelingMotorReferenceRun, InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion_LevellingMotorMove, InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    
    Std_ReturnType rtval;
    rtval=Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion_SwivelingMotorMove, InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion_FanControl, InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    
    rtval = Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion_LeftRightDetection,InBuffer,OutBuffer);

    return rtval;
#if 0
    DCM_UNUSED(InBuffer);
    DCM_UNUSED(OutBuffer);
    DCM_UNUSED(currentDataLength);
    DCM_UNUSED(ErrorCode);
    return E_OK;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x0206_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{

    Interface_StartRoutineCallBack(E_RountineCrtFuntion_CheckProgramePrecondition,InBuffer,OutBuffer);

    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval=E_OK;
    rtval = Interface_StartRoutineCallBack(E_RountineCrtFuntion_LevelingMotorReferenceRun,InBuffer,OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval=E_OK;
    rtval = Interface_StartRoutineCallBack(E_RountineCrtFuntion_SwivelingMotorReferenceRun,InBuffer,OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval=E_OK;
    rtval = Interface_StartRoutineCallBack(E_RountineCrtFuntion_LevellingMotorMove,InBuffer,OutBuffer);
    return rtval;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval=E_OK;
    rtval = Interface_StartRoutineCallBack(E_RountineCrtFuntion_SwivelingMotorMove,InBuffer,OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval=E_OK;
    rtval = Interface_StartRoutineCallBack(E_RountineCrtFuntion_FanControl,InBuffer,OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;

    rtval = Interface_StartRoutineCallBack(E_RountineCrtFuntion_LeftRightDetection,InBuffer,OutBuffer);

    return rtval;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_StopRoutineCallBack(E_RountineCrtFuntion_LevelingMotorReferenceRun,InBuffer, OutBuffer);
    return rtval;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_StopRoutineCallBack(E_RountineCrtFuntion_SwivelingMotorReferenceRun,InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_StopRoutineCallBack(E_RountineCrtFuntion_LevellingMotorMove,InBuffer, OutBuffer);
    return rtval;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_StopRoutineCallBack(E_RountineCrtFuntion_SwivelingMotorMove,InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType rtval;
    rtval=Interface_StopRoutineCallBack(E_RountineCrtFuntion_FanControl,InBuffer, OutBuffer);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
     Std_ReturnType rtval;   

     rtval = Interface_StopRoutineCallBack(E_RountineCrtFuntion_LeftRightDetection,InBuffer,OutBuffer);

     return rtval;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**************function for ClearDTC**************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_ClearDTCCheck(uint32 GoDTC,Dcm_NegativeResponseCodeType* ErrorCode)
{
    DCM_UNUSED(GoDTC);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/*PreConditon Check*/
Std_ReturnType RTE_PreConditonCheck_Dcm10(uint8 subservice)
{
    Std_ReturnType rval = E_OK;
    double speed;
    uint32_t signalval;
    S_E2EStateForFailSafe SafetyFlag;

    if(subservice == 0x02 || subservice == 0x03)
    {
        if(subservice == 0x02)
        {
            SafetyFlag = GetE2EFlagForFailSafe();
            if(SafetyFlag.E2EErrorFlagForFailSafe.bits.UsgModeTimeout ==1 || SafetyFlag.E2EErrorFlagForFailSafe.bits.VehSpdTimeout ==1)
            {
                return E_OK;
            }
        }
        /*进入编程会话*/
        Interface_GetSignal_VehSpdLgtQf(&signalval);
        if (signalval != 2 && signalval != 3)
            rval = E_NOT_OK;

        Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&signalval);
        if ((E_UsageModeSts)signalval == E_UsageModeSts_Drvg)
            rval = E_NOT_OK;

        Interface_GetSignal_VehSpdLgtA(&speed);
        /*
        *  1(km/h)=0.277777(m/s)
        *  4(km/h)=1.111111(m/s)
        */
        if ((speed / 0.277777) > 3)
            rval = E_NOT_OK;

    }

    return rval;
}
Std_ReturnType RTE_PreConditonCheck(void)
{
    double speed;
    uint32_t signalval;
    S_E2EStateForFailSafe SafetyFlag;
    
    SafetyFlag = GetE2EFlagForFailSafe();
    if(SafetyFlag.E2EErrorFlagForFailSafe.bits.UsgModeTimeout ==1 || SafetyFlag.E2EErrorFlagForFailSafe.bits.VehSpdTimeout ==1)
    {
        return E_OK;
    }


    Interface_GetSignal_VehSpdLgtQf(&signalval);
    if (signalval != 2 && signalval != 3)
        return E_NOT_OK;

    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&signalval);
    if ((E_UsageModeSts)signalval == E_UsageModeSts_Drvg)
        return E_NOT_OK;

    Interface_GetSignal_VehSpdLgtA(&speed);
    /*
     *  1(km/h)=0.277777(m/s)
     *  4(km/h)=1.111111(m/s)
     */
    if ((speed / 0.277777) > 3)
        return E_NOT_OK;

    return E_OK;

}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset)
{
    if (Reset == RTE_MODE_DcmEcuReset_EXECUTE)
    {
        /*Ecu复位的时候不存Dtc*/
#if 0 
        uint32 RESET_NVM_USE_TIME = 0;
        NvM_RequestResultType RequestResultPtr = NVM_REQ_NOT_OK;
        Dem_Shutdown();
        NvM_WriteAll();
        do
        {
            RESET_NVM_USE_TIME++;
            NvM_MainFunction();
            Fee_MainFunction();
            Fls_MainFunction();
            NvM_GetErrorStatus(0,&RequestResultPtr);
            if(RESET_NVM_USE_TIME == 500)
                break;
        }while (RequestResultPtr== NVM_REQ_PENDING);
#endif         
        
        Mcu_PerformReset();
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

