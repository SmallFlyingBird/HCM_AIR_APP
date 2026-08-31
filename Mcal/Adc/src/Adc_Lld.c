/**
* @file    Adc_Lld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Adc_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#include "Platform_Types.h"
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0306 Rule 11.4: A conversion should not be performed between a pointer to object and an
 *                    integer type.
 *
 * PRQA S 0326 Rule 11.6: A cast shall not be performed between pointer to void and an arithmetic
 *                        type.
 *
 * PRQA S 3673 Rule 8.13: A pointer should point to a const-qualified type whenever possible.
 *
 * PRQA S 2985 Rule 2.2: There shall be no dead code.
 *
 * PRQA S 2986 Rule 2.2: There shall be no dead code.
 *
 * PRQA S 1505 Rule 8.7: Functions and objects should not be defined with external linkage
 *                       if they are referenced in only one translation unit
 * PRQA S 0488 Rule 18.4: The +, -, += and -= operators sho uld not be applied to an
 *                         expression of pointer type
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Adc.h"
#include "Adc_Lld.h"
#include "SchM_Adc.h"
#include "Adc_Lld_Reg.h"
#ifdef ADC_DMA_SUPPORTED
#include "CddDma.h"
#endif



/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_LLD_VENDOR_ID_C                      (180)
#define ADC_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ADC_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define ADC_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define ADC_LLD_SW_MAJOR_VERSION_C               (2)
#define ADC_LLD_SW_MINOR_VERSION_C               (3)
#define ADC_LLD_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC_LLD header file are of the same vendor */
#if (ADC_LLD_VENDOR_ID_C != ADC_LLD_VENDOR_ID)
#error "Adc_Lld.c and Adc_Lld.h have different vendor ids"
#endif

/* Check if source file and ADC_LLD header file are of the same Autosar version */
#if (( ADC_LLD_AR_RELEASE_MAJOR_VERSION_C != ADC_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_MINOR_VERSION_C != ADC_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_REVISION_VERSION_C != ADC_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_Lld.c and Adc_Lld.h are different"
#endif

/* Check if source file and ADC_LLD header file are of the same Software version */
#if (( ADC_LLD_SW_MAJOR_VERSION_C != ADC_LLD_SW_MAJOR_VERSION) || \
      ( ADC_LLD_SW_MINOR_VERSION_C != ADC_LLD_SW_MINOR_VERSION) || \
      ( ADC_LLD_SW_PATCH_VERSION_C != ADC_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_Lld.c and Adc_Lld.h are different"
#endif

/* Check if source file and ADC_LLD_REG header file are of the same vendor */
#if (ADC_LLD_VENDOR_ID_C != ADC_LLD_REG_VENDOR_ID)
#error "Adc_Lld.c and Adc_Lld_Reg.h have different vendor ids"
#endif

/* Check if source file and ADC_LLD_REG header file are of the same Autosar version */
#if (( ADC_LLD_AR_RELEASE_MAJOR_VERSION_C != ADC_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_MINOR_VERSION_C != ADC_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_REVISION_VERSION_C != ADC_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_Lld.c and Adc_Lld_Reg.h are different"
#endif

/* Check if source file and ADC_LLD_REG header file are of the same Software version */
#if (( ADC_LLD_SW_MAJOR_VERSION_C != ADC_LLD_REG_SW_MAJOR_VERSION) || \
      ( ADC_LLD_SW_MINOR_VERSION_C != ADC_LLD_REG_SW_MINOR_VERSION) || \
      ( ADC_LLD_SW_PATCH_VERSION_C != ADC_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_Lld.c and Adc_Lld_Reg.h are different"
#endif


/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
ADC_CONST static volatile ADC_Type *const Adc_RegBase[ADC_INSTANCE_COUNT] = ADC_BASE_PTRS;

#if(ADC_HW_TRIGGER_API == STD_ON)
ADC_CONST static volatile CIM_Type *const Adc_CimBase = CIM_BASE_PTRS;
#endif
#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
#ifdef ADC_DMA_SUPPORTED
#define ADC_START_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"
ADC_VAR static CddDma_TransferConfigType Adc_DmaTransferConfig[ADC_MAX_HW_UNITS];
#define ADC_STOP_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"
#endif


/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
#define ADC_MAX_CHANNEL_IN_GROUP    8U

#define ADC_TWO_BYTE                2U

#define ADC_MAX_UINT16              0xFFFFU

/*Reset value for adc registers*/
#define ADC_RESET_ZERO_VALUE        0x00000000U
#define ADC_RESET_ONE_VALUE         0xFFFFFFFFU
#if defined (CPU_YTM32B1ME0)||defined (CPU_YTM32B1MD1)
#define ADC_CFG0_DEFAULT_VALUE      0x07000010U
#elif defined (CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
#define ADC_CFG0_DEFAULT_VALUE      0x07400010U
#else
#endif
#define ADC_CFG1_DEFAULT_VALUE      0x000002A0U
#define ADC_SMP_DEFAULT_VALUE       0x00000002U
#define ADC_WDTH_DEFAULT_VALUE      0x0FFF0000U
#define ADC_CHNSEL_DEFAULT_VALUE    (uint8)0x00U

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief   Set ADC prescaler
 * @param[out]   PtrAdcBase ADC base address pointer
 * @param[in]    Prescale ADC prescale
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetPrescaler(volatile ADC_Type *PtrAdcBase, uint8 Prescale)
{
    uint32 Temp = PtrAdcBase->CFG1;
    Temp &= ~ADC_CFG1_PRS_MASK;
    Temp |= ADC_CFG1_PRS(Prescale);
    PtrAdcBase->CFG1 = Temp;
}

/**
 * @brief   Set ADC start up time
 * @param[out]   PtrAdcBase ADC base address pointer
 * @param[in]    StartUpTime ADC start up time
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetStartUpTime(volatile ADC_Type *PtrAdcBase, uint8 StartUpTime)
{
    uint32 Temp = PtrAdcBase->CFG1;
    Temp &= ~ADC_CFG1_STCNT_MASK;
    /*MR12 RULE 2.2 VIOLATION: For the sake of stylistic uniformity of register manipulation functions,
     *                         there is a shift as '<<0'.
     */
    Temp |= ADC_CFG1_STCNT(StartUpTime);/*PRQA S 2985*/
    PtrAdcBase->CFG1 = Temp;
}

/**
 * @brief   Set ADC sample time
 * @param[out]   PtrAdcBase ADC base address pointer
 * @param[in]    SampleTime ADC sample time
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetSampleTime(volatile ADC_Type *PtrAdcBase, uint8 SampleTime)
{
    uint32 Temp = PtrAdcBase->SMP;
    Temp &= ~ADC_SMP_SMP_MASK;
    /*MR12 RULE 2.2 VIOLATION: For the sake of stylistic uniformity of register manipulation functions,
     *                         there is a shift as '<<0'.
     */
    Temp |= ADC_SMP_SMP(SampleTime);/*PRQA S 2985*/
    PtrAdcBase->SMP = Temp;
}

/*!
 * @brief Sets the sequence channel ID by sequence index
 * @param[in] PtrAdcBase adc base pointer
 * @param[in] ChselIdx Sequence index
 * @param[in] ChannelId channel id
 * @return void
 */
