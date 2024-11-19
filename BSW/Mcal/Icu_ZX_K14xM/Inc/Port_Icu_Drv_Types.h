/**************************************************************************************************/
/**
 * @file      : Port_Icu_Drv_Types.h
 * @brief     : AUTOSAR Port Icu hardware types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_ICU_DRV_TYPES_H
#define PORT_ICU_DRV_TYPES_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Port_Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Port_Icu_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define PORT_ICU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define PORT_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_ICU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define PORT_ICU_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define PORT_ICU_DRV_TYPES_H_SW_PATCH_VERSION            2U

#if ((PORT_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != PORT_ICU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != PORT_ICU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Port_Icu_Drv_Types.h and Port_Icu_Drv_Cfg.h are different"
#endif

#if ((PORT_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != PORT_ICU_DRV_CFG_H_SW_MAJOR_VERSION) || \
        (PORT_ICU_DRV_TYPES_H_SW_MINOR_VERSION != PORT_ICU_DRV_CFG_H_SW_MINOR_VERSION))
    #error "Software version of Port_Icu_Drv_Types.h and Port_Icu_Drv_Cfg.h are different"
#endif

#if ((PORT_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != PORT_ICU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION) || \
        (PORT_ICU_DRV_TYPES_H_SW_PATCH_VERSION != PORT_ICU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software version of Port_Icu_Drv_Types.h and Port_Icu_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (PORT_ICU_DRV_TYPES_H_VENDOR_ID != MCALLIB_VENDOR_ID)
        #error "Vendor ID Port_Icu_Drv_Types.h and McalLib.h have different"
    #endif

    #if ((PORT_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
            (PORT_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Port_Icu_Drv_Types.h and McalLib.h are different"
    #endif

    #if ((PORT_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) || \
            (PORT_ICU_DRV_TYPES_H_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION))
        #error "Software version of Port_Icu_Drv_Types.h and McalLib.h are different"
    #endif

    #if ((PORT_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
            (PORT_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Port_Icu_Drv_Types.h and Std_Types.h are different"
    #endif

    #if ((PORT_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) || \
            (PORT_ICU_DRV_TYPES_H_SW_MINOR_VERSION != STD_SW_MINOR_VERSION))
        #error "Software version of Port_Icu_Drv_Types.h and Std_Types.h are different"
    #endif

#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/**
 * @brief Icu Port_Icu_Drv_ActivationType typedef
 */
typedef uint8 Port_Icu_Drv_ActivationType;

/**
 *  @brief The notification functions shall have no parameters and no return value
 */
typedef void (* Port_Icu_Drv_NotificationType)(void);

/**
 *  @brief The callback type for each channel
 */
typedef void (* Port_Icu_Drv_CallbackType)(uint16 Param1, boolean Param2);

/**
 * @brief Port id definition
 */
typedef enum
{
    PORT_ICU_DRV_PORT_A = 0U, /*!< PORT A*/
    PORT_ICU_DRV_PORT_B,      /*!< PORT B*/
    PORT_ICU_DRV_PORT_C,      /*!< PORT C*/
    PORT_ICU_DRV_PORT_D,      /*!< PORT D*/
    PORT_ICU_DRV_PORT_E       /*!< PORT E*/
} Port_Icu_Drv_IdType;

/**
 *  @brief Gpio number definition
 */
typedef enum
{
    PORT_ICU_DRV_GPIO_0 = 0U, /*!< GPIO0 pin definition*/
    PORT_ICU_DRV_GPIO_1,      /*!< GPIO1 pin definition*/
    PORT_ICU_DRV_GPIO_2,      /*!< GPIO2 pin definition*/
    PORT_ICU_DRV_GPIO_3,      /*!< GPIO3 pin definition*/
    PORT_ICU_DRV_GPIO_4,      /*!< GPIO4 pin definition*/
    PORT_ICU_DRV_GPIO_5,      /*!< GPIO5 pin definition*/
    PORT_ICU_DRV_GPIO_6,      /*!< GPIO6 pin definition*/
    PORT_ICU_DRV_GPIO_7,      /*!< GPIO7 pin definition*/
    PORT_ICU_DRV_GPIO_8,      /*!< GPIO8 pin definition*/
    PORT_ICU_DRV_GPIO_9,      /*!< GPIO9 pin definition*/
    PORT_ICU_DRV_GPIO_10,     /*!< GPIO10 pin definition*/
    PORT_ICU_DRV_GPIO_11,     /*!< GPIO11 pin definition*/
    PORT_ICU_DRV_GPIO_12,     /*!< GPIO12 pin definition*/
    PORT_ICU_DRV_GPIO_13,     /*!< GPIO13 pin definition*/
    PORT_ICU_DRV_GPIO_14,     /*!< GPIO14 pin definition*/
    PORT_ICU_DRV_GPIO_15,     /*!< GPIO15 pin definition*/
    PORT_ICU_DRV_GPIO_16,     /*!< GPIO16 pin definition*/
    PORT_ICU_DRV_GPIO_17,     /*!< GPIO17 pin definition*/
    PORT_ICU_DRV_GPIO_18,     /*!< GPIO18 pin definition*/
    PORT_ICU_DRV_GPIO_19,     /*!< GPIO19 pin definition*/
    PORT_ICU_DRV_GPIO_20,     /*!< GPIO20 pin definition*/
    PORT_ICU_DRV_GPIO_21,     /*!< GPIO21 pin definition*/
    PORT_ICU_DRV_GPIO_22,     /*!< GPIO22 pin definition*/
    PORT_ICU_DRV_GPIO_23,     /*!< GPIO23 pin definition*/
    PORT_ICU_DRV_GPIO_24,     /*!< GPIO24 pin definition*/
    PORT_ICU_DRV_GPIO_25,     /*!< GPIO25 pin definition*/
    PORT_ICU_DRV_GPIO_26,     /*!< GPIO26 pin definition*/
    PORT_ICU_DRV_GPIO_27,     /*!< GPIO27 pin definition*/
    PORT_ICU_DRV_GPIO_28,     /*!< GPIO28 pin definition*/
    PORT_ICU_DRV_GPIO_29,     /*!< GPIO29 pin definition*/
    PORT_ICU_DRV_GPIO_30,     /*!< GPIO30 pin definition*/
    PORT_ICU_DRV_GPIO_31      /*!< GPIO31 pin definition*/
} Port_Icu_Drv_GpioNoType;

