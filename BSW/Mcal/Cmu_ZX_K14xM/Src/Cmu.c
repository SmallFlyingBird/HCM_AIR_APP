/**************************************************************************************************/
/**
 * @file      : Cmu.c
 * @brief     : AUTOSAR Cmu driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu
 *  @brief Cmu high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Cmu.h"
#include "Cmu_Drv.h"

#if (CMU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define CMU_C_VENDOR_ID                   0x00B3U
#define CMU_C_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_C_AR_RELEASE_MINOR_VERSION    6U
#define CMU_C_AR_RELEASE_REVISION_VERSION 0U
#define CMU_C_SW_MAJOR_VERSION            1U
#define CMU_C_SW_MINOR_VERSION            1U
#define CMU_C_SW_PATCH_VERSION            0U

/* Check if current file and Cmu.h file are of the same vendor */
#if (CMU_C_VENDOR_ID != CMU_VENDOR_ID)
    #error "Vendor ID of Cmu.c and Cmu.h are different"
#endif

/* Check if current file and Cmu.h file are of the same Autosar version */
#if ((CMU_C_AR_RELEASE_MAJOR_VERSION != CMU_AR_RELEASE_MAJOR_VERSION) ||                           \
     (CMU_C_AR_RELEASE_MINOR_VERSION != CMU_AR_RELEASE_MINOR_VERSION) ||                           \
     (CMU_C_AR_RELEASE_REVISION_VERSION != CMU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu.c and Cmu.h are different"
#endif

/* Check if current file and Cmu.h file are of the same Software version */
#if ((CMU_C_SW_MAJOR_VERSION != CMU_SW_MAJOR_VERSION) ||                                           \
     (CMU_C_SW_MINOR_VERSION != CMU_SW_MINOR_VERSION) ||                                           \
     (CMU_C_SW_PATCH_VERSION != CMU_SW_PATCH_VERSION))
    #error "Software Version of Cmu.c and Cmu.h are different"
#endif

/* Check if current file and Cmu_Drv.h file are of the same vendor */
#if (CMU_C_VENDOR_ID != CMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Cmu.c and Cmu_Drv.h are different"
#endif

/* Check if current file and Cmu_Drv.h file are of the same Autosar version */
#if ((CMU_C_AR_RELEASE_MAJOR_VERSION != CMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (CMU_C_AR_RELEASE_MINOR_VERSION != CMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (CMU_C_AR_RELEASE_REVISION_VERSION != CMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu.c and Cmu_Drv.h are different"
#endif

