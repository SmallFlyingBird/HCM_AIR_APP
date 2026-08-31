/**
 * @file    Pwm.c
 * @version V2.3.0
 *
 * @brief   AUTOSAR Pwm module interface
 * @details API implementation for Pwm driver
 *
 * @addtogroup PWM_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR, MPWM
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm.h"
#include "Pwm_Mld.h"
#if (PWM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID_C                      (180)
#define PWM_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PWM_AR_RELEASE_MINOR_VERSION_C       (4)
#define PWM_AR_RELEASE_REVISION_VERSION_C    (0)
#define PWM_SW_MAJOR_VERSION_C               (2)
#define PWM_SW_MINOR_VERSION_C               (3)
#define PWM_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm.c and Pwm.h are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_VENDOR_ID)
#error "Pwm.c and Pwm.h have different vendor ids"
#endif

/* Check if Pwm.c and Pwm.h are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm.c and Pwm.h are different"
#endif

/* Check if Pwm.c and Pwm.h are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm.c and Pwm.h are different"
#endif

/* Check if Pwm.c and Pwm_Mld.h are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_MLD_VENDOR_ID)
#error "Pwm.c and Pwm_Mld.h have different vendor ids"
#endif

/* Check if Pwm.c and Pwm_Mld.h are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C != PWM_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C != PWM_MLD_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_MLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm.c and Pwm_Mld.h are different"
#endif

/* Check if Pwm.c and Pwm_Mld.h are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_MLD_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION_C != PWM_MLD_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION_C != PWM_MLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm.c and Pwm_Mld.h are different"
#endif

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/
#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief   Pwm driver configuration structure */
PWM_CONST extern const Pwm_ConfigType Pwm_Config;

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif

/*==================================================================================================
 *                                       LOCAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief   Pwm driver state structure */
PWM_VAR static Pwm_DriverStateType Pwm_DriverState;

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if (PWM_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief       Validate the call of a function impacting the configuration of the entire driver.
 * @details     Before executing, a function which changes the configuration of the entire driver
 *              shall check if:
 *              1. It is not preempting itself
 *              2. It is not preempting another function that changes the configuration of the
 *                 entire driver
 *              3. It is not preempting a function that changes the configuration of one of the
 *                 driver's channels
 *              In any of the above cases, the function will report an error to Det or Serr,
 *              depending on the environment the driver is run in.
 * @param[in]   ServiceId Id of the service calling this function
 * @return      Std_ReturnType
 * @retval      E_OK Caller of the function can continue its execution
 * @retval      E_NOT_OK Caller of the function should drop execution
 */
PWM_FUNC static Std_ReturnType Pwm_ValidateGlobalConfigCall(uint8 ServiceId)
{
    Std_ReturnType Ret = E_OK;

    if (PWM_UNINIT == Pwm_DriverState.State)
    {
        if (PWM_SID_INIT != ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16)PWM_MODULE_ID,
                (uint8)PWM_INDEX,
                ServiceId,
                (uint8)PWM_E_UNINIT
            );
            Ret = E_NOT_OK;
        }
    }
    else
    {
        if (PWM_SID_INIT == ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16)PWM_MODULE_ID,
                (uint8)PWM_INDEX,
                ServiceId,
                (uint8)PWM_E_ALREADY_INITIALIZED
            );
            Ret = E_NOT_OK;
        }
    }

    return Ret;
}

/**
 * @brief       Completes the execution of a function impacting the configuration of the entire driver.
 * @details     Performs actions in order to ensure that after it's caller has completed the execution
 *              the driver will remain in a state allowing execution of other functions updating the
 *              configuration of the entire driver or of a single channel
 * @param[in]   ValidCall The function call was previously validated
 * @param[in]   ServiceId The service id of the caller function
 * @return      void
 */
PWM_FUNC static void Pwm_EndValidateGlobalConfigCall(Std_ReturnType ValidCall, uint8 ServiceId)
{
    /* Change the state of the driver only if the previous call to
    Pwm_ValidateGlobalConfigCall() stated that the API call is valid */
    if (E_OK == ValidCall)
    {
        if (PWM_SID_DEINIT == ServiceId)
        {
            Pwm_DriverState.State = PWM_UNINIT;
        }
        else
        {
            Pwm_DriverState.State = PWM_IDLE;
        }
    }
}

