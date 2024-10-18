/**************************************************************************************************/
/**
 * @file      : Scc_Drv.c
 * @brief     : SCC low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Scc_Drv
 *  @brief SCC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Scc_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define SCC_DRV_C_VENDOR_ID                   0x00B3U
#define SCC_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCC_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define SCC_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define SCC_DRV_C_SW_MAJOR_VERSION            1U
#define SCC_DRV_C_SW_MINOR_VERSION            2U
#define SCC_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Mcu drv clock.h file are of the same vendor */
#if (SCC_DRV_C_VENDOR_ID != SCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Scc_Drv.c and Scc_Drv.h are different"
#endif

/* Check if current file and Mcu drv clock.h file are of the same Autosar version */
#if ((SCC_DRV_C_AR_RELEASE_MAJOR_VERSION != SCC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (SCC_DRV_C_AR_RELEASE_MINOR_VERSION != SCC_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (SCC_DRV_C_AR_RELEASE_REVISION_VERSION != SCC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Scc_Drv.c and Scc_Drv.h are different"
#endif

/* Check if current file and Mcu drv clock.h file are of the same Software version */
#if ((SCC_DRV_C_SW_MAJOR_VERSION != SCC_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (SCC_DRV_C_SW_MINOR_VERSION != SCC_DRV_H_SW_MINOR_VERSION) ||                                 \
     (SCC_DRV_C_SW_PATCH_VERSION != SCC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Scc_Drv.c and Scc_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((SCC_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (SCC_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Scc_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define SCC_DRV_WAIT_CLK_RDY_CNT  100000U
#define SCC_DRV_WAIT_SOSC_RDY_CNT 5000000U

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

#define MCU_START_SEC_CONST_PTR
#include "Mcu_MemMap.h"

/**
 *  @brief Pointer to Power Management Unit Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Pmu_BfType *const Scc_Drv_PmuRegBfPtr = (Reg_Pmu_BfType *)PMU_BASE_ADDR;
static Reg_Pmu_WType *const  Scc_Drv_PmuRegwPtr = (Reg_Pmu_WType *)PMU_BASE_ADDR;

/**
 *  @brief Pointer to System Clock Control Unit Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Scc_BfType *const Scc_Drv_SccRegBfPtr = (Reg_Scc_BfType *)SCC_BASE_ADDR;
static Reg_Scc_WType *const  Scc_Drv_SccRegWPtr = (Reg_Scc_WType *)SCC_BASE_ADDR;

/**
 *  @brief Pointer to RTC Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Rtc_BfType *const Scc_Drv_RtcRegBfPtr = (Reg_Rtc_BfType *)RTC_BASE_ADDR;
static Reg_Rtc_WType *const  Scc_Drv_RtcRegWPtr = (Reg_Rtc_WType *)RTC_BASE_ADDR;

/**
 *  @brief Pointer to Flash Unit Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
static Reg_Flash_BfType *const Scc_Drv_FlsRegBfPtr = (Reg_Flash_BfType *)FLASHC_BASE_ADDR;

#define MCU_STOP_SEC_CONST_PTR
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

/**
 * @brief     Configured PLL clock frequency.
 */
static uint32 Scc_Drv_PllClockFrequency;

#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_CLEARED_PTR
#include "Mcu_MemMap.h"

/**
 * @brief     Configured loss of FIRC64M clock callback function.
 */
static Scc_Drv_LocCallbackFunc Scc_Drv_Firc64MLocCallBackFunc;

/**
 * @brief     Configured loss of FOSC clock callback function.
 */
static Scc_Drv_LocCallbackFunc Scc_Drv_FoscLocCallBackFunc;

#define MCU_STOP_SEC_VAR_CLEARED_PTR
#include "Mcu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/**
 * @brief      Gets LPO32K clock ready state.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  LPO32K clock is ready.
 * @retval     FALSE: LPO32K clock is not ready.
 *
 */
static boolean Scc_Drv_GetLpo32KClockReadyState(void)
{
    boolean         ReadyState = FALSE;
    volatile uint32 LocalCount = 0U;

    for (; SCC_DRV_WAIT_CLK_RDY_CNT > LocalCount; ++LocalCount)
    {
        if (1U == Scc_Drv_PmuRegBfPtr->PMU_LPO_32K_CFG.LPO_CLK_READY)
        {
            ReadyState = TRUE;
            break;
        }
    }

    return ReadyState;
}

/**
 * @brief      Gets Slow Osc clock(SOSC) ready state.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  SOSC clock is ready.
 * @retval     FALSE: SOSC clock is not ready.
 *
 */
static boolean Scc_Drv_GetSOscClockReadyState(void)
{
    boolean         ReadyState = FALSE;
    volatile uint32 LocalCount = 0U;

    for (; SCC_DRV_WAIT_SOSC_RDY_CNT > LocalCount; ++LocalCount)
    {
        if (1U == Scc_Drv_RtcRegBfPtr->RTC_CSR.OSC_RDY)
        {
            ReadyState = TRUE;
            break;
        }
    }

    return ReadyState;
}

/**
 * @brief      Gets FIRC64M clock ready state.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  FIRC64M clock is ready.
 * @retval     FALSE: FIRC64M clock is not ready.
 *
 */
static boolean Scc_Drv_GetFirc64MClockReadyState(void)
{
    boolean         ReadyState = FALSE;
    volatile uint32 LocalCount = 0U;

    for (; SCC_DRV_WAIT_CLK_RDY_CNT > LocalCount; ++LocalCount)
    {
        if (1U == Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCRDY)
        {
            ReadyState = TRUE;
            break;
        }
    }

    return ReadyState;
}

/**
 * @brief      Gets Fast OSC clock(FOSC) ready state.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  FOSC clock is ready.
 * @retval     FALSE: FOSC clock is not ready.
 *
 */
static boolean Scc_Drv_GetFOscClockReadyState(void)
{
    boolean         ReadyState = FALSE;
    volatile uint32 LocalCount = 0U;

    for (; SCC_DRV_WAIT_CLK_RDY_CNT > LocalCount; ++LocalCount)
    {
        if (1U == Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCRDY)
        {
            ReadyState = TRUE;
            break;
        }
    }

    return ReadyState;
}

/**
 * @brief      Get PLL clock ready state.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  PLL clock is ready.
 * @retval     FALSE: PLL clock is not ready.
 *
 */
static boolean Scc_Drv_GetPllClockReadyState(void)
{
    boolean         ReadyState = FALSE;
    volatile uint32 LocalCount = 0U;

    for (; SCC_DRV_WAIT_CLK_RDY_CNT > LocalCount; ++LocalCount)
    {
        if (1U == Scc_Drv_SccRegBfPtr->SCC_SPLLCS.SPLLRDY)
        {
            if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK)
            {
                /* unlock this register */
                Scc_Drv_SccRegWPtr->SCC_SPLLCS = 0x5B000000U;
            }

            Scc_Drv_SccRegBfPtr->SCC_SPLLCS.OUTEN = 1U;
            Scc_Drv_SccRegBfPtr->SCC_SPLLCS.RDYEN = 0U;

            /* lock this register */
            Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK = 1U;

            ReadyState = TRUE;
            break;
        }
    }

    return ReadyState;
}

/**
 * @brief      Disables FIRC64M clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_DisableFirc64MClock(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_FIRCCS = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCEN = 0U;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK = 1U;
}

/**
 * @brief      Enable/disable FIC64M clock in stop mode.
 *
 * @param[in]  StopMode: Enable/Disable FIRC64M clock in stop mode.
 *
 * @return     None
 *
 */
static void Scc_Drv_ConfigFirc64MClockInStopMode(uint32 StopMode)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_FIRCCS = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCSTOPEN = (uint32)StopMode;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK = 1U;
}

/**
 * @brief      Enable LDO over driver, it is recommended to enable to guarantee the driving
 * capability.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_EnableLDOOverDrive(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCFG2.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_SPLLCFG2 = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_SPLLCFG2.LDOODEN = 1U;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_SPLLCFG2.LOCK = 1U;
}

/**
 * @brief      Enables PLL clock and configs enable/disable PLL clock in stop mode.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_EnablePllClock(void)
{
    Scc_Drv_EnableLDOOverDrive();

    if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_SPLLCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCKWIN = 3U;
    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.RDYEN = 1U;
    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.SPLLEN = 1U;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK = 1U;
}

/**
 * @brief      Enables/Disables PLL clock in stop mode.
 *
 * @param[in]  StopMode: Enable/Disable PLL clock in stop mode.
 *
 * @return     None
 *
 */
static void Scc_Drv_ConfigPllClockInStopMode(uint32 StopMode)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_SPLLCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.SPLLSTOPEN = (uint32)StopMode;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK = 1U;
}

/**
 * @brief      Configures loss of FIRC64M clock interrupt callback function.
 *
 * @param[in]  LocCallbackFunc: Loss of FIRC64M clock interrupt callback function.
 *
 * @return     None
 *
 */
LOCAL_INLINE void Scc_Drv_ConfigFirc64MLocCallback(Scc_Drv_LocCallbackFunc LocCallbackFunc)
{
    Scc_Drv_Firc64MLocCallBackFunc = LocCallbackFunc;
}

/**
 * @brief      Configures loss of FOSC clock interrupt callback function.
 *
 * @param[in]  LocCallbackFunc: Loss of FOSC clock interrupt callback function.
 *
 * @return     None
 *
 */
LOCAL_INLINE void Scc_Drv_ConfigFoscLocCallback(Scc_Drv_LocCallbackFunc LocCallbackFunc)
{
    Scc_Drv_FoscLocCallBackFunc = LocCallbackFunc;
}

/**
 * @brief      Enables FOSC clock and configs high frequency mode, stop mode and selects clock
 *             source.
 *
 * @param[in]  FreqMode: Enable/Disable high frequency mode.
 * @param[in]  StopMode: Enable/Disable FOSC in stop mode.
 * @param[in]  Mode: Clock source.
 *
 * @return     boolean
 * @retval     TRUE:  FOSC clock is enabled and ready.
 * @retval     TRUE:  FOSC clock is not enabled or not ready.
 *
 */
static boolean Scc_Drv_EnableFOscClock(Scc_Drv_FOscFreqModeType FreqMode, Scc_Drv_OscModeType Mode)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_OSCCFG.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_OSCCFG = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_OSCCFG.HFREQ = (uint32)FreqMode;
    Scc_Drv_SccRegBfPtr->SCC_OSCCFG.EXCLKS = (uint32)Mode;
    Scc_Drv_SccRegBfPtr->SCC_OSCCFG.OLMEN = 1U;

    /* lock */
    Scc_Drv_SccRegBfPtr->SCC_OSCCFG.LOCK = 1U;

    if (0U != Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_OSCCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCEN = 1U;
    /* lock */
    Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK = 1U;

    return Scc_Drv_GetClockReadyState(SCC_DRV_CLOCK_SRC_FOSC);
}

/**
 * @brief      Disables PLL clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_DisablePllClock(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_SPLLCS = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.SPLLEN = 0U;

    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.OUTEN = 0U;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK = 1U;
}

/**
 * @brief      Enables/Disables FOSC clock in stop mode.
 *
 * @param[in]  StopMode: Enable/Disable FOSC in stop mode.
 *
 * @return     None
 *
 */
static void Scc_Drv_ConfigFOscClockInStopMode(uint32 StopMode)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_OSCCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCSTOPEN = (uint32)StopMode;

    /* lock */
    Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK = 1U;
}

