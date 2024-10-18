/**************************************************************************************************/
/**
 * @file      : I2c_Drv.h
 * @brief     : AUTOSAR Tim I2c hardware driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
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
extern "C"{
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
#define I2C_DRV_H_SW_PATCH_VERSION            1U

#if (I2C_DRV_H_VENDOR_ID != I2C_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID I2c_Drv.h and I2c_Drv_Types.h have different"
#endif

#if ((I2C_DRV_H_AR_RELEASE_MAJOR_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (I2C_DRV_H_AR_RELEASE_MINOR_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of I2c_Drv.h and I2c_Drv_Types.h are different"
#endif

#if ((I2C_DRV_H_SW_MAJOR_VERSION != I2C_DRV_TYPES_H_SW_MAJOR_VERSION) || \
        (I2C_DRV_H_SW_MINOR_VERSION != I2C_DRV_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of I2c_Drv.h and I2c_Drv_Types.h are different"
#endif

#if ((I2C_DRV_H_AR_RELEASE_REVISION_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION) || \
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
 * @brief      This function set slave receive or send data.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TxBuffer: Pointer to the buffer-array 
 * @param[in]  TxSize: Size of the external buffer
 *
 * @return I2c_Drv_StatusType
 * @retval I2C_DRV_STATE_IDLE  Success
 * 
 */
I2c_Drv_StatusType I2c_Drv_SetupSlaveBuffer(const I2c_Drv_IdType InstId,
                                                                uint8 *TxBuff,
                                                                uint32 TxSize);

/**
 * @brief      Set the target address .
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TargetAddr: The target address for any master transaction.
 * @param[in]  AddrBitMode: The I2C start its transfer in 7 or 10 bits address mode.
 * @param[in]  RestartSendData: The Restart direction of the data. Can be either Send or Receive.
 *
 * @return     none
 *
 */
void I2c_Drv_SetRequestConfig(const I2c_Drv_IdType InstId, 
                                                    uint16 TargetAddr, 
                                                    boolean AddrBitMode, 
                                                    boolean RestartSendData);


/**
 * @brief      Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void I2c_Drv_Init(const I2c_Drv_IdType InstId, const I2c_Drv_PhyUnitConfigType * I2cPhyUnitCfgPtr);

/**
 * @brief      De-Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void I2c_Drv_DeInit(const I2c_Drv_IdType InstId, 
                                                const I2c_Drv_PhyUnitConfigType * I2cPhyUnitCfgPtr);

/**
 * @brief      This function receive data i2c block.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  RxBuff: Pointer to the buffer-array 
 * @param[in]  RxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterReceiveData(const I2c_Drv_IdType InstId,
                                                                    uint8 *RxBuff,
                                                                    uint32 RxSize,
                                                                    boolean SendStop);


/**
 * @brief      This function receive data i2c block.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TxBuffer: Pointer to the buffer-array 
 * @param[in]  TxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterSendData(const I2c_Drv_IdType InstId,
                                                                uint8 * TxBuffer,
                                                                uint32 TxSize,
                                                                boolean SendStop);

/**
 * @brief      Get I2c status
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  I2cPhyUnitCfgPtr: Pointer that contains driver configuration data 
 *
 * @return I2c_Drv_ChannelStateType
 *
 */
I2c_Drv_ChannelStateType I2c_Drv_GetStatus(const I2c_Drv_IdType InstId, 
                                            const I2c_Drv_PhyUnitConfigType * I2cPhyUnitCfgPtr);

/**
 * @brief      This function transmission data i2c blocking.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TxBuffer: Pointer to the buffer-array 
 * @param[in]  TxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterSendDataBlocking(const I2c_Drv_IdType InstId,
                                                                        uint8 * TxBuffer,
                                                                        uint32 TxSize,
                                                                        boolean SendStop);

/**
 * @brief      This function receive data i2c blocking.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  RxBuff: Pointer to the buffer-array 
 * @param[in]  RxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterReceiveDataBlocking(const I2c_Drv_IdType InstId,
                                                                                uint8 * RxBuff,
                                                                                uint32 RxSize,
                                                                                boolean SendStop);

/**
 * @brief      This function handles I2c interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */
void I2c_Drv_ChIntHandler(I2c_Drv_IdType InstId);                                                           

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c_Drv  */
/** @} end of group I2c_Module */

#endif  /* I2C_DRV_H */

