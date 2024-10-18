/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Fee_Types.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Type definitions of FEE                                     **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef FEE_TYPES_H
#define FEE_TYPES_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls.h"
/*******************************************************************************
**                      STRUCTURES AND OTHER TYPEDEFS                         **
*******************************************************************************/
#if (0)
typedef struct
{
    P2FUNC(Std_ReturnType, FEE_APPL_CODE, Fls_WriteApi)
    (Fls_AddressType TargetAddress, const uint8* SourceAddressPtr, Fls_LengthType Length);
    P2FUNC(Std_ReturnType, FEE_APPL_CODE, Fls_ReadApi)
    (Fls_AddressType SourceAddress, uint8* TargetAddressPtr, Fls_LengthType Length);
    P2FUNC(Std_ReturnType, FEE_APPL_CODE, Fls_EraseApi)(Fls_AddressType TargetAddress, Fls_LengthType Length);
    P2FUNC(void, FEE_APPL_CODE, Fls_CancelApi)(void);
    P2FUNC(Std_ReturnType, FEE_APPL_CODE, Fls_CompareApi)
    (Fls_AddressType SourceAddress, const uint8* TargetAddressPtr, Fls_LengthType Length);
    P2FUNC(MemIf_JobResultType, FEE_APPL_CODE, Fls_GetJobResultApi)(void);
    P2FUNC(MemIf_StatusType, FEE_APPL_CODE, Fls_GetStatusApi)(void);
    P2FUNC(void, FEE_APPL_CODE, Fls_SetModeApi)(MemIf_ModeType Mode);
    P2FUNC(Std_ReturnType, FEE_APPL_CODE, Fls_BlankCheckApi)(Fls_AddressType TargetAddress, Fls_LengthType Length);
} Fee_FlashDrvApiType;
#endif

typedef struct
{
    uint16 FeeBlockNumber;    /*Block identifier (handle)*/
    uint16 FeeBlockSize;      /*Size of a logical block in bytes*/
    boolean FeeImmediateData; /*Marker for high priority data*/
#if (0)
    uint8 FeeDeviceIndex;     /*Reference to the device this block is stored in*/
#endif
} Fee_BlockConfigType;

typedef struct
{
    uint16 FeeBlockSum;                                                  /*Block identifier (handle)*/
    P2CONST(Fee_BlockConfigType, AUTOMATIC, FEE_APPL_CONST) FeeBlockRef; /*Every block configuration*/
#if (0)
    P2CONST(Fee_FlashDrvApiType, AUTOMATIC, FEE_APPL_CONST) FeeFlashDrvApiRef;
#endif
} Fee_ConfigType;

typedef struct
{
    Fls_AddressType FeeBankStartAddr;
    Fls_LengthType FeeBankLength;
} Fee_BankConfigType;

#endif /* FEE_TYPES_H */
