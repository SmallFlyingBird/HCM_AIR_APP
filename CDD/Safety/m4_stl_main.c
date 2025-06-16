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
 *      m4 stl main file (used only for implementation)
 *
 *   About: Supported Configurations
 *      All configurations
 *
 *   About: Assumption of Use
 *      All global assumptions of use apply
 *      Local assumptions of use: NONE
 *
 *   About: TEST_ID
 *      N.A.
 * 
 **************************************************************************************************/
/*  This example contains sample code for customer evaluation purpose only. It is not
    part of the production code deliverables. The example code is only tested under defined
    environment with related context of the whole example project. Therefore, it is not guaranteed
    that the example always works under user environment due to the diversity of hardware and
    software environment. Do not use pieces copy of the example code without prior and separate
    verification and validation in user environment. */


/* System Includes */

#include <stdio.h>
#include "m4_stl_nvic_config.h"
#include "m4_stl_config_Var.h"
#include "functions_table_0x001f_3500.h"
#include "variables_table.h"
#include "z20k14xmc_stl_nvic_config.h"
#include "wdog_drv.h"
#include "ghs_compatible.h"
#include "SafetyDrv.h"

#define VectorTableOffsetRegister 0xE000ED08


/*User Includes (Project Level Includes) */

/* Defines MCU registers */

#define SERU_CFGKEY_reg   ((uint32_t *) 0x4007F010)
#define SERU_CSR_reg   ((uint32_t *) 0x4007F008)
#define SERU_CHFLAG_reg ((uint32_t *) 0x4007F01C)

#define NVIC_ISER0_reg ((uint32_t *) 0xE000E100)  /*外部中断使能寄存器*/
#define NVIC_ISER1_reg ((uint32_t *) 0xE000E104)
#define NVIC_ISER2_reg ((uint32_t *) 0xE000E108)
#define NVIC_ISER3_reg ((uint32_t *) 0xE000E10C)
#define NVIC_ISER4_reg ((uint32_t *) 0xE000E110)
#define NVIC_ISER5_reg ((uint32_t *) 0xE000E114)
#define NVIC_ISER6_reg ((uint32_t *) 0xE000E118)
#define NVIC_ISER7_reg ((uint32_t *) 0xE000E11C)

#define NVIC_ICER0_reg ((uint32_t *) 0xE000E180)   /*清除外部中断使能(失能)寄存器*/
#define NVIC_ICER1_reg ((uint32_t *) 0xE000E184)
#define NVIC_ICER2_reg ((uint32_t *) 0xE000E188)
#define NVIC_ICER3_reg ((uint32_t *) 0xE000E18C)
#define NVIC_ICER4_reg ((uint32_t *) 0xE000E190)
#define NVIC_ICER5_reg ((uint32_t *) 0xE000E194)
#define NVIC_ICER6_reg ((uint32_t *) 0xE000E198)
#define NVIC_ICER7_reg ((uint32_t *) 0xE000E19C)

#define SHPR1_reg ((uint32_t *) 0xE000ED18)    /*系统中断优先级*/
#define SHPR2_reg ((uint32_t *) 0xE000ED1C)
#define SHPR3_reg ((uint32_t *) 0xE000ED20)
#define NVIC_IPR0_reg ((uint32_t *) 0xE000E400)  /*外部中断优先级*/

#define SERU_CONFIG_KEY     (0x7F1A2dFEU)
#define SERU_NORMAL_KEY     (0x6CC92DD9U)

#define SLT_TEST_MODS_NUM 33U
/* init mods parameter */
uint8_t mods = 1;
/* init result variable */
uint32_t result = 0;

