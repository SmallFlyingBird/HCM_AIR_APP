/**
*   @file    pSIP_Tmr.h
*   @version
*
*   @brief   AUTOSAR Tmr register map
*   @details Register map for TMR
*
*   @addtogroup TMR_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Tmr
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

#ifndef PSIP_TMR_H
#define PSIP_TMR_H

/* PRQA S 1039 EOF */
/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              TMR REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup TMR_Peripheral_Access_Layer TMR Peripheral Access Layer
 * @{
 */


/** TMR - Size of Registers Arrays */
#define TMR_CH_COUNT           (4)

/* TMR Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 PRS;                                /**< Prescaler Register, offset: 0x0004 */
    uint32 CNT;                                /**< Count Register, offset: 0x0008 */
    uint32 RESERVED0[ 1];                      /**< RESERVED0, offset: 0x000C */
    struct {
        uint32 CTRL;                               /**< Channel Control Register, offset: 0x0010 */
        uint32 INT;                                /**< Channel Interrupt Register, offset: 0x0014 */
        uint32 CMP;                                /**< Channel Compare Register, offset: 0x0018 */
    uint32 RESERVED1[ 1];                      /**< RESERVED1, offset: 0x001C */

    } CH[4];

} TMR_Type, *TMR_MemMapPtr;

/** Number of instances of the TMR module. */
#define TMR_INSTANCE_COUNT                        (1u)

/* TMR0  base address */
#define TMR0_BASE_ADDR32                                   (0x40054000U)
#define TMR0                                               ((volatile TMR_Type *)(TMR0_BASE_ADDR32))

/** Array initializer of TMR peripheral base addresses */
#define TMR_BASE_ADDRS                                     { TMR0_BASE_ADDR32 }
/** Array initializer of TMR peripheral base pointers */
#define TMR_BASE_PTRS                                      { TMR0 }

#define TMR_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Control Register */
#define TMR_PRS_OFFSET32                                   (0x0004U)                    /**< Offset for Prescaler Register */
#define TMR_CNT_OFFSET32                                   (0x0008U)                    /**< Offset for Count Register */
#define TMR_CH_OFFSET32(x)                                 (0x0010U + ((x) * (16U)))    /**< Offset for Channel Control and Status Register */

#define TMR_CH_CTRL_OFFSET32(x)                            (0x0010U + ((x) * (16U)))    /**< Offset for Channel Control Register */
#define TMR_CH_INT_OFFSET32(x)                             (0x0014U + ((x) * (16U)))    /**< Offset for Channel Interrupt Register */
#define TMR_CH_CMP_OFFSET32(x)                             (0x0018U + ((x) * (16U)))    /**< Offset for Channel Compare Register */



/**
 * @addtogroup TMR Register Mask
 * @{
 */
/* TMR_CTRL Register */
#define TMR_CTRL_DBGDIS_MASK                               (0x2U)
#define TMR_CTRL_DBGDIS_SHIFT                              (1U)
#define TMR_CTRL_DBGDIS(x)                                 (((uint32)(((uint32)(x)) << TMR_CTRL_DBGDIS_SHIFT)) & TMR_CTRL_DBGDIS_MASK)
#define TMR_CTRL_TEN_MASK                                  (0x1U)
#define TMR_CTRL_TEN_SHIFT                                 (0U)
#define TMR_CTRL_TEN(x)                                    (((uint32)(((uint32)(x)) << TMR_CTRL_TEN_SHIFT)) & TMR_CTRL_TEN_MASK)
/* TMR_PRS Register */
#define TMR_PRS_PRS_MASK                                   (0xFFU)
#define TMR_PRS_PRS_SHIFT                                  (0U)
#define TMR_PRS_PRS(x)                                     (((uint32)(((uint32)(x)) << TMR_PRS_PRS_SHIFT)) & TMR_PRS_PRS_MASK)
/* TMR_CNT Register */
#define TMR_CNT_CNT_MASK                                   (0xFFFFFFFFU)
#define TMR_CNT_CNT_SHIFT                                  (0U)
#define TMR_CNT_CNT(x)                                     (((uint32)(((uint32)(x)) << TMR_CNT_CNT_SHIFT)) & TMR_CNT_CNT_MASK)
/* TMR_CH_CTRL Register */
#define TMR_CH_CTRL_CHEN_MASK                                 (0x1U)
#define TMR_CH_CTRL_CHEN_SHIFT                                (0U)
#define TMR_CH_CTRL_CHEN(x)                                   (((uint32)(((uint32)(x)) << TMR_CH_CTRL_CHEN_SHIFT)) & TMR_CH_CTRL_CHEN_MASK)
/* TMR_CH_INT Register */
#define TMR_CH_INT_CHIF_MASK                                  (0x1U)
#define TMR_CH_INT_CHIF_SHIFT                                 (0U)
#define TMR_CH_INT_CHIF(x)                                    (((uint32)(((uint32)(x)) << TMR_CH_INT_CHIF_SHIFT)) & TMR_CH_INT_CHIF_MASK)
/* TMR_CH_CMP Register */
#define TMR_CH_CMP_CHCMP_MASK                                 (0xFFFFFFFFU)
#define TMR_CH_CMP_CHCMP_SHIFT                                (0U)
#define TMR_CH_CMP_CHCMP(x)                                   (((uint32)(((uint32)(x)) << TMR_CH_CMP_CHCMP_SHIFT)) & TMR_CH_CMP_CHCMP_MASK)



/**
 * @}
 */ /* end of group TMR_Register_Masks */


/**
 * @}
 */ /* end of group TMR_Peripheral_Access_Layer */

#endif /* PSIP_TMR_H */

