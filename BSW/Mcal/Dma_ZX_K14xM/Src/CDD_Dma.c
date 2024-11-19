/**************************************************************************************************/
/**
 * @file      : CDD_Dma.c
 * @brief     : CDD_Dma driver source file
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

/** @addtogroup  CDD_Dma
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_Dma.h"
#include "Dma_Drv.h"


#if (STD_ON == DMA_DEV_ERROR_DETECT)
#include "Det.h"
#endif
/** @defgroup Private_MacroDefinition
 *  @{
 */

#define CDD_DMA_C_VENDOR_ID                   0x00B3U
#define CDD_DMA_C_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_DMA_C_AR_RELEASE_MINOR_VERSION    6U
#define CDD_DMA_C_AR_RELEASE_REVISION_VERSION 0U
#define CDD_DMA_C_SW_MAJOR_VERSION            1U
#define CDD_DMA_C_SW_MINOR_VERSION            2U
#define CDD_DMA_C_SW_PATCH_VERSION            2U


#if (CDD_DMA_C_VENDOR_ID != CDD_DMA_VENDOR_ID)
    #error "Vendor ID of CDD_Dma.c and CDD_Dma.h are different"
#endif

#if ((CDD_DMA_C_AR_RELEASE_MAJOR_VERSION != CDD_DMA_AR_RELEASE_MAJOR_VERSION) || \
    (CDD_DMA_C_AR_RELEASE_MINOR_VERSION != CDD_DMA_AR_RELEASE_MINOR_VERSION) || \
    (CDD_DMA_C_AR_RELEASE_REVISION_VERSION != CDD_DMA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_Dma.c and CDD_Dma.h are different"
#endif

#if ((CDD_DMA_C_SW_MAJOR_VERSION != CDD_DMA_SW_MAJOR_VERSION) || \
    (CDD_DMA_C_SW_MINOR_VERSION != CDD_DMA_SW_MINOR_VERSION) || \
    (CDD_DMA_C_SW_PATCH_VERSION != CDD_DMA_SW_PATCH_VERSION))
    #error "Software version of CDD_Dma.c and CDD_Dma.h are different"
#endif

#if (CDD_DMA_C_VENDOR_ID != DMA_DRV_H_VENDOR_ID)
    #error "Vendor ID of CDD_Dma.c and Dma_Drv.h are different"
#endif

#if ((CDD_DMA_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (CDD_DMA_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (CDD_DMA_C_AR_RELEASE_REVISION_VERSION != DMA_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_Dma.c and Dma_Drv.h are different"
#endif

