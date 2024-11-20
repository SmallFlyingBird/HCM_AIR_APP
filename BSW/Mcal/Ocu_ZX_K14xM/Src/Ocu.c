/**************************************************************************************************/
/**
 * @file      : Ocu.c
 * @brief     : Ocu AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Ocu
 *  @brief Ocu driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Ocu.h"
#include "Ocu_Drvw.h"
#include "SchM_Ocu.h"
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define OCU_C_VENDOR_ID                   0x00B3U
#define OCU_C_AR_RELEASE_MAJOR_VERSION    4U
#define OCU_C_AR_RELEASE_MINOR_VERSION    6U
#define OCU_C_AR_RELEASE_REVISION_VERSION 0U
#define OCU_C_SW_MAJOR_VERSION            1U
#define OCU_C_SW_MINOR_VERSION            2U
#define OCU_C_SW_PATCH_VERSION            2U

/* Check if source file and OCU header file are of the same vendor */
#if (OCU_C_VENDOR_ID != OCU_VENDOR_ID)
    #error "Vendor ID of Ocu.c and Ocu.h are different"
#endif

/* Check if source file and OCU header file are of the same AutoSar version */
#if ((OCU_C_AR_RELEASE_MAJOR_VERSION != OCU_AR_RELEASE_MAJOR_VERSION) ||                           \
     (OCU_C_AR_RELEASE_MINOR_VERSION != OCU_AR_RELEASE_MINOR_VERSION) ||                           \
     (OCU_C_AR_RELEASE_REVISION_VERSION != OCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu.c and Ocu.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_C_SW_MAJOR_VERSION != OCU_SW_MAJOR_VERSION) ||                                           \
     (OCU_C_SW_MINOR_VERSION != OCU_SW_MINOR_VERSION) ||                                           \
     (OCU_C_SW_PATCH_VERSION != OCU_SW_PATCH_VERSION))
    #error "Software Version of Ocu.c and Ocu.h are different"
#endif

