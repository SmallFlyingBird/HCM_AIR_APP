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
*   @internal
*   @addtogroup Platform_Mld
*   @{
*/

/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 3344  Rule-14.4: The controlling expression of an if-statement and the controlling expression
 *                         of an iteration-statement shall have essentially Boolean type
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_Types.h"
#include "Platform_TypesDef.h"
#include "Platform_Mld.h"
#include "System_Lld.h"
#if (STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT)
#include "OsIf.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_MLD_VENDOR_ID_C                         (180)
#define PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION_C          (4)
#define PLATFORM_MLD_AR_RELEASE_MINOR_VERSION_C          (4)
#define PLATFORM_MLD_AR_RELEASE_REVISION_VERSION_C       (0)
#define PLATFORM_MLD_SW_MAJOR_VERSION_C                  (2)
#define PLATFORM_MLD_SW_MINOR_VERSION_C                  (3)
#define PLATFORM_MLD_SW_PATCH_VERSION_C                  (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_TypesDef header file are of the same vendor */
#if (PLATFORM_MLD_VENDOR_ID_C != PLATFORM_TYPESDEF_VENDOR_ID)
#error "Platform_Mld.c and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Autosar version */
#if ((PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MLD_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MLD_AR_RELEASE_REVISION_VERSION_C != PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Platform_Mld.c and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_Mld_Cfg header file are of the same Software version */
#if ((PLATFORM_MLD_SW_MAJOR_VERSION_C != PLATFORM_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_SW_MINOR_VERSION_C != PLATFORM_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_SW_PATCH_VERSION_C != PLATFORM_TYPESDEF_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld.c and Platform_TypesDef.h are different"
#endif


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Mld.header file are of the same vendor */
#if (PLATFORM_MLD_VENDOR_ID_C != PLATFORM_MLD_CFG_VENDOR_ID)
#error "Platform_Mld.c and Platform_Mld.h have different vendor ids"
#endif
/* Check if current file and Platform_Mld.header file are of the same Autosar version */
#if ((PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MLD_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_MLD_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MLD_AR_RELEASE_REVISION_VERSION_C != PLATFORM_MLD_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Platform_Mld.c and Platform_Mld.h are different"
#endif
/* Check if current file and Platform_Mld.header file are of the same Software version */
#if ((PLATFORM_MLD_SW_MAJOR_VERSION_C != PLATFORM_MLD_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_SW_MINOR_VERSION_C != PLATFORM_MLD_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_SW_PATCH_VERSION_C != PLATFORM_MLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld.c and Platform_Mld.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Platform_Mld.c header file are of the same Autosar version */
/* #if ((PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MLD_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Mld.c and Mcal.h are different"
#endif    */
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if ((STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
#define Call_System_Mld_ConfigIrq(Irq,Enable)          OsIf_Trusted_Call2params(System_Lld_ConfigIrq,(Irq),(Enable))
#else
#define Call_System_Mld_ConfigIrq(Irq,Enable)          System_Lld_ConfigIrq((Irq),(Enable))
#endif

PLATFORM_FUNC static Std_ReturnType Platform_Mld_InitIntCtrl(const IntCtrl_Lld_CtrlConfigType *IntCtrlCtrlConfig)
{
    for (uint32 IrqIndex = 0; IrqIndex < IntCtrlCtrlConfig->ConfigIrqCount; ++IrqIndex)
    {
        /* interrupt number for which the priority is set */
        IntCtrl_Lld_SetPriority(IntCtrlCtrlConfig->IrqConfig[IrqIndex].IrqNumber,
                                IntCtrlCtrlConfig->IrqConfig[IrqIndex].IrqPriority);
        /* Enable interrupt */
        if (TRUE == IntCtrlCtrlConfig->IrqConfig[IrqIndex].IrqEnabled)
        {
            /* enables the interrupt request at interrupt controller level. */
            IntCtrl_Lld_EnableIrq(IntCtrlCtrlConfig->IrqConfig[IrqIndex].IrqNumber);
        }
        else
        {
            /* disables the interrupt request at interrupt controller level.*/
            IntCtrl_Lld_DisableIrq(IntCtrlCtrlConfig->IrqConfig[IrqIndex].IrqNumber);
        }
    }

    return E_OK;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the platform settings based on user configuration.
 */
PLATFORM_FUNC Std_ReturnType Platform_Mld_Init(const Platform_Mld_ConfigType *Config)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    /* Initialize interrupts at interrupt controller level */
    if (NULL_PTR != Config->IntCtrlConfig)
    {
        Ret = Platform_Mld_InitIntCtrl(Config->IntCtrlConfig);

        if ((Std_ReturnType)E_OK == Ret)
        {
#if (SYSTEM_FPU_CFG == STD_ON)
            if (NULL_PTR != Config->SystemConfig)
            {
#if (PLATFORM_SYS_CFG == STD_ON)
                /* Configure core-related interrupt requests */
                for (uint8 IrqIndex = 0u; IrqIndex < (Config->SystemConfig)->SysIrqsCount; ++IrqIndex)
                {
                    Call_System_Mld_ConfigIrq((Config->SystemConfig)->SystemIrqs[IrqIndex].Irq, (Config->SystemConfig)->SystemIrqs[IrqIndex].Enable);
                }
                /* Call_System_Lld_SetAhbSlavePriority((Config->SystemConfig)->AhbSlavePriority); */
#endif
            }
            else
            {
                Ret = E_NOT_OK;
            }
#endif
        }
        else
        {
            /* compliance to MISRA C-2012 */
        }

    }
    else
    {
        Ret = E_NOT_OK;
    }

#if (PLATFORM_INT_MONITOR == STD_ON)

    if (NULL_PTR != Config->IntMonitorConfig)
    {
        /* Configure interrupt monitors */
        for (uint8 IntmIdx = 0u; IntmIdx < (Config->IntMonitorConfig)->ChannelNum; ++IntmIdx)
        {
            Intm_Lld_SelectMonitoredIrq(Config->IntMonitorConfig->IntmChannelConfig[IntmIdx].Monitor, \
                                        Config->IntMonitorConfig->IntmChannelConfig[IntmIdx].MonitoredIrq);
            Intm_Lld_SetLatency(Config->IntMonitorConfig->IntmChannelConfig[IntmIdx].Monitor, \
                                Config->IntMonitorConfig->IntmChannelConfig[IntmIdx].AcceptedLatency);
        }
        if (Config->IntMonitorConfig->IntmGenericConfig != NULL_PTR)
        {
            /*
                *  Rule 14.4 VIOLATION: The EnableIntMonitor is not Boolean but a boolean type defined in Platform_Types.h as AUTOSAR required:
                *                       typedef unsigned char   boolean;
            *                       So, there is no risk for such use here
                */
            if (Config->IntMonitorConfig->IntmGenericConfig->EnableIntMonitor) /* PRQA S 3344 */
            {
                Intm_Lld_EnableMonitor();
            }
            else
            {
                Intm_Lld_DisableMonitor();
            }
        }
    }
    else
    {
        Ret = E_NOT_OK;
    }

#endif

    return Ret;
}

#if (PLATFORM_MSCM_CFG == STD_ON)
/**
 * @brief         Initializes the platform settings for non-core elements  based on user configuration.
 */

PLATFORM_FUNC void Platform_Mld_InitNonCore(const Platform_Mld_NonCoreConfigType *Config)
{
    uint32 IrqIndex;
    if (Config -> IntRouteConfig != NULL_PTR)
    {
        for (IrqIndex = 0; IrqIndex < (Config -> IntRouteConfig) -> ConfigIrqCount ; IrqIndex++)
        {
            IntCtrl_Lld_ClearPending(Config -> IntRouteConfig->IrqConfig[IrqIndex].IrqNumber);
            IntCtrl_Lld_InstallHandler(Config -> IntRouteConfig->IrqConfig[IrqIndex].IrqNumber,
                                       Config -> IntRouteConfig->IrqConfig[IrqIndex].Handler,
                                       NULL_PTR);
        }
    }
}
#endif

#if (PLATFORM_INT_MONITOR == STD_ON)
/**
 * @internal
 * @brief         Enables/disables interrupt monitoring feature by calling the Interrupt Monitor IP layer.
 */
PLATFORM_FUNC void Platform_Mld_SetIrqMonitor(boolean Enable)
{
    if (TRUE == Enable)
    {
        Intm_Lld_EnableMonitor();
    }
    else
    {
        Intm_Lld_DisableMonitor();
    }
}


/**
 * @internal
 * @brief         Selects an interrupt to be monitored by calling the Interrupt Monitor IP layer.
 */
PLATFORM_FUNC void Platform_Mld_SelectMonitoredIrq(uint8 Channel, IRQn_Type IrqNumber)
{
    Intm_Lld_SelectMonitoredIrq((Intm_Lld_MonitorType)Channel, IrqNumber);
}

/**
 * @internal
 * @brief         Selects an accepted latency for a monitored interrupt
 *                by calling the Interrupt Monitor IP layer.
 */
PLATFORM_FUNC void Platform_Mld_SetMonitoredIrqLatency(uint8 Channel, uint32 Latency)
{
    Intm_Lld_SetLatency((Intm_Lld_MonitorType)Channel, Latency);
}

/**
 * @internal
 * @brief         Resets an interrupt monitor timer by calling the Interrupt Monitor IP layer.
 */
PLATFORM_FUNC void Platform_Mld_ResetIrqMonitorTimer(uint8 Channel)
{
    Intm_Lld_ResetTimer((Intm_Lld_MonitorType)Channel);
}


/**
 * @internal
 * @brief         Returns the status of an interrupt monitor by calling the Interrupt Monitor IP layer.
 */
PLATFORM_FUNC boolean Platform_Mld_GetIrqMonitorStatus(uint8 Channel)
{
    boolean RetVal = TRUE;

    if (0U == Intm_Lld_GetStatus((Intm_Lld_MonitorType)Channel))
    {
        RetVal = FALSE;
    }
    else
    {
        RetVal = TRUE;
    }

    return RetVal;
}

/**
 * @internal
 * @brief         Returns the validation result for given logical channel.
 */
PLATFORM_FUNC Std_ReturnType Platform_Mld_ValidateChannelIntm(const Platform_Mld_ConfigType *Config,
        uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if (Channel <= (Config->IntMonitorConfig->ChannelNum))
    {
        RetVal = E_OK;
    }
    else
    {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

/**
 * @internal
 * @brief         Returns the the possibility of setting interrupt monitor enabling.
 */
PLATFORM_FUNC Std_ReturnType Platform_Mld_ValidateSetIrqMonitor(const Platform_Mld_ConfigType *Config)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if (Config->IntMonitorConfig->IntmGenericConfig != NULL_PTR)
    {
        RetVal = E_OK;
    }
    return RetVal;
}
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

