/**************************************************************************************************/
/**
 * @file      : McalLib.h
 * @brief     : It provides specific definitions for AUTOSAR MCAL.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MCALLIB_H
#define MCALLIB_H

/** @addtogroup  McalLib_Module
 *  @{
 */

/** @defgroup McalLib
 *  @brief It provides specific definitions for AUTOSAR MCAL
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "McalLib_Compiler.h"
#include "McalLib_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define MCALLIB_MODULE_ID                   2048U
#define MCALLIB_VENDOR_ID                   0x00B3U
#define MCALLIB_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_SW_MAJOR_VERSION            1U
#define MCALLIB_SW_MINOR_VERSION            2U
#define MCALLIB_SW_PATCH_VERSION            2U

/* Check if current file and McalLib_Compiler.h are the same vendor */
#if (MCALLIB_VENDOR_ID != MCALLIB_COMPILER_H_VENDOR_ID)
    #error "Vendor ID of McalLib.h and McalLib_Compiler.h are different"
#endif

/* Check if current file and McalLib_Compiler.h are the same Autosar version */
#if ((MCALLIB_AR_RELEASE_MAJOR_VERSION != MCALLIB_COMPILER_H_AR_RELEASE_MAJOR_VERSION) ||          \
     (MCALLIB_AR_RELEASE_MINOR_VERSION != MCALLIB_COMPILER_H_AR_RELEASE_MINOR_VERSION) ||          \
     (MCALLIB_AR_RELEASE_REVISION_VERSION != MCALLIB_COMPILER_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib.h and McalLib_Compiler.h are different"
#endif

/* Check if current file and McalLib_Compiler.h are the same Software version */
#if ((MCALLIB_SW_MAJOR_VERSION != MCALLIB_COMPILER_H_SW_MAJOR_VERSION) ||                          \
     (MCALLIB_SW_MINOR_VERSION != MCALLIB_COMPILER_H_SW_MINOR_VERSION) ||                          \
     (MCALLIB_SW_PATCH_VERSION != MCALLIB_COMPILER_H_SW_PATCH_VERSION))
    #error "Software Version of McalLib.h and McalLib_Compiler.h are different"
#endif

/* Check if current file and McalLib_Cfg.h are the same vendor */
#if (MCALLIB_VENDOR_ID != MCALLIB_CFG_H_VENDOR_ID)
    #error "Vendor ID of McalLib.h and McalLib_Cfg.h are different"
#endif

/* Check if current file and McalLib_Cfg.h are the same Autosar version */
#if ((MCALLIB_AR_RELEASE_MAJOR_VERSION != MCALLIB_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (MCALLIB_AR_RELEASE_MINOR_VERSION != MCALLIB_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (MCALLIB_AR_RELEASE_REVISION_VERSION != MCALLIB_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib.h and McalLib_Cfg.h are different"
#endif

