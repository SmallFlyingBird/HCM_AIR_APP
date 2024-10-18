/**************************************************************************************************/
/**
 * @file      : SchM_Dio.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/**
 * @file SchM_Dio.c
 * @brief Dio schedule source file. This is a stub file.
 *
 */

/** @addtogroup  Rte_Module
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Dio.h"

/** @defgroup Private_Defines
 *  @{
 */

/**
 *  @brief Published information
 */
#define SCHM_DIO_C_VENDOR_ID                   0x00B3U
#define SCHM_DIO_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_DIO_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_DIO_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_DIO_C_SW_MAJOR_VERSION            1U
#define SCHM_DIO_C_SW_MINOR_VERSION            2U
#define SCHM_DIO_C_SW_PATCH_VERSION            1U

/**
 *  @brief Check if current file and SchM_Dio header file are of the same vendor
 */
#if (SCHM_DIO_C_VENDOR_ID != SCHM_DIO_H_VENDOR_ID)
    #error "Vendor ID of SchM_Dio.c and SchM_Dio.h are different"
#endif
/**
 *  @brief Check if current file and SchM_Dio header file are of the same Autosar version
 */
#if ((SCHM_DIO_H_AR_RELEASE_MAJOR_VERSION != SCHM_DIO_C_AR_RELEASE_MAJOR_VERSION) ||               \
     (SCHM_DIO_H_AR_RELEASE_MINOR_VERSION != SCHM_DIO_C_AR_RELEASE_MINOR_VERSION) ||               \
     (SCHM_DIO_H_AR_RELEASE_REVISION_VERSION != SCHM_DIO_C_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of SchM_Dio.h and SchM_Dio.c are different"
#endif

#if ((SCHM_DIO_H_SW_MAJOR_VERSION != SCHM_DIO_C_SW_MAJOR_VERSION) ||                               \
     (SCHM_DIO_H_SW_MINOR_VERSION != SCHM_DIO_C_SW_MINOR_VERSION) ||                               \
     (SCHM_DIO_H_SW_PATCH_VERSION != SCHM_DIO_C_SW_PATCH_VERSION))
    #error "Software Version of SchM_Dio.c and SchM_Dio.h are different"
#endif

/** @} end of group Private_Defines */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/** @defgroup Public_Functions
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
void SchM_Enter_Dio_WritePortData(void)
{
    SuspendAllInterrupts();
}
/**
 * @brief          The critical region exits.
 * @details        Protect register.
 *
 * @param[in]      None.
 *
 * @return         None.
 */
void SchM_Exit_Dio_WritePortData(void)
{
    ResumeAllInterrupts();
}
/** @} end of group Public_Functions */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Rte_Module */
