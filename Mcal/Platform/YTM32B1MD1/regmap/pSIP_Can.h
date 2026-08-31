/**
*   @file    pSIP_Can.h
*   @version
*
*   @brief   AUTOSAR Can register map
*   @details Register map for CAN
*
*   @addtogroup ADC_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Adc
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

#ifndef PSIP_CAN_H
#define PSIP_CAN_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CAN REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */


/** CAN - Size of Registers Arrays */
#define CAN_RAM_COUNT           (256)
#define CAN_RXIMR_COUNT           (64)
#define CAN_WMB_COUNT           (4)
#define CAN_HR_TIME_STAMPn_COUNT           (128)
#define CAN_ERFFELn_COUNT           (128)

/* CAN Register Layout Typedef */
typedef struct {
    uint32 MCR;                                /**< Module Configuration Register, offset: 0x0000 */
    uint32 CTRL1;                              /**< Countrol 1 Register, offset: 0x0004 */
    uint32 TIMER;                              /**< Free Running Timer Register, offset: 0x0008 */
    uint32 RESERVED0[ 1];                      /**< RESERVED0, offset: 0x000C */
    uint32 RXMGMASK;                           /**< Rx Mailboxes Global Mask Register, offset: 0x0010 */
    uint32 RX14MASK;                           /**< Rx 14 Mask Register, offset: 0x0014 */
    uint32 RX15MASK;                           /**< Rx 15 Mask Register, offset: 0x0018 */
    uint32 ECR;                                /**< Error Counter Register, offset: 0x001C */
    uint32 ESR1;                               /**< Error and Status Register, offset: 0x0020 */
    uint32 IMASK2;                             /**< Interrupt Mask 2 Register, offset: 0x0024 */
    uint32 IMASK1;                             /**< Interrupt Mask 1 Register, offset: 0x0028 */
    uint32 IFLAG2;                             /**< Interrupt Flag 2 Register, offset: 0x002C */
    uint32 IFLAG1;                             /**< Interrupt Flag 1 Register, offset: 0x0030 */
    uint32 CTRL2;                              /**< Control 2 Register, offset: 0x0034 */
    uint32 ESR2;                               /**< Error and Status 2 Register, offset: 0x0038 */
    uint32 RESERVED1[ 2];                      /**< RESERVED1, offset: 0x003C */
    uint32 CRCR;                               /**< CRC Register, offset: 0x0044 */
    uint32 RXFGMASK;                           /**< Legacy Rx FIFO Global Mask Register, offset: 0x0048 */
    uint32 RXFIR;                              /**< Legacy Rx FIFO Information Register, offset: 0x004C */
    uint32 CBT;                                /**< Bit Timing Register, offset: 0x0050 */
    uint32 RESERVED2[ 5];                      /**< RESERVED2, offset: 0x0054 */
    uint32 IMASK4;                             /**< Interrupt Mask 4 Register, offset: 0x0068 */
    uint32 IMASK3;                             /**< Interrupt Mask 3 Register, offset: 0x006C */
    uint32 IFLAG4;                             /**< Interrupt Flags 4 Register, offset: 0x0070 */
    uint32 IFLAG3;                             /**< Interrupt Flags 3 Register, offset: 0x0074 */
    uint32 RESERVED3[ 2];                      /**< RESERVED3, offset: 0x0078 */
    uint32 RAM[256];                            /**< Embeded RAM, offset: 0x0080 */
    uint32 RESERVED4[256];                      /**< RESERVED4, offset: 0x0480 */
    uint32 RXIMR[64];                          /**< RX Individual Mask Register, offset: 0x0880 */
    uint32 RESERVED5[88];                      /**< RESERVED5, offset: 0x0980 */
    uint32 MECR;                               /**< Memory Error Control Register, offset: 0x0AE0 */
    uint32 ERRIAR;                             /**< Error Injection Address Register, offset: 0x0AE4 */
    uint32 ERRIDPR;                            /**< Error Injection Data Pattern Register, offset: 0x0AE8 */
    uint32 ERRIPPR;                            /**< Error Injection Parity Pattern Register, offset: 0x0AEC */
    uint32 RERRAR;                             /**< Error Report Address Register, offset: 0x0AF0 */
    uint32 RERRDR;                             /**< Error Report Data Register, offset: 0x0AF4 */
    uint32 RERRSYNR;                           /**< Error Report Syndrome Register, offset: 0x0AF8 */
    uint32 ERRSR;                              /**< Error Status Register, offset: 0x0AFC */
    uint32 CTRL1_PN;                           /**< Pretended Networking Control 1 Register, offset: 0x0B00 */
    uint32 CTRL2_PN;                           /**< Pretended Networking Control 2 Register, offset: 0x0B04 */
    uint32 WU_MTC;                             /**< Pretended Networking Wake Up Match Register, offset: 0x0B08 */
    uint32 FLT_ID1;                            /**< Pretended Networking ID Filter 1 Register, offset: 0x0B0C */
    uint32 FLT_DLC;                            /**< Pretended Networking DLC Filter Register, offset: 0x0B10 */
    uint32 PL1_LO;                             /**< Pretended Networking Payload Low Filter 1 Register, offset: 0x0B14 */
    uint32 PL1_HI;                             /**< Pretended Networking Payload High Filter 1 Register, offset: 0x0B18 */
    uint32 FLT_ID2_IDMASK;                     /**< Pretended Networking ID Filter 2 Register, offset: 0x0B1C */
    uint32 PL2_PLMASK_LO;                      /**< Pretended Networking Payload Low Filter 2 Register, offset: 0x0B20 */
    uint32 PL2_PLMASK_HI;                      /**< Pretended Networking Payload High Filter 2 Register, offset: 0x0B24 */
    uint32 RESERVED6[ 6];                      /**< RESERVED6, offset: 0x0B28 */
    struct {
        uint32 WMBn_CS;                            /**< , offset: 0x0B40 */
        uint32 WMBn_ID;                            /**< , offset: 0x0B44 */
        uint32 WMBn_D03;                           /**< , offset: 0x0B48 */
        uint32 WMBn_D47;                           /**< , offset: 0x0B4C */

    } WMB[4];
    uint32 RESERVED7[28];                      /**< RESERVED7, offset: 0x0B80 */
    uint32 EPRS;                               /**< Enhanced CAN Bit Timing Prescalers Register, offset: 0x0BF0 */
    uint32 ENCBT;                              /**< Enhanced Nominal CAN Bit Timing Register, offset: 0x0BF4 */
    uint32 EDCBT;                              /**< Enhanced Data Phase CAN Bit Timing Register, offset: 0x0BF8 */
    uint32 ETDC;                               /**< Enhanced Transceiver Delay Compensation Register, offset: 0x0BFC */
    uint32 FDCTRL;                             /**< FD Control Register, offset: 0x0C00 */
    uint32 FDCBT;                              /**< FD Bit Timing Register, offset: 0x0C04 */
    uint32 FDCRC;                              /**< FD CRC Register, offset: 0x0C08 */
    uint32 ERFCR;                              /**< Enhanced Rx FIFO Control Register, offset: 0x0C0C */
    uint32 ERFIER;                             /**< Enhanced Rx FIFO Interrupt Enable Register, offset: 0x0C10 */
    uint32 ERFSR;                              /**< Enhanced Rx FIFO Status Register, offset: 0x0C14 */
    uint32 RESERVED8[ 6];                      /**< RESERVED8, offset: 0x0C18 */
    uint32 HR_TIME_STAMPn[128];                 /**< High Resolution Time Stamp Registers, offset: 0x0C30 */
    uint32 RESERVED9[2164];                      /**< RESERVED9, offset: 0x0E30 */
    uint32 ERFFELn[128];                        /**< Enhanced Rx FIFO Filter Element Registers, offset: 0x3000 */

} CAN_Type, *CAN_MemMapPtr;

/** Number of instances of the CAN module. */
#define CAN_INSTANCE_COUNT                        (3u)

/* CAN0  base address */
#define CAN0_BASE_ADDR32                                   (0x40030000U)
#define CAN0                                               ((volatile CAN_Type *)(CAN0_BASE_ADDR32))
/* CAN1  base address */
#define CAN1_BASE_ADDR32                                   (0x40034000U)
#define CAN1                                               ((volatile CAN_Type *)(CAN1_BASE_ADDR32))
/* CAN2  base address */
#define CAN2_BASE_ADDR32                                   (0x40038000U)
#define CAN2                                               ((volatile CAN_Type *)(CAN2_BASE_ADDR32))

/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                                     { CAN0_BASE_ADDR32,  CAN1_BASE_ADDR32,  CAN2_BASE_ADDR32 }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                                      { CAN0,  CAN1,  CAN2 }

#define CAN_MCR_OFFSET32                                   (0x0000U)                    /**< Offset for Module Configuration Register */
#define CAN_CTRL1_OFFSET32                                 (0x0004U)                    /**< Offset for Countrol 1 Register */
#define CAN_TIMER_OFFSET32                                 (0x0008U)                    /**< Offset for Free Running Timer Register */
#define CAN_RXMGMASK_OFFSET32                              (0x0010U)                    /**< Offset for Rx Mailboxes Global Mask Register */
#define CAN_RX14MASK_OFFSET32                              (0x0014U)                    /**< Offset for Rx 14 Mask Register */
#define CAN_RX15MASK_OFFSET32                              (0x0018U)                    /**< Offset for Rx 15 Mask Register */
#define CAN_ECR_OFFSET32                                   (0x001CU)                    /**< Offset for Error Counter Register */
#define CAN_ESR1_OFFSET32                                  (0x0020U)                    /**< Offset for Error and Status Register */
#define CAN_IMASK2_OFFSET32                                (0x0024U)                    /**< Offset for Interrupt Mask 2 Register */
#define CAN_IMASK1_OFFSET32                                (0x0028U)                    /**< Offset for Interrupt Mask 1 Register */
#define CAN_IFLAG2_OFFSET32                                (0x002CU)                    /**< Offset for Interrupt Flag 2 Register */
#define CAN_IFLAG1_OFFSET32                                (0x0030U)                    /**< Offset for Interrupt Flag 1 Register */
#define CAN_CTRL2_OFFSET32                                 (0x0034U)                    /**< Offset for Control 2 Register */
#define CAN_ESR2_OFFSET32                                  (0x0038U)                    /**< Offset for Error and Status 2 Register */
#define CAN_CRCR_OFFSET32                                  (0x0044U)                    /**< Offset for CRC Register */
#define CAN_RXFGMASK_OFFSET32                              (0x0048U)                    /**< Offset for Legacy Rx FIFO Global Mask Register */
#define CAN_RXFIR_OFFSET32                                 (0x004CU)                    /**< Offset for Legacy Rx FIFO Information Register */
#define CAN_CBT_OFFSET32                                   (0x0050U)                    /**< Offset for Bit Timing Register */
#define CAN_IMASK4_OFFSET32                                (0x0068U)                    /**< Offset for Interrupt Mask 4 Register */
#define CAN_IMASK3_OFFSET32                                (0x006CU)                    /**< Offset for Interrupt Mask 3 Register */
#define CAN_IFLAG4_OFFSET32                                (0x0070U)                    /**< Offset for Interrupt Flags 4 Register */
#define CAN_IFLAG3_OFFSET32                                (0x0074U)                    /**< Offset for Interrupt Flags 3 Register */
#define CAN_RAM_OFFSET32(x)                                (0x0080U + ((x) * (4U)))     /**< Offset for Embeded RAM */
#define CAN_RXIMR_OFFSET32(x)                              (0x0880U + ((x) * (4U)))     /**< Offset for RX Individual Mask Register */
#define CAN_MECR_OFFSET32                                  (0x0AE0U)                    /**< Offset for Memory Error Control Register */
#define CAN_ERRIAR_OFFSET32                                (0x0AE4U)                    /**< Offset for Error Injection Address Register */
#define CAN_ERRIDPR_OFFSET32                               (0x0AE8U)                    /**< Offset for Error Injection Data Pattern Register */
#define CAN_ERRIPPR_OFFSET32                               (0x0AECU)                    /**< Offset for Error Injection Parity Pattern Register */
#define CAN_RERRAR_OFFSET32                                (0x0AF0U)                    /**< Offset for Error Report Address Register */
#define CAN_RERRDR_OFFSET32                                (0x0AF4U)                    /**< Offset for Error Report Data Register */
#define CAN_RERRSYNR_OFFSET32                              (0x0AF8U)                    /**< Offset for Error Report Syndrome Register */
#define CAN_ERRSR_OFFSET32                                 (0x0AFCU)                    /**< Offset for Error Status Register */
#define CAN_CTRL1_PN_OFFSET32                              (0x0B00U)                    /**< Offset for Pretended Networking Control 1 Register */
#define CAN_CTRL2_PN_OFFSET32                              (0x0B04U)                    /**< Offset for Pretended Networking Control 2 Register */
#define CAN_WU_MTC_OFFSET32                                (0x0B08U)                    /**< Offset for Pretended Networking Wake Up Match Register */
#define CAN_FLT_ID1_OFFSET32                               (0x0B0CU)                    /**< Offset for Pretended Networking ID Filter 1 Register */
#define CAN_FLT_DLC_OFFSET32                               (0x0B10U)                    /**< Offset for Pretended Networking DLC Filter Register */
#define CAN_PL1_LO_OFFSET32                                (0x0B14U)                    /**< Offset for Pretended Networking Payload Low Filter 1 Register */
#define CAN_PL1_HI_OFFSET32                                (0x0B18U)                    /**< Offset for Pretended Networking Payload High Filter 1 Register */
#define CAN_FLT_ID2_IDMASK_OFFSET32                        (0x0B1CU)                    /**< Offset for Pretended Networking ID Filter 2 Register */
#define CAN_PL2_PLMASK_LO_OFFSET32                         (0x0B20U)                    /**< Offset for Pretended Networking Payload Low Filter 2 Register */
#define CAN_PL2_PLMASK_HI_OFFSET32                         (0x0B24U)                    /**< Offset for Pretended Networking Payload High Filter 2 Register */
#define CAN_WMB_OFFSET32(x)                                (0x0B40U + ((x) * (16U)))    /**< Offset for Wake Up Message Buffer Register */

