/**************************************************************************************************/
/**
 * @file      : CDD_I2c.c
 * @brief     : AUTOSAR I2c driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  CDD_I2c_Module
 *  @{
 */

/** @addtogroup  CDD_I2c
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "I2c_Drv.h"
#include "CDD_I2c.h"

#include "SchM_I2c.h"
#if (STD_ON == I2C_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

#if (STD_ON == I2C_E_TIMEOUT_ENABLE)
    #include "Dem.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CDD_I2C_C_VENDOR_ID                   0x00B3U
#define CDD_I2C_C_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_I2C_C_AR_RELEASE_MINOR_VERSION    6U
#define CDD_I2C_C_AR_RELEASE_REVISION_VERSION 0U
#define CDD_I2C_C_SW_MAJOR_VERSION            1U
#define CDD_I2C_C_SW_MINOR_VERSION            2U
#define CDD_I2C_C_SW_PATCH_VERSION            2U

#if (CDD_I2C_C_VENDOR_ID != CDD_I2C_VENDOR_ID)
    #error "Vendor ID of CDD_I2c.c and CDD_I2c.h are different"
#endif

#if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != CDD_I2C_AR_RELEASE_MAJOR_VERSION) ||                   \
     (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != CDD_I2C_AR_RELEASE_MINOR_VERSION) ||                   \
     (CDD_I2C_C_AR_RELEASE_REVISION_VERSION != CDD_I2C_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_I2c.c and CDD_I2c.h are different"
#endif

#if ((CDD_I2C_C_SW_MAJOR_VERSION != CDD_I2C_SW_MAJOR_VERSION) ||                                   \
     (CDD_I2C_C_SW_MINOR_VERSION != CDD_I2C_SW_MINOR_VERSION) ||                                   \
     (CDD_I2C_C_SW_PATCH_VERSION != CDD_I2C_SW_PATCH_VERSION))
    #error "Software version of CDD_I2c.c and CDD_I2c.h are different"
#endif

#if (CDD_I2C_C_VENDOR_ID != I2C_DRV_H_VENDOR_ID)
    #error "Vendor ID of CDD_I2c.c and I2c_Drv.h are different"
#endif

#if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != I2C_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != I2C_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (CDD_I2C_C_AR_RELEASE_REVISION_VERSION != I2C_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_I2c.c and I2c_Drv.h are different"
#endif

#if ((CDD_I2C_C_SW_MAJOR_VERSION != I2C_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (CDD_I2C_C_SW_MINOR_VERSION != I2C_DRV_H_SW_MINOR_VERSION) ||                                 \
     (CDD_I2C_C_SW_PATCH_VERSION != I2C_DRV_H_SW_PATCH_VERSION))
    #error "Software version of CDD_I2c.c and I2c_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != SCHM_I2C_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != SCHM_I2C_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of CDD_I2c.c and SchM_I2c.h are different"
    #endif

    #if (STD_ON == I2C_DEV_ERROR_DETECT)
        #if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||               \
             (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of CDD_I2c.c and Det.h are different"
        #endif
    #endif

    #if (STD_ON == I2C_E_TIMEOUT_ENABLE)
        #if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) ||               \
             (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of CDD_I2c.c and Dem.h are different"
        #endif
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define I2c_GetCoreID() ((uint32)McalLib_GetCoreID())

#define I2C_HWUNIT(CoreID, Unit) (I2c_ConfigPtr[(CoreID)]->I2cChCfgPtr)[Unit]

#define I2C_HWID(CoreID, Unit)                                                                     \
    (I2c_Drv_IdType)(I2c_ConfigPtr[(CoreID)]->I2cChCfgPtr)[Unit].I2cPhyUnitCfgPtr->PhysChId

/**
 * @brief Defines MACRO for Det report error.
 */
#define I2C_DET_REPORT_ERROR(ServiceId, ErrorId)                                                   \
    (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (ServiceId), (ErrorId))

/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/**
 * @brief States of the I2c driver
 */
#if (STD_ON == I2C_DEV_ERROR_DETECT)
typedef enum
{
    I2C_STATE_UNINIT = 0U,
    I2C_STATE_READY
} I2c_ModuleStateType;
#endif

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/**
 * @brief I2c autosar interface level configuration structure
 */
static const I2c_ConfigType *I2c_ConfigPtr[I2C_PARTITIONS_MAXNUM];

/**
 * @brief Variable storing the current module state of the I2c driver
 */
