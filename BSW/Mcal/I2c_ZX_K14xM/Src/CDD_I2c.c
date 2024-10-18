/**************************************************************************************************/
/**
 * @file      : CDD_I2c.c
 * @brief     : AUTOSAR I2c driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  CDD_I2c_Module
 *  @{
 */

/** @addtogroup  CDD_I2c
 *  @{
 */

#ifdef __cplusplus
extern "C"{
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
#define CDD_I2C_C_SW_PATCH_VERSION            1U

#if (CDD_I2C_C_VENDOR_ID != CDD_I2C_VENDOR_ID)
    #error "Vendor ID CDD_I2c.c and CDD_I2c.h have different"
#endif
            
#if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != CDD_I2C_AR_RELEASE_MAJOR_VERSION) || \
        (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != CDD_I2C_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of CDD_I2c.c and CDD_I2c.h are different"
#endif
            
#if ((CDD_I2C_C_SW_MAJOR_VERSION != CDD_I2C_SW_MAJOR_VERSION) || \
        (CDD_I2C_C_SW_MINOR_VERSION != CDD_I2C_SW_MINOR_VERSION))
    #error "Software version of CDD_I2c.c and CDD_I2c.h are different"
#endif

#if ((CDD_I2C_C_AR_RELEASE_REVISION_VERSION != CDD_I2C_AR_RELEASE_REVISION_VERSION) || \
        (CDD_I2C_C_SW_PATCH_VERSION != CDD_I2C_SW_PATCH_VERSION))
    #error "Software version of CDD_I2c.c and CDD_I2c.h are different"
#endif

#if (CDD_I2C_C_VENDOR_ID != CDD_I2C_VENDOR_ID)
    #error "Vendor ID CDD_I2c.c and CDD_I2c.h have different"
#endif
            
#if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != CDD_I2C_AR_RELEASE_MAJOR_VERSION) || \
        (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != CDD_I2C_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of CDD_I2c.c and CDD_I2c.h are different"
#endif
            
#if ((CDD_I2C_C_SW_MAJOR_VERSION != CDD_I2C_SW_MAJOR_VERSION) || \
        (CDD_I2C_C_SW_MINOR_VERSION != CDD_I2C_SW_MINOR_VERSION))
    #error "Software version of CDD_I2c.c and CDD_I2c.h are different"
#endif

#if ((CDD_I2C_C_AR_RELEASE_REVISION_VERSION != CDD_I2C_AR_RELEASE_REVISION_VERSION) || \
        (CDD_I2C_C_SW_PATCH_VERSION != CDD_I2C_SW_PATCH_VERSION))
    #error "Software version of CDD_I2c.c and CDD_I2c.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (CDD_I2C_C_VENDOR_ID != SCHM_I2C_H_VENDOR_ID)
        #error "Vendor ID CDD_I2c.c and SchM_I2c.h have different"
    #endif
                
    #if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != SCHM_I2C_H_AR_RELEASE_MAJOR_VERSION) || \
            (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != SCHM_I2C_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of CDD_I2c.c and SchM_I2c.h are different"
    #endif
                
    #if ((CDD_I2C_C_SW_MAJOR_VERSION != SCHM_I2C_H_SW_MAJOR_VERSION) || \
            (CDD_I2C_C_SW_MINOR_VERSION != SCHM_I2C_H_SW_MINOR_VERSION))
        #error "Software version of CDD_I2c.c and SchM_I2c.h are different"
    #endif

    #if ((CDD_I2C_C_AR_RELEASE_REVISION_VERSION != SCHM_I2C_H_AR_RELEASE_REVISION_VERSION) || \
            (CDD_I2C_C_SW_PATCH_VERSION != SCHM_I2C_H_SW_PATCH_VERSION))
        #error "Software version of CDD_I2c.c and SchM_I2c.h are different"
    #endif

    #if (STD_ON == I2C_DEV_ERROR_DETECT)
        #if (CDD_I2C_C_VENDOR_ID != DET_VENDOR_ID)
            #error "Vendor ID CDD_I2c.c and Det.h have different"
        #endif
                    
        #if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
                (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of CDD_I2c.c and Det.h are different"
        #endif
                    
        #if ((CDD_I2C_C_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION) || \
                (CDD_I2C_C_SW_MINOR_VERSION != DET_SW_MINOR_VERSION))
            #error "Software version of CDD_I2c.c and Det.h are different"
        #endif

        #if ((CDD_I2C_C_AR_RELEASE_REVISION_VERSION != DET_AR_RELEASE_REVISION_VERSION) || \
                (CDD_I2C_C_SW_PATCH_VERSION != DET_SW_PATCH_VERSION))
            #error "Software version of CDD_I2c.c and Det.h are different"
        #endif
    #endif

    #if (STD_ON == CDD_I2C_DEM_EVENT_REPORT)
        #if (CDD_I2C_C_VENDOR_ID != DEM_VENDOR_ID)
            #error "Vendor ID CDD_I2c.c and Dem.h have different"
        #endif
                    
        #if ((CDD_I2C_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
                (CDD_I2C_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of CDD_I2c.c and Dem.h are different"
        #endif
                    
        #if ((CDD_I2C_C_SW_MAJOR_VERSION != DEM_SW_MAJOR_VERSION) || \
                (CDD_I2C_C_SW_MINOR_VERSION != DEM_SW_MINOR_VERSION))
            #error "Software version of CDD_I2c.c and Dem.h are different"
        #endif

        #if ((CDD_I2C_C_AR_RELEASE_REVISION_VERSION != DEM_AR_RELEASE_REVISION_VERSION) || \
                (CDD_I2C_C_SW_PATCH_VERSION != DEM_SW_PATCH_VERSION))
            #error "Software version of CDD_I2c.c and Dem.h are different"
        #endif
    #endif

