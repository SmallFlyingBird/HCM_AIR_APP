/**************************************************************************//**
 * @file     cmsis_iccarm.h
 * @brief    CMSIS compiler ICCARM (IAR Compiler for Arm) header file
 * @version  V2.3.0
 * @date     14. April 2021
 ******************************************************************************/

//------------------------------------------------------------------------------
//
// Copyright (c) 2017-2021 IAR Systems
// Copyright (c) 2017-2021 Arm Limited. All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//------------------------------------------------------------------------------


#ifndef __CMSIS_ICCARM_H__
#define __CMSIS_ICCARM_H__

#ifndef __ICCARM__
  #error This file should only be compiled by ICCARM
#endif

#pragma system_include

#define __IAR_FT _Pragma("inline=forced") __intrinsic

#if (__VER__ >= 8000000)
  #define __ICCARM_V8 1
#else
  #define __ICCARM_V8 0
#endif

#ifndef __ALIGNED
  #if __ICCARM_V8
    #define __ALIGNED(x) __attribute__((aligned(x)))
  #elif (__VER__ >= 7080000)
    /* Needs IAR language extensions */
    #define __ALIGNED(x) __attribute__((aligned(x)))
  #else
    #warning No compiler specific solution for __ALIGNED.__ALIGNED is ignored.
    #define __ALIGNED(x)
  #endif
#endif


/* Define compiler macros for CPU architecture, used in CMSIS 5.
 */
#if __ARM_ARCH_6M__ || __ARM_ARCH_7M__ || __ARM_ARCH_7EM__ || __ARM_ARCH_8M_BASE__ || __ARM_ARCH_8M_MAIN__
/* Macros already defined */
#else
  #if defined(__ARM8M_MAINLINE__) || defined(__ARM8EM_MAINLINE__)
    #define __ARM_ARCH_8M_MAIN__ 1
  #elif defined(__ARM8M_BASELINE__)
    #define __ARM_ARCH_8M_BASE__ 1
  #elif defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M'
    #if __ARM_ARCH == 6
      #define __ARM_ARCH_6M__ 1
    #elif __ARM_ARCH == 7
      #if __ARM_FEATURE_DSP
        #define __ARM_ARCH_7EM__ 1
      #else
        #define __ARM_ARCH_7M__ 1
      #endif
    #endif /* __ARM_ARCH */
  #endif /* __ARM_ARCH_PROFILE == 'M' */
#endif

/* Alternativ core deduction for older ICCARM's */
#if !defined(__ARM_ARCH_6M__) && !defined(__ARM_ARCH_7M__) && !defined(__ARM_ARCH_7EM__) && \
    !defined(__ARM_ARCH_8M_BASE__) && !defined(__ARM_ARCH_8M_MAIN__)
  #if defined(__ARM6M__) && (__CORE__ == __ARM6M__)
    #define __ARM_ARCH_6M__ 1
  #elif defined(__ARM7M__) && (__CORE__ == __ARM7M__)
    #define __ARM_ARCH_7M__ 1
  #elif defined(__ARM7EM__) && (__CORE__ == __ARM7EM__)
    #define __ARM_ARCH_7EM__  1
  #elif defined(__ARM8M_BASELINE__) && (__CORE == __ARM8M_BASELINE__)
    #define __ARM_ARCH_8M_BASE__ 1
  #elif defined(__ARM8M_MAINLINE__) && (__CORE == __ARM8M_MAINLINE__)
    #define __ARM_ARCH_8M_MAIN__ 1
  #elif defined(__ARM8EM_MAINLINE__) && (__CORE == __ARM8EM_MAINLINE__)
    #define __ARM_ARCH_8M_MAIN__ 1
  #else
    #error "Unknown target."
  #endif
#endif



#if defined(__ARM_ARCH_6M__) && __ARM_ARCH_6M__==1
  #define __IAR_M0_FAMILY  1
#elif defined(__ARM_ARCH_8M_BASE__) && __ARM_ARCH_8M_BASE__==1
  #define __IAR_M0_FAMILY  1
#else
  #define __IAR_M0_FAMILY  0
