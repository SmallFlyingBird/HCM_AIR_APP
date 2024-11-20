/**************************************************************************************************/
/**
 * @file      : CDD_Dma_PBcfg.c
 * @brief     : AUTOSAR CDD Dma post-build configure source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
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

#include "CDD_Dma.h"
#include "Dma_Drv.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */

#define CDD_DMA_PBCFG_C_VENDOR_ID                   0x00B3U
#define CDD_DMA_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_DMA_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define CDD_DMA_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define CDD_DMA_PBCFG_C_SW_MAJOR_VERSION            1U
#define CDD_DMA_PBCFG_C_SW_MINOR_VERSION            2U
#define CDD_DMA_PBCFG_C_SW_PATCH_VERSION            2U


#if (CDD_DMA_PBCFG_C_VENDOR_ID != CDD_DMA_VENDOR_ID)
    #error "Vendor ID of CDD_Dma_PBcfg.c and CDD_Dma.h are different "
#endif

#if ((CDD_DMA_PBCFG_C_AR_RELEASE_MAJOR_VERSION != CDD_DMA_AR_RELEASE_MAJOR_VERSION) || \
    (CDD_DMA_PBCFG_C_AR_RELEASE_MINOR_VERSION != CDD_DMA_AR_RELEASE_MINOR_VERSION) || \
    (CDD_DMA_PBCFG_C_AR_RELEASE_REVISION_VERSION != CDD_DMA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_Dma_PBcfg.c and CDD_Dma.h are different"
#endif

#if ((CDD_DMA_PBCFG_C_SW_MAJOR_VERSION != CDD_DMA_SW_MAJOR_VERSION) || \
    (CDD_DMA_PBCFG_C_SW_MINOR_VERSION != CDD_DMA_SW_MINOR_VERSION) || \
    (CDD_DMA_PBCFG_C_SW_PATCH_VERSION != CDD_DMA_SW_PATCH_VERSION))
     #error "Software version of CDD_Dma_PBcfg.c and CDD_Dma.h are different"
#endif

#if (CDD_DMA_PBCFG_C_VENDOR_ID != DMA_DRV_H_VENDOR_ID)
    #error "Vendor ID of CDD_Dma_PBcfg.c and Dma_Drv.h are different "
#endif

#if ((CDD_DMA_PBCFG_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (CDD_DMA_PBCFG_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (CDD_DMA_PBCFG_C_AR_RELEASE_REVISION_VERSION != DMA_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_Dma_PBcfg.c and Dma_Drv.h are different"
#endif

#if ((CDD_DMA_PBCFG_C_SW_MAJOR_VERSION != DMA_DRV_H_SW_MAJOR_VERSION) || \
    (CDD_DMA_PBCFG_C_SW_MINOR_VERSION != DMA_DRV_H_SW_MINOR_VERSION) || \
    (CDD_DMA_PBCFG_C_SW_PATCH_VERSION != DMA_DRV_H_SW_PATCH_VERSION))
     #error "Software version of CDD_Dma_PBcfg.c and Dma_Drv.h are different"
#endif

/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"


extern void DMA_CH13_Major_Finish(uint32 LogicChIndex);
extern void DMA_CH15_Major_Finish(uint32 LogicChIndex);

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

/**
* @brief   DMA logic id 0 channel configuration
*
*/
static const Dma_ChannelConfigType Dma_ChCfg0 =
{
    DMA_DRV_PHYS_CH_12,
    NULL_PTR,
    NULL_PTR,
    &Dma_Drv_ChGlobalCfg0,
    &Dma_Drv_ChTransferCfg0
};
/**
* @brief   DMA logic id 1 channel configuration
*
*/
static const Dma_ChannelConfigType Dma_ChCfg1 =
{
    DMA_DRV_PHYS_CH_13,
    NULL_PTR,
    DMA_CH13_Major_Finish,
    &Dma_Drv_ChGlobalCfg1,
    &Dma_Drv_ChTransferCfg1
};
/**
* @brief   DMA logic id 2 channel configuration
*
*/
static const Dma_ChannelConfigType Dma_ChCfg2 =
{
    DMA_DRV_PHYS_CH_14,
    NULL_PTR,
    NULL_PTR,
    &Dma_Drv_ChGlobalCfg2,
    &Dma_Drv_ChTransferCfg2
};
/**
* @brief   DMA logic id 3 channel configuration
*
*/
static const Dma_ChannelConfigType Dma_ChCfg3 =
{
    DMA_DRV_PHYS_CH_15,
    NULL_PTR,
    DMA_CH15_Major_Finish,
    &Dma_Drv_ChGlobalCfg3,
    &Dma_Drv_ChTransferCfg3
};


#define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_START_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"

/**
* @brief   DMA channel configuration
*
*/
static const Dma_ChannelConfigType * const  Dma_ChCfgArrayPtr[DMA_CHANNEL_CFG_TOTALNUM] =
{
    /*  DMA channel logic id 0 configuration */
    &Dma_ChCfg0,
    /*  DMA channel logic id 1 configuration */
    &Dma_ChCfg1,
    /*  DMA channel logic id 2 configuration */
    &Dma_ChCfg2,
    /*  DMA channel logic id 3 configuration */
    &Dma_ChCfg3,
};


#define DMA_STOP_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"


#define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"


static const Dma_ConfigType Dma_Config = 
{    


    /*channel configuration pointer */
    Dma_ChCfgArrayPtr,

    /*module configuration pointer */
    Dma_Drv_ModuleCfgArrayPtr,
};


#define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_START_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"

/*predefined config ptr*/

/**
* @brief          DMA pre-defined config poiter.
*
*/
const Dma_ConfigType * const Dma_PreDefinedConfigPtr =
{
    &Dma_Config
};



#define DMA_STOP_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

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

