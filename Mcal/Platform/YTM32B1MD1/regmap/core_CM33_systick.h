/**
*   @file    core_CM33_systick.h
*   @version
*
*   @brief   AUTOSAR CM33_systick register map
*   @details Register map for CM33_SYSTICK
*
*   @addtogroup CM33_SYSTICK_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : core_CM33_systick
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
/*==================================================================================================
==================================================================================================*/

#ifndef CORE_CM33_SYSTICK_H
#define CORE_CM33_SYSTICK_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CM33_SYSTICK REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CM33_SysTick_Peripheral_Access_Layer CM33_SysTick Peripheral Access Layer
 * @{
 */


/** CM33_SysTick - Size of Registers Arrays */

/* CM33_SysTick Register Layout Typedef */
typedef struct {
    uint32 CSR;                                /**< Control and status Register, offset: 0x0000 */
    uint32 RVR;                                /**< Systick Reload Value Register, offset: 0x0004 */
    uint32 CVR;                                /**< Systick Current Value Register, offset: 0x0008 */
    uint32 CALIB;                              /**< Systick Calibration Value Register, offset: 0x000C */

} CM33_SysTick_Type, *CM33_SysTick_MemMapPtr;

/** Number of instances of the CM33_SysTick module. */
#define CM33_SysTick_INSTANCE_COUNT                        (1u)

/* CM33_SysTick base address */
#define CM33_SysTick_BASE_ADDR32                           (0xE000E010U)
#define CM33_SysTick                                       ((volatile CM33_SysTick_Type *)(CM33_SysTick_BASE_ADDR32))

/** Array initializer of CM33_SysTick peripheral base addresses */
#define CM33_SysTick_BASE_ADDRS                             { CM33_SysTick_BASE_ADDR32 }
/** Array initializer of CM33_SysTick peripheral base pointers */
#define CM33_SysTick_BASE_PTRS                              { CM33_SysTick }

#define CM33_SysTick_CSR_OFFSET32                           (0x0000U)                    /**< Offset for Control and status Register */
#define CM33_SysTick_RVR_OFFSET32                           (0x0004U)                    /**< Offset for Systick Reload Value Register */
#define CM33_SysTick_CVR_OFFSET32                           (0x0008U)                    /**< Offset for Systick Current Value Register */
#define CM33_SysTick_CALIB_OFFSET32                         (0x000CU)                    /**< Offset for Systick Calibration Value Register */


/**
 * @addtogroup CM33_SysTick Register Mask
 * @{
 */
/* CM33_SysTick_CSR Register */
#define CM33_SysTick_CSR_COUNTFLAG_MASK                             (0x10000U)
#define CM33_SysTick_CSR_COUNTFLAG_SHIFT                            (16U)
#define CM33_SysTick_CSR_COUNTFLAG(x)                               (((uint32)(((uint32)(x)) << CM33_SysTick_CSR_COUNTFLAG_SHIFT)) & CM33_SysTick_CSR_COUNTFLAG_MASK)
#define CM33_SysTick_CSR_CLKSOURCE_MASK                             (0x4U)
#define CM33_SysTick_CSR_CLKSOURCE_SHIFT                            (2U)
#define CM33_SysTick_CSR_CLKSOURCE(x)                               (((uint32)(((uint32)(x)) << CM33_SysTick_CSR_CLKSOURCE_SHIFT)) & CM33_SysTick_CSR_CLKSOURCE_MASK)
#define CM33_SysTick_CSR_TICKINT_MASK                               (0x2U)
#define CM33_SysTick_CSR_TICKINT_SHIFT                              (1U)
#define CM33_SysTick_CSR_TICKINT(x)                                 (((uint32)(((uint32)(x)) << CM33_SysTick_CSR_TICKINT_SHIFT)) & CM33_SysTick_CSR_TICKINT_MASK)
#define CM33_SysTick_CSR_ENABLE_MASK                                (0x1U)
#define CM33_SysTick_CSR_ENABLE_SHIFT                               (0U)
#define CM33_SysTick_CSR_ENABLE(x)                                  (((uint32)(((uint32)(x)) << CM33_SysTick_CSR_ENABLE_SHIFT)) & CM33_SysTick_CSR_ENABLE_MASK)
/* CM33_SysTick_RVR Register */
#define CM33_SysTick_RVR_RELOAD_WIDTH                               (24)
#define CM33_SysTick_RVR_RELOAD_MASK                                (0xFFFFFFU)
#define CM33_SysTick_RVR_RELOAD_SHIFT                               (0U)
#define CM33_SysTick_RVR_RELOAD(x)                                  (((uint32)(((uint32)(x)) << CM33_SysTick_RVR_RELOAD_SHIFT)) & CM33_SysTick_RVR_RELOAD_MASK)
/* CM33_SysTick_CVR Register */
#define CM33_SysTick_CVR_CURRENT_WIDTH                              (24)
#define CM33_SysTick_CVR_CURRENT_MASK                               (0xFFFFFFU)
#define CM33_SysTick_CVR_CURRENT_SHIFT                              (0U)
#define CM33_SysTick_CVR_CURRENT(x)                                 (((uint32)(((uint32)(x)) << CM33_SysTick_CVR_CURRENT_SHIFT)) & CM33_SysTick_CVR_CURRENT_MASK)
/* CM33_SysTick_CALIB Register */
#define CM33_SysTick_CALIB_NOREF_MASK                               (0x80000000U)
#define CM33_SysTick_CALIB_NOREF_SHIFT                              (31U)
#define CM33_SysTick_CALIB_NOREF(x)                                 (((uint32)(((uint32)(x)) << CM33_SysTick_CALIB_NOREF_SHIFT)) & CM33_SysTick_CALIB_NOREF_MASK)
#define CM33_SysTick_CALIB_SKEW_MASK                                (0x40000000U)
#define CM33_SysTick_CALIB_SKEW_SHIFT                               (30U)
#define CM33_SysTick_CALIB_SKEW(x)                                  (((uint32)(((uint32)(x)) << CM33_SysTick_CALIB_SKEW_SHIFT)) & CM33_SysTick_CALIB_SKEW_MASK)
#define CM33_SysTick_CALIB_TENMS_MASK                               (0xFFFFFFU)
#define CM33_SysTick_CALIB_TENMS_SHIFT                              (0U)
#define CM33_SysTick_CALIB_TENMS(x)                                 (((uint32)(((uint32)(x)) << CM33_SysTick_CALIB_TENMS_SHIFT)) & CM33_SysTick_CALIB_TENMS_MASK)


/**
 * @}
 */ /* end of group CM33_SysTick_Register_Masks */


/**
 * @}
 */ /* end of group CM33_SysTick_Peripheral_Access_Layer */

#endif /* CORE_CM33_SYSTICK_H */

