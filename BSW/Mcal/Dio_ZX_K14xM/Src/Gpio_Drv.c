/**************************************************************************************************/
/**
 * @file      : Gpio_Drv.c
 * @brief     : Internal gpio low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Gpio_Module
 *  @{
 */

/** @addtogroup Gpio_Drv
 *  @brief Internal Gpio low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpio_Drv.h"
#include "Device_Regs.h"
#include "SchM_Dio.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define GPIO_DRV_C_VENDOR_ID                   0x00B3U
#define GPIO_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define GPIO_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define GPIO_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define GPIO_DRV_C_SW_MAJOR_VERSION            1U
#define GPIO_DRV_C_SW_MINOR_VERSION            2U
#define GPIO_DRV_C_SW_PATCH_VERSION            1U

/**
 *  @brief Check if current file and Gpio_Drv header file are of the same vendor
 */
#if (GPIO_DRV_H_VENDOR_ID != GPIO_DRV_C_VENDOR_ID)
    #error "Vendor ID of Gpio_Drv.h and Gpio_Drv.c are different "
#endif
/**
 *  @brief Check if current file and Gpio_Drv header file are of the same Autosar version
 */
#if ((GPIO_DRV_H_AR_RELEASE_MAJOR_VERSION != GPIO_DRV_C_AR_RELEASE_MAJOR_VERSION) ||               \
     (GPIO_DRV_H_AR_RELEASE_MINOR_VERSION != GPIO_DRV_C_AR_RELEASE_MINOR_VERSION) ||               \
     (GPIO_DRV_H_AR_RELEASE_REVISION_VERSION != GPIO_DRV_C_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Gpio_Drv.c and Gpio_Drv.h are different"
#endif

#if ((GPIO_DRV_H_SW_MAJOR_VERSION != GPIO_DRV_C_SW_MAJOR_VERSION) ||                               \
     (GPIO_DRV_H_SW_MINOR_VERSION != GPIO_DRV_C_SW_MINOR_VERSION) ||                               \
     (GPIO_DRV_H_SW_PATCH_VERSION != GPIO_DRV_C_SW_PATCH_VERSION))
    #error "Software Version of Gpio_Drv.c and Gpio_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((GPIO_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (GPIO_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Gpio_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Dio header file are of the same Autosar version */
    #if ((GPIO_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_DIO_H_AR_RELEASE_MAJOR_VERSION) ||           \
         (GPIO_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_DIO_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Gpio_Drv.c and SchM_Dio.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Number of instances of the GPIO module. */
#define GPIO_DRV_INSTANCE_NUM (5U)
/** @} end of group Private_MacroDefinition */
/** @defgroup Private_VariableDefinition
 *  @{
 */

#define DIO_START_SEC_CONST_PTR
#include "Dio_MemMap.h"

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
 no side effects forseen by violating this rule.
 The following five lines of code also violate this rule with the same reason. */
static Reg_Gpio_WType *const Gpio_Drv_GpioRegWPtr[GPIO_DRV_INSTANCE_NUM] = {
    (Reg_Gpio_WType *)GPIOA_BASE_ADDR, /*!< GPIO A base address */
    (Reg_Gpio_WType *)GPIOB_BASE_ADDR, /*!< GPIO B base address */
    (Reg_Gpio_WType *)GPIOC_BASE_ADDR, /*!< GPIO C base address */
    (Reg_Gpio_WType *)GPIOD_BASE_ADDR, /*!< GPIO D base address */
    (Reg_Gpio_WType *)GPIOE_BASE_ADDR  /*!< GPIO E base address */
};

#define DIO_STOP_SEC_CONST_PTR
#include "Dio_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration*/

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

/** @defgroup Public_FunctionDefinition
 *  @{
 */
/**
 * @brief          Returns the value of the specified GPIO channel.
 *
 * @param[in]      Base: ID of GPIO port.
 * @param[in]      Pin: The specified GPIO channel.
 *
 * @return         Gpio_Drv_PinsLevelType: Returns the level of the corresponding pin
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: The physical level of the corresponding Pin is STD_LOW.
 *
 */
Gpio_Drv_PinsLevelType Gpio_Drv_ReadPin(const uint32 Base, Gpio_Drv_PinsChannelType Pin)
{
    Gpio_Drv_PinsLevelType ReturnValue = 0U;
    const Reg_Gpio_WType *Gpiox = Gpio_Drv_GpioRegWPtr[Base];

    ReturnValue = (Gpio_Drv_PinsLevelType)(((Gpiox->GPIOx_PDIR) & ((uint32)1 << Pin)) >> (Pin));
    return ReturnValue;
}

/**
 * @brief          Set the level of a channel.
 *
 * @param[in]      Base: ID of GPIO port.
 * @param[in]      Pin: The specified GPIO channel.
 * @param[in]      Value: Value to be written.
 *
 * @return         None.
 */
void Gpio_Drv_WritePin(const uint32 Base, Gpio_Drv_PinsChannelType Pin,
                       Gpio_Drv_PinsLevelType Value)
{
    SchM_Enter_Dio_WritePortData();
    Reg_Gpio_WType *Gpiox = Gpio_Drv_GpioRegWPtr[Base];

    Gpio_Drv_PinsChannelType PinsValues = (Gpio_Drv_PinsChannelType)Gpiox->GPIOx_PDOR;
    PinsValues &= ~((Gpio_Drv_PinsChannelType)1U << Pin);
    PinsValues |= (Gpio_Drv_PinsChannelType)Value << Pin;
    Gpiox->GPIOx_PDOR = PinsValues;
    SchM_Exit_Dio_WritePortData();
}

/**
 * @brief          Toggle (change from 1 to 0 or from 0 to 1) the level of a
 *                 channel
 *
 * @param[in]      Base: ID of GPIO channel.
 * @param[in]      Pins: The specified GPIO channel.
 *
 * @return         None.
 *
 */
void Gpio_Drv_TogglePins(const uint32 Base, Gpio_Drv_PinsChannelType Pins)
{
    Reg_Gpio_WType *Gpiox = Gpio_Drv_GpioRegWPtr[Base];

    Gpiox->GPIOx_PTOR = Pins;
}

/**
 * @brief          Get the level of a port.
 *
 * @param[in]      Base: ID of GPIO port.
 *
 * @return         Gpio_Drv_PinsChannelType: Returns the level of the corresponding port
 *
 */
Gpio_Drv_PinsChannelType Gpio_Drv_GetPinsOutput(const uint32 Base)
{
    Gpio_Drv_PinsChannelType ReturnValue = 0U;
    const Reg_Gpio_WType *Gpiox = Gpio_Drv_GpioRegWPtr[Base];

    ReturnValue = (Gpio_Drv_PinsChannelType)(Gpiox->GPIOx_PDOR);
    return ReturnValue;
}

/**
 * @brief          Returns the value of the specified GPIO port.
 *
 * @param[in]      Base: ID of GPIO port.
 *
 * @return         Gpio_Drv_PinsChannelType: Returns the level of the corresponding port
 *
 */
Gpio_Drv_PinsChannelType Gpio_Drv_ReadPins(const uint32 Base)
{
    Gpio_Drv_PinsChannelType ReturnValue = 0U;
    const Reg_Gpio_WType    *Gpiox = Gpio_Drv_GpioRegWPtr[Base];
    ReturnValue = (Gpio_Drv_PinsChannelType)(Gpiox->GPIOx_PDIR);
    return ReturnValue;
}

/**
 * @brief          Set the level of a port.
 *
 * @param[in]      Base: ID of GPIO port.
 * @param[in]      Pins: Value to be written for the specified port.
 *
 * @return         None.
 */
void Gpio_Drv_WritePort(const uint32 Base, Gpio_Drv_PinsChannelType Pins)
{
    Reg_Gpio_WType *Gpiox = Gpio_Drv_GpioRegWPtr[Base];

    Gpiox->GPIOx_PDOR = (uint32)(Pins);
}

/**
 * @brief          Set the level of a port.
 *
 * @param[in]      Base: ID of GPIO port.
 * @param[in]      Pins: The specified GPIO channel.
 *
 * @return         None.
 */
void Gpio_Drv_SetPins(const uint32 Base, Gpio_Drv_PinsChannelType Pins)
{
    Reg_Gpio_WType *Gpiox = Gpio_Drv_GpioRegWPtr[Base];

    Gpiox->GPIOx_PSOR = (uint32)(Pins);
}

/**
 * @brief          Clear the level of a port.
 *
 * @param[in]      Base: ID of GPIO port.
 * @param[in]      Pin: The specified GPIO channel.
 *
 * @return         None.
 */
void Gpio_Drv_ClearPins(const uint32 Base, Gpio_Drv_PinsChannelType Pins)
{
    Reg_Gpio_WType *Gpiox = Gpio_Drv_GpioRegWPtr[Base];

    Gpiox->GPIOx_PCOR = (uint32)(Pins);
}
/** @} end of group Public_FunctionDefinition */
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Gpio_Drv */

/** @} end of group Dio_Module */
