/*************************************************************************************/
/**
 * @file      : Pwm.c
 * @brief     : Pwm AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm
 *  @brief Pwm AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
#include "Pwm.h"
#include "Pwm_Drvw.h"

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* PWM_DEV_ERROR_DETECT */

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define PWM_C_VENDOR_ID                   0x00B3U
#define PWM_C_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_C_AR_RELEASE_MINOR_VERSION    6U
#define PWM_C_AR_RELEASE_REVISION_VERSION 0U
#define PWM_C_SW_MAJOR_VERSION            1U
#define PWM_C_SW_MINOR_VERSION            2U
#define PWM_C_SW_PATCH_VERSION            1U


/* Check if current file and Pwm.h are the same vendor */
#if (PWM_C_VENDOR_ID != PWM_VENDOR_ID)
    #error "Vendor ID of Pwm.c and Pwm.h are different"
#endif
/* Check if current file and Pwm.h are the same AutoSar vision*/
#if ((PWM_C_AR_RELEASE_MAJOR_VERSION    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_C_AR_RELEASE_MINOR_VERSION    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_C_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm.c and Pwm.h are different"
#endif
/* Check if current file and Pwm.h are the same Software vision*/
#if ((PWM_C_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION)  || \
     (PWM_C_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION)  || \
     (PWM_C_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software Version of Pwm.c and Pwm.h are different"
#endif

/* Check if current file and Pwm_Drvw.h are the same vendor */
#if (PWM_C_VENDOR_ID != PWM_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Pwm.c and Pwm_Drvw.h are different"
#endif
/* Check if current file and Pwm_Drvw.h are the same AutoSar vision*/
#if ((PWM_C_AR_RELEASE_MAJOR_VERSION    != PWM_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_C_AR_RELEASE_MINOR_VERSION    != PWM_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_C_AR_RELEASE_REVISION_VERSION != PWM_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm.c and Pwm_Drvw.h are different"
#endif
/* Check if current file and Pwm_Drvw.h are the same Software vision*/
#if ((PWM_C_SW_MAJOR_VERSION != PWM_DRVW_H_SW_MAJOR_VERSION) || \
     (PWM_C_SW_MINOR_VERSION != PWM_DRVW_H_SW_MINOR_VERSION) || \
     (PWM_C_SW_PATCH_VERSION != PWM_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm.c and Pwm_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Det.h are the same Software vision*/
        #if ((PWM_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
            (PWM_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Pwm.c and Det.h are different"
        #endif
    #endif /* PWM_DEV_ERROR_DETECT */
#endif

#define Pwm_GetCoreID()           (uint32)0U

/**
* @brief        PWM Det Report Error macro
*
*/
#define PWM_E_UNINIT_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID,(uint8)PWM_INDEX,\
                      (uint8)(SerId),(uint8)PWM_E_UNINIT);\
                        
#define PWM_E_ALREADY_INITIALIZED_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID,(uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_ALREADY_INITIALIZED);\
 
#define PWM_E_INIT_FAILED_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_INIT_FAILED); \

#define PWM_E_CHANNEL_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_CHANNEL_CONFIGURATION_STRUCTURE);\

#define PWM_E_MODULE_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_MODULE_CONFIGURATION_STRUCTURE);\

#define PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_DUTYCYCLE_RANGE);\
                  
#define PWM_E_PARAM_CHANNEL_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16) PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_PARAM_CHANNEL);\
                        
#define PWM_E_PARAM_PHASESHIFT_RANGE_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_PARAM_PHASESHIFT_RANGE);\
                        
#define PWM_E_TRIGGER_MASK_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                (uint8)(SerId), (uint8)PWM_E_TRIGGER_MASK);\
                        
#define PWM_E_PARAM_INSTANCE_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_PARAM_INSTANCE);\
                        
#define PWM_E_PARAM_POINTER_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID,(uint8)PWM_INDEX,\
                      (uint8)(SerId),(uint8)PWM_E_PARAM_POINTER);\
                        
#define PWM_E_POWER_STATE_NOT_SUPPORTED_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID,(uint8)PWM_INDEX,\
                      (uint8)(SerId),(uint8)PWM_E_POWER_STATE_NOT_SUPPORTED);\
                        
#define PWM_E_PERIPHERAL_NOT_PREPARED_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_PERIPHERAL_NOT_PREPARED);\
                        
#define PWM_E_PARAM_CONFIG_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_PARAM_CONFIG);\
                        
#define PWM_E_PERIODVALUE_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX,\
                      (uint8)(SerId), (uint8)PWM_E_PERIODVALUE);\

#define PWM_E_PERIOD_UNCHANGEABLE_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX, \
                      (uint8)(SerId), (uint8)PWM_E_PERIOD_UNCHANGEABLE);\

#define PWM_E_PARAM_NOTIFICATION_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX, \
                      (uint8)(SerId), (uint8)PWM_E_PARAM_NOTIFICATION);\

#define PWM_E_PARAM_NOTIFICATION_NULL_DET_REPORT_ERROR(SerId)\
(void)Det_ReportError((uint16)PWM_INSTANCE_ID, (uint8)PWM_INDEX, \
                      (uint8)(SerId), (uint8)PWM_E_PARAM_NOTIFICATION_NULL);\
                      
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
#define PWM_START_SEC_VAR_INIT_PTR 
#include "Pwm_MemMap.h"

static const Pwm_ConfigType * Pwm_ConfigPtr[PWM_MAX_PARTITIONS] = {NULL_PTR};

#define PWM_STOP_SEC_VAR_INIT_PTR
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

static Pwm_DriverStateType Pwm_DrvState[PWM_MAX_PARTITIONS];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if (PWM_DEV_ERROR_DETECT == STD_ON)

#if ((PWM_SET_PERIOD_AND_DUTY_API               == STD_ON) || \
     (PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API   == STD_ON) || \
     (PWM_SET_PHASE_SHIFT_TICKS_API             == STD_ON) || \
     (PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON))
LOCAL_INLINE Std_ReturnType Pwm_CheckParamsPeriodClass(Pwm_ChannelType ChannelNumber,
                        Pwm_ChannelClassType ChannelClass, Pwm_PeriodType Period, uint8 ServiceId);
#endif
 
#endif /* PWM_DEV_ERROR_DETECT */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

