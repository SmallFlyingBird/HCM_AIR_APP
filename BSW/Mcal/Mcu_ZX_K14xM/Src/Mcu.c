/**************************************************************************************************/
/**
 * @file      : Mcu.c
 * @brief     : AUTOSAR Mcu driver source file
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

/** @addtogroup Mcu
 *  @brief Mcu high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu.h"
#include "Mcu_Drvw.h"
#include "SchM_Mcu.h"

#if (MCU_E_CLOCK_FAILURE_ENABLE == STD_ON)
    #include "Dem.h"
#endif

#include "Det.h"

#if (MCU_HW_TEST_ENABLED == STD_ON)
    #include "Mstp.h"
#endif /* (MCU_HW_TEST_ENABLED == STD_ON) */

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define MCU_C_VENDOR_ID                   0x00B3U
#define MCU_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_C_AR_RELEASE_MINOR_VERSION    6U
#define MCU_C_AR_RELEASE_REVISION_VERSION 0U
#define MCU_C_SW_MAJOR_VERSION            1U
#define MCU_C_SW_MINOR_VERSION            2U
#define MCU_C_SW_PATCH_VERSION            1U

/* Check if current file and Mcu.h file are of the same vendor */
#if (MCU_C_VENDOR_ID != MCU_VENDOR_ID)
    #error "Vendor ID of Mcu.c and Mcu.h are different"
#endif

/* Check if current file and Mcu.h file are of the same Autosar version */
#if ((MCU_C_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) ||                           \
     (MCU_C_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION) ||                           \
     (MCU_C_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu.c and Mcu.h are different"
#endif

/* Check if current file and Mcu.h file are of the same Software version */
#if ((MCU_C_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION) ||                                           \
     (MCU_C_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION) ||                                           \
     (MCU_C_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION))
    #error "Software Version of Mcu.c and Mcu.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same vendor */
