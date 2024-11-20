/**************************************************************************************************/
/**
 * @file      : Tim_Icu_Drv.c
 * @brief     : AUTOSAR Tim Icu hardware driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Tim_Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Tim_Icu_Drv.h"
#include "Device_Regs.h"
#include "SchM_Icu.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_ICU_DRV_C_VENDOR_ID                   0x00B3U
#define TIM_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_ICU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_ICU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_ICU_DRV_C_SW_MAJOR_VERSION            1U
#define TIM_ICU_DRV_C_SW_MINOR_VERSION            2U
#define TIM_ICU_DRV_C_SW_PATCH_VERSION            2U

#if (TIM_ICU_DRV_C_VENDOR_ID != TIM_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Tim_Icu_Drv.c and Tim_Icu_Drv.h have different"
#endif

#if ((TIM_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (TIM_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Tim_Icu_Drv.c and Tim_Icu_Drv.h are different"
#endif

#if ((TIM_ICU_DRV_C_AR_RELEASE_REVISION_VERSION != TIM_ICU_DRV_H_AR_RELEASE_REVISION_VERSION) || \
        (TIM_ICU_DRV_C_SW_PATCH_VERSION != TIM_ICU_DRV_H_SW_PATCH_VERSION))
    #error "AutoSar version of Tim_Icu_Drv.c and Tim_Icu_Drv.h are different"
#endif

#if ((TIM_ICU_DRV_C_SW_MAJOR_VERSION != TIM_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (TIM_ICU_DRV_C_SW_MINOR_VERSION != TIM_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Tim_Icu_Drv.c and Tim_Icu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((TIM_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||     \
         (TIM_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Icu_Drv.c and Device_Regs.h are different"
    #endif

    #if ((TIM_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_ICU_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (TIM_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_ICU_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Tim_Icu_Drv.c and SchM_Icu.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define TIM_ICU_DRV_PCR_COMB0_MASK                              (0x04U)
#define TIM_ICU_DRV_PCR_DECAPMODE_MASK                          (0x30U)
#define TIM_ICU_DRV_PCR_MASK                                    (0xFFU)
#define TIM_ICU_DRV_CHANNEL_STATE_IDLE                  (1U << 0U)
#define TIM_ICU_DRV_CHANNEL_STATE_RUNNING               (1U << 1U)

/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"


/**
 *  @brief TIM0, TIM1, TIM2 address array
 */
static Reg_Tim_BfType *const Tim_Icu_Drv_IcuRegBfPtr[TIM_ICU_DRV_INSTANCE_SUMCNT] = 
{
   (Reg_Tim_BfType *)TIM0_BASE_ADDR, 
   (Reg_Tim_BfType *)TIM1_BASE_ADDR, 
   (Reg_Tim_BfType *)TIM2_BASE_ADDR,
   (Reg_Tim_BfType *)TIM3_BASE_ADDR
};

/**
 *  @brief TIM0, TIM1, TIM2 address array
 */
static Reg_Tim_WType *const Tim_Icu_Drv_IcuRegWPtr[TIM_ICU_DRV_INSTANCE_SUMCNT] = 
{
   (Reg_Tim_WType *)TIM0_BASE_ADDR, 
   (Reg_Tim_WType *)TIM1_BASE_ADDR, 
   (Reg_Tim_WType *)TIM2_BASE_ADDR,
   (Reg_Tim_WType *)TIM3_BASE_ADDR
};

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

static Tim_Icu_Drv_ChannelStateType \
                        Tim_Icu_Drv_ChState[TIM_ICU_DRV_INSTANCE_SUMCNT][TIM_ICU_DRV_CHANNEL_SUMCNT];
static Tim_Icu_Drv_InstanceStateType Tim_Icu_Drv_InstState[TIM_ICU_DRV_INSTANCE_SUMCNT];

#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

LOCAL_INLINE void Tim_Icu_Drv_ClrLocalIntFlag(Tim_Icu_Drv_IdType InstId,
                                                 Tim_Icu_Drv_ChannelIdType Channel)
{
    Reg_Tim_WType * TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];

    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMWx->TIM_CMCn[Channel]&= (0x00DFUL);
    SchM_Exit_Icu_TimSetChannelModeCfg();
}

LOCAL_INLINE void Tim_Icu_Drv_CheckArguments(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif


#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TIM_ICU_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(TIM_ICU_DRV_CHANNEL_SUMCNT > (uint32)Channel);
#endif

#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

}

#if ((STD_ON == TIM_ICU_DRV_TIMESTAMP_API) || (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API) || \
                                                 (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API))
LOCAL_INLINE void Tim_Icu_Drv_StopLocalChannel(Tim_Icu_Drv_IdType InstId,
                                                             Tim_Icu_Drv_ChannelIdType Channel)
{
    Reg_Tim_WType * TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];

    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMWx->TIM_CMCn[Channel] = (uint32)((TIMWx->TIM_CMCn[Channel]&0x00FCUL)|0x20UL);
    SchM_Exit_Icu_TimSetChannelModeCfg();
}
#endif

#if ((STD_ON == TIM_ICU_DRV_EDGE_DETECT_API) || (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API))
LOCAL_INLINE void Tim_Icu_Drv_LocalNotifyEvent(Tim_Icu_Drv_IdType InstId, 
                                                         Tim_Icu_Drv_ChannelIdType Channel, 
                                                         boolean OvfFlag)
{
    const Tim_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];

    if(NULL_PTR != ChStatePtr->CallbackFun)
    {
        ChStatePtr->CallbackFun(ChStatePtr->CallbackParam, OvfFlag);
    }
    else
    {
        if ((TRUE == ChStatePtr->NotifyEnable) && (NULL_PTR != ChStatePtr->ChNotificationFun))
        {
            ChStatePtr->ChNotificationFun();
        }

        if ((TRUE == OvfFlag) && (NULL_PTR != ChStatePtr->ChOvfNotificationFun))
        {
            ChStatePtr->ChOvfNotificationFun();
        }
    }
}
#endif

