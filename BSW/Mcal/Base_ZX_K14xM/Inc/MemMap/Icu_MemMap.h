/**************************************************************************************************/
/**
 * @file      : Icu_MemMap.h
 * @brief     : AUTOSAR Icu MemMap header file. It specifies mechanisms for the mapping of code
 *              and data to specific memory sections. This file only contains example code.
 *              This file must be updated depending on the integrating environment.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
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

/** @defgroup Icu_MemMap
 *  @brief Icu MemMap header file
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
#define ICU_MEMMAP_VENDOR_ID                   0x00B3U
#define ICU_MEMMAP_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_MEMMAP_AR_RELEASE_MINOR_VERSION    6U
#define ICU_MEMMAP_AR_RELEASE_REVISION_VERSION 0U
#define ICU_MEMMAP_SW_MAJOR_VERSION            1U
#define ICU_MEMMAP_SW_MINOR_VERSION            2U
#define ICU_MEMMAP_SW_PATCH_VERSION            1U

/** @} end of Public_MacroDefinition */

#define MEMMAP_ERROR

/********************************************* IAR ************************************************/
#if defined(_IAR_C_Z20K14XM_)
    #ifdef ICU_START_SEC_CONFIG_DATA_8
        #undef ICU_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_8_STARTED
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_8
        #undef ICU_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_8_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_16
        #undef ICU_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_16_STARTED
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_16
        #undef ICU_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_16_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_32
        #undef ICU_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_32_STARTED
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_32
        #undef ICU_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_32_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_PTR
        #undef ICU_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_PTR_STARTED
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_PTR
        #undef ICU_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_PTR_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
        #pragma default_variable_attributes = @ ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONST_BOOLEAN
        #undef ICU_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_BOOLEAN_STARTED
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_BOOLEAN
        #undef ICU_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_BOOLEAN_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONST_8
        #undef ICU_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_8_STARTED
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_8
        #undef ICU_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_8_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONST_16
        #undef ICU_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_16_STARTED
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_16
        #undef ICU_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_16_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONST_32
        #undef ICU_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_32_STARTED
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_32
        #undef ICU_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_32_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONST_PTR
        #undef ICU_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_PTR_STARTED
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_PTR
        #undef ICU_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_PTR_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CONST_UNSPECIFIED
        #undef ICU_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_UNSPECIFIED_STARTED
        #pragma default_variable_attributes = @ ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_UNSPECIFIED
        #undef ICU_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_UNSPECIFIED_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_CODE
        #undef ICU_START_SEC_CODE
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CODE_STARTED
        #pragma default_function_attributes = @ ".mcal_code"
    #endif

    #ifdef ICU_STOP_SEC_CODE
        #undef ICU_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CODE_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CODE_STARTED
        #endif
        #pragma default_function_attributes =
    #endif

    #ifdef ICU_START_SEC_RAMCODE
        #undef ICU_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_RAMCODE_STARTED
        #pragma default_function_attributes = @ ".mcal_ramcode"
    #endif

    #ifdef ICU_STOP_SEC_RAMCODE
        #undef ICU_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_RAMCODE_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_RAMCODE_STARTED
        #endif
        #pragma default_function_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_BOOLEAN
        #undef ICU_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef ICU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_8
        #undef ICU_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_8_STARTED
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_8
        #undef ICU_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_8_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_16
        #undef ICU_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_16_STARTED
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_16
        #undef ICU_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_16_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_32
        #undef ICU_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_32_STARTED
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_32
        #undef ICU_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_32_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_PTR
        #undef ICU_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_PTR_STARTED
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_PTR
        #undef ICU_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_PTR_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ICU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
        #pragma default_variable_attributes = @ ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ICU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef ICU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_8
        #undef ICU_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_8_STARTED
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_8
        #undef ICU_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_8_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_16
        #undef ICU_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_16_STARTED
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_16
        #undef ICU_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_16_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_32
        #undef ICU_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_32_STARTED
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_32
        #undef ICU_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_32_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_PTR
        #undef ICU_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_PTR_STARTED
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_PTR
        #undef ICU_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_PTR_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
        #pragma default_variable_attributes = @ ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
        #endif
        #pragma default_variable_attributes =
    #endif

