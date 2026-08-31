/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
 *   @file
 *
 *   @addtogroup Platform
 *   @{
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform.h"
#include "Platform_Mld.h"
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_MAIN_VENDOR_ID_C                     (180)
#define PLATFORM_MAIN_AR_RELEASE_MAJOR_VERSION_C      (4)
#define PLATFORM_MAIN_AR_RELEASE_MINOR_VERSION_C      (4)
#define PLATFORM_MAIN_AR_RELEASE_REVISION_VERSION_C   (0)
#define PLATFORM_MAIN_SW_MAJOR_VERSION_C              (2)
#define PLATFORM_MAIN_SW_MINOR_VERSION_C              (3)
#define PLATFORM_MAIN_SW_PATCH_VERSION_C              (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform header file are of the same vendor */
#if (PLATFORM_MAIN_VENDOR_ID_C != PLATFORM_MAIN_VENDOR_ID)
#error "Platform.c and Platform.h have different vendor ids"
#endif
/* Check if current file and Platform header file are of the same Autosar version */
#if ((PLATFORM_MAIN_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_MAIN_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MAIN_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_MAIN_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MAIN_AR_RELEASE_REVISION_VERSION_C != PLATFORM_MAIN_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Platform.c and Platform.h are different"
#endif
/* Check if current file and Platform header file are of the same Software version */
#if ((PLATFORM_MAIN_SW_MAJOR_VERSION_C != PLATFORM_MAIN_SW_MAJOR_VERSION) || \
     (PLATFORM_MAIN_SW_MINOR_VERSION_C != PLATFORM_MAIN_SW_MINOR_VERSION) || \
     (PLATFORM_MAIN_SW_PATCH_VERSION_C != PLATFORM_MAIN_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform.c and Platform.h are different"
#endif


/* Check if current file and Platform_Mld.header file are of the same vendor */
#if (PLATFORM_MAIN_VENDOR_ID_C != PLATFORM_MLD_VENDOR_ID)
#error "Platform.c and Platform_Mld.h have different vendor ids"
#endif
/* Check if current file and Platform_Mld.header file are of the same Autosar version */
#if ((PLATFORM_MAIN_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MAIN_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_MLD_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MAIN_AR_RELEASE_REVISION_VERSION_C != PLATFORM_MLD_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Platform.c and Platform_Mld.h are different"
#endif
/* Check if current file and Platform_Mld.header file are of the same Software version */
#if ((PLATFORM_MAIN_SW_MAJOR_VERSION_C != PLATFORM_MLD_SW_MAJOR_VERSION) || \
     (PLATFORM_MAIN_SW_MINOR_VERSION_C != PLATFORM_MLD_SW_MINOR_VERSION) || \
     (PLATFORM_MAIN_SW_PATCH_VERSION_C != PLATFORM_MLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform.c and Platform_Mld.h are different"
#endif

/*==================================================================================================
 *                                          LOCAL MACROS
==================================================================================================*/
#define EXCEPTION_NUMBER_OFFSET 14

/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/

#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

PLATFORM_CONST extern const Platform_ConfigType *const Platform_Config[PLATFORM_MAX_PARTITIONS];

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/*==================================================================================================
                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if (PLATFORM_INT_MONITOR == STD_ON)
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
PLATFORM_FUNC static Std_ReturnType Platform_CheckNullPtrCfg(uint8 CoreId);
#endif
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if (PLATFORM_INT_MONITOR == STD_ON)
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
PLATFORM_FUNC static Std_ReturnType Platform_CheckNullPtrCfg(uint8 CoreId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    /*Checking number of configuration and number of Interrupt controller */
    if ((NULL_PTR != (Platform_Config[CoreId])) && (NULL_PTR != (Platform_Config[CoreId] -> MldConfig)))
    {
        /* if NullPtrCfg is different NULL_PTR then RetVal variable is E_OK*/
        RetVal = E_OK;
    }
    return RetVal;
}
#endif
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @internal
 * @brief         Initializes the platform settings based on user configuration.
 * @implements    Platform_Init_Activity
 */
PLATFORM_FUNC void Platform_Init(const Platform_ConfigType *Config)
{
    uint8 CoreId;

    CoreId = Platform_GetCoreID();

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Platform_Config[CoreId] -> MldConfig)
    {
        (void)Det_ReportError((uint16)PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_INIT_ID, PLATFORM_E_PARAM_POINTER);
    }
    else
    {
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        if (NULL_PTR == (Platform_Config[CoreId]))
        {
            (void)Det_ReportError((uint16)PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_INIT_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
#endif /*(PLATFORM_MULTICORE_SUPPORT == STD_ON)*/
#endif /*(PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

#if (PLATFORM_MSCM_CFG == STD_ON)
            Platform_Mld_InitNonCore(Platform_Config[CoreId] -> MldNonCoreConfig);
#endif /* (PLATFORM_MSCM_CFG == STD_ON) */

            (void)Platform_Mld_Init(Platform_Config[CoreId] -> MldConfig);

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        }
#endif /*(PLATFORM_MULTICORE_SUPPORT == STD_ON)*/
    }
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

    (void)CoreId;  /* avoid compile warning */
    (void)Config;   /* avoid compile warning */
}

/**
 * @internal
 * @brief         Configures (enables/disables) an interrupt request.
 * @implements    Platform_SetIrq_Activity
 */
PLATFORM_FUNC Std_ReturnType Platform_SetIrq(IRQn_Type IrqNumber, boolean Enable)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INT_CTRL_LLD_IRQ_MAX) || \
            ((sint32)INT_CTRL_LLD_IRQ_MIN > (sint32)IrqNumber))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SET_IRQ_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        Platform_Mld_SetIrq(IrqNumber, Enable);
    }
    return RetValue;
}

