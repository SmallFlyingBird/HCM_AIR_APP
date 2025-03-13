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
**  FILENAME    : LinTp_Slave.c                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>   <DATE>     <AUTHOR>   <REVISION LOG> 
 * V1.0.0      20200729   HuRongbo   Initial version
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "LinIf_Cfg.h"
#include "LinTp_Slave.h"
#include "LinIf_Internal.h"
#include "string.h"
#include "LinIf_Slave.h"
#include "Dcm.h"
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
#define LINTP_START_SEC_CODE
#include "LinIf_MemMap.h"

static FUNC(void,LINIF_CODE) LinTp_SlaveSFRxHandle(
    NetworkHandleType tpCh,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr,
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) rxNSdu
);

static FUNC(void,LINIF_CODE) LinTp_SlaveFFRxHandle(
    NetworkHandleType tpCh,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr,
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) rxNSdu
);

static FUNC(void,LINIF_CODE) LinTp_SlaveCFRxHandle(
    NetworkHandleType tpCh,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
);

static FUNC(void,LINIF_CODE) LinTp_SlaveSFRxMainHandle(
    NetworkHandleType tpCh
);

static FUNC(void,LINIF_CODE) LinTp_SlaveFFRxMainHandle(
    NetworkHandleType tpCh
);

static FUNC(void,LINIF_CODE) LinTp_SlaveCFRxMainHandle(
    NetworkHandleType tpCh
);

static FUNC(void,LINIF_CODE) LinTp_SlaveAbortRxAndNotifyFailToUpper(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
);

static FUNC(void,LINIF_CODE) LinTp_SlaveSFTxHandle(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);

static FUNC(void,LINIF_CODE) LinTp_SlaveFFTxHandle(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);

static FUNC(void,LINIF_CODE) LinTp_SlaveCFTxHandle(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);

static FUNC(void,LINIF_CODE) LinTp_SlaveAbortTxAndNotifyFailToUpper(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
);

static FUNC(void,LINIF_CODE) LinTp_SlaveAbortTxRxAndNotifyFailToUpper(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
);

static FUNC(NetworkHandleType,LINIF_CODE) LinTp_SlaveGetLinTpChannel(
    NetworkHandleType ComMChannel
);

static FUNC(void,LINIF_CODE) LinTp_SlaveTimerHandle(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
);

static FUNC(void, LINIF_CODE) LinTp_SlaveResetRtData(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
);

#define LINTP_STOP_SEC_CODE
#include "LinIf_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define LINTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinIf_MemMap.h"

static VAR(LinTp_SlaveRuntimeType, LINIF_VAR) 
LinTp_SlaveRTData[LINTP_SLAVE_CHANNEL_NUMBER];

#define LINTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinIf_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define LINTP_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               LinTp slave node runtime data init
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinTp_SlaveInit (void)
{
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(0u);
    uint8 idx = LINTP_SLAVE_CHANNEL_NUMBER;

    /* Reset all of the channel */
    while (idx > 0u)
    {
        LinTp_SlaveResetRtData(tpSlaveRTPtr);

        tpSlaveRTPtr++;
        idx--;
    }
}

/******************************************************************************/
/*
 * Brief               TP message receive indication process in slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 *                     Lin_SduPtr: pointer to a buffer where the current SDU is
 *                                 stored.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinTp_SlaveMRFIndication(
    NetworkHandleType ch,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
)
{
    uint8 pciType = Lin_SduPtr[LINTP_PDU_OFS_PCI] & LINTP_PDU_PCI_MASK;
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) rxNSdu =
                        LinTp_GetRxNSduByNad(ch, Lin_SduPtr[LINTP_PDU_OFS_NAD]);
    NetworkHandleType commCh;
    NetworkHandleType tpCh;

    if ((Lin_SduPtr[0] == 0x7Eu)
    		&& (Lin_SduPtr[1] == 0x02u)
			&& (Lin_SduPtr[2] == 0x3Eu)
			&& (Lin_SduPtr[3] == 0x80u))
    {
    	Dcm_StartP3cTimer();
    }
    else if(NULL_PTR != rxNSdu)
    {
        commCh = rxNSdu->LinTpRxNSduChannelRef;
        tpCh = LinTp_SlaveGetLinTpChannel(commCh);

		switch (pciType)
		{
			/* SF */
			case LINTP_PDU_PCI_SF:
				LinTp_SlaveSFRxHandle(tpCh, Lin_SduPtr, rxNSdu);
				break;

			/* FF */
			case LINTP_PDU_PCI_FF:
				LinTp_SlaveFFRxHandle(tpCh, Lin_SduPtr, rxNSdu);
				break;

			/* CF */
			case LINTP_PDU_PCI_CF:
				LinTp_SlaveCFRxHandle(tpCh, Lin_SduPtr);
				break;

			/* Unknow PCI */
			default:
				/*@req <SWS_LinIf_00697>*/
				/* Unknown PCI type is received, ignore this LIN frame*/
				break;
		}
    }
}