/**
 * @brief      Configs post divider, pre-divider, multiplier, pre-scaler and reference clock to
 *             PLL clock.
 *
 * @param[in]  PllConfigPtr: Pointer to the PLL configuration.
 *
 * @return     None
 *
 */
static void Scc_Drv_ConfigPllClock(const Scc_Drv_PllParamConfigType *PllConfigPtr)
{
    if (NULL_PTR != PllConfigPtr)
    {
        if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.LOCK)
        {
            /* unlock this register */
            Scc_Drv_SccRegWPtr->SCC_SPLLCFG1 = 0x5B000000U;
        }
        else
        {
            /* Do nothing */
        }

        /* Set up the PLL configuration register*/
        Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.POSTDIV = (uint32)(PllConfigPtr->PllPostDivider);
        Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.PREDIV = (uint32)(PllConfigPtr->PllPreDivider);
        Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.MULT = PllConfigPtr->PllMultiplier;
        Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.FBPRESEN = (uint32)(PllConfigPtr->PllPreScaler);
        Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.REFCKS = (uint32)(PllConfigPtr->PllRefClock);

        /* lock this register */
        Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.LOCK = 1U;

        /* Save  PLL clock source frequency */
        Scc_Drv_PllClockFrequency = PllConfigPtr->PllFreq;
    }
}

