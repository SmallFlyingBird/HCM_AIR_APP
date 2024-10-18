/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Xcp_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-09-13 15:41:46>
 */
/*============================================================================*/

#include "Xcp.h"
/*
 *  GetId CMD Config
 */
#define XCP_START_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"
static CONST(uint8, XCP_CONST_PBCFG) IdInfo1[5] = {"test"};
#define XCP_STOP_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_IdInfoType, XCP_CONST_PBCFG) Xcp_IdInfo[XCP_NUM_OF_ID] =
{
    {
        1, 0, sizeof(IdInfo1), &IdInfo1[0]
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(XcpDtoType, XCP_CONST_PBCFG) Xcp_Dto[1] =
{
    {
        0,/*XcpFirstPid*/
        &Xcp_Daq_Pdu[0] /*XcpDto2PduMapping*/
    },
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static VAR(Xcp_EntryType, XCP_VAR) Xcp_StaticEntry[4];  /* Sum(XcpMaxOdtEntries(Daq) * XcpMaxOdt(Daq)) */
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static VAR(Xcp_OdtType, XCP_CONST_PBCFG) Xcp_StaticOdt[2] =   /* Sum(XcpMaxOdtEntries(Daq)) */
{
    {2, 0, &Xcp_StaticEntry[0]},
    {2, 1, &Xcp_StaticEntry[2]},
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_DaqListConfigType, XCP_CONST_PBCFG) Xcp_DaqConfig[XCP_MAX_DAQ] =
{
    {
        0,/*XcpDaqListNumber*/
        DAQ, /* XcpDaqListtype */
        0x2,  /* XcpMaxOdt */
        2,  /* XcpMaxOdtEntries */
        &Xcp_Dto[0],  /* XcpDto */
        &Xcp_StaticOdt[0]   /* XcpOdt */
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
static VAR(Xcp_AGType, XCP_VAR) Xcp_EvCh0Buffer[XCP_EVCHBUFFER_0_DEPTH];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"
static CONST(uint8, XCP_CONST_PBCFG) Xcp_Evch_0[MAX_EVCH_NAME_LENGTH] = { "EventChannel_0" };
#define XCP_STOP_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_16
#include "Xcp_MemMap.h"
static CONST(Xcp_DaqNumType, XCP_CONST_PBCFG) Xcp_EvCh0DaqList[1] = {0 };
#define XCP_STOP_SEC_CONFIG_DATA_16
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_EvChConfigType, XCP_CONST_PBCFG) Xcp_EvChConfig[XCP_MAX_EVENT_CHANNEL] =
{
    {
        Xcp_Evch_0,
        sizeof(Xcp_Evch_0),
        XCP_EVENT_CONSIST_EVENT,
        1, /*XcpEvChMaxDaqList*/
        0,/*XcpEvChNumber*/
        0,/*XcpEvChPriority*/
        10,/*XcpEvChTimeCycle*/
        TIMESTAMP_UNIT_1MS,/*XcpEvChTimeUnit*/
        DAQ,/*XcpEvChType*/
        XCP_EVCHBUFFER_0_DEPTH,
        &Xcp_EvCh0Buffer[0],
        &Xcp_EvCh0DaqList[0]
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
static VAR(uint8, XCP_VAR) Xcp_PageBuffer0[XCP_PAGE_BUF0_SIZE];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_PageInfoType, XCP_CONST_PBCFG) Xcp_PageInfo[XCP_MAX_SEGMENT] =
{
    {
        0x2000,
        0x2001d000,
        0x2001efff,
        0x1e2000u,
        0x1e3fffu,
        (uint32)Xcp_PageBuffer0, /* PRQA S 0306 */ /* MISRA Rule 11.4 */
    }
};

CONST(Xcp_SegmentInfoType,XCP_CONST_PBCFG) Xcp_SegmentInfo =
{
    XCP_MAX_SEGMENT,
    Xcp_PageInfo,
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"
static CONST(uint8, XCP_CONST_PBCFG) sectorName_No_0[] = {"XcpSectorInfo_0"};
#define XCP_STOP_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
/* PRQA S 1531 ++ */     /* MISRA Rule 8.7 */
CONST(Xcp_SectorInfoType, XCP_CONST_PBCFG) Xcp_SectorInfo[XCP_MAX_SECTOR] =
{
    {
        sectorName_No_0,            /* Name*/
        sizeof(sectorName_No_0),    /* name length */
        0x0u,                      /* SECTOR_NUMBER */
        0x20000UL,                   /* address */
        0x2000UL,                   /* length */
        0x01u,        /* Flash range type*/
        0x20000UL,                   /* progStartAddress */
        0x2000UL,                   /* progDataSize */
        0x00u,                      /* Erase number */
        0x01u,                      /* Program number */
        0x00u                       /* Programming method */
    }
};

CONST(Xcp_FlsFuncPtrType, XCP_CONST_PBCFG) Xcp_FlsFuncPtr =
{
    Fls_Write,
    Fls_Erase,
    Fls_GetJobResult
};
/* PRQA S 1531 -- */     /* MISRA Rule 8.7 */

#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
CONST(Xcp_PCConfigType, XCP_CONST_PBCFG) Xcp_PConfig = /* PRQA S 1533 */ /* MISRA Rule 8.9 */
{
    &Xcp_DaqConfig[0],
    &Xcp_EvChConfig[0],
    XCP_NUM_OF_ID,
    &Xcp_IdInfo[0]
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
