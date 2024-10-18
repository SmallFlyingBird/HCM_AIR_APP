/**************************************************************************************************/
/**
 * @file      : Tim_Ocu_Drv.c
 * @brief     : Ocu low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Tim_Ocu_Drv
 *  @brief Ocu driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tim_Ocu_Drv.h"
#include "SchM_Ocu.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_OCU_DRV_C_VENDOR_ID                   0x00B3U
#define TIM_OCU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_OCU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_OCU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_OCU_DRV_C_SW_MAJOR_VERSION            1U
#define TIM_OCU_DRV_C_SW_MINOR_VERSION            2U
#define TIM_OCU_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Tim_Ocu_Drv.h are of the same vendor */
#if (TIM_OCU_DRV_C_VENDOR_ID != TIM_OCU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Tim_Ocu_Drv.c and Tim_Ocu_Drv.h are different"
#endif

/* Check if  source file and Tim_Ocu_Drv.h file are of the same Autosar version */
#if ((TIM_OCU_DRV_C_AR_RELEASE_MAJOR_VERSION != TIM_OCU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (TIM_OCU_DRV_C_AR_RELEASE_MINOR_VERSION != TIM_OCU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (TIM_OCU_DRV_C_AR_RELEASE_REVISION_VERSION != TIM_OCU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tim_Ocu_Drv.c and Tim_Ocu_Drv.h are different"
#endif