#if (PWM_DEV_ERROR_DETECT == STD_ON)
#if ((PWM_SET_DUTY_CYCLE_API                    == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API               == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API                == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API                  == STD_ON) || \
     (PWM_GET_CHANNEL_DUTYCYCLE_API          == STD_ON) || \
     (PWM_FORCE_OUTPUT_TO_LOW_LEVEL_API         == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED                == STD_ON) || \
     (PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API   == STD_ON) || \
     (PWM_WRITE_DUTY_CYCLE_TO_BUFFER_API        == STD_ON) || \
     (PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON) || \
     (PWM_SYNC_UPDATE_API                       == STD_ON) || \
     (PWM_SET_PHASE_SHIFT_TICKS_API             == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_TICKS_API       == STD_ON) || \
     (PWM_SET_DUTY_AND_PHASE_SHIFT_TICKS_API    == STD_ON))

/**
* @brief        Check the Hw init state.
*
* @param[in]    CoreId          Core ID
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType  
* @retval       E_OK            Hw init
* @retval       E_NOT_OK        Hw uninit
*
*/
static Std_ReturnType Pwm_CheckHwInitCall(uint32 CoreId, uint8 ServiceId)
{
    Std_ReturnType RetVal;
    
    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
         PWM_E_UNINIT_DET_REPORT_ERROR(ServiceId);
         RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    
    return RetVal;
}

/**
* @brief        Check that the channel is in valid range.
*
* @param[in]    ChannelNumber   PWM logic channel ID in the AutoSar configuration structure
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType  
* @retval       E_OK            Channel is in valid range
* @retval       E_NOT_OK        Channel is not in valid range
*
*/
static Std_ReturnType Pwm_CheckChnParamCall(Pwm_ChannelType ChannelNumber, uint8 ServiceId)
{
    Std_ReturnType RetVal;
    
    if (PWM_CONFIG_LOGIC_CHANNELS <= ChannelNumber)
    {
         PWM_E_PARAM_CHANNEL_DET_REPORT_ERROR(ServiceId);
         RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    
    return RetVal;
}
/**
* @brief        Check that the channel is in current partition.
*
* @param[in]    ChannelNumber   PWM logic channel ID in the AutoSar configuration structure
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType  
* @retval       E_OK            Channel is in current partition
* @retval       E_NOT_OK        Channel is not current partition
*
*/
static Std_ReturnType Pwm_CheckChnCfgCall(Pwm_ChannelType ChannelNumber, uint8 ServiceId)
{
    Std_ReturnType RetVal;
    uint32 CoreId = Pwm_GetCoreID();
    
    if (ChannelNumber >= Pwm_ConfigPtr[CoreId]->NumChannels)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        PWM_E_PARAM_CONFIG_DET_REPORT_ERROR(ServiceId);
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    
    return RetVal;
}
/**
* @brief        Check channel configuration structure.
*
* @param[in]    ChannelNumber   PWM logic channel ID in the AutoSar configuration structure
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType
* @retval       E_OK            The channel configuration structure is correct
* @retval       E_NOT_OK        The channel configuration structure error
*
*/
static Std_ReturnType Pwm_CheckChnCfgStruct(Pwm_ChannelType ChannelNumber, uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr =
                (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;

    if(PWM_DRVW_HW_MCPWM == DrvwChnCfgPtr->ChnHwType)
    {
        if (NULL_PTR == DrvwChnCfgPtr->McpwmChConfig)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            PWM_E_CHANNEL_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(ServiceId);
        }
    }
    else if(PWM_DRVW_HW_TIM == DrvwChnCfgPtr->ChnHwType)
    {
        if (NULL_PTR == DrvwChnCfgPtr->TimChConfig)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            PWM_E_CHANNEL_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(ServiceId);
        }
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        PWM_E_CHANNEL_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(ServiceId);
    }

    return RetVal;
}

/**
* @brief        Check module configuration structure.
*
* @param[in]    ModuleId        PWM HW module ID.
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType
* @retval       E_OK            The module configuration structure is correct
* @retval       E_NOT_OK        The module configuration structure error
*
*/
static Std_ReturnType Pwm_CheckModuleCfgStruct(uint8 ModuleId, uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_HwConfigType * DrvwHwCfgPtr =
                                    &((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[ModuleId]);

    if(PWM_DRVW_HW_MCPWM == DrvwHwCfgPtr->HwType)
    {
        if (NULL_PTR == DrvwHwCfgPtr->McpwmHwConfig)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            PWM_E_MODULE_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(ServiceId);
        }
    }
    else if(PWM_DRVW_HW_TIM == DrvwHwCfgPtr->HwType)
    {
        if (NULL_PTR == DrvwHwCfgPtr->TimHwConfig)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            PWM_E_MODULE_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(ServiceId);
        }
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        PWM_E_MODULE_CONFIGURATION_STRUCTURE_DET_REPORT_ERROR(ServiceId);
    }

    return RetVal;
}

/**
* @brief        Check pwm configuration structure.
*
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType
* @retval       E_OK            The pwm configuration structure is correct
* @retval       E_NOT_OK        The pwm configuration structure error
*
*/
static Std_ReturnType Pwm_CheckPwmCfgStruct(uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    uint8 Index;

    for(Index = 0U; Index < Pwm_ConfigPtr[CoreId]->NumChannels; Index++)
    {
        RetVal = Pwm_CheckChnCfgStruct(Index, ServiceId);
        if((Std_ReturnType)E_NOT_OK == RetVal)
        {
            break;
        }
    }
    if((Std_ReturnType)E_OK == RetVal)
    {
        for (Index = 0U; Index < Pwm_ConfigPtr[CoreId]->NumModules; Index++)
        {
            RetVal = Pwm_CheckModuleCfgStruct(Index, ServiceId);
            if((Std_ReturnType)E_NOT_OK == RetVal)
            {
                break;
            }
        }
    }

    return RetVal;
}

/**
* @brief        Check Hw init state, check channel is in valid range and check channel is in current
*               partition.
*
* @param[in]    ChannelNumber   PWM logic channel ID in the AutoSar configuration structure
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType
* @retval       E_OK            Channel is in current partition
* @retval       E_NOT_OK        Channel is not current partition
*
*/
static Std_ReturnType Pwm_CheckHwAndChannel(Pwm_ChannelType ChannelNumber, uint8 ServiceId)
{
    Std_ReturnType RetVal;
    uint32 CoreId = Pwm_GetCoreID();

    RetVal = Pwm_CheckHwInitCall(CoreId, ServiceId);
    if((Std_ReturnType)E_OK == RetVal)
    {
        RetVal = Pwm_CheckChnParamCall(ChannelNumber, ServiceId);
        if((Std_ReturnType)E_OK == RetVal)
        {
            RetVal = Pwm_CheckChnCfgCall(ChannelNumber, ServiceId);
            if((Std_ReturnType)E_OK == RetVal)
            {
                RetVal = Pwm_CheckChnCfgStruct(ChannelNumber, ServiceId);
            }
        }
    }

    return RetVal;
}

