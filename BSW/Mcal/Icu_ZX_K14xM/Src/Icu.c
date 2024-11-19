/**************************************************************************************************/
/**
 * @file      : Icu.c
 * @brief     : AUTOSAR Icu driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Icu.h"
#include "Icu_Drvw.h"
#include "SchM_Icu.h"
#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
#include "CDD_Dma.h"
#endif

#if (STD_ON == ICU_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#if (STD_ON == ICU_DEM_EVENT_REPORT)
#include "Dem.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ICU_C_VENDOR_ID                   0x00B3U
#define ICU_C_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_C_AR_RELEASE_MINOR_VERSION    6U
#define ICU_C_AR_RELEASE_REVISION_VERSION 0U
#define ICU_C_SW_MAJOR_VERSION            1U
#define ICU_C_SW_MINOR_VERSION            2U
#define ICU_C_SW_PATCH_VERSION            2U

#if (ICU_C_VENDOR_ID != ICU_VENDOR_ID)
    #error "Vendor ID Icu.c and Icu.h have different"
#endif
            
#if ((ICU_C_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_C_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu.c and Icu.h are different"
#endif
            
#if ((ICU_C_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION) || \
        (ICU_C_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION))
    #error "Software version of Icu.c and Icu.h are different"
#endif

#if ((ICU_C_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION) || \
        (ICU_C_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION))
    #error "Software version of Icu.c and Icu.h are different"
#endif


#if (ICU_C_VENDOR_ID != ICU_DRVW_H_VENDOR_ID)
    #error "Vendor ID Icu.c and Icu_Drvw.h have different"
#endif
            
#if ((ICU_C_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_C_AR_RELEASE_MINOR_VERSION != ICU_DRVW_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu.c and Icu_Drvw.h are different"
#endif
            
#if ((ICU_C_SW_MAJOR_VERSION != ICU_DRVW_H_SW_MAJOR_VERSION) || \
        (ICU_C_SW_MINOR_VERSION != ICU_DRVW_H_SW_MINOR_VERSION))
    #error "Software version of Icu.c and Icu_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
        #if (ICU_C_VENDOR_ID != CDD_DMA_VENDOR_ID)
            #error "Vendor ID Icu.c and CDD_Dma.h have different"
        #endif
                    
        #if ((ICU_C_AR_RELEASE_MAJOR_VERSION != CDD_DMA_AR_RELEASE_MAJOR_VERSION) || \
                (ICU_C_AR_RELEASE_MINOR_VERSION != CDD_DMA_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of Icu.c and CDD_Dma.h are different"
        #endif
                    
        #if ((ICU_C_SW_MAJOR_VERSION != CDD_DMA_SW_MAJOR_VERSION) || \
                (ICU_C_SW_MINOR_VERSION != CDD_DMA_SW_MINOR_VERSION))
            #error "Software version of Icu.c and CDD_Dma.h are different"
        #endif
    #endif

    #if (ICU_C_VENDOR_ID != SCHM_ICU_H_VENDOR_ID)
        #error "Vendor ID Icu.c and SchM_Icu.h have different"
    #endif
                
    #if ((ICU_C_AR_RELEASE_MAJOR_VERSION != SCHM_ICU_H_AR_RELEASE_MAJOR_VERSION) || \
            (ICU_C_AR_RELEASE_MINOR_VERSION != SCHM_ICU_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Icu.c and SchM_Icu.h are different"
    #endif
                
    #if ((ICU_C_SW_MAJOR_VERSION != SCHM_ICU_H_SW_MAJOR_VERSION) || \
            (ICU_C_SW_MINOR_VERSION != SCHM_ICU_H_SW_MINOR_VERSION))
        #error "Software version of Icu.c and SchM_Icu.h are different"
    #endif

    #if (STD_ON == ICU_DEV_ERROR_DETECT)
        #if (ICU_C_VENDOR_ID != DET_VENDOR_ID)
            #error "Vendor ID Icu.c and Det.h have different"
        #endif
                    
        #if ((ICU_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
                (ICU_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of Icu.c and Det.h are different"
        #endif
                    
        #if ((ICU_C_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION) || \
                (ICU_C_SW_MINOR_VERSION != DET_SW_MINOR_VERSION))
            #error "Software version of Icu.c and Det.h are different"
        #endif
    #endif

    #if (STD_ON == ICU_DEM_EVENT_REPORT)
        #if (ICU_C_VENDOR_ID != DEM_VENDOR_ID)
            #error "Vendor ID Icu.c and Dem.h have different"
        #endif
                    
        #if ((ICU_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
                (ICU_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of Icu.c and Dem.h are different"
        #endif
                    
        #if ((ICU_C_SW_MAJOR_VERSION != DEM_SW_MAJOR_VERSION) || \
                (ICU_C_SW_MINOR_VERSION != DEM_SW_MINOR_VERSION))
            #error "Software version of Icu.c and Dem.h are different"
        #endif
    #endif

#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define Icu_GetCoreID()   ((uint32)0U)


#define ICU_CHANNEL_STATE_RUNNING               (1U << 1U)
#define ICU_CHANNEL_STATE_NOTIFICATIONENABLE    (1U << 2U)
#define ICU_CHANNEL_STATE_OVERFLOW              (1U << 3U)
#define ICU_CHANNEL_STATE_WAKEUPENABLE          (1U << 4U)
#define ICU_CHANNEL_STATE_WAKEUPSOURCE          (1U << 5U)

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
#define ICU_DMA_SIGMEASTS_COUNT                 ((uint32)2U)
#endif
/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/**
 * @brief Numeric identifier of an ICU channel State.
 */
typedef uint8 Icu_ChannelStateType;

/**
 * @brief States of the Icu driver
 */
#if (STD_ON == ICU_DEV_ERROR_DETECT)
typedef enum
{
    ICU_STATE_UNINIT = 0U,
    ICU_STATE_READY
} Icu_ModuleStateType;
#endif

/**
 * @brief Timestamp DMA config of the Icu driver
 */
#if ((STD_ON == ICU_TIMESTAMP_DMA_USE) && (STD_ON == ICU_TIMESTAMP_API))
typedef struct
{
    Icu_ValueType * DataBuffer[ICU_CHANNEL_MAXNUM];
    Icu_ValueType BufferSize[ICU_CHANNEL_MAXNUM];
    Icu_ValueType NotifyInterval[ICU_CHANNEL_MAXNUM];
    volatile Icu_ValueType NotifyCount[ICU_CHANNEL_MAXNUM];
    volatile Icu_ValueType TransferIndex[ICU_CHANNEL_MAXNUM];
    volatile Icu_IndexType BufferIndex[ICU_CHANNEL_MAXNUM];
} Icu_TimestampDmaTcbPtrType;
#endif

/**
 * @brief Signal Measurement DMA config of the Icu driver
 */
#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
typedef struct
{
    volatile Icu_ValueType DataBuffer[ICU_CHANNEL_MAXNUM][ICU_DMA_SIGMEASTS_COUNT];
    volatile Icu_ValueType StartTimestamp[ICU_CHANNEL_MAXNUM];
    volatile uint8 IntFlag[ICU_CHANNEL_MAXNUM];
} Icu_SignalMeasurementDmaTcbType;
#endif

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

/**
 * @brief Icu autosar interface level configuration structure
 */
static const Icu_ConfigType * Icu_ConfigPtr[ICU_PARTITIONS_MAXNUM];

/**
 * @brief Variable storing the current module state of the Icu driver
 */
#if (STD_ON == ICU_DEV_ERROR_DETECT)
static Icu_ModuleStateType Icu_ModuleState[ICU_PARTITIONS_MAXNUM];
#endif

/**
 * @brief Variable storing the current state of each ICU channel
 */
static volatile Icu_ChannelStateType Icu_ChannelState[ICU_CHANNEL_MAXNUM];

/**
 * @brief Allow enabling / disabling of all interrupts which are not required for the ECU wakeup
 */
static Icu_ModeType Icu_CurrentMode;

