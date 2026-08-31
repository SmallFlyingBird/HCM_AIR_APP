/**
* @file    Icu_Lld_Etmr.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Lld_Etmr
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0488 Rule 18.4: The +, -, += and -= operators sho uld not be applied to anexpression of pointer type
 * PRQA S 0404 Rule 1.3: More than one read access to volatile objects between sequence points.
 * PRQA S 2985 Rule 2.2: There shall be no dead code.
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/

#include "Icu_Cfg.h"
#include "Icu_Lld_Etmr.h"
#include "SchM_Icu.h"
#include "Icu_Etmr_Irq.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_LLD_ETMR_VENDOR_ID_C                      (180)
#define ICU_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ICU_LLD_ETMR_AR_RELEASE_MINOR_VERSION_C       (4)
#define ICU_LLD_ETMR_AR_RELEASE_REVISION_VERSION_C    (0)
#define ICU_LLD_ETMR_SW_MAJOR_VERSION_C               (2)
#define ICU_LLD_ETMR_SW_MINOR_VERSION_C               (3)
#define ICU_LLD_ETMR_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU_LLD header file are of the same vendor */
#if (ICU_LLD_ETMR_VENDOR_ID_C != ICU_LLD_ETMR_VENDOR_ID)
#error "Icu_Lld_Etmr.c and Icu_Lld_Etmr.h have different vendor ids"
#endif

/* Check if source file and ICU_LLD header file are of the same Autosar version */
#if ((ICU_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_ETMR_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LLD_ETMR_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_ETMR_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LLD_ETMR_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_ETMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Lld_Etmr.c and Icu_Lld_Etmr.h are different"
#endif

/* Check if source file and ICU_LLD header file are of the same Software version */
#if ((ICU_LLD_ETMR_SW_MAJOR_VERSION_C != ICU_LLD_ETMR_SW_MAJOR_VERSION) || \
     (ICU_LLD_ETMR_SW_MINOR_VERSION_C != ICU_LLD_ETMR_SW_MINOR_VERSION) || \
     (ICU_LLD_ETMR_SW_PATCH_VERSION_C != ICU_LLD_ETMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lld_Etmr.c and Icu_Lld_Etmr.h are different"
#endif
/*=================================================================================*/
/* Check if source file and ICU_PBCFG header file are of the same vendor */
#if (ICU_LLD_ETMR_VENDOR_ID_C != ICU_VENDOR_ID_PBCFG)
#error "Icu_Lld_Etmr.c and Icu_PBcfg.h have different vendor ids"
#endif

/* Check if source file and ICU_PBCFG header file are of the same Autosar version */
#if ((ICU_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (ICU_LLD_ETMR_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (ICU_LLD_ETMR_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_PBCFG))
#error "AutoSar Version Numbers of Icu_Lld_Etmr.c and Icu_PBcfg.h are different"
#endif

/* Check if source file and ICU_PBCFG header file are of the same Software version */
#if ((ICU_LLD_ETMR_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_PBCFG) || \
     (ICU_LLD_ETMR_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_PBCFG) || \
     (ICU_LLD_ETMR_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_PBCFG))
#error "Software Version Numbers of Icu_Lld_Etmr.c and Icu_PBcfg.h are different"
#endif
/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
extern Icu_ChannelInfoType Icu_gChannelInfo[ICU_MAX_CHANNEL];
#define ICU_START_SEC_VAR_CLEARED_32
#include "Icu_MemMap.h"
ICU_VAR Icu_Etmr_Mc_ChannelInfoType Icu_Etmr_Mc_gChannelInfo[ICU_ETMR_MC_CHANNEL_COUNT];
ICU_VAR Icu_ChannelType Etmr_Icu_gHwToUserChannelMap[ICU_ETMR_MC_CHANNEL_COUNT][ETMR_ICU_CHANNEL_COUNT];
#if (ICU_TIMESTAMP_API == STD_ON)
ICU_VAR Etmr_Icu_TimeStampInfoType Etmr_Icu_TimeStampInfo[ICU_MAX_CHANNEL];
#endif

ICU_VAR Etmr_Icu_EdgeDetectType Etmr_Icu_gEdgeNotification[ICU_MAX_CHANNEL];

#define ICU_STOP_SEC_VAR_CLEARED_32
#include "Icu_MemMap.h"


#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"
ICU_VAR static Etmr_Icu_ChannelInitStateType Etmr_Icu_gChannelInitState[ICU_MAX_CHANNEL];
#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
static void Icu_Etmr_StartChannelCapture(Icu_ChannelType Channel, uint32 ServiceID);
static void Icu_Etmr_StopChannelCapture(Icu_ChannelType Channel);
static void Icu_Etmr_Mc_InitChannel(Icu_Etmr_Mc_ChannelConfigType const *ConfigPtr);
/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if defined (CIM_ETMROPT_IS_INDEPENDENT)
ICU_FUNC static inline void Icu_Etmr_ClearExternalClockSource(uint8 Instance)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    volatile uint32 * EtmrOpt = &CimBase->ETMROPT0 + Instance;

    *EtmrOpt &= ~CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK;
}

ICU_FUNC static inline void Icu_Etmr_ConfigureExternalClockSource(uint8 Instance, Icu_Etmr_Mc_ClockOthersType ExClkSrc)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    volatile uint32 * EtmrOpt = &CimBase->ETMROPT0 + Instance;

    *EtmrOpt &= ~CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK;
    *EtmrOpt |= CIM_ETMROPT0_ETMR0_EXTCLK_SEL(ExClkSrc);
}
#else
/**
 * @brief       This function clears the external clock source for the eTMR instance.
 * @param[in]   Instance The instance number.
 * @return      void
 */