/**
* @brief        Check if initialization is allowed.
*
* @param[in]    ConfigPtr       Pointer to configuration set
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType
* @retval       E_OK            Allow initialization
* @retval       E_NOT_OK        Initialization not allowed
*
*/
static Std_ReturnType Pwm_CheckInit(const Pwm_ConfigType * ConfigPtr, uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

    if (PWM_STATE_UNINIT != Pwm_DrvState[CoreId].PwmGlobalState)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        PWM_E_ALREADY_INITIALIZED_DET_REPORT_ERROR(ServiceId);
    }
    else
    {
    #if (PWM_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != ConfigPtr)
        {
    #else
        if (NULL_PTR == ConfigPtr)
        {
    #endif
            RetVal = (Std_ReturnType)E_NOT_OK;
            PWM_E_INIT_FAILED_DET_REPORT_ERROR(ServiceId);
        }
        else
        {
        #if (PWM_PRECOMPILE_SUPPORT == STD_ON)
            Pwm_ConfigPtr[CoreId] = Pwm_PreDefinedConfigPtr[CoreId];
            (void)ConfigPtr;
        #else
            Pwm_ConfigPtr[CoreId] = ConfigPtr;
        #endif

            RetVal = Pwm_CheckPwmCfgStruct(ServiceId);
        }
    }

    return RetVal;
}

/**
* @brief        Check if setting power status is allowed.
*
* @param[out]   Result
*                 - PWM_NOT_INIT           PWM Module not initialized.
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType
* @retval       E_OK            Allow setting of power status
* @retval       E_NOT_OK        Setting power status is not allowed
*
*/
static Std_ReturnType Pwm_CheckSetPowerState(Pwm_PowerStateRequestResultType * Result,
                                                                         uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
        *Result = PWM_NOT_INIT;
        RetVal = (Std_ReturnType)E_NOT_OK;
        PWM_E_UNINIT_DET_REPORT_ERROR(ServiceId);
    }
    else
    {
        RetVal = Pwm_CheckPwmCfgStruct(ServiceId);
    }

    return RetVal;
}

#endif

 
#if ((PWM_SET_PERIOD_AND_DUTY_API               == STD_ON) || \
     (PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API   == STD_ON) || \
     (PWM_SET_PHASE_SHIFT_TICKS_API             == STD_ON) || \
     (PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON))
