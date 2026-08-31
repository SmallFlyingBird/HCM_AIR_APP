/**
 * @file    Pwm_Lld_Etmr.C
 * @version V2.3.0
 *
 * @brief   YUNTU Pwm_Lld_Etmr module interface
 * @details API implementation for Pwm_Lld_Etmr driver
 *
 * @addtogroup PWM_LLD_ETMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                         INCLUDE FILES
=================================================================================================*/
#include "Pwm_Lld_Etmr.h"
#include "Pwm_Cfg.h"
#include "SchM_Pwm.h"
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_ETMR_VENDOR_ID_C                      (180)
#define PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION_C       (4)
#define PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION_C    (0)
#define PWM_LLD_ETMR_SW_MAJOR_VERSION_C               (2)
#define PWM_LLD_ETMR_SW_MINOR_VERSION_C               (3)
#define PWM_LLD_ETMR_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Lld_Etmr.c and Pwm_Lld_Etmr.h are of the same vendor */
#if (PWM_LLD_ETMR_VENDOR_ID_C != PWM_LLD_ETMR_VENDOR_ID)
#error "Pwm_Lld_Etmr.c and Pwm_Lld_Etmr.h have different vendor ids"
#endif

/* Check if Pwm_Lld_Etmr.c and Pwm_Lld_Etmr.h are of the same Autosar version */
#if ((PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION) || \
     (PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Lld_Etmr.c and Pwm_Lld_Etmr.h are different"
#endif

/* Check if Pwm_Lld_Etmr.c and Pwm_Lld_Etmr.h are of the same Software version */
#if ((PWM_LLD_ETMR_SW_MAJOR_VERSION_C != PWM_LLD_ETMR_SW_MAJOR_VERSION) || \
     (PWM_LLD_ETMR_SW_MINOR_VERSION_C != PWM_LLD_ETMR_SW_MINOR_VERSION) || \
     (PWM_LLD_ETMR_SW_PATCH_VERSION_C != PWM_LLD_ETMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Lld_Etmr.c and Pwm_Lld_Etmr.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief Converts the duty cycle to ticks
 */
#define PWM_LLD_ETMR_DUTY_TO_TICK(duty, period) ((uint32)(((uint64)(duty) * (uint64)(period)) >> 15U))

/**
 * @brief Converts the ticks to duty cycle
 */
#define PWM_LLD_ETMR_TICK_TO_DUTY(tick, period) ((uint16)(((uint64)(tick) << 15U) / (uint64)(period)))

/*==================================================================================================
 *                                         LOCAL CONSTANTS
==================================================================================================*/
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Table of base addresses for eTMR instances. */
PWM_CONST static volatile eTMR_Type *const Etmr_Lld_Base[eTMR_INSTANCE_COUNT] = eTMR_BASE_PTRS;

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
 *                                         LOCAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Table to save eTMR align mode. */
PWM_VAR static Pwm_Lld_Etmr_AlignModeType Pwm_Lld_Etmr_AlignMode[eTMR_INSTANCE_COUNT][eTMR_CH_COUNT];

/** @brief Table to save eTMR overflow interrupt callback pointers. */
PWM_VAR static Pwm_Lld_Etmr_CallbackType Pwm_Lld_Etmr_OvfCallback[eTMR_INSTANCE_COUNT];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
 *                                         LOCAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 * @brief       This function returns the overflow interrupt enable bit.
 * @param[in]   Base The base address of the eTMR instance.
 * @return      uint8
 * @retval      TRUE if the interrupt is enabled
 * @retval      FALSE if the interrupt is disabled
 */
PWM_FUNC static inline uint8 ETMR_IsOvfIntEnabled(eTMR_Type const volatile *Base)
{
    return (uint8)((Base->INTE & eTMR_INTE_TOIE_MASK) >> eTMR_INTE_TOIE_SHIFT);
}

/**
 * @brief       This function returns the overflow interrupt flag.
 * @param[in]   Base The base address of the eTMR instance.
 * @return      uint8
 * @retval      TRUE if the interrupt flag is set
 * @retval      FALSE if the interrupt flag is cleared
 */
PWM_FUNC static inline uint8 ETMR_GetOvfFlag(eTMR_Type const volatile *Base)
{
    return (uint8)((Base->STS & eTMR_STS_TOF_MASK) >> eTMR_STS_TOF_SHIFT);
}

/**
 * @brief       This function clears the overflow interrupt flag.
 * @param[in]   Base The base address of the eTMR instance.
 * @return      void
 */
PWM_FUNC static inline void ETMR_ClearOvfFlag(volatile eTMR_Type *const Base)
{
    /* Clear overflow interrupt flag. */
    Base->STS |= eTMR_STS_TOF_MASK;
}

/**
 * @brief       This function checks if the registers is loading.
 * @param[in]   Base The base address of the eTMR instance.
 * @return      The registers loading status.
 * @retval      TRUE The registers is loading.
 * @retval      FALSE The registers is not loading.
 */
PWM_FUNC static inline uint8 ETMR_RegistersIsLoading(eTMR_Type const volatile *Base)
{
    return (uint8)((Base->SYNC & eTMR_SYNC_LDOK_MASK) >> eTMR_SYNC_LDOK_SHIFT);
}

#if defined (CIM_ETMROPT_IS_INDEPENDENT)
/**
 * @brief       This function clears the external clock source for the eTMR instance.
 * @param[in]   Instance The instance number.
 * @return      void
 */
PWM_FUNC static inline void ETMR_ClearExternalClockSource(uint8 Instance)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    volatile uint32 *EtmrOpt = &CimBase->ETMROPT0 + Instance;
    *EtmrOpt &= ~CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK;
}

/**
 * @brief       This function configures the external clock source for the eTMR instance.
 * @param[in]   Instance The instance number.
 * @param[in]   ExClkSrc The external clock source.
 * @return      void
 */
PWM_FUNC static inline void ETMR_ConfigureExternalClockSource(uint8 Instance, Pwm_Lld_Etmr_ExClkSrcType ExClkSrc)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    volatile uint32 *EtmrOpt = &CimBase->ETMROPT0 + Instance;
    *EtmrOpt &= ~CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK;
    *EtmrOpt |= CIM_ETMROPT0_ETMR0_EXTCLK_SEL(ExClkSrc);
}
#else
/**
 * @brief       This function clears the external clock source for the eTMR instance.
 * @param[in]   Instance The instance number.
 * @return      void
 */
