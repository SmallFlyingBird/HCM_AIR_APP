/**
*   @file    pSIP_Gpio.h
*   @version
*
*   @brief   AUTOSAR Gpio register map
*   @details Register map for GPIO
*
*   @addtogroup GPIO_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Gpio
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

#ifndef PSIP_GPIO_H
#define PSIP_GPIO_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              GPIO REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */


/** GPIO - Size of Registers Arrays */
#define GPIO_PCR_COUNT           (32)

/* GPIO Register Layout Typedef */
typedef struct {
    uint32 PDOR;                               /**< Port Data Output Register, offset: 0x0000 */
    uint32 PSOR;                               /**< Port Set Output Register, offset: 0x0004 */
    uint32 PCOR;                               /**< Port Clear Output Register, offset: 0x0008 */
    uint32 PTOR;                               /**< Port Toggle Output Register, offset: 0x000C */
    uint32 PDIR;                               /**< Port Data Input Register, offset: 0x0010 */
    uint32 POER;                               /**< Port Output Enable Register, offset: 0x0014 */
    uint32 PIER;                               /**< Port Input Enable Register, offset: 0x0018 */
    uint32 PIFR;                               /**< Port Interrupt Status Flag Register, offset: 0x001C */
    uint32 RESERVED0[24];                      /**< RESERVED0, offset: 0x0020 */
    uint32 PCR[32];                            /**< Port Control Register, offset: 0x0080 */

} GPIO_Type, *GPIO_MemMapPtr;

/** Number of instances of the GPIO module. */
#define GPIO_INSTANCE_COUNT                        (5u)

/* GPIOA  base address */
#define GPIOA_BASE_ADDR32                                  (0x40011000U)
#define GPIOA                                              ((volatile GPIO_Type *)(GPIOA_BASE_ADDR32))
/* GPIOB  base address */
#define GPIOB_BASE_ADDR32                                  (0x40011100U)
#define GPIOB                                              ((volatile GPIO_Type *)(GPIOB_BASE_ADDR32))
/* GPIOC  base address */
#define GPIOC_BASE_ADDR32                                  (0x40011200U)
#define GPIOC                                              ((volatile GPIO_Type *)(GPIOC_BASE_ADDR32))
/* GPIOD  base address */
#define GPIOD_BASE_ADDR32                                  (0x40011300U)
#define GPIOD                                              ((volatile GPIO_Type *)(GPIOD_BASE_ADDR32))
/* GPIOE  base address */
#define GPIOE_BASE_ADDR32                                  (0x40011400U)
#define GPIOE                                              ((volatile GPIO_Type *)(GPIOE_BASE_ADDR32))

/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                                    { GPIOA_BASE_ADDR32,  GPIOB_BASE_ADDR32,  GPIOC_BASE_ADDR32,  GPIOD_BASE_ADDR32,  GPIOE_BASE_ADDR32 }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                                     { GPIOA,  GPIOB,  GPIOC,  GPIOD,  GPIOE }

#define GPIO_PDOR_OFFSET32                                 (0x0000U)                    /**< Offset for Port Data Output Register */
#define GPIO_PSOR_OFFSET32                                 (0x0004U)                    /**< Offset for Port Set Output Register */
#define GPIO_PCOR_OFFSET32                                 (0x0008U)                    /**< Offset for Port Clear Output Register */
#define GPIO_PTOR_OFFSET32                                 (0x000CU)                    /**< Offset for Port Toggle Output Register */
#define GPIO_PDIR_OFFSET32                                 (0x0010U)                    /**< Offset for Port Data Input Register */
#define GPIO_POER_OFFSET32                                 (0x0014U)                    /**< Offset for Port Output Enable Register */
#define GPIO_PIER_OFFSET32                                 (0x0018U)                    /**< Offset for Port Input Enable Register */
#define GPIO_PIFR_OFFSET32                                 (0x001CU)                    /**< Offset for Port Interrupt Status Flag Register */
#define GPIO_PCR_OFFSET32(x)                               (0x0080U + ((x) * (4U)))     /**< Offset for Port Control Register */

#define GPIO_BASE_ADDR32(port)                             ((uint32)0x40011000U + ((uint32)(port) * (uint32)0x00000100))
#define GPIO_PDOR_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PDOR_OFFSET32))
#define GPIO_PSOR_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PSOR_OFFSET32))
#define GPIO_PCOR_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PCOR_OFFSET32))
#define GPIO_PTOR_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PTOR_OFFSET32))
#define GPIO_PDIR_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PDIR_OFFSET32))
#define GPIO_POER_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_POER_OFFSET32))
#define GPIO_PIER_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PIER_OFFSET32))
#define GPIO_PIFR_ADDR32(port)                             ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PIFR_OFFSET32))
#define GPIO_PCR_ADDR32(port, pin)                         ((uint32)(GPIO_BASE_ADDR32(port) + GPIO_PCR_OFFSET32(pin)))

