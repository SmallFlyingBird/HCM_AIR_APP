/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2017)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinIf_Types.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : API declaration and type definitions of LinIf               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef LINIF_TYPES_H
#define LINIF_TYPES_H

#include "ComStack_Types.h"
#include "LinIf_Cfg.h"
#include "Lin_GeneralTypes.h"
#include "EcuM.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef uint8 LinIf_SchHandleType;

typedef enum
{
    LINIF_CLASSIC,
    LINIF_ENHANCED
} LinIf_ChecksumType;

typedef enum
{
    LINIF_ASSIGN,
    LINIF_ASSIGN_FRAME_ID_RANGE,
    LINIF_ASSIGN_NAD,
    LINIF_CONDITIONAL,
    LINIF_EVENT_TRIGGERED,
    LINIF_FREE,
    LINIF_MRF,
    LINIF_SAVE_CONFIGURATION,
    LINIF_SPORADIC,
    LINIF_SRF,
    LINIF_UNASSIGN,
    LINIF_UNCONDITIONAL
} LinIf_FrameTypeType;

typedef enum
{
    LINIF_CONTINUE_AT_IT_POINT,
    LINIF_START_FROM_BEGINNING
} LinIf_ResumePositionType;

typedef enum
{
    LINIF_RUN_CONTINUOUS,
    LINIF_RUN_ONCE
} LinIf_RunModeType;

typedef enum
{
    LINIF_UL_CDD,
    LINIF_UL_PDUR,
    LINIF_UL_LINSM
} LinIf_ULModuleType;

typedef enum
{
    LINIF_STARTUP_NORMAL,
    LINIF_STARTUP_SLEEP
} LinIf_StartupStateType;

typedef enum
{
    LINIF_RX_PDU = 0u,
    LINIF_TX_PDU = 1u,
    LINIF_INTERNAL_PDU = 2u,
    LINIF_SLAVE_TO_SLAVE_PDU = 3u
} LinIf_PduDirectionIdType;

typedef enum
{
    LINIF_VER_ISO17987,
    LINIF_VER_LIN13,
    LINIF_VER_LIN20,
    LINIF_VER_LIN21,
    LINIF_VER_LIN22
} LinIf_LinProtocolVersionType;

typedef enum
{
    LINIF_MASTER,
    LINIF_SLAVE
} LinIf_NodeTypeType;

typedef struct
{
    LinIf_PduDirectionIdType LinIfPduDirectionId;
} LinIf_PduDirectionType;

typedef struct
{
    LinIf_ChecksumType LinIfChecksumType;
    uint8 LinIfFrameId;
    uint8 LinIfLength;
    LinIf_FrameTypeType LinIfFrameType;
    P2CONST(LinIf_PduDirectionType, AUTOMATIC, LINIF_APPL_DATA) LinIfPduDirection;
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Buffer;
} LinIf_FrameType;

typedef struct
{
    uint8 LinIfDelay;
    uint8 LinIfEntryIndex;
    LinIf_SchHandleType LinIfCollisionResolvingRef;
    uint16 LinIfFrameRef;
} LinIf_EntryType;

typedef struct
{
    LinIf_NodeTypeType LinIfNodeType;
} LinIf_NodeType;

typedef struct
{
    uint8 LinChannelIdRef;
    uint8 LinDriverId;
    EcuM_WakeupSourceType WakeUpSource;
} LinIf_LinDriverChannelRef;

typedef struct
{
    uint16 LinIfBusIdleTimeoutPeriod;
    LinIf_ULModuleType LinIfGotoSleepConfirmationUL;
    P2FUNC(void,LINIF_APPL_CODE,GotoSleepConfirmation)(NetworkHandleType channel,boolean success);
    LinIf_ULModuleType LinIfGotoSleepIndicationUL;
    P2FUNC(void,LINIF_APPL_CODE,GotoSleepIndication)(NetworkHandleType channel);
    LinIf_StartupStateType LinIfStartupState;
    LinIf_ULModuleType LinIfWakeupConfirmationUL;
    P2FUNC(void,LINIF_APPL_CODE,WakeupConfirmation)(NetworkHandleType channel,boolean success);
    P2CONST(LinIf_LinDriverChannelRef, AUTOMATIC, LINIF_APPL_CONST) LinIfChannelRef;
    NetworkHandleType LinIfComMNetworkHandleRef;
    uint16 LinIfNumOfFrame;
    uint16 LinIfFrameIndexOffset;
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) LinIfFrame;
    P2CONST(LinIf_NodeType, AUTOMATIC, LINIF_APPL_CONST) LinIfNodeType;
}LinIf_ChannelType;

typedef struct
{
    Std_ReturnType LinIfTimeBase;
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) LinIfFrame;
    P2CONST(LinIf_ChannelType, AUTOMATIC, LINIF_APPL_CONST) LinIfChannel;
    uint8 SideSelect;
} LinIf_ConfigType;

typedef struct
{
    P2FUNC(Lin_StatusType, LINIF_APPL_CODE, LinGetStatus)(uint8 Channel,uint8** Lin_SduPtr);
    P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinGoToSleep)(uint8 Channel);
    P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinGoToSleepInternal)(uint8 Channel);
    P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinSendFrame)(uint8 Channel, const Lin_PduType* PduInfoPtr);
    P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinWakeup)(uint8 Channel);
    P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinWakeupInternal)(uint8 Channel);
    P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinCheckWakeup)(uint8 Channel);
} Lin_DriverApiType;

typedef enum
{
    LIN_SIDE_NO_CONFIG,
    LIN_SIDE_LEFT,
    LIN_SIDE_RIGHT,
} LinIf_SideSelectNumType;

#endif /* #ifndef LINIF_TYPES_H */
