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

#ifndef PLATFORM_H_
#define PLATFORM_H_

/**
 *   @file
 *
 *   @addtogroup Platform
 *   @{
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_Cfg.h"
#if defined (CPU_YTM32B1ME0) || defined (CPU_YTM32B1MD1)
#include "YTM32B1Mx_CM33_DSP_FP.h"
#elif defined (CPU_YTM32B1HA0)
#include "YTM32B1Hx_CM7_DSP_FP.h"
#elif defined (CPU_YTM32B1MC0)
#include "YTM32B1Mx_CM33.h"
#else
#error "No valid CPU defined!"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_MAIN_VENDOR_ID                     (180)
#define PLATFORM_MAIN_MODULE_ID                     (255)
#define PLATFORM_MAIN_AR_RELEASE_MAJOR_VERSION      (4)
#define PLATFORM_MAIN_AR_RELEASE_MINOR_VERSION      (4)
#define PLATFORM_MAIN_AR_RELEASE_REVISION_VERSION   (0)
#define PLATFORM_MAIN_SW_MAJOR_VERSION              (2)
#define PLATFORM_MAIN_SW_MINOR_VERSION              (3)
#define PLATFORM_MAIN_SW_PATCH_VERSION              (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Cfg header file are of the same vendor */
#if (PLATFORM_MAIN_VENDOR_ID != PLATFORM_MAIN_CFG_VENDOR_ID)
#error "Platform.h and Platform_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Cfg header file are of the same Autosar version */
#if ((PLATFORM_MAIN_AR_RELEASE_MAJOR_VERSION    != PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MAIN_AR_RELEASE_MINOR_VERSION    != PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MAIN_AR_RELEASE_REVISION_VERSION != PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Platform.h and Platform_Cfg.h are different"
#endif
/* Check if current file and Platform_Cfg header file are of the same Software version */
#if ((PLATFORM_MAIN_SW_MAJOR_VERSION != PLATFORM_MAIN_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_MAIN_SW_MINOR_VERSION != PLATFORM_MAIN_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_MAIN_SW_PATCH_VERSION != PLATFORM_MAIN_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Platform.h and Platform_Cfg.h are different"
#endif
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/


/**
 * @brief         Initializes the paltform settings based on user configuration.
 *
 * @details       This function is non-reentrant; it initializes the interrupts,
 *                interrupt monitors (if available), as well as other platform specific settings
 *                as defined for each SoC.
 *
 * @param[in]     Config: pointer to platform configuration structure.
 * @return        void
 * */
void Platform_Init(const Platform_ConfigType *Config); /* NOSONAR, for app use if needed */

/**
 * @brief         Configures (enables/disables) an interrupt request.
 *
 * @details       This function is non-reentrant; it enables/disables the selected interrupt.
 *
 * @param[in]     IrqNumber: interrupt to be configured.
 * @param[in]     Enable: TRUE - enable interrupt, FALSE - disable interrupt.
 * @return        Std_ReturnType: E_OK/E_NOT_OK; specific errors are reported through DET.
 * */
Std_ReturnType Platform_SetIrq(IRQn_Type IrqNumber, boolean Enable);

/**
 * @brief         Configures the priority of an interrupt request.
 *
 * @details       This function is non-reentrant; it sets the priority for the selected interrupt.
 *
 * @param[in]     IrqNumber: interrupt number for which priority is configured.
 * @param[in]     Priority: desired priority of the interrupt.
 * @return        Std_ReturnType: E_OK/E_NOT_OK; specific errors are reported through DET.
 * */
Std_ReturnType Platform_SetIrqPriority(IRQn_Type IrqNumber, uint8 Priority);

/**
 * @brief         Returns the priority of an interrupt request.
 *
 * @details       This function is non-reentrant; it retrieves the current priority of
 *                the selected interrupt.
 *
 * @param[in]     IrqNumber: interrupt number for which priority is returned.
 * @param[out]    Priority: output parameter storing the priority of the interrupt.
 * @return        Std_ReturnType: E_OK/E_NOT_OK; specific errors are reported through DET.
 * */