/**
 * @brief Variable storing the current state of Icu Timestamp DMA config  
 */
#if ((STD_ON == ICU_TIMESTAMP_DMA_USE) && (STD_ON == ICU_TIMESTAMP_API))
static Icu_TimestampDmaTcbPtrType Icu_TsDmaBuffer;
#endif

/**
 * @brief Variable storing the current state of Icu Signal Measurement DMA config  
 */
#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) && (STD_ON == ICU_SIGNAL_MEASUREMENT_API))
static Icu_SignalMeasurementDmaTcbType Icu_SigMeasDmaBuffer;
#endif

#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief     This function reports the wakeup event, overflow event and notification
 *
 * @param[in] Channel : number identifier of the ICU Channel
 * @param[in] OvfFlag : Parameter that indicates the source of report is an overflow 
 *
 * @return none
 *
 */
void Icu_EventNotification(uint16 Channel, boolean OvfFlag);

/**
 * @brief      This function reports the wakeup and overflow events
 *
 * @param[in] Channel : number identifier of the ICU Channel
 * @param[in] OvfFlag : Parameter that indicates the source of report is an overflow 
 *
 * @return none
 *
 */
void Icu_WakeupAndOvfNotification(uint16 Channel, boolean OvfFlag);

/**
 * @brief      This function reports the wakeup and overflow events
 *
 * @param[in] Channel : number identifier of the ICU Channel
 * @param[in] Mask : Numeric identifier of an ICU channel State
 * @param[in] OptType:  Interrupt set/clear type.
 *             - TRUE: set channel state
 *             - FALSE: clear channel state 
 *
 * @return none
 *
 */
void Icu_SetupChannelStateHandler(uint16 Channel, uint8 Mask, boolean OptType);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      This function get the Internal configuration parameter.
 *
 * @param[in]  CoreId: Internal Channel ID
 *
 * @return     Icu_ConfigType: Channel configuration for corresponding ID
 */
LOCAL_INLINE const Icu_ConfigType * Icu_GetLocalInternalCfg(uint32 CoreId)
{
    return (Icu_ConfigPtr[CoreId]);
}

#if ((STD_ON == ICU_TIMESTAMP_DMA_USE) && (STD_ON == ICU_TIMESTAMP_API))
/**
 * @brief      This function get the Timestamp DMA configuration parameter.
 *
 * @param[in]  None
 *
 * @return     Icu_TsDmaBuffer: current state of Timestamp DMA configuration 
 */
LOCAL_INLINE Icu_TimestampDmaTcbPtrType * Icu_GetLocalTsDmaTcb(void)
{
    return (&Icu_TsDmaBuffer);
}
#endif

/**
 * @brief      This function get the Signal Measurement DMA configuration parameter.
 *
 * @param[in]  None
 *
 * @return     Icu_SigMeasDmaBuffer: current state of Signal Measurement DMA configuration 
 */
#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) && (STD_ON == ICU_SIGNAL_MEASUREMENT_API))
LOCAL_INLINE Icu_SignalMeasurementDmaTcbType * Icu_GetLocalSigMeasDmaTcb(void)
{
    return (&Icu_SigMeasDmaBuffer);
}
#endif

/**
 * @brief      This function get the current mode parameter.
 *
 * @param[in]  None
 *
 * @return     Icu_CurrentMode: mode type for Icu instance 
 */
LOCAL_INLINE Icu_ModeType Icu_GetLocalMode(void)
{
    return Icu_CurrentMode;
}

#if (STD_ON == ICU_SET_MODE_API)
/**
 * @brief      This function set the current mode parameter.
 *
 * @param[in]  Mode: mode type for Icu instance
 *
 * @return     None 
 */
LOCAL_INLINE void Icu_SetLocalMode(Icu_ModeType Mode)
{
    Icu_CurrentMode = Mode;
}
#endif

/**
 * @brief      This function get the current Channel State.
 *
 * @param[in]  Channel:  Icu channel number
 * @param[in]  Mask: ICU channel State
 *
 * @return     Icu_ChannelStateType 
 */
LOCAL_INLINE Icu_ChannelStateType Icu_GetLocalChannelState(Icu_ChannelType Channel,
                                                                         Icu_ChannelStateType Mask)
{
    return (uint8)(Icu_ChannelState[Channel] & Mask);
}

/**
 * @brief      This function set the current Channel State.
 *
 * @param[in]  Channel:  Icu channel number
 * @param[in]  Mask: ICU channel State
 *
 * @return     None 
 */
LOCAL_INLINE void Icu_SetLocalChannelState(Icu_ChannelType Channel, Icu_ChannelStateType Mask)
{
    SchM_Enter_Icu_TimSetChannelState();
    Icu_ChannelState[Channel] |= Mask;
    SchM_Exit_Icu_TimSetChannelState();
}

/**
 * @brief      This function clear the current Channel State.
 *
 * @param[in]  Channel:  Icu channel number
 * @param[in]  Mask: ICU channel State
 *
 * @return     None 
 */
LOCAL_INLINE void Icu_ClearLocalChannelState(Icu_ChannelType Channel, Icu_ChannelStateType Mask)
{
    SchM_Enter_Icu_TimSetChannelState();
    Icu_ChannelState[Channel] &= ~Mask;
    SchM_Exit_Icu_TimSetChannelState();
}

#if (STD_ON == ICU_DEV_ERROR_DETECT)
/**
 * @brief      This function check the current Channel mode
 *
 * @param[in]  ServiceId:  API service ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalMode(uint8 ServiceId)
{
    Std_ReturnType RetVal = E_OK;

    if (ICU_MODE_SLEEP == Icu_CurrentMode)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ICU_E_MODE_INVALID);
        RetVal = E_NOT_OK;
    }
 
    return RetVal;
}

/**
 * @brief      This function check the module state
 *
 * @param[in]  ServiceId:  API service ID
 * @param[in]  CoreId:  Internal Channel ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalModuleState(uint8 ServiceId, uint8 CoreId)
{
    Std_ReturnType RetVal = E_OK;

    if (ICU_STATE_UNINIT == Icu_ModuleState[CoreId])
    {
        if (ICU_SID_INIT != ServiceId)
        {
            (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ICU_E_UNINIT);
            RetVal = E_NOT_OK;
        }
    }
    else
    {
        if (ICU_SID_INIT == ServiceId)
        {
            (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ICU_E_ALREADY_INITIALIZED);
            RetVal = E_NOT_OK;
        }
    }
    return RetVal;
}


/**
 * @brief      This function set the module state
 *
 * @param[in]  RetVal:  API return type
 *                   - E_OK:     Successfully.
 *                   - E_NOT_OK: Failed.
 * @param[in]  ServiceId:  API service ID
 * @param[in]  CoreId:  Internal Channel ID
 *
 * @return    None
 */
LOCAL_INLINE void Icu_SetLocalModuleState(Std_ReturnType RetVal, uint8 ServiceId, uint8 CoreId)
{
    if (E_OK == RetVal)
    {
#if (STD_ON == ICU_DEINIT_API)
        if (ICU_SID_DEINIT == ServiceId)
        {
            Icu_ModuleState[CoreId] = ICU_STATE_UNINIT;
        }
        else
#endif
        {
            Icu_ModuleState[CoreId] = ICU_STATE_READY;
        }
    }
}