/**
* @brief        Check the period range and if the pwm channel class supports variable period feature.
*
* @param[in]    ChannelNumber   PWM logic channel ID in the AutoSar configuration structure
* @param[in]    channelClass    PWM channel class
* @param[in]    Period          Period in ticks
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType  Check result of Channel Class, DutyCycle, Period parameters
* @retval       E_OK            Channel Class, Period are all valid
* @retval       E_NOT_OK        One of Channel Class, Period is wrong
*
*/
LOCAL_INLINE Std_ReturnType Pwm_CheckParamsPeriodClass(Pwm_ChannelType ChannelNumber,
                        Pwm_ChannelClassType ChannelClass, Pwm_PeriodType Period, uint8 ServiceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    
#if (PWM_MAX_PERIOD_PLAUSABILITY == STD_ON)
    uint32 PeriodMaxValue = (uint32)0U;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = 
                      (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
#else
    (void)Period;
    (void)ChannelNumber;
#endif

    if (PWM_VARIABLE_PERIOD == ChannelClass)
    {
#if (PWM_MAX_PERIOD_PLAUSABILITY == STD_ON)
        PeriodMaxValue = (uint32)Pwm_Drvw_GetMaxPeriodValue(DrvwChnCfgPtr);

        if ((uint32)Period > PeriodMaxValue)
        {
            PWM_E_PERIODVALUE_DET_REPORT_ERROR(ServiceId);

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Nothing */
        }
#endif /* PWM_MAX_PERIOD_PLAUSABILITY */
    }
    else
    {
        PWM_E_PERIOD_UNCHANGEABLE_DET_REPORT_ERROR(ServiceId);

        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}
#endif
 
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Check whether the notification callback function of the channel is empty.
*
* @param[in]    Callback        Notification callback function for PWM logic channel
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType  
* @retval       E_OK            Channel is in current partition
* @retval       E_NOT_OK        Channel is not current partition
*
*/
static Std_ReturnType Pwm_CheckNotificationCallback(Pwm_NotifyType Callback, uint8 ServiceId)
{
    Std_ReturnType RetVal;
    
    if (Callback == NULL_PTR)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        PWM_E_PARAM_NOTIFICATION_NULL_DET_REPORT_ERROR(ServiceId);
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    
    return RetVal;
}
    #endif /* PWM_NOTIFICATION_SUPPORTED */
#endif /* PWM_DEV_ERROR_DETECT */

/** @} end of group Private_FunctionDefinition */


/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
* @brief        Service for PWM initialization.
*
* @param[in]    ConfigPtr       Pointer to configuration set 
*
* @return       void
*/
void Pwm_Init(const Pwm_ConfigType * ConfigPtr)
{
    uint8  Index;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;
    Pwm_OutputStateType State;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType RetVal = Pwm_CheckInit(ConfigPtr, PWM_SID_INIT);
    if ((Std_ReturnType)E_OK == RetVal)
    {
#else
    #if (PWM_PRECOMPILE_SUPPORT == STD_ON)
        Pwm_ConfigPtr[CoreId] = Pwm_PreDefinedConfigPtr[CoreId];
        (void)ConfigPtr;
    #else
        Pwm_ConfigPtr[CoreId] = ConfigPtr;
    #endif
#endif

        for(Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumChannels; Index++)
        {
            DrvwChnCfgPtr = (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[Index].DrvwChannelCfg;
            State = (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[Index].ChannelIdleState;
            if(PWM_LOW == State)
            {
                Pwm_Drvw_InitIdleState(PWM_DRVW_LOW, DrvwChnCfgPtr);
            }
            else if (PWM_HIGH == State)
            {
                Pwm_Drvw_InitIdleState(PWM_DRVW_HIGH, DrvwChnCfgPtr);
            }
            else
            {
                /* Nothing to do */
            }
        }

        for (Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumModules; Index++)
        {
            Pwm_Drvw_Init(&((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[Index]));
        }

        for(Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumChannels; Index++)
        {
            DrvwChnCfgPtr = (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[Index].DrvwChannelCfg;
            Pwm_Drvw_SetDefaultDutyCycle(DrvwChnCfgPtr->ChannelDutyCycle, DrvwChnCfgPtr);
        }
        for(Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumModules; Index++)
        {
            Pwm_Drvw_SyncDefaultDutyCycle((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[Index].HwId,(*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[Index].HwType);
            Pwm_Drvw_StartInstance(&((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[Index]));
        }

#if (PWM_LOW_POWER_STATE_SUPPORTED == STD_ON)
        Pwm_DrvState[CoreId].PwmCurrentPowerState = PWM_FULL_POWER;
        Pwm_DrvState[CoreId].PwmTargetPowerState = PWM_NODEFINE_POWER;
#endif /* PWM_LOW_POWER_STATE_SUPPORTED */

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        Pwm_DrvState[CoreId].PwmGlobalState = PWM_STATE_IDLE;
    }
#endif
}

#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        Service for PWM De-Initialization.
*
* @param[in]    None
*
* @return       void
*/
void Pwm_DeInit(void)
{
    uint8  Index;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
        PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_DEINIT);
    }
    else
    {
        RetVal = Pwm_CheckPwmCfgStruct(PWM_SID_DEINIT);
        if ((Std_ReturnType)E_OK == RetVal)
        {
#endif
            /* Deinitialize all logic channels */
            for(Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumChannels; Index++)
            {
                DrvwChnCfgPtr = (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[Index].DrvwChannelCfg;
          
                Pwm_Drvw_SetOutputToIdle(DrvwChnCfgPtr);
            }

            for (Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumModules; Index++)
            {
                Pwm_Drvw_DeInit(&((*Pwm_ConfigPtr[CoreId]->PwmHwConfig)[Index]));
            }

            Pwm_ConfigPtr[CoreId] = NULL_PTR;

#if (PWM_LOW_POWER_STATE_SUPPORTED == STD_ON)
            /* Reset Power State */
            Pwm_DrvState[CoreId].PwmCurrentPowerState = PWM_NODEFINE_POWER;
            Pwm_DrvState[CoreId].PwmTargetPowerState = PWM_NODEFINE_POWER;
#endif /* PWM_LOW_POWER_STATE_SUPPORTED */

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            Pwm_DrvState[CoreId].PwmGlobalState = PWM_STATE_UNINIT;
        }
    }
#endif
}
#endif /* PWM_DE_INIT_API */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        Service sets the duty cycle of the PWM channel.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
* @param[in]    DutyCycle       Min=0x0000 Max=0x8000
*
* @return       void
*/
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_SET_DUTYCYCLE);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
        if (DutyCycle <= PWM_DUTY_CYCLE_100)
        {
#endif
            DrvwChnCfgPtr = 
                (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
            RetVal = Pwm_Drvw_SetDutyCycle(DutyCycle, DrvwChnCfgPtr);
            (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            if ((Std_ReturnType)E_OK != RetVal)
            {
                PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_SET_DUTYCYCLE);
            }
        }
        else
        {
            PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_SET_DUTYCYCLE);
        }
    }
#endif
}
#endif /* PWM_SET_DUTY_CYCLE_API */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        Service sets the period and the duty cycle of a PWM channel
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
* @param[in]    Period          Period of the PWM signal
* @param[in]    DutyCycle       Min=0x0000 Max=0x8000
*
* @return       void
*/
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                        uint16 DutyCycle)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_SET_PERIODANDDUTY);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
        if ((Std_ReturnType)E_OK == Pwm_CheckParamsPeriodClass(ChannelNumber, \
                        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].PwmChnClass, \
                        Period,PWM_SID_SET_PERIODANDDUTY))
        {
            if (DutyCycle <= PWM_DUTY_CYCLE_100)
            {
#endif
                DrvwChnCfgPtr = \
                (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
                
                RetVal = Pwm_Drvw_SetPeriodAndDuty(Period, DutyCycle, DrvwChnCfgPtr);
                (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
                if ((Std_ReturnType)E_OK != RetVal)
                {
                    PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_SET_PERIODANDDUTY);
                }
            }
            else
            {
                PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_SET_PERIODANDDUTY);
            }
        }
    }
#endif
}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        Service sets the PWM output to the configured Idle state.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
*
* @return       void
*
*/
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_SET_OUTPUTTOIDLE);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif

        DrvwChnCfgPtr = \
        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
        
        Pwm_Drvw_SetOutputToIdle(DrvwChnCfgPtr);
        
        (void)RetVal;
            
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        Service to read the internal state of the PWM output signal.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
*
* @return       Pwm_OutputStateType
*                 - PWM_LOW              The PWM output state is low
*                 - PWM_HIGH             The PWM output state is high
*/
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{
    Std_ReturnType  CheckRetVal = (Std_ReturnType)E_OK;
    Pwm_OutputStateType RetVal = PWM_LOW;
    uint32 CoreId = Pwm_GetCoreID();
    
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = \
    (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CheckRetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_GET_OUTPUTSTATE);
    
    if ((Std_ReturnType)E_OK == CheckRetVal)
    {
#endif
        if(PWM_DRVW_HIGH == Pwm_Drvw_GetOutputState(DrvwChnCfgPtr))
        {
            RetVal = PWM_HIGH;
        }
        else
        {
            RetVal = PWM_LOW;
        }
        
        (void)CheckRetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return RetVal;
}
#endif /* PWM_GET_OUTPUT_STATE_API */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Service to disable the PWM signal edge notification.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
*
* @return       void
*/
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = \
    (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
      
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_DISABLE_NOTIFICATION);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        Pwm_Drvw_DisableNotification(DrvwChnCfgPtr);
        
        (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
* @brief        Service to enable the PWM signal edge notification according to notification 
*               parameter.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
* @param[in]    Notification    Type of notification
*                 - PWM_RISING_EDGE
*                 - PWM_FALLING_EDGE
*                 - PWM_BOTH_EDGES
*
* @return       void
*/
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    Pwm_Drvw_EdgeNotificationType PwmDrvwNotification = PWM_DRVW_RISING_EDGE;
    uint32 CoreId = Pwm_GetCoreID();
    
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = \
    (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;

    if(PWM_RISING_EDGE == Notification)
    {
        PwmDrvwNotification = PWM_DRVW_RISING_EDGE;
    }
    else if(PWM_FALLING_EDGE == Notification)
    {
        PwmDrvwNotification = PWM_DRVW_FALLING_EDGE;
    }
    else
    {
        PwmDrvwNotification = PWM_DRVW_BOTH_EDGE;
    }
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_ENABLE_NOTIFICATION);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
        RetVal = Pwm_CheckNotificationCallback(
        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].PwmChannelNotificationPtr, \
                                                                PWM_SID_ENABLE_NOTIFICATION);
        if((Std_ReturnType)E_OK == RetVal)
        {
            RetVal = Pwm_Drvw_CheckEdgeNotificationType(PwmDrvwNotification,DrvwChnCfgPtr);
            if ((Std_ReturnType)E_OK != RetVal)
            {
                PWM_E_PARAM_NOTIFICATION_DET_REPORT_ERROR(PWM_SID_ENABLE_NOTIFICATION);
            }
            else
            {
#endif
                Pwm_Drvw_EnableNotification(PwmDrvwNotification,DrvwChnCfgPtr);
                
                (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif
}
#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_VERSION_INFO_API == STD_ON)
/**
* @brief        Service returns the version information of this module.
*
* @param[out]   versioninfo     Pointer to where to store the version information of this module.
*
* @return       void
*/
void Pwm_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        PWM_E_PARAM_POINTER_DET_REPORT_ERROR(PWM_SID_GET_VERSIONINFO);
    }
    else
#endif
    {
        (versioninfo)->vendorID         = (uint16)PWM_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)PWM_INSTANCE_ID;

        (versioninfo)->sw_major_version = (uint8)PWM_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)PWM_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)PWM_SW_PATCH_VERSION;
    }
}
#endif /* PWM_VERSION_INFO_API */

