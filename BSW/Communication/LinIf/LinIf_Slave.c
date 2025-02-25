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
**  FILENAME    : LinIf_Slave.c                                               **
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
 * V1.0.0      20200721   HuRongbo   Initial version
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "LinIf_Cfg.h"
#include "LinIf_Slave.h"
#include "LinTp_Slave.h"
#include "string.h"
#include "LinIf_Internal.h"
#include "Com.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define LINIF_NC_NAD_POS                    (uint8)0x00

#define LINIF_GET_CHANNEL_PIDTABLE(ch)      \
        (&LinIf_SlavePIDTable[LINIF_GET_FRAME_OFS(ch) - LINIF_MASTER_FRAME_NUM])

#define LINIF_GET_SLAVE_RTDATA_PTR(ch)      \
        (&LinIf_SlaveRTData[(ch) - LINIF_MASTER_CHANNEL_NUMBER])

#define LINIF_GET_BUS_IDLE_TIMEOUT_PERIOD(ch)      \
        (LINIF_GET_CHANNEL(ch).LinIfBusIdleTimeoutPeriod)

#define USER_GOTO_SLEEP_INDICATION(ch,channel)        \
            (LINIF_GET_CHANNEL(ch).GotoSleepIndication(channel))
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef enum {
    LINIF_SLAVE_FRAME_IDLE,
    LINIF_SLAVE_FRAME_RESPONSE /*Response transmitting or receiving*/
} LinIf_SlaveFrameStatusType;

typedef struct {
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) curFrame;
    uint16 busIdleTimer;
    LinIf_ChannelStateType channelState;
    LinIf_SlaveFrameStatusType frameStatus;
    boolean responseError;
    boolean wakeupFlag;
    boolean waitWakeupConfirmFlag;
    boolean gotoSleepConfirmationFlag;
}LinIf_SlaveRuntimeType;
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"

static FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveMRFHeaderHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) framePtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);

static FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveSRFHeaderHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) framePtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);

static FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveUncondHeaderHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) framePtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);

static FUNC(void,LINIF_CODE) LinIf_SlaveMRFRxHandle(
    NetworkHandleType ch,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
);

static FUNC(void,LINIF_CODE) LinIf_SlaveUncondRxHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) framePtr,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
);
static FUNC(void,LINIF_CODE) LinIf_SlaveUncondTxHandle(
	NetworkHandleType ch);

static FUNC(void,LINIF_CODE) LinIf_SlaveSetResponseErrorBit(
    NetworkHandleType ch,
    boolean responseError
);

static FUNC(void, LINIF_CODE) LinIf_SlaveSetLinPduType(
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) frame
);

static FUNC(void, LINIF_CODE) LinIf_SlaveTimerHandle(
    NetworkHandleType ch
);

static FUNC(void, LINIF_CODE) LinIf_SlaveResetRtData(
    NetworkHandleType ch
);
#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define LINIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinIf_MemMap.h"
static VAR(uint8,LINIF_VAR) LinIf_SlavePIDTable[LINIF_SLAVE_FRAME_NUM];

static VAR(LinIf_SlaveRuntimeType, LINIF_VAR)
LinIf_SlaveRTData[LINIF_SLAVE_CHANNEL_NUMBER];