/**
 * @brief      This function check the init configuration param state
 *
 * @param[in]  CoreId:  Internal Channel ID
 * @param[in]  ConfigPtr: Pointer to a Icu initial configuration structure
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalInitCfgParam(uint8 CoreId,
                                                                 const Icu_ConfigType * ConfigPtr)
{
    Std_ReturnType RetVal = E_OK;

#if (STD_ON == ICU_PRECOMPILE_SUPPORT)
    if (NULL_PTR != ConfigPtr)
    {
#else
    if (NULL_PTR == ConfigPtr)
    {
#endif
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ICU_SID_INIT, ICU_E_INIT_FAILED);
        RetVal = E_NOT_OK;
    }

    (void)CoreId;

    return RetVal;
}

#if (STD_ON == ICU_SET_MODE_API)
/**
 * @brief      This function check the set mode state
 *
 * @param[in]  Mode: ICU_MODE_NORMAL: Normal operation, all used interrupts are enabled
 *                                    according to the notification requests. 
 *                   ICU_MODE_SLEEP: Reduced power mode. In sleep mode only those notifications are
 *                                  available which are configured as wakeup capable.
 * @param[in]  ServiceId:  API service ID
 * @param[in]  CoreId:  Internal Channel ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckSetMode(Icu_ModeType Mode, uint32 CoreId, 
                                                                            uint8 ServiceId)
{
    Icu_ChannelType Channel;
    Std_ReturnType RetVal = E_OK;
    if ((ICU_MODE_SLEEP != Mode) && (ICU_MODE_NORMAL != Mode))
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ICU_E_PARAM_MODE);
        RetVal = E_NOT_OK;
    }
    else if (Mode != Icu_CurrentMode)
    {
        for (Channel = 0U; Channel < Icu_ConfigPtr[CoreId]->IcuChSumNum; Channel++)
        {
            if(ICU_CHANNEL_STATE_RUNNING == Icu_GetLocalChannelState(Channel, 
                                                                    ICU_CHANNEL_STATE_RUNNING | 
                                                                    ICU_CHANNEL_STATE_WAKEUPENABLE))
            {
                RetVal  = E_NOT_OK;
                (void)Det_ReportError(ICU_MODULE_ID, 0U, ICU_SID_SET_MODE, ICU_E_BUSY_OPERATION);
                break;
            }
        }
    }
    else
    {
        /*do nothing*/
    }
    return RetVal;
}
#endif

/**
 * @brief      This function check the operation mode
 * 
 * @param[in]  Channel: Logical number of the ICU Channel
 * @param[in]  Mask: ICU channel State
 * @param[in]  ServiceId:  API service ID
 * @param[in]  CoreId:  Internal Channel ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckOptMode(Icu_ChannelType Channel, uint8 Mask,
                                                                uint8 ServiceId, uint32 CoreId)
{
    Std_ReturnType RetVal = E_NOT_OK;
    boolean ReportError = TRUE;
    uint8 TmpOptMode;
    uint8 ErrorId;

    if (ICU_STATE_UNINIT == Icu_ModuleState[CoreId])
    {
        ErrorId = ICU_E_UNINIT;
    }
    else
    {
        if(ICU_CHANNEL_MAXNUM <= Channel)
        {
            ErrorId = ICU_E_PARAM_CHANNEL;
        }
        else
        {
            TmpOptMode = (*(Icu_ConfigPtr[CoreId]->IcuChCfgPtr))[Channel].ChOptMode;
            if (Channel >= Icu_ConfigPtr[CoreId]->IcuChSumNum)
            {
                ErrorId = ICU_E_PARAM_INVALID;
            }
            else if (TmpOptMode != (Mask & TmpOptMode))
            {
                ErrorId = ICU_E_PARAM_CHANNEL;
            }
            else
            {
                ReportError = FALSE;
                RetVal = E_OK;
            }
        }
    }
    
    if(TRUE == ReportError)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ErrorId);
    }
    
    return RetVal;
}

#if((STD_ON == ICU_WAKEUP_FUNCTIONALITY_API) || (STD_ON == ICU_DISABLE_WAKEUP_API)|| \
                                                 (STD_ON == ICU_ENABLE_WAKEUP_API))
/**
 * @brief      This function check the wakeup capable
 * 
 * @param[in]  Channel: Logical number of the ICU Channel
 * @param[in]  ServiceId:  API service ID
 * @param[in]  CoreId:  Internal Channel ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalWakeupCapable(Icu_ChannelType Channel,
                                                                        uint8 ServiceId, 
                                                                        uint32 CoreId)
{
    Std_ReturnType  RetVal = E_OK;

    if (FALSE == (*(Icu_ConfigPtr[CoreId]->IcuChCfgPtr))[Channel].WakeupCapable)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ICU_E_PARAM_CHANNEL);
        RetVal = E_NOT_OK;
    }
    
    return RetVal;
}
#endif

/**
 * @brief      This function check the activation param
 * 
 * @param[in]  ServiceId:  API service ID
 * @param[in]  Activation: Type of activation (if supported by hardware)
 *                         - ICU_RISING_EDGE
 *                         - ICU_FALLING_EDGE
 *                         - ICU_BOTH_EDGES
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalActivationParam(uint8 ServiceId,
                                                                 Icu_ActivationType ActiveEdge)
{
    Std_ReturnType RetVal = E_OK;

    if (ICU_BOTH_EDGES < ActiveEdge)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ICU_E_PARAM_ACTIVATION);
        RetVal = E_NOT_OK;
    }
    
    return RetVal;
}

#if (STD_ON == ICU_TIMESTAMP_API)
/**
 * @brief      This function check the Timestamp param
 * 
 * @param[in]  Channel:        Numeric identifier of the ICU channel
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 * @param[in]  BufferSize:     Size of the external buffer (number of entries)
 * @param[in]  NotifyInterval: Notification interval (number of events). This parameter can not be
 *                             checked in a reasonable way.
 * @param[in]  CoreId:  Internal Channel ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */

LOCAL_INLINE Std_ReturnType Icu_CheckLocalTimestampParam(Icu_ChannelType Channel, 
                                                                    const Icu_ValueType * BufferPtr, 
                                                                    uint16 BufferSize, 
                                                                    uint16 NotifyInterval, 
                                                                    uint32 CoreId)
{
    Std_ReturnType  RetVal = E_NOT_OK;

    if (NULL_PTR == BufferPtr)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ICU_SID_START_TIMESTAMP, ICU_E_PARAM_POINTER);
    }
    else if (0U == BufferSize)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ICU_SID_START_TIMESTAMP, ICU_E_PARAM_BUFFER_SIZE);
    }
    else if ((ICU_CHANNEL_STATE_NOTIFICATIONENABLE == Icu_GetLocalChannelState(Channel,
                                                 ICU_CHANNEL_STATE_NOTIFICATIONENABLE)) &&
            (NULL_PTR != (*(Icu_ConfigPtr[CoreId]->IcuChCfgPtr))[Channel].ChNotificationFun) &&
             (0U == NotifyInterval))
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ICU_SID_START_TIMESTAMP,
                                                             ICU_E_PARAM_NOTIFY_INTERVAL);
    }
    else
    {
        RetVal = E_OK;
    }
    
    return RetVal;
}
#endif


