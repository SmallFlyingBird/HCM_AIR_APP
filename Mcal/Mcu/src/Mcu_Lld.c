/**
* @file    Mcu_Lld.c
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

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"
#include "Mcu.h"
#include "Mcu_Lld_Reg.h"
#include "Mcu_Lld.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_LLD_VENDOR_ID_C                      (180)
#define MCU_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define MCU_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define MCU_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define MCU_LLD_SW_MAJOR_VERSION_C               (2)
#define MCU_LLD_SW_MINOR_VERSION_C               (3)
#define MCU_LLD_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and MCU_LLD header file are of the same vendor */
#if (MCU_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
#error "Mcu_Lld.c and Mcu_Lld.h have different vendor ids"
#endif

/* Check if source file and MCU_LLD header file are of the same Autosar version */
#if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION_C != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LLD_AR_RELEASE_MINOR_VERSION_C != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_Lld.c and Mcu_Lld.h are different"
#endif

/* Check if source file and MCU_LLD header file are of the same Software version */
#if ((MCU_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_Lld.c and Mcu_Lld.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/

#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

#if (MCU_LLD_PCU_ISR_USED == STD_ON)
/* Store the Pcu notification functions */
MCU_VAR static Mcu_NotificationType Mcu_PcuNotiList[MCU_PCU_DOMAIN_NUMS];
#endif

#if (MCU_LLD_SCU_ISR_USED == STD_ON)
/* Store the cmu enable state */
MCU_VAR static boolean Mcu_CmuIntEnableList[MCU_CMU_CHANNEL_NUMS];
/* Store the Cmu notification function */
MCU_VAR static Mcu_CmuNotificationType Mcu_CmuNotiList[MCU_CMU_CHANNEL_NUMS];
#endif

#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"


#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"
/* Store last reset reason when reset is empty */
MCU_VAR static Mcu_RawResetType Mcu_ResetStatusValue = 0U;
#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
#define MCU_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))

#define MCU_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define MCU_REG_ADDR32_AEARWRITE(address, mask, value) \
    (MCU_REG_ADDR32_WRITE((address),                   \
                          ((MCU_REG_ADDR32_READ(address) & ((uint32) ~(mask))) | (value))))
#define MCU_REG_ADDR32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define MCU_REG_ADDR32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))
#define MCU_REG_ADDR32_INDEX_SET_BIT(address, bitindex) ((*(volatile uint32 *)(address)) |= ((uint32)1U << (bitindex)))
#define MCU_REG_ADDR32_INDEX_CLEAR_BIT(address, bitindex) ((*(volatile uint32 *)(address)) &= (~((uint32)1U << (bitindex))))

#define MCU_REG_ADDR32_GET_BITS(address, mask) ((*(volatile uint32 *)(address)) & (mask))
#define MCU_REG_ADDR32_INDEX_GET_BIT(address, bitindex) (((*(volatile uint32 *)(address)) >> (bitindex)) & ((uint32)1U))

#define MCU_CMU_ENABLE_AREA_OFFSET (uint32)(8U)
#define MCU_CMU_REFERENCE_AREA_OFFSET (uint32)(16U)
#define SCU_CMUSTS_CMUX_LOSR_MASK(Channel) (uint32)(((uint32)SCU_CMUSTS_CMU0_LOSR_MASK) << (Channel))
#define SCU_CMUSTS_CMUX_OUTRNG_MASK(Channel) (uint32)(((uint32)SCU_CMUSTS_CMU0_OUTRNG_MASK) << (Channel))
#define SCU_CMUSTS_CMUX_LOSC_MASK(Channel) (uint32)(((uint32)SCU_CMUSTS_CMU0_LOSC_MASK) << (Channel))
#define SCU_CMU_CTRL_CMUX_RE(Channel) (uint32)((uint32)(SCU_CMU_CTRL_CMU0_RE_MASK) << (Channel))
#define SCU_CMUSTS_MASK (0x000F0F0FU)
/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
/**
 * MR12 RULE 2.2 VIOLATION: The operation here is redundant as the result's value is always that
 * of the left-hand operand.This line of code has been maintained for the sake of code clarity and
 * readability.
 */
/* PRQA S 2985, 2986 EOF */
/* PRQA S 0306 EOF */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/**
 * @brief Disables all clock monitoring units.
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_DisableAllCmu(void)
{
#ifndef CPU_YTM32B1MC0
    MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_CMU_CTRL_OFFSET32,
                             SCU_CMU_CTRL_CMU0_EN_MASK |
                             SCU_CMU_CTRL_CMU1_EN_MASK |
                             SCU_CMU_CTRL_CMU2_EN_MASK |
                             SCU_CMU_CTRL_CMU3_EN_MASK,
                             SCU_CMU_CTRL_CMU0_EN(STD_OFF) |
                             SCU_CMU_CTRL_CMU1_EN(STD_OFF) |
                             SCU_CMU_CTRL_CMU2_EN(STD_OFF) |
                             SCU_CMU_CTRL_CMU3_EN(STD_OFF));
#else
    MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_CMU_CTRL_OFFSET32,
                             SCU_CMU_CTRL_CMU0_EN_MASK |
                             SCU_CMU_CTRL_CMU1_EN_MASK,
                             SCU_CMU_CTRL_CMU0_EN(STD_OFF) |
                             SCU_CMU_CTRL_CMU1_EN(STD_OFF));
#endif
}

/**
 * @brief Enables FIRC with deepSleep mode.
 * @param[in] DeepSleepEnable - Enable/Disable Deep Sleep Mode
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_FircEnable(const Mcu_FircConfigType *Config)
{
    uint32 RegVal = SCU_FIRC_CTRL_FIRC_EN_MASK;
    if (TRUE == Config->FircDeepSleepEnable)
    {
        RegVal |= SCU_FIRC_CTRL_FIRC_DS_EN_MASK;
    }
#if (MCU_FIRC_DELAY_SUPPORT == STD_ON)
    if (TRUE == Config->FircDelayEnable)
    {
        RegVal |= SCU_FIRC_CTRL_FIRC_DLY_EN_MASK;
    }
#endif
    MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_FIRC_CTRL_OFFSET32,
                             SCU_FIRC_CTRL_FIRC_DS_EN_MASK | SCU_FIRC_CTRL_FIRC_EN_MASK, RegVal);
}

/**
 * @brief Disable FIRC
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_FircDisable(void)
{
    MCU_REG_ADDR32_INDEX_CLEAR_BIT(SCU_BASE_ADDR32 + SCU_FIRC_CTRL_OFFSET32, SCU_FIRC_CTRL_FIRC_EN_SHIFT);
}

/**
 * @brief Disable FXOSC
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_FxoscDisable(void)
{
    MCU_REG_ADDR32_INDEX_CLEAR_BIT(SCU_BASE_ADDR32 + SCU_FXOSC_CTRL_OFFSET32, SCU_FXOSC_CTRL_FXOSC_EN_SHIFT);
}



#if (MCU_HAS_SXOSC == STD_ON)
/**
 * @brief Disable SXOSC
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SxoscDisable(void)
{
    MCU_REG_ADDR32_INDEX_CLEAR_BIT(SCU_BASE_ADDR32 + SCU_SXOSC_CTRL_OFFSET32, SCU_SXOSC_CTRL_SXOSC_EN_SHIFT);
}
#endif

/**
 * @brief Configures EFM Prescalers
 * @param[in] EfmPrescaleValue - Value to configure EFM Prescaler
 * @param[in] EfmWRSValue - Value to configure EFM WRS
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_EfmPrescaler(uint32 EfmPrescaleValue, uint32 EfmWRSValue)
{
    MCU_REG_ADDR32_AEARWRITE(EFM_BASE_ADDR32 + EFM_CTRL_OFFSET32,
                             EFM_CTRL_PRESCALER_MASK | EFM_CTRL_RWS_MASK,
                             EFM_CTRL_PRESCALER(EfmPrescaleValue) |
                             EFM_CTRL_RWS(EfmWRSValue));
}

/**
 * @brief Disables Clock Out feature
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_ClkOutDisable(void)
{
    MCU_REG_ADDR32_CLEAR_BITS(SCU_BASE_ADDR32 + SCU_CLKO_OFFSET32, SCU_CLKO_CLKOSEL_MASK);
}

/**
 * @brief Sets system clock source
 * @param[in] SystemClockSource - system clock source selection
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetSystemClockSource(Mcu_SystemClockSourceType SystemClockSource)
{
    /* Set clock source */
    MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_CLKS_OFFSET32,
                             SCU_CLKS_CLKSRCSEL_MASK,
                             SCU_CLKS_CLKSRCSEL(SystemClockSource));
}