#if (STD_ON == I2C_DEV_ERROR_DETECT)
static I2c_ModuleStateType I2c_ModuleState[I2C_PARTITIONS_MAXNUM];
#endif

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_8
#include "I2c_MemMap.h"

/**
 * @brief Table for getting Channel by Instance Id
 */
static I2c_ChannelType I2c_InstIdToChannelMap[I2C_DRV_INSTANCE_NUM];

#define I2C_STOP_SEC_VAR_CLEARED_8
#include "I2c_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
#if (STD_ON == I2C_DEV_ERROR_DETECT)
LOCAL_INLINE Std_ReturnType I2c_CheckInit(uint8 ServiceId, uint32 CoreId,
                                          const I2c_ConfigType *ConfigPtr);
LOCAL_INLINE Std_ReturnType I2c_CheckLocalTransmitCfgParam(uint8                  Channel,
                                                           const I2c_RequestType *RequestPtr,
                                                           uint32 CoreId, uint8 ServiceId);
LOCAL_INLINE Std_ReturnType I2c_CheckLocalSlaveCfgParam(uint8               Channel,
                                                        const I2c_DataType *BufferPtr,
                                                        uint32 CoreId, uint8 ServiceId);
#if (STD_ON == I2C_GET_VERSION_INFO_API)
LOCAL_INLINE Std_ReturnType I2c_CheckLocalGetVersionInfoParam(const Std_VersionInfoType *InfoPtr);
#endif
#endif
LOCAL_INLINE I2c_ChannelStateType I2c_GetConvertStatus(const I2c_ChannelType Channel);
void I2c_CallbackFunc(uint8 Event, uint8 InstId);
void I2c_ErrorCallbackFunc(uint8 Event, uint8 InstId);
#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

#if (STD_ON == I2C_DEV_ERROR_DETECT)

/**
 * @brief      This function check the module state
 *
 * @param[in]  ServiceId:  API service ID
 * @param[in]  CoreId:  Core ID
 * @param[in]  ConfigPtr: Pointer to a I2c initial configuration structure.
 *                        It shall be NULL_PTR in APIs except for I2c_Init().
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType I2c_CheckInit(uint8 ServiceId, uint32 CoreId,
                                          const I2c_ConfigType *ConfigPtr)
{
    Std_ReturnType RetVal = E_OK;

    if (I2C_STATE_UNINIT == I2c_ModuleState[CoreId])
    {
        if (I2C_SID_INIT != ServiceId)
        {
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_UNINIT);
            RetVal = E_NOT_OK;
        }
        else /* I2C_SID_INIT == ServiceId */
        {
    #if (STD_ON == I2C_PRECOMPILE_SUPPORT)
            if (NULL_PTR != ConfigPtr)
    #else
            if (NULL_PTR == ConfigPtr)
    #endif
            {
                I2C_DET_REPORT_ERROR(I2C_SID_INIT, I2C_E_INIT_FAILED);
                RetVal = E_NOT_OK;
            }
        }
    }
    else /* I2C_STATE_READY == I2c_ModuleState[CoreId] */
    {
        if (I2C_SID_INIT == ServiceId)
        {
            I2C_DET_REPORT_ERROR(I2C_SID_INIT, I2C_E_ALREADY_INITIALIZED);
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}

/**
 * @brief   This function checks parameters for transmit function of I2c driver.
 *
 * @param[in]     Channel:       I2c index of channel number
 * @param[in]     RequestPtr:     Specifies the pointer to user transmit request
 * @param[in]     CoreId:        Core ID
 * @param[in]     ServiceId:      Specifies what api call this function
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 *
 */
LOCAL_INLINE Std_ReturnType I2c_CheckLocalTransmitCfgParam(uint8                  Channel,
                                                           const I2c_RequestType *RequestPtr,
                                                           uint32 CoreId, uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    /* Check whether the I2C driver is in I2C_STATE_READY state */
    if (I2C_STATE_READY != I2c_ModuleState[CoreId])
    {
        /* I2C driver has not been initialized yet */
        I2C_DET_REPORT_ERROR(ServiceId, I2C_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_CHANNEL_MAXNUM)
        {
            /* Invalid channel */
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_CHANNEL);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (CoreId != I2C_HWUNIT(CoreId, Channel).ChannelCoreId)
        {
            /* Invalid channel for current core */
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_CHANNEL);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Check RequestPtr for not being a null pointer */
            if (NULL_PTR == RequestPtr)
            {
                /* Invalid pointer */
                I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_POINTER);
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }

    (void)RequestPtr;
    (void)ServiceId;

    return RetVal;
}

/**
 * @brief   This function checks parameters for transmit function of I2c driver.
 *
 * @param[in]     Channel       Specifies the index of channel
 * @param[in]     BufferPtr     Specifies the pointer to check
 * @param[in]     CoreId        Specifies the core Id of current execution
 * @param[in]     ServiceId      Specifies what api call this function
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 *
 */
LOCAL_INLINE Std_ReturnType I2c_CheckLocalSlaveCfgParam(uint8               Channel,
                                                        const I2c_DataType *BufferPtr,
                                                        uint32 CoreId, uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_STATE_READY != I2c_ModuleState[CoreId])
    {
        /* I2C driver has not been initialized yet */
        I2C_DET_REPORT_ERROR(ServiceId, I2C_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_CHANNEL_MAXNUM)
        {
            /* Invalid channel */
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_CHANNEL);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (CoreId != I2C_HWUNIT(CoreId, Channel).ChannelCoreId)
        {
            /* Invalid channel for current core */
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_CHANNEL);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Check DataBuffer for not being a null pointer */
            if (NULL_PTR == BufferPtr)
            {
                /* Invalid pointer */
                I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_POINTER);
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }

    return RetVal;
}