#if ((STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API) || (STD_ON == TIM_ICU_DRV_TIMESTAMP_API))
LOCAL_INLINE void Tim_Icu_Drv_LocalOvfReport(Tim_Icu_Drv_IdType InstId, 
                                                      Tim_Icu_Drv_ChannelIdType Channel, 
                                                      boolean OvfFlag)
{
    const Tim_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    
    if(NULL_PTR != ChStatePtr->CallbackFun)
    {
        ChStatePtr->CallbackFun(ChStatePtr->CallbackParam, OvfFlag);
    }
    else
    {
        if ((TRUE == OvfFlag) && (NULL_PTR != ChStatePtr->ChOvfNotificationFun))
        {
            ChStatePtr->ChOvfNotificationFun();
        }
    }
}
#endif

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
LOCAL_INLINE void Tim_Icu_Drv_SetLocalSigMeasAndNotify(Tim_Icu_Drv_IdType InstId, 
                                                                    Tim_Icu_Drv_ChannelIdType Channel, 
                                                                    uint16 PulseValue, 
                                                                    uint16 PeriodValue, 
                                                                    boolean OvfFlag)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    SchM_Enter_Icu_TimValue();
    ChStatePtr->PulseValue = PulseValue;
    ChStatePtr->PeriodValue = PeriodValue;
    SchM_Exit_Icu_TimValue();

    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    Tim_Icu_Drv_LocalOvfReport(InstId, Channel, OvfFlag);
    
    if (NULL_PTR != ChStatePtr->SetupChStateFun)     
    {
        ChStatePtr->SetupChStateFun(ChStatePtr->CallbackParam,
                                                     TIM_ICU_DRV_CHANNEL_STATE_IDLE, TRUE);
    }
    # if (STD_ON == TIM_ICU_DRV_GET_INPUT_STATE_API)
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    ChStatePtr->InputStatus = (boolean) TRUE;
    #endif
}
#endif

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
LOCAL_INLINE void Tim_Icu_Drv_CalcLocalPeriodTime(Tim_Icu_Drv_IdType InstId, 
                                                             Tim_Icu_Drv_ChannelIdType Channel, 
                                                             boolean OvfFlag)
{
    const Reg_Tim_BfType *TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    const Tim_Icu_Drv_InstanceStateType * InstStatePtr;
    uint32 PeriodValue;
    uint32 CapValue;

    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];

    InstStatePtr = &Tim_Icu_Drv_InstState[InstId];

    CapValue = TIMx->TIM_CCVn[Channel].CCV;

    if(FALSE == ChStatePtr->FirstCapture)
    {
        if (CapValue > ChStatePtr->FirstCapValue)
        {
            PeriodValue = CapValue - ChStatePtr->FirstCapValue;
        }
        else
        {
            PeriodValue = (uint32)(InstStatePtr->TimCounterModulValue) - (uint32)(ChStatePtr->FirstCapValue) + 
                          (uint32)CapValue + (uint32)1U;
        }
        
        ChStatePtr->FirstCapValue = (uint16)CapValue;
        Tim_Icu_Drv_SetLocalSigMeasAndNotify(InstId, Channel, (uint16)0U,
                                                             (uint16)PeriodValue, OvfFlag);
    }
    else
    {
        ChStatePtr->FirstCapValue = (uint16)CapValue;
        ChStatePtr->FirstCapture = (boolean)FALSE;
    }
}

LOCAL_INLINE void Tim_Icu_Drv_CalcLocalDutyCycle(Tim_Icu_Drv_IdType InstId, 
                                                           Tim_Icu_Drv_ChannelIdType Channel, 
                                                           boolean OvfFlag)
{
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_ChannelStateType * ChStateFPtr;
    const Tim_Icu_Drv_InstanceStateType * InstStatePtr;
    uint32 PeriodValue;
    uint32 PulseValue;
    uint32 FirstCapValue;
    uint32 SecondCapValue;
    uint16 FirstCapEls;
    uint16 SecondCapEls;

    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];

    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStateFPtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    InstStatePtr = &Tim_Icu_Drv_InstState[InstId];

    if (FALSE == ChStateFPtr->FirstCapture)
    {
        ChStatePtr = &Tim_Icu_Drv_ChState[InstId][((uint32)Channel - 1U)];

        FirstCapValue = TIMx->TIM_CCVn[(uint32)Channel - 1U].CCV;
        SecondCapValue = TIMx->TIM_CCVn[Channel].CCV;

        if (SecondCapValue > FirstCapValue)
        {
            PeriodValue = SecondCapValue - FirstCapValue;
        }
        else
        {
            PeriodValue = (uint32)InstStatePtr->TimCounterModulValue - FirstCapValue + 
                        SecondCapValue + (uint32)1U;
        }
        
        if (FirstCapValue > ChStatePtr->FirstCapValue)
        {
            PulseValue = FirstCapValue - ChStatePtr->FirstCapValue;
        }
        else
        {
            PulseValue = (uint32)InstStatePtr->TimCounterModulValue - (uint32)ChStatePtr->FirstCapValue + 
                        FirstCapValue + (uint32)1U;
        }
        PeriodValue = PeriodValue + PulseValue ;
        if (TRUE == ChStatePtr->FirstCapturePolarity)
        {
            PulseValue = PeriodValue - PulseValue;
        }
        
        Tim_Icu_Drv_SetLocalSigMeasAndNotify(InstId,
                                        (Tim_Icu_Drv_ChannelIdType)((uint8)((uint32)Channel - 1U)), 
                                        (uint16)PulseValue, (uint16)PeriodValue, OvfFlag);
        TIMx->TIM_CMCn[(uint32)Channel - 1U].CHF = 0U;

        ChStateFPtr->FirstCapture = (boolean)FALSE;
        ChStatePtr->FirstCapValue= (uint16)SecondCapValue ;
    }
    else
    {
        FirstCapEls = (uint16)TIMx->TIM_CMCn[Channel].ELS;
        SecondCapEls = (uint16)TIMx->TIM_CMCn[(uint32)Channel + 1U].ELS;

        ChStateFPtr->FirstCapValue = (uint16)TIMx->TIM_CCVn[Channel].CCV;

        if ((uint16)TIM_ICU_DRV_INPUT_FALLING_EDGE == FirstCapEls)
        {
            ChStateFPtr->FirstCapturePolarity = (boolean)TRUE;
        }

        SchM_Enter_Icu_TimSetChannelModeCfg();
        /* If write protection is enabled, then disable it. */
        if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
        {
            /* Disable write protection */
                TIMWx->TIM_GLBSR |= (uint32)0xFFFU;
        }
        ChStateFPtr->FirstCapture = (boolean)FALSE;
        TIMWx->TIM_PCR |= ((uint32)TIM_ICU_DRV_PCR_DECAPMODE_MASK << 
                                                ((((uint32)Channel & 0xFEU) >> 1U) << 3U));
        TIMWx->TIM_CMCn[Channel] = (uint32)((TIMWx->TIM_CMCn[Channel]&(~0xCUL))|(uint32)0x24UL);
        TIMWx->TIM_CMCn[Channel] = (uint32)((TIMWx->TIM_CMCn[Channel]&(~0x3UL))|(uint32)SecondCapEls|0x20UL);
        TIMWx->TIM_CMCn[(uint32)Channel + 1U] = (uint32)((TIMWx->TIM_CMCn[(uint32)Channel + 1U]&(~0x3UL))|(uint32)FirstCapEls|0x24UL);
        TIMWx->TIM_CMCn[Channel] &= (uint32)0xCFUL;
        TIMx->TIM_CMCn[(uint32)Channel + 1U].CHF = 0U;
        TIMWx->TIM_CMCn[(uint32)Channel + 1U] |= (uint32)0x30UL;
        SchM_Exit_Icu_TimSetChannelModeCfg();
    

    }
}


