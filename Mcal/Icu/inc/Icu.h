/**
 * @file    Icu.h
 * @version
 *
 * @brief   AUTOSAR Icu module interface
 * @details API implementation for ICU driver
 *
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Icu
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

#ifndef ICU_H
#define ICU_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Icu_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case
 * sensitivity are supported for external identifiers. The used
 * compilers/linkers allow more than 31 characters significance for external
 * identifiers.
 *
 * @section Icu_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case
 * sensitivity are supported for external identifiers. The used
 * compilers/linkers allow more than 31 characters significance for external
 * identifiers.
 */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "EcuM.h"
#include "Icu_Base.h"
#include "Icu_Cfg.h"
#include "Std_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID                      (0xB4)
#define ICU_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_SW_MAJOR_VERSION               (2)
#define ICU_SW_MINOR_VERSION               (3)
#define ICU_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU configuration header file are of the same vendor
 */
#if (ICU_VENDOR_ID != ICU_VENDOR_ID_CFG)
#error "Icu.h and Icu_Cfg.h have different vendor ids"
#endif

/* Check if source file and ICU configuration header file are of the same
 * Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG) ||                     \
     (ICU_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG) ||                     \
     (ICU_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Icu.h and Icu_Cfg.h are different"
#endif

/* Check if source file and ICU configuration header file are of the same
 * software version */