#if defined( __ICCARM__ )
  extern uint32_t PROCESS_STACK$$Limit;
    uint32_t process_stack_pointer_addr = (uint32_t) &PROCESS_STACK$$Limit;  
  extern uint32_t test_vectors$$Base;
    uint32_t test_vectors_addr = (uint32_t) &test_vectors$$Base;
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
/* If arm compiler is used, PROCESS_STACK and VECTORS shall be defined in linker file */
/* PROCESS_STACK is a stack section used for STL test */
/* VECTORS is a section which stores STL exceptions vectors table in m4_stl_exceptions.c */
  extern unsigned int Image$$PROCESS_STACK$$ZI$$Limit;
    uint32_t process_stack_pointer_addr = (uint32_t) &Image$$PROCESS_STACK$$ZI$$Limit;
  extern unsigned int Image$$VECTORS$$Base;
    uint32_t test_vectors_addr = (uint32_t) &Image$$VECTORS$$Base;
#elif defined(__ghs__)
  extern uint32_t __process_stack_end__;
    uint32_t process_stack_pointer_addr = (uint32_t) &__process_stack_end__;  
  extern uint32_t test_vectors_base;
    uint32_t test_vectors_addr = (uint32_t) &test_vectors_base;
#endif

void errorHandler(void);
void set_Priorities(void);
void stl_app(void);
void stl_init_var(void);
void m4_stl_main(void);
static void set_defaultVal(void);

const uint8_t oor_next_module_index[STL_TOT_MODS_MAX] = {
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_0,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_1,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_2,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_3,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_4,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_5,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_6,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_7,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_8,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_9,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_10,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_11,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_12,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_13,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_14_A,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_14_B,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_14_C,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_A,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_B,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_C,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_D,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_16_A,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_16_B,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_17_A,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_17_B,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_17_C,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_18,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_19,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_20,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_21,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_22,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_23,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_24,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_25,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_26,
        STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_27
};

#define ASMV_KEYWORD  __asm volatile

static void WDOG_REFRESH_COUNT(void)
{
    uint32_t Primask;
    ASMV_KEYWORD( "MRS %0, PRIMASK " : "=r"(Primask));
    if (0U == Primask)
    {
        COMMON_DISABLE_INTERRUPTS();
    }
    __asm (
        "PUSH  {R0, R1, R2}\n"
        "LDR   R0, =0x40052014\n"
        "LDR   R1, =0xA0C4B1D6\n"
        "LDR   R2, =0x1E0D0C7B\n"

        "STR   R1, [R0]\n"
        "STR   R2, [R0]\n"
        "POP  {R0, R1, R2}\n"
            );
    if (0U == Primask)
    {
        COMMON_ENABLE_INTERRUPTS();
    }
}

void WDOG_Refresh(void)
{
    WDOG_REFRESH_COUNT();
}

