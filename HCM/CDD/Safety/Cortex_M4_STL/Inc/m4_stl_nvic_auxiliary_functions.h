/******************************************************************************/
/**
 *  The confidential and proprietary information contained in this file may
 *  only be used by a person authorised under and to the extent permitted
 *  by a subsisting licensing agreement from ARM Limited or its affiliates.
 *
 *         (C) COPYRIGHT 2017-2018 ARM Limited or its affiliates.
 *             ALL RIGHTS RESERVED
 *
 *  This entire notice must be reproduced on all copies of this file
 *  and copies of this file may only be made by a person if such person is
 *  permitted to do so under the terms of a subsisting license agreement
 *  from ARM Limited or its affiliates.
 *
 *  Release Information : Cortex-M4_STL-r0p0-00eac0
 * 
 ******************************************************************************/
/**************************************************************************************************/
/**
 *   About: About the File
 *      CMSIS functions for Core, System Control Block and NVIC registers access
 *
 *   About: Supported Configurations
 *      All configurations
 *
 *   About: Assumption of Use
 *      All global assumptions of use apply
 *      Local assumptions of use: AD-NVIC, AD-FMSK
 *
 *   About: TEST_ID
 *      N.A.
 * 
 **************************************************************************************************/



#ifndef M4_STL_NVIC_AUXILIARY_FUNCTIONS_H
#define M4_STL_NVIC_AUXILIARY_FUNCTIONS_H

#include <stdint.h>
#include "m4_stl_nvic_config.h"
#if defined(__ghs__)
#include "ghs_compatible.h"
#else
#include "cmsis_compiler.h"
#endif
#include "core_cm4.h"


/* Auxiliary functions for NVIC Pending and Active Tree test */



/* This function sets to pending state the IRQ number specified as input */
__STATIC_INLINE void __STL_NVIC_Set_Pending(int32_t exc_num)
{

        if(exc_num < 0){

            switch(exc_num){

                /* NMI Exception */
                case -14:
                    /* Set NMIPENDSET bit to 1 */
                    STL_ICSR_reg -> STL_ICSR_v |= 0x80000000;
                break;
                /* MemManage Exception */
                case -12:
                    /* Set MEMFAULTPENDED bit to 1 */
                    STL_SHCSR_reg -> STL_SHCSR_v |= 0x00002000;
                break;
                /* BusFault Exception */
                case -11:
                    /* Set BUSFAULTPENDED bit to 1 */
                    STL_SHCSR_reg -> STL_SHCSR_v |= 0x00004000;
                break;
                /* UsageFault Exception */
                case -10:
                    /* Set USGFAULTPENDED bit to 1 */
                    STL_SHCSR_reg -> STL_SHCSR_v |= 0x00001000;
                break;
                /* SVCall Exception */
                case -5:
                    /* Set SVCALLPENDED bit to 1 */
                    STL_SHCSR_reg -> STL_SHCSR_v |= 0x00008000;
                break;
                /* PendSV Exception */
                case -2:
                    /* Set PENDSVSET bit to 1 */
                    STL_ICSR_reg -> STL_ICSR_v |= 0x10000000;
                break;
                /* SysTick Exception */
                case -1:
                    /* Set PENDSTSET bit to 1 */
                    STL_ICSR_reg -> STL_ICSR_v |= 0x04000000;
                break;
                default:
                    /* Set none */
                break;

            }

        }else{

            NVIC_SetPendingIRQ((IRQn_Type)exc_num);

        }

}

/* This function clears pending state for the IRQ number specified as input */
__STATIC_INLINE void __STL_NVIC_Clear_Pending(int32_t exc_num)
{

        if(exc_num < 0){

        	uint32_t temp = 0x00000000;

                switch(exc_num){

                    /* MemManage Exception */
                    case -12:
                        /* Set MEMFAULTPENDED bit to 0 */
                        STL_SHCSR_reg -> STL_SHCSR_v &= 0xFFFFDFFF;
                    break;
                    /* BusFault Exception */
                    case -11:
                        /* Set BUSFAULTPENDED bit to 0 */
                        STL_SHCSR_reg -> STL_SHCSR_v &= 0xFFFFBFFF;
                    break;
                    /* UsageFault Exception */
                    case -10:
                        /* Set USGFAULTPENDED bit to 0 */
                        STL_SHCSR_reg -> STL_SHCSR_v &= 0xFFFFEFFF;
                    break;
                    /* SVCall Exception */
                    case -5:
                        /* Set SVCALLPENDED bit to 0 */
                        STL_SHCSR_reg -> STL_SHCSR_v &= 0xFFFF7FFF;
                    break;
                    /* PendSV Exception */
                    case -2:
                        /* Set PENDSVCLR bit to 1 */
                        temp = STL_ICSR_reg -> STL_ICSR_v;
                        temp = (temp & 0xE7FFFFFF)|0x08000000;
                        STL_ICSR_reg -> STL_ICSR_v = temp;
                    break;
                    /* SysTick Exception */
                    case -1:
                        /* Set PENDSTCLR bit to 1 */
                        temp = STL_ICSR_reg -> STL_ICSR_v;
                        temp = (temp & 0xF9FFFFFF)|0x02000000;
                        STL_ICSR_reg -> STL_ICSR_v = temp;
                    break;
                    default:
                        /* Set none */
                    break;

                }

        }else{

            NVIC_ClearPendingIRQ((IRQn_Type)exc_num);

        }

}

/* This function sets all IRQ Enable bits to 1 */
__STATIC_INLINE void __STL_NVIC_Enable_All_IRQs(void)
{
        /* Setting all ISER registers to 0xFFFFFFFF */
        STL_NVIC_ISER0_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
        STL_NVIC_ISER1_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
        STL_NVIC_ISER2_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
        STL_NVIC_ISER3_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
        STL_NVIC_ISER4_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
        STL_NVIC_ISER5_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
        STL_NVIC_ISER6_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
        STL_NVIC_ISER7_reg -> STL_NVIC_ISER_v = 0xFFFFFFFF;
}