/* Check if current file and Cmu_Drv.h file are of the same Software version */
#if ((CMU_C_SW_MAJOR_VERSION != CMU_DRV_H_SW_MAJOR_VERSION) ||                                     \
     (CMU_C_SW_MINOR_VERSION != CMU_DRV_H_SW_MINOR_VERSION) ||                                     \
     (CMU_C_SW_PATCH_VERSION != CMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Cmu.c and Cmu_Drv.h are different"
#endif

#if (CMU_DEV_ERROR_DETECT == STD_ON)
    #ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
        /* Check if current file and Det.h are of the same Autosar version */
        #if ((CMU_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                   \
             (CMU_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Cmu.c and Det.h are different"
        #endif
    #endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
#endif     /* CMU_DEV_ERROR_DETECT */


#define CMU_MAX_ID_NUM                 3U


/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/**
 *  @brief Type definition of the Cmu status
 */
typedef enum
{
    CMU_UNINIT = 0x00U, /*!< Cmu module uninitialized. */
    CMU_INIT            /*!< Cmu module initialized. */
} Cmu_StatusType;

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#if (CMU_DEV_ERROR_DETECT == STD_ON)

#define CMU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cmu_MemMap.h"

/**
 *  @brief Variable that indicates the CMU status.
 */
static Cmu_StatusType Cmu_Status = CMU_UNINIT;

#define CMU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cmu_MemMap.h"
#endif

#define CMU_START_SEC_VAR_INIT_PTR
#include "Cmu_MemMap.h"

/**
 * @brief Local copy of the pointer to the configuration data
 */
static const Cmu_ConfigType *Cmu_ConfigPtr = NULL_PTR;

#define CMU_STOP_SEC_VAR_INIT_PTR
#include "Cmu_MemMap.h"


#define CMU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Cmu_MemMap.h"
/**
 * @brief   Logic and physic CMU Monitor map
 */
static Cmu_Drv_IdType Cmu_MonitorMappingArray[CMU_MAX_ID_NUM];

#define CMU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Cmu_MemMap.h"



/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

#define CMU_START_SEC_CODE
#include "Cmu_MemMap.h"

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#if (CMU_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks whether given CMU id is valid.
 *
 * @param[in]  CmuId: The given CMU id.
 *
 * @return     boolean
 * @retval     TRUE: CMU id is valid.
 * @retval     FALSE: CMU id is invalid.
 *
 */
static boolean Cmu_CheckCmuId(const Cmu_IdType CmuId)
{
    boolean CheckResult = FALSE;
    uint8   Index = 0U;

    if (CmuId < CMU_MAX_ID_NUM)
    {
        if (NULL_PTR != Cmu_ConfigPtr )
        {
            for (; Index < Cmu_ConfigPtr->NumberOfConfigedCmu; ++Index)
            {
                if (CmuId == Cmu_ConfigPtr->SysCmuConfigPtr[Index].CmuId)
                {
                    CheckResult = TRUE;
                    break;
                }
            }
        }
    }

    return CheckResult;
}

/**
 * @brief      Checks status to execute init service.
 *
 * @param[in]  ConfigPtr: Pointer to the Cmu configuration.
 *
 * @return    boolean
 * @retval    TRUE: Cmu init service is ready to execute.
 * @retval    FALSE: Cmu init service is not ready to execute.
 *
 */
static boolean Cmu_CheckInit(const Cmu_ConfigType *ConfigPtr)
{
    boolean CheckResult = TRUE;

    if (CMU_UNINIT != Cmu_Status)
    {
        CheckResult = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, CMU_SID_INIT,
                              CMU_E_ALLREADY_INITIALIZED);
    }
    else
    {
    #if (CMU_PRECOMPILE_SUPPORT == STD_OFF)
        if (NULL_PTR == ConfigPtr)
    #else
        if (NULL_PTR != ConfigPtr)
    #endif /* (CMU_PRECOMPILE_SUPPORT == STD_OFF) */
        {
            CheckResult = FALSE;
            (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, CMU_SID_INIT,
                                  CMU_E_PARAM_INVALID);
        }
    }

    return CheckResult;
}

/**
 * @brief      Checks status to execute the given service.
 *
 * @param[in]  CmuId: The given CMU id.
 * @param[in]  ServiceId: Service to be executed.
 *
 * @return    boolean
 * @retval    TRUE: The given service is ready to execute.
 * @retval    FALSE: The given service is not ready to execute.
 *
 */
static boolean Cmu_CheckExecuteService(Cmu_IdType CmuId, uint8 ServiceId)
{
    boolean CheckStatus = TRUE;

    if (CMU_UNINIT == Cmu_Status)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, ServiceId, CMU_E_UNINIT);
    }
    else
    {
        if (FALSE == Cmu_CheckCmuId(CmuId))
        {
            CheckStatus = FALSE;
            (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, ServiceId,
                                  CMU_E_PARAM_INVALID);
        }
    }

    return CheckStatus;
}

/**
 * @brief      Checks whether current clock monitor is in measure mode.
 *
 * @param[in]  CmuId: The given CMU id.
 * @param[in]  ServiceId: Service to be executed.
 *
 * @return    boolean
 * @retval    TRUE: The clock is in measure mode.
 * @retval    FALSE: The clock is not in measure mode.
 *
 */
