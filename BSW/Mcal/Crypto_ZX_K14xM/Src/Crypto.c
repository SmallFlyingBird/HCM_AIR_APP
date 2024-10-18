/**************************************************************************************************/
/**
 * @file      : Crypto.c
 * @brief     : Crypto AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
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

#include "CryIf.h"
#include "Aes_Drv.h"
#include "Trng_Drv.h"
#include "NvM.h"
#include "Det.h"
#include "SchM_Crypto.h"
#include "Crypto.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYPTO_C_VENDOR_ID                   0x00B3U
#define CRYPTO_C_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_C_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_C_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_C_SW_MAJOR_VERSION            1U
#define CRYPTO_C_SW_MINOR_VERSION            2U
#define CRYPTO_C_SW_PATCH_VERSION            1U

/* Check if current file and Crypto.h are the same vendor */
#if (CRYPTO_C_VENDOR_ID != CRYPTO_VENDOR_ID)
    #error "Vendor ID of Crypto.c and Crypto.h are different"
#endif
/* Check if current file and Crypto.h are the same Autosar version */
#if ((CRYPTO_C_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_C_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_C_AR_RELEASE_REVISION_VERSION != CRYPTO_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto.c and Crypto.h are different"
#endif
/* Check if current file and Crypto.h are the same Software version */
#if ((CRYPTO_C_SW_MAJOR_VERSION != CRYPTO_SW_MAJOR_VERSION) || \
     (CRYPTO_C_SW_MINOR_VERSION != CRYPTO_SW_MINOR_VERSION) || \
     (CRYPTO_C_SW_PATCH_VERSION != CRYPTO_SW_PATCH_VERSION))
    #error "Software Version of Crypto.c and Crypto.h are different"
#endif

/* Check if current file and Aes_Drv.h are the same vendor */
#if (CRYPTO_C_VENDOR_ID != AES_DRV_H_VENDOR_ID)
    #error "Vendor ID of Crypto.c and Aes_Drv.h are different"
#endif
/* Check if current file and Aes_Drv.h are the same Autosar version */
#if ((CRYPTO_C_AR_RELEASE_MAJOR_VERSION != AES_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_C_AR_RELEASE_MINOR_VERSION != AES_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_C_AR_RELEASE_REVISION_VERSION != AES_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto.c and Aes_Drv.h are different"
#endif
/* Check if current file and Aes_Drv.h are the same Software version */
#if ((CRYPTO_C_SW_MAJOR_VERSION != AES_DRV_H_SW_MAJOR_VERSION) || \
     (CRYPTO_C_SW_MINOR_VERSION != AES_DRV_H_SW_MINOR_VERSION) || \
     (CRYPTO_C_SW_PATCH_VERSION != AES_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto.c and Aes_Drv.h are different"
#endif

/* Check if current file and Trng_Drv.h are the same vendor */
#if (CRYPTO_C_VENDOR_ID != TRNG_DRV_H_VENDOR_ID)
    #error "Vendor ID of Crypto.c and Trng_Drv.h are different"
#endif
/* Check if current file and Trng_Drv.h are the same Autosar version */
#if ((CRYPTO_C_AR_RELEASE_MAJOR_VERSION != TRNG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_C_AR_RELEASE_MINOR_VERSION != TRNG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_C_AR_RELEASE_REVISION_VERSION != TRNG_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto.c and Trng_Drv.h are different"
#endif
/* Check if current file and Trng_Drv.h are the same Software version */
#if ((CRYPTO_C_SW_MAJOR_VERSION != TRNG_DRV_H_SW_MAJOR_VERSION) || \
     (CRYPTO_C_SW_MINOR_VERSION != TRNG_DRV_H_SW_MINOR_VERSION) || \
     (CRYPTO_C_SW_PATCH_VERSION != TRNG_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto.c and Trng_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and CryIf.h are the same Autosar version */
    #if ((CRYPTO_C_AR_RELEASE_MAJOR_VERSION != CRYIF_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_C_AR_RELEASE_MINOR_VERSION != CRYIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto.c and CryIf.h are different"
    #endif
    /* Check if current file and NvM.h are the same Autosar version */
    #if ((CRYPTO_C_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_C_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto.c and NvM.h are different"
    #endif
    /* Check if current file and Det.h are the same Autosar version */
    #if ((CRYPTO_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto.c and Det.h are different"
    #endif
    /* Check if current file and SchM_Crypto.h are the same Autosar version */
    #if ((CRYPTO_C_AR_RELEASE_MAJOR_VERSION != SCHM_CRYPTO_H_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_C_AR_RELEASE_MINOR_VERSION != SCHM_CRYPTO_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto.c and SchM_Crypto.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define CRYPTO_JOB_QUEUE_NONE               ((uint32)0xFFFFFFFFU)
#define CRYPTO_INVALID_JOBID                ((uint32)0xFFFFFFFFU)
#define CRYPTO_INVALID_KEYID                ((uint32)0xFFFFFFFFU)
#define CRYPTO_INVALID_KEYELEMENTID         ((uint32)0xFFFFFFFFU)
#define CRYPTO_NUM_SUPPORTED_SERVICES       ((uint8)((uint8)CRYPTO_KEYSETVALID + 1U))

/* Defines for the UPDATE (U), FINISH (F) or UPDATE & FINISH (UF) Crypto operation modes */
#define CRYPTO_U  ((uint8)(CRYPTO_OPERATIONMODE_UPDATE))
#define CRYPTO_F  ((uint8)(CRYPTO_OPERATIONMODE_FINISH))
#define CRYPTO_UF ((uint8)(CRYPTO_U | CRYPTO_F))

/* Mask definition for input and output parameters obtain */
#define CRYPTO_INPUT_MASK            (1U)
#define CRYPTO_SECOND_INPUT_MASK     (2U)
#define CRYPTO_THIRD_INPUT_MASK      (4U)
#define CRYPTO_OUTPUT_MASK           (16U)
#define CRYPTO_SECOND_OUTPUT_MASK    (32U)
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/* Structure defining the parameters need to be checked */
typedef struct
{
    boolean SingleCallOnly;              /* Only single call mode is supported */
    uint8 InputMask;                     /* Input pointer and length mask */ 
    uint8 SecondInputMask;               /* Second input pointer and length mask */ 
    uint8 ThirdInputMask;                /* Third input pointer and length mask */ 
    uint8 OutputMask;                    /* Output pointer and length mask */ 
    uint8 SecondOutputMask;              /* Second output pointer and length mask */
    uint8 VerifyMask;                    /* Verify pointer mask */
}Crypto_ServiceParaType;

/* Structure defining the job information of Aes module */
typedef struct
{
    uint32 CurrentJobId;                    /* Identification of the job being processed by AES */
    Crypto_JobType *PendingJobPtr;          /* Pointer to the asynchronous pending job */
    Crypto_DriverObjectStateType AesState;  /* Aes module state indicating if a job has been started */
    boolean ProcessingFlag;                 /* Job processing flag indicating if a job is being processed */
}Crypto_AesJobInfoType;

/* Structure defining the job information of Trng module */
typedef struct
{
    uint32 CurrentJobId;                    /* Identification of the job being processed by TRNG */
    boolean ProcessingFlag;                 /* Job processing flag indicating if a job is being processed */
}Crypto_TrngJobInfoType;

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
Crypto_KeyJobInfoType Crypto_KeyJobInfo;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
Crypto_InitStateType Crypto_InitState;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
static Crypto_AesJobInfoType Crypto_AesJobInfo;
static Crypto_TrngJobInfoType Crypto_TrngJobInfo;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
/* List of the job parameters mask need to be checked for Crypto_ProcessJob() API */
static const Crypto_ServiceParaType Crypto_ParaCheckList[CRYPTO_NUM_SUPPORTED_SERVICES] =
{
    /* SingleCall,   Input,    SecondIn, ThirdIn,  Output,   SecondOut, Verify */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)FALSE, CRYPTO_U, 0x0U,     0x0U,     CRYPTO_F,  0x0U,     0x0U}, /* MACGENERATE */
    {(boolean)FALSE, CRYPTO_U, CRYPTO_F, 0x0U,     0x0U,      0x0U,     CRYPTO_F}, /* MACVERIFY */
    {(boolean)FALSE, CRYPTO_U, 0x0U,     0x0U,     CRYPTO_UF, 0x0U,     0x0U}, /* ENCRYPT */
    {(boolean)FALSE, CRYPTO_U, 0x0U,     0x0U,     CRYPTO_UF, 0x0U,     0x0U}, /* DECRYPT */
    {(boolean)FALSE, CRYPTO_U, 0x0U,     0x0U,     CRYPTO_UF, CRYPTO_F, 0x0U}, /* AEADENCRYPT */
    {(boolean)FALSE, CRYPTO_U, 0x0U,     CRYPTO_F, CRYPTO_UF, 0x0U,     CRYPTO_F}, /* AEADDECRYPT */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY*/
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)TRUE,  0x0U,     0x0U,     0x0U,     CRYPTO_F,  0x0U,     0x0U}, /* RANDOMGENERATE */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY*/
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY*/
    {(boolean)FALSE, 0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* EMPTY */
    {(boolean)TRUE,  0x0U,     0x0U,     0x0U,     0x0U,      0x0U,     0x0U}, /* KEYSETVALID */
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
#endif
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
static void Crypto_RestoreNonPersistentKeyElements(void);
static void Crypto_RestoreKeysFromNvm(void);
static boolean Crypto_EnqueueJob(uint32 ObjectIndex, Crypto_JobType* CryptoJob);
static void Crypto_DequeueHeadJob(uint32 ObjectIndex);
static Std_ReturnType Crypto_DequeueJob(uint32 ObjectIndex, uint32 JobId);
static void Crypto_SendTrngQueuedJob(void);
static void Crypto_SendAesQueuedJob(void);
static void Crypto_SendKeyQueuedJob(void);
static void Crypto_HandlePendingJob(void);
static void Crypto_HandleNvmResult(void);
static void Crypto_InitJobQueues(void);
static Std_ReturnType Crypto_ConvertAesResponse(Aes_Drv_StatusType ResultStatus);
static Std_ReturnType Crypto_ConvertTrngResponse(Trng_Drv_StatusType ResultStatus);
static Std_ReturnType Crypto_GetKeyInfo(Crypto_JobType const *CryptoJob, const uint8 **KeyPtr, 
                              const uint8 **IvPtr, uint32 *IvLen);
static void Crypto_GetElementIndex(uint32 KeyId, uint32 ElementId, uint32 *ElementIndex);
static Std_ReturnType Crypto_GetInputByRedirection(Crypto_JobType const *CryptoJob,const uint8 **InputPtr, 
                                                   uint32 *InputLen, uint32 InputMask);
static Std_ReturnType Crypto_GetInputByJobPrimitive(Crypto_JobType const *CryptoJob, 
                                        const uint8 **InputPtr, uint32 *InputLen, uint32 InputMask);
static Std_ReturnType Crypto_GetInputPara(Crypto_JobType const *CryptoJob, const uint8 **InputPtr, 
                                          uint32 *InputLen, uint32 InputMask);
static Std_ReturnType Crypto_GetOutputByRedirection(Crypto_JobType const *CryptoJob, uint8 **OutputPtr, 
                                                    uint32 **OutputLenPtr, uint32 OutputMask);
static Std_ReturnType Crypto_GetOutputByJobPrimitive(Crypto_JobType const *CryptoJob, uint8 **OutputPtr, 
                                                     uint32 **OutputLenPtr, uint32 OutputMask);
static Std_ReturnType Crypto_GetOutputPara(Crypto_JobType const *CryptoJob, uint8 **OutputPtr, 
                                           uint32 **OutputLenPtr, uint32 OutputMask);                                                                                                                                                                                           
static Std_ReturnType Crypto_CmacOperation(Crypto_JobType const *CryptoJob);
static Std_ReturnType Crypto_GmacOperation(Crypto_JobType const *CryptoJob, 
                              Aes_Drv_CryptFunctionType FunctionType);
static Std_ReturnType Crypto_GenerateVerifyMac(Crypto_JobType const *CryptoJob);
static Std_ReturnType Crypto_EncryptDecryptOperation(Crypto_JobType const *CryptoJob, 
                                                     Aes_Drv_AlgorithmModeType Mode,
                                                     Aes_Drv_CryptFunctionType FunctionType);
static Std_ReturnType Crypto_EncryptDecrypt(Crypto_JobType const *CryptoJob);
static Std_ReturnType Crypto_AeadEncryptOperation(Crypto_JobType const *CryptoJob, 
                                                  Crypto_AlgorithmModeType Mode);
static Std_ReturnType Crypto_AeadDecryptOperation(Crypto_JobType const *CryptoJob, 
                                                  Crypto_AlgorithmModeType Mode);
static Std_ReturnType Crypto_AeadEncryptDecrypt(Crypto_JobType const *CryptoJob);
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
static Std_ReturnType Crypto_CheckPrimitive(uint32 ObjectId, const Crypto_JobType *CryptoJob);
static Std_ReturnType Crypto_CheckProcessJob(Crypto_JobType const *CryptoJob);
#endif
static Std_ReturnType Crypto_ProcessTrngOperation(Crypto_JobType const *CryptoJob);
static Std_ReturnType Crypto_ProcessAesOperation(Crypto_JobType const *CryptoJob);
static Std_ReturnType Crypto_HandleWithAesIdle(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob);
static Std_ReturnType Crypto_HandleWithAesActive(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob);
static Std_ReturnType Crypto_HandleTrngJob(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob);
static Std_ReturnType Crypto_HandleKeyJob(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob);
static Std_ReturnType Crypto_HandleAesJob(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob);
static Std_ReturnType Crypto_CancelTrngJob(uint32 ObjectId, Crypto_JobType* Job);
static Std_ReturnType Crypto_CancelAesJob(uint32 ObjectId, Crypto_JobType* Job);
static Std_ReturnType Crypto_CancelKeyJob(uint32 ObjectId, Crypto_JobType* Job);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * @brief     Restore for all non-persistent key elements.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
static void Crypto_RestoreNonPersistentKeyElements(void)
{
    uint32 KeyLoop, ElementLoop, Len;
    
    for (KeyLoop = 0U; KeyLoop < CRYPTO_NUMBER_OF_KEYS; KeyLoop++)
    {
        for (ElementLoop = 0U; ElementLoop < Crypto_KeyList[KeyLoop].KeyElementNum; ElementLoop++)
        {
            if((FALSE == Crypto_KeyList[KeyLoop].KeyElementListPtr[ElementLoop]->ElementPersist) && 
               (NULL_PTR != Crypto_KeyList[KeyLoop].KeyElementListPtr[ElementLoop]->ElementInitValue))
            {
                for (Len = 0U; Len < *Crypto_KeyList[KeyLoop].KeyElementListPtr[ElementLoop]->ElementActSize; Len++)
                {
                    Crypto_KeyList[KeyLoop].KeyElementListPtr[ElementLoop]->KeyElementPtr[Len] = 
                    Crypto_KeyList[KeyLoop].KeyElementListPtr[ElementLoop]->ElementInitValue[Len];
                }
                CRYPTO_SETKEYSTATUS(KeyLoop, CRYPTO_KEYSTATUS_VALID);
            }
        }
    }
}

/**
 * @brief     Restore persistent key elements from NVM.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
static void Crypto_RestoreKeysFromNvm(void)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    uint8 KeyLoop, RetryLoop;
    
    for (KeyLoop = 0U; KeyLoop < CRYPTO_NUMBER_OF_KEYS; KeyLoop++)
    {
        if(0U != Crypto_KeyList[KeyLoop].RefNvBlockSize)
        {
            for (RetryLoop = 0U; RetryLoop<= Crypto_KeyList[KeyLoop].RetryTimes; RetryLoop++)
            {
                Ret = NvM_ReadBlock(Crypto_KeyList[KeyLoop].RefNvBlockId, Crypto_KeyList[KeyLoop].PersistKeyElementsPtr);
                if((Std_ReturnType)E_OK == Ret)
                {
                    break;
                }
            }
        }
    }
}

/**
 * @brief     Adds a job into the queue.
 * 
 * @param[in] ObjectIndex: Crypto driver object index.
 * @param[in] CryptoJob: Pointer to the job that needs to be queued.
 * 
 * @return    boolean
 *
 */
static boolean Crypto_EnqueueJob(uint32 ObjectIndex, Crypto_JobType* CryptoJob)
{
    uint32* SearchIndex;
    Crypto_QueueElementType *QueueElement;
    boolean JobFound = FALSE;
    uint32 InsertJobIndex;
    uint32 TempJobIndex;

    SchM_Enter_Crypto_QueueAccess();
    if (CRYPTO_JOB_QUEUE_NONE != Crypto_ObjectQueueList[ObjectIndex].FreeJobHead)
    {
        SearchIndex = &(Crypto_ObjectQueueList[ObjectIndex].QueuedJobHead);
        /* Head of free job will be set as index for the job to be queued */
        InsertJobIndex = Crypto_ObjectQueueList[ObjectIndex].FreeJobHead;
        QueueElement = &Crypto_QueueInfoList[ObjectIndex].QueuedJobs[InsertJobIndex];

        Crypto_ObjectQueueList[ObjectIndex].FreeJobHead = QueueElement->NextJobIndex;
        
        /* Insert job to queued jobs according to job priority */
        while ((FALSE == JobFound) && (CRYPTO_JOB_QUEUE_NONE != *SearchIndex))
        {
            if (CryptoJob->jobPriority > Crypto_QueueInfoList[ObjectIndex].QueuedJobs[*SearchIndex].CryptoJob->jobPriority)
            {
                /* Find the first job whose priority is lower than that of the new job */
                TempJobIndex = *SearchIndex;
                *SearchIndex = InsertJobIndex;
                QueueElement->NextJobIndex = TempJobIndex;
                JobFound = TRUE;
            }
            /* Move to the next queued job */
            SearchIndex = &(Crypto_QueueInfoList[ObjectIndex].QueuedJobs[*SearchIndex].NextJobIndex);
        }
        
        /* Put the new job to the end if its priority is the lowest among the queued jobs */
        if (FALSE == JobFound)
        {
            *SearchIndex = InsertJobIndex;
            QueueElement->NextJobIndex = CRYPTO_JOB_QUEUE_NONE;
        }
        
        QueueElement->CryptoJob = CryptoJob;

        JobFound = TRUE;
    }
    SchM_Exit_Crypto_QueueAccess();
    return JobFound;
}

/**
 * @brief     Remove the first job from the queue.
 * 
 * @param[in] ObjectIndex: Crypto driver object index.
 * 
 * @return    None
 *
 */
static void Crypto_DequeueHeadJob(uint32 ObjectIndex)
{
    uint32 QueuedJobHead;
    uint32 FreeJobHead;
    uint32 *NextJobIndexPtr;

    SchM_Enter_Crypto_QueueAccess();
    QueuedJobHead = Crypto_ObjectQueueList[ObjectIndex].QueuedJobHead;
    FreeJobHead = Crypto_ObjectQueueList[ObjectIndex].FreeJobHead;
    NextJobIndexPtr = &Crypto_QueueInfoList[ObjectIndex].QueuedJobs[QueuedJobHead].NextJobIndex;

    Crypto_ObjectQueueList[ObjectIndex].QueuedJobHead = *NextJobIndexPtr;
    Crypto_ObjectQueueList[ObjectIndex].FreeJobHead = QueuedJobHead;
    *NextJobIndexPtr = FreeJobHead;
    SchM_Exit_Crypto_QueueAccess();
}

/**
 * @brief     Remove the specified job from the queue.
 * 
 * @param[in] ObjectIndex: Crypto driver object index.
 * @param[in] CryptoJob: Pointer to the job that needs to be queued.
 * 
 * @return    Std_ReturnType
 *
 */
static Std_ReturnType Crypto_DequeueJob(uint32 ObjectIndex, uint32 JobId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    uint32* SearchIndex;
    uint32 TempJobIndex1;
    uint32 TempJobIndex2;

    SchM_Enter_Crypto_QueueAccess();
    if (CRYPTO_JOB_QUEUE_NONE != Crypto_ObjectQueueList[ObjectIndex].QueuedJobHead)
    {
        SearchIndex = &(Crypto_ObjectQueueList[ObjectIndex].QueuedJobHead);
        /* Look through the queued jobs list to find the job to be dequeued */
        while (CRYPTO_JOB_QUEUE_NONE != *SearchIndex)
        {
            if (JobId == Crypto_QueueInfoList[ObjectIndex].QueuedJobs[*SearchIndex].CryptoJob->jobId)
            {
                /* Find and delete the job in the queued jobs */
                TempJobIndex1 = *SearchIndex;
                *SearchIndex = Crypto_QueueInfoList[ObjectIndex].QueuedJobs[*SearchIndex].NextJobIndex;

                /* The deleted job will be set as the head of the free jobs */
                TempJobIndex2 = Crypto_ObjectQueueList[ObjectIndex].FreeJobHead;
                Crypto_ObjectQueueList[ObjectIndex].FreeJobHead = TempJobIndex1;
                Crypto_QueueInfoList[ObjectIndex].QueuedJobs[TempJobIndex1].NextJobIndex = TempJobIndex2;

                Ret = (Std_ReturnType)E_OK;
                break;
            }

            SearchIndex = &(Crypto_QueueInfoList[ObjectIndex].QueuedJobs[*SearchIndex].NextJobIndex);
        }
    }
    SchM_Exit_Crypto_QueueAccess();

    return Ret;
}

/**
 * @brief     Send the queued TRNG jobs for processing.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
static void Crypto_SendTrngQueuedJob(void)
{
    Std_ReturnType Ret;
    Crypto_JobType* CryptoJob;
    uint32 QueuedJobHead;
    
    if(CRYPTO_JOB_QUEUE_NONE != Crypto_ObjectQueueList[CRYPTO_CDO_INDEX_TRNG].QueuedJobHead)
    {
        QueuedJobHead = Crypto_ObjectQueueList[CRYPTO_CDO_INDEX_TRNG].QueuedJobHead;
        CryptoJob = Crypto_QueueInfoList[CRYPTO_CDO_INDEX_TRNG].QueuedJobs[QueuedJobHead].CryptoJob;
        
        /* Try to send the job to HW for processing */
        Crypto_TrngJobInfo.ProcessingFlag = TRUE; 
        Crypto_TrngJobInfo.CurrentJobId = CryptoJob->jobId;
        CryptoJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
        Ret = Crypto_ProcessTrngOperation(CryptoJob);
        CryptoJob->jobState = CRYPTO_JOBSTATE_IDLE;
        Crypto_TrngJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
        Crypto_TrngJobInfo.ProcessingFlag  = FALSE;
        
        Crypto_DequeueHeadJob(CRYPTO_CDO_INDEX_TRNG);
        
        CryIf_CallbackNotification(CryptoJob, Ret);
    } 
}

