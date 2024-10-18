/**************************************************************************************************/
/**
 * @file      : Srmc_Drv.c
 * @brief     : SRMC low level driver source file
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

/** @addtogroup Srmc_Drv
 *  @brief SRMC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Srmc_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define SRMC_DRV_C_VENDOR_ID                   0x00B3U
#define SRMC_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define SRMC_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define SRMC_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define SRMC_DRV_C_SW_MAJOR_VERSION            1U
#define SRMC_DRV_C_SW_MINOR_VERSION            2U
#define SRMC_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Srmc_Drv.h file are of the same vendor */
#if (SRMC_DRV_C_VENDOR_ID != SRMC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Srmc_Drv.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Autosar version */
#if ((SRMC_DRV_C_AR_RELEASE_MAJOR_VERSION != SRMC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SRMC_DRV_C_AR_RELEASE_MINOR_VERSION != SRMC_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SRMC_DRV_C_AR_RELEASE_REVISION_VERSION != SRMC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Srmc_Drv.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Software version */
#if ((SRMC_DRV_C_SW_MAJOR_VERSION != SRMC_DRV_H_SW_MAJOR_VERSION) ||                               \
     (SRMC_DRV_C_SW_MINOR_VERSION != SRMC_DRV_H_SW_MINOR_VERSION) ||                               \
     (SRMC_DRV_C_SW_PATCH_VERSION != SRMC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Srmc_Drv.c and Srmc_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((SRMC_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (SRMC_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Srmc_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/* SCB SCR: SLEEPDEEP Position */
#define Z20_SCB_SCR_SLEEPDEEP_POS (2U)
/* SCB SCR: SLEEPDEEP Mask */
#define Z20_SCB_SCR_SLEEPDEEP_MASK (1U << Z20_SCB_SCR_SLEEPDEEP_POS)

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
 *  @brief Pointer to System Reset and Mode Control Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type, 
no side effects forseen by violating this rule. 
The following two lines of code also violate this rule with the same reason. */
static Reg_Srmc_BfType *const Srmc_Drv_SrmcRegBfPtr = (Reg_Srmc_BfType *)SRMC_BASE_ADDR;
static Reg_Srmc_WType *const  Srmc_Drv_SrmcRegWPtr = (Reg_Srmc_WType *)SRMC_BASE_ADDR;

/**
 *  @brief Pointer to SCB Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to object to an integral type,  
no side effects forseen by violating this rule. */
static Z20_SCBType *const Srmc_Drv_ScbRegPtr = (Z20_SCBType *)Z20_SCB;

#define MCU_STOP_SEC_CONST_PTR
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
 * @brief       Configs SRMC wakeup source.
 *
 * @param[in]   WakeupValue1:  Settings of wakeup sources.
 * @param[in]   WakeupValue2:  Settings of wakeup sources.
 *
 * @return      None
 *
 */
static void Srmc_Drv_ConfigPowerModeWakeupSrc(uint32 WakeupValue1, uint32 WakeupValue2)
{
    Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 = WakeupValue1;
    Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC2 = WakeupValue2;
}

/**
 * @brief       Configs core lockup reset.
 *
 * @param[in]   Enable:  Enable/Disable core lockup reset.
 *
 * @return      None
 *
 */
static void Srmc_Drv_ConfigCoreLockupReset(uint32 Enable)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_CTRL.LOCKUP_RST_EN = (uint32)(Enable & SRMC_DRV_ALLOW_STANDBY_MASK);
}

/**
 * @brief      Configs reset pin filter bus clock width.
 * @note       Actual reset pin bus clock filter width cycle = ClockCycles + 1.
 *
 * @param[in]  ClockCycles: Number of Clock cycles.
 *
 * @return     None
 *
 */
static void Srmc_Drv_ConfigResetPinFilterBusClock(uint32 ClockCycles)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_CTRL.RSTFLTSEL = (uint32)ClockCycles & 0x1FUL;
}

/**
 * @brief      Configs reset pin filter in stop mode.
 *
 * @param[in]  FilterType: Reset pin filter in stop mode.
 *
 * @return     None
 *
 */
static void Srmc_Drv_ConfigResetPinFilterInStopMode(Srmc_Drv_ResetPinFilterType FilterType)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_CTRL.RSTFLTSS = ((uint32)FilterType >> 1U) & 0x01U;
}

/**
 * @brief      Configs reset pin filter in run and wait modes.
 *
 * @param[in]  FilterType: Reset pin filter in run and wait modes.
 *
 * @return     None
 *
 */
static void Srmc_Drv_ConfigResetPinFilterInNormalMode(Srmc_Drv_ResetPinFilterType FilterType)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_CTRL.RSTFLTSRW = (uint32)FilterType;
}

