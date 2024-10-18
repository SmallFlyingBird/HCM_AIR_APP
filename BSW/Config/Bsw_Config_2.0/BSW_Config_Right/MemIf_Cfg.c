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
**  FILENAME    : MemIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/03/25 10:03:40                                         **
**  Author      :                                                             **
**  Vendor      : isoft                                                       **
**  DESCRIPTION : MemIf pre compile globle macro define                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "MemIf_Cfg.h"
#include "Fee.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define MEMIF_START_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"
/* PRQA S 1531++ */ /* MISRA Rule 8.7 */
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 1531-- */ /* MISRA Rule 8.7 */
{

    {
        /* Device SetMode Operation API */
        Fee_SetMode,
        /* Device Read operation API */
        Fee_Read,
        /* Device Write operation API */
        Fee_Write,
        /* Device Erase Immediate operation API */
        Fee_EraseImmediateBlock,
        /* Device Invalidate operation API */
        Fee_InvalidateBlock,
        /* Device Cancel operation API */
        Fee_Cancel,
        /* Device GetStatus operation API */
        Fee_GetStatus,
        /* Device GetJobResult operation API */
        Fee_GetJobResult
    },
};

#define MEMIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"
