/**************************************************************************************************/
/**
 * @file      : Wdg_179_Ewdt.c
 * @brief     : Wdg_179_Ewdt AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Wdg_179_Ewdt_Module
 *  @{
 */

/** @addtogroup Wdg_179_Ewdt
 *  @brief Wdg_179_Ewdt AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Ewdt_Drv.h"
#include "Wdg_179_Ewdt.h"
#include "SchM_Wdg_179_Ewdt.h"
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (WDG_179_EWDT_E_MODE_FAILED_ENABLE == STD_ON)
    #include "Dem.h"
#endif
/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_179_EWDT_C_VENDOR_ID                   0x00B3U
#define WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION    6U
#define WDG_179_EWDT_C_AR_RELEASE_REVISION_VERSION 0U
#define WDG_179_EWDT_C_SW_MAJOR_VERSION            1U
#define WDG_179_EWDT_C_SW_MINOR_VERSION            2U
#define WDG_179_EWDT_C_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_179_Ewdt.h header file are of the same vendor */
#if (WDG_179_EWDT_C_VENDOR_ID != WDG_179_EWDT_VENDOR_ID)
   #error "Vendor ID of Wdg_179_Ewdt.c and Wdg_179_Ewdt.h are different"
#endif

#if ((WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION    != WDG_179_EWDT_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION    != WDG_179_EWDT_AR_RELEASE_MINOR_VERSION) || \
    (WDG_179_EWDT_C_AR_RELEASE_REVISION_VERSION != WDG_179_EWDT_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_179_Ewdt.c and Wdg_179_Ewdt.h are different"
#endif

#if ((WDG_179_EWDT_C_SW_MAJOR_VERSION != WDG_179_EWDT_SW_MAJOR_VERSION) || \
    (WDG_179_EWDT_C_SW_MINOR_VERSION != WDG_179_EWDT_SW_MINOR_VERSION) || \
    (WDG_179_EWDT_C_SW_PATCH_VERSION != WDG_179_EWDT_SW_PATCH_VERSION))
#error "Software Version of Wdg_179_Ewdt.c and Wdg_179_Ewdt.h are different"
#endif

/* Check if current file and Ewdt_Drv.h header file are of the same vendor */
#if (WDG_179_EWDT_C_VENDOR_ID != EWDT_DRV_H_VENDOR_ID)
   #error "Vendor ID of Wdg_179_Ewdt.c and Ewdt_Drv.h are different"
#endif

#if ((WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION    != EWDT_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION    != EWDT_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (WDG_179_EWDT_C_AR_RELEASE_REVISION_VERSION != EWDT_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_179_Ewdt.c and Ewdt_Drv.h are different"
#endif

