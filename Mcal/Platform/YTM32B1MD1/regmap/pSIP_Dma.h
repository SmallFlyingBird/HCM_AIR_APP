/**
*   @file    pSIP_Dma.h
*   @version
*
*   @brief   AUTOSAR Dma register map
*   @details Register map for DMA
*
*   @addtogroup DMA_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Dma
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

#ifndef PSIP_DMA_H
#define PSIP_DMA_H

/*
* @page misra_violations MISRA-C:2012 violations list
* PRQA S 0750 Rule 19.2: The union keyword should not be used.
*/
/* MR12 RULE 19.2 VIOLATION: The DMA registers - BCNT, TCNT and DTO_RLD are defined as unions for
*                            control and configuration access.
*/
/* PRQA S 0750 EOF */

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              DMA REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */


/** DMA - Size of Registers Arrays */
#define DMA_CHMUX_COUNT           (16)
#define DMA_CTS_COUNT           (16)

/* DMA module features */
/* @brief DMA Channel width based on number of CTSs: 2^N, N=4,5,... */
#define FEATURE_DMA_CH_WIDTH (4U)
/* @brief DMA Channel to instance */
#define FEATURE_DMA_VCH_TO_INSTANCE(x)  ((x) >> (uint32)FEATURE_DMA_CH_WIDTH)

/* DMA Register Layout Typedef */
typedef struct
{
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 CHTLDIF;                            /**< Channel Trigger Loop Done Interrupt Flag Register, offset: 0x0004 */
    uint32 CHTLHDIF;                           /**< Channel Trigger Loop Half Done Interrupt Flag Register, offset: 0x0008 */
    uint32 CHEIF;                              /**< DMA Channel Error Interrupt Flag Register, offset: 0x000C */
    uint32 CHEIE;                              /**< DMA Channel Error Interrupt Enable Register, offset: 0x0010 */
    uint32 ERS;                                /**< Error Status Register, offset: 0x0014 */
    uint32 REQEN;                              /**< Hardware Request Enable Register, offset: 0x0018 */
    uint32 REQS;                               /**< Request Status Register, offset: 0x001C */
    uint32 START;                              /**< Channel Start Register, offset: 0x0020 */
    uint32 DONE;                               /**< Channel Done Register, offset: 0x0024 */
    uint32 RESERVED0[ 6];                      /**< RESERVED0, offset: 0x0028 */
    uint8 CHMUX[16];                          /**< Channel Mux Register, offset: 0x0040 */
    uint32 RESERVED1[236];                      /**< RESERVED1, offset: 0x0060 */
    struct
    {
        uint32 SADDR;                              /**< Source Address Register, offset: 0x0400 */
        uint16 SOFF;                               /**< Source Address Offset Register, offset: 0x0404 */
        uint16 TCR;                                /**< Transfer Control Register, offset: 0x0406 */
        union
        {
            uint32 BCNT;                               /**< Transfer Loop Byte Count, offset: 0x0408 */
            uint32 LODIS;                              /**< Transfer Loop Offset Disable Mapping, offset: 0x0408 */
            uint32 LOEN;                               /**< Transfer Loop Offset Enable Mapping, offset: 0x0408 */

        } BCNT;
        uint32 STO;                                /**< Source Trigger Loop Offset Register, offset: 0x040C */
        uint32 DADDR;                              /**< Destination Address Register, offset: 0x0410 */
        uint16 DOFF;                               /**< Destination Address Offset Register, offset: 0x0414 */
        union
        {
            uint16 LKDIS;                              /**< Trigger Count with Link Disable, offset: 0x0416 */
            uint16 LKEN;                               /**< Trigger Count with Link Enable, offset: 0x0416 */

        } TCNT;
        union
        {
            uint32 DTO;                                /**< Destination Trigger Loop Offset Register, offset: 0x0418 */
            uint32 RLD;                                /**< RAM Reload Address Register, offset: 0x0418 */

        } DTO_RLD;
        uint16 CSR;                                /**< Control and Status Register, offset: 0x041C */
        uint16 TCNTRV;                             /**< TCNT Reload Value Register, offset: 0x041E */

    } CTS[16];

} DMA_Type, *DMA_MemMapPtr;

/* Dma module reset via IPC Register Layout Typedef */
typedef struct
{
    uint32 CTRL;  /**< Control Register, offset: 0x0000 */
} Dma_ResetType;