ICU_FUNC static inline void Icu_Etmr_ClearExternalClockSource(uint8 Instance)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    uint32  EtmrInstIndex = Instance * 2U;

    CimBase->ETMROPT0 &= ~(CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK << EtmrInstIndex);
}


ICU_FUNC static inline void Icu_Etmr_ConfigureExternalClockSource(uint8 Instance, Icu_Etmr_Mc_ClockOthersType ExClkSrc)
{
    volatile CIM_Type *const CimBase = CIM_BASE_PTRS;
    
    uint32  EtmrInstIndex = Instance * 2U;

    CimBase->ETMROPT0 &= ~(CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK << EtmrInstIndex);
    CimBase->ETMROPT0 |= (CIM_ETMROPT0_ETMR0_EXTCLK_SEL(ExClkSrc) << EtmrInstIndex);
}
#endif

ICU_FUNC static void Icu_Etmr_Mc_InitChannel(Icu_Etmr_Mc_ChannelConfigType const *ConfigPtr)
{
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[ConfigPtr->HwChannelId];
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    /* Disable etmr counter */
    ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_CTRL_OFFSET32, eTMR_CTRL_EN_MASK);
    /* Clear the overflow flag */
    ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_STS_OFFSET32, eTMR_STS_TOF_MASK);/*PRQA S 2985*/
    /* Set module clock source */
    if (ICU_MC_CLOCK_SOURCE_FASTBUSCLK == ConfigPtr->ClockSource)
    {
        ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_CTRL_OFFSET32, eTMR_CTRL_CLKSRC_MASK);
    }
    else
    {
        ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_CTRL_OFFSET32, eTMR_CTRL_CLKSRC_MASK);
        /* Set external clock source */
        Icu_Etmr_ConfigureExternalClockSource(ConfigPtr->HwChannelId, ConfigPtr->ClockOthers);
    }

    /* Set clock prescale */
    ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CTRL_OFFSET32, eTMR_CTRL_CLKPRS_MASK, eTMR_CTRL_CLKPRS(ConfigPtr->Prescale));
#if defined (CPU_YTM32B1MC0)
#else
    /* Set counter INIT value */
    ICU_ETMR_REG_ADDR32_WRITE(EtmrBaseAddress + eTMR_INIT_OFFSET32, 0U);
    /* Set counter initial value load from register INIT */
    ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_SYNC_OFFSET32, eTMR_SYNC_CNTINIT_MASK);
#endif
    Icu_Etmr_Mc_gChannelInfo[ConfigPtr->HwChannelId].CountMode = ConfigPtr->CountMode;
    Icu_Etmr_Mc_gChannelInfo[ConfigPtr->HwChannelId].IsNotificationEnabled = ConfigPtr->EnableNotification;
    Icu_Etmr_Mc_gChannelInfo[ConfigPtr->HwChannelId].NotificationPtr = ConfigPtr->NotificationPtr;
    Icu_Etmr_Mc_gChannelInfo[ConfigPtr->HwChannelId].State = ETMR_MC_CHANNEL_STATE_INITIALIZED;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();
}

ICU_FUNC static void Icu_Etmr_Mc_StartChannel(uint16 Channel, Icu_Etmr_Mc_ValueType Value)
{
    /* get hardware etmr channel id */
    uint8 EtmrInstanceId = (uint8)((Channel & ((uint16)ICU_INSTANCE_ID_MASK)) >> ICU_INSTANCE_SHIFT);
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13();
    /* Disable overflow interrupt */
    ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_INTE_OFFSET32, eTMR_INTE_TOIE_MASK);
    /* Clean interrupt flag */
    ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_STS_OFFSET32, eTMR_STS_TOF_MASK); /*PRQA S 2985*/
    /* Set period value */
    /* Set counter MOD value */
    ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_CTRL_OFFSET32, eTMR_CTRL_EN_MASK);
    if (0U == ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_MOD_OFFSET32))
    {
        ICU_ETMR_REG_ADDR32_WRITE((EtmrBaseAddress + eTMR_MOD_OFFSET32), Value - 1U);
    }
    /* Save period value */
    Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].PeriodTickValue = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_MOD_OFFSET32);

    /* Enable or disable interrupt */
    if (TRUE == Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].IsNotificationEnabled)
    {
        ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_INTE_OFFSET32, eTMR_INTE_TOIE_MASK);
    }
    else
    {
        ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_INTE_OFFSET32, eTMR_INTE_TOIE_MASK);
    }
    /* Enable etmr module counter */
    ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_CTRL_OFFSET32, eTMR_CTRL_EN_MASK);
    /* HA0 enable instance need Clear the all interrupt flag */
    ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_STS_OFFSET32, 0xFFFFFFFFU); /*PRQA S 2985*/
    /* Update channel state to "running" */
    Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].State = ETMR_MC_CHANNEL_STATE_RUNNING;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13();
}

