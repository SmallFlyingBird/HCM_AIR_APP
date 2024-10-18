/**************************************************************************************************/
/**
 * @file      : Mpu_Externals.h
 * @brief     : System memory protect unit externals header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MPU_EXTERNALS_H
#define MPU_EXTERNALS_H

/** @addtogroup  Mpu_Module
 *  @{
 */

/** @defgroup Mpu
 *  @brief Mpu configuration value defined
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MPU_EXTERNALS_H_VENDOR_ID                   0x00B3U
#define MPU_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION    4U
#define MPU_EXTERNALS_H_AR_RELEASE_MINOR_VERSION    6U
#define MPU_EXTERNALS_H_AR_RELEASE_REVISION_VERSION 0U
#define MPU_EXTERNALS_H_SW_MAJOR_VERSION            1U
#define MPU_EXTERNALS_H_SW_MINOR_VERSION            1U
#define MPU_EXTERNALS_H_SW_PATCH_VERSION            0U

#define MPU_ERRORNOTIFICATIONPTR MpuErrorNotificationFunc
/** @} end of group Public_MacroDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
 * @brief      Mpu Callback Error Notification
 *
 * @param[in]  SlavePort: Slave port that caused the error.
 * @param[in]  ErrorTypePtr: Pointer to Error information.
 * 
 * @return     None
 */
extern void MpuErrorNotificationFunc(const uint8   SlavePort,
                                          const Mpu_SalveErrorType *ErrorTypePtr);
    /** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Smpu */

/** @} end of group Smpu_Module */
#endif /* MPU_EXTERNALS_H */
