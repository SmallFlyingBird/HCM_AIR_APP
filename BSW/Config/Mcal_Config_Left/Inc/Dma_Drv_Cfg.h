/**************************************************************************************************/
/**
 * @file      : Dma_Drv_Cfg.h
 * @brief     : AUTOSAR CDD dma pre-compile configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DMA_DRV_CFG_H
#define DMA_DRV_CFG_H

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup  Dma
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif


#include "Dma_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define DMA_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define DMA_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define DMA_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define DMA_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define DMA_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define DMA_DRV_CFG_H_SW_MINOR_VERSION            2U
#define DMA_DRV_CFG_H_SW_PATCH_VERSION            2U



#if (DMA_DRV_CFG_H_VENDOR_ID != DMA_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Dma_Drv_Cfg.h and Dma_Drv_PBcfg.h are different"
#endif

#if ((DMA_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != DMA_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
    (DMA_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != DMA_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
    (DMA_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != DMA_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version of Dma_Drv_Cfg.h and Dma_Drv_PBcfg.h are different"
#endif

#if ((DMA_DRV_CFG_H_SW_MAJOR_VERSION != DMA_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
    (DMA_DRV_CFG_H_SW_MINOR_VERSION != DMA_DRV_PBCFG_H_SW_MINOR_VERSION) || \
    (DMA_DRV_CFG_H_SW_PATCH_VERSION != DMA_DRV_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version of Dma_Drv_Cfg.h and Dma_Drv_PBcfg.h are different"
#endif

/**
 * @brief Defines Dma Driver configuration.
 */
#define DMA_DRV_CONFIG_EXT \
    DMA_DRV_CONFIG_PB


/**
* @brief Dma module configured num
*/

#define DMA_DRV_MODULE_TOTALNUM     ((uint32)1U)
#define DMA_DRV_CHANNEL_NUM    ((uint32)16U)
#define DMA_DRV_CHANNEL_CFG_TOTALNUM     ((uint32)4U)

#define DMA_DRV_CH_0_ENABLE    (STD_OFF)
#define DMA_DRV_CH_1_ENABLE    (STD_OFF)
#define DMA_DRV_CH_2_ENABLE    (STD_OFF)
#define DMA_DRV_CH_3_ENABLE    (STD_OFF)
#define DMA_DRV_CH_4_ENABLE    (STD_OFF)
#define DMA_DRV_CH_5_ENABLE    (STD_OFF)
#define DMA_DRV_CH_6_ENABLE    (STD_OFF)
#define DMA_DRV_CH_7_ENABLE    (STD_OFF)
#define DMA_DRV_CH_8_ENABLE    (STD_OFF)
#define DMA_DRV_CH_9_ENABLE    (STD_OFF)
#define DMA_DRV_CH_10_ENABLE    (STD_OFF)
#define DMA_DRV_CH_11_ENABLE    (STD_OFF)
#define DMA_DRV_CH_12_ENABLE    (STD_ON)
#define DMA_DRV_CH_13_ENABLE    (STD_ON)
#define DMA_DRV_CH_14_ENABLE    (STD_ON)
#define DMA_DRV_CH_15_ENABLE    (STD_ON)

#define DMA_DRV_PHYS_CH_USED                 (STD_ON)

#define DMA_DRV_DEV_ERROR_DETECT    (STD_ON)


/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
    
/** @} end of group Dma */
/** @} end of group Dma_Module */

#endif /* DMA_DRV_CFG_H */

