/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-03-21 10:57:33>
 */
/*============================================================================*/

#ifndef RTEDCM_H
#define RTEDCM_H

#include "Dcm_Types.h"
/* Public Key operate */
#define RSA_PUBLIC_KEY_LENGTH    		292u
#define SECM_SECCONST_LENGTH    		5U
#define FL_PUBLICKEY_SECCONST_NVM_INFO_ADDRESS  (0x0101E000U)
#define FL_BOOT_SHARE_DID_ADDRESS               (0x1E0000)

/** PublicKey information */
typedef struct
{
    /* Public Key */
    uint8 PublicKey[RSA_PUBLIC_KEY_LENGTH];
    /* flag if PublicKey has written */
    uint32 PublicKeyWritten;
    
    /* Safety constant */
    uint8 security[SECM_SECCONST_LENGTH];
    /* flag if security constant has written */
    uint32 securityConstantWritten;

    uint8 reserved[3];

    /*information checksum */
    uint32 infoChecksum;

}FL_PublicKeyAndSecConstInfoType;
/* PRAQ S 0777,0779++ */ /* MISRA Rule 5.1,Rule 1.3 */


extern uint8 Buffer_DcmDspData_0x434B[ 4 ]  ;
extern uint8 Buffer_DcmDspData_0x434B_Default[ 4 ]  ;
extern uint8 Buffer_DcmDspData_0x434B_OptionRecord[(4+1)] ;

extern uint8 Buffer_DcmDspData_0x4358[ 3 ]  ;
extern uint8 Buffer_DcmDspData_0x4358_Default[ 3 ]  ;
extern uint8 Buffer_DcmDspData_0x4358_OptionRecord[(3+1)] ;

