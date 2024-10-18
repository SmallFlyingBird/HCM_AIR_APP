/**************************************************************************************************/
/**
 * @file      : Tim_Icu_Drv.h
 * @brief     : AUTOSAR Tim Icu hardware driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TIM_ICU_DRV_H
#define TIM_ICU_DRV_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Tim_Icu_Drv_Types.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define TIM_ICU_DRV_H_VENDOR_ID                   0x00B3U
#define TIM_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_ICU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_ICU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_ICU_DRV_H_SW_MAJOR_VERSION            1U
#define TIM_ICU_DRV_H_SW_MINOR_VERSION            2U
#define TIM_ICU_DRV_H_SW_PATCH_VERSION            1U

#if (TIM_ICU_DRV_H_VENDOR_ID != TIM_ICU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID Tim_Icu_Drv.h and Tim_Icu_Drv_Types.h have different"
#endif

#if ((TIM_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (TIM_ICU_DRV_H_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Tim_Icu_Drv.h and Tim_Icu_Drv_Types.h are different"
#endif

#if ((TIM_ICU_DRV_H_AR_RELEASE_REVISION_VERSION != TIM_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION) || \
        (TIM_ICU_DRV_H_SW_PATCH_VERSION != TIM_ICU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "AutoSar version of Tim_Icu_Drv.h and Tim_Icu_Drv_Types.h are different"
#endif

#if ((TIM_ICU_DRV_H_SW_MAJOR_VERSION != TIM_ICU_DRV_TYPES_H_SW_MAJOR_VERSION) || \
        (TIM_ICU_DRV_H_SW_MINOR_VERSION != TIM_ICU_DRV_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Tim_Icu_Drv.h and Tim_Icu_Drv_Types.h are different"
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/**
 * @brief   Export Post-Build configurations.
 */
#if (defined TIM_ICU_DRV_CONFIG_EXT)

TIM_ICU_DRV_CONFIG_EXT

#endif /* TIM_ICU_DRV_CONFIG_EXT */ 
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @brief Tim Icu Drv functions declaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  TimIcuInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
Tim_Icu_Drv_StatusType Tim_Icu_Drv_Init(Tim_Icu_Drv_IdType InstId, 
                                          const Tim_Icu_Drv_InstanceConfigType * TimIcuInstCfgPtr);

/**
 * @brief      The function enable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_EnableNotification(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      The function that sets up the activation condition
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[in]  ActiveEdge: edge activation type used 
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetActivationCondition(Tim_Icu_Drv_IdType InstId, 
                                                   Tim_Icu_Drv_ChannelIdType Channel, 
                                                   Tim_Icu_Drv_EdgeAlignmentModeType ActiveEdge);

/**
 * @brief      The function disable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_DisableNotification(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

#if (STD_OFF == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)    
/**
 * @brief      This function get the state of the overflow flag
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return whether the flag is set
 *
 */
boolean Tim_Icu_Drv_GetOvfState(Tim_Icu_Drv_IdType InstId);
#endif

#if (STD_ON == TIM_ICU_DRV_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
Tim_Icu_Drv_StatusType Tim_Icu_Drv_DeInit (Tim_Icu_Drv_IdType InstId);
#endif

#if (STD_ON == TIM_ICU_DRV_GET_INPUT_STATE_API)
/**
 * @brief      The function get input state of the Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return input state
 *
 */
boolean Tim_Icu_Drv_GetInputState(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);
#endif

#if (((STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API) && \
    (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_DMA_USE)) || \
     ((STD_ON == TIM_ICU_DRV_TIMESTAMP_API) && (STD_ON == TIM_ICU_DRV_TIMESTAMP_DMA_USE)))
/**
 * @brief      The function get address of CVn register
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return CVn register
 *
 */
uint32 Tim_Icu_Drv_GetCounterAddr(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);
#endif

#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
/**
 * @brief      This function starts timestamp measure mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[in]  bufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 * @param[in]  bufferSize:     Size of the external buffer
 * @param[in]  NotifyInterval: Notification interval
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StartTimestamp(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel, 
                                    uint16 * bufferPtr, uint16 bufferSize, uint16 NotifyInterval);

/**
 * @brief      This function read the timestamp index of the given Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return the timestamp index
 *
 */
uint16 Tim_Icu_Drv_GetTimestampIndex(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      This function stops timestamp measure mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StopTimestamp(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);
#endif

#if (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API)
/**
 * @brief      This function reset the edge counting for hardware Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_ResetEdgeCount(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      This function enable edge count measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return operation flag
 *
 */
Tim_Icu_Drv_StatusType Tim_Icu_Drv_EnableEdgeCount(Tim_Icu_Drv_IdType InstId, 
                                                         Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      This function get the edges number
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return edge number
 *
 */
uint16 Tim_Icu_Drv_GetEdgeNumbers(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      This function disable edge count measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_DisableEdgeCount(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);
#endif

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
/**
 * @brief      This function starts signal measurement mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StartSignalMeasurement(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);


/**
 * @brief      This function reads the coherent active time and period time
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[out]  DutyCyclePtr: structure where duty cycle values are stored
 *
 * @return none
 *
 */
void Tim_Icu_Drv_GetDutyCycleValues(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel, 
                                             Tim_Icu_Drv_DutyCycleType * DutyCyclePtr);

/**
 * @brief      This function reads the elapsed Signal Low, High or Period Time
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return elapsed time
 *
 */
uint16 Tim_Icu_Drv_GetTimeElapsed(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      This function stops signal measurement mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StopSignalMeasurement(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);
#endif

#if (STD_ON == TIM_ICU_DRV_EDGE_DETECT_API)
/**
 * @brief      This function enable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_EnableEdgeDetection(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      This function disable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_DisableEdgeDetection(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);
#endif

#if (STD_ON == TIM_ICU_DRV_SET_MODE_API)
/**
 * @brief      Sets hardware Channel into SLEEP mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used 
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetChannelSleepMode(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);

/**
 * @brief      Sets hardware Channel into NORMAL mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used 
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetChannelNormalMode(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel);
#endif

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_DMA_USE)
/**
 * @brief      This function sets the coherent active time and period time
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[in]  PulseValue: active time
 * @param[in]  PeriodValue: period time
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetSignalMeasurementValue(Tim_Icu_Drv_IdType InstId, 
                                                       Tim_Icu_Drv_ChannelIdType Channel, 
                                                       uint16 PulseValue, uint16 PeriodValue);
#endif

/**
 * @brief      This function handles CHF interrupt of all Channels
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Tim_Icu_Drv_ChIntHandler(Tim_Icu_Drv_IdType InstId);

/**
 * @brief      This function handles overflow interrupt
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */    
void Tim_Icu_Drv_OverflowIntHandler(Tim_Icu_Drv_IdType InstId);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Icu_Drv  */
/** @} end of group Icu_Module */

#endif  /* ICU_DRV_H */

