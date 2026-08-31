/**
*   @file    pSIP_Pcu.h
*   @version
*
*   @brief   AUTOSAR Pcu register map
*   @details Register map for PCU
*
*   @addtogroup PCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Pcu
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

#ifndef PSIP_PCU_H
#define PSIP_PCU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              PCU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup PCU_Peripheral_Access_Layer PCU Peripheral Access Layer
 * @{
 */


/** PCU - Size of Registers Arrays */

/* PCU Register Layout Typedef */
typedef struct {
    uint32 SSTS;                               /**< Sticky Status Register, offset: 0x0000 */
    uint32 STS;                                /**< Status Register, offset: 0x0004 */
    uint32 INTE;                               /**< Interrupt Register, offset: 0x0008 */
    uint32 CTRL;                               /**< Control Register, offset: 0x000C */
    uint32 RESERVED_4;                         /**< RESERVED_4, offset: 0x0010 */
    uint32 RESERVED_5;                         /**< RESERVED_5, offset: 0x0014 */
    uint32 RESERVED_6;                         /**< RESERVED_6, offset: 0x0018 */
    uint32 RESERVED_7;                         /**< RESERVED_7, offset: 0x001C */

} PCU_Type, *PCU_MemMapPtr;

/** Number of instances of the PCU module. */
#define PCU_INSTANCE_COUNT                        (1u)

/* PCU base address */
#define PCU_BASE_ADDR32                                   (0x4007E000U)
#define PCU                                               ((volatile PCU_Type *)(PCU_BASE_ADDR32))

/** Array initializer of PCU peripheral base addresses */
#define PCU_BASE_ADDRS                                     { PCU_BASE_ADDR32 }
/** Array initializer of PCU peripheral base pointers */
#define PCU_BASE_PTRS                                      { PCU }

#define PCU_SSTS_OFFSET32                                  (0x0000U)                    /**< Offset for Sticky Status Register */
#define PCU_STS_OFFSET32                                   (0x0004U)                    /**< Offset for Status Register */
#define PCU_INTE_OFFSET32                                  (0x0008U)                    /**< Offset for Interrupt Register */
#define PCU_CTRL_OFFSET32                                  (0x000CU)                    /**< Offset for Control Register */


/**
 * @addtogroup PCU Register Mask
 * @{
 */
