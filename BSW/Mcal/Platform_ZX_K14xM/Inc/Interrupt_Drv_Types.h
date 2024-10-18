/**************************************************************************************************/
/**
 * @file      : Interrupt_Drv_Types.h
 * @brief     : Interrupt Control driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef INTERRUPT_DRV_TYPES_H
#define INTERRUPT_DRV_TYPES_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Interrupt_Drv
 *  @brief Interrupt Control driver type definition file
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Interrupt_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"
#include "Device_Regs.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define INTERRUPT_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define INTERRUPT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define INTERRUPT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define INTERRUPT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define INTERRUPT_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define INTERRUPT_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define INTERRUPT_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Interrupt_Drv.h are the same vendor */
#if (INTERRUPT_DRV_TYPES_H_VENDOR_ID != INTERRUPT_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Interrupt_Drv.c and Interrupt_Drv.h have different vendor ids"
#endif
/* Check if current file and Interrupt_Drv.h are the same Autosar version */
#if ((INTERRUPT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION !=                                            \
      INTERRUPT_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||                                             \
     (INTERRUPT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION !=                                            \
      INTERRUPT_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||                                             \
     (INTERRUPT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                         \
      INTERRUPT_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Interrupt_Drv.c and Interrupt_Drv.h are different"
#endif
/* Check if current file and Interrupt_Drv.h are the same Software version */
#if ((INTERRUPT_DRV_TYPES_H_SW_MAJOR_VERSION != INTERRUPT_DRV_CFG_H_SW_MAJOR_VERSION) ||           \
     (INTERRUPT_DRV_TYPES_H_SW_MINOR_VERSION != INTERRUPT_DRV_CFG_H_SW_MINOR_VERSION) ||           \
     (INTERRUPT_DRV_TYPES_H_SW_PATCH_VERSION != INTERRUPT_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Interrupt_Drv.c and Interrupt_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((INTERRUPT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION !=                                        \
          DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||                                               \
         (INTERRUPT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION !=                                        \
          DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Interrupt_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((INTERRUPT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||       \
         (INTERRUPT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Interrupt_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((INTERRUPT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||   \
         (INTERRUPT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Interrupt_Drv.c and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Defines interrupt handler type.
 */
typedef void (*Interrupt_Drv_IrqHandlerType)(void);

/**
 * @brief  Defines structure for interrupt request configuration.
 */
typedef struct
{
    IRQn_Type                    IrqNumber;   /*!< Interrupt number */
    boolean                      IrqEnabled;  /*!< Interrupt state (enabled/disabled) */
    uint8                        IrqPriority; /*!< Interrupt priority */
    Interrupt_Drv_IrqHandlerType IrqHandler;  /*!< Interrupt handler */
} Interrupt_Drv_IrqConfigType;

/**
 * @brief  Defines structure for list of all interrupt request configuration.
 */
typedef struct
{
    uint32 ConfigIrqCount; /*!< Number of configured interrupt request */
    const Interrupt_Drv_IrqConfigType
        *IrqConfigList; /*!< List of interrupt request configuration */
} Interrupt_Drv_ConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Interrupt_Drv */

/** @} end of group Platform_Module */

#endif /* INTERRUPT_DRV_TYPES_H */
