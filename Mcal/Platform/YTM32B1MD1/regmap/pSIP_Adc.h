/**
*   @file    pSIP_Adc.h
*   @version
*
*   @brief   AUTOSAR Adc register map
*   @details Register map for ADC
*
*   @addtogroup ADC_MODULE
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

#ifndef PSIP_ADC_H
#define PSIP_ADC_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              ADC REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */


/** ADC - Size of Registers Arrays */
#define ADC_CHSEL_COUNT           (8U)

/* ADC Register Layout Typedef */
typedef struct {
    uint32 STS;                                /**< Status Register, offset: 0x0000 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x0004 */
    uint32 CTRL;                               /**< Control Register, offset: 0x0008 */
    uint32 CFG0;                               /**< Configuration 0 Register, offset: 0x000C */
    uint32 CFG1;                               /**< Configuration 1 Register, offset: 0x0010 */
    uint32 SMP;                                /**< Sampling Register, offset: 0x0014 */
    uint32 WDCTRL;                             /**< Watchdog Control Register, offset: 0x0018 */
    uint32 WDTH;                               /**< Watchdog Threshold Register, offset: 0x001C */
    uint32 RESERVED0[ 3];                      /**< RESERVED0, offset: 0x0020 */
    uint8 CHSEL[ 8];                          /**< Channel Configure 0 Register, offset: 0x002C */
    uint32 RESERVED1[ 6];                      /**< RESERVED1, offset: 0x0034 */
    uint32 FIFO;                               /**< FIFO Access Register, offset: 0x004C */
    uint32 RESERVED_12;                        /**< RESERVED_12, offset: 0x0050 */

} ADC_Type, *ADC_MemMapPtr;

/** Number of instances of the ADC module. */
#define ADC_INSTANCE_COUNT                        (1u)

/* ADC0  base address */
#define ADC0_BASE_ADDR32                                   (0x40040000U)
#define ADC0                                               ((volatile ADC_Type *)(ADC0_BASE_ADDR32))

/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                                     { ADC0_BASE_ADDR32 }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                                      { ADC0 }

#define ADC_STS_OFFSET32                                   (0x0000U)                    /**< Offset for Status Register */
#define ADC_INTE_OFFSET32                                  (0x0004U)                    /**< Offset for Interrupt Enable Register */
#define ADC_CTRL_OFFSET32                                  (0x0008U)                    /**< Offset for Control Register */
#define ADC_CFG0_OFFSET32                                  (0x000CU)                    /**< Offset for Configuration 0 Register */
#define ADC_CFG1_OFFSET32                                  (0x0010U)                    /**< Offset for Configuration 1 Register */
#define ADC_SMP_OFFSET32                                   (0x0014U)                    /**< Offset for Sampling Register */
#define ADC_WDCTRL_OFFSET32                                (0x0018U)                    /**< Offset for Watchdog Control Register */
#define ADC_WDTH_OFFSET32                                  (0x001CU)                    /**< Offset for Watchdog Threshold Register */
#define ADC_CHSEL_OFFSET8(x)                              (0x002CU + ((x) * (1U)))     /**< Offset for Channel Configure 0 Register */
#define ADC_FIFO_OFFSET32                                  (0x004CU)                    /**< Offset for FIFO Access Register */


/**
 * @addtogroup ADC Register Mask
 * @{
 */