/* Check if current file and Ocu_Drvw.h are the same vendor */
#if (OCU_C_VENDOR_ID != OCU_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Ocu.c and Ocu_Drvw.h are different"
#endif
/* Check if current file and Ocu_Drvw.h are the same Autosar version */
#if ((OCU_C_AR_RELEASE_MAJOR_VERSION != OCU_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (OCU_C_AR_RELEASE_MINOR_VERSION != OCU_DRVW_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (OCU_C_AR_RELEASE_REVISION_VERSION != OCU_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu.c and Ocu_Drvw.h are different"
#endif
/* Check if current file and Ocu_Drvw.h are the same Software version */
#if ((OCU_C_SW_MAJOR_VERSION != OCU_DRVW_H_SW_MAJOR_VERSION) ||                                    \
     (OCU_C_SW_MINOR_VERSION != OCU_DRVW_H_SW_MINOR_VERSION) ||                                    \
     (OCU_C_SW_PATCH_VERSION != OCU_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu.c and Ocu_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and SchM_Ocu.h are the same Autosar version */
    #if ((OCU_C_AR_RELEASE_MAJOR_VERSION != SCHM_OCU_H_AR_RELEASE_MAJOR_VERSION) ||                  \
         (OCU_C_AR_RELEASE_MINOR_VERSION != SCHM_OCU_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Ocu.c and SchM_Ocu.h are different"
    #endif
#endif

/* Check if source file and DET header file are of the same version */
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    #ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
        #if ((OCU_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                   \
             (OCU_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Ocu.c and Det.h are different"
        #endif
    #endif
#endif /* OCU_DEV_ERROR_DETECT */

/**
 * @brief Defines MACRO for Ocu configuration.
 */
#define OCU_CONF(CoreID)     (Ocu_ConfigPtr[(CoreID)])

#if (OCU_DEV_ERROR_DETECT == STD_ON)
/**
* @brief        Ocu Det Report Error Macro
*
*/
#define OCU_DET_REPORT_ERROR(ApiId, ErrorId)    \
(void)Det_ReportError((uint16)OCU_MODULE_ID,(uint8)OCU_INSTANCE_ID,         \
                      (uint8)(ApiId),(uint8)(ErrorId));     \

#endif

#define OCU_START_SEC_VAR_CLEARED_PTR
#include "Ocu_MemMap.h"

/**
 * @brief Ocu autosar interface level configuration structure
 */
static const Ocu_ConfigType *Ocu_ConfigPtr[OCU_MAX_PARTITIONS];

#define OCU_STOP_SEC_VAR_CLEARED_PTR
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_INIT_32
#include "Ocu_MemMap.h"

#if (OCU_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief Variable storing the current state of the Ocu driver
 */
static Ocu_GlobalStateType Ocu_GlobalState[OCU_MAX_PARTITIONS] = {OCU_STATE_UNINIT};
#endif

#define OCU_STOP_SEC_VAR_INIT_32
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_CLEARED_32
#include "Ocu_MemMap.h"

/**
 * @brief Variable storing the current state of each OCU channel
 */
static Ocu_ChannelStatusType Ocu_ChannelState[OCU_CONFIGURED_CHANNELS_NUM];

#define OCU_STOP_SEC_VAR_CLEARED_32
#include "Ocu_MemMap.h"

#define OCU_START_SEC_CONFIG_DATA_PTR
#include "Ocu_MemMap.h"

#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
/**
 * @brief pointer to Ocu autosar interface level config structures
 */
extern const Ocu_ConfigType *const Ocu_PreDefinedConfigPtr[OCU_MAX_PARTITIONS];
#endif

#define OCU_STOP_SEC_CONFIG_DATA_PTR
#include "Ocu_MemMap.h"

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (OCU_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function check the initialization of driver.
 *
 * @param[in]  CoreId: Core ID
 * @param[in]  ConfigPtr: The pointer to the OCU configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckInit(uint8 CoreId, const Ocu_ConfigType *ConfigPtr);

#if (OCU_DEINIT_API == STD_ON)
/**
 * @brief      This function check the de-initialization of driver.
 *
 * @param[in]  CoreId: Core ID
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckDeInit(uint8 CoreId);
#endif

/**
 * @brief      This function check channel states of driver.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckChannelState(Ocu_ChannelType ChannelNumber, uint8 ServiceId);

/**
 * @brief      This function services check ocu set pin status.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckSetPinStates(Ocu_ChannelType ChannelNumber, uint8 ServiceId);

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief      This function services check ocu notification.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckNotification(Ocu_ChannelType ChannelNumber, uint8 ServiceId);
#endif

/**
 * @brief      This function check ocu global config of driver.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckGlobalConfig(Ocu_ChannelType ChannelNumber, uint8 ServiceId);

#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"
#if (OCU_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function check the initialization of driver.
 *
 * @param[in]  CoreId: Core ID
 * @param[in]  ConfigPtr: The pointer to the OCU configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckInit(uint8 CoreId, const Ocu_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (OCU_STATE_UNINIT != Ocu_GlobalState[CoreId])
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        OCU_DET_REPORT_ERROR(OCU_SID_INIT, OCU_E_ALREADY_INITIALIZED);
    }
    else
    {
        if (NULL_PTR != OCU_CONF(CoreId))
        {
            OCU_DET_REPORT_ERROR(OCU_SID_INIT, OCU_E_ALREADY_INITIALIZED);
            Ret = (Std_ReturnType)E_NOT_OK;
        }
#if (OCU_PRECOMPILE_SUPPORT == STD_OFF)
        else if (NULL_PTR == ConfigPtr)
        {
            OCU_DET_REPORT_ERROR(OCU_SID_INIT, OCU_E_INIT_FAILED);
            Ret = (Std_ReturnType)E_NOT_OK;
        }
#else
        else if (NULL_PTR != ConfigPtr)
        {
            OCU_DET_REPORT_ERROR(OCU_SID_INIT, OCU_E_INIT_FAILED);
            Ret = (Std_ReturnType)E_NOT_OK;
        }
#endif /*(OCU_PRECOMPILE_SUPPORT == STD_OFF)*/
        else
        {   
#if (OCU_PRECOMPILE_SUPPORT == STD_OFF)
            if (CoreId != ConfigPtr->CoreId)
            {
                Ret = (Std_ReturnType)E_NOT_OK;
                OCU_DET_REPORT_ERROR(OCU_SID_INIT, OCU_E_INIT_FAILED);
            }
            else
            {
                /* Do nothing */
            }
#endif
        }
    }
    return Ret;
}

#if (OCU_DEINIT_API == STD_ON)
/**
 * @brief      This function check the de-initialization of driver.
 *
 * @param[in]  CoreId: Core ID
 * @param[in]  ConfigPtr: The pointer to the OCU configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckDeInit(uint8 CoreId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    if (OCU_STATE_IDLE != Ocu_GlobalState[CoreId])
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        OCU_DET_REPORT_ERROR(OCU_SID_DEINIT, OCU_E_UNINIT);
    }
    else
    {
        if (NULL_PTR != OCU_CONF(CoreId))
        {
            
            /* do nothing */

        }
        else
        {
            /* Driver not yet initialized */
            Ret = (Std_ReturnType)OCU_E_UNINIT;
            OCU_DET_REPORT_ERROR(OCU_SID_DEINIT, OCU_E_UNINIT);
        }
    }
    return (Std_ReturnType)Ret;
}
#endif

