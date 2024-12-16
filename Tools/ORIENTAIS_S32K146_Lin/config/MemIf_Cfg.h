/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : MemIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/12/12 15:33:33                                         **
**  Author      : Haibin.Shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : MemIf pre compile globle macro define                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11/4.2.2                **
**                                                                            **
*******************************************************************************/	
#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H

#include "MemIf_Types.h"

#define MEMIF_FEE_MAP_SUPPORT     STD_ON
#define MEMIF_EA_MAP_SUPPORT      STD_OFF

#define MEMIF_NUMBER_OF_DEVICES     (1u)

#define MEMIF_VERSION_INFO_API  (STD_OFF)
#define MEMIF_CFG_USE_FCT_API   (STD_OFF)

/* preprocessor switch for DET */
#define MEMIF_DEV_ERROR_DETECT (STD_OFF)

/*---- Include of the MemHwAs ---------------------------*/
#if (MEMIF_FEE_MAP_SUPPORT == STD_ON)
#include "Fee.h"
#endif

#if (MEMIF_EA_MAP_SUPPORT == STD_ON)
#include "Ea.h"
#endif

#define MEMIF_START_SEC_CONST_8BIT
#include "MemIf_MemMap.h"
extern CONST(uint8, MEMIF_CONST) MemIf_NumberOfDevices_u8;
#define MEMIF_STOP_SEC_CONST_8BIT
#include "MemIf_MemMap.h"

#define MEMIF_START_SEC_CONST_32BIT
#include "MemIf_MemMap.h"
extern CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES];
#define MEMIF_STOP_SEC_CONST_32BIT
#include "MemIf_MemMap.h"

/* mapping of MemIf_Read() */
#define MemIf_Read(DeviceIndex, BlockNumber, BlockOffset, DataBufferPtr, Length) \
					MemIf_MemHwaApis_at[DeviceIndex].Read( \
					(BlockNumber), \
					(BlockOffset), \
					(DataBufferPtr), \
					(Length))

/* mapping of MemIf_Write() */
#define MemIf_Write(DeviceIndex, BlockNumber, DataBufferPtr) \
					MemIf_MemHwaApis_at[DeviceIndex].Write((BlockNumber),(DataBufferPtr))
					
/* mapping of MemIf_EraseImmediateBlock() */					
#define MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
					MemIf_MemHwaApis_at[DeviceIndex].EraseImmediateBlock(BlockNumber)

/* mapping of MemIf_InvalidateBlock() */
#define MemIf_InvalidateBlock(DeviceIndex, BlockNumber) \
					MemIf_MemHwaApis_at[DeviceIndex].InvalidateBlock(BlockNumber)

/* mapping of MemIf_Cancel() */
#define MemIf_Cancel(DeviceIndex) MemIf_MemHwaApis_at[DeviceIndex].Cancel()

/* mapping of MemIf_GetJobResult() */
#define MemIf_GetJobResult(DeviceIndex) MemIf_MemHwaApis_at[DeviceIndex].GetJobResult()

#endif
