/**
 * @file    Adc.c
 * @version
 *
 * @brief   AUTOSAR Adc module interface
 * @details API implementation for ADC driver
 *
 * @addtogroup ADC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Adc
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#include "Compiler.h"
#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Adc_PBcfg.h"
#include "Adc.h"
#include "Adc_Lld.h"
#include "SchM_Adc.h"
#include "Det.h"
#include "OsIf.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_C                      (180)
#define ADC_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ADC_AR_RELEASE_MINOR_VERSION_C       (4)
#define ADC_AR_RELEASE_REVISION_VERSION_C    (0)
#define ADC_SW_MAJOR_VERSION_C               (2)
#define ADC_SW_MINOR_VERSION_C               (3)
#define ADC_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_VENDOR_ID_C != ADC_VENDOR_ID)
#error "Adc.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Adc.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Adc.c and Adc.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define ADC_INVALID_GROUP_INDEX 0xFFFFU
#define ADC_INVALID_HW_INDEX 0xFFU
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/



/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_VAR_INIT_BOOLEAN
#include "Adc_MemMap.h"
/* ADC Init Status flag*/
ADC_VAR static boolean  Adc_IsDriverInit = FALSE;
#define ADC_STOP_SEC_VAR_INIT_BOOLEAN
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
#if(ADC_FIXED_PB_CONFIG == STD_ON)
/*ADC conversion result buffer*/
ADC_VAR Adc_GroupResultType     Adc_GroupResult[ADC_GROUP_NUMBER];
#else
ADC_VAR Adc_GroupResultType     Adc_GroupResult[ADC_MAX_GROUPS];
#endif
/*ADC hw status data*/
ADC_VAR Adc_UnitStatusType Adc_HwStatus[ADC_MAX_HW_UNITS];

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
ADC_VAR static Adc_PowerStateType Adc_CurrentState;
ADC_VAR static Adc_PowerStateType Adc_TargetState;
#endif /* (ADC_LOW_POWER_STATES_SUPPORT == STD_ON) */
#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT_32
#include "Adc_MemMap.h"
#if(ADC_FIXED_PB_CONFIG == STD_ON)
extern const Adc_ConfigType Adc_PreCompileConfig;
/* Variable Adc_ConfigPtr point to configuration data of ADC units */
ADC_VAR const Adc_ConfigType *Adc_ConfigPtr = &Adc_PreCompileConfig;
#else
/* Variable Adc_ConfigPtr point to configuration data of ADC units */
ADC_VAR const Adc_ConfigType *Adc_ConfigPtr = NULL_PTR;
#endif
#define ADC_STOP_SEC_VAR_INIT_32
#include "Adc_MemMap.h"
/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static Std_ReturnType Adc_ValidGroupCheck(Adc_GroupType Group);

#if((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING==STD_ON))
static uint8 Adc_CheckGroupQueueIndex(uint16 GroupIndex);

static void Adc_GroupsInQueueUpdate(uint8 AdcHwIndex);

#else
static Std_ReturnType Adc_GroupStatusCheck(Adc_StatusType GroupStatus);
#endif /*((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING==STD_ON))*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/************************************************************************************
 * limit the Adc queue depth
 ************************************************************************************/
#if (ADC_ENABLE_QUEUING == STD_ON)||(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
ADC_FUNC LOCAL_INLINE void Adc_LimitQueueIndex(uint8 AdcHwIndex)
{
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > ADC_QUEUE_MAX_DEPTH_MAX)
    {
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = ADC_QUEUE_MAX_DEPTH_MAX;
    }
}
#endif

/************************************************************************************
 * check the ADC driver is initialized or not and the group is valid or not
 ************************************************************************************/
ADC_FUNC static Std_ReturnType Adc_InitAndGroupValidErrCheck(uint8 AdcInstanceId, uint8 AdcApiNumber, Adc_GroupType Group)
{
    Std_ReturnType TempRet = E_OK;
    if (FALSE == Adc_IsDriverInit)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, AdcInstanceId, AdcApiNumber, ADC_E_UNINIT);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
        TempRet = E_NOT_OK;
    }
    else
    {
        /* SWS_Adc_00225 */
        if (E_NOT_OK == Adc_ValidGroupCheck(Group))
        {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, AdcInstanceId, AdcApiNumber, ADC_E_PARAM_GROUP);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempRet = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    return TempRet;
}

/*************************************************************************************
* Check the group id valid or not.
**************************************************************************************/
ADC_FUNC static Std_ReturnType Adc_ValidGroupCheck(Adc_GroupType Group)
{
    Std_ReturnType TempRet = E_OK;
    uint8 InterLoopCount = 0;
    for (InterLoopCount = 0; InterLoopCount < Adc_ConfigPtr->GroupCfgNum; ++InterLoopCount)
    {
        if (Group == Adc_ConfigPtr->GroupUserCfg[InterLoopCount].GroupId)
        {
            break;
        }
    }
    /*Group ID is invalid,return E_NOT_OK*/
    if (InterLoopCount >= Adc_ConfigPtr->GroupCfgNum)
    {
        TempRet = E_NOT_OK;
    }
    return TempRet;
}

#if((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING==STD_ON))
/*************************************************************************************
* Check the specific group in queue or not ,and return the index of the group in queue.
**************************************************************************************/
ADC_FUNC static uint8 Adc_CheckGroupQueueIndex(uint16 GroupIndex)
{
    uint8 InterLoopCount = ADC_INVALID_HW_INDEX;
    Adc_GroupType Group = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupId;
    uint8 AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
    for (InterLoopCount = 0; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex; ++InterLoopCount)
    {
        if (Group == Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount])
        {
            break;
        }
    }
    if (InterLoopCount >= Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex)
    {
        InterLoopCount = ADC_INVALID_HW_INDEX;
    }
    return InterLoopCount;
}

/*************************************************************************************
* Remove the group which has been converted, and load next group to convert when
* queue is not empty.
**************************************************************************************/
ADC_FUNC static void Adc_GroupsInQueueUpdate(uint8 AdcHwIndex)
{
    /*stop convert and empty fifo*/
#ifdef ADC_USER_MODE_SUPPORTED
    OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
    OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
#else
    Adc_Lld_StopConversion(AdcHwIndex);
    Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
#endif
    Adc_LimitQueueIndex(AdcHwIndex);
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 1u)
    {
        uint8 InterGroupIndex = 0;
        /*load next group to ADC HW and start conversion*/
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
        for (uint8 InterLoopCount = 0; (InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex); ++InterLoopCount)
        {
            Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1u]; /*NOSONAR,There are no memory overruns here*/
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
            Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount + 1];
#endif /*(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)*/
        }
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = ADC_INVALID_GROUP_INDEX;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
        InterGroupIndex = (uint8)Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
#ifdef ADC_USER_MODE_SUPPORTED
        OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, InterGroupIndex);
        OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
        Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, InterGroupIndex);
        Adc_Lld_StartConversion(AdcHwIndex);
#endif
    }
    else if (1U == Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex)
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[0] =  ADC_INVALID_GROUP_INDEX;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
    }
    else
    {
        /*nothing to do*/
    }
}

#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
/*************************************************************************************
* Remove the group which has been converted, and load next group to convert when
* queue is not empty.
**************************************************************************************/
ADC_FUNC static uint8 Adc_PriorityIndexCheck(uint8 AdcHwIndex, uint16 GroupIndex)
{
    uint8 InterLoopCount = 0;
    Adc_GroupPriorityType GroupPrio = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupPriority;
    for (InterLoopCount = 0; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex; InterLoopCount++)
    {
        if (GroupPrio > Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount])
        {
            break;
        }
        else
        {    }
    }
    return (InterLoopCount);
}

ADC_FUNC static void Adc_InjectGroupToQueue(uint8 AdcHwIndex, uint16 GroupIndex, uint8 QueueIndex)
{
    uint8 InterLoopCount  = 0;
    for (InterLoopCount = QueueIndex; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex; InterLoopCount++)
    {
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount];
        Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount + 1] = Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount];
    }
    Adc_HwStatus[AdcHwIndex].SwNormalQueue[QueueIndex] = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupId;
    Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[QueueIndex] = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupPriority;
}
#endif
#else
/*************************************************************************************
* Check Adc_GroupResult array, there is any group status the same as input parameter.
**************************************************************************************/
ADC_FUNC static Std_ReturnType Adc_GroupStatusCheck(Adc_StatusType GroupStatus)
{
    Std_ReturnType TempRet = E_OK;
    uint8 InterLoopCount = 0;
    for (InterLoopCount = 0; InterLoopCount < Adc_ConfigPtr->GroupCfgNum; InterLoopCount++)
    {
        if (GroupStatus == Adc_GroupResult[InterLoopCount].GroupStatus)
        {
            break;
        }
    }
    /*Group ID is invalid,return E_NOT_OK*/
    if (InterLoopCount >= Adc_ConfigPtr->GroupCfgNum)
    {
        TempRet = E_NOT_OK;
    }
    return TempRet;
}
#endif /*((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING==STD_ON))*/


/*************************************************************************************
* This function used to updata the status for a group which don't enable INTC and DMA.
**************************************************************************************/
ADC_FUNC static void Adc_UpdateStatusReadGroupNoInt(uint16 GroupIndex)
{
    Adc_ChannelType AdcGroupChannelNum = 0;
    uint8 AdcHwIndex = 0;
    uint8 TempSampleCnt = 0;
    /* Get adc datas */
    AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
#if (ADC_HW_TRIGGER_API==STD_ON)
    /*Handles the number of times the hardware group collection is completed, because the
        hardware triggers the group in the ** state to allow the collection to continue*/
    if ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW) && \
            (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples))
    {
        Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples - 1u;
    }