/** Number of instances of the DMA module. */
#define DMA_INSTANCE_COUNT                        (1u)

/* DMA0  base address */
#define DMA0_BASE_ADDR32                                   (0x40008000U)
#define DMA0                                               ((volatile DMA_Type *)(DMA0_BASE_ADDR32))

/* Dma rest via IPC base address */
#define DMA_REST_VIA_IPC_BASE_ADDR32                       (0x4007D020U)
#define DMA_REST_VIA_IPC                                   ((volatile Dma_ResetType *)(DMA_REST_VIA_IPC_BASE_ADDR32))
#define DMA_CTRL_SWRESET_MASK                              (0x2U)

/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                                     { DMA0_BASE_ADDR32 }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                                      { DMA0 }

#define DMA_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Control Register */
#define DMA_CHTLDIF_OFFSET32                               (0x0004U)                    /**< Offset for Channel Trigger Loop Done Interrupt Flag Register */
#define DMA_CHTLHDIF_OFFSET32                              (0x0008U)                    /**< Offset for Channel Trigger Loop Half Done Interrupt Flag Register */
#define DMA_CHEIF_OFFSET32                                 (0x000CU)                    /**< Offset for DMA Channel Error Interrupt Flag Register */
#define DMA_CHEIE_OFFSET32                                 (0x0010U)                    /**< Offset for DMA Channel Error Interrupt Enable Register */
#define DMA_ERS_OFFSET32                                   (0x0014U)                    /**< Offset for Error Status Register */
#define DMA_REQEN_OFFSET32                                 (0x0018U)                    /**< Offset for Hardware Request Enable Register */
#define DMA_REQS_OFFSET32                                  (0x001CU)                    /**< Offset for Request Status Register */
#define DMA_START_OFFSET32                                 (0x0020U)                    /**< Offset for Channel Start Register */
#define DMA_DONE_OFFSET32                                  (0x0024U)                    /**< Offset for Channel Done Register */
#define DMA_CHMUX_OFFSET8(x)                               (0x0040U + ((x) * (1U)))     /**< Offset for Channel Mux Register */
#define DMA_CTS_OFFSET32(x)                                (0x0400U + ((x) * (32U)))    /**< Offset for Channel Transfer Structure */

#define DMA_CTS_SADDR_OFFSET32(x)                          (0x0400U + ((x) * (32U)))    /**< Offset for Source Address Register */
#define DMA_CTS_SOFF_OFFSET16(x)                           (0x0404U + ((x) * (32U)))    /**< Offset for Source Address Offset Register */
#define DMA_CTS_TCR_OFFSET16(x)                            (0x0406U + ((x) * (32U)))    /**< Offset for Transfer Control Register */
#define DMA_CTS_BCNT_OFFSET32                              (0x0408U)                    /**< Offset for Byte Count Register */
#define DMA_CTS_BCNT_BCNT_OFFSET32(x)                      (0x0408U + ((x) * (32U)))    /**< Offset for Transfer Loop Byte Count */
#define DMA_CTS_BCNT_LODIS_OFFSET32(x)                     (0x0408U + ((x) * (32U)))    /**< Offset for Transfer Loop Offset Disable Mapping */
#define DMA_CTS_BCNT_LOEN_OFFSET32(x)                      (0x0408U + ((x) * (32U)))    /**< Offset for Transfer Loop Offset Enable Mapping */


#define DMA_CTS_STO_OFFSET32(x)                            (0x040CU + ((x) * (32U)))    /**< Offset for Source Trigger Loop Offset Register */
#define DMA_CTS_DADDR_OFFSET32(x)                          (0x0410U + ((x) * (32U)))    /**< Offset for Destination Address Register */
#define DMA_CTS_DOFF_OFFSET16(x)                           (0x0414U + ((x) * (32U)))    /**< Offset for Destination Address Offset Register */
#define DMA_CTS_TCNT_OFFSET16                              (0x0416U)                    /**< Offset for Trigger Count Register */
#define DMA_CTS_TCNT_LKDIS_OFFSET16(x)                     (0x0416U + ((x) * (32U)))    /**< Offset for Trigger Count with Link Disable */
#define DMA_CTS_TCNT_LKEN_OFFSET16(x)                      (0x0416U + ((x) * (32U)))    /**< Offset for Trigger Count with Link Enable */