ADC_FUNC LOCAL_INLINE void ADC_Lld_SetSequeceChannel(volatile ADC_Type *PtrAdcBase,
        uint8 ChselIdx,
        uint16 ChannelId)
{
    if (ChselIdx < ADC_MAX_CHANNEL_IN_GROUP)
    {
        PtrAdcBase->CHSEL[ChselIdx] = (uint8)ChannelId;
    }
}



/**
 * @brief   Set ADC stop conversion
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetStopConversion(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= ADC_CTRL_ADSTOP_MASK;
}

/**
 * @brief   Get ADC stop status
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       Boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetStopStatus(volatile ADC_Type const   *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & ADC_CTRL_ADSTOP_MASK) >> ADC_CTRL_ADSTOP_SHIFT);
}

/**
 * @brief   Set ADC start conversion
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetStartConversion(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= ADC_CTRL_ADSTART_MASK;
}

/**
 * @brief   Get ADC start status
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       Boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetStartConversion(volatile ADC_Type const   *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & ADC_CTRL_ADSTART_MASK) >> ADC_CTRL_ADSTART_SHIFT);
}

/**
 * @brief   Disable ADCx all interrupt
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_DisableAllInt(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->INTE = 0x00000000;
}
/**
 * @brief  Sets the ADC Trigger Mode
 * @param[out]  PtrAdcBase ADC base address pointer
 * @param[in]  TriggerSource ADC trigger source
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetTriggerMode(volatile ADC_Type *PtrAdcBase, Adc_TriggerSourceType TriggerSource)
{
    uint32 Temp = PtrAdcBase->CFG0;
#if defined(CPU_YTM32B1ME0)||defined (CPU_YTM32B1MD1)||defined (CPU_YTM32B1MC0)
    Temp &= ~ADC_CFG0_TRIGMD_MASK;
    Temp |= ADC_CFG0_TRIGMD(TriggerSource);
#elif defined (CPU_YTM32B1HA0)
    Temp &= ~ADC_CFG0_NORTMD_MASK;
    Temp |= ADC_CFG0_NORTMD(TriggerSource);
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
    PtrAdcBase->CFG0 = Temp;
}

/**
 * @brief  Set the ADDIS to disable ADC unit
 * @param[out]  PtrAdcBase ADC base address pointer
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetADDIS(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= ADC_CTRL_ADDIS_MASK;
}

/**
 * @brief  Get ADCx Disable or not.
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetADDISStatus(volatile ADC_Type const *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & ADC_CTRL_ADDIS_MASK) >> ADC_CTRL_ADDIS_SHIFT);
}

/**
 * @brief  Set TSEN to enable tempreture sensor
 * @param[out]  PtrAdcBase ADC base address pointer
 * @param[in]   EnableTSEN enable or disable tempreture sensor
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetTSEN(volatile ADC_Type *PtrAdcBase, boolean EnableTSEN)
{
    uint32 Temp = PtrAdcBase->CTRL;
    if (TRUE == EnableTSEN)
    {
        Temp |= ADC_CTRL_TSEN_MASK;
    }
    else
    {
        Temp &= ~ADC_CTRL_TSEN_MASK;
    }
    PtrAdcBase->CTRL = Temp;
}

/**
 * @brief  Set ADEN to enable ADC unit
 * @param[out]  PtrAdcBase ADC base address pointer
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetADEN(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= ADC_CTRL_ADEN_MASK;
}
/**
 * @brief  Get ADCx Enable or not.
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetADEN(volatile ADC_Type const *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & ADC_CTRL_ADEN_MASK) >> ADC_CTRL_ADEN_SHIFT);
}
/**
 * @brief  Get ADCx End of Sequence Interrupt Flag
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetEOSEQIntFlag(volatile ADC_Type const *PtrAdcBase)
{
    uint32 Temp = PtrAdcBase->STS;
    boolean Ret = FALSE;
    Temp = (Temp & ADC_STS_EOSEQ_MASK) >> ADC_STS_EOSEQ_SHIFT;
    if (Temp != 0u)
    {
        Ret = TRUE;
    }
    return Ret;
}

/**
 * @brief  Get ADCx FIFO Empty Flag
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetFIFOEmptyFlag(volatile ADC_Type const   *PtrAdcBase)
{
    uint32 Temp = PtrAdcBase->STS;
    boolean Ret = FALSE;
    Temp = (Temp & ADC_STS_EMPTY_MASK) >> ADC_STS_EMPTY_SHIFT;
    if (Temp != 0u)
    {
        Ret = TRUE;
    }
    return Ret;
}

/**
 * @brief  Clear ADCx End of Sequence Interrupt Flag
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_ClearEOSEQIntFlag(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->STS = ADC_STS_EOSEQ_MASK;
}

/*!
 * @brief Gets the result from result FIFO
 * @param[in] PtrAdcBase adc base pointer
 * @return uint16
 */
ADC_FUNC LOCAL_INLINE uint16 Adc_Lld_ReadFIFO(volatile ADC_Type const *PtrAdcBase)
{
    return ((uint16)(PtrAdcBase->FIFO));
}

