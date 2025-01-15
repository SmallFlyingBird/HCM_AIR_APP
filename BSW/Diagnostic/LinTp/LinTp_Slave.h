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
**  FILENAME    : LinTp_Slave.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef LINTP_SLAVE_H
#define LINTP_SLAVE_H

#include "LinIf_Cfg.h"
#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_SLAVE_SUPPORT))
#include "LinTp.h"
#include "LinTp_Internal.h"

/*******************************************************************************
**                            Macros Definitions                              **
*******************************************************************************/

#define LINTP_GET_SLAVE_RTDATA_PTR(ch)     \
						(&LinTp_SlaveRTData[(ch)-LINTP_MASTER_CHANNEL_NUMBER])

/*******************************************************************************
**                      Runtime Type Definitions                              **
*******************************************************************************/
typedef enum {
    LINTP_SLAVE_RX_IDLE,
    LINTP_SLAVE_RX_SF,
    LINTP_SLAVE_RX_FF,
    LINTP_SLAVE_RX_REQ_BUF,
    LINTP_SLAVE_RX_WAIT_CF,
    LINTP_SLAVE_RX_CF
}LinTp_SlaveRxStage;

typedef enum {
    LINTP_SLAVE_TX_IDLE,
    LINTP_SLAVE_TX_SF,
    LINTP_SLAVE_TX_FF,
    LINTP_SLAVE_TX_CF,
    LINTP_SLAVE_TX_WAIT_CONFIRM
}LinTp_SlaveTxStage;

typedef struct {
    P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) ChCfgPtr;
    P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST) TxNSduPtr;
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) RxNSduPtr;
    uint8 SduBuf[LINTP_FRAME_LEN_MAX];
    PduInfoType* PduInfoPtr;
    PduLengthType SduSize;
    PduLengthType SduRemaining;
    PduLengthType SduCopyCnt;
    LinTp_StateType channelState;
    uint16 NcrTimer;
    uint16 NasTimer;
    uint16 NcsTimer;
    LinTp_FrameType LastFrameType;
    LinTp_SlaveRxStage RxStage;
    LinTp_SlaveTxStage TxStage;
    uint8 SduSN;
    uint8 RetryCopyCnt;
}LinTp_SlaveRuntimeType;

/*******************************************************************************
**                      Global Functions                                      **
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
FUNC(void,LINIF_CODE) LinTp_SlaveInit (void);

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
);

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
);

/******************************************************************************/
/*
* Brief               Shutdowns the LINTP slave node
* Sync/Async          Synchronous
* Reentrancy          Reentrant
* Param-Name[in]      None
* Param-Name[out]     None
* Param-Name[in/out]  None
* Return              None
*/
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_SlaveShutdown(void);

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
);

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
FUNC(void, LINIF_CODE) LinTp_SlaveTxConfirmation(
    NetworkHandleType ch,
    P2VAR(boolean, AUTOMATIC, LINIF_APPL_DATA) isTpTxFinish
);

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
);

#define LINTP_STOP_SEC_CODE
#include "LinIf_MemMap.h"

#endif /* #if ((LINIF_TP_SUPPORTED == STD_ON) && \
               (STD_ON == LINIF_SLAVE_SUPPORT)) */

#endif /* LINTP_SLAVE_H */