#endif
    /*change the count of conversion*/
    ++Adc_GroupResult[GroupIndex].GroupSampleCount;
    AdcGroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
    TempSampleCnt = Adc_GroupResult[GroupIndex].GroupSampleCount - 1u;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* SWS_Adc_00446 ,SWS_Adc_00447, SWS_Adc_00448*/
    boolean LimitCheckResult = FALSE;
    /*buffer filled with data from FIFO register*/
    /*
    */
#ifdef ADC_USER_MODE_SUPPORTED
    LimitCheckResult = OsIf_Trusted_Call_Return5param(Adc_Lld_ReadConversionResults, AdcHwIndex, GroupIndex, \
                       (&(Adc_GroupResult[GroupIndex].GroupValueBuf[AdcGroupChannelNum * TempSampleCnt])), \
                       AdcGroupChannelNum, \
                       Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution);
#else
    LimitCheckResult = Adc_Lld_ReadConversionResults(AdcHwIndex, GroupIndex, \
                       & (Adc_GroupResult[GroupIndex].GroupValueBuf[AdcGroupChannelNum * TempSampleCnt]), \
                       AdcGroupChannelNum, \
                       Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution);
#endif
    if (FALSE == LimitCheckResult)
    {
        Adc_GroupResult[GroupIndex].GroupSampleCount -= 1u;
    }
    else
#else
    /*buffer filled with data from FIFO register*/
#ifdef ADC_USER_MODE_SUPPORTED
    OsIf_Trusted_Call4params(Adc_Lld_ReadConversionResults, AdcHwIndex, \
                             (&(Adc_GroupResult[GroupIndex].GroupValueBuf[AdcGroupChannelNum * TempSampleCnt])), \
                             AdcGroupChannelNum, \
                             Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution);
#else
    Adc_Lld_ReadConversionResults(AdcHwIndex, \
                                  (&(Adc_GroupResult[GroupIndex].GroupValueBuf[AdcGroupChannelNum * TempSampleCnt])), \
                                  AdcGroupChannelNum, \
                                  Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution);
#endif
#endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    {
        /* SWS_Adc_00325 */
        Adc_Lld_GroupStatusUpdata(GroupIndex);
    }
    /*Close ADC HW unit except the continuous mode circular streaming access*/
#ifdef ADC_USER_MODE_SUPPORTED
    OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
#else
    Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
#endif
}

/*************************************************************************************
 * This function used to updata the status for a group which disabled
 * INTC and DMA in api Adc_ReadGroup and Adc_GetLastStreamBuffer.
 *************************************************************************************/
ADC_FUNC static void Adc_UpdataStatusInReadApi(uint8 AdcHwIndex)
{
    uint16 TempOnGoGroupIndex;
    Std_ReturnType GroupAlternateFlag = E_NOT_OK;
    TempOnGoGroupIndex = Adc_Lld_GetRunningGroupIndex(AdcHwIndex);
    if ((ADC_INVALID_GROUP_INDEX != TempOnGoGroupIndex) && \
            (Adc_ConfigPtr->GroupUserCfg[TempOnGoGroupIndex].GroupSample->IntcAndDmaCfg == ADC_INTCANDDMA_DISABLED))
    {
#ifdef ADC_USER_MODE_SUPPORTED
        if (OsIf_Trusted_Call_Return1param(Adc_Lld_ReadSeqConvEndIntFlag, AdcHwIndex) == TRUE)
#else
        if (Adc_Lld_ReadSeqConvEndIntFlag(AdcHwIndex) == TRUE)
#endif
        {
            /*ADC has complete the sequence conversion, read data to buffer and  update group status*/
            Adc_UpdateStatusReadGroupNoInt(TempOnGoGroupIndex);
            GroupAlternateFlag = Adc_Lld_QueueDataUpdata(AdcHwIndex, TempOnGoGroupIndex);
            /*check the queue wether has group to convert*/
            if (E_OK == GroupAlternateFlag)
            {
                if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u)
                {
                    TempOnGoGroupIndex = (uint8)Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
                    if (Adc_GroupResult[TempOnGoGroupIndex].GroupStatus != ADC_STREAM_COMPLETED)
                    {
#ifdef ADC_USER_MODE_SUPPORTED
                        OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, TempOnGoGroupIndex);
                        OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                        Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, TempOnGoGroupIndex);
                        Adc_Lld_StartConversion(AdcHwIndex);
#endif
                    }
                }
                else
                {
                    /*NoGroup to be conversion stop ADC*/
#ifdef ADC_USER_MODE_SUPPORTED
                    OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
                    OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
#else
                    Adc_Lld_StopConversion(AdcHwIndex);
                    Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
#endif
                }
            }
            else
            {
                /*keep the adc group to run, only hw trigger execute this */
            }
        }
    }
}


# if 0
ADC_FUNC static void Adc_UpdataStatusInReadApi(uint8 AdcHwIndex, uint16 AdcOnGoGroupIndex)
{
    uint16 TempOnGoGroupIndex = AdcOnGoGroupIndex;
    if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u) && \
            (ADC_INTCANDDMA_DISABLED == Adc_ConfigPtr->GroupUserCfg[TempOnGoGroupIndex].GroupSample->IntcAndDmaCfg))
    {
        /*ADC has complete the sequence conversion, read data to buffer and  update group status*/
#ifdef ADC_USER_MODE_SUPPORTED
        if (TRUE == OsIf_Trusted_Call_Return1param(Adc_Lld_ReadSeqConvEndIntFlag, AdcHwIndex))
#else
        if (TRUE == Adc_Lld_ReadSeqConvEndIntFlag(AdcHwIndex))
#endif
        {
            Adc_UpdateStatusReadGroupNoInt(TempOnGoGroupIndex);
#if ((STD_ON == ADC_ENABLE_QUEUING)||(ADC_PRIORITY_NONE != ADC_PRIORITY_IMPLEMENTATION))
            boolean GroupOnGoFlag = FALSE;
            GroupOnGoFlag = Adc_Lld_QueueDataUpdata(AdcHwIndex, TempOnGoGroupIndex);
            /*check the queue wether has group to convert*/
            if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u)
            {
                TempOnGoGroupIndex = (uint8)Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
                if ((TRUE == GroupOnGoFlag) && \
                        (Adc_GroupResult[TempOnGoGroupIndex].GroupStatus != ADC_STREAM_COMPLETED))
                {
#ifdef ADC_USER_MODE_SUPPORTED
                    OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, TempOnGoGroupIndex);
                    OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                    Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, TempOnGoGroupIndex);
                    Adc_Lld_StartConversion(AdcHwIndex);
#endif
                }
                else
                {
                    /*nothing to do*/
                }
            }
            else
            {
                /*nothing to do*/
            }
#else
            Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
#endif /*((STD_ON == ADC_ENABLE_QUEUING)||(ADC_PRIORITY_NONE != ADC_PRIORITY_IMPLEMENTATION))*/
        }
        else
        {
            /*nothing to do*/
        }
    }
}
#endif
/******************** End of Adc_UpdataStatusInReadApi ******************************/

/*************************************************************************************
* This function used to updata the status for a group when read data.
*************************************************************************************/
ADC_FUNC static void Adc_UpdataStatusAfterReadData(uint16 GroupIndex)
{
    switch (Adc_GroupResult[GroupIndex].GroupStatus)
    {
        case ADC_COMPLETED:
        {
            Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
            Adc_GroupResult[GroupIndex].GroupSampleCount = 0u;
            Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0u;
        }
        break;
        case ADC_STREAM_COMPLETED:
        {
            /* SWS_Adc_00222-5 */
            /* SWS_Adc_00222-7 */
            /*State machines are processed separately according to software trigger or hardware trigger*/
#if (ADC_HW_TRIGGER_API == STD_ON)
            if (ADC_TRIGG_SRC_HW == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc)
            {
                if ((ADC_ACCESS_MODE_STREAMING == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupAccessMode) && \
                        (ADC_STREAM_BUFFER_LINEAR == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingBufferMode))
                {
                    Adc_GroupResult[GroupIndex].GroupStatus = ADC_IDLE;
                }
                else
                {
                    Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
                }
            }
            else
#endif
            {
                if ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupConversionMode == ADC_CONV_MODE_CONTINUOUS) && \
                        ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupAccessMode     == ADC_ACCESS_MODE_SINGLE) || \
                         (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingBufferMode == ADC_STREAM_BUFFER_CIRCULAR)))
                {
                    /* SWS_Adc_00222 */
                    Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
                }
                else
                {
                    /* SWS_Adc_00221 */
                    /* SWS_Adc_00222 */
                    Adc_GroupResult[GroupIndex].GroupStatus = ADC_IDLE;
                }
            }
            Adc_GroupResult[GroupIndex].GroupSampleCount = 0u;
            Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0u;
        }
        break;
        default:
            /*Nothing to do*/
            break;
    }
}

/*************************************************************************************
 * This function used to switch state machine when read data  in api Adc_ReadGroup .
 *************************************************************************************/
#if (ADC_READ_GROUP_API == STD_ON)
ADC_FUNC static void Adc_SwStateAndRdRstInReadApi(uint16 GroupIndex, Adc_ValueGroupType *DataBufferPtr)
{
    uint16 AdcGroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
    Adc_StreamNumSampleType ResultIndex = 0u;
    if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_STREAM_COMPLETED)
    {
        ResultIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples - 1u;
    }
    else if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_COMPLETED)
    {
        ResultIndex = Adc_GroupResult[GroupIndex].GroupSampleCount - 1u;
    }
    else
    {
        /*nothing to do*/
    }
    Adc_UpdataStatusAfterReadData(GroupIndex);
    /*read data*/
    for (uint8 InterLoopCount = 0; InterLoopCount < AdcGroupChannelNum; ++InterLoopCount)
    {
#ifdef ADC_ERRATA_ERR0002
        if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg == ADC_DMA_ENABLED)
        {
            DataBufferPtr[InterLoopCount] = Adc_GroupResult[GroupIndex].GroupValueBuf[(ResultIndex * (AdcGroupChannelNum + 1U)) + InterLoopCount];
        }
        else
        {
            DataBufferPtr[InterLoopCount] = Adc_GroupResult[GroupIndex].GroupValueBuf[(ResultIndex * AdcGroupChannelNum) + InterLoopCount];
        }
