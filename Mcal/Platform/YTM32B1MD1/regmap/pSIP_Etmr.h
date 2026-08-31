/**
*   @file    pSIP_Etmr.h
*   @version
*
*   @brief   AUTOSAR Etmr register map
*   @details Register map for ETMR
*
*   @addtogroup ETMR_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Etmr
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

#ifndef PSIP_ETMR_H
#define PSIP_ETMR_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/* ERRATA sections*/

/* @brief E0003
 * When PWM is in right edge align mode, 100% duty cycle will not be generated if CH_VAL1 is equal to MOD
 * So just when configuring PWM as 100% duty cycle, CH_VAL1 should be set to MOD + 1, 0-99% duty cycle is not affected.
 * So when configuring PWM duty cycle in ticks, the max value of MOD should be 0xFFFE, or CH_VAL1 will be 0x10000,
 * when writing CH_VAL1, the register will be truncated to 0x0000.
 */
#define eTMR_ERRATA_E0003

/** Extra features */
#define eTMR_INIT_VALUE     (0U)

/*==================================================================================================
*                              ETMR REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup eTMR_Peripheral_Access_Layer eTMR Peripheral Access Layer
 * @{
 */


/** eTMR - Size of Registers Arrays */
#define eTMR_CH_COUNT           (8U)

/* eTMR Register Layout Typedef */
typedef struct {
    uint32 STS;                                /**< Status Register, offset: 0x0000 */
    uint32 IOSTS;                              /**< Input/Output Status Register, offset: 0x0004 */
    uint32 CNT;                                /**< Counter Value Register, offset: 0x0008 */
    uint32 QDCNT;                              /**< Quadrature Decoder Counter Value Register, offset: 0x000C */
    uint32 CTRL;                               /**< Control Register, offset: 0x0010 */
    uint32 SYNC;                               /**< Synchronous Register, offset: 0x0014 */
    uint32 OTRIG;                              /**< Output Trigger Register, offset: 0x0018 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x001C */
    uint32 CHINIT;                             /**< Channel Output Initial Value Register, offset: 0x0020 */
    uint32 CHSWV;                              /**< Channel Software Value Register, offset: 0x0024 */
    uint32 CHMASK;                             /**< Channel Output Mask Value Register, offset: 0x0028 */
    uint32 CHFV;                               /**< Channel Fault Value Register, offset: 0x002C */
    uint32 INIT;                               /**< Counter Initial Value Register, offset: 0x0030 */
    uint32 MOD;                                /**< Counter Modulus Value Register, offset: 0x0034 */
    uint32 DITHMOD;                            /**< Dithering MOD Register, offset: 0x0038 */
    uint32 MID;                                /**< Counter Middle Value Register, offset: 0x003C */
    uint32 QDCTRL;                             /**< Quadrature Decoder Control Register, offset: 0x0040 */
    uint32 QDINIT;                             /**< Quadrature Decoder Counter Initial Value Register, offset: 0x0044 */
    uint32 QDMOD;                              /**< Quadrature Decoder Modulus Register, offset: 0x0048 */
    uint32 FAULT;                              /**< Fault Control Register, offset: 0x004C */
    uint32 RESERVED0[12];                      /**< RESERVED0, offset: 0x0050 */
    struct {
        uint32 CTRL;                               /**< Channel Control Register, offset: 0x0080 */
        uint32 VAL0;                               /**< Value 0 Register, offset: 0x0084 */
        uint32 VAL1;                               /**< Value 1 Register, offset: 0x0088 */
        uint32 DITHVAL1;                           /**< Dithering Value 1 Register, offset: 0x008C */
        uint32 DT;                                 /**< Deadtime Register, offset: 0x0090 */
        uint32 CVAL;                               /**< Capture Value Register, offset: 0x0094 */
        uint32 PPCNTN;                             /**< Positive Pulse Timeout Flag Number Register, offset: 0x0098 */
        uint32 PPCNTV;                             /**< Positive Pulse Width Capture Value Register, offset: 0x009C */
        uint32 NPCNTN;                             /**< Negative Pulse Timeout Flag Number Register, offset: 0x00A0 */
        uint32 NPCNTV;                             /**< Negative Pulse Width Capture Value Register, offset: 0x00A4 */
    uint32 RESERVED1[ 6];                      /**< RESERVED1, offset: 0x00A8 */

    } CH[8];

} eTMR_Type, *eTMR_MemMapPtr;

/** Number of instances of the eTMR module. */
#define eTMR_INSTANCE_COUNT                        (4u)

/* eTMR0  base address */
#define eTMR0_BASE_ADDR32                                  (0x40049000U)
#define eTMR0                                              ((volatile eTMR_Type *)(eTMR0_BASE_ADDR32))
/* eTMR1  base address */
#define eTMR1_BASE_ADDR32                                  (0x4004A000U)
#define eTMR1                                              ((volatile eTMR_Type *)(eTMR1_BASE_ADDR32))
/* eTMR2  base address */
#define eTMR2_BASE_ADDR32                                  (0x4004B000U)
#define eTMR2                                              ((volatile eTMR_Type *)(eTMR2_BASE_ADDR32))
/* eTMR3  base address */
#define eTMR3_BASE_ADDR32                                  (0x4004C000U)
#define eTMR3                                              ((volatile eTMR_Type *)(eTMR3_BASE_ADDR32))

/** Array initializer of eTMR peripheral base addresses */
#define eTMR_BASE_ADDRS                                    { eTMR0_BASE_ADDR32,  eTMR1_BASE_ADDR32,  eTMR2_BASE_ADDR32,  eTMR3_BASE_ADDR32 }
/** Array initializer of eTMR peripheral base pointers */
#define eTMR_BASE_PTRS                                     { eTMR0,  eTMR1,  eTMR2,  eTMR3 }

#define eTMR_STS_OFFSET32                                  (0x0000U)                    /**< Offset for Status Register */
#define eTMR_IOSTS_OFFSET32                                (0x0004U)                    /**< Offset for Input/Output Status Register */
#define eTMR_CNT_OFFSET32                                  (0x0008U)                    /**< Offset for Counter Value Register */
#define eTMR_QDCNT_OFFSET32                                (0x000CU)                    /**< Offset for Quadrature Decoder Counter Value Register */
#define eTMR_CTRL_OFFSET32                                 (0x0010U)                    /**< Offset for Control Register */
#define eTMR_SYNC_OFFSET32                                 (0x0014U)                    /**< Offset for Synchronous Register */
#define eTMR_OTRIG_OFFSET32                                (0x0018U)                    /**< Offset for Output Trigger Register */
#define eTMR_INTE_OFFSET32                                 (0x001CU)                    /**< Offset for Interrupt Enable Register */
#define eTMR_CHINIT_OFFSET32                               (0x0020U)                    /**< Offset for Channel Output Initial Value Register */
#define eTMR_CHSWV_OFFSET32                                (0x0024U)                    /**< Offset for Channel Software Value Register */
#define eTMR_CHMASK_OFFSET32                               (0x0028U)                    /**< Offset for Channel Output Mask Value Register */
#define eTMR_CHFV_OFFSET32                                 (0x002CU)                    /**< Offset for Channel Fault Value Register */
#define eTMR_INIT_OFFSET32                                 (0x0030U)                    /**< Offset for Counter Initial Value Register */
#define eTMR_MOD_OFFSET32                                  (0x0034U)                    /**< Offset for Counter Modulus Value Register */
#define eTMR_DITHMOD_OFFSET32                              (0x0038U)                    /**< Offset for Dithering MOD Register */
#define eTMR_MID_OFFSET32                                  (0x003CU)                    /**< Offset for Counter Middle Value Register */
#define eTMR_QDCTRL_OFFSET32                               (0x0040U)                    /**< Offset for Quadrature Decoder Control Register */
#define eTMR_QDINIT_OFFSET32                               (0x0044U)                    /**< Offset for Quadrature Decoder Counter Initial Value Register */
#define eTMR_QDMOD_OFFSET32                                (0x0048U)                    /**< Offset for Quadrature Decoder Modulus Register */
#define eTMR_FAULT_OFFSET32                                (0x004CU)                    /**< Offset for Fault Control Register */
#define eTMR_CH_OFFSET32(x)                                (0x0080U + ((x) * (64U)))    /**< Offset for eTMR 8 Channels */

#define eTMR_CH_CTRL_OFFSET32(x)                           (0x0080U + ((x) * (64U)))    /**< Offset for Channel Control Register */
#define eTMR_CH_VAL0_OFFSET32(x)                           (0x0084U + ((x) * (64U)))    /**< Offset for Value 0 Register */
#define eTMR_CH_VAL1_OFFSET32(x)                           (0x0088U + ((x) * (64U)))    /**< Offset for Value 1 Register */
#define eTMR_CH_DITHVAL1_OFFSET32(x)                       (0x008CU + ((x) * (64U)))    /**< Offset for Dithering Value 1 Register */
#define eTMR_CH_DT_OFFSET32(x)                             (0x0090U + ((x) * (64U)))    /**< Offset for Deadtime Register */
#define eTMR_CH_CVAL_OFFSET32(x)                           (0x0094U + ((x) * (64U)))    /**< Offset for Capture Value Register */
#define eTMR_CH_PPCNTN_OFFSET32(x)                         (0x0098U + ((x) * (64U)))    /**< Offset for Positive Pulse Timeout Flag Number Register */
#define eTMR_CH_PPCNTV_OFFSET32(x)                         (0x009CU + ((x) * (64U)))    /**< Offset for Positive Pulse Width Capture Value Register */
#define eTMR_CH_NPCNTN_OFFSET32(x)                         (0x00A0U + ((x) * (64U)))    /**< Offset for Negative Pulse Timeout Flag Number Register */
#define eTMR_CH_NPCNTV_OFFSET32(x)                         (0x00A4U + ((x) * (64U)))    /**< Offset for Negative Pulse Width Capture Value Register */