#if ((STD_ON == ICU_GET_TIMEELAPSED_API) || (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API))
/**
 * @brief      This function check the signal measurement property
 * 
 * @param[in]  Channel:        Numeric identifier of the ICU channel
 * @param[in]  Mask:  ICU channel State
 * @param[in]  ServiceId:  API service ID
 *                             values shall be placed
 * @param[in]  CoreId:  Internal Channel ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalSignalMeasurementProperty(Icu_ChannelType Channel,
                                                                                uint8 Mask,
                                                                                uint8  ServiceId,
                                                                                uint32 CoreId)
{
    const Icu_ConfigType * InternalCfgPtr;
    Std_ReturnType  RetVal = E_OK;
    uint8 ChProperty;

    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
    ChProperty = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).ChProperty;

    if(ChProperty != (ChProperty & Mask))
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ServiceId, ICU_E_PARAM_CHANNEL);
        RetVal = E_NOT_OK;
    }
    
    return RetVal;
}
#endif

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
/**
 * @brief      This function check the get dutycycle param
 * 
 * @param[out] DutyCycleValues : Pointer to a buffer where the results (high time 
 *                               and period time) shall be placed
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalGetDutyCycleParam(
                                                            const Icu_DutyCycleType * DutyCyclePtr)
{
    Std_ReturnType RetVal = E_OK;

    if (NULL_PTR == DutyCyclePtr)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ICU_SID_GET_DUTY_CYCLE_VALUES, ICU_E_PARAM_POINTER);
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
#endif

#if (STD_ON == ICU_GET_VERSION_INFO_API)
/**
 * @brief      This function check the get versioninfo param
 * 
 * @param[out] InfoPtr : Pointer to where to store the version information of this module.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckLocalGetVersionInfoParam(
                                                                const Std_VersionInfoType * InfoPtr)
{
    Std_ReturnType RetVal = E_OK;

    if (NULL_PTR == InfoPtr)
    {
        (void)Det_ReportError(ICU_MODULE_ID, 0U, ICU_SID_GET_VERSION_INFO, ICU_E_PARAM_VINFO);
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
#endif
#endif

#if (STD_ON == ICU_TIMESTAMP_API)
#if (STD_ON == ICU_DEV_ERROR_DETECT)
/**
 * @brief      This function check the channel state
 * 
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType Icu_CheckChannelState(Icu_ChannelType Channel)
{
    Std_ReturnType RetVal = E_OK;

    if(ICU_CHANNEL_STATE_RUNNING != (Icu_ChannelState[Channel] & ICU_CHANNEL_STATE_RUNNING))
    {
        (void)Det_ReportRuntimeError(ICU_MODULE_ID, 0U, ICU_SID_STOP_TIMESTAMP, ICU_E_NOT_STARTED);
        RetVal = E_NOT_OK;
    }
    
    return RetVal;
}
#endif
#endif

/**
 * @brief      This function reports the notification
 * 
 * @param[in]  Channel: Numeric identifier of the ICU channel
 * @param[in]  CoreId:  Internal Channel ID
 * 
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE void Icu_LocalEventNotification(Icu_ChannelType Channel, uint32 CoreId)
{
    const Icu_ChannelConfigType * IcuChCfgPtr;

    IcuChCfgPtr = &(*(Icu_GetLocalInternalCfg(CoreId)->IcuChCfgPtr))[Channel];

    if ((ICU_CHANNEL_STATE_NOTIFICATIONENABLE == Icu_GetLocalChannelState(Channel,
                                                ICU_CHANNEL_STATE_NOTIFICATIONENABLE)) && 
                                                (NULL_PTR != IcuChCfgPtr->ChNotificationFun))
    {
        (IcuChCfgPtr->ChNotificationFun)();
    } 
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      This function initializes the driver.
 *
 * @param[in]  ConfigPtr: Pointer to a Icu initial configuration structure
 *
 * @return none
 *
 */
