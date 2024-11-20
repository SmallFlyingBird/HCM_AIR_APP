/**************************************************************************************************/
/**
 * @file      : Dma_Drv_PBcfg.h
 * @brief     : AUTOSAR dma post-build configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DMA_DRV_PBCFG_H
#define DMA_DRV_PBCFG_H

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


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define DMA_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define DMA_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define DMA_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define DMA_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define DMA_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define DMA_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define DMA_DRV_PBCFG_H_SW_PATCH_VERSION            2U

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define DMA_DRV_CONFIG_PB \
extern const Dma_Drv_ConfigType * const Dma_Drv_ModuleCfgArrayPtr[DMA_DRV_MODULE_TOTALNUM];   \
extern const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg0;   \
extern const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg1;   \
extern const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg2;   \
extern const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg3;   \
extern const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg0;   \
extern const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg1;   \
extern const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg2;   \
extern const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg3;   \



/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma  */
/** @} end of group Dma_Module */

#endif /* DMA_PBCFG_H */