#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#if (I2C_MULTICORE_SUPPORT == STD_ON)
    #define I2c_GetCoreID()           ((uint32)0UL)
#else
    #define I2c_GetCoreID()            ((uint32)0UL)
#endif /* (I2C_MULTICORE_SUPPORT == STD_ON) */


#define I2C_HWUNIT(CoreID, Unit)                                                                   \
    (*(I2c_ConfigPtr[(CoreID)]->I2cChCfgPtr))[Unit]

#define I2C_HWID(CoreID, Unit)                                                                   \
    (I2c_Drv_IdType)(*(I2c_ConfigPtr[(CoreID)]->I2cChCfgPtr))[Unit].I2cPhyUnitCfgPtr->PhsyChId

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
static const I2c_ConfigType * I2c_ConfigPtr[I2C_PARTITIONS_MAXNUM];

/**
 * @brief Variable storing the current module state of the I2c driver
 */
#if (STD_ON == I2C_DEV_ERROR_DETECT)
static I2c_ModuleStateType I2c_ModuleState[I2C_PARTITIONS_MAXNUM];
#endif

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/**
 * @brief Variable storing the current state of each I2c channel
 */
static volatile I2c_ChannelStateType I2c_ChannelState[I2C_CHANNEL_MAXNUM];

/** @} end of group Global_VariableDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief      This function reports the channel status events
 *
 * @param[in] InstId : Select the I2C port.
 * @param[in] UserData : User data
 *
 * @return none
 *
 */
