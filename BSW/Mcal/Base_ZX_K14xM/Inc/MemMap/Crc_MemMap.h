/**************************************************************************************************/
/**
 * @file      : Crc_MemMap.h
 * @brief     : AUTOSAR Crc MemMap header file. It specifies mechanisms for the mapping of code
 *              and data to specific memory sections. This file only contains example code.
 *              This file must be updated depending on the integrating environment.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Base_Module
 *  @{
 */

/** @addtogroup  MemMap
 *  @{
 */

/** @defgroup Crc_MemMap
 *  @brief Crc MemMap header file
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
#define CRC_MEMMAP_VENDOR_ID                   0x00B3U
#define CRC_MEMMAP_AR_RELEASE_MAJOR_VERSION    4U
#define CRC_MEMMAP_AR_RELEASE_MINOR_VERSION    6U
#define CRC_MEMMAP_AR_RELEASE_REVISION_VERSION 0U
#define CRC_MEMMAP_SW_MAJOR_VERSION            1U
#define CRC_MEMMAP_SW_MINOR_VERSION            2U
#define CRC_MEMMAP_SW_PATCH_VERSION            2U

/** @} end of Public_MacroDefinition */

#define MEMMAP_ERROR

/********************************************* IAR ************************************************/
#if defined(_IAR_C_Z20K14XM_)
    #ifdef CRC_START_SEC_CONFIG_DATA_8
        #undef CRC_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_8
        #undef CRC_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_16
        #undef CRC_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_16
        #undef CRC_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_32
        #undef CRC_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_32
        #undef CRC_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_PTR
        #undef CRC_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_PTR
        #undef CRC_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONST_BOOLEAN
        #undef CRC_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_BOOLEAN
        #undef CRC_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONST_8
        #undef CRC_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_8
        #undef CRC_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONST_16
        #undef CRC_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_16
        #undef CRC_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONST_32
        #undef CRC_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_32
        #undef CRC_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONST_PTR
        #undef CRC_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_PTR
        #undef CRC_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CONST_UNSPECIFIED
        #undef CRC_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_UNSPECIFIED
        #undef CRC_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_CODE
        #undef CRC_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes = @ ".mcal_code"
    #endif

    #ifdef CRC_STOP_SEC_CODE
        #undef CRC_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes =
    #endif

    #ifdef CRC_START_SEC_RAMCODE
        #undef CRC_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes = @ ".mcal_ramcode"
    #endif

    #ifdef CRC_STOP_SEC_RAMCODE
        #undef CRC_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma default_function_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_BOOLEAN
        #undef CRC_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_BOOLEAN
        #undef CRC_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_8
        #undef CRC_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_8
        #undef CRC_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_16
        #undef CRC_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_16
        #undef CRC_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_32
        #undef CRC_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_32
        #undef CRC_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_PTR
        #undef CRC_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_PTR
        #undef CRC_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_UNSPECIFIED
        #undef CRC_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_BOOLEAN
        #undef CRC_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef CRC_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_8
        #undef CRC_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_8
        #undef CRC_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_16
        #undef CRC_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_16
        #undef CRC_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_32
        #undef CRC_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_32
        #undef CRC_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_PTR
        #undef CRC_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_PTR
        #undef CRC_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CRC_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma default_variable_attributes =
    #endif