void Icu_Init(const Icu_ConfigType * ConfigPtr)
{
    Icu_ChannelType Channel;
    uint32 CoreId;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif
#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
    const Icu_ChannelConfigType * ChCfgPtr;
#endif

    CoreId = Icu_GetCoreID();
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalModuleState(ICU_SID_INIT, (uint8)CoreId);
    if (E_OK == RetVal)
    {
        RetVal = Icu_CheckLocalInitCfgParam((uint8)CoreId, ConfigPtr);
        if (E_OK == RetVal)
        {
#endif
        #if (STD_ON == ICU_PRECOMPILE_SUPPORT)
            Icu_ConfigPtr[CoreId] = Icu_PredefinedConfigPtr[CoreId];
            (void)ConfigPtr;
        #else
            Icu_ConfigPtr[CoreId] = ConfigPtr;
        #endif

            /* initiate icu instance modules */
            Icu_Drvw_Init(Icu_ConfigPtr[CoreId]->IcuInstSumNum,
                                             Icu_ConfigPtr[CoreId]->IcuHwInstCfgPtr);

            /* clear logic Channel state */
            for (Channel = 0U; Channel < Icu_ConfigPtr[CoreId]->IcuChSumNum; Channel++)
            {
                Icu_ChannelState[Channel] = 0x0U;

            #if (STD_ON == ICU_TIMESTAMP_DMA_USE)
                ChCfgPtr = &(*Icu_ConfigPtr[CoreId]->IcuChCfgPtr)[Channel];
                if (ICU_MODE_TIMESTAMP == ChCfgPtr->ChOptMode)
                {
                    Icu_TsDmaBuffer.DataBuffer[Channel] = NULL_PTR;
                    Icu_TsDmaBuffer.BufferIndex[Channel] = 0U;
                }
            #endif 
            }
            
            Icu_CurrentMode = ICU_MODE_NORMAL;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
    
    Icu_SetLocalModuleState(RetVal, ICU_SID_INIT, (uint8)CoreId);
#endif
}

#if (STD_ON == ICU_DEINIT_API)
/**
 * @brief      This function de-initializes the ICU module. 
 *
 * @param[in]  none
 *
 * @return     none
 *
 */
void Icu_DeInit(void)
{
    Icu_ChannelType Channel;
    uint32 CoreId;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif

    CoreId = Icu_GetCoreID();
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalModuleState(ICU_SID_DEINIT, (uint8)CoreId);
    if (E_OK == RetVal)
    {
#endif
        /* deinitiate icu instance modules */
        Icu_Drvw_DeInit(Icu_ConfigPtr[CoreId]->IcuInstSumNum,
                                                     Icu_ConfigPtr[CoreId]->IcuHwInstCfgPtr);

        /* clear logic Channel state */
        for (Channel = 0U; Channel < Icu_ConfigPtr[CoreId]->IcuChSumNum; Channel++)
        {
            Icu_ChannelState[Channel] = 0x0U;
        }

        Icu_ConfigPtr[CoreId] = NULL_PTR;
        Icu_CurrentMode = ICU_MODE_NORMAL;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }

    Icu_SetLocalModuleState(RetVal, ICU_SID_DEINIT, (uint8)CoreId);
#endif
}
#endif

/**
 * @brief      This function sets the activation-edge for the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 * @param[in]  Activation: Type of activation (if supported by hardware)
 *                         - ICU_RISING_EDGE
 *                         - ICU_FALLING_EDGE
 *                         - ICU_BOTH_EDGES
 *
 * @return none
 *
 */
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)((1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT) |
                         (1U << (uint32)ICU_MODE_TIMESTAMP) | 
                         (1U << (uint32)ICU_MODE_EDGE_COUNTER));
#endif

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_SET_ACTIVATION_CONDITION, CoreId);
    if (E_OK == RetVal)
    {
        if (E_OK == Icu_CheckLocalActivationParam(ICU_SID_SET_ACTIVATION_CONDITION, Activation))
        {
#endif
            Icu_Drvw_SetActivationCondition((ICU_DRVW_ACTIVATION_TYPE)Activation,
                                 (*(InternalCfgPtr->IcuChCfgPtr))[Channel].DrvwHwChCfgPtr);
            if((ICU_CHANNEL_STATE_RUNNING == Icu_GetLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING))
            &&((uint32)((*((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr).ChModule) != 0U))
            {
                Icu_Drvw_EnableEdgeDetection(((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
            }

#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
#endif
}

/**
 * @brief      This function enables the notification on the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_EnableNotification(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)((1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT) |
                         (1U << (uint32)ICU_MODE_TIMESTAMP)|
                         (1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT)|
                         (1U << (uint32)ICU_MODE_EDGE_COUNTER));
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_ENABLE_NOTIFICATION, CoreId);
    if (E_OK == RetVal)
    {
#endif
        Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_NOTIFICATIONENABLE);
        Icu_Drvw_EnableNotification((*(InternalCfgPtr->IcuChCfgPtr))[Channel].DrvwHwChCfgPtr);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
    
    Icu_SetLocalModuleState(RetVal, ICU_SID_ENABLE_NOTIFICATION, (uint8)CoreId);
#endif
}

/**
 * @brief      This function disables the notification of a Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_DisableNotification(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)((1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT) |
                         (1U << (uint32)ICU_MODE_TIMESTAMP)|
                         (1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT)|
                         (1U << (uint32)ICU_MODE_EDGE_COUNTER));
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_DISABLE_NOTIFICATION, CoreId);
    if (E_OK == RetVal)
    {
#endif
        Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_NOTIFICATIONENABLE);
        Icu_Drvw_DisableNotification((*(InternalCfgPtr->IcuChCfgPtr))[Channel].DrvwHwChCfgPtr);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
    
    Icu_SetLocalModuleState(RetVal, ICU_SID_DISABLE_NOTIFICATION, (uint8)CoreId);
#endif
}

#if (STD_ON == ICU_GET_INPUT_STATE_API)
/**
 * @brief      This function returns the status of the ICU input
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return     Icu_InputStateType
 *             - ICU_ACTIVE: An activation edge has been detected
 *             - ICU_IDLE: No activation edge has been detected since the last
 *                         call of Icu_GetInputState() or Icu_Init().
 *
 */
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel)
{
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    uint32 CoreId;
    Icu_InputStateType TmpState = ICU_IDLE;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)((1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT) |
                         (1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT));
#endif

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_GET_INPUT_STATE, CoreId);
    if (E_OK == RetVal)
    {
#endif
        DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;

        if (((1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT) ==
                                    (((*InternalCfgPtr->IcuChCfgPtr)[Channel]).ChOptMode)) ||
            ((1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT) ==(((*InternalCfgPtr->IcuChCfgPtr)[Channel]).ChOptMode )))
        {
            TmpState = (TRUE == Icu_Drvw_GetInputState(DrvwHwChCfgPtr)) ? ICU_ACTIVE : ICU_IDLE;
        }
        else
        {
            /*do nothing*/
        }
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
    
    Icu_SetLocalModuleState(RetVal, ICU_SID_GET_INPUT_STATE, (uint8)CoreId);
#endif
    return TmpState;
}
#endif

#if (STD_ON == ICU_SET_MODE_API)
/**
 * @brief      This function sets the ICU Mode
 *
 * @param[in]  Mode: ICU_MODE_NORMAL: Normal operation, all used interrupts are enabled
 *                                    according to the notification requests. 
 *                   ICU_MODE_SLEEP: Reduced power mode. In sleep mode only those notifications are
 *                                  available which are configured as wakeup capable.
 *
 * @return none
 *
 */
void Icu_SetMode(Icu_ModeType Mode)
{
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    Icu_ChannelType Channel;
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalModuleState(ICU_SID_SET_MODE, (uint8)CoreId);
    if (E_OK == RetVal)
    {
        RetVal = Icu_CheckSetMode(Mode, CoreId, ICU_SID_SET_MODE);
        if (E_OK == RetVal)
        {
#endif
            for (Channel = 0U; Channel < InternalCfgPtr->IcuChSumNum; Channel++)
            {
                DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;
                if (ICU_MODE_SLEEP == Mode)
                {
                    if ((Icu_GetLocalChannelState(Channel, ICU_CHANNEL_STATE_WAKEUPENABLE) != 
                        ICU_CHANNEL_STATE_WAKEUPENABLE) && (Icu_GetLocalMode() != Mode))
                    {
                        Icu_Drvw_SetSleepMode(DrvwHwChCfgPtr);
                    }
                    #if(STD_ON == ICU_OVERFLOW_NOTIFICATION_API)
                    Icu_Drvw_DisableOverflowInt(DrvwHwChCfgPtr);
                    #endif

                }
                else
                {
                    if ((Icu_GetLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING) == 
                        ICU_CHANNEL_STATE_RUNNING) && (Icu_GetLocalMode() != Mode))
                    {
                        Icu_Drvw_SetNormalMode(DrvwHwChCfgPtr);
                    #if (STD_ON == ICU_OVERFLOW_NOTIFICATION_API)
                        Icu_Drvw_EnableOverflowInt(DrvwHwChCfgPtr);
                    #endif
                    }
                }
            }
            
            Icu_SetLocalMode(Mode);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
    Icu_SetLocalModuleState(RetVal, ICU_SID_SET_MODE, (uint8)CoreId);
#endif
}
#endif

#if (STD_ON == ICU_TIMESTAMP_API)
/**
 * @brief      This function starts the capturing of timer values on the edges
 *
 * @param[in]  Channel:        Numeric identifier of the ICU channel
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 * @param[in]  BufferSize:     Size of the external buffer (number of entries)It should be the same 
 *                             size as the array pointed to by BufferPtr.
 * @param[in]  NotifyInterval: Notification interval (number of events). This parameter can not be
 *                             checked in a reasonable way,It should not be greater than BufferSize.
 *
 * @return none
 *
 */
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType * BufferPtr, uint16 BufferSize, 
                               uint16 NotifyInterval)
{
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    uint32 CoreId;
#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
    Icu_TimestampDmaTcbPtrType * DmaTcbPtr;
    uint32 IcuInstSumNum;
    uint32 DmaChId;
#endif    
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
    DmaChId = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh;
#endif  

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalMode(ICU_SID_START_TIMESTAMP);
    if (E_OK == RetVal)
    {
        RetVal = Icu_CheckOptMode(Channel, 1U << (uint32)ICU_MODE_TIMESTAMP,
                                                                 ICU_SID_START_TIMESTAMP, CoreId);
        if (E_OK == RetVal)
        {
            if ((Std_ReturnType)E_OK == Icu_CheckLocalTimestampParam(Channel,
                                                                        BufferPtr,
                                                                        BufferSize,
                                                                        NotifyInterval, 
                                                                        CoreId))
            {
#endif
                Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
                Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_OVERFLOW);

                DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;

            #if (STD_ON == ICU_TIMESTAMP_DMA_USE)
            if (ICU_INVALID_DMACHANNEL != DmaChId)
            {
                DmaTcbPtr = Icu_GetLocalTsDmaTcb();
                IcuInstSumNum = DrvwHwChCfgPtr->InstId;

                SchM_Enter_Icu_TimSetDmaParam();
                DmaTcbPtr->DataBuffer[Channel] = BufferPtr;
                DmaTcbPtr->BufferSize[Channel] = BufferSize;
                DmaTcbPtr->NotifyInterval[Channel] = NotifyInterval;

                if ((BufferSize <= DmaTcbPtr->NotifyInterval[Channel]) || (0U == NotifyInterval))
                {
                    DmaTcbPtr->TransferIndex[Channel] = (uint16)BufferSize;
                }
                else
                {
                    DmaTcbPtr->TransferIndex[Channel] = (uint16)(NotifyInterval);
                }

                DmaTcbPtr->NotifyCount[Channel] = 0U;
                DmaTcbPtr->BufferIndex[Channel] = 0U;
                SchM_Exit_Icu_TimSetDmaParam();

                Icu_Drvw_TimestampDmaGlobalConfig(DmaChId, DrvwHwChCfgPtr, IcuInstSumNum);
                Icu_Drvw_TimestampDmaTransferConfig(DmaChId,
                                     DrvwHwChCfgPtr, BufferSize, NotifyInterval, BufferPtr);

            }
            #endif
                Icu_Drvw_StartTimestamp(DrvwHwChCfgPtr, BufferPtr, BufferSize, NotifyInterval);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            }
        }
        
        Icu_SetLocalModuleState(RetVal, ICU_SID_START_TIMESTAMP, (uint8)CoreId);
    }
#endif
}


/**
 * @brief      This function read the timestamp index of the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return     Icu_IndexType Abstract return type to cover different microcontrollers.
 *
 */
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
    const Icu_ConfigType * InternalCfgPtr;
    uint32 CoreId;
#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
    Icu_TimestampDmaTcbPtrType * TsDmaTcbPtr;
    uint32 DmaChId;
#endif    

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_TIMESTAMP);
#endif
    Icu_IndexType TsIdx = 0U;

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_GET_TIMESTAMP_INDEX, CoreId);
    if (E_OK == RetVal)
    {
#endif    
        #if (STD_ON == ICU_TIMESTAMP_DMA_USE)
            DmaChId = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh; 
            if (ICU_INVALID_DMACHANNEL != DmaChId)
            {
                TsDmaTcbPtr = Icu_GetLocalTsDmaTcb();   
                TsIdx = TsDmaTcbPtr->BufferIndex[Channel];  
            }
            else
            {
        #endif
                TsIdx = Icu_Drvw_GetTimestampIndex(
                                            ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
        #if (STD_ON == ICU_TIMESTAMP_DMA_USE)
            }
        #endif
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
#endif

    return TsIdx;
}

/**
 * @brief      This function stops the timestamp measurement of the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_StopTimestamp(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
    uint32 DmaChId;
#endif

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_TIMESTAMP);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
    DmaChId = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh;
#endif
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_STOP_TIMESTAMP, CoreId);
    if (E_OK == RetVal)
    {
        if (E_OK == Icu_CheckChannelState(Channel))
        {
#endif

            DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;
        #if (STD_ON == ICU_TIMESTAMP_DMA_USE)
            if (ICU_INVALID_DMACHANNEL != (DmaChId))
            {
                Icu_Drvw_DisableDmaChannelRequest((Dma_Drv_ChannelType)DmaChId);
            }
        #endif
        
            Icu_Drvw_StopTimestamp(DrvwHwChCfgPtr);
            Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
#endif
}
#endif

#if (STD_ON == ICU_ENABLE_WAKEUP_API)
/**
 * @brief      This function (re-)enables the wakeup capability of the given ICU channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_EnableWakeup(Icu_ChannelType Channel)
{
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    uint32 CoreId;
    uint8 Mask = (uint8)((1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT) |
                         (1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT) | 
                         (1U << (uint32)ICU_MODE_TIMESTAMP) |
                         (1U << (uint32)ICU_MODE_EDGE_COUNTER));

    if(E_OK == Icu_CheckLocalMode(ICU_SID_ENABLE_WAKEUP))
    {
        CoreId = Icu_GetCoreID();
        if (E_OK == Icu_CheckOptMode(Channel, Mask, ICU_SID_ENABLE_WAKEUP, CoreId))
        {
            if (E_OK == Icu_CheckLocalWakeupCapable(Channel, ICU_SID_ENABLE_WAKEUP, CoreId))
            {
#endif
                Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_WAKEUPENABLE);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            }
        }
    }
#endif
}
#endif

#if (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API)
/**
 * @brief      Checks if a wakeup capable ICU channel is the source for a wakeup event and calls
 *             the ECU state manager service EcuM_SetWakeupEvent in case of a valid ICU channel
 *             wakeup event.
 *
 * @param[in]  WakeupSource: Informatin on wakeup source to be checked. The associated ICU
 *                           channel can be determined from configuration data.
 *
 * @return none
 *
 */
/* SWS_Icu_00276 */
void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    Icu_ChannelType Channel;
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_WAKEUP_SOURCE_REPORT)    
    const Icu_ChannelConfigType * ChCfgPtr;
