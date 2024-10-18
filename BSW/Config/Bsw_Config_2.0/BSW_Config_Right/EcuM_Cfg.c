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
**  FILENAME    : EcuM_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2024/03/26 15:24:53                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration constant variables for pre-compile            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11.                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM_Internal.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_16
#include "EcuM_MemMap.h"
CONST(ResourceType, ECUM_CONST)EcuM_OSResource = RES_SCHEDULER_CORE0;
#define ECUM_STOP_SEC_CONFIG_DATA_16
#include "EcuM_MemMap.h"
#define ECUM_START_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"
static CONST(uint8, ECUM_CONST) Ecum_WkSources_0[1]={0};
#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
/*Containers:EcuMSleepMode*/
CONST(EcuM_SleepModeCfgType, ECUM_CONST) EcuM_SleepModeCfgs[ECUM_MAX_SLEEP_MODE_NUM]=
{
    /*EcuMSleepMode*/
    {
        TRUE,    /*sleepSuspend*/
        0xff,        /*mcuMode(sleep)*/
        1,    /*numberOfWakeSource*/
        &Ecum_WkSources_0[0],/*wkSrcIdx*/
        EcuMWakeupSource_ByCAN/*wkMask*/
    }
};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
static CONST(NetworkHandleType, ECUM_CONST) EcuM_WkSource0RefComMCh =
{
    BodyExposedCAN_HCML
};

/*Containers:EcuMWakeupSource*/
CONST(EcuM_WakeupSourceCfgType, ECUM_CONST) EcuM_WkSourceCfgs[ECUM_MAX_WAKE_UP_SOURCE_NUM]=
{
    /*EcuMWakeupSource_ByCAN*/
    {
        0,    /*checkWkupTimeout*/
        3000,    /*validationTimeout*/
        EcuMWakeupSource_ByCAN,/*wkSource*/
        FALSE,    /*isPolling*/
        &EcuM_WkSource0RefComMCh,       /*comMChnl*/
        0u,    /*resetResasonNum*/
        NULL_PTR,    /*resetResasonPtr*/
    }
};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
#define ECUM_START_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"
CONST(Mcu_ModeType, ECUM_CONST)EcuM_NormalMcuModeCfg = ECUM_DAFULT_MCU_NORMAL_MODE;    /* EcuMNormalMcuModeRef*/
#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
/*Containers:EcuMFlexUserConfig*/
CONST(EcuM_UserCfgType, ECUM_CONST) EcuM_UserCfgs[ECUM_MAX_USER_NUM]=
{
    /*EcuMFlexUserConfig*/
    {
        TRUE,    /*goDownAllowed*/
        0     /*usrId*/
    }
};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"