/************************************** ARM clang *************************************************/
#elif defined(_ARMCLANG_C_Z20K14XM_)
    #ifdef ICU_START_SEC_CONFIG_DATA_8
        #undef ICU_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_8_STARTED
        #pragma clang section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_8
        #undef ICU_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_8_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_16
        #undef ICU_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_16_STARTED
        #pragma clang section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_16
        #undef ICU_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_16_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_32
        #undef ICU_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_32_STARTED
        #pragma clang section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_32
        #undef ICU_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_32_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_PTR
        #undef ICU_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_PTR_STARTED
        #pragma clang section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_PTR
        #undef ICU_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_PTR_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
        #pragma clang section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONST_BOOLEAN
        #undef ICU_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_BOOLEAN_STARTED
        #pragma clang section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_BOOLEAN
        #undef ICU_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_BOOLEAN_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONST_8
        #undef ICU_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_8_STARTED
        #pragma clang section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_8
        #undef ICU_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_8_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONST_16
        #undef ICU_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_16_STARTED
        #pragma clang section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_16
        #undef ICU_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_16_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONST_32
        #undef ICU_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_32_STARTED
        #pragma clang section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_32
        #undef ICU_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_32_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONST_PTR
        #undef ICU_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_PTR_STARTED
        #pragma clang section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_PTR
        #undef ICU_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_PTR_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CONST_UNSPECIFIED
        #undef ICU_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_UNSPECIFIED_STARTED
        #pragma clang section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_UNSPECIFIED
        #undef ICU_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_UNSPECIFIED_STARTED
        #endif
        #pragma clang section rodata = ""
    #endif

    #ifdef ICU_START_SEC_CODE
        #undef ICU_START_SEC_CODE
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CODE_STARTED
        #pragma clang section text = ".mcal_code"
    #endif

    #ifdef ICU_STOP_SEC_CODE
        #undef ICU_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CODE_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CODE_STARTED
        #endif
        #pragma clang section text = ""
    #endif

    #ifdef ICU_START_SEC_RAMCODE
        #undef ICU_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_RAMCODE_STARTED
        #pragma clang section text = ".mcal_ramcode"
    #endif

    #ifdef ICU_STOP_SEC_RAMCODE
        #undef ICU_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_RAMCODE_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_RAMCODE_STARTED
        #endif
        #pragma clang section text = ""
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_BOOLEAN
        #undef ICU_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
        #pragma clang section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef ICU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
        #endif
        #pragma clang section data = ""
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_8
        #undef ICU_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_8_STARTED
        #pragma clang section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_8
        #undef ICU_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_8_STARTED
        #endif
        #pragma clang section data = ""
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_16
        #undef ICU_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_16_STARTED
        #pragma clang section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_16
        #undef ICU_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_16_STARTED
        #endif
        #pragma clang section data = ""
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_32
        #undef ICU_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_32_STARTED
        #pragma clang section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_32
        #undef ICU_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_32_STARTED
        #endif
        #pragma clang section data = ""
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_PTR
        #undef ICU_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_PTR_STARTED
        #pragma clang section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_PTR
        #undef ICU_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_PTR_STARTED
        #endif
        #pragma clang section data = ""
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ICU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
        #pragma clang section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
        #endif
        #pragma clang section data = ""
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ICU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
        #pragma clang section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef ICU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
        #endif
        #pragma clang section bss = ""
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_8
        #undef ICU_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_8_STARTED
        #pragma clang section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_8
        #undef ICU_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_8_STARTED
        #endif
        #pragma clang section bss = ""
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_16
        #undef ICU_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_16_STARTED
        #pragma clang section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_16
        #undef ICU_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_16_STARTED
        #endif
        #pragma clang section bss = ""
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_32
        #undef ICU_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_32_STARTED
        #pragma clang section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_32
        #undef ICU_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_32_STARTED
        #endif
        #pragma clang section bss = ""
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_PTR
        #undef ICU_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_PTR_STARTED
        #pragma clang section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_PTR
        #undef ICU_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_PTR_STARTED
        #endif
        #pragma clang section bss = ""
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
        #pragma clang section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
        #endif
        #pragma clang section bss = ""
    #endif

