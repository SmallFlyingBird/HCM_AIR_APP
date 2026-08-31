/**
 * @file    Mcu.c
 * @version
 *
 * @brief   AUTOSAR Mcu module interface
 * @details API implementation for MCU driver
 *
 * @addtogroup MCU_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Mcu
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Mcu.h"
#include "Mcu_Lld.h"
#include "OsIf.h"
#include "SchM_Mcu.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* MCU_DEV_ERROR_DETECT == STD_ON */

#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif /* MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON */

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID_C                      (0xB4)
#define MCU_AR_RELEASE_MAJOR_VERSION_C       (4)
#define MCU_AR_RELEASE_MINOR_VERSION_C       (4)
#define MCU_AR_RELEASE_REVISION_VERSION_C    (0)
#define MCU_SW_MAJOR_VERSION_C               (2)
#define MCU_SW_MINOR_VERSION_C               (3)
#define MCU_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu.c and Mcu.h have different vendor ids"
#endif

/* Check if source file and MCU header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu.c and Mcu.h are different"
#endif

/* Check if source file and MCU header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu.c and Mcu.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
/* MR12 RULE 2.5 VIOLATION: The macro 'MCU_UNUSED_PARAM' is used in pre-compile */
#define MCU_UNUSED_PARAM(Parma) ((void)Parma) /* PRQA S 1534 */


#define MCU_CLOCK_UNINIT (0xFFU)

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
 * @brief This enumeration type is used to enumerate the Mcu state.
 */
typedef enum
{
    MCU_UNINIT,                         /**< Mcu module is not initialize */
    MCU_READY,                          /**< Mcu module is initialized */
} Mcu_DriverStateType;
/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"
MCU_VAR static const Mcu_ClockConfigType *Mcu_ClockConfigPtr = NULL_PTR;

#if (MCU_FIXED_PB_CONFIG == STD_ON)
extern const Mcu_ConfigType Mcu_PreCompileConfig;
MCU_VAR static const Mcu_ConfigType *Mcu_ConfigPtr = &Mcu_PreCompileConfig;
#else
MCU_VAR static const Mcu_ConfigType *Mcu_ConfigPtr = NULL_PTR;
#endif

#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"


#define MCU_START_SEC_VAR_INIT_8
#include "Mcu_MemMap.h"

MCU_VAR static Mcu_DriverStateType Mcu_DriverState = MCU_UNINIT;
MCU_VAR static Mcu_ClockType Mcu_ActiveClockSetting = MCU_CLOCK_UNINIT;

#define MCU_STOP_SEC_VAR_INIT_8
#include "Mcu_MemMap.h"
/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (MCU_NO_PLL == STD_OFF)

MCU_FUNC Std_ReturnType Mcu_DistributePllClock(void)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;

    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
       before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
       Trace : SWS_Mcu_00125 */
    if (MCU_UNINIT == Mcu_DriverState)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_GET_PLL_STATUS, MCU_E_UNINIT);
#endif
    }
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
    if (MCU_PLL_LOCKED != OsIf_Trusted_Call_Return(Mcu_Lld_GetPllStatus))
#else
    if (MCU_PLL_LOCKED != Mcu_Lld_GetPllStatus())
#endif
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        /* A error shall be reported if the status of the PLL is detected as not locked with the function Mcu_DistributePllClock()
           Trace : SWS_Mcu_00122 */
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_DISTRIBUTE_PLL_CLOCK, MCU_E_PLL_NOT_LOCKED);
#endif
        /* If the function Mcu_DistributePllClock is called before PLL has locked, this function shall return E_NOT_OK immediately,
           without any further action
           Trace : SWS_Mcu_00142 */
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        ReturnValue = OsIf_Trusted_Call_Return1param(Mcu_Lld_SetClockSource, Mcu_ClockConfigPtr);
#else
        ReturnValue = Mcu_Lld_SetClockSource(Mcu_ClockConfigPtr);
#endif

#if MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON
        if (E_OK != ReturnValue)
        {
            (void)Mcu_SetEventStatus(MCU_E_CLOCK_FAILURE, MCU_EVENT_STATUS_FAILED);
        }
