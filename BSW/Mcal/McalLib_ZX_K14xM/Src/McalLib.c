/**************************************************************************************************/
/**
 * @file      : McalLib.c
 * @brief     : McalLib source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  McalLib_Module
 *  @{
 */

/** @defgroup McalLib
 *  @brief It provides the source code of McalLib APIS.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "McalLib_CustomCounter.h"
#include "McalLib_OsCounter.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define MCALLIB_C_VENDOR_ID                   0x00B3U
#define MCALLIB_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_C_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_C_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_C_SW_MAJOR_VERSION            1U
#define MCALLIB_C_SW_MINOR_VERSION            2U
#define MCALLIB_C_SW_PATCH_VERSION            1U

/* Check if current file and McalLib.h are the same vendor */
#if (MCALLIB_C_VENDOR_ID != MCALLIB_VENDOR_ID)
    #error "Vendor ID of McalLib.c and McalLib.h are different"
#endif

/* Check if current file and McalLib.h are the same Autosar version */
#if ((MCALLIB_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||                   \
     (MCALLIB_C_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION) ||                   \
     (MCALLIB_C_AR_RELEASE_REVISION_VERSION != MCALLIB_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib.c and McalLib.h are different"
#endif

/* Check if current file and McalLib.h are the same Software version */
#if ((MCALLIB_C_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) ||                                   \
     (MCALLIB_C_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION) ||                                   \
     (MCALLIB_C_SW_PATCH_VERSION != MCALLIB_SW_PATCH_VERSION))
    #error "Software Version of McalLib.c and McalLib.h are different"
#endif

/* Check if current file and McalLib_CustomCounter.h are the same vendor */
#if (MCALLIB_C_VENDOR_ID != MCALLIB_CUSTOMCOUNTER_H_VENDOR_ID)
    #error "McalLib.c and McalLib_CustomCounter.h have different vendor ids"
#endif

/* Check if current file and McalLib_CustomCounter.h are the same Autosar version */
#if ((MCALLIB_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (MCALLIB_C_AR_RELEASE_MINOR_VERSION != MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_MINOR_VERSION) ||   \
     (MCALLIB_C_AR_RELEASE_REVISION_VERSION !=                                                     \
      MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib.c and McalLib_CustomCounter.h are different"
#endif

/* Check if current file and McalLib_CustomCounter.h are the same Software version */
#if ((MCALLIB_C_SW_MAJOR_VERSION != MCALLIB_CUSTOMCOUNTER_H_SW_MAJOR_VERSION) ||                   \
     (MCALLIB_C_SW_MINOR_VERSION != MCALLIB_CUSTOMCOUNTER_H_SW_MINOR_VERSION) ||                   \
     (MCALLIB_C_SW_PATCH_VERSION != MCALLIB_CUSTOMCOUNTER_H_SW_PATCH_VERSION))
    #error "Software Version of McalLib.c and McalLib_CustomCounter.h are different"
#endif

/* Check if current file and McalLib_OsCounter.h are the same vendor */
#if (MCALLIB_C_VENDOR_ID != MCALLIB_OSCOUNTER_H_VENDOR_ID)
    #error "Vendor ID of McalLib.c and McalLib_OsCounter.h are different"
#endif

/* Check if current file and McalLib_OsCounter.h are the same Autosar version */
#if ((MCALLIB_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_OSCOUNTER_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (MCALLIB_C_AR_RELEASE_MINOR_VERSION != MCALLIB_OSCOUNTER_H_AR_RELEASE_MINOR_VERSION) ||       \
     (MCALLIB_C_AR_RELEASE_REVISION_VERSION != MCALLIB_OSCOUNTER_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib.c and McalLib_OsCounter.h are different"
#endif

/* Check if current file and McalLib_OsCounter.h are the same Software version */
#if ((MCALLIB_C_SW_MAJOR_VERSION != MCALLIB_OSCOUNTER_H_SW_MAJOR_VERSION) ||                       \
     (MCALLIB_C_SW_MINOR_VERSION != MCALLIB_OSCOUNTER_H_SW_MINOR_VERSION) ||                       \
     (MCALLIB_C_SW_PATCH_VERSION != MCALLIB_OSCOUNTER_H_SW_PATCH_VERSION))
    #error "Software Version of McalLib.c and McalLib_OsCounter.h are different"
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
#define MCALLIB_START_SEC_VAR_CLEARED_32
#include "McalLib_MemMap.h"

static volatile uint32 McalLib_IntDisabledCounter;

