/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file CddDma_PBcfg.h
 * @brief 
 * 
 */


#ifndef CDDDMA_PB_CFG_H
#define CDDDMA_PB_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID_PBCFG                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define CDDDMA_SW_MAJOR_VERSION_PBCFG               (2)
#define CDDDMA_SW_MINOR_VERSION_PBCFG               (3)
#define CDDDMA_SW_PATCH_VERSION_PBCFG               (0)

/*!
 * @brief Structure for the DMA hardware channel
 *
 * Defines the structure for the DMA hardware channel collections.
 */
typedef enum {
    DMA_IP_HW_CH_0           =  0U,     /*!< DMA IP HW channel 0 */
    DMA_IP_HW_CH_1           =  1U,     /*!< DMA IP HW channel 1 */
    DMA_IP_HW_CH_2           =  2U,     /*!< DMA IP HW channel 2 */
    DMA_IP_HW_CH_3           =  3U,     /*!< DMA IP HW channel 3 */
    DMA_IP_HW_CH_4           =  4U,     /*!< DMA IP HW channel 4 */
    DMA_IP_HW_CH_5           =  5U,     /*!< DMA IP HW channel 5 */
    DMA_IP_HW_CH_6           =  6U,     /*!< DMA IP HW channel 6 */
    DMA_IP_HW_CH_7           =  7U,     /*!< DMA IP HW channel 7 */
    DMA_IP_HW_CH_8           =  8U,     /*!< DMA IP HW channel 8 */
    DMA_IP_HW_CH_9           =  9U,     /*!< DMA IP HW channel 9 */
    DMA_IP_HW_CH_10          = 10U,     /*!< DMA IP HW channel 10 */
    DMA_IP_HW_CH_11          = 11U,     /*!< DMA IP HW channel 11 */
    DMA_IP_HW_CH_12          = 12U,     /*!< DMA IP HW channel 12 */
    DMA_IP_HW_CH_13          = 13U,     /*!< DMA IP HW channel 13 */
    DMA_IP_HW_CH_14          = 14U,     /*!< DMA IP HW channel 14 */
    DMA_IP_HW_CH_15          = 15U,     /*!< DMA IP HW channel 15 */
} CddDma_HwChannelType;

#define CDDDMA_TRANSFER_CONFIG_COUNT                (2U)

/* Logic Channel 0 */
#define CddDmaConf_CddDmaConfig_dmaLogicChannel_Type_0             DMA_IP_HW_CH_0
/* Logic Channel 1 */
#define CddDmaConf_CddDmaConfig_dmaLogicChannel_Type_1             DMA_IP_HW_CH_1

#define CDDDMA_CONFIG_PB \
    extern const CddDma_ConfigType CddDma_Config;

#endif

