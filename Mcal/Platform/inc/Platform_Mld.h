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

#ifndef PLATFORM_MLD_H_
#define PLATFORM_MLD_H_

/**
*   @file
*
*   @internal
*   @addtogroup Platform_Mld
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_Mld_Cfg.h"
#include "IntCtrl_Lld.h"
#include "Platform_Types.h"
#include "System_Lld.h"
#include "IntCtrl_Lld_CfgDefines.h"

#if (PLATFORM_INT_MONITOR == STD_ON)
#include "Intm_Lld.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_MLD_VENDOR_ID                         (180)
#define PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION          (4)
#define PLATFORM_MLD_AR_RELEASE_MINOR_VERSION          (4)
#define PLATFORM_MLD_AR_RELEASE_REVISION_VERSION       (0)
#define PLATFORM_MLD_SW_MAJOR_VERSION                  (2)
#define PLATFORM_MLD_SW_MINOR_VERSION                  (3)
#define PLATFORM_MLD_SW_PATCH_VERSION                  (0)
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Mld_Cfg header file are of the same vendor */
#if (PLATFORM_MLD_VENDOR_ID != PLATFORM_MLD_CFG_VENDOR_ID)
#error "Platform_Mld.h and Platform_Mld_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Mld_Cfg header file are of the same Autosar version */
#if ((PLATFORM_MLD_AR_RELEASE_MAJOR_VERSION    != PLATFORM_MLD_CFG_AR_MAJOR_VERSION) || \
     (PLATFORM_MLD_AR_RELEASE_MINOR_VERSION    != PLATFORM_MLD_CFG_AR_MINOR_VERSION) || \
     (PLATFORM_MLD_AR_RELEASE_REVISION_VERSION != PLATFORM_MLD_CFG_AR_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Platform_Mld.h and Platform_Mld_Cfg.h are different"
#endif
/* Check if current file and Platform_Mld_Cfg header file are of the same Software version */
#if ((PLATFORM_MLD_SW_MAJOR_VERSION != PLATFORM_MLD_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_SW_MINOR_VERSION != PLATFORM_MLD_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_SW_PATCH_VERSION != PLATFORM_MLD_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld.h and Platform_Mld_Cfg.h are different"
#endif


/* Check if current file and IntCtrl_Lld header file are of the same vendor */
#if (PLATFORM_MLD_VENDOR_ID != PLATFORM_INTCTRL_LLD_VENDOR_ID)
#error "Platform_Mld.h and IntCtrl_Lld.h have different vendor ids"
#endif

/* Check if current file and IntCtrl_Lld header file are of the same Software version */
#if ((PLATFORM_MLD_SW_MAJOR_VERSION != PLATFORM_INTCTRL_LLD_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_SW_MINOR_VERSION != PLATFORM_INTCTRL_LLD_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_SW_PATCH_VERSION != PLATFORM_INTCTRL_LLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld.h and IntCtrl_Lld.h are different"
#endif

#if (PLATFORM_INT_MONITOR == STD_ON)
/* Check if current file and Intm_Lld header file are of the same vendor */
#if (PLATFORM_MLD_VENDOR_ID != INTM_LLD_VENDOR_ID)
#error "Platform_Mld.h and Intm_Lld.h have different vendor ids"
#endif

/* Check if current file and Intm_Lld header file are of the same Software version */
#if ((PLATFORM_MLD_SW_MAJOR_VERSION != INTM_LLD_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_SW_MINOR_VERSION != INTM_LLD_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_SW_PATCH_VERSION != INTM_LLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld.h and Intm_Lld.h are different"
#endif
#endif

/* Check if current file and System_Lld header file are of the same vendor */
#if (PLATFORM_MLD_VENDOR_ID != PLATFORM_SYSTEM_LLD_VENDOR_ID)
#error "Platform_Mld.h and System_Lld.h have different vendor ids"
#endif

/* Check if current file and System_Lld header file are of the same Software version */
#if ((PLATFORM_MLD_SW_MAJOR_VERSION != PLATFORM_SYSTEM_LLD_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_SW_MINOR_VERSION != PLATFORM_SYSTEM_LLD_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_SW_PATCH_VERSION != PLATFORM_SYSTEM_LLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform_Mld.h and System_Lld.h are different"
#endif

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
extern uint32 VTABLE[((uint32)(INT_CTRL_LLD_IRQ_MAX)) + 16U + 1U];

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * @internal
 * @brief         Initializes the platform settings based on user configuration.
 */
Std_ReturnType Platform_Mld_Init(const Platform_Mld_ConfigType *Config);

#if (PLATFORM_MSCM_CFG == STD_ON)
/**
 * @internal
 * @brief         Initializes the platform settings for non-core elements based on user configuration.
 */
void Platform_Mld_InitNonCore(const Platform_Mld_NonCoreConfigType *Config);
#endif

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @internal
 * @brief         Enables/disables an interrupt by calling the Interrupt Controller IP layer.
 */
PLATFORM_FUNC static inline void Platform_Mld_SetIrq(IRQn_Type IrqNumber, boolean Enable)
{
    if (TRUE == Enable)
    {
        IntCtrl_Lld_EnableIrq(IrqNumber);
    }
    else
    {
        IntCtrl_Lld_DisableIrq(IrqNumber);
    }
}

/**
 * @internal
 * @brief         Sets the priority of an interrupt by calling the Interrupt Controller IP layer.
 */
PLATFORM_FUNC static inline void Platform_Mld_SetIrqPriority(IRQn_Type IrqNumber, uint8 Priority)
{
    IntCtrl_Lld_SetPriority(IrqNumber, Priority);
}

/**
 * @internal
 * @brief         Returns the priority of an interrupt by calling the Interrupt Controller IP layer.
 */
PLATFORM_FUNC static inline uint8 Platform_Mld_GetIrqPriority(IRQn_Type IrqNumber)
{
    return IntCtrl_Lld_GetPriority(IrqNumber);
}

/**
 * @internal
 * @brief         Installs a new interrupt handler by calling the Interrupt Controller IP layer.
 */
PLATFORM_FUNC static inline void Platform_Mld_InstallIrqHandler(IRQn_Type IrqNumber,
        const IntCtrl_Lld_IrqHandlerType NewHandler,
        IntCtrl_Lld_IrqHandlerType* const OldHandler)
{
    IntCtrl_Lld_InstallHandler(IrqNumber, NewHandler, OldHandler);
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#if (PLATFORM_INT_MONITOR == STD_ON)
/**
 * @internal
 * @brief         Enables/disables interrupt monitoring feature by calling the Interrupt Monitor IP layer.
 */
void Platform_Mld_SetIrqMonitor(boolean Enable);


/**
 * @internal
 * @brief         Acknowledges a monitored interrupt by calling the Interrupt Monitor IP layer.
 */
#define Platform_Mld_AckIrq(IrqNumber) Intm_Lld_AckIrq(IrqNumber)


/**
 * @internal
 * @brief         Selects an interrupt to be monitored by calling the Interrupt Monitor IP layer.
 */
void Platform_Mld_SelectMonitoredIrq(uint8 Channel, IRQn_Type IrqNumber);

/**
 * @internal
 * @brief         Selects an accepted latency for a monitored interrupt
 *                by calling the Interrupt Monitor IP layer.
 */
void Platform_Mld_SetMonitoredIrqLatency(uint8 Channel, uint32 Latency);


/**
 * @internal
 * @brief         Resets an interrupt monitor timer by calling the Interrupt Monitor IP layer.
 */
void Platform_Mld_ResetIrqMonitorTimer(uint8 Channel);

/**
 * @internal
 * @brief         Returns the status of an interrupt monitor by calling the Interrupt Monitor IP layer.
 */
boolean Platform_Mld_GetIrqMonitorStatus(uint8 Channel);

/**
 * @internal
 * @brief         Returns the validation result for given logical channel.
 */
Std_ReturnType Platform_Mld_ValidateChannelIntm(const Platform_Mld_ConfigType *Config,
        uint8 Channel);
/**
 * @internal
 * @brief         Returns the the possibility of setting interrupt monitor enabling.
 */

Std_ReturnType Platform_Mld_ValidateSetIrqMonitor(const Platform_Mld_ConfigType *Config);

#endif /* (PLATFORM_INT_MONITOR == STD_ON) */

#endif /* PLATFORM_MLD_H_ */