LOCAL_INLINE void Tim_Icu_Drv_LocalSignalMeasurementHandle(Tim_Icu_Drv_IdType InstId, 
                                                                Tim_Icu_Drv_ChannelIdType Channel, 
                                                                boolean OvfFlag)
{
    Reg_Tim_BfType * TIMx;
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    const Tim_Icu_Drv_InstanceStateType * InstStatePtr;
    uint32 PulseValue;
    uint32 FirstCapValue;
    uint32 SecondCapValue;
    Tim_Icu_Drv_MeasPropertyType MeasProperty;
    
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    InstStatePtr = &Tim_Icu_Drv_InstState[InstId];
    MeasProperty = ChStatePtr->MeasProperty;

    if ((TIM_ICU_DRV_HIGH_TIME == MeasProperty) || (TIM_ICU_DRV_LOW_TIME == MeasProperty))
    {

        if(TIMx->TIM_CMCn[(uint32)Channel -1U].CHF  == 1U)
        {

            FirstCapValue = TIMx->TIM_CCVn[(uint32)Channel -1U].CCV;
            SecondCapValue = TIMx->TIM_CCVn[Channel].CCV;
            TIMx->TIM_CMCn[(uint32)Channel -1U].CHF = 0U ;
            if(SecondCapValue > FirstCapValue)
            {
                PulseValue = SecondCapValue - FirstCapValue;
            }
            else
            {
                PulseValue = (uint32)InstStatePtr->TimCounterModulValue - FirstCapValue + SecondCapValue + 1U;
            }

            Tim_Icu_Drv_SetLocalSigMeasAndNotify(InstId,
                                            (Tim_Icu_Drv_ChannelIdType)((uint8)((uint32)Channel - 1U)), 
                                            (uint16)PulseValue, (uint16)0U, OvfFlag);

        }
        else
        {
            /*do nothing */
        }
    }
    else if (TIM_ICU_DRV_PERIOD_TIME == MeasProperty)
    {
        Tim_Icu_Drv_CalcLocalPeriodTime(InstId, Channel, OvfFlag);
    }
    else if (TIM_ICU_DRV_DUTY_CYCLE == MeasProperty)
    {
        Tim_Icu_Drv_CalcLocalDutyCycle(InstId, Channel, OvfFlag);
    }
    else
    {
        /*do nothing*/
    }
}
#endif

#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
LOCAL_INLINE void Tim_Icu_Drv_LocalTimestampHandle(Tim_Icu_Drv_IdType InstId, 
                                                              Tim_Icu_Drv_ChannelIdType Channel, 
                                                              uint16 CapValue, boolean OvfFlag)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    
    Tim_Icu_Drv_LocalOvfReport(InstId, Channel, OvfFlag);
    ChStatePtr->BufferHeadPtr[ChStatePtr->BufferIndex] = CapValue;
    ChStatePtr->BufferIndex++;

    if (ChStatePtr->BufferIndex >= ChStatePtr->BufferSize)
    {
        if (TIM_ICU_DRV_CIRCULAR_BUFFER == ChStatePtr->TsBufferType)
        {
            ChStatePtr->BufferIndex = 0U;
        }
        else
        {
            Tim_Icu_Drv_StopTimestamp(InstId, Channel);
            if (NULL_PTR != ChStatePtr->SetupChStateFun)
            {
                ChStatePtr->SetupChStateFun(ChStatePtr->CallbackParam, 
                                            TIM_ICU_DRV_CHANNEL_STATE_RUNNING, 
                                            FALSE);
            }
        }
    }

    if (0U != ChStatePtr->NotifyInterval)
    {
        ChStatePtr->NotifyCount++;
        if (ChStatePtr->NotifyCount >= ChStatePtr->NotifyInterval)
        {
            ChStatePtr->NotifyCount = 0U;
            if ((TRUE == ChStatePtr->NotifyEnable) && (NULL_PTR != ChStatePtr->ChNotificationFun))
            {
                ChStatePtr->ChNotificationFun();
            }
        }
    }
}
#endif

LOCAL_INLINE void Tim_Icu_Drv_LocalChfProcess(Tim_Icu_Drv_IdType InstId, 
                                                        Tim_Icu_Drv_ChannelIdType Channel)
{
    const Reg_Tim_BfType * TIMx;
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    boolean OvfFlag = FALSE;
    
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];

    switch (ChStatePtr->OptMode)
    {
    #if (STD_ON == TIM_ICU_DRV_EDGE_DETECT_API)
        case TIM_ICU_DRV_MODE_SIGNAL_EDGE_DETECT:
        {
            # if (STD_ON == TIM_ICU_DRV_GET_INPUT_STATE_API)
            ChStatePtr->InputStatus = (boolean) TRUE;
            #endif
            Tim_Icu_Drv_LocalNotifyEvent(InstId, Channel, OvfFlag);
        }
        
        break;
    #endif

    #if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
        case TIM_ICU_DRV_MODE_SIGNAL_MEASUREMENT:
        {
            Tim_Icu_Drv_LocalSignalMeasurementHandle(InstId, Channel, OvfFlag);
        }
        
        break;
    #endif

    #if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
        case TIM_ICU_DRV_MODE_TIMESTAMP:
        {
            Tim_Icu_Drv_LocalTimestampHandle(InstId, Channel,
                                             (uint16)TIMx->TIM_CCVn[Channel].CCV, OvfFlag);
        }
        
        break;
    #endif

    #if (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API)
        case TIM_ICU_DRV_MODE_EDGE_COUNTER:
        {
            ChStatePtr->EdgeSumNum++;
            if (0U == ChStatePtr->EdgeSumNum)
            {
                OvfFlag = (boolean)TRUE;
            }
            else
            {
                OvfFlag = (boolean)FALSE;
            }
            #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
            if (ChStatePtr->OverflowNotificationEnable == TRUE)
            {
            #endif
                Tim_Icu_Drv_LocalNotifyEvent(InstId, Channel, OvfFlag);
            #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
            }
            #endif
        }
        
        break;
    #endif
    
        default:
            /* Do nothing */
            break;
    }
    (void)TIMx;
}

LOCAL_INLINE void Tim_Icu_Drv_LocalVofProcess(Tim_Icu_Drv_IdType InstId)
{
    const Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    uint8  Channel;
    Tim_Icu_Drv_MeasurementModeType OptMode;

    for (Channel = 0U; Channel < (uint8)TIM_ICU_DRV_CHANNEL_SUMCNT; Channel++)
    {
        Tim_Icu_Drv_CheckArguments(InstId, (Tim_Icu_Drv_ChannelIdType)Channel);

        ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
        OptMode = ChStatePtr->OptMode;

        if ((TIM_ICU_DRV_MODE_SIGNAL_MEASUREMENT == OptMode) || 
                                                    (TIM_ICU_DRV_MODE_TIMESTAMP == OptMode))
        {
            #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)  
            if ( ChStatePtr->OverflowNotificationEnable == TRUE)
            {
            #endif
                if(NULL_PTR != ChStatePtr->CallbackFun)
                {
                    ChStatePtr->CallbackFun(ChStatePtr->CallbackParam, TRUE);
                }
                else
                {
                    if(NULL_PTR != ChStatePtr->ChOvfNotificationFun)
                    {
                        ChStatePtr->ChOvfNotificationFun();
                    }
                }
            #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)  
            }
            #endif

        }
    }
}

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
LOCAL_INLINE void Tim_Icu_Drv_LocalSetInputFilter(Tim_Icu_Drv_IdType InstId, 
                                                             Tim_Icu_Drv_ChannelIdType Channel, 
                                                             Tim_Icu_Drv_FilterType Filter)
{
    Reg_Tim_BfType * TIMx;

    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    switch (Channel)
    {
        case TIM_ICU_DRV_CHANNEL_0:
            TIMx->TIM_FILTER.FILVAL0 = (uint32)Filter;
            break;
            
        case TIM_ICU_DRV_CHANNEL_1:
            TIMx->TIM_FILTER.FILVAL1 = (uint32)Filter;
            break;
            
        case TIM_ICU_DRV_CHANNEL_2:
            TIMx->TIM_FILTER.FILVAL2 = (uint32)Filter;
            break;
            
        case TIM_ICU_DRV_CHANNEL_3:
            TIMx->TIM_FILTER.FILVAL3 = (uint32)Filter;
            break;
            
        default:
            /* Do nothing */
            break;
      
    }
}
#endif

