/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file CddDma_PBcfg.c
 * @brief 
 * 
 */



#include "CddDma.h"
#include "CddDma_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID_PBCFG_C                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define CDDDMA_SW_MAJOR_VERSION_PBCFG_C               (2)
#define CDDDMA_SW_MINOR_VERSION_PBCFG_C               (3)
#define CDDDMA_SW_PATCH_VERSION_PBCFG_C               (0)

/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CDDDMA header file are of the same vendor */
#if (CDDDMA_VENDOR_ID_PBCFG_C != CDDDMA_VENDOR_ID_PBCFG)
#error "CddDma_PBcfg.c and CddDma_PBcfg.h have different vendor ids"
#endif

/* Check if source file and CDDDMA header file are of the same Autosar version */
#if (( CDDDMA_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CDDDMA_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
      ( CDDDMA_AR_RELEASE_MINOR_VERSION_PBCFG_C != CDDDMA_AR_RELEASE_MINOR_VERSION_PBCFG) || \
      ( CDDDMA_AR_RELEASE_REVISION_VERSION_PBCFG_C != CDDDMA_AR_RELEASE_REVISION_VERSION_PBCFG))
#error "AutoSar Version Numbers of CddDma_PBcfg.c and CddDma_PBcfg.h are different"
#endif

/* Check if source file and CDDDMA header file are of the same Software version */
#if (( CDDDMA_SW_MAJOR_VERSION_PBCFG_C != CDDDMA_SW_MAJOR_VERSION_PBCFG) || \
      ( CDDDMA_SW_MINOR_VERSION_PBCFG_C != CDDDMA_SW_MINOR_VERSION_PBCFG) || \
      ( CDDDMA_SW_PATCH_VERSION_PBCFG_C != CDDDMA_SW_PATCH_VERSION_PBCFG))
#error "Software Version Numbers of CddDma_PBcfg.c and CddDma_PBcfg.h are different"
#endif

/*==================================================================================================
 *                                          VARIATES
==================================================================================================*/
#define CDDDMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddDma_MemMap.h"


/**< Dma transfer configuration 0*/
CDDDMA_CONST static const CddDma_TransferConfigType DmaChannelTransferConfig_0 =
{
    /**< Memory address pointing to the source data. */
    .SrcAddr = 0,  
     /**< Memory address pointing to the destination data. */
    .DestAddr = 0, 
     /**< Source data transfer size. */
    .SrcTransferSize = DMA_TRANSFER_SIZE_1_BYTE, 
    /**< Destination data transfer size. */
    .DestTransferSize = DMA_TRANSFER_SIZE_1_BYTE,  
    /**< Sign-extended offset Bytes applied to the current source address to form the next-state value as each source read/write is completed. */
    .SrcOffset = 0, 
    /**< Sign-extended offset Bytes applied to the current destination address to form the next-state value as each source read/write is completed. */
    .DestOffset = 0,  
    /**< Last source address adjustment. */
    .SrcLastAddrAdjust = 0,  
    /**< Last destination address adjustment.
     *Note here it is only valid when ram reload feature is not enabled. */
    .DestLastAddrAdjust = 0, 
    /**< Source address modulo. */
    .SrcModulo = DMA_MODULO_OFF,  
    /**< Destination address modulo. */
    .DestModulo = DMA_MODULO_OFF,
    /**< Number of bytes to be transferred in each service request of the channel. */
    .TransferLoopByteCount = 0,
    /**< Number of major interation count
     * Note: This value is not used when channel link(loop/trigger link) is enabled*/
    .TriggerCount = 1,
    /**< Disables the DMA channel automatic request after the trigger loop completes for the CTS*/
    .DisableReqOnCompletion = TRUE,
    /**< If TRUE the interrupt of Error, Major and HalfMajor will be disabled */
    .ChannelPollingMode = FALSE,
    /**< Used for ram reload feature, it shoule be configured by the API CddDma_ChannelRamReloadConfig */
    .RamReloadEnable = FALSE,
    /**< The address of the next descriptor to be used, when ram reload feature is enabled.
     * Note: this value is not used when ram reload feature is disabled. It shoule be configured by the API CddDma_ChannelRamReloadConfig */
    .RamReloadNextDescAddr = 0U,
    /**< Used to configures the interrupt request for RamReload configuration
     * Note: It shoule be configured by the API CddDma_ChannelRamReloadConfig */
    .RamReloadIntEnable = FALSE,
    /**< Pointer to loopLink transfer configuration structure (defines transfer/trigger loop attributes)
     * Note: this field is only used when transfer loop mapping is enabled from DMA configuration. */
    .LoopTransferConfig = NULL_PTR,
    /**< DMA channel bandwidth control. */
    .EngineStall = DMA_ENGINE_STALL_4_CYCLES,
};
/**< Dma transfer configuration 1*/
CDDDMA_CONST static const CddDma_TransferConfigType DmaChannelTransferConfig_1 =
{
    /**< Memory address pointing to the source data. */
    .SrcAddr = 0,  
     /**< Memory address pointing to the destination data. */
    .DestAddr = 0, 
     /**< Source data transfer size. */
    .SrcTransferSize = DMA_TRANSFER_SIZE_1_BYTE, 
    /**< Destination data transfer size. */
    .DestTransferSize = DMA_TRANSFER_SIZE_1_BYTE,  
    /**< Sign-extended offset Bytes applied to the current source address to form the next-state value as each source read/write is completed. */
    .SrcOffset = 0, 
    /**< Sign-extended offset Bytes applied to the current destination address to form the next-state value as each source read/write is completed. */
    .DestOffset = 0,  
    /**< Last source address adjustment. */
    .SrcLastAddrAdjust = 0,  
    /**< Last destination address adjustment.
     *Note here it is only valid when ram reload feature is not enabled. */
    .DestLastAddrAdjust = 0, 
    /**< Source address modulo. */
    .SrcModulo = DMA_MODULO_OFF,  
    /**< Destination address modulo. */
    .DestModulo = DMA_MODULO_OFF,
    /**< Number of bytes to be transferred in each service request of the channel. */
    .TransferLoopByteCount = 0,
    /**< Number of major interation count
     * Note: This value is not used when channel link(loop/trigger link) is enabled*/
    .TriggerCount = 1,
    /**< Disables the DMA channel automatic request after the trigger loop completes for the CTS*/
    .DisableReqOnCompletion = TRUE,
    /**< If TRUE the interrupt of Error, Major and HalfMajor will be disabled */
    .ChannelPollingMode = FALSE,
    /**< Used for ram reload feature, it shoule be configured by the API CddDma_ChannelRamReloadConfig */
    .RamReloadEnable = FALSE,
    /**< The address of the next descriptor to be used, when ram reload feature is enabled.
     * Note: this value is not used when ram reload feature is disabled. It shoule be configured by the API CddDma_ChannelRamReloadConfig */
    .RamReloadNextDescAddr = 0U,
    /**< Used to configures the interrupt request for RamReload configuration
     * Note: It shoule be configured by the API CddDma_ChannelRamReloadConfig */
    .RamReloadIntEnable = FALSE,
    /**< Pointer to loopLink transfer configuration structure (defines transfer/trigger loop attributes)
     * Note: this field is only used when transfer loop mapping is enabled from DMA configuration. */
    .LoopTransferConfig = NULL_PTR,
    /**< DMA channel bandwidth control. */
    .EngineStall = DMA_ENGINE_STALL_4_CYCLES,
};

