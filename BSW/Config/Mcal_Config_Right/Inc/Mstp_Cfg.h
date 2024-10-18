/**************************************************************************************************/
/**
 * @file      : Mstp_Cfg.h
 * @brief     : Mstp AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MSTP_CFG_H
#define MSTP_CFG_H

/** @addtogroup Mstp_Module
 *  @{
 */

/** @addtogroup Mstp
 *  @brief Mstp AUTOSAR level
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Device_Regs.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define MSTP_CFG_H_MODULE_ID                   2054U
#define MSTP_CFG_H_VENDOR_ID                   0x00B3U
#define MSTP_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MSTP_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MSTP_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MSTP_CFG_H_SW_MAJOR_VERSION            1U
#define MSTP_CFG_H_SW_MINOR_VERSION            1U
#define MSTP_CFG_H_SW_PATCH_VERSION            0U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h file are of the same Autosar version */
    #if ((MSTP_CFG_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||   \
         (MSTP_CFG_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Mstp_Cfg.h and Std_Types.h are different"
    #endif

    /* Check if current file and Device_Regs.h file are of the same Autosar version */
    #if ((MSTP_CFG_H_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (MSTP_CFG_H_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Mstp_Cfg.h and Device_Regs.h are different"
    #endif
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type definition of PARCC register
 */
typedef struct
{
    struct
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
    } PARCC_x[53U];
} Mstp_PeripheralCfgBfType;

/**
 *  @brief Type definition of PARCC register
 */
typedef struct
{
    uint32 PARCC_x[53U];
} Mstp_PeripheralCfgWType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define MSTP_START_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"

/**
 *  @brief CRC Register
 */
extern Reg_Crc_BfType *const Mstp_CrcRegBfPtr;
extern Reg_Crc_WType *const  Mstp_CrcRegWPtr;

/**
 *  @brief PARCC Register
 */
extern Reg_Parcc_BfType *const Mstp_ParccRegBfPtr;
extern Reg_Parcc_WType *const  Mstp_ParccRegWPtr;
extern Mstp_PeripheralCfgBfType *const Mstp_PeripheralRegBfPtr;
extern Mstp_PeripheralCfgWType *const Mstp_PeripheralRegWPtr;

/**
 *  @brief SERU Register
 */
extern Reg_Seru_WType *const  Mstp_SeruRegWPtr;
extern Reg_Seru_BfType *const Mstp_SeruRegBfPtr;

/**
 *  @brief EIRU Register
 */
extern Reg_Eiru_BfType *const Mstp_EiruRegBfPtr;
extern Reg_Eiru_WType *const  Mstp_EiruRegWPtr;

/**
 *  @brief PMU Register
 */
extern Reg_Pmu_WType *const  Mstp_PmuRegWPtr;
extern Reg_Pmu_BfType *const Mstp_PmuRegBfPtr;

/**
 *  @brief SRMC Register
 */
extern Reg_Srmc_WType *const Mstp_SrmcRegWPtr;

/**
 *  @brief SCC Register
 */
extern Reg_Scc_WType *const Mstp_SccRegWPtr;

/**
 *  @brief SCM Register
 */
extern Reg_Scm_WType *const  Mstp_ScmRegWPtr;
extern Reg_Scm_BfType *const Mstp_ScmRegBfPtr;

/**
 *  @brief CMU Register
 */
extern Reg_Cmu_WType *const Mstp_Cmu0RegWPtr;
extern Reg_Cmu_WType *const Mstp_Cmu1RegWPtr;
extern Reg_Cmu_WType *const Mstp_Cmu2RegWPtr;

extern Reg_Cmu_BfType *const Mstp_CmuRegBfPtr[3U];
extern Reg_Cmu_WType *const  Mstp_CmuRegWPtr[3U];

/**
 *  @brief FLASHC Register
 */
extern Reg_Flash_BfType *const Mstp_FlashRegBfPtr;
extern Reg_Flash_WType *const  Mstp_FlashRegWPtr;