#if ((CDD_DMA_C_SW_MAJOR_VERSION != DMA_DRV_H_SW_MAJOR_VERSION) || \
    (CDD_DMA_C_SW_MINOR_VERSION != DMA_DRV_H_SW_MINOR_VERSION) || \
    (CDD_DMA_C_SW_PATCH_VERSION != DMA_DRV_H_SW_PATCH_VERSION))
    #error "Software version of CDD_Dma.c and Dma_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (STD_ON == DMA_DEV_ERROR_DETECT)
        #if ((CDD_DMA_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
            (CDD_DMA_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of CDD_Dma.c and Det.h are different"
        #endif
    #endif
#endif

/**
 * @brief DMA channel error is unknown because hardware only record latest error state.
*/
#define DMA_CH_ERROR_UNKNOWN_STATE (0xFFFFU)

/** @} end of Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

static Dma_ChannelOptStateType Dma_ChannelStateArray[DMA_CHANNEL_CFG_TOTALNUM];

#define DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_START_SEC_VAR_CLEARED_PTR
#include "Dma_MemMap.h"

/**
 * @brief   Pointer to DMA Global Configuration.
 *
 */
static const Dma_ConfigType *Dma_CfgPtr;

#define DMA_STOP_SEC_VAR_CLEARED_PTR
#include "Dma_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/* parameter check */
#if (DMA_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Dma_CheckInit(const Dma_ConfigType * const CfgPtr);
#endif
static uint8 Dma_GetLogicChIndexOfPhyCh(const Dma_Drv_ChannelType PhysChId);
static void Dma_HandlePhysChannelErrInt(const Dma_Drv_ChannelType PhysChId);
static void Dma_HandlePhysChannelDoneInt(const Dma_Drv_ChannelType PhysChId);
static void Dma_UpdateErrorState(const uint32 LogicChIndex);

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
/** @} end of group Private_FunctionDeclaration */


/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"

#if (STD_ON == DMA_DEV_ERROR_DETECT)
/**
 * @brief      Checks validity of DMA configuration parameter.
 *
 * @param[in]  CfgPtr: Pointer to the DMA configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:  Configuration parameter is valid.
 * @retval     E_NOT_OK: Configuration parameter is invalid.
 */
LOCAL_INLINE Std_ReturnType Dma_CheckInit(const Dma_ConfigType * const CfgPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    if (NULL_PTR == Dma_CfgPtr)
    {
#if (STD_ON != DMA_PRECOMPILE_SUPPORT)
        if (NULL_PTR == CfgPtr)
        {
            (void)Det_ReportError(CDD_DMA_MODULE_ID, DMA_INSTANCE_ID, 
                DMA_SID_INIT, DMA_E_PARAM_POINTER);
            Ret = E_NOT_OK;
        }
        else
        {
#else /*STD_ON == DMA_PRECOMPILE_SUPPORT*/    
            if (NULL_PTR != CfgPtr)
            {
                (void)Det_ReportError(CDD_DMA_MODULE_ID, DMA_INSTANCE_ID,
                    DMA_SID_INIT, DMA_E_INIT_FAILED);
                Ret = E_NOT_OK;
            }
            else
            {
                /* Nothing to do */
            }
#endif
        }
#if (STD_ON != DMA_PRECOMPILE_SUPPORT)
    }
#endif
    else
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, DMA_INSTANCE_ID, 
            DMA_SID_INIT, DMA_E_INIT_FAILED);
        Ret = E_NOT_OK;
    }

    return Ret;
}
#endif

/**
 * @brief      Get Dma logic channel index of a physical channel.
 *
 * @param[in]  PhysChId: Physical channel id.
 *
 * @return     uint8: Logic channel index.
 * @retval    - 0xFF: The physical channel is not found in the configuration structure.
 * @retval    - other values: The logic channel index.
 *
 */
static uint8 Dma_GetLogicChIndexOfPhyCh(const Dma_Drv_ChannelType PhysChId)
{
    uint8 LogicChIndex = 0xFF;
    uint8 Cnt = 0U;

    for(Cnt = 0U; Cnt < DMA_CHANNEL_CFG_TOTALNUM; Cnt++)
    {
        if (Dma_CfgPtr->ChCfgArrayPtr[Cnt]->PhyChId == PhysChId)
        {
            LogicChIndex = Cnt;
            break;
        }
    }

    return LogicChIndex;
}

/**
 * @brief      Dma driver error interrupt handler.
 *
 * @param[in]  PhysChId: Physical channel id.
 *
 * @return     None.
 *
 */
static void Dma_HandlePhysChannelErrInt(const Dma_Drv_ChannelType PhysChId)
{
    uint8 LogicChIndex;
    uint16 LastErrStatus;
    Dma_CallbackType ErrIntCallback;

    LogicChIndex = Dma_GetLogicChIndexOfPhyCh(PhysChId);
    if ((uint8)0xFF != LogicChIndex)
    {
        /* global index */
        Dma_ChannelStateArray[LogicChIndex].ChState = DMA_CH_ERROR_STATE;
        LastErrStatus = Dma_Drv_GetLastErrorStatus();
        if (Dma_Drv_GetLastErrorChannel(LastErrStatus) == PhysChId)
        {
            /* store last error status */
            Dma_ChannelStateArray[LogicChIndex].ChErrState = LastErrStatus;
        }

        ErrIntCallback = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->ErrIntCallback;

        if (ErrIntCallback != NULL_PTR)
        {
            ErrIntCallback(LogicChIndex);
        }  
    }
}

