/*
* @file    CddDma.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CDDDMA_H
#define CDDDMA_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "CddDma_Cfg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION    (0)
#define CDDDMA_SW_MAJOR_VERSION               (2)
#define CDDDMA_SW_MINOR_VERSION               (3)
#define CDDDMA_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/**
* @file     CddDma.h
*/
/* Check if source file and DMA configuration header file are of the same vendor */
#if (CDDDMA_VENDOR_ID != CDDDMA_VENDOR_ID_CFG)
#error "CddDma.h and CddDma_Cfg.h have different vendor ids"
#endif

/* Check if source file and DMA configuration header file are of the same Autosar version */
#if ((CDDDMA_AR_RELEASE_MAJOR_VERSION != CDDDMA_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDDDMA_AR_RELEASE_MINOR_VERSION != CDDDMA_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDDDMA_AR_RELEASE_REVISION_VERSION != CDDDMA_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of CddDma.h and CddDma_Cfg.h are different"
#endif

/* Check if source file and DMA configuration header file are of the same software version */
#if ((CDDDMA_SW_MAJOR_VERSION != CDDDMA_SW_MAJOR_VERSION_CFG) || \
     (CDDDMA_SW_MINOR_VERSION != CDDDMA_SW_MINOR_VERSION_CFG) || \
     (CDDDMA_SW_PATCH_VERSION != CDDDMA_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of CddDma.h and CddDma_Cfg.h are different"
#endif
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/

#define CDDDMA_INSTANCE_ID ((uint8)0U)  /** @brief CDDDMA MODULE INSTANCE ID */
#define CDDDMA_MODULE_ID ((uint8)256U)  /** @brief CDDDMA MODULE ID */

#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        CDDDMA_DEV_ERROR
 * @brief           CddDma development errors
 * @{
 */
#define CDDDMA_E_INIT_FAILED                   ((uint8)0x10)  /** @brief API CDDDMA_Init service called with wrong parameter. */
#define CDDDMA_E_OUT_OF_RANGE_FAILED           ((uint8)0x11)  /** @brief Current channel number out of range */
#define CDDDMA_E_NOT_INIT_FAILED               ((uint8)0x12)  /** @brief Current channel of DMA not initial */
#define CDDDMA_E_ADDR_INVALID_FAILED           ((uint8)0x13)  /** @brief Transfer address not valid */
#define CDDDMA_E_PARAM_POINTER                 ((uint8)0x14)  /** @brief Error in param pointer */
#define CDDDMA_E_RAMRELOAD_ADDR_UNALIGNED      ((uint8)0x15)  /** @brief The address of TCD for ram reload is not 32Byte aligned*/
#define CDDDMA_E_ADDR_UNALIGNED                ((uint8)0x16)  /** @brief The address of source or destination is not aligned */
#define CDDDMA_E_LOOPCOUNT_INVALID             ((uint8)0x17)  /** @brief The parameter of transfer loop count is invalid */
/** @brief   All API's having pointers as parameters shall return this error if
*            called with with a NULL value
*/
#define CDDDMA_E_UNINIT                            ((uint8)0x05) /** @brief API called without module initialization */
/** @} */
#endif

#define CDDDMA_SID_INIT                        (0x01U)  /** @brief API Service ID for CddDma_Init */
#define CDDDMA_SID_DEINIT                      (0x02U)  /** @brief API Service ID for CddDma_DeInit */
#define CDDDMA_SID_CONFIG_TRANSFER             (0x03U)  /** @brief API Service ID for CddDma_SetLogicChannelTransfer */
#define CDDDMA_SID_START_CHANNEL               (0x04U)  /** @brief API Service ID for CddDma_StartChannel */
#define CDDDMA_SID_STOP_CHANNEL                (0x05U)  /** @brief API Service ID for CddDma_StopChannel */
#define CDDDMA_SID_SOFT_TRIGGER                (0x06U)  /** @brief API Service ID for CddDma_SoftTrigger */
#define CDDDMA_SID_CONFIG_RAM_RELOAD           (0x07U)  /** @brief API Service ID for CddDma_ChannelRamReloadConfig */
#define CDDDMA_SID_INSTALL_CALLBACK            (0x08U)  /** @brief API Service ID for CddDma_InstallCallback */
#define CDDDMA_SID_INSTALL_ERROR_CALLBACK      (0x09U)  /** @brief API Service ID for CddDma_InstallErrorCallback */
#define CDDDMA_SID_GET_CHANNEL_STATUS          (0x0AU)  /** @brief API Service ID for CddDma_GetChannelStatus */
#define CDDDMA_SID_CLEAR_CHANNEL_DONE_STATUS   (0x0BU)  /** @brief API Service ID for CddDma_ClearChannelDoneStatus */
#define CDDDMA_SID_GET_VERSION_INFO            (0x0CU)  /** @brief API Service ID for CddDma_GetVersionInfo */
#define CDDDMA_SID_GET_REMAINING_TRIGGER_COUNT (0x0DU)  /** @brief API Service ID for CddDma_GetRemainingTriggerCount */

#define ALIGNED_32B_MASK                       (0x1FU)  /**@brief MASK for 32Bytes aligned*/

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/** @brief Channel status for DMA channel. */
typedef enum
{
    DMA_CHN_UNINIT = 0U,      /**< DMA channel is not initialized. */
    DMA_CHN_NORMAL = 1U,      /**< DMA channel normal state. */
    DMA_CHN_ERROR  = 2U,      /**< An error occurred in the DMA channel. */
} CddDma_ChannelStatusType;
/** @brief DMA transfer configuration */
typedef enum
{
    DMA_TRANSFER_SIZE_1_BYTE  = 0x0U,   /**< DMA transfer 1 byte */
    DMA_TRANSFER_SIZE_2_BYTE  = 0x1U,   /**< DMA transfer 2 bytes */
    DMA_TRANSFER_SIZE_4_BYTE  = 0x2U,   /**< DMA transfer 4 bytes */
    DMA_TRANSFER_SIZE_16_BYTE = 0x4U,   /**< DMA transfer 16 bytes */
    DMA_TRANSFER_SIZE_32_BYTE = 0x5U,   /**< DMA transfer 32 bytes */
} CddDma_TransferSizeType;

/** @brief Specifies the number of cycles the DMA Engine is stalled. */
typedef enum
{
    DMA_ENGINE_STALL_0_CYCLES = 0U,
    DMA_ENGINE_STALL_4_CYCLES = 2U,
    DMA_ENGINE_STALL_8_CYCLES = 3U
} CddDma_EngineStallType;

/*! @brief DMA modulo configuration
 * DMA source/destination address modulo value when address changes.
 * Implements : dma_modulo_t_Class
 */
typedef enum
{
    DMA_MODULO_OFF   = 0U,
    DMA_MODULO_2B    = 1U,
    DMA_MODULO_4B    = 2U,
    DMA_MODULO_8B    = 3U,
    DMA_MODULO_16B   = 4U,
    DMA_MODULO_32B   = 5U,
    DMA_MODULO_64B   = 6U,
    DMA_MODULO_128B  = 7U,
    DMA_MODULO_256B  = 8U,
    DMA_MODULO_512B  = 9U,
    DMA_MODULO_1KB   = 10U,
    DMA_MODULO_2KB   = 11U,
    DMA_MODULO_4KB   = 12U,
    DMA_MODULO_8KB   = 13U,
    DMA_MODULO_16KB  = 14U,
    DMA_MODULO_32KB  = 15U,
    DMA_MODULO_64KB  = 16U,
    DMA_MODULO_128KB = 17U,
    DMA_MODULO_256KB = 18U,
    DMA_MODULO_512KB = 19U,
    DMA_MODULO_1MB   = 20U,
    DMA_MODULO_2MB   = 21U,
    DMA_MODULO_4MB   = 22U,
    DMA_MODULO_8MB   = 23U,
    DMA_MODULO_16MB  = 24U,
    DMA_MODULO_32MB  = 25U,
    DMA_MODULO_64MB  = 26U,
    DMA_MODULO_128MB = 27U,
    DMA_MODULO_256MB = 28U,
    DMA_MODULO_512MB = 29U,
    DMA_MODULO_1GB   = 30U,
    DMA_MODULO_2GB   = 31U
} CddDma_ModuloType;

/**
 * @brief This type contains the Dma Ip Return Type.
 * @details The Return Type give information for the execution of interfaces.
 *
 */
typedef enum
{
    DMA_IP_STATUS_SUCCESS      = E_OK,
    DMA_IP_STATUS_ERROR        = E_NOT_OK,
    DMA_IP_STATUS_WRONG_STATE  = 2U,
    DMA_IP_STATUS_WRONG_CONFIG = 3U,
} CddDma_ReturnType;
/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/
/** @brief This gives the count of DMA channels for initial*/
typedef uint8 CddDma_ChannelCountType;
/** @brief This gives the numeric ID (hardware channel number) of an DMA channel */
typedef uint8 CddDma_ChannelType;
/** @brief Definition for the DMA channel callback function. */
typedef void (*CddDma_CallbackType)(void *Parameter);
/** @brief This gives parameter of an DMA callback */
typedef void CddDma_CallbackParamType;
/** @brief This gives if DMA halting when error occurs. */
typedef boolean CddDma_HaltOnErrorType;
/** @brief This gives the debug mode of the DMA module for initial. */
typedef boolean CddDma_DebugType;
/** @brief This gives if disable request when DMA completion */
typedef boolean CddDma_DisReqOnCompletionType;
/** @brief This gives if DMA channel enables. */
typedef boolean CddDma_ChannelEnableType;
/** @brief This gives the address for transfer */
typedef uint32 CddDma_TransferAddressType;

/*!
 * @brief DMA loop transfer configuration.
 *
 * This structure configures the basic transfer/trigger loop attributes.
 * Implements : dma_loop_transfer_config_t_Class
 */
typedef struct
{
    uint32 TriggerLoopIterationCount;   /*!< Number of trigger loop iterations. */
    boolean SrcOffsetEnable;            /*!< Selects whether the transfer loop offset is applied to the
                                             source address upon transfer loop completion. */
    boolean DestOffsetEnable;           /*!< Selects whether the transfer loop offset is applied to the
                                             destination address upon transfer loop completion. */
    sint32 TriggerLoopOffset;           /*!< Sign-extended offset applied to the source or destination address
                                             to form the next-state value after the transfer loop completes. */
    boolean TransferLoopChnLinkEnable;  /*!< Enables channel-to-channel linking on transfer loop complete. */
    uint8 TransferLoopChnLinkNumber;    /*!< The number of the next channel to be started by DMA
                                             engine when transfer loop completes. */
    boolean TriggerLoopChnLinkEnable;   /*!< Enables channel-to-channel linking on trigger loop complete. */
    uint8 TriggerLoopChnLinkNumber;     /*!< The number of the next channel to be started by DMA
                                             engine when trigger loop completes. */
} CddDma_LoopTransferConfigType;

typedef struct
{
    CddDma_TransferAddressType SrcAddr;   /*!< Memory address pointing to the source data. */
    CddDma_TransferAddressType DestAddr;  /*!< Memory address pointing to the destination data. */
} CddDma_RamReloadListType;


/*!
 * @brief DMA transfer size configuration.
 *
 * This structure configures the basic source/destination transfer attribute.
 * Implements : dma_transfer_config_t_Class
 */
typedef struct
{
    CddDma_TransferAddressType SrcAddr;                        /*!< Memory address pointing to the source data. */
    CddDma_TransferAddressType DestAddr;                       /*!< Memory address pointing to the destination data. */
    CddDma_TransferSizeType SrcTransferSize;                   /*!< Source data transfer size. */
    CddDma_TransferSizeType DestTransferSize;                  /*!< Destination data transfer size. */
    sint16 SrcOffset;                                           /*!< Sign-extended offset Bytes applied to the current source address
                                                                    to form the next-state value as each source read/write
                                                                    is completed. */
    sint16 DestOffset;                                          /*!< Sign-extended offset Bytes applied to the current destination
                                                                    address to form the next-state value as each source
                                                                    read/write is completed. */
    sint32 SrcLastAddrAdjust;                                   /*!< Last source address adjustment. */
    sint32 DestLastAddrAdjust;                                  /*!< Last destination address adjustment. Note here it is only
                                                                     valid when ram reload feature is not enabled. */
    CddDma_ModuloType SrcModulo;                               /*!< Source address modulo. */
    CddDma_ModuloType DestModulo;                              /*!< Destination address modulo. */
    uint32 TransferLoopByteCount;                               /*!< Number of bytes to be transferred in each service request
                                                                     of the channel. */
    uint32 TriggerCount;                                        /*!< Number of major interation count */
    CddDma_DisReqOnCompletionType DisableReqOnCompletion;       /*!< Disables the DMA request after the trigger loop completes
                                                                 for the CTS*/
    boolean ChannelPollingMode;                                 /*!< If TRUE will disable the interrupt of Error and trigger loop done or half done*/
    boolean RamReloadEnable;                                    /*!< Enable ram reload feature */
    uint32 RamReloadNextDescAddr;                               /*!< The address of the next descriptor to be used, when
                                                                     ram reload feature is enabled.
                                                                     Note: this value is not used when ram reload
                                                                     feature is disabled. */
    boolean RamReloadIntEnable;                                 /*!< Enable/disable the interrupt request for RamReload configuration*/
    const CddDma_LoopTransferConfigType *LoopTransferConfig;    /*!< Pointer to loop transfer configuration structure
                                                                     (defines transfer/trigger loop attributes)
                                                                     Note: this field is only used when transfer loop mapping is
                                                                     enabled from DMA configuration. */
    CddDma_EngineStallType EngineStall;                         /*!< DMA channel bandwidth control. */
} CddDma_TransferConfigType;

typedef struct
{
    CddDma_ChannelStatusType ChannelStateValue;  /*!< The ChStateValue value is read from the internal DMA Driver Channel State Machine. */
    uint32  Errors;                              /*!< The Errors value is read from the DMA Channel Error Register (CHx_ERS) as it is */
    boolean Active;                              /*!< The Active value is read from the DMA Channel Control and Status Register (CHx_CSR)
                                                      field ACTIVE. */
    boolean Done;                                /*!< The Active value is read from the DMA Channel Control and Status Register (CHx_CSR)
                                                      field DONE. */
} CddDma_ChannelStatusReturnType;

/*! @brief DMA CTS
 * DMA CTS structure, reflects DMA CTS configuration registers.
 * Implements : dma_software_cts_t_Class
 */
typedef struct
{
    uint32 SADDR;              /*!< Source address */
    sint16 SOFF;               /*!< Source offset */
    uint16 ATTR;               /*!< Transfer attributes */
    uint32 BCNT;               /*!< One loop transfer byte count */
    sint32 STO;                /*!< Source trigger loop offset */
    uint32 DADDR;              /*!< Destination address */
    sint16 DOFF;               /*!< Destination offset */
    uint16 TCNT;               /*!< Trigger loop transfer count */
    sint32 RamLoadAddr;      /*!< RAM load address */
    uint16 CSR;                /*!< Control/status register */
    uint16 TCNTRV;             /*!< Trigger loop counter value */
} CddDma_SoftwareCtsType;

/** @brief The user configuration structure for the an DMA module config. */
typedef struct
{
    boolean EnErrInt;                                /**< Error interrupt */
    boolean EnMajorInt;                              /**< Enables interrupt after the trigger loop completes for the CTS*/
    boolean EnHalfMajorInt;                          /**< Enables the half complete interrupt for the CTS */
} Dma_ChanInterruptType;

typedef struct
{
    CddDma_HwChannelType VirtualChannel;            /**< DMA virtual channel number */
    CddDma_RequestSourceType RequestSource;         /**< Selects the source of the DMA request for this channel */
    Dma_ChanInterruptType ChanIntRequest;           /**< Channel interrupt configuration */
    CddDma_CallbackType Callback;                   /**< Callback that will be registered for this channel */
    CddDma_CallbackParamType *CallbackParam;        /**< Parameter passed to the channel callback */
    CddDma_CallbackType ErrorCallback;              /**< Error Callback that will be registered for this channel */
    CddDma_CallbackParamType *ErrorCallbackParam;   /**< Parameter passed to the channel callback */
} CddDma_ChannelConfigType;
/** @brief The user state structure for the an DMA channel state. */
typedef struct
{
    CddDma_ChannelEnableType ChannelEnable;         /**< DMA channel if enable */
    CddDma_CallbackType Callback;                   /**< Callback that will be registered for this channel */
    CddDma_CallbackParamType *CallbackParam;        /**< Parameter passed to the channel callback */
    CddDma_CallbackType ErrorCallback;              /**< Error Callback that will be registered for this channel */
    CddDma_CallbackParamType *ErrorCallbackParam;   /**< Parameter passed to the channel callback */
    CddDma_ChannelStatusType Status;                /**< DMA channel status */
} CddDma_ChannelStateType;
/** @brief The user configuration structure for the an DMA config. */
typedef struct
{
    CddDma_ChannelCountType ChannelCount;                /**< DMA channel count */
    const CddDma_ChannelConfigType *ChannelConfigPtr;    /**< Pointer to DMA channel configuration */
    CddDma_HaltOnErrorType HaltOnError;                  /**< If DMA halting when error occurs. */
    CddDma_DebugType EnDebug;                            /**< When in debug mode, the DMA stalls the start of a new channel. Executing channels are
                                                              allowed to complete. DMA resumes channel execution when the system exits debug mode or
                                                              clears the DBGDIS field to 0. */
} CddDma_ConfigType;

/*==================================================================================================
 *                                          VARIATES
==================================================================================================*/

extern CddDma_ChannelStateType CddDma_State[CDDDMA_CHANNEL_CONFIG_COUNT];

/*==================================================================================================
 *                                   EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                   GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief            This function initializes the run-time state structure to provide the DMA channel allocation
*                   release, protect, and track the state for channels. This function also resets the DMA modules,
*                   initializes the module to user-defined settings and default settings.
* @details
* @param[in]        ConfigPtr Pointer to user configuration structure for DMA peripheral drivers.
* @return           void
*
*/
void CddDma_Init(const CddDma_ConfigType *ConfigPtr);

/**
* @brief            This function resets the DMA module to reset state and disables the interrupt to the core.
* @details
* @return           void
*
*/
void CddDma_DeInit(void);

/**
* @brief            This function enables the DMA channel DMA request.
* @details
* @param[in]        VirtualChannel  DMA virtual channel number.
* @return           void
*
* @note             service_id:       0x03
*                   is_reentrant:     true
*                   is_synchronous:   true
*                   autosar_api:      false
*/
void CddDma_StartChannel(CddDma_ChannelType VirtualChannel);

/**
* @brief            This function disables the DMA channel DMA request.
* @details
* @param[in]        VirtualChannel  DMA virtual channel number.
* @return           void
*/
void CddDma_StopChannel(CddDma_ChannelType VirtualChannel);

/**
* @brief            This function starts a transfer using the current channel (software request).
* @details
* @param[in]        VirtualChannel  DMA virtual channel number.
* @return           void
*
*/
void CddDma_SoftTrigger(CddDma_ChannelType VirtualChannel);

/*!
 * @brief Sets Dma channel transfer settings.
 *
 * @details This function configures the DMA transfer in a loop chain or multi-block transfer.
 *          If the loop chain is enabled,user passes a block of memory into this function that configures the loop transfer
 *          properties (transfer/trigger loop count, address offsets, channel linking).The DMA driver copies the configuration
 *          to CTS registers, only when the loop properties are set up correctly and transfer loop mapping is enabled for the
 *          DMA module.
 *          If the loop chain is not used the function considers contiguous memory blocks, thus it configures the CTS
 *          source/destination offset fields to cover the data buffer without gaps, according to "transferSize" parameter
 *          (the offset is equal to the number of bytes transferred in a source read/destination write). The buffer is divided
 *          in multiple block, each block being transferred upon a single DMA request.
 *
 * @param[in] VirtualChannel  DMA virtual channel number.
 * @param[in]        SrcAddr  A source register address or a source memory address.
 * @param[in]        DestAddr A destination register address or a destination memory address.
 * @param[in] TransferConfig  Pointer to the transfer configuration structure; this structure defines fields for setting
 *                            up the basic transfer and also a pointer to a memory structure that defines the loop chain properties (minor/major).
 *
 * @return StatusType
 * @retval E_OK is returned if the DMA channel is configured successfully
 * @retval E_NOT_OK is returned if the DMA channel configuration is not asserted
 *
 */
StatusType CddDma_SetLogicChannelTransfer(CddDma_ChannelType VirtualChannel, uint32 SrcAddr, uint32 DestAddr, \
        const CddDma_TransferConfigType *TransferConfig);

#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0)
/*!
* @brief  This function configures DMA for ram reload operation
* @details This function configures the CTS descriptors into a single linked List or circular linked List. The user passes blocks of memory into
*          this function. The loop done interrupt is triggered only when the last memory block is completed, if loop mode is enabled the loop done
*          interrupt is triggered every time when a loop is completed. The memory block information is passed with the CddDma_RamReloadListType data
*          structure, which can tell the memory source and destination address.
*          NOTE: Expect for the source/destination address, all other parameters related to the transmission(such as offset, BCNT, TCNT, TCNTRV..)
*                are consistent with the third input parameter 'TransferConfig'.
*
* @param[in] VirtualChannel  DMA virtual channel number.
* @param[in] List            Data structure storing the source and destination address
* @param[in] TransferConfig  Pointer to the transfer configuration structure; this structure defines fields for setting
*                            up the basic transfer and also a pointer to a memory structure that defines the loop chain properties (minor/major).
* @param[in] Scts            Array of empty software CTS structures. Expect the SrcAddr and DestAddr, all other parameters follow from TransferConfig
*                            The user must prepare this memory block. We don't need a software CTS structure for the first descriptor,
*                            since the configuration is pushed directly to registers.
*                            NOTE:The "Scts" buffer must align with 32 bytes; if not, an error occurs in the DMA driver.
* @param[in] CtsCount        The number of CTS memory blocks contained in the ram reload List.
* @param[in] LoopMode        Enable/disable cycle mode, such as [first TransferConfig]->[Scts 0]->[Scts 1]->...[Scts n] or
*                                                                                          |                        v
*                                                                                          |____________<___________|
*                            [first TransferConfig]->[Scts 0]->[Scts 1]->...[Scts n]->NULL_PTR;
* @return void
*
*/
void CddDma_ChannelRamReloadConfig(CddDma_ChannelType VirtualChannel, const CddDma_RamReloadListType *List,
                                   CddDma_TransferConfigType *TransferConfig,
                                   CddDma_SoftwareCtsType *Scts, uint8 CtsCount, boolean LoopMode);
#endif

/*!
* @brief Registers the IRQ callback function and the parameter for DMA channel.
* @details This function registers the callback function and the parameter into the DMA channel state structure.
*          The callback function is called when the channel is complete.
*
* @param[in] VirtualChannel  DMA virtual channel number.
* @param[in] Callback        The pointer to the callback function.
* @param[in] Parameter       The pointer to the callback function's parameter.
* @return void
*
*/
void CddDma_InstallCallback(CddDma_ChannelType VirtualChannel, CddDma_CallbackType Callback, void *Parameter);

/*!
* @brief Registers the ERROR IRQ callback function and the parameter for DMA channel.
* @details This function registers the callback function and the parameter into the DMA channel state structure.
*          The callback function is called when the channel error event occurs.
*
* @param[in] VirtualChannel  DMA virtual channel number.
* @param[in] Callback        The pointer to the callback function.
* @param[in] Parameter       The pointer to the callback function's parameter.
* @return void
*
*/
void CddDma_InstallErrorCallback(CddDma_ChannelType VirtualChannel, CddDma_CallbackType Callback, void *Parameter);

/**
 * @brief This function gets Dma Ip Logic Channel Status.
 * @details This service is a reentrant function that shall get the Dma Channel status.
 *          The command shall read specific functionalities of the Dma Channel.
 *
 * @param[in]  VirtualChannel Selection value of the Logic Channel.
 * @param[out] ChannelStatus  Pointer to the Dma Channel status.
 * @return           void
 *
 */
void CddDma_GetChannelStatus(CddDma_ChannelType VirtualChannel, CddDma_ChannelStatusReturnType *ChannelStatus);

/**
 * @brief This function clears the the DMA channel's Done state
 *
 * @param[in]  VirtualChannel Selection value of the Logic Channel.
 * @return           void
 *
 */
void CddDma_ClearChannelDoneStatus(CddDma_ChannelType VirtualChannel);

/**
 * @brief This function returns the remaining trigger count of the DMA channel.
 *
 * @param[in]  VirtualChannel The DMA channel number.
 * @return           uint32
 *
 */
uint32 CddDma_GetChannelRemainingTriggerCount(CddDma_ChannelType VirtualChannel);

#if (((CDDDMA_VERSION_INFO_API == STD_ON) && (CDDDMA_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details
 *
 * @param[out]       Versioninfo Pointer to where to store version information of this module
 * @return           void
 *
 */
#define CddDma_GetVersionInfo(Versioninfo)                                        \
    {                                                                             \
        /* Check for DET: CDDDMA_E_PARAM_POINTER */                               \
        if ((Versioninfo) == NULL_PTR)                                            \
        {                                                                         \
            /* Report CDDDMA_E_PARAM_POINTER DET if service called with           \
               NULL_PTR                                                           \
            */                                                                    \
            Det_ReportError(                                                      \
                (uint16)CDDDMA_MODULE_ID,                                         \
                CDDDMA_INSTANCE_ID,                                               \
                CDDDMA_SID_GET_VERSION_INFO,                                      \
                CDDDMA_E_PARAM_POINTER);                                          \
        }                                                                         \
        else                                                                      \
        {                                                                         \
            /* Vendor ID information */                                           \
            ((Std_VersionInfoType *)(Versioninfo))->vendorID = CDDDMA_VENDOR_ID;  \
            /* CddDma module ID information */                                    \
            ((Std_VersionInfoType *)(Versioninfo))->moduleID = CDDDMA_MODULE_ID;  \
            /* CddDma module Software major version information */                \
            ((Std_VersionInfoType *)(Versioninfo))->sw_major_version =            \
                (uint8)CDDDMA_SW_MAJOR_VERSION;                                   \
            /* CddDma module Software minor version information */                \
            ((Std_VersionInfoType *)(Versioninfo))->sw_minor_version =            \
                (uint8)CDDDMA_SW_MINOR_VERSION;                                   \
            /* CddDma module Software patch version information */                \
            ((Std_VersionInfoType *)(Versioninfo))->sw_patch_version =            \
                (uint8)CDDDMA_SW_PATCH_VERSION;                                   \
        }                                                                         \
    }
#elif (((CDDDMA_VERSION_INFO_API == STD_ON) && (CDDDMA_DEV_ERROR_DETECT == STD_OFF)))
#define CddDma_GetVersionInfo(Versioninfo)                                        \
    {                                                                             \
        /* Vendor ID information */                                               \
        ((Std_VersionInfoType *)(Versioninfo))->vendorID = CDDDMA_VENDOR_ID;      \
        /* CddDma module ID information */                                        \
        ((Std_VersionInfoType *)(Versioninfo))->moduleID = CDDDMA_MODULE_ID;      \
        /* CddDma module Software major version information */                    \
        ((Std_VersionInfoType *)(Versioninfo))->sw_major_version =                \
            (uint8)CDDDMA_SW_MAJOR_VERSION;                                       \
        /* CddDma module Software minor version information */                    \
        ((Std_VersionInfoType *)(Versioninfo))->sw_minor_version =                \
            (uint8)CDDDMA_SW_MINOR_VERSION;                                       \
        /* CddDma module Software patch version information */                    \
        ((Std_VersionInfoType *)(Versioninfo))->sw_patch_version =                \
            (uint8)CDDDMA_SW_PATCH_VERSION;                                       \
    }
#endif /* CDDDMA_VERSION_INFO_API == STD_ON && CDDDMA_DEV_ERROR_DETECT == STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* End of file CddDma.h */