/**
 * @brief       Validate the configuration parameter of the Pwm_Init API. In case an
 *              error is detected, the function will report an error to Det or Serr,
 *              depending on the environment the driver is run in.
 * @param[in]   ConfigPtr Pointer to the configuration of Pwm driver
 * @return      Std_ReturnType
 * @retval      E_OK Pointer is valid
 * @retval      E_NOT_OK Pointer is invalid
 */
PWM_FUNC static Std_ReturnType Pwm_ValidateParamPtrInit(const Pwm_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = E_OK;

#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
    /* For pre-compile, check DET error if the received config pointer is not NULL_PTR */
    if (NULL_PTR != ConfigPtr)
#else
    /* For post build, check DET error if the received config pointer is NULL_PTR */
    if (NULL_PTR == ConfigPtr)
#endif
    {
        (void)Det_ReportError
        (
            (uint16)PWM_MODULE_ID,
            (uint8)PWM_INDEX,
            (uint8)PWM_SID_INIT,
            (uint8)PWM_E_INIT_FAILED
        );
        Ret = E_NOT_OK;
    }

    return Ret;
}

#if ((PWM_SET_DUTY_CYCLE == STD_ON) ||\
     (PWM_SET_PERIOD_AND_DUTY == STD_ON) ||\
     (PWM_SET_OUTPUT_TO_IDLE == STD_ON) ||\
     (PWM_GET_OUTPUT_STATE == STD_ON))
/**
 * @brief       Validate the call of a function impacting the configuration of one of the driver's
 * @details     channels. Before executing, a function which changes the configuration of a
 *              channel shall check if:
 *              1. It is not preempting itself
 *              2. It is not preempting a function that changes the configuration of the
 *                 entire driver
 *              In any of the above cases, the function will report an error to Det or Serr,
 *              depending on the environment the driver is run in.
 * @param[in]   ChannelNumber  Id of the channel the caller tries to update
 * @param[in]   ServiceId Id of the service calling this function
 * @return      Std_ReturnType
 * @retval      E_OK Caller of the function can continue its execution
 * @retval      E_NOT_OK Caller of the function should drop execution
 */
PWM_FUNC static Std_ReturnType Pwm_ValidateChannelConfigCall(Pwm_ChannelType ChannelNumber, uint8 ServiceId)
{
    Std_ReturnType Ret = E_OK;

    /* Check if the driver is initialized */
    if (PWM_UNINIT == Pwm_DriverState.State)
    {
        /* Driver not initialized yet */
        (void)Det_ReportError
        (
            (uint16)PWM_MODULE_ID,
            (uint8)PWM_INDEX,
            ServiceId,
            (uint8)PWM_E_UNINIT
        );
        Ret = E_NOT_OK;
    }
    else
    {
        /* Check that the channel is in valid range */
        if (ChannelNumber >= PWM_LOGIC_CHANNEL_NUM)
        {
            (void)Det_ReportError
            (
                (uint16)PWM_MODULE_ID,
                (uint8)PWM_INDEX,
                ServiceId,
                (uint8)PWM_E_PARAM_CHANNEL
            );
            Ret = E_NOT_OK;
        }
    }

    return Ret;
}
#endif

#if (PWM_SET_DUTY_CYCLE == STD_ON) || (PWM_SET_PERIOD_AND_DUTY == STD_ON)
/**
 * @brief       Validate the DutyCycle parameter of the Pwm_SetDutyCycle API. In case an
 *              error is detected, the function will report it to Det or Serr,
 *              depending on the environment the driver is run in.
 * @param[in]   DutyCycle DutyCycle value to be validated
 * @param[in]   ServiceId Id of calling API
 * @return      Std_ReturnType
 * @retval      E_OK Duty Cycle is valid
 * @retval      E_NOT_OK Duty Cycle is invalid
 */