#endif
    }
    return ReturnValue;
}

#endif

MCU_FUNC Mcu_PllStatusType Mcu_GetPllStatus(void)
{
    Mcu_PllStatusType PllStatus = MCU_PLL_STATUS_UNDEFINED;
#if (MCU_NO_PLL == STD_OFF)
    /* The function Mcu_GetPllStatus shall return MCU_PLL_STATUS_UNDEFINED if this function is called prior to calling of the function Mcu_Init
       Trace : SWS_Mcu_00132 */
    if (MCU_UNINIT != Mcu_DriverState)
    {
        /* The function Mcu_GetPllStatus shall return the lock status of the PLL
           Trace : SWS_Mcu_00008 */
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        PllStatus = (Mcu_PllStatusType)OsIf_Trusted_Call_Return(Mcu_Lld_GetPllStatus);
#else
        PllStatus = Mcu_Lld_GetPllStatus();
#endif
    }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
       before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
       Trace : SWS_Mcu_00125 */
    else
    {

        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_GET_PLL_STATUS, MCU_E_UNINIT);
    }
#endif
    return PllStatus;
#else
    /* If the pre-compile parameter McuNoPll is set to TRUE, return MCU_PLL_STATUS_UNDEFINED
       Trace : SWS_Mcu_00206  */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
       before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
       Trace : SWS_Mcu_00125 */
    if (MCU_UNINIT != Mcu_DriverState)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_GET_PLL_STATUS, MCU_E_UNINIT);
    }
#endif
    return PllStatus;
#endif
}

#if (MCU_GET_SXOSC_STATU_API == STD_ON)
MCU_FUNC Mcu_SxoscStatusType Mcu_GetSxoscStatus(void)
{
    Mcu_SxoscStatusType SxoscStatus = MCU_SXOSC_INVALID;
    if (MCU_UNINIT != Mcu_DriverState)
    {
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        SxoscStatus = (Mcu_SxoscStatusType)OsIf_Trusted_Call_Return(Mcu_Lld_GetSxoscStatus);
#else
        SxoscStatus = Mcu_Lld_GetSxoscStatus();
#endif
    }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    else
    {

        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_GET_SXOSC_STATUS, MCU_E_UNINIT);
    }
#endif
    return SxoscStatus;
}
#endif

#if (MCU_GET_RAM_STATE_API == STD_ON)
MCU_FUNC Mcu_RamStateType Mcu_GetRamState(void)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
       before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
       Trace : SWS_Mcu_00125 */
    if (MCU_UNINIT != Mcu_DriverState)
    {

        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_GET_RAM_STATE, MCU_E_UNINIT);
    }
#endif
    return MCU_RAMSTATE_VALID;
}
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

MCU_FUNC Mcu_ResetType Mcu_GetResetReason(void)
{
    Mcu_ResetType ResetReason = MCU_RESET_UNDEFINED;

    /* If called befor Mcu_Init, return MCU_RESET_UNDEFINED
       Trace : SWS_Mcu_00133 */
    if (MCU_UNINIT != Mcu_DriverState)
    {
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        ResetReason = (Mcu_ResetType)OsIf_Trusted_Call_Return(Mcu_Lld_GetResetValue);
#else
        ResetReason = Mcu_Lld_GetResetValue();
#endif
    }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
       before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
       Trace : SWS_Mcu_00125 */
    else
    {

        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_GET_RESET_REASON, MCU_E_UNINIT);
    }
#endif
    return ResetReason;
}

MCU_FUNC void Mcu_Init(const Mcu_ConfigType *ConfigPtr)
{
    Mcu_DriverState = MCU_UNINIT;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#if (MCU_FIXED_PB_CONFIG == STD_ON)
    if (NULL_PTR == Mcu_ConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_INIT, MCU_E_PARAM_POINTER);
    }
    else
#else
    if (NULL_PTR == ConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_INIT, MCU_E_PARAM_POINTER);
    }
    else