/**
 * @brief configure the adc CFG0
 * @param[out] PtrAdcBase adc base pointer
 * @param[in] SetValue the set value
 * @return void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetRegisterCFG0(volatile ADC_Type *PtrAdcBase, uint32 SetValue)
{
    PtrAdcBase->CFG0 = SetValue;
}

/**
 * @brief Clear all interrupt flag
 * @param[out] PtrAdcBase adc base pointer
 * @return void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_ClearRegsiterSTS(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->STS = ADC_RESET_ONE_VALUE;
}

/**
 * @brief Configure the adc INTE
 * @param[out] PtrAdcBase adc base pointer
 * @param[in] SetValue the set value
 * @return void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetRegiterINTE(volatile ADC_Type *PtrAdcBase, uint32 SetValue)
{
    PtrAdcBase->INTE = SetValue;
}

/**
 * @brief Reset all registers to power on default value
 * @param[out] PtrAdcBase adc base pointer
 * @return void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_ResetRegister(volatile ADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL = ADC_RESET_ZERO_VALUE;
    PtrAdcBase->STS = ADC_RESET_ONE_VALUE;
    PtrAdcBase->INTE = ADC_RESET_ZERO_VALUE;
    PtrAdcBase->CFG0 = ADC_CFG0_DEFAULT_VALUE;
    PtrAdcBase->CFG1 = ADC_CFG1_DEFAULT_VALUE;
    PtrAdcBase->SMP  = ADC_SMP_DEFAULT_VALUE;
    PtrAdcBase->WDCTRL = ADC_RESET_ZERO_VALUE;
#if defined(CPU_YTM32B1ME0)||defined (CPU_YTM32B1MD1)||defined (CPU_YTM32B1MC0)
    PtrAdcBase->WDTH = ADC_WDTH_DEFAULT_VALUE;
#elif defined (CPU_YTM32B1HA0)
    for (uint8 LoopCnt = 0; LoopCnt < ADC_WDTH_COUNT; ++LoopCnt)
    {
        PtrAdcBase->WDTH[LoopCnt] = ADC_WDTH_DEFAULT_VALUE;
    }
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
    for (uint8 LoopCnt = 0; LoopCnt < ADC_MAX_CHANNEL_IN_GROUP; ++LoopCnt)
    {
        PtrAdcBase->CHSEL[LoopCnt] = ADC_CHNSEL_DEFAULT_VALUE;
    }
}

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief   Set the ADC hardware trigger source
 * @param[in]   AdcHwIndex ADC hardware index
 * @param[in]   HwTriggerSource hardware trigger source
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetHwTriggerSource(uint8 AdcHwIndex, Adc_HwTriggerSourceType HwTriggerSource)
{
    uint32 Temp;
#if defined (CPU_YTM32B1ME0)
    Temp = Adc_CimBase->CTRL;
    if (ADC_0 == AdcHwIndex)
    {
        Temp &= ~CIM_CTRL_ADC0_TRIG_SEL_MASK;
        Temp |= CIM_CTRL_ADC0_TRIG_SEL(HwTriggerSource);
    }
    else
    {
        Temp &= ~CIM_CTRL_ADC1_TRIG_SEL_MASK;
        Temp |= CIM_CTRL_ADC1_TRIG_SEL(HwTriggerSource);
    }
    Adc_CimBase->CTRL = Temp;
#elif defined (CPU_YTM32B1MD1)||defined (CPU_YTM32B1MC0)
    Temp = Adc_CimBase->CTRL;
    Temp &= ~CIM_CTRL_ADC0_TRIG_SEL_MASK;
    Temp |= CIM_CTRL_ADC0_TRIG_SEL(HwTriggerSource);
    Adc_CimBase->CTRL = Temp;
    (void)AdcHwIndex;
#elif defined (CPU_YTM32B1HA0)
    Temp = Adc_CimBase->CTRL0;
    if (ADC_0 == AdcHwIndex)
    {
        Temp &= ~CIM_CTRL0_ADC0_NORMT_SEL_MASK;
        Temp |= CIM_CTRL0_ADC0_NORMT_SEL(HwTriggerSource);
    }
    else
    {
        Temp &= ~CIM_CTRL0_ADC1_NORMT_SEL_MASK;
        Temp |= CIM_CTRL0_ADC1_NORMT_SEL(HwTriggerSource);
    }
    Adc_CimBase->CTRL0 = Temp;
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
}
#endif

#ifdef ADC_DMA_SUPPORTED
/*
 * @brief   Get the ADC hardware index in adc hardware unit condfiguration array.
 * @param[in]   AdcHwUnit ADC hardware unit
 * @return  uint8 ADC hardware index in hardware unit condfiguration array
*/
ADC_FUNC static uint8 Adc_Lld_HwIndexCaculate(uint8 AdcHwUnit)
{
    uint8 LoopCnt;
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1ME0)
    for (LoopCnt = 0; LoopCnt < Adc_ConfigPtr->HwUnitCfgNum; ++LoopCnt)
    {
        if (Adc_ConfigPtr->HwUnitUserCfg[LoopCnt].HwUnitId == AdcHwUnit)
        {
            break;
        }
    }
#else
    LoopCnt = AdcHwUnit;
#endif
    return LoopCnt;
}

/**
 * @brief   Set Dma TCD for ADCx
 * @param[in]   AdcHwIndex ADC hardware index
 * @param[in]   VirtualChannel DMA virtual channel
 * @param[in]   DestAddr destination address
 * @param[in]   TransferCount transfer count in bytes
 * @return  void
*/
ADC_FUNC static void Adc_Lld_DmaTcdInit(uint8 AdcHwIndex, CddDma_ChannelType VirtualChannel, uint32 DestAddr, uint32 TransferCount)
{
    /*LOAD trancsfer configuration to TDC*/
    Adc_DmaTransferConfig[AdcHwIndex].SrcAddr = (uint32)(&(Adc_RegBase[AdcHwIndex]->FIFO));
    Adc_DmaTransferConfig[AdcHwIndex].DestAddr = DestAddr;
    Adc_DmaTransferConfig[AdcHwIndex].SrcTransferSize = DMA_TRANSFER_SIZE_2_BYTE;
    Adc_DmaTransferConfig[AdcHwIndex].DestTransferSize = DMA_TRANSFER_SIZE_2_BYTE;
    Adc_DmaTransferConfig[AdcHwIndex].SrcOffset = 0;
    Adc_DmaTransferConfig[AdcHwIndex].DestOffset = (sint16)((uint32)1U << ((uint8)DMA_TRANSFER_SIZE_2_BYTE));
    Adc_DmaTransferConfig[AdcHwIndex].TransferLoopByteCount = TransferCount;
    Adc_DmaTransferConfig[AdcHwIndex].TriggerCount = 1u;
    (void)CddDma_SetLogicChannelTransfer(VirtualChannel, (uint32)(&(Adc_RegBase[AdcHwIndex]->FIFO)), DestAddr, &Adc_DmaTransferConfig[AdcHwIndex]);
    /*Install the call back function for DMA transfer compeleted irq*/
    /* MR12 RULE 11.6 VIOLATION:In this specific case, needs to convert the Parameter to instance, thus, couldn't adhere
     *                           to M3CM Rule-11.6
     */
    CddDma_InstallCallback(VirtualChannel, Adc_Lld_DmaTransEndNotification, (void *)((uint32)AdcHwIndex)); /*PRQA S 0326*/
    CddDma_StartChannel(VirtualChannel);
}

/**
 * @brief   Update the Dma TCD for ADCx
 * @param[in]   AdcHwIndex ADC hardware index
 * @param[in]   GroupIndex ADC group index
 * @return  void
*/
ADC_FUNC static void Adc_Lld_UpdataDmaTcdForGroup(uint8 AdcHwUnit, uint16 GroupIndex)
{
    uint32 DestAddr = 0;
    uint32 TransferCount = 0;
    uint8 DmaVirChannel;
#ifdef ADC_ERRATA_ERR0002
    uint8 ChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum + 1U;
    TransferCount = ADC_TWO_BYTE * ((uint32)Adc_GroupResult[GroupIndex].GroupLoadChnNum + 1U);
#else
    uint8 ChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
    TransferCount = ADC_TWO_BYTE * ((uint32)Adc_GroupResult[GroupIndex].GroupLoadChnNum);
#endif
    /* MR12 Rule 11.4 VIOLATION: In this specific case, the Adc result buffer address need use to configure
        *                           the DMA dest Parameter, couldn't adhere to M3CM Rule-11.4
        */
    /*PRQA S 0306 ++*/
    /*Modify the Dest address for a bug, when adc configured to hw trigger with DMA, if the result is not
    read before a new trigger signal generated, the dest address must minus 2*channel number.*/
    uint8 TempSampleCnt;
    if (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples)
    {
        TempSampleCnt = Adc_GroupResult[GroupIndex].GroupSampleCount - 1U;
    }
    else
    {
        TempSampleCnt = Adc_GroupResult[GroupIndex].GroupSampleCount;
    }
    /*NOSONAR - The Dma init function need a address for parameter ,not a pointer*/
    DestAddr = (uint32) & (Adc_GroupResult[GroupIndex].GroupValueBuf[(TempSampleCnt * ChannelNum) + Adc_GroupResult[GroupIndex].GroupCompChnNum]);/*NOSONAR */
    /*PRQA S 0306 --*/
    DmaVirChannel = Adc_ConfigPtr->HwUnitUserCfg[Adc_Lld_HwIndexCaculate(AdcHwUnit)].DmaChannel;
    Adc_Lld_DmaTcdInit(AdcHwUnit, DmaVirChannel, DestAddr, TransferCount);
}
#endif/*ADC_DMA_SUPPORTED*/

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief check the adc result is in the range
 * @param[out] GroupIndex adc group index
 * @param[in] TempResult the adc result
 * @return boolean TRUE:in the range;FALSE:out of the range