#else
        DataBufferPtr[InterLoopCount] = Adc_GroupResult[GroupIndex].GroupValueBuf[(ResultIndex * AdcGroupChannelNum) + InterLoopCount];
#endif
    }
}
#endif
/*****  End of Adc_SwStateAndRdRstInReadApi  *****************************/

/*********************************************************************************************
 * This function used to switch state machine when read data  in api Adc_GetLastStreamBuffer .
 *********************************************************************************************/
ADC_FUNC static Adc_StreamNumSampleType Adc_SwStateAndRdRstInGetStream(uint16 GroupIndex, Adc_ValueGroupType **PtrToSamplePtr)
{
    Adc_StreamNumSampleType ResultNum  = 0u;
    Adc_ChannelType AdcGroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
    Adc_StreamNumSampleType ResultIndex = 0u;
    if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_STREAM_COMPLETED)
    {
        ResultIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples - 1u;
        ResultNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples;
    }
    else if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_COMPLETED)
    {
        ResultIndex = Adc_GroupResult[GroupIndex].GroupSampleCount - 1u;
        ResultNum = Adc_GroupResult[GroupIndex].GroupSampleCount;
    }
    else
    {
        /*nothing to do*/
    }
    Adc_UpdataStatusAfterReadData(GroupIndex);
    /* SWS_Adc_00214 */
    /* SWS_Adc_00418 */
#ifdef ADC_ERRATA_ERR0002
    if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg == ADC_DMA_ENABLED)
    {
        *PtrToSamplePtr = &(Adc_GroupResult[GroupIndex].GroupValueBuf[ResultIndex * (AdcGroupChannelNum + 1U)]);
    }
    else
    {
        *PtrToSamplePtr = &(Adc_GroupResult[GroupIndex].GroupValueBuf[ResultIndex * AdcGroupChannelNum]);
    }
#else
    *PtrToSamplePtr = &(Adc_GroupResult[GroupIndex].GroupValueBuf[ResultIndex * AdcGroupChannelNum]);
#endif
    return ResultNum;
}

/** End of Adc_SwStateAndRdRstInGetStream  *****************************/

/*********************************************************************************************
 * This function used to handle the hw run again when status is BUSY after reading.
 *********************************************************************************************/
ADC_FUNC static void Adc_HandleHwRunAgainInBusy(Adc_GroupType Group, uint8 AdcHwIndex, uint16 GroupIndex)
{
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    uint16 AdcOnGoGroupIndex = Adc_Lld_GetRunningGroupIndex(AdcHwIndex);
    if (Group == Adc_HwStatus[AdcHwIndex].SwNormalQueue[0])
    {  }
    else
    {
        boolean bQueueUpdate = FALSE;
        if (Adc_GroupResult[AdcOnGoGroupIndex].GroupStatus == ADC_STREAM_COMPLETED)
        {
            for (InterLoopCount = 0u; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex - 1u; InterLoopCount++)
            {
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1];
                Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount + 1];
            }
            Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = ADC_INVALID_GROUP_INDEX;
            Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
            bQueueUpdate = TRUE;
        }
        else
        {   }
        uint8 PrioIndex = Adc_PriorityIndexCheck(AdcHwIndex, GroupIndex);
        Adc_InjectGroupToQueue(AdcHwIndex, GroupIndex, PrioIndex);
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex++;
        if (PrioIndex == 0)
        {
#ifdef ADC_USER_MODE_SUPPORTED
            OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
            OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
#else
            Adc_Lld_StopConversion(AdcHwIndex);
            Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
#endif
            /*Adc_Lld_ClearFIFOInvalidData(AdcHwIndex);*/
            Adc_GroupResult[Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[1])].GroupSampleCount = 0;
        }
        else
        {
            if (TRUE == bQueueUpdate)
            {
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
                OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
#else
                Adc_Lld_StopConversion(AdcHwIndex);
                Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
#endif
                /*Adc_Lld_ClearFIFOInvalidData(AdcHwIndex);*/
            }
            else
            {   }
        }
    }
#elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)&&(ADC_ENABLE_QUEUING == STD_ON ))
    uint16 AdcOnGoGroupIndex = Adc_Lld_GetRunningGroupIndex(AdcHwIndex);
    /*No priority and the queue is enable*/
    if (0U == Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex)
    {
        /*Queue is empty, set group to queue[0] and start conversion*/
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[0] = Group;
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 1u;
#ifdef ADC_USER_MODE_SUPPORTED
        OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
#else
        Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
#endif
    }
    else if (1U == Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex)
    {
        /*only one group in the queue, if the group ongoing has convert completed ,update
            queue to convert this group, else add group to queue*/
        if (Group != Adc_HwStatus[AdcHwIndex].SwNormalQueue[0])
        {
            if (Adc_GroupResult[AdcOnGoGroupIndex].GroupStatus == ADC_STREAM_COMPLETED)
            {
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[0] = Group;
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
#else
                Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
#endif
            }
            else
            {
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[1] = Group;
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex += 1u;
            }
        }
    }
    else
    {
        /*if more than one group in queue, add the group to queue ,and check the
            queue whether need to be update*/
        if (ADC_INVALID_HW_INDEX == Adc_CheckGroupQueueIndex(GroupIndex))
        {
            Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = Group;
            Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex += 1u;
        }
    }
#else
    /*NO priority and queue, start the conversion*/
    if (Group == Adc_HwStatus[AdcHwIndex].SwNormalQueue[0])
    {
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 1u;
    }
    else
    {
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[0] = Group;
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 1u;
#ifdef ADC_USER_MODE_SUPPORTED
        OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
#else
        Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
#endif
    }
#endif
}

/****************************************************************************************
 * @brief   This function used to handle the hw stop or reload next group when status
 * is idle after reading.
 ****************************************************************************************/
ADC_FUNC static void Adc_HwHandleInIdle(uint8 AdcHwIndex, uint16 GroupIndex)
{
#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING == STD_ON ))
    uint8 AdcOnGoGroupIndex = 0;
    uint8 QueueIndex = Adc_CheckGroupQueueIndex(GroupIndex);
    /*Check and limit the queue index*/
    Adc_LimitQueueIndex(AdcHwIndex);
    if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u) && (QueueIndex < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex))
    {
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
        for (uint8 InterLoopCount = 0; (InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex); ++InterLoopCount)
        {
            Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1u];
        }
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = ADC_INVALID_GROUP_INDEX;
        if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u)
        {
            AdcOnGoGroupIndex = (uint8)Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0u]);
            if (ADC_INTCANDDMA_DISABLED == Adc_ConfigPtr->GroupUserCfg[AdcOnGoGroupIndex].GroupSample->IntcAndDmaCfg)
            {
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
                OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
                OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, AdcOnGoGroupIndex);
#else
                Adc_Lld_StopConversion(AdcHwIndex);
                Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
                Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, AdcOnGoGroupIndex);
#endif
            }
            else
            {
                /*nothing to do*/
            }
        }
    }
    else
    {
        /*nothing to do*/
    }
#else
    Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
    (void)GroupIndex;
#endif
}
#if (ADC_HW_TRIGGER_API == STD_ON)
/****************************************************************************************
 * @brief   This function used to check dev error for hardware trigger api.
 ****************************************************************************************/
ADC_FUNC static Std_ReturnType Adc_HwTriggerDevErrorCheck(Adc_GroupType Group, uint8 FunctionSid)
{
    Std_ReturnType TempRet = E_OK;
    if (FALSE == Adc_IsDriverInit)
    {
        /* [SWS_Adc_00297],[SWS_Adc_00298] Check Adc module Init or not*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, FunctionSid, ADC_E_UNINIT);
#endif
        TempRet = E_NOT_OK;
    }
    else if (E_NOT_OK == Adc_ValidGroupCheck(Group))
    {
        /* [SWS_Adc_00128],[SWS_Adc_00129] Check the Group id is valid or not */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, FunctionSid, ADC_E_PARAM_GROUP);
#endif
        TempRet = E_NOT_OK;
    }
    else
    {
        uint16 GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc != ADC_TRIGG_SRC_HW)
        {
            /* [SWS_Adc_00136],[SWS_Adc_00137] Check the Group is a hardware trigger group or not */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, FunctionSid, ADC_E_WRONG_TRIGG_SRC);
#endif
            TempRet = E_NOT_OK;
        }
        else if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupConversionMode != ADC_CONV_MODE_ONESHOT)
        {
            /* [SWS_Adc_00281],[SWS_Adc_00282] The hardware trigger group can't be configured to contineous convert mode*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, FunctionSid, ADC_E_WRONG_CONV_MODE);
#endif
            TempRet = E_NOT_OK;
        }
        else if ((FALSE == Adc_GroupResult[GroupIndex].ResultBufInitSt) && (ADC_SID_ENABLE_HARDWARE_TRIGGER == FunctionSid))
        {
            /* [SWS_Adc_00425] Check the result buffer is enable or not*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, FunctionSid, ADC_E_BUFFER_UNINIT);
#endif
            TempRet = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    return TempRet;
}

/****************************************************************************************
 * @brief   This function reload a group to hardware.
 ****************************************************************************************/
ADC_FUNC static void Adc_StartNextSwGroupToHw(uint8 AdcHwIndex)
{
    uint16 AdcOnGoGroupIndex = 0xFFFFu;
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u)
    {
        AdcOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
        if (Adc_GroupResult[AdcOnGoGroupIndex].GroupStatus != ADC_STREAM_COMPLETED)
        {
            Adc_GroupResult[AdcOnGoGroupIndex].GroupLoadChnNum = 0;
            Adc_GroupResult[AdcOnGoGroupIndex].GroupCompChnNum = 0;
#ifdef ADC_USER_MODE_SUPPORTED
            OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
            OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, AdcOnGoGroupIndex);
#else
            Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, AdcOnGoGroupIndex);
            Adc_Lld_StartConversion(AdcHwIndex);
#endif
        }
    }
}

