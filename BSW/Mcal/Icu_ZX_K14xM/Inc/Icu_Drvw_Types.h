/**************************************************************************************************/
/**
 * @file      : Icu_Drvw_Types.h
 * @brief     : AUTOSAR Icu drvw types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ICU_DRVW_TYPES_H
#define ICU_DRVW_TYPES_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drvw
 *  @{
 */
        
#ifdef __cplusplus
extern "C"{
#endif

#include "Icu_Drvw_Cfg.h"
#include "Tim_Icu_Drv_Types.h"
#include "Cmp_Icu_Drv_Types.h"
#include "Port_Icu_Drv_Types.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define ICU_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define ICU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define ICU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define ICU_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define ICU_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define ICU_DRVW_TYPES_H_SW_PATCH_VERSION            1U

#if (ICU_DRVW_TYPES_H_VENDOR_ID != TIM_ICU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_Types.h and Tim_Icu_Drv_Types.h have different"
#endif
            
#if ((ICU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_Types.h and Tim_Icu_Drv_Types.h are different"
#endif

#if ((ICU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != TIM_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_DRVW_TYPES_H_SW_PATCH_VERSION != TIM_ICU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "AutoSar version of Icu_Drvw_Types.h and Tim_Icu_Drv_Types.h are different"
#endif
            
#if ((ICU_DRVW_TYPES_H_SW_MAJOR_VERSION != TIM_ICU_DRV_TYPES_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_SW_MINOR_VERSION != TIM_ICU_DRV_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_Types.h and Tim_Icu_Drv_Types.h are different"
#endif

#if (ICU_DRVW_TYPES_H_VENDOR_ID != CMP_ICU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_Types.h and Cmp_Icu_Drv_Types.h have different"
#endif
            
#if ((ICU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_Types.h and Cmp_Icu_Drv_Types.h are different"
#endif
            
#if ((ICU_DRVW_TYPES_H_SW_MAJOR_VERSION != CMP_ICU_DRV_TYPES_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_SW_MINOR_VERSION != CMP_ICU_DRV_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_Types.h and Cmp_Icu_Drv_Types.h are different"
#endif

#if (ICU_DRVW_TYPES_H_VENDOR_ID != PORT_ICU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_Types.h and Port_Icu_Drv_Types.h have different"
#endif
            
#if ((ICU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != PORT_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != PORT_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_Types.h and Port_Icu_Drv_Types.h are different"
#endif
            
#if ((ICU_DRVW_TYPES_H_SW_MAJOR_VERSION != PORT_ICU_DRV_TYPES_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_SW_MINOR_VERSION != PORT_ICU_DRV_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_Types.h and Port_Icu_Drv_Types.h are different"
#endif

#if (ICU_DRVW_TYPES_H_VENDOR_ID != ICU_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_Types.h and Icu_Drvw_Cfg.h have different"
#endif
            
#if ((ICU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != ICU_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_Types.h and Icu_Drvw_Cfg.h are different"
#endif
            
#if ((ICU_DRVW_TYPES_H_SW_MAJOR_VERSION != ICU_DRVW_CFG_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_TYPES_H_SW_MINOR_VERSION != ICU_DRVW_CFG_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_Types.h and Icu_Drvw_Cfg.h are different"
#endif

/**
 * @brief Icu Icu_Drvw_ActivationType typedef
 */
typedef uint8 Icu_Drvw_ActivationType;

/**
 * @brief Icu TIM channel type
 */

#ifndef ICU_DRVW_ACTIVATION_TYPE
#define ICU_DRVW_ACTIVATION_TYPE             Icu_Drvw_ActivationType
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

typedef uint16  Icu_Drvw_ValueType;

/**
 *  @brief instance type for Icu Drvw implemention
 */
typedef enum
{
    ICU_DRVW_INSTANCE_TIM                                   = 0U,               /*!< TIM module */       
    ICU_DRVW_INSTANCE_PORT,                                                     /*!< PORT module */
    ICU_DRVW_INSTANCE_CMP                                                       /*!< CMP module */
} Icu_Drvw_InstanceType;

/**
 * @brief   Structure defining the pointer of the tim and cmp channel.
 */
typedef struct
{
    const Tim_Icu_Drv_ChannelConfigType * TimIcuChCfgPtr;    /*!< TIM channels configuration */
    const Cmp_Icu_Drv_ChannelConfigType * CmpIcuChCfgPtr;    /*!< CMP channels configuration*/
    const Port_Icu_Drv_ChannelConfigType * PortIcuChCfgPtr;  /*!< PORT channels configuration*/
} Icu_Drvw_ChannelConfigType;

/**
 * @brief   Structure defining the pointer of the tim and cmp channel.
 */
typedef struct
{
    const Tim_Icu_Drv_InstanceConfigType * TimIcuInstCfgPtr;      /*!< TIM instances configuration */
    const Cmp_Icu_Drv_InstanceConfigType * CmpIcuInstCfgPtr;      /*!< CMP instances configuration */
    const Port_Icu_Drv_InstanceConfigType * PortIcuInstCfgPtr;    /*!< PORT instances configuration */   
} Icu_Drvw_InstanceConfigType;

/**
 * @brief Structure that store Icu Drvw configuration data
 */
typedef struct
{
    Icu_Drvw_InstanceType ChModule;           /*!< The instance used to implement this Icu channel */
    uint8 InstId;                             /*!< The instance Id used for the channel */
    uint16 Index;                             /*!< reserved */
    Icu_Drvw_ChannelConfigType ChannelConfig; /*!< Pointer of the channel configuration*/
} Icu_Drvw_HwChannelConfigType;

/**
 * @brief Structure that store Icu Drvw configuration data
 */
typedef struct
{
    Icu_Drvw_InstanceType InstModule;                   /*!< The instance used to implement Icu channel */
    uint8 InstId;                                       /*!< The instance Id */
    uint16 InstProperty;                                /*!< The instance module */                                                 
    const Icu_Drvw_InstanceConfigType InstanceConfig;   /*!< Pointer of the instances configuration*/
} Icu_Drvw_HwInstanceConfigType;

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

/** @} end of group Icu_Drvw  */
/** @} end of group Icu_Module */

#endif  /* ICU_DRVW_TYPES_H */