/**
 * @brief      Disables fast OSC clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_DisableFOscClock(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_OSCCS = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    if (0U != Scc_Drv_SccRegBfPtr->SCC_OSCCFG.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_OSCCFG = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCEN = 0U;
    Scc_Drv_SccRegBfPtr->SCC_OSCCFG.OLMEN = 0U;

    /* lock */
    Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK = 1U;
    Scc_Drv_SccRegBfPtr->SCC_OSCCFG.LOCK = 1U;
}

/**
 * @brief      Enables LPO32K clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_EnableLpo32KClock(void)
{
    if (0U != Scc_Drv_PmuRegBfPtr->PMU_LOCK.LOCK)
    {
        /* Unlock this register */
        Scc_Drv_PmuRegwPtr->PMU_LOCK = 0x94730000U;
    }

    Scc_Drv_PmuRegBfPtr->PMU_LPO_32K_CFG.LPO_CLK_DIS = 0U;

    /* Lock */
    Scc_Drv_PmuRegBfPtr->PMU_LOCK.LOCK = 1U;
}

/**
 * @brief      Disables LPO32K clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_DisableLpo32KClock(void)
{
    if (0U != Scc_Drv_PmuRegBfPtr->PMU_LOCK.LOCK)
    {
        /* Unlock this register */
        Scc_Drv_PmuRegwPtr->PMU_LOCK = 0x94730000U;
    }

    Scc_Drv_PmuRegBfPtr->PMU_LPO_32K_CFG.LPO_CLK_DIS = 1U;

    /* Lock */
    Scc_Drv_PmuRegBfPtr->PMU_LOCK.LOCK = 1U;
}

