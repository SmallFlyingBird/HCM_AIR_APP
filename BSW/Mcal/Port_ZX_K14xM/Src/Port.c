/**************************************************************************************************/
/**
 * @file      : Port.c
 * @brief     : AUTOSAR Port driver
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port
 *  @brief Port AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port.h"
#include "Port_Drvw.h"

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_C_VENDOR_ID                   0x00B3U
#define PORT_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_C_SW_MAJOR_VERSION            1U
#define PORT_C_SW_MINOR_VERSION            2U
#define PORT_C_SW_PATCH_VERSION            1U


#if (PORT_C_VENDOR_ID != PORT_VENDOR_ID)
    #error "Vendor id of Port.c and Port.h are different"
#endif

#if ((PORT_C_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) ||              \
     (PORT_C_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) ||              \
     (PORT_C_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port.c and Port.h are different"
#endif

#if ((PORT_C_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) ||                              \
     (PORT_C_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) ||                              \
     (PORT_C_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
    #error "Software version of Port.c and Port.h are different"
#endif

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    #ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
        #if ((PORT_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||       \
             (PORT_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of Port.c and Det.h are different"
        #endif
    #endif
#endif

#if (PORT_C_VENDOR_ID != PORT_DRVW_H_VENDOR_ID)
    #error "Vendor id of Port.h and Port_Drvw.h are different"
#endif

#if ((PORT_C_AR_RELEASE_MAJOR_VERSION != PORT_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (PORT_C_AR_RELEASE_MINOR_VERSION != PORT_DRVW_H_AR_RELEASE_MINOR_VERSION) ||       \
     (PORT_C_AR_RELEASE_REVISION_VERSION != PORT_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port.h and Port_Drvw.h are different"
#endif

#if ((PORT_C_SW_MAJOR_VERSION != PORT_DRVW_H_SW_MAJOR_VERSION) ||                       \
     (PORT_C_SW_MINOR_VERSION != PORT_DRVW_H_SW_MINOR_VERSION) ||                       \
     (PORT_C_SW_PATCH_VERSION != PORT_DRVW_H_SW_PATCH_VERSION))
    #error "Software version of Port.h and Port_Drvw.h are different"
#endif

#define PORT_GET_CORE_ID            (0U) 

/**
* @brief        Port Det Report Error Macro
*
*/
#define PORT_DET_REPORT_ERROR(ApiId, ErrorId)    \
(void)Det_ReportError((uint16)PORT_MODULE_ID,(uint8)PORT_INSTANCE_ID,         \
                      (uint8)(ApiId),(uint8)(ErrorId));     \

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define PORT_START_SEC_VAR_CLEARED_PTR
#include "Port_MemMap.h"

static const Port_ConfigType *Port_ConfigPtr;

#define PORT_STOP_SEC_VAR_CLEARED_PTR
#include "Port_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Port_CheckInit(uint32 PortCoreId,const Port_ConfigType *ConfigPtr);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
static Std_ReturnType Port_CheckSetPinDirection(Port_PinType PinIndex,
                                                const Port_ConfigType *ConfigPtr);
#endif /*STD_ON == PORT_SET_PIN_DIRECTION_API*/

#if (STD_ON == PORT_SET_PIN_MODE_API)
static Std_ReturnType Port_CheckSetPinMode(Port_PinType PinIndex, Port_PinModeType PinMode, 
                                           const Port_ConfigType *ConfigPtr);
#endif /*STD_ON == PORT_SET_PIN_MODE_API*/

static Std_ReturnType Port_CheckRefreshPortDirection(uint32 PortCoreId,
                                                    const Port_ConfigType *ConfigPtr);

#if (STD_ON == PORT_VERSION_INFO_API)
static Std_ReturnType Port_CheckGetVersionInfo(const Std_VersionInfoType *versioninfo);
#endif /*STD_ON == PORT_VERSION_INFO_API*/

#endif /*PORT_DEV_ERROR_DETECT == STD_ON*/
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function checks the initialization of driver.
 *
 * @param[in]  PortCoreId: Core ID
 * @param[in]  ConfigPtr: The pointer to the PORT configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      There is no checking error.
 * @retval     E_NOT_OK:  There is checking error.
 */