#define LINIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinIf_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the LinIf slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinIf_SlaveInit( void )
{
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) framePtr;
    P2CONST(LinIf_ChannelType, AUTOMATIC, LINIF_VAR) chCfgPtr;
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr;
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) pidTablePtr;
    NetworkHandleType ch;
    uint16 frmIdx;

    for (ch = 0u; ch < LINIF_NUMBER_OF_CHANNELS; ch++)
    {
        LinIf_SlaveResetRtData(ch);

        chCfgPtr = &LINIF_GET_CHANNEL(ch);
        slaveRTDataPtr = LINIF_GET_SLAVE_RTDATA_PTR(ch);
        /*@req <SWS_LinIf_00507>*/
        if (LINIF_STARTUP_NORMAL == chCfgPtr->LinIfStartupState)
        {
            slaveRTDataPtr->channelState = LINIF_CHANNEL_OPERATIONAL;

            /*@req <SWS_LinIf_00752>*/
            /* Start the bus idle timeout observation */
            slaveRTDataPtr->busIdleTimer =
                LINIF_GET_BUS_IDLE_TIMEOUT_PERIOD(ch) / LINIF_GET_TIMEBASE();
        }
        else
        {
            slaveRTDataPtr->channelState = LINIF_CHANNEL_SLEEP;
            slaveRTDataPtr->busIdleTimer = 0u;
        }

        /* Initial Pid table */
        pidTablePtr = LINIF_GET_CHANNEL_PIDTABLE(ch);
        for (frmIdx = 0u; frmIdx < LINIF_GET_FRAME_NUM(ch); frmIdx++)
        {
            framePtr = &LINIF_GET_FRAME(ch, frmIdx);
            pidTablePtr[frmIdx] = framePtr->LinIfFrameId;
        }
    }
}

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
FUNC(void, LINIF_CODE) LinTp_SlaveShutdown(void)
{
    LinIf_SlaveInit();
}

/******************************************************************************/
/*
 * Brief               Wakeup process in slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveWakeUp(
    NetworkHandleType ch
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);
    uint8 linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
    uint8 linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
    Std_ReturnType ret;

    if(LINIF_CHANNEL_SLEEP == slaveRTDataPtr->channelState)
    {
        if (TRUE == slaveRTDataPtr->wakeupFlag)
        {
            /*@req <SWS_LinIf_00713>,<SWS_LinIf_00721>*/
            ret = LIN_DRIVER_API(linDriver).LinWakeupInternal(linChannel);
        }
        else
        {
            /*@req <SWS_LinIf_00296>,<SWS_LinIf_00720>*/
            ret = LIN_DRIVER_API(linDriver).LinWakeup(linChannel);
        }
    }
    else if(LINIF_CHANNEL_OPERATIONAL == slaveRTDataPtr->channelState)
    {
        /*@req <SWS_LinIf_00432>*/
        ret = E_OK;
    }
    else
    {
        /* LINIF_CHANNEL_GOTO_SLEEP */
        /*@req <SWS_LinIf_00760>*/
        (void)LIN_DRIVER_API(linDriver).LinWakeup(linChannel);
        ret = E_NOT_OK;
    }

    /*@req <SWS_LinIf_00720>,<SWS_LinIf_00721>*/
    if (E_OK == ret)
    {
        /*@req <SWS_LinIf_00714>*/
        slaveRTDataPtr->wakeupFlag = FALSE;
        /* Wait LinIf_HeaderIndication */
        slaveRTDataPtr->waitWakeupConfirmFlag = TRUE;
    }
    else
    {
        /*@req <SWS_LinIf_00762>*/
        USER_WAKEUP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), FALSE);
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief: Wakeup confirmation process in slave node
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SlaveWakeupConfirmation(
    EcuM_WakeupSourceType WakeupSource
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr;
    EcuM_WakeupSourceType wakeupSource;
    NetworkHandleType ch;

    #if (LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON)
    /*check all Lin driver channel to find the wake-up source*/
    for (ch = LINIF_MASTER_CHANNEL_NUMBER; ch < LINIF_NUMBER_OF_CHANNELS; ch++)
    {
        wakeupSource = LINIF_GET_LIN_DRIVER_WAKEUP_SOURCE(ch);
        if (0u != (WakeupSource & wakeupSource))
        {
            /*@req <SWS_LinIf_00716>*/
            slaveRTDataPtr = LINIF_GET_SLAVE_RTDATA_PTR(ch);
            slaveRTDataPtr->wakeupFlag = TRUE;
            break;
        }
    }
    #endif

    #if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
    #if (LINIF_LIN_TRCV_WAKEUP_SUPPORT == STD_ON)
    /*check all Lin transceiver channel to find the wake-up source*/
    for (ch = LINIF_MASTER_CHANNEL_NUMBER; ch < LINIF_NUMBER_OF_CHANNELS; ch++)
    {
        wakeupSource = LINIF_GET_LIN_TRCV_WAKEUP_SOURCE(ch);
        if (0u != (WakeupSource & wakeupSource))
        {
            /*@req <SWS_LinIf_00716>*/
            slaveRTDataPtr = LINIF_GET_SLAVE_RTDATA_PTR(ch);
            slaveRTDataPtr->wakeupFlag = TRUE;
            break;
        }
    }
    #endif
    #endif
}