PWM_FUNC static Std_ReturnType Pwm_ValidateParamDuty(uint16 DutyCycle, uint8 ServiceId)
{
    Std_ReturnType Ret = E_OK;

    /* Check if the DutyCycle is in valid range */
    if (DutyCycle > PWM_DUTY_CYCLE_100)
    {
        (void)Det_ReportError
        (
            (uint16)PWM_MODULE_ID,
            (uint8)PWM_INDEX,
            ServiceId,
            (uint8)PWM_E_DUTYCYCLE_RANGE
        );
        Ret = E_NOT_OK;
    }

    return Ret;
}
#endif /* (PWM_SET_DUTY_CYCLE == STD_ON) || (PWM_SET_PERIOD_AND_DUTY == STD_ON) */

#if (PWM_SET_PERIOD_AND_DUTY == STD_ON)
/**
 * @brief       Validate the Period and channel class parameters for Pwm_SetPeriodAndDuty API.
 *              The Period is validated in the sense that it can be updated only for channels having
 *              Variable Period class. Also it may be possible (when hardware allows it)
 *              for the PWM period that would be written to hardware, to be constructed taking into
 *              consideration some initial value. In such case the total value (maximum value)
 *              should not exceed the maximum value supported by the hardware (0xFFFFU).
 *              In case any of the parameters is invalid, the function will report an error to
 *              DET or SERR, depending on the environment the driver is run in.
 * @param[in]   ChannelClass PWM channel class
 * @param[in]   ServiceId API service ID
 * @return      Std_ReturnType
 * @retval      E_OK Channel Class, Period are all valid
 * @retval      E_NOT_OK One of Channel Class, Period is invalid
 */
PWM_FUNC static Std_ReturnType Pwm_ValidateParamsPeriodClass
(
    Pwm_ChannelClassType ChannelClass,
    uint8 ServiceId
)
{
    Std_ReturnType Ret = E_OK;

    /* Check if channel supports updates of the period */
    if (PWM_VARIABLE_PERIOD != ChannelClass)
    {
        (void)Det_ReportError
        (
            (uint16)PWM_MODULE_ID,
            (uint8)PWM_INDEX,
            ServiceId,
            (uint8)PWM_E_PERIOD_UNCHANGEABLE
        );
        Ret = E_NOT_OK;
    }

    return Ret;
}
#endif /* PWM_SET_PERIOD_AND_DUTY == STD_ON */

#if (PWM_SET_OUTPUT_TO_IDLE == STD_ON)
/**
 * @brief       This function will check the validation when calling the Pwm_SetOutputToIdle api.
 * @param[in]   ChannelNumber The id of channel number
 * @return      Std_ReturnType
 * @retval      E_NOT_OK Set output to idle is not valid
 * @retval      E_OK Set output to idle is valid
 */
PWM_FUNC static Std_ReturnType Pwm_ValidateSetOutPutToIdle(Pwm_ChannelType ChannelNumber)
{
    Std_ReturnType Ret;

    Ret = Pwm_Mld_ValidateSetOutPutToIdle(&((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].MldChCfg));
    if (E_OK != Ret)
    {
        (void)Det_ReportError
        (
            (uint16)PWM_MODULE_ID,
            (uint8)PWM_INDEX,
            (uint8)PWM_SID_SET_OUTPUT_TO_IDLE,
            (uint8)PWM_E_SETOUTPUTTOIDLE_NOT_SUPPORTED
        );
    }

    return Ret;
}
#endif

#if (PWM_VERSION_INFO_API == STD_ON)
/**
 * @brief       Validates the pointer to the version info
 * @details     This function validates the pointer to the version info
 * @param[in]   VersionInfo Pointer to the version info
 * @return      Std_ReturnType
 * @retval      E_OK Pointer is valid
 * @retval      E_NOT_OK Pointer is not valid
 */