/**
 * @brief      This function check channel states of driver.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckChannelState(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    uint8 CoreId = (uint8)Ocu_GetCoreId();
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    /* Check if the driver is initialized */
    if (OCU_STATE_UNINIT == Ocu_GlobalState[CoreId])
    {
        Ret = (Std_ReturnType)OCU_E_UNINIT;
    }
    else
    {
        Ret = Ocu_CheckGlobalConfig(ChannelNumber, ServiceId);
    }

    if ((Std_ReturnType)E_OK != Ret)
    {
        OCU_DET_REPORT_ERROR(ServiceId, Ret);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/**
 * @brief      This function services check ocu set pin status.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckSetPinStates(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    boolean PinConfigStatus;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    uint8 CoreId = (uint8)Ocu_GetCoreId();
    if ((OCU_SID_SET_PIN_STATE == ServiceId) || (OCU_SID_SET_PIN_ACTION == ServiceId))
    {
        if (NULL_PTR != OCU_CONF(CoreId)->OcuChannelsConfigPtr)
        {
            PinConfigStatus =
                (*OCU_CONF(CoreId)->OcuChannelsConfigPtr)[ChannelNumber].OutputPinEnable;
            Ret = (TRUE != PinConfigStatus) ? (Std_ReturnType)OCU_E_PARAM_NO_PIN
                                                   : (Std_ReturnType)E_OK;
            }
        else
        {
            Ret = (Std_ReturnType)OCU_E_PARAM_POINTER;
        }
    }
    return Ret;
}

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief      This function services check ocu notification.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckNotification(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    Ocu_NotificationType ChNotificationCallback;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    uint8 CoreId = (uint8)Ocu_GetCoreId();
    if ((OCU_SID_DISABLE_NOTIFICATION == ServiceId) || (OCU_SID_ENABLE_NOTIFICATION == ServiceId))
    {
        if (NULL_PTR != OCU_CONF(CoreId)->OcuChannelsConfigPtr)
        {
            ChNotificationCallback =
                (*OCU_CONF(CoreId)->OcuChannelsConfigPtr)[ChannelNumber].ChNotification;
            /* store the value to be returned according to the Notification param */
            Ret = (NULL_PTR == ChNotificationCallback) ? (Std_ReturnType)OCU_E_NO_VALID_NOTIF
                                                         : (Std_ReturnType)E_OK;
        }
        else
        {
            Ret = (Std_ReturnType)OCU_E_PARAM_POINTER;
        }
    }
    return Ret;
}
#endif

