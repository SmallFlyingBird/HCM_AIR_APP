/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file CddDma_Cfg.h
 * @brief 
 * 
 */


#ifndef CDDDMA_CFG_H
#define CDDDMA_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "CddDma_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID_CFG                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define CDDDMA_SW_MAJOR_VERSION_CFG               (2)
#define CDDDMA_SW_MINOR_VERSION_CFG               (3)
#define CDDDMA_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum {
    DMA_REQ_DISABLED         =   0U,     /*!< Disabled         dma request    0u */
    DMA_REQ_LINFlexD0_RX     =   2U,     /*!< LINFlexD0_RX     dma request    1u */
    DMA_REQ_LINFlexD0_TX     =   3U,     /*!< LINFlexD0_TX     dma request    2u */
    DMA_REQ_LINFlexD1_RX     =   4U,     /*!< LINFlexD1_RX     dma request    3u */
    DMA_REQ_LINFlexD1_TX     =   5U,     /*!< LINFlexD1_TX     dma request    4u */
    DMA_REQ_LINFlexD2_RX     =   6U,     /*!< LINFlexD2_RX     dma request    5u */
    DMA_REQ_LINFlexD2_TX     =   7U,     /*!< LINFlexD2_TX     dma request    6u */
    DMA_REQ_I2C1_RX          =   8U,     /*!< I2C1_RX          dma request    8u */
    DMA_REQ_I2C1_TX          =   9U,     /*!< I2C1_TX          dma request    9u */
    DMA_REQ_SPI0_RX          =  14U,     /*!< SPI0_RX          dma request   14u */
    DMA_REQ_SPI0_TX          =  15U,     /*!< SPI0_TX          dma request   15u */
    DMA_REQ_SPI1_RX          =  16U,     /*!< SPI1_RX          dma request   16u */
    DMA_REQ_SPI1_TX          =  17U,     /*!< SPI1_TX          dma request   17u */
    DMA_REQ_SPI2_RX          =  18U,     /*!< SPI2_RX          dma request   18u */
    DMA_REQ_SPI2_TX          =  19U,     /*!< SPI2_TX          dma request   19u */
    DMA_REQ_eTMR1_CH0        =  20U,     /*!< eTMR1_CH0        dma request   20u */
    DMA_REQ_eTMR1_CH1        =  21U,     /*!< eTMR1_CH1        dma request   21u */
    DMA_REQ_eTMR1_CH2        =  22U,     /*!< eTMR1_CH2        dma request   22u */
    DMA_REQ_eTMR1_CH3        =  23U,     /*!< eTMR1_CH3        dma request   23u */
    DMA_REQ_eTMR1_CH4        =  24U,     /*!< eTMR1_CH4        dma request   24u */
    DMA_REQ_eTMR1_CH5        =  25U,     /*!< eTMR1_CH5        dma request   25u */
    DMA_REQ_eTMR1_CH6        =  26U,     /*!< eTMR1_CH6        dma request   26u */
    DMA_REQ_eTMR1_CH7        =  27U,     /*!< eTMR1_CH7        dma request   27u */
    DMA_REQ_eTMR2_CH0        =  28U,     /*!< eTMR2_CH0        dma request   28u */
    DMA_REQ_eTMR2_CH1        =  29U,     /*!< eTMR2_CH1        dma request   29u */
    DMA_REQ_eTMR2_CH2        =  30U,     /*!< eTMR2_CH2        dma request   30u */
    DMA_REQ_eTMR2_CH3        =  31U,     /*!< eTMR2_CH3        dma request   31u */
    DMA_REQ_eTMR2_CH4        =  32U,     /*!< eTMR2_CH4        dma request   32u */
    DMA_REQ_eTMR2_CH5        =  33U,     /*!< eTMR2_CH5        dma request   33u */
    DMA_REQ_eTMR2_CH6        =  34U,     /*!< eTMR2_CH6        dma request   34u */
    DMA_REQ_eTMR2_CH7        =  35U,     /*!< eTMR2_CH7        dma request   35u */
    DMA_REQ_eTMR0            =  36U,     /*!< eTMR0            dma request   36u */
    DMA_REQ_eTMR3            =  37U,     /*!< eTMR3            dma request   37u */
    DMA_REQ_SENT0_FAST       =  38U,     /*!< Sent0_Fast       dma request   38u */
    DMA_REQ_SENT0_SLOW       =  39U,     /*!< Sent0_Slow       dma request   39u */
    DMA_REQ_HCU_IN           =  40U,     /*!< HCU_IN           dma request   40u */
    DMA_REQ_HCU_OUT          =  41U,     /*!< HCU_OUT          dma request   41u */
    DMA_REQ_ADC0             =  42U,     /*!< ADC0             dma request   42u */
    DMA_REQ_I2C0_RX          =  44U,     /*!< I2C0_RX          dma request   44u */
    DMA_REQ_I2C0_TX          =  45U,     /*!< I2C0_TX          dma request   45u */
    DMA_REQ_GPIOA            =  49U,     /*!< GPIOA            dma request   49u */
    DMA_REQ_GPIOB            =  50U,     /*!< GPIOB            dma request   50u */
    DMA_REQ_GPIOC            =  51U,     /*!< GPIOC            dma request   51u */
    DMA_REQ_GPIOD            =  52U,     /*!< GPIOD            dma request   52u */
    DMA_REQ_GPIOE            =  53U,     /*!< GPIOE            dma request   53u */
    DMA_REQ_FLEXCAN0         =  54U,     /*!< FLEXCAN0         dma request   54u */
    DMA_REQ_FLEXCAN1         =  55U,     /*!< FLEXCAN1         dma request   55u */
    DMA_REQ_FLEXCAN2         =  56U,     /*!< FLEXCAN2         dma request   56u */
    DMA_REQ_SPI3_RX          =  60U,     /*!< SPI3_RX          dma request   60u */
    DMA_REQ_SPI3_TX          =  61U,     /*!< SPI3_TX          dma request   61u */
    DMA_REQ_Always_On0       =  62U,     /*!< Always On        dma request   62u */
    DMA_REQ_Always_On1       =  63U,     /*!< Always On        dma request   63u */
} CddDma_RequestSourceType;
/*==================================================================================================
*                                       DEFINITIONS AND MACROS
==================================================================================================*/

/* @brief Total enabled number of DMA channels. */
#define CDDDMA_CHANNEL_CONFIG_COUNT                (2U)

/**
* @brief Define precompile support.
* @details Define precompile support if VARIANT-PRE-COMPILE or VARIANT-LINK-TIME is selected and number of variant <=1.
*/
#define CDDDMA_PRECOMPILE_SUPPORT                  (STD_OFF)

#define CDDDMA_DEV_ERROR_DETECT                    (STD_ON)

#define CDDDMA_VERSION_INFO_API                    (STD_OFF)

/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*        If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic operations for key resource protection.
*        If it is enabled, all the SchM codes in MCAL CddDma driver codes will work and support sync/atomic operation with CPU global interrupt enable/disable for key resource protection. 
*        Disable it can reduce code size, but may cause potential risks when access to some critical resource!
*/
#define CDDDMA_SCHM_SUPPORT                         (STD_ON) 


#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if CDDDMA_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

#endif

