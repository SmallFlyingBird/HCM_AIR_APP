/**************************************************************************************************/
/**
 * @file      : Smpu_Drv.h
 * @brief     : System memory protect unit header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SMPU_DRV_H
#define SMPU_DRV_H

/** @addtogroup  Smpu_Module
 *  @{
 */

/** @addtogroup  Smpu
 *  @brief Smpu Driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Smpu_Drv_Types.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SMPU_DRV_H_VENDOR_ID                   0x00B3U
#define SMPU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define SMPU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define SMPU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define SMPU_DRV_H_SW_MAJOR_VERSION            1U
#define SMPU_DRV_H_SW_MINOR_VERSION            1U
#define SMPU_DRV_H_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Smpu_Drv_Types.h are of the same vendor
 */
#if (SMPU_DRV_TYPES_H_VENDOR_ID != SMPU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Smpu_Drv.h and Smpu_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv_Types.h are of the same Autosar version
 */
#if ((SMPU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (SMPU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != SMPU_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (SMPU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != SMPU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Smpu_Drv.h and Smpu_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv_Types.h are of the same SW version
 */
#if ((SMPU_DRV_TYPES_H_SW_MAJOR_VERSION != SMPU_DRV_H_SW_MAJOR_VERSION) ||                         \
     (SMPU_DRV_TYPES_H_SW_MINOR_VERSION != SMPU_DRV_H_SW_MINOR_VERSION) ||                         \
     (SMPU_DRV_TYPES_H_SW_PATCH_VERSION != SMPU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Smpu_Drv.h and Smpu_Drv_Types.h are different"
#endif
/** @} end of group Private_MacroDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define MPU_START_SEC_CODE
#include "Mpu_MemMap.h"
/**
 * @brief      Init Smpu memory region config.
 *
 * @param[in]  SmpuRegionConfigPtr: Pointer to configuration information
 *
 * @return     None
 * 
 */
void Smpu_Drv_InitMemoryRegion(const Smpu_Drv_RegionConfigType *SmpuRegionConfigPtr);

/**
 * @brief        This function is used to enable or disable Smpu.
 *
 * @param[in]    ControlState: Enable and Disable Smpu
 *
 * @return       none
 */
void Smpu_Drv_Enable(const boolean ControlState);

/**
 * @brief        This function get memory region id that detected a error.
 *
 * @param[in]    SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 *
 * @return       MRC Number by MRCn(n=0~15),
 *               Bit n corresponds to MRCn, bit n set 1 when error occurs in MRCn.
 * 
 */
uint16 Smpu_Drv_GetSingleMrcErrStatus(const Smpu_Drv_SlavePortType SlavePort);

/**
 * @brief       This function get master number that cause the error.
 *
 * @param[in]   SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 * 
 * @return      Error master number:
 * @retval      0: bus master0 cause the access error
 * @retval      1: bus master1 cause the access error
 * @retval      2: bus master2 cause the access error
 * 
 */
Smpu_Drv_BusMasterType Smpu_Drv_GetErrAccessMasterNum(const Smpu_Drv_SlavePortType SlavePort);

/**
 * @brief       This function get error cause that occur in slave port.
 *
 * @param[in]   SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 * @param[out]  ErrorTypePtr: Point to the structure that contain error information
 * 
 * @return      none
 * 
 */
void Smpu_Drv_GetAccessErrCause(const Smpu_Drv_SlavePortType SlavePort, 
                                      Smpu_Drv_SalveErrorType *ErrorTypePtr);

/**
 * @brief        This function get slave port error address.
 *
 * @param[in]    SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 *
 * @return       Slave port n error address
 */
uint32 Smpu_Drv_GetSlavePortErrAddress(const Smpu_Drv_SlavePortType SlavePort);

/**
 * @brief        This function get error bits mask.
 *
 * @param[in]    None
 *
 * @return       Slave port bits mask that occur an error.
 * 
 */
uint32 Smpu_Drv_GetSlavePortAccErrStatus(void);


/**
 * @brief        This function check Smpu is enabled or disabled.
 *
 * @param[in]    None
 *
 * @return       Smpu status.
 * @retval       TRUE: Smpu is enabled
 * @retval       FALSE: Smpu is disabled
 * 
 */
boolean Smpu_Drv_CheckStatus(void);

/**
 * @brief        This function is used to clear slave port n error status.
 *
 * @param[in]    SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 *
 * @return       None
 */
void Smpu_Drv_ClearSlavePortErrStatus(const Smpu_Drv_SlavePortType SlavePort);
#define MPU_STOP_SEC_CODE
#include "Mpu_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Smpu */

/** @} end of group Smpu_Module */
#endif /* SMPU_DRV_H */