PWM_FUNC static inline void ETMR_ClearExternalClockSource(uint8 Instance)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    uint32  Etmr_Inst_Index = Instance * 2U;
    CimBase->ETMROPT0 &= ~(CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK << Etmr_Inst_Index);
}

/**
 * @brief       This function configures the external clock source for the eTMR instance.
 * @param[in]   Instance The instance number.
 * @param[in]   ExClkSrc The external clock source.
 * @return      void
 */
PWM_FUNC static inline void ETMR_ConfigureExternalClockSource(uint8 Instance, Pwm_Lld_Etmr_ExClkSrcType ExClkSrc)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    uint32  Etmr_Inst_Index = Instance * 2U;
    CimBase->ETMROPT0 &= ~(CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK << Etmr_Inst_Index);
    CimBase->ETMROPT0 |= (CIM_ETMROPT0_ETMR0_EXTCLK_SEL(ExClkSrc) << Etmr_Inst_Index);
}
#endif

/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       This function initializes the eTMR instance.
 * @param[in]   Instance The instance number.
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_InitInstance(uint8 Instance, const Pwm_Lld_Etmr_InstCfgType *InstCfg)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(InstCfg != NULL_PTR);
#endif
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();
    /* Configure INIT register. */
#ifndef eTMR_NO_INIT
    Base->INIT = 0U;
#endif
    /* Clear LDOK bit. */
    Base->SYNC |= eTMR_SYNC_CLDOK_MASK;
    /* Configure the default period. */
#ifdef eTMR_ERRATA_E0003
    Base->MOD = InstCfg->Period - 1;
#else
    Base->MOD = InstCfg->Period;
#endif
    /* Set LDOK bit. */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK;
    Base->SYNC |= eTMR_SYNC_REGLD(3U);
    Base->SYNC |= eTMR_SYNC_TRIGS0(1U);
    /* Init MOD value, it takes effect immediately. */
    Base->SYNC |= eTMR_SYNC_SWTRIG(1U);
    /* Configure SYNC register. */
    Base->SYNC = 0U;
    Base->SYNC |= eTMR_SYNC_LDFRQ(0U);
    Base->SYNC |= eTMR_SYNC_MASKLD(PWM_LLD_ETMR_REG_LOAD_MATCH_MOD);
    Base->SYNC |= eTMR_SYNC_TRIGS2(PWM_LLD_ETMR_TRGSRC_NONE);
    Base->SYNC |= eTMR_SYNC_CNTLD(PWM_LLD_ETMR_COUNTER_LOAD_TRIGGER);
    Base->SYNC |= eTMR_SYNC_TRIGS1(PWM_LLD_ETMR_TRGSRC_NONE);
