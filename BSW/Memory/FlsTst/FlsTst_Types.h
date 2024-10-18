/*============================================================================*/
/*  Copyright (C) 2021, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       <FlsTst.h>
 *  brief      <Containing the entire or parts of Flash test code.>
 *
 *  <Compiler: S32DS 2.2 with GreenHills  MCU:S32K146>
 *
 *  author     <yin.Huang>
 *  date       <2021-9-16>
 */
/*============================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>      <AUTHOR>         <REVISION LOG>
 *   V1.0.0     20210916     Huangyin         Initial version
 */
/*============================================================================*/
#ifndef FLSTST_TYPES_H
#define FLSTST_TYPES_H


/*============================[I N C L U D E S]===============================*/
#include "Std_Types.h"



typedef uint8       FlsTst_BlockIdType; 
typedef uint32      FlsTst_IntervalIDType;
typedef uint32      FlsTst_AddressType;
typedef uint32      FlsTst_LengthType;
typedef uint32      FlsTst_SignatureType;

typedef FlsTst_BlockIdType FlsTst_BlockIdFgndType;

typedef P2FUNC(void, FLSTST_CODE, FlsTst_UserNotificationPtrType)(void);


typedef enum
{
    /* The Flash Test is not initialized or not usable. */
    FLSTST_UNINIT           =0x00, 

    /* The Flash Test is initialized and ready to be started. */
    FLSTST_INIT             =0x01,  

    /* The Flash Test is currently running */
    FLSTST_RUNNING          =0x02,  

    /* The Flash Test is aborted. */
    FLSTST_ABORTED          =0x03,  

    /* The Flash Test is waiting to be resumed or is waiting to start foreground mode test */
    FLSTST_SUSPENDED        =0x04   
} FlsTst_StateType;


typedef enum
{
    /* There is no result availabl. */
    FLSTST_RESULT_NOT_TESTED    =0x00,  

    /* The last Flash Test has been tested with OK result. */
    FLSTST_RESULT_OK            =0x01,  

    /* The last Flash Test has been tested with NOT_OK result. */
    FLSTST_RESULT_NOT_OK        =0x02,  
}FlsTst_TestResultType;

typedef enum
{
    /* There is no result availabl. */
    FLSTST_NOT_TESTED       =0x00,

    /* The last Flash Test has been tested with OK result. */
    FLSTST_OK               =0x01,

    /* The last Flash Test has been tested with NOT_OK result. */
    FLSTST_NOT_OK           =0x02,
}FlsTst_TestResultFgndType;

typedef enum
{
    FLSTST_16BIT_CRC,
    FLSTST_32BIT_CRC,
    FLSTST_8BIT_CRC,
    FLSTST_CHECKSUM,
    FLSTST_DUPLICATED_MEMORY,
    FLSTST_ECC
}FlsTst_AlgorithmType;

typedef struct
{
    /* current value of FlsTstTestIntervalId,which is incremented by each new start of an test interval. */
    FlsTst_IntervalIDType   FlsTstIntervalID;

     /* Test Result in background flash test*/   
    FlsTst_TestResultType   result;
}FlsTst_TestResultBgndType;


/*The range is dependent on the number of Foreground
Flash blocks defined in the configuration structure. The
type shall be chosen depending on the MCU platform for
best performance.*/

typedef struct
{
    FlsTst_BlockIdType    ErrorBlockID;
    FlsTst_AlgorithmType  Algorithm;
    uint32                SignatureResult;
}FlsTst_ErrorDetailsType; 


typedef struct
{
    uint32  FgndSignature;                 
}FlsTst_TestSignatureFgndType; 


typedef struct
{
    uint32  FlsTstIntervalID;       /* current value of FlsTstTestIntervalId,which is incremented by each new start of an test interval. */
    uint32  BgndSignature;
}FlsTst_TestSignatureBgndType; 


typedef struct
{
    FlsTst_StateType                State;
    FlsTst_IntervalIDType           IntervalID;
    FlsTst_TestResultType           BgndResult;
    FlsTst_TestResultFgndType       FgndResult;
    FlsTst_ErrorDetailsType         ErrorInfo;
    FlsTst_UserNotificationPtrType  UserCallBack;
}FlsTst_ModuleTypes;
 

typedef struct FlsTst_BlockBgndType
{
    FlsTst_BlockIdType        BgndBlockIndex;
    FlsTst_AddressType        BlockBaseAddress;
    FlsTst_LengthType         BlcokLength;
    FlsTst_AddressType        SignatureAddress;
    FlsTst_AlgorithmType      TestAlgorithm; 
}FlsTst_BlockBgndType;


typedef struct FlsTst_BlockFgndType
{
    FlsTst_BlockIdType        BgndBlockIndex;
    FlsTst_AddressType        BlockBaseAddress;
    FlsTst_LengthType         BlcokLength;
    FlsTst_AddressType        SignatureAddress;
    FlsTst_AlgorithmType      TestAlgorithm; 
}FlsTst_BlockFgndType;


typedef struct FlsTst_ConfigType
{
    const FlsTst_BlockBgndType* FlsTst_BgndBlockPtr;
    const FlsTst_BlockFgndType* FlsTst_FgndBlockPtr;
    FlsTst_UserNotificationPtrType FlsTstUserCallBack;
}FlsTst_ConfigType;



typedef struct FlsTst_BlockInfoType
{
    FlsTst_BlockIdType        MemoryBlockID;
    FlsTst_AlgorithmType      TestAlgorithm;
    FlsTst_AddressType        MemBlcokStartAddr;
    FlsTst_LengthType         MemBlcokLength;
    FlsTst_SignatureType      SignatureStored;
    FlsTst_SignatureType      SignatueCalculated;
    FlsTst_TestResultType     TestResult;
}FlsTst_BlockInfoType;


typedef struct FlsTst_CurRunningTag
{
    FlsTst_BlockIdType      CurBlockID;
    uint8       FirstFlag;  /*First Calc CRC*/
    uint32      TestAddr;
    uint32      TestLength;
    uint32      CalcResult;
    FlsTst_AlgorithmType TestAlgorithm;
}FlsTst_CurRunningType;


#endif