*/
ADC_FUNC static boolean Adc_Lld_LimitCheck(uint16 GroupIndex, uint16 TempResult)
{
    boolean LimitCheckResultFlag = FALSE;
    switch (Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelRangeSelect)
    {
        case ADC_RANGE_UNDER_LOW:
        {
            if (TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_BETWEEN:
        {
            if ((TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit) && \
                    (TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit))
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_OVER_HIGH:
        {
            if (TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_NOT_UNDER_LOW:
        {
            if (TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_NOT_BETWEEN:
        {
            if ((TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit) || \
                    (TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit))
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_NOT_OVER_HIGH:
        {
            if (TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        default:
        {
            LimitCheckResultFlag = TRUE;
        }
        break;
    }
    return LimitCheckResultFlag;
}
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief This function is used to get the auto off state of the ADC hardware unit.
 * @param AdcHwUnit ADC hardware unit number.
 * @return boolean TRUE if the ADC hardware unit is in auto off state, FALSE otherwise.
 */
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetAutoOff(uint8 AdcHwUnit)
{
    boolean AutoOff = FALSE;
    if ((Adc_RegBase[AdcHwUnit]->CFG0 & ADC_CFG0_AUTOOFF_MASK) != 0U)
    {
        AutoOff = TRUE;
    }
    return AutoOff;
}

/**
 * @brief Configures the auto off state of the ADC hardware unit.
 * @param AdcHwUnit ADC hardware unit number.
 * @param AutoOff TRUE if the ADC hardware unit is in auto off state, FALSE otherwise.
 * @return void
 */
ADC_FUNC static void Adc_Lld_AutoOffCfg(uint8 AdcHwUnit, boolean AutoOff)
{
    uint32 Temp = Adc_RegBase[AdcHwUnit]->CFG0;
    if (TRUE == AutoOff)
    {
        Temp |= ADC_CFG0_AUTOOFF_MASK;
#if  defined(CPU_YTM32B1MD1)||defined (CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
        Temp &= ~ADC_CFG0_LPEN_MASK;
#endif
    }
    else
    {
        Temp &= ~ADC_CFG0_AUTOOFF_MASK;
#if  defined(CPU_YTM32B1MD1)||defined (CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
        Temp |= ADC_CFG0_LPEN_MASK;
#endif
    }
    Adc_RegBase[AdcHwUnit]->CFG0 = Temp;
}
#endif /* ADC_LOW_POWER_STATES_SUPPORT == STD_ON */

/**
 * @brief  Disable ADC unit
 * @param[in]  AdcHwUnit Adc hardware index
 * @param[in]  TimeoutLimit timeout value
 * @return  void
 */
ADC_FUNC static void Adc_Lld_Disable(uint8 AdcHwUnit, uint32 TimeoutLimit)
{
    uint32 TimeOutCount = TimeoutLimit;
    Adc_Lld_SetADDIS(Adc_RegBase[AdcHwUnit]);
    while ((TRUE == Adc_Lld_GetADDISStatus(Adc_RegBase[AdcHwUnit])) && (TimeOutCount > 0u))
    {
        --TimeOutCount;
    }
}

/**
 * @brief  Enable ADC unit
 * @param[in] AdcHwIndex Adc hardware index
 * @param[in] TimeoutLimit timeout value
 * @return  void
*/
ADC_FUNC  static void Adc_Lld_Enable(uint8 AdcHwIndex, uint32 TimeoutLimit)
{
    uint32 TimeOutCount = TimeoutLimit;
    Adc_Lld_SetADEN(Adc_RegBase[AdcHwIndex]);
    while ((FALSE == Adc_Lld_GetADEN(Adc_RegBase[AdcHwIndex])) && (TimeOutCount > 0u))
    {
        --TimeOutCount;
    }
}
/**
 * @brief Clear all interrupt flag
 *
 * @param AdcHwUnit  ADC hardware index
 * @return void
 */
ADC_FUNC static void  Adc_Lld_ClearAllIntcFlag(uint8 AdcHwUnit)
{
    Adc_Lld_ClearRegsiterSTS(Adc_RegBase[AdcHwUnit]);
}

/**
 * @brief Reload data to Adc hardware and start conversion
 *
 * @param AdcHwIndex Adc hardware index
 * @return void
 */
ADC_FUNC static void Adc_Lld_RestartAdcHardWare(uint8 AdcHwIndex)
{
    uint16 Group = ADC_MAX_UINT16;
    uint16 GroupIndex = 0;
    Group = Adc_HwStatus[AdcHwIndex].SwNormalQueue[0];
    GroupIndex = Adc_Lld_GroupIndexCheck(Group);
    Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
    Adc_Lld_StartConversion(AdcHwIndex);
}

/**
 * @brief  Clear the adc FIFO invalid data
 * @details This function is used to clear the adc FIFO invalid data.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return      void
*/
ADC_FUNC static void Adc_Lld_ClearFIFOInvalidData(uint8 AdcHwUnit)
{
    uint32 FifoCount = ADC_TIMEOUT_VALUE;
    while ((TRUE != Adc_Lld_GetFIFOEmptyFlag(Adc_RegBase[AdcHwUnit])) && (FifoCount > 0u))
    {
        (void)Adc_Lld_ReadFIFO(Adc_RegBase[AdcHwUnit]);
        --FifoCount;
    }
}

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
/*************************************************************************************
*This function used to get the running group index.
**************************************************************************************/
ADC_FUNC uint16 Adc_Lld_GetRunningGroupIndex(uint8 AdcHwIndex)
{
    uint16 TempOnGoGroupIndex = ADC_MAX_UINT16;
#if (ADC_HW_TRIGGER_API==STD_ON)
    if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_MAX_UINT16)
    {
        TempOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup);
    }
    else
    {
        if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u)
        {
            TempOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
        }
    }
#else
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u)
    {
        TempOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
    }
#endif
    return TempOnGoGroupIndex;
}
/************************************************************************
 *                       Adc_Lld_InitTempSensor
************************************************************************/
ADC_FUNC void Adc_Lld_InitTempSensor(boolean TempSensorEnable)
{
    Adc_Lld_SetTSEN(Adc_RegBase[ADC_0], TempSensorEnable);
}

/************************************************************************
 *                       Adc_Lld_HwUnitEnable
************************************************************************/
ADC_FUNC void Adc_Lld_HwUnitEnable(uint8 AdcHwUnit)
{
    Adc_Lld_Enable(AdcHwUnit, ADC_TIMEOUT_VALUE);
}

/************************************************************************
 *                       Adc_Lld_HwClockInit
*************************************************************************/
ADC_FUNC void Adc_Lld_HwClockInit(const Adc_HwUnitType *HwUnitCfgPtr)
{
    volatile ADC_Type *PtrAdcBase = Adc_RegBase[HwUnitCfgPtr->HwUnitId];
    /* set ADC function clock prescaler*/
    Adc_Lld_SetPrescaler(PtrAdcBase, HwUnitCfgPtr->Prescale);
    /* set ADC start up time*/
    Adc_Lld_SetStartUpTime(PtrAdcBase, HwUnitCfgPtr->StartupTime);
}

/************************************************************************
 *                       Adc_Lld_StopConversion
*************************************************************************/
ADC_FUNC void Adc_Lld_StopConversion(uint8 AdcHwUnit)
{
    uint32 TimeoutLimit = 0;
    TimeoutLimit = ADC_TIMEOUT_VALUE;
    Adc_Lld_SetStopConversion(Adc_RegBase[AdcHwUnit]);
    while ((TRUE == Adc_Lld_GetStopStatus(Adc_RegBase[AdcHwUnit])) && (TimeoutLimit > 0u))
    {
        --TimeoutLimit;
    }
}

/************************************************************************
 *                       Adc_Lld_StartConversion
*************************************************************************/
ADC_FUNC void Adc_Lld_StartConversion(uint8 AdcHwUnit)
{
    if (FALSE == Adc_Lld_GetStartConversion(Adc_RegBase[AdcHwUnit]))
    {
        /**empty FIFO to prepare the next conversion*/
        Adc_Lld_ClearFIFOInvalidData(AdcHwUnit);
#ifdef ADC_DMA_SUPPORTED
        /*Set Dma config if need*/
        uint16 GroupIndex = Adc_Lld_GetRunningGroupIndex(AdcHwUnit);
        if (ADC_DMA_ENABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg)
        {
            Adc_Lld_UpdataDmaTcdForGroup(AdcHwUnit, GroupIndex);
        }
#endif/*ADC_DMA_SUPPORTED*/
        Adc_Lld_SetStartConversion(Adc_RegBase[AdcHwUnit]);
    }
    else
    {
        /*do nothing*/
    }
}

/************************************************************************
 *                       Adc_Lld_DisableIntcandHwTrigger
*************************************************************************/
ADC_FUNC void Adc_Lld_DisableIntcandHwTrigger(uint8 AdcHwUnit)
{
    /* disable ADCx all interrupt*/
    Adc_Lld_DisableAllInt(Adc_RegBase[AdcHwUnit]);
    /* disable ADCx hardware trigger*/
    Adc_Lld_SetTriggerMode(Adc_RegBase[AdcHwUnit], ADC_TRIGG_SRC_SW);
}

/************************************************************************
 *                       Adc_Lld_DeinitHwUnit
*************************************************************************/
ADC_FUNC void Adc_Lld_DeinitHwUnit(uint8 AdcHwUnit)
{
    Adc_Lld_StopConversion(AdcHwUnit);
    Adc_Lld_ClearFIFOInvalidData(AdcHwUnit);
    Adc_Lld_Disable(AdcHwUnit, ADC_TIMEOUT_VALUE);
    Adc_Lld_ResetRegister(Adc_RegBase[AdcHwUnit]);
}

/************************************************************************
 *                       Adc_Lld_ReadSeqConvEndIntFlag
*************************************************************************/
ADC_FUNC boolean Adc_Lld_ReadSeqConvEndIntFlag(uint8 AdcHwUnit)
{
    boolean Temp = FALSE;
    Temp = Adc_Lld_GetEOSEQIntFlag(Adc_RegBase[AdcHwUnit]);
    return Temp;
}

/************************************************************************
 *                       Adc_Lld_ClearSeqConvEndIntFlag
*************************************************************************/
ADC_FUNC void Adc_Lld_ClearSeqConvEndIntFlag(uint8 AdcHwUnit)
{
    Adc_Lld_ClearEOSEQIntFlag(Adc_RegBase[AdcHwUnit]);
}

/************************************************************************
 *                       Adc_Lld_ReadConversionResults
*************************************************************************/
#if (ADC_ENABLE_LIMIT_CHECK==STD_ON)
ADC_FUNC boolean Adc_Lld_ReadConversionResults(uint8 AdcHwUnit, uint16 GroupIndex, Adc_ValueGroupType *ResultBufPtr,
        uint16 ChannelCount, Adc_ResolutionType Resolution)
{
    uint16 Temp = 0;
    boolean LimitCheckResultFlag = TRUE;
#ifdef ADC_ERRATA_ERR0002
    (void)Adc_Lld_ReadFIFO(Adc_RegBase[AdcHwUnit]);
#endif
    for (uint8 InterLoopCount = 0; InterLoopCount < ChannelCount; ++InterLoopCount)
    {
        Temp = Adc_Lld_ReadFIFO(Adc_RegBase[AdcHwUnit]);
        if ((TRUE == Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLimitCheck) && \
                (ADC_RANGE_ALWAYS != Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelRangeSelect) && \
                (FALSE == Adc_Lld_LimitCheck(GroupIndex, Temp)))
        {
            LimitCheckResultFlag = FALSE;
        }
        else
        {
#if (ADC_ALIGN_AUTOMATIC==FALSE)&&(ADC_RESULT_ALIGNMENT==ADC_ALIGN_LEFT)
            ResultBufPtr[InterLoopCount] = (Temp << (4u + Resolution * 2u));
#else
            ResultBufPtr[InterLoopCount] = Temp;
            (void)Resolution;
#endif
        }
    }
    return LimitCheckResultFlag;
}
#else
ADC_FUNC void Adc_Lld_ReadConversionResults(uint8 AdcHwUnit, Adc_ValueGroupType *ResultBufPtr,
        uint16 ChannelCount, Adc_ResolutionType Resolution)
{
#ifdef ADC_ERRATA_ERR0002
    (void)Adc_Lld_ReadFIFO(Adc_RegBase[AdcHwUnit]);
#endif
    for (uint8 InterLoopCount = 0; InterLoopCount < ChannelCount; ++InterLoopCount)
    {
#if (ADC_ALIGN_AUTOMATIC==FALSE)&&(ADC_RESULT_ALIGNMENT==ADC_ALIGN_LEFT)
        ResultBufPtr[InterLoopCount] = (Adc_Lld_ReadFIFO(Adc_RegBase[AdcHwUnit]) << (4u + Resolution * 2u));
#else
        ResultBufPtr[InterLoopCount] = Adc_Lld_ReadFIFO(Adc_RegBase[AdcHwUnit]);
        (void)Resolution;
#endif
    }
}
#endif /* ADC_ENABLE_LIMIT_CHECK==STD_ON */


/************************************************************************
 *                       Adc_Lld_LoadGroupToHwUnit
*************************************************************************/
ADC_FUNC void Adc_Lld_LoadGroupToHwUnit(uint8 AdcHwUnit, uint16 GroupIndex)
{
    volatile ADC_Type *const PtrAdcBase = Adc_RegBase[AdcHwUnit];
    uint8 GroupChannelNum = 0u;
    uint32 TempReg = 0u;
    /*Stop ADC unit*/
    Adc_Lld_StopConversion(AdcHwUnit);
    /*ADC_SetSampleTime*/
    Adc_Lld_SetSampleTime(PtrAdcBase, Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelSampTime);
    /*get group channels number*/
#ifdef ADC_ERRATA_ERR0002
    GroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum + 1U;
    Adc_GroupResult[GroupIndex].GroupLoadChnNum = (uint8)(Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum);
#else
    if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum > ADC_MAX_CHANNEL_IN_GROUP)
    {
        if ((0u == Adc_GroupResult[GroupIndex].GroupCompChnNum) || \
                ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum - \
                  Adc_GroupResult[GroupIndex].GroupCompChnNum) > ADC_MAX_CHANNEL_IN_GROUP))
        {
            GroupChannelNum = ADC_MAX_CHANNEL_IN_GROUP;
        }
        else
        {
            GroupChannelNum = (uint8)(Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum - \
                                      Adc_GroupResult[GroupIndex].GroupCompChnNum);
        }
    }
    else
    {
        GroupChannelNum = (uint8)Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
    }
    Adc_GroupResult[GroupIndex].GroupLoadChnNum = GroupChannelNum;
#endif
    /*Configure the CFG0 register*/
    /*ADC_SetOverrunModeFlag*/
    /*ADC_SetAutoffEnableFlag*/
    /*ADC_SetResolution*/
    /*ADC_SetTriggerMode*/
    /*ADC_SetWaitEnableFlag*/
    /*ADC_SetSequenceNumber*/
    /*MR12 RULE 2.2 VIOLATION: For the sake of stylistic uniformity of register manipulation functions,
     *                         there is code as '|0' and '<<0'.
     */
    /*PRQA S 2985,2986 ++*/
    TempReg = ADC_CFG0_OVRMD(FALSE) | ADC_CFG0_AUTOOFF(FALSE) | \
              ADC_CFG0_RES(Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution) | \
              ADC_CFG0_WAIT(FALSE) | ADC_CFG0_SEQLEN((uint32)GroupChannelNum - 1u);
#if(ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
    if (TRUE == Adc_Lld_GetAutoOff(AdcHwUnit))
    {
        TempReg |= ADC_CFG0_AUTOOFF_MASK;
#if  defined(CPU_YTM32B1MD1)||defined (CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
        TempReg &= ~ADC_CFG0_LPEN_MASK;
#endif
    }
    else
    {
        TempReg &= ~ADC_CFG0_AUTOOFF_MASK;
#if  defined(CPU_YTM32B1MD1)||defined (CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
        TempReg |= ADC_CFG0_LPEN(TRUE);
#endif
    }
#endif
#if defined(CPU_YTM32B1ME0)||defined (CPU_YTM32B1MD1)||defined (CPU_YTM32B1MC0)
    TempReg |= ADC_CFG0_TRIGMD(Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc);
#elif defined (CPU_YTM32B1HA0)
    TempReg |= ADC_CFG0_NORTMD(Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc);
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
    /*Adc set result align*/
#if (ADC_ALIGN_AUTOMATIC==TRUE)
    TempReg |= ADC_CFG0_ALIGN(ADC_RESULT_ALIGNMENT);
#endif
    /*ADC_SetDMAEnableFlag and DMA water mark*/
#ifdef ADC_DMA_SUPPORTED
    if (ADC_DMA_ENABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg)
    {
        TempReg |= ADC_CFG0_DMAEN(TRUE) | ADC_CFG0_WM((uint32)GroupChannelNum - 1u);
    }
    else
#endif /*ADC_DMA_SUPPORTED*/
    {
        /*MR12 RULE 2.2 VIOLATION: For the sake of stylistic uniformity of register manipulation functions,
             *                         there is code as '|0'.
             */
        TempReg |= ADC_CFG0_DMAEN(FALSE) | ADC_CFG0_WM(0); /*PRQA S 2985*/
    }
    /*continuous mode or short mode*/
#if defined(CPU_YTM32B1ME0)
    TempReg |= ADC_CFG0_DISCEN(FALSE) | ADC_CFG0_CONT(FALSE);
#elif defined(CPU_YTM32B1MD1)||defined (CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
    TempReg |= ADC_CFG0_MODE(0x00);
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
    /*PRQA S 2985,2986 --*/
    Adc_Lld_SetRegisterCFG0(PtrAdcBase, TempReg);
    /*Set conversion sequence*/
#ifdef ADC_ERRATA_ERR0002
    ADC_Lld_SetSequeceChannel(PtrAdcBase, 0, Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannels[0]);
    for (uint8 InterLoopCount = 1; InterLoopCount < GroupChannelNum; ++InterLoopCount)
    {
        ADC_Lld_SetSequeceChannel(PtrAdcBase, InterLoopCount, \
                                  Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannels[InterLoopCount - 1U]);
    }
#else
    for (uint8 InterLoopCount = 0; InterLoopCount < GroupChannelNum; ++InterLoopCount)
    {
        ADC_Lld_SetSequeceChannel(PtrAdcBase, InterLoopCount, \
                                  Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannels[Adc_GroupResult[GroupIndex].GroupCompChnNum + InterLoopCount]);
    }
#endif
    /* Clear all interrupt flag */
    Adc_Lld_ClearRegsiterSTS(PtrAdcBase);
    /* set ADC intc enable */
    /* SWS_Adc_00156 */
    TempReg = 0u;
    if (ADC_INTC_ENABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg)
    {
        /*enable EOSEQIE in INTE*/
        TempReg |= ADC_INTE_EOSEQIE(1);
    }
    Adc_Lld_SetRegiterINTE(PtrAdcBase, TempReg);
    /*config hw trigger source when hw trigger enable*/
#if (ADC_HW_TRIGGER_API == STD_ON)
    if (ADC_TRIGG_SRC_HW == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc)
    {
        Adc_Lld_SetHwTriggerSource(AdcHwUnit, Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->HwTrigSrc);
    }
#endif
    /*ADC Enable*/
    /*ADC Start*/
}

/************************************************************************************
* Check the Group index is in Groups array or not.
*************************************************************************************/
ADC_FUNC uint16 Adc_Lld_GroupIndexCheck(Adc_GroupType Group)
{
    uint16 TempIndex = 0u;
    uint8 InterLoopCount;
    for (InterLoopCount = 0u; InterLoopCount < Adc_ConfigPtr->GroupCfgNum; ++InterLoopCount)
    {
        if (Group == Adc_ConfigPtr->GroupUserCfg[InterLoopCount].GroupId)
        {
            TempIndex = InterLoopCount;
            break;
        }
    }
    /*Group ID is invalid,return Adc_ConfigPtr->GroupCfgNum*/
    if (InterLoopCount >= Adc_ConfigPtr->GroupCfgNum)
    {
        TempIndex = Adc_ConfigPtr->GroupCfgNum;
    }
    return TempIndex;
}


/************************************************************************************
* Update the group status in IRQ.
*************************************************************************************/
ADC_FUNC void Adc_Lld_GroupStatusUpdata(uint16 GroupIndex)
{
    /*update group status*/
    switch (Adc_GroupResult[GroupIndex].GroupStatus)
    {
        case ADC_IDLE:
            Adc_GroupResult[GroupIndex].GroupSampleCount = 0u;
            break;
        case ADC_BUSY:
        case ADC_COMPLETED:
        {
            if (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples)
            {
                Adc_GroupResult[GroupIndex].GroupStatus = ADC_STREAM_COMPLETED;
                Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples;
            }
            else
            {
                Adc_GroupResult[GroupIndex].GroupStatus = ADC_COMPLETED;
            }
        }
        break;
        case ADC_STREAM_COMPLETED:
        {
            Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples;
        }
        break;
        default:
            /*Nothing to do*/
            break;
    }
}

/************************************************************************
 *                       Adc_Lld_QueueDataUpdata
 ***********************************************************************/
ADC_FUNC Std_ReturnType Adc_Lld_QueueDataUpdata(uint8 AdcHwIndex, uint16 GroupIndex)
{
    Std_ReturnType TempRet = E_NOT_OK;
    /*The group state is stream completed, the ADC hw need to load another group in queue to
      conversion or stop if no group in queue*/
    if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_STREAM_COMPLETED)
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05();
        if (ADC_TRIGG_SRC_SW == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc)
        {
#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING == STD_ON))
            if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 1u)
            {
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
                for (uint8 InterLoopCount = 0; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex; ++InterLoopCount)
                {
                    /*NOSONAR - This is a pointer copy operation, which is safe to do*/
                    Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1u]; /*NOSONAR*/
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
                    Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount + 1];/*NOSONAR*/
#endif /*(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)*/
                }
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = ADC_MAX_UINT16;
            }
            else
#endif /*((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING == STD_ON))*/
            {
                Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
            }
            TempRet = E_OK;
        }