/**
 * @brief     Send the queued AES jobs for processing.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
static void Crypto_SendAesQueuedJob(void)
{
    Std_ReturnType Ret;
    Crypto_JobType* CryptoJob;
    uint32 QueuedJobHead;

    if(CRYPTO_JOB_QUEUE_NONE != Crypto_ObjectQueueList[CRYPTO_CDO_INDEX_AES].QueuedJobHead)
    {
        QueuedJobHead = Crypto_ObjectQueueList[CRYPTO_CDO_INDEX_AES].QueuedJobHead;
        CryptoJob = Crypto_QueueInfoList[CRYPTO_CDO_INDEX_AES].QueuedJobs[QueuedJobHead].CryptoJob;
        
        /* Try to send the job to HW for processing */
        Crypto_AesJobInfo.ProcessingFlag = TRUE;
        Crypto_AesJobInfo.AesState = CRYPTO_DRIVER_OBJECT_ACTIVE;
        Crypto_AesJobInfo.CurrentJobId = CryptoJob->jobId;  
        CryptoJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
        Ret = Crypto_ProcessAesOperation(CryptoJob);
        Crypto_AesJobInfo.ProcessingFlag = FALSE;
        
        Crypto_DequeueHeadJob(CRYPTO_CDO_INDEX_AES);

        if(((Std_ReturnType)E_OK != Ret) || 
           (CRYPTO_OPERATIONMODE_SINGLECALL == CryptoJob->jobPrimitiveInputOutput.mode))
        {
            Crypto_AesJobInfo.AesState = CRYPTO_DRIVER_OBJECT_IDLE;
            Crypto_AesJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
            CryptoJob->jobState = CRYPTO_JOBSTATE_IDLE;
        }
        
        CryIf_CallbackNotification(CryptoJob, Ret);
    }   
}