#if (MCU_C_VENDOR_ID != MCU_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Mcu.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Autosar version */
#if ((MCU_C_AR_RELEASE_MAJOR_VERSION != MCU_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (MCU_C_AR_RELEASE_MINOR_VERSION != MCU_DRVW_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (MCU_C_AR_RELEASE_REVISION_VERSION != MCU_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Software version */
#if ((MCU_C_SW_MAJOR_VERSION != MCU_DRVW_H_SW_MAJOR_VERSION) ||                                    \
     (MCU_C_SW_MINOR_VERSION != MCU_DRVW_H_SW_MINOR_VERSION) ||                                    \
     (MCU_C_SW_PATCH_VERSION != MCU_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu.c and Mcu_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (MCU_HW_TEST_ENABLED == STD_ON)
        /* Check if current file and Mstp.h file are of the same Autosar version */
        #if ((MCU_C_AR_RELEASE_MAJOR_VERSION != MSTP_AR_RELEASE_MAJOR_VERSION) ||                  \
             (MCU_C_AR_RELEASE_MINOR_VERSION != MSTP_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Mcu.c and Mstp.h are different"
        #endif
    #endif /* (MCU_HW_TEST_ENABLED == STD_ON) */

    /* Check if current file and Det.h file are of the same Autosar version */
    #if ((MCU_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                       \
         (MCU_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Mcu.c and Det.h are different"
    #endif

    #if (MCU_E_CLOCK_FAILURE_ENABLE == STD_ON)
        /* Check if current file and Dem.h are the same Autosar version */
        #if ((MCU_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) ||                   \
             (MCU_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Mcu.c and Dem.h are different"
        #endif
    #endif

    #if ((MCU_C_AR_RELEASE_MAJOR_VERSION != SCHM_MCU_H_AR_RELEASE_MAJOR_VERSION) ||                \
         (MCU_C_AR_RELEASE_MINOR_VERSION != SCHM_MCU_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Mcu.c and SchM_Mcu.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define MCU_PARAM_UNUSED(param) ((void)((param)))

/* SWS_Mcu_00017 */
#define MCU_PARAM_CHECK (MCU_DEV_ERROR_DETECT)

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/**
 * @brief  Type of MCU driver's states.
 */
typedef enum
{
    MCU_UNINIT = 0x00U, /*!< The Mcu driver is not uninitialized. */
    MCU_READY,          /*!< The Mcu driver is initialized. */
} Mcu_StatusType;

/**
 * @brief  Type of mapping table of reset reasons in autosar interface layer and wrapper layer.
 */
typedef struct
{
    Mcu_Drvw_ResetType DrvwResetReason;
    Mcu_ResetType      ResetReason;
} Mcu_ResetReasonTableType;

/**
 * @brief  Type of mapping table of wake up source in autosar interface layer and wrapper layer.
 */
typedef struct
{
    Mcu_Drvw_WakeupSourceType DrvwWakeupSource;
    Mcu_WakeupSourceType      WakeupSource;
} Mcu_WakeupSourceTableType;

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_VAR_CLEARED_8
#include "Mcu_MemMap.h"

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief            Array for saving the Clock configuration Ids.
 */
static uint8 Mcu_ClockConfigIds[MCU_MAX_CLKCONFIGS];

#endif /* ( MCU_INIT_CLOCK == STD_ON ) */
/**
 * @brief            Array for saving the Mode configuration Ids.
 */
static uint8 Mcu_ModeConfigIds[MCU_MAX_MODECONFIGS];

/**
 * @brief            Array for saving the Ram sectors configuration Ids.
 *                   If no ramConfig is defined, remove all usages of that array
 */

#ifndef MCU_MAX_NORAMCONFIGS
static uint8 Mcu_RamConfigIds[MCU_MAX_RAMCONFIGS];
#endif

#define MCU_STOP_SEC_VAR_CLEARED_8
#include "Mcu_MemMap.h"

#if (MCU_INIT_CLOCK == STD_ON)
    #define MCU_START_SEC_VAR_CLEARED_PTR
    #include "Mcu_MemMap.h"

/**
 * @brief            Array for saving the Clock configuration Ids.
 */
static const Mcu_Drvw_ClockConfigType *Mcu_ClockConfigPtr;

    #define MCU_STOP_SEC_VAR_CLEARED_PTR
    #include "Mcu_MemMap.h"
#endif /* ( MCU_INIT_CLOCK == STD_ON ) */

#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

#if (MCU_PARAM_CHECK == STD_ON)
/**
 *  @brief Variable that indicates the state of the driver.
 */
static Mcu_StatusType Mcu_Status = MCU_UNINIT;
#endif /* (MCU_PARAM_CHECK == STD_ON) */

#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_PTR
#include "Mcu_MemMap.h"

static const Mcu_ConfigType *Mcu_ConfigPtr = NULL_PTR;

#define MCU_STOP_SEC_VAR_INIT_PTR
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* clang-format off */
static const Mcu_ResetReasonTableType Mcu_ResetReasonTable[] = 
{
    {MCU_DRVW_WAKEUP_RESET,          MCU_WAKEUP_RESET},
    {MCU_DRVW_LVD_RESET,             MCU_LVD_RESET},
    {MCU_DRVW_LOC_RESET,             MCU_LOC_RESET},
    {MCU_DRVW_WATCHDOG_RESET,        MCU_WATCHDOG_RESET},
    {MCU_DRVW_PIN_RESET,             MCU_PIN_RESET},
    {MCU_DRVW_POWER_ON_RESET,        MCU_POWER_ON_RESET},
    {MCU_DRVW_LOCKUP_RESET,          MCU_LOCKUP_RESET},
    {MCU_DRVW_SW_RESET,              MCU_SW_RESET},
    {MCU_DRVW_MDM_AP_RESET,          MCU_MDM_AP_RESET},
    {MCU_DRVW_SERU_COLD_RESET,       MCU_SERU_COLD_RESET},
    {MCU_DRVW_SERU_SYS_RESET,        MCU_SERU_SYS_RESET},
    {MCU_DRVW_SERU_SACKERR,          MCU_SERU_SACKERR},
    {MCU_DRVW_MULTIPLE_RESET_REASON, MCU_MULTIPLE_RESET_REASON},
    {MCU_DRVW_RESET_UNDEFINED,       MCU_RESET_UNDEFINED}
};

static const Mcu_WakeupSourceTableType Mcu_WakeupSourceTable[] = 
{
    {MCU_DRVW_WUPSRC_PTD0,  MCU_WUPSRC_PTD0},
    {MCU_DRVW_WUPSRC_PTD1,  MCU_WUPSRC_PTD1},
    {MCU_DRVW_WUPSRC_PTA4,  MCU_WUPSRC_PTA4},
    {MCU_DRVW_WUPSRC_PTC4,  MCU_WUPSRC_PTC4},
    {MCU_DRVW_WUPSRC_PTC5,  MCU_WUPSRC_PTC5},
    {MCU_DRVW_WUPSRC_PTE0,  MCU_WUPSRC_PTE0},
    {MCU_DRVW_WUPSRC_PTE1,  MCU_WUPSRC_PTE1},
    {MCU_DRVW_WUPSRC_PTE11, MCU_WUPSRC_PTE11},
    {MCU_DRVW_WUPSRC_PTE13, MCU_WUPSRC_PTE13},
    {MCU_DRVW_WUPSRC_PTE15, MCU_WUPSRC_PTE15},
    {MCU_DRVW_WUPSRC_PTE16, MCU_WUPSRC_PTE16},
    {MCU_DRVW_WUPSRC_PTA8,  MCU_WUPSRC_PTA8},
    {MCU_DRVW_WUPSRC_PTA9,  MCU_WUPSRC_PTA9},
    {MCU_DRVW_WUPSRC_PTA25, MCU_WUPSRC_PTA25},
    {MCU_DRVW_WUPSRC_PMU,   MCU_WUPSRC_PMU},
    {MCU_DRVW_WUPSRC_RTC,   MCU_WUPSRC_RTC}
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

#if (MCU_PARAM_CHECK == STD_ON)
/**
 * @brief      Checks validity of MCU configuration parameter.
 *
 * @param[in]  ConfigPtr: Pointer to the MCU configuration.
 *
 * @return     boolean
 * @retval     TRUE:  Configuration parameter is valid.
 * @retval     FALSE: Configuration parameter is invalid.
 */
static boolean Mcu_CheckInit(const Mcu_ConfigType *ConfigPtr)
{
    boolean CheckStatus = TRUE;

    #if (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    if (NULL_PTR == ConfigPtr)
    #else
    if (NULL_PTR != ConfigPtr)
    #endif
    {
        CheckStatus = FALSE;

        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT,
                              MCU_E_INIT_FAILED);
    }

    return CheckStatus;
}
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */

#ifndef MCU_MAX_NORAMCONFIGS
    #if (MCU_PARAM_CHECK == STD_ON)
/**
 * @brief      Checks validity of Ram sector id.
 *
 * @param[in]  RamSection: RAM sector id.
 *
 * @return     boolean
 * @retval     TRUE:  Ram sector id is valid.
 * @retval     FALSE: Ram sector id is invalid.
 *
 */
static boolean Mcu_CheckInitRamSection(Mcu_RamSectionType RamSection)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == Mcu_ConfigPtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_RAM_SECTION,
                              MCU_E_UNINIT);
    }
    else
    {
        /* Ram sector id is out of range. */
        if (RamSection >= Mcu_ConfigPtr->NoOfRamConfigs)
        {
            CheckStatus = FALSE;

            (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_RAM_SECTION,
                                  MCU_E_PARAM_RAMSECTION);
        }
        else
        {
            if (NULL_PTR == Mcu_ConfigPtr->RamConfigPtr)
            {
                CheckStatus = FALSE;

                (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                                      MCU_SID_INIT_RAM_SECTION, MCU_E_PARAM_RAMSECTION);
            }
            else
            {
                /* Ram write size is invalid. */
                if ((1U !=
                     ((*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]]).RamWriteSize) &&
                    (2U !=
                     ((*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]]).RamWriteSize) &&
                    (4U !=
                     ((*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]]).RamWriteSize) &&
                    (8U !=
                     ((*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]]).RamWriteSize))
                {
                    CheckStatus = FALSE;

                    (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                                          MCU_SID_INIT_RAM_SECTION, MCU_E_PARAM_RAMSECTION);
                }
            }
        }
    }

    return CheckStatus;
}
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
#endif     /* ifndef MCU_MAX_NORAMCONFIGS */

