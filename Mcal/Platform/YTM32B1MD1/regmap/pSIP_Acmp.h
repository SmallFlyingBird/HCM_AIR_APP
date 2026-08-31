/**
*   @file    pSIP_Acmp.h
*   @version
*
*   @brief   AUTOSAR Acmp register map
*   @details Register map for ACMP
*
*   @addtogroup ACMP_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Acmp
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

#ifndef PSIP_ACMP_H
#define PSIP_ACMP_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              ACMP REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup ACMP_Peripheral_Access_Layer ACMP Peripheral Access Layer
 * @{
 */


/** ACMP - Size of Registers Arrays */

/* ACMP Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 DAC;                                /**< DAC Register, offset: 0x0004 */
    uint32 MUX;                                /**< Channels Multiplexer, offset: 0x0008 */
    uint32 FILT;                               /**< Filter Register, offset: 0x000C */
    uint32 DMACR;                              /**< DMA Control Register, offset: 0x0010 */
    uint32 RESERVED_5;                         /**< RESERVED_5, offset: 0x0014 */
    uint32 STS;                                /**< Status Register, offset: 0x0018 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x001C */
    uint32 CONT;                               /**< Continuous Mode Register, offset: 0x0020 */

} ACMP_Type, *ACMP_MemMapPtr;

/** Number of instances of the ACMP module. */
#define ACMP_INSTANCE_COUNT                        (1u)

/* ACMP0  base address */
#define ACMP0_BASE_ADDR32                                  (0x40043000U)
#define ACMP0                                              ((volatile ACMP_Type *)(ACMP0_BASE_ADDR32))

/** Array initializer of ACMP peripheral base addresses */
#define ACMP_BASE_ADDRS                                    { ACMP0_BASE_ADDR32 }
/** Array initializer of ACMP peripheral base pointers */
#define ACMP_BASE_PTRS                                     { ACMP0 }

#define ACMP_CTRL_OFFSET32                                 (0x0000U)                    /**< Offset for Control Register */
#define ACMP_DAC_OFFSET32                                  (0x0004U)                    /**< Offset for DAC Register */
#define ACMP_MUX_OFFSET32                                  (0x0008U)                    /**< Offset for Channels Multiplexer */
#define ACMP_FILT_OFFSET32                                 (0x000CU)                    /**< Offset for Filter Register */
#define ACMP_DMACR_OFFSET32                                (0x0010U)                    /**< Offset for DMA Control Register */
#define ACMP_STS_OFFSET32                                  (0x0018U)                    /**< Offset for Status Register */
#define ACMP_INTE_OFFSET32                                 (0x001CU)                    /**< Offset for Interrupt Enable Register */
#define ACMP_CONT_OFFSET32                                 (0x0020U)                    /**< Offset for Continuous Mode Register */


/**
 * @addtogroup ACMP Register Mask
 * @{
 */
