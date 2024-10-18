/**************************************************************************************************/
/**
 * @file      : Port_Drvw.c
 * @brief     : AUTOSAR Port drvw driver
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

/** @addtogroup Port_Drvw
 *  @brief Port driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_Drvw.h"
#include "Port_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRVW_C_VENDOR_ID                   0x00B3U
#define PORT_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRVW_C_SW_MAJOR_VERSION            1U
#define PORT_DRVW_C_SW_MINOR_VERSION            2U
#define PORT_DRVW_C_SW_PATCH_VERSION            1U

#if (PORT_DRVW_C_VENDOR_ID != PORT_DRVW_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw.c and Port_Drvw.h are different"
#endif

#if ((PORT_DRVW_C_AR_RELEASE_MAJOR_VERSION != PORT_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (PORT_DRVW_C_AR_RELEASE_MINOR_VERSION != PORT_DRVW_H_AR_RELEASE_MINOR_VERSION) ||             \
     (PORT_DRVW_C_AR_RELEASE_REVISION_VERSION != PORT_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drvw.c and Port_Drvw.h are different"
#endif

#if ((PORT_DRVW_C_SW_MAJOR_VERSION != PORT_DRVW_H_SW_MAJOR_VERSION) ||                             \
     (PORT_DRVW_C_SW_MINOR_VERSION != PORT_DRVW_H_SW_MINOR_VERSION) ||                             \
     (PORT_DRVW_C_SW_PATCH_VERSION != PORT_DRVW_H_SW_PATCH_VERSION))
    #error "Software version of Port_Drvw.c and Port_Drvw.h are different"
#endif


#if (PORT_DRVW_C_VENDOR_ID != PORT_DRV_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw.c and Port_Drv.h are different"
#endif

#if ((PORT_DRVW_C_AR_RELEASE_MAJOR_VERSION != PORT_DRV_H_AR_RELEASE_MAJOR_VERSION) ||              \
     (PORT_DRVW_C_AR_RELEASE_MINOR_VERSION != PORT_DRV_H_AR_RELEASE_MINOR_VERSION) ||              \
     (PORT_DRVW_C_AR_RELEASE_REVISION_VERSION != PORT_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drvw.c and PoPort_Drv.h are different"
#endif

#if ((PORT_DRVW_C_SW_MAJOR_VERSION != PORT_DRV_H_SW_MAJOR_VERSION) ||                              \
     (PORT_DRVW_C_SW_MINOR_VERSION != PORT_DRV_H_SW_MINOR_VERSION) ||                              \
     (PORT_DRVW_C_SW_PATCH_VERSION != PORT_DRV_H_SW_PATCH_VERSION))
    #error "Software version of Port_Drvw.c and Port_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
 
/** @} end of group Global_VariableDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
 * @brief     This function initializes the unused pins
 *
 * @param[in] DrvwConfigPtr: Pointer to configuration set
 * 
 * @return    None
 */
static void Port_Drvw_InitUnconfigPins(const Port_Drvw_ConfigType *DrvwConfigPtr);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
 * @brief     This function initializes the unused pins
 *
 * @param[in] DrvwConfigPtr: Pointer to configuration set
 * 
 * @return    None
 */