static boolean Cmu_CheckMeasureMode(Cmu_IdType CmuId, uint8 ServiceId)
{
    boolean CheckStatus = TRUE;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
    if (CMU_MEASURE_MODE != (Cmu_ModeType)Cmu_Drv_GetMode(CmuMonitorId))
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, ServiceId,
                              CMU_E_INVALID_MODE);
    }

    return CheckStatus;
}

/**
 * @brief      Checks status to execute get clock monitor mode.
 *
 * @param[in]  CmuModePtr: Pointer to store clock monitor mode.
 *
 * @return    boolean
 * @retval    TRUE:  Get clock monitor mode service is ready to execute.
 * @retval    FALSE: Get clock monitor mode service is not ready to execute.
 *
 */
static boolean Cmu_CheckGetClockMonitorMode(const Cmu_ModeType *CmuModePtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == CmuModePtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID,
                              CMU_SID_GET_CLOCK_MONITOR_MODE, CMU_E_NULL_POINTER);
    }

    return CheckStatus;
}

/**
 * @brief      Checks status to execute get measure status.
 *
 * @param[in]  MeasureStatusPtr: Pointer to store measure status.
 *
 * @return    boolean
 * @retval    TRUE:  Get measure status service is ready to execute.
 * @retval    FALSE: Get measure status service is not ready to execute.
 *
 */
static boolean Cmu_CheckGetMeasureStatus(const boolean *MeasureStatusPtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == MeasureStatusPtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, CMU_SID_GET_MEASURE_STATUS,
                              CMU_E_NULL_POINTER);
    }

    return CheckStatus;
}

/**
 * @brief      Checks status to execute get measure result.
 *
 * @param[in]  MeaureResultPtr: Pointer to store the measure result.
 *
 * @return    boolean
 * @retval    TRUE:  Get measure result service is ready to execute.
 * @retval    FALSE: Get measure result service is not ready to execute.
 *
 */
static boolean Cmu_CheckGetMeasureResult(const uint32 *MeaureResultPtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == MeaureResultPtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, CMU_SID_GET_MEASURE_RESULT,
                              CMU_E_NULL_POINTER);
    }

    return CheckStatus;
}

/**
 * @brief      Checks status to execute get clock monitor state.
 *
 * @param[in]  CmuStatePtr: Pointer to store the state.
 *
 * @return    boolean
 * @retval    TRUE:  Get clock monitor state service is ready to execute.
 * @retval    FALSE: Get clock monitor state service is not ready to execute.
 *
 */
static boolean Cmu_CheckGetClockMonitorState(const Cmu_StateType *CmuStatePtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == CmuStatePtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID,
                              CMU_SID_GET_CLOCK_MONITOR_STATE, CMU_E_NULL_POINTER);
    }

    return CheckStatus;
}


#endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */

#if ((CMU_VERSION_INFO_API == STD_ON) && (CMU_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief      Checks status to execute get version info service.
 *
 * @param[in]  VersionInfoPtr: Pointer to store the software version info.
 *
 * @return    boolean
 * @retval    TRUE:  Get version info service is ready to execute.
 * @retval    FALSE: Get version info service is not ready to execute.
 *
 */
static boolean Cmu_CheckGetVersionInfo(const Std_VersionInfoType *VersionInfoPtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == VersionInfoPtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)CMU_MODULE_ID, CMU_INSTANCE_ID, CMU_SID_GET_VERSION_INFO,
                              CMU_E_NULL_POINTER);
    }

    return CheckStatus;
}
#endif /* ((CMU_VERSION_INFO_API == STD_ON) && (CMU_DEV_ERROR_DETECT == STD_ON)) */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief     Initializes the Cmu driver.
 *
 * @param[in] ConfigPtr: Pointer to Cmu driver configuration set.
 *
 * @return    None
 *
 */
