/*============================================================================*/
/*  Copyright (C) 2009-2018, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <LinIf_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:--->
 *  
 *  @author     <>
 *  @date       <2018-01-24 16:19:31>
 */
/*============================================================================*/

    
/*============================================================================*/
/*      I N C L U D E S                                                       */
/*============================================================================*/
#include "LinIf_Types.h"
#if (LINIF_TP_SUPPORTED == STD_ON)
#include "LinTp_Types.h"
#endif
#include "LinSM_Cbk.h"
#include "PduR_LinIf.h"
#include "EcuM.h"
#include "LinIf_Cfg.h"
#include "Com_Cfg.h"

#define LINIF_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"
static VAR(boolean, LINIF_VAR) LinIf_TransmitPendingData[10] = {0};
#define LINIF_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_CONST_UNSPECIFIED
#include "LinIf_MemMap.h"

CONST(LinIf_SubstitutionFramesType, LINIF_CONST) LinIf_SubstitutionFramesData[] =
{
};

CONST(LinIf_FixedFrameSduType, LINIF_CONST) LinIf_FixedFrameSduData[] =
{
};


CONST(LinIf_TxPduType, LINIF_CONST) LinIf_TxPduData[] =
{

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_RLM_RS_BCM_01,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_RLM_RS_BCM_01   ,     /* LinIfTxPduRef */
        TRUE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_HcmlZcud_Lin2Fr01,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_HcmlZcud_Lin2Fr01   ,     /* LinIfTxPduRef */
        TRUE                       /* LinIfContainResponseErrorSignal */
    }
};

CONST(LinIf_RxPduType, LINIF_CONST) LinIf_RxPduData[] =
{
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BCM_RLM_01                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BCM_RLM_02                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_ZcudZcud_Lin2Fr01                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_ZcudZcud_Lin2Fr02                      /* LinIfRxPduRef */
    }
};

CONST(LinIf_PduDirectionType, LINIF_CONST) LinIf_PduDirectionData[] =
{
    /* index 0 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[0],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 1 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[1],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 2 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[0]             /* LinIfTxPdu */
    },
    /* index 3 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 4 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 5 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[1]             /* LinIfTxPdu */
    },
    /* index 6 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[2],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 7 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[3],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 8 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 9 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    }
};

CONST(LinIf_FrameType, LINIF_CONST) LinIf_FrameData[] =
{
  /* index 0 */
  {
      LINIF_ENHANCED,             /* LinIfChecksumType */
    0x4c,                       /* LinIfFrameId */
    0,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[0], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[0] /* LinIfIsTransmitPending */
  },
  /* index 1 */
  {
      LINIF_ENHANCED,             /* LinIfChecksumType */
    0xd,                       /* LinIfFrameId */
    1,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[1], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[1] /* LinIfIsTransmitPending */
  },
  /* index 2 */
  {
      LINIF_ENHANCED,             /* LinIfChecksumType */
    0xd8,                       /* LinIfFrameId */
    2,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[2], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[2] /* LinIfIsTransmitPending */
  },
  /* index 3 */
  {
      LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3c,                       /* LinIfFrameId */
    3,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_MRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[3], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[3] /* LinIfIsTransmitPending */
  },
  /* index 4 */
  {
      LINIF_CLASSIC,             /* LinIfChecksumType */
    0x7d,                       /* LinIfFrameId */
    4,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_SRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[4], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[4] /* LinIfIsTransmitPending */
  },
  /* index 5 */
  {
      LINIF_ENHANCED,             /* LinIfChecksumType */
    0xc1,                       /* LinIfFrameId */
    0,                            /* LinIfFrameIndex */
    7,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[5], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[5] /* LinIfIsTransmitPending */
  },
  /* index 6 */
  {
      LINIF_ENHANCED,             /* LinIfChecksumType */
    0x3,                       /* LinIfFrameId */
    1,                            /* LinIfFrameIndex */
    7,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[6], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[6] /* LinIfIsTransmitPending */
  },
  /* index 7 */
  {
      LINIF_ENHANCED,             /* LinIfChecksumType */
    0xc4,                       /* LinIfFrameId */
    2,                            /* LinIfFrameIndex */
    7,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[7], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[7] /* LinIfIsTransmitPending */
  },
  /* index 8 */
  {
      LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3c,                       /* LinIfFrameId */
    3,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_MRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[8], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[8] /* LinIfIsTransmitPending */
  },
  /* index 9 */
  {
      LINIF_CLASSIC,             /* LinIfChecksumType */
    0x7d,                       /* LinIfFrameId */
    4,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_SRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[9], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */   
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[9] /* LinIfIsTransmitPending */
  }
};