#if (STD_ON == I2C_GET_VERSION_INFO_API)
/**
 * @brief      This function check the get versioninfo param
 *
 * @param[out] InfoPtr : Pointer to where to store the version information of this module.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType I2c_CheckLocalGetVersionInfoParam(const Std_VersionInfoType *InfoPtr)
{
    Std_ReturnType RetVal = E_OK;

    if (NULL_PTR == InfoPtr)
    {
        I2C_DET_REPORT_ERROR(I2C_SID_GET_VERSION_INFO, I2C_E_PARAM_VINFO);
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
#endif
#endif

/**
 * @brief      This function converts driver layer defined status to AUTOSAR layer defined status.
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 *
 * @return    I2c_ChannelStateType
 * @retval    I2C_STATE_IDLE:    The driver is idle and can start a new transmission
 * @retval    I2C_STATE_BUSY:    The driver is busy and cannot start a new transmission
 * @retval    I2C_STATE_ERROR_PRESENT:  There is some error during last transmission
 */
LOCAL_INLINE I2c_ChannelStateType I2c_GetConvertStatus(const I2c_ChannelType Channel)
{
    I2c_ChannelStateType I2cStatus = I2C_STATE_IDLE;
    I2c_Drv_StatusType   Status;
    uint32               CoreId;
    I2c_Drv_IdType       InstId;

    CoreId = I2c_GetCoreID();
    InstId = I2C_HWID(CoreId, Channel);

    Status = I2c_Drv_GetStatus(InstId);
    switch (Status)
    {
        case I2C_DRV_SUCCESS_STATUS:
        {
            I2cStatus = I2C_STATE_IDLE;
            break;
        }
        case I2C_DRV_BUSY_STATUS:
        {
            I2cStatus = I2C_STATE_BUSY;
            break;
        }
        default:
        {
            I2cStatus = I2C_STATE_ERROR_PRESENT;
            break;
        }
    }

    return I2cStatus;
}

/**
 * @brief      I2c callback function for both master and slave mode.
 *
 * @param[in]  Event: event type.
 *              - 0x0A: I2C_DRV_MASTER_EVENT_END_TRANSFER
 *              - 0x0D: I2C_DRV_MASTER_EVENT_RESTART_TRANSFER
 *              - 0x03: I2C_DRV_SLAVE_EVENT_RX_FULL
 *              - 0x04: I2C_DRV_SLAVE_EVENT_TX_EMPTY
 *              - 0x07: I2C_DRV_SLAVE_EVENT_STOP
 *              - 0x0F: I2C_DRV_SLAVE_EVENT_RESTART
 * @param[in]  InstId: The I2C instance id.
 *
 * @return     None
 *
 */
void I2c_CallbackFunc(uint8 Event, uint8 InstId)
{
    uint32          CoreId;
    I2c_ChannelType Channel;

    CoreId = I2c_GetCoreID();
    Channel = I2c_InstIdToChannelMap[InstId];
    I2C_HWUNIT(CoreId, Channel).I2cNotification(Event, Channel);
}