LOCAL_INLINE void Tim_Icu_Drv_SetModeCondition(Tim_Icu_Drv_IdType InstId, 
                                                    Tim_Icu_Drv_ChannelIdType Channel, 
                                                    const Tim_Icu_Drv_ChannelConfigType * ChCfgPtr)
{
#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
#endif
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
#endif
    switch(ChCfgPtr->OptMode)
    {
    #if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
        case TIM_ICU_DRV_MODE_SIGNAL_MEASUREMENT:
        {
            ChStatePtr->MeasProperty = ChCfgPtr->MeasProperty;
        }
            break;
    #endif
    
    #if (STD_ON == TIM_ICU_DRV_EDGE_DETECT_API)
        case TIM_ICU_DRV_MODE_SIGNAL_EDGE_DETECT:
        {
            /* If write protection is enabled, then disable it. */
            if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
            {
                /* Disable write protection */
                TIMWx->TIM_GLBSR |= (uint32)0xFFFU;
            }
            TIMWx->TIM_PCR &= ~((uint32)TIM_ICU_DRV_PCR_COMB0_MASK << 
                                                    ((((uint32)Channel & 0xFEU) >> 1U) << 3U));
            TIMWx->TIM_CMCn[Channel] = (uint32)((TIMWx->TIM_CMCn[Channel]&0xF3UL)|0x20UL);
        }
            break;
    #endif
    
    #if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
        case TIM_ICU_DRV_MODE_TIMESTAMP:
            break;
    #endif
    
    #if (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API)
        case TIM_ICU_DRV_MODE_EDGE_COUNTER:
            break;
    #endif
    
        default:
            /* Do nothing */
            break;
    }
    (void)TIMx;
    (void)TIMWx;
}

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
LOCAL_INLINE void Tim_Icu_Drv_SetInputFilterCondition(Tim_Icu_Drv_IdType InstId, 
                                                    Tim_Icu_Drv_ChannelIdType Channel, 
                                                    const Tim_Icu_Drv_ChannelConfigType * ChCfgPtr,
                                                    Tim_Icu_Drv_MeasPropertyType MeasProperty)
{
    uint32 ChannelId = (uint32)(Channel) + 1U;

    if ((uint32)Channel < TIM_ICU_DRV_FILTER_MAXCH)
    {       

        if ((TIM_ICU_DRV_PERIOD_TIME != MeasProperty) && 
            (TIM_ICU_DRV_MODE_SIGNAL_MEASUREMENT == ChCfgPtr->OptMode))
        {
            Tim_Icu_Drv_LocalSetInputFilter(InstId, 
                                            (Tim_Icu_Drv_ChannelIdType)ChannelId, 
                                            ChCfgPtr->FilterWidth);
        }
    
    }
}
#endif

#if (STD_ON == TIM_ICU_DRV_DEINIT_API)
LOCAL_INLINE void Tim_Icu_Drv_LocalClearChannelState(Tim_Icu_Drv_IdType InstId, 
                                                                 Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];

    SchM_Enter_Icu_TimSetChannelStatePtr();
#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
    ChStatePtr->FirstCapture = (boolean)FALSE;
    ChStatePtr->MeasProperty = TIM_ICU_DRV_NO_MEAS;
#endif

#if (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API)
    ChStatePtr->EdgeSumNum = 0U;
#endif

    ChStatePtr->OptMode = TIM_ICU_DRV_MODE_MEASUREMENT_DISABLE;
    ChStatePtr->ActiveEdge = TIM_ICU_DRV_INPUT_DISABLED;
    ChStatePtr->DmaUse = TIM_ICU_DRV_DMA_DISABLE;
    ChStatePtr->CallbackFun = NULL_PTR;
    ChStatePtr->CallbackParam = 0U;
    ChStatePtr->NotifyEnable = (boolean)FALSE;
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    ChStatePtr->OverflowNotificationEnable = FALSE;
#endif
#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
    ChStatePtr->TsBufferType = TIM_ICU_DRV_NO_TIMESTAMP;
#endif
    SchM_Exit_Icu_TimSetChannelStatePtr();
}
#endif