#endif


#ifndef __ASM
  #define __ASM __asm
#endif

#ifndef   __COMPILER_BARRIER
  #define __COMPILER_BARRIER() __ASM volatile("":::"memory")
#endif

#ifndef __INLINE
  #define __INLINE inline
#endif

#ifndef   __NO_RETURN
  #if __ICCARM_V8
    #define __NO_RETURN __attribute__((__noreturn__))
  #else
    #define __NO_RETURN _Pragma("object_attribute=__noreturn")
  #endif
#endif

#ifndef   __PACKED
  #if __ICCARM_V8
    #define __PACKED __attribute__((packed, aligned(1)))
  #else
    /* Needs IAR language extensions */
    #define __PACKED __packed
  #endif
#endif

#ifndef   __PACKED_STRUCT
  #if __ICCARM_V8
    #define __PACKED_STRUCT struct __attribute__((packed, aligned(1)))
  #else
    /* Needs IAR language extensions */
    #define __PACKED_STRUCT __packed struct
  #endif
#endif

#ifndef   __PACKED_UNION
  #if __ICCARM_V8
    #define __PACKED_UNION union __attribute__((packed, aligned(1)))
  #else
    /* Needs IAR language extensions */
    #define __PACKED_UNION __packed union
  #endif
#endif

#ifndef   __RESTRICT
  #if __ICCARM_V8
    #define __RESTRICT            __restrict
  #else
    /* Needs IAR language extensions */
    #define __RESTRICT            restrict
  #endif
#endif

#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE       static inline
#endif

#ifndef   __FORCEINLINE
  #define __FORCEINLINE         _Pragma("inline=forced")
#endif

#ifndef   __STATIC_FORCEINLINE
  #define __STATIC_FORCEINLINE  __FORCEINLINE __STATIC_INLINE
#endif

#ifndef __UNALIGNED_UINT16_READ
#pragma language=save
#pragma language=extended
__IAR_FT uint16 __iar_uint16_read(void const *ptr)
{
  return *(__packed uint16*)(ptr);
}
#pragma language=restore
#define __UNALIGNED_UINT16_READ(PTR) __iar_uint16_read(PTR)
#endif


#ifndef __UNALIGNED_UINT16_WRITE
#pragma language=save
#pragma language=extended
__IAR_FT void __iar_uint16_write(void const *ptr, uint16 val)
{
  *(__packed uint16*)(ptr) = val;;
}
#pragma language=restore
#define __UNALIGNED_UINT16_WRITE(PTR,VAL) __iar_uint16_write(PTR,VAL)
#endif

#ifndef __UNALIGNED_UINT32_READ
#pragma language=save
#pragma language=extended
__IAR_FT uint32 __iar_uint32_read(void const *ptr)
{
  return *(__packed uint32*)(ptr);
}
#pragma language=restore
#define __UNALIGNED_UINT32_READ(PTR) __iar_uint32_read(PTR)
#endif

#ifndef __UNALIGNED_UINT32_WRITE
#pragma language=save
#pragma language=extended
__IAR_FT void __iar_uint32_write(void const *ptr, uint32 val)
{
  *(__packed uint32*)(ptr) = val;;
}
#pragma language=restore
#define __UNALIGNED_UINT32_WRITE(PTR,VAL) __iar_uint32_write(PTR,VAL)
#endif

#ifndef __UNALIGNED_UINT32   /* deprecated */
#pragma language=save
#pragma language=extended
__packed struct  __iar_u32 { uint32 v; };
#pragma language=restore
#define __UNALIGNED_UINT32(PTR) (((struct __iar_u32 *)(PTR))->v)
#endif

#ifndef   __USED
  #if __ICCARM_V8
    #define __USED __attribute__((used))
  #else
    #define __USED _Pragma("__root")
  #endif
#endif

#undef __WEAK                           /* undo the definition from DLib_Defaults.h */
#ifndef   __WEAK
  #if __ICCARM_V8
    #define __WEAK __attribute__((weak))
  #else
    #define __WEAK _Pragma("__weak")
  #endif