#endif
#endif
    {
#if (MCU_FIXED_PB_CONFIG == STD_ON)
        MCU_UNUSED_PARAM(ConfigPtr); /* To avoid compiler warning */
#else
        Mcu_ConfigPtr = ConfigPtr;
#endif
        /* Init clock */
        if (NULL_PTR == Mcu_ConfigPtr->ClockConfig)
        {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                                  MCU_SID_INIT, MCU_E_PARAM_POINTER);
#endif
            Mcu_ConfigPtr = NULL_PTR;
        }
        else
        {
            /* Init reset settings */
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Mcu_Lld_SetRcu, Mcu_ConfigPtr->ResetConfig);
#else
            Mcu_Lld_SetRcu(Mcu_ConfigPtr->ResetConfig);
#endif
            /* Init power settings */
            /*TODO: Mcu_Lld_SetPowerMode(Mcu_ConfigPtr->PowerConfig);*/

            /* Init Pcu setting */
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Mcu_Lld_SetPcu, Mcu_ConfigPtr->PcuConfig);
#else
            Mcu_Lld_SetPcu(Mcu_ConfigPtr->PcuConfig);
#endif

            Mcu_DriverState = MCU_READY;
        }
    }
}

#if (MCU_INIT_CLOCK == STD_ON)
MCU_FUNC Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;

    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
    before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
    Trace : SWS_Mcu_00125, SWS_Mcu_00139 */
    if (MCU_UNINIT == Mcu_DriverState)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_INIT_CLOCK, MCU_E_UNINIT);
#endif
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* ClockSetting shall be within the sections defined in the configuration data structure
       Trace :  */
    else if (ClockSetting >= Mcu_ConfigPtr->ClockConfigNum)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_INIT_CLOCK, MCU_E_PARAM_CLOCK);
#endif
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Mcu_ActiveClockSetting = ClockSetting;
        Mcu_ClockConfigPtr = &Mcu_ConfigPtr->ClockConfig[ClockSetting];
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        ReturnValue = OsIf_Trusted_Call_Return1param(Mcu_Lld_InitClock,Mcu_ClockConfigPtr);
#else
        ReturnValue = Mcu_Lld_InitClock(Mcu_ClockConfigPtr);
#endif

#if MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON
        if (E_OK != ReturnValue)
        {
            (void)Mcu_SetEventStatus(MCU_E_CLOCK_FAILURE, MCU_EVENT_STATUS_FAILED);
        }
#endif
    }
    return ReturnValue;
}
#endif
/**
 * GCOVR_EXCL_START: The 'Mcu_Lld_SetRamSection' function is designed to clear the RAM section data to the default values
 * configured by the PB file. Due to the potential risk of unintentionally erasing critical data, this function is excluded
 * from coverage testing to prevent inadvertent impacts during the testing process.
 */
MCU_FUNC Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    Mcu_RamSectionConfigType const *RamSectionConfigPtr = NULL_PTR;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
    before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
    Trace : SWS_Mcu_00125, SWS_Mcu_00136 */
    if (MCU_UNINIT == Mcu_DriverState)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_INIT_RAM_SECTION, MCU_E_UNINIT);
#endif
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    /* RamSection shall be within the sections defined in the configuration data structure
    Trace : SWS_Mcu_00021 */
    else if (RamSection >= Mcu_ConfigPtr->RamSectionConfigNum)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_INIT_RAM_SECTION, MCU_E_PARAM_RAMSECTION);
#endif
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Write default value to eath sector
                       Trace : SWS_Mcu_00011 */
        RamSectionConfigPtr = &Mcu_ConfigPtr->RamSectionConfig[RamSection];
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Mcu_Lld_SetRamSection,RamSectionConfigPtr);
#else
        Mcu_Lld_SetRamSection(RamSectionConfigPtr);
#endif
        ReturnValue = (Std_ReturnType)E_OK;
    }
    return ReturnValue;
}
/* GCOVR_EXCL_STOP */
/**
 * GCOVR_EXCL_START: The 'Mcu_PerformReset' function performs a chip reset, preventing testing
 * in integration tests.
 */