#if((STD_ON == PWM_DUTYCYCLE_UPDATED_ENDPERIOD)||(STD_ON == PWM_PERIOD_UPDATED_ENDPERIOD))
    Base->SYNC |= eTMR_SYNC_REGLD(PWM_LLD_ETMR_REG_LOAD_MATCH_MOD);
    Base->SYNC |= eTMR_SYNC_TRIGS0(PWM_LLD_ETMR_TRGSRC_NONE);
#else
    Base->SYNC |= eTMR_SYNC_REGLD(PWM_LLD_ETMR_REG_LOAD_TRIGGER);
    Base->SYNC |= eTMR_SYNC_TRIGS0(PWM_LLD_ETMR_TRGSRC_SW);
#endif
    /* Counter initial value is from register INIT. */
#ifndef eTMR_NO_INIT
    Base->SYNC |= eTMR_SYNC_CNTINIT(1U);
#endif
    /* Configure external clock source. */
    if (PWM_LLD_ETMR_CLKSRC_EXTERNAL == InstCfg->ClockSource)
    {
        ETMR_ConfigureExternalClockSource(Instance, InstCfg->ExClockSource);
    }
    /* Configure output trigger. */
    Base->OTRIG = 0U;
#if (defined(PWM_LLD_ETMR_HAS_OUTPUT_TRIGGER_WIDTH) && (PWM_LLD_ETMR_HAS_OUTPUT_TRIGGER_WIDTH == STD_ON))
    Base->OTRIG |= eTMR_OTRIG_TWD(InstCfg->OutTrgWidth);
#endif
    Base->OTRIG |= eTMR_OTRIG_TFRQ(InstCfg->OutTrgFreq);
    Base->OTRIG |= eTMR_OTRIG_PULSESRC(InstCfg->PulseSrc);
    Base->OTRIG |= eTMR_OTRIG_TSRC(InstCfg->OutTrgSrc);
    Base->OTRIG |= eTMR_OTRIG_MODTEN(InstCfg->ModTrgEn);
#if (defined(PWM_LLD_ETMR_HAS_MID_MATCH_TRIGGER) && (PWM_LLD_ETMR_HAS_MID_MATCH_TRIGGER == STD_ON))
    Base->OTRIG |= eTMR_OTRIG_MIDTEN(InstCfg->MidTrgEn);
#endif
#if (defined(PWM_LLD_ETMR_HAS_INIT_MATCH_TRIGGER) && (PWM_LLD_ETMR_HAS_INIT_MATCH_TRIGGER == STD_ON))
    Base->OTRIG |= eTMR_OTRIG_INITTEN(InstCfg->InitTrgEn);
#endif
    /* Clear the Ovf flag. */
    ETMR_ClearOvfFlag(Base);
    /* Configure INTE register. */
    Base->INTE &= ~(uint32)eTMR_INTE_TOIE_MASK;
    Base->INTE |= eTMR_INTE_TOIE(InstCfg->OvfIrqEn);
    if (TRUE == InstCfg->OvfIrqEn)
    {
        Pwm_Lld_Etmr_OvfCallback[Instance] = InstCfg->OvfCallback;
    }
    else
    {
        Pwm_Lld_Etmr_OvfCallback[Instance] = NULL_PTR;
    }
    /* Configure CTRL register. */
    Base->CTRL = 0U;
    Base->CTRL |= eTMR_CTRL_DBGDIS(InstCfg->DebugModeEnable);
    Base->CTRL |= eTMR_CTRL_CLKPRS(InstCfg->ClockPrescaler);
#if (defined(PWM_LLD_ETMR_HAS_DEADTIME_PRESCALER) && (PWM_LLD_ETMR_HAS_DEADTIME_PRESCALER == STD_ON))
    Base->CTRL |= eTMR_CTRL_DTPRS(InstCfg->DeadtimePrescaler);
#endif
    Base->CTRL |= eTMR_CTRL_CLKSRC(InstCfg->ClockSource);
#ifndef eTMR_CTRL_NO_DITHMD
    Base->CTRL |= eTMR_CTRL_DITHMD(PWM_LLD_ETMR_DITHMD_DISABLED);
#endif
    Base->CTRL |= eTMR_CTRL_GLOBEN(0U);
    /* Enable eTMR */
    Base->CTRL |= eTMR_CTRL_EN(1U);
#ifdef eTMR_ERRATA_CLEAR_MASK
    Base->STS = eTMR_STS_CLEAR_MASK;
#endif
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();
}

