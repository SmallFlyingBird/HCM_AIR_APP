#ifndef FUNCTIONS_TABLE_H
#define FUNCTIONS_TABLE_H

#include <stdint.h>

#define STL_FUNC_BASE                       0x000f3500U
#define STL_OFFSET_M4_STL                   0x00U
#define STL_OFFSET_M4_STL_INIT              0x04U
#define STL_OFFSET_M4_STL_GET_LAST_EXECUTED 0x08U
#define STL_OFFSET_M4_STL_NVIC              0x0CU
#define STL_OFFSET_M4_STL_NVIC_INIT         0x10U

/* Definitions of api address*/
#define M4_STL_FUNC_ADDR        (*(uint32_t *)(STL_FUNC_BASE + STL_OFFSET_M4_STL))
#define M4_STL_INIT_FUNC_ADDR   (*(uint32_t *)(STL_FUNC_BASE + STL_OFFSET_M4_STL_INIT))
#define M4_STL_GET_LAST_EXECUTED_FUNC_ADDR                                                         \
                                (*(uint32_t *)(STL_FUNC_BASE + STL_OFFSET_M4_STL_GET_LAST_EXECUTED))
#define M4_STL_NVIC_FUNC_ADDR      (*(uint32_t *)(STL_FUNC_BASE + STL_OFFSET_M4_STL_NVIC))
#define M4_STL_NVIC_INIT_FUNC_ADDR (*(uint32_t *)(STL_FUNC_BASE + STL_OFFSET_M4_STL_NVIC_INIT))

/**
 * @brief      It points to a function which is a library scheduler
 *
 * @param[in]  mods: Specify the total number of STL modules have to be executed
 * @param[in]  mode: Specify the test mode
 *                    0 - Out of Reset test mode
 *                    1 - Online test mode
 * @param[in]  next_module_index: It points to a table that indicates
 *                                  the next module index for each module.
 * @param[in]  nvic_reg_max_value_vect: It points to a vector that indicates NVIC register max value
 * @param[in]  ipr_max_value_vect: It points to a vector that indicates IPR register max value
 *
 * @return     uint8_t
 * @retval     0: At least one executed module failed.
 * @retval     1: All executed modules passed.
 * @retval     2: The input parameter mods is out-of-range.
 * @retval     3: The executing device is invalid.
 *
 */
typedef uint8_t (*m4_stl_ptr)(uint8_t mods, uint8_t mode, const uint8_t next_module_index[],
                              const uint32_t nvic_reg_max_value_vect[],
                              const uint32_t ipr_max_value_vect[]);

/**
 * @brief      It points to a function that initializes index of module execution
 *             It Initialize the different data structures that are needed for correct
 *             execution of M4_STL test, and resets the pointer to the next part to execute.
 *
 * @param[in]  oor_rt_mode: Specify the test mode
 *                           0 - Out of Reset test mode
 *                           1 - Online test mode
 * @param[in]  first_module_idx: The first module index to be executed
 *
 * @return     None
 *
 *
 */
typedef void (*m4_stl_init_ptr)(uint8_t oor_rt_mode, uint8_t first_module_idx);

/**
 * @brief      It points to a function that returns last executed module ID
 *
 * @param[in]  oor_rt_mode: Specify the test mode
 *                           0 - Out of Reset test mode
 *                           1 - Online test mode
 *
 * @return     uint8_t
 *
 */
typedef uint8_t (*m4_stl_get_last_executed_ptr)(uint8_t oor_rt_mode);

/**
 * @brief      It points to a function for NVIC pending and active tree test
 *
 * @param[in]  tot_test_step: Number of tests to be executed
 * @param[in]  next_irq_index: It points to a table that indicates the next irq index for each irq.
 * @param[in]  test_param: It points to a table that indicates parameters of
 *                                          NVIC pending and active tree test
 *                   - test_param[0]: STL_TEST_MAX_STEPS 
 *                              - number of necessary tests to fulfill phases from 0 to 3 completely
 *                   - test_param[1]: STL_PHASE_0_LAST 
 *                              - number of tests to fulfill pending tree phase 0 completely
 *                   - test_param[2]: STL_PHASE_1_LAST 
 *                              - number of tests to fulfill pending tree phase 1 completely
 *                   - test_param[3]: STL_PHASE_2_LAST 
 *                              - number of tests to fulfill active tree phase 2 completely
 *                   - test_param[4]: STL_IRQMAX - IRQ maximum index value
 *
 * @return     uint8_t
 * @retval     0: At least one executed test failed.
 * @retval     1: All executed tests passed.
 * @retval     2: The input parameter tot_test_step is out-of-range.
 * @retval     3: The executing device is invalid.
 *
 */
typedef uint8_t (*m4_stl_nvic_ptr)(uint32_t tot_test_step, const uint32_t next_irq_index[],
                                   const uint32_t test_param[5]);

/**
 * @brief      It points to a function that initializes for STL NVIC global variables
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
typedef void (*m4_stl_nvic_init_ptr)(void);

#define M4_STL_FUNC             ((m4_stl_ptr)(M4_STL_FUNC_ADDR))
#define M4_STL_INIT_FUNC        ((m4_stl_init_ptr)(M4_STL_INIT_FUNC_ADDR))
#define M4_STL_GET_LAST_EXECUTED_FUNC                                                              \
                                ((m4_stl_get_last_executed_ptr)(M4_STL_GET_LAST_EXECUTED_FUNC_ADDR))
#define M4_STL_NVIC_FUNC        ((m4_stl_nvic_ptr)(M4_STL_NVIC_FUNC_ADDR))
#define M4_STL_NVIC_INIT_FUNC   ((m4_stl_nvic_init_ptr)(M4_STL_NVIC_INIT_FUNC_ADDR))

#endif