/**
 * @brief      Enables slow OSC (SOSC) clock and configs OSC clock source.
 *
 * @param[in]  Mode: Select OSC clock source.
 *
 * @return     None
 *
 */
static void Scc_Drv_EnableSOscClock(Scc_Drv_OscModeType Mode)
{
    if (0U != Scc_Drv_RtcRegBfPtr->RTC_LOCKR.LOCK)
    {
        Scc_Drv_RtcRegWPtr->RTC_LOCKR = 0x98670000U;
    }
    else
    {
        /* Do nothing */
    }

    if (SCC_DRV_OSC_XTAL == Mode)
    {
        Scc_Drv_RtcRegBfPtr->RTC_CSR.EXTAL_32K_EN = 0U;
        Scc_Drv_RtcRegBfPtr->RTC_CSR.CRYSTAL_EN = 1U;
    }
    else
    {
        Scc_Drv_RtcRegBfPtr->RTC_CSR.EXTAL_32K_EN = 1U;
        Scc_Drv_RtcRegBfPtr->RTC_CSR.CRYSTAL_EN = 0U;
    }

    Scc_Drv_RtcRegBfPtr->RTC_LOCKR.LOCK = 1U;
}

/**
 * @brief      Disables slow OSC (SOSC) clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_DisableSOscClock(void)
{
    if (0U != Scc_Drv_RtcRegBfPtr->RTC_LOCKR.LOCK)
    {
        Scc_Drv_RtcRegWPtr->RTC_LOCKR = 0x98670000U;
    }
    else
    {
        /* Do nothing */
    }

    Scc_Drv_RtcRegBfPtr->RTC_CSR.EXTAL_32K_EN = 0U;
    Scc_Drv_RtcRegBfPtr->RTC_CSR.CRYSTAL_EN = 0U;
    Scc_Drv_RtcRegBfPtr->RTC_LOCKR.LOCK = 1U;
}