/**
 * @addtogroup eTMR Register Mask
 * @{
 */
/* eTMR_STS Register */
#define eTMR_STS_CH7NPF_MASK                                (0x80000000U)
#define eTMR_STS_CH7NPF_SHIFT                               (31U)
#define eTMR_STS_CH7NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH7NPF_SHIFT)) & eTMR_STS_CH7NPF_MASK)
#define eTMR_STS_CH6NPF_MASK                                (0x40000000U)
#define eTMR_STS_CH6NPF_SHIFT                               (30U)
#define eTMR_STS_CH6NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH6NPF_SHIFT)) & eTMR_STS_CH6NPF_MASK)
#define eTMR_STS_CH5NPF_MASK                                (0x20000000U)
#define eTMR_STS_CH5NPF_SHIFT                               (29U)
#define eTMR_STS_CH5NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH5NPF_SHIFT)) & eTMR_STS_CH5NPF_MASK)
#define eTMR_STS_CH4NPF_MASK                                (0x10000000U)
#define eTMR_STS_CH4NPF_SHIFT                               (28U)
#define eTMR_STS_CH4NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH4NPF_SHIFT)) & eTMR_STS_CH4NPF_MASK)
#define eTMR_STS_CH3NPF_MASK                                (0x8000000U)
#define eTMR_STS_CH3NPF_SHIFT                               (27U)
#define eTMR_STS_CH3NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH3NPF_SHIFT)) & eTMR_STS_CH3NPF_MASK)
#define eTMR_STS_CH2NPF_MASK                                (0x4000000U)
#define eTMR_STS_CH2NPF_SHIFT                               (26U)
#define eTMR_STS_CH2NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH2NPF_SHIFT)) & eTMR_STS_CH2NPF_MASK)
#define eTMR_STS_CH1NPF_MASK                                (0x2000000U)
#define eTMR_STS_CH1NPF_SHIFT                               (25U)
#define eTMR_STS_CH1NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH1NPF_SHIFT)) & eTMR_STS_CH1NPF_MASK)
#define eTMR_STS_CH0NPF_MASK                                (0x1000000U)
#define eTMR_STS_CH0NPF_SHIFT                               (24U)
#define eTMR_STS_CH0NPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH0NPF_SHIFT)) & eTMR_STS_CH0NPF_MASK)
#define eTMR_STS_CH7PPF_MASK                                (0x800000U)
#define eTMR_STS_CH7PPF_SHIFT                               (23U)
#define eTMR_STS_CH7PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH7PPF_SHIFT)) & eTMR_STS_CH7PPF_MASK)
#define eTMR_STS_CH6PPF_MASK                                (0x400000U)
#define eTMR_STS_CH6PPF_SHIFT                               (22U)
#define eTMR_STS_CH6PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH6PPF_SHIFT)) & eTMR_STS_CH6PPF_MASK)
#define eTMR_STS_CH5PPF_MASK                                (0x200000U)
#define eTMR_STS_CH5PPF_SHIFT                               (21U)
#define eTMR_STS_CH5PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH5PPF_SHIFT)) & eTMR_STS_CH5PPF_MASK)
#define eTMR_STS_CH4PPF_MASK                                (0x100000U)
#define eTMR_STS_CH4PPF_SHIFT                               (20U)
#define eTMR_STS_CH4PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH4PPF_SHIFT)) & eTMR_STS_CH4PPF_MASK)
#define eTMR_STS_CH3PPF_MASK                                (0x80000U)
#define eTMR_STS_CH3PPF_SHIFT                               (19U)
#define eTMR_STS_CH3PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH3PPF_SHIFT)) & eTMR_STS_CH3PPF_MASK)
#define eTMR_STS_CH2PPF_MASK                                (0x40000U)
#define eTMR_STS_CH2PPF_SHIFT                               (18U)
#define eTMR_STS_CH2PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH2PPF_SHIFT)) & eTMR_STS_CH2PPF_MASK)
#define eTMR_STS_CH1PPF_MASK                                (0x20000U)
#define eTMR_STS_CH1PPF_SHIFT                               (17U)
#define eTMR_STS_CH1PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH1PPF_SHIFT)) & eTMR_STS_CH1PPF_MASK)
#define eTMR_STS_CH0PPF_MASK                                (0x10000U)
#define eTMR_STS_CH0PPF_SHIFT                               (16U)
#define eTMR_STS_CH0PPF(x)                                  (((uint32)(((uint32)(x)) << eTMR_STS_CH0PPF_SHIFT)) & eTMR_STS_CH0PPF_MASK)
#define eTMR_STS_QDDIR_MASK                                 (0x8000U)
#define eTMR_STS_QDDIR_SHIFT                                (15U)
#define eTMR_STS_QDDIR(x)                                   (((uint32)(((uint32)(x)) << eTMR_STS_QDDIR_SHIFT)) & eTMR_STS_QDDIR_MASK)
#define eTMR_STS_QDTOF_MASK                                 (0x4000U)
#define eTMR_STS_QDTOF_SHIFT                                (14U)
#define eTMR_STS_QDTOF(x)                                   (((uint32)(((uint32)(x)) << eTMR_STS_QDTOF_SHIFT)) & eTMR_STS_QDTOF_MASK)
#define eTMR_STS_TOF_MASK                                   (0x2000U)
#define eTMR_STS_TOF_SHIFT                                  (13U)
#define eTMR_STS_TOF(x)                                     (((uint32)(((uint32)(x)) << eTMR_STS_TOF_SHIFT)) & eTMR_STS_TOF_MASK)
#define eTMR_STS_RF_MASK                                    (0x1000U)
#define eTMR_STS_RF_SHIFT                                   (12U)
#define eTMR_STS_RF(x)                                      (((uint32)(((uint32)(x)) << eTMR_STS_RF_SHIFT)) & eTMR_STS_RF_MASK)
#define eTMR_STS_F3F_MASK                                   (0x800U)
#define eTMR_STS_F3F_SHIFT                                  (11U)
#define eTMR_STS_F3F(x)                                     (((uint32)(((uint32)(x)) << eTMR_STS_F3F_SHIFT)) & eTMR_STS_F3F_MASK)
#define eTMR_STS_F2F_MASK                                   (0x400U)
#define eTMR_STS_F2F_SHIFT                                  (10U)
#define eTMR_STS_F2F(x)                                     (((uint32)(((uint32)(x)) << eTMR_STS_F2F_SHIFT)) & eTMR_STS_F2F_MASK)
#define eTMR_STS_F1F_MASK                                   (0x200U)
#define eTMR_STS_F1F_SHIFT                                  (9U)
#define eTMR_STS_F1F(x)                                     (((uint32)(((uint32)(x)) << eTMR_STS_F1F_SHIFT)) & eTMR_STS_F1F_MASK)
#define eTMR_STS_F0F_MASK                                   (0x100U)
#define eTMR_STS_F0F_SHIFT                                  (8U)
#define eTMR_STS_F0F(x)                                     (((uint32)(((uint32)(x)) << eTMR_STS_F0F_SHIFT)) & eTMR_STS_F0F_MASK)
#define eTMR_STS_CH7F_MASK                                  (0x80U)
#define eTMR_STS_CH7F_SHIFT                                 (7U)
#define eTMR_STS_CH7F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH7F_SHIFT)) & eTMR_STS_CH7F_MASK)
#define eTMR_STS_CH6F_MASK                                  (0x40U)
#define eTMR_STS_CH6F_SHIFT                                 (6U)
#define eTMR_STS_CH6F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH6F_SHIFT)) & eTMR_STS_CH6F_MASK)
#define eTMR_STS_CH5F_MASK                                  (0x20U)
#define eTMR_STS_CH5F_SHIFT                                 (5U)
#define eTMR_STS_CH5F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH5F_SHIFT)) & eTMR_STS_CH5F_MASK)
#define eTMR_STS_CH4F_MASK                                  (0x10U)
#define eTMR_STS_CH4F_SHIFT                                 (4U)
#define eTMR_STS_CH4F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH4F_SHIFT)) & eTMR_STS_CH4F_MASK)
#define eTMR_STS_CH3F_MASK                                  (0x8U)
#define eTMR_STS_CH3F_SHIFT                                 (3U)
#define eTMR_STS_CH3F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH3F_SHIFT)) & eTMR_STS_CH3F_MASK)
#define eTMR_STS_CH2F_MASK                                  (0x4U)
#define eTMR_STS_CH2F_SHIFT                                 (2U)
#define eTMR_STS_CH2F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH2F_SHIFT)) & eTMR_STS_CH2F_MASK)
#define eTMR_STS_CH1F_MASK                                  (0x2U)
#define eTMR_STS_CH1F_SHIFT                                 (1U)
#define eTMR_STS_CH1F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH1F_SHIFT)) & eTMR_STS_CH1F_MASK)
#define eTMR_STS_CH0F_MASK                                  (0x1U)
#define eTMR_STS_CH0F_SHIFT                                 (0U)
#define eTMR_STS_CH0F(x)                                    (((uint32)(((uint32)(x)) << eTMR_STS_CH0F_SHIFT)) & eTMR_STS_CH0F_MASK)
/* eTMR_IOSTS Register */
#define eTMR_IOSTS_PHB_MASK                                 (0x2000000U)
#define eTMR_IOSTS_PHB_SHIFT                                (25U)
#define eTMR_IOSTS_PHB(x)                                   (((uint32)(((uint32)(x)) << eTMR_IOSTS_PHB_SHIFT)) & eTMR_IOSTS_PHB_MASK)
#define eTMR_IOSTS_PHA_MASK                                 (0x1000000U)
#define eTMR_IOSTS_PHA_SHIFT                                (24U)
#define eTMR_IOSTS_PHA(x)                                   (((uint32)(((uint32)(x)) << eTMR_IOSTS_PHA_SHIFT)) & eTMR_IOSTS_PHA_MASK)
#define eTMR_IOSTS_F3_MASK                                  (0x80000U)
#define eTMR_IOSTS_F3_SHIFT                                 (19U)
#define eTMR_IOSTS_F3(x)                                    (((uint32)(((uint32)(x)) << eTMR_IOSTS_F3_SHIFT)) & eTMR_IOSTS_F3_MASK)
#define eTMR_IOSTS_F2_MASK                                  (0x40000U)
#define eTMR_IOSTS_F2_SHIFT                                 (18U)
#define eTMR_IOSTS_F2(x)                                    (((uint32)(((uint32)(x)) << eTMR_IOSTS_F2_SHIFT)) & eTMR_IOSTS_F2_MASK)
#define eTMR_IOSTS_F1_MASK                                  (0x20000U)
#define eTMR_IOSTS_F1_SHIFT                                 (17U)
#define eTMR_IOSTS_F1(x)                                    (((uint32)(((uint32)(x)) << eTMR_IOSTS_F1_SHIFT)) & eTMR_IOSTS_F1_MASK)
#define eTMR_IOSTS_F0_MASK                                  (0x10000U)
#define eTMR_IOSTS_F0_SHIFT                                 (16U)
#define eTMR_IOSTS_F0(x)                                    (((uint32)(((uint32)(x)) << eTMR_IOSTS_F0_SHIFT)) & eTMR_IOSTS_F0_MASK)
#define eTMR_IOSTS_CH7IO_MASK                               (0x80U)
#define eTMR_IOSTS_CH7IO_SHIFT                              (7U)
#define eTMR_IOSTS_CH7IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH7IO_SHIFT)) & eTMR_IOSTS_CH7IO_MASK)
#define eTMR_IOSTS_CH6IO_MASK                               (0x40U)
#define eTMR_IOSTS_CH6IO_SHIFT                              (6U)
#define eTMR_IOSTS_CH6IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH6IO_SHIFT)) & eTMR_IOSTS_CH6IO_MASK)
#define eTMR_IOSTS_CH5IO_MASK                               (0x20U)
#define eTMR_IOSTS_CH5IO_SHIFT                              (5U)
#define eTMR_IOSTS_CH5IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH5IO_SHIFT)) & eTMR_IOSTS_CH5IO_MASK)
#define eTMR_IOSTS_CH4IO_MASK                               (0x10U)
#define eTMR_IOSTS_CH4IO_SHIFT                              (4U)
#define eTMR_IOSTS_CH4IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH4IO_SHIFT)) & eTMR_IOSTS_CH4IO_MASK)
#define eTMR_IOSTS_CH3IO_MASK                               (0x8U)
#define eTMR_IOSTS_CH3IO_SHIFT                              (3U)
#define eTMR_IOSTS_CH3IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH3IO_SHIFT)) & eTMR_IOSTS_CH3IO_MASK)
#define eTMR_IOSTS_CH2IO_MASK                               (0x4U)
#define eTMR_IOSTS_CH2IO_SHIFT                              (2U)
#define eTMR_IOSTS_CH2IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH2IO_SHIFT)) & eTMR_IOSTS_CH2IO_MASK)
#define eTMR_IOSTS_CH1IO_MASK                               (0x2U)
#define eTMR_IOSTS_CH1IO_SHIFT                              (1U)
#define eTMR_IOSTS_CH1IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH1IO_SHIFT)) & eTMR_IOSTS_CH1IO_MASK)
#define eTMR_IOSTS_CH0IO_MASK                               (0x1U)
#define eTMR_IOSTS_CH0IO_SHIFT                              (0U)
#define eTMR_IOSTS_CH0IO(x)                                 (((uint32)(((uint32)(x)) << eTMR_IOSTS_CH0IO_SHIFT)) & eTMR_IOSTS_CH0IO_MASK)
/* eTMR_CNT Register */
#define eTMR_CNT_CNT_MASK                                   (0xFFFFU)
#define eTMR_CNT_CNT_SHIFT                                  (0U)
#define eTMR_CNT_CNT(x)                                     (((uint32)(((uint32)(x)) << eTMR_CNT_CNT_SHIFT)) & eTMR_CNT_CNT_MASK)
/* eTMR_QDCNT Register */
#define eTMR_QDCNT_QDCNT_MASK                               (0xFFFFU)
#define eTMR_QDCNT_QDCNT_SHIFT                              (0U)
#define eTMR_QDCNT_QDCNT(x)                                 (((uint32)(((uint32)(x)) << eTMR_QDCNT_QDCNT_SHIFT)) & eTMR_QDCNT_QDCNT_MASK)
/* eTMR_CTRL Register */
#define eTMR_CTRL_CAPTST_MASK                               (0x80000000U)
#define eTMR_CTRL_CAPTST_SHIFT                              (31U)
#define eTMR_CTRL_CAPTST(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_CAPTST_SHIFT)) & eTMR_CTRL_CAPTST_MASK)
#define eTMR_CTRL_COMPL67_MASK                              (0x8000000U)
#define eTMR_CTRL_COMPL67_SHIFT                             (27U)
#define eTMR_CTRL_COMPL67(x)                                (((uint32)(((uint32)(x)) << eTMR_CTRL_COMPL67_SHIFT)) & eTMR_CTRL_COMPL67_MASK)
#define eTMR_CTRL_COMPL45_MASK                              (0x4000000U)
#define eTMR_CTRL_COMPL45_SHIFT                             (26U)
#define eTMR_CTRL_COMPL45(x)                                (((uint32)(((uint32)(x)) << eTMR_CTRL_COMPL45_SHIFT)) & eTMR_CTRL_COMPL45_MASK)
#define eTMR_CTRL_COMPL23_MASK                              (0x2000000U)
#define eTMR_CTRL_COMPL23_SHIFT                             (25U)
#define eTMR_CTRL_COMPL23(x)                                (((uint32)(((uint32)(x)) << eTMR_CTRL_COMPL23_SHIFT)) & eTMR_CTRL_COMPL23_MASK)
#define eTMR_CTRL_COMPL01_MASK                              (0x1000000U)
#define eTMR_CTRL_COMPL01_SHIFT                             (24U)
#define eTMR_CTRL_COMPL01(x)                                (((uint32)(((uint32)(x)) << eTMR_CTRL_COMPL01_SHIFT)) & eTMR_CTRL_COMPL01_MASK)
#define eTMR_CTRL_DBSW67_MASK                               (0x80000U)
#define eTMR_CTRL_DBSW67_SHIFT                              (19U)
#define eTMR_CTRL_DBSW67(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_DBSW67_SHIFT)) & eTMR_CTRL_DBSW67_MASK)
#define eTMR_CTRL_DBSW45_MASK                               (0x40000U)
#define eTMR_CTRL_DBSW45_SHIFT                              (18U)
#define eTMR_CTRL_DBSW45(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_DBSW45_SHIFT)) & eTMR_CTRL_DBSW45_MASK)
#define eTMR_CTRL_DBSW23_MASK                               (0x20000U)
#define eTMR_CTRL_DBSW23_SHIFT                              (17U)
#define eTMR_CTRL_DBSW23(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_DBSW23_SHIFT)) & eTMR_CTRL_DBSW23_MASK)
#define eTMR_CTRL_DBSW01_MASK                               (0x10000U)
#define eTMR_CTRL_DBSW01_SHIFT                              (16U)
#define eTMR_CTRL_DBSW01(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_DBSW01_SHIFT)) & eTMR_CTRL_DBSW01_MASK)
#define eTMR_CTRL_DBGDIS_MASK                               (0x8000U)
#define eTMR_CTRL_DBGDIS_SHIFT                              (15U)
#define eTMR_CTRL_DBGDIS(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_DBGDIS_SHIFT)) & eTMR_CTRL_DBGDIS_MASK)
#define eTMR_CTRL_CLKPRS_WIDTH                              (7)
#define eTMR_CTRL_CLKPRS_MASK                               (0x7F00U)
#define eTMR_CTRL_CLKPRS_SHIFT                              (8U)
#define eTMR_CTRL_CLKPRS(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_CLKPRS_SHIFT)) & eTMR_CTRL_CLKPRS_MASK)
#define eTMR_CTRL_CLKSRC_MASK                               (0x10U)
#define eTMR_CTRL_CLKSRC_SHIFT                              (4U)
#define eTMR_CTRL_CLKSRC(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_CLKSRC_SHIFT)) & eTMR_CTRL_CLKSRC_MASK)
#define eTMR_CTRL_DITHMD_WIDTH                              (2)
#define eTMR_CTRL_DITHMD_MASK                               (0xCU)
#define eTMR_CTRL_DITHMD_SHIFT                              (2U)
#define eTMR_CTRL_DITHMD(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_DITHMD_SHIFT)) & eTMR_CTRL_DITHMD_MASK)
#define eTMR_CTRL_GLOBEN_MASK                               (0x2U)
#define eTMR_CTRL_GLOBEN_SHIFT                              (1U)
#define eTMR_CTRL_GLOBEN(x)                                 (((uint32)(((uint32)(x)) << eTMR_CTRL_GLOBEN_SHIFT)) & eTMR_CTRL_GLOBEN_MASK)
#define eTMR_CTRL_EN_MASK                                   (0x1U)
#define eTMR_CTRL_EN_SHIFT                                  (0U)
#define eTMR_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << eTMR_CTRL_EN_SHIFT)) & eTMR_CTRL_EN_MASK)
/* eTMR_SYNC Register */
#define eTMR_SYNC_GLOB_MASK                                 (0x80000000U)
#define eTMR_SYNC_GLOB_SHIFT                                (31U)
#define eTMR_SYNC_GLOB(x)                                   (((uint32)(((uint32)(x)) << eTMR_SYNC_GLOB_SHIFT)) & eTMR_SYNC_GLOB_MASK)
#define eTMR_SYNC_LDFRQ_WIDTH                               (4)
#define eTMR_SYNC_LDFRQ_MASK                                (0xF000000U)
#define eTMR_SYNC_LDFRQ_SHIFT                               (24U)
#define eTMR_SYNC_LDFRQ(x)                                  (((uint32)(((uint32)(x)) << eTMR_SYNC_LDFRQ_SHIFT)) & eTMR_SYNC_LDFRQ_MASK)
#define eTMR_SYNC_TRIG2EN_MASK                              (0x80000U)
#define eTMR_SYNC_TRIG2EN_SHIFT                             (19U)
#define eTMR_SYNC_TRIG2EN(x)                                (((uint32)(((uint32)(x)) << eTMR_SYNC_TRIG2EN_SHIFT)) & eTMR_SYNC_TRIG2EN_MASK)
#define eTMR_SYNC_TRIG1EN_MASK                              (0x40000U)
#define eTMR_SYNC_TRIG1EN_SHIFT                             (18U)
#define eTMR_SYNC_TRIG1EN(x)                                (((uint32)(((uint32)(x)) << eTMR_SYNC_TRIG1EN_SHIFT)) & eTMR_SYNC_TRIG1EN_MASK)
#define eTMR_SYNC_TRIG0EN_MASK                              (0x20000U)
#define eTMR_SYNC_TRIG0EN_SHIFT                             (17U)
#define eTMR_SYNC_TRIG0EN(x)                                (((uint32)(((uint32)(x)) << eTMR_SYNC_TRIG0EN_SHIFT)) & eTMR_SYNC_TRIG0EN_MASK)
#define eTMR_SYNC_SWTRIG_MASK                               (0x10000U)
#define eTMR_SYNC_SWTRIG_SHIFT                              (16U)
#define eTMR_SYNC_SWTRIG(x)                                 (((uint32)(((uint32)(x)) << eTMR_SYNC_SWTRIG_SHIFT)) & eTMR_SYNC_SWTRIG_MASK)
#define eTMR_SYNC_MASKLD_WIDTH                              (2)
#define eTMR_SYNC_MASKLD_MASK                               (0xC000U)
#define eTMR_SYNC_MASKLD_SHIFT                              (14U)
#define eTMR_SYNC_MASKLD(x)                                 (((uint32)(((uint32)(x)) << eTMR_SYNC_MASKLD_SHIFT)) & eTMR_SYNC_MASKLD_MASK)
#define eTMR_SYNC_TRIGS2_WIDTH                              (2)
#define eTMR_SYNC_TRIGS2_MASK                               (0x3000U)
#define eTMR_SYNC_TRIGS2_SHIFT                              (12U)
#define eTMR_SYNC_TRIGS2(x)                                 (((uint32)(((uint32)(x)) << eTMR_SYNC_TRIGS2_SHIFT)) & eTMR_SYNC_TRIGS2_MASK)
#define eTMR_SYNC_CNTLD_WIDTH                               (2)
#define eTMR_SYNC_CNTLD_MASK                                (0xC00U)
#define eTMR_SYNC_CNTLD_SHIFT                               (10U)
#define eTMR_SYNC_CNTLD(x)                                  (((uint32)(((uint32)(x)) << eTMR_SYNC_CNTLD_SHIFT)) & eTMR_SYNC_CNTLD_MASK)
#define eTMR_SYNC_TRIGS1_WIDTH                              (2)
#define eTMR_SYNC_TRIGS1_MASK                               (0x300U)
#define eTMR_SYNC_TRIGS1_SHIFT                              (8U)
#define eTMR_SYNC_TRIGS1(x)                                 (((uint32)(((uint32)(x)) << eTMR_SYNC_TRIGS1_SHIFT)) & eTMR_SYNC_TRIGS1_MASK)
#define eTMR_SYNC_REGLD_WIDTH                               (2)
#define eTMR_SYNC_REGLD_MASK                                (0xC0U)
#define eTMR_SYNC_REGLD_SHIFT                               (6U)
#define eTMR_SYNC_REGLD(x)                                  (((uint32)(((uint32)(x)) << eTMR_SYNC_REGLD_SHIFT)) & eTMR_SYNC_REGLD_MASK)
#define eTMR_SYNC_TRIGS0_WIDTH                              (2)
#define eTMR_SYNC_TRIGS0_MASK                               (0x30U)
#define eTMR_SYNC_TRIGS0_SHIFT                              (4U)
#define eTMR_SYNC_TRIGS0(x)                                 (((uint32)(((uint32)(x)) << eTMR_SYNC_TRIGS0_SHIFT)) & eTMR_SYNC_TRIGS0_MASK)
#define eTMR_SYNC_CNTINIT_MASK                              (0x4U)
#define eTMR_SYNC_CNTINIT_SHIFT                             (2U)
#define eTMR_SYNC_CNTINIT(x)                                (((uint32)(((uint32)(x)) << eTMR_SYNC_CNTINIT_SHIFT)) & eTMR_SYNC_CNTINIT_MASK)
#define eTMR_SYNC_CLDOK_MASK                                (0x2U)
#define eTMR_SYNC_CLDOK_SHIFT                               (1U)
#define eTMR_SYNC_CLDOK(x)                                  (((uint32)(((uint32)(x)) << eTMR_SYNC_CLDOK_SHIFT)) & eTMR_SYNC_CLDOK_MASK)
#define eTMR_SYNC_LDOK_MASK                                 (0x1U)
#define eTMR_SYNC_LDOK_SHIFT                                (0U)
#define eTMR_SYNC_LDOK(x)                                   (((uint32)(((uint32)(x)) << eTMR_SYNC_LDOK_SHIFT)) & eTMR_SYNC_LDOK_MASK)
/* eTMR_OTRIG Register */
#define eTMR_OTRIG_TWD_WIDTH                                (8)
#define eTMR_OTRIG_TWD_MASK                                 (0xFF0000U)
#define eTMR_OTRIG_TWD_SHIFT                                (16U)
#define eTMR_OTRIG_TWD(x)                                   (((uint32)(((uint32)(x)) << eTMR_OTRIG_TWD_SHIFT)) & eTMR_OTRIG_TWD_MASK)
#define eTMR_OTRIG_TFRQ_WIDTH                               (4)
#define eTMR_OTRIG_TFRQ_MASK                                (0xF000U)
#define eTMR_OTRIG_TFRQ_SHIFT                               (12U)
#define eTMR_OTRIG_TFRQ(x)                                  (((uint32)(((uint32)(x)) << eTMR_OTRIG_TFRQ_SHIFT)) & eTMR_OTRIG_TFRQ_MASK)
#define eTMR_OTRIG_PULSESRC_WIDTH                           (3)
#define eTMR_OTRIG_PULSESRC_MASK                            (0x700U)
#define eTMR_OTRIG_PULSESRC_SHIFT                           (8U)
#define eTMR_OTRIG_PULSESRC(x)                              (((uint32)(((uint32)(x)) << eTMR_OTRIG_PULSESRC_SHIFT)) & eTMR_OTRIG_PULSESRC_MASK)
#define eTMR_OTRIG_TSRC_MASK                                (0x10U)
#define eTMR_OTRIG_TSRC_SHIFT                               (4U)
#define eTMR_OTRIG_TSRC(x)                                  (((uint32)(((uint32)(x)) << eTMR_OTRIG_TSRC_SHIFT)) & eTMR_OTRIG_TSRC_MASK)
#define eTMR_OTRIG_MODTEN_MASK                              (0x4U)
#define eTMR_OTRIG_MODTEN_SHIFT                             (2U)
#define eTMR_OTRIG_MODTEN(x)                                (((uint32)(((uint32)(x)) << eTMR_OTRIG_MODTEN_SHIFT)) & eTMR_OTRIG_MODTEN_MASK)
#define eTMR_OTRIG_MIDTEN_MASK                              (0x2U)
#define eTMR_OTRIG_MIDTEN_SHIFT                             (1U)
#define eTMR_OTRIG_MIDTEN(x)                                (((uint32)(((uint32)(x)) << eTMR_OTRIG_MIDTEN_SHIFT)) & eTMR_OTRIG_MIDTEN_MASK)
#define eTMR_OTRIG_INITTEN_MASK                             (0x1U)
#define eTMR_OTRIG_INITTEN_SHIFT                            (0U)
#define eTMR_OTRIG_INITTEN(x)                               (((uint32)(((uint32)(x)) << eTMR_OTRIG_INITTEN_SHIFT)) & eTMR_OTRIG_INITTEN_MASK)
/* eTMR_INTE Register */
#define eTMR_INTE_QDTOIE_MASK                               (0x4000U)
#define eTMR_INTE_QDTOIE_SHIFT                              (14U)
#define eTMR_INTE_QDTOIE(x)                                 (((uint32)(((uint32)(x)) << eTMR_INTE_QDTOIE_SHIFT)) & eTMR_INTE_QDTOIE_MASK)
#define eTMR_INTE_TOIE_MASK                                 (0x2000U)
#define eTMR_INTE_TOIE_SHIFT                                (13U)
#define eTMR_INTE_TOIE(x)                                   (((uint32)(((uint32)(x)) << eTMR_INTE_TOIE_SHIFT)) & eTMR_INTE_TOIE_MASK)
#define eTMR_INTE_FIE_MASK                                  (0x100U)
#define eTMR_INTE_FIE_SHIFT                                 (8U)
#define eTMR_INTE_FIE(x)                                    (((uint32)(((uint32)(x)) << eTMR_INTE_FIE_SHIFT)) & eTMR_INTE_FIE_MASK)
#define eTMR_INTE_CH7IE_MASK                                (0x80U)
#define eTMR_INTE_CH7IE_SHIFT                               (7U)
#define eTMR_INTE_CH7IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH7IE_SHIFT)) & eTMR_INTE_CH7IE_MASK)
#define eTMR_INTE_CH6IE_MASK                                (0x40U)
#define eTMR_INTE_CH6IE_SHIFT                               (6U)
#define eTMR_INTE_CH6IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH6IE_SHIFT)) & eTMR_INTE_CH6IE_MASK)
#define eTMR_INTE_CH5IE_MASK                                (0x20U)
#define eTMR_INTE_CH5IE_SHIFT                               (5U)
#define eTMR_INTE_CH5IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH5IE_SHIFT)) & eTMR_INTE_CH5IE_MASK)
#define eTMR_INTE_CH4IE_MASK                                (0x10U)
#define eTMR_INTE_CH4IE_SHIFT                               (4U)
#define eTMR_INTE_CH4IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH4IE_SHIFT)) & eTMR_INTE_CH4IE_MASK)
#define eTMR_INTE_CH3IE_MASK                                (0x8U)
#define eTMR_INTE_CH3IE_SHIFT                               (3U)
#define eTMR_INTE_CH3IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH3IE_SHIFT)) & eTMR_INTE_CH3IE_MASK)
#define eTMR_INTE_CH2IE_MASK                                (0x4U)
#define eTMR_INTE_CH2IE_SHIFT                               (2U)
#define eTMR_INTE_CH2IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH2IE_SHIFT)) & eTMR_INTE_CH2IE_MASK)
#define eTMR_INTE_CH1IE_MASK                                (0x2U)
#define eTMR_INTE_CH1IE_SHIFT                               (1U)
#define eTMR_INTE_CH1IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH1IE_SHIFT)) & eTMR_INTE_CH1IE_MASK)
#define eTMR_INTE_CH0IE_MASK                                (0x1U)
#define eTMR_INTE_CH0IE_SHIFT                               (0U)
#define eTMR_INTE_CH0IE(x)                                  (((uint32)(((uint32)(x)) << eTMR_INTE_CH0IE_SHIFT)) & eTMR_INTE_CH0IE_MASK)
/* eTMR_CHINIT Register */
#define eTMR_CHINIT_CH7INITV_MASK                           (0x800000U)
#define eTMR_CHINIT_CH7INITV_SHIFT                          (23U)
#define eTMR_CHINIT_CH7INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH7INITV_SHIFT)) & eTMR_CHINIT_CH7INITV_MASK)
#define eTMR_CHINIT_CH6INITV_MASK                           (0x400000U)
#define eTMR_CHINIT_CH6INITV_SHIFT                          (22U)
#define eTMR_CHINIT_CH6INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH6INITV_SHIFT)) & eTMR_CHINIT_CH6INITV_MASK)
#define eTMR_CHINIT_CH5INITV_MASK                           (0x200000U)
#define eTMR_CHINIT_CH5INITV_SHIFT                          (21U)
#define eTMR_CHINIT_CH5INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH5INITV_SHIFT)) & eTMR_CHINIT_CH5INITV_MASK)
#define eTMR_CHINIT_CH4INITV_MASK                           (0x100000U)
#define eTMR_CHINIT_CH4INITV_SHIFT                          (20U)
#define eTMR_CHINIT_CH4INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH4INITV_SHIFT)) & eTMR_CHINIT_CH4INITV_MASK)
#define eTMR_CHINIT_CH3INITV_MASK                           (0x80000U)
#define eTMR_CHINIT_CH3INITV_SHIFT                          (19U)
#define eTMR_CHINIT_CH3INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH3INITV_SHIFT)) & eTMR_CHINIT_CH3INITV_MASK)
#define eTMR_CHINIT_CH2INITV_MASK                           (0x40000U)
#define eTMR_CHINIT_CH2INITV_SHIFT                          (18U)
#define eTMR_CHINIT_CH2INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH2INITV_SHIFT)) & eTMR_CHINIT_CH2INITV_MASK)
#define eTMR_CHINIT_CH1INITV_MASK                           (0x20000U)
#define eTMR_CHINIT_CH1INITV_SHIFT                          (17U)
#define eTMR_CHINIT_CH1INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH1INITV_SHIFT)) & eTMR_CHINIT_CH1INITV_MASK)
#define eTMR_CHINIT_CH0INITV_MASK                           (0x10000U)
#define eTMR_CHINIT_CH0INITV_SHIFT                          (16U)
#define eTMR_CHINIT_CH0INITV(x)                             (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH0INITV_SHIFT)) & eTMR_CHINIT_CH0INITV_MASK)
#define eTMR_CHINIT_CH7INIT_MASK                            (0x80U)
#define eTMR_CHINIT_CH7INIT_SHIFT                           (7U)
#define eTMR_CHINIT_CH7INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH7INIT_SHIFT)) & eTMR_CHINIT_CH7INIT_MASK)
#define eTMR_CHINIT_CH6INIT_MASK                            (0x40U)
#define eTMR_CHINIT_CH6INIT_SHIFT                           (6U)
#define eTMR_CHINIT_CH6INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH6INIT_SHIFT)) & eTMR_CHINIT_CH6INIT_MASK)
#define eTMR_CHINIT_CH5INIT_MASK                            (0x20U)
#define eTMR_CHINIT_CH5INIT_SHIFT                           (5U)
#define eTMR_CHINIT_CH5INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH5INIT_SHIFT)) & eTMR_CHINIT_CH5INIT_MASK)
#define eTMR_CHINIT_CH4INIT_MASK                            (0x10U)
#define eTMR_CHINIT_CH4INIT_SHIFT                           (4U)
#define eTMR_CHINIT_CH4INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH4INIT_SHIFT)) & eTMR_CHINIT_CH4INIT_MASK)
#define eTMR_CHINIT_CH3INIT_MASK                            (0x8U)
#define eTMR_CHINIT_CH3INIT_SHIFT                           (3U)
#define eTMR_CHINIT_CH3INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH3INIT_SHIFT)) & eTMR_CHINIT_CH3INIT_MASK)
#define eTMR_CHINIT_CH2INIT_MASK                            (0x4U)
#define eTMR_CHINIT_CH2INIT_SHIFT                           (2U)
#define eTMR_CHINIT_CH2INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH2INIT_SHIFT)) & eTMR_CHINIT_CH2INIT_MASK)
#define eTMR_CHINIT_CH1INIT_MASK                            (0x2U)
#define eTMR_CHINIT_CH1INIT_SHIFT                           (1U)
#define eTMR_CHINIT_CH1INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH1INIT_SHIFT)) & eTMR_CHINIT_CH1INIT_MASK)
#define eTMR_CHINIT_CH0INIT_MASK                            (0x1U)
#define eTMR_CHINIT_CH0INIT_SHIFT                           (0U)
#define eTMR_CHINIT_CH0INIT(x)                              (((uint32)(((uint32)(x)) << eTMR_CHINIT_CH0INIT_SHIFT)) & eTMR_CHINIT_CH0INIT_MASK)
/* eTMR_CHSWV Register */
#define eTMR_CHSWV_CH7SWV_MASK                              (0x80U)
#define eTMR_CHSWV_CH7SWV_SHIFT                             (7U)
#define eTMR_CHSWV_CH7SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH7SWV_SHIFT)) & eTMR_CHSWV_CH7SWV_MASK)
#define eTMR_CHSWV_CH6SWV_MASK                              (0x40U)
#define eTMR_CHSWV_CH6SWV_SHIFT                             (6U)
#define eTMR_CHSWV_CH6SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH6SWV_SHIFT)) & eTMR_CHSWV_CH6SWV_MASK)
#define eTMR_CHSWV_CH5SWV_MASK                              (0x20U)
#define eTMR_CHSWV_CH5SWV_SHIFT                             (5U)
#define eTMR_CHSWV_CH5SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH5SWV_SHIFT)) & eTMR_CHSWV_CH5SWV_MASK)
#define eTMR_CHSWV_CH4SWV_MASK                              (0x10U)
#define eTMR_CHSWV_CH4SWV_SHIFT                             (4U)
#define eTMR_CHSWV_CH4SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH4SWV_SHIFT)) & eTMR_CHSWV_CH4SWV_MASK)
#define eTMR_CHSWV_CH3SWV_MASK                              (0x8U)
#define eTMR_CHSWV_CH3SWV_SHIFT                             (3U)
#define eTMR_CHSWV_CH3SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH3SWV_SHIFT)) & eTMR_CHSWV_CH3SWV_MASK)
#define eTMR_CHSWV_CH2SWV_MASK                              (0x4U)
#define eTMR_CHSWV_CH2SWV_SHIFT                             (2U)
#define eTMR_CHSWV_CH2SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH2SWV_SHIFT)) & eTMR_CHSWV_CH2SWV_MASK)
#define eTMR_CHSWV_CH1SWV_MASK                              (0x2U)
#define eTMR_CHSWV_CH1SWV_SHIFT                             (1U)
#define eTMR_CHSWV_CH1SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH1SWV_SHIFT)) & eTMR_CHSWV_CH1SWV_MASK)
#define eTMR_CHSWV_CH0SWV_MASK                              (0x1U)
#define eTMR_CHSWV_CH0SWV_SHIFT                             (0U)
#define eTMR_CHSWV_CH0SWV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHSWV_CH0SWV_SHIFT)) & eTMR_CHSWV_CH0SWV_MASK)
/* eTMR_CHMASK Register */
#define eTMR_CHMASK_CH7MV_WIDTH                             (2)
#define eTMR_CHMASK_CH7MV_MASK                              (0xC0000000U)
#define eTMR_CHMASK_CH7MV_SHIFT                             (30U)
#define eTMR_CHMASK_CH7MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH7MV_SHIFT)) & eTMR_CHMASK_CH7MV_MASK)
#define eTMR_CHMASK_CH6MV_WIDTH                             (2)
#define eTMR_CHMASK_CH6MV_MASK                              (0x30000000U)
#define eTMR_CHMASK_CH6MV_SHIFT                             (28U)
#define eTMR_CHMASK_CH6MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH6MV_SHIFT)) & eTMR_CHMASK_CH6MV_MASK)
#define eTMR_CHMASK_CH5MV_WIDTH                             (2)
#define eTMR_CHMASK_CH5MV_MASK                              (0xC000000U)
#define eTMR_CHMASK_CH5MV_SHIFT                             (26U)
#define eTMR_CHMASK_CH5MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH5MV_SHIFT)) & eTMR_CHMASK_CH5MV_MASK)
#define eTMR_CHMASK_CH4MV_WIDTH                             (2)
#define eTMR_CHMASK_CH4MV_MASK                              (0x3000000U)
#define eTMR_CHMASK_CH4MV_SHIFT                             (24U)
#define eTMR_CHMASK_CH4MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH4MV_SHIFT)) & eTMR_CHMASK_CH4MV_MASK)
#define eTMR_CHMASK_CH3MV_WIDTH                             (2)
#define eTMR_CHMASK_CH3MV_MASK                              (0xC00000U)
#define eTMR_CHMASK_CH3MV_SHIFT                             (22U)
#define eTMR_CHMASK_CH3MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH3MV_SHIFT)) & eTMR_CHMASK_CH3MV_MASK)
#define eTMR_CHMASK_CH2MV_WIDTH                             (2)
#define eTMR_CHMASK_CH2MV_MASK                              (0x300000U)
#define eTMR_CHMASK_CH2MV_SHIFT                             (20U)
#define eTMR_CHMASK_CH2MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH2MV_SHIFT)) & eTMR_CHMASK_CH2MV_MASK)
#define eTMR_CHMASK_CH1MV_WIDTH                             (2)
#define eTMR_CHMASK_CH1MV_MASK                              (0xC0000U)
#define eTMR_CHMASK_CH1MV_SHIFT                             (18U)
#define eTMR_CHMASK_CH1MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH1MV_SHIFT)) & eTMR_CHMASK_CH1MV_MASK)
#define eTMR_CHMASK_CH0MV_WIDTH                             (2)
#define eTMR_CHMASK_CH0MV_MASK                              (0x30000U)
#define eTMR_CHMASK_CH0MV_SHIFT                             (16U)
#define eTMR_CHMASK_CH0MV(x)                                (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH0MV_SHIFT)) & eTMR_CHMASK_CH0MV_MASK)
#define eTMR_CHMASK_CH7M_MASK                               (0x80U)
#define eTMR_CHMASK_CH7M_SHIFT                              (7U)
#define eTMR_CHMASK_CH7M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH7M_SHIFT)) & eTMR_CHMASK_CH7M_MASK)
#define eTMR_CHMASK_CH6M_MASK                               (0x40U)
#define eTMR_CHMASK_CH6M_SHIFT                              (6U)
#define eTMR_CHMASK_CH6M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH6M_SHIFT)) & eTMR_CHMASK_CH6M_MASK)
#define eTMR_CHMASK_CH5M_MASK                               (0x20U)
#define eTMR_CHMASK_CH5M_SHIFT                              (5U)
#define eTMR_CHMASK_CH5M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH5M_SHIFT)) & eTMR_CHMASK_CH5M_MASK)
#define eTMR_CHMASK_CH4M_MASK                               (0x10U)
#define eTMR_CHMASK_CH4M_SHIFT                              (4U)
#define eTMR_CHMASK_CH4M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH4M_SHIFT)) & eTMR_CHMASK_CH4M_MASK)
#define eTMR_CHMASK_CH3M_MASK                               (0x8U)
#define eTMR_CHMASK_CH3M_SHIFT                              (3U)
#define eTMR_CHMASK_CH3M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH3M_SHIFT)) & eTMR_CHMASK_CH3M_MASK)
#define eTMR_CHMASK_CH2M_MASK                               (0x4U)
#define eTMR_CHMASK_CH2M_SHIFT                              (2U)
#define eTMR_CHMASK_CH2M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH2M_SHIFT)) & eTMR_CHMASK_CH2M_MASK)
#define eTMR_CHMASK_CH1M_MASK                               (0x2U)
#define eTMR_CHMASK_CH1M_SHIFT                              (1U)
#define eTMR_CHMASK_CH1M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH1M_SHIFT)) & eTMR_CHMASK_CH1M_MASK)
#define eTMR_CHMASK_CH0M_MASK                               (0x1U)
#define eTMR_CHMASK_CH0M_SHIFT                              (0U)
#define eTMR_CHMASK_CH0M(x)                                 (((uint32)(((uint32)(x)) << eTMR_CHMASK_CH0M_SHIFT)) & eTMR_CHMASK_CH0M_MASK)
/* eTMR_CHFV Register */
#define eTMR_CHFV_CH7FV_WIDTH                               (2)
#define eTMR_CHFV_CH7FV_MASK                                (0xC000U)
#define eTMR_CHFV_CH7FV_SHIFT                               (14U)
#define eTMR_CHFV_CH7FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH7FV_SHIFT)) & eTMR_CHFV_CH7FV_MASK)
#define eTMR_CHFV_CH6FV_WIDTH                               (2)
#define eTMR_CHFV_CH6FV_MASK                                (0x3000U)
#define eTMR_CHFV_CH6FV_SHIFT                               (12U)
#define eTMR_CHFV_CH6FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH6FV_SHIFT)) & eTMR_CHFV_CH6FV_MASK)
#define eTMR_CHFV_CH5FV_WIDTH                               (2)
#define eTMR_CHFV_CH5FV_MASK                                (0xC00U)
#define eTMR_CHFV_CH5FV_SHIFT                               (10U)
#define eTMR_CHFV_CH5FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH5FV_SHIFT)) & eTMR_CHFV_CH5FV_MASK)
#define eTMR_CHFV_CH4FV_WIDTH                               (2)
#define eTMR_CHFV_CH4FV_MASK                                (0x300U)
#define eTMR_CHFV_CH4FV_SHIFT                               (8U)
#define eTMR_CHFV_CH4FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH4FV_SHIFT)) & eTMR_CHFV_CH4FV_MASK)
#define eTMR_CHFV_CH3FV_WIDTH                               (2)
#define eTMR_CHFV_CH3FV_MASK                                (0xC0U)
#define eTMR_CHFV_CH3FV_SHIFT                               (6U)
#define eTMR_CHFV_CH3FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH3FV_SHIFT)) & eTMR_CHFV_CH3FV_MASK)
#define eTMR_CHFV_CH2FV_WIDTH                               (2)
#define eTMR_CHFV_CH2FV_MASK                                (0x30U)
#define eTMR_CHFV_CH2FV_SHIFT                               (4U)
#define eTMR_CHFV_CH2FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH2FV_SHIFT)) & eTMR_CHFV_CH2FV_MASK)
#define eTMR_CHFV_CH1FV_WIDTH                               (2)
#define eTMR_CHFV_CH1FV_MASK                                (0xCU)
#define eTMR_CHFV_CH1FV_SHIFT                               (2U)
#define eTMR_CHFV_CH1FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH1FV_SHIFT)) & eTMR_CHFV_CH1FV_MASK)
#define eTMR_CHFV_CH0FV_WIDTH                               (2)
#define eTMR_CHFV_CH0FV_MASK                                (0x3U)
#define eTMR_CHFV_CH0FV_SHIFT                               (0U)
#define eTMR_CHFV_CH0FV(x)                                  (((uint32)(((uint32)(x)) << eTMR_CHFV_CH0FV_SHIFT)) & eTMR_CHFV_CH0FV_MASK)
/* eTMR_INIT Register */
#define eTMR_INIT_INIT_MASK                                 (0xFFFFU)
#define eTMR_INIT_INIT_SHIFT                                (0U)
#define eTMR_INIT_INIT(x)                                   (((uint32)(((uint32)(x)) << eTMR_INIT_INIT_SHIFT)) & eTMR_INIT_INIT_MASK)
/* eTMR_MOD Register */
#define eTMR_MOD_MOD_MASK                                   (0xFFFFU)
#define eTMR_MOD_MOD_SHIFT                                  (0U)
#define eTMR_MOD_MOD(x)                                     (((uint32)(((uint32)(x)) << eTMR_MOD_MOD_SHIFT)) & eTMR_MOD_MOD_MASK)
/* eTMR_DITHMOD Register */
#define eTMR_DITHMOD_MODINT_WIDTH                           (7)
#define eTMR_DITHMOD_MODINT_MASK                            (0x7F00U)
#define eTMR_DITHMOD_MODINT_SHIFT                           (8U)
#define eTMR_DITHMOD_MODINT(x)                              (((uint32)(((uint32)(x)) << eTMR_DITHMOD_MODINT_SHIFT)) & eTMR_DITHMOD_MODINT_MASK)
#define eTMR_DITHMOD_MODFRAC_WIDTH                          (5)
#define eTMR_DITHMOD_MODFRAC_MASK                           (0x1FU)
#define eTMR_DITHMOD_MODFRAC_SHIFT                          (0U)
#define eTMR_DITHMOD_MODFRAC(x)                             (((uint32)(((uint32)(x)) << eTMR_DITHMOD_MODFRAC_SHIFT)) & eTMR_DITHMOD_MODFRAC_MASK)
/* eTMR_MID Register */
#define eTMR_MID_MID_MASK                                   (0xFFFFU)
#define eTMR_MID_MID_SHIFT                                  (0U)
#define eTMR_MID_MID(x)                                     (((uint32)(((uint32)(x)) << eTMR_MID_MID_SHIFT)) & eTMR_MID_MID_MASK)
/* eTMR_QDCTRL Register */
#define eTMR_QDCTRL_QDFCNT_WIDTH                            (4)
#define eTMR_QDCTRL_QDFCNT_MASK                             (0xF0000000U)
#define eTMR_QDCTRL_QDFCNT_SHIFT                            (28U)
#define eTMR_QDCTRL_QDFCNT(x)                               (((uint32)(((uint32)(x)) << eTMR_QDCTRL_QDFCNT_SHIFT)) & eTMR_QDCTRL_QDFCNT_MASK)
#define eTMR_QDCTRL_QDFPER_WIDTH                            (4)
#define eTMR_QDCTRL_QDFPER_MASK                             (0xF000000U)
#define eTMR_QDCTRL_QDFPER_SHIFT                            (24U)
#define eTMR_QDCTRL_QDFPER(x)                               (((uint32)(((uint32)(x)) << eTMR_QDCTRL_QDFPER_SHIFT)) & eTMR_QDCTRL_QDFPER_MASK)
#define eTMR_QDCTRL_PHBPOL_MASK                             (0x20000U)
#define eTMR_QDCTRL_PHBPOL_SHIFT                            (17U)
#define eTMR_QDCTRL_PHBPOL(x)                               (((uint32)(((uint32)(x)) << eTMR_QDCTRL_PHBPOL_SHIFT)) & eTMR_QDCTRL_PHBPOL_MASK)
#define eTMR_QDCTRL_PHAPOL_MASK                             (0x10000U)
#define eTMR_QDCTRL_PHAPOL_SHIFT                            (16U)
#define eTMR_QDCTRL_PHAPOL(x)                               (((uint32)(((uint32)(x)) << eTMR_QDCTRL_PHAPOL_SHIFT)) & eTMR_QDCTRL_PHAPOL_MASK)
#define eTMR_QDCTRL_QDCLKPRS_WIDTH                          (3)
#define eTMR_QDCTRL_QDCLKPRS_MASK                           (0x7000U)
#define eTMR_QDCTRL_QDCLKPRS_SHIFT                          (12U)
#define eTMR_QDCTRL_QDCLKPRS(x)                             (((uint32)(((uint32)(x)) << eTMR_QDCTRL_QDCLKPRS_SHIFT)) & eTMR_QDCTRL_QDCLKPRS_MASK)
#define eTMR_QDCTRL_QDMODE_WIDTH                            (2)
#define eTMR_QDCTRL_QDMODE_MASK                             (0x30U)
#define eTMR_QDCTRL_QDMODE_SHIFT                            (4U)
#define eTMR_QDCTRL_QDMODE(x)                               (((uint32)(((uint32)(x)) << eTMR_QDCTRL_QDMODE_SHIFT)) & eTMR_QDCTRL_QDMODE_MASK)
#define eTMR_QDCTRL_QDEN_MASK                               (0x1U)
#define eTMR_QDCTRL_QDEN_SHIFT                              (0U)
#define eTMR_QDCTRL_QDEN(x)                                 (((uint32)(((uint32)(x)) << eTMR_QDCTRL_QDEN_SHIFT)) & eTMR_QDCTRL_QDEN_MASK)
/* eTMR_QDINIT Register */
#define eTMR_QDINIT_QDINIT_MASK                             (0xFFFFU)
#define eTMR_QDINIT_QDINIT_SHIFT                            (0U)
#define eTMR_QDINIT_QDINIT(x)                               (((uint32)(((uint32)(x)) << eTMR_QDINIT_QDINIT_SHIFT)) & eTMR_QDINIT_QDINIT_MASK)
/* eTMR_QDMOD Register */
#define eTMR_QDMOD_QDMOD_MASK                               (0xFFFFU)
#define eTMR_QDMOD_QDMOD_SHIFT                              (0U)
#define eTMR_QDMOD_QDMOD(x)                                 (((uint32)(((uint32)(x)) << eTMR_QDMOD_QDMOD_SHIFT)) & eTMR_QDMOD_QDMOD_MASK)
/* eTMR_FAULT Register */
#define eTMR_FAULT_FFCNT_WIDTH                              (4)
#define eTMR_FAULT_FFCNT_MASK                               (0xF0000000U)
#define eTMR_FAULT_FFCNT_SHIFT                              (28U)
#define eTMR_FAULT_FFCNT(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_FFCNT_SHIFT)) & eTMR_FAULT_FFCNT_MASK)
#define eTMR_FAULT_FFPER_WIDTH                              (4)
#define eTMR_FAULT_FFPER_MASK                               (0xF000000U)
#define eTMR_FAULT_FFPER_SHIFT                              (24U)
#define eTMR_FAULT_FFPER(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_FFPER_SHIFT)) & eTMR_FAULT_FFPER_MASK)
#define eTMR_FAULT_STRETCH_MASK                             (0x200000U)
#define eTMR_FAULT_STRETCH_SHIFT                            (21U)
#define eTMR_FAULT_STRETCH(x)                               (((uint32)(((uint32)(x)) << eTMR_FAULT_STRETCH_SHIFT)) & eTMR_FAULT_STRETCH_MASK)
#define eTMR_FAULT_FCOMB_MASK                               (0x100000U)
#define eTMR_FAULT_FCOMB_SHIFT                              (20U)
#define eTMR_FAULT_FCOMB(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_FCOMB_SHIFT)) & eTMR_FAULT_FCOMB_MASK)
#define eTMR_FAULT_RCVRY_WIDTH                              (2)
#define eTMR_FAULT_RCVRY_MASK                               (0xC0000U)
#define eTMR_FAULT_RCVRY_SHIFT                              (18U)
#define eTMR_FAULT_RCVRY(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_RCVRY_SHIFT)) & eTMR_FAULT_RCVRY_MASK)
#define eTMR_FAULT_FAUTO_MASK                               (0x30000U)
#define eTMR_FAULT_FAUTO_SHIFT                              (16U)
#define eTMR_FAULT_FAUTO(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_FAUTO_SHIFT)) & eTMR_FAULT_FAUTO_MASK)
#define eTMR_FAULT_F3POL_MASK                               (0x800U)
#define eTMR_FAULT_F3POL_SHIFT                              (11U)
#define eTMR_FAULT_F3POL(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_F3POL_SHIFT)) & eTMR_FAULT_F3POL_MASK)
#define eTMR_FAULT_F2POL_MASK                               (0x400U)
#define eTMR_FAULT_F2POL_SHIFT                              (10U)
#define eTMR_FAULT_F2POL(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_F2POL_SHIFT)) & eTMR_FAULT_F2POL_MASK)
#define eTMR_FAULT_F1POL_MASK                               (0x200U)
#define eTMR_FAULT_F1POL_SHIFT                              (9U)
#define eTMR_FAULT_F1POL(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_F1POL_SHIFT)) & eTMR_FAULT_F1POL_MASK)
#define eTMR_FAULT_F0POL_MASK                               (0x100U)
#define eTMR_FAULT_F0POL_SHIFT                              (8U)
#define eTMR_FAULT_F0POL(x)                                 (((uint32)(((uint32)(x)) << eTMR_FAULT_F0POL_SHIFT)) & eTMR_FAULT_F0POL_MASK)
#define eTMR_FAULT_F3EN_MASK                                (0x8U)
#define eTMR_FAULT_F3EN_SHIFT                               (3U)
#define eTMR_FAULT_F3EN(x)                                  (((uint32)(((uint32)(x)) << eTMR_FAULT_F3EN_SHIFT)) & eTMR_FAULT_F3EN_MASK)
#define eTMR_FAULT_F2EN_MASK                                (0x4U)
#define eTMR_FAULT_F2EN_SHIFT                               (2U)
#define eTMR_FAULT_F2EN(x)                                  (((uint32)(((uint32)(x)) << eTMR_FAULT_F2EN_SHIFT)) & eTMR_FAULT_F2EN_MASK)
#define eTMR_FAULT_F1EN_MASK                                (0x2U)
#define eTMR_FAULT_F1EN_SHIFT                               (1U)
#define eTMR_FAULT_F1EN(x)                                  (((uint32)(((uint32)(x)) << eTMR_FAULT_F1EN_SHIFT)) & eTMR_FAULT_F1EN_MASK)
#define eTMR_FAULT_F0EN_MASK                                (0x1U)
#define eTMR_FAULT_F0EN_SHIFT                               (0U)
#define eTMR_FAULT_F0EN(x)                                  (((uint32)(((uint32)(x)) << eTMR_FAULT_F0EN_SHIFT)) & eTMR_FAULT_F0EN_MASK)
/* eTMR_CH_CTRL Register */
#define eTMR_CH_CTRL_DMAEN_MASK                                (0x40000000U)
#define eTMR_CH_CTRL_DMAEN_SHIFT                               (30U)
#define eTMR_CH_CTRL_DMAEN(x)                                  (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_DMAEN_SHIFT)) & eTMR_CH_CTRL_DMAEN_MASK)
#define eTMR_CH_CTRL_LDEN_MASK                                 (0x10000000U)
#define eTMR_CH_CTRL_LDEN_SHIFT                                (28U)
#define eTMR_CH_CTRL_LDEN(x)                                   (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_LDEN_SHIFT)) & eTMR_CH_CTRL_LDEN_MASK)
#define eTMR_CH_CTRL_CAPEDGE_WIDTH                             (2)
#define eTMR_CH_CTRL_CAPEDGE_MASK                              (0x3000000U)
#define eTMR_CH_CTRL_CAPEDGE_SHIFT                             (24U)
#define eTMR_CH_CTRL_CAPEDGE(x)                                (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_CAPEDGE_SHIFT)) & eTMR_CH_CTRL_CAPEDGE_MASK)
#define eTMR_CH_CTRL_CFCNT_WIDTH                               (4)
#define eTMR_CH_CTRL_CFCNT_MASK                                (0xF00000U)
#define eTMR_CH_CTRL_CFCNT_SHIFT                               (20U)
#define eTMR_CH_CTRL_CFCNT(x)                                  (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_CFCNT_SHIFT)) & eTMR_CH_CTRL_CFCNT_MASK)
#define eTMR_CH_CTRL_CFPER_WIDTH                               (4)
#define eTMR_CH_CTRL_CFPER_MASK                                (0xF0000U)
#define eTMR_CH_CTRL_CFPER_SHIFT                               (16U)
#define eTMR_CH_CTRL_CFPER(x)                                  (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_CFPER_SHIFT)) & eTMR_CH_CTRL_CFPER_MASK)
#define eTMR_CH_CTRL_VAL1CMP_WIDTH                             (2)
#define eTMR_CH_CTRL_VAL1CMP_MASK                              (0xC000U)
#define eTMR_CH_CTRL_VAL1CMP_SHIFT                             (14U)
#define eTMR_CH_CTRL_VAL1CMP(x)                                (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_VAL1CMP_SHIFT)) & eTMR_CH_CTRL_VAL1CMP_MASK)
#define eTMR_CH_CTRL_VAL0CMP_WIDTH                             (2)
#define eTMR_CH_CTRL_VAL0CMP_MASK                              (0x3000U)
#define eTMR_CH_CTRL_VAL0CMP_SHIFT                             (12U)
#define eTMR_CH_CTRL_VAL0CMP(x)                                (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_VAL0CMP_SHIFT)) & eTMR_CH_CTRL_VAL0CMP_MASK)
#define eTMR_CH_CTRL_PWMSRC_MASK                               (0x300U)
#define eTMR_CH_CTRL_PWMSRC_SHIFT                              (8U)
#define eTMR_CH_CTRL_PWMSRC(x)                                 (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_PWMSRC_SHIFT)) & eTMR_CH_CTRL_PWMSRC_MASK)
#define eTMR_CH_CTRL_VAL1TEN_MASK                              (0x80U)
#define eTMR_CH_CTRL_VAL1TEN_SHIFT                             (7U)
#define eTMR_CH_CTRL_VAL1TEN(x)                                (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_VAL1TEN_SHIFT)) & eTMR_CH_CTRL_VAL1TEN_MASK)
#define eTMR_CH_CTRL_VAL0TEN_MASK                              (0x40U)
#define eTMR_CH_CTRL_VAL0TEN_SHIFT                             (6U)
#define eTMR_CH_CTRL_VAL0TEN(x)                                (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_VAL0TEN_SHIFT)) & eTMR_CH_CTRL_VAL0TEN_MASK)
#define eTMR_CH_CTRL_CHPOL_MASK                                (0x20U)
#define eTMR_CH_CTRL_CHPOL_SHIFT                               (5U)
#define eTMR_CH_CTRL_CHPOL(x)                                  (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_CHPOL_SHIFT)) & eTMR_CH_CTRL_CHPOL_MASK)
#define eTMR_CH_CTRL_CENTER_MASK                               (0x10U)
#define eTMR_CH_CTRL_CENTER_SHIFT                              (4U)
#define eTMR_CH_CTRL_CENTER(x)                                 (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_CENTER_SHIFT)) & eTMR_CH_CTRL_CENTER_MASK)
#define eTMR_CH_CTRL_CHMODE_WIDTH                              (2)
#define eTMR_CH_CTRL_CHMODE_MASK                               (0x3U)
#define eTMR_CH_CTRL_CHMODE_SHIFT                              (0U)
#define eTMR_CH_CTRL_CHMODE(x)                                 (((uint32)(((uint32)(x)) << eTMR_CH_CTRL_CHMODE_SHIFT)) & eTMR_CH_CTRL_CHMODE_MASK)
/* eTMR_CH_VAL0 Register */
#define eTMR_CH_VAL0_VAL0_MASK                                 (0xFFFFU)
#define eTMR_CH_VAL0_VAL0_SHIFT                                (0U)
#define eTMR_CH_VAL0_VAL0(x)                                   (((uint32)(((uint32)(x)) << eTMR_CH_VAL0_VAL0_SHIFT)) & eTMR_CH_VAL0_VAL0_MASK)
/* eTMR_CH_VAL1 Register */
#define eTMR_CH_VAL1_VAL1_MASK                                 (0xFFFFU)
#define eTMR_CH_VAL1_VAL1_SHIFT                                (0U)
#define eTMR_CH_VAL1_VAL1(x)                                   (((uint32)(((uint32)(x)) << eTMR_CH_VAL1_VAL1_SHIFT)) & eTMR_CH_VAL1_VAL1_MASK)
/* eTMR_CH_DITHVAL1 Register */
#define eTMR_CH_DITHVAL1_VAL1INT_MASK                          (0x7F00U)
#define eTMR_CH_DITHVAL1_VAL1INT_SHIFT                         (8U)
#define eTMR_CH_DITHVAL1_VAL1INT(x)                            (((uint32)(((uint32)(x)) << eTMR_CH_DITHVAL1_VAL1INT_SHIFT)) & eTMR_CH_DITHVAL1_VAL1INT_MASK)
#define eTMR_CH_DITHVAL1_VAL1FRAC_MASK                         (0x1FU)
#define eTMR_CH_DITHVAL1_VAL1FRAC_SHIFT                        (0U)
#define eTMR_CH_DITHVAL1_VAL1FRAC(x)                           (((uint32)(((uint32)(x)) << eTMR_CH_DITHVAL1_VAL1FRAC_SHIFT)) & eTMR_CH_DITHVAL1_VAL1FRAC_MASK)
/* eTMR_CH_DT Register */
#define eTMR_CH_DT_DTVAL_MASK                                  (0xFFFFU)
#define eTMR_CH_DT_DTVAL_SHIFT                                 (0U)
#define eTMR_CH_DT_DTVAL(x)                                    (((uint32)(((uint32)(x)) << eTMR_CH_DT_DTVAL_SHIFT)) & eTMR_CH_DT_DTVAL_MASK)
/* eTMR_CH_CVAL Register */
#define eTMR_CH_CVAL_CVAL_MASK                                 (0xFFFFU)
#define eTMR_CH_CVAL_CVAL_SHIFT                                (0U)
#define eTMR_CH_CVAL_CVAL(x)                                   (((uint32)(((uint32)(x)) << eTMR_CH_CVAL_CVAL_SHIFT)) & eTMR_CH_CVAL_CVAL_MASK)
/* eTMR_CH_PPCNTN Register */
#define eTMR_CH_PPCNTN_PPCNTN_MASK                             (0xFFU)
#define eTMR_CH_PPCNTN_PPCNTN_SHIFT                            (0U)
#define eTMR_CH_PPCNTN_PPCNTN(x)                               (((uint32)(((uint32)(x)) << eTMR_CH_PPCNTN_PPCNTN_SHIFT)) & eTMR_CH_PPCNTN_PPCNTN_MASK)
/* eTMR_CH_PPCNTV Register */
#define eTMR_CH_PPCNTV_PPCNTV_MASK                             (0xFFFFU)
#define eTMR_CH_PPCNTV_PPCNTV_SHIFT                            (0U)
#define eTMR_CH_PPCNTV_PPCNTV(x)                               (((uint32)(((uint32)(x)) << eTMR_CH_PPCNTV_PPCNTV_SHIFT)) & eTMR_CH_PPCNTV_PPCNTV_MASK)
/* eTMR_CH_NPCNTN Register */
#define eTMR_CH_NPCNTN_NPCNTN_MASK                             (0xFFU)
#define eTMR_CH_NPCNTN_NPCNTN_SHIFT                            (0U)
#define eTMR_CH_NPCNTN_NPCNTN(x)                               (((uint32)(((uint32)(x)) << eTMR_CH_NPCNTN_NPCNTN_SHIFT)) & eTMR_CH_NPCNTN_NPCNTN_MASK)
/* eTMR_CH_NPCNTV Register */
#define eTMR_CH_NPCNTV_NPCNTV_MASK                             (0xFFFFU)
#define eTMR_CH_NPCNTV_NPCNTV_SHIFT                            (0U)
#define eTMR_CH_NPCNTV_NPCNTV(x)                               (((uint32)(((uint32)(x)) << eTMR_CH_NPCNTV_NPCNTV_SHIFT)) & eTMR_CH_NPCNTV_NPCNTV_MASK)



/**
 * @}
 */ /* end of group eTMR_Register_Masks */


/**
 * @}
 */ /* end of group eTMR_Peripheral_Access_Layer */

#endif /* PSIP_ETMR_H */