/**
 *  @brief PORT Edge-Alignment Mode type definition
 */
typedef enum
{
    PORT_ICU_DRV_INPUT_DISABLED     = 0U,   /*!< PORT input capture disabled*/
    PORT_ICU_DRV_INPUT_RISING_EDGE  = 9U,   /*!< PORT input capture only on rising edge*/
    PORT_ICU_DRV_INPUT_FALLING_EDGE = 10U,  /*!< PORT input capture only on falling edge*/
    PORT_ICU_DRV_INPUT_BOTH_EDGES   = 11U,  /*!< PORT input capture both on rising and falling edge*/
} Port_Icu_Drv_EdgeAlignmentModeType;

/**
 *  @brief  Generic operation type definition
 */
typedef enum
{
    PORT_ICU_DRV_STATUS_SUCCESS                 = 0U, /*!< Generic operation success status */
    PORT_ICU_DRV_STATUS_ERROR                         /*!< Generic operation failure status */
} Port_Icu_Drv_StatusType;

/**
 * @brief Structure that store Input capture parameters for each channel
 */
typedef struct
{
    uint32 PhsyChId; /*!< Physical hardware channel ID */  
    Port_Icu_Drv_EdgeAlignmentModeType ActiveEdge;   /*!< Edge alignment Mode for signal measurement */      
    uint16 CallbackParam; /*!< The parameters of callback functions for channels events */
    Port_Icu_Drv_CallbackType CallbackFun; /*!< The callback function for 
                                                        channels edge detect events */ 
    Port_Icu_Drv_NotificationType ChNotificationFun; /*!< The notification functions for 
                                                                        SIGNAL_EDGE_DETECT mode */                                                               
} Port_Icu_Drv_ChannelConfigType;

/**
 * @brief Structure that store channel operation state
 */
typedef struct
{
    uint32 PhsyChId; /*!< Physical hardware channel ID */  
    Port_Icu_Drv_EdgeAlignmentModeType ActiveEdge; /*!< Type of edge used for activation */      
    Port_Icu_Drv_CallbackType CallbackFun; /*!< Calback for other types of measurement */
    uint16 CallbackParam; /*!< Logic channel for which callback is executed */
    Port_Icu_Drv_NotificationType ChNotificationFun; /*!< The notification functions for 
                                                                        SIGNAL_EDGE_DETECT mode */
    boolean NotifyEnable;   /*!< determines whether Notifications are enabled or not
                                 - TRUE: enable notification 
                                 - FALSE: disable notification */
#if (STD_ON == PORT_ICU_DRV_GET_INPUT_STATE_API)
    boolean InputStatus;     /* Store the input status*/
#endif
} Port_Icu_Drv_ChannelStateType;

/**
 * @brief Structure that driver configuration
 */
typedef struct
{
    uint32 ChSumNum; /*!< Number of input capture channel used */
    const Port_Icu_Drv_ChannelConfigType (*ChCfgPtr)[]; /*!< Edge detection channels configuration */
} Port_Icu_Drv_InstanceConfigType;

/**
 * @brief used by the drv driver for internal logic
 */
typedef struct
{
    boolean InstInitFlag;   /*!< Module initialization state
                             - TRUE: initialization 
                             - FALSE: de-initialization */
} Port_Icu_Drv_InstanceStateType;


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

/** @} end of group Port_Icu_Drv  */
/** @} end of group Icu_Module */

#endif  /* PORT_ICU_DRV_TYPES_H */

