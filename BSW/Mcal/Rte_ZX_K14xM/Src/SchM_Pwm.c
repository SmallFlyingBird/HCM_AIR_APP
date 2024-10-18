/**************************************************************************************************/
/**
 * @file      : SchM_Pwm.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/**
 * @file SchM_Pwm.c
 * @brief Pwm schedule source file. This is a stub file.
 *
 */

/** @addtogroup  Rte_Module
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Pwm.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_PWM_C_VENDOR_ID                   0x00B3U
#define SCHM_PWM_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_PWM_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_PWM_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_PWM_C_SW_MAJOR_VERSION            1U
#define SCHM_PWM_C_SW_MINOR_VERSION            2U
#define SCHM_PWM_C_SW_PATCH_VERSION            1U


/* Check if current file and SchM_Pwm.h are the same vendor */
#if (SCHM_PWM_C_VENDOR_ID != SCHM_PWM_H_VENDOR_ID)
    #error "Vendor ID of SchM_Pwm.c and SchM_Pwm.h are different"
#endif
/* Check if current file and SchM_Pwm.h are the same AutoSar version */
#if ((SCHM_PWM_C_AR_RELEASE_MAJOR_VERSION    != SCHM_PWM_H_AR_RELEASE_MAJOR_VERSION) || \
     (SCHM_PWM_C_AR_RELEASE_MINOR_VERSION    != SCHM_PWM_H_AR_RELEASE_MINOR_VERSION) || \
     (SCHM_PWM_C_AR_RELEASE_REVISION_VERSION != SCHM_PWM_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of SchM_Pwm.c and SchM_Pwm.h are different"
#endif
/* Check if current file and SchM_Pwm.h are the same Software version */
#if ((SCHM_PWM_C_SW_MAJOR_VERSION != SCHM_PWM_H_SW_MAJOR_VERSION) || \
     (SCHM_PWM_C_SW_MINOR_VERSION != SCHM_PWM_H_SW_MINOR_VERSION) || \
     (SCHM_PWM_C_SW_PATCH_VERSION != SCHM_PWM_H_SW_PATCH_VERSION))
    #error "Software Version of SchM_Pwm.c and SchM_Pwm.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

void SchM_Enter_Pwm_SetMcpwmNotifIrq(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmNotifIrq(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmOutputTriggerRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmOutputTriggerRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmGlobalControlRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmGlobalControlRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmSoftwareControlRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmSoftwareControlRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmChannelConfigurationRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmChannelConfigurationRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmGlobalStatusRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmGlobalStatusRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmModuloValueRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmModuloValueRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmChannelValueRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmChannelValueRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmReloadRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmReloadRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmSyncRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmSyncRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmTimeRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmTimeRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMcpwmChannelState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMcpwmChannelState(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetMCPWMCounterRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetMCPWMCounterRegister(void)
{
    ResumeAllInterrupts();
}



void SchM_Enter_Pwm_SetTimNotifIrq(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimNotifIrq(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimOutputControlRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimOutputControlRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimGlobalControlRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimGlobalControlRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimSoftwareControlRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimSoftwareControlRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimTimeRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimTimeRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimReloadRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimReloadRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimSyncRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimSyncRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimFilterRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimFilterRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimChannelConfigurationRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimChannelConfigurationRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimGlobalStatusRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimGlobalStatusRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimModuloValueRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimModuloValueRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimCompValueRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimCompValueRegister(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimChannelState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimChannelState(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Pwm_SetTimCounterRegister(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Pwm_SetTimCounterRegister(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Rte_Module */