/**
 * @brief Get System Clock Source
 * @return Mcu_SystemClockSourceType - System Clock Source
 */
MCU_FUNC LOCAL_INLINE uint32 Mcu_Lld_GetSystemClockStatus(void)
{
    /* Get clock source */
    return (MCU_REG_ADDR32_GET_BITS(SCU_BASE_ADDR32 + SCU_STS_OFFSET32, SCU_CLKS_CLKSRCSEL_MASK));
}

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief Disable Pll clock
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_PllDisable(void)
{
    /* Only clear EN bit will lead to some error in PLL test */
    MCU_REG_ADDR32_WRITE(SCU_BASE_ADDR32 + SCU_PLL_CTRL_OFFSET32, 0U);
}
#endif

/**
 * @brief Get core clock source type
 */
MCU_FUNC LOCAL_INLINE Mcu_SystemClockSourceType Mcu_Lld_GetCoreClockSource(void)
{
    uint32 Src = MCU_REG_ADDR32_GET_BITS(SCU_BASE_ADDR32 + SCU_STS_OFFSET32, SCU_STS_CLKST_MASK) >> SCU_STS_CLKST_SHIFT;
    return (Mcu_SystemClockSourceType)Src;
}

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief Get PLL divider value
 */
MCU_FUNC LOCAL_INLINE uint32 Mcu_Lld_GetPllFbDiv(void)
{
    return (MCU_REG_ADDR32_GET_BITS(SCU_BASE_ADDR32 + SCU_PLL_CTRL_OFFSET32, SCU_PLL_CTRL_FBDIV_MASK) >> SCU_PLL_CTRL_FBDIV_SHIFT) + 1U;
}
#endif
/**
 * @brief Set up Clock Divider Register. Configures core, fast bus and slow bus clock dividers.
 * @param[in] CoreClockDiv - Value of core clock divider
 * @param[in] FastBusClockDiv - Value of fast bus clock divider
 * @param[in] SlowBusClockDiv - Value of slow bus clock divider
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetClockDivider(uint32 CoreClockDiv, uint32 FastBusClockDiv, uint32 SlowBusClockDiv)
{
    MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_DIV_OFFSET32,
                             SCU_DIV_CPDIVS_MASK | SCU_DIV_FBDIVS_MASK | SCU_DIV_SBDIVS_MASK,
                             SCU_DIV_CPDIVS(CoreClockDiv) |
                             SCU_DIV_FBDIVS(FastBusClockDiv) |
                             SCU_DIV_SBDIVS(SlowBusClockDiv));
}

/**
 * @brief   Get Clock Divider Status Register
 */
MCU_FUNC LOCAL_INLINE uint32 Mcu_Lld_GetDividerStatus(void)
{
    return (MCU_REG_ADDR32_READ(SCU_BASE_ADDR32 + SCU_DIVSTS_OFFSET32));
}

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief get PLL reference clock source
 */
MCU_FUNC LOCAL_INLINE Mcu_PllClockRefType Mcu_Lld_GetPllRef(void)
{
    uint32 Ref = MCU_REG_ADDR32_INDEX_GET_BIT(SCU_BASE_ADDR32 + SCU_PLL_CTRL_OFFSET32, SCU_PLL_CTRL_REFCLKSRCSEL_SHIFT);
    return (Mcu_PllClockRefType)Ref;
}

/**
 * @brief get PLL reference clock divider
 */
MCU_FUNC LOCAL_INLINE uint32 Mcu_Lld_GetPllRefDiv(void)
{
    return (MCU_REG_ADDR32_GET_BITS(SCU_BASE_ADDR32 + SCU_PLL_CTRL_OFFSET32, SCU_PLL_CTRL_REFDIV_MASK) >> SCU_PLL_CTRL_REFDIV_SHIFT) + 1U;
}
#endif

/**
 * @brief Get Core Clock Divider
 * @return uint32 - Core Clock Divider
 */
MCU_FUNC LOCAL_INLINE uint32 Mcu_Lld_GetCoreDiv(void)
{
    return (MCU_REG_ADDR32_GET_BITS(SCU_BASE_ADDR32 + SCU_DIV_OFFSET32, SCU_DIV_CPDIVS_MASK) >> SCU_DIV_CPDIVS_SHIFT) + 1U;
}

/**
 * @brief Sets the configuration for the External High-Speed Oscillator (FXOSC).
 * This function sets the mode, bypass, gain selection, and compensation status for
 * the FXOSC through setting the relevant bits in the SCU_FXOSC_CTRL_OFFSET32 register.
 * If ConfigPtr is NULL_PTR, then this function does nothing.
 * @param[in] ConfigPtr Pointer to the struct containing the configurations of the FXOSC.
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetFxoscClock(const Mcu_FxoscConfigType *ConfigPtr)
{
    uint32 ByPassMode;
    uint32 NotBypassMode;
    if (NULL_PTR != ConfigPtr)
    {
        if(TRUE == ConfigPtr->BypassMode)
        {
            ByPassMode = 1;
            NotBypassMode = 0;
        }
        else
        {
            ByPassMode = 0;
            NotBypassMode = 1;
        }
#if defined(CPU_YTM32B1MC0)
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_FXOSC_CTRL_OFFSET32,
                                 SCU_FXOSC_CTRL_FXOSC_MODE_MASK |
                                 SCU_FXOSC_CTRL_GMSEL_MASK |
                                 SCU_FXOSC_CTRL_ALCDIS_MASK |
                                 SCU_FXOSC_CTRL_DLY_SEL_MASK,
                                 SCU_FXOSC_CTRL_FXOSC_MODE(NotBypassMode) |
                                 SCU_FXOSC_CTRL_GMSEL(ConfigPtr->GainSelection) |
                                 SCU_FXOSC_CTRL_ALCDIS(ByPassMode) |
                                 SCU_FXOSC_CTRL_DLY_SEL((uint32)ConfigPtr->DelaySelect));
#else
        /* FXOSC control */
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_FXOSC_CTRL_OFFSET32,
                                 SCU_FXOSC_CTRL_FXOSC_MODE_MASK |
                                 SCU_FXOSC_CTRL_HYSTDIS_MASK |
                                 SCU_FXOSC_CTRL_GMSEL_MASK |
                                 SCU_FXOSC_CTRL_ALCDIS_MASK |
                                 SCU_FXOSC_CTRL_COMPEN_MASK,
                                 SCU_FXOSC_CTRL_FXOSC_MODE(NotBypassMode) |
                                 SCU_FXOSC_CTRL_HYSTDIS(ByPassMode) |
                                 SCU_FXOSC_CTRL_GMSEL(ConfigPtr->GainSelection) |
                                 SCU_FXOSC_CTRL_ALCDIS(ByPassMode) |
                                 SCU_FXOSC_CTRL_COMPEN(NotBypassMode));
#endif
        MCU_REG_ADDR32_INDEX_SET_BIT(SCU_BASE_ADDR32 + SCU_FXOSC_CTRL_OFFSET32, SCU_FXOSC_CTRL_FXOSC_EN_SHIFT);
    }
}

MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetFxoscGain(uint8 Gain)
{
    MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_FXOSC_CTRL_OFFSET32, SCU_FXOSC_CTRL_GMSEL_MASK,
        SCU_FXOSC_CTRL_GMSEL(Gain));
}

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief Initializes PLL with given configuration parameter.
 *
 * This function is used to initialize the PLL module of Microcontroller Unit with specific configuration
 * parameters. It configures reference clock source selection, feedback clock divider and reference
 * clock divider for PLL. It also enables the PLL module after configuration.
 *
 * @param[in] ConfigPtr: Pointer to a structure containing initialization data for PLL.
 *
 * @return void.
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetPll(const Mcu_PllConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        /* Configure PLL control registers */
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_PLL_CTRL_OFFSET32,
                                 SCU_PLL_CTRL_REFCLKSRCSEL_MASK |
                                 SCU_PLL_CTRL_FBDIV_MASK |
                                 SCU_PLL_CTRL_REFDIV_MASK,
                                 SCU_PLL_CTRL_REFCLKSRCSEL(ConfigPtr->ClockRef) |
                                 SCU_PLL_CTRL_FBDIV(ConfigPtr->FeedbackDiv) |
                                 SCU_PLL_CTRL_REFDIV(ConfigPtr->RefDiv));