/****************************************************************************************
* @brief   This function used to add the group to queue,when hardware group is ongoing.
****************************************************************************************/
ADC_FUNC static void Adc_InjectSwGroupToQueue(uint8 AdcHwIndex, Adc_GroupType Group)
{
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || (ADC_ENABLE_QUEUING == STD_ON)
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex < ADC_QUEUE_MAX_DEPTH_MAX)
    {
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = Group;
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex += 1u;
    }
#else
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex < 1)
    {
        Adc_HwStatus[AdcHwIndex].SwNormalQueue[0] = Group;
        Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 1u;
    }
#endif
    else
    {
        /*report a dev runtime error*/
    }
}

#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
/*********************************************************************************************
* This function used to handle hw unit reload after reading.
**********************************************************************************************/
ADC_FUNC static void Adc_HandleHwReloadAfterRead(uint8 AdcHwIndex, Adc_GroupType Group, uint16 GroupIndex)
{
#if (ADC_HW_TRIGGER_API ==STD_ON)
    if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u) || \
            (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_INVALID_GROUP_INDEX))
#else
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u)
#endif /*(ADC_HW_TRIGGER_API == STD_ON)*/
    {
#if (ADC_HW_TRIGGER_API == STD_ON)
        if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_INVALID_GROUP_INDEX)
        {
            /*Read the ongoing group,restart the group or anterior group*/
            uint16 AdcOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup);
            if (GroupIndex == AdcOnGoGroupIndex)
            {
                if (ADC_IDLE == Adc_GroupResult[AdcOnGoGroupIndex].GroupStatus)
                {
                    Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup = ADC_INVALID_GROUP_INDEX;
                    /*The hw is completed,restart another sw group in the queue*/
                    Adc_StartNextSwGroupToHw(AdcHwIndex);
                }
                else
                {
                    /*The hw group need to restart*/
                    Adc_GroupResult[GroupIndex].GroupLoadChnNum = \
                            Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
                }
            }
            else
            {
                /*Read another group,check the group need to add to queue or not*/
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();
                if (Adc_GroupResult[GroupIndex].GroupStatus != ADC_IDLE)
                {
                    Adc_InjectSwGroupToQueue(AdcHwIndex, Group);
                }
                else
                {
                    /*nothing to do*/
                }
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
            }
        }
        else
#endif
        {
#ifdef ADC_USER_MODE_SUPPORTED
            OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
#else
            Adc_Lld_StopConversion(AdcHwIndex);
#endif
            /*updata the queue and restart convert*/
            if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_BUSY)
            {
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();
                Adc_HandleHwRunAgainInBusy(Group, AdcHwIndex, GroupIndex);
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
            }
            else if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_IDLE)
            {
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();
                Adc_HwHandleInIdle(AdcHwIndex, GroupIndex);
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
            }
            else
            {
                /*nothing to do*/
            }
            /*check the queue wether has group to convert*/
            if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u)
            {
                uint16 AdcReadLoadGroupIndex;
                AdcReadLoadGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
                if (Adc_GroupResult[AdcReadLoadGroupIndex].GroupStatus != ADC_STREAM_COMPLETED)
                {
#ifdef ADC_USER_MODE_SUPPORTED
                    OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                    Adc_Lld_StartConversion(AdcHwIndex);
#endif
                }
            }
        }
    }
    else
    {
        /*updata the queue and restart convert, when no group in queue*/
        if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_BUSY)
        {
#if (ADC_HW_TRIGGER_API == STD_ON)
            if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW)
            {
                Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup = Group;
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
                OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
                Adc_Lld_StartConversion(AdcHwIndex);
#endif
            }
            else
#endif /*(ADC_HW_TRIGGER_API == STD_ON)*/
            {
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 1u;
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[0] = Group;
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
                OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
                Adc_Lld_StartConversion(AdcHwIndex);
#endif
            }
        }
    }
}

#if (ADC_LOW_POWER_STATES_SUPPORT==STD_ON)
/**
 * @brief This function validates the state and pointer of the ADC driver for power state manegement APIs.
 * @param[in] ServiceId Service ID of the API
 * @param[out] Adc_PowerStateRequestResultType Power state request result pointer
 * @return Std_ReturnType
 */
ADC_FUNC static Std_ReturnType Adc_ValidateStateAndPtr(uint8 ServiceId,
        Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    if (NULL_PTR == Result)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ServiceId, ADC_E_PARAM_POINTER);
#else
        (void)ServiceId;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (FALSE == Adc_IsDriverInit)
    {
        /* Adc module is not initialized */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* SWS_Adc_00496, SWS_Adc_00493, SWS_Adc_00491, SWS_Adc_00486 */
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ServiceId, ADC_E_UNINIT);
#else
        (void)ServiceId;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        *Result = ADC_NOT_INIT;
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*Nothing to do*/
    }
    return RetVal;
}

/**
 * @brief This function validates the power state support
 * @param[in] ServiceId Service ID of the API
 * @param[in] PowerState The power state to be checked
 * @param[out] Adc_PowerStateRequestResultType Power state request result pointer
 * @return Std_ReturnType
 */
ADC_FUNC static Std_ReturnType Adc_ValidatePowerStateSupport(uint8 ServiceId,
        Adc_PowerStateType PowerState,
        Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    /* If the power state is not supported or low power state is not supported at all */
    if (PowerState >= ADC_NODEFINE_POWER)
    {
        /* The state is not supported */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ServiceId, ADC_E_POWER_STATE_NOT_SUPPORTED);
#else
        (void)ServiceId;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        *Result = ADC_POWER_STATE_NOT_SUPP;
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}

/**
* @brief        This function validates the state of the adc unit.
* @param[in]    Unit          The Logical Unit Id
* @param[in]    ServiceId     Service ID of the API
*
* @return     Std_ReturnType  Standard return type.
*               E_OK:           The call means that unit is not busy
*               E_NOT_OK:       The call means that unit is busy
*/
ADC_FUNC static Std_ReturnType Adc_ValidateNotBusyNoQueue(uint8 Unit,
        uint8 ServiceId)
{
    Std_ReturnType ErrorFound = (Std_ReturnType)E_OK;
#if (ADC_HW_TRIGGER_API == STD_ON)
    Adc_GroupType OngoingHwGroupId;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    const Adc_QueueIndexType NoGroupsInSwNormalQueue = Adc_HwStatus[Unit].SwNormalQueueIndex;
#if (ADC_HW_TRIGGER_API == STD_ON)
    OngoingHwGroupId = Adc_HwStatus[Unit].HwOngoingHwGroup;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    /* Check for ongoing conversions */
    if ((NoGroupsInSwNormalQueue > (Adc_QueueIndexType)0U)
#if (ADC_HW_TRIGGER_API == STD_ON)
            || (OngoingHwGroupId != ADC_INVALID_GROUP_INDEX)
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
       )
    {
        /* SWS_Adc_00321, SWS_Adc_00346, SWS_Adc_00426 */
        (void)Det_ReportRuntimeError(ADC_MODULE_ID, ADC_INSTANCE_ID, ServiceId, (uint8)ADC_E_BUSY);
        ErrorFound = (Std_ReturnType)E_NOT_OK;
    }
    return ErrorFound;
}
/**
 * @brief This function validates the ADC state to be idle.
 * @param[in] ServiceId ID of the service to be validated
 * @param[out] Adc_PowerStateRequestResultType Power state request result pointer
 * @return Std_ReturnType E_OK if the ADC is idle, E_NOT_OK otherwise
 */
ADC_FUNC static Std_ReturnType Adc_ValidateIdleState(uint8 ServiceId,
        Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    for (uint8 LogicalHwUnitId = 0U; LogicalHwUnitId < ADC_MAX_HW_UNITS; ++LogicalHwUnitId)
    {
        if ((Std_ReturnType)E_NOT_OK == Adc_ValidateNotBusyNoQueue(LogicalHwUnitId, ServiceId))
        {
            /* Adc conversion is ongoing */
            /* SWS_Adc_00487 */
            (void)Det_ReportRuntimeError(ADC_MODULE_ID, ADC_INSTANCE_ID, ServiceId, ADC_E_NOT_DISENGAGED);
            *Result = ADC_SEQUENCE_ERROR;
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
    return RetVal;
}
/**
 * @brief This function validates the pointer of the power state parameter.
 * @param[in] ServiceId ID of the service to be validated
 * @param[out] Adc_PowerStateType Power state request result pointer
 * @return Std_ReturnType E_OK if the pointer is valid, E_NOT_OK otherwise
 */
ADC_FUNC static Std_ReturnType Adc_ValidStatePtr(uint8 ServiceId, Adc_PowerStateType const *StatePtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    if (NULL_PTR == StatePtr)
    {
#if (ADC_DEV_ERROR_DETECT==STD_ON)
        (void)Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ServiceId, ADC_E_PARAM_POINTER);
#endif /* (ADC_DEV_ERROR_DETECT==STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}
#endif /*(ADC_LOW_POWER_STATES_SUPPORT==STD_ON)*/
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (ADC_DE_INIT_API == STD_ON)
ADC_FUNC void Adc_DeInit(void)
{
    uint8 InterLoopCount;
    /* SWS_Adc_00154 */
    /* SWS_Adc_00358 */
    if (FALSE == Adc_IsDriverInit)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_DE_INIT, ADC_E_UNINIT);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        /* SWS_Adc_00112 */
        boolean GroupOnGoingFlag = FALSE;
        for (InterLoopCount = 0; InterLoopCount < Adc_ConfigPtr->GroupCfgNum; ++InterLoopCount)
        {
            if ((Adc_GroupResult[InterLoopCount].GroupStatus != ADC_IDLE) && (Adc_GroupResult[InterLoopCount].GroupStatus != ADC_STREAM_COMPLETED))
            {
                GroupOnGoingFlag = TRUE;
                break;
            }
        }
        if (TRUE == GroupOnGoingFlag)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_DE_INIT, ADC_E_BUSY);
        }
        else
        {
            /* SWS_Adc_00111 */
            for (InterLoopCount = 0; InterLoopCount < Adc_ConfigPtr->HwUnitCfgNum; ++InterLoopCount)
            {
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_DeinitHwUnit, Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
#else
                Adc_Lld_DeinitHwUnit(Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
#endif
#if ((STD_ON==ADC_ENABLE_QUEUING)||(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
                /*reset queue index*/
                Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].SwNormalQueueIndex = 0;
                for (uint8 InterCycleCount = 0; InterCycleCount < ADC_QUEUE_MAX_DEPTH_MAX; ++InterCycleCount)
                {
                    Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].SwNormalQueue[InterCycleCount] = ADC_INVALID_HW_INDEX;
                }
#endif /*(STD_ON==ADC_ENABLE_QUEUING)*/
#if (STD_ON==ADC_HW_TRIGGER_API)
                Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].HwOngoingHwGroup = ADC_INVALID_GROUP_INDEX;
#endif /*(STD_ON==ADC_HW_TRIGGER_API)*/
            }
