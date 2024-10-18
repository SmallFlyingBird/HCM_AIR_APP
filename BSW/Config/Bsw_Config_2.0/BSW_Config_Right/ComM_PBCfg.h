
/**
 *
 * Copyright (C) iSOFT   (2022)
 *
 * All rights reserved.
 *
 * This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and
 * communication of its contents is not permitted without prior written authorization.
 *
 *
 *  @file               : ComM_PBCfg.h
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2024/05/14 08:26:59 
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-1
 *
 */

#ifndef COMM_PBCFG_H_
#define COMM_PBCFG_H_

/*=================================================[inclusions]=======================================================*/

#include "ComM_Types.h"
#include "Com.h"
/*====================================================[macros]========================================================*/
BEGIN_C_DECLS
#if !defined(COMM_CONFIG_LOCAL)
#define COMM_CONFIG_LOCAL static
#endif /* !defined(COMM_LOCAL) */

/*=============================================[type definitions]=====================================================*/
/** \brief busSm type */
typedef struct {
    Std_ReturnType (*busSm_RequestComMode)(NetworkHandleType network, ComM_ModeType ComM_Mode);
    Std_ReturnType (*busSm_GetCurrentComMode)(NetworkHandleType network, ComM_ModeType* ComM_Mode);
} ComM_BusSmConfigType;
/** \brief channel data type */
typedef struct {
    uint32 inerChIdx;
#define COMM_BUS_TYPE_CAN      0u
    uint32 busType;
    NetworkHandleType busIndex;
    const ComM_BusSmConfigType* busSmCfgType;
#define COMM_NM_VARIANT_FULL          0x01u
#define COMM_NM_VARIANT_NORMAL        0x1u
    uint8 nmVariant;
    uint8 dcmInReqIdx;
    const uint8* dcmNotifyIdPtr;
    NetworkHandleType netifId;
    Com_SignalIdType txIraSigIdx;
    const uint8* pncInChIdex;
#define COMM_PNC_NM_REQUEST   0x2u
#define COMM_NO_COM_INHIBITION 0x3u
#define COMM_NO_WAKEUP_INHIBITION 0x4u
    uint32 cfgMask[1];
    /* channel var */
    uint8* requestMask;
    uint8 requestMaskLen;
} ComM_ChannelConfigType;

/** \brief pnc member data type */
typedef struct {
    PNCHandleType pncId;
    uint8 pncOffsetId;
    uint8 pncMapChNum;
    boolean pncWakeupSleepRequestEnabled;
    PNCHandleType notifyBswMPncId;
    /* pnc var */
    uint8* requestMask;
    uint8 requestMaskLen;
} ComM_PncItemConfigType;
/** \brief Com Signal data type used by the RX EIRA */
typedef struct {
    Com_SignalIdType sigId;
    uint8 offset;
    uint8 len;
    const uint8* pncMask;
} ComM_ComEiraRxSignalConfigType;

/** \brief Com Signal data type used by the TX IRA */
typedef struct {
    Com_SignalIdType sigId;
    uint8 offset;
    uint8 len;
} ComM_ComIraTxSignalConfigType;

/** \brief pnc data type */
typedef struct {
    uint8 pncVectorOffset;
    const ComM_PncItemConfigType* pncListCfgPtr;
    uint32 pncListNum;
    const uint8 (*chanToPncMap)[COMM_PN_INFO_LENGTH];
    uint32 pncMapTotalChannelNum;
    const ComM_ChannelConfigType* const* ChCfgPtr;
    uint32 comRxEiraSigNum;
    const ComM_ComEiraRxSignalConfigType* comEiraRxSigPtr;
    uint32 comTxIraSigNum;
    const ComM_ComIraTxSignalConfigType* comIraTxSigPtr;
} ComM_PncConfigType;

/** \brief user data type */
typedef struct ComM_UserConfigSTag{
    ComM_UserHandleType userId;
    const uint8* directChList;
    uint32 directChListNum;
    const uint8* mapAllChList;
    uint32 mapAllChListNum;
    const uint8* userInChIdex;
    const uint8* pncList;
    uint32 pncListNum;
    /* this user in pnc index */
    const uint8* userInPncIdex;
} ComM_UserConfigType;
typedef struct {
    boolean ComMPncEnabled;
    const ComM_ChannelConfigType* chCfgPtr;
    uint32 chCfgNum;
    const ComM_PncConfigType* pncCfgPtr;
    const ComM_UserConfigType* userCfgPtr;
    uint32 userCfgNum;
}ComM_ConfigType;
/*========================================[external data declarations]============================================*/
extern CONST(ComM_ConfigType, COMM_CONST) ComM_Config;
END_C_DECLS
#endif /* COMM_PBCFG_H_ */

