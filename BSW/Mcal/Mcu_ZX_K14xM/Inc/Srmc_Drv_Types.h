/**************************************************************************************************/
/**
 * @file      : Srmc_Drv_Types.h
 * @brief     : SRMC low level driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SRMC_DRV_TYPES_H
#define SRMC_DRV_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Srmc_Drv
 *  @brief SRMC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Srmc_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SRMC_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define SRMC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SRMC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SRMC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SRMC_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define SRMC_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define SRMC_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Srmc_Drv_Cfg.h file are of the same vendor */
#if (SRMC_DRV_TYPES_H_VENDOR_ID != SRMC_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Srmc_Drv_Types.h and Srmc_Drv_Cfg.h are different"
#endif

/* Check if current file and Srmc_Drv_Cfg.h file are of the same Autosar version */
#if ((SRMC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != SRMC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (SRMC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != SRMC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (SRMC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != SRMC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Srmc_Drv_Types.h and Srmc_Drv_Cfg.h are different"
#endif

/* Check if current file and Srmc_Drv_Cfg.h file are of the same Software version */
#if ((SRMC_DRV_TYPES_H_SW_MAJOR_VERSION != SRMC_DRV_CFG_H_SW_MAJOR_VERSION) ||                     \
     (SRMC_DRV_TYPES_H_SW_MINOR_VERSION != SRMC_DRV_CFG_H_SW_MINOR_VERSION) ||                     \
     (SRMC_DRV_TYPES_H_SW_PATCH_VERSION != SRMC_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Srmc_Drv_Types.h and Srmc_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h file are of the same Autosar version */
    #if ((SRMC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||            \
         (SRMC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Srmc_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h file are of the same Autosar version */
    #if ((SRMC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||        \
         (SRMC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Srmc_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define SRMC_DRV_INT_TYPE_LOC_EN  0x00000004U
#define SRMC_DRV_INT_TYPE_LOC_DIS 0x00000000U

#define SRMC_DRV_INT_TYPE_WDOG_EN  0x00000020U
#define SRMC_DRV_INT_TYPE_WDOG_DIS 0x00000000U

#define SRMC_DRV_INT_TYPE_PIN_EN  0x00000040U
#define SRMC_DRV_INT_TYPE_PIN_DIS 0x00000000U

#define SRMC_DRV_INT_TYPE_LOCKUP_EN  0x00000200U
#define SRMC_DRV_INT_TYPE_LOCKUP_DIS 0x00000000U

#define SRMC_DRV_INT_TYPE_SW_EN  0x00000400U
#define SRMC_DRV_INT_TYPE_SW_DIS 0x00000000U

#define SRMC_DRV_INT_TYPE_SERU_COLD_EN  0x00001000U
#define SRMC_DRV_INT_TYPE_SERU_COLD_DIS 0x00000000U

#define SRMC_DRV_INT_TYPE_SERU_SYS_EN  0x00002000U
#define SRMC_DRV_INT_TYPE_SERU_SYS_DIS 0x00000000U

#define SRMC_DRV_INT_TYPE_SACKERR_EN  0x00008000U
#define SRMC_DRV_INT_TYPE_SACKERR_DIS 0x00000000U

/* SRMC RESET by Power-on Detection Logic */
#define SRMC_DRV_RESET_POR 0x00000080U

#define SRMC_DRV_RESET_ALL  0x0000BEE7U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of SRMC reset pin filter.
 *
 */
typedef enum
{
    SRMC_DRV_RESET_PIN_DISABLE_FILTER = 0U, /*!< SRMC RESET Pin filter disabled */
    SRMC_DRV_RESET_PIN_BUS_CLOCK_FILTER,    /*!< SRMC RESET Pin bus clock filter */
    SRMC_DRV_RESET_PIN_LPO_CLOCK_FILTER     /*!< SRMC RESET Pin lpo clock filter */
} Srmc_Drv_ResetPinFilterType;

/**
 *  @brief Type of SRMC delay cycles.
 *
 */
typedef enum
{
    SRMC_DRV_DELAY_8_LPO_CYCLES = 0U, /*!< SRMC delay 8 lpo cycles */
    SRMC_DRV_DELAY_32_LPO_CYCLES,     /*!< SRMC delay 32 lpo cycles */
    SRMC_DRV_DELAY_128_LPO_CYCLES,    /*!< SRMC delay 128 lpo cycles */
    SRMC_DRV_DELAY_512_LPO_CYCLES     /*!< SRMC delay 512 lpo cycles */
} Srmc_Drv_DelayType;

/**
 *  @brief Type of SRMC MCU power mode.
 *
 */
typedef enum
{
    SRMC_DRV_MODE_RUN = 0U, /*!< SRMC run mode */
    SRMC_DRV_MODE_WAIT,     /*!< SRMC wait mode */
    SRMC_DRV_MODE_STOP,     /*!< SRMC stop mode */
    SRMC_DRV_MODE_STANDBY   /*!< SRMC standby mode */
} Srmc_Drv_PowerModeType;

/**
 *  @brief Type of SRMC wakeup source.
 *
 */
typedef enum
{
    SRMC_DRV_WUPSRC_PTD0 = 0x0U,  /*!< SRMC wakeup source: PTD0 pin */
    SRMC_DRV_WUPSRC_PTD1 = 0x1U,  /*!< SRMC wakeup source: PTD1 pin */
    SRMC_DRV_WUPSRC_PTA4 = 0x2U,  /*!< SRMC wakeup source: PTA4 pin */
    SRMC_DRV_WUPSRC_PTC4 = 0x4U,  /*!< SRMC wakeup source: PTC4 pin */
    SRMC_DRV_WUPSRC_PTC5 = 0x5U,  /*!< SRMC wakeup source: PTC5 pin */
    SRMC_DRV_WUPSRC_PTE0 = 0x6U,  /*!< SRMC wakeup source: PTE0 pin */
    SRMC_DRV_WUPSRC_PTE1 = 0x7U,  /*!< SRMC wakeup source: PTE1 pin */
    SRMC_DRV_WUPSRC_PTE11 = 0x8U, /*!< SRMC wakeup source: PTE11 pin */
    SRMC_DRV_WUPSRC_PTE13 = 0x9U, /*!< SRMC wakeup source: PTE13 pin */
    SRMC_DRV_WUPSRC_PTE15 = 0xAU, /*!< SRMC wakeup source: PTE15 pin */
    SRMC_DRV_WUPSRC_PTE16 = 0xBU, /*!< SRMC wakeup source: PTE16 pin */
    SRMC_DRV_WUPSRC_PTA8 = 0xCU,  /*!< SRMC wakeup source: PTA8 pin */
    SRMC_DRV_WUPSRC_PTA9 = 0xDU,  /*!< SRMC wakeup source: PTA9 pin */
    SRMC_DRV_WUPSRC_PTA25 = 0xEU, /*!< SRMC wakeup source: PTA25 pin */
    SRMC_DRV_WUPSRC_PMU = 0xFU,   /*!< SRMC wakeup source: PMU */
    SRMC_DRV_WUPSRC_RTC = 0x10U   /*!< SRMC wakeup source: RTC */
} Srmc_Drv_WakeupSourceType;

/**
 *  @brief Type of SRMC wakeup source polarity.
 *
 */
typedef enum
{
    SRMC_DRV_WUPSRC_POLARITY_LOW = 0x0U, /*!< SRMC wakeup source polarity: active low */
    SRMC_DRV_WUPSRC_POLARITY_HIGH = 0x1U /*!< SRMC wakeup source polarity: active high */
} Srmc_Drv_WupPolarityType;

/* SRMC Reset Interrupt Enable Mask define */
#define SRMC_DRV_INTERRUPT_ENABLE_MASK ((uint32)0x0000B664U)
/* SRMC Reset Cause Mask define */
#define SRMC_DRV_RESET_CAUSE_MASK ((uint32)0x0000BEE7U)

#define SRMC_DRV_ALLOW_STANDBY_MASK ((uint32)0x00000001U)

#define SRMC_DRV_DSMWUPC1_EN_MASK32 ((uint32)0x0000FFF7U)
#define SRMC_DRV_DSMWUPC1_EN(source)                                                               \
    ((uint32)(((uint32)(((uint32)0x00000001U) << (source))) & SRMC_DRV_DSMWUPC1_EN_MASK32))

#define SRMC_DRV_DSMWUPC1_PL_MASK32      ((uint32)0x7FF70000U)
#define SRMC_DRV_DSMWUPC1_PL_LOW(source) ((uint32)0x00000000U)
#define SRMC_DRV_DSMWUPC1_PL_HIGH(source)                                                          \
    ((uint32)(((uint32)(((uint32)0x00010000U) << (source))) & SRMC_DRV_DSMWUPC1_PL_MASK32))

/* WUPSRC_EN2_0 */
#define SRMC_DRV_WUPSRC_PTD0_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTD0))
#define SRMC_DRV_WUPSRC_PTD0_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTD1_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTD1))
#define SRMC_DRV_WUPSRC_PTD1_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTA4_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTA4))
#define SRMC_DRV_WUPSRC_PTA4_DIS ((uint32)0x00000000U)

/* WUPSRC_EN15_4 */
#define SRMC_DRV_WUPSRC_PTC4_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTC4))
#define SRMC_DRV_WUPSRC_PTC4_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTC5_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTC5))
#define SRMC_DRV_WUPSRC_PTC5_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTE0_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTE0))
#define SRMC_DRV_WUPSRC_PTE0_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTE1_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTE1))
#define SRMC_DRV_WUPSRC_PTE1_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTE11_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTE11))
#define SRMC_DRV_WUPSRC_PTE11_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTE13_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTE13))
#define SRMC_DRV_WUPSRC_PTE13_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTE15_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTE15))
#define SRMC_DRV_WUPSRC_PTE15_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTE16_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTE16))
#define SRMC_DRV_WUPSRC_PTE16_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTA8_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTA8))
#define SRMC_DRV_WUPSRC_PTA8_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTA9_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTA9))
#define SRMC_DRV_WUPSRC_PTA9_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PTA25_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PTA25))
#define SRMC_DRV_WUPSRC_PTA25_DIS ((uint32)0x00000000U)

#define SRMC_DRV_WUPSRC_PMU_EN  (SRMC_DRV_DSMWUPC1_EN((uint32)SRMC_DRV_WUPSRC_PMU))
#define SRMC_DRV_WUPSRC_PMU_DIS ((uint32)0x00000000U)

/* WUPSRC_PL2_0 */
#define SRMC_DRV_WUPSRC_PTD0_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTD0))
#define SRMC_DRV_WUPSRC_PTD0_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTD0))

#define SRMC_DRV_WUPSRC_PTD1_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTD1))
#define SRMC_DRV_WUPSRC_PTD1_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTD1))

#define SRMC_DRV_WUPSRC_PTA4_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTA4))
#define SRMC_DRV_WUPSRC_PTA4_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTA4))

/* WUPSRC_PL14_4 */
#define SRMC_DRV_WUPSRC_PTC4_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTC4))
#define SRMC_DRV_WUPSRC_PTC4_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTC4))

#define SRMC_DRV_WUPSRC_PTC5_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTC5))
#define SRMC_DRV_WUPSRC_PTC5_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTC5))

#define SRMC_DRV_WUPSRC_PTE0_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTE0))
#define SRMC_DRV_WUPSRC_PTE0_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTE0))

#define SRMC_DRV_WUPSRC_PTE1_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTE1))
#define SRMC_DRV_WUPSRC_PTE1_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTE1))

#define SRMC_DRV_WUPSRC_PTE11_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTE11))
#define SRMC_DRV_WUPSRC_PTE11_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTE11))

#define SRMC_DRV_WUPSRC_PTE13_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTE13))
#define SRMC_DRV_WUPSRC_PTE13_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTE13))

#define SRMC_DRV_WUPSRC_PTE15_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTE15))
#define SRMC_DRV_WUPSRC_PTE15_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTE15))

#define SRMC_DRV_WUPSRC_PTE16_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTE16))
#define SRMC_DRV_WUPSRC_PTE16_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTE16))

#define SRMC_DRV_WUPSRC_PTA8_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTA8))
#define SRMC_DRV_WUPSRC_PTA8_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTA8))

#define SRMC_DRV_WUPSRC_PTA9_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTA9))
#define SRMC_DRV_WUPSRC_PTA9_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTA9))

#define SRMC_DRV_WUPSRC_PTA25_HIGH (SRMC_DRV_DSMWUPC1_PL_HIGH((uint32)SRMC_DRV_WUPSRC_PTA25))
#define SRMC_DRV_WUPSRC_PTA25_LOW  (SRMC_DRV_DSMWUPC1_PL_LOW((uint32)SRMC_DRV_WUPSRC_PTA25))

#define SRMC_DRV_WUPSRC_RTC_EN  ((uint32)0x00000001U)
#define SRMC_DRV_WUPSRC_RTC_DIS ((uint32)0x00000000U)

/**
 *  @brief Type of SRMC reset configuration.
 *
 */
typedef struct
{
    Srmc_Drv_ResetPinFilterType ResetPinFilterInNormal;
    Srmc_Drv_ResetPinFilterType ResetPinFilterInStop;
    uint32                      ResetPinFilterBusClock;
    boolean                     CoreLockupResetEnable;
    Srmc_Drv_DelayType          ResetDelayTime;
    uint32                      ResetInterruptEnable;
} Srmc_Drv_ResetConfigType;

/**
 *  @brief Type of SRMC power mode configuration.
 */
typedef struct
{
    boolean AllowStandbyMode;   /*!< Allow standby mode config */
    uint32  StopModeAckTimeout; /*!< Stop mode acknowledge config */
    uint32  WakeupControl1;     /*!< Standby Wakeup control 1 */
    uint32  WakeupControl2;     /*!< Standby Wakeup control 2 */
} Srmc_Drv_PowerModeConfigType;

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

/** @} end of group Srmc_Drv */

/** @} end of group Mcu_Module */

#endif /* SRMC_DRV_TYPES_H */