/* Check if current file and McalLib_Cfg.h are the same Software version */
#if ((MCALLIB_SW_MAJOR_VERSION != MCALLIB_CFG_H_SW_MAJOR_VERSION) ||                               \
     (MCALLIB_SW_MINOR_VERSION != MCALLIB_CFG_H_SW_MINOR_VERSION) ||                               \
     (MCALLIB_SW_PATCH_VERSION != MCALLIB_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of McalLib.h and McalLib_Cfg.h are different"
#endif

/** @name Service IDs
 * @{
 */
#define MCALLIB_SID_INIT              0x01U
#define MCALLIB_SID_GET_COUNTER_VALUE 0x02U
#define MCALLIB_SID_GET_ELAPSED_VALUE 0x03U
#define MCALLIB_SID_MICROSEC_TO_TICKS 0x04U
#define MCALLIB_SID_SET_COUNTER_FREQ  0x05U
/** @} */

/** @name Development errors
 * @{
 */
#define MCALLIB_E_PARAM  0x01U /*!< invalid parameter */
#define MCALLIB_E_UNINIT 0x02U /*!< API service called without module initialization */
#define MCALLIB_E_COREID 0x03U /*!< invalid core ID */

/** @} */

#define McalLib_GetCoreID() (0U)

#if (defined(MCALLIB_OS_USED) && (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR))
    #include "Os.h"
#else
    /**
     * @brief defines an interrupt handler if no OS is present.
     */
    #define ISR(IsrName)           INTERRUPT_FUNC void IsrName(void)

    /**
     * @brief suspend all interrupts if no OS is present.
     */
    // #define SuspendAllInterrupts() McalLib_SuspendAllInterrupts()

    /**
     * @brief resume all interrupts if no OS is present.
     */
    // #define ResumeAllInterrupts()  McalLib_ResumeAllInterrupts()
#endif

#if (MCALLIB_DEV_ASSERT_ENABLE == STD_ON)
    #define MCALLIB_DEV_ASSERT_START()                                                             \
        while (1U)                                                                                 \
        {
#else
    #define MCALLIB_DEV_ASSERT_START()
#endif

#if (MCALLIB_DEV_ASSERT_ENABLE == STD_ON)
    #define MCALLIB_DEV_ASSERT(expr)                                                               \
        if ((boolean)(expr) == (boolean)0U)                                                        \
        {                                                                                          \
            McalLib_Assert((uint8 *)__FILE__, __LINE__);                                           \
            break;                                                                                 \
        }
#else
    #define MCALLIB_DEV_ASSERT(expr)
#endif

#if (MCALLIB_DEV_ASSERT_ENABLE == STD_ON)
    #define MCALLIB_DEV_ASSERT_END()                                                               \
        break;                                                                                     \
        }
#else
    #define MCALLIB_DEV_ASSERT_END()
#endif

/**
 * @brief Data Synchronization Barrier (DSB)
 */
#define MCALLIB_DATA_SYNC_BARRIER() ASM_KEYWORD("DSB")

/**
 * @brief Instruction Synchronization Barrier (ISB)
 */
#define MCALLIB_INSTRUCTION_SYNC_BARRIER() ASM_KEYWORD("ISB")

/**
 * @brief No Operation
 * @details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define MCALLIB_NOP() ASM_KEYWORD("nop")

/**
 * @brief Exit interrupt
 */
#if (!defined(MCALLIB_OS_USED)) ||                                                                 \
    (defined(MCALLIB_OS_USED) && (MCALLIB_OS_USED != MCALLIB_OS_AUTOSAR))
    #define EXIT_INTERRUPT() MCALLIB_DATA_SYNC_BARRIER()
#else
    #define EXIT_INTERRUPT()
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief  Defines McalLib counter type
 */
typedef enum
{
    MCALLIB_COUNTER_SOFTWARE, /**< software counter */
#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
    MCALLIB_COUNTER_OS, /**< OS counter */
#endif                  /* (MCALLIB_USE_OS_COUNTER == STD_ON) */
#if (MCALLIB_CUSTOM_COUNTER_ENABLE == STD_ON)
    MCALLIB_COUNTER_CUSTOM /**< custom counter */
#endif                     /* (MCALLIB_USE_CUSTOM_TIMER == STD_ON) */
} McalLib_CounterType;

/**
 * @brief  McalLib configuration type
 */
typedef struct
{
#if (defined(MCALLIB_OS_USED) && (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR))
    CounterType CounterId;
#else
    uint32 CounterId;
#endif
    uint32 CounterFreq;
} McalLib_ConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define MCALLIB_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "McalLib_MemMap.h"

extern const McalLib_ConfigType *const McalLib_PreDefinedConfigPtr[MCALLIB_CORE_NUM];

#define MCALLIB_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "McalLib_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/* prototypes are defined in System.h */
#if (!defined(MCALLIB_OS_USED)) ||                                                                 \
    (defined(MCALLIB_OS_USED) && (MCALLIB_OS_USED != MCALLIB_OS_AUTOSAR))
    #ifdef MCAL_SUPPORT_USER_MODE
extern uint32 Sys_EnterPrivilegedMode(void);
extern void   Sys_EnterNonPrivilegedMode(void);
    #endif /* MCAL_SUPPORT_USER_MODE */
#endif       /* (MCALLIB_OS_USED != MCALLIB_OS_AUTOSAR) */
extern void Sys_SystemReset(void);

#define MCALLIB_START_SEC_CODE
#include "McalLib_MemMap.h"

/**
 * @brief     Initialize McalLib module, this function shall be called during startup
 *
 * @return    None
 *
 */
void McalLib_Init(void);

/**
 * @brief     Get the current value of the counter
 *
 * @param[in] Counter: select the counter type
 * @param[out] Value: point to variable where the counter value will be stored by this API
 *
 * @return    Std_ReturnType
 * @retval    E_OK: succeed in getting counter value.
 * @retval    E_NOT_OK: fail to get counter value.
 *
 */
Std_ReturnType McalLib_GetCounterValue(McalLib_CounterType Counter, uint32 *Value);

/**
 * @brief     Get the number of ticks between the current tick value and a previously read tick
 *            value.
 *
 * @param[in] Counter: select the counter type
 * @param[inout] CounterValue: in - the previously read tick value of the counter
 *                             out - the current tick value of the counter
 * @param[out] ElapsedValue: The elapsed value
 *
 * @return    Std_ReturnType
 * @retval    E_OK: succeed in getting elapsed value.
 * @retval    E_NOT_OK: fail to get elapsed value.
 *
 */
Std_ReturnType McalLib_GetElapsedValue(McalLib_CounterType Counter, uint32 *const CounterValue,
                                       uint32 *ElapsedValue);

/**
 * @brief     Convert microseconds to ticks
 *
 * @param[in] Counter: select the counter type
 * @param[in] MicroSecond: microseconds value
 *
 * @return    Converted tick value
 *
 */
uint32 McalLib_MicroSecToTicks(McalLib_CounterType Counter, uint32 MicroSecond);

/**
 * @brief     Set the counter frequency.
 *            For software counter, this API does nothing.
 *            For OS counter, this API is only valid if baremetal or FreeRTOS is selected, this API
 *            does nothing if AUTOSAR os is selected.
 *
 * @param[in] Counter: select the counter type
 * @param[in] Freq: the counter frequency
 *
 * @return    None
 *
 */
void McalLib_SetCounterFreq(McalLib_CounterType Counter, uint32 Freq);

#if (MCALLIB_DEV_ASSERT_ENABLE == STD_ON)
/**
 * @brief     Reports the name of the source file and the source line number where the error
 *            has occurred
 *
 * @param[in] file: current file
 * @param[in] line: current line
 *
 * @return    None
 *
 */
LOCAL_INLINE void McalLib_Assert(const uint8 *File, uint32 Line)
{
    (void)File;
    (void)Line;
    /* Infinite loop. User can replace with his own way to report the file name and line number */
    for (;;)
    {
    }
}
#endif

/**
 * @brief   This function suspends all interrupts
 *
 * @return  None
 *
 * @note    Normally this function is called through SchM_Enter function.
 * If this function is called directly, user shall invoke this function in conjunction
 * with McalLib_ResumeAllInterrupts.
 * Nested call is permitted.
 *
 * @note    In user mode, this function will block all exceptions(including interrupts) with 
 * priority 1~15, while allowing exception with priority 0. 
 * To ensure interrupts can be resumed correctly in user mode, the priority of exception SVCall 
 * shall be set to 0(default priority is 0).
 *
 */
void McalLib_SuspendAllInterrupts(void);

/**
 * @brief   This function resumes all interrupts
 *
 * @return  None
 *
 * @note    Normally this function is called through SchM_Exit function.
 * If this function is called directly, user shall invoke this function in conjunction
 * with McalLib_SuspendAllInterrupts.
 * Nested call is permitted.
 *
 */
void McalLib_ResumeAllInterrupts(void);

#define MCALLIB_STOP_SEC_CODE
#include "McalLib_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group McalLib */

/** @} end of group McalLib_Module */

#endif /* MCALLIB_H */