/* Check if source file and Tim_Ocu_Drv.h file are of the same Software version */
#if ((TIM_OCU_DRV_C_SW_MAJOR_VERSION != TIM_OCU_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (TIM_OCU_DRV_C_SW_MINOR_VERSION != TIM_OCU_DRV_H_SW_MINOR_VERSION) ||                                 \
     (TIM_OCU_DRV_C_SW_PATCH_VERSION != TIM_OCU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Ocu_Drv.c and Tim_Ocu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((TIM_OCU_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||     \
         (TIM_OCU_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Ocu_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if this source file and SchM_Ocu.h file are of the same Autosar version */
    #if ((TIM_OCU_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_OCU_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (TIM_OCU_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_OCU_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Ocu_Drv.c and SchM_Ocu.h are different"
    #endif
#endif

/**
 *@brief TIM instance number
 */
#define TIM_OCU_DRV_INSTANCE_COUNT 0x4U
/** @} end of Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define OCU_START_SEC_VAR_CLEARED_PTR
#include "Ocu_MemMap.h"
/**
 * @brief pointer to TIM config structures
 */
#define OCU_STOP_SEC_VAR_CLEARED_PTR
static const Tim_Ocu_Drv_ModuleConfigType *Tim_Ocu_Drv_ConfigPtr;
#include "Ocu_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define OCU_START_SEC_CONST_PTR
#include "Ocu_MemMap.h"
/**
 *  @brief TIM0, TIM1, TIM2 TIM3 address array
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason. */
static Reg_Tim_BfType *const Tim_Ocu_Drv_OcuRegBfPtr[TIM_OCU_DRV_INSTANCE_COUNT] = {
    (Reg_Tim_BfType *)TIM0_BASE_ADDR, /* TIM0 base address */
    (Reg_Tim_BfType *)TIM1_BASE_ADDR, /* TIM1 base address */
    (Reg_Tim_BfType *)TIM2_BASE_ADDR, /* TIM2 base address */
    (Reg_Tim_BfType *)TIM3_BASE_ADDR  /* TIM3 base address */
};

/**
 *  @brief TIM0, TIM1, TIM2 TIM3 address array
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason. */
static Reg_Tim_WType *const Tim_Ocu_Drv_OcuRegWPtr[TIM_OCU_DRV_INSTANCE_COUNT] = {
    (Reg_Tim_WType *)TIM0_BASE_ADDR, /* TIM0 base address */
    (Reg_Tim_WType *)TIM1_BASE_ADDR, /* TIM1 base address */
    (Reg_Tim_WType *)TIM2_BASE_ADDR, /* TIM2 base address */
    (Reg_Tim_WType *)TIM3_BASE_ADDR  /* TIM3 base address */
};

#define OCU_STOP_SEC_CONST_PTR
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

#if (TIM_OCU_DRV_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief Global array variable describe the notification information of channels
 */
static Tim_Ocu_Drv_ChStateType Tim_Ocu_Drv_NoticeChState[TIM_OCU_DRV_TIM_INSTANCE_COUNT][TIM_OCU_DRV_TIM_CHANNEL_COUNT];
#endif

#define OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_INIT_32
#include "Ocu_MemMap.h"

/**
 * @brief Variable storing the current state of the TIM module
 */
static Tim_Ocu_Drv_GlobalDrvStateType Tim_Ocu_Drv_GlobalState = TIM_OCU_DRV_STATE_UNINIT;

#define OCU_STOP_SEC_VAR_INIT_32
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_CLEARED_32
#include "Ocu_MemMap.h"

/**
 * @brief Variable storing the state of each OCU channel.
 */
static Tim_Ocu_Drv_ChannelStateType Tim_Ocu_Drv_ChannelState[TIM_OCU_DRV_TIM_INSTANCE_COUNT]
                                                       [TIM_OCU_DRV_TIM_CHANNEL_COUNT];

/**
 * @brief Variable storing the pin used state of each OCU channel.
 */
static Tim_Ocu_Drv_ChannelPinUseType Tim_Ocu_Drv_ChannelPinUsedState[TIM_OCU_DRV_TIM_INSTANCE_COUNT]
                                                              [TIM_OCU_DRV_TIM_CHANNEL_COUNT];

#define OCU_STOP_SEC_VAR_CLEARED_32
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_CLEARED_8
#include "Ocu_MemMap.h"

/**
 * @brief Variable storing the pin action state of each OCU channel.
 */
static uint8 Tim_Ocu_Drv_PinAction[TIM_OCU_DRV_TIM_INSTANCE_COUNT][TIM_OCU_DRV_TIM_CHANNEL_COUNT];

#define OCU_STOP_SEC_VAR_CLEARED_8
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_CLEARED_16
#include "Ocu_MemMap.h"

/**
 * @brief  Variable storing the max counter value of each OCU channel.
 */
static uint16 Tim_Ocu_Drv_MaxCounterValue[TIM_OCU_DRV_TIM_INSTANCE_COUNT][TIM_OCU_DRV_TIM_CHANNEL_COUNT];
static uint16 Tim_Ocu_Drv_ModuleMaxCounterValue[TIM_OCU_DRV_TIM_INSTANCE_COUNT];

#define OCU_STOP_SEC_VAR_CLEARED_16
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

static Tim_Ocu_Drv_InstanceClockType Tim_Ocu_Drv_InstanceClockInfo[TIM_OCU_DRV_TIM_INSTANCE_COUNT];

#define OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief      Service to process channel property.
 * 
 * @param[in]  InstNum: Instance number
 * @param[in]  ChNum: Channel number
 * @param[in]  ChLoopIdx: Loop channel number
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ProcessChannel(uint8 *InstNum, uint8 *ChNum, uint8 ChLoopIdx);

/**
 * @brief      Service to check pin set action.
 * 
 * @param[in]  InstNum: Instance number
 * @param[in]  ChNum: Channel number
 * @param[in]  PinAction: Pin set action
 *
 * @return     None
 */
static uint8 Tim_Ocu_Drv_CheckPinAction(uint8 PinAction, uint8 InstNum, uint8 ChNum);

/**
 * @brief      Service to ocu drv clear counter info.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ClearCounterInfo(void);

/**
 * @brief      Service to ocu drv start counter.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_StartCounter(void);

/**
 * @brief      Service to ocu drv channel init.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ChannelInit(void);

/**
 * @brief      Service to ocu drv instance init.
 * 
 * @param[in]  TimInstanceConfigPtr: OCU driver tim instance config
 *
 * @return     None
 */
static void Tim_Ocu_Drv_InstanceInit(const Tim_Ocu_Drv_TimConfigType * TimInstanceConfigPtr);

/**
 * @brief      Service to ocu drv module init.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ModuleInit(void);

/**
 * @brief      Service to ocu drv channel deinit.
 * 
 * @param[in]  void
 * 
 * @return     None
 */
static void Tim_Ocu_Drv_ChannelDeInit(void);

/**
 * @brief      Service to ocu drv instance deinit.
 * 
 * @param[in]  TimInstanceConfigPtr: OCU driver tim instance config
 *
 * @return     None
 */
static void Tim_Ocu_Drv_InstanceDeInit(const Tim_Ocu_Drv_TimConfigType *TimInstanceConfigPtr);

/**
 * @brief      Service to ocu drv module deinit.
 * 
 * @param[in]  void
 * 
 * @return     None
 */
static void Tim_Ocu_Drv_ModuleDeInit(void);

/**
 * @brief      Service to process channel set.
 * 
 * @param[in]  InstNum: Instance number
 * @param[in]  ChNum: Channel number
 * @param[in]  ChannelSet: Channel set
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Tim_Ocu_Drv_CheckChannelSet(uint8 InstNum, uint8 ChNum, uint8 ChannelSet);

/**
 * @brief      Service to judge whether the next match was in the given interval.
 * 
 * @param[in]  PostCmWriteValue: Compare match value
 * @param[in]  StartIntervalValue: Start value of this cycle
 * @param[in]  EndIntervalValue: End value of this cycle
 *
 * @return     Tim_Ocu_Drv_ReturnType
 * @retval     TIM_OCU_DRV_IN_INTERVAL:  compare match was in the given interval
 * @retval     TIM_OCU_DRV_OUT_INTERVAL: compare match was out of the given interval
 */
static Tim_Ocu_Drv_ReturnType Tim_Ocu_Drv_DetermineNextCmStatus(Tim_Ocu_Drv_ValueType PostCmWriteValue,
                                                        Tim_Ocu_Drv_ValueType StartIntervalValue,
                                                        Tim_Ocu_Drv_ValueType EndIntervalValue);
#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"
/**
 * @brief      Service to process channel property.
 * 
 * @param[in]  InstNum: Instance number
 * @param[in]  ChNum: Channel number
 * @param[in]  ChLoopIdx: Loop channel number
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ProcessChannel(uint8 *InstNum, uint8 *ChNum, uint8 ChLoopIdx)
{
    /* Pointer to TIM channel configuration */
    const Tim_Ocu_Drv_ChannelConfigType *TimChannelConfigPtr = NULL_PTR;
    /* Get pointer to configuration of TIM channel */
    TimChannelConfigPtr = &(*Tim_Ocu_Drv_ConfigPtr->ChannelsConfig)[ChLoopIdx];

    /* Get TIM channel and instance numbers from Hw Channel Id */
    *InstNum = Tim_Ocu_Drv_GetInstanceNum(TimChannelConfigPtr->OcuHwChannel);
    *ChNum = Tim_Ocu_Drv_GetChannelNum(TimChannelConfigPtr->OcuHwChannel);
}

/**
 * @brief      Service to check pin set action.
 * 
 * @param[in]  InstNum: Instance number
 * @param[in]  ChNum: Channel number
 * @param[in]  PinAction: Pin set action
 *
 * @return     None
 */
static uint8 Tim_Ocu_Drv_CheckPinAction(uint8 PinAction, uint8 InstNum, uint8 ChNum)
{
    uint8 RegEls;
    switch (PinAction)
    {
        case (uint8)TIM_OCU_DRV_SET_LOW:
        {
            Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_LOW;
            RegEls = 2U;
            break;
        }
        case (uint8)TIM_OCU_DRV_SET_HIGH:
        {
            Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_HIGH;
            RegEls = 3U;
            break;
        }
        case (uint8)TIM_OCU_DRV_SET_TOGGLE:
        {
            Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_TOGGLE;
            RegEls = 1U;
            break;
        }
        default:
        {
            Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_DISABLE;
            RegEls = 0U;
            break;
        }
    }
    return RegEls;
}

/**
 * @brief      Service to ocu drv stop counter.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ClearCounterInfo(void)
{
    uint8 InstNum;
    for (InstNum = 0U; InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT; InstNum++)
    {
        Tim_Ocu_Drv_InstanceClockInfo[InstNum].InstanceClockDivide = (uint8)TIM_OCU_DRV_CS_DIV1_U32;
        Tim_Ocu_Drv_InstanceClockInfo[InstNum].InstanceClockSource = (uint8)TIM_OCU_DRV_CLOCK_SOURCE_NONE;
    }
}

/**
 * @brief      Service to ocu drv start counter.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_StartCounter(void)
{
    uint8 InstNum;
    Reg_Tim_BfType *TIMx = NULL_PTR;
    for (InstNum = 0U; InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT; InstNum++)
    {
        TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
        if (TIM_OCU_DRV_CLOCK_SOURCE_NONE != Tim_Ocu_Drv_InstanceClockInfo[InstNum].InstanceClockSource)
        {
            /* If write protection is enabled, then disable it. */
            if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
            {
                /* Disable write protection */
                TIMx->TIM_GLBSR.WPDIS = 1U;
            }
            TIMx->TIM_TIMEBASE.PSDIV = (uint32)Tim_Ocu_Drv_InstanceClockInfo[InstNum].InstanceClockDivide;
            TIMx->TIM_TIMEBASE.CKSRC = (uint32)Tim_Ocu_Drv_InstanceClockInfo[InstNum].InstanceClockSource;
            /* Enable write protection */
            TIMx->TIM_FLTSR.WPEN = (uint32)1U; 
        }
    }
}

