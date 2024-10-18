/**************************************************************************************************/
/**
 * @file      : Wdog_Drv_Irq.c
 * @brief     : Wdg low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drv
 *  @brief Wdg low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdog_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDOG_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define WDOG_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDOG_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define WDOG_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define WDOG_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define WDOG_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define WDOG_DRV_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_Drv configuration header file are of the same vendor*/
#if (WDOG_DRV_IRQ_C_VENDOR_ID != WDOG_DRV_H_VENDOR_ID)
#error "Vendor of Wdog_Drv_Irq.c and Wdg_Drv.h are different"
#endif
#if ((WDOG_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    != WDOG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (WDOG_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    != WDOG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (WDOG_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != WDOG_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdog_Drv_Irq.c and Wdg_Drv.h are different"
#endif

#if ((WDOG_DRV_IRQ_C_SW_MAJOR_VERSION != WDOG_DRV_H_SW_MAJOR_VERSION) || \
    (WDOG_DRV_IRQ_C_SW_MINOR_VERSION != WDOG_DRV_H_SW_MINOR_VERSION) || \
    (WDOG_DRV_IRQ_C_SW_PATCH_VERSION != WDOG_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Wdog_Drv_Irq.c and Wdg_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#if (WDG_DRV_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#if (WDOG_DRV_ISR_ENABLED == STD_ON)
ISR(Wdog_Drv_IrqHandler);
#endif

#if (WDG_DRV_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/** @} end of Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#if (WDG_DRV_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"


#if (WDOG_DRV_ISR_ENABLED == STD_ON)
ISR(Wdog_Drv_IrqHandler)
{
    Wdog_Drv_IntHandler();
    EXIT_INTERRUPT();
}
#endif

#if (WDG_DRV_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif
/** @} end of group Wdg_Drv */

/** @} end of group Wdg_Module */
