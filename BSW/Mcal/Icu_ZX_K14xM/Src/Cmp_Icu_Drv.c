/**************************************************************************************************/
/**
 * @file      : Cmp_Icu_Drv.c
 * @brief     : AUTOSAR Cmp Icu hardware driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Cmp_Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Cmp_Icu_Drv.h"
#include "Device_Regs.h"
#include "SchM_Icu.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CMP_ICU_DRV_C_VENDOR_ID                   0x00B3U
#define CMP_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define CMP_ICU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define CMP_ICU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define CMP_ICU_DRV_C_SW_MAJOR_VERSION            1U
#define CMP_ICU_DRV_C_SW_MINOR_VERSION            2U
#define CMP_ICU_DRV_C_SW_PATCH_VERSION            1U

#if (CMP_ICU_DRV_C_VENDOR_ID != CMP_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Cmp_Icu_Drv.c and Cmp_Icu_Drv.h have different"
#endif

#if (CMP_ICU_DRV_C_AR_RELEASE_REVISION_VERSION != CMP_ICU_DRV_H_AR_RELEASE_REVISION_VERSION)
    #error "Vendor ID Cmp_Icu_Drv.c and Cmp_Icu_Drv.h have different"
#endif

#if (CMP_ICU_DRV_C_SW_PATCH_VERSION != CMP_ICU_DRV_H_SW_PATCH_VERSION)
    #error "Vendor ID Cmp_Icu_Drv.c and Cmp_Icu_Drv.h have different"
#endif

#if ((CMP_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (CMP_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Cmp_Icu_Drv.c and Cmp_Icu_Drv.h are different"
#endif

#if ((CMP_ICU_DRV_C_SW_MAJOR_VERSION != CMP_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (CMP_ICU_DRV_C_SW_MINOR_VERSION != CMP_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Cmp_Icu_Drv.c and Cmp_Icu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((CMP_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||     \
         (CMP_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Cmp_Icu_Drv.c and Device_Regs.h are different"
    #endif

    #if ((CMP_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_ICU_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (CMP_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_ICU_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Cmp_Icu_Drv.c and SchM_Icu.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

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
 *  @brief CMP0 address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type, 
no side effects forseen by violating this rule. */
static Reg_Cmp_BfType *const Cmp_Icu_Drv_IcuRegBfPtr[CMP_ICU_DRV_INSTANCE_SUMCNT] = 
{
   (Reg_Cmp_BfType *)CMP_BASE_ADDR
};

/**
 *  @brief CMP0 address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type, 
no side effects forseen by violating this rule. */
static Reg_Cmp_WType *const Cmp_Icu_Drv_IcuRegWPtr[CMP_ICU_DRV_INSTANCE_SUMCNT] = 
{
   (Reg_Cmp_WType *)CMP_BASE_ADDR
};

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

static Cmp_Icu_Drv_ChannelStateType Cmp_Icu_Drv_ChState[CMP_ICU_DRV_INSTANCE_SUMCNT];
static Cmp_Icu_Drv_InstanceStateType Cmp_Icu_Drv_InstState[CMP_ICU_DRV_INSTANCE_SUMCNT];

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

LOCAL_INLINE Cmp_Icu_Drv_ChannelStateType * Cmp_Icu_Drv_GetLocalChannelState(
                                                                Cmp_Icu_Drv_IdType InstId)
{
    return (&Cmp_Icu_Drv_ChState[InstId]);
}

LOCAL_INLINE Cmp_Icu_Drv_InstanceStateType * Cmp_Icu_Drv_GetLocalInstanceState(Cmp_Icu_Drv_IdType InstId)
{
    return (&Cmp_Icu_Drv_InstState[InstId]);
}

#if (STD_ON == CMP_ICU_DRV_EDGE_DETECT_API)
LOCAL_INLINE void Cmp_Icu_Drv_ClrLocalIntFlag(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType *CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    CMPx->CMP_CSR.CFR = 1U;
    CMPx->CMP_CSR.CFF = 1U;
}
#endif