/**
 * @brief      Configs system clock source and divider.
 *
 * @param[in]  Module:  System clock source.
 * @param[in]  Divider: Clock divider.
 *
 * @return     None
 *
 */
static void Scc_Drv_SetSysClockDivider(Scc_Drv_SysClockType        Module,
                                       Scc_Drv_SysClockDividerType Divider)
{
    switch (Module)
    {
        case SCC_DRV_SYS_CLOCK_CORE:
            if (0U != Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK)
            {
                /* unlock this register */
                Scc_Drv_SccRegWPtr->SCC_CFG = 0x5B000000U;
            }
            else
            {
                /* Do nothing */
            }

            Scc_Drv_SccRegWPtr->SCC_CFG =
                (Scc_Drv_SccRegWPtr->SCC_CFG & 0xFFFFF0FFU) | ((uint32)Divider << 8U);
            Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK = 1U;
            break;

        case SCC_DRV_SYS_CLOCK_BUS:
            if (0U != Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK)
            {
                /* unlock this register */
                Scc_Drv_SccRegWPtr->SCC_CFG = 0x5B000000U;
            }
            else
            {
                /* Do nothing */
            }

            Scc_Drv_SccRegWPtr->SCC_CFG =
                (Scc_Drv_SccRegWPtr->SCC_CFG & 0xFFFFFF0FU) | ((uint32)Divider << 4U);
            Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK = 1U;
            break;

        case SCC_DRV_SYS_CLOCK_SLOW:
            if (0U != Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK)
            {
                /* unlock this register */
                Scc_Drv_SccRegWPtr->SCC_CFG = 0x5B000000U;
            }
            else
            {
                /* Do nothing */
            }

            Scc_Drv_SccRegWPtr->SCC_CFG =
                (Scc_Drv_SccRegWPtr->SCC_CFG & 0xFFFFFFF0U) | (uint32)Divider;
            Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK = 1U;
            break;

        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      Sets system clock source with FIRC64M clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_SetSysClockSrcWithFirc64M(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_CFG = 0x5B000000U;
    }

    /* select system clock source with FIRC64M clock */
    Scc_Drv_SccRegWPtr->SCC_CFG = (Scc_Drv_SccRegWPtr->SCC_CFG & 0xFFF8FFFFU) | (1UL << 16U);

    Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK = 1U;
}

/**
 * @brief      Sets system clock source with Fast OSC(FOSC) clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_SetSysClockSrcWithFOsc(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_CFG = 0x5B000000U;
    }

    /* select system clock source with FOSC clock */
    Scc_Drv_SccRegWPtr->SCC_CFG = (Scc_Drv_SccRegWPtr->SCC_CFG & 0xFFF8FFFFU) | (2UL << 16U);

    Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK = 1U;
}

/**
 * @brief      Sets system clock source with PLL clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scc_Drv_SetSysClockSrcWithPll(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_CFG = 0x5B000000U;
    }

    /* select system clock source with PLL clock */
    Scc_Drv_SccRegWPtr->SCC_CFG = (Scc_Drv_SccRegWPtr->SCC_CFG & 0xFFF8FFFFU) | (3UL << 16U);

    Scc_Drv_SccRegBfPtr->SCC_CFG.LOCK = 1U;
}

/**
 * @brief      Updates RWSC in Flash module according to current system clock frequency.
 *
 * @param[in]  SysClockFreq: Current system clock frequency.
 *
 * @return     None
 *
 */
static void Scc_Drv_UpdateFlsWaitCounter(uint32 SysClockFreq)
{
    Scc_Drv_FlsRegBfPtr->FLASH_FCTRL.RWSC = (uint32)((SysClockFreq - 1U) / (uint32)32000000U);
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief      Enables OSC clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Scc_Drv_EnableOscClockMonitor(Scc_Drv_OscClockLossActType Act)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_OSCCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCCMRE = (uint32)Act;

    Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCCME = 1U;

    if (SCC_DRV_OSC_CLOCK_LOSS_INT == Act)
    {
        Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCLOCINTEN = 1U;
    }
    else
    {
        Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCLOCINTEN = 0U;
    }

    /* lock */
    Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK = 1U;
}