void I2c_ChannelStatusNotification(uint8 InstId, uint8 UserData);


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
LOCAL_INLINE void I2c_SetLocalModuleState(uint8 ServiceId, uint8 CoreId)
{

    if (I2C_SID_DEINIT == ServiceId)
    {
        I2c_ModuleState[CoreId] = I2C_STATE_UNINIT;
    }
    else
    {
        I2c_ModuleState[CoreId] = I2C_STATE_READY;
    }

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
LOCAL_INLINE Std_ReturnType I2c_CheckLocalModuleState(uint8 ServiceId, uint8 CoreId)
{
    Std_ReturnType RetVal = E_OK;

    if (I2C_STATE_UNINIT == I2c_ModuleState[CoreId])
    {
        if (I2C_SID_INIT != ServiceId)
        {
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_UNINIT);
            RetVal = E_NOT_OK;
        }
    }
    else
    {
        if (I2C_SID_INIT == ServiceId)
        {
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_ALREADY_INITIALIZED);
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}

/**
 * @brief      This function check the init configuration param state
 *
 * @param[in]  CoreId:  Internal Channel ID
 * @param[in]  ConfigPtr: Pointer to a I2c initial configuration structure
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
LOCAL_INLINE Std_ReturnType I2c_CheckLocalInitCfgParam(uint8 CoreId,
                                                                 const I2c_ConfigType * ConfigPtr)
{
    Std_ReturnType RetVal = E_OK;

#if (STD_ON == I2C_PRECOMPILE_SUPPORT)
    if (NULL_PTR != ConfigPtr)
    {
#else
    if (NULL_PTR == ConfigPtr)
    {
#endif
        I2C_DET_REPORT_ERROR(I2C_SID_INIT, I2C_E_INIT_FAILED);
        RetVal = E_NOT_OK;
    }

    (void)CoreId;

    return RetVal;
}

/**
* @brief   This function checks parameters for transmit function of I2c driver.
*
* @param[in]     Channel       I2c index of channel number
* @param[in]     RequestPtr     Specifies the pointer to user transmit request
* @param[in]     CoreId        Internal Channel ID
* @param[in]     ServiceId      Specifies what api call this function
*
* @return    Std_ReturnType
* @retval    E_OK:     Successfully.
* @retval    E_NOT_OK: Failed.
*
*/
LOCAL_INLINE Std_ReturnType I2c_CheckLocalTransmitCfgParam(uint8 Channel, 
                                                            const I2c_RequestType * RequestPtr, 
                                                            uint8 CoreId, 
                                                            uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_STATE_READY state */
    if (I2C_STATE_READY != I2c_ModuleState[CoreId])
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        I2C_DET_REPORT_ERROR(ServiceId, I2C_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_CHANNEL_MAXNUM)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_CHANNEL);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Check RequestPtr for not being a null pointer */
            if(NULL_PTR == RequestPtr)
            {
               /* Invalid pointer */
               /* Report error to development error tracer */
                I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_POINTER);
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
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
static inline Std_ReturnType I2c_CheckLocalSlaveCfgParam(uint8 Channel,
                                                                    const I2c_DataType * BufferPtr,
                                                                    uint8 CoreId,
                                                                    uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_STATE_READY != I2c_ModuleState[CoreId])
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        I2C_DET_REPORT_ERROR(ServiceId, I2C_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_CHANNEL_MAXNUM)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_CHANNEL);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Check DataBuffer for not being a null pointer */
            if((NULL_PTR == BufferPtr) && ((uint8)I2C_SID_SETUP_SLAVE_BUFFER == ServiceId))
            {
                /* Invalid pointer */
               /* Report error to development error tracer */
                I2C_DET_REPORT_ERROR(ServiceId, I2C_E_PARAM_POINTER);
                RetVal = (Std_ReturnType)E_NOT_OK;
            }

#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

#if (I2C_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    (void)ServiceId;
    (void)BufferPtr;
    
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
LOCAL_INLINE Std_ReturnType I2c_CheckLocalGetVersionInfoParam(const Std_VersionInfoType * InfoPtr)
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


