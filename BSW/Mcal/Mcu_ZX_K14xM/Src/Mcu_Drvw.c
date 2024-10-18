/**************************************************************************************************/
/**
 * @file      : Mcu_Drvw.c
 * @brief     : AUTOSAR Mcu driver wrapper source file
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

/** @addtogroup Mcu_Drvw
 *  @brief Mcu middle level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Drvw.h"
#include "Scc_Drv.h"
#include "Parcc_Drv.h"
#include "Pmu_Drv.h"
#include "Ram_Drv.h"
#include "Scm_Mcu_Drv.h"
#include "Srmc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define MCU_DRVW_C_VENDOR_ID                   0x00B3U
#define MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define MCU_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define MCU_DRVW_C_SW_MAJOR_VERSION            1U
#define MCU_DRVW_C_SW_MINOR_VERSION            2U
#define MCU_DRVW_C_SW_PATCH_VERSION            1U

/* Check if current file and Mcu_Drvw.h file are of the same vendor */
#if (MCU_DRVW_C_VENDOR_ID != MCU_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Autosar version */
#if ((MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != MCU_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (MCU_DRVW_C_AR_RELEASE_MINOR_VERSION != MCU_DRVW_H_AR_RELEASE_MINOR_VERSION) ||               \
     (MCU_DRVW_C_AR_RELEASE_REVISION_VERSION != MCU_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Software version */
#if ((MCU_DRVW_C_SW_MAJOR_VERSION != MCU_DRVW_H_SW_MAJOR_VERSION) ||                               \
     (MCU_DRVW_C_SW_MINOR_VERSION != MCU_DRVW_H_SW_MINOR_VERSION) ||                               \
     (MCU_DRVW_C_SW_PATCH_VERSION != MCU_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same vendor */
#if (MCU_DRVW_C_VENDOR_ID != SCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.c and Scc_Drv.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != SCC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                \
     (MCU_DRVW_C_AR_RELEASE_MINOR_VERSION != SCC_DRV_H_AR_RELEASE_MINOR_VERSION) ||                \
     (MCU_DRVW_C_AR_RELEASE_REVISION_VERSION != SCC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.c and Scc_Drv.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same Software version */
#if ((MCU_DRVW_C_SW_MAJOR_VERSION != SCC_DRV_H_SW_MAJOR_VERSION) ||                                \
     (MCU_DRVW_C_SW_MINOR_VERSION != SCC_DRV_H_SW_MINOR_VERSION) ||                                \
     (MCU_DRVW_C_SW_PATCH_VERSION != SCC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.c and Scc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same vendor */
#if (MCU_DRVW_C_VENDOR_ID != PARCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != PARCC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||              \
     (MCU_DRVW_C_AR_RELEASE_MINOR_VERSION != PARCC_DRV_H_AR_RELEASE_MINOR_VERSION) ||              \
     (MCU_DRVW_C_AR_RELEASE_REVISION_VERSION != PARCC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Software version */
#if ((MCU_DRVW_C_SW_MAJOR_VERSION != PARCC_DRV_H_SW_MAJOR_VERSION) ||                              \
     (MCU_DRVW_C_SW_MINOR_VERSION != PARCC_DRV_H_SW_MINOR_VERSION) ||                              \
     (MCU_DRVW_C_SW_PATCH_VERSION != PARCC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same vendor */
#if (MCU_DRVW_C_VENDOR_ID != PMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != PMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                \
     (MCU_DRVW_C_AR_RELEASE_MINOR_VERSION != PMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                \
     (MCU_DRVW_C_AR_RELEASE_REVISION_VERSION != PMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Software version */
#if ((MCU_DRVW_C_SW_MAJOR_VERSION != PMU_DRV_H_SW_MAJOR_VERSION) ||                                \
     (MCU_DRVW_C_SW_MINOR_VERSION != PMU_DRV_H_SW_MINOR_VERSION) ||                                \
     (MCU_DRVW_C_SW_PATCH_VERSION != PMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same vendor */
#if (MCU_DRVW_C_VENDOR_ID != RAM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != RAM_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                \
     (MCU_DRVW_C_AR_RELEASE_MINOR_VERSION != RAM_DRV_H_AR_RELEASE_MINOR_VERSION) ||                \
     (MCU_DRVW_C_AR_RELEASE_REVISION_VERSION != RAM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Software version */
#if ((MCU_DRVW_C_SW_MAJOR_VERSION != RAM_DRV_H_SW_MAJOR_VERSION) ||                                \
     (MCU_DRVW_C_SW_MINOR_VERSION != RAM_DRV_H_SW_MINOR_VERSION) ||                                \
     (MCU_DRVW_C_SW_PATCH_VERSION != RAM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.c and Ram_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same vendor */
#if (MCU_DRVW_C_VENDOR_ID != SCM_MCU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != SCM_MCU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||            \
     (MCU_DRVW_C_AR_RELEASE_MINOR_VERSION != SCM_MCU_DRV_H_AR_RELEASE_MINOR_VERSION) ||            \
     (MCU_DRVW_C_AR_RELEASE_REVISION_VERSION != SCM_MCU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Software version */
#if ((MCU_DRVW_C_SW_MAJOR_VERSION != SCM_MCU_DRV_H_SW_MAJOR_VERSION) ||                            \
     (MCU_DRVW_C_SW_MINOR_VERSION != SCM_MCU_DRV_H_SW_MINOR_VERSION) ||                            \
     (MCU_DRVW_C_SW_PATCH_VERSION != SCM_MCU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same vendor */
#if (MCU_DRVW_C_VENDOR_ID != SRMC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != SRMC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (MCU_DRVW_C_AR_RELEASE_MINOR_VERSION != SRMC_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (MCU_DRVW_C_AR_RELEASE_REVISION_VERSION != SRMC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Software version */
#if ((MCU_DRVW_C_SW_MAJOR_VERSION != SRMC_DRV_H_SW_MAJOR_VERSION) ||                               \
     (MCU_DRVW_C_SW_MINOR_VERSION != SRMC_DRV_H_SW_MINOR_VERSION) ||                               \
     (MCU_DRVW_C_SW_PATCH_VERSION != SRMC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw.c and Srmc_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/**
 * @brief  Type of mapping table of wakeup source in driver layer and wrapper layer.
 */
typedef struct
{
    Srmc_Drv_WakeupSourceType DrvWakeupSource;
    Mcu_Drvw_WakeupSourceType DrvwWakeupSource;
} Mcu_Drvw_WakeupSourceTableType;

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* clang-format off */
static const Mcu_Drvw_WakeupSourceTableType Mcu_Drvw_WakeupSourceTable[] = 
{
    {SRMC_DRV_WUPSRC_PTD0,  MCU_DRVW_WUPSRC_PTD0},
    {SRMC_DRV_WUPSRC_PTD1,  MCU_DRVW_WUPSRC_PTD1},
    {SRMC_DRV_WUPSRC_PTA4,  MCU_DRVW_WUPSRC_PTA4},
    {SRMC_DRV_WUPSRC_PTC4,  MCU_DRVW_WUPSRC_PTC4},
    {SRMC_DRV_WUPSRC_PTC5,  MCU_DRVW_WUPSRC_PTC5},
    {SRMC_DRV_WUPSRC_PTE0,  MCU_DRVW_WUPSRC_PTE0},
    {SRMC_DRV_WUPSRC_PTE1,  MCU_DRVW_WUPSRC_PTE1},
    {SRMC_DRV_WUPSRC_PTE11, MCU_DRVW_WUPSRC_PTE11},
    {SRMC_DRV_WUPSRC_PTE13, MCU_DRVW_WUPSRC_PTE13},
    {SRMC_DRV_WUPSRC_PTE15, MCU_DRVW_WUPSRC_PTE15},
    {SRMC_DRV_WUPSRC_PTE16, MCU_DRVW_WUPSRC_PTE16},
    {SRMC_DRV_WUPSRC_PTA8,  MCU_DRVW_WUPSRC_PTA8},
    {SRMC_DRV_WUPSRC_PTA9,  MCU_DRVW_WUPSRC_PTA9},
    {SRMC_DRV_WUPSRC_PTA25, MCU_DRVW_WUPSRC_PTA25},
    {SRMC_DRV_WUPSRC_PMU,   MCU_DRVW_WUPSRC_PMU},
    {SRMC_DRV_WUPSRC_RTC,   MCU_DRVW_WUPSRC_RTC}
};

/* clang-format on */

#define MCU_STOP_SEC_CONST_UNSPECIFIED
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

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief     Initializes SRMC, SCM and PMU modules.
 *
 * @param[in] HwConfigPtr: Pointer to configuration of SRMC, SCM and PMU modules.
 *
 * @return    None
 *
 */
void Mcu_Drvw_Init(const Mcu_Drvw_HwConfigType *HwConfigPtr)
{
    if (NULL_PTR != HwConfigPtr)
    {
        Pmu_Drv_ClearIsolationClear();
#if (MCU_DRVW_DISABLE_SRMC_INIT == STD_OFF)
        Srmc_Drv_InitResetConfiguration(HwConfigPtr->SrmcResetConfigPtr);
        Srmc_Drv_InitPowerMode(HwConfigPtr->SrmcPowerModeConfigPtr);
#endif

#if (MCU_DRVW_DISABLE_SCM_INIT == STD_OFF)
        Scm_Mcu_Drv_Init(HwConfigPtr->ScmConfigPtr);
#endif

#if (MCU_DRVW_DISABLE_PMU_INIT == STD_OFF)
        Pmu_Drv_Init(HwConfigPtr->PmuConfigPtr);
#endif
    }
}

#ifndef MCU_DRVW_MAX_NORAMCONFIGS
/**
 * @brief     Initializes a given RAM section.
 *
 * @param[in] RamConfigPtr: Pointer to RAM section configuration.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     RAM section initialized success.
 * @retval    E_NOT_OK: RAM section initialized failed, e.g. given parameters are invalid.
 *
 */
Std_ReturnType Mcu_Drvw_InitRamSection(const Ram_Drv_ConfigType *RamConfigPtr)
{
    Std_ReturnType RamStatus = E_NOT_OK;

    if (NULL_PTR != RamConfigPtr)
    {
        switch (Ram_Drv_Init(RamConfigPtr))
        {
            case RAM_DRV_STATUS_OK:
                RamStatus = E_OK;
                break;
            case RAM_DRV_STATUS_NOT_OK:
            case RAM_DRV_STATUS_UNDEFINED:
                RamStatus = E_NOT_OK;
                break;
            default:
                /* Do nothing */
                break;
        }
    }

    return RamStatus;
}
#endif /* ifndef MCU_DRVW_MAX_NORAMCONFIGS */

#if (MCU_DRVW_INIT_CLOCK == STD_ON)
/**
 * @brief     Initializes the clock.
 *
 * @param[in] ClockConfigPtr: Pointer to clock configuration.
 *
 * @return    None
 *
 */
void Mcu_Drvw_InitClock(const Mcu_Drvw_ClockConfigType *ClockConfigPtr)
{
    if (NULL_PTR != ClockConfigPtr)
    {
        Scc_Drv_ConfigSccClock(ClockConfigPtr->SccClockConfigPtr);

        Scm_Mcu_Drv_InitClockOut(ClockConfigPtr->ScmClockConfigPtr);

        /* SWS_Mcu_00138 */
        Parcc_Drv_Init(ClockConfigPtr->ParccConfigPtr);
    }
}
#endif /* (MCU_DRVW_INIT_CLOCK == STD_ON) */

#if (MCU_DRVW_NO_PLL == STD_OFF)
/**
 * @brief      Activates the main PLL as the system clock source.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_DistributePllClock(void)
{
    uint32 PllClockFreq = 0U;

    if (TRUE != Scc_Drv_GetPllClockSelectedState())
    {
        PllClockFreq = Scc_Drv_GetPllClockFreq();
        (void)Scc_Drv_SetSysClockSrc(SCC_DRV_SYS_CLOCK_PLL, PllClockFreq);
        Scm_Mcu_Drv_UpdateClockOut();
    }
}
#endif /* (MCU_DRVW_NO_PLL == STD_OFF) */

#if (MCU_DRVW_NO_PLL == STD_OFF)
/**
 * @brief      Gets PLL clock status.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  PLL is enabled and ready.
 * @retval     FALSE: PLL is not enabled or not ready.
 *
 */
boolean Mcu_Drvw_GetPllStatus(void)
{
    return Scc_Drv_GetPllClockStatus();
}
#endif /* (MCU_DRVW_NO_PLL == STD_OFF) */

/**
 * @brief      Sets MCU mode.
 *
 * @param[in]  PowerMode: Selected MCU power mode.
 *
 * @return     None
 *
 */
void Mcu_Drvw_SetMode(const Mcu_Drvw_PowerModeType PowerMode)
{
    switch (PowerMode)
    {
        case MCU_DRVW_POWERMODE_RUN:
            Srmc_Drv_SetMode(SRMC_DRV_MODE_RUN);
            break;
        case MCU_DRVW_POWERMODE_WAIT:
            Srmc_Drv_SetMode(SRMC_DRV_MODE_WAIT);
            break;
        case MCU_DRVW_POWERMODE_STOP:
            Srmc_Drv_SetMode(SRMC_DRV_MODE_STOP);
            break;
        case MCU_DRVW_POWERMODE_STANDBY:
            Srmc_Drv_SetMode(SRMC_DRV_MODE_STANDBY);
            break;
        default:
            /* Do nothing */
            break;
    }
}

#if (MCU_DRVW_POWERMODE_STATE_API == STD_ON)
/**
 * @brief      Gets current power mode.
 *
 * @param[in]  None
 *
 * @return     Mcu_Drvw_PowerModeType: Current power mode.
 *
 */
Mcu_Drvw_PowerModeType Mcu_Drvw_GetPowerModeState(void)
{
    Mcu_Drvw_PowerModeType PowerMode = MCU_DRVW_POWERMODE_RUN;

    switch (Srmc_Drv_GetCurrentPowerMode())
    {
        case SRMC_DRV_MODE_RUN:
            PowerMode = MCU_DRVW_POWERMODE_RUN;
            break;
        case SRMC_DRV_MODE_WAIT:
            PowerMode = MCU_DRVW_POWERMODE_WAIT;
            break;
        case SRMC_DRV_MODE_STOP:
            PowerMode = MCU_DRVW_POWERMODE_STOP;
            break;
        case SRMC_DRV_MODE_STANDBY:
            PowerMode = MCU_DRVW_POWERMODE_STANDBY;
            break;
        default:
            PowerMode = MCU_DRVW_POWERMODE_RUN;
            break;
    }

    return PowerMode;
}
#endif /*(MCU_DRVW_POWERMODE_STATE_API == STD_ON)*/

#if (MCU_DRVW_PERFORM_RESET_API == STD_ON)
/**
 * @brief      Performs a microcontroller reset.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_PerformReset(void)
{
    Sys_SystemReset();
}
#endif /* (MCU_DRVW_PERFORM_RESET_API == STD_ON) */

/**
 * @brief      Gets MCU reset reason.
 *
 * @param[in]  None
 *
 * @return     Mcu_Drvw_ResetType: Reset reason.
 *
 */
Mcu_Drvw_ResetType Mcu_Drvw_GetResetReason(void)
{
    Mcu_Drvw_ResetType ResetReason = MCU_DRVW_POWER_ON_RESET;
    uint8              Index = 0U;
    uint32             Tmp;
    uint8              ReasonNum = 0U;

    if ((uint32)SRMC_DRV_RESET_POR ==
        (Srmc_Drv_GetResetReasonValue() & (uint32)SRMC_DRV_RESET_POR))
    {
        ResetReason = MCU_DRVW_POWER_ON_RESET;
    }
    else
    {
        Tmp = Srmc_Drv_GetResetReasonValue() & (uint32)SRMC_DRV_RESET_ALL;
        for (Index = 0U; Index < 32U; ++Index)
        {
            if (0U != (Tmp & ((uint32)1U << Index)))
            {
                ResetReason = (Mcu_Drvw_ResetType)Index;
                ++ReasonNum;

                /* If there are more than two reset reasons, set reset reason with
                 * MCU_DRVW_MULTIPLE_RESET_REASON */
                if (ReasonNum >= 2U)
                {
                    ResetReason = MCU_DRVW_MULTIPLE_RESET_REASON;
                    break;
                }
            }
        }
    }

    return ResetReason;
}

/**
 * @brief      Gets reset reason raw value.
 *
 * @param[in]  None
 *
 * @return     uint32: reset reason raw value.
 *
 */
uint32 Mcu_Drvw_GetResetRawValue(void)
{
    return Srmc_Drv_GetResetReasonValue();
}

/**
 * @brief      Enables OSC clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Mcu_Drvw_EnableOscClockMonitor(Mcu_Drvw_OscClockLossActType Act)
{
    if (MCU_DRVW_OSC_CLOCK_LOSS_INT == Act)
    {
        Scc_Drv_EnableOscClockMonitor(SCC_DRV_OSC_CLOCK_LOSS_INT);
    }
    else if (MCU_DRVW_OSC_CLOCK_LOSS_RST == Act)
    {
        Scc_Drv_EnableOscClockMonitor(SCC_DRV_OSC_CLOCK_LOSS_RST);
    }
    else
    {
        /* Do nothing */
    }
}

/**
 * @brief      Disables OSC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_DisableOscClockMonitor(void)
{
    Scc_Drv_DisableOscClockMonitor();
}

/**
 * @brief      Enables FIRC64M clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Mcu_Drvw_EnableFirc64MClockMonitor(Mcu_Drvw_Firc64MClockLossActType Act)
{
    if (MCU_DRVW_FIRC64M_CLOCK_LOSS_INT == Act)
    {
        Scc_Drv_EnableFirc64MClockMonitor(SCC_DRV_FIRC64M_CLOCK_LOSS_INT);
    }
    else if (MCU_DRVW_FIRC64M_CLOCK_LOSS_RST == Act)
    {
        Scc_Drv_EnableFirc64MClockMonitor(SCC_DRV_FIRC64M_CLOCK_LOSS_RST);
    }
    else
    {
        /* Do nothing */
    }
}

/**
 * @brief      Disables FIRC64M clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_Drvw_DisableFirc64MClockMonitor(void)
{
    Scc_Drv_DisableFirc64MClockMonitor();
}

#if (MCU_DRVW_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 * @brief      Enables PLL clock monitor.
 *
 * @param[in]  Act: Action when loss of clock is detected, reset/interrupt.
 *
 * @return     None
 *
 */
void Mcu_Drvw_EnablePllClockMonitor(Mcu_Drvw_PllClockLossActType Act)
{
    if (MCU_DRVW_PLL_CLOCK_LOSS_INT == Act)
    {
        Scc_Drv_EnablePllClockMonitor(SCC_DRV_PLL_CLOCK_LOSS_INT);
    }
    else if (MCU_DRVW_PLL_CLOCK_LOSS_RST == Act)
    {
        Scc_Drv_EnablePllClockMonitor(SCC_DRV_PLL_CLOCK_LOSS_RST);
    }
    else
    {
        /* Do nothing */
    }
}
#endif

/**
 * @brief      Configs wakeup source.
 *
 * @param[in]  WakeupSource: Wakeup source.
 * @param[in]  ActiveHigh: Wakeup MCU if polarity is high.
 * @param[in]  Enable: Enable/disable.
 *
 * @return     None
 *
 */
void Mcu_Drvw_SetWakeupSource(Mcu_Drvw_WakeupSourceType WakeupSource, boolean ActiveHigh,
                              boolean Enable)
{
    uint8  Index = 0U;
    uint32 TableSize = sizeof(Mcu_Drvw_WakeupSourceTable) / sizeof(Mcu_Drvw_WakeupSourceTable[0]);

    for (Index = 0U; Index < TableSize; ++Index)
    {
        if (Mcu_Drvw_WakeupSourceTable[Index].DrvwWakeupSource == WakeupSource)
        {
            Srmc_Drv_SetWakeupSource(Mcu_Drvw_WakeupSourceTable[Index].DrvWakeupSource, Enable);
            Srmc_Drv_ConfigWakeupSource(Mcu_Drvw_WakeupSourceTable[Index].DrvWakeupSource,
                                        (Srmc_Drv_WupPolarityType)ActiveHigh);
            break;
        }
    }
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
boolean Mcu_Drvw_GetClockReadyState(Mcu_Drvw_ClockSrcType ClockSource)
{
    return Scc_Drv_GetClockReadyState((Scc_Drv_ClockSrcType)ClockSource);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Mcu_Drvw */

/** @} end of group Mcu_Module */
