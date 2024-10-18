/**************************************************************************************************/
/**
 * @file      : Wdg.c
 * @brief     : Wdg AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdg
 *  @brief Wdg AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_Drvw.h"
#include "Wdg.h"
#include "Det.h"
#if ((WDG_E_MODE_FAILED_ENABLE == STD_ON) || (WDG_E_DISABLE_REJECTED_ENABLE == STD_ON))
    #include "Dem.h"
#endif
/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_C_VENDOR_ID                   0x00B3U
#define WDG_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_C_AR_RELEASE_MINOR_VERSION    6U
#define WDG_C_AR_RELEASE_REVISION_VERSION 0U
#define WDG_C_SW_MAJOR_VERSION            1U
#define WDG_C_SW_MINOR_VERSION            2U
#define WDG_C_SW_PATCH_VERSION            1U

/* Check if current file and Wdg.h header file are of the same vendor */
#if (WDG_C_VENDOR_ID != WDG_VENDOR_ID)
   #error "Vendor ID of Wdg.c and Wdg.h are different"
#endif

#if ((WDG_C_AR_RELEASE_MAJOR_VERSION    != WDG_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_C_AR_RELEASE_MINOR_VERSION    != WDG_AR_RELEASE_MINOR_VERSION) || \
    (WDG_C_AR_RELEASE_REVISION_VERSION != WDG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg.c and Wdg.h are different"
#endif

#if ((WDG_C_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION) || \
    (WDG_C_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION) || \
    (WDG_C_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION))
#error "Software Version of Wdg.c and Wdg.h are different"
#endif

/* Check if current file and Wdg_Drvw.h header file are of the same vendor */
#if (WDG_C_VENDOR_ID != WDG_DRVW_H_VENDOR_ID)
   #error "Vendor ID of Wdg.c and Wdg_Drvw.h are different"
#endif

#if ((WDG_C_AR_RELEASE_MAJOR_VERSION    != WDG_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_C_AR_RELEASE_MINOR_VERSION    != WDG_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
    (WDG_C_AR_RELEASE_REVISION_VERSION != WDG_DRVW_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg.c and Wdg_Drvw.h are different"
#endif

#if ((WDG_C_SW_MAJOR_VERSION != WDG_DRVW_H_SW_MAJOR_VERSION) || \
    (WDG_C_SW_MINOR_VERSION != WDG_DRVW_H_SW_MINOR_VERSION) || \
    (WDG_C_SW_PATCH_VERSION != WDG_DRVW_H_SW_PATCH_VERSION))
#error "Software Version of Wdg.c and Wdg_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Wdg.c file and Det.h file are of the same Autosar version */
    #if ((WDG_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg.c and Det.h are different"
    #endif
#if ((WDG_E_MODE_FAILED_ENABLE == STD_ON) || (WDG_E_DISABLE_REJECTED_ENABLE == STD_ON))
    /* Check if Wdg.c file and Dem.h file are of the same Autosar version */
    #if ((WDG_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg.c and Dem.h are different"
    #endif
#endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define WDG_START_SEC_CONST_32
#include "Wdg_MemMap.h"

#if (WDG_DEV_ERROR_DETECT == STD_ON)
#if (WDG_DIRECT_SERVICE == STD_OFF)
static const uint32 Wdg_TimeOutPeriod[3] = WDG_TIMEOUT_VALUE_ARRAY;
#endif
#endif

#define WDG_STOP_SEC_CONST_32
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_CLEARED_32
#include "Wdg_MemMap.h"
#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
*  @brief watchdog timeout in Gpt counter tick.
*/
static uint32 Wdg_TimeoutTickForGpt;
/**
*  @brief Gpt one period ticks.
*/
static uint32 Wdg_GptPeriodTick;
#endif
#define WDG_STOP_SEC_VAR_CLEARED_32
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#if (WDG_DEV_ERROR_DETECT == STD_ON)
static Wdg_StateType Wdg_State = WDG_UNINIT;
#if (WDG_DIRECT_SERVICE == STD_OFF)
static WdgIf_ModeType Wdg_Mode = WDGIF_OFF_MODE;
#endif
#endif

#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_CLEARED_PTR
#include "Wdg_MemMap.h"
/**
 * @brief Pointer to current flash module configuration set
 */