/******************************************************************************/
/*
 * Brief               Get ComMChannel corresponding LinTp channel 
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ComMChannel: ComM Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              LinTp channel id
 */
/******************************************************************************/
FUNC(Std_ReturnType,LINIF_CODE) LinTp_SlaveTransmit(
    P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST) txNSdu,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) LinTpTxInfoPtr
)
{
    NetworkHandleType tpCh = 
                    LinTp_SlaveGetLinTpChannel(txNSdu->LinTpTxNSduChannelRef);
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    Std_ReturnType ret = E_NOT_OK;

    /*@req <SWS_LinIf_00321>*/
    if(LINTP_CHANNEL_IDLE == tpSlaveRTPtr->channelState)
    {
        tpSlaveRTPtr->TxNSduPtr = txNSdu;
        tpSlaveRTPtr->SduRemaining = LinTpTxInfoPtr->SduLength;
        tpSlaveRTPtr->channelState = LINTP_CHANNEL_BUSY;
        if(LinTpTxInfoPtr->SduLength <= LINTP_SF_DATA_LEN_MAX)
        {
            tpSlaveRTPtr->TxStage = LINTP_SLAVE_TX_SF;
        }
        else
        {
            tpSlaveRTPtr->TxStage = LINTP_SLAVE_TX_FF;
        }
        /*@req <SWS_LinIf_00800>*/
        /* Start N_As timer */
        tpSlaveRTPtr->NasTimer = txNSdu->LinTpNas / LINIF_GET_TIMEBASE();

        ret = E_OK;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               SRF process(Response transmit) in slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinTp_SlaveSRFIndication(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    NetworkHandleType tpCh = 
                    LinTp_SlaveGetLinTpChannel(LINIF_GET_COMM_NETWORK(ch));
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);

    /*@req <SWS_LinIf_00803>*/
    /* Stop N_Cs timer */
    tpSlaveRTPtr->NcsTimer = 0u;

    switch(tpSlaveRTPtr->TxStage)
    {
        case LINTP_SLAVE_TX_SF:
            LinTp_SlaveSFTxHandle(ch, PduPtr);
            break;

        case LINTP_SLAVE_TX_FF:
            LinTp_SlaveFFTxHandle(ch, PduPtr);
            break;

        case LINTP_SLAVE_TX_CF:
            LinTp_SlaveCFTxHandle(ch, PduPtr);
            break;

        default:
            /* No data need to transmit */
            PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
            break;
    }
}

/******************************************************************************/
/*
 * Brief               TP tx confirmation process in slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     isTpTxFinish: Indiacate if TP transmit finished
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinTp_SlaveTxConfirmation(
    NetworkHandleType ch,
    P2VAR(boolean, AUTOMATIC, LINIF_APPL_DATA) isTpTxFinish
)
{
    NetworkHandleType tpCh = 
                    LinTp_SlaveGetLinTpChannel(LINIF_GET_COMM_NETWORK(ch));
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);

    if(LINTP_SLAVE_TX_WAIT_CONFIRM == tpSlaveRTPtr->TxStage)
    {
        /* Transmit finish */
        /*@req <SWS_LinIf_00068>*/
        /* Notify upper */
        Dcm_TxConfirmation(tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduPduRef, E_OK);

        /* Abort transmit */
        LinTp_SlaveResetRtData(tpSlaveRTPtr);
        /* TP tx finished */
        *isTpTxFinish = TRUE;
    }
    else
    {
        /* Transmit ongoing */
        /*@req <SWS_LinIf_00800>*/
        /* Stop N_As timer */
        tpSlaveRTPtr->NasTimer = 0u;

        /*@req <SWS_LinIf_00803>*/
        /* Start N_Cs timer */
        tpSlaveRTPtr->NcsTimer = 
                    tpSlaveRTPtr->TxNSduPtr->LinTpNcs / LINIF_GET_TIMEBASE();
        /* TP tx not finished */
        *isTpTxFinish = FALSE;
    }
}