#if (PWM_GET_CHANNEL_DUTYCYCLE_API == STD_ON)
/**
* @brief        This function is used to get current duty cycle of the channel, When the channel
*               status is running.
* @details      The current duty cycle is obtained, and the previous setting value must take effect.
*               The high and low levels of the duty cycle are determined by the PWM polarity of the
*               channel.
*
* @param[in]    ChannelNumber   Pwm logic channel id
*
* @return       uint16          DutyCycle of the specified logic channel
*/
uint16 Pwm_GetChannelDutyCycle(Pwm_ChannelType ChannelNumber)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint16 DutyCycle = (uint16)0U;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_GET_CHANNEL_DUTYCYCLE);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        DrvwChnCfgPtr = \
        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
        DutyCycle = Pwm_Drvw_GetChannelDutyCycle(DrvwChnCfgPtr);
        
        (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    if(DutyCycle > PWM_DUTY_CYCLE_100)
    {
        PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_GET_CHANNEL_DUTYCYCLE);
    }
#endif

    return DutyCycle;
}
#endif /* PWM_GET_CHANNEL_DUTYCYCLE_API */

#if (PWM_FORCE_OUTPUT_TO_LOW_LEVEL_API == STD_ON)
/**
* @brief        This function is used to enable or disable the forcing of the output of a given
*               channel to logic 0.
*
* @param[in]    ChannelNumber   Pwm logic channel id
* @param[in]    ForceEnable     If the output of the channel will be forced to zero logic or not
* @return       void
*/
void Pwm_ForceOutputToLowLevel(Pwm_ChannelType ChannelNumber, boolean ForceEnable)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = \
    (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber, PWM_SID_FORCE_OUTPUT_TOLOWLEVEL);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        Pwm_Drvw_ForceOutputToLowLevel(ForceEnable,DrvwChnCfgPtr);
        
        (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* PWM_FORCE_OUTPUT_TO_LOW_LEVEL_API */

#if (PWM_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON)
/**
* @brief        This function is used to set the deadtime ticks for Pwm logic channel specified
*
* @param[in]    ChannelNumber       Pwm logic channel id
* @param[in]    DeadTimeTicks       Dead Time ticks
*
* @return       void
*/
void Pwm_SetChannelDeadTimeTicks(Pwm_ChannelType ChannelNumber, uint16 DeadTimeTicks)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = 
          (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;

#if (PWM_DEV_ERROR_DETECT == STD_ON) 
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_SET_CHANNELDEADTIME);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
        RetVal = Pwm_Drvw_CheckDeadTimeMode(DrvwChnCfgPtr);

        if ((Std_ReturnType)E_OK != RetVal)
        {
            PWM_E_PARAM_CHANNEL_DET_REPORT_ERROR(PWM_SID_SET_CHANNELDEADTIME);
        }
        else 
        {
#endif
            RetVal = Pwm_Drvw_SetChannelDeadTimeTicks(DeadTimeTicks, \
                (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg);
            (void)RetVal;
            (void)DrvwChnCfgPtr;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            if((Std_ReturnType)E_OK != RetVal)
            {
                (void)Det_ReportRuntimeError((uint16)PWM_INSTANCE_ID,(uint8)PWM_INDEX, \
                                (uint8)PWM_SID_SET_CHANNELDEADTIME,(uint8)PWM_E_DEADTIME_RANGE);
            }
        }
    }
#endif
}
#endif /* PWM_SET_CHANNEL_DEAD_TIME_TICKS_API */

#if (PWM_SYNC_UPDATE_API == STD_ON)
    #if (PWM_WRITE_DUTY_CYCLE_TO_BUFFER_API == STD_ON)
/**
* @brief        This function set the duty cycle value to the shadow registers of Pwm physical module,
*               and they will not active right now but trigged by a sync signal.
* @details      Generating synchronization signals by using Pwm_SyncUpdate function.
*               This function should not be mixed Pwm_SetDutyCycle and Pwm_SetPeriodAndDuty.
*
* @param[in]    ChannelNumber       Pwm logic channel id
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*/
void Pwm_WriteDutyCycleToBuffer(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;
    
#if (PWM_DEV_ERROR_DETECT == STD_ON)  
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber,PWM_SID_WRITER_DUTYCYCLE_TOBUFFER);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        DrvwChnCfgPtr = \
        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (DutyCycle <= PWM_DUTY_CYCLE_100)
        {
#endif
            RetVal = Pwm_Drvw_WriteDutyCycleToBuffer(DutyCycle, DrvwChnCfgPtr);
            (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            if ((Std_ReturnType)E_OK != RetVal)
            {
                PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_WRITER_DUTYCYCLE_TOBUFFER);
            }
        }
        else
        {
            PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_WRITER_DUTYCYCLE_TOBUFFER);
        }
    }
#endif
}
    #endif /* PWM_WRITE_DUTY_CYCLE_TO_BUFFER_API */

    #if (PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API == STD_ON)
