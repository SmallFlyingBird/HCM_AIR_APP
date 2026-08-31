/**
* @file    Port_Lld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Port_Lld
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
#include "Compiler.h"
#include "Port_Lld_Reg.h"
#include "Port_Lld.h"
#include "SchM_Port.h"
/*==================================================================================================
 *                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_LLD_VENDOR_ID_C                      (180)
#define PORT_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PORT_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define PORT_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define PORT_LLD_SW_MAJOR_VERSION_C               (2)
#define PORT_LLD_SW_MINOR_VERSION_C               (3)
#define PORT_LLD_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
 *                                        FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PORT_LLD header file are of the same vendor */
#if (PORT_LLD_VENDOR_ID_C != PORT_LLD_VENDOR_ID)
#error "Port_Lld.c and Port_Lld.h have different vendor ids"
#endif

/* Check if source file and PORT_LLD header file are of the same Autosar version */
#if (( PORT_LLD_AR_RELEASE_MAJOR_VERSION_C != PORT_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( PORT_LLD_AR_RELEASE_MINOR_VERSION_C != PORT_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( PORT_LLD_AR_RELEASE_REVISION_VERSION_C != PORT_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Port_Lld.c and Port_Lld.h are different"
#endif

/* Check if source file and PORT_LLD header file are of the same Software version */
#if (( PORT_LLD_SW_MAJOR_VERSION_C != PORT_LLD_SW_MAJOR_VERSION) || \
      ( PORT_LLD_SW_MINOR_VERSION_C != PORT_LLD_SW_MINOR_VERSION) || \
      ( PORT_LLD_SW_PATCH_VERSION_C != PORT_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Port_Lld.c and Port_Lld.h are different"
#endif

/*==================================================================================================
 *                                         GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
 *                                          LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
 *                                          LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
 *                                           LOCAL MACROS
==================================================================================================*/
#define PORT_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))
#define PORT_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define PORT_REG_ADDR32_AEARWRITE(address, mask, value) \
    (PORT_REG_ADDR32_WRITE((address),                   \
                           ((PORT_REG_ADDR32_READ(address) & ((uint32) ~(mask))) | (value))))

#define PORT_REG_ADDR32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define PORT_REG_ADDR32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))
#define PORT_REG_ADDR32_INDEX_SET_BIT(address, bitindex) ((*(volatile uint32 *)(address)) |= ((uint32)1 << (bitindex)))
#define PORT_REG_ADDR32_INDEX_CLEAR_BIT(address, bitindex) ((*(volatile uint32 *)(address)) &= (~((uint32)1 << (bitindex))))

#define Port_IsCorrectPortPinId(Port, Pin) (((Port) < PORT_TOTAL_NUMBER) && ((Pin) < PORT_PIN_TOTAL_NUMBER))

#if (PORT_FIXED_PB_CONFIG == STD_ON)
#define PORT_UNUSED_PARAM(parma) ((void)parma)
#endif
/**
 * MR12 RULE 2.2 VIOLATION: The operation here is redundant as the result's value is always that of
 * the left-hand operand. This line of code has been maintained for the sake of code clarity and readability.
 */
/* PRQA S 2985, 2986 EOF */
/*==================================================================================================
 *                                          LOCAL FUNCTIONS
==================================================================================================*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
 * @brief This function is used to set the pin's pull configuration.
 *
 * @param PinPullConfig Target pull type
 * @param RegPCTRLPCRAddr PCTRL PCR register address
 */
PORT_FUNC LOCAL_INLINE void Port_Lld_InitPull(Port_PinPullConfigType PinPullConfig, uint32 RegPCTRLPCRAddr)
{
    switch (PinPullConfig)
    {
    case PORT_PIN_NO_PULL:
        PORT_REG_ADDR32_CLEAR_BITS(RegPCTRLPCRAddr, PCTRL_PCR_PE_MASK);
        PORT_REG_ADDR32_CLEAR_BITS(RegPCTRLPCRAddr, PCTRL_PCR_PS_MASK);
        break;
    case PORT_PIN_PULLDOWN:
        PORT_REG_ADDR32_SET_BITS(RegPCTRLPCRAddr, PCTRL_PCR_PE_MASK);
        PORT_REG_ADDR32_CLEAR_BITS(RegPCTRLPCRAddr, PCTRL_PCR_PS_MASK);
        break;
    case PORT_PIN_PULLUP:
        PORT_REG_ADDR32_SET_BITS(RegPCTRLPCRAddr, PCTRL_PCR_PE_MASK);
        PORT_REG_ADDR32_SET_BITS(RegPCTRLPCRAddr, PCTRL_PCR_PS_MASK);
        break;
    default:
        /* null */
        break;
    }
}


#if PORT_HAS_SLEW_RATE == STD_ON
/**
 * @brief This function is used to set the pin's slew rate.
 *
 * @param PinSlewRate The port pin slew rate.
 * @param RegPCTRLPCRAddr PCTRL PCR register address.
 */
PORT_FUNC LOCAL_INLINE void Port_Lld_InitSRE(Port_PinSlewRateType PinSlewRate, uint32 RegPCTRLPCRAddr)
{
    if (PORT_PIN_SLOW_SLEW_RATE == PinSlewRate)
    {
        PORT_REG_ADDR32_SET_BITS(RegPCTRLPCRAddr, PCTRL_PCR_SRE_MASK);
    }
    else
    {
        PORT_REG_ADDR32_CLEAR_BITS(RegPCTRLPCRAddr, PCTRL_PCR_SRE_MASK);
    }
}
#endif

/**
 * @brief This function sets the relative register for a pin in GPIO mode.
 *
 * @details This function sets the relative register according to the pin's direction specified in PinConfigPtr.
 *
 * @param PinConfigPtr The pin config type ready for initialization.
 * @param PinHwId Hardware pin ID
 * @param PortHwId Hardware port ID
 */

PORT_FUNC LOCAL_INLINE void Port_Lld_InitGPIOMode(const Port_PinConfigType *PinConfigPtr, Port_HwPinType PinHwId, Port_HwPortType PortHwId)
{
    if (PORT_PIN_IN == PinConfigPtr->Direction) /* Direction = PORT_PIN_IN */
    {
        /* Disable port pin output */
        PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_POER_ADDR32(PortHwId), PinHwId);
        /* Enalbe port pin input */
        PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PIER_ADDR32(PortHwId), PinHwId);

        /* Config the passive filter */
        if (STD_ON == PinConfigPtr->PassiveFilter)
        {
            PORT_REG_ADDR32_SET_BITS(PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId), PCTRL_PCR_PFE_MASK); /* Enable passive filter */
        }
        else
        {
            PORT_REG_ADDR32_CLEAR_BITS(PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId), PCTRL_PCR_PFE_MASK); /* Disable passive filter */
        }

        uint32 RegGPIOPCRAddr = GPIO_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId);

