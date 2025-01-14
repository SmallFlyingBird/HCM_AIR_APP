/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-16 14:21:13>
 */
/*============================================================================*/

#include "Rte_Dcm.h"

#define  DataLength_FalseAcessCount_DcmDspSecurityRow_1 1 
uint8  Buffer_FalseAcessCount_DcmDspSecurityRow_1[DataLength_FalseAcessCount_DcmDspSecurityRow_1]  =  {0x0};
#define  Offset_FalseAcessCount_DcmDspSecurityRow_1 
#define  DataLength_FalseAcessCount_DcmDspSecurityRow_2 1 
uint8  Buffer_FalseAcessCount_DcmDspSecurityRow_2[DataLength_FalseAcessCount_DcmDspSecurityRow_2]  =  {0x0};
#define  Offset_FalseAcessCount_DcmDspSecurityRow_2 
#define  DataLength_FalseAcessCount_DcmDspSecurityRow_4 1 
uint8  Buffer_FalseAcessCount_DcmDspSecurityRow_4[DataLength_FalseAcessCount_DcmDspSecurityRow_4]  =  {0x0};
#define  Offset_FalseAcessCount_DcmDspSecurityRow_4 
/***************************Security Part****************************************/
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}

Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,uint8*  AttemptCounter )
{
#ifdef  DCM_DDDID_STORAGE_BLOCKID
#ifdef  Offset_FalseAcessCount_DcmDspSecurityRow_1
    (*AttemptCounter) = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_FalseAcessCount_DcmDspSecurityRow_1);
#endif
#else
    (*AttemptCounter) = Buffer_FalseAcessCount_DcmDspSecurityRow_1[0];
#endif
	return E_OK;
}
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,uint8*  AttemptCounter )
{
#ifdef  DCM_DDDID_STORAGE_BLOCKID
#ifdef  Offset_FalseAcessCount_DcmDspSecurityRow_2
    (*AttemptCounter) = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_FalseAcessCount_DcmDspSecurityRow_2);
#endif
#else
    (*AttemptCounter) = Buffer_FalseAcessCount_DcmDspSecurityRow_2[0];
#endif
	return E_OK;
}

Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_GetSeed( Dcm_OpStatusType  OpStatus,uint8*  Seed,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_GetSeed( Dcm_OpStatusType  OpStatus,uint8*  Seed,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    return E_OK;
}

Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter )
{
#ifdef  DCM_DDDID_STORAGE_BLOCKID
#ifdef  Offset_FalseAcessCount_DcmDspSecurityRow_1
    *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_FalseAcessCount_DcmDspSecurityRow_1) = AttemptCounter;
NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
#endif
#else
    Buffer_FalseAcessCount_DcmDspSecurityRow_1[0] = AttemptCounter;
#endif
	return E_OK;
}
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_2_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter )
{
#ifdef  DCM_DDDID_STORAGE_BLOCKID
#ifdef  Offset_FalseAcessCount_DcmDspSecurityRow_2
    *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_FalseAcessCount_DcmDspSecurityRow_2) = AttemptCounter;
NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
#endif
#else
    Buffer_FalseAcessCount_DcmDspSecurityRow_2[0] = AttemptCounter;