#if ((MCU_INIT_CLOCK == STD_ON) && (MCU_PARAM_CHECK == STD_ON))
/**
 * @brief      Checks validity of clock id.
 *
 * @param[in]  ClockSetting: Clock id.
 *
 * @return     boolean
 * @retval     TRUE:  Clock id is valid.
 * @retval     FALSE: Clock id is invalid.
 *
 */
static boolean Mcu_CheckInitClock(Mcu_ClockType ClockSetting)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR != Mcu_ConfigPtr)
    {
        if (ClockSetting >= Mcu_ConfigPtr->NoOfClkConfigs)
        {
            CheckStatus = FALSE;

            (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_CLOCK,
                                  MCU_E_PARAM_CLOCK);
        }
    }
    else
    {
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif /* ((MCU_INIT_CLOCK == STD_ON) && (MCU_PARAM_CHECK == STD_ON)) */

#if ((MCU_NO_PLL == STD_OFF) && (MCU_PARAM_CHECK == STD_ON))
/**
 * @brief      Checks whether current PLL state is locked.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  PLL clock is in lock state.
 * @retval     FALSE: PLL clock is not in lock state.
 *
 */
static boolean Mcu_CheckDistributePllClock(void)
{
    boolean CheckStatus = TRUE;

    if (TRUE != Mcu_Drvw_GetPllStatus())
    {
        CheckStatus = FALSE;

        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_DISTRIBUTE_PLL_CLOCK,
                              MCU_E_PLL_NOT_LOCKED);
    }

    return CheckStatus;
}
#endif /* ((MCU_NO_PLL == STD_OFF) && (MCU_PARAM_CHECK == STD_ON))                                 \
        */