/******************************************************************************/
/*
 * Brief               LinTp slave main function
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinTp_SlaveMainFunction(
    NetworkHandleType ch
)
{
    NetworkHandleType tpCh = 
                    LinTp_SlaveGetLinTpChannel(LINIF_GET_COMM_NETWORK(ch));
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr;

    if(tpCh < LINTP_NUMBER_OF_CHANNELS)
    {
        tpSlaveRTPtr = LINTP_GET_SLAVE_RTDATA_PTR(tpCh);

        LinTp_SlaveTimerHandle(tpSlaveRTPtr);
        if(NULL_PTR != tpSlaveRTPtr->RxNSduPtr)
        {
            /* Rx processing */
            switch(tpSlaveRTPtr->RxStage)
            {
                case LINTP_SLAVE_RX_SF:
                    LinTp_SlaveSFRxMainHandle(tpCh);
                    break;

                case LINTP_SLAVE_RX_FF:
                    LinTp_SlaveFFRxMainHandle(tpCh);
                    break;

                case LINTP_SLAVE_RX_REQ_BUF:
                case LINTP_SLAVE_RX_CF:
                    LinTp_SlaveCFRxMainHandle(tpCh);
                    break;

                default:
                    /* Other Stage */
                    break;
            }
        }
    }
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               LinTp slave node receive Single frame handle
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveSFRxHandle(
    NetworkHandleType tpCh,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr,
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) rxNSdu
)
{
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    uint16 sduSize = (uint16)Lin_SduPtr[LINTP_PDU_OFS_PCI] & LINTP_PDU_PCI_DL_MASK;
    boolean ignoreFlag = FALSE;

    if(LINTP_CHANNEL_BUSY == tpSlaveRTPtr->channelState)
    {
        if(Lin_SduPtr[LINTP_PDU_OFS_NAD] != LINTP_FUNCTIONAL_REQ_NAD)
        {
            /* @req <SWS_LinIf_00651>,<SWS_LinIf_00653>,
               <SWS_LinIf_00808>,<SWS_LinIf_00797> */
            LinTp_SlaveAbortTxRxAndNotifyFailToUpper(tpSlaveRTPtr);
        }
        else
        {
            /* @req <SWS_LinIf_00807>,<SWS_LinIf_00798> */
            /* Physical request is ongoing, ignore the functional request.*/
            ignoreFlag = TRUE;
        }
    }

    /* @req <SWS_LinIf_00652> */
    /* Rx message error check*/
    if((FALSE == ignoreFlag) &&
       (sduSize > LINTP_LENGTH_SF_MIN) &&
       (sduSize <= LINTP_LENGTH_SF_MAX))
    {
        tpSlaveRTPtr->RxNSduPtr = rxNSdu;
        tpSlaveRTPtr->channelState = LINTP_CHANNEL_BUSY;
        tpSlaveRTPtr->SduSize = sduSize;
        tpSlaveRTPtr->SduRemaining = sduSize;
        tpSlaveRTPtr->SduCopyCnt = 0u;
        /* Data copy */
        (void)memcpy(tpSlaveRTPtr->SduBuf, Lin_SduPtr, LINTP_FRAME_LEN_MAX);
        tpSlaveRTPtr->LastFrameType = LINTP_FRAMETYPE_SF;
        tpSlaveRTPtr->ChCfgPtr = &LINTP_GET_CHANNEL_CONFIG(tpCh);
        tpSlaveRTPtr->RxStage = LINTP_SLAVE_RX_SF;
        tpSlaveRTPtr->SduSN = 0u;
    }
}