#if(ADC_FIXED_PB_CONFIG == STD_ON)
            for (InterLoopCount = 0; InterLoopCount < Adc_ConfigPtr->GroupCfgNum; InterLoopCount++)
#else
            for (InterLoopCount = 0; InterLoopCount < ADC_MAX_GROUPS; ++InterLoopCount)
#endif /*(ADC_FIXED_PB_CONFIG == STD_ON)*/
            {
                Adc_GroupResult[InterLoopCount].GroupStatus = ADC_IDLE;
                Adc_GroupResult[InterLoopCount].GroupSampleCount = 0u;
                Adc_GroupResult[InterLoopCount].GroupValueBuf = NULL_PTR;
                Adc_GroupResult[InterLoopCount].NotificationEnFlag = ADC_NOTIFICATION_DISABLED;
                Adc_GroupResult[InterLoopCount].ResultBufInitSt = FALSE;
            }
            /* SWS_Adc_00110 */
            Adc_IsDriverInit = FALSE;
            Adc_ConfigPtr = NULL_PTR;
        }
    }
}
#endif

/* SWS_Adc_00101 */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
ADC_FUNC void Adc_DisableGroupNotification(Adc_GroupType Group)
{
    Std_ReturnType TempRet = E_OK;
    uint16 GroupIndex = 0u;
    /* SWS_Adc_00300 */
    if (FALSE == Adc_IsDriverInit)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_DISABLE_GROUP_NOTIFICATION, ADC_E_UNINIT);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
        TempRet = E_NOT_OK;
    }
    else
    {
        /* SWS_Adc_00131 */
        if (E_NOT_OK == Adc_ValidGroupCheck(Group))
        {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_DISABLE_GROUP_NOTIFICATION, ADC_E_PARAM_GROUP);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempRet = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    GroupIndex = Adc_Lld_GroupIndexCheck(Group);
    if (E_OK == TempRet)
    {
        /*SWS_Adc_166*/
        const Adc_GroupSampleType *ChannelGroupPtr = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample;
        if (NULL_PTR == ChannelGroupPtr->NotificationFunc)
        {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_DISABLE_GROUP_NOTIFICATION, ADC_E_NOTIF_CAPABILITY);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempRet = E_NOT_OK;
        }
    }
    else
    {
        /*nothing to do*/
    }
    if (E_OK == TempRet)
    {
        /* SWS_Adc_00058 */
        /* disable notification status and register*/
        Adc_GroupResult[GroupIndex].NotificationEnFlag = ADC_NOTIFICATION_DISABLED;
    }
    else
    {
        /*nothing to do*/
    }
}
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
ADC_FUNC void Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
    if (E_OK == Adc_HwTriggerDevErrorCheck(Group, ADC_SID_DISABLE_HARDWARE_TRIGGER))
    {
        uint16 GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        uint8 AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
        /*[SWS_Adc_00304] The Group is not running ,report ADC_E_IDLE*/
        if (ADC_IDLE == Adc_GroupResult[GroupIndex].GroupStatus)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_DISABLE_HARDWARE_TRIGGER, ADC_E_IDLE);
        }
        else
        {
            /*stop hw trigger group*/
#ifdef ADC_USER_MODE_SUPPORTED
            OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
            OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
#else
            Adc_Lld_StopConversion(AdcHwIndex);
            Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
#endif
            /*reset the group to idle and complete times reset to 0*/
            Adc_GroupResult[GroupIndex].GroupStatus = ADC_IDLE;
            Adc_GroupResult[GroupIndex].GroupSampleCount = 0u;
            Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0u;
            /*If the group need to disable is running in hardware, clear the HwOngoingHwGroup and reload a sw group to hardware*/
            if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup == Group)
            {
                Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup = ADC_INVALID_GROUP_INDEX;
                /*reload the sw group and restart the group*/
                if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u)
                {
                    uint16 TempOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
                    if (Adc_GroupResult[TempOnGoGroupIndex].GroupStatus != ADC_STREAM_COMPLETED)
                    {
#ifdef ADC_USER_MODE_SUPPORTED
                        OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, TempOnGoGroupIndex);
                        OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                        Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, TempOnGoGroupIndex);
                        Adc_Lld_StartConversion(AdcHwIndex);
#endif
                    }
                    else
                    {
                        /*nothing to do*/
                    }
                }
                else
                {
                    /*nothing to do*/
                }
            }
        }
    }
}
#endif


#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
ADC_FUNC void Adc_EnableGroupNotification(Adc_GroupType Group)
{
    Std_ReturnType TempRet = E_OK;
    uint16 GroupIndex = 0;
    /* SWS_Adc_00299 */
    if (FALSE == Adc_IsDriverInit)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_ENABLE_GROUP_NOTIFICATION, ADC_E_UNINIT);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
        TempRet = E_NOT_OK;
    }
    else
    {
        /* SWS_Adc_00130 */
        if (E_NOT_OK == Adc_ValidGroupCheck(Group))
        {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_ENABLE_GROUP_NOTIFICATION, ADC_E_PARAM_GROUP);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempRet = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    GroupIndex = Adc_Lld_GroupIndexCheck(Group);
    if (E_OK == TempRet)
    {
        /*SWS_Adc_165*/
        const Adc_GroupSampleType *ChannelGroupPtr = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample;
        if (NULL_PTR == ChannelGroupPtr->NotificationFunc)
        {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_ENABLE_GROUP_NOTIFICATION, ADC_E_NOTIF_CAPABILITY);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempRet = E_NOT_OK;
        }
    }
    if (E_OK == TempRet)
    {
        /* SWS_Adc_00057 */
        /* enable notification status and register*/
        Adc_GroupResult[GroupIndex].NotificationEnFlag = ADC_NOTIFICATION_ENABLED;
    }
    else
    {
        /*nothing to do*/
    }
}
#endif


#if (ADC_HW_TRIGGER_API == STD_ON)
ADC_FUNC void Adc_EnableHardwareTrigger(Adc_GroupType Group)
{
    if (E_OK == Adc_HwTriggerDevErrorCheck(Group, ADC_SID_ENABLE_HARDWARE_TRIGGER))
    {
        uint16 GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        uint8 AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
        /*need schm protect for the function Reentrant*/
        /*[SWS_Adc_00349] Check the group is busy or not */
        if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_BUSY)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_ENABLE_HARDWARE_TRIGGER, ADC_E_BUSY);
        }
#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING == STD_ON))
        /*[SWS_Adc_00353] When a hardware trigger group is running on the hardware unit, report ADC_E_BUSY*/
        else if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_INVALID_GROUP_INDEX)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_ENABLE_HARDWARE_TRIGGER, ADC_E_BUSY);
        }
#else
        /*[SWS_Adc_00321] The priority and queue is disable, when the Adc hard unit is busy, report ADC_E_BUSY*/
        else if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex != 0u) || (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_INVALID_GROUP_INDEX))
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_ENABLE_HARDWARE_TRIGGER, ADC_E_BUSY);
        }
#endif
        else
        {
            uint16 TempOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
            /*ADC has complete the sequence conversion, read data to buffer and  update group status*/
            if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u) && \
                    (ADC_INTCANDDMA_DISABLED == Adc_ConfigPtr->GroupUserCfg[TempOnGoGroupIndex].GroupSample->IntcAndDmaCfg))
            {
#ifdef ADC_USER_MODE_SUPPORTED
                if (OsIf_Trusted_Call_Return1param(Adc_Lld_ReadSeqConvEndIntFlag, AdcHwIndex) == TRUE)
#else
                if (Adc_Lld_ReadSeqConvEndIntFlag(AdcHwIndex) == TRUE)
#endif
                {
                    Adc_UpdateStatusReadGroupNoInt(Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]));
                    (void)Adc_Lld_QueueDataUpdata(AdcHwIndex, Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]));
                }
            }
            /* Set the hardware Group state machine*/
#ifdef ADC_USER_MODE_SUPPORTED
            OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
            OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
#else
            Adc_Lld_StopConversion(AdcHwIndex);
            Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
#endif
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00();
            /*delete the sw group data for the group not complteted*/
            if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u))
            {
                Adc_GroupResult[TempOnGoGroupIndex].GroupCompChnNum = 0u;
                Adc_GroupResult[TempOnGoGroupIndex].GroupLoadChnNum = 0u;
            }
            Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
            Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup = Group;
