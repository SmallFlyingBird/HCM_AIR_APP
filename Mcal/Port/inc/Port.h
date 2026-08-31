/**
 * @file    Port.h
 * @version
 *
 * @brief   AUTOSAR Port module interface
 * @details API implementation for PORT driver
 *
 * @addtogroup PORT_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Port
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef PORT_H
#define PORT_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Port_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Port_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */

/* PRQA S 3630 EOF */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Port_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_VENDOR_ID                      (180)
#define PORT_AR_RELEASE_MAJOR_VERSION       (4)
#define PORT_AR_RELEASE_MINOR_VERSION       (4)
#define PORT_AR_RELEASE_REVISION_VERSION    (0)
#define PORT_SW_MAJOR_VERSION               (2)
#define PORT_SW_MINOR_VERSION               (3)
#define PORT_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PORT configuration header file are of the same vendor */
#if (PORT_VENDOR_ID != PORT_VENDOR_ID_CFG)
#error "Port.h and Port_Cfg.h have different vendor ids"
#endif

/* Check if source file and PORT configuration header file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (PORT_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (PORT_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Port.h and Port_Cfg.h are different"
#endif

/* Check if source file and PORT configuration header file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION_CFG) || \
     (PORT_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION_CFG) || \
     (PORT_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Port.h and Port_Cfg.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief PORT MODULE INSTANCE ID */
#define PORT_INSTANCE_ID                    ((uint8)0U)

/** @brief PORT MODULE ID */
#define PORT_MODULE_ID                      (124U)

