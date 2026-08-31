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

#ifndef INTCTRL_LLD_TRUSTEDFUNCTIONS_H_
#define INTCTRL_LLD_TRUSTEDFUNCTIONS_H_

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
#include "Devassert.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_VENDOR_ID                          (180)
#define PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                   (2)
#define PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                   (3)
#define PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                   (0)
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Lld_CfgDefines header file are of the same vendor */
#if (PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_VENDOR_ID != PLATFORM_INTCTRL_LLD_CFG_DEFINES_VENDOR_ID)
#error "IntCtrl_Lld_TrustedFunctions.h and IntCtrl_Lld_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and IntCtrl_Lld_CfgDefines header file are of the same Software version */
#if ((PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != PLATFORM_INTCTRL_LLD_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != PLATFORM_INTCTRL_LLD_CFG_DEFINES_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != PLATFORM_INTCTRL_LLD_CFG_DEFINES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of IntCtrl_Lld_TrustedFunctions.h and IntCtrl_Lld_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

#if ((STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
/**
 * @internal
 * @brief         Installs a handler for an IRQ.
 */
extern void IntCtrl_Lld_InstIsrPrivileged(IRQn_Type IrqNumber,
        const IntCtrl_Lld_IrqHandlerType NewHandler,
        IntCtrl_Lld_IrqHandlerType* const OldHandler);
/**
 * @internal
 * @brief         Enables an interrupt request.
 */
extern void IntCtrl_Lld_EnableIrqPrivileged(IRQn_Type IrqNumber);
/**
 * @internal
 * @brief         Disables an interrupt request.
 */
extern void IntCtrl_Lld_DisableIrqPrivileged(IRQn_Type IrqNumber);
/**
 * @internal
 * @brief         Sets the priority for an interrupt request.
 */
extern void IntCtrl_Lld_SetPriPrivileged(IRQn_Type IrqNumber, uint8 Priority);
/**
 * @internal
 * @brief         Gets the priority for an interrupt request.
 */
extern uint8 IntCtrl_Lld_GetPriPrivileged(IRQn_Type IrqNumber);
/**
 * @internal
 * @brief         Clears the pending flag for an interrupt request.
 */
extern void IntCtrl_Lld_ClrPendingPrivileged(IRQn_Type IrqNumber);


#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)
/**
 * @internal
 * @brief         Sets the pending flag for an interrupt request.
 */
extern void IntCtrl_Lld_SetPendingPrivileged(IRQn_Type IrqNumber);
/**
 * @internal
 * @brief         Gets the pending flag for an interrupt request.
 */
extern boolean IntCtrl_Lld_GetPendingPrivileged(IRQn_Type IrqNumber);
#if (INT_CTRL_LLD_CORTEXM == STD_ON)
/**
 * @internal
 * @brief         Gets the active flag for an interrupt request.
 */
extern boolean IntCtrl_Lld_GetActivePrivileged(IRQn_Type IrqNumber);
#endif
#endif
#if ((INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_LLD_ROUTING_CONTROL_REGISTER == STD_ON))
/**
 * @internal
 * @brief         Sets the target cores for an interrupt request.
 */
extern void IntCtrl_Lld_SetCpuCorePrivileged(IRQn_Type IrqNumber, uint8 TargetCores);
#endif


#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* INTCTRL_LLD_TRUSTEDFUNCTIONS_H_ */

/** @} */

