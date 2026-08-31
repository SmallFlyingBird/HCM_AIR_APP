/**
*   @file    pSIP_Crc.h
*   @version
*
*   @brief   AUTOSAR Crc register map
*   @details Register map for CRC
*
*   @addtogroup CRC_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Crc
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

#ifndef PSIP_CRC_H
#define PSIP_CRC_H

/*
* @page misra_violations MISRA-C:2012 violations list
* PRQA S 0750 Rule 19.2: The union keyword should not be used.
*/
/* MR12 RULE 19.2 VIOLATION: The CRC register - DATA is defined as unions for
*                            control and configuration access.
*/
/* PRQA S 0750 EOF */

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CRC REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */


/** CRC - Size of Registers Arrays */

/* CRC Register Layout Typedef */
typedef struct
{
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 INIT;                               /**< Initial Seed Register, offset: 0x0004 */
    union
    {
        uint32 IN32;                               /**< Data in 32 bits, offset: 0x0008 */
        uint16 IN16;                               /**< Data in 16 bits, offset: 0x0008 */
        uint8 IN8;                                /**< Data in 8 Bits, offset: 0x0008 */

    } DATA;
    uint32 RESULT;                             /**< Result Register, offset: 0x000C */

} CRC_Type, *CRC_MemMapPtr;

/** Number of instances of the CRC module. */
#define CRC_INSTANCE_COUNT                        (1u)

/* CRC0  base address */
#define CRC0_BASE_ADDR32                                   (0x40065000U)
#define CRC0                                               ((volatile CRC_Type *)(CRC0_BASE_ADDR32))

/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                                     { CRC0_BASE_ADDR32 }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                                      { CRC0 }

#define CRC_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Control Register */
#define CRC_INIT_OFFSET32                                  (0x0004U)                    /**< Offset for Initial Seed Register */
#define CRC_DATA_OFFSET32                                  (0x0008U)                    /**< Offset for DATA Register */
#define CRC_DATA_IN32_OFFSET32                             (0x0008U)                    /**< Offset for Data in 32 bits */
#define CRC_DATA_IN16_OFFSET16                             (0x0008U)                    /**< Offset for Data in 16 bits */
#define CRC_DATA_IN8_OFFSET8                              (0x0008U)                    /**< Offset for Data in 8 Bits */


#define CRC_RESULT_OFFSET32                                (0x000CU)                    /**< Offset for Result Register */


/**
 * @addtogroup CRC Register Mask
 * @{
 */
/* CRC_CTRL Register */
#define CRC_CTRL_INV_OUT_MASK                              (0x40U)
#define CRC_CTRL_INV_OUT_SHIFT                             (6U)
#define CRC_CTRL_INV_OUT(x)                                (((uint32)(((uint32)(x)) << CRC_CTRL_INV_OUT_SHIFT)) & CRC_CTRL_INV_OUT_MASK)
#define CRC_CTRL_SWAP_OUT_MASK                             (0x20U)
#define CRC_CTRL_SWAP_OUT_SHIFT                            (5U)
#define CRC_CTRL_SWAP_OUT(x)                               (((uint32)(((uint32)(x)) << CRC_CTRL_SWAP_OUT_SHIFT)) & CRC_CTRL_SWAP_OUT_MASK)
#define CRC_CTRL_SWAP_IN_MASK                              (0x10U)
#define CRC_CTRL_SWAP_IN_SHIFT                             (4U)
#define CRC_CTRL_SWAP_IN(x)                                (((uint32)(((uint32)(x)) << CRC_CTRL_SWAP_IN_SHIFT)) & CRC_CTRL_SWAP_IN_MASK)
#define CRC_CTRL_MODE_MASK                                 (0x3U)
#define CRC_CTRL_MODE_SHIFT                                (0U)
#define CRC_CTRL_MODE(x)                                   (((uint32)(((uint32)(x)) << CRC_CTRL_MODE_SHIFT)) & CRC_CTRL_MODE_MASK)
/* CRC_INIT Register */
#define CRC_INIT_SEED_MASK                                 (0xFFFFFFFFU)
#define CRC_INIT_SEED_SHIFT                                (0U)
#define CRC_INIT_SEED(x)                                   (((uint32)(((uint32)(x)) << CRC_INIT_SEED_SHIFT)) & CRC_INIT_SEED_MASK)
/* CRC_DATA_IN32 Register */
#define CRC_DATA_IN32_DATA_MASK                                 (0xFFFFFFFFU)
#define CRC_DATA_IN32_DATA_SHIFT                                (0U)
#define CRC_DATA_IN32_DATA(x)                                   (((uint32)(((uint32)(x)) << CRC_DATA_IN32_DATA_SHIFT)) & CRC_DATA_IN32_DATA_MASK)
/* CRC_DATA_IN16 Register */
#define CRC_DATA_IN16_DATA_MASK                                 (0xFFFFU)
#define CRC_DATA_IN16_DATA_SHIFT                                (0U)
#define CRC_DATA_IN16_DATA(x)                                   (((uint32)(((uint32)(x)) << CRC_DATA_IN16_DATA_SHIFT)) & CRC_DATA_IN16_DATA_MASK)
/* CRC_DATA_IN8 Register */
#define CRC_DATA_IN8_DATA_MASK                                  (0xFFU)
#define CRC_DATA_IN8_DATA_SHIFT                                 (0U)
#define CRC_DATA_IN8_DATA(x)                                    (((uint32)(((uint32)(x)) << CRC_DATA_IN8_DATA_SHIFT)) & CRC_DATA_IN8_DATA_MASK)

/* CRC_RESULT Register */
#define CRC_RESULT_RESULT_MASK                             (0xFFFFFFFFU)
#define CRC_RESULT_RESULT_SHIFT                            (0U)
#define CRC_RESULT_RESULT(x)                               (((uint32)(((uint32)(x)) << CRC_RESULT_RESULT_SHIFT)) & CRC_RESULT_RESULT_MASK)


/**
 * @}
 */ /* end of group CRC_Register_Masks */


/**
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */

#endif /* PSIP_CRC_H */