extern uint8 Buffer_DcmDspData_0x4359[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4359_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4359_OptionRecord[(11+1)] ;

extern uint8 Buffer_DcmDspData_0x435B[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435B_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435B_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x435C[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435C_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435C_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x435D[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435D_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435D_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x435E[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435E_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435E_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x435F[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435F_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x435F_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x4360[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4360_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4360_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x4361[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4361_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4361_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x4362[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4362_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4362_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x4363[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4363_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4363_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x4364[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4364_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4364_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x4367[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4367_Default[ 11 ]  ;
extern uint8 Buffer_DcmDspData_0x4367_OptionRecord[ (11+1)];

extern uint8 Buffer_DcmDspData_0x4365[ 2 ]  ;
extern uint8 Buffer_DcmDspData_0x4365_Default[ 2 ]  ;
extern uint8 Buffer_DcmDspData_0x4365_OptionRecord[ (2+1)];

extern uint8 Buffer_DcmDspData_0x4366[ 2 ]  ;
extern uint8 Buffer_DcmDspData_0x4366_Default[ 2 ]  ;
extern uint8 Buffer_DcmDspData_0x4366_OptionRecord[ (2+1)];

extern uint8 Buffer_DcmDspData_0x43A9[ 3 ]  ;
extern uint8 Buffer_DcmDspData_0x43A9_Default[ 3 ]  ;
extern uint8 Buffer_DcmDspData_0x43A9_OptionRecord[ (3+1)];

extern uint8 Buffer_DcmDspData_0x7022[ 84 ]  ;
extern uint8 Buffer_DcmDspData_0x7022_Default[ 84 ]  ;
extern uint8 Buffer_DcmDspData_0x7022_OptionRecord[ (84 +1)];

extern uint8 Buffer_DcmDspData_0x4351[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x4351_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x4357[ 2 ]  ;
extern uint8 Buffer_DcmDspData_0x4357_Default[ 2 ] ;

extern uint8 Buffer_DcmDspData_0x4368[ 4 ]  ;
extern uint8 Buffer_DcmDspData_0x4368_Default[ 4 ] ;

extern uint8 Buffer_DcmDspData_0x437C[ 24 ]  ;
extern uint8 Buffer_DcmDspData_0x437C_Default[ 24 ] ;

extern uint8 Buffer_DcmDspData_0x43A8[ 100 ]  ;
extern uint8 Buffer_DcmDspData_0x43A8_Default[ 100 ] ;

extern uint8 Buffer_DcmDspData_0x43CA[ 3 ]  ;
extern uint8 Buffer_DcmDspData_0x43CA_Default[ 3 ] ;

extern uint8 Buffer_DcmDspData_0x43CE[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43CE_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43CF[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43CF_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D0[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D0_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D1[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D1_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D2[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D2_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D3[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D3_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D4[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D4_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D5[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D5_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D7[ 2 ]  ;
extern uint8 Buffer_DcmDspData_0x43D7_Default[ 2 ] ;

extern uint8 Buffer_DcmDspData_0x43D8[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D8_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43D9[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0x43D9_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0x43DA[ 2 ]  ;
extern uint8 Buffer_DcmDspData_0x43DA_Default[ 2 ] ;

extern uint8 Buffer_DcmDspData_0xD134[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0xD134_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0xDD00[ 4 ]  ;
extern uint8 Buffer_DcmDspData_0xDD00_Default[ 4 ] ;

extern uint8 Buffer_DcmDspData_0xDD01[ 3 ]  ;
extern uint8 Buffer_DcmDspData_0xDD01_Default[ 3 ] ;

extern uint8 Buffer_DcmDspData_0xDD02[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0xDD02_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0xDD0A[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0xDD0A_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0xDD0C[ 1 ]  ;
extern uint8 Buffer_DcmDspData_0xDD0C_Default[ 1 ] ;

extern uint8 Buffer_DcmDspData_0xDD07[ 6 ] ;
extern uint8 Buffer_DcmDspData_0xDD07_Default[ 6 ] ;


typedef struct {
	uint32 Mask;
	uint8 Buffer_DcmDspData_0xF121[7];
	uint8 Buffer_DcmDspData_0xF125[7];
	uint8 Buffer_DcmDspData_0xF12A[7];
	uint8 Buffer_DcmDspData_0xF12B[7];
	uint8 Buffer_DcmDspData_0x437C[24];
	uint8 Buffer_DcmDspData_0xF18C[4];
	uint8 Buffer_DcmDspData_0xF1A1[8];
	uint8 Buffer_DcmDspData_0xF1A5[8];
	uint8 Buffer_DcmDspData_0xF1AA[8];
	uint8 Buffer_DcmDspData_0xF1AB[8];
    uint8 LeftRightFlag;
} DcmDspDataStruct;
#define DCMDSPDATAMASK 0x5A5A5A5AU
#define SIDE_DETECT_LEFT_PBL    0x55
#define SIDE_DETECT_RIGHT_PBL   0xAA
/***************************Security Part****************************************/
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8*  AttemptCounter );

extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode);

extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter );
/***************************Did Part****************************************/

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_FreezeCurrentState(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4351_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4357_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4368_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x437C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A8_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CA_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CE_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43CF_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D1_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D2_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D3_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D4_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D5_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D7_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D8_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43D9_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43DA_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43E0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xD03A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xD134_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xD214_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD00_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD01_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD02_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xE103_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF120_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF126_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF12E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF13F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF186_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1A0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AA_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AB_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1AE_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1F0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF1F1_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xED20_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xEDA0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD07_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x434B_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4358_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4359_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435B_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435C_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435D_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435E_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x435F_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4360_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4361_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4362_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4363_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4364_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4365_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4366_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x4367_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A9_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x7022_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A8_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
/***************************Routine Part****************************************/
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_RequestResults(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x0206_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF100_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF101_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF102_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF103_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF104_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF106_Stop(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/**************function for ClearDTC**************************/
extern Std_ReturnType Rte_ClearDTCCheck(uint32 GoDTC,Dcm_NegativeResponseCodeType* ErrorCode);

/********* PreConditon Check ***********************/
extern Std_ReturnType Dcm_Rte_PreConditonCheck;
extern Std_ReturnType RTE_PreConditonCheck_Dcm10(uint8 subservice);
extern Std_ReturnType RTE_PreConditonCheck(void);

extern Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset);

/* PRAQ S 0777,0779-- */ /* MISRA Rule 5.1,Rule 1.3 */

#endif /*RTEDCM_H*/