#if(ICU_DE_INIT_API == STD_ON)
ICU_FUNC static void Icu_Etmr_Mc_StopChannel(uint16 Channel)
{
    uint16 EtmrInstanceId = (uint16)((Channel & (uint16)ICU_INSTANCE_ID_MASK) >> ICU_INSTANCE_SHIFT);
    uint16 EtmrChannelId = (uint16)(Channel & (uint16)ICU_CHANNEL_ID_MASK);
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14();
    /* Disable timer channel */
    ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32(EtmrChannelId), eTMR_CTRL_EN_MASK);
    /* Update channel state to "stoped" */
    if (ETMR_MC_CH_MODE_CONTINUOUS == Icu_Etmr_Mc_gChannelInfo[EtmrChannelId].CountMode)
    {
        Icu_Etmr_Mc_gChannelInfo[EtmrChannelId].State = ETMR_MC_CHANNEL_STATE_STOPPED;
    }
    else
    {
        /* math MISRA-C */
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14();
}
#endif
ICU_FUNC void Icu_Lld_Etmr_Init(void)
{
    uint32 EtmrBaseAddress;
    uint16 InstanceIndex = 0U;
    uint16 EtmrInstanceCount = Icu_gConfigPtr->IcuEtmrConfigPtr[InstanceIndex].IcuEtmrCount;
    uint16 EtmrInstanceId;
    uint8 EtmrChannelId;
    Icu_ChannelConfigType const *IcuChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;

    Icu_Etmr_Mc_ChannelConfigType EtmrMcConfig;

    /* Init eTMR ICU channel */
    for (Icu_ChannelType ChannelIndex = 0U; ChannelIndex < Icu_gConfigPtr->IcuChannelCount; ++ChannelIndex)
    {
        if (IcuChannelConfigPtr->IcuHwIp == ICU_ETMR)
        {
            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
            /* Get eTMR module id and channel id */
            EtmrInstanceId = (uint16)(IcuChannelConfigPtr->IcuHwIpInstance & (((Icu_ChannelType)ICU_INSTANCE_ID_MASK) >> INSTANCE_OFFSET));
            EtmrChannelId = (uint8)(IcuChannelConfigPtr->IcuHwChannel & (Icu_ChannelType)ICU_CHANNEL_ID_MASK);
            /* Get eTMR instance base address */
            EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];

            /* Assign Hardware channel to user define channel */
            Etmr_Icu_gHwToUserChannelMap[EtmrInstanceId][EtmrChannelId] = ChannelIndex;
            Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].TimerBaseFunction = ETMR_MC_TIMER_BASE_ICU;

            /* Clear template value MeasurementInfo */
            Icu_gChannelInfo[ChannelIndex].ActiveTime = 0;
            Icu_gChannelInfo[ChannelIndex].PeriodTime = 0;
            Icu_gChannelInfo[ChannelIndex].EdgeNumber = 0;
            Icu_gChannelInfo[ChannelIndex].InputState = ICU_IDLE;
            Icu_gChannelInfo[ChannelIndex].StartEdge = IcuChannelConfigPtr->IcuDefaultStartEdge;

            /* Set channel mode as disable mode */
            ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                          eTMR_CH_CTRL_CHMODE_MASK,
                                          eTMR_CH_CTRL_CHMODE(ETMR_FUNCTION_MODE_DISABLE));

            /* Clear ICU refer interrupt flag */
            ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_STS_OFFSET32,    /*PRQA S 2985*/
                                         ((uint32)eTMR_STS_CH0F_MASK << EtmrChannelId)
#ifndef CPU_YTM32B1MC0
                                         | ((uint32)eTMR_STS_CH0NPF_MASK << EtmrChannelId)
                                         | ((uint32)eTMR_STS_CH0PPF_MASK << EtmrChannelId)
#endif
                                        );
            /* Disable capture interrupt */
            ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_INTE_OFFSET32,
                                           (uint32)eTMR_INTE_CH0IE_MASK << EtmrChannelId);

            /* Set the capture edge */
            ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                          eTMR_CH_CTRL_CAPEDGE_MASK,
                                          eTMR_CH_CTRL_CAPEDGE((uint8)IcuChannelConfigPtr->IcuDefaultStartEdge));

            // if (ETMR_MC_TIMER_BASE_GPT != Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].TimerBaseFunction)
            {
                if (ETMR_MC_CHANNEL_STATE_UNINIT == Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].State)
                {
                    for (InstanceIndex = 0U; InstanceIndex < EtmrInstanceCount; ++InstanceIndex)
                    {
                        if (Icu_gConfigPtr->IcuEtmrConfigPtr[InstanceIndex].IcuEtmrModule == EtmrInstanceId)
                        {
                            break;
                        }
                    }
                    /* Set module counter */
                    EtmrMcConfig.HwChannelId = (uint8)EtmrInstanceId;
                    EtmrMcConfig.ClockSource = (Icu_Etmr_Mc_ClockSourceType)Icu_gConfigPtr->IcuEtmrConfigPtr[InstanceIndex].IcuEtmrClockSource;
                    EtmrMcConfig.ClockOthers = (Icu_Etmr_Mc_ClockOthersType)Icu_gConfigPtr->IcuEtmrConfigPtr[InstanceIndex].IcuEtmrClockOthers;
                    EtmrMcConfig.Prescale = (uint8)(Icu_gConfigPtr->IcuEtmrConfigPtr[InstanceIndex].IcuEtmrPrescaler);
                    EtmrMcConfig.CountMode = ETMR_MC_CH_MODE_CONTINUOUS;
                    EtmrMcConfig.EnableNotification = TRUE;
                    EtmrMcConfig.NotificationPtr = NULL_PTR;

                    Icu_Etmr_Mc_InitChannel(&EtmrMcConfig);
                    Icu_Etmr_Mc_StartChannel((uint16)(EtmrInstanceId << INSTANCE_OFFSET) | EtmrChannelId, MOD_FULL_MASK);
                }

                Icu_gChannelInfo[ChannelIndex].PeriodTime = Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].PeriodTickValue;
                Etmr_Icu_gChannelInitState[ChannelIndex] = ETMR_ICU_CHANNEL_INIT_OK;
            }
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
        }
        /* Move to next channel config pointer */
        ++IcuChannelConfigPtr;
    }
}

