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
**  FILENAME    : CanSM_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/09/25 14:02:24                                         ** 
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of CANSM                 **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "CanSM_Cfg.h"
#include "CanSM.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
#include "Dem.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"

static CONST(uint8, CANSM_CONST) CanSM_MN_0ControllerId[1] = {CANIF_CANDRV_0_BodyExposedCAN_HCML};/*CanSMControllerId*/

static CONST(CanSM_ControllerRefType, CANSM_CONST) CanSM_ControllerConfig[CANSM_NETWORK_NUM] =
{
    {
        0x1,
        &CanSM_MN_0ControllerId[0]
    },
};

static Dem_EventIdType CanSM_BodyExposedCAN_HCML_DemEvtBusOff = DemEventParameter_0xC03788;

static CONST(CanSM_DemEventParameterRefType, CANSM_CONST) CanSM_DemEventParameter [1] =
{
    {
        &CanSM_BodyExposedCAN_HCML_DemEvtBusOff,     /*CANSM_E_BUS_OFF */
        NULL_PTR,     /*CANSM_E_MODE_REQUEST_TIMEOUT */
    },
};

static CONST(CanSM_ManagerNetworkType, CANSM_CONST) CanSM_NetworkConfig [CANSM_NETWORK_NUM] =
{
    {
        0x1f,    /*CanSMBorCounterL1ToL2 */
        0xa,           /*CanSMBorTimeL1 */
        0xea60,           /*CanSMBorTimeL2 */
        0x3e8,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        BodyExposedCAN_HCML,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[0],
        &CanSM_DemEventParameter[0]
    },
};

CONST(CanSM_ConfigType, CANSM_CONST) CanSM_Config =  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
{
    0xa,    /*CanSMModeRequestRepetitionMax */
    0x64,    /*CanSMModeRequestRepetitionTime */
    &CanSM_NetworkConfig[0]
};

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