#if (MCU_PLL_ADVANCED_MODE_SUPPORT == STD_ON)
        /* Configure PLL CFG register */
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_PLL_CFG_OFFSET32,
                                 SCU_PLL_CFG_DITHER_EN_MASK |
                                 SCU_PLL_CFG_DITHER_GAIN_MASK |
                                 SCU_PLL_CFG_FM_EN_MASK |
                                 SCU_PLL_CFG_FD_EN_MASK,
                                 SCU_PLL_CFG_DITHER_EN(ConfigPtr->PLLDitherEnable) |
                                 SCU_PLL_CFG_DITHER_GAIN(ConfigPtr->PLLDitherGain) |
                                 SCU_PLL_CFG_FM_EN(ConfigPtr->PLLFMModeEnable) |
                                 SCU_PLL_CFG_FD_EN(ConfigPtr->PLLFracModeEnable));
        /* Configure PLL FM register */
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_PLL_FM_OFFSET32,
                                 SCU_PLL_FM_FM_STEP_MASK | SCU_PLL_FM_FM_NO_MASK,
                                 SCU_PLL_FM_FM_STEP(ConfigPtr->PLLFMStepSize) | SCU_PLL_FM_FM_NO(ConfigPtr->PLLFMStepNum));
        /* Configure PLL FD register */
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_PLL_FD_OFFSET32, SCU_PLL_FD_FD_FRAC_MASK, SCU_PLL_FD_FD_FRAC(ConfigPtr->PLLFracLoopDivFactor));
#endif
        /* Enable PLL */
        MCU_REG_ADDR32_INDEX_SET_BIT(SCU_BASE_ADDR32 + SCU_PLL_CTRL_OFFSET32, SCU_PLL_CTRL_PLL_EN_SHIFT);
    }
}
#endif

#if (MCU_HAS_SXOSC == STD_ON)
/**
 * @brief This function sets the Sxosc Clock Configuration
 * @param[in] ConfigPtr A pointer to a structure containing the Sxosc configuration parameters
 * @return void
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetSxoscClock(const Mcu_SxoscConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        /* FXOSC control */
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_SXOSC_CTRL_OFFSET32,
                                 SCU_SXOSC_CTRL_SXOSC_MODE_MASK |
                                 SCU_SXOSC_CTRL_GMSEL_MASK |
                                 SCU_SXOSC_CTRL_SXOSC_PD_EN_MASK |
                                 SCU_SXOSC_CTRL_SXOSC_DS_EN_MASK |
                                 SCU_SXOSC_CTRL_SXOSC_STB_EN_MASK,
                                 SCU_SXOSC_CTRL_SXOSC_MODE(ConfigPtr->BypassMode) |
                                 SCU_FXOSC_CTRL_GMSEL(ConfigPtr->GainSelection) |
                                 SCU_SXOSC_CTRL_SXOSC_PD_EN(ConfigPtr->PowerDownEnable) |
                                 SCU_SXOSC_CTRL_SXOSC_DS_EN(ConfigPtr->DeepSleepEnable) |
                                 SCU_SXOSC_CTRL_SXOSC_STB_EN(ConfigPtr->StandbyEnable));

        /* Enable SXOSC */
        MCU_REG_ADDR32_INDEX_SET_BIT(SCU_BASE_ADDR32 + SCU_SXOSC_CTRL_OFFSET32, SCU_SXOSC_CTRL_SXOSC_EN_SHIFT);

    }
}
#endif

/**
 * @brief Configures the clock output (CLKOUT) module with the provided configuration.
 * @param[in] ConfigPtr Pointer to a Mcu_ClockOutConfigType structure containing the configuration information for CLKOUT.
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetClockOut(const Mcu_ClockOutConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_CLKO_OFFSET32,
                                 SCU_CLKO_CLKODIV_MASK |
                                 SCU_CLKO_CLKOSEL_MASK,
                                 SCU_CLKO_CLKODIV(ConfigPtr->ClockOutDiv) |
                                 SCU_CLKO_CLKOSEL(ConfigPtr->Source));
    }
}

/**
 * @brief Sets the Configuration of Clock Monitor Unit(CMU) based on the user passed Configurations.
 * This function sets the CMU Configuration for each channel as per the user configuration in the input Mcu_ClockMonitorConfigType pointer.
 * @param[in] ConfigPtr Pointer to a structure containing user configurations.
 * @return void
 */
MCU_FUNC LOCAL_INLINE void Mcu_Lld_SetCmu(const Mcu_ClockMonitorConfigType* ConfigPtr, const uint8 Len)
{
    Mcu_ClockMonitorConfigType const *CmuConfigPtr = NULL_PTR;
    uint32 CmuCtrlRegVal = 0;
    if ((ConfigPtr != NULL_PTR) && (Len <= MCU_CMU_CHANNEL_NUMS))
    {
        CmuConfigPtr = ConfigPtr;
        for (uint8 Idx = 0U; Idx < Len; ++Idx)
        {
            /* Enable */
            MCU_REG_ADDR32_SET_BITS(&CmuCtrlRegVal, (uint32)(CmuConfigPtr->Enable) << CmuConfigPtr->CmuChannelIdx);

            /* Enable or Disable CMU reset enable */
            MCU_REG_ADDR32_SET_BITS(&CmuCtrlRegVal, (uint32)(CmuConfigPtr->ResetEnable) << (CmuConfigPtr->CmuChannelIdx + 8U));

#if (MCU_CMU_REFERENCE_CHANGEABLE == STD_ON)
            /* Set CMU clock reference */
            if (MCU_CMU_CLOCK_REFERENCE_FXOSC == CmuConfigPtr->ClockReference)
            {
                MCU_REG_ADDR32_SET_BITS(&CmuCtrlRegVal, ((uint32)1U << (CmuConfigPtr->CmuChannelIdx + 16U)));
            }
#endif
            /* Set CMUxCMPH */
            MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_CMUCMP_HIGH_OFFSET32((uint32)CmuConfigPtr->CmuChannelIdx),
                                    SCU_CMUCMP_HIGH_VAL_MASK,
                                    SCU_CMUCMP_HIGH_VAL(CmuConfigPtr->CmuCmpHValue));

            /* Set CMUxCMPH */
            MCU_REG_ADDR32_AEARWRITE(SCU_BASE_ADDR32 + SCU_CMUCMP_LOW_OFFSET32((uint32)CmuConfigPtr->CmuChannelIdx),
                                    SCU_CMUCMP_LOW_VAL_MASK,
                                    SCU_CMUCMP_LOW_VAL(CmuConfigPtr->CmuCmpLValue));
#if (MCU_LLD_SCU_ISR_USED == STD_ON)
            /* Store the interrpt enable flags */
            Mcu_CmuIntEnableList[CmuConfigPtr->CmuChannelIdx] = CmuConfigPtr->CmuIntEnable;

            /* Store the notification */
            Mcu_CmuNotiList[CmuConfigPtr->CmuChannelIdx] = CmuConfigPtr->NotificationPtr;
#endif
            /* Set next CMU channel */
            ++CmuConfigPtr;
        }
#if (MCU_LLD_SCU_ISR_USED == STD_ON)
        /* Use this function to get raw reset value */
        (void)Mcu_Lld_GetResetValue();

        /* Verify if the chip has been reset by CMU and decide whether to trigger a notification */
        if (0U != (Mcu_ResetStatusValue & RCU_RSSR_CMU_MASK))
        {
            Mcu_Lld_Cmu_ChannelIrqProcess();
        }
#endif
        /* Start CMU */
        MCU_REG_ADDR32_WRITE(SCU_BASE_ADDR32 + SCU_CMU_CTRL_OFFSET32, CmuCtrlRegVal);
    }
}

/**
 * @brief Get relative clock valid flag in SCU STS register
 * @param[in] ClockMask relative clock mask, which is specified by chip
 * @return uint32 - raw clock valid flag
 */
MCU_FUNC LOCAL_INLINE uint32 Mcu_Lld_GetClockStatus(uint32 ClockMask)
{
    /* Set clock source */
    return MCU_REG_ADDR32_GET_BITS(SCU_BASE_ADDR32 + SCU_STS_OFFSET32, ClockMask);
}

/**
 * @brief Initializes the SIRC clock using the provided ConfigPtr.
 *
 * @param[in] ConfigPtr Pointer to the configuration of type Mcu_ClockConfigType.
 * @return Std_ReturnType
 *         - E_OK: FIRC initialization successful.
 *         - E_NOT_OK: FIRC could not be validated in time.
 */