/**
 * @addtogroup GPIO Register Mask
 * @{
 */
/* GPIO_PDOR Register */
#define GPIO_PDOR_PDO_MASK                                  (0xFFFFFFFFU)
#define GPIO_PDOR_PDO_SHIFT                                 (0U)
#define GPIO_PDOR_PDO(x)                                    (((uint32)(((uint32)(x)) << GPIO_PDOR_PDO_SHIFT)) & GPIO_PDOR_PDO_MASK)
/* GPIO_PSOR Register */
#define GPIO_PSOR_PSO_MASK                                  (0xFFFFFFFFU)
#define GPIO_PSOR_PSO_SHIFT                                 (0U)
#define GPIO_PSOR_PSO(x)                                    (((uint32)(((uint32)(x)) << GPIO_PSOR_PSO_SHIFT)) & GPIO_PSOR_PSO_MASK)
/* GPIO_PCOR Register */
#define GPIO_PCOR_PCO_MASK                                  (0xFFFFFFFFU)
#define GPIO_PCOR_PCO_SHIFT                                 (0U)
#define GPIO_PCOR_PCO(x)                                    (((uint32)(((uint32)(x)) << GPIO_PCOR_PCO_SHIFT)) & GPIO_PCOR_PCO_MASK)
/* GPIO_PTOR Register */
#define GPIO_PTOR_PTO_MASK                                  (0xFFFFFFFFU)
#define GPIO_PTOR_PTO_SHIFT                                 (0U)
#define GPIO_PTOR_PTO(x)                                    (((uint32)(((uint32)(x)) << GPIO_PTOR_PTO_SHIFT)) & GPIO_PTOR_PTO_MASK)
/* GPIO_PDIR Register */
#define GPIO_PDIR_PDI_MASK                                  (0xFFFFFFFFU)
#define GPIO_PDIR_PDI_SHIFT                                 (0U)
#define GPIO_PDIR_PDI(x)                                    (((uint32)(((uint32)(x)) << GPIO_PDIR_PDI_SHIFT)) & GPIO_PDIR_PDI_MASK)
/* GPIO_POER Register */
#define GPIO_POER_POE_MASK                                  (0xFFFFFFFFU)
#define GPIO_POER_POE_SHIFT                                 (0U)
#define GPIO_POER_POE(x)                                    (((uint32)(((uint32)(x)) << GPIO_POER_POE_SHIFT)) & GPIO_POER_POE_MASK)
/* GPIO_PIER Register */
#define GPIO_PIER_PIE_MASK                                  (0xFFFFFFFFU)
#define GPIO_PIER_PIE_SHIFT                                 (0U)
#define GPIO_PIER_PIE(x)                                    (((uint32)(((uint32)(x)) << GPIO_PIER_PIE_SHIFT)) & GPIO_PIER_PIE_MASK)
/* GPIO_PIFR Register */
#define GPIO_PIFR_PIF_MASK                                  (0xFFFFFFFFU)
#define GPIO_PIFR_PIF_SHIFT                                 (0U)
#define GPIO_PIFR_PIF(x)                                    (((uint32)(((uint32)(x)) << GPIO_PIFR_PIF_SHIFT)) & GPIO_PIFR_PIF_MASK)
/* GPIO_PCR Register */
#define GPIO_PCR_DFW_WIDTH                                  (5)
#define GPIO_PCR_DFW_MASK                                   (0x1F000000U)
#define GPIO_PCR_DFW_SHIFT                                  (24U)
#define GPIO_PCR_DFW(x)                                     (((uint32)(((uint32)(x)) << GPIO_PCR_DFW_SHIFT)) & GPIO_PCR_DFW_MASK)
#define GPIO_PCR_DFE_MASK                                   (0x10000U)
#define GPIO_PCR_DFE_SHIFT                                  (16U)
#define GPIO_PCR_DFE(x)                                     (((uint32)(((uint32)(x)) << GPIO_PCR_DFE_SHIFT)) & GPIO_PCR_DFE_MASK)
#define GPIO_PCR_INVE_MASK                                  (0x10U)
#define GPIO_PCR_INVE_SHIFT                                 (4U)
#define GPIO_PCR_INVE(x)                                    (((uint32)(((uint32)(x)) << GPIO_PCR_INVE_SHIFT)) & GPIO_PCR_INVE_MASK)
#define GPIO_PCR_IRQC_MASK                                  (0xFU)
#define GPIO_PCR_IRQC_SHIFT                                 (0U)
#define GPIO_PCR_IRQC(x)                                    (((uint32)(((uint32)(x)) << GPIO_PCR_IRQC_SHIFT)) & GPIO_PCR_IRQC_MASK)


/**
 * @}
 */ /* end of group GPIO_Register_Masks */


/**
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */

#endif /* PSIP_GPIO_H */

