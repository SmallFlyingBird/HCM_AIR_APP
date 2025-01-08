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
#include "LinTp_Types.h"
#include "Lin.h"
#include "LinIf_Cfg.h"
#include "HcmPlatform.h"
#include "LinSM.h"
#define LINIF_START_SEC_CONST_UNSPECIFIED
#include "LinIf_MemMap.h"

CONST(LinIf_PduDirectionType, LINIF_CONST) LinIf_PduDirectionData[] =
{
    /* index 0,HCM DTC */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */
    },
    /* index 1,CONTROL */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */
    },
	/* index 2,CONTROL */
	{
		LINIF_TX_PDU,		 /* LinIfPduDirectionId */
	},
	/* index 3,MRF */
	{
		LINIF_RX_PDU,		 /* LinIfPduDirectionId */
	},
	/* index 4,SRF */
	{
		LINIF_TX_PDU,		 /* LinIfPduDirectionId */
	},
};

CONST(LinIf_FrameType, LINIF_CONST) LinIf_FrameData[] =
{	
	/* HCM DTC */
    {
	  LINIF_CLASSIC,			  /* LinIfChecksumType */
	  0x80, 					  /* LinIfFrameId */
	  8,						  /* LinIfLength */
	  LINIF_UNCONDITIONAL,		  /* LinIfFrameType */
	  &LinIf_PduDirectionData[0]  /* LinIfPduDirection */
	},
	/* CONTROL */
    {
	  LINIF_CLASSIC,			  /* LinIfChecksumType */
	  0xC1, 					  /* LinIfFrameId */
	  8,						  /* LinIfLength */
	  LINIF_UNCONDITIONAL,		  /* LinIfFrameType */
	  &LinIf_PduDirectionData[1]  /* LinIfPduDirection */
	},
	/* HCM STATUS */
    {
	  LINIF_CLASSIC,			  /* LinIfChecksumType */
	  0x03, 					  /* LinIfFrameId */
	  8,						  /* LinIfLength */
	  LINIF_UNCONDITIONAL,		  /* LinIfFrameType */
	  &LinIf_PduDirectionData[2]  /* LinIfPduDirection */
	},
    /* MRF */
    {
      LINIF_CLASSIC,              /* LinIfChecksumType */
      0x3c,                       /* LinIfFrameId */
      8,                          /* LinIfLength */
      LINIF_MRF,                  /* LinIfFrameType */
      &LinIf_PduDirectionData[3]  /* LinIfPduDirection */
    },
    /* SRF */
    {
      LINIF_CLASSIC,              /* LinIfChecksumType */
      0x7d,                       /* LinIfFrameId */
      8,                          /* LinIfLength */
      LINIF_SRF,                  /* LinIfFrameType */
      &LinIf_PduDirectionData[4]  /* LinIfPduDirection */
    },
};

CONST(LinIf_LinDriverChannelRef, LINIF_CONST) LinIf_LinDriverChannelRefData[] =
{
    {
        0, /* LinChannelIdRef */
        0, /* LinDriverId */
        0  /* WakeUpSource */
    }
};

CONST(LinIf_NodeType, LINIF_CONST) LinIf_NodeTypeData[] =
{
    {
        LINIF_SLAVE,                    /* LinIfNodeType */
    }
};

CONST(LinIf_ChannelType, LINIF_CONST) LinIf_ChannelData[LINIF_NUMBER_OF_CHANNELS] =
{
  {
    4000u,                              /* LinIfBusIdleTimeoutPeriod */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepConfirmationUL */
    LinSM_GotoSleepConfirmation,        /* GotoSleepConfirmation */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepIndicationUL */
    LinSM_GotoSleepIndication,          /* GotoSleepIndication */
    LINIF_STARTUP_NORMAL,               /* LinIfStartupState */
    LINIF_UL_LINSM,                     /* LinIfWakeupConfirmationUL */
    LinSM_WakeupConfirmation,         	/* WakeupConfirmation */
    &LinIf_LinDriverChannelRefData[0],  /* LinIfChannelRef */
    0,                                  /* LinIfComMNetworkHandleRef */
    2,                                  /* LinIfNumOfFrame */
    0,                                  /* LinIfFrameIndexOffset */
    &LinIf_FrameData[0],                /* LinIfFrame */
    &LinIf_NodeTypeData[0]              /* LinIfNodeType */
  }
};

