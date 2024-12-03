/**************************************************************************************************/
/**
 * @file      : Platform_Types.h
 * @brief     : AUTOSAR platform types definition
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/** @addtogroup  Base_Module
 *  @{
 */

/** @defgroup Platform_Types
 *  @brief AUTOSAR platform types definition
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* published information */
#define PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION    4U
#define PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION    6U
#define PLATFORM_TYPES_AR_RELEASE_REVISION_VERSION 0U
#define PLATFORM_TYPES_SW_MAJOR_VERSION            1U
#define PLATFORM_TYPES_SW_MINOR_VERSION            2U
#define PLATFORM_TYPES_SW_PATCH_VERSION            2U

#define CPU_TYPE_8  8U  /* Indicating a 8 bit processor */
#define CPU_TYPE_16 16U /* Indicating a 16 bit processor */
#define CPU_TYPE_32 32U /* Indicating a 32 bit processor */
#define CPU_TYPE_64 64U /* Indicating a 64 bit processor */

/* The most significant bit is the first bit of the bit sequence */
#define MSB_FIRST 0U

/* The least significant bit is the first bit of the bit sequence */
#define LSB_FIRST 1U

/* highe byte first */
#define HIGH_BYTE_FIRST 0U

/* low byte first */
#define LOW_BYTE_FIRST 1U

#ifndef TRUE
    /* Boolean true value */
    #define TRUE 1U
#endif
#ifndef FALSE
    /* Boolean false value */
    #define FALSE 0U
#endif

/* the register width of the CPU */
#define CPU_TYPE (CPU_TYPE_32)

/* Bit order on register level */
#define CPU_BIT_ORDER (LSB_FIRST)

/* The byte order on memory level */
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief The standard AUTOSAR type boolean shall be implemented as an unsigned integer with a bit
 *        length that is the shortest one natively supported by the platform (8 bits).
 */
typedef unsigned char boolean;

/**
 * @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF)
 */
typedef unsigned char uint8;

/**
 * @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF)
 */
typedef unsigned short uint16;

/**
 * @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF)
 */
typedef unsigned int uint32;

/**
 * @brief Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..
 *        0xFFFFFFFFFFFFFFFF)
 */
typedef unsigned long long uint64;

/**
 * @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F)
 */
typedef signed char sint8;

/**
 * @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF)
 */
typedef signed short sint16;

/**
 * @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF)
 */
typedef signed int sint32;

/**
 * @brief Signed 64 bit integer with range of -9223372036854775808..9223372036854775807
 *        (0x8000000000000000..0x7FFFFFFFFFFFFFFF )
 */
typedef signed long long sint64;

/**
 * @brief Unsigned integer at least 8 bit long with Range of at least 0 ..+255 (0x00..0xFF)
 */
typedef unsigned long uint8_least;

/**
 * @brief  Unsigned integer at least 16 bit long with Range of at least 0 ..+65535 (0x0000..0xFFFF)
 */
typedef unsigned long uint16_least;

/**
 * @brief Unsigned integer at least 32 bit long with Range of at least 0 ..+4294967295
 *       (0x00000000..0xFFFFFFFF)
 */
typedef unsigned long uint32_least;

/**
 * @brief Signed integer at least 8 bit long with Range of at least -128 ..+127.
 */
typedef signed long sint8_least;

/**
 * @brief Signed integer at least 16 bit long with Range of at least -32768 ..+32767.
 */
typedef signed long sint16_least;

/**
 * @brief Signed integer at least 32 bit long with Range of at least -2147483648.. +2147483647.
 */
typedef signed long sint32_least;

/**
 * @brief 32-bit floating point data type with range of -3.4028235e+38 ..+3.4028235e+38
 */
typedef float float32;

/**
 * @brief 64-bit floating point data type with range -1.7976931348623157e+308 ..
 *        +1.7976931348623157e+308
 */
typedef double float64;

/**
 * @brief a void pointer
 */
typedef void *VoidPtr;

/**
 * @brief a void pointer to const
 */
typedef const void *ConstVoidPtr;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Platform_Types */
/** @} end of group Base_Module */

#endif /* PLATFORM_TYPES_H */
