/**************************************************************************************************/
/**
 * @file      : Seru_Drv_Types.h
 * @brief     : Meh Extended MicroController Error Handle Types header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SERU_DRV_TYPES_H
#define SERU_DRV_TYPES_H

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Seru_Drv
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Seru_Drv_Cfg.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 *  @brief Published information
 */
#define SERU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define SERU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SERU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SERU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SERU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define SERU_DRV_TYPES_H_SW_MINOR_VERSION            1U
#define SERU_DRV_TYPES_H_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Seru_Drv_Cfg.h are of the same vendor
 */
#if (SERU_DRV_TYPES_H_VENDOR_ID != SERU_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv_Types.h and Seru_Drv_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv_Cfg.h are of the same Autosar version
 */
#if ((SERU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != SERU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (SERU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != SERU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (SERU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != SERU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Seru_Drv_Types.h and Seru_Drv_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv_Cfg.h are of the same SW version
 */
#if ((SERU_DRV_TYPES_H_SW_MAJOR_VERSION != SERU_DRV_CFG_H_SW_MAJOR_VERSION) ||                     \
     (SERU_DRV_TYPES_H_SW_MINOR_VERSION != SERU_DRV_CFG_H_SW_MINOR_VERSION) ||                     \
     (SERU_DRV_TYPES_H_SW_PATCH_VERSION != SERU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Seru_Drv_Types.h and Seru_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Std_Types.h and Seru_Drv_Types.h header files are of the same AUTOSAR version */
    #if ((STD_AR_RELEASE_MAJOR_VERSION != SERU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (STD_AR_RELEASE_MINOR_VERSION != SERU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Std_Types.h and Seru_Drv_Types.h are different"
    #endif
    /* Check if McalLib.h and Seru_Drv_Types.h header files are of the same AUTOSAR version */
    #if ((MCALLIB_AR_RELEASE_MAJOR_VERSION != SERU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (MCALLIB_AR_RELEASE_MINOR_VERSION != SERU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of McalLib.h and Seru_Drv_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of group Private_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief SERU mode type definition
 */
typedef enum
{
    SERU_DRV_NORMAL_MODE = 0U, /*!< In normal mode  */
    SERU_DRV_CONFIG_MODE       /*!< In config mode  */
} Seru_Drv_ModeType;


/**
 *  @brief EOUT bypass PORT control or not definition
 */
typedef enum
{
    SERU_DRV_EOUT_PORT = 0U, /*!< EOUT is controlled by PORT ALT selection to output  */
    SERU_DRV_EOUT_EXTERNAL   /*!< EOUT is bypassed PORT control to output external pin directly */
} Seru_Drv_ControlEoutModeType;

/**
 *  @brief EOUT Polarity Selection definition
 */
typedef enum
{
    SERU_DRV_EOUT0_HIGH_EOUT1_LOW = 0U, /*!< EOUT1 is low, and EOUT0 is high as default */
    SERU_DRV_EOUT0_LOW_EOUT1_HIGH       /*!< EOUT1 is high, and EOUT0 is low as default */
} Seru_Drv_SelectEoutPolarityType;


/**
 *  @brief delay for reset generation type definition
 */
typedef enum
{
    SERU_DRV_RST_DELAY_NO = 0U, /*!< No delay for reset generation */
    SERU_DRV_RST_DELAY_32,      /*!< 2048 seru_clk cycle for reset delay (32us) */
    SERU_DRV_RST_DELAY_64,      /*!< 4096 seru_clk cycle for reset delay (64us) */
    SERU_DRV_RST_DELAY_128      /*!< 8192 seru_clk cycle for reset delay (128us) */
} Seru_Drv_ResetDelayType;

/**
 *  @brief select RESET type definition
 */
typedef enum
{
    SERU_DRV_SEL_RST_NORMAL = 0U, /*!< Normal reset is selected */
    SERU_DRV_SEL_RST_COLD         /*!< Cold reset is selected */
} Seru_Drv_SelectResetType;

/**
 *  @brief SERU channel No. type definition
 */
typedef enum
{
    SERU_DRV_SW_ERR0 = 0U,          /*  SERU SW error0. */
    SERU_DRV_SW_ERR1,               /* SERU SW error1. */
    SERU_DRV_SW_ERR2,               /* SERU SW error2. */
    SERU_DRV_PMU_LVW_FLAG,           /* PMU LVW flag. */
    SERU_DRV_PMU_SRMC_LOWPOWER_MODE,/* PMU/SRMC Any low power mode but not including wait mode*/
    SERU_DRV_EWDT_INTERRUPT_FLAG,    /* EWDT interrupt flag. */
    SERU_DRV_CPU_LOCKUPFLAG,        /* CPU lockup flag. */
    SERU_DRV_RESERVED,               /* This value cannot be used. */
    SERU_DRV_SCC_OSC40M_LOSS_OF_CLOCK, /* SCC OSC40M loss of clock. */
    SERU_DRV_CMU0_BUS_CLOCK_ERROR, /* CMU0 Bus cock error. */
    SERU_DRV_CMU2_LPO_ERROR,         /* CMU2 LPO error. */
    SERU_DRV_FLASH_ECC_ERROR,        /* Flash ECC error. */
    SERU_DRV_FLASH_UNSECURE,        /* Flash un-secure. */
    SERU_DRV_SRAMU_ECC_ERROR,        /* SramU ECC error. */
    SERU_DRV_SRAML_ECC_ERROR,        /* SramL ECC error. */
    SERU_DRV_RESERVED1,              /* This value cannot be used. */
    SERU_DRV_CPU_DEBUG_HALT,         /* Debug and halt. */
} Seru_Drv_ChannelType;

/**
 *  @brief  Interrupt type definition
 */
typedef enum
{
    SERU_DRV_SEL_INT_NORMAL = 0U, /*!< Normal interrupt is selected*/
    SERU_DRV_SEL_INT_NMI          /*!< NMI is selected */
} Seru_Drv_IntType;

/**
 *  @brief SERU channel configure type definition
 */
typedef struct
{
    Seru_Drv_SelectResetType ResetType; /*!< Configure SERU RESET type
                                     - SERU_DRV_SEL_RST_NORMAL (0): Normal reset is selected
                                     - SERU_DRV_SEL_RST_COLD   (1): Cold reset is selected */

    Seru_Drv_ResetDelayType
        ResetDelay; /*!< Configure reset generation delay
         - SERU_DRV_RST_DELAY_NO (0) : no delay for reset generation
         - SERU_DRV_RST_DELAY_32 (1) : 2048 seru_clk cycle for reset delay (32us)
         - SERU_DRV_RST_DELAY_64 (2) : 4096 seru_clk cycle for reset delay (64us)
         - SERU_DRV_RST_DELAY_128 (3): 8192 seru_clk cycle for reset delay (128us) */

    boolean ResetEnable; /*!< Enable or disable RESET generation
                                   - FALSE (0): Error input on this channel  does not generate reset
                                   - TRUE  (1): Error input on this channel generates reset */

    boolean
        EoutEnable; /*!< Enable or disable EOUT report
                             - FALSE (0): Error input on this channel does not generate EOUT fault
                       state
                             - TRUE  (1):  Error input on this channel generates EOUT fault state */

    Seru_Drv_IntType IntType; /*!< Set INT type
                           - SERU_DRV_SEL_INT_NORMAL (0): Normal interrupt is selected
                           - SERU_DRV_SEL_INT_NMI (1)   :  NMI is selected */

    boolean
        IntEnable; /*!< Enable or disable INT generation
                             - FALSE (0): Error input on this channel  does not generate interrupt
                             - TRUE  (1): Error input on this channel  generates interrupt */

    boolean
        ChannelEnable;                /*!< Enable or disable channel
                                                - FALSE (0): Channel is disabled, no respond for error generation
                                                - TRUE  (1): Channel is enabled */
    Seru_Drv_ChannelType ChannelNo; /*!< channel number
                                   - SERU_DRV_CHANNEL_0: Channel 0
                                   - SERU_DRV_CHANNEL_1: Channel 1
                                   - ***
                                   - SERU_DRV_CHANNEL_16: Channel 16*/

} Seru_Drv_ChannelConfigType;

typedef struct
{
    boolean ParityErrorInterruptEnable; /*!< Enable or disable error interrupt */
    Seru_Drv_SelectEoutPolarityType
        PolaritySel; /*!< default value selection for EOUT
             - SERU_DRV_EOUT0_HIGH_EOUT1_LOW (0): EOUT1 is low, and EOUT0 is high
             - SERU_DRV_EOUT0_LOW_EOUT1_HIGH  (1): EOUT1 is high, and EOUT0 is low */
    Seru_Drv_ControlEoutModeType Eout0Mode;
    Seru_Drv_ControlEoutModeType Eout1Mode;
    boolean                      FaultInjectEnable;     /*!< Enable or disable fake fault injection
                                                      - FALSE (0): no action
                                                      - TRUE  (1): Fake fault injection at corresponding fault */
    uint8                       SeruChannelUserUsedNum; /*!< Channel number that user configured */
    const Seru_Drv_ChannelConfigType *SeruChannelConfigPtr;

} Seru_Drv_ConfigType;

#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
/**
 *  @brief ISR callback function type
 */
typedef void(Seru_Drv_ParityErrCallBackFunType)(void);
#endif
#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
/**
 *  @brief seru channel 0-16 callback function type
 */
typedef void(Seru_Drv_ChannelErrorCallBackFunType)(uint32 SeruCh);
#endif

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Seru_Drv */

/** @} end of group Meh_Module */
#endif /* SERU_DRV_TYPES_H */
