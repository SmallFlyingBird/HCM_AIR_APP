/**
*   @file    pSIP_Ewdg.h
*   @version
*
*   @brief   AUTOSAR Ewdg register map
*   @details Register map for EWDG
*
*   @addtogroup EWDG_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Ewdg
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

#ifndef PSIP_EWDG_H
#define PSIP_EWDG_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              EWDG REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup EWDG_Peripheral_Access_Layer EWDG Peripheral Access Layer
 * @{
 */


/** EWDG - Size of Registers Arrays */

/* EWDG Register Layout Typedef */
typedef struct {
    uint32 SERV;                               /**< Service Code Register, offset: 0x0000 */
    uint32 CMPL;                               /**< Compare Low Register, offset: 0x0004 */
    uint32 CMPH;                               /**< Compare High Register, offset: 0x0008 */
    uint32 CTRL;                               /**< Control Register, offset: 0x000C */
    uint32 CLK_CTRL;                           /**< Clock Control Register, offset: 0x0010 */

} EWDG_Type, *EWDG_MemMapPtr;

/** Number of instances of the EWDG module. */
#define EWDG_INSTANCE_COUNT                        (1u)

/* EWDG base address */
#define EWDG_BASE_ADDR32                                  (0x4006B000U)
#define EWDG                                              ((volatile EWDG_Type *)(EWDG_BASE_ADDR32))

/** Array initializer of EWDG peripheral base addresses */
#define EWDG_BASE_ADDRS                                    { EWDG_BASE_ADDR32 }
/** Array initializer of EWDG peripheral base pointers */
#define EWDG_BASE_PTRS                                     { EWDG }

#define EWDG_SERV_OFFSET32                                 (0x0000U)                    /**< Offset for Service Code Register */
#define EWDG_CMPL_OFFSET32                                 (0x0004U)                    /**< Offset for Compare Low Register */
#define EWDG_CMPH_OFFSET32                                 (0x0008U)                    /**< Offset for Compare High Register */
#define EWDG_CTRL_OFFSET32                                 (0x000CU)                    /**< Offset for Control Register */
#define EWDG_CLK_CTRL_OFFSET32                             (0x0010U)                    /**< Offset for Clock Control Register */


/**
 * @addtogroup EWDG Register Mask
 * @{
 */
/* EWDG_SERV Register */
#define EWDG_SERV_SERVICE_MASK                              (0xFFU)
#define EWDG_SERV_SERVICE_SHIFT                             (0U)
#define EWDG_SERV_SERVICE(x)                                (((uint32)(((uint32)(x)) << EWDG_SERV_SERVICE_SHIFT)) & EWDG_SERV_SERVICE_MASK)
/* EWDG_CMPL Register */
#define EWDG_CMPL_COMPAREL_MASK                             (0xFFU)
#define EWDG_CMPL_COMPAREL_SHIFT                            (0U)
#define EWDG_CMPL_COMPAREL(x)                               (((uint32)(((uint32)(x)) << EWDG_CMPL_COMPAREL_SHIFT)) & EWDG_CMPL_COMPAREL_MASK)
/* EWDG_CMPH Register */
#define EWDG_CMPH_COMPAREH_MASK                             (0xFFU)
#define EWDG_CMPH_COMPAREH_SHIFT                            (0U)
#define EWDG_CMPH_COMPAREH(x)                               (((uint32)(((uint32)(x)) << EWDG_CMPH_COMPAREH_SHIFT)) & EWDG_CMPH_COMPAREH_MASK)
/* EWDG_CTRL Register */
#define EWDG_CTRL_INTEN_MASK                                (0x8U)
#define EWDG_CTRL_INTEN_SHIFT                               (3U)
#define EWDG_CTRL_INTEN(x)                                  (((uint32)(((uint32)(x)) << EWDG_CTRL_INTEN_SHIFT)) & EWDG_CTRL_INTEN_MASK)
#define EWDG_CTRL_INEN_MASK                                 (0x4U)
#define EWDG_CTRL_INEN_SHIFT                                (2U)
#define EWDG_CTRL_INEN(x)                                   (((uint32)(((uint32)(x)) << EWDG_CTRL_INEN_SHIFT)) & EWDG_CTRL_INEN_MASK)
#define EWDG_CTRL_POLARITY_MASK                             (0x2U)
#define EWDG_CTRL_POLARITY_SHIFT                            (1U)
#define EWDG_CTRL_POLARITY(x)                               (((uint32)(((uint32)(x)) << EWDG_CTRL_POLARITY_SHIFT)) & EWDG_CTRL_POLARITY_MASK)
#define EWDG_CTRL_EN_MASK                                   (0x1U)
#define EWDG_CTRL_EN_SHIFT                                  (0U)
#define EWDG_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << EWDG_CTRL_EN_SHIFT)) & EWDG_CTRL_EN_MASK)
/* EWDG_CLK_CTRL Register */
#define EWDG_CLK_CTRL_PRESCALER_MASK                        (0xFFU)
#define EWDG_CLK_CTRL_PRESCALER_SHIFT                       (0U)
#define EWDG_CLK_CTRL_PRESCALER(x)                          (((uint32)(((uint32)(x)) << EWDG_CLK_CTRL_PRESCALER_SHIFT)) & EWDG_CLK_CTRL_PRESCALER_MASK)


/**
 * @}
 */ /* end of group EWDG_Register_Masks */


/**
 * @}
 */ /* end of group EWDG_Peripheral_Access_Layer */

#endif /* PSIP_EWDG_H */

