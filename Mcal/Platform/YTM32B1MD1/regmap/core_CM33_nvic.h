/**
*   @file    core_CM33_nvic.h
*   @version
*
*   @brief   AUTOSAR CM33_nvic register map
*   @details Register map for CM33_NVIC
*
*   @addtogroup CM33_NVIC_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : core_CM33_nvic
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

#ifndef CORE_CM33_NVIC_H
#define CORE_CM33_NVIC_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CM33_NVIC REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CM33_NVIC_Peripheral_Access_Layer CM33_NVIC Peripheral Access Layer
 * @{
 */


/** CM33_NVIC - Size of Registers Arrays */
#define CM33_NVIC_ISER_COUNT           (8)
#define CM33_NVIC_ICER_COUNT           (8)
#define CM33_NVIC_ISPR_COUNT           (8)
#define CM33_NVIC_ICPR_COUNT           (8)
#define CM33_NVIC_IABR_COUNT           (8)
#define CM33_NVIC_IPR_COUNT           (240)

/* CM33_NVIC Register Layout Typedef */
typedef struct {
    uint32 ISER[ 8];                           /**< Interrupt Set Enable Register, offset: 0x0000 */
    uint32 Reserved0[24];                      /**< Reserved0, offset: 0x0004 */
    uint32 ICER[ 8];                           /**< Interrupt Clear Enable Register, offset: 0x0080 */
    uint32 Reserved1[24];                      /**< Reserved1, offset: 0x0004 */
    uint32 ISPR[ 8];                           /**< Interrupt Set Pending Register, offset: 0x0100 */
    uint32 Reserved2[24];                      /**< Reserved2, offset: 0x0004 */
    uint32 ICPR[ 8];                           /**< Interrupt Clear Pending Register, offset: 0x0180 */
    uint32 Reserved3[24];                      /**< Reserved3, offset: 0x0004 */
    uint32 IABR[ 8];                           /**< Interrupt Active bit Register, offset: 0x0180 */
    uint32 Reserved4[56];                      /**< Reserved4, offset: 0x0004 */
    uint8  IPR[240];                           /**< Interrupt Priority Register, offset: 0x0300 */
    uint32 Reserved5[644];                     /**< Reserved5, offset: 0x0004 */
    uint32 STIR;                               /**< Software Trigger Interrupt Register, offset: 0x0E00 */

} CM33_NVIC_Type, *CM33_NVIC_MemMapPtr;

/** Number of instances of the CM33_NVIC module. */
#define CM33_NVIC_INSTANCE_COUNT                        (1u)

/* CM33_NVIC base address */
#define CM33_NVIC_BASE_ADDR32                              (0xE000E100U)
#define CM33_NVIC                                          ((volatile CM33_NVIC_Type *)(CM33_NVIC_BASE_ADDR32))

/** Array initializer of CM33_NVIC peripheral base addresses */
#define CM33_NVIC_BASE_ADDRS                                { CM33_NVIC_BASE_ADDR32 }
/** Array initializer of CM33_NVIC peripheral base pointers */
#define CM33_NVIC_BASE_PTRS                                 { CM33_NVIC }

#define CM33_NVIC_ISER_OFFSET32(x)                          (0x0000U + ((x) * (4U)))     /**< Offset for Interrupt Set Enable Register */
#define CM33_NVIC_ICER_OFFSET32(x)                          (0x0080U + ((x) * (4U)))     /**< Offset for Interrupt Clear Enable Register */
#define CM33_NVIC_ISPR_OFFSET32(x)                          (0x0100U + ((x) * (4U)))     /**< Offset for Interrupt Set Pending Register */
#define CM33_NVIC_ICPR_OFFSET32(x)                          (0x0180U + ((x) * (4U)))     /**< Offset for Interrupt Clear Pending Register */
#define CM33_NVIC_IABR_OFFSET32(x)                          (0x0180U + ((x) * (4U)))     /**< Offset for Interrupt Active bit Register */
#define CM33_NVIC_IPR_OFFSET32(x)                           (0x0300U + ((x) * (4U)))     /**< Offset for Interrupt Priority Register */
#define CM33_NVIC_STIR_OFFSET32                             (0x0E00U)                    /**< Offset for Software Trigger Interrupt Register */