/* PCU_SSTS Register */
#define PCU_SSTS_PORF_MASK                                 (0x80000000U)
#define PCU_SSTS_PORF_SHIFT                                (31U)
#define PCU_SSTS_PORF(x)                                   (((uint32)(((uint32)(x)) << PCU_SSTS_PORF_SHIFT)) & PCU_SSTS_PORF_MASK)
#define PCU_SSTS_GNG11F_MASK                               (0x800000U)
#define PCU_SSTS_GNG11F_SHIFT                              (23U)
#define PCU_SSTS_GNG11F(x)                                 (((uint32)(((uint32)(x)) << PCU_SSTS_GNG11F_SHIFT)) & PCU_SSTS_GNG11F_MASK)
#define PCU_SSTS_HVD11F_MASK                               (0x80000U)
#define PCU_SSTS_HVD11F_SHIFT                              (19U)
#define PCU_SSTS_HVD11F(x)                                 (((uint32)(((uint32)(x)) << PCU_SSTS_HVD11F_SHIFT)) & PCU_SSTS_HVD11F_MASK)
#define PCU_SSTS_GNG25F_MASK                               (0x8000U)
#define PCU_SSTS_GNG25F_SHIFT                              (15U)
#define PCU_SSTS_GNG25F(x)                                 (((uint32)(((uint32)(x)) << PCU_SSTS_GNG25F_SHIFT)) & PCU_SSTS_GNG25F_MASK)
#define PCU_SSTS_HVD25F_MASK                               (0x800U)
#define PCU_SSTS_HVD25F_SHIFT                              (11U)
#define PCU_SSTS_HVD25F(x)                                 (((uint32)(((uint32)(x)) << PCU_SSTS_HVD25F_SHIFT)) & PCU_SSTS_HVD25F_MASK)
#define PCU_SSTS_HVD50F_MASK                               (0x8U)
#define PCU_SSTS_HVD50F_SHIFT                              (3U)
#define PCU_SSTS_HVD50F(x)                                 (((uint32)(((uint32)(x)) << PCU_SSTS_HVD50F_SHIFT)) & PCU_SSTS_HVD50F_MASK)
/* PCU_STS Register */
#define PCU_STS_HVD11S_MASK                                (0x80000U)
#define PCU_STS_HVD11S_SHIFT                               (19U)
#define PCU_STS_HVD11S(x)                                  (((uint32)(((uint32)(x)) << PCU_STS_HVD11S_SHIFT)) & PCU_STS_HVD11S_MASK)
#define PCU_STS_HVD25S_MASK                                (0x800U)
#define PCU_STS_HVD25S_SHIFT                               (11U)
#define PCU_STS_HVD25S(x)                                  (((uint32)(((uint32)(x)) << PCU_STS_HVD25S_SHIFT)) & PCU_STS_HVD25S_MASK)
#define PCU_STS_HVD50S_MASK                                (0x8U)
#define PCU_STS_HVD50S_SHIFT                               (3U)
#define PCU_STS_HVD50S(x)                                  (((uint32)(((uint32)(x)) << PCU_STS_HVD50S_SHIFT)) & PCU_STS_HVD50S_MASK)
/* PCU_INTE Register */
#define PCU_INTE_HVD11IE_MASK                              (0x80000U)
#define PCU_INTE_HVD11IE_SHIFT                             (19U)
#define PCU_INTE_HVD11IE(x)                                (((uint32)(((uint32)(x)) << PCU_INTE_HVD11IE_SHIFT)) & PCU_INTE_HVD11IE_MASK)
#define PCU_INTE_HVD25IE_MASK                              (0x800U)
#define PCU_INTE_HVD25IE_SHIFT                             (11U)
#define PCU_INTE_HVD25IE(x)                                (((uint32)(((uint32)(x)) << PCU_INTE_HVD25IE_SHIFT)) & PCU_INTE_HVD25IE_MASK)
#define PCU_INTE_HVD50IE_MASK                              (0x8U)
#define PCU_INTE_HVD50IE_SHIFT                             (3U)
#define PCU_INTE_HVD50IE(x)                                (((uint32)(((uint32)(x)) << PCU_INTE_HVD50IE_SHIFT)) & PCU_INTE_HVD50IE_MASK)
/* PCU_CTRL Register */
#define PCU_CTRL_HVDRE_MASK                                (0x8000U)
#define PCU_CTRL_HVDRE_SHIFT                               (15U)
#define PCU_CTRL_HVDRE(x)                                  (((uint32)(((uint32)(x)) << PCU_CTRL_HVDRE_SHIFT)) & PCU_CTRL_HVDRE_MASK)
#define PCU_CTRL_FASTREC_MASK                              (0x100U)
#define PCU_CTRL_FASTREC_SHIFT                             (8U)
#define PCU_CTRL_FASTREC(x)                                (((uint32)(((uint32)(x)) << PCU_CTRL_FASTREC_SHIFT)) & PCU_CTRL_FASTREC_MASK)
#define PCU_CTRL_PKE_MASK                                  (0x80U)
#define PCU_CTRL_PKE_SHIFT                                 (7U)
#define PCU_CTRL_PKE(x)                                    (((uint32)(((uint32)(x)) << PCU_CTRL_PKE_SHIFT)) & PCU_CTRL_PKE_MASK)
#define PCU_CTRL_STANDBYEN_MASK                            (0x2U)
#define PCU_CTRL_STANDBYEN_SHIFT                           (1U)
#define PCU_CTRL_STANDBYEN(x)                              (((uint32)(((uint32)(x)) << PCU_CTRL_STANDBYEN_SHIFT)) & PCU_CTRL_STANDBYEN_MASK)
#define PCU_CTRL_RPMEN_MASK                                (0x1U)
#define PCU_CTRL_RPMEN_SHIFT                               (0U)
#define PCU_CTRL_RPMEN(x)                                  (((uint32)(((uint32)(x)) << PCU_CTRL_RPMEN_SHIFT)) & PCU_CTRL_RPMEN_MASK)


/**
 * @}
 */ /* end of group PCU_Register_Masks */


/**
 * @}
 */ /* end of group PCU_Peripheral_Access_Layer */

#endif /* PSIP_PCU_H */