#if PORT_HAS_DIGITAL_FILTER == STD_ON
        /* Set up Digital filter*/
        if (STD_ON == PinConfigPtr->DigitalFilter)
        {
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1MC0)
            //TODO: seems HA0 any port can setup digital filter feature, need check and change 
            PORT_REG_ADDR32_SET_BITS(PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId), PCTRL_PCR_DFE_MASK); /* Enable digital filter */
#else
            PORT_REG_ADDR32_SET_BITS(RegGPIOPCRAddr, GPIO_PCR_DFE_MASK); /* Enable digital filter */
#endif
        }
        else
        {
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1MC0)
            PORT_REG_ADDR32_CLEAR_BITS(PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId), PCTRL_PCR_DFE_MASK); /* Enable digital filter */
#else
            PORT_REG_ADDR32_CLEAR_BITS(RegGPIOPCRAddr, GPIO_PCR_DFE_MASK); /* Disable digital filter */
#endif
        }
#endif

        /* setup invert */
        if (STD_ON == PinConfigPtr->InvertEnable)
        {
            PORT_REG_ADDR32_SET_BITS(RegGPIOPCRAddr, GPIO_PCR_INVE_MASK); /* Enable invert */
        }
        else
        {
            PORT_REG_ADDR32_CLEAR_BITS(RegGPIOPCRAddr, GPIO_PCR_INVE_MASK); /* Disable invert */
        }
#if PORT_HAS_DIGITAL_FILTER == STD_ON
        /* setup width */
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1MC0)
        PORT_REG_ADDR32_CLEAR_BITS(PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId), PCTRL_PCR_DFW(PinConfigPtr->DigitalFilterWidth)); /* Enable digital filter */
#else
        PORT_REG_ADDR32_AEARWRITE(RegGPIOPCRAddr, GPIO_PCR_DFW_MASK, GPIO_PCR_DFW(PinConfigPtr->DigitalFilterWidth));
#endif
#endif
    }
    else /* Direction = PORT_PIN_OUT */
    {
        /** [SWS_Port_00055]
         *  Set the port pin output latch to a default level (defined during configuration)
         *  before setting the port pin direction to output.
         */
        /* Config the init level */
        if (PORT_PIN_LEVEL_LOW == PinConfigPtr->InitLevel)
        {
            PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PCOR_ADDR32(PortHwId), PinHwId);
        }
        else
        {
            PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PSOR_ADDR32(PortHwId), PinHwId);
        }