static const Wdg_ConfigType * Wdg_ConfigPtr;
#define WDG_STOP_SEC_VAR_CLEARED_PTR
#include "Wdg_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#if (WDG_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
* @brief      starts the Gpt channel used for servicing the Wdg.
*
* @param[in]   None
*
* @return   None
*/
static void Wdg_StartGpt(void)
{
    uint8 WdogMode;
    WdgIf_ModeType Mode = Wdg_ConfigPtr->DrvwConfigPtr->DefaultMode;

    Gpt_StopTimer(Wdg_ConfigPtr->GptChannel);
    
    if((WDGIF_FAST_MODE == Mode) || (WDGIF_SLOW_MODE == Mode))
    {
        if(WDGIF_SLOW_MODE == Mode)
        {
            WdogMode = 1U;
        }
        else
        {
            WdogMode = 2U;
        }
        Wdg_GptPeriodTick = Wdg_ConfigPtr->DrvwConfigPtr->ModeConfigPtr[WdogMode]->TimerTriggerPeriod;
        Gpt_EnableNotification(Wdg_ConfigPtr->GptChannel);
        
        Gpt_StartTimer(Wdg_ConfigPtr->GptChannel, Wdg_GptPeriodTick);

    }
    Wdg_TimeoutTickForGpt = (uint32)(WDG_INITIAL_TIMEOUT * (Wdg_ConfigPtr->GptClock));

}
#endif

/**
 * @brief       check the mode to be configured.
 *
 * @param[in]   Mode: the mode
 * @param[in]   ServiceId: The service id of the caller
 * @param[in]   ErrorId: The function call was previously validated
 *
 * @return      The check result
 * @retval      E_OK    
 * @retval      E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Wdg_CheckMode(WdgIf_ModeType Mode,  uint8 ServiceId,uint8 ErrorId)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;

    if (!((WDGIF_FAST_MODE == Mode)||(WDGIF_OFF_MODE  == Mode)||(WDGIF_SLOW_MODE == Mode)))
    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, ServiceId, ErrorId);
#endif

        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }
#if (WDG_DISABLE_ALLOWED != STD_ON)
    else if(WDGIF_OFF_MODE == Mode)
    {
      ReturnVal = (Std_ReturnType)E_NOT_OK;
#if (WDG_E_DISABLE_REJECTED_ENABLE == STD_ON)
        /*SWS_Wdg_00026,SWS_Wdg_00025*/
        (void) Dem_SetEventStatus(WDG_E_DISABLE_REJECTED_EVNEN_ID, DEM_EVENT_STATUS_FAILED);
#endif
    }
#endif
    else
    {
#if (WDG_E_DISABLE_REJECTED_ENABLE == STD_ON)
        (void) Dem_SetEventStatus(WDG_E_DISABLE_REJECTED_EVNEN_ID, DEM_EVENT_STATUS_PASSED);
#endif
    }

    return ReturnVal;
}

#if (WDG_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Check if the current state is WDG_IDLE, if yes, change the state to WDG_BUSY
 *
 * @param[in]   ServiceId: The service id of the caller
 *
 * @return     the check result
 * @retval     E_OK 
 * @retval     E_NOT_OK
 *
 */
static Std_ReturnType Wdg_CheckIdleState(uint32 ServiceId)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;
    
    SchM_Enter_Wdg_ProtectWdgState();
    if(WDG_IDLE != Wdg_State)
    {  
        SchM_Exit_Wdg_ProtectWdgState();
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, (uint8)ServiceId, WDG_E_DRIVER_STATE);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Wdg_State = WDG_BUSY;
        SchM_Exit_Wdg_ProtectWdgState();
    }

    return ReturnVal;
}

#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
* @brief       This function check the timeout value
*
* @param[in]   Timeout: timeout value
*
* @return      the check result
* @retval      E_OK      
* @retval      E_NOT_OK 
* 
* */
LOCAL_INLINE Std_ReturnType Wdg_CheckTimeout(uint16 Timeout)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK; 
    uint8 WdogMode;
    
    if(WDGIF_SLOW_MODE == Wdg_Mode)
    {
        WdogMode = 1U;
    }
    else if(WDGIF_FAST_MODE == Wdg_Mode)
    {
        WdogMode = 2U;
    }
    else
    {
        WdogMode = 0U;
    }

    if (((Timeout <= Wdg_TimeOutPeriod[WdogMode]) && ( Timeout > 0U))
           || (Timeout > WDG_MAX_TIMEOUT))
    {
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, WDG_SID_SET_TRIGGER_CONDITION, WDG_E_PARAM_TIMEOUT);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }
    return ReturnVal;
}