#if (MCU_PARAM_CHECK == STD_ON)
/**
 * @brief      Checks validity of MCU mode id.
 *
 * @param[in]  Mcu_ModeType: MCU mode id.
 *
 * @return     boolean
 * @retval     TRUE:  MCU mode id is valid.
 * @retval     FALSE: MCU mode id is not valid.
 *
 */
static boolean Mcu_CheckSetMode(Mcu_ModeType McuMode)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR != Mcu_ConfigPtr)
    {
        if (McuMode >= Mcu_ConfigPtr->NoOfModeConfigs)
        {
            CheckStatus = FALSE;

            (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_SET_MODE,
                                  MCU_E_PARAM_MODE);
        }
    }
    else
    {
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif /* (MCU_PARAM_CHECK == STD_ON) */

#if (MCU_PARAM_CHECK == STD_ON)
/**
 * @brief      Checks whether MCU has already initialized.
 *
 * @param[in]  McuServiceID: Service of MCU provided.
 *
 * @return     boolean
 * @retval     TRUE:  MCU has already been initialized.
 * @retval     FALSE: MCU has not been initialized.
 *
 */
static boolean Mcu_CheckMcuInitialized(uint8 McuServiceID)
{
    boolean CheckStatus = TRUE;

    if (MCU_UNINIT == Mcu_Status)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)McuServiceID,
                              MCU_E_UNINIT);
    }

    return CheckStatus;
}
#endif /* MCU_PARAM_CHECK == STD_ON  */

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
static boolean Mcu_GetClockReadyState(Mcu_Drvw_ClockSrcType ClockSource)
{
    return Mcu_Drvw_GetClockReadyState(ClockSource);
}

/**
 * @brief      Checks validity of enable FIRC64M clock monitor.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  Conditions to enable FIRC64M clock monitor are satisfied.
 * @retval     FALSE: Conditions to enable FIRC64M clock monitor are not satisfied.
 *
 */
static boolean Mcu_CheckEnableFircClockMonitor(void)
{
    boolean CheckStatus = TRUE;

    /* Only can enable FIRC clock monitor when LPO64 clock is ready */
    if (FALSE == Mcu_GetClockReadyState(MCU_DRVW_CLOCK_SRC_LPO32K))
    {
        CheckStatus = FALSE;
        (void)Det_ReportRuntimeError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                                     MCU_SID_ENABLE_FIRC_CLOCK_MONITOR, MCU_E_ENABLE_CLOCK_MONITOR);
    }

    return CheckStatus;
}

/**
 * @brief      Checks validity of enable OSC clock monitor.
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  Conditions to enable FOSC clock monitor are satisfied.
 * @retval     FALSE: Conditions to enable FOSC clock monitor are not satisfied.
 *
 */
static boolean Mcu_CheckEnableOscClockMonitor(void)
{
    boolean CheckStatus = TRUE;

    /* Only can enable FOSC clock monitor when FIRC clock is ready */
    if (FALSE == Mcu_GetClockReadyState(MCU_DRVW_CLOCK_SRC_FIRC64M))
    {
        CheckStatus = FALSE;
        (void)Det_ReportRuntimeError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                                     MCU_SID_ENABLE_OSC_CLOCK_MONITOR, MCU_E_ENABLE_CLOCK_MONITOR);
    }

    return CheckStatus;
}

/**
 * @brief      Stores configured mode ids.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Mcu_StoreConfiguredModeId(void)
{
    uint32 Index;

    if (NULL_PTR != Mcu_ConfigPtr)
    {
        for (Index = 0U; Index < Mcu_ConfigPtr->NoOfModeConfigs; ++Index)
        {
            Mcu_ModeConfigIds[(*Mcu_ConfigPtr->ModeConfigPtr)[Index].ModeConfigId] = (uint8)Index;
        }
    }
}

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief      Stores configured clock ids.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Mcu_StoreConfiguredClockId(void)
{
    uint32 Index;

    if (NULL_PTR != Mcu_ConfigPtr)
    {
        for (Index = 0U; Index < Mcu_ConfigPtr->NoOfClkConfigs; ++Index)
        {
            Mcu_ClockConfigIds[(*Mcu_ConfigPtr->ClockConfigPtr)[Index].ClockConfigId] =
                (uint8)Index;
        }
    }
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
/**
 * @brief      Stores configured RAM sectors ids.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Mcu_StoreConfiguredRamSectorId(void)
{
    uint32 Index;

    if (NULL_PTR != Mcu_ConfigPtr)
    {
        for (Index = 0U; Index < Mcu_ConfigPtr->NoOfRamConfigs; ++Index)
        {
            Mcu_RamConfigIds[(*Mcu_ConfigPtr->RamConfigPtr)[Index].RamSectorId] = (uint8)Index;
        }
    }
}
#endif /* MCU_MAX_NORAMCONFIGS */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief     This service initializes the MCU driver.
 *
 * @param[in] ConfigPtr: Pointer to MCU driver configuration set.
 *
 * @return    None
 *
 */