#define DMA_CTS_DTO_RLD_OFFSET32                           (0x0418U)                    /**< Offset for Destination Address Adjustment/RAM Reload Address */
#define DMA_CTS_DTO_RLD_DTO_OFFSET32(x)                    (0x0418U + ((x) * (32U)))    /**< Offset for Destination Trigger Loop Offset Register */
#define DMA_CTS_DTO_RLD_RLD_OFFSET32(x)                    (0x0418U + ((x) * (32U)))    /**< Offset for RAM Reload Address Register */


#define DMA_CTS_CSR_OFFSET16(x)                            (0x041CU + ((x) * (32U)))    /**< Offset for Control and Status Register */
#define DMA_CTS_TCNTRV_OFFSET16(x)                         (0x041EU + ((x) * (32U)))    /**< Offset for TCNT Reload Value Register */



/**
 * @addtogroup DMA Register Mask
 * @{
 */
/* DMA_CTRL Register */
#define DMA_CTRL_ACTIVE_MASK                               (0x80000000U)
#define DMA_CTRL_ACTIVE_SHIFT                              (31U)
#define DMA_CTRL_ACTIVE(x)                                 (((uint32)(((uint32)(x)) << DMA_CTRL_ACTIVE_SHIFT)) & DMA_CTRL_ACTIVE_MASK)
#define DMA_CTRL_ACTCH_MASK                                (0xF000000U)
#define DMA_CTRL_ACTCH_SHIFT                               (24U)
#define DMA_CTRL_ACTCH(x)                                  (((uint32)(((uint32)(x)) << DMA_CTRL_ACTCH_SHIFT)) & DMA_CTRL_ACTCH_MASK)
#define DMA_CTRL_CX_MASK                                   (0x80000U)
#define DMA_CTRL_CX_SHIFT                                  (19U)
#define DMA_CTRL_CX(x)                                     (((uint32)(((uint32)(x)) << DMA_CTRL_CX_SHIFT)) & DMA_CTRL_CX_MASK)
#define DMA_CTRL_ECX_MASK                                  (0x40000U)
#define DMA_CTRL_ECX_SHIFT                                 (18U)
#define DMA_CTRL_ECX(x)                                    (((uint32)(((uint32)(x)) << DMA_CTRL_ECX_SHIFT)) & DMA_CTRL_ECX_MASK)
#define DMA_CTRL_PAUSE_MASK                                (0x20000U)
#define DMA_CTRL_PAUSE_SHIFT                               (17U)
#define DMA_CTRL_PAUSE(x)                                  (((uint32)(((uint32)(x)) << DMA_CTRL_PAUSE_SHIFT)) & DMA_CTRL_PAUSE_MASK)
#define DMA_CTRL_POE_MASK                                  (0x10000U)
#define DMA_CTRL_POE_SHIFT                                 (16U)
#define DMA_CTRL_POE(x)                                    (((uint32)(((uint32)(x)) << DMA_CTRL_POE_SHIFT)) & DMA_CTRL_POE_MASK)
#define DMA_CTRL_LOEN_MASK                                 (0x400U)
#define DMA_CTRL_LOEN_SHIFT                                (10U)
#define DMA_CTRL_LOEN(x)                                   (((uint32)(((uint32)(x)) << DMA_CTRL_LOEN_SHIFT)) & DMA_CTRL_LOEN_MASK)
#define DMA_CTRL_CLM_MASK                                  (0x200U)
#define DMA_CTRL_CLM_SHIFT                                 (9U)
#define DMA_CTRL_CLM(x)                                    (((uint32)(((uint32)(x)) << DMA_CTRL_CLM_SHIFT)) & DMA_CTRL_CLM_MASK)
#define DMA_CTRL_DBGDIS_MASK                               (0x4U)
#define DMA_CTRL_DBGDIS_SHIFT                              (2U)
#define DMA_CTRL_DBGDIS(x)                                 (((uint32)(((uint32)(x)) << DMA_CTRL_DBGDIS_SHIFT)) & DMA_CTRL_DBGDIS_MASK)
#define DMA_CTRL_CLRAD_MASK                                (0x2U)
#define DMA_CTRL_CLRAD_SHIFT                               (1U)
#define DMA_CTRL_CLRAD(x)                                  (((uint32)(((uint32)(x)) << DMA_CTRL_CLRAD_SHIFT)) & DMA_CTRL_CLRAD_MASK)
#define DMA_CTRL_STACH_MASK                                (0x1U)
#define DMA_CTRL_STACH_SHIFT                               (0U)
#define DMA_CTRL_STACH(x)                                  (((uint32)(((uint32)(x)) << DMA_CTRL_STACH_SHIFT)) & DMA_CTRL_STACH_MASK)
/* DMA_CHTLDIF Register */
#define DMA_CHTLDIF_CH_MASK                                (0xFFFFU)
#define DMA_CHTLDIF_CH_SHIFT                               (0U)
#define DMA_CHTLDIF_CH(x)                                  (((uint32)(((uint32)(x)) << DMA_CHTLDIF_CH_SHIFT)) & DMA_CHTLDIF_CH_MASK)
/* DMA_CHTLHDIF Register */
#define DMA_CHTLHDIF_CH_MASK                               (0xFFFFU)
#define DMA_CHTLHDIF_CH_SHIFT                              (0U)
#define DMA_CHTLHDIF_CH(x)                                 (((uint32)(((uint32)(x)) << DMA_CHTLHDIF_CH_SHIFT)) & DMA_CHTLHDIF_CH_MASK)
/* DMA_CHEIF Register */
#define DMA_CHEIF_CH_MASK                                  (0xFFFFU)
#define DMA_CHEIF_CH_SHIFT                                 (0U)
#define DMA_CHEIF_CH(x)                                    (((uint32)(((uint32)(x)) << DMA_CHEIF_CH_SHIFT)) & DMA_CHEIF_CH_MASK)
/* DMA_CHEIE Register */
#define DMA_CHEIE_CH_MASK                                  (0xFFFFU)
#define DMA_CHEIE_CH_SHIFT                                 (0U)
#define DMA_CHEIE_CH(x)                                    (((uint32)(((uint32)(x)) << DMA_CHEIE_CH_SHIFT)) & DMA_CHEIE_CH_MASK)
/* DMA_ERS Register */
#define DMA_ERS_VALID_MASK                                 (0x80000000U)
#define DMA_ERS_VALID_SHIFT                                (31U)
#define DMA_ERS_VALID(x)                                   (((uint32)(((uint32)(x)) << DMA_ERS_VALID_SHIFT)) & DMA_ERS_VALID_MASK)
#define DMA_ERS_ECX_MASK                                   (0x40000U)
#define DMA_ERS_ECX_SHIFT                                  (18U)
#define DMA_ERS_ECX(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_ECX_SHIFT)) & DMA_ERS_ECX_MASK)
#define DMA_ERS_SAE_MASK                                   (0x8000U)
#define DMA_ERS_SAE_SHIFT                                  (15U)
#define DMA_ERS_SAE(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_SAE_SHIFT)) & DMA_ERS_SAE_MASK)
#define DMA_ERS_SOE_MASK                                   (0x4000U)
#define DMA_ERS_SOE_SHIFT                                  (14U)
#define DMA_ERS_SOE(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_SOE_SHIFT)) & DMA_ERS_SOE_MASK)
#define DMA_ERS_DAE_MASK                                   (0x2000U)
#define DMA_ERS_DAE_SHIFT                                  (13U)
#define DMA_ERS_DAE(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_DAE_SHIFT)) & DMA_ERS_DAE_MASK)
#define DMA_ERS_DOE_MASK                                   (0x1000U)
#define DMA_ERS_DOE_SHIFT                                  (12U)
#define DMA_ERS_DOE(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_DOE_SHIFT)) & DMA_ERS_DOE_MASK)
#define DMA_ERS_BTCE_MASK                                  (0x800U)
#define DMA_ERS_BTCE_SHIFT                                 (11U)
#define DMA_ERS_BTCE(x)                                    (((uint32)(((uint32)(x)) << DMA_ERS_BTCE_SHIFT)) & DMA_ERS_BTCE_MASK)
#define DMA_ERS_RLDE_MASK                                  (0x400U)
#define DMA_ERS_RLDE_SHIFT                                 (10U)
#define DMA_ERS_RLDE(x)                                    (((uint32)(((uint32)(x)) << DMA_ERS_RLDE_SHIFT)) & DMA_ERS_RLDE_MASK)
#define DMA_ERS_SBE_MASK                                   (0x200U)
#define DMA_ERS_SBE_SHIFT                                  (9U)
#define DMA_ERS_SBE(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_SBE_SHIFT)) & DMA_ERS_SBE_MASK)
#define DMA_ERS_DBE_MASK                                   (0x100U)
#define DMA_ERS_DBE_SHIFT                                  (8U)
#define DMA_ERS_DBE(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_DBE_SHIFT)) & DMA_ERS_DBE_MASK)
#define DMA_ERS_ECH_WIDTH                                  (4)
#define DMA_ERS_ECH_MASK                                   (0xFU)
#define DMA_ERS_ECH_SHIFT                                  (0U)
#define DMA_ERS_ECH(x)                                     (((uint32)(((uint32)(x)) << DMA_ERS_ECH_SHIFT)) & DMA_ERS_ECH_MASK)
/* DMA_REQEN Register */
#define DMA_REQEN_CH_WIDTH                                 (16)
#define DMA_REQEN_CH_MASK                                  (0xFFFFU)
#define DMA_REQEN_CH_SHIFT                                 (0U)
#define DMA_REQEN_CH(x)                                    (((uint32)(((uint32)(x)) << DMA_REQEN_CH_SHIFT)) & DMA_REQEN_CH_MASK)
/* DMA_REQS Register */
#define DMA_REQS_CH_WIDTH                                  (16)
#define DMA_REQS_CH_MASK                                   (0xFFFFU)
#define DMA_REQS_CH_SHIFT                                  (0U)
#define DMA_REQS_CH(x)                                     (((uint32)(((uint32)(x)) << DMA_REQS_CH_SHIFT)) & DMA_REQS_CH_MASK)
/* DMA_START Register */
#define DMA_START_CH_WIDTH                                 (16)
#define DMA_START_CH_MASK                                  (0xFFFFU)
#define DMA_START_CH_SHIFT                                 (0U)
#define DMA_START_CH(x)                                    (((uint32)(((uint32)(x)) << DMA_START_CH_SHIFT)) & DMA_START_CH_MASK)
/* DMA_DONE Register */
#define DMA_DONE_CH_WIDTH                                  (16)
#define DMA_DONE_CH_MASK                                   (0xFFFFU)
#define DMA_DONE_CH_SHIFT                                  (0U)
#define DMA_DONE_CH(x)                                     (((uint32)(((uint32)(x)) << DMA_DONE_CH_SHIFT)) & DMA_DONE_CH_MASK)
/* DMA_CHMUX Register */
#define DMA_CHMUX_CH_WIDTH                                 (7)
#define DMA_CHMUX_CH_MASK                                  (0x7FU)
#define DMA_CHMUX_CH_SHIFT                                 (0U)
#define DMA_CHMUX_CH(x)                                    (((uint32)(((uint32)(x)) << DMA_CHMUX_CH_SHIFT)) & DMA_CHMUX_CH_MASK)
/* DMA_CTS_SADDR Register */
#define DMA_CTS_SADDR_SADDR_WIDTH                              (32)
#define DMA_CTS_SADDR_SADDR_MASK                               (0xFFFFFFFFU)
#define DMA_CTS_SADDR_SADDR_SHIFT                              (0U)
#define DMA_CTS_SADDR_SADDR(x)                                 (((uint32)(((uint32)(x)) << DMA_CTS_SADDR_SADDR_SHIFT)) & DMA_CTS_SADDR_SADDR_MASK)
/* DMA_CTS_SOFF Register */
#define DMA_CTS_SOFF_SOFF_WIDTH                                (32)
#define DMA_CTS_SOFF_SOFF_MASK                                 (0xFFFFU)
#define DMA_CTS_SOFF_SOFF_SHIFT                                (0U)
#define DMA_CTS_SOFF_SOFF(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_SOFF_SOFF_SHIFT)) & DMA_CTS_SOFF_SOFF_MASK)
/* DMA_CTS_TCR Register */
#define DMA_CTS_TCR_SMOD_WIDTH                                 (5)
#define DMA_CTS_TCR_SMOD_MASK                                  (0xF800U)
#define DMA_CTS_TCR_SMOD_SHIFT                                 (11U)
#define DMA_CTS_TCR_SMOD(x)                                    (((uint32)(((uint32)(x)) << DMA_CTS_TCR_SMOD_SHIFT)) & DMA_CTS_TCR_SMOD_MASK)
#define DMA_CTS_TCR_SSIZE_WIDTH                                (3)
#define DMA_CTS_TCR_SSIZE_MASK                                 (0x700U)
#define DMA_CTS_TCR_SSIZE_SHIFT                                (8U)
#define DMA_CTS_TCR_SSIZE(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_TCR_SSIZE_SHIFT)) & DMA_CTS_TCR_SSIZE_MASK)
#define DMA_CTS_TCR_DMOD_WIDTH                                 (5)
#define DMA_CTS_TCR_DMOD_MASK                                  (0xF8U)
#define DMA_CTS_TCR_DMOD_SHIFT                                 (3U)
#define DMA_CTS_TCR_DMOD(x)                                    (((uint32)(((uint32)(x)) << DMA_CTS_TCR_DMOD_SHIFT)) & DMA_CTS_TCR_DMOD_MASK)
#define DMA_CTS_TCR_DSIZE_WIDTH                                (3)
#define DMA_CTS_TCR_DSIZE_MASK                                 (0x7U)
#define DMA_CTS_TCR_DSIZE_SHIFT                                (0U)
#define DMA_CTS_TCR_DSIZE(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_TCR_DSIZE_SHIFT)) & DMA_CTS_TCR_DSIZE_MASK)
/* DMA_CTS_BCNT_BCNT Register */
#define DMA_CTS_BCNT_BCNT_BCNT_MASK                                 (0xFFFFFFFFU)
#define DMA_CTS_BCNT_BCNT_BCNT_SHIFT                                (0U)
#define DMA_CTS_BCNT_BCNT_BCNT(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_BCNT_BCNT_SHIFT)) & DMA_CTS_BCNT_BCNT_BCNT_MASK)
/* DMA_CTS_BCNT_LODIS Register */
#define DMA_CTS_BCNT_LODIS_SLOE_MASK                                (0x80000000U)
#define DMA_CTS_BCNT_LODIS_SLOE_SHIFT                               (31U)
#define DMA_CTS_BCNT_LODIS_SLOE(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_LODIS_SLOE_SHIFT)) & DMA_CTS_BCNT_LODIS_SLOE_MASK)
#define DMA_CTS_BCNT_LODIS_DLOE_MASK                                (0x40000000U)
#define DMA_CTS_BCNT_LODIS_DLOE_SHIFT                               (30U)
#define DMA_CTS_BCNT_LODIS_DLOE(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_LODIS_DLOE_SHIFT)) & DMA_CTS_BCNT_LODIS_DLOE_MASK)
#define DMA_CTS_BCNT_LODIS_BCNT_MASK                                (0x3FFFFFFFU)
#define DMA_CTS_BCNT_LODIS_BCNT_SHIFT                               (0U)
#define DMA_CTS_BCNT_LODIS_BCNT(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_LODIS_BCNT_SHIFT)) & DMA_CTS_BCNT_LODIS_BCNT_MASK)
/* DMA_CTS_BCNT_LOEN Register */
#define DMA_CTS_BCNT_LOEN_SLOE_MASK                                 (0x80000000U)
#define DMA_CTS_BCNT_LOEN_SLOE_SHIFT                                (31U)
#define DMA_CTS_BCNT_LOEN_SLOE(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_LOEN_SLOE_SHIFT)) & DMA_CTS_BCNT_LOEN_SLOE_MASK)
#define DMA_CTS_BCNT_LOEN_DLOE_MASK                                 (0x40000000U)
#define DMA_CTS_BCNT_LOEN_DLOE_SHIFT                                (30U)
#define DMA_CTS_BCNT_LOEN_DLOE(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_LOEN_DLOE_SHIFT)) & DMA_CTS_BCNT_LOEN_DLOE_MASK)
#define DMA_CTS_BCNT_LOEN_OFFSET_MASK                               (0x3FFFFC00U)
#define DMA_CTS_BCNT_LOEN_OFFSET_SHIFT                              (10U)
#define DMA_CTS_BCNT_LOEN_OFFSET(x)                                 (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_LOEN_OFFSET_SHIFT)) & DMA_CTS_BCNT_LOEN_OFFSET_MASK)
#define DMA_CTS_BCNT_LOEN_BCNT_MASK                                 (0x3FFU)
#define DMA_CTS_BCNT_LOEN_BCNT_SHIFT                                (0U)
#define DMA_CTS_BCNT_LOEN_BCNT(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_BCNT_LOEN_BCNT_SHIFT)) & DMA_CTS_BCNT_LOEN_BCNT_MASK)