#if ((ICU_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION_CFG) ||                             \
     (ICU_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION_CFG) ||                             \
     (ICU_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu.h and Icu_Cfg.h are different"
#endif
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/

typedef void (*Icu_TimestampNotificationType)(
    void); /**< @brief Pointer to a function that is called when a timestamp
              notification occurs */
typedef void (*Icu_EdgeNotificationType)(
    void); /**< @brief Pointer to a function that is called when an edge
              notification occurs */

#define ICU_INSTANCE_ID_MASK (0xFF00U) /** ICU instance ID mask */
#define ICU_CHANNEL_ID_MASK (0x00FFU)  /** ICU channel ID mask */
#define ICU_INSTANCE_SHIFT  (8U)

#define ICU_INSTANCE_ID (6U) /** ICU instance ID */
/**
 * @brief API service ID for Icu_Init function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_INIT_ID (0x00U)
/**
 * @brief API service ID for Icu_DeInit function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_DEINIT_ID (0x01U)

#if (ICU_SET_MODE_API == STD_ON)
/**
 * @brief API service ID for Icu_SetMode function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_SETMODE_ID (0x02U)
#endif

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/**
 * @brief API service ID for Icu_DisableWakeup function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_DISABLEWAKEUP_ID (0x03U)

#endif

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
/**
 * @brief API service ID for Icu_EnableWakeup function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_ENABLEWAKEUP_ID (0x04U)

#endif

/**
 * @brief API service ID for Icu_SetActivationCondition function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_SETACTIVATIONCONDITION_ID (0x05U)

/**
 * @brief API service ID for Icu_DisableNotification function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_DISABLENOTIFICATION_ID (0x06U)

/**
 * @brief API service ID for Icu_EnableNotification function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_ENABLENOTIFICATION_ID (0x07U)

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief API service ID for Icu_GetInputState function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_GETINPUTSTATE_ID (0x08U)
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief API service ID for Icu_StartTimestamp function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_STARTTIMESTAMP_ID (0x09U)

/**
 * @brief API service ID for Icu_GetTimestampIndex function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_GETTIMESTAMPINDEX_ID (0x0BU)
#endif

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
 * @brief API service ID for Icu_ResetEdgeCount function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_RESETEDGECOUNT_ID (0x0CU)

/**
 * @brief API service ID for Icu_EnableEdgeCount function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_ENABLEEDGECOUNT_ID (0x0DU)

/**
 * @brief API service ID for Icu_DisableEdgeCount function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_DISABLEEDGECOUNT_ID (0x0EU)

/**
 * @brief API service ID for Icu_GetEdgeNumbers function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_GETEDGENUMBERS_ID (0x0FU)
#endif /* (STD_ON == ICU_EDGE_COUNT_API) */

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
/**
 * @brief API service ID for Icu_GetTimeElapsed function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_GETTIMEELAPSED_ID (0x10U)
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/**
 * @brief API service ID for Icu_GetDutyCycleValues function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_GETDUTYCYCLEVALUES_ID (0x11U)
#endif

/**
 * @brief API service ID for Icu_GetVersionInfo function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_GETVERSIONINFO_ID (0x12U)

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
 * @brief API service ID for Icu_StartSignalMeasurement function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_STARTSIGNALMEASUREMENT_ID (0x13U)

/**
 * @brief API service ID for Icu_StopSignalMeasurement function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_STOPSIGNALMEASUREMENT_ID (0x14U)
#endif /* (STD_ON == ICU_SIGNAL_MEASUREMENT_API) */

/**
 * @brief API service ID for Icu_EnableEdgeDetection function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_ENABLEEDGEDETECTION_ID (0x16U)

/**
 * @brief API service ID for Icu_DisableEdgeDetection function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_DISABLEEDGEDETECTION_ID (0x17U)

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief API service ID for Icu_StopTimestamp function
 * @details Parameters used when raising an error/exception
 * */
#define ICU_STOPTIMESTAMP_ID (0x0AU)

#endif

/** @brief ICU MODULE ID */
#define ICU_MODULE_ID (122U)

#if (ICU_DEV_ERROR_DETECT == STD_ON)

/** @brief ICU API service is called using an invalid pointer (e.g. the pointer
 * should not be NULL).  */
#define ICU_E_PARAM_POINTER (0x0AU)
/** @brief API service used with an invalid channel identifier or channel was
 * not configured for the functionality of the calling API. */
#define ICU_E_PARAM_CHANNEL (0x0BU)
/** @brief API service used with an invalid or not feasible activation */
#define ICU_E_PARAM_ACTIVATION (0x0CU)
/** @brief Init function failed */
#define ICU_E_INIT_FAILED (0x0DU)
/** @brief API service used with an invalid buffer size */
#define ICU_E_PARAM_BUFFER_SIZE (0x0EU)
/** @brief API service Icu_SetMode used with an invalid mode */
#define ICU_E_PARAM_MODE (0x0FU)
/** @brief API service used without module initialization */
#define ICU_E_UNINIT (0x14U)
/** @brief API service Icu_SetMode is called while a running operation */
#define ICU_E_BUSY_OPERATION (0x16U)
/** @brief API Icu_Init service is called and when the ICU driver and the
 * Hardware are already initialized. */
#define ICU_E_ALREADY_INITIALIZED (0x17U)
/** @brief API Icu_StartTimeStamp is called and the parameter NotifyInterval is
 * invalid */
#define ICU_E_PARAM_NOTIFY_INTERVAL (0x18U)
/** @brief API Icu_GetVersionInfo is called and the parameter versioninfo is is
 * invalid */
#define ICU_E_PARAM_VINFO (0x19U)
/** @brief API Icu_EnableEdgeCount shall be available for each ICU channel in
 * Measurement Mode "Edge Counter" */
#define ICU_E_INIT_CONFIG_MEASUREMENT_MODE (0x10U)
#endif

/*Runtime Errors*/
/** @brief API service Icu_StopTimestamp called on a channel which was not
 * started or already stopped */
#define ICU_E_NOT_STARTED (0x15U)



/**
 * @brief API service ID for Icu_SetMode function
 * @details Parameters used when raising an error/exception
 * */
#if defined (CPU_YTM32B1MC0)
#define ICU_ETMR_MC_CHANNEL_COUNT (2U)
#define ETMR_ICU_CHANNEL_COUNT (8U)
#else
#define ICU_ETMR_MC_CHANNEL_COUNT (6U)
#define ETMR_ICU_CHANNEL_COUNT (8U)
#endif
#if (ICU_FIXED_PB_CONFIG == STD_ON)
#define ICU_MAX_CHANNEL                                                        \
  ICU_USE_CHANNEL /**< @brief Maximum number of channels on post-build*/
#else
#define ICU_MAX_CHANNEL                                                        \
  (ICU_ETMR_MC_CHANNEL_COUNT *                                                 \
   ETMR_ICU_CHANNEL_COUNT) /**< @brief Maximum number of channels on           \
                              pre-compile */
#endif
#define ICU_CMP_MAX (1U) /**< @brief Maximum number of channels */

#if defined(CPU_YTM32B1ME0)
#define ICU_WKUP_PORT_MAX                                                      \
  (32U + 1U) /**< @brief Maximum number of wakeup ports */
#elif defined(CPU_YTM32B1MD1)
#define ICU_WKUP_PORT_MAX                                                      \
  (16U + 1U) /**< @brief Maximum number of wakeup ports */
#elif defined(CPU_YTM32B1HA0)
#define ICU_WKUP_PORT_MAX                                                      \
  (64U + 1U) /**< @brief Maximum number of wakeup ports */
#elif defined(CPU_YTM32B1MC0)
#if defined(YTM32B1MC_LQFP64)
#define ICU_WKUP_PORT_MAX (58U+1U) /**< @brief Maximum number of wakeup ports */
#elif defined(YTM32B1MC_QFN48) || defined(YTM32B1MC_LQFP48)
#define ICU_WKUP_PORT_MAX (43U+1U) /**< @brief Maximum number of wakeup ports */
#endif
#endif
#define ICU_WKU_REG_ADDR8_READ(address)                                        \
  (*(volatile uint8 *)(address)) /*!< Read 8bit register */
#define ICU_WKU_REG_ADDR8_WRITE(address, value)                                \
  ((*(volatile uint8 *)(address)) = (value)) /*!< Write 8bit register */

#define ICU_WKU_REG_ADDR8_AEARWRITE(address, mask, value)                      \
  (ICU_WKU_REG_ADDR8_WRITE(                                                    \
      (address), ((ICU_WKU_REG_ADDR8_READ(address) & ((uint8) ~(mask))) |      \
                  (value)))) /*!< Write 8bit register with mask */

#define ICU_WKU_REG_ADDR32_READ(address)                                       \
  (*(volatile uint32 *)(address)) /*!< Read 32bit register */
#define ICU_WKU_REG_ADDR32_WRITE(address, value)                               \
  ((*(volatile uint32 *)(address)) = (value)) /*!< Write 32bit register */

#define ICU_WKU_REG_ADDR32_AEARWRITE(address, mask, value)                     \
  (ICU_WKU_REG_ADDR32_WRITE(                                                   \
      (address), ((ICU_WKU_REG_ADDR32_READ(address) & ((uint32) ~(mask))) |    \
                  (value)))) /*!< Write 32bit register with mask */
/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/

typedef uint32 Icu_IndexType; /*!< ICU Index Type*/

typedef uint32 Icu_ChannelType; /*!< ICU Channel Type*/

typedef uint32 Icu_ValueType;

typedef uint32 Icu_EdgeNumberType;
typedef enum
{
    ICU_ETMR_0_CH_0 = 0x00U, /**< @brief ICU_ETMR_0_CH_0 */
    ICU_ETMR_0_CH_1 = 0x01U, /**< @brief ICU_ETMR_0_CH_1 */
    ICU_ETMR_0_CH_2 = 0x02U, /**< @brief ICU_ETMR_0_CH_2 */
    ICU_ETMR_0_CH_3 = 0x03U, /**< @brief ICU_ETMR_0_CH_3 */
    ICU_ETMR_0_CH_4 = 0x04U, /**< @brief ICU_ETMR_0_CH_4 */
    ICU_ETMR_0_CH_5 = 0x05U, /**< @brief ICU_ETMR_0_CH_5 */
    ICU_ETMR_0_CH_6 = 0x06U, /**< @brief ICU_ETMR_0_CH_6 */
    ICU_ETMR_0_CH_7 = 0x07U, /**< @brief ICU_ETMR_0_CH_7 */

    ICU_ETMR_1_CH_0 = 0x0100U, /**< @brief ICU_ETMR_1_CH_0 */
    ICU_ETMR_1_CH_1 = 0x0101U, /**< @brief ICU_ETMR_1_CH_1 */
    ICU_ETMR_1_CH_2 = 0x0102U, /**< @brief ICU_ETMR_1_CH_2 */
    ICU_ETMR_1_CH_3 = 0x0103U, /**< @brief ICU_ETMR_1_CH_3 */
    ICU_ETMR_1_CH_4 = 0x0104U, /**< @brief ICU_ETMR_1_CH_4 */
    ICU_ETMR_1_CH_5 = 0x0105U, /**< @brief ICU_ETMR_1_CH_5 */
    ICU_ETMR_1_CH_6 = 0x0106U, /**< @brief ICU_ETMR_1_CH_6 */
    ICU_ETMR_1_CH_7 = 0x0107U, /**< @brief ICU_ETMR_1_CH_7 */

    ICU_ETMR_2_CH_0 = 0x0200U, /**< @brief ICU_ETMR_2_CH_0 */
    ICU_ETMR_2_CH_1 = 0x0201U, /**< @brief ICU_ETMR_2_CH_1 */
    ICU_ETMR_2_CH_2 = 0x0202U, /**< @brief ICU_ETMR_2_CH_2 */
    ICU_ETMR_2_CH_3 = 0x0203U, /**< @brief ICU_ETMR_2_CH_3 */
    ICU_ETMR_2_CH_4 = 0x0204U, /**< @brief ICU_ETMR_2_CH_4 */
    ICU_ETMR_2_CH_5 = 0x0205U, /**< @brief ICU_ETMR_2_CH_5 */
    ICU_ETMR_2_CH_6 = 0x0206U, /**< @brief ICU_ETMR_2_CH_6 */
    ICU_ETMR_2_CH_7 = 0x0207U, /**< @brief ICU_ETMR_2_CH_7 */

    ICU_ETMR_3_CH_0 = 0x0300U, /**< @brief ICU_ETMR_3_CH_0 */
    ICU_ETMR_3_CH_1 = 0x0301U, /**< @brief ICU_ETMR_3_CH_1 */
    ICU_ETMR_3_CH_2 = 0x0302U, /**< @brief ICU_ETMR_3_CH_2 */
    ICU_ETMR_3_CH_3 = 0x0303U, /**< @brief ICU_ETMR_3_CH_3 */
    ICU_ETMR_3_CH_4 = 0x0304U, /**< @brief ICU_ETMR_3_CH_4 */
    ICU_ETMR_3_CH_5 = 0x0305U, /**< @brief ICU_ETMR_3_CH_5 */
    ICU_ETMR_3_CH_6 = 0x0306U, /**< @brief ICU_ETMR_3_CH_6 */
    ICU_ETMR_3_CH_7 = 0x0307U, /**< @brief ICU_ETMR_3_CH_7 */

    ICU_ETMR_4_CH_0 = 0x0400U, /**< @brief ICU_ETMR_4_CH_0 */
    ICU_ETMR_4_CH_1 = 0x0401U, /**< @brief ICU_ETMR_4_CH_1 */
    ICU_ETMR_4_CH_2 = 0x0402U, /**< @brief ICU_ETMR_4_CH_2 */
    ICU_ETMR_4_CH_3 = 0x0403U, /**< @brief ICU_ETMR_4_CH_3 */
    ICU_ETMR_4_CH_4 = 0x0404U, /**< @brief ICU_ETMR_4_CH_4 */
    ICU_ETMR_4_CH_5 = 0x0405U, /**< @brief ICU_ETMR_4_CH_5 */
    ICU_ETMR_4_CH_6 = 0x0406U, /**< @brief ICU_ETMR_4_CH_6 */
    ICU_ETMR_4_CH_7 = 0x0407U, /**< @brief ICU_ETMR_4_CH_7 */

    ICU_ETMR_5_CH_0 = 0x0500U, /**< @brief ICU_ETMR_5_CH_0 */
    ICU_ETMR_5_CH_1 = 0x0501U, /**< @brief ICU_ETMR_5_CH_1 */
    ICU_ETMR_5_CH_2 = 0x0502U, /**< @brief ICU_ETMR_5_CH_2 */
    ICU_ETMR_5_CH_3 = 0x0503U, /**< @brief ICU_ETMR_5_CH_3 */
    ICU_ETMR_5_CH_4 = 0x0504U, /**< @brief ICU_ETMR_5_CH_4 */
    ICU_ETMR_5_CH_5 = 0x0505U, /**< @brief ICU_ETMR_5_CH_5 */
    ICU_ETMR_5_CH_6 = 0x0506U, /**< @brief ICU_ETMR_5_CH_6 */
    ICU_ETMR_5_CH_7 = 0x0507U, /**< @brief ICU_ETMR_5_CH_7 */
} Icu_EtmrChannelType;       /*PRQA S 1535 */
typedef enum
{
    ICU_PORT_0 = 0x00U,  /**< @brief ICU_PORT_A */
    ICU_PORT_1 = 0x01U,  /**< @brief ICU_PORT_B */
    ICU_PORT_2 = 0x02U,  /**< @brief ICU_PORT_C */
    ICU_PORT_3 = 0x03U,  /**< @brief ICU_PORT_D */
    ICU_PORT_4 = 0x04U,  /**< @brief ICU_PORT_E */
} Icu_PortChannelType; /*PRQA S 1535 */

#if defined(CPU_YTM32B1HA0)
typedef enum
{
    ICU_MPWM_0_CH_0 = 0x00U, /**< @brief ICU_MPWM_0_CH_0 */
    ICU_MPWM_0_CH_1 = 0x01U, /**< @brief ICU_MPWM_0_CH_1 */
    ICU_MPWM_0_CH_2 = 0x02U, /**< @brief ICU_MPWM_0_CH_2 */
    ICU_MPWM_0_CH_3 = 0x03U, /**< @brief ICU_MPWM_0_CH_3 */
    ICU_MPWM_0_CH_4 = 0x04U, /**< @brief ICU_MPWM_0_CH_4 */
    ICU_MPWM_0_CH_5 = 0x05U, /**< @brief ICU_MPWM_0_CH_5 */
    ICU_MPWM_0_CH_6 = 0x06U, /**< @brief ICU_MPWM_0_CH_6 */
    ICU_MPWM_0_CH_7 = 0x07U, /**< @brief ICU_MPWM_0_CH_7 */
    ICU_MPWM_0_CH_8 = 0x08U, /**< @brief ICU_MPWM_0_CH_8 */
    ICU_MPWM_0_CH_9 = 0x09U, /**< @brief ICU_MPWM_0_CH_9 */
    ICU_MPWM_0_CH_10 = 0x0AU, /**< @brief ICU_MPWM_0_CH_10 */
    ICU_MPWM_0_CH_11 = 0x0BU, /**< @brief ICU_MPWM_0_CH_11 */
    ICU_MPWM_0_CH_12 = 0x0CU, /**< @brief ICU_MPWM_0_CH_12 */
    ICU_MPWM_0_CH_13 = 0x0DU, /**< @brief ICU_MPWM_0_CH_13 */
    ICU_MPWM_0_CH_14 = 0x0EU, /**< @brief ICU_MPWM_0_CH_14 */
    ICU_MPWM_0_CH_15 = 0x0FU, /**< @brief ICU_MPWM_0_CH_15 */

    ICU_MPWM_1_CH_0 = 0x1000U, /**< @brief ICU_MPWM_1_CH_0 */
    ICU_MPWM_1_CH_1 = 0x1001U, /**< @brief ICU_MPWM_1_CH_1 */
    ICU_MPWM_1_CH_2 = 0x1002U, /**< @brief ICU_MPWM_1_CH_2 */
    ICU_MPWM_1_CH_3 = 0x1003U, /**< @brief ICU_MPWM_1_CH_3 */
    ICU_MPWM_1_CH_4 = 0x1004U, /**< @brief ICU_MPWM_1_CH_4 */
    ICU_MPWM_1_CH_5 = 0x1005U, /**< @brief ICU_MPWM_1_CH_5 */
    ICU_MPWM_1_CH_6 = 0x1006U, /**< @brief ICU_MPWM_1_CH_6 */
    ICU_MPWM_1_CH_7 = 0x1007U, /**< @brief ICU_MPWM_1_CH_7 */
    ICU_MPWM_1_CH_8 = 0x1008U, /**< @brief ICU_MPWM_1_CH_8 */
    ICU_MPWM_1_CH_9 = 0x1009U, /**< @brief ICU_MPWM_1_CH_9 */
    ICU_MPWM_1_CH_10 = 0x100AU, /**< @brief ICU_MPWM_1_CH_10 */
    ICU_MPWM_1_CH_11 = 0x100BU, /**< @brief ICU_MPWM_1_CH_11 */
    ICU_MPWM_1_CH_12 = 0x100CU, /**< @brief ICU_MPWM_1_CH_12 */
    ICU_MPWM_1_CH_13 = 0x100DU, /**< @brief ICU_MPWM_1_CH_13 */
    ICU_MPWM_1_CH_14 = 0x100EU, /**< @brief ICU_MPWM_1_CH_14 */
    ICU_MPWM_1_CH_15 = 0x100FU, /**< @brief ICU_MPWM_1_CH_15 */

    ICU_MPWM_2_CH_0 = 0x2000U, /**< @brief ICU_MPWM_2_CH_0 */
    ICU_MPWM_2_CH_1 = 0x2001U, /**< @brief ICU_MPWM_2_CH_1 */
    ICU_MPWM_2_CH_2 = 0x2002U, /**< @brief ICU_MPWM_2_CH_2 */
    ICU_MPWM_2_CH_3 = 0x2003U, /**< @brief ICU_MPWM_2_CH_3 */
    ICU_MPWM_2_CH_4 = 0x2004U, /**< @brief ICU_MPWM_2_CH_4 */
    ICU_MPWM_2_CH_5 = 0x2005U, /**< @brief ICU_MPWM_2_CH_5 */
    ICU_MPWM_2_CH_6 = 0x2006U, /**< @brief ICU_MPWM_2_CH_6 */
    ICU_MPWM_2_CH_7 = 0x2007U, /**< @brief ICU_MPWM_2_CH_7 */
    ICU_MPWM_2_CH_8 = 0x2008U, /**< @brief ICU_MPWM_2_CH_8 */
    ICU_MPWM_2_CH_9 = 0x2009U, /**< @brief ICU_MPWM_2_CH_9 */
    ICU_MPWM_2_CH_10 = 0x200AU, /**< @brief ICU_MPWM_2_CH_10 */
    ICU_MPWM_2_CH_11 = 0x200BU, /**< @brief ICU_MPWM_2_CH_11 */
    ICU_MPWM_2_CH_12 = 0x200CU, /**< @brief ICU_MPWM_2_CH_12 */
    ICU_MPWM_2_CH_13 = 0x200DU, /**< @brief ICU_MPWM_2_CH_13 */
    ICU_MPWM_2_CH_14 = 0x200EU, /**< @brief ICU_MPWM_2_CH_14 */
    ICU_MPWM_2_CH_15 = 0x200FU, /**< @brief ICU_MPWM_2_CH_15 */
} Icu_MpwmHWChannelType; /*PRQA S 1535 */
#endif

#define ICU_CMP0 (0U)       /**< @brief ICU_CMP0 */
typedef struct              /*PRQA S 3630 */
{
    Icu_ValueType ActiveTime; /*!< ICU Active Time*/
    Icu_ValueType PeriodTime; /*!< ICU Period Time*/
} Icu_DutyCycleType;
typedef enum
{
    INTERNAL_TRIGGER = 0U, /**<    */
    EXTERNAL_TRIGGER = 1U, /**<    */
} IcuLptmrTriggerSourceType;
typedef void (*Icu_SignalNotificationType)(void);

#if WKU_SUPPORT == STD_ON
typedef void (*Icu_WakeUpNotificationType)(uint32 *WakeUpPortMask, uint8 WakeupPortRegion, uint8 ExternalWakeup);
#endif

typedef enum
{
    ICU_RISING_EDGE = 1U,  /**<    */
    ICU_FALLING_EDGE = 2U, /**<    */
    ICU_BOTH_EDGES = 3U,   /**<    */
} Icu_ActivationType;

typedef enum
{
    ICU_ETMR = 0U,  /**<    */
    ICU_LPTMR = 1U, /**<    */
    ICU_PORT = 2U,  /**<    */
    ICU_LPCMP = 3U, /**<    */
    ICU_MPWM = 4U,  /**<    */
    ICU_COUNT = 5U, /**<    */
} Icu_HwIPType;

typedef enum
{
    ICU_MODE_NORMAL = 0U, /**<    */
    ICU_MODE_SLEEP = 1U,  /**<    */
} Icu_ModeType;

typedef enum
{
    ICU_LOW_TIME = 0U,    /**<    */
    ICU_HIGH_TIME = 1U,   /**<    */
    ICU_PERIOD_TIME = 2U, /**<    */
    ICU_DUTY_CYCLE = 3U,  /**<    */
} Icu_SignalMeasurementPropertyType;

typedef enum
{
    ICU_LINEAR_BUFFER = 0U,   /**<    */
    ICU_CIRCULAR_BUFFER = 1U, /**<    */
} Icu_TimestampBufferType;
typedef enum
{
    CMP_IP_FUNCTIONALMODE_DISABLED = 0U, /*!< CMP is disabled */
    CMP_IP_FUNCTIONALMODE_CONTINUOUS_ONE_SHOT =
        1U, /*!< CMP is enabled in continuous one-shot mode */
    CMP_IP_FUNCTIONALMODE_CONTINUOUS_LOOP = 2U, /* PRQA S 0779*/
    /*!< CMP is enabled in continuous loop mode */
    CMP_IP_FUNCTIONALMODE_WINDOWED = 3U, /*!< CMP is enabled in windowed mode */
    CMP_IP_FUNCTIONALMODE_SAMPLED = 4U,  /*!< CMP is enabled in sampled mode */
    CMP_IP_FUNCTIONALMODE_COMMON = 5U,   /*!< CMP is enabled in common mode */
} IcuCmpFunctionalType;

typedef enum
{
    CMP_IP_OFFSETLEVEL_0 = 0U, /*!< Offset level 0 */
    CMP_IP_OFFSETLEVEL_1 = 1U, /*!< Offset level 1 */
} IcuCmpOffsetLevelType;
typedef enum
{
    CMP_IP_INPUTMUX_IN0 = 0U, /*!< CMP input mux in0 */
    CMP_IP_INPUTMUX_IN1 = 1U, /*!< CMP input mux in1 */
    CMP_IP_INPUTMUX_IN2 = 2U, /*!< CMP input mux in2 */
    CMP_IP_INPUTMUX_IN3 = 3U, /*!< CMP input mux in3 */
    CMP_IP_INPUTMUX_IN4 = 4U, /*!< CMP input mux in4 */
    CMP_IP_INPUTMUX_IN5 = 5U, /*!< CMP input mux in5 */
    CMP_IP_INPUTMUX_IN6 = 6U, /*!< CMP input mux in6 */
    CMP_IP_INPUTMUX_IN7 = 7U, /*!< CMP input mux in7 */
    CMP_IP_INPUTMUX_DAC = 8U, /*!< CMP input mux DAC */
} IcuCmpInputMuxType;


#if 0 /*default set to 0*/
typedef enum
{
    CMP_IP_VOLTAGEREFSOURCE_VREF0 = 0U,  /*!< Voltage reference source VREF0 */
    CMP_IP_VOLTAGEREFSOURCE_VREF1 = 1U,  /*!< Voltage reference source VREF1 */
} IcuDacVoltageRefSourceType;
typedef enum
{
    CMP_IP_DACPOWERSTATE_DISABLED = 0U, /*!< DAC is disabled */
    CMP_IP_DACPOWERSTATE_ENABLED = 1U,  /*!< DAC is enabled */
} IcuDacPowerStateType;
#endif
typedef enum
{
    CMP_COMMON_MODE = 0U,     /**< Common Mode */
    CMP_SAMPLED_MODE = 1U,    /**< Sampled Mode */
    CMP_WINDOWED_MODE = 2U,   /**< Windowed Mode */
    CMP_CONTINUOUS_MODE = 3U, /**< Continuous Mode */
} IcuCmpSampleModeType;

typedef enum
{
    CMP_HIGH_SPEED_MODE = 0U, /**<High speed mode */
    CMP_LOW_POWER_MODE = 1U,  /**<Low power mode */
} IcuCmpPowerModeType;

typedef enum
{
    ICU_CMP_FIX_NEGATIVE = 0U, /**<Cmp Fix Negative */
    ICU_CMP_FIX_POSITIVE = 1U, /**<Cmp Fix Positive */
} IcuCmpFixChannelType;

typedef enum
{
    CMP_IP_CLK_SRC_IPC = 0U, /**<Cmp Functionnal Clock is Selcted by IPC Module */
    CMP_IP_CLK_SRC_SIRC = 1U, /**<Cmp Functionnal Clock is from SIRC */
    CMP_IP_CLK_SRC_SXOSC = 2U, /**<Cmp Functionnal Clock is from SXOSC */
} IcuCmpClockSourceType;

#if defined(CPU_YTM32B1HA0)
typedef enum
{
    ICU_MPWM_CONTINUOUS_MODE = 0U, /**< Continuous mode */
    ICU_MPWM_ONE_SHOT_MODE = 1U,    /**< One-shot mode */
} IcuMpwmCountModeType;
#endif

#if defined(CPU_YTM32B1HA0)
/*!
* @brief IcuMpwm prescale options
*/
typedef enum
{
    ICU_MPWM_PRESC_DIV_1    = 0U,  /**< Divide by 1   */
    ICU_MPWM_PRESC_DIV_2    = 1U,  /**< Divide by 2   */
    ICU_MPWM_PRESC_DIV_4    = 2U,  /**< Divide by 4   */
    ICU_MPWM_PRESC_DIV_8    = 3U,  /**< Divide by 8   */
    ICU_MPWM_PRESC_DIV_16   = 4U,  /**< Divide by 16  */
    ICU_MPWM_PRESC_DIV_32   = 5U,  /**< Divide by 32  */
    ICU_MPWM_PRESC_DIV_64   = 6U,  /**< Divide by 64  */
    ICU_MPWM_PRESC_DIV_128  = 7U,  /**< Divide by 128 */
} IcuMpwmPrescalerType;
#endif
/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/
typedef struct           /*PRQA S 3630 */
{
    boolean ExpectedValue; /*!< Init value,avoid generate int when init */
    boolean Enable;        /*!< ACMP enable */
} IcuExpectedChannelType;

typedef struct                             /*PRQA S 3630 */
{
    uint8 IcuCmpInstance;                    /*!< CMP instance number */
    IcuCmpFunctionalType IcuCmpFunctional;   /*!< CMP functional mode */
    IcuCmpOffsetLevelType IcuCmpOffsetLevel; /*!< CMP offset level */
    boolean IcuCmpEnablePinOutput;           /*!< CMP enable pin out */
    boolean IcuCmpEnableInverter;            /*!< CMP enable inverter */
    boolean IcuCmpEnableComparatorInvert;    /*!< CMP enable comparator invert */
    boolean IcuCmpEnableHighPowerMode;       /*!< CMP enable high power mode */

    uint8 IcuCmpFilterSamplePeriod; /*!< CMP filter sample period */
    uint8 IcuCmpFilterSampleCount;  /*!< CMP filter sample count */

    IcuCmpClockSourceType IcuCmpClockSource;   /*!< CMP functional clock source */

    IcuCmpInputMuxType IcuCmpNegativeInputMux; /*!< CMP negative input mux */
    IcuCmpInputMuxType IcuCmpPositiveInputMux; /*!< CMP positive input mux */
    IcuCmpFixChannelType IcuCmpFixChannel;     /*!< CMP fix channel */
    IcuExpectedChannelType *IcuCmpExpectedChannelPtr;    /*!< CMP expected channel Ptr */
    uint8 IcuCmpExpectedChannelCount; /*!< CMP expected channel count */
    /********************* DAC ***************************/
    uint8 IcuDacVoltageLevel; /*!< CMP DAC voltage level */
    boolean IcuDacEnable;     /*!< CMP DAC enable */
} Icu_LpCmpConfigType;

#if defined(CPU_YTM32B1HA0)
typedef struct       /*PRQA S 3630 */
{
    uint8 IcuMpwmChannel;     /*!< MPWM channel number */
    IcuMpwmPrescalerType IcuMpwmPrescaler;   /*!< MPWM prescaler */
    uint16 IcuMpwmPeriod;     /*!< MPWM period */
    IcuMpwmCountModeType IcuMpwmCountMode; /*!< MPWM count mode */
    boolean IcuMpwmDebug;     /*!< MPWM debug */
} IcuMpwmChannelType;

typedef struct                           /*PRQA S 3630 */
{
    uint8 IcuMpwmInstance;                  /*!< MPWM instance number */
    uint8 IcuMpwmInstanceCount;             /*!< MPWM instance count */
    uint8 IcuMpwmChannelCount;              /*!< MPWM channel count */
    IcuMpwmChannelType *IcuMpwmChannelPtr;  /*!< MPWM channel number Ptr */
} Icu_MpwmConfigType;
#endif
typedef struct       /*PRQA S 3630 */
{
    uint32 ChannelNum; /*!< eTMR Channel number */
} IcuEtmrChannelType;

typedef struct                           /*PRQA S 3630 */
{
    uint16 IcuEtmrModule;                  /*!< ETMR module number */
    uint16 IcuEtmrCount;                   /*!< ETMR instance number */
    IcuEtmrChannelType *IcuEtmrChannelPtr; /*!< ETMR channel number Ptr */
    uint16 IcuEtmrClockSource;             /*!< ETMR clock source */
    uint16 IcuEtmrClockOthers;           /*!< ETMR trigger source */
    uint16 IcuEtmrPrescaler;               /*!< ETMR prescaler */
    uint32 IcuEtmrModValue;                /*!< ETMR mod value */
} Icu_EtmrConfigType;
typedef struct                                     /*PRQA S 3630 */
{
    uint16 IcuLptmrModule;                           /*!< LPTMR module number */
    uint16 IcuLptmrChannel;                          /*!< LPTMR channel number */
    IcuLptmrTriggerSourceType IcuLptmrTriggerSource; /*!< LPTMR trigger source */
    uint16 IcuLptmrClockSource;                      /*!< LPTMR clock source */
    uint32 IcuLptmrPinSelect;                        /*!< LPTMR pin select */
} Icu_LptmrConfigType;

typedef struct       /*PRQA S 3630 */
{
    uint8 PortChannel; /*!< PORT channel number */
} IcuPortChannelType;

typedef struct                           /*PRQA S 3630 */
{
    uint16 IcuPortModule;                  /*!< PORT module number */
    uint16 IcuPortCount;                   /*!< PORT instance number */
    IcuPortChannelType *IcuPortChannelPtr; /*!< PORT channel number */
} Icu_PortConfigType;

typedef struct         /*PRQA S 3630 */
{
    uint16 IcuIsrHwId;   /*!< ICU Interrupt hardware ID */
    uint16 IcuIsrEnable; /*!< ICU Interrupt enable */
} Icu_HwInterruptConfigType;

typedef struct
{
    Icu_ChannelType IcuChannelId;               /*!< ICU channel ID */
    Icu_HwIPType IcuHwIp;                       /*!< ICU hardware IP */
    uint16 IcuHwIpInstance;                     /*!< ICU hardware IP instance */
    uint16 IcuHwChannel;                        /*!< ICU hardware channel */
    Icu_ActivationType IcuDefaultStartEdge;     /*!< ICU default start edge */
    Icu_MeasurementModeType IcuMeasurementMode; /*!< ICU measurement mode */
    boolean IcuWakeupCapability;                /*!< ICU wakeup capability */
#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
    EcuM_WakeupSourceType IcuWakeupSource;      /*!< ICU wakeup source */
#endif
    Icu_SignalMeasurementPropertyType
    SignalMeasurementProperty; /*!< ICU signal measurement property */

    Icu_TimestampBufferType
    TimestampBufferProperty; /*!< ICU timestamp buffer property */
    Icu_TimestampNotificationType
    TimestampNotificationPtr; /*!< ICU timestamp notification pointer */

    Icu_SignalNotificationType
    SignalNotificationPtr; /*!< ICU signal notification pointer */
} Icu_ChannelConfigType;

typedef struct
{
    Icu_ChannelConfigType *ChannelConfigPtr; /*!< ICU channel configuration pointer */
    Icu_EtmrConfigType *IcuEtmrConfigPtr; /*!< ICU ETMR configuration pointer */
    Icu_LptmrConfigType *IcuLptmrConfigPtr;               /*!< ICU LPTMR configuration pointer */
    Icu_PortConfigType *IcuPortConfigPtr; /*!< ICU PORT configuration pointer */
    Icu_LpCmpConfigType *IcuLpCmpConfigPtr; /*!< ICU LPCMP configuration pointer */
#if defined(CPU_YTM32B1HA0)
    Icu_MpwmConfigType *IcuMpwmConfigPtr; /*!< ICU MPWM configuration pointer */
#endif
    Icu_HwInterruptConfigType *IcuHwInterruptConfigPtr; /*!< ICU hardware interrupt configuration pointer */
#if WKU_SUPPORT == STD_ON
    Icu_WakeUpNotificationType IcuWakeUpNotificationPtr; /*!< ICU wakeup notification pointer */
#endif
    uint32 IcuChannelCount;       /*!< ICU channel count */
} Icu_ConfigType;

typedef enum
{
    ETMR_ICU_SM_ACTIVE_NONE,
    ETMR_ICU_SM_ACTIVE_RISING_EDGE,
    ETMR_ICU_SM_ACTIVE_FALLING_EDGE,
} Etmr_Icu_SMActiveStateType;
typedef struct
{
    Icu_InputStateType InputState; /**< ICU run state  */
    boolean InputLevel;            /**< ICU input level  */
    Icu_ModeType CurrentMode;      /**< ICU current mode  */
    Icu_ValueType ActiveTime;      /**< ICU active time  */
    Etmr_Icu_SMActiveStateType
    SMActiveState;             /**< ICU state machine active state  */
    Icu_ActivationType StartEdge;  /**< ICU start edge  */
    Icu_ValueType PeriodTime;      /**< ICU period time  */
    Icu_EdgeNumberType EdgeNumber; /**< ICU edge number  */
    Icu_ValueType
    HighLevelMcOverflowTimes; /**< ICU high level mc overflow times  */
    Icu_ValueType LowLevelMcOverflowTimes; /**< ICU low level mc overflow times */
    Icu_ValueType HighLevelTimes;          /**< ICU high level times  */
    Icu_ValueType LowLevelTimes;           /**< ICU low level times  */
#if defined (CPU_YTM32B1MC0)
    Icu_ValueType EtmrChannelValue; /**< ICU etmr channel value  */
#endif
    boolean IsNotificationEnable;          /**< ICU notification enable  */
} Icu_ChannelInfoType;

extern Icu_ConfigType const *Icu_gConfigPtr;
extern Icu_ChannelStateType Icu_WKUChannelState[ICU_WKUP_PORT_MAX];
/*==================================================================================================
 *                                             FUNCTIONS
==================================================================================================*/
#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief            Checks if a wakeup capable ICU channel is the source for a
 wakeup event and calls
 *                   the ECU state manager service EcuM_SetWakeupEvent in case
 of a valid ICU channel wakeup event.
 * @details
 * @param[in]        WakeupSource Information on wakeup source to be checked.
                    The associated ICU channel can be determined from
 configuration data.
 *
 *
 */
void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

#endif
#if (ICU_DE_INIT_API == STD_ON)

/**
 * @brief            This function de-initializes the ICU module.
 * @details
 *
 *
 */
void Icu_DeInit(void);

#endif

/**
 * @brief            This function disables the notification of a channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_DisableNotification(Icu_ChannelType Channel);

/**
 * @brief            This function disables the notification of a channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel.
 *
 *
 */
void Icu_DisableNotificationAsync(Icu_ChannelType Channel);

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/**
 * @brief            This function disables the wakeup capability of a single
 * ICU channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_DisableWakeup(Icu_ChannelType Channel);
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
 * @brief            This function enables / re-enables the detection of edges
 * of the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_EnableEdgeDetection(Icu_ChannelType Channel);

/**
 * @brief            This function disables the detection of edges of the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_DisableEdgeDetection(Icu_ChannelType Channel);
#endif

/**
 * @brief            This function enables the notification on the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_EnableNotification(Icu_ChannelType Channel);

/**
 * @brief            This function enables the notification on the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel.
 *
 *
 */
void Icu_EnableNotificationAsync(Icu_ChannelType Channel);

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
/**
 * @brief            This function (re-)enables the wakeup capability of the
 * given ICU channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_EnableWakeup(Icu_ChannelType Channel);
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/**
 * @brief            This function reads the coherent active time and period
 * time for the given ICU Channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @param[out]       DutyCycleValues Pointer to a buffer where the results (high
 * time and period time) shall be placed.
 *
 *
 */
void Icu_GetDutyCycleValues(Icu_ChannelType Channel,
                            Icu_DutyCycleType *DutyCycleValues);
#endif

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*!<
 * @brief            This function returns the status of the ICU input.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @return           Icu_InputStateType
 *
 */
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel);
#endif

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
/*!<
 * @brief            This function reads the elapsed Signal Low Time for the
 * given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @return           Icu_Value
 *
 */
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel);
#endif