/* ACMP_CTRL Register */
#define ACMP_CTRL_EDGESEL_WIDTH                             (2)
#define ACMP_CTRL_EDGESEL_MASK                              (0x30000000U)
#define ACMP_CTRL_EDGESEL_SHIFT                             (28U)
#define ACMP_CTRL_EDGESEL(x)                                (((uint32)(((uint32)(x)) << ACMP_CTRL_EDGESEL_SHIFT)) & ACMP_CTRL_EDGESEL_MASK)
#define ACMP_CTRL_AUTODIS_MASK                              (0x200000U)
#define ACMP_CTRL_AUTODIS_SHIFT                             (21U)
#define ACMP_CTRL_AUTODIS(x)                                (((uint32)(((uint32)(x)) << ACMP_CTRL_AUTODIS_SHIFT)) & ACMP_CTRL_AUTODIS_MASK)
#define ACMP_CTRL_OUTSEL_MASK                               (0x100000U)
#define ACMP_CTRL_OUTSEL_SHIFT                              (20U)
#define ACMP_CTRL_OUTSEL(x)                                 (((uint32)(((uint32)(x)) << ACMP_CTRL_OUTSEL_SHIFT)) & ACMP_CTRL_OUTSEL_MASK)
#define ACMP_CTRL_POL_MASK                                  (0x80000U)
#define ACMP_CTRL_POL_SHIFT                                 (19U)
#define ACMP_CTRL_POL(x)                                    (((uint32)(((uint32)(x)) << ACMP_CTRL_POL_SHIFT)) & ACMP_CTRL_POL_MASK)
#define ACMP_CTRL_OFFSET_MASK                               (0x40000U)
#define ACMP_CTRL_OFFSET_SHIFT                              (18U)
#define ACMP_CTRL_OFFSET(x)                                 (((uint32)(((uint32)(x)) << ACMP_CTRL_OFFSET_SHIFT)) & ACMP_CTRL_OFFSET_MASK)
#define ACMP_CTRL_HYSTVAL_WIDTH                             (2)
#define ACMP_CTRL_HYSTVAL_MASK                              (0x30000U)
#define ACMP_CTRL_HYSTVAL_SHIFT                             (16U)
#define ACMP_CTRL_HYSTVAL(x)                                (((uint32)(((uint32)(x)) << ACMP_CTRL_HYSTVAL_SHIFT)) & ACMP_CTRL_HYSTVAL_MASK)
#define ACMP_CTRL_INNSEL_WIDTH                              (2)
#define ACMP_CTRL_INNSEL_MASK                               (0x3000U)
#define ACMP_CTRL_INNSEL_SHIFT                              (12U)
#define ACMP_CTRL_INNSEL(x)                                 (((uint32)(((uint32)(x)) << ACMP_CTRL_INNSEL_SHIFT)) & ACMP_CTRL_INNSEL_MASK)
#define ACMP_CTRL_INPSEL_WIDTH                              (2)
#define ACMP_CTRL_INPSEL_MASK                               (0x300U)
#define ACMP_CTRL_INPSEL_SHIFT                              (8U)
#define ACMP_CTRL_INPSEL(x)                                 (((uint32)(((uint32)(x)) << ACMP_CTRL_INPSEL_SHIFT)) & ACMP_CTRL_INPSEL_MASK)
#define ACMP_CTRL_CLKSEL_WIDTH                              (2)
#define ACMP_CTRL_CLKSEL_MASK                               (0x40U)
#define ACMP_CTRL_CLKSEL_SHIFT                              (6U)
#define ACMP_CTRL_CLKSEL(x)                                 (((uint32)(((uint32)(x)) << ACMP_CTRL_CLKSEL_SHIFT)) & ACMP_CTRL_CLKSEL_MASK)
#define ACMP_CTRL_SMPMD_WIDTH                               (2)
#define ACMP_CTRL_SMPMD_MASK                                (0x30U)
#define ACMP_CTRL_SMPMD_SHIFT                               (4U)
#define ACMP_CTRL_SMPMD(x)                                  (((uint32)(((uint32)(x)) << ACMP_CTRL_SMPMD_SHIFT)) & ACMP_CTRL_SMPMD_MASK)
#define ACMP_CTRL_PWRMD_MASK                                (0x2U)
#define ACMP_CTRL_PWRMD_SHIFT                               (1U)
#define ACMP_CTRL_PWRMD(x)                                  (((uint32)(((uint32)(x)) << ACMP_CTRL_PWRMD_SHIFT)) & ACMP_CTRL_PWRMD_MASK)
#define ACMP_CTRL_EN_MASK                                   (0x1U)
#define ACMP_CTRL_EN_SHIFT                                  (0U)
#define ACMP_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << ACMP_CTRL_EN_SHIFT)) & ACMP_CTRL_EN_MASK)
/* ACMP_DAC Register */
#define ACMP_DAC_VAL_WIDTH                                  (8)
#define ACMP_DAC_VAL_MASK                                   (0xFF00U)
#define ACMP_DAC_VAL_SHIFT                                  (8U)
#define ACMP_DAC_VAL(x)                                     (((uint32)(((uint32)(x)) << ACMP_DAC_VAL_SHIFT)) & ACMP_DAC_VAL_MASK)
#define ACMP_DAC_EN_MASK                                    (0x1U)
#define ACMP_DAC_EN_SHIFT                                   (0U)
#define ACMP_DAC_EN(x)                                      (((uint32)(((uint32)(x)) << ACMP_DAC_EN_SHIFT)) & ACMP_DAC_EN_MASK)
/* ACMP_MUX Register */
#define ACMP_MUX_CHNSEL_WIDTH                               (3)
#define ACMP_MUX_CHNSEL_MASK                                (0x70U)
#define ACMP_MUX_CHNSEL_SHIFT                               (4U)
#define ACMP_MUX_CHNSEL(x)                                  (((uint32)(((uint32)(x)) << ACMP_MUX_CHNSEL_SHIFT)) & ACMP_MUX_CHNSEL_MASK)
#define ACMP_MUX_CHPSEL_WIDTH                               (3)
#define ACMP_MUX_CHPSEL_MASK                                (0x7U)
#define ACMP_MUX_CHPSEL_SHIFT                               (0U)
#define ACMP_MUX_CHPSEL(x)                                  (((uint32)(((uint32)(x)) << ACMP_MUX_CHPSEL_SHIFT)) & ACMP_MUX_CHPSEL_MASK)
/* ACMP_FILT Register */
#define ACMP_FILT_CLKSRC_MASK                               (0x10000U)
#define ACMP_FILT_CLKSRC_SHIFT                              (16U)
#define ACMP_FILT_CLKSRC(x)                                 (((uint32)(((uint32)(x)) << ACMP_FILT_CLKSRC_SHIFT)) & ACMP_FILT_CLKSRC_MASK)
#define ACMP_FILT_CNT_WIDTH                                 (3)
#define ACMP_FILT_CNT_MASK                                  (0x700U)
#define ACMP_FILT_CNT_SHIFT                                 (8U)
#define ACMP_FILT_CNT(x)                                    (((uint32)(((uint32)(x)) << ACMP_FILT_CNT_SHIFT)) & ACMP_FILT_CNT_MASK)
#define ACMP_FILT_PER_WIDTH                                 (8)
#define ACMP_FILT_PER_MASK                                  (0xFFU)
#define ACMP_FILT_PER_SHIFT                                 (0U)
#define ACMP_FILT_PER(x)                                    (((uint32)(((uint32)(x)) << ACMP_FILT_PER_SHIFT)) & ACMP_FILT_PER_MASK)
/* ACMP_DMACR Register */
#define ACMP_DMACR_EN_MASK                                  (0x1U)
#define ACMP_DMACR_EN_SHIFT                                 (0U)
#define ACMP_DMACR_EN(x)                                    (((uint32)(((uint32)(x)) << ACMP_DMACR_EN_SHIFT)) & ACMP_DMACR_EN_MASK)
/* ACMP_STS Register */
#define ACMP_STS_CH7OUT_MASK                                (0x80000000U)
#define ACMP_STS_CH7OUT_SHIFT                               (31U)
#define ACMP_STS_CH7OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH7OUT_SHIFT)) & ACMP_STS_CH7OUT_MASK)
#define ACMP_STS_CH6OUT_MASK                                (0x40000000U)
#define ACMP_STS_CH6OUT_SHIFT                               (30U)
#define ACMP_STS_CH6OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH6OUT_SHIFT)) & ACMP_STS_CH6OUT_MASK)
#define ACMP_STS_CH5OUT_MASK                                (0x20000000U)
#define ACMP_STS_CH5OUT_SHIFT                               (29U)
#define ACMP_STS_CH5OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH5OUT_SHIFT)) & ACMP_STS_CH5OUT_MASK)
#define ACMP_STS_CH4OUT_MASK                                (0x10000000U)
#define ACMP_STS_CH4OUT_SHIFT                               (28U)
#define ACMP_STS_CH4OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH4OUT_SHIFT)) & ACMP_STS_CH4OUT_MASK)
#define ACMP_STS_CH3OUT_MASK                                (0x8000000U)
#define ACMP_STS_CH3OUT_SHIFT                               (27U)
#define ACMP_STS_CH3OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH3OUT_SHIFT)) & ACMP_STS_CH3OUT_MASK)
#define ACMP_STS_CH2OUT_MASK                                (0x4000000U)
#define ACMP_STS_CH2OUT_SHIFT                               (26U)
#define ACMP_STS_CH2OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH2OUT_SHIFT)) & ACMP_STS_CH2OUT_MASK)
#define ACMP_STS_CH1OUT_MASK                                (0x2000000U)
#define ACMP_STS_CH1OUT_SHIFT                               (25U)
#define ACMP_STS_CH1OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH1OUT_SHIFT)) & ACMP_STS_CH1OUT_MASK)
#define ACMP_STS_CH0OUT_MASK                                (0x1000000U)
#define ACMP_STS_CH0OUT_SHIFT                               (24U)
#define ACMP_STS_CH0OUT(x)                                  (((uint32)(((uint32)(x)) << ACMP_STS_CH0OUT_SHIFT)) & ACMP_STS_CH0OUT_MASK)
#define ACMP_STS_CH7F_MASK                                  (0x800000U)
#define ACMP_STS_CH7F_SHIFT                                 (23U)
#define ACMP_STS_CH7F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH7F_SHIFT)) & ACMP_STS_CH7F_MASK)
#define ACMP_STS_CH6F_MASK                                  (0x400000U)
#define ACMP_STS_CH6F_SHIFT                                 (22U)
#define ACMP_STS_CH6F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH6F_SHIFT)) & ACMP_STS_CH6F_MASK)
#define ACMP_STS_CH5F_MASK                                  (0x200000U)
#define ACMP_STS_CH5F_SHIFT                                 (21U)
#define ACMP_STS_CH5F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH5F_SHIFT)) & ACMP_STS_CH5F_MASK)
#define ACMP_STS_CH4F_MASK                                  (0x100000U)
#define ACMP_STS_CH4F_SHIFT                                 (20U)
#define ACMP_STS_CH4F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH4F_SHIFT)) & ACMP_STS_CH4F_MASK)
#define ACMP_STS_CH3F_MASK                                  (0x80000U)
#define ACMP_STS_CH3F_SHIFT                                 (19U)
#define ACMP_STS_CH3F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH3F_SHIFT)) & ACMP_STS_CH3F_MASK)
#define ACMP_STS_CH2F_MASK                                  (0x40000U)
#define ACMP_STS_CH2F_SHIFT                                 (18U)
#define ACMP_STS_CH2F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH2F_SHIFT)) & ACMP_STS_CH2F_MASK)
#define ACMP_STS_CH1F_MASK                                  (0x20000U)
#define ACMP_STS_CH1F_SHIFT                                 (17U)
#define ACMP_STS_CH1F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH1F_SHIFT)) & ACMP_STS_CH1F_MASK)
#define ACMP_STS_CH0F_MASK                                  (0x10000U)
#define ACMP_STS_CH0F_SHIFT                                 (16U)
#define ACMP_STS_CH0F(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CH0F_SHIFT)) & ACMP_STS_CH0F_MASK)
#define ACMP_STS_CHID_WIDTH                                 (3)
#define ACMP_STS_CHID_MASK                                  (0x700U)
#define ACMP_STS_CHID_SHIFT                                 (8U)
#define ACMP_STS_CHID(x)                                    (((uint32)(((uint32)(x)) << ACMP_STS_CHID_SHIFT)) & ACMP_STS_CHID_MASK)
#define ACMP_STS_OUTNF_MASK                                 (0x4U)
#define ACMP_STS_OUTNF_SHIFT                                (2U)
#define ACMP_STS_OUTNF(x)                                   (((uint32)(((uint32)(x)) << ACMP_STS_OUTNF_SHIFT)) & ACMP_STS_OUTNF_MASK)
#define ACMP_STS_OUTPF_MASK                                 (0x2U)
#define ACMP_STS_OUTPF_SHIFT                                (1U)
#define ACMP_STS_OUTPF(x)                                   (((uint32)(((uint32)(x)) << ACMP_STS_OUTPF_SHIFT)) & ACMP_STS_OUTPF_MASK)
#define ACMP_STS_OUT_MASK                                   (0x1U)
#define ACMP_STS_OUT_SHIFT                                  (0U)
#define ACMP_STS_OUT(x)                                     (((uint32)(((uint32)(x)) << ACMP_STS_OUT_SHIFT)) & ACMP_STS_OUT_MASK)
/* ACMP_INTE Register */
#define ACMP_INTE_CONTIE_MASK                               (0x10000U)
#define ACMP_INTE_CONTIE_SHIFT                              (16U)
#define ACMP_INTE_CONTIE(x)                                 (((uint32)(((uint32)(x)) << ACMP_INTE_CONTIE_SHIFT)) & ACMP_INTE_CONTIE_MASK)
#define ACMP_INTE_IE_MASK                                   (0x1U)
#define ACMP_INTE_IE_SHIFT                                  (0U)
#define ACMP_INTE_IE(x)                                     (((uint32)(((uint32)(x)) << ACMP_INTE_IE_SHIFT)) & ACMP_INTE_IE_MASK)
/* ACMP_CONT Register */
#define ACMP_CONT_SMP_WIDTH                                 (8)
#define ACMP_CONT_SMP_MASK                                  (0xFF000000U)
#define ACMP_CONT_SMP_SHIFT                                 (24U)
#define ACMP_CONT_SMP(x)                                    (((uint32)(((uint32)(x)) << ACMP_CONT_SMP_SHIFT)) & ACMP_CONT_SMP_MASK)
#define ACMP_CONT_PER_WIDTH                                 (8)
#define ACMP_CONT_PER_MASK                                  (0xFF0000U)
#define ACMP_CONT_PER_SHIFT                                 (16U)
#define ACMP_CONT_PER(x)                                    (((uint32)(((uint32)(x)) << ACMP_CONT_PER_SHIFT)) & ACMP_CONT_PER_MASK)
#define ACMP_CONT_CH7EN_MASK                                (0x8000U)
#define ACMP_CONT_CH7EN_SHIFT                               (15U)
#define ACMP_CONT_CH7EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH7EN_SHIFT)) & ACMP_CONT_CH7EN_MASK)
#define ACMP_CONT_CH6EN_MASK                                (0x4000U)
#define ACMP_CONT_CH6EN_SHIFT                               (14U)
#define ACMP_CONT_CH6EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH6EN_SHIFT)) & ACMP_CONT_CH6EN_MASK)
#define ACMP_CONT_CH5EN_MASK                                (0x2000U)
#define ACMP_CONT_CH5EN_SHIFT                               (13U)
#define ACMP_CONT_CH5EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH5EN_SHIFT)) & ACMP_CONT_CH5EN_MASK)
#define ACMP_CONT_CH4EN_MASK                                (0x1000U)
#define ACMP_CONT_CH4EN_SHIFT                               (12U)
#define ACMP_CONT_CH4EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH4EN_SHIFT)) & ACMP_CONT_CH4EN_MASK)
#define ACMP_CONT_CH3EN_MASK                                (0x800U)
#define ACMP_CONT_CH3EN_SHIFT                               (11U)
#define ACMP_CONT_CH3EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH3EN_SHIFT)) & ACMP_CONT_CH3EN_MASK)
#define ACMP_CONT_CH2EN_MASK                                (0x400U)
#define ACMP_CONT_CH2EN_SHIFT                               (10U)
#define ACMP_CONT_CH2EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH2EN_SHIFT)) & ACMP_CONT_CH2EN_MASK)
#define ACMP_CONT_CH1EN_MASK                                (0x200U)
#define ACMP_CONT_CH1EN_SHIFT                               (9U)
#define ACMP_CONT_CH1EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH1EN_SHIFT)) & ACMP_CONT_CH1EN_MASK)
#define ACMP_CONT_CH0EN_MASK                                (0x100U)
#define ACMP_CONT_CH0EN_SHIFT                               (8U)
#define ACMP_CONT_CH0EN(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CH0EN_SHIFT)) & ACMP_CONT_CH0EN_MASK)
#define ACMP_CONT_MODE_MASK                                 (0x4U)
#define ACMP_CONT_MODE_SHIFT                                (2U)
#define ACMP_CONT_MODE(x)                                   (((uint32)(((uint32)(x)) << ACMP_CONT_MODE_SHIFT)) & ACMP_CONT_MODE_MASK)
#define ACMP_CONT_CHFIX_MASK                                (0x2U)
#define ACMP_CONT_CHFIX_SHIFT                               (1U)
#define ACMP_CONT_CHFIX(x)                                  (((uint32)(((uint32)(x)) << ACMP_CONT_CHFIX_SHIFT)) & ACMP_CONT_CHFIX_MASK)
#define ACMP_CONT_EN_MASK                                   (0x1U)
#define ACMP_CONT_EN_SHIFT                                  (0U)
#define ACMP_CONT_EN(x)                                     (((uint32)(((uint32)(x)) << ACMP_CONT_EN_SHIFT)) & ACMP_CONT_EN_MASK)


/**
 * @}
 */ /* end of group ACMP_Register_Masks */


/**
 * @}
 */ /* end of group ACMP_Peripheral_Access_Layer */

#endif /* PSIP_ACMP_H */