/**
 *  @brief WDOG Register
 */
extern Reg_Wdog_BfType *const Mstp_WdogRegBfPtr;
extern Reg_Wdog_WType *const  Mstp_WdogRegWPtr;

/**
 *  @brief EWDT Register
 */
extern Reg_Ewdt_BfType *const Mstp_EwdtRegBfPtr;
extern Reg_Ewdt_WType *const  Mstp_EwdtRegWPtr;

/**
 *  @brief STIM Register
 */
extern Reg_Stim_BfType *const Mstp_StimRegBfPtr;
extern Reg_Stim_WType *const  Mstp_StimRegWPtr;

/**
 *  @brief TIM0, TIM1, TIM2 TIM3 address array
 */
extern Reg_Tim_BfType *const Mstp_TimRegBfPtr[4U];
extern Reg_Tim_WType *const Mstp_Tim0RegWPtr;
extern Reg_Tim_WType *const Mstp_Tim1RegWPtr;
extern Reg_Tim_WType *const Mstp_Tim2RegWPtr;
extern Reg_Tim_WType *const Mstp_Tim3RegWPtr;

/**
 *  @brief MCPWM peripheral (MCPWM0 MCPWM1) base address array
 */
extern Reg_Mcpwm_BfType *const Mstp_McpwmRegBfPtr[2U];
extern Reg_Mcpwm_WType *const  Mstp_Mcpwm0RegWPtr;
extern Reg_Mcpwm_WType *const  Mstp_Mcpwm1RegWPtr;

/**
 *  @brief TDG peripheral (TDG0 TDG1) base address array
 */
extern Reg_Tdg_BfType *const Mstp_TdgRegBfPtr[2U];
extern Reg_Tdg_WType *const Mstp_Tdg0RegWPtr;
extern Reg_Tdg_WType *const Mstp_Tdg1RegWPtr;

/**
 *  @brief UART peripheral (UART0 ~ UART5) base address array
 */
extern Reg_Uart_BfType *const Mstp_UartRegBfPtr[6U];

/**
 *  @brief SPI peripheral (SPI0 SPI1 SPI2 SPI3) base address array
 */
extern Reg_Spi_BfType *const Mstp_SpiRegBfPtr[4U];

/**
 *  @brief I2C peripheral base address array
 */
extern Reg_I2c_BfType *const Mstp_I2cRegBfPtr[2U];

#if (defined(DEV_Z20K148M))
/**
 *  @brief CAN peripheral base address array
 */
extern Reg_Can_BfType *const Mstp_CanRegBfPtr[8U]; 

/**
 *  @brief I2S peripheral base address array
 */
extern Reg_I2s_BfType *const Mstp_I2sRegBfPtr[2U];
#elif (defined(DEV_Z20K146M))
/**
 *  @brief CAN peripheral base address array
 */
extern Reg_Can_BfType *const Mstp_CanRegBfPtr[6U]; 

/**
 *  @brief I2S peripheral base address array
 */
extern Reg_I2s_BfType *const Mstp_I2sRegBfPtr[1U];
#elif (defined(DEV_Z20K144M))
/**
 *  @brief CAN peripheral base address array
 */
extern Reg_Can_BfType *const Mstp_CanRegBfPtr[4U]; 

/**
 *  @brief I2S peripheral base address array
 */
extern Reg_I2s_BfType *const Mstp_I2sRegBfPtr[1U];
#else
    #error "No valid CPU defined!"
#endif

/**
 *  @brief ADC peripheral (ADC0 ADC1) base address array
 */
extern Reg_Adc_BfType *const Mstp_AdcRegBfPtr[2U];
extern Reg_Adc_WType *const  Mstp_Adc0RegWPtr;
extern Reg_Adc_BfType *const Mstp_Adc0RegBfPtr;
extern Reg_Adc_WType *const  Mstp_Adc1RegWPtr;

/**
 *  @brief CMP Register
 */
