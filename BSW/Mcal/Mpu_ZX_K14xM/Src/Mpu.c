/**************************************************************************************************/
/**
 * @file      : Mpu.c
 * @brief     :  Memory protect unit source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Mpu_Module
 *  @{
 */

/** @addtogroup Mpu
 *  @brief Mpu handle api
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mpu.h"
#include "Smpu_Drv.h"
#include "Mpu_Externals.h"

#if (MPU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* (MPU_DEV_ERROR_DETECT == STD_ON) */

/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 *  @brief Published information
 */
#define MPU_C_VENDOR_ID                   0x00B3U
#define MPU_C_AR_RELEASE_MAJOR_VERSION    4U
#define MPU_C_AR_RELEASE_MINOR_VERSION    6U
#define MPU_C_AR_RELEASE_REVISION_VERSION 0U
#define MPU_C_SW_MAJOR_VERSION            1U
#define MPU_C_SW_MINOR_VERSION            1U
#define MPU_C_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Mpu header file are of the same vendor
 */
#if (MPU_C_VENDOR_ID != MPU_VENDOR_ID)
    #error "Vendor ID of Mpu.c and Mpu.h are different"
#endif

/**
 *  @brief Check if current file and Mpu header file are of the same Autosar version
 */
#if ((MPU_C_AR_RELEASE_MAJOR_VERSION != MPU_AR_RELEASE_MAJOR_VERSION) ||                           \
     (MPU_C_AR_RELEASE_MINOR_VERSION != MPU_AR_RELEASE_MINOR_VERSION) ||                           \
     (MPU_C_AR_RELEASE_REVISION_VERSION != MPU_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu.c and Mpu.h are different"
#endif

/**
 *  @brief Check if current file and Mpu header file are of the same SW version
 */
#if ((MPU_C_SW_MAJOR_VERSION != MPU_SW_MAJOR_VERSION) ||                                           \
     (MPU_C_SW_MINOR_VERSION != MPU_SW_MINOR_VERSION) ||                                           \
     (MPU_C_SW_PATCH_VERSION != MPU_SW_PATCH_VERSION))
    #error "Software Version of Mpu.c and Mpu.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv.h are of the same vendor
 */
#if (MPU_C_VENDOR_ID != SMPU_DRV_H_VENDOR_ID)
    #error "Vendor ID Mpu.c and Smpu_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv.h are of the same Autosar version
 */
#if ((MPU_C_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (MPU_C_AR_RELEASE_MINOR_VERSION != SMPU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (MPU_C_AR_RELEASE_REVISION_VERSION != SMPU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu.c and Smpu_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv.h are of the same SW version
 */
