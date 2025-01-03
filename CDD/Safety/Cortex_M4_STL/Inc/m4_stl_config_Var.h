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
 *
 *   About: TEST_ID
 *      N.A.
 *
 **************************************************************************************************/





#ifndef M4_STL_CONFIG_VAR_H
#define M4_STL_CONFIG_VAR_H

// #ifndef ASM

#include <stdint.h>

/* START User Configuration Section */

/* Comment out the following define only if the given module is neither used at run time or out of reset */
/* This is used to optimize code size */

/* MPU present state */
#define STL_MPU_PRESENT 0

/* total number of modules @ boot; including multiple calls for LUT modules */
#define STL_TOT_MODS_OOR 36
/* total number of modules @ run time; including multiple calls for LUT modules */
#define STL_TOT_MODS_RT 36

/* definition of oor sequence for scheduler, number of define MUST be the total number of module+1 */
/* The STL_xxx_NEXT_MODULE_IDX_AFTER_MODULE_x should be no more than 35
For Z20K14xMC, the STL_xxx_NEXT_MODULE_IDX_AFTER_MODULE_x should be be no more than 32 */
#define STL_OOR_FIRST_MODULE_IDX 0
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_0 1
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_1 2
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_2 3
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_3 4
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_4 5
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_5 6
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_6 7
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_7 8
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_8 9
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_9 10
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_10 11
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_11 12
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_12 13
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_13 14
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_14_A 15
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_14_B 16
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_14_C 17
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_A 18
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_B 19
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_C 20
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_15_D 21
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_16_A 22
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_16_B 23
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_17_A 24
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_17_B 25
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_17_C 26
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_18 27
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_19 28
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_20 29
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_21 30
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_22 31
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_23 32
#if STL_MPU_PRESENT == 1
  #define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_24 33
  #define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_25 34
  #define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_26 35
#else
  #define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_24 0
  #define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_25 0
  #define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_26 0
#endif
#define STL_OOR_NEXT_MODULE_IDX_AFTER_MODULE_27 0



/* definition of runtime (RT) sequence for scheduler, number of define MUST be the total number of module+1 */

#define STL_RT_FIRST_MODULE_IDX 0
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_0 1
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_1 3
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_2 3
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_3 5
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_4 5
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_5 6
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_6 8
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_7 8
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_8 9
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_9 10
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_10 11
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_11 12
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_12 13
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_13 14
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_14_A 15
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_14_B 16
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_14_C 17
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_A 18
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_B 19
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_C 20
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_15_D 21
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_16_A 22
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_16_B 23
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_17_A 24
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_17_B 25
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_17_C 26
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_18 29
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_19 28
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_20 29
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_21 0
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_22 0
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_23 0
#if STL_MPU_PRESENT == 1
  #define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_24 33
  #define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_25 34
  #define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_26 35
#else
  #define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_24 0
  #define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_25 0
  #define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_26 0
#endif
#define STL_RT_NEXT_MODULE_IDX_AFTER_MODULE_27 0

// #endif

/* BASEPRI max value read back from register after setting it with 0xFFFFFFFF, depending on HW configuration */
#define STL_BASEPRI_MAX        0x000000F0
/* SHPR1 max value read back from register after setting it with 0xFFFFFFFF, depending on HW configuration */
#define STL_SHPR1_MAX          0x00F0F0F0
/* SHPR2 max value read back from register after setting it with 0xFFFFFFFF, depending on HW configuration */
#define STL_SHPR2_MAX          0xF0000000
/* SHPR3 max value read back from register after setting it with 0xFFFFFFFF, depending on HW configuration */
#define STL_SHPR3_MAX          0xF0F000F0
/* CONTROL max value read back from register after setting it with 0xFFFFFFFF, depending on HW configuration */
#define STL_CONTROL_MAX        0x00000006
/* ACTLR max value read back from register after setting it with 0xFFFFFFFF, depending on HW configuration */
#define STL_ACTLR_MAX          0x00000307

/* Endianness configuration */
/* Set this constant to 1 for little endian configuration, set this one to 0 for big endian configuration */
#define STL_ENDIANNESS_TYPE 1

/* MPU configuration parameters */

/* MPU Total number of regions provided by HW configuration (must be 0 or 8) */
#define STL_MPU_NUM_REGION            8
/* MPU_TYPE register known value used on MPU registers test, to check read back value, depending on HW configuration */
#define STL_MPU_TYPE_VALUE            0x00000800
/* MPU_CTRL register known value used on MPU registers test, to check read back value, depending on HW configuration */
#define STL_MPU_CTRL_VALUE            0x00000007

/* End of MPU configuration parameters */


/* NVIC Configuration parameters */

/* TYPICAL Configuration */

#define STL_ISER_ISPR_LOOP_TH_1       0x00000008
#define STL_IPR_LOOP_TH_1             0x00000040

/* Considering Interrupt from 0 to 63 */
#define STL_NVIC_REG_OFFSET_1         0x00000000
#define STL_IPR_OFFSET_1              0x00000000