#ifdef ADC_USER_MODE_SUPPORTED
            OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
            OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
            Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
            Adc_Lld_StartConversion(AdcHwIndex);
#endif
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();
        }
    }
}
#endif

ADC_FUNC Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
{
    Std_ReturnType TempRet = E_OK;
    Adc_StatusType TempGroupStatus = ADC_IDLE;
    /* SWS_Adc_00301 */
    TempRet = Adc_InitAndGroupValidErrCheck(ADC_INSTANCE_ID, ADC_SID_GET_GROUP_STATUS, Group);
    if (E_OK == TempRet)
    {
        uint16 GroupIndex = 0u;
        uint8 AdcHwIndex = 0u;
        GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
        /**the Group is conversion ongoing, INTC and DMA is closed,this function need to
         * check the ADC down flag to change the status of the Group*/
        Adc_UpdataStatusInReadApi(AdcHwIndex);
        TempGroupStatus = Adc_GroupResult[GroupIndex].GroupStatus;
    }
    else
    {
        /*nothing to do*/
    }
    return TempGroupStatus;
}

ADC_FUNC Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType **PtrToSamplePtr)
{
    Std_ReturnType TempRet = E_OK;
    Adc_StreamNumSampleType ResultNum  = 0u;
    uint16 GroupIndex = 0u;
    /* SWS_Adc_00302 */
    /* SWS_Adc_00218 */
    TempRet = Adc_InitAndGroupValidErrCheck(ADC_INSTANCE_ID, ADC_SID_GET_STREAM_LAST_POINTER, Group);
    if (E_OK == TempRet)
    {
        GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        /* SWS_Adc_00215 */
        if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_IDLE)
        {
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_GET_STREAM_LAST_POINTER, ADC_E_IDLE);
            *PtrToSamplePtr = NULL_PTR;
            TempRet = E_NOT_OK;
        }
    }
    else
    {
        *PtrToSamplePtr = NULL_PTR;
    }
    if (E_OK == TempRet)
    {
        uint8 AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
        *PtrToSamplePtr = (Adc_ValueGroupType *)NULL_PTR;
        /*updata status and result when INTC and DMA both disabled*/
        Adc_UpdataStatusInReadApi(AdcHwIndex);
        /* SWS_Adc_00387, SWS_Adc_00216*/
        if ((Adc_GroupResult[GroupIndex].GroupStatus == ADC_COMPLETED) || \
                (Adc_GroupResult[GroupIndex].GroupStatus == ADC_STREAM_COMPLETED))
        {
            /* SWS_Adc_00387 */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01();
            ResultNum = Adc_SwStateAndRdRstInGetStream(GroupIndex, PtrToSamplePtr);
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01();
            /*stop adc to sure there is no intc when read and updata queue in read*/
            Adc_HandleHwReloadAfterRead(AdcHwIndex, Group, GroupIndex);
        }
        else
        {
            *PtrToSamplePtr = (Adc_ValueGroupType *)NULL_PTR;
            ResultNum = 0;
        }
    }
    else
    {
        /*nothing to do*/
    }
    return ResultNum;
}

ADC_FUNC void Adc_Init(const Adc_ConfigType *ConfigPtr)
{
    /* the adc_init main functions
    * Fun1:init clock source (element in Adc_HwUnitType)
    * Fun2:init prescale (element in Adc_HwUnitType)
    * Fun3:init all configurated Hw Units (element in Adc_HwUnitType)
    * Fun4:stop all configurated Hw Units if already run
    * Fun5:disable nitification(interrupt) and hardware trigger default
    * Fun6:init HW status data
    * Fun7:init all resutl data bufs
    */
    Std_ReturnType TempRet = E_OK;
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Adc_IsDriverInit)
    {
        /* SWS_Adc_00107 */
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_INIT, ADC_E_ALREADY_INITIALIZED);
    }
    else
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
#if (STD_ON==ADC_FIXED_PB_CONFIG)
        if (ConfigPtr != NULL_PTR)
        {
            /* SWS_Adc_00343 */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_INIT, ADC_E_PARAM_CONFIG);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempRet = E_NOT_OK;
        }
        else
        {
            /* SWS_Adc_00343 */
            Adc_ConfigPtr = &Adc_PreCompileConfig;
        }
#else
        if (NULL_PTR == ConfigPtr)
        {
            /* SWS_Adc_00343 */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_INIT, ADC_E_PARAM_CONFIG);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempRet = E_NOT_OK;
        }
        else
        {
            Adc_ConfigPtr = ConfigPtr;
        }
#endif
        /* SWS_Adc_00054 */
        /* SWS_Adc_00342 */
        /* SWS_Adc_00056 */
        /* SWS_Adc_00246 */
        /* SWS_Adc_00247 */
        /* SWS_Adc_00248 */
        /* SWS_Adc_00249 */
        /* SWS_Adc_00250 */
        /* SWS_Adc_00077 */
        if (E_OK == TempRet)
        {
            /* Fun3:init all configurated Hw Units (element in Adc_HwUnitType) */
            uint8 InterLoopCount;
            for (InterLoopCount = 0; InterLoopCount < Adc_ConfigPtr->HwUnitCfgNum; ++InterLoopCount)
            {
#ifdef ADC_USER_MODE_SUPPORTED
                /*set the prescaler and startup time for ADC HW Unit*/
                OsIf_Trusted_Call1param(Adc_Lld_HwClockInit, &(Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount]));
                /* Fun4:stop all configurated Hw Units if already run */
                OsIf_Trusted_Call1param(Adc_Lld_StopConversion, Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
                /* Fun5:disable nitification(interrupt) and hardware trigger default */
                OsIf_Trusted_Call1param(Adc_Lld_DisableIntcandHwTrigger, Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
#else
                /*set the prescaler and startup time for ADC HW Unit*/
                Adc_Lld_HwClockInit(&(Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount]));
                /* Fun4:stop all configurated Hw Units if already run */
                Adc_Lld_StopConversion(Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
                /* Fun5:disable nitification(interrupt) and hardware trigger default */
                Adc_Lld_DisableIntcandHwTrigger(Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
#endif
                /*Fun6:init HW status data*/
                /*reset queue index*/
                Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].SwNormalQueueIndex = 0;
                /*Func8:init the Hw unit group queue[0] to 0xFFFF,the GROUP ID 0xFFFF as a no use ID in APP*/
#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(STD_ON==ADC_ENABLE_QUEUING))
                for (uint8 InterCycleCount = 0; InterCycleCount < ADC_QUEUE_MAX_DEPTH_MAX; ++InterCycleCount)
                {
                    Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].SwNormalQueue[InterCycleCount] = ADC_INVALID_GROUP_INDEX;
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
                    Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].SwNormalQueuePriority[InterLoopCount] = 0;
#endif /*(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)*/
                }
#else
                Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].SwNormalQueue[0] = ADC_INVALID_GROUP_INDEX;
#endif
#if (STD_ON==ADC_HW_TRIGGER_API)
                Adc_HwStatus[Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId].HwOngoingHwGroup = ADC_INVALID_GROUP_INDEX;
#endif /*(STD_ON==ADC_HW_TRIGGER_API)*/
                if (ADC_0 == Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId)
                {
#ifdef ADC_USER_MODE_SUPPORTED
                    OsIf_Trusted_Call1param(Adc_Lld_InitTempSensor, Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].InternalTempSensor);
#else
                    Adc_Lld_InitTempSensor(Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].InternalTempSensor);
#endif
                }
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_HwUnitEnable, Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
#else
                Adc_Lld_HwUnitEnable(Adc_ConfigPtr->HwUnitUserCfg[InterLoopCount].HwUnitId);
#endif
            }
#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
#if (ADC_LOW_POWER_STATE_ENABLE_WHEN_INIT == STD_ON)
#ifdef ADC_USER_MODE_SUPPORTED
            (void)OsIf_Trusted_Call1param(Adc_Lld_SetPowerState, ADC_LOW_POWER);
#else
            (void)Adc_Lld_SetPowerState(ADC_LOW_POWER);
#endif
            Adc_CurrentState = ADC_LOW_POWER;
            Adc_TargetState = ADC_NODEFINE_POWER;
#else
#ifdef ADC_USER_MODE_SUPPORTED
            (void)OsIf_Trusted_Call1param(Adc_Lld_SetPowerState, ADC_FULL_POWER);
#else
            (void)Adc_Lld_SetPowerState(ADC_FULL_POWER);
#endif
            Adc_CurrentState = ADC_FULL_POWER;
            Adc_TargetState = ADC_NODEFINE_POWER;
#endif /*(ADC_LOW_POWER_STATE_ENABLE_WHEN_INIT == STD_ON)*/
#endif /* (ADC_LOW_POWER_STATES_SUPPORT == STD_ON) */
            Adc_IsDriverInit = TRUE;
            /* Fun7:init all resutl data bufs */
            for (InterLoopCount = 0; InterLoopCount < Adc_ConfigPtr->GroupCfgNum; ++InterLoopCount)
            {
                /* SWS_Adc_00307 */
                Adc_GroupResult[InterLoopCount].GroupStatus = ADC_IDLE;
                Adc_GroupResult[InterLoopCount].ResultBufInitSt = FALSE;
                Adc_GroupResult[InterLoopCount].SampleFinished  = FALSE;
                Adc_GroupResult[InterLoopCount].GroupSampleCount = 0u;
#if (ADC_GRP_NOTIF_CAPABILITY==STD_ON)
                Adc_GroupResult[InterLoopCount].NotificationEnFlag = ADC_NOTIFICATION_DISABLED;
#endif /*(ADC_GRP_NOTIF_CAPABILITY==STD_ON)*/
            }
        }
    }
}


