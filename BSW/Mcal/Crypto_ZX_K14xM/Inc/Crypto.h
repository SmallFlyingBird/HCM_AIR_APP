/**************************************************************************************************/
/**
 * @file      : Crypto.h
 * @brief     : Crypto AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CRYPTO_H
#define CRYPTO_H

/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Crypto
 *  @brief Crypto AUTOSAR level
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_Types.h"
#include "Crypto_KeyManagement.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYPTO_VENDOR_ID                   0x00B3U
#define CRYPTO_MODULE_ID                   114U
#define CRYPTO_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_SW_MAJOR_VERSION            1U
#define CRYPTO_SW_MINOR_VERSION            2U
#define CRYPTO_SW_PATCH_VERSION            1U

/* Check if current file and Crypto_Types.h are the same vendor */
#if (CRYPTO_VENDOR_ID != CRYPTO_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Crypto.h and Crypto_Types.h are different"
#endif
/* Check if current file and Crypto_Types.h are the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION != CRYPTO_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION != CRYPTO_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION != CRYPTO_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto.h and Crypto_Types.h are different"
#endif
/* Check if current file and Crypto_Types.h are the same software version */
#if ((CRYPTO_SW_MAJOR_VERSION != CRYPTO_TYPES_H_SW_MAJOR_VERSION) || \
     (CRYPTO_SW_MINOR_VERSION != CRYPTO_TYPES_H_SW_MINOR_VERSION) || \
     (CRYPTO_SW_PATCH_VERSION != CRYPTO_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto.h and Crypto_Types.h are different"
#endif

/* Check if current file and Crypto_KeyManagement.h are the same vendor */
#if (CRYPTO_VENDOR_ID != CRYPTO_KEYMANAGEMENT_H_VENDOR_ID)
    #error "Vendor ID of Crypto.h and Crypto_KeyManagement.h are different"
#endif
/* Check if current file and Crypto_KeyManagement.h are the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION != CRYPTO_KEYMANAGEMENT_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION != CRYPTO_KEYMANAGEMENT_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION != CRYPTO_KEYMANAGEMENT_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto.h and Crypto_KeyManagement.h are different"
#endif
/* Check if current file and Crypto_KeyManagement.h are the same software version */
#if ((CRYPTO_SW_MAJOR_VERSION != CRYPTO_KEYMANAGEMENT_H_SW_MAJOR_VERSION) || \
     (CRYPTO_SW_MINOR_VERSION != CRYPTO_KEYMANAGEMENT_H_SW_MINOR_VERSION) || \
     (CRYPTO_SW_PATCH_VERSION != CRYPTO_KEYMANAGEMENT_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto.h and Crypto_KeyManagement.h are different"
#endif

/**
 * @brief Crypto driver object definition.
 * 
 */
#define CRYPTO_CDO_INDEX_TRNG               ((uint8)0U)
#define CRYPTO_CDO_INDEX_AES                ((uint8)1U)
#define CRYPTO_CDO_INDEX_KEY                ((uint8)2U)

/**
 * @brief API request called before initialization of Crypto Driver.
 * 
 */
#define CRYPTO_E_UNINIT                     ((uint8)0x00U)

/**
 * @brief Initialization of Crypto Driver failed.
 * 
 */
#define CRYPTO_E_INIT_FAILED                ((uint8)0x01U)

/**
 * @brief API request called with invalid parameter (Null pointer without redirection).
 * 
 */
#define CRYPTO_E_PARAM_POINTER              ((uint8)0x02U)

/**
 * @brief API request called with invalid parameter (out of range).
 * 
 */
#define CRYPTO_E_PARAM_HANDLE               ((uint8)0x04U)

/**
 * @brief API request called with invalid parameter (invalid value).
 * 
 */
#define CRYPTO_E_PARAM_VALUE                ((uint8)0x05U)

/**
 * @brief Buffer is too small for operation.
 * 
 */
#define CRYPTO_E_SMALL_BUFFER               ((uint8)0x06U)

/**
 * @brief Access Nvm failed.
 * 
 */
#define CRYPTO_E_RE_NVM_ACCESS_FAILED       ((uint8)0x04U)

/**
 * @brief service IDs
 */            
#define CRYPTO_SID_INIT                   0x00U /*!< service ID of Crypto_Init() */
#define CRYPTO_SID_GETVERSIONINFO         0x01U /*!< service ID of Crypto_GetVersionInfo() */
#define CRYPTO_SID_PROCESSJOB             0x03U /*!< service ID of Crypto_ProcessJob() */
#define CRYPTO_SID_KEYELEMENTSET          0x04U /*!< service ID of Crypto_KeyElementSet() */
#define CRYPTO_SID_KEYSETVALID            0x05U /*!< service ID of Crypto_KeySetValid() */
#define CRYPTO_SID_KEYELEMENTGET          0x06U /*!< service ID of Crypto_KeyElementGet() */
#define CRYPTO_SID_KEYGENERATE            0x07U /*!< service ID of Crypto_KeyGenerate() */
#define CRYPTO_SID_KEYDERIVE              0x08U /*!< service ID of Crypto_KeyDerive() */
#define CRYPTO_SID_KEYEXCHANGECALCPUBVAL  0x09U /*!< service ID of Crypto_KeyExchangeCalcPubVal() */
#define CRYPTO_SID_KEYEXCHANGECALCSECRET  0x0aU /*!< service ID of Crypto_KeyExchangeCalcSecret() */
#define CRYPTO_SID_MAINFUNCTION           0x0cU /*!< service ID of Crypto_MainFunction() */
#define CRYPTO_SID_RANDOMSEED             0x0dU /*!< service ID of Crypto_RandomSeed() */
#define CRYPTO_SID_CANCELJOB              0x0eU /*!< service ID of Crypto_CancelJob() */
#define CRYPTO_SID_KEYELEMENTCOPY         0x0fU /*!< service ID of Crypto_KeyElementCopy() */
#define CRYPTO_SID_KEYCOPY                0x10U /*!< service ID of Crypto_KeyCopy() */
#define CRYPTO_SID_KEYELEMENTIDSGET       0x11U /*!< service ID of Crypto_KeyElementIdsGet() */
#define CRYPTO_SID_KEYELEMENTCOPYPARTIAL  0x13U /*!< service ID of Crypto_KeyElementCopyPartial() */
#define CRYPTO_SID_KEYGETSTATUS           0x14U /*!< service ID of Crypto_KeyGetStatus() */
#define CRYPTO_SID_KEYSETINVALID          0x15U /*!< service ID of Crypto_KeySetInvalid() */
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Configuration data structure of Crypto module.
 *
 */
typedef void Crypto_ConfigType;

/**
 * @brief   CRYPTO queue elment struct.
 *
 */
typedef struct
{
    uint32 NextJobIndex;
    Crypto_JobType* CryptoJob;
} Crypto_QueueElementType;
 
/**
 * @brief   CRYPTO object head job information.
 *
 */
typedef struct
{
    uint32 FreeJobHead;
    uint32 QueuedJobHead;
}Crypto_ObjectQueueType;
 
/**
 * @brief   CRYPTO object queue information.
 *
 */
typedef struct
{
    Crypto_QueueElementType* const QueuedJobs;
    const uint32 QueueSize;
} Crypto_QueueInfoType;

/* Structure defining the Key job information */
typedef struct
{
    uint32 RetryTimes;                      /* Retry times for nvm write request and operation */
    boolean NvmResultValidFlag;             /* Indicates if nvm has notified cryto about the result */
    boolean WriteNvmFailFlag;               /* Indicates if a write request or operation to nvm is failed */
    uint32 ProcessingKeyId;                 /* Current processing key id */
    Crypto_JobType *CurrentJobPtr;          /* Pointer to the current processing job */
    boolean ProcessingFlag;                 /* Job processing flag indicating if a job is being processed */
}Crypto_KeyJobInfoType;
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

CRYPTO_CONFIG_EXT
CRYPTO_CONFIG1_EXT
CRYPTO_CONFIG2_EXT
CRYPTO_CONFIG3_EXT

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
extern Crypto_InitStateType Crypto_InitState;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
extern Crypto_KeyJobInfoType Crypto_KeyJobInfo;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

CRYPTO_CALLBACK_FUNSET_EXT

/**
 * @brief     Initializes the Crypto Driver.
 *
 * @param[in] ConfigPtr: Pointer to a selected configuration structure.
 * 
 * @return    None
 * 
 */
void Crypto_Init(const Crypto_ConfigType *configPtr);

/**
 * @brief     Performs the crypto primitive, that is configured in the job parameter.
 *
 * @param[in] objectId: Holds the identifier of the Crypto Driver Object.
 * @param[in] job: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
Std_ReturnType Crypto_ProcessJob(uint32 objectId, Crypto_JobType* job);

/**
 * @brief     This interface removes the provided job from the queue and cancels the 
 *            processing of the job if possible.
 *
 * @param[in] objectId: Holds the identifier of the Crypto Driver Object.
 * @param[in] job: Pointer to the configuration of the job. Contains structures with job 
 *            and primitive relevant information.
 *
 * @return    Std_ReturnType
 * 
 */
Std_ReturnType Crypto_CancelJob(uint32 objectId, Crypto_JobType* job);

/**
 * @brief     If asynchronous job processing is configured and there are job queues, the function 
 *            is called cyclically to process queued jobs.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Crypto_MainFunction (void);

#if (STD_ON == CRYPTO_VERSION_INFO_API)
/**
 * @brief      Returns the version information of this module.
 *
 * @param[out] versionInfo: Pointer to where to store the version information of this module.
 *
 * @return     None
 * 
 */
void Crypto_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* (CRYPTO_VERSION_INFO_API == STD_ON) */

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Crypto */

/** @} end of group Crypto_Module */

#endif /* CRYPTO_H */
