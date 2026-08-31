/******************************************************************************
 * @file     cachel1_armv7.h
 * @brief    CMSIS Level 1 Cache API for Armv7-M and later
 * @version  V2.3.0
 * @date     19. April 2021
 ******************************************************************************/
/*
 * Copyright (c) 2020-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* PRQA S 0602,0603,0306,0883 EOF */

#if   defined ( __ICCARM__ )
#pragma system_include         /* treat file as system include file for MISRA check */
#elif defined (__clang__)
#pragma clang system_header    /* treat file as system include file */
#endif

#ifndef ARM_CACHEL1_ARMV7_H
#define ARM_CACHEL1_ARMV7_H

/*
* @page misra_violations MISRA-C:2012 violations list
* PRQA S 4446 Rule 10.3: The value of an expression shall not be assigned to an object with a narrower
*                        essential type or of a different essential type category.
* PRQA S 3673 Rule 8.13: A pointer should point to a const-qualified type whenever possible.
* PRQA S 3440 Rule 13.3: A full expression containing an increment (++) or decrement (--) operator should
*                        have no other potential side effects other than that caused by the increment or decrement operator
* PRQA S 3344 Rule 14.4: The controlling expression of an if-statement and the controlling expression
*                        of an iteration-statement shall have essentially Boolean type
* PRQA S 1820 Rule 10.4: Both operands of an operator in which the usual arithmetic conversions are performed
*                        shall have the same essential type category
* PRQA S 0326 Rule 11.6: A cast shall not be performed between pointer to void and an arithmetic type
*/
/* MR12 RULE 10.3/8.13/13.3/14.4/10.4/11.6 VIOLATION: This cache API is designed to provide
*                            control and configuration access to the cache. They are widely used and verified
*                            with no any potential side effects and risks.
*/
/* PRQA S 4446, 3673, 3440, 3344, 1820, 0326 EOF */

/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_CacheFunctions Cache Functions
  \brief    Functions that configure Instruction and Data cache.
  @{
 */

/* Cache Size ID Register Macros */
#define CCSIDR_WAYS(x)         (((x) & SCB_CCSIDR_ASSOCIATIVITY_Msk) >> SCB_CCSIDR_ASSOCIATIVITY_Pos)
#define CCSIDR_SETS(x)         (((x) & SCB_CCSIDR_NUMSETS_Msk      ) >> SCB_CCSIDR_NUMSETS_Pos      )

#ifndef __SCB_DCACHE_LINE_SIZE
#define __SCB_DCACHE_LINE_SIZE  32U /*!< Cortex-M7 cache line size is fixed to 32 bytes (8 words). See also register SCB_CCSIDR */
#endif

#ifndef __SCB_ICACHE_LINE_SIZE
#define __SCB_ICACHE_LINE_SIZE  32U /*!< Cortex-M7 cache line size is fixed to 32 bytes (8 words). See also register SCB_CCSIDR */
#endif

/**
  \brief   Enable I-Cache
  \details Turns on I-Cache
  */
__STATIC_FORCEINLINE void SCB_EnableICache(void)
{
#if defined (__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    if (SCB->CCR & SCB_CCR_IC_Msk)
    {
        return;    /* return if ICache is already enabled */
    }
    __DSB();
    __ISB();
    SCB->ICIALLU = 0UL;                     /* invalidate I-Cache */
    __DSB();
    __ISB();
    SCB->CCR |= (uint32)SCB_CCR_IC_Msk;   /* enable I-Cache */
    __DSB();
    __ISB();
#endif
}


/**
  \brief   Disable I-Cache
  \details Turns off I-Cache
  */
__STATIC_FORCEINLINE void SCB_DisableICache(void)
{
#if defined (__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    __DSB();
    __ISB();
    SCB->CCR &= ~(uint32)SCB_CCR_IC_Msk;  /* disable I-Cache */
    SCB->ICIALLU = 0UL;                     /* invalidate I-Cache */
    __DSB();
    __ISB();
#endif
}


/**
  \brief   Invalidate I-Cache
  \details Invalidates I-Cache
  */
__STATIC_FORCEINLINE void SCB_InvalidateICache(void)
{
#if defined (__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    __DSB();
    __ISB();
    SCB->ICIALLU = 0UL;
    __DSB();
    __ISB();
#endif
}


/**
  \brief   I-Cache Invalidate by address
  \details Invalidates I-Cache for the given address.
           I-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
           I-Cache memory blocks which are part of given address + given size are invalidated.
  \param[in]   addr    address
  \param[in]   isize   size of memory block (in number of bytes)
*/
__STATIC_FORCEINLINE void SCB_InvalidateICache_by_Addr(volatile void *addr, sint32 isize)
{
#if defined (__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    if (isize > 0)
    {
        sint32 op_size = isize + (((uint32)addr) & (__SCB_ICACHE_LINE_SIZE - 1U));
        uint32 op_addr = (uint32)addr /* & ~(__SCB_ICACHE_LINE_SIZE - 1U) */;
        __DSB();
        do
        {
            SCB->ICIMVAU = op_addr;             /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            op_addr += __SCB_ICACHE_LINE_SIZE;
            op_size -= __SCB_ICACHE_LINE_SIZE;
        } while (op_size > 0);
        __DSB();
        __ISB();
    }
#endif
}


/**
  \brief   Enable D-Cache
  \details Turns on D-Cache
  */
__STATIC_FORCEINLINE void SCB_EnableDCache(void)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    uint32 ccsidr;
    uint32 sets;
    uint32 ways;
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        return;    /* return if DCache is already enabled */
    }
    SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    __DSB();
    ccsidr = SCB->CCSIDR;
    /* invalidate D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        do
        {
            SCB->DCISW = (((sets << SCB_DCISW_SET_Pos) & SCB_DCISW_SET_Msk) |
                          ((ways << SCB_DCISW_WAY_Pos) & SCB_DCISW_WAY_Msk));
#if defined ( __CC_ARM )
            __schedule_barrier();
#endif
        } while (ways-- != 0U);
    } while (sets-- != 0U);
    __DSB();
    SCB->CCR |= (uint32)SCB_CCR_DC_Msk;   /* enable D-Cache */
    __DSB();
    __ISB();