PWM_FUNC static Std_ReturnType Pwm_ValidatePtrVersion(const Std_VersionInfoType *VersionInfo)
{
    Std_ReturnType Ret = E_OK;

    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError
        (
            (uint16)PWM_MODULE_ID,
            (uint8)PWM_INDEX,
            (uint8)PWM_SID_GET_VERSION_INFO,
            (uint8)PWM_E_PARAM_POINTER
        );
        Ret = E_NOT_OK;
    }

    return Ret;
}
#endif

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        Validate the mode of current channel.
* @param[in]    ChannelNumber The Id of the given channel
* @return       Std_ReturnType
* @retval       E_OK The mode of current channel is valid
* @retval       E_NOT_OK The mode of current channel is not valid
*/
PWM_FUNC static Std_ReturnType Pwm_ValidateDeadTime(Pwm_ChannelType ChannelNumber)
{
    Std_ReturnType Ret;

    Ret = Pwm_Mld_ValidateDeadTime(&((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].MldChCfg));
    if (E_OK != Ret)
    {
        (void)Det_ReportError
        (
            (uint16)PWM_MODULE_ID,
            (uint8)PWM_INDEX,
            (uint8)PWM_SID_SET_CHANNEL_DEAD_TIME_ID,
            (uint8)PWM_E_PARAM_CHANNEL
        );
    }

    return Ret;
}
#endif
#endif /* PWM_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       Service for PWM initialization.
 * @param[in]   ConfigPtr Pointer to configuration set
 * @return      void
 */
PWM_FUNC void Pwm_Init(const Pwm_ConfigType *ConfigPtr)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType CallIsValid;
#endif
    uint8 Index;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PWM_SID_INIT);
    if (E_OK == CallIsValid)
    {
        CallIsValid = Pwm_ValidateParamPtrInit(ConfigPtr);
        if (E_OK == CallIsValid)
        {
#endif
#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
            /* Save configuration pointer in global variable */
            Pwm_DriverState.PwmConfig = &Pwm_Config;
            (void)ConfigPtr;
#else
            Pwm_DriverState.PwmConfig = ConfigPtr;
#endif
            /* MLD call to hw instance initialization when PWM controls the entire hw instance */
            for (Index = 0; Index < Pwm_DriverState.PwmConfig->InstanceCount; ++Index)
            {
                Pwm_Mld_InitInstance(&((*Pwm_DriverState.PwmConfig->PwmInstancesConfig)[Index]));
            }
            /* MLD call to hw channel initialization when PWM controls the entire hw channel */
            for (Index = 0; Index < Pwm_DriverState.PwmConfig->ChannelCount; ++Index)
            {
                Pwm_DriverState.PwmChannelConfigs[Index] = &((*Pwm_DriverState.PwmConfig->PwmChannelsConfig)[Index]);
                /* Continue to hw channel initialization */
                Pwm_Mld_InitChannel(&((*Pwm_DriverState.PwmConfig->PwmChannelsConfig)[Index].MldChCfg));
            }
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
    }
    Pwm_EndValidateGlobalConfigCall(CallIsValid, PWM_SID_INIT);
#endif
}

#if (PWM_DEINIT_API == STD_ON)
/**
 * @brief       Service for PWM De-Initialization.
 * @return      void
 */
PWM_FUNC void Pwm_DeInit(void)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType CallIsValid;
#endif
    uint8 Index;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PWM_SID_DEINIT);
    if (E_OK == CallIsValid)
    {
#endif
        /* MLD call to hw channel de-initialization */
        for (Index = 0; Index < Pwm_DriverState.PwmConfig->ChannelCount; ++Index)
        {
            Pwm_Mld_DeInitChannel(&((*Pwm_DriverState.PwmChannelConfigs)[Index].MldChCfg));
        }
        /* MLD call to hw instance de-initialization */
        for (Index = 0; Index < Pwm_DriverState.PwmConfig->InstanceCount; ++Index)
        {
            Pwm_Mld_DeInitInstance(&((*Pwm_DriverState.PwmConfig->PwmInstancesConfig)[Index]));
        }
        /* Set global configuration pointer back to NULL_PTR */
        Pwm_DriverState.PwmConfig = NULL_PTR;
        /* Set all channels config to NULL_PTR */
        for (Index = 0; Index < PWM_LOGIC_CHANNEL_NUM; ++Index)
        {
            Pwm_DriverState.PwmChannelConfigs[Index] = NULL_PTR;
        }
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    Pwm_EndValidateGlobalConfigCall(CallIsValid, PWM_SID_DEINIT);
#endif
}
#endif