ICU_FUNC void Icu_Lld_Etmr_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;

    /* get hardware etmr channel id */
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    ChannelConfigPtr = ChannelConfigPtr + Channel; /*PRQA S 0488*/
    /* Get eTMR module id and channel id */
    uint8 EtmrInstanceId = (uint8)(ChannelConfigPtr->IcuHwIpInstance & (((Icu_ChannelType)ICU_INSTANCE_ID_MASK) >> INSTANCE_OFFSET));
    uint8 EtmrChannelId = (uint8)(ChannelConfigPtr->IcuHwChannel & (Icu_ChannelType)ICU_CHANNEL_ID_MASK);
    /* Get eTMR instance base address */
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];

    /* The function Icu_SetActivationCondition shall reset the
       state for the given channel to ICU_IDLE
       Trace : SWS_Icu_00139 */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16();
    Icu_gChannelInfo[Channel].InputState = ICU_IDLE;
    /* Reset values of channel */
    Icu_gChannelInfo[Channel].ActiveTime = 0;
    Icu_gChannelInfo[Channel].EdgeNumber = 0;

    /* Reset the capture edge */
    ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                  eTMR_CH_CTRL_CAPEDGE_MASK,
                                  eTMR_CH_CTRL_CAPEDGE((uint8)Activation));
    Icu_gChannelInfo[Channel].StartEdge = Activation;

    Icu_Etmr_StartChannelCapture(Channel, SETACTIVATION_SERVICE_ID); /*Implementing SetActivationCondition() enables the channel function.*/
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16();
}

#if (ICU_DE_INIT_API == STD_ON)
ICU_FUNC void Icu_Lld_Etmr_DeInit(void)
{
    uint32 EtmrBaseAddress;
    uint16 EtmrInstanceId;
    uint8 EtmrChannelId;
    Icu_ChannelConfigType const *IcuChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;
    Icu_Etmr_Mc_ChannelConfigType EtmrMcConfig;
    /* Init eTMR ICU channel */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17();
    for (Icu_ChannelType ChannelIndex = 0; ChannelIndex < Icu_gConfigPtr->IcuChannelCount; ++ChannelIndex)
    {

        if (IcuChannelConfigPtr->IcuHwIp == ICU_ETMR)
        {
            /* Get eTMR module id and channel id */
            EtmrInstanceId = (uint8)(IcuChannelConfigPtr->IcuHwIpInstance & (((Icu_ChannelType)ICU_INSTANCE_ID_MASK) >> INSTANCE_OFFSET));
            EtmrChannelId = (uint8)(IcuChannelConfigPtr->IcuHwChannel & (Icu_ChannelType)ICU_CHANNEL_ID_MASK);
            /* Get eTMR instance base address */
            EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];

            /* Assign Hardware channel to user define channel */
            Etmr_Icu_gHwToUserChannelMap[EtmrInstanceId][EtmrChannelId] = ChannelIndex;

            /* Clear template value MeasurementInfo */
            Icu_gChannelInfo[ChannelIndex].ActiveTime = 0U;
            Icu_gChannelInfo[ChannelIndex].PeriodTime = 0U;
            Icu_gChannelInfo[ChannelIndex].EdgeNumber = 0U;
            Icu_gChannelInfo[ChannelIndex].InputState = ICU_IDLE;
            Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].TimerBaseFunction = ETMR_MC_TIMER_BASE_NONE;


            /* Set channel mode as disable mode */
            ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                          eTMR_CH_CTRL_CHMODE_MASK,
                                          eTMR_CH_CTRL_CHMODE(ETMR_FUNCTION_MODE_DISABLE));

            /* Clear ICU refer interrupt flag */
            ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_STS_OFFSET32,  /*PRQA S 2985*/
                                         ((uint32)eTMR_STS_CH0F_MASK << EtmrChannelId)
#ifndef CPU_YTM32B1MC0
                                         | ((uint32)eTMR_STS_CH0NPF_MASK << EtmrChannelId)
                                         | ((uint32)eTMR_STS_CH0PPF_MASK << EtmrChannelId)
#endif
                                        );

            /* Disable capture interrupt */
            ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_INTE_OFFSET32,
                                           (uint32)eTMR_INTE_CH0IE_MASK << EtmrChannelId);

            /* Find the configuration information to the current etmr instance. */
            for (uint8 EtmrInstanceCount = 0U; EtmrInstanceCount < Icu_gConfigPtr->IcuEtmrConfigPtr->IcuEtmrCount; ++EtmrInstanceCount)
            {
                if (Icu_gConfigPtr->IcuEtmrConfigPtr[EtmrInstanceCount].IcuEtmrModule == EtmrInstanceId)
                {
                    break;
                }
            }

            /* Set module counter */
            EtmrMcConfig.HwChannelId = (uint8)EtmrInstanceId;
            EtmrMcConfig.ClockSource = ICU_MC_CLOCK_SOURCE_FASTBUSCLK;
            EtmrMcConfig.Prescale = 0U;
            EtmrMcConfig.CountMode = ETMR_MC_CH_MODE_CONTINUOUS;
            EtmrMcConfig.EnableNotification = FALSE;
            EtmrMcConfig.NotificationPtr = NULL_PTR;
            Icu_Etmr_Mc_InitChannel(&EtmrMcConfig);
            Icu_Etmr_Mc_StopChannel((uint16)(EtmrInstanceId << INSTANCE_OFFSET) | EtmrChannelId);
            Icu_Etmr_Mc_gChannelInfo[EtmrInstanceId].State = ETMR_MC_CHANNEL_STATE_UNINIT;

            Icu_gChannelInfo[ChannelIndex].PeriodTime = 0U;
            Etmr_Icu_gChannelInitState[ChannelIndex] = ETMR_ICU_CHANNEL_UNINIT;
            /* De-initialize ETMROPT in CIM. */
            Icu_Etmr_ClearExternalClockSource(EtmrInstanceId);
        }
        /* Move to next channel config pointer */
        ++IcuChannelConfigPtr;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17();
   
}
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)
ICU_FUNC void Icu_Lld_Etmr_EnableEdgeCount(Icu_ChannelType Channel)
{
    /* Clear edge counter value */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18();
    Icu_gChannelInfo[Channel].EdgeNumber = 0U;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18();
    /* Start channel capture function */
    Icu_Etmr_StartChannelCapture(Channel, NORMAL_SERVICE_ID);
}
void Icu_Lld_Etmr_DisableEdgeCount(Icu_ChannelType Channel)
{
    /*  *STOP channel Capture,but not Clear edge counter value* */
    Icu_Etmr_StopChannelCapture(Channel);
}