/******************************************************************************/
/*
 * Brief               LinTp slave node receive First Frame handle
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveFFRxHandle(
    NetworkHandleType tpCh,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr,
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) rxNSdu
)
{
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    uint16 sduSize;
    boolean ignoreFlag = FALSE;

    if(LINTP_CHANNEL_BUSY == tpSlaveRTPtr->channelState)
    {
        if(Lin_SduPtr[LINTP_PDU_OFS_NAD] != LINTP_FUNCTIONAL_REQ_NAD)
        {
            /* @req <SWS_LinIf_00651>,<SWS_LinIf_00653>,
               <SWS_LinIf_00808>,<SWS_LinIf_00797> */
            LinTp_SlaveAbortTxRxAndNotifyFailToUpper(tpSlaveRTPtr);
        }
        else
        {
            /* @req <SWS_LinIf_00807> */
            /* Physical request is ongoing, ignore the functional request.*/
            ignoreFlag = TRUE;
        }
    }

    /* @req <SWS_LinIf_00652> */
    /* Rx message error check*/
    sduSize = (uint16)Lin_SduPtr[LINTP_PDU_OFS_PCI] & LINTP_PDU_PCI_DL_MASK;
    sduSize = sduSize << 8u;
    sduSize = sduSize | Lin_SduPtr[LINTP_PDU_OFS_LEN];
    if((FALSE == ignoreFlag) &&
       (sduSize >= LINTP_LENGTH_FF_MIN))
    {
    	tpSlaveRTPtr->RxNSduPtr = rxNSdu;
        tpSlaveRTPtr->channelState = LINTP_CHANNEL_BUSY;
        tpSlaveRTPtr->SduSize = sduSize;
        tpSlaveRTPtr->SduRemaining = sduSize;
        tpSlaveRTPtr->SduCopyCnt = 0u;
        /* Data copy */
        (void)memcpy(tpSlaveRTPtr->SduBuf, Lin_SduPtr, LINTP_FRAME_LEN_MAX);
        tpSlaveRTPtr->LastFrameType = LINTP_FRAMETYPE_FF;
        tpSlaveRTPtr->ChCfgPtr = &LINTP_GET_CHANNEL_CONFIG(tpCh);
        tpSlaveRTPtr->RxStage = LINTP_SLAVE_RX_FF;
        tpSlaveRTPtr->SduSN = 0u;

        /* @req <SWS_LinIf_00652> */
        /* Start the N_Cr timer */
        tpSlaveRTPtr->NcrTimer =
                    tpSlaveRTPtr->RxNSduPtr->LinTpNcr / LINIF_GET_TIMEBASE();
    }
}

/******************************************************************************/
/*
 * Brief               LinTp slave node receive First Frame handle
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveCFRxHandle(
    NetworkHandleType tpCh,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
)
{
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);

    if(LINTP_CHANNEL_BUSY == tpSlaveRTPtr->channelState)
    {
        if(LINTP_SLAVE_RX_REQ_BUF == tpSlaveRTPtr->RxStage)
        {
            /* @req <SWS_LinIf_00795> */
            LinTp_SlaveAbortRxAndNotifyFailToUpper(tpSlaveRTPtr);
        }
        else if(LINTP_SLAVE_RX_WAIT_CF == tpSlaveRTPtr->RxStage)
        {
            /* Rx message error check*/
        	tpSlaveRTPtr->SduSN = (++tpSlaveRTPtr->SduSN) % 0x10u;
            if((Lin_SduPtr[LINTP_PDU_OFS_PCI] & LINTP_PDU_PCI_SN_MASK)
                                                        == tpSlaveRTPtr->SduSN)
            {
                /* Data copy */
                (void)memcpy(tpSlaveRTPtr->SduBuf, Lin_SduPtr,
                              LINTP_FRAME_LEN_MAX);
                tpSlaveRTPtr->LastFrameType = LINTP_FRAMETYPE_CF;
                tpSlaveRTPtr->RxStage = LINTP_SLAVE_RX_CF;

                /* @req <SWS_LinIf_00652> */
                /* Restart the N_Cr timer */
                tpSlaveRTPtr->NcrTimer =
                    (tpSlaveRTPtr->RxNSduPtr->LinTpNcr + 100) / LINIF_GET_TIMEBASE();
            }
            else
            {
                /* @req <SWS_LinIf_00079>,<SWS_LinIf_00081> */
                LinTp_SlaveAbortRxAndNotifyFailToUpper(tpSlaveRTPtr);
            }
        }
        else
        {
            /* Wrong stage,Abort the reception */
            LinTp_SlaveResetRtData(tpSlaveRTPtr);
        }
    }
    else
    {
        /* @req <SWS_LinIf_00696> */
        /* CF is received instead of a FF or a SF,Ignore this LIN frame. */
    	LinTp_SlaveAbortTxRxAndNotifyFailToUpper(tpSlaveRTPtr);
    }
}

