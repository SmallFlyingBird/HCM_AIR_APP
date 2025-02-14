/**************************************************************************************************/
/**
 * @file      : Interrupt_Drv_Cfg.h
 * @brief     : Interrupt control driver level configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef INTERRUPT_DRV_CFG_H
#define INTERRUPT_DRV_CFG_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Interrupt_Drv
 *  @brief Interrupt control driver configuration header file
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define INTERRUPT_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define INTERRUPT_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define INTERRUPT_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define INTERRUPT_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define INTERRUPT_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define INTERRUPT_DRV_CFG_H_SW_MINOR_VERSION            2U
#define INTERRUPT_DRV_CFG_H_SW_PATCH_VERSION            2U

/**
* @brief Defines ISR support enabled or not.
*/
#define INTERRUPT_DRV_ISR_ENABLE     (STD_ON)

/**
* @brief Switches development error detection ON or OFF.
*/
#define INTERRUPT_DRV_DEV_ERROR_DETECT        (STD_ON)

/**
* @brief Defines user mode support or not.
*/
#define INTERRUPT_DRV_SUPPORT_USER_MODE         (STD_OFF)

/**
* @brief Defines the first implemented interrupt vector.
*/
#define INTERRUPT_DRV_FIRST_IRQ                  (NMI_IRQn)

/**
* @brief Defines the last implemented interrupt vector.
*/

#define INTERRUPT_DRV_LAST_IRQ                       (CACHE_Err_IRQn)

/**
* @brief The interrupt counter value.
*/
#define INTERRUPT_DRV_IRQ_COUNT                     (205U)

/**
* @brief Defines number of priority bits.
*/
#define INTERRUPT_DRV_PRIO_BITS_NUM                (4U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define INTERRUPT_DRV_CONFIG_EXT \
    extern const Interrupt_Drv_ConfigType Interrupt_Drv_Config; \
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @brief Declaration of interrupt handlers
 */
extern void undefined_handler(void);
extern void Uart_Drv_3_IrqHandler(void);
extern void Tim_Drv_0_ChIrqHandler(void);
extern void Tim_Drv_0_OverflowIrqHandler(void);
extern void Tim_Drv_1_ChIrqHandler(void);
extern void Tim_Drv_1_OverflowIrqHandler(void);
extern void Tim_Drv_2_ChIrqHandler(void);
extern void Adc_Drv_0_IrqHandler(void);
extern void Adc_Drv_1_IrqHandler(void);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Interrupt_Drv */

/** @} end of group Platform_Module */

#endif /* INTERRUPT_DRV_CFG_H */
