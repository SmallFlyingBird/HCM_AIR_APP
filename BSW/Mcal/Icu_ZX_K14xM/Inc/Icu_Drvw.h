/**************************************************************************************************/
/**
 * @file      : Icu_Drvw.h
 * @brief     : AUTOSAR Icu drvw driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ICU_DRVW_H
#define ICU_DRVW_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drvw
 *  @{
 */
        
#ifdef __cplusplus
extern "C"{
#endif

#include "Icu_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define ICU_DRVW_H_VENDOR_ID                   0x00B3U
#define ICU_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define ICU_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define ICU_DRVW_H_SW_MAJOR_VERSION            1U
#define ICU_DRVW_H_SW_MINOR_VERSION            2U
#define ICU_DRVW_H_SW_PATCH_VERSION            2U


#if (ICU_DRVW_H_VENDOR_ID != ICU_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw.h and Icu_Drvw_Types.h have different"
#endif
                
#if ((ICU_DRVW_H_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_H_AR_RELEASE_MINOR_VERSION != ICU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw.h and Icu_Drvw_Types.h are different"
#endif

#if ((ICU_DRVW_H_AR_RELEASE_REVISION_VERSION != ICU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_DRVW_H_SW_PATCH_VERSION != ICU_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "AutoSar version of Icu_Drvw.h and Icu_Drvw_Types.h are different"
#endif
                
#if ((ICU_DRVW_H_SW_MAJOR_VERSION != ICU_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_H_SW_MINOR_VERSION != ICU_DRVW_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw.h and Icu_Drvw_Types.h are different"
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
 * @brief TIM activation types define
 */
/* The channel pin will be set rising edge . */
#define ICU_DRVW_RISING_EDGE     0U
/* The channel pin will be set falling edge. */
#define ICU_DRVW_FALLING_EDGE    1U
/* The channel pin will be set either a rising  or falling edge. */
#define ICU_DRVW_BOTH_EDGES  2U


/**
 * @brief   Export Post-Build configurations.
 */
#if (defined ICU_DRVW_CONFIG_EXT)

ICU_DRVW_CONFIG_EXT

#endif /* ICU_DRVW_CONFIG_EXT */
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @brief Icu Drvw functions declaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Initialize a hardware Icu Instance
 *
 * @param[in]  IcuInstSumNum: Number of instances to be configured
 * @param[in]  IcuHwInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void Icu_Drvw_Init(uint32 IcuInstSumNum, const Icu_Drvw_HwInstanceConfigType (* IcuHwInstCfgPtr)[]);

#if (STD_ON == ICU_DRVW_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  IcuInstSumNum: Number of instances to be configured
 * @param[in]  IcuHwInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void Icu_Drvw_DeInit(uint32 IcuInstSumNum, const Icu_Drvw_HwInstanceConfigType (* IcuHwInstCfgPtr)[]);
#endif

/**
 * @brief      set the type of activation
 *
 * @param[in]  ActiveEdge: the type of activation for the ICU Channel 
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_SetActivationCondition(ICU_DRVW_ACTIVATION_TYPE ActiveEdge, 
                                                const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      Disable Notification for timestamp
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_DisableNotification(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      Enable Notification for timestamp
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_EnableNotification(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

#if (STD_ON == ICU_DRVW_SET_MODE_API)
/**
 * @brief      Put the Channel in normal state
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_SetNormalMode(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      Put the Channel in a reduce power state
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_SetSleepMode(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif

#if (STD_ON == ICU_DRVW_GET_INPUT_STATE_API)
/**
 * @brief      Service that returns the state of input Channel
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return whetner An active edge has been detected
 *
 */
boolean Icu_Drvw_GetInputState(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif

#if (((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_API) && (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE)) || \
     ((STD_ON == ICU_DRVW_TIMESTAMP_API) && (STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE)))
/**
 * @brief      Service that return the address of capture register
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return address of capture register
 *
 */     
uint32 Icu_Drvw_GetCounterAddr(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif

#if (STD_ON == ICU_DRVW_TIMESTAMP_API)
/**
 * @brief      This function starts the capturing of timer values on the edges
 *
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 * @param[in]  BufferSize:     Size of the external buffer
 * @param[in]  NotifyInterval: Notification interval
 *
 * @return none
 *
 */
void Icu_Drvw_StartTimestamp(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint16 * BufferPtr, 
                                     uint16 BufferSize, uint16 NotifyInterval);

/**
 * @brief      This function read the timestamp index of the given Channel
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return the timestamp index
 *
 */
uint16 Icu_Drvw_GetTimestampIndex(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      This function stops the capturing of timer values on the edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_StopTimestamp(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif



#if (STD_ON == ICU_DRVW_EDGE_COUNT_API)
/**
 * @brief      This function enables the counting of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_EnableEdgeCount(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      This function reads the number of counted edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return Number of the counted edges
 *
 */
uint16 Icu_Drvw_GetEdgeNumbers(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      This function resets the value of the counted edges to zero
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_ResetEdgeCount(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      This function is reentrant and disables the counting of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_DisableEdgeCount(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif

#if (STD_ON == ICU_DRVW_EDGE_DETECT_API)
/**
 * @brief      This function enables or re-enables the detection of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_EnableEdgeDetection(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      This function disables the detection of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_DisableEdgeDetection(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif

#if (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_API)
/**
 * @brief      This function starts the measurement of signals
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_StartSignalMeasurement(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);

/**
 * @brief      This function stops the measurement of signals
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_StopSignalMeasurement(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif

#if (STD_ON == ICU_DRVW_GET_TIMEELAPSED_API)
/**
 * @brief      This function reads the elapsed Signal Low, High or Period Time
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return elapsed time
 *
 */
Icu_Drvw_ValueType Icu_Drvw_GetTimeElapsed(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#endif

#if (STD_ON == ICU_DRVW_GET_DUTYCYCLE_VALUES_API)
/**
 * @brief      This function reads the coherent active time and period time
 *
 * @param[in]  DrvwHwChCfgPtr:  configuration of the Channel
 * @param[out] DutyCyclePtr : Pointer to a buffer where the results (high time 
 *                          and period time) shall be placed 
 *
 * @return none
 *
 */
void Icu_Drvw_GetDutyCycleValues(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, 
                                           Tim_Icu_Drv_DutyCycleType* DutyCyclePtr);
#endif

#if (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE)
/**
 * @brief      This function store the active time and period time
 *
 * @param[in]  DrvwHwChCfgPtr  : configuration of the Channel
 * @param[in]  PulseValue  : active time
 * @param[in]  PeriodValue : period time
 *
 * @return none
 *
 */
void Icu_Drvw_SetSignalMeasurementValue(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, 
                                                    Icu_Drvw_ValueType PulseValue,
                                                    Icu_Drvw_ValueType PeriodValue);
#endif


#if ((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE))

/**
 * @brief     This function enable channel request of DMA.
 *
 * @param[in] DmaChannel: dma channel id
 *
 * @return    None
 *
 */
void Icu_Drvw_EnableDmaChannelRequest(uint32 DmaChannel);

/**
 * @brief     This function disable channel request of DMA.
 *
 * @param[in] DmaChannel: dma channel id
 *
 * @return    None
 *
 */
void Icu_Drvw_DisableDmaChannelRequest(uint32 DmaChannel);

/**
 * @brief      set dma destination address Function
 *
 * @param[in]  DmaChId: dma channel id
 * @param[in]  Address: dma transfer destination address
 *
 * @return none.
 *
 */
void Icu_Drvw_SetDmaDestAddr(const uint32 DmaChId, uint32 Address);

/**
 * @brief      set total number of minor loop in a major loop Function
 *
 * @param[in]  DmaChId: dma channel id
 * @param[in]  Num: number of minor loop in a major loop
 *
 * @return none.
 *
 */
void Icu_Drvw_SetDmaMinorLoopNum(const uint32 DmaChId, uint16 Num);
#endif

#if ((STD_ON == ICU_DRVW_TIMESTAMP_API) && (STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE))

/**
 * @brief      This function starts the capturing of timer values on the edges
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  IcuInstSumNum:    number of driver instances configured 
 *
 * @return none
 *
 */
void Icu_Drvw_TimestampDmaGlobalConfig(const uint32 DmaChId, 
                            const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint32 IcuInstSumNum);

/**
 * @brief      This function config icu dma transfer configuration parameter
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  BufferSize:     Size of the external buffer
 * @param[in]  NotifyInterval: Notification interval
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 *
 * @return none
 *
 */
void Icu_Drvw_TimestampDmaTransferConfig(const uint32 DmaChId, 
                            const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint16 BufferSize, 
                               uint16 NotifyInterval, uint16 * BufferPtr);

/**
 * @brief      This function config icu dma transfer configuration parameter
 * @param[in]  DmaChId: dma channel id
 * @param[in]  ParamArray:     Pointer to a Array
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_GetDmaTimestampIndex(const uint32 DmaChId, uint32 * ParamArray, 
                                        const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);     

#endif

#if ((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_API) && (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE))
/**
 * @brief      This function starts the capturing of timer values on the edges
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  IcuInstSumNum:    number of driver instances configured 
 *
 * @return none
 *
 */
void Icu_Drvw_SignalMeasurementDmaGlobalConfig(const uint32 DmaChId, 
                            const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint32 IcuInstSumNum);

/**
 * @brief      This function starts the capturing of timer values on the edges
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 *
 * @return none
 *
 */

void Icu_Drvw_SignalMeasurementDmaTransferConfig(const uint32 DmaChId, 
                        const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, volatile uint16 * BufferPtr);

#endif
/**
 * @brief      This function disable overflow interrupt
 * 
 * @param[in]  DrvwHwChCfgPtr  : configuration of the Channel
 * 
 * @return none
 *
 */    
void Icu_Drvw_DisableOverflowInt(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
/**
 * @brief      This function enable overflow interrupt
 * 
 * @param[in]  DrvwHwChCfgPtr  : configuration of the Channel
 * 
 * @return none
 *
 */    
void Icu_Drvw_EnableOverflowInt(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu_Drvw  */
/** @} end of group Icu_Module */

#endif  /* ICU_DRVW_H */