/**
 * @brief            This function initializes the driver.
 * @details
 * @param[in]        ConfigPtr Pointer to a selected configuration structure
 *
 *
 */
void Icu_Init(const Icu_ConfigType *ConfigPtr);

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
 * @brief            This function resets the value of the counted edges to
 * zero.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_ResetEdgeCount(Icu_ChannelType Channel);

/**
 * @brief            This function enables the counting of edges of the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_EnableEdgeCount(Icu_ChannelType Channel);

/**
 * @brief            This function disables the counting of edges of the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_DisableEdgeCount(Icu_ChannelType Channel);

/**
 * @brief            This function reads the number of counted edges.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @return           Icu_EdgeNumberType
 *
 */
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel);
#endif

/**
 * @brief            This function sets the activation-edge for the given
 channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @param[in]        Activation Type of activation (if supported by hardware)
                    - ICU_RISING_EDGE
                    - ICU_FALLING_EDGE
                    - ICU_BOTH_EDGES
 *
 *
 */
void Icu_SetActivationCondition(Icu_ChannelType Channel,
                                Icu_ActivationType Activation);

/**
 * @brief            This function sets the ICU mode.
 * @details
 * @param[in]        Mode ICU_MODE_NORMAL: Normal operation, all used interrupts
 are enabled according to the notification requests. ICU_MODE_SLEEP: Reduced
 power mode. In sleep mode only those notifications are available which are
 configured as wakeup capable.
 *
 *
 */
