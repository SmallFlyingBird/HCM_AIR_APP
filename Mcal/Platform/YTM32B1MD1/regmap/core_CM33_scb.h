/**
*   @file    core_CM33_scb.h
*   @version
*
*   @brief   AUTOSAR CM33_scb register map
*   @details Register map for CM33_SCB
*
*   @addtogroup core_CM33_scb_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : core_CM33_scb
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
/*==================================================================================================
==================================================================================================*/

#ifndef CORE_CM33_SCB_H
#define CORE_CM33_SCB_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CM33_SCB REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CM33_SCB_Peripheral_Access_Layer CM33_SCB Peripheral Access Layer
 * @{
 */


/** CM33_SCB - Size of Registers Arrays */
#define CM33_SCB_CFSR_COUNT           (2)

/* CM33_SCB Register Layout Typedef */
typedef struct {
    uint32 Reserved0[2];                      /**< Reserved0, offset: 0x0000 */
    uint32 ACTLR;                              /**< Auxiliary Control Register, offset: 0x0008 */
    uint32 Reserved1[829];                      /**< Reserved1, offset: 0x000C */
    uint32 CPUID;                              /**< CPUID base Register, offset: 0x0D00 */
    uint32 ICSR;                               /**< Interrupt Control and Status Register, offset: 0x0D04 */
    uint32 VTOR;                               /**< Vector Table Offset Register, offset: 0x0D08 */
    uint32 AIRCR;                              /**< Application Interrupt and Reset Control Register, offset: 0x0D0C */
    uint32 SCR;                                /**< System Control Register, offset: 0x0D10 */
    uint32 CCR;                                /**< Configuration and Control Register, offset: 0x0D14 */
    uint32 SHPR1;                              /**< System Handler Priority Register 1, offset: 0x0D18 */
    uint32 SHPR2;                              /**< System Handler Priority Register 2, offset: 0x0D1C */
    uint32 SHPR3;                              /**< System Handler Priority Register 3, offset: 0x0D20 */
    uint32 SHCSR;                              /**< System Handler Control and State Register, offset: 0x0D24 */
    uint32 CFSR[2];                           /**< Configurable Fault Status Register, offset: 0x0D28 */
    uint32 HFSR;                               /**< Hard Fault Status Register, offset: 0x0D2C */
    uint32 DFSR;                               /**< Debug Fault Status Register, offset: 0x0D30 */
    uint32 MMAR;                               /**< MemManage Fault Address Register, offset: 0x0D34 */
    uint32 AFSR;                               /**< Auxiliary Fault Status Register, offset: 0x0D38 */
    uint32 Reserved2[18];                      /**< Reserved2, offset: 0x0D3C */
    uint32 CPACR;                              /**< Coprocessor Access Control Register, offset: 0x0D88 */
    uint32 Reserved3[106];                      /**< Reserved3, offset: 0x0D10 */
    uint32 FPCCR;                              /**< Floating-point Context Control Register, offset: 0x0F34 */
    uint32 FCAR;                               /**< Floating-point Context Address Register, offset: 0x0F38 */
    uint32 FDSCR;                              /**< Floating-point Default Status Control Register, offset: 0x0F3C */

} CM33_SCB_Type, *CM33_SCB_MemMapPtr;

/** Number of instances of the CM33_SCB module. */
#define CM33_SCB_INSTANCE_COUNT                        (1u)

/* CM33_SCB base address */
#define CM33_SCB_BASE_ADDR32                               (0xE000E000U)
#define CM33_SCB                                           ((volatile CM33_SCB_Type *)(CM33_SCB_BASE_ADDR32))

/** Array initializer of CM33_SCB peripheral base addresses */
#define CM33_SCB_BASE_ADDRS                                 { CM33_SCB_BASE_ADDR32 }
/** Array initializer of CM33_SCB peripheral base pointers */
#define CM33_SCB_BASE_PTRS                                  { CM33_SCB }

#define CM33_SCB_ACTLR_OFFSET32                             (0x0008U)                    /**< Offset for Auxiliary Control Register */
#define CM33_SCB_CPUID_OFFSET32                             (0x0D00U)                    /**< Offset for CPUID base Register */
#define CM33_SCB_ICSR_OFFSET32                              (0x0D04U)                    /**< Offset for Interrupt Control and Status Register */
#define CM33_SCB_VTOR_OFFSET32                              (0x0D08U)                    /**< Offset for Vector Table Offset Register */
#define CM33_SCB_AIRCR_OFFSET32                             (0x0D0CU)                    /**< Offset for Application Interrupt and Reset Control Register */
#define CM33_SCB_SCR_OFFSET32                               (0x0D10U)                    /**< Offset for System Control Register */
#define CM33_SCB_CCR_OFFSET32                               (0x0D14U)                    /**< Offset for Configuration and Control Register */
#define CM33_SCB_SHPR1_OFFSET32                             (0x0D18U)                    /**< Offset for System Handler Priority Register 1 */
#define CM33_SCB_SHPR2_OFFSET32                             (0x0D1CU)                    /**< Offset for System Handler Priority Register 2 */
#define CM33_SCB_SHPR3_OFFSET32                             (0x0D20U)                    /**< Offset for System Handler Priority Register 3 */
#define CM33_SCB_SHCSR_OFFSET32                             (0x0D24U)                    /**< Offset for System Handler Control and State Register */
#define CM33_SCB_CFSR_OFFSET32(x)                           (0x0D28U + ((x) * (4U)))     /**< Offset for Configurable Fault Status Register */
#define CM33_SCB_HFSR_OFFSET32                              (0x0D2CU)                    /**< Offset for Hard Fault Status Register */
#define CM33_SCB_DFSR_OFFSET32                              (0x0D30U)                    /**< Offset for Debug Fault Status Register */
#define CM33_SCB_MMAR_OFFSET32                              (0x0D34U)                    /**< Offset for MemManage Fault Address Register */
#define CM33_SCB_AFSR_OFFSET32                              (0x0D38U)                    /**< Offset for Auxiliary Fault Status Register */
#define CM33_SCB_CPACR_OFFSET32                             (0x0D88U)                    /**< Offset for Coprocessor Access Control Register */
#define CM33_SCB_FPCCR_OFFSET32                             (0x0F34U)                    /**< Offset for Floating-point Context Control Register */
#define CM33_SCB_FCAR_OFFSET32                              (0x0F38U)                    /**< Offset for Floating-point Context Address Register */
#define CM33_SCB_FDSCR_OFFSET32                             (0x0F3CU)                    /**< Offset for Floating-point Default Status Control Register */


/**
 * @addtogroup CM33_SCB Register Mask
 * @{
 */
/* CM33_SCB_ACTLR Register */
#define CM33_SCB_ACTLR_DISOOFP_MASK                             (0x200U)
#define CM33_SCB_ACTLR_DISOOFP_SHIFT                            (9U)
#define CM33_SCB_ACTLR_DISOOFP(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_ACTLR_DISOOFP_SHIFT)) & CM33_SCB_ACTLR_DISOOFP_MASK)
#define CM33_SCB_ACTLR_DISFPCA_MASK                             (0x100U)
#define CM33_SCB_ACTLR_DISFPCA_SHIFT                            (8U)
#define CM33_SCB_ACTLR_DISFPCA(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_ACTLR_DISFPCA_SHIFT)) & CM33_SCB_ACTLR_DISFPCA_MASK)
#define CM33_SCB_ACTLR_DISFOLD_MASK                             (0x4U)
#define CM33_SCB_ACTLR_DISFOLD_SHIFT                            (2U)
#define CM33_SCB_ACTLR_DISFOLD(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_ACTLR_DISFOLD_SHIFT)) & CM33_SCB_ACTLR_DISFOLD_MASK)
#define CM33_SCB_ACTLR_DISDEFWBUF_MASK                          (0x2U)
#define CM33_SCB_ACTLR_DISDEFWBUF_SHIFT                         (1U)
#define CM33_SCB_ACTLR_DISDEFWBUF(x)                            (((uint32)(((uint32)(x)) << CM33_SCB_ACTLR_DISDEFWBUF_SHIFT)) & CM33_SCB_ACTLR_DISDEFWBUF_MASK)
#define CM33_SCB_ACTLR_DISMCYCINT_MASK                          (0x1U)
#define CM33_SCB_ACTLR_DISMCYCINT_SHIFT                         (0U)
#define CM33_SCB_ACTLR_DISMCYCINT(x)                            (((uint32)(((uint32)(x)) << CM33_SCB_ACTLR_DISMCYCINT_SHIFT)) & CM33_SCB_ACTLR_DISMCYCINT_MASK)
/* CM33_SCB_CPUID Register */
#define CM33_SCB_CPUID_IMPLEMENTER_WIDTH                        (8)
#define CM33_SCB_CPUID_IMPLEMENTER_MASK                         (0xFF000000U)
#define CM33_SCB_CPUID_IMPLEMENTER_SHIFT                        (24U)
#define CM33_SCB_CPUID_IMPLEMENTER(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_CPUID_IMPLEMENTER_SHIFT)) & CM33_SCB_CPUID_IMPLEMENTER_MASK)
#define CM33_SCB_CPUID_VARIANT_WIDTH                            (4)
#define CM33_SCB_CPUID_VARIANT_MASK                             (0xF00000U)
#define CM33_SCB_CPUID_VARIANT_SHIFT                            (20U)
#define CM33_SCB_CPUID_VARIANT(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_CPUID_VARIANT_SHIFT)) & CM33_SCB_CPUID_VARIANT_MASK)
#define CM33_SCB_CPUID_PARTNO_WIDTH                             (12)
#define CM33_SCB_CPUID_PARTNO_MASK                              (0xFFF0U)
#define CM33_SCB_CPUID_PARTNO_SHIFT                             (4U)
#define CM33_SCB_CPUID_PARTNO(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_CPUID_PARTNO_SHIFT)) & CM33_SCB_CPUID_PARTNO_MASK)
#define CM33_SCB_CPUID_REVISION_WIDTH                           (4)
#define CM33_SCB_CPUID_REVISION_MASK                            (0xFU)
#define CM33_SCB_CPUID_REVISION_SHIFT                           (0U)
#define CM33_SCB_CPUID_REVISION(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_CPUID_REVISION_SHIFT)) & CM33_SCB_CPUID_REVISION_MASK)
/* CM33_SCB_ICSR Register */
#define CM33_SCB_ICSR_NMIPENDSET_MASK                           (0x80000000U)
#define CM33_SCB_ICSR_NMIPENDSET_SHIFT                          (31U)
#define CM33_SCB_ICSR_NMIPENDSET(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_ICSR_NMIPENDSET_SHIFT)) & CM33_SCB_ICSR_NMIPENDSET_MASK)
#define CM33_SCB_ICSR_PENDSVSET_MASK                            (0x10000000U)
#define CM33_SCB_ICSR_PENDSVSET_SHIFT                           (28U)
#define CM33_SCB_ICSR_PENDSVSET(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_ICSR_PENDSVSET_SHIFT)) & CM33_SCB_ICSR_PENDSVSET_MASK)
#define CM33_SCB_ICSR_PENDSVCLR_MASK                            (0x2000000U)
#define CM33_SCB_ICSR_PENDSVCLR_SHIFT                           (25U)
#define CM33_SCB_ICSR_PENDSVCLR(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_ICSR_PENDSVCLR_SHIFT)) & CM33_SCB_ICSR_PENDSVCLR_MASK)
#define CM33_SCB_ICSR_ISRPENDING_MASK                           (0x400000U)
#define CM33_SCB_ICSR_ISRPENDING_SHIFT                          (22U)
#define CM33_SCB_ICSR_ISRPENDING(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_ICSR_ISRPENDING_SHIFT)) & CM33_SCB_ICSR_ISRPENDING_MASK)
#define CM33_SCB_ICSR_VECTPENDING_WIDTH                         (6)
#define CM33_SCB_ICSR_VECTPENDING_MASK                          (0x3F000U)
#define CM33_SCB_ICSR_VECTPENDING_SHIFT                         (12U)
#define CM33_SCB_ICSR_VECTPENDING(x)                            (((uint32)(((uint32)(x)) << CM33_SCB_ICSR_VECTPENDING_SHIFT)) & CM33_SCB_ICSR_VECTPENDING_MASK)
#define CM33_SCB_ICSR_VECTACTIVE_WIDTH                          (6)
#define CM33_SCB_ICSR_VECTACTIVE_MASK                           (0x3FU)
#define CM33_SCB_ICSR_VECTACTIVE_SHIFT                          (0U)
#define CM33_SCB_ICSR_VECTACTIVE(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_ICSR_VECTACTIVE_SHIFT)) & CM33_SCB_ICSR_VECTACTIVE_MASK)
/* CM33_SCB_VTOR Register */
#define CM33_SCB_VTOR_TBLOFF_WIDTH                              (25)
#define CM33_SCB_VTOR_TBLOFF_MASK                               (0xFFFFFF80U)
#define CM33_SCB_VTOR_TBLOFF_SHIFT                              (7U)
#define CM33_SCB_VTOR_TBLOFF(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_VTOR_TBLOFF_SHIFT)) & CM33_SCB_VTOR_TBLOFF_MASK)
/* CM33_SCB_AIRCR Register */
#define CM33_SCB_AIRCR_VECTKEY_WIDTH                            (16)
#define CM33_SCB_AIRCR_VECTKEY_MASK                             (0xFFFF0000U)
#define CM33_SCB_AIRCR_VECTKEY_SHIFT                            (16U)
#define CM33_SCB_AIRCR_VECTKEY(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_AIRCR_VECTKEY_SHIFT)) & CM33_SCB_AIRCR_VECTKEY_MASK)
#define CM33_SCB_AIRCR_ENDIANNESS_MASK                          (0x8000U)
#define CM33_SCB_AIRCR_ENDIANNESS_SHIFT                         (15U)
#define CM33_SCB_AIRCR_ENDIANNESS(x)                            (((uint32)(((uint32)(x)) << CM33_SCB_AIRCR_ENDIANNESS_SHIFT)) & CM33_SCB_AIRCR_ENDIANNESS_MASK)
#define CM33_SCB_AIRCR_PRIGROUP_MASK                            (0x300U)
#define CM33_SCB_AIRCR_PRIGROUP_SHIFT                           (8U)
#define CM33_SCB_AIRCR_PRIGROUP(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_AIRCR_PRIGROUP_SHIFT)) & CM33_SCB_AIRCR_PRIGROUP_MASK)
#define CM33_SCB_AIRCR_SYSRESETREQ_MASK                         (0x4U)
#define CM33_SCB_AIRCR_SYSRESETREQ_SHIFT                        (2U)
#define CM33_SCB_AIRCR_SYSRESETREQ(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_AIRCR_SYSRESETREQ_SHIFT)) & CM33_SCB_AIRCR_SYSRESETREQ_MASK)
#define CM33_SCB_AIRCR_VECTCLRACTIVE_MASK                       (0x2U)
#define CM33_SCB_AIRCR_VECTCLRACTIVE_SHIFT                      (1U)
#define CM33_SCB_AIRCR_VECTCLRACTIVE(x)                         (((uint32)(((uint32)(x)) << CM33_SCB_AIRCR_VECTCLRACTIVE_SHIFT)) & CM33_SCB_AIRCR_VECTCLRACTIVE_MASK)
/* CM33_SCB_SCR Register */
#define CM33_SCB_SCR_SEVONPEND_MASK                             (0x10U)
#define CM33_SCB_SCR_SEVONPEND_SHIFT                            (4U)
#define CM33_SCB_SCR_SEVONPEND(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_SCR_SEVONPEND_SHIFT)) & CM33_SCB_SCR_SEVONPEND_MASK)
#define CM33_SCB_SCR_SLEEPDEEP_MASK                             (0x4U)
#define CM33_SCB_SCR_SLEEPDEEP_SHIFT                            (2U)
#define CM33_SCB_SCR_SLEEPDEEP(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_SCR_SLEEPDEEP_SHIFT)) & CM33_SCB_SCR_SLEEPDEEP_MASK)
#define CM33_SCB_SCR_SLEEPONEXIT_MASK                           (0x2U)
#define CM33_SCB_SCR_SLEEPONEXIT_SHIFT                          (1U)
#define CM33_SCB_SCR_SLEEPONEXIT(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_SCR_SLEEPONEXIT_SHIFT)) & CM33_SCB_SCR_SLEEPONEXIT_MASK)
/* CM33_SCB_CCR Register */
#define CM33_SCB_CCR_STKALIGN_MASK                              (0x200U)
#define CM33_SCB_CCR_STKALIGN_SHIFT                             (9U)
#define CM33_SCB_CCR_STKALIGN(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_CCR_STKALIGN_SHIFT)) & CM33_SCB_CCR_STKALIGN_MASK)
#define CM33_SCB_CCR_UNALIGN_TRP_MASK                           (0x8U)
#define CM33_SCB_CCR_UNALIGN_TRP_SHIFT                          (3U)
#define CM33_SCB_CCR_UNALIGN_TRP(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_CCR_UNALIGN_TRP_SHIFT)) & CM33_SCB_CCR_UNALIGN_TRP_MASK)
/* CM33_SCB_SHPR1 Register */
#define CM33_SCB_SHPR1_PRI_6_MASK                               (0xFF0000U)
#define CM33_SCB_SHPR1_PRI_6_SHIFT                              (16U)
#define CM33_SCB_SHPR1_PRI_6(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_SHPR1_PRI_6_SHIFT)) & CM33_SCB_SHPR1_PRI_6_MASK)
#define CM33_SCB_SHPR1_PRI_5_MASK                               (0xFF00U)
#define CM33_SCB_SHPR1_PRI_5_SHIFT                              (8U)
#define CM33_SCB_SHPR1_PRI_5(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_SHPR1_PRI_5_SHIFT)) & CM33_SCB_SHPR1_PRI_5_MASK)
#define CM33_SCB_SHPR1_PRI_4_MASK                               (0xFFU)
#define CM33_SCB_SHPR1_PRI_4_SHIFT                              (0U)
#define CM33_SCB_SHPR1_PRI_4(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_SHPR1_PRI_4_SHIFT)) & CM33_SCB_SHPR1_PRI_4_MASK)
/* CM33_SCB_SHPR2 Register */
#define CM33_SCB_SHPR2_PRI_11_MASK                              (0xFF000000U)
#define CM33_SCB_SHPR2_PRI_11_SHIFT                             (24U)
#define CM33_SCB_SHPR2_PRI_11(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_SHPR2_PRI_11_SHIFT)) & CM33_SCB_SHPR2_PRI_11_MASK)
/* CM33_SCB_SHPR3 Register */
#define CM33_SCB_SHPR3_PRI_15_MASK                              (0xFF000000U)
#define CM33_SCB_SHPR3_PRI_15_SHIFT                             (24U)
#define CM33_SCB_SHPR3_PRI_15(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_SHPR3_PRI_15_SHIFT)) & CM33_SCB_SHPR3_PRI_15_MASK)
#define CM33_SCB_SHPR3_PRI_14_MASK                              (0xFF0000U)
#define CM33_SCB_SHPR3_PRI_14_SHIFT                             (16U)
#define CM33_SCB_SHPR3_PRI_14(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_SHPR3_PRI_14_SHIFT)) & CM33_SCB_SHPR3_PRI_14_MASK)
/* CM33_SCB_SHCSR Register */
#define CM33_SCB_SHCSR_USGFAULTENA_MASK                         (0x40000U)
#define CM33_SCB_SHCSR_USGFAULTENA_SHIFT                        (18U)
#define CM33_SCB_SHCSR_USGFAULTENA(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_USGFAULTENA_SHIFT)) & CM33_SCB_SHCSR_USGFAULTENA_MASK)
#define CM33_SCB_SHCSR_BUSFAULTENA_MASK                         (0x20000U)
#define CM33_SCB_SHCSR_BUSFAULTENA_SHIFT                        (17U)
#define CM33_SCB_SHCSR_BUSFAULTENA(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_BUSFAULTENA_SHIFT)) & CM33_SCB_SHCSR_BUSFAULTENA_MASK)
#define CM33_SCB_SHCSR_MEMFAULTENA_MASK                         (0x10000U)
#define CM33_SCB_SHCSR_MEMFAULTENA_SHIFT                        (16U)
#define CM33_SCB_SHCSR_MEMFAULTENA(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_MEMFAULTENA_SHIFT)) & CM33_SCB_SHCSR_MEMFAULTENA_MASK)
#define CM33_SCB_SHCSR_SVCALLPENDED_MASK                        (0x8000U)
#define CM33_SCB_SHCSR_SVCALLPENDED_SHIFT                       (15U)
#define CM33_SCB_SHCSR_SVCALLPENDED(x)                          (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_SVCALLPENDED_SHIFT)) & CM33_SCB_SHCSR_SVCALLPENDED_MASK)
#define CM33_SCB_SHCSR_BUSFAULTPENDED_MASK                      (0x4000U)
#define CM33_SCB_SHCSR_BUSFAULTPENDED_SHIFT                     (14U)
#define CM33_SCB_SHCSR_BUSFAULTPENDED(x)                        (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_BUSFAULTPENDED_SHIFT)) & CM33_SCB_SHCSR_BUSFAULTPENDED_MASK)
#define CM33_SCB_SHCSR_MEMFAULTPENDED_MASK                      (0x2000U)
#define CM33_SCB_SHCSR_MEMFAULTPENDED_SHIFT                     (13U)
#define CM33_SCB_SHCSR_MEMFAULTPENDED(x)                        (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_MEMFAULTPENDED_SHIFT)) & CM33_SCB_SHCSR_MEMFAULTPENDED_MASK)
#define CM33_SCB_SHCSR_USGFAULTPENDED_MASK                      (0x1000U)
#define CM33_SCB_SHCSR_USGFAULTPENDED_SHIFT                     (12U)
#define CM33_SCB_SHCSR_USGFAULTPENDED(x)                        (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_USGFAULTPENDED_SHIFT)) & CM33_SCB_SHCSR_USGFAULTPENDED_MASK)
#define CM33_SCB_SHCSR_SYSTICKACT_MASK                          (0x800U)
#define CM33_SCB_SHCSR_SYSTICKACT_SHIFT                         (11U)
#define CM33_SCB_SHCSR_SYSTICKACT(x)                            (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_SYSTICKACT_SHIFT)) & CM33_SCB_SHCSR_SYSTICKACT_MASK)
#define CM33_SCB_SHCSR_PENDSVACT_MASK                           (0x400U)
#define CM33_SCB_SHCSR_PENDSVACT_SHIFT                          (10U)
#define CM33_SCB_SHCSR_PENDSVACT(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_PENDSVACT_SHIFT)) & CM33_SCB_SHCSR_PENDSVACT_MASK)
#define CM33_SCB_SHCSR_MONITORACT_MASK                          (0x100U)
#define CM33_SCB_SHCSR_MONITORACT_SHIFT                         (8U)
#define CM33_SCB_SHCSR_MONITORACT(x)                            (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_MONITORACT_SHIFT)) & CM33_SCB_SHCSR_MONITORACT_MASK)
#define CM33_SCB_SHCSR_SVCALLACT_MASK                           (0x80U)
#define CM33_SCB_SHCSR_SVCALLACT_SHIFT                          (7U)
#define CM33_SCB_SHCSR_SVCALLACT(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_SVCALLACT_SHIFT)) & CM33_SCB_SHCSR_SVCALLACT_MASK)
#define CM33_SCB_SHCSR_USGFAULTACT_MASK                         (0x8U)
#define CM33_SCB_SHCSR_USGFAULTACT_SHIFT                        (3U)
#define CM33_SCB_SHCSR_USGFAULTACT(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_USGFAULTACT_SHIFT)) & CM33_SCB_SHCSR_USGFAULTACT_MASK)
#define CM33_SCB_SHCSR_BUSFAULTACT_MASK                         (0x2U)
#define CM33_SCB_SHCSR_BUSFAULTACT_SHIFT                        (1U)
#define CM33_SCB_SHCSR_BUSFAULTACT(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_BUSFAULTACT_SHIFT)) & CM33_SCB_SHCSR_BUSFAULTACT_MASK)
#define CM33_SCB_SHCSR_MEMFAULTACT_MASK                         (0x1U)
#define CM33_SCB_SHCSR_MEMFAULTACT_SHIFT                        (0U)
#define CM33_SCB_SHCSR_MEMFAULTACT(x)                           (((uint32)(((uint32)(x)) << CM33_SCB_SHCSR_MEMFAULTACT_SHIFT)) & CM33_SCB_SHCSR_MEMFAULTACT_MASK)
/* CM33_SCB_CFSR Register */
#define CM33_SCB_CFSR_DIVBYZERO_MASK                            (0x2000000U)
#define CM33_SCB_CFSR_DIVBYZERO_SHIFT                           (25U)
#define CM33_SCB_CFSR_DIVBYZERO(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_DIVBYZERO_SHIFT)) & CM33_SCB_CFSR_DIVBYZERO_MASK)
#define CM33_SCB_CFSR_UNALIGNED_MASK                            (0x1000000U)
#define CM33_SCB_CFSR_UNALIGNED_SHIFT                           (24U)
#define CM33_SCB_CFSR_UNALIGNED(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_UNALIGNED_SHIFT)) & CM33_SCB_CFSR_UNALIGNED_MASK)
#define CM33_SCB_CFSR_NOCP_MASK                                 (0x80000U)
#define CM33_SCB_CFSR_NOCP_SHIFT                                (19U)
#define CM33_SCB_CFSR_NOCP(x)                                   (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_NOCP_SHIFT)) & CM33_SCB_CFSR_NOCP_MASK)
#define CM33_SCB_CFSR_INVPC_MASK                                (0x40000U)
#define CM33_SCB_CFSR_INVPC_SHIFT                               (18U)
#define CM33_SCB_CFSR_INVPC(x)                                  (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_INVPC_SHIFT)) & CM33_SCB_CFSR_INVPC_MASK)
#define CM33_SCB_CFSR_INVSTATE_MASK                             (0x20000U)
#define CM33_SCB_CFSR_INVSTATE_SHIFT                            (17U)
#define CM33_SCB_CFSR_INVSTATE(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_INVSTATE_SHIFT)) & CM33_SCB_CFSR_INVSTATE_MASK)
#define CM33_SCB_CFSR_UNDEFINSTR_MASK                           (0x10000U)
#define CM33_SCB_CFSR_UNDEFINSTR_SHIFT                          (16U)
#define CM33_SCB_CFSR_UNDEFINSTR(x)                             (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_UNDEFINSTR_SHIFT)) & CM33_SCB_CFSR_UNDEFINSTR_MASK)
#define CM33_SCB_CFSR_BFARVALID_MASK                            (0x8000U)
#define CM33_SCB_CFSR_BFARVALID_SHIFT                           (15U)
#define CM33_SCB_CFSR_BFARVALID(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_BFARVALID_SHIFT)) & CM33_SCB_CFSR_BFARVALID_MASK)
#define CM33_SCB_CFSR_LSPERR_MASK                               (0x2000U)
#define CM33_SCB_CFSR_LSPERR_SHIFT                              (13U)
#define CM33_SCB_CFSR_LSPERR(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_LSPERR_SHIFT)) & CM33_SCB_CFSR_LSPERR_MASK)
#define CM33_SCB_CFSR_STKERR_MASK                               (0x1000U)
#define CM33_SCB_CFSR_STKERR_SHIFT                              (12U)
#define CM33_SCB_CFSR_STKERR(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_STKERR_SHIFT)) & CM33_SCB_CFSR_STKERR_MASK)
#define CM33_SCB_CFSR_UNSTKERR_MASK                             (0x800U)
#define CM33_SCB_CFSR_UNSTKERR_SHIFT                            (11U)
#define CM33_SCB_CFSR_UNSTKERR(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_UNSTKERR_SHIFT)) & CM33_SCB_CFSR_UNSTKERR_MASK)
#define CM33_SCB_CFSR_IMPRECISERR_MASK                          (0x400U)
#define CM33_SCB_CFSR_IMPRECISERR_SHIFT                         (10U)
#define CM33_SCB_CFSR_IMPRECISERR(x)                            (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_IMPRECISERR_SHIFT)) & CM33_SCB_CFSR_IMPRECISERR_MASK)
#define CM33_SCB_CFSR_PRECISERR_MASK                            (0x200U)
#define CM33_SCB_CFSR_PRECISERR_SHIFT                           (9U)
#define CM33_SCB_CFSR_PRECISERR(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_PRECISERR_SHIFT)) & CM33_SCB_CFSR_PRECISERR_MASK)
#define CM33_SCB_CFSR_IBUSERR_MASK                              (0x100U)
#define CM33_SCB_CFSR_IBUSERR_SHIFT                             (8U)
#define CM33_SCB_CFSR_IBUSERR(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_IBUSERR_SHIFT)) & CM33_SCB_CFSR_IBUSERR_MASK)
#define CM33_SCB_CFSR_MMARVALID_MASK                            (0x80U)
#define CM33_SCB_CFSR_MMARVALID_SHIFT                           (7U)
#define CM33_SCB_CFSR_MMARVALID(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_MMARVALID_SHIFT)) & CM33_SCB_CFSR_MMARVALID_MASK)
#define CM33_SCB_CFSR_MLSPERR_MASK                              (0x20U)
#define CM33_SCB_CFSR_MLSPERR_SHIFT                             (5U)
#define CM33_SCB_CFSR_MLSPERR(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_MLSPERR_SHIFT)) & CM33_SCB_CFSR_MLSPERR_MASK)
#define CM33_SCB_CFSR_MSTKERR_MASK                              (0x10U)
#define CM33_SCB_CFSR_MSTKERR_SHIFT                             (4U)
#define CM33_SCB_CFSR_MSTKERR(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_MSTKERR_SHIFT)) & CM33_SCB_CFSR_MSTKERR_MASK)
#define CM33_SCB_CFSR_MUNSTKERR_MASK                            (0x8U)
#define CM33_SCB_CFSR_MUNSTKERR_SHIFT                           (3U)
#define CM33_SCB_CFSR_MUNSTKERR(x)                              (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_MUNSTKERR_SHIFT)) & CM33_SCB_CFSR_MUNSTKERR_MASK)
#define CM33_SCB_CFSR_DACCVIOL_MASK                             (0x2U)
#define CM33_SCB_CFSR_DACCVIOL_SHIFT                            (1U)
#define CM33_SCB_CFSR_DACCVIOL(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_DACCVIOL_SHIFT)) & CM33_SCB_CFSR_DACCVIOL_MASK)
#define CM33_SCB_CFSR_IACCVIOL_MASK                             (0x1U)
#define CM33_SCB_CFSR_IACCVIOL_SHIFT                            (0U)
#define CM33_SCB_CFSR_IACCVIOL(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_CFSR_IACCVIOL_SHIFT)) & CM33_SCB_CFSR_IACCVIOL_MASK)
/* CM33_SCB_HFSR Register */
#define CM33_SCB_HFSR_DEBUGEVT_MASK                             (0x80000000U)
#define CM33_SCB_HFSR_DEBUGEVT_SHIFT                            (31U)
#define CM33_SCB_HFSR_DEBUGEVT(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_HFSR_DEBUGEVT_SHIFT)) & CM33_SCB_HFSR_DEBUGEVT_MASK)
#define CM33_SCB_HFSR_FORCED_MASK                               (0x40000000U)
#define CM33_SCB_HFSR_FORCED_SHIFT                              (30U)
#define CM33_SCB_HFSR_FORCED(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_HFSR_FORCED_SHIFT)) & CM33_SCB_HFSR_FORCED_MASK)
#define CM33_SCB_HFSR_VECTTBL_MASK                              (0x2U)
#define CM33_SCB_HFSR_VECTTBL_SHIFT                             (1U)
#define CM33_SCB_HFSR_VECTTBL(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_HFSR_VECTTBL_SHIFT)) & CM33_SCB_HFSR_VECTTBL_MASK)
/* CM33_SCB_DFSR Register */
#define CM33_SCB_DFSR_EXTERNAL_MASK                             (0x10U)
#define CM33_SCB_DFSR_EXTERNAL_SHIFT                            (4U)
#define CM33_SCB_DFSR_EXTERNAL(x)                               (((uint32)(((uint32)(x)) << CM33_SCB_DFSR_EXTERNAL_SHIFT)) & CM33_SCB_DFSR_EXTERNAL_MASK)
#define CM33_SCB_DFSR_VCATCH_MASK                               (0x8U)
#define CM33_SCB_DFSR_VCATCH_SHIFT                              (3U)
#define CM33_SCB_DFSR_VCATCH(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_DFSR_VCATCH_SHIFT)) & CM33_SCB_DFSR_VCATCH_MASK)
#define CM33_SCB_DFSR_DWTTRAP_MASK                              (0x4U)
#define CM33_SCB_DFSR_DWTTRAP_SHIFT                             (2U)
#define CM33_SCB_DFSR_DWTTRAP(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_DFSR_DWTTRAP_SHIFT)) & CM33_SCB_DFSR_DWTTRAP_MASK)
#define CM33_SCB_DFSR_BKPT_MASK                                 (0x2U)
#define CM33_SCB_DFSR_BKPT_SHIFT                                (1U)
#define CM33_SCB_DFSR_BKPT(x)                                   (((uint32)(((uint32)(x)) << CM33_SCB_DFSR_BKPT_SHIFT)) & CM33_SCB_DFSR_BKPT_MASK)
#define CM33_SCB_DFSR_HALTED_MASK                               (0x1U)
#define CM33_SCB_DFSR_HALTED_SHIFT                              (0U)
#define CM33_SCB_DFSR_HALTED(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_DFSR_HALTED_SHIFT)) & CM33_SCB_DFSR_HALTED_MASK)
/* CM33_SCB_MMAR Register */
#define CM33_SCB_MMAR_ADDRESS_MASK                              (0xFFFFFFFFU)
#define CM33_SCB_MMAR_ADDRESS_SHIFT                             (0U)
#define CM33_SCB_MMAR_ADDRESS(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_MMAR_ADDRESS_SHIFT)) & CM33_SCB_MMAR_ADDRESS_MASK)
/* CM33_SCB_AFSR Register */
#define CM33_SCB_AFSR_IMPDEF_MASK                               (0xFFFFFFFFU)
#define CM33_SCB_AFSR_IMPDEF_SHIFT                              (0U)
#define CM33_SCB_AFSR_IMPDEF(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_AFSR_IMPDEF_SHIFT)) & CM33_SCB_AFSR_IMPDEF_MASK)
/* CM33_SCB_CPACR Register */
#define CM33_SCB_CPACR_CP11_WIDTH                               (2)
#define CM33_SCB_CPACR_CP11_MASK                                (0xC00000U)
#define CM33_SCB_CPACR_CP11_SHIFT                               (22U)
#define CM33_SCB_CPACR_CP11(x)                                  (((uint32)(((uint32)(x)) << CM33_SCB_CPACR_CP11_SHIFT)) & CM33_SCB_CPACR_CP11_MASK)
#define CM33_SCB_CPACR_CP10_WIDTH                               (2)
#define CM33_SCB_CPACR_CP10_MASK                                (0x300000U)
#define CM33_SCB_CPACR_CP10_SHIFT                               (20U)
#define CM33_SCB_CPACR_CP10(x)                                  (((uint32)(((uint32)(x)) << CM33_SCB_CPACR_CP10_SHIFT)) & CM33_SCB_CPACR_CP10_MASK)
/* CM33_SCB_FPCCR Register */
#define CM33_SCB_FPCCR_ASPEN_MASK                               (0x80000000U)
#define CM33_SCB_FPCCR_ASPEN_SHIFT                              (31U)
#define CM33_SCB_FPCCR_ASPEN(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_ASPEN_SHIFT)) & CM33_SCB_FPCCR_ASPEN_MASK)
#define CM33_SCB_FPCCR_LSPEN_MASK                               (0x40000000U)
#define CM33_SCB_FPCCR_LSPEN_SHIFT                              (30U)
#define CM33_SCB_FPCCR_LSPEN(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_LSPEN_SHIFT)) & CM33_SCB_FPCCR_LSPEN_MASK)
#define CM33_SCB_FPCCR_MONRDY_MASK                              (0x100U)
#define CM33_SCB_FPCCR_MONRDY_SHIFT                             (8U)
#define CM33_SCB_FPCCR_MONRDY(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_MONRDY_SHIFT)) & CM33_SCB_FPCCR_MONRDY_MASK)
#define CM33_SCB_FPCCR_BFRDY_MASK                               (0x40U)
#define CM33_SCB_FPCCR_BFRDY_SHIFT                              (6U)
#define CM33_SCB_FPCCR_BFRDY(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_BFRDY_SHIFT)) & CM33_SCB_FPCCR_BFRDY_MASK)
#define CM33_SCB_FPCCR_MMRDY_MASK                               (0x20U)
#define CM33_SCB_FPCCR_MMRDY_SHIFT                              (5U)
#define CM33_SCB_FPCCR_MMRDY(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_MMRDY_SHIFT)) & CM33_SCB_FPCCR_MMRDY_MASK)
#define CM33_SCB_FPCCR_HFRDY_MASK                               (0x10U)
#define CM33_SCB_FPCCR_HFRDY_SHIFT                              (4U)
#define CM33_SCB_FPCCR_HFRDY(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_HFRDY_SHIFT)) & CM33_SCB_FPCCR_HFRDY_MASK)
#define CM33_SCB_FPCCR_THREAD_MASK                              (0x8U)
#define CM33_SCB_FPCCR_THREAD_SHIFT                             (3U)
#define CM33_SCB_FPCCR_THREAD(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_THREAD_SHIFT)) & CM33_SCB_FPCCR_THREAD_MASK)
#define CM33_SCB_FPCCR_USER_MASK                                (0x2U)
#define CM33_SCB_FPCCR_USER_SHIFT                               (1U)
#define CM33_SCB_FPCCR_USER(x)                                  (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_USER_SHIFT)) & CM33_SCB_FPCCR_USER_MASK)
#define CM33_SCB_FPCCR_LSPACT_MASK                              (0x1U)
#define CM33_SCB_FPCCR_LSPACT_SHIFT                             (0U)
#define CM33_SCB_FPCCR_LSPACT(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_FPCCR_LSPACT_SHIFT)) & CM33_SCB_FPCCR_LSPACT_MASK)
/* CM33_SCB_FCAR Register */
#define CM33_SCB_FCAR_ADDRESS_MASK                              (0xFFFFFFF8U)
#define CM33_SCB_FCAR_ADDRESS_SHIFT                             (3U)
#define CM33_SCB_FCAR_ADDRESS(x)                                (((uint32)(((uint32)(x)) << CM33_SCB_FCAR_ADDRESS_SHIFT)) & CM33_SCB_FCAR_ADDRESS_MASK)
/* CM33_SCB_FDSCR Register */
#define CM33_SCB_FDSCR_AHP_MASK                                 (0x4000000U)
#define CM33_SCB_FDSCR_AHP_SHIFT                                (26U)
#define CM33_SCB_FDSCR_AHP(x)                                   (((uint32)(((uint32)(x)) << CM33_SCB_FDSCR_AHP_SHIFT)) & CM33_SCB_FDSCR_AHP_MASK)
#define CM33_SCB_FDSCR_DN_MASK                                  (0x2000000U)
#define CM33_SCB_FDSCR_DN_SHIFT                                 (25U)
#define CM33_SCB_FDSCR_DN(x)                                    (((uint32)(((uint32)(x)) << CM33_SCB_FDSCR_DN_SHIFT)) & CM33_SCB_FDSCR_DN_MASK)
#define CM33_SCB_FDSCR_FZ_MASK                                  (0x1000000U)
#define CM33_SCB_FDSCR_FZ_SHIFT                                 (24U)
#define CM33_SCB_FDSCR_FZ(x)                                    (((uint32)(((uint32)(x)) << CM33_SCB_FDSCR_FZ_SHIFT)) & CM33_SCB_FDSCR_FZ_MASK)
#define CM33_SCB_FDSCR_RMODE_MASK                               (0xC00000U)
#define CM33_SCB_FDSCR_RMODE_SHIFT                              (22U)
#define CM33_SCB_FDSCR_RMODE(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FDSCR_RMODE_SHIFT)) & CM33_SCB_FDSCR_RMODE_MASK)

/* CM33_SCB FPSCR register bit masks definitions */
#define CM33_SCB_FPSCR_IDCFLAG_MASK                               (0x0080U)
#define CM33_SCB_FPSCR_IDCFLAG_SHIFT                              (7U)
#define CM33_SCB_FPSCR_IDCFLAG(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPSCR_IDCFLAG_SHIFT)) & CM33_SCB_FPSCR_IDCFLAG_MASK)
#define CM33_SCB_FPSCR_IXCFLAG_MASK                               (0x0010U)
#define CM33_SCB_FPSCR_IXCFLAG_SHIFT                              (4U)
#define CM33_SCB_FPSCR_IXCFLAG(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPSCR_IXCFLAG_SHIFT)) & CM33_SCB_FPSCR_IXCFLAG_MASK)
#define CM33_SCB_FPSCR_UFCFLAG_MASK                               (0x0008U)
#define CM33_SCB_FPSCR_UFCFLAG_SHIFT                              (3U)
#define CM33_SCB_FPSCR_UFCFLAG(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPSCR_UFCFLAG_SHIFT)) & CM33_SCB_FPSCR_UFCFLAG_MASK)
#define CM33_SCB_FPSCR_OFCFLAG_MASK                               (0x0004U)
#define CM33_SCB_FPSCR_OFCFLAG_SHIFT                              (2U)
#define CM33_SCB_FPSCR_OFCFLAG(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPSCR_OFCFLAG_SHIFT)) & CM33_SCB_FPSCR_OFCFLAG_MASK)
#define CM33_SCB_FPSCR_DZCFLAG_MASK                               (0x0002U)
#define CM33_SCB_FPSCR_DZCFLAG_SHIFT                              (1U)
#define CM33_SCB_FPSCR_DZCFLAG(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPSCR_DZCFLAG_SHIFT)) & CM33_SCB_FPSCR_DZCFLAG_MASK)
#define CM33_SCB_FPSCR_IOCFLAG_MASK                               (0x0001U)
#define CM33_SCB_FPSCR_IOCFLAG_SHIFT                              (0U)
#define CM33_SCB_FPSCR_IOCFLAG(x)                                 (((uint32)(((uint32)(x)) << CM33_SCB_FPSCR_IOCFLAG_SHIFT)) & CM33_SCB_FPSCR_IOCFLAG_MASK)

/**
 * @}
 */ /* end of group CM33_SCB_Register_Masks */


/**
 * @}
 */ /* end of group CM33_SCB_Peripheral_Access_Layer */

#endif /* PSIP_CM33_SCB_H */