/**
 * @brief      Configs system reset interrupts.
 *
 * @param[in]  Enable: Settings of SRMC interrupt.
 *
 * @return     None
 *
 */
static void Srmc_Drv_ConfigSysResetInterrupt(uint32 Enable)
{
    uint32 EnableMask = 0U;

    EnableMask = Enable & SRMC_DRV_INTERRUPT_ENABLE_MASK;

    if (0x0U != EnableMask)
    {
        Srmc_Drv_SrmcRegWPtr->SRMC_SRIE =
            (Srmc_Drv_SrmcRegWPtr->SRMC_SRIE & (~SRMC_DRV_INTERRUPT_ENABLE_MASK)) | EnableMask;

        Srmc_Drv_SrmcRegBfPtr->SRMC_SRIE.GIE = 1U;
    }
    else
    {
        Srmc_Drv_SrmcRegWPtr->SRMC_SRIE =
            Srmc_Drv_SrmcRegWPtr->SRMC_SRIE & (~SRMC_DRV_INTERRUPT_ENABLE_MASK);

        Srmc_Drv_SrmcRegBfPtr->SRMC_SRIE.GIE = 0U;
    }
}

/**
 * @brief      Configs max reset delay time(LPO cycles).
 *
 * @param[in]  DelayTime: Maximum reset delay time.
 *
 * @return     None
 *
 */
static void Srmc_Drv_ConfigMaxResetDelayTime(Srmc_Drv_DelayType DelayTime)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_SRIE.DELAY = (uint32)DelayTime;
}

/**
 * @brief      Configs allowed to enter into standby mode.
 *
 * @param[in]  Enable: Allow or not to enter into standby mode.
 *
 * @return     None
 *
 */
static void Srmc_Drv_ConfigStandbyModeState(uint32 Enable)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_PMPORT.APD = (uint32)Enable;
}

/**
 * @brief      Enters into wait mode.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Srmc_Drv_EnterWaitMode(void)
{
    Srmc_Drv_ScbRegPtr->SCR &= (~Z20_SCB_SCR_SLEEPDEEP_MASK);

    EXECUTE_WAIT();
}

/**
 * @brief      Configs how many LPO cycles reached and no acknowledge received will cause time out
 *             reset.
 *
 * @param[in]  AckTimeout: LPO cycles to time out reset if no acknowledge received.
 *
 * @return     None
 *
 */
static void Srmc_Drv_ConfigStopModeAckTimeout(uint32 AckTimeout)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_PMCTRL.DSMACKTMO = (uint32)AckTimeout;
}

/**
 * @brief      Enters standby mode.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Srmc_Drv_EnterStandbyMode(void)
{   
    Srmc_Drv_SrmcRegBfPtr->SRMC_PMCTRL.DSMC = 3U;

    Srmc_Drv_ScbRegPtr->SCR |= Z20_SCB_SCR_SLEEPDEEP_MASK;

    EXECUTE_WAIT();
}

/**
 * @brief      Enters stop mode(deep sleep mode).
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Srmc_Drv_EnterStopMode(void)
{
    Srmc_Drv_SrmcRegBfPtr->SRMC_PMCTRL.DSMC = 2U;

    Srmc_Drv_ScbRegPtr->SCR |= Z20_SCB_SCR_SLEEPDEEP_MASK;

    EXECUTE_WAIT();
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief      Gets current MCU mode.
 *
 * @param[in]  None
 *
 * @return     Srmc_Drv_PowerModeType: Current MCU mode.
 *
 */
Srmc_Drv_PowerModeType Srmc_Drv_GetCurrentPowerMode(void)
{
    Srmc_Drv_PowerModeType RetPowerMode;
    uint8                  Pm = (uint8)Srmc_Drv_SrmcRegBfPtr->SRMC_PMSTAT.PMSTAT;

    switch (Pm)
    {
        case 1U:
            RetPowerMode = SRMC_DRV_MODE_RUN;
            break;

        case 2U:
            RetPowerMode = SRMC_DRV_MODE_WAIT;
            break;

        case 4U:
            RetPowerMode = SRMC_DRV_MODE_STOP;
            break;

        case 8U:
            RetPowerMode = SRMC_DRV_MODE_STANDBY;
            break;

        default:
            RetPowerMode = SRMC_DRV_MODE_RUN;
            break;
    }

    return RetPowerMode;
}

