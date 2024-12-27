/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.h>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-16 14:21:13>
 */
/*============================================================================*/


#ifndef RTEDCM_H
#define RTEDCM_H


#include "Rte_Dcm_Type.h"

/***************************Security Part****************************************/
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8*  AttemptCounter );
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8*  AttemptCounter );

extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_GetSeed( Dcm_OpStatusType  OpStatus,uint8*  Seed, Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_GetSeed( Dcm_OpStatusType  OpStatus,uint8*  Seed, Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter );
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter );
/***************************Did Part****************************************/




extern  Std_ReturnType  DcmDspDataReadF193( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF195( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataRead_4B40( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF010( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF110( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF111( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF118( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF119( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF15B( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF186( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF187( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF18A( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF18B( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF18C( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF192( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF194( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF197( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF199( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF19E( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  DcmDspDataReadF150( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );


extern  Std_ReturnType  Rte_ReturnControlToECU_4B40( Dcm_OpStatusType  OpStatus,uint8*  ControlEnableMaskRecord,Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_ShortTermAdjustment_4B40( const  uint8*  ControlOptionRecord,uint16  DataLength,uint8*  ControlEnableMaskRecord,Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_WriteData_F110( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_WriteData_F111( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_WriteData_F187( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_WriteData_F18B( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_WriteData_F18C( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
/***************************Routine Part****************************************/

extern  Std_ReturnType  Rte_DcmRoutineStart_0203(const  uint8*  dataInVar,
											       uint8*  dataOutVar,
											       Dcm_NegativeResponseCodeType*  ErrorCode);


#endif /*RTEDCM_H*/