MCU_FUNC LOCAL_INLINE Std_ReturnType Mcu_Lld_InitSirc(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType Res = E_OK;
    if (TRUE == ConfigPtr->SircUnderUserCtrl)
    {
        uint32 RegCtrl = 0U;
        if (TRUE == ConfigPtr->SircConfig->SircDeepSleepEnable)
        {
            RegCtrl |= SCU_SIRC_CTRL_SIRC_DS_EN_MASK;
        }
#if (MCU_POWERDOWN_MODE_SUPPORT == STD_ON)
        if (TRUE == ConfigPtr->SircConfig->SircPowerDownEnable)
        {
            RegCtrl |= SCU_SIRC_CTRL_SIRC_PD_EN_MASK;
        }
#endif
        if (TRUE == ConfigPtr->SircConfig->SircStandbyEnable)
        {
            RegCtrl |= SCU_SIRC_CTRL_SIRC_STB_EN_MASK;
        }
        MCU_REG_ADDR32_WRITE(SCU_BASE_ADDR32 + SCU_SIRC_CTRL_OFFSET32, RegCtrl);
    }
    return Res;
}

/**
 * @brief Initializes the FIRC clock using the provided ConfigPtr.
 *
 * @param[in] ConfigPtr Pointer to the configuration of type Mcu_ClockConfigType.
 * @return Std_ReturnType
 *         - E_OK: FIRC initialization successful.
 *         - E_NOT_OK: FIRC could not be validated in time.
 * @note `Mcu_Lld_InitFirc()` operation requires FircUnderUserCtrl.
 */
MCU_FUNC LOCAL_INLINE Std_ReturnType Mcu_Lld_InitFirc(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType Res = E_OK;
    if (TRUE == ConfigPtr->FircUnderUserCtrl)
    {
        if (TRUE == ConfigPtr->FircEnable)
        {
            uint32 TimeOutTempCnt = 0U;
            uint32 RegVal = 0U;
            Mcu_Lld_FircEnable(ConfigPtr->FircConfig);
            RegVal = Mcu_Lld_GetClockStatus(SCU_STS_FIRC_VALID_MASK);
            while ((RegVal != SCU_STS_FIRC_VALID_MASK) && (TimeOutTempCnt < MCU_CLOCK_TIMEOUT_COUNT))
            {
                RegVal = Mcu_Lld_GetClockStatus(SCU_STS_FIRC_VALID_MASK);
                ++TimeOutTempCnt;
            }
            if (TimeOutTempCnt >= MCU_CLOCK_TIMEOUT_COUNT)
            {
                Res = E_NOT_OK;
            }
        }
        else
        {
            Mcu_Lld_FircDisable();
        }
    }
    return Res;
}

#if (MCU_HAS_SXOSC == STD_ON)
/**
 * @brief Initializes the SXOSC clock using the provided ConfigPtr
 *
 * @param[in] ConfigPtr Pointer to the configuration of type Mcu_ClockConfigType.
 * @return Std_ReturnType
 *         - E_OK: Sxosc initialization successful.
 *         - E_NOT_OK: Sxosc could not be validated in time.
 * @note `Mcu_Lld_InitSxosc()` operation requires SxoscUnderUserCtrl.
 */
MCU_FUNC LOCAL_INLINE Std_ReturnType Mcu_Lld_InitSxosc(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType Res = E_OK;
    if (TRUE == ConfigPtr->SxoscUnderUserCtrl)
    {
        if (TRUE == ConfigPtr->SxoscEnable)
        {
            /* Sxosc startup is too slow, Dont wait for it in the driver */
            Mcu_Lld_SetSxoscClock(ConfigPtr->SxoscConfig);
#if (MCU_WAIT_SXOSC_STABLE == STD_ON)
            uint32 RegVal;
            uint32 TimeOutTempCnt = 0;
            RegVal = Mcu_Lld_GetClockStatus(SCU_STS_SXOSC_VALID_MASK);
            while ((RegVal != SCU_STS_SXOSC_VALID_MASK) && (TimeOutTempCnt < MCU_CLOCK_TIMEOUT_COUNT))
            {
                RegVal = Mcu_Lld_GetClockStatus(SCU_STS_SXOSC_VALID_MASK);
                ++TimeOutTempCnt;
            }
            if (TimeOutTempCnt >= MCU_CLOCK_TIMEOUT_COUNT)
            {
                Res = E_NOT_OK;
            }
#endif
        }
        else
        {
            Mcu_Lld_SxoscDisable();
        }
    }
    return Res;
}
#endif

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief Initializes the PLL clock using the provided ConfigPtr.
 *
 * @param[in] ConfigPtr Pointer to the configuration of type Mcu_ClockConfigType.
 * @return Std_ReturnType
 *         - E_OK: PLL initialization successful.
 *         - E_NOT_OK: PLL could not be validated in time.
 * @note
 * - `Mcu_Lld_InitPll()` operation requires PllUnderUserCtrl.
 * - PLL needs a reference clock to lock, please confirm the reference clock is valid.
 */
MCU_FUNC LOCAL_INLINE Std_ReturnType Mcu_Lld_InitPll(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType Res = E_OK;
    if (TRUE == ConfigPtr->PllUnderUserCtrl)
    {
        /* SetPll need the Pll EN flag is false, and check the flag. Too fast to run enable the PLL will made error */
        Mcu_Lld_PllDisable();
        if (TRUE == ConfigPtr->PllEnable)
        {
            /* Pll startup too slow, don't wait for it lock */
            Mcu_Lld_SetPll(ConfigPtr->PllConfig);
        }
    }
    return Res;
}
#endif
/**
 * @brief Initializes the Fxosc clock.
 *
 * @details The Fxosc can be used as the CMU reference clock. Therefore, it is necessary to ensure
 *          that the Fxosc is valid for the CMU channel.
 *
 * @param[in] ConfigPtr Pointer to the configuration of type Mcu_ClockConfigType.
 * @return Std_ReturnType
 *         - E_OK: Fxosc initialization successful.
 *         - E_NOT_OK: Fxosc could not be validated in time.
 */
MCU_FUNC LOCAL_INLINE Std_ReturnType Mcu_Lld_InitFxosc(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType Res = E_OK;
    if (TRUE == ConfigPtr->FxoscUnderUserCtrl)
    {
        if (TRUE == ConfigPtr->FxoscEnable)
        {
            uint32 TimeOutTempCnt = 0U;
            uint32 RegVal = 0U;
            uint8 TempGain = 1;
            uint8 MaxGain = (SCU_FXOSC_CTRL_GMSEL_MASK >> SCU_FXOSC_CTRL_GMSEL_SHIFT);
            sint8 GainStep = 1;
            Mcu_Lld_SetFxoscClock(ConfigPtr->FxoscConfig);
            RegVal = Mcu_Lld_GetClockStatus(SCU_STS_FXOSC_VALID_MASK);
            while ((RegVal != SCU_STS_FXOSC_VALID_MASK) && (TimeOutTempCnt < MCU_CLOCK_TIMEOUT_COUNT))
            {
                RegVal = Mcu_Lld_GetClockStatus(SCU_STS_FXOSC_VALID_MASK);
                Mcu_Lld_SetFxoscGain(TempGain);
                /**
                 * @note FXOSC may failed to start when OSC not match to MCU gain setting, to get a
                 *       more stable FXOSC startup, software should sweep FXOSC gain setting when 
                 *       start FXOSC, when FXOSC ready, software set gain back to user setting.
                 * 
                 */
                TempGain += GainStep;
                if (TempGain == 1)
                {
                    GainStep = 1;
                }
                else if (TempGain == MaxGain)
                {
                    GainStep = -1;
                }
                ++TimeOutTempCnt;
            }
            if (TimeOutTempCnt >= MCU_CLOCK_TIMEOUT_COUNT)
            {
                Res = E_NOT_OK;
            }
            Mcu_Lld_SetFxoscGain(ConfigPtr->FxoscConfig->GainSelection);
        }
        else
        {
            Mcu_Lld_FxoscDisable();
        }
    }
    return Res;
}

/**
 * @brief Initializes the divider of system clock.
 *
 * @details The `Mcu_Lld_InitClockDivider()` function will set the system clock use ConfigPtr.
 *
 * @param[in] ConfigPtr Pointer to the configuration of type Mcu_ClockConfigType.
 * @return Std_ReturnType
 *         - E_OK: Clock divider initialization successful.
 *         - E_NOT_OK: Clock divider could not be validated in time.
 */
