/**************************************************************************************************/
/**
 * @file      : SchM_Pwm.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_PWM_H
#define SCHM_PWM_H

/**
*   @addtogroup Rte_Module
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
/***************************************************************************************************
  Source File Version Information
 **************************************************************************************************/
#define SCHM_PWM_H_VENDOR_ID                   0x00B3U
#define SCHM_PWM_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_PWM_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_PWM_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_PWM_H_SW_MAJOR_VERSION            1U
#define SCHM_PWM_H_SW_MINOR_VERSION            2U
#define SCHM_PWM_H_SW_PATCH_VERSION            1U

/***************************************************************************************************
  File Version Checks
 **************************************************************************************************/
/***************************************************************************************************
  Macro Definition
 **************************************************************************************************/
/***************************************************************************************************
  Type Definition
 **************************************************************************************************/
/***************************************************************************************************
  GLOBAL VARIABLE DECLARATIONS
 **************************************************************************************************/
/***************************************************************************************************
  Function Declaration
 **************************************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

extern void SchM_Enter_Pwm_SetMcpwmNotifIrq(void);
extern void SchM_Exit_Pwm_SetMcpwmNotifIrq(void);

extern void SchM_Enter_Pwm_SetMcpwmOutputTriggerRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmOutputTriggerRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmGlobalControlRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmGlobalControlRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmSoftwareControlRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmSoftwareControlRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmChannelConfigurationRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmChannelConfigurationRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmGlobalStatusRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmGlobalStatusRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmModuloValueRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmModuloValueRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmChannelValueRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmChannelValueRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmReloadRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmReloadRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmSyncRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmSyncRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmTimeRegister(void);
extern void SchM_Exit_Pwm_SetMcpwmTimeRegister(void);

extern void SchM_Enter_Pwm_SetMcpwmChannelState(void);
extern void SchM_Exit_Pwm_SetMcpwmChannelState(void);

extern void SchM_Enter_Pwm_SetMCPWMCounterRegister(void);
extern void SchM_Exit_Pwm_SetMCPWMCounterRegister(void);





extern void SchM_Enter_Pwm_SetTimNotifIrq(void);
extern void SchM_Exit_Pwm_SetTimNotifIrq(void);

extern void SchM_Enter_Pwm_SetTimOutputControlRegister(void);
extern void SchM_Exit_Pwm_SetTimOutputControlRegister(void);

extern void SchM_Enter_Pwm_SetTimGlobalControlRegister(void);
extern void SchM_Exit_Pwm_SetTimGlobalControlRegister(void);

extern void SchM_Enter_Pwm_SetTimSoftwareControlRegister(void);
extern void SchM_Exit_Pwm_SetTimSoftwareControlRegister(void);

extern void SchM_Enter_Pwm_SetTimTimeRegister(void);
extern void SchM_Exit_Pwm_SetTimTimeRegister(void);

extern void SchM_Enter_Pwm_SetTimReloadRegister(void);
extern void SchM_Exit_Pwm_SetTimReloadRegister(void);

extern void SchM_Enter_Pwm_SetTimSyncRegister(void);
extern void SchM_Exit_Pwm_SetTimSyncRegister(void);

extern void SchM_Enter_Pwm_SetTimFilterRegister(void);
extern void SchM_Exit_Pwm_SetTimFilterRegister(void);

extern void SchM_Enter_Pwm_SetTimChannelConfigurationRegister(void);
extern void SchM_Exit_Pwm_SetTimChannelConfigurationRegister(void);

extern void SchM_Enter_Pwm_SetTimGlobalStatusRegister(void);
extern void SchM_Exit_Pwm_SetTimGlobalStatusRegister(void);

extern void SchM_Enter_Pwm_SetTimModuloValueRegister(void);
extern void SchM_Exit_Pwm_SetTimModuloValueRegister(void);

extern void SchM_Enter_Pwm_SetTimCompValueRegister(void);
extern void SchM_Exit_Pwm_SetTimCompValueRegister(void);

extern void SchM_Enter_Pwm_SetTimChannelState(void);
extern void SchM_Exit_Pwm_SetTimChannelState(void);

extern void SchM_Enter_Pwm_SetTimCounterRegister(void);
extern void SchM_Exit_Pwm_SetTimCounterRegister(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_SPI_H */