/**
 * @brief      I2c error callback function for both master and slave mode.
 *
 * @param[in]  Event: event type.
 *              - 0x08: I2C_DRV_MASTER_EVENT_NACK
 *              - 0x09: I2C_DRV_MASTER_EVENT_TRANSFER_ERROR
 *              - 0x0B: I2C_DRV_MASTER_EVENT_STUCK_LOW_TIMEOUT
 *              - 0x0E: I2C_DRV_MASTER_EVENT_HOLD_LOW_TIMEOUT(only when dev error detect is on)
 *              - 0x01: I2C_DRV_SLAVE_EVENT_UNDERRUN
 *              - 0x02: I2C_DRV_SLAVE_EVENT_OVERRUN
 * @param[in]  InstId: The I2C instance id.
 *
 * @return     None
 *
 */
void I2c_ErrorCallbackFunc(uint8 Event, uint8 InstId)
{
    uint32          CoreId;
    I2c_ChannelType Channel;

    CoreId = I2c_GetCoreID();
    Channel = I2c_InstIdToChannelMap[InstId];
    I2C_HWUNIT(CoreId, Channel).I2cErrorNotification(Event, Channel);
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief      This function initializes the driver.
 *
 * @param[in]  ConfigPtr: Pointer to a I2c initial configuration structure
 *
 * @return     None
 *
 */
void I2c_Init(const I2c_ConfigType *ConfigPtr)
{
    I2c_ChannelType Channel;
    uint32          CoreId;
    I2c_Drv_IdType  InstId;

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif
    CoreId = I2c_GetCoreID();
#if (STD_ON == I2C_DEV_ERROR_DETECT)
    RetVal = I2c_CheckInit(I2C_SID_INIT, CoreId, ConfigPtr);
    if (E_OK == RetVal)
    {
#endif
#if (STD_ON == I2C_PRECOMPILE_SUPPORT)
        I2c_ConfigPtr[CoreId] = I2c_PredefinedConfigPtr[CoreId];
        (void)ConfigPtr;
#else
    I2c_ConfigPtr[CoreId] = ConfigPtr;
#endif

        /* initiate all configured i2c instances */
        for (Channel = 0U; Channel < I2C_CHANNEL_MAXNUM; Channel++)
        {
            if (CoreId == I2C_HWUNIT(CoreId, Channel).ChannelCoreId)
            {
                InstId = I2C_HWID(CoreId, Channel);
                I2c_InstIdToChannelMap[(uint8)InstId] = Channel;
                I2c_Drv_Init(InstId, I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr);
            }
        }

#if (STD_ON == I2C_DEV_ERROR_DETECT)
        I2c_ModuleState[CoreId] = I2C_STATE_READY;
    }
#endif
}

/**
 * @brief      This function de-initializes the I2c module.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void I2c_DeInit(void)
{
    I2c_ChannelType Channel;
    uint32          CoreId;
    I2c_Drv_IdType  InstId;

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif
    CoreId = I2c_GetCoreID();
#if (STD_ON == I2C_DEV_ERROR_DETECT)
    RetVal = I2c_CheckInit(I2C_SID_DEINIT, CoreId, NULL_PTR);
    if (E_OK == RetVal)
    {
#endif
        for (Channel = 0U; Channel < I2C_CHANNEL_MAXNUM; Channel++)
        {
            if (CoreId == I2C_HWUNIT(CoreId, Channel).ChannelCoreId)
            {
                /* de-initiate all configured i2c instances */
                InstId = I2C_HWID(CoreId, Channel);
                I2c_Drv_DeInit(InstId, I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr);
            }
        }

        I2c_ConfigPtr[CoreId] = NULL_PTR;
#if (STD_ON == I2C_DEV_ERROR_DETECT)
        /* clear logic Channel state */
        I2c_ModuleState[CoreId] = I2C_STATE_UNINIT;
    }
#endif
}

/**
 * @brief      This function returns current channel status
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 *
 * @return    I2c_ChannelStateType
 * @retval    I2C_STATE_IDLE:    The driver is idle and can start a new transmission
 * @retval    I2C_STATE_BUSY:    The driver is busy and cannot start a new transmission
 * @retval    I2C_STATE_ERROR_PRESENT:  There is some error during last transmission
 *
 */