/******************************************************************************/
/*
 * Brief               Single Frame receive process in mainfunction
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveSFRxMainHandle(
    NetworkHandleType tpCh
)
{
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    PduInfoType pduInfo;
    BufReq_ReturnType bufRslt;
    PduIdType upLayerPduId;

    /* Require Rx buffer from DCM */
    bufRslt = Dcm_ProvideRxBuffer(tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef,
                                  tpSlaveRTPtr->SduSize,
                                  &tpSlaveRTPtr->PduInfoPtr);

    /* Buffer Request Success */
    if ((BUFREQ_OK == bufRslt) &&
        (NULL_PTR != tpSlaveRTPtr->PduInfoPtr) &&
        (tpSlaveRTPtr->PduInfoPtr->SduLength >= tpSlaveRTPtr->SduSize))
    {
        /*@req <SWS_LinIf_00674> */
        /* Set destination buffer pointer and the number of bytes to be copied */
        pduInfo.SduDataPtr = &(tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_SF_DATA]);
        pduInfo.SduLength = tpSlaveRTPtr->SduSize;
        /* Copy data to DCM buffer */
        memcpy(tpSlaveRTPtr->PduInfoPtr->SduDataPtr, pduInfo.SduDataPtr, pduInfo.SduLength);

        upLayerPduId = tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef;
        /* @req <SWS_LinIf_00677>*/
        /* Abort the reception or receive finish,Reset runtime data */
        LinTp_SlaveResetRtData(tpSlaveRTPtr);
        /*@req <SWS_LinIf_00078>*/
        /* Notify upper with E_OK */
        Dcm_RxIndication(upLayerPduId, E_OK);
    }
    else
    {
        /* Notify upper */
        Dcm_RxIndication(tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef,
                               E_NOT_OK);

        /* @req <SWS_LinIf_00676>,<SWS_LinIf_00701>*/
        /* Abort the reception */
        LinTp_SlaveResetRtData(tpSlaveRTPtr);
    }
}

/******************************************************************************/
/*
 * Brief               First Frame receive process in mainfunction
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveFFRxMainHandle(
    NetworkHandleType tpCh
)
{
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    PduInfoType pduInfo;
    BufReq_ReturnType bufRslt;

    /* Require Rx buffer from DCM */
    bufRslt = Dcm_ProvideRxBuffer(tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef,
                                  tpSlaveRTPtr->SduSize,
                                  &tpSlaveRTPtr->PduInfoPtr);

    /* Buffer Request Success */
    if ((BUFREQ_OK == bufRslt) &&
        (NULL_PTR != tpSlaveRTPtr->PduInfoPtr) &&
        (tpSlaveRTPtr->PduInfoPtr->SduLength >= tpSlaveRTPtr->SduSize))
    {
        /*@req <SWS_LinIf_00674> */
        /* Set destination buffer pointer and the number of bytes to be copied */
        pduInfo.SduDataPtr = &(tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_FF_DATA]);
        pduInfo.SduLength = LINTP_FF_DATA_LEN;
        /* Copy data to DCM buffer */
        memcpy(tpSlaveRTPtr->PduInfoPtr->SduDataPtr, pduInfo.SduDataPtr, pduInfo.SduLength);
        tpSlaveRTPtr->SduRemaining -= pduInfo.SduLength;
        tpSlaveRTPtr->SduCopyCnt = pduInfo.SduLength;
        tpSlaveRTPtr->RxStage = LINTP_SLAVE_RX_WAIT_CF;
    }
    else
    {
        /* Notify upper */
        Dcm_RxIndication(tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef,
                               E_NOT_OK);

        /* @req <SWS_LinIf_00676>,<SWS_LinIf_00701>*/
        /* Abort the reception */
        LinTp_SlaveResetRtData(tpSlaveRTPtr);
    }
}

/******************************************************************************/
/*
 * Brief               Consecutive Frame receive process in mainfunction
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveCFRxMainHandle(
    NetworkHandleType tpCh
)
{
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                            LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    PduInfoType pduInfo;
    PduIdType upLayerPduId;

    /*Set destination buffer pointer and the number of bytes to be copied */
    pduInfo.SduDataPtr = &(tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_CF_DATA]);
    if(LINTP_SLAVE_RX_REQ_BUF == tpSlaveRTPtr->RxStage)
    {
        /*@req <SWS_LinIf_00793> */
        pduInfo.SduLength = 0u;
    }
    else
    {
        pduInfo.SduLength = LINIF_MIN(tpSlaveRTPtr->SduRemaining,
                                      LINTP_CF_DATA_LEN_MAX);
    }
    
    /* Copy data to DCM buffer */
    memcpy(&tpSlaveRTPtr->PduInfoPtr->SduDataPtr[tpSlaveRTPtr->SduCopyCnt],
           pduInfo.SduDataPtr, pduInfo.SduLength);
    tpSlaveRTPtr->SduRemaining -= pduInfo.SduLength;
    tpSlaveRTPtr->SduCopyCnt += pduInfo.SduLength;
    tpSlaveRTPtr->RxStage = LINTP_SLAVE_RX_WAIT_CF;

    if(0u == tpSlaveRTPtr->SduRemaining)
    {
        /* Reception finish */
        upLayerPduId = tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef;
        /* Abort the reception */
        LinTp_SlaveResetRtData(tpSlaveRTPtr);
        /*@req <SWS_LinIf_00078>*/
        /* Notify upper with E_OK */
        Dcm_RxIndication(upLayerPduId, E_OK);
    }
}