/**
* @brief        This function set the period and duty cycle value to the shadow registers of Pwm 
*               physical module, and they will not active right now but trigged by a sync signal
* @details      Generating synchronization signals by using Pwm_SyncUpdate function.
*               This function should not be mixed Pwm_SetDutyCycle and Pwm_SetPeriodAndDuty.
*
* @param[in]    ChannelNumber    Pwm logic channel id
* @param[in]    Period           Pwm Period value
* @param[in]    DutyCycle        Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*/
void Pwm_WritePeriodAndDutyToBuffer(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                                    uint16 DutyCycle)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber, PWM_SID_WRITER_PERIODANDDUTY_TOBUFFER);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        DrvwChnCfgPtr = \
        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
        
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if ((Std_ReturnType)E_OK  == Pwm_CheckParamsPeriodClass( ChannelNumber, \
                    (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].PwmChnClass, \
                    Period, PWM_SID_WRITER_PERIODANDDUTY_TOBUFFER))
        {
            if (DutyCycle > PWM_DUTY_CYCLE_100)
            {
                PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_WRITER_PERIODANDDUTY_TOBUFFER);
            }
            else
            {
#endif
                RetVal = Pwm_Drvw_WritePeriodAndDutyToBuffer(Period, DutyCycle, DrvwChnCfgPtr);
                (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
                if ((Std_ReturnType)E_OK != RetVal)
                {
                    PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_WRITER_PERIODANDDUTY_TOBUFFER);
                }
            }
        }
    }
#endif
}
    #endif /* PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API */

    #if (PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON)
/**
* @brief        This function is used to set the phase shift scale and force the duty cycle to 50%.
*               Set the values to the shadow registers of the Pwm physical module, and they will now
*               be inactive and triggered by a synchronization signal.
* @details      Generating synchronization signals by using Pwm_SyncUpdate function.
*               This function should not be mixed Pwm_SetDutyCycle and Pwm_SetPeriodAndDuty.
*
* @param[in]    ChannelNumber        Pwm logic channel Id specified
* @param[in]    Period               Pwm period value
* @param[in]    PhaseShiftTicks      Phase shift ticks
*
* @return       void
*
*/
void Pwm_WritePhaseShiftTicksToBuffer(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                                    uint16 PhaseShiftTicks)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber, PWM_SID_WRITER_PHASESHIFT_TOBUFFER);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
        if ((Std_ReturnType)E_OK  == Pwm_CheckParamsPeriodClass(ChannelNumber, \
                        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].PwmChnClass, \
                        Period,PWM_SID_WRITER_PHASESHIFT_TOBUFFER))
        {
            if ((PhaseShiftTicks > (Period / 2U)) || (PhaseShiftTicks == 0U))
            {
                PWM_E_PARAM_PHASESHIFT_RANGE_DET_REPORT_ERROR(PWM_SID_WRITER_PHASESHIFT_TOBUFFER);
            }
            else
#endif
            {
                Pwm_Drvw_WritePhaseShiftTicksToBuffer(Period, PhaseShiftTicks, 
                (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg);
                
                (void)RetVal;

            }
#if (PWM_DEV_ERROR_DETECT == STD_ON) 
        }
    }
#endif
}
    #endif /* PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API */