#endif
	return E_OK;
}
/***************************Did Part****************************************/
#define  DataLength_DcmDspData_F193 4 
uint8 Buffer_DcmDspData_F193[ DataLength_DcmDspData_F193 ] = {0x0};
#define  DataLength_DcmDspData_F195 4 
uint8 Buffer_DcmDspData_F195[ DataLength_DcmDspData_F195 ] = {0x0};
#define  DataLength_DcmDspData_4B40 1 
uint8 Buffer_DcmDspData_4B40[ DataLength_DcmDspData_4B40 ] = {0x0};
#define  DataLength_DcmDspData_F010TBD 4 
uint8 Buffer_DcmDspData_F010TBD[ DataLength_DcmDspData_F010TBD ] = {0x0};
#define  DataLength_DcmDspData_F110 11 
uint8 Buffer_DcmDspData_F110[ DataLength_DcmDspData_F110 ] = {0x0};
#define  DataLength_DcmDspData_F111 2 
uint8 Buffer_DcmDspData_F111[ DataLength_DcmDspData_F111 ] = {0x0};
#define  DataLength_DcmDspData_F118 11 
uint8 Buffer_DcmDspData_F118[ DataLength_DcmDspData_F118 ] = {0x0};
#define  DataLength_DcmDspData_F119 2 
uint8 Buffer_DcmDspData_F119[ DataLength_DcmDspData_F119 ] = {0x0};
#define  DataLength_DcmDspData_F15B 12 
uint8 Buffer_DcmDspData_F15B[ DataLength_DcmDspData_F15B ] = {0x0};
#define  DataLength_DcmDspData_F186 1 
uint8 Buffer_DcmDspData_F186[ DataLength_DcmDspData_F186 ] = {0x0};
#define  DataLength_DcmDspData_F187 11 
uint8 Buffer_DcmDspData_F187[ DataLength_DcmDspData_F187 ] = {0x0};
#define  DataLength_DcmDspData_F18A 8 
uint8 Buffer_DcmDspData_F18A[ DataLength_DcmDspData_F18A ] = {0x0};
#define  DataLength_DcmDspData_F18B 3 
uint8 Buffer_DcmDspData_F18B[ DataLength_DcmDspData_F18B ] = {0x0};
#define  DataLength_DcmDspData_F18C 10 
uint8 Buffer_DcmDspData_F18C[ DataLength_DcmDspData_F18C ] = {0x0};
#define  DataLength_DcmDspData_F192TBD 9 
uint8 Buffer_DcmDspData_F192TBD[ DataLength_DcmDspData_F192TBD ] = {0x0};
#define  DataLength_DcmDspData_F194TBD 9 
uint8 Buffer_DcmDspData_F194TBD[ DataLength_DcmDspData_F194TBD ] = {0x0};
#define  DataLength_DcmDspData_F197 8 
uint8 Buffer_DcmDspData_F197[ DataLength_DcmDspData_F197 ] = {0x0};
#define  DataLength_DcmDspData_F199 3 
uint8 Buffer_DcmDspData_F199[ DataLength_DcmDspData_F199 ] = {0x0};
#define  DataLength_DcmDspData_F19E 3 
uint8 Buffer_DcmDspData_F19E[ DataLength_DcmDspData_F19E ] = {0x0};
#define  DataLength_DcmDspData_F150 3 
uint8 Buffer_DcmDspData_F150[ DataLength_DcmDspData_F150 ] = {0x0};
#define  DataLength_DcmDspData_F15A 12 
uint8 Buffer_DcmDspData_F15A[ DataLength_DcmDspData_F15A ] = {0x0};




