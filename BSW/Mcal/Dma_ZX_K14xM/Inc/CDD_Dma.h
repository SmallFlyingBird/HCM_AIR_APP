/**************************************************************************************************/
/**
 * @file      : CDD_Dma.h
 * @brief     : CDD_Dma module head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CDD_DMA_H
#define CDD_DMA_H

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup  CDD_Dma
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_Dma_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CDD_DMA_MODULE_ID                   2049U
#define CDD_DMA_VENDOR_ID                   0x00B3U
#define CDD_DMA_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_DMA_AR_RELEASE_MINOR_VERSION    6U
#define CDD_DMA_AR_RELEASE_REVISION_VERSION 0U
#define CDD_DMA_SW_MAJOR_VERSION            1U
#define CDD_DMA_SW_MINOR_VERSION            2U
#define CDD_DMA_SW_PATCH_VERSION            1U

/* Check if current file and CDD_Dma_Types.h are the same vendor */
#if (CDD_DMA_VENDOR_ID != CDD_DMA_TYPES_H_VENDOR_ID)
    #error "Vendor ID of CDD_Dma.h and CDD_Dma_Types.h are different"
#endif
/* Check if current file and CDD_Dma_Types.h are the same Autosar version */
#if ((CDD_DMA_AR_RELEASE_MAJOR_VERSION != CDD_DMA_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (CDD_DMA_AR_RELEASE_MINOR_VERSION != CDD_DMA_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (CDD_DMA_AR_RELEASE_REVISION_VERSION != CDD_DMA_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of CDD_Dma.h and CDD_Dma_Types.h are different"
#endif
/* Check if current file and CDD_Dma_Types.h are the same Software version */
#if ((CDD_DMA_SW_MAJOR_VERSION != CDD_DMA_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (CDD_DMA_SW_MINOR_VERSION != CDD_DMA_TYPES_H_SW_MINOR_VERSION) ||                           \
     (CDD_DMA_SW_PATCH_VERSION != CDD_DMA_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of CDD_Dma.h and CDD_Dma_Types.h are different"
#endif

#define DMA_INSTANCE_ID 0
/**
* @brief Service ID 
* */
#define DMA_SID_INIT                             ((uint8)0x00U)
#define DMA_SID_GET_CHANNEL_STATUS               ((uint8)0x01U)
#define DMA_SID_HALT                             ((uint8)0x02U)
#define DMA_SID_CONFIG_CHANNEL_TRANSFER          ((uint8)0x03U)
#define DMA_SID_CONFIG_CHANNEL_GLOBAL_PARAM      ((uint8)0x04U)
#define DMA_SID_ENABLE_CHANNEL_HW_REQUEST        ((uint8)0x05U)
#define DMA_SID_TRIGGER_CHANNEL_START_BY_SW      ((uint8)0x06U)
#define DMA_SID_CLEAR_INT_STATUS                 ((uint8)0x07U)
#define DMA_SID_GET_HW_MODULE_STATUS             ((uint8)0x08U)
#define DMA_SID_SET_SOURCE_ADDR                  ((uint8)0x09U)
#define DMA_SID_SET_DEST_ADDR                    ((uint8)0x0AU)
#define DMA_SID_GET_VERSION_INFO                 ((uint8)0x0BU)
#define DMA_SID_GET_CHANNEL_TRANSFER_CONFIG      ((uint8)0x0CU)
#define DMA_SID_GET_CHANNEL_GLOBAL_PARAM         ((uint8)0x0DU)

/**
* @brief   Api may return following error
*
* */
#define DMA_E_UNINIT                         ((uint8)0x01U)
#define DMA_E_PARAM_POINTER                  ((uint8)0x02U)
#define DMA_E_INVALID_CHANNEL                ((uint8)0x03U)
#define DMA_E_INVALID_COMMAND                ((uint8)0x04U)
#define DMA_E_INVALID_PARAMETER              ((uint8)0x05U)
#define DMA_E_CH_STATE                        ((uint8)0x06U)
#define DMA_E_INIT_FAILED                    ((uint8)0x07U)
/** @} end of group Public_MacroDefinition */



/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (DMA_PRECOMPILE_SUPPORT == STD_ON)
#define DMA_START_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"

extern const Dma_ConfigType *const Dma_PreDefinedConfigPtr;

#define DMA_STOP_SEC_CONFIG_DATA_PTR
#include "Dma_MemMap.h"
#else
    #define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Dma_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
DMA_CONFIG_EXT

    #define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Dma_MemMap.h"
#endif /* (DMA_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"

/**
 * @brief      Dma Initialization function.
 *             - Service ID: 0x00
 *
 * @param[in]  CfgPtr: Pointer to a DMA initial configuration structure.
 *
 * @return     None.
 *
 */
void Dma_Init(const Dma_ConfigType * const CfgPtr);

/**
 * @brief      Get dma channel status.
 *             - Service ID: 0x01
 *
 * @param[in]  LogicChIndex: Logic dma channel index.
 * @param[out] StatusPtr: Pointer to a structure that stores dma channel status.
 *
 * @return     None.
 *
 */
void Dma_GetChannelStatus(const uint32 LogicChIndex, Dma_ChannelStatusType * const StatusPtr);

/**
 * @brief      Halt/resume Dma.
 *             - Service ID: 0x02
 *
 * @param[in] Cmd: Halt control.
 *            - DMA_HALT_OFF: Resume the dma.
 *            - DMA_HALT_ON: Stall the dma.
 *
 * @return    None.
 *
 */
void Dma_Halt(Dma_HaltType Cmd);

/**
 * @brief      Configure Dma channel transfer parameters.
 *             - Service ID: 0x03
 *
 * @param[in]  LogicChIndex: Logic dma channel id.
 * @param[in]  ChConfigPtr: Point to the channel transfer configuration.
 *
 * @return     Std_ReturnType: status
 * @retval     - E_OK: Transfer parameters are configured.
 * @retval     - E_NOT_OK: Transfer parameters are not configured successfully.
 *
 */
Std_ReturnType Dma_ConfigChannelTransfer(const uint32 LogicChIndex, 
                               const Dma_ChannelTransferConfigType *ChConfigPtr);

/**
 * @brief      Configure dma channel global parameters.
 *             - Service ID: 0x04
 *
 * @param[in]  LogicChIndex: Logic dma channel id.
 * @param[in]  ChConfigPtr: Point to the channel global configuration.
 *
 * @return     Std_ReturnType: config status
 * @retval     - E_OK: Global parameters are configured.
 * @retval     - E_NOT_OK: Global parameters are not configured successfully.
 *
 */
Std_ReturnType Dma_ConfigChannelGlobalParam(const uint32 LogicChIndex, 
                                  const Dma_ChannelGlobalConfigType *ChConfigPtr);

/**
 * @brief      Enable/disable channel hardware request.
 *             - Service ID: 0x05
 * 
 * @param[in]  LogicChIndex: Logic channel index.
 * @param[in]  Enable: Enable/disable HW request.
 *
 * @return     None.
 *
 */
void Dma_EnableChannelHwRequest(const uint32 LogicChIndex, boolean Enable);

/**
 * @brief      Software trigger dma transfer.
 *             - Service ID: 0x06
 * 
 * @param[in]  LogicChIndex: Logic channel index.
 *
 * @return     None.
 *
 */
void Dma_TriggerChannelStartBySw(const uint32 LogicChIndex);

/**
 * @brief      Clear channel interrupt status Function
 *             - Service ID: 0x07
 * 
 * @param[in]  LogicChIndex: Logic channel index
 * @param[in]  Int: int type
 *             - DMA_INT_ERROR: error interrupt
 *             - DMA_INT_DONE: done interrupt
 *             - DMA_INT_ALL: all interrupt
 *
 * @return     None.
 *
 */
void Dma_ClearIntStatus(const uint32 LogicChIndex, Dma_IntType Int);

/**
 * @brief      Get Dma HW module status.
 *             - Service ID: 0x08
 * 
 * @param[out] StatusPtr: Pointer to a structure that stores dma HW module status.
 *
 * @return     None.
 *
 */
void Dma_GetHwModuleStatus(Dma_ModuleStatusType * const StatusPtr);

/**
 * @brief      Set dma source address.
 *             - Service ID: 0x09
 *
 * @param[in]  LogicChIndex: Logic channel index
 * @param[in]  Address: Dma transfer source address.
 *
 * @return     None.
 *
 */
void Dma_SetSourceAddr(const uint32 LogicChIndex, uint32 Address);

/**
 * @brief      Set dma destination address.
 *             - Service ID: 0x0A
 *
 * @param[in]  LogicChIndex: Logic channel index
 * @param[in]  Address: Dma transfer destination address.
 *
 * @return     None.
 *
 */
void Dma_SetDestAddr(const uint32 LogicChIndex, uint32 Address);

#if (STD_ON == DMA_VERSIONINFOAPI_SUPPORT)
/**
 * @brief      Get Dma version information.
 *             - Service ID: 0x0B
 *
 * @param[out] VersionInfo: Pointer to structure which stores version info.
 *
 * @return     None.
 *
 */
void Dma_GetVersionInfo(Std_VersionInfoType * const VersionInfo);
#endif

/**
 * @brief      Get Dma channel transfer parameters.
 *             - Service ID: 0x0C
 *
 * @param[in]  LogicChIndex: Logic dma channel id.
 * @param[out]  ChConfigPtr: Point to the channel transfer configuration.
 *
 * @return     Std_ReturnType: status
 * @retval     - E_OK: Get channel transfer parameters successfully.
 * @retval     - E_NOT_OK: Error occurred while getting channel transfer parameters.
 *
 */
Std_ReturnType Dma_GetChannelTransferConfig(const uint32 LogicChIndex, 
                                            const Dma_ChannelTransferConfigType * ChConfigPtr);

/**
 * @brief      Get dma channel global parameters.
 *             - Service ID: 0x0D
 *
 * @param[in]  LogicChIndex: Logic dma channel id.
 * @param[out]  ChConfigPtr: Point to the channel global configuration.
 *
 * @return     Std_ReturnType: status
 * @retval     - E_OK: Get channel global parameters successfully.
 * @retval     - E_NOT_OK: Error occurred while getting channel global parameters.
 *
 */
Std_ReturnType Dma_GetChannelGlobalParam(const uint32 LogicChIndex, 
                                        Dma_ChannelGlobalConfigType * ChConfigPtr);

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma  */
/** @} end of group Dma_Module */

#endif  /* CDD_DMA_H */

