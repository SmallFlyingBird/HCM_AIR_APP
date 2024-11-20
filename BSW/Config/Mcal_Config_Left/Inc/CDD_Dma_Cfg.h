/**************************************************************************************************/
/**
 * @file      : CDD_Dma_Cfg.h
 * @brief     : AUTOSAR CDD dma pre-compile configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CDD_DMA_CFG_H
#define CDD_DMA_CFG_H

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


#include "CDD_Dma_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CDD_DMA_CFG_H_VENDOR_ID                   0x00B3U
#define CDD_DMA_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_DMA_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CDD_DMA_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CDD_DMA_CFG_H_SW_MAJOR_VERSION            1U
#define CDD_DMA_CFG_H_SW_MINOR_VERSION            2U
#define CDD_DMA_CFG_H_SW_PATCH_VERSION            2U



#if (CDD_DMA_CFG_H_VENDOR_ID != CDD_DMA_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of CDD_Dma_Cfg.h and CDD_Dma_PBcfg.h are different"
#endif

#if ((CDD_DMA_CFG_H_AR_RELEASE_MAJOR_VERSION != CDD_DMA_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
    (CDD_DMA_CFG_H_AR_RELEASE_MINOR_VERSION != CDD_DMA_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
    (CDD_DMA_CFG_H_AR_RELEASE_REVISION_VERSION != CDD_DMA_PBCFG_H_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version of CDD_Dma_Cfg.h and CDD_Dma_PBcfg.h are different"
#endif

#if ((CDD_DMA_CFG_H_SW_MAJOR_VERSION != CDD_DMA_PBCFG_H_SW_MAJOR_VERSION) || \
    (CDD_DMA_CFG_H_SW_MINOR_VERSION != CDD_DMA_PBCFG_H_SW_MINOR_VERSION) || \
    (CDD_DMA_CFG_H_SW_PATCH_VERSION != CDD_DMA_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version of CDD_Dma_Cfg.h and CDD_Dma_PBcfg.h are different"
#endif


/**
* @brief Dma module configured num
*/

#define DMA_MODULE_TOTALNUM     ((uint32)1U)
#define DMA_MAX_CFG_CHANNELS    ((uint32)16U)

#define DMA_CHANNEL_CFG_TOTALNUM     (DMA_DRV_CHANNEL_CFG_TOTALNUM)
#define DMA_LOGIC_CH_0  ((uint32)0U)
#define DMA_LOGIC_CH_1  ((uint32)1U)
#define DMA_LOGIC_CH_2  ((uint32)2U)
#define DMA_LOGIC_CH_3  ((uint32)3U)

/**
* @brief Switches ON or OFF for the detection and reporting of development errors(API parameter checking) at IP level.
*/
#define DMA_DEV_ERROR_DETECT                        STD_ON


#define DMA_VERSIONINFOAPI_SUPPORT                 STD_ON


#define DMA_PRECOMPILE_SUPPORT                     STD_ON




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

#endif /* CDD_DMA_CFG_H_ */

