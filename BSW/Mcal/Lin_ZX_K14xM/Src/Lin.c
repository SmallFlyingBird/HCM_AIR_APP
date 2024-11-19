/**************************************************************************************************/
/**
 * @file      : Lin.c
 * @brief     : Lin AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin
 *  @brief Lin AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin.h"
#include "Lin_Drvw.h"

#if (STD_ON == LIN_DEV_ERROR_DETECT )
    #include "Det.h"
#endif
#if(STD_ON == LIN_E_TIMEOUT_ENABLE )
    #include "Dem.h"
#endif
/** @defgroup Private_MacroDefinition
 *  @{
 */
#define LIN_C_VENDOR_ID                   0x00B3U
#define LIN_C_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_C_AR_RELEASE_MINOR_VERSION    6U
#define LIN_C_AR_RELEASE_REVISION_VERSION 0U
#define LIN_C_SW_MAJOR_VERSION            1U
#define LIN_C_SW_MINOR_VERSION            2U
#define LIN_C_SW_PATCH_VERSION            2U

/* Check if current file and Lin header file are of the same vendor */
#if (LIN_C_VENDOR_ID != LIN_VENDOR_ID)
    #error "Vendor ID of Lin.c and Lin.h are different"
#endif

/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_C_AR_RELEASE_MAJOR_VERSION != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_C_AR_RELEASE_MINOR_VERSION != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_C_AR_RELEASE_REVISION_VERSION != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Lin.c and Lin.h are different"
#endif