#endif    
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalModuleState(ICU_SID_CHECK_WAKEUP, (uint8)CoreId);
    if (E_OK == RetVal)
    {
#endif
        for (Channel = 0U; Channel < InternalCfgPtr->IcuChSumNum; Channel++)
        {
            if ((Icu_ChannelStateType)(ICU_CHANNEL_STATE_WAKEUPSOURCE |
                                         ICU_CHANNEL_STATE_WAKEUPENABLE) == 
                Icu_GetLocalChannelState(Channel, ICU_CHANNEL_STATE_WAKEUPSOURCE |
                                                     ICU_CHANNEL_STATE_WAKEUPENABLE))
            {
#if (STD_ON == ICU_WAKEUP_SOURCE_REPORT)
                ChCfgPtr = &(*(InternalCfgPtr->IcuChCfgPtr))[Channel];
                if (WakeupSource == (EcuM_WakeupSourceType)ChCfgPtr->ChWakeupSource)
                {
                    EcuM_SetWakeupEvent(WakeupSource);
                    Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_WAKEUPSOURCE);
                }
#else
                Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_WAKEUPSOURCE);
#endif
                break;
            }
        }
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }

    Icu_SetLocalModuleState(RetVal, ICU_SID_CHECK_WAKEUP, (uint8)CoreId);
#endif
}
#endif

#if (STD_ON == ICU_DISABLE_WAKEUP_API)
/**
 * @brief      This function disables the wakeup capability of a single ICU Channel
 *
 * @param[in]  Channel: Logical number of the ICU Channel
 *
 * @return none
 *
 */
void Icu_DisableWakeup(Icu_ChannelType Channel)
{
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint32 CoreId;
    uint8 Mask = (uint8)((1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT) |
                         (1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT) | 
                         (1U << (uint32)ICU_MODE_TIMESTAMP) |
                          (1U << (uint32)ICU_MODE_EDGE_COUNTER));

    CoreId = Icu_GetCoreID();
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_DISABLE_WAKEUP, CoreId);
    if (E_OK == RetVal)
    {
        if (E_OK == Icu_CheckLocalWakeupCapable(Channel, ICU_SID_DISABLE_WAKEUP, CoreId))
        {
#endif
            Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_WAKEUPENABLE);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
#endif
}
#endif

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
 * @brief      This function enables the counting of edges of the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
    const Icu_ConfigType * InternalCfgPtr;
    uint32 CoreId;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
        
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalMode(ICU_SID_ENABLE_EDGE_COUNT);
    if (E_OK == RetVal)
    {
        RetVal = Icu_CheckOptMode(Channel, 1U << (uint32)ICU_MODE_EDGE_COUNTER,
                                                         ICU_SID_ENABLE_EDGE_COUNT, CoreId);
        if (E_OK == RetVal)
        {
#endif            
            Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
            Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
            
            Icu_Drvw_EnableEdgeCount(((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
#endif
}


/**
 * @brief      This function reads the number of counted edges
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return Icu_EdgeNumberType Abstract return type to cover different microcontrollers.
 *
 */
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
    Icu_EdgeNumberType EdgeNum = 0U;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_EDGE_COUNTER);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_GET_EDGE_NUMBERS, CoreId);
    if (E_OK == RetVal)
    {
#endif
        EdgeNum = Icu_Drvw_GetEdgeNumbers(
                                    ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
#endif

    return EdgeNum;
}

/**
 * @brief      This function resets the value of the counted edges to zero.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_EDGE_COUNTER);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_RESET_EDGE_COUNT, CoreId);
    if (E_OK == RetVal)
    {
#endif
        DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;
        Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
        Icu_Drvw_ResetEdgeCount(DrvwHwChCfgPtr);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
#endif
}

/**
 * @brief      This function disables the counting of edges of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_EDGE_COUNTER);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_DISABLE_EDGE_COUNT, CoreId);
    if (E_OK == RetVal)
    {
#endif
        Icu_Drvw_DisableEdgeCount(((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
        Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
#endif
}
#endif

#if (STD_ON == ICU_EDGE_DETECT_API)
/**
 * @brief      This function enables / re-enables the detection of edges of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_EnableEdgeDetection(Icu_ChannelType Channel)
{
    const Icu_ConfigType * InternalCfgPtr;
    uint32 CoreId;  
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = 1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT;
#endif

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
        
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalMode(ICU_SID_ENABLE_EDGE_DETECTION);
    if (E_OK == RetVal)
    {
        RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_ENABLE_EDGE_DETECTION, CoreId);
        if (E_OK == RetVal)
        {
#endif
            Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
            Icu_Drvw_EnableEdgeDetection(((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
#endif
}

/**
 * @brief      This function disables the detection of edges of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_DisableEdgeDetection(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_SIGNAL_EDGE_DETECT);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_DISABLE_EDGE_DETECTION, CoreId);
    if (E_OK == RetVal)
    {
#endif
        Icu_Drvw_DisableEdgeDetection(((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
        Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
#endif
}
#endif

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
 * @brief      This function starts the measurement of signals.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    uint32 CoreId;
#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
    Icu_SignalMeasurementDmaTcbType * DmaTcbPtr;
    uint8 Loop;
    uint32 DmaChId;
#endif    
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = 1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT;
#endif

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
    DmaChId = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh;
#endif    

#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckLocalMode(ICU_SID_START_SIGNAL_MEASUREMENT);
    if (E_OK == RetVal)
    {
        RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_START_SIGNAL_MEASUREMENT, CoreId);
        if (E_OK == RetVal)
        {
#endif
            Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
            Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_OVERFLOW);

            DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;

        #if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
            SchM_Enter_Icu_TimSetDmaParam();
            if(ICU_INVALID_DMACHANNEL != ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh)
            {
                DmaTcbPtr = Icu_GetLocalSigMeasDmaTcb();
                Icu_Drvw_SignalMeasurementDmaGlobalConfig(DmaChId, DrvwHwChCfgPtr, 
                                                            DrvwHwChCfgPtr->InstId);
                Icu_Drvw_SignalMeasurementDmaTransferConfig(DmaChId, DrvwHwChCfgPtr, 
                                                            &DmaTcbPtr->DataBuffer[Channel][0U]);

                /* Enable dma channel request*/
                Icu_Drvw_EnableDmaChannelRequest((Dma_Drv_ChannelType)DmaChId);

                for(Loop = 0U; Loop < ICU_DMA_SIGMEASTS_COUNT; Loop++)
                {
                    DmaTcbPtr->DataBuffer[Channel][Loop] = 0U;
                }
            }
            SchM_Exit_Icu_TimSetDmaParam();
        #endif
        
            Icu_Drvw_StartSignalMeasurement(DrvwHwChCfgPtr);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }
    }