/**
 * @brief      Service to ocu drv channel init.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ChannelInit(void)
{
    /* Channel index used in the loop */
    uint8 ChLoopIdx; 
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    uint8 ChPairNum;
    uint8 PinAction; /* Store pin action from configured data */
    Reg_Tim_BfType *TIMx = NULL_PTR;
    Reg_Tim_WType  *TIMw = NULL_PTR;
    /* Pointer to TIM channel configuration */
    const Tim_Ocu_Drv_ChannelConfigType *TimChannelConfigPtr = NULL_PTR;
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
    /* Loop all TIM channels and perform Init actions */
    for (ChLoopIdx = 0U; ChLoopIdx < (Tim_Ocu_Drv_ConfigPtr->NumChannels); ++ChLoopIdx)
    {
        Tim_Ocu_Drv_ProcessChannel(&InstNum, &ChNum, ChLoopIdx);
        TimChannelConfigPtr = &(*Tim_Ocu_Drv_ConfigPtr->ChannelsConfig)[ChLoopIdx];
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
        MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif

        TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
        TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];
        /* If write protection is enabled, then disable it. */
        if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
        {
            /* Disable write protection */
            TIMx->TIM_GLBSR.WPDIS = 1U;
        }

        /* Initialize the channels output */
        TIMx->TIM_GLBCR.INIT = (uint32)1U;
        /* Configure MODE */
        TIMx->TIM_GLBCR.RLDIE = (uint32)0U;

        /* Store the max counter value */
        Tim_Ocu_Drv_MaxCounterValue[InstNum][ChNum] = Tim_Ocu_Drv_ModuleMaxCounterValue[InstNum];

        /*clear CHF bit*/
        TIMx->TIM_CMCn[ChNum].CHF = (uint32)0U;
        /* disable Channel Interrupt CHIE for the given channel */
        TIMx->TIM_CMCn[ChNum].CHIE = (uint32)0U;

        /* Disable output on the TIM channel */
        TIMw->TIM_GLBCR &= ~(1UL << ChNum);

        /* Clear the POL bits */
        TIMw->TIM_OUTCR &= ~(((uint32)1U) << (ChNum + TIM_OCU_DRV_OUTCTRL_POL_SHIFT_U8));

        /* Set this channel output compare mode */
        TIMx->TIM_CMCn[ChNum].CMS = (uint32)1U;
        /* Set DMA trigger */
        TIMx->TIM_CMCn[ChNum].DMAEN = (uint32)TimChannelConfigPtr->PinDMATrigger;

        /* Set the compare value */
        TIMx->TIM_CCVn[ChNum].CCV = (uint32)TimChannelConfigPtr->DefaultThreshold;

        /* Configure default PIN Action behaviour and initialize the array used to store
        pin action */
        PinAction = (uint8)TimChannelConfigPtr->PinAction;
        TIMx->TIM_CMCn[ChNum].ELS = Tim_Ocu_Drv_CheckPinAction(PinAction, InstNum, ChNum);

        /* disable TIM Pairs of Channel Control Register */
        if (0U == (ChNum & 0x01U))
        {
            ChPairNum = (ChNum >> 1U);
            TIMw->TIM_PCR &= ~(((uint32)(0x30U)) << (ChPairNum * (8U)));
            TIMw->TIM_PCR &= ~(((uint32)(0x4U)) << (ChPairNum * (8U)));
            TIMw->TIM_PCR &= ~(((uint32)(0x8U)) << (ChPairNum * (8U)));
            TIMw->TIM_PCR &= ~(((uint32)(0x2U)) << (ChPairNum * (8U)));
        }
            
        /* If pin is used, it should be enter software control mode */
        if (0U != TimChannelConfigPtr->PinUsedState)
        {
            /* Initialize global pin data for current channel*/
            Tim_Ocu_Drv_ChannelPinUsedState[InstNum][ChNum] = TIM_OCU_DRV_CH_PIN_USED;
            /* Setting forced value for current channel*/
            TIMw->TIM_OUTSWCR |= ((uint32)TimChannelConfigPtr->DefaultPinState)
                        << (ChNum + TIM_OCU_DRV_OUTSWCR_FORCED_VALUE_OFFSET);
            /* Enable software output control */
            TIMw->TIM_OUTSWCR |= ((uint32)1U) << (ChNum);
        }

        /* Clears the channel event status */
        TIMx->TIM_GLBSR.RLDF = (uint32)0U;
        TIMx->TIM_GLBSR.TOF = (uint32)0U;