#endif

#ifndef __PROGRAM_START
#define __PROGRAM_START           __iar_program_start
#endif

#ifndef __INITIAL_SP
#define __INITIAL_SP              CSTACK$$Limit
#endif

#ifndef __STACK_LIMIT
#define __STACK_LIMIT             CSTACK$$Base
#endif

#ifndef __VECTOR_TABLE
#define __VECTOR_TABLE            __vector_table
#endif

#ifndef __VECTOR_TABLE_ATTRIBUTE
#define __VECTOR_TABLE_ATTRIBUTE  @".intvec"
#endif

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#ifndef __STACK_SEAL
#define __STACK_SEAL              STACKSEAL$$Base
#endif

#ifndef __TZ_STACK_SEAL_SIZE
#define __TZ_STACK_SEAL_SIZE      8U
#endif

#ifndef __TZ_STACK_SEAL_VALUE
#define __TZ_STACK_SEAL_VALUE     0xFEF5EDA5FEF5EDA5ULL
#endif

__STATIC_FORCEINLINE void __TZ_set_STACKSEAL_S (uint32* stackTop) {
  *((uint64 *)stackTop) = __TZ_STACK_SEAL_VALUE;
}
#endif

#ifndef __ICCARM_INTRINSICS_VERSION__
  #define __ICCARM_INTRINSICS_VERSION__  0
#endif

#if __ICCARM_INTRINSICS_VERSION__ == 2

  #include "iccarm_builtin.h"

  #define __disable_fault_irq __iar_builtin_disable_fiq
  #define __disable_irq       __iar_builtin_disable_interrupt
  #define __enable_fault_irq  __iar_builtin_enable_fiq
  #define __enable_irq        __iar_builtin_enable_interrupt
  #define __arm_rsr           __iar_builtin_rsr
  #define __arm_wsr           __iar_builtin_wsr


  #define __get_APSR()                (__arm_rsr("APSR"))
  #define __get_BASEPRI()             (__arm_rsr("BASEPRI"))
  #define __get_CONTROL()             (__arm_rsr("CONTROL"))
  #define __get_FAULTMASK()           (__arm_rsr("FAULTMASK"))

  #if ((defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U)) && \
       (defined (__FPU_USED   ) && (__FPU_USED    == 1U))     )
    #define __get_FPSCR()             (__arm_rsr("FPSCR"))
    #define __set_FPSCR(VALUE)        (__arm_wsr("FPSCR", (VALUE)))
  #else
    #define __get_FPSCR()             ( 0 )
    #define __set_FPSCR(VALUE)        ((void)VALUE)
  #endif

  #define __get_IPSR()                (__arm_rsr("IPSR"))
  #define __get_MSP()                 (__arm_rsr("MSP"))
  #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
       (!defined (__ARM_FEATURE_CMSE) || (__ARM_FEATURE_CMSE < 3)))
    // without main extensions, the non-secure MSPLIM is RAZ/WI
    #define __get_MSPLIM()            (0U)
  #else
    #define __get_MSPLIM()            (__arm_rsr("MSPLIM"))
  #endif
  #define __get_PRIMASK()             (__arm_rsr("PRIMASK"))
  #define __get_PSP()                 (__arm_rsr("PSP"))

  #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
       (!defined (__ARM_FEATURE_CMSE) || (__ARM_FEATURE_CMSE < 3)))
    // without main extensions, the non-secure PSPLIM is RAZ/WI
    #define __get_PSPLIM()            (0U)
  #else
    #define __get_PSPLIM()            (__arm_rsr("PSPLIM"))
  #endif

  #define __get_xPSR()                (__arm_rsr("xPSR"))

  #define __set_BASEPRI(VALUE)        (__arm_wsr("BASEPRI", (VALUE)))
  #define __set_BASEPRI_MAX(VALUE)    (__arm_wsr("BASEPRI_MAX", (VALUE)))