#endif
}


/**
  \brief   Disable D-Cache
  \details Turns off D-Cache
  */
__STATIC_FORCEINLINE void SCB_DisableDCache(void)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    uint32 ccsidr;
    uint32 sets;
    uint32 ways;
    SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    __DSB();
    SCB->CCR &= ~(uint32)SCB_CCR_DC_Msk;  /* disable D-Cache */
    __DSB();
    ccsidr = SCB->CCSIDR;
    /* clean & invalidate D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        do
        {
            SCB->DCCISW = (((sets << SCB_DCCISW_SET_Pos) & SCB_DCCISW_SET_Msk) |
                           ((ways << SCB_DCCISW_WAY_Pos) & SCB_DCCISW_WAY_Msk));
#if defined ( __CC_ARM )
            __schedule_barrier();
#endif
        } while (ways-- != 0U);
    } while (sets-- != 0U);
    __DSB();
    __ISB();
#endif
}


/**
  \brief   Invalidate D-Cache
  \details Invalidates D-Cache
  */
__STATIC_FORCEINLINE void SCB_InvalidateDCache(void)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    uint32 ccsidr;
    uint32 sets;
    uint32 ways;
    SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    __DSB();
    ccsidr = SCB->CCSIDR;
    /* invalidate D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        do
        {
            SCB->DCISW = (((sets << SCB_DCISW_SET_Pos) & SCB_DCISW_SET_Msk) |
                          ((ways << SCB_DCISW_WAY_Pos) & SCB_DCISW_WAY_Msk));
#if defined ( __CC_ARM )
            __schedule_barrier();
#endif
        } while (ways-- != 0U);
    } while (sets-- != 0U);
    __DSB();
    __ISB();
#endif
}


/**
  \brief   Clean D-Cache
  \details Cleans D-Cache
  */
__STATIC_FORCEINLINE void SCB_CleanDCache(void)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    uint32 ccsidr;
    uint32 sets;
    uint32 ways;
    SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    __DSB();
    ccsidr = SCB->CCSIDR;
    /* clean D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        do
        {
            SCB->DCCSW = (((sets << SCB_DCCSW_SET_Pos) & SCB_DCCSW_SET_Msk) |
                          ((ways << SCB_DCCSW_WAY_Pos) & SCB_DCCSW_WAY_Msk));
#if defined ( __CC_ARM )
            __schedule_barrier();
#endif
        } while (ways-- != 0U);
    } while (sets-- != 0U);
    __DSB();
    __ISB();
#endif
}


/**
  \brief   Clean & Invalidate D-Cache
  \details Cleans and Invalidates D-Cache
  */