/**
 * @brief      Initializes reset configuration of SRMC module.
 *
 * @param[in]  ConfigPtr: Pointer to SRMC Reset configuration.
 *
 * @return     None
 *
 */
void Srmc_Drv_InitResetConfiguration(const Srmc_Drv_ResetConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        /* Configure Reset Pin Filter In Normal Mode  */
        Srmc_Drv_ConfigResetPinFilterInNormalMode(ConfigPtr->ResetPinFilterInNormal);
        /* Configure Reset Pin Filter In Stop Mode  */
        Srmc_Drv_ConfigResetPinFilterInStopMode(ConfigPtr->ResetPinFilterInStop);
        /* Configure Reset Pin Filter Bus Clock  */
        Srmc_Drv_ConfigResetPinFilterBusClock(ConfigPtr->ResetPinFilterBusClock);
        /* Configure Core Lockup Reset Enable  */
        Srmc_Drv_ConfigCoreLockupReset((uint32)ConfigPtr->CoreLockupResetEnable);
        /* Configure Reset Delay Time  */
        Srmc_Drv_ConfigMaxResetDelayTime(ConfigPtr->ResetDelayTime);
        /* Configure Interrupt Enable  */
        Srmc_Drv_ConfigSysResetInterrupt(ConfigPtr->ResetInterruptEnable);
    }
}

/**
 * @brief      Initializes power mode configuration of SRMC module.
 *
 * @param[in]  ConfigPtr: Pointer to SRMC Power mode configuration.
 *
 * @return     None
 *
 */
void Srmc_Drv_InitPowerMode(const Srmc_Drv_PowerModeConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        /* Configure Allow Standby Mode  */
        Srmc_Drv_ConfigStandbyModeState((uint32)ConfigPtr->AllowStandbyMode);
        /* Configure Stop Mode Acknowledge Timeout  */
        Srmc_Drv_ConfigStopModeAckTimeout((uint32)ConfigPtr->StopModeAckTimeout);
        /* Configure Wakeup Control Configure for Standby Mode  */
        Srmc_Drv_ConfigPowerModeWakeupSrc((uint32)ConfigPtr->WakeupControl1,
                                          (uint32)ConfigPtr->WakeupControl2);
    }
}

/**
 * @brief      Reads reset reason value from SRMC module.
 *
 * @param[in]  None
 *
 * @return     uint32: Reset reason value.
 *
 */
/* SWS_Mcu_00006 */
uint32 Srmc_Drv_GetResetReasonValue(void)
{
    uint32 ResetValue;

    ResetValue = Srmc_Drv_SrmcRegWPtr->SRMC_SRS & SRMC_DRV_RESET_CAUSE_MASK;

    if ((uint32)0x00U != ResetValue)
    {
        Srmc_Drv_SrmcRegWPtr->SRMC_SSRS = ResetValue & SRMC_DRV_RESET_CAUSE_MASK;
    }
    else
    {
        /* Do nothing */
    }

    return ResetValue;
}

/**
 * @brief      Reads reset interrupt configuration.
 *
 * @param[in]  None
 *
 * @return     uint32: Settings of reset interrupt configuration.
 *
 */
uint32 Srmc_Drv_GetSysResetInterruptConfig(void)
{
    uint32 InterruptSetting;

    InterruptSetting = Srmc_Drv_SrmcRegWPtr->SRMC_SRIE & SRMC_DRV_INTERRUPT_ENABLE_MASK;

    return InterruptSetting;
}

/**
 * @brief      Sets reset interrupts in SRMC.
 *
 * @param[in]  ResetInterruptConfig: Settings of reset interrupt configuration.
 *
 * @return     None
 *
 */
void Srmc_Drv_SetSysResetInterruptConfig(uint32 ResetInterruptConfig)
{
    Srmc_Drv_ConfigSysResetInterrupt(ResetInterruptConfig);
}