static void Port_Drvw_InitUnconfigPins(const Port_Drvw_ConfigType *DrvwConfigPtr)
{
    uint16          PinIndex;
    uint16          PinNumber;
    Port_Drvw_PortIdType PortId;
    Port_Drvw_GpioNoType GpioNo;

    uint16                NumUnconfigPins = (uint16)(DrvwConfigPtr->NumUnconfigPins);
    uint8                 PinLevel = DrvwConfigPtr->UnconfigPinConfigAttr->PinOutputLevel;
    Port_Drvw_SlewRateType SlewValue = DrvwConfigPtr->UnconfigPinConfigAttr->PinSlewRate;
    Port_Drvw_PullConfigType PullConfig = DrvwConfigPtr->UnconfigPinConfigAttr->PinPullConfig;
    Port_Drvw_DirectionType PinDirection = (Port_Drvw_DirectionType)
                                            DrvwConfigPtr->UnconfigPinConfigAttr->PinDirection;

    for (PinIndex = (uint16)0U; PinIndex < NumUnconfigPins; PinIndex++)
    {
        PinNumber = DrvwConfigPtr->UnconfigPinList[PinIndex];
        PortId = (Port_Drvw_PortIdType)PORT_DRVW_GET_PORT_ID(PinNumber);
        GpioNo = (Port_Drvw_GpioNoType)PORT_DRVW_GET_GPIO_ID(PinNumber);

        Port_Drv_SetSlewRate((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo,
                             (Port_Drv_SlewRateType)SlewValue);
        Port_Drv_SetPullConfig((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo,
                               (Port_Drv_PullConfigType)PullConfig);

        /* Set output level if the direction is PORT_PIN_OUT*/
        if (PORT_DRVW_PIN_OUT == PinDirection)
        {
            /* Set pin to High value */
            if (PORT_DRVW_PIN_LEVEL_HIGH == PinLevel)
            {
                Port_Drv_SetPinOutput((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo);
            }
            /* Set pin to LOW value*/
            else
            {
                Port_Drv_ClearPinOutput((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo);
            }

            (void)Port_Drv_SetPinDirection((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo,
                (Port_Drv_DirectionType)DrvwConfigPtr->UnconfigPinConfigAttr->PinDirection);
        }
        /* The direction of pin is PORT_DRVW_PIN_IN */
        else
        {
            (void)Port_Drv_SetPinDirection((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo,
                                           (Port_Drv_DirectionType)PORT_DRVW_PIN_IN);
        }
    }
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
 * @brief     This function initializes both the configured and un-configured pins
 *
 * @param[in] DrvwConfigPtr: Pointer to configuration set
 * 
 * @return    None
 */
void Port_Drvw_Init(const Port_Drvw_ConfigType *DrvwConfigPtr)
{

    Port_Drv_Init(NUMBER_OF_CONFIG_PINS, DrvwConfigPtr->DrvConfigPtr);

    /* Init un-configured pins */
    Port_Drvw_InitUnconfigPins(DrvwConfigPtr);
}

#if (STD_ON == PORT_DRVW_DEV_ERROR_DETECT)

#if (STD_ON == PORT_DRVW_SET_PIN_DIRECTION_API)
/**
 * @brief     This function checks if the port pin direction is changeable.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    Pin direction check status
 * @retval    E_OK: Pin direction is changeable
 * @retval    PORT_DRVW_E_DIRECTION_UNCHANGEABLE: Pin direction is not changeable
 */
Std_ReturnType Port_Drvw_CheckPinDirectionChangeable(Port_Drvw_PinType PinIndex,
                                                     const Port_Drvw_ConfigType *DrvwConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    /*Port pin direction will not change*/
    if (FALSE == DrvwConfigPtr->ConfigPinAttr[PinIndex].DirectionChangebility)
    {
        Ret = PORT_DRVW_E_DIRECTION_UNCHANGEABLE;
    }

    return Ret;
}
#endif /*(STD_ON == PORT_DRVW_SET_PIN_DIRECTION_API)*/

#if (STD_ON == PORT_DRVW_SET_PIN_MODE_API)
/**
 * @brief     This function checks if the port pin mode is changeable.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    Pin mode check status
 * @retval    E_OK: Pin mode is changeable
 * @retval    PORT_DRVW_E_MODE_UNCHANGEABLE: Pin mode is not changeable
 */
Std_ReturnType Port_Drvw_CheckPinModeChangeable(Port_Drvw_PinType PinIndex,
                                                const Port_Drvw_ConfigType *DrvwConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    /*Port pin direction will not change*/
    if (FALSE == DrvwConfigPtr->ConfigPinAttr[PinIndex].ModeChangebility)
    {
        Ret = PORT_DRVW_E_MODE_UNCHANGEABLE;
    }

    return Ret;
}
#endif /*(STD_ON == PORT_DRVW_SET_PIN_MODE_API)*/

#endif /*(STD_ON == PORT_DRVW_DEV_ERROR_DETECT)*/

#if (STD_ON == PORT_DRVW_SET_PIN_DIRECTION_API)
/**
 * @brief     This function sets the port pin direction.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] Direction:    Port pin direction
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    None
 */
/* SWS_Port_00129 */
void Port_Drvw_SetPinDirection(Port_Drvw_PinType PinIndex, Port_Drvw_DirectionType Direction,
                                         const Port_Drvw_ConfigType *DrvwConfigPtr)
{
    uint16           PinNumber = DrvwConfigPtr->ConfigPinAttr[PinIndex].Pin;
    Port_Drvw_PortIdType PortId = (Port_Drvw_PortIdType)PORT_DRVW_GET_PORT_ID(PinNumber);
    Port_Drvw_GpioNoType GpioNo = (Port_Drvw_GpioNoType)PORT_DRVW_GET_GPIO_ID(PinNumber);

    /* Set Port pin direction */
    if((PORT_DRVW_PIN_IN == Direction) || (PORT_DRVW_PIN_OUT == Direction))
    {
        Port_Drv_SetPinDirection((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo, \
            (Port_Drv_DirectionType)Direction);
    }
    else
    {
        /*Do nothing*/
    }
}
#endif

#if (STD_ON == PORT_DRVW_SET_PIN_MODE_API)
/**
 * @brief     This function sets the port pin pinmux mode.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] PinMode:      Port pin pinmux mode
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    None
 */
/* SWS_Port_00129 */
void Port_Drvw_SetPinMode(Port_Drvw_PinType PinIndex, Port_Drvw_PinModeType PinMode,
                                    const Port_Drvw_ConfigType *DrvwConfigPtr)
{
    uint16          PinNumber = DrvwConfigPtr->ConfigPinAttr[PinIndex].Pin;
    Port_Drvw_PortIdType PortId = (Port_Drvw_PortIdType)PORT_DRVW_GET_PORT_ID(PinNumber);
    Port_Drvw_GpioNoType GpioNo = (Port_Drvw_GpioNoType)PORT_DRVW_GET_GPIO_ID(PinNumber);

    Port_Drvw_DirectionType PinDirection = PORT_DRVW_PIN_IN;

    if(PORT_DRVW_PIN_MODE_GPIO == PinMode)
    {
        PinDirection = (Port_Drvw_DirectionType)DrvwConfigPtr->ConfigPinAttr[PinIndex].PinDirection;
        Port_Drv_SetPinDirection((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo,
                                 (Port_Drv_DirectionType)PinDirection);
    }
    else
    {
            /*Nothing to do*/
    }

    Port_Drv_SetPinMode((Port_Drv_PortIdType)PortId, (Port_Drv_GpioNoType)GpioNo,
                        (Port_Drv_PortMuxType)PinMode);
}
#endif /*(STD_ON == PORT_DRVW_SET_PIN_MODE_API)*/

/**
 * @brief     This function refresh the port direction for used pins.
 *
 * @param[in] DrvwConfigPtr: Pointer to configuration set
 * 
 * @return    None
 */
void Port_Drvw_RefreshPortDirection(const Port_Drvw_ConfigType *DrvwConfigPtr)
{
    uint16 NumConfigPins = DrvwConfigPtr->NumConfigPins;
    /* Index of the port table */
    uint16 PinIndex;
    uint16 PinNumber;

    /* refresh port pin with direction attribute that are not changeable */
    for (PinIndex = (uint16)0U; PinIndex < NumConfigPins; PinIndex++)
    {
        if (FALSE == DrvwConfigPtr->ConfigPinAttr[PinIndex].DirectionChangebility)
        {  
            if (TRUE == DrvwConfigPtr->ConfigPinAttr[PinIndex].GPIO)
            {
                PinNumber = DrvwConfigPtr->ConfigPinAttr[PinIndex].Pin;

                Port_Drvw_PortIdType PortId = (Port_Drvw_PortIdType)
                                               PORT_DRVW_GET_PORT_ID(PinNumber);
                Port_Drvw_GpioNoType GpioNo = (Port_Drvw_GpioNoType)
                                               PORT_DRVW_GET_GPIO_ID(PinNumber);

                /* Set Port pin direction */
                (void)Port_Drv_SetPinDirection((Port_Drv_PortIdType)PortId, 
                                               (Port_Drv_GpioNoType)GpioNo,
                                               (Port_Drv_DirectionType)
                                               DrvwConfigPtr->ConfigPinAttr[PinIndex].PinDirection);
            }
            else
            {
            /*Keep Empty*/
            }
        }
    }
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Port_Drvw */

/** @} end of group Port_Module */
