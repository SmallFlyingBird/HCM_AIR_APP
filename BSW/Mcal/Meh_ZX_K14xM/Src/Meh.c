/**************************************************************************************************/
/**
 * @file      : Meh.c
 * @brief     : Meh Extended MicroController Error Handle source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Meh_Module
 *  @{
 */

/** @addtogroup Meh
 *  @brief Extended MicroController Error Handle
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Meh.h"
#include "Seru_Drv.h"
#include "Eiru_Drv.h"
#include "Meh_Externals.h"

#if (MEH_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* (MEH_DEV_ERROR_DETECT == STD_ON) */

/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 *  @brief Published information
 */
#define MEH_C_VENDOR_ID                   0x00B3U
#define MEH_C_AR_RELEASE_MAJOR_VERSION    4U
#define MEH_C_AR_RELEASE_MINOR_VERSION    6U
#define MEH_C_AR_RELEASE_REVISION_VERSION 0U
#define MEH_C_SW_MAJOR_VERSION            1U
#define MEH_C_SW_MINOR_VERSION            1U
#define MEH_C_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Meh header file are of the same vendor
 */
#if (MEH_C_VENDOR_ID != MEH_VENDOR_ID)
    #error "Vendor ID of Meh.c and Meh.h are different"
#endif

/**
 *  @brief Check if current file and Meh header file are of the same Autosar version
 */
#if ((MEH_C_AR_RELEASE_MAJOR_VERSION != MEH_AR_RELEASE_MAJOR_VERSION) ||                           \
     (MEH_C_AR_RELEASE_MINOR_VERSION != MEH_AR_RELEASE_MINOR_VERSION) ||                           \
     (MEH_C_AR_RELEASE_REVISION_VERSION != MEH_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh.c and Meh.h are different"
#endif

/**
 *  @brief Check if current file and Meh header file are of the same SW version
 */
#if ((MEH_C_SW_MAJOR_VERSION != MEH_SW_MAJOR_VERSION) ||                                           \
     (MEH_C_SW_MINOR_VERSION != MEH_SW_MINOR_VERSION) ||                                           \
     (MEH_C_SW_PATCH_VERSION != MEH_SW_PATCH_VERSION))
    #error "Software Version of Meh.c and Meh.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same vendor
 */
#if (MEH_C_VENDOR_ID != SERU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Meh.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same Autosar version
 */
#if ((MEH_C_AR_RELEASE_MAJOR_VERSION != SERU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (MEH_C_AR_RELEASE_MINOR_VERSION != SERU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (MEH_C_AR_RELEASE_REVISION_VERSION != SERU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv.h are of the same SW version
 */