__attribute__((noreturn)) void m4_stl_main(void)
{
        *SERU_CFGKEY_reg = SERU_CONFIG_KEY;
        uint32 temp =*SERU_CHFLAG_reg;
        *SERU_CHFLAG_reg = temp;
        *SERU_CSR_reg = 0;
        *SERU_CFGKEY_reg = SERU_NORMAL_KEY;
        /* Launch the core test function in order to perform Diagnosis SW */
        /* Procedure to set CP10 and CP11 of CPACR register to enable FPU */
        /* Read CPACR */
        __asm("LDR.W R0, =0xE000ED88");
        /* Set bits 20-23 to enable CP10 and CP11 coprocessors */
        __asm("LDR R1, [R0]");
        /* Write back the modified value to the CPACR */
        __asm("ORR R1, R1, #(0xF << 20)");
        /* wait for store to complete */
        __asm("STR R1, [R0]");
        /* reset pipeline now the FPU is enabled */
        __asm("DSB");
        __asm("ISB");

        /* Processor starts-up in Privileged Thread Mode using Main Stack */

        /* Tell the processor the location of the vector table used for STL, obtained from the linker file */
        volatile uint32_t Vector_Old = *(volatile uint32_t *)(VectorTableOffsetRegister);
        *(volatile uint32_t *)(VectorTableOffsetRegister) = (uint32_t) test_vectors_addr;

        /* Initialize Process Stack Pointer */
        #if defined(__ghs__)
          __MSR(__PSP, (uint32_t) process_stack_pointer_addr);
        #else
          __arm_wsr("PSP", (uint32_t) process_stack_pointer_addr);
        #endif

        /* Change Thread mode to Unprivileged and to use the Process Stack */
        #if defined(__ghs__)
          uint32_t read_ctrl = __MRS(__CONTROL);
          __MSR(__CONTROL, read_ctrl | 2);
        #else
          uint32_t read_ctrl = __arm_rsr("CONTROL");
          __arm_wsr("CONTROL", read_ctrl | 2);
        #endif

        /* Flush and refill pipeline with unprivileged permissions */
        #if defined(__ghs__)
          __ISB();
        #else
          __isb(0xf);
        #endif
        
        /* Initialize value of some variables used in library */
        stl_init_var();
        
        /* Run the main application (sorts) */
        stl_app();
        set_defaultVal();

        *(volatile uint32_t *)(VectorTableOffsetRegister) = (uint32_t) Vector_Old;

        /* Change to use main stack */
        #if defined(__ghs__)
          read_ctrl = __MRS(__CONTROL);
          __MSR(__CONTROL, read_ctrl  & ~2);
        #else
          read_ctrl = __arm_rsr("CONTROL");
          __arm_wsr("CONTROL", read_ctrl  & ~2);
        #endif

        /* Flush and refill pipeline before proceeding */
        #if defined(__ghs__)
          __ISB();
        #else
          __isb(0xf);
        #endif

        
        // for(;;)
        // {
            /* Refresh watch dog */
            //  WDOG_Refresh();
        // }
}

void stl_app(void)
{

        /* Refresh watch dog */
         WDOG_Refresh();

        /* Flush and refill pipeline before proceeding */
        #if defined(__ghs__)
          __ISB();
        #else
          __isb(0xf);
        #endif

        /* init index */
        M4_STL_INIT_FUNC(STL_TMODE_OOR, STL_OOR_FIRST_MODULE_IDX);

        /* Enable all Interrupt and Exceptions */
        __asm("cpsie f");

        /* Necessary to set ISER registers */
        uint32_t en_dis_Value = 0xFFFFFFFF;

        /* ENABLING ALL IRQ */

        /* Setting all ISER registers to 0xFFFFFFFF */
        *NVIC_ISER0_reg = en_dis_Value;
        *NVIC_ISER1_reg = en_dis_Value;
        *NVIC_ISER2_reg = en_dis_Value;
        *NVIC_ISER3_reg = en_dis_Value;
        *NVIC_ISER4_reg = en_dis_Value;
        *NVIC_ISER5_reg = en_dis_Value;
        *NVIC_ISER6_reg = en_dis_Value;
        *NVIC_ISER7_reg = en_dis_Value;

        /* Calls all testSegments and exits once a testSegment fails */
        
        mods=SLT_TEST_MODS_NUM;

        /*Note: When testing NVIC or exceptions, there shall be no pending or active interrupts or 
        exceptions, and no interrupts or exceptions shall be generated during the test. */

        /*Note: During the execution of specific modules, 
        Non-Maskable Interrupt(NMI) shall never be asserted.*/
        
        result = M4_STL_FUNC(mods, STL_TMODE_OOR, oor_next_module_index,NULL,NULL);

        /* Refresh watch dog */
         WDOG_Refresh();

        if(result != 1U) 
        {
          uint32 index = M4_STL_GET_LAST_EXECUTED_FUNC(STL_TMODE_OOR);
          errorHandler();
        }

        /* Initialize NVIC Pending/Active tree global variables */
        M4_STL_NVIC_INIT_FUNC();

        set_Priorities();

        /* User shall set up the appropriate number of tests to be executed here */
        result = M4_STL_NVIC_FUNC(1, m4_stl_next_irq_index, m4_stl_test_param);
        
        /* Refresh watch dog */
         WDOG_Refresh();

        if(result != 1U) 
        {
            Safety_SetTestRes(SAFETY_STL_OOR, SAFETY_ERROR);
            errorHandler();
        }

        Safety_SetTestRes(SAFETY_STL_OOR, SAFETY_NORMAL);

}

