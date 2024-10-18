/**************************************************************************************************/
/**
 * @file      : Rtc_Drv.h
 * @brief     : Rtc module header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef RTC_DRV_H
#define RTC_DRV_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Rtc_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define RTC_DRV_H_VENDOR_ID                   0x00B3U
#define RTC_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define RTC_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define RTC_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define RTC_DRV_H_SW_MAJOR_VERSION            1U
#define RTC_DRV_H_SW_MINOR_VERSION            2U
#define RTC_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Rtc_Drv_Types header file are of the same vendor */
#if (RTC_DRV_H_VENDOR_ID != RTC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Rtc_Drv.h and Rtc_Drv_Types.h are different"
#endif
/* Check if current file and Rtc_Drv_Types header file are of the same Autosar version */
#if ((RTC_DRV_H_AR_RELEASE_MAJOR_VERSION != RTC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (RTC_DRV_H_AR_RELEASE_MINOR_VERSION != RTC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (RTC_DRV_H_AR_RELEASE_REVISION_VERSION != RTC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Rtc_Drv.h and Rtc_Drv_Types.h are different"
#endif
/* Check if current file and Rtc_Drv_Types header file are of the same Software version */
#if ((RTC_DRV_H_SW_MAJOR_VERSION != RTC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (RTC_DRV_H_SW_MINOR_VERSION != RTC_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (RTC_DRV_H_SW_PATCH_VERSION != RTC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Rtc_Drv.h and Rtc_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (RTC_DRV_ENABLE == STD_ON)

#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"
/**
 * @brief  Rtc target value.
 */
extern uint32 Rtc_Drv_TargetValue;

#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
RTC_DRV_CONFIG_EXT

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief      This function reads the current rtc counter.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     uint32
 */
uint32 Rtc_Drv_GetAlarmCounter(uint8 Instance);

/**
 * @brief      This function gets rtc match counter
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     uint32
 */
uint32 Rtc_Drv_GetAlarmMatchCounter(uint8 Instance);

/**
 * @brief       Config second interrupt mux and need to configure this before
 *              enable second interrupt.
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   MuxSel:  RTC second interrupt mux type
 *                        - RTC_DRV_SECOND_1
 *                        - RTC_DRV_SECOND_64
 *                        - RTC_DRV_SECOND_32
 *                        - RTC_DRV_SECOND_16
 *                        - RTC_DRV_SECOND_8
 *                        - RTC_DRV_SECOND_4
 *                        - RTC_DRV_SECOND_2
 *                        - RTC_DRV_SECOND_128
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS: Second interrupt mux configuration is SUCCESS
 * @retval     RTC_DRV_ERROR: Second interrupt mux configuration is ERROR
 */
Rtc_Drv_StatusType Rtc_Drv_ConfigSecondIntMux(uint8 Instance, Rtc_Drv_SecondIntMuxSelType MuxSel);

/**
 * @brief      This function gets RTC interrupt status.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  InterruptType:  Rtc instance interrupt type
 *                             - RTC_DRV_INT_OVERFLOW
 *                             - RTC_DRV_INT_ALARM
 *                             - RTC_DRV_INT_SECOND
 *                             - RTC_DRV_INT_PERIODIC
 * @return     uint32
 * @retval     RTC interrupt status
 */
uint32 Rtc_Drv_GetIntStatus(uint8 Instance, Rtc_Drv_InterruptType InterruptType);

/**
 * @brief      This function initialize the RTC.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  RtcConfigPtr:   Pointer to the specified RTC Unit configuration
 *
 * @return     None
 */
void Rtc_Drv_Init(uint8 Instance, const Rtc_Drv_ConfigType *RtcConfigPtr);

/**
 * @brief      This function de-initialize the RTC.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     None
 */
void Rtc_Drv_DeInit(uint8 Instance);

/**
 * @brief      This function configures the alarm based on the configuration structure.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  AlarmConfigPtr: pointer to alarm configuration
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  status success.
 * @retval     RTC_DRV_ERROR:    status error.
 */
Rtc_Drv_StatusType Rtc_Drv_ConfigAlarm(uint8                          Instance,
                                       const Rtc_Drv_AlarmConfigType *AlarmConfigPtr);

/**
 * @brief      Start the Rtc timer channel with a timeout value.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  Value: RTC channel timeout value
 *
 * @return     None
 */
void Rtc_Drv_StartTimer(uint8 Instance, uint32 Value);

/**
 * @brief      Stop the Rtc counter.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  stop command has been accepted.
 * @retval     RTC_DRV_ERROR:    stop command has not been accepted.
 */
Rtc_Drv_StatusType Rtc_Drv_StopTimer(uint8 Instance);

/**
 * @brief      Enable interrupt for RTC channel.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  InterruptType: Rtc interrupt type
 *                           - RTC_DRV_INT_OVERFLOW
 *                           - RTC_DRV_INT_ALARM
 *                           - RTC_DRV_INT_SECOND
 *                           - RTC_DRV_INT_PERIODIC
 *                           - RTC_DRV_INT_ALL
 * @return     None
 */
void Rtc_Drv_EnableInterrupt(uint8 Instance, Rtc_Drv_InterruptType InterruptType);

/**
 * @brief      Disable interrupt for RTC channel.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  InterruptType: Rtc interrupt type
 *                           - RTC_DRV_INT_OVERFLOW
 *                           - RTC_DRV_INT_ALARM
 *                           - RTC_DRV_INT_SECOND
 *                           - RTC_DRV_INT_PERIODIC
 *                           - RTC_DRV_INT_ALL
 * @return     None
 */
void Rtc_Drv_DisableInterrupt(uint8 Instance, Rtc_Drv_InterruptType InterruptType);
                                     
/**
 * @brief      This function sets the date passed by the user
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  TimeDatePtr: pointer to time date configuration
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  status success.
 * @retval     RTC_DRV_ERROR:    status error.
 */
Rtc_Drv_StatusType Rtc_Drv_SetTimeDate(uint8 Instance, const Rtc_Drv_TimedateType *TimeDatePtr);

/**
 * @brief      This function gets the current time and date stored in the state structure.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  TimeDatePtr: pointer to time date configuration
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  status success.
 * @retval     RTC_DRV_ERROR:    status error.
 */
Rtc_Drv_StatusType Rtc_Drv_GetCurrentTimeDate(uint8                       Instance,
                                              Rtc_Drv_TimedateType *const TimeDatePtr);

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* RTC_DRV_ENABLE == STD_ON */
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Rtc_Drv */

/** @} end of group Rtc_Module */

#endif /* RTC_DRV_H */