#if ((MPU_C_SW_MAJOR_VERSION != SMPU_DRV_H_SW_MAJOR_VERSION) ||                                    \
     (MPU_C_SW_MINOR_VERSION != SMPU_DRV_H_SW_MINOR_VERSION) ||                                    \
     (MPU_C_SW_PATCH_VERSION != SMPU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mpu.c and Smpu_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Externals.h are of the same vendor
 */
#if (MPU_C_VENDOR_ID != MPU_EXTERNALS_H_VENDOR_ID)
    #error "Vendor ID Mpu.c and Mpu_Externals.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Externals.h are of the same Autosar version
 */
#if ((MPU_C_AR_RELEASE_MAJOR_VERSION != MPU_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (MPU_C_AR_RELEASE_MINOR_VERSION != MPU_EXTERNALS_H_AR_RELEASE_MINOR_VERSION) ||               \
     (MPU_C_AR_RELEASE_REVISION_VERSION != MPU_EXTERNALS_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu.c and Mpu_Externals.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Externals.h are of the same SW version
 */
#if ((MPU_C_SW_MAJOR_VERSION != MPU_EXTERNALS_H_SW_MAJOR_VERSION) ||                               \
     (MPU_C_SW_MINOR_VERSION != MPU_EXTERNALS_H_SW_MINOR_VERSION) ||                               \
     (MPU_C_SW_PATCH_VERSION != MPU_EXTERNALS_H_SW_PATCH_VERSION))
    #error "Software Version of Mpu.c and Mpu_Externals.h are different"
#endif

#if (MPU_DEV_ERROR_DETECT == STD_ON)
    #ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
        /* Check if current file and Det.h are of the same Autosar version */
        #if ((MPU_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                   \
             (MPU_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Mpu.c and Det.h are different"
        #endif
    #endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
#endif     /* MPU_DEV_ERROR_DETECT */

#define MPU_PARAM_UNUSED(param)     ((void)((param)))
/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
#if (MPU_DEV_ERROR_DETECT == STD_ON)
/**
 *  @brief Type of the state of Mpu
 */
typedef enum
{
    MPU_UNINIT = 0x00U, /*!< Mpu module uninitialized. */
    MPU_INIT            /*!< Mpu module initialized. */
} Mpu_StateType;
#endif
/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#if (MPU_DEV_ERROR_DETECT == STD_ON)
#define MPU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mpu_MemMap.h"

/**
 *  @brief Variable that indicates the state of the Mpu.
 */
static Mpu_StateType Mpu_Status = MPU_UNINIT;

#define MPU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mpu_MemMap.h"
#endif

#define MPU_START_SEC_VAR_INIT_PTR
#include "Mpu_MemMap.h"

/**
 * @brief Local copy of the pointer to the configuration data
 */
static const Mpu_ConfigType *Mpu_ConfigPtr = NULL_PTR;

static Mpu_ErrCallBackFunType  Mpu_ErrorCallbackFunc = MPU_ERRORNOTIFICATIONPTR;
#define MPU_STOP_SEC_VAR_INIT_PTR
#include "Mpu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define MPU_START_SEC_CODE
#include "Mpu_MemMap.h"

#if (MPU_DEV_ERROR_DETECT == STD_ON)
static boolean Mpu_CheckInit(const Mpu_ConfigType *ConfigPtr);
#endif

#if ((MPU_VERSION_INFO_API == STD_ON) && (MPU_DEV_ERROR_DETECT == STD_ON))
static boolean Mpu_CheckGetVersionInfo(const Std_VersionInfoType *VersionInfoPtr);
#endif

#define MPU_STOP_SEC_CODE
#include "Mpu_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define MPU_START_SEC_CODE
#include "Mpu_MemMap.h"

#if (MPU_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks status to execute init service.
 *
 * @param[in]  ConfigPtr: Pointer to the Mpu configuration.
 *
 * @return    boolean: 
 * @retval    TRUE : check result is ready to execute mpu init service 
 * @retval    FALSE :check result is not ready .
 */
static boolean Mpu_CheckInit(const Mpu_ConfigType *ConfigPtr)
{
    boolean CheckResult = TRUE;

    if (MPU_UNINIT != Mpu_Status)
    {
        CheckResult = FALSE;
        (void)Det_ReportError((uint16)MPU_MODULE_ID, MPU_INSTANCE_ID, MPU_SID_INIT,
                              MPU_E_ALREADY_INITIALIZED);
    }
    else
    {
    #if (MPU_PRECOMPILE_SUPPORT == STD_OFF)
        if (NULL_PTR == ConfigPtr)
        {
            CheckResult = FALSE;
            (void)Det_ReportError((uint16)MPU_MODULE_ID, MPU_INSTANCE_ID, MPU_SID_INIT,
                                  MPU_E_NULL_POINTER);
        }
    #else
        if (NULL_PTR != ConfigPtr)
        {
            CheckResult = FALSE;
            (void)Det_ReportError((uint16)MPU_MODULE_ID, MPU_INSTANCE_ID, MPU_SID_INIT,
                                  MPU_E_PARAM_INVALID);
        }
    #endif /* (MPU_PRECOMPILE_SUPPORT == STD_OFF) */
    }

    return CheckResult;
}

#endif /* (MPU_DEV_ERROR_DETECT == STD_ON) */

#if ((MPU_VERSION_INFO_API == STD_ON) && (MPU_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief      Checks status to execute get version info service.
 *
 * @param[out]  VersionInfoPtr: Pointer to store the software version info.
 *
 * @return    boolean: 
 * @retval    TRUE : check result is ready to execute mpu init service 
 * @retval    FALSE :check result is not ready .
 */
static boolean Mpu_CheckGetVersionInfo(const Std_VersionInfoType *VersionInfoPtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == VersionInfoPtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)MPU_MODULE_ID, MPU_INSTANCE_ID, MPU_SID_GET_VERSION_INFO,
                              MPU_E_NULL_POINTER);
    }

    return CheckStatus;
}
#endif /* ((MPU_VERSION_INFO_API == STD_ON) && (MPU_DEV_ERROR_DETECT == STD_ON)) */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

#if (MPU_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersionInfoPtr: Pointer to where to store the version information of this module.
 *
 * @return    None
 */