/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_C_SW_MAJOR_VERSION != LIN_SW_MAJOR_VERSION) || \
     (LIN_C_SW_MINOR_VERSION != LIN_SW_MINOR_VERSION) || \
     (LIN_C_SW_PATCH_VERSION != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version of Lin.c and Lin.h are different"
#endif

/* Check if current file and Lin_Drvw header file are of the same vendor */
#if (LIN_C_VENDOR_ID != LIN_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Lin.c and Lin_Drvw.h are different"
#endif
/* Check if current file and Lin_Drvw header file are of the same Autosar version */
#if ((LIN_C_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||                   \
     (LIN_C_AR_RELEASE_MINOR_VERSION != LIN_DRVW_H_AR_RELEASE_MINOR_VERSION) ||                   \
     (LIN_C_AR_RELEASE_REVISION_VERSION != LIN_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin.c and Lin_Drvw.h are different"
#endif
/* Check if current file and Lin_Drvw header file are of the same Software version */
#if ((LIN_C_SW_MAJOR_VERSION != LIN_DRVW_H_SW_MAJOR_VERSION) ||                                   \
     (LIN_C_SW_MINOR_VERSION != LIN_DRVW_H_SW_MINOR_VERSION) ||                                   \
     (LIN_C_SW_PATCH_VERSION != LIN_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Lin.c and Lin_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((LIN_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                       \
         (LIN_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Lin.c and Det.h are different"
    #endif
#endif

#if(LIN_E_TIMEOUT_ENABLE == STD_ON)
    /* Check if current file and McalLib header file are of the same Autosar version */
    #if ((LIN_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) ||                   \
         (LIN_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Lin.c and Dem.h are different"
    #endif
#endif

#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
/** @} end of Private_MacroDefinition */


/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define LIN_START_SEC_VAR_CLEARED_PTR
#include "Lin_MemMap.h"
/**
 * @brief          Pointer to the configuration structure.
 */
static const Lin_ConfigType *Lin_ConfigPtr[LIN_MAX_PARTITIONS];

/**
 * @brief          Global channel configuration array.
 */
static const Lin_ChannelConfigType *Lin_ChannelConfigPtr[LIN_NUMBER_OF_INSTANCES_USED];


#define LIN_STOP_SEC_VAR_CLEARED_PTR
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_INIT_8
#include "Lin_MemMap.h"
/**
 * @brief          Lin driver status.
 */
/* Pointer to current position in source data buffer */
static uint8 Lin_DrvStatus[LIN_MAX_PARTITIONS] = {LIN_UNINIT};

#define LIN_STOP_SEC_VAR_INIT_8
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

/**
 * @brief         LIN channel status .
 */
static volatile uint8 Lin_ChannelStatusArray[LIN_NUMBER_OF_INSTANCES_USED];

#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"
/** @} end of group Private_VariableDefinition */


/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_DEV_ERROR_DETECT == STD_ON) 
static Std_ReturnType Lin_CheckInit(uint32 LinCoreID, const Lin_ConfigType *ConfigPtr);
#endif
static Std_ReturnType Lin_CheckChannel(const uint8 Channel, const uint8 ServiceId);
static Std_ReturnType Lin_CheckWakeupParam(const uint8 Channel, const uint8 ServiceId);
static void Lin_ReportTimeout(const uint8 ServiceId);

#if (LIN_MASTER_SUPPORT == STD_ON)
static Std_ReturnType Lin_CheckStatus(const uint8 Channel,  uint8* const *Lin_SduPtr);
static Std_ReturnType Lin_CheckSendFrame(const uint8 Channel,const Lin_PduType *PduInfoPtr);
#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @}end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_DEV_ERROR_DETECT == STD_ON) 
/**
 *
 * @brief    This function check the initialization of driver.
 *
 * @param[in]  LinCoreID: Core ID.
 * @param[in]  ConfigPtr: The pointer to the SPI configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 *
 */
 /* SWS_Lin_00105, SWS_Lin_00235, SWS_Lin_00099,  */
static Std_ReturnType Lin_CheckInit(uint32 LinCoreID, const Lin_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if (LIN_UNINIT != Lin_DrvStatus[LinCoreID])
    {
        (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID, (uint8)LIN_SID_INIT,
                              (uint8)LIN_E_STATE_TRANSITION);                
    }
    else /* LIN_UNINIT == Lin_DrvStatus[LinCoreID]  */
    {      
#if (LIN_PRECOMPILE_SUPPORT != STD_ON)
        if(NULL_PTR == ConfigPtr)
        {
            (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)LIN_INSTANCE_ID, (uint8)LIN_SID_INIT,
                              (uint8)LIN_E_PARAM_POINTER);
        }
        else if (LinCoreID != ConfigPtr->PartitionCoreId)
        {
            (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)LIN_INSTANCE_ID, (uint8)LIN_SID_INIT,
                              (uint8)LIN_E_INVALID_POINTER);
        }        
#else /* LIN_PRECOMPILE_SUPPORT == STD_ON */
        if (NULL_PTR != ConfigPtr)
        {
            (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)LIN_INSTANCE_ID, (uint8)LIN_SID_INIT,
                              (uint8)LIN_E_INVALID_POINTER);
        }
        else if((NULL_PTR == Lin_PreDefinedConfigPtr[LinCoreID]) || 
        (Lin_PreDefinedConfigPtr[LinCoreID]->PartitionCoreId != LinCoreID))
        {
            (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)LIN_INSTANCE_ID, (uint8)LIN_SID_INIT,
                              (uint8)LIN_E_INVALID_POINTER);
        }
#endif /* LIN_PRECOMPILE_SUPPORT */
        else
        {
            Ret = (Std_ReturnType)E_OK;
        }
    }
    return Ret;
}

#if (STD_ON == LIN_SOFTWARE_POLLING )
/**
 *
 * @brief    This function is only called by Lin_MainFunction_Handling() to check init status.
 *
 * @param[in] ServiceId: Service IDs of the AUTOSAR LIN API.
 *
 * @return  Std_ReturnType
 * @retval  E_NOT_OK: In case of at least a error occurred.
 * @retval  E_OK: No error occurred.
 *
 */
static Std_ReturnType Lin_CheckMainFunction(const uint8 ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (LIN_UNINIT == Lin_DrvStatus[0U])
    {

        (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID, (uint8)ServiceId,
                              (uint8)LIN_E_UNINIT);
        Ret = E_NOT_OK;
    }
    else
    {
        /*Nothing to do*/
    }
    return Ret;
}
#endif


#endif

/**
 *
 * @brief    This function check the value of channel.
 *
 * @param[in] Channel:LinChannelId.
 * @param[in] ServiceId: Service IDs of the AUTOSAR LIN API.
 *
 * @return  Std_ReturnType
 * @retval  E_NOT_OK: In case of at least a error occurred.
 * @retval  E_OK: No error occurred.
 *
 */
/* SWS_Lin_00235 */
static Std_ReturnType Lin_CheckChannel(const uint8 Channel, const uint8 ServiceId)
{
    Std_ReturnType RetVal = E_OK;
    uint32         CoreId = Lin_GetCoreID;

    if (LIN_INIT != Lin_DrvStatus[CoreId])
    {     
#if (LIN_DEV_ERROR_DETECT == STD_ON) 
        (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID, (uint8)ServiceId,
                              (uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */    
        RetVal = E_NOT_OK;    
    }
    else
    {
        if((Channel >= LIN_NUMBER_OF_INSTANCES_USED) ||
            (FALSE == Lin_ChannelConfigPtr[Channel]->AllocatedPartition)||
            (CoreId != Lin_ChannelConfigPtr[Channel]->ChannelCoreId))
        {
#if (LIN_DEV_ERROR_DETECT == STD_ON) 
            (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID, (uint8)ServiceId,
                                  (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */ 
            RetVal = E_NOT_OK;        
        }
    }
        
    return RetVal;
}

/**
 *
 * @brief    This function check Lin_Wakeup() and Lin_WakeupInternal().
 *
 * @param[in] Channel:LinChannelId.
 * @param[in] ServiceId: Service IDs of the AUTOSAR LIN API.
 *
 * @return  Std_ReturnType
 * @retval  E_NOT_OK: In case of at least a error occurred.
 * @retval  E_OK: No error occurred.
 *
 */
/* SWS_Lin_00235 */
static Std_ReturnType Lin_CheckWakeupParam(const uint8 Channel, const uint8 ServiceId)
{
    Std_ReturnType RetVal = E_NOT_OK;

    RetVal = Lin_CheckChannel(Channel, ServiceId);

    if( E_OK == RetVal )
    {
        if (LIN_CH_SLEEP_STATE != Lin_ChannelStatusArray[Channel])
        {
#if (STD_ON == LIN_DEV_ERROR_DETECT )
            (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID,
                                  (uint8)ServiceId, (uint8)LIN_E_STATE_TRANSITION);
#endif /* STD_ON == LIN_DEV_ERROR_DETECT  */
            RetVal = (uint8)E_NOT_OK;
        }
    }
    else
    {
        /* Nothing to do */
    }
    return RetVal;
}

/**
 *
 * @brief     This function is used to report timeout error.
 *
 * @param[in] ServiceId: Service IDs of the AUTOSAR LIN API.
 *
 * @return    None
 *
 */
static void Lin_ReportTimeout(const uint8 ServiceId)
{
#if (STD_ON == LIN_DEV_ERROR_DETECT )
    (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID,
            (uint8)ServiceId, (uint8)LIN_E_TIMEOUT);
#else
    (void)ServiceId;
#endif

#if (STD_ON == LIN_E_TIMEOUT_ENABLE )
    
    (void)Dem_SetEventStatus((Dem_EventIdType)LIN_E_TIMEOUT_EVENT_ID,
                                 (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);    
#else
    /* Nothing to dp */
#endif /* STD_ON == LIN_E_TIMEOUT_ENABLE*/
}

#if ( STD_ON == LIN_MASTER_SUPPORT )
/**
 *
 * @brief    This function is only called by Lin_GetStatus() to check parameter.
 *
 * @param[in] Channel:LinChannelId.
 * @param[in] Lin_SduPtr: Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *             receive buffer where the current SDU is stored.
 *
 * @return  Std_ReturnType
 * @retval  E_NOT_OK: In case of at least a error occurred.
 * @retval  E_OK: No error occurred.
 *
 */
static Std_ReturnType Lin_CheckStatus(const uint8 Channel, uint8* const *Lin_SduPtr)
{
    Std_ReturnType RetVal = E_NOT_OK;

    RetVal = Lin_CheckChannel(Channel, LIN_SID_GET_STATUS);

    if( E_OK == RetVal )
    {
        if(NULL_PTR == Lin_SduPtr)
        {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID,
                                  (uint8)LIN_SID_GET_STATUS, (uint8)LIN_E_PARAM_POINTER);
#endif    
            RetVal = E_NOT_OK;  
        }
        else
        {
            /*Nothing to do*/
        }
    }
    else
    {
        /*Nothing to do*/
    }
    return RetVal;
}

/**
 *
 * @brief    This function is only called by Lin_GetStatus() to check parameter.
 *
 * @param[in] Channel:LinChannelId
 * @param[in] PduInfoPtr: Pointer to PDU containing the PID, checksum model, response type, Dl and
 *            SDU data pointer
 *
 * @return  Std_ReturnType
 * @retval  E_NOT_OK: In case of at least a error occurred.
 * @retval  E_OK: No error occurred.
 *
 */
static Std_ReturnType Lin_CheckSendFrame(const uint8 Channel, const Lin_PduType *PduInfoPtr)
{
    Std_ReturnType RetVal = E_NOT_OK;

    RetVal = Lin_CheckChannel(Channel, LIN_SID_SEND_FRAME);

    if( E_OK == RetVal )
    {
        if(NULL_PTR == PduInfoPtr)
        {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID,
                                  (uint8)LIN_SID_SEND_FRAME, (uint8)LIN_E_PARAM_POINTER);
#endif
            RetVal = E_NOT_OK;  
        }
        else if(LIN_CH_OPERATIONAL != Lin_ChannelStatusArray[Channel])
        {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID,
                                  (uint8)LIN_SID_SEND_FRAME, (uint8)LIN_E_STATE_TRANSITION);
#endif
            RetVal = E_NOT_OK;              
        }
        else
        {
            /*Nothing to do*/
        }
    }
    else
    {
        /*Nothing to do*/
    }
    return RetVal;
}
#endif/*STD_ON == LIN_MASTER_SUPPORT*/

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
/**
 *
 * @brief     Initializes the LIN module.
 *             - Service ID: 0x00
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Config: Pointer to LIN driver configuration set.
 *
 * @return    None
 *
 */
/*SWS_Lin_00084, SWS_Lin_00150, SWS_Lin_00008, SWS_Lin_00099, SWS_Lin_00105,SWS_Lin_00207*/
void Lin_Init(const Lin_ConfigType *Config)
{
    uint8  ChannelLoop = (uint8)0U;
    uint32 CoreId = Lin_GetCoreID;

#if (STD_ON == LIN_DEV_ERROR_DETECT )
    if(E_OK == Lin_CheckInit(CoreId, Config))
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

#if (LIN_PRECOMPILE_SUPPORT == STD_ON)

    Lin_ConfigPtr[CoreId] = Lin_PreDefinedConfigPtr[CoreId];

#else /* LIN_PRECOMPILE_SUPPORT == STD_OFF */
    
    Lin_ConfigPtr[CoreId] = Config;
    
#endif /* LIN_PRECOMPILE_SUPPORT */
    
    while(ChannelLoop < LIN_NUMBER_OF_INSTANCES_USED)
    {
        if ( CoreId == Lin_ConfigPtr[CoreId]->Lin_ChannelArrayPtr[ChannelLoop]->ChannelCoreId)
        {
            if(TRUE == Lin_ConfigPtr[CoreId]->Lin_ChannelArrayPtr[ChannelLoop]->AllocatedPartition)
            {
                Lin_ChannelConfigPtr[ChannelLoop] = 
                (Lin_ConfigPtr[CoreId]->Lin_ChannelArrayPtr)[ChannelLoop];
                Lin_Drvw_ChannelInit(ChannelLoop, Lin_ChannelConfigPtr[ChannelLoop]->HwConfig);
                Lin_ChannelStatusArray[ChannelLoop] = LIN_CH_SLEEP_STATE;
            }            
        }
        ChannelLoop++;
    }
   
    Lin_DrvStatus[CoreId] = LIN_INIT;
    
    #if (STD_ON == LIN_DEV_ERROR_DETECT )          
    }
    #endif /* STD_ON == LIN_DEV_ERROR_DETECT */
}

/**
 *
 * @brief    This function checks if a wakeup has occurred on the addressed LIN channel.
 *             - Service ID: 0x0a
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: No error has occurred during execution of the API.
 * @retval    E_NOT_OK: An error has occurred during execution of the API.
 *
 */
/*SWS_Lin_00098, SWS_Lin_00107, SWS_Lin_00251*/
Std_ReturnType Lin_CheckWakeup(uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;

    RetVal = Lin_CheckChannel(Channel, LIN_SID_CHECK_WAKE_UP);

    if ((uint8)E_OK == RetVal)
    {
        if ((LIN_CH_SLEEP_STATE == Lin_ChannelStatusArray[Channel]) || 
        (LIN_CH_SLEEP_PENDING == Lin_ChannelStatusArray[Channel]))
        {
             RetVal = Lin_Drvw_CheckWakeup(Channel);
            if ((uint8)E_OK == RetVal)
            {
#if (LIN_WAKEUP_DETECTION == STD_ON)
                if (TRUE == Lin_ChannelConfigPtr[Channel]->HwConfig->LinChannelWakeupSupport)
                {  
                    EcuM_SetWakeupEvent(
                        Lin_ChannelConfigPtr[Channel]->HwConfig->LinChannelEcuMWakeupSource);
                    LinIf_WakeupConfirmation(
                        Lin_ChannelConfigPtr[Channel]->HwConfig->LinChannelEcuMWakeupSource);
                }
#endif
            }
        }
        else
        {
            /* Nothing to do */
        }
    }
    else/*(uint8)E_OK != RetVal*/
    {
        /* Nothing to do */
    }

    return RetVal;
}

#if (LIN_MASTER_SUPPORT == STD_ON)
/**
 *
 * @brief      Gets the status of the LIN driver.Only used for LIN master nodes.
 *             - Service ID: 0x08
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Channel: LIN channel to be addressed.
 * @param[out] Lin_SduPtr: Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *             receive buffer where the current SDU is stored.
 *
 * @return    Lin_StatusType
 * @retval    LIN_NOT_OK - Development or production error occurred.
 * @retval    LIN_TX_OK - Successful transmission.
 * @retval    LIN_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval    LIN_TX_HEADER_ERROR: Erroneous header transmission such as:
 *            - Mismatch between sent and read back data
 *   		  - Identifier parity error or Physical bus error
 * @retval	  LIN_TX_ERROR: Erroneous response transmission such as:
 *			  - Mismatch between sent and read back data
 *			  - Physical bus error
 * @retval	  LIN_RX_OK: Reception of correct response.
 * @retval	  LIN_RX_BUSY: Ongoing reception: at least one response byte has been received,
 *            but the checksum byte has not been received.
 * @retval	  LIN_RX_ERROR: Erroneous response reception such as:
 *			  - Framing error
 *			  - Overrun error
 *			  - Checksum error or Short response
 * @retval	  LIN_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval	  LIN_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *            from the LIN_CH_SLEEP and no data has been sent.
 * @retval	  LIN_CH_SLEEP: Sleep state operation; in this state wake-up detection from slave
 *            nodes is enabled.
 *
 */
/* SWS_Lin_00168,  SWS_Lin_00091, SWS_Lin_00200, SWS_Lin_00092,SWS_Lin_00238, SWS_Lin_00141, 
   SWS_Lin_00143,SWS_Lin_00144, SWS_Lin_00289*/
Lin_StatusType Lin_GetStatus(uint8 Channel, uint8 **Lin_SduPtr)
{
    Lin_StatusType RetVal = LIN_NOT_OK;
    uint8          ChannelState;

    if ((uint8)E_OK == Lin_CheckStatus(Channel, Lin_SduPtr))
    {        
        ChannelState = Lin_ChannelStatusArray[Channel];

        if((uint32)LIN_CH_SLEEP_STATE == ChannelState)
        {
            RetVal = LIN_CH_SLEEP;
        }
        else if(LIN_CH_SLEEP_PENDING == ChannelState)
        {
            Lin_ChannelStatusArray[Channel] = LIN_CH_SLEEP_STATE;                    
            RetVal = LIN_CH_SLEEP;
        }
        else if(LIN_CH_OPERATIONAL == ChannelState)
        {
            RetVal = Lin_Drvw_GetStatus(Channel, Lin_SduPtr);
        }
        else
        {
            /* Nothing to do */
        }                
    }
    else
    {
        /* Nothing to do */
    }

    return RetVal;
}

/**
 *
 * @brief     Sends a LIN header and a LIN response, if necessary. The direction of the frame
 *            response (master response, slave response, slave-to-slave communication) is provided 
 *            by the PduInfoPtr. Only used for LIN master nodes.
 *             - Service ID: 0x04
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed
 * @param[in] PduInfoPtr: Pointer to PDU containing the PID, checksum model, response type, Dl and
 *            SDU data pointer
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Send command has been accepted.
 * @retval    E_NOT_OK: Send command has not been accepted, development or production error
 *            occurred.
 *
 */
/* SWS_Lin_00192,  SWS_Lin_00194, SWS_Lin_00195, SWS_Lin_00197, 
   SWS_Lin_00198, SWS_Lin_00199, SWS_Lin_00235*/
Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr)
{
    Std_ReturnType RetVal = (uint8)E_NOT_OK;

    RetVal = Lin_CheckSendFrame(Channel, PduInfoPtr);

    if ((uint8)E_OK == RetVal)
    {
        RetVal = Lin_Drvw_SendFrame(Channel, PduInfoPtr);

        if ((uint8)E_OK != RetVal)
        {
            if((uint8)LIN_TIMEOUT_ERROR == RetVal)
            {
                Lin_ReportTimeout(LIN_SID_SEND_FRAME);
            }

            RetVal = E_NOT_OK;
        }
        else
        {
#if (STD_ON == LIN_E_TIMEOUT_ENABLE)
                          
            (void)Dem_SetEventStatus((Dem_EventIdType)LIN_E_TIMEOUT_EVENT_ID,
                                        (Dem_EventStatusType)DEM_EVENT_STATUS_PASSED);
            
#endif
        }

    }
    else
    {
        /*Nothing to do*/
    }

    return RetVal;
}

/**
 *
 * @brief     The service instructs the driver to transmit a go-to-sleep-command on the addressed
 *            LIN channel. Only used for LIN master nodes.
 *             - Service ID: 0x06
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Sleep command has been accepted.
 * @retval    E_NOT_OK: Sleep command has not been accepted, development or production error
 *            occurred.
 *
 */
/* SWS_Lin_00089, SWS_Lin_00266, SWS_Lin_00129, SWS_Lin_00131, SWS_Lin_00288 */
Std_ReturnType Lin_GoToSleep(uint8 Channel)
{
    Std_ReturnType RetVal = E_OK;

#if (STD_ON == LIN_DEV_ERROR_DETECT)
    RetVal = Lin_CheckChannel(Channel, LIN_SID_GO_TO_SLEEP);
    if ((uint8)E_OK == RetVal)
    {
#endif      
        if (LIN_CH_SLEEP_STATE == Lin_ChannelStatusArray[Channel])
        {
            /* Nothing to do */
        }
        else
        {
            RetVal = Lin_Drvw_GoToSleep(Channel);
            if ((uint8)E_OK != RetVal)
            {
                if ((uint8)LIN_TIMEOUT_ERROR == RetVal)
                {
                    Lin_ReportTimeout(LIN_SID_GO_TO_SLEEP);
                }

                RetVal = (uint8)E_NOT_OK;
            }
            else
            {
#if (STD_ON == LIN_E_TIMEOUT_ENABLE)
                                  
                (void)Dem_SetEventStatus((Dem_EventIdType)LIN_E_TIMEOUT_EVENT_ID,
                                            DEM_EVENT_STATUS_PASSED);
                
#endif
            }
            Lin_ChannelStatusArray[Channel] = LIN_CH_SLEEP_PENDING;
        }
#if(STD_ON == LIN_DEV_ERROR_DETECT)
    }
    else
    {
        /*Nothing to do*/
    }
#endif
    return RetVal;
}
#endif /* LIN_MASTER_SUPPORT == STD_ON */

/**
 *
 * @brief     Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection and optionally
 *            sets the LIN hardware unit to reduced power operation mode (if supported by HW).
 *             - Service ID: 0x09
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Command has been accepted.
 * @retval    E_NOT_OK: Command has not been accepted, development or production error occurred.
 *
 */
/* SWS_Lin_00095, SWS_Lin_00133, SWS_Lin_00135, SWS_Lin_00234,SWS_Lin_00235*/
Std_ReturnType Lin_GoToSleepInternal(uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
#if (STD_ON == LIN_DEV_ERROR_DETECT )          
    RetVal = Lin_CheckChannel(Channel, LIN_SID_GO_TO_SLEEP_INTERNAL);

    if ((uint8)E_OK == RetVal)
    {
#endif
        if (LIN_CH_SLEEP_STATE != Lin_ChannelStatusArray[Channel])
        {
            RetVal = Lin_Drvw_GoToSleepInternal(Channel);

            if ((uint8)E_OK == RetVal)
            {
                #if (STD_ON == LIN_E_TIMEOUT_ENABLE)
                                   
                (void)Dem_SetEventStatus((Dem_EventIdType)LIN_E_TIMEOUT_EVENT_ID,
                                            (Dem_EventStatusType)DEM_EVENT_STATUS_PASSED);
                
                #endif /* LIN_E_TIMEOUT_ENABLE == STD_ON */
                Lin_ChannelStatusArray[Channel] = LIN_CH_SLEEP_STATE;
            }
            else
            {
                if ((uint8)LIN_TIMEOUT_ERROR == RetVal)
                {
                    Lin_ReportTimeout(LIN_SID_GO_TO_SLEEP_INTERNAL);
                }

                RetVal = (uint8)E_NOT_OK;
            }
            
        }
        else
        {
            RetVal = E_OK;          
        }

#if (STD_ON == LIN_DEV_ERROR_DETECT )            
    }
    else
    {
        /* Nothing to do */
    }
#endif

    return RetVal;
}

/**
 *
 * @brief      Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
 *             - Service ID: 0x07
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Channel: LIN channel to be addressed.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Wake-up request has been accepted.
 * @retval     E_NOT_OK: Wake-up request has not been accepted, development or production error
 *             occurred.
 *
 */
/* SWS_Lin_00137,  SWS_Lin_00139, SWS_Lin_00140*/
Std_ReturnType Lin_Wakeup(uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;

    /* check parameter */
    RetVal = Lin_CheckWakeupParam(Channel, LIN_SID_WAKE_UP);

    if ((uint8)E_OK == RetVal)
    {
        if(E_OK !=  Lin_Drvw_Wakeup(Channel))
        {
            Lin_ReportTimeout(LIN_SID_WAKE_UP);
        }
        Lin_ChannelStatusArray[Channel] = LIN_CH_OPERATIONAL;
        RetVal                     = (uint8)E_OK;
         
    }
    else
    {
        /* Nothing to do */        
    }

    return RetVal;
}

/**
 *
 * @brief      Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 *             - Service ID: 0x0b
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Channel: LIN channel to be addressed.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Wake-up request has been accepted.
 * @retval     E_NOT_OK: Wake-up request has not been accepted, development or production error
 *             occurred.
 *
 */
/* SWS_Lin_00257, SWS_Lin_00258, SWS_Lin_00259, SWS_Lin_00260 */
Std_ReturnType Lin_WakeupInternal(uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;

    RetVal = Lin_CheckWakeupParam(Channel, LIN_SID_WAKE_UP_INTERNAL);

    if ((uint8)E_OK == RetVal)
    {       
        Lin_Drvw_WakeupInternal(Channel);
        Lin_ChannelStatusArray[Channel] = LIN_CH_OPERATIONAL;
        RetVal                     = (uint8)E_OK;
    }
    else
    {
        /* Nothing to do */  
    }

    return RetVal;
}

/**
 *
 * @brief      Lin Driver status is uninit 
 *
 * @param[in]  None.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Deinit ok.
 * @retval     E_NOT_OK: Deinit error.
 *
 */
Std_ReturnType Lin_DeInit(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 CoreId = Lin_GetCoreID;
    uint8  ChannelLoop = (uint8)0U;
    while(ChannelLoop < LIN_NUMBER_OF_INSTANCES_USED)
    {
        RetVal = Lin_Drvw_Deinit(ChannelLoop);
        ChannelLoop++;
    }
    
    Lin_DrvStatus[CoreId] = LIN_UNINIT;
    return RetVal;
}


/**
 *
 * @brief      This service returns the version information of this module.
 *             pre-established configurations
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[inout] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return     None
 *
 */
/*SWS_Lin_00001, SWS_Lin_00248, SWS_Lin_00235 */
#if (LIN_VERSION_INFO_API == STD_ON)
void Lin_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (STD_ON == LIN_DEV_ERROR_DETECT )          
    if (NULL_PTR == versioninfo)
    {       
        (void)Det_ReportError((uint16)LIN_MODULE_ID, (uint8)LIN_INSTANCE_ID,
                              (uint8)LIN_SID_GET_VERSION_INFO, (uint8)LIN_E_PARAM_POINTER);
    }
    else
    {
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        versioninfo->vendorID         = (uint16)LIN_VENDOR_ID;
        versioninfo->moduleID         = (uint8)LIN_MODULE_ID;
        versioninfo->sw_major_version = (uint8)LIN_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)LIN_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)LIN_SW_PATCH_VERSION;
#if (STD_ON == LIN_DEV_ERROR_DETECT )          
    }
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
}
#endif /* LIN_VERSION_INFO_API == STD_ON */