/**
 * @brief       This function initializes the eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_InitChannel(uint8 Instance, const Pwm_Lld_Etmr_ChCfgType *ChCfg)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(ChCfg != NULL_PTR);
#endif
    uint32 PeriodTick;
    uint32 DutyCycleTick;
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01();
    /* Clear LDOK bit. */
    Base->SYNC |= eTMR_SYNC_CLDOK_MASK;
    /* Configure CHMASK register. */
    /* Output PWM normally. */
    Base->CHMASK &= ~((uint32)eTMR_CHMASK_CH0M_MASK << ChCfg->ChannelId);
    /* Configure CH_CTRL register. */
    Base->CH[ChCfg->ChannelId].CTRL = 0U;
    Base->CH[ChCfg->ChannelId].CTRL |= eTMR_CH_CTRL_LDEN(1U);
    Base->CH[ChCfg->ChannelId].CTRL |= eTMR_CH_CTRL_CHPOL(ChCfg->Polarity);
    /* Configure output trigger. */
    Base->CH[ChCfg->ChannelId].CTRL |= eTMR_CH_CTRL_VAL0TEN(ChCfg->Val0TrgEn);
    Base->CH[ChCfg->ChannelId].CTRL |= eTMR_CH_CTRL_VAL1TEN(ChCfg->Val1TrgEn);
    /* Select channel in PWM mode. */
    Base->CH[ChCfg->ChannelId].CTRL |= eTMR_CH_CTRL_CHMODE(PWM_LLD_ETMR_CHANNEL_MODE_PWM);
    /* Configure CHINIT register. */
    Base->CHINIT &= ~((uint32)eTMR_CHINIT_CH0INIT_MASK << ChCfg->ChannelId);
    /* Configure channel mode: independent or complementary mode. */
    Base->CTRL |= (uint32)ChCfg->ChMode << (eTMR_CTRL_COMPL01_SHIFT + (ChCfg->ChannelId >> 1U));
    /* Get the newest period in the MOD register */
#if defined(eTMR_ERRATA_E0003) && (0 == eTMR_INIT_VALUE)
    PeriodTick = Base->MOD + 1U;
#else
    PeriodTick = Base->MOD;
#endif
    /* Configure the default duty cycle. */
    DutyCycleTick = PWM_LLD_ETMR_DUTY_TO_TICK(ChCfg->DutyCycle, PeriodTick);
    switch (ChCfg->AlignMode)
    {
        case PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE:
#ifdef eTMR_ERRATA_DUTY_0
            if (0U == DutyCycleTick)
            {
                Base->CH[ChCfg->ChannelId].VAL0 = Base->MOD + 1U;
                Base->CH[ChCfg->ChannelId].VAL1 = Base->MOD;
            }
            else
            {
                Base->CH[ChCfg->ChannelId].VAL0 = eTMR_INIT_VALUE;
                Base->CH[ChCfg->ChannelId].VAL1 = DutyCycleTick;
            }
#else
#ifdef eTMR_ERRATA_E0003
            if (PeriodTick == DutyCycleTick)
            {
                Base->CH[ChCfg->ChannelId].VAL0 = eTMR_INIT_VALUE;
                Base->CH[ChCfg->ChannelId].VAL1 = Base->MOD + 1U;
            }
            else
#endif
            {
                Base->CH[ChCfg->ChannelId].VAL0 = eTMR_INIT_VALUE;
                Base->CH[ChCfg->ChannelId].VAL1 = DutyCycleTick;
            }
#endif
            break;
        case PWM_LLD_ETMR_ALIGN_MODE_CENTER:
#ifdef eTMR_ERRATA_E0003
            if (DutyCycleTick == PeriodTick)
            {
                Base->CH[ChCfg->ChannelId].VAL0 = (PeriodTick - DutyCycleTick) >> 1U;
                Base->CH[ChCfg->ChannelId].VAL1 = Base->MOD + 1U;
            }
            else
#endif
            {
                Base->CH[ChCfg->ChannelId].VAL0 = (PeriodTick - DutyCycleTick) >> 1U;
                Base->CH[ChCfg->ChannelId].VAL1 = (PeriodTick + DutyCycleTick) >> 1U;
            }
            break;
        case PWM_LLD_ETMR_ALIGN_MODE_RIGHT_EDGE:
#ifdef eTMR_ERRATA_E0003
            if (DutyCycleTick == PeriodTick)
            {
                Base->CH[ChCfg->ChannelId].VAL0 = PeriodTick - DutyCycleTick;
                Base->CH[ChCfg->ChannelId].VAL1 = Base->MOD + 1U;
            }
            else
            {
                Base->CH[ChCfg->ChannelId].VAL0 = PeriodTick - DutyCycleTick - 1;
                Base->CH[ChCfg->ChannelId].VAL1 = Base->MOD;
            }
#else
            Base->CH[ChCfg->ChannelId].VAL0 = PeriodTick - DutyCycleTick;
            Base->CH[ChCfg->ChannelId].VAL1 = Base->MOD;
#endif
            break;
        default:
            /* Do nothing. */
            break;
    }
    /* Configure the default dead time. */
