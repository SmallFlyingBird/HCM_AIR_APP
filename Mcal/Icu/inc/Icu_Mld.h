/*
* @file    Icu_Mld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Mld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef ICU_MLD_H
#define ICU_MLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
#include "Icu_Mld_Cfg.h"
#if (ICU_ETMR_USED == STD_ON)
#include "Icu_Lld_Etmr.h"
#endif
#if (ICU_PORT_USED == STD_ON)
#include "Icu_Lld_Port.h"
#endif
#if (ICU_ACMP_USED == STD_ON)
#include "Icu_Lld_Cmp.h"
#endif
#if (ICU_MPWM_USED == STD_ON)
#include "Icu_Lld_Mpwm.h"
#endif
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION                                
==================================================================================================*/
#define ICU_MLD_VENDOR_ID                      (180)
#define ICU_MLD_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_MLD_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_MLD_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_MLD_SW_MAJOR_VERSION               (2)
#define ICU_MLD_SW_MINOR_VERSION               (3)
#define ICU_MLD_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS                                       
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS                                        
==================================================================================================*/
extern Icu_ChannelInfoType Icu_gChannelInfo[ICU_MAX_CHANNEL];
extern const uint16 IcuWkupPortBuff[ICU_WKUP_PORT_MAX];
/*==================================================================================================
                                                ENUMS                                        
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES                                           
==================================================================================================*/
/**
 * @brief            This function initializes the driver.
 * @details
 *   
 *
 */
void Icu_Mld_Init(void);

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
 * @brief            Etmr Channel Start Signal Measurement.
 * @details
 * @param[in]        Channel - Icu channel  
 *
 */
void Icu_Mld_StartSignalMeasurement(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel Stop Signal Measurement.
 * @details
 * @param[in]        Channel - Icu channel  
 *
 */
void Icu_Mld_StopSignalMeasurement(Icu_ChannelType Channel);
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/**
 * @brief            Etmr Channel Get Input State.
 * @details
 * @param[in]        Channel - Icu channel  
 * @param[out]       DutyCycleValues - Icu DutyCycle Values
 *
 */
void Icu_Mld_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues);
#endif

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief            Etmr Channel Get Input State.
 * @details
 * @param[in]        InChannel - Icu channel  
 * @return           Icu_InputState - Icu Input State
 *
 */
Icu_InputStateType Icu_Mld_GetInputState(Icu_ChannelType InChannel);
#endif

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
/**
 * @brief            Etmr Channel Get Time Elapsed.
 * @details
 * @param[in]        Channel - Icu channel  
 * @return           Icu_ValueType - Icu Value Type
 *
 */
Icu_ValueType Icu_Mld_GetTimeElapsed(Icu_ChannelType Channel);
#endif

/**
 * @brief            Etmr Channel disable notification.
 * @details
 * @param[in]        Channel - Icu channel  
 * 
 *
 */
void Icu_Mld_DisableNotification(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel enable notification.
 * @details
 * @param[in]        Channel - Icu channel  
 * 
 *
 */
void Icu_Mld_EnableNotification(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel Set Sleep Mode.
 * @details
 * @param[in]        WkuChannelConfig - WKu channel config  
 * 
 *
 */
void Icu_Mld_SetSleepMode(const Icu_ChannelConfigType *WkuChannelConfig);

/**
 * @brief            Etmr Channel Set Normal Mode.
 * @details
 * @param[in]        WkuChannelConfig - WKu channel config  
 * 
 *
 */
void Icu_Mld_SetNormalMode(const Icu_ChannelConfigType *WkuChannelConfig);

/**
 * @brief            Etmr Channel Set Wakeup Mode.
 * @details
 * 
 * 
 *
 */
void Icu_Mld_DeInit(void);

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief            Etmr Channel Start Timestamp.
 * @details
 * @param[in]        Channel - Icu channel  
 * @param[in]        BufferSize - Icu Buffer Size
 * @param[in]        NotifyInterval - Icu Notify Interval
 * @param[out]       BufferPtr - Icu Buffer Pointer
 *
 */
void Icu_Mld_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType *BufferPtr, uint16 BufferSize, uint16 NotifyInterval);

/**
 * @brief            Etmr Channel Stop Timestamp.
 * @details
 * @param[in]        Channel - Icu channel  
 *
 */
void Icu_Mld_StopTimestamp(Icu_ChannelType Channel);
#endif
/**
 * @brief            Etmr Channel Get Time Stamp Index.
 * @details
 * @param[in]        Channel - Icu channel  
 * @return           Icu_Index - Icu Index TimestampIndex
 *
 */
Icu_IndexType Icu_Mld_GetTimestampIndex(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel Enable Edge Count.
 * @details
 * @param[in]        Channel - Icu channel  
 * 
 *
 */
void Icu_Mld_EnableEdgeCount(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel Disable Edge Count.
 * @details
 * @param[in]        Channel - Icu channel  
 * 
 *
 */
void Icu_Mld_DisableEdgeCount(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel Reset Edge Count.
 * @details
 * @param[in]        Channel - Icu channel  
 * 
 *
 */
void Icu_Mld_ResetEdgeCount(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel Get Edge Numbers.
 * @details
 * @param[in]        Channel - Icu channel  
 * @return           Icu_EdgeNumber - Icu Edge Number
 *
 */
Icu_EdgeNumberType Icu_Mld_GetEdgeNumbers(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel set activation condition.
 * @details
 * @param[in]        Channel - Icu channel  
 * @param[in]        Activation - Icu Activation
 *
 */
void Icu_Mld_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);

/**
 * @brief            Etmr Channel Disable Edge Detection.
 * @details
 * @param[in]        Channel - Icu channel  
 * 
 *
 */
void Icu_Mld_EnableEdgeDetection(Icu_ChannelType Channel);

/**
 * @brief            Etmr Channel Disable Edge Detection.
 * @details
 * @param[in]        Channel - Icu channel  
 * 
 *
 */
void Icu_Mld_DisableEdgeDetection(Icu_ChannelType Channel);

#ifdef __cplusplus
}
#endif

#endif /* End of file Icu_Mld.h */

