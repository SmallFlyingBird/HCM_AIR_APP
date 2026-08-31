/**
* @file    Port.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Port
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
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Port.h"
#include "Port_Lld.h"
#include "OsIf.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* PORT_DEV_ERROR_DETECT == STD_ON */
/*==================================================================================================
 *                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_VENDOR_ID_C                      (180)
#define PORT_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PORT_AR_RELEASE_MINOR_VERSION_C       (4)
#define PORT_AR_RELEASE_REVISION_VERSION_C    (0)
#define PORT_SW_MAJOR_VERSION_C               (2)
#define PORT_SW_MINOR_VERSION_C               (3)
#define PORT_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
 *                                        FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PORT header file are of the same vendor */
#if (PORT_VENDOR_ID_C != PORT_VENDOR_ID)
#error "Port.c and Port.h have different vendor ids"
#endif

/* Check if source file and PORT header file are of the same Autosar version */
#if (( PORT_AR_RELEASE_MAJOR_VERSION_C != PORT_AR_RELEASE_MAJOR_VERSION) || \
      ( PORT_AR_RELEASE_MINOR_VERSION_C != PORT_AR_RELEASE_MINOR_VERSION) || \
      ( PORT_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Port.c and Port.h are different"
#endif

/* Check if source file and PORT header file are of the same Software version */
#if (( PORT_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION) || \
      ( PORT_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION) || \
      ( PORT_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION))
#error "Software Version Numbers of Port.c and Port.h are different"
#endif

/*==================================================================================================
 *                                         GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                                          LOCAL VARIABLES
==================================================================================================*/
#define PORT_START_SEC_VAR_INIT_32
#include "Port_MemMap.h"
#if (PORT_FIXED_PB_CONFIG == STD_ON)
extern const Port_ConfigType Port_PreCompileConfig;
PORT_VAR static Port_ConfigType const *Port_ConfigPtr = &Port_PreCompileConfig;
#else
PORT_VAR static Port_ConfigType const *Port_ConfigPtr = NULL_PTR;
#endif


#if (PORT_DEV_ERROR_DETECT == STD_ON)
typedef enum
{
    PORT_UNINIT = 0U,  /**< Port not initializesed */
    PORT_INIT_OK = 1U, /**< Port initializesed */
} Port_InitStateType;


/**
 * @brief Port initializes state variable
 */
PORT_VAR static Port_InitStateType Port_InitState = PORT_UNINIT;
#endif


#define PORT_STOP_SEC_VAR_INIT_32
#include "Port_MemMap.h"
/*==================================================================================================
 *                                          LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
 *                                           LOCAL MACROS
==================================================================================================*/
#define Port_IsCorrectPortPinId(Port, Pin) (((Port) < PORT_TOTAL_NUMBER) && ((Pin) < PORT_PIN_TOTAL_NUMBER))

#if (PORT_FIXED_PB_CONFIG == STD_ON)
#define PORT_UNUSED_PARAM(parma) ((void)parma)
#endif
/*==================================================================================================
 *                                          LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
PORT_FUNC void Port_Init(const Port_ConfigType *ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameters
       Trace : SWS_Port_00077 */
    uint8 ErrorState = E_OK;
#if (PORT_FIXED_PB_CONFIG == STD_ON)
    if (NULL_PTR == Port_ConfigPtr)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_INIT, PORT_E_PARAM_CONFIG);
        ErrorState = E_NOT_OK;
    }
#else
    if (NULL_PTR == ConfigPtr)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_INIT, PORT_E_PARAM_CONFIG);
        ErrorState = E_NOT_OK;
    }
#endif
#endif
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (E_OK == ErrorState)
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
    {
#if (PORT_FIXED_PB_CONFIG == STD_ON)
        PORT_UNUSED_PARAM(ConfigPtr); /* To avoid compiler warning */
#else
        Port_ConfigPtr = ConfigPtr;
#endif
#ifdef PORT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Port_Lld_Init, Port_ConfigPtr);
#else
        Port_Lld_Init(Port_ConfigPtr);
#endif
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        Port_InitState = PORT_INIT_OK;
#endif
    }
}

PORT_FUNC void Port_RefreshPortDirection(void)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check the Port init state
       Trace : SWS_Port_00077 */
    if (PORT_UNINIT == Port_InitState)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_REFRESH_PORT_SID_DIRECTION, PORT_E_UNINIT);
    }
    else
#endif
    {
#ifdef PORT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Port_Lld_RefreshPortDirection, Port_ConfigPtr);
#else
        Port_Lld_RefreshPortDirection(Port_ConfigPtr);
#endif
    }
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
PORT_FUNC void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    Port_HwPortType PortHwId = (Port_HwPortType)((Pin & PORT_HW_ID_PORT_MASK) >> 8);
    Port_HwPinType PinHwId = (Port_HwPinType)(Pin & PORT_HW_ID_PIN_MASK);

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check the Port init state
       Trace : SWS_Port_00077 */
    if (PORT_UNINIT == Port_InitState)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_SET_PIN_DIRECTION, PORT_E_UNINIT);
    }
    /* Check the function parameters
       Trace : SWS_Port_00077 */
    else if (!Port_IsCorrectPortPinId(PortHwId, PinHwId))
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_SET_PIN_DIRECTION, PORT_E_PARAM_PIN);
    }
    /* Check the port Pin not configured as changeable
       Trace : SWS_Port_00077 */
    else if (FALSE == Port_Lld_IsPinDireChangeable(Port_ConfigPtr, PortHwId, PinHwId))
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_SET_PIN_DIRECTION, PORT_E_DIRECTION_UNCHANGEABLE);
    }
    else
#endif
    {
#ifdef PORT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call3params(Port_Lld_SetPinDirection, PortHwId, PinHwId, Direction);
#else
        Port_Lld_SetPinDirection(PortHwId, PinHwId, Direction);
#endif
    }
}
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
PORT_FUNC void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    Port_HwPortType PortHwId = (Port_HwPortType)((Pin & PORT_HW_ID_PORT_MASK) >> 8);
    Port_HwPinType PinHwId = (Port_HwPinType)(Pin & PORT_HW_ID_PIN_MASK);
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check the Port init state
       Trace : SWS_Port_00077 */
    if (PORT_UNINIT == Port_InitState)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_SET_PIN_MODE, PORT_E_UNINIT);
    }
    /* Check the function parameters - Pin
       Trace : SWS_Port_00077 */
    else if (!Port_IsCorrectPortPinId(PortHwId, PinHwId))
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_SET_PIN_MODE, PORT_E_PARAM_PIN);
    }
    /* Check the function parameters - Mode
       Trace : SWS_Port_00077 */
    else if (Mode >= PORT_PIN_MODE_NUMS)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_SET_PIN_MODE, PORT_E_PARAM_INVALID_MODE);
    }
    /* Check the port pin mode changeable or not
       Trace : SWS_Port_00077 */
    else if (FALSE == Port_Lld_IsPinModeChangeable(Port_ConfigPtr, PortHwId, PinHwId))
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SID_SET_PIN_MODE, PORT_E_MODE_UNCHANGEABLE);
    }
    else
#endif
    {
        /* Assign the PCR_MUX register */
#ifdef PORT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call3params(Port_Lld_SetPinMode, PortHwId, PinHwId, Mode);
#else
        Port_Lld_SetPinMode(PortHwId, PinHwId, Mode);
#endif
    }
}
#endif

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"


#ifdef __cplusplus
}
#endif
/* End of file Port.c */