/**
 * @brief     Send the queued Key jobs for processing.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
static void Crypto_SendKeyQueuedJob(void)
{
    Crypto_JobType* CryptoJob;
    uint32 QueuedJobHead;
    
    if(CRYPTO_JOB_QUEUE_NONE != Crypto_ObjectQueueList[CRYPTO_CDO_INDEX_KEY].QueuedJobHead)
    {
        QueuedJobHead = Crypto_ObjectQueueList[CRYPTO_CDO_INDEX_KEY].QueuedJobHead;
        CryptoJob = Crypto_QueueInfoList[CRYPTO_CDO_INDEX_KEY].QueuedJobs[QueuedJobHead].CryptoJob;
        
        /* Try to send the job to HW for processing */
        CryptoJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
        (void)Crypto_KeySetValid(CryptoJob->cryptoKeyId);

        /* Record current job for persist key and set job state to idle for non persist key */
        if(0U != Crypto_KeyList[CryptoJob->cryptoKeyId].RefNvBlockSize)
        {
            Crypto_KeyJobInfo.CurrentJobPtr = CryptoJob;
        }
        else
        {
            CryptoJob->jobState = CRYPTO_JOBSTATE_IDLE;
        }
        
        Crypto_DequeueHeadJob(CRYPTO_CDO_INDEX_KEY);
    } 
}

/**
 * @brief     Handles Aes pending jobs (async "update" or "finish" jobs).
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
static void Crypto_HandlePendingJob(void)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if(Crypto_AesJobInfo.PendingJobPtr->jobId == Crypto_AesJobInfo.CurrentJobId)
    {
        Crypto_AesJobInfo.ProcessingFlag = TRUE;
        Crypto_AesJobInfo.PendingJobPtr->jobState = CRYPTO_JOBSTATE_ACTIVE;
        Ret = Crypto_ProcessAesOperation(Crypto_AesJobInfo.PendingJobPtr);
        Crypto_AesJobInfo.ProcessingFlag = FALSE;
        
        if(((Std_ReturnType)E_OK != Ret) || (CRYPTO_OPERATIONMODE_FINISH == 
            Crypto_AesJobInfo.PendingJobPtr->jobPrimitiveInputOutput.mode))
        {
            Crypto_AesJobInfo.AesState = CRYPTO_DRIVER_OBJECT_IDLE;
            Crypto_AesJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
            Crypto_AesJobInfo.PendingJobPtr->jobState = CRYPTO_JOBSTATE_IDLE;
        }
        Crypto_AesJobInfo.PendingJobPtr = NULL_PTR;

        CryIf_CallbackNotification(Crypto_AesJobInfo.PendingJobPtr, (Crypto_ResultType)Ret);
    }
}

/**
 * @brief     Handles for NVM write return result.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
static void Crypto_HandleNvmResult(void)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    uint32 KeyId = Crypto_KeyJobInfo.ProcessingKeyId;
    boolean BlockChanged = TRUE;

    /* Write request to nvm returns failure or write operation is failed */
    if(TRUE == Crypto_KeyJobInfo.WriteNvmFailFlag) 
    {
       (void)Det_ReportRuntimeError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, 
                                     CRYPTO_SID_MAINFUNCTION, CRYPTO_E_RE_NVM_ACCESS_FAILED);
       
        if(NULL_PTR != Crypto_KeyJobInfo.CurrentJobPtr)
        {
            CryIf_CallbackNotification(Crypto_KeyJobInfo.CurrentJobPtr, E_NOT_OK);
            if(0U == Crypto_KeyJobInfo.RetryTimes)
            {
                Crypto_KeyJobInfo.CurrentJobPtr->jobState = CRYPTO_JOBSTATE_IDLE;
            }
        }

        if(Crypto_KeyJobInfo.RetryTimes > 0U)
        {
            Crypto_KeyJobInfo.RetryTimes--;
            
            Ret = NvM_SetRamBlockStatus(Crypto_KeyList[KeyId].RefNvBlockId, BlockChanged);

            if(((Std_ReturnType)E_OK == Ret) && 
               (CRYPTO_NV_BLOCK_IMMEDIATE == Crypto_KeyList[KeyId].BlockProType))
            {
                Ret = NvM_WriteBlock(Crypto_KeyList[KeyId].RefNvBlockId, Crypto_KeyList[KeyId].PersistKeyElementsPtr);
            }  

            if((Std_ReturnType)E_OK == Ret)
            {
                /* Write request is successful and wait for the result from nvm */
                Crypto_KeyJobInfo.WriteNvmFailFlag = FALSE;
                Crypto_KeyJobInfo.NvmResultValidFlag = FALSE;
                
                /* Set crypto key status */
                CRYPTO_SETKEYSTATUS(KeyId, CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS);
            }
        }
        else
        {
            Crypto_KeyJobInfo.WriteNvmFailFlag = FALSE;
            Crypto_KeyJobInfo.NvmResultValidFlag = FALSE;
            Crypto_KeyJobInfo.CurrentJobPtr = NULL_PTR;
            Crypto_KeyJobInfo.ProcessingKeyId = CRYPTO_INVALID_KEYID;
            Crypto_KeyJobInfo.ProcessingFlag = FALSE;
        }
    }
    /* A key has been successfully written to nvm */
    else if(TRUE == Crypto_KeyJobInfo.NvmResultValidFlag)
    {
        if(NULL_PTR != Crypto_KeyJobInfo.CurrentJobPtr)
        {
            Crypto_KeyJobInfo.CurrentJobPtr->jobState = CRYPTO_JOBSTATE_IDLE;
            CryIf_CallbackNotification(Crypto_KeyJobInfo.CurrentJobPtr, E_OK);
        }
        
        Crypto_KeyJobInfo.WriteNvmFailFlag = FALSE;
        Crypto_KeyJobInfo.NvmResultValidFlag = FALSE;
        Crypto_KeyJobInfo.CurrentJobPtr = NULL_PTR;
        Crypto_KeyJobInfo.ProcessingKeyId = CRYPTO_INVALID_KEYID;
        Crypto_KeyJobInfo.ProcessingFlag = FALSE;
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief     Initializes job queues.
 *
 * @param[in] None
 * 
 * @return    None
 *
 */
static void Crypto_InitJobQueues(void)
{
    uint32 ObjectIndex;
    uint32 QueueElementIndex;

    SchM_Enter_Crypto_QueueAccess();
    for(ObjectIndex = 0U; ObjectIndex < (uint32)CRYPTO_NUMBER_OF_DRIVER_OBJECTS; ObjectIndex++)
    {
        /* Initialize the head of queued jobs stating that no job is queued */
        Crypto_ObjectQueueList[ObjectIndex].QueuedJobHead = CRYPTO_JOB_QUEUE_NONE;

        if(0U == Crypto_QueueInfoList[ObjectIndex].QueueSize)
        {
            /* If CDO queue size is zero, mark the queue of free jobs as being empty. */
            Crypto_ObjectQueueList[ObjectIndex].FreeJobHead = CRYPTO_JOB_QUEUE_NONE;
        }
        else
        {
            /* Initialize the CDO queue of free jobs by chaining all queue job elements */
            Crypto_ObjectQueueList[ObjectIndex].FreeJobHead = 0U;
            for (QueueElementIndex = 0U; 
                 QueueElementIndex < (Crypto_QueueInfoList[ObjectIndex].QueueSize - 1U); 
                 QueueElementIndex++)
            {
                Crypto_QueueInfoList[ObjectIndex].QueuedJobs[QueueElementIndex].NextJobIndex = 
                                                                            QueueElementIndex + 1U;
            }
            /* Mark the last in the queue as pointing to no other next queue element */
            Crypto_QueueInfoList[ObjectIndex].QueuedJobs[QueueElementIndex].NextJobIndex = 
                                                                        CRYPTO_JOB_QUEUE_NONE;
        }
    }
    SchM_Exit_Crypto_QueueAccess();
}

/**
 * @brief     This function converts the return code of AES to Std_ReturnType.
 *
 * @param[in] ResultStatus: AES Driver status.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_ConvertAesResponse(Aes_Drv_StatusType ResultStatus)
{
    Std_ReturnType Ret;

    switch (ResultStatus)
    {
        /* No error has occurred. */
        case AES_DRV_STATUS_NO_ERR:
            Ret = (Std_ReturnType)E_OK;
            break;
        /* Another operation is in progress. */
        case AES_DRV_STATUS_BUSY_ERROR:
            Ret = (Std_ReturnType)CRYPTO_E_BUSY;
            break;
        default:
        /* Should not get here */
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
    }
    return Ret;
}

/**
 * @brief     This function converts the return code of AES to Std_ReturnType.
 *
 * @param[in] ResultStatus: AES Driver status.
 *
 * @return    Std_ReturnType
 * 
 */
 static Std_ReturnType Crypto_ConvertTrngResponse(Trng_Drv_StatusType ResultStatus)
 {
    Std_ReturnType Ret;
 
    switch (ResultStatus)
    {
        /* No error has occurred. */
        case TRNG_DRV_STATUS_NO_ERR:
            Ret = (Std_ReturnType)E_OK;
            break;
        case TRNG_DRV_STATUS_INVALID_RANDOM_ERR:
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        default:
        /* Should not get here */
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
    }
    return Ret;
 }

/**
 * @brief     Get key information (Key material, IV and IV length).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] KeyPtr: Pointer to the key material buffer pointer.
 * @param[in] IvPtr: Pointer to the IV buffer pointer.
 * @param[in] IvLen: Pointer to the IV length.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GetKeyInfo(Crypto_JobType const *CryptoJob, const uint8 **KeyPtr, 
                              const uint8 **IvPtr, uint32 *IvLen)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    uint32 KeyId = CryptoJob->cryptoKeyId;
    uint32 Loop;
    boolean ValidFlag;

    ValidFlag = CRYPTO_GETKEYSTATUS(KeyId);

    if(FALSE != ValidFlag)
    {
        for (Loop = 0U; Loop < Crypto_KeyList[KeyId].KeyElementNum; Loop++)
        {
            if (1U == Crypto_KeyList[KeyId].KeyElementListPtr[Loop]->ElementId)
            {
                *KeyPtr = Crypto_KeyList[KeyId].KeyElementListPtr[Loop]->KeyElementPtr;
            }
            else if(5U == Crypto_KeyList[KeyId].KeyElementListPtr[Loop]->ElementId)
            {
                *IvPtr = Crypto_KeyList[KeyId].KeyElementListPtr[Loop]->KeyElementPtr;
                *IvLen = *Crypto_KeyList[KeyId].KeyElementListPtr[Loop]->ElementActSize;
            }
            else
            {
                /* do nothing */
            }
        }
    }
    else
    {
        Ret = CRYPTO_E_KEY_NOT_VALID;
    }

    return Ret;
}

/**
 * @brief      Get key element index.
 *
 * @param[in]  KeyId: Key identification.
 * @param[in]  ElementId: Key element identification.
 * @param[out] ElementIndex: Key element index.
 *
 * @return     None
 * 
 */                              
static void Crypto_GetElementIndex(uint32 KeyId, uint32 ElementId, uint32 *ElementIndex)
{
    uint32 Loop;

    *ElementIndex = CRYPTO_INVALID_KEYELEMENTID;

    for (Loop = 0U; Loop < Crypto_KeyList[KeyId].KeyElementNum; Loop++)
    {
        if (ElementId == Crypto_KeyList[KeyId].KeyElementListPtr[Loop]->ElementId)
        {
            *ElementIndex = Loop;
            break;
        }
    }
}

