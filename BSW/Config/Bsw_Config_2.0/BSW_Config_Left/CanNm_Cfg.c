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
**  FILENAME    : CanNm_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/10/09 16:59:32                                         **
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration data for CanNm                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"
#include "PduR_Cfg.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
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
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"

static CONST(CanNm_RxPduType, CANNM_CONST) CanNm_RxPduData[CANNM_RX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* RxPduId */
        },
};

static CONST(CanNm_TxPduType, CANNM_CONST)  CanNm_TxPduData[CANNM_TX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* TxConfirmationPduId*/
            CANIF_TXPDU_HcmlBodyExposedCanNmPdu1,      /* CanNmTxPduRef */
            FALSE        /*TxPduIsTriggerTrans*/
        },
};

static CONST(CanNm_UserDataTxPduType, CANNM_CONST) CanNM_UserDataTxPdu[CANNM_USER_DATA_TX_PDU_MAX]=
{
        {
             0u,                 /* CanNmTxUserDataPduId*/
             PDUR_DESTPDU_CanNmUserDataTxPdu_BodyExposedCAN_HCML,       /* CanNmTxUserDataPduRef */
        },
};

static CONST(CanNm_ChannelConfigType, CANNM_CONST)
CanNm_ChannelCfgData[CANNM_NUMBER_OF_CHANNEL]=
{
    {
        TRUE,    /* CanNmActiveWakeupBitEnabled */
        TRUE,    /* CanNmAllNmMessagesKeepAwake */
        4u,        /* CanNmImmediateNmCycleTime */
        20u,        /* CanNmImmediateNmTransmissions */
        20u,        /* CanNmMsgCycleOffset */
        200u,        /* CanNmMsgCycleTime */
        100u,        /* CanNmMsgTimeoutTime */
        TRUE, /* CanNmNodeDetectionEnabled */
        TRUE,/* CanNmNodeIdEnabled */
        49u,        /* CanNmNodeId */
        CANNM_PDU_BYTE_1,    /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,    /* CanNmPduNidPosition */
        TRUE,            /* CanNmPnEnabled */
        TRUE,            /* CanNmPnEraCalcEnabled */
        TRUE,            /* CanNmPnHandleMultipleNetworkRequests */
        200u,                    /* CanNmRepeatMessageTime */
        TRUE,                /* CanNmRetryFirstMessageRequest */
        FALSE,    /* CanNmStayInPbsEnabled */
        600u,                    /* CanNmTimeoutTime */
        800u,                    /* CanNmWaitBusSleepTime */
        BodyExposedCAN_HCML,    /* CanNmComMNetworkHandleRef */
        PDUR_SRCPDU_CanNmEraRxPdu_BodyExposedCAN_HCML,    /* CanNmPnEraRxNSduRef */
        &CanNm_RxPduData[0],    /* CanNmRxPdu */
        1u,              /* RxPduNum */
        &CanNm_TxPduData[0],   /* CanNmTxPdu */
        6u,  /* CanNm_UserDataLen */
        2u,  /* CanNm_UserDataOffsetPos */
        &CanNM_UserDataTxPdu[0],   /* CanNmUserDataTxPdu */
    },

};

static CONST(CanNm_PnFilterMaskByteType, CANNM_CONST) CanNm_PnFilterMaskByteData[6]=
{
    {
        0x0u,
        0x47
    },
    {
        0x1u,
        0x21
    },
    {
        0x2u,
        0xc0
    },
    {
        0x3u,
        0x0
    },
    {
        0x4u,
        0x0
    },
    {
        0x5u,
        0x0
    },
};
static CONST(CanNm_PnInfoType, CANNM_CONST) CanNm_PnInfoData =
{
    6u,        /* CanNmPnInfoLength */
    2u,        /* CanNmPnInfoOffset */
    6u,                          /* CanNmPnFilterMaskByteNum */
    CanNm_PnFilterMaskByteData  /* CanNmPnFilterMaskByte */
};

CONST(CanNm_ConfigType, CANNM_CONST) CanNm_Config =  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
{
    0x5u,    /* CanNmMainFunctionPeriod */
    390u,    /* CanNmPnResetTime */
    PDUR_SRCPDU_CanNmEiraRxPdu,    /*CanNmPnEiraRxNSduRef*/
    CanNm_ChannelCfgData,       /* CanNmChannelConfig */
    &CanNm_PnInfoData           /* CanNmPnInfo */
};
#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

