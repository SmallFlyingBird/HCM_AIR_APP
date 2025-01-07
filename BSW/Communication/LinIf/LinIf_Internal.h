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
**  FILENAME    : LinIf.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for LinIf                                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef LINIF_INTERNAL_H
#define LINIF_INTERNAL_H

#include "LinIf_Types.h"
#include "Lin_GeneralTypes.h"
#include "SchM_LinIf.h"

/*******************************************************************************
**                            Macros Definitions                              **
*******************************************************************************/
/* PC/LT/PB configuration */
#define LINIF_GET_CHANNEL(ch)           \
            (LinIf_ConfigPtr->LinIfChannel[ch])
#define LINIF_GET_TIMEBASE()     \
            (LinIf_ConfigPtr->LinIfTimeBase)
#define LINIF_GET_GLOBAL_FRAME(idx)     \
            (LinIf_ConfigPtr->LinIfFrame[idx])
#define LINIF_GET_FRAME_NUM(ch)         \
            (LINIF_GET_CHANNEL(ch).LinIfNumOfFrame)
#define LINIF_GET_SCHEDULE_OFS(ch)      \
            (LINIF_GET_CHANNEL(ch).LinIfScheduleIndexOffset)
#define LINIF_GET_FRAME_OFS(ch)         \
            (LINIF_GET_CHANNEL(ch).LinIfFrameIndexOffset)
#define LINIF_GET_FRAME(ch,idx)         \
            (LINIF_GET_CHANNEL(ch).LinIfFrame[idx])
#define LINIF_GET_LIN_CHANNEL_ID(ch)     \
            (LINIF_GET_CHANNEL(ch).LinIfChannelRef->LinChannelIdRef)
#define LINIF_GET_LIN_DRIVER_ID(ch)      \
            (LINIF_GET_CHANNEL(ch).LinIfChannelRef->LinDriverId)
#define LINIF_GET_LIN_DRIVER_WAKEUP_SOURCE(ch)  \
            (LINIF_GET_CHANNEL(ch).LinIfChannelRef->WakeUpSource)
#define LINIF_GET_COMM_NETWORK(ch)      \
            (LINIF_GET_CHANNEL(ch).LinIfComMNetworkHandleRef)
#define LINIF_GET_STARTUP_STATE(ch)     \
            (LINIF_GET_CHANNEL(ch).LinIfStartupState)
#define LINIF_GET_NODETYPE(ch)     \
            (LINIF_GET_CHANNEL(ch).LinIfNodeType->LinIfNodeType)
#define USER_WAKEUP_CONFIRMATION(ch,channel,success)        \
            (LINIF_GET_CHANNEL(ch).WakeupConfirmation(channel,success))
#define USER_GOTO_SLEEP_CONFIRMATION(ch,channel,success)    \
            (LINIF_GET_CHANNEL(ch).GotoSleepConfirmation(channel,success))
#define USER_SCHEDULE_REQUEST_CONFIRMATION(ch,channel,schedule)   \
            (LINIF_GET_CHANNEL(ch).ScheduleRequestConfirmation(channel,schedule))

#define LIN_DRIVER_API(driverId) Lin_DriverApi[driverId]

/* Check whether frame slot timer is timeout */
#define LINIF_IS_TIMEOUT(ch)    (LinIf_MasterChRtData[ch].Timer == 0u)

/* Handle events of LINIF */
#define LINIF_EVENT_MASK            0xFFFFu
#define LINIF_EVENT_NONE            0x0000u
#define LINIF_EVENT_SLEEP           0x0001u
#define LINIF_EVENT_GOTO_SLEEP      0x0002u
#define LINIF_EVENT_WAKEUP_E_OK     0x0004u
#define LINIF_EVENT_WAKEUP_E_NOT_OK 0x0008u
#define LINIF_EVENT_COLLISION       0x0010u
#define LINIF_EVENT_INTERRUPT_BACK  0x0020u
#define LINIF_EVENT_HEADER          0x0040u
#define LINIF_EVENT_RESPONSE        0x0080u
#define LINIF_EVENT_SCHEDULE_CONF   0x0100u
#define LINIF_EVENT_SCHEDULE_REQ    0x0200u
#define LINIF_EVENT_NCMRF_SEND      0x0400u
#define LINIF_EVENT_NCSRF_SEND      0x0800u

#define LINIF_SET_EVENT(e) chPtr->RootEvent |= (e)
#define LINIF_CLR_EVENT(e) chPtr->RootEvent &= ~(e)
#define LINIF_IS_EVENT(e)  ((chPtr->RootEvent & (e)) != 0u)

#define LINIF_CH(ch) (&LinIf_MasterChRtData[ch])

/* Return the minimum value */
#define LINIF_MIN(a,b) (((a) < (b)) ? (a) : (b))

/*******************************************************************************
**                      Runtime Type Definitions                              **
*******************************************************************************/
typedef enum {
    LINIF_UNINIT,
    LINIF_INIT
} LinIf_StatusType;

typedef enum {
    LINIF_CHANNEL_UNINIT,
    LINIF_CHANNEL_OPERATIONAL,
    LINIF_CHANNEL_GOTO_SLEEP,
    LINIF_CHANNEL_SLEEP
} LinIf_ChannelStateType;

/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/
#define LINIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"
/* The status of LINIF */
extern VAR(LinIf_StatusType, LINIF_VAR) LinIf_Status;
#define LINIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"
/* Global configuration pointer of LINIF */
extern P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST) LinIf_ConfigPtr;
#define LINIF_STOP_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"

#endif /* LINIF_INTERNAL_H */