#if (MCU_PERFORM_RESET_API == STD_ON)
MCU_FUNC void Mcu_PerformReset(void)
{
    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
    before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
    Trace : SWS_Mcu_00125 */
    if (MCU_UNINIT == Mcu_DriverState)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                        MCU_SID_GET_PLL_STATUS, MCU_E_UNINIT);
#endif
    }
    else
    {
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Mcu_Lld_SystemReset);
#else
        Mcu_Lld_SystemReset();
#endif
    }
}
#endif /* (MCU_PERFORM_RESET_API == STD_ON) GCOVR_EXCL_STOP */
MCU_FUNC void Mcu_SetMode(Mcu_ModeType McuMode)
{
    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
    before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
    Trace : SWS_Mcu_00125 */
    if (MCU_UNINIT == Mcu_DriverState)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_SET_MODE, MCU_E_UNINIT);
#endif
    }
    else if (McuMode >= Mcu_ConfigPtr->ModeConfigNum)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_SET_MODE, MCU_E_PARAM_MODE);
#endif
    }
    else
    {
        SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00();
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Mcu_Lld_SetMode,Mcu_ConfigPtr->PowerConfig->ModeMap[McuMode]);
#else
        Mcu_Lld_SetMode(Mcu_ConfigPtr->PowerConfig->ModeMap[McuMode]);
#endif
        SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00();
    }
}

MCU_FUNC Mcu_RawResetType Mcu_GetResetRawValue(void)
{
    Mcu_RawResetType ReturnValue = MCU_RAW_RESET_DEFAULT;

    /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
    before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
    Trace : SWS_Mcu_00125 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (MCU_UNINIT == Mcu_DriverState)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_GET_RESET_RAW_VALUE, MCU_E_UNINIT);
    }
    else
#endif
    {
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        ReturnValue = OsIf_Trusted_Call_Return(Mcu_Lld_GetResetRawValue);
#else
        ReturnValue = Mcu_Lld_GetResetRawValue();
#endif
    }
    return ReturnValue;

}

MCU_FUNC uint32 Mcu_180_GetCoreClockFrequency(void)
{
    uint32 ReturnValue = 0u;
    if(Mcu_ActiveClockSetting != MCU_CLOCK_UNINIT)
    {
        Mcu_ClockConfigPtr = &Mcu_ConfigPtr->ClockConfig[Mcu_ActiveClockSetting];
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
        ReturnValue = OsIf_Trusted_Call_Return1param(Mcu_Lld_GetCoreClockFrequency,Mcu_ClockConfigPtr);
#else
        ReturnValue = Mcu_Lld_GetCoreClockFrequency(Mcu_ClockConfigPtr);
#endif
    }
    return ReturnValue;
}

#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
MCU_FUNC Std_ReturnType Mcu_SetEventStatus(Mcu_ErrorType ErrorType, Mcu_EventStatusType EventStatus)
{
    Std_ReturnType Ret = E_OK;
    if (MCU_READY == Mcu_DriverState)
    {
        switch (ErrorType)
        {
        case MCU_E_CLOCK_FAILURE:
            if(STD_ON == Mcu_ConfigPtr->DemConfig->ErrorClockFailureCfg.Enable)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Mcu_ConfigPtr->DemConfig->ErrorClockFailureCfg.EventId, (Dem_EventStatusType)EventStatus);
            }
            break;
        case MCU_E_CMU_FAILURE:
            if(STD_ON == Mcu_ConfigPtr->DemConfig->ErrorCMUFailureCfg.Enable)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Mcu_ConfigPtr->DemConfig->ErrorCMUFailureCfg.EventId, (Dem_EventStatusType)EventStatus);
            }
            break;
        default:
            Ret = E_NOT_OK;
            break;
        }
    }
    else
    {
        Ret = E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        /* If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called
           before Mcu_Init function, the error code MCU_E_UNINIT shall be reported
           Trace : SWS_Mcu_00125 */
        (void)Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_SID_SET_EVENT_STATUS, MCU_E_UNINIT);
#endif
    }
    return Ret;
}
#endif /* MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON */

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