/******************************************************************************/
/*
 * Brief               Notify upper with E_NOT_OK and abort reception
 *                     (reset runtime data)
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveAbortRxAndNotifyFailToUpper(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
)
{
    if(NULL_PTR != tpSlaveRTPtr->RxNSduPtr)
    {
        /* Notify upper with E_NOT_OK */
        Dcm_RxIndication(tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef,
                               E_NOT_OK);
    }
    
    /* Abort the reception or transmit(SWS_LinIf_00797) */
    LinTp_SlaveResetRtData(tpSlaveRTPtr);
}

/******************************************************************************/
/*
 * Brief               Single frame transmit process.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpSlaveRTPtr: Lintp slave runtime data pointer
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinTp_SlaveSFTxHandle(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    NetworkHandleType tpCh =
                        LinTp_SlaveGetLinTpChannel(LINIF_GET_COMM_NETWORK(ch));
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                                LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    PduInfoType pduInfo;
    BufReq_ReturnType bufRslt;

    /*@req <SWS_LinIf_00671>,<SWS_LinIf_00705>*/
    /* Require Tx buffer from DCM */
    bufRslt = Dcm_ProvideTxBuffer(tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduPduRef,
                        &tpSlaveRTPtr->PduInfoPtr);

    if((BUFREQ_OK == bufRslt) &&
       (NULL_PTR != tpSlaveRTPtr->PduInfoPtr))
    {
        /* Set buffer value to padding data(0xFF) */
        (void)memset(tpSlaveRTPtr->SduBuf, LINTP_PADDING_VALUE, LINTP_FRAME_LEN_MAX);
        /* Set destination buffer pointer and he number of bytes to be copied */
        pduInfo.SduDataPtr = &(tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_SF_DATA]);
        pduInfo.SduLength = tpSlaveRTPtr->SduRemaining;
        /* Copy data from DCM */
        (void)memcpy(pduInfo.SduDataPtr, tpSlaveRTPtr->PduInfoPtr->SduDataPtr, pduInfo.SduLength);

        /* Set NAD and PCI */
        tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_NAD] = tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduNad;
        tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_PCI] =
                            LINTP_PDU_PCI_SF | (uint8)pduInfo.SduLength;
        tpSlaveRTPtr->TxStage = LINTP_SLAVE_TX_WAIT_CONFIRM;

        /* Copy data to Lin module provide buffer */
        (void)memcpy(PduPtr->SduPtr, tpSlaveRTPtr->SduBuf, LINTP_FRAME_LEN_MAX);
    }
    else
    {
        LinTp_SlaveAbortTxAndNotifyFailToUpper(tpSlaveRTPtr);
        PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
    }
}

/******************************************************************************/
/*
 * Brief               First frame transmit process.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpSlaveRTPtr: Lintp slave runtime data pointer
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveFFTxHandle(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    NetworkHandleType tpCh =
                        LinTp_SlaveGetLinTpChannel(LINIF_GET_COMM_NETWORK(ch));
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                                LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    PduInfoType pduInfo;
    BufReq_ReturnType bufRslt;

    /*@req <SWS_LinIf_00671>,<SWS_LinIf_00705>*/
    /* Copy data from DCM */
    bufRslt = Dcm_ProvideTxBuffer(tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduPduRef,
                        &tpSlaveRTPtr->PduInfoPtr);

    if((BUFREQ_OK == bufRslt) &&
       (NULL_PTR != tpSlaveRTPtr->PduInfoPtr))
    {
        /* Set buffer value to padding data(0xFF) */
        (void)memset(tpSlaveRTPtr->SduBuf, LINTP_PADDING_VALUE, LINTP_FRAME_LEN_MAX);
        /* Set destination buffer pointer and he number of bytes to be copied */
        pduInfo.SduDataPtr = &(tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_FF_DATA]);
        pduInfo.SduLength = LINTP_FF_DATA_LEN;
        /* Copy data from DCM */
        (void)memcpy(pduInfo.SduDataPtr, tpSlaveRTPtr->PduInfoPtr->SduDataPtr, pduInfo.SduLength);

        /* Set NAD and PCI */
        tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_NAD] = tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduNad;
        tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_PCI] =
            LINTP_PDU_PCI_FF | (uint8)(tpSlaveRTPtr->SduRemaining >> 8u);
        tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_LEN] =
            (uint8)(tpSlaveRTPtr->SduRemaining);

        tpSlaveRTPtr->SduRemaining -= pduInfo.SduLength;
        tpSlaveRTPtr->SduCopyCnt = pduInfo.SduLength;
        tpSlaveRTPtr->TxStage = LINTP_SLAVE_TX_CF;
        tpSlaveRTPtr->SduSN = 0u;

        /* Copy data to Lin module provide buffer */
        (void)memcpy(PduPtr->SduPtr, tpSlaveRTPtr->SduBuf, LINTP_FRAME_LEN_MAX);
    }
    else
    {
        LinTp_SlaveAbortTxAndNotifyFailToUpper(tpSlaveRTPtr);
        PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
    }
}