static Std_ReturnType Port_CheckInit(uint32 PortCoreId, const Port_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    const Port_ConfigType *TempConfigPtr;

#if (STD_ON == PORT_PRECOMPILE_SUPPORT)
    if ((NULL_PTR != ConfigPtr) || (NULL_PTR == Port_PreDefinedConfigPtr[PortCoreId]))  
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_INIT_ID,(uint8)PORT_E_INIT_FAILED);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#if (STD_ON == PORT_PRECOMPILE_SUPPORT)
        TempConfigPtr = Port_PreDefinedConfigPtr[PortCoreId]; 
#else
        TempConfigPtr = ConfigPtr;
#endif

        if ((uint32)1 != TempConfigPtr->Port_PartitionTable[PortCoreId])
        {
            PORT_DET_REPORT_ERROR((uint8)PORT_INIT_ID,(uint8)PORT_E_PARAM_CONFIG);
            Ret = (Std_ReturnType)E_NOT_OK;
        }
    }

    return Ret;
}

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/**
 * @brief      This function checks the set pin direction parameter.
 *
 * @param[in]  PinIndex: Port pin index
 * @param[in]  ConfigPtr: The pointer to the PORT configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      There is no checking error.
 * @retval     E_NOT_OK:  There is checking error.
 */
static Std_ReturnType Port_CheckSetPinDirection(Port_PinType PinIndex,
                                                const Port_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    Std_ReturnType PinDirectionError = (Std_ReturnType)E_OK;

    if (NULL_PTR == ConfigPtr)
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_DIRECTION_ID, (uint8)PORT_E_UNINIT);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if (PinIndex >= (Port_PinType)ConfigPtr->NumConfigPins)
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_DIRECTION_ID, (uint8)PORT_E_PARAM_PIN);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if ((uint32)1 != ConfigPtr->Port_PinsPartitionTable[PinIndex])
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_DIRECTION_ID, (uint8)PORT_E_PARAM_CONFIG);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else 
    {
        PinDirectionError = Port_Drvw_CheckPinDirectionChangeable(PinIndex,
                                                                  ConfigPtr->DrvwConfigPtr);
        if(PORT_E_DIRECTION_UNCHANGEABLE == PinDirectionError)
        {
            PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_DIRECTION_ID, 
                                  (uint8)PORT_E_DIRECTION_UNCHANGEABLE);
            Ret = (Std_ReturnType)E_NOT_OK;
        }
    }

    return Ret;
}
#endif /* STD_ON == PORT_SET_PIN_DIRECTION_API */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
 * @brief      This function checks the set pin mode api parameter
 *
 * @param[in]  PinIndex: Port pin index
 * @param[in]  PinMode: Port pin mode
 * @param[in]  ConfigPtr: The pointer to the PORT configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      There is no checking error.
 * @retval     E_NOT_OK:  There is checking error.
 */
static Std_ReturnType Port_CheckSetPinMode(Port_PinType PinIndex, Port_PinModeType PinMode, 
                                           const Port_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    Std_ReturnType PinModeError = (Std_ReturnType)E_OK;

    if (NULL_PTR == ConfigPtr)
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_MODE_ID, (uint8)PORT_E_UNINIT);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if (PinIndex >= (Port_PinType)ConfigPtr->NumConfigPins)
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_MODE_ID, (uint8)PORT_E_PARAM_PIN);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if ((uint32)1 != ConfigPtr->Port_PinsPartitionTable[PinIndex])
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_MODE_ID, (uint8)PORT_E_PARAM_CONFIG);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if(PORT_MAX_PINMUX_NUMBER <= PinMode)
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_MODE_ID, (uint8)PORT_E_PARAM_INVALID_MODE);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        PinModeError = Port_Drvw_CheckPinModeChangeable(PinIndex,ConfigPtr->DrvwConfigPtr);
        if(PORT_E_MODE_UNCHANGEABLE == PinModeError)
        {
            PORT_DET_REPORT_ERROR((uint8)PORT_SET_PIN_MODE_ID, (uint8)PORT_E_MODE_UNCHANGEABLE);
            Ret = (Std_ReturnType)E_NOT_OK;
        }

    }

    return Ret;
}
#endif /*STD_ON == PORT_SET_PIN_MODE_API*/

/**
 * @brief      This function checks the refresh port direction api parameter
 *
 * @param[in]  PortCoreId: Core Id
 * @param[in]  ConfigPtr: The pointer to the PORT configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      There is no checking error.
 * @retval     E_NOT_OK:  There is checking error.
 */
