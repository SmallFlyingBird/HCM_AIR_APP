/**************************************************************************************************/
/**
 * @file      : Adc_Drv.c
 * @brief     : Adc driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Drv
 *  @brief Adc low lever driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Adc_Drv.h"
#include "Tdg_Adc_Drv.h"
#include "SchM_Adc.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ADC_DRV_C_VENDOR_ID                   0x00B3U
#define ADC_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define ADC_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define ADC_DRV_C_SW_MAJOR_VERSION            1U
#define ADC_DRV_C_SW_MINOR_VERSION            2U
#define ADC_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Adc_Drv.h are the same vendor */
#if (ADC_DRV_C_VENDOR_ID != ADC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Adc_Drv.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same Autosar version */
#if ((ADC_DRV_C_AR_RELEASE_MAJOR_VERSION != ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (ADC_DRV_C_AR_RELEASE_MINOR_VERSION != ADC_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (ADC_DRV_C_AR_RELEASE_REVISION_VERSION != ADC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Drv.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are of the same Software version */
#if ((ADC_DRV_C_SW_MAJOR_VERSION != ADC_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (ADC_DRV_C_SW_MINOR_VERSION != ADC_DRV_H_SW_MINOR_VERSION) ||                                 \
     (ADC_DRV_C_SW_PATCH_VERSION != ADC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Drv.c and Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same vendor */
#if (ADC_DRV_C_VENDOR_ID != TDG_ADC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Adc_Drv.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Autosar version */
#if ((ADC_DRV_C_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (ADC_DRV_C_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (ADC_DRV_C_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Drv.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Software version */
#if ((ADC_DRV_C_SW_MAJOR_VERSION != TDG_ADC_DRV_H_SW_MAJOR_VERSION) ||                             \
     (ADC_DRV_C_SW_MINOR_VERSION != TDG_ADC_DRV_H_SW_MINOR_VERSION) ||                             \
     (ADC_DRV_C_SW_PATCH_VERSION != TDG_ADC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Drv.c and Tdg_Adc_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((ADC_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (ADC_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Adc_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Adc.h are the same Autosar version */
    #if ((ADC_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_ADC_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (ADC_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_ADC_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Adc_Drv.c and SchM_Adc.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/**
 * @brief ADC calibration channel number
 */
#define ADC_DRV_CALIBRATION_CHANNEL (22U)

/**
 * @brief Reset value of ADC stable time
 */
#define ADC_DRV_STABLE_TIME_RESET_VALUE (0x3FU)

/** @} end of Private_MacroDefinition */

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

#define ADC_START_SEC_CONST_PTR
#include "Adc_MemMap.h"

/**
 *  @brief ADC peripheral (ADC0 ADC1) base address array
 */
static Reg_Adc_BfType *const Adc_Drv_AdcRegBfPtr[ADC_DRV_INSTANCE_NUM] = {
    (Reg_Adc_BfType *)ADC0_BASE_ADDR, /*!< ADC0 base address */
    (Reg_Adc_BfType *)ADC1_BASE_ADDR  /*!< ADC1 base address */
};
static Reg_Adc_WType *const Adc_Drv_AdcRegWPtr[ADC_DRV_INSTANCE_NUM] = {
    (Reg_Adc_WType *)ADC0_BASE_ADDR, /*!< ADC0 base address */
    (Reg_Adc_WType *)ADC1_BASE_ADDR  /*!< ADC1 base address */
};

#define ADC_STOP_SEC_CONST_PTR
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"
/**
 * @brief List of pointer to ADC Driver configuration.
 */
static const Adc_Drv_ConfigType *Adc_Drv_ConfigList[ADC_DRV_INSTANCE_NUM];

/**
 * @brief List of pointer to ADC Driver Group configuration.
 */
static const Adc_Drv_GroupConfigType *Adc_Drv_GroupConfigList[ADC_DRV_MAX_GROUPS];

#define ADC_STOP_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/**
 * @brief ADC Driver state array
 */
static Adc_Drv_StateStructType Adc_Drv_StateArray[ADC_DRV_INSTANCE_NUM];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_DRV_DMA_USED == STD_ON)
    #if (ADC_DRV_0_ENABLE == STD_ON)
void Adc_Drv_0_DmaIrqHandler(uint32 LogicChIndex);
    #endif /* (ADC_DRV_0_ENABLE == STD_ON) */

    #if (ADC_DRV_1_ENABLE == STD_ON)
void Adc_Drv_1_DmaIrqHandler(uint32 LogicChIndex);
    #endif /* (ADC_DRV_1_ENABLE == STD_ON) */
#endif     /* (ADC_DRV_DMA_USED == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
LOCAL_INLINE void Adc_Drv_SetTdgTriggerCmdBuf(Reg_Adc_BfType                   *ADCx,
                                              const ADC_Drv_CmdBufferType       CmdBufIndex,
                                              const ADC_Drv_PositiveChannelType Channel,
                                              const boolean                     InterruptEnable);

static void Adc_Drv_ClearFifo(const uint8 Instance);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief     This function configures command buffer for TDG.
 *
 * @param[in] ADCx: ADC Register base address
 * @param[in] CmdBufferIndex: Index of Command buffer
 * @param[in] Channel: Positive channel to be selected.
 * @param[in] InterruptEnable: enable/disable interrupt to be set, Enable(TRUE) and Disable(FALSE).
 *
 * @return    None
 */
LOCAL_INLINE void Adc_Drv_SetTdgTriggerCmdBuf(Reg_Adc_BfType                   *ADCx,
                                              const ADC_Drv_CmdBufferType       CmdBufIndex,
                                              const ADC_Drv_PositiveChannelType Channel,
                                              const boolean                     InterruptEnable)
{
    switch (CmdBufIndex)
    {
        case ADC_DRV_CMD_BUFFER_0:
        {
            ADCx->ADC_CMD_BUFF0.CMD0 = (uint32)Channel;
            ADCx->ADC_CMD_BUFF0.CMD0_INT_EN = (uint32)InterruptEnable;
            break;
        }
        case ADC_DRV_CMD_BUFFER_1:
        {
            ADCx->ADC_CMD_BUFF0.CMD1 = (uint32)Channel;
            ADCx->ADC_CMD_BUFF0.CMD1_INT_EN = (uint32)InterruptEnable;
            break;
        }
        case ADC_DRV_CMD_BUFFER_2:
        {
            ADCx->ADC_CMD_BUFF0.CMD2 = (uint32)Channel;
            ADCx->ADC_CMD_BUFF0.CMD2_INT_EN = (uint32)InterruptEnable;
            break;
        }
        case ADC_DRV_CMD_BUFFER_3:
        {
            ADCx->ADC_CMD_BUFF0.CMD3 = (uint32)Channel;
            ADCx->ADC_CMD_BUFF0.CMD3_INT_EN = (uint32)InterruptEnable;
            break;
        }
        case ADC_DRV_CMD_BUFFER_4:
        {
            ADCx->ADC_CMD_BUFF1.CMD4 = (uint32)Channel;
            ADCx->ADC_CMD_BUFF1.CMD4_INT_EN = (uint32)InterruptEnable;
            break;
        }
        case ADC_DRV_CMD_BUFFER_5:
        {
            ADCx->ADC_CMD_BUFF1.CMD5 = (uint32)Channel;
            ADCx->ADC_CMD_BUFF1.CMD5_INT_EN = (uint32)InterruptEnable;
            break;
        }
        default:
        {
            /* noting to do */
            break;
        }
    }
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief     This function initializes group configuration.
 *
 * @param[in] Group:     Group Id
 * @param[in] GrpCfgPtr: Pointer to Group Configuration.
 *
 * @return    None.
 *
 */
void Adc_Drv_InitGroupConfig(const uint16 Group, const Adc_Drv_GroupConfigType *GrpCfgPtr)
{
    Adc_Drv_GroupConfigList[Group] = GrpCfgPtr;
}

/**
 * @brief     Initialize ADC module.
 * @details   This function initializes the ADC module by configuring all available features.
 *
 * @param[in] Instance: ADC instance number
 * @param[in] ConfigPtr: Pointer to configuration structure
 *
 * @return    None
 */
void Adc_Drv_Init(const uint8 Instance, const Adc_Drv_ConfigType *const ConfigPtr)
{
    Reg_Adc_BfType     *ADCx;
    Adc_Drv_IRefSelType IRefSel = ADC_DRV_IREF_INTERNAL;
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(ConfigPtr != NULL_PTR);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    /* Set software trigger mode */
    ADCx->ADC_CFG.HWT_EN = 0U;
    ADCx->ADC_CTRL.TRIG_MODE_ENABLE = 0U;

    /* Set VREF reference as configured */
    ADCx->ADC_CFG.REF_SEL = (uint32)ConfigPtr->VoltageRef;
    /* Set IREF reference as internal */
    ADCx->ADC_CTRL.IREF_SEL = (uint32)IRefSel;
    /* Set resolution for conversion */
    ADCx->ADC_CFG.RES = (uint32)ConfigPtr->Resolution;
    /* Set conversion type */
    ADCx->ADC_CFG.CTYPE = (uint32)ConfigPtr->ConvMode;
    /* Set the compare method and compare low&high value */
    ADCx->ADC_CFG.CMPS = (uint32)ConfigPtr->CompareMode;
    /* Set the compare low value */
    if (ADC_DRV_COMPARE_MODE_DISABLED < ConfigPtr->CompareMode)
    {
        ADCx->ADC_CV.CVL = (uint32)ConfigPtr->CompVal1;
    }
    /* Set the compare high value */
    if (ADC_DRV_COMPARE_MODE_EQUAL_CVL < ConfigPtr->CompareMode)
    {
        ADCx->ADC_CV.CVH = (uint32)ConfigPtr->CompVal2;
    }
    ADCx->ADC_FCTRL.FWMARK = ADC_DRV_FIFO_SIZE - 1U;

    /* Enable trigger conflict error interrupt */
    ADCx->ADC_IE.ERR_INT_IE = TRUE;

    /* Enable ADC */
    ADCx->ADC_CTRL.ADC_EN = TRUE;

    Adc_Drv_StateArray[Instance].ConversionCompleteNotification =
        ConfigPtr->ConversionCompleteNotification;
    Adc_Drv_StateArray[Instance].TriggerErrorNotification = ConfigPtr->TriggerErrorNotification;

    Adc_Drv_StateArray[Instance].InitFlag = TRUE;

    Adc_Drv_ConfigList[Instance] = ConfigPtr;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     Deinitialize ADC module.
 * @details   This function disables and resets the ADC module.
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    None
 */
void Adc_Drv_DeInit(const uint8 Instance)
{
    Reg_Adc_BfType *ADCx;
    Reg_Adc_WType  *ADCxw;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
    ADCxw = Adc_Drv_AdcRegWPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCxw);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    /* Disable all interrupts */
    ADCxw->ADC_IE = 0;
    /* Disable ADC */
    ADCx->ADC_CTRL.ADC_EN = FALSE;
    /* Reset ADC */
    ADCx->ADC_CTRL.RST = TRUE;

    Adc_Drv_StateArray[Instance].ConversionCompleteNotification = NULL_PTR;
    Adc_Drv_StateArray[Instance].InitFlag = FALSE;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function returns the value of the conversion complete status.
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    boolean: conversion complete status
 * @retval    TRUE: completed
 * @retval    FALSE: not completed
 */
boolean Adc_Drv_GetConvCompleteFlag(const uint8 Instance)
{
    const Reg_Adc_WType *ADCxw;
    boolean              Status = FALSE;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCxw = Adc_Drv_AdcRegWPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCxw);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    if (TRUE == ((ADCxw->ADC_STAT >> (uint8)ADC_DRV_STATUS_TCOMP_INT) & (uint32)0x01U))
    {
        Status = TRUE;
    }

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    return Status;
}

/**
 * @brief     This function retrieves the last conversion result for the
 *            selected control channel.
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    uint16: converted data
 */
uint16 Adc_Drv_GetConvData(const uint8 Instance)
{
    const Reg_Adc_BfType *ADCx;
    uint16                ConvResult = 0;
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    ConvResult = (uint16)(ADCx->ADC_DATA_RD.ADC_DATA_RD & 0xFFFU);

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    return ConvResult;
}

/**
 * @brief     This function clears FIFO by reading all FIFO data
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    None
 *
 */
static void Adc_Drv_ClearFifo(const uint8 Instance)
{
    uint8                 Count;
    uint8                 Index;
    const Reg_Adc_BfType *ADCx;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    Count = ADCx->ADC_FCTRL.FCOUNT;
    for (Index = 0U; Index < Count; Index++)
    {
        (void)ADCx->ADC_DATA_RD.ADC_DATA_RD;
    }

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function disables complete interrupt of ADC hardware unit
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    None
 *
 */
void Adc_Drv_DisableCompInterrupt(const uint8 Instance)
{
    Reg_Adc_WType *ADCxw;
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCxw = Adc_Drv_AdcRegWPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCxw);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    /* Disable ADC complete interrupt */
    ADCxw->ADC_IE &= ~((uint32)0x01U << (uint8)ADC_DRV_TCOMP_INT);

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function disables dma of ADC hardware unit
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    None
 *
 */
void Adc_Drv_DisableDma(const uint8 Instance)
{
    Reg_Adc_BfType *ADCx;
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    /* Disable ADC DMA Request */
    ADCx->ADC_IE.FWMDE = FALSE;
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function returns the address of ADC data
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    uint32: ADC data address
 *
 */
uint32 Adc_Drv_GetDataAddress(const uint8 Instance)
{
    const Reg_Adc_WType *ADCxw;
    uint32               DataAddr = 0;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCxw = Adc_Drv_AdcRegWPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCxw);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    DataAddr = (uint32)(&ADCxw->ADC_DATA_RD);

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    return DataAddr;
}

/**
 * @brief     This function configures adc registers to start conversion.
 *
 * @param[in] Instance: ADC Hardware Unit id
 * @param[in] Group: Group Id
 * @param[in] ChannelNum: channel number of group to be started
 * @param[in] ChannelList: pointer to the channel list
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Adc_Drv_StartConversion(const uint8 Instance, const uint16 Group, uint8 ChannelNum,
                                       const ADC_Drv_PositiveChannelType *ChannelList)
{
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;
    uint8           ChannelIndex;
    boolean         InterruptEnable;
    Reg_Adc_BfType *ADCx;
    Reg_Adc_WType  *ADCxw;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
    ADCxw = Adc_Drv_AdcRegWPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCxw);
    MCALLIB_DEV_ASSERT(0U < ChannelNum);
    MCALLIB_DEV_ASSERT(ADC_DRV_MAX_CHANNELS_PER_GROUP >= ChannelNum);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    SchM_Enter_Adc_StartAdcConversion();

    /* Clear FIFO by reading all FIFO data */
    Adc_Drv_ClearFifo(Instance);

    /* Set stable time */
    ADCx->ADC_CTRL.STABLE_T = (uint32)((Adc_Drv_GroupConfigList[Group])->StableTime);

    /* Set sample time */
    ADCx->ADC_CFG.STS = (uint32)((Adc_Drv_GroupConfigList[Group])->SampleTime);

    /* Set average select */
    ADCx->ADC_CFG.AVGS = (uint32)((Adc_Drv_GroupConfigList[Group])->AverageSelect);

    /* Set Fifo depth */
    ADCx->ADC_FCTRL.FDRD = (uint32)ChannelNum;

    /* Set Fifo watermark */
    ADCx->ADC_FCTRL.FWMARK = (uint32)ChannelNum - 1U;

    /* Set trigger source as TDG trigger */
    ADCx->ADC_CTRL.TRIG_MODE_ENABLE = 1U;

    /* Set Loop trigger mode and loop depth */
    ADCx->ADC_CTRL.TRIG_MODE = (uint32)((Adc_Drv_GroupConfigList[Group])->TdgTriggerMode);
    ADCx->ADC_CTRL.LMD = (uint32)ChannelNum;

    /* Configure channels from current to (last channel - 1) */
    for (ChannelIndex = 0U; ChannelIndex < (ChannelNum - 1U); ChannelIndex++)
    {
        /* Configure all channels except the last one with interrupts disabled */
        Adc_Drv_SetTdgTriggerCmdBuf(ADCx, (ADC_Drv_CmdBufferType)ChannelIndex,
                                    ChannelList[ChannelIndex], FALSE);
    }

#if (ADC_DRV_DMA_USED == STD_ON)
    if (ADC_DRV_DMA == (Adc_Drv_ConfigList[Instance])->TransferMode)
    {
        InterruptEnable = FALSE;
        ADCxw->ADC_IE &= ~((uint32)0x01U << (uint8)ADC_DRV_TCOMP_INT);
    }
    else
#endif /* (ADC_DRV_DMA_USED == STD_ON) */
    {
        /* In case of group is configured with interrupt, the complete int bit of the last channel
         * must be enabled */
        if (TRUE == (Adc_Drv_ConfigList[Instance])->WithoutInterrupt)
        {
            InterruptEnable = FALSE;
            ADCxw->ADC_IE &= ~((uint32)0x01U << (uint8)ADC_DRV_TCOMP_INT);
        }
        else
        {
            InterruptEnable = TRUE;
            ADCxw->ADC_IE |= (uint32)0x01U << (uint8)ADC_DRV_TCOMP_INT;
        }
    }

    /* Configure last channel */
    Adc_Drv_SetTdgTriggerCmdBuf(ADCx, (ADC_Drv_CmdBufferType)ChannelIndex,
                                ChannelList[ChannelIndex], InterruptEnable);

#if (ADC_DRV_DMA_USED == STD_ON)
    if (ADC_DRV_DMA == (Adc_Drv_ConfigList[Instance])->TransferMode)
    {
        /* Enable DMA for ADC module */
        ADCx->ADC_IE.FWMDE = TRUE;
    }
#endif /* (ADC_DRV_DMA_USED == STD_ON) */

    SchM_Exit_Adc_StartAdcConversion();

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    return Ret;
}

/**
 * @brief     This function stops the current conversion.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType Adc_Drv_StopConversion(const uint8 Instance)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
#if (ADC_DRV_DMA_USED == STD_ON)
    Reg_Adc_BfType *ADCx;
#endif /* (ADC_DRV_DMA_USED == STD_ON) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (ADC_DRV_DMA_USED == STD_ON)
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
#endif /* (ADC_DRV_DMA_USED == STD_ON) */

#if ((STD_ON == ADC_DRV_DEV_ERROR_DETECT) && (ADC_DRV_DMA_USED == STD_ON))
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
#endif /* ((STD_ON == ADC_DRV_DEV_ERROR_DETECT) && (ADC_DRV_DMA_USED == STD_ON)) */

    SchM_Enter_Adc_StopAdcConversion();

#if (ADC_DRV_DMA_USED == STD_ON)
    if (ADC_DRV_DMA == (Adc_Drv_ConfigList[Instance])->TransferMode)
    {
        /* Disable DMA for Adc */
        ADCx->ADC_IE.FWMDE = FALSE;
    }
#endif /* (ADC_DRV_DMA_USED == STD_ON) */

    /* Clear FIFO by reading all FIFO data */
    Adc_Drv_ClearFifo(Instance);

    SchM_Exit_Adc_StopAdcConversion();

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    return Ret;
}

/**
 * @brief     This function performs a calibration of the ADC.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    Std_ReturnType: the calibration result
 * @retval    E_OK: calibration successful
 * @retval    E_NOT_OK: calibration failed
 */
Std_ReturnType Adc_Drv_Calibrate(const uint8 Instance)
{
    Reg_Adc_BfType      *ADCx;
    const Reg_Adc_WType *ADCxw;
    Std_ReturnType       Ret = E_NOT_OK;
    uint32 TimeoutTicks = McalLib_MicroSecToTicks(ADC_DRV_TIMEOUT_METHOD, ADC_DRV_TIMEOUT_VAL);
    uint32 CurrentTicks = 0u;      /* initialize current counter */
    uint32 ElapsedTicks = 0u;      /* elapsed elapsed time */
    uint32 TotalElapsedTicks = 0u; /* total elapsed time*/
    uint32 Status;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
    ADCxw = Adc_Drv_AdcRegWPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCxw);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    ADCx->ADC_CFG.CHSELP = (uint32)ADC_DRV_CALIBRATION_CHANNEL;
    ADCx->ADC_CTRL.CAL_REQ = TRUE;

    (void)McalLib_GetCounterValue(ADC_DRV_TIMEOUT_METHOD, &CurrentTicks);
    while (TotalElapsedTicks < TimeoutTicks)
    {
        Status = (ADCxw->ADC_STAT >> (uint8)ADC_DRV_STATUS_CAL_RDY) & 0x01U;
        if (TRUE == Status)
        {
            Ret = E_OK;
            break;
        }
        (void)McalLib_GetElapsedValue(ADC_DRV_TIMEOUT_METHOD, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
    }
    ADCx->ADC_CFG.CHSELP = (uint32)ADC_DRV_P_CH0;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    return Ret;
}

/**
 * @brief     This function performs a self test of the ADC.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    Std_ReturnType: the self test result
 * @retval    E_OK: self test successful
 * @retval    E_NOT_OK: self test failed
 */
Std_ReturnType Adc_Drv_SelfTest(const uint8 Instance)
{
    Reg_Adc_BfType *ADCx;
    Std_ReturnType  Ret = E_NOT_OK;
    uint32 TimeoutTicks = McalLib_MicroSecToTicks(ADC_DRV_TIMEOUT_METHOD, ADC_DRV_TIMEOUT_VAL);
    uint32 CurrentTicks = 0u;      /* initialize current counter */
    uint32 ElapsedTicks = 0u;      /* elapsed elapsed time */
    uint32 TotalElapsedTicks = 0u; /* total elapsed time*/

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCx = Adc_Drv_AdcRegBfPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCx);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    /* Clear FIFO by reading all FIFO data */
    Adc_Drv_ClearFifo(Instance);

    /* Set stable time as reset value */
    ADCx->ADC_CTRL.STABLE_T = ADC_DRV_STABLE_TIME_RESET_VALUE;

    /* Select hardware average as single */
    ADCx->ADC_CFG.AVGS = (uint32)ADC_DRV_AVG_DISABLE;

    /* Disable TDG trigger */
    ADCx->ADC_CTRL.TRIG_MODE_ENABLE = 0U;

    /* Select bandgap as input channel */
    ADCx->ADC_CFG.CHSELP = (uint32)ADC_DRV_P_CH20;

    /* Start software trigger */
    ADCx->ADC_SWTRIG.ADC_SWTRIG = TRUE;

    (void)McalLib_GetCounterValue(ADC_DRV_TIMEOUT_METHOD, &CurrentTicks);
    while (TotalElapsedTicks < TimeoutTicks)
    {
        if (0U < ADCx->ADC_FCTRL.FCOUNT)
        {
            /* Clear FIFO by reading all FIFO data */
            Adc_Drv_ClearFifo(Instance);
            Ret = E_OK;
            break;
        }
        (void)McalLib_GetElapsedValue(ADC_DRV_TIMEOUT_METHOD, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
    }
    ADCx->ADC_CFG.CHSELP = (uint32)ADC_DRV_P_CH0;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    return Ret;
}

/**
 * @brief     This function handles the ADC interrupt.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    None
 */
void Adc_Drv_IntHandler(const uint8 Instance)
{
    Reg_Adc_WType *ADCxw;
    uint32         Status;
    uint32         IntEnable;

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
    ADCxw = Adc_Drv_AdcRegWPtr[Instance];
#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ADCxw);
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */

    Status = ADCxw->ADC_STAT;
    IntEnable = ADCxw->ADC_IE;
    /* Clear interrupt flags */
    ADCxw->ADC_STAT = Status;
    /* handle complete interrupt */
    if (TRUE == ((Status >> (uint32)ADC_DRV_STATUS_TCOMP_INT) & 0x01U))
    {
        if (TRUE == ((IntEnable >> (uint32)ADC_DRV_TCOMP_INT) & 0x01U))
        {
            if ((Adc_Drv_StateArray[Instance].InitFlag == TRUE) &&
                (NULL_PTR != Adc_Drv_StateArray[Instance].ConversionCompleteNotification))
            {
                Adc_Drv_StateArray[Instance].ConversionCompleteNotification(Instance);
            }
        }
    }

    /* handle trigger error interrupt */
    if (TRUE == ((Status >> (uint32)ADC_DRV_STATUS_TC_ERR_INT) & 0x01U))
    {
        if (TRUE == ((IntEnable >> (uint32)ADC_DRV_TC_ERR_INT) & 0x01U))
        {
            if ((Adc_Drv_StateArray[Instance].InitFlag == TRUE) &&
                (NULL_PTR != Adc_Drv_StateArray[Instance].TriggerErrorNotification))
            {
                Adc_Drv_StateArray[Instance].TriggerErrorNotification();
            }
        }
    }

#if (STD_ON == ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == ADC_DRV_DEV_ERROR_DETECT) */
}

#if (ADC_DRV_DMA_USED == STD_ON)
    #if (ADC_DRV_0_ENABLE == STD_ON)
/**
 * @brief     This function handles the DMA interrupt for ADC Driver 0.
 *
 * @return    None
 */
void Adc_Drv_0_DmaIrqHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Adc_ProcessDmaConversionEndInterrupt(0U);
}
    #endif /* (ADC_DRV_0_ENABLE == STD_ON) */

    #if (ADC_DRV_1_ENABLE == STD_ON)
/**
 * @brief     This function handles the DMA interrupt for ADC Driver 1.
 *
 * @return    None
 */
void Adc_Drv_1_DmaIrqHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Adc_ProcessDmaConversionEndInterrupt(1U);
}
    #endif /* (ADC_DRV_1_ENABLE == STD_ON) */
#endif     /* (ADC_DRV_DMA_USED == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv */

/** @} end of group Adc_Module */