#if (STD_ON == CMP_ICU_DRV_EDGE_DETECT_API)
LOCAL_INLINE void Cmp_Icu_Drv_LocalNotifyEvent(Cmp_Icu_Drv_IdType InstId)
{
    const Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);

    if(NULL_PTR != ChStatePtr->CallbackFun)
    {
        ChStatePtr->CallbackFun(ChStatePtr->CallbackParam, FALSE);
    }
    else
    {
        if ((TRUE == ChStatePtr->NotifyEnable) && (NULL_PTR != ChStatePtr->ChNotificationFun))
        {
            ChStatePtr->ChNotificationFun();
        }
    }
}
#endif

#if (STD_ON == CMP_ICU_DRV_DEINIT_API)
LOCAL_INLINE void Cmp_Icu_Drv_LocalClearChannelState(Cmp_Icu_Drv_IdType InstId)
{
    Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);

    ChStatePtr->ActiveEdge = CMP_ICU_DRV_INPUT_DISABLED;
    ChStatePtr->CallbackFun = NULL_PTR;
    ChStatePtr->ChNotificationFun = NULL_PTR;
    ChStatePtr->CallbackParam = 0U;
}
#endif

LOCAL_INLINE void Cmp_Icu_Drv_LocalDacConfig(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;
    
    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    const Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);

    CMPx->CMP_DCR.VREF_SEL = (uint32)(ChStatePtr->DacVref);
    CMPx->CMP_DCR.DAC_EN = (uint32)(ChStatePtr->DacConfig);
    CMPx->CMP_DCR.DAC_SEL = (uint32)(ChStatePtr->DacOutputVoltageConfig);
}

LOCAL_INLINE void Cmp_Icu_Drv_LocalSpeedInitConfig(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;
    
    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    const Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);

    CMPx->CMP_CCR0.CMP_SEL = (uint32)(ChStatePtr->Speed);

    if(CMP_ICU_DRV_SPEED_LOW == ChStatePtr->Speed)
    {
        CMPx->CMP_CCR2.LS_HSTCTR = (uint32)(ChStatePtr->HystSpeedLevel);
        CMPx->CMP_CCR2.LS_PSEL = (uint32)(ChStatePtr->PInput);
        CMPx->CMP_CCR2.LS_MSEL = (uint32)(ChStatePtr->NInput);
    }
    else
    {
        CMPx->CMP_CCR2.HS_HSTCTR = (uint32)(ChStatePtr->HystSpeedLevel);
        CMPx->CMP_CCR2.HS_PSEL = (uint32)(ChStatePtr->PInput);
        CMPx->CMP_CCR2.HS_MSEL = (uint32)(ChStatePtr->NInput);
    }
}

LOCAL_INLINE void Cmp_Icu_Drv_LocalTriggerConfig(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;
    
    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    const Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);

    if(CMP_ICU_DRV_SW_TRIGGER == ChStatePtr->Trigger)
    {
        CMPx->CMP_CCR0.CMP_EN = 1U;
        CMPx->CMP_CCR0.SOC_TRG_EN = 0U;
    }
    else
    {
        CMPx->CMP_CCR0.CMP_EN = 0U;
        CMPx->CMP_CCR0.SOC_TRG_EN = 1U;
    }   
}

#if (STD_ON == CMP_ICU_DRV_DEINIT_API)
LOCAL_INLINE void Cmp_Icu_Drv_LocalDeInitConfig(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;
    
    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    CMPx->CMP_DCR.DAC_EN = 0U;
    CMPx->CMP_IER.CFR_IE = 0U;
    CMPx->CMP_IER.CFF_IE = 0U;
}
#endif

/**
 * @brief      Config window mode parameter
 *
 * @param[in]  WinOutLvl: Select the output level when window is closed
 *
 * @return     None
 *
 */ 
LOCAL_INLINE void Cmp_Icu_Drv_LocalWindowConfig(Cmp_Icu_Drv_IdType InstId, 
                              Cmp_Icu_Drv_WinOutLvlType WinOutLvl)
{
    Reg_Cmp_BfType * CMPx;
    
    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    if(CMP_ICU_DRV_WIN_OUT_LVL_LAST == WinOutLvl)
    {
        CMPx->CMP_CCR1.COUT_OWE = 0U;
    }
    else
    {
        CMPx->CMP_CCR1.COUT_OWE = 1U;
        CMPx->CMP_CCR1.COUT_OW = ((uint32)(WinOutLvl) >> 1U);
    }
}