/******************************************************************************/
/*
 * Brief               Header receive process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     Nad: Configured NAD of slave.
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveHeaderIndication(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) framePtr;
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) pidTablePtr = 
                                                LINIF_GET_CHANNEL_PIDTABLE(ch);
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);
    Std_ReturnType ret = E_NOT_OK;
    boolean irrelevantFlag = TRUE;
    uint16 frmIdx;

    if(TRUE == slaveRTDataPtr->waitWakeupConfirmFlag)
    {
        /*@req <SWS_LinIf_00761>*/
        USER_WAKEUP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), TRUE);

        slaveRTDataPtr->channelState = LINIF_CHANNEL_OPERATIONAL;
        /*@req <SWS_LinIf_00752>*/
        /* Start the bus idle timeout observation */
        slaveRTDataPtr->busIdleTimer = 
            LINIF_GET_BUS_IDLE_TIMEOUT_PERIOD(ch) / LINIF_GET_TIMEBASE();
    }

    /*@req <SWS_LinIf_00189>*/
    /* Receive/transmit LIN frame headers and responses only in the state LINIF_CHANNEL_OPERATIONAL*/
    if(LINIF_CHANNEL_OPERATIONAL == slaveRTDataPtr->channelState)
    {
        framePtr = &LINIF_GET_FRAME(ch, 0u);
        for(frmIdx = 0u; frmIdx < LINIF_GET_FRAME_NUM(ch); frmIdx++)
        {
            if(pidTablePtr[frmIdx] == PduPtr->Pid)
            {
                irrelevantFlag = FALSE;

                switch(framePtr->LinIfFrameType)
                {
                    case LINIF_MRF:
                        ret = LinIf_SlaveMRFHeaderHandle(ch, framePtr, PduPtr);
                        break;
                    case LINIF_SRF:
                        ret = LinIf_SlaveSRFHeaderHandle(ch, framePtr, PduPtr);
                        break;
					case LINIF_UNCONDITIONAL:
						ret = LinIf_SlaveUncondHeaderHandle(ch, framePtr, PduPtr);
						break;
                    default:
                        /* Other Frame Type */
                        break;
                }

                /* Response transmitting/receiving,save info to runtime data */
                if(E_OK == ret)
                {
                    /* Set frame status to response handle */
                    slaveRTDataPtr->frameStatus = LINIF_SLAVE_FRAME_RESPONSE;
                    /* Save current frame */
                    slaveRTDataPtr->curFrame = framePtr;
                }
                break;
            }
            framePtr++;
        }

        if(TRUE == irrelevantFlag)
        {
            /*@req <SWS_LinIf_00748>*/
            PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
            ret = E_OK;
        }

        /*@req <SWS_LinIf_00754>*/
        /* Reload the running bus idle timer*/
        slaveRTDataPtr->busIdleTimer = 
            LINIF_GET_BUS_IDLE_TIMEOUT_PERIOD(ch) / LINIF_GET_TIMEBASE();
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Receive indication process in slave node.
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
FUNC(void,LINIF_CODE) LinIf_SlaveRxIndication(
    NetworkHandleType ch,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) framePtr;

    if((LINIF_SLAVE_FRAME_RESPONSE == slaveRTDataPtr->frameStatus) &&
        (LINIF_RX_PDU ==
            slaveRTDataPtr->curFrame->LinIfPduDirection->LinIfPduDirectionId))
    {
        /*@req <SWS_LinIf_00189>*/
        /* Receive/transmit LIN frame headers and responses only in the state
        LINIF_CHANNEL_OPERATIONAL*/
        if(LINIF_CHANNEL_OPERATIONAL == slaveRTDataPtr->channelState)
        {
            framePtr = slaveRTDataPtr->curFrame;
            switch(framePtr->LinIfFrameType)
            {
                case LINIF_MRF:
                    LinIf_SlaveMRFRxHandle(ch, Lin_SduPtr);
                    break;
				case LINIF_UNCONDITIONAL:
					LinIf_SlaveUncondRxHandle(ch,framePtr,Lin_SduPtr);
					break;
                default:
                    /* Other Frame Type */
                    break;
            }
            /*@req <SWS_LinIf_00754>*/
            /* Reload the running bus idle timer*/
            slaveRTDataPtr->busIdleTimer = 
                LINIF_GET_BUS_IDLE_TIMEOUT_PERIOD(ch) / LINIF_GET_TIMEBASE();
        }
    }
    else
    {
        /*@req <SWS_LinIf_00848>*/
        /*No response reception is expected,return without further action.*/
    }
}
/******************************************************************************/
/*
 * Brief               uncondition message transmission indication process in slave node.
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
static FUNC(void,LINIF_CODE) LinIf_SlaveUncondTxHandle(NetworkHandleType ch)
{
	Com_SlaveTxIndication(ch);
}
/******************************************************************************/
/*
 * Brief               Tx confirmation process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinIf_SlaveTxConfirmation(
    NetworkHandleType ch
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                    LINIF_GET_SLAVE_RTDATA_PTR(ch);
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) framePtr =
                                    slaveRTDataPtr->curFrame;
    boolean isTpTxFinished;

    if((LINIF_SLAVE_FRAME_RESPONSE == slaveRTDataPtr->frameStatus) &&
       (LINIF_TX_PDU == slaveRTDataPtr->curFrame->LinIfPduDirection->LinIfPduDirectionId))
    {
    	switch(framePtr->LinIfFrameType)
    	{
    		case LINIF_SRF:
				LinTp_SlaveTxConfirmation(ch, &isTpTxFinished);
				if (TRUE == isTpTxFinished)
				{
					/* TP transmit finish,Reset channel runtime data */
					LinIf_SlaveResetRtData(ch);
				}
				break;
			case LINIF_UNCONDITIONAL:
            case LINIF_EVENT_TRIGGERED:
                LinIf_SlaveSetResponseErrorBit(ch,FALSE);
                LinIf_SlaveUncondTxHandle(ch);
				LinIf_SlaveResetRtData(ch);
				break;
			default: break;
    	}
        /*@req <SWS_LinIf_00754>*/
        /* Reload the running bus idle timer*/
        slaveRTDataPtr->busIdleTimer = 
                LINIF_GET_BUS_IDLE_TIMEOUT_PERIOD(ch) / LINIF_GET_TIMEBASE();
    }
    else
    {
        /*@req <SWS_LinIf_00852>*/
        /*No response reception is expected,return without further action.*/
    }
}