/* ADC_STS Register */
#define ADC_STS_WD_MASK                                    (0x80U)
#define ADC_STS_WD_SHIFT                                   (7U)
#define ADC_STS_WD(x)                                      (((uint32)(((uint32)(x)) << ADC_STS_WD_SHIFT)) & ADC_STS_WD_MASK)
#define ADC_STS_EMPTY_MASK                                 (0x40U)
#define ADC_STS_EMPTY_SHIFT                                (6U)
#define ADC_STS_EMPTY(x)                                   (((uint32)(((uint32)(x)) << ADC_STS_EMPTY_SHIFT)) & ADC_STS_EMPTY_MASK)
#define ADC_STS_FULL_MASK                                  (0x20U)
#define ADC_STS_FULL_SHIFT                                 (5U)
#define ADC_STS_FULL(x)                                    (((uint32)(((uint32)(x)) << ADC_STS_FULL_SHIFT)) & ADC_STS_FULL_MASK)
#define ADC_STS_OVR_MASK                                   (0x10U)
#define ADC_STS_OVR_SHIFT                                  (4U)
#define ADC_STS_OVR(x)                                     (((uint32)(((uint32)(x)) << ADC_STS_OVR_SHIFT)) & ADC_STS_OVR_MASK)
#define ADC_STS_EOSEQ_MASK                                 (0x8U)
#define ADC_STS_EOSEQ_SHIFT                                (3U)
#define ADC_STS_EOSEQ(x)                                   (((uint32)(((uint32)(x)) << ADC_STS_EOSEQ_SHIFT)) & ADC_STS_EOSEQ_MASK)
#define ADC_STS_EOC_MASK                                   (0x4U)
#define ADC_STS_EOC_SHIFT                                  (2U)
#define ADC_STS_EOC(x)                                     (((uint32)(((uint32)(x)) << ADC_STS_EOC_SHIFT)) & ADC_STS_EOC_MASK)
#define ADC_STS_EOSMP_MASK                                 (0x2U)
#define ADC_STS_EOSMP_SHIFT                                (1U)
#define ADC_STS_EOSMP(x)                                   (((uint32)(((uint32)(x)) << ADC_STS_EOSMP_SHIFT)) & ADC_STS_EOSMP_MASK)
#define ADC_STS_ADRDY_MASK                                 (0x1U)
#define ADC_STS_ADRDY_SHIFT                                (0U)
#define ADC_STS_ADRDY(x)                                   (((uint32)(((uint32)(x)) << ADC_STS_ADRDY_SHIFT)) & ADC_STS_ADRDY_MASK)
/* ADC_INTE Register */
#define ADC_INTE_WDIE_MASK                                 (0x80U)
#define ADC_INTE_WDIE_SHIFT                                (7U)
#define ADC_INTE_WDIE(x)                                   (((uint32)(((uint32)(x)) << ADC_INTE_WDIE_SHIFT)) & ADC_INTE_WDIE_MASK)
#define ADC_INTE_OVRIE_MASK                                (0x10U)
#define ADC_INTE_OVRIE_SHIFT                               (4U)
#define ADC_INTE_OVRIE(x)                                  (((uint32)(((uint32)(x)) << ADC_INTE_OVRIE_SHIFT)) & ADC_INTE_OVRIE_MASK)
#define ADC_INTE_EOSEQIE_MASK                              (0x8U)
#define ADC_INTE_EOSEQIE_SHIFT                             (3U)
#define ADC_INTE_EOSEQIE(x)                                (((uint32)(((uint32)(x)) << ADC_INTE_EOSEQIE_SHIFT)) & ADC_INTE_EOSEQIE_MASK)
#define ADC_INTE_EOCIE_MASK                                (0x4U)
#define ADC_INTE_EOCIE_SHIFT                               (2U)
#define ADC_INTE_EOCIE(x)                                  (((uint32)(((uint32)(x)) << ADC_INTE_EOCIE_SHIFT)) & ADC_INTE_EOCIE_MASK)
#define ADC_INTE_EOSMPIE_MASK                              (0x2U)
#define ADC_INTE_EOSMPIE_SHIFT                             (1U)
#define ADC_INTE_EOSMPIE(x)                                (((uint32)(((uint32)(x)) << ADC_INTE_EOSMPIE_SHIFT)) & ADC_INTE_EOSMPIE_MASK)
#define ADC_INTE_ADRDYIE_MASK                              (0x1U)
#define ADC_INTE_ADRDYIE_SHIFT                             (0U)
#define ADC_INTE_ADRDYIE(x)                                (((uint32)(((uint32)(x)) << ADC_INTE_ADRDYIE_SHIFT)) & ADC_INTE_ADRDYIE_MASK)
/* ADC_CTRL Register */
#define ADC_CTRL_TSEN_MASK                                 (0x10U)
#define ADC_CTRL_TSEN_SHIFT                                (4U)
#define ADC_CTRL_TSEN(x)                                   (((uint32)(((uint32)(x)) << ADC_CTRL_TSEN_SHIFT)) & ADC_CTRL_TSEN_MASK)
#define ADC_CTRL_ADSTOP_MASK                               (0x8U)
#define ADC_CTRL_ADSTOP_SHIFT                              (3U)
#define ADC_CTRL_ADSTOP(x)                                 (((uint32)(((uint32)(x)) << ADC_CTRL_ADSTOP_SHIFT)) & ADC_CTRL_ADSTOP_MASK)
#define ADC_CTRL_ADSTART_MASK                              (0x4U)
#define ADC_CTRL_ADSTART_SHIFT                             (2U)
#define ADC_CTRL_ADSTART(x)                                (((uint32)(((uint32)(x)) << ADC_CTRL_ADSTART_SHIFT)) & ADC_CTRL_ADSTART_MASK)
#define ADC_CTRL_ADDIS_MASK                                (0x2U)
#define ADC_CTRL_ADDIS_SHIFT                               (1U)
#define ADC_CTRL_ADDIS(x)                                  (((uint32)(((uint32)(x)) << ADC_CTRL_ADDIS_SHIFT)) & ADC_CTRL_ADDIS_MASK)
#define ADC_CTRL_ADEN_MASK                                 (0x1U)
#define ADC_CTRL_ADEN_SHIFT                                (0U)
#define ADC_CTRL_ADEN(x)                                   (((uint32)(((uint32)(x)) << ADC_CTRL_ADEN_SHIFT)) & ADC_CTRL_ADEN_MASK)
/* ADC_CFG0 Register */
#define ADC_CFG0_OVRMD_MASK                                (0x40000000U)
#define ADC_CFG0_OVRMD_SHIFT                               (30U)
#define ADC_CFG0_OVRMD(x)                                  (((uint32)(((uint32)(x)) << ADC_CFG0_OVRMD_SHIFT)) & ADC_CFG0_OVRMD_MASK)
#define ADC_CFG0_SEQLEN_MASK                               (0x7000000U)
#define ADC_CFG0_SEQLEN_SHIFT                              (24U)
#define ADC_CFG0_SEQLEN(x)                                 (((uint32)(((uint32)(x)) << ADC_CFG0_SEQLEN_SHIFT)) & ADC_CFG0_SEQLEN_MASK)
#define ADC_CFG0_LPEN_MASK                                 (0x400000U)
#define ADC_CFG0_LPEN_SHIFT                                (22U)
#define ADC_CFG0_LPEN(x)                                   (((uint32)(((uint32)(x)) << ADC_CFG0_LPEN_SHIFT)) & ADC_CFG0_LPEN_MASK)
#define ADC_CFG0_AUTOOFF_MASK                              (0x200000U)
#define ADC_CFG0_AUTOOFF_SHIFT                             (21U)
#define ADC_CFG0_AUTOOFF(x)                                (((uint32)(((uint32)(x)) << ADC_CFG0_AUTOOFF_SHIFT)) & ADC_CFG0_AUTOOFF_MASK)
#define ADC_CFG0_WAIT_MASK                                 (0x100000U)
#define ADC_CFG0_WAIT_SHIFT                                (20U)
#define ADC_CFG0_WAIT(x)                                   (((uint32)(((uint32)(x)) << ADC_CFG0_WAIT_SHIFT)) & ADC_CFG0_WAIT_MASK)
#define ADC_CFG0_MODE_MASK                                 (0x30000U)
#define ADC_CFG0_MODE_SHIFT                                (16U)
#define ADC_CFG0_MODE(x)                                   (((uint32)(((uint32)(x)) << ADC_CFG0_MODE_SHIFT)) & ADC_CFG0_MODE_MASK)
#define ADC_CFG0_TRIGMD_MASK                               (0x800U)
#define ADC_CFG0_TRIGMD_SHIFT                              (11U)
#define ADC_CFG0_TRIGMD(x)                                 (((uint32)(((uint32)(x)) << ADC_CFG0_TRIGMD_SHIFT)) & ADC_CFG0_TRIGMD_MASK)
#define ADC_CFG0_RES_MASK                                  (0x300U)
#define ADC_CFG0_RES_SHIFT                                 (8U)
#define ADC_CFG0_RES(x)                                    (((uint32)(((uint32)(x)) << ADC_CFG0_RES_SHIFT)) & ADC_CFG0_RES_MASK)
#define ADC_CFG0_WM_MASK                                   (0xF0U)
#define ADC_CFG0_WM_SHIFT                                  (4U)
#define ADC_CFG0_WM(x)                                     (((uint32)(((uint32)(x)) << ADC_CFG0_WM_SHIFT)) & ADC_CFG0_WM_MASK)
#define ADC_CFG0_DMAEN_MASK                                (0x1U)
#define ADC_CFG0_DMAEN_SHIFT                               (0U)
#define ADC_CFG0_DMAEN(x)                                  (((uint32)(((uint32)(x)) << ADC_CFG0_DMAEN_SHIFT)) & ADC_CFG0_DMAEN_MASK)
/* ADC_CFG1 Register */
#define ADC_CFG1_PRS_MASK                                  (0xF00U)
#define ADC_CFG1_PRS_SHIFT                                 (8U)
#define ADC_CFG1_PRS(x)                                    (((uint32)(((uint32)(x)) << ADC_CFG1_PRS_SHIFT)) & ADC_CFG1_PRS_MASK)
#define ADC_CFG1_STCNT_MASK                                (0xFFU)
#define ADC_CFG1_STCNT_SHIFT                               (0U)
#define ADC_CFG1_STCNT(x)                                  (((uint32)(((uint32)(x)) << ADC_CFG1_STCNT_SHIFT)) & ADC_CFG1_STCNT_MASK)
/* ADC_SMP Register */
#define ADC_SMP_SMP_MASK                                   (0xFFU)
#define ADC_SMP_SMP_SHIFT                                  (0U)
#define ADC_SMP_SMP(x)                                     (((uint32)(((uint32)(x)) << ADC_SMP_SMP_SHIFT)) & ADC_SMP_SMP_MASK)
/* ADC_WDCTRL Register */
#define ADC_WDCTRL_WDEN_MASK                               (0x80U)
#define ADC_WDCTRL_WDEN_SHIFT                              (7U)
#define ADC_WDCTRL_WDEN(x)                                 (((uint32)(((uint32)(x)) << ADC_WDCTRL_WDEN_SHIFT)) & ADC_WDCTRL_WDEN_MASK)
#define ADC_WDCTRL_WDSGL_MASK                              (0x40U)
#define ADC_WDCTRL_WDSGL_SHIFT                             (6U)
#define ADC_WDCTRL_WDSGL(x)                                (((uint32)(((uint32)(x)) << ADC_WDCTRL_WDSGL_SHIFT)) & ADC_WDCTRL_WDSGL_MASK)
#define ADC_WDCTRL_WDCHSEL_MASK                            (0x3FU)
#define ADC_WDCTRL_WDCHSEL_SHIFT                           (0U)
#define ADC_WDCTRL_WDCHSEL(x)                              (((uint32)(((uint32)(x)) << ADC_WDCTRL_WDCHSEL_SHIFT)) & ADC_WDCTRL_WDCHSEL_MASK)
/* ADC_WDTH Register */
#define ADC_WDTH_THMD_MASK                                 (0x80000000U)
#define ADC_WDTH_THMD_SHIFT                                (31U)
#define ADC_WDTH_THMD(x)                                   (((uint32)(((uint32)(x)) << ADC_WDTH_THMD_SHIFT)) & ADC_WDTH_THMD_MASK)
#define ADC_WDTH_HIGH_MASK                                 (0xFFF0000U)
#define ADC_WDTH_HIGH_SHIFT                                (16U)
#define ADC_WDTH_HIGH(x)                                   (((uint32)(((uint32)(x)) << ADC_WDTH_HIGH_SHIFT)) & ADC_WDTH_HIGH_MASK)
#define ADC_WDTH_LOW_MASK                                  (0xFFFU)
#define ADC_WDTH_LOW_SHIFT                                 (0U)
#define ADC_WDTH_LOW(x)                                    (((uint32)(((uint32)(x)) << ADC_WDTH_LOW_SHIFT)) & ADC_WDTH_LOW_MASK)
/* ADC_CHSEL Register */
#define ADC_CHSEL_CHSEL_MASK                               (0x3FU)
#define ADC_CHSEL_CHSEL_SHIFT                              (0U)
#define ADC_CHSEL_CHSEL(x)                                 (((uint32)(((uint32)(x)) << ADC_CHSEL_CHSEL_SHIFT)) & ADC_CHSEL_CHSEL_MASK)
/* ADC_FIFO Register */
#define ADC_FIFO_CHID_MASK                                 (0x3F0000U)
#define ADC_FIFO_CHID_SHIFT                                (16U)
#define ADC_FIFO_CHID(x)                                   (((uint32)(((uint32)(x)) << ADC_FIFO_CHID_SHIFT)) & ADC_FIFO_CHID_MASK)
#define ADC_FIFO_DATA_MASK                                 (0xFFFFU)
#define ADC_FIFO_DATA_SHIFT                                (0U)
#define ADC_FIFO_DATA(x)                                   (((uint32)(((uint32)(x)) << ADC_FIFO_DATA_SHIFT)) & ADC_FIFO_DATA_MASK)


/**
 * @}
 */ /* end of group ADC_Register_Masks */


/**
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */

#endif /* PSIP_ADC_H */

