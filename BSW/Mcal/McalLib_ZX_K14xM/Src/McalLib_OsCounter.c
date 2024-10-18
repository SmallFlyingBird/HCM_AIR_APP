/**************************************************************************************************/
/**
 * @file      : McalLib_OsCounter.c
 * @brief     : McalLib OS counter source file.
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

/** @defgroup McalLib_OsCounter
 *  @brief McalLib OS counter
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib_OsCounter.h"
#include "McalLib.h"
#include "Device_Regs.h"
#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT) && (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR)
        #include "Det.h"
    #endif
    #if (MCALLIB_OS_USED == MCALLIB_OS_FREERTOS)
        #include "FreeRTOSConfig.h"
    #endif
#endif /* (MCALLIB_OS_COUNTER_ENABLE == STD_ON) */

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define MCALLIB_OSCOUNTER_C_VENDOR_ID                   0x00B3U
#define MCALLIB_OSCOUNTER_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_OSCOUNTER_C_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_OSCOUNTER_C_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_OSCOUNTER_C_SW_MAJOR_VERSION            1U
#define MCALLIB_OSCOUNTER_C_SW_MINOR_VERSION            2U
#define MCALLIB_OSCOUNTER_C_SW_PATCH_VERSION            1U

/* Check if current file and McalLib_OsCounter.h are the same vendor */
#if (MCALLIB_OSCOUNTER_C_VENDOR_ID != MCALLIB_OSCOUNTER_H_VENDOR_ID)
    #error "Vendor ID of McalLib_OsCounter.c and McalLib_OsCounter.h are different"
#endif
/* Check if current file and McalLib_OsCounter.h are the same Autosar version */
#if ((MCALLIB_OSCOUNTER_C_AR_RELEASE_MAJOR_VERSION !=                                              \
      MCALLIB_OSCOUNTER_H_AR_RELEASE_MAJOR_VERSION) ||                                             \
     (MCALLIB_OSCOUNTER_C_AR_RELEASE_MINOR_VERSION !=                                              \
      MCALLIB_OSCOUNTER_H_AR_RELEASE_MINOR_VERSION) ||                                             \
     (MCALLIB_OSCOUNTER_C_AR_RELEASE_REVISION_VERSION !=                                           \
      MCALLIB_OSCOUNTER_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib_OsCounter.c and McalLib_OsCounter.h are different"
#endif
/* Check if current file and McalLib_OsCounter.h are the same Software version */
#if ((MCALLIB_OSCOUNTER_C_SW_MAJOR_VERSION != MCALLIB_OSCOUNTER_H_SW_MAJOR_VERSION) ||             \
     (MCALLIB_OSCOUNTER_C_SW_MINOR_VERSION != MCALLIB_OSCOUNTER_H_SW_MINOR_VERSION) ||             \
     (MCALLIB_OSCOUNTER_C_SW_PATCH_VERSION != MCALLIB_OSCOUNTER_H_SW_PATCH_VERSION))
    #error "Software Version of McalLib_OsCounter.c and McalLib_OsCounter.h are different"
#endif

/* Check if current file and McalLib.h are the same vendor */
#if (MCALLIB_OSCOUNTER_C_VENDOR_ID != MCALLIB_VENDOR_ID)
    #error "Vendor ID of McalLib_OsCounter.c and McalLib.h are different"