/**
 * @brief      This API initializes the data used by STL.
 *             It needs to be called first before calling any other STL APIs. 
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void stl_init_var(void)
{
#ifndef STL_DATA_SEC_ALREADY_INITIALIZE
      uint32_t *sram_addr_ptr = (uint32_t *)(0x2000000);
      while((uint32_t)sram_addr_ptr < 0x2000000 + 0x40U)
      {
        (*sram_addr_ptr) = 0x00000000U;
        sram_addr_ptr++;
      }
#endif

    *stl_last_exec_ptr = (uint8_t)0xFF;
    *stl_fail_test_ptr = (uint8_t) 1;
    *stl_exit_first_fault_ptr = (uint8_t) 1;

}

/* Demo function here */
/* User shall implement this function autonomously to handle error properly */
void errorHandler(void)
{
        while(true)
        {
            /* Refresh watch dog */
            // WDOG_Refresh();
        }
}

void set_Priorities(void){

        /* Set exceptions priority */
        uint32_t SHPR1_value = 0x00000000;
        uint32_t SHPR2_value = 0x00000000;
        uint32_t SHPR3_value = 0x00000000;

        /* Set MemManage Fault priority to highest priority possible value */
        uint32_t value_tmp = (0x00000008 - __NVIC_PRIO_BITS);
        value_tmp = (0x1 << value_tmp);
        value_tmp = 0x100 - value_tmp;
        SHPR1_value = SHPR1_value | value_tmp;

        /* Set Bus Fault priority with distance 2 from MemManage Fault priority */
        value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
        value_tmp = value_tmp & 0x000000FF;
        value_tmp = value_tmp << 0x8;
        SHPR1_value = SHPR1_value | value_tmp;

        /* Set Usage Fault priority with distance 2 from Bus Fault priority */
        value_tmp = value_tmp >> 0x8;
        value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
        value_tmp = value_tmp & 0x000000FF;
        value_tmp = value_tmp << 0x10;
        SHPR1_value = SHPR1_value | value_tmp;

        *SHPR1_reg = SHPR1_value;

        /* Set SVCall priority with distance 2 from Usage Fault priority */
        value_tmp = value_tmp >> 0x10;
        value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
        value_tmp = value_tmp & 0x000000FF;
        value_tmp = value_tmp << 0x18;
        SHPR2_value = SHPR2_value | value_tmp;

        *SHPR2_reg = SHPR2_value;

        /* Set PendSV Fault priority with distance 2 from SVCall priority */
        value_tmp = value_tmp >> 0x18;
        value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
        value_tmp = value_tmp & 0x000000FF;
        value_tmp = value_tmp << 0x10;
        SHPR3_value = SHPR3_value | value_tmp;

        /* Set SysTick priority with distance 2 from PendSV Fault priority */
        value_tmp = value_tmp >> 0x10;
        value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
        value_tmp = value_tmp & 0x000000FF;
        value_tmp = value_tmp << 0x18;
        SHPR3_value = SHPR3_value | value_tmp;

        *SHPR3_reg = SHPR3_value;

        value_tmp = value_tmp >> 0x18;

        /* Set Interrupts priorities */

        int counter = 0;
        int offset = 0;
        uint32_t IPR_value = 0x00000000;

        while(counter <= m4_stl_test_param[4]){

            value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
            value_tmp = value_tmp & 0x000000FF;
            IPR_value = IPR_value | value_tmp;

            value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
            value_tmp = value_tmp & 0x000000FF;
            value_tmp = value_tmp << 0x8;
            IPR_value = IPR_value | value_tmp;

            value_tmp = value_tmp >> 0x8;

            value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
            value_tmp = value_tmp & 0x000000FF;
            value_tmp = value_tmp << 0x10;
            IPR_value = IPR_value | value_tmp;

            value_tmp = value_tmp >> 0x10;

            value_tmp = value_tmp - (0x00000001 << (0x8 - __NVIC_PRIO_BITS + 0x1));
            value_tmp = value_tmp & 0x000000FF;
            value_tmp = value_tmp << 0x18;
            IPR_value = IPR_value | value_tmp;

            value_tmp = value_tmp >> 0x18;

            *(NVIC_IPR0_reg + offset) = IPR_value;

            IPR_value = 0x00000000;

            offset++;

            counter = counter + 4;

        }

}

