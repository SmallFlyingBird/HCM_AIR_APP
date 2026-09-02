/**
 * @file    MemIf_Types.h
 * @version 
 *
 * @brief   AUTOSAR MemIf module interface
 * @details API implementation for MEMIF driver
 *
 * @addtogroup MEMIF_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : MemIf
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

#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif



/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMIF_TYPES_VENDOR_ID                      (180)
#define MEMIF_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define MEMIF_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define MEMIF_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define MEMIF_TYPES_SW_MAJOR_VERSION               (2)
#define MEMIF_TYPES_SW_MINOR_VERSION               (3)
#define MEMIF_TYPES_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief           
 * @note            trace: 
 */
typedef enum {
    MEMIF_JOB_OK                             = 0, /**<    */
    MEMIF_JOB_FAILED                         = 1, /**<    */
    MEMIF_JOB_PENDING                        = 2, /**<    */
    MEMIF_JOB_CANCELED                       = 3, /**<    */
    MEMIF_BLOCK_INCONSISTENT                 = 4, /**<    */
    MEMIF_BLOCK_INVALID                      = 5, /**<    */
} MemIf_JobResultType;


/**
 * @brief           
 * @note            trace: 
 */
typedef enum {
    MEMIF_MODE_SLOW                          = 0, /**<    */
    MEMIF_MODE_FAST                          = 1, /**<    */
} MemIf_ModeType;


/**
 * @brief           
 * @note            trace: 
 */
typedef enum {
    MEMIF_UNINIT                             = 0, /**<    */
    MEMIF_IDLE                               = 1, /**<    */
    MEMIF_BUSY                               = 2, /**<    */
    MEMIF_BUSY_INTERNAL                      = 3, /**<    */
} MemIf_StatusType;



#ifdef __cplusplus
}
#endif

#endif /* MEMIF_H */

/** @} */