/* SWS_Mcu_00153, SWS_Mcu_00126 */
void Mcu_Init(const Mcu_ConfigType *ConfigPtr)
{
#if (MCU_PARAM_CHECK == STD_ON)
    if (MCU_UNINIT == Mcu_Status)
    {
        if (TRUE == Mcu_CheckInit(ConfigPtr))
        {
#endif /* (MCU_PARAM_CHECK == STD_ON) */

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
            Mcu_ConfigPtr = Mcu_PreDefinedConfigPtr;
            MCU_PARAM_UNUSED(ConfigPtr);
#else
    Mcu_ConfigPtr = ConfigPtr;
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

            Mcu_StoreConfiguredModeId();
#if (MCU_INIT_CLOCK == STD_ON)
            Mcu_StoreConfiguredClockId();
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
            Mcu_StoreConfiguredRamSectorId();
#endif /* MCU_MAX_NORAMCONFIGS */

            Mcu_Drvw_Init(Mcu_ConfigPtr->HwConfigPtr);

#if (MCU_PARAM_CHECK == STD_ON)
            Mcu_Status = MCU_READY;
        }
        else
        {
            Mcu_ConfigPtr = NULL_PTR;
        }
    }
    else
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)MCU_SID_INIT,
                              MCU_E_ALLREADY_INITIALIZED);
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */
}

/**
 * @brief     This service initializes the RAM section wise.
 *
 * @param[in] RamSection: Selects RAM memory section provided in configuration set.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Command has been accepted.
 * @retval    E_NOT_OK: Command has not been accepted, e.g. due to parameter error.
 *
 */
/* SWS_Mcu_00154 */
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    Std_ReturnType RamStatus = (Std_ReturnType)E_NOT_OK;

#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_INIT_RAM_SECTION))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
    #if (MCU_PARAM_CHECK == STD_ON)
        if (TRUE == Mcu_CheckInitRamSection(RamSection))
        {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

            Ram_Drv_ConfigType TmpDrvRamConfig;
            TmpDrvRamConfig.RamBaseAddr =
                (*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]].RamBaseAddr;
            TmpDrvRamConfig.RamSize =
                (*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]].RamSize;
            TmpDrvRamConfig.RamDefaultValue =
                (*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]].RamDefaultValue;
            TmpDrvRamConfig.RamWriteSize =
                (*Mcu_ConfigPtr->RamConfigPtr)[Mcu_RamConfigIds[RamSection]].RamWriteSize;

            RamStatus = Mcu_Drvw_InitRamSection(&TmpDrvRamConfig);
    #if (MCU_PARAM_CHECK == STD_ON)
        }
        else
        {
            /* Do nothing */
        }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
#else
    MCU_PARAM_UNUSED(RamSection);
#endif /* #ifndef MCU_MAX_NORAMCONFIGS */

#if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        /* Do nothing */
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */

    return RamStatus;
}

#if (MCU_INIT_CLOCK == STD_ON) /* SWS_Mcu_00210 */
/**
 * @brief     This service initializes the PLL and other MCU specific clock options.
 *
 * @param[in] ClockSetting: Clock setting.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Command has been accepted.
 * @retval    E_NOT_OK: Command has not been accepted.
 *
 */