#endif
}

/**
 * @brief      This function stops the measurement of signals of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
    uint32 DmaChId;
#endif
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
    DmaChId = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh;
#endif
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_STOP_SIGNAL_MEASUREMENT, CoreId);
    if (E_OK == RetVal)
    {
#endif
#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
        if (ICU_INVALID_DMACHANNEL != (DmaChId))
        {
            Icu_Drvw_DisableDmaChannelRequest((Dma_Drv_ChannelType)DmaChId);
        }
#endif
        Icu_Drvw_StopSignalMeasurement(((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr);
        Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
#endif
}
#endif

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/**
 * @brief      This function reads the elapsed Signal Low Time for the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return elapsed time
 *
 */
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    Icu_ValueType TimeElapsed = (Icu_ValueType)0U;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
    DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;
    
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_GET_TIME_ELAPSED, CoreId);
    if (E_OK == RetVal)
    {

        Mask = (uint8)((1U << (uint32)ICU_LOW_TIME) |
                       (1U << (uint32)ICU_HIGH_TIME) |
                       (1U << (uint32)ICU_PERIOD_TIME));
        if (E_OK == Icu_CheckLocalSignalMeasurementProperty(Channel, Mask,
                                                             ICU_SID_GET_TIME_ELAPSED, CoreId))
        {
#endif
                TimeElapsed = Icu_Drvw_GetTimeElapsed(DrvwHwChCfgPtr);
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        }

    }
#endif

    return TimeElapsed;
}
#endif

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
/**
 * @brief      This function reads the coherent active time and period time for the given 
 *             ICU Channel.
 *
 * @param[in]  Channel:          Numeric identifier of the ICU channel
 * @param[out] DutyCycleValues : Pointer to a buffer where the results (high time 
 *                               and period time) shall be placed
 *
 * @return none
 *
 */
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues)
{
    uint32 CoreId;
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    Tim_Icu_Drv_DutyCycleType DrvDutyCycleType = 
    {
        0U, 0U
    };
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
    uint8 Mask = (uint8)(1U << (uint32)ICU_MODE_SIGNAL_MEASUREMENT);
#endif
    
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
    DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;
    
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    RetVal = Icu_CheckOptMode(Channel, Mask, ICU_SID_GET_DUTY_CYCLE_VALUES, CoreId);
    if (E_OK == RetVal)
    {

        Mask = (uint8)(1U << (uint32)ICU_DUTY_CYCLE);
        if (E_OK == Icu_CheckLocalSignalMeasurementProperty(Channel, Mask,
                                                     ICU_SID_GET_DUTY_CYCLE_VALUES, CoreId))
        {
            if (E_OK == Icu_CheckLocalGetDutyCycleParam(DutyCycleValues))
            {
#endif
                Icu_Drvw_GetDutyCycleValues(DrvwHwChCfgPtr, &DrvDutyCycleType);
                if (DrvwHwChCfgPtr->ChModule == ICU_DRVW_INSTANCE_TIM)
                {
                    DutyCycleValues->ActiveTime = DrvDutyCycleType.ActiveTime;
                    DutyCycleValues->PeriodTime = DrvDutyCycleType.PeriodTime;
                }

#if (STD_ON == ICU_DEV_ERROR_DETECT)
            }
        }

    }
#endif
}
#endif

#if (STD_ON == ICU_GET_VERSION_INFO_API)
/**
 * @brief      This function returns the version information of this module.
 *
 * @param[out] versioninfo : Pointer to where to store the version information of this module.
 *
 * @return none
 *
 */
void Icu_GetVersionInfo(Std_VersionInfoType * const versioninfo)
{
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    if (E_OK == Icu_CheckLocalGetVersionInfoParam(versioninfo))
    {
#endif
        versioninfo->vendorID = (uint16)ICU_MODULE_ID;
        versioninfo->moduleID = (uint16)ICU_VENDOR_ID;
        versioninfo->sw_major_version = (uint8)ICU_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)ICU_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)ICU_SW_PATCH_VERSION;
#if (STD_ON == ICU_DEV_ERROR_DETECT)
    }
#endif
}
#endif

/**
 * @brief      This function reports the wakeup and overflow events
 *
 * @param[in] Channel : number identifier of the ICU Channel
 * @param[in] OvfFlag : Parameter that indicates the source of report is an overflow 
 *
 * @return none
 *
 */
void Icu_WakeupAndOvfNotification(uint16 Channel, boolean OvfFlag)
{
#if ((STD_ON == ICU_OVERFLOW_NOTIFICATION_API) || (STD_ON == ICU_WAKEUP_SOURCE_REPORT))
    uint32  CoreId;
    const Icu_ChannelConfigType * IcuChCfgPtr;

    CoreId = Icu_GetCoreID();
    IcuChCfgPtr = &(*(Icu_GetLocalInternalCfg(CoreId)->IcuChCfgPtr))[Channel];

#endif     

    if ((ICU_CHANNEL_STATE_WAKEUPENABLE == Icu_GetLocalChannelState(Channel,
                                            ICU_CHANNEL_STATE_WAKEUPENABLE)) &&
                                            (ICU_MODE_SLEEP == Icu_GetLocalMode()))
    {
        Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_WAKEUPSOURCE);
    #if (STD_ON == ICU_WAKEUP_SOURCE_REPORT)
        EcuM_CheckWakeup(IcuChCfgPtr->ChWakeupSource); 
    #endif
    }
    
    if (TRUE == OvfFlag)
    {
        Icu_SetLocalChannelState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
    #if (STD_ON == ICU_OVERFLOW_NOTIFICATION_API)
        if (NULL_PTR != IcuChCfgPtr->ChOvfNotificationFun)
        {
            (IcuChCfgPtr->ChOvfNotificationFun)();
        }
    #endif
    }
}

/**
 * @brief     This function reports the wakeup event, overflow event and notification
 *
 * @param[in] Channel : number identifier of the ICU Channel
 * @param[in] OvfFlag : Parameter that indicates the source of report is an overflow 
 *
 * @return none
 *
 */
void Icu_EventNotification(uint16 Channel, boolean OvfFlag)
{
    uint32  CoreId;

    CoreId = Icu_GetCoreID();
    
    Icu_WakeupAndOvfNotification(Channel, OvfFlag);
    Icu_LocalEventNotification(Channel, CoreId);
}