/**
 * @brief      Dma driver major done interrupt handler.
 *
 * @param[in]  PhysChId: Physical channel id.
 *
 * @return     None.
 *
 */
static void Dma_HandlePhysChannelDoneInt(const Dma_Drv_ChannelType PhysChId)
{
    uint8 LogicChIndex;
    Dma_CallbackType MajorIntCallback;

    LogicChIndex = Dma_GetLogicChIndexOfPhyCh(PhysChId);
    if ((uint8)0xFF != LogicChIndex)
    {
        MajorIntCallback = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->MajorIntCallback;

        if (MajorIntCallback != NULL_PTR)
        {
            MajorIntCallback(LogicChIndex);
        }  
    }
}

/**
 * @brief      Update DMA channel error state manually when error interrupt is disabled.
 *             Do nothing when error interrupt is enabled.
 * 
 * @param[in]  LogicChIndex: Logic dma channel index.
 * 
 * @return     None.
 * 
*/
static void Dma_UpdateErrorState(const uint32 LogicChIndex)
{
    Dma_Drv_ChannelType PhysChId;
    uint16 LastErrStatus;

    /* error state is managed by error interrupt handler when error interrupt is enabled */
    if (TRUE != Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->ChGlobalCfgPtr->ErrIntEn)
    {
        /* Get hardware channel id */
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;
        /* error interrupt disabled */
        if (TRUE == Dma_Drv_GetChannelErrorStatus(PhysChId))
        {
            /* store last error status */
            Dma_ChannelStateArray[LogicChIndex].ChState = DMA_CH_ERROR_STATE;
            LastErrStatus = Dma_Drv_GetLastErrorStatus();
            if (Dma_Drv_GetLastErrorChannel(LastErrStatus) == PhysChId)
            {
                Dma_ChannelStateArray[LogicChIndex].ChErrState = LastErrStatus;
            }
            else
            {
                Dma_ChannelStateArray[LogicChIndex].ChErrState = DMA_CH_ERROR_UNKNOWN_STATE;
            }
        }
    }
}

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
/** @} end of group Private_FunctionDefinition */


/** @defgroup Public_FunctionDefinition
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
void Dma_Init(const Dma_ConfigType * const CfgPtr)
{
    uint8 LogicChIndex;
    Dma_Drv_ChannelType PhysChId;
    Dma_ChannelOptStateType * ChOptSta;
    const Dma_Drv_ChannelGlobalConfigType * ChGlobalCfg;
    const Dma_Drv_ChannelTransferConfigType * ChTransCfg;

#if (STD_ON == DMA_DEV_ERROR_DETECT)  
    if (E_OK == Dma_CheckInit(CfgPtr))
    {
#endif /* (DMA_DEV_ERROR_DETECT == STD_ON) */

#if (DMA_PRECOMPILE_SUPPORT == STD_ON)
        Dma_CfgPtr = Dma_PreDefinedConfigPtr;
        (void)CfgPtr;
#else /* DMA_PRECOMPILE_SUPPORT == STD_OFF */  
        Dma_CfgPtr = CfgPtr;    
#endif /* DMA_PRECOMPILE_SUPPORT */

        Dma_Drv_Init(Dma_CfgPtr->ModuleCfgArrayPtr[0]);

        Dma_Drv_InstallErrIntCallbackFunc(&Dma_HandlePhysChannelErrInt);

        /* init channel */
        for (LogicChIndex = 0U; LogicChIndex < DMA_CHANNEL_CFG_TOTALNUM; LogicChIndex++)
        {
            ChOptSta = &Dma_ChannelStateArray[LogicChIndex];
            PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;

            /*Clear all interrupt status*/
            Dma_Drv_ClearIntStatus(PhysChId, DMA_DRV_INT_ALL);

            /* init channel global configuration */
            ChGlobalCfg = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->ChGlobalCfgPtr;
            Dma_Drv_SetChannelGlobalConfig(PhysChId, ChGlobalCfg);
            /* Init Done Irq Callback*/
            Dma_Drv_InitDoneIrqHandle(PhysChId, &Dma_HandlePhysChannelDoneInt);
            /* init channel transfer configuration */
            ChTransCfg = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->ChTransferCfgPtr;
            if (NULL_PTR != ChTransCfg)
            {
                Dma_Drv_SetChannelTransferConfig(PhysChId, ChTransCfg);
            }

            ChOptSta->ChErrState = 0U;
            ChOptSta->ChState = DMA_CH_READY_STATE;
        }