static void Tim_Icu_Drv_LocalGlobalInitConfig(Tim_Icu_Drv_IdType InstId, uint16 ModValue)
{
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx; 
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    SchM_Enter_Icu_TimSetChannelModeCfg();
    if (1U == TIMx->TIM_FLTSR.WPEN)
    {
        TIMWx->TIM_GLBSR |= (uint32)0xFFFU;
    }

    TIMx->TIM_TIMEBASE.CKSRC = 0U;
    TIMx->TIM_MOD.MOD = ModValue;
    TIMx->TIM_CNTINIT.CNTINIT = 0U;
    TIMWx->TIM_GLBSR = 0x1FFU;
    SchM_Exit_Icu_TimSetChannelModeCfg();
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Private_FunctionDefinition */


/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  TimIcuInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
Tim_Icu_Drv_StatusType Tim_Icu_Drv_Init(Tim_Icu_Drv_IdType InstId, 
                                          const Tim_Icu_Drv_InstanceConfigType * TimIcuInstCfgPtr)
{
    const Tim_Icu_Drv_ChannelConfigType * ChCfgPtr;
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_InstanceStateType * InstStatePtr;
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    uint32 PhsyChId;
    uint8 Loop;
    Tim_Icu_Drv_StatusType RetVal = TIM_ICU_DRV_STATUS_SUCCESS;

#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif


#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((uint32)InstId < TIM_ICU_DRV_INSTANCE_SUMCNT);
    MCALLIB_DEV_ASSERT(NULL_PTR != TimIcuInstCfgPtr);
#endif 
    
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    InstStatePtr = &Tim_Icu_Drv_InstState[InstId];

    if (FALSE == InstStatePtr->InstInitFlag)
    {
        Tim_Icu_Drv_LocalGlobalInitConfig(InstId, TimIcuInstCfgPtr->GlobalCfgPtr->MaxCntVal);
        InstStatePtr->ClockDiv = TimIcuInstCfgPtr->GlobalCfgPtr->ClockDiv;
        InstStatePtr->TimCounterModulValue = TimIcuInstCfgPtr->GlobalCfgPtr->MaxCntVal;
        
        for (Loop = 0U; Loop < TimIcuInstCfgPtr->ChSumNum ; Loop++)
        {
            ChCfgPtr = &(*TimIcuInstCfgPtr->ChCfgPtr)[Loop];
            PhsyChId = ChCfgPtr->PhsyChId;
            Tim_Icu_Drv_CheckArguments(InstId, (Tim_Icu_Drv_ChannelIdType)PhsyChId);

            ChStatePtr = &Tim_Icu_Drv_ChState[InstId][PhsyChId];

#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
            MCALLIB_DEV_ASSERT(NULL_PTR != ChStatePtr);
#endif 

            ChStatePtr->CallbackFun = ChCfgPtr->CallbackFun;
            ChStatePtr->CallbackParam = ChCfgPtr->CallbackParam;
            ChStatePtr->ChNotificationFun = ChCfgPtr->ChNotificationFun;
            ChStatePtr->ChOvfNotificationFun = ChCfgPtr->ChOvfNotificationFun;
            ChStatePtr->ActiveEdge = ChCfgPtr->ActiveEdge;
            ChStatePtr->DmaUse = ChCfgPtr->DmaUse;
            ChStatePtr->NotifyEnable = (boolean)FALSE;

        #if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
            ChStatePtr->PulseValue = 0U;
            ChStatePtr->PeriodValue = 0U;
        #endif
        #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
            ChStatePtr->OverflowNotificationEnable = FALSE;
        #endif
        #if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
            ChStatePtr->BufferHeadPtr = NULL_PTR;
            ChStatePtr->BufferSize = (uint16)0U;
            ChStatePtr->NotifyInterval = (uint16)0U;
            ChStatePtr->NotifyCount = (uint16)0U;
            ChStatePtr->BufferIndex = (uint16)0U;
            ChStatePtr->TsBufferType = ChCfgPtr->TsBufferType;
        #endif
            ChStatePtr->SetupChStateFun = ChCfgPtr->SetupChStateFun;
            TIMWx->TIM_CMCn[PhsyChId] = 0U;
        #if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
            Tim_Icu_Drv_SetInputFilterCondition(InstId, (Tim_Icu_Drv_ChannelIdType)PhsyChId, 
                                                        ChCfgPtr,
                                                        ChStatePtr->MeasProperty);
            ChStatePtr->FirstCapture = FALSE;
        #endif
        #if (STD_ON == TIM_ICU_DRV_TIMESTAMP_DMA_USE)
            TIMWx->TIM_CMCn[PhsyChId]= (uint32)((TIMWx->TIM_CMCn[PhsyChId]&0xBFUL)|((uint32)(ChCfgPtr->DmaUse)<<6U)|0x20UL);
        #endif
        #if (STD_ON == TIM_ICU_DRV_GET_INPUT_STATE_API)
            ChStatePtr->InputStatus = (boolean) FALSE;
        #endif
            Tim_Icu_Drv_SetActivationCondition(InstId, (Tim_Icu_Drv_ChannelIdType)PhsyChId, 
                                              ChStatePtr->ActiveEdge);

            ChStatePtr->OptMode = ChCfgPtr->OptMode;

            Tim_Icu_Drv_SetModeCondition(InstId, (Tim_Icu_Drv_ChannelIdType)PhsyChId, ChCfgPtr);

        }

        TIMx->TIM_TIMEBASE.DBGM = (uint32)TimIcuInstCfgPtr->GlobalCfgPtr->DebugMode;
        TIMx->TIM_TIMEBASE.PSDIV = (uint32)TimIcuInstCfgPtr->GlobalCfgPtr->ClockDiv;
        TIMx->TIM_TIMEBASE.CKSRC = (uint32)TimIcuInstCfgPtr->GlobalCfgPtr->ClockSrc;
        InstStatePtr->InstInitFlag = (boolean)TRUE;
        #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
        TIMWx->TIM_GLBSR = 0x1FFU;
        TIMx->TIM_GLBCR.TOIE = 0U;
        #endif
    }
    else
    {
        RetVal = TIM_ICU_DRV_STATUS_ERROR;
    }

#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return RetVal;
}

#if (STD_ON == TIM_ICU_DRV_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
Tim_Icu_Drv_StatusType Tim_Icu_Drv_DeInit (Tim_Icu_Drv_IdType InstId)
{
    Tim_Icu_Drv_InstanceStateType * InstStatePtr;
    #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API) 
    Reg_Tim_BfType * TIMx;
    #endif
    Reg_Tim_WType * TIMWx;
    uint32 Channel;
    Tim_Icu_Drv_StatusType RetVal = TIM_ICU_DRV_STATUS_SUCCESS;
    
    #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API) 
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    #endif
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    InstStatePtr = &Tim_Icu_Drv_InstState[InstId];
    #if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)  
    SchM_Enter_Icu_TimSetChannelState();
    TIMx->TIM_GLBCR.TOIE = 0U;
    SchM_Exit_Icu_TimSetChannelState();
    #endif
    if (TRUE == (boolean)InstStatePtr->InstInitFlag)
    {
        SchM_Enter_Icu_TimSetChannelState();

        for (Channel = 0U; Channel < TIM_ICU_DRV_CHANNEL_SUMCNT; Channel++)
        {
            if (Channel < TIM_ICU_DRV_FILTER_MAXCH)
            {
                Tim_Icu_Drv_LocalSetInputFilter(InstId, (Tim_Icu_Drv_ChannelIdType)Channel, 
                                               TIM_ICU_DRV_INPUT_FILTER_DISABLE);
            }

            TIMWx->TIM_CMCn[Channel] = 0U;
            TIMWx->TIM_CCVn[Channel] = 0U;
            
            Tim_Icu_Drv_LocalClearChannelState(InstId, (Tim_Icu_Drv_ChannelIdType)Channel);
       }
        TIMWx->TIM_TIMEBASE = 0U;
        TIMWx->TIM_CNT = 0U;
        TIMWx->TIM_PCR =0;
        InstStatePtr->InstInitFlag = (boolean)FALSE;
        InstStatePtr->ClockDiv = TIM_ICU_DRV_CLK_DIVIDE_1;
        InstStatePtr->ChfClrMask = 0U;
        SchM_Exit_Icu_TimSetChannelState();
        Tim_Icu_Drv_LocalGlobalInitConfig(InstId, 0U);
        
    }
    else
    {
        RetVal = TIM_ICU_DRV_STATUS_ERROR;
    }
    return RetVal;

}
#endif

#if (STD_ON == TIM_ICU_DRV_SET_MODE_API)
/**
 * @brief      Sets hardware Channel into SLEEP mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used 
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetChannelSleepMode(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Reg_Tim_WType * TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];

    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMWx->TIM_CMCn[Channel] = (uint32)((TIMWx->TIM_CMCn[Channel]&(uint32)0xFCUL)|0x20UL);
    SchM_Exit_Icu_TimSetChannelModeCfg();
}

/**
 * @brief      Sets hardware Channel into NORMAL mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used 
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetChannelNormalMode(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    const Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Reg_Tim_WType * TIMWx;
    Tim_Icu_Drv_EdgeAlignmentModeType ActiveEdge;

    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    ActiveEdge= ChStatePtr->ActiveEdge;
    if (TIM_ICU_DRV_INPUT_DISABLED != ActiveEdge)
    {
        SchM_Enter_Icu_TimSetChannelModeCfg();
        TIMWx->TIM_CMCn[Channel] = ((TIMWx->TIM_CMCn[Channel]&(uint32)0xFCUL)|(uint32)ActiveEdge|0x20UL) ;
        SchM_Exit_Icu_TimSetChannelModeCfg();
    }
}
#endif

/**
 * @brief      The function that sets up the activation condition
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[in]  ActiveEdge: edge activation type used 
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetActivationCondition(Tim_Icu_Drv_IdType InstId, 
                                                   Tim_Icu_Drv_ChannelIdType Channel, 
                                                   Tim_Icu_Drv_EdgeAlignmentModeType ActiveEdge)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Reg_Tim_WType * TIMWx;

    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    ChStatePtr->ActiveEdge = ActiveEdge;

    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMWx->TIM_CMCn[Channel] = ((TIMWx->TIM_CMCn[Channel]&(uint32)0xFCUL)|(uint32)ActiveEdge|0x20UL) ;
    SchM_Exit_Icu_TimSetChannelModeCfg();
}

/**
 * @brief      The function disable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_DisableNotification(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    ChStatePtr->NotifyEnable = (boolean)FALSE;
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    ChStatePtr->OverflowNotificationEnable= (boolean)FALSE;
#endif
}

/**
 * @brief      The function enable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_EnableNotification(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    ChStatePtr->NotifyEnable = (boolean)TRUE;
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    ChStatePtr->OverflowNotificationEnable= (boolean)TRUE;
#endif
}

#if (STD_ON == TIM_ICU_DRV_GET_INPUT_STATE_API)
/**
 * @brief      The function get input state of the Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return input state
 *
 */
boolean Tim_Icu_Drv_GetInputState(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    boolean RetVal = (boolean)FALSE;
    SchM_Enter_Icu_TimSetChannelStatePtr();
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    RetVal = ChStatePtr->InputStatus;
    ChStatePtr->InputStatus = (boolean)FALSE;
    SchM_Exit_Icu_TimSetChannelStatePtr();
    return RetVal;
}
#endif

#if (((STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API) && \
    (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_DMA_USE)) || \
     ((STD_ON == TIM_ICU_DRV_TIMESTAMP_API) && \
     (STD_ON == TIM_ICU_DRV_TIMESTAMP_DMA_USE)))