/* SWS_Adc_00359 */
#if (ADC_READ_GROUP_API == STD_ON)
ADC_FUNC Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr)
{
    Std_ReturnType TempReturn = E_OK;
    uint16 GroupIndex = 0;
    /* SWS_Adc_00296 */
    /* SWS_Adc_00152 */
    TempReturn = Adc_InitAndGroupValidErrCheck(ADC_INSTANCE_ID, ADC_SID_READ_GROUP, Group);
    GroupIndex = Adc_Lld_GroupIndexCheck(Group);
    if ((E_OK == TempReturn) && (ADC_IDLE == Adc_GroupResult[GroupIndex].GroupStatus))
    {
        /* SWS_Adc_00388 */
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_READ_GROUP, ADC_E_IDLE);
        TempReturn = E_NOT_OK;
    }
    if (E_OK == TempReturn)
    {
        uint8 AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
        /*updata status and result when INTC and DMA both disabled*/
        Adc_UpdataStatusInReadApi(AdcHwIndex);
        if ((Adc_GroupResult[GroupIndex].GroupStatus == ADC_COMPLETED) || \
                (Adc_GroupResult[GroupIndex].GroupStatus == ADC_STREAM_COMPLETED))
        {
            /* SWS_Adc_00329 */
            /* SWS_Adc_00330 */
            /* SWS_Adc_00075 */
            /*group status update*/
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02();
            Adc_SwStateAndRdRstInReadApi(GroupIndex, DataBufferPtr);
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02();
            /*stop adc to sure there is no intc when read and updata queue in read*/
            Adc_HandleHwReloadAfterRead(AdcHwIndex, Group, GroupIndex);
        }
        else if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_BUSY)
        {
            TempReturn = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    else
    {
        /*nothing to do*/
    }
    return TempReturn;
}
#endif


ADC_FUNC Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr)
{
    Std_ReturnType TempReturn = E_OK;
    /* SWS_Adc_00434 */
    if (FALSE == Adc_IsDriverInit)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_SETUP_RESULT_BUFFER, ADC_E_UNINIT);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
        TempReturn = E_NOT_OK;
    }
    else
    {
        /* SWS_Adc_00457 */
        if (NULL_PTR == DataBufferPtr)
        {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_SETUP_RESULT_BUFFER, ADC_E_PARAM_POINTER);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = E_NOT_OK;
        }
        else
        {
            /* SWS_Adc_00423 */
            if (E_NOT_OK == Adc_ValidGroupCheck(Group))
            {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_SETUP_RESULT_BUFFER, ADC_E_PARAM_GROUP);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
                TempReturn = E_NOT_OK;
            }
            else
            {
                /*nothing to do*/
            }
        }
    }
    if (E_OK == TempReturn)
    {
        uint16 GroupIndex = 0u;
        GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        /* SWS_Adc_00433 */
        if (Adc_GroupResult[GroupIndex].GroupStatus != ADC_IDLE)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_SETUP_RESULT_BUFFER, ADC_E_BUSY);
            TempReturn = E_NOT_OK;
        }
        else
        {
            /* SWC_Adc_00420 */
            Adc_GroupResult[GroupIndex].GroupValueBuf = DataBufferPtr;
            Adc_GroupResult[GroupIndex].ResultBufInitSt = TRUE;
            Adc_GroupResult[GroupIndex].GroupSampleCount = 0u;
            Adc_GroupResult[GroupIndex].SampleFinished = FALSE;
        }
    }
    else
    {
        /*nothing to do*/
    }
    return TempReturn;
}


/* SWS_Adc_00259 */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
ADC_FUNC void Adc_StartGroupConversion(Adc_GroupType Group)
{
    Std_ReturnType TempReturn = E_OK;
    uint16 GroupIndex = 0u;
    uint8 AdcHwIndex = 0u;
    /* SWS_Adc_00294 */
    TempReturn = Adc_InitAndGroupValidErrCheck(ADC_INSTANCE_ID, ADC_SID_START_GROUP_CONVERSION, Group);
    if (E_OK == TempReturn)
    {
        GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        if (ADC_TRIGG_SRC_HW == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc)
        {
            /*SWS_Adc_00133*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_START_GROUP_CONVERSION, ADC_E_WRONG_TRIGG_SRC);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = E_NOT_OK;
        }
        else if (FALSE == Adc_GroupResult[GroupIndex].ResultBufInitSt)
        {
            /*SWS_Adc_00424,SWS_Adc_00421*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_START_GROUP_CONVERSION, ADC_E_BUFFER_UNINIT);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    else
    {
        /*nothing to do*/
    }
    if (E_OK == TempReturn)
    {
        AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
#if ((ADC_PRIORITY_IMPLEMENTATION !=ADC_PRIORITY_NONE)||(STD_ON==ADC_ENABLE_QUEUING))
        /*SWS_Adc_00351,SWS_Adc_00428*/
        /*the Group is in queue or conversion is ongoing,or the Queue is full ,report running error*/
        if (((Adc_GroupResult[GroupIndex].GroupStatus != ADC_IDLE) && \
                (Adc_GroupResult[GroupIndex].GroupStatus != ADC_STREAM_COMPLETED)) || \
                (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= ADC_QUEUE_MAX_DEPTH_MAX))
#else
        /*SWS_Adc_00346,SWS_Adc_00426*/
        if ((E_OK == Adc_GroupStatusCheck(ADC_BUSY)) && \
                (E_OK == Adc_GroupStatusCheck(ADC_COMPLETED)))
#endif
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_START_GROUP_CONVERSION, ADC_E_BUSY);
            TempReturn = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    if (E_OK == TempReturn)
    {
        Adc_GroupResult[GroupIndex].GroupSampleCount = 0u;
        Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
        Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0u;
#if (ADC_HW_TRIGGER_API == STD_ON)
        if (ADC_INVALID_GROUP_INDEX == Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup)
        {
#endif
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();
#if ((ADC_PRIORITY_IMPLEMENTATION !=ADC_PRIORITY_NONE)||(STD_ON==ADC_ENABLE_QUEUING))
            uint8 PrioIndex = ADC_INVALID_HW_INDEX;
            if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u) && (Group != Adc_HwStatus[AdcHwIndex].SwNormalQueue[0u]))
            {
                /*stop adc to sure the queue is atomic operation*/
#if (ADC_PRIORITY_IMPLEMENTATION !=ADC_PRIORITY_NONE)
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
#else
                Adc_Lld_StopConversion(AdcHwIndex);
#endif /*ADC_USER_MODE_SUPPORTED*/
                PrioIndex = Adc_PriorityIndexCheck(AdcHwIndex, GroupIndex);
                Adc_InjectGroupToQueue(AdcHwIndex, GroupIndex, PrioIndex);
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex += 1u;
                /* SWS_Adc_00222-3 */
                Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
                if (PrioIndex == 0u)
                {
                    /*Adc_Lld_ClearFIFOInvalidData(AdcHwIndex);*/
                    Adc_GroupResult[Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[1u])].GroupSampleCount = 0u;
#ifdef ADC_USER_MODE_SUPPORTED
                    OsIf_Trusted_Call1param(Adc_Lld_ClearSeqConvEndIntFlag, AdcHwIndex);
                    OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
#else
                    Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
                    Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
#endif /*ADC_USER_MODE_SUPPORTED*/
                }
                else
                {
                    /*nothing to do*/
                }
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                Adc_Lld_StartConversion(AdcHwIndex);
#endif /*ADC_USER_MODE_SUPPORTED*/
#else
                PrioIndex = (uint8)(Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex);
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[PrioIndex] = Group;
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex += 1u;
                /* SWS_Adc_00222-3 */
                Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
#endif /*ADC_PRIORITY_IMPLEMENTATION */
            }
            else
#endif /*((ADC_PRIORITY_IMPLEMENTATION !=ADC_PRIORITY_NONE)||(STD_ON==ADC_ENABLE_QUEUING)) */
                /*No group in queue*/
            {
                /*SWS_Adc_00348*/
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[0u] = Group;
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 1u;
                /* SWS_Adc_00222-3 */
                Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
#if (ADC_PRIORITY_IMPLEMENTATION !=ADC_PRIORITY_NONE)
                Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[0u] = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupPriority;
#endif
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
                /*SWS_Adc_00146,SWS_Adc_00133*/
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call2params(Adc_Lld_LoadGroupToHwUnit, AdcHwIndex, GroupIndex);
                OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
                Adc_Lld_StartConversion(AdcHwIndex);
#endif
            }
#if (ADC_HW_TRIGGER_API == STD_ON)
        }
        else
        {
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();
            Adc_InjectSwGroupToQueue(AdcHwIndex, Group);
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
            Adc_GroupResult[GroupIndex].GroupStatus = ADC_BUSY;
        }
#endif /*(ADC_HW_TRIGGER_API == STD_ON)*/
    }
    else
    {
        /*nothing to do*/
    }
}
#endif