/**
 * @brief     Get redirection input information (input data pointer and length).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] InputPtr: Pointer to the input data buffer pointer.
 * @param[in] InputLen: Pointer to the input length.
 * @param[in] InputMask: Input mask indicating which input parameters should be get.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GetInputByRedirection(Crypto_JobType const *CryptoJob,const uint8 **InputPtr, 
                                                   uint32 *InputLen, uint32 InputMask)
{
    Std_ReturnType Ret;
    uint32 KeyId, ElementId, ElementIndex;
    boolean ValidFlag = FALSE;

    switch(CryptoJob->jobRedirectionInfoRef->redirectionConfig & InputMask)
    {
        case CRYPTO_INPUT_MASK:
            KeyId = CryptoJob->jobRedirectionInfoRef->inputKeyId;
            ElementId = CryptoJob->jobRedirectionInfoRef->inputKeyElementId;
            break;
        case CRYPTO_SECOND_INPUT_MASK:
            KeyId = CryptoJob->jobRedirectionInfoRef->secondaryInputKeyId;
            ElementId = CryptoJob->jobRedirectionInfoRef->secondaryInputKeyElementId;
            break;
        case CRYPTO_THIRD_INPUT_MASK:
            KeyId = CryptoJob->jobRedirectionInfoRef->tertiaryInputKeyId;
            ElementId = CryptoJob->jobRedirectionInfoRef->tertiaryInputKeyElementId;
            break;
        default:
            KeyId = CRYPTO_INVALID_KEYID;
            break;
    }

    if(KeyId < CRYPTO_NUMBER_OF_KEYS)
    {
        ValidFlag = CRYPTO_GETKEYSTATUS(KeyId);
        Crypto_GetElementIndex(KeyId, ElementId, &ElementIndex);
        if(CRYPTO_INVALID_KEYELEMENTID == ElementIndex)
        {
            ValidFlag = FALSE;
        }
    }

    if(FALSE != ValidFlag)
    {
        if(Crypto_KeyList[KeyId].KeyElementListPtr[ElementIndex]->ElementReadAccess > CRYPTO_RA_INTERNAL_COPY)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        }
        else if(((CRYPTO_ENCRYPT == CryptoJob->jobPrimitiveInfo->primitiveInfo->service) ||
                 (CRYPTO_DECRYPT == CryptoJob->jobPrimitiveInfo->primitiveInfo->service) ||
                 (CRYPTO_AEADENCRYPT == CryptoJob->jobPrimitiveInfo->primitiveInfo->service) ||
                 (CRYPTO_AEADDECRYPT == CryptoJob->jobPrimitiveInfo->primitiveInfo->service)) &&
                (Crypto_KeyList[KeyId].KeyElementListPtr[ElementIndex]->ElementReadAccess > CRYPTO_RA_ENCRYPTED))
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            *InputPtr = Crypto_KeyList[KeyId].KeyElementListPtr[ElementIndex]->KeyElementPtr;
            *InputLen = *Crypto_KeyList[KeyId].KeyElementListPtr[ElementIndex]->ElementActSize;
            Ret = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        Ret = CRYPTO_E_KEY_NOT_VALID;
    }    

    return Ret;
}

/**
 * @brief     Get Job Primitive input information (input data pointer and length).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] InputPtr: Pointer to the input data buffer pointer.
 * @param[in] InputLen: Pointer to the input length.
 * @param[in] InputMask: Input mask indicating which input parameters should be get.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GetInputByJobPrimitive(Crypto_JobType const *CryptoJob, 
                                         const uint8 **InputPtr, uint32 *InputLen, uint32 InputMask)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    switch(InputMask)
    {
        case CRYPTO_INPUT_MASK:
            *InputPtr = CryptoJob->jobPrimitiveInputOutput.inputPtr;
            *InputLen = CryptoJob->jobPrimitiveInputOutput.inputLength;
            break;
        case CRYPTO_SECOND_INPUT_MASK:
            *InputPtr = CryptoJob->jobPrimitiveInputOutput.secondaryInputPtr;
            *InputLen = CryptoJob->jobPrimitiveInputOutput.secondaryInputLength;
            break;
        case CRYPTO_THIRD_INPUT_MASK:
            *InputPtr = CryptoJob->jobPrimitiveInputOutput.tertiaryInputPtr;
            *InputLen = CryptoJob->jobPrimitiveInputOutput.tertiaryInputLength; 
            break;
        default:
            *InputPtr = NULL_PTR;
            *InputLen = 0U;
            Ret = (Std_ReturnType)E_NOT_OK;  
            break;
    }

    return Ret;
}

/**
 * @brief     Get input information (input data pointer and length).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] InputPtr: Pointer to the input data buffer pointer.
 * @param[in] InputLen: Pointer to the input length.
 * @param[in] InputMask: Input mask indicating which input parameters should be get.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GetInputPara(Crypto_JobType const *CryptoJob, const uint8 **InputPtr, 
                                          uint32 *InputLen, uint32 InputMask)
{
    Std_ReturnType Ret;

    if(NULL_PTR != CryptoJob->jobRedirectionInfoRef)
    {
        Ret = Crypto_GetInputByRedirection(CryptoJob, InputPtr, InputLen, InputMask);
    }
    else
    {
        Ret = Crypto_GetInputByJobPrimitive(CryptoJob, InputPtr, InputLen, InputMask);
    }

    return Ret;
}

/**
 * @brief     Get redirection output information (output data pointer and length).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] OutputPtr: Pointer to the output data buffer pointer.
 * @param[in] OutputLenPtr: Pointer to the output length pointer.
 * @param[in] OutputMask: Output mask indicating which output parameters should be get.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GetOutputByRedirection(Crypto_JobType const *CryptoJob, uint8 **OutputPtr, 
                                                    uint32 **OutputLenPtr, uint32 OutputMask)
{
    Std_ReturnType Ret;
    uint32 KeyId, ElementId, ElementIndex;
    boolean ValidFlag = FALSE;

    switch(CryptoJob->jobRedirectionInfoRef->redirectionConfig & OutputMask)
    {
        case CRYPTO_OUTPUT_MASK:
            KeyId = CryptoJob->jobRedirectionInfoRef->outputKeyId;
            ElementId = CryptoJob->jobRedirectionInfoRef->outputKeyElementId;
            break;
        case CRYPTO_SECOND_OUTPUT_MASK:
            KeyId = CryptoJob->jobRedirectionInfoRef->secondaryOutputKeyId;
            ElementId = CryptoJob->jobRedirectionInfoRef->secondaryOutputKeyElementId;
            break;         
        default:
            KeyId = CRYPTO_INVALID_KEYID;
            break;
    }

    if(KeyId < CRYPTO_NUMBER_OF_KEYS)
    {
        ValidFlag = CRYPTO_GETKEYSTATUS(KeyId);
        Crypto_GetElementIndex(KeyId, ElementId, &ElementIndex);
        if(CRYPTO_INVALID_KEYELEMENTID == ElementIndex)
        {
            ValidFlag = FALSE;
        }
    }

    if(FALSE != ValidFlag)
    {
        if(Crypto_KeyList[KeyId].KeyElementListPtr[ElementIndex]->ElementWriteAccess > CRYPTO_WA_INTERNAL_COPY)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            *OutputPtr = Crypto_KeyList[KeyId].KeyElementListPtr[ElementIndex]->KeyElementPtr;
            *OutputLenPtr = Crypto_KeyList[KeyId].KeyElementListPtr[ElementIndex]->ElementActSize;
            Ret = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        Ret = CRYPTO_E_KEY_NOT_VALID;
    }    
    
    return Ret;
}

/**
 * @brief     Get Job Primitive output information (output data pointer and length).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] OutputPtr: Pointer to the output data buffer pointer.
 * @param[in] OutputLenPtr: Pointer to the output length pointer.
 * @param[in] OutputMask: Output mask indicating which output parameters should be get.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GetOutputByJobPrimitive(Crypto_JobType const *CryptoJob, uint8 **OutputPtr, 
                                                     uint32 **OutputLenPtr, uint32 OutputMask)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    switch(OutputMask)
    {
        case CRYPTO_OUTPUT_MASK:
            *OutputPtr = CryptoJob->jobPrimitiveInputOutput.outputPtr;
            *OutputLenPtr = CryptoJob->jobPrimitiveInputOutput.outputLengthPtr;
            break;
        case CRYPTO_SECOND_OUTPUT_MASK:
            *OutputPtr = CryptoJob->jobPrimitiveInputOutput.secondaryOutputPtr;
            *OutputLenPtr = CryptoJob->jobPrimitiveInputOutput.secondaryOutputLengthPtr;
            break;       
        default:
            *OutputPtr = NULL_PTR;
            *OutputLenPtr = NULL_PTR;
            Ret = (Std_ReturnType)E_NOT_OK;  
            break;
    }

    return Ret;
}

/**
 * @brief     Check the output length.
 *
 * @param[in] InputLen: Input length.
 * @param[in] OutputLen: Output length.
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    CRYPTO_E_SMALL_BUFFER
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckOutputLen(uint32 InputLen, uint32 OutputLen)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(OutputLen < InputLen)
    {
        RetVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
    }

	return RetVal;
}

/**
 * @brief     Get output information (output pointer and length).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] OutputPtr: Pointer to the output data buffer pointer.
 * @param[in] OutputLenPtr: Pointer to the output length pointer.
 * @param[in] OutputMask: Output mask indicating which output parameters should be get.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GetOutputPara(Crypto_JobType const *CryptoJob, uint8 **OutputPtr, 
                                           uint32 **OutputLenPtr, uint32 OutputMask)
{
    Std_ReturnType Ret;

    if(NULL_PTR != CryptoJob->jobRedirectionInfoRef)
    {
        Ret = Crypto_GetOutputByRedirection(CryptoJob, OutputPtr, OutputLenPtr, OutputMask);
    }
    else
    {
        Ret = Crypto_GetOutputByJobPrimitive(CryptoJob, OutputPtr, OutputLenPtr, OutputMask);
    }

    return Ret;
}

/**
 * @brief     Performs the CMAC operation (CRYPTO_MACGENERATE and CRYPTO_MACVERIFY).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_CmacOperation(Crypto_JobType const *CryptoJob)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    Std_ReturnType Res;
    uint8 GenMacPtr[16U] = {0U};
    boolean CompareResult;
    Crypto_ServiceInfoType Service = CryptoJob->jobPrimitiveInfo->primitiveInfo->service;

    const uint8 *KeyPtr = NULL_PTR;
    const uint8 *IvPtr = NULL_PTR;
    uint32 IvLen;

    const uint8 *InputPtr = NULL_PTR;
    uint32 InputLen = 0U;
    const uint8 *SecondInputPtr = NULL_PTR;
    uint32 SecondInputLen = 0U;

    uint8 *OutputPtr = NULL_PTR;
    uint32 *OutputLen = NULL_PTR;

    Crypto_VerifyResultType *VerifyPtr= CryptoJob->jobPrimitiveInputOutput.verifyPtr;

    (void)Crypto_GetInputPara(CryptoJob, &InputPtr, &InputLen, CRYPTO_INPUT_MASK);
    (void)Crypto_GetInputPara(CryptoJob, &SecondInputPtr, &SecondInputLen, CRYPTO_SECOND_INPUT_MASK);
    (void)Crypto_GetOutputPara(CryptoJob, &OutputPtr, &OutputLen, CRYPTO_OUTPUT_MASK);
    Res = Crypto_GetKeyInfo(CryptoJob, &KeyPtr, &IvPtr, &IvLen);

    if((Std_ReturnType)E_OK == Res)
    {
        switch(CryptoJob->jobPrimitiveInputOutput.mode)
        {
            case CRYPTO_OPERATIONMODE_START:
                Aes_Drv_StartCmac(KeyPtr);
                break;
            case CRYPTO_OPERATIONMODE_UPDATE:
                Ret = Aes_Drv_UpdateCmac(InputPtr, InputLen);
                break;
            case CRYPTO_OPERATIONMODE_STREAMSTART:
                Aes_Drv_StartCmac(KeyPtr);
                Ret = Aes_Drv_UpdateCmac(InputPtr, InputLen);
                break;
            case CRYPTO_OPERATIONMODE_FINISH:
                if(CRYPTO_MACGENERATE == Service)
                {
                    *OutputLen = ((*OutputLen < 16U) ? *OutputLen : 16U);
                    Ret = Aes_Drv_FinishCmac(InputPtr, InputLen, OutputPtr, *OutputLen);
                    *OutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? *OutputLen : 0U);
                }
                else
                {
                    Ret = Aes_Drv_FinishCmac(InputPtr, InputLen, GenMacPtr, 16U);
                    if(AES_DRV_STATUS_NO_ERR == Ret)
                    {
                        CompareResult = Aes_Drv_CompareData(SecondInputPtr, GenMacPtr, SecondInputLen);
                        *VerifyPtr = (Crypto_VerifyResultType)CompareResult;
                    }
                }
                break;
            case CRYPTO_OPERATIONMODE_SINGLECALL:
                if(CRYPTO_MACGENERATE == Service)
                {
                    *OutputLen = ((*OutputLen < 16U) ? *OutputLen : 16U);
                    Ret = Aes_Drv_GenerateCmac(KeyPtr, InputPtr, InputLen, OutputPtr, *OutputLen);
                    *OutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? *OutputLen : 0U);
                }
                else
                {
                    Ret = Aes_Drv_VerifyCmac(KeyPtr, InputPtr, InputLen, SecondInputPtr, 
                                             SecondInputLen, &CompareResult);
                    *VerifyPtr = (Crypto_VerifyResultType)CompareResult; 
                }
                break;
            default:
                Ret = AES_DRV_STATUS_MODE_ERR;
                break;
        }
        Res = Crypto_ConvertAesResponse(Ret);
    }

    return Res;
}

/**
 * @brief     Performs the GMAC operation (CRYPTO_MACGENERATE and CRYPTO_MACVERIFY).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] FunctionType: AES encryption or decryption.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GmacOperation(Crypto_JobType const *CryptoJob, 
                                           Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    Std_ReturnType Res;
    uint8 GenMacPtr[16U] = {0U};
    boolean CompareResult;
    Crypto_ServiceInfoType Service = CryptoJob->jobPrimitiveInfo->primitiveInfo->service;

    const uint8 *KeyPtr = NULL_PTR;
    const uint8 *IvPtr = NULL_PTR;
    uint32 IvLen;

    const uint8 *InputPtr = NULL_PTR;
    uint32 InputLen = 0U;
    const uint8 *SecondInputPtr = NULL_PTR;
    uint32 SecondInputLen = 0U;

    uint8 *OutputPtr = NULL_PTR;
    uint32 *OutputLen = NULL_PTR;
    Crypto_VerifyResultType *VerifyPtr= CryptoJob->jobPrimitiveInputOutput.verifyPtr;

    (void)Crypto_GetInputPara(CryptoJob, &InputPtr, &InputLen, CRYPTO_INPUT_MASK);
    (void)Crypto_GetInputPara(CryptoJob, &SecondInputPtr, &SecondInputLen, CRYPTO_SECOND_INPUT_MASK);
    (void)Crypto_GetOutputPara(CryptoJob, &OutputPtr, &OutputLen, CRYPTO_OUTPUT_MASK);
    Res = Crypto_GetKeyInfo(CryptoJob, &KeyPtr, &IvPtr, &IvLen);

    if((Std_ReturnType)E_OK == Res)
    {
        switch(CryptoJob->jobPrimitiveInputOutput.mode)
        {
            case CRYPTO_OPERATIONMODE_START:
                Ret = Aes_Drv_StartGcm(KeyPtr, IvPtr, 8U * IvLen, FunctionType);
                break;
            case CRYPTO_OPERATIONMODE_UPDATE:
                Ret = Aes_Drv_UpdateGcmAad(InputPtr, InputLen, FunctionType);
                break;
            case CRYPTO_OPERATIONMODE_STREAMSTART:
                Ret = Aes_Drv_StartGcm(KeyPtr, IvPtr, 8U * IvLen, FunctionType);
                if(AES_DRV_STATUS_NO_ERR == Ret)
                {
                    Ret = Aes_Drv_UpdateGcmAad(InputPtr, InputLen, FunctionType);
                }
                break;
            case CRYPTO_OPERATIONMODE_FINISH:
                if(CRYPTO_MACGENERATE == Service)
                {
                    *OutputLen = ((*OutputLen < 16U) ? *OutputLen : 16U);
                    Ret = Aes_Drv_FinishGcm(NULL_PTR, 0U, InputPtr, InputLen, NULL_PTR, OutputPtr,
                                            *OutputLen, FunctionType);
                    *OutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? *OutputLen : 0U);
                }
                else
                {
                    Ret = Aes_Drv_FinishGcm(NULL_PTR, 0U, InputPtr, InputLen, NULL_PTR, GenMacPtr,
                                            16U, FunctionType);
                    if(AES_DRV_STATUS_NO_ERR == Ret)
                    {
                        CompareResult = Aes_Drv_CompareData(SecondInputPtr, GenMacPtr, SecondInputLen);
                        *VerifyPtr = (Crypto_VerifyResultType)CompareResult;
                    }
                }
                break;
            case CRYPTO_OPERATIONMODE_SINGLECALL:
                if(CRYPTO_MACGENERATE == Service)
                {
                    *OutputLen = ((*OutputLen < 16U) ? *OutputLen : 16U);
                    Ret = Aes_Drv_Gcm(KeyPtr, IvPtr, 8U * IvLen, NULL_PTR, 0U, InputPtr, 
                                      InputLen, NULL_PTR, OutputPtr, *OutputLen, FunctionType);
                    *OutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? *OutputLen : 0U);
                }
                else
                {
                    Ret = Aes_Drv_Gcm(KeyPtr, IvPtr, 8U * IvLen, NULL_PTR, 0U, InputPtr, 
                                      InputLen, NULL_PTR, GenMacPtr, 16U, FunctionType);
                    if(AES_DRV_STATUS_NO_ERR == Ret)
                    {
                        CompareResult = Aes_Drv_CompareData(SecondInputPtr, GenMacPtr, SecondInputLen);
                        *VerifyPtr = (Crypto_VerifyResultType)CompareResult;
                    }
                }
                break;
            default:
                Ret = AES_DRV_STATUS_MODE_ERR;
                break;
        }
        Res = Crypto_ConvertAesResponse(Ret);
    }

    return Res;
}

/**
 * @brief     Processes the MAC service (CRYPTO_MACGENERATE and CRYPTO_MACVERIFY).
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_GenerateVerifyMac(Crypto_JobType const *CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    Crypto_ServiceInfoType Service = CryptoJob->jobPrimitiveInfo->primitiveInfo->service;
    Aes_Drv_CryptFunctionType FunctionType;

    FunctionType = ((CRYPTO_ENCRYPT == Service) ? AES_DRV_ENCRYPTION : AES_DRV_DECRYPTION);

    switch(CryptoJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
    {
        case CRYPTO_ALGOMODE_CMAC:
            Ret = Crypto_CmacOperation(CryptoJob);
            break;
        case CRYPTO_ALGOMODE_GMAC:
            Ret = Crypto_GmacOperation(CryptoJob, FunctionType);
            break;
        default:
            /* do nothing */
            break;
    }

    return Ret;
}