MCU_FUNC LOCAL_INLINE Std_ReturnType Mcu_Lld_InitClockDivider(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType Res = E_OK;
    uint32 TimeOutTempCnt = 0U;
    uint32 RegVal = 0U;
    Mcu_Lld_SetClockDivider(ConfigPtr->CoreClockDiv, ConfigPtr->FastBusClockDiv, ConfigPtr->SlowBusClockDiv);
    RegVal = Mcu_Lld_GetDividerStatus();
    while ((RegVal != (SCU_DIVSTS_CPDIVST(ConfigPtr->CoreClockDiv) |
                       SCU_DIVSTS_FBDIVST(ConfigPtr->FastBusClockDiv) |
                       SCU_DIVSTS_SBDIVST(ConfigPtr->SlowBusClockDiv))) && (TimeOutTempCnt < MCU_CLOCK_TIMEOUT_COUNT))
    {
        RegVal = Mcu_Lld_GetDividerStatus();
        ++TimeOutTempCnt;
    }
    if (TimeOutTempCnt >= MCU_CLOCK_TIMEOUT_COUNT)
    {
        Res = E_NOT_OK;
    }
    return Res;
}

/**
 * @brief Initializes the system clock.
 *
 * @details The function `Mcu_Lld_SwitchSystemClock()` sets the system clock to the
 *          specified clock. After the set operation, the function waits for SCU.STS
 *          register to validate whether the operation was successful.
 *
 * @param[in] SystemClockSource Specified clock name.
 * @return Std_ReturnType
 *         - E_OK: System clock initialization successful.
 *         - E_NOT_OK: System clock could not be validated in time.
 */
MCU_FUNC LOCAL_INLINE Std_ReturnType Mcu_Lld_SwitchSystemClock(Mcu_SystemClockSourceType SystemClockSource)
{
    Std_ReturnType Res = E_OK;
    uint32 TimeOutTempCnt = 0U;
    uint32 TargetSystemClock = (uint32)SystemClockSource;
    Mcu_Lld_SetSystemClockSource(SystemClockSource);
    uint32 CurSystemClock = Mcu_Lld_GetSystemClockStatus() >> SCU_CLKS_CLKSRCSEL_SHIFT;
    while ((CurSystemClock != TargetSystemClock) && (TimeOutTempCnt < MCU_CLOCK_TIMEOUT_COUNT))
    {
        CurSystemClock = (Mcu_Lld_GetSystemClockStatus() >> SCU_CLKS_CLKSRCSEL_SHIFT);
        ++TimeOutTempCnt;
    }
    if (TimeOutTempCnt >= MCU_CLOCK_TIMEOUT_COUNT)
    {
        Res = E_NOT_OK;
    }
    return Res;
}

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
#if (MCU_NO_PLL == STD_OFF)
MCU_FUNC void Mcu_Lld_SetCmuChannel2(void)
{
    MCU_REG_ADDR32_SET_BITS(SCU_BASE_ADDR32 + SCU_CMU_CTRL_OFFSET32, SCU_CMU_CTRL_CMU2_EN_MASK);
}
#endif

#if (MCU_NO_PLL == STD_OFF)
MCU_FUNC Mcu_PllStatusType Mcu_Lld_GetPllStatus(void)
{
    uint32 RegVal = 0;
    Mcu_PllStatusType PllStatus;
    /* Get PLL lock Status */
    RegVal = MCU_REG_ADDR32_INDEX_GET_BIT(SCU_BASE_ADDR32 + SCU_STS_OFFSET32, SCU_STS_PLL_LOCK_SHIFT);
    if (RegVal > 0U)
    {
        PllStatus = MCU_PLL_LOCKED;
    }
    else
    {
        PllStatus = MCU_PLL_UNLOCKED;
    }
    return PllStatus;
}
#endif

#if (MCU_GET_SXOSC_STATU_API == STD_ON)
Mcu_SxoscStatusType Mcu_Lld_GetSxoscStatus(void)
{
    uint32 RegVal = Mcu_Lld_GetClockStatus(SCU_STS_SXOSC_VALID_MASK);
    Mcu_SxoscStatusType SxoscStatus = MCU_SXOSC_INVALID;
    if (RegVal > 0U)
    {
        SxoscStatus = MCU_SXOSC_VALID;
    }
    else
    {
        SxoscStatus = MCU_SXOSC_INVALID;
    }
    return SxoscStatus;
}
#endif

/**
 * GCOVR_EXCL_START: The 'Mcu_Lld_SystemReset' function performs a chip reset, preventing testing
 * in integration tests.
 */
/**
 * MR12 DIR 4.3 VIOLATION: The function 'Mcu_Lld_SystemReset' contains a mixture of in-line
 * assembler statements and C statements. In this specific case, due to the need for low-level
 * hardware access or specific performance requirements, we had to use inline assembly code
 * alongside C statements, thus we couldn't adhere to this rule.
 */
MCU_FUNC void Mcu_Lld_SystemReset(void) /* PRQA S 3006 */
{
    uint32 AircrValue;
    /** asm("dsb"); */
    /* Read Application Interrupt and Reset Control Register */
    AircrValue = SCB->AIRCR;

    /* Clear register key */
    AircrValue &= ~SCB_AIRCR_VECTKEY_Msk;
    /* Configure System reset request bit and Register Key */
    AircrValue |= (uint32)0x05FAU << SCB_AIRCR_VECTKEY_Pos;
    AircrValue |= SCB_AIRCR_SYSRESETREQ_Msk;

    /* Write back to Application Interrupt and Reset Control Register */
    SCB->AIRCR = AircrValue;
    /**
     * MR12 RULE 1.2 VIOLATION: This line uses the __ASM() macro for inline assembly which is not
     * a part of standard C. In this specific case, we are executing a 'dsb' instruction for ensuring
     * all previous instructions have been completed before continuing, hence we couldn't adhere to
     * the rule 1.2
     */
    __ASM("dsb"); /* PRQA S 1006 */
}
/* GCOVR_EXCL_STOP */

MCU_FUNC void Mcu_Lld_SetRcu(const Mcu_ResetConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        MCU_REG_ADDR32_AEARWRITE(RCU_BASE_ADDR32 + RCU_RPFR_OFFSET32,
                                 RCU_RPFR_FLTEN_MASK | RCU_RPFR_RSTPIN_OBEN_MASK | RCU_RPFR_FLTVAL_MASK,
                                 RCU_RPFR_FLTEN(ConfigPtr->HwResetPinFilterEnable) |
                                 RCU_RPFR_RSTPIN_OBEN(ConfigPtr->HwResetPinOutputEnable) |
                                 RCU_RPFR_FLTVAL(ConfigPtr->HwResetPinFilterCount));
    }
}

/**
 * GCOVR_EXCL_START: The 'Mcu_Lld_SetRamSection' function is designed to clear the RAM section data to the default values
 * configured by the PB file. Due to the potential risk of unintentionally erasing critical data, this function is excluded
 * from coverage testing to prevent inadvertent impacts during the testing process.
 */
MCU_FUNC void Mcu_Lld_SetRamSection(const Mcu_RamSectionConfigType *ConfigPtr)
{
    uint32 RamSectionAddress = 0;
    if (NULL_PTR != ConfigPtr)
    {
        /**
         * MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type.
         * In this specific case, we need to obtain the integer value of the base address, thus, we
         * couldn't adhere to M3CM Rule-11.4
         */
        RamSectionAddress = (uint32)(ConfigPtr->BaseAddress); /* PRQA S 0306 */
        for (uint32 AddressOffset = 0U; AddressOffset < ConfigPtr->SectionSize; ++AddressOffset)
        {
            MCU_REG_ADDR32_WRITE(RamSectionAddress + AddressOffset, ConfigPtr->DefaultValue);
        }
    }
}
/* GCOVR_EXCL_STOP */

/**
 * GCOVR_EXCL_START: The function 'Mcu_Lld_SetMode' modifies the chip's operating mode. In coverage testing,
 * ensuring the normal operation of the chip's testing framework after changing the operating mode is crucial.
 * Therefore, this function has been excluded from coverage testing.
 */
/**
 * MR12 DIR 4.3 VIOLATION: The function 'Mcu_Lld_SetMode' contains a mixture of in-line assembler statements
 * and C statements. In this specific case, due to the need for low-level hardware access or specific
 * performance requirements, we had to use inline assembly code alongside C statements, thus we couldn't
 * adhere to this rule.
 */