__STATIC_FORCEINLINE void __set_CONTROL(uint32 control)
{
  __arm_wsr("CONTROL", control);
  __iar_builtin_ISB();
}

  #define __set_FAULTMASK(VALUE)      (__arm_wsr("FAULTMASK", (VALUE)))
  #define __set_MSP(VALUE)            (__arm_wsr("MSP", (VALUE)))

  #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
       (!defined (__ARM_FEATURE_CMSE) || (__ARM_FEATURE_CMSE < 3)))
    // without main extensions, the non-secure MSPLIM is RAZ/WI
    #define __set_MSPLIM(VALUE)       ((void)(VALUE))
  #else
    #define __set_MSPLIM(VALUE)       (__arm_wsr("MSPLIM", (VALUE)))
  #endif
  #define __set_PRIMASK(VALUE)        (__arm_wsr("PRIMASK", (VALUE)))
  #define __set_PSP(VALUE)            (__arm_wsr("PSP", (VALUE)))
  #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
       (!defined (__ARM_FEATURE_CMSE) || (__ARM_FEATURE_CMSE < 3)))
    // without main extensions, the non-secure PSPLIM is RAZ/WI
    #define __set_PSPLIM(VALUE)       ((void)(VALUE))
  #else
    #define __set_PSPLIM(VALUE)       (__arm_wsr("PSPLIM", (VALUE)))
  #endif

  #define __TZ_get_CONTROL_NS()       (__arm_rsr("CONTROL_NS"))

__STATIC_FORCEINLINE void __TZ_set_CONTROL_NS(uint32 control)
{
  __arm_wsr("CONTROL_NS", control);
  __iar_builtin_ISB();
}

  #define __TZ_get_PSP_NS()           (__arm_rsr("PSP_NS"))
  #define __TZ_set_PSP_NS(VALUE)      (__arm_wsr("PSP_NS", (VALUE)))
  #define __TZ_get_MSP_NS()           (__arm_rsr("MSP_NS"))
  #define __TZ_set_MSP_NS(VALUE)      (__arm_wsr("MSP_NS", (VALUE)))
  #define __TZ_get_SP_NS()            (__arm_rsr("SP_NS"))
  #define __TZ_set_SP_NS(VALUE)       (__arm_wsr("SP_NS", (VALUE)))
  #define __TZ_get_PRIMASK_NS()       (__arm_rsr("PRIMASK_NS"))
  #define __TZ_set_PRIMASK_NS(VALUE)  (__arm_wsr("PRIMASK_NS", (VALUE)))
  #define __TZ_get_BASEPRI_NS()       (__arm_rsr("BASEPRI_NS"))
  #define __TZ_set_BASEPRI_NS(VALUE)  (__arm_wsr("BASEPRI_NS", (VALUE)))
  #define __TZ_get_FAULTMASK_NS()     (__arm_rsr("FAULTMASK_NS"))
  #define __TZ_set_FAULTMASK_NS(VALUE)(__arm_wsr("FAULTMASK_NS", (VALUE)))

  #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
       (!defined (__ARM_FEATURE_CMSE) || (__ARM_FEATURE_CMSE < 3)))
    // without main extensions, the non-secure PSPLIM is RAZ/WI
    #define __TZ_get_PSPLIM_NS()      (0U)
    #define __TZ_set_PSPLIM_NS(VALUE) ((void)(VALUE))
  #else
    #define __TZ_get_PSPLIM_NS()      (__arm_rsr("PSPLIM_NS"))
    #define __TZ_set_PSPLIM_NS(VALUE) (__arm_wsr("PSPLIM_NS", (VALUE)))
  #endif

  #define __TZ_get_MSPLIM_NS()        (__arm_rsr("MSPLIM_NS"))
  #define __TZ_set_MSPLIM_NS(VALUE)   (__arm_wsr("MSPLIM_NS", (VALUE)))

  #define __NOP     __iar_builtin_no_operation

  #define __DMB     __iar_builtin_DMB
  #define __DSB     __iar_builtin_DSB
  #define __ISB     __iar_builtin_ISB

  #define __SEV     __iar_builtin_SEV

  #define __WFE     __iar_builtin_WFE
  #define __WFI     __iar_builtin_WFI