#endif
/* Check if current file and McalLib.h are the same Autosar version */
#if ((MCALLIB_OSCOUNTER_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
     (MCALLIB_OSCOUNTER_C_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION) ||         \
     (MCALLIB_OSCOUNTER_C_AR_RELEASE_REVISION_VERSION != MCALLIB_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib_OsCounter.c and McalLib.h are different"
#endif
/* Check if current file and McalLib_OsCounter.h are the same Software version */
#if ((MCALLIB_OSCOUNTER_C_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) ||                         \
     (MCALLIB_OSCOUNTER_C_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION) ||                         \
     (MCALLIB_OSCOUNTER_C_SW_PATCH_VERSION != MCALLIB_SW_PATCH_VERSION))
    #error "Software Version of McalLib_OsCounter.c and McalLib.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
        #if (STD_ON == MCALLIB_DEV_ERROR_DETECT) && (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR)
            /* Check if current file and Det.h are the same Autosar version */
            #if ((MCALLIB_OSCOUNTER_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
                 (MCALLIB_OSCOUNTER_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version of McalLib_OsCounter.c and Det.h are different"
            #endif
        #endif
    #endif /* (MCALLIB_OS_COUNTER_ENABLE == STD_ON) */

    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((MCALLIB_OSCOUNTER_C_AR_RELEASE_MAJOR_VERSION !=                                          \
          DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||                                               \
         (MCALLIB_OSCOUNTER_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of McalLib_OsCounter.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define Z20_SYSTICK_CTRL_ENABLE_POS  (0U)
#define Z20_SYSTICK_CTRL_ENABLE_MASK (1U << Z20_SYSTICK_CTRL_ENABLE_POS)
#define Z20_SYSTICK_CTRL_ENABLE(x)                                                                 \
    (((uint32)(((uint32)(x)) << Z20_SYSTICK_CTRL_ENABLE_POS)) & Z20_SYSTICK_CTRL_ENABLE_MASK)

#define Z20_SYSTICK_CTRL_CLKSOURCE_POS  (2U)
#define Z20_SYSTICK_CTRL_CLKSOURCE_MASK (1U << Z20_SYSTICK_CTRL_CLKSOURCE_POS)
#define Z20_SYSTICK_CTRL_CLKSOURCE(x)                                                              \
    (((uint32)(((uint32)(x)) << Z20_SYSTICK_CTRL_CLKSOURCE_POS)) & Z20_SYSTICK_CTRL_CLKSOURCE_MASK)

/**
 * @brief Defines maximum microseconds value for microseconds to ticks converting when
 * system tick is used, since maximum core frequency is 160M HZ.
 */
#define MCALLIB_MAX_MICROSECONDS_TO_TICKS (26800000U)

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)

    /** @defgroup Private_VariableDefinition
     *  @{
     */
    #define MCALLIB_START_SEC_VAR_CLEARED_8
    #include "McalLib_MemMap.h"

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
static boolean McalLib_InitFlag[MCALLIB_CORE_NUM];
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #define MCALLIB_STOP_SEC_VAR_CLEARED_8
    #include "McalLib_MemMap.h"

    #define MCALLIB_START_SEC_VAR_CLEARED_32
    #include "McalLib_MemMap.h"

static uint32 McalLib_OsCounterFreq[MCALLIB_CORE_NUM];

    #define MCALLIB_STOP_SEC_VAR_CLEARED_32
    #include "McalLib_MemMap.h"

    #define MCALLIB_START_SEC_CONST_PTR
    #include "McalLib_MemMap.h"

/**
 *  @brief Pointer to SysTick Register address
 */
/* MISRA2012 Rule-11.4 violation: Cast between integral type to a pointer object,
 no side effects foreseen by violating this rule, as Z20_SYSTICK is register address. */
static Z20_SysTickType *const Z20_SysTickRegPtr = Z20_SYSTICK;

    #define MCALLIB_STOP_SEC_CONST_PTR
    #include "McalLib_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

    #define MCALLIB_START_SEC_CODE
    #include "McalLib_MemMap.h"

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
static void McalLib_DetReportError(uint8 ServiceId, uint8 ErrorId);
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #if (MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL)
static void McalLib_Systick_Init(void);
    #endif

    #if ((MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL) || (MCALLIB_OS_USED == MCALLIB_OS_FREERTOS))
static uint32 McalLib_Systick_GetCounterValue(void);
static void   McalLib_Systick_GetElapsedValue(uint32 *CounterValue, uint32 *ElapsedValue);
    #endif

    #define MCALLIB_STOP_SEC_CODE
    #include "McalLib_MemMap.h"

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

    #define MCALLIB_START_SEC_CODE
    #include "McalLib_MemMap.h"

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
static void McalLib_DetReportError(uint8 ServiceId, uint8 ErrorId)
{
        #if (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR)
    (void)Det_ReportError(MCALLIB_MODULE_ID, MCALLIB_INSTANCE, ServiceId,
                          ErrorId);
        #else
    (void)ServiceId;
    (void)ErrorId;
    MCALLIB_DEV_ASSERT_START();
    /* Expression (0U == ErrorId) is used to avoid misra violation by pass FALSE, ErrorId can't be
     * 0U. */
    MCALLIB_DEV_ASSERT(0U == ErrorId);
    MCALLIB_DEV_ASSERT_END();
        #endif
}
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #if (MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL)
static void McalLib_Systick_Init(void)
{
        #if (MCALLIB_ENABLE_USER_MODE_SUPPORT == STD_ON)
    uint32 ModeSwitched;

    ModeSwitched = Sys_EnterPrivilegedMode();
        #endif
    /* set reload value */
    Z20_SysTickRegPtr->LOAD = (uint32)MCAL_SYSTICK_RELOAD_VALUE;
    /* Load the Z20_SYSTICK Counter Value */
    Z20_SysTickRegPtr->VAL = (uint32)0U;
    /* Disable Z20_SYSTICK IRQ and Enable Z20_SYSTICK Timer */
    Z20_SysTickRegPtr->CTRL =
        (uint32)(Z20_SYSTICK_CTRL_CLKSOURCE(MCALLIB_SYSTEM_TICK_TIMER_CLKSOURCE) |
                 Z20_SYSTICK_CTRL_ENABLE(1));

        #if (MCALLIB_ENABLE_USER_MODE_SUPPORT == STD_ON)
    if (1U == ModeSwitched)
    {
        Sys_EnterNonPrivilegedMode();
    }
        #endif
}
    #endif /* (MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL) */

    #if ((MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL) || (MCALLIB_OS_USED == MCALLIB_OS_FREERTOS))
static uint32 McalLib_Systick_GetCounterValue(void)
{
    uint32 Value;

        #if (MCALLIB_ENABLE_USER_MODE_SUPPORT == STD_ON)
    uint32 ModeSwitched;

    ModeSwitched = Sys_EnterPrivilegedMode();
        #endif

    Value = Z20_SysTickRegPtr->VAL;

        #if (MCALLIB_ENABLE_USER_MODE_SUPPORT == STD_ON)
    if (1U == ModeSwitched)
    {
        Sys_EnterNonPrivilegedMode();
    }
        #endif
    return Value;
}

static void McalLib_Systick_GetElapsedValue(uint32 *CounterValue, uint32 *ElapsedValue)
{
    uint32 CurrentValue;
        #if (MCALLIB_ENABLE_USER_MODE_SUPPORT == STD_ON)
    uint32 ModeSwitched;

    ModeSwitched = Sys_EnterPrivilegedMode();
        #endif

    CurrentValue = Z20_SysTickRegPtr->VAL;

    if (CurrentValue > *CounterValue)
    {
        /* counter overflow */
        *ElapsedValue = Z20_SysTickRegPtr->LOAD + 1U - CurrentValue + *CounterValue;
    }
    else
    {
        *ElapsedValue = *CounterValue - CurrentValue;
    }

    *CounterValue = CurrentValue;

        #if (MCALLIB_ENABLE_USER_MODE_SUPPORT == STD_ON)
    if (1U == ModeSwitched)
    {
        Sys_EnterNonPrivilegedMode();
    }
        #endif
}
    #endif /*((MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL) || (MCALLIB_OS_USED ==                     \
              MCALLIB_OS_FREERTOS))*/

    #define MCALLIB_STOP_SEC_CODE
    #include "McalLib_MemMap.h"

    /** @} end of group Private_FunctionDefinition */

    /** @defgroup Public_FunctionDefinition
     *  @{
     */
    #define MCALLIB_START_SEC_CODE
    #include "McalLib_MemMap.h"

/**
 * @brief     Initialize OS counter module, this function shall be called during startup
 *
 *
 * @return    None
 *
 */
void McalLib_OsCounter_Init(void)
{
    uint32 CoreId = McalLib_GetCoreID();

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    if (NULL_PTR == McalLib_PreDefinedConfigPtr[CoreId])
    {
        McalLib_DetReportError(MCALLIB_SID_INIT, MCALLIB_E_PARAM);
    }
    else
    {
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #if (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR)
        /* AUTOSAR OS */
        McalLib_OsCounterFreq[CoreId] = McalLib_PreDefinedConfigPtr[CoreId]->CounterFreq;
    #elif (MCALLIB_OS_USED == MCALLIB_OS_FREERTOS)
    /* FreeRTOS */
    McalLib_OsCounterFreq[CoreId] = configCPU_CLOCK_HZ;
    #elif (MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL)
    /* Baremetal */
    McalLib_OsCounterFreq[CoreId] = McalLib_PreDefinedConfigPtr[CoreId]->CounterFreq;
    McalLib_Systick_Init();
    #endif

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
        McalLib_InitFlag[CoreId] = (boolean)TRUE;
    }
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */
}

/**
 * @brief     Get the current value of the OS counter
 *
 * @param[out] Value: point to variable where the counter value will be stored by this API
 *
 * @return    Std_ReturnType
 * @retval    E_OK: succeed in getting counter value.
 * @retval    E_NOT_OK: fail to get counter value.
 *
 */
Std_ReturnType McalLib_OsCounter_GetCounterValue(uint32 *Value)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;
    uint32         CoreId = McalLib_GetCoreID();

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    if (TRUE != McalLib_InitFlag[CoreId])
    {
        McalLib_DetReportError(MCALLIB_SID_GET_COUNTER_VALUE, MCALLIB_E_UNINIT);
    }
    else
    {
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #if (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR)
        /* AUTOSAR OS */
        RetValue = GetCounterValue(McalLib_PreDefinedConfigPtr[CoreId]->CounterId, Value);

        #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
        if ((Std_ReturnType)E_OK != RetValue)
        {
            McalLib_DetReportError(MCALLIB_SID_GET_COUNTER_VALUE, MCALLIB_E_PARAM);
        }
        #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #elif ((MCALLIB_OS_USED == MCALLIB_OS_FREERTOS) || (MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL))
    /* FreeRTOS or Baremetal */
    *Value = McalLib_Systick_GetCounterValue();
    (void)CoreId;
    #endif

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    }
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    return RetValue;
}