#if (TIM_OCU_DRV_NOTIFICATION_SUPPORTED == STD_ON)
        Tim_Ocu_Drv_NoticeChState[InstNum][ChNum].ChannelIsInit = TRUE;
        Tim_Ocu_Drv_NoticeChState[InstNum][ChNum].CallBackFunc =
                TimChannelConfigPtr->CallBackFunc;
#endif

        /* Disable the timer overflow interrupt and Fault interrupt */
        TIMx->TIM_GLBCR.TOIE = (uint32)0U;
        TIMx->TIM_FLTCR.FLTIE = (uint32)0U;
        /* Enable write protection */
        TIMx->TIM_FLTSR.WPEN = (uint32)1U;  
        /* Initialize global data */
        Tim_Ocu_Drv_ChannelState[InstNum][ChNum] = TIM_OCU_DRV_CH_STATE_INITIALIZED;
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Service to ocu drv instance init.
 * 
 * @param[in]  TimInstanceConfigPtr: OCU driver tim instance config
 *
 * @return     None
 */
static void Tim_Ocu_Drv_InstanceInit(const Tim_Ocu_Drv_TimConfigType * TimInstanceConfigPtr)
{
    /* TIM instance numbers */
    uint8 InstNum;
    InstNum = TimInstanceConfigPtr->ModuleId;
    Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
    Reg_Tim_WType  *TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];

    /* If write protection is enabled, then disable it. */
    if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
    {
        /* Disable write protection */
        TIMx->TIM_GLBSR.WPDIS = 1U;
    }
    /* Stop clock */
    TIMx->TIM_TIMEBASE.CKSRC = (uint32)0;
    TIMx->TIM_TIMEBASE.PSDIV = (uint32)1;
    /* Configure TIM_SYNC*/
    TIMw->TIM_SYNC = (uint32)0U;
    /* TIM counter operates in up counting mode */
    TIMx->TIM_GLBCR.CNTMODE = (uint32)0UL;

    /* Configure CONF with debug mode.*/
    TIMx->TIM_TIMEBASE.DBGM = (uint8)TimInstanceConfigPtr->DebugMode;

    /* Reset TIM_CNTINIT register */
    TIMx->TIM_CNTINIT.CNTINIT = (uint32)0U;

    /* Write TIM_MOD register */
    TIMx->TIM_MOD.MOD = TimInstanceConfigPtr->MaxCounterValue;

    /* Store the max counter value */
    Tim_Ocu_Drv_ModuleMaxCounterValue[InstNum] = (uint16)TimInstanceConfigPtr->MaxCounterValue;

    /* Set clock source and divider */
    Tim_Ocu_Drv_InstanceClockInfo[InstNum].InstanceClockSource = (uint8)(TimInstanceConfigPtr->ClockSource);
    Tim_Ocu_Drv_InstanceClockInfo[InstNum].InstanceClockDivide =(uint8)TimInstanceConfigPtr->ClockPrescale;

    /* Enable write protection */
    TIMx->TIM_FLTSR.WPEN = (uint32)1U;
}

/**
 * @brief      Service to ocu drv module init.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ModuleInit(void)
{
    /* Module index used in the loop */
    uint8 ModuleIdx; 
    /* Pointer to TIM Module configuration */
    const Tim_Ocu_Drv_TimConfigType *TimModuleConfigPtr = NULL_PTR;
    for (ModuleIdx = 0U; ModuleIdx < Tim_Ocu_Drv_ConfigPtr->NumModules; ++ModuleIdx)
    {
        TimModuleConfigPtr = &(*Tim_Ocu_Drv_ConfigPtr->ModulesConfig)[ModuleIdx];
        Tim_Ocu_Drv_InstanceInit(TimModuleConfigPtr);
    }
}

/**
 * @brief      Service to ocu drv channel deinit.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ChannelDeInit(void)
{
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    Reg_Tim_BfType *TIMx = NULL_PTR;
    Reg_Tim_WType  *TIMw = NULL_PTR;

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

    /* Loop all TIM channels and perform deInit actions */
    for (uint8 ChLoopIdx = 0U; ChLoopIdx < (Tim_Ocu_Drv_ConfigPtr->NumChannels); ++ChLoopIdx)
    {
        Tim_Ocu_Drv_ProcessChannel(&InstNum, &ChNum, ChLoopIdx);
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
        MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif
        TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
        TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];
        /* If write protection is enabled, then disable it. */
        if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
        {
            /* Disable write protection */
            TIMx->TIM_GLBSR.WPDIS = 1U;
        }

        /* Reset Tim_Ocu_Drv_PinAction */
        Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_LOW;

        /* Reset the max counter value */
        Tim_Ocu_Drv_MaxCounterValue[InstNum][ChNum] = (uint16)0U;
        /* reset the compare value, Correspond to init function*/
        TIMx->TIM_CCVn[ChNum].CCV = (uint32)0U;
        /* Reset the CH(n) output software control enable */
        TIMw->TIM_OUTSWCR &= ~(((uint32)1U) << (ChNum));
        /* Reset the CH(n)  output software control value */
        TIMw->TIM_OUTSWCR &= ~(((uint32)1U) << (ChNum + (8U)));
        /* Clears the channel event status */
        TIMx->TIM_GLBSR.RLDF = (uint32)0U;
        TIMx->TIM_GLBSR.TOF = (uint32)0U;
        /*reset this channel output compare mode, Correspond to init function */
        TIMw->TIM_CMCn[ChNum] = (uint32)0U;
        /* Disable output on the TIM channel */
        TIMw->TIM_GLBCR &= ~(1UL << ChNum);

