/**************************************************************************************************/
/**
 * @file      : Wdg_Drvw.c
 * @brief     : Wdg driver wrapper source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drvw
 *  @brief Wdg driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdog_Drv.h"
#include "Wdg_Drvw.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_DRVW_C_VENDOR_ID                   0x00B3U
#define WDG_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define WDG_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define WDG_DRVW_C_SW_MAJOR_VERSION            1U
#define WDG_DRVW_C_SW_MINOR_VERSION            2U
#define WDG_DRVW_C_SW_PATCH_VERSION            1U

/* Check if Wdg_Drvw.c and Wdog_Drv.h are of the same vendor */
#if (WDG_DRVW_C_VENDOR_ID != WDOG_DRV_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Drvw.c and Wdog_Drv.h are different"
#endif
/* Check if Wdg_Drvw.c file and Wdog_Drv.h file are of the same Autosar version */
#if ((WDG_DRVW_C_AR_RELEASE_MAJOR_VERSION != WDOG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_DRVW_C_AR_RELEASE_MINOR_VERSION != WDOG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (WDG_DRVW_C_AR_RELEASE_REVISION_VERSION != WDOG_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Drvw.c and Wdog_Drv.h are different"
#endif
#if ((WDG_DRVW_C_SW_MAJOR_VERSION != WDOG_DRV_H_SW_MAJOR_VERSION) || \
    (WDG_DRVW_C_SW_MINOR_VERSION != WDOG_DRV_H_SW_MINOR_VERSION) || \
    (WDG_DRVW_C_SW_PATCH_VERSION != WDOG_DRV_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Drvw.c and Wdog_Drv.h are different"
#endif

/* Check if Wdg_Drvw.c and Wdg_Drvw.h are of the same vendor */
#if (WDG_DRVW_C_VENDOR_ID != WDG_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Wdg_Drvw.c and Wdg_Drvw.h are different"
#endif
/* Check if Wdg_Drvw.c file and Wdg_Drvw.h file are of the same Autosar version */
#if ((WDG_DRVW_C_AR_RELEASE_MAJOR_VERSION != WDG_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_DRVW_C_AR_RELEASE_MINOR_VERSION != WDG_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
    (WDG_DRVW_C_AR_RELEASE_REVISION_VERSION != WDG_DRVW_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Drvw.c and Wdg_Drvw.h are different"
#endif
#if ((WDG_DRVW_C_SW_MAJOR_VERSION != WDG_DRVW_H_SW_MAJOR_VERSION) || \
    (WDG_DRVW_C_SW_MINOR_VERSION != WDG_DRVW_H_SW_MINOR_VERSION) || \
    (WDG_DRVW_C_SW_PATCH_VERSION != WDG_DRVW_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Drvw.c and Wdg_Drvw.h are different"
#endif

/* Rename Wdog_Drv_Init*/
#define Wdog_Drv_Config Wdog_Drv_Init

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#if (WDG_DRVW_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"


/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief    Config the watchdog Fast/Slow mode.
 *
 * @param[in] Mode: The accessible watchdog mode(Fast/Slow).
 * @param[in] ConfigPtr: Pointer to configuration structure
 * 
 * @return   the result
 * @retval   E_OK 
 * @retval   E_NOT_OK
 * @retval   WDG_DRVW_E_TIMEOUT: hardware timeout error
 * 
 */
Std_ReturnType Wdg_Drvw_SetMode(const WdgIf_ModeType Mode, const Wdg_Drvw_ConfigType *ConfigPtr)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_OK;
    uint8 WdogMode;
    Wdog_Drv_StatusType LowLvlStatus = WDOG_DRV_STATUS_SUCCESS;

    if(WDGIF_OFF_MODE != Mode)
    {
        if(WDGIF_SLOW_MODE == Mode)
        {
            WdogMode = 1U;
        }
        else
        {
            WdogMode = 2U;
        }

        LowLvlStatus = Wdog_Drv_Config(ConfigPtr->ModeConfigPtr[WdogMode]->WdogDrvConfig);
        if(WDOG_DRV_STATUS_SUCCESS == LowLvlStatus)
        {
            ReturnVal = (Std_ReturnType)E_OK;
        }
		else
        {
            ReturnVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
#if (WDG_DRVW_DISABLE_ALLOWED == STD_ON)
        LowLvlStatus = Wdog_Drv_DeInit();

        ReturnVal = (Std_ReturnType)LowLvlStatus;
#else
        ReturnVal = (Std_ReturnType)E_NOT_OK;
#endif
    }

    return ReturnVal;
}

/**
 * @brief   This function initializes the WDG module.
 *
 * @param[in] ConfigPtr: Pointer to configuration structure.
 *
 * @return   The init status
 * @retval   E_OK 
 * @retval   E_NOT_OK
 * @retval   WDG_DRVW_E_TIMEOUT: hardware timeout error
 */
Std_ReturnType Wdg_Drvw_Init(const Wdg_Drvw_ConfigType *ConfigPtr)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_NOT_OK;
    Wdog_Drv_StatusType LowLvlStatus = WDOG_DRV_STATUS_SUCCESS;
    uint8 WdogMode;

    if (WDGIF_OFF_MODE == ConfigPtr->DefaultMode)
    {
#if (WDG_DRVW_DISABLE_ALLOWED == (STD_ON))
        LowLvlStatus = Wdog_Drv_DeInit();
        ReturnVal = (Std_ReturnType)LowLvlStatus;
#else
        ReturnVal = (Std_ReturnType)E_NOT_OK;
        (void)LowLvlStatus;
#endif
    }
    else
    {
        if(WDGIF_SLOW_MODE == ConfigPtr->DefaultMode)
        {
            WdogMode = 1U;
        }
        else
        {
            WdogMode = 2U;
        }
        ReturnVal = (uint8)Wdog_Drv_Init(ConfigPtr->ModeConfigPtr[WdogMode]->WdogDrvConfig);
    }

    return ReturnVal;
}

/**
 * @brief   Refresh the wdg.
 * 
 * @param[in]  ConfigPtr: Pointer to configuration structure.
 * 
 * @return   None
 *
 */
void Wdg_Drvw_Refresh(const Wdg_Drvw_ConfigType *ConfigPtr)
{
    Wdog_Drv_Refresh(ConfigPtr->CbBeforeRefreshPtr,ConfigPtr->CbAfterRefreshPtr);
}

#if (WDG_DRVW_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif
/** @} end of group Wdg_Drvw */

/** @} end of group Wdg_Module */
