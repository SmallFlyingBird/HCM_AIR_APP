/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef PLATFORM_MLD_TYPESDEF_H_
#define PLATFORM_MLD_TYPESDEF_H_

/**
*   @file
*
*   @internal
*   @addtogroup Platform_Mld
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_CfgDefines.h"
#include "Platform_Types.h"
#include "IntCtrl_Lld_TypesDef.h"
#include "System_Lld_CfgDefines.h"
#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1HA0)
#include "Intm_Lld_CfgDefines.h"
#endif
#if defined(CPU_YTM32B1HA0)
#include "YTM32B1Hx_CM7_DSP_FP.h"
#elif defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1)
#include "YTM32B1Mx_CM33_DSP_FP.h"
#elif defined(CPU_YTM32B1MC0)
#include "YTM32B1Mx_CM33.h"
#endif
#if (PLATFORM_MPU_CFG == STD_ON)
#if (PLATFORM_MPU_TYPE == PLATFORM_MPU_M7)
#include "Mpu_Lld_M7_Types.h"
#elif (PLATFORM_MPU_TYPE == PLATFORM_MPU_M33)
#include "Mpu_Lld_M33_Types.h"
#endif
#endif
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PLATFORM_MLD_TYPESDEF_VENDOR_ID                       (180)
#define PLATFORM_MLD_TYPESDEF_AR_RELEASE_MAJOR_VERSION        (4)
#define PLATFORM_MLD_TYPESDEF_AR_RELEASE_MINOR_VERSION        (4)
#define PLATFORM_MLD_TYPESDEF_AR_RELEASE_REVISION_VERSION     (0)
#define PLATFORM_MLD_TYPESDEF_SW_MAJOR_VERSION                (2)
#define PLATFORM_MLD_TYPESDEF_SW_MINOR_VERSION                (3)
#define PLATFORM_MLD_TYPESDEF_SW_PATCH_VERSION                (0)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Lld_TypesDef header file are of the same vendor */
#if (PLATFORM_MLD_TYPESDEF_VENDOR_ID != PLATFORM_INTCTRL_LLD_TYPESDEF_TYPES_VENDOR_ID)
#error "Platform_Mld_TypesDef.c and IntCtrl_Lld_TypesDef.h have different vendor ids"
#endif

/* Check if current file and IntCtrl_Lld_TypesDef header file are of the same Software version */
#if ((PLATFORM_MLD_TYPESDEF_SW_MAJOR_VERSION != PLATFORM_INTCTRL_LLD_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_TYPESDEF_SW_MINOR_VERSION != PLATFORM_INTCTRL_LLD_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_TYPESDEF_SW_PATCH_VERSION != PLATFORM_INTCTRL_LLD_TYPESDEF_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld_TypesDef.h and IntCtrl_Lld_TypesDef.h are different"
#endif


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Lld_TypesDef header file are of the same vendor */
#if (PLATFORM_MLD_TYPESDEF_VENDOR_ID != PLATFORM_SYSTEM_LLD_CFG_DEFINES_TYPES_VENDOR_ID)
#error "Platform_Mld_TypesDef.c and System_Lld_TypesDef.h have different vendor ids"
#endif

/* Check if current file and System_Lld_TypesDef header file are of the same Software version */
#if ((PLATFORM_MLD_TYPESDEF_SW_MAJOR_VERSION != PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_TYPESDEF_SW_MINOR_VERSION != PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_TYPESDEF_SW_PATCH_VERSION != PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld_TypesDef.h and System_Lld_TypesDef.h are different"
#endif

/*==================================================================================================
 *                              TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/**
 * @internal
 * @brief          Configuration structure core-related interrupt requests.
 */
typedef struct
{
#if (SYSTEM_FPU_CFG == STD_ON)
    /** @brief Interrupt request types */
    System_Lld_IrqType Irq;
#endif
    /** @brief Enable interrupt request */
    boolean Enable;
} Platform_SystemIrqConfigType;

/**
 * @internal
 * @brief          Configuration structure system settings.
 */
#if (SYSTEM_FPU_CFG == STD_ON)
typedef struct
{
    /** @brief Configuration for system interrupts */
    const Platform_SystemIrqConfigType *SystemIrqs;
    /** @brief Number of system interrupts */
    uint8 SysIrqsCount;
    /** @brief AHB slave priority */
    boolean AhbSlavePriority;
} Platform_SystemConfigType;
#endif

/**
 * @internal
 * @brief          Configuration structure system settings.
 */
typedef struct
{
    /** @brief Target cores for the interrupt */
    const IntCtrl_Lld_GlobalRouteConfigType *IntRouteConfig;
} Platform_Mld_NonCoreConfigType;

#if (PLATFORM_INT_MONITOR == STD_ON)
/**
 * @internal
 * @brief          Configuration structure channel interrupt monitors.
 */
typedef struct
{
    Intm_Lld_MonitorType Monitor;
    IRQn_Type MonitoredIrq;
    uint32 AcceptedLatency;
} Platform_IntmChannelConfigType;

/**
 * @internal
 * @brief          Configuration structure generic interrupt monitors.
 */
typedef struct
{
    boolean EnableIntMonitor;
} Platform_IntmGenericConfigType;

/**
 * @internal
 * @brief          Configuration structure interrupt monitors.
 */
typedef struct
{
    /** @brief number of IntmChannelConfig */
    uint8 ChannelNum;
    /** @brief configuration for a logic channel */
    const Platform_IntmChannelConfigType *IntmChannelConfig;
    /** @brief configuration generic part, just en/disable */
    const Platform_IntmGenericConfigType *IntmGenericConfig;
} Platform_IntmConfigType;

#endif /* PLATFORM_INT_MONITOR == STD_ON */

/**
 * @internal
 * @brief          Configuration structure for PLATFORM IP wrapper.
 */
typedef struct
{
    /** @brief Configuration for interrupt control */
    const IntCtrl_Lld_CtrlConfigType *IntCtrlConfig;
#if (SYSTEM_FPU_CFG == STD_ON)
    /** @brief Configuration for system settings */
    const Platform_SystemConfigType *SystemConfig;
#endif

#if (PLATFORM_INT_MONITOR == STD_ON)
    /** @brief Configuration for non-core settings */
    const Platform_IntmConfigType *IntMonitorConfig;
#endif

#if (PLATFORM_MPU_CFG == STD_ON)
    /** @brief Configuration for MPU settings */
#if (PLATFORM_MPU_TYPE == PLATFORM_MPU_M33)
    const Mpu_Lld_M33_ConfigType *MpuConfig;
#elif (PLATFORM_MPU_TYPE == PLATFORM_MPU_M7)
    /** @brief Configuration for MPU settings */
    const Mpu_Lld_M7_ConfigType *MpuConfig;
#endif
#endif
} Platform_Mld_ConfigType;

#endif /* PLATFORM_MLD_TYPESDEF_H_ */

