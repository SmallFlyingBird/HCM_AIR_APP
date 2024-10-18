/**************************************************************************************************/
/**
 * @file      : Dma_Drv_PBcfg.c
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
#define DMA_DRV_PBCFG_C_SW_PATCH_VERSION            1U


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
    (boolean)TRUE,
};

/**
* @brief   DMA logic channel id 0 priority init configuration.
*
*/
static Dma_Drv_PriorityConfigType Dma_Drv_ChPriorityCfg0 =
{
    (uint8)DMA_DRV_PRIORITY_LEVEL_12,
    (boolean)FALSE,
    (boolean)FALSE,
};
/**
* @brief   DMA logic channel id 1 request source init configuration.
*
*/
static Dma_Drv_RequestConfigType Dma_Drv_ChRequestCfg1 =
{   
    DMA_DRV_REQ_UART0_RX,
    (boolean)TRUE,
};

/**
* @brief   DMA logic channel id 1 priority init configuration.
*
*/
static Dma_Drv_PriorityConfigType Dma_Drv_ChPriorityCfg1 =
{
    (uint8)DMA_DRV_PRIORITY_LEVEL_13,
    (boolean)FALSE,
    (boolean)FALSE,
};
/**
* @brief   DMA logic channel id 2 request source init configuration.
*
*/
static Dma_Drv_RequestConfigType Dma_Drv_ChRequestCfg2 =
{   
    DMA_DRV_REQ_UART1_TX,
    (boolean)TRUE,
};

/**
* @brief   DMA logic channel id 2 priority init configuration.
*
*/
static Dma_Drv_PriorityConfigType Dma_Drv_ChPriorityCfg2 =
{
    (uint8)DMA_DRV_PRIORITY_LEVEL_14,
    (boolean)FALSE,
    (boolean)FALSE,
};
/**
* @brief   DMA logic channel id 3 request source init configuration.
*
*/
static Dma_Drv_RequestConfigType Dma_Drv_ChRequestCfg3 =
{   
    DMA_DRV_REQ_UART1_RX,
    (boolean)TRUE,
};

/**
* @brief   DMA logic channel id 3 priority init configuration.
*
*/
static Dma_Drv_PriorityConfigType Dma_Drv_ChPriorityCfg3 =
{
    (uint8)DMA_DRV_PRIORITY_LEVEL_15,
    (boolean)FALSE,
    (boolean)FALSE,
};

/**
* @brief   DMA logic channel id 0 source init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChSourceCfg0 =
{
    0U,
    1,
    1,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 0 destination init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChDestCfg0 =
{
    0U,
    0,
    0,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 0 control init configuration
*
*/
static Dma_Drv_TransferControlConfigType Dma_Drv_ChControlCfg0 =
{
    1U,
    1U,
    (boolean)TRUE
};

/**
* @brief   DMA logic channel id 1 source init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChSourceCfg1 =
{
    0U,
    0,
    0,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 1 destination init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChDestCfg1 =
{
    0U,
    1,
    1,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 1 control init configuration
*
*/
static Dma_Drv_TransferControlConfigType Dma_Drv_ChControlCfg1 =
{
    1U,
    1U,
    (boolean)TRUE
};

/**
* @brief   DMA logic channel id 2 source init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChSourceCfg2 =
{
    0U,
    1,
    1,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 2 destination init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChDestCfg2 =
{
    0U,
    0,
    0,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 2 control init configuration
*
*/
static Dma_Drv_TransferControlConfigType Dma_Drv_ChControlCfg2 =
{
    1U,
    1U,
    (boolean)TRUE
};

/**
* @brief   DMA logic channel id 3 source init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChSourceCfg3 =
{
    0U,
    0,
    0,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 3 destination init configuration
*
*/
static Dma_Drv_AddrConfigType Dma_Drv_ChDestCfg3 =
{
    0U,
    1,
    1,
    DMA_DRV_TRANSFER_SIZE_1BYTE,
};

/**
* @brief   DMA logic channel id 3 control init configuration
*
*/
static Dma_Drv_TransferControlConfigType Dma_Drv_ChControlCfg3 =
{
    1U,
    1U,
    (boolean)TRUE
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
    (boolean)TRUE,
    (boolean)TRUE,
    (boolean)TRUE
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
/**
* @brief   DMA logic channel id 1 init configuration
*
*/
const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg1 =
{
    (boolean)FALSE,
    (boolean)TRUE,
    &Dma_Drv_ChRequestCfg1,
    &Dma_Drv_ChPriorityCfg1
};
/**
* @brief   DMA logic channel id 2 init configuration
*
*/
const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg2 =
{
    (boolean)FALSE,
    (boolean)FALSE,
    &Dma_Drv_ChRequestCfg2,
    &Dma_Drv_ChPriorityCfg2
};
/**
* @brief   DMA logic channel id 3 init configuration
*
*/
const Dma_Drv_ChannelGlobalConfigType Dma_Drv_ChGlobalCfg3 =
{
    (boolean)FALSE,
    (boolean)TRUE,
    &Dma_Drv_ChRequestCfg3,
    &Dma_Drv_ChPriorityCfg3
};

/**
* @brief   DMA logic id 0 channel transfer init configuration
*
*/
const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg0 =
{
	&Dma_Drv_ChSourceCfg0,
	&Dma_Drv_ChDestCfg0,
    &Dma_Drv_ChControlCfg0
};
/**
* @brief   DMA logic id 1 channel transfer init configuration
*
*/
const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg1 =
{
	&Dma_Drv_ChSourceCfg1,
	&Dma_Drv_ChDestCfg1,
    &Dma_Drv_ChControlCfg1
};
/**
* @brief   DMA logic id 2 channel transfer init configuration
*
*/
const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg2 =
{
	&Dma_Drv_ChSourceCfg2,
	&Dma_Drv_ChDestCfg2,
    &Dma_Drv_ChControlCfg2
};
/**
* @brief   DMA logic id 3 channel transfer init configuration
*
*/
const Dma_Drv_ChannelTransferConfigType Dma_Drv_ChTransferCfg3 =
{
	&Dma_Drv_ChSourceCfg3,
	&Dma_Drv_ChDestCfg3,
    &Dma_Drv_ChControlCfg3
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

