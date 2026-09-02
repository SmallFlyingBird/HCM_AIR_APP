/*
* @file    CddDma_Lld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CDDDMA_LLD_H
#define CDDDMA_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_LLD_VENDOR_ID                      (180)
#define CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define CDDDMA_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define CDDDMA_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define CDDDMA_LLD_SW_MAJOR_VERSION               (2)
#define CDDDMA_LLD_SW_MINOR_VERSION               (3)
#define CDDDMA_LLD_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/

/*!
 * @brief This function is used to Initializes the DMA controller
 *
 * @details This service is a non reentrant function that shall initialize the DMA controller
 *
 * @param[in] ConfigPtr Pointer to the configuration structure
 *
 * @return CddDma_ReturnType
 * @retval DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 * @retval DMA_IP_STATUS_WRONG_STATE is returned if the Dma Channel state isn't in Reset State.
 */
CddDma_ReturnType Dma_Lld_Init(const CddDma_ConfigType *ConfigPtr);

/*!
 * @brief This function deinitialize the CDDDMA Driver
 *
 * @details This service is a non reentrant function that shall deinitialize the DMA controller
 *
 * @return void
 */
void Dma_Lld_Deinit(void);

/*!
 * @brief This function is Enable/Disable dma request for Channel
 *
 * @details
 *
 * @param[in] Channel DMAMUX Channel number.
 * @param[in] Enable  Enable/disable dma request [TRUE/FALSE]
 *
 * @return void
 */
void Dma_Lld_SetDmaRequestCmd(uint8 Channel, boolean Enable);

/*!
 * @brief Triggers the DMA Channel.
 *
 * @param[in] Channel DMA Channel number..
 *
 * @return void
 */
void Dma_Lld_TriggerChannelStart(uint8 Channel);

/*!
 * @brief Configures the DMA transfer.
 *
 * @details This function sets DMA Channel transfer settings. The user passes a block of memory into this
 *          function that configures the transfer properties (transfer/trigger loop count, address offsets, Channel linking...).
 *          The DMA driver copies the configuration to CTS registers.
 *
 * @param[in] Channel        DMA virtual Channel number.
 * @param[in] TransferConfig Pointer to the transfer configuration structure; this structure defines fields for setting
 *                           up the basic transfer and also a pointer to a memory structure that defines the loop chain
 *                           properties (minor/major).
 *
 * @return StatusType
 * @retval E_OK is returned if the initialization finished ok.
 * @retval E_NOT_OK is returned if the Dma Ip Channel state isn't Dma_Ip_Ch_ReadyState.
 */
StatusType Dma_Lld_SetChannelTransfer(uint8 Channel, const CddDma_TransferConfigType *TransferConfig);

/*!
 * @brief This function is to get the remaining trigger count of the DMA Channel
 * @details This service is a reentrant function that shall get the remaining trigger count of the DMA Channel.
 *
 * @param[in] Channel The DMA Channel number
 *
 * @return uint32 Remaining trigger count of the DMA Channel
 */
uint32 Dma_Lld_GetRemainingTriggerCount(uint8 Channel);

#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0)
/*!
 * @brief Copies the Channel transfer configuration to the software CTS structure
 * @details This function copies the properties from the Channel configuration to the software CTS structure; the address
 *          of the software CTS can be used to Enable ram reload operation (pointer to the next CTS).
 *
 * @param[in] TransferConfig The pointer to the Channel transfer configuration structure
 * @param[in] Scts           Pointer to the software CTS structure
 *
 * @return void
 */
void Dma_Lld_PushConfigToScts(const CddDma_TransferConfigType *TransferConfig, CddDma_SoftwareCtsType *Scts);
#endif

/*!
* @brief Registers the IRQ callback function and the parameter for DMA Channel.
* @details This function registers the callback function and the parameter into the DMA Channel state structure.
*          The callback function is called when the Channel is complete.
*
* @param[in] Channel   DMA virtual Channel number.
* @param[in] Callback  The pointer to the callback function.
* @param[in] Parameter The pointer to the callback function's parameter.
*
* @return void
*/
void Dma_Lld_InstallCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, void *Parameter);

/*!
* @brief Registers the Error IRQ callback function and the parameter for DMA Channel.
* @details This function registers the callback function and the parameter into the DMA Channel state structure.
*          The callback function is called when the Channel error event occurs.
*
* @param[in] Channel   DMA virtual Channel number.
* @param[in] Callback  The pointer to the callback function.
* @param[in] Parameter The pointer to the callback function's parameter.
*
* @return void
*/
void Dma_Lld_InstallErrorCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, void *Parameter);

/**
 * @brief This function gets Dma Ip Logic Channel Status.
 * @details This service is a reentrant function that shall get the Dma Channel status.
 *          The command shall read specific functionalities of the Dma Channel.
 *
 * @param[in]  Channel        Selection value of the Logic Channel.
 * @param[out] ChannelStatus  Pointer to the Dma Channel status.
 *
 * @return void
 */
void Dma_Lld_GetChannelStatus(uint8 Channel, CddDma_ChannelStatusReturnType *ChannelStatus);

/**
 * @brief This function clears the the DMA Channel's Done state
 *
 * @param[in]  Channel Selection value of the Logic Channel.
 *
 * @return               void
 */
void Dma_Lld_ClearChannelDoneStatus(uint8 Channel);

/**
 * @brief This function is to cancel the remaining data transfer. Stop the executing Channel and force the
 * minor loop to finish.
 * @details The cancel takes effect after the last write of the current read/write sequence. The CX bit
 * clears itself after the cancel has been honored. This cancel retires the Channel normally as if the
 * minor loop was completed.
 *
 * @param[in]  void.
 * @return void
 */
void Dma_Lld_TransferCancel(void);

/**
 * @brief This function is the Error Interrupt Service Handler
 * @details
 *
 * @param[in]  void.
 * @return void
 */
void DMA_Error_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* End of file CddDma_Lld.h */

