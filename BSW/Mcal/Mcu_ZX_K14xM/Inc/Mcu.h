/**************************************************************************************************/
/**
 * @file      : Mcu.h
 * @brief     : AUTOSAR Mcu driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef MCU_H
#define MCU_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Mcu
 *  @brief Mcu high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define MCU_MODULE_ID                   101U
#define MCU_VENDOR_ID                   0x00B3U
#define MCU_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_AR_RELEASE_MINOR_VERSION    6U
#define MCU_AR_RELEASE_REVISION_VERSION 0U
#define MCU_SW_MAJOR_VERSION            1U
#define MCU_SW_MINOR_VERSION            2U
#define MCU_SW_PATCH_VERSION            1U

/* Check if current file and Mcu_Types.h file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu.h and Mcu_Types.h are different"
#endif

/* Check if current file and Mcu_Types.h file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION != MCU_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (MCU_AR_RELEASE_MINOR_VERSION != MCU_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (MCU_AR_RELEASE_REVISION_VERSION != MCU_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu.h and Mcu_Types.h are different"
#endif

/* Check if current file and Mcu_Types.h file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION != MCU_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (MCU_SW_MINOR_VERSION != MCU_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (MCU_SW_PATCH_VERSION != MCU_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu.h and Mcu_Types.h are different"
#endif

/**
 * @brief Specifies the instance id of MCU module.
 */
#define MCU_INSTANCE_ID ((uint8)0x0U)

/**
 * @brief Service Ids for MCU APIs
 */
#define MCU_SID_INIT                 ((uint8)0x00U)
#define MCU_SID_INIT_RAM_SECTION     ((uint8)0x01U)
#define MCU_SID_INIT_CLOCK           ((uint8)0x02U)
#define MCU_SID_DISTRIBUTE_PLL_CLOCK ((uint8)0x03U)
#define MCU_SID_GET_PLL_STATUS       ((uint8)0x04U)
#define MCU_SID_GET_RESET_REASON     ((uint8)0x05U)
#define MCU_SID_GET_RESET_RAW_VALUE  ((uint8)0x06U)
#define MCU_SID_PERFORM_RESET        ((uint8)0x07U)
#define MCU_SID_SET_MODE             ((uint8)0x08U)
#define MCU_SID_GET_VERSION_INFO     ((uint8)0x09U)
#if (MCU_GET_RAM_STATE_API == STD_ON) /* SWS_Mcu_00209 */
    #define MCU_SID_GET_RAM_STATE ((uint8)0x0AU)
#endif
#define MCU_SID_GET_POWER_MODE_STATE       ((uint8)0x0BU)
#define MCU_SID_ENABLE_OSC_CLOCK_MONITOR   ((uint8)0x0CU)
#define MCU_SID_DISABLE_OSC_CLOCK_MONITOR  ((uint8)0x0DU)
#define MCU_SID_ENABLE_FIRC_CLOCK_MONITOR  ((uint8)0x0EU)
#define MCU_SID_DISABLE_FIRC_CLOCK_MONITOR ((uint8)0x0FU)
#if (MCU_ENABLE_PLL_MONITOR_API == STD_ON)
    #define MCU_SID_ENABLE_PLL_CLOCK_MONITOR ((uint8)0x10U)
#endif
#define MCU_SID_SET_WAKEUP_SOURCE ((uint8)0x11U)

/**
 * @brief Development errors
 */
/* SWS_Mcu_00012 */
#define MCU_E_PARAM_CLOCK          ((uint8)0x0BU)
#define MCU_E_PARAM_MODE           ((uint8)0x0CU)
#define MCU_E_PARAM_RAMSECTION     ((uint8)0x0DU)
#define MCU_E_PLL_NOT_LOCKED       ((uint8)0x0EU)
#define MCU_E_UNINIT               ((uint8)0x0FU)
#define MCU_E_PARAM_POINTER        ((uint8)0x10U)
#define MCU_E_INIT_FAILED          ((uint8)0x11U)
#define MCU_E_ALLREADY_INITIALIZED ((uint8)0x13U)
#define MCU_E_ENABLE_CLOCK_MONITOR ((uint8)0x14U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    #define MCU_START_SEC_CONFIG_DATA_PTR
    #include "Mcu_MemMap.h"
extern const Mcu_ConfigType *const Mcu_PreDefinedConfigPtr;
    #define MCU_STOP_SEC_CONFIG_DATA_PTR
    #include "Mcu_MemMap.h"
#else
    #define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Mcu_MemMap.h"

MCU_CONFIG_EXT

    #define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Mcu_MemMap.h"
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief     This service initializes the MCU driver.
 *
 * @param[in] ConfigPtr: Pointer to MCU driver configuration set.
 *
 * @return    None
 *
 */
void Mcu_Init(const Mcu_ConfigType *ConfigPtr);