CONST(LinIf_EntryType, LINIF_CONST) LinIf_EntryData[] =
{
};

CONST(LinIf_ScheduleTableType, LINIF_CONST) LinIf_ScheduleTableData[] =
{
  /* NULL SCHEDULE */
  {
    LINIF_START_FROM_BEGINNING, /* LinIfResumePosition */
    LINIF_RUN_ONCE,             /* LinIfRunMode */
    LINIF_NULL_SCHEDULE_INDEX,  /* LinIfScheduleTableIndex */
    NULL_PTR,                   /* LinIfEntry */
    0                           /* LinIfNumOfEntry */
  },
};

CONST(LinIf_LinDriverChannelRef, LINIF_CONST) LinIf_LinDriverChannelRefData[] =
{
    {
        0,                   /* LinChannelIdRef */
        0,                   /* LinDriverId */
        0  /* WakeUpSource */
    },
    {
        0,                   /* LinChannelIdRef */
        0,                   /* LinDriverId */
        0  /* WakeUpSource */
    }
};

CONST(LinIf_TransceiverDrvConfigType, LINIF_CONST) LinIf_TransceiverDrvConfigData[] =
{
};

CONST(LinIf_MasterType, LINIF_CONST) LinIf_MasterData[] =
{
};

CONST(LinIf_NodeConfigurationIdentificationType, LINIF_CONST)
LinIf_NodeConfigurationIdentificationData[] =
{
    {
        70u,                            /* LinIfConfiguredNAD */
        25u,                            /* LinIfFunctionId */
        70u,                            /* LinIfInitialNAD */
        1000u,                          /* LinIfNasTimeout */
        332u,                            /* LinIfSupplierId */
        0u                            /* LinIfVariantId */
    },
    {
        42u,                            /* LinIfConfiguredNAD */
        0u,                            /* LinIfFunctionId */
        42u,                            /* LinIfInitialNAD */
        1000u,                          /* LinIfNasTimeout */
        0u,                            /* LinIfSupplierId */
        0u                            /* LinIfVariantId */
    }
   
};

CONST(LinIf_SlaveType, LINIF_CONST) LinIf_SlaveTypeData[] =
{
    {
        LINIF_VER_LIN22,                /* LinIfLinProtocolVersion */
        RLM_RSResponseErr_RLM_RS_BCM_01,                           /* LinIfResponseErrorSignal */
        TRUE,                       /* LinIfResponseErrorSignalConfigured */   
        &LinIf_NodeConfigurationIdentificationData[0] /* LinIf_NodeConfigurationIdentificationType */        
    },
    {
        LINIF_VER_LIN21,                /* LinIfLinProtocolVersion */
        ErrRespHCML_HcmlZcud_Lin2Fr01,                           /* LinIfResponseErrorSignal */
        TRUE,                       /* LinIfResponseErrorSignalConfigured */   
        &LinIf_NodeConfigurationIdentificationData[1] /* LinIf_NodeConfigurationIdentificationType */        
    }

};
CONST(LinIf_NodeType, LINIF_CONST) LinIf_NodeTypeData[] =
{
    {
    LINIF_SLAVE,                    /* LinIfNodeType */
    NULL_PTR,                       /* LinIfMaster */
    &LinIf_SlaveTypeData[0]         /* LinIfSlave */      
    },
    {
    LINIF_SLAVE,                    /* LinIfNodeType */
    NULL_PTR,                       /* LinIfMaster */
    &LinIf_SlaveTypeData[1]         /* LinIfSlave */      
    }
};