/**
 * @addtogroup CM33_NVIC Register Mask
 * @{
 */
/* CM33_NVIC_ISER Register */
#define CM33_NVIC_ISER_ISER_MASK                                 (0xFFFFFFFFU)
#define CM33_NVIC_ISER_ISER_SHIFT                                (0U)
#define CM33_NVIC_ISER_ISER(x)                                   (((uint32)(((uint32)(x)) << CM33_NVIC_ISER_ISER_SHIFT)) & CM33_NVIC_ISER_ISER_MASK)
/* CM33_NVIC_ICER Register */
#define CM33_NVIC_ICER_ICER_MASK                                 (0xFFFFFFFFU)
#define CM33_NVIC_ICER_ICER_SHIFT                                (0U)
#define CM33_NVIC_ICER_ICER(x)                                   (((uint32)(((uint32)(x)) << CM33_NVIC_ICER_ICER_SHIFT)) & CM33_NVIC_ICER_ICER_MASK)
/* CM33_NVIC_ISPR Register */
#define CM33_NVIC_ISPR_ISPR_MASK                                 (0xFFFFFFFFU)
#define CM33_NVIC_ISPR_ISPR_SHIFT                                (0U)
#define CM33_NVIC_ISPR_ISPR(x)                                   (((uint32)(((uint32)(x)) << CM33_NVIC_ISPR_ISPR_SHIFT)) & CM33_NVIC_ISPR_ISPR_MASK)
/* CM33_NVIC_ICPR Register */
#define CM33_NVIC_ICPR_ICPR_MASK                                 (0xFFFFFFFFU)
#define CM33_NVIC_ICPR_ICPR_SHIFT                                (0U)
#define CM33_NVIC_ICPR_ICPR(x)                                   (((uint32)(((uint32)(x)) << CM33_NVIC_ICPR_ICPR_SHIFT)) & CM33_NVIC_ICPR_ICPR_MASK)
/* CM33_NVIC_IABR Register */
#define CM33_NVIC_IABR_ACTIVE_MASK                               (0xFFFFFFFFU)
#define CM33_NVIC_IABR_ACTIVE_SHIFT                              (0U)
#define CM33_NVIC_IABR_ACTIVE(x)                                 (((uint32)(((uint32)(x)) << CM33_NVIC_IABR_ACTIVE_SHIFT)) & CM33_NVIC_IABR_ACTIVE_MASK)
/* CM33_NVIC_IPR Register */
#define CM33_NVIC_IPR_IPR_MASK                                   (0xFFFFFFFFU)
#define CM33_NVIC_IPR_IPR_SHIFT                                  (0U)
#define CM33_NVIC_IPR_IPR(x)                                     (((uint32)(((uint32)(x)) << CM33_NVIC_IPR_IPR_SHIFT)) & CM33_NVIC_IPR_IPR_MASK)
/* CM33_NVIC_STIR Register */
#define CM33_NVIC_STIR_INTID_WIDTH                               (9)
#define CM33_NVIC_STIR_INTID_MASK                                (0x1FFU)
#define CM33_NVIC_STIR_INTID_SHIFT                               (0U)
#define CM33_NVIC_STIR_INTID(x)                                  (((uint32)(((uint32)(x)) << CM33_NVIC_STIR_INTID_SHIFT)) & CM33_NVIC_STIR_INTID_MASK)


/**
 * @}
 */ /* end of group CM33_NVIC_Register_Masks */


/**
 * @}
 */ /* end of group CM33_NVIC_Peripheral_Access_Layer */

#endif /* CORE_CM33_NVIC_H */