MCU_FUNC void Mcu_Lld_SetMode(Mcu_PowerModeType McuMode) /* PRQA S 3006 */
{
    /* Clear Efm DeepSleep Mode Enable */
#if defined(CPU_YTM32B1MC0)
    MCU_REG_ADDR32_INDEX_CLEAR_BIT(EFM_BASE_ADDR32 + EFM_CTRL_OFFSET32, EFM_CTRL_LPEN_SHIFT);
#else
    MCU_REG_ADDR32_INDEX_CLEAR_BIT(EFM_BASE_ADDR32 + EFM_CTRL_OFFSET32, EFM_CTRL_DPD_EN_SHIFT);
#endif
    if (MCU_POWER_MODE_RUN == McuMode)
    {
        SCB->SCR &= ~(SCB_SCR_SLEEPONEXIT_Msk);
    }
    else
    {
        uint32 TempSystick;
        Mcu_Lld_DisableAllCmu();
        /* Switch to the set mode */
        switch (McuMode)
        {
#if defined(CPU_YTM32B1MC0)
        case MCU_POWER_MODE_SLEEP:
            SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
            break;
        case MCU_POWER_MODE_DEEPSLEEP:
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            MCU_REG_ADDR32_CLEAR_BITS(PCU_BASE_ADDR32 + PCU_CSR_OFFSET32, PCU_CSR_PMCLPEN_MASK);
            break;
        case MCU_POWER_MODE_STANDBY:
            MCU_REG_ADDR32_SET_BITS(EFM_BASE_ADDR32 + EFM_CTRL_OFFSET32, EFM_CTRL_LPEN_MASK);
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            MCU_REG_ADDR32_SET_BITS(PCU_BASE_ADDR32 + PCU_CSR_OFFSET32, PCU_CSR_PMCLPEN_MASK);
            break;
#else
        case MCU_POWER_MODE_SLEEP:
            SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
            break;
        case MCU_POWER_MODE_DEEPSLEEP:
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            MCU_REG_ADDR32_INDEX_SET_BIT(EFM_BASE_ADDR32 + EFM_CTRL_OFFSET32, EFM_CTRL_DPD_EN_SHIFT);
            MCU_REG_ADDR32_CLEAR_BITS(PCU_BASE_ADDR32 + PCU_CTRL_OFFSET32, PCU_CTRL_RPMEN_MASK | PCU_CTRL_STANDBYEN_MASK);
            break;
        case MCU_POWER_MODE_POWERDOWN:
            MCU_REG_ADDR32_INDEX_SET_BIT(EFM_BASE_ADDR32 + EFM_CTRL_OFFSET32, EFM_CTRL_DPD_EN_SHIFT);
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            MCU_REG_ADDR32_CLEAR_BITS(PCU_BASE_ADDR32 + PCU_CTRL_OFFSET32, PCU_CTRL_STANDBYEN_MASK);
            MCU_REG_ADDR32_SET_BITS(PCU_BASE_ADDR32 + PCU_CTRL_OFFSET32, PCU_CTRL_RPMEN_MASK);
            break;
        case MCU_POWER_MODE_STANDBY:
            MCU_REG_ADDR32_INDEX_SET_BIT(EFM_BASE_ADDR32 + EFM_CTRL_OFFSET32, EFM_CTRL_DPD_EN_SHIFT);
            SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
            MCU_REG_ADDR32_SET_BITS(PCU_BASE_ADDR32 + PCU_CTRL_OFFSET32, PCU_CTRL_RPMEN_MASK | PCU_CTRL_STANDBYEN_MASK);
            break;
#endif
        default:
            /* Nothing to do */
            break;
        }
        /* Disable systick, store current CMU Ctrl register value to temp value */
        TempSystick = SysTick->CTRL;
        SysTick->CTRL = 0x00;
        /* When interrupt happen, exit low power mode to run mode: */
        SCB->SCR &= ~(SCB_SCR_SLEEPONEXIT_Msk);
        /**
         * MR12 RULE 1.2 VIOLATION: This line uses the __ASM() macro for inline assembly which is not a part of standard C.
         * In this specific case, we are executing a 'wfi' instruction to put the processor into low power state or sleep
         * mode until the next interrupt is fired, hence we couldn't adhere to the rule 1.2
         */
        __ASM("wfi\n");/* PRQA S 1006 */

        /* Restore systick */
        SysTick->CTRL = TempSystick;

        /* Clear the DEEPSLEEP flag */
        SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);

        /**
         * NOTE:
         * After the `Mcu_Lld_SetMode()` function returns, the enabled clocks become effective. Due to the inclusion of multiple
         * clocks, the setting is not performed in the `Mcu_Lld_SetMode()` function. Instead, users need to re-invoke
         * `Mcu_InitClock()` for clock initialization.
         */
    }
}
/* GCOVR_EXCL_STOP */

MCU_FUNC Std_ReturnType Mcu_Lld_SetClockSource(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    ReturnValue = Mcu_Lld_SwitchSystemClock(ConfigPtr->SystemClockSource);
    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        /* Set CMU */
        Mcu_Lld_SetCmu(ConfigPtr->ClockMonitorConfig, ConfigPtr->ClockMonitorConfigNums);

        /* Init Clock output */
        /* Disable Clock output */
        Mcu_Lld_ClkOutDisable();

        if (TRUE == ConfigPtr->ClockOutEnable)
        {
            Mcu_Lld_SetClockOut(ConfigPtr->ClockOutConfig);
        }
    }
    return ReturnValue;
}

/* PRQA S 1505 */
MCU_FUNC void Mcu_Lld_SetPeripheralClock(const Mcu_PeripheralClockConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        Mcu_IpcConfigType const *IpcConfigPtr = ConfigPtr->IpcConfig;
        if (NULL_PTR != IpcConfigPtr)
        {
            for (uint8 IpcIndex = 0U; IpcIndex < ConfigPtr->IpcCount; ++IpcIndex)
            {
                /* Disable the peripheral clock */
                MCU_REG_ADDR32_INDEX_CLEAR_BIT(IPC_BASE_ADDR32 + IPC_CTRL_OFFSET32((uint32)IpcConfigPtr->PeripheralIndex), IPC_CTRL_CLKEN_SHIFT);
                /* Set peripheral clock config and enable the peripheral clock */
                MCU_REG_ADDR32_AEARWRITE(IPC_BASE_ADDR32 + IPC_CTRL_OFFSET32((uint32)IpcConfigPtr->PeripheralIndex),
                                         IPC_CTRL_SRCSEL_MASK | IPC_CTRL_DIV_MASK | IPC_CTRL_CLKEN_MASK,
                                         IPC_CTRL_SRCSEL(IpcConfigPtr->ClockSource) |
                                         IPC_CTRL_DIV(IpcConfigPtr->ClockDiv) |
                                         IPC_CTRL_CLKEN(IpcConfigPtr->ClockEnable));
                ++IpcConfigPtr;
            }
        }
    }
}

MCU_FUNC Std_ReturnType Mcu_Lld_InitClock(const Mcu_ClockConfigType *ConfigPtr)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    if (NULL_PTR != ConfigPtr)
    {
        Mcu_Lld_DisableAllCmu();
        /* Set the system clock to SIRC and ensure that the following functions run correctly */
        ReturnValue = Mcu_Lld_SwitchSystemClock(MCU_SYSTEM_CLOCK_SOURCE_SIRC);
        if (E_OK == ReturnValue)
        {
            /* Init peripheral clock */
            Mcu_Lld_SetPeripheralClock(ConfigPtr->PeripheralClockConfig);
            ReturnValue |= Mcu_Lld_InitSirc(ConfigPtr);
            ReturnValue |= Mcu_Lld_InitFirc(ConfigPtr);
            ReturnValue |= Mcu_Lld_InitFxosc(ConfigPtr);
#if (MCU_HAS_SXOSC == STD_ON)
            ReturnValue |= Mcu_Lld_InitSxosc(ConfigPtr);
#endif
#if (MCU_NO_PLL == STD_OFF)
            ReturnValue |= Mcu_Lld_InitPll(ConfigPtr);
#endif
            /* Set EFM prescaler configuration and RWS value */
            Mcu_Lld_EfmPrescaler(ConfigPtr->EfmPrescaleValue, ConfigPtr->EfmWRSValue);

            ReturnValue |= Mcu_Lld_InitClockDivider(ConfigPtr);
        }
        /* Pll end wait clock stable, others clock can init directly */
        if ((E_OK == ReturnValue) && (ConfigPtr->SystemClockSource != MCU_SYSTEM_CLOCK_SOURCE_PLL))
        {
            /* Set the clock source of diferent IP */
            ReturnValue = Mcu_Lld_SetClockSource(ConfigPtr);
        }
    }
    return ReturnValue;
}