/**
 * @internal
 * @brief         Configures the priority of an interrupt request.
 * @implements    Platform_SetIrqPriority_Activity
 */
PLATFORM_FUNC Std_ReturnType Platform_SetIrqPriority(IRQn_Type IrqNumber, uint8 Priority)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INT_CTRL_LLD_IRQ_MAX) || \
            ((sint32)INT_CTRL_LLD_IRQ_MIN > (sint32)IrqNumber) || \
            (Priority >= (uint8)(1U << INT_CTRL_LLD_NVIC_PRIO_BITS)))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SET_IRQ_PRIO_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        Platform_Mld_SetIrqPriority(IrqNumber, Priority);
    }
    return RetValue;
}

/**
 * @internal
 * @brief         Returns the priority of an interrupt request.
 * @implements    Platform_GetIrqPriority_Activity
 */
PLATFORM_FUNC Std_ReturnType Platform_GetIrqPriority(IRQn_Type IrqNumber, uint8 *Priority)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INT_CTRL_LLD_IRQ_MAX) || \
            ((sint32)INT_CTRL_LLD_IRQ_MIN > (sint32)IrqNumber))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_GET_IRQ_PRIO_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == Priority)
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_GET_IRQ_PRIO_ID, PLATFORM_E_PARAM_POINTER);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        *Priority = Platform_Mld_GetIrqPriority(IrqNumber);
    }

    return RetValue;
}

/**
 * @internal
 * @brief         Installs a new handler for an interrupt request.
 * @implements    Platform_InstallIrqHandler_Activity
 */
PLATFORM_FUNC Std_ReturnType Platform_InstallIrqHandler(IRQn_Type IrqNumber,
        const Platform_IrqHandlerType NewHandler,
        Platform_IrqHandlerType *const OldHandler)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INT_CTRL_LLD_IRQ_MAX) || \
            ((sint32)INT_CTRL_LLD_IRQ_MIN > (sint32)((sint32)IrqNumber + EXCEPTION_NUMBER_OFFSET)))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_INSTALL_HANDLER_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == OldHandler)
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_INSTALL_HANDLER_ID, PLATFORM_E_PARAM_POINTER);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        Platform_Mld_InstallIrqHandler(IrqNumber, NewHandler, OldHandler);
    }
    return RetValue;
}

#if (PLATFORM_INT_MONITOR == STD_ON)
/**
 * @internal
 * @brief         Configures (enables/disables) the interrupt monitor.
 * @implements    Platform_SetIrqMonitor_Activity
 */