/**
* @brief        This function can generate a synchronization signal to update the shadow register
*               synchronized by the physical pwm module.
* @details      The update is not immediate, but at the end of the period
*
* @param[in]    ModuleId      PWM HW module ID.
*
* @return       void
*/
void Pwm_SyncUpdate(uint8 ModuleId)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
        PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_SYNCUPDATE);
    }
    else
    {
        if (PWM_HW_MODULE_NO_USED > ModuleId)
        {
            RetVal = Pwm_CheckModuleCfgStruct(ModuleId, PWM_SID_SYNCUPDATE);
            if((Std_ReturnType)E_OK == RetVal)
            {
#endif
                Pwm_Drvw_SyncUpdate(&((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[ModuleId]));
                (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            }
        }
        else
        {
            PWM_E_PARAM_INSTANCE_DET_REPORT_ERROR(PWM_SID_SYNCUPDATE);
        }
    }
#endif
}
#endif /* PWM_SYNC_UPDATE_API */

#if (PWM_SET_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function is used to set phase shift ticks and also force duty cycle to 50%
*
* @param[in]    ChannelNumber           Pwm logic channel Id in the configuration
* @param[in]    Period                  Pwm period value
* @param[in]    PhaseShiftTicks         Phase shift ticks 
*
* @return       void
*/
void Pwm_SetPhaseShiftTicks(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                        uint16 PhaseShiftTicks)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

#if (PWM_DEV_ERROR_DETECT == STD_ON)  
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber, PWM_SID_SET_PHASESHIFT);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
        if ((Std_ReturnType)E_OK  == Pwm_CheckParamsPeriodClass(ChannelNumber, \
                        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].PwmChnClass, \
                        Period,PWM_SID_SET_PHASESHIFT))
        {
            if ((PhaseShiftTicks > (Period / 2U)) || (PhaseShiftTicks == 0U))
            {
                PWM_E_PARAM_PHASESHIFT_RANGE_DET_REPORT_ERROR(PWM_SID_SET_PHASESHIFT);
            }
            else
#endif
            {
                 Pwm_Drvw_SetPhaseShiftTicks(Period, PhaseShiftTicks,
                (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg);               
                
                (void)RetVal;
            }
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}
#endif /* PWM_SET_PHASE_SHIFT_TICKS_API */

#if (PWM_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function is used to set phase shift and duty cycle value, and specify update or not.
*
* @param[in]    ChannelNumber           Pwm logic channel Id in the configuration
* @param[in]    DutyCycle               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShiftTicks         Phase shift ticks
* @param[in]    boolean                 SyncUpdate
*                                        - TRUE    Update settings at the end of the period
*                                        - FALSE   Update is triggered by a synchronization signal
*                                                  by using the function Pwm_SyncUpdate
*
* @return       void
*/
void Pwm_SetDutyPhaseShiftTicks(Pwm_ChannelType ChannelNumber, uint16 DutyCycle,
                                uint16 PhaseShiftTicks, boolean SyncUpdate)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    const Pwm_Drvw_ChannelConfigType * DrvwChnCfgPtr = NULL_PTR;

#if (PWM_DEV_ERROR_DETECT == STD_ON)  
    RetVal = Pwm_CheckHwAndChannel(ChannelNumber, PWM_SID_SET_DUTYPHASESHIFT);
    
    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        DrvwChnCfgPtr = \
        (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[ChannelNumber].DrvwChannelCfg;
                 
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (DutyCycle <= PWM_DUTY_CYCLE_100)
        {
            RetVal = Pwm_Drvw_CheckSetDutyPhaseShiftParams(PhaseShiftTicks,DutyCycle,
                                                           DrvwChnCfgPtr);

            if((Std_ReturnType)E_OK != RetVal)
            {
                PWM_E_PARAM_PHASESHIFT_RANGE_DET_REPORT_ERROR(PWM_SID_SET_DUTYPHASESHIFT);
            }
            else
            {
#endif
                Pwm_Drvw_SetDutyPhaseShiftTicks(DutyCycle,PhaseShiftTicks,DrvwChnCfgPtr, 
                                                SyncUpdate);
                
                (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            }
        }
        else
        {
            PWM_E_DUTYCYCLE_RANGE_DET_REPORT_ERROR(PWM_SID_SET_DUTYPHASESHIFT);
        }
    }
#endif
}
#endif /* PWM_SET_DUTY_AND_PHASE_SHIFT_TICKS_API */

#if (PWM_ENABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function is used to enable trigger generation for source specified
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    TriggerMask   Bit mask will be set to enable trigger with corresponding sources.
*
* @return       void
*
*/
void Pwm_EnableTriggerOutput(uint8 ModuleId, uint16 TriggerMask)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

#if (PWM_DEV_ERROR_DETECT == STD_ON)

    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
        PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_ENABLE_TRIGGER);
    }
    else
    {
        if (PWM_HW_MODULE_NO_USED > ModuleId)
        {
            RetVal = Pwm_CheckModuleCfgStruct(ModuleId, PWM_SID_ENABLE_TRIGGER);
            if((Std_ReturnType)E_OK == RetVal)
            {
                if ((TriggerMask & ((uint32)(0x1FF))) != 0U)
                {
#endif
                    Pwm_Drvw_EnableTriggerOutput(TriggerMask, \
                                     &((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[ModuleId]));
                    (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
                }
                else
                {
                    PWM_E_TRIGGER_MASK_DET_REPORT_ERROR(PWM_SID_ENABLE_TRIGGER);
                }
            }
        }
        else
        {
            PWM_E_PARAM_INSTANCE_DET_REPORT_ERROR(PWM_SID_ENABLE_TRIGGER);
        }
    }
#endif
}
#endif /* PWM_ENABLE_TRIGGER_OUTPUT_API */

#if (PWM_DISABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function is used to disable trigger generation for specific source
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    TriggerMask   Bit mask will be cleared to disable trigger with corresponding sources.
*
* @return       void
*/
void Pwm_DisableTriggerOutput(uint8 ModuleId, uint16 TriggerMask)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

#if (PWM_DEV_ERROR_DETECT == STD_ON)

    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
        PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_DISABLE_TRIGGER);
    }
    else
    {
        if (PWM_HW_MODULE_NO_USED > ModuleId)
        {
            RetVal = Pwm_CheckModuleCfgStruct(ModuleId, PWM_SID_DISABLE_TRIGGER);
            if((Std_ReturnType)E_OK == RetVal)
            {
                if ((TriggerMask & ((uint32)(0x1FF))) != 0U)
                {
#endif
                    Pwm_Drvw_DisableTriggerOutput(TriggerMask,
                                     &((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[ModuleId]));
                    (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
                }
                else
                {
                    PWM_E_TRIGGER_MASK_DET_REPORT_ERROR(PWM_SID_DISABLE_TRIGGER);
                }
            }
        }
        else
        {
            PWM_E_PARAM_INSTANCE_DET_REPORT_ERROR(PWM_SID_DISABLE_TRIGGER);
        }
    }
#endif
}
#endif /* PWM_DISABLE_TRIGGER_OUTPUT_API */

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function is used to force channels output to their inactive state
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    ChannelMask   Bit mask will be set to inactive corresponding channels.
*
* @return       void
*/
void Pwm_MaskOutputs(uint8 ModuleId, uint8 ChannelMask)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
        PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_MASKOUTPUT);
    }
    else
    {
        if (PWM_HW_MODULE_NO_USED > ModuleId)
        {
            RetVal = Pwm_CheckModuleCfgStruct(ModuleId, PWM_SID_MASKOUTPUT);
            if((Std_ReturnType)E_OK == RetVal)
            {
#endif
                Pwm_Drvw_MaskOutputs(ChannelMask,
                                    &((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[ModuleId]));
                (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            }
        }
        else
        {
            PWM_E_PARAM_INSTANCE_DET_REPORT_ERROR(PWM_SID_MASKOUTPUT);
        }
    }
#endif
}

/**
* @brief        This function is to active channels output to normal operation state
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    ChannelMask   Bit mask will be cleared to active the output of corresponding channel.
*
* @return       void
*/
void Pwm_UnMaskOutputs(uint8 ModuleId, uint8 ChannelMask)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

#if (PWM_DEV_ERROR_DETECT == STD_ON)

    if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
    {
        PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_UNMASKOUTPUT);
    }
    else
    {
        if (PWM_HW_MODULE_NO_USED > ModuleId)
        {
            RetVal = Pwm_CheckModuleCfgStruct(ModuleId, PWM_SID_UNMASKOUTPUT);
            if((Std_ReturnType)E_OK == RetVal)
            {
#endif
                Pwm_Drvw_UnMaskOutputs(ChannelMask, \
                                     &((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[ModuleId]));
                (void)RetVal;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
            }
        }
        else
        {
            PWM_E_PARAM_INSTANCE_DET_REPORT_ERROR(PWM_SID_UNMASKOUTPUT);
        }
    }
#endif
}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

