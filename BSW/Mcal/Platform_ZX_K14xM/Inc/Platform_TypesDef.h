/**************************************************************************************************/
/**
 * @file      : Platform_TypesDef.h
 * @brief     : Platform high level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PLATFORM_TYPESDEF_H
#define PLATFORM_TYPESDEF_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Platform
 *  @brief Platform high level driver type definition file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_Cfg.h"
#include "Interrupt_Drv_Types.h"
#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
    #include "Tmu_Drv_Types.h"
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define PLATFORM_TYPESDEF_H_VENDOR_ID                   0x00B3U
#define PLATFORM_TYPESDEF_H_AR_RELEASE_MAJOR_VERSION    4U
#define PLATFORM_TYPESDEF_H_AR_RELEASE_MINOR_VERSION    6U
#define PLATFORM_TYPESDEF_H_AR_RELEASE_REVISION_VERSION 0U
#define PLATFORM_TYPESDEF_H_SW_MAJOR_VERSION            1U
#define PLATFORM_TYPESDEF_H_SW_MINOR_VERSION            2U
#define PLATFORM_TYPESDEF_H_SW_PATCH_VERSION            1U

/* Check if current file and Platform_Cfg.h are the same vendor */
#if (PLATFORM_TYPESDEF_H_VENDOR_ID != PLATFORM_CFG_H_VENDOR_ID)
    #error "Vendor ID of Platform_TypesDef.h and Platform_Cfg.h are different"
#endif
/* Check if current file and Platform_Cfg.h are the same Autosar version */
#if ((PLATFORM_TYPESDEF_H_AR_RELEASE_MAJOR_VERSION != PLATFORM_CFG_H_AR_RELEASE_MAJOR_VERSION) ||  \
     (PLATFORM_TYPESDEF_H_AR_RELEASE_MINOR_VERSION != PLATFORM_CFG_H_AR_RELEASE_MINOR_VERSION) ||  \
     (PLATFORM_TYPESDEF_H_AR_RELEASE_REVISION_VERSION !=                                           \
      PLATFORM_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Platform_TypesDef.h and Platform_Cfg.h are different"
#endif
/* Check if current file and Platform_Cfg.h are the same Software version */
#if ((PLATFORM_TYPESDEF_H_SW_MAJOR_VERSION != PLATFORM_CFG_H_SW_MAJOR_VERSION) ||                  \
     (PLATFORM_TYPESDEF_H_SW_MINOR_VERSION != PLATFORM_CFG_H_SW_MINOR_VERSION) ||                  \
     (PLATFORM_TYPESDEF_H_SW_PATCH_VERSION != PLATFORM_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Platform_TypesDef.h and Platform_Cfg.h are different"
#endif

/* Check if current file and Interrupt_Drv_Types.h are the same vendor */
#if (PLATFORM_TYPESDEF_H_VENDOR_ID != INTERRUPT_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Platform_TypesDef.h and Interrupt_Drv_Types.h are different"
#endif
/* Check if current file and Interrupt_Drv_Types.h are the same Autosar version */
#if ((PLATFORM_TYPESDEF_H_AR_RELEASE_MAJOR_VERSION !=                                              \
      INTERRUPT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                                           \
     (PLATFORM_TYPESDEF_H_AR_RELEASE_MINOR_VERSION !=                                              \
      INTERRUPT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                                           \
     (PLATFORM_TYPESDEF_H_AR_RELEASE_REVISION_VERSION !=                                           \
      INTERRUPT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Platform_TypesDef.h and Interrupt_Drv_Types.h are different"
#endif
/* Check if current file and Interrupt_Drv_Types.h are the same Software version */
#if ((PLATFORM_TYPESDEF_H_SW_MAJOR_VERSION != INTERRUPT_DRV_TYPES_H_SW_MAJOR_VERSION) ||           \
     (PLATFORM_TYPESDEF_H_SW_MINOR_VERSION != INTERRUPT_DRV_TYPES_H_SW_MINOR_VERSION) ||           \
     (PLATFORM_TYPESDEF_H_SW_PATCH_VERSION != INTERRUPT_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Platform_TypesDef.h and Interrupt_Drv_Types.h are different"
#endif

#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
    /* Check if current file and Tmu_Drv_Types.h are the same vendor */
    #if (PLATFORM_TYPESDEF_H_VENDOR_ID != TMU_DRV_TYPES_H_VENDOR_ID)
        #error "Vendor ID of Platform_TypesDef.h and Tmu_Drv_Types.h are different"
    #endif
    /* Check if current file and Tmu_Drv_Types.h are the same Autosar version */
    #if ((PLATFORM_TYPESDEF_H_AR_RELEASE_MAJOR_VERSION !=                                          \
          TMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                                             \
         (PLATFORM_TYPESDEF_H_AR_RELEASE_MINOR_VERSION !=                                          \
          TMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                                             \
         (PLATFORM_TYPESDEF_H_AR_RELEASE_REVISION_VERSION !=                                       \
          TMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version of Platform_TypesDef.h and Tmu_Drv_Types.h are different"
    #endif
    /* Check if current file and Tmu_Drv_Types.h are the same Software version */
    #if ((PLATFORM_TYPESDEF_H_SW_MAJOR_VERSION != TMU_DRV_TYPES_H_SW_MAJOR_VERSION) ||             \
         (PLATFORM_TYPESDEF_H_SW_MINOR_VERSION != TMU_DRV_TYPES_H_SW_MINOR_VERSION) ||             \
         (PLATFORM_TYPESDEF_H_SW_PATCH_VERSION != TMU_DRV_TYPES_H_SW_PATCH_VERSION))
        #error "Software Version of Platform_TypesDef.h and Tmu_Drv_Types.h are different"
    #endif
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */

/**
 * @brief Error returned for pointers a NULL value
 */
#define PLATFORM_E_PARAM_POINTER ((uint8)0x01)

/**
 * @brief Error returned for parameters out of range
 */
#define PLATFORM_E_PARAM_OUT_OF_RANGE ((uint8)0x02)

/**
 * @brief Error returned for wrong configuration.
 */
#define PLATFORM_E_PARAM_CONFIG ((uint8)0x03)

/**
 * @brief Defines service ID of Platform_Init function
 */
#define PLATFORM_SID_INIT ((uint8)0x10U)

/**
 * @brief Defines service ID of Platform_SetIrq function
 */
#define PLATFORM_SID_SET_IRQ ((uint8)0x11U)

/**
 * @brief Defines service ID of Platform_SetIrqPriority function
 */
#define PLATFORM_SID_SET_IRQ_PRIO ((uint8)0x12U)

/**
 * @brief Defines service ID of Platform_GetIrqPriority function
 */
#define PLATFORM_SID_GET_IRQ_PRIO ((uint8)0x13U)

/**
 * @brief Defines service ID of Platform_InstallIrqHandler function
 */
#define PLATFORM_SID_INSTALL_HANDLER ((uint8)0x14U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Defines configuration structure for platform CDD
 */
typedef struct
{
    const Interrupt_Drv_ConfigType *InterruptConfigPtr;
#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
    const Tmu_Drv_ConfigType *TmuConfigPtr;
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */
} Platform_ConfigType;

/**
 * @brief  Defines interrupt handler type.
 */
typedef Interrupt_Drv_IrqHandlerType Platform_IrqHandlerType;

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

/** @} end of group Platform */

/** @} end of group Platform_Module */

#endif /* PLATFORM_TYPESDEF_H */