#define STL_ISER_ISPR_LOOP_TH_2       0x00000010
#define STL_IPR_LOOP_TH_2             0x00000080

/* Considering Interrupt from 64 to 127 */
#define STL_NVIC_REG_OFFSET_2         0x00000008
#define STL_IPR_OFFSET_2              0x00000040


#define STL_ISER_ISPR_LOOP_TH_3       0x0000001C
#define STL_IPR_LOOP_TH_3             0x000000D0

/* Considering Interrupt from 128 to 204 */
#define STL_NVIC_REG_OFFSET_3         0x00000010
#define STL_IPR_OFFSET_3              0x00000080

/* Do not define these for assembly files */
//#ifndef ASM

/* Default nvic & ipr register max value vector */
/* User can redefine their own vectors and pass into the function M4_STL_FUNC */
static const uint32_t STL_NVIC_REG_MAX_VALUE_VECT[7] =  {
  0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00001FFF};
static const uint32_t STL_IPR_MAX_VALUE_VECT[52] =  {
  0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0,
  0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0,
  0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0,
  0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0,
  0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0,
  0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0,
  0xF0F0F0F0, 0xF0F0F0F0, 0xF0F0F0F0, 0x000000F0};

//#endif

/* End of NVIC configuration parameters */

/* END User Configuration Section */

/* Do not define these for assembly files */
// #ifndef ASM

#define STL_TMODE_OOR      0
#define STL_TMODE_OL_TIME  1

/* total number of modules including multiple calls for LUT modules */
#define STL_TOT_MODS_MAX 36

// #endif

/* Registers Addresses necessary for exception tests */
#define STL_SHCSR             0xE000ED24
#define STL_SHPR1             0xE000ED18
#define STL_ICSR              0xE000ED04
#define STL_SCSR              0xE000E010
#define STL_Syst_CVR          0xE000E018
#define STL_SHCSR             0xE000ED24
#define STL_STIR              0xE000EF00

/* MPU register addresses */

#define STL_MPU_TYPE          0xE000ED90
#define STL_MPU_CTRL          0xE000ED94
#define STL_MPU_RNR           0xE000ED98
#define STL_MPU_RBAR          0xE000ED9C
#define STL_MPU_RASR          0xE000EDA0
#define STL_MPU_RBAR_A1       0xE000EDA4
#define STL_MPU_RBAR_A2       0xE000EDAC
#define STL_MPU_RBAR_A3       0xE000EDB4
#define STL_MPU_RASR_A1       0xE000EDA8
#define STL_MPU_RASR_A2       0xE000EDB0
#define STL_MPU_RASR_A3       0xE000EDB8

/* NVIC register addresses */

#define STL_NVIC_ISER         0xE000E100
#define STL_NVIC_ISPR         0xE000E200
#define STL_NVIC_IPR          0xE000E400
#define STL_NVIC_ICER         0xE000E180
#define STL_NVIC_ICPR         0xE000E280

/* Define addresses needed for registers test */

#define STL_ACTLR             0xE000E008
#define STL_VTOR              0xE000ED08
#define STL_AIRCR             0xE000ED0C
#define STL_SCR               0xE000ED10
#define STL_CCR               0xE000ED14
#define STL_SHPR1             0xE000ED18
#define STL_SHPR2             0xE000ED1C
#define STL_SHPR3             0xE000ED20
#define STL_SHCSR             0xE000ED24

/* MPU Constant for MPU_NUM_REGION = 0 signature cumulation (do not update) */
#define STL_MPU_CONSTANT      0xAAAAAAAA

/* MPU_RNR register known value used on MPU registers test, to check read back value, do not update */
#define STL_MPU_RNR_VALUE              0x00000007
/* MPU_RASR register known value used on MPU registers test, to check read back value, do not update */
#define STL_MPU_RASR_VALUE             0x1307003E
/* MPU_RBAR register known value used on MPU registers test, to check read back value, do not update */
#define STL_MPU_RBAR_VALUE             0xFFFFFFE0
/* Start region number parameter for m4_stl_mpu_p001_n001.s MPU registers test, do not update */
#define STL_REGION_NUM_START_MPU_02    0x00000000
/* Stop region number parameter for m4_stl_mpu_p001_n001.s MPU registers test, do not update */
#define STL_REGION_NUM_STOP_MPU_02     0x00000004
/* Start region number parameter for m4_stl_mpu_p002_n001.s MPU registers test, do not update */
#define STL_REGION_NUM_START_MPU_03    0x00000004
/* Stop region number parameter for m4_stl_mpu_p002_n001.s MPU registers test, do not update */
#define STL_REGION_NUM_STOP_MPU_03     0x00000008

#if STL_ENDIANNESS_TYPE == 1

/* AIRCR values for little endian configuration */
#define STL_AIRCR_VALUE_1     0xFA050700
#define STL_AIRCR_VALUE_2     0xFA050000

#elif STL_ENDIANNESS_TYPE == 0
/* AIRCR values for big endian configuration */
#define STL_AIRCR_VALUE_1     0xFA058700
#define STL_AIRCR_VALUE_2     0xFA058000

#endif

#endif
