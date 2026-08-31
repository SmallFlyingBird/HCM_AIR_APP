/**
*   @file    pSIP_Spi.h
*   @version
*
*   @brief   AUTOSAR Spi register map
*   @details Register map for SPI
*
*   @addtogroup SPI_MODULE
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

#ifndef PSIP_SPI_H
#define PSIP_SPI_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              SPI REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */


/** SPI - Size of Registers Arrays */

/* SPI Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 TXCFG;                              /**< Transmit Configuration Register, offset: 0x0004 */
    uint32 CLK;                                /**< Clock Configuration Register, offset: 0x0008 */
    uint32 STS;                                /**< Status Register, offset: 0x000C */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x0010 */
    uint32 MATCH0;                             /**< Data Match Register 0, offset: 0x0014 */
    uint32 MATCH1;                             /**< Data Match Register 1, offset: 0x0018 */
    uint32 TXFIFO;                             /**< TX FIFO Configuration Register, offset: 0x001C */
    uint32 RXFIFO;                             /**< RX FIFO Configuration Register, offset: 0x0020 */
    uint32 DATA;                               /**< Data Register, offset: 0x0024 */

} SPI_Type, *SPI_MemMapPtr;

/** Number of instances of the SPI module. */
#define SPI_INSTANCE_COUNT                        (4u)

/* SPI0  base address */
#define SPI0_BASE_ADDR32                                   (0x4002A000U)
#define SPI0                                               ((volatile SPI_Type *)(SPI0_BASE_ADDR32))
/* SPI1  base address */
#define SPI1_BASE_ADDR32                                   (0x4002B000U)
#define SPI1                                               ((volatile SPI_Type *)(SPI1_BASE_ADDR32))
/* SPI2  base address */
#define SPI2_BASE_ADDR32                                   (0x4002C000U)
#define SPI2                                               ((volatile SPI_Type *)(SPI2_BASE_ADDR32))
/* SPI3  base address */
#define SPI3_BASE_ADDR32                                   (0x4002D000U)
#define SPI3                                               ((volatile SPI_Type *)(SPI3_BASE_ADDR32))

/* Spi module reset via IPC Register Layout Typedef */
typedef struct
{
    uint32 CTRL[SPI_INSTANCE_COUNT];  /**< Control Register, offset: 0x0000 */
} Spi_ResetType;

/* Spi rest via IPC base address */
#define SPI_REST_VIA_IPC_BASE_ADDR32                       (0x4007D0A8U)
#define SPI_REST_VIA_IPC                                   ((volatile Spi_ResetType *)(SPI_REST_VIA_IPC_BASE_ADDR32))
#define IPC_CTRL_SWRESET_MASK                              (0x2U)

/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                                     { SPI0_BASE_ADDR32,  SPI1_BASE_ADDR32,  SPI2_BASE_ADDR32,  SPI3_BASE_ADDR32 }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                                      { SPI0,  SPI1,  SPI2,  SPI3 }

#define SPI_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Control Register */
#define SPI_TXCFG_OFFSET32                                 (0x0004U)                    /**< Offset for Transmit Configuration Register */
#define SPI_CLK_OFFSET32                                   (0x0008U)                    /**< Offset for Clock Configuration Register */
#define SPI_STS_OFFSET32                                   (0x000CU)                    /**< Offset for Status Register */
#define SPI_INTE_OFFSET32                                  (0x0010U)                    /**< Offset for Interrupt Enable Register */
#define SPI_MATCH0_OFFSET32                                (0x0014U)                    /**< Offset for Data Match Register 0 */
#define SPI_MATCH1_OFFSET32                                (0x0018U)                    /**< Offset for Data Match Register 1 */
#define SPI_TXFIFO_OFFSET32                                (0x001CU)                    /**< Offset for TX FIFO Configuration Register */
#define SPI_RXFIFO_OFFSET32                                (0x0020U)                    /**< Offset for RX FIFO Configuration Register */
#define SPI_DATA_OFFSET32                                  (0x0024U)                    /**< Offset for Data Register */


/**
 * @addtogroup SPI Register Mask
 * @{
 */