void Mpu_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
    #if (MPU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Mpu_CheckGetVersionInfo(VersionInfoPtr))
    {
    #endif /* (MPU_DEV_ERROR_DETECT == STD_ON) */

        (VersionInfoPtr)->vendorID = (uint16)MPU_VENDOR_ID;
        (VersionInfoPtr)->moduleID = (uint16)MPU_MODULE_ID;
        (VersionInfoPtr)->sw_major_version = (uint8)MPU_SW_MAJOR_VERSION;
        (VersionInfoPtr)->sw_minor_version = (uint8)MPU_SW_MINOR_VERSION;
        (VersionInfoPtr)->sw_patch_version = (uint8)MPU_SW_PATCH_VERSION;

    #if (MPU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (MPU_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (MPU_VERSION_INFO_API == STD_ON) */

/**
 * @brief      Init Mpu global config and memory region config.
 *
 * @param[in]  ConfigPtr: Global configuration for Mpu.
 * 
 * @return     None
 * 
 */
void Mpu_Init(const Mpu_ConfigType *ConfigPtr)
{
    uint8 MemoryRegionIndex = 0U;
    const Smpu_Drv_RegionConfigType *SmpuRegionConfigPtr;
#if (MPU_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Mpu_CheckInit(ConfigPtr))
    {
#endif /* (MPU_DEV_ERROR_DETECT == STD_ON) */

#if (MPU_PRECOMPILE_SUPPORT == STD_ON)
        Mpu_ConfigPtr = Mpu_PreDefinedConfigPtr;
        MPU_PARAM_UNUSED(ConfigPtr);
#else
    Mpu_ConfigPtr = ConfigPtr;
#endif /* (MPU_PRECOMPILE_SUPPORT == STD_ON) */

        SmpuRegionConfigPtr = Mpu_ConfigPtr->MpuRegionConfigPtr;

        for (; MemoryRegionIndex < Mpu_ConfigPtr->RegionConfigNum; MemoryRegionIndex++)
        {
            Smpu_Drv_InitMemoryRegion(SmpuRegionConfigPtr);
            SmpuRegionConfigPtr++;
        }
        Smpu_Drv_Enable(Mpu_ConfigPtr->GlobalMpuControlState);

#if (MPU_DEV_ERROR_DETECT == STD_ON)
        Mpu_Status = MPU_INIT;
    }
    else
    {
        /* Clean the configuration pointer in case of an error. */
        Mpu_ConfigPtr = NULL_PTR;
    }
#endif /* (MPU_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief      This is an interrupt handler function,and will be called by BusFault_Handler.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
void Mpu_SmpuErrorCallBack(void)
{
    Smpu_Drv_SalveErrorType  SlaveErrorInfo;
    uint8   SlaveErrorPortNum = 0U;
    Smpu_Drv_SlavePortType   SlaveErrorPort = SMPU_DRV_SLV_PORT_0;
    uint32 SlavePortErrorStatus = 0U;

    /*Implement for Normal Smpu interrupt*/
    if (0U != Smpu_Drv_CheckStatus())
    {
        SlavePortErrorStatus = Smpu_Drv_GetSlavePortAccErrStatus();
        while ((SlavePortErrorStatus != 0U)&&(SlaveErrorPortNum < (uint8)SMPU_DRV_SLV_PORT_ALL))
        {
            if (0x1U == (SlavePortErrorStatus & 0x1U))
            {
                SlaveErrorPort = (Smpu_Drv_SlavePortType)SlaveErrorPortNum;
                
                /*Get slave error info*/
                SlaveErrorInfo.ErrorAddress = Smpu_Drv_GetSlavePortErrAddress(SlaveErrorPort);
                SlaveErrorInfo.BusMasterId = Smpu_Drv_GetErrAccessMasterNum(SlaveErrorPort);
                SlaveErrorInfo.MrcnIndication = Smpu_Drv_GetSingleMrcErrStatus(SlaveErrorPort);
                Smpu_Drv_GetAccessErrCause(SlaveErrorPort, &SlaveErrorInfo);

                /*Clear and call callback function*/  
                Smpu_Drv_ClearSlavePortErrStatus(SlaveErrorPort);
                if (Mpu_ErrorCallbackFunc != NULL_PTR)
                {
                    Mpu_ErrorCallbackFunc(SlaveErrorPortNum, &SlaveErrorInfo);
                }
            }
            SlaveErrorPortNum++;
            SlavePortErrorStatus = SlavePortErrorStatus >> 1UL;
        }
    }
}

#define MPU_STOP_SEC_CODE
#include "Mpu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Mpu */

/** @} end of group Mpu_Module */
