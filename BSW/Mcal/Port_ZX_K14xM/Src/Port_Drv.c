/**************************************************************************************************/
/**
 * @file      : Port_Drv.c
 * @brief     : AUTOSAR Port low level driver
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

/** @addtogroup Port_Drv
 *  @brief Port low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_Drv.h"
#include "SchM_Port.h"
#include "Device_Regs.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRV_C_VENDOR_ID                   0x00B3U
#define PORT_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRV_C_SW_MAJOR_VERSION            1U
#define PORT_DRV_C_SW_MINOR_VERSION            2U
#define PORT_DRV_C_SW_PATCH_VERSION            1U

#if (PORT_DRV_C_VENDOR_ID != PORT_DRV_H_VENDOR_ID)
    #error "Vendor id of Port_Drv.c and Port_Drv.h are different"
#endif

#if ((PORT_DRV_C_AR_RELEASE_MAJOR_VERSION != PORT_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (PORT_DRV_C_AR_RELEASE_MINOR_VERSION != PORT_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (PORT_DRV_C_AR_RELEASE_REVISION_VERSION != PORT_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drv.c and Port_Drv.h are different"
#endif

#if ((PORT_DRV_C_SW_MAJOR_VERSION != PORT_DRV_H_SW_MAJOR_VERSION) ||                               \
     (PORT_DRV_C_SW_MINOR_VERSION != PORT_DRV_H_SW_MINOR_VERSION) ||                               \
     (PORT_DRV_C_SW_PATCH_VERSION != PORT_DRV_H_SW_PATCH_VERSION))
    #error "Software version of Port_Drv.c and Port_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((PORT_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_PORT_AR_RELEASE_MAJOR_VERSION) ||            \
         (PORT_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_PORT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Port_Drv.c and SchM_Port.h are different"
    #endif
#endif

/* Check if current file and  Reg_Dio header file are of the same Autosar version */
#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((PORT_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (PORT_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Port_Drv.c and Device_Regs.h are different"
    #endif
#endif

#define PORT_START_SEC_CONST_32
#include "Port_MemMap.h"
/**
 * @brief Base address array for PORT instances
 */
#define PORT_DRV_PORT_TOTAL_NUM 5U

/**
 * @brief Base address array for GPIO instances
 */
#define PORT_DRV_GPIO_TOTAL_NUM 5U

#define GPIOA_BASE_ADDR (GPIO_BASE_ADDR + 0x00UL)
#define GPIOB_BASE_ADDR (GPIO_BASE_ADDR + 0x40UL)
#define GPIOC_BASE_ADDR (GPIO_BASE_ADDR + 0x80UL)
#define GPIOD_BASE_ADDR (GPIO_BASE_ADDR + 0xC0UL)
#define GPIOE_BASE_ADDR (GPIO_BASE_ADDR + 0x100UL)

#define PORT_STOP_SEC_CONST_32
#include "Port_MemMap.h"
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define PORT_START_SEC_CONST_PTR
#include "Port_MemMap.h"

/* MISRA2012 Rule-11.4 violation: Convert an integral type of register address to a pointer object, 
 no side effects forseen by violating this rule.
 The following three lines of code also violate this rule with the same reason. */
static Reg_Port_BfType * const Port_Drv_PortRegBfPtr[PORT_DRV_PORT_TOTAL_NUM] = 
{
    (Reg_Port_BfType *)PORTA_BASE_ADDR, (Reg_Port_BfType *)PORTB_BASE_ADDR,
    (Reg_Port_BfType *)PORTC_BASE_ADDR, (Reg_Port_BfType *)PORTD_BASE_ADDR,
    (Reg_Port_BfType *)PORTE_BASE_ADDR
};

/* MISRA2012 Rule-11.4 violation: Convert an integral type of register address to a pointer object, 
 no side effects forseen by violating this rule.
 The following three lines of code also violate this rule with the same reason. */
static Reg_Port_WType * const Port_Drv_PortRegWPtr[PORT_DRV_PORT_TOTAL_NUM] = 
{
    (Reg_Port_WType *)PORTA_BASE_ADDR, (Reg_Port_WType *)PORTB_BASE_ADDR,
    (Reg_Port_WType *)PORTC_BASE_ADDR, (Reg_Port_WType *)PORTD_BASE_ADDR,
    (Reg_Port_WType *)PORTE_BASE_ADDR
};

/* MISRA2012 Rule-11.4 violation: Convert an integral type of register address to a pointer object, 
 no side effects forseen by violating this rule.
 The following three lines of code also violate this rule with the same reason. */
