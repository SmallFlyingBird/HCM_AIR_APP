/**************************************************************************************************/
/**
 * @file      : CDD_I2c_Types.h
 * @brief     : AUTOSAR I2c types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CDD_I2C_TYPES_H
#define CDD_I2C_TYPES_H

/** @addtogroup  I2c_Module
 *  @{
 */

/** @addtogroup  I2c
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "CDD_I2c_Cfg.h"
#include "I2c_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CDD_I2C_TYPES_H_VENDOR_ID                   0x00B3U
#define CDD_I2C_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_I2C_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CDD_I2C_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CDD_I2C_TYPES_H_SW_MAJOR_VERSION            1U
#define CDD_I2C_TYPES_H_SW_MINOR_VERSION            2U
#define CDD_I2C_TYPES_H_SW_PATCH_VERSION            1U

#if (CDD_I2C_TYPES_H_VENDOR_ID != CDD_I2C_CFG_H_VENDOR_ID)
    #error "Vendor ID CDD_I2c_Types.h and CDD_I2c_Cfg.h have different"
#endif
    
#if ((CDD_I2C_TYPES_H_AR_RELEASE_MAJOR_VERSION != CDD_I2C_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (CDD_I2C_TYPES_H_AR_RELEASE_MINOR_VERSION != CDD_I2C_CFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of CDD_I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif
    
#if ((CDD_I2C_TYPES_H_SW_MAJOR_VERSION != CDD_I2C_CFG_H_SW_MAJOR_VERSION) || \
        (CDD_I2C_TYPES_H_SW_MINOR_VERSION != CDD_I2C_CFG_H_SW_MINOR_VERSION))
    #error "Software version of CDD_I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif

#if ((CDD_I2C_TYPES_H_AR_RELEASE_REVISION_VERSION != CDD_I2C_CFG_H_AR_RELEASE_REVISION_VERSION) || \
        (CDD_I2C_TYPES_H_SW_PATCH_VERSION != CDD_I2C_CFG_H_SW_PATCH_VERSION))
    #error "Software version of CDD_I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @brief Type for giving the I2c Channel ID
*/
typedef uint8                       I2c_ChannelType;

/** @brief Type for giving the I2c Type Address Value
*/
typedef uint16                       I2c_AddressType;

/**
 * @brief  Type for giving the I2c Data to be sent or received
 */
typedef uint8                          I2c_DataType;

/**
 * @brief Definition for different state and errors of Operation Status for I2C Handler Driver
 *
*/
typedef enum
{
    I2C_STATE_IDLE          = 0U,  /*!< The I2C no transfer request. */
    I2C_STATE_SEND,                /*!< The I2C transmit data. */
    I2C_STATE_RECEIVE,             /*!< The I2C receive data. */
    I2C_STATE_FINISHED,            /*!< The I2C operation is finished */
    I2C_STATE_ERROR_PRESENT        /*!< The I2C is performing an error is present */
} I2c_ChannelStateType;

/**
 *  @brief Definition of the type of mode
 */
typedef enum
{
    I2C_MASTER_MODE = 0U,                             /*!< I2C master mode.*/
    I2C_SLAVE_MODE                                    /*!< I2C slave mode.*/
} I2c_ModeType;

/**
 * @brief Definition of the type of activation or procession mechanism of an I2C hw unit
 */
typedef enum
{
    I2C_SEND_DATA       = 0U, /*!< Used to send data to a slave */
    I2C_RECEIVE_DATA          /*!< Used to receive data from a slave */
} I2c_DataDirectionType;

/**
 * @brief Structure that contains channel configuration
 * */
typedef struct
{
    uint8 I2cChanelId;    /*!< The number of driver channel configured */
    I2c_ModeType MasterSlaveMode;  /*!< type of function mode */
    const I2c_Drv_PhyUnitConfigType * I2cPhyUnitCfgPtr; /*!< Pointer to the list of I2c 
                                                                            configured instances */
} I2c_ChannelConfigType;

/**
 * @brief Structure that contains initialization data
 * */
typedef struct
{
    uint8 CoreId; /*!< core Id */
    const I2c_ChannelConfigType (* I2cChCfgPtr)[]; /*!< Pointer to the list of I2c 
                                                    configured channels */
} I2c_ConfigType;

/**
 * @brief Structure that definition for Request Buffer. 
*/
typedef struct
{
    /*!< Slave address when the I2C is operating as a slave.
                                             This parameter can be a 7-bit or 10-bit address. */
    I2c_AddressType                  OwnSlaveAddr; 

    /*!< This is true when the slave address is 10 bits, when false the address is on 7 bits */
    /*!< I2C start its transfer in 7 or 10 bits address mode
                                            - TRUE: 10 bits address mode
                                            - FALSE: 7 bits address mode */
    boolean                          AddrBitMode; 

    boolean Restart;                    /*!< Determines whether RESTART conditions may be sent when 
                                            acting as a master.
                                            - ENABLE: enable RESTART condition
                                            - DISABLE: disable RESTART condition
                                            When the RESTART is disabled, the I2C module master is 
                                            incapable of performing the following functions:
                                            - Sending a START BYTE
                                            - Performing any high-speed mode operation
                                            - Performing direction changes in combined format mode
                                            - Performing a read operation with a 10-bit address */
    boolean RestartSendData;    /*!<Restart direction of the data. Can be either Send or Receive.     
                                            - TRUE: receive data 
                                            - FALSE: Send data */

    /*!< Buffer Size : The number of bytes for reading or writing.*/
    uint16                           BufferSize;

    /*!<Direction of the data. Can be either Send or Receive. */
    I2c_DataDirectionType            DataDirection;

    /*!< Buffer to Store or to transmit Serial data */
    I2c_DataType *    DataBuffer;

} I2c_RequestType;

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

/** @} end of group I2c  */
/** @} end of group I2c_Module */

#endif  /* CDD_I2C_TYPES_H */