/**
 * @brief     Get the number of ticks between the current tick value and a previously read tick
 *            value.
 *
 * @param[inout] CounterValue: in - the previously read tick value of the counter
 *                             out - the current tick value of the counter
 * @param[out] ElapsedValue: The elapsed value
 *
 * @return    Std_ReturnType
 * @retval    E_OK: succeed in getting elapsed value.
 * @retval    E_NOT_OK: fail to get elapsed value.
 *
 */
Std_ReturnType McalLib_OsCounter_GetElapsedValue(uint32 *const CounterValue, uint32 *ElapsedValue)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;
    uint32         CoreId = McalLib_GetCoreID();

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    if (TRUE != McalLib_InitFlag[CoreId])
    {
        McalLib_DetReportError(MCALLIB_SID_GET_ELAPSED_VALUE, MCALLIB_E_UNINIT);
    }
    else
    {
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #if (MCALLIB_OS_USED == MCALLIB_OS_AUTOSAR)
        /* AUTOSAR OS */
        RetValue = GetElapsedValue(McalLib_PreDefinedConfigPtr[CoreId]->CounterId, CounterValue,
                                   ElapsedValue);

        #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
        if ((Std_ReturnType)E_OK != RetValue)
        {
            McalLib_DetReportError(MCALLIB_SID_GET_ELAPSED_VALUE, MCALLIB_E_PARAM);
        }
        #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    #elif ((MCALLIB_OS_USED == MCALLIB_OS_FREERTOS) || (MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL))
    /* FreeRTOS or Baremetal */
    McalLib_Systick_GetElapsedValue(CounterValue, ElapsedValue);
    (void)CoreId;
    #endif

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    }
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    return RetValue;
}