#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
ICU_FUNC void Icu_Lld_Etmr_StartSignalMeasurement(Icu_ChannelType Channel)
{
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;

    /* get hardware etmr channel id */
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    ChannelConfigPtr += Channel;/*PRQA S 0488*/
    /* Get eTMR module id and channel id */
    uint8 EtmrInstanceId = (uint8)(ChannelConfigPtr->IcuHwIpInstance & (((Icu_ChannelType)ICU_INSTANCE_ID_MASK) >> INSTANCE_OFFSET));
    uint8 EtmrChannelId = (uint8)(ChannelConfigPtr->IcuHwChannel & (Icu_ChannelType)ICU_CHANNEL_ID_MASK);
    /* Get eTMR instance base address */
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];
    /* Stop channel capture */
    Icu_Etmr_StopChannelCapture(Channel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_20();
    Icu_gChannelInfo[Channel].InputState = ICU_IDLE;
    /* Reset values of channel */
    Icu_gChannelInfo[Channel].EdgeNumber = 0U;
    Icu_gChannelInfo[Channel].ActiveTime = 0U;
    Icu_gChannelInfo[Channel].SMActiveState = ETMR_ICU_SM_ACTIVE_NONE;
#if defined (CPU_YTM32B1MC0)
    Icu_gChannelInfo[Channel].EtmrChannelValue = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress
            + (uint32)eTMR_CH_CVAL_OFFSET32((uint32)EtmrChannelId));
#endif
    /* Set channel to both edges active */
    ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                  eTMR_CH_CTRL_CAPEDGE_MASK,
                                  eTMR_CH_CTRL_CAPEDGE(ICU_BOTH_EDGES));

    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_20();

    /* Start channel capture function */
    Icu_Etmr_StartChannelCapture(Channel, NORMAL_SERVICE_ID);
}

ICU_FUNC void Icu_Lld_Etmr_StopSignalMeasurement(Icu_ChannelType Channel)
{
    /* Stop channel capture */
    Icu_Etmr_StopChannelCapture(Channel);
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_21();
    Icu_gChannelInfo[Channel].InputState = ICU_IDLE;
    Icu_gChannelInfo[Channel].SMActiveState = ETMR_ICU_SM_ACTIVE_NONE;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_21();
}
#endif


#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
ICU_FUNC Icu_ValueType Icu_Lld_Etmr_GetTimeElapsed(Icu_ChannelType Channel)
{
    Icu_ValueType ReturnValue = 0U;
    volatile Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;
    Icu_ValueType McOverFlowTimes1 = 0U;
    Icu_ValueType McOverFlowTimes2 = 0U;
    Icu_ValueType LevelTimes1 = 0U;
    Icu_ValueType LevelTimes2 = 0U;
    boolean InputLevelState;
    Icu_SignalMeasurementPropertyType ChannelMeasurementProperty;
    /* get hardware etmr channel id */
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    ChannelConfigPtr += Channel;/*PRQA S 0488*/
    /* Get eTMR module id and channel id */
    uint8 EtmrInstanceId = (uint8)(ChannelConfigPtr->IcuHwIpInstance & (((Icu_ChannelType)ICU_INSTANCE_ID_MASK) >> INSTANCE_OFFSET));
    uint8 EtmrChannelId = (uint8)(ChannelConfigPtr->IcuHwChannel & (Icu_ChannelType)ICU_CHANNEL_ID_MASK);
    /* Get eTMR instance base address */
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_23();
    if (ICU_ACTIVE == Icu_gChannelInfo[Channel].InputState)
    {
        InputLevelState = (boolean)ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_IOSTS_OFFSET32,
                          EtmrChannelId);
        ChannelMeasurementProperty = ChannelConfigPtr->SignalMeasurementProperty;
        /* When measurement property is "Low Time" */
        if (ICU_LOW_TIME == ChannelMeasurementProperty)
        {
            if ((boolean)STD_HIGH == InputLevelState)
            {
#if defined (CPU_YTM32B1MC0)
                McOverFlowTimes1 = Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes;
                LevelTimes1 = Icu_gChannelInfo[Channel].LowLevelTimes;
#else
                McOverFlowTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_NPCNTN_OFFSET32((uint32)EtmrChannelId));
                LevelTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_NPCNTV_OFFSET32((uint32)EtmrChannelId));
#endif
                Icu_gChannelInfo[Channel].EdgeNumber = 0U;
                Icu_gChannelInfo[Channel].InputState = ICU_IDLE;
            }
        }
        /* When measurement property is "High Time" */
        else if (ICU_HIGH_TIME == ChannelMeasurementProperty)
        {
            if ((boolean)STD_LOW == InputLevelState)
            {
#if defined (CPU_YTM32B1MC0)
                McOverFlowTimes1 = Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes;
                LevelTimes1 = Icu_gChannelInfo[Channel].HighLevelTimes;
#else
                McOverFlowTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_PPCNTN_OFFSET32((uint32)EtmrChannelId));
                LevelTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_PPCNTV_OFFSET32((uint32)EtmrChannelId));
