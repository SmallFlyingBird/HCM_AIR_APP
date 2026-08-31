/**
 * @file    Mpu_Lld_M33.C
 * @version V2.3.0
 *
 * @brief   YUNTU Mpu_Lld_M33 module interface
 * @details API implementation for Mpu_Lld_M33 driver
 *
 * @addtogroup MPU_LLD_M33_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Cortex M33 MPU
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                         INCLUDE FILES
=================================================================================================*/
#include "Mpu_Lld_M33.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MPU_LLD_M33_VENDOR_ID_C                      (180)
#define MPU_LLD_M33_AR_RELEASE_MAJOR_VERSION_C       (4)
#define MPU_LLD_M33_AR_RELEASE_MINOR_VERSION_C       (4)
#define MPU_LLD_M33_AR_RELEASE_REVISION_VERSION_C    (0)
#define MPU_LLD_M33_SW_MAJOR_VERSION_C               (2)
#define MPU_LLD_M33_SW_MINOR_VERSION_C               (3)
#define MPU_LLD_M33_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mpu_Lld_M33.c and Mpu_Lld_M33.h are of the same vendor */
#if (MPU_LLD_M33_VENDOR_ID_C != MPU_LLD_M33_VENDOR_ID)
#error "Mpu_Lld_M33.c and Mpu_Lld_M33.h have different vendor ids"
#endif

/* Check if Mpu_Lld_M33.c and Mpu_Lld_M33.h are of the same Autosar version */
#if ((MPU_LLD_M33_AR_RELEASE_MAJOR_VERSION_C != MPU_LLD_M33_AR_RELEASE_MAJOR_VERSION) || \
     (MPU_LLD_M33_AR_RELEASE_MINOR_VERSION_C != MPU_LLD_M33_AR_RELEASE_MINOR_VERSION) || \
     (MPU_LLD_M33_AR_RELEASE_REVISION_VERSION_C != MPU_LLD_M33_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mpu_Lld_M33.c and Mpu_Lld_M33.h are different"
#endif

/* Check if Mpu_Lld_M33.c and Mpu_Lld_M33.h are of the same Software version */
#if ((MPU_LLD_M33_SW_MAJOR_VERSION_C != MPU_LLD_M33_SW_MAJOR_VERSION) || \
     (MPU_LLD_M33_SW_MINOR_VERSION_C != MPU_LLD_M33_SW_MINOR_VERSION) || \
     (MPU_LLD_M33_SW_PATCH_VERSION_C != MPU_LLD_M33_SW_PATCH_VERSION))
#error "Software Version Numbers of Mpu_Lld_M33.c and Mpu_Lld_M33.h are different"
#endif

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"    /* NOSONAR, memory map */
/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       This function initializes the Cortex M33 MPU.
 * @param[in]   MpuConfig The pointer to the MPU configuration structure.
 * @return      void
 */
PLATFORM_FUNC void Mpu_Lld_M33_Init(const Mpu_Lld_M33_ConfigType *MpuConfig)
{
    uint8 Index;
    uint8 MpuRegionCount = (uint8)(MPU->TYPE >> MPU_TYPE_DREGION_Pos);
    uint32 MpuEnableMask = 0U;

    /* Disable MPU */
    ARM_MPU_Disable();
    /* Disable all regions. */
    for (Index = 0U; Index < MpuRegionCount; ++Index)
    {
        ARM_MPU_ClrRegion(Index);
    }
    /* Initialize the memory attributes */
    for (Index = 0U; Index < MpuConfig->AttributeCount; ++Index)
    {
        ARM_MPU_SetMemAttr(MpuConfig->AttributeConfig[Index].AttributeIndex, MpuConfig->AttributeConfig[Index].Attribute);
    }
    /* Load the region configuration */
    for (Index = 0U; Index < MpuConfig->RegionCount; ++Index)
    {
        ARM_MPU_SetRegion
        (
            MpuConfig->RegionConfig[Index].RegionIndex,
            MpuConfig->RegionConfig[Index].Region.RBAR,
            MpuConfig->RegionConfig[Index].Region.RLAR
        );
    }
    /* Enable MPU with MemManage fault. */
    if (TRUE == MpuConfig->DefaultMapEn)
    {
        MpuEnableMask |= MPU_CTRL_PRIVDEFENA_Msk;
    }
    if (TRUE == MpuConfig->RunHFNMIEn)
    {
        MpuEnableMask |= MPU_CTRL_HFNMIENA_Msk;
    }
    /* Enable MPU */
    ARM_MPU_Enable(MpuEnableMask);
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"    /* NOSONAR, memory map */

#ifdef __cplusplus
}
#endif

/** @} */

