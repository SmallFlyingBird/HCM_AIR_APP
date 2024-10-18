/**************************************************************************************************/
/**
 * @file      : Wdg_179_Ewdt.h
 * @brief     : Wdg_179_Ewdt AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_179_EWDT_H
#define WDG_179_EWDT_H

/** @addtogroup  Wdg_179_Ewdt_Module
 *  @{
 */

/** @addtogroup Wdg_179_Ewdt
 *  @brief Wdg_179_Ewdt AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_179_Ewdt_Types.h"
#include "WdgIf.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_179_EWDT_VENDOR_ID                   0x00B3U
#define WDG_179_EWDT_MODULE_ID                   102U
#define WDG_179_EWDT_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_179_EWDT_AR_RELEASE_MINOR_VERSION    6U
#define WDG_179_EWDT_AR_RELEASE_REVISION_VERSION 0U
#define WDG_179_EWDT_SW_MAJOR_VERSION            1U
#define WDG_179_EWDT_SW_MINOR_VERSION            2U
#define WDG_179_EWDT_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_179_Ewdt_Types header file are of the same vendor */
#if (WDG_179_EWDT_VENDOR_ID != WDG_179_EWDT_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Wdg_179_Ewdt.h and Wdg_179_Ewdt_Types.h are different"
#endif

/* Check if current file and Wdg_179_Ewdt_Types header file are of the same Autosar version */
#if ((WDG_179_EWDT_AR_RELEASE_MAJOR_VERSION    != WDG_179_EWDT_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_179_EWDT_AR_RELEASE_MINOR_VERSION    != WDG_179_EWDT_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (WDG_179_EWDT_AR_RELEASE_REVISION_VERSION != WDG_179_EWDT_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_179_Ewdt.h and Wdg_179_Ewdt_Types.h are different"
#endif

/* Check if current file and Wdg_179_Ewdt_Types header file are of the same software version */
#if ((WDG_179_EWDT_SW_MAJOR_VERSION != WDG_179_EWDT_TYPES_H_SW_MAJOR_VERSION) || \
     (WDG_179_EWDT_SW_MINOR_VERSION != WDG_179_EWDT_TYPES_H_SW_MINOR_VERSION) || \
     (WDG_179_EWDT_SW_PATCH_VERSION != WDG_179_EWDT_TYPES_H_SW_PATCH_VERSION))
#error "Software Version of Wdg_179_Ewdt.h and Wdg_179_Ewdt_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and WdgIf.h are the same Autosar version */
    #if ((WDG_179_EWDT_AR_RELEASE_MAJOR_VERSION != WDGIF_AR_RELEASE_MAJOR_VERSION) ||            \
         (WDG_179_EWDT_AR_RELEASE_MINOR_VERSION != WDGIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdg_Drvw_Types.h and WdgIf.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/**
 * @brief  Service ID
 */
#define    WDG_179_EWDT_SID_INIT                         ((uint8)0x00U)    
                                               
#define    WDG_179_EWDT_SID_SET_TRIGGER_CONDITION        ((uint8)0x03U)
#if (WDG_179_EWDT_VERSION_INFO_API == STD_ON)
    #define    WDG_179_EWDT_SID_GET_VERSION_INFO         ((uint8)0x04U)
#endif
#if (WDG_179_EWDT_DIRECT_SERVICE == STD_ON)
    #define    WDG_179_EWDT_SID_SERVICE                  ((uint8)0x05U)
#endif
#define    WDG_179_EWDT_SID_TRIGGER                      ((uint8)0x06U)

/**
 * @brief  API service used in wrong context
 */
#define     WDG_179_EWDT_E_DRIVER_STATE        ((uint8)0x10U)


/**
 * @brief  The passed timeout value is higher than the maximum timeout value
 */
#define     WDG_179_EWDT_E_PARAM_TIMEOUT       ((uint8)0x13U)

/**
 * @brief  API is called with wrong pointer value
 */
#define     WDG_179_EWDT_E_PARAM_POINTER       ((uint8)0x14U)

/**
 * @brief  Invalid configuration set selection
 */
#define     WDG_179_EWDT_E_INIT_FAILED         ((uint8)0x15U)

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (WDG_179_EWDT_PRECOMPILE_SUPPORT == STD_ON)
    #define WDG_179_EWDT_START_SEC_CONFIG_DATA_PTR
    #include "Wdg_179_Ewdt_MemMap.h"

extern const Wdg_179_Ewdt_ConfigType *const Wdg_179_Ewdt_PreDefinedConfigPtr;

    #define WDG_179_EWDT_STOP_SEC_CONFIG_DATA_PTR
    #include "Wdg_179_Ewdt_MemMap.h"

#else
    #define WDG_179_EWDT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Wdg_179_Ewdt_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
WDG_179_EWDT_CONFIG_EXT

    #define WDG_179_EWDT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Wdg_179_Ewdt_MemMap.h"
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#if (WDG_179_EWDT_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_START_SEC_CODE
#else
#define WDG_179_EWDT_START_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

/**
* @brief   This function initializes the WDG_179_EWDT module.
*
* @param[in] ConfigPtr     Pointer to configuration set.
*
* @return   None
*/
void Wdg_179_Ewdt_Init(const Wdg_179_Ewdt_ConfigType *ConfigPtr);

/**
* @brief   Switches the ewdt into the mode.
* @note    Due to hardware limitation,ewdt cannot support mode switch.So this function will return
*          E_NOT_OK all the time.
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
Std_ReturnType Wdg_179_Ewdt_SetMode(WdgIf_ModeType Mode);

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)
/**
 * @brief   Sets the timeout value for the trigger counter.
 *
 * @param[in] Timeout    Timeout value (milliseconds) for setting the trigger counter.
 * 
 * @return   None
 *  
 */
void Wdg_179_Ewdt_SetTriggerCondition(uint16 Timeout);
#endif

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_ON)
/**
* @brief   Service the ewdt directly
*
* @param[in] none
* 
* @return   None
* 
*/
void Wdg_179_Ewdt_Service(void);
#endif

#if (WDG_179_EWDT_VERSION_INFO_API == STD_ON)
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
void Wdg_179_Ewdt_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#if (WDG_179_EWDT_DIRECT_SERVICE == STD_OFF)

/**
 * @brief     Callback function for GPT notification.
 * 
 * @param[in] None
 * 
 * @return   None
 * 
 */
void Wdg_179_Ewdt_CallbackForGptNotification(void);
#endif

#if (WDG_179_EWDT_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_STOP_SEC_CODE
#else
#define WDG_179_EWDT_STOP_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

/** @} end of Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdg_179_Ewdt */

/** @} end of group Wdg_179_Ewdt_Module */