/**
 * @brief     Performs the encryption or decryption operation.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] Mode: Algorithm mode.
 * @param[in] FunctionType: AES encryption or decryption.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_EncryptDecryptOperation(Crypto_JobType const *CryptoJob, 
                                                     Aes_Drv_AlgorithmModeType Mode,
                                                     Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    Std_ReturnType Res;

    const uint8 *KeyPtr = NULL_PTR;
    const uint8 *IvPtr = NULL_PTR;
    uint32 IvLen;

    const uint8 *InputPtr = NULL_PTR;
    uint32 InputLen = 0U;
    uint8 *OutputPtr = NULL_PTR;
    uint32 *OutputLen = NULL_PTR;

    (void)Crypto_GetInputPara(CryptoJob, &InputPtr, &InputLen, CRYPTO_INPUT_MASK);
    (void)Crypto_GetOutputPara(CryptoJob, &OutputPtr, &OutputLen, CRYPTO_OUTPUT_MASK);
   
    Res = Crypto_CheckOutputLen(InputLen, *OutputLen);
    if ((Std_ReturnType)E_OK == Res)
    {
        Res = Crypto_GetKeyInfo(CryptoJob, &KeyPtr, &IvPtr, &IvLen);

        if((Std_ReturnType)E_OK == Res)
        {
            switch(CryptoJob->jobPrimitiveInputOutput.mode)
            {
                case CRYPTO_OPERATIONMODE_START:
                    Ret = Aes_Drv_StartCrypt(KeyPtr, IvPtr, Mode, FunctionType);
                    break;
                case CRYPTO_OPERATIONMODE_UPDATE:
                    Ret = Aes_Drv_UpdateCrypt(InputPtr, InputLen, OutputPtr, Mode, FunctionType);
                    break;
                case CRYPTO_OPERATIONMODE_STREAMSTART:
                    Ret = Aes_Drv_StartCrypt(KeyPtr, IvPtr, Mode, FunctionType);
                    if(AES_DRV_STATUS_NO_ERR == Ret)
                    {
                        Ret = Aes_Drv_UpdateCrypt(InputPtr, InputLen, OutputPtr, Mode, FunctionType);
                    }
                    break;
                case CRYPTO_OPERATIONMODE_FINISH:
                    if(InputLen > 0U)
                    {
                        Ret = Aes_Drv_UpdateCrypt(InputPtr, InputLen, OutputPtr, Mode, FunctionType);
                    }
                    break;
                case CRYPTO_OPERATIONMODE_SINGLECALL:
                    Ret = Aes_Drv_Crypt(KeyPtr, IvPtr, InputPtr, InputLen, OutputPtr, Mode, FunctionType);
                    break;
                default:
                    Ret = AES_DRV_STATUS_MODE_ERR;
                    break;
            }
            
            if(CRYPTO_OPERATIONMODE_START != CryptoJob->jobPrimitiveInputOutput.mode)
            {
                *OutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? InputLen : 0U);
            }
            
            Res = Crypto_ConvertAesResponse(Ret);
        }
    }
    else
    {
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_SMALL_BUFFER);
#else
        Res = (Std_ReturnType)E_NOT_OK;
#endif
    }    
    return Res;
}

/**
 * @brief     Processes the encryption or decryption service.
 *            Note: ECB/CBC/OFB/CTR/CFB/XTS mode is supported.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_EncryptDecrypt(Crypto_JobType const *CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    Crypto_ServiceInfoType Service = CryptoJob->jobPrimitiveInfo->primitiveInfo->service;
    Aes_Drv_CryptFunctionType FunctionType;
    Aes_Drv_AlgorithmModeType AlgorithmMode;

    FunctionType = ((CRYPTO_ENCRYPT == Service) ? AES_DRV_ENCRYPTION : AES_DRV_DECRYPTION);

    switch(CryptoJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
    {
        case CRYPTO_ALGOMODE_ECB:
            AlgorithmMode = AES_DRV_ECB;
            break;
        case CRYPTO_ALGOMODE_CBC:
            AlgorithmMode = AES_DRV_CBC;
            break;
        case CRYPTO_ALGOMODE_OFB:
            AlgorithmMode = AES_DRV_OFB;
            break;
        case CRYPTO_ALGOMODE_CTR:
            AlgorithmMode = AES_DRV_CTR;
            break;
        case CRYPTO_ALGOMODE_CFB:
            AlgorithmMode = AES_DRV_CFB;
            break;
        case CRYPTO_ALGOMODE_XTS:
            AlgorithmMode = AES_DRV_XTS;
            break;
        default:
            AlgorithmMode = AES_DRV_NONE;
            break;
    }

    if(AES_DRV_NONE != AlgorithmMode) 
    {
        Ret = Crypto_EncryptDecryptOperation(CryptoJob, AlgorithmMode, FunctionType);
    }

    return Ret;
}


/**
 * @brief     Performs the Authenticated Encryption with Associated Data operation.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] Mode: Algorithm mode.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_AeadEncryptOperation(Crypto_JobType const *CryptoJob, 
                                                  Crypto_AlgorithmModeType Mode)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    Std_ReturnType Res;
    Crypto_OperationModeType OperationMode = CryptoJob->jobPrimitiveInputOutput.mode;

    const uint8 *KeyPtr = NULL_PTR;
    const uint8 *IvPtr = NULL_PTR;
    uint32 IvLen;

    const uint8 *InputPtr = NULL_PTR;
    uint32 InputLen = 0U;
    const uint8 *SecondInputPtr = NULL_PTR;
    uint32 SecondInputLen = 0U;

    uint8 *OutputPtr = NULL_PTR;
    uint32 *OutputLen = NULL_PTR;
    uint8 *SecondOutputPtr = NULL_PTR;
    uint32 *SecondOutputLen = NULL_PTR;

    (void)Crypto_GetInputPara(CryptoJob, &InputPtr, &InputLen, CRYPTO_INPUT_MASK);
    (void)Crypto_GetInputPara(CryptoJob, &SecondInputPtr, &SecondInputLen, CRYPTO_SECOND_INPUT_MASK);
    (void)Crypto_GetOutputPara(CryptoJob, &OutputPtr, &OutputLen, CRYPTO_OUTPUT_MASK);
    (void)Crypto_GetOutputPara(CryptoJob, &SecondOutputPtr, &SecondOutputLen, CRYPTO_SECOND_OUTPUT_MASK);
    Res = Crypto_CheckOutputLen(InputLen, *OutputLen);
    if ((Std_ReturnType)E_OK == Res)
    {
        Res = Crypto_GetKeyInfo(CryptoJob, &KeyPtr, &IvPtr, &IvLen);

        if((Std_ReturnType)E_OK == Res)
        {
#if (STD_ON == CRYPTO_ALGOMODE_CUSTOM_SWITCH)       
            if ((CRYPTO_OPERATIONMODE_SINGLECALL != OperationMode) && ((Crypto_AlgorithmModeType)CRYPTO_ALGOMODE_CCM == Mode))
            {
                Ret = AES_DRV_STATUS_INPUT_ERROR;
            }
            else
#endif            
            {
                switch(OperationMode)
                {
                    case CRYPTO_OPERATIONMODE_START:
                        Ret = Aes_Drv_StartGcm(KeyPtr, IvPtr, 8U * IvLen, AES_DRV_ENCRYPTION);
                        break;
                    case CRYPTO_OPERATIONMODE_UPDATE:
                        if (SecondInputLen > 0U)
                        {
                            Ret = Aes_Drv_UpdateGcmAad(SecondInputPtr, SecondInputLen, AES_DRV_ENCRYPTION);
                        }
                        if (AES_DRV_STATUS_NO_ERR == Ret)
                        {
                            Ret = Aes_Drv_UpdateGcmData(InputPtr, InputLen, OutputPtr, AES_DRV_ENCRYPTION);
                        }
                        break;
                    case CRYPTO_OPERATIONMODE_STREAMSTART:
                        Ret = Aes_Drv_StartGcm(KeyPtr, IvPtr, 8U * IvLen, AES_DRV_ENCRYPTION);
                        if((AES_DRV_STATUS_NO_ERR == Ret) && (SecondInputLen > 0U))
                        {
                            Ret = Aes_Drv_UpdateGcmAad(SecondInputPtr, SecondInputLen, AES_DRV_ENCRYPTION);
                        }
                        if (AES_DRV_STATUS_NO_ERR == Ret)
                        {
                            Ret = Aes_Drv_UpdateGcmData(InputPtr, InputLen, OutputPtr, AES_DRV_ENCRYPTION);
                        }
                        break;
                    case CRYPTO_OPERATIONMODE_FINISH:
                        *SecondOutputLen = ((*SecondOutputLen < 16U) ? *SecondOutputLen : 16U);
                        Ret = Aes_Drv_FinishGcm(InputPtr, InputLen, SecondInputPtr, SecondInputLen, 
                                                OutputPtr, SecondOutputPtr, *SecondOutputLen, AES_DRV_ENCRYPTION);
                        *SecondOutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? *SecondOutputLen : 0U);
                        break;
                    case CRYPTO_OPERATIONMODE_SINGLECALL:
                        if(CRYPTO_ALGOMODE_GCM == Mode)
                        {
                            *SecondOutputLen = ((*SecondOutputLen < 16U) ? *SecondOutputLen : 16U);
                            /* Length of Tag is set to 16 bytes by default for GCM Encryption */
                            Ret = Aes_Drv_Gcm(KeyPtr, IvPtr, 8U * IvLen, InputPtr, InputLen, SecondInputPtr, 
                                              SecondInputLen, OutputPtr, SecondOutputPtr, *SecondOutputLen,
                                              AES_DRV_ENCRYPTION);
                            *SecondOutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? *SecondOutputLen : 0U);
                        }
