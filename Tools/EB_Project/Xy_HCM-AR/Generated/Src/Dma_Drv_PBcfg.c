/**************************************************************************************************/
/**
 * @file      : Dma_Drv_PBcfg.c
 * @brief     : AUTOSAR CDD Dma post-build configure source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup  Dma
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Dma_Drv.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */

#define DMA_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define DMA_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define DMA_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define DMA_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define DMA_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define DMA_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define DMA_DRV_PBCFG_C_SW_PATCH_VERSION            2U


#if (DMA_DRV_PBCFG_C_VENDOR_ID != DMA_DRV_H_VENDOR_ID)
    #error "Vendor ID of Dma_Drv_PBcfg.c and Dma_Drv.h are different "
#endif

#if ((DMA_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (DMA_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (DMA_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != DMA_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Dma_Drv_PBcfg.c and Dma_Drv.h are different"
#endif

#if ((DMA_DRV_PBCFG_C_SW_MAJOR_VERSION != DMA_DRV_H_SW_MAJOR_VERSION) || \
    (DMA_DRV_PBCFG_C_SW_MINOR_VERSION != DMA_DRV_H_SW_MINOR_VERSION) || \
    (DMA_DRV_PBCFG_C_SW_PATCH_VERSION != DMA_DRV_H_SW_PATCH_VERSION))
     #error "Software version of Dma_Drv_PBcfg.c and Dma_Drv.h are different"
#endif


/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define DMA_START_SEC_VAR_INIT_UNSPECIFIED
#include "Dma_MemMap.h"

/**
* @brief   DMA logic channel id 0 request source init configuration.
*
*/
static Dma_Drv_RequestConfigType Dma_Drv_ChRequestCfg0 =
{   
    DMA_DRV_REQ_UART0_TX,
    (boolean)FALSE,
};

/**
* @brief   DMA logic channel id 0 priority init configuration.
*
*/
static Dma_Drv_PriorityConfigType Dma_Drv_ChPriorityCfg0 =
{
    (uint8)DMA_DRV_PRIORITY_LEVEL_0,
    (boolean)FALSE,
    (boolean)FALSE,
};



#define DMA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dma_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

/**
* @brief   DMA module 0 init configuration
*
*/
static const Dma_Drv_ConfigType Dma_Drv_ModuleConfig0 =
{
    (boolean)FALSE,
    (boolean)FALSE,
    (boolean)FALSE
};


#define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_START_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"

const Dma_Drv_ConfigType * const  Dma_Drv_ModuleCfgArrayPtr[DMA_DRV_MODULE_TOTALNUM]=
{
/**
* @brief   DMA module 0 init configuration
*
*/
    &Dma_Drv_ModuleConfig0,
};


#define DMA_STOP_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"


#define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

/**
* @brief   DMA logic channel id 0 init configuration
*
*/
const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg0 =
{
    (boolean)FALSE,
    (boolean)FALSE,
    &Dma_Drv_ChRequestCfg0,
    &Dma_Drv_ChPriorityCfg0
};



#define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma */
/** @} end of group Dma_Module */

