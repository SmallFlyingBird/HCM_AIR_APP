/**
*   @file    pSIP_Tmu.h
*   @version
*
*   @brief   AUTOSAR Tmu register map
*   @details Register map for TMU
*
*   @addtogroup TMU_MODULE
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

#ifndef PSIP_TMU_H
#define PSIP_TMU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              TMU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup TMU_Peripheral_Access_Layer TMU Peripheral Access Layer
 * @{
 */


/** TMU - Size of Registers Arrays */
#define TMU_MUX_COUNT           (16)

/* TMU Register Layout Typedef */
typedef struct {
    uint32 MUX[16];                            /**< MUX, offset: 0x0000 */

} TMU_Type, *TMU_MemMapPtr;

/** Number of instances of the TMU module. */
#define TMU_INSTANCE_COUNT                        (1u)

/* TMU base address */
#define TMU_BASE_ADDR32                                   (0x40048000U)
#define TMU                                               ((volatile TMU_Type *)(TMU_BASE_ADDR32))

/** Array initializer of TMU peripheral base addresses */
#define TMU_BASE_ADDRS                                     { TMU_BASE_ADDR32 }
/** Array initializer of TMU peripheral base pointers */
#define TMU_BASE_PTRS                                      { TMU }

#define TMU_MUX_OFFSET32(x)                                (0x0000U + ((x) * (4U)))     /**< Offset for MUX */


/**
 * @addtogroup TMU Register Mask
 * @{
 */
/* TMU_MUX Register */
#define TMU_MUX_LOCK_MASK                                  (0x80000000U)
#define TMU_MUX_LOCK_SHIFT                                 (31U)
#define TMU_MUX_LOCK(x)                                    (((uint32)(((uint32)(x)) << TMU_MUX_LOCK_SHIFT)) & TMU_MUX_LOCK_MASK)
#define TMU_MUX_SEL3_WIDTH                                 (6)
#define TMU_MUX_SEL3_MASK                                  (0x3F000000U)
#define TMU_MUX_SEL3_SHIFT                                 (24U)
#define TMU_MUX_SEL3(x)                                    (((uint32)(((uint32)(x)) << TMU_MUX_SEL3_SHIFT)) & TMU_MUX_SEL3_MASK)
#define TMU_MUX_SEL2_WIDTH                                 (6)
#define TMU_MUX_SEL2_MASK                                  (0x3F0000U)
#define TMU_MUX_SEL2_SHIFT                                 (16U)
#define TMU_MUX_SEL2(x)                                    (((uint32)(((uint32)(x)) << TMU_MUX_SEL2_SHIFT)) & TMU_MUX_SEL2_MASK)
#define TMU_MUX_SEL1_WIDTH                                 (6)
#define TMU_MUX_SEL1_MASK                                  (0x3F00U)
#define TMU_MUX_SEL1_SHIFT                                 (8U)
#define TMU_MUX_SEL1(x)                                    (((uint32)(((uint32)(x)) << TMU_MUX_SEL1_SHIFT)) & TMU_MUX_SEL1_MASK)
#define TMU_MUX_SEL0_WIDTH                                 (6)
#define TMU_MUX_SEL0_MASK                                  (0x3FU)
#define TMU_MUX_SEL0_SHIFT                                 (0U)
#define TMU_MUX_SEL0(x)                                    (((uint32)(((uint32)(x)) << TMU_MUX_SEL0_SHIFT)) & TMU_MUX_SEL0_MASK)


/**
 * @}
 */ /* end of group TMU_Register_Masks */


/**
 * @}
 */ /* end of group TMU_Peripheral_Access_Layer */

#endif /* PSIP_TMU_H */

