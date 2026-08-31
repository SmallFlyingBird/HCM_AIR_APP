/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file System_Lld_CfgDefines.h
 * @brief 
 * 
 */


#ifndef SYSTEM_LLD_CFG_DEFINES_H_
#define SYSTEM_LLD_CFG_DEFINES_H_
/**
*   @file
*
*   @addtogroup System_LLD
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "System_Lld_DeviceRegisters.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_SYSTEM_LLD_CFG_DEFINES_TYPES_VENDOR_ID                    (180)
#define PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MAJOR_VERSION                   (2)
#define PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MINOR_VERSION                   (3)
#define PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_PATCH_VERSION                   (0)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Lld_DeviceRegisters header file are of the same vendor */
#if (PLATFORM_SYSTEM_LLD_CFG_DEFINES_TYPES_VENDOR_ID != PLATFORM_SYSTEM_LLD_DEVICE_REGISTERS_TYPES_VENDOR_ID)
    #error "System_Lld_Cfg.h and System_Lld_DeviceRegisters.h have different vendor ids"
#endif

/* Check if current file and System_Lld_DeviceRegisters header file are of the same Software version */
#if ((PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MAJOR_VERSION != PLATFORM_SYSTEM_LLD_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MINOR_VERSION != PLATFORM_SYSTEM_LLD_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_PATCH_VERSION != PLATFORM_SYSTEM_LLD_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of System_Lld_Cfg.h and System_Lld_DeviceRegisters.h are different"
#endif

/* Include headers for System_Lld_DeviceRegister.h   */

#define MCM_ISCR_FIDCE_SHIFT          CIM_FPUIE_FPIDCIE_SHIFT
#define MCM_ISCR_FIXCE_SHIFT          CIM_FPUIE_FPIXCIE_SHIFT
#define MCM_ISCR_FUFCE_SHIFT          CIM_FPUIE_FPUFCIE_SHIFT
#define MCM_ISCR_FOFCE_SHIFT          CIM_FPUIE_FPOFCIE_SHIFT
#define MCM_ISCR_FDZCE_SHIFT          CIM_FPUIE_FPDZCIE_SHIFT
#define MCM_ISCR_FIOCE_SHIFT          CIM_FPUIE_FPIOCIE_SHIFT

#define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
#define FPU_INEXACT_IRQ_SUPPORTED
#define FPU_UNDERFLOW_IRQ_SUPPORTED
#define FPU_OVERFLOW_IRQ_SUPPORTED
#define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
#define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Arm Cortex M33 */
#define SYSTEM_LLD_ARM_CORTEXM             (STD_ON)
#define SYSTEM_FPU_CFG                     (1)

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if ((SYSTEM_LLD_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
/**
* @brief      Enumeration listing available core-related interrupt requests
*             defined per each platform.
* @implements System_Lld_IrqType_typedef
*/
typedef enum
{
#ifdef FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    /** @brief FPU Input Denormal Interrupt */
    FPU_INPUT_DENORMAL_IRQ    = CIM_FPUIE_FPIDCIE_SHIFT,
#endif    
#ifdef FPU_INEXACT_IRQ_SUPPORTED
    /** @brief FPU Inexact Interrupt */
    FPU_INEXACT_IRQ           = CIM_FPUIE_FPIXCIE_SHIFT,
#endif
#ifdef FPU_UNDERFLOW_IRQ_SUPPORTED
    /** @brief FPU Underflow Interrupt */
    FPU_UNDERFLOW_IRQ         = CIM_FPUIE_FPUFCIE_SHIFT,
#endif
#ifdef FPU_OVERFLOW_IRQ_SUPPORTED
    /** @brief FPU Overflow Interrupt */
    FPU_OVERFLOW_IRQ          = CIM_FPUIE_FPOFCIE_SHIFT,
#endif
#ifdef FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    /** @brief FPU Divide-by-Zero Interrupt */
    FPU_DIVIDE_BY_ZERO_IRQ    = CIM_FPUIE_FPDZCIE_SHIFT,
#endif
#ifdef FPU_INVALID_OPERATION_IRQ_SUPPORTED
    /** @brief FPU Invalid Operation Interrupt */
    FPU_INVALID_OPERATION_IRQ = CIM_FPUIE_FPIOCIE_SHIFT,
#endif
#ifdef TCM_WRITE_ABORT_IRQ_SUPPORTED
    /** @brief TCM Write Abort Interrupt */
    TCM_WRITE_ABORT_IRQ       = MCM_ISCR_WABE_SHIFT
#endif
}System_Lld_IrqType;
#endif /* SYSTEM_LLD_ARM_CORTEXM == STD_ON */
#endif /* SYSTEM_LLD_CFG_DEFINES_H_ */

/** @} */