/* SWS_Mcu_00155 */
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    Std_ReturnType ClockStatus = (Std_ReturnType)E_NOT_OK;

    #if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_INIT_CLOCK))
    {
        if (TRUE == Mcu_CheckInitClock(ClockSetting))
        {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

            Mcu_ClockConfigPtr =
                (*Mcu_ConfigPtr->ClockConfigPtr)[Mcu_ClockConfigIds[ClockSetting]].ClockConfigPtr;
            Mcu_Drvw_InitClock(Mcu_ClockConfigPtr);

            ClockStatus = (Std_ReturnType)E_OK;
    #if (MCU_PARAM_CHECK == STD_ON)
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

    return ClockStatus;
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF) /* SWS_Mcu_00205 */
/**
 * @brief     This service activates the PLL clock to the MCU clock distribution.
 *
 * @param[in] None
 *
 * @return    Std_ReturnType
 * @retval    E_OK: PLL Command has been accepted.
 * @retval    E_NOT_OK: Command has not been accepted.
 *
 */
/* SWS_Mcu_00156, SWS_Mcu_00056, SWS_Mcu_00142 */
Std_ReturnType Mcu_DistributePllClock(void)
{
    Std_ReturnType PllStatus = (Std_ReturnType)E_NOT_OK;

    #if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_DISTRIBUTE_PLL_CLOCK))
    {
        if (TRUE == Mcu_CheckDistributePllClock())
        {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

            Mcu_Drvw_DistributePllClock();

            PllStatus = (Std_ReturnType)E_OK;
    #if (MCU_PARAM_CHECK == STD_ON)
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

    return PllStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */

/**
 * @brief     This service provides the lock status of the PLL.
 *
 * @param[in] None
 *
 * @return    Mcu_PllStatusType: PLL status.
 * @retval    MCU_PLL_LOCKED:           PLL is locked.
 * @retval    MCU_PLL_UNLOCKED:         PLL is unlocked.
 * @retval    MCU_PLL_STATUS_UNDEFINED: PLL status is unkown.
 *
 */
/* SWS_Mcu_00230, SWS_Mcu_00157, SWS_Mcu_00206 */
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
    Mcu_PllStatusType PllStatus = MCU_PLL_STATUS_UNDEFINED;

#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_GET_PLL_STATUS))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
        if (TRUE == Mcu_Drvw_GetPllStatus())
        {
            PllStatus = MCU_PLL_LOCKED;
        }
        else
        {
            PllStatus = MCU_PLL_UNLOCKED;
        }
#endif /* (MCU_NO_PLL == STD_OFF) */

#if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        /* Do nothing */
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */

    return PllStatus;
}

/**
 * @brief     This service reads the reset type from the hardware.
 *
 * @param[in] None
 *
 * @return    Mcu_ResetType: MCU reset reason.
 *
 */
/* SWS_Mcu_00158, SWS_Mcu_00005 */
Mcu_ResetType Mcu_GetResetReason(void)
{
    Mcu_ResetType      ResetReason = MCU_RESET_UNDEFINED;
    Mcu_Drvw_ResetType DrvwResetReason = MCU_DRVW_RESET_UNDEFINED;
    uint8              Index = 0U;
    uint8 ResetReasonsCnt = sizeof(Mcu_ResetReasonTable) / sizeof(Mcu_ResetReasonTable[0U]);

#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_GET_RESET_REASON))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */

        DrvwResetReason = Mcu_Drvw_GetResetReason();
        for (; Index < ResetReasonsCnt; ++Index)
        {
            if (DrvwResetReason == Mcu_ResetReasonTable[Index].DrvwResetReason)
            {
                ResetReason = Mcu_ResetReasonTable[Index].ResetReason;
                break;
            }
        }

#if (MCU_HW_TEST_ENABLED == STD_ON)
        if (MCU_WATCHDOG_RESET == ResetReason)
        {
            if (MSTP_SELFTEST_STATE_BUSY == MCU_GET_HARDWARE_TEST_STATE_FUNC())
            {
                ResetReason = MCU_HW_TEST_RESET;
            }
        }
        else
        {
            /* Do nothing */
        }
#endif /* (MCU_HW_TEST_ENABLED == STD_ON) */

#if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        /* Do nothing */
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */

    return ResetReason;
}

/**
 * @brief     This service read the reset type from the hardware register.
 *
 * @param[in] None
 *
 * @return    Mcu_RawResetType: Reset raw value.
 *
 */
/* SWS_Mcu_00235, SWS_Mcu_00159 */
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
#if (MCU_PARAM_CHECK == STD_ON)
    Mcu_RawResetType RawResetValue = MCU_RAW_RESET_DEFAULT;
#else
    Mcu_RawResetType RawResetValue;
#endif

#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_GET_RESET_RAW_VALUE))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
        RawResetValue = (Mcu_RawResetType)Mcu_Drvw_GetResetRawValue();

#if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        /* Do nothing */
    }
#endif /*( MCU_PARAM_CHECK == STD_ON )*/

    return RawResetValue;
}

#if (MCU_PERFORM_RESET_API == STD_ON)
/**
 * @brief     The service perform a microcontroller reset.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
/* SWS_Mcu_00146 */
void Mcu_PerformReset(void)
{
    #if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_PERFORM_RESET))
    {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

    #if (MCU_PRIOR_RESET_CALLOUT_USED == STD_ON)
        /* User defined callout function before performing MCU reset. */
        MCU_PRIOR_RESET_CALLOUT();
    #endif /* (MCU_PRIOR_RESET_CALLOUT_USED == STD_ON) */

        Mcu_Drvw_PerformReset();
    #if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        /* Do nothing */
    }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
}
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

/**
 * @brief     This service activates the MCU power modes.
 *
 * @param[in] McuMode: Set different MCU power modes configured in the configuration set.
 *
 * @return    None
 *
 */
/* SWS_Mcu_00161 */
void Mcu_SetMode(Mcu_ModeType McuMode)
{
#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_SET_MODE))
    {
        if (TRUE == Mcu_CheckSetMode(McuMode))
        {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
            SchM_Enter_Mcu_SetMode();
            switch ((*Mcu_ConfigPtr->ModeConfigPtr)[Mcu_ModeConfigIds[McuMode]].PowerMode)
            {
                case MCU_POWERMODE_RUN:
                    Mcu_Drvw_SetMode(MCU_DRVW_POWERMODE_RUN);
                    break;
                case MCU_POWERMODE_WAIT:
                    Mcu_Drvw_SetMode(MCU_DRVW_POWERMODE_WAIT);
                    break;
                case MCU_POWERMODE_STOP:
                    Mcu_Drvw_SetMode(MCU_DRVW_POWERMODE_STOP);
                    break;
                case MCU_POWERMODE_STANDBY:
                    Mcu_Drvw_SetMode(MCU_DRVW_POWERMODE_STANDBY);
                    break;
                default:
                    /* Do nothing */
                    break;
            }
            SchM_Exit_Mcu_SetMode();
#if (MCU_PARAM_CHECK == STD_ON)
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */
}

#if (MCU_VERSION_INFO_API == STD_ON)
/**
 * @brief        This service returns the version information of this module.
 *
 * @param[inout] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return       None
 *
 */
/* SWS_Mcu_00162 */
void Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    #if (MCU_PARAM_CHECK == STD_ON)
    if (NULL_PTR != versioninfo)
    {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
        (versioninfo)->vendorID = (uint16)MCU_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)MCU_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)MCU_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)MCU_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)MCU_SW_PATCH_VERSION;
    #if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_GET_VERSION_INFO,
                              MCU_E_PARAM_POINTER);
    }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
}
#endif /* (MCU_VERSION_INFO_API == STD_ON) */