#if ((WDG_179_EWDT_C_SW_MAJOR_VERSION != EWDT_DRV_H_SW_MAJOR_VERSION) || \
    (WDG_179_EWDT_C_SW_MINOR_VERSION != EWDT_DRV_H_SW_MINOR_VERSION) || \
    (WDG_179_EWDT_C_SW_PATCH_VERSION != EWDT_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Wdg_179_Ewdt.c and Ewdt_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    /* Check if current file and Det.h file are of the same Autosar version */
    #if ((WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_179_Ewdt.c and Det.h are different"
    #endif
#endif
    /* Check if current file and SchM_Wdg_179_Ewdt.h file are of the same Autosar version */
    #if ((WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION != SCHM_WDG_179_EWDT_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION != SCHM_WDG_179_EWDT_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdg_179_Ewdt.c and SchM_Wdg_179_Ewdt.h are different"
    #endif
#if (WDG_179_EWDT_E_MODE_FAILED_ENABLE == STD_ON)
    /* Check if current file and Dem.h file are of the same Autosar version */
    #if ((WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_179_Ewdt.c and Dem.h are different"
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

#define WDG_179_EWDT_START_SEC_VAR_CLEARED_32
#include "Wdg_179_Ewdt_MemMap.h"
#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
/**
*  @brief ewdt timeout in Gpt counter tick.
*/
static uint32 Wdg_179_Ewdt_TimeoutTickForGpt;
/**
*  @brief Gpt one period ticks.
*/
static uint32 Wdg_179_Ewdt_GptPeriodTick;
#endif
#define WDG_179_EWDT_STOP_SEC_VAR_CLEARED_32
#include "Wdg_179_Ewdt_MemMap.h"

#define WDG_179_EWDT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_179_Ewdt_MemMap.h"

#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
static Wdg_179_Ewdt_StateType Wdg_179_Ewdt_State = WDG_179_EWDT_UNINIT;
#endif

#define WDG_179_EWDT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_179_Ewdt_MemMap.h"

#define WDG_179_EWDT_START_SEC_VAR_CLEARED_PTR
#include "Wdg_179_Ewdt_MemMap.h"
/**
 * @brief Pointer to current flash module configuration set
 */
static const Wdg_179_Ewdt_ConfigType * Wdg_179_Ewdt_ConfigPtr;
#define WDG_179_EWDT_STOP_SEC_VAR_CLEARED_PTR
#include "Wdg_179_Ewdt_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#if (WDG_179_EWDT_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_START_SEC_CODE
#else
#define WDG_179_EWDT_START_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
/**
* @brief      starts the Gpt channel used for servicing the Wdg_179_Ewdt.
*
* @param[in]   None
*
* @return   None
*/
static void Wdg_179_Ewdt_StartGpt(void)
{
    Gpt_StopTimer(Wdg_179_Ewdt_ConfigPtr->GptChannel);
    
    Wdg_179_Ewdt_GptPeriodTick = Wdg_179_Ewdt_ConfigPtr->TimerTriggerPeriod;
    Gpt_EnableNotification(Wdg_179_Ewdt_ConfigPtr->GptChannel);
    
    Gpt_StartTimer(Wdg_179_Ewdt_ConfigPtr->GptChannel, Wdg_179_Ewdt_GptPeriodTick);

    Wdg_179_Ewdt_TimeoutTickForGpt = (uint32)(WDG_179_EWDT_INITIAL_TIMEOUT * (Wdg_179_Ewdt_ConfigPtr->GptClock));

}
#endif

#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
/**
* @brief       This function check the timeout value
*
* @param[in]   Timeout: Timeout value
*
* @return      The check result
* @retval      E_OK      
* @retval      E_NOT_OK 
* 
* */
LOCAL_INLINE Std_ReturnType Wdg_179_Ewdt_CheckTimeout(uint16 Timeout)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;    

    if ((( Timeout > 0U)&&(Timeout < WDG_179_EWDT_TRIGER_TIME))
           || (Timeout > WDG_179_EWDT_MAX_TIMEOUT))
    {
        (void)Det_ReportError(WDG_179_EWDT_MODULE_ID, WDG_179_EWDT_INSTANCE_ID, WDG_179_EWDT_SID_SET_TRIGGER_CONDITION, WDG_179_EWDT_E_PARAM_TIMEOUT);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }
    return ReturnVal;
}

/**
 * @brief      Check if the current state is WDG_179_EWDT_IDLE, if yes, change the state to WDG_179_EWDT_BUSY
 *
 * @param[in]   ServiceId: The service id of the caller
 *
 * @return     the check result
 * @retval     E_OK 
 * @retval     E_NOT_OK
 *
 */
static Std_ReturnType Wdg_179_Ewdt_CheckIdleState(uint32 ServiceId)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;
    
    SchM_Enter_Wdg_179_Ewdt_ProtectEwdtState();
    if(WDG_179_EWDT_IDLE != Wdg_179_Ewdt_State)
    {  
        SchM_Exit_Wdg_179_Ewdt_ProtectEwdtState();
        (void)Det_ReportError(WDG_179_EWDT_MODULE_ID, WDG_179_EWDT_INSTANCE_ID, (uint8)ServiceId, WDG_179_EWDT_E_DRIVER_STATE);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Wdg_179_Ewdt_State = WDG_179_EWDT_BUSY;
        SchM_Exit_Wdg_179_Ewdt_ProtectEwdtState();
    }

    return ReturnVal;
}

/**
* @brief      This function check the ewdt status for the triggering event.
*
* @param[in]   Timeout: Timeout value
*
* @return      The validity of the function call
* @retval      E_OK    
* @retval      E_NOT_OK 
*
*/
LOCAL_INLINE Std_ReturnType Wdg_179_Ewdt_CheckSetTriggerCondition(uint16 Timeout)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;
    if (Wdg_179_Ewdt_State != WDG_179_EWDT_IDLE)
    {
        (void)Det_ReportError(WDG_179_EWDT_MODULE_ID, WDG_179_EWDT_INSTANCE_ID, WDG_179_EWDT_SID_SET_TRIGGER_CONDITION, WDG_179_EWDT_E_DRIVER_STATE);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }

    if(E_OK == ReturnVal)
    {
        ReturnVal = Wdg_179_Ewdt_CheckTimeout(Timeout);
    }

    return ReturnVal;
}
#endif