#if (PORT_READBACK_ENABLE == STD_ON)
        PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PIER_ADDR32(PortHwId), PinHwId);
#else
        /* Disable port pin input */
        PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_PIER_ADDR32(PortHwId), PinHwId);
#endif
        /* Enalbe port pin output */
        PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_POER_ADDR32(PortHwId), PinHwId);
    }
}

/**
 * @brief This function sets the mode of a pin.
 *
 * @param PinConfigPtr Pointer to pin configuration.
 * @param PinHwId Hardware pin ID.
 * @param PortHwId Hardware port ID.
 *
 * @note If the pin's mode type is GPIO, the function `Port_Lld_InitGPIOMode()` will be called to set the GPIO relative register.
 */
PORT_FUNC LOCAL_INLINE void Port_Lld_InitMode(const Port_PinConfigType *PinConfigPtr, Port_HwPinType PinHwId, Port_HwPortType PortHwId)
{
    if (PORT_PIN_MODE_GPIO == PinConfigPtr->InitMode)
    {
        /* Config the relative register of GPIO mode */
        Port_Lld_InitGPIOMode(PinConfigPtr, PinHwId, PortHwId);
        /* Assign the PCR_MUX register */
        PORT_REG_ADDR32_AEARWRITE(PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId),
                                  PCTRL_PCR_MUX_MASK,
                                  (uint32)PORT_PIN_MODE_GPIO << PCTRL_PCR_MUX_SHIFT);
    }
    else
    {
        /** [SWS_Port_00055]
         *  Set the port pin output latch to a default level (defined during configuration)
         *  before setting the port pin direction to output.
         */
        /* Config the init output level to low */
        PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_PDOR_ADDR32(PortHwId), PinHwId);
        /* Disable port pin input */
        PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_PIER_ADDR32(PortHwId), PinHwId);
        /* Disable port pin output */
        PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_POER_ADDR32(PortHwId), PinHwId);
        /* Assign the PCR_MUX register */
        PORT_REG_ADDR32_AEARWRITE(PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId),
                                  PCTRL_PCR_MUX_MASK,
                                  (uint32)(PinConfigPtr->InitMode) << PCTRL_PCR_MUX_SHIFT);
    }
}

/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
PORT_FUNC void Port_Lld_Init(const Port_ConfigType *ConfigPtr)
{
    Port_HwPortType PortHwId;
    Port_HwPinType PinHwId;
    uint8 PortAvailablePinsNumber;
    const Port_PinConfigType *PinConfigPtr;

    for (uint8 Idx = 0U; Idx < ConfigPtr->NumberOfGroup; ++Idx)
    {
        PortHwId = ConfigPtr->PortGroupConfigPtr[Idx].HwPortId;
        PinConfigPtr = ConfigPtr->PortGroupConfigPtr[Idx].PortPinConfigPtr;
        PortAvailablePinsNumber = ConfigPtr->PortGroupConfigPtr[Idx].NumberOfPortPins;
        for (uint8 PinConfigIndex = 0U; PinConfigIndex < PortAvailablePinsNumber; ++PinConfigIndex)
        {
            PinHwId = PinConfigPtr->HwPinId;
            /* Config the pull selection */
            Port_Lld_InitPull(PinConfigPtr->PullConfig, PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId));
#if PORT_HAS_SLEW_RATE == STD_ON
            /* Config the slew rate */
            Port_Lld_InitSRE(PinConfigPtr->SlewRate, PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId));
#endif
            /* Config the pin mode */
            Port_Lld_InitMode(PinConfigPtr, PinHwId, PortHwId);
            ++PinConfigPtr;
        }
    }
}