CONST(LinIf_ChannelType, LINIF_CONST) LinIf_ChannelData[LINIF_NUMBER_OF_CHANNELS] =
{
  {
    4000u,                                 /* LinIfBusIdleTimeoutPeriod */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepConfirmationUL */
    LinSM_GotoSleepConfirmation,        /* GotoSleepConfirmation */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepIndicationUL */
    LinSM_GotoSleepIndication,        /* GotoSleepIndication */
    0,                                /* LinIfMaxFrameCnt */
    FALSE,                               /* LinIfScheduleChangeNextTimeBase */
    LINIF_UL_LINSM,                     /* LinIfScheduleRequestConfirmationUL */ 
    NULL_PTR,  /* ScheduleRequestConfirmation */
    LINIF_STARTUP_NORMAL,               /* LinIfStartupState */
    LINIF_UL_LINSM,                     /* LinIfWakeupConfirmationUL */
    LinSM_WakeupConfirmation,           /* WakeupConfirmation */
    &LinIf_LinDriverChannelRefData[0],  /* LinIfChannelRef */
    0,                                  /* LinIfComMNetworkHandleRef */
    5,                                  /* LinIfNumOfFrame */
    0,                                  /* LinIfFrameIndexOffset */
    &LinIf_FrameData[0],                /* LinIfFrame */
    &LinIf_NodeTypeData[0],               /* LinIfNodeType */
    0,                                  /* LinIfNumOfSchedule */
    0,                                  /* LinIfScheduleIndexOffset */
    NULL_PTR,        /* LinIfScheduleTable */
    NULL_PTR                            /* LinIfTransceiverDrvConfig */
  },
  {
    4000u,                                 /* LinIfBusIdleTimeoutPeriod */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepConfirmationUL */
    LinSM_GotoSleepConfirmation,        /* GotoSleepConfirmation */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepIndicationUL */
    NULL_PTR,        /* GotoSleepIndication */
    0,                                /* LinIfMaxFrameCnt */
    FALSE,                               /* LinIfScheduleChangeNextTimeBase */
    LINIF_UL_LINSM,                     /* LinIfScheduleRequestConfirmationUL */ 
    NULL_PTR,  /* ScheduleRequestConfirmation */
    LINIF_STARTUP_SLEEP,               /* LinIfStartupState */
    LINIF_UL_LINSM,                     /* LinIfWakeupConfirmationUL */
    LinSM_WakeupConfirmation,           /* WakeupConfirmation */
    &LinIf_LinDriverChannelRefData[1],  /* LinIfChannelRef */
    1,                                  /* LinIfComMNetworkHandleRef */
    5,                                  /* LinIfNumOfFrame */
    5,                                  /* LinIfFrameIndexOffset */
    &LinIf_FrameData[5],                /* LinIfFrame */
    &LinIf_NodeTypeData[1],               /* LinIfNodeType */
    0,                                  /* LinIfNumOfSchedule */
    0,                                  /* LinIfScheduleIndexOffset */
    NULL_PTR,        /* LinIfScheduleTable */
    NULL_PTR                            /* LinIfTransceiverDrvConfig */
  }
};

CONST(LinIf_ConfigType, LINIF_CONST) LinIf_PCConfig =
{
  5,                                   /* LinIfTimeBase */
  0,                                    /* LinIfNumOfSubstitution */
  NULL_PTR,                             /* LinIfSubstitution */
  4,                                    /* LinIfNumOfTxPdu */
  LinIf_TxPduData,                      /* LinIfTxPdu */
  LinIf_FrameData,                      /* LinIfFrame */
  LinIf_ChannelData                     /* LinIfChannel */
};


CONST(LinTp_ChannelConfigType, LINIF_CONST) LinTp_ChannelConfigData[] =
{
    {
        0,     /* LinTpLinDriverChannelRef */
        TRUE,  /* LinTpDropNotRequestedNad */
        TRUE,  /* LinTpScheduleChangeDiag */
        0      /* LinTpChannelRef */
    },
    {
        0,     /* LinTpLinDriverChannelRef */
        TRUE,  /* LinTpDropNotRequestedNad */
        TRUE,  /* LinTpScheduleChangeDiag */
        1      /* LinTpChannelRef */
    }
};