#if (STD_ON == CRYPTO_ALGOMODE_CUSTOM_SWITCH)
                        else
                        {
                            *SecondOutputLen = ((*SecondOutputLen < 16U) ? *SecondOutputLen : 16U);
                            /* Actual Tag length is the same with the Expected Tag length if the CCM Encryption 
                               operation is successful */
                            Ret = Aes_Drv_Ccm(KeyPtr, IvPtr, IvLen, InputPtr, InputLen, SecondInputPtr, 
                                              SecondInputLen, OutputPtr, SecondOutputPtr, *SecondOutputLen,
                                              AES_DRV_ENCRYPTION);
                            *SecondOutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? *SecondOutputLen : 0U);
                        }
#endif                        
                        break;
                    default:
                        Ret = AES_DRV_STATUS_MODE_ERR;
                        break;
                }
            }
            
            if(CRYPTO_OPERATIONMODE_START != CryptoJob->jobPrimitiveInputOutput.mode)
            {
                *OutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? InputLen : 0U);
            }
            
            Res = Crypto_ConvertAesResponse(Ret);
        }
    }
    else
    {
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_SMALL_BUFFER);
#else
        Res = (Std_ReturnType)E_NOT_OK;
#endif
    }
    return Res;
}

/**
 * @brief     Performs the Authenticated Decryption with Associated Data operation.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] Mode: Algorithm mode.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_AeadDecryptOperation(Crypto_JobType const *CryptoJob, 
                                                  Crypto_AlgorithmModeType Mode)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    Std_ReturnType Res;
    boolean CompareResult;
    uint8 GenTagPtr[16U] = {0U};
    Crypto_OperationModeType OperationMode = CryptoJob->jobPrimitiveInputOutput.mode;

    const uint8 *KeyPtr = NULL_PTR;
    const uint8 *IvPtr = NULL_PTR;
    uint32 IvLen;

    const uint8 *InputPtr = NULL_PTR;
    uint32 InputLen = 0U;
    const uint8 *SecondInputPtr = NULL_PTR;
    uint32 SecondInputLen = 0U;
    const uint8 *ThirdInputPtr = NULL_PTR;
    uint32 ThirdInputLen = 0U;

    uint8 *OutputPtr = NULL_PTR;
    uint32 *OutputLen = NULL_PTR;
    Crypto_VerifyResultType *VerifyPtr= CryptoJob->jobPrimitiveInputOutput.verifyPtr;

    (void)Crypto_GetInputPara(CryptoJob, &InputPtr, &InputLen, CRYPTO_INPUT_MASK);
    (void)Crypto_GetInputPara(CryptoJob, &SecondInputPtr, &SecondInputLen, CRYPTO_SECOND_INPUT_MASK);
    (void)Crypto_GetInputPara(CryptoJob, &ThirdInputPtr, &ThirdInputLen, CRYPTO_THIRD_INPUT_MASK);
    (void)Crypto_GetOutputPara(CryptoJob, &OutputPtr, &OutputLen, CRYPTO_OUTPUT_MASK);
    Res = Crypto_CheckOutputLen(InputLen, *OutputLen);
    if ((Std_ReturnType)E_OK == Res)
    {
        Res = Crypto_GetKeyInfo(CryptoJob, &KeyPtr, &IvPtr, &IvLen);

        if((Std_ReturnType)E_OK == Res)
        {
#if (STD_ON == CRYPTO_ALGOMODE_CUSTOM_SWITCH)  
            if ((CRYPTO_OPERATIONMODE_SINGLECALL != OperationMode) && ((Crypto_AlgorithmModeType)CRYPTO_ALGOMODE_CCM == Mode))
            {
                Ret = AES_DRV_STATUS_INPUT_ERROR;
            }
            else
#endif            
            {
                switch(OperationMode)
                {
                    case CRYPTO_OPERATIONMODE_START:
                        Ret = Aes_Drv_StartGcm(KeyPtr, IvPtr, 8U * IvLen, AES_DRV_DECRYPTION);
                        break;
                    case CRYPTO_OPERATIONMODE_UPDATE:
                        if ((0U != SecondInputLen) && (NULL_PTR != SecondInputPtr))
                        {
                            Ret = Aes_Drv_UpdateGcmAad(SecondInputPtr, SecondInputLen, AES_DRV_DECRYPTION);
                        }
                        if (AES_DRV_STATUS_NO_ERR == Ret)
                        {
                            Ret = Aes_Drv_UpdateGcmData(InputPtr, InputLen, OutputPtr, AES_DRV_DECRYPTION);
                        }
                        break;
                    case CRYPTO_OPERATIONMODE_STREAMSTART:
                        Ret = Aes_Drv_StartGcm(KeyPtr, IvPtr, 8U * IvLen, AES_DRV_DECRYPTION);
                        if((AES_DRV_STATUS_NO_ERR == Ret) &&
                           ((0U != SecondInputLen) && (NULL_PTR != SecondInputPtr)))
                        {
                            Ret = Aes_Drv_UpdateGcmAad(SecondInputPtr, SecondInputLen, AES_DRV_DECRYPTION);
                        }
                        if (AES_DRV_STATUS_NO_ERR == Ret)
                        {
                            Ret = Aes_Drv_UpdateGcmData(InputPtr, InputLen, OutputPtr, AES_DRV_DECRYPTION);
                        }
                        break;
                    case CRYPTO_OPERATIONMODE_FINISH:
                        Ret = Aes_Drv_FinishGcm(InputPtr, InputLen, SecondInputPtr, SecondInputLen, 
                                                OutputPtr, GenTagPtr, ThirdInputLen, AES_DRV_DECRYPTION);
                        if(AES_DRV_STATUS_NO_ERR == Ret)
                        {
                            CompareResult = Aes_Drv_CompareData(ThirdInputPtr, GenTagPtr, 8U*ThirdInputLen);
                            *VerifyPtr = (Crypto_VerifyResultType)CompareResult;
                        }
                        else
                        {
                            *VerifyPtr = CRYPTO_E_VER_NOT_OK; 
                        }
                        break;
                    case CRYPTO_OPERATIONMODE_SINGLECALL:
                        if(CRYPTO_ALGOMODE_GCM == Mode)
                        {
                            Ret = Aes_Drv_Gcm(KeyPtr, IvPtr, 8U * IvLen, InputPtr, InputLen, SecondInputPtr, 
                                              SecondInputLen, OutputPtr, GenTagPtr, ThirdInputLen,
                                              AES_DRV_DECRYPTION);
                        }
#if (STD_ON == CRYPTO_ALGOMODE_CUSTOM_SWITCH)                        
                        else
                        {
                            Ret = Aes_Drv_Ccm(KeyPtr, IvPtr, IvLen, InputPtr, InputLen, SecondInputPtr, 
                                              SecondInputLen, OutputPtr, GenTagPtr, ThirdInputLen,
                                              AES_DRV_DECRYPTION);
                        }
#endif
                        if(AES_DRV_STATUS_NO_ERR == Ret)
                        {
                            CompareResult = Aes_Drv_CompareData(ThirdInputPtr, GenTagPtr, 8U*ThirdInputLen);
                            *VerifyPtr = (Crypto_VerifyResultType)CompareResult;
                        }
                        else
                        {
                            *VerifyPtr = CRYPTO_E_VER_NOT_OK; 
                        }
                        break;
                    default:
                        Ret = AES_DRV_STATUS_MODE_ERR;
                        break;
                }
            }
            
            if(CRYPTO_OPERATIONMODE_START != CryptoJob->jobPrimitiveInputOutput.mode)
            {
                *OutputLen = ((AES_DRV_STATUS_NO_ERR == Ret) ? InputLen : 0U);
            }
            
            Res = Crypto_ConvertAesResponse(Ret);
        }
    }  
    else
    {
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_SMALL_BUFFER);
#else
        Res = (Std_ReturnType)E_NOT_OK;
#endif
    }
    return Res;
}

/**
 * @brief     This function performs the encryption or decryption operation
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *                       Contains structures with job and primitive relevant information 
 *                       but also pointer to result buffers.
 *
 * @return    Std_ReturnType
 * 
 */

