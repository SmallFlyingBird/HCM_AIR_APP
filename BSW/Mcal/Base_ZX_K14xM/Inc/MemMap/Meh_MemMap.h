/**************************************************************************************************/
/**
 * @file      : Meh_MemMap.h
 * @brief     : AUTOSAR Meh MemMap header file. It specifies mechanisms for the mapping of code
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

/** @defgroup Meh_MemMap
 *  @brief Meh MemMap header file
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
#define MEH_MEMMAP_VENDOR_ID                   0x00B3U
#define MEH_MEMMAP_AR_RELEASE_MAJOR_VERSION    4U
#define MEH_MEMMAP_AR_RELEASE_MINOR_VERSION    6U
#define MEH_MEMMAP_AR_RELEASE_REVISION_VERSION 0U
#define MEH_MEMMAP_SW_MAJOR_VERSION            1U
#define MEH_MEMMAP_SW_MINOR_VERSION            1U
#define MEH_MEMMAP_SW_PATCH_VERSION            0U

/** @} end of Public_MacroDefinition */

#define MEMMAP_ERROR

#ifdef AUTOSAR_OS_USED
    #include "Os_memmap.h"
#endif

/********************************************* IAR ************************************************/
#if defined(_IAR_C_Z20K14XM_)
    #ifdef MEH_START_SEC_CONFIG_DATA_8
        #undef MEH_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_8
        #undef MEH_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_16
        #undef MEH_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_16
        #undef MEH_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_32
        #undef MEH_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_32
        #undef MEH_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_PTR
        #undef MEH_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_PTR
        #undef MEH_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONST_BOOLEAN
        #undef MEH_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_BOOLEAN
        #undef MEH_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONST_8
        #undef MEH_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_8
        #undef MEH_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONST_16
        #undef MEH_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_16
        #undef MEH_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONST_32
        #undef MEH_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_32
        #undef MEH_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONST_PTR
        #undef MEH_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_PTR
        #undef MEH_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CONST_UNSPECIFIED
        #undef MEH_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_UNSPECIFIED
        #undef MEH_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_CODE
        #undef MEH_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes = @ ".mcal_code"
    #endif

    #ifdef MEH_STOP_SEC_CODE
        #undef MEH_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes =
    #endif

    #ifdef MEH_START_SEC_RAMCODE
        #undef MEH_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes = @ ".mcal_ramcode"
    #endif

    #ifdef MEH_STOP_SEC_RAMCODE
        #undef MEH_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_BOOLEAN
        #undef MEH_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEH_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_8
        #undef MEH_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_8
        #undef MEH_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_16
        #undef MEH_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_16
        #undef MEH_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_32
        #undef MEH_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_32
        #undef MEH_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_PTR
        #undef MEH_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_PTR
        #undef MEH_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEH_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEH_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEH_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEH_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_8
        #undef MEH_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_8
        #undef MEH_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_16
        #undef MEH_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_16
        #undef MEH_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_32
        #undef MEH_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_32
        #undef MEH_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_PTR
        #undef MEH_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_PTR
        #undef MEH_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEH_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

/********************************************* GCC ************************************************/
#elif defined(_GNU_C_Z20K14XM_)
    #ifdef MEH_START_SEC_CONFIG_DATA_8
        #undef MEH_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_8
        #undef MEH_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_16
        #undef MEH_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_16
        #undef MEH_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_32
        #undef MEH_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_32
        #undef MEH_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_PTR
        #undef MEH_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_PTR
        #undef MEH_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONST_BOOLEAN
        #undef MEH_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_BOOLEAN
        #undef MEH_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONST_8
        #undef MEH_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_8
        #undef MEH_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONST_16
        #undef MEH_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_16
        #undef MEH_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONST_32
        #undef MEH_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_32
        #undef MEH_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONST_PTR
        #undef MEH_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_PTR
        #undef MEH_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CONST_UNSPECIFIED
        #undef MEH_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_UNSPECIFIED
        #undef MEH_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section rodata
    #endif

    #ifdef MEH_START_SEC_CODE
        #undef MEH_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma GCC section text ".mcal_code"
    #endif

    #ifdef MEH_STOP_SEC_CODE
        #undef MEH_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma GCC section text
    #endif

    #ifdef MEH_START_SEC_RAMCODE
        #undef MEH_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma GCC section text ".mcal_ramcode"
    #endif

    #ifdef MEH_STOP_SEC_RAMCODE
        #undef MEH_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma GCC section text
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_BOOLEAN
        #undef MEH_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEH_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_8
        #undef MEH_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_8
        #undef MEH_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_16
        #undef MEH_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_16
        #undef MEH_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_32
        #undef MEH_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_32
        #undef MEH_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_PTR
        #undef MEH_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_PTR
        #undef MEH_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEH_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section data ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEH_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section data
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEH_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEH_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_8
        #undef MEH_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_8
        #undef MEH_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_16
        #undef MEH_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_16
        #undef MEH_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_32
        #undef MEH_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_32
        #undef MEH_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_PTR
        #undef MEH_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_PTR
        #undef MEH_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEH_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section bss ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma GCC section bss
    #endif

/***************************************** GreenHills *********************************************/
#elif defined(_GHS_C_Z20K14XM_)
    #ifdef MEH_START_SEC_CONFIG_DATA_8
        #undef MEH_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_8
        #undef MEH_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_16
        #undef MEH_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_16
        #undef MEH_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_32
        #undef MEH_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_32
        #undef MEH_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_PTR
        #undef MEH_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_PTR
        #undef MEH_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONST_BOOLEAN
        #undef MEH_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_BOOLEAN
        #undef MEH_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONST_8
        #undef MEH_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_8
        #undef MEH_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONST_16
        #undef MEH_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_16
        #undef MEH_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONST_32
        #undef MEH_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_32
        #undef MEH_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONST_PTR
        #undef MEH_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_PTR
        #undef MEH_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CONST_UNSPECIFIED
        #undef MEH_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef MEH_STOP_SEC_CONST_UNSPECIFIED
        #undef MEH_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_CODE
        #undef MEH_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma ghs section text = ".mcal_code"
    #endif

    #ifdef MEH_STOP_SEC_CODE
        #undef MEH_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_RAMCODE
        #undef MEH_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma ghs section text = ".mcal_ramcode"
        #pragma ghs         inlineprologue
        #pragma ghs         callmode = far
    #endif

    #ifdef MEH_STOP_SEC_RAMCODE
        #undef MEH_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma ghs section
        #pragma ghs inlineprologue
        #pragma ghs callmode = far
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_BOOLEAN
        #undef MEH_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEH_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_8
        #undef MEH_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_8
        #undef MEH_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_16
        #undef MEH_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_16
        #undef MEH_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_32
        #undef MEH_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_32
        #undef MEH_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_PTR
        #undef MEH_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_PTR
        #undef MEH_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEH_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef MEH_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEH_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEH_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEH_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_8
        #undef MEH_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_8
        #undef MEH_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_16
        #undef MEH_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_16
        #undef MEH_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_32
        #undef MEH_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_32
        #undef MEH_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_PTR
        #undef MEH_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_PTR
        #undef MEH_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef MEH_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEH_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef MEH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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

/** @} end of group Meh_MemMap */

/** @} end of group MemMap */
/* MISRA2012 Dir-4.10 violation: Include file code is not protected against repeated inclusion. 
Memmap header usage complies to Autosar guidelines */
/** @} end of group Base_Module */