#if (STD_ON == DMA_DEV_ERROR_DETECT)          
    }
#endif /* STD_ON == DMA_DEV_ERROR_DETECT */
}

/**
 * @brief      Get dma channel status.
 *             - Service ID: 0x01
 *
 * @param[in]  LogicChIndex: Logic dma channel index.
 * @param[out] StatusPtr: Pointer to a structure that stores dma channel status.
 *              each bit of StatusPtr->Error represents a type of error.
 *              for more information please refer to DMA_ES reg reference manual.
 *              - DBEF(bit 0)  : destination bus error
 *              - SBEF(bit 1)  : source bus error
 *              - NUMEF(bit 3) : TransferNum is not multiple of source TransferSize  or destination
 *                               TransferSize
 *              - DOEF(bit 4)  : destination MinorLoopOffset or MajorLoopOffset is not
 *                               multiple of destination TransferSize
 *              - DAEF(bit 5)  : destination address is not multiple of destination TransferSize
 *              - SOEF(bit 6)  : source MinorLoopOffset or MajorLoopOffset is not
 *                               multiple of source TransferSize
 *              - SAEF(bit 7)  : source address is not multiple of source TransferSize
 *              - PRIEF(bit 13): channel priority not unique error
 *
 * @return     None.
 *
 */
void Dma_GetChannelStatus(const uint32 LogicChIndex,
                        Dma_ChannelStatusType * const StatusPtr)
{
    Dma_Drv_ChannelType PhysChId;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    boolean DetErrFlag = FALSE;
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_GET_CHANNEL_STATUS, DMA_E_INVALID_CHANNEL);
        DetErrFlag = TRUE;
    }    
    else 
    {
        if (DMA_CH_UNINIT_STATE == Dma_ChannelStateArray[LogicChIndex].ChState)
        {
            (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                DMA_SID_GET_CHANNEL_STATUS, DMA_E_UNINIT);
            DetErrFlag = TRUE;
        }
        else
        {
            if (NULL_PTR == StatusPtr)
            {
                (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                    DMA_SID_GET_CHANNEL_STATUS, DMA_E_PARAM_POINTER);
                DetErrFlag = TRUE;
            }
        }
    }
    if (FALSE == DetErrFlag)
    {
#endif  
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;

        Dma_UpdateErrorState(LogicChIndex);

        StatusPtr->Error = Dma_ChannelStateArray[LogicChIndex].ChErrState;
        StatusPtr->State = Dma_ChannelStateArray[LogicChIndex].ChState;
        StatusPtr->Busy = Dma_Drv_GetChannelBusyStatus(PhysChId);
        StatusPtr->Done = Dma_Drv_GetDoneStatus(PhysChId);
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif   
}

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
void Dma_Halt(Dma_HaltType Cmd)
{
    if (Cmd > DMA_HALT_ON)
    {
#if (STD_ON == DMA_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_HALT, DMA_E_INVALID_COMMAND);
#endif
    }
    else
    {
        Dma_Drv_HaltControl((Dma_Drv_HaltType)Cmd);
    }
}

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
                                         const Dma_ChannelTransferConfigType *ChConfigPtr)
{    
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Dma_Drv_ChannelType PhysChId;

#if (STD_ON == DMA_DEV_ERROR_DETECT)
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_CONFIG_CHANNEL_TRANSFER, DMA_E_INVALID_CHANNEL);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == ChConfigPtr)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_CONFIG_CHANNEL_TRANSFER, DMA_E_PARAM_POINTER);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (DMA_CH_UNINIT_STATE == Dma_ChannelStateArray[LogicChIndex].ChState)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_CONFIG_CHANNEL_TRANSFER, DMA_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* No Det Error */
    }