CONST(LinTp_RxNSduType, LINIF_CONST) LinTp_RxNSduData[] =
{
    {
        0,                             /* LinTpLinDriverChannelRef */
        1000,                             /* LinTpNcr */
        LINTP_RXPDU_RLM_RS_MasterReq,      /* LinTpRxNSduId */
        0x46,                           /* LinTpRxNSduNad */
        0,                             /* LinTpRxNSduChannelRef */
        PDUR_SRCPDU_RLM_RS_MasterReq                             /* LinTpRxNSduPduRef */
    },
    {
        0,                             /* LinTpLinDriverChannelRef */
        1000,                             /* LinTpNcr */
        LINTP_RXPDU_RLM_RS_MasterReq_Fun,      /* LinTpRxNSduId */
        0x7e,                           /* LinTpRxNSduNad */
        0,                             /* LinTpRxNSduChannelRef */
        PDUR_SRCPDU_RLM_RS_MasterReq_Fun                             /* LinTpRxNSduPduRef */
    },
    {
        0,                             /* LinTpLinDriverChannelRef */
        1000,                             /* LinTpNcr */
        LINTP_RXPDU_HCML_MasterReq,      /* LinTpRxNSduId */
        0x2a,                           /* LinTpRxNSduNad */
        1,                             /* LinTpRxNSduChannelRef */
        PDUR_SRCPDU_HCML_MasterReq                             /* LinTpRxNSduPduRef */
    }
};

CONST(LinTp_TxNSduType, LINIF_CONST) LinTp_TxNSduData[] =
{
    {
        0,                             /* LinTpLinDriverChannelRef */
        10,                            /* LinTpMaxBufReq */
        500,                           /* LinTpNas */
        300,                             /* LinTpNcs */
        LINTP_TXPDU_RLM_RS_SlaveResp,      /* LinTpTxNSduId */
        0x46,                           /* LinTpTxNSduNad */
        0,                             /* LinTpTxNSduChannelRef */
        PDUR_DESTPDU_RLM_RS_SlaveResp                             /* LinTpTxNSduPduRef */
    },
    {
        0,                             /* LinTpLinDriverChannelRef */
        10,                            /* LinTpMaxBufReq */
        500,                           /* LinTpNas */
        0,                             /* LinTpNcs */
        LINTP_TXPDU_HCML_SlaveResp,      /* LinTpTxNSduId */
        0x2a,                           /* LinTpTxNSduNad */
        1,                             /* LinTpTxNSduChannelRef */
        PDUR_DESTPDU_HCML_SlaveResp                             /* LinTpTxNSduPduRef */
    }
};

CONST(LinTp_ConfigType, LINIF_CONST) LinTp_PCConfig =
{
    5,                          /* LinTpMaxNumberOfRespPendingFrames */
    0,                          /* LinTpMaxRxNSduCnt */
    3,                          /* LinTpNumOfRxNSdu */
    0,                          /* LinTpMaxTxNSduCnt */
    2,                          /* LinTpNumOfTxNSdu */
    2000,                       /* LinTpP2Max */
    500,                        /* LinTpP2Timing */
    LinTp_ChannelConfigData,    /* LinTpChannelConfig */
    LinTp_RxNSduData,           /* LinTpRxNSdu */
    LinTp_TxNSduData            /* LinTpTxNSdu */
};
CONST(Lin_DriverApiType, LINIF_CONST) Lin_DriverApi[] =
{
    {
        NULL_PTR,            /* LinGetStatus */
        NULL_PTR,             /* LinGoToSleep */
        Lin_GoToSleepInternal,    /* LinGoToSleepInternal */
        NULL_PTR,               /* LinSendFrame */
        Lin_Wakeup,               /* LinWakeup */
        Lin_WakeupInternal,       /* LinWakeupInternal */
        Lin_CheckWakeup     /* LinCheckWakeup */
    },
    {
        NULL_PTR,            /* LinGetStatus */
        NULL_PTR,             /* LinGoToSleep */
        Lin_GoToSleepInternal,    /* LinGoToSleepInternal */
        NULL_PTR,               /* LinSendFrame */
        Lin_Wakeup,               /* LinWakeup */
        Lin_WakeupInternal,       /* LinWakeupInternal */
        Lin_CheckWakeup     /* LinCheckWakeup */
    }   
};

#define LINIF_STOP_SEC_CONST_UNSPECIFIED
#include "LinIf_MemMap.h"