/**
 * @brief      Disables OSC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_DisableOscClockMonitor(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_OSCCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCCME = 0U;
    if (1U == Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCLOCINTEN)
    {
        Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCLOCINTEN = 0U;
    }

    Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK = 1U;
}

/**
 * @brief      Enables FIRC64M clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Scc_Drv_EnableFirc64MClockMonitor(Scc_Drv_Firc64MClockLossActType Act)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_FIRCCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCCMRE = (uint32)Act;
    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCCME = 1U;

    if (SCC_DRV_FIRC64M_CLOCK_LOSS_INT == Act)
    {
        Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCLOCINTEN = 1U;
    }
    else
    {
        Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCLOCINTEN = 0U;
    }

    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK = 1U;
}

/**
 * @brief      Disables FIRC64M clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_DisableFirc64MClockMonitor(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_FIRCCS = 0x5B000000U;
    }

    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCCME = 0U;
    if (1U == Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCLOCINTEN)
    {
        Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCLOCINTEN = 0U;
    }

    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK = 1U;
}

#if (SCC_DRV_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 * @brief      Enables PLL clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Scc_Drv_EnablePllClockMonitor(Scc_Drv_PllClockLossActType Act)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_SPLLCS = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOLRESTEN = (uint32)Act;

    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.RDYEN = 1U;
    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOLINTEN = 1U;
    /* lock */
    Scc_Drv_SccRegBfPtr->SCC_SPLLCS.LOCK = 1U;
}
#endif

/**
 * @brief       Configs SCC clock.
 *
 * @param[in]   ClockConfigPtr: Pointer to the SCC clock configuration.
 *
 * @return      None
 *
 */
void Scc_Drv_ConfigSccClock(const Scc_Drv_ClockConfigType *ClockConfigPtr)
{
    if (NULL_PTR != ClockConfigPtr)
    {
        if (TRUE == ClockConfigPtr->SccFOscClockConfig.Enable)
        {
            (void)Scc_Drv_EnableFOscClock(ClockConfigPtr->SccFOscClockConfig.SccOscHfreq,
                                          ClockConfigPtr->SccFOscClockConfig.Mode);
        }
        else
        {
            Scc_Drv_DisableFOscClock();
        }
        Scc_Drv_ConfigFoscLocCallback(ClockConfigPtr->SccFOscClockConfig.LocCallbackFunc);

        Scc_Drv_ConfigFOscClockInStopMode(
            (uint32)ClockConfigPtr->SccFOscClockConfig.SccOscEnableUnderStop);

        Scc_Drv_ConfigPllClock(&(ClockConfigPtr->SccPllClockConfig.SccPllClockParamConfig));
        if (TRUE == ClockConfigPtr->SccPllClockConfig.Enable)
        {
            Scc_Drv_EnablePllClock();
        }
        else
        {
            Scc_Drv_DisablePllClock();
        }

        Scc_Drv_ConfigPllClockInStopMode(
            (uint32)ClockConfigPtr->SccPllClockConfig.SccPllEnableUnderStop);

        if (TRUE == ClockConfigPtr->SccSOscClockConfig.Enable)
        {
            Scc_Drv_EnableSOscClock(ClockConfigPtr->SccSOscClockConfig.Mode);
        }
        else
        {
            Scc_Drv_DisableSOscClock();
        }

        if (TRUE == ClockConfigPtr->SccLpoClockConfig.Enable)
        {
            Scc_Drv_EnableLpo32KClock();
        }
        else
        {
            Scc_Drv_DisableLpo32KClock();
        }

        (void)Scc_Drv_SetSysClockSrc(ClockConfigPtr->SccSystemClockConfig.SccSystemClockSource,
                                     ClockConfigPtr->SccSystemClockConfig.SccSystemClockFreq);

        Scc_Drv_SetSysClockDivider(SCC_DRV_SYS_CLOCK_CORE,
                                   ClockConfigPtr->SccSystemClockConfig.SccCoreClockDivider);
        Scc_Drv_SetSysClockDivider(SCC_DRV_SYS_CLOCK_BUS,
                                   ClockConfigPtr->SccSystemClockConfig.SccBusClockDivider);
        Scc_Drv_SetSysClockDivider(SCC_DRV_SYS_CLOCK_SLOW,
                                   ClockConfigPtr->SccSystemClockConfig.SccSlowClockDivider);

        if (FALSE == ClockConfigPtr->SccFircClockConfig.Enable)
        {
            Scc_Drv_DisableFirc64MClock();
        }

        Scc_Drv_ConfigFirc64MClockInStopMode(
            (uint32)ClockConfigPtr->SccFircClockConfig.Firc64MStopEn);

        Scc_Drv_ConfigFirc64MLocCallback(ClockConfigPtr->SccFircClockConfig.Firc64MLocCallbackFunc);
    }
}