PLATFORM_FUNC void Platform_SetIrqMonitor(boolean Enable)
{
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    uint8 CoreId;

    CoreId = (uint8)Platform_GetCoreID();
    if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(CoreId))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SET_IRQ_MONITOR_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else
    {
        if ((Std_ReturnType)E_NOT_OK == Platform_Mld_ValidateSetIrqMonitor(Platform_Config[CoreId] -> MldConfig))
        {
            (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SET_IRQ_MONITOR_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
#endif
            Platform_Mld_SetIrqMonitor(Enable);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}

/**
 * @internal
 * @brief         Acknowledges a monitored interrupt has been served.
 * @implements    Platform_AckIrq_Activity
 */
PLATFORM_FUNC void Platform_AckIrq(IRQn_Type IrqNumber)
{
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INT_CTRL_LLD_IRQ_MAX) || \
            ((sint32)INT_CTRL_LLD_IRQ_MIN > (sint32)IrqNumber))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_ACK_IRQ_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else
    {
#endif
        Platform_Mld_AckIrq(IrqNumber);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    }
#endif


}

/**
 * @internal
 * @brief         Selects an interrupt to monitor.
 * @implements    Platform_SelectMonitoredIrq_Activity
 */
PLATFORM_FUNC void Platform_SelectMonitoredIrq(uint8 Channel, IRQn_Type IrqNumber)
{
    uint8 CoreId;

    CoreId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INT_CTRL_LLD_IRQ_MAX) || \
            ((sint32)INT_CTRL_LLD_IRQ_MIN > (sint32)IrqNumber) ||
            (Channel >= PLATFORM_INT_MONITOR_CNT))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SELECT_MONITORED_IRQ_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else
    {
        if ((Std_ReturnType)E_OK == Platform_CheckNullPtrCfg(CoreId))
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Mld_ValidateChannelIntm(Platform_Config[CoreId] -> MldConfig, Channel))
            {
                (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SELECT_MONITORED_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                Platform_Mld_SelectMonitoredIrq(Channel, IrqNumber);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
        else
        {
            (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SELECT_MONITORED_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
        }
    }
#endif
}

/**
 * @internal
 * @brief         Sets the latency for a monitored interrupt.
 * @implements    Platform_SetMonitoredIrqLatency_Activity
 */
PLATFORM_FUNC void Platform_SetMonitoredIrqLatency(uint8 Channel, uint32 Latency)
{
    uint8 CoreId;

    CoreId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if ((Latency > PLATFORM_INT_MONITOR_MAX_LATENCY) ||
            (Channel >= PLATFORM_INT_MONITOR_CNT))
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SET_MONITORED_IRQ_LATENCY_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else
    {
        if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(CoreId))
        {
            (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SET_MONITORED_IRQ_LATENCY_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Mld_ValidateChannelIntm(Platform_Config[CoreId] -> MldConfig, Channel))
            {
                (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_SET_MONITORED_IRQ_LATENCY_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                Platform_Mld_SetMonitoredIrqLatency(Channel, Latency);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif
}
/**
 * @internal
 * @brief         Resets the timer for an interrupt monitor.
 * @implements    Platform_ResetIrqMonitorTimer_Activity
 */
PLATFORM_FUNC void Platform_ResetIrqMonitorTimer(uint8 Channel)
{
    uint8 CoreId;

    CoreId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (Channel >= PLATFORM_INT_MONITOR_CNT)
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_RESET_IRQ_MONITOR_TIMER_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else
    {
        if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(CoreId))
        {
            (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_RESET_IRQ_MONITOR_TIMER_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Mld_ValidateChannelIntm(Platform_Config[CoreId] -> MldConfig, Channel))
            {
                (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_RESET_IRQ_MONITOR_TIMER_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                Platform_Mld_ResetIrqMonitorTimer(Channel);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif
}

/**
 * @internal
 * @brief         Retrieves the status of an interrupt monitor.
 * @implements    Platform_GetIrqMonitorStatus_Activity
 */
PLATFORM_FUNC Std_ReturnType Platform_GetIrqMonitorStatus(uint8 Channel, boolean *LatencyExceeded)
{
    uint8 CoreId;
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

    CoreId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (Channel >= PLATFORM_INT_MONITOR_CNT)
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else if (NULL_PTR == LatencyExceeded)
    {
        (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_POINTER);
    }
    else
    {
        if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(CoreId))
        {
            (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Mld_ValidateChannelIntm(Platform_Config[CoreId] -> MldConfig, Channel))
            {
                (void)Det_ReportError(PLATFORM_MAIN_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                *LatencyExceeded = Platform_Mld_GetIrqMonitorStatus(Channel);
                RetVal = (Std_ReturnType)E_OK;
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif
    return RetVal;
}
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} */

