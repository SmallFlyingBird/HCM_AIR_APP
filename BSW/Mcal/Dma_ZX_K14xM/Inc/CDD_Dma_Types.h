/**************************************************************************************************/
/**
 * @file      : CDD_Dma_Types.h
 * @brief     : CDD Dma type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CDD_DMA_TYPES_H
#define CDD_DMA_TYPES_H

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup CDD_Dma_Types
 *  @brief CDD Dma types definition
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "CDD_Dma_Cfg.h"
#include "Dma_Drv_Types.h"

  
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define CDD_DMA_TYPES_H_VENDOR_ID                   0x00B3U
#define CDD_DMA_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_DMA_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CDD_DMA_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CDD_DMA_TYPES_H_SW_MAJOR_VERSION            1U
#define CDD_DMA_TYPES_H_SW_MINOR_VERSION            2U
#define CDD_DMA_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and CDD_Dma_Cfg.h are the same vendor */
#if (CDD_DMA_TYPES_H_VENDOR_ID != CDD_DMA_CFG_H_VENDOR_ID)
    #error "Vendor ID of CDD_Dma_Types.h and CDD_Dma_Cfg.h are different"
#endif
/* Check if current file and CDD_Dma_Cfg.h are the same Autosar version */
#if ((CDD_DMA_TYPES_H_AR_RELEASE_MAJOR_VERSION != CDD_DMA_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (CDD_DMA_TYPES_H_AR_RELEASE_MINOR_VERSION != CDD_DMA_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (CDD_DMA_TYPES_H_AR_RELEASE_REVISION_VERSION != CDD_DMA_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of CDD_Dma_Types.h and CDD_Dma_Cfg.h are different"
#endif
/* Check if current file and CDD_Dma_Cfg.h are the same software version */
#if ((CDD_DMA_TYPES_H_SW_MAJOR_VERSION != CDD_DMA_CFG_H_SW_MAJOR_VERSION) ||                       \
     (CDD_DMA_TYPES_H_SW_MINOR_VERSION != CDD_DMA_CFG_H_SW_MINOR_VERSION) ||                       \
     (CDD_DMA_TYPES_H_SW_PATCH_VERSION != CDD_DMA_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of CDD_Dma_Types.h and CDD_Dma_Cfg.h are different"
#endif

/* Check if current file and Dma_Drv_Types.h are the same vendor */
#if (CDD_DMA_TYPES_H_VENDOR_ID != DMA_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of CDD_Dma_Types.h and Dma_Drv_Types.h are different"
#endif
/* Check if current file and Dma_Drv_Types.h are the same Autosar version */
#if ((CDD_DMA_TYPES_H_AR_RELEASE_MAJOR_VERSION != DMA_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (CDD_DMA_TYPES_H_AR_RELEASE_MINOR_VERSION != DMA_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||     \
     (CDD_DMA_TYPES_H_AR_RELEASE_REVISION_VERSION != DMA_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of CDD_Dma_Types.h and Dma_Drv_Types.h are different"
#endif
/* Check if current file and Dma_Drv_Types.h are the same software version */
#if ((CDD_DMA_TYPES_H_SW_MAJOR_VERSION != DMA_DRV_TYPES_H_SW_MAJOR_VERSION) ||                     \
     (CDD_DMA_TYPES_H_SW_MINOR_VERSION != DMA_DRV_TYPES_H_SW_MINOR_VERSION) ||                     \
     (CDD_DMA_TYPES_H_SW_PATCH_VERSION != DMA_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of CDD_Dma_Types.h and Dma_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/**
 * @brief Dma Callback interface
 * 
 */
typedef void (*Dma_CallbackType)(uint32 LogicChIndex);


/**
 * @brief Dma channel state values enum definition.
 * 
 */
typedef enum
{
    DMA_CH_UNINIT_STATE        = 0U,  /*!< dma channel is uninitiated */
    DMA_CH_READY_STATE         = 1U,  /*!< dma channel ready state after init */
    DMA_CH_ERROR_STATE         = 2U   /*!< dma channel error state */
} Dma_ChannelStateType;

/**
 *  @brief DMA transfer size type definition 
 */
typedef enum
{
    DMA_TRANSFER_SIZE_1BYTE  = 0U,      /*!< dma once transfer size: 1 byte */
    DMA_TRANSFER_SIZE_2BYTE,            /*!< dma once transfer size: 2 bytes */
    DMA_TRANSFER_SIZE_4BYTE             /*!< dma once transfer size: 4 bytes */
} Dma_TransferSizeType;

/**
 * @brief the DMA hardware request source type. Defines the structure for the DMA hardware request 
 * collections. The user can configure the hardware request into DMAMUX to trigger the DMA transfer 
 * accordingly. The index of the hardware request varies according to the SoC.
 */
typedef enum
{
    DMA_REQ_UART0_TX                = 2U,    /*!< dma input source: uart0 tx */
    DMA_REQ_UART0_RX                = 3U,    /*!< dma input source: uart0 rx */
    DMA_REQ_UART1_TX                = 4U,    /*!< dma input source: uart1 tx */
    DMA_REQ_UART1_RX                = 5U,    /*!< dma input source: uart1 rx */
    DMA_REQ_UART2_TX                = 6U,    /*!< dma input source: uart2 tx */
    DMA_REQ_UART2_RX                = 7U,    /*!< dma input source: uart2 rx */
    DMA_REQ_UART3_TX                = 8U,    /*!< dma input source: uart3 tx */
    DMA_REQ_UART3_RX                = 9U,    /*!< dma input source: uart3 rx */
    DMA_REQ_UART4_TX                = 10U,   /*!< dma input source: uart4 tx */
    DMA_REQ_UART4_RX                = 11U,   /*!< dma input source: uart4 rx */
    DMA_REQ_UART5_TX                = 12U,   /*!< dma input source: uart5 tx */
    DMA_REQ_UART5_RX                = 13U,   /*!< dma input source: uart5 rx */
    
    DMA_REQ_SPI0_TX                 = 14U,   /*!< dma input source: spi0 tx */
    DMA_REQ_SPI0_RX                 = 15U,   /*!< dma input source: spi0 rx */
    DMA_REQ_SPI1_TX                 = 16U,   /*!< dma input source: spi1 tx */
    DMA_REQ_SPI1_RX                 = 17U,   /*!< dma input source: spi1 rx */
    DMA_REQ_SPI2_TX                 = 18U,   /*!< dma input source: spi2 tx */
    DMA_REQ_SPI2_RX                 = 19U,   /*!< dma input source: spi2 rx */
    DMA_REQ_SPI3_TX                 = 20U,   /*!< dma input source: spi3 tx */
    DMA_REQ_SPI3_RX                 = 21U,   /*!< dma input source: spi3 rx */

    DMA_REQ_STIM0                   = 22U,   /*!< dma input source: STIM0 */
    DMA_REQ_STIM1                   = 23U,   /*!< dma input source: STIM1 */
    DMA_REQ_STIM2                   = 24U,   /*!< dma input source: STIM2 */
    DMA_REQ_STIM3                   = 25U,   /*!< dma input source: STIM3 */
    
    DMA_REQ_I2C0_TX                 = 26U,   /*!< dma input source: i2c0 tx */
    DMA_REQ_I2C0_RX                 = 27U,   /*!< dma input source: i2c0 rx */
    DMA_REQ_I2C1_TX                 = 28U,   /*!< dma input source: i2c1 tx */
    DMA_REQ_I2C1_RX                 = 29U,   /*!< dma input source: i2c1 rx */
    
    DMA_REQ_CAN0                    = 30U,   /*!< dma input source: can0 */
    DMA_REQ_CAN1                    = 31U,   /*!< dma input source: can1 */
    DMA_REQ_CAN2                    = 32U,   /*!< dma input source: can2 */
    DMA_REQ_CAN3                    = 33U,   /*!< dma input source: can3 */
    DMA_REQ_CAN4                    = 34U,   /*!< dma input source: can4 */
    DMA_REQ_CAN5                    = 35U,   /*!< dma input source: can5 */
    DMA_REQ_CAN6                    = 36U,   /*!< dma input source: can6 */
    DMA_REQ_CAN7                    = 37U,   /*!< dma input source: can7 */
    
    DMA_REQ_TIM0_CHANNEL0           = 38U,   /*!< dma input source: tim0-channel0 */
    DMA_REQ_TIM0_CHANNEL1           = 39U,   /*!< dma input source: tim0-channel1 */
    DMA_REQ_TIM0_CHANNEL2           = 40U,   /*!< dma input source: tim0-channel2 */
    DMA_REQ_TIM0_CHANNEL3           = 41U,   /*!< dma input source: tim0-channel3 */
    DMA_REQ_TIM0_CHANNEL4           = 42U,   /*!< dma input source: tim0-channel4 */
    DMA_REQ_TIM0_CHANNEL5           = 43U,   /*!< dma input source: tim0-channel5 */
    DMA_REQ_TIM0_CHANNEL6           = 44U,   /*!< dma input source: tim0-channel6 */
    DMA_REQ_TIM0_CHANNEL7           = 45U,   /*!< dma input source: tim0-channel7 */
    DMA_REQ_TIM1_CHANNEL0           = 46U,   /*!< dma input source: tim1-channel0 */
    DMA_REQ_TIM1_CHANNEL1           = 47U,   /*!< dma input source: tim1-channel1 */
    DMA_REQ_TIM1_CHANNEL2           = 48U,   /*!< dma input source: tim1-channel2 */
    DMA_REQ_TIM1_CHANNEL3           = 49U,   /*!< dma input source: tim1-channel3 */
    DMA_REQ_TIM1_CHANNEL4           = 50U,   /*!< dma input source: tim1-channel4 */
    DMA_REQ_TIM1_CHANNEL5           = 51U,   /*!< dma input source: tim1-channel5 */
    DMA_REQ_TIM1_CHANNEL6           = 52U,   /*!< dma input source: tim1-channel6 */
    DMA_REQ_TIM1_CHANNEL7           = 53U,   /*!< dma input source: tim1-channel7 */
    DMA_REQ_TIM2_CHANNEL0           = 54U,   /*!< dma input source: tim2-channel0 */
    DMA_REQ_TIM2_CHANNEL1           = 55U,   /*!< dma input source: tim2-channel1 */
    DMA_REQ_TIM2_CHANNEL2           = 56U,   /*!< dma input source: tim2-channel2 */
    DMA_REQ_TIM2_CHANNEL3           = 57U,   /*!< dma input source: tim2-channel3 */
    DMA_REQ_TIM2_CHANNEL4           = 58U,   /*!< dma input source: tim2-channel4 */
    DMA_REQ_TIM2_CHANNEL5           = 59U,   /*!< dma input source: tim2-channel5 */
    DMA_REQ_TIM2_CHANNEL6           = 60U,   /*!< dma input source: tim2-channel6 */
    DMA_REQ_TIM2_CHANNEL7           = 61U,   /*!< dma input source: tim2-channel7 */
    DMA_REQ_TIM3_CHANNEL0           = 62U,   /*!< dma input source: tim3-channel0 */
    DMA_REQ_TIM3_CHANNEL1           = 63U,   /*!< dma input source: tim3-channel1 */
    DMA_REQ_TIM3_CHANNEL2           = 64U,   /*!< dma input source: tim3-channel2 */
    DMA_REQ_TIM3_CHANNEL3           = 65U,   /*!< dma input source: tim3-channel3 */
    DMA_REQ_TIM3_CHANNEL4           = 66U,   /*!< dma input source: tim3-channel4 */
    DMA_REQ_TIM3_CHANNEL5           = 67U,   /*!< dma input source: tim3-channel5 */
    DMA_REQ_TIM3_CHANNEL6           = 68U,   /*!< dma input source: tim3-channel6 */
    DMA_REQ_TIM3_CHANNEL7           = 69U,   /*!< dma input source: tim3-channel7 */

    DMA_REQ_MCPWM0_CHANNEL0         = 70U,   /*!< dma input source: mcpwm0-channel0 */
    DMA_REQ_MCPWM0_CHANNEL1         = 71U,   /*!< dma input source: mcpwm0-channel1 */
    DMA_REQ_MCPWM0_CHANNEL2         = 72U,   /*!< dma input source: mcpwm0-channel2 */
    DMA_REQ_MCPWM0_CHANNEL3         = 73U,   /*!< dma input source: mcpwm0-channel3 */
    DMA_REQ_MCPWM0_CHANNEL4         = 74U,   /*!< dma input source: mcpwm0-channel4 */
    DMA_REQ_MCPWM0_CHANNEL5         = 75U,   /*!< dma input source: mcpwm0-channel5 */
    DMA_REQ_MCPWM0_CHANNEL6         = 76U,   /*!< dma input source: mcpwm0-channel6 */
    DMA_REQ_MCPWM0_CHANNEL7         = 77U,   /*!< dma input source: mcpwm0-channel7 */
    DMA_REQ_MCPWM1_CHANNEL0         = 78U,   /*!< dma input source: mcpwm1-channel0 */
    DMA_REQ_MCPWM1_CHANNEL1         = 79U,   /*!< dma input source: mcpwm1-channel1 */
    DMA_REQ_MCPWM1_CHANNEL2         = 80U,   /*!< dma input source: mcpwm1-channel2 */
    DMA_REQ_MCPWM1_CHANNEL3         = 81U,   /*!< dma input source: mcpwm1-channel3 */
    DMA_REQ_MCPWM1_CHANNEL4         = 82U,   /*!< dma input source: mcpwm1-channel4 */
    DMA_REQ_MCPWM1_CHANNEL5         = 83U,   /*!< dma input source: mcpwm1-channel5 */
    DMA_REQ_MCPWM1_CHANNEL6         = 84U,   /*!< dma input source: mcpwm1-channel6 */
    DMA_REQ_MCPWM1_CHANNEL7         = 85U,   /*!< dma input source: mcpwm1-channel7 */

    DMA_REQ_ADC0                    = 88U,   /*!< dma input source: adc0 */
    DMA_REQ_ADC1                    = 89U,   /*!< dma input source: adc1 */
    
    DMA_REQ_CMP                     = 90U,   /*!< dma input source: cmp */
    
    DMA_REQ_PORTA                   = 91U,   /*!< dma input source: PORTA */
    DMA_REQ_PORTB                   = 92U,   /*!< dma input source: PORTB */
    DMA_REQ_PORTC                   = 93U,   /*!< dma input source: PORTC */
    DMA_REQ_PORTD                   = 94U,   /*!< dma input source: PORTD */
    DMA_REQ_PORTE                   = 95U,   /*!< dma input source: PORTE */
    
    DMA_REQ_DMAMUX_ALWAYS_ENABLED0  = 96U,   /*!< dma input source: always on channel 0 */
    DMA_REQ_DMAMUX_ALWAYS_ENABLED1  = 97U,   /*!< dma input source: always on channel 1 */

    DMA_REQ_SOFTWARE                = 128U   /*!< software trigger to DMA channel */
} Dma_RequestSourceType;

/**
 * @brief Dma channel source or destination address configure type definition.
*/
typedef struct
{
    uint32 Addr;                            /*!< transfer start address */
    sint16 MinorLoopOffset;                 /*!< transfer minor loop offset */
    sint16 MajorLoopOffset;                 /*!< transfer major loop offset */
    Dma_TransferSizeType TransferSize;  /*!< transfer size */
} Dma_AddrConfigType;

typedef Dma_Drv_TransferControlConfigType Dma_TransferControlConfigType;

/**
 * @brief Dma channel transfer configure type definition.
 */
typedef struct
{
    Dma_AddrConfigType * SourceConfig;      /* !< dma channel source configuration */
    Dma_AddrConfigType * DestinationConfig; /* !< dma channel destination configuration */
    Dma_TransferControlConfigType * ControlConfig; /* !< dma channel transfer control configuration */
} Dma_ChannelTransferConfigType;

/**
 * @brief Dma channel request source configure type definition.
*/
typedef struct
{
    Dma_RequestSourceType MuxReqSrc;   /*!< dma mux input source */
    boolean ReqEn;                     /*!< dma channel request control
                                            - TRUE: enable dma channel hardware request
                                            - FALSE: disable dma channel hardware request */
} Dma_RequestConfigType;

/**
 * @brief Dma channel priority configure type definition.
*/
typedef Dma_Drv_PriorityConfigType Dma_PriorityConfigType;

/**
 * @brief Dma channel global configure type definition.
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
    Dma_RequestConfigType * RequestConfig;     /* !< dma channel request source configuration */
    Dma_PriorityConfigType * PriorityConfig;   /* !< dma channel priority configuration */
} Dma_ChannelGlobalConfigType;

/**
 * @brief Dma channel operation state type definition.
 * 
 */
typedef struct
{
    uint32 ChErrState;                         /*!< dma logic channel error state */ 
    Dma_ChannelStateType ChState;              /*!< dma logic channel state */ 
} Dma_ChannelOptStateType;



typedef struct
{  
    Dma_Drv_ChannelType PhyChId;                                /*!< physical channel ID */
    Dma_CallbackType ErrIntCallback;                            /*!< dma channel error interrupt 
                                                                     callback */
    Dma_CallbackType MajorIntCallback;                          /*!< dma channel major done
                                                                     interrupt callback */
    const Dma_Drv_ChannelGlobalConfigType  * ChGlobalCfgPtr;    /*!< pointer to channel global
                                                                     configuration */
    const Dma_Drv_ChannelTransferConfigType * ChTransferCfgPtr; /*!< transfer configuration pointer 
                                                                     contain channel transfer 
                                                                     parameters */         
} Dma_ChannelConfigType;



typedef struct 
{
    const Dma_ChannelConfigType * const * ChCfgArrayPtr;     /*!< contain a pointer to channel 
                                                                  configuration array */
    const Dma_Drv_ConfigType * const * ModuleCfgArrayPtr;    /*!< pointer to module configuration
                                                                  array */
} Dma_ConfigType;


/**
 * @brief Dma channel status type definition.
 * 
 */
typedef struct
{
    Dma_ChannelStateType State;    /*!< dma channel state */
    uint32  Error;                 /*!< channel error
                                    - DBEF(bit 0)  : destination bus error
                                    - SBEF(bit 1)  : source bus error
                                    - NUMEF(bit 3) : TransferNum is not multiple of
                                                     source TransferSize or destination TransferSize
                                    - DOEF(bit 4)  : destination MinorLoopOffset or MajorLoopOffset
                                                     is not multiple of destination TransferSize
                                    - DAEF(bit 5)  : destination address is not multiple of
                                                     destination TransferSize
                                    - SOEF(bit 6)  : source MinorLoopOffset or MajorLoopOffset
                                                     is not multiple of source TransferSize
                                    - SAEF(bit 7)  : source address is not multiple of
                                                     source TransferSize
                                    - PRIEF(bit 13): channel priority not unique error */
    boolean Busy;                  /*!< channel busy flag
                                    - TRUE: busy 
                                    - FALSE: idle */
    boolean Done;                  /*!< channel done flag
                                    - TRUE: major loop complete 
                                    - FALSE: major loop not done */
} Dma_ChannelStatusType;

/**
 * @brief Dma HW module status type definition
 *
 */
typedef struct
{
    uint16 LastErrChStatus;         /*!< error status of last channel error(DMA_ES reg reference) */
    uint16 ChannelsErrStatus;       /*!< error flag of all channel(DMA_CES reg reference) */
    boolean Busy;                   /*!< instance busy flag
                                            - TRUE: busy 
                                            - FALSE: idle */
    boolean Halt;                   /*!< last error channel valid flag
                                            - TRUE: dma stall the start new channels 
                                            - FALSE: dma is not halt */
} Dma_ModuleStatusType;

/**  
 *  @brief DMA interrupt type definition
 */
typedef enum
{
    DMA_INT_ERROR           = 0U,                /*!< dma error interrupt */
    DMA_INT_DONE,                                /*!< dma done interrupt */
    DMA_INT_ALL                                  /*!< dma all interrupt */
} Dma_IntType;

/**
 * @brief DMA halt type definition
*/
typedef enum
{
    DMA_HALT_OFF              = 0U,              /*!< resume the dma */
    DMA_HALT_ON                                  /*!< stall the dma */
} Dma_HaltType;

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

#endif /* CDD_DMA_TYPES_H */
