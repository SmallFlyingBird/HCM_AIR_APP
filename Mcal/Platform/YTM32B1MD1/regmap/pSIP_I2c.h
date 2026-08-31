/**
*   @file    pSIP_I2c.h
*   @version
*
*   @brief   AUTOSAR I2c register map
*   @details Register map for I2C
*
*   @addtogroup I2C_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : I2c
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

#ifndef PSIP_I2C_H
#define PSIP_I2C_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              I2C REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 * @{
 */


/** I2C - Size of Registers Arrays */

/* I2C Register Layout Typedef */
typedef struct
{
    uint32 MCTRL;                              /**< Master Control Register, offset: 0x0000 */
    uint32 MCLKCFG;                            /**< Master Clock Configuration Register, offset: 0x0004 */
    uint32 MFLTCFG;                            /**< Master Clock Filter Configuration and Divider Register, offset: 0x0008 */
    uint32 MSTS;                               /**< Master Status Register, offset: 0x000C */
    uint32 MIE;                                /**< Master Interrupt Register, offset: 0x0010 */
    uint32 TXFIFO;                             /**< Master TX FIFO Control and Status Register, offset: 0x0014 */
    uint32 RXFIFO;                             /**< Master RX FIFO Control and Status Register, offset: 0x0018 */
    uint32 MDATA;                              /**< Master Data Register, offset: 0x001C */
    uint32 MATCH;                              /**< Data Match Register, offset: 0x0020 */
    uint32 TOCFG;                              /**< Timeout Configure Register, offset: 0x0024 */
    uint32 HSCLK;                              /**< Master Clock Configuration Under High Speed Mode Register, offset: 0x0028 */
    uint32 RESERVED0[53];                      /**< RESERVED0, offset: 0x002C */
    uint32 SCTRL;                              /**< Slave Control Register, offset: 0x0100 */
    uint32 SCLKCFG;                            /**< Slave Clock Configuration Register, offset: 0x0104 */
    uint32 SFLTCFG;                            /**< Slave Filter Configuration Register, offset: 0x0108 */
    uint32 SSTS;                               /**< Slave Status Register, offset: 0x010C */
    uint32 SIE;                                /**< Slave Interrupt Enable Register, offset: 0x0110 */
    uint32 SDATA;                              /**< Slave Data Register, offset: 0x0114 */
    uint32 SACK;                               /**< Slave Ack Register, offset: 0x0118 */
    uint32 SADDR;                              /**< Slave Address Match Configuration Register, offset: 0x011C */
    uint32 SRADDR;                             /**< Slave Received Address Register, offset: 0x0120 */

} I2C_Type, *I2C_MemMapPtr;

/** Number of instances of the I2C module. */
#define I2C_INSTANCE_COUNT                        (2u)

/* I2c module reset via IPC Register Layout Typedef */
typedef struct
{
    uint32 CTRL[I2C_INSTANCE_COUNT];  /**< Control Register, offset: 0x0000 */
} CddI2c_ResetType;

/* Spi rest via IPC base address */
#define I2C_REST_VIA_IPC_BASE_ADDR32                       (0x4007D08CU)
#define I2C_REST_VIA_IPC                                   ((volatile CddI2c_ResetType *)(I2C_REST_VIA_IPC_BASE_ADDR32))
#define I2C_IPC_CTRL_SWRESET_MASK                          (0x2U)

/* I2C0  base address */
#define I2C0_BASE_ADDR32                                   (0x40023000U)
#define I2C0                                               ((volatile I2C_Type *)(I2C0_BASE_ADDR32))
/* I2C1  base address */
#define I2C1_BASE_ADDR32                                   (0x40024000U)
#define I2C1                                               ((volatile I2C_Type *)(I2C1_BASE_ADDR32))

/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                                     { I2C0_BASE_ADDR32,  I2C1_BASE_ADDR32 }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                                      { I2C0,  I2C1 }

#define I2C_MCTRL_OFFSET32                                 (0x0000U)                    /**< Offset for Master Control Register */
#define I2C_MCLKCFG_OFFSET32                               (0x0004U)                    /**< Offset for Master Clock Configuration Register */
#define I2C_MFLTCFG_OFFSET32                               (0x0008U)                    /**< Offset for Master Clock Filter Configuration and Divider Register */
#define I2C_MSTS_OFFSET32                                  (0x000CU)                    /**< Offset for Master Status Register */
#define I2C_MIE_OFFSET32                                   (0x0010U)                    /**< Offset for Master Interrupt Register */
#define I2C_TXFIFO_OFFSET32                                (0x0014U)                    /**< Offset for Master TX FIFO Control and Status Register */
#define I2C_RXFIFO_OFFSET32                                (0x0018U)                    /**< Offset for Master RX FIFO Control and Status Register */
#define I2C_MDATA_OFFSET32                                 (0x001CU)                    /**< Offset for Master Data Register */
#define I2C_MATCH_OFFSET32                                 (0x0020U)                    /**< Offset for Data Match Register */
#define I2C_TOCFG_OFFSET32                                 (0x0024U)                    /**< Offset for Timeout Configure Register */
#define I2C_HSCLK_OFFSET32                                 (0x0028U)                    /**< Offset for Master Clock Configuration Under High Speed Mode Register */
#define I2C_SCTRL_OFFSET32                                 (0x0100U)                    /**< Offset for Slave Control Register */
#define I2C_SCLKCFG_OFFSET32                               (0x0104U)                    /**< Offset for Slave Clock Configuration Register */
#define I2C_SFLTCFG_OFFSET32                               (0x0108U)                    /**< Offset for Slave Filter Configuration Register */
#define I2C_SSTS_OFFSET32                                  (0x010CU)                    /**< Offset for Slave Status Register */
#define I2C_SIE_OFFSET32                                   (0x0110U)                    /**< Offset for Slave Interrupt Enable Register */
#define I2C_SDATA_OFFSET32                                 (0x0114U)                    /**< Offset for Slave Data Register */
#define I2C_SACK_OFFSET32                                  (0x0118U)                    /**< Offset for Slave Ack Register */
#define I2C_SADDR_OFFSET32                                 (0x011CU)                    /**< Offset for Slave Address Match Configuration Register */
#define I2C_SRADDR_OFFSET32                                (0x0120U)                    /**< Offset for Slave Received Address Register */