#if (TIM_OCU_DRV_NOTIFICATION_SUPPORTED == STD_ON)
        Tim_Ocu_Drv_NoticeChState[InstNum][ChNum].ChannelIsInit = FALSE;
        Tim_Ocu_Drv_NoticeChState[InstNum][ChNum].CallBackFunc = NULL_PTR;
#endif  
        /* initialize global data */
        Tim_Ocu_Drv_ChannelState[InstNum][ChNum] = TIM_OCU_DRV_CH_STATE_UNINITIALIZED;
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Service to ocu drv instance deinit.
 * 
 * @param[in]  TimInstanceConfigPtr: OCU driver tim instance config
 *
 * @return     None
 */
static void Tim_Ocu_Drv_InstanceDeInit(const Tim_Ocu_Drv_TimConfigType *TimInstanceConfigPtr)
{
    /* TIM channel and instance numbers */
    uint8 InstNum = TimInstanceConfigPtr->ModuleId;;
    Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
    Reg_Tim_WType  *TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];
    /* If write protection is enabled, then disable it. */
    if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
    {
        /* Disable write protection */
        TIMx->TIM_GLBSR.WPDIS = 1U;
    }
        
    /* reset TIM_TIMEBASE register*/
    TIMw->TIM_TIMEBASE = (uint32)0U;
    /* Reset debug mode */
    TIMx->TIM_TIMEBASE.DBGM = (uint32)0U;
    /* Reset MOD */
    TIMx->TIM_MOD.MOD = (uint32)0U;
    /* Reset the max counter value */
    Tim_Ocu_Drv_ModuleMaxCounterValue[InstNum] = (uint16)0U;
    /* Release TIM cnt */
    TIMx->TIM_CNT.CNT = (uint32)0x0U;
}

/**
 * @brief      Service to ocu drv module deinit.
 * 
 * @param[in]  void
 *
 * @return     None
 */
static void Tim_Ocu_Drv_ModuleDeInit(void)
{
    /* Module index used in the loop */
    uint8 ModuleIdx;
    /* Pointer to TIM Module configuration */
    const Tim_Ocu_Drv_TimConfigType *TimModuleConfigPtr = NULL_PTR;

    for (ModuleIdx = 0U; ModuleIdx < Tim_Ocu_Drv_ConfigPtr->NumModules; ++ModuleIdx)
    {   
        /* Get pointer to configuration data of the TIM module */
        TimModuleConfigPtr = &(*Tim_Ocu_Drv_ConfigPtr->ModulesConfig)[ModuleIdx];
        Tim_Ocu_Drv_InstanceDeInit(TimModuleConfigPtr);
    }
}

/**
 * @brief      Service to process channel set.
 * 
 * @param[in]  InstNum: Instance number
 * @param[in]  ChNum: Channel number
 * @param[in]  ChannelSet: Channel set
 *
 * @return     None
 */
static Std_ReturnType Tim_Ocu_Drv_CheckChannelSet(uint8 InstNum, uint8 ChNum, uint8 ChannelSet)
{
    Std_ReturnType Ret = E_OK;
    if (TIM_OCU_DRV_STATE_IDLE != Tim_Ocu_Drv_GlobalState)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        if (TIM_OCU_DRV_START == ChannelSet)
        {
            if ((TIM_OCU_DRV_CH_STATE_INITIALIZED != Tim_Ocu_Drv_ChannelState[InstNum][ChNum]) &&
                (TIM_OCU_DRV_CH_STATE_STOPPED != Tim_Ocu_Drv_ChannelState[InstNum][ChNum]))
            {
                Ret = E_NOT_OK;
            }
        }
        else
        {
            if ((TIM_OCU_DRV_CH_STATE_INITIALIZED != Tim_Ocu_Drv_ChannelState[InstNum][ChNum]) &&
                (TIM_OCU_DRV_CH_STATE_RUNNING != Tim_Ocu_Drv_ChannelState[InstNum][ChNum]))
            {
                Ret = E_NOT_OK;
            }
        }
    }
    return Ret;
}

/**
 * @brief      Service to judge whether the next match was in the given interval.
 * 
 * @param[in]  PostCmWriteValue: Compare match value
 * @param[in]  StartIntervalValue: Start value of this cycle
 * @param[in]  EndIntervalValue: End value of this cycle
 *
 * @return     Tim_Ocu_Drv_ReturnType
 * @retval     TIM_OCU_DRV_IN_INTERVAL:  compare match was in the given interval
 * @retval     TIM_OCU_DRV_OUT_INTERVAL: compare match was out of the given interval
 */
static Tim_Ocu_Drv_ReturnType Tim_Ocu_Drv_DetermineNextCmStatus(Tim_Ocu_Drv_ValueType PostCmWriteValue,
                                                        Tim_Ocu_Drv_ValueType StartIntervalValue,
                                                        Tim_Ocu_Drv_ValueType EndIntervalValue)
{
    Tim_Ocu_Drv_ReturnType RetValue = TIM_OCU_DRV_IN_INTERVAL;

    if (StartIntervalValue <= EndIntervalValue)
    {
        RetValue =
            ((StartIntervalValue <= PostCmWriteValue) && (PostCmWriteValue <= EndIntervalValue))
                ? TIM_OCU_DRV_IN_INTERVAL
                : TIM_OCU_DRV_OUT_INTERVAL;
    }
    else
    {
        RetValue =
            ((PostCmWriteValue < StartIntervalValue) && (PostCmWriteValue > EndIntervalValue))
                ? TIM_OCU_DRV_OUT_INTERVAL
                : TIM_OCU_DRV_IN_INTERVAL;
    }

    return RetValue;
}
#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"
/**
 * @brief     The function initializes the OCU Driver.
 *
 * @param[in] ModuleConfigPtr: Pointer to the OCU configuration
 *
 * @return    None
 */