/**
 * @brief       Gets PLL clock status.
 *
 * @param[in]   None
 *
 * @return      boolean
 * @retval      TRUE:  PLL is enabled and ready.
 * @retval      FALSE: PLL is not enabled or not ready.
 *
 */
boolean Scc_Drv_GetPllClockStatus(void)
{
    boolean ReturnPllStatus = FALSE;

    uint32 PllStatus;

    PllStatus = Scc_Drv_SccRegBfPtr->SCC_SPLLCS.SPLLRDY;

    if (1UL == PllStatus)
    {
        ReturnPllStatus = TRUE;
    }

    return ReturnPllStatus;
}

/**
 * @brief       Gets whether the PLL clock has been selected system clock source.
 *
 * @param[in]   None
 *
 * @return      boolean
 * @retval      TRUE:  PLL is the system clock source.
 * @retval      FALSE: PLL is not the system clock source.
 *
 */
boolean Scc_Drv_GetPllClockSelectedState(void)
{
    boolean PllSelectedStatus = FALSE;

    if (1UL == Scc_Drv_SccRegBfPtr->SCC_SPLLCS.SPLLSELD)
    {
        PllSelectedStatus = TRUE;
    }

    return PllSelectedStatus;
}

/**
 * @brief       Gets FIRC64M clock status.
 *
 * @param[in]   None
 *
 * @return      boolean
 * @retval      TRUE:  FIRC64M clock is enabled and ready.
 * @retval      FALSE: FIRC64M clock is not enabled or not ready.
 */
boolean Scc_Drv_GetFirc64MClockStatus(void)
{
    uint32 ReturnStatus;

    ReturnStatus = Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCRDY;

    return (boolean)ReturnStatus;
}

/**
 * @brief     Sets the system clock source and update RWSC in Flash module according to system
 * clock frequency.
 * @note      The selected clock source has to be ready before call this function.
 *
 * @param[in] ClockSrc: Selected clock source.
 * @param[in] SysClockFreq: System clock frequency.
 *
 * @return    boolean
 * @retval    TRUE:  System clock source has been set with the given clock source.
 * @retval    FALSE: Set system clock source with given clock source failed, e.g. given clock source
 *                   is not ready.
 */
boolean Scc_Drv_SetSysClockSrc(Scc_Drv_SystemClockType ClockSrc, uint32 SysClockFreq)
{
    boolean ReturnVal = FALSE;

    if (SCC_DRV_SYS_CLOCK_FIRC64M == ClockSrc)
    {
        if (TRUE != Scc_Drv_GetClockReadyState(SCC_DRV_CLOCK_SRC_FIRC64M))
        {
            ReturnVal = FALSE;
        }
        else
        {
            Scc_Drv_UpdateFlsWaitCounter(SysClockFreq);
            Scc_Drv_SetSysClockSrcWithFirc64M();
            ReturnVal = TRUE;
        }
    }
    else if (SCC_DRV_SYS_CLOCK_FOSC == ClockSrc)
    {
        if (TRUE != Scc_Drv_GetClockReadyState(SCC_DRV_CLOCK_SRC_FOSC))
        {
            ReturnVal = FALSE;
        }
        else
        {
            Scc_Drv_UpdateFlsWaitCounter(SysClockFreq);
            Scc_Drv_SetSysClockSrcWithFOsc();
            ReturnVal = TRUE;
        }
    }
    else if (SCC_DRV_SYS_CLOCK_PLL == ClockSrc)
    {
        if (TRUE != Scc_Drv_GetClockReadyState(SCC_DRV_CLOCK_SRC_PLL))
        {
            ReturnVal = FALSE;
        }
        else
        {
            Scc_Drv_UpdateFlsWaitCounter(SysClockFreq);
            Scc_Drv_SetSysClockSrcWithPll();
            ReturnVal = TRUE;
        }
    }
    else
    {
        ReturnVal = FALSE;
    }

    return ReturnVal;
}

