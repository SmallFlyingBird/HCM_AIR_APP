/**************************************************************************************************/
/**
 * @file      : System.c
 * @brief     : system source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Platform_Module
 *  @{
 */

/** @defgroup System
 *  @brief It provides the source code of system common APIs.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "System.h"
#include "McalLib.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define SYSTEM_C_VENDOR_ID                   0x00B3U
#define SYSTEM_C_AR_RELEASE_MAJOR_VERSION    4U
#define SYSTEM_C_AR_RELEASE_MINOR_VERSION    6U
#define SYSTEM_C_AR_RELEASE_REVISION_VERSION 0U
#define SYSTEM_C_SW_MAJOR_VERSION            1U
#define SYSTEM_C_SW_MINOR_VERSION            2U
#define SYSTEM_C_SW_PATCH_VERSION            1U

/* Check if current file and System.h are the same vendor */
#if (SYSTEM_C_VENDOR_ID != SYSTEM_H_VENDOR_ID)
    #error "Vendor ID of System.c and System.h are different"
#endif

/* Check if current file and System.h are the same Autosar version */
#if ((SYSTEM_C_AR_RELEASE_MAJOR_VERSION != SYSTEM_H_AR_RELEASE_MAJOR_VERSION) ||                   \
     (SYSTEM_C_AR_RELEASE_MINOR_VERSION != SYSTEM_H_AR_RELEASE_MINOR_VERSION) ||                   \
     (SYSTEM_C_AR_RELEASE_REVISION_VERSION != SYSTEM_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of System.c and System.h are different"
#endif

/* Check if current file and System.h are the same Software version */
#if ((SYSTEM_C_SW_MAJOR_VERSION != SYSTEM_H_SW_MAJOR_VERSION) ||                                   \
     (SYSTEM_C_SW_MINOR_VERSION != SYSTEM_H_SW_MINOR_VERSION) ||                                   \
     (SYSTEM_C_SW_PATCH_VERSION != SYSTEM_H_SW_PATCH_VERSION))
    #error "Software Version of System.c and System.h are different"
#endif

/* SCB Application Interrupt and Reset Control Register Definitions */
/*!< SCB AIRCR: VECTKEY Position */
#define Z20_SCB_AIRCR_VECTKEY_POS (16U)

/*!< SCB AIRCR: PRIGROUP Position */
#define Z20_Z20_SCB_AIRCR_PRIGROUP_POS (8U)
/*!< SCB AIRCR: PRIGROUP Mask */
#define Z20_Z20_SCB_AIRCR_PRIGROUP_MASK (7UL << Z20_Z20_SCB_AIRCR_PRIGROUP_POS)

/*!< SCB AIRCR: SYSRESETREQ Position */
#define Z20_SCB_AIRCR_SYSRESETREQ_POS (2U)
/*!< SCB AIRCR: SYSRESETREQ Mask */
#define Z20_SCB_AIRCR_SYSRESETREQ_MASK (1UL << Z20_SCB_AIRCR_SYSRESETREQ_POS)

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
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#ifdef MCAL_SUPPORT_USER_MODE
/**
 * @brief     Suspend all interrupts.
 * @details   This function suspends all interrupts.
 *
 * @return    None
 *
 */
void Sys_SuspendAllInterrupts(void)
{
    uint32 ControlReg;
    uint32 IpsrReg;

    /* if it's 0, Thread mode has privileged access */
    ControlReg = McalLib_ReadControlReg();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    IpsrReg = McalLib_ReadIpsrReg();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is
     * no need to make the switch */
    if ((0U == (ControlReg & 1U)) || ((IpsrReg & 0x1FFU) > 0U))
    {
        ASM_KEYWORD(" cpsid i");
    }
    else
    {
        ASM_KEYWORD(" svc 0x1");
    }
}

/**
 * @brief     Resume all interrupts.
 * @details   This function resumes all interrupts.
 *
 * @return    None
 *
 */
void Sys_ResumeAllInterrupts(void)
{
    uint32 ControlReg;
    uint32 IpsrReg;

    /* if it's 0, Thread mode has privileged access */
    ControlReg = McalLib_ReadControlReg();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    IpsrReg = McalLib_ReadIpsrReg();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is
     * no need to make the switch */
    if ((0U == (ControlReg & 1U)) || ((IpsrReg & 0x1FFU) > 0U))
    {
        ASM_KEYWORD(" cpsie i");
    }
    else
    {
        ASM_KEYWORD(" svc 0x2");
    }
}

/**
 * @brief     Enter privileged thread mode.
 * @details   Enter privileged thread mode. If it is already privileged(privileged thread mode or
 *            handle mode), this API does nothing; If it is in non-privileged thread mode, it will
 *            switched to privileged mode.
 *
 * @return    If it has switched from Non-privileged to privileged.
 * @retval    0U - no switch occurs because it is already in privileged mode
 * @retval    1U - switched from Non-privileged to privileged
 *
 */
uint32 Sys_EnterPrivilegedMode(void)
{
    uint32 ControlReg;
    uint32 IpsrReg;
    uint32 SwitchToPrivileged;

    /* if it's 0, Thread mode has privileged access */
    ControlReg = McalLib_ReadControlReg();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    IpsrReg = McalLib_ReadIpsrReg();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is
     * no need to make the switch */
    if ((0U == (ControlReg & 1U)) || ((IpsrReg & 0x1FFU) > 0U))
    {
        SwitchToPrivileged = 0U;
    }
    else
    {
        SwitchToPrivileged = 1U;
        ASM_KEYWORD("svc 0x0");
    }

    return SwitchToPrivileged;
}

/**
 * @brief     Enter Non-privileged thread mode.
 * @details   Enter Non-privileged thread mode.
 *
 * @return    None
 *
 */
void Sys_EnterNonPrivilegedMode(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("ldr r0, =0x1");
    ASM_KEYWORD("msr CONTROL, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif /* MCAL_SUPPORT_USER_MODE */

/**
  @brief   System Reset
  @details Initiates a system reset request to reset the MCU.
 */
void Sys_SystemReset(void)
{
    /* Ensure completion of memory access before reset config */
    MCALLIB_DATA_SYNC_BARRIER();

    /* Keep priority group unchanged */
    /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
    object, no side effects forseen by violating this rule.
    The following two lines of code also violate this rule with the same reason. */
    Z20_SCB->AIRCR = (uint32)((0x5FAUL << Z20_SCB_AIRCR_VECTKEY_POS) |
                              (Z20_SCB->AIRCR & Z20_Z20_SCB_AIRCR_PRIGROUP_MASK) |
                              Z20_SCB_AIRCR_SYSRESETREQ_MASK);

    /* Ensure completion of memory access */
    MCALLIB_DATA_SYNC_BARRIER();

    /* wait until reset */
    for (;;)
    {
        MCALLIB_NOP();
    }
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group System */

/** @} end of group Platform_Module */
