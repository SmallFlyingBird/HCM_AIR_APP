/**************************************************************************************************/
/**
 * @file      : Cmu_MemMap.h
 * @brief     : AUTOSAR Cmu MemMap header file. It specifies mechanisms for the mapping of code
 *              and data to specific memory sections. This file only contains example code.
 *              This file must be updated depending on the integrating environment.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Base_Module
 *  @{
 */

/** @addtogroup  MemMap
 *  @{
 */

/** @defgroup Cmu_MemMap
 *  @brief Cmu MemMap header file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib_Compiler.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* published information */
#define CMU_MEMMAP_VENDOR_ID                   0x00B3U
#define CMU_MEMMAP_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_MEMMAP_AR_RELEASE_MINOR_VERSION    6U
#define CMU_MEMMAP_AR_RELEASE_REVISION_VERSION 0U
#define CMU_MEMMAP_SW_MAJOR_VERSION            1U
#define CMU_MEMMAP_SW_MINOR_VERSION            1U
#define CMU_MEMMAP_SW_PATCH_VERSION            0U

/** @} end of Public_MacroDefinition */

#define MEMMAP_ERROR

#ifdef AUTOSAR_OS_USED
    #include "Os_memmap.h"
#endif

/********************************************* IAR ************************************************/
#if defined(_IAR_C_Z20K14XM_)
    #ifdef CMU_START_SEC_CONFIG_DATA_8
        #undef CMU_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_8
        #undef CMU_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_16
        #undef CMU_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_16
        #undef CMU_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_32
        #undef CMU_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_32
        #undef CMU_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_PTR
        #undef CMU_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_PTR
        #undef CMU_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONST_BOOLEAN
        #undef CMU_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_BOOLEAN
        #undef CMU_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONST_8
        #undef CMU_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_8
        #undef CMU_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONST_16
        #undef CMU_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_16
        #undef CMU_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONST_32
        #undef CMU_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_32
        #undef CMU_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONST_PTR
        #undef CMU_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_PTR
        #undef CMU_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CONST_UNSPECIFIED
        #undef CMU_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_UNSPECIFIED
        #undef CMU_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_CODE
        #undef CMU_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes = @ ".mcal_code"
    #endif

    #ifdef CMU_STOP_SEC_CODE
        #undef CMU_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes =
    #endif

    #ifdef CMU_START_SEC_RAMCODE
        #undef CMU_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes = @ ".mcal_ramcode"
    #endif

    #ifdef CMU_STOP_SEC_RAMCODE
        #undef CMU_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_BOOLEAN
        #undef CMU_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef CMU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_8
        #undef CMU_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_8
        #undef CMU_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_16
        #undef CMU_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_16
        #undef CMU_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_32
        #undef CMU_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_32
        #undef CMU_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_PTR
        #undef CMU_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_PTR
        #undef CMU_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef CMU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef CMU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef CMU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef CMU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_8
        #undef CMU_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_8
        #undef CMU_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_16
        #undef CMU_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_16
        #undef CMU_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_32
        #undef CMU_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_32
        #undef CMU_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_PTR
        #undef CMU_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_PTR
        #undef CMU_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CMU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CMU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

