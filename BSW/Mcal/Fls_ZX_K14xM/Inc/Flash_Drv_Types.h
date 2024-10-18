/**************************************************************************************************/
/**
 * @file      : Flash_Drv_Types.h  
 * @brief     : Internal flash low level driver types definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLASH_DRV_TYPES_H
#define FLASH_DRV_TYPES_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Flash_Drv_Types
 *  @brief Internal Flash low level driver types definition
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Flash_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"
#include "MemIf.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLASH_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define FLASH_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define FLASH_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define FLASH_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define FLASH_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Flash_Drv_Cfg.h are the same vendor */
#if (FLASH_DRV_TYPES_H_VENDOR_ID != FLASH_DRV_CFG_H_VENDOR_ID)
	#error "Vendor ID of Flash_Drv_Types.h and Flash_Drv_Cfg.h are different"
#endif
/* Check if current file and Flash_Drv_Cfg.h are the same Autosar version */
#if((FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
	(FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != FLASH_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
	(FLASH_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != FLASH_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version of Flash_Drv_Types.h and Flash_Drv_Cfg.h are different"
#endif
/* Check if current file and Flash_Drv_Cfg.h are the same Software version */
#if((FLASH_DRV_TYPES_H_SW_MAJOR_VERSION != FLASH_DRV_CFG_H_SW_MAJOR_VERSION) || \
	(FLASH_DRV_TYPES_H_SW_MINOR_VERSION != FLASH_DRV_CFG_H_SW_MINOR_VERSION) || \
	(FLASH_DRV_TYPES_H_SW_PATCH_VERSION != FLASH_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Flash_Drv_Types.h and Flash_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
	/* Check if current file and Std_Types.h are the same Autosar version */
    #if((FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version of Flash_Drv_Types.h and Std_Types.h are different"
    #endif
	/* Check if current file and McalLib.h are the same Autosar version */
	#if((FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
		(FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version of Flash_Drv_Types.h and McalLib.h are different"
	#endif
    /* Check if current file and MemIf.h are the same Autosar version */
    #if((FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
        (FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version of Fls_Types.h and MemIf.h are different"
    #endif
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */ 
/**
 * @brief  start access notification function pointer type
 */
typedef void (*Flash_Drv_StartAccessNotifType)(void);

/**
 * @brief  finish access notification function pointer type
 */
typedef void (*Flash_Drv_FinishAccessNotifType)(void);

/**
 * @brief Define pointer type of access code function
 */
typedef void (*Flash_Drv_AcPtrType)(void (*CallBack)(void));

/**
 * @brief Define pointer type of call back function
 */
typedef void (*Flash_Drv_CallBackType)(void);

/**
 * @brief Flash operation return type
 */
typedef enum
{
    FLASH_DRV_SUCCESS                   = 0U,    /*!< Successful */
    FLASH_DRV_BUSY                      = 1U,    /*!< busy */
    FLASH_DRV_CMD_ABORTED               = 2U,    /*!< a flash command has been aborted  */
    FLASH_DRV_ERR                       = 3U,    /*!< Error */
    FLASH_DRV_ERR_TIMEOUT               = 4U,    /*!< Error - timeout */
    FLASH_DRV_ERR_INPUT_PARAM           = 5U,    /*!< Error - wrong input parameter */
    FLASH_DRV_ERR_BLANK_CHECK           = 6U,    /*!< Error - checked memory area is not erased */
    FLASH_DRV_ERR_COMPARE               = 7U,    /*!< Error - checked memory area 
                                                              doesn't contain desired value */
    FLASH_DRV_ERR_ECC_S                 = 8U,    /*!< Error - single bit correction */
    FLASH_DRV_ERR_ECC_M                 = 9U,    /*!< Error - multi-bit detection */
    FLASH_DRV_ERR_HW_FAIL               = 10U,   /*!< Error - hardware fail */ 
} Flash_Drv_ReturnType;

/**
 *  @brief Flash status type definition
 */
typedef enum
{
    FLASH_DRV_STATUS_FAIL   = 0x00000001U,   /*!< command fail: an error is detected during execution
                                                of a flash command or during flash initialization */
    FLASH_DRV_STATUS_CMDABT = 0x00000004U,   /*!< Command Abort: Command is aborted during execution */
    FLASH_DRV_STATUS_ACCERR = 0x00000020U,   /*!< Access Error */
    FLASH_DRV_STATUS_PREABT = 0x00000040U,   /*!< Write Sequence Abort: a request to abort a command
                                                write sequence prior to command launch has been
                                                granted */
    FLASH_DRV_STATUS_CCIF   = 0x00000080U,   /*!< Command Complete: a flash command has completed */
    FLASH_DRV_STATUS_CMDWRF = 0x00000800U,   /*!< Flash command registers written: It is set by 
                                                writing FCMD/FADDR/FDATA registers or command 
                                                launching. And it is cleared after command 
                                                execution */
    FLASH_DRV_STATUS_DFDIF  = 0x00010000U,   /*!< Multi-bit ECC fault was detected during a valid 
                                                flash read */
    FLASH_DRV_STATUS_SFDIF  = 0x00020000U,   /*!< single-bit ECC fault was detected during a valid
                                                flash read */
    FLASH_DRV_STATUS_DBG_ERSALL_DIS = 0x40000000U   /*!< debug erase all request disable */
}Flash_Drv_StatusType;

/**
 * @brief Flash read status type
 */
typedef enum
{
    FLASH_DRV_READ_IDLE                 = 0U,    /*!< Successful */
    FLASH_DRV_READ_BUSY                 = 1U,    /*!< busy */
    FLASH_DRV_READ_ERROR                = 2U,    /*!< error */
} Flash_Drv_ReadStatusType;

/**
 * @brief Flash read state type
 */
typedef struct 
{  
    Flash_Drv_ReadStatusType Status;    /*!< the status of read operation */
    uint32 Address;                     /*!< the address that is read */        
} Flash_Drv_ReadStateType;


/**
 * @brief   Flash driver configuration type
 */
typedef struct 
{  
    Flash_Drv_StartAccessNotifType StartNotifPtr;    /*!< a pointer to start access notification
                                                          function */
    Flash_Drv_FinishAccessNotifType FinishNotifPtr;  /*!< a pointer to finish access notification
                                                          function */                                                      
    uint32 IgnoreBusErrStartAddr;                    /*!< The physical start address of the flash 
                                                          region to ignore bus error if Flash ECC 
                                                          multi-bit error happens during flash 
                                                          reading. The bit3-bit0 of the address 
                                                          should be always 0 */
    uint32 IgnoreBusErrEndAddr;                      /*!< The physical end address of the flash 
                                                          region to ignore bus error if Flash ECC 
                                                          multi-bit error happens during flash 
                                                          reading. The bit3-bit0 of the address 
                                                          should be always 0 */
     
} Flash_Drv_ConfigType;

/**
 * @brief Flash Command action Structure
 */
typedef struct
{
    boolean AsyncFlag;                 /*!< it indicates if the command shall be executed in  
                                            asynchronous mode or synchronous mode*/
                                 
    Flash_Drv_CallBackType CallBack;   /*!< Call back function to service the time critical 
                                            events. Any code reachable from this function
                                            must not be placed in a Flash block targeted for
                                            a program/erase operation. if 'AsyncFlag' paramenter is 
                                            set to FALSE, this callBack is called when waiting for
                                            the completion of command. If 'AsyncFlag' is TRUE, 
                                            this paramter can be ignored. If no callback function is
                                            needed, please set this parameter to NULL  */
    Flash_Drv_AcPtrType AcFunc;        /*!< It points to the access code function in the SRAM. 
                                            If it is not NULL,AcFunc will be called to wait for the 
                                            command finishing. */
} Flash_Drv_CmdActionType;
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *	@{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *	@{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Flash_Drv_Types */

/** @} end of group Fls_Module */

#endif /* FLASH_DRV_TYPES_H */