#if (MCU_GET_RAM_STATE_API == STD_ON) /* SWS_Mcu_00209 */
/**
 * @brief     This service provides the actual status of the microcontroller Ram.
 *
 * @param[in] None
 *
 * @return    Mcu_RamStateType: Status of the Ram content.
 *
 */
/* SWS_Mcu_00207 */
Mcu_RamStateType Mcu_GetRamState(void)
{
    Mcu_RamStateType RamState = MCU_RAMSTATE_INVALID;

    #if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_GET_RAM_STATE))
    {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
           /* Get Ram status */

    #if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        /* Do nothing */
    }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

    return RamState;
}
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

#if (MCU_POWERMODE_STATE_API == STD_ON)
/**
 * @brief     This service reads current power mode.
 *
 * @param[in] None
 *
 * @return    Mcu_PowerModeType: Current power mode.
 *
 */
Mcu_PowerModeType Mcu_GetPowerModeState(void)
{
    Mcu_PowerModeType PowerMode = MCU_POWERMODE_RUN;

    #if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_GET_POWER_MODE_STATE))
    {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
        switch (Mcu_Drvw_GetPowerModeState())
        {
            case MCU_DRVW_POWERMODE_RUN:
                PowerMode = MCU_POWERMODE_RUN;
                break;
            case MCU_DRVW_POWERMODE_WAIT:
                PowerMode = MCU_POWERMODE_WAIT;
                break;
            case MCU_DRVW_POWERMODE_STOP:
                PowerMode = MCU_POWERMODE_STOP;
                break;
            case MCU_DRVW_POWERMODE_STANDBY:
                PowerMode = MCU_POWERMODE_STANDBY;
                break;
            default:
                PowerMode = MCU_POWERMODE_RUN;
                break;
        }

    #if (MCU_PARAM_CHECK == STD_ON)
    }
    else
    {
        /* Do nothing */
    }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */

    return PowerMode;
}
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */

/**
 * @brief      This service enables and configs OSC clock monitor.
 *
 * @param[in]  Act: Select the action when loss of clock is detected.
 *
 * @return     boolean
 * @retval     TRUE:  OSC clock monitor is enabled success.
 * @retval     FALSE: OSC clock monitor is enabled failed.
 *
 */
boolean Mcu_EnableOscClockMonitor(Mcu_OscClockLossActType Act)
{
    boolean Ret = FALSE;

#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_ENABLE_OSC_CLOCK_MONITOR))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
        if (TRUE == Mcu_CheckEnableOscClockMonitor())
        {
            if (MCU_OSC_CLOCK_LOSS_INT == Act)
            {
                Mcu_Drvw_EnableOscClockMonitor(MCU_DRVW_OSC_CLOCK_LOSS_INT);
            }
            else if (MCU_OSC_CLOCK_LOSS_RST == Act)
            {
                Mcu_Drvw_EnableOscClockMonitor(MCU_DRVW_OSC_CLOCK_LOSS_RST);
            }
            else
            {
                /* Do nothing */
            }
            Ret = TRUE;
        }
#if (MCU_PARAM_CHECK == STD_ON)
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */

    return Ret;
}