/**
* @brief      This function check the watchdog status for the triggering event.
*
* @param[in]   Timeout: timeout value
*
* @return      The validity of the function call
* @retval      E_OK    
* @retval      E_NOT_OK 
*
*/
LOCAL_INLINE Std_ReturnType Wdg_CheckSetTriggerCondition(uint16 Timeout)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;
    if (Wdg_State != WDG_IDLE)
    {
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, WDG_SID_SET_TRIGGER_CONDITION, WDG_E_DRIVER_STATE);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }

    if(E_OK == ReturnVal)
    {
        ReturnVal = Wdg_CheckTimeout(Timeout);
    }

    return ReturnVal;
}
#endif

/**
 * @brief     Checks the status and parameters for init API
 *
 * @param[in]   ConfigPtr: Pointer to configuration structure.
 *
 * @return      the check result
 * @retval      E_OK  
 * @retval      E_NOT_OK
 *
 */
static Std_ReturnType Wdg_CheckInit(const Wdg_ConfigType *ConfigPtr)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;

    if(WDG_UNINIT != Wdg_State)
    {
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, WDG_SID_INIT, WDG_E_DRIVER_STATE);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }

    if(ReturnVal == (Std_ReturnType)E_OK)
    {
#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
        if (ConfigPtr != NULL_PTR)
#else
        if (ConfigPtr == NULL_PTR )
#endif
        {
            (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, WDG_SID_INIT, WDG_E_INIT_FAILED);
            ReturnVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnVal;
}

/**
 * @brief      This function checks the parameter and status for Wdg_SetMode()
 *
 * @param[in]  Mode: the mode to be checked
 *
 * @return     the check result
 * @retval     E_OK 
 * @retval     E_NOT_OK
 *
 */
static Std_ReturnType Wdg_CheckSetMode(WdgIf_ModeType Mode)
{
    Std_ReturnType ReturnVal = Wdg_CheckMode(Mode,WDG_SID_SET_MODE,WDG_E_PARAM_MODE);

    if(ReturnVal == (Std_ReturnType)E_OK)
    {
        ReturnVal = Wdg_CheckIdleState(WDG_SID_SET_MODE);
    }

    return ReturnVal;
}
#endif

/**
 * @brief       checks the initialization result
 *
 * @param[in]   Res: the initial result from drvw level
 *
 * @return      the check result
 * @retval      E_OK 
 * @retval      E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Wdg_CheckInitResult(const Std_ReturnType Res)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)Res;
    if (ReturnVal != (Std_ReturnType)E_OK)
    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, WDG_SID_INIT, WDG_E_INIT_FAILED);
#endif

#if(WDG_E_MODE_FAILED_ENABLE == STD_ON)
        /*SWS_Wdg_00173*/
        (void) Dem_SetEventStatus(WDG_E_MODE_FAILED_EVNEN_ID, DEM_EVENT_STATUS_FAILED);
#endif
        Wdg_ConfigPtr = NULL_PTR;
    }
    else
    {
#if(WDG_E_MODE_FAILED_ENABLE == STD_ON)
        (void) Dem_SetEventStatus(WDG_E_MODE_FAILED_EVNEN_ID, DEM_EVENT_STATUS_PASSED);
#endif
    }

    return ReturnVal;
}

/**
 * @brief       checks the channel mode setting for wdg.
 *
 * @param[in]   Status: The set mode result from drvw level
 * @param[in]   Mode: One of the following statically configured modes
 *                    - WDGIF_OFF_MODE,
 *                    - WDGIF_SLOW_MODE,
 *                    - WDGIF_FAST_MODE.
 * 
 * @return      The validity of the function call
 * @retval      E_OK
 * @retval      E_NOT_OK
 *
 */
static Std_ReturnType Wdg_HandleSetModeResult(const WdgIf_ModeType Mode, const Std_ReturnType Status)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)Status;
#if (WDG_DIRECT_SERVICE == STD_OFF)
    Gpt_ValueType GptElapsedTick;
    uint8 WdogMode;
