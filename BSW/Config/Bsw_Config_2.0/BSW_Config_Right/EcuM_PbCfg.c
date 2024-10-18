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
**  FILENAME    : EcuM_PbCfg.c                                                **
**                                                                            **
**  Created on  : 2024/03/26 17:50:58                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :  Configuration constant variables for pre-compile           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "Port.h"
#include "Can.h"
#include "Gpt.h"
#include "CanIf.h"
#include "CanSM.h"
#include "CanNm.h"
#include "Nm.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "CanTp.h"
#include "WdgM.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"
static CONST(EcuM_GenBSWPbCfgType, ECUM_VAR_NO_INIT) EcuM_GenMcalConfig =
{
    NULL_PTR, /*bswmPbCfg*/
    (const void *)&Port_Config,
    (const void *)&Can_Config,
    (const void *)&Gpt_Config,
    (const void *)&CanIf_InitCfgSet,
    (const void *)&CanSM_Config,
    (const void *)&CanNm_Config,
    (const void *)&PduR_PBConfigData,
    (const void *)&Com_PBConfigData,
    (const void *)&ComM_Config,
    (const void *)&CanTp_Config,
    (const void *)&WdgMConfigRoot[0],
};
CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config = /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    1,    /*EcuMConfigConsistencyHash*/
    OSDEFAULTAPPMODE,    /*EcuMDefaultAppMode*/
    ECUM_SHUTDOWN_TARGET_OFF,
    0,
    &EcuM_GenMcalConfig
};
#define ECUM_STOP_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

