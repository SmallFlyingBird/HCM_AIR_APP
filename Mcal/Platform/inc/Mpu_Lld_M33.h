/**
 * @file    Mpu_Lld_M33.h
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

#ifndef MPU_LLD_M33_H
#define MPU_LLD_M33_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Mpu_Lld_M33_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MPU_LLD_M33_VENDOR_ID                      (180)
#define MPU_LLD_M33_MODULE_ID              (121)
#define MPU_LLD_M33_AR_RELEASE_MAJOR_VERSION       (4)
#define MPU_LLD_M33_AR_RELEASE_MINOR_VERSION       (4)
#define MPU_LLD_M33_AR_RELEASE_REVISION_VERSION    (0)
#define MPU_LLD_M33_SW_MAJOR_VERSION               (2)
#define MPU_LLD_M33_SW_MINOR_VERSION               (3)
#define MPU_LLD_M33_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mpu_Lld_M33.h and Mpu_Lld_M33_Types.h are of the same vendor */
#if (MPU_LLD_M33_VENDOR_ID != MPU_LLD_M33_TYPES_VENDOR_ID)
#error "Mpu_Lld_M33.h and Mpu_Lld_M33_Types.h have different vendor ids"
#endif
/* Check if Mpu_Lld_M33.h and Mpu_Lld_M33_Types.h are of the same Autosar version */
#if ((MPU_LLD_M33_AR_RELEASE_MAJOR_VERSION != MPU_LLD_M33_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MPU_LLD_M33_AR_RELEASE_MINOR_VERSION != MPU_LLD_M33_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MPU_LLD_M33_AR_RELEASE_REVISION_VERSION != MPU_LLD_M33_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mpu_Lld_M33.h and Mpu_Lld_M33_Types.h are different"
#endif
/* Check if Mpu_Lld_M33.h and Mpu_Lld_M33_Types.h are of the same software version */
#if ((MPU_LLD_M33_SW_MAJOR_VERSION != MPU_LLD_M33_TYPES_SW_MAJOR_VERSION) || \
     (MPU_LLD_M33_SW_MINOR_VERSION != MPU_LLD_M33_TYPES_SW_MINOR_VERSION) || \
     (MPU_LLD_M33_SW_PATCH_VERSION != MPU_LLD_M33_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mpu_Lld_M33.h and Mpu_Lld_M33_Types.h are different"
#endif

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"  /* NOSONAR, memory map */

/**
 * @brief       This function initializes the Cortex M33 MPU.
 * @param[in]   MpuConfig The pointer to the MPU configuration structure.
 * @return      void
 */
PLATFORM_FUNC void Mpu_Lld_M33_Init(const Mpu_Lld_M33_ConfigType *MpuConfig);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"  /* NOSONAR, memory map */

#ifdef __cplusplus
}
#endif

#endif /* MPU_LLD_M33_H */

/** @} */