#if (PORT_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        PORT_DEV_ERROR
 * @brief           PORT development errors
 * @{
 */
/** @brief Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                    ((uint8)0x0A)
/** @brief Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE       ((uint8)0x0B)
/** @brief API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG                 ((uint8)0x0C)
/** @brief API Port_SetPinMode service called when paramater invalid mode */
#define PORT_E_PARAM_INVALID_MODE           ((uint8)0x0D)
/** @brief API Port_SetPinMode service called when mode unchangeable */
#define PORT_E_MODE_UNCHANGEABLE            ((uint8)0x0E)
/** @brief API service called without module initialization */
#define PORT_E_UNINIT                       ((uint8)0x0F)
/** @brief APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                ((uint8)0x10)
/** @} */

/**
 * @defgroup        PORT_SID
 * @brief           Service ID number for all PORT driver services
 */
/** @{ */
/** @brief API Service ID for Port_GetVersionInfo */
#define PORT_SID_GET_VERSION_INFO           (0x03U)
/** @brief API Service ID for Port_Init */
#define PORT_SID_INIT                       (0x00U)
/** @brief API Service ID for Port_RefreshPortDirection */
#define PORT_SID_REFRESH_PORT_SID_DIRECTION (0x02U)
/** @brief API Service ID for Port_SetPinDirection */
#define PORT_SID_SET_PIN_DIRECTION          (0x01U)
/** @brief API Service ID for Port_SetPinMode */
#define PORT_SID_SET_PIN_MODE               (0x04U)
/** @} */
#endif

/**
 @brief Pin masked(available) define.
 */
#define PORT_PIN_NOT_MASKED     ((uint32)0U) /**< Port Pin is available in the hardware */
#define PORT_PIN_MASKED         ((uint32)1U) /**< Port Pin is not available in the hardware */

/**
 * @brief Total number of hardware
 * @note Strong relationship to the hardware
 */
#define PORT_TOTAL_NUMBER       (5U)

/**
 * @brief Total number of hardware one port pins
 * @note Strong relationship to the hardware
 */
#define PORT_PIN_TOTAL_NUMBER   (32U)

/**
 @brief Port ID and Pin ID masked(available) define.
 */
#define PORT_HW_ID_PIN_MASK ((Port_PinType)0x00FF)  /**< Port ID mask: Highest 8 bit of half word */
#define PORT_HW_ID_PORT_MASK ((Port_PinType)0xFF00) /**< Port ID mask: Lowest 8 bit of half word */
#define PORT_HW_PIN(Pin) ((Port_HwPinType)Pin)

/**
 * @defgroup PORT_HW_ID
 * @brief Hardware Port ID define.
 */
/** @{ */
#define PORT_HW_PORT_A ((Port_HwPortType)0) /**< Hardware PORT A ID */
#define PORT_HW_PORT_B ((Port_HwPortType)1) /**< Hardware PORT B ID */
#define PORT_HW_PORT_C ((Port_HwPortType)2) /**< Hardware PORT C ID */
#define PORT_HW_PORT_D ((Port_HwPortType)3) /**< Hardware PORT D ID */
#define PORT_HW_PORT_E ((Port_HwPortType)4) /**< Hardware PORT E ID */
/** @} */

/** @brief Port Pin Mode Type Nums */

#if defined (CPU_YTM32B1HA0)
#define PORT_PIN_MODE_NUMS             ((uint8)16U)
#else
#define PORT_PIN_MODE_NUMS             ((uint8)8U)
#endif

/** @brief Port Alternate 0 Mode */
#define PORT_PIN_MODE_ANA              ((Port_PinModeType)0)
/** @brief Port GPIO Mode */
#define PORT_PIN_MODE_GPIO             ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_PIN_MODE_ALT2             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_PIN_MODE_ALT3             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_PIN_MODE_ALT4             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_PIN_MODE_ALT5             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_PIN_MODE_ALT6             ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_PIN_MODE_ALT7             ((Port_PinModeType)7)

#if defined (CPU_YTM32B1HA0)
/** @brief Port Alternate 8 Mode */
#define PORT_PIN_MODE_ALT8             ((Port_PinModeType)8)
/** @brief Port Alternate 9 Mode */
#define PORT_PIN_MODE_ALT9             ((Port_PinModeType)9)
/** @brief Port Alternate 10 Mode */
#define PORT_PIN_MODE_ALT10            ((Port_PinModeType)10)
/** @brief Port Alternate 11 Mode */
#define PORT_PIN_MODE_ALT11            ((Port_PinModeType)11)
/** @brief Port Alternate 12 Mode */
#define PORT_PIN_MODE_ALT12            ((Port_PinModeType)12)
/** @brief Port Alternate 13 Mode */
#define PORT_PIN_MODE_ALT13            ((Port_PinModeType)13)
/** @brief Port Alternate 14 Mode */
#define PORT_PIN_MODE_ALT14            ((Port_PinModeType)14)
/** @brief Port Alternate 15 Mode */
#define PORT_PIN_MODE_ALT15            ((Port_PinModeType)15)
#endif

/**
 * @brief Hardware Port pin ID define
 */
#define PORT_HW_PORT_PIN(Port, Pin) (((Port_PinType)Port << 8) + ((Port_PinType)Pin))

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief Port pin direction
 * @note Class: Stander-typedef
 *       Trace: SWS_Port_00230
 */
typedef enum
{
    PORT_PIN_IN = 0,  /**< Port Pin direction is in */
    PORT_PIN_OUT = 1, /**< Port Pin direction is out */
} Port_PinDirectionType;

/**
 * @brief Port pin level
 * @note Class : Vendor-typedef
 */
typedef enum
{
    PORT_PIN_LEVEL_LOW = 0U,  /**< Port Pin Level is low */
    PORT_PIN_LEVEL_HIGH = 1U, /**< Port Pin Level is high */
    PORT_PIN_LEVEL_NOTCHANGED = 2U, /**< Port Pin Level is not changed */
} Port_PinLevelType;

/**
 * @brief The pin mode is changeable on a port pin during runtime.
 * @note Class : Vendor-typedef
 */
typedef enum
{
    PORT_PIN_MODE_NOT_CHANGEABLE = 0U, /**< Port Pin mode unchangeable */
    PORT_PIN_MODE_CHANGEABLE = 1U,     /**< Port Pin mode changeable */
} Port_PinModeChangeableType;

/**
 * @brief The pin direction is changeable on a port pin during runtime.
 * @note Class : Vendor-typedef
 */
typedef enum
{
    PORT_PIN_DIRECTION_UNCHANGEABLE = 0U,   /**< Port Pin direction unchangeable */
    PORT_PIN_DIRECTION_CHANGEABLE = 1U,     /**< Port Pin direction changeable */
} Port_PinDirectionChangeableType;

/**
 * @brief The port pin pull state
 * @note Class : Vendor-typedef
 */
typedef enum
{
    PORT_PIN_NO_PULL = 0U,  /**< Port Pin no pull */
    PORT_PIN_PULLDOWN = 1U, /**< Port Pin pull down */
    PORT_PIN_PULLUP = 2U,   /**< Port Pin pull up */
} Port_PinPullConfigType;


#if (PORT_HAS_SLEW_RATE == STD_ON)
/**
 * @brief The port pin slew rate
 * @note Class : Vendor-typedef
 */
typedef enum
{
    PORT_PIN_FAST_SLEW_RATE = 0U, /**< Port Pin in fast slew rate */
    PORT_PIN_SLOW_SLEW_RATE = 1U, /**< Port Pin in low slew rate */
} Port_PinSlewRateType;
#endif

/**
 * @brief The port pin drive strength
 * @note Class : Vendor-typedef
 */
typedef enum
{
    PORT_PIN_LOW_DRIVE_STRENGTH  = 0U, /**< Port Pin in fast slew rate */
    PORT_PIN_HIGH_DRIVE_STRENGTH = 1U, /**< Port Pin in low slew rate */
} Port_PinDriveStrengthType;


/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/
/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements Port_PinModeType_typedef
*/
typedef uint8 Port_PinModeType;

/**
 * @brief Data type for the symbolic name of a port pin
 * @note Trace: SWS_Port_00229
 */
typedef uint16 Port_PinType;

/**
 * @brief Hardware pin ID type
 * @note Class: Vendor-typedef
 */
typedef uint8 Port_HwPinType;

/**
 * @brief Hardware port ID type
 * @note Class: Vendor-typedef
 */
typedef uint8 Port_HwPortType;

/**
 * @brief Hardware port pin ID type
 * @note Class: Vendor-typedef
 */
typedef struct
{
    Port_HwPinType PinId;   /*!< Pin ID */
    Port_HwPortType PortId; /*!< Port ID */
} Port_HwPortPinType;

/**
 * @brief One pin config type
 * @note Class: Vendor-typedef
 *       trace:
 */
typedef struct
{
    Port_HwPinType HwPinId;                                 /**< Pin id */
    Port_PinDirectionType Direction;                        /**< Pin init. direction */
    Port_PinDirectionChangeableType IsDirectionChangeable;  /**< Pin direction changeable set */
    Port_PinLevelType InitLevel;                            /**< Pin init. level */
    Port_PinModeType InitMode;                              /**< Pin init. mode */
    Port_PinModeChangeableType IsModeChangeable;            /**< Pin mode changeable set */
    Port_PinPullConfigType PullConfig;                      /**< Pin mode changeable set */
    Port_PinDriveStrengthType DriveStrength;                /**< Pin drive strength set */
#if (PORT_HAS_SLEW_RATE == STD_ON)
    Port_PinSlewRateType SlewRate;                          /**< Pin slew rate set */
#endif
    boolean PassiveFilter;                                  /**< Pin passive filter enable/disable set, if the pin is configured as a digital input*/
#if (PORT_HAS_DIGITAL_FILTER == STD_ON)
    boolean DigitalFilter;                                  /**< Pin digital filter enable/disable set, if the pin is configured as a digital input*/
    uint8   DigitalFilterWidth;                             /**< Pin digital filter width set, if the pin is configured as a digital input*/
#endif
    boolean InvertEnable;                                   /**< Pin invert enable/disable set, if the pin is configured as a digital input*/
} Port_PinConfigType;

/**
 * @brief Type of the external data structure containing the initialization
 *        data for this module
 * @note Trace: SWS_Port_00228
 */
typedef struct
{
    uint8 NumberOfPortPins;                     /**< Valid pin numbers of port */
    Port_HwPortType HwPortId;                   /**< Port ID */
    const Port_PinConfigType *PortPinConfigPtr; /**< Port pins config pointer */
} Port_GroupConfigType;


typedef struct
{
    uint8 NumberOfGroup;                            /**< Valid pin numbers of port */
    const Port_GroupConfigType *PortGroupConfigPtr; /**< Port pins config pointer */
} Port_ConfigType;

/*==================================================================================================
 *                                        EXTERNAL CONSTANTS
==================================================================================================*/
/** @brief Declaration of port post build configuration */
#if (PORT_FIXED_PB_CONFIG == STD_ON)
extern const Port_ConfigType Port_PinsConfig[];
#endif

/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief            Initializes the Port Driver module.
 * @param[in]        ConfigPtr Pointer to configuration set.
 * @return           void
 */
void Port_Init(const Port_ConfigType *ConfigPtr);

/**
 * @brief            Refreshes port direction.
 * @return           void
 */
void Port_RefreshPortDirection(void);

#if (PORT_SET_PIN_MODE_API == STD_ON)
/**
 * @brief            Sets the port pin direction
 * @param[in]        Pin Port Pin ID number
 * @param[in]        Direction Port Pin Direction
 * @return           void
 */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
/**
 * @brief            Sets the port pin mode.
 * @param[in]        Pin Port Pin ID number
 * @param[in]        Mode New Port Pin mode to be set on port pin.
 * @return           void
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

#if (((PORT_VERSION_INFO_API == STD_ON) && (PORT_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @param[in,out]    versioninfo Pointer to where to store version information of this module
 * @return           none
 */
#define Port_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: PORT_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report PORT_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)PORT_MODULE_ID,                                        \
                PORT_INSTANCE_ID,                                              \
                PORT_GET_VERSION_INFO_SID,                                     \
                PORT_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = PORT_VENDOR_ID; \
            /* Port module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = PORT_MODULE_ID; \
            /* Port module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)PORT_SW_MAJOR_VERSION;                                      \
            /* Port module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)PORT_SW_MINOR_VERSION;                                      \
            /* Port module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)PORT_SW_PATCH_VERSION;                                      \
        }                                                                      \
    }
#elif (((PORT_VERSION_INFO_API == STD_ON) && (PORT_DEV_ERROR_DETECT == STD_OFF)))
#define Port_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = PORT_VENDOR_ID; \
        /* Port module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = PORT_MODULE_ID; \
        /* Port module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)PORT_SW_MAJOR_VERSION;                                      \
        /* Port module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)PORT_SW_MINOR_VERSION;                                      \
        /* Port module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)PORT_SW_PATCH_VERSION;                                      \
    }
#endif /* PORT_VERSION_INFO_API == STD_ON && PORT_DEV_ERROR_DETECT == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* PORT_H */

/** @} */

