/**************************************************************************************************/
/**
 * @file      : Interrupt_Drv_Cfg.h
 * @brief     : Interrupt control driver level configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
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
#define INTERRUPT_DRV_CFG_H_SW_PATCH_VERSION            1U

/**
* @brief Defines ISR support enabled or not.
*/
#define INTERRUPT_DRV_ISR_ENABLE     (STD_ON)

/**
* @brief Switches development error detection ON or OFF.
*/
#define INTERRUPT_DRV_DEV_ERROR_DETECT        (STD_OFF)

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
extern void Dma_Drv_Ch12IrqHandler(void);
extern void Dma_Drv_Ch13IrqHandler(void);
extern void Dma_Drv_Ch14IrqHandler(void);
extern void Dma_Drv_Ch15IrqHandler(void);
extern void Dma_Drv_ErrIrqHandler(void);
extern void Can_Drv_6_BusOffIrqHandler(void);
extern void Can_Drv_6_TxWarnIrqHandler(void);
extern void Can_Drv_6_RxWarnIrqHandler(void);
extern void Can_Drv_6_ErrIrqHandler(void);
extern void Can_Drv_6_SelfWakeupIrqHandler(void);
extern void Can_Drv_6_EccIrqHandler(void);
extern void Can_Drv_6_Mb0To31IrqHandler(void);
extern void Can_Drv_6_Mb32To63IrqHandler(void);
extern void Can_Drv_6_Mb64To95IrqHandler(void);
extern void Can_Drv_6_Mb96To127IrqHandler(void);
extern void Tim_Drv_0_ChIrqHandler(void);
extern void Tim_Drv_1_ChIrqHandler(void);
extern void Stim_Drv_IrqHandler(void);
extern void Cmu_Drv_0_IrqHandler(void);
extern void Cmu_Drv_1_IrqHandler(void);
extern void Cmu_Drv_2_IrqHandler(void);
extern void Seru_Drv_ParityErrIrqHandler(void);
extern void Seru_Drv_ChErrIrqHandler(void);
extern void Mcpwm_Drv_0_ChIrqHandler(void);
extern void Mcpwm_Drv_1_ChIrqHandler(void);
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