LOCAL_INLINE void Cmp_Icu_Drv_LocalInitConfig(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;
    const Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);
    Cmp_Icu_Drv_LocalDacConfig(InstId);

    /* default cout after filter */
    CMPx->CMP_CCR1.COUT_SEL = 0U;
    
    CMPx->CMP_CCR0.STOP_EN = 0U;
    /* select DMA / interrupt request */
    CMPx->CMP_CCR1.DMA_EN = 0U;
    /* invert output or not */
    CMPx->CMP_CCR1.COUT_INV = 0U;
    /* output to pad or not */
    CMPx->CMP_CCR1.COUT_PEN = 1U;  

    /* config working mode */
    switch(ChStatePtr->Mode)
    {
        case CMP_ICU_DRV_BASIC_MODE:
            CMPx->CMP_CCR1.WINDOW_EN = 0U;
            CMPx->CMP_CCR1.SAMPLE_EN = 1U;
            CMPx->CMP_CCR1.FILT_PER = 0U;

            break;
        
        case CMP_ICU_DRV_WINDOW_MODE:

            CMPx->CMP_CCR1.WINDOW_EN = 1U;
            CMPx->CMP_CCR1.SAMPLE_EN = 0U;
            CMPx->CMP_CCR1.FILT_CNT = (uint32)CMP_ICU_DRV_FILTER_BYPASSED;
            CMPx->CMP_CCR1.FILT_PER = 0U;
            Cmp_Icu_Drv_LocalWindowConfig(InstId, ChStatePtr->WinOutLvl);
            break;
        
        case CMP_ICU_DRV_FILTER_MODE:

            CMPx->CMP_CCR1.WINDOW_EN = 0U;
            CMPx->CMP_CCR1.SAMPLE_EN = 0U;

            CMPx->CMP_CCR1.FILT_CNT = (uint32)(ChStatePtr->FilterSampleCount);
            CMPx->CMP_CCR1.FILT_PER = (uint32)(ChStatePtr->CmpFilterSamplePeriod);
            break;
        
        case CMP_ICU_DRV_SAMPLE_MODE:

            CMPx->CMP_CCR1.WINDOW_EN = 0U;
            CMPx->CMP_CCR1.SAMPLE_EN = 1U;
            CMPx->CMP_CCR1.FILT_CNT = (uint32)CMP_ICU_DRV_FILTER_1_CONSECUTIVE_SAMPLE;
            CMPx->CMP_CCR1.FILT_PER = 0U;

            CMPx->CMP_CCR1.COUT_SEL = (uint32)(ChStatePtr->OutputCfg); 
            break;
        
        case CMP_ICU_DRV_WINDOW_FILTER_MODE:
            CMPx->CMP_CCR1.WINDOW_EN = 1U;
            CMPx->CMP_CCR1.SAMPLE_EN = 0U;

            CMPx->CMP_CCR1.FILT_CNT = (uint32)(ChStatePtr->FilterSampleCount);
            CMPx->CMP_CCR1.FILT_PER = (uint32)(ChStatePtr->CmpFilterSamplePeriod);
            CMPx->CMP_CCR1.COUT_SEL = (uint32)(ChStatePtr->WinOutLvl);
            Cmp_Icu_Drv_LocalWindowConfig(InstId, ChStatePtr->WinOutLvl);

            break;
            
        default:
            /*do nothing*/
            break;
    }
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
 * @param[in]  CmpIcuInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