/**
 * @addtogroup I2C Register Mask
 * @{
 */
/* I2C_MCTRL Register */
#define I2C_MCTRL_TXDMAEN_MASK                             (0x20000000U)
#define I2C_MCTRL_TXDMAEN_SHIFT                            (29U)
#define I2C_MCTRL_TXDMAEN(x)                               (((uint32)(((uint32)(x)) << I2C_MCTRL_TXDMAEN_SHIFT)) & I2C_MCTRL_TXDMAEN_MASK)
#define I2C_MCTRL_RXDMAEN_MASK                             (0x10000000U)
#define I2C_MCTRL_RXDMAEN_SHIFT                            (28U)
#define I2C_MCTRL_RXDMAEN(x)                               (((uint32)(((uint32)(x)) << I2C_MCTRL_RXDMAEN_SHIFT)) & I2C_MCTRL_RXDMAEN_MASK)
#define I2C_MCTRL_RDMO_MASK                                (0x2000000U)
#define I2C_MCTRL_RDMO_SHIFT                               (25U)
#define I2C_MCTRL_RDMO(x)                                  (((uint32)(((uint32)(x)) << I2C_MCTRL_RDMO_SHIFT)) & I2C_MCTRL_RDMO_MASK)
#define I2C_MCTRL_MATCFG_MASK                              (0x70000U)
#define I2C_MCTRL_MATCFG_SHIFT                             (16U)
#define I2C_MCTRL_MATCFG(x)                                (((uint32)(((uint32)(x)) << I2C_MCTRL_MATCFG_SHIFT)) & I2C_MCTRL_MATCFG_MASK)
#define I2C_MCTRL_IGACK_MASK                               (0x8000U)
#define I2C_MCTRL_IGACK_SHIFT                              (15U)
#define I2C_MCTRL_IGACK(x)                                 (((uint32)(((uint32)(x)) << I2C_MCTRL_IGACK_SHIFT)) & I2C_MCTRL_IGACK_MASK)
#define I2C_MCTRL_ASTOP_MASK                               (0x4000U)
#define I2C_MCTRL_ASTOP_SHIFT                              (14U)
#define I2C_MCTRL_ASTOP(x)                                 (((uint32)(((uint32)(x)) << I2C_MCTRL_ASTOP_SHIFT)) & I2C_MCTRL_ASTOP_MASK)
#define I2C_MCTRL_HSMOD_MASK                               (0x200U)
#define I2C_MCTRL_HSMOD_SHIFT                              (9U)
#define I2C_MCTRL_HSMOD(x)                                 (((uint32)(((uint32)(x)) << I2C_MCTRL_HSMOD_SHIFT)) & I2C_MCTRL_HSMOD_MASK)
#define I2C_MCTRL_PPEN_MASK                                (0x100U)
#define I2C_MCTRL_PPEN_SHIFT                               (8U)
#define I2C_MCTRL_PPEN(x)                                  (((uint32)(((uint32)(x)) << I2C_MCTRL_PPEN_SHIFT)) & I2C_MCTRL_PPEN_MASK)
#define I2C_MCTRL_MEN_MASK                                 (0x1U)
#define I2C_MCTRL_MEN_SHIFT                                (0U)
#define I2C_MCTRL_MEN(x)                                   (((uint32)(((uint32)(x)) << I2C_MCTRL_MEN_SHIFT)) & I2C_MCTRL_MEN_MASK)
/* I2C_MCLKCFG Register */
#define I2C_MCLKCFG_HIGH_WIDTH                             (6)
#define I2C_MCLKCFG_HIGH_MASK                              (0x3F000000U)
#define I2C_MCLKCFG_HIGH_SHIFT                             (24U)
#define I2C_MCLKCFG_HIGH(x)                                (((uint32)(((uint32)(x)) << I2C_MCLKCFG_HIGH_SHIFT)) & I2C_MCLKCFG_HIGH_MASK)
#define I2C_MCLKCFG_LOW_WIDTH                              (6)
#define I2C_MCLKCFG_LOW_MASK                               (0x3F0000U)
#define I2C_MCLKCFG_LOW_SHIFT                              (16U)
#define I2C_MCLKCFG_LOW(x)                                 (((uint32)(((uint32)(x)) << I2C_MCLKCFG_LOW_SHIFT)) & I2C_MCLKCFG_LOW_MASK)
#define I2C_MCLKCFG_VALID_WIDTH                            (6)
#define I2C_MCLKCFG_VALID_MASK                             (0x3F00U)
#define I2C_MCLKCFG_VALID_SHIFT                            (8U)
#define I2C_MCLKCFG_VALID(x)                               (((uint32)(((uint32)(x)) << I2C_MCLKCFG_VALID_SHIFT)) & I2C_MCLKCFG_VALID_MASK)
#define I2C_MCLKCFG_STHD_WIDTH                             (6)
#define I2C_MCLKCFG_STHD_MASK                              (0x3FU)
#define I2C_MCLKCFG_STHD_SHIFT                             (0U)
#define I2C_MCLKCFG_STHD(x)                                (((uint32)(((uint32)(x)) << I2C_MCLKCFG_STHD_SHIFT)) & I2C_MCLKCFG_STHD_MASK)
/* I2C_MFLTCFG Register */
#define I2C_MFLTCFG_FLTSCL_WIDTH                           (4)
#define I2C_MFLTCFG_FLTSCL_MASK                            (0xF000000U)
#define I2C_MFLTCFG_FLTSCL_SHIFT                           (24U)
#define I2C_MFLTCFG_FLTSCL(x)                              (((uint32)(((uint32)(x)) << I2C_MFLTCFG_FLTSCL_SHIFT)) & I2C_MFLTCFG_FLTSCL_MASK)
#define I2C_MFLTCFG_FLTSDA_WIDTH                           (4)
#define I2C_MFLTCFG_FLTSDA_MASK                            (0xF0000U)
#define I2C_MFLTCFG_FLTSDA_SHIFT                           (16U)
#define I2C_MFLTCFG_FLTSDA(x)                              (((uint32)(((uint32)(x)) << I2C_MFLTCFG_FLTSDA_SHIFT)) & I2C_MFLTCFG_FLTSDA_MASK)
#define I2C_MFLTCFG_DIV_WIDTH                              (3)
#define I2C_MFLTCFG_DIV_MASK                               (0x7U)
#define I2C_MFLTCFG_DIV_SHIFT                              (0U)
#define I2C_MFLTCFG_DIV(x)                                 (((uint32)(((uint32)(x)) << I2C_MFLTCFG_DIV_SHIFT)) & I2C_MFLTCFG_DIV_MASK)
/* I2C_MSTS Register */
#define I2C_MSTS_ACTIVE_MASK                               (0x20000U)
#define I2C_MSTS_ACTIVE_SHIFT                              (17U)
#define I2C_MSTS_ACTIVE(x)                                 (((uint32)(((uint32)(x)) << I2C_MSTS_ACTIVE_SHIFT)) & I2C_MSTS_ACTIVE_MASK)
#define I2C_MSTS_BUSY_MASK                                 (0x10000U)
#define I2C_MSTS_BUSY_SHIFT                                (16U)
#define I2C_MSTS_BUSY(x)                                   (((uint32)(((uint32)(x)) << I2C_MSTS_BUSY_SHIFT)) & I2C_MSTS_BUSY_MASK)
#define I2C_MSTS_OPERRIF_MASK                              (0x800U)
#define I2C_MSTS_OPERRIF_SHIFT                             (11U)
#define I2C_MSTS_OPERRIF(x)                                (((uint32)(((uint32)(x)) << I2C_MSTS_OPERRIF_SHIFT)) & I2C_MSTS_OPERRIF_MASK)
#define I2C_MSTS_MATIF_MASK                                (0x200U)
#define I2C_MSTS_MATIF_SHIFT                               (9U)
#define I2C_MSTS_MATIF(x)                                  (((uint32)(((uint32)(x)) << I2C_MSTS_MATIF_SHIFT)) & I2C_MSTS_MATIF_MASK)
#define I2C_MSTS_TOIF_MASK                                 (0x100U)
#define I2C_MSTS_TOIF_SHIFT                                (8U)
#define I2C_MSTS_TOIF(x)                                   (((uint32)(((uint32)(x)) << I2C_MSTS_TOIF_SHIFT)) & I2C_MSTS_TOIF_MASK)
#define I2C_MSTS_ARBIF_MASK                                (0x80U)
#define I2C_MSTS_ARBIF_SHIFT                               (7U)
#define I2C_MSTS_ARBIF(x)                                  (((uint32)(((uint32)(x)) << I2C_MSTS_ARBIF_SHIFT)) & I2C_MSTS_ARBIF_MASK)
#define I2C_MSTS_NACKIF_MASK                               (0x40U)
#define I2C_MSTS_NACKIF_SHIFT                              (6U)
#define I2C_MSTS_NACKIF(x)                                 (((uint32)(((uint32)(x)) << I2C_MSTS_NACKIF_SHIFT)) & I2C_MSTS_NACKIF_MASK)
#define I2C_MSTS_STOPIF_MASK                               (0x10U)
#define I2C_MSTS_STOPIF_SHIFT                              (4U)
#define I2C_MSTS_STOPIF(x)                                 (((uint32)(((uint32)(x)) << I2C_MSTS_STOPIF_SHIFT)) & I2C_MSTS_STOPIF_MASK)
#define I2C_MSTS_TXIF_MASK                                 (0x2U)
#define I2C_MSTS_TXIF_SHIFT                                (1U)
#define I2C_MSTS_TXIF(x)                                   (((uint32)(((uint32)(x)) << I2C_MSTS_TXIF_SHIFT)) & I2C_MSTS_TXIF_MASK)
#define I2C_MSTS_RXIF_MASK                                 (0x1U)
#define I2C_MSTS_RXIF_SHIFT                                (0U)
#define I2C_MSTS_RXIF(x)                                   (((uint32)(((uint32)(x)) << I2C_MSTS_RXIF_SHIFT)) & I2C_MSTS_RXIF_MASK)
/* I2C_MIE Register */
#define I2C_MIE_OPERRIE_MASK                               (0x800U)
#define I2C_MIE_OPERRIE_SHIFT                              (11U)
#define I2C_MIE_OPERRIE(x)                                 (((uint32)(((uint32)(x)) << I2C_MIE_OPERRIE_SHIFT)) & I2C_MIE_OPERRIE_MASK)
#define I2C_MIE_MATIE_MASK                                 (0x200U)
#define I2C_MIE_MATIE_SHIFT                                (9U)
#define I2C_MIE_MATIE(x)                                   (((uint32)(((uint32)(x)) << I2C_MIE_MATIE_SHIFT)) & I2C_MIE_MATIE_MASK)
#define I2C_MIE_TOIE_MASK                                  (0x100U)
#define I2C_MIE_TOIE_SHIFT                                 (8U)
#define I2C_MIE_TOIE(x)                                    (((uint32)(((uint32)(x)) << I2C_MIE_TOIE_SHIFT)) & I2C_MIE_TOIE_MASK)
#define I2C_MIE_ARBIE_MASK                                 (0x80U)
#define I2C_MIE_ARBIE_SHIFT                                (7U)
#define I2C_MIE_ARBIE(x)                                   (((uint32)(((uint32)(x)) << I2C_MIE_ARBIE_SHIFT)) & I2C_MIE_ARBIE_MASK)
#define I2C_MIE_NACKIE_MASK                                (0x40U)
#define I2C_MIE_NACKIE_SHIFT                               (6U)
#define I2C_MIE_NACKIE(x)                                  (((uint32)(((uint32)(x)) << I2C_MIE_NACKIE_SHIFT)) & I2C_MIE_NACKIE_MASK)
#define I2C_MIE_STOPIE_MASK                                (0x10U)
#define I2C_MIE_STOPIE_SHIFT                               (4U)
#define I2C_MIE_STOPIE(x)                                  (((uint32)(((uint32)(x)) << I2C_MIE_STOPIE_SHIFT)) & I2C_MIE_STOPIE_MASK)
#define I2C_MIE_TXIE_MASK                                  (0x2U)
#define I2C_MIE_TXIE_SHIFT                                 (1U)
#define I2C_MIE_TXIE(x)                                    (((uint32)(((uint32)(x)) << I2C_MIE_TXIE_SHIFT)) & I2C_MIE_TXIE_MASK)
#define I2C_MIE_RXIE_MASK                                  (0x1U)
#define I2C_MIE_RXIE_SHIFT                                 (0U)
#define I2C_MIE_RXIE(x)                                    (((uint32)(((uint32)(x)) << I2C_MIE_RXIE_SHIFT)) & I2C_MIE_RXIE_MASK)
/* I2C_TXFIFO Register */
#define I2C_TXFIFO_SIZE_MASK                               (0x7000000U)
#define I2C_TXFIFO_SIZE_SHIFT                              (24U)
#define I2C_TXFIFO_SIZE(x)                                 (((uint32)(((uint32)(x)) << I2C_TXFIFO_SIZE_SHIFT)) & I2C_TXFIFO_SIZE_MASK)
#define I2C_TXFIFO_RESET_MASK                              (0x8000U)
#define I2C_TXFIFO_RESET_SHIFT                             (15U)
#define I2C_TXFIFO_RESET(x)                                (((uint32)(((uint32)(x)) << I2C_TXFIFO_RESET_SHIFT)) & I2C_TXFIFO_RESET_MASK)
#define I2C_TXFIFO_COUNT_MASK                              (0x700U)
#define I2C_TXFIFO_COUNT_SHIFT                             (8U)
#define I2C_TXFIFO_COUNT(x)                                (((uint32)(((uint32)(x)) << I2C_TXFIFO_COUNT_SHIFT)) & I2C_TXFIFO_COUNT_MASK)
#define I2C_TXFIFO_WATER_MASK                              (0x3U)
#define I2C_TXFIFO_WATER_SHIFT                             (0U)
#define I2C_TXFIFO_WATER(x)                                (((uint32)(((uint32)(x)) << I2C_TXFIFO_WATER_SHIFT)) & I2C_TXFIFO_WATER_MASK)
/* I2C_RXFIFO Register */
#define I2C_RXFIFO_SIZE_MASK                               (0x7000000U)
#define I2C_RXFIFO_SIZE_SHIFT                              (24U)
#define I2C_RXFIFO_SIZE(x)                                 (((uint32)(((uint32)(x)) << I2C_RXFIFO_SIZE_SHIFT)) & I2C_RXFIFO_SIZE_MASK)
#define I2C_RXFIFO_RESET_MASK                              (0x8000U)
#define I2C_RXFIFO_RESET_SHIFT                             (15U)
#define I2C_RXFIFO_RESET(x)                                (((uint32)(((uint32)(x)) << I2C_RXFIFO_RESET_SHIFT)) & I2C_RXFIFO_RESET_MASK)
#define I2C_RXFIFO_COUNT_MASK                              (0x700U)
#define I2C_RXFIFO_COUNT_SHIFT                             (8U)
#define I2C_RXFIFO_COUNT(x)                                (((uint32)(((uint32)(x)) << I2C_RXFIFO_COUNT_SHIFT)) & I2C_RXFIFO_COUNT_MASK)
#define I2C_RXFIFO_WATER_MASK                              (0x7U)
#define I2C_RXFIFO_WATER_SHIFT                             (0U)
#define I2C_RXFIFO_WATER(x)                                (((uint32)(((uint32)(x)) << I2C_RXFIFO_WATER_SHIFT)) & I2C_RXFIFO_WATER_MASK)
/* I2C_MDATA Register */
#define I2C_MDATA_EMPTY_MASK                               (0x10000U)
#define I2C_MDATA_EMPTY_SHIFT                              (16U)
#define I2C_MDATA_EMPTY(x)                                 (((uint32)(((uint32)(x)) << I2C_MDATA_EMPTY_SHIFT)) & I2C_MDATA_EMPTY_MASK)
#define I2C_MDATA_HS_MASK                                  (0x800U)
#define I2C_MDATA_HS_SHIFT                                 (11U)
#define I2C_MDATA_HS(x)                                    (((uint32)(((uint32)(x)) << I2C_MDATA_HS_SHIFT)) & I2C_MDATA_HS_MASK)
#define I2C_MDATA_REC_MASK                                 (0x400U)
#define I2C_MDATA_REC_SHIFT                                (10U)
#define I2C_MDATA_REC(x)                                   (((uint32)(((uint32)(x)) << I2C_MDATA_REC_SHIFT)) & I2C_MDATA_REC_MASK)
#define I2C_MDATA_STOP_MASK                                (0x200U)
#define I2C_MDATA_STOP_SHIFT                               (9U)
#define I2C_MDATA_STOP(x)                                  (((uint32)(((uint32)(x)) << I2C_MDATA_STOP_SHIFT)) & I2C_MDATA_STOP_MASK)
#define I2C_MDATA_START_MASK                               (0x100U)
#define I2C_MDATA_START_SHIFT                              (8U)
#define I2C_MDATA_START(x)                                 (((uint32)(((uint32)(x)) << I2C_MDATA_START_SHIFT)) & I2C_MDATA_START_MASK)
#define I2C_MDATA_DATA_MASK                                (0xFFU)
#define I2C_MDATA_DATA_SHIFT                               (0U)
#define I2C_MDATA_DATA(x)                                  (((uint32)(((uint32)(x)) << I2C_MDATA_DATA_SHIFT)) & I2C_MDATA_DATA_MASK)
/* I2C_MATCH Register */
#define I2C_MATCH_MATCH1_MASK                              (0xFF0000U)
#define I2C_MATCH_MATCH1_SHIFT                             (16U)
#define I2C_MATCH_MATCH1(x)                                (((uint32)(((uint32)(x)) << I2C_MATCH_MATCH1_SHIFT)) & I2C_MATCH_MATCH1_MASK)
#define I2C_MATCH_MATCH0_MASK                              (0xFFU)
#define I2C_MATCH_MATCH0_SHIFT                             (0U)
#define I2C_MATCH_MATCH0(x)                                (((uint32)(((uint32)(x)) << I2C_MATCH_MATCH0_SHIFT)) & I2C_MATCH_MATCH0_MASK)
/* I2C_TOCFG Register */
#define I2C_TOCFG_IDLE_MASK                                (0xFFF0000U)
#define I2C_TOCFG_IDLE_SHIFT                               (16U)
#define I2C_TOCFG_IDLE(x)                                  (((uint32)(((uint32)(x)) << I2C_TOCFG_IDLE_SHIFT)) & I2C_TOCFG_IDLE_MASK)
#define I2C_TOCFG_SDA_MASK                                 (0x8000U)
#define I2C_TOCFG_SDA_SHIFT                                (15U)
#define I2C_TOCFG_SDA(x)                                   (((uint32)(((uint32)(x)) << I2C_TOCFG_SDA_SHIFT)) & I2C_TOCFG_SDA_MASK)
#define I2C_TOCFG_LOW_MASK                                 (0xFFFU)
#define I2C_TOCFG_LOW_SHIFT                                (0U)
#define I2C_TOCFG_LOW(x)                                   (((uint32)(((uint32)(x)) << I2C_TOCFG_LOW_SHIFT)) & I2C_TOCFG_LOW_MASK)
/* I2C_HSCLK Register */
#define I2C_HSCLK_HIGH_WIDTH                               (6)
#define I2C_HSCLK_HIGH_MASK                                (0x3F000000U)
#define I2C_HSCLK_HIGH_SHIFT                               (24U)
#define I2C_HSCLK_HIGH(x)                                  (((uint32)(((uint32)(x)) << I2C_HSCLK_HIGH_SHIFT)) & I2C_HSCLK_HIGH_MASK)
#define I2C_HSCLK_LOW_WIDTH                                (6)
#define I2C_HSCLK_LOW_MASK                                 (0x3F0000U)
#define I2C_HSCLK_LOW_SHIFT                                (16U)
#define I2C_HSCLK_LOW(x)                                   (((uint32)(((uint32)(x)) << I2C_HSCLK_LOW_SHIFT)) & I2C_HSCLK_LOW_MASK)
#define I2C_HSCLK_VALID_WIDTH                              (6)
#define I2C_HSCLK_VALID_MASK                               (0x3F00U)
#define I2C_HSCLK_VALID_SHIFT                              (8U)
#define I2C_HSCLK_VALID(x)                                 (((uint32)(((uint32)(x)) << I2C_HSCLK_VALID_SHIFT)) & I2C_HSCLK_VALID_MASK)
#define I2C_HSCLK_STHD_WIDTH                               (6)
#define I2C_HSCLK_STHD_MASK                                (0x3FU)
#define I2C_HSCLK_STHD_SHIFT                               (0U)
#define I2C_HSCLK_STHD(x)                                  (((uint32)(((uint32)(x)) << I2C_HSCLK_STHD_SHIFT)) & I2C_HSCLK_STHD_MASK)
/* I2C_SCTRL Register */
#define I2C_SCTRL_ADDRDMAEN_MASK                           (0x40000000U)
#define I2C_SCTRL_ADDRDMAEN_SHIFT                          (30U)
#define I2C_SCTRL_ADDRDMAEN(x)                             (((uint32)(((uint32)(x)) << I2C_SCTRL_ADDRDMAEN_SHIFT)) & I2C_SCTRL_ADDRDMAEN_MASK)
#define I2C_SCTRL_TXDMAEN_MASK                             (0x20000000U)
#define I2C_SCTRL_TXDMAEN_SHIFT                            (29U)
#define I2C_SCTRL_TXDMAEN(x)                               (((uint32)(((uint32)(x)) << I2C_SCTRL_TXDMAEN_SHIFT)) & I2C_SCTRL_TXDMAEN_MASK)
#define I2C_SCTRL_RXDMAEN_MASK                             (0x10000000U)
#define I2C_SCTRL_RXDMAEN_SHIFT                            (28U)
#define I2C_SCTRL_RXDMAEN(x)                               (((uint32)(((uint32)(x)) << I2C_SCTRL_RXDMAEN_SHIFT)) & I2C_SCTRL_RXDMAEN_MASK)
#define I2C_SCTRL_STARTDMAEN_MASK                          (0x8000000U)
#define I2C_SCTRL_STARTDMAEN_SHIFT                         (27U)
#define I2C_SCTRL_STARTDMAEN(x)                            (((uint32)(((uint32)(x)) << I2C_SCTRL_STARTDMAEN_SHIFT)) & I2C_SCTRL_STARTDMAEN_MASK)
#define I2C_SCTRL_STOPDMAEN_MASK                           (0x4000000U)
#define I2C_SCTRL_STOPDMAEN_SHIFT                          (26U)
#define I2C_SCTRL_STOPDMAEN(x)                             (((uint32)(((uint32)(x)) << I2C_SCTRL_STOPDMAEN_SHIFT)) & I2C_SCTRL_STOPDMAEN_MASK)
#define I2C_SCTRL_HSEN_MASK                                (0x400000U)
#define I2C_SCTRL_HSEN_SHIFT                               (22U)
#define I2C_SCTRL_HSEN(x)                                  (((uint32)(((uint32)(x)) << I2C_SCTRL_HSEN_SHIFT)) & I2C_SCTRL_HSEN_MASK)
#define I2C_SCTRL_RXCFG_MASK                               (0x100000U)
#define I2C_SCTRL_RXCFG_SHIFT                              (20U)
#define I2C_SCTRL_RXCFG(x)                                 (((uint32)(((uint32)(x)) << I2C_SCTRL_RXCFG_SHIFT)) & I2C_SCTRL_RXCFG_MASK)
#define I2C_SCTRL_TXCFG_MASK                               (0x80000U)
#define I2C_SCTRL_TXCFG_SHIFT                              (19U)
#define I2C_SCTRL_TXCFG(x)                                 (((uint32)(((uint32)(x)) << I2C_SCTRL_TXCFG_SHIFT)) & I2C_SCTRL_TXCFG_MASK)
#define I2C_SCTRL_ADDRCFG_MASK                             (0x70000U)
#define I2C_SCTRL_ADDRCFG_SHIFT                            (16U)
#define I2C_SCTRL_ADDRCFG(x)                               (((uint32)(((uint32)(x)) << I2C_SCTRL_ADDRCFG_SHIFT)) & I2C_SCTRL_ADDRCFG_MASK)
#define I2C_SCTRL_IGACK_MASK                               (0x8000U)
#define I2C_SCTRL_IGACK_SHIFT                              (15U)
#define I2C_SCTRL_IGACK(x)                                 (((uint32)(((uint32)(x)) << I2C_SCTRL_IGACK_SHIFT)) & I2C_SCTRL_IGACK_MASK)
#define I2C_SCTRL_TXRST_MASK                               (0x2000U)
#define I2C_SCTRL_TXRST_SHIFT                              (13U)
#define I2C_SCTRL_TXRST(x)                                 (((uint32)(((uint32)(x)) << I2C_SCTRL_TXRST_SHIFT)) & I2C_SCTRL_TXRST_MASK)
#define I2C_SCTRL_RXRST_MASK                               (0x1000U)
#define I2C_SCTRL_RXRST_SHIFT                              (12U)
#define I2C_SCTRL_RXRST(x)                                 (((uint32)(((uint32)(x)) << I2C_SCTRL_RXRST_SHIFT)) & I2C_SCTRL_RXRST_MASK)
#define I2C_SCTRL_ALERTEN_MASK                             (0x800U)
#define I2C_SCTRL_ALERTEN_SHIFT                            (11U)
#define I2C_SCTRL_ALERTEN(x)                               (((uint32)(((uint32)(x)) << I2C_SCTRL_ALERTEN_SHIFT)) & I2C_SCTRL_ALERTEN_MASK)
#define I2C_SCTRL_GCEN_MASK                                (0x400U)
#define I2C_SCTRL_GCEN_SHIFT                               (10U)
#define I2C_SCTRL_GCEN(x)                                  (((uint32)(((uint32)(x)) << I2C_SCTRL_GCEN_SHIFT)) & I2C_SCTRL_GCEN_MASK)
#define I2C_SCTRL_TXSTALL_MASK                             (0x80U)
#define I2C_SCTRL_TXSTALL_SHIFT                            (7U)
#define I2C_SCTRL_TXSTALL(x)                               (((uint32)(((uint32)(x)) << I2C_SCTRL_TXSTALL_SHIFT)) & I2C_SCTRL_TXSTALL_MASK)
#define I2C_SCTRL_RXSTALL_MASK                             (0x40U)
#define I2C_SCTRL_RXSTALL_SHIFT                            (6U)
#define I2C_SCTRL_RXSTALL(x)                               (((uint32)(((uint32)(x)) << I2C_SCTRL_RXSTALL_SHIFT)) & I2C_SCTRL_RXSTALL_MASK)
#define I2C_SCTRL_ACKSTALL_MASK                            (0x20U)
#define I2C_SCTRL_ACKSTALL_SHIFT                           (5U)
#define I2C_SCTRL_ACKSTALL(x)                              (((uint32)(((uint32)(x)) << I2C_SCTRL_ACKSTALL_SHIFT)) & I2C_SCTRL_ACKSTALL_MASK)
#define I2C_SCTRL_ADRSTALL_MASK                            (0x10U)
#define I2C_SCTRL_ADRSTALL_SHIFT                           (4U)
#define I2C_SCTRL_ADRSTALL(x)                              (((uint32)(((uint32)(x)) << I2C_SCTRL_ADRSTALL_SHIFT)) & I2C_SCTRL_ADRSTALL_MASK)
#define I2C_SCTRL_FILTEN_MASK                              (0x4U)
#define I2C_SCTRL_FILTEN_SHIFT                             (2U)
#define I2C_SCTRL_FILTEN(x)                                (((uint32)(((uint32)(x)) << I2C_SCTRL_FILTEN_SHIFT)) & I2C_SCTRL_FILTEN_MASK)
#define I2C_SCTRL_SEN_MASK                                 (0x1U)
#define I2C_SCTRL_SEN_SHIFT                                (0U)
#define I2C_SCTRL_SEN(x)                                   (((uint32)(((uint32)(x)) << I2C_SCTRL_SEN_SHIFT)) & I2C_SCTRL_SEN_MASK)
/* I2C_SCLKCFG Register */
#define I2C_SCLKCFG_VALID_MASK                             (0x3F00U)
#define I2C_SCLKCFG_VALID_SHIFT                            (8U)
#define I2C_SCLKCFG_VALID(x)                               (((uint32)(((uint32)(x)) << I2C_SCLKCFG_VALID_SHIFT)) & I2C_SCLKCFG_VALID_MASK)
#define I2C_SCLKCFG_HOLD_MASK                              (0xFU)
#define I2C_SCLKCFG_HOLD_SHIFT                             (0U)
#define I2C_SCLKCFG_HOLD(x)                                (((uint32)(((uint32)(x)) << I2C_SCLKCFG_HOLD_SHIFT)) & I2C_SCLKCFG_HOLD_MASK)
/* I2C_SFLTCFG Register */
#define I2C_SFLTCFG_FLTSCL_MASK                            (0xF000000U)
#define I2C_SFLTCFG_FLTSCL_SHIFT                           (24U)
#define I2C_SFLTCFG_FLTSCL(x)                              (((uint32)(((uint32)(x)) << I2C_SFLTCFG_FLTSCL_SHIFT)) & I2C_SFLTCFG_FLTSCL_MASK)
#define I2C_SFLTCFG_FLTSDA_MASK                            (0xF0000U)
#define I2C_SFLTCFG_FLTSDA_SHIFT                           (16U)
#define I2C_SFLTCFG_FLTSDA(x)                              (((uint32)(((uint32)(x)) << I2C_SFLTCFG_FLTSDA_SHIFT)) & I2C_SFLTCFG_FLTSDA_MASK)
/* I2C_SSTS Register */
#define I2C_SSTS_ACTIVE_MASK                               (0x20000U)
#define I2C_SSTS_ACTIVE_SHIFT                              (17U)
#define I2C_SSTS_ACTIVE(x)                                 (((uint32)(((uint32)(x)) << I2C_SSTS_ACTIVE_SHIFT)) & I2C_SSTS_ACTIVE_MASK)
#define I2C_SSTS_BUSY_MASK                                 (0x10000U)
#define I2C_SSTS_BUSY_SHIFT                                (16U)
#define I2C_SSTS_BUSY(x)                                   (((uint32)(((uint32)(x)) << I2C_SSTS_BUSY_SHIFT)) & I2C_SSTS_BUSY_MASK)
#define I2C_SSTS_OPERRIF_MASK                              (0x2000U)
#define I2C_SSTS_OPERRIF_SHIFT                             (13U)
#define I2C_SSTS_OPERRIF(x)                                (((uint32)(((uint32)(x)) << I2C_SSTS_OPERRIF_SHIFT)) & I2C_SSTS_OPERRIF_MASK)
#define I2C_SSTS_ALERTIF_MASK                              (0x1000U)
#define I2C_SSTS_ALERTIF_SHIFT                             (12U)
#define I2C_SSTS_ALERTIF(x)                                (((uint32)(((uint32)(x)) << I2C_SSTS_ALERTIF_SHIFT)) & I2C_SSTS_ALERTIF_MASK)
#define I2C_SSTS_GCIF_MASK                                 (0x800U)
#define I2C_SSTS_GCIF_SHIFT                                (11U)
#define I2C_SSTS_GCIF(x)                                   (((uint32)(((uint32)(x)) << I2C_SSTS_GCIF_SHIFT)) & I2C_SSTS_GCIF_MASK)
#define I2C_SSTS_ADRBIF_MASK                               (0x400U)
#define I2C_SSTS_ADRBIF_SHIFT                              (10U)
#define I2C_SSTS_ADRBIF(x)                                 (((uint32)(((uint32)(x)) << I2C_SSTS_ADRBIF_SHIFT)) & I2C_SSTS_ADRBIF_MASK)
#define I2C_SSTS_MATCHAIF_MASK                             (0x200U)
#define I2C_SSTS_MATCHAIF_SHIFT                            (9U)
#define I2C_SSTS_MATCHAIF(x)                               (((uint32)(((uint32)(x)) << I2C_SSTS_MATCHAIF_SHIFT)) & I2C_SSTS_MATCHAIF_MASK)
#define I2C_SSTS_ARBIF_MASK                                (0x80U)
#define I2C_SSTS_ARBIF_SHIFT                               (7U)
#define I2C_SSTS_ARBIF(x)                                  (((uint32)(((uint32)(x)) << I2C_SSTS_ARBIF_SHIFT)) & I2C_SSTS_ARBIF_MASK)
#define I2C_SSTS_RSIF_MASK                                 (0x20U)
#define I2C_SSTS_RSIF_SHIFT                                (5U)
#define I2C_SSTS_RSIF(x)                                   (((uint32)(((uint32)(x)) << I2C_SSTS_RSIF_SHIFT)) & I2C_SSTS_RSIF_MASK)
#define I2C_SSTS_STOPIF_MASK                               (0x10U)
#define I2C_SSTS_STOPIF_SHIFT                              (4U)
#define I2C_SSTS_STOPIF(x)                                 (((uint32)(((uint32)(x)) << I2C_SSTS_STOPIF_SHIFT)) & I2C_SSTS_STOPIF_MASK)
#define I2C_SSTS_ADDRIF_MASK                               (0x8U)
#define I2C_SSTS_ADDRIF_SHIFT                              (3U)
#define I2C_SSTS_ADDRIF(x)                                 (((uint32)(((uint32)(x)) << I2C_SSTS_ADDRIF_SHIFT)) & I2C_SSTS_ADDRIF_MASK)
#define I2C_SSTS_ACKIF_MASK                                (0x4U)
#define I2C_SSTS_ACKIF_SHIFT                               (2U)
#define I2C_SSTS_ACKIF(x)                                  (((uint32)(((uint32)(x)) << I2C_SSTS_ACKIF_SHIFT)) & I2C_SSTS_ACKIF_MASK)
#define I2C_SSTS_TXIF_MASK                                 (0x2U)
#define I2C_SSTS_TXIF_SHIFT                                (1U)
#define I2C_SSTS_TXIF(x)                                   (((uint32)(((uint32)(x)) << I2C_SSTS_TXIF_SHIFT)) & I2C_SSTS_TXIF_MASK)
#define I2C_SSTS_RXIF_MASK                                 (0x1U)
#define I2C_SSTS_RXIF_SHIFT                                (0U)
#define I2C_SSTS_RXIF(x)                                   (((uint32)(((uint32)(x)) << I2C_SSTS_RXIF_SHIFT)) & I2C_SSTS_RXIF_MASK)
/* I2C_SIE Register */
#define I2C_SIE_OPERRIE_MASK                               (0x2000U)
#define I2C_SIE_OPERRIE_SHIFT                              (13U)
#define I2C_SIE_OPERRIE(x)                                 (((uint32)(((uint32)(x)) << I2C_SIE_OPERRIE_SHIFT)) & I2C_SIE_OPERRIE_MASK)
#define I2C_SIE_ALERTIE_MASK                               (0x1000U)
#define I2C_SIE_ALERTIE_SHIFT                              (12U)
#define I2C_SIE_ALERTIE(x)                                 (((uint32)(((uint32)(x)) << I2C_SIE_ALERTIE_SHIFT)) & I2C_SIE_ALERTIE_MASK)
#define I2C_SIE_GCIE_MASK                                  (0x800U)
#define I2C_SIE_GCIE_SHIFT                                 (11U)
#define I2C_SIE_GCIE(x)                                    (((uint32)(((uint32)(x)) << I2C_SIE_GCIE_SHIFT)) & I2C_SIE_GCIE_MASK)
#define I2C_SIE_MAT1IE_MASK                                (0x400U)
#define I2C_SIE_MAT1IE_SHIFT                               (10U)
#define I2C_SIE_MAT1IE(x)                                  (((uint32)(((uint32)(x)) << I2C_SIE_MAT1IE_SHIFT)) & I2C_SIE_MAT1IE_MASK)
#define I2C_SIE_MAT0IE_MASK                                (0x200U)
#define I2C_SIE_MAT0IE_SHIFT                               (9U)
#define I2C_SIE_MAT0IE(x)                                  (((uint32)(((uint32)(x)) << I2C_SIE_MAT0IE_SHIFT)) & I2C_SIE_MAT0IE_MASK)
#define I2C_SIE_ARBIE_MASK                                 (0x80U)
#define I2C_SIE_ARBIE_SHIFT                                (7U)
#define I2C_SIE_ARBIE(x)                                   (((uint32)(((uint32)(x)) << I2C_SIE_ARBIE_SHIFT)) & I2C_SIE_ARBIE_MASK)
#define I2C_SIE_RSIE_MASK                                  (0x20U)
#define I2C_SIE_RSIE_SHIFT                                 (5U)
#define I2C_SIE_RSIE(x)                                    (((uint32)(((uint32)(x)) << I2C_SIE_RSIE_SHIFT)) & I2C_SIE_RSIE_MASK)
#define I2C_SIE_STOPIE_MASK                                (0x10U)
#define I2C_SIE_STOPIE_SHIFT                               (4U)
#define I2C_SIE_STOPIE(x)                                  (((uint32)(((uint32)(x)) << I2C_SIE_STOPIE_SHIFT)) & I2C_SIE_STOPIE_MASK)
#define I2C_SIE_ADDRIE_MASK                                (0x8U)
#define I2C_SIE_ADDRIE_SHIFT                               (3U)
#define I2C_SIE_ADDRIE(x)                                  (((uint32)(((uint32)(x)) << I2C_SIE_ADDRIE_SHIFT)) & I2C_SIE_ADDRIE_MASK)
#define I2C_SIE_ACKIE_MASK                                 (0x4U)
#define I2C_SIE_ACKIE_SHIFT                                (2U)
#define I2C_SIE_ACKIE(x)                                   (((uint32)(((uint32)(x)) << I2C_SIE_ACKIE_SHIFT)) & I2C_SIE_ACKIE_MASK)
#define I2C_SIE_TXIE_MASK                                  (0x2U)
#define I2C_SIE_TXIE_SHIFT                                 (1U)
#define I2C_SIE_TXIE(x)                                    (((uint32)(((uint32)(x)) << I2C_SIE_TXIE_SHIFT)) & I2C_SIE_TXIE_MASK)
#define I2C_SIE_RXIE_MASK                                  (0x1U)
#define I2C_SIE_RXIE_SHIFT                                 (0U)
#define I2C_SIE_RXIE(x)                                    (((uint32)(((uint32)(x)) << I2C_SIE_RXIE_SHIFT)) & I2C_SIE_RXIE_MASK)
/* I2C_SDATA Register */
#define I2C_SDATA_EMPTY_MASK                               (0x10000U)
#define I2C_SDATA_EMPTY_SHIFT                              (16U)
#define I2C_SDATA_EMPTY(x)                                 (((uint32)(((uint32)(x)) << I2C_SDATA_EMPTY_SHIFT)) & I2C_SDATA_EMPTY_MASK)
#define I2C_SDATA_DATA_MASK                                (0xFFU)
#define I2C_SDATA_DATA_SHIFT                               (0U)
#define I2C_SDATA_DATA(x)                                  (((uint32)(((uint32)(x)) << I2C_SDATA_DATA_SHIFT)) & I2C_SDATA_DATA_MASK)
/* I2C_SACK Register */
#define I2C_SACK_NACK_MASK                                 (0x1U)
#define I2C_SACK_NACK_SHIFT                                (0U)
#define I2C_SACK_NACK(x)                                   (((uint32)(((uint32)(x)) << I2C_SACK_NACK_SHIFT)) & I2C_SACK_NACK_MASK)
/* I2C_SADDR Register */
#define I2C_SADDR_ADDRB_MASK                               (0x7FE0000U)
#define I2C_SADDR_ADDRB_SHIFT                              (17U)
#define I2C_SADDR_ADDRB(x)                                 (((uint32)(((uint32)(x)) << I2C_SADDR_ADDRB_SHIFT)) & I2C_SADDR_ADDRB_MASK)
#define I2C_SADDR_ADDRA_MASK                               (0x7FEU)
#define I2C_SADDR_ADDRA_SHIFT                              (1U)
#define I2C_SADDR_ADDRA(x)                                 (((uint32)(((uint32)(x)) << I2C_SADDR_ADDRA_SHIFT)) & I2C_SADDR_ADDRA_MASK)
/* I2C_SRADDR Register */
#define I2C_SRADDR_VALID_MASK                              (0x8000U)
#define I2C_SRADDR_VALID_SHIFT                             (15U)
#define I2C_SRADDR_VALID(x)                                (((uint32)(((uint32)(x)) << I2C_SRADDR_VALID_SHIFT)) & I2C_SRADDR_VALID_MASK)
#define I2C_SRADDR_ADDR_MASK                               (0x7FFU)
#define I2C_SRADDR_ADDR_SHIFT                              (0U)
#define I2C_SRADDR_ADDR(x)                                 (((uint32)(((uint32)(x)) << I2C_SRADDR_ADDR_SHIFT)) & I2C_SRADDR_ADDR_MASK)


/**
 * @}
 */ /* end of group I2C_Register_Masks */


/**
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */

#endif /* PSIP_I2C_H */