LOCAL_INLINE I2c_ChannelStateType I2c_GetConvertStatus(const I2c_ChannelType Channel)
{
    
    I2c_ChannelStateType I2cStatus = I2C_STATE_IDLE;
    I2c_Drv_ChannelStateType Status;
    uint32         CoreId;
    I2c_Drv_IdType         InstlId;

    CoreId = I2c_GetCoreID();
    InstlId = I2C_HWID(CoreId, Channel);

    Status = (I2c_Drv_ChannelStateType)I2c_Drv_GetStatus(InstlId,
                                       I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr);
    switch(Status)
    {
        case I2C_DRV_SUCCESS_STATUS: /* STATUS_SUCCESS */
        {
            if(I2C_STATE_IDLE == (I2c_ChannelStateType)(I2c_ChannelState[(uint32)Channel]))
            {
                I2cStatus = I2C_STATE_IDLE;
            }
            else
            {
                I2cStatus = I2C_STATE_FINISHED;
            }

            break;
        }
        case I2C_DRV_BUSY_STATUS: /* STATUS_BUSY */
        {
            if(I2C_STATE_SEND == (I2c_ChannelState[(uint32)Channel]))
            {
                I2cStatus = I2C_STATE_SEND;
            }
            else
            {
                I2cStatus = I2C_STATE_RECEIVE;
            }

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

#if (STD_ON == I2C_E_TIMEOUT_ENABLE)

/**
 * @brief      This function check the channel state
 * 
 * @param[in]  Channel: Numeric identifier of the I2C channel
 *
 * @return    None
 */
LOCAL_INLINE void I2c_ReportDemTimeoutError(void)
{  
    (void)Dem_SetEventStatus((Dem_EventIdType)I2C_E_TIMEOUT_EVENT_ID,
                                 (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);    
}
#endif

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
 * @return none
 *
 */
void I2c_Init(const I2c_ConfigType * ConfigPtr)
{
    I2c_ChannelType Channel;
    uint32 CoreId;
    I2c_Drv_IdType         InstlId;

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif

    CoreId = I2c_GetCoreID();

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    RetVal = I2c_CheckLocalModuleState(I2C_SID_INIT, (uint8)CoreId);
    if (E_OK == RetVal)
    {
        RetVal = I2c_CheckLocalInitCfgParam((uint8)CoreId, ConfigPtr);
        if (E_OK == RetVal)
        {
#endif
        #if (STD_ON == I2C_PRECOMPILE_SUPPORT)
            I2c_ConfigPtr[CoreId] = I2c_PredefinedConfigPtr[CoreId];
            (void)ConfigPtr;
        #else
            I2c_ConfigPtr[CoreId] = ConfigPtr;
        #endif

            /* initiate i2c instance modules */
            for (Channel = 0U; Channel < I2C_CHANNEL_MAXNUM; Channel++)
            {
                InstlId = I2C_HWID(CoreId, Channel);
                I2c_Drv_Init(InstlId, I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr);
                I2c_ChannelState[Channel] = I2C_STATE_IDLE;
            }
            
#if (STD_ON == I2C_DEV_ERROR_DETECT)
        }

        I2c_SetLocalModuleState(I2C_SID_INIT, (uint8)CoreId);
    }
#endif
}

/**
 * @brief      This function de-initializes the I2c module. 
 *
 * @param[in]  none
 *
 * @return     none
 *
 */
void I2c_DeInit(void)
{
    I2c_ChannelType Channel;
    uint32 CoreId;
    I2c_Drv_IdType         InstlId;

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    Std_ReturnType RetVal;
#endif

    CoreId = I2c_GetCoreID();
#if (STD_ON == I2C_DEV_ERROR_DETECT)
    RetVal = I2c_CheckLocalModuleState(I2C_SID_DEINIT, (uint8)CoreId);
    if (E_OK == RetVal)
    {
#endif

        /* clear logic Channel state */
        for (Channel = 0U; Channel < I2C_CHANNEL_MAXNUM; Channel++)
        {
             /* deinitiate i2c instance modules */
            InstlId = I2C_HWID(CoreId, Channel);
            I2c_Drv_DeInit(InstlId, I2C_HWUNIT(CoreId, Channel).I2cPhyUnitCfgPtr);

            I2c_ChannelState[Channel] = I2C_STATE_IDLE;
        }

        I2c_ConfigPtr[CoreId] = NULL_PTR;
#if (STD_ON == I2C_DEV_ERROR_DETECT)
        I2c_SetLocalModuleState(I2C_SID_DEINIT, (uint8)CoreId);
    }
#endif
}

/**
 * @brief      This function check whether status flag is set or not for given status type
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 *
 * @return    I2c_ChannelStateType
 *     I2C_STATE_ERROR_PRESENT:  The driver is error
 *     I2C_STATE_IDLE:    The driver has no pending transfers
 *     I2C_STATE_FINISHED:    The driver is finished
 *
 */
I2c_ChannelStateType I2c_GetStatus(I2c_ChannelType Channel)
{
    I2c_ChannelStateType Status = I2C_STATE_IDLE;
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    uint32         CoreId;

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
 * @brief      This function Sends or receives data I2c blocking 
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  RequestPtr: Pointer to the information structure to be used in the transmission
 * 
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_SyncTransmit(I2c_ChannelType Channel, const I2c_RequestType * RequestPtr)
{
    I2c_ChannelStateType TempChannelStatus;
    I2c_Drv_ChannelStateType TempDrvChannelStatus;
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32         CoreId;
    I2c_Drv_IdType     InstlId;

    CoreId = I2c_GetCoreID();

#if (STD_ON == I2C_DEV_ERROR_DETECT)

    RetVal = I2c_CheckLocalTransmitCfgParam(Channel,
                                                RequestPtr,
                                                (uint8)CoreId,
                                                (uint8)I2C_SID_SYNC_TRANSMIT);

    if((Std_ReturnType)E_OK == RetVal)
    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

        /* Check whether the I2C channel is a master or master/slave channel */
        if (I2C_SLAVE_MODE != I2C_HWUNIT(CoreId, Channel).MasterSlaveMode)
        {

            InstlId = I2C_HWID(CoreId, Channel);
            /* Check whether the I2C channel is in busy state */
            TempChannelStatus = (I2c_ChannelStateType)I2c_GetConvertStatus(Channel);

            if ((I2C_STATE_SEND != TempChannelStatus) && (I2C_STATE_RECEIVE != TempChannelStatus))
            {

                if (I2C_SEND_DATA == RequestPtr->DataDirection)
                {
                    I2c_ChannelState[(uint32)Channel] = I2C_STATE_SEND;
                }
                else
                {
                    I2c_ChannelState[(uint32)Channel] = I2C_STATE_RECEIVE;
                }

                I2c_Drv_SetRequestConfig(InstlId,
                                            RequestPtr->OwnSlaveAddr,
                                            RequestPtr->AddrBitMode, 
                                            RequestPtr->RestartSendData);

                if(I2C_SEND_DATA == RequestPtr->DataDirection)
                {
                    TempDrvChannelStatus = I2c_Drv_MasterSendDataBlocking(InstlId, 
                                                                    RequestPtr->DataBuffer,
                                                                    RequestPtr->BufferSize,
                                                                    RequestPtr->Restart);
                }
                else
                {
                    TempDrvChannelStatus = I2c_Drv_MasterReceiveDataBlocking(InstlId, 
                                                                        RequestPtr->DataBuffer,
                                                                        RequestPtr->BufferSize,
                                                                        RequestPtr->Restart);
                }

#if (STD_ON == I2C_E_TIMEOUT_ENABLE)
                if(I2C_DRV_TIMEOUT_STATUS == TempDrvChannelStatus)
                {
                    I2c_ReportDemTimeoutError();
                }
#endif
                
                if(E_OK != (Std_ReturnType)TempDrvChannelStatus)
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
            /* Invalid channel */
            /* Report error to development error tracer */
            I2C_DET_REPORT_ERROR(I2C_SID_SYNC_TRANSMIT, I2C_E_PARAM_CHANNEL);
            RetVal = E_NOT_OK;                       
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return RetVal;
}

/**
 * @brief      This function Sends or receives data I2c block 
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  RequestPtr: Request Buffer
 * 
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_AsyncTransmit(I2c_ChannelType Channel, const I2c_RequestType * RequestPtr)
{
    I2c_ChannelStateType TempChannelStatus;
    I2c_Drv_ChannelStateType TempDrvChannelStatus;

    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32         CoreId;
    I2c_Drv_IdType         InstlId;

    CoreId = I2c_GetCoreID();
#if (STD_ON == I2C_DEV_ERROR_DETECT)

    RetVal = I2c_CheckLocalTransmitCfgParam(Channel, 
                                                    RequestPtr, 
                                                    (uint8)CoreId, 
                                                    (uint8)I2C_SID_ASYNC_TRANSMIT);
    
    if((Std_ReturnType)E_OK == RetVal)
    {
        /* Check whether the I2C channel is a master or master/slave channel */
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
        if ( I2C_SLAVE_MODE != I2C_HWUNIT(CoreId, Channel).MasterSlaveMode )
        {
            InstlId = I2C_HWID(CoreId, Channel);
            /* Check whether the I2C channel is in busy state */
            TempChannelStatus = (I2c_ChannelStateType)I2c_GetConvertStatus(Channel);

            if ((I2C_STATE_SEND != TempChannelStatus) && (I2C_STATE_RECEIVE != TempChannelStatus))
            {
                if (I2C_SEND_DATA == RequestPtr->DataDirection)
                {
                    I2c_ChannelState[(uint32)Channel] = I2C_STATE_SEND;
                }
                else
                {
                    I2c_ChannelState[(uint32)Channel] = I2C_STATE_RECEIVE;
                }

                I2c_Drv_SetRequestConfig(InstlId,
                                            RequestPtr->OwnSlaveAddr,
                                            RequestPtr->AddrBitMode,
                                            RequestPtr->RestartSendData);

                if(I2C_SEND_DATA == RequestPtr->DataDirection)
                {
                    TempDrvChannelStatus = I2c_Drv_MasterSendData(InstlId, 
                                                                            RequestPtr->DataBuffer, 
                                                                            RequestPtr->BufferSize, 
                                                                            RequestPtr->Restart);
                }
                else
                {
                    TempDrvChannelStatus = I2c_Drv_MasterReceiveData(InstlId, 
                                                                        RequestPtr->DataBuffer, 
                                                                        RequestPtr->BufferSize, 
                                                                        RequestPtr->Restart);
                }

                if(E_OK != (Std_ReturnType)TempDrvChannelStatus)
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
            /* Invalid channel */
            /* Report error to development error tracer */
            I2C_DET_REPORT_ERROR(I2C_SID_SYNC_TRANSMIT, I2C_E_PARAM_CHANNEL);
            RetVal = E_NOT_OK;                        
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return RetVal;
}


/**
 * @brief      This function configure slave data transfer
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  BufferSize Maximum number of bytes to be sent or received.
 * @param[in]  BufferPtr  Pointer to data buffer
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_SetupSlaveBuffer(I2c_ChannelType Channel, 
                                                    I2c_DataType * BufferPtr, 
                                                    uint8 BufferSize)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    I2c_ChannelStateType TempChannelStatus;
    uint32         CoreId;
    I2c_Drv_IdType         InstlId;
    
    CoreId = I2c_GetCoreID();

#if (STD_ON == I2C_DEV_ERROR_DETECT)
    RetVal = I2c_CheckLocalSlaveCfgParam(Channel, 
                                            BufferPtr, 
                                            (uint8)CoreId, 
                                            (uint8)I2C_SID_SETUP_SLAVE_BUFFER);

    if((Std_ReturnType)E_OK == RetVal)
    {
#endif
        InstlId = I2C_HWID(CoreId, Channel);
        /* Check whether the I2C channel is in busy state */
        TempChannelStatus = (I2c_ChannelStateType)I2c_GetConvertStatus(Channel);

        if ((I2C_STATE_SEND != TempChannelStatus) && (I2C_STATE_RECEIVE != TempChannelStatus))
        {
            RetVal = (uint8)I2c_Drv_SetupSlaveBuffer(InstlId, BufferPtr, BufferSize);
        }
        else
        {
#if (STD_ON == I2C_DEV_ERROR_DETECT)
            /* Invalid channel */
            /* Report error to development error tracer */
            I2C_DET_REPORT_ERROR(I2C_SID_SYNC_TRANSMIT, I2C_E_PARAM_CHANNEL);
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
        }
#if (STD_ON == I2C_DEV_ERROR_DETECT)
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return RetVal;
}

/**
 * @brief      This function reports the channel status events
 *
 * @param[in] InstId : Select the I2C port.
 * @param[in] UserData : User data
 *
 * @return none
 *
 */
void I2c_ChannelStatusNotification(uint8 InstId, uint8 UserData)
{
    I2c_Drv_IdType PhsyChId;
    uint32         CoreId;
    I2c_ChannelType Channel;

    CoreId = I2c_GetCoreID();

    for (Channel = 0U; Channel < I2C_CHANNEL_MAXNUM; Channel++)
    {
        PhsyChId = I2C_HWID(CoreId, Channel);
        if((uint8)PhsyChId == InstId)
        {
            I2c_ChannelState[Channel] = (I2c_ChannelStateType)UserData;
        }
    }
}

#if (STD_ON == I2C_GET_VERSION_INFO_API)
/**
 * @brief      This function returns the version information of this module.
 *
 * @param[out] versioninfo : Pointer to where to store the version information of this module.
 *
 * @return none
 *
 */
void I2c_GetVersionInfo(Std_VersionInfoType * const Versioninfo)
{
#if (STD_ON == I2C_DEV_ERROR_DETECT)
    if (E_OK == I2c_CheckLocalGetVersionInfoParam(Versioninfo))
    {
#endif
        Versioninfo->vendorID = (uint16)CDD_I2C_MODULE_ID;
        Versioninfo->moduleID = (uint16)CDD_I2C_VENDOR_ID;
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


