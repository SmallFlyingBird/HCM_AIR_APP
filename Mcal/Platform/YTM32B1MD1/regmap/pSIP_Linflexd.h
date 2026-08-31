/**
*   @file    pSIP_Linflexd.h
*   @version
*
*   @brief   AUTOSAR Linflexd register map
*   @details Register map for LINFLEXD
*
*   @addtogroup LINFLEXD_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : LINFlexD
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

#ifndef PSIP_LINFLEXD_H
#define PSIP_LINFLEXD_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              LINFLEXD REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup LINFlexD_Peripheral_Access_Layer LINFlexD Peripheral Access Layer
 * @{
 */


/** LINFlexD - Size of Registers Arrays */
#define LINFlexD_IFCR_COUNT           (16)

/* LINFlexD Register Layout Typedef */
typedef struct {
    uint32 LINCR1;                             /**< LIN Control Register 1, offset: 0x0000 */
    uint32 LINIER;                             /**< LIN Interrupt Enable Register, offset: 0x0004 */
    uint32 LINSR;                              /**< LIN Status Register, offset: 0x0008 */
    uint32 LINESR;                             /**< LIN Error Status Register, offset: 0x000C */
    uint32 UARTCR;                             /**< UART Mode Control Register, offset: 0x0010 */
    uint32 UARTSR;                             /**< UART Mode Status Register, offset: 0x0014 */
    uint32 LINTCSR;                            /**< LIN Timeout Control Status Register, offset: 0x0018 */
    uint32 LINOCR;                             /**< LIN Output Compare Register, offset: 0x001C */
    uint32 LINTOCR;                            /**< LIN Timeout Control Register, offset: 0x0020 */
    uint32 LINFBRR;                            /**< LIN Fractional Baud Rate Register, offset: 0x0024 */
    uint32 LINIBRR;                            /**< LIN Integer Baud Rate Register, offset: 0x0028 */
    uint32 LINCFR;                             /**< LIN Checksum Field Register, offset: 0x002C */
    uint32 LINCR2;                             /**< LIN Control Register 2, offset: 0x0030 */
    uint32 BIDR;                               /**< Buffer Identifier Register, offset: 0x0034 */
    union {
    uint8 DATA8[ 8];                          /**< Data in Byte, offset: 0x0038 */
    uint16 DATA16[ 4];                         /**< Data in half-word, offset: 0x0038 */
    uint32 DATA32[ 2];                         /**< Data in Word, offset: 0x0038 */

    } DATA;
    uint32 IFER;                               /**< Identifier Filter Enable Register, offset: 0x0040 */
    uint32 IFMI;                               /**< Identifier Filter Match Index, offset: 0x0044 */
    uint32 IFMR;                               /**< Identifier Filter Mode Register, offset: 0x0048 */
    uint32 IFCR[16];                           /**< Identifier Filter Control Register, offset: 0x004C */
    uint32 GCR;                                /**< Global Control Register, offset: 0x008C */
    uint32 UARTPTO;                            /**< UART Preset Timeout Register, offset: 0x0090 */
    uint32 UARTCTO;                            /**< UART Current Timeout Register, offset: 0x0094 */
    uint32 DMATXE;                             /**< DMA Tx Enable Register, offset: 0x0098 */
    uint32 DMARXE;                             /**< DMA Rx Enable Register, offset: 0x009C */

} LINFlexD_Type, *LINFlexD_MemMapPtr;

/** Number of instances of the LINFlexD module. */
#define LINFlexD_INSTANCE_COUNT                        (3u)

/* LINFlexD0  base address */
#define LINFlexD0_BASE_ADDR32                              (0x4001B000U)
#define LINFlexD0                                          ((volatile LINFlexD_Type *)(LINFlexD0_BASE_ADDR32))
/* LINFlexD1  base address */
#define LINFlexD1_BASE_ADDR32                              (0x4001C000U)
#define LINFlexD1                                          ((volatile LINFlexD_Type *)(LINFlexD1_BASE_ADDR32))
/* LINFlexD2  base address */
#define LINFlexD2_BASE_ADDR32                              (0x4001D000U)
#define LINFlexD2                                          ((volatile LINFlexD_Type *)(LINFlexD2_BASE_ADDR32))

/** Array initializer of LINFlexD peripheral base addresses */
#define LINFlexD_BASE_ADDRS                                { LINFlexD0_BASE_ADDR32,  LINFlexD1_BASE_ADDR32,  LINFlexD2_BASE_ADDR32 }
/** Array initializer of LINFlexD peripheral base pointers */
#define LINFlexD_BASE_PTRS                                 { LINFlexD0,  LINFlexD1,  LINFlexD2 }

#define LINFlexD_LINCR1_OFFSET32                           (0x0000U)                    /**< Offset for LIN Control Register 1 */
#define LINFlexD_LINIER_OFFSET32                           (0x0004U)                    /**< Offset for LIN Interrupt Enable Register */
#define LINFlexD_LINSR_OFFSET32                            (0x0008U)                    /**< Offset for LIN Status Register */
#define LINFlexD_LINESR_OFFSET32                           (0x000CU)                    /**< Offset for LIN Error Status Register */
#define LINFlexD_UARTCR_OFFSET32                           (0x0010U)                    /**< Offset for UART Mode Control Register */
#define LINFlexD_UARTSR_OFFSET32                           (0x0014U)                    /**< Offset for UART Mode Status Register */
#define LINFlexD_LINTCSR_OFFSET32                          (0x0018U)                    /**< Offset for LIN Timeout Control Status Register */
#define LINFlexD_LINOCR_OFFSET32                           (0x001CU)                    /**< Offset for LIN Output Compare Register */
#define LINFlexD_LINTOCR_OFFSET32                          (0x0020U)                    /**< Offset for LIN Timeout Control Register */
#define LINFlexD_LINFBRR_OFFSET32                          (0x0024U)                    /**< Offset for LIN Fractional Baud Rate Register */
#define LINFlexD_LINIBRR_OFFSET32                          (0x0028U)                    /**< Offset for LIN Integer Baud Rate Register */
#define LINFlexD_LINCFR_OFFSET32                           (0x002CU)                    /**< Offset for LIN Checksum Field Register */
#define LINFlexD_LINCR2_OFFSET32                           (0x0030U)                    /**< Offset for LIN Control Register 2 */
#define LINFlexD_BIDR_OFFSET32                             (0x0034U)                    /**< Offset for Buffer Identifier Register */
#define LINFlexD_DATA_OFFSET32                             (0x0038U)                    /**< Offset for Buffer Data Register */
#define LINFlexD_DATA_DATA8_OFFSET8(x)                    (0x0038U + ((x) * (1U)))     /**< Offset for Data in Byte */
#define LINFlexD_DATA_DATA16_OFFSET16(x)                   (0x0038U + ((x) * (1U)))     /**< Offset for Data in half-word */
#define LINFlexD_DATA_DATA32_OFFSET32(x)                   (0x0038U + ((x) * (1U)))     /**< Offset for Data in Word */


