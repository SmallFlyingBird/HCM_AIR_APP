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
 *      Description of all exception handlers and vector table
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



/* This file contains the default exception handlers and vector table.
   All exceptions are handled in Handler mode.  Processor state is automatically
   pushed onto the stack when an exception occurs, and popped from the stack at
   the end of the handler */

/* Exception Handlers */
/* Marking as __attribute__((interrupt)) avoids them being accidentally called from elsewhere */
#include <stdio.h>
#include "m4_stl_config_Var.h"
#include "m4_stl_nvic_auxiliary_functions.h"
#include "variables_table.h"
#include "ghs_compatible.h"
#include "functions_table_0x001f_3500.h"
#if defined( __ICCARM__ )
  #define INTERRUPT_FUNC   
  extern uint32_t CSTACK$$Limit;
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
/* If arm compiler is used, ARM_LIB_STACK shall be defined in linker file */
/* ARM_LIB_STACK is the main stack section */
  #define INTERRUPT_FUNC   __attribute__((interrupt))
  extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Limit;
#elif defined(__ghs__)
  #define INTERRUPT_FUNC   
  extern uint32_t __stack_end__;
#endif

extern void Reset_Handler(void);

void Strobe_Handler(void);
void NVIC_Test_Handler(void);

INTERRUPT_FUNC void NMIException(void) {

        uint32 index = M4_STL_GET_LAST_EXECUTED_FUNC(STL_TMODE_OOR);
        if ((*stl_exceptions_ptr) == 1) {
            (*stl_exceptions_ptr) = 0;
            /* Init control flow value */
            uint32_t control_flow_value = 0xC31B64AC;
            /* rotate result right of 1 bit */
            uint32_t temp_exc_result= (*stl_exc_result_ptr);
            (*stl_exc_result_ptr) = (temp_exc_result << 1) | (temp_exc_result >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;

        } else if ((*stl_test_nvic_ptr) == 1){

            (*stl_test_nvic_ptr) = 0;

            /* Testing pending tree */
            if((*stl_phase_ptr) < 2){

                /* Get IPSR register current value */
                uint32_t reg_IPSR_value = __get_IPSR();

                /* Check if IPSR value is compliant with the expected one */
                if(reg_IPSR_value == (*stl_ipsr_golden_value_ptr)){
                    (*stl_exc_result_ptr) = 1;
                }else{
                    (*stl_exc_result_ptr) = 0;
                }

                /* Disable interrupts */
                __disable_irq();

            /* Testing active tree */
            }else{

                /* Set lowest priority IRQ/exception to pending state */
                STL_NVIC_Set_Pending(*stl_priority_low_irq_ptr);

            }

        } else {

            Strobe_Handler();

        }

}

INTERRUPT_FUNC void HardFaultException(void) {
        if ((*stl_exceptions_ptr) == 1) {
            (*stl_exceptions_ptr) = 0;
            /* Init control flow value */
            uint32_t control_flow_value = 0x3FFE406A;
            /* rotate result right of 1 bit */
            uint32_t temp_exc_result= (*stl_exc_result_ptr);
            (*stl_exc_result_ptr) = (temp_exc_result << 1) | (temp_exc_result >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;
        } else {

            Strobe_Handler();
        }
}

INTERRUPT_FUNC void MemManageException(void) {

#if STL_MPU_PRESENT == 1
        if((*stl_exceptions_ptr) == 1){
            
            /* disable mpu */
            uint32_t* stl_mpu_ctrl_p = (uint32_t*) STL_MPU_CTRL;
            *stl_mpu_ctrl_p = 0x0;

            (*stl_exceptions_ptr) = 0;

            /* Init control flow value */
            uint32_t control_flow_value = 0x5A7816BC;
            /* rotate result right of 1 bit */
            (*stl_exc_result_ptr) = ((*stl_exc_result_ptr) << 1) | ((*stl_exc_result_ptr) >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;


        } else
#endif
        if((*stl_test_nvic_ptr) == 1){

            NVIC_Test_Handler();

        } else {

            Strobe_Handler();
        }
}

INTERRUPT_FUNC void BusFaultException(void) {
        if ((*stl_exceptions_ptr) == 1) {
            (*stl_exceptions_ptr) = 0;
            /* Init control flow value */
            uint32_t control_flow_value = 0xDD386CCA;
            /* rotate result right of 1 bit */
            uint32_t temp_exc_result= (*stl_exc_result_ptr);
            (*stl_exc_result_ptr) = (temp_exc_result << 1) | (temp_exc_result >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;

        } else if((*stl_test_nvic_ptr) == 1){

            NVIC_Test_Handler();

        } else {

            Strobe_Handler();
        }
}

INTERRUPT_FUNC void UsageFaultException(void) {
        if ((*stl_exceptions_ptr) == 1) {
            (*stl_exceptions_ptr) = 0;
            /* Init control flow value */
            uint32_t control_flow_value = 0x39701C68;
            /* rotate result right of 1 bit */
            uint32_t temp_exc_result= (*stl_exc_result_ptr);
            (*stl_exc_result_ptr) = (temp_exc_result << 1) | (temp_exc_result >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;

        } else if((*stl_test_nvic_ptr) == 1){

            NVIC_Test_Handler();

        } else {

            Strobe_Handler();
        }
}

INTERRUPT_FUNC void DebugMonitor(void) {
        Strobe_Handler();
}

INTERRUPT_FUNC void SVCHandler(void) {
        if ((*stl_exceptions_ptr) == 1) {
            (*stl_exceptions_ptr) = 0;
            /* Init control flow value */
            uint32_t control_flow_value = 0x98554100;
            /* rotate result right of 1 bit */
            uint32_t temp_exc_result= (*stl_exc_result_ptr);
            (*stl_exc_result_ptr) = (temp_exc_result << 1) | (temp_exc_result >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;

        } else if((*stl_test_nvic_ptr) == 1){

            NVIC_Test_Handler();

        } else {

            Strobe_Handler();
        }
}

INTERRUPT_FUNC void PendSV(void) {
        if ((*stl_exceptions_ptr) == 1) {
            (*stl_exceptions_ptr) = 0;
            /* Init control flow value */
            uint32_t control_flow_value = 0x9788AC46;
            /* rotate result right of 1 bit */
            uint32_t temp_exc_result= (*stl_exc_result_ptr);
            (*stl_exc_result_ptr) = (temp_exc_result << 1) | (temp_exc_result >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;

        } else if((*stl_test_nvic_ptr) == 1){

            NVIC_Test_Handler();

        } else {

            Strobe_Handler();
        }
}

INTERRUPT_FUNC void SysTickHandler(void){
        if ((*stl_exceptions_ptr) == 1) {
            (*stl_exceptions_ptr) = 0;
            /* Init control flow value */
            uint32_t control_flow_value = 0xBD21CE34;
            /* rotate result right of 1 bit */
            uint32_t temp_exc_result= (*stl_exc_result_ptr);
            (*stl_exc_result_ptr) = (temp_exc_result << 1) | (temp_exc_result >> (32 - 1));
            /* add control flow value to result */
            (*stl_exc_result_ptr) += control_flow_value;
        } else if((*stl_test_nvic_ptr) == 1){

            NVIC_Test_Handler();

        } else {

            Strobe_Handler();
        }
}

INTERRUPT_FUNC void InterruptHandler(void) {

        if((*stl_test_nvic_ptr) == 1){

            NVIC_Test_Handler();

        } else {

            Strobe_Handler();
        }
}

void NVIC_Test_Handler() {

/* Phase 2, Stage 1: triggering high priority exception/irq */
        if(((*stl_phase_ptr) == 2)&&((*stl_stage_ph_2_ptr) == 1)){

            /* Set Stage 2 */
            (*stl_stage_ph_2_ptr) = 2;

            int exc_num = (*stl_ipsr_golden_value_ptr) - 16;

            /* Set pending exception/irq to execute preemption */
            STL_NVIC_Set_Pending(exc_num);

            /* Dummy cycle to wait preemption */
            while((*stl_stage_ph_2_ptr) == 2);

        /* Phase 2, Stage 2 or Phase 3: triggering NMI */
        }else if((((*stl_phase_ptr) == 2)&&((*stl_stage_ph_2_ptr) == 2))||((*stl_phase_ptr) == 3)){

            int exc_num = -14;

            /* Triggering NMI exception */
            STL_NVIC_Set_Pending(exc_num);

            /* Dummy cycle to wait preemption */
            while((*stl_test_nvic_ptr) == 1);

            /* Selecting only [21:12] VECTPENDING bits */
            uint32_t pending_irq_n = STL_Get_ICSR();
            pending_irq_n &= 0x003FF000;
            pending_irq_n = pending_irq_n >> 12;

            /* Check if lowest priority IRQ/exception is already on pending state */
            if(pending_irq_n == ((*stl_priority_low_irq_ptr) + 16)){
                (*stl_exc_result_ptr) = 1;
            }else{
                (*stl_exc_result_ptr) = 0;
            }

            /* Clean pending IRQ/exception with lowest priority */
            STL_NVIC_Clear_Pending(*stl_priority_low_irq_ptr);

            /* Return to previous stage */
            (*stl_stage_ph_2_ptr) = 1;

        /* In other cases we are on pending tree test */
        }else{

            /* Get IPSR register current value */
            uint32_t reg_IPSR_value = __get_IPSR();

            /* Check if IPSR value is compliant with the expected one */
            if(reg_IPSR_value == (*stl_ipsr_golden_value_ptr)){
                (*stl_exc_result_ptr) = 1;
            }else{
                (*stl_exc_result_ptr) = 0;
            }

            /* Disable interrupts */
            __disable_irq();
        }

        (*stl_test_nvic_ptr) = 0;

}


void Strobe_Handler() {

        __asm ("NOP");
        __asm ("NOP");
        __asm ("NOP");
        __asm ("NOP");
        while (1);

}

/* typedef for the function pointers in the vector table */
typedef void (* const ExecFuncPtr)(void)   INTERRUPT_FUNC ;

/* Vector table */
/* Create a named ELF section for the vector table that can be placed in a linker file. */
/* The first two entries are: */
/* Initial SP  */
/* Initial PC */

#if defined( __ICCARM__ )
#pragma location = "test_vectors"
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
__attribute__((section("test_vectors")))
#elif defined(__ghs__)
__attribute__((section(".test_vectors")))
#endif

ExecFuncPtr test_vector_table[] = {
/* Configure Initial Stack Pointer using linker-generated symbol */
#if defined( __ICCARM__ )
        (ExecFuncPtr) &CSTACK$$Limit,
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
        (ExecFuncPtr) &Image$$ARM_LIB_STACK$$ZI$$Limit,
#elif defined(__ghs__)
        (ExecFuncPtr) &__stack_end__,
#endif
        /* Initial PC, set to entry point */
        Reset_Handler,
        NMIException, HardFaultException, MemManageException, BusFaultException,
        /* Reserved */
        UsageFaultException, 0, 0, 0, 0,
        /* Reserved */
        SVCHandler, DebugMonitor, 0, PendSV, SysTickHandler,
        /* For Z20K14xM, add up to 205 interrupt handlers(0-204), starting here... */
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler, InterruptHandler, InterruptHandler, InterruptHandler,
        InterruptHandler

};