/* DMA_CTS_STO Register */
#define DMA_CTS_STO_STLOFF_WIDTH                               (31)
#define DMA_CTS_STO_STLOFF_MASK                                (0xFFFFFFFFU)
#define DMA_CTS_STO_STLOFF_SHIFT                               (0U)
#define DMA_CTS_STO_STLOFF(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_STO_STLOFF_SHIFT)) & DMA_CTS_STO_STLOFF_MASK)
/* DMA_CTS_DADDR Register */
#define DMA_CTS_DADDR_DADDR_WIDTH                              (31)
#define DMA_CTS_DADDR_DADDR_MASK                               (0xFFFFFFFFU)
#define DMA_CTS_DADDR_DADDR_SHIFT                              (0U)
#define DMA_CTS_DADDR_DADDR(x)                                 (((uint32)(((uint32)(x)) << DMA_CTS_DADDR_DADDR_SHIFT)) & DMA_CTS_DADDR_DADDR_MASK)
/* DMA_CTS_DOFF Register */
#define DMA_CTS_DOFF_DOFF_WIDTH                                (16)
#define DMA_CTS_DOFF_DOFF_MASK                                 (0xFFFFU)
#define DMA_CTS_DOFF_DOFF_SHIFT                                (0U)
#define DMA_CTS_DOFF_DOFF(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_DOFF_DOFF_SHIFT)) & DMA_CTS_DOFF_DOFF_MASK)
/* DMA_CTS_TCNT_LKDIS Register */
#define DMA_CTS_TCNT_LKDIS_LKEN_MASK                                (0x8000U)
#define DMA_CTS_TCNT_LKDIS_LKEN_SHIFT                               (15U)
#define DMA_CTS_TCNT_LKDIS_LKEN(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_TCNT_LKDIS_LKEN_SHIFT)) & DMA_CTS_TCNT_LKDIS_LKEN_MASK)
#define DMA_CTS_TCNT_LKDIS_TCNT_MASK                                (0x7FFFU)
#define DMA_CTS_TCNT_LKDIS_TCNT_SHIFT                               (0U)
#define DMA_CTS_TCNT_LKDIS_TCNT(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_TCNT_LKDIS_TCNT_SHIFT)) & DMA_CTS_TCNT_LKDIS_TCNT_MASK)
/* DMA_CTS_TCNT_LKEN Register */
#define DMA_CTS_TCNT_LKEN_LKEN_MASK                                 (0x8000U)
#define DMA_CTS_TCNT_LKEN_LKEN_SHIFT                                (15U)
#define DMA_CTS_TCNT_LKEN_LKEN(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_TCNT_LKEN_LKEN_SHIFT)) & DMA_CTS_TCNT_LKEN_LKEN_MASK)
#define DMA_CTS_TCNT_LKEN_LKCH_MASK                                 (0x1E00U)
#define DMA_CTS_TCNT_LKEN_LKCH_SHIFT                                (9U)
#define DMA_CTS_TCNT_LKEN_LKCH(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_TCNT_LKEN_LKCH_SHIFT)) & DMA_CTS_TCNT_LKEN_LKCH_MASK)
#define DMA_CTS_TCNT_LKEN_TCNT_MASK                                 (0x1FFU)
#define DMA_CTS_TCNT_LKEN_TCNT_SHIFT                                (0U)
#define DMA_CTS_TCNT_LKEN_TCNT(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_TCNT_LKEN_TCNT_SHIFT)) & DMA_CTS_TCNT_LKEN_TCNT_MASK)