MCU_FUNC Mcu_RawResetType Mcu_Lld_GetResetRawValue(void)
{
    Mcu_RawResetType ResetReasonRawValue;
    ResetReasonRawValue = (MCU_REG_ADDR32_GET_BITS(RCU_BASE_ADDR32 + RCU_RSSR_OFFSET32, RCU_RSSR_MASK));
    /* Clear reset source status register */
    MCU_REG_ADDR32_WRITE(RCU_BASE_ADDR32 + RCU_RSSR_OFFSET32, RCU_RSSR_MASK);
    return ResetReasonRawValue;
}

MCU_FUNC Mcu_ResetType Mcu_Lld_GetResetValue(void)
{
    Mcu_ResetType ResetReason;
    Mcu_RawResetType ResetReasonRawValue = Mcu_Lld_GetResetRawValue();

    /* If reset reason is zero, use the value from Mcu_ResetStatusValue */
    if (0U == ResetReasonRawValue)
    {
        ResetReasonRawValue = Mcu_ResetStatusValue;
    }
    else
    {
        Mcu_ResetStatusValue = ResetReasonRawValue;
    }

    switch (ResetReasonRawValue)
    {
#if defined(CPU_YTM32B1MC0)
    case RCU_RSSR_LVD_MASK:
        ResetReason = MCU_LVD_RESET;
        break;
#else
    case RCU_RSSR_HVD_MASK:
        ResetReason = MCU_HVD_RESET;
        break;
#endif
    case RCU_RSSR_LPACK_MASK:
        ResetReason = MCU_DEEPSLEEP_ACK_RESET;
        break;
    case RCU_RSSR_WDG_MASK:
        ResetReason = MCU_WATCHDOG_RESET;
        break;
    case RCU_RSSR_CMU_MASK:
        ResetReason = MCU_CMU_RESET;
        break;
    case RCU_RSSR_LOCKUP_MASK:
        ResetReason = MCU_CORE_LOCK_RESET;
        break;
    case RCU_RSSR_DBG_MASK:
        ResetReason = MCU_DEBUG_RESET;
        break;
    case RCU_RSSR_SW_MASK:
        ResetReason = MCU_SW_RESET;
        break;
    case RCU_RSSR_PIN_MASK:
        ResetReason = MCU_RESETB_RESET;
        break;
#if defined(CPU_YTM32B1MC0)
    case RCU_RSSR_POR_BOR_MASK:
        ResetReason = MCU_POR_BOR_RESET;
        break;
#else
    case RCU_RSSR_POR_LVD_MASK:
        ResetReason = MCU_POWER_ON_RESET;
        break;
#endif
#if (MCU_FMU_SUPPORT == STD_ON)
    case RCU_RSSR_FMU_FAIL_REACT_MASK:
        ResetReason = MCU_FMU_FAIL_REACT_RESET;
        break;
    case RCU_RSSR_FMU_FUNC_MASK:
        ResetReason = MCU_FMU_FUNC_RESET;
        break;
#endif
    default:
        ResetReason = MCU_MUTI_REASON_RESET;
        break;
    }
    return ResetReason;
}

#if (MCU_NO_PLL == STD_OFF)
MCU_FUNC uint32 Mcu_Lld_GetPllClockFrequency(const Mcu_ClockConfigType *ConfigPtr)
{
    uint32 PllClockFrequency = 0U;
    Mcu_PllClockRefType PllClockRef = MCU_PLL_CLOCK_REFERENCE_FXOSC;
    uint32 PllRefClockFrequency = 0U;
    uint32 PllFbDiv = 0U;
    uint32 PllRefDiv = 0U;
    uint32 PllFixDiv = 2U;
    if ((MCU_PLL_LOCKED == Mcu_Lld_GetPllStatus()) && (ConfigPtr != NULL_PTR))
    {
        /* Get pll reference clock source */
        PllClockRef = Mcu_Lld_GetPllRef();
        switch (PllClockRef)
        {
        case MCU_PLL_CLOCK_REFERENCE_FXOSC:
            PllRefClockFrequency = ConfigPtr->FxoscConfig->ClockRefPointFrequency;
            break;
        case MCU_PLL_CLOCK_REFERENCE_FIRC:
            PllRefClockFrequency = ConfigPtr->FircConfig->FircClockRefPointFrequency;
            break;
        default:
            PllRefClockFrequency = 0;
            break;
        }
        PllFbDiv = Mcu_Lld_GetPllFbDiv();
        PllRefDiv = Mcu_Lld_GetPllRefDiv();
        PllClockFrequency = (PllRefClockFrequency * PllFbDiv) / (PllFixDiv * PllRefDiv);
    }
    return PllClockFrequency;
}
#endif

MCU_FUNC uint32 Mcu_Lld_GetCoreClockFrequency(const Mcu_ClockConfigType *ConfigPtr)
{
    Mcu_SystemClockSourceType CoreClockSrc = MCU_SYSTEM_CLOCK_SOURCE_FIRC;
    uint32 CoreClockSrcFrequency = 0;
    uint32 CoreClockDiv = 0;
    uint32 CoreClockFrequency = 0;
    /* Get core clock source */
    CoreClockSrc = Mcu_Lld_GetCoreClockSource();
    switch (CoreClockSrc)
    {
    case MCU_SYSTEM_CLOCK_SOURCE_FIRC:
        CoreClockSrcFrequency = ConfigPtr->FircConfig->FircClockRefPointFrequency;
        break;
#if (MCU_NO_PLL == STD_OFF)
    case MCU_SYSTEM_CLOCK_SOURCE_PLL:
        CoreClockSrcFrequency = Mcu_Lld_GetPllClockFrequency(ConfigPtr);
        break;
#endif
    case MCU_SYSTEM_CLOCK_SOURCE_FXOSC:
        CoreClockSrcFrequency = ConfigPtr->FxoscConfig->ClockRefPointFrequency;
        break;
    case MCU_SYSTEM_CLOCK_SOURCE_SIRC:
        CoreClockSrcFrequency = ConfigPtr->SircConfig->SircClockRefPointFrequency;
        break;
    default:
        break;
    }
    if (0U != CoreClockSrcFrequency)
    {
        /* Get core clock divider */
        CoreClockDiv = Mcu_Lld_GetCoreDiv();
        /* Caculate core clock frequency */
        CoreClockFrequency = CoreClockSrcFrequency / CoreClockDiv;
    }
    return CoreClockFrequency;
}

#if defined(CPU_YTM32B1MC0)
MCU_FUNC void Mcu_Lld_SetPcu(const Mcu_PcuConfigType *ConfigPtr)
{
    /* Check the configPtr */
    if (ConfigPtr != NULL_PTR)
    {
        uint32 RegValue = 0U;
        /* BORCR register */
        RegValue |= PCU_BORCR_BOREN(ConfigPtr->LvdConfigPtr->EnableBitList.BOREnable);
        RegValue |= PCU_BORCR_BORLPMD(ConfigPtr->LvdConfigPtr->EnableBitList.BORLowPowerModeEnable);
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_BORCR_OFFSET32, RegValue);

        /* LVDCR register */
        RegValue = 0U;
        RegValue |= PCU_LVDCR_LVD1P5VEN(ConfigPtr->LvdConfigPtr->EnableBitList.LVD1P5VEnable);
        RegValue |= PCU_LVDCR_LVD5VEN(ConfigPtr->LvdConfigPtr->EnableBitList.LVD5VEnable);
        RegValue |= PCU_LVDCR_LVD5VFLTEN(ConfigPtr->LvdConfigPtr->EnableBitList.LVD5VFilterEnable);
        RegValue |= PCU_LVDCR_LVD5VIE(ConfigPtr->LvdConfigPtr->EnableBitList.LVD5VIntEnable);
        RegValue |= PCU_LVDCR_LVD5VLPMD(ConfigPtr->LvdConfigPtr->EnableBitList.LVD5VLowPowerModeEnable);
        RegValue |= PCU_LVDCR_LVD5VRE(ConfigPtr->LvdConfigPtr->EnableBitList.LVD5VReset);
        RegValue |= PCU_LVDCR_LVD5VHYS(ConfigPtr->LvdConfigPtr->LVD5VHysteresis);
        RegValue |= PCU_LVDCR_LVD5VTRIM(ConfigPtr->LvdConfigPtr->LVD5VTrim);
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_LVDCR_OFFSET32, RegValue);

        /* CSR register */
        RegValue = 0;
        RegValue |= PCU_CSR_ESCFG(ConfigPtr->EnergySavingConfigure);
        RegValue |= PCU_CSR_SET1V(ConfigPtr->SetCoreVoltage);
        RegValue |= PCU_CSR_PMCHPRDYDCFG(ConfigPtr->PMCHPRDYConfigure);
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_CSR_OFFSET32, RegValue);
#if (MCU_LLD_PCU_ISR_USED == STD_ON)
        Mcu_PcuNotiList[MCU_PCU_LVD5V] = ConfigPtr->LvdConfigPtr->LVD5VNotificationPtr;
