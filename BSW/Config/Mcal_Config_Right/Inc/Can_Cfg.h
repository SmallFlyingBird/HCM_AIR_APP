/***************************************************************************************************/
/**
 * @file      : Can_Cfg.h  
 * @brief     : Can AUTOSAR level - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_CFG_H
#define CAN_CFG_H

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Configuration
 *  @brief Can AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_PBcfg.h"

/** @defgroup Public_MacroDefinition
*  @{
*/

/* Published information */
#define CAN_CFG_H_VENDOR_ID                   0x00B3U
#define CAN_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_CFG_H_SW_MAJOR_VERSION            1U
#define CAN_CFG_H_SW_MINOR_VERSION            2U
#define CAN_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Can_PBcfg.h are of the same vendor */
#if (CAN_CFG_H_VENDOR_ID != CAN_PBCFG_H_VENDOR_ID)
#error "Vendor ID of Can_Cfg.h and Can_PBcfg.h are different"
#endif
/* Check if current file and Can_PBcfg.h are of the same Autosar version */
#if ((CAN_CFG_H_AR_RELEASE_MAJOR_VERSION != CAN_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
(CAN_CFG_H_AR_RELEASE_MINOR_VERSION != CAN_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
(CAN_CFG_H_AR_RELEASE_REVISION_VERSION != CAN_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Can_Cfg.h and Can_PBcfg.h are different"
#endif
/* Check if current file and Can_PBcfg.h are of the same software version */
#if ((CAN_CFG_H_SW_MAJOR_VERSION != CAN_PBCFG_H_SW_MAJOR_VERSION) || \
(CAN_CFG_H_SW_MINOR_VERSION != CAN_PBCFG_H_SW_MINOR_VERSION) ||\
(CAN_CFG_H_SW_PATCH_VERSION != CAN_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Can_Cfg.h and Can_PBcfg.h are different"
#endif

/**
*   @brief      Message buffer index which not assigned for any Hw Object
*/
#define CAN_HWOBJ_UNMAPPED    ((Can_HwHandleType)0xFFU)

/**
*  @brief      Number Of Can Controller Config
*/
#define CAN_HWNUMBER_SUPPORT    8U

/**
*  @brief      CAN wake polling mask 
*/
#define CAN_WAKE_POLLING_MASK        (0x00000001U)

/**
*  @brief      The definition represent for number of ECUC partition configured.
*/
#define CAN_MAX_PARTITIONS    1U

/**
*  @brief      Enable/Disable Precompile Support
*/
#define CAN_PRECOMPILE_SUPPORT    (STD_OFF)


/**
*   @brief      Enable/Disable support Can_GetVersionInfo API
*/
#define CAN_VERSION_INFO_API    (STD_OFF)

/**
*  @brief Enable/Disable Development Error Detection and Notification.
*/
#define CAN_DEV_ERROR_DETECT    (STD_OFF)

/**
*   @brief      Instance of the Can Hw unit
*/
#define CAN_INSTANCE    ((uint8)0U)

/**
*   @brief     Enable/Disable  baudrate support
*/
#define CAN_SET_BAUDRATE_API    (STD_OFF)

/**
*   @brief      Enable/Disable support Can_AbortHwObjectSend API
*/
#define CAN_ABORT_HW_OBJECT_SEND_API    (STD_ON)

/**
*   @brief      Enable/Disable support SecurityEventReporting
*/
#define CAN_SEC_EVENT_REPORT_SUPPORT    (STD_OFF)

/**
* @brief          Enable/Disable LPdu Receive callout function support
*/
#define CAN_LPDU_CALLOUT_SUPPORT    (STD_ON)

/**
* @brief    Define LPDU Function
*/
#define CAN_LPDU_CALLOUT_FUNC_CALLED    Interface_CanRcvMessageCallOut

/**
*   @brief      Define period of CAN Tx/Rx
*/
#define CAN_MAINFUNCTION_MULTIPLE_WRITE    (STD_OFF)
#define CAN_MAINFUNCTION_MULTIPLE_READ    (STD_OFF)

/**
*   @brief      Can MainFunction period
*/
#define CAN_MAINFUNCTION_MODE_PERIOD    (0.01F)



/**
*   @brief       trigger transmit configure.
*/
#define CAN_TRIGGER_TRANSMIT_USED    (STD_OFF)

/**
*   @brief      Can Rx/Tx common interrupt support
*/
#define CAN_MB_INTERRUPT_SUPPORT    (STD_ON)
/**
*   @brief     Can controller configure number
*/
#define CAN_CONTROLLER_CONFIG_COUNT    (1U)

/**
*   @brief      Number Of Hw Message Buffer support
*/
#define CAN_HWMB_COUNT    ((uint8)128U)

/**
*   @brief      HardwareObject Config Number 
*/
#define CAN_HWOBJECT_CONFIG_COUNT    ((Can_HwHandleType)73U)

/**
*   @brief      Symbolic Name generated for Can Controller
*/
#define CanConf_CanController_CanController_HCML    ((uint8)0U)

/**
*   @brief      Symbolic Name generated for Can HardwareObject
*/
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonSignalIPdu09    ((Can_HwHandleType)0U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonSignalIPdu10    ((Can_HwHandleType)1U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonSignalIPdu19    ((Can_HwHandleType)2U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonSignalIPdu17    ((Can_HwHandleType)3U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonSignalIPDU05    ((Can_HwHandleType)4U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemToAllFuncBodyCanExposedDiagReqFrame    ((Can_HwHandleType)5U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemToHcmrBodyCanExposedDiagReqFrame    ((Can_HwHandleType)6U)
#define CanConf_CanHardwareObject_CanHardwareObject_EtctoHcmrXCPFr01    ((Can_HwHandleType)7U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr21    ((Can_HwHandleType)8U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr20    ((Can_HwHandleType)9U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr15    ((Can_HwHandleType)10U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr02    ((Can_HwHandleType)11U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr14    ((Can_HwHandleType)12U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr18    ((Can_HwHandleType)13U)
#define CanConf_CanHardwareObject_CanHardwareObject_CEMBodyExpoCommonFr07    ((Can_HwHandleType)14U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr08    ((Can_HwHandleType)15U)
#define CanConf_CanHardwareObject_CanHardwareObject_CEMBodyExpoCommonFr06    ((Can_HwHandleType)16U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr13    ((Can_HwHandleType)17U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr16    ((Can_HwHandleType)18U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr01    ((Can_HwHandleType)19U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr11    ((Can_HwHandleType)20U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr12    ((Can_HwHandleType)21U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr22    ((Can_HwHandleType)22U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr01    ((Can_HwHandleType)23U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr07    ((Can_HwHandleType)24U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr100    ((Can_HwHandleType)25U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr101    ((Can_HwHandleType)26U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr102    ((Can_HwHandleType)27U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr103    ((Can_HwHandleType)28U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr104    ((Can_HwHandleType)29U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr105    ((Can_HwHandleType)30U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr106    ((Can_HwHandleType)31U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr107    ((Can_HwHandleType)32U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr108    ((Can_HwHandleType)33U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr109    ((Can_HwHandleType)34U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr110    ((Can_HwHandleType)35U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr111    ((Can_HwHandleType)36U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr112    ((Can_HwHandleType)37U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr113    ((Can_HwHandleType)38U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr114    ((Can_HwHandleType)39U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr115    ((Can_HwHandleType)40U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr116    ((Can_HwHandleType)41U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr25    ((Can_HwHandleType)42U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr29    ((Can_HwHandleType)43U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr31    ((Can_HwHandleType)44U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr33    ((Can_HwHandleType)45U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr35    ((Can_HwHandleType)46U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr37    ((Can_HwHandleType)47U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr38    ((Can_HwHandleType)48U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr42    ((Can_HwHandleType)49U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr45    ((Can_HwHandleType)50U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr50    ((Can_HwHandleType)51U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr51    ((Can_HwHandleType)52U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr59    ((Can_HwHandleType)53U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr61    ((Can_HwHandleType)54U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr66    ((Can_HwHandleType)55U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr67    ((Can_HwHandleType)56U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr91    ((Can_HwHandleType)57U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr92    ((Can_HwHandleType)58U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr93    ((Can_HwHandleType)59U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr94    ((Can_HwHandleType)60U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr95    ((Can_HwHandleType)61U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr96    ((Can_HwHandleType)62U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr97    ((Can_HwHandleType)63U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr98    ((Can_HwHandleType)64U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoFr99    ((Can_HwHandleType)65U)
#define CanConf_CanHardwareObject_CanHardwareObject_HcmrBodyExposedNMFr    ((Can_HwHandleType)66U)
#define CanConf_CanHardwareObject_CanHardwareObject_CemBodyExpoCommonFr04    ((Can_HwHandleType)67U)
#define CanConf_CanHardwareObject_CanHardwareObject_HcmrBodyExpoFr02    ((Can_HwHandleType)68U)
#define CanConf_CanHardwareObject_CanHardwareObject_HcmrBodyExpoFr04    ((Can_HwHandleType)69U)
#define CanConf_CanHardwareObject_HcmrBodyExposedNMFr    ((Can_HwHandleType)70U)
#define CanConf_CanHardwareObject_HcmrToCemBodyCanExposedDiagResFrame    ((Can_HwHandleType)71U)
#define CanConf_CanHardwareObject_HcmrtoEtcXCPFr01    ((Can_HwHandleType)72U)

/**
*   @brief      Can WakeUp configure
*/
#define CAN_WAKEUP_FUNCTIONALITY_API    (STD_OFF)

/**
*   @brief      Instance of the Can wakeup
*/
#define CAN_WAKEUP_SUPPORT    (STD_OFF)

/**
*   @brief      Can Tx polling configure
*/
#define CAN_TX_POLLING_SUPPORT    (STD_OFF)
/**
*   @brief      Can Rx polling configure
*/
#define CAN_RX_POLLING_SUPPORT    (STD_OFF)
/**
*   @brief      Can bus off polling configure
*/
#define CAN_BUSOFF_POLLING_SUPPORT    (STD_OFF)

/**
*   @brief      Can Wakeup Polling configure
*/
#define CAN_WAKEUP_POLLING_SUPPORT    (STD_OFF)

/**
* @brief        Definition of none EcuM wakeup source defined
*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)
#define CAN_NONE_ECUM_WAKEUP_SOURCE_REF     (0U)
#endif

/**
*  @brief Enable/Disable CAN FD mode
*/
#define CAN_FD_MODE_ENABLE          CAN_DRV_FD_MODE_ENABLE

#define CAN_CONFIG_EXT \
    CAN_CONFIG_PB

/**
*   @brief     Define Name of CanMainFunction
*/
#define CAN_MAINFUNCTIONRWPERIODS_0    0U

/**
 *  @brief      CAN bus off polling mask 
 */
#define CAN_BUSOFF_POLLING_MASK    (0x00000002U)

/**
*   @brief      Can error interrupt support
*/
#define CAN_ERROR_INTERRUPT_SUPPORT             CAN_DRV_ERROR_INTERRUPT_SUPPORT

/**
*   @brief      Can DMA feature support ot not
*/
#define CAN_FEATURE_HAS_DMA_ENABLE              CAN_DRV_FEATURE_HAS_DMA_ENABLE

/**
*   @brief      Can FD feature support or not
*/
#define CAN_FEATURE_HAS_FD                      CAN_DRV_FEATURE_HAS_FD

/**
*   @brief      Can ecc interrupt support
*/
#define CAN_ECC_INTERRUPT_SUPPORT               CAN_DRV_ECC_INTERRUPT_SUPPORT

/**
*   @brief      Can error injection support
*/
#define CAN_ERROR_INJECTION_SUPPORT             CAN_DRV_ERROR_INJECTION_SUPPORT

#if(STD_ON == CAN_ECC_INTERRUPT_SUPPORT)
/**
 *  @brief      CAN host memory mask 
 */
#define CAN_HOST_MEM_MASK    (0x00080000U)

/**
 *  @brief      CAN memory mask 
 */
#define CAN_MEM_MASK    (0x00040000U)

/**
 *  @brief      CAN correctable memory mask 
 */
#define CAN_COR_MEM_MASK    (0x00010000U)
#endif

/**
*   @brief       trigger transmit configure.
*/
#define CAN_TRIGGER_TRANSMIT_USED    (STD_OFF)


/**
*   @brief      Instance of the Can bus off interrupt
*/
#define CAN_BUSOFF_INTERRUPT_SUPPORT    (STD_ON)


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#define CAN_ERROR_NOTIFICATION_CFG_EXT \

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Public_FunctionDeclaration */



#ifdef __cplusplus
}
#endif
/** @} end of group Can_Configuration */

/** @} end of group Can_Module */
#endif /* CAN_CFG_H */