/******************************************************************************/
/*
 * Brief               Lin error indication process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel.
 *                     ErrorStatus: Type of detected error.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinIf_SlaveLinErrorIndication(
    NetworkHandleType ch,
    Lin_SlaveErrorType ErrorStatus
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);
    LinIf_PduDirectionIdType LinIfPduDirectionId;

    if((NULL_PTR != slaveRTDataPtr) && (NULL_PTR != slaveRTDataPtr->curFrame))
    {
        LinIfPduDirectionId = slaveRTDataPtr->curFrame->LinIfPduDirection->LinIfPduDirectionId;
        if(LINIF_SLAVE_FRAME_RESPONSE == slaveRTDataPtr->frameStatus)
        {

            if((LIN_ERR_RESP_STOPBIT == ErrorStatus) ||
            (LIN_ERR_RESP_CHKSUM == ErrorStatus) ||
            (LIN_ERR_RESP_DATABIT == ErrorStatus) ||
            ((LIN_ERR_INC_RESP == ErrorStatus) &&
            (LINIF_RX_PDU == LinIfPduDirectionId)))
			{
				LinIf_SlaveSetResponseErrorBit(ch, TRUE);
			}
        }

        /*@req <SWS_LinIf_00754>*/
        /* Reload the running bus idle timer*/
        slaveRTDataPtr->busIdleTimer =
                LINIF_GET_BUS_IDLE_TIMEOUT_PERIOD(ch) / LINIF_GET_TIMEBASE();
    }
}

