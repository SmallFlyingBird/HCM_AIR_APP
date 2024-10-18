/**************************************************************************************************/
/**
 * @file      : CDD_I2c.h
 * @brief     : AUTOSAR I2c driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CDD_I2C_H
#define CDD_I2C_H

/** @addtogroup  I2c_Module
 *  @{
 */

/** @addtogroup  I2c
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_I2c_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CDD_I2C_MODULE_ID                   2055U
#define CDD_I2C_VENDOR_ID                   0x00B3U
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION    4U
#define CDD_I2C_AR_RELEASE_MINOR_VERSION    6U
#define CDD_I2C_AR_RELEASE_REVISION_VERSION 0U
#define CDD_I2C_SW_MAJOR_VERSION            1U
#define CDD_I2C_SW_MINOR_VERSION            2U
#define CDD_I2C_SW_PATCH_VERSION            1U

#if (CDD_I2C_VENDOR_ID != CDD_I2C_TYPES_H_VENDOR_ID)
    #error "Vendor ID CDD_I2c.h and CDD_I2c_Types.h have different"
#endif
    
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION != CDD_I2C_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (CDD_I2C_AR_RELEASE_MINOR_VERSION != CDD_I2C_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of CDD_I2c.h and CDD_I2c_Types.h are different"
#endif
    
#if ((CDD_I2C_SW_MAJOR_VERSION != CDD_I2C_TYPES_H_SW_MAJOR_VERSION) || \
        (CDD_I2C_SW_MINOR_VERSION != CDD_I2C_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of CDD_I2c.h and CDD_I2c_Types.h are different"
#endif

#if (STD_ON == I2C_DEV_ERROR_DETECT)
/**
* @brief API service ID for I2c_Init function
* */
#define I2C_SID_INIT                                            ((uint8)0x00U)

/**
* @brief API service ID for I2c_DeInit function
* */
#define I2C_SID_DEINIT                                          ((uint8)0x01U)

/**
* @brief API service ID for I2c_SyncTransmit function
* */
#define I2C_SID_SYNC_TRANSMIT                                        ((uint8)0x02U)

/**
* @brief API service ID for I2c_AsyncTransmit function
* */
#define I2C_SID_ASYNC_TRANSMIT                                        ((uint8)0x03U)

/**
* @brief API service ID for I2c_SetupSlaveBuffer function
* */
#define I2C_SID_SETUP_SLAVE_BUFFER                                  ((uint8)0x04U)

/**
* @brief API service ID for I2C_GetStatus function
* */
#define I2C_SID_GET_STATUS                                      ((uint8)0x05U)

/**
* @brief API service ID for I2c_GetVersionInfo function
* */
#define I2C_SID_GET_VERSION_INFO                                  ((uint8)0x06U)

/**
* @brief   API is called with invalid pointer
* */
#define I2C_E_PARAM_POINTER                                     ((uint8)0x0AU)

/**
* @brief   API service used with an invalid channel identifier or channel
*          was not configured for the functionality of the calling API
* */
#define I2C_E_PARAM_CHANNEL                                     ((uint8)0x0BU)

/**
* @brief   Init function failed
* */
#define I2C_E_INIT_FAILED                                       ((uint8)0x0CU)


/**
* @brief   API service used without module initialization
* */
#define I2C_E_UNINIT                                            ((uint8)0x0DU)

/**
* @brief   API I2c_Init service is called and when the I2C driver and the
*          Hardware are already initialized
* */
#define I2C_E_ALREADY_INITIALIZED                               ((uint8)0x0EU)

/**
* @brief   API I2c_GetVersionInfo is called and the parameter
*          versioninfo is is invalid ( e.g. NULL )
* */
#define I2C_E_PARAM_VINFO                                       ((uint8)0x10U)

#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (STD_ON == I2C_PRECOMPILE_SUPPORT)

    #define I2C_START_SEC_CONFIG_DATA_PTR
    #include "I2c_MemMap.h"

extern const I2c_ConfigType *const I2c_PredefinedConfigPtr[I2C_PARTITIONS_MAXNUM];

    #define I2C_STOP_SEC_CONFIG_DATA_PTR
    #include "I2c_MemMap.h"

#else
    #define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "I2c_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
I2C_CONFIG_EXT

    #define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "I2c_MemMap.h"
#endif /* (I2C_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @brief I2c functions declaration
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief      This function initializes the driver.
 *
 * @param[in]  ConfigPtr: Pointer to a I2c initial configuration structure
 *
 * @return none
 *
 */
void I2c_Init(const I2c_ConfigType * ConfigPtr);

/**
 * @brief      This function de-initializes the I2c module. 
 *
 * @param[in]  none
 *
 * @return     none
 *
 */
void I2c_DeInit(void);


/**
 * @brief      This function check whether status flag is set or not for given status type
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 *
 * @return    I2c_ChannelStateType
 *     I2C_UNINIT:  The driver is un-initialized
 *     I2C_IDLE:    The driver has no pending transfers
 *     I2C_BUSY:    The driver is busy
 *
 */
I2c_ChannelStateType I2c_GetStatus(I2c_ChannelType Channel);

/**
 * @brief      This function Sends or receives data I2c blocking 
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  RequestPtr: Request Buffer
 * 
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_SyncTransmit(I2c_ChannelType Channel, const I2c_RequestType * RequestPtr);

/**
 * @brief      This function Sends or receives data I2c block 
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  RequestPtr: Request Buffer
 * 
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_AsyncTransmit(I2c_ChannelType Channel, const I2c_RequestType * RequestPtr);

/**
 * @brief      This function check whether status flag is set or not for given status type
 *
 * @param[in]  Channel: Numeric identifier of the I2C channel
 * @param[in]  BufferSize Maximum number of bytes to be sent or received.
 * @param[in]  BufferPtr  Pointer to data buffer
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType I2c_SetupSlaveBuffer(I2c_ChannelType Channel, 
                                                        I2c_DataType * BufferPtr, 
                                                        uint8 BufferSize);

#if (STD_ON == I2C_GET_VERSION_INFO_API)
/**
 * @brief      This function returns the version information of this module.
 *
 * @param[out] versioninfo : Pointer to where to store the version information of this module.
 *
 * @return none
 *
 */
void I2c_GetVersionInfo(Std_VersionInfoType * const Versioninfo);
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c  */
/** @} end of group I2c_Module */

#endif  /* CDD_I2C_H */