/**
 * @brief     This service initializes the RAM section wise.
 *
 * @param[in] RamSection: Selects RAM memory section provided in configuration set.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Command has been accepted.
 * @retval    E_NOT_OK: Command has not been accepted, e.g. due to parameter error.
 *
 */
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief    Initializes the PLL and other MCU specific clock options.
 *
 * @param[in] ClockSetting: Clock setting.
 *
 * @return    Std_ReturnType: State of initialise clock.
 *            - E_OK - Clock is initialised success.
 *            - E_NOT_OK - Clock is initialised failed.
 *
 */
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief     This service activates the PLL clock to the MCU clock distribution.
 *
 * @param[in] None
 *
 * @return    Std_ReturnType
 * @retval    E_OK: PLL Command has been accepted.
 * @retval    E_NOT_OK: Command has not been accepted.
 *
 */
Std_ReturnType Mcu_DistributePllClock(void);
#endif /* (MCU_NO_PLL == STD_OFF) */

/**
 * @brief     This service provides the lock status of the PLL.
 *
 * @param[in] None
 *
 * @return    Mcu_PllStatusType: PLL status.
 * @retval    MCU_PLL_LOCKED:           PLL is locked.
 * @retval    MCU_PLL_UNLOCKED:         PLL is unlocked.
 * @retval    MCU_PLL_STATUS_UNDEFINED: PLL status is unkown.
 *
 */
Mcu_PllStatusType Mcu_GetPllStatus(void);

/**
 * @brief     This service reads the reset type from the hardware.
 *
 * @param[in] None
 *
 * @return    Mcu_ResetType: MCU reset reason.
 *
 */
Mcu_ResetType Mcu_GetResetReason(void);

/**
 * @brief     This service read the reset type from the hardware register.
 *
 * @param[in] None
 *
 * @return    Mcu_RawResetType: Reset raw value.
 *
 */
Mcu_RawResetType Mcu_GetResetRawValue(void);

#if (MCU_PERFORM_RESET_API == STD_ON)
/**
 * @brief     The service perform a microcontroller reset.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Mcu_PerformReset(void);
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

/**
 * @brief     This service activates the MCU power modes.
 *
 * @param[in] McuMode: Set different MCU power modes configured in the configuration set.
 *
 * @return    None
 *
 */
void Mcu_SetMode(Mcu_ModeType McuMode);

#if (MCU_VERSION_INFO_API == STD_ON)
/**
 * @brief        This service returns the version information of this module.
 *
 * @param[inout] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return       None
 *
 */
void Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* (MCU_VERSION_INFO_API == STD_ON) */

#if (MCU_GET_RAM_STATE_API == STD_ON) /* SWS_Mcu_00209 */
/**
 * @brief     This service provides the actual status of the microcontroller Ram.
 *
 * @param[in] None
 *
 * @return    Mcu_RamStateType: Status of the Ram content.
 *
 */
Mcu_RamStateType Mcu_GetRamState(void);
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

#if (MCU_POWERMODE_STATE_API == STD_ON)
/**
 * @brief     This service reads current power mode.
 *
 * @param[in] None
 *
 * @return    Mcu_PowerModeType: Current power mode.
 *
 */
Mcu_PowerModeType Mcu_GetPowerModeState(void);
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */

/**
 * @brief      This service enables and configs OSC clock monitor.
 *
 * @param[in]  Act: Select the action when loss of clock is detected.
 *
 * @return     boolean
 * @retval     TRUE:  OSC clock monitor is enabled success.
 * @retval     FALSE: OSC clock monitor is enabled failed.
 *
 */
boolean Mcu_EnableOscClockMonitor(Mcu_OscClockLossActType Act);

/**
 * @brief      This service disables OSC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_DisableOscClockMonitor(void);

/**
 * @brief      This service enables and configs FIRC clock monitor.
 *
 * @param[in]  Act: Select the action when loss of clock is detected.
 *
 * @return     boolean
 * @retval     TRUE:  FIRC clock monitor is enabled success.
 * @retval     FALSE: FIRC clock monitor is enabled failed.
 *
 */
boolean Mcu_EnableFircClockMonitor(Mcu_Firc64MClockLossActType Act);

/**
 * @brief      This service disables FIRC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_DisableFircClockMonitor(void);

#if (MCU_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 * @brief      This service enables and configs PLL clock monitor.
 *
 * @param[in]  Act: Select the action when loss of clock is detected.
 *
 * @return     None
 *
 */
void Mcu_EnablePllClockMonitor(Mcu_PllClockLossActType Act);
#endif

/**
 * @brief      This service configs MCU wakeup source.
 *
 * @param[in]  WakeupSource: Select wakeup source.
 * @param[in]  ActiveHigh: Wakeup MCU if polarity is high.
 * @param[in]  Enable: Enable/disable this wakeup source.
 *
 * @return     None
 *
 */
void Mcu_SetWakeupSource(Mcu_WakeupSourceType WakeupSource, boolean ActiveHigh, boolean Enable);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Mcu */

/** @} end of group Mcu_Module */

#endif /* MCU_H */
