/**
*   @file    pSIP_Sent.h
*   @version
*
*   @brief   AUTOSAR Sent register map
*   @details Register map for SENT
*
*   @addtogroup ADC_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Adc
*   Dependencies         : none
*
*   Autosar Version      : V4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : V2.3.0
*   Build Version        : YTM32B1LD0x_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0001
*
*   (c) Copyright 2020-2025 YTMicro Semiconductor, Inc.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef PSIP_SENT_H
#define PSIP_SENT_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              SENT REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup SENT_Peripheral_Access_Layer SENT Peripheral Access Layer
 * @{
 */


/** SENT - Size of Registers Arrays */
#define SENT_CH_COUNT           (2)

/* SENT Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 CHCTRL;                             /**< Channel Control Register, offset: 0x0004 */
    uint32 GSTS;                               /**< Global Status Register, offset: 0x0008 */
    uint32 GINTE;                              /**< Global Interrupt Register, offset: 0x000C */
    uint32 FRDY;                               /**< Fast Message Ready Register, offset: 0x0010 */
    uint32 SRDY;                               /**< Slow Serial Message Ready Register, offset: 0x0014 */
    uint32 FINTE;                              /**< Fast Message Ready Interrupt Register, offset: 0x0018 */
    uint32 SINTE;                              /**< Slow Serial Message Ready Interrupt Register, offset: 0x001C */
    uint32 DMACTRL;                            /**< DMA Control Register, offset: 0x0020 */
    uint32 CFG;                                /**< Configuration Register, offset: 0x0024 */
    uint32 NIBCFG;                             /**< Nibble Configuration Register, offset: 0x0028 */
    uint32 RESERVED0;                          /**< RESERVED0, offset: 0x002C */
    uint32 FMDATA;                             /**< Fast Message Data Register, offset: 0x0030 */
    uint32 FMCHNUM;                            /**< Fast Message Channel Number Register, offset: 0x0034 */
    uint32 FMTS;                               /**< Fast Message Time Stamp Register, offset: 0x0038 */
    uint32 SMBIT3;                             /**< Slow Serial Message Bit 3 Register, offset: 0x003C */
    uint32 SMBIT2;                             /**< Slow Serial Message Bit 2 Register, offset: 0x0040 */
    uint32 SMTS;                               /**< Slow Serial Message Time Stamp Register, offset: 0x0044 */
    uint32 RESERVED_18;                        /**< RESERVED_18, offset: 0x0048 */
    uint32 RESERVED1;                          /**< RESERVED1, offset: 0x004C */
    struct {
        uint32 CLK;                                /**< Channel n Clock Register, offset: 0x0050 */
        uint32 STS;                                /**< Channel n Status Register, offset: 0x0054 */
        uint32 INTE;                               /**< Channel n Interrupt Enable Register, offset: 0x0058 */
        uint32 CFG;                                /**< Channel n Configuration Register, offset: 0x005C */
        uint32 FMDATA;                             /**< Channel n Fast Message Data Register, offset: 0x0060 */
        uint32 FMCHNUM;                            /**< Channel n Fast Message Channel Number Register, offset: 0x0064 */
        uint32 FMTS;                               /**< Channel n Fast Message Time Stamp Register, offset: 0x0068 */
        uint32 SMBIT3;                             /**< Channel n Slow Serial Message Bit 3 Register, offset: 0x006C */
        uint32 SMBIT2;                             /**< Channel n Slow Serial Message Bit 2 Register, offset: 0x0070 */
        uint32 SMTS;                               /**< Channel n Slow Serial Message Time Stamp Register, offset: 0x0074 */
    uint32 RESERVED2[ 2];                      /**< RESERVED2, offset: 0x0078 */

    } CH[2];

} SENT_Type, *SENT_MemMapPtr;

/** Number of instances of the SENT module. */
#define SENT_INSTANCE_COUNT                        (1u)

/* SENT0  base address */
#define SENT0_BASE_ADDR32                                  (0x40021000U)
#define SENT0                                              ((volatile SENT_Type *)(SENT0_BASE_ADDR32))

/** Array initializer of SENT peripheral base addresses */
#define SENT_BASE_ADDRS                                    { SENT0_BASE_ADDR32 }
/** Array initializer of SENT peripheral base pointers */
#define SENT_BASE_PTRS                                     { SENT0 }

#define SENT_CTRL_OFFSET32                                 (0x0000U)                    /**< Offset for Control Register */
#define SENT_CHCTRL_OFFSET32                               (0x0004U)                    /**< Offset for Channel Control Register */
#define SENT_GSTS_OFFSET32                                 (0x0008U)                    /**< Offset for Global Status Register */
#define SENT_GINTE_OFFSET32                                (0x000CU)                    /**< Offset for Global Interrupt Register */
#define SENT_FRDY_OFFSET32                                 (0x0010U)                    /**< Offset for Fast Message Ready Register */
#define SENT_SRDY_OFFSET32                                 (0x0014U)                    /**< Offset for Slow Serial Message Ready Register */
#define SENT_FINTE_OFFSET32                                (0x0018U)                    /**< Offset for Fast Message Ready Interrupt Register */
#define SENT_SINTE_OFFSET32                                (0x001CU)                    /**< Offset for Slow Serial Message Ready Interrupt Register */
#define SENT_DMACTRL_OFFSET32                              (0x0020U)                    /**< Offset for DMA Control Register */
#define SENT_CFG_OFFSET32                                  (0x0024U)                    /**< Offset for Configuration Register */
#define SENT_NIBCFG_OFFSET32                               (0x0028U)                    /**< Offset for Nibble Configuration Register */
#define SENT_FMDATA_OFFSET32                               (0x0030U)                    /**< Offset for Fast Message Data Register */
#define SENT_FMCHNUM_OFFSET32                              (0x0034U)                    /**< Offset for Fast Message Channel Number Register */
#define SENT_FMTS_OFFSET32                                 (0x0038U)                    /**< Offset for Fast Message Time Stamp Register */
#define SENT_SMBIT3_OFFSET32                               (0x003CU)                    /**< Offset for Slow Serial Message Bit 3 Register */
#define SENT_SMBIT2_OFFSET32                               (0x0040U)                    /**< Offset for Slow Serial Message Bit 2 Register */
#define SENT_SMTS_OFFSET32                                 (0x0044U)                    /**< Offset for Slow Serial Message Time Stamp Register */
#define SENT_CH_OFFSET32(x)                                (0x0050U + ((x) * (48U)))    /**< Offset for Channel Structure */