/**
 * @brief      This function check ocu global config of driver.
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ServiceId: API service ID of function
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Ocu_CheckGlobalConfig(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    uint8 CoreId = (uint8)Ocu_GetCoreId();
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR != OCU_CONF(CoreId))
    {   
        if (ChannelNumber >= OCU_CONFIGURED_CHANNELS_NUM)
        {
            Ret = (Std_ReturnType)OCU_E_PARAM_INVALID_CHANNEL;
        }
        else
        {
            /* switch ServiceId and then check, only one function will be called*/
            Ret = Ocu_CheckSetPinStates(ChannelNumber, ServiceId);
            if ((Std_ReturnType)E_OK == Ret)
            {
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
                Ret = Ocu_CheckNotification(ChannelNumber, ServiceId);
#endif
            }            
        }
    }
    else
    {
        /* Driver not yet initialized */
        Ret = (Std_ReturnType)OCU_E_UNINIT;
    }
    return Ret;
}
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief      Service for OCU initialization.
 *             This function initializes the Ocu driver using the
 *             pre-established configurations
 *             - Service ID: 0x00
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @param[in]  ConfigPtr: Pointer to configuration set
 *
 * @return     None
 */
void Ocu_Init(const Ocu_ConfigType *ConfigPtr)
{
    uint8 ChIdx;
    uint8 CoreId = (uint8)Ocu_GetCoreId();
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType OcuStatus = (Std_ReturnType)E_OK;
    OcuStatus = Ocu_CheckInit(CoreId, ConfigPtr);
    if ((Std_ReturnType)E_NOT_OK != OcuStatus)
    {
#endif
        /* Save configuration pointer in global variable */
#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
        OCU_CONF(CoreId) = Ocu_PreDefinedConfigPtr[CoreId];
#else
        OCU_CONF(CoreId) = ConfigPtr;
#endif
        Ocu_Drvw_Init(OCU_CONF(CoreId)->TimConfig);

        for (ChIdx = 0U; ChIdx < OCU_CONFIGURED_CHANNELS_NUM; ++ChIdx)
        {     
            /* Initialize global data */
            Ocu_ChannelState[ChIdx] = OCU_STATUS_STOPPED;
        }
#if (OCU_DEV_ERROR_DETECT == STD_ON)
        Ocu_GlobalState[CoreId] = OCU_STATE_IDLE;
    }
    else
    {
        /* do nothing */
    }
#endif
}

#if (OCU_DEINIT_API == STD_ON)
/**
 * @brief      Service for OCU de-initialization..
 *             This function de-initializes the OCU driver using the pre-established configurations
 *             The driver needs to be initialized before calling Ocu_DeInit()
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @return     None
 */
void Ocu_DeInit(void)
{
    uint8 ChIdx;
    uint8 ChErrorState = 0;
    uint8 CoreId = Ocu_GetCoreId();
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Ocu_CheckDeInit(CoreId))
    {
#endif
        for (ChIdx = 0U; ChIdx < OCU_CONFIGURED_CHANNELS_NUM; ++ChIdx)
        {
            if (OCU_STATUS_RUNNING == Ocu_ChannelState[ChIdx])
            {
#if (OCU_DEV_ERROR_DETECT == STD_ON)
                OCU_DET_REPORT_ERROR(OCU_SID_DEINIT, (uint8)OCU_E_PARAM_INVALID_STATE);
#endif
                ChErrorState++;
            }
        }
        if ((uint8)0 == ChErrorState)
        {
            Ocu_Drvw_DeInit(OCU_CONF(CoreId)->TimConfig);
            /* Set global configuration pointer back to NULL after de-initialized */
            OCU_CONF(CoreId) = NULL_PTR;
            for (ChIdx = 0U; ChIdx < OCU_CONFIGURED_CHANNELS_NUM; ++ChIdx)
            {
                /* initialize global data */
                Ocu_ChannelState[ChIdx] = OCU_STATUS_UNINITIALIZED;
            }
        }
#if (OCU_DEV_ERROR_DETECT == STD_ON)
        Ocu_GlobalState[CoreId] = OCU_STATE_UNINIT;
    }
    else
    {
        /* do nothing */
    }
