/**************************************************************************************************/
/**
 * @file      : Dma_Drv.h
 * @brief     : Dma_Drv module head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DMA_DRV_H
#define DMA_DRV_H

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup  Dma_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Dma_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define DMA_DRV_H_VENDOR_ID                   0x00B3U
#define DMA_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define DMA_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define DMA_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define DMA_DRV_H_SW_MAJOR_VERSION            1U
#define DMA_DRV_H_SW_MINOR_VERSION            2U
#define DMA_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Dma_Drv_Types.h are the same vendor */
#if (DMA_DRV_H_VENDOR_ID != DMA_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Dma_Drv.h and Dma_Drv_Types.h are different"
#endif
/* Check if current file and Dma_Drv_Types.h are the same Autosar version */
#if ((DMA_DRV_H_AR_RELEASE_MAJOR_VERSION != DMA_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (DMA_DRV_H_AR_RELEASE_MINOR_VERSION != DMA_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (DMA_DRV_H_AR_RELEASE_REVISION_VERSION != DMA_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Dma_Drv.h and Dma_Drv_Types.h are different"
#endif
/* Check if current file and Dma_Drv_Types.h are the same Software version */
#if ((DMA_DRV_H_SW_MAJOR_VERSION != DMA_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (DMA_DRV_H_SW_MINOR_VERSION != DMA_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (DMA_DRV_H_SW_PATCH_VERSION != DMA_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Dma_Drv.h and Dma_Drv_Types.h are different"
#endif


/** @} end of group Public_MacroDefinition */



/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
DMA_DRV_CONFIG_EXT

#define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"

/**
 * @brief      Get last error channel id.
 *
 * @param[in]  ErrStateRegVal Last DMA error status register value.
 *
 * @return     Channel where the last error occurred.
 * @retval     DMA_DRV_PHYS_CH_0
 * @retval     DMA_DRV_PHYS_CH_1
 * @retval     DMA_DRV_PHYS_CH_2
 * @retval     ...
 * @retval     DMA_DRV_PHYS_CH_15
 *
 */
Dma_Drv_ChannelType Dma_Drv_GetLastErrorChannel(uint16 ErrStateRegVal);

/**
 * @brief      Register dma transfer done callback function.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  MajorIntCallback: Done callback function.
 *
 * @return     None.
 *
 */
void Dma_Drv_InitDoneIrqHandle(const Dma_Drv_ChannelType Channel, Dma_Drv_CallbackType MajorIntCallback);

/**
 * @brief      Halt dma.
 *
 * @param[in]  Cmd: Halt control.
 *                  - DMA_DRV_HALT_ON: Stall the dma start a new channels for transfer.
 *                  - DMA_DRV_HALT_OFF: Dma is not stall.
 *
 * @return     None.
 *
 */
void Dma_Drv_HaltControl(Dma_Drv_HaltType Cmd);

/**
 * @brief      Enable dma channel request.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_EnableChannelRequest(Dma_Drv_ChannelType Channel);

/**
 * @brief      Disable dma channel request.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_DisableChannelRequest(Dma_Drv_ChannelType Channel);

/**
 * @brief      Clear channel int flag.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  IntType: Int type.
 *                      - DMA_DRV_INT_ERROR: Error interrupt.
 *                      - DMA_DRV_INT_DONE: Done interrupt.
 *                      - DMA_DRV_INT_ALL: All interrupts.
 *
 * @return     None.
 *
 */
void Dma_Drv_ClearIntStatus(Dma_Drv_ChannelType Channel, Dma_Drv_IntType IntType);

/**
 * @brief      Get dma busy status.
 *
 * @param[in]  None.
 *
 * @return     Busy status.
 * @retval     TRUE: Is busy.
 * @retval     FALSE: Not busy.
 */
boolean Dma_Drv_GetBusyStatus(void);

/**
 * @brief      Get dma halt status.
 *
 * @param[in]  None.
 *
 * @return     Whether dma halt is asserted or not.
 * @retval     TRUE: Is halted.
 * @retval     FALSE: Not halted.
 *
 */
boolean Dma_Drv_GetHaltStatus(void);

/**
 * @brief      Get dma channel error status.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     Whether dma channel error status is asserted or not.
 * @retval     TRUE: Dma channel configuration error.
 * @retval     FALSE: Dma channel no configuration error.
 *
*/
boolean Dma_Drv_GetChannelErrorStatus(Dma_Drv_ChannelType Channel);

/**
 * @brief      Get dma all channel error status.
 *
 * @param[in]  None.
 *
 * @return     Dma error status. Each bit represents a channel.
 *
 */
uint16 Dma_Drv_GetAllChannelsErrorStatus(void);

/**
 * @brief      Set dma source address.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Address: Dma transfer source address.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetSourceAddr(Dma_Drv_ChannelType Channel, uint32 Address);

/**
 * @brief      Set dma source transfer size.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Size: Dma source transfer size.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetSourceTransferSize(Dma_Drv_ChannelType Channel,
                                                 Dma_Drv_TransferSizeType Size);

/**
 * @brief      Set dma destination address.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Address: Dma transfer destination address.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetDestAddr(Dma_Drv_ChannelType Channel, uint32 Address);

/**
 * @brief      Set dma source address offset in minor loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma source address offset in minor loop.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMinorLoopSrcOffset(Dma_Drv_ChannelType Channel, sint16 Offset);

/**
 * @brief      Set dma destination address offset in minor loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma destination address offset in minor loop.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMinorLoopDestOffset(Dma_Drv_ChannelType Channel, sint16 Offset);

/**
 * @brief      Set dma source address offset after a major loop done.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma source address offset after a major loop done.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMajorLoopSrcOffset(Dma_Drv_ChannelType Channel, sint16 Offset);

/**
 * @brief      Set dma destination address offset after a major loop done.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma destination address offset after a major loop done.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMajorLoopDestOffset(Dma_Drv_ChannelType Channel, sint16 Offset);

/**
 * @brief      Set total number of minor loop in a major loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Num: number of minor loop in a major loop
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMinorLoopNum(Dma_Drv_ChannelType Channel, uint16 Num);

/**
 * @brief      Get number of minor loop that not finished in one major loop.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return number of rest minor loop in a major loop.
 *
 */