#define SENT_CH_CLK_OFFSET32(x)                            (0x0050U + ((x) * (48U)))    /**< Offset for Channel n Clock Register */
#define SENT_CH_STS_OFFSET32(x)                            (0x0054U + ((x) * (48U)))    /**< Offset for Channel n Status Register */
#define SENT_CH_INTE_OFFSET32(x)                           (0x0058U + ((x) * (48U)))    /**< Offset for Channel n Interrupt Enable Register */
#define SENT_CH_CFG_OFFSET32(x)                            (0x005CU + ((x) * (48U)))    /**< Offset for Channel n Configuration Register */
#define SENT_CH_FMDATA_OFFSET32(x)                         (0x0060U + ((x) * (48U)))    /**< Offset for Channel n Fast Message Data Register */
#define SENT_CH_FMCHNUM_OFFSET32(x)                        (0x0064U + ((x) * (48U)))    /**< Offset for Channel n Fast Message Channel Number Register */
#define SENT_CH_FMTS_OFFSET32(x)                           (0x0068U + ((x) * (48U)))    /**< Offset for Channel n Fast Message Time Stamp Register */
#define SENT_CH_SMBIT3_OFFSET32(x)                         (0x006CU + ((x) * (48U)))    /**< Offset for Channel n Slow Serial Message Bit 3 Register */
#define SENT_CH_SMBIT2_OFFSET32(x)                         (0x0070U + ((x) * (48U)))    /**< Offset for Channel n Slow Serial Message Bit 2 Register */
#define SENT_CH_SMTS_OFFSET32(x)                           (0x0074U + ((x) * (48U)))    /**< Offset for Channel n Slow Serial Message Time Stamp Register */



/**
 * @addtogroup SENT Register Mask
 * @{
 */