#define CAN_WMB_WMBn_CS_OFFSET32(x)                        (0x0B40U + ((x) * (16U)))    /**< Offset for  */
#define CAN_WMB_WMBn_ID_OFFSET32(x)                        (0x0B44U + ((x) * (16U)))    /**< Offset for  */
#define CAN_WMB_WMBn_D03_OFFSET32(x)                       (0x0B48U + ((x) * (16U)))    /**< Offset for  */
#define CAN_WMB_WMBn_D47_OFFSET32(x)                       (0x0B4CU + ((x) * (16U)))    /**< Offset for  */

#define CAN_EPRS_OFFSET32                                  (0x0BF0U)                    /**< Offset for Enhanced CAN Bit Timing Prescalers Register */
#define CAN_ENCBT_OFFSET32                                 (0x0BF4U)                    /**< Offset for Enhanced Nominal CAN Bit Timing Register */
#define CAN_EDCBT_OFFSET32                                 (0x0BF8U)                    /**< Offset for Enhanced Data Phase CAN Bit Timing Register */
#define CAN_ETDC_OFFSET32                                  (0x0BFCU)                    /**< Offset for Enhanced Transceiver Delay Compensation Register */
#define CAN_FDCTRL_OFFSET32                                (0x0C00U)                    /**< Offset for FD Control Register */
#define CAN_FDCBT_OFFSET32                                 (0x0C04U)                    /**< Offset for FD Bit Timing Register */
#define CAN_FDCRC_OFFSET32                                 (0x0C08U)                    /**< Offset for FD CRC Register */
#define CAN_ERFCR_OFFSET32                                 (0x0C0CU)                    /**< Offset for Enhanced Rx FIFO Control Register */
#define CAN_ERFIER_OFFSET32                                (0x0C10U)                    /**< Offset for Enhanced Rx FIFO Interrupt Enable Register */
#define CAN_ERFSR_OFFSET32                                 (0x0C14U)                    /**< Offset for Enhanced Rx FIFO Status Register */
#define CAN_HR_TIME_STAMPn_OFFSET32(x)                     (0x0C30U + ((x) * (4U)))     /**< Offset for High Resolution Time Stamp Registers */
#define CAN_ERFFELn_OFFSET32(x)                            (0x3000U + ((x) * (4U)))     /**< Offset for Enhanced Rx FIFO Filter Element Registers */


/**
 * @addtogroup CAN Register Mask
 * @{
 */