/***************************************** GreenHills *********************************************/
#elif defined(_GHS_C_Z20K14XM_)
    #ifdef ICU_START_SEC_CONFIG_DATA_8
        #undef ICU_START_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_8_STARTED
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_8
        #undef ICU_STOP_SEC_CONFIG_DATA_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_8_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_16
        #undef ICU_START_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_16_STARTED
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_16
        #undef ICU_STOP_SEC_CONFIG_DATA_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_16_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_32
        #undef ICU_START_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_32_STARTED
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_32
        #undef ICU_STOP_SEC_CONFIG_DATA_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_32_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_PTR
        #undef ICU_START_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_PTR_STARTED
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_PTR
        #undef ICU_STOP_SEC_CONFIG_DATA_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_PTR_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
        #pragma ghs section rodata = ".mcal_config_data"
    #endif

    #ifdef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONST_BOOLEAN
        #undef ICU_START_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_BOOLEAN_STARTED
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_BOOLEAN
        #undef ICU_STOP_SEC_CONST_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_BOOLEAN_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONST_8
        #undef ICU_START_SEC_CONST_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_8_STARTED
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_8
        #undef ICU_STOP_SEC_CONST_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_8_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONST_16
        #undef ICU_START_SEC_CONST_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_16_STARTED
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_16
        #undef ICU_STOP_SEC_CONST_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_16_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONST_32
        #undef ICU_START_SEC_CONST_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_32_STARTED
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_32
        #undef ICU_STOP_SEC_CONST_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_32_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONST_PTR
        #undef ICU_START_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_PTR_STARTED
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_PTR
        #undef ICU_STOP_SEC_CONST_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_PTR_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CONST_UNSPECIFIED
        #undef ICU_START_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CONST_UNSPECIFIED_STARTED
        #pragma ghs section rodata = ".mcal_const"
    #endif

    #ifdef ICU_STOP_SEC_CONST_UNSPECIFIED
        #undef ICU_STOP_SEC_CONST_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CONST_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CONST_UNSPECIFIED_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_CODE
        #undef ICU_START_SEC_CODE
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_CODE_STARTED
        #pragma ghs section text = ".mcal_code"
    #endif

    #ifdef ICU_STOP_SEC_CODE
        #undef ICU_STOP_SEC_CODE
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_CODE_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_CODE_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_RAMCODE
        #undef ICU_START_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_RAMCODE_STARTED
        #pragma ghs section text = ".mcal_ramcode"
        #pragma ghs         inlineprologue
        #pragma ghs         callmode = far
    #endif

    #ifdef ICU_STOP_SEC_RAMCODE
        #undef ICU_STOP_SEC_RAMCODE
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_RAMCODE_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_RAMCODE_STARTED
        #endif
        #pragma ghs section
        #pragma ghs inlineprologue
        #pragma ghs callmode = far
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_BOOLEAN
        #undef ICU_START_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef ICU_STOP_SEC_VAR_INIT_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_BOOLEAN_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_8
        #undef ICU_START_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_8_STARTED
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_8
        #undef ICU_STOP_SEC_VAR_INIT_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_8_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_16
        #undef ICU_START_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_16_STARTED
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_16
        #undef ICU_STOP_SEC_VAR_INIT_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_16_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_32
        #undef ICU_START_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_32_STARTED
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_32
        #undef ICU_STOP_SEC_VAR_INIT_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_32_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_PTR
        #undef ICU_START_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_PTR_STARTED
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_PTR
        #undef ICU_STOP_SEC_VAR_INIT_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_PTR_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ICU_START_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
        #pragma ghs section data = ".mcal_data"
    #endif

    #ifdef ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_INIT_UNSPECIFIED_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ICU_START_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef ICU_STOP_SEC_VAR_CLEARED_BOOLEAN
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_BOOLEAN_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_8
        #undef ICU_START_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_8_STARTED
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_8
        #undef ICU_STOP_SEC_VAR_CLEARED_8
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_8_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_8_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_16
        #undef ICU_START_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_16_STARTED
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_16
        #undef ICU_STOP_SEC_VAR_CLEARED_16
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_16_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_16_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_32
        #undef ICU_START_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_32_STARTED
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_32
        #undef ICU_STOP_SEC_VAR_CLEARED_32
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_32_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_32_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_PTR
        #undef ICU_START_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_PTR_STARTED
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_PTR
        #undef ICU_STOP_SEC_VAR_CLEARED_PTR
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_PTR_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_PTR_STARTED
        #endif
        #pragma ghs section
    #endif

    #ifdef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifdef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #define MEMMAP_MATCH_ERROR
        #endif
        #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
        #pragma ghs section bss = ".mcal_bss"
    #endif

    #ifdef ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #undef MEMMAP_ERROR
        #ifndef MEMMAP_MATCH_ERROR
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef MEMMAP_MATCH_ERROR
        #endif
        #ifndef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
            #error "MemMap error: no matched start-stop section defined"
        #else
            #undef ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
        #endif
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

/** @} end of group Icu_MemMap */

/** @} end of group MemMap */

/* MISRA2012 Dir-4.10 violation: Include file code is not protected against repeated inclusion. 
Memmap header usage complies to Autosar guidelines */
/** @} end of group Base_Module */