Std_ReturnType  DcmDspDataReadF193( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F193;index++)
    {
#ifdef  Offset_DcmDspData_F193
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F193 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F193[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF195( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F195;index++)
    {
#ifdef  Offset_DcmDspData_F195
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F195 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F195[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataRead_4B40( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_4B40;index++)
    {
#ifdef  Offset_DcmDspData_4B40
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_4B40 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_4B40[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF010( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F010TBD;index++)
    {
#ifdef  Offset_DcmDspData_F010TBD
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F010TBD + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F010TBD[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF110( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F110;index++)
    {
#ifdef  Offset_DcmDspData_F110
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F110 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F110[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF111( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F111;index++)
    {
#ifdef  Offset_DcmDspData_F111
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F111 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F111[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF118( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F118;index++)
    {
#ifdef  Offset_DcmDspData_F118
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F118 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F118[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF119( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F119;index++)
    {
#ifdef  Offset_DcmDspData_F119
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F119 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F119[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF15B( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F15B;index++)
    {
#ifdef  Offset_DcmDspData_F15B
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F15B + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F15B[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF186( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F186;index++)
    {
#ifdef  Offset_DcmDspData_F186
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F186 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F186[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF187( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F187;index++)
    {
#ifdef  Offset_DcmDspData_F187
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F187 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F187[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF18A( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F18A;index++)
    {
#ifdef  Offset_DcmDspData_F18A
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F18A + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F18A[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF18B( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F18B;index++)
    {
#ifdef  Offset_DcmDspData_F18B
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F18B + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F18B[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF18C( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F18C;index++)
    {
#ifdef  Offset_DcmDspData_F18C
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F18C + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F18C[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF192( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F192TBD;index++)
    {
#ifdef  Offset_DcmDspData_F192TBD
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F192TBD + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F192TBD[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF194( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F194TBD;index++)
    {
#ifdef  Offset_DcmDspData_F194TBD
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F194TBD + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F194TBD[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF197( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F197;index++)
    {
#ifdef  Offset_DcmDspData_F197
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F197 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F197[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF199( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F199;index++)
    {
#ifdef  Offset_DcmDspData_F199
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F199 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F199[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF19E( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F19E;index++)
    {
#ifdef  Offset_DcmDspData_F19E
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F19E + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F19E[index];
#endif
    }
	return E_OK;
}
Std_ReturnType  DcmDspDataReadF150( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_F150;index++)
    {
#ifdef  Offset_DcmDspData_F150
#ifdef  DCM_DDDID_STORAGE_BLOCKID
        Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F150 + index);
#endif
#else
        Data[index] = Buffer_DcmDspData_F150[index];
#endif
    }
	return E_OK;
}


Std_ReturnType  Rte_ReturnControlToECU_4B40( Dcm_OpStatusType  OpStatus,uint8*  ControlEnableMaskRecord,Dcm_NegativeResponseCodeType*  ErrorCode )
{
return E_OK;
}

Std_ReturnType  Rte_ShortTermAdjustment_4B40( const  uint8*  ControlOptionRecord,uint16  DataLength,uint8*  ControlEnableMaskRecord,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8  index;
    for(index = 0;index < DataLength_DcmDspData_4B40;index++)
    {
        Buffer_DcmDspData_4B40[index] = ControlOptionRecord[index];
    }
	return E_OK;
}

Std_ReturnType  Rte_WriteData_F110( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode ) 
{
	uint8  index = 0;
    for(index = 0; index < DataLength_DcmDspData_F110; index++)
    {
#ifdef DCM_DDDID_STORAGE_BLOCKID
#ifdef Offset_DcmDspData_F110
        *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F110 + index) = Data[index] ;
#endif
#else
        Buffer_DcmDspData_F110[index] = Data[index];
#endif
    }
#ifdef DCM_DDDID_STORAGE_BLOCKID
    NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
#endif
	return E_OK;
}
Std_ReturnType  Rte_WriteData_F111( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode ) 
{
	uint8  index = 0;
    for(index = 0; index < DataLength_DcmDspData_F111; index++)
    {
#ifdef DCM_DDDID_STORAGE_BLOCKID
#ifdef Offset_DcmDspData_F111
        *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F111 + index) = Data[index] ;
#endif
#else
        Buffer_DcmDspData_F111[index] = Data[index];
#endif
    }
#ifdef DCM_DDDID_STORAGE_BLOCKID
    NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
#endif
	return E_OK;
}
Std_ReturnType  Rte_WriteData_F187( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode ) 
{
	uint8  index = 0;
    for(index = 0; index < DataLength_DcmDspData_F187; index++)
    {
#ifdef DCM_DDDID_STORAGE_BLOCKID
#ifdef Offset_DcmDspData_F187
        *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F187 + index) = Data[index] ;
#endif
#else
        Buffer_DcmDspData_F187[index] = Data[index];
#endif
    }
#ifdef DCM_DDDID_STORAGE_BLOCKID
    NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
#endif
	return E_OK;
}
Std_ReturnType  Rte_WriteData_F18B( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode ) 
{
	uint8  index = 0;
    for(index = 0; index < DataLength_DcmDspData_F18B; index++)
    {
#ifdef DCM_DDDID_STORAGE_BLOCKID
#ifdef Offset_DcmDspData_F18B
        *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F18B + index) = Data[index] ;
#endif
#else
        Buffer_DcmDspData_F18B[index] = Data[index];
#endif
    }
#ifdef DCM_DDDID_STORAGE_BLOCKID
    NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
#endif
	return E_OK;
}
Std_ReturnType  Rte_WriteData_F18C( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode ) 
{
	uint8  index = 0;
    for(index = 0; index < DataLength_DcmDspData_F18C; index++)
    {
#ifdef DCM_DDDID_STORAGE_BLOCKID
#ifdef Offset_DcmDspData_F18C
        *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_F18C + index) = Data[index] ;
#endif
#else
        Buffer_DcmDspData_F18C[index] = Data[index];
#endif
    }
#ifdef DCM_DDDID_STORAGE_BLOCKID
    NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
#endif
	return E_OK;
}
/***************************Routine Part****************************************/		

Std_ReturnType  Rte_DcmRoutineStart_0203(const  uint8*  dataInVar,
		                                 uint8*  dataOutVar,
		                                 Dcm_NegativeResponseCodeType*  ErrorCode) 
{
return E_OK;
}

