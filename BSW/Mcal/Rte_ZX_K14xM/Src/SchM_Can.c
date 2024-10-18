/**************************************************************************************************/
/**
 * @file      : SchM_Can.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup SchM_Can
 *  @brief Can schedule manager source file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Can.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_CAN_C_VENDOR_ID                   0x00B3U
#define SCHM_CAN_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_CAN_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_CAN_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_CAN_C_SW_MAJOR_VERSION            1U
#define SCHM_CAN_C_SW_MINOR_VERSION            2U
#define SCHM_CAN_C_SW_PATCH_VERSION            1U
/**
 *  @brief Check if current file and SchM_Dio header file are of the same vendor
 */
#if (SCHM_CAN_C_VENDOR_ID != SCHM_CAN_H_VENDOR_ID)
    #error "Vendor ID of SchM_Can.c and SchM_Can.h are different"
#endif

/* Check if current file and SchM_Can.h are of the same Autosar version */
#if ((SCHM_CAN_C_AR_RELEASE_MAJOR_VERSION != SCHM_CAN_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SCHM_CAN_C_AR_RELEASE_MINOR_VERSION != SCHM_CAN_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SCHM_CAN_C_AR_RELEASE_REVISION_VERSION != SCHM_CAN_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of SchM_Can.c and SchM_Can.h are different"
#endif

/* Check if current file and SchM_Can.h are of the same Software version */
#if ((SCHM_CAN_C_SW_MAJOR_VERSION != SCHM_CAN_H_SW_MAJOR_VERSION) ||                               \
     (SCHM_CAN_C_SW_MINOR_VERSION != SCHM_CAN_H_SW_MINOR_VERSION) ||                               \
     (SCHM_CAN_C_SW_PATCH_VERSION != SCHM_CAN_H_SW_PATCH_VERSION))
    #error "Software Version of SchM_Can.c and SchM_Can.h are different"
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

void SchM_Enter_Can_DisableIntGlobal(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_DisableIntGlobal(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_DisableModule(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_DisableModule(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_DisableClock(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_DisableClock(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_SetStandardBitTiming(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_SetStandardBitTiming(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_ConfigFdDataBitTiming(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_ConfigFdDataBitTiming(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_ConfigFdCompensation(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_ConfigFdCompensation(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_SetTxArbitrationDelay(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_SetTxArbitrationDelay(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_InterMaskBuff(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_InterMaskBuff(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_ConfigTimeStamp(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_ConfigTimeStamp(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_RecoveryBusOff(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_RecoveryBusOff(void)
{
    ResumeAllInterrupts();
}
void SchM_Enter_Can_CanCtl2Reg(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_CanCtl2Reg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_CanMcrReg(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_CanMcrReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_CanMecrReg(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_CanMecrReg(void)
{
    ResumeAllInterrupts();
}
void SchM_Enter_Can_CanRxmgMskReg(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_CanRxmgMskReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_SetFdArbitrationBitTiming(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_SetFdArbitrationBitTiming(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_CanCtl1Reg(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Can_CanCtl1Reg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Can_SetSelfWakeup(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Can_SetSelfWakeup(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Can */

/** @} end of group Rte_Module */