void Cmu_Init(const Cmu_ConfigType *ConfigPtr)
{
    uint8 Index = 0U;

#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckInit(ConfigPtr))
    {
#endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */

#if (CMU_PRECOMPILE_SUPPORT == STD_ON)
        Cmu_ConfigPtr = Cmu_PreDefinedConfigPtr;
        (void)(ConfigPtr);
#else
    Cmu_ConfigPtr = ConfigPtr;
#endif /* (CMU_PRECOMPILE_SUPPORT == STD_ON) */

        for (Index = 0; Index < Cmu_ConfigPtr->NumberOfConfigedCmu; ++Index)
        {
            Cmu_Drv_Init(&(Cmu_ConfigPtr->SysCmuConfigPtr[Index]));
            Cmu_MonitorMappingArray[Cmu_ConfigPtr->SysCmuConfigPtr[Index].CmuId] = 
                                            Cmu_ConfigPtr->SysCmuConfigPtr[Index].ClockMonitorId;
        }
#if (CMU_DEV_ERROR_DETECT == STD_ON)
        Cmu_Status = CMU_INIT;
    }
    else
    {
        /* Clean the configuration pointer in case of an error. */
        Cmu_ConfigPtr = NULL_PTR;
    }
#endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief      Sets the given clock monitor state(Enabled/Disabled).
 *
 * @param[in]  CmuId: The given CMU id.
 * @param[in]  Enable: Enable or disable.
 *
 * @return    Std_ReturnType
 * @retval    - E_OK:       The command is executed successfully.
 * @retval    - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_SetClockMonitorState(Cmu_IdType CmuId, boolean Enable)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckExecuteService(CmuId, CMU_SID_SET_CLOCK_MONITOR_STATE))
    {
#endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */
        if (TRUE == Enable)
        {
            Cmu_Drv_Enable(CmuMonitorId);
        }
        else
        {
            Cmu_Drv_Disable(CmuMonitorId);
        }
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        Status = (Std_ReturnType)E_NOT_OK;
    }
#endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */

    return Status;
}

#if (CMU_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersionInfo: Pointer to where to store the version information of this module.
 * 
 * @return    None.
 *
 */
void Cmu_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
    #if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckGetVersionInfo(VersionInfo))
    {
    #endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */
        (VersionInfo)->vendorID = (uint16)CMU_VENDOR_ID;
        (VersionInfo)->moduleID = (uint16)CMU_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8)CMU_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8)CMU_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8)CMU_SW_PATCH_VERSION;
    #if (CMU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (CMU_DEV_ERROR_DETECT == STD_ON) */
}
#endif     /* (CMU_VERSION_INFO_API == STD_ON) */