static Std_ReturnType Port_CheckRefreshPortDirection(uint32 PortCoreId,
                                                     const Port_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR == ConfigPtr)
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_REFRESH_PIN_DIRECTION_ID, (uint8)PORT_E_UNINIT);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if ((uint32)1 != ConfigPtr->Port_PartitionTable[PortCoreId])
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_REFRESH_PIN_DIRECTION_ID, (uint8)PORT_E_PARAM_CONFIG);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*Do nothing*/
    }

    return Ret;
}

/**
 * @brief      This function checks the get version api parameter
 *
 * @param[in]  versioninfo: The pointer to the version structure.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      There is no checking error.
 * @retval     E_NOT_OK:  There is checking error.
 */
#if (STD_ON == PORT_VERSION_INFO_API)
static Std_ReturnType Port_CheckGetVersionInfo(const Std_VersionInfoType *versioninfo)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR == versioninfo)
    {
        PORT_DET_REPORT_ERROR((uint8)PORT_GET_VERSION_INFO_ID, (uint8)PORT_E_PARAM_POINTER);
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    return Ret;
}
#endif /*STD_ON == PORT_VERSION_INFO_API*/

#endif /* PORT_DEV_ERROR_DETECT == STD_ON*/

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/**
 * @brief     Initialize all ports and port pins with the configuration set
 *            pointed to by the parameter ConfigPtr.
 *
 * @param[in] ConfigPtr: Pointer to port configuration structure
 * 
 * @return    None
 */
/* SWS_Port_00001,SWS_Port_00217,SWS_Port_00218,SWS_Port_00121*/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    uint8 PortCoreId;

    PortCoreId = (uint8)PORT_GET_CORE_ID;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Port_CheckInit(PortCoreId, ConfigPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif

#if (STD_ON == PORT_PRECOMPILE_SUPPORT)

        Port_ConfigPtr = Port_PreDefinedConfigPtr[PortCoreId];
#else
        (void)PortCoreId;
        Port_ConfigPtr = ConfigPtr;
#endif

        Port_Drvw_Init(Port_ConfigPtr->DrvwConfigPtr);

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/**
 * @brief      Set the port pin direction during runtime.
 *
 * @param[in] Pin:          Port pin index
 * @param[in] Direction:    Port pin direction
 * 
 * @return    None
 */
/* SWS_Port_00054*/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Port_CheckSetPinDirection(Pin, Port_ConfigPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif
        Port_Drvw_SetPinDirection((Port_Drvw_PinType)Pin, (Port_Drvw_DirectionType)Direction, 
                                  Port_ConfigPtr->DrvwConfigPtr);

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    }
#endif

}
#endif /* STD_ON == PORT_SET_PIN_DIRECTION_API*/

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
 * @brief     Set the port pin mode of the referenced pin during runtime.
 *
 * @param[in] Pin :    Port pin index
 * @param[in] Mode:    Port pin pinmux mode
 *
 * @return    None
 */
/* SWS_Port_00212,SWS_Port_00128*/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Port_CheckSetPinMode(Pin, Mode, Port_ConfigPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif
        Port_Drvw_SetPinMode((Port_Drvw_PinType)Pin, (Port_Drvw_PinModeType)Mode, 
                             Port_ConfigPtr->DrvwConfigPtr);

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    }
#endif
}
#endif /*STD_ON == PORT_SET_PIN_MODE_API*/

/**
 * @brief     Refresh the direction of all configured ports to the configured direction.
 *
 * @param[in] None
 * 
 * @return    None
 */
void Port_RefreshPortDirection(void)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    uint8          PortCoreId;

    PortCoreId = (uint8)PORT_GET_CORE_ID;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Port_CheckRefreshPortDirection(PortCoreId, Port_ConfigPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif
        Port_Drvw_RefreshPortDirection(Port_ConfigPtr->DrvwConfigPtr);

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    }
#endif
}

#if (STD_ON == PORT_VERSION_INFO_API)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] versioninfo: Pointer to version type structure
 * 
 * @return    None
 */
/* SWS_Port_00129 */
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Port_CheckGetVersionInfo(versioninfo);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif
        (versioninfo)->vendorID = (uint16)PORT_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)PORT_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    }
#endif
}
#endif /* STD_ON == PORT_VERSION_INFO_API*/

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Port */

/** @} end of group Port_Module */