/**
 * @brief     Processes the Authenticated Encryption/Decryption with Associated Data service.
 *            Note: GCM/CCM mode is supported.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_AeadEncryptDecrypt(Crypto_JobType const *CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    Crypto_ServiceInfoType Service = CryptoJob->jobPrimitiveInfo->primitiveInfo->service;
    Crypto_AlgorithmModeType Mode = CryptoJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    if((CRYPTO_ALGOMODE_GCM == Mode) 
#if (STD_ON == CRYPTO_ALGOMODE_CUSTOM_SWITCH)  
    || ((Crypto_AlgorithmModeType)CRYPTO_ALGOMODE_CCM == Mode))
#else
    )
#endif
    {
        if (CRYPTO_AEADENCRYPT == Service)
        {
            Ret = Crypto_AeadEncryptOperation(CryptoJob, Mode);
        }
        else
        {
            Ret = Crypto_AeadDecryptOperation(CryptoJob, Mode);
        }
    }

    return Ret;
}

#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
/**
 * @brief     Check the Crypto module state.
 *
 * @param[in] ServiceId: ApiId.
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckModuleStatus(uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(CRYPTO_DRIVER_UNINIT == Crypto_InitState)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the Crypto Driver Object id is out of range.
 *
 * @param[in] ObjectId: Crypto Driver Object id.
 * @param[in] ServiceId: ApiId.
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckObjectId(uint32 ObjectId, uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(ObjectId >= CRYPTO_NUMBER_OF_DRIVER_OBJECTS)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_PARAM_HANDLE);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the job pointer is NULL.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 * @param[in] ServiceId: ApiId.
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckJobPtr(Crypto_JobType const *CryptoJob, uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if(NULL_PTR == CryptoJob)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_PARAM_POINTER);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the primitive is supported.
 *
 * @param[in] ObjectId: Crypto Driver Object identifier.
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
static Std_ReturnType Crypto_CheckPrimitive(uint32 ObjectId, const Crypto_JobType *CryptoJob)
{
	Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    uint32 Count;
    const Crypto_PrimitiveInfoType* JobPrimitive = CryptoJob->jobPrimitiveInfo->primitiveInfo;
    const Crypto_PrimitiveType* TempPrimitive;

    if((32U!=JobPrimitive->algorithm.keyLength)&&(CRYPTO_ALGOMODE_XTS==JobPrimitive->algorithm.mode))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if((16U != JobPrimitive->algorithm.keyLength) && 
            (CRYPTO_RANDOMGENERATE != JobPrimitive->service) &&
            (CRYPTO_KEYSETVALID != JobPrimitive->service) &&
            (CRYPTO_ALGOMODE_XTS != JobPrimitive->algorithm.mode))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        for (Count = 0U; Count < Crypto_ObjectPrimitiveList[ObjectId].CryptoPrimitivesNum; Count++)
        {
            TempPrimitive = &Crypto_ObjectPrimitiveList[ObjectId].CryptoPrimitives[Count];
            if ((JobPrimitive->service == TempPrimitive->Service) && 
                ((uint8)JobPrimitive->algorithm.family == TempPrimitive->AlgoFamily) && 
                ((uint8)JobPrimitive->algorithm.mode == TempPrimitive->AlgoMode))
            {
                Ret = (Std_ReturnType)E_OK;
                break;
            }
        }
    }

    if((Std_ReturnType)E_OK != Ret)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_PARAM_HANDLE);
    }

	return Ret;
}

/**
 * @brief     Checks if the input parameters are valid.
 *
 * @param[in] InputPtr: Pointer to the input data buffer.
 * @param[in] InputLen: Input length in bytes.
 * 
 * @return    Std_ReturnType
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckInputPara(const uint8 *InputPtr, uint32 InputLen)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if(NULL_PTR == InputPtr)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_PARAM_POINTER);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if(0U == InputLen)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_PARAM_VALUE);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief     Checks if the output parameters are valid.
 *
 * @param[in] OutputPtr: Pointer to the output data buffer.
 * @param[in] OutputLenPtr: Pointer to the output length.
 * 
 * @return    Std_ReturnType
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckOutputPara(const uint8 *OutputPtr, const uint32 *OutputLenPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if((NULL_PTR == OutputPtr) || (NULL_PTR == OutputLenPtr))
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_PARAM_POINTER);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if(0U == *OutputLenPtr)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_PROCESSJOB, CRYPTO_E_PARAM_VALUE);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/**
 * @brief     Checks if there is any invalid parameter for Crypto_ProcessJob() API.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 *
 */
static Std_ReturnType Crypto_CheckProcessJob(Crypto_JobType const *CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    Crypto_OperationModeType OperationMode = CryptoJob->jobPrimitiveInputOutput.mode;
    Crypto_ServiceInfoType JobService = CryptoJob->jobPrimitiveInfo->primitiveInfo->service;

    const uint8 *InputPtr = NULL_PTR;
    uint32 InputLen = 0U;
    const uint8 *SecondInputPtr = NULL_PTR;
    uint32 SecondInputLen = 0U;
    const uint8 *ThirdInputPtr = NULL_PTR;
    uint32 ThirdInputLen = 0U;
    uint8 *OutputPtr = NULL_PTR;
    uint32 *OutputLen = NULL_PTR;
    uint8 *SecondOutputPtr = NULL_PTR;
    uint32 *SecondOutputLen = NULL_PTR;
    Crypto_VerifyResultType const *VerifyPtr = CryptoJob->jobPrimitiveInputOutput.verifyPtr;

    if (0x0U != ((uint8)OperationMode & (Crypto_ParaCheckList[JobService].InputMask)))
    {
        Ret = Crypto_GetInputPara(CryptoJob, &InputPtr, &InputLen, CRYPTO_INPUT_MASK);
        Ret |= Crypto_CheckInputPara(InputPtr, InputLen);
    }

    if (0x0U != ((uint8)OperationMode & (Crypto_ParaCheckList[JobService].SecondInputMask)))
    {
        Ret |= Crypto_GetInputPara(CryptoJob, &SecondInputPtr, &SecondInputLen, CRYPTO_SECOND_INPUT_MASK);
        Ret |= Crypto_CheckInputPara(SecondInputPtr, SecondInputLen);
    }

    if (0x0U != ((uint8)OperationMode & (Crypto_ParaCheckList[JobService].ThirdInputMask)))
    {
        Ret |= Crypto_GetInputPara(CryptoJob, &ThirdInputPtr, &ThirdInputLen, CRYPTO_THIRD_INPUT_MASK);
        Ret |= Crypto_CheckInputPara(ThirdInputPtr, ThirdInputLen);
    }

    if (0x0U != ((uint8)OperationMode & (Crypto_ParaCheckList[JobService].OutputMask)))
    {
        Ret |= Crypto_GetOutputPara(CryptoJob, &OutputPtr, &OutputLen, CRYPTO_OUTPUT_MASK);
        Ret |= Crypto_CheckOutputPara(OutputPtr, OutputLen);
    }

    if (0x0U != ((uint8)OperationMode & (Crypto_ParaCheckList[JobService].SecondOutputMask)))
    {
        Ret |= Crypto_GetOutputPara(CryptoJob, &SecondOutputPtr, &SecondOutputLen, CRYPTO_SECOND_OUTPUT_MASK);
        Ret |= Crypto_CheckOutputPara(SecondOutputPtr, SecondOutputLen);
    }

    if (0x0U != ((uint8)OperationMode & (Crypto_ParaCheckList[JobService].VerifyMask)))
    {
        Ret |= Crypto_CheckInputPara((uint8 const*)VerifyPtr, 0x5A5AU);
    }

    return Ret;
}
#endif

/**
 * @brief     Performs random number generation.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_ProcessTrngOperation(Crypto_JobType const *CryptoJob)
{
    Trng_Drv_StatusType ResultStatus;
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    uint32 const *OutputLength = CryptoJob->jobPrimitiveInputOutput.outputLengthPtr;

    ResultStatus = Trng_Drv_GetCtrDrbgRandomData(CryptoJob->jobPrimitiveInputOutput.outputPtr, 
                                                 *OutputLength);
    /* Translate TRNG response into a Std_ReturnType one */
    Ret = Crypto_ConvertTrngResponse(ResultStatus);

    return Ret;
}

/**
 * @brief     Processes for supported primitive services.
 *
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_ProcessAesOperation(Crypto_JobType const *CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    switch (CryptoJob->jobPrimitiveInfo->primitiveInfo->service)
    {
        case CRYPTO_MACGENERATE:
        case CRYPTO_MACVERIFY:
            Ret = Crypto_GenerateVerifyMac(CryptoJob);
            break;
        case CRYPTO_AEADENCRYPT:
        case CRYPTO_AEADDECRYPT:
            Ret = Crypto_AeadEncryptDecrypt(CryptoJob);
            break;
        case CRYPTO_ENCRYPT:
        case CRYPTO_DECRYPT:
            Ret = Crypto_EncryptDecrypt(CryptoJob);
            break;
        default:
            /* The service is not supported by current hardware */
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
    }

    return Ret;
}

/**
 * @brief     Handles Aes jobs accepted when Aes is idle.
 *
 * @param[in] ObjectIndex: Holds the identifier of the Crypto Driver Object.
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_HandleWithAesIdle(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob)
{    
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    boolean Res;

    /* A sync job can only be processed when there is no any other job is being processed */
    if((CRYPTO_PROCESSING_SYNC == CryptoJob->jobPrimitiveInfo->processingType) && 
       (FALSE == Crypto_AesJobInfo.ProcessingFlag))
    {
        Crypto_AesJobInfo.ProcessingFlag = TRUE;
        Crypto_AesJobInfo.AesState = CRYPTO_DRIVER_OBJECT_ACTIVE;
        Crypto_AesJobInfo.CurrentJobId = CryptoJob->jobId;
        CryptoJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
        
        Ret = Crypto_ProcessAesOperation(CryptoJob);
        
        Crypto_AesJobInfo.ProcessingFlag = FALSE;
    
        if(((Std_ReturnType)E_OK != Ret) || 
           (CRYPTO_OPERATIONMODE_SINGLECALL == CryptoJob->jobPrimitiveInputOutput.mode))
        {
            Crypto_AesJobInfo.AesState = CRYPTO_DRIVER_OBJECT_IDLE;
            Crypto_AesJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
            CryptoJob->jobState = CRYPTO_JOBSTATE_IDLE;
        }
    }
    else if(CRYPTO_PROCESSING_ASYNC == CryptoJob->jobPrimitiveInfo->processingType)
    {
        Res = Crypto_EnqueueJob(ObjectIndex, CryptoJob);
        if(TRUE == Res)
        {
            Ret = (Std_ReturnType)E_OK;
        }
        else
        {
            Ret = CRYPTO_E_BUSY;
        }
    }
    else
    {
        /* do nothing */
    }
    
    return Ret;
}

/**
 * @brief     Handles Aes jobs accepted when Aes is active.
 *
 * @param[in] ObjectIndex: Holds the identifier of the Crypto Driver Object.
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_HandleWithAesActive(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    boolean Res;

    /* A sync job can only be processed when there is no any other job is being processed, 
       and its id matches the id of the current processing job. */
    if((CRYPTO_PROCESSING_SYNC == CryptoJob->jobPrimitiveInfo->processingType) && 
       (FALSE == Crypto_AesJobInfo.ProcessingFlag) &&
       (Crypto_AesJobInfo.CurrentJobId == CryptoJob->jobId))
    {
        /* "start" indicates reset the current job. "update" indicates feed data for 
           the current job, and "finish" indicates end the current job. */
        Crypto_AesJobInfo.ProcessingFlag = TRUE;
        CryptoJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
        Ret = Crypto_ProcessAesOperation(CryptoJob);
        Crypto_AesJobInfo.ProcessingFlag = FALSE;

        if(((Std_ReturnType)E_OK != Ret) || 
           ((uint8)CRYPTO_OPERATIONMODE_FINISH == ((uint8)CryptoJob->jobPrimitiveInputOutput.mode & 0x04U)))
        {
            Crypto_AesJobInfo.AesState = CRYPTO_DRIVER_OBJECT_IDLE;
            Crypto_AesJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
            CryptoJob->jobState = CRYPTO_JOBSTATE_IDLE;
        }
    }
    else if(CRYPTO_PROCESSING_ASYNC == CryptoJob->jobPrimitiveInfo->processingType)
    {
        /* enqueue the async "start" job */
        if((uint8)CRYPTO_OPERATIONMODE_START == ((uint8)CryptoJob->jobPrimitiveInputOutput.mode & 0x01U))
        {
            Res = Crypto_EnqueueJob(ObjectIndex, CryptoJob);
            if(TRUE == Res)
            {
                Ret = (Std_ReturnType)E_OK;
            }
            else
            {
                Ret = CRYPTO_E_BUSY;
            }
        }
        /* record async "update" or "finish" job for next process when there is no pending job */
        else if((Crypto_AesJobInfo.CurrentJobId == CryptoJob->jobId) &&
                (NULL_PTR == Crypto_AesJobInfo.PendingJobPtr))
        {
            Crypto_AesJobInfo.PendingJobPtr = CryptoJob;
            Ret = (Std_ReturnType)E_OK;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        Ret = CRYPTO_E_BUSY;
    }

    return Ret;
}

/**
 * @brief     Handles Trng jobs.
 *
 * @param[in] ObjectIndex: Holds the identifier of the Crypto Driver Object.
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_HandleTrngJob(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    boolean Res;

    if(CRYPTO_OPERATIONMODE_SINGLECALL == CryptoJob->jobPrimitiveInputOutput.mode)
    {
        /* "start" indicates a new request of a crypto primitive, and it shall cancel all previous 
           requests of the same job. */
        (void)Crypto_DequeueJob(ObjectIndex, CryptoJob->jobId);

        if((CRYPTO_PROCESSING_SYNC == CryptoJob->jobPrimitiveInfo->processingType) && 
           (CRYPTO_JOBSTATE_IDLE == CryptoJob->jobState) && (FALSE == Crypto_TrngJobInfo.ProcessingFlag))
        {
            Crypto_TrngJobInfo.ProcessingFlag = TRUE; 
            Crypto_TrngJobInfo.CurrentJobId = CryptoJob->jobId;
            Ret = Crypto_ProcessTrngOperation(CryptoJob);
            Crypto_TrngJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
            Crypto_TrngJobInfo.ProcessingFlag  = FALSE;
        }
        else if(CRYPTO_PROCESSING_ASYNC == CryptoJob->jobPrimitiveInfo->processingType)
        {
            /* enqueue the async single call job */
            Res = Crypto_EnqueueJob(ObjectIndex, CryptoJob);
            if(TRUE == Res)
            {
                Ret = (Std_ReturnType)E_OK;
            }
            else
            {
                Ret = CRYPTO_E_BUSY;
            }   
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}