#endif
}
#endif

/**
 * @brief      Service to start an OCU channel.
 *             This function  start an OCU channel by 
 *             allowing all compare match configured actions to be performed.
 *             - Service ID: 0x02
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_StartChannel(Ocu_ChannelType ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_START_CHANNEL))
    {
#endif
        if (OCU_STATUS_RUNNING == Ocu_ChannelState[ChannelNumber])
        {
#if (OCU_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportRuntimeError((uint16)OCU_MODULE_ID, 0U, (uint8)OCU_SID_START_CHANNEL,\
                                        (uint8)OCU_E_BUSY);
#endif
        }
        else
        {
            /* Enter to wrapper level to start channel */
            Ocu_Drvw_StartChannel(ChannelNumber);
            /*set channel status to RUNNING*/
            Ocu_ChannelState[ChannelNumber] = OCU_STATUS_RUNNING;
        }
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* do nothing */
    }
#endif
}

/**
 * @brief      Service to stop an OCU channel.
 *             This function stop an OCU channel by 
 *             halting compare match configured actions for this channel.
 *             - Service ID: 0x03
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_StopChannel(Ocu_ChannelType ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_STOP_CHANNEL))
    {
#endif
        if (OCU_STATUS_STOPPED == Ocu_ChannelState[ChannelNumber])
        {
            /* do nothing */
        }
        else
        {
            /* Enter to wrapper level to stop channel */
            Ocu_Drvw_StopChannel(ChannelNumber);
            /*set channel status to STOPPED*/
            Ocu_ChannelState[ChannelNumber] = OCU_STATUS_STOPPED; 
        }
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* do nothing */
    }
#endif
}

#if (OCU_SET_PIN_STATE_API == STD_ON)
/**
 * @brief      Service to set immediately the level of the pin associated to an OCU channel.
 *             This function set the pin associated with
 *              the channel to the level indicated by PinState.
 *             - Service ID: 0x04
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  PinState: Ocu channel pin state after init or deinit
 *
 * @return     None
 */
void Ocu_SetPinState(Ocu_ChannelType ChannelNumber, Ocu_PinStateType PinState)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = ((PinState != OCU_LOW) && (PinState != OCU_HIGH))
                                ? (Std_ReturnType)OCU_E_PARAM_INVALID_STATE
                                : (Std_ReturnType)E_OK;

    if ((Std_ReturnType)E_OK != Ret)
    {
        OCU_DET_REPORT_ERROR((uint8)OCU_SID_SET_PIN_STATE, Ret);
    }
    else
    {
        if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_SET_PIN_STATE))
        {
#endif
            if (OCU_STATUS_RUNNING == Ocu_ChannelState[ChannelNumber])
            {
#if (OCU_DEV_ERROR_DETECT == STD_ON)
                OCU_DET_REPORT_ERROR((uint8)OCU_SID_SET_PIN_STATE, (uint8)OCU_E_PARAM_INVALID_STATE);
#endif
            }
            else
            {
                /* Enter to wrapper level set pin state */
                Ocu_Drvw_SetPinState((uint16)ChannelNumber, (OCU_DRVW_PIN_STATE_TYPE)PinState);
            }
#if (OCU_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
        /* do nothing */
        }
    }
#endif
}
#endif

#if (OCU_SET_PIN_ACTION_API == STD_ON)
/**
 * @brief      Service to indicate the driver what shall be done automatically by 
 *             hardware (if supported) upon compare match.
 *             This function set the action to be performed by hardware automatically, at the next 
 *             compare match in the corresponding OCU channel.
 *             - Service ID: 0x05
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  PinAction: Ocu channel action after compare match
 *
 * @return     None
 */
