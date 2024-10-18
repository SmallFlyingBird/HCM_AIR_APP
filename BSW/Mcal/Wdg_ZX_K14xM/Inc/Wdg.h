/**************************************************************************************************/
/**
 * @file      : Wdg.h
 * @brief     : Wdg AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_H
#define WDG_H

/** @addtogroup  Wdg_Module
 *  @{
 */

/** @addtogroup Wdg
 *  @brief Wdg AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_Types.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_VENDOR_ID                   0x00B3U
#define WDG_MODULE_ID                   102U
#define WDG_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_AR_RELEASE_MINOR_VERSION    6U
#define WDG_AR_RELEASE_REVISION_VERSION 0U
#define WDG_SW_MAJOR_VERSION            1U
#define WDG_SW_MINOR_VERSION            2U
#define WDG_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_Types header file are of the same vendor */
#if (WDG_VENDOR_ID != WDG_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Wdg.h and Wdg_Types.h are different"
#endif

/* Check if current file and Wdg_Types header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION    != WDG_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION    != WDG_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION != WDG_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg.h and Wdg_Types.h are different"
#endif

/* Check if current file and Wdg_Types header file are of the same software version */
#if ((WDG_SW_MAJOR_VERSION != WDG_TYPES_H_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION != WDG_TYPES_H_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION != WDG_TYPES_H_SW_PATCH_VERSION))
#error "Software Version of Wdg.h and Wdg_Types.h are different"
#endif

/**
 * @brief  Service ID
 */
#define    WDG_SID_INIT                         ((uint8)0x00U)    
#define    WDG_SID_SET_MODE                     ((uint8)0x01U)                                                  
#define    WDG_SID_SET_TRIGGER_CONDITION        ((uint8)0x03U)
#if (WDG_VERSION_INFO_API == STD_ON)
    #define    WDG_SID_GET_VERSION_INFO         ((uint8)0x04U)
#endif
#if (WDG_DIRECT_SERVICE == STD_ON)
    #define    WDG_SID_SERVICE                  ((uint8)0x05U)
#endif
#define    WDG_SID_TRIGGER                      ((uint8)0x06U)

/**
 * @brief  API service used in wrong context
 */
#define     WDG_E_DRIVER_STATE        ((uint8)0x10U)

/**
 * @brief  API service called with wrong / inconsistent parameter(s) of mode
 */
#define     WDG_E_PARAM_MODE          ((uint8)0x11U)

/**
 * @brief  API service called with wrong / inconsistent parameter(s) of config
 */
#define     WDG_E_PARAM_CONFIG        ((uint8)0x12U)

/**
 * @brief  The passed timeout value is higher than the maximum timeout value
 */
#define     WDG_E_PARAM_TIMEOUT       ((uint8)0x13U)

/**
 * @brief  API is called with wrong pointer value
 */
#define     WDG_E_PARAM_POINTER       ((uint8)0x14U)

/**
 * @brief  Invalid configuration set selection
 */
#define     WDG_E_INIT_FAILED         ((uint8)0x15U)

/**
 * @brief  Wdg runtime errors
 */
#define     WDG_E_TIMEOUT             ((uint8)0x16U)

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
    #define WDG_START_SEC_CONFIG_DATA_PTR
    #include "Wdg_MemMap.h"

extern const Wdg_ConfigType *const Wdg_PreDefinedConfigPtr;

    #define WDG_STOP_SEC_CONFIG_DATA_PTR
    #include "Wdg_MemMap.h"

#else
    #define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Wdg_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
WDG_CONFIG_EXT

    #define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Wdg_MemMap.h"
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#if (WDG_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/**
* @brief   This function initializes the WDG module.
*
* @param[in] ConfigPtr     Pointer to configuration set.
*
* @return   None
*/
void Wdg_Init(const Wdg_ConfigType *ConfigPtr);

/**
* @brief   Switches the watchdog into the mode Mode.
*
* @param[in] Mode      One of the following statically configured modes:<br>
*                      - WDGIF_OFF_MODE,
*                      - WDGIF_SLOW_MODE,
*                      - WDGIF_FAST_MODE.
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
*/
Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode);

#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
 * @brief   Sets the timeout value for the trigger counter.
 *
 * @param[in] Timeout    Timeout value (milliseconds) for setting the trigger counter.
 * 
 * @return   None
 *  
 */
void Wdg_SetTriggerCondition(uint16 Timeout);
#endif

#if (WDG_DIRECT_SERVICE == STD_ON)
/**
* @brief   Service the Watchdog directly
*
* @param[in] none
* 
* @return   None
* 
*/
void Wdg_Service(void);
#endif

#if (WDG_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of the module.
*
*
* @param[out] versioninfo   Pointer to where to store the version
*                              information of this module.
*
* @return   None
*
*/
void Wdg_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#if (WDG_DIRECT_SERVICE == STD_OFF)

/**
 * @brief     Callback function for GPT notification.
 * 
 * @param[in] None
 * 
 * @return   None
 * 
 */
void Wdg_CallbackForGptNotification(void);
#endif

#if (WDG_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/** @} end of Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdg */

/** @} end of group Wdg_Module */