#endif
    if ((Std_ReturnType)E_OK == RetVal)
    {
        Dma_UpdateErrorState(LogicChIndex);

        if (DMA_CH_READY_STATE == Dma_ChannelStateArray[LogicChIndex].ChState)
        {
            /*Get hardware channel id*/
            PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;
            Dma_Drv_ClearIntStatus(PhysChId, DMA_DRV_INT_DONE);
            Dma_Drv_SetChannelTransferConfig(PhysChId, 
                                            (const Dma_Drv_ChannelTransferConfigType *)ChConfigPtr);
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
            (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                DMA_SID_CONFIG_CHANNEL_TRANSFER, DMA_E_CH_STATE);
#endif
        }
    }

    return RetVal;
}

/**
 * @brief      Configure dma channel global parameters.
 *             - Service ID: 0x04
 * @note       Due to hardware limitation, when DMA priority error occurs, channel error status flag
 *             can be asserted on incorrect channel. So user should ensure that the dma channel
 *             priority is unique for each channel before dma request if fixed priority arbitration
 *             is used.
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
                                    const Dma_ChannelGlobalConfigType *ChConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Dma_Drv_ChannelType PhysChId;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID,
            DMA_SID_CONFIG_CHANNEL_GLOBAL_PARAM, DMA_E_INVALID_CHANNEL);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == ChConfigPtr)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_CONFIG_CHANNEL_GLOBAL_PARAM, DMA_E_PARAM_POINTER);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (DMA_CH_UNINIT_STATE == Dma_ChannelStateArray[LogicChIndex].ChState)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_CONFIG_CHANNEL_GLOBAL_PARAM, DMA_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR != ChConfigPtr->RequestConfig)
    {
        if (((boolean)TRUE == ChConfigPtr->RequestConfig->ReqEn)
            && (DMA_REQ_SOFTWARE == ChConfigPtr->RequestConfig->MuxReqSrc))
        {
            (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                DMA_SID_CONFIG_CHANNEL_GLOBAL_PARAM, DMA_E_INVALID_PARAMETER);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /* No Det Error */
    }
#endif
    if ((Std_ReturnType)E_OK == RetVal)
    {
        Dma_UpdateErrorState(LogicChIndex);

        if (DMA_CH_READY_STATE == Dma_ChannelStateArray[LogicChIndex].ChState) 
        {
            /*Get hardware channel id*/
            PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;
            Dma_Drv_SetChannelGlobalConfig(PhysChId,
                                        (const Dma_Drv_ChannelGlobalConfigType *)ChConfigPtr);
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
            (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                DMA_SID_CONFIG_CHANNEL_GLOBAL_PARAM, DMA_E_CH_STATE);
#endif
        }
    }

    return RetVal;
}

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
void Dma_EnableChannelHwRequest(const uint32 LogicChIndex, boolean Enable)
{
    Dma_Drv_ChannelType PhysChId;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    boolean DetErrFlag = FALSE;
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                        DMA_SID_ENABLE_CHANNEL_HW_REQUEST,  DMA_E_INVALID_CHANNEL);
        DetErrFlag = TRUE;
    }    
    else 
    {
        if (DMA_CH_READY_STATE != Dma_ChannelStateArray[LogicChIndex].ChState)
        {
            (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                DMA_SID_ENABLE_CHANNEL_HW_REQUEST, DMA_E_CH_STATE);
            DetErrFlag = TRUE;
        }
        else 
        {
            if (TRUE < Enable)
            {
                (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                            DMA_SID_ENABLE_CHANNEL_HW_REQUEST, DMA_E_INVALID_PARAMETER);
                DetErrFlag = TRUE;
            }        
        }
    }
    if (FALSE == DetErrFlag)
    {
#endif
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;
        if (TRUE == Enable)
        {
            Dma_Drv_EnableChannelRequest(PhysChId);
        }
        else
        {
            Dma_Drv_DisableChannelRequest(PhysChId);
        }
        
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif
}