#define MCALLIB_STOP_SEC_VAR_CLEARED_32
#include "McalLib_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#ifdef MCAL_SUPPORT_USER_MODE
extern void Sys_SuspendAllInterrupts(void);
extern void Sys_ResumeAllInterrupts(void);
#endif
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

#define MCALLIB_START_SEC_CODE
#include "McalLib_MemMap.h"
/**
 * @brief     Initialize McalLib module, this function shall be called during startup
 *
 *
 * @return    None
 *
 */
void McalLib_Init(void)
{
#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
    McalLib_OsCounter_Init();
#endif

#if (MCALLIB_CUSTOM_COUNTER_ENABLE == STD_ON)
    McalLib_CustomCounter_Init();
#endif
    McalLib_IntDisabledCounter = 0U;
}

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
Std_ReturnType McalLib_GetCounterValue(McalLib_CounterType Counter, uint32 *Value)
{
    Std_ReturnType Ret = E_NOT_OK;

    switch (Counter)
    {
        case MCALLIB_COUNTER_SOFTWARE:
            *Value = 0U;
            Ret = E_OK;
            break;

#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_OS:
            Ret = McalLib_OsCounter_GetCounterValue(Value);
            break;
#endif

#if (MCALLIB_CUSTOM_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_CUSTOM:
            Ret = McalLib_CustomCounter_GetCounterValue(Value);
            break;
#endif
        default:
            /* do nothing */
            break;
    }

    return Ret;
}

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
                                       uint32 *ElapsedValue)
{
    Std_ReturnType Ret = E_NOT_OK;

    switch (Counter)
    {
        case MCALLIB_COUNTER_SOFTWARE:
            *ElapsedValue = 1U;
            *CounterValue += 1U;
            Ret = E_OK;
            break;

#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_OS:
            Ret = McalLib_OsCounter_GetElapsedValue(CounterValue, ElapsedValue);
            break;
#endif

#if (MCALLIB_CUSTOM_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_CUSTOM:
            Ret = McalLib_CustomCounter_GetElapsedValue(CounterValue, ElapsedValue);
            break;
#endif
        default:
            /* do thing */
            break;
    }

    return Ret;
}

/**
 * @brief     Convert microseconds to ticks
 *
 * @param[in] Counter: select the counter type
 * @param[in] MicroSecond: microseconds value
 *
 * @return    Converted tick value
 *
 */
uint32 McalLib_MicroSecToTicks(McalLib_CounterType Counter, uint32 MicroSecond)
{
    uint32 Value = 0u;

    switch (Counter)
    {
        case MCALLIB_COUNTER_SOFTWARE:
            Value = MicroSecond;
            break;

#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_OS:
            Value = McalLib_OsCounter_MicroSecToTicks(MicroSecond);
            break;
#endif

#if (MCALLIB_CUSTOM_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_CUSTOM:
            Value = McalLib_CustomCounter_MicroSecToTicks(MicroSecond);
            break;
#endif
        default:
            /* do nothing */
            break;
    }

    return Value;
}

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
void McalLib_SetCounterFreq(McalLib_CounterType Counter, uint32 Freq)
{
    switch (Counter)
    {
#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_OS:
            McalLib_OsCounter_SetCounterFreq(Freq);
            break;
#endif
#if (MCALLIB_CUSTOM_COUNTER_ENABLE == STD_ON)
        case MCALLIB_COUNTER_CUSTOM:
            McalLib_CustomCounter_SetCounterFreq(Freq);
            break;
#endif
        default:
            /* do nothing */
            break;
    }
}

/**
 * @brief     This function suspends all interrupts
 *
 * @return    None
 *
 */
void McalLib_SuspendAllInterrupts(void)
{
    if (0U == McalLib_IntDisabledCounter)
    {
#ifdef MCAL_SUPPORT_USER_MODE
        /* BASEPRI will be set to 0x10 in SVC handler  */
        Sys_SuspendAllInterrupts();
#else
        ASM_KEYWORD(" cpsid i");
#endif
    }
    McalLib_IntDisabledCounter++;
}

/**
 * @brief     This function resumes all interrupts
 *
 * @return    None
 *
 */
void McalLib_ResumeAllInterrupts(void)
{
    if (0U < McalLib_IntDisabledCounter)
    {
        McalLib_IntDisabledCounter--;
    }
    if (0U == McalLib_IntDisabledCounter)
    {
#ifdef MCAL_SUPPORT_USER_MODE
        /* BASEPRI will be set to 0x0 in SVC handler  */
        Sys_ResumeAllInterrupts();
#else
        ASM_KEYWORD(" cpsie i");
#endif
    }
}

#define MCALLIB_STOP_SEC_CODE
#include "McalLib_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group McalLib */

/** @} end of group McalLib_Module */