#if 0
#if (ADC_HW_TRIGGER_API==STD_ON)
        else if ((ADC_TRIGG_SRC_HW == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc) && \
                 (ADC_ACCESS_MODE_STREAMING == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupAccessMode) && \
                 (ADC_STREAM_BUFFER_LINEAR == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingBufferMode))
        {
            Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup = ADC_MAX_UINT16;
            TempRet = E_OK;
        }
#endif
#endif
        else
        {
            /*do nothing*/
        }
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
    }
    return TempRet;
}

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/************************************************************************
 *                       Adc_Lld_SetPowerState
 ***********************************************************************/
ADC_FUNC Std_ReturnType Adc_Lld_SetPowerState(Adc_PowerStateType PowerState)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    for (uint8 AdcHwUnitId = 0U; AdcHwUnitId < ADC_MAX_HW_UNITS; ++AdcHwUnitId)
    {
        if (ADC_FULL_POWER == PowerState)
        {
            Adc_Lld_AutoOffCfg(AdcHwUnitId, FALSE);
        }
        else if (ADC_LOW_POWER == PowerState)
        {
            Adc_Lld_AutoOffCfg(AdcHwUnitId, TRUE);
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnValue;
}
#endif /* (ADC_LOW_POWER_STATES_SUPPORT == STD_ON) */


/************************************************************************
 *                       Adc_Lld_Adc0DmaTransEndNotification
 ***********************************************************************/
ADC_FUNC void Adc_Lld_IrqProcess(uint8 AdcHwIndex)
{
    /*judge interrput flag*/
    uint16 GroupIndex = 0;
    /*read which group is busy in queue*/
    GroupIndex = Adc_Lld_GetRunningGroupIndex(AdcHwIndex);
    if ((TRUE == Adc_Lld_ReadSeqConvEndIntFlag(AdcHwIndex)) && (GroupIndex != ADC_MAX_UINT16))
    {
        /*Clear the end queue intc flag*/
        Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
        /* Get adc datas */
#if (ADC_HW_TRIGGER_API==STD_ON)
        /*Handles the number of times the hardware group collection is completed, because the
            hardware triggers the group in the ADC_STREAM_COMPLETED state to allow the collection to continue*/
        if ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW) && \
                (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples) && \
                (ADC_STREAM_COMPLETED == Adc_GroupResult[GroupIndex].GroupStatus))
        {
            Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples - 1u;
        }
#endif
        Adc_ChannelType GroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
        uint8 TempSampleCnt = (Adc_GroupResult[GroupIndex].GroupSampleCount * GroupChannelNum) + Adc_GroupResult[GroupIndex].GroupCompChnNum;
        /*Read Adc data to result buffer and align*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /* SWS_Adc_00446 ,SWS_Adc_00447, SWS_Adc_00448*/
        boolean LimitCheckResultFlag = TRUE;
        /*buffer filled with data from FIFO register*/
        LimitCheckResultFlag = Adc_Lld_ReadConversionResults(AdcHwIndex, GroupIndex, \
                               & (Adc_GroupResult[GroupIndex].GroupValueBuf[TempSampleCnt]), \
                               Adc_GroupResult[GroupIndex].GroupLoadChnNum, \
                               Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution);
        if (FALSE == LimitCheckResultFlag)
        {
            if ((Adc_GroupResult[GroupIndex].GroupCompChnNum + Adc_GroupResult[GroupIndex].GroupLoadChnNum) >= \
                    Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
            {
                Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
            }
        }
        else
#else
        /*buffer filled with data from FIFO register*/
        /* MR12 RULE 18.4 VIOLATION: The integer Value 1 is being added or subtracted from a pointer.
                     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
                     */
        /*PRQA S 0488 ++*/
        Adc_Lld_ReadConversionResults(AdcHwIndex, (Adc_GroupResult[GroupIndex].GroupValueBuf + TempSampleCnt), \
                                      Adc_GroupResult[GroupIndex].GroupLoadChnNum, \
                                      Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution);
        /*PRQA S 0488 --*/
#endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        {
            /* SWS_Adc_00325 */
            Adc_GroupResult[GroupIndex].GroupCompChnNum += Adc_GroupResult[GroupIndex].GroupLoadChnNum;
            if (Adc_GroupResult[GroupIndex].GroupCompChnNum >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
            {
                Adc_GroupResult[GroupIndex].GroupSampleCount += 1u;
                Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
                Adc_Lld_GroupStatusUpdata(GroupIndex);
            }
        }
        Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
        /*updata queue data*/
        (void)Adc_Lld_QueueDataUpdata(AdcHwIndex, GroupIndex);
#if ADC_GRP_NOTIF_CAPABILITY==STD_ON
        /* call notification api for user if enable*/
        if ((ADC_NOTIFICATION_ENABLED == Adc_GroupResult[GroupIndex].NotificationEnFlag) && \
                (ADC_BUSY != Adc_GroupResult[GroupIndex].GroupStatus) && \
                (0u == Adc_GroupResult[GroupIndex].GroupCompChnNum))
        {
            Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->NotificationFunc();
        }
#endif
        /*reload group configuration and restart convert,when the queue is not empty*/
#if (ADC_HW_TRIGGER_API==STD_ON)
        if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_MAX_UINT16)
        {
            /*keep the group*/
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
        }
        else if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u)
        {
            /*load the remaining channels or next group to ADC HW and start conversion*/
            Adc_Lld_RestartAdcHardWare(AdcHwIndex);
        }