Cmp_Icu_Drv_StatusType Cmp_Icu_Drv_Init(Cmp_Icu_Drv_IdType InstId, 
                                          const Cmp_Icu_Drv_InstanceConfigType * CmpIcuInstCfgPtr)
{
    const Cmp_Icu_Drv_ChannelConfigType * ChCfgPtr;
    Cmp_Icu_Drv_ChannelStateType * ChStatePtr;
    Cmp_Icu_Drv_InstanceStateType * InstStatePtr;

    Cmp_Icu_Drv_StatusType RetVal = CMP_ICU_DRV_STATUS_SUCCESS;

    InstStatePtr = Cmp_Icu_Drv_GetLocalInstanceState(InstId);

    if (FALSE == InstStatePtr->InstInitFlag)
    {
        ChCfgPtr = &(*CmpIcuInstCfgPtr->ChCfgPtr)[InstId];
        ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);

        ChStatePtr->CallbackFun = ChCfgPtr->CallbackFun;
        ChStatePtr->CallbackParam = ChCfgPtr->CallbackParam;
        ChStatePtr->ActiveEdge = ChCfgPtr->ActiveEdge;          
        ChStatePtr->Mode = ChCfgPtr->Mode;
        ChStatePtr->FilterSampleCount = ChCfgPtr->FilterSampleCount;
        ChStatePtr->HystSpeedLevel = ChCfgPtr->HystSpeedLevel;
        ChStatePtr->Speed = ChCfgPtr->Speed;
        ChStatePtr->PInput = ChCfgPtr->PInput;
        ChStatePtr->NInput = ChCfgPtr->NInput;
        ChStatePtr->DacVref = ChCfgPtr->DacVref;
        ChStatePtr->CmpFilterSamplePeriod = ChCfgPtr->CmpFilterSamplePeriod;
        ChStatePtr->Trigger = ChCfgPtr->Trigger;
        ChStatePtr->DacConfig = ChCfgPtr->DacConfig;
        ChStatePtr->DacOutputVoltageConfig = ChCfgPtr->DacOutputVoltageConfig;
        ChStatePtr->ChNotificationFun = ChCfgPtr->ChNotificationFun;
        
        Cmp_Icu_Drv_LocalSpeedInitConfig(InstId);

        Cmp_Icu_Drv_LocalInitConfig(InstId);

        Cmp_Icu_Drv_LocalTriggerConfig(InstId);
        InstStatePtr->InstInitFlag = (boolean)TRUE;
    }
    else
    {
        RetVal = CMP_ICU_DRV_STATUS_ERROR;
    }
    
    return RetVal;
}

#if (STD_ON == CMP_ICU_DRV_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
Cmp_Icu_Drv_StatusType Cmp_Icu_Drv_DeInit (Cmp_Icu_Drv_IdType InstId)
{
    Cmp_Icu_Drv_InstanceStateType * InstStatePtr;
    
    Cmp_Icu_Drv_StatusType RetVal = CMP_ICU_DRV_STATUS_SUCCESS;
    
    InstStatePtr = Cmp_Icu_Drv_GetLocalInstanceState(InstId);

    if (TRUE == InstStatePtr->InstInitFlag)
    {
        Cmp_Icu_Drv_LocalDeInitConfig(InstId);
        InstStatePtr->InstInitFlag = (boolean)FALSE;
        InstStatePtr->ChfClrMask = 0U;

        Cmp_Icu_Drv_LocalClearChannelState(InstId);
    }
    else
    {
        RetVal = CMP_ICU_DRV_STATUS_ERROR;
    }
    
    return RetVal;

}
#endif

/**
 * @brief      The function that sets up the activation condition
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  ActiveEdge: edge activation type used 
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_SetActivationCondition(Cmp_Icu_Drv_IdType InstId,  
                                                   Cmp_Icu_Drv_EdgeAlignmentModeType ActiveEdge)
{
    Reg_Cmp_WType * CMPWx;
    Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    CMPWx = Cmp_Icu_Drv_IcuRegWPtr[InstId];

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);
    SchM_Enter_Icu_CmpSetActiveEdge();

    ChStatePtr->ActiveEdge = ActiveEdge;

    CMPWx->CMP_IER = (uint32)ActiveEdge;
    SchM_Exit_Icu_CmpSetActiveEdge();

}

/**
 * @brief      The function disable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_DisableNotification(Cmp_Icu_Drv_IdType InstId)
{
    Cmp_Icu_Drv_ChannelStateType * ChStatePtr;
    SchM_Enter_Icu_CmpSetChannelState();
    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);
    ChStatePtr->NotifyEnable = (boolean)FALSE;
    SchM_Exit_Icu_CmpSetChannelState();
}

/**
 * @brief      The function enable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_EnableNotification(Cmp_Icu_Drv_IdType InstId)
{
    Cmp_Icu_Drv_ChannelStateType * ChStatePtr;
    SchM_Enter_Icu_CmpSetChannelState();
    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);
    ChStatePtr->NotifyEnable = (boolean)TRUE;
    SchM_Exit_Icu_CmpSetChannelState();
}

#if (STD_ON == CMP_ICU_DRV_GET_INPUT_STATE_API)
/**
 * @brief      The function get input state of the Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return input state
 *
 */
