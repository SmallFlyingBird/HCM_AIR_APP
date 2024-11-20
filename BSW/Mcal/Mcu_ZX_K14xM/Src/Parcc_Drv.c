/**************************************************************************************************/
/**
 * @file      : Parcc_Drv.c
 * @brief     : PARCC low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Parcc_Drv
 *  @brief PARCC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Parcc_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define PARCC_DRV_C_VENDOR_ID                   0x00B3U
#define PARCC_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define PARCC_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define PARCC_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define PARCC_DRV_C_SW_MAJOR_VERSION            1U
#define PARCC_DRV_C_SW_MINOR_VERSION            2U
#define PARCC_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Parcc_Drv.h file are of the same vendor */
#if (PARCC_DRV_C_VENDOR_ID != PARCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Parcc_Drv.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Autosar version */
#if ((PARCC_DRV_C_AR_RELEASE_MAJOR_VERSION != PARCC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (PARCC_DRV_C_AR_RELEASE_MINOR_VERSION != PARCC_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (PARCC_DRV_C_AR_RELEASE_REVISION_VERSION != PARCC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Parcc_Drv.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Software version */
#if ((PARCC_DRV_C_SW_MAJOR_VERSION != PARCC_DRV_H_SW_MAJOR_VERSION) ||                             \
     (PARCC_DRV_C_SW_MINOR_VERSION != PARCC_DRV_H_SW_MINOR_VERSION) ||                             \
     (PARCC_DRV_C_SW_PATCH_VERSION != PARCC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Parcc_Drv.c and Parcc_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((PARCC_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||       \
         (PARCC_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Parcc_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define PARCC_DRV_LOCK_MASK ((uint32)1U << 31U)

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

typedef volatile struct
{
    uint32 PCKMD      : 2; /*!< [1:0]          r/w  */
    uint32 RSVD_3_2   : 2; /*!< [3:2]          r    */
    uint32 CLKMUX     : 3; /*!< [6:4]          r/w  */
    uint32 RSVD_7     : 1; /*!< [7]            r    */
    uint32 CLKDIV     : 4; /*!< [11:8]         r/w  */
    uint32 RSVD_15_12 : 4; /*!< [15:12]        r    */
    uint32 PWLK       : 1; /*!< [16]           r/w  */
    uint32 RSVD_19_17 : 3; /*!< [19:17]        r    */
    uint32 PSUPVACEN  : 1; /*!< [20]           r/w  */
    uint32 PRSTB      : 1; /*!< [21]           r/w  */
    uint32 RSVD_23_22 : 2; /*!< [23:22]        r    */
    uint32 PPR        : 1; /*!< [24]           r/w  */
    uint32 PCLKMUXPR  : 1; /*!< [25]           r/w  */
    uint32 PCLKDIVPR  : 1; /*!< [26]           r/w  */
    uint32 PSUPVACPR  : 1; /*!< [27]           r/w  */
    uint32 RSVD_30_28 : 3; /*!< [30:28]        r    */
    uint32 LOCK       : 1; /*!< [31]           r/w  */
} Parcc_Drv_PeriphBfType;

/**
 * @brief  Type of peripheral functional clock table.
 */
typedef struct
{
    const Parcc_Drv_ClockSrcType *PeripheralFunctionalClockPtr;
    uint32                        NumOfFunctionalClock;
} Parcc_Drv_PeripheralFunctionalClockTableType;

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONST_PTR
#include "Mcu_MemMap.h"

/**
 *  @brief Pointer to Parcc base address
 */
static Parcc_Drv_PeriphBfType *const Parcc_Drv_ParccRegBfPtr =
    (Parcc_Drv_PeriphBfType *)PARCC_BASE_ADDR;
static uint32 *const Parcc_Drv_ParccRegWPtr = (uint32 *)PARCC_BASE_ADDR;

#define MCU_STOP_SEC_CONST_PTR
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

/* clang-format off */
static const Parcc_Drv_ClockSrcType Parcc_Drv_WdogFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_EwdtFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO, 
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_StimFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_TimFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_McpwmFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_TdgFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_CanFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO, 
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_UartFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_SpiFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_I2cFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_I2sFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO,      
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M,
    PARCC_DRV_CLOCK_SRC_FOSC,   
    PARCC_DRV_CLOCK_SRC_PLL
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_AdcFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO, 
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_CmpFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_BUS
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_CrcFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_BUS
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_AesFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_BUS
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_TrngFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_BUS
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_FlashFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO, 
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC,
    PARCC_DRV_CLOCK_SRC_PLL, 
    PARCC_DRV_CLOCK_SRC_SLOW
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_DmaFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_CORE
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_DmaMuxFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_CORE
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_PortFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_NO, 
    PARCC_DRV_CLOCK_SRC_LPO32K, 
    PARCC_DRV_CLOCK_SRC_SOSC,
    PARCC_DRV_CLOCK_SRC_FIRC64M, 
    PARCC_DRV_CLOCK_SRC_FOSC
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_TmuFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_CORE
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_RegfileFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_CORE
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_SmpuFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_CORE
};

static const Parcc_Drv_ClockSrcType Parcc_Drv_GpioFunctionalClock[] = 
{
    PARCC_DRV_CLOCK_SRC_CORE
};

#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const Parcc_Drv_PeripheralFunctionalClockTableType Parcc_Drv_PeripheralFunctionalClockTable[] = 
{
    /* WDOG */
    {
        Parcc_Drv_WdogFunctionalClock,
        sizeof(Parcc_Drv_WdogFunctionalClock) / sizeof(Parcc_Drv_WdogFunctionalClock[0])
    },
    /* EWDT */
    {
        Parcc_Drv_EwdtFunctionalClock,
        sizeof(Parcc_Drv_EwdtFunctionalClock) / sizeof(Parcc_Drv_EwdtFunctionalClock[0])  
    },
    /* STIM */
    {
        Parcc_Drv_StimFunctionalClock,
        sizeof(Parcc_Drv_StimFunctionalClock) / sizeof(Parcc_Drv_StimFunctionalClock[0])
    }, 
    /* TIM0 */
    {
        Parcc_Drv_TimFunctionalClock,
        sizeof(Parcc_Drv_TimFunctionalClock) / sizeof(Parcc_Drv_TimFunctionalClock[0])
    },
    /* TIM1 */
    {
        Parcc_Drv_TimFunctionalClock,
        sizeof(Parcc_Drv_TimFunctionalClock) / sizeof(Parcc_Drv_TimFunctionalClock[0])
    },
    /* TIM2 */
    {
        Parcc_Drv_TimFunctionalClock,
        sizeof(Parcc_Drv_TimFunctionalClock) / sizeof(Parcc_Drv_TimFunctionalClock[0])
    },
    /* TIM3 */
    {
        Parcc_Drv_TimFunctionalClock,
        sizeof(Parcc_Drv_TimFunctionalClock) / sizeof(Parcc_Drv_TimFunctionalClock[0])
    },
    /* MCPWM0 */
    {
        Parcc_Drv_McpwmFunctionalClock,
        sizeof(Parcc_Drv_McpwmFunctionalClock) / sizeof(Parcc_Drv_McpwmFunctionalClock[0])
    },
    /* MCPWM1 */
    {
        Parcc_Drv_McpwmFunctionalClock,
        sizeof(Parcc_Drv_McpwmFunctionalClock) / sizeof(Parcc_Drv_McpwmFunctionalClock[0])
    },
    /* TDG0 */
    {
        Parcc_Drv_TdgFunctionalClock,
        sizeof(Parcc_Drv_TdgFunctionalClock) / sizeof(Parcc_Drv_TdgFunctionalClock[0])
    },
    /* TDG1 */
    {
        Parcc_Drv_TdgFunctionalClock,
        sizeof(Parcc_Drv_TdgFunctionalClock) / sizeof(Parcc_Drv_TdgFunctionalClock[0])
    },
    /* CAN0 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* CAN1 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* CAN2 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* CAN3 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* CAN4 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* CAN5 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* CAN6 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* CAN7 */
    {
        Parcc_Drv_CanFunctionalClock,
        sizeof(Parcc_Drv_CanFunctionalClock) / sizeof(Parcc_Drv_CanFunctionalClock[0])
    },
    /* UART0 */
    {
        Parcc_Drv_UartFunctionalClock,
        sizeof(Parcc_Drv_UartFunctionalClock) / sizeof(Parcc_Drv_UartFunctionalClock[0])
    },
    /* UART1 */
    {
        Parcc_Drv_UartFunctionalClock,
        sizeof(Parcc_Drv_UartFunctionalClock) / sizeof(Parcc_Drv_UartFunctionalClock[0])
    },
    /* UART2 */
    {
        Parcc_Drv_UartFunctionalClock,
        sizeof(Parcc_Drv_UartFunctionalClock) / sizeof(Parcc_Drv_UartFunctionalClock[0])
    },
    /* UART3 */
    {
        Parcc_Drv_UartFunctionalClock,
        sizeof(Parcc_Drv_UartFunctionalClock) / sizeof(Parcc_Drv_UartFunctionalClock[0])
    },
    /* UART4 */
    {
        Parcc_Drv_UartFunctionalClock,
        sizeof(Parcc_Drv_UartFunctionalClock) / sizeof(Parcc_Drv_UartFunctionalClock[0])
    },
    /* UART5 */
    {
        Parcc_Drv_UartFunctionalClock,
        sizeof(Parcc_Drv_UartFunctionalClock) / sizeof(Parcc_Drv_UartFunctionalClock[0])
    },
    /* SPI0 */
    {
        Parcc_Drv_SpiFunctionalClock,
        sizeof(Parcc_Drv_SpiFunctionalClock) / sizeof(Parcc_Drv_SpiFunctionalClock[0])
    },
    /* SPI1 */
    {
        Parcc_Drv_SpiFunctionalClock,
        sizeof(Parcc_Drv_SpiFunctionalClock) / sizeof(Parcc_Drv_SpiFunctionalClock[0])
    },
    /* SPI2 */
    {
        Parcc_Drv_SpiFunctionalClock,
        sizeof(Parcc_Drv_SpiFunctionalClock) / sizeof(Parcc_Drv_SpiFunctionalClock[0])
    },
    /* SPI3 */
    {
        Parcc_Drv_SpiFunctionalClock,
        sizeof(Parcc_Drv_SpiFunctionalClock) / sizeof(Parcc_Drv_SpiFunctionalClock[0])
    },
    /* I2C0 */
    {
        Parcc_Drv_I2cFunctionalClock,
        sizeof(Parcc_Drv_I2cFunctionalClock) / sizeof(Parcc_Drv_I2cFunctionalClock[0])
    },
    /* I2C1 */
    {
        Parcc_Drv_I2cFunctionalClock,
        sizeof(Parcc_Drv_I2cFunctionalClock) / sizeof(Parcc_Drv_I2cFunctionalClock[0])
    },
    /* I2S0 */
    {
        Parcc_Drv_I2sFunctionalClock,
        sizeof(Parcc_Drv_I2sFunctionalClock) / sizeof(Parcc_Drv_I2sFunctionalClock[0])
    },
    /* I2S1 */
    {
        Parcc_Drv_I2sFunctionalClock,
        sizeof(Parcc_Drv_I2sFunctionalClock) / sizeof(Parcc_Drv_I2sFunctionalClock[0])
    },
    /* RESERVED */
    {
        NULL_PTR,
        0
    },
    /* ADC0 */
    {
        Parcc_Drv_AdcFunctionalClock,
        sizeof(Parcc_Drv_AdcFunctionalClock) / sizeof(Parcc_Drv_AdcFunctionalClock[0])
    },
    /* ADC1 */
    {
        Parcc_Drv_AdcFunctionalClock,
        sizeof(Parcc_Drv_AdcFunctionalClock) / sizeof(Parcc_Drv_AdcFunctionalClock[0])
    },
    /* CMP0 */
    {
        Parcc_Drv_CmpFunctionalClock,
        sizeof(Parcc_Drv_CmpFunctionalClock) / sizeof(Parcc_Drv_CmpFunctionalClock[0])
    },
    /* CRC */
    {
        Parcc_Drv_CrcFunctionalClock,
        sizeof(Parcc_Drv_CrcFunctionalClock) / sizeof(Parcc_Drv_CrcFunctionalClock[0])
    },
    /* AES */
    {
        Parcc_Drv_AesFunctionalClock,
        sizeof(Parcc_Drv_AesFunctionalClock) / sizeof(Parcc_Drv_AesFunctionalClock[0])
    },
    /* TRNG */
    {
        Parcc_Drv_TrngFunctionalClock,
        sizeof(Parcc_Drv_TrngFunctionalClock) / sizeof(Parcc_Drv_TrngFunctionalClock[0])
    },
    /* FLASH */
    {
        Parcc_Drv_FlashFunctionalClock,
        sizeof(Parcc_Drv_FlashFunctionalClock) / sizeof(Parcc_Drv_FlashFunctionalClock[0])
    },
    /* RESERVED */
    {
        NULL_PTR,
        0
    },
    /* DMA */
    {
        Parcc_Drv_DmaFunctionalClock,
        sizeof(Parcc_Drv_DmaFunctionalClock) / sizeof(Parcc_Drv_DmaFunctionalClock[0])
    },
    /* DMAMUX */
    {
        Parcc_Drv_DmaMuxFunctionalClock,
        sizeof(Parcc_Drv_DmaMuxFunctionalClock) / sizeof(Parcc_Drv_DmaMuxFunctionalClock[0])
    },
    /* PORTA */
    {
        Parcc_Drv_PortFunctionalClock,
        sizeof(Parcc_Drv_PortFunctionalClock) / sizeof(Parcc_Drv_PortFunctionalClock[0])
    },
    /* PORTB */
    {
        Parcc_Drv_PortFunctionalClock,
        sizeof(Parcc_Drv_PortFunctionalClock) / sizeof(Parcc_Drv_PortFunctionalClock[0])
    },
    /* PORTC */
    {
        Parcc_Drv_PortFunctionalClock,
        sizeof(Parcc_Drv_PortFunctionalClock) / sizeof(Parcc_Drv_PortFunctionalClock[0])
    },
    /* PORTD */
    {
        Parcc_Drv_PortFunctionalClock,
        sizeof(Parcc_Drv_PortFunctionalClock) / sizeof(Parcc_Drv_PortFunctionalClock[0])
    },
    /* PORTE */
    {
        Parcc_Drv_PortFunctionalClock,
        sizeof(Parcc_Drv_PortFunctionalClock) / sizeof(Parcc_Drv_PortFunctionalClock[0])
    },
    /* TMU */
    {
        Parcc_Drv_TmuFunctionalClock,
        sizeof(Parcc_Drv_TmuFunctionalClock) / sizeof(Parcc_Drv_TmuFunctionalClock[0])
    },
    /* REGFILE */
    {
        Parcc_Drv_RegfileFunctionalClock, 
        sizeof(Parcc_Drv_RegfileFunctionalClock) / sizeof(Parcc_Drv_RegfileFunctionalClock[0])
    },
    /* SMPU */
    {
        Parcc_Drv_SmpuFunctionalClock,
        sizeof(Parcc_Drv_SmpuFunctionalClock) / sizeof(Parcc_Drv_SmpuFunctionalClock[0])
    },
    /* GPIO */
    {
        Parcc_Drv_GpioFunctionalClock,
        sizeof(Parcc_Drv_GpioFunctionalClock) / sizeof(Parcc_Drv_GpioFunctionalClock[0])
    }
};

/* clang-format on */

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static void Parcc_Drv_ResetParccModule(Parcc_Drv_ModuleType ModuleId);

static void Parcc_Drv_EnableParccModule(Parcc_Drv_ModuleType ModuleId);

static void Parcc_Drv_DisableParccModule(Parcc_Drv_ModuleType ModuleId);

static void Parcc_Drv_SetParccClockDivider(Parcc_Drv_ModuleType       ModuleId,
                                           Parcc_Drv_ClockDividerType ClockDivider);

static Parcc_Drv_StatusType Parcc_Drv_SetParccClockSrc(Parcc_Drv_ModuleType   ModuleId,
                                                       Parcc_Drv_ClockSrcType ClockSource);

static void Parcc_Drv_ConfigParccAccess(Parcc_Drv_ModuleType ModuleId, boolean WriteLockEnabled,
                                        boolean SupervisorEnabled);

static boolean Parcc_Drv_CheckParccId(Parcc_Drv_ModuleType ModuleId);

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Private_FunctionDeclaration */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/**
 * @brief      Resets given parcc module.
 *
 * @param[in]  ModuleId: Given parcc module.
 *
 * @return     None
 *
 */
static void Parcc_Drv_ResetParccModule(Parcc_Drv_ModuleType ModuleId)
{
    if (0U != Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK)
    {
        /* unlock this register */
        Parcc_Drv_ParccRegWPtr[ModuleId] = 0x5B000000U;
    }

    Parcc_Drv_ParccRegBfPtr[ModuleId].PRSTB = 0U;
    Parcc_Drv_ParccRegBfPtr[ModuleId].PRSTB = 1U;
    Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK = 1U;
}

/**
 * @brief      Enables given parcc module.
 *
 * @param[in]  ModuleId: Given parcc module.
 *
 * @return     None
 *
 */
static void Parcc_Drv_EnableParccModule(Parcc_Drv_ModuleType ModuleId)
{
    if (0U != Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK)
    {
        /* unlock this register */
        Parcc_Drv_ParccRegWPtr[ModuleId] = 0x5B000000U;
    }

    Parcc_Drv_ParccRegBfPtr[ModuleId].PCKMD = 1U;
    Parcc_Drv_ParccRegBfPtr[ModuleId].PRSTB = 1U;
    Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK = 1U;
}

/**
 * @brief      Disables given parcc module.
 *
 * @param[in]  ModuleId: Given parcc module.
 *
 * @return     None
 *
 */
static void Parcc_Drv_DisableParccModule(Parcc_Drv_ModuleType ModuleId)
{
    if (0U != Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK)
    {
        /* unlock this register */
        Parcc_Drv_ParccRegWPtr[ModuleId] = 0x5B000000U;
    }

    Parcc_Drv_ParccRegBfPtr[ModuleId].PCKMD = 0U;
    Parcc_Drv_ParccRegBfPtr[ModuleId].PRSTB = 0U;
    Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK = 1U;
}

/**
 * @brief      Sets clock divider to given parcc module.
 *
 * @param[in]  ModuleId: Given parcc module.
 * @param[in]  ClockDivider: Clock divider.
 *
 * @return     None
 *
 */
static void Parcc_Drv_SetParccClockDivider(Parcc_Drv_ModuleType       ModuleId,
                                           Parcc_Drv_ClockDividerType ClockDivider)
{
    switch (ModuleId)
    {
        case PARCC_DRV_EWDT:
        case PARCC_DRV_STIM:
        case PARCC_DRV_TIM0:
        case PARCC_DRV_TIM1:
        case PARCC_DRV_TIM2:
        case PARCC_DRV_TIM3:
        case PARCC_DRV_MCPWM0:
        case PARCC_DRV_MCPWM1:
        case PARCC_DRV_TDG0:
        case PARCC_DRV_TDG1:
        case PARCC_DRV_CAN0:
        case PARCC_DRV_CAN1:
        case PARCC_DRV_CAN2:
        case PARCC_DRV_CAN3:
#if (defined(DEV_Z20K148M) || defined(DEV_Z20K146M))
        case PARCC_DRV_CAN4:
        case PARCC_DRV_CAN5:
#endif
#if (defined(DEV_Z20K148M))
        case PARCC_DRV_CAN6:
        case PARCC_DRV_CAN7:
#endif
        case PARCC_DRV_UART0:
        case PARCC_DRV_UART1:
        case PARCC_DRV_UART2:
        case PARCC_DRV_UART3:
        case PARCC_DRV_UART4:
        case PARCC_DRV_UART5:
        case PARCC_DRV_SPI0:
        case PARCC_DRV_SPI1:
        case PARCC_DRV_SPI2:
        case PARCC_DRV_SPI3:
        case PARCC_DRV_I2C0:
        case PARCC_DRV_I2C1:
        case PARCC_DRV_I2S0:
#if (defined(DEV_Z20K148M))
        case PARCC_DRV_I2S1:
#endif
        case PARCC_DRV_ADC0:
        case PARCC_DRV_ADC1:
        case PARCC_DRV_FLASH:
        case PARCC_DRV_PORTA:
        case PARCC_DRV_PORTB:
        case PARCC_DRV_PORTC:
        case PARCC_DRV_PORTD:
        case PARCC_DRV_PORTE:
            if (0U != Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK)
            {
                /* unlock this register */
                Parcc_Drv_ParccRegWPtr[ModuleId] = 0x5B000000U;
            }

            Parcc_Drv_ParccRegBfPtr[ModuleId].CLKDIV = (uint32)ClockDivider;
            Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK = 1U;
            break;

        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      Sets functional clock source to given parcc module.
 *
 * @param[in]  ModuleId:  Given parcc module.
 * @param[in]  ClockSource: Functional clock source.
 *
 * @return     Parcc_Drv_StatusType: Current parcc module state.
 *
 */
static Parcc_Drv_StatusType Parcc_Drv_SetParccClockSrc(Parcc_Drv_ModuleType   ModuleId,
                                                       Parcc_Drv_ClockSrcType ClockSource)
{
    volatile Parcc_Drv_StatusType ResRet = PARCC_DRV_STATUS_OK;
    uint8                         ClockSourceIndex = 0U;
    uint32                        TmpFunctionalClockSize = 0U;

    if (0U != Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK)
    {
        /* unlock this register */
        Parcc_Drv_ParccRegWPtr[ModuleId] = 0x5B000000U;
    }

    TmpFunctionalClockSize =
        Parcc_Drv_PeripheralFunctionalClockTable[ModuleId].NumOfFunctionalClock;
    for (; ClockSourceIndex < TmpFunctionalClockSize; ++ClockSourceIndex)
    {
        if (NULL_PTR !=
            Parcc_Drv_PeripheralFunctionalClockTable[ModuleId].PeripheralFunctionalClockPtr)
        {
            if (ClockSource == Parcc_Drv_PeripheralFunctionalClockTable[ModuleId]
                                   .PeripheralFunctionalClockPtr[ClockSourceIndex])
            {
                Parcc_Drv_ParccRegBfPtr[ModuleId].CLKMUX = (uint32)ClockSource;
                break;
            }
        }
    }

    /* Given functional clock is not supported for this peripheral */
    if (ClockSourceIndex == TmpFunctionalClockSize)
    {
        ResRet = PARCC_DRV_STATUS_NOT_OK;
    }

    Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK = 1U;

    return ResRet;
}

/**
 * @brief      Configs write lock and supervisor access to given parcc module.
 *
 * @param[in]  ModuleId: Given parcc module.
 * @param[in]  WriteLockEnable: Enable/Disable write lock.
 * @param[in]  SupervisorEnable: Enable/Disable supervisor mode.
 *
 * @return     None
 *
 */
static void Parcc_Drv_ConfigParccAccess(Parcc_Drv_ModuleType ModuleId, boolean WriteLockEnabled,
                                        boolean SupervisorEnabled)
{
    if (0U != Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK)
    {
        /* unlock this register */
        Parcc_Drv_ParccRegWPtr[ModuleId] = 0x5B000000U;
    }

    if (PARCC_DRV_FLASH != ModuleId)
    {
        Parcc_Drv_ParccRegBfPtr[ModuleId].PWLK = (uint32)WriteLockEnabled;
        Parcc_Drv_ParccRegBfPtr[ModuleId].PSUPVACEN = (uint32)SupervisorEnabled;
    }

    Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK = 1U;
}

/**
 * @brief      Check whether the requested parcc module support to configure write lock.
 *
 * @param[in]  ModuleId: Given parcc module.
 *
 * @return     boolean
 * @retval     TRUE:  The requested parcc module is supported to configure write lock.
 * @retval     FALSE: The requested parcc module is not supported to configure write lock.
 *
 */
static boolean Parcc_Drv_CheckParccId(Parcc_Drv_ModuleType ModuleId)
{
    boolean RetVal = TRUE;

    if ((ModuleId > PARCC_DRV_GPIO) || (PARCC_DRV_FLASH == ModuleId))
    {
        RetVal = FALSE;
    }

    return RetVal;
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief       Initializes the PARCC configuration.
 *
 * @param[in]   ConfigPtr: Pointer to the PARCC configuration.
 *
 * @return      None
 *
 */
void Parcc_Drv_Init(const Parcc_Drv_SystemParccConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        uint32 ModuleNum = ConfigPtr->NumberOfModule;
        uint32 Index;

        for (Index = 0U; Index < ModuleNum; Index++)
        {
            Parcc_Drv_DisableParccModule(ConfigPtr->SystemParccConfigPtr[Index].ParccModule);
            (void)Parcc_Drv_SetParccClockSrc(ConfigPtr->SystemParccConfigPtr[Index].ParccModule,
                                             ConfigPtr->SystemParccConfigPtr[Index].ParccModuleSrc);

            Parcc_Drv_SetParccClockDivider(
                ConfigPtr->SystemParccConfigPtr[Index].ParccModule,
                ConfigPtr->SystemParccConfigPtr[Index].ParccModuleDivider);

            Parcc_Drv_ConfigParccAccess(
                ConfigPtr->SystemParccConfigPtr[Index].ParccModule,
                ConfigPtr->SystemParccConfigPtr[Index].WriteLockEnable,
                ConfigPtr->SystemParccConfigPtr[Index].SupervisorAccessEnable);

            if (TRUE == ConfigPtr->SystemParccConfigPtr[Index].Enable)
            {
                Parcc_Drv_ResetParccModule(ConfigPtr->SystemParccConfigPtr[Index].ParccModule);
                Parcc_Drv_EnableParccModule(ConfigPtr->SystemParccConfigPtr[Index].ParccModule);
            }
            else
            {
                Parcc_Drv_DisableParccModule(ConfigPtr->SystemParccConfigPtr[Index].ParccModule);
            }
        }
    }
}

/**
 * @brief      Enable/Disable peripheral write lock.
 *
 * @param[in]  ModuleId: Given parcc module.
 * @param[in]  Enable: Enable/Disable.
 *
 * @return     boolean
 * @retval     TRUE: Enable/Disable peripheral write lock success.
 * @retval     FALSE: Enable/Disable peripheral write lock failed.
 *
 */
boolean Parcc_Drv_SetPeripheralWriteLock(Parcc_Drv_ModuleType ModuleId, boolean Enable)
{
    boolean RetVal = FALSE;

    if (TRUE == Parcc_Drv_CheckParccId(ModuleId))
    {
        if (0U != Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK)
        {
            /* unlock this register */
            Parcc_Drv_ParccRegWPtr[ModuleId] = 0x5B000000U;
        }

        Parcc_Drv_ParccRegBfPtr[ModuleId].PWLK = (uint32)Enable;
        Parcc_Drv_ParccRegBfPtr[ModuleId].LOCK = 1U;

        RetVal = TRUE;
    }

    return RetVal;
}

/**
 * @brief       Resets all parcc registers to reset value.
 *
 * @param[in]   None
 *
 * @return      None
 *
 */
void Parcc_Drv_ResetParccRegisters(void)
{
    Parcc_Drv_PeriphBfType *TmpVal;
    uint32 PerIndex = 0U;

    for (; PerIndex < PARCC_DRV_SUPPORTED_PERIPHERAL_NUM; ++PerIndex)
    {
        TmpVal = (Parcc_Drv_PeriphBfType *)Parcc_Drv_ParccRegsTab[PerIndex].Addr;

        if (0U != TmpVal->LOCK)
        {
            *((uint32 *)Parcc_Drv_ParccRegsTab[PerIndex].Addr) = 0x5B000000U;
        }

        if (0U != TmpVal->PCKMD)
        {
            TmpVal->PCKMD = 0U;
        }

        *((uint32 *)Parcc_Drv_ParccRegsTab[PerIndex].Addr) =
            (Parcc_Drv_ParccRegsTab[PerIndex].ResetVal & (~PARCC_DRV_LOCK_MASK));

        TmpVal->LOCK = 1U;
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Parcc_Drv */

/** @} end of group Mcu_Module */
