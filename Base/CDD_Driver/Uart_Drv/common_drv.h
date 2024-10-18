/**************************************************************************************************/
/**
 * @file     common_drv.h
 * @brief    Drv common module header file.
 * @version  V1.0.0
 * @date     December-2022
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef COMMON_DRV_H
#define COMMON_DRV_H

#include "Device_Regs.h"
#include "McalLib.h"

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */

/** @addtogroup  COMMON_DRV
 *  @{
 */

/** @defgroup COMMON_Public_Types
 *  @brief DRV type definition
 *  @{
 */

/** 
 * @brief Core Configuration
 */
#define CM4_REV                 0x0001U /*!< core version */
#define FPU_PRESENT             1U      /*!< FPU present or not*/
#define INT_PRIO_BITS           4U      /*!< Number of Bits used for Priority Levels */

/** 
 * @brief Compiler ramsection configuration
 */
#if defined ( __ICCARM__ )
    #define START_FUNCTION_DECLARATION_RAMSECTION      __ramfunc
    #define END_FUNCTION_DECLARATION_RAMSECTION     ;
#elif defined  (__ARMCC_VERSION)
    #define START_FUNCTION_DECLARATION_RAMSECTION
    #define END_FUNCTION_DECLARATION_RAMSECTION        __attribute__((section (".code_ram")));
#elif defined (__GNUC__)
    #define START_FUNCTION_DECLARATION_RAMSECTION
    #define END_FUNCTION_DECLARATION_RAMSECTION        __attribute__((section (".code_ram")));
#elif defined ( __ghs__ )
    #define START_FUNCTION_DECLARATION_RAMSECTION      _Pragma("ghs callmode=far")
    #define END_FUNCTION_DECLARATION_RAMSECTION        __attribute__((section (".code_ram")));\
                                                       _Pragma("ghs callmode=default")
#else 
     #define START_FUNCTION_DECLARATION_RAMSECTION
     #define END_FUNCTION_DECLARATION_RAMSECTION        ;
#endif
     
#if defined (__ICCARM__)
    #define DISABLE_CHECK_RAMSECTION_FUNCTION_CALL     _Pragma("diag_suppress=Ta022")
    #define ENABLE_CHECK_RAMSECTION_FUNCTION_CALL      _Pragma("diag_default=Ta022")
#else
    #define DISABLE_CHECK_RAMSECTION_FUNCTION_CALL
    #define ENABLE_CHECK_RAMSECTION_FUNCTION_CALL
#endif

/**
 * @brief Core register mask
 */
#define SCB_SCR_SLEEPDEEP_POS               2U                                            /*!< SCB SCR: SLEEPDEEP Position */
#define SCB_SCR_SLEEPDEEP_MASK              (1UL << SCB_SCR_SLEEPDEEP_POS)                 /*!< SCB SCR: SLEEPDEEP Mask */

/**
 * @brief Control State Type Definition
 */
typedef enum
{
    DISABLE  = 0U,
    ENABLE   = 1U
}ControlState_t;

/**
 * @brief Result status Type definition
 */
typedef enum
{
    SUCC = 0U,
    ERR = 1U,
    BUSY = 2U
}ResultStatus_t;

/**
 * @brief Flag/Int status Type definition
 */
typedef enum
{
    RESET = 0U,
    SET = 1U
}FlagStatus_t, IntStatus_t;

/**
 * @brief interrupt mask Type definition
 */
typedef enum
{
    UNMASK = 0U,
    MASK = 1U
}IntMask_t;

/**
 * @brief level Type definition
 */
typedef enum
{
    LEVEL_LOW = 0U,
    LEVEL_HIGH = 1U
}Level_t;


/**
 *  @brief ISR callback function type
 */
typedef void (isr_cb_t)(void);


/** @} end of group COMMON_Public_Types */


/** @defgroup COMMON_Public_Constants
 *  @{
 */

/** @defgroup COMMON_ISR_INDEX
 *  @{
 */
#define IS_ISR_INDEX(INDEX)     ((INDEX) < ISR_INDEX_NUM)
/** @} end of group COMMON_INT_PERIPH */

/** @defgroup COMMON_INT_MASK
 *  @{
 */
#define IS_INTMASK(INTMASK)     (((INTMASK) == MASK) || ((INTMASK) == UNMASK))
/** @} end of group COMMON_INT_MASK */

/** @} end of group COMMON_Public_Constants */

/** @defgroup COMMON_Public_Macro
 *  @{
 */

/** @} end of group COMMON_Public_Macro */

/** @defgroup COMMON_Public_FunctionDeclaration
 *  @brief DRV functions declaration
 *  @{
 */
#define COMMON_DSB()   __asm("dsb")

#define COMMON_ISB()   __asm("isb")

#define COMMON_DMB()   __asm("dmb")

#define COMMON_NOP()   __asm ("nop")

#define COMMON_DISABLE_INTERRUPTS()    __asm("cpsid i")

#define COMMON_ENABLE_INTERRUPTS()     __asm("cpsie i")

#define COMMON_WFI()   __asm("wfi")

#define COMMON_WFE()   __asm("wfe")

/**
 * @brief      Convert 4 byte into a word. The first byte is the lowest byte in 
 *             the word(little end).
 *
 * @param[in]  bytes: it points to an array with 4 bytes.
 *
 * @return     None
 *
 */
uint32 COMMON_BytesToWord(uint8 bytes[4]);

/**
 * @brief      Delay for some cycles
 *
 * @param[in]  delayCount: the cycles to delay
 *
 * @return     None
 *
 */


/* #if( COMMON_DELAY_FUNC_IN_RAM == 1) */
#if 1
START_FUNCTION_DECLARATION_RAMSECTION
void COMMON_Delay(unsigned int delayCount)
END_FUNCTION_DECLARATION_RAMSECTION
#else
void COMMON_Delay(uint32 delayCount);
#endif

/**
 * @brief      System Reset.
 * @param[in]  None.
 * @return     None.
 */
void COMMON_SystemReset(void);

/**
 * @brief      Config Priviliege Mode in CONTROL register.
 * @param[in]  mode: 
 *             0:   privileged
 *             1:   unprivileged
 * @return     None.
 */
void COMMON_SetControl(uint8 mode);
/** @} end of group COMMON_Public_FunctionDeclaration */

/** @} end of group COMMON_DRV  */

/** @} end of group Z20K14XM_Peripheral_Driver */

#endif /* COMMON_DRV_H */