boolean Cmp_Icu_Drv_GetInputState(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;
    boolean RetVal = (boolean)FALSE;

    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];
    SchM_Enter_Icu_CmpGetInputState();
    if (1U == CMPx->CMP_IER.CFR_IE)
    {
        if ((0U != CMPx->CMP_CSR.CFR))
        {
            RetVal = (boolean)TRUE;

            CMPx->CMP_CSR.CFR = 1U;
        }
    }
    
    if(1U == CMPx->CMP_IER.CFF_IE)
    {
        if ((0U != CMPx->CMP_CSR.CFF))
        {
            RetVal = (boolean)TRUE;

            CMPx->CMP_CSR.CFF = 1U;
        }
    }
    SchM_Exit_Icu_CmpGetInputState();
    return RetVal;
}
#endif

#if (STD_ON == CMP_ICU_DRV_EDGE_DETECT_API)
/**
 * @brief      This function enable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_EnableEdgeDetection(Cmp_Icu_Drv_IdType InstId)
{
    const Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);
    
    Cmp_Icu_Drv_ClrLocalIntFlag(InstId);
    Cmp_Icu_Drv_SetActivationCondition(InstId, ChStatePtr->ActiveEdge);
}

/**
 * @brief      This function disable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_DisableEdgeDetection(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;

    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];
    SchM_Enter_Icu_CmpSetActiveEdge();

    CMPx->CMP_IER.CFR_IE = 0U;
    CMPx->CMP_IER.CFF_IE = 0U; 
    CMPx->CMP_CSR.CFR = 1U;
    CMPx->CMP_CSR.CFF = 1U;   
    SchM_Exit_Icu_CmpSetActiveEdge();
}
#endif

#if (STD_ON == CMP_ICU_DRV_SET_MODE_API)
/**
 * @brief      Sets hardware Channel into SLEEP mode
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_SetChannelSleepMode(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;

    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];
    SchM_Enter_Icu_CmpSetActiveEdge();

    CMPx->CMP_IER.CFR_IE = 0U;
    CMPx->CMP_IER.CFF_IE = 0U;
    CMPx->CMP_CSR.CFR = 1U;
    CMPx->CMP_CSR.CFF = 1U;       
    SchM_Exit_Icu_CmpSetActiveEdge();
}

/**
 * @brief      Sets hardware Channel into NORMAL mode
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_SetChannelNormalMode(Cmp_Icu_Drv_IdType InstId)
{
    Reg_Cmp_BfType * CMPx;
    Cmp_Icu_Drv_EdgeAlignmentModeType ActiveEdge;
    const Cmp_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Cmp_Icu_Drv_GetLocalChannelState(InstId);

    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];
    
    ActiveEdge = ChStatePtr->ActiveEdge;
    if (CMP_ICU_DRV_INPUT_DISABLED != ActiveEdge)
    {
        Cmp_Icu_Drv_SetActivationCondition((Cmp_Icu_Drv_IdType)InstId, ChStatePtr->ActiveEdge);
    }

    CMPx->CMP_CSR.CFR = 1U;
    CMPx->CMP_CSR.CFF = 1U; 
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
void Cmp_Icu_Drv_ChIntHandler(Cmp_Icu_Drv_IdType InstId)
{

    Reg_Cmp_BfType * CMPx;
    CMPx = Cmp_Icu_Drv_IcuRegBfPtr[InstId];

    if ((0U != CMPx->CMP_CSR.CFR))
    {
        CMPx->CMP_CSR.CFR = 1U;
    }

    if ((0U != CMPx->CMP_CSR.CFF))
    {
        CMPx->CMP_CSR.CFF = 1U;
    }
#if (STD_ON == CMP_ICU_DRV_EDGE_DETECT_API)
    Cmp_Icu_Drv_LocalNotifyEvent(InstId);
#endif
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu_Drv */
/** @} end of group Icu_Module */