/* SENT_CTRL Register */
#define SENT_CTRL_EN_MASK                                   (0x1U)
#define SENT_CTRL_EN_SHIFT                                  (0U)
#define SENT_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << SENT_CTRL_EN_SHIFT)) & SENT_CTRL_EN_MASK)
/* SENT_CHCTRL Register */
#define SENT_CHCTRL_CH1EN_MASK                              (0x2U)
#define SENT_CHCTRL_CH1EN_SHIFT                             (1U)
#define SENT_CHCTRL_CH1EN(x)                                (((uint32)(((uint32)(x)) << SENT_CHCTRL_CH1EN_SHIFT)) & SENT_CHCTRL_CH1EN_MASK)
#define SENT_CHCTRL_CH0EN_MASK                              (0x1U)
#define SENT_CHCTRL_CH0EN_SHIFT                             (0U)
#define SENT_CHCTRL_CH0EN(x)                                (((uint32)(((uint32)(x)) << SENT_CHCTRL_CH0EN_SHIFT)) & SENT_CHCTRL_CH0EN_MASK)
/* SENT_GSTS Register */
#define SENT_GSTS_CH1ERR_MASK                               (0x20000U)
#define SENT_GSTS_CH1ERR_SHIFT                              (17U)
#define SENT_GSTS_CH1ERR(x)                                 (((uint32)(((uint32)(x)) << SENT_GSTS_CH1ERR_SHIFT)) & SENT_GSTS_CH1ERR_MASK)
#define SENT_GSTS_CH0ERR_MASK                               (0x10000U)
#define SENT_GSTS_CH0ERR_SHIFT                              (16U)
#define SENT_GSTS_CH0ERR(x)                                 (((uint32)(((uint32)(x)) << SENT_GSTS_CH0ERR_SHIFT)) & SENT_GSTS_CH0ERR_MASK)
#define SENT_GSTS_WUF_MASK                                  (0x8U)
#define SENT_GSTS_WUF_SHIFT                                 (3U)
#define SENT_GSTS_WUF(x)                                    (((uint32)(((uint32)(x)) << SENT_GSTS_WUF_SHIFT)) & SENT_GSTS_WUF_MASK)
#define SENT_GSTS_FMFO_MASK                                 (0x4U)
#define SENT_GSTS_FMFO_SHIFT                                (2U)
#define SENT_GSTS_FMFO(x)                                   (((uint32)(((uint32)(x)) << SENT_GSTS_FMFO_SHIFT)) & SENT_GSTS_FMFO_MASK)
#define SENT_GSTS_FMDU_MASK                                 (0x2U)
#define SENT_GSTS_FMDU_SHIFT                                (1U)
#define SENT_GSTS_FMDU(x)                                   (((uint32)(((uint32)(x)) << SENT_GSTS_FMDU_SHIFT)) & SENT_GSTS_FMDU_MASK)
#define SENT_GSTS_SMDU_MASK                                 (0x1U)
#define SENT_GSTS_SMDU_SHIFT                                (0U)
#define SENT_GSTS_SMDU(x)                                   (((uint32)(((uint32)(x)) << SENT_GSTS_SMDU_SHIFT)) & SENT_GSTS_SMDU_MASK)
/* SENT_GINTE Register */
#define SENT_GINTE_WUIE_MASK                                (0x8U)
#define SENT_GINTE_WUIE_SHIFT                               (3U)
#define SENT_GINTE_WUIE(x)                                  (((uint32)(((uint32)(x)) << SENT_GINTE_WUIE_SHIFT)) & SENT_GINTE_WUIE_MASK)
#define SENT_GINTE_FMFOIE_MASK                              (0x4U)
#define SENT_GINTE_FMFOIE_SHIFT                             (2U)
#define SENT_GINTE_FMFOIE(x)                                (((uint32)(((uint32)(x)) << SENT_GINTE_FMFOIE_SHIFT)) & SENT_GINTE_FMFOIE_MASK)
#define SENT_GINTE_FMDUIE_MASK                              (0x2U)
#define SENT_GINTE_FMDUIE_SHIFT                             (1U)
#define SENT_GINTE_FMDUIE(x)                                (((uint32)(((uint32)(x)) << SENT_GINTE_FMDUIE_SHIFT)) & SENT_GINTE_FMDUIE_MASK)
#define SENT_GINTE_SMDUIE_MASK                              (0x1U)
#define SENT_GINTE_SMDUIE_SHIFT                             (0U)
#define SENT_GINTE_SMDUIE(x)                                (((uint32)(((uint32)(x)) << SENT_GINTE_SMDUIE_SHIFT)) & SENT_GINTE_SMDUIE_MASK)
/* SENT_FRDY Register */
#define SENT_FRDY_CH1FRDY_MASK                              (0x2U)
#define SENT_FRDY_CH1FRDY_SHIFT                             (1U)
#define SENT_FRDY_CH1FRDY(x)                                (((uint32)(((uint32)(x)) << SENT_FRDY_CH1FRDY_SHIFT)) & SENT_FRDY_CH1FRDY_MASK)
#define SENT_FRDY_CH0FRDY_MASK                              (0x1U)
#define SENT_FRDY_CH0FRDY_SHIFT                             (0U)
#define SENT_FRDY_CH0FRDY(x)                                (((uint32)(((uint32)(x)) << SENT_FRDY_CH0FRDY_SHIFT)) & SENT_FRDY_CH0FRDY_MASK)
/* SENT_SRDY Register */
#define SENT_SRDY_CH1SRDY_MASK                              (0x2U)
#define SENT_SRDY_CH1SRDY_SHIFT                             (1U)
#define SENT_SRDY_CH1SRDY(x)                                (((uint32)(((uint32)(x)) << SENT_SRDY_CH1SRDY_SHIFT)) & SENT_SRDY_CH1SRDY_MASK)
#define SENT_SRDY_CH0SRDY_MASK                              (0x1U)
#define SENT_SRDY_CH0SRDY_SHIFT                             (0U)
#define SENT_SRDY_CH0SRDY(x)                                (((uint32)(((uint32)(x)) << SENT_SRDY_CH0SRDY_SHIFT)) & SENT_SRDY_CH0SRDY_MASK)
/* SENT_FINTE Register */
#define SENT_FINTE_CH1FRIE_MASK                             (0x2U)
#define SENT_FINTE_CH1FRIE_SHIFT                            (1U)
#define SENT_FINTE_CH1FRIE(x)                               (((uint32)(((uint32)(x)) << SENT_FINTE_CH1FRIE_SHIFT)) & SENT_FINTE_CH1FRIE_MASK)
#define SENT_FINTE_CH0FRIE_MASK                             (0x1U)
#define SENT_FINTE_CH0FRIE_SHIFT                            (0U)
#define SENT_FINTE_CH0FRIE(x)                               (((uint32)(((uint32)(x)) << SENT_FINTE_CH0FRIE_SHIFT)) & SENT_FINTE_CH0FRIE_MASK)
/* SENT_SINTE Register */
#define SENT_SINTE_CH1SRIE_MASK                             (0x2U)
#define SENT_SINTE_CH1SRIE_SHIFT                            (1U)
#define SENT_SINTE_CH1SRIE(x)                               (((uint32)(((uint32)(x)) << SENT_SINTE_CH1SRIE_SHIFT)) & SENT_SINTE_CH1SRIE_MASK)
#define SENT_SINTE_CH0SRIE_MASK                             (0x1U)
#define SENT_SINTE_CH0SRIE_SHIFT                            (0U)
#define SENT_SINTE_CH0SRIE(x)                               (((uint32)(((uint32)(x)) << SENT_SINTE_CH0SRIE_SHIFT)) & SENT_SINTE_CH0SRIE_MASK)
/* SENT_DMACTRL Register */
#define SENT_DMACTRL_CH1FDMA_MASK                           (0x20000U)
#define SENT_DMACTRL_CH1FDMA_SHIFT                          (17U)
#define SENT_DMACTRL_CH1FDMA(x)                             (((uint32)(((uint32)(x)) << SENT_DMACTRL_CH1FDMA_SHIFT)) & SENT_DMACTRL_CH1FDMA_MASK)
#define SENT_DMACTRL_CH0FDMA_MASK                           (0x10000U)
#define SENT_DMACTRL_CH0FDMA_SHIFT                          (16U)
#define SENT_DMACTRL_CH0FDMA(x)                             (((uint32)(((uint32)(x)) << SENT_DMACTRL_CH0FDMA_SHIFT)) & SENT_DMACTRL_CH0FDMA_MASK)
#define SENT_DMACTRL_CH1SDMA_MASK                           (0x2U)
#define SENT_DMACTRL_CH1SDMA_SHIFT                          (1U)
#define SENT_DMACTRL_CH1SDMA(x)                             (((uint32)(((uint32)(x)) << SENT_DMACTRL_CH1SDMA_SHIFT)) & SENT_DMACTRL_CH1SDMA_MASK)
#define SENT_DMACTRL_CH0SDMA_MASK                           (0x1U)
#define SENT_DMACTRL_CH0SDMA_SHIFT                          (0U)
#define SENT_DMACTRL_CH0SDMA(x)                             (((uint32)(((uint32)(x)) << SENT_DMACTRL_CH0SDMA_SHIFT)) & SENT_DMACTRL_CH0SDMA_MASK)
/* SENT_CFG Register */
#define SENT_CFG_TSPRSC_MASK                                (0xFF000000U)
#define SENT_CFG_TSPRSC_SHIFT                               (24U)
#define SENT_CFG_TSPRSC(x)                                  (((uint32)(((uint32)(x)) << SENT_CFG_TSPRSC_SHIFT)) & SENT_CFG_TSPRSC_MASK)
#define SENT_CFG_FIFOWM_MASK                                (0x30000U)
#define SENT_CFG_FIFOWM_SHIFT                               (16U)
#define SENT_CFG_FIFOWM(x)                                  (((uint32)(((uint32)(x)) << SENT_CFG_FIFOWM_SHIFT)) & SENT_CFG_FIFOWM_MASK)
#define SENT_CFG_OVW_MASK                                   (0x10U)
#define SENT_CFG_OVW_SHIFT                                  (4U)
#define SENT_CFG_OVW(x)                                     (((uint32)(((uint32)(x)) << SENT_CFG_OVW_SHIFT)) & SENT_CFG_OVW_MASK)
#define SENT_CFG_FIFOEN_MASK                                (0x8U)
#define SENT_CFG_FIFOEN_SHIFT                               (3U)
#define SENT_CFG_FIFOEN(x)                                  (((uint32)(((uint32)(x)) << SENT_CFG_FIFOEN_SHIFT)) & SENT_CFG_FIFOEN_MASK)
#define SENT_CFG_FASTCLR_MASK                               (0x4U)
#define SENT_CFG_FASTCLR_SHIFT                              (2U)
#define SENT_CFG_FASTCLR(x)                                 (((uint32)(((uint32)(x)) << SENT_CFG_FASTCLR_SHIFT)) & SENT_CFG_FASTCLR_MASK)
#define SENT_CFG_SLPACK_MASK                                (0x2U)
#define SENT_CFG_SLPACK_SHIFT                               (1U)
#define SENT_CFG_SLPACK(x)                                  (((uint32)(((uint32)(x)) << SENT_CFG_SLPACK_SHIFT)) & SENT_CFG_SLPACK_MASK)
#define SENT_CFG_DBGFRZ_MASK                                (0x1U)
#define SENT_CFG_DBGFRZ_SHIFT                               (0U)
#define SENT_CFG_DBGFRZ(x)                                  (((uint32)(((uint32)(x)) << SENT_CFG_DBGFRZ_SHIFT)) & SENT_CFG_DBGFRZ_MASK)
/* SENT_NIBCFG Register */
#define SENT_NIBCFG_NIBCH1_MASK                             (0x70U)
#define SENT_NIBCFG_NIBCH1_SHIFT                            (4U)
#define SENT_NIBCFG_NIBCH1(x)                               (((uint32)(((uint32)(x)) << SENT_NIBCFG_NIBCH1_SHIFT)) & SENT_NIBCFG_NIBCH1_MASK)
#define SENT_NIBCFG_NIBCH0_MASK                             (0x7U)
#define SENT_NIBCFG_NIBCH0_SHIFT                            (0U)
#define SENT_NIBCFG_NIBCH0(x)                               (((uint32)(((uint32)(x)) << SENT_NIBCFG_NIBCH0_SHIFT)) & SENT_NIBCFG_NIBCH0_MASK)
/* SENT_FMDATA Register */
#define SENT_FMDATA_SCNIB_MASK                              (0xF0000000U)
#define SENT_FMDATA_SCNIB_SHIFT                             (28U)
#define SENT_FMDATA_SCNIB(x)                                (((uint32)(((uint32)(x)) << SENT_FMDATA_SCNIB_SHIFT)) & SENT_FMDATA_SCNIB_MASK)
#define SENT_FMDATA_DNIB0_MASK                              (0xF000000U)
#define SENT_FMDATA_DNIB0_SHIFT                             (24U)
#define SENT_FMDATA_DNIB0(x)                                (((uint32)(((uint32)(x)) << SENT_FMDATA_DNIB0_SHIFT)) & SENT_FMDATA_DNIB0_MASK)
#define SENT_FMDATA_DNIB1_MASK                              (0xF00000U)
#define SENT_FMDATA_DNIB1_SHIFT                             (20U)
#define SENT_FMDATA_DNIB1(x)                                (((uint32)(((uint32)(x)) << SENT_FMDATA_DNIB1_SHIFT)) & SENT_FMDATA_DNIB1_MASK)
#define SENT_FMDATA_DNIB2_MASK                              (0xF0000U)
#define SENT_FMDATA_DNIB2_SHIFT                             (16U)
#define SENT_FMDATA_DNIB2(x)                                (((uint32)(((uint32)(x)) << SENT_FMDATA_DNIB2_SHIFT)) & SENT_FMDATA_DNIB2_MASK)
#define SENT_FMDATA_DNIB3_MASK                              (0xF000U)
#define SENT_FMDATA_DNIB3_SHIFT                             (12U)
#define SENT_FMDATA_DNIB3(x)                                (((uint32)(((uint32)(x)) << SENT_FMDATA_DNIB3_SHIFT)) & SENT_FMDATA_DNIB3_MASK)
#define SENT_FMDATA_DNIB4_MASK                              (0xF00U)
#define SENT_FMDATA_DNIB4_SHIFT                             (8U)
#define SENT_FMDATA_DNIB4(x)                                (((uint32)(((uint32)(x)) << SENT_FMDATA_DNIB4_SHIFT)) & SENT_FMDATA_DNIB4_MASK)
#define SENT_FMDATA_DNIB5_MASK                              (0xF0U)
#define SENT_FMDATA_DNIB5_SHIFT                             (4U)
#define SENT_FMDATA_DNIB5(x)                                (((uint32)(((uint32)(x)) << SENT_FMDATA_DNIB5_SHIFT)) & SENT_FMDATA_DNIB5_MASK)
#define SENT_FMDATA_FCRC_MASK                               (0xFU)
#define SENT_FMDATA_FCRC_SHIFT                              (0U)
#define SENT_FMDATA_FCRC(x)                                 (((uint32)(((uint32)(x)) << SENT_FMDATA_FCRC_SHIFT)) & SENT_FMDATA_FCRC_MASK)
/* SENT_FMCHNUM Register */
#define SENT_FMCHNUM_CHNUM_MASK                             (0xFU)
#define SENT_FMCHNUM_CHNUM_SHIFT                            (0U)
#define SENT_FMCHNUM_CHNUM(x)                               (((uint32)(((uint32)(x)) << SENT_FMCHNUM_CHNUM_SHIFT)) & SENT_FMCHNUM_CHNUM_MASK)
/* SENT_FMTS Register */
#define SENT_FMTS_TS_MASK                                   (0xFFFFFFFFU)
#define SENT_FMTS_TS_SHIFT                                  (0U)
#define SENT_FMTS_TS(x)                                     (((uint32)(((uint32)(x)) << SENT_FMTS_TS_SHIFT)) & SENT_FMTS_TS_MASK)
/* SENT_SMBIT3 Register */
#define SENT_SMBIT3_ID7_4_ID3_0_MASK                        (0xF000U)
#define SENT_SMBIT3_ID7_4_ID3_0_SHIFT                       (12U)
#define SENT_SMBIT3_ID7_4_ID3_0(x)                          (((uint32)(((uint32)(x)) << SENT_SMBIT3_ID7_4_ID3_0_SHIFT)) & SENT_SMBIT3_ID7_4_ID3_0_MASK)
#define SENT_SMBIT3_ID3_0_DATA15_12_MASK                    (0xF00U)
#define SENT_SMBIT3_ID3_0_DATA15_12_SHIFT                   (8U)
#define SENT_SMBIT3_ID3_0_DATA15_12(x)                      (((uint32)(((uint32)(x)) << SENT_SMBIT3_ID3_0_DATA15_12_SHIFT)) & SENT_SMBIT3_ID3_0_DATA15_12_MASK)
#define SENT_SMBIT3_CFG_MASK                                (0x40U)
#define SENT_SMBIT3_CFG_SHIFT                               (6U)
#define SENT_SMBIT3_CFG(x)                                  (((uint32)(((uint32)(x)) << SENT_SMBIT3_CFG_SHIFT)) & SENT_SMBIT3_CFG_MASK)
#define SENT_SMBIT3_TYPE_MASK                               (0x10U)
#define SENT_SMBIT3_TYPE_SHIFT                              (4U)
#define SENT_SMBIT3_TYPE(x)                                 (((uint32)(((uint32)(x)) << SENT_SMBIT3_TYPE_SHIFT)) & SENT_SMBIT3_TYPE_MASK)
#define SENT_SMBIT3_CHNUM_MASK                              (0xFU)
#define SENT_SMBIT3_CHNUM_SHIFT                             (0U)
#define SENT_SMBIT3_CHNUM(x)                                (((uint32)(((uint32)(x)) << SENT_SMBIT3_CHNUM_SHIFT)) & SENT_SMBIT3_CHNUM_MASK)
/* SENT_SMBIT2 Register */
#define SENT_SMBIT2_SCRC_MASK                               (0x3F0000U)
#define SENT_SMBIT2_SCRC_SHIFT                              (16U)
#define SENT_SMBIT2_SCRC(x)                                 (((uint32)(((uint32)(x)) << SENT_SMBIT2_SCRC_SHIFT)) & SENT_SMBIT2_SCRC_MASK)
#define SENT_SMBIT2_DATA_MASK                               (0xFFFU)
#define SENT_SMBIT2_DATA_SHIFT                              (0U)
#define SENT_SMBIT2_DATA(x)                                 (((uint32)(((uint32)(x)) << SENT_SMBIT2_DATA_SHIFT)) & SENT_SMBIT2_DATA_MASK)
/* SENT_SMTS Register */
#define SENT_SMTS_TS_MASK                                   (0xFFFFFFFFU)
#define SENT_SMTS_TS_SHIFT                                  (0U)
#define SENT_SMTS_TS(x)                                     (((uint32)(((uint32)(x)) << SENT_SMTS_TS_SHIFT)) & SENT_SMTS_TS_MASK)
/* SENT_CH_CLK Register */
#define SENT_CH_CLK_CMPRSC_MASK                                (0x7FFF0000U)
#define SENT_CH_CLK_CMPRSC_SHIFT                               (16U)
#define SENT_CH_CLK_CMPRSC(x)                                  (((uint32)(((uint32)(x)) << SENT_CH_CLK_CMPRSC_SHIFT)) & SENT_CH_CLK_CMPRSC_MASK)
#define SENT_CH_CLK_CMEN_MASK                                  (0x8000U)
#define SENT_CH_CLK_CMEN_SHIFT                                 (15U)
#define SENT_CH_CLK_CMEN(x)                                    (((uint32)(((uint32)(x)) << SENT_CH_CLK_CMEN_SHIFT)) & SENT_CH_CLK_CMEN_MASK)
#define SENT_CH_CLK_RPRSC_WIDTH                                (14)
#define SENT_CH_CLK_RPRSC_MASK                                 (0x3FFFU)
#define SENT_CH_CLK_RPRSC_SHIFT                                (0U)
#define SENT_CH_CLK_RPRSC(x)                                   (((uint32)(((uint32)(x)) << SENT_CH_CLK_RPRSC_SHIFT)) & SENT_CH_CLK_RPRSC_MASK)
/* SENT_CH_STS Register */
#define SENT_CH_STS_ENUMERR_MASK                               (0x4000U)
#define SENT_CH_STS_ENUMERR_SHIFT                              (14U)
#define SENT_CH_STS_ENUMERR(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_STS_ENUMERR_SHIFT)) & SENT_CH_STS_ENUMERR_MASK)
#define SENT_CH_STS_FCRCERR_MASK                               (0x2000U)
#define SENT_CH_STS_FCRCERR_SHIFT                              (13U)
#define SENT_CH_STS_FCRCERR(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_STS_FCRCERR_SHIFT)) & SENT_CH_STS_FCRCERR_MASK)
#define SENT_CH_STS_SCRCERR_MASK                               (0x1000U)
#define SENT_CH_STS_SCRCERR_SHIFT                              (12U)
#define SENT_CH_STS_SCRCERR(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_STS_SCRCERR_SHIFT)) & SENT_CH_STS_SCRCERR_MASK)
#define SENT_CH_STS_NVERR_MASK                                 (0x800U)
#define SENT_CH_STS_NVERR_SHIFT                                (11U)
#define SENT_CH_STS_NVERR(x)                                   (((uint32)(((uint32)(x)) << SENT_CH_STS_NVERR_SHIFT)) & SENT_CH_STS_NVERR_MASK)
#define SENT_CH_STS_CDERR_MASK                                 (0x400U)
#define SENT_CH_STS_CDERR_SHIFT                                (10U)
#define SENT_CH_STS_CDERR(x)                                   (((uint32)(((uint32)(x)) << SENT_CH_STS_CDERR_SHIFT)) & SENT_CH_STS_CDERR_MASK)
#define SENT_CH_STS_CLERR_MASK                                 (0x200U)
#define SENT_CH_STS_CLERR_SHIFT                                (9U)
#define SENT_CH_STS_CLERR(x)                                   (((uint32)(((uint32)(x)) << SENT_CH_STS_CLERR_SHIFT)) & SENT_CH_STS_CLERR_MASK)
#define SENT_CH_STS_PPDERR_MASK                                (0x100U)
#define SENT_CH_STS_PPDERR_SHIFT                               (8U)
#define SENT_CH_STS_PPDERR(x)                                  (((uint32)(((uint32)(x)) << SENT_CH_STS_PPDERR_SHIFT)) & SENT_CH_STS_PPDERR_MASK)
#define SENT_CH_STS_FMOF_MASK                                  (0x80U)
#define SENT_CH_STS_FMOF_SHIFT                                 (7U)
#define SENT_CH_STS_FMOF(x)                                    (((uint32)(((uint32)(x)) << SENT_CH_STS_FMOF_SHIFT)) & SENT_CH_STS_FMOF_MASK)
#define SENT_CH_STS_SMOF_MASK                                  (0x40U)
#define SENT_CH_STS_SMOF_SHIFT                                 (6U)
#define SENT_CH_STS_SMOF(x)                                    (((uint32)(((uint32)(x)) << SENT_CH_STS_SMOF_SHIFT)) & SENT_CH_STS_SMOF_MASK)
#define SENT_CH_STS_CAL_20_25_MASK                             (0x20U)
#define SENT_CH_STS_CAL_20_25_SHIFT                            (5U)
#define SENT_CH_STS_CAL_20_25(x)                               (((uint32)(((uint32)(x)) << SENT_CH_STS_CAL_20_25_SHIFT)) & SENT_CH_STS_CAL_20_25_MASK)
#define SENT_CH_STS_CALRESYNC_MASK                             (0x10U)
#define SENT_CH_STS_CALRESYNC_SHIFT                            (4U)
#define SENT_CH_STS_CALRESYNC(x)                               (((uint32)(((uint32)(x)) << SENT_CH_STS_CALRESYNC_SHIFT)) & SENT_CH_STS_CALRESYNC_MASK)
#define SENT_CH_STS_IDLE_MASK                                  (0x1U)
#define SENT_CH_STS_IDLE_SHIFT                                 (0U)
#define SENT_CH_STS_IDLE(x)                                    (((uint32)(((uint32)(x)) << SENT_CH_STS_IDLE_SHIFT)) & SENT_CH_STS_IDLE_MASK)
/* SENT_CH_INTE Register */
#define SENT_CH_INTE_ENUMERRIE_MASK                            (0x4000U)
#define SENT_CH_INTE_ENUMERRIE_SHIFT                           (14U)
#define SENT_CH_INTE_ENUMERRIE(x)                              (((uint32)(((uint32)(x)) << SENT_CH_INTE_ENUMERRIE_SHIFT)) & SENT_CH_INTE_ENUMERRIE_MASK)
#define SENT_CH_INTE_FCRCERRIE_MASK                            (0x2000U)
#define SENT_CH_INTE_FCRCERRIE_SHIFT                           (13U)
#define SENT_CH_INTE_FCRCERRIE(x)                              (((uint32)(((uint32)(x)) << SENT_CH_INTE_FCRCERRIE_SHIFT)) & SENT_CH_INTE_FCRCERRIE_MASK)
#define SENT_CH_INTE_SCRCERRIE_MASK                            (0x1000U)
#define SENT_CH_INTE_SCRCERRIE_SHIFT                           (12U)
#define SENT_CH_INTE_SCRCERRIE(x)                              (((uint32)(((uint32)(x)) << SENT_CH_INTE_SCRCERRIE_SHIFT)) & SENT_CH_INTE_SCRCERRIE_MASK)
#define SENT_CH_INTE_NVERRIE_MASK                              (0x800U)
#define SENT_CH_INTE_NVERRIE_SHIFT                             (11U)
#define SENT_CH_INTE_NVERRIE(x)                                (((uint32)(((uint32)(x)) << SENT_CH_INTE_NVERRIE_SHIFT)) & SENT_CH_INTE_NVERRIE_MASK)
#define SENT_CH_INTE_CDERRIE_MASK                              (0x400U)
#define SENT_CH_INTE_CDERRIE_SHIFT                             (10U)
#define SENT_CH_INTE_CDERRIE(x)                                (((uint32)(((uint32)(x)) << SENT_CH_INTE_CDERRIE_SHIFT)) & SENT_CH_INTE_CDERRIE_MASK)
#define SENT_CH_INTE_CLERRIE_MASK                              (0x200U)
#define SENT_CH_INTE_CLERRIE_SHIFT                             (9U)
#define SENT_CH_INTE_CLERRIE(x)                                (((uint32)(((uint32)(x)) << SENT_CH_INTE_CLERRIE_SHIFT)) & SENT_CH_INTE_CLERRIE_MASK)
#define SENT_CH_INTE_PPDERRIE_MASK                             (0x100U)
#define SENT_CH_INTE_PPDERRIE_SHIFT                            (8U)
#define SENT_CH_INTE_PPDERRIE(x)                               (((uint32)(((uint32)(x)) << SENT_CH_INTE_PPDERRIE_SHIFT)) & SENT_CH_INTE_PPDERRIE_MASK)
#define SENT_CH_INTE_FMOFIE_MASK                               (0x80U)
#define SENT_CH_INTE_FMOFIE_SHIFT                              (7U)
#define SENT_CH_INTE_FMOFIE(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_INTE_FMOFIE_SHIFT)) & SENT_CH_INTE_FMOFIE_MASK)
#define SENT_CH_INTE_SMOFIE_MASK                               (0x40U)
#define SENT_CH_INTE_SMOFIE_SHIFT                              (6U)
#define SENT_CH_INTE_SMOFIE(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_INTE_SMOFIE_SHIFT)) & SENT_CH_INTE_SMOFIE_MASK)
#define SENT_CH_INTE_CAL_20_25_IE_MASK                         (0x20U)
#define SENT_CH_INTE_CAL_20_25_IE_SHIFT                        (5U)
#define SENT_CH_INTE_CAL_20_25_IE(x)                           (((uint32)(((uint32)(x)) << SENT_CH_INTE_CAL_20_25_IE_SHIFT)) & SENT_CH_INTE_CAL_20_25_IE_MASK)
#define SENT_CH_INTE_CALRESYNCIE_MASK                          (0x10U)
#define SENT_CH_INTE_CALRESYNCIE_SHIFT                         (4U)
#define SENT_CH_INTE_CALRESYNCIE(x)                            (((uint32)(((uint32)(x)) << SENT_CH_INTE_CALRESYNCIE_SHIFT)) & SENT_CH_INTE_CALRESYNCIE_MASK)
/* SENT_CH_CFG Register */
#define SENT_CH_CFG_FCRCCHK_MASK                               (0x1000000U)
#define SENT_CH_CFG_FCRCCHK_SHIFT                              (24U)
#define SENT_CH_CFG_FCRCCHK(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_CFG_FCRCCHK_SHIFT)) & SENT_CH_CFG_FCRCCHK_MASK)
#define SENT_CH_CFG_SCCHK_MASK                                 (0x800000U)
#define SENT_CH_CFG_SCCHK_SHIFT                                (23U)
#define SENT_CH_CFG_SCCHK(x)                                   (((uint32)(((uint32)(x)) << SENT_CH_CFG_SCCHK_SHIFT)) & SENT_CH_CFG_SCCHK_MASK)
#define SENT_CH_CFG_PPEN_MASK                                  (0x400000U)
#define SENT_CH_CFG_PPEN_SHIFT                                 (22U)
#define SENT_CH_CFG_PPEN(x)                                    (((uint32)(((uint32)(x)) << SENT_CH_CFG_PPEN_SHIFT)) & SENT_CH_CFG_PPEN_MASK)
#define SENT_CH_CFG_SCRCTYPE_MASK                              (0x200000U)
#define SENT_CH_CFG_SCRCTYPE_SHIFT                             (21U)
#define SENT_CH_CFG_SCRCTYPE(x)                                (((uint32)(((uint32)(x)) << SENT_CH_CFG_SCRCTYPE_SHIFT)) & SENT_CH_CFG_SCRCTYPE_MASK)
#define SENT_CH_CFG_FCRCSCEN_MASK                              (0x100000U)
#define SENT_CH_CFG_FCRCSCEN_SHIFT                             (20U)
#define SENT_CH_CFG_FCRCSCEN(x)                                (((uint32)(((uint32)(x)) << SENT_CH_CFG_FCRCSCEN_SHIFT)) & SENT_CH_CFG_FCRCSCEN_MASK)
#define SENT_CH_CFG_FCRCTYPE_MASK                              (0x80000U)
#define SENT_CH_CFG_FCRCTYPE_SHIFT                             (19U)
#define SENT_CH_CFG_FCRCTYPE(x)                                (((uint32)(((uint32)(x)) << SENT_CH_CFG_FCRCTYPE_SHIFT)) & SENT_CH_CFG_FCRCTYPE_MASK)
#define SENT_CH_CFG_PPCHKSEL_MASK                              (0x40000U)
#define SENT_CH_CFG_PPCHKSEL_SHIFT                             (18U)
#define SENT_CH_CFG_PPCHKSEL(x)                                (((uint32)(((uint32)(x)) << SENT_CH_CFG_PPCHKSEL_SHIFT)) & SENT_CH_CFG_PPCHKSEL_MASK)
#define SENT_CH_CFG_CALRNG_MASK                                (0x20000U)
#define SENT_CH_CFG_CALRNG_SHIFT                               (17U)
#define SENT_CH_CFG_CALRNG(x)                                  (((uint32)(((uint32)(x)) << SENT_CH_CFG_CALRNG_SHIFT)) & SENT_CH_CFG_CALRNG_MASK)
#define SENT_CH_CFG_DCHGEN_MASK                                (0x10000U)
#define SENT_CH_CFG_DCHGEN_SHIFT                               (16U)
#define SENT_CH_CFG_DCHGEN(x)                                  (((uint32)(((uint32)(x)) << SENT_CH_CFG_DCHGEN_SHIFT)) & SENT_CH_CFG_DCHGEN_MASK)
#define SENT_CH_CFG_FILCNT_MASK                                (0xFF00U)
#define SENT_CH_CFG_FILCNT_SHIFT                               (8U)
#define SENT_CH_CFG_FILCNT(x)                                  (((uint32)(((uint32)(x)) << SENT_CH_CFG_FILCNT_SHIFT)) & SENT_CH_CFG_FILCNT_MASK)
#define SENT_CH_CFG_IDLECNT_MASK                               (0xFU)
#define SENT_CH_CFG_IDLECNT_SHIFT                              (0U)
#define SENT_CH_CFG_IDLECNT(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_CFG_IDLECNT_SHIFT)) & SENT_CH_CFG_IDLECNT_MASK)
/* SENT_CH_FMDATA Register */
#define SENT_CH_FMDATA_SCNIB_MASK                              (0xF0000000U)
#define SENT_CH_FMDATA_SCNIB_SHIFT                             (28U)
#define SENT_CH_FMDATA_SCNIB(x)                                (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_SCNIB_SHIFT)) & SENT_CH_FMDATA_SCNIB_MASK)
#define SENT_CH_FMDATA_DNIB0_MASK                              (0xF000000U)
#define SENT_CH_FMDATA_DNIB0_SHIFT                             (24U)
#define SENT_CH_FMDATA_DNIB0(x)                                (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_DNIB0_SHIFT)) & SENT_CH_FMDATA_DNIB0_MASK)
#define SENT_CH_FMDATA_DNIB1_MASK                              (0xF00000U)
#define SENT_CH_FMDATA_DNIB1_SHIFT                             (20U)
#define SENT_CH_FMDATA_DNIB1(x)                                (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_DNIB1_SHIFT)) & SENT_CH_FMDATA_DNIB1_MASK)
#define SENT_CH_FMDATA_DNIB2_MASK                              (0xF0000U)
#define SENT_CH_FMDATA_DNIB2_SHIFT                             (16U)
#define SENT_CH_FMDATA_DNIB2(x)                                (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_DNIB2_SHIFT)) & SENT_CH_FMDATA_DNIB2_MASK)
#define SENT_CH_FMDATA_DNIB3_MASK                              (0xF000U)
#define SENT_CH_FMDATA_DNIB3_SHIFT                             (12U)
#define SENT_CH_FMDATA_DNIB3(x)                                (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_DNIB3_SHIFT)) & SENT_CH_FMDATA_DNIB3_MASK)
#define SENT_CH_FMDATA_DNIB4_MASK                              (0xF00U)
#define SENT_CH_FMDATA_DNIB4_SHIFT                             (8U)
#define SENT_CH_FMDATA_DNIB4(x)                                (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_DNIB4_SHIFT)) & SENT_CH_FMDATA_DNIB4_MASK)
#define SENT_CH_FMDATA_DNIB5_MASK                              (0xF0U)
#define SENT_CH_FMDATA_DNIB5_SHIFT                             (4U)
#define SENT_CH_FMDATA_DNIB5(x)                                (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_DNIB5_SHIFT)) & SENT_CH_FMDATA_DNIB5_MASK)
#define SENT_CH_FMDATA_CRC4_MASK                               (0xFU)
#define SENT_CH_FMDATA_CRC4_SHIFT                              (0U)
#define SENT_CH_FMDATA_CRC4(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_FMDATA_CRC4_SHIFT)) & SENT_CH_FMDATA_CRC4_MASK)
/* SENT_CH_FMCHNUM Register */
#define SENT_CH_FMCHNUM_CHNUM_MASK                             (0xFU)
#define SENT_CH_FMCHNUM_CHNUM_SHIFT                            (0U)
#define SENT_CH_FMCHNUM_CHNUM(x)                               (((uint32)(((uint32)(x)) << SENT_CH_FMCHNUM_CHNUM_SHIFT)) & SENT_CH_FMCHNUM_CHNUM_MASK)
/* SENT_CH_FMTS Register */
#define SENT_CH_FMTS_TS_MASK                                   (0xFFFFFFFFU)
#define SENT_CH_FMTS_TS_SHIFT                                  (0U)
#define SENT_CH_FMTS_TS(x)                                     (((uint32)(((uint32)(x)) << SENT_CH_FMTS_TS_SHIFT)) & SENT_CH_FMTS_TS_MASK)
/* SENT_CH_SMBIT3 Register */
#define SENT_CH_SMBIT3_ID7_4_ID3_0_MASK                        (0xF000U)
#define SENT_CH_SMBIT3_ID7_4_ID3_0_SHIFT                       (12U)
#define SENT_CH_SMBIT3_ID7_4_ID3_0(x)                          (((uint32)(((uint32)(x)) << SENT_CH_SMBIT3_ID7_4_ID3_0_SHIFT)) & SENT_CH_SMBIT3_ID7_4_ID3_0_MASK)
#define SENT_CH_SMBIT3_ID3_0_DATA15_12_MASK                    (0xF00U)
#define SENT_CH_SMBIT3_ID3_0_DATA15_12_SHIFT                   (8U)
#define SENT_CH_SMBIT3_ID3_0_DATA15_12(x)                      (((uint32)(((uint32)(x)) << SENT_CH_SMBIT3_ID3_0_DATA15_12_SHIFT)) & SENT_CH_SMBIT3_ID3_0_DATA15_12_MASK)
#define SENT_CH_SMBIT3_CFG_MASK                                (0x40U)
#define SENT_CH_SMBIT3_CFG_SHIFT                               (6U)
#define SENT_CH_SMBIT3_CFG(x)                                  (((uint32)(((uint32)(x)) << SENT_CH_SMBIT3_CFG_SHIFT)) & SENT_CH_SMBIT3_CFG_MASK)
#define SENT_CH_SMBIT3_TYPE_MASK                               (0x10U)
#define SENT_CH_SMBIT3_TYPE_SHIFT                              (4U)
#define SENT_CH_SMBIT3_TYPE(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_SMBIT3_TYPE_SHIFT)) & SENT_CH_SMBIT3_TYPE_MASK)
#define SENT_CH_SMBIT3_CHNUM_MASK                              (0xFU)
#define SENT_CH_SMBIT3_CHNUM_SHIFT                             (0U)
#define SENT_CH_SMBIT3_CHNUM(x)                                (((uint32)(((uint32)(x)) << SENT_CH_SMBIT3_CHNUM_SHIFT)) & SENT_CH_SMBIT3_CHNUM_MASK)
/* SENT_CH_SMBIT2 Register */
#define SENT_CH_SMBIT2_SMCRC_MASK                              (0x3F0000U)
#define SENT_CH_SMBIT2_SMCRC_SHIFT                             (16U)
#define SENT_CH_SMBIT2_SMCRC(x)                                (((uint32)(((uint32)(x)) << SENT_CH_SMBIT2_SMCRC_SHIFT)) & SENT_CH_SMBIT2_SMCRC_MASK)
#define SENT_CH_SMBIT2_DATA_MASK                               (0xFFFU)
#define SENT_CH_SMBIT2_DATA_SHIFT                              (0U)
#define SENT_CH_SMBIT2_DATA(x)                                 (((uint32)(((uint32)(x)) << SENT_CH_SMBIT2_DATA_SHIFT)) & SENT_CH_SMBIT2_DATA_MASK)
/* SENT_CH_SMTS Register */
#define SENT_CH_SMTS_TS_MASK                                   (0xFFFFFFFFU)
#define SENT_CH_SMTS_TS_SHIFT                                  (0U)
#define SENT_CH_SMTS_TS(x)                                     (((uint32)(((uint32)(x)) << SENT_CH_SMTS_TS_SHIFT)) & SENT_CH_SMTS_TS_MASK)



/**
 * @}
 */ /* end of group SENT_Register_Masks */


/**
 * @}
 */ /* end of group SENT_Peripheral_Access_Layer */

#endif /* PSIP_SENT_H */

