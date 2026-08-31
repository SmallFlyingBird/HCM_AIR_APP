/**
* @file    Mcu_Lld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Mcu_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef MCU_LLD_H
#define MCU_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Mcu.h"

/*==================================================================================================
 *                                  HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_LLD_VENDOR_ID                      (180)
#define MCU_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define MCU_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define MCU_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define MCU_LLD_SW_MAJOR_VERSION               (2)
#define MCU_LLD_SW_MINOR_VERSION               (3)
#define MCU_LLD_SW_PATCH_VERSION               (0)
/*==================================================================================================
 *                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
 *                                        EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
 *                                              ENUMS
==================================================================================================*/
/*==================================================================================================
 *                                        FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * @brief Sets the default value for the RAM section pointed to by ConfigPtr.
 * @param[in] ConfigPtr Pointer to the struct containing information about the RAM section, including
 * its base address and the default value to be set.
 * @return No return value.
 * This function sets the default value for all addresses in the RAM section as specified by ConfigPtr.
 * It uses a for loop with an incrementing offset variable to write each address with the default value.
*/
void Mcu_Lld_SetRamSection(const Mcu_RamSectionConfigType *ConfigPtr);
/**
 * @brief Set the RCU reset configuration
 * This function sets MCU Reset and Control Unit (RCU) reset configuration.
 * The hardware reset pin can be optionally filtered by configuring the filter enable, filter stabilization time,
 * and filter counter value before triggering a Reset.
 * @param[in] ConfigPtr A pointer to the structure containing RCU reset configurations
 * @return none
*/
void Mcu_Lld_SetRcu(const Mcu_ResetConfigType *ConfigPtr);

/**
 * @brief Retrieves the status of the PLL
 * @return Returns the locked or unlocked status of the PLL
 * This function retrieves the status of the PLL by getting its lock status from the
 * corresponding register.
*/
Mcu_PllStatusType Mcu_Lld_GetPllStatus(void);

/**
 *@brief Sets the MCU power mode.
 * This function is used to switch between different power modes of the MCU.
 * In the case of sleep mode, it clears the SLEEPDEEP bit in CM33_SCB_SCR_OFFSET32 Register.
 * In the case of deep sleep mode, it sets the SLEEPDEEP bit and clears the RPMEN bit in PCU_CTRL_OFFSET32 Register.
 * In the case of standby mode, it sets the SLEEPDEEP bit, DPD_EN bit in EFM_CTRL_OFFSET32 register,
 * and the RPMEN bit in PCU_CTRL_OFFSET32 register.
 * @param[in] McuMode Power mode selection for MCU.
*/
void Mcu_Lld_SetMode(Mcu_PowerModeType McuMode);

/**
 * @brief Sets the peripheral clock for the specified peripherals.
 *
 * This function sets the peripheral clock for the peripherals specified in the Mcu_PeripheralClockConfigType
 * structure using the Mcu_Lld_SetPeripheralClock() function. It iterates over the IPC configurations provided in
 * the structure and sets the peripheral clock for each IPC using the Mcu_Lld_SetPeripheralClock() function.
 *
 * @param[in] ConfigPtr Pointer to the configuration structure for the peripheral clock.
 *                  It contains the list of IPC configurations and the number of IPCs to be configured.
 */
void Mcu_Lld_SetPeripheralClock(const Mcu_PeripheralClockConfigType *ConfigPtr);

/**
 * @brief Initializes the MCU clock as per the given configuration.
 * @param[in] ConfigPtr Pointer to the configuration data.
 * @return Std_ReturnType
 * @retval E_OK Clock initialization succeeded.
 * @retval E_NOT_OK Clock initialization failed due to timeout or invalid parameter.
*/
Std_ReturnType Mcu_Lld_InitClock(const Mcu_ClockConfigType *ConfigPtr);

/**
 * @brief This function gets the reset value using Mcu_Lld_GetResetValue.
 *
 * @return The reset value.
 */
Mcu_ResetType Mcu_Lld_GetResetValue(void);

/**
 * @brief This function gets the core clock frequency using the configuration
 * provided in ConfigPtr.
 *
 * @param[in] ConfigPtr A pointer to the configuration data.
 * @return The core clock frequency.
 */
uint32 Mcu_Lld_GetCoreClockFrequency(const Mcu_ClockConfigType *ConfigPtr);

/**
 * @brief This function gets the PLL clock frequency using the configuration
 * provided in ConfigPtr.
 *
 * @param[in] ConfigPtr A pointer to the configuration data.
 * @return The PLL clock frequency.
 */
uint32 Mcu_Lld_GetPllClockFrequency(const Mcu_ClockConfigType *ConfigPtr);

/**
 * @brief Sets the clock source using the provided configuration data.
 *
 * This function sets the system clock source using the system clock source
 * configuration provided in ConfigPtr. It then waits for the system clock
 * source to stabilize before proceeding to set the CMU, initialize the
 * clock output, and set the peripheral clock. If ConfigPtr is NULL, the
 * function returns E_NOT_OK.
 *
 * @param[in] ConfigPtr A pointer to the configuration data.
 *
 * @return The status of the operation.
 * @retval E_OK The operation succeeded.
 * @retval E_NOT_OK The operation failed.
 */
Std_ReturnType Mcu_Lld_SetClockSource(const Mcu_ClockConfigType *ConfigPtr);


/**
* @brief This function gets the reset raw value.
*     This function is called by Mcu_GetResetRawValue() API.
* @return The reset raw value.
*/
Mcu_RawResetType Mcu_Lld_GetResetRawValue(void);

/**
 * @brief Set the PCU configuration
 * This function initializes the PCU-related registers using the provided configuration,
 * including enabling high voltage detected reset, enabling high voltage detected interrupt
 * and its notification, enabling fast recovery, and enabling PKE.
 * @attention High/Low voltage detection is enabled by default in hardware.
 *
 * @param[in] ConfigPtr A pointer to the PCU configuration data
 */
void Mcu_Lld_SetPcu(const Mcu_PcuConfigType *ConfigPtr);

/**
 * @brief Pcu interrupt handler
 * The PCU has a single IRQ API for three different voltage domains (VD). This function
 * determines which VD's interrupt function to call.
 */
void Mcu_Lld_Pcu_ChannelIrqProcess(void);

/**
 * @brief Cmu interrupt handler
 * The Clock Monitor Unit (CMU) has a single IRQ API for a four-channel CMU instance. This function
 * determines which CMU instance's notification to call.
 */
void Mcu_Lld_Cmu_ChannelIrqProcess(void);

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief Enable CMU2 channel for monitoring PLL
 *
 * @details This function controls the enabling of CMU2 channel when PLL is enabled
 *          but not used as the system clock.
 *
 * @note When the PLL is enabled but not used as the system clock, once the CMU2 is
 *       enabled, Mcu_InitClock will enable CMU before PLL is locked, which may lead
 *       to a chip reset.
 */
void Mcu_Lld_SetCmuChannel2(void);
#endif

#if (MCU_GET_SXOSC_STATU_API == STD_ON)
/**
 * @brief Retrieves the status of the Sxosc
 * 
 * @details This function retrieves the status of the SXOSC by getting its lock status from the
 *          corresponding register.
 * @return Mcu_SxoscStatusType 
 */
Mcu_SxoscStatusType Mcu_Lld_GetSxoscStatus(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* End of file Mcu_Lld.h */