/* CAN_MCR Register */
#define CAN_MCR_MDIS_MASK                                  (0x80000000U)
#define CAN_MCR_MDIS_SHIFT                                 (31U)
#define CAN_MCR_MDIS(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_MDIS_SHIFT)) & CAN_MCR_MDIS_MASK)
#define CAN_MCR_FRZ_MASK                                   (0x40000000U)
#define CAN_MCR_FRZ_SHIFT                                  (30U)
#define CAN_MCR_FRZ(x)                                     (((uint32)(((uint32)(x)) << CAN_MCR_FRZ_SHIFT)) & CAN_MCR_FRZ_MASK)
#define CAN_MCR_RFEN_MASK                                  (0x20000000U)
#define CAN_MCR_RFEN_SHIFT                                 (29U)
#define CAN_MCR_RFEN(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_RFEN_SHIFT)) & CAN_MCR_RFEN_MASK)
#define CAN_MCR_HALT_MASK                                  (0x10000000U)
#define CAN_MCR_HALT_SHIFT                                 (28U)
#define CAN_MCR_HALT(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_HALT_SHIFT)) & CAN_MCR_HALT_MASK)
#define CAN_MCR_NOTRDY_MASK                                (0x8000000U)
#define CAN_MCR_NOTRDY_SHIFT                               (27U)
#define CAN_MCR_NOTRDY(x)                                  (((uint32)(((uint32)(x)) << CAN_MCR_NOTRDY_SHIFT)) & CAN_MCR_NOTRDY_MASK)
#define CAN_MCR_WAKMSK_MASK                                (0x4000000U)
#define CAN_MCR_WAKMSK_SHIFT                               (26U)
#define CAN_MCR_WAKMSK(x)                                  (((uint32)(((uint32)(x)) << CAN_MCR_WAKMSK_SHIFT)) & CAN_MCR_WAKMSK_MASK)
#define CAN_MCR_SOFTRST_MASK                               (0x2000000U)
#define CAN_MCR_SOFTRST_SHIFT                              (25U)
#define CAN_MCR_SOFTRST(x)                                 (((uint32)(((uint32)(x)) << CAN_MCR_SOFTRST_SHIFT)) & CAN_MCR_SOFTRST_MASK)
#define CAN_MCR_FRZACK_MASK                                (0x1000000U)
#define CAN_MCR_FRZACK_SHIFT                               (24U)
#define CAN_MCR_FRZACK(x)                                  (((uint32)(((uint32)(x)) << CAN_MCR_FRZACK_SHIFT)) & CAN_MCR_FRZACK_MASK)
#define CAN_MCR_SUPV_MASK                                  (0x800000U)
#define CAN_MCR_SUPV_SHIFT                                 (23U)
#define CAN_MCR_SUPV(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_SUPV_SHIFT)) & CAN_MCR_SUPV_MASK)
#define CAN_MCR_SLFWAK_MASK                                (0x400000U)
#define CAN_MCR_SLFWAK_SHIFT                               (22U)
#define CAN_MCR_SLFWAK(x)                                  (((uint32)(((uint32)(x)) << CAN_MCR_SLFWAK_SHIFT)) & CAN_MCR_SLFWAK_MASK)
#define CAN_MCR_WRNEN_MASK                                 (0x200000U)
#define CAN_MCR_WRNEN_SHIFT                                (21U)
#define CAN_MCR_WRNEN(x)                                   (((uint32)(((uint32)(x)) << CAN_MCR_WRNEN_SHIFT)) & CAN_MCR_WRNEN_MASK)
#define CAN_MCR_LPMACK_MASK                                (0x100000U)
#define CAN_MCR_LPMACK_SHIFT                               (20U)
#define CAN_MCR_LPMACK(x)                                  (((uint32)(((uint32)(x)) << CAN_MCR_LPMACK_SHIFT)) & CAN_MCR_LPMACK_MASK)
#define CAN_MCR_WAKSRC_MASK                                (0x80000U)
#define CAN_MCR_WAKSRC_SHIFT                               (19U)
#define CAN_MCR_WAKSRC(x)                                  (((uint32)(((uint32)(x)) << CAN_MCR_WAKSRC_SHIFT)) & CAN_MCR_WAKSRC_MASK)
#define CAN_MCR_DOZE_MASK                                  (0x40000U)
#define CAN_MCR_DOZE_SHIFT                                 (18U)
#define CAN_MCR_DOZE(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_DOZE_SHIFT)) & CAN_MCR_DOZE_MASK)
#define CAN_MCR_SRXDIS_MASK                                (0x20000U)
#define CAN_MCR_SRXDIS_SHIFT                               (17U)
#define CAN_MCR_SRXDIS(x)                                  (((uint32)(((uint32)(x)) << CAN_MCR_SRXDIS_SHIFT)) & CAN_MCR_SRXDIS_MASK)
#define CAN_MCR_IRMQ_MASK                                  (0x10000U)
#define CAN_MCR_IRMQ_SHIFT                                 (16U)
#define CAN_MCR_IRMQ(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_IRMQ_SHIFT)) & CAN_MCR_IRMQ_MASK)
#define CAN_MCR_DMA_MASK                                   (0x8000U)
#define CAN_MCR_DMA_SHIFT                                  (15U)
#define CAN_MCR_DMA(x)                                     (((uint32)(((uint32)(x)) << CAN_MCR_DMA_SHIFT)) & CAN_MCR_DMA_MASK)
#define CAN_MCR_PNET_EN_MASK                               (0x4000U)
#define CAN_MCR_PNET_EN_SHIFT                              (14U)
#define CAN_MCR_PNET_EN(x)                                 (((uint32)(((uint32)(x)) << CAN_MCR_PNET_EN_SHIFT)) & CAN_MCR_PNET_EN_MASK)
#define CAN_MCR_LPRIOEN_MASK                               (0x2000U)
#define CAN_MCR_LPRIOEN_SHIFT                              (13U)
#define CAN_MCR_LPRIOEN(x)                                 (((uint32)(((uint32)(x)) << CAN_MCR_LPRIOEN_SHIFT)) & CAN_MCR_LPRIOEN_MASK)
#define CAN_MCR_AEN_MASK                                   (0x1000U)
#define CAN_MCR_AEN_SHIFT                                  (12U)
#define CAN_MCR_AEN(x)                                     (((uint32)(((uint32)(x)) << CAN_MCR_AEN_SHIFT)) & CAN_MCR_AEN_MASK)
#define CAN_MCR_FDEN_MASK                                  (0x800U)
#define CAN_MCR_FDEN_SHIFT                                 (11U)
#define CAN_MCR_FDEN(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_FDEN_SHIFT)) & CAN_MCR_FDEN_MASK)
#define CAN_MCR_IDAM_MASK                                  (0x300U)
#define CAN_MCR_IDAM_SHIFT                                 (8U)
#define CAN_MCR_IDAM(x)                                    (((uint32)(((uint32)(x)) << CAN_MCR_IDAM_SHIFT)) & CAN_MCR_IDAM_MASK)
#define CAN_MCR_MAXMB_MASK                                 (0x7FU)
#define CAN_MCR_MAXMB_SHIFT                                (0U)
#define CAN_MCR_MAXMB(x)                                   (((uint32)(((uint32)(x)) << CAN_MCR_MAXMB_SHIFT)) & CAN_MCR_MAXMB_MASK)
/* CAN_CTRL1 Register */
#define CAN_CTRL1_PRESDIV_MASK                             (0xFF000000U)
#define CAN_CTRL1_PRESDIV_SHIFT                            (24U)
#define CAN_CTRL1_PRESDIV(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_PRESDIV_SHIFT)) & CAN_CTRL1_PRESDIV_MASK)
#define CAN_CTRL1_RJW_MASK                                 (0xC00000U)
#define CAN_CTRL1_RJW_SHIFT                                (22U)
#define CAN_CTRL1_RJW(x)                                   (((uint32)(((uint32)(x)) << CAN_CTRL1_RJW_SHIFT)) & CAN_CTRL1_RJW_MASK)
#define CAN_CTRL1_PSEG1_MASK                               (0x380000U)
#define CAN_CTRL1_PSEG1_SHIFT                              (19U)
#define CAN_CTRL1_PSEG1(x)                                 (((uint32)(((uint32)(x)) << CAN_CTRL1_PSEG1_SHIFT)) & CAN_CTRL1_PSEG1_MASK)
#define CAN_CTRL1_PSEG2_MASK                               (0x70000U)
#define CAN_CTRL1_PSEG2_SHIFT                              (16U)
#define CAN_CTRL1_PSEG2(x)                                 (((uint32)(((uint32)(x)) << CAN_CTRL1_PSEG2_SHIFT)) & CAN_CTRL1_PSEG2_MASK)
#define CAN_CTRL1_BOFFMSK_MASK                             (0x8000U)
#define CAN_CTRL1_BOFFMSK_SHIFT                            (15U)
#define CAN_CTRL1_BOFFMSK(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_BOFFMSK_SHIFT)) & CAN_CTRL1_BOFFMSK_MASK)
#define CAN_CTRL1_ERRMSK_MASK                              (0x4000U)
#define CAN_CTRL1_ERRMSK_SHIFT                             (14U)
#define CAN_CTRL1_ERRMSK(x)                                (((uint32)(((uint32)(x)) << CAN_CTRL1_ERRMSK_SHIFT)) & CAN_CTRL1_ERRMSK_MASK)
#define CAN_CTRL1_CLKSRC_MASK                              (0x2000U)
#define CAN_CTRL1_CLKSRC_SHIFT                             (13U)
#define CAN_CTRL1_CLKSRC(x)                                (((uint32)(((uint32)(x)) << CAN_CTRL1_CLKSRC_SHIFT)) & CAN_CTRL1_CLKSRC_MASK)
#define CAN_CTRL1_LPB_MASK                                 (0x1000U)
#define CAN_CTRL1_LPB_SHIFT                                (12U)
#define CAN_CTRL1_LPB(x)                                   (((uint32)(((uint32)(x)) << CAN_CTRL1_LPB_SHIFT)) & CAN_CTRL1_LPB_MASK)
#define CAN_CTRL1_TWRNMSK_MASK                             (0x800U)
#define CAN_CTRL1_TWRNMSK_SHIFT                            (11U)
#define CAN_CTRL1_TWRNMSK(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_TWRNMSK_SHIFT)) & CAN_CTRL1_TWRNMSK_MASK)
#define CAN_CTRL1_RWRNMSK_MASK                             (0x400U)
#define CAN_CTRL1_RWRNMSK_SHIFT                            (10U)
#define CAN_CTRL1_RWRNMSK(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_RWRNMSK_SHIFT)) & CAN_CTRL1_RWRNMSK_MASK)
#define CAN_CTRL1_SMP_MASK                                 (0x80U)
#define CAN_CTRL1_SMP_SHIFT                                (7U)
#define CAN_CTRL1_SMP(x)                                   (((uint32)(((uint32)(x)) << CAN_CTRL1_SMP_SHIFT)) & CAN_CTRL1_SMP_MASK)
#define CAN_CTRL1_BOFFREC_MASK                             (0x40U)
#define CAN_CTRL1_BOFFREC_SHIFT                            (6U)
#define CAN_CTRL1_BOFFREC(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_BOFFREC_SHIFT)) & CAN_CTRL1_BOFFREC_MASK)
#define CAN_CTRL1_TSYN_MASK                                (0x20U)
#define CAN_CTRL1_TSYN_SHIFT                               (5U)
#define CAN_CTRL1_TSYN(x)                                  (((uint32)(((uint32)(x)) << CAN_CTRL1_TSYN_SHIFT)) & CAN_CTRL1_TSYN_MASK)
#define CAN_CTRL1_LBUF_MASK                                (0x10U)
#define CAN_CTRL1_LBUF_SHIFT                               (4U)
#define CAN_CTRL1_LBUF(x)                                  (((uint32)(((uint32)(x)) << CAN_CTRL1_LBUF_SHIFT)) & CAN_CTRL1_LBUF_MASK)
#define CAN_CTRL1_LOM_MASK                                 (0x8U)
#define CAN_CTRL1_LOM_SHIFT                                (3U)
#define CAN_CTRL1_LOM(x)                                   (((uint32)(((uint32)(x)) << CAN_CTRL1_LOM_SHIFT)) & CAN_CTRL1_LOM_MASK)
#define CAN_CTRL1_PROPSEG_MASK                             (0x7U)
#define CAN_CTRL1_PROPSEG_SHIFT                            (0U)
#define CAN_CTRL1_PROPSEG(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_PROPSEG_SHIFT)) & CAN_CTRL1_PROPSEG_MASK)
/* CAN_TIMER Register */
#define CAN_TIMER_TIMER_MASK                               (0xFFFFU)
#define CAN_TIMER_TIMER_SHIFT                              (0U)
#define CAN_TIMER_TIMER(x)                                 (((uint32)(((uint32)(x)) << CAN_TIMER_TIMER_SHIFT)) & CAN_TIMER_TIMER_MASK)
/* CAN_RXMGMASK Register */
#define CAN_RXMGMASK_MG_MASK                               (0xFFFFFFFFU)
#define CAN_RXMGMASK_MG_SHIFT                              (0U)
#define CAN_RXMGMASK_MG(x)                                 (((uint32)(((uint32)(x)) << CAN_RXMGMASK_MG_SHIFT)) & CAN_RXMGMASK_MG_MASK)
/* CAN_RX14MASK Register */
#define CAN_RX14MASK_RX14M_MASK                            (0xFFFFFFFFU)
#define CAN_RX14MASK_RX14M_SHIFT                           (0U)
#define CAN_RX14MASK_RX14M(x)                              (((uint32)(((uint32)(x)) << CAN_RX14MASK_RX14M_SHIFT)) & CAN_RX14MASK_RX14M_MASK)
/* CAN_RX15MASK Register */
#define CAN_RX15MASK_RX15M_MASK                            (0xFFFFFFFFU)
#define CAN_RX15MASK_RX15M_SHIFT                           (0U)
#define CAN_RX15MASK_RX15M(x)                              (((uint32)(((uint32)(x)) << CAN_RX15MASK_RX15M_SHIFT)) & CAN_RX15MASK_RX15M_MASK)
/* CAN_ECR Register */
#define CAN_ECR_RXERRCNT_FAST_MASK                         (0xFF000000U)
#define CAN_ECR_RXERRCNT_FAST_SHIFT                        (24U)
#define CAN_ECR_RXERRCNT_FAST(x)                           (((uint32)(((uint32)(x)) << CAN_ECR_RXERRCNT_FAST_SHIFT)) & CAN_ECR_RXERRCNT_FAST_MASK)
#define CAN_ECR_TXERRCNT_FAST_MASK                         (0xFF0000U)
#define CAN_ECR_TXERRCNT_FAST_SHIFT                        (16U)
#define CAN_ECR_TXERRCNT_FAST(x)                           (((uint32)(((uint32)(x)) << CAN_ECR_TXERRCNT_FAST_SHIFT)) & CAN_ECR_TXERRCNT_FAST_MASK)
#define CAN_ECR_RXERRCNT_MASK                              (0xFF00U)
#define CAN_ECR_RXERRCNT_SHIFT                             (8U)
#define CAN_ECR_RXERRCNT(x)                                (((uint32)(((uint32)(x)) << CAN_ECR_RXERRCNT_SHIFT)) & CAN_ECR_RXERRCNT_MASK)
#define CAN_ECR_TXERRCNT_MASK                              (0xFFU)
#define CAN_ECR_TXERRCNT_SHIFT                             (0U)
#define CAN_ECR_TXERRCNT(x)                                (((uint32)(((uint32)(x)) << CAN_ECR_TXERRCNT_SHIFT)) & CAN_ECR_TXERRCNT_MASK)
/* CAN_ESR1 Register */
#define CAN_ESR1_BIT1ERR_FAST_MASK                         (0x80000000U)
#define CAN_ESR1_BIT1ERR_FAST_SHIFT                        (31U)
#define CAN_ESR1_BIT1ERR_FAST(x)                           (((uint32)(((uint32)(x)) << CAN_ESR1_BIT1ERR_FAST_SHIFT)) & CAN_ESR1_BIT1ERR_FAST_MASK)
#define CAN_ESR1_BIT0ERR_FAST_MASK                         (0x40000000U)
#define CAN_ESR1_BIT0ERR_FAST_SHIFT                        (30U)
#define CAN_ESR1_BIT0ERR_FAST(x)                           (((uint32)(((uint32)(x)) << CAN_ESR1_BIT0ERR_FAST_SHIFT)) & CAN_ESR1_BIT0ERR_FAST_MASK)
#define CAN_ESR1_CRCERR_FAST_MASK                          (0x10000000U)
#define CAN_ESR1_CRCERR_FAST_SHIFT                         (28U)
#define CAN_ESR1_CRCERR_FAST(x)                            (((uint32)(((uint32)(x)) << CAN_ESR1_CRCERR_FAST_SHIFT)) & CAN_ESR1_CRCERR_FAST_MASK)
#define CAN_ESR1_FRMERR_FAST_MASK                          (0x8000000U)
#define CAN_ESR1_FRMERR_FAST_SHIFT                         (27U)
#define CAN_ESR1_FRMERR_FAST(x)                            (((uint32)(((uint32)(x)) << CAN_ESR1_FRMERR_FAST_SHIFT)) & CAN_ESR1_FRMERR_FAST_MASK)
#define CAN_ESR1_STFERR_FAST_MASK                          (0x4000000U)
#define CAN_ESR1_STFERR_FAST_SHIFT                         (26U)
#define CAN_ESR1_STFERR_FAST(x)                            (((uint32)(((uint32)(x)) << CAN_ESR1_STFERR_FAST_SHIFT)) & CAN_ESR1_STFERR_FAST_MASK)
#define CAN_ESR1_ERROVR_MASK                               (0x200000U)
#define CAN_ESR1_ERROVR_SHIFT                              (21U)
#define CAN_ESR1_ERROVR(x)                                 (((uint32)(((uint32)(x)) << CAN_ESR1_ERROVR_SHIFT)) & CAN_ESR1_ERROVR_MASK)
#define CAN_ESR1_ERRINT_FAST_MASK                          (0x100000U)
#define CAN_ESR1_ERRINT_FAST_SHIFT                         (20U)
#define CAN_ESR1_ERRINT_FAST(x)                            (((uint32)(((uint32)(x)) << CAN_ESR1_ERRINT_FAST_SHIFT)) & CAN_ESR1_ERRINT_FAST_MASK)
#define CAN_ESR1_BOFFDONEINT_MASK                          (0x80000U)
#define CAN_ESR1_BOFFDONEINT_SHIFT                         (19U)
#define CAN_ESR1_BOFFDONEINT(x)                            (((uint32)(((uint32)(x)) << CAN_ESR1_BOFFDONEINT_SHIFT)) & CAN_ESR1_BOFFDONEINT_MASK)
#define CAN_ESR1_SYNCH_MASK                                (0x40000U)
#define CAN_ESR1_SYNCH_SHIFT                               (18U)
#define CAN_ESR1_SYNCH(x)                                  (((uint32)(((uint32)(x)) << CAN_ESR1_SYNCH_SHIFT)) & CAN_ESR1_SYNCH_MASK)
#define CAN_ESR1_TWRNINT_MASK                              (0x20000U)
#define CAN_ESR1_TWRNINT_SHIFT                             (17U)
#define CAN_ESR1_TWRNINT(x)                                (((uint32)(((uint32)(x)) << CAN_ESR1_TWRNINT_SHIFT)) & CAN_ESR1_TWRNINT_MASK)
#define CAN_ESR1_RWRNINT_MASK                              (0x10000U)
#define CAN_ESR1_RWRNINT_SHIFT                             (16U)
#define CAN_ESR1_RWRNINT(x)                                (((uint32)(((uint32)(x)) << CAN_ESR1_RWRNINT_SHIFT)) & CAN_ESR1_RWRNINT_MASK)
#define CAN_ESR1_BIT1ERR_MASK                              (0x8000U)
#define CAN_ESR1_BIT1ERR_SHIFT                             (15U)
#define CAN_ESR1_BIT1ERR(x)                                (((uint32)(((uint32)(x)) << CAN_ESR1_BIT1ERR_SHIFT)) & CAN_ESR1_BIT1ERR_MASK)
#define CAN_ESR1_BIT0ERR_MASK                              (0x4000U)
#define CAN_ESR1_BIT0ERR_SHIFT                             (14U)
#define CAN_ESR1_BIT0ERR(x)                                (((uint32)(((uint32)(x)) << CAN_ESR1_BIT0ERR_SHIFT)) & CAN_ESR1_BIT0ERR_MASK)
#define CAN_ESR1_ACKERR_MASK                               (0x2000U)
#define CAN_ESR1_ACKERR_SHIFT                              (13U)
#define CAN_ESR1_ACKERR(x)                                 (((uint32)(((uint32)(x)) << CAN_ESR1_ACKERR_SHIFT)) & CAN_ESR1_ACKERR_MASK)
#define CAN_ESR1_CRCERR_MASK                               (0x1000U)
#define CAN_ESR1_CRCERR_SHIFT                              (12U)
#define CAN_ESR1_CRCERR(x)                                 (((uint32)(((uint32)(x)) << CAN_ESR1_CRCERR_SHIFT)) & CAN_ESR1_CRCERR_MASK)
#define CAN_ESR1_FRMERR_MASK                               (0x800U)
#define CAN_ESR1_FRMERR_SHIFT                              (11U)
#define CAN_ESR1_FRMERR(x)                                 (((uint32)(((uint32)(x)) << CAN_ESR1_FRMERR_SHIFT)) & CAN_ESR1_FRMERR_MASK)
#define CAN_ESR1_STFERR_MASK                               (0x400U)
#define CAN_ESR1_STFERR_SHIFT                              (10U)
#define CAN_ESR1_STFERR(x)                                 (((uint32)(((uint32)(x)) << CAN_ESR1_STFERR_SHIFT)) & CAN_ESR1_STFERR_MASK)
#define CAN_ESR1_TXWRN_MASK                                (0x200U)
#define CAN_ESR1_TXWRN_SHIFT                               (9U)
#define CAN_ESR1_TXWRN(x)                                  (((uint32)(((uint32)(x)) << CAN_ESR1_TXWRN_SHIFT)) & CAN_ESR1_TXWRN_MASK)
#define CAN_ESR1_RXWRN_MASK                                (0x100U)
#define CAN_ESR1_RXWRN_SHIFT                               (8U)
#define CAN_ESR1_RXWRN(x)                                  (((uint32)(((uint32)(x)) << CAN_ESR1_RXWRN_SHIFT)) & CAN_ESR1_RXWRN_MASK)
#define CAN_ESR1_IDLE_MASK                                 (0x80U)
#define CAN_ESR1_IDLE_SHIFT                                (7U)
#define CAN_ESR1_IDLE(x)                                   (((uint32)(((uint32)(x)) << CAN_ESR1_IDLE_SHIFT)) & CAN_ESR1_IDLE_MASK)
#define CAN_ESR1_TX_MASK                                   (0x40U)
#define CAN_ESR1_TX_SHIFT                                  (6U)
#define CAN_ESR1_TX(x)                                     (((uint32)(((uint32)(x)) << CAN_ESR1_TX_SHIFT)) & CAN_ESR1_TX_MASK)
#define CAN_ESR1_FLTCONF_MASK                              (0x30U)
#define CAN_ESR1_FLTCONF_SHIFT                             (4U)
#define CAN_ESR1_FLTCONF(x)                                (((uint32)(((uint32)(x)) << CAN_ESR1_FLTCONF_SHIFT)) & CAN_ESR1_FLTCONF_MASK)
#define CAN_ESR1_RX_MASK                                   (0x8U)
#define CAN_ESR1_RX_SHIFT                                  (3U)
#define CAN_ESR1_RX(x)                                     (((uint32)(((uint32)(x)) << CAN_ESR1_RX_SHIFT)) & CAN_ESR1_RX_MASK)
#define CAN_ESR1_BOFFINT_MASK                              (0x4U)
#define CAN_ESR1_BOFFINT_SHIFT                             (2U)
#define CAN_ESR1_BOFFINT(x)                                (((uint32)(((uint32)(x)) << CAN_ESR1_BOFFINT_SHIFT)) & CAN_ESR1_BOFFINT_MASK)
#define CAN_ESR1_ERRINT_MASK                               (0x2U)
#define CAN_ESR1_ERRINT_SHIFT                              (1U)
#define CAN_ESR1_ERRINT(x)                                 (((uint32)(((uint32)(x)) << CAN_ESR1_ERRINT_SHIFT)) & CAN_ESR1_ERRINT_MASK)
#define CAN_ESR1_WAKINT_MASK                               (0x1U)
#define CAN_ESR1_WAKINT_SHIFT                              (0U)
#define CAN_ESR1_WAKINT(x)                                 (((uint32)(((uint32)(x)) << CAN_ESR1_WAKINT_SHIFT)) & CAN_ESR1_WAKINT_MASK)
#define CAN_BUSOFF_FLAGS_MASK                              (0x00080302U)
/* CAN_IMASK2 Register */
#define CAN_IMASK2_BUF63TO32M_MASK                         (0xFFFFFFFFU)
#define CAN_IMASK2_BUF63TO32M_SHIFT                        (0U)
#define CAN_IMASK2_BUF63TO32M(x)                           (((uint32)(((uint32)(x)) << CAN_IMASK2_BUF63TO32M_SHIFT)) & CAN_IMASK2_BUF63TO32M_MASK)
/* CAN_IMASK1 Register */
#define CAN_IMASK1_BUF31TO0M_MASK                          (0xFFFFFFFFU)
#define CAN_IMASK1_BUF31TO0M_SHIFT                         (0U)
#define CAN_IMASK1_BUF31TO0M(x)                            (((uint32)(((uint32)(x)) << CAN_IMASK1_BUF31TO0M_SHIFT)) & CAN_IMASK1_BUF31TO0M_MASK)
/* CAN_IFLAG2 Register */
#define CAN_IFLAG2_BUF63TO32I_MASK                         (0xFFFFFFFFU)
#define CAN_IFLAG2_BUF63TO32I_SHIFT                        (0U)
#define CAN_IFLAG2_BUF63TO32I(x)                           (((uint32)(((uint32)(x)) << CAN_IFLAG2_BUF63TO32I_SHIFT)) & CAN_IFLAG2_BUF63TO32I_MASK)
/* CAN_IFLAG1 Register */
#define CAN_IFLAG1_BUF31TO8I_MASK                          (0xFFFFFF00U)
#define CAN_IFLAG1_BUF31TO8I_SHIFT                         (8U)
#define CAN_IFLAG1_BUF31TO8I(x)                            (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF31TO8I_SHIFT)) & CAN_IFLAG1_BUF31TO8I_MASK)
#define CAN_IFLAG1_BUF7I_MASK                              (0x80U)
#define CAN_IFLAG1_BUF7I_SHIFT                             (7U)
#define CAN_IFLAG1_BUF7I(x)                                (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF7I_SHIFT)) & CAN_IFLAG1_BUF7I_MASK)
#define CAN_IFLAG1_BUF6I_MASK                              (0x40U)
#define CAN_IFLAG1_BUF6I_SHIFT                             (6U)
#define CAN_IFLAG1_BUF6I(x)                                (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF6I_SHIFT)) & CAN_IFLAG1_BUF6I_MASK)
#define CAN_IFLAG1_BUF5I_MASK                              (0x20U)
#define CAN_IFLAG1_BUF5I_SHIFT                             (5U)
#define CAN_IFLAG1_BUF5I(x)                                (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF5I_SHIFT)) & CAN_IFLAG1_BUF5I_MASK)
#define CAN_IFLAG1_BUF4TO1I_MASK                           (0x1EU)
#define CAN_IFLAG1_BUF4TO1I_SHIFT                          (1U)
#define CAN_IFLAG1_BUF4TO1I(x)                             (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF4TO1I_SHIFT)) & CAN_IFLAG1_BUF4TO1I_MASK)
#define CAN_IFLAG1_BUF0I_MASK                              (0x1U)
#define CAN_IFLAG1_BUF0I_SHIFT                             (0U)
#define CAN_IFLAG1_BUF0I(x)                                (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF0I_SHIFT)) & CAN_IFLAG1_BUF0I_MASK)
#define CAN_LEGACY_FIFO_FLAGS_MASK                         (0x000000E0U)
/* CAN_CTRL2 Register */
#define CAN_CTRL2_ERRMSK_FAST_MASK                         (0x80000000U)
#define CAN_CTRL2_ERRMSK_FAST_SHIFT                        (31U)
#define CAN_CTRL2_ERRMSK_FAST(x)                           (((uint32)(((uint32)(x)) << CAN_CTRL2_ERRMSK_FAST_SHIFT)) & CAN_CTRL2_ERRMSK_FAST_MASK)
#define CAN_CTRL2_BOFFDONEMSK_MASK                         (0x40000000U)
#define CAN_CTRL2_BOFFDONEMSK_SHIFT                        (30U)
#define CAN_CTRL2_BOFFDONEMSK(x)                           (((uint32)(((uint32)(x)) << CAN_CTRL2_BOFFDONEMSK_SHIFT)) & CAN_CTRL2_BOFFDONEMSK_MASK)
#define CAN_CTRL2_ECRWRE_MASK                              (0x20000000U)
#define CAN_CTRL2_ECRWRE_SHIFT                             (29U)
#define CAN_CTRL2_ECRWRE(x)                                (((uint32)(((uint32)(x)) << CAN_CTRL2_ECRWRE_SHIFT)) & CAN_CTRL2_ECRWRE_MASK)
#define CAN_CTRL2_WRMFRZ_MASK                              (0x10000000U)
#define CAN_CTRL2_WRMFRZ_SHIFT                             (28U)
#define CAN_CTRL2_WRMFRZ(x)                                (((uint32)(((uint32)(x)) << CAN_CTRL2_WRMFRZ_SHIFT)) & CAN_CTRL2_WRMFRZ_MASK)
#define CAN_CTRL2_RFFN_MASK                                (0xF000000U)
#define CAN_CTRL2_RFFN_SHIFT                               (24U)
#define CAN_CTRL2_RFFN(x)                                  (((uint32)(((uint32)(x)) << CAN_CTRL2_RFFN_SHIFT)) & CAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_TASD_MASK                                (0xF80000U)
#define CAN_CTRL2_TASD_SHIFT                               (19U)
#define CAN_CTRL2_TASD(x)                                  (((uint32)(((uint32)(x)) << CAN_CTRL2_TASD_SHIFT)) & CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_MRP_MASK                                 (0x40000U)
#define CAN_CTRL2_MRP_SHIFT                                (18U)
#define CAN_CTRL2_MRP(x)                                   (((uint32)(((uint32)(x)) << CAN_CTRL2_MRP_SHIFT)) & CAN_CTRL2_MRP_MASK)
#define CAN_CTRL2_RRS_MASK                                 (0x20000U)
#define CAN_CTRL2_RRS_SHIFT                                (17U)
#define CAN_CTRL2_RRS(x)                                   (((uint32)(((uint32)(x)) << CAN_CTRL2_RRS_SHIFT)) & CAN_CTRL2_RRS_MASK)
#define CAN_CTRL2_EACEN_MASK                               (0x10000U)
#define CAN_CTRL2_EACEN_SHIFT                              (16U)
#define CAN_CTRL2_EACEN(x)                                 (((uint32)(((uint32)(x)) << CAN_CTRL2_EACEN_SHIFT)) & CAN_CTRL2_EACEN_MASK)
#define CAN_CTRL2_TIMER_SRC_MASK                           (0x8000U)
#define CAN_CTRL2_TIMER_SRC_SHIFT                          (15U)
#define CAN_CTRL2_TIMER_SRC(x)                             (((uint32)(((uint32)(x)) << CAN_CTRL2_TIMER_SRC_SHIFT)) & CAN_CTRL2_TIMER_SRC_MASK)
#define CAN_CTRL2_PREXCEN_MASK                             (0x4000U)
#define CAN_CTRL2_PREXCEN_SHIFT                            (14U)
#define CAN_CTRL2_PREXCEN(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL2_PREXCEN_SHIFT)) & CAN_CTRL2_PREXCEN_MASK)
#define CAN_CTRL2_BTE_MASK                                 (0x2000U)
#define CAN_CTRL2_BTE_SHIFT                                (13U)
#define CAN_CTRL2_BTE(x)                                   (((uint32)(((uint32)(x)) << CAN_CTRL2_BTE_SHIFT)) & CAN_CTRL2_BTE_MASK)
#define CAN_CTRL2_ISOCANFDEN_MASK                          (0x1000U)
#define CAN_CTRL2_ISOCANFDEN_SHIFT                         (12U)
#define CAN_CTRL2_ISOCANFDEN(x)                            (((uint32)(((uint32)(x)) << CAN_CTRL2_ISOCANFDEN_SHIFT)) & CAN_CTRL2_ISOCANFDEN_MASK)
#define CAN_CTRL2_EDFLTDIS_MASK                            (0x800U)
#define CAN_CTRL2_EDFLTDIS_SHIFT                           (11U)
#define CAN_CTRL2_EDFLTDIS(x)                              (((uint32)(((uint32)(x)) << CAN_CTRL2_EDFLTDIS_SHIFT)) & CAN_CTRL2_EDFLTDIS_MASK)
#define CAN_CTRL2_MBTSBASE_MASK                            (0x300U)
#define CAN_CTRL2_MBTSBASE_SHIFT                           (8U)
#define CAN_CTRL2_MBTSBASE(x)                              (((uint32)(((uint32)(x)) << CAN_CTRL2_MBTSBASE_SHIFT)) & CAN_CTRL2_MBTSBASE_MASK)
#define CAN_CTRL2_TSTAMPCAP_MASK                           (0xC0U)
#define CAN_CTRL2_TSTAMPCAP_SHIFT                          (6U)
#define CAN_CTRL2_TSTAMPCAP(x)                             (((uint32)(((uint32)(x)) << CAN_CTRL2_TSTAMPCAP_SHIFT)) & CAN_CTRL2_TSTAMPCAP_MASK)
/* CAN_ESR2 Register */
#define CAN_ESR2_LPTM_MASK                                 (0x7F0000U)
#define CAN_ESR2_LPTM_SHIFT                                (16U)
#define CAN_ESR2_LPTM(x)                                   (((uint32)(((uint32)(x)) << CAN_ESR2_LPTM_SHIFT)) & CAN_ESR2_LPTM_MASK)
#define CAN_ESR2_VPS_MASK                                  (0x4000U)
#define CAN_ESR2_VPS_SHIFT                                 (14U)
#define CAN_ESR2_VPS(x)                                    (((uint32)(((uint32)(x)) << CAN_ESR2_VPS_SHIFT)) & CAN_ESR2_VPS_MASK)
#define CAN_ESR2_IMB_MASK                                  (0x2000U)
#define CAN_ESR2_IMB_SHIFT                                 (13U)
#define CAN_ESR2_IMB(x)                                    (((uint32)(((uint32)(x)) << CAN_ESR2_IMB_SHIFT)) & CAN_ESR2_IMB_MASK)
/* CAN_CRCR Register */
#define CAN_CRCR_MBCRC_MASK                                (0x7F0000U)
#define CAN_CRCR_MBCRC_SHIFT                               (16U)
#define CAN_CRCR_MBCRC(x)                                  (((uint32)(((uint32)(x)) << CAN_CRCR_MBCRC_SHIFT)) & CAN_CRCR_MBCRC_MASK)
#define CAN_CRCR_TXCRC_MASK                                (0x7FFFU)
#define CAN_CRCR_TXCRC_SHIFT                               (0U)
#define CAN_CRCR_TXCRC(x)                                  (((uint32)(((uint32)(x)) << CAN_CRCR_TXCRC_SHIFT)) & CAN_CRCR_TXCRC_MASK)
/* CAN_RXFGMASK Register */
#define CAN_RXFGMASK_FGM_MASK                              (0xFFFFFFFFU)
#define CAN_RXFGMASK_FGM_SHIFT                             (0U)
#define CAN_RXFGMASK_FGM(x)                                (((uint32)(((uint32)(x)) << CAN_RXFGMASK_FGM_SHIFT)) & CAN_RXFGMASK_FGM_MASK)
/* CAN_RXFIR Register */
#define CAN_RXFIR_IDHIT_MASK                               (0x1FFU)
#define CAN_RXFIR_IDHIT_SHIFT                              (0U)
#define CAN_RXFIR_IDHIT(x)                                 (((uint32)(((uint32)(x)) << CAN_RXFIR_IDHIT_SHIFT)) & CAN_RXFIR_IDHIT_MASK)
/* CAN_CBT Register */
#define CAN_CBT_BTF_MASK                                   (0x80000000U)
#define CAN_CBT_BTF_SHIFT                                  (31U)
#define CAN_CBT_BTF(x)                                     (((uint32)(((uint32)(x)) << CAN_CBT_BTF_SHIFT)) & CAN_CBT_BTF_MASK)
#define CAN_CBT_EPRESDIV_MASK                              (0x7FE00000U)
#define CAN_CBT_EPRESDIV_SHIFT                             (21U)
#define CAN_CBT_EPRESDIV(x)                                (((uint32)(((uint32)(x)) << CAN_CBT_EPRESDIV_SHIFT)) & CAN_CBT_EPRESDIV_MASK)
#define CAN_CBT_ERJW_MASK                                  (0x1F0000U)
#define CAN_CBT_ERJW_SHIFT                                 (16U)
#define CAN_CBT_ERJW(x)                                    (((uint32)(((uint32)(x)) << CAN_CBT_ERJW_SHIFT)) & CAN_CBT_ERJW_MASK)
#define CAN_CBT_EPROPSEG_MASK                              (0xFC00U)
#define CAN_CBT_EPROPSEG_SHIFT                             (10U)
#define CAN_CBT_EPROPSEG(x)                                (((uint32)(((uint32)(x)) << CAN_CBT_EPROPSEG_SHIFT)) & CAN_CBT_EPROPSEG_MASK)
#define CAN_CBT_EPSEG1_MASK                                (0x3E0U)
#define CAN_CBT_EPSEG1_SHIFT                               (5U)
#define CAN_CBT_EPSEG1(x)                                  (((uint32)(((uint32)(x)) << CAN_CBT_EPSEG1_SHIFT)) & CAN_CBT_EPSEG1_MASK)
#define CAN_CBT_EPSEG2_MASK                                (0x1FU)
#define CAN_CBT_EPSEG2_SHIFT                               (0U)
#define CAN_CBT_EPSEG2(x)                                  (((uint32)(((uint32)(x)) << CAN_CBT_EPSEG2_SHIFT)) & CAN_CBT_EPSEG2_MASK)
/* CAN_IMASK4 Register */
#define CAN_IMASK4_BUF127TO96M_MASK                        (0xFFFFFFFFU)
#define CAN_IMASK4_BUF127TO96M_SHIFT                       (0U)
#define CAN_IMASK4_BUF127TO96M(x)                          (((uint32)(((uint32)(x)) << CAN_IMASK4_BUF127TO96M_SHIFT)) & CAN_IMASK4_BUF127TO96M_MASK)
/* CAN_IMASK3 Register */
#define CAN_IMASK3_BUF95TO64M_MASK                         (0xFFFFFFFFU)
#define CAN_IMASK3_BUF95TO64M_SHIFT                        (0U)
#define CAN_IMASK3_BUF95TO64M(x)                           (((uint32)(((uint32)(x)) << CAN_IMASK3_BUF95TO64M_SHIFT)) & CAN_IMASK3_BUF95TO64M_MASK)
/* CAN_IFLAG4 Register */
#define CAN_IFLAG4_BUF127TO96_MASK                         (0xFFFFFFFFU)
#define CAN_IFLAG4_BUF127TO96_SHIFT                        (0U)
#define CAN_IFLAG4_BUF127TO96(x)                           (((uint32)(((uint32)(x)) << CAN_IFLAG4_BUF127TO96_SHIFT)) & CAN_IFLAG4_BUF127TO96_MASK)
/* CAN_IFLAG3 Register */
#define CAN_IFLAG3_BUF95TO64_MASK                          (0xFFFFFFFFU)
#define CAN_IFLAG3_BUF95TO64_SHIFT                         (0U)
#define CAN_IFLAG3_BUF95TO64(x)                            (((uint32)(((uint32)(x)) << CAN_IFLAG3_BUF95TO64_SHIFT)) & CAN_IFLAG3_BUF95TO64_MASK)
/* CAN_RAM Register */
#define CAN_RAM_RAM_MASK                                   (0xFFFFFFFFU)
#define CAN_RAM_RAM_SHIFT                                  (0U)
#define CAN_RAM_RAM(x)                                     (((uint32)(((uint32)(x)) << CAN_RAM_RAM_SHIFT)) & CAN_RAM_RAM_MASK)
/* CAN_RXIMR Register */
#define CAN_RXIMR_MI_MASK                                  (0xFFFFFFFFU)
#define CAN_RXIMR_MI_SHIFT                                 (0U)
#define CAN_RXIMR_MI(x)                                    (((uint32)(((uint32)(x)) << CAN_RXIMR_MI_SHIFT)) & CAN_RXIMR_MI_MASK)
/* CAN_MECR Register */
#define CAN_MECR_ECRWRDIS_MASK                             (0x80000000U)
#define CAN_MECR_ECRWRDIS_SHIFT                            (31U)
#define CAN_MECR_ECRWRDIS(x)                               (((uint32)(((uint32)(x)) << CAN_MECR_ECRWRDIS_SHIFT)) & CAN_MECR_ECRWRDIS_MASK)
#define CAN_MECR_HANCEI_MSK_MASK                           (0x80000U)
#define CAN_MECR_HANCEI_MSK_SHIFT                          (19U)
#define CAN_MECR_HANCEI_MSK(x)                             (((uint32)(((uint32)(x)) << CAN_MECR_HANCEI_MSK_SHIFT)) & CAN_MECR_HANCEI_MSK_MASK)
#define CAN_MECR_FANCEI_MSK_MASK                           (0x40000U)
#define CAN_MECR_FANCEI_MSK_SHIFT                          (18U)
#define CAN_MECR_FANCEI_MSK(x)                             (((uint32)(((uint32)(x)) << CAN_MECR_FANCEI_MSK_SHIFT)) & CAN_MECR_FANCEI_MSK_MASK)
#define CAN_MECR_CEI_MSK_MASK                              (0x10000U)
#define CAN_MECR_CEI_MSK_SHIFT                             (16U)
#define CAN_MECR_CEI_MSK(x)                                (((uint32)(((uint32)(x)) << CAN_MECR_CEI_MSK_SHIFT)) & CAN_MECR_CEI_MSK_MASK)
#define CAN_MECR_HAERRIE_MASK                              (0x8000U)
#define CAN_MECR_HAERRIE_SHIFT                             (15U)
#define CAN_MECR_HAERRIE(x)                                (((uint32)(((uint32)(x)) << CAN_MECR_HAERRIE_SHIFT)) & CAN_MECR_HAERRIE_MASK)
#define CAN_MECR_FAERRIE_MASK                              (0x4000U)
#define CAN_MECR_FAERRIE_SHIFT                             (14U)
#define CAN_MECR_FAERRIE(x)                                (((uint32)(((uint32)(x)) << CAN_MECR_FAERRIE_SHIFT)) & CAN_MECR_FAERRIE_MASK)
#define CAN_MECR_EXTERRIE_MASK                             (0x2000U)
#define CAN_MECR_EXTERRIE_SHIFT                            (13U)
#define CAN_MECR_EXTERRIE(x)                               (((uint32)(((uint32)(x)) << CAN_MECR_EXTERRIE_SHIFT)) & CAN_MECR_EXTERRIE_MASK)
#define CAN_MECR_RERRDIS_MASK                              (0x200U)
#define CAN_MECR_RERRDIS_SHIFT                             (9U)
#define CAN_MECR_RERRDIS(x)                                (((uint32)(((uint32)(x)) << CAN_MECR_RERRDIS_SHIFT)) & CAN_MECR_RERRDIS_MASK)
#define CAN_MECR_ECCDIS_MASK                               (0x100U)
#define CAN_MECR_ECCDIS_SHIFT                              (8U)
#define CAN_MECR_ECCDIS(x)                                 (((uint32)(((uint32)(x)) << CAN_MECR_ECCDIS_SHIFT)) & CAN_MECR_ECCDIS_MASK)
#define CAN_MECR_NCEFAFRZ_MASK                             (0x80U)
#define CAN_MECR_NCEFAFRZ_SHIFT                            (7U)
#define CAN_MECR_NCEFAFRZ(x)                               (((uint32)(((uint32)(x)) << CAN_MECR_NCEFAFRZ_SHIFT)) & CAN_MECR_NCEFAFRZ_MASK)
/* CAN_ERRIAR Register */
#define CAN_ERRIAR_INJADDR_H_MASK                          (0x3FFCU)
#define CAN_ERRIAR_INJADDR_H_SHIFT                         (2U)
#define CAN_ERRIAR_INJADDR_H(x)                            (((uint32)(((uint32)(x)) << CAN_ERRIAR_INJADDR_H_SHIFT)) & CAN_ERRIAR_INJADDR_H_MASK)
#define CAN_ERRIAR_INJADDR_L_MASK                          (0x3U)
#define CAN_ERRIAR_INJADDR_L_SHIFT                         (0U)
#define CAN_ERRIAR_INJADDR_L(x)                            (((uint32)(((uint32)(x)) << CAN_ERRIAR_INJADDR_L_SHIFT)) & CAN_ERRIAR_INJADDR_L_MASK)
/* CAN_ERRIDPR Register */
#define CAN_ERRIDPR_DFLIP_MASK                             (0xFFFFFFFFU)
#define CAN_ERRIDPR_DFLIP_SHIFT                            (0U)
#define CAN_ERRIDPR_DFLIP(x)                               (((uint32)(((uint32)(x)) << CAN_ERRIDPR_DFLIP_SHIFT)) & CAN_ERRIDPR_DFLIP_MASK)
/* CAN_ERRIPPR Register */
#define CAN_ERRIPPR_PFLIP3_MASK                            (0x1F000000U)
#define CAN_ERRIPPR_PFLIP3_SHIFT                           (24U)
#define CAN_ERRIPPR_PFLIP3(x)                              (((uint32)(((uint32)(x)) << CAN_ERRIPPR_PFLIP3_SHIFT)) & CAN_ERRIPPR_PFLIP3_MASK)
#define CAN_ERRIPPR_PFLIP2_MASK                            (0x1F0000U)
#define CAN_ERRIPPR_PFLIP2_SHIFT                           (16U)
#define CAN_ERRIPPR_PFLIP2(x)                              (((uint32)(((uint32)(x)) << CAN_ERRIPPR_PFLIP2_SHIFT)) & CAN_ERRIPPR_PFLIP2_MASK)
#define CAN_ERRIPPR_PFLIP1_MASK                            (0x1F00U)
#define CAN_ERRIPPR_PFLIP1_SHIFT                           (8U)
#define CAN_ERRIPPR_PFLIP1(x)                              (((uint32)(((uint32)(x)) << CAN_ERRIPPR_PFLIP1_SHIFT)) & CAN_ERRIPPR_PFLIP1_MASK)
#define CAN_ERRIPPR_PFLIP0_MASK                            (0x1FU)
#define CAN_ERRIPPR_PFLIP0_SHIFT                           (0U)
#define CAN_ERRIPPR_PFLIP0(x)                              (((uint32)(((uint32)(x)) << CAN_ERRIPPR_PFLIP0_SHIFT)) & CAN_ERRIPPR_PFLIP0_MASK)
/* CAN_RERRAR Register */
#define CAN_RERRAR_NCE_MASK                                (0x1000000U)
#define CAN_RERRAR_NCE_SHIFT                               (24U)
#define CAN_RERRAR_NCE(x)                                  (((uint32)(((uint32)(x)) << CAN_RERRAR_NCE_SHIFT)) & CAN_RERRAR_NCE_MASK)
#define CAN_RERRAR_SAID_MASK                               (0x70000U)
#define CAN_RERRAR_SAID_SHIFT                              (16U)
#define CAN_RERRAR_SAID(x)                                 (((uint32)(((uint32)(x)) << CAN_RERRAR_SAID_SHIFT)) & CAN_RERRAR_SAID_MASK)
#define CAN_RERRAR_ERRADDR_MASK                            (0x3FFFU)
#define CAN_RERRAR_ERRADDR_SHIFT                           (0U)
#define CAN_RERRAR_ERRADDR(x)                              (((uint32)(((uint32)(x)) << CAN_RERRAR_ERRADDR_SHIFT)) & CAN_RERRAR_ERRADDR_MASK)
/* CAN_RERRDR Register */
#define CAN_RERRDR_RDATA_MASK                              (0xFFFFFFFFU)
#define CAN_RERRDR_RDATA_SHIFT                             (0U)
#define CAN_RERRDR_RDATA(x)                                (((uint32)(((uint32)(x)) << CAN_RERRDR_RDATA_SHIFT)) & CAN_RERRDR_RDATA_MASK)
/* CAN_RERRSYNR Register */
#define CAN_RERRSYNR_BE3_MASK                              (0x80000000U)
#define CAN_RERRSYNR_BE3_SHIFT                             (31U)
#define CAN_RERRSYNR_BE3(x)                                (((uint32)(((uint32)(x)) << CAN_RERRSYNR_BE3_SHIFT)) & CAN_RERRSYNR_BE3_MASK)
#define CAN_RERRSYNR_SYND3_MASK                            (0x1F000000U)
#define CAN_RERRSYNR_SYND3_SHIFT                           (24U)
#define CAN_RERRSYNR_SYND3(x)                              (((uint32)(((uint32)(x)) << CAN_RERRSYNR_SYND3_SHIFT)) & CAN_RERRSYNR_SYND3_MASK)
#define CAN_RERRSYNR_BE2_MASK                              (0x800000U)
#define CAN_RERRSYNR_BE2_SHIFT                             (23U)
#define CAN_RERRSYNR_BE2(x)                                (((uint32)(((uint32)(x)) << CAN_RERRSYNR_BE2_SHIFT)) & CAN_RERRSYNR_BE2_MASK)
#define CAN_RERRSYNR_SYND2_MASK                            (0x1F0000U)
#define CAN_RERRSYNR_SYND2_SHIFT                           (16U)
#define CAN_RERRSYNR_SYND2(x)                              (((uint32)(((uint32)(x)) << CAN_RERRSYNR_SYND2_SHIFT)) & CAN_RERRSYNR_SYND2_MASK)
#define CAN_RERRSYNR_BE1_MASK                              (0x8000U)
#define CAN_RERRSYNR_BE1_SHIFT                             (15U)
#define CAN_RERRSYNR_BE1(x)                                (((uint32)(((uint32)(x)) << CAN_RERRSYNR_BE1_SHIFT)) & CAN_RERRSYNR_BE1_MASK)
#define CAN_RERRSYNR_SYND1_MASK                            (0x1F00U)
#define CAN_RERRSYNR_SYND1_SHIFT                           (8U)
#define CAN_RERRSYNR_SYND1(x)                              (((uint32)(((uint32)(x)) << CAN_RERRSYNR_SYND1_SHIFT)) & CAN_RERRSYNR_SYND1_MASK)
#define CAN_RERRSYNR_BE0_MASK                              (0x80U)
#define CAN_RERRSYNR_BE0_SHIFT                             (7U)
#define CAN_RERRSYNR_BE0(x)                                (((uint32)(((uint32)(x)) << CAN_RERRSYNR_BE0_SHIFT)) & CAN_RERRSYNR_BE0_MASK)
#define CAN_RERRSYNR_SYND0_MASK                            (0x1FU)
#define CAN_RERRSYNR_SYND0_SHIFT                           (0U)
#define CAN_RERRSYNR_SYND0(x)                              (((uint32)(((uint32)(x)) << CAN_RERRSYNR_SYND0_SHIFT)) & CAN_RERRSYNR_SYND0_MASK)
/* CAN_ERRSR Register */
#define CAN_ERRSR_HANCEIF_MASK                             (0x80000U)
#define CAN_ERRSR_HANCEIF_SHIFT                            (19U)
#define CAN_ERRSR_HANCEIF(x)                               (((uint32)(((uint32)(x)) << CAN_ERRSR_HANCEIF_SHIFT)) & CAN_ERRSR_HANCEIF_MASK)
#define CAN_ERRSR_FANCEIF_MASK                             (0x40000U)
#define CAN_ERRSR_FANCEIF_SHIFT                            (18U)
#define CAN_ERRSR_FANCEIF(x)                               (((uint32)(((uint32)(x)) << CAN_ERRSR_FANCEIF_SHIFT)) & CAN_ERRSR_FANCEIF_MASK)
#define CAN_ERRSR_CEIF_MASK                                (0x10000U)
#define CAN_ERRSR_CEIF_SHIFT                               (16U)
#define CAN_ERRSR_CEIF(x)                                  (((uint32)(((uint32)(x)) << CAN_ERRSR_CEIF_SHIFT)) & CAN_ERRSR_CEIF_MASK)
#define CAN_ERRSR_HANCEIOF_MASK                            (0x8U)
#define CAN_ERRSR_HANCEIOF_SHIFT                           (3U)
#define CAN_ERRSR_HANCEIOF(x)                              (((uint32)(((uint32)(x)) << CAN_ERRSR_HANCEIOF_SHIFT)) & CAN_ERRSR_HANCEIOF_MASK)
#define CAN_ERRSR_FANCEIOF_MASK                            (0x4U)
#define CAN_ERRSR_FANCEIOF_SHIFT                           (2U)
#define CAN_ERRSR_FANCEIOF(x)                              (((uint32)(((uint32)(x)) << CAN_ERRSR_FANCEIOF_SHIFT)) & CAN_ERRSR_FANCEIOF_MASK)
#define CAN_ERRSR_CEIOF_MASK                               (0x1U)
#define CAN_ERRSR_CEIOF_SHIFT                              (0U)
#define CAN_ERRSR_CEIOF(x)                                 (((uint32)(((uint32)(x)) << CAN_ERRSR_CEIOF_SHIFT)) & CAN_ERRSR_CEIOF_MASK)
/* CAN_CTRL1_PN Register */
#define CAN_CTRL1_PN_WTOF_MSK_MASK                         (0x20000U)
#define CAN_CTRL1_PN_WTOF_MSK_SHIFT                        (17U)
#define CAN_CTRL1_PN_WTOF_MSK(x)                           (((uint32)(((uint32)(x)) << CAN_CTRL1_PN_WTOF_MSK_SHIFT)) & CAN_CTRL1_PN_WTOF_MSK_MASK)
#define CAN_CTRL1_PN_WUMF_MSK_MASK                         (0x10000U)
#define CAN_CTRL1_PN_WUMF_MSK_SHIFT                        (16U)
#define CAN_CTRL1_PN_WUMF_MSK(x)                           (((uint32)(((uint32)(x)) << CAN_CTRL1_PN_WUMF_MSK_SHIFT)) & CAN_CTRL1_PN_WUMF_MSK_MASK)
#define CAN_CTRL1_PN_NMATCH_MASK                           (0xFF00U)
#define CAN_CTRL1_PN_NMATCH_SHIFT                          (8U)
#define CAN_CTRL1_PN_NMATCH(x)                             (((uint32)(((uint32)(x)) << CAN_CTRL1_PN_NMATCH_SHIFT)) & CAN_CTRL1_PN_NMATCH_MASK)
#define CAN_CTRL1_PN_PLFS_MASK                             (0x30U)
#define CAN_CTRL1_PN_PLFS_SHIFT                            (4U)
#define CAN_CTRL1_PN_PLFS(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_PN_PLFS_SHIFT)) & CAN_CTRL1_PN_PLFS_MASK)
#define CAN_CTRL1_PN_IDFS_MASK                             (0xCU)
#define CAN_CTRL1_PN_IDFS_SHIFT                            (2U)
#define CAN_CTRL1_PN_IDFS(x)                               (((uint32)(((uint32)(x)) << CAN_CTRL1_PN_IDFS_SHIFT)) & CAN_CTRL1_PN_IDFS_MASK)
#define CAN_CTRL1_PN_FCS_MASK                              (0x3U)
#define CAN_CTRL1_PN_FCS_SHIFT                             (0U)
#define CAN_CTRL1_PN_FCS(x)                                (((uint32)(((uint32)(x)) << CAN_CTRL1_PN_FCS_SHIFT)) & CAN_CTRL1_PN_FCS_MASK)
/* CAN_CTRL2_PN Register */
#define CAN_CTRL2_PN_MATCHTO_MASK                          (0xFFFFU)
#define CAN_CTRL2_PN_MATCHTO_SHIFT                         (0U)
#define CAN_CTRL2_PN_MATCHTO(x)                            (((uint32)(((uint32)(x)) << CAN_CTRL2_PN_MATCHTO_SHIFT)) & CAN_CTRL2_PN_MATCHTO_MASK)
/* CAN_WU_MTC Register */
#define CAN_WU_MTC_WTOF_MASK                               (0x20000U)
#define CAN_WU_MTC_WTOF_SHIFT                              (17U)
#define CAN_WU_MTC_WTOF(x)                                 (((uint32)(((uint32)(x)) << CAN_WU_MTC_WTOF_SHIFT)) & CAN_WU_MTC_WTOF_MASK)
#define CAN_WU_MTC_WUMF_MASK                               (0x10000U)
#define CAN_WU_MTC_WUMF_SHIFT                              (16U)
#define CAN_WU_MTC_WUMF(x)                                 (((uint32)(((uint32)(x)) << CAN_WU_MTC_WUMF_SHIFT)) & CAN_WU_MTC_WUMF_MASK)
#define CAN_WU_MTC_MCOUNTER_MASK                           (0xFF00U)
#define CAN_WU_MTC_MCOUNTER_SHIFT                          (8U)
#define CAN_WU_MTC_MCOUNTER(x)                             (((uint32)(((uint32)(x)) << CAN_WU_MTC_MCOUNTER_SHIFT)) & CAN_WU_MTC_MCOUNTER_MASK)
/* CAN_FLT_ID1 Register */
#define CAN_FLT_ID1_FLT_IDE_MASK                           (0x40000000U)
#define CAN_FLT_ID1_FLT_IDE_SHIFT                          (30U)
#define CAN_FLT_ID1_FLT_IDE(x)                             (((uint32)(((uint32)(x)) << CAN_FLT_ID1_FLT_IDE_SHIFT)) & CAN_FLT_ID1_FLT_IDE_MASK)
#define CAN_FLT_ID1_FLT_RTR_MASK                           (0x20000000U)
#define CAN_FLT_ID1_FLT_RTR_SHIFT                          (29U)
#define CAN_FLT_ID1_FLT_RTR(x)                             (((uint32)(((uint32)(x)) << CAN_FLT_ID1_FLT_RTR_SHIFT)) & CAN_FLT_ID1_FLT_RTR_MASK)
#define CAN_FLT_ID1_FLT_ID1_MASK                           (0x1FFFFFFFU)
#define CAN_FLT_ID1_FLT_ID1_SHIFT                          (0U)
#define CAN_FLT_ID1_FLT_ID1(x)                             (((uint32)(((uint32)(x)) << CAN_FLT_ID1_FLT_ID1_SHIFT)) & CAN_FLT_ID1_FLT_ID1_MASK)
/* CAN_FLT_DLC Register */
#define CAN_FLT_DLC_FLT_DLC_LO_MASK                        (0xF0000U)
#define CAN_FLT_DLC_FLT_DLC_LO_SHIFT                       (16U)
#define CAN_FLT_DLC_FLT_DLC_LO(x)                          (((uint32)(((uint32)(x)) << CAN_FLT_DLC_FLT_DLC_LO_SHIFT)) & CAN_FLT_DLC_FLT_DLC_LO_MASK)
#define CAN_FLT_DLC_FLT_DLC_HI_MASK                        (0xFU)
#define CAN_FLT_DLC_FLT_DLC_HI_SHIFT                       (0U)
#define CAN_FLT_DLC_FLT_DLC_HI(x)                          (((uint32)(((uint32)(x)) << CAN_FLT_DLC_FLT_DLC_HI_SHIFT)) & CAN_FLT_DLC_FLT_DLC_HI_MASK)
/* CAN_PL1_LO Register */
#define CAN_PL1_LO_Data_byte_0_MASK                        (0xFF000000U)
#define CAN_PL1_LO_Data_byte_0_SHIFT                       (24U)
#define CAN_PL1_LO_Data_byte_0(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_LO_Data_byte_0_SHIFT)) & CAN_PL1_LO_Data_byte_0_MASK)
#define CAN_PL1_LO_Data_byte_1_MASK                        (0xFF0000U)
#define CAN_PL1_LO_Data_byte_1_SHIFT                       (16U)
#define CAN_PL1_LO_Data_byte_1(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_LO_Data_byte_1_SHIFT)) & CAN_PL1_LO_Data_byte_1_MASK)
#define CAN_PL1_LO_Data_byte_2_MASK                        (0xFF00U)
#define CAN_PL1_LO_Data_byte_2_SHIFT                       (8U)
#define CAN_PL1_LO_Data_byte_2(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_LO_Data_byte_2_SHIFT)) & CAN_PL1_LO_Data_byte_2_MASK)
#define CAN_PL1_LO_Data_byte_3_MASK                        (0xFFU)
#define CAN_PL1_LO_Data_byte_3_SHIFT                       (0U)
#define CAN_PL1_LO_Data_byte_3(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_LO_Data_byte_3_SHIFT)) & CAN_PL1_LO_Data_byte_3_MASK)
/* CAN_PL1_HI Register */
#define CAN_PL1_HI_Data_byte_4_MASK                        (0xFF000000U)
#define CAN_PL1_HI_Data_byte_4_SHIFT                       (24U)
#define CAN_PL1_HI_Data_byte_4(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_HI_Data_byte_4_SHIFT)) & CAN_PL1_HI_Data_byte_4_MASK)
#define CAN_PL1_HI_Data_byte_5_MASK                        (0xFF0000U)
#define CAN_PL1_HI_Data_byte_5_SHIFT                       (16U)
#define CAN_PL1_HI_Data_byte_5(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_HI_Data_byte_5_SHIFT)) & CAN_PL1_HI_Data_byte_5_MASK)
#define CAN_PL1_HI_Data_byte_6_MASK                        (0xFF00U)
#define CAN_PL1_HI_Data_byte_6_SHIFT                       (8U)
#define CAN_PL1_HI_Data_byte_6(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_HI_Data_byte_6_SHIFT)) & CAN_PL1_HI_Data_byte_6_MASK)
#define CAN_PL1_HI_Data_byte_7_MASK                        (0xFFU)
#define CAN_PL1_HI_Data_byte_7_SHIFT                       (0U)
#define CAN_PL1_HI_Data_byte_7(x)                          (((uint32)(((uint32)(x)) << CAN_PL1_HI_Data_byte_7_SHIFT)) & CAN_PL1_HI_Data_byte_7_MASK)
/* CAN_FLT_ID2_IDMASK Register */
#define CAN_FLT_ID2_IDMASK_IDE_MSK_MASK                    (0x40000000U)
#define CAN_FLT_ID2_IDMASK_IDE_MSK_SHIFT                   (30U)
#define CAN_FLT_ID2_IDMASK_IDE_MSK(x)                      (((uint32)(((uint32)(x)) << CAN_FLT_ID2_IDMASK_IDE_MSK_SHIFT)) & CAN_FLT_ID2_IDMASK_IDE_MSK_MASK)
#define CAN_FLT_ID2_IDMASK_RTR_MSK_MASK                    (0x20000000U)
#define CAN_FLT_ID2_IDMASK_RTR_MSK_SHIFT                   (29U)
#define CAN_FLT_ID2_IDMASK_RTR_MSK(x)                      (((uint32)(((uint32)(x)) << CAN_FLT_ID2_IDMASK_RTR_MSK_SHIFT)) & CAN_FLT_ID2_IDMASK_RTR_MSK_MASK)
#define CAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_MASK             (0x1FFFFFFFU)
#define CAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_SHIFT            (0U)
#define CAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK(x)               (((uint32)(((uint32)(x)) << CAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_SHIFT)) & CAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_MASK)
/* CAN_PL2_PLMASK_LO Register */
#define CAN_PL2_PLMASK_LO_Data_byte_0_MASK                 (0xFF000000U)
#define CAN_PL2_PLMASK_LO_Data_byte_0_SHIFT                (24U)
#define CAN_PL2_PLMASK_LO_Data_byte_0(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_LO_Data_byte_0_SHIFT)) & CAN_PL2_PLMASK_LO_Data_byte_0_MASK)
#define CAN_PL2_PLMASK_LO_Data_byte_1_MASK                 (0xFF0000U)
#define CAN_PL2_PLMASK_LO_Data_byte_1_SHIFT                (16U)
#define CAN_PL2_PLMASK_LO_Data_byte_1(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_LO_Data_byte_1_SHIFT)) & CAN_PL2_PLMASK_LO_Data_byte_1_MASK)
#define CAN_PL2_PLMASK_LO_Data_byte_2_MASK                 (0xFF00U)
#define CAN_PL2_PLMASK_LO_Data_byte_2_SHIFT                (8U)
#define CAN_PL2_PLMASK_LO_Data_byte_2(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_LO_Data_byte_2_SHIFT)) & CAN_PL2_PLMASK_LO_Data_byte_2_MASK)
#define CAN_PL2_PLMASK_LO_Data_byte_3_MASK                 (0xFFU)
#define CAN_PL2_PLMASK_LO_Data_byte_3_SHIFT                (0U)
#define CAN_PL2_PLMASK_LO_Data_byte_3(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_LO_Data_byte_3_SHIFT)) & CAN_PL2_PLMASK_LO_Data_byte_3_MASK)
/* CAN_PL2_PLMASK_HI Register */
#define CAN_PL2_PLMASK_HI_Data_byte_4_MASK                 (0xFF000000U)
#define CAN_PL2_PLMASK_HI_Data_byte_4_SHIFT                (24U)
#define CAN_PL2_PLMASK_HI_Data_byte_4(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_HI_Data_byte_4_SHIFT)) & CAN_PL2_PLMASK_HI_Data_byte_4_MASK)
#define CAN_PL2_PLMASK_HI_Data_byte_5_MASK                 (0xFF0000U)
#define CAN_PL2_PLMASK_HI_Data_byte_5_SHIFT                (16U)
#define CAN_PL2_PLMASK_HI_Data_byte_5(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_HI_Data_byte_5_SHIFT)) & CAN_PL2_PLMASK_HI_Data_byte_5_MASK)
#define CAN_PL2_PLMASK_HI_Data_byte_6_MASK                 (0xFF00U)
#define CAN_PL2_PLMASK_HI_Data_byte_6_SHIFT                (8U)
#define CAN_PL2_PLMASK_HI_Data_byte_6(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_HI_Data_byte_6_SHIFT)) & CAN_PL2_PLMASK_HI_Data_byte_6_MASK)
#define CAN_PL2_PLMASK_HI_Data_byte_7_MASK                 (0xFFU)
#define CAN_PL2_PLMASK_HI_Data_byte_7_SHIFT                (0U)
#define CAN_PL2_PLMASK_HI_Data_byte_7(x)                   (((uint32)(((uint32)(x)) << CAN_PL2_PLMASK_HI_Data_byte_7_SHIFT)) & CAN_PL2_PLMASK_HI_Data_byte_7_MASK)
/* CAN_WMB_WMBn_CS Register */
#define CAN_WMB_WMBn_CS_SRR_MASK                               (0x400000U)
#define CAN_WMB_WMBn_CS_SRR_SHIFT                              (22U)
#define CAN_WMB_WMBn_CS_SRR(x)                                 (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_CS_SRR_SHIFT)) & CAN_WMB_WMBn_CS_SRR_MASK)
#define CAN_WMB_WMBn_CS_IDE_MASK                               (0x200000U)
#define CAN_WMB_WMBn_CS_IDE_SHIFT                              (21U)
#define CAN_WMB_WMBn_CS_IDE(x)                                 (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_CS_IDE_SHIFT)) & CAN_WMB_WMBn_CS_IDE_MASK)
#define CAN_WMB_WMBn_CS_RTR_MASK                               (0x100000U)
#define CAN_WMB_WMBn_CS_RTR_SHIFT                              (20U)
#define CAN_WMB_WMBn_CS_RTR(x)                                 (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_CS_RTR_SHIFT)) & CAN_WMB_WMBn_CS_RTR_MASK)
#define CAN_WMB_WMBn_CS_DLC_MASK                               (0xF0000U)
#define CAN_WMB_WMBn_CS_DLC_SHIFT                              (16U)
#define CAN_WMB_WMBn_CS_DLC(x)                                 (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_CS_DLC_SHIFT)) & CAN_WMB_WMBn_CS_DLC_MASK)
/* CAN_WMB_WMBn_ID Register */
#define CAN_WMB_WMBn_ID_ID_MASK                                (0x1FFFFFFFU)
#define CAN_WMB_WMBn_ID_ID_SHIFT                               (0U)
#define CAN_WMB_WMBn_ID_ID(x)                                  (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_ID_ID_SHIFT)) & CAN_WMB_WMBn_ID_ID_MASK)
/* CAN_WMB_WMBn_D03 Register */
#define CAN_WMB_WMBn_D03_Data_byte_0_MASK                      (0xFF000000U)
#define CAN_WMB_WMBn_D03_Data_byte_0_SHIFT                     (24U)
#define CAN_WMB_WMBn_D03_Data_byte_0(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D03_Data_byte_0_SHIFT)) & CAN_WMB_WMBn_D03_Data_byte_0_MASK)
#define CAN_WMB_WMBn_D03_Data_byte_1_MASK                      (0xFF0000U)
#define CAN_WMB_WMBn_D03_Data_byte_1_SHIFT                     (16U)
#define CAN_WMB_WMBn_D03_Data_byte_1(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D03_Data_byte_1_SHIFT)) & CAN_WMB_WMBn_D03_Data_byte_1_MASK)
#define CAN_WMB_WMBn_D03_Data_byte_2_MASK                      (0xFF00U)
#define CAN_WMB_WMBn_D03_Data_byte_2_SHIFT                     (8U)
#define CAN_WMB_WMBn_D03_Data_byte_2(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D03_Data_byte_2_SHIFT)) & CAN_WMB_WMBn_D03_Data_byte_2_MASK)
#define CAN_WMB_WMBn_D03_Data_byte_3_MASK                      (0xFFU)
#define CAN_WMB_WMBn_D03_Data_byte_3_SHIFT                     (0U)
#define CAN_WMB_WMBn_D03_Data_byte_3(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D03_Data_byte_3_SHIFT)) & CAN_WMB_WMBn_D03_Data_byte_3_MASK)
/* CAN_WMB_WMBn_D47 Register */
#define CAN_WMB_WMBn_D47_Data_byte_4_MASK                      (0xFF000000U)
#define CAN_WMB_WMBn_D47_Data_byte_4_SHIFT                     (24U)
#define CAN_WMB_WMBn_D47_Data_byte_4(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D47_Data_byte_4_SHIFT)) & CAN_WMB_WMBn_D47_Data_byte_4_MASK)
#define CAN_WMB_WMBn_D47_Data_byte_5_MASK                      (0xFF0000U)
#define CAN_WMB_WMBn_D47_Data_byte_5_SHIFT                     (16U)
#define CAN_WMB_WMBn_D47_Data_byte_5(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D47_Data_byte_5_SHIFT)) & CAN_WMB_WMBn_D47_Data_byte_5_MASK)
#define CAN_WMB_WMBn_D47_Data_byte_6_MASK                      (0xFF00U)
#define CAN_WMB_WMBn_D47_Data_byte_6_SHIFT                     (8U)
#define CAN_WMB_WMBn_D47_Data_byte_6(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D47_Data_byte_6_SHIFT)) & CAN_WMB_WMBn_D47_Data_byte_6_MASK)
#define CAN_WMB_WMBn_D47_Data_byte_7_MASK                      (0xFFU)
#define CAN_WMB_WMBn_D47_Data_byte_7_SHIFT                     (0U)
#define CAN_WMB_WMBn_D47_Data_byte_7(x)                        (((uint32)(((uint32)(x)) << CAN_WMB_WMBn_D47_Data_byte_7_SHIFT)) & CAN_WMB_WMBn_D47_Data_byte_7_MASK)