#endif
                Icu_gChannelInfo[Channel].EdgeNumber = 0U;
                Icu_gChannelInfo[Channel].InputState = ICU_IDLE;
            }
        }
        /* When measurement property is "Period Time" */
        else
        {
            if (((ICU_RISING_EDGE == ChannelConfigPtr->IcuDefaultStartEdge) && ((boolean)STD_HIGH == InputLevelState)) ||
                    ((ICU_FALLING_EDGE == ChannelConfigPtr->IcuDefaultStartEdge) && ((boolean)STD_LOW == InputLevelState)))
            {
                /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                     * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                         */
#if defined (CPU_YTM32B1MC0)
                McOverFlowTimes1 = Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes;
                LevelTimes1 = Icu_gChannelInfo[Channel].LowLevelTimes;
#else
                McOverFlowTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_NPCNTN_OFFSET32((uint32)EtmrChannelId));   /*PRQA S 0404*/
                McOverFlowTimes2 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_PPCNTN_OFFSET32((uint32)EtmrChannelId));   /*PRQA S 0404*/
                LevelTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_NPCNTV_OFFSET32((uint32)EtmrChannelId));    /*PRQA S 0404*/
                LevelTimes2 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_PPCNTV_OFFSET32((uint32)EtmrChannelId));    /*PRQA S 0404*/
#endif
                Icu_gChannelInfo[Channel].EdgeNumber = FULL_MASK;
            }
            else
            {
                if (ICU_BOTH_EDGES == ChannelConfigPtr->IcuDefaultStartEdge)
                {
                    /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                         * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                             */
#if defined (CPU_YTM32B1MC0)
                    McOverFlowTimes1 = Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes;
                    LevelTimes1 = Icu_gChannelInfo[Channel].HighLevelTimes;
#else
                    McOverFlowTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_NPCNTN_OFFSET32((uint32)EtmrChannelId));  /*PRQA S 0404*/
                    McOverFlowTimes2 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_PPCNTN_OFFSET32((uint32)EtmrChannelId));  /*PRQA S 0404*/
                    LevelTimes1 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_NPCNTV_OFFSET32((uint32)EtmrChannelId));  /*PRQA S 0404*/
                    LevelTimes2 = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_CH_PPCNTV_OFFSET32((uint32)EtmrChannelId));  /*PRQA S 0404*/

#endif
                    Icu_gChannelInfo[Channel].EdgeNumber = 2U;
                }
                else
                {
                    Icu_gChannelInfo[Channel].EdgeNumber = 0U;
                }
            }
            Icu_gChannelInfo[Channel].InputState = ICU_IDLE;
        }
    }
    /* Calculate high or low level elapsed time */
    if ((McOverFlowTimes1 + McOverFlowTimes2) != 0U)
    {
        ReturnValue = ((McOverFlowTimes1 + McOverFlowTimes2) * Icu_gChannelInfo[Channel].PeriodTime) + LevelTimes1 + LevelTimes2;
    }
    else
    {
        ReturnValue = Icu_gChannelInfo[Channel].PeriodTime + LevelTimes1 + LevelTimes2;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_23();
    return ReturnValue;
}
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
ICU_FUNC void Icu_Lld_Etmr_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType *DutyCycleValues)
{
    Icu_ChannelConfigType ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr[Channel];


    Icu_ValueType McOverFlowTimes = 0U;
    Icu_ValueType LevelActiveTimes = 0U;
    /* Get eTMR module id and channel id */
    IcuEtmrInstanceType EtmrInstanceId = (IcuEtmrInstanceType)ChannelConfigPtr.IcuHwIpInstance;
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];
    Icu_gChannelInfo[Channel].PeriodTime = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_MOD_OFFSET32) + 1U;

    if (ICU_ACTIVE == Icu_gChannelInfo[Channel].InputState)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_24();

#if defined (CPU_YTM32B1MC0) 
    Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes = 0;
    Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes = 0;