/**
 * @brief     Checks the status and parameters for init API
 *
 * @param[in]   ConfigPtr: Pointer to configuration structure.
 *
 * @return      The check result
 * @retval      E_OK  
 * @retval      E_NOT_OK
 *
 */
static Std_ReturnType Wdg_179_Ewdt_CheckInit(const Wdg_179_Ewdt_ConfigType *ConfigPtr)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;

    if(WDG_179_EWDT_UNINIT != Wdg_179_Ewdt_State)
    {
        (void)Det_ReportError(WDG_179_EWDT_MODULE_ID, WDG_179_EWDT_INSTANCE_ID, WDG_179_EWDT_SID_INIT, WDG_179_EWDT_E_DRIVER_STATE);
        ReturnVal = (Std_ReturnType)E_NOT_OK;
    }

    if(ReturnVal == (Std_ReturnType)E_OK)
    {
#if (WDG_179_EWDT_PRECOMPILE_SUPPORT == STD_ON)
        if (ConfigPtr != NULL_PTR)
#else
        if (ConfigPtr == NULL_PTR )
#endif
        {
            (void)Det_ReportError(WDG_179_EWDT_MODULE_ID, WDG_179_EWDT_INSTANCE_ID, WDG_179_EWDT_SID_INIT, WDG_179_EWDT_E_INIT_FAILED);
            ReturnVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnVal;
}
#endif

/**
 * @brief       Handle the initialization result
 *
 * @param[in]   ReturnVal: The initialization result 
 *
 * @return      None
 *
 */
static void Wdg_179_Ewdt_HandleInitResult(const Std_ReturnType ReturnVal)
{
    if (ReturnVal == (Std_ReturnType)E_OK)
    {
#if(WDG_179_EWDT_E_MODE_FAILED_ENABLE == STD_ON)
        /*SWS_Wdg_00173*/
        (void) Dem_SetEventStatus(WDG_179_EWDT_E_MODE_FAILED_EVNEN_ID, DEM_EVENT_STATUS_PASSED);
#endif

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
        Wdg_179_Ewdt_StartGpt();
#endif

#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
        Wdg_179_Ewdt_State = WDG_179_EWDT_IDLE;
#endif 
    } 
    else
    {
#if(WDG_179_EWDT_E_MODE_FAILED_ENABLE == STD_ON)
        /*SWS_Wdg_00173*/
        (void) Dem_SetEventStatus(WDG_179_EWDT_E_MODE_FAILED_EVNEN_ID, DEM_EVENT_STATUS_FAILED);
#endif

#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(WDG_179_EWDT_MODULE_ID, WDG_179_EWDT_INSTANCE_ID, 
                                    WDG_179_EWDT_SID_INIT, WDG_179_EWDT_E_INIT_FAILED);
#endif            
    }
}

#if (WDG_179_EWDT_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_STOP_SEC_CODE
#else
#define WDG_179_EWDT_STOP_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#if (WDG_179_EWDT_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_START_SEC_CODE
#else
#define WDG_179_EWDT_START_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