#else
        if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u)
        {
            /*load the remaining channels or next group to ADC HW and start conversion*/
            Adc_Lld_RestartAdcHardWare(AdcHwIndex);
        }
#endif
        else
        {
            /*No group to be convert, stop adc hw*/
            Adc_Lld_StopConversion(AdcHwIndex);
        }
    }
    else
    {
        Adc_Lld_ClearAllIntcFlag(AdcHwIndex);
    }
}

#ifdef ADC_DMA_SUPPORTED
/************************************************************************
 *                       Adc_Lld_DmaTransEndNotification
 ***********************************************************************/
/* MR12 RULE 8.13 VIOLATION: In this specific case, to avoid introducing more problems, thus, couldn't adhere to M3CM Rule-8.13
 * MR12 RULE 8.7 VIOLATION: In this specific case, this function is isr call back for DMA_Irq, thus, couldn't adhere to M3CM Rule-8.7
 */
ADC_FUNC void Adc_Lld_DmaTransEndNotification(void *Parameter)  /*PRQA S 3673,1505*/
{
    /* MR12 RULE 11.4 VIOLATION:In this specific case, needs to convert the Parameter to instance, thus, couldn't adhere
     *                           to M3CM Rule-11.6
     */
    uint8 AdcHwIndex = (uint8)((uint32)Parameter); /*PRQA S 0326*/
    uint16 GroupIndex = 0u;
    Adc_ChannelType GroupChannelNum = 0U;
    uint8 InterLoopCount = 0;
    uint8 DmaVirChannel;
    DmaVirChannel = Adc_ConfigPtr->HwUnitUserCfg[Adc_Lld_HwIndexCaculate(AdcHwIndex)].DmaChannel;
    CddDma_StopChannel(DmaVirChannel);
    Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
    /*read which group is busy in queue*/
    GroupIndex =  Adc_Lld_GetRunningGroupIndex(AdcHwIndex);
    GroupChannelNum = Adc_GroupResult[GroupIndex].GroupLoadChnNum;
#ifdef ADC_ERRATA_ERR0002
    uint8 TempRstCount = Adc_GroupResult[GroupIndex].GroupSampleCount;
    for (InterLoopCount = 1U; InterLoopCount < (GroupChannelNum + 1U); ++InterLoopCount)
    {
        Adc_GroupResult[GroupIndex].GroupValueBuf[((TempRstCount * (GroupChannelNum + 1U)) + InterLoopCount) - 1U] = \
                Adc_GroupResult[GroupIndex].GroupValueBuf[(TempRstCount * (GroupChannelNum + 1U)) + InterLoopCount];
    }
#endif
#if (ADC_HW_TRIGGER_API==STD_ON)
    /*Handles the number of times the hardware group collection is completed, because the
        hardware triggers the group in the ADC_STREAM_COMPLETED state to allow the collection to continue*/
    if ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW) && \
            (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples) && \
            (ADC_STREAM_COMPLETED == Adc_GroupResult[GroupIndex].GroupStatus))
    {
        Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples - 1u;
    }