extern Reg_Cmp_BfType *const Mstp_CmpRegBfPtr;
extern Reg_Cmp_WType *const  Mstp_CmpRegWPtr;

/**
 *  @brief AES Register
 */
extern Reg_Aes_BfType *const Mstp_AesRegBfPtr;

/**
 *  @brief TRNG Register
 */
extern Reg_Trng_BfType *const Mstp_TrngRegBfPtr;

/**
 *  @brief DMA Register
 */
extern Reg_Dma_BfType *const Mstp_DmaRegBfPtr;
extern Reg_Dma_WType *const  Mstp_DmaRegWPtr;

/**
 *  @brief DMAMUX Register
 */
extern Reg_Dmamux_BfType *const Mstp_DmamuxRegBfPtr;

/**
 *  @brief PORT Register
 */
extern Reg_Port_BfType *const Mstp_PortRegBfPtr[5U];
extern Reg_Port_WType *const Mstp_PortRegWPtr[5U];
extern Reg_Port_WType *const Mstp_PortARegWPtr;
extern Reg_Port_WType *const Mstp_PortBRegWPtr;
extern Reg_Port_WType *const Mstp_PortCRegWPtr;
extern Reg_Port_WType *const Mstp_PortDRegWPtr;
extern Reg_Port_WType *const Mstp_PortERegWPtr;

/**
 *  @brief TMU Register
 */
extern Reg_Tmu_BfType *const Mstp_TmuRegBfPtr;
extern Reg_Tmu_WType *const  Mstp_TmuRegWPtr;

/**
 *  @brief REGFILE Register
 */
extern Reg_Regfile_BfType *const Mstp_RegfileRegBfPtr;
extern Reg_Regfile_WType *const  Mstp_RegfileRegWPtr;

/**
 *  @brief SMPU Register
 */
extern Reg_Smpu_BfType *const Mstp_SmpuRegBfPtr;
extern Reg_Smpu_WType *const  Mstp_SmpuRegWPtr;

/**
 *  @brief GPIO Register
 */
extern Reg_Gpio_BfType *const Mstp_GpioRegBfPtr;

#define MSTP_STOP_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"

#define MSTP_START_SEC_CONFIG_DATA_8
#include "Mstp_MemMap.h"

/**
* @brief Enable/Disable the default error detection and reporting to the DET.
*
*/
extern const uint8 Mstp_DetFlag;

/**
* @brief RegFile index of store self test result.

*/
extern const uint8 Mstp_SelfTestRetRegFileIdx;

/**
* @brief RegFile index of store self test state.

*/
extern const uint8 Mstp_SelfTestStateRegFileIdx;

#define MSTP_STOP_SEC_CONFIG_DATA_8
#include "Mstp_MemMap.h"

#define MSTP_START_SEC_CONFIG_DATA_32
#include "Mstp_MemMap.h"

/**
* @brief Program flash memory start address and end address.
*/
extern const uint32 Mstp_PFlashStartAddress;
extern const uint32 Mstp_PFlashEndAddress;

/**
* @brief SRAM memory start address and end address.
*/
extern const uint32 Mstp_SramStartAddress;
extern const uint32 Mstp_SramEndAddress;

/**
* @brief Data flash memory start address and end address.
*/
extern const uint32 Mstp_DFlashStartAddress;
extern const uint32 Mstp_DFlashEndAddress;

/**
* @brief Program flash IFR memory start address and end address.
*/
extern const uint32 Mstp_PFlashIFRStartAddress;
extern const uint32 Mstp_PFlashIFREndAddress;

#define MSTP_STOP_SEC_CONFIG_DATA_32
#include "Mstp_MemMap.h"

/**
* @brief RAM test result.
*/
#define MSTP_RAM_TEST_RESULT_EXT \
    extern Mstp_RamTestResultType Mstp_RamTestResult[1U];

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
extern void RamTestCompletedNotification(void);


extern void RamTestErrorNotification(void);


/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Mstp */

/** @} end of group Mstp_Module */

#endif /* MSTP_CFG_H */