/********************************************* GCC ************************************************/
#elif defined(_GNU_C_Z20K14XM_)
    #ifdef CMU_START_SEC_CONFIG_DATA_8
        #undef CMU_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_8
        #undef CMU_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_16
        #undef CMU_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_16
        #undef CMU_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_32
        #undef CMU_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_32
        #undef CMU_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_PTR
        #undef CMU_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_PTR
        #undef CMU_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONST_BOOLEAN
        #undef CMU_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_BOOLEAN
        #undef CMU_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONST_8
        #undef CMU_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_8
        #undef CMU_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONST_16
        #undef CMU_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_16
        #undef CMU_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONST_32
        #undef CMU_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_32
        #undef CMU_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONST_PTR
        #undef CMU_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_PTR
        #undef CMU_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CONST_UNSPECIFIED
        #undef CMU_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_UNSPECIFIED
        #undef CMU_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef CMU_START_SEC_CODE
        #undef CMU_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma GCC section text ".mcal_code"
    #endif

    #ifdef CMU_STOP_SEC_CODE
        #undef CMU_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma GCC section text
    #endif

    #ifdef CMU_START_SEC_RAMCODE
        #undef CMU_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma GCC section text ".mcal_ramcode"
    #endif

    #ifdef CMU_STOP_SEC_RAMCODE
        #undef CMU_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma GCC section text
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_BOOLEAN
        #undef CMU_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef CMU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_8
        #undef CMU_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_8
        #undef CMU_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_16
        #undef CMU_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_16
        #undef CMU_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_32
        #undef CMU_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_32
        #undef CMU_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_PTR
        #undef CMU_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_PTR
        #undef CMU_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef CMU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef CMU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef CMU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef CMU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_8
        #undef CMU_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_8
        #undef CMU_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_16
        #undef CMU_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_16
        #undef CMU_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_32
        #undef CMU_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_32
        #undef CMU_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_PTR
        #undef CMU_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_PTR
        #undef CMU_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CMU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CMU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

/***************************************** GreenHills *********************************************/
#elif defined(_GHS_C_Z20K14XM_)
    #ifdef CMU_START_SEC_CONFIG_DATA_8
        #undef CMU_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_8
        #undef CMU_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_16
        #undef CMU_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_16
        #undef CMU_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_32
        #undef CMU_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_32
        #undef CMU_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_PTR
        #undef CMU_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_PTR
        #undef CMU_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONST_BOOLEAN
        #undef CMU_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_BOOLEAN
        #undef CMU_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONST_8
        #undef CMU_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_8
        #undef CMU_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONST_16
        #undef CMU_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_16
        #undef CMU_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONST_32
        #undef CMU_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_32
        #undef CMU_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONST_PTR
        #undef CMU_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_PTR
        #undef CMU_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CONST_UNSPECIFIED
        #undef CMU_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CMU_STOP_SEC_CONST_UNSPECIFIED
        #undef CMU_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_CODE
        #undef CMU_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma ghs section text = ".mcal_code"
    #endif

    #ifdef CMU_STOP_SEC_CODE
        #undef CMU_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_RAMCODE
        #undef CMU_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma ghs section text = ".mcal_ramcode"
        #pragma ghs         inlineprologue
        #pragma ghs         callmode = far
    #endif

    #ifdef CMU_STOP_SEC_RAMCODE
        #undef CMU_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma ghs section
        #pragma ghs inlineprologue
        #pragma ghs callmode = far
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_BOOLEAN
        #undef CMU_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef CMU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_8
        #undef CMU_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_8
        #undef CMU_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_16
        #undef CMU_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_16
        #undef CMU_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_32
        #undef CMU_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_32
        #undef CMU_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_PTR
        #undef CMU_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_PTR
        #undef CMU_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef CMU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CMU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef CMU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef CMU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef CMU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_8
        #undef CMU_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_8
        #undef CMU_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_16
        #undef CMU_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_16
        #undef CMU_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_32
        #undef CMU_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_32
        #undef CMU_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_PTR
        #undef CMU_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_PTR
        #undef CMU_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CMU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CMU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CMU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CMU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

#endif

/****************************************** Report error ******************************************/
#ifdef MEMMAP_ERROR
    #error "MemMap.h, no valid memory mapping symbol defined."
#endif

#ifdef __cplusplus
}
#endif

/** @} end of group Cmu_MemMap */

/** @} end of group MemMap */

/* MISRA2012 Dir-4.10 violation: Include file code is not protected against repeated inclusion. 
Memmap header usage complies to Autosar guidelines */
/** @} end of group Base_Module */