#if (PWM_SET_DUTY_CYCLE == STD_ON)
/**
 * @brief       Service sets the duty cycle of the PWM channel.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @param[in]   DutyCycle 0x0000 for 0%, 0x8000 for 100%
 * @return      void
 */
PWM_FUNC void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType CallIsValid;
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CallIsValid = Pwm_ValidateChannelConfigCall(ChannelNumber, PWM_SID_SET_DUTY_CYCLE);
    if (E_OK == CallIsValid)
    {
        CallIsValid = Pwm_ValidateParamDuty(DutyCycle, PWM_SID_SET_DUTY_CYCLE);
        if (E_OK == CallIsValid)
        {
#endif
            /* MLD call to hw channel set duty cycle */
            Pwm_Mld_SetDutyCycle(DutyCycle, &((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].MldChCfg));
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}
#endif /* PWM_SET_DUTY_CYCLE == STD_ON */

#if (PWM_SET_PERIOD_AND_DUTY == STD_ON)
/**
 * @brief       Service sets the period and the duty cycle of a PWM channel
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @param[in]   Period Period of the PWM signal
 * @param[in]   DutyCycle 0x0000 for 0%, 0x8000 for 100%
 * @return      void
 */
PWM_FUNC void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType CallIsValid;
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CallIsValid = Pwm_ValidateChannelConfigCall(ChannelNumber, PWM_SID_SET_PERIOD_AND_DUTY);
    if (E_OK == CallIsValid)
    {
        CallIsValid = Pwm_ValidateParamsPeriodClass((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].ChannelClass, PWM_SID_SET_PERIOD_AND_DUTY);
        if (E_OK == CallIsValid)
        {
            CallIsValid = Pwm_ValidateParamDuty(DutyCycle, PWM_SID_SET_PERIOD_AND_DUTY);
            if (E_OK == CallIsValid)
            {
#endif
                /* MLD call to hw channel set period and duty cycle */
                Pwm_Mld_SetPeriodAndDuty(Period, DutyCycle, &((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].MldChCfg));
#if (PWM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif
}
#endif /* PWM_SET_PERIOD_AND_DUTY == STD_ON */

#if (PWM_SET_OUTPUT_TO_IDLE == STD_ON)
/**
 * @brief       Service sets the PWM output to the configured Idle state.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @return      void
 */
PWM_FUNC void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType CallIsValid;
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CallIsValid = Pwm_ValidateChannelConfigCall(ChannelNumber, PWM_SID_SET_OUTPUT_TO_IDLE);
    if (E_OK == CallIsValid)
    {
        CallIsValid = Pwm_ValidateSetOutPutToIdle(ChannelNumber);
        if (E_OK == CallIsValid)
        {
#endif
            /* MLD call to hw channel set output to idle */
            Pwm_Mld_SetOutputToIdle
            (
                (*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].ChannelIdleState,
                &((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].MldChCfg)
            );
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}
#endif

#if (PWM_GET_OUTPUT_STATE == STD_ON)
/**
 * @brief       Service to read the internal state of the PWM output signal.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @return      Pwm_OutputStateType
 */
PWM_FUNC Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{
    /* SWS_Pwm_30051 */
    Pwm_OutputStateType OutputState = PWM_LOW;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType CallIsValid;
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CallIsValid = Pwm_ValidateChannelConfigCall(ChannelNumber, PWM_SID_GET_OUTPUT_STATE);
    if (E_OK == CallIsValid)
    {
#endif
        /* MLD call to hw channel get output state */
        OutputState = Pwm_Mld_GetOutputState(&((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].MldChCfg));
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return OutputState;
}
#endif

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        This function is used to update the dead time at runtime for Pwm channels.
* @param[in]    ChannelNumber Pwm channel id
* @param[in]    DeadTimeTicks Dead Time value
* @return       void
*/
void Pwm_SetChannelDeadTime(Pwm_ChannelType ChannelNumber, uint16 DeadTimeTicks)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType CallIsValid;
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    CallIsValid = Pwm_ValidateChannelConfigCall(ChannelNumber, PWM_SID_SET_CHANNEL_DEAD_TIME_ID);
    if (E_OK == CallIsValid)
    {
        CallIsValid = Pwm_ValidateDeadTime(ChannelNumber);
        if (E_OK == CallIsValid)
        {
#endif
            Pwm_Mld_SetChannelDeadTime(DeadTimeTicks, &((*Pwm_DriverState.PwmChannelConfigs)[ChannelNumber].MldChCfg));
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}
#endif

#if (PWM_VERSION_INFO_API == STD_ON)
/**
 * @brief       This function returns Pwm driver version details
 * @details     The function Pwm_GetVersionInfo shall return the version information of this module.
 *              The version information includes: Module Id, Vendor Id, Vendor specific version number.
 * @param[out]  VersionInfo Pointer to Std_VersionInfoType output variable
 * @return      void
 */
PWM_FUNC void Pwm_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret;

    Ret = Pwm_ValidatePtrVersion(VersionInfo);
    if (E_OK == Ret)
#endif
    {
        VersionInfo->vendorID = (uint16)PWM_VENDOR_ID;
        VersionInfo->moduleID = (uint16)PWM_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)PWM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)PWM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)PWM_SW_PATCH_VERSION;
    }
}
#endif /* PWM_VERSION_INFO_API */



#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
#if 0
/**
 * @brief       Service to disable the PWM signal edge notification.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @return      void
 */
PWM_FUNC void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
}

/**
 * @brief       Service to enable the PWM signal edge notification according to notification parameter.
 * @param[in]   ChannelNumber Numeric identifier of the PWM
 * @param[in]   Notification Type of notification
 * @return      void
 */
PWM_FUNC void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
}
#endif
#endif