/******************************************************************************/
/*
 * Brief               Consecutive Frame transmit process.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpSlaveRTPtr: Lintp slave runtime data pointer
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveCFTxHandle(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    NetworkHandleType tpCh =
                        LinTp_SlaveGetLinTpChannel(LINIF_GET_COMM_NETWORK(ch));
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr =
                                                LINTP_GET_SLAVE_RTDATA_PTR(tpCh);
    PduInfoType pduInfo;

    if(NULL_PTR != tpSlaveRTPtr->TxNSduPtr)
    {

        /*@req <SWS_LinIf_00800>*/
        /* Start N_As timer */
        tpSlaveRTPtr->NasTimer =
                    tpSlaveRTPtr->TxNSduPtr->LinTpNas / LINIF_GET_TIMEBASE();


        /* Set buffer value to padding data(0xFF) */
        (void)memset(tpSlaveRTPtr->SduBuf, LINTP_PADDING_VALUE, LINTP_FRAME_LEN_MAX);
        /* Set destination buffer pointer and he number of bytes to be copied */
        pduInfo.SduDataPtr = &(tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_CF_DATA]);
        pduInfo.SduLength = LINIF_MIN(tpSlaveRTPtr->SduRemaining,
                                      LINTP_CF_DATA_LEN_MAX);
        /* Copy data from DCM */
        (void)memcpy(pduInfo.SduDataPtr,
                     &tpSlaveRTPtr->PduInfoPtr->SduDataPtr[tpSlaveRTPtr->SduCopyCnt],
                     pduInfo.SduLength);

        /* Set NAD and PCI */
        tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_NAD] = tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduNad;
        tpSlaveRTPtr->SduSN++;
        tpSlaveRTPtr->SduSN = tpSlaveRTPtr->SduSN % 16u;
        tpSlaveRTPtr->SduBuf[LINTP_PDU_OFS_PCI] =
                            LINTP_PDU_PCI_CF | tpSlaveRTPtr->SduSN;

        tpSlaveRTPtr->SduRemaining -= pduInfo.SduLength;
        tpSlaveRTPtr->SduCopyCnt += pduInfo.SduLength;
        if(0u == tpSlaveRTPtr->SduRemaining)
        {
            tpSlaveRTPtr->TxStage = LINTP_SLAVE_TX_WAIT_CONFIRM;
        }
        else
        {
            tpSlaveRTPtr->TxStage = LINTP_SLAVE_TX_CF;
        }

        /* Copy data to Lin module provide buffer */
        (void)memcpy(PduPtr->SduPtr, tpSlaveRTPtr->SduBuf, LINTP_FRAME_LEN_MAX);
    }
}

/******************************************************************************/
/*
 * Brief               Notify upper with E_NOT_OK and abort transmition
 *                     (reset runtime data)
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveAbortTxAndNotifyFailToUpper(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
)
{
    if(NULL_PTR != tpSlaveRTPtr->TxNSduPtr)
    {
        /* Notify upper with E_NOT_OK */
        Dcm_TxConfirmation(tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduPduRef,
                                 E_NOT_OK);
    }
    /* Abort transmit */
    LinTp_SlaveResetRtData(tpSlaveRTPtr);
}

/******************************************************************************/
/*
 * Brief               Notify upper with E_NOT_OK and abort transmition and receive
 *                     (reset runtime data)
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpCh: LinTp Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveAbortTxRxAndNotifyFailToUpper(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
)
{
    if(NULL_PTR != tpSlaveRTPtr->TxNSduPtr)
    {
        /* Notify upper with E_NOT_OK */
        Dcm_TxConfirmation(tpSlaveRTPtr->TxNSduPtr->LinTpTxNSduPduRef,
                                 E_NOT_OK);
    }
    if(NULL_PTR != tpSlaveRTPtr->RxNSduPtr)
    {
        /* Notify upper with E_NOT_OK */
        Dcm_RxIndication(tpSlaveRTPtr->RxNSduPtr->LinTpRxNSduPduRef,
                               E_NOT_OK);
    }

    /* Abort transmit */
    LinTp_SlaveResetRtData(tpSlaveRTPtr);
}