PORT_FUNC void Port_Lld_RefreshPortDirection(const Port_ConfigType *ConfigPtr)
{
    Port_HwPinType PinHwId;
    uint8 PortAvailablePinsNumber;
    const Port_PinConfigType *PinConfigPtr;

    for (Port_HwPortType PortHwId = 0;  PortHwId < ConfigPtr->NumberOfGroup; ++PortHwId)
    {
        PinConfigPtr = ConfigPtr->PortGroupConfigPtr[PortHwId].PortPinConfigPtr;
        PortAvailablePinsNumber = ConfigPtr->PortGroupConfigPtr[PortHwId].NumberOfPortPins;
        for (uint8 PinConfigIndex = 0; PinConfigIndex < PortAvailablePinsNumber; ++PinConfigIndex)
        {
            /* [SWS_Port_00061]*/
            if (PinConfigPtr->IsDirectionChangeable == PORT_PIN_DIRECTION_UNCHANGEABLE)
            {
                PinHwId = PinConfigPtr->HwPinId;
                /* Ensure the port pin not masked */
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02();
                /* Config the direction */
                if (PORT_PIN_IN == PinConfigPtr->Direction) /* Direction = PORT_PIN_IN */
                {
                    /* Disable port pin output */
                    PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_POER_ADDR32(PortHwId), PinHwId);
                    /* Enalbe port pin input */
                    PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PIER_ADDR32(PortHwId), PinHwId);
                }
                else
                {
#if (PORT_READBACK_ENABLE == STD_ON)
                    PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PIER_ADDR32(PortHwId), PinHwId);
#else
                    /* Disable port pin input */
                    PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_PIER_ADDR32(PortHwId), PinHwId);
#endif
                    /* Enalbe port pin output */
                    PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_POER_ADDR32(PortHwId), PinHwId);
                }
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02();
            }
            ++PinConfigPtr;
        }
    }
}

PORT_FUNC boolean Port_Lld_IsPinDireChangeable(const Port_ConfigType *ConfigPtr, Port_HwPortType Port, Port_HwPinType Pin)
{
    const Port_PinConfigType *PinConfigPtr;
    uint8 PortAvailablePinsNumber;
    boolean ReturnValue = FALSE;

    PinConfigPtr = ConfigPtr->PortGroupConfigPtr[Port].PortPinConfigPtr;
    PortAvailablePinsNumber =  ConfigPtr->PortGroupConfigPtr[Port].NumberOfPortPins;

    /* Find the port pin config ,ensure whether the port pin direction changeable */
    for (uint8 PinConfigIndex = 0; (PinConfigIndex < PortAvailablePinsNumber) && (Pin != PinConfigPtr->HwPinId); ++PinConfigIndex)
    {
        ++PinConfigPtr;
    }
    if (PORT_PIN_DIRECTION_CHANGEABLE == PinConfigPtr->IsDirectionChangeable)
    {
        ReturnValue = TRUE;
    }
    return ReturnValue;
}

PORT_FUNC boolean Port_Lld_IsPinModeChangeable(const Port_ConfigType *ConfigPtr, Port_HwPortType Port, Port_HwPinType Pin)
{
    const Port_PinConfigType *PinConfigPtr;
    uint8 PortAvailablePinsNumber;
    boolean ReturnValue = FALSE;

    PinConfigPtr = ConfigPtr->PortGroupConfigPtr[Port].PortPinConfigPtr;
    PortAvailablePinsNumber =  ConfigPtr->PortGroupConfigPtr[Port].NumberOfPortPins;

    /* Find the port pin config ,ensure whether the port pin direction changeable */
    for (uint8 PinConfigIndex = 0U; (PinConfigIndex < PortAvailablePinsNumber) && (Pin != PinConfigPtr->HwPinId); ++PinConfigIndex)
    {
        ++PinConfigPtr;
    }
    if (PORT_PIN_MODE_CHANGEABLE == PinConfigPtr->IsModeChangeable)
    {
        ReturnValue = TRUE;
    }
    return ReturnValue;
}

PORT_FUNC void Port_Lld_SetPinDirection(Port_HwPortType Port, Port_HwPinType Pin, Port_PinDirectionType Direction)
{
    if (Port_IsCorrectPortPinId(Port, Pin))
    {
        SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
        if (PORT_PIN_IN == Direction)
        {
            /* Disable port pin output */
            PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_POER_ADDR32(Port), Pin);
            /* Enable port pin input */
            PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PIER_ADDR32(Port), Pin);
        }
        else
        {
#if (PORT_READBACK_ENABLE == STD_ON)
            PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_PIER_ADDR32(Port), Pin);
#else
            /* Disable port pin input */
            PORT_REG_ADDR32_INDEX_CLEAR_BIT(GPIO_PIER_ADDR32(Port), Pin);
#endif
            /* Enable port pin output */
            PORT_REG_ADDR32_INDEX_SET_BIT(GPIO_POER_ADDR32(Port), Pin);
        }
        SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
    }
}

PORT_FUNC void Port_Lld_SetPinMode(Port_HwPortType Port, Port_HwPinType Pin, Port_PinModeType Mode)
{
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
    PORT_REG_ADDR32_AEARWRITE(PCTRL_PCR_ADDR32((uint32)Port, (uint32)Pin), PCTRL_PCR_MUX_MASK, PCTRL_PCR_MUX((uint32)Mode));
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Port_Lld.c */

