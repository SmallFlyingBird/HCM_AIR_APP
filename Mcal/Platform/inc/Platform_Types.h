/**
*   @file    Platform_Types.h
*   @version
*
*   @brief   AUTOSAR general types define
*
*   @addtogroup GENERAL
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V2.3.0
*
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
// #include "IntCtrl_Lld_TypesDef.h"
#ifdef MCAL_HAS_PLATFORM_TYPES_DEFINE
#define PLATFORM_VENDOR_ID                      (180)
#define PLATFORM_AR_RELEASE_MAJOR_VERSION       (4)
#define PLATFORM_AR_RELEASE_MINOR_VERSION       (4)
#define PLATFORM_AR_RELEASE_REVISION_VERSION    (0)
#define PLATFORM_SW_MAJOR_VERSION               (2)
#define PLATFORM_SW_MINOR_VERSION               (3)
#define PLATFORM_SW_PATCH_VERSION               (0)
#endif


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
typedef signed char         sint8;         /**< -128 .. +127                   */
typedef unsigned char       uint8;         /**< 0 .. 255                       */
typedef signed short        sint16;        /**< -32768 .. +32767               */
typedef unsigned short      uint16;        /**<  0 .. 65535                    */
typedef signed int         sint32;        /**< -2147483648 .. +2147483647     */
typedef unsigned int       uint32;        /**<  0 .. 4294967295               */
typedef signed long long    sint64;
typedef unsigned long long  uint64;

typedef unsigned long       uint8_least;    /**< At least 8 bit                 */
typedef unsigned long       uint16_least;   /**< At least 16 bit                */
typedef unsigned long       uint32_least;   /**< At least 32 bit                */
typedef signed long         sint8_least;    /**< At least 7 bit + 1 bit sign    */
typedef signed long         sint16_least;   /**< At least 15 bit + 1 bit sign   */
typedef signed long         sint32_least;   /**< At least 31 bit + 1 bit sign   */

typedef float               float32;
typedef double              float64;

typedef unsigned char       boolean;

/**
 * @brief CPU_TYPE
 */
#define CPU_TYPE_8        8
#define CPU_TYPE_16       16
#define CPU_TYPE_32       32
#define CPU_TYPE_64       64

/**
 * @brief CPU_BIT_ORDER
 */
#define MSB_FIRST         0                 /**< Big endian bit ordering        */
#define LSB_FIRST         1                 /**< Little endian bit ordering     */

/**
 * @brief CPU_BYTE_ORDER
 */
#define HIGH_BYTE_FIRST   0                 /**< Big endian byte ordering       */
#define LOW_BYTE_FIRST    1                 /**< Little endian byte ordering    */


#define CPU_TYPE          (CPU_TYPE_32)
#define CPU_BIT_ORDER     (LSB_FIRST)
#define CPU_BYTE_ORDER    (LOW_BYTE_FIRST)

#ifndef TRUE
#define TRUE      1U
#endif

#ifndef FALSE
#define FALSE     0U
#endif

#endif /* PLATFORM_TYPES_H */
/** @} */