uint16 Dma_Drv_GetRestMinorLoopNum(Dma_Drv_ChannelType Channel);

/**
 * @brief      Set dma destination transfer size.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Size: dma destination transfer size
 *
 * @return     None.
 *
 */
void Dma_Drv_SetDestTransferSize(Dma_Drv_ChannelType Channel,
                                             Dma_Drv_TransferSizeType Size);

/**
 * @brief      Set dma transfer num of bytes in a minor loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Num: dma transfer num of bytes in a minor loop
 *
 * @return     None.
 *
 */
void Dma_Drv_SetTransferByteNum(Dma_Drv_ChannelType Channel, uint32 Num);

/**
 * @brief      Disables/enables the DMA request after the transfer complete.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Cmd: disable request after done
 *                  - TRUE: disables the DMA request after the transfer complete
 *                  - FALSE: enables the DMA request after the transfer complete
 *
 * @return     None.
 *
 */
void Dma_Drv_SetDisableRequestAfterDone(Dma_Drv_ChannelType Channel, boolean Cmd);

/**
 * @brief      Software trigger one channel dma transfer.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_TriggerChannelStart(Dma_Drv_ChannelType Channel);

/**
 * @brief      Get channel busy status.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     Whether a channel is busy or not.
 * @retval     TRUE: Is busy.
 * @retval     FALSE: Not busy.
 *
 */
boolean Dma_Drv_GetChannelBusyStatus(Dma_Drv_ChannelType Channel);

/**
 * @brief      Get channel done flag.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     Whether a channel done flag is asserted or not.
 * @retval     TRUE: Done flag is asserted.
 * @retval     FALSE: Done flag is not asserted.
 *
 */
boolean Dma_Drv_GetDoneStatus(Dma_Drv_ChannelType Channel);

/**
 * @brief      Initialize Dma HW module global configuration.
 *
 * @param[in]  ModuleCfgPtr: Pointer to configuration.
 *
 * @return     None.
 *
 */
void Dma_Drv_Init(const Dma_Drv_ConfigType * ModuleCfgPtr);

/**
 * @brief      Clear channel done flag.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_ClearDoneStatus(Dma_Drv_ChannelType Channel);

/**
 * @brief       Config Dma transfer configuration parameter.
 *
 * @param       Channel: Dma channel id.
 * @param       ChTransCfgPtr: Pointer to transfer configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_SetChannelTransferConfig(const Dma_Drv_ChannelType Channel,
                                     const Dma_Drv_ChannelTransferConfigType * ChTransCfgPtr);

/**
 * @brief       Config Dma channel global configuration parameter.
 *
 * @param       Channel: Dma channel id.
 * @param       ChGlobalCfgPtr: Pointer to global configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_SetChannelGlobalConfig(const Dma_Drv_ChannelType Channel,
                                     const Dma_Drv_ChannelGlobalConfigType * ChGlobalCfgPtr);

/**
 * @brief      Get dma last error status.
 *
 * @param[in]  None.
 *
 * @return     Last dma error type and channel id.
 *
 */
uint16 Dma_Drv_GetLastErrorStatus(void);

/**
 * @brief      Set channel int mask.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  IntType: Int type.
 *                      - DMA_DRV_INT_ERROR: error interrupt.
 *                      - DMA_DRV_INT_DONE: done interrupt.
 *                      - DMA_DRV_INT_ALL: all interrupt.
 * @param[in]  Control: Int enable.
 *                      - TRUE: Enable.
 *                      - FALSE: Disable.
 *
 * @return     None.
 *
 */
void Dma_Drv_ControlInt(Dma_Drv_ChannelType Channel, Dma_Drv_IntType IntType,
                                    boolean Control);

/**
 * @brief      DMA error interrupt handler.
 *
 * @param[in]  None.
 *
 * @return     None.
 *
 */
void Dma_Drv_ErrorIntHandler(void);

/**
 * @brief      DMA done interrupt handle.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_DoneIntHandler(Dma_Drv_ChannelType Channel);

/**
 * @brief      Install error interrupt callback function.
 *
 * @param[in]  CbFunPtr: Error interrupt callback function.
 *
 * @return     None.
 *
 */
void Dma_Drv_InstallErrIntCallbackFunc(Dma_Drv_ErrIntCallbackType CbFunPtr);

/**
 * @brief       Get Dma transfer configuration parameter.
 *
 * @param[in]   Channel: Dma channel id.
 * @param[out]  ChTransCfgPtr: Pointer to transfer configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_GetChannelTransferConfig(Dma_Drv_ChannelType Channel,
                                    const Dma_Drv_ChannelTransferConfigType * ChTransCfgPtr);

/**
 * @brief       Get Dma channel global configuration parameter.
 *
 * @param[in]   Channel: Dma channel id.
 * @param[out]  ChGlobalCfgPtr: Pointer to global configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_GetChannelGlobalConfig(Dma_Drv_ChannelType Channel,
                                    Dma_Drv_ChannelGlobalConfigType * ChGlobalCfgPtr);

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma  */
/** @} end of group Dma_Module */

#endif  /* DMA_DRV_H */