#if (PWM_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief       This API is cyclically called and supervises the power state transitions.
 * @return      void
 */
PWM_FUNC void Pwm_Main_PowerTransitionManager(void)
{
}

/**
 * @brief       This API returns the current power state of the PWM HW unit.
 * @param[out]  CurrentPowerState The current power mode of the PWM HW Unit is returned in this parameter
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED:Current power mode was returned.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * @return  Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType *CurrentPowerState, Pwm_PowerStateRequestResultType *Result)
{
}

/**
 * @brief       This API returns the Target power state of the PWM HW unit.
 * @param[out]  TargetPowerState The Target power mode of the PWM HW Unit is returned in this parameter
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED:Target power mode was returned.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * @return      Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType *TargetPowerState, Pwm_PowerStateRequestResultType *Result)
{
}

/**
 * @brief       This API starts the needed process to allow the PWM HW module to enter the requested power state.
 * @param[in]   PowerState The target power state intended to be attained
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED: PWM Module power state preparation was started.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * PWM_SEQUENCE_ERROR: wrong API call sequence (Current Power State = Target Power State).
 * PWM_POWER_STATE_NOT_SUPP: PWM Module does not support the requested power state.
 * PWM_TRANS_NOT_POSSIBLE: PWM Module cannot transition directly from the current power state to
 * the requested power state or the HW peripheral is still busy.
 * @return      Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType PowerState, Pwm_PowerStateRequestResultType *Result)
{
}

/**
 * @brief       This API configures the Pwm module so that it enters the already prepared power state, chosen between a predefined set of configured ones.
 * @param[out]  Result
 * If the API returns E_OK: PWM_SERVICE_ACCEPTED:Power state change executed.
 * If the API returns E_NOT_OK: PWM_NOT_INIT: PWM Module not initialized.
 * PWM_SEQUENCE_ERROR: wrong API call sequence.
 * PWM_HW_FAILURE: the HW module has a failure which prevents it to enter the required power state.
 * @return      Std_ReturnType
 */
PWM_FUNC Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType *Result)
{
}
#endif /* PWM_LOW_POWER_STATES_SUPPORT == STD_ON */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