#else /* __ICCARM_INTRINSICS_VERSION__ == 2 */

  #if __IAR_M0_FAMILY
   /* Avoid clash between intrinsics.h and arm_math.h when compiling for Cortex-M0. */
    #define __get_APSR  __cmsis_iar_get_APSR_not_active
  #endif


  #if (!((defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U)) && \
         (defined (__FPU_USED   ) && (__FPU_USED    == 1U))     ))
    #define __get_FPSCR __cmsis_iar_get_FPSR_not_active
    #define __set_FPSCR __cmsis_iar_set_FPSR_not_active
  #endif

  #ifdef __INTRINSICS_INCLUDED
  #error intrinsics.h is already included previously!
  #endif

  #include <intrinsics.h>

  #if __IAR_M0_FAMILY
   /* Avoid clash between intrinsics.h and arm_math.h when compiling for Cortex-M0. */
    #undef __get_APSR

    __STATIC_INLINE  uint32 __get_APSR(void)
    {
      uint32 res;
      __asm("MRS      %0,APSR" : "=r" (res));
      return res;
    }

  #endif

  #if (!((defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U)) && \
         (defined (__FPU_USED   ) && (__FPU_USED    == 1U))     ))
    #undef __get_FPSCR
    #undef __set_FPSCR
    #define __get_FPSCR()       (0)
    #define __set_FPSCR(VALUE)  ((void)VALUE)
  #endif

  #pragma diag_suppress=Pe940
  #pragma diag_suppress=Pe177

  #define __enable_irq    __enable_interrupt
  #define __disable_irq   __disable_interrupt
  #define __NOP           __no_operation

  #define __get_xPSR      __get_PSR

  /* __CORTEX_M is defined in core_cm0.h, core_cm3.h and core_cm4.h. */
  #if (__CORTEX_M >= 0x03)

    __IAR_FT void __set_BASEPRI_MAX(uint32 value)
    {
      __asm volatile("MSR      BASEPRI_MAX,%0"::"r" (value));
    }


    #define __enable_fault_irq  __enable_fiq
    #define __disable_fault_irq __disable_fiq


  #endif /* (__CORTEX_M >= 0x03) */

  #if ((defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) || \
       (defined (__ARM_ARCH_8M_BASE__ ) && (__ARM_ARCH_8M_BASE__ == 1))    )

   __IAR_FT uint32 __get_MSPLIM(void)
    {
      uint32 res;
    #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
         (!defined (__ARM_FEATURE_CMSE  ) || (__ARM_FEATURE_CMSE   < 3)))
      // without main extensions, the non-secure MSPLIM is RAZ/WI
      res = 0U;
    #else
      __asm volatile("MRS      %0,MSPLIM" : "=r" (res));
    #endif
      return res;
    }

    __IAR_FT void   __set_MSPLIM(uint32 value)
    {
    #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
         (!defined (__ARM_FEATURE_CMSE  ) || (__ARM_FEATURE_CMSE   < 3)))
      // without main extensions, the non-secure MSPLIM is RAZ/WI
      (void)value;
    #else
      __asm volatile("MSR      MSPLIM,%0" :: "r" (value));
    #endif
    }

    __IAR_FT uint32 __get_PSPLIM(void)
    {
      uint32 res;
    #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
         (!defined (__ARM_FEATURE_CMSE  ) || (__ARM_FEATURE_CMSE   < 3)))
      // without main extensions, the non-secure PSPLIM is RAZ/WI
      res = 0U;
    #else
      __asm volatile("MRS      %0,PSPLIM" : "=r" (res));
    #endif
      return res;
    }

    __IAR_FT void   __set_PSPLIM(uint32 value)
    {
    #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
         (!defined (__ARM_FEATURE_CMSE  ) || (__ARM_FEATURE_CMSE   < 3)))
      // without main extensions, the non-secure PSPLIM is RAZ/WI
      (void)value;
    #else
      __asm volatile("MSR      PSPLIM,%0" :: "r" (value));
    #endif
    }

    __IAR_FT uint32 __TZ_get_CONTROL_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,CONTROL_NS" : "=r" (res));
      return res;
    }

    __IAR_FT void   __TZ_set_CONTROL_NS(uint32 value)
    {
      __asm volatile("MSR      CONTROL_NS,%0" :: "r" (value));
      __iar_builtin_ISB();
    }

    __IAR_FT uint32   __TZ_get_PSP_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,PSP_NS" : "=r" (res));
      return res;
    }

    __IAR_FT void   __TZ_set_PSP_NS(uint32 value)
    {
      __asm volatile("MSR      PSP_NS,%0" :: "r" (value));
    }

    __IAR_FT uint32   __TZ_get_MSP_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,MSP_NS" : "=r" (res));
      return res;
    }

    __IAR_FT void   __TZ_set_MSP_NS(uint32 value)
    {
      __asm volatile("MSR      MSP_NS,%0" :: "r" (value));
    }

    __IAR_FT uint32   __TZ_get_SP_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,SP_NS" : "=r" (res));
      return res;
    }
    __IAR_FT void   __TZ_set_SP_NS(uint32 value)
    {
      __asm volatile("MSR      SP_NS,%0" :: "r" (value));
    }

    __IAR_FT uint32   __TZ_get_PRIMASK_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,PRIMASK_NS" : "=r" (res));
      return res;
    }

    __IAR_FT void   __TZ_set_PRIMASK_NS(uint32 value)
    {
      __asm volatile("MSR      PRIMASK_NS,%0" :: "r" (value));
    }

    __IAR_FT uint32   __TZ_get_BASEPRI_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,BASEPRI_NS" : "=r" (res));
      return res;
    }

    __IAR_FT void   __TZ_set_BASEPRI_NS(uint32 value)
    {
      __asm volatile("MSR      BASEPRI_NS,%0" :: "r" (value));
    }

    __IAR_FT uint32   __TZ_get_FAULTMASK_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,FAULTMASK_NS" : "=r" (res));
      return res;
    }

    __IAR_FT void   __TZ_set_FAULTMASK_NS(uint32 value)
    {
      __asm volatile("MSR      FAULTMASK_NS,%0" :: "r" (value));
    }

    __IAR_FT uint32   __TZ_get_PSPLIM_NS(void)
    {
      uint32 res;
    #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
         (!defined (__ARM_FEATURE_CMSE  ) || (__ARM_FEATURE_CMSE   < 3)))
      // without main extensions, the non-secure PSPLIM is RAZ/WI
      res = 0U;
    #else
      __asm volatile("MRS      %0,PSPLIM_NS" : "=r" (res));
    #endif
      return res;
    }

    __IAR_FT void   __TZ_set_PSPLIM_NS(uint32 value)
    {
    #if (!(defined (__ARM_ARCH_8M_MAIN__ ) && (__ARM_ARCH_8M_MAIN__ == 1)) && \
         (!defined (__ARM_FEATURE_CMSE  ) || (__ARM_FEATURE_CMSE   < 3)))
      // without main extensions, the non-secure PSPLIM is RAZ/WI
      (void)value;
    #else
      __asm volatile("MSR      PSPLIM_NS,%0" :: "r" (value));
    #endif
    }

    __IAR_FT uint32   __TZ_get_MSPLIM_NS(void)
    {
      uint32 res;
      __asm volatile("MRS      %0,MSPLIM_NS" : "=r" (res));
      return res;
    }

    __IAR_FT void   __TZ_set_MSPLIM_NS(uint32 value)
    {
      __asm volatile("MSR      MSPLIM_NS,%0" :: "r" (value));
    }

  #endif /* __ARM_ARCH_8M_MAIN__ or __ARM_ARCH_8M_BASE__ */

#endif   /* __ICCARM_INTRINSICS_VERSION__ == 2 */

#define __BKPT(value)    __asm volatile ("BKPT     %0" : : "i"(value))

#undef __IAR_FT
#undef __IAR_M0_FAMILY
#undef __ICCARM_V8

#pragma diag_default=Pe940
#pragma diag_default=Pe177


#endif /* __CMSIS_ICCARM_H__ */