/**
* @brief   This function initializes the WDG_179_EWDT module.
*
* @param[in] ConfigPtr: Pointer to configuration structure.
*
* @return   None
**/
void Wdg_179_Ewdt_Init(const Wdg_179_Ewdt_ConfigType *ConfigPtr)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_NOT_OK;
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    ReturnVal = Wdg_179_Ewdt_CheckInit(ConfigPtr);
    if ((Std_ReturnType)E_OK == ReturnVal)
    {
#endif

#if (WDG_179_EWDT_PRECOMPILE_SUPPORT == STD_ON)
        Wdg_179_Ewdt_ConfigPtr = Wdg_179_Ewdt_PreDefinedConfigPtr;
#else
        Wdg_179_Ewdt_ConfigPtr = ConfigPtr;
#endif

        ReturnVal = (Std_ReturnType)Ewdt_Drv_Init(Wdg_179_Ewdt_ConfigPtr->EwdtDrvConfig);  
        Wdg_179_Ewdt_HandleInitResult(ReturnVal); 
        
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
* @brief   Switches the ewdt into the mode.
* @note    Due to hardware limitation,ewdt cannot support mode switch.So this function will return
*          E_NOT_OK all the time.
*
* @param[in] Mode      One of the following statically configured modes:<br>
*                      - WDGIF_OFF_MODE,
*                      - WDGIF_SLOW_MODE,
*                      - WDGIF_FAST_MODE.
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
*/
Std_ReturnType Wdg_179_Ewdt_SetMode(WdgIf_ModeType Mode)
{
    (void)Mode;
    return E_NOT_OK;
}

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
/**
 * @brief   Sets the timeout value for the trigger counter.
 *
 * @param[in] Timeout: Timeout value (milliseconds) for setting the trigger counter.
 * 
 * @return   None
 *  
 */
void Wdg_179_Ewdt_SetTriggerCondition(uint16 Timeout)
{
    Gpt_ValueType GptElapsedTick = (Gpt_ValueType)0;
#if(WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnVal = (Std_ReturnType)E_NOT_OK;

    ReturnVal = Wdg_179_Ewdt_CheckSetTriggerCondition(Timeout);
    if ((Std_ReturnType)E_OK == ReturnVal)
    {
#endif
        GptElapsedTick =  Gpt_GetTimeElapsed(Wdg_179_Ewdt_ConfigPtr->GptChannel);
        SchM_Enter_Wdg_179_Ewdt_ProtectEwdtTimeoutValue();
        if ((GptElapsedTick > Wdg_179_Ewdt_TimeoutTickForGpt) || ((uint16)0 == Timeout) ||(0U == Wdg_179_Ewdt_TimeoutTickForGpt))
        {
            Wdg_179_Ewdt_TimeoutTickForGpt = (uint32)0;
            SchM_Exit_Wdg_179_Ewdt_ProtectEwdtTimeoutValue();
            Gpt_StopTimer(Wdg_179_Ewdt_ConfigPtr->GptChannel);
        }
        else
        {
            Wdg_179_Ewdt_TimeoutTickForGpt = (uint32)(Timeout * Wdg_179_Ewdt_ConfigPtr->GptClock) + GptElapsedTick;
            SchM_Exit_Wdg_179_Ewdt_ProtectEwdtTimeoutValue();
        }
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_ON)
/**
* @brief   Service the ewdt directly
*
* @param[in] none
* 
* @return   None
* 
*/
void Wdg_179_Ewdt_Service(void)
{
    if(NULL_PTR != Wdg_179_Ewdt_ConfigPtr)
    {
        Ewdt_Drv_Refresh(Wdg_179_Ewdt_ConfigPtr->CbBeforeRefreshPtr,
                                        Wdg_179_Ewdt_ConfigPtr->CbAfterRefreshPtr);
    }
}
#endif

#if (WDG_179_EWDT_VERSION_INFO_API == STD_ON)
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
void Wdg_179_Ewdt_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(WDG_179_EWDT_MODULE_ID, WDG_179_EWDT_INSTANCE_ID,
                       WDG_179_EWDT_SID_GET_VERSION_INFO,WDG_179_EWDT_E_PARAM_POINTER);
    }
    else
    {
#endif
        versioninfo->vendorID         = (uint16)WDG_179_EWDT_VENDOR_ID;
        versioninfo->moduleID         = (uint16)WDG_179_EWDT_MODULE_ID;
        versioninfo->sw_major_version = (uint8)WDG_179_EWDT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)WDG_179_EWDT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)WDG_179_EWDT_SW_PATCH_VERSION;
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
/**
 * @brief     Callback function for GPT notification.
 * 
 * @param[in] None
 * 
 * @return   None
 * 
 */
void Wdg_179_Ewdt_CallbackForGptNotification(void)
{
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;
    ReturnVal = Wdg_179_Ewdt_CheckIdleState(WDG_179_EWDT_SID_TRIGGER);

    if ((Std_ReturnType)E_OK == ReturnVal)
    {
#endif
        if( Wdg_179_Ewdt_TimeoutTickForGpt < Wdg_179_Ewdt_GptPeriodTick)
        {
            Gpt_StopTimer(Wdg_179_Ewdt_ConfigPtr->GptChannel);
        }
        else
        {
            Wdg_179_Ewdt_TimeoutTickForGpt = Wdg_179_Ewdt_TimeoutTickForGpt - Wdg_179_Ewdt_GptPeriodTick;
            Ewdt_Drv_Refresh(Wdg_179_Ewdt_ConfigPtr->CbBeforeRefreshPtr,
                                        Wdg_179_Ewdt_ConfigPtr->CbAfterRefreshPtr);
        }
#if (WDG_179_EWDT_DEV_ERROR_DETECT == STD_ON)
    }
    Wdg_179_Ewdt_State = WDG_179_EWDT_IDLE;
#endif
}
#endif

#if (WDG_179_EWDT_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_STOP_SEC_CODE
#else
#define WDG_179_EWDT_STOP_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

/** @} end of Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif
/** @} end of group Wdg_179_Ewdt */

/** @} end of group Wdg_179_Ewdt_Module */