/**
 * @brief      The function get address of CVn register
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return CVn register
 *
 */
uint32 Tim_Icu_Drv_GetCounterAddr(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
     Reg_Tim_BfType * TIMx;

     TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
     return ((uint32)(&TIMx->TIM_CCVn[Channel]));
}
#endif

#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
/**
 * @brief      This function starts timestamp measure mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[in]  bufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 * @param[in]  bufferSize:     Size of the external buffer
 * @param[in]  NotifyInterval: Notification interval
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StartTimestamp(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel, 
                                        uint16 * bufferPtr,
                                        uint16 bufferSize, uint16 NotifyInterval)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Reg_Tim_WType * TIMWx;
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    Reg_Tim_BfType * TIMx;
#endif
    Tim_Icu_Drv_CheckArguments(InstId, Channel);
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
#endif
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];

    SchM_Enter_Icu_TimSetChannelStatePtr();
    ChStatePtr->BufferHeadPtr = bufferPtr;
    ChStatePtr->BufferSize = bufferSize;
    ChStatePtr->NotifyInterval = NotifyInterval;
    ChStatePtr->NotifyCount = 0U;
    ChStatePtr->BufferIndex = 0U;
    SchM_Exit_Icu_TimSetChannelStatePtr();
    Tim_Icu_Drv_SetActivationCondition(InstId, Channel, ChStatePtr->ActiveEdge);
    Tim_Icu_Drv_ClrLocalIntFlag(InstId, Channel);
    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMWx->TIM_CMCn[Channel] |= (uint32)0x30UL;
    SchM_Exit_Icu_TimSetChannelModeCfg();
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    TIMWx->TIM_GLBSR = 0x1FFU;
    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMx->TIM_GLBCR.TOIE = 1U;
    SchM_Exit_Icu_TimSetChannelModeCfg();
#endif
}

/**
 * @brief      This function read the timestamp index of the given Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return the timestamp index
 *
 */
uint16 Tim_Icu_Drv_GetTimestampIndex(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    const Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    uint16 TsIdx = 0U;

    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];

    if (NULL_PTR != ChStatePtr->BufferHeadPtr)
    {
        TsIdx = ChStatePtr->BufferIndex;
    }

    return TsIdx;
}

/**
 * @brief      This function stops timestamp measure mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StopTimestamp(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{   
    Reg_Tim_WType * TIMWx; 
    Tim_Icu_Drv_CheckArguments(InstId, Channel);
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)  
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
#endif

    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    Tim_Icu_Drv_StopLocalChannel(InstId, Channel);
    SchM_Enter_Icu_TimSetChannelModeCfg();
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)    
    ChStatePtr->OverflowNotificationEnable = FALSE;
#endif 
    TIMWx->TIM_CMCn[Channel] =(uint32)((TIMWx->TIM_CMCn[Channel]&(uint32)0xEFUL)|(uint32)0x20UL);
    SchM_Exit_Icu_TimSetChannelModeCfg();
}
#endif



#if (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API)
/**
 * @brief      This function reset the edge counting for hardware Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_ResetEdgeCount(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    SchM_Enter_Icu_TimSetChannelStatePtr();
    ChStatePtr->EdgeSumNum = 0U;
    SchM_Exit_Icu_TimSetChannelStatePtr();
}
/**
 * @brief      This function enable edge count measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return operation flag
 *
 */
Tim_Icu_Drv_StatusType Tim_Icu_Drv_EnableEdgeCount(Tim_Icu_Drv_IdType InstId, 
                                                         Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Reg_Tim_WType * TIMWx;

    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    SchM_Enter_Icu_TimSetChannelStatePtr();
    ChStatePtr->EdgeSumNum = 0U;
    SchM_Exit_Icu_TimSetChannelStatePtr();
    Tim_Icu_Drv_SetActivationCondition(InstId, Channel, ChStatePtr->ActiveEdge);
    Tim_Icu_Drv_ClrLocalIntFlag(InstId, Channel);
    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMWx->TIM_CMCn[Channel] |= 0x30U;
    SchM_Exit_Icu_TimSetChannelModeCfg();

    return TIM_ICU_DRV_STATUS_SUCCESS;
}

/**
 * @brief      This function disable edge count measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_DisableEdgeCount(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Reg_Tim_WType * TIMWx;
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)  
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
#endif  
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    Tim_Icu_Drv_StopLocalChannel(InstId, Channel);

    SchM_Enter_Icu_TimSetChannelModeCfg();
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)    
    ChStatePtr->OverflowNotificationEnable = FALSE;
#endif 
    TIMWx->TIM_CMCn[Channel] =(uint32)((TIMWx->TIM_CMCn[Channel]&(uint32)0xEFUL)|(uint32)0x20UL);
    SchM_Exit_Icu_TimSetChannelModeCfg();
}

/**
 * @brief      This function get the edges number
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return edge number
 *
 */
uint16 Tim_Icu_Drv_GetEdgeNumbers(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    const Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
        
    return (ChStatePtr->EdgeSumNum);
}
#endif