#ifndef eTMR_DT_IS_DEPENDENT
    if (0U == (ChCfg->ChannelId & 0x1U))
    {
        /* configure the deadtime of the even PWM channel */
        Base->CH[ChCfg->ChannelId].DT = ChCfg->DeadTime;
        /* configure the deadtime of the complementary odd PWM channel */
        Base->CH[ChCfg->ChannelId + 1].DT = ChCfg->DeadTime;
    }
    else
    {
        /* configure the deadtime of the odd PWM channel */
        Base->CH[ChCfg->ChannelId].DT = ChCfg->DeadTime;
    }
#else
    if (0U == (ChCfg->ChannelId & 0x1U))
    {
        /* configure the deadtime of the even PWM channel */
        Base->DT &= ~eTMR_DT_DTEVEN_MASK;
        Base->DT |= (uint32)ChCfg->DeadTime & eTMR_DT_DTEVEN_MASK;
        /* configure the deadtime of the complementary odd PWM channel */
        Base->DT &= ~eTMR_DT_DTODD_MASK;
        Base->DT |= eTMR_DT_DTODD(ChCfg->DeadTime);
    }
    else
    {
        /* configure the deadtime of the odd PWM channel */
        Base->DT &= ~eTMR_DT_DTODD_MASK;
        Base->DT |= eTMR_DT_DTODD(ChCfg->DeadTime);
    }
#endif
#if(STD_ON == PWM_PERIOD_UPDATED_ENDPERIOD)
    /* Set LDOK bit. registers are loaded at the end of period of currently generated waveform (current waveform is finished) */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK;
#else
    /* Set LDOK bit with a SW trigger to make registers load immidiately. */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK | eTMR_SYNC_SWTRIG_MASK;
#endif
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01();
    /* Save PWM align mode */
    Pwm_Lld_Etmr_AlignMode[Instance][ChCfg->ChannelId] = ChCfg->AlignMode;
}

/**
 * @brief       This function de-initializes the eTMR module.
 * @param[in]   Instance The instance number.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_DeInitInstance(uint8 Instance)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
#endif
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    Base->STS = 0xFFFF7FFFU;
    Base->CNT = 0U;
    Base->CTRL = 0U;
    Base->SYNC = 0U;
    Base->OTRIG = 0U;
    Base->INTE = 0U;
    Base->CHINIT = 0U;
    Base->CHMASK = 0U;
    Base->CHFV = 0U;
#ifndef eTMR_NO_INIT
    Base->INIT = 0U;
#endif
#if (eTMR_INSTANCE_COUNT > 2U)
    if (3U == Instance)
    {
        Base->MOD = 0xFFFFFFFFU;
#ifndef eTMR_NO_MID
        Base->MID = 0xFFFFU;
#endif
    }
    else
#endif  /* eTMR_INSTANCE_COUNT > 2U */
    {
        Base->MOD = 0xFFFFU;
#ifndef eTMR_NO_MID
        Base->MID = 0xFFU;
#endif
    }
#ifndef eTMR_NO_DITHMOD
    Base->DITHMOD = 0U;
#endif
#ifdef eTMR_DT_IS_DEPENDENT
    Base->DT = 0U;
#endif
    Base->FAULT = 0U;
    /* De-initialize ETMROPT in CIM. */
    ETMR_ClearExternalClockSource(Instance);
    Pwm_Lld_Etmr_OvfCallback[Instance] = NULL_PTR;
}

