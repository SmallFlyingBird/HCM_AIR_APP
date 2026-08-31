/**
*   @file    pSIP_Hcu.h
*   @version
*
*   @brief   AUTOSAR Hcu register map
*   @details Register map for HCU
*
*   @addtogroup HCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Hcu
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

#ifndef PSIP_HCU_H
#define PSIP_HCU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              HCU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup HCU_Peripheral_Access_Layer HCU Peripheral Access Layer
 * @{
 */


/** HCU - Size of Registers Arrays */
#define HCU_KEY_COUNT           (4)
#define HCU_AESIV_COUNT           (4)
#define HCU_AESMAC_COUNT           (4)

/* HCU Register Layout Typedef */
typedef struct {
    uint32 GO;                                 /**< Go Register, offset: 0x0000 */
    uint32 CR;                                 /**< Configuration Register, offset: 0x0004 */
    uint32 RESERVED0;                          /**< RESERVED0, offset: 0x0008 */
    uint32 MSGADL;                             /**< Message and Additional Data Length Register, offset: 0x000C */
    uint32 RESERVED1;                          /**< RESERVED1, offset: 0x0010 */
    uint32 FIFOWM;                             /**< FIFO watermark Register, offset: 0x0014 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x0018 */
    uint32 SR;                                 /**< Status Register, offset: 0x001C */
    uint32 KEY[ 4];                            /**< Key (0~3) Register, offset: 0x0020 */
    uint32 RESERVED2[12];                      /**< RESERVED2, offset: 0x0030 */
    uint32 AESIV[ 4];                          /**< AES Initial Vector (0~3) Register, offset: 0x0060 */
    uint32 AESMAC[ 4];                         /**< AES MAC (0~3) Register, offset: 0x0070 */
    uint32 RESERVED3[12];                      /**< RESERVED3, offset: 0x0080 */
    uint32 IFDAT;                              /**< Input FIFO Data Register, offset: 0x00B0 */
    uint32 OFDAT;                              /**< Output FIFO Data Register, offset: 0x00B4 */

} HCU_Type, *HCU_MemMapPtr;

/** Number of instances of the HCU module. */
#define HCU_INSTANCE_COUNT                        (1u)

/* HCU base address */
#define HCU_BASE_ADDR32                                   (0x40067000U)
#define HCU                                               ((volatile HCU_Type *)(HCU_BASE_ADDR32))

/** Array initializer of HCU peripheral base addresses */
#define HCU_BASE_ADDRS                                     { HCU_BASE_ADDR32 }
/** Array initializer of HCU peripheral base pointers */
#define HCU_BASE_PTRS                                      { HCU }

#define HCU_GO_OFFSET32                                    (0x0000U)                    /**< Offset for Go Register */
#define HCU_CR_OFFSET32                                    (0x0004U)                    /**< Offset for Configuration Register */
#define HCU_MSGADL_OFFSET32                                (0x000CU)                    /**< Offset for Message and Additional Data Length Register */
#define HCU_FIFOWM_OFFSET32                                (0x0014U)                    /**< Offset for FIFO watermark Register */
#define HCU_INTE_OFFSET32                                  (0x0018U)                    /**< Offset for Interrupt Enable Register */
#define HCU_SR_OFFSET32                                    (0x001CU)                    /**< Offset for Status Register */
#define HCU_KEY_OFFSET32(x)                                (0x0020U + ((x) * (4U)))     /**< Offset for Key (0~3) Register */
#define HCU_AESIV_OFFSET32(x)                              (0x0060U + ((x) * (4U)))     /**< Offset for AES Initial Vector (0~3) Register */
#define HCU_AESMAC_OFFSET32(x)                             (0x0070U + ((x) * (4U)))     /**< Offset for AES MAC (0~3) Register */
#define HCU_IFDAT_OFFSET32                                 (0x00B0U)                    /**< Offset for Input FIFO Data Register */
#define HCU_OFDAT_OFFSET32                                 (0x00B4U)                    /**< Offset for Output FIFO Data Register */


/**
 * @addtogroup HCU Register Mask
 * @{
 */