#if (PWM_LOW_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        This API configures the Pwm module so that it enters the already prepared power 
*               state, chosen between a predefined set of configured ones.
*
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED   Power state change executed.
*                 - PWM_NOT_INIT           PWM Module not initialized.
*                 - PWM_SEQUENCE_ERROR     wrong API call sequence.
*                 - PWM_HW_FAILURE         the HW module has a failure which prevents it to enter
*                                          the required power state.
*
* @return       Std_ReturnType
*                 - E_OK                   Mode changed
*                 - E_NOT_OK               request rejected
*
*/
Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();
    uint8 Index;

    Pwm_Drvw_PowerStateType PwmDrvwPowerState =
                                (Pwm_Drvw_PowerStateType)Pwm_DrvState[CoreId].PwmTargetPowerState;

    if (NULL_PTR != Result)
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        RetVal = Pwm_CheckSetPowerState(Result, PWM_SID_SET_POWERSTATE);
        if((Std_ReturnType)E_OK == RetVal)
        {
#endif
            if (Pwm_DrvState[CoreId].PwmCurrentPowerState == \
                                              Pwm_DrvState[CoreId].PwmTargetPowerState)
            {
                *Result = PWM_SERVICE_ACCEPTED;
            }
            else
            {
                switch(Pwm_DrvState[CoreId].PwmTargetPowerState)
                {
                    case PWM_NODEFINE_POWER:
                        *Result = PWM_SEQUENCE_ERROR;
                        RetVal = (Std_ReturnType)E_NOT_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
                        PWM_E_PERIPHERAL_NOT_PREPARED_DET_REPORT_ERROR(PWM_SID_SET_POWERSTATE);
#endif
                        break;
                    case PWM_LOW_POWER:
                    case PWM_FULL_POWER:
                        for(Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumChannels; Index++)
                        {
                            RetVal = Pwm_Drvw_CheckIdleState(
                               (*(Pwm_ConfigPtr[CoreId]->PwmChannelConfigs))[Index].DrvwChannelCfg);

                            if (RetVal == (Std_ReturnType)E_NOT_OK)
                            {
                                break;
                            }
                        }

                        if((Std_ReturnType)E_OK == RetVal)
                        {
                            for (Index = 0; Index < Pwm_ConfigPtr[CoreId]->NumModules; Index++)
                            {
                                Pwm_Drvw_SetPowerState(
                                    &((*(Pwm_ConfigPtr[CoreId]->PwmHwConfig))[Index]), 
                                    PwmDrvwPowerState);
                            }
                            *Result = PWM_SERVICE_ACCEPTED;
                            Pwm_DrvState[CoreId].PwmCurrentPowerState = \
                            Pwm_DrvState[CoreId].PwmTargetPowerState;
                            Pwm_DrvState[CoreId].PwmTargetPowerState = PWM_NODEFINE_POWER;
                        }
                        else
                        {
                            *Result = PWM_HW_FAILURE;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
                            (void)Det_ReportRuntimeError((uint16)PWM_INSTANCE_ID,(uint8)PWM_INDEX,
                                (uint8)PWM_SID_SET_POWERSTATE,(uint8)PWM_E_NOT_DISENGAGED);
#endif
                        }
                        break;
                    default:
                        *Result = PWM_POWER_STATE_NOT_SUPP;
                        RetVal = (Std_ReturnType)E_NOT_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
                        PWM_E_POWER_STATE_NOT_SUPPORTED_DET_REPORT_ERROR(PWM_SID_SET_POWERSTATE);
#endif
                        break;
                }   
            }
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    }
    else
    {      
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        PWM_E_PARAM_POINTER_DET_REPORT_ERROR(PWM_SID_SET_POWERSTATE);
#endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    
    return RetVal;
}

/**
* @brief        This API returns the current power state of the PWM HW unit.
*
* @param[out]   CurrentPowerState    The current power mode of the PWM HW Unit is returned in 
*                                    this parameter
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED   Current power mode was returned.
*                 - PWM_NOT_INIT           PWM Module not initialized.
*
* @return       Std_ReturnType
*                 - E_OK                   Mode could be read
*                 - E_NOT_OK               Service is rejected
*
*/
Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType * CurrentPowerState,
                                        Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

    if ((NULL_PTR != Result) && (NULL_PTR != CurrentPowerState))
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)

        if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
        {
            PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_GET_CURRENTPOWERSTATE);
            *Result = PWM_NOT_INIT;
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
#endif
            *CurrentPowerState =  Pwm_DrvState[CoreId].PwmCurrentPowerState;
            *Result = PWM_SERVICE_ACCEPTED;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        PWM_E_PARAM_POINTER_DET_REPORT_ERROR(PWM_SID_GET_CURRENTPOWERSTATE);
#endif
    }

    return RetVal;
}

/**
* @brief        This API returns the Target power state of the PWM HW unit.
*
* @param[out]   TargetPowerState     The Target power mode of the PWM HW Unit is returned in this 
*                                    parameter
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED   Target power mode was returned.
*                 - PWM_NOT_INIT           PWM Module not initialized.
*
* @return       Std_ReturnType
*                 - E_OK                   Mode could be read
*                 - E_NOT_OK               Service is rejected
*
*/
Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType * TargetPowerState,
                                       Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

    if ((NULL_PTR != Result) && (NULL_PTR != TargetPowerState))
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        
        if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
        {
            PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_GET_TARGETPOWERSTATE);
            *Result = PWM_NOT_INIT;
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
#endif
            *TargetPowerState = Pwm_DrvState[CoreId].PwmTargetPowerState;
            *Result = PWM_SERVICE_ACCEPTED;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        PWM_E_PARAM_POINTER_DET_REPORT_ERROR(PWM_SID_GET_TARGETPOWERSTATE);
#endif
    }

    return RetVal;
}

/**
* @brief        This API starts the needed process to allow the PWM HW module to enter the 
*               requested power state.
*
* @param[in]    PowerState      The target power state intended to be attained
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED      PWM Module power state preparation was started.
*                 - PWM_NOT_INIT              PWM Module not initialized.
*                 - PWM_SEQUENCE_ERROR        wrong API call sequence (Current Power State = Target 
*                                             Power State).
*                 - PWM_POWER_STATE_NOT_SUPP  PWM Module does not support the requested power state.
*                 - PWM_TRANS_NOT_POSSIBLE    PWM Module cannot transition directly from the current
*                                             power state to the requested power state or the HW 
*                                             peripheral is still busy.
*
* @return       Std_ReturnType
*                 - E_OK                      Preparation process started
*                 - E_NOT_OK                  Service is rejected
*
*/
Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType PowerState,
                                     Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 CoreId = Pwm_GetCoreID();

    if (NULL_PTR != Result)
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        
        if (PWM_STATE_UNINIT == Pwm_DrvState[CoreId].PwmGlobalState)
        {
            PWM_E_UNINIT_DET_REPORT_ERROR(PWM_SID_PREPARE_POWERSTATE);
            *Result = PWM_NOT_INIT;
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
#endif
            if ( Pwm_DrvState[CoreId].PwmCurrentPowerState != PowerState)
            {
                if ((PWM_LOW_POWER != PowerState) && (PWM_FULL_POWER != PowerState))
                {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
                    PWM_E_POWER_STATE_NOT_SUPPORTED_DET_REPORT_ERROR(PWM_SID_PREPARE_POWERSTATE);
#endif
                    *Result = PWM_POWER_STATE_NOT_SUPP;
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    *Result = PWM_SERVICE_ACCEPTED;
                    Pwm_DrvState[CoreId].PwmTargetPowerState = PowerState;
                }
            }
            else
            {
                *Result = PWM_SEQUENCE_ERROR;
                RetVal = (Std_ReturnType)E_NOT_OK;
            }

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
        PWM_E_PARAM_POINTER_DET_REPORT_ERROR(PWM_SID_PREPARE_POWERSTATE);
#endif
    }

    return RetVal;
}
#endif /* PWM_LOW_POWER_STATE_SUPPORTED */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Pwm */

/** @} end of group Pwm_Module */