#endif
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    boolean LimitCheckResultFlag = TRUE;
    /* SWS_Adc_00446 ,SWS_Adc_00447, SWS_Adc_00448*/
    if ((TRUE == Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLimitCheck) && \
            (ADC_RANGE_ALWAYS != Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelRangeSelect))
    {
        for (InterLoopCount = 0u; InterLoopCount < GroupChannelNum; ++InterLoopCount)
        {
            LimitCheckResultFlag = Adc_Lld_LimitCheck(GroupIndex, \
                                   Adc_GroupResult[GroupIndex].GroupValueBuf[Adc_GroupResult[GroupIndex].GroupCompChnNum + InterLoopCount]);
            if (FALSE == LimitCheckResultFlag)
            {
                break;
            }
        }
    }
    if (TRUE == LimitCheckResultFlag)
#endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    {
#if (ADC_ALIGN_AUTOMATIC==FALSE)&&(ADC_RESULT_ALIGNMENT==ADC_ALIGN_LEFT)
        /* Get adc datas */
        uint16 TempSampleCnt = Adc_GroupResult[GroupIndex].GroupSampleCount * \
                               Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
        /* align dispose*/
        for (InterLoopCount = 0u; InterLoopCount < GroupChannelNum; InterLoopCount++)
        {
            *(Adc_GroupResult[GroupIndex].GroupValueBuf + TempSampleCnt + GroupChannelNum + InterLoopCount) = \
                    (*(Adc_GroupResult[GroupIndex].GroupValueBuf + TempSampleCnt + GroupChannelNum + InterLoopCount) << \
                     (4u + Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution * 2u));
        }