/********************************************* ARM clang ************************************************/
#elif defined(_ARMCLANG_C_Z20K14XM_)
    #ifdef CRC_START_SEC_CONFIG_DATA_8
        #undef CRC_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_8
        #undef CRC_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_16
        #undef CRC_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_16
        #undef CRC_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_32
        #undef CRC_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_32
        #undef CRC_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_PTR
        #undef CRC_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_PTR
        #undef CRC_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONST_BOOLEAN
        #undef CRC_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_BOOLEAN
        #undef CRC_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONST_8
        #undef CRC_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_8
        #undef CRC_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONST_16
        #undef CRC_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_16
        #undef CRC_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONST_32
        #undef CRC_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_32
        #undef CRC_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONST_PTR
        #undef CRC_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_PTR
        #undef CRC_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CONST_UNSPECIFIED
        #undef CRC_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section rodata=".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_UNSPECIFIED
        #undef CRC_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section rodata=""
    #endif

    #ifdef CRC_START_SEC_CODE
        #undef CRC_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma clang section text=".mcal_code"
    #endif

    #ifdef CRC_STOP_SEC_CODE
        #undef CRC_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma clang section text=""
    #endif

    #ifdef CRC_START_SEC_RAMCODE
        #undef CRC_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma clang section text=".mcal_ramcode"
    #endif

    #ifdef CRC_STOP_SEC_RAMCODE
        #undef CRC_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma clang section text=""
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_BOOLEAN
        #undef CRC_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma clang section data=".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_BOOLEAN
        #undef CRC_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma clang section data=""
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_8
        #undef CRC_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma clang section data=".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_8
        #undef CRC_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma clang section data=""
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_16
        #undef CRC_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma clang section data=".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_16
        #undef CRC_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma clang section data=""
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_32
        #undef CRC_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma clang section data=".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_32
        #undef CRC_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma clang section data=""
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_PTR
        #undef CRC_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma clang section data=".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_PTR
        #undef CRC_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma clang section data=""
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_UNSPECIFIED
        #undef CRC_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section data=".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section data=""
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_BOOLEAN
        #undef CRC_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma clang section bss=".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef CRC_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma clang section bss=""
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_8
        #undef CRC_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma clang section bss=".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_8
        #undef CRC_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma clang section bss=""
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_16
        #undef CRC_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma clang section bss=".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_16
        #undef CRC_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma clang section bss=""
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_32
        #undef CRC_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma clang section bss=".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_32
        #undef CRC_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma clang section bss=""
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_PTR
        #undef CRC_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma clang section bss=".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_PTR
        #undef CRC_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma clang section bss=""
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CRC_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section bss=".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma clang section bss=""
    #endif

/***************************************** GreenHills *********************************************/
#elif defined(_GHS_C_Z20K14XM_)
    #ifdef CRC_START_SEC_CONFIG_DATA_8
        #undef CRC_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_8
        #undef CRC_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_16
        #undef CRC_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_16
        #undef CRC_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_32
        #undef CRC_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_32
        #undef CRC_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_PTR
        #undef CRC_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_PTR
        #undef CRC_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONST_BOOLEAN
        #undef CRC_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_BOOLEAN
        #undef CRC_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONST_8
        #undef CRC_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_8
        #undef CRC_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONST_16
        #undef CRC_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_16
        #undef CRC_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONST_32
        #undef CRC_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_32
        #undef CRC_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONST_PTR
        #undef CRC_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_PTR
        #undef CRC_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CONST_UNSPECIFIED
        #undef CRC_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef CRC_STOP_SEC_CONST_UNSPECIFIED
        #undef CRC_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_CODE
        #undef CRC_START_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma ghs section text = ".mcal_code"
    #endif

    #ifdef CRC_STOP_SEC_CODE
        #undef CRC_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_RAMCODE
        #undef CRC_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma ghs section text = ".mcal_ramcode"
        #pragma ghs         inlineprologue
        #pragma ghs         callmode = far
    #endif

    #ifdef CRC_STOP_SEC_RAMCODE
        #undef CRC_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #pragma ghs section
        #pragma ghs inlineprologue
        #pragma ghs callmode = far
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_BOOLEAN
        #undef CRC_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_BOOLEAN
        #undef CRC_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_8
        #undef CRC_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_8
        #undef CRC_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_16
        #undef CRC_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_16
        #undef CRC_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_32
        #undef CRC_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_32
        #undef CRC_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_PTR
        #undef CRC_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_PTR
        #undef CRC_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_INIT_UNSPECIFIED
        #undef CRC_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_BOOLEAN
        #undef CRC_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef CRC_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_8
        #undef CRC_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_8
        #undef CRC_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_16
        #undef CRC_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_16
        #undef CRC_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_32
        #undef CRC_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_32
        #undef CRC_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_PTR
        #undef CRC_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_PTR
        #undef CRC_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #pragma ghs section
    #endif

    #ifdef CRC_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CRC_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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

/** @} end of group Crc_MemMap */

/** @} end of group MemMap */

/** @} end of group Base_Module */