static boolean hasCoreTestHex = false;
static boolean Safety_HasCoreTestHex(void)
{
  const uint8 *coreTestStartAddr = STL_FUNC_BASE;
  static uint8_t coreTestStartData[4] = {0xDD, 0xCA, 0x1f, 0x00}; // hex 内容固定
  for(uint8_t i = 0; i < 4; i++) {
    if (coreTestStartData[i] != coreTestStartAddr[i]) {
      hasCoreTestHex = false;
      return false;
    }
  }
  hasCoreTestHex = true;
  return true;
}

static boolean Safety_HasCoreTestHexRes(void) {
  return hasCoreTestHex;
}

void Safety_CoreSwSelfTest(void)
{
#if SAFETEY_MECHANISMS_ON

  if(!Safety_HasCoreTestHex()) {
    return;
  }
  m4_stl_main();

#endif
}

//static void restore_default(void)
static void set_defaultVal(void)
{
        int counter = 0;
        int offset = 0;

        while(counter <= m4_stl_test_param[4])
        {
          *(NVIC_IPR0_reg + offset) = 0;
          offset++;
          counter = counter + 4;
        }
        *SHPR1_reg = 0;
        *SHPR2_reg = 0;
        *SHPR3_reg = 0;

        /* set ICER registers to disable ALL IRQ */
        uint32_t dis_Value = 0xFFFFFFFF;
        *NVIC_ICER0_reg = dis_Value;
        *NVIC_ICER1_reg = dis_Value;
        *NVIC_ICER2_reg = dis_Value;
        *NVIC_ICER3_reg = dis_Value;
        *NVIC_ICER4_reg = dis_Value;
        *NVIC_ICER5_reg = dis_Value;
        *NVIC_ICER6_reg = dis_Value;
        *NVIC_ICER7_reg = dis_Value;
}


const uint8_t ol_next_module_index[STL_TOT_MODS_MAX] = {
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_0,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_1,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_2,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_3,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_4,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_5,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_6,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_7,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_8,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_9,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_10,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_11,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_12,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_13,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_14_A,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_14_B,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_14_C,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_A,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_B,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_C,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_D,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_16_A,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_16_B,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_17_A,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_17_B,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_17_C,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_18,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_19,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_20,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_21,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_22,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_23,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_24,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_25,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_26,
        STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_27
};

void Safety_StlOlTst(void)
{
    if(!Safety_HasCoreTestHexRes()) {
      return;
    }
    static boolean inited = false;
    if(!inited)
    {
        M4_STL_INIT_FUNC(STL_TMODE_OL_TIME, STL_RT_FIRST_MODULE_IDX);
        inited = true;
    }

    mods=SLT_TEST_MODS_NUM - 7; // 部分上电测试在周期测试中不能测试, 参照ol_next_module_index 中跳过的测试项

    result = M4_STL_FUNC(mods, STL_TMODE_OL_TIME, ol_next_module_index, NULL, NULL);
    /* Refresh watch dog */
    WDOG_Refresh();
    if(result != 1U) 
    {
      Safety_SetTestRes(SAFETY_STL_OL_TIME, SAFETY_ERROR);
      uint32 index = M4_STL_GET_LAST_EXECUTED_FUNC(STL_TMODE_OL_TIME);
      errorHandler();
    }
    Safety_SetTestRes(SAFETY_STL_OL_TIME, SAFETY_NORMAL);
}