#if (STD_ON == TIM_ICU_DRV_EDGE_DETECT_API)
/**
 * @brief      This function enable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_EnableEdgeDetection(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];

#if (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API)  
    SchM_Enter_Icu_TimSetChannelStatePtr(); 
    ChStatePtr->EdgeSumNum = 0U;
    SchM_Exit_Icu_TimSetChannelStatePtr();
#endif    
    Tim_Icu_Drv_SetActivationCondition(InstId, Channel, ChStatePtr->ActiveEdge);
    SchM_Enter_Icu_TimSetChannelModeCfg();
#if (STD_ON == TIM_ICU_DRV_GET_INPUT_STATE_API)
    ChStatePtr->InputStatus = (boolean)FALSE;
#endif   
    TIMx->TIM_CMCn[Channel].CHF = 0U;
    TIMWx->TIM_CMCn[Channel] |=(uint32)0x30UL;
    SchM_Exit_Icu_TimSetChannelModeCfg(); 
}

/**
 * @brief      This function disable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_DisableEdgeDetection(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Reg_Tim_WType * TIMWx;

    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];

    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMWx->TIM_CMCn[Channel] =(uint32)((TIMWx->TIM_CMCn[Channel]&(uint32)0xEFUL)|(uint32)0x20UL);
    SchM_Exit_Icu_TimSetChannelModeCfg();
}
#endif

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
/**
 * @brief      This function starts signal measurement mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StartSignalMeasurement(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_InstanceStateType * InstStatePtr;
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    Tim_Icu_Drv_MeasPropertyType MeasProperty;
    Tim_Icu_Drv_EdgeAlignmentModeType ActiveEdge;
    uint32 InPariChannel;

    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    InstStatePtr = &Tim_Icu_Drv_InstState[InstId];
    MeasProperty = ChStatePtr->MeasProperty;
    ActiveEdge = ChStatePtr->ActiveEdge;
    InPariChannel = ((uint32)Channel & 0xFEU) >> 1U;

    ChStatePtr->PeriodValue = 0U;
    ChStatePtr->PulseValue = 0U;
    ChStatePtr->FirstCapturePolarity = (boolean)FALSE;

    /* If write protection is enabled, then disable it. */
    if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
    {
        /* Disable write protection */
        TIMWx->TIM_GLBSR |= (uint32)0xFFFU;
    }
#if (STD_ON == TIM_ICU_DRV_GET_INPUT_STATE_API)
    ChStatePtr->InputStatus = (boolean)FALSE;
#endif   
    if (TIM_ICU_DRV_PERIOD_TIME == MeasProperty)
    {
        Tim_Icu_Drv_ClrLocalIntFlag(InstId, Channel);
        SchM_Enter_Icu_TimSetChannelStatePtr();
        ChStatePtr->FirstCapture = (boolean)TRUE;
        SchM_Exit_Icu_TimSetChannelStatePtr();
        SchM_Enter_Icu_TimSetChannelModeCfg();
        TIMWx->TIM_PCR &= ~((uint32)TIM_ICU_DRV_PCR_DECAPMODE_MASK << (InPariChannel << 3U));
        TIMWx->TIM_CMCn[Channel]=(((TIMWx->TIM_CMCn[Channel] & (uint32)(0xF3UL))|(((uint32)TIM_ICU_DRV_ONE_PULSE_CAPTURE)<<2U))|(uint32)(0x20UL)) ;
        TIMx->TIM_CMCn[Channel].CHF=0;
        TIMWx->TIM_CMCn[Channel] |= (uint32)0x30UL;
        SchM_Exit_Icu_TimSetChannelModeCfg();

    }
    else
    {
        ChStatePtr = &Tim_Icu_Drv_ChState[InstId][(uint32)Channel + 1U];
        ChStatePtr->MeasProperty = MeasProperty;
        ChStatePtr->OptMode = TIM_ICU_DRV_MODE_SIGNAL_MEASUREMENT;
        Tim_Icu_Drv_ClrLocalIntFlag(InstId, Channel);

        if (TIM_ICU_DRV_DUTY_CYCLE == MeasProperty)
        {
            ChStatePtr = &Tim_Icu_Drv_ChState[InstId][(uint32)Channel];
            SchM_Enter_Icu_TimSetChannelStatePtr();
            ChStatePtr->FirstCapture = (boolean)TRUE;
            SchM_Exit_Icu_TimSetChannelStatePtr();
            InstStatePtr->ChfClrMask |= (uint16)((uint16)1U << (uint16)Channel);
            SchM_Enter_Icu_TimSetChannelModeCfg();
            TIMWx->TIM_PCR &= ~((uint32)TIM_ICU_DRV_PCR_DECAPMODE_MASK << (InPariChannel << 3U));
            TIMWx->TIM_CMCn[Channel]=((TIMWx->TIM_CMCn[Channel] & (uint32)(0xF3UL))|(((uint32)TIM_ICU_DRV_ONE_PULSE_CAPTURE)<<2U)|(uint32)(0x20UL)) ;
            TIMx->TIM_CMCn[Channel].CHF=0;
            TIMWx->TIM_CMCn[Channel] |= (uint32)0x30UL;
            SchM_Exit_Icu_TimSetChannelModeCfg();

        }
        else
        {
            SchM_Enter_Icu_TimSetChannelModeCfg();
            TIMWx->TIM_PCR |= ((uint32)TIM_ICU_DRV_PCR_DECAPMODE_MASK << (InPariChannel << 3U));
            TIMWx->TIM_CMCn[Channel]=((TIMWx->TIM_CMCn[Channel] & (uint32)(0xF3UL))|(((uint32)TIM_ICU_DRV_CONTINUOUS_PULSE_CAPTURE)<<2U)|(uint32)(0x20UL)) ;
            TIMx->TIM_CMCn[(uint8)Channel + 1U].CHF=0;
            TIMWx->TIM_CMCn[(uint8)Channel + 1U] |= (uint32)0x30UL;
            SchM_Exit_Icu_TimSetChannelModeCfg();
        }
        
          switch(ActiveEdge)
          {
              case TIM_ICU_DRV_INPUT_RISING_EDGE:
                  Tim_Icu_Drv_SetActivationCondition(InstId, 
                                          (Tim_Icu_Drv_ChannelIdType)((uint8)((uint32)Channel + 1U)), 
                                          TIM_ICU_DRV_INPUT_FALLING_EDGE);
                  break;
              
              case TIM_ICU_DRV_INPUT_FALLING_EDGE:
                  Tim_Icu_Drv_SetActivationCondition(InstId, 
                                          (Tim_Icu_Drv_ChannelIdType)((uint8)((uint32)Channel + 1U)), 
                                          TIM_ICU_DRV_INPUT_RISING_EDGE);
                  break;
              
              default:
                  Tim_Icu_Drv_SetActivationCondition(InstId, 
                                          (Tim_Icu_Drv_ChannelIdType)((uint8)((uint32)Channel + 1U)), 
                                          TIM_ICU_DRV_INPUT_BOTH_EDGES);
                  break;
          }

        
    }
    Tim_Icu_Drv_SetActivationCondition(InstId, Channel, ActiveEdge);

#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    TIMWx->TIM_GLBSR = 0x1FFU;
    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMx->TIM_GLBCR.TOIE = 1U;
    SchM_Exit_Icu_TimSetChannelModeCfg();
#endif
}

/**
 * @brief      This function stops signal measurement mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return none
 *
 */