I2c_ChannelStateType I2c_GetStatus(I2c_ChannelType Channel)
{
    I2c_ChannelStateType Status = I2C_STATE_IDLE;
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    uint32 CoreId;

    CoreId = I2c_GetCoreID();

    if (I2C_STATE_UNINIT == I2c_ModuleState[CoreId])
    {
        I2C_DET_REPORT_ERROR(I2C_SID_GET_STATUS, I2C_E_UNINIT);
        Status = I2C_STATE_ERROR_PRESENT;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_CHANNEL_MAXNUM)
        {
            I2C_DET_REPORT_ERROR(I2C_SID_GET_STATUS, I2C_E_PARAM_CHANNEL);
            Status = I2C_STATE_ERROR_PRESENT;
        }
        else if (CoreId != I2C_HWUNIT(CoreId, Channel).ChannelCoreId)
        {
            /* Invalid channel for current core */
            I2C_DET_REPORT_ERROR(I2C_SID_GET_STATUS, I2C_E_PARAM_CHANNEL);
            Status = I2C_STATE_ERROR_PRESENT;
        }
        else
        {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

            Status = I2c_GetConvertStatus(Channel);

#if (I2C_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return Status;
}

/**
 * @brief      This function sends or receives data I2c blocking
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  RequestPtr: Pointer to the information structure to be used in the transmission
 *
 * @return     Std_ReturnType: E_OK or E_NOT_OK.
 * @retval     E_OK:     Successful.
 * @retval     E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_SyncTransmit(I2c_ChannelType Channel, const I2c_RequestType *RequestPtr)
{
    I2c_ChannelStateType ChannelStatus;
    I2c_Drv_StatusType   HwInstanceStatus;
    Std_ReturnType       RetVal = (Std_ReturnType)E_NOT_OK;
    uint32               CoreId;
    I2c_Drv_IdType       InstId;
    I2c_Drv_RequestType  RequestParam;

    CoreId = I2c_GetCoreID();

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    RetVal = I2c_CheckLocalTransmitCfgParam(Channel, RequestPtr, CoreId, I2C_SID_SYNC_TRANSMIT);
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
        /* Check whether the I2C channel is a master or slave channel */
        if (I2C_DRV_MASTER_MODE == I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr->MasterSlaveMode)
        {
            InstId = I2C_HWID(CoreId, Channel);
            /* Check whether the I2C channel is in busy state */
            ChannelStatus = I2c_GetConvertStatus(Channel);
            if (I2C_STATE_BUSY != ChannelStatus)
            {
                RequestParam.TargetAddr = RequestPtr->SlaveAddr;
                RequestParam.AddrBitMode = RequestPtr->AddrBitMode;
                RequestParam.BufferPtr = RequestPtr->DataBuffer;
                RequestParam.BufferSize = RequestPtr->BufferSize;
                RequestParam.SendStop = (TRUE == RequestPtr->Restart) ? FALSE : TRUE;
                RequestParam.SendData = (I2C_SEND_DATA == RequestPtr->DataDirection) ? TRUE : FALSE;
                I2c_Drv_SetRequestConfig(InstId, &RequestParam);

                HwInstanceStatus = I2c_Drv_MasterTransmitData(InstId, TRUE);

#if (STD_ON == I2C_E_TIMEOUT_ENABLE)
                if (I2C_DRV_TIMEOUT_STATUS == HwInstanceStatus)
                {
                    (void)Dem_SetEventStatus(I2C_E_TIMEOUT_EVENT_ID, DEM_EVENT_STATUS_FAILED);
                }
#endif

                if (E_OK != (Std_ReturnType)HwInstanceStatus)
                {
                    RetVal = E_NOT_OK;
                }
            }
            else
            {
                RetVal = E_NOT_OK;
            }
        }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        else
        {
            /* Invalid channel, try to request transmission on slave mode channel */
            I2C_DET_REPORT_ERROR(I2C_SID_SYNC_TRANSMIT, I2C_E_PARAM_CHANNEL);
            RetVal = E_NOT_OK;
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return RetVal;
}

/**
 * @brief      This function sends or receives data I2c non-blocking
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  RequestPtr: Pointer to request configuration structure
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_AsyncTransmit(I2c_ChannelType Channel, const I2c_RequestType *RequestPtr)
{
    I2c_ChannelStateType ChannelStatus;
    I2c_Drv_StatusType   HwInstanceStatus;
    Std_ReturnType       RetVal = (Std_ReturnType)E_NOT_OK;
    uint32               CoreId;
    I2c_Drv_IdType       InstId;
    I2c_Drv_RequestType  RequestParam;

    CoreId = I2c_GetCoreID();
#if (STD_ON == I2C_DEV_ERROR_DETECT)

    RetVal = I2c_CheckLocalTransmitCfgParam(Channel, RequestPtr, CoreId, I2C_SID_ASYNC_TRANSMIT);

    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
        /* Check whether the I2C channel is a master or slave channel */
        if (I2C_DRV_SLAVE_MODE != I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr->MasterSlaveMode)
        {
            InstId = I2C_HWID(CoreId, Channel);
            /* Check whether the I2C channel is in busy state */
            ChannelStatus = I2c_GetConvertStatus(Channel);

            if (I2C_STATE_BUSY != ChannelStatus)
            {
                RequestParam.TargetAddr = RequestPtr->SlaveAddr;
                RequestParam.AddrBitMode = RequestPtr->AddrBitMode;
                RequestParam.BufferPtr = RequestPtr->DataBuffer;
                RequestParam.BufferSize = RequestPtr->BufferSize;
                RequestParam.SendStop = (TRUE == RequestPtr->Restart) ? FALSE : TRUE;
                RequestParam.SendData = (I2C_SEND_DATA == RequestPtr->DataDirection) ? TRUE : FALSE;
                I2c_Drv_SetRequestConfig(InstId, &RequestParam);

                HwInstanceStatus = I2c_Drv_MasterTransmitData(InstId, FALSE);

                if (E_OK != (Std_ReturnType)HwInstanceStatus)
                {
                    RetVal = E_NOT_OK;
                }
            }
            else
            {
                RetVal = E_NOT_OK;
            }
        }
#if (STD_ON == I2C_DEV_ERROR_DETECT)
        else
        {
            /* Invalid channel, try to request transmission on slave mode channel */
            I2C_DET_REPORT_ERROR(I2C_SID_ASYNC_TRANSMIT, I2C_E_PARAM_CHANNEL);
            RetVal = E_NOT_OK;
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return RetVal;
}

/**
 * @brief      This function configures slave data buffer
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  BufferSize: Maximum number of bytes to be sent or received. Range: 1..255
 * @param[in]  BufferPtr:  Pointer to data buffer
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_SetupSlaveBuffer(I2c_ChannelType Channel, I2c_DataType *BufferPtr,
                                    uint8 BufferSize)
{
    Std_ReturnType       RetVal = (Std_ReturnType)E_OK;
    I2c_ChannelStateType ChannelStatus;
    uint32               CoreId;
    I2c_Drv_IdType       InstId;

    CoreId = I2c_GetCoreID();

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    RetVal = I2c_CheckLocalSlaveCfgParam(Channel, BufferPtr, CoreId, I2C_SID_SETUP_SLAVE_BUFFER);

    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        /* Check whether the I2C channel is a master or slave channel */
        if (I2C_DRV_SLAVE_MODE == I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr->MasterSlaveMode)
        {
            InstId = I2C_HWID(CoreId, Channel);
            /* Check whether the I2C channel is in busy state */
            ChannelStatus = I2c_GetConvertStatus(Channel);

            if (I2C_STATE_BUSY != ChannelStatus)
            {
                I2c_Drv_SetupSlaveBuffer(InstId, BufferPtr, BufferSize);
                RetVal = E_OK;
            }
            else
            {
                RetVal = E_NOT_OK;
            }
        }
#if (STD_ON == I2C_DEV_ERROR_DETECT)
        else
        {
            /* Invalid channel, try to configure slave data buffer on master mode channel  */
            I2C_DET_REPORT_ERROR(I2C_SID_SETUP_SLAVE_BUFFER, I2C_E_PARAM_CHANNEL);
            RetVal = E_NOT_OK;
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return RetVal;
}

#if (STD_ON == I2C_GET_VERSION_INFO_API)
/**
 * @brief      This function returns the version information of this module.
 *
 * @param[out] Versioninfo : Pointer to where to store the version information of this module.
 *
 * @return     None
 *
 */
void I2c_GetVersionInfo(Std_VersionInfoType *const Versioninfo)
{
    #if (STD_ON == I2C_DEV_ERROR_DETECT)
    if (E_OK == I2c_CheckLocalGetVersionInfoParam(Versioninfo))
    {
    #endif
        Versioninfo->vendorID = (uint16)CDD_I2C_VENDOR_ID;
        Versioninfo->moduleID = (uint16)CDD_I2C_MODULE_ID;
        Versioninfo->sw_major_version = (uint8)CDD_I2C_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = (uint8)CDD_I2C_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = (uint8)CDD_I2C_SW_PATCH_VERSION;
    #if (STD_ON == I2C_DEV_ERROR_DETECT)
    }
    #endif
}
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c */
/** @} end of group I2c_Module */