#endif

    if (ReturnVal != (Std_ReturnType)E_OK)
    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, WDG_SID_SET_MODE, WDG_E_PARAM_MODE);
#endif   
#if (WDG_E_MODE_FAILED_ENABLE == STD_ON)
        (void) Dem_SetEventStatus(WDG_E_MODE_FAILED_EVNEN_ID, DEM_EVENT_STATUS_FAILED);
#endif
        if(ReturnVal == WDG_DRVW_E_TIMEOUT)
        {
            (void)Det_ReportRuntimeError(WDG_MODULE_ID, WDG_INSTANCE_WDOG, WDG_SID_SET_MODE, WDG_E_TIMEOUT);
        }
        ReturnVal = (Std_ReturnType)E_NOT_OK;                
    }
    else
    {   
#if (WDG_E_MODE_FAILED_ENABLE == STD_ON)
        (void) Dem_SetEventStatus(WDG_E_MODE_FAILED_EVNEN_ID, DEM_EVENT_STATUS_PASSED);
#endif
#if (WDG_DIRECT_SERVICE == STD_OFF)

        Gpt_StopTimer(Wdg_ConfigPtr->GptChannel);
        if((WDGIF_FAST_MODE == Mode) || (WDGIF_SLOW_MODE == Mode))
        {
            if(WDGIF_SLOW_MODE == Mode)
            {
                WdogMode = 1U;
            }
            else
            {
                WdogMode = 2U;
            }
	        GptElapsedTick =  Gpt_GetTimeElapsed(Wdg_ConfigPtr->GptChannel);
	        SchM_Enter_Wdg_ProtectWdgGptPeriod();
	        if(Wdg_TimeoutTickForGpt <= GptElapsedTick)
	        {
	            Wdg_TimeoutTickForGpt = 0;
	        }
	        else
	        {
	            Wdg_TimeoutTickForGpt = Wdg_TimeoutTickForGpt - GptElapsedTick;
	        }
	        SchM_Exit_Wdg_ProtectWdgGptPeriod();

            Wdg_GptPeriodTick = Wdg_ConfigPtr->DrvwConfigPtr->ModeConfigPtr[WdogMode]->TimerTriggerPeriod;
            Gpt_StartTimer(Wdg_ConfigPtr->GptChannel,Wdg_GptPeriodTick);
        }
#endif
        ReturnVal = (Std_ReturnType)E_OK;
#if (WDG_DEV_ERROR_DETECT == STD_ON) && (WDG_DIRECT_SERVICE == STD_OFF)
        /* change the current mode flag to the new mode */
        Wdg_Mode = Mode;
#else
        (void)Mode;
#endif
    }

    return ReturnVal;
}

#if (WDG_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#if (WDG_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/**
* @brief   This function initializes the WDG module.
*
* @param[in] ConfigPtr: Pointer to configuration structure.
*
* @return   None
**/
void Wdg_Init(const Wdg_ConfigType *ConfigPtr)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_NOT_OK;
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    ReturnVal = Wdg_CheckInit(ConfigPtr);
    if ((Std_ReturnType)E_OK == ReturnVal)
    {
#endif

#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
        Wdg_ConfigPtr = Wdg_PreDefinedConfigPtr;
#else
        Wdg_ConfigPtr = ConfigPtr;
#endif
        ReturnVal = Wdg_CheckMode(Wdg_ConfigPtr->DrvwConfigPtr->DefaultMode, WDG_SID_INIT, WDG_E_PARAM_CONFIG);

        if((Std_ReturnType)E_OK == ReturnVal)
        {
            ReturnVal = Wdg_Drvw_Init(Wdg_ConfigPtr->DrvwConfigPtr);
            ReturnVal = Wdg_CheckInitResult(ReturnVal);
        }
        
        if (ReturnVal == (Std_ReturnType)E_OK)
        {
            
#if (WDG_DIRECT_SERVICE == STD_OFF)
            Wdg_StartGpt();
#endif

#if (WDG_DEV_ERROR_DETECT == STD_ON)
#if (WDG_DIRECT_SERVICE == STD_OFF)
            Wdg_Mode = Wdg_ConfigPtr->DrvwConfigPtr->DefaultMode;
#endif
            Wdg_State = WDG_IDLE;
#endif
        } 
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
* @brief   Switches the watchdog into the mode Mode.
*
* @param[in] Mode: One of the following statically configured modes:
*                  - WDGIF_OFF_MODE,
*                  - WDGIF_SLOW_MODE,
*                  - WDGIF_FAST_MODE.
*
* @return  Std_ReturnType.
* @retval  E_OK        Mode switched successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
**/
Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_NOT_OK;
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    ReturnVal = Wdg_CheckSetMode(Mode);
    if ((Std_ReturnType)E_OK == ReturnVal)
    {        
#endif
        ReturnVal = Wdg_Drvw_SetMode(Mode, Wdg_ConfigPtr->DrvwConfigPtr);
        ReturnVal = Wdg_HandleSetModeResult(Mode, ReturnVal);
		
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        Wdg_State = WDG_IDLE;
    }
#endif

    return ReturnVal;
}