/**
 * @brief      Selects PLL referenced clock source.
 *
 * @param[in]  PllRefClk: PLL referenced clock.
 *
 * @return     None
 *
 */
void Scc_Drv_SelectPllClockRefSrc(Scc_Drv_PllRefClockType PllRefClk)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_SPLLCFG1 = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    /*Select FOSC or FIRC64M as PLL reference clock*/
    Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.REFCKS = (uint32)PllRefClk;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_SPLLCFG1.LOCK = 1U;
}

/**
 * @brief      Returns PLL clock frequency.
 *
 * @param[in]  None
 *
 * @return     uint32: PLL clock frequency
 *
 */
uint32 Scc_Drv_GetPllClockFreq(void)
{
    return Scc_Drv_PllClockFrequency;
}

/**
 * @brief      Enables FIRC64M clock.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_EnableFirc64MClock(void)
{
    if (0U != Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK)
    {
        /* unlock this register */
        Scc_Drv_SccRegWPtr->SCC_FIRCCS = 0x5B000000U;
    }
    else
    {
        /* Do nothing */
    }

    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCEN = 1U;

    /* lock this register */
    Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK = 1U;
}

/**
 * @brief      Get the given clock source ready state.
 *
 * @param[in]  ClockSource: Given clock source.
 *
 * @return     boolean
 * @retval     TRUE:  Given clock is ready.
 * @retval     FALSE: Given clock is not ready.
 *
 */
boolean Scc_Drv_GetClockReadyState(Scc_Drv_ClockSrcType ClockSource)
{
    boolean RetVal = FALSE;

    switch (ClockSource)
    {
        case SCC_DRV_CLOCK_SRC_LPO32K:
            RetVal = Scc_Drv_GetLpo32KClockReadyState();
            break;
        case SCC_DRV_CLOCK_SRC_SOSC:
            RetVal = Scc_Drv_GetSOscClockReadyState();
            break;
        case SCC_DRV_CLOCK_SRC_FIRC64M:
            RetVal = Scc_Drv_GetFirc64MClockReadyState();
            break;
        case SCC_DRV_CLOCK_SRC_FOSC:
            RetVal = Scc_Drv_GetFOscClockReadyState();
            break;
        case SCC_DRV_CLOCK_SRC_PLL:
            RetVal = Scc_Drv_GetPllClockReadyState();
            break;
        default:
            /* Do nothing */
            break;
    }

    return RetVal;
}

/**
 * @brief      SCC interrupt handler
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scc_Drv_IntHandler(void)
{
    if (Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCLOC != 0U)
    {
        if (Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK != 0U)
        {
            /* Unlock this register */
            Scc_Drv_SccRegWPtr->SCC_OSCCS = 0x5B000000U;
        }

        /* Clear interrupt status */
        Scc_Drv_SccRegBfPtr->SCC_OSCCS.OSCLOC = 1U;
        Scc_Drv_SccRegBfPtr->SCC_OSCCS.LOCK = 1U;

        if (Scc_Drv_FoscLocCallBackFunc != NULL_PTR)
        {
            Scc_Drv_FoscLocCallBackFunc();
        }
    }

    if (Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCLOC != 0U)
    {
        if (Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK != 0U)
        {
            /* Unlock this register */
            Scc_Drv_SccRegWPtr->SCC_FIRCCS = 0x5B000000U;
        }

        /* Clear int status */
        Scc_Drv_SccRegBfPtr->SCC_FIRCCS.FIRCLOC = 1U;
        Scc_Drv_SccRegBfPtr->SCC_FIRCCS.LOCK = 1U;

        if (Scc_Drv_Firc64MLocCallBackFunc != NULL_PTR)
        {
            Scc_Drv_Firc64MLocCallBackFunc();
        }
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Scc_Drv */

/** @} end of group Mcu_Module */