/**
 * @brief      Software trigger dma transfer.
 *             - Service ID: 0x06
 * 
 * @param[in]  LogicChIndex: Logic channel index.
 *
 * @return     None.
 *
 */
void Dma_TriggerChannelStartBySw(const uint32 LogicChIndex)
{
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    boolean DetErrFlag = FALSE;
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_TRIGGER_CHANNEL_START_BY_SW, DMA_E_INVALID_CHANNEL);
        DetErrFlag = TRUE;
    }    
    else 
    {
        if (DMA_CH_READY_STATE != Dma_ChannelStateArray[LogicChIndex].ChState)
        {
            (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                DMA_SID_TRIGGER_CHANNEL_START_BY_SW, DMA_E_CH_STATE);
            DetErrFlag = TRUE;
        }
        else 
        {
            /* Nothing to do */
        }
    }
    if (FALSE == DetErrFlag)
    {
#endif
        Dma_Drv_ChannelType PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;

        Dma_Drv_TriggerChannelStart(PhysChId);
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif    
}

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
void Dma_ClearIntStatus(const uint32 LogicChIndex, Dma_IntType Int)
{
    Dma_Drv_ChannelType PhysChId;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    boolean DetErrFlag = FALSE;
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_CLEAR_INT_STATUS, DMA_E_INVALID_CHANNEL);
        DetErrFlag = TRUE;
    }    
    else 
    {
        if (DMA_CH_UNINIT_STATE == Dma_ChannelStateArray[LogicChIndex].ChState)
        {
            (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID,
                DMA_SID_CLEAR_INT_STATUS, DMA_E_UNINIT);
            DetErrFlag = TRUE;
        }
        else 
        {
            if (DMA_INT_ALL < Int)
            {
                (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
                    DMA_SID_CLEAR_INT_STATUS, DMA_E_INVALID_PARAMETER);
                DetErrFlag = TRUE;
            }
        }
    }

    if (FALSE == DetErrFlag)
    {
#endif
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;

        Dma_Drv_ClearIntStatus(PhysChId, (Dma_Drv_IntType)Int);
        if ((DMA_INT_ERROR == Int) && (DMA_CH_ERROR_STATE == 
            Dma_ChannelStateArray[LogicChIndex].ChState))
        {
            Dma_ChannelStateArray[LogicChIndex].ChState = DMA_CH_READY_STATE;
        }        
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif        
}

/**
 * @brief      Get Dma HW module status.
 *             - Service ID: 0x08
 * 
 * @param[out] StatusPtr: Pointer to a structure that stores dma HW module status.
 *
 * @return     None.
 *
 */
