/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-16 14:21:13>
 */
/*============================================================================*/


/*******************************************************************************
**                       Version  information                                 **
*******************************************************************************/
#define DEM_CFG_C_AR_MAJOR_VERSION   4U
#define DEM_CFG_C_AR_MINOR_VERSION   2U
#define DEM_CFG_C_AR_PATCH_VERSION   2U
#define DEM_CFG_C_SW_MAJOR_VERSION   1U
#define DEM_CFG_C_SW_MINOR_VERSION   0U
#define DEM_CFG_C_SW_PATCH_VERSION   0U
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Dem_CfgTypes.h"
#include "Dem_Internal.h"
#if(DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM_Cfg.h"
#endif
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (DEM_CFG_C_AR_MAJOR_VERSION != DEM_CFG_H_AR_MAJOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_AR_MINOR_VERSION != DEM_CFG_H_AR_MINOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_AR_PATCH_VERSION != DEM_CFG_H_AR_PATCH_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_SW_MAJOR_VERSION != DEM_CFG_H_SW_MAJOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_SW_MINOR_VERSION != DEM_CFG_H_SW_MINOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif

#if (DEM_CFG_C_AR_MAJOR_VERSION != DEM_CFGTYPES_H_AR_MAJOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_AR_MINOR_VERSION != DEM_CFGTYPES_H_AR_MINOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_AR_PATCH_VERSION != DEM_CFGTYPES_H_AR_PATCH_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_SW_MAJOR_VERSION != DEM_CFGTYPES_H_SW_MAJOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (DEM_CFG_C_SW_MINOR_VERSION != DEM_CFGTYPES_H_SW_MINOR_VERSION)
  #error "Dem_Cfg.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
*                          General Configuration
*******************************************************************************/


/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType DemReadOccctr(uint8* Buffer)
{
    *Buffer = InternalData.Occctr;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(DemDataElementClassTypes,AUTOMATIC) DemDataElementClass[DEM_DATA_ELEMENT_CLASS_NUM] =
{
    {
        1u,/*DemDataElementDataSize*/
        Rte_ReadData_SnapShot,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        DemReadOccctr,/*DemDataElementClass*/
    },
    {
        6u,/*DemDataElementDataSize*/
        Rte_ReadData_Timestamp,/*DemDataElementClass*/
    },
    {
        3u,/*DemDataElementDataSize*/
        Rte_ReadData_Odomete,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_ReadDataLVBatteryVoltage,/*DemDataElementClass*/
    },
    {
        2u,/*DemDataElementDataSize*/
        Rte_ReadData_VehicleSpeed,/*DemDataElementClass*/
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
    { /* DemOperationCycle_IG */
        FALSE,
        FALSE,
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
    0x3u,
    
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemEnableConditionGroup */
CONST(uint8,AUTOMATIC) DemEnableConditionGroup[DEM_ENABLE_CONDITION_GROUP_NUM][DEM_ENABLE_CONDITION_NUM_BYTE] =
{
    {0x5u,},
    {0x4u,},
    {0x3u,}
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
    { /* DemDidClass_0 */
        0x0u,
        0u,
        1u,
        1u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) DemDidClassRef[DEM_DID_CLASS_REF_TOTAL_NUM] =
{
    /* DemFreezeFrameClass_0 */
	0x0u
	
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameClassType,AUTOMATIC) DemFreezeFrameClass[DEM_FREEZE_FRAME_CLASS_NUM] =
{
    { /* DemFreezeFrameClass_0 DID*/
        1u,
        0u,
        1u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemFreezeFrameRecordClass */
CONST(Dem_FreezeFrameRecordClassType,AUTOMATIC) DemFreezeFrameRecordClass[DEM_FREEZE_FRAME_RECORD_CLASS_NUM] =
{
    { /* DemFreezeFrameRecordClass_0 */
        0u,                       /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_CONFIRMED,   /* DemFreezeFrameRecordTrigger */
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
	0x0u
	
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameRecNumClassType,AUTOMATIC) DemFreezeFrameRecNumClass[DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM] =
{
    { /* DemFreezeFrameRecNumClass_0 */
        0u,
        1u,
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
    { /* DemExtendedDataRecordClass_0 */
        0x1u,
        DEM_TRIGGER_ON_TEST_FAILED,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        1u,/*DemDataElementClassIndex*/
        5u,/*DemDataElementClassNum*/
        13u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8,AUTOMATIC) DemExtendedDataRecordClassRef[DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM] =
{
    /* DemExtendedDataClass_0 */
    0x0u
	
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
        1u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGroupOfDTC 0-255 */
CONST(uint32,AUTOMATIC) DemGroupOfDTC[DEM_GROUP_OF_DTC_NUM] =
{
    0x100u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTC 0-65535 */
CONST(Dem_DTCType,AUTOMATIC) DemDTC[DEM_DTC_NUM] =
{
    { /* DemDTC_B2980 */
        0xa98014u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2981 */
        0xa98114u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2982 */
        0xa98214u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2983 */
        0xa98314u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2984 */
        0xa98414u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2985 */
        0xa98514u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2986 */
        0xa98614u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2987 */
        0xa98713u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2988 */
        0xa98811u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2989 */
        0xa98913u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B298A */
        0xa98a11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B298B */
        0xa98b13u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B298C */
        0xa98c11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B298D */
        0xa98d13u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B298E */
        0xa98e11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B298F */
        0xa98f13u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2990 */
        0xa99011u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2991 */
        0xa99187u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2992 */
        0xa99287u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2993 */
        0xa99387u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2994 */
        0xa99487u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2995 */
        0xa99513u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2996 */
        0xa99611u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2997 */
        0xa9974bu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2998 */
        0xa99807u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B2999 */
        0xa99987u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B299A */
        0xa99a16u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B299B */
        0xa99b17u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B299C */
        0xa99c1cu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B299D */
        0xa99d16u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B299E */
        0xa99e05u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B299F */
        0xa99f17u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A0 */
        0xa9a016u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A1 */
        0xa9a117u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A2 */
        0xa9a215u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A3 */
        0xa9a305u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A4 */
        0xa9a417u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A5 */
        0xa9a551u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A6 */
        0xa9a617u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A7 */
        0xa9a716u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A8 */
        0xa9a805u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29A9 */
        0xa9a919u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U310016 */
        0xf10016u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U310017 */
        0xf10017u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U30DC87 */
        0xf0dc87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U32FC87 */
        0xf2fc87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U32AC87 */
        0xf2ac87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U30DC83 */
        0xf0dc83u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U30DC82 */
        0xf0dc82u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_U101F88 */
        0xd01f88u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29AA */
        0xa9aa11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_B29AB */
        0xa9ab13u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        1u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTCAttributes */
CONST(Dem_DTCAttributesType,AUTOMATIC) DemDTCAttributes[DEM_DTC_ATTRIBUTES_NUM] =
{
    { /* DemDTCAttributes_0 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        TRUE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        DEM_FREEZE_FRAME_INVALID, /* DemFreezeFrameClassRef  */
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
CONST(Dem_DebounceCounterBasedClassType,AUTOMATIC) DemDebounceCounterBasedClass[DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM] =
{
    { /* DemDebounceCounterBasedClass_0 */
        1u, /* DemDebounceCounterDecrementStepSize */
        1u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        1, /* DemDebounceCounterFailedThreshold */
        -1, /* DemDebounceCounterPassedThreshold */
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
CONST(Dem_EventParameterType,AUTOMATIC) DemEventParameter[DEM_EVENT_PARAMETER_NUM] =
{
    {  /* Low_Beam_BIN_resistor*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        0u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* High_Beam_BIN_resistor*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        1u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* FogOrCorner_BIN_resistor*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        2u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* DRLOrTI_NTC_resistor*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        3u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* FogOrCorner_NTC_resistor*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        4u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* High_Beam_NTC_resistor*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        5u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Low_Beam_NTC_resistor*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        6u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* High_Beam_Led_open*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        7u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* High_Beam_Led_short*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        8u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* Low_Beam_Led_open*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        9u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Low_Beam_Led_short*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        10u, /* DemDTCRef */
        10u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* FogOrCorner_Led_open*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        11u, /* DemDTCRef */
        11u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* FogOrCorner_Led_short*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        12u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DRLOrPO_Led_open*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        13u, /* DemDTCRef */
        13u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DRLOrPO_Led_short*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        14u, /* DemDTCRef */
        14u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* TL_Led_open*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        15u, /* DemDTCRef */
        15u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* TL_Led_short*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        16u, /* DemDTCRef */
        16u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* BUCK1Low_Beam_lost_Com*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        17u, /* DemDTCRef */
        17u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* BUCK2High_Beam_lost_Com*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        18u, /* DemDTCRef */
        18u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DRLOrPO_led_driver_lost_Com*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        19u, /* DemDTCRef */
        19u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* TL_led_driver_lost_Com*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        20u, /* DemDTCRef */
        20u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Leveling_motor_open_circuit*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        21u, /* DemDTCRef */
        21u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Leveling_motor_short_circuit*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        22u, /* DemDTCRef */
        22u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Leveling_motor_ThermalShutdown*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        23u, /* DemDTCRef */
        23u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* Leveling_motor_stall*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        24u, /* DemDTCRef */
        24u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Leveling_motor_driver_lost_Com*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        25u, /* DemDTCRef */
        25u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* SBC_input_undervoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        26u, /* DemDTCRef */
        26u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* SBC_input_overvoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        27u, /* DemDTCRef */
        27u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* DEM5VUnderOrOvervoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        28u, /* DemDTCRef */
        28u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* BUCK1_V5A_undervoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        29u, /* DemDTCRef */
        29u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* BUCK1_driver*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        30u, /* DemDTCRef */
        30u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* BUCK1_COMP_overvoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        31u, /* DemDTCRef */
        31u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* BUCK1_outputLow_Beam_undervoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        32u, /* DemDTCRef */
        32u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* BUCK1_outputLow_Beam_overvoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        33u, /* DemDTCRef */
        33u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* BUCK2_V5A_undervoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        34u, /* DemDTCRef */
        34u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* BUCK2_driver*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        35u, /* DemDTCRef */
        35u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* BUCK2_COMP_overvoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        36u, /* DemDTCRef */
        36u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Program_flow*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        37u, /* DemDTCRef */
        37u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Boost_ouput_overvoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        38u, /* DemDTCRef */
        38u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Boost_ouput_undervoltage*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        39u, /* DemDTCRef */
        39u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* Boost_driver*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        40u, /* DemDTCRef */
        40u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* HideSide_ouput_overcurrent*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        41u, /* DemDTCRef */
        41u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* KL15_voltage_less_than_7V*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        42u, /* DemDTCRef */
        42u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* KL15_voltage_more_than_18V*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        43u, /* DemDTCRef */
        43u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* Lost_Com_with_BCM_FLM0xDC*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        44u, /* DemDTCRef */
        44u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
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
    {  /* Lost_Com_with_BGW_LI0x2FC*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        45u, /* DemDTCRef */
        45u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
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
    {  /* Lost_Com_with_CDC_HU_070x2AC*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        46u, /* DemDTCRef */
        46u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
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
    {  /* CRC_with_BCM_FLM0xDC*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        47u, /* DemDTCRef */
        47u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
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
    {  /* Message_counter_witth_BCM_FLM0xDC*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        48u, /* DemDTCRef */
        48u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
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
    {  /* CAN_bus_off*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        49u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_BSW, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* HideSide_ouput_shorterror*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        50u, /* DemDTCRef */
        49u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
    {  /* HideSide_ouput_openerror*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        51u, /* DemDTCRef */
        50u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
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
VAR(Dem_EventMemEntryType,AUTOMATIC) DemPrimaryMemory[DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY];
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
    NvMBlock_DemEntry_0, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_1, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_2, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_3, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_4, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_5, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_6, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_7, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_8, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_9, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_10, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_11, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_12, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_13, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_14, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_15, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_16, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_17, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_18, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_19, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_20, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_21, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_22, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_23, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_24, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_25, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_26, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_27, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_28, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_29, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_30, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_31, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_32, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_33, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_34, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_35, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_36, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_37, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_DemVersion, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEntry_OBD, /* DemNvRamBlockIdRef  */
    NvMBlock_DemEventInfo, /* DemNvRamBlockIdRef  */
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
#define DEM_START_CONST_PBCFG_ROOT
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
};
#define DEM_STOP_CONST_PBCFG_ROOT
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