/* SWS_Adc_00260 */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
ADC_FUNC void Adc_StopGroupConversion(Adc_GroupType Group)
{
    Std_ReturnType TempReturn = E_OK;
    uint16 GroupIndex = 0u;
    uint8 AdcHwIndex = 0u;
    TempReturn = Adc_InitAndGroupValidErrCheck(ADC_INSTANCE_ID, ADC_SID_STOP_GROUP_CONVERSION, Group);
    if (E_OK == TempReturn)
    {
        GroupIndex = Adc_Lld_GroupIndexCheck(Group);
        if (ADC_TRIGG_SRC_HW == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc)
        {
            /*SWS_Adc_00133*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_STOP_GROUP_CONVERSION, ADC_E_WRONG_TRIGG_SRC);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = E_NOT_OK;
        }
        else if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_IDLE)
        {
            /* SWS_Adc_00241 */
            (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SID_STOP_GROUP_CONVERSION, ADC_E_IDLE);
            TempReturn = E_NOT_OK;
        }
        else
        {
            /*nothing to do*/
        }
    }
    else
    {
        /*nothing to do*/
    }
    if (E_OK == TempReturn)
    {
        AdcHwIndex = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupInHwUnitId;
#if (ADC_HW_TRIGGER_API == STD_ON)
        if (ADC_INVALID_GROUP_INDEX == Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup)
        {
#endif /*(ADC_HW_TRIGGER_API == STD_ON)*/
            /*group conversion is ongoing ,stop it firstly*/
            if (Group == Adc_HwStatus[AdcHwIndex].SwNormalQueue[0u])
            {
                /*SWS_Adc_00242*/
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
#else
                Adc_Lld_StopConversion(AdcHwIndex);
#endif
            }
            else
            {
                /*nothing to do*/
            }
#if ((ADC_ENABLE_QUEUING == STD_ON)||(ADC_PRIORITY_IMPLEMENTATION!=ADC_PRIORITY_NONE))
            uint8 QueueIndex = 0u;
            /* SWS_Adc_00437 */
            /* SWS_Adc_00438 */
            /**when queue or priority is enable , if group is onging,disable the ADC and
            *load the next group in the queue to ADC HW;or the group in queue waiting for
            *conversion,delet the group in queue*/
            if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 1u)
            {
                QueueIndex = Adc_CheckGroupQueueIndex(GroupIndex);
                if (0U == QueueIndex)
                {
                    /*the group is ongoing ,load next group to ADC HW and start conversion*/
                    Adc_GroupsInQueueUpdate(AdcHwIndex);
                }
                else if (QueueIndex == (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex - 1u))
                {
                    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
                    Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex - 1u] = ADC_INVALID_GROUP_INDEX;
#if (ADC_PRIORITY_IMPLEMENTATION!=ADC_PRIORITY_NONE)
                    Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex - 1u] = 0u;
#endif
                    Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
                    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
                }
                else if (ADC_INVALID_HW_INDEX == QueueIndex)
                {
                    /*The group not in queue,nothing to do*/
                }
                else
                {
                    /*sure the atomic operation*/
#ifdef ADC_USER_MODE_SUPPORTED
                    OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
#else
                    Adc_Lld_StopConversion(AdcHwIndex);
#endif
                    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
                    /*the group is waiting for conversion ,remove group ID from the queue*/
                    Adc_LimitQueueIndex(AdcHwIndex);
                    Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
                    for (uint8 InterLoopCount = QueueIndex; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex; ++InterLoopCount)
                    {
                        Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1u]; /*NOSONAR,There are no memory overruns here*/
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
                        Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount] = \
                                Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount + 1u];
#endif /*(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)*/
                    }
                    Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = ADC_INVALID_GROUP_INDEX;
                    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
#ifdef ADC_USER_MODE_SUPPORTED
                    OsIf_Trusted_Call1param(Adc_Lld_StartConversion, AdcHwIndex);
#else
                    Adc_Lld_StartConversion(AdcHwIndex);
#endif
                }
            }
            else
            {
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
            }
#else
            /**when queue and priority disable, stop ADC HW unit and
            *disable notification.
            */
            if (Group == Adc_HwStatus[AdcHwIndex].SwNormalQueue[0u])
            {
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[0u] = ADC_INVALID_GROUP_INDEX;
            }
#endif/*((ADC_ENABLE_QUEUING == STD_ON)||(ADC_PRIORITY_IMPLEMENTATION!=ADC_PRIORITY_NONE))*/
            if (0u == Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex)
            {
                /* SWS_Adc_00385 */
                /* SWS_Adc_00386 */
#ifdef ADC_USER_MODE_SUPPORTED
                OsIf_Trusted_Call1param(Adc_Lld_StopConversion, AdcHwIndex);
#else
                Adc_Lld_StopConversion(AdcHwIndex);
#endif
            }
#if (ADC_HW_TRIGGER_API == STD_ON)
        }
        else
        {
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
#if ((ADC_ENABLE_QUEUING == STD_ON)||(ADC_PRIORITY_IMPLEMENTATION!=ADC_PRIORITY_NONE))
            uint8 QueueIndex = Adc_CheckGroupQueueIndex(GroupIndex);
            if (ADC_INVALID_HW_INDEX != QueueIndex)
            {
                /*the group is waiting for conversion ,remove group ID from the queue*/
                Adc_LimitQueueIndex(AdcHwIndex);
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
                for (uint8 InterLoopCount = QueueIndex; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex; ++InterLoopCount)
                {
                    Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1u]; /*NOSONAR,There are no memory overruns here*/
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
                    Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount] = \
                            Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount + 1u];
#endif /*(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)*/
                }
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = ADC_INVALID_GROUP_INDEX;
            }
#else
            Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
            Adc_HwStatus[AdcHwIndex].SwNormalQueue[0u] = ADC_INVALID_GROUP_INDEX;
#endif /*((ADC_ENABLE_QUEUING == STD_ON)||(ADC_PRIORITY_IMPLEMENTATION!=ADC_PRIORITY_NONE))*/
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
        }
#endif /*(ADC_HW_TRIGGER_API == STD_ON)*/
        /* SWS_Adc_00360 */
        /* SWS_Adc_00221-2 */
        Adc_GroupResult[GroupIndex].GroupStatus = ADC_IDLE;
        /*Clear result FIFO and flag */
        Adc_GroupResult[GroupIndex].SampleFinished = FALSE;
        Adc_GroupResult[GroupIndex].GroupSampleCount = ADC_INVALID_HW_INDEX;
        /* SWS_Adc_00155 */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        Adc_GroupResult[GroupIndex].NotificationEnFlag = ADC_NOTIFICATION_DISABLED;
#endif/*(ADC_GRP_NOTIF_CAPABILITY == STD_ON)*/
    }
    else
    {
        /*nothing to do*/
    }
}
#endif

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/* SWS_Adc_00475, SWS_Adc_00481 */
/** @implements      Adc_SetPowerState_Activity */
ADC_FUNC Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_SID_SET_POWER_STATE, Result))
    {
        if ((Std_ReturnType)E_OK == Adc_ValidatePowerStateSupport(ADC_SID_SET_POWER_STATE, Adc_TargetState, Result))
        {
            RetVal = Adc_ValidateIdleState(ADC_SID_SET_POWER_STATE, Result);
        }
    }
    if ((Std_ReturnType)E_OK == RetVal)
    {
#ifdef ADC_USER_MODE_SUPPORTED
        RetVal = OsIf_Trusted_Call1param(Adc_Lld_SetPowerState, Adc_TargetState);
#else
        RetVal = Adc_Lld_SetPowerState(Adc_TargetState);
#endif
        if ((Std_ReturnType)E_OK == RetVal)
        {
            /* SWS_Adc_00482 */
            /* Everything is ok */
            *Result = ADC_SERVICE_ACCEPTED;
            Adc_CurrentState = Adc_TargetState;
            Adc_TargetState = ADC_NODEFINE_POWER;
        }
        else
        {
            /* Hardware failure */
            *Result = ADC_HW_FAILURE;
        }
    }
    return RetVal;
}

/* SWS_Adc_00476 */
/** @implements      Adc_GetCurrentPowerState_Activity */
ADC_FUNC Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType *CurrentPowerState,
        Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_SID_GET_CURRENT_POWER_STATE, Result))
    {
        RetVal = Adc_ValidStatePtr(ADC_SID_GET_CURRENT_POWER_STATE, CurrentPowerState);
    }
    if ((Std_ReturnType)E_OK == RetVal)
    {
        *CurrentPowerState = Adc_CurrentState;
        *Result = ADC_SERVICE_ACCEPTED;
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}

/* SWS_Adc_00477 */
/** @implements      Adc_GetTargetPowerState_Activity */
ADC_FUNC Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType *TargetPowerState,
        Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_SID_GET_TARGET_POWER_STATE, Result))
    {
        RetVal = Adc_ValidStatePtr(ADC_SID_GET_TARGET_POWER_STATE, TargetPowerState);
    }
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* SWS_Adc_00492 */
        if (Adc_TargetState < ADC_NODEFINE_POWER)
        {
            /* A transition is ongoing */
            *TargetPowerState = Adc_TargetState;
        }
        else
        {
            /* No transition is ongoing */
            *TargetPowerState = Adc_CurrentState;
        }
        *Result = ADC_SERVICE_ACCEPTED;
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}

/* SWS_Adc_00478 */
/** @implements      Adc_PreparePowerState_Activity */
ADC_FUNC Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState,
        Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_SID_PREPARE_POWER_STATE, Result))
    {
        if ((Std_ReturnType)E_OK == Adc_ValidatePowerStateSupport(ADC_SID_PREPARE_POWER_STATE, PowerState, Result))
        {
            RetVal = (Std_ReturnType)E_OK;
            for (uint8 LogicalHwUnitId = 0U; LogicalHwUnitId < ADC_MAX_HW_UNITS; ++LogicalHwUnitId)
            {
                RetVal = Adc_ValidateNotBusyNoQueue(LogicalHwUnitId, ADC_SID_PREPARE_POWER_STATE);
                if ((Std_ReturnType)E_NOT_OK == RetVal)
                {
                    /* Break the loop to avoid overwriting RetVal */
                    break;
                }
            }
            if ((Std_ReturnType)E_NOT_OK == RetVal)
            {
                *Result = ADC_TRANS_NOT_POSSIBLE;
            }
            else
            {
                /* SWS_Adc_00495 */
                /* Everything is ok */
                Adc_TargetState = PowerState;
                *Result = ADC_SERVICE_ACCEPTED;
            }
        }
    }
    return RetVal;
}

#if (ADC_POWER_STATE_ASYNCH_TRANSITION_MODE == STD_ON)
ADC_FUNC void Adc_Main_PowerTransitionManager(void)
{
}
#endif /* (ADC_POWER_STATE_ASYNCH_TRANSITION_MODE == STD_ON) */
#endif /* (ADC_LOW_POWER_STATES_SUPPORT == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