static Reg_Gpio_WType * const Port_Drv_GpioRegWPtr[PORT_DRV_GPIO_TOTAL_NUM] = 
{
    (Reg_Gpio_WType *)GPIOA_BASE_ADDR, (Reg_Gpio_WType *)GPIOB_BASE_ADDR, 
    (Reg_Gpio_WType *)GPIOC_BASE_ADDR, (Reg_Gpio_WType *)GPIOD_BASE_ADDR, 
    (Reg_Gpio_WType *)GPIOE_BASE_ADDR
};

#define PORT_STOP_SEC_CONST_PTR
#include "Port_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
/**
 * @brief       This function initializes the port pin in low level.
 *
 * @param[in]   PinConfig: Pointer to the port pin config structure.
 * @return      None.
 */
static void Port_Drv_InitPins(const Port_Drv_ConfigType *PinConfig);
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
 * @brief       This function initializes the port pin in low level.
 *
 * @param[in]   PinConfig: Pointer to the port pin config structure.
 * @return      None.
 */
/* SWS_Port_00075*/
static void Port_Drv_InitPins(const Port_Drv_ConfigType *PinConfig)
{
    Reg_Port_BfType *PORTx = Port_Drv_PortRegBfPtr[PinConfig->PortId];
    Reg_Port_WType  *PORTxw = Port_Drv_PortRegWPtr[PinConfig->PortId];
    Reg_Gpio_WType *GPIOxw = Port_Drv_GpioRegWPtr[PinConfig->PortId];

    uint32 PinDir = GPIOxw->GPIOx_PDDR;

    SchM_Enter_Port_WritePortPcr();
    if (PORTx->PORTx_PCRn[PinConfig->GpioNo].LK == 1U)
    {
        PORTxw->PORTx_PCRn[PinConfig->GpioNo] = 0x5B000000U;
    }
    PORTx->PORTx_PCRn[PinConfig->GpioNo].PS = ((uint32)(PinConfig->PullConfig)) & 0x01U;
    PORTx->PORTx_PCRn[PinConfig->GpioNo].PE = (((uint32)(PinConfig->PullConfig)) & 0x02U) >> 1U;
    PORTx->PORTx_PCRn[PinConfig->GpioNo].MUX = (uint32)(PinConfig->PinMode);
    PORTx->PORTx_PCRn[PinConfig->GpioNo].SRE = (uint32)(PinConfig->SlewRate);
    PORTx->PORTx_PCRn[PinConfig->GpioNo].ODE = (uint32)(PinConfig->OpenDrainConfig);
    PORTx->PORTx_PCRn[PinConfig->GpioNo].FLTEN = (uint32)(PinConfig->FilterEnable);
    PORTx->PORTx_PCRn[PinConfig->GpioNo].FLT = (uint32)(PinConfig->FilterConfig);
    PORTx->PORTx_PCRn[PinConfig->GpioNo].LK = 1U;
    SchM_Exit_Port_WritePortPcr();

    if(PORT_DRV_PIN_MODE_GPIO == PinConfig->PinMode)
    {
        GPIOxw->GPIOx_PSOR = ((uint32)(PinConfig->InitValue) << (uint32)(PinConfig->GpioNo));
    }

    PinDir &= (~(0x01UL << (uint32)(PinConfig->GpioNo)));
    PinDir |= ((uint32)(PinConfig->Direction) << (uint32)(PinConfig->GpioNo));
    GPIOxw->GPIOx_PDDR = PinDir;
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
 * @brief       This function writes a pin with 'Set' value.
 *
 * @param[in]   PortId: Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                      PORT_D, PORT_E.
 * @param[in]   GpioNo: Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return      None.
 */
void Port_Drv_SetPinOutput(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo)
{
    Reg_Gpio_WType *GPIOxw = Port_Drv_GpioRegWPtr[PortId];

    GPIOxw->GPIOx_PSOR = (0x01UL << (uint32)GpioNo);
}

/**
 * @brief       This function writes a pin to 'Clear' value.
 *
 * @param[in]   PortId: Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                      PORT_D, PORT_E.
 * @param[in]   GpioNo: Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return      None.
 */
void Port_Drv_ClearPinOutput(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo)
{
    Reg_Gpio_WType *GPIOxw =Port_Drv_GpioRegWPtr[PortId];

    GPIOxw->GPIOx_PCOR = (0x01UL << (uint32)GpioNo);
}

/**
 * @brief       This function sets the pin Direction.
 *
 * @param[in]   PortId: Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                      PORT_D, PORT_E.
 * @param[in]   GpioNo: Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   Direction: Select  I/O Direction of a pin.
 *
 * @return      None.
 */
/* SWS_Port_00075*/
void Port_Drv_SetPinDirection(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                    Port_Drv_DirectionType Direction)
{
    Reg_Gpio_WType *GPIOxw = Port_Drv_GpioRegWPtr[PortId];

    SchM_Enter_Port_WriteGpioPddr();
    uint32 PinDir = GPIOxw->GPIOx_PDDR;
    PinDir &= (~(0x01UL << (uint32)(GpioNo)));
    PinDir |= ((uint32)(Direction) << (uint32)(GpioNo));

    GPIOxw->GPIOx_PDDR = PinDir;
    SchM_Exit_Port_WriteGpioPddr();
}

/**
 * @brief       This function initializes port pin.
 *
 * @param[in]   PinCount: total number of the pins to be initialized.
 * @param[in]   Config: Pointer to the pin setting structure.
 *
 * @return      None
 */
void Port_Drv_Init(uint32 PinCount, const Port_Drv_ConfigType Config[])
{
    uint32 i;

    for (i = 0U; i < PinCount; i++)
    {
        Port_Drv_InitPins(&Config[i]);
    }
}

/**
 * @brief       This function configures the pin muxing.
 *
 * @param[in]   PortId:   Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                          PORT_D,PORT_E.
 * @param[in]   GpioNo:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   PinMode:  Pin mux function.
 *
 * @return      None.
 */
/* SWS_Port_00075*/
void Port_Drv_SetPinMode(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                         Port_Drv_PortMuxType PinMode)
{
    Reg_Port_BfType *PORTx = (Reg_Port_BfType *)(Port_Drv_PortRegBfPtr[PortId]);
    Reg_Port_WType  *PORTxw = Port_Drv_PortRegWPtr[PortId];

    SchM_Enter_Port_WritePortPcr();
    if (PORTx->PORTx_PCRn[GpioNo].LK == 1U)
    {
        PORTxw->PORTx_PCRn[GpioNo] = 0x5B000000U;
    }
    PORTx->PORTx_PCRn[GpioNo].MUX = (uint32)PinMode;
    PORTx->PORTx_PCRn[GpioNo].LK = 1U;
    SchM_Exit_Port_WritePortPcr();
}

/**
 * @brief       This function configures the slew rate.
 *
 * @param[in]   PortId:   Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                          PORT_D,PORT_E.
 * @param[in]   GpioNo:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   SlewRateConfig:  Slew Rate.
 *
 * @return      None.
 */
void Port_Drv_SetSlewRate(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                          Port_Drv_SlewRateType SlewRateConfig)
{
    Reg_Port_BfType *PORTx = (Reg_Port_BfType *)(Port_Drv_PortRegBfPtr[PortId]);
    Reg_Port_WType  *PORTxw = Port_Drv_PortRegWPtr[PortId];
    
    SchM_Enter_Port_WritePortPcr();
    if(PORTx->PORTx_PCRn[GpioNo].LK == 1U)
    {
        PORTxw->PORTx_PCRn[GpioNo] = 0x5B000000U;
    }
    PORTx->PORTx_PCRn[GpioNo].SRE = (uint32)SlewRateConfig;
    PORTx->PORTx_PCRn[GpioNo].LK = 1U;
    SchM_Exit_Port_WritePortPcr();
}

/**
 * @brief       This function configures the pin pull configure.
 *
 * @param[in]   PortId:   Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                          PORT_D,PORT_E.
 * @param[in]   GpioNo:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   PullConfig:  Pull Configure value.
 *
 * @return      None.
 */
void Port_Drv_SetPullConfig(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                            Port_Drv_PullConfigType PullConfig)
{
    Reg_Port_BfType *PORTx = (Reg_Port_BfType *)(Port_Drv_PortRegBfPtr[PortId]);
    Reg_Port_WType  *PORTxw = Port_Drv_PortRegWPtr[PortId];
    
    SchM_Enter_Port_WritePortPcr();
    if(PORTx->PORTx_PCRn[GpioNo].LK == 1U)
    {
        PORTxw->PORTx_PCRn[GpioNo] = 0x5B000000U;
    }
    PORTx->PORTx_PCRn[GpioNo].PS = (uint32)PullConfig & 0x01U;
    PORTx->PORTx_PCRn[GpioNo].PE = ((uint32)PullConfig & 0x02UL)>>1UL;
    PORTx->PORTx_PCRn[GpioNo].LK = 1U;
    SchM_Exit_Port_WritePortPcr();
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/** @} end of group Public_FunctionDeclaration */
#ifdef __cplusplus
}
#endif

/** @} end of group Port_Drv */

/** @} end of group Port_Module */