/**<Dma transfer configuration for external using*/
CDDDMA_CONST const CddDma_TransferConfigType* const DmaChannelTransferConfigArray[2] =
{
    &DmaChannelTransferConfig_0,
    &DmaChannelTransferConfig_1,
};

/**< Dma Channel golbal configuration*/
CDDDMA_CONST static const CddDma_ChannelConfigType DmaChannelConfig[2] =
{
    /**< DMA hardware channel configuration for DMA_IP_HW_CH_0 */
    {
        .VirtualChannel = DMA_IP_HW_CH_0,   /**< DMA hardware channel number */
        .RequestSource = DMA_REQ_DISABLED,  /**< Selects the source of the DMA request for this channel */
        {
            .EnErrInt = TRUE,  /**< Enable Error interrupt */
            .EnMajorInt = TRUE,  /**< Enables interrupt after the trigger loop completes for the CTS */
            .EnHalfMajorInt = FALSE,  /**< Enables the half complete interrupt for the CTS */
        },
        .Callback = NULL_PTR,  /**< Callback that will be registered for this channel */
        .CallbackParam = NULL_PTR,  /**< Parameter passed to the channel callback */
        .ErrorCallback = NULL_PTR,  /**< Error Callback that will be registered for this channel */
        .ErrorCallbackParam = NULL_PTR,  /**< Parameter passed to the channel Error callback */
    },
    /**< DMA hardware channel configuration for DMA_IP_HW_CH_1 */
    {
        .VirtualChannel = DMA_IP_HW_CH_1,   /**< DMA hardware channel number */
        .RequestSource = DMA_REQ_DISABLED,  /**< Selects the source of the DMA request for this channel */
        {
            .EnErrInt = TRUE,  /**< Enable Error interrupt */
            .EnMajorInt = TRUE,  /**< Enables interrupt after the trigger loop completes for the CTS */
            .EnHalfMajorInt = FALSE,  /**< Enables the half complete interrupt for the CTS */
        },
        .Callback = NULL_PTR,  /**< Callback that will be registered for this channel */
        .CallbackParam = NULL_PTR,  /**< Parameter passed to the channel callback */
        .ErrorCallback = NULL_PTR,  /**< Error Callback that will be registered for this channel */
        .ErrorCallbackParam = NULL_PTR,  /**< Parameter passed to the channel Error callback */
    },
};

/* CDD Dma Configuration */
CDDDMA_CONST const CddDma_ConfigType CddDma_Config =
{
    .ChannelCount = 2, /**< DMA channel count to be configured */
    .ChannelConfigPtr = DmaChannelConfig,  /**< Pointer to DMA channel configuration */
    .HaltOnError = FALSE,  /**< If enabled DMA will be halted when error occurs. */
    .EnDebug = FALSE,  /**< When in debug mode, the DMA stalls the start of a new channel. Executing channels are allowed to complete.
                       *DMA resumes channel execution when the system exits debug mode or clears the DBGDIS field to 0. */
};

#define CDDDMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddDma_MemMap.h"