#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
 * @brief   Sets the timeout value for the trigger counter.
 *
 * @param[in] Timeout: Timeout value (milliseconds) for setting the trigger counter.
 * 
 * @return   None
 *  
 */
void Wdg_SetTriggerCondition(uint16 Timeout)
{
    Gpt_ValueType GptElapsedTick = (Gpt_ValueType)0;
#if(WDG_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnVal = (Std_ReturnType)E_NOT_OK;

    ReturnVal = Wdg_CheckSetTriggerCondition(Timeout);
    if ((Std_ReturnType)E_OK == ReturnVal)
    {
#endif
        GptElapsedTick =  Gpt_GetTimeElapsed(Wdg_ConfigPtr->GptChannel);
        SchM_Enter_Wdg_ProtectWdgTimeoutValue();
        if ((GptElapsedTick > Wdg_TimeoutTickForGpt) || ((uint16)0 == Timeout) ||(0U == Wdg_TimeoutTickForGpt))
        {
            Wdg_TimeoutTickForGpt = (uint32)0;
            SchM_Exit_Wdg_ProtectWdgTimeoutValue();
            Gpt_StopTimer(Wdg_ConfigPtr->GptChannel);
        }
        else
        {
            Wdg_TimeoutTickForGpt = (uint32)(Timeout * Wdg_ConfigPtr->GptClock) + GptElapsedTick;
            SchM_Exit_Wdg_ProtectWdgTimeoutValue();
        }
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (WDG_DIRECT_SERVICE == STD_ON)
/**
* @brief   Service the Watchdog directly
*
* @param[in] none
* 
* @return   None
* 
*/
void Wdg_Service(void)
{
    Wdg_Drvw_Refresh(Wdg_ConfigPtr->DrvwConfigPtr);
}
#endif

#if (WDG_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of the module.
*
*
* @param[out] versioninfo   Pointer to where to store the version
*                              information of this module.
*
* @return   None
*
*/
void Wdg_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_WDOG,WDG_SID_GET_VERSION_INFO,WDG_E_PARAM_POINTER);
    }
    else
    {
#endif
        versioninfo->vendorID         = (uint16)WDG_VENDOR_ID;
        versioninfo->moduleID         = (uint16)WDG_MODULE_ID;
        versioninfo->sw_major_version = (uint8)WDG_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)WDG_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)WDG_SW_PATCH_VERSION;
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
 * @brief     Callback function for GPT notification.
 * 
 * @param[in] None
 * 
 * @return   None
 * 
 */
void Wdg_CallbackForGptNotification(void)
{
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;
    ReturnVal = Wdg_CheckIdleState(WDG_SID_TRIGGER);

    if ((Std_ReturnType)E_OK == ReturnVal)
    {
#endif
        if( Wdg_TimeoutTickForGpt < Wdg_GptPeriodTick)
        {
            Gpt_StopTimer(Wdg_ConfigPtr->GptChannel);
        }
        else
        {
            Wdg_TimeoutTickForGpt = Wdg_TimeoutTickForGpt - Wdg_GptPeriodTick;
            Wdg_Drvw_Refresh(Wdg_ConfigPtr->DrvwConfigPtr);
        }
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    }
    Wdg_State = WDG_IDLE;
#endif
}
#endif

#if (WDG_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/** @} end of Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif
/** @} end of group Wdg */

/** @} end of group Wdg_Module */