#endif
        /* Get input level state,IOSTS of odd ch were not accurate,detection of IOSTS was canceled */
        if (ICU_HIGH_TIME == ChannelConfigPtr.SignalMeasurementProperty)
        {
            /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                 * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                 */
            LevelActiveTimes = Icu_gChannelInfo[Channel].HighLevelTimes + (Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes * Icu_gChannelInfo[Channel].PeriodTime);    /*PRQA S 0404*/
            McOverFlowTimes = Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes + Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes;   /*PRQA S 0404*/
            (void)McOverFlowTimes;

            DutyCycleValues->ActiveTime = LevelActiveTimes;
            DutyCycleValues->PeriodTime = 0U;
            Icu_gChannelInfo[Channel].EdgeNumber = FULL_MASK;
        }
        else if (ICU_LOW_TIME == ChannelConfigPtr.SignalMeasurementProperty)
        {
            /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                 * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                 */
            LevelActiveTimes = Icu_gChannelInfo[Channel].LowLevelTimes + (Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes * Icu_gChannelInfo[Channel].PeriodTime);   /*PRQA S 0404*/
            McOverFlowTimes = Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes + Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes;  /*PRQA S 0404*/
            (void)McOverFlowTimes;

            DutyCycleValues->ActiveTime = LevelActiveTimes;
            DutyCycleValues->PeriodTime = 0U;
            Icu_gChannelInfo[Channel].EdgeNumber = FULL_MASK;
        }
        else if (ICU_PERIOD_TIME == ChannelConfigPtr.SignalMeasurementProperty)
        {

            /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                 * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                 */
            LevelActiveTimes = Icu_gChannelInfo[Channel].LowLevelTimes + (Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes * Icu_gChannelInfo[Channel].PeriodTime); /*PRQA S 0404*/
            (void)LevelActiveTimes;

            DutyCycleValues->ActiveTime = 0U;
            /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                 * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                 */
            McOverFlowTimes = Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes + Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes;   /*PRQA S 0404*/
            DutyCycleValues->PeriodTime = (McOverFlowTimes * Icu_gChannelInfo[Channel].PeriodTime) +  /*PRQA S 0404*/
                                          Icu_gChannelInfo[Channel].HighLevelTimes + Icu_gChannelInfo[Channel].LowLevelTimes;
        }
        else if (ICU_DUTY_CYCLE == ChannelConfigPtr.SignalMeasurementProperty)
        {
            /*************************************************************/
            /**Icu_gChannelInfo[Channel].InputLevel form IOSTS*/
            /**IOSTS Even-numbered channels are normal; odd-numbered channels do not reflect the IO state correctly*/
            /**only ch0,ch2,ch4,ch6 work normally in each instance*/
            /************************************************************/
            if ((ICU_RISING_EDGE == Icu_gChannelInfo[Channel].StartEdge) || (ICU_BOTH_EDGES == Icu_gChannelInfo[Channel].StartEdge))
            {
                /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                         * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                         */
                LevelActiveTimes = Icu_gChannelInfo[Channel].HighLevelTimes + (Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes * Icu_gChannelInfo[Channel].PeriodTime); /*PRQA S 0404*/
            }
            else if (ICU_FALLING_EDGE == Icu_gChannelInfo[Channel].StartEdge)
            {
                LevelActiveTimes = Icu_gChannelInfo[Channel].LowLevelTimes + (Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes * Icu_gChannelInfo[Channel].PeriodTime); /*PRQA S 0404*/
            }
            else
            {
                /* Do nothing */
            }
            DutyCycleValues->ActiveTime = LevelActiveTimes;
            /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                 * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                 */
            McOverFlowTimes = Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes + Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes;  /*PRQA S 0404*/
            /* MR12 RULE 1.3 VIOLATION: Two volatile variables cannot be evaluated directly.
                 * In this specific case, need to compare the values of two registers, thus, couldn't adhere to M3CM Rule-1.3
                 */
            DutyCycleValues->PeriodTime = (McOverFlowTimes * Icu_gChannelInfo[Channel].PeriodTime) +  /*PRQA S 0404*/
                                          Icu_gChannelInfo[Channel].HighLevelTimes + Icu_gChannelInfo[Channel].LowLevelTimes;
        }
        else
        {
            Icu_gChannelInfo[Channel].HighLevelTimes = 0U;
            Icu_gChannelInfo[Channel].LowLevelTimes = 0U;
        }
        Icu_gChannelInfo[Channel].HighLevelMcOverflowTimes = 0U;
        Icu_gChannelInfo[Channel].LowLevelMcOverflowTimes = 0U;
        Icu_gChannelInfo[Channel].InputState = ICU_IDLE;
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_24();
    }


}
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
ICU_FUNC void Icu_Lld_Etmr_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType *BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;
    /* get hardware etmr channel id */
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    ChannelConfigPtr += Channel;  /*PRQA S 0488*/

    Icu_Lld_Etmr_StopTimestamp(Channel);
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_31();
    Etmr_Icu_TimeStampInfo[Channel].BufferPtr = BufferPtr;
    Etmr_Icu_TimeStampInfo[Channel].BufferSize = BufferSize;
    Etmr_Icu_TimeStampInfo[Channel].NotifyInterval = NotifyInterval;
    Etmr_Icu_TimeStampInfo[Channel].TimestampNotificationPtr = ChannelConfigPtr->TimestampNotificationPtr;
    Etmr_Icu_TimeStampInfo[Channel].BufferType = ChannelConfigPtr->TimestampBufferProperty;

    /* Start channel capture function */
    Icu_Etmr_StartChannelCapture(Channel, NORMAL_SERVICE_ID);
    /* Update the channel timestamp state to "RUNNING" */
    Etmr_Icu_TimeStampInfo[Channel].TimeStampModeState = ETMR_ICU_TIMESTAMP_STATE_RUNNING;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_31();
}
ICU_FUNC void Icu_Lld_Etmr_StopTimestamp(Icu_ChannelType Channel)
{
    /* Reset timestamp infomation variables */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_25();
    Etmr_Icu_TimeStampInfo[Channel].BufferPtr = NULL_PTR;
    Etmr_Icu_TimeStampInfo[Channel].BufferSize = 0U;
    Etmr_Icu_TimeStampInfo[Channel].NotifyInterval = 0U;
    Etmr_Icu_TimeStampInfo[Channel].TimestampNotificationPtr = NULL_PTR;
    /* The function Icu_StartTimestamp shall start the capturing of
       timer values on the edges to an external buffer, at the beginning of the buffer
       Trace : SWS_Icu_00317 */
    /* Reset the timestamp value index to 0 */
    Etmr_Icu_TimeStampInfo[Channel].TimestampIndex = 0U;

    /* Stop channel capture */
    Icu_Etmr_StopChannelCapture(Channel);
    /* Set the channel timestamp state to "STOPPED" */
    Etmr_Icu_TimeStampInfo[Channel].TimeStampModeState = ETMR_ICU_TIMESTAMP_STATE_STOPPED;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_25();
}
#endif
#if (ICU_GET_INPUT_STATE_API == STD_ON)
Icu_InputStateType Icu_Lld_Etmr_GetInputState(Icu_ChannelType Channel)
{
    Icu_InputStateType ReturnValue;
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02();
    ReturnValue = Icu_gChannelInfo[Channel].InputState;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02();
    /* Once the function Icu_GetInputState has returned the
       status ICU_ACTIVE, the function Icu_GetInputState shall set the stored status
       to ICU_IDLE until the next edge is detected.
       Trace : SWS_Icu_00032 */
    if (ICU_ACTIVE == ReturnValue)
    {
        /* Reset values of channel */
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02();
        Icu_gChannelInfo[Channel].EdgeNumber = 0U;
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02();
    }
    else
    {
        if (Icu_gChannelInfo[Channel].EdgeNumber > 3U)
        {
            Icu_gChannelInfo[Channel].EdgeNumber = 0U;
        }
    }
    return ReturnValue;
}
#endif
#if 0
ICU_FUNC Icu_IndexType Icu_Lld_Etmr_GetTimestampIndex(Icu_ChannelType Channel)
{
    /* The function Icu_GetTimestampIndex shall read the
       timestamp index of the given channel, which is the next to be written.
       Trace : SWS_Icu_00071 */
    return Etmr_Icu_TimeStampInfo[Channel].TimestampIndex;
}
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)
#if 0
ICU_FUNC void Icu_Lld_EnableNotification(Icu_ChannelType Channel)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_26();
    Etmr_Icu_gEdgeNotification[Channel].IsNotificationEnable = TRUE;
    Etmr_Icu_gEdgeNotification[Channel].EdgeNotificationPtr = Icu_gConfigPtr->ChannelConfigPtr[Channel].SignalNotificationPtr;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_26();
    Icu_Etmr_StartChannelCapture(Channel, NORMAL_SERVICE_ID);
}
#endif
#endif
/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
ICU_FUNC static void Icu_Etmr_StartChannelCapture(Icu_ChannelType Channel, uint32 ServiceID)
{
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;
    uint32 SYNCValue = 0;

    /* get hardware etmr channel id */
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    ChannelConfigPtr += Channel; /*PRQA S 0488*/
    /* Get eTMR module id and channel id */
    uint8 EtmrInstanceId = (uint8)(ChannelConfigPtr->IcuHwIpInstance & (((Icu_ChannelType)ICU_INSTANCE_ID_MASK) >> ICU_INSTANCE_SHIFT));
    uint8 EtmrChannelId = (uint8)(ChannelConfigPtr->IcuHwChannel & (Icu_ChannelType)ICU_CHANNEL_ID_MASK);
    /* Get eTMR instance base address */
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];
    /* Clear capture interrupt flag */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_27();
    ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_STS_OFFSET32,      /*PRQA S 2985*/
                                 ((uint32)eTMR_STS_CH0F_MASK << EtmrChannelId)