/**
 * @brief       This function de-initializes the eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_DeInitChannel(uint8 Instance, const Pwm_Lld_Etmr_ChCfgType *ChCfg)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(ChCfg != NULL_PTR);
#endif
    uint32 Timeout = PWM_LLD_ETMR_TIMEOUT_COUNT;
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02();
    /* Clear LDOK bit. */
    Base->SYNC |= eTMR_SYNC_CLDOK_MASK;
    /* Clear VAL0 and VAL1 first. */
    Base->CH[ChCfg->ChannelId].VAL0 = 0U;
    Base->CH[ChCfg->ChannelId].VAL1 = 0U;
    /* Set LDOK bit. */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK;
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02();
    /* Wait until registers loading is ok or timeout, VAL0 and VAL1 is cleared. */
    /* GCOVR_EXCL_START */
    /* This (TRUE == ETMR_RegistersIsLoading(Base)) branch cannot be reached sometimes. */
    while ((TRUE == ETMR_RegistersIsLoading(Base)) && (Timeout > 0U))
    {
        Timeout--;
    }
    /* GCOVR_EXCL_STOP */
    /* PWM mode. */
    Base->CH[ChCfg->ChannelId].CTRL = 0x1U;
    Pwm_Lld_Etmr_SetOutputToIdle(Instance, ChCfg->ChannelId, ChCfg->IdleState);
#ifndef eTMR_NO_DITHVAL1
    Base->CH[ChCfg->ChannelId].DITHVAL1 = 0U;
#endif
#ifndef eTMR_DT_IS_DEPENDENT
    Base->CH[ChCfg->ChannelId].DT = 0U;
#endif
    /* Clear PWM align mode */
    Pwm_Lld_Etmr_AlignMode[Instance][ChCfg->ChannelId] = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE;
}

/**
 * @brief       This function sets the duty cycle of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   DutyCycle The duty cycle value. The value should be in the range of [0, 0x8000].
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetDutyCycle(uint8 Instance, uint8 Channel, uint16 DutyCycle)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(Channel < eTMR_CH_COUNT);
#endif
    uint32 PeriodTick;
    uint32 DutyCycleTick;
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03();
    /* Generate PWM by normal mode, VAL0 and VAL1. */
    Base->CH[Channel].CTRL &= ~(eTMR_CH_CTRL_PWMSRC_MASK);
    Base->CH[Channel].CTRL |= eTMR_CH_CTRL_PWMSRC(PWM_LLD_ETMR_PWMSRC_NORMAL);
    /* Clear LDOK bit. */
    Base->SYNC |= eTMR_SYNC_CLDOK_MASK;
    /* Get the newest period in the MOD register */
#if defined(eTMR_ERRATA_E0003) && (0 == eTMR_INIT_VALUE)
    PeriodTick = Base->MOD + 1U;
#else
    PeriodTick = Base->MOD;
#endif
    /* Configure the default duty cycle. */
    DutyCycleTick = PWM_LLD_ETMR_DUTY_TO_TICK(DutyCycle, PeriodTick);
    switch (Pwm_Lld_Etmr_AlignMode[Instance][Channel])
    {
        case PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE:
#ifdef eTMR_ERRATA_DUTY_0
            if (0U == DutyCycleTick)
            {
                Base->CH[Channel].VAL0 = Base->MOD + 1U;
                Base->CH[Channel].VAL1 = Base->MOD;
            }
            else
            {
                Base->CH[Channel].VAL0 = eTMR_INIT_VALUE;
                Base->CH[Channel].VAL1 = DutyCycleTick;
            }
#else
#ifdef eTMR_ERRATA_E0003
            if (PeriodTick == DutyCycleTick)
            {
                Base->CH[Channel].VAL0 = eTMR_INIT_VALUE;
                Base->CH[Channel].VAL1 = Base->MOD + 1U;
            }
            else
#endif
            {
                Base->CH[Channel].VAL0 = eTMR_INIT_VALUE;
                Base->CH[Channel].VAL1 = DutyCycleTick;
            }
#endif
            break;
        case PWM_LLD_ETMR_ALIGN_MODE_CENTER:
#ifdef eTMR_ERRATA_E0003
            if (DutyCycleTick == PeriodTick)
            {
                Base->CH[Channel].VAL0 = (PeriodTick - DutyCycleTick) >> 1U;
                Base->CH[Channel].VAL1 = Base->MOD + 1U;
            }
            else
#endif
            {
                Base->CH[Channel].VAL0 = (PeriodTick - DutyCycleTick) >> 1U;
                Base->CH[Channel].VAL1 = (PeriodTick + DutyCycleTick) >> 1U;
            }
            break;
        case PWM_LLD_ETMR_ALIGN_MODE_RIGHT_EDGE:
#ifdef eTMR_ERRATA_E0003
            if (DutyCycleTick == PeriodTick)
            {
                Base->CH[Channel].VAL0 = PeriodTick - DutyCycleTick;
                Base->CH[Channel].VAL1 = Base->MOD + 1U;
            }
            else
            {
                Base->CH[Channel].VAL0 = PeriodTick - DutyCycleTick - 1;
                Base->CH[Channel].VAL1 = Base->MOD;
            }
#else
            Base->CH[Channel].VAL0 = PeriodTick - DutyCycleTick;
            Base->CH[Channel].VAL1 = Base->MOD;
#endif
            break;
        default:
            /* Do nothing. */
            break;
    }