CONST(LinIf_ConfigType, LINIF_CONST) LinIf_PCConfig =
{
    10u,                                  /* LinIfTimeBase */
    &LinIf_FrameData[0],                  /* LinIfFrame */
    LinIf_ChannelData                     /* LinIfChannel */
};

CONST(LinTp_ChannelConfigType, LINIF_CONST) LinTp_ChannelConfigData[] =
{
    {
        0,     /* LinTpLinDriverChannelRef */
        TRUE,  /* LinTpDropNotRequestedNad */
        TRUE,  /* LinTpScheduleChangeDiag */
        0      /* LinTpChannelRef */
    }
};

CONST(LinTp_RxNSduType, LINIF_CONST) LinTp_RxNSduData_L[] =
{
    {
        0,                             /* LinTpLinDriverChannelRef */
        LINTP_TIME_NCR,                /* LinTpNcr */
        LINTP_RXPDU_Lin_S_Diag_Phy_Rx, /* LinTpRxNSduId */
        LINTP_PHY_NAD_L,                 /* LinTpRxNSduNad */
        0,                             /* LinTpRxNSduChannelRef */
        DCM_RX_PHY_PDU_ID              /* LinTpRxNSduPduRef */
    },
    {
        0,                             /* LinTpLinDriverChannelRef */
        LINTP_TIME_NCR,                /* LinTpNcr */
        LINTP_RXPDU_Lin_S_Diag_Fun_Rx, /* LinTpRxNSduId */
        LINTP_FUN_NAD,                 /* LinTpRxNSduNad */
        0,                             /* LinTpRxNSduChannelRef */
        DCM_RX_FUNC_PDU_ID             /* LinTpRxNSduPduRef */
    }
};

CONST(LinTp_TxNSduType, LINIF_CONST) LinTp_TxNSduData_L[] =
{
    {
        0,                             /* LinTpLinDriverChannelRef */
        10,                            /* LinTpMaxBufReq */
        LINTP_TIME_NAS,                /* LinTpNas */
        LINTP_TIME_NCS,                /* LinTpNcs */
        LINTP_TXPDU_Lin_S_Diag_Tx,     /* LinTpTxNSduId */
        LINTP_PHY_NAD_L,               /* LinTpTxNSduNad */
        0,                             /* LinTpTxNSduChannelRef */
        DCM_TX_PDU_ID                  /* LinTpTxNSduPduRef */
    }
};


CONST(LinTp_RxNSduType, LINIF_CONST) LinTp_RxNSduData_R[] =
{
    {
        0,                             /* LinTpLinDriverChannelRef */
        LINTP_TIME_NCR,                /* LinTpNcr */
        LINTP_RXPDU_Lin_S_Diag_Phy_Rx, /* LinTpRxNSduId */
        LINTP_PHY_NAD_R,               /* LinTpRxNSduNad */
        0,                             /* LinTpRxNSduChannelRef */
        DCM_RX_PHY_PDU_ID              /* LinTpRxNSduPduRef */
    },
    {
        0,                             /* LinTpLinDriverChannelRef */
        LINTP_TIME_NCR,                /* LinTpNcr */
        LINTP_RXPDU_Lin_S_Diag_Fun_Rx, /* LinTpRxNSduId */
        LINTP_FUN_NAD,                 /* LinTpRxNSduNad */
        0,                             /* LinTpRxNSduChannelRef */
        DCM_RX_FUNC_PDU_ID             /* LinTpRxNSduPduRef */
    }
};

CONST(LinTp_TxNSduType, LINIF_CONST) LinTp_TxNSduData_R[] =
{
    {
        0,                             /* LinTpLinDriverChannelRef */
        10,                            /* LinTpMaxBufReq */
        LINTP_TIME_NAS,                /* LinTpNas */
        LINTP_TIME_NCS,                /* LinTpNcs */
        LINTP_TXPDU_Lin_S_Diag_Tx,     /* LinTpTxNSduId */
        LINTP_PHY_NAD_R,                 /* LinTpTxNSduNad */
        0,                             /* LinTpTxNSduChannelRef */
        DCM_TX_PDU_ID                  /* LinTpTxNSduPduRef */
    }
};


