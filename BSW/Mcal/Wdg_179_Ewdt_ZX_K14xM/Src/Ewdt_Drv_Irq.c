/**************************************************************************************************/
/**
 * @file      : Ewdt_Drv_Irq.c
 * @brief     : Wdg_179_Ewdt low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Wdg_179_Ewdt_Module
 *  @{
 */

/** @addtogroup Ewdt_Drv
 *  @brief Ewdt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Ewdt_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define EWDT_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define EWDT_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define EWDT_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define EWDT_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define EWDT_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define EWDT_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define EWDT_DRV_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Ewdt_Drv configuration header file are of the same vendor*/
#if (EWDT_DRV_IRQ_C_VENDOR_ID != EWDT_DRV_H_VENDOR_ID)
#error "Vendor of Ewdt_Drv_Irq.c and Ewdt_Drv.h are different"
#endif
#if ((EWDT_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    != EWDT_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (EWDT_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    != EWDT_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (EWDT_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != EWDT_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Ewdt_Drv_Irq.c and Ewdt_Drv.h are different"
#endif

#if ((EWDT_DRV_IRQ_C_SW_MAJOR_VERSION != EWDT_DRV_H_SW_MAJOR_VERSION) || \
    (EWDT_DRV_IRQ_C_SW_MINOR_VERSION != EWDT_DRV_H_SW_MINOR_VERSION) || \
    (EWDT_DRV_IRQ_C_SW_PATCH_VERSION != EWDT_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Ewdt_Drv_Irq.c and Ewdt_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_START_SEC_CODE
#else
#define WDG_179_EWDT_START_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

#if (EWDT_DRV_ISR_ENABLED == STD_ON)
ISR(Ewdt_Drv_IrqHandler);
#endif

#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_STOP_SEC_CODE
#else
#define WDG_179_EWDT_STOP_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"
/** @} end of Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_START_SEC_CODE
#else
#define WDG_179_EWDT_START_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"


#if (EWDT_DRV_ISR_ENABLED == STD_ON)
ISR(Ewdt_Drv_IrqHandler)
{
    Ewdt_Drv_IntHandler();
    EXIT_INTERRUPT();
}
#endif

#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_STOP_SEC_CODE
#else
#define WDG_179_EWDT_STOP_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif
/** @} end of group Ewdt_Drv */

/** @} end of group Wdg_179_Ewdt_Module */
