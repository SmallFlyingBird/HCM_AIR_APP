/**************************************************************************************************/
/**
 * @file      : I2c_Drv.h
 * @brief     : AUTOSAR Tim I2c hardware driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef I2C_DRV_H
#define I2C_DRV_H

/** @addtogroup  I2c_Module
 *  @{
 */

/** @addtogroup  I2c_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "I2c_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define I2C_DRV_H_VENDOR_ID                   0x00B3U
#define I2C_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define I2C_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define I2C_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define I2C_DRV_H_SW_MAJOR_VERSION            1U
#define I2C_DRV_H_SW_MINOR_VERSION            2U
#define I2C_DRV_H_SW_PATCH_VERSION            2U

#if (I2C_DRV_H_VENDOR_ID != I2C_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of I2c_Drv.h and I2c_Drv_Types.h are different"
#endif

#if ((I2C_DRV_H_AR_RELEASE_MAJOR_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (I2C_DRV_H_AR_RELEASE_MINOR_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (I2C_DRV_H_AR_RELEASE_REVISION_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of I2c_Drv.h and I2c_Drv_Types.h are different"
#endif

#if ((I2C_DRV_H_SW_MAJOR_VERSION != I2C_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (I2C_DRV_H_SW_MINOR_VERSION != I2C_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (I2C_DRV_H_SW_PATCH_VERSION != I2C_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software version of I2c_Drv.h and I2c_Drv_Types.h are different"
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/**
 * @brief   Export Post-Build configurations.
 */
#if (defined I2C_DRV_CONFIG_EXT)
    #define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "I2c_MemMap.h"

I2C_DRV_CONFIG_EXT

    #define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "I2c_MemMap.h"
#endif /* I2C_DRV_CONFIG_EXT */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @brief I2c Drv functions declaration
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief      Set transmit request configurations.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  RequestParam: Pointer to structure for request parameters.
 *
 * @return     None
 *
 */
void I2c_Drv_SetRequestConfig(const I2c_Drv_IdType InstId, I2c_Drv_RequestType *RequestParam);

/**
 * @brief      Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer to structure which contains driver configuration data
 *
 * @return     None
 *
 */
void I2c_Drv_Init(const I2c_Drv_IdType InstId, const I2c_Drv_PhyUnitConfigType *I2cPhyUnitCfgPtr);

/**
 * @brief      De-Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer to structure which contains driver configuration data
 *
 * @return     None
 *
 */
void I2c_Drv_DeInit(const I2c_Drv_IdType InstId, const I2c_Drv_PhyUnitConfigType *I2cPhyUnitCfgPtr);

/**
 * @brief      This function send or receive data.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  Blocking: Select blocking or non-blocking method
 *             - TRUE: Blocking method, used for sync transmit
 *             - FALSE: Non-blocking method, used for async transmit
 *
 * @return     I2c_Drv_StatusType
 * @retval     I2C_DRV_SUCCESS_STATUS  Success
 * @retval     I2C_DRV_ERROR_STATUS    Error
 * @retval     I2C_DRV_BUSY_STATUS     Busy
 *
 */
I2c_Drv_StatusType I2c_Drv_MasterTransmitData(const I2c_Drv_IdType InstId, boolean Blocking);

/**
 * @brief      This function sets slave receive or send data.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  TxBuffer: Pointer to the buffer-array
 * @param[in]  TxSize: Size of the external buffer
 *
 * @return     None
 *
 */
void I2c_Drv_SetupSlaveBuffer(const I2c_Drv_IdType InstId, uint8 *TxBuff, uint32 TxSize);

/**
 * @brief      Return the current status
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     I2c_Drv_StatusType: current status
 * @retval     I2C_DRV_SUCCESS_STATUS
 * @retval     I2C_DRV_ERROR_STATUS
 * @retval     I2C_DRV_BUSY_STATUS
 * @retval     I2C_DRV_TIMEOUT_STATUS
 * @retval     I2C_DRV_RECEIVED_NACK_STATUS
 * @retval     I2C_DRV_TX_UNDERRUN_STATUS
 * @retval     I2C_DRV_RX_OVERRUN_STATUS
 */
I2c_Drv_StatusType I2c_Drv_GetStatus(const I2c_Drv_IdType InstId);

/**
 * @brief      This function handles I2c interrupt
 *
 * @param[in]  InstId: The I2C instance id.
 *
 * @return     None
 *
 */
void I2c_Drv_ChIntHandler(I2c_Drv_IdType InstId);

/**
 * @brief      This function set SCL stuck at low timeout value.
 *             This function will disable I2C module first and may disrupt ongoing transmissions.
 *             Therefore, it is recommended to call this function when I2C status is idle.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  TimeoutValue: SCL stuck at low timeout value.
 *             I2C module generates the SCL_STUCK_AT_LOW interrupt to indicate SCL stuck at low if
 *             it detects the SCL stuck at low for the I2C_SCL_LOW_TIMEOUT in units of I2C function
 *             clock period.
 *
 * @return     None
 *
 */
void I2C_Drv_SetSclHoldLowTimeout(I2c_Drv_IdType InstId, uint32 TimeoutValue);

