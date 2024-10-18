/**************************************************************************************************/
/**
 * @file      : Dma_Drv_Types.h
 * @brief     : Dma driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DMA_DRV_TYPES_H
#define DMA_DRV_TYPES_H

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup Dma_Drv_Types
 *  @brief Dma driver types definition
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif


#include "Std_Types.h"
#include "McalLib.h"
#include "Dma_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define DMA_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define DMA_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define DMA_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define DMA_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define DMA_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define DMA_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define DMA_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Dma_Drv_Cfg.h are the same vendor */
#if (DMA_DRV_TYPES_H_VENDOR_ID != DMA_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Dma_Drv_Types.h and Dma_Drv_Cfg.h are different"
#endif
/* Check if current file and Dma_Drv_Cfg.h are the same Autosar version */
#if ((DMA_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != DMA_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (DMA_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != DMA_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (DMA_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != DMA_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Dma_Drv_Types.h and Dma_Drv_Cfg.h are different"
#endif
/* Check if current file and Dma_Drv_Cfg.h are the same software version */
#if ((DMA_DRV_TYPES_H_SW_MAJOR_VERSION != DMA_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (DMA_DRV_TYPES_H_SW_MINOR_VERSION != DMA_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (DMA_DRV_TYPES_H_SW_PATCH_VERSION != DMA_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Dma_Drv_Types.h and Dma_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((DMA_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (DMA_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Dma_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((DMA_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
        (DMA_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Dma_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */




/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief DMA channel id type definition
 */
typedef enum
{
    DMA_DRV_PHYS_CH_0      = 0U,          /*!< dma channel 0 */
    DMA_DRV_PHYS_CH_1,                    /*!< dma channel 1 */
    DMA_DRV_PHYS_CH_2,                    /*!< dma channel 2 */
    DMA_DRV_PHYS_CH_3,                    /*!< dma channel 3 */
    DMA_DRV_PHYS_CH_4,                    /*!< dma channel 4 */
    DMA_DRV_PHYS_CH_5,                    /*!< dma channel 5 */
    DMA_DRV_PHYS_CH_6,                    /*!< dma channel 6 */
    DMA_DRV_PHYS_CH_7,                    /*!< dma channel 7 */
    DMA_DRV_PHYS_CH_8,                    /*!< dma channel 8 */
    DMA_DRV_PHYS_CH_9,                    /*!< dma channel 9 */
    DMA_DRV_PHYS_CH_10,                   /*!< dma channel 10 */
    DMA_DRV_PHYS_CH_11,                   /*!< dma channel 11 */
    DMA_DRV_PHYS_CH_12,                   /*!< dma channel 12 */
    DMA_DRV_PHYS_CH_13,                   /*!< dma channel 13 */
    DMA_DRV_PHYS_CH_14,                   /*!< dma channel 14 */
    DMA_DRV_PHYS_CH_15                    /*!< dma channel 15 */
} Dma_Drv_ChannelType;

/**
 * @brief Dma major done interrupt callback interface
 */
typedef void (*Dma_Drv_CallbackType)(const Dma_Drv_ChannelType Channel);

/**
 * @brief Dma error interrupt callback interface
 */
typedef void (*Dma_Drv_ErrIntCallbackType)(const Dma_Drv_ChannelType Channel);

/**
 * @brief DMA priority type definition
 */
typedef enum
{
    DMA_DRV_PRIORITY_LEVEL_0 = 0U,          /*!< dma channel priority 0, the lowest */
    DMA_DRV_PRIORITY_LEVEL_1,               /*!< dma channel priority 1 */
    DMA_DRV_PRIORITY_LEVEL_2,               /*!< dma channel priority 2 */
    DMA_DRV_PRIORITY_LEVEL_3,               /*!< dma channel priority 3 */
    DMA_DRV_PRIORITY_LEVEL_4,               /*!< dma channel priority 4 */
    DMA_DRV_PRIORITY_LEVEL_5,               /*!< dma channel priority 5 */
    DMA_DRV_PRIORITY_LEVEL_6,               /*!< dma channel priority 6 */
    DMA_DRV_PRIORITY_LEVEL_7,               /*!< dma channel priority 7 */
    DMA_DRV_PRIORITY_LEVEL_8,               /*!< dma channel priority 8 */
    DMA_DRV_PRIORITY_LEVEL_9,               /*!< dma channel priority 9 */
    DMA_DRV_PRIORITY_LEVEL_10,              /*!< dma channel priority 10 */
    DMA_DRV_PRIORITY_LEVEL_11,              /*!< dma channel priority 11 */
    DMA_DRV_PRIORITY_LEVEL_12,              /*!< dma channel priority 12 */
    DMA_DRV_PRIORITY_LEVEL_13,              /*!< dma channel priority 13 */
    DMA_DRV_PRIORITY_LEVEL_14,              /*!< dma channel priority 14 */
    DMA_DRV_PRIORITY_LEVEL_15               /*!< dma channel priority 15, the highest*/
} Dma_Drv_ChannelPriorityType;


/**
 *  @brief DMA transfer size type definition
 */
typedef enum
{
    DMA_DRV_TRANSFER_SIZE_1BYTE  = 0U,      /*!< dma once transfer size: 1 byte */
    DMA_DRV_TRANSFER_SIZE_2BYTE,            /*!< dma once transfer size: 2 bytes */
    DMA_DRV_TRANSFER_SIZE_4BYTE             /*!< dma once transfer size: 4 bytes */
} Dma_Drv_TransferSizeType;

/**
 * @brief the DMA hardware request source type. Defines the structure for the DMA hardware request
 * collections. The user can configure the hardware request into DMAMUX to trigger the DMA transfer
 * accordingly. The index of the hardware request varies according  to the SoC.
 */
typedef enum
{
    DMA_DRV_REQ_I2S0                    = 0U,    /*!< dma input source: i2s0 tx */
    DMA_DRV_REQ_I2S1                    = 1U,    /*!< dma input source: i2s1 tx */

    DMA_DRV_REQ_UART0_TX                = 2U,    /*!< dma input source: uart0 tx */
    DMA_DRV_REQ_UART0_RX                = 3U,    /*!< dma input source: uart0 rx */
    DMA_DRV_REQ_UART1_TX                = 4U,    /*!< dma input source: uart1 tx */
    DMA_DRV_REQ_UART1_RX                = 5U,    /*!< dma input source: uart1 rx */
    DMA_DRV_REQ_UART2_TX                = 6U,    /*!< dma input source: uart2 tx */
    DMA_DRV_REQ_UART2_RX                = 7U,    /*!< dma input source: uart2 rx */
    DMA_DRV_REQ_UART3_TX                = 8U,    /*!< dma input source: uart3 tx */
    DMA_DRV_REQ_UART3_RX                = 9U,    /*!< dma input source: uart3 rx */
    DMA_DRV_REQ_UART4_TX                = 10U,   /*!< dma input source: uart4 tx */
    DMA_DRV_REQ_UART4_RX                = 11U,   /*!< dma input source: uart4 rx */
    DMA_DRV_REQ_UART5_TX                = 12U,   /*!< dma input source: uart5 tx */
    DMA_DRV_REQ_UART5_RX                = 13U,   /*!< dma input source: uart5 rx */

    DMA_DRV_REQ_SPI0_TX                 = 14U,   /*!< dma input source: spi0 tx */
    DMA_DRV_REQ_SPI0_RX                 = 15U,   /*!< dma input source: spi0 rx */
    DMA_DRV_REQ_SPI1_TX                 = 16U,   /*!< dma input source: spi1 tx */
    DMA_DRV_REQ_SPI1_RX                 = 17U,   /*!< dma input source: spi1 rx */
    DMA_DRV_REQ_SPI2_TX                 = 18U,   /*!< dma input source: spi2 tx */
    DMA_DRV_REQ_SPI2_RX                 = 19U,   /*!< dma input source: spi2 rx */
    DMA_DRV_REQ_SPI3_TX                 = 20U,   /*!< dma input source: spi3 tx */
    DMA_DRV_REQ_SPI3_RX                 = 21U,   /*!< dma input source: spi3 rx */

    DMA_DRV_REQ_STIM0                   = 22U,   /*!< dma input source: STIM0 */
    DMA_DRV_REQ_STIM1                   = 23U,   /*!< dma input source: STIM1 */
    DMA_DRV_REQ_STIM2                   = 24U,   /*!< dma input source: STIM2 */
    DMA_DRV_REQ_STIM3                   = 25U,   /*!< dma input source: STIM3 */

    DMA_DRV_REQ_I2C0_TX                 = 26U,   /*!< dma input source: i2c0 tx */
    DMA_DRV_REQ_I2C0_RX                 = 27U,   /*!< dma input source: i2c0 rx */
    DMA_DRV_REQ_I2C1_TX                 = 28U,   /*!< dma input source: i2c1 tx */
    DMA_DRV_REQ_I2C1_RX                 = 29U,   /*!< dma input source: i2c1 rx */

    DMA_DRV_REQ_CAN0                    = 30U,   /*!< dma input source: can0 */
    DMA_DRV_REQ_CAN1                    = 31U,   /*!< dma input source: can1 */
    DMA_DRV_REQ_CAN2                    = 32U,   /*!< dma input source: can2 */
    DMA_DRV_REQ_CAN3                    = 33U,   /*!< dma input source: can3 */
    DMA_DRV_REQ_CAN4                    = 34U,   /*!< dma input source: can4 */
    DMA_DRV_REQ_CAN5                    = 35U,   /*!< dma input source: can5 */
    DMA_DRV_REQ_CAN6                    = 36U,   /*!< dma input source: can6 */
    DMA_DRV_REQ_CAN7                    = 37U,   /*!< dma input source: can7 */

    DMA_DRV_REQ_TIM0_CHANNEL0           = 38U,   /*!< dma input source: tim0-channel0 */
    DMA_DRV_REQ_TIM0_CHANNEL1           = 39U,   /*!< dma input source: tim0-channel1 */
    DMA_DRV_REQ_TIM0_CHANNEL2           = 40U,   /*!< dma input source: tim0-channel2 */
    DMA_DRV_REQ_TIM0_CHANNEL3           = 41U,   /*!< dma input source: tim0-channel3 */
    DMA_DRV_REQ_TIM0_CHANNEL4           = 42U,   /*!< dma input source: tim0-channel4 */
    DMA_DRV_REQ_TIM0_CHANNEL5           = 43U,   /*!< dma input source: tim0-channel5 */
    DMA_DRV_REQ_TIM0_CHANNEL6           = 44U,   /*!< dma input source: tim0-channel6 */
    DMA_DRV_REQ_TIM0_CHANNEL7           = 45U,   /*!< dma input source: tim0-channel7 */
    DMA_DRV_REQ_TIM1_CHANNEL0           = 46U,   /*!< dma input source: tim1-channel0 */
    DMA_DRV_REQ_TIM1_CHANNEL1           = 47U,   /*!< dma input source: tim1-channel1 */
    DMA_DRV_REQ_TIM1_CHANNEL2           = 48U,   /*!< dma input source: tim1-channel2 */
    DMA_DRV_REQ_TIM1_CHANNEL3           = 49U,   /*!< dma input source: tim1-channel3 */
    DMA_DRV_REQ_TIM1_CHANNEL4           = 50U,   /*!< dma input source: tim1-channel4 */
    DMA_DRV_REQ_TIM1_CHANNEL5           = 51U,   /*!< dma input source: tim1-channel5 */
    DMA_DRV_REQ_TIM1_CHANNEL6           = 52U,   /*!< dma input source: tim1-channel6 */
    DMA_DRV_REQ_TIM1_CHANNEL7           = 53U,   /*!< dma input source: tim1-channel7 */
    DMA_DRV_REQ_TIM2_CHANNEL0           = 54U,   /*!< dma input source: tim2-channel0 */
    DMA_DRV_REQ_TIM2_CHANNEL1           = 55U,   /*!< dma input source: tim2-channel1 */
    DMA_DRV_REQ_TIM2_CHANNEL2           = 56U,   /*!< dma input source: tim2-channel2 */
    DMA_DRV_REQ_TIM2_CHANNEL3           = 57U,   /*!< dma input source: tim2-channel3 */
    DMA_DRV_REQ_TIM2_CHANNEL4           = 58U,   /*!< dma input source: tim2-channel4 */
    DMA_DRV_REQ_TIM2_CHANNEL5           = 59U,   /*!< dma input source: tim2-channel5 */
    DMA_DRV_REQ_TIM2_CHANNEL6           = 60U,   /*!< dma input source: tim2-channel6 */
    DMA_DRV_REQ_TIM2_CHANNEL7           = 61U,   /*!< dma input source: tim2-channel7 */
    DMA_DRV_REQ_TIM3_CHANNEL0           = 62U,   /*!< dma input source: tim3-channel0 */
    DMA_DRV_REQ_TIM3_CHANNEL1           = 63U,   /*!< dma input source: tim3-channel1 */
    DMA_DRV_REQ_TIM3_CHANNEL2           = 64U,   /*!< dma input source: tim3-channel2 */
    DMA_DRV_REQ_TIM3_CHANNEL3           = 65U,   /*!< dma input source: tim3-channel3 */
    DMA_DRV_REQ_TIM3_CHANNEL4           = 66U,   /*!< dma input source: tim3-channel4 */
    DMA_DRV_REQ_TIM3_CHANNEL5           = 67U,   /*!< dma input source: tim3-channel5 */
    DMA_DRV_REQ_TIM3_CHANNEL6           = 68U,   /*!< dma input source: tim3-channel6 */
    DMA_DRV_REQ_TIM3_CHANNEL7           = 69U,   /*!< dma input source: tim3-channel7 */

    DMA_DRV_REQ_MCPWM0_CHANNEL0          = 70U,   /*!< dma input source: mcpwm0-channel0 */
    DMA_DRV_REQ_MCPWM0_CHANNEL1          = 71U,   /*!< dma input source: mcpwm0-channel1 */
    DMA_DRV_REQ_MCPWM0_CHANNEL2          = 72U,   /*!< dma input source: mcpwm0-channel2 */
    DMA_DRV_REQ_MCPWM0_CHANNEL3          = 73U,   /*!< dma input source: mcpwm0-channel3 */
    DMA_DRV_REQ_MCPWM0_CHANNEL4          = 74U,   /*!< dma input source: mcpwm0-channel4 */
    DMA_DRV_REQ_MCPWM0_CHANNEL5          = 75U,   /*!< dma input source: mcpwm0-channel5 */
    DMA_DRV_REQ_MCPWM0_CHANNEL6          = 76U,   /*!< dma input source: mcpwm0-channel6 */
    DMA_DRV_REQ_MCPWM0_CHANNEL7          = 77U,   /*!< dma input source: mcpwm0-channel7 */
    DMA_DRV_REQ_MCPWM1_CHANNEL0          = 78U,   /*!< dma input source: mcpwm1-channel0 */
    DMA_DRV_REQ_MCPWM1_CHANNEL1          = 79U,   /*!< dma input source: mcpwm1-channel1 */
    DMA_DRV_REQ_MCPWM1_CHANNEL2          = 80U,   /*!< dma input source: mcpwm1-channel2 */
    DMA_DRV_REQ_MCPWM1_CHANNEL3          = 81U,   /*!< dma input source: mcpwm1-channel3 */
    DMA_DRV_REQ_MCPWM1_CHANNEL4          = 82U,   /*!< dma input source: mcpwm1-channel4 */
    DMA_DRV_REQ_MCPWM1_CHANNEL5          = 83U,   /*!< dma input source: mcpwm1-channel5 */
    DMA_DRV_REQ_MCPWM1_CHANNEL6          = 84U,   /*!< dma input source: mcpwm1-channel6 */
    DMA_DRV_REQ_MCPWM1_CHANNEL7          = 85U,   /*!< dma input source: mcpwm1-channel7 */

    DMA_DRV_REQ_ADC0                    = 88U,   /*!< dma input source: adc0 */
    DMA_DRV_REQ_ADC1                    = 89U,   /*!< dma input source: adc1 */

    DMA_DRV_REQ_CMP                     = 90U,   /*!< dma input source: cmp */

    DMA_DRV_REQ_PORTA                   = 91U,   /*!< dma input source: PORTA */
    DMA_DRV_REQ_PORTB                   = 92U,   /*!< dma input source: PORTB */
    DMA_DRV_REQ_PORTC                   = 93U,   /*!< dma input source: PORTC */
    DMA_DRV_REQ_PORTD                   = 94U,   /*!< dma input source: PORTD */
    DMA_DRV_REQ_PORTE                   = 95U,   /*!< dma input source: PORTE */

    DMA_DRV_REQ_DMAMUX_ALWAYS_ENABLED0  = 96U,   /*!< dma input source: always on channel 0 */
    DMA_DRV_REQ_DMAMUX_ALWAYS_ENABLED1  = 97U,   /*!< dma input source: always on channel 1 */

    DMA_DRV_REQ_SOFTWARE                = 128U   /*!< software trigger to DMA channel */
} Dma_Drv_RequestSourceType;

/**
 * @brief Dma channel request source configure type definition.
*/
typedef struct
{
    Dma_Drv_RequestSourceType MuxReqSrc;   /*!< dma mux input source */
    boolean ReqEn;                     /*!< dma channel request control
                                            - TRUE: enable dma channel hardware request
                                            - FALSE: disable dma channel hardware request */
} Dma_Drv_RequestConfigType;

/**
 * @brief Dma channel priority configure type definition.
*/
typedef struct
{
    uint8 Priority;                        /*!< dma channel priority */
    boolean PreemptionDis;                 /*!< dma channel preemption control
                                                - TRUE: not allow channel preempt a lower priority channel
                                                - FALSE: allow channel preempt a lower priority channel */
    boolean SuspendEn;                     /*!< dma channel suspend control
                                                - TRUE: allow channel suspended by a higher priority channel
                                                - FALSE: not allow channel suspended by a higher priority channel */
} Dma_Drv_PriorityConfigType;

/**
 * @brief Dma channel global configure type definition.
 *
 *
 */
typedef struct
{
    boolean ErrIntEn;                      /*!< dma channel error interrupt control
                                                    - TRUE: enable dma channel error interrupt
                                                    - FALSE: disable dma channel error interrupt */
    boolean MajorIntEn;                    /*!< major done interrupt control
                                                - TRUE: enable major done interrupt
                                                - FALSE: disable major done interrupt */
    Dma_Drv_RequestConfigType * RequestConfig;     /* !< dma channel request source configuration */
    Dma_Drv_PriorityConfigType * PriorityConfig;   /* !< dma channel priority configuration */
} Dma_Drv_ChannelGlobalConfigType;

/**
 * @brief Dma channel source or destination address configure type definition.
*/
typedef struct
{
    uint32 Addr;                            /*!< transfer start address */
    sint16 MinorLoopOffset;                 /*!< transfer minor loop offset */
    sint16 MajorLoopOffset;                 /*!< transfer major loop offset */
    Dma_Drv_TransferSizeType TransferSize;  /*!< transfer size */
} Dma_Drv_AddrConfigType;

typedef struct
{
    uint32 TransferNum;                   /*!< transfer number in a minor loop */
    uint16 MinorLoopCnt;                  /*!< minor loop count in a major loop */
    boolean ReqDis;                       /*!< auto disable request control
                                                - TRUE: auto disable hardware request after done flag set
                                                - FALSE: no disable hardware request after done flag set */
} Dma_Drv_TransferControlConfigType;

/**
 * @brief Dma channel transfer configure type definition.
 */
typedef struct
{
    Dma_Drv_AddrConfigType * SourceConfig;      /* !< dma channel source configuration */
    Dma_Drv_AddrConfigType * DestinationConfig; /* !< dma channel destination configuration */
    Dma_Drv_TransferControlConfigType * ControlConfig; /* !< dma channel transfer control configuration */
} Dma_Drv_ChannelTransferConfigType;


/**
 * @brief Dma HW module configure type definition.
 *
 * */
typedef struct
{
    boolean DebugHalt;          /*!< debug mode control
                                    - TRUE: dma will halt after completing the executing channel
                                            data transfer in debug mode
                                    - FALSE: dma continue to data transfer in debug mode */
    boolean RoundRobin;         /*!< round robin channel arbitration control
                                    - TRUE: channel use round robin arbitration
                                    - FALSE: channel use fixed priority arbitration */
    boolean ErrHalt;            /*!< halt on error control
                                    - TRUE: halt bit of DMA_CONF will assert and dma operation will
                                            halt when error occur
                                    - FALSE: dma will not halt when error occur */
} Dma_Drv_ConfigType;


/**
 *  @brief DMA interrupt type definition
 */
typedef enum
{
    DMA_DRV_INT_ERROR = 0U,                /*!< dma error interrupt */
    DMA_DRV_INT_DONE,                      /*!< dma done interrupt */
    DMA_DRV_INT_ALL                        /*!< dma all interrupt */
} Dma_Drv_IntType;

/**
 * @brief DMA halt type definition
*/
typedef enum
{
    DMA_DRV_HALT_OFF              = 0U,              /*!< resume the dma */
    DMA_DRV_HALT_ON                                  /*!< stall the dma */
} Dma_Drv_HaltType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma */

/** @} end of group Dma_Module */

#endif /*DMA_DRV_TYPES*/