#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
void Icu_TimestampDmaDoneHandler(Icu_ChannelType Channel)
{
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    uint32 CoreId;
    Icu_TimestampDmaTcbPtrType * DmaTcbPtr;
    uint32 DmaChId;
    uint32 IterCfgCnt;
    uint32 NotifyDiffNum;
    Icu_IndexType UnUsedBufferNum = 0U;
 
    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
    DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;
    DmaTcbPtr = Icu_GetLocalTsDmaTcb();
    DmaChId = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh;

    IterCfgCnt = (uint16)DmaTcbPtr->TransferIndex[Channel];

    SchM_Enter_Icu_TimSetDmaParam();
    DmaTcbPtr->BufferIndex[Channel] += IterCfgCnt;
    UnUsedBufferNum = DmaTcbPtr->BufferSize[Channel] - DmaTcbPtr->BufferIndex[Channel];

    if ((Icu_IndexType)0U != DmaTcbPtr->NotifyInterval[Channel])
    {
        DmaTcbPtr->NotifyCount[Channel] += IterCfgCnt;
        if (DmaTcbPtr->NotifyInterval[Channel] = DmaTcbPtr->NotifyCount[Channel])
        {
            DmaTcbPtr->NotifyCount[Channel] = 0U;
            Icu_LocalEventNotification(Channel, CoreId);
        }
    }
    SchM_Exit_Icu_TimSetDmaParam();

    if (0U == UnUsedBufferNum)
    {
        if ((uint8)(1 << (uint32)ICU_CIRCULAR_BUFFER) == 
                                            ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).ChProperty)
        {
            SchM_Enter_Icu_TimSetDmaParam();
            DmaTcbPtr->BufferIndex[Channel] = 0U;
            Icu_Drvw_SetDmaDestAddr(DmaChId, (uint32)DmaTcbPtr->DataBuffer[Channel]);
            NotifyDiffNum = DmaTcbPtr->NotifyInterval[Channel] - DmaTcbPtr->NotifyCount[Channel];
            if (DmaTcbPtr->BufferSize[Channel] > NotifyDiffNum)
            {
                if ((Icu_IndexType)0U != DmaTcbPtr->NotifyInterval[Channel])
                {
                    Icu_Drvw_SetDmaMinorLoopNum(DmaChId, NotifyDiffNum);
                    DmaTcbPtr->TransferIndex[Channel] = NotifyDiffNum;
                }
            }
            Icu_Drvw_EnableDmaChannelRequest(DmaChId);
            SchM_Exit_Icu_TimSetDmaParam();
        }
        else
        {
            Icu_Drvw_DisableDmaChannelRequest((Dma_Drv_ChannelType)DmaChId);
            Icu_Drvw_StopTimestamp(DrvwHwChCfgPtr);
            Icu_ClearLocalChannelState(Channel, ICU_CHANNEL_STATE_RUNNING);
        }
    }
    else
    {
        SchM_Enter_Icu_TimSetDmaParam();
        if (IterCfgCnt < DmaTcbPtr->NotifyInterval[Channel])
        {
            Icu_Drvw_SetDmaMinorLoopNum(DmaChId, DmaTcbPtr->NotifyInterval[Channel]);
            DmaTcbPtr->TransferIndex[Channel] = DmaTcbPtr->NotifyInterval[Channel];
        }

        if (UnUsedBufferNum < DmaTcbPtr->NotifyInterval[Channel])
        {
            Icu_Drvw_SetDmaMinorLoopNum(DmaChId, UnUsedBufferNum);
            DmaTcbPtr->TransferIndex[Channel] = UnUsedBufferNum;
        }
        Icu_Drvw_EnableDmaChannelRequest(DmaChId);

        SchM_Exit_Icu_TimSetDmaParam();
    }
}
#endif

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
void Icu_SignalMeasurementDmaDoneHandler(Icu_ChannelType Channel, uint8 InstanceId)
{
    const Icu_ConfigType * InternalCfgPtr;
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr;
    Icu_Drvw_InstanceConfigType DrvwInstanceCfg;
    uint32 CoreId;
    Icu_SignalMeasurementDmaTcbType * DmaTcbPtr;
    uint32 DmaChId;
    uint16 IcuCounterModulValue;
    uint32 Loop;
    Icu_ValueType PulseValue;
    Icu_ValueType PeriodValue;
    uint16 ChDataBuffer[ICU_DMA_SIGMEASTS_COUNT];

    CoreId = Icu_GetCoreID();
    InternalCfgPtr = Icu_GetLocalInternalCfg(CoreId);
    DrvwHwChCfgPtr = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DrvwHwChCfgPtr;
    DrvwInstanceCfg = (*InternalCfgPtr->IcuHwInstCfgPtr)[InstanceId].InstanceConfig;

    DmaTcbPtr = Icu_GetLocalSigMeasDmaTcb();
    DmaChId = ((*InternalCfgPtr->IcuChCfgPtr)[Channel]).DmaLogicCh;
    IcuCounterModulValue = (DrvwInstanceCfg.TimIcuInstCfgPtr)->GlobalCfgPtr->MaxCntVal;
    ChDataBuffer[0] = DmaTcbPtr->DataBuffer[Channel][0];
    ChDataBuffer[1] = DmaTcbPtr->DataBuffer[Channel][1];
    Icu_Drvw_DisableDmaChannelRequest(DmaChId);

    if (1U == DmaTcbPtr->IntFlag[Channel])
    {
        SchM_Enter_Icu_TimSetDmaParam();
        if (ChDataBuffer[0] > DmaTcbPtr->StartTimestamp[Channel])
        {
            PulseValue = ChDataBuffer[0] - DmaTcbPtr->StartTimestamp[Channel];
        }
        else
        {
            PulseValue = IcuCounterModulValue - DmaTcbPtr->StartTimestamp[Channel] + ChDataBuffer[0];
        }

        if (ChDataBuffer[1U] > DmaTcbPtr->StartTimestamp[Channel])
        {
            PeriodValue = ChDataBuffer[1U] - DmaTcbPtr->StartTimestamp[Channel];
        }
        else
        {
            PeriodValue = IcuCounterModulValue - DmaTcbPtr->StartTimestamp[Channel] + 
                                                        ChDataBuffer[1U];
        }

        Icu_Drvw_SetSignalMeasurementValue(DrvwHwChCfgPtr, PulseValue, PeriodValue);
        DmaTcbPtr->StartTimestamp[Channel] = ChDataBuffer[1U];
        SchM_Exit_Icu_TimSetDmaParam();
        /* start next dual capture */
        Icu_Drvw_SetDmaDestAddr(DmaChId, (uint32)(&DmaTcbPtr->DataBuffer[Channel][0]));
        Icu_Drvw_EnableDmaChannelRequest(DmaChId);
    }
    else
    {
        /* capture the first edge */
        DmaTcbPtr->StartTimestamp[Channel] = ChDataBuffer[0U];
        
        Icu_Drvw_SetDmaMinorLoopNum(DmaChId, ICU_DMA_SIGMEASTS_COUNT);
        Icu_Drvw_SetDmaDestAddr(DmaChId, (uint32)(&DmaTcbPtr->DataBuffer[Channel][0]));

        for(Loop = 0U; Loop < ICU_DMA_SIGMEASTS_COUNT; Loop++)
        {
            DmaTcbPtr->DataBuffer[Channel][Loop] = 0U;
        }

        Icu_Drvw_SetActivationCondition(ICU_BOTH_EDGES, DrvwHwChCfgPtr);
        Icu_Drvw_EnableDmaChannelRequest(DmaChId);

        DmaTcbPtr->IntFlag[Channel] = 1U;
    }
    
}
#endif

/**
 * @brief      This function reports the wakeup and overflow events
 *
 * @param[in] Channel : number identifier of the ICU Channel
 * @param[in] Mask : Numeric identifier of an ICU channel State
 * @param[in] OptType:  Interrupt set/clear type.
 *             - TRUE: set channel state
 *             - FALSE: clear channel state 
 *
 * @return none
 *
 */
void Icu_SetupChannelStateHandler(uint16 Channel, uint8 Mask, boolean OptType)
{
    if (TRUE == OptType)
    {
        Icu_SetLocalChannelState((Icu_ChannelType)Channel, (Icu_ChannelStateType)Mask);
    }
    else
    {
        Icu_ClearLocalChannelState((Icu_ChannelType)Channel, (Icu_ChannelStateType)Mask);    
    }
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif


/** @} end of group Icu */
/** @} end of group Icu_Module */