/**
 * @brief      Sets MCU mode.
 *
 * @param[in]  PowerMode: MCU power mode.
 *
 * @return     None
 *
 */
void Srmc_Drv_SetMode(const Srmc_Drv_PowerModeType PowerMode)
{
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    Srmc_Drv_PowerModeType CurrentPowerMode = SRMC_DRV_MODE_RUN;

    CurrentPowerMode = Srmc_Drv_GetCurrentPowerMode();

    switch (PowerMode)
    {
        case (SRMC_DRV_MODE_RUN):
        {
            /* Set RUN mode */

            break;
        }
        case (SRMC_DRV_MODE_WAIT):
        {
            if (SRMC_DRV_MODE_RUN == CurrentPowerMode)
            {
                /* Set WAIT mode. */
                Srmc_Drv_EnterWaitMode();
            }
            else
            {
                /* Do nothing */
            }

            break;
        }
        case (SRMC_DRV_MODE_STOP):
        {
            if (SRMC_DRV_MODE_RUN == CurrentPowerMode)
            {
                /* Set STOP mode. */
                Srmc_Drv_EnterStopMode();
            }
            else
            {
                /* Do nothing */
            }

            break;
        }
        case (SRMC_DRV_MODE_STANDBY):
        {
            if (SRMC_DRV_MODE_RUN == CurrentPowerMode)
            {
                /* Set STANDBY mode. */
                Srmc_Drv_EnterStandbyMode();
            }
            else
            {
                /* Do nothing */
            }

            break;
        }
        default:
        {
            /*Only the above modes are allowed when this function is called*/
            break;
        }
    }
}

/**
 * @brief      Configs wakeup sources in SRMC.
 *
 * @param[in]  WakeupSource: Given wakeup source.
 * @param[in]  Enable: Enable/disable this source to wakeup the MCU.
 *
 * @return     None
 *
 */
void Srmc_Drv_SetWakeupSource(Srmc_Drv_WakeupSourceType WakeupSource, boolean Enable)
{
    uint8 Leftshift = (uint8)WakeupSource;

    if (FALSE == Enable)
    {
        if (SRMC_DRV_WUPSRC_RTC == WakeupSource)
        {
            Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC2 = Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC2 & (~(0x1UL));
        }
        else
        {
            Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 =
                Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 & (~(0x1UL << Leftshift));
        }
    }
    else
    {
        if (SRMC_DRV_WUPSRC_RTC == WakeupSource)
        {
            Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC2 = Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC2 | (0x1UL);
        }
        else
        {
            Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 =
                Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 | (0x1UL << Leftshift);
        }
    }
}

/**
 * @brief      Configs the polarity of given source to wakeup the MCU.
 *
 * @param[in]  WakeupSource: Given wakeup source.
 * @param[in]  ActivePolarity: Wakeup MCU if polarity low or high.
 *
 * @return     None
 *
 */
void Srmc_Drv_ConfigWakeupSource(Srmc_Drv_WakeupSourceType WakeupSource,
                                 Srmc_Drv_WupPolarityType  ActivePolarity)
{
    uint8 Leftshift = (uint8)WakeupSource;

    if (14U >= (uint8)WakeupSource)
    {
        if (SRMC_DRV_WUPSRC_POLARITY_LOW == ActivePolarity)
        {
            Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 =
                Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 & (~(0x10000UL << Leftshift));
        }
        else
        {
            Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 =
                Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPC1 | (0x10000UL << Leftshift);
        }
    }
}

/**
 * @brief      Gets whether the given source is enabled or not to wakeup the MCU.
 *
 * @param[in]  WakeupSource: Given wakeup source.
 *
 * @return     boolean
 * @retval     TRUE:  Given wakeup source is enabled to wakeup the MCU.
 * @retval     FALSE: Given wakeup source is not enabled to wakeup the MCU.
 *
 */
boolean Srmc_Drv_GetWakeupSourceStatus(Srmc_Drv_WakeupSourceType WakeupSource)
{
    uint8   Leftshift = (uint8)WakeupSource;
    boolean ReturnStatus;

    if (0UL == (Srmc_Drv_SrmcRegWPtr->SRMC_DSMWUPS & (0x1UL << Leftshift)))
    {
        ReturnStatus = FALSE;
    }
    else
    {
        ReturnStatus = TRUE;
    }

    return ReturnStatus;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Srmc_Drv */

/** @} end of group Mcu_Module */