/* This function sets all IRQ Enable bits to 0 */
__STATIC_INLINE void __STL_NVIC_Clear_Enable_All_IRQs(void)
{
        /* Setting all ICER registers to 0xFFFFFFFF */
        STL_NVIC_ICER0_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
        STL_NVIC_ICER1_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
        STL_NVIC_ICER2_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
        STL_NVIC_ICER3_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
        STL_NVIC_ICER4_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
        STL_NVIC_ICER5_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
        STL_NVIC_ICER6_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
        STL_NVIC_ICER7_reg -> STL_NVIC_ICER_v = 0xFFFFFFFF;
}

/* This function returns ICSR register value */
__STATIC_INLINE uint32_t __STL_Get_ICSR(void)
{
        return STL_ICSR_reg -> STL_ICSR_v;
}

/* This function sets ICSR register to the value passed as input */
__STATIC_INLINE void __STL_Set_ICSR(uint32_t ICSR_value)
{
        STL_ICSR_reg -> STL_ICSR_v = ICSR_value;
}

/* This function returns SHCSR register value */
__STATIC_INLINE uint32_t __STL_Get_SHCSR(void)
{
        return STL_SHCSR_reg -> STL_SHCSR_v;
}

/* This function sets SHCSR register to the value passed as input */
__STATIC_INLINE void __STL_Set_SHCSR(uint32_t SHCSR_value)
{
        STL_SHCSR_reg -> STL_SHCSR_v = SHCSR_value;
}

/* This function returns SCR register value */
__STATIC_INLINE uint32_t __STL_Get_SCR(void)
{
        return STL_SCR_reg -> STL_SCR_v;
}

/* This function sets SCR register to the value passed as input */
__STATIC_INLINE void __STL_Set_SCR(uint32_t SCR_value)
{
        STL_SCR_reg -> STL_SCR_v = SCR_value;
}

/* This function returns NVIC_ISER0 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER0(void)
{
        return STL_NVIC_ISER0_reg -> STL_NVIC_ISER_v;
}

/* This function returns NVIC_ISER1 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER1(void)
{
        return STL_NVIC_ISER1_reg -> STL_NVIC_ISER_v;
}

/* This function returns NVIC_ISER2 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER2(void)
{
        return STL_NVIC_ISER2_reg -> STL_NVIC_ISER_v;
}

/* This function returns NVIC_ISER3 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER3(void)
{
        return STL_NVIC_ISER3_reg -> STL_NVIC_ISER_v;
}

/* This function returns NVIC_ISER4 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER4(void)
{
        return STL_NVIC_ISER4_reg -> STL_NVIC_ISER_v;
}

/* This function returns NVIC_ISER5 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER5(void)
{
        return STL_NVIC_ISER5_reg -> STL_NVIC_ISER_v;
}

/* This function returns NVIC_ISER6 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER6(void)
{
        return STL_NVIC_ISER6_reg -> STL_NVIC_ISER_v;
}

/* This function returns NVIC_ISER7 register value */
__STATIC_INLINE uint32_t __STL_Get_NVIC_ISER7(void)
{
        return STL_NVIC_ISER7_reg -> STL_NVIC_ISER_v;
}

/* This function sets NVIC_ISER0 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER0(uint32_t NVIC_ISER0_value)
{
        STL_NVIC_ISER0_reg -> STL_NVIC_ISER_v = NVIC_ISER0_value;
}

/* This function sets NVIC_ISER1 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER1(uint32_t NVIC_ISER1_value)
{
        STL_NVIC_ISER1_reg -> STL_NVIC_ISER_v = NVIC_ISER1_value;
}

/* This function sets NVIC_ISER2 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER2(uint32_t NVIC_ISER2_value)
{
        STL_NVIC_ISER2_reg -> STL_NVIC_ISER_v = NVIC_ISER2_value;
}

/* This function sets NVIC_ISER3 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER3(uint32_t NVIC_ISER3_value)
{
        STL_NVIC_ISER3_reg -> STL_NVIC_ISER_v = NVIC_ISER3_value;
}

/* This function sets NVIC_ISER4 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER4(uint32_t NVIC_ISER4_value)
{
        STL_NVIC_ISER4_reg -> STL_NVIC_ISER_v = NVIC_ISER4_value;
}

/* This function sets NVIC_ISER5 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER5(uint32_t NVIC_ISER5_value)
{
        STL_NVIC_ISER5_reg -> STL_NVIC_ISER_v = NVIC_ISER5_value;
}

/* This function sets NVIC_ISER6 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER6(uint32_t NVIC_ISER6_value)
{
        STL_NVIC_ISER6_reg -> STL_NVIC_ISER_v = NVIC_ISER6_value;
}

/* This function sets NVIC_ISER7 register to the value passed as input */
__STATIC_INLINE void __STL_Set_NVIC_ISER7(uint32_t NVIC_ISER7_value)
{
        STL_NVIC_ISER7_reg -> STL_NVIC_ISER_v = NVIC_ISER7_value;
}

/* This function returns FPCCR register value */
__STATIC_INLINE uint32_t __STL_Get_FPCCR(void)
{
        return STL_FPCCR_reg -> STL_FPCCR;
}

/* This function sets FPCCR register to the value passed as input */
__STATIC_INLINE void __STL_Set_FPCCR(uint32_t FPCCR_value)
{
        STL_FPCCR_reg -> STL_FPCCR = FPCCR_value;
}

/* end of Auxiliary functions for NVIC Pending and Active Tree test */


#endif