/* SPI_CTRL Register */
#define SPI_CTRL_TXDMAEN_MASK                              (0x20000000U)
#define SPI_CTRL_TXDMAEN_SHIFT                             (29U)
#define SPI_CTRL_TXDMAEN(x)                                (((uint32)(((uint32)(x)) << SPI_CTRL_TXDMAEN_SHIFT)) & SPI_CTRL_TXDMAEN_MASK)
#define SPI_CTRL_RXDMAEN_MASK                              (0x10000000U)
#define SPI_CTRL_RXDMAEN_SHIFT                             (28U)
#define SPI_CTRL_RXDMAEN(x)                                (((uint32)(((uint32)(x)) << SPI_CTRL_RXDMAEN_SHIFT)) & SPI_CTRL_RXDMAEN_MASK)
#define SPI_CTRL_AUTOPCS_MASK                              (0x2000000U)
#define SPI_CTRL_AUTOPCS_SHIFT                             (25U)
#define SPI_CTRL_AUTOPCS(x)                                (((uint32)(((uint32)(x)) << SPI_CTRL_AUTOPCS_SHIFT)) & SPI_CTRL_AUTOPCS_MASK)
#define SPI_CTRL_SPDEN_MASK                                (0x1000000U)
#define SPI_CTRL_SPDEN_SHIFT                               (24U)
#define SPI_CTRL_SPDEN(x)                                  (((uint32)(((uint32)(x)) << SPI_CTRL_SPDEN_SHIFT)) & SPI_CTRL_SPDEN_MASK)
#define SPI_CTRL_MATCFG_MASK                               (0x70000U)
#define SPI_CTRL_MATCFG_SHIFT                              (16U)
#define SPI_CTRL_MATCFG(x)                                 (((uint32)(((uint32)(x)) << SPI_CTRL_MATCFG_SHIFT)) & SPI_CTRL_MATCFG_MASK)
#define SPI_CTRL_CSDEN_MASK                                (0x8000U)
#define SPI_CTRL_CSDEN_SHIFT                               (15U)
#define SPI_CTRL_CSDEN(x)                                  (((uint32)(((uint32)(x)) << SPI_CTRL_CSDEN_SHIFT)) & SPI_CTRL_CSDEN_MASK)
#define SPI_CTRL_DHZEN_MASK                                (0x4000U)
#define SPI_CTRL_DHZEN_SHIFT                               (14U)
#define SPI_CTRL_DHZEN(x)                                  (((uint32)(((uint32)(x)) << SPI_CTRL_DHZEN_SHIFT)) & SPI_CTRL_DHZEN_MASK)
#define SPI_CTRL_CSPOL_MASK                                (0x3C00U)
#define SPI_CTRL_CSPOL_SHIFT                               (10U)
#define SPI_CTRL_CSPOL(x)                                  (((uint32)(((uint32)(x)) << SPI_CTRL_CSPOL_SHIFT)) & SPI_CTRL_CSPOL_MASK)
#define SPI_CTRL_PINCFG_MASK                               (0x300U)
#define SPI_CTRL_PINCFG_SHIFT                              (8U)
#define SPI_CTRL_PINCFG(x)                                 (((uint32)(((uint32)(x)) << SPI_CTRL_PINCFG_SHIFT)) & SPI_CTRL_PINCFG_MASK)
#define SPI_CTRL_RXMO_MASK                                 (0x80U)
#define SPI_CTRL_RXMO_SHIFT                                (7U)
#define SPI_CTRL_RXMO(x)                                   (((uint32)(((uint32)(x)) << SPI_CTRL_RXMO_SHIFT)) & SPI_CTRL_RXMO_MASK)
#define SPI_CTRL_MODE_MASK                                 (0x4U)
#define SPI_CTRL_MODE_SHIFT                                (2U)
#define SPI_CTRL_MODE(x)                                   (((uint32)(((uint32)(x)) << SPI_CTRL_MODE_SHIFT)) & SPI_CTRL_MODE_MASK)
#define SPI_CTRL_EN_MASK                                   (0x1U)
#define SPI_CTRL_EN_SHIFT                                  (0U)
#define SPI_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << SPI_CTRL_EN_SHIFT)) & SPI_CTRL_EN_MASK)
/* SPI_TXCFG Register */
#define SPI_TXCFG_CPOL_MASK                                (0x80000000U)
#define SPI_TXCFG_CPOL_SHIFT                               (31U)
#define SPI_TXCFG_CPOL(x)                                  (((uint32)(((uint32)(x)) << SPI_TXCFG_CPOL_SHIFT)) & SPI_TXCFG_CPOL_MASK)
#define SPI_TXCFG_CPHA_MASK                                (0x40000000U)
#define SPI_TXCFG_CPHA_SHIFT                               (30U)
#define SPI_TXCFG_CPHA(x)                                  (((uint32)(((uint32)(x)) << SPI_TXCFG_CPHA_SHIFT)) & SPI_TXCFG_CPHA_MASK)
#define SPI_TXCFG_PRESCALE_MASK                            (0x38000000U)
#define SPI_TXCFG_PRESCALE_SHIFT                           (27U)
#define SPI_TXCFG_PRESCALE(x)                              (((uint32)(((uint32)(x)) << SPI_TXCFG_PRESCALE_SHIFT)) & SPI_TXCFG_PRESCALE_MASK)
#define SPI_TXCFG_PCS_MASK                                 (0x3000000U)
#define SPI_TXCFG_PCS_SHIFT                                (24U)
#define SPI_TXCFG_PCS(x)                                   (((uint32)(((uint32)(x)) << SPI_TXCFG_PCS_SHIFT)) & SPI_TXCFG_PCS_MASK)
#define SPI_TXCFG_LSBF_MASK                                (0x800000U)
#define SPI_TXCFG_LSBF_SHIFT                               (23U)
#define SPI_TXCFG_LSBF(x)                                  (((uint32)(((uint32)(x)) << SPI_TXCFG_LSBF_SHIFT)) & SPI_TXCFG_LSBF_MASK)
#define SPI_TXCFG_BSW_MASK                                 (0x400000U)
#define SPI_TXCFG_BSW_SHIFT                                (22U)
#define SPI_TXCFG_BSW(x)                                   (((uint32)(((uint32)(x)) << SPI_TXCFG_BSW_SHIFT)) & SPI_TXCFG_BSW_MASK)
#define SPI_TXCFG_CONT_MASK                                (0x200000U)
#define SPI_TXCFG_CONT_SHIFT                               (21U)
#define SPI_TXCFG_CONT(x)                                  (((uint32)(((uint32)(x)) << SPI_TXCFG_CONT_SHIFT)) & SPI_TXCFG_CONT_MASK)
#define SPI_TXCFG_CONTC_MASK                               (0x100000U)
#define SPI_TXCFG_CONTC_SHIFT                              (20U)
#define SPI_TXCFG_CONTC(x)                                 (((uint32)(((uint32)(x)) << SPI_TXCFG_CONTC_SHIFT)) & SPI_TXCFG_CONTC_MASK)
#define SPI_TXCFG_MSKRX_MASK                               (0x80000U)
#define SPI_TXCFG_MSKRX_SHIFT                              (19U)
#define SPI_TXCFG_MSKRX(x)                                 (((uint32)(((uint32)(x)) << SPI_TXCFG_MSKRX_SHIFT)) & SPI_TXCFG_MSKRX_MASK)
#define SPI_TXCFG_MSKTX_MASK                               (0x40000U)
#define SPI_TXCFG_MSKTX_SHIFT                              (18U)
#define SPI_TXCFG_MSKTX(x)                                 (((uint32)(((uint32)(x)) << SPI_TXCFG_MSKTX_SHIFT)) & SPI_TXCFG_MSKTX_MASK)
#define SPI_TXCFG_WIDTH_MASK                               (0x30000U)
#define SPI_TXCFG_WIDTH_SHIFT                              (16U)
#define SPI_TXCFG_WIDTH(x)                                 (((uint32)(((uint32)(x)) << SPI_TXCFG_WIDTH_SHIFT)) & SPI_TXCFG_WIDTH_MASK)
#define SPI_TXCFG_FRAMESZ_WIDTH                            (12)
#define SPI_TXCFG_FRAMESZ_MASK                             (0xFFFU)
#define SPI_TXCFG_FRAMESZ_SHIFT                            (0U)
#define SPI_TXCFG_FRAMESZ(x)                               (((uint32)(((uint32)(x)) << SPI_TXCFG_FRAMESZ_SHIFT)) & SPI_TXCFG_FRAMESZ_MASK)
/* SPI_CLK Register */
#define SPI_CLK_SCKPCS_WIDTH                               (8)
#define SPI_CLK_SCKPCS_MASK                                (0xFF000000U)
#define SPI_CLK_SCKPCS_SHIFT                               (24U)
#define SPI_CLK_SCKPCS(x)                                  (((uint32)(((uint32)(x)) << SPI_CLK_SCKPCS_SHIFT)) & SPI_CLK_SCKPCS_MASK)
#define SPI_CLK_PCSSCK_WIDTH                               (8)
#define SPI_CLK_PCSSCK_MASK                                (0xFF0000U)
#define SPI_CLK_PCSSCK_SHIFT                               (16U)
#define SPI_CLK_PCSSCK(x)                                  (((uint32)(((uint32)(x)) << SPI_CLK_PCSSCK_SHIFT)) & SPI_CLK_PCSSCK_MASK)
#define SPI_CLK_FMDLY_WIDTH                                (8)
#define SPI_CLK_FMDLY_MASK                                 (0xFF00U)
#define SPI_CLK_FMDLY_SHIFT                                (8U)
#define SPI_CLK_FMDLY(x)                                   (((uint32)(((uint32)(x)) << SPI_CLK_FMDLY_SHIFT)) & SPI_CLK_FMDLY_MASK)
#define SPI_CLK_DIV_WIDTH                                  (8)
#define SPI_CLK_DIV_MASK                                   (0xFFU)
#define SPI_CLK_DIV_SHIFT                                  (0U)
#define SPI_CLK_DIV(x)                                     (((uint32)(((uint32)(x)) << SPI_CLK_DIV_SHIFT)) & SPI_CLK_DIV_MASK)
/* SPI_STS Register */
#define SPI_STS_BUSY_MASK                                  (0x40000U)
#define SPI_STS_BUSY_SHIFT                                 (18U)
#define SPI_STS_BUSY(x)                                    (((uint32)(((uint32)(x)) << SPI_STS_BUSY_SHIFT)) & SPI_STS_BUSY_MASK)
#define SPI_STS_RXEPT_MASK                                 (0x20000U)
#define SPI_STS_RXEPT_SHIFT                                (17U)
#define SPI_STS_RXEPT(x)                                   (((uint32)(((uint32)(x)) << SPI_STS_RXEPT_SHIFT)) & SPI_STS_RXEPT_MASK)
#define SPI_STS_SOF_MASK                                   (0x10000U)
#define SPI_STS_SOF_SHIFT                                  (16U)
#define SPI_STS_SOF(x)                                     (((uint32)(((uint32)(x)) << SPI_STS_SOF_SHIFT)) & SPI_STS_SOF_MASK)
#define SPI_STS_MATIF_MASK                                 (0x80U)
#define SPI_STS_MATIF_SHIFT                                (7U)
#define SPI_STS_MATIF(x)                                   (((uint32)(((uint32)(x)) << SPI_STS_MATIF_SHIFT)) & SPI_STS_MATIF_MASK)
#define SPI_STS_RXOVIF_MASK                                (0x40U)
#define SPI_STS_RXOVIF_SHIFT                               (6U)
#define SPI_STS_RXOVIF(x)                                  (((uint32)(((uint32)(x)) << SPI_STS_RXOVIF_SHIFT)) & SPI_STS_RXOVIF_MASK)
#define SPI_STS_TXUNIF_MASK                                (0x20U)
#define SPI_STS_TXUNIF_SHIFT                               (5U)
#define SPI_STS_TXUNIF(x)                                  (((uint32)(((uint32)(x)) << SPI_STS_TXUNIF_SHIFT)) & SPI_STS_TXUNIF_MASK)
#define SPI_STS_TCIF_MASK                                  (0x10U)
#define SPI_STS_TCIF_SHIFT                                 (4U)
#define SPI_STS_TCIF(x)                                    (((uint32)(((uint32)(x)) << SPI_STS_TCIF_SHIFT)) & SPI_STS_TCIF_MASK)
#define SPI_STS_FCIF_MASK                                  (0x8U)
#define SPI_STS_FCIF_SHIFT                                 (3U)
#define SPI_STS_FCIF(x)                                    (((uint32)(((uint32)(x)) << SPI_STS_FCIF_SHIFT)) & SPI_STS_FCIF_MASK)
#define SPI_STS_TXIF_MASK                                  (0x2U)
#define SPI_STS_TXIF_SHIFT                                 (1U)
#define SPI_STS_TXIF(x)                                    (((uint32)(((uint32)(x)) << SPI_STS_TXIF_SHIFT)) & SPI_STS_TXIF_MASK)
#define SPI_STS_RXIF_MASK                                  (0x1U)
#define SPI_STS_RXIF_SHIFT                                 (0U)
#define SPI_STS_RXIF(x)                                    (((uint32)(((uint32)(x)) << SPI_STS_RXIF_SHIFT)) & SPI_STS_RXIF_MASK)
/* SPI_INTE Register */
#define SPI_INTE_MATIE_MASK                                (0x80U)
#define SPI_INTE_MATIE_SHIFT                               (7U)
#define SPI_INTE_MATIE(x)                                  (((uint32)(((uint32)(x)) << SPI_INTE_MATIE_SHIFT)) & SPI_INTE_MATIE_MASK)
#define SPI_INTE_RXOVIE_MASK                               (0x40U)
#define SPI_INTE_RXOVIE_SHIFT                              (6U)
#define SPI_INTE_RXOVIE(x)                                 (((uint32)(((uint32)(x)) << SPI_INTE_RXOVIE_SHIFT)) & SPI_INTE_RXOVIE_MASK)
#define SPI_INTE_TXUNIE_MASK                               (0x20U)
#define SPI_INTE_TXUNIE_SHIFT                              (5U)
#define SPI_INTE_TXUNIE(x)                                 (((uint32)(((uint32)(x)) << SPI_INTE_TXUNIE_SHIFT)) & SPI_INTE_TXUNIE_MASK)
#define SPI_INTE_TCIE_MASK                                 (0x10U)
#define SPI_INTE_TCIE_SHIFT                                (4U)
#define SPI_INTE_TCIE(x)                                   (((uint32)(((uint32)(x)) << SPI_INTE_TCIE_SHIFT)) & SPI_INTE_TCIE_MASK)
#define SPI_INTE_FCIE_MASK                                 (0x8U)
#define SPI_INTE_FCIE_SHIFT                                (3U)
#define SPI_INTE_FCIE(x)                                   (((uint32)(((uint32)(x)) << SPI_INTE_FCIE_SHIFT)) & SPI_INTE_FCIE_MASK)
#define SPI_INTE_TXIE_MASK                                 (0x2U)
#define SPI_INTE_TXIE_SHIFT                                (1U)
#define SPI_INTE_TXIE(x)                                   (((uint32)(((uint32)(x)) << SPI_INTE_TXIE_SHIFT)) & SPI_INTE_TXIE_MASK)
#define SPI_INTE_RXIE_MASK                                 (0x1U)
#define SPI_INTE_RXIE_SHIFT                                (0U)
#define SPI_INTE_RXIE(x)                                   (((uint32)(((uint32)(x)) << SPI_INTE_RXIE_SHIFT)) & SPI_INTE_RXIE_MASK)
/* SPI_MATCH0 Register */
#define SPI_MATCH0_MATCH0_MASK                             (0xFFFFFFFFU)
#define SPI_MATCH0_MATCH0_SHIFT                            (0U)
#define SPI_MATCH0_MATCH0(x)                               (((uint32)(((uint32)(x)) << SPI_MATCH0_MATCH0_SHIFT)) & SPI_MATCH0_MATCH0_MASK)
/* SPI_MATCH1 Register */
#define SPI_MATCH1_MATCH1_MASK                             (0xFFFFFFFFU)
#define SPI_MATCH1_MATCH1_SHIFT                            (0U)
#define SPI_MATCH1_MATCH1(x)                               (((uint32)(((uint32)(x)) << SPI_MATCH1_MATCH1_SHIFT)) & SPI_MATCH1_MATCH1_MASK)
/* SPI_TXFIFO Register */
#define SPI_TXFIFO_SIZE_MASK                               (0x1F000000U)
#define SPI_TXFIFO_SIZE_SHIFT                              (24U)
#define SPI_TXFIFO_SIZE(x)                                 (((uint32)(((uint32)(x)) << SPI_TXFIFO_SIZE_SHIFT)) & SPI_TXFIFO_SIZE_MASK)
#define SPI_TXFIFO_RESET_MASK                              (0x8000U)
#define SPI_TXFIFO_RESET_SHIFT                             (15U)
#define SPI_TXFIFO_RESET(x)                                (((uint32)(((uint32)(x)) << SPI_TXFIFO_RESET_SHIFT)) & SPI_TXFIFO_RESET_MASK)
#define SPI_TXFIFO_COUNT_MASK                              (0x1F00U)
#define SPI_TXFIFO_COUNT_SHIFT                             (8U)
#define SPI_TXFIFO_COUNT(x)                                (((uint32)(((uint32)(x)) << SPI_TXFIFO_COUNT_SHIFT)) & SPI_TXFIFO_COUNT_MASK)
#define SPI_TXFIFO_WATER_MASK                              (0xFU)
#define SPI_TXFIFO_WATER_SHIFT                             (0U)
#define SPI_TXFIFO_WATER(x)                                (((uint32)(((uint32)(x)) << SPI_TXFIFO_WATER_SHIFT)) & SPI_TXFIFO_WATER_MASK)
/* SPI_RXFIFO Register */
#define SPI_RXFIFO_SIZE_MASK                               (0x1F000000U)
#define SPI_RXFIFO_SIZE_SHIFT                              (24U)
#define SPI_RXFIFO_SIZE(x)                                 (((uint32)(((uint32)(x)) << SPI_RXFIFO_SIZE_SHIFT)) & SPI_RXFIFO_SIZE_MASK)
#define SPI_RXFIFO_RESET_MASK                              (0x8000U)
#define SPI_RXFIFO_RESET_SHIFT                             (15U)
#define SPI_RXFIFO_RESET(x)                                (((uint32)(((uint32)(x)) << SPI_RXFIFO_RESET_SHIFT)) & SPI_RXFIFO_RESET_MASK)
#define SPI_RXFIFO_COUNT_MASK                              (0x1F00U)
#define SPI_RXFIFO_COUNT_SHIFT                             (8U)
#define SPI_RXFIFO_COUNT(x)                                (((uint32)(((uint32)(x)) << SPI_RXFIFO_COUNT_SHIFT)) & SPI_RXFIFO_COUNT_MASK)
#define SPI_RXFIFO_WATER_MASK                              (0xFU)
#define SPI_RXFIFO_WATER_SHIFT                             (0U)
#define SPI_RXFIFO_WATER(x)                                (((uint32)(((uint32)(x)) << SPI_RXFIFO_WATER_SHIFT)) & SPI_RXFIFO_WATER_MASK)
/* SPI_DATA Register */
#define SPI_DATA_DATA_MASK                                 (0xFFFFFFFFU)
#define SPI_DATA_DATA_SHIFT                                (0U)
#define SPI_DATA_DATA(x)                                   (((uint32)(((uint32)(x)) << SPI_DATA_DATA_SHIFT)) & SPI_DATA_DATA_MASK)


/**
 * @}
 */ /* end of group SPI_Register_Masks */


/**
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */

#endif /* PSIP_SPI_H */