/* HCU_GO Register */
#define HCU_GO_GO_MASK                                     (0x1U)
#define HCU_GO_GO_SHIFT                                    (0U)
#define HCU_GO_GO(x)                                       (((uint32)(((uint32)(x)) << HCU_GO_GO_SHIFT)) & HCU_GO_GO_MASK)
/* HCU_CR Register */
#define HCU_CR_OFSWR_MASK                                  (0x80000000U)
#define HCU_CR_OFSWR_SHIFT                                 (31U)
#define HCU_CR_OFSWR(x)                                    (((uint32)(((uint32)(x)) << HCU_CR_OFSWR_SHIFT)) & HCU_CR_OFSWR_MASK)
#define HCU_CR_IFSWR_MASK                                  (0x40000000U)
#define HCU_CR_IFSWR_SHIFT                                 (30U)
#define HCU_CR_IFSWR(x)                                    (((uint32)(((uint32)(x)) << HCU_CR_IFSWR_SHIFT)) & HCU_CR_IFSWR_MASK)
#define HCU_CR_OFDMAE_MASK                                 (0x20000000U)
#define HCU_CR_OFDMAE_SHIFT                                (29U)
#define HCU_CR_OFDMAE(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_OFDMAE_SHIFT)) & HCU_CR_OFDMAE_MASK)
#define HCU_CR_IFDMAE_MASK                                 (0x10000000U)
#define HCU_CR_IFDMAE_SHIFT                                (28U)
#define HCU_CR_IFDMAE(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_IFDMAE_SHIFT)) & HCU_CR_IFDMAE_MASK)
#define HCU_CR_MACLEN_MASK                                 (0xF000000U)
#define HCU_CR_MACLEN_SHIFT                                (24U)
#define HCU_CR_MACLEN(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_MACLEN_SHIFT)) & HCU_CR_MACLEN_MASK)
#define HCU_CR_CS_MASK                                     (0x40000U)
#define HCU_CR_CS_SHIFT                                    (18U)
#define HCU_CR_CS(x)                                       (((uint32)(((uint32)(x)) << HCU_CR_CS_SHIFT)) & HCU_CR_CS_MASK)
#define HCU_CR_MSGB_MASK                                   (0x20000U)
#define HCU_CR_MSGB_SHIFT                                  (17U)
#define HCU_CR_MSGB(x)                                     (((uint32)(((uint32)(x)) << HCU_CR_MSGB_SHIFT)) & HCU_CR_MSGB_MASK)
#define HCU_CR_MSGE_MASK                                   (0x10000U)
#define HCU_CR_MSGE_SHIFT                                  (16U)
#define HCU_CR_MSGE(x)                                     (((uint32)(((uint32)(x)) << HCU_CR_MSGE_SHIFT)) & HCU_CR_MSGE_MASK)
#define HCU_CR_ALGSEL_MASK                                 (0xF000U)
#define HCU_CR_ALGSEL_SHIFT                                (12U)
#define HCU_CR_ALGSEL(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_ALGSEL_SHIFT)) & HCU_CR_ALGSEL_MASK)
#define HCU_CR_ENGSEL_MASK                                 (0xF0U)
#define HCU_CR_ENGSEL_SHIFT                                (4U)
#define HCU_CR_ENGSEL(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_ENGSEL_SHIFT)) & HCU_CR_ENGSEL_MASK)
#define HCU_CR_DATSWP_MASK                                 (0xCU)
#define HCU_CR_DATSWP_SHIFT                                (2U)
#define HCU_CR_DATSWP(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_DATSWP_SHIFT)) & HCU_CR_DATSWP_MASK)
#define HCU_CR_ENC_MASK                                    (0x2U)
#define HCU_CR_ENC_SHIFT                                   (1U)
#define HCU_CR_ENC(x)                                      (((uint32)(((uint32)(x)) << HCU_CR_ENC_SHIFT)) & HCU_CR_ENC_MASK)
/* HCU_MSGADL Register */
#define HCU_MSGADL_ADLEN_MASK                              (0x7FFF0000U)
#define HCU_MSGADL_ADLEN_SHIFT                             (16U)
#define HCU_MSGADL_ADLEN(x)                                (((uint32)(((uint32)(x)) << HCU_MSGADL_ADLEN_SHIFT)) & HCU_MSGADL_ADLEN_MASK)
#define HCU_MSGADL_MSGLEN_MASK                             (0x7FFFU)
#define HCU_MSGADL_MSGLEN_SHIFT                            (0U)
#define HCU_MSGADL_MSGLEN(x)                               (((uint32)(((uint32)(x)) << HCU_MSGADL_MSGLEN_SHIFT)) & HCU_MSGADL_MSGLEN_MASK)
/* HCU_FIFOWM Register */
#define HCU_FIFOWM_OFWM_MASK                               (0x1F0000U)
#define HCU_FIFOWM_OFWM_SHIFT                              (16U)
#define HCU_FIFOWM_OFWM(x)                                 (((uint32)(((uint32)(x)) << HCU_FIFOWM_OFWM_SHIFT)) & HCU_FIFOWM_OFWM_MASK)
#define HCU_FIFOWM_IFWM_MASK                               (0x1FU)
#define HCU_FIFOWM_IFWM_SHIFT                              (0U)
#define HCU_FIFOWM_IFWM(x)                                 (((uint32)(((uint32)(x)) << HCU_FIFOWM_IFWM_SHIFT)) & HCU_FIFOWM_IFWM_MASK)
/* HCU_INTE Register */
#define HCU_INTE_IFWMIE_MASK                               (0x8000U)
#define HCU_INTE_IFWMIE_SHIFT                              (15U)
#define HCU_INTE_IFWMIE(x)                                 (((uint32)(((uint32)(x)) << HCU_INTE_IFWMIE_SHIFT)) & HCU_INTE_IFWMIE_MASK)
#define HCU_INTE_OFWMIE_MASK                               (0x4000U)
#define HCU_INTE_OFWMIE_SHIFT                              (14U)
#define HCU_INTE_OFWMIE(x)                                 (((uint32)(((uint32)(x)) << HCU_INTE_OFWMIE_SHIFT)) & HCU_INTE_OFWMIE_MASK)
#define HCU_INTE_IFOFIE_MASK                               (0x2000U)
#define HCU_INTE_IFOFIE_SHIFT                              (13U)
#define HCU_INTE_IFOFIE(x)                                 (((uint32)(((uint32)(x)) << HCU_INTE_IFOFIE_SHIFT)) & HCU_INTE_IFOFIE_MASK)
#define HCU_INTE_OFUFIE_MASK                               (0x1000U)
#define HCU_INTE_OFUFIE_SHIFT                              (12U)
#define HCU_INTE_OFUFIE(x)                                 (((uint32)(((uint32)(x)) << HCU_INTE_OFUFIE_SHIFT)) & HCU_INTE_OFUFIE_MASK)
#define HCU_INTE_IFEIE_MASK                                (0x400U)
#define HCU_INTE_IFEIE_SHIFT                               (10U)
#define HCU_INTE_IFEIE(x)                                  (((uint32)(((uint32)(x)) << HCU_INTE_IFEIE_SHIFT)) & HCU_INTE_IFEIE_MASK)
#define HCU_INTE_OFFIE_MASK                                (0x200U)
#define HCU_INTE_OFFIE_SHIFT                               (9U)
#define HCU_INTE_OFFIE(x)                                  (((uint32)(((uint32)(x)) << HCU_INTE_OFFIE_SHIFT)) & HCU_INTE_OFFIE_MASK)
#define HCU_INTE_ODIE_MASK                                 (0x1U)
#define HCU_INTE_ODIE_SHIFT                                (0U)
#define HCU_INTE_ODIE(x)                                   (((uint32)(((uint32)(x)) << HCU_INTE_ODIE_SHIFT)) & HCU_INTE_ODIE_MASK)
/* HCU_SR Register */
#define HCU_SR_IFWMF_MASK                                  (0x8000U)
#define HCU_SR_IFWMF_SHIFT                                 (15U)
#define HCU_SR_IFWMF(x)                                    (((uint32)(((uint32)(x)) << HCU_SR_IFWMF_SHIFT)) & HCU_SR_IFWMF_MASK)
#define HCU_SR_OFWMF_MASK                                  (0x4000U)
#define HCU_SR_OFWMF_SHIFT                                 (14U)
#define HCU_SR_OFWMF(x)                                    (((uint32)(((uint32)(x)) << HCU_SR_OFWMF_SHIFT)) & HCU_SR_OFWMF_MASK)
#define HCU_SR_IFOFF_MASK                                  (0x2000U)
#define HCU_SR_IFOFF_SHIFT                                 (13U)
#define HCU_SR_IFOFF(x)                                    (((uint32)(((uint32)(x)) << HCU_SR_IFOFF_SHIFT)) & HCU_SR_IFOFF_MASK)
#define HCU_SR_OFUFF_MASK                                  (0x1000U)
#define HCU_SR_OFUFF_SHIFT                                 (12U)
#define HCU_SR_OFUFF(x)                                    (((uint32)(((uint32)(x)) << HCU_SR_OFUFF_SHIFT)) & HCU_SR_OFUFF_MASK)
#define HCU_SR_IFFS_MASK                                   (0x800U)
#define HCU_SR_IFFS_SHIFT                                  (11U)
#define HCU_SR_IFFS(x)                                     (((uint32)(((uint32)(x)) << HCU_SR_IFFS_SHIFT)) & HCU_SR_IFFS_MASK)
#define HCU_SR_IFES_MASK                                   (0x400U)
#define HCU_SR_IFES_SHIFT                                  (10U)
#define HCU_SR_IFES(x)                                     (((uint32)(((uint32)(x)) << HCU_SR_IFES_SHIFT)) & HCU_SR_IFES_MASK)
#define HCU_SR_OFFS_MASK                                   (0x200U)
#define HCU_SR_OFFS_SHIFT                                  (9U)
#define HCU_SR_OFFS(x)                                     (((uint32)(((uint32)(x)) << HCU_SR_OFFS_SHIFT)) & HCU_SR_OFFS_MASK)
#define HCU_SR_OFES_MASK                                   (0x100U)
#define HCU_SR_OFES_SHIFT                                  (8U)
#define HCU_SR_OFES(x)                                     (((uint32)(((uint32)(x)) << HCU_SR_OFES_SHIFT)) & HCU_SR_OFES_MASK)
#define HCU_SR_AESVAL_MASK                                 (0x2U)
#define HCU_SR_AESVAL_SHIFT                                (1U)
#define HCU_SR_AESVAL(x)                                   (((uint32)(((uint32)(x)) << HCU_SR_AESVAL_SHIFT)) & HCU_SR_AESVAL_MASK)
#define HCU_SR_OD_MASK                                     (0x1U)
#define HCU_SR_OD_SHIFT                                    (0U)
#define HCU_SR_OD(x)                                       (((uint32)(((uint32)(x)) << HCU_SR_OD_SHIFT)) & HCU_SR_OD_MASK)
/* HCU_KEY Register */
#define HCU_KEY_KEY_MASK                                   (0xFFFFFFFFU)
#define HCU_KEY_KEY_SHIFT                                  (0U)
#define HCU_KEY_KEY(x)                                     (((uint32)(((uint32)(x)) << HCU_KEY_KEY_SHIFT)) & HCU_KEY_KEY_MASK)
/* HCU_AESIV Register */
#define HCU_AESIV_INIT_MASK                                (0xFFFFFFFFU)
#define HCU_AESIV_INIT_SHIFT                               (0U)
#define HCU_AESIV_INIT(x)                                  (((uint32)(((uint32)(x)) << HCU_AESIV_INIT_SHIFT)) & HCU_AESIV_INIT_MASK)
/* HCU_AESMAC Register */
#define HCU_AESMAC_MAC_MASK                                (0xFFFFFFFFU)
#define HCU_AESMAC_MAC_SHIFT                               (0U)
#define HCU_AESMAC_MAC(x)                                  (((uint32)(((uint32)(x)) << HCU_AESMAC_MAC_SHIFT)) & HCU_AESMAC_MAC_MASK)
/* HCU_IFDAT Register */
#define HCU_IFDAT_IFDAT_MASK                               (0xFFFFFFFFU)
#define HCU_IFDAT_IFDAT_SHIFT                              (0U)
#define HCU_IFDAT_IFDAT(x)                                 (((uint32)(((uint32)(x)) << HCU_IFDAT_IFDAT_SHIFT)) & HCU_IFDAT_IFDAT_MASK)
/* HCU_OFDAT Register */
#define HCU_OFDAT_OFDAT_MASK                               (0xFFFFFFFFU)
#define HCU_OFDAT_OFDAT_SHIFT                              (0U)
#define HCU_OFDAT_OFDAT(x)                                 (((uint32)(((uint32)(x)) << HCU_OFDAT_OFDAT_SHIFT)) & HCU_OFDAT_OFDAT_MASK)


/**
 * @}
 */ /* end of group HCU_Register_Masks */


/**
 * @}
 */ /* end of group HCU_Peripheral_Access_Layer */

#endif /* PSIP_HCU_H */