/**
 * @brief     Convert microseconds to ticks
 *
 * @param[in] MicroSecond: microseconds value
 *
 * @return    The tick value
 *
 */
uint32 McalLib_OsCounter_MicroSecToTicks(uint32 MicroSecond)
{
    uint32 Ticks = 0U;
    uint64 Temp = 0U;
    uint32 CoreId = McalLib_GetCoreID();

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    if (TRUE != McalLib_InitFlag[CoreId])
    {
        McalLib_DetReportError(MCALLIB_SID_MICROSEC_TO_TICKS, MCALLIB_E_UNINIT);
    }
    else
    {
        if (MCALLIB_MAX_MICROSECONDS_TO_TICKS < MicroSecond)
        {
            McalLib_DetReportError(MCALLIB_SID_MICROSEC_TO_TICKS, MCALLIB_E_PARAM);
        }
        else
        {
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */
            Temp = (uint64)MicroSecond * (uint64)McalLib_OsCounterFreq[CoreId];
            Ticks = (uint32)(Temp / 1000000U);
    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
        }
    }
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */

    return Ticks;
}

/**
 * @brief     Set the counter frequency
 *
 * @param[in] Freq: the counter frequency
 *
 * @return    None
 *
 */
void McalLib_OsCounter_SetCounterFreq(uint32 Freq)
{
    uint32 CoreId = McalLib_GetCoreID();

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    if (TRUE != McalLib_InitFlag[CoreId])
    {
        McalLib_DetReportError(MCALLIB_SID_SET_COUNTER_FREQ, MCALLIB_E_UNINIT);
    }
    else
    {
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */
    #if ((MCALLIB_OS_USED == MCALLIB_OS_FREERTOS) || (MCALLIB_OS_USED == MCALLIB_OS_BAREMETAL))
        McalLib_OsCounterFreq[CoreId] = Freq;
    #else
    (void)CoreId;
    (void)Freq;
    #endif /* (MCALLIB_OS_USED == MCALLIB_OS_FREERTOS) || (MCALLIB_OS_USED ==                      \
              MCALLIB_OS_BAREMETAL) */

    #if (STD_ON == MCALLIB_DEV_ERROR_DETECT)
    }
    #endif /* (STD_ON == MCALLIB_DEV_ERROR_DETECT) */
}

    #define MCALLIB_STOP_SEC_CODE
    #include "McalLib_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#endif /* MCALLIB_OS_COUNTER_ENABLE == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} end of group McalLib_OsCounter */

/** @} end of group McalLib_Module */