void Dma_GetHwModuleStatus(Dma_ModuleStatusType * const StatusPtr)
{
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    boolean DetErrFlag = FALSE;

    if (NULL_PTR == StatusPtr)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID,
            DMA_SID_GET_HW_MODULE_STATUS, DMA_E_PARAM_POINTER);
        DetErrFlag = TRUE;
    }
    else 
    {
        /* Nothing to do */            
    }

    if (FALSE == DetErrFlag)
    {
#endif  
        StatusPtr->Busy = Dma_Drv_GetBusyStatus();
        StatusPtr->Halt = Dma_Drv_GetHaltStatus();
        StatusPtr->ChannelsErrStatus = Dma_Drv_GetAllChannelsErrorStatus();
        StatusPtr->LastErrChStatus = Dma_Drv_GetLastErrorStatus();

#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif     
}

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
void Dma_SetSourceAddr(const uint32 LogicChIndex, uint32 Address)
{
    Dma_Drv_ChannelType PhysChId;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    boolean DetErrFlag = FALSE;
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_SET_SOURCE_ADDR, DMA_E_INVALID_CHANNEL);
        DetErrFlag = TRUE;
    }
    else if (DMA_CH_UNINIT_STATE == Dma_ChannelStateArray[LogicChIndex].ChState)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_SET_SOURCE_ADDR, DMA_E_UNINIT);
        DetErrFlag = TRUE;
    }
    else
    {
        /* No Det Error */
    }
    if (FALSE == DetErrFlag)
    {
#endif
        /*Get hardware channel id*/
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;

        Dma_Drv_SetSourceAddr(PhysChId, Address);
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif
}

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
void Dma_SetDestAddr(const uint32 LogicChIndex, uint32 Address)
{
    Dma_Drv_ChannelType PhysChId;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    boolean DetErrFlag = FALSE;
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_SET_DEST_ADDR, DMA_E_INVALID_CHANNEL);
        DetErrFlag = TRUE;
    }
    else if (DMA_CH_UNINIT_STATE == Dma_ChannelStateArray[LogicChIndex].ChState)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_SET_DEST_ADDR, DMA_E_UNINIT);
        DetErrFlag = TRUE;
    }
    else
    {
        /* No Det Error */
    }
    if (FALSE == DetErrFlag)
    {
#endif
        /*Get hardware channel id*/
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;

        Dma_Drv_SetDestAddr(PhysChId, Address);
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif
}

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
void Dma_GetVersionInfo(Std_VersionInfoType * const VersionInfo)
{
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError((uint16)CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID,
            DMA_SID_GET_VERSION_INFO, DMA_E_PARAM_POINTER);
    }
    else
    {
#endif
    VersionInfo->vendorID = (uint16)CDD_DMA_VENDOR_ID;
    VersionInfo->moduleID = (uint16)CDD_DMA_MODULE_ID;
    VersionInfo->sw_major_version = (uint8)CDD_DMA_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = (uint8)CDD_DMA_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = (uint8)CDD_DMA_SW_PATCH_VERSION;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    }
#endif
}
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
                                            const Dma_ChannelTransferConfigType * ChConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Dma_Drv_ChannelType PhysChId;

#if (STD_ON == DMA_DEV_ERROR_DETECT)
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_GET_CHANNEL_TRANSFER_CONFIG, DMA_E_INVALID_CHANNEL);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == ChConfigPtr)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_GET_CHANNEL_TRANSFER_CONFIG, DMA_E_PARAM_POINTER);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* No Det Error */
    }
#endif
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /*Get hardware channel id*/
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;
        Dma_Drv_GetChannelTransferConfig(PhysChId, 
                                        (const Dma_Drv_ChannelTransferConfigType *)ChConfigPtr);
    }
    return RetVal;
}

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
                                        Dma_ChannelGlobalConfigType * ChConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Dma_Drv_ChannelType PhysChId;
#if (STD_ON == DMA_DEV_ERROR_DETECT)
    if (DMA_CHANNEL_CFG_TOTALNUM <= LogicChIndex)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID,
            DMA_SID_GET_CHANNEL_GLOBAL_PARAM, DMA_E_INVALID_CHANNEL);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == ChConfigPtr)
    {
        (void)Det_ReportError(CDD_DMA_MODULE_ID, (uint8)DMA_INSTANCE_ID, 
            DMA_SID_GET_CHANNEL_GLOBAL_PARAM, DMA_E_PARAM_POINTER);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* No Det Error */
    }
#endif
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /*Get hardware channel id*/
        PhysChId = Dma_CfgPtr->ChCfgArrayPtr[LogicChIndex]->PhyChId;
        Dma_Drv_GetChannelGlobalConfig(PhysChId,
                                    (Dma_Drv_ChannelGlobalConfigType *)ChConfigPtr);
    }

    return RetVal;
}

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"


/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group CDD_Dma */
/** @} end of group Dma_Module */