#endif
        /*Add sample times for the Group*/
        Adc_GroupResult[GroupIndex].GroupCompChnNum += Adc_GroupResult[GroupIndex].GroupLoadChnNum;
        if (Adc_GroupResult[GroupIndex].GroupCompChnNum >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
        {
            Adc_GroupResult[GroupIndex].GroupSampleCount += 1u;
            Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
            /* SWS_Adc_00325 */
            Adc_Lld_GroupStatusUpdata(GroupIndex);
        }
        (void)GroupChannelNum;
        (void)InterLoopCount;
    }
    Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
    /*updata queue data*/
    (void)Adc_Lld_QueueDataUpdata(AdcHwIndex, GroupIndex);
#if ADC_GRP_NOTIF_CAPABILITY==STD_ON
    /* call notification api for user if enable*/
    if ((ADC_NOTIFICATION_ENABLED == Adc_GroupResult[GroupIndex].NotificationEnFlag) && \
            (ADC_BUSY != Adc_GroupResult[GroupIndex].GroupStatus) && \
            (0u == Adc_GroupResult[GroupIndex].GroupCompChnNum))
    {
        Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->NotificationFunc();
    }
#endif
    /*reload group configuration and restart convert,when the queue is not empty*/
#if (ADC_HW_TRIGGER_API==STD_ON)
    if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_MAX_UINT16)
    {
        /*Only when continuous hardware triggers the acquisition, the DMA TCD needs to be adjusted.*/
        if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupId)
        {
            /*keep the group and config the DMA*/
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
            Adc_Lld_UpdataDmaTcdForGroup(AdcHwIndex, GroupIndex);
        }
    }
    else if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u)
    {
        /*load the remaining channels or next group to ADC HW and start conversion*/
        Adc_Lld_RestartAdcHardWare(AdcHwIndex);
    }
#else
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u)
    {
        /*load the remaining channels or next group to ADC HW and start conversion*/
        Adc_Lld_RestartAdcHardWare(AdcHwIndex);
    }
#endif
    else
    {
        /*No group to be convert, stop adc hw*/
        Adc_Lld_StopConversion(AdcHwIndex);
    }
}
#endif/*ADC_DMA_SUPPORTED*/

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Adc_Lld.c */

