/**************************************************************************************************/
/**
 * @file      : CDD_I2c_Types.h
 * @brief     : AUTOSAR I2c types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
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
extern "C" {
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
#define CDD_I2C_TYPES_H_SW_PATCH_VERSION            2U

#if (CDD_I2C_TYPES_H_VENDOR_ID != CDD_I2C_CFG_H_VENDOR_ID)
    #error "Vendor ID of CDD_I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif

#if ((CDD_I2C_TYPES_H_AR_RELEASE_MAJOR_VERSION != CDD_I2C_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (CDD_I2C_TYPES_H_AR_RELEASE_MINOR_VERSION != CDD_I2C_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (CDD_I2C_TYPES_H_AR_RELEASE_REVISION_VERSION != CDD_I2C_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif

#if ((CDD_I2C_TYPES_H_SW_MAJOR_VERSION != CDD_I2C_CFG_H_SW_MAJOR_VERSION) ||                       \
     (CDD_I2C_TYPES_H_SW_MINOR_VERSION != CDD_I2C_CFG_H_SW_MINOR_VERSION) ||                       \
     (CDD_I2C_TYPES_H_SW_PATCH_VERSION != CDD_I2C_CFG_H_SW_PATCH_VERSION))
    #error "Software version of CDD_I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif

#if (CDD_I2C_TYPES_H_VENDOR_ID != I2C_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of CDD_I2c_Types.h and I2c_Drv_Types.h are different"
#endif

#if ((CDD_I2C_TYPES_H_AR_RELEASE_MAJOR_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (CDD_I2C_TYPES_H_AR_RELEASE_MINOR_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||     \
     (CDD_I2C_TYPES_H_AR_RELEASE_REVISION_VERSION != I2C_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of CDD_I2c_Types.h and I2c_Drv_Types.h are different"
#endif

#if ((CDD_I2C_TYPES_H_SW_MAJOR_VERSION != I2C_DRV_TYPES_H_SW_MAJOR_VERSION) ||                     \
     (CDD_I2C_TYPES_H_SW_MINOR_VERSION != I2C_DRV_TYPES_H_SW_MINOR_VERSION) ||                     \
     (CDD_I2C_TYPES_H_SW_PATCH_VERSION != I2C_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software version of CDD_I2c_Types.h and I2c_Drv_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((CDD_I2C_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (CDD_I2C_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of CDD_I2c_Types.h and McalLib.h are different"
    #endif

    #if ((CDD_I2C_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (CDD_I2C_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of CDD_I2c_Types.h and Std_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @brief Type for giving the I2c Channel ID
 */
typedef uint8 I2c_ChannelType;

/** @brief Type for giving the I2c Type Address Value
 */
typedef uint16 I2c_AddressType;

/**
 * @brief  Type for giving the I2c Data to be sent or received
 */
typedef uint8 I2c_DataType;

/**
 * @brief  Type for giving the I2c master or slave event
 */
typedef uint8 I2c_EventType;

/**
 *  @brief The I2C notification function type definition
 */
typedef void (*I2c_NotifyType)(I2c_EventType Event, I2c_ChannelType Channel);

/**
 * @brief Definition for different state and errors of Operation Status for I2C Driver
 *
 */
typedef enum
{
    I2C_STATE_IDLE = 0U,    /*!< The I2C idle state and can accept transmit request. */
    I2C_STATE_BUSY,         /*!< The I2C busy transmitting data state. */
    I2C_STATE_ERROR_PRESENT /*!< The I2C error state presented during last transmission. */
} I2c_ChannelStateType;

/**
 * @brief Definition of the type of direction of the data transmission.
 */
typedef enum
{
    I2C_SEND_DATA = 0U, /*!< Used to send data to a slave */
    I2C_RECEIVE_DATA    /*!< Used to receive data from a slave */
} I2c_DataDirectionType;

/**
 * @brief Structure that contains channel configuration
 */
typedef struct
{
    uint8                            I2cChanelId;   /*!< The number of driver channel configured */
    uint8                            ChannelCoreId; /*!< The number of core Id configured */
    const I2c_Drv_PhyUnitConfigType *I2cPhyUnitCfgPtr; /*!< Pointer to the list of I2c
                                                                           configured instances */
    I2c_NotifyType I2cNotification;      /* Pointer to channel notification function */
    I2c_NotifyType I2cErrorNotification; /* Pointer to channel error notification function */
} I2c_ChannelConfigType;

/**
 * @brief Structure that contains initialization data
 */
typedef struct
{
    uint8                        CoreId;      /*!< core Id */
    const I2c_ChannelConfigType *I2cChCfgPtr; /*!< Pointer to the list of I2c
                                                   configured channels */
} I2c_ConfigType;

/**
 * @brief Structure that definition for Request Buffer.
 */
typedef struct
{
    I2c_AddressType SlaveAddr; /*!< Target slave address when the I2C is operating as a master.
                                    This parameter can be a 7-bit or 10-bit address. */

    boolean AddrBitMode; /*!< I2C start its transfer in 7 or 10 bits address mode
                                             - TRUE: 10 bits address mode
                                             - FALSE: 7 bits address mode */

    boolean Restart; /*!< Determines whether RESTART conditions may be sent when acting as a master.
                         - ENABLE: enable RESTART condition
                         - DISABLE: disable RESTART condition */

    uint16 BufferSize; /*!< BufferSize: The number of bytes for reading or writing.*/

    I2c_DataDirectionType DataDirection; /*!< Direction of the data transmission.
                                              Can be either Send or Receive. */

    I2c_DataType *DataBuffer; /*!< Buffer to send or receive serial data */

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

#endif /* CDD_I2C_TYPES_H */