/******************************************************************************/
/*
 * Brief               Go-to-sleep process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SlaveGotoSleep(
    NetworkHandleType ch
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);
    uint8 linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
    uint8 linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);

    /*@req <SWS_LinIf_00757>*/
    /* When LinIf_GotoSleep is called, Lin_GotoSleepInternal shall be called
       directly */
    (void)LIN_DRIVER_API(linDriver).LinGoToSleepInternal(linChannel);

    /*@req <SWS_LinIf_00758>*/
    /* Clear the wakeup flag */
    slaveRTDataPtr->wakeupFlag = FALSE;

    /* Set flag to call GoToSleepConfirmation() in MainFunction */
    slaveRTDataPtr->gotoSleepConfirmationFlag = TRUE;

    /*@req <SWS_LinIf_00753>*/
    /* LINIF_CHANNEL_SLEEP is entered,stop the bus idle timeout observation */
    slaveRTDataPtr->busIdleTimer = 0u;
}

/******************************************************************************/
/*
 * Brief               Main function of slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SlaveMainFunction(
    NetworkHandleType ch
)
{
	P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
	                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);

    LinIf_SlaveTimerHandle(ch);

    if(TRUE == slaveRTDataPtr->gotoSleepConfirmationFlag)
    {
		/* Change channel state to sleep */
		slaveRTDataPtr->channelState = LINIF_CHANNEL_SLEEP;
		slaveRTDataPtr->gotoSleepConfirmationFlag = FALSE;

    	/*@req <SWS_LinIf_00759>*/
		/* After calling the function Lin_GoToSleepInternal, the LIN Interface shall
		   invoke the function <User>_GotoSleepConfirmation with parameter TRUE.*/
		USER_GOTO_SLEEP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), TRUE);
    }
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               MRF frame process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 *                     framePtr: Pointed to configed LinIfFrameType
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
static FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveMRFHeaderHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) framePtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);

    /*@req <SWS_LinIf_00789>*/
    if(LINIF_SLAVE_FRAME_RESPONSE == slaveRTDataPtr->frameStatus)
    {
        LinIf_SlaveResetRtData(ch);
    }

    /*@req <SWS_LinIf_00733> */
    LinIf_SlaveSetLinPduType(PduPtr, framePtr);

    return E_OK;
}

/******************************************************************************/
/*
 * Brief               SRF frame process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 *                     framePtr: Pointed to configed LinIfFrameType
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
static FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveSRFHeaderHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) framePtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*@req <SWS_LinIf_00776>*/
    LinIf_SlaveSetLinPduType(PduPtr, framePtr);
    LinTp_SlaveSRFIndication(ch, PduPtr);
    if (LIN_FRAMERESPONSE_TX == PduPtr->Drc)
    {
        ret = E_OK;
    }
    
    return ret;
}

/******************************************************************************/
/*
 * Brief               unconditianl frame process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 *                     framePtr: Pointed to configed LinIfFrameType
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
static FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveUncondHeaderHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) framePtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
	uint8 ret = E_OK;

	LinIf_SlaveSetLinPduType(PduPtr, framePtr);
	ret = Com_SlaveHeaderIndication(ch,PduPtr);
	
	return ret;
}

/******************************************************************************/
/*
 * Brief               MRF response receive process in slave node.
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
static FUNC(void,LINIF_CODE) LinIf_SlaveMRFRxHandle(
    NetworkHandleType ch,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR)
    slaveRTDataPtr = LINIF_GET_SLAVE_RTDATA_PTR(ch);

    /*@req <SWS_LinIf_00750> */
    /* Go-to-sleep command */
    if(0x00u == Lin_SduPtr[LINIF_NC_NAD_POS])
    {
        /*@req <SWS_LinIf_00756> */
        /* Notify upper layer by invoke function <User>_GotoSleepIndication */
    	USER_GOTO_SLEEP_INDICATION(ch, LINIF_GET_COMM_NETWORK(ch));

        slaveRTDataPtr->channelState = LINIF_CHANNEL_GOTO_SLEEP;
    }
    else
    {
        LinTp_SlaveMRFIndication(ch, Lin_SduPtr);
        LinIf_SlaveResetRtData(ch);
    }
}