void Icu_SetMode(Icu_ModeType Mode);

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
 * @brief            This function starts the measurement of signals.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_StartSignalMeasurement(Icu_ChannelType Channel);

/**
 * @brief            This function stops the measurement of signals of the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_StopSignalMeasurement(Icu_ChannelType Channel);
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief            This function starts the capturing of timer values on the
 edges.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @param[out]       BufferPtr Pointer to the buffer-array where the timestamp
 values shall be placed.
 * @param[in]        BufferSize Size of the external buffer (number of entries)
 * @param[in]        NotifyInterval Notification interval  (number of events).
                    This parameter can not be checked in a reasonable way.
 *
 *
 */
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType *BufferPtr,
                        uint16 BufferSize, uint16 NotifyInterval);

/**
 * @brief            This function stops the timestamp measurement of the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_StopTimestamp(Icu_ChannelType Channel);

/**
 * @brief            This function reads the timestamp index of the given
 * channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @return           Icu_Index
 *
 */
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel);
#endif /* (ICU_TIMESTAMP_API == STD_ON) */

#if (((ICU_GET_VERSION_INFO_API == STD_ON) && (ICU_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Get the version information of the ICU module.
 * @details
 *
 * @param[in]        versioninfo Pointer to structure where version information
 * are to be stored.
 *
 *
 */

void Icu_GetVersionInfo(Std_VersionInfoType *Versioninfo);

#endif /* ICU_VERSION_INFO_API == STD_ON && ICU_DEV_ERROR_DETECT == STD_ON */


/**
 * @brief Report port wakeup event to the EcuM
 * @param[in] ChannelIndex Channel index, not Channel
 */
void Icu_ReportWakeup(uint32 ChannelIndex);

#ifdef __cplusplus
}
#endif

#endif /* ICU_H */

