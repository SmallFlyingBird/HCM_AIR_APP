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
 *  @file               : ComM_PBCfg.c
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2024/05/14 13:47:03
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic R19-11
 *
 */

/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"
#include "ComM_PBCfg.h"
#include "CanSM.h"
/*==========================================[external function definitions]===========================================*/
BEGIN_C_DECLS
/*=================================================[internal data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserDirectMapChanelTable[1] = {0u};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserMapAllChanelTable[9] = {
    0u,0u,0u,0u,0u,0u,0u,0u,0u
};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserInChanelIdexTable[1] = {0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserMapPncTable[8] = {0u,1u,2u,3u,4u,5u,6u,7u};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserInPncIdexTable[8] = {0u,0u,0u,0u,0u,0u,0u,0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_UserConfigType, COMM_CONST) ComM_UserCfg[COMM_USER_NUMBER] = {
    /* ComMUser_BodyExposedCAN_HCML */
    {
        0u,/*userId*/
        &ComM_UserDirectMapChanelTable[0],/*directChList*/
        1u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[0],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[0],/*userInChIdex*/
        NULL_PTR,/*pncList*/
        0u,/*pncListNum*/
        NULL_PTR,/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING22 */
    {
        1u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[1],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[0],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[0],/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING24 */
    {
        2u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[2],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[1],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[1],/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING16 */
    {
        3u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[3],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[2],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[2],/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING38 */
    {
        4u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[4],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[3],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[3],/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING17 */
    {
        5u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[5],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[4],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[4],/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING39 */
    {
        6u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[6],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[5],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[5],/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING18 */
    {
        7u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[7],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[6],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[6],/*userInPncIdex*/
    },
    /* ComMUser_SystemMAPPING29 */
    {
        8u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[8],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
        &ComM_UserMapPncTable[7],/*pncList*/
        1u,/*pncListNum*/
        &ComM_UserInPncIdexTable[7],/*userInPncIdex*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_BusSmConfigType, COMM_CONST) ComM_BusSmCfgTable[1] = {
    {
        CanSM_RequestComMode,/*busSm_RequestComMode*/
        CanSM_GetCurrentComMode /*busSm_GetCurrentComMode*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
#define COMM_START_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_BodyExposedCAN_HCML[2];
#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_PncInChanelIdex_BodyExposedCAN_HCML[8] =
{0x1u,0x2u,0x3u,0x4u,0x5u,0x6u,0x7u,0x8u};

COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_DcmNotifyId[1]={0x0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_ChannelConfigType, COMM_CONST) ComM_ChannelConfig[COMM_CHANNEL_NUMBER] = {
    /* BodyExposedCAN_HCML */
    {
        0u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        0u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_FULL,/*nmVariant*/
        9u,/*dcmInReqIdx*/
        &ComM_DcmNotifyId[0],/*dcmNotifyIdPtr*/
        0u,/*netifId*/
        0x0u,/*txIraSigIdx*/
        &ComM_PncInChanelIdex_BodyExposedCAN_HCML[0],/*pncInChIdex*/
        {0x4},/*cfgMask*/
        &ComM_ReqMaskBuf_BodyExposedCAN_HCML[0],/*requestMask*/
        2u /*requestMaskLen*/
    }
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING22[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING24[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING16[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING38[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING17[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING39[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING18[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_SystemMAPPING29[1];

#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_PncItemConfigType, COMM_CONST) ComM_PncItemCfgTable[8] = {
    /* SystemMAPPING22 */
    {
        22u,/*pncId*/
        6u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        0u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING22[0],/*requestMask*/
        1u,/*requestMaskLen*/
    },
    /* SystemMAPPING24 */
    {
        24u,/*pncId*/
        8u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        1u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING24[0],/*requestMask*/
        1u,/*requestMaskLen*/
    },
    /* SystemMAPPING16 */
    {
        16u,/*pncId*/
        0u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        2u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING16[0],/*requestMask*/
        1u,/*requestMaskLen*/
    },
    /* SystemMAPPING38 */
    {
        38u,/*pncId*/
        22u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        3u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING38[0],/*requestMask*/
        1u,/*requestMaskLen*/
    },
    /* SystemMAPPING17 */
    {
        17u,/*pncId*/
        1u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        4u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING17[0],/*requestMask*/
        1u,/*requestMaskLen*/
    },
    /* SystemMAPPING39 */
    {
        39u,/*pncId*/
        23u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        5u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING39[0],/*requestMask*/
        1u,/*requestMaskLen*/
    },
    /* SystemMAPPING18 */
    {
        18u,/*pncId*/
        2u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        6u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING18[0],/*requestMask*/
        1u,/*requestMaskLen*/
    },
    /* SystemMAPPING29 */
    {
        29u,/*pncId*/
        13u,/*pncOffsetId*/
        1u,/*pncMapChNum*/
        FALSE,/*pncWakeupSleepRequestEnabled*/
        7u,/*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_SystemMAPPING29[0],/*requestMask*/
        1u,/*requestMaskLen*/
    }
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_PncToChannelMap[1][COMM_PN_INFO_LENGTH] = {
{0x47u,0x21u,0xc0u,0x0u,0x0u,0x0u},/*BodyExposedCAN_HCML */
};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_PTR
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONSTP2CONST(ComM_ChannelConfigType, COMM_CONST, COMM_CONST) ComMPncChannelList[1] = {
&ComM_ChannelConfig[0]
};
#define COMM_STOP_SEC_CONST_PBCFG_PTR
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_ComPncMaskEira_isCanNmEira[6] = {0x47u,0x21u,0xc0u,0x0u,0x0u,0x0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

COMM_CONFIG_LOCAL CONST(ComM_ComEiraRxSignalConfigType, COMM_CONST) ComM_ComRxEiraSigTable[1] = {
    {
        45,/*sigId*/
        0u,/*offset*/
        6u,/*len*/
        ComM_ComPncMaskEira_isCanNmEira,/*pncMask*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_ComIraTxSignalConfigType, COMM_CONST) ComM_ComTxIraSigTable[1]=
{
     {
          21u,/*sigId*/
          0u,/*offset*/
          6u/*len*/
     },

};

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_PncConfigType, COMM_CONST) ComM_PncCfg = {
    2u,/*pncVectorOffset*/
    ComM_PncItemCfgTable,/*pncListCfgPtr*/
    8u,/*pncListNum*/
    ComM_PncToChannelMap,/*chanToPncMap*/
    1u,/*pncMapTotalChannelNum*/
    ComMPncChannelList,/*ChCfgPtr*/
    1u,/*comRxEiraSigNum*/
    ComM_ComRxEiraSigTable,/*comEiraRxSigPtr*/
    1u,/*comTxIraSigNum*/
    ComM_ComTxIraSigTable,/*comIraTxSigPtr*/
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

/*=================================================[external data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
CONST(ComM_ConfigType, COMM_CONST) ComM_Config = {  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
    TRUE,/*ComMPncEnabled*/
    ComM_ChannelConfig,/*chCfgPtr*/
    COMM_CHANNEL_NUMBER,/*chCfgNum*/
    &ComM_PncCfg,/*pncCfgPtr*/
    ComM_UserCfg,/*userCfgPtr*/
    COMM_USER_NUMBER,/*userCfgNum*/
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
END_C_DECLS

