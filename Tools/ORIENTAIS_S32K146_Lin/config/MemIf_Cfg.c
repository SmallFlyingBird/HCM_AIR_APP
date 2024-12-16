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
**  FILENAME    : MemIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/12/12 15:33:33                                         **
**  Author      : Haibin.Shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : MemIf pre compile globle macro define                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11/4.2.2                **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>   	 <AUTHOR>   	 <REVISION LOG>
 *  V1.0.0    20200819    Haibin.Shao     Initial version.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define MEMIF_CFG_C_AR_MAJOR_VERSION  (4U)
#define MEMIF_CFG_C_AR_MINOR_VERSION  (2U)
#define MEMIF_CFG_C_AR_PATCH_VERSION  (2U)
#define MEMIF_CFG_C_SW_MAJOR_VERSION  (1U)
#define MEMIF_CFG_C_SW_MINOR_VERSION  (0U)
#define MEMIF_CFG_C_SW_PATCH_VERSION  (3U)

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "MemIf.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (MEMIF_CFG_C_AR_MAJOR_VERSION != MEMIF_CFG_H_AR_MAJOR_VERSION)
#error "MemIf_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (MEMIF_CFG_C_AR_MINOR_VERSION != MEMIF_CFG_H_AR_MINOR_VERSION)
#error "MemIf_Cfg.c : Mismatch in Specification _MINOR Version"
#endif
#if (MEMIF_CFG_C_AR_PATCH_VERSION != MEMIF_CFG_H_AR_PATCH_VERSION)
#error "MemIf_Cfg.c : Mismatch in Specification PATCH Version"
#endif
#if (MEMIF_CFG_C_SW_MAJOR_VERSION != MEMIF_CFG_H_SW_MAJOR_VERSION)
#error "MemIf_Cfg.c : Mismatch in Software Major Version"
#endif
#if (MEMIF_CFG_C_SW_MINOR_VERSION != MEMIF_CFG_H_SW_MINOR_VERSION)
#error "MemIf_Cfg.c : Mismatch in Software MINOR Version"
#endif
#if (MEMIF_CFG_C_SW_PATCH_VERSION != MEMIF_CFG_H_SW_PATCH_VERSION)
#error "MemIf_Cfg.c : Mismatch in Software PATCH Version"
#endif

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define MEMIF_START_SEC_CONST_8BIT
#include "MemIf_MemMap.h"
CONST(uint8, MEMIF_CONST) MemIf_NumberOfDevices_u8 = MEMIF_NUMBER_OF_DEVICES;
#define MEMIF_STOP_SEC_CONST_8BIT
#include "MemIf_MemMap.h"

#define MEMIF_START_SEC_CONST_32BIT
#include "MemIf_MemMap.h"
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES] =
{
	/*<MEMIF_FEE_API/>*/
	{
		/* Fee */
		Fee_SetMode,
		Fee_Read,
		Fee_Write,
		Fee_EraseImmediateBlock,
		Fee_InvalidateBlock,
		Fee_Cancel,
		Fee_GetStatus,
		Fee_GetJobResult	
	}
};
#define MEMIF_STOP_SEC_CONST_32BIT
#include "MemIf_MemMap.h"