void Ocu_SetPinAction(Ocu_ChannelType ChannelNumber, Ocu_PinActionType PinAction)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    /* Check pin action */
    Std_ReturnType Ret = ((PinAction != OCU_SET_LOW) && (PinAction != OCU_SET_HIGH) &&
                             (PinAction != OCU_TOGGLE) && (PinAction != OCU_DISABLE))
                                ? (Std_ReturnType)OCU_E_PARAM_INVALID_ACTION
                                : (Std_ReturnType)E_OK;
    if ((Std_ReturnType)E_OK != Ret)
    {
        OCU_DET_REPORT_ERROR((uint8)OCU_SID_SET_PIN_ACTION, Ret);
    }
    else
    {
        if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_SET_PIN_ACTION))
        {
#endif
            /* Enter to wrapper level to set pin action */
            Ocu_Drvw_SetPinAction((uint16)ChannelNumber, (OCU_DRVW_PIN_ACTION_TYPE)PinAction);
#if (OCU_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            /* do nothing */
        }
    }
#endif
}
#endif

#if (OCU_GET_COUNTER_API == STD_ON)
/**
 * @brief      Service to read the current value of the counter.
 *             This function read and return the value of the counter of the channel indicated by 
 *             ChannelNumber.
 *             - Service ID: 0x06
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     Ocu_ValueType
 * @retval     Ret: Content of the counter in ticks
 */
Ocu_ValueType Ocu_GetCounter(Ocu_ChannelType ChannelNumber)
{
    Ocu_ValueType Ret = 0U;

#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_GET_COUNTER))
#endif
    {
        /* Enter to wrapper level to get counter value */
        Ret = Ocu_Drvw_GetCounter(ChannelNumber);
    }
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /* do nothing */
    }
#endif
    return Ret;
}
#endif

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief      This service is used to disable notifications from an OCU channel.
 *             This function disable the OCU compare match notification.
 *             - Service ID: 0x0a
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_DisableNotification(Ocu_ChannelType ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_DISABLE_NOTIFICATION))
    {
#endif
        /* Enter to wrapper level to disable notifications*/
        Ocu_Drvw_DisableNotification((uint16)ChannelNumber);
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* do nothing */
    }
#endif
}
#endif

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief      This service is used to enable notifications from an OCU channel.
 *             This function enable the OCU compare match notification of the indexed channel.
 *             - Service ID: 0x0b
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_EnableNotification(Ocu_ChannelType ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_ENABLE_NOTIFICATION))
    {
#endif
        /* Enter to wrapper level to enable notifications*/
        Ocu_Drvw_EnableNotification((uint16)ChannelNumber);
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* do nothing */
    }
#endif
}
#endif

#if (OCU_VERSION_INFO_API == STD_ON)
/**
 * @brief      This service returns the version information of this module.
 *             This function return the version information of this module. 
 *             The version information includes:
 *             - Module Id
 *             - Vendor Id
 *             - Vendor specific version numbers.
 *             - Service ID: 0x09
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  None
 * @param[out] versioninfo: Pointer to where to store the version information of this module
 *
 * @return     None
 */