void Tim_Icu_Drv_StopSignalMeasurement(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Reg_Tim_WType * TIMWx;

    Tim_Icu_Drv_CheckArguments(InstId, Channel);
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    SchM_Enter_Icu_TimSetChannelModeCfg();
    ChStatePtr->FirstCapturePolarity = (boolean)FALSE;
#if (STD_ON == TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API)
    ChStatePtr->OverflowNotificationEnable = FALSE;
#endif
    SchM_Exit_Icu_TimSetChannelModeCfg();
    Tim_Icu_Drv_StopLocalChannel(InstId, Channel);
    Tim_Icu_Drv_StopLocalChannel(InstId, (Tim_Icu_Drv_ChannelIdType)((uint8)((uint32)Channel + 1U)));

    SchM_Enter_Icu_TimSetChannelModeCfg();

    TIMWx->TIM_CMCn[Channel] = 0U;

    TIMWx->TIM_CMCn[(uint32)Channel + 1U] = 0U;
    TIMWx->TIM_PCR &= ~((uint32)TIM_ICU_DRV_PCR_MASK << 
                                                    ((((uint32)Channel & 0xFEU) >> 1U) << 3U));
    SchM_Exit_Icu_TimSetChannelModeCfg();
}

/**
 * @brief      This function reads the elapsed Signal Low, High or Period Time
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 *
 * @return elapsed time
 *
 */
uint16 Tim_Icu_Drv_GetTimeElapsed(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    uint16 TimeElapsed = 0U;
#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TIM_ICU_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(TIM_ICU_DRV_CHANNEL_SUMCNT > (uint32)Channel);
#endif


    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    SchM_Enter_Icu_TimValue();
    if (TIM_ICU_DRV_DUTY_CYCLE != ChStatePtr->MeasProperty)
    {
        if (TIM_ICU_DRV_PERIOD_TIME == ChStatePtr->MeasProperty)
        {
            TimeElapsed = ChStatePtr->PeriodValue;
            ChStatePtr->PeriodValue = 0U;
        }
        else
        {
            TimeElapsed = ChStatePtr->PulseValue;
            ChStatePtr->PulseValue = 0U;
        }
    }
    SchM_Exit_Icu_TimValue();
#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return TimeElapsed;
}

/**
 * @brief      This function reads the coherent active time and period time
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[out]  DutyCyclePtr: structure where duty cycle values are stored
 *
 * @return none
 *
 */
void Tim_Icu_Drv_GetDutyCycleValues(Tim_Icu_Drv_IdType InstId, Tim_Icu_Drv_ChannelIdType Channel, 
                                             Tim_Icu_Drv_DutyCycleType * DutyCyclePtr)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif


#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TIM_ICU_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(TIM_ICU_DRV_CHANNEL_SUMCNT > (uint32)Channel);
#endif

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    SchM_Enter_Icu_TimValue();
    if (TIM_ICU_DRV_DUTY_CYCLE == ChStatePtr->MeasProperty)
    {
        if (0U != ChStatePtr->PeriodValue)
        {
            DutyCyclePtr->ActiveTime = ChStatePtr->PulseValue;
            DutyCyclePtr->PeriodTime = ChStatePtr->PeriodValue;
            
            ChStatePtr->PulseValue = 0U;
            ChStatePtr->PeriodValue = 0U;
        }
        else
        {
            DutyCyclePtr->ActiveTime = 0U;
            DutyCyclePtr->PeriodTime = 0U;
        }
    }
    SchM_Exit_Icu_TimValue();
#if (STD_ON == TIM_ICU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

}
#endif

#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_DMA_USE)
/**
 * @brief      This function sets the coherent active time and period time
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of TIM used
 * @param[in]  PulseValue: active time
 * @param[in]  PeriodValue: period time
 *
 * @return none
 *
 */
void Tim_Icu_Drv_SetSignalMeasurementValue(Tim_Icu_Drv_IdType InstId, 
                                                       Tim_Icu_Drv_ChannelIdType Channel, 
                                                       uint16 PulseValue, uint16 PeriodValue)
{
    Tim_Icu_Drv_ChannelStateType * ChStatePtr;
    Tim_Icu_Drv_CheckArguments(InstId, Channel);

    ChStatePtr = &Tim_Icu_Drv_ChState[InstId][Channel];
    ChStatePtr->PulseValue = PulseValue;
    ChStatePtr->PeriodValue = PeriodValue;
}
#endif

/**
 * @brief      This function handles CHF interrupt of all Channels
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Tim_Icu_Drv_ChIntHandler(Tim_Icu_Drv_IdType InstId)
{
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    uint32 status;
    uint32 Channel;
    
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    status = TIMWx->TIM_GLBSR; 

    for (Channel = 0U; (uint32)Channel < TIM_ICU_DRV_CHANNEL_SUMCNT; Channel++)
    {
        if (((uint32)0U != (status & ((uint32)1U << Channel))) && (1U == TIMx->TIM_CMCn[Channel].CHIE))
        {
            TIMx->TIM_CMCn[Channel].CHF = 0;        
        }
    }
    for (Channel = 0U; (uint32)Channel < TIM_ICU_DRV_CHANNEL_SUMCNT; Channel++)
    {
        if (((uint32)0U != (status & ((uint32)1U << Channel))) && (1U == TIMx->TIM_CMCn[Channel].CHIE))
        {
            Tim_Icu_Drv_LocalChfProcess(InstId, (Tim_Icu_Drv_ChannelIdType)Channel);                   
        }
    }
}

/**
 * @brief      This function handles overflow interrupt
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */    
void Tim_Icu_Drv_OverflowIntHandler(Tim_Icu_Drv_IdType InstId)
{
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    if ((1U == TIMx->TIM_GLBSR.TOF) && (1U == TIMx->TIM_GLBCR.TOIE))
    {
        TIMWx->TIM_GLBSR = 0x1FFU;
        Tim_Icu_Drv_LocalVofProcess(InstId);
    }
}
/**
 * @brief      This function disable overflow interrupt
 * 
 * @param[in]  InstId: Number of instances to be configured
 * 
 * @return none
 *
 */    
void Tim_Icu_Drv_DisableOverflowInt(Tim_Icu_Drv_IdType InstId)
{
    Reg_Tim_BfType * TIMx;
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMx->TIM_GLBCR.TOIE = 0U;
    SchM_Exit_Icu_TimSetChannelModeCfg();
}
/**
 * @brief      This function enable overflow interrupt
 * 
 * @param[in]  InstId: Number of instances to be configured
 * 
 * @return none
 *
 */    
void Tim_Icu_Drv_EnableOverflowInt(Tim_Icu_Drv_IdType InstId)
{
    Reg_Tim_BfType * TIMx;
    Reg_Tim_WType * TIMWx;
    TIMWx = Tim_Icu_Drv_IcuRegWPtr[InstId];
    TIMx = Tim_Icu_Drv_IcuRegBfPtr[InstId];
    TIMWx->TIM_GLBSR = 0x1FFU;
    SchM_Enter_Icu_TimSetChannelModeCfg();
    TIMx->TIM_GLBCR.TOIE = 1U;
    SchM_Exit_Icu_TimSetChannelModeCfg();
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu_Drv */
/** @} end of group Icu_Module */