#if ((MEH_C_SW_MAJOR_VERSION != SERU_DRV_H_SW_MAJOR_VERSION) ||                                    \
     (MEH_C_SW_MINOR_VERSION != SERU_DRV_H_SW_MINOR_VERSION) ||                                    \
     (MEH_C_SW_PATCH_VERSION != SERU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Meh.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv.h are of the same vendor
 */
#if (MEH_C_VENDOR_ID != EIRU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Meh.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv.h are of the same Autosar version
 */
#if ((MEH_C_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (MEH_C_AR_RELEASE_MINOR_VERSION != EIRU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (MEH_C_AR_RELEASE_REVISION_VERSION != EIRU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv.h are of the same SW version
 */
#if ((MEH_C_SW_MAJOR_VERSION != EIRU_DRV_H_SW_MAJOR_VERSION) ||                                    \
     (MEH_C_SW_MINOR_VERSION != EIRU_DRV_H_SW_MINOR_VERSION) ||                                    \
     (MEH_C_SW_PATCH_VERSION != EIRU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Meh.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Externals.h are of the same vendor
 */
#if (MEH_C_VENDOR_ID != MEH_EXTERNALS_H_VENDOR_ID)
    #error "Vendor ID of Meh.c and Meh_Externals.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Externals.h are of the same Autosar version
 */
#if ((MEH_C_AR_RELEASE_MAJOR_VERSION != MEH_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (MEH_C_AR_RELEASE_MINOR_VERSION != MEH_EXTERNALS_H_AR_RELEASE_MINOR_VERSION) ||               \
     (MEH_C_AR_RELEASE_REVISION_VERSION != MEH_EXTERNALS_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh.c and Meh_Externals.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Externals.h are of the same SW version
 */
#if ((MEH_C_SW_MAJOR_VERSION != MEH_EXTERNALS_H_SW_MAJOR_VERSION) ||                               \
     (MEH_C_SW_MINOR_VERSION != MEH_EXTERNALS_H_SW_MINOR_VERSION) ||                               \
     (MEH_C_SW_PATCH_VERSION != MEH_EXTERNALS_H_SW_PATCH_VERSION))
    #error "Software Version of Meh.c and Meh_Externals.hare different"
#endif

#if (MEH_DEV_ERROR_DETECT == STD_ON)
    #ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
        /* Check if current file and Det.h are of the same Autosar version */
        #if ((MEH_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                   \
             (MEH_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Meh.c and Det.h are different"
        #endif
    #endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
#endif     /* MEH_DEV_ERROR_DETECT */

/**
 * @brief Param unused
 */
#define MEH_PARAM_UNUSED(param) ((void)((param)))
/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of the state of Meh
 */
#if (MEH_DEV_ERROR_DETECT == STD_ON)
typedef enum
{
    MEH_UNINIT = 0x00U, /*!< Meh module uninitialized. */
    MEH_INIT            /*!< Meh module initialized. */
} Meh_StateType;
#endif
/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define MEH_START_SEC_VAR_INIT_UNSPECIFIED
#include "Meh_MemMap.h"
#if (MEH_DEV_ERROR_DETECT == STD_ON)
/**
 *  @brief Variable that indicates the state of the Meh.
 */
static Meh_StateType Meh_Status = MEH_UNINIT;
#endif
#define MEH_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Meh_MemMap.h"

#define MEH_START_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"

/**
 * @brief Local copy of the pointer to the configuration data
 */
static const Meh_ConfigType *Meh_ConfigPtr = NULL_PTR;

static Meh_EiruErrCallBackFunType *Meh_EiruErrCallBackFunc = MEH_EIRU_ERRORNOTIFICATIONPTR;
#define MEH_STOP_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

#if (MEH_DEV_ERROR_DETECT == STD_ON)
static boolean Meh_CheckInit(const Meh_ConfigType *ConfigPtr);
#endif

#if ((MEH_VERSION_INFO_API == STD_ON) && (MEH_DEV_ERROR_DETECT == STD_ON))
static boolean Meh_CheckGetVersionInfo(const Std_VersionInfoType *VersionInfoPtr);
#endif
LOCAL_INLINE void Meh_HandleSramError(const Eiru_Drv_SramType             Sram,
                                const Eiru_Drv_SramEccErrStatusType ErrorStatus);
static void Meh_CallBackErrorNotification(const Meh_SramType             Sram,
                                          const Meh_SramEccErrStatusType ErrorStatus,
                                          Meh_SramEccErrCauseType       *ErrorCausePtr);
#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

#if (MEH_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks status to execute init service.
 *
 * @param[in]  ConfigPtr: Pointer to the Meh configuration.
 *
 * @return     boolean
 * @retval     TRUE: check result is ready to execute meh init service.
 * @retval     FALSE: check result is not ready to execute meh init service.
 * 
 */
static boolean Meh_CheckInit(const Meh_ConfigType *ConfigPtr)
{
    boolean CheckResult = TRUE;

    if (MEH_UNINIT != Meh_Status)
    {
        CheckResult = FALSE;
        (void)Det_ReportError((uint16)MEH_MODULE_ID, MEH_INSTANCE_ID, MEH_SID_INIT,
                              MEH_E_ALREADY_INITIALIZED);
    }
    else
    {
    #if (MEH_PRECOMPILE_SUPPORT == STD_OFF)
        if (NULL_PTR == ConfigPtr)
        {
            CheckResult = FALSE;
            (void)Det_ReportError((uint16)MEH_MODULE_ID, MEH_INSTANCE_ID, MEH_SID_INIT,
                                  MEH_E_NULL_POINTER);
        }
    #else
        if (NULL_PTR != ConfigPtr)
        {
            CheckResult = FALSE;
            (void)Det_ReportError((uint16)MEH_MODULE_ID, MEH_INSTANCE_ID, MEH_SID_INIT,
                                  MEH_E_PARAM_INVALID);
        }
    #endif /* (MEH_PRECOMPILE_SUPPORT == STD_OFF) */
    }

    return CheckResult;
}

#endif /* (MEH_DEV_ERROR_DETECT == STD_ON) */

#if ((MEH_VERSION_INFO_API == STD_ON) && (MEH_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief      Checks status to execute get version info service.
 *
 * @param[out]  VersionInfoPtr: Pointer to store the software version info.
 *
 * @return     boolean
 * @retval     TRUE: check result is ready to call the service.
 * @retval     FALSE: check result is not ready to call the service.
 * 
 */
static boolean Meh_CheckGetVersionInfo(const Std_VersionInfoType *VersionInfoPtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == VersionInfoPtr)
    {
        CheckStatus = FALSE;
        (void)Det_ReportError((uint16)MEH_MODULE_ID, MEH_INSTANCE_ID, MEH_SID_GET_VERSION_INFO,
                              MEH_E_NULL_POINTER);
    }

    return CheckStatus;
}
#endif /* (MEH_VERSION_INFO_API == STD_ON) && (MEH_DEV_ERROR_DETECT == STD_ON) */

/**
 * @brief      This is a external function and shall be implemented by user.
 *
 * @param[in]  Sram: which Sram the error occured. SramL or SramU
 * @param[in]  ErrorStatus: Error Status.
 * @param[in]  ErrorCausePtr: Pointer to Error Cause.
 * 
 * @return     None.
 * 
 */
static void Meh_CallBackErrorNotification(const Meh_SramType             Sram,
                                          const Meh_SramEccErrStatusType ErrorStatus,
                                          Meh_SramEccErrCauseType       *ErrorCausePtr)
{
    if (Meh_EiruErrCallBackFunc != NULL_PTR)
    {
        Meh_EiruErrCallBackFunc(Sram, ErrorStatus, ErrorCausePtr);
    }
}

/**
 * @brief      This is a function to handle sram error.
 *
 * @param[in]  Sram: which Sram the error occured. SramL or SramU
 * @param[in]  ErrorStatus: Error Status.
 * 
 * @return     None.
 * 
 */
LOCAL_INLINE void Meh_HandleSramError(const Eiru_Drv_SramType             Sram,
                                const Eiru_Drv_SramEccErrStatusType ErrorStatus)
{
    Eiru_Drv_SramEccErrCauseType     ErrorCause;
    boolean                          CheckStatus;
    CheckStatus = Eiru_Drv_GetSramEccErrStatus(Sram, ErrorStatus);
    if (TRUE == CheckStatus)
    {
        Eiru_Drv_GetSramEccErrCause(Sram, &ErrorCause);
        Eiru_Drv_ClearSramEccErrStatus(Sram, ErrorStatus);
        /* MISRA2012 Rule-11.3 violation: Convert Eiru_Drv_SramEccErrCauseType pointer object to 
        Meh_SramEccErrCauseType pointer object,no side effects forseen by violating this rule.*/
        Meh_CallBackErrorNotification((Meh_SramType)Sram, (Meh_SramEccErrStatusType)ErrorStatus,
                                        (Meh_SramEccErrCauseType *)&ErrorCause);
    }    
}
#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

#if (MEH_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersionInfoPtr: Pointer to where to store the version information of this module.
 *
 * @return    None
 * 
 */
void Meh_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
    #if (MEH_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Meh_CheckGetVersionInfo(VersionInfoPtr))
    {
    #endif /* (MEH_DEV_ERROR_DETECT == STD_ON) */

        (VersionInfoPtr)->vendorID = (uint16)MEH_VENDOR_ID;
        (VersionInfoPtr)->moduleID = (uint16)MEH_MODULE_ID;
        (VersionInfoPtr)->sw_major_version = (uint8)MEH_SW_MAJOR_VERSION;
        (VersionInfoPtr)->sw_minor_version = (uint8)MEH_SW_MINOR_VERSION;
        (VersionInfoPtr)->sw_patch_version = (uint8)MEH_SW_PATCH_VERSION;

    #if (MEH_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (MEH_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (MEH_VERSION_INFO_API == STD_ON) */

/**
 * @brief      The function initializes the Meh driver.
 *
 * @param[in]  ConfigPtr:Configuration for Meh
 * 
 * @return     None
 * 
 */
void Meh_Init(const Meh_ConfigType *ConfigPtr)
{
#if (MEH_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Meh_CheckInit(ConfigPtr))
    {
#endif /* (MEH_DEV_ERROR_DETECT == STD_ON) */

#if (MEH_PRECOMPILE_SUPPORT == STD_ON)
        Meh_ConfigPtr = Meh_PreDefinedConfigPtr;
        MEH_PARAM_UNUSED(ConfigPtr);
#else
    Meh_ConfigPtr = ConfigPtr;
#endif /* (MEH_PRECOMPILE_SUPPORT == STD_ON) */

        Seru_Drv_Init(Meh_ConfigPtr->SeruConfigPtr);
        Eiru_Drv_Init(Meh_ConfigPtr->EiruConfigPtr);

#if (MEH_DEV_ERROR_DETECT == STD_ON)
        /* Set the driver state to INITIALIZED to prevent spurious interrupt and getStatus */
        Meh_Status = MEH_INIT;
    }
    else
    {
        /* Clean the configuration pointer in case of an error. */
        Meh_ConfigPtr = NULL_PTR;
    }
#endif /* (MEH_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief      The function De-initializes the Meh driver.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
void Meh_DeInit(void)
{
#if (STD_ON == MEH_DEV_ERROR_DETECT)
    if (MEH_INIT != Meh_Status)
    {
        (void)Det_ReportError((uint16)MEH_MODULE_ID, MEH_INSTANCE_ID, MEH_SID_DEINIT,
                              MEH_E_UNINIT);
    }
    else
    {
#endif
        Seru_Drv_DeInit();
        Eiru_Drv_DeInit();
#if (STD_ON == MEH_DEV_ERROR_DETECT)
        Meh_Status = MEH_UNINIT;
    }
#endif    
}
/**
 * @brief      The function check Eiru Status and get mem error info.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
void Meh_MainFunction(void)
{
#if (STD_ON == MEH_DEV_ERROR_DETECT)
    if (MEH_INIT != Meh_Status)
    {
        (void)Det_ReportError((uint16)MEH_MODULE_ID, MEH_INSTANCE_ID, MEH_SID_MAIN_FUNCTION,
                              MEH_E_UNINIT);
    }
    else
    {
#endif
        /* Check and get Over Run SramL Memory Errors */
        Meh_HandleSramError(EIRU_DRV_SRAM_L,EIRU_DRV_SRAM_ECC_ERR_OVERRUN);
        /* Check and get Over Run SramU Memory Errors */
        Meh_HandleSramError(EIRU_DRV_SRAM_U,EIRU_DRV_SRAM_ECC_ERR_OVERRUN);
        /* Check and get Single Bit SramL Memory Errors */
        Meh_HandleSramError(EIRU_DRV_SRAM_L,EIRU_DRV_SRAM_ECC_ERR_SINGLEBIT);
        /* Check and get Single Bit SramU Memory Errors */
        Meh_HandleSramError(EIRU_DRV_SRAM_U,EIRU_DRV_SRAM_ECC_ERR_SINGLEBIT);
#if (STD_ON == MEH_DEV_ERROR_DETECT)
    }
#endif
}

/**
 * @brief      This function should be called by bus fault handler to handle multi bit error.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
void Meh_CheckEccMultiBitError(void)
{
    /* Check and get multi bit SramL Memory Errors */
    Meh_HandleSramError(EIRU_DRV_SRAM_L,EIRU_DRV_SRAM_ECC_ERR_MULTIBIT);
    /* Check and get multi bit SramU Memory Errors */
    Meh_HandleSramError(EIRU_DRV_SRAM_U,EIRU_DRV_SRAM_ECC_ERR_MULTIBIT);
}

#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Meh */

/** @} end of group Meh_Module */