/**
 * @brief      This service disables OSC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_DisableOscClockMonitor(void)
{
#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_DISABLE_OSC_CLOCK_MONITOR))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
        Mcu_Drvw_DisableOscClockMonitor();
#if (MCU_PARAM_CHECK == STD_ON)
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */
}

/**
 * @brief      This service enables and configs FIRC clock monitor.
 *
 * @param[in]  Act: Select the action when loss of clock is detected.
 *
 * @return     boolean
 * @retval     TRUE:  FIRC clock monitor is enabled success.
 * @retval     FALSE: FIRC clock monitor is enabled failed.
 *
 */
boolean Mcu_EnableFircClockMonitor(Mcu_Firc64MClockLossActType Act)
{
    boolean Ret = FALSE;

#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_ENABLE_FIRC_CLOCK_MONITOR))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
        if (TRUE == Mcu_CheckEnableFircClockMonitor())
        {
            if (MCU_FIRC64M_CLOCK_LOSS_INT == Act)
            {
                Mcu_Drvw_EnableFirc64MClockMonitor(MCU_DRVW_FIRC64M_CLOCK_LOSS_INT);
            }
            else if (MCU_FIRC64M_CLOCK_LOSS_RST == Act)
            {
                Mcu_Drvw_EnableFirc64MClockMonitor(MCU_DRVW_FIRC64M_CLOCK_LOSS_RST);
            }
            else
            {
                /* Do nothing */
            }

            Ret = TRUE;
        }
#if (MCU_PARAM_CHECK == STD_ON)
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */

    return Ret;
}

/**
 * @brief      This service disables FIRC clock monitor.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Mcu_DisableFircClockMonitor(void)
{
#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_DISABLE_FIRC_CLOCK_MONITOR))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
        Mcu_Drvw_DisableFirc64MClockMonitor();
#if (MCU_PARAM_CHECK == STD_ON)
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */
}

#if (MCU_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 * @brief      This service enables and configs PLL clock monitor.
 *
 * @param[in]  Act: Select the action when loss of clock is detected.
 *
 * @return     None
 *
 */
void Mcu_EnablePllClockMonitor(Mcu_PllClockLossActType Act)
{
    #if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_ENABLE_PLL_CLOCK_MONITOR))
    {
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
        if (MCU_PLL_CLOCK_LOSS_INT == Act)
        {
            Mcu_Drvw_EnablePllClockMonitor(MCU_DRVW_PLL_CLOCK_LOSS_INT);
        }
        else if (MCU_PLL_CLOCK_LOSS_RST == Act)
        {
            Mcu_Drvw_EnablePllClockMonitor(MCU_DRVW_PLL_CLOCK_LOSS_RST);
        }
        else
        {
            /* Do nothing */
        }
    #if (MCU_PARAM_CHECK == STD_ON)
    }
    #endif /* (MCU_PARAM_CHECK == STD_ON) */
}
#endif

/**
 * @brief      This service configs MCU wakeup source.
 *
 * @param[in]  WakeupSource: Select wakeup source.
 * @param[in]  ActiveHigh: Wakeup MCU if polarity is high.
 * @param[in]  Enable: Enable/disable this wakeup source.
 *
 * @return     None
 *
 */
void Mcu_SetWakeupSource(Mcu_WakeupSourceType WakeupSource, boolean ActiveHigh, boolean Enable)
{
    uint8 Index = 0U;
    uint8 WakeupSourcesCnt = sizeof(Mcu_WakeupSourceTable) / sizeof(Mcu_WakeupSourceTable[0U]);

#if (MCU_PARAM_CHECK == STD_ON)
    if (TRUE == Mcu_CheckMcuInitialized(MCU_SID_SET_WAKEUP_SOURCE))
    {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
        for (; Index < WakeupSourcesCnt; ++Index)
        {
            if (WakeupSource == Mcu_WakeupSourceTable[Index].WakeupSource)
            {
                Mcu_Drvw_SetWakeupSource(Mcu_WakeupSourceTable[Index].DrvwWakeupSource, ActiveHigh,
                                         Enable);
                break;
            }
        }
#if (MCU_PARAM_CHECK == STD_ON)
    }
#endif /* (MCU_PARAM_CHECK == STD_ON) */
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Mcu */

/** @} end of group Mcu_Module */
