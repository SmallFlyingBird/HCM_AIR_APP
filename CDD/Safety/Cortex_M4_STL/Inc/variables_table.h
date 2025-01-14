#ifndef VARIABLES_TABLE_H
#define VARIABLES_TABLE_H

#include <stdint.h>

/* Definitions of variables address for initialization */
#define STL_LAST_EXEC_ADDR                  0x20000000
#define STL_EXIT_FIRST_FAULT_ADDR           0x20000001
#define STL_FAIL_TEST_ADDR                  0x20000002

/* Definitions of variables address used in m4_stl_exceptions.c */
#define STL_IPSR_GOLDEN_VALUE_ADDR          0x20000008
#define STL_EXC_RESULT_ADDR                 0x20000018
#define STL_EXCEPTIONS_ADDR                 0x2000001c
#define STL_PHASE_ADDR                      0x20000022
#define STL_PRIORITY_LOW_IRQ_ADDR           0x20000024
#define STL_STAGE_PH_2_ADDR                 0x20000028
#define STL_TEST_NVIC_ADDR                  0x20000029

static uint8_t *const stl_last_exec_ptr = (uint8_t *)STL_LAST_EXEC_ADDR;
static uint8_t *const stl_exit_first_fault_ptr = (uint8_t *)STL_EXIT_FIRST_FAULT_ADDR;
static uint8_t *const stl_fail_test_ptr = (uint8_t *)STL_FAIL_TEST_ADDR;

static uint32_t *const stl_ipsr_golden_value_ptr = (uint32_t *)STL_IPSR_GOLDEN_VALUE_ADDR;
static uint32_t *const stl_exc_result_ptr = (uint32_t *)STL_EXC_RESULT_ADDR;
static uint32_t *const stl_exceptions_ptr = (uint32_t *)STL_EXCEPTIONS_ADDR;
static uint8_t *const stl_phase_ptr = (uint8_t *)STL_PHASE_ADDR;
static uint32_t *const stl_priority_low_irq_ptr = (uint32_t *)STL_PRIORITY_LOW_IRQ_ADDR;
static uint8_t *const stl_stage_ph_2_ptr = (uint8_t *)STL_STAGE_PH_2_ADDR;
static uint8_t *const stl_test_nvic_ptr = (uint8_t *)STL_TEST_NVIC_ADDR;

#endif