#if(STD_ON == PWM_DUTYCYCLE_UPDATED_ENDPERIOD)
    /* Set LDOK bit. registers are loaded at the end of period of currently generated waveform (current waveform is finished) */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK;
#else
    /* Set LDOK bit with a SW trigger to make registers load immidiately. */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK | eTMR_SYNC_SWTRIG_MASK;
#endif
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03();
}

/**
 * @brief       This function sets the period and duty cycle of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   Period The period value.
 * @param[in]   DutyCycle The duty cycle value. The value should be in the range of [0, 0x8000].
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetPeriodAndDuty
(
    uint8 Instance,
    uint8 Channel,
    uint32 Period,
    uint16 DutyCycle
)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(Channel < eTMR_CH_COUNT);
    DevAssert(Period > 0U);
#endif
    uint32 PeriodTick;
    uint32 DutyCycleTick;
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04();
    /* Generate PWM by normal mode, VAL0 and VAL1. */
    Base->CH[Channel].CTRL &= ~(eTMR_CH_CTRL_PWMSRC_MASK);
    Base->CH[Channel].CTRL |= eTMR_CH_CTRL_PWMSRC(PWM_LLD_ETMR_PWMSRC_NORMAL);
    /* Clear LDOK bit. */
    Base->SYNC |= eTMR_SYNC_CLDOK_MASK;
    /* Update the period. */
#ifdef eTMR_ERRATA_E0003
    Base->MOD = Period - 1;
#else
    Base->MOD = Period;
#endif
    PeriodTick = Period;
    /* Configure the duty cycle. */
    DutyCycleTick = PWM_LLD_ETMR_DUTY_TO_TICK(DutyCycle, PeriodTick);
    switch (Pwm_Lld_Etmr_AlignMode[Instance][Channel])
    {
        case PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE:
#ifdef eTMR_ERRATA_DUTY_0
            if (0U == DutyCycleTick)
            {
                Base->CH[Channel].VAL0 = PeriodTick + 1U;
                Base->CH[Channel].VAL1 = PeriodTick;
            }
            else
            {
                Base->CH[Channel].VAL0 = eTMR_INIT_VALUE;
                Base->CH[Channel].VAL1 = DutyCycleTick;
            }
#else
#ifdef eTMR_ERRATA_E0003
            if (PeriodTick == DutyCycleTick)
            {
                Base->CH[Channel].VAL0 = eTMR_INIT_VALUE;
                Base->CH[Channel].VAL1 = PeriodTick;
            }
            else
#endif
            {
                Base->CH[Channel].VAL0 = eTMR_INIT_VALUE;
                Base->CH[Channel].VAL1 = DutyCycleTick;
            }
#endif
            break;
        case PWM_LLD_ETMR_ALIGN_MODE_CENTER:
#ifdef eTMR_ERRATA_E0003
            if (DutyCycleTick == PeriodTick)
            {
                Base->CH[Channel].VAL0 = (PeriodTick - DutyCycleTick) >> 1U;
                Base->CH[Channel].VAL1 = PeriodTick;
            }
            else
#endif
            {
                Base->CH[Channel].VAL0 = (PeriodTick - DutyCycleTick) >> 1U;
                Base->CH[Channel].VAL1 = (PeriodTick + DutyCycleTick) >> 1U;
            }
            break;
        case PWM_LLD_ETMR_ALIGN_MODE_RIGHT_EDGE:
#ifdef eTMR_ERRATA_E0003
            if (DutyCycleTick == PeriodTick)
            {
                Base->CH[Channel].VAL0 = PeriodTick - DutyCycleTick;
                Base->CH[Channel].VAL1 = PeriodTick;
            }
            else
            {
                Base->CH[Channel].VAL0 = PeriodTick - DutyCycleTick - 1U;
                Base->CH[Channel].VAL1 = PeriodTick - 1U;
            }
#else
            Base->CH[Channel].VAL0 = PeriodTick - DutyCycleTick;
            Base->CH[Channel].VAL1 = PeriodTick;
#endif
            break;
        default:
            /* Do nothing. */
            break;
    }
#if(STD_ON == PWM_PERIOD_UPDATED_ENDPERIOD)
    /* Set LDOK bit. registers are loaded at the end of period of currently generated waveform (current waveform is finished) */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK;