void Ocu_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        OCU_DET_REPORT_ERROR(OCU_SID_GET_VERSION_INFO, OCU_E_PARAM_POINTER);
    }
    else
    {
#endif
        versioninfo->vendorID = (uint16)OCU_VENDOR_ID;
        versioninfo->moduleID = OCU_MODULE_ID;
        versioninfo->sw_major_version = (uint8)OCU_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)OCU_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)OCU_SW_PATCH_VERSION;
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/**
 * @brief      Service to set the value of the channel threshold using an absolute input data.
 *             This function set the channel threshold (the compare value) to the value 
 *             given by AbsoluteValue.
 *             - Service ID: 0x07
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ReferenceValue: Value given by the upper layer and used as a base to determine 
 *                             whether to call the notification before the function exits or not.
 *                        This value should be less than configuration parameter OcuMaxCounterValue.
 * @param[in]  AbsoluteValue: Value to compare with the content of the counter. This value is in 
 *                  ticks.This value should be less than configuration parameter OcuMaxCounterValue.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval,
 *                             as a result of setting the new threshold value.
 *
 * @retval     OCU_CM_IN_REF_INTERVAL:   The compare match will occur inside the current 
 *                                       reference interval.
 * @retval     OCU_CM_OUT_REF_INTERVAL:  The compare match will not occur inside the current 
 *                                       reference interval.
 */
Ocu_ReturnType Ocu_SetAbsoluteThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType ReferenceValue,
                                        Ocu_ValueType AbsoluteValue)
{
    Ocu_ReturnType Ret = OCU_CM_OUT_REF_INTERVAL;
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    Ocu_ValueType MaxCntVal;
    if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_SET_ABSOLUTE_THRESHOLD))
    {
        MaxCntVal = Ocu_Drvw_GetMaxCounterValue(ChannelNumber);
        if ((ReferenceValue < MaxCntVal ) && (AbsoluteValue < MaxCntVal))
        {
#endif
            Ret = (OCU_DRVW_CM_IN_REF_INTERVAL ==
                Ocu_Drvw_SetAbsoluteThreshold(
                    (uint16)ChannelNumber, (uint16)ReferenceValue, (uint16)AbsoluteValue))
                    ? OCU_CM_IN_REF_INTERVAL
                    : OCU_CM_OUT_REF_INTERVAL;
#if (OCU_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {  
            OCU_DET_REPORT_ERROR(OCU_SID_SET_ABSOLUTE_THRESHOLD, OCU_E_PARAM_INVALID_VALUE); 
        }
    }
    else
    {
        /* do nothing */
    }
#endif
    return Ret;
}
#endif

#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
/**
 * @brief      Service to set the value of the channel threshold relative to the current value of 
 *             the counter.
 *             This function set the channel threshold (the compare value) to the value 
 *             given by RelativeValue.
 *             - Service ID: 0x08
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  RelativeValue: Value to use for computing the new threshold.
 * This value should be less than configuration parameter OcuMaxCounterValue.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, 
 *                             as a result of setting the new threshold value.
 * 
 * @retval     OCU_CM_IN_REF_INTERVAL:   The compare match will occur inside the current 
 *                                       reference interval.
 * @retval     OCU_CM_OUT_REF_INTERVAL:  The compare match will not occur inside the current 
 *                                       reference interval.
 */
Ocu_ReturnType Ocu_SetRelativeThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType RelativeValue)
{
    Ocu_ReturnType Ret = OCU_CM_OUT_REF_INTERVAL;
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    Ocu_ValueType MaxCntVal;
    if ((Std_ReturnType)E_OK == Ocu_CheckChannelState(ChannelNumber, OCU_SID_SET_RELATIVE_THRESHOLD))
    {
        MaxCntVal = Ocu_Drvw_GetMaxCounterValue(ChannelNumber);
        if (RelativeValue < MaxCntVal)
        {
#endif
            Ret = (OCU_DRVW_CM_IN_REF_INTERVAL ==
                      Ocu_Drvw_SetRelativeThreshold((uint16)ChannelNumber, (uint16)RelativeValue))
                         ? OCU_CM_IN_REF_INTERVAL
                         : OCU_CM_OUT_REF_INTERVAL;
#if (OCU_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {   
            OCU_DET_REPORT_ERROR(OCU_SID_SET_RELATIVE_THRESHOLD, OCU_E_PARAM_INVALID_VALUE); 
        }
    }
    else
    {
        /* do nothing */
    }
#endif
    return Ret;
}
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Ocu */

/** @} end of group Ocu_Module */