__STATIC_FORCEINLINE void SCB_CleanInvalidateDCache(void)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    uint32 ccsidr;
    uint32 sets;
    uint32 ways;
    SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    __DSB();
    ccsidr = SCB->CCSIDR;
    /* clean & invalidate D-Cache */
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do
    {
        ways = (uint32)(CCSIDR_WAYS(ccsidr));
        do
        {
            SCB->DCCISW = (((sets << SCB_DCCISW_SET_Pos) & SCB_DCCISW_SET_Msk) |
                           ((ways << SCB_DCCISW_WAY_Pos) & SCB_DCCISW_WAY_Msk));
#if defined ( __CC_ARM )
            __schedule_barrier();
#endif
        } while (ways-- != 0U);
    } while (sets-- != 0U);
    __DSB();
    __ISB();
#endif
}


/**
  \brief   D-Cache Invalidate by address
  \details Invalidates D-Cache for the given address.
           D-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
           D-Cache memory blocks which are part of given address + given size are invalidated.
  \param[in]   addr    address
  \param[in]   dsize   size of memory block (in number of bytes)
*/
__STATIC_FORCEINLINE void SCB_InvalidateDCache_by_Addr(volatile void *addr, sint32 dsize)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    if (dsize > 0)
    {
        sint32 op_size = dsize + (((uint32)addr) & (__SCB_DCACHE_LINE_SIZE - 1U));
        uint32 op_addr = (uint32)addr /* & ~(__SCB_DCACHE_LINE_SIZE - 1U) */;
        __DSB();
        do
        {
            SCB->DCIMVAC = op_addr;             /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            op_addr += __SCB_DCACHE_LINE_SIZE;
            op_size -= __SCB_DCACHE_LINE_SIZE;
        } while (op_size > 0);
        __DSB();
        __ISB();
    }
#endif
}


/**
  \brief   D-Cache Clean by address
  \details Cleans D-Cache for the given address
           D-Cache is cleaned starting from a 32 byte aligned address in 32 byte granularity.
           D-Cache memory blocks which are part of given address + given size are cleaned.
  \param[in]   addr    address
  \param[in]   dsize   size of memory block (in number of bytes)
*/
__STATIC_FORCEINLINE void SCB_CleanDCache_by_Addr(volatile void *addr, sint32 dsize)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    if (dsize > 0)
    {
        sint32 op_size = dsize + (((uint32)addr) & (__SCB_DCACHE_LINE_SIZE - 1U));
        uint32 op_addr = (uint32)addr /* & ~(__SCB_DCACHE_LINE_SIZE - 1U) */;
        __DSB();
        do
        {
            SCB->DCCMVAC = op_addr;             /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            op_addr += __SCB_DCACHE_LINE_SIZE;
            op_size -= __SCB_DCACHE_LINE_SIZE;
        } while (op_size > 0);
        __DSB();
        __ISB();
    }
#endif
}


/**
  \brief   D-Cache Clean and Invalidate by address
  \details Cleans and invalidates D_Cache for the given address
           D-Cache is cleaned and invalidated starting from a 32 byte aligned address in 32 byte granularity.
           D-Cache memory blocks which are part of given address + given size are cleaned and invalidated.
  \param[in]   addr    address (aligned to 32-byte boundary)
  \param[in]   dsize   size of memory block (in number of bytes)
*/
__STATIC_FORCEINLINE void SCB_CleanInvalidateDCache_by_Addr(volatile void *addr, sint32 dsize)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    if (dsize > 0)
    {
        sint32 op_size = dsize + (((uint32)addr) & (__SCB_DCACHE_LINE_SIZE - 1U));
        uint32 op_addr = (uint32)addr /* & ~(__SCB_DCACHE_LINE_SIZE - 1U) */;
        __DSB();
        do
        {
            SCB->DCCIMVAC = op_addr;            /* register accepts only 32byte aligned values, only bits 31..5 are valid */
            op_addr +=          __SCB_DCACHE_LINE_SIZE;
            op_size -=          __SCB_DCACHE_LINE_SIZE;
        } while (op_size > 0);
        __DSB();
        __ISB();
    }
#endif
}

/*@} end of CMSIS_Core_CacheFunctions */

#endif /* ARM_CACHEL1_ARMV7_H */