/**
 * @brief        Gets the given clock monitor current mode.
 *
 * @param[in]    CmuId: The given CMU id.
 * @param[out]   CmuModePtr: Pointer to store clock monitor mode.
 *
 * @return       Std_ReturnType
 * @retval       - E_OK:       The command is executed successfully.
 * @retval       - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetClockMonitorMode(const Cmu_IdType CmuId, Cmu_ModeType *CmuModePtr)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckExecuteService(CmuId, CMU_SID_GET_CLOCK_MONITOR_MODE))
    {
        if (TRUE == Cmu_CheckGetClockMonitorMode(CmuModePtr))
        {
#endif
            *CmuModePtr = (Cmu_ModeType)Cmu_Drv_GetMode(CmuMonitorId);
#if (CMU_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        Status = (Std_ReturnType)E_NOT_OK;
    }
#endif
    return Status;
}

/**
 * @brief      Sets the given clock monitor mode.
 *
 * @param[in]  CmuId: The given CMU ID.
 * @param[in]  CmuMode: The given CMU mode.
 *
 * @return     Std_ReturnType
 * @retval     - E_OK:       The command is executed successfully.
 * @retval     - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_SetClockMonitorMode(const Cmu_IdType CmuId, const Cmu_ModeType CmuMode)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckExecuteService(CmuId, CMU_SID_SET_CLOCK_MONITOR_MODE))
    {
#endif
        Cmu_Drv_SetMode(CmuMonitorId, (Cmu_Drv_ModeType)CmuMode);
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        Status = (Std_ReturnType)E_NOT_OK;
    }
#endif

    return Status;
}

/**
 * @brief      Starts the measure of the given clock monitor.
 *
 * @param[in]  CmuId: The given CMU id.
 *
 * @return     Std_ReturnType
 * @retval     - E_OK:       The command is executed successfully.
 * @retval     - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_StartMeasure(Cmu_IdType CmuId)
{
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckExecuteService(CmuId, CMU_SID_START_MEASURE))
    {
        if (TRUE == Cmu_CheckMeasureMode(CmuId, CMU_SID_START_MEASURE))
        {
#endif
            Cmu_Drv_StartMeasure(CmuMonitorId);
            Status = (Std_ReturnType)E_OK;
#if (CMU_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif

    return Status;
}

/**
 * @brief       Gets the measure status.
 *
 * @param[in]   CmuId: The given CMU id.
 * @param[out]  MeasureStatusPtr: Pointer to store meaure status.
 *
 * @return      Std_ReturnType
 * @retval      - E_OK:     The command is executed successfully.
 * @retval      - E_NOT_OK: The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetMeasureStatus(Cmu_IdType CmuId, boolean *MeasureStatusPtr)
{
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckExecuteService(CmuId, CMU_SID_GET_MEASURE_STATUS))
    {
        if (TRUE == Cmu_CheckGetMeasureStatus(MeasureStatusPtr))
        {
            if (TRUE == Cmu_CheckMeasureMode(CmuId, CMU_SID_GET_MEASURE_STATUS))
            {
#endif
                *MeasureStatusPtr = Cmu_Drv_GetMeasureCompleteStatus(CmuMonitorId);
                Status = (Std_ReturnType)E_OK;
#if (CMU_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif

    return Status;
}

/**
 * @brief      Gets measure result when CMU is working in measure mode.
 * @note       User needs to make sure the measure is completed before calling this function,
 * otherwise the return value is incorrect.
 *
 * @param[in]   CmuId: The given CMU id.
 * @param[out]  MeaureResultPtr: Pointer to store the measure result.
 *
 * @return    Std_ReturnType
 * @retval    - E_OK:     The command is executed successfully.
 * @retval    - E_NOT_OK: The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetMeasureResult(Cmu_IdType CmuId, uint32 *MeaureResultPtr)
{
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckExecuteService(CmuId, CMU_SID_GET_MEASURE_RESULT))
    {
        if (TRUE == Cmu_CheckGetMeasureResult(MeaureResultPtr))
        {
            if (TRUE == Cmu_CheckMeasureMode(CmuId, CMU_SID_GET_MEASURE_RESULT))
            {
#endif
                *MeaureResultPtr = Cmu_Drv_GetMeasureResult(CmuMonitorId);
                Status = (Std_ReturnType)E_OK;
#if (CMU_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif

    return Status;
}

/**
 * @brief        Gets the given clock monitor state.
 *
 * @param[in]    CmuId: The given CMU id.
 * @param[out]   CmuStatePtr: Pointer to store the state.
 *
 * @return       Std_ReturnType
 * @retval       - E_OK:     The command is executed successfully.
 * @retval       - E_NOT_OK: The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetClockMonitorState(Cmu_IdType CmuId, Cmu_StateType *CmuStatePtr)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Cmu_Drv_IdType CmuMonitorId = Cmu_MonitorMappingArray[CmuId];
#if (CMU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Cmu_CheckExecuteService(CmuId, CMU_SID_GET_CLOCK_MONITOR_STATE))
    {
        if (TRUE == Cmu_CheckGetClockMonitorState(CmuStatePtr))
        {
#endif
            *CmuStatePtr = (Cmu_StateType)Cmu_Drv_GetState(CmuMonitorId);
#if (CMU_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        Status = (Std_ReturnType)E_NOT_OK;
    }
#endif

    return Status;
}

/** @} end of group Public_FunctionDefinition */

#define CMU_STOP_SEC_CODE
#include "Cmu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Cmu */

/** @} end of group Cmu_Module */