/* DMA_CTS_DTO_RLD_DTO Register */
#define DMA_CTS_DTO_RLD_DTO_OFFSET_MASK                                (0xFFFFFFFFU)
#define DMA_CTS_DTO_RLD_DTO_OFFSET_SHIFT                               (0U)
#define DMA_CTS_DTO_RLD_DTO_OFFSET(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_DTO_RLD_DTO_OFFSET_SHIFT)) & DMA_CTS_DTO_RLD_DTO_OFFSET_MASK)
/* DMA_CTS_DTO_RLD_RLD Register */
#define DMA_CTS_DTO_RLD_RLD_ADDR_MASK                                  (0xFFFFFFFFU)
#define DMA_CTS_DTO_RLD_RLD_ADDR_SHIFT                                 (0U)
#define DMA_CTS_DTO_RLD_RLD_ADDR(x)                                    (((uint32)(((uint32)(x)) << DMA_CTS_DTO_RLD_RLD_ADDR_SHIFT)) & DMA_CTS_DTO_RLD_RLD_ADDR_MASK)

/* DMA_CTS_CSR Register */
#define DMA_CTS_CSR_TDINT_MASK                                 (0x8000U)
#define DMA_CTS_CSR_TDINT_SHIFT                                (15U)
#define DMA_CTS_CSR_TDINT(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_CSR_TDINT_SHIFT)) & DMA_CTS_CSR_TDINT_MASK)
#define DMA_CTS_CSR_THDINT_MASK                                (0x4000U)
#define DMA_CTS_CSR_THDINT_SHIFT                               (14U)
#define DMA_CTS_CSR_THDINT(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_CSR_THDINT_SHIFT)) & DMA_CTS_CSR_THDINT_MASK)
#define DMA_CTS_CSR_TLKCH_MASK                                 (0xF00U)
#define DMA_CTS_CSR_TLKCH_SHIFT                                (8U)
#define DMA_CTS_CSR_TLKCH(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_CSR_TLKCH_SHIFT)) & DMA_CTS_CSR_TLKCH_MASK)
#define DMA_CTS_CSR_TLKEN_MASK                                 (0x80U)
#define DMA_CTS_CSR_TLKEN_SHIFT                                (7U)
#define DMA_CTS_CSR_TLKEN(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_CSR_TLKEN_SHIFT)) & DMA_CTS_CSR_TLKEN_MASK)
#define DMA_CTS_CSR_RLDEN_MASK                                 (0x40U)
#define DMA_CTS_CSR_RLDEN_SHIFT                                (6U)
#define DMA_CTS_CSR_RLDEN(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_CSR_RLDEN_SHIFT)) & DMA_CTS_CSR_RLDEN_MASK)
#define DMA_CTS_CSR_BWC_MASK                                   (0x30U)
#define DMA_CTS_CSR_BWC_SHIFT                                  (4U)
#define DMA_CTS_CSR_BWC(x)                                     (((uint32)(((uint32)(x)) << DMA_CTS_CSR_BWC_SHIFT)) & DMA_CTS_CSR_BWC_MASK)
#define DMA_CTS_CSR_DREQ_MASK                                  (0x8U)
#define DMA_CTS_CSR_DREQ_SHIFT                                 (3U)
#define DMA_CTS_CSR_DREQ(x)                                    (((uint32)(((uint32)(x)) << DMA_CTS_CSR_DREQ_SHIFT)) & DMA_CTS_CSR_DREQ_MASK)
#define DMA_CTS_CSR_ACTIVE_MASK                                (0x4U)
#define DMA_CTS_CSR_ACTIVE_SHIFT                               (2U)
#define DMA_CTS_CSR_ACTIVE(x)                                  (((uint32)(((uint32)(x)) << DMA_CTS_CSR_ACTIVE_SHIFT)) & DMA_CTS_CSR_ACTIVE_MASK)
#define DMA_CTS_CSR_DONE_MASK                                  (0x2U)
#define DMA_CTS_CSR_DONE_SHIFT                                 (1U)
#define DMA_CTS_CSR_DONE(x)                                    (((uint32)(((uint32)(x)) << DMA_CTS_CSR_DONE_SHIFT)) & DMA_CTS_CSR_DONE_MASK)
#define DMA_CTS_CSR_START_MASK                                 (0x1U)
#define DMA_CTS_CSR_START_SHIFT                                (0U)
#define DMA_CTS_CSR_START(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_CSR_START_SHIFT)) & DMA_CTS_CSR_START_MASK)
/* DMA_CTS_TCNTRV Register */
#define DMA_CTS_TCNTRV_RV_MASK                                 (0xFFFFU)
#define DMA_CTS_TCNTRV_RV_SHIFT                                (0U)
#define DMA_CTS_TCNTRV_RV(x)                                   (((uint32)(((uint32)(x)) << DMA_CTS_TCNTRV_RV_SHIFT)) & DMA_CTS_TCNTRV_RV_MASK)



/**
 * @}
 */ /* end of group DMA_Register_Masks */


/**
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */

#endif /* PSIP_DMA_H */