/**
 * @brief     Handles Aes jobs.
 *
 * @param[in] ObjectIndex: Holds the identifier of the Crypto Driver Object.
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_HandleAesJob(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    /* "start" indicates a new request of a crypto primitive, and it shall cancel all previous 
        requests of the same job. */
    if((uint8)CRYPTO_OPERATIONMODE_START == ((uint8)CryptoJob->jobPrimitiveInputOutput.mode & 0x01U))
    {
        (void)Crypto_DequeueJob(ObjectIndex, CryptoJob->jobId);
    }

    /* Only jobs with "start" flag can be accepted when AES is idle.
       Job state should be idle when operation mode is start/stream start/single call.
       Current job id should be an invalid value when AES is idle */
    if((CRYPTO_DRIVER_OBJECT_IDLE == Crypto_AesJobInfo.AesState) && 
       ((uint8)CRYPTO_OPERATIONMODE_START == ((uint8)CryptoJob->jobPrimitiveInputOutput.mode & 0x01U)) &&
       (CRYPTO_JOBSTATE_IDLE == CryptoJob->jobState) &&
       (CRYPTO_INVALID_JOBID == Crypto_AesJobInfo.CurrentJobId))
    {
        Ret = Crypto_HandleWithAesIdle(ObjectIndex, CryptoJob);
    }
    /* AES is active means a job has been started.
       Current job id shoule be a valid job id when AES is active */
    else if((CRYPTO_DRIVER_OBJECT_ACTIVE == Crypto_AesJobInfo.AesState) &&
            (CRYPTO_INVALID_JOBID != Crypto_AesJobInfo.CurrentJobId))
    {
        Ret = Crypto_HandleWithAesActive(ObjectIndex, CryptoJob);
    }
    else
    {
        /* do nothing */
    }
    return Ret;
}

/**
 * @brief     Handles Key jobs.
 *
 * @param[in] ObjectIndex: Holds the identifier of the Crypto Driver Object.
 * @param[in] CryptoJob: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_HandleKeyJob(const uint32 ObjectIndex, Crypto_JobType* const CryptoJob)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    boolean Res;

    /* Only single call mode and async processing type is supported for KEYSETVALID job */
    if((CRYPTO_OPERATIONMODE_SINGLECALL == CryptoJob->jobPrimitiveInputOutput.mode) && 
       (CRYPTO_PROCESSING_ASYNC == CryptoJob->jobPrimitiveInfo->processingType))
    {
        /* "start" indicates a new request of a crypto primitive, and it shall cancel all previous 
           requests of the same job. */
        (void)Crypto_DequeueJob(ObjectIndex, CryptoJob->jobId);

        /* enqueue the async single call job */
        Res = Crypto_EnqueueJob(ObjectIndex, CryptoJob);
        if(TRUE == Res)
        {
            Ret = (Std_ReturnType)E_OK;
        }
        else
        {
            Ret = CRYPTO_E_BUSY;
        }   
    }

    return Ret;
}

/**
 * @brief     This interface removes the provided job from the queue and cancels the 
 *            processing of the job if possible.
 *
 * @param[in] ObjectId: Holds the identifier of the Crypto Driver Object.
 * @param[in] Job: Pointer to the configuration of the job. Contains structures with job 
 *            and primitive relevant information.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_CancelTrngJob(uint32 ObjectId, Crypto_JobType* Job)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if((TRUE == Crypto_TrngJobInfo.ProcessingFlag) && (Crypto_TrngJobInfo.CurrentJobId == Job->jobId))
    {
        Ret = CRYPTO_E_JOB_CANCELED;
    }
    else
    {
        Ret = Crypto_DequeueJob(ObjectId, Job->jobId);
        if((Std_ReturnType)E_OK == Ret)
        {
            Job->jobState = CRYPTO_JOBSTATE_IDLE;
        }
    }

    return Ret;
}

/**
 * @brief     This interface removes the provided job from the queue and cancels the 
 *            processing of the job if possible.
 *
 * @param[in] ObjectId: Holds the identifier of the Crypto Driver Object.
 * @param[in] Job: Pointer to the configuration of the job. Contains structures with job 
 *            and primitive relevant information.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_CancelAesJob(uint32 ObjectId, Crypto_JobType* Job)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if((CRYPTO_DRIVER_OBJECT_ACTIVE == Crypto_AesJobInfo.AesState) && 
       (TRUE == Crypto_AesJobInfo.ProcessingFlag) &&
       (Job->jobId == Crypto_AesJobInfo.CurrentJobId))
    {
        Ret = CRYPTO_E_JOB_CANCELED;
    }
    else
    {
        Ret = Crypto_DequeueJob(ObjectId, Job->jobId);
        if((Std_ReturnType)E_OK == Ret)
        {
            Job->jobState = CRYPTO_JOBSTATE_IDLE;
        }
        else if(NULL_PTR != Crypto_AesJobInfo.PendingJobPtr)
        {
            if((Job->jobId == Crypto_AesJobInfo.PendingJobPtr->jobId) &&
               (Job->jobId == Crypto_AesJobInfo.CurrentJobId))
            {
                Crypto_AesJobInfo.AesState = CRYPTO_DRIVER_OBJECT_IDLE;
                Crypto_AesJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
                Crypto_AesJobInfo.PendingJobPtr = NULL_PTR;
                Job->jobState = CRYPTO_JOBSTATE_IDLE;
                
                Ret = (Std_ReturnType)E_OK;
            }
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}

/**
 * @brief     This interface removes the provided job from the queue and cancels the 
 *            processing of the job if possible.
 *
 * @param[in] ObjectId: Holds the identifier of the Crypto Driver Object.
 * @param[in] Job: Pointer to the configuration of the job. Contains structures with job 
 *            and primitive relevant information.
 *
 * @return    Std_ReturnType
 * 
 */
static Std_ReturnType Crypto_CancelKeyJob(uint32 ObjectId, Crypto_JobType* Job)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if((TRUE == Crypto_KeyJobInfo.ProcessingFlag) && (Crypto_KeyJobInfo.CurrentJobPtr == Job))
    {
        Ret = CRYPTO_E_JOB_CANCELED;
    }
    else
    {
        Ret = Crypto_DequeueJob(ObjectId, Job->jobId);
        if((Std_ReturnType)E_OK == Ret)
        {
            Job->jobState = CRYPTO_JOBSTATE_IDLE;
        }
    }

    return Ret;
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * @brief     Initializes the Crypto Driver.
 *
 * @param[in] ConfigPtr: Pointer to a selected configuration structure.
 * 
 * @return    None
 * 
 */
void Crypto_Init(const Crypto_ConfigType *configPtr)
{
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    if(CRYPTO_DRIVER_INITIALIZED == Crypto_InitState)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_INIT,
                              CRYPTO_E_INIT_FAILED);
    }
    else
#endif /* (CRYPTO_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Initialize the random number generator */
        Trng_Drv_Init();
        
        /* Initialize the job queues */
        Crypto_InitJobQueues();

        /* Restore non-persist key elements */
        Crypto_RestoreNonPersistentKeyElements();
            
        /* Restore persist key elements */
        Crypto_RestoreKeysFromNvm();

        /* Initialize the global variables */
        Crypto_InitState = CRYPTO_DRIVER_INITIALIZED;
        Crypto_AesJobInfo.CurrentJobId = CRYPTO_INVALID_JOBID;
        Crypto_KeyJobInfo.ProcessingKeyId = CRYPTO_INVALID_KEYID;
    }

    (void)configPtr;
}

/**
 * @brief     Performs the crypto primitive, that is configured in the job parameter.
 *
 * @param[in] objectId: Holds the identifier of the Crypto Driver Object.
 * @param[in] job: Pointer to the configuration of the job.
 *
 * @return    Std_ReturnType
 * 
 */
Std_ReturnType Crypto_ProcessJob(uint32 objectId, Crypto_JobType* job)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleStatus(CRYPTO_SID_PROCESSJOB);
	Ret |= Crypto_CheckObjectId(objectId, CRYPTO_SID_PROCESSJOB);
	Ret |= Crypto_CheckJobPtr(job, CRYPTO_SID_PROCESSJOB);
    if ((Std_ReturnType)E_OK == Ret)
    {
        Ret = Crypto_CheckPrimitive(objectId, job);
        Ret |= Crypto_CheckProcessJob(job);
    }
	if ((Std_ReturnType)E_OK == Ret)
#endif /* STD_ON == CRYPTO_DEV_ERROR_DETECT*/
    {
        if (CRYPTO_RANDOMGENERATE == job->jobPrimitiveInfo->primitiveInfo->service)
        {
            Ret = Crypto_HandleTrngJob(objectId, job);
        }
        else if(CRYPTO_KEYSETVALID == job->jobPrimitiveInfo->primitiveInfo->service)        
        {
            Ret = Crypto_HandleKeyJob(objectId, job);
        }
        else if(CRYPTO_KEYSETINVALID != job->jobPrimitiveInfo->primitiveInfo->service)
        {
            Ret = Crypto_HandleAesJob(objectId, job);
        }
        else
        {
            /* do nothing */
        }
    }

    return Ret;
}

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
Std_ReturnType Crypto_CancelJob(uint32 objectId, Crypto_JobType* job)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleStatus(CRYPTO_SID_CANCELJOB);
	Ret |= Crypto_CheckObjectId(objectId, CRYPTO_SID_CANCELJOB);
	Ret |= Crypto_CheckJobPtr(job, CRYPTO_SID_CANCELJOB);
	if ((Std_ReturnType)E_OK == Ret)
#endif /* STD_ON == CRYPTO_DEV_ERROR_DETECT*/
    { 
        if(CRYPTO_CDO_INDEX_TRNG == objectId)
        {
            Ret = Crypto_CancelTrngJob(objectId, job);
        }
        else if(CRYPTO_CDO_INDEX_AES == objectId)
        {
            Ret = Crypto_CancelAesJob(objectId, job);
        }
        else
        {
            Ret = Crypto_CancelKeyJob(objectId, job);
        }
    }
    return Ret;
}

/**
 * @brief     If asynchronous job processing is configured and there are job queues, the function 
 *            is called cyclically to process queued jobs.
 *
 * @param[in] None
 *
 * @return    None
 * 
 */
void Crypto_MainFunction(void)
{
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void)Crypto_CheckModuleStatus(CRYPTO_SID_MAINFUNCTION);
#endif /* STD_ON == CRYPTO_DEV_ERROR_DETECT*/

    if(FALSE == Crypto_TrngJobInfo.ProcessingFlag)
    {
        Crypto_SendTrngQueuedJob();
    }

    if((CRYPTO_DRIVER_OBJECT_IDLE == Crypto_AesJobInfo.AesState) &&
       (CRYPTO_INVALID_JOBID == Crypto_AesJobInfo.CurrentJobId) &&
       (FALSE == Crypto_AesJobInfo.ProcessingFlag))
    {
        Crypto_SendAesQueuedJob();
    }
    else if((CRYPTO_DRIVER_OBJECT_ACTIVE == Crypto_AesJobInfo.AesState) &&
            (CRYPTO_INVALID_JOBID != Crypto_AesJobInfo.CurrentJobId) &&
            (FALSE == Crypto_AesJobInfo.ProcessingFlag) &&
            (NULL_PTR != Crypto_AesJobInfo.PendingJobPtr))
    {
        Crypto_HandlePendingJob();
    }
    else
    {
        /* do nothing */
    }  

    /* A key job is being processed */
    if(TRUE == Crypto_KeyJobInfo.ProcessingFlag)
    {
        Crypto_HandleNvmResult();
    }
    else
    {
        Crypto_SendKeyQueuedJob();
    }
}

#if (STD_ON == CRYPTO_VERSION_INFO_API)
/**
 * @brief      Returns the version information of this module.
 *
 * @param[out] versionInfo: Pointer to where to store the version information of this module.
 *
 * @return     None
 * 
 */
void Crypto_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_GETVERSIONINFO,
                              CRYPTO_E_PARAM_POINTER);
    }
    else
#endif /* (CRYPTO_DEV_ERROR_DETECT == STD_ON) */
    {
        (versioninfo)->vendorID = (uint16)CRYPTO_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)CRYPTO_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)CRYPTO_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)CRYPTO_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)CRYPTO_SW_PATCH_VERSION;
    }
}
#endif /* (CRYPTO_VERSION_INFO_API == STD_ON) */

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Crypto */

/** @} end of group Crypto_Module */