#ifndef CPU_YTM32B1MC0
                                 | ((uint32)eTMR_STS_CH0NPF_MASK << EtmrChannelId)
                                 | ((uint32)eTMR_STS_CH0PPF_MASK << EtmrChannelId)
#endif
                                );
    if (SETACTIVATION_SERVICE_ID != ServiceID)
    {
        /* Enable capture interrupt */
        ICU_ETMR_REG_ADDR32_SET_BITS(EtmrBaseAddress + eTMR_INTE_OFFSET32,
                                     (uint32)eTMR_INTE_CH0IE_MASK << EtmrChannelId);
    }

    /* Set channel mode as ICU mode */
    ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                  eTMR_CH_CTRL_CHMODE_MASK,
                                  eTMR_CH_CTRL_CHMODE(ETMR_FUNCTION_MODE_ICU));
    /*SET MOD value takes effect immediately.*/
    if (ChannelConfigPtr->IcuMeasurementMode == ICU_MODE_TIMESTAMP)
    {
        SYNCValue = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_SYNC_OFFSET32);
        ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_SYNC_OFFSET32,
                                      eTMR_SYNC_REGLD_MASK,
                                      eTMR_SYNC_REGLD(0X03U));
        ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_SYNC_OFFSET32,
                                      eTMR_SYNC_TRIGS0_MASK,
                                      eTMR_SYNC_TRIGS0(0X01U));
        ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_SYNC_OFFSET32,
                                      eTMR_SYNC_SWTRIG_MASK,
                                      eTMR_SYNC_SWTRIG(0X01U));
        ICU_ETMR_REG_ADDR32_WRITE(EtmrBaseAddress + eTMR_SYNC_OFFSET32, SYNCValue);

    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_27();
}
ICU_FUNC static void Icu_Etmr_StopChannelCapture(Icu_ChannelType Channel)
{
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;

    /* get hardware etmr channel id */
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
     */
    ChannelConfigPtr += Channel; /*PRQA S 0488*/
    /* Get eTMR module id and channel id */
    uint8 EtmrInstanceId = (uint8)(ChannelConfigPtr->IcuHwIpInstance & (((Icu_ChannelType)ICU_INSTANCE_ID_MASK) >> ICU_INSTANCE_SHIFT));
    uint8 EtmrChannelId = (uint8)(ChannelConfigPtr->IcuHwChannel & (Icu_ChannelType)ICU_CHANNEL_ID_MASK);
    /* Get eTMR instance base address */
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[EtmrInstanceId];

    /* DIsable capture interrupt */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_28();
    ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_INTE_OFFSET32,
                                   (uint32)eTMR_INTE_CH0IE_MASK << EtmrChannelId);

    /* Set channel mode as disable mode */
    ICU_ETMR_REG_ADDR32_AEARWRITE(EtmrBaseAddress + eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                  eTMR_CH_CTRL_CHMODE_MASK,
                                  eTMR_CH_CTRL_CHMODE(ETMR_FUNCTION_MODE_DISABLE));
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_28();
}
ICU_FUNC void Icu_Lld_Etmr_EnableEdgeDetectionNotification(Icu_ChannelType Channel)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_29();
    Etmr_Icu_gEdgeNotification[Channel].IsNotificationEnable = TRUE;
    Etmr_Icu_gEdgeNotification[Channel].EdgeNotificationPtr = Icu_gConfigPtr->ChannelConfigPtr[Channel].SignalNotificationPtr;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_29();
    Icu_Etmr_StartChannelCapture(Channel, NORMAL_SERVICE_ID);
}
ICU_FUNC void Icu_Lld_Etmr_EnableEdgeDetection(Icu_ChannelType ChannelIndex)
{
    Icu_Etmr_StartChannelCapture(ChannelIndex, NORMAL_SERVICE_ID);
}
ICU_FUNC void Icu_Lld_Etmr_DisableEdgeDetection(Icu_ChannelType ChannelIndex)
{
    Icu_Etmr_StopChannelCapture(ChannelIndex);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#ifdef __cplusplus
}
#endif

/* End of file Icu_Lld_Etmr.c */