Std_ReturnType Platform_GetIrqPriority(IRQn_Type IrqNumber, uint8 * Priority); /* NOSONAR, for app use if needed */

/**
 * @brief         Installs a new handler for an interrupt request.
 *
 * @details       This function is non-reentrant; it replaces the current interrupt handler
 *                for the selected interrupt with the new function provided as the second
 *                parameter. The address of the old handler can be optionally stored in the third
 *                parameter.
 *
 * @param[in]     IrqNumber: interrupt number for which priority is returned.
 * @param[in]     NewHandler: function pointer for the new handler.
 * @param[out]    OldHandler: function pointer that will store the address of the old handler
 * @note          this parameter can be passed as NULL if not needed.
 * @return        OldHandler: E_OK/E_NOT_OK; specific errors are reported through DET.
 * */
Std_ReturnType Platform_InstallIrqHandler(IRQn_Type IrqNumber,
        const Platform_IrqHandlerType NewHandler,
        Platform_IrqHandlerType* const OldHandler);


#if (PLATFORM_INT_MONITOR == STD_ON)

/**
 * @brief         Configures (enables/disables) the interrupt monitor.
 *
 * @details       This function is reentrant; it enables/disables the interrupt monitoring feature.
 *
 * @param[in]     Enable: TRUE - enable interrupt monitoring, FALSE - disable interrupt monitoring.
 * @return        void
 *
 * @api
 *
 * */
void Platform_SetIrqMonitor(boolean Enable); /* NOSONAR, for app use if needed */

/**
 * @brief         Acknowledges a monitored interrupt has been served.
 *
 * @details       This function is reentrant; it confirms that a monitored interrupt has been served.
 *
 * @param[in]     Enable: enable or disable monitoring, TRUE-enable FALSE-disablw.
 * @return        void.
 *
 * @api
 *
 * */
void Platform_AckIrq(IRQn_Type IrqNumber); /* NOSONAR, for app use if needed */

/**
 * @brief         Selects an interrupt to monitor.
 *
 * @details       This function is reentrant; it selects which interrupt is monitored on which
 *                interrupt monitor.
 *
 * @param[in]     Channel: Logical channel of interrupt monitor used.
 * @param[in]     IrqNumber: the interrupt vector to be monitored.
 * @return        void.
 *
 * @api
 *
 * */
void Platform_SelectMonitoredIrq(uint8 Channel, IRQn_Type IrqNumber); /* NOSONAR, for app use if needed */

/**
 * @brief         Sets the latency for a monitored interrupt.
 *
 * @details       This function is reentrant; it sets the accepted latency for the
 *                monitored interrupt.
 *
 * @param[in]     Channel: Logical channel of interrupt monitor used.
 * @param[in]     Latency: The accepted latency for the monitored interrupt.
 * @return        void.
 *
 * @api
 *
 * */
void Platform_SetMonitoredIrqLatency(uint8 Channel, uint32 Latency); /* NOSONAR, for app use if needed */

/**
 * @brief         Resets the timer for an interrupt monitor.
 *
 * @details       This function is reentrant; it resets the timer for the interrupt monitor.
 *
 * @param[in]     Channel: Logical channel of interrupt monitor used.
 * @return        void.
 *
 * @api
 *
 * */
void Platform_ResetIrqMonitorTimer(uint8 Channel); /* NOSONAR, for app use if needed */

/**
 * @brief         Retrieves the status of an interrupt monitor.
 *
 * @details       This function shall return whether the accepted latency for the  monitored IRQs * has been exceeded.
 *
 * @param[in]     Channel        : Logical channel of interrupt monitor used.
 * @param[out]    LatencyExceeded : output status parameter: TRUE - latency exceeded, FALSE * latency not exceeded
 * @return        Std_ReturnType: E_OK/E_NOT_OK; specific errors are reported through DET.
 *
 * @api
 *
 * */
Std_ReturnType Platform_GetIrqMonitorStatus(uint8 Channel, boolean *LatencyExceeded); /* NOSONAR, for app use if needed */
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* PLATFORM_H_ */

/** @} */