/**
 * @brief      This function set SDA stuck at low timeout value.
 *             This function will disable I2C module first and may disrupt ongoing transmissions.
 *             Therefore, it is recommended to call this function when I2C status is idle.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  TimeoutValue: SDA stuck at low timeout value.
 *             I2C module initiates the recovery of SDA line through enabling the SDA_RECOVER_EN bit
 *             if it detects the SDA stuck at low for the I2C_SDA_LOW_TIMEOUT in units of I2C
 *             function clock period.
 *
 * @return     None
 *
 */
void I2C_Drv_SetSdaHoldLowTimeout(I2c_Drv_IdType InstId, uint32 TimeoutValue);

/**
 * @brief      Check whether interrupt status flag is set or not for given interrupt type
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  IntType:  Specified interrupt type.
 *             - I2C_DRV_INT_GEN_CALL
 *             - I2C_DRV_INT_TX_OVER
 *             - I2C_DRV_INT_ERROR_ABORT
 *             - I2C_DRV_INT_ACTIVITY
 *             - I2C_DRV_INT_STOP_DET
 *             - I2C_DRV_INT_START_DET
 *             - I2C_DRV_INT_RD_REQ
 *             - I2C_DRV_INT_RX_DONE
 *             - I2C_DRV_INT_RX_UNDER
 *             - I2C_DRV_INT_RX_OVER
 *             - I2C_DRV_INT_RESTART_DET
 *             - I2C_DRV_SCL_STUCK_AT_LOW
 *             - I2C_DRV_INT_RX_FULL
 *             - I2C_DRV_INT_TX_EMPTY
 *
 * @return     boolean: The status flag of interrupt status register.
 * @retval     TRUE: Specified interrupt status flag is set.
 * @retval     FALSE: Specified interrupt status flag is reset.
 *
 */
boolean I2c_Drv_GetIntStatus(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType);

/**
 * @brief      Check whether status flag is set or not for given status type
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  ConfigStatusType:  Specified status type.
 *             - I2C_DRV_MST_ACTIVITY
 *             - I2C_DRV_SLV_ACTIVITY
 *             - I2C_DRV_TXFIFO_EMPTY_MASTER_HOLD
 *             - I2C_DRV_TXFIFO_EMPTY_SLAVE_HOLD
 *             - I2C_DRV_RXFIFO_FULL_MASTER_HOLD
 *             - I2C_DRV_RXFIFO_FULL_SLAVE_HOLD
 *             - I2C_DRV_STATUS_TFNF
 *             - I2C_DRV_STATUS_TFE
 *             - I2C_DRV_STATUS_RFNE
 *             - I2C_DRV_STATUS_RFF
 *             - I2C_DRV_SDA_ERR_RECOVER_STUCK_LOW
 *             - I2C_DRV_SLAVE_IS_DISABLED_UNDER_ACT
 *             - I2C_DRV_SLAVE_RX_DATA_DISCARD
 *             - I2C_DRV_ENABLE
 *
 * @return     boolean: The status flag of I2C status register.
 * @retval     TRUE: Specified status flag is set.
 * @retval     FALSE: Specified status flag is reset.
 *
 */
boolean I2c_Drv_GetCurrentStatus(I2c_Drv_IdType InstId, I2c_Drv_ConfigStatusType ConfigStatusType);

/**
 * @brief      Check whether error status flag is set or not
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  ErrorType:  Specified abort type.
 *             - I2C_DRV_ERR_GEN_CALL_NO_ACK
 *             - I2C_DRV_ERR_GEN_CALL_READ
 *             - I2C_DRV_ERR_START_BYTE_ACK_DET
 *             - I2C_DRV_ERR_SBYTE_NORSTRT
 *             - I2C_DRV_ERR_H_NO_RSTRT
 *             - I2C_DRV_ERR_H_MCODE_ACK_DET
 *             - I2C_DRV_ERR_7BIT_ADDR_NO_ACK
 *             - I2C_DRV_ERR_10BIT_ADDR1_NO_ACK
 *             - I2C_DRV_ERR_10BIT_ADDR2_NO_ACK
 *             - I2C_DRV_ERR_10BIT_READ_NO_RSTRT
 *             - I2C_DRV_ERR_DATA_NO_ACK
 *             - I2C_DRV_ERR_MASTER_LOST
 *             - I2C_DRV_ERR_MASTER_DIS
 *             - I2C_DRV_ERR_SLAVE_ARBLOST
 *             - I2C_DRV_ERR_MASTER_ABRT
 *             - I2C_DRV_ERR_SLAVE_READ_REQ
 *             - I2C_DRV_ERR_SLAVE_FLUSH_TXFIFO
 *             - I2C_DRV_ERR_SDA_LOW_TIMEOUT
 *
 * @return     boolean: The status flag of error status register.
 * @retval     TRUE: Specified error status flag is set.
 * @retval     FALSE: Specified error status flag is reset.
 *
 */
boolean I2c_Drv_GetErrorStatus(I2c_Drv_IdType InstId, I2c_Drv_ErrorStatusType ErrorType);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c_Drv  */
/** @} end of group I2c_Module */

#endif /* I2C_DRV_H */