/******************************************************************************/
/*
 * Brief               Get ComMChannel corresponding LinTp channel 
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ComMChannel: ComM Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              LinTp channel id
 */
/******************************************************************************/
static FUNC(NetworkHandleType,LINIF_CODE) LinTp_SlaveGetLinTpChannel(
    NetworkHandleType ComMChannel
)
{
    P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_CONST) tpChCfgPtr = 
                                                &LINTP_GET_CHANNEL_CONFIG(0u);
    NetworkHandleType tpCh;

    for(tpCh = 0u; tpCh < LINTP_NUMBER_OF_CHANNELS; tpCh++)
    {
        if(ComMChannel == tpChCfgPtr->LinTpChannelRef)
        {
            break;
        }
        tpChCfgPtr++;
    }

    return tpCh;
}

/******************************************************************************/
/*
 * Brief               Get ComMChannel corresponding LinTp channel 
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      tpSlaveRTPtr: Pointer of LinTp slave runtime data
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              LinTp channel id
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinTp_SlaveTimerHandle(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
)
{
    if(tpSlaveRTPtr->NcrTimer > 0u)
    {
        tpSlaveRTPtr->NcrTimer--;
        if(0u == tpSlaveRTPtr->NcrTimer)
        {
            /*@req <SWS_LinIf_00806>*/
            /* N_Cr timeout occurrence */
            LinTp_SlaveAbortRxAndNotifyFailToUpper(tpSlaveRTPtr);
        }
    }

    if(tpSlaveRTPtr->NasTimer > 0u)
    {
        tpSlaveRTPtr->NasTimer--;
        if(0u == tpSlaveRTPtr->NasTimer)
        {
            /*@req <SWS_LinIf_00801>*/
            /* N_As timeout occurrence */
            LinTp_SlaveAbortTxAndNotifyFailToUpper(tpSlaveRTPtr);
        }
    }

    if(tpSlaveRTPtr->NcsTimer > 0u)
    {
        tpSlaveRTPtr->NcsTimer--;
        if(0u == tpSlaveRTPtr->NcsTimer)
        {
            /*@req <SWS_LinIf_00801>*/
            /* N_Cs timeout occurrence */
            LinTp_SlaveAbortTxAndNotifyFailToUpper(tpSlaveRTPtr);
        }
    }
}

/******************************************************************************/
/*
* Brief               Reset the channel runtime data to default value
* Sync/Async          Synchronous
* Reentrancy          Reentrant
* Param-Name[in]      tpSlaveRTPtr: Pointer of LinTp slave runtime data
* Param-Name[out]     None
* Param-Name[in/out]  None
* Return              None
*/
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinTp_SlaveResetRtData(
    P2VAR(LinTp_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) tpSlaveRTPtr
)
{
    tpSlaveRTPtr->ChCfgPtr = NULL_PTR;
    tpSlaveRTPtr->TxNSduPtr = NULL_PTR;
    tpSlaveRTPtr->RxNSduPtr = NULL_PTR;
    tpSlaveRTPtr->PduInfoPtr = NULL_PTR;
    tpSlaveRTPtr->SduSize = 0u;
    tpSlaveRTPtr->SduRemaining = 0u;
    tpSlaveRTPtr->SduCopyCnt = 0u;
    tpSlaveRTPtr->channelState = LINTP_CHANNEL_IDLE;
    tpSlaveRTPtr->NcrTimer = 0u;
    tpSlaveRTPtr->NasTimer = 0u;
    tpSlaveRTPtr->NcsTimer = 0u;
    tpSlaveRTPtr->LastFrameType = LINTP_FRAMETYPE_NONE;
    tpSlaveRTPtr->RxStage = LINTP_SLAVE_RX_IDLE;
    tpSlaveRTPtr->TxStage = LINTP_SLAVE_TX_IDLE;
    tpSlaveRTPtr->SduSN = 0u;
    tpSlaveRTPtr->RetryCopyCnt = 0u;
    (void)memset(tpSlaveRTPtr->SduBuf, 0, LINTP_FRAME_LEN_MAX);
}

#define LINTP_STOP_SEC_CODE
#include "LinIf_MemMap.h"
