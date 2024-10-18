/**************************************************************************************************/
/**
 * @file      : SchM_Dio.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_DIO_H
#define SCHM_DIO_H

/**
*   @file
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
  
/** @defgroup Public_Defines
 *  @{
 */

/**
 *  @brief Published information
 */
#define SCHM_DIO_H_VENDOR_ID                   0x00B3U
#define SCHM_DIO_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_DIO_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_DIO_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_DIO_H_SW_MAJOR_VERSION            1U
#define SCHM_DIO_H_SW_MINOR_VERSION            2U
#define SCHM_DIO_H_SW_PATCH_VERSION            1U
/** @} end of group Public_Defines */ 
  
  
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/** @defgroup Public_FunctionDeclaration
 *  @{
 */
 /**
 * @brief          The critical region enters.
 * @details        Protect register.
 *
 * @param[in]      None.
 *
 * @return         None.
 */
extern void SchM_Enter_Dio_WritePortData(void);
 /**
 * @brief          The critical region exits.
 * @details        Protect register.
 *
 * @param[in]      None.
 *
 * @return         None.
 */
extern void SchM_Exit_Dio_WritePortData(void);

/** @} end of group Public_FunctionDeclaration */ 
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_DIO_H */