/******************************************************************************/
/*
 * Brief               slave response receive process in slave node.
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
static FUNC(void,LINIF_CODE) LinIf_SlaveUncondRxHandle(
    NetworkHandleType ch,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) framePtr,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
)
{
	Com_SlaveRxIndication(ch,framePtr,Lin_SduPtr);
	LinIf_SlaveResetRtData(ch);
}

/******************************************************************************/
/*
 * Brief               Set Lin_PduType
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      frame: Pointed to configed LinIfFrameType
 * Param-Name[out]     None
 * Param-Name[in/out]  PduPtr: Lin_PduType buffer pointer provided by Lin.
 * Return              None
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SlaveSetLinPduType(
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr,
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_CONST) frame
)
{
    /* Set DL */
    PduPtr->Dl = frame->LinIfLength;

    /* Set checksum type */
    if (LINIF_ENHANCED == frame->LinIfChecksumType)
    {
        /* Enhanced frame */
        PduPtr->Cs = LIN_ENHANCED_CS;
    }
    else
    {
        /* Classic frame */
        PduPtr->Cs = LIN_CLASSIC_CS;
    }

    /* Set direction */
    switch (frame->LinIfPduDirection->LinIfPduDirectionId)
    {
		case LINIF_RX_PDU:
			PduPtr->Drc = LIN_FRAMERESPONSE_RX;
		break;
		case LINIF_TX_PDU:
			PduPtr->Drc = LIN_FRAMERESPONSE_TX;
		break;
		default:
			PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		break;
    }
}

/******************************************************************************/
/*
 * Brief               Process timer used in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SlaveTimerHandle(
    NetworkHandleType ch
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);

    if(slaveRTDataPtr->busIdleTimer > 0u)
    {
        slaveRTDataPtr->busIdleTimer--;
        if(0u == slaveRTDataPtr->busIdleTimer)
        {
            /*@req <SWS_LinIf_00755>*/
            /* execute sleep mode transition */
        	USER_GOTO_SLEEP_INDICATION(ch, LINIF_GET_COMM_NETWORK(ch));
        }
    }
}

/******************************************************************************/
/*
* Brief               Process timer used in slave node.
* Sync/Async          Synchronous
* Reentrancy          Reentrant
* Param-Name[in]      ch: LinIf channel
* Param-Name[out]     None
* Param-Name[in/out]  None
* Return              None
*/
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SlaveResetRtData(
    NetworkHandleType ch
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                                LINIF_GET_SLAVE_RTDATA_PTR(ch);

    slaveRTDataPtr->curFrame = NULL_PTR;
    slaveRTDataPtr->frameStatus = LINIF_SLAVE_FRAME_IDLE;
    slaveRTDataPtr->wakeupFlag = FALSE;
    slaveRTDataPtr->waitWakeupConfirmFlag = FALSE;
    slaveRTDataPtr->gotoSleepConfirmationFlag = FALSE;
}

/******************************************************************************/
/*
 * Brief               Set Response-Error bit to the value same with parameter 
 *                     'responseError'.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel.
 *                     ErrorStatus: Type of detected error.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void,LINIF_CODE) LinIf_SlaveSetResponseErrorBit(
    NetworkHandleType ch,
    boolean responseError
)
{
    P2VAR(LinIf_SlaveRuntimeType, AUTOMATIC, LINIF_VAR) slaveRTDataPtr =
                                            LINIF_GET_SLAVE_RTDATA_PTR(ch);

    /*@req <SWS_LinIf_00766>*/
    #if defined(LinIfResponseErrorSignalChangedCallout)
    if((responseError != slaveRTDataPtr->responseError) &&
       (TRUE == LINIF_GET_RESPONSE_ERROR_SIGNAL_CONFIGURED(ch)))
    {
        /*@req <SWS_LinIf_00765>*/
        LinIfResponseErrorSignalChangedCallout(ch, responseError);
    }
    #endif
    /* Set the response_error signal */
    slaveRTDataPtr->responseError = responseError;

    /*@req <SWS_LinIf_00764>*/
    Com_SetErrorSignal(slaveRTDataPtr->curFrame->LinIfFrameId,&slaveRTDataPtr->responseError);

}

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"