#else
    /* Set LDOK bit with a SW trigger to make registers load immidiately. */
    Base->SYNC |= eTMR_SYNC_LDOK_MASK | eTMR_SYNC_SWTRIG_MASK;
#endif
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04();
}

/**
 * @brief       This function sets the output to idle state.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   IdleState The idle state.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetOutputToIdle
(
    uint8 Instance,
    uint8 Channel,
    Pwm_Lld_Etmr_OutputStateType IdleState
)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(Channel < eTMR_CH_COUNT);
#endif
    uint32 Polarity;
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05();
    /* Generate PWM by software mode. */
    Base->CH[Channel].CTRL &= ~eTMR_CH_CTRL_PWMSRC_MASK;
    Base->CH[Channel].CTRL |= eTMR_CH_CTRL_PWMSRC(PWM_LLD_ETMR_PWMSRC_SW);
    Polarity = (Base->CH[Channel].CTRL & eTMR_CH_CTRL_CHPOL_MASK) >> eTMR_CH_CTRL_CHPOL_SHIFT;
    /* Change software output value. */
    Base->CHSWV &= ~((uint32)eTMR_CHSWV_CH0SWV_MASK << Channel);
    Base->CHSWV |= (((uint32)IdleState ^ Polarity) << Channel);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05();
}

/**
 * @brief       This function gets the output state of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @return      The output state.
 * @retval      PWM_LLD_ETMR_OUTPUT_STATE_LOW The output is low.
 * @retval      PWM_LLD_ETMR_OUTPUT_STATE_HIGH The output is high.
 */
PWM_FUNC Pwm_Lld_Etmr_OutputStateType Pwm_Lld_Etmr_GetOutputState(uint8 Instance, uint8 Channel)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(Channel < eTMR_CH_COUNT);
#endif
    Pwm_Lld_Etmr_OutputStateType OutputState;
    eTMR_Type const volatile *Base = Etmr_Lld_Base[Instance];
    /* Get the output state. */
    if (0U != (Base->IOSTS & ((uint32)eTMR_IOSTS_CH0IO_MASK << Channel)))
    {
        OutputState = PWM_LLD_ETMR_OUTPUT_STATE_HIGH;
    }
    else
    {
        OutputState = PWM_LLD_ETMR_OUTPUT_STATE_LOW;
    }
    return OutputState;
}

/**
 * @brief       This function sets the dead time of the specified eTMR channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   DeadTimeTicks The dead time value.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_SetChannelDeadTime(uint8 Instance, uint8 Channel, uint16 DeadTimeTicks)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
    DevAssert(Channel < eTMR_CH_COUNT);
#endif
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
#ifndef eTMR_DT_IS_DEPENDENT
    Base->CH[Channel].DT = DeadTimeTicks;
#else
    if (0U == (Channel & 0x1U))
    {
        Base->DT &= ~eTMR_DT_DTEVEN_MASK;
        Base->DT |= (uint32)DeadTimeTicks & eTMR_DT_DTEVEN_MASK;
    }
    else
    {
        Base->DT &= ~eTMR_DT_DTODD_MASK;
        Base->DT |= eTMR_DT_DTODD(DeadTimeTicks);
    }
#endif
}

/**
 * @brief       eTMR overflow interrupt handler.
 * @details     This function handles the different eTMR instances overflow interrupt.
 * @param[in]   Instance eTMR hardware instance
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Etmr_Ovf_IrqHandler(uint8 Instance)
{
#if (PWM_LLD_ETMR_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eTMR_INSTANCE_COUNT);
#endif
    volatile eTMR_Type *const Base = Etmr_Lld_Base[Instance];
    /* GCOVR_EXCL_START */
    /* This (FALSE == ETMR_GetOvfFlag(Base)) branch cannot be reached normally. */
    if (TRUE == ETMR_GetOvfFlag(Base))
        /* GCOVR_EXCL_STOP */
    {
        /* Clear interrupt flag */
        ETMR_ClearOvfFlag(Base);
        /* GCOVR_EXCL_START */
        /* This (FALSE == ETMR_IsOvfIntEnabled(Base)) branch cannot be reached normally. */
        if ((TRUE == ETMR_IsOvfIntEnabled(Base)) && (Pwm_Lld_Etmr_OvfCallback[Instance] != NULL_PTR))
            /* GCOVR_EXCL_STOP */
        {
            Pwm_Lld_Etmr_OvfCallback[Instance]();
        }
    }
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