#define LINFlexD_IFER_OFFSET32                             (0x0040U)                    /**< Offset for Identifier Filter Enable Register */
#define LINFlexD_IFMI_OFFSET32                             (0x0044U)                    /**< Offset for Identifier Filter Match Index */
#define LINFlexD_IFMR_OFFSET32                             (0x0048U)                    /**< Offset for Identifier Filter Mode Register */
#define LINFlexD_IFCR_OFFSET32(x)                          (0x004CU + ((x) * (4U)))     /**< Offset for Identifier Filter Control Register */
#define LINFlexD_GCR_OFFSET32                              (0x008CU)                    /**< Offset for Global Control Register */
#define LINFlexD_UARTPTO_OFFSET32                          (0x0090U)                    /**< Offset for UART Preset Timeout Register */
#define LINFlexD_UARTCTO_OFFSET32                          (0x0094U)                    /**< Offset for UART Current Timeout Register */
#define LINFlexD_DMATXE_OFFSET32                           (0x0098U)                    /**< Offset for DMA Tx Enable Register */
#define LINFlexD_DMARXE_OFFSET32                           (0x009CU)                    /**< Offset for DMA Rx Enable Register */


/**
 * @addtogroup LINFlexD Register Mask
 * @{
 */
/* LINFlexD_LINCR1 Register */
#define LINFlexD_LINCR1_NLSE_MASK                               (0x10000U)
#define LINFlexD_LINCR1_NLSE_SHIFT                              (16U)
#define LINFlexD_LINCR1_NLSE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_NLSE_SHIFT)) & LINFlexD_LINCR1_NLSE_MASK)
#define LINFlexD_LINCR1_CCD_MASK                                (0x8000U)
#define LINFlexD_LINCR1_CCD_SHIFT                               (15U)
#define LINFlexD_LINCR1_CCD(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_CCD_SHIFT)) & LINFlexD_LINCR1_CCD_MASK)
#define LINFlexD_LINCR1_CFD_MASK                                (0x4000U)
#define LINFlexD_LINCR1_CFD_SHIFT                               (14U)
#define LINFlexD_LINCR1_CFD(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_CFD_SHIFT)) & LINFlexD_LINCR1_CFD_MASK)
#define LINFlexD_LINCR1_LASE_MASK                               (0x2000U)
#define LINFlexD_LINCR1_LASE_SHIFT                              (13U)
#define LINFlexD_LINCR1_LASE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_LASE_SHIFT)) & LINFlexD_LINCR1_LASE_MASK)
#define LINFlexD_LINCR1_AUTOWU_MASK                             (0x1000U)
#define LINFlexD_LINCR1_AUTOWU_SHIFT                            (12U)
#define LINFlexD_LINCR1_AUTOWU(x)                               (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_AUTOWU_SHIFT)) & LINFlexD_LINCR1_AUTOWU_MASK)
#define LINFlexD_LINCR1_MBL_MASK                                (0xF00U)
#define LINFlexD_LINCR1_MBL_SHIFT                               (8U)
#define LINFlexD_LINCR1_MBL(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_MBL_SHIFT)) & LINFlexD_LINCR1_MBL_MASK)
#define LINFlexD_LINCR1_BF_MASK                                 (0x80U)
#define LINFlexD_LINCR1_BF_SHIFT                                (7U)
#define LINFlexD_LINCR1_BF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_BF_SHIFT)) & LINFlexD_LINCR1_BF_MASK)
#define LINFlexD_LINCR1_LBKM_MASK                               (0x20U)
#define LINFlexD_LINCR1_LBKM_SHIFT                              (5U)
#define LINFlexD_LINCR1_LBKM(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_LBKM_SHIFT)) & LINFlexD_LINCR1_LBKM_MASK)
#define LINFlexD_LINCR1_MME_MASK                                (0x10U)
#define LINFlexD_LINCR1_MME_SHIFT                               (4U)
#define LINFlexD_LINCR1_MME(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_MME_SHIFT)) & LINFlexD_LINCR1_MME_MASK)
#define LINFlexD_LINCR1_SSBL_MASK                               (0x8U)
#define LINFlexD_LINCR1_SSBL_SHIFT                              (3U)
#define LINFlexD_LINCR1_SSBL(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_SSBL_SHIFT)) & LINFlexD_LINCR1_SSBL_MASK)
#define LINFlexD_LINCR1_RBLM_MASK                               (0x4U)
#define LINFlexD_LINCR1_RBLM_SHIFT                              (2U)
#define LINFlexD_LINCR1_RBLM(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_RBLM_SHIFT)) & LINFlexD_LINCR1_RBLM_MASK)
#define LINFlexD_LINCR1_SLEEP_MASK                              (0x2U)
#define LINFlexD_LINCR1_SLEEP_SHIFT                             (1U)
#define LINFlexD_LINCR1_SLEEP(x)                                (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_SLEEP_SHIFT)) & LINFlexD_LINCR1_SLEEP_MASK)
#define LINFlexD_LINCR1_INIT_MASK                               (0x1U)
#define LINFlexD_LINCR1_INIT_SHIFT                              (0U)
#define LINFlexD_LINCR1_INIT(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR1_INIT_SHIFT)) & LINFlexD_LINCR1_INIT_MASK)
/* LINFlexD_LINIER Register */
#define LINFlexD_LINIER_REDIE_MASK                              (0x20000U)
#define LINFlexD_LINIER_REDIE_SHIFT                             (17U)
#define LINFlexD_LINIER_REDIE(x)                                (((uint32)(((uint32)(x)) << LINFlexD_LINIER_REDIE_SHIFT)) & LINFlexD_LINIER_REDIE_MASK)
#define LINFlexD_LINIER_SZIE_MASK                               (0x8000U)
#define LINFlexD_LINIER_SZIE_SHIFT                              (15U)
#define LINFlexD_LINIER_SZIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_SZIE_SHIFT)) & LINFlexD_LINIER_SZIE_MASK)
#define LINFlexD_LINIER_OCIE_MASK                               (0x4000U)
#define LINFlexD_LINIER_OCIE_SHIFT                              (14U)
#define LINFlexD_LINIER_OCIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_OCIE_SHIFT)) & LINFlexD_LINIER_OCIE_MASK)
#define LINFlexD_LINIER_BEIE_MASK                               (0x2000U)
#define LINFlexD_LINIER_BEIE_SHIFT                              (13U)
#define LINFlexD_LINIER_BEIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_BEIE_SHIFT)) & LINFlexD_LINIER_BEIE_MASK)
#define LINFlexD_LINIER_CEIE_MASK                               (0x1000U)
#define LINFlexD_LINIER_CEIE_SHIFT                              (12U)
#define LINFlexD_LINIER_CEIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_CEIE_SHIFT)) & LINFlexD_LINIER_CEIE_MASK)
#define LINFlexD_LINIER_HEIE_MASK                               (0x800U)
#define LINFlexD_LINIER_HEIE_SHIFT                              (11U)
#define LINFlexD_LINIER_HEIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_HEIE_SHIFT)) & LINFlexD_LINIER_HEIE_MASK)
#define LINFlexD_LINIER_FEIE_MASK                               (0x100U)
#define LINFlexD_LINIER_FEIE_SHIFT                              (8U)
#define LINFlexD_LINIER_FEIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_FEIE_SHIFT)) & LINFlexD_LINIER_FEIE_MASK)
#define LINFlexD_LINIER_BOIE_MASK                               (0x80U)
#define LINFlexD_LINIER_BOIE_SHIFT                              (7U)
#define LINFlexD_LINIER_BOIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_BOIE_SHIFT)) & LINFlexD_LINIER_BOIE_MASK)
#define LINFlexD_LINIER_LSIE_MASK                               (0x40U)
#define LINFlexD_LINIER_LSIE_SHIFT                              (6U)
#define LINFlexD_LINIER_LSIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_LSIE_SHIFT)) & LINFlexD_LINIER_LSIE_MASK)
#define LINFlexD_LINIER_WUIE_MASK                               (0x20U)
#define LINFlexD_LINIER_WUIE_SHIFT                              (5U)
#define LINFlexD_LINIER_WUIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_WUIE_SHIFT)) & LINFlexD_LINIER_WUIE_MASK)
#define LINFlexD_LINIER_TOIE_MASK                               (0x8U)
#define LINFlexD_LINIER_TOIE_SHIFT                              (3U)
#define LINFlexD_LINIER_TOIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_TOIE_SHIFT)) & LINFlexD_LINIER_TOIE_MASK)
#define LINFlexD_LINIER_DRIE_MASK                               (0x4U)
#define LINFlexD_LINIER_DRIE_SHIFT                              (2U)
#define LINFlexD_LINIER_DRIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_DRIE_SHIFT)) & LINFlexD_LINIER_DRIE_MASK)
#define LINFlexD_LINIER_DTIE_MASK                               (0x2U)
#define LINFlexD_LINIER_DTIE_SHIFT                              (1U)
#define LINFlexD_LINIER_DTIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_DTIE_SHIFT)) & LINFlexD_LINIER_DTIE_MASK)
#define LINFlexD_LINIER_HRIE_MASK                               (0x1U)
#define LINFlexD_LINIER_HRIE_SHIFT                              (0U)
#define LINFlexD_LINIER_HRIE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIER_HRIE_SHIFT)) & LINFlexD_LINIER_HRIE_MASK)
/* LINFlexD_LINSR Register */
#define LINFlexD_LINSR_REDF_MASK                                (0x200000U)
#define LINFlexD_LINSR_REDF_SHIFT                               (21U)
#define LINFlexD_LINSR_REDF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINSR_REDF_SHIFT)) & LINFlexD_LINSR_REDF_MASK)
#define LINFlexD_LINSR_AUTOSYNC_COMP_MASK                       (0x80000U)
#define LINFlexD_LINSR_AUTOSYNC_COMP_SHIFT                      (19U)
#define LINFlexD_LINSR_AUTOSYNC_COMP(x)                         (((uint32)(((uint32)(x)) << LINFlexD_LINSR_AUTOSYNC_COMP_SHIFT)) & LINFlexD_LINSR_AUTOSYNC_COMP_MASK)
#define LINFlexD_LINSR_RDC_MASK                                 (0x70000U)
#define LINFlexD_LINSR_RDC_SHIFT                                (16U)
#define LINFlexD_LINSR_RDC(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINSR_RDC_SHIFT)) & LINFlexD_LINSR_RDC_MASK)
#define LINFlexD_LINSR_LINS_MASK                                (0xF000U)
#define LINFlexD_LINSR_LINS_SHIFT                               (12U)
#define LINFlexD_LINSR_LINS(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINSR_LINS_SHIFT)) & LINFlexD_LINSR_LINS_MASK)
#define LINFlexD_LINSR_RMB_MASK                                 (0x200U)
#define LINFlexD_LINSR_RMB_SHIFT                                (9U)
#define LINFlexD_LINSR_RMB(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINSR_RMB_SHIFT)) & LINFlexD_LINSR_RMB_MASK)
#define LINFlexD_LINSR_DRBNE_MASK                               (0x100U)
#define LINFlexD_LINSR_DRBNE_SHIFT                              (8U)
#define LINFlexD_LINSR_DRBNE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINSR_DRBNE_SHIFT)) & LINFlexD_LINSR_DRBNE_MASK)
#define LINFlexD_LINSR_RXBUSY_MASK                              (0x80U)
#define LINFlexD_LINSR_RXBUSY_SHIFT                             (7U)
#define LINFlexD_LINSR_RXBUSY(x)                                (((uint32)(((uint32)(x)) << LINFlexD_LINSR_RXBUSY_SHIFT)) & LINFlexD_LINSR_RXBUSY_MASK)
#define LINFlexD_LINSR_RDI_MASK                                 (0x40U)
#define LINFlexD_LINSR_RDI_SHIFT                                (6U)
#define LINFlexD_LINSR_RDI(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINSR_RDI_SHIFT)) & LINFlexD_LINSR_RDI_MASK)
#define LINFlexD_LINSR_WUF_MASK                                 (0x20U)
#define LINFlexD_LINSR_WUF_SHIFT                                (5U)
#define LINFlexD_LINSR_WUF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINSR_WUF_SHIFT)) & LINFlexD_LINSR_WUF_MASK)
#define LINFlexD_LINSR_DRF_MASK                                 (0x4U)
#define LINFlexD_LINSR_DRF_SHIFT                                (2U)
#define LINFlexD_LINSR_DRF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINSR_DRF_SHIFT)) & LINFlexD_LINSR_DRF_MASK)
#define LINFlexD_LINSR_DTF_MASK                                 (0x2U)
#define LINFlexD_LINSR_DTF_SHIFT                                (1U)
#define LINFlexD_LINSR_DTF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINSR_DTF_SHIFT)) & LINFlexD_LINSR_DTF_MASK)
#define LINFlexD_LINSR_HRF_MASK                                 (0x1U)
#define LINFlexD_LINSR_HRF_SHIFT                                (0U)
#define LINFlexD_LINSR_HRF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINSR_HRF_SHIFT)) & LINFlexD_LINSR_HRF_MASK)
/* LINFlexD_LINESR Register */
#define LINFlexD_LINESR_SZF_MASK                                (0x8000U)
#define LINFlexD_LINESR_SZF_SHIFT                               (15U)
#define LINFlexD_LINESR_SZF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINESR_SZF_SHIFT)) & LINFlexD_LINESR_SZF_MASK)
#define LINFlexD_LINESR_OCF_MASK                                (0x4000U)
#define LINFlexD_LINESR_OCF_SHIFT                               (14U)
#define LINFlexD_LINESR_OCF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINESR_OCF_SHIFT)) & LINFlexD_LINESR_OCF_MASK)
#define LINFlexD_LINESR_BEF_MASK                                (0x2000U)
#define LINFlexD_LINESR_BEF_SHIFT                               (13U)
#define LINFlexD_LINESR_BEF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINESR_BEF_SHIFT)) & LINFlexD_LINESR_BEF_MASK)
#define LINFlexD_LINESR_CEF_MASK                                (0x1000U)
#define LINFlexD_LINESR_CEF_SHIFT                               (12U)
#define LINFlexD_LINESR_CEF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINESR_CEF_SHIFT)) & LINFlexD_LINESR_CEF_MASK)
#define LINFlexD_LINESR_SFEF_MASK                               (0x800U)
#define LINFlexD_LINESR_SFEF_SHIFT                              (11U)
#define LINFlexD_LINESR_SFEF(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINESR_SFEF_SHIFT)) & LINFlexD_LINESR_SFEF_MASK)
#define LINFlexD_LINESR_SDEF_MASK                               (0x400U)
#define LINFlexD_LINESR_SDEF_SHIFT                              (10U)
#define LINFlexD_LINESR_SDEF(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINESR_SDEF_SHIFT)) & LINFlexD_LINESR_SDEF_MASK)
#define LINFlexD_LINESR_IDPEF_MASK                              (0x200U)
#define LINFlexD_LINESR_IDPEF_SHIFT                             (9U)
#define LINFlexD_LINESR_IDPEF(x)                                (((uint32)(((uint32)(x)) << LINFlexD_LINESR_IDPEF_SHIFT)) & LINFlexD_LINESR_IDPEF_MASK)
#define LINFlexD_LINESR_FEF_MASK                                (0x100U)
#define LINFlexD_LINESR_FEF_SHIFT                               (8U)
#define LINFlexD_LINESR_FEF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINESR_FEF_SHIFT)) & LINFlexD_LINESR_FEF_MASK)
#define LINFlexD_LINESR_BOF_MASK                                (0x80U)
#define LINFlexD_LINESR_BOF_SHIFT                               (7U)
#define LINFlexD_LINESR_BOF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINESR_BOF_SHIFT)) & LINFlexD_LINESR_BOF_MASK)
#define LINFlexD_LINESR_NF_MASK                                 (0x1U)
#define LINFlexD_LINESR_NF_SHIFT                                (0U)
#define LINFlexD_LINESR_NF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINESR_NF_SHIFT)) & LINFlexD_LINESR_NF_MASK)
/* LINFlexD_UARTCR Register */
#define LINFlexD_UARTCR_MIS_MASK                                (0x80000000U)
#define LINFlexD_UARTCR_MIS_SHIFT                               (31U)
#define LINFlexD_UARTCR_MIS(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_MIS_SHIFT)) & LINFlexD_UARTCR_MIS_MASK)
#define LINFlexD_UARTCR_CSP_MASK                                (0x70000000U)
#define LINFlexD_UARTCR_CSP_SHIFT                               (28U)
#define LINFlexD_UARTCR_CSP(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_CSP_SHIFT)) & LINFlexD_UARTCR_CSP_MASK)
#define LINFlexD_UARTCR_OSR_MASK                                (0xF000000U)
#define LINFlexD_UARTCR_OSR_SHIFT                               (24U)
#define LINFlexD_UARTCR_OSR(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_OSR_SHIFT)) & LINFlexD_UARTCR_OSR_MASK)
#define LINFlexD_UARTCR_ROSE_MASK                               (0x800000U)
#define LINFlexD_UARTCR_ROSE_SHIFT                              (23U)
#define LINFlexD_UARTCR_ROSE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_ROSE_SHIFT)) & LINFlexD_UARTCR_ROSE_MASK)
#define LINFlexD_UARTCR_NEF_MASK                                (0x700000U)
#define LINFlexD_UARTCR_NEF_SHIFT                               (20U)
#define LINFlexD_UARTCR_NEF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_NEF_SHIFT)) & LINFlexD_UARTCR_NEF_MASK)
#define LINFlexD_UARTCR_DTU_MASK                                (0x80000U)
#define LINFlexD_UARTCR_DTU_SHIFT                               (19U)
#define LINFlexD_UARTCR_DTU(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_DTU_SHIFT)) & LINFlexD_UARTCR_DTU_MASK)
#define LINFlexD_UARTCR_SBUR_MASK                               (0x60000U)
#define LINFlexD_UARTCR_SBUR_SHIFT                              (17U)
#define LINFlexD_UARTCR_SBUR(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_SBUR_SHIFT)) & LINFlexD_UARTCR_SBUR_MASK)
#define LINFlexD_UARTCR_WLS_MASK                                (0x10000U)
#define LINFlexD_UARTCR_WLS_SHIFT                               (16U)
#define LINFlexD_UARTCR_WLS(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_WLS_SHIFT)) & LINFlexD_UARTCR_WLS_MASK)
#define LINFlexD_UARTCR_TDFL_TFC_MASK                           (0xE000U)
#define LINFlexD_UARTCR_TDFL_TFC_SHIFT                          (13U)
#define LINFlexD_UARTCR_TDFL_TFC(x)                             (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_TDFL_TFC_SHIFT)) & LINFlexD_UARTCR_TDFL_TFC_MASK)
#define LINFlexD_UARTCR_RDFL_RFC_MASK                           (0x1C00U)
#define LINFlexD_UARTCR_RDFL_RFC_SHIFT                          (10U)
#define LINFlexD_UARTCR_RDFL_RFC(x)                             (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_RDFL_RFC_SHIFT)) & LINFlexD_UARTCR_RDFL_RFC_MASK)
#define LINFlexD_UARTCR_RFBM_MASK                               (0x200U)
#define LINFlexD_UARTCR_RFBM_SHIFT                              (9U)
#define LINFlexD_UARTCR_RFBM(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_RFBM_SHIFT)) & LINFlexD_UARTCR_RFBM_MASK)
#define LINFlexD_UARTCR_TFBM_MASK                               (0x100U)
#define LINFlexD_UARTCR_TFBM_SHIFT                              (8U)
#define LINFlexD_UARTCR_TFBM(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_TFBM_SHIFT)) & LINFlexD_UARTCR_TFBM_MASK)
#define LINFlexD_UARTCR_WL1_MASK                                (0x80U)
#define LINFlexD_UARTCR_WL1_SHIFT                               (7U)
#define LINFlexD_UARTCR_WL1(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_WL1_SHIFT)) & LINFlexD_UARTCR_WL1_MASK)
#define LINFlexD_UARTCR_PC1_MASK                                (0x40U)
#define LINFlexD_UARTCR_PC1_SHIFT                               (6U)
#define LINFlexD_UARTCR_PC1(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_PC1_SHIFT)) & LINFlexD_UARTCR_PC1_MASK)
#define LINFlexD_UARTCR_RxEn_MASK                               (0x20U)
#define LINFlexD_UARTCR_RxEn_SHIFT                              (5U)
#define LINFlexD_UARTCR_RxEn(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_RxEn_SHIFT)) & LINFlexD_UARTCR_RxEn_MASK)
#define LINFlexD_UARTCR_TxEn_MASK                               (0x10U)
#define LINFlexD_UARTCR_TxEn_SHIFT                              (4U)
#define LINFlexD_UARTCR_TxEn(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_TxEn_SHIFT)) & LINFlexD_UARTCR_TxEn_MASK)
#define LINFlexD_UARTCR_PC0_MASK                                (0x8U)
#define LINFlexD_UARTCR_PC0_SHIFT                               (3U)
#define LINFlexD_UARTCR_PC0(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_PC0_SHIFT)) & LINFlexD_UARTCR_PC0_MASK)
#define LINFlexD_UARTCR_PCE_MASK                                (0x4U)
#define LINFlexD_UARTCR_PCE_SHIFT                               (2U)
#define LINFlexD_UARTCR_PCE(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_PCE_SHIFT)) & LINFlexD_UARTCR_PCE_MASK)
#define LINFlexD_UARTCR_WL0_MASK                                (0x2U)
#define LINFlexD_UARTCR_WL0_SHIFT                               (1U)
#define LINFlexD_UARTCR_WL0(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_WL0_SHIFT)) & LINFlexD_UARTCR_WL0_MASK)
#define LINFlexD_UARTCR_UART_MASK                               (0x1U)
#define LINFlexD_UARTCR_UART_SHIFT                              (0U)
#define LINFlexD_UARTCR_UART(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCR_UART_SHIFT)) & LINFlexD_UARTCR_UART_MASK)
/* LINFlexD_UARTSR Register */
#define LINFlexD_UARTSR_SZF_MASK                                (0x8000U)
#define LINFlexD_UARTSR_SZF_SHIFT                               (15U)
#define LINFlexD_UARTSR_SZF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_SZF_SHIFT)) & LINFlexD_UARTSR_SZF_MASK)
#define LINFlexD_UARTSR_OCF_MASK                                (0x4000U)
#define LINFlexD_UARTSR_OCF_SHIFT                               (14U)
#define LINFlexD_UARTSR_OCF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_OCF_SHIFT)) & LINFlexD_UARTSR_OCF_MASK)
#define LINFlexD_UARTSR_PE_MASK                                 (0x3C00U)
#define LINFlexD_UARTSR_PE_SHIFT                                (10U)
#define LINFlexD_UARTSR_PE(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_PE_SHIFT)) & LINFlexD_UARTSR_PE_MASK)
#define LINFlexD_UARTSR_RMB_MASK                                (0x200U)
#define LINFlexD_UARTSR_RMB_SHIFT                               (9U)
#define LINFlexD_UARTSR_RMB(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_RMB_SHIFT)) & LINFlexD_UARTSR_RMB_MASK)
#define LINFlexD_UARTSR_FEF_MASK                                (0x100U)
#define LINFlexD_UARTSR_FEF_SHIFT                               (8U)
#define LINFlexD_UARTSR_FEF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_FEF_SHIFT)) & LINFlexD_UARTSR_FEF_MASK)
#define LINFlexD_UARTSR_BOF_MASK                                (0x80U)
#define LINFlexD_UARTSR_BOF_SHIFT                               (7U)
#define LINFlexD_UARTSR_BOF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_BOF_SHIFT)) & LINFlexD_UARTSR_BOF_MASK)
#define LINFlexD_UARTSR_RDI_MASK                                (0x40U)
#define LINFlexD_UARTSR_RDI_SHIFT                               (6U)
#define LINFlexD_UARTSR_RDI(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_RDI_SHIFT)) & LINFlexD_UARTSR_RDI_MASK)
#define LINFlexD_UARTSR_WUF_MASK                                (0x20U)
#define LINFlexD_UARTSR_WUF_SHIFT                               (5U)
#define LINFlexD_UARTSR_WUF(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_WUF_SHIFT)) & LINFlexD_UARTSR_WUF_MASK)
#define LINFlexD_UARTSR_RFNE_MASK                               (0x10U)
#define LINFlexD_UARTSR_RFNE_SHIFT                              (4U)
#define LINFlexD_UARTSR_RFNE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_RFNE_SHIFT)) & LINFlexD_UARTSR_RFNE_MASK)
#define LINFlexD_UARTSR_TO_MASK                                 (0x8U)
#define LINFlexD_UARTSR_TO_SHIFT                                (3U)
#define LINFlexD_UARTSR_TO(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_TO_SHIFT)) & LINFlexD_UARTSR_TO_MASK)
#define LINFlexD_UARTSR_DRF_RFE_MASK                            (0x4U)
#define LINFlexD_UARTSR_DRF_RFE_SHIFT                           (2U)
#define LINFlexD_UARTSR_DRF_RFE(x)                              (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_DRF_RFE_SHIFT)) & LINFlexD_UARTSR_DRF_RFE_MASK)
#define LINFlexD_UARTSR_DTF_TFF_MASK                            (0x2U)
#define LINFlexD_UARTSR_DTF_TFF_SHIFT                           (1U)
#define LINFlexD_UARTSR_DTF_TFF(x)                              (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_DTF_TFF_SHIFT)) & LINFlexD_UARTSR_DTF_TFF_MASK)
#define LINFlexD_UARTSR_NF_MASK                                 (0x1U)
#define LINFlexD_UARTSR_NF_SHIFT                                (0U)
#define LINFlexD_UARTSR_NF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_UARTSR_NF_SHIFT)) & LINFlexD_UARTSR_NF_MASK)
/* LINFlexD_LINTCSR Register */
#define LINFlexD_LINTCSR_MODE_MASK                              (0x400U)
#define LINFlexD_LINTCSR_MODE_SHIFT                             (10U)
#define LINFlexD_LINTCSR_MODE(x)                                (((uint32)(((uint32)(x)) << LINFlexD_LINTCSR_MODE_SHIFT)) & LINFlexD_LINTCSR_MODE_MASK)
#define LINFlexD_LINTCSR_IOT_MASK                               (0x200U)
#define LINFlexD_LINTCSR_IOT_SHIFT                              (9U)
#define LINFlexD_LINTCSR_IOT(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINTCSR_IOT_SHIFT)) & LINFlexD_LINTCSR_IOT_MASK)
#define LINFlexD_LINTCSR_TOCE_MASK                              (0x100U)
#define LINFlexD_LINTCSR_TOCE_SHIFT                             (8U)
#define LINFlexD_LINTCSR_TOCE(x)                                (((uint32)(((uint32)(x)) << LINFlexD_LINTCSR_TOCE_SHIFT)) & LINFlexD_LINTCSR_TOCE_MASK)
#define LINFlexD_LINTCSR_CNT_MASK                               (0xFFU)
#define LINFlexD_LINTCSR_CNT_SHIFT                              (0U)
#define LINFlexD_LINTCSR_CNT(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINTCSR_CNT_SHIFT)) & LINFlexD_LINTCSR_CNT_MASK)
/* LINFlexD_LINOCR Register */
#define LINFlexD_LINOCR_OC2_MASK                                (0xFF00U)
#define LINFlexD_LINOCR_OC2_SHIFT                               (8U)
#define LINFlexD_LINOCR_OC2(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINOCR_OC2_SHIFT)) & LINFlexD_LINOCR_OC2_MASK)
#define LINFlexD_LINOCR_OC1_MASK                                (0xFFU)
#define LINFlexD_LINOCR_OC1_SHIFT                               (0U)
#define LINFlexD_LINOCR_OC1(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_LINOCR_OC1_SHIFT)) & LINFlexD_LINOCR_OC1_MASK)
/* LINFlexD_LINTOCR Register */
#define LINFlexD_LINTOCR_RTO_MASK                               (0xF00U)
#define LINFlexD_LINTOCR_RTO_SHIFT                              (8U)
#define LINFlexD_LINTOCR_RTO(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINTOCR_RTO_SHIFT)) & LINFlexD_LINTOCR_RTO_MASK)
#define LINFlexD_LINTOCR_HTO_MASK                               (0x7FU)
#define LINFlexD_LINTOCR_HTO_SHIFT                              (0U)
#define LINFlexD_LINTOCR_HTO(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINTOCR_HTO_SHIFT)) & LINFlexD_LINTOCR_HTO_MASK)
/* LINFlexD_LINFBRR Register */
#define LINFlexD_LINFBRR_FBR_WIDTH                              (4)
#define LINFlexD_LINFBRR_FBR_MASK                               (0xFU)
#define LINFlexD_LINFBRR_FBR_SHIFT                              (0U)
#define LINFlexD_LINFBRR_FBR(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINFBRR_FBR_SHIFT)) & LINFlexD_LINFBRR_FBR_MASK)
/* LINFlexD_LINIBRR Register */
#define LINFlexD_LINIBRR_IBR_MASK                               (0xFFFFFU)
#define LINFlexD_LINIBRR_IBR_SHIFT                              (0U)
#define LINFlexD_LINIBRR_IBR(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINIBRR_IBR_SHIFT)) & LINFlexD_LINIBRR_IBR_MASK)
/* LINFlexD_LINCFR Register */
#define LINFlexD_LINCFR_CF_MASK                                 (0xFFU)
#define LINFlexD_LINCFR_CF_SHIFT                                (0U)
#define LINFlexD_LINCFR_CF(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_LINCFR_CF_SHIFT)) & LINFlexD_LINCFR_CF_MASK)
/* LINFlexD_LINCR2 Register */
#define LINFlexD_LINCR2_TBDE_MASK                               (0x8000U)
#define LINFlexD_LINCR2_TBDE_SHIFT                              (15U)
#define LINFlexD_LINCR2_TBDE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_TBDE_SHIFT)) & LINFlexD_LINCR2_TBDE_MASK)
#define LINFlexD_LINCR2_IOBE_MASK                               (0x4000U)
#define LINFlexD_LINCR2_IOBE_SHIFT                              (14U)
#define LINFlexD_LINCR2_IOBE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_IOBE_SHIFT)) & LINFlexD_LINCR2_IOBE_MASK)
#define LINFlexD_LINCR2_IOPE_MASK                               (0x2000U)
#define LINFlexD_LINCR2_IOPE_SHIFT                              (13U)
#define LINFlexD_LINCR2_IOPE(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_IOPE_SHIFT)) & LINFlexD_LINCR2_IOPE_MASK)
#define LINFlexD_LINCR2_WURQ_MASK                               (0x1000U)
#define LINFlexD_LINCR2_WURQ_SHIFT                              (12U)
#define LINFlexD_LINCR2_WURQ(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_WURQ_SHIFT)) & LINFlexD_LINCR2_WURQ_MASK)
#define LINFlexD_LINCR2_DDRQ_MASK                               (0x800U)
#define LINFlexD_LINCR2_DDRQ_SHIFT                              (11U)
#define LINFlexD_LINCR2_DDRQ(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_DDRQ_SHIFT)) & LINFlexD_LINCR2_DDRQ_MASK)
#define LINFlexD_LINCR2_DTRQ_MASK                               (0x400U)
#define LINFlexD_LINCR2_DTRQ_SHIFT                              (10U)
#define LINFlexD_LINCR2_DTRQ(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_DTRQ_SHIFT)) & LINFlexD_LINCR2_DTRQ_MASK)
#define LINFlexD_LINCR2_ABRQ_MASK                               (0x200U)
#define LINFlexD_LINCR2_ABRQ_SHIFT                              (9U)
#define LINFlexD_LINCR2_ABRQ(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_ABRQ_SHIFT)) & LINFlexD_LINCR2_ABRQ_MASK)
#define LINFlexD_LINCR2_HTRQ_MASK                               (0x100U)
#define LINFlexD_LINCR2_HTRQ_SHIFT                              (8U)
#define LINFlexD_LINCR2_HTRQ(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_LINCR2_HTRQ_SHIFT)) & LINFlexD_LINCR2_HTRQ_MASK)
/* LINFlexD_BIDR Register */
#define LINFlexD_BIDR_DFL_MASK                                  (0x1C00U)
#define LINFlexD_BIDR_DFL_SHIFT                                 (10U)
#define LINFlexD_BIDR_DFL(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_BIDR_DFL_SHIFT)) & LINFlexD_BIDR_DFL_MASK)
#define LINFlexD_BIDR_DIR_MASK                                  (0x200U)
#define LINFlexD_BIDR_DIR_SHIFT                                 (9U)
#define LINFlexD_BIDR_DIR(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_BIDR_DIR_SHIFT)) & LINFlexD_BIDR_DIR_MASK)
#define LINFlexD_BIDR_CCS_MASK                                  (0x100U)
#define LINFlexD_BIDR_CCS_SHIFT                                 (8U)
#define LINFlexD_BIDR_CCS(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_BIDR_CCS_SHIFT)) & LINFlexD_BIDR_CCS_MASK)
#define LINFlexD_BIDR_ID_MASK                                   (0x3FU)
#define LINFlexD_BIDR_ID_SHIFT                                  (0U)
#define LINFlexD_BIDR_ID(x)                                     (((uint32)(((uint32)(x)) << LINFlexD_BIDR_ID_SHIFT)) & LINFlexD_BIDR_ID_MASK)
/* LINFlexD_DATA_DATA8 Register */
#define LINFlexD_DATA_DATA8_DATA_MASK                                (0xFFU)
#define LINFlexD_DATA_DATA8_DATA_SHIFT                               (0U)
#define LINFlexD_DATA_DATA8_DATA(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_DATA_DATA8_DATA_SHIFT)) & LINFlexD_DATA_DATA8_DATA_MASK)
/* LINFlexD_DATA_DATA16 Register */
#define LINFlexD_DATA_DATA16_DATA_MASK                               (0xFFFFU)
#define LINFlexD_DATA_DATA16_DATA_SHIFT                              (0U)
#define LINFlexD_DATA_DATA16_DATA(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_DATA_DATA16_DATA_SHIFT)) & LINFlexD_DATA_DATA16_DATA_MASK)
/* LINFlexD_DATA_DATA32 Register */
#define LINFlexD_DATA_DATA32_DATA_MASK                               (0xFFFFFFFFU)
#define LINFlexD_DATA_DATA32_DATA_SHIFT                              (0U)
#define LINFlexD_DATA_DATA32_DATA(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_DATA_DATA32_DATA_SHIFT)) & LINFlexD_DATA_DATA32_DATA_MASK)

