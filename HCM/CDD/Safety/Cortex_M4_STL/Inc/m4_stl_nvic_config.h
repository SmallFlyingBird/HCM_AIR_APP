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
 *      Declaration of global variables and #define directive for typical configuration
 *
 *   About: Supported Configurations
 *      Typical Configuration
 *
 *   About: Assumption of Use
 *      All global assumptions of use apply
 *      Local assumptions of use: NONE
 *
 *   About: TEST_ID
 *      N.A.
 *
 **************************************************************************************************/


#ifndef M4_STL_NVIC_CONFIG_H
#define M4_STL_NVIC_CONFIG_H

#include <stdint.h>
#include "device_regs.h"
/* START User Configuration Section */

#define __NVIC_PRIO_BITS        4U
#define __FPU_PRESENT           1U

/* END User Configuration Section */

/* define ARM Architecture in use, necessary for CMSIS */
#ifndef __ARM_ARCH_7M__
    #define __ARM_ARCH_7M__        1
#endif

/* Register addresses definitions */

#define STL_ICSR_reg        ((ICSR_t *) 0xE000ED04)
#define STL_SHCSR_reg       ((SHCSR_t *) 0xE000ED24)
#define STL_SCR_reg         ((SCR_t *) 0xE000ED10)
#define STL_FPCCR_reg       ((FPCCR_t *) 0xE000EF34)

#define STL_NVIC_ISER0_reg        ((NVIC_ISER_t *) 0xE000E100)
#define STL_NVIC_ISER1_reg        ((NVIC_ISER_t *) 0xE000E104)
#define STL_NVIC_ISER2_reg        ((NVIC_ISER_t *) 0xE000E108)
#define STL_NVIC_ISER3_reg        ((NVIC_ISER_t *) 0xE000E10C)
#define STL_NVIC_ISER4_reg        ((NVIC_ISER_t *) 0xE000E110)
#define STL_NVIC_ISER5_reg        ((NVIC_ISER_t *) 0xE000E114)
#define STL_NVIC_ISER6_reg        ((NVIC_ISER_t *) 0xE000E118)
#define STL_NVIC_ISER7_reg        ((NVIC_ISER_t *) 0xE000E11C)

#define STL_NVIC_ICER0_reg        ((NVIC_ICER_t *) 0xE000E180)
#define STL_NVIC_ICER1_reg        ((NVIC_ICER_t *) 0xE000E184)
#define STL_NVIC_ICER2_reg        ((NVIC_ICER_t *) 0xE000E188)
#define STL_NVIC_ICER3_reg        ((NVIC_ICER_t *) 0xE000E18C)
#define STL_NVIC_ICER4_reg        ((NVIC_ICER_t *) 0xE000E190)
#define STL_NVIC_ICER5_reg        ((NVIC_ICER_t *) 0xE000E194)
#define STL_NVIC_ICER6_reg        ((NVIC_ICER_t *) 0xE000E198)
#define STL_NVIC_ICER7_reg        ((NVIC_ICER_t *) 0xE000E19C)

/* Function names declarations */

#define STL_NVIC_Set_Pending                __STL_NVIC_Set_Pending
#define STL_NVIC_Clear_Pending              __STL_NVIC_Clear_Pending
#define STL_NVIC_Enable_All_IRQs            __STL_NVIC_Enable_All_IRQs
#define STL_NVIC_Clear_Enable_All_IRQs      __STL_NVIC_Clear_Enable_All_IRQs
#define STL_Get_ICSR                        __STL_Get_ICSR
#define STL_Set_ICSR                        __STL_Set_ICSR
#define STL_Get_SHCSR                       __STL_Get_SHCSR
#define STL_Set_SHCSR                       __STL_Set_SHCSR
#define STL_Get_SCR                         __STL_Get_SCR
#define STL_Set_SCR                         __STL_Set_SCR
#define STL_Get_NVIC_ISER0                  __STL_Get_NVIC_ISER0
#define STL_Set_NVIC_ISER0                  __STL_Set_NVIC_ISER0
#define STL_Get_NVIC_ISER1                  __STL_Get_NVIC_ISER1
#define STL_Set_NVIC_ISER1                  __STL_Set_NVIC_ISER1
#define STL_Get_NVIC_ISER2                  __STL_Get_NVIC_ISER2
#define STL_Set_NVIC_ISER2                  __STL_Set_NVIC_ISER2
#define STL_Get_NVIC_ISER3                  __STL_Get_NVIC_ISER3
#define STL_Set_NVIC_ISER3                  __STL_Set_NVIC_ISER3
#define STL_Get_NVIC_ISER4                  __STL_Get_NVIC_ISER4
#define STL_Set_NVIC_ISER4                  __STL_Set_NVIC_ISER4
#define STL_Get_NVIC_ISER5                  __STL_Get_NVIC_ISER5
#define STL_Set_NVIC_ISER5                  __STL_Set_NVIC_ISER5
#define STL_Get_NVIC_ISER6                  __STL_Get_NVIC_ISER6
#define STL_Set_NVIC_ISER6                  __STL_Set_NVIC_ISER6
#define STL_Get_NVIC_ISER7                  __STL_Get_NVIC_ISER7
#define STL_Set_NVIC_ISER7                  __STL_Set_NVIC_ISER7
#define STL_Get_FPCCR                       __STL_Get_FPCCR
#define STL_Set_FPCCR                       __STL_Set_FPCCR

typedef struct{

        uint32_t STL_NVIC_ISER_v;

}  NVIC_ISER_t;

typedef struct{

        uint32_t STL_NVIC_ICER_v;

}  NVIC_ICER_t;

typedef struct{

        uint32_t STL_ICSR_v;

}  ICSR_t;

typedef struct{

        uint32_t STL_SHCSR_v;

}  SHCSR_t;

typedef struct{

        uint32_t STL_SCR_v;

}  SCR_t;


typedef struct{

        uint32_t STL_FPCCR;

}  FPCCR_t;

#endif