// CONST(LinTp_RxNSduType, LINIF_CONST) LinTp_RxNSduData_M[] =
// {
//     {
//         0,                             /* LinTpLinDriverChannelRef */
//         LINTP_TIME_NCR,                /* LinTpNcr */
//         LINTP_RXPDU_Lin_S_Diag_Phy_Rx, /* LinTpRxNSduId */
//         LINTP_PHY_NAD_M,                 /* LinTpRxNSduNad */
//         0,                             /* LinTpRxNSduChannelRef */
//         DCM_RX_PHY_PDU_ID              /* LinTpRxNSduPduRef */
//     },
//     {
//         0,                             /* LinTpLinDriverChannelRef */
//         LINTP_TIME_NCR,                /* LinTpNcr */
//         LINTP_RXPDU_Lin_S_Diag_Fun_Rx, /* LinTpRxNSduId */
//         LINTP_FUN_NAD,                 /* LinTpRxNSduNad */
//         0,                             /* LinTpRxNSduChannelRef */
//         DCM_RX_FUNC_PDU_ID             /* LinTpRxNSduPduRef */
//     }
// };

// CONST(LinTp_TxNSduType, LINIF_CONST) LinTp_TxNSduData_M[] =
// {
//     {
//         0,                             /* LinTpLinDriverChannelRef */
//         10,                            /* LinTpMaxBufReq */
//         LINTP_TIME_NAS,                /* LinTpNas */
//         LINTP_TIME_NCS,                /* LinTpNcs */
//         LINTP_TXPDU_Lin_S_Diag_Tx,     /* LinTpTxNSduId */
//         LINTP_PHY_NAD_M,                 /* LinTpTxNSduNad */
//         0,                             /* LinTpTxNSduChannelRef */
//         DCM_TX_PDU_ID                  /* LinTpTxNSduPduRef */
//     }
// };



CONST(LinTp_ConfigType, LINIF_CONST) LinTp_PCConfig_L =
{
    5,                          /* LinTpMaxNumberOfRespPendingFrames */
    0,                          /* LinTpMaxRxNSduCnt */
    2,                          /* LinTpNumOfRxNSdu */
    0,                          /* LinTpMaxTxNSduCnt */
    1,                          /* LinTpNumOfTxNSdu */
    LINTP_TIME_P2MAX,           /* LinTpP2Max */
    LINTP_TIME_P2,              /* LinTpP2Timing */
    LinTp_ChannelConfigData,    /* LinTpChannelConfig */
    LinTp_RxNSduData_L,           /* LinTpRxNSdu */
    LinTp_TxNSduData_L            /* LinTpTxNSdu */
};

CONST(LinTp_ConfigType, LINIF_CONST) LinTp_PCConfig_R =
{
    5,                          /* LinTpMaxNumberOfRespPendingFrames */
    0,                          /* LinTpMaxRxNSduCnt */
    2,                          /* LinTpNumOfRxNSdu */
    0,                          /* LinTpMaxTxNSduCnt */
    1,                          /* LinTpNumOfTxNSdu */
    LINTP_TIME_P2MAX,           /* LinTpP2Max */
    LINTP_TIME_P2,              /* LinTpP2Timing */
    LinTp_ChannelConfigData,    /* LinTpChannelConfig */
    LinTp_RxNSduData_R,           /* LinTpRxNSdu */
    LinTp_TxNSduData_R            /* LinTpTxNSdu */
};

CONST(Lin_DriverApiType, LINIF_CONST) Lin_DriverApi[] =
{
    {
        NULL_PTR,               /* LinGetStatus */
        NULL_PTR,               /* LinGoToSleep */
        Lin_GoToSleepInternal,  /* LinGoToSleepInternal */
        NULL_PTR,               /* LinSendFrame */
        Lin_Wakeup,             /* LinWakeup */
        Lin_WakeupInternal,     /* LinWakeupInternal */
        Lin_CheckWakeup         /* LinCheckWakeup */
    } 
};

#define LINIF_STOP_SEC_CONST_UNSPECIFIED
#include "LinIf_MemMap.h"