#if (STD_ON == LIN_SOFTWARE_POLLING )
/**
 *
 * @brief     Lin software poll replace interrupts to handle events.
              In this mode,all interrupts need to be closed.
              
 * @param[in] None
 *
 * @return    None
 *
 */
void Lin_MainFunction_Handling(void)
{
    Std_ReturnType RetVal = E_OK;
    uint8  ChannelLoop = (uint8)0U;
#if (STD_ON == LIN_DEV_ERROR_DETECT)
    RetVal = Lin_CheckMainFunction(LIN_SID_MAINFUNCTION_HANDLING);
    if ((uint8)E_OK == RetVal)
    {
#endif

        while(ChannelLoop < LIN_NUMBER_OF_INSTANCES_USED)
        {
            Lin_Drvw_Poll(ChannelLoop);
            ChannelLoop++;
        }

#if (STD_ON == LIN_DEV_ERROR_DETECT )
    }
    else
    {
        /* Nothing to do */
    }
#endif

}

#endif


#if (STD_ON == LIN_SOFTWARE_SIMULATION_TIMEOUT )
/**
 *
 * @brief     Set Lin software simulation status to idle .
              
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    None
 *
 */
void Lin_SetSimulationStatusToIdle(uint8 Channel)
{
    Std_ReturnType RetVal = E_OK;
#if (STD_ON == LIN_DEV_ERROR_DETECT)
    RetVal = Lin_CheckChannel(Channel, LIN_SID_SIMULATION_TIMEOUT);
    if ((uint8)E_OK == RetVal)
    {
#endif      
        Lin_Drvw_SetSimulationStatusToIdle(Channel);
#if (STD_ON == LIN_DEV_ERROR_DETECT )
    }
    else
    {
        /* Nothing to do */
    }
#endif

}
#endif


#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Public_FunctionDefinition */
#ifdef __cplusplus
}
#endif

/** @} end of group Lin */

/** @} end of group Lin_Module */