/* LINFlexD_IFER Register */
#define LINFlexD_IFER_FACT_MASK                                 (0xFFFFU)
#define LINFlexD_IFER_FACT_SHIFT                                (0U)
#define LINFlexD_IFER_FACT(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_IFER_FACT_SHIFT)) & LINFlexD_IFER_FACT_MASK)
/* LINFlexD_IFMI Register */
#define LINFlexD_IFMI_IFMI_MASK                                 (0x1FU)
#define LINFlexD_IFMI_IFMI_SHIFT                                (0U)
#define LINFlexD_IFMI_IFMI(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_IFMI_IFMI_SHIFT)) & LINFlexD_IFMI_IFMI_MASK)
/* LINFlexD_IFMR Register */
#define LINFlexD_IFMR_IFM_MASK                                  (0xFFU)
#define LINFlexD_IFMR_IFM_SHIFT                                 (0U)
#define LINFlexD_IFMR_IFM(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_IFMR_IFM_SHIFT)) & LINFlexD_IFMR_IFM_MASK)
/* LINFlexD_IFCR Register */
#define LINFlexD_IFCR_DFL_MASK                                  (0x1C00U)
#define LINFlexD_IFCR_DFL_SHIFT                                 (10U)
#define LINFlexD_IFCR_DFL(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_IFCR_DFL_SHIFT)) & LINFlexD_IFCR_DFL_MASK)
#define LINFlexD_IFCR_DIR_MASK                                  (0x200U)
#define LINFlexD_IFCR_DIR_SHIFT                                 (9U)
#define LINFlexD_IFCR_DIR(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_IFCR_DIR_SHIFT)) & LINFlexD_IFCR_DIR_MASK)
#define LINFlexD_IFCR_CCS_MASK                                  (0x100U)
#define LINFlexD_IFCR_CCS_SHIFT                                 (8U)
#define LINFlexD_IFCR_CCS(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_IFCR_CCS_SHIFT)) & LINFlexD_IFCR_CCS_MASK)
#define LINFlexD_IFCR_ID_MASK                                   (0x3FU)
#define LINFlexD_IFCR_ID_SHIFT                                  (0U)
#define LINFlexD_IFCR_ID(x)                                     (((uint32)(((uint32)(x)) << LINFlexD_IFCR_ID_SHIFT)) & LINFlexD_IFCR_ID_MASK)
/* LINFlexD_GCR Register */
#define LINFlexD_GCR_SLPRE_MASK                                 (0x80U)
#define LINFlexD_GCR_SLPRE_SHIFT                                (7U)
#define LINFlexD_GCR_SLPRE(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_GCR_SLPRE_SHIFT)) & LINFlexD_GCR_SLPRE_MASK)
#define LINFlexD_GCR_SWPC_MASK                                  (0x40U)
#define LINFlexD_GCR_SWPC_SHIFT                                 (6U)
#define LINFlexD_GCR_SWPC(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_GCR_SWPC_SHIFT)) & LINFlexD_GCR_SWPC_MASK)
#define LINFlexD_GCR_TDFBM_MASK                                 (0x20U)
#define LINFlexD_GCR_TDFBM_SHIFT                                (5U)
#define LINFlexD_GCR_TDFBM(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_GCR_TDFBM_SHIFT)) & LINFlexD_GCR_TDFBM_MASK)
#define LINFlexD_GCR_RDFBM_MASK                                 (0x10U)
#define LINFlexD_GCR_RDFBM_SHIFT                                (4U)
#define LINFlexD_GCR_RDFBM(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_GCR_RDFBM_SHIFT)) & LINFlexD_GCR_RDFBM_MASK)
#define LINFlexD_GCR_TDLIS_MASK                                 (0x8U)
#define LINFlexD_GCR_TDLIS_SHIFT                                (3U)
#define LINFlexD_GCR_TDLIS(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_GCR_TDLIS_SHIFT)) & LINFlexD_GCR_TDLIS_MASK)
#define LINFlexD_GCR_RDLIS_MASK                                 (0x4U)
#define LINFlexD_GCR_RDLIS_SHIFT                                (2U)
#define LINFlexD_GCR_RDLIS(x)                                   (((uint32)(((uint32)(x)) << LINFlexD_GCR_RDLIS_SHIFT)) & LINFlexD_GCR_RDLIS_MASK)
#define LINFlexD_GCR_STOP_MASK                                  (0x2U)
#define LINFlexD_GCR_STOP_SHIFT                                 (1U)
#define LINFlexD_GCR_STOP(x)                                    (((uint32)(((uint32)(x)) << LINFlexD_GCR_STOP_SHIFT)) & LINFlexD_GCR_STOP_MASK)
#define LINFlexD_GCR_SR_MASK                                    (0x1U)
#define LINFlexD_GCR_SR_SHIFT                                   (0U)
#define LINFlexD_GCR_SR(x)                                      (((uint32)(((uint32)(x)) << LINFlexD_GCR_SR_SHIFT)) & LINFlexD_GCR_SR_MASK)
/* LINFlexD_UARTPTO Register */
#define LINFlexD_UARTPTO_PTO_MASK                               (0xFFFU)
#define LINFlexD_UARTPTO_PTO_SHIFT                              (0U)
#define LINFlexD_UARTPTO_PTO(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTPTO_PTO_SHIFT)) & LINFlexD_UARTPTO_PTO_MASK)
/* LINFlexD_UARTCTO Register */
#define LINFlexD_UARTCTO_CTO_MASK                               (0xFFFU)
#define LINFlexD_UARTCTO_CTO_SHIFT                              (0U)
#define LINFlexD_UARTCTO_CTO(x)                                 (((uint32)(((uint32)(x)) << LINFlexD_UARTCTO_CTO_SHIFT)) & LINFlexD_UARTCTO_CTO_MASK)
/* LINFlexD_DMATXE Register */
#define LINFlexD_DMATXE_DTE_MASK                                (0xFFFFU)
#define LINFlexD_DMATXE_DTE_SHIFT                               (0U)
#define LINFlexD_DMATXE_DTE(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_DMATXE_DTE_SHIFT)) & LINFlexD_DMATXE_DTE_MASK)
/* LINFlexD_DMARXE Register */
#define LINFlexD_DMARXE_DRE_MASK                                (0xFFFFU)
#define LINFlexD_DMARXE_DRE_SHIFT                               (0U)
#define LINFlexD_DMARXE_DRE(x)                                  (((uint32)(((uint32)(x)) << LINFlexD_DMARXE_DRE_SHIFT)) & LINFlexD_DMARXE_DRE_MASK)


/**
 * @}
 */ /* end of group LINFlexD_Register_Masks */


/**
 * @}
 */ /* end of group LINFlexD_Peripheral_Access_Layer */

#endif /* PSIP_LINFLEXD_H */

