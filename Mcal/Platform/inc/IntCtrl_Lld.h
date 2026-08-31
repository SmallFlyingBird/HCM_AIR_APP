/*==================================================================================================
*   Project              : AUTOSAR 4.4
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

#ifndef INTCTRL_LLD_H_
#define INTCTRL_LLD_H_

/**
*   @file
*
*   @defgroup   IntCtrl_Lld Interrupt Controller IP
*   @ingroup    Platform
*
*   @addtogroup IntCtrl_Lld
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Lld_CfgDefines.h"
#include "IntCtrl_Lld_Cfg.h"
#include "Devassert.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_LLD_VENDOR_ID                          (180)
#define PLATFORM_INTCTRL_LLD_SW_MAJOR_VERSION                   (2)
#define PLATFORM_INTCTRL_LLD_SW_MINOR_VERSION                   (3)
#define PLATFORM_INTCTRL_LLD_SW_PATCH_VERSION                   (0)
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Lld_Cfg header file are of the same vendor */
#if (PLATFORM_INTCTRL_LLD_VENDOR_ID != PLATFORM_INTCTRL_LLD_CFG_VENDOR_ID)
#error "IntCtrl_Lld.h and IntCtrl_Lld_Cfg.h have different vendor ids"
#endif

/* Check if current file and IntCtrl_Lld_Cfg header file are of the same Software version */
#if ((PLATFORM_INTCTRL_LLD_SW_MAJOR_VERSION != PLATFORM_INTCTRL_LLD_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_SW_MINOR_VERSION != PLATFORM_INTCTRL_LLD_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_SW_PATCH_VERSION != PLATFORM_INTCTRL_LLD_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of IntCtrl_Lld.h and IntCtrl_Lld_Cfg.h are different"
#endif

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/**
 * @brief         Initializes the configured interrupts at interrupt controller level.
 *
 * @details       This function is non-reentrant and initializes the interrupts.
 *
 * @param[in]     IntCtrlCtrlConfig: pointer to configuration structure for interrupts.
 * @return        IntCtrl_Lld_StatusType: error code.
 * */
IntCtrl_Lld_StatusType IntCtrl_Lld_Init(const IntCtrl_Lld_CtrlConfigType *IntCtrlCtrlConfig); /* NOSONAR, for app use if needed */

#if (INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON)
/**
 * @brief         Initializes the configured routing interrupts .
 *
 * @details       This function is non-reentrant and initializes the routing interrupts.
 *
 * @param[in]     routeConfig: pointer to configuration structure for interrupts.
 * @return        IntCtrl_Lld_StatusType: error code.
 * */
IntCtrl_Lld_StatusType IntCtrl_Lld_ConfigIrqRouting(const IntCtrl_Lld_GlobalRouteConfigType *routeConfig);
#endif

/**
 * @brief         Installs a handler for an IRQ.
 *
 * @details       This function is non-reentrant; it installs an new ISR for an interrupt line.
 * @note          This function works only when the interrupt vector table resides in RAM.
 *
 * @param[in]     IrqNumber: interrupt number.
 * @param[in]     NewHandler: function pointer for the new handler.
 * @param[out]    OldHandler: stores the address of the old interrupt handler.
 * @return        void.
 * */
void IntCtrl_Lld_InstallHandler(IRQn_Type IrqNumber,
                                const IntCtrl_Lld_IrqHandlerType NewHandler,
                                IntCtrl_Lld_IrqHandlerType* const OldHandler);

/**
 * @brief         Enables an interrupt request.
 *
 * @details       This function is non-reentrant; it enables the interrupt request at
 *                interrupt controller level.
 *
 * @param[in]     IrqNumber: interrupt number to be enabled.
 * @return        void.
 * */
void IntCtrl_Lld_EnableIrq(IRQn_Type IrqNumber);

/**
 * @brief         Disables an interrupt request.
 *
 * @details       This function is non-reentrant; it disables the interrupt request at
 *                interrupt controller level.
 *
 * @param[in]     IrqNumber: interrupt number to be disabled.
 * @return        void.
 * */
void IntCtrl_Lld_DisableIrq(IRQn_Type IrqNumber);

/**
 * @brief         Sets the Priority for an interrupt request.
 *
 * @details       This function is non-reentrant; it sets the Priority for the
 *                interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which the Priority is set.
 * @param[in]     Priority: the Priority to be set.
 * @return        void.
 * */
void IntCtrl_Lld_SetPriority(IRQn_Type IrqNumber, uint8 Priority);

/**
 * @brief         Gets the Priority for an interrupt request.
 *
 * @details       This function is non-reentrant; it retrieves the Priority for the
 *                interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which the Priority is set.
 * @return        uint8: the Priority of the interrupt.
 * */
uint8 IntCtrl_Lld_GetPriority(IRQn_Type IrqNumber);

/**
 * @brief         Clears the pending flag for an interrupt request.
 *
 * @details       This function is reentrant; it clears the pending flag for the
 *                interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which the pending flag is cleared.
 * @return        void.
 * */
void IntCtrl_Lld_ClearPending(IRQn_Type IrqNumber);


#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)
/**
 * @brief         Sets the pending flag for an interrupt request.
 *
 * @details       This function is reentrant; it sets the pending flag for the
 *                interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which the pending flag is set.
 * @return        void.
 * */
void IntCtrl_Lld_SetPending(IRQn_Type IrqNumber); /* NOSONAR, for app use if needed */

/**
 * @brief         Gets the pending flag for an interrupt request.
 *
 * @details       This function is reentrant; it retrieves the pending flag for the
 *                interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which the pending flag is returned.
 * @return        boolean: TRUE - pending flag set, FALSE - pending flag cleared.
 * */
boolean IntCtrl_Lld_GetPending(IRQn_Type IrqNumber); /* NOSONAR, for app use if needed */

/**
 * @brief         Gets the active flag for an interrupt request.
 *
 * @details       This function is reentrant; it retrieves the active flag for the
 *                interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which the active flag is returned.
 * @return        boolean: TRUE - active flag set, FALSE - active flag cleared.
 * */

boolean IntCtrl_Lld_GetActive(IRQn_Type IrqNumber); /* NOSONAR, for app use if needed */

#endif /* INT_CTRL_LLD_STANDALONE_APIS*/

#if ((INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_LLD_ROUTING_CONTROL_REGISTER == STD_ON))
/**
 * @brief         Sets the target cores for an interrupt request.
 *
 * @details       This function is non-reentrant; it configures the target cores for the
 *                interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which the target cores are set.
 * @param[in]     TargetCores: uint8 mask to defining the target cores.
 * @note          TargetCores parameter encodes the CPU targets as defined in each platform
 *                (see MSCM IRSPRCx register) - the function writes this value to the corresponding
 *                IRSPRCx register directly.
 * @return        void.
 * */
void IntCtrl_Lld_SetTargetCores(IRQn_Type IrqNumber, uint8 TargetCores);
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* INTCTRL_LLD_H_ */

/** @} */

