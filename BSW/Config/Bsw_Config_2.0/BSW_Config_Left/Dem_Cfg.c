/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-08-14 18:47:52>
 */
/*============================================================================*/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Dem_CfgTypes.h"
#include "Dem_Internal.h"
#if (DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM_Cfg.h"
#endif

/*******************************************************************************
*                          General Configuration
*******************************************************************************/

/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType DemReadAgingUpCnt(uint8* Buffer)
{
    *Buffer = DemInternalData.AgingUpCnt;
    return E_OK;
}
static Std_ReturnType DemReadCurrentFDC(uint8* Buffer)
{
    *Buffer = DemInternalData.CurrentFDC;
    return E_OK;
}
static Std_ReturnType DemReadMaxFDCSinceLastClear(uint8* Buffer)
{
    *Buffer = DemInternalData.MaxFDCSinceLastClear;
    return E_OK;
}
static Std_ReturnType DemReadMaxFDCDuringCurrentCycle(uint8* Buffer)
{
    *Buffer = DemInternalData.MaxFDCDuringCurrentCycle;
    return E_OK;
}
static Std_ReturnType DemReadCyclesSinceLastFailed(uint8* Buffer)
{
    *Buffer = DemInternalData.CyclesSinceLastFailed;
    return E_OK;
}
static Std_ReturnType DemReadCyclesSinceFirstFailed(uint8* Buffer)
{
    *Buffer = DemInternalData.CyclesSinceFirstFailed;
    return E_OK;
}
static Std_ReturnType DemReadOCC6(uint8* Buffer)
{
    *Buffer = DemInternalData.OCC6;
    return E_OK;
}
static Std_ReturnType DemReadOCC4(uint8* Buffer)
{
    *Buffer = DemInternalData.OCC4;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(DemDataElementClassTypes,AUTOMATIC) DemDataElementClass[DEM_DATA_ELEMENT_CLASS_NUM] =
{
    {
        FALSE,
        4u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD00_ReadData,/*DemDataElementClass*/
    },
    {
        FALSE,
        3u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD01_ReadData,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD02_ReadData,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0A_ReadData,/*DemDataElementClass*/
    },
    {
        FALSE,
        2u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0B_ReadData,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0C_ReadData,/*DemDataElementClass*/
    },
    {
        FALSE,
        6u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD07_ReadData,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadCurrentFDC,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadMaxFDCDuringCurrentCycle,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadMaxFDCSinceLastClear,/*DemDataElementClass*/
    },
    {
        FALSE,
        4u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_20_ReadData,/*DemDataElementClass*/
    },
    {
        FALSE,
        4u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_21_ReadData,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadCyclesSinceLastFailed,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadAgingUpCnt,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadCyclesSinceFirstFailed,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadOCC4,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_OC_5_ReadData,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadOCC6,/*DemDataElementClass*/
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          Condition Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemOperationCycle */
CONST(Dem_OperationCycleType,AUTOMATIC) DemOperationCycle[DEM_OPERATION_CYCLE_NUM] =
{
    { /* DemOperationCycle_No2 */
        FALSE,
        TRUE,
        DEM_OPCYC_IGNITION
    },
    { /* DemOperationCycle_No5 */
        FALSE,
        TRUE,
        DEM_OPCYC_IGNITION
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemEnableCondition */
CONST(uint8,AUTOMATIC) DemEnableCondition[DEM_ENABLE_CONDITION_NUM_BYTE] =
{
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,

};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemEnableConditionGroup */
CONST(uint8,AUTOMATIC) DemEnableConditionGroup[DEM_ENABLE_CONDITION_GROUP_NUM][DEM_ENABLE_CONDITION_NUM_BYTE] =
{
    {0x1fu,0x0u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x0u,0x0u,},
    {0x2fu,0x0u,0x0u,0x4u,0x0u,0x0u,},
    {0x4fu,0x0u,0x0u,0x4u,0x0u,0x0u,},
    {0x8fu,0x0u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x1u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x2u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x4u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x8u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x10u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x20u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x40u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x80u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x1u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x2u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x4u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x8u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x10u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x20u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x40u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0xc0u,0x4u,0x0u,0x0u,},
    {0x2fu,0x0u,0x0u,0x4u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x5u,0x0u,0x0u,},
    {0x8u,0x0u,0x0u,0xcu,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x0u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x10u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x30u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x40u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0xc0u,0x0u,},
    {0xfu,0x0u,0x0u,0x14u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x24u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x44u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x84u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x1u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x2u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x4u,0x0u,},
    {0xfu,0x0u,0x0u,0x4u,0x8u,0x0u,},
    {0xfu,0x0u,0x0u,0x0u,0x0u,0x4u,},
    {0x1fu,0x0u,0x0u,0x0u,0x0u,0x0u,},
    {0xfu,0x0u,0x0u,0x0u,0x0u,0x3u,},
    {0xfu,0x0u,0x0u,0x4u,0x0u,0x4u,}
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          FreezeFrame Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDidClass */
CONST(Dem_DidClassType,AUTOMATIC) DemDidClass[DEM_DID_CLASS_NUM] =
{
    { /* DemDidClass_0xDD00 */
        0xdd00u,
        0u,
        1u,
        4u,
    },
    { /* DemDidClass_0xDD01 */
        0xdd01u,
        1u,
        1u,
        3u,
    },
    { /* DemDidClass_0xDD02 */
        0xdd02u,
        2u,
        1u,
        1u,
    },
    { /* DemDidClass_0xDD0A */
        0xdd0au,
        3u,
        1u,
        1u,
    },
    { /* DemDidClass_0xDD0B */
        0xdd0bu,
        4u,
        1u,
        2u,
    },
    { /* DemDidClass_0xDD0C */
        0xdd0cu,
        5u,
        1u,
        1u,
    },
    { /* DemDidClass_0xDD07 */
        0xdd07u,
        6u,
        1u,
        6u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) DemDidClassRef[DEM_DID_CLASS_REF_TOTAL_NUM] =
{
    /* DemFreezeFrameClass_0 */
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x5u,
    0x6u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameClassType,AUTOMATIC) DemFreezeFrameClass[DEM_FREEZE_FRAME_CLASS_NUM] =
{
    { /* DemFreezeFrameClass_0 DID*/
        18u,
        0u,
        7u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemFreezeFrameRecordClass */
CONST(Dem_FreezeFrameRecordClassType,AUTOMATIC) DemFreezeFrameRecordClass[DEM_FREEZE_FRAME_RECORD_CLASS_NUM] =
{
    { /* DemFreezeFrameRecordClass_0x20 */
        32u,                       /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_CONFIRMED,   /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_NO       /* DemFreezeFrameRecordUpdate */
    },
    { /* DemFreezeFrameRecordClass_0x21 */
        33u,                       /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_FDC_THRESHOLD,   /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_NO       /* DemFreezeFrameRecordUpdate */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8,AUTOMATIC) DemFreezeFrameRecordClassRef[DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM] =
{
    /* DemFreezeFrameRecNumClass_0 */
    0x0u,
    0x1u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameRecNumClassType,AUTOMATIC) DemFreezeFrameRecNumClass[DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM] =
{
    { /* DemFreezeFrameRecNumClass_0 */
        0u,
        2u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          ExtendedData Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemExtendedDataRecordClass */
CONST(Dem_ExtendedDataRecordClassType,AUTOMATIC) DemExtendedDataRecordClass[DEM_EXTENDED_DATA_RECORD_CLASS_NUM] =
{
    { /* DemExtendedDataRecordClass_0x10 */
        0x10u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        7u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x11 */
        0x11u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        8u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x12 */
        0x12u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        9u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x20 */
        0x20u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        10u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        4u,
    },
    { /* DemExtendedDataRecordClass_0x21 */
        0x21u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        11u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        4u,
    },
    { /* DemExtendedDataRecordClass_0x01 */
        0x1u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        12u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x02 */
        0x2u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        13u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x03 */
        0x3u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        14u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x04 */
        0x4u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        15u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x05 */
        0x5u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        16u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_0x06 */
        0x6u,
        DEM_TRIGGER_ON_FDC_THRESHOLD,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        17u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8,AUTOMATIC) DemExtendedDataRecordClassRef[DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM] =
{
    /* DemExtendedDataClass_0 */
    0x5u,
    0x6u,
    0x7u,
    0x8u,
    0x9u,
    0xau,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/* DemGeneral/DemExtendedDataClass */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_ExtendedDataClassType,AUTOMATIC) DemExtendedDataClass[DEM_EXTENDED_DATA_CLASS_NUM] =
{
    { /* DemExtendedDataClass_0 */
        0u,
        11u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTC Mapping event */
static CONST(Dem_EventIdType,AUTOMATIC) DemDTCMapping[135] =
{
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29,
    30,
    31,
    32,
    33,
    34,
    35,
    36,
    37,
    38,
    39,
    40,
    41,
    42,
    43,
    44,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    63,
    64,
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90,
    91,
    92,
    93,
    94,
    95,
    96,
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121,
    122,
    123,
    124,
    125,
    126,
    127,
    128,
    129,
    130,
    131,
    132,
    133,
    134,
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTC 0-65535 */
static CONST(Dem_DTCType,AUTOMATIC) DemDTC[DEM_DTC_NUM] =
{
    { /* DemDTC_0x505547 */
        0x505547u, /* DemDtcValue */
        11u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        0,
    },
    { /* DemDTC_0x90E714 */
        0x90e714u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        1,
    },
    { /* DemDTC_0x95B219 */
        0x95b219u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        2,
    },
    { /* DemDTC_0x95B319 */
        0x95b319u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        3,
    },
    { /* DemDTC_0x957011 */
        0x957011u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        4,
    },
    { /* DemDTC_0x957015 */
        0x957015u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        5,
    },
    { /* DemDTC_0x957911 */
        0x957911u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        6,
    },
    { /* DemDTC_0x957915 */
        0x957915u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        7,
    },
    { /* DemDTC_0x957A11 */
        0x957a11u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        8,
    },
    { /* DemDTC_0x957A15 */
        0x957a15u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        9,
    },
    { /* DemDTC_0x957E11 */
        0x957e11u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        10,
    },
    { /* DemDTC_0x957E15 */
        0x957e15u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        11,
    },
    { /* DemDTC_0x959011 */
        0x959011u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        12,
    },
    { /* DemDTC_0x959015 */
        0x959015u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        13,
    },
    { /* DemDTC_0x95A214 */
        0x95a214u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        14,
    },
    { /* DemDTC_0x95A301 */
        0x95a301u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        15,
    },
    { /* DemDTC_0x95A323 */
        0x95a323u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        16,
    },
    { /* DemDTC_0x95A324 */
        0x95a324u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        17,
    },
    { /* DemDTC_0x95A401 */
        0x95a401u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        18,
    },
    { /* DemDTC_0x95A771 */
        0x95a771u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        19,
    },
    { /* DemDTC_0x95A801 */
        0x95a801u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        20,
    },
    { /* DemDTC_0x95A813 */
        0x95a813u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        21,
    },
    { /* DemDTC_0x95A863 */
        0x95a863u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        22,
    },
    { /* DemDTC_0x95A901 */
        0x95a901u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        23,
    },
    { /* DemDTC_0x95A913 */
        0x95a913u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        24,
    },
    { /* DemDTC_0x95A963 */
        0x95a963u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        25,
    },
    { /* DemDTC_0x95AA11 */
        0x95aa11u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        26,
    },
    { /* DemDTC_0x95AA12 */
        0x95aa12u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        27,
    },
    { /* DemDTC_0x95AA13 */
        0x95aa13u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        28,
    },
    { /* DemDTC_0x95AB11 */
        0x95ab11u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        29,
    },
    { /* DemDTC_0x95AB12 */
        0x95ab12u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        30,
    },
    { /* DemDTC_0x95AB13 */
        0x95ab13u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        31,
    },
    { /* DemDTC_0x95AC11 */
        0x95ac11u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        32,
    },
    { /* DemDTC_0x95AC12 */
        0x95ac12u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        33,
    },
    { /* DemDTC_0x95AC13 */
        0x95ac13u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        34,
    },
    { /* DemDTC_0x95AD11 */
        0x95ad11u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        35,
    },
    { /* DemDTC_0x95AD12 */
        0x95ad12u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        36,
    },
    { /* DemDTC_0x95AD13 */
        0x95ad13u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        37,
    },
    { /* DemDTC_0x95AE11 */
        0x95ae11u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        38,
    },
    { /* DemDTC_0x95AE12 */
        0x95ae12u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        39,
    },
    { /* DemDTC_0x95AE13 */
        0x95ae13u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        40,
    },
    { /* DemDTC_0x95AF11 */
        0x95af11u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        41,
    },
    { /* DemDTC_0x95AF12 */
        0x95af12u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        42,
    },
    { /* DemDTC_0x95AF13 */
        0x95af13u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        43,
    },
    { /* DemDTC_0x95B011 */
        0x95b011u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        44,
    },
    { /* DemDTC_0x95B012 */
        0x95b012u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        45,
    },
    { /* DemDTC_0x95B013 */
        0x95b013u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        46,
    },
    { /* DemDTC_0x95B111 */
        0x95b111u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        47,
    },
    { /* DemDTC_0x95B112 */
        0x95b112u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        48,
    },
    { /* DemDTC_0x95B113 */
        0x95b113u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        49,
    },
    { /* DemDTC_0x95B211 */
        0x95b211u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        50,
    },
    { /* DemDTC_0x95B215 */
        0x95b215u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        51,
    },
    { /* DemDTC_0x95B311 */
        0x95b311u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        52,
    },
    { /* DemDTC_0x95B315 */
        0x95b315u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        53,
    },
    { /* DemDTC_0x95B411 */
        0x95b411u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        54,
    },
    { /* DemDTC_0x95B415 */
        0x95b415u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        55,
    },
    { /* DemDTC_0x95D096 */
        0x95d096u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        56,
    },
    { /* DemDTC_0x95D196 */
        0x95d196u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        57,
    },
    { /* DemDTC_0x95D296 */
        0x95d296u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        58,
    },
    { /* DemDTC_0x95D309 */
        0x95d309u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        59,
    },
    { /* DemDTC_0x95D511 */
        0x95d511u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        60,
    },
    { /* DemDTC_0x95D512 */
        0x95d512u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        61,
    },
    { /* DemDTC_0x95B419 */
        0x95b419u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        62,
    },
    { /* DemDTC_0x960221 */
        0x960221u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        63,
    },
    { /* DemDTC_0x961021 */
        0x961021u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        64,
    },
    { /* DemDTC_0x961121 */
        0x961121u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        65,
    },
    { /* DemDTC_0x961221 */
        0x961221u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        66,
    },
    { /* DemDTC_0x961321 */
        0x961321u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        67,
    },
    { /* DemDTC_0x961421 */
        0x961421u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        68,
    },
    { /* DemDTC_0x961521 */
        0x961521u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        69,
    },
    { /* DemDTC_0x961621 */
        0x961621u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        70,
    },
    { /* DemDTC_0x968711 */
        0x968711u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        71,
    },
    { /* DemDTC_0x968712 */
        0x968712u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        72,
    },
    { /* DemDTC_0x968713 */
        0x968713u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        73,
    },
    { /* DemDTC_0x968721 */
        0x968721u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        74,
    },
    { /* DemDTC_0x968A11 */
        0x968a11u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        75,
    },
    { /* DemDTC_0x968A12 */
        0x968a12u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        76,
    },
    { /* DemDTC_0x968A13 */
        0x968a13u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        77,
    },
    { /* DemDTC_0x968A21 */
        0x968a21u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        78,
    },
    { /* DemDTC_0x96F511 */
        0x96f511u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        79,
    },
    { /* DemDTC_0x96F512 */
        0x96f512u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        80,
    },
    { /* DemDTC_0x96F513 */
        0x96f513u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        81,
    },
    { /* DemDTC_0x96F521 */
        0x96f521u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        82,
    },
    { /* DemDTC_0x96F611 */
        0x96f611u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        83,
    },
    { /* DemDTC_0x96F612 */
        0x96f612u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        84,
    },
    { /* DemDTC_0x96F613 */
        0x96f613u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        85,
    },
    { /* DemDTC_0x96F621 */
        0x96f621u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        86,
    },
    { /* DemDTC_0x982111 */
        0x982111u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        87,
    },
    { /* DemDTC_0x982115 */
        0x982115u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        88,
    },
    { /* DemDTC_0x982341 */
        0x982341u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        89,
    },
    { /* DemDTC_0x9DFB01 */
        0x9dfb01u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        90,
    },
    { /* DemDTC_0xC03788 */
        0xc03788u, /* DemDtcValue */
        2u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        91,
    },
    { /* DemDTC_0xD00246 */
        0xd00246u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        92,
    },
    { /* DemDTC_0xD00544 */
        0xd00544u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        93,
    },
    { /* DemDTC_0xE01449 */
        0xe01449u, /* DemDtcValue */
        7u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        94,
    },
    { /* DemDTC_0xE01498 */
        0xe01498u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        95,
    },
    { /* DemDTC_0xE10156 */
        0xe10156u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        96,
    },
    { /* DemDTC_0xE79982 */
        0xe79982u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        97,
    },
    { /* DemDTC_0xE79A82 */
        0xe79a82u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        98,
    },
    { /* DemDTC_0xED3E82 */
        0xed3e82u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        99,
    },
    { /* DemDTC_0xED3E83 */
        0xed3e83u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        100,
    },
    { /* DemDTC_0xED5A82 */
        0xed5a82u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        101,
    },
    { /* DemDTC_0xED5A83 */
        0xed5a83u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        102,
    },
    { /* DemDTC_0xED8B82 */
        0xed8b82u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        103,
    },
    { /* DemDTC_0xED8B83 */
        0xed8b83u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        104,
    },
    { /* DemDTC_0xED8C82 */
        0xed8c82u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        105,
    },
    { /* DemDTC_0xED8C83 */
        0xed8c83u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        106,
    },
    { /* DemDTC_0xEE0368 */
        0xee0368u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        107,
    },
    { /* DemDTC_0xEE0468 */
        0xee0468u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        108,
    },
    { /* DemDTC_0xEF0F86 */
        0xd6a114u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        109,
    },
    { /* DemDTC_0xEF1068 */
        0xd65d68u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        110,
    },
    { /* DemDTC_0xEF1168 */
        0xd66068u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        111,
    },
    { /* DemDTC_0xEF7001 */
        0xd66201u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        112,
    },
    { /* DemDTC_0xEF7101 */
        0xd66301u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        113,
    },
    { /* DemDTC_0xD66419 */
        0xd66419u, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        114,
    },
    { /* DemDTC_0xF0001C */
        0xf0001cu, /* DemDtcValue */
        10u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        115,
    },
    { /* DemDTC_0xF00362 */
        0xf00362u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        116,
    },
    { /* DemDTC_0xEF0E86 */
        0xd6a014u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        117,
    },
    { /* DemDTC_0xEF7201 */
        0xd6a201u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        118,
    },
    { /* DemDTC_0xD14B51 */
        0xd14b51u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        119,
    },
    { /* DemDTC_0xD14C51 */
        0xd14c51u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        120,
    },
    { /* DemDTC_0xEF1086 */
        0xd65f86u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        121,
    },
    { /* DemDTC_0xEF1186 */
        0xd66186u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        122,
    },
    { /* DemDTC_0xE30057 */
        0xe30057u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        123,
    },
    { /* DemDTC_0x961087 */
        0x961087u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        124,
    },
    { /* DemDTC_0x961187 */
        0x961187u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        125,
    },
    { /* DemDTC_0x961287 */
        0x961287u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        126,
    },
    { /* DemDTC_0x961387 */
        0x961387u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        127,
    },
    { /* DemDTC_0x961487 */
        0x961487u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        128,
    },
    { /* DemDTC_0x961587 */
        0x961587u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        129,
    },
    { /* DemDTC_0x961687 */
        0x961687u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        130,
    },
    { /* DemDTC_0x968787 */
        0x968787u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        131,
    },
    { /* DemDTC_0x968A87 */
        0x968a87u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        132,
    },
    { /* DemDTC_0x96F587 */
        0x96f587u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        133,
    },
    { /* DemDTC_0x96F687 */
        0x96f687u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
        1,
        134,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTCAttributes */
static CONST(Dem_DTCAttributesType,AUTOMATIC) DemDTCAttributes[DEM_DTC_ATTRIBUTES_NUM] =
{
    { /* DemDTCAttributes_Aged_1_UNCFM_127 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        1u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        126u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_127_UNCFM_127 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        127u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        126u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_4 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        4u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_6 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        6u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_12 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        12u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_15 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        15u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_20 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        20u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_24 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        24u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_26 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        26u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_126 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        126u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_255_UNCFM_127 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        255u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        126u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_Aged_127_UNCFM_127_WdgTout */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        127u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        126u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        TRUE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          Indicator Configuration
*******************************************************************************/
/*******************************************************************************
*                          Debounce Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
static CONST(Dem_DebounceCounterBasedClassType,AUTOMATIC) DemDebounceCounterBasedClass[DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM] =
{
    { /* DemDebounceCounte_BusOff */
        128u, /* DemDebounceCounterDecrementStepSize */
        4u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_1_1 */
        1u, /* DemDebounceCounterDecrementStepSize */
        1u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_3_3 */
        3u, /* DemDebounceCounterDecrementStepSize */
        3u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_3_6 */
        6u, /* DemDebounceCounterDecrementStepSize */
        3u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_4_4 */
        4u, /* DemDebounceCounterDecrementStepSize */
        4u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_6_6 */
        6u, /* DemDebounceCounterDecrementStepSize */
        6u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_7_7 */
        7u, /* DemDebounceCounterDecrementStepSize */
        7u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_8_8 */
        8u, /* DemDebounceCounterDecrementStepSize */
        8u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_9_9 */
        9u, /* DemDebounceCounterDecrementStepSize */
        9u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_13_13 */
        13u, /* DemDebounceCounterDecrementStepSize */
        13u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_25_25 */
        25u, /* DemDebounceCounterDecrementStepSize */
        25u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_127_127 */
        127u, /* DemDebounceCounterDecrementStepSize */
        127u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounter_127_128 */
        128u, /* DemDebounceCounterDecrementStepSize */
        127u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          Event Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
static CONST(Dem_EventParameterType,AUTOMATIC) DemEventParameter[DEM_EVENT_PARAMETER_NUM] =
{
    {  /* DemEventParameter_0x505547*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        0u, /* DemDTCRef */
        11u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x90E714*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        1u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        1u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B219*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        2u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        2u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B319*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        3u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        3u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957011*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        4u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        4u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957015*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        5u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        5u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957911*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        6u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        6u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957915*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        7u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        7u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957A11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        8u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        8u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957A15*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        9u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        9u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957E11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        10u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        10u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x957E15*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        11u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        11u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x959011*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        12u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        12u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x959015*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        13u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        13u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A214*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        14u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        14u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A301*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        15u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        15u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A323*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        16u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        16u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A324*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        17u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        17u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A401*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        18u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        18u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A771*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        19u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        19u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A801*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        20u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        20u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A813*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        21u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        21u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A863*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        22u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        22u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A901*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        23u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        23u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A913*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        24u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        24u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95A963*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        25u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        25u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AA11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        26u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        26u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        3u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AA12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        27u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        27u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        4u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AA13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        28u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        28u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        3u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AB11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        29u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        29u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        5u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AB12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        30u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        30u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        6u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AB13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        31u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        31u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        5u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AC11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        32u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        32u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        7u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AC12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        33u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        33u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        8u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AC13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        34u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        34u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        7u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AD11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        35u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        35u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        9u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AD12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        36u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        36u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        10u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AD13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        37u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        37u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        9u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AE11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        38u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        38u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        11u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AE12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        39u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        39u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        12u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AE13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        40u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        40u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        11u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AF11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        41u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        41u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        13u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AF12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        42u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        42u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        14u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95AF13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        43u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        43u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        13u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B011*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        44u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        44u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        15u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B012*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        45u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        45u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        16u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B013*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        46u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        46u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        15u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B111*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        47u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        47u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        17u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B112*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        48u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        48u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        18u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B113*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        49u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        49u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        17u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B211*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        50u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        50u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        19u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B215*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        51u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        51u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        20u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B311*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        52u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        52u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        25u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B315*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        53u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        53u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        26u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B411*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        54u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        54u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        27u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B415*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        55u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        55u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        28u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95D096*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        56u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        56u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95D196*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        57u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        57u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95D296*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        58u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        58u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95D309*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        59u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        59u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95D511*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        60u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        60u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95D512*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        61u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        61u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x95B419*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        62u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        62u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x960221*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        63u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        63u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961021*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        64u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        64u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961121*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        65u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        65u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961221*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        66u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        66u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961321*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        67u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        67u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961421*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        68u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        68u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961521*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        69u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        69u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961621*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        70u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        70u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968711*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        71u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        71u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        29u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968712*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        72u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        72u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        30u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968713*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        73u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        73u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        29u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968721*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        74u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        74u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968A11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        75u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        75u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        31u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968A12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        76u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        76u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        32u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968A13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        77u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        77u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        31u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968A21*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        78u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        78u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F511*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        79u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        79u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        33u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F512*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        80u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        80u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        34u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F513*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        81u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        81u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        33u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F521*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        82u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        82u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F611*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        83u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        83u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        35u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F612*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        84u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        84u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        36u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F613*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        85u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        85u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        35u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F621*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        86u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        86u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x982111*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        87u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        87u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        22u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x982115*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        88u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        88u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        22u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x982341*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        89u, /* DemDTCRef */
        10u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        89u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x9DFB01*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        90u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        90u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC03788*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        91u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        91u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_BSW, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        23u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD00246*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        92u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        92u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD00544*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        93u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        93u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xE01449*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        94u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        94u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xE01498*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        95u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        95u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xE10156*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        96u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        96u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xE79982*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        97u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        97u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        37u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xE79A82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        98u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        98u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        37u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED3E82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        99u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        99u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED3E83*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        100u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        100u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED5A82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        101u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        101u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        37u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED5A83*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        102u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        102u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        37u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED8B82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        103u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        103u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        37u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED8B83*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        104u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        104u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        37u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED8C82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        105u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        105u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        40u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xED8C83*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        106u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        106u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        40u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEE0368*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        107u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        107u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        24u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEE0468*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        108u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        108u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        10u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        38u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF0F86*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        109u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        109u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF1068*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        110u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        110u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF1168*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        111u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        111u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF7001*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        112u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        112u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF7101*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        113u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        113u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD66419*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        114u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        114u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xF0001C*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        115u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        115u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        24u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xF00362*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        116u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        116u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        10u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        39u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF0E86*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        117u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        117u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF7201*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        118u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        118u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD14B51*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        119u, /* DemDTCRef */
        11u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        119u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD14C51*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        120u, /* DemDTCRef */
        11u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        120u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF1086*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        121u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        121u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xEF1186*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        122u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        122u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xE30057*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        123u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        123u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961087*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        124u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        124u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961187*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        125u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        125u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961287*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        126u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        126u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961387*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        127u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        127u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961487*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        128u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        128u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961587*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        129u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        129u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x961687*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        130u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        130u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968787*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        131u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        131u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x968A87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        132u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        132u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F587*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        133u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        133u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x96F687*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        134u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        134u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        3u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          Memory Configuration
*******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemPrimaryMemory 1-1 */
static VAR(Dem_EventMemEntryType,AUTOMATIC) DemPrimaryMemory[DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

/* Dem_EventMemEntryType DemUserDefinedMemory<Mem/Name>[Mem/DemMaxNumberEventEntryUserDefined]; */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_MemDestConfigType,AUTOMATIC) DemMemDestCfg[DEM_MEM_DEST_TOTAL_NUM] =
{
    /* DemPrimaryMemory */
    {
        DemPrimaryMemory,
        DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) DemNvRamBlockId[DEM_NVRAM_BLOCKID_NUM] =
{
    NvMBlock_EventEntryPrimary_1, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_2, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_3, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_4, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_5, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_6, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_7, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_8, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_9, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_10, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_11, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_12, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_13, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_14, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_15, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_16, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_17, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_18, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_19, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_20, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_21, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_22, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_23, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_24, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_25, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_26, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_27, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_28, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_29, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_30, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_31, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_32, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_33, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_34, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_35, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_36, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_37, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_38, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_39, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_40, /* DemNvRamBlockIdRef  */
    NvMBlock_UDS_InternalData, /* DemNvRamBlockIdRef  */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          OBD Configuration
*******************************************************************************/

/*******************************************************************************
*                          J1939 Configuration
*******************************************************************************/
/*******************************************************************************
*                          PB DemConfigSet Configuration
*******************************************************************************/
#define DEM_START_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
CONST(Dem_ConfigType, AUTOMATIC) DemPbCfg =
{
    NULL_PTR,
    DemDTC,
    DemDTCAttributes,
    DemDebounceCounterBasedClass,
    NULL_PTR,
    NULL_PTR,
    DemEventParameter,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    DemDTCMapping,
};
#define DEM_STOP_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