#endif
    }
}

#if (MCU_LLD_PCU_ISR_USED == STD_ON)
/**
 * GCOVR_EXCL_START
 * The function `Mcu_Lld_Pcu_ChannelIrqProcess` is called during a voltage abnormality interrupt.
 * This function checks the relevant voltage status registers of the PCU, making it suitable for
 * coverage testing in integrated testing scenarios.
 */
MCU_FUNC void Mcu_Lld_Pcu_ChannelIrqProcess(void)
{
    uint32 RegVal = 0U;
    RegVal = MCU_REG_ADDR32_READ(PCU_BASE_ADDR32 + PCU_LVDCR_OFFSET32);
    if (0U != (RegVal & PCU_LVDCR_LVD5VFLAG_MASK))
    {
        /* Clear the LVD5V Flag */
        MCU_REG_ADDR32_SET_BITS(PCU_BASE_ADDR32 + PCU_LVDCR_OFFSET32, PCU_LVDCR_LVD5VFLAG_MASK);
        if (NULL_PTR != Mcu_PcuNotiList[MCU_PCU_LVD5V])
        {
            Mcu_PcuNotiList[MCU_PCU_LVD5V]();
        }
    }
}
/* GCOVR_EXCL_STOP */
#endif /* #if ( MCU_LLD_PCU_ISR_USED == STD_ON) */

#else
MCU_FUNC void Mcu_Lld_SetPcu(const Mcu_PcuConfigType *ConfigPtr)
{
    /* Check the configPtr */
    if (ConfigPtr != NULL_PTR)
    {
        uint32 RegValue = 0U;
        /* INTE register */
        RegValue = PCU_INTE_HVD11IE(ConfigPtr->HvdConfigPtr->HVD11IntEnable);
        RegValue |= PCU_INTE_HVD25IE(ConfigPtr->HvdConfigPtr->HVD25IntEnable);
        RegValue |= PCU_INTE_HVD50IE(ConfigPtr->HvdConfigPtr->HVD50IntEnable);
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_INTE_OFFSET32, RegValue);

        /* CTRL register */
        RegValue = PCU_CTRL_HVDRE(ConfigPtr->HvdConfigPtr->ResetEnable);
        RegValue |= PCU_CTRL_FASTREC(ConfigPtr->FastRecoveryEnable);
#if (MCU_HAS_PKE == STD_ON)
        RegValue |= PCU_CTRL_PKE(ConfigPtr->PadKeepEnable);
#endif
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_CTRL_OFFSET32, RegValue);

#if (MCU_LLD_PCU_ISR_USED == STD_ON)
        /* Global notification list initialize*/
        Mcu_PcuNotiList[MCU_PCU_HVD11] = ConfigPtr->HvdConfigPtr->HVD11NotificationPtr;
        Mcu_PcuNotiList[MCU_PCU_HVD25] = ConfigPtr->HvdConfigPtr->HVD25NotificationPtr;
        Mcu_PcuNotiList[MCU_PCU_HVD50] = ConfigPtr->HvdConfigPtr->HVD50NotificationPtr;
#endif
    }
}
#if (MCU_LLD_PCU_ISR_USED == STD_ON)
/**
 * GCOVR_EXCL_START
 * The function `Mcu_Lld_Pcu_ChannelIrqProcess` is called during a voltage abnormality interrupt.
 * This function checks the relevant voltage status registers of the PCU, making it suitable for
 * coverage testing in integrated testing scenarios.
 */
MCU_FUNC void Mcu_Lld_Pcu_ChannelIrqProcess(void)
{
    uint32 RegSSTS = 0;
    uint32 RegINTE = 0;
    RegSSTS = MCU_REG_ADDR32_READ(PCU_BASE_ADDR32 + PCU_SSTS_OFFSET32);
    RegINTE = MCU_REG_ADDR32_READ(PCU_BASE_ADDR32 + PCU_INTE_OFFSET32);

    /* if(High voltage detected) && (Interrupt enabled) */
    if(((RegSSTS & PCU_SSTS_HVD50F_MASK) != 0U) && ((RegINTE & PCU_INTE_HVD50IE_MASK) != 0U))
    {
        /* Clear the SSTS register to prevent the continuous triggering of interrupts. */
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_SSTS_OFFSET32, PCU_SSTS_HVD50F_MASK);
        if(Mcu_PcuNotiList[MCU_PCU_HVD50] != NULL_PTR)
        {
            Mcu_PcuNotiList[MCU_PCU_HVD50]();
        }
    }
    if(((RegSSTS & PCU_SSTS_HVD25F_MASK) != 0U) && ((RegINTE & PCU_INTE_HVD25IE_MASK) != 0U))
    {
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_SSTS_OFFSET32, PCU_SSTS_HVD25F_MASK);
        if(Mcu_PcuNotiList[MCU_PCU_HVD25] != NULL_PTR)
        {
            Mcu_PcuNotiList[MCU_PCU_HVD25]();
        }
    }

    if(((RegSSTS & PCU_SSTS_HVD11F_MASK) != 0U) && ((RegINTE & PCU_INTE_HVD11IE_MASK) != 0U))
    {
        MCU_REG_ADDR32_WRITE(PCU_BASE_ADDR32 + PCU_SSTS_OFFSET32, PCU_SSTS_HVD11F_MASK);
        if(Mcu_PcuNotiList[MCU_PCU_HVD11] != NULL_PTR)
        {
            Mcu_PcuNotiList[MCU_PCU_HVD11]();
        }
    }
}
/*GCOVR_EXCL_STOP*/
#endif /* #if ( MCU_LLD_PCU_ISR_USED == STD_ON) */
#endif

#if (MCU_LLD_SCU_ISR_USED == STD_ON)
MCU_FUNC void Mcu_Lld_Cmu_ChannelIrqProcess(void)
{
    uint32 RegSts = 0U;
    /* Read the STS register */
    RegSts = MCU_REG_ADDR32_READ(SCU_BASE_ADDR32 + SCU_CMUSTS_OFFSET32);

    /* Clear the STS register */
    MCU_REG_ADDR32_WRITE(SCU_BASE_ADDR32 + SCU_CMUSTS_OFFSET32, SCU_CMUSTS_MASK);
    /**
     * The notification function will be call when the fellowing conditions are met:
     * - CMUx interrupt is enabled in configuration.
     * - CMUx notification function is not NULL_PTR.
     * - CMUx flag is detected.
     */
    for (uint8 Idx = 0U; Idx < MCU_CMU_CHANNEL_NUMS; ++Idx)
    {
        if ((Mcu_CmuIntEnableList[Idx] != (boolean)STD_OFF) && (Mcu_CmuNotiList[Idx] != NULL_PTR))
        {
            /* Set the raw RegSts value to `Mcu_CmuErrorType` value */
            Mcu_CmuErrorType CmuError = {0}; /* PRQA S 0759 */
            CmuError.OUTRNG = (uint8)((RegSts & SCU_CMUSTS_CMUX_OUTRNG_MASK(Idx)) >> (SCU_CMUSTS_CMU0_OUTRNG_SHIFT + Idx));
            CmuError.LOSR = (uint8)((RegSts & SCU_CMUSTS_CMUX_LOSR_MASK(Idx)) >> (SCU_CMUSTS_CMU0_LOSR_SHIFT + Idx));
            CmuError.LOSC = (uint8)((RegSts & SCU_CMUSTS_CMUX_LOSC_MASK(Idx)) >> (SCU_CMUSTS_CMU0_LOSC_SHIFT + Idx));

            if ((CmuError.OUTRNG != 0U) || (CmuError.LOSR != 0U) || (CmuError.LOSC != 0U))
            {
#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                (void)Mcu_SetEventStatus(MCU_E_CMU_FAILURE, MCU_EVENT_STATUS_FAILED);
#endif
                Mcu_CmuNotiList[Idx](CmuError);
            }
        }
    }
}
#endif /* #if (MCU_LLD_SCU_ISR_USED == STD_ON) */



#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Mcu_Lld.c */