/* CAN_EPRS Register */
#define CAN_EPRS_EDPRESDIV_MASK                            (0x3FF0000U)
#define CAN_EPRS_EDPRESDIV_SHIFT                           (16U)
#define CAN_EPRS_EDPRESDIV(x)                              (((uint32)(((uint32)(x)) << CAN_EPRS_EDPRESDIV_SHIFT)) & CAN_EPRS_EDPRESDIV_MASK)
#define CAN_EPRS_ENPRESDIV_MASK                            (0x3FFU)
#define CAN_EPRS_ENPRESDIV_SHIFT                           (0U)
#define CAN_EPRS_ENPRESDIV(x)                              (((uint32)(((uint32)(x)) << CAN_EPRS_ENPRESDIV_SHIFT)) & CAN_EPRS_ENPRESDIV_MASK)
/* CAN_ENCBT Register */
#define CAN_ENCBT_NRJW_MASK                                (0x1FC00000U)
#define CAN_ENCBT_NRJW_SHIFT                               (22U)
#define CAN_ENCBT_NRJW(x)                                  (((uint32)(((uint32)(x)) << CAN_ENCBT_NRJW_SHIFT)) & CAN_ENCBT_NRJW_MASK)
#define CAN_ENCBT_NTSEG2_MASK                              (0x7F000U)
#define CAN_ENCBT_NTSEG2_SHIFT                             (12U)
#define CAN_ENCBT_NTSEG2(x)                                (((uint32)(((uint32)(x)) << CAN_ENCBT_NTSEG2_SHIFT)) & CAN_ENCBT_NTSEG2_MASK)
#define CAN_ENCBT_NTSEG1_MASK                              (0xFFU)
#define CAN_ENCBT_NTSEG1_SHIFT                             (0U)
#define CAN_ENCBT_NTSEG1(x)                                (((uint32)(((uint32)(x)) << CAN_ENCBT_NTSEG1_SHIFT)) & CAN_ENCBT_NTSEG1_MASK)
/* CAN_EDCBT Register */
#define CAN_EDCBT_DRJW_MASK                                (0x3C00000U)
#define CAN_EDCBT_DRJW_SHIFT                               (22U)
#define CAN_EDCBT_DRJW(x)                                  (((uint32)(((uint32)(x)) << CAN_EDCBT_DRJW_SHIFT)) & CAN_EDCBT_DRJW_MASK)
#define CAN_EDCBT_DTSEG2_MASK                              (0xF000U)
#define CAN_EDCBT_DTSEG2_SHIFT                             (12U)
#define CAN_EDCBT_DTSEG2(x)                                (((uint32)(((uint32)(x)) << CAN_EDCBT_DTSEG2_SHIFT)) & CAN_EDCBT_DTSEG2_MASK)
#define CAN_EDCBT_DTSEG1_MASK                              (0x1FU)
#define CAN_EDCBT_DTSEG1_SHIFT                             (0U)
#define CAN_EDCBT_DTSEG1(x)                                (((uint32)(((uint32)(x)) << CAN_EDCBT_DTSEG1_SHIFT)) & CAN_EDCBT_DTSEG1_MASK)
/* CAN_ETDC Register */
#define CAN_ETDC_ETDCEN_MASK                               (0x80000000U)
#define CAN_ETDC_ETDCEN_SHIFT                              (31U)
#define CAN_ETDC_ETDCEN(x)                                 (((uint32)(((uint32)(x)) << CAN_ETDC_ETDCEN_SHIFT)) & CAN_ETDC_ETDCEN_MASK)
#define CAN_ETDC_TDMDIS_MASK                               (0x40000000U)
#define CAN_ETDC_TDMDIS_SHIFT                              (30U)
#define CAN_ETDC_TDMDIS(x)                                 (((uint32)(((uint32)(x)) << CAN_ETDC_TDMDIS_SHIFT)) & CAN_ETDC_TDMDIS_MASK)
#define CAN_ETDC_ETDCOFF_MASK                              (0x7F0000U)
#define CAN_ETDC_ETDCOFF_SHIFT                             (16U)
#define CAN_ETDC_ETDCOFF(x)                                (((uint32)(((uint32)(x)) << CAN_ETDC_ETDCOFF_SHIFT)) & CAN_ETDC_ETDCOFF_MASK)
#define CAN_ETDC_ETDCFAIL_MASK                             (0x8000U)
#define CAN_ETDC_ETDCFAIL_SHIFT                            (15U)
#define CAN_ETDC_ETDCFAIL(x)                               (((uint32)(((uint32)(x)) << CAN_ETDC_ETDCFAIL_SHIFT)) & CAN_ETDC_ETDCFAIL_MASK)
#define CAN_ETDC_ETDCVAL_MASK                              (0xFFU)
#define CAN_ETDC_ETDCVAL_SHIFT                             (0U)
#define CAN_ETDC_ETDCVAL(x)                                (((uint32)(((uint32)(x)) << CAN_ETDC_ETDCVAL_SHIFT)) & CAN_ETDC_ETDCVAL_MASK)
/* CAN_FDCTRL Register */
#define CAN_FDCTRL_FDRATE_MASK                             (0x80000000U)
#define CAN_FDCTRL_FDRATE_SHIFT                            (31U)
#define CAN_FDCTRL_FDRATE(x)                               (((uint32)(((uint32)(x)) << CAN_FDCTRL_FDRATE_SHIFT)) & CAN_FDCTRL_FDRATE_MASK)
#define CAN_FDCTRL_MBDSR3_MASK                             (0x6000000U)
#define CAN_FDCTRL_MBDSR3_SHIFT                            (25U)
#define CAN_FDCTRL_MBDSR3(x)                               (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR3_SHIFT)) & CAN_FDCTRL_MBDSR3_MASK)
#define CAN_FDCTRL_MBDSR2_MASK                             (0xC00000U)
#define CAN_FDCTRL_MBDSR2_SHIFT                            (22U)
#define CAN_FDCTRL_MBDSR2(x)                               (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR2_SHIFT)) & CAN_FDCTRL_MBDSR2_MASK)
#define CAN_FDCTRL_MBDSR1_MASK                             (0x180000U)
#define CAN_FDCTRL_MBDSR1_SHIFT                            (19U)
#define CAN_FDCTRL_MBDSR1(x)                               (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR1_SHIFT)) & CAN_FDCTRL_MBDSR1_MASK)
#define CAN_FDCTRL_MBDSR0_MASK                             (0x30000U)
#define CAN_FDCTRL_MBDSR0_SHIFT                            (16U)
#define CAN_FDCTRL_MBDSR0(x)                               (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR0_SHIFT)) & CAN_FDCTRL_MBDSR0_MASK)
#define CAN_FDCTRL_TDCEN_MASK                              (0x8000U)
#define CAN_FDCTRL_TDCEN_SHIFT                             (15U)
#define CAN_FDCTRL_TDCEN(x)                                (((uint32)(((uint32)(x)) << CAN_FDCTRL_TDCEN_SHIFT)) & CAN_FDCTRL_TDCEN_MASK)
#define CAN_FDCTRL_TDCFAIL_MASK                            (0x4000U)
#define CAN_FDCTRL_TDCFAIL_SHIFT                           (14U)
#define CAN_FDCTRL_TDCFAIL(x)                              (((uint32)(((uint32)(x)) << CAN_FDCTRL_TDCFAIL_SHIFT)) & CAN_FDCTRL_TDCFAIL_MASK)
#define CAN_FDCTRL_TDCOFF_MASK                             (0x1F00U)
#define CAN_FDCTRL_TDCOFF_SHIFT                            (8U)
#define CAN_FDCTRL_TDCOFF(x)                               (((uint32)(((uint32)(x)) << CAN_FDCTRL_TDCOFF_SHIFT)) & CAN_FDCTRL_TDCOFF_MASK)
#define CAN_FDCTRL_TDCVAL_MASK                             (0x3FU)
#define CAN_FDCTRL_TDCVAL_SHIFT                            (0U)
#define CAN_FDCTRL_TDCVAL(x)                               (((uint32)(((uint32)(x)) << CAN_FDCTRL_TDCVAL_SHIFT)) & CAN_FDCTRL_TDCVAL_MASK)
/* CAN_FDCBT Register */
#define CAN_FDCBT_FPRESDIV_MASK                            (0x3FF00000U)
#define CAN_FDCBT_FPRESDIV_SHIFT                           (20U)
#define CAN_FDCBT_FPRESDIV(x)                              (((uint32)(((uint32)(x)) << CAN_FDCBT_FPRESDIV_SHIFT)) & CAN_FDCBT_FPRESDIV_MASK)
#define CAN_FDCBT_FRJW_MASK                                (0x70000U)
#define CAN_FDCBT_FRJW_SHIFT                               (16U)
#define CAN_FDCBT_FRJW(x)                                  (((uint32)(((uint32)(x)) << CAN_FDCBT_FRJW_SHIFT)) & CAN_FDCBT_FRJW_MASK)
#define CAN_FDCBT_FPROPSEG_MASK                            (0x7C00U)
#define CAN_FDCBT_FPROPSEG_SHIFT                           (10U)
#define CAN_FDCBT_FPROPSEG(x)                              (((uint32)(((uint32)(x)) << CAN_FDCBT_FPROPSEG_SHIFT)) & CAN_FDCBT_FPROPSEG_MASK)
#define CAN_FDCBT_FPSEG1_MASK                              (0xE0U)
#define CAN_FDCBT_FPSEG1_SHIFT                             (5U)
#define CAN_FDCBT_FPSEG1(x)                                (((uint32)(((uint32)(x)) << CAN_FDCBT_FPSEG1_SHIFT)) & CAN_FDCBT_FPSEG1_MASK)
#define CAN_FDCBT_FPSEG2_MASK                              (0x7U)
#define CAN_FDCBT_FPSEG2_SHIFT                             (0U)
#define CAN_FDCBT_FPSEG2(x)                                (((uint32)(((uint32)(x)) << CAN_FDCBT_FPSEG2_SHIFT)) & CAN_FDCBT_FPSEG2_MASK)
/* CAN_FDCRC Register */
#define CAN_FDCRC_FD_MBCRC_MASK                            (0x7F000000U)
#define CAN_FDCRC_FD_MBCRC_SHIFT                           (24U)
#define CAN_FDCRC_FD_MBCRC(x)                              (((uint32)(((uint32)(x)) << CAN_FDCRC_FD_MBCRC_SHIFT)) & CAN_FDCRC_FD_MBCRC_MASK)
#define CAN_FDCRC_FD_TXCRC_MASK                            (0x1FFFFFU)
#define CAN_FDCRC_FD_TXCRC_SHIFT                           (0U)
#define CAN_FDCRC_FD_TXCRC(x)                              (((uint32)(((uint32)(x)) << CAN_FDCRC_FD_TXCRC_SHIFT)) & CAN_FDCRC_FD_TXCRC_MASK)
/* CAN_ERFCR Register */
#define CAN_ERFCR_ERFEN_MASK                               (0x80000000U)
#define CAN_ERFCR_ERFEN_SHIFT                              (31U)
#define CAN_ERFCR_ERFEN(x)                                 (((uint32)(((uint32)(x)) << CAN_ERFCR_ERFEN_SHIFT)) & CAN_ERFCR_ERFEN_MASK)
#define CAN_ERFCR_DMALW_MASK                               (0x7C000000U)
#define CAN_ERFCR_DMALW_SHIFT                              (26U)
#define CAN_ERFCR_DMALW(x)                                 (((uint32)(((uint32)(x)) << CAN_ERFCR_DMALW_SHIFT)) & CAN_ERFCR_DMALW_MASK)
#define CAN_ERFCR_NEXIF_MASK                               (0x7F0000U)
#define CAN_ERFCR_NEXIF_SHIFT                              (16U)
#define CAN_ERFCR_NEXIF(x)                                 (((uint32)(((uint32)(x)) << CAN_ERFCR_NEXIF_SHIFT)) & CAN_ERFCR_NEXIF_MASK)
#define CAN_ERFCR_NFE_MASK                                 (0x3F00U)
#define CAN_ERFCR_NFE_SHIFT                                (8U)
#define CAN_ERFCR_NFE(x)                                   (((uint32)(((uint32)(x)) << CAN_ERFCR_NFE_SHIFT)) & CAN_ERFCR_NFE_MASK)
#define CAN_ERFCR_ERFWM_MASK                               (0x1FU)
#define CAN_ERFCR_ERFWM_SHIFT                              (0U)
#define CAN_ERFCR_ERFWM(x)                                 (((uint32)(((uint32)(x)) << CAN_ERFCR_ERFWM_SHIFT)) & CAN_ERFCR_ERFWM_MASK)
/* CAN_ERFIER Register */
#define CAN_ERFIER_ERFUFWIE_MASK                           (0x80000000U)
#define CAN_ERFIER_ERFUFWIE_SHIFT                          (31U)
#define CAN_ERFIER_ERFUFWIE(x)                             (((uint32)(((uint32)(x)) << CAN_ERFIER_ERFUFWIE_SHIFT)) & CAN_ERFIER_ERFUFWIE_MASK)
#define CAN_ERFIER_ERFOVFIE_MASK                           (0x40000000U)
#define CAN_ERFIER_ERFOVFIE_SHIFT                          (30U)
#define CAN_ERFIER_ERFOVFIE(x)                             (((uint32)(((uint32)(x)) << CAN_ERFIER_ERFOVFIE_SHIFT)) & CAN_ERFIER_ERFOVFIE_MASK)
#define CAN_ERFIER_ERFWMIIE_MASK                           (0x20000000U)
#define CAN_ERFIER_ERFWMIIE_SHIFT                          (29U)
#define CAN_ERFIER_ERFWMIIE(x)                             (((uint32)(((uint32)(x)) << CAN_ERFIER_ERFWMIIE_SHIFT)) & CAN_ERFIER_ERFWMIIE_MASK)
#define CAN_ERFIER_ERFDAIE_MASK                            (0x10000000U)
#define CAN_ERFIER_ERFDAIE_SHIFT                           (28U)
#define CAN_ERFIER_ERFDAIE(x)                              (((uint32)(((uint32)(x)) << CAN_ERFIER_ERFDAIE_SHIFT)) & CAN_ERFIER_ERFDAIE_MASK)
/* CAN_ERFSR Register */
#define CAN_ERFSR_ERFUFW_MASK                              (0x80000000U)
#define CAN_ERFSR_ERFUFW_SHIFT                             (31U)
#define CAN_ERFSR_ERFUFW(x)                                (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFUFW_SHIFT)) & CAN_ERFSR_ERFUFW_MASK)
#define CAN_ERFSR_ERFOVF_MASK                              (0x40000000U)
#define CAN_ERFSR_ERFOVF_SHIFT                             (30U)
#define CAN_ERFSR_ERFOVF(x)                                (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFOVF_SHIFT)) & CAN_ERFSR_ERFOVF_MASK)
#define CAN_ERFSR_ERFWMI_MASK                              (0x20000000U)
#define CAN_ERFSR_ERFWMI_SHIFT                             (29U)
#define CAN_ERFSR_ERFWMI(x)                                (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFWMI_SHIFT)) & CAN_ERFSR_ERFWMI_MASK)
#define CAN_ERFSR_ERFDA_MASK                               (0x10000000U)
#define CAN_ERFSR_ERFDA_SHIFT                              (28U)
#define CAN_ERFSR_ERFDA(x)                                 (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFDA_SHIFT)) & CAN_ERFSR_ERFDA_MASK)
#define CAN_ERFSR_ERFCLR_MASK                              (0x8000000U)
#define CAN_ERFSR_ERFCLR_SHIFT                             (27U)
#define CAN_ERFSR_ERFCLR(x)                                (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFCLR_SHIFT)) & CAN_ERFSR_ERFCLR_MASK)
#define CAN_ERFSR_ERFE_MASK                                (0x20000U)
#define CAN_ERFSR_ERFE_SHIFT                               (17U)
#define CAN_ERFSR_ERFE(x)                                  (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFE_SHIFT)) & CAN_ERFSR_ERFE_MASK)
#define CAN_ERFSR_ERFF_MASK                                (0x10000U)
#define CAN_ERFSR_ERFF_SHIFT                               (16U)
#define CAN_ERFSR_ERFF(x)                                  (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFF_SHIFT)) & CAN_ERFSR_ERFF_MASK)
#define CAN_ERFSR_ERFEL_MASK                               (0x3FU)
#define CAN_ERFSR_ERFEL_SHIFT                              (0U)
#define CAN_ERFSR_ERFEL(x)                                 (((uint32)(((uint32)(x)) << CAN_ERFSR_ERFEL_SHIFT)) & CAN_ERFSR_ERFEL_MASK)
/* CAN_HR_TIME_STAMPn Register */
#define CAN_HR_TIME_STAMPn_TS_MASK                         (0xFFFFFFFFU)
#define CAN_HR_TIME_STAMPn_TS_SHIFT                        (0U)
#define CAN_HR_TIME_STAMPn_TS(x)                           (((uint32)(((uint32)(x)) << CAN_HR_TIME_STAMPn_TS_SHIFT)) & CAN_HR_TIME_STAMPn_TS_MASK)
/* CAN_ERFFELn Register */
#define CAN_ERFFELn_FEL_MASK                               (0xFFFFFFFFU)
#define CAN_ERFFELn_FEL_SHIFT                              (0U)
#define CAN_ERFFELn_FEL(x)                                 (((uint32)(((uint32)(x)) << CAN_ERFFELn_FEL_SHIFT)) & CAN_ERFFELn_FEL_MASK)


/**
 * @}
 */ /* end of group CAN_Register_Masks */


/**
 * @}
 */ /* end of group CAN_Peripheral_Access_Layer */

#endif /* PSIP_CAN_H */