void Tim_Ocu_Drv_Init(const Tim_Ocu_Drv_ModuleConfigType *const ModuleConfigPtr)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ModuleConfigPtr);
#endif

    if (NULL_PTR == Tim_Ocu_Drv_ConfigPtr)
    {
        /* Save configuration pointer in a local variable */
        Tim_Ocu_Drv_ConfigPtr = ModuleConfigPtr;

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
        MCALLIB_DEV_ASSERT(Tim_Ocu_Drv_ConfigPtr->NumModules <= TIM_OCU_DRV_TIM_INSTANCE_COUNT);
        MCALLIB_DEV_ASSERT((0U < Tim_Ocu_Drv_ConfigPtr->NumChannels) &&
                          (Tim_Ocu_Drv_ConfigPtr->NumChannels <= TIM_OCU_DRV_NUM_HW_CHANNELS));
#endif
        Tim_Ocu_Drv_ClearCounterInfo();
        Tim_Ocu_Drv_ModuleInit();
        Tim_Ocu_Drv_ChannelInit();
        Tim_Ocu_Drv_StartCounter();

        Tim_Ocu_Drv_GlobalState = TIM_OCU_DRV_STATE_IDLE;
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     The function de-initializes the OCU Driver.
 *
 * @param[in] None
 *
 * @return    None
 */
void Tim_Ocu_Drv_DeInit(void)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
    if (NULL_PTR != Tim_Ocu_Drv_ConfigPtr)
    {
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
        MCALLIB_DEV_ASSERT(Tim_Ocu_Drv_ConfigPtr->NumModules <= TIM_OCU_DRV_TIM_INSTANCE_COUNT);
        MCALLIB_DEV_ASSERT((0U < Tim_Ocu_Drv_ConfigPtr->NumChannels) &&
                      (Tim_Ocu_Drv_ConfigPtr->NumChannels <= TIM_OCU_DRV_NUM_HW_CHANNELS));
#endif
        Tim_Ocu_Drv_ModuleDeInit();
        Tim_Ocu_Drv_ChannelDeInit();
        Tim_Ocu_Drv_ClearCounterInfo();

        Tim_Ocu_Drv_ConfigPtr = NULL_PTR;
        Tim_Ocu_Drv_GlobalState = TIM_OCU_DRV_STATE_UNINIT;
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Service to start an TIM channel.
 *             This function  start an TIM channel by 
 *             allowing all compare match configured actions to be performed.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_StartChannel(uint8 InstNum, uint8 ChNum)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif

    if (E_OK  == Tim_Ocu_Drv_CheckChannelSet(InstNum, ChNum, TIM_OCU_DRV_START))
    {
        Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
        Reg_Tim_WType  *TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];
        /* enter critical section */
        SchM_Enter_Ocu_StartChannelUpdate();

        /* If write protection is enabled, then disable it. */
        if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
        {
            /* Disable write protection */
            TIMx->TIM_GLBSR.WPDIS = 1U;
        }

        /* get Ocu Action data from Tim_Ocu_Drv_PinAction[] */
        switch (Tim_Ocu_Drv_PinAction[InstNum][ChNum])
        {
            case (uint8)TIM_OCU_DRV_SET_LOW:
            {
                TIMx->TIM_CMCn[ChNum].ELS = 2U;
                break;
            }
            case (uint8)TIM_OCU_DRV_SET_HIGH:
            {
                TIMx->TIM_CMCn[ChNum].ELS = 3U;
                break;
            }
            case (uint8)TIM_OCU_DRV_SET_TOGGLE:
            {
                TIMx->TIM_CMCn[ChNum].ELS = 1U;
                break;
            }
            default:
            {
                TIMx->TIM_CMCn[ChNum].ELS = 0U;
                break;
            }
        }

        /* Release software control */
        TIMw->TIM_OUTSWCR &= (~(uint32)(((uint32)1U) << ((uint8)ChNum)));
        /*clear CHF bit*/
        TIMx->TIM_CMCn[ChNum].CHF = 0;
        /* Clears the channel event status */
        TIMx->TIM_GLBSR.RLDF = 0;
        TIMx->TIM_GLBSR.TOF = 0;
        /* Enable output on the TIM channel */
        TIMw->TIM_GLBCR |= ((uint32)1U) << (ChNum);

        TIMx->TIM_FLTSR.WPEN = (uint32)1U;
        /* exit critical section */
        SchM_Exit_Ocu_StartChannelUpdate();

        /* set channel status to 'RUNNING' */
        Tim_Ocu_Drv_ChannelState[InstNum][ChNum] = TIM_OCU_DRV_CH_STATE_RUNNING;
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Service to stop an TIM channel.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_StopChannel(uint8 InstNum, uint8 ChNum)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif
    if (E_OK  == Tim_Ocu_Drv_CheckChannelSet(InstNum, ChNum, TIM_OCU_DRV_STOP))
    {
        Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
        Reg_Tim_WType  *TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];
        /* enter critical section */
        SchM_Enter_Ocu_StopChannelUpdate();

        /* If write protection is enabled, then disable it. */
        if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
        {
                /* Disable write protection */
            TIMx->TIM_GLBSR.WPDIS = 1U;
        }

        /* write the ELS = 0 */
        TIMx->TIM_CMCn[ChNum].ELS = 0U;

        /*clear CHF bit*/
        TIMx->TIM_CMCn[ChNum].CHF = 0;

        /* Clears the channel event status */
        TIMx->TIM_GLBSR.RLDF = 0;
        TIMx->TIM_GLBSR.TOF = 0;

        /* Disable interrupts for the given channel*/
        TIMx->TIM_CMCn[ChNum].CHIE = 0;

        /* Disable output on the TIM channel */
        TIMw->TIM_GLBCR &= ~(1UL << ChNum);

        TIMx->TIM_FLTSR.WPEN = (uint32)1U;

        /* exit critical section */
        SchM_Exit_Ocu_StopChannelUpdate();

        /* set channel status to 'STOPPED' */
        Tim_Ocu_Drv_ChannelState[InstNum][ChNum] = TIM_OCU_DRV_CH_STATE_STOPPED;
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Service to get current counter value of TIM.
 *
 * @param[in]  InstNum: Module id of the TIM
 *
 * @return     Tim_Ocu_Drv_ValueType: current counter value
 */
Tim_Ocu_Drv_ValueType Tim_Ocu_Drv_GetCounter(uint8 InstNum)
{
    Tim_Ocu_Drv_ValueType RetCntVal = 0U;
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT);
#endif

    if (TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState)
    {
        Reg_Tim_BfType const *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
        RetCntVal = TIMx->TIM_CNT.CNT;
    }

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return RetCntVal;
}

/**
 * @brief      Service to indicate the driver what shall be done automatically by 
 *             hardware (if supported) upon compare match.
 *             This function set the action to be performed by hardware automatically, at the next 
 *             compare match in the corresponding OCU channel.
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  PinAction: Ocu channel action after compare match
 *
 * @return     None
 */
void Tim_Ocu_Drv_SetPinAction(uint8 InstNum, uint8 ChNum, Tim_Ocu_Drv_PinActionType PinAction)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif

    if ((TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState) &&
        (TIM_OCU_DRV_CH_STATE_RUNNING == Tim_Ocu_Drv_ChannelState[InstNum][ChNum]) &&
        (TIM_OCU_DRV_CH_PIN_USED == Tim_Ocu_Drv_ChannelPinUsedState[InstNum][ChNum]))
    {
        Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
        /* enter critical section */
        SchM_Enter_Ocu_SetPinActionUpdate();

        /* If write protection is enabled, then disable it. */
        if (TIMx->TIM_FLTSR.WPEN == (uint32)1U)
        {
            /* Disable write protection */
            TIMx->TIM_GLBSR.WPDIS = 1U;
        } 
        /* Store Ocu Action value to Tim_Ocu_Drv_PinAction[] */
        switch (PinAction)
        {
            case TIM_OCU_DRV_SET_LOW:
            {
                Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_LOW;
                TIMx->TIM_CMCn[ChNum].ELS = 2;
                break;
            }
            case TIM_OCU_DRV_SET_HIGH:
            {
                Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_HIGH;
                TIMx->TIM_CMCn[ChNum].ELS = 3;
                break;
            }
            case TIM_OCU_DRV_SET_TOGGLE:
            {
                Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_TOGGLE;
                TIMx->TIM_CMCn[ChNum].ELS = 1;
                break;
            }
            default:
            {
                Tim_Ocu_Drv_PinAction[InstNum][ChNum] = (uint8)TIM_OCU_DRV_SET_DISABLE;
                TIMx->TIM_CMCn[ChNum].ELS = 0;
                break;
            }
        }
        TIMx->TIM_FLTSR.WPEN = (uint32)1U;
        /* exit critical section */
        SchM_Exit_Ocu_SetPinActionUpdate();
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Service to set immediately the level of the pin associated to an OCU channel
 * 
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  PinState: Ocu channel pin state after init or deinit
 *
 * @return     None
 */
void Tim_Ocu_Drv_SetPinState(uint8 InstNum, uint8 ChNum, Tim_Ocu_Drv_PinStateType PinState)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif

    if ((TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState) &&
        (TIM_OCU_DRV_CH_STATE_RUNNING != Tim_Ocu_Drv_ChannelState[InstNum][ChNum]) &&
        (TIM_OCU_DRV_CH_PIN_USED == Tim_Ocu_Drv_ChannelPinUsedState[InstNum][ChNum]))
    {
        Reg_Tim_WType *TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];
        /* enter critical section */
        SchM_Enter_Ocu_SetPinStateUpdate();

        /* set output pin to its configured state */
        if (TIM_OCU_DRV_HIGH == PinState)
        {
            TIMw->TIM_OUTSWCR |=
                (uint32)(((uint32)1U) << (ChNum + TIM_OCU_DRV_OUTSWCR_FORCED_VALUE_OFFSET));
        }
        else
        {
            TIMw->TIM_OUTSWCR &=
                (uint32)(~(uint32)(((uint32)1U) << (ChNum + TIM_OCU_DRV_OUTSWCR_FORCED_VALUE_OFFSET)));
        }

        /* Enable software control */
        TIMw->TIM_OUTSWCR |= (uint32)(((uint32)1U) << (ChNum));

        /* exit critical section */
        SchM_Exit_Ocu_SetPinStateUpdate();
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Service to set the value of the channel threshold relative to the current value of 
 *             the counter.
 * 
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  RelativeValue: Value to use for computing the new threshold.
 *
 * @return     Tim_Ocu_Drv_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:  compare match was in the given interval
 * @retval     TIM_OCU_DRV_OUT_INTERVAL: compare match was out of the given interval
 */
Tim_Ocu_Drv_ReturnType Tim_Ocu_Drv_SetRelativeThreshold(uint8 InstNum, uint8 ChNum,
                                                Tim_Ocu_Drv_ValueType RelativeValue)
{
    Tim_Ocu_Drv_ReturnType RetVal = TIM_OCU_DRV_IN_INTERVAL;
    Tim_Ocu_Drv_ValueType CntValuePreUpdate;  /* CNT register value before computing the update */
    Tim_Ocu_Drv_ValueType CntValuePostUpdate; /* CNT register value after computing the update */
    Tim_Ocu_Drv_ValueType CmpMatchValue;      /* New CNT register value */
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif

    Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
    if (TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState)
    {
        CntValuePreUpdate = (uint16)TIMx->TIM_CNT.CNT;
        CmpMatchValue =
            ((CntValuePreUpdate + RelativeValue) % Tim_Ocu_Drv_MaxCounterValue[InstNum][ChNum]);
        TIMx->TIM_CCVn[ChNum].CCV = CmpMatchValue;
        CntValuePostUpdate = (uint16)TIMx->TIM_CNT.CNT;
        RetVal =
            Tim_Ocu_Drv_DetermineNextCmStatus(CntValuePostUpdate, CntValuePreUpdate, CmpMatchValue);
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return RetVal;
}

/**
 * @brief      Service to set the value of the channel threshold using an absolute input data.
 *             
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  ReferenceValue: Value to use for computing the new threshold by reference.
 * @param[in]  AbsoluteValue: Value to use for computing the new threshold.
 *
 * @return     Tim_Ocu_Drv_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occur) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:  compare match was in the given interval
 * @retval     TIM_OCU_DRV_OUT_INTERVAL: compare match was out of the given interval
 */
Tim_Ocu_Drv_ReturnType Tim_Ocu_Drv_SetAbsoluteThreshold(uint8 InstNum, uint8 ChNum,
                                                Tim_Ocu_Drv_ValueType ReferenceValue,
                                                Tim_Ocu_Drv_ValueType AbsoluteValue)
{
    Tim_Ocu_Drv_ReturnType RetVal = TIM_OCU_DRV_IN_INTERVAL;

    Tim_Ocu_Drv_ValueType CntValuePostUpdate;
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif
    Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
    if (TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState)
    {
        TIMx->TIM_CCVn[ChNum].CCV = AbsoluteValue;

        CntValuePostUpdate = (uint16)TIMx->TIM_CNT.CNT;

        RetVal = Tim_Ocu_Drv_DetermineNextCmStatus(CntValuePostUpdate, ReferenceValue, AbsoluteValue);
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return RetVal;
}

/**
 * @brief      Service to get max counter value of TIM.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
uint16 Tim_Ocu_Drv_GetMaxCounterValue(uint8 InstNum, uint8 ChNum)
{
    uint16 RetMaxCntVal = 0U;
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif

    if (TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState)
    {
        RetMaxCntVal = Tim_Ocu_Drv_MaxCounterValue[InstNum][ChNum];
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return RetMaxCntVal;
}

#if (STD_ON == TIM_OCU_DRV_NOTIFICATION_SUPPORTED)
/**
 * @brief      This service is used to disable notifications from an OCU channel.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_DisableNotification(uint8 InstNum, uint8 ChNum)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif
    Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
    if (TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState)
    {
        /* enter critical section */
        SchM_Enter_Ocu_NotificationUpdate();
        /* disable interrupts for given channel */
        TIMx->TIM_CMCn[ChNum].CHIE = 0;
        /* exit critical section */
        SchM_Exit_Ocu_NotificationUpdate();
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This service is used to enable notifications from an OCU channel.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_EnableNotification(uint8 InstNum, uint8 ChNum)
{
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((ChNum < TIM_OCU_DRV_TIM_CHANNEL_COUNT) && (InstNum < TIM_OCU_DRV_TIM_INSTANCE_COUNT));
#endif
    Reg_Tim_BfType *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
    if (TIM_OCU_DRV_STATE_IDLE == Tim_Ocu_Drv_GlobalState)
    {
        if (NULL_PTR != Tim_Ocu_Drv_NoticeChState[InstNum][ChNum].CallBackFunc)
        {
            /* enter critical section */
            SchM_Enter_Ocu_NotificationUpdate();
            /* enable interrupts for given channel */
            TIMx->TIM_CMCn[ChNum].CHIE = 1;
            /* exit critical section */
            SchM_Exit_Ocu_NotificationUpdate();
        }
    }
#if (STD_ON == TIM_OCU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}
#endif

/**
 * @brief      TIM channel interrupt handle
 *
 * @param[in]  InstNum:  Select the TIM ID
 *
 * @return none
 *
 */
void Tim_Ocu_Drv_ChIntHandler(Tim_Ocu_Drv_IdType InstNum)
{
    uint32     AllIntStatus = 0U;
    uint32     TimIntStatus = 0U;
    uint32 Channel;
    Reg_Tim_WType *TIMw = Tim_Ocu_Drv_OcuRegWPtr[InstNum];
    Reg_Tim_BfType const *TIMx = Tim_Ocu_Drv_OcuRegBfPtr[InstNum];
#if (STD_ON == TIM_OCU_DRV_NOTIFICATION_SUPPORTED)
    Tim_Ocu_Drv_ChStateType const *Tim_Ocu_Drv_ChannelNoticeState = NULL_PTR;
#endif

    /* Check the parameters */
    AllIntStatus = TIMw->TIM_GLBSR & TIM_OCU_DRV_INTMASK;
    for (Channel = 0U; Channel < TIM_OCU_DRV_TIM_CHANNEL_COUNT; Channel++)
    {
        if (((uint32)0U != (AllIntStatus & ((uint32)1U << Channel))) && ((uint32)1U == TIMx->TIM_CMCn[Channel].CHIE))
        {
            /* enter critical section */
            SchM_Enter_Ocu_ISRRegisterStatusUpdate();
            /* get interrupt status */
            TimIntStatus = TIMw->TIM_CMCn[Channel];
            /* only check enabled interrupts */
            TimIntStatus = TimIntStatus & (~(TIM_OCU_DRV_CHINTMASK));
            /* clear interrupt status */
            TIMw->TIM_CMCn[Channel] = TimIntStatus;
            /* exit critical section */
            SchM_Exit_Ocu_ISRRegisterStatusUpdate();
#if (STD_ON == TIM_OCU_DRV_NOTIFICATION_SUPPORTED)
            Tim_Ocu_Drv_ChannelNoticeState = &Tim_Ocu_Drv_NoticeChState[InstNum][Channel];
            /* Call upper layer handler */
            if (NULL_PTR != Tim_Ocu_Drv_ChannelNoticeState->CallBackFunc)
            {
                if (Tim_Ocu_Drv_ChannelNoticeState->ChannelIsInit == (boolean)TRUE)
                {
                    Tim_Ocu_Drv_ChannelNoticeState->CallBackFunc();
                }
            }
#endif
        }
    }
}

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Ocu_Drv */

/** @} end of group Ocu_Module */
