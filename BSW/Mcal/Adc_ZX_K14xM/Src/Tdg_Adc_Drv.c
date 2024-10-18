/**************************************************************************************************/
/**
 * @file      : Tdg_Adc_Drv.c
 * @brief     : Tdg Adc low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Tdg_Adc_Drv
 *  @brief Tdg Adc low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Tdg_Adc_Drv.h"
#include "SchM_Adc.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TDG_ADC_DRV_C_VENDOR_ID                   0x00B3U
#define TDG_ADC_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define TDG_ADC_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define TDG_ADC_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define TDG_ADC_DRV_C_SW_MAJOR_VERSION            1U
#define TDG_ADC_DRV_C_SW_MINOR_VERSION            2U
#define TDG_ADC_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Tdg_Adc_Drv.h are the same vendor */
#if (TDG_ADC_DRV_C_VENDOR_ID != TDG_ADC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Tdg_Adc_Drv.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Autosar version */
#if ((TDG_ADC_DRV_C_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (TDG_ADC_DRV_C_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (TDG_ADC_DRV_C_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tdg_Adc_Drv.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Software version */
#if ((TDG_ADC_DRV_C_SW_MAJOR_VERSION != TDG_ADC_DRV_H_SW_MAJOR_VERSION) ||                         \
     (TDG_ADC_DRV_C_SW_MINOR_VERSION != TDG_ADC_DRV_H_SW_MINOR_VERSION) ||                         \
     (TDG_ADC_DRV_C_SW_PATCH_VERSION != TDG_ADC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Tdg_Adc_Drv.c and Tdg_Adc_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((TDG_ADC_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||     \
         (TDG_ADC_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tdg_Adc_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Adc.h are the same Autosar version */
    #if ((TDG_ADC_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_ADC_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (TDG_ADC_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_ADC_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tdg_Adc_Drv.c and SchM_Adc.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

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
 *  @brief TDG peripheral (TDG0 TDG1) base address array
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Tdg_BfType *const Tdg_Adc_Drv_TdgRegBfPtr[TDG_ADC_DRV_INSTANCE_NUM] = {
    (Reg_Tdg_BfType *)TDG0_BASE_ADDR, /*!< TDG0 base address */
    (Reg_Tdg_BfType *)TDG1_BASE_ADDR  /*!< TDG1 base address */
};

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Tdg_WType *const Tdg_Adc_Drv_TdgRegWPtr[TDG_ADC_DRV_INSTANCE_NUM] = {
    (Reg_Tdg_WType *)TDG0_BASE_ADDR, /*!< TDG0 base address */
    (Reg_Tdg_WType *)TDG1_BASE_ADDR  /*!< TDG1 base address */
};

#define ADC_STOP_SEC_CONST_PTR
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"
/**
 * @brief List of pointer to TDG Driver Group configuration.
 */
static const Tdg_Adc_Drv_GroupConfigType *Tdg_Adc_Drv_GroupConfigList[TDG_ADC_DRV_MAX_GROUPS];

#define ADC_STOP_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/**
 * @brief TDG Driver global state array.
 */
static Tdg_Adc_Drv_StateStructType Tdg_Adc_Drv_StateArray[TDG_ADC_DRV_INSTANCE_NUM];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

LOCAL_INLINE void Tdg_Adc_Drv_EnableChannel(Reg_Tdg_BfType                 *TDGx,
                                            const Tdg_Adc_Drv_ChannelIdType ChannelId);
LOCAL_INLINE void Tdg_Adc_Drv_DisableChannel(Reg_Tdg_BfType                 *TDGx,
                                             const Tdg_Adc_Drv_ChannelIdType ChannelId);
LOCAL_INLINE void
                  Tdg_Adc_Drv_ConfigChannelDelayOutput(Reg_Tdg_BfType *TDGx, Reg_Tdg_WType *TDGxw,
                                                       const Tdg_Adc_Drv_ChannelConfigType *ChannelConfig);
LOCAL_INLINE void Tdg_Adc_Drv_LoadRegValues(Reg_Tdg_BfType *TDGx);
LOCAL_INLINE void Tdg_Adc_Drv_DisableAndClearChannel(Reg_Tdg_BfType *TDGx, Reg_Tdg_WType *TDGxw,
                                                     const Tdg_Adc_Drv_ChannelIdType ChannelId);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief     This function enables TDG channel.
 *
 * @param[in] TDGx: TDG Register base address
 * @param[in] ChannelId: TDG channel id
 *
 * @return    None
 */
LOCAL_INLINE void Tdg_Adc_Drv_EnableChannel(Reg_Tdg_BfType                 *TDGx,
                                            const Tdg_Adc_Drv_ChannelIdType ChannelId)
{
    switch (ChannelId)
    {
        case TDG_ADC_DRV_CHANNEL_0:
        {
            TDGx->TDG_CTRL2.CH0E = TRUE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_1:
        {
            TDGx->TDG_CTRL2.CH1E = TRUE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_2:
        {
            TDGx->TDG_CTRL2.CH2E = TRUE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_3:
        {
            TDGx->TDG_CTRL2.CH3E = TRUE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_4:
        {
            TDGx->TDG_CTRL2.CH4E = TRUE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_5:
        {
            TDGx->TDG_CTRL2.CH5E = TRUE;
            break;
        }
        default:
        {
            /* do nothing */
            break;
        }
    }
}

/**
 * @brief     This function disables TDG channel.
 *
 * @param[in] TDGx: TDG Register base address
 * @param[in] ChannelId: TDG channel id
 *
 * @return    None
 */
LOCAL_INLINE void Tdg_Adc_Drv_DisableChannel(Reg_Tdg_BfType                 *TDGx,
                                             const Tdg_Adc_Drv_ChannelIdType ChannelId)
{
    switch (ChannelId)
    {
        case TDG_ADC_DRV_CHANNEL_0:
        {
            TDGx->TDG_CTRL2.CH0E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_1:
        {
            TDGx->TDG_CTRL2.CH1E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_2:
        {
            TDGx->TDG_CTRL2.CH2E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_3:
        {
            TDGx->TDG_CTRL2.CH3E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_4:
        {
            TDGx->TDG_CTRL2.CH4E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_5:
        {
            TDGx->TDG_CTRL2.CH5E = FALSE;
            break;
        }
        default:
        {
            /* do nothing */
            break;
        }
    }
}

/**
 * @brief     This function Configures delay output points of TDG channel.
 *
 * @param[in] TDGx: TDG Register base address for bit field access
 * @param[in] TDGxw: TDG Register base address for word access
 * @param[in] ChannelConfig: configuration of TDG channel delay output
 *
 * @return    None
 */
LOCAL_INLINE void
Tdg_Adc_Drv_ConfigChannelDelayOutput(Reg_Tdg_BfType *TDGx, Reg_Tdg_WType *TDGxw,
                                     const Tdg_Adc_Drv_ChannelConfigType *ChannelConfig)
{
    uint8   Index;
    uint16  Offset;
    boolean Enable;
    uint32  ChannelCtrl;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((uint32)ChannelConfig->ChannelId < TDG_ADC_DRV_CHANNEL_NUM);
    MCALLIB_DEV_ASSERT((uint32)ChannelConfig->DelayOutputNum <
                       TDG_ADC_DRV_CHANNEL_DELAY_OUTPUT_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    TDGx->TDG_CHCFG[ChannelConfig->ChannelId].TDG_CHCDOINTDLY.CDOINTDLY =
        ChannelConfig->IntDelayVal & 0x3FFUL;

    for (Index = 0U; Index < ChannelConfig->DelayOutputNum; Index++)
    {
        Offset = ChannelConfig->DelayOutputConfig[Index].Offset;
        Enable = ChannelConfig->DelayOutputConfig[Index].Enable;

        ChannelCtrl = TDGxw->TDG_CHCFG[ChannelConfig->ChannelId].TDG_CHCTRL;
        TDGxw->TDG_CHCFG[ChannelConfig->ChannelId].TDG_CHCTRL =
            ChannelCtrl | (((uint32)Enable) << (8U + (uint8)Index));
        TDGxw->TDG_CHCFG[ChannelConfig->ChannelId].TDG_CHDOOFS[Index] = (uint32)Offset;
    }

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function Load buffered register values.
 *
 * @param[in] TDGx: TDG Register base address
 * @return    None
 */
LOCAL_INLINE void Tdg_Adc_Drv_LoadRegValues(Reg_Tdg_BfType *TDGx)
{
    uint32 TimeoutTicks =
        McalLib_MicroSecToTicks(TDG_ADC_DRV_TIMEOUT_METHOD, TDG_ADC_DRV_TIMEOUT_VAL);
    uint32 CurrentTicks = 0u;      /* initialize current counter */
    uint32 ElapsedTicks = 0u;      /* elapsed elapsed time */
    uint32 TotalElapsedTicks = 0u; /* total elapsed time*/

    /* Set this bit to load channel configuration from register to shadow buffer */
    TDGx->TDG_CTRL1.CFGUP = 1U;

    (void)McalLib_GetCounterValue(TDG_ADC_DRV_TIMEOUT_METHOD, &CurrentTicks);

    /* Read this value to check if the load is complete */
    while (TRUE == TDGx->TDG_CTRL1.CFGUP)
    {
        (void)McalLib_GetElapsedValue(TDG_ADC_DRV_TIMEOUT_METHOD, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
        if (TotalElapsedTicks >= TimeoutTicks)
        {
            break;
        }
    }
}

/**
 * @brief     This function Disable and clear TDG channel.
 *
 * @param[in] TDGx: TDG Register base address for bit field access
 * @param[in] TDGxw: TDG Register base address for word access
 * @param[in] ChannelId: TDG channel id
 *
 * @return    None
 */
LOCAL_INLINE void Tdg_Adc_Drv_DisableAndClearChannel(Reg_Tdg_BfType *TDGx, Reg_Tdg_WType *TDGxw,
                                                     const Tdg_Adc_Drv_ChannelIdType ChannelId)
{
    uint8  Index;
    uint32 ChannelCtrl;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((uint32)ChannelId < TDG_ADC_DRV_CHANNEL_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    switch (ChannelId)
    {
        case TDG_ADC_DRV_CHANNEL_0:
        {
            TDGx->TDG_CTRL2.CH0E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_1:
        {
            TDGx->TDG_CTRL2.CH1E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_2:
        {
            TDGx->TDG_CTRL2.CH2E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_3:
        {
            TDGx->TDG_CTRL2.CH3E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_4:
        {
            TDGx->TDG_CTRL2.CH4E = FALSE;
            break;
        }
        case TDG_ADC_DRV_CHANNEL_5:
        {
            TDGx->TDG_CTRL2.CH5E = FALSE;
            break;
        }
        default:
        {
            /* nothing to do */
            break;
        }
    }
    TDGx->TDG_CHCFG[ChannelId].TDG_CHCDOINTDLY.CDOINTDLY = 0U;

    /* Disable all delay outputs */
    ChannelCtrl = TDGxw->TDG_CHCFG[ChannelId].TDG_CHCTRL;
    TDGxw->TDG_CHCFG[ChannelId].TDG_CHCTRL = ChannelCtrl & (~0xFF00U);

    for (Index = 0U; Index < TDG_ADC_DRV_CHANNEL_DELAY_OUTPUT_NUM; Index++)
    {
        TDGxw->TDG_CHCFG[ChannelId].TDG_CHDOOFS[Index] = 0U;
    }

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
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
void Tdg_Adc_Drv_InitGroupConfig(const uint16 Group, const Tdg_Adc_Drv_GroupConfigType *GrpCfgPtr)
{
    Tdg_Adc_Drv_GroupConfigList[Group] = GrpCfgPtr;
}

/**
 * @brief     This function initializes the TDG module.
 *
 * @param[in] Instance: TDG instance number
 * @param[in] Config: TDG Configuration
 *
 * @return    None
 */
void Tdg_Adc_Drv_Init(const uint32 Instance, const Tdg_Adc_Drv_ConfigType *const Config)
{
    Reg_Tdg_BfType *TDGx;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < TDG_ADC_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(Config != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
    TDGx = Tdg_Adc_Drv_TdgRegBfPtr[Instance];
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TDGx != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    /* Set prescaler */
    TDGx->TDG_CTRL1.PRES = (uint32)Config->PrescalerDiv;
    /* Set Channel configuration update mode */
    TDGx->TDG_CTRL1.UPMD = (uint32)Config->UpdateMode;
    /* Set counter clear mode */
    TDGx->TDG_CTRL1.CLRMD = (uint32)Config->ClearMode;
    /* Set modulate value */
    TDGx->TDG_MOD.MOD = (uint32)Config->ModValue;

    Tdg_Adc_Drv_StateArray[Instance].ErrorNotifPtr = Config->ErrorNotifPtr;
    Tdg_Adc_Drv_StateArray[Instance].InitFlag = TRUE;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function de-initializes the TDG module.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_DeInit(const uint32 Instance)
{
    Reg_Tdg_BfType *TDGx;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < TDG_ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
    TDGx = Tdg_Adc_Drv_TdgRegBfPtr[Instance];
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TDGx != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    TDGx->TDG_CTRL1.TDGEN = FALSE;

    Tdg_Adc_Drv_StateArray[Instance].ErrorNotifPtr = NULL_PTR;
    Tdg_Adc_Drv_StateArray[Instance].InitFlag = FALSE;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function starts the conversion on the specified hardware Unit.
 *
 * @param[in] Instance: Hardware Unit
 * @param[in] Group: Group Id
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType Tdg_Adc_Drv_StartConversion(const uint8 Instance, const uint16 Group)
{
    Std_ReturnType                Ret = (Std_ReturnType)E_OK;
    Reg_Tdg_BfType               *TDGx;
    Reg_Tdg_WType                *TDGxw;
    Tdg_Adc_Drv_TriggerSourceType TrigSource;
    uint8                         Index;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < TDG_ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
    TDGx = Tdg_Adc_Drv_TdgRegBfPtr[Instance];
    TDGxw = Tdg_Adc_Drv_TdgRegWPtr[Instance];
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TDGx != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    if (TRUE == Tdg_Adc_Drv_GroupConfigList[Group]->IsSwTrig)
    {
        TrigSource = TDG_ADC_DRV_TRIG_SW;
    }
    else
    {
        TrigSource = TDG_ADC_DRV_TRIG_EXTERNAL;
    }

    SchM_Enter_Adc_StartTdgConversion();

    for (Index = 0; Index < Tdg_Adc_Drv_GroupConfigList[Group]->NumOfChannel; Index++)
    {
        /* Configures delay output of TDG channels*/
        Tdg_Adc_Drv_ConfigChannelDelayOutput(
            TDGx, TDGxw, &((*Tdg_Adc_Drv_GroupConfigList[Group]->TdgChannelConfigArray)[Index]));

        /* Enable TDG channels */
        Tdg_Adc_Drv_EnableChannel(TDGx, (Tdg_Adc_Drv_ChannelIdType)Index);
    }

    /* Select the input trigger source for TDG */
    TDGx->TDG_CTRL1.TRIGS = (uint32)TrigSource;

    /* TDG operation in single mode for software */
    TDGx->TDG_CTRL1.CNTMD = (uint32)TDG_ADC_DRV_COUNT_SINGLE;

    /* TDG operation in single mode for software */
    TDGx->TDG_CTRL1.TDGEN = TRUE;

    /* Load the configuration */
    Tdg_Adc_Drv_LoadRegValues(TDGx);

    /* Start software trigger */
    /* If trigger is not software trigger, hardware trigger or external trigger will be used */
    if (TDG_ADC_DRV_TRIG_SW == TrigSource)
    {
        /* TDG operation in Continuous mode for software */
        TDGx->TDG_CTRL1.SWTRG = 1U;
    }

    SchM_Exit_Adc_StartTdgConversion();

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    return Ret;
}

/**
 * @brief     This function stops the current conversion of a group.
 *
 * @param[in] Instance: Hardware Unit
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType Tdg_Adc_Drv_StopConversion(const uint8 Instance)
{
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;
    Reg_Tdg_BfType *TDGx;
    Reg_Tdg_WType  *TDGxw;
    uint8           Index;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < TDG_ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
    TDGx = Tdg_Adc_Drv_TdgRegBfPtr[Instance];
    TDGxw = Tdg_Adc_Drv_TdgRegWPtr[Instance];
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TDGx != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    SchM_Enter_Adc_StopTdgConversion();

    for (Index = 0; Index < TDG_ADC_DRV_CHANNEL_NUM; Index++)
    {
        /* Disable TDG channels */
        Tdg_Adc_Drv_DisableChannel(TDGx, (Tdg_Adc_Drv_ChannelIdType)Index);
    }

    /* Disable TDG hardware unit */
    TDGx->TDG_CTRL1.TDGEN = FALSE;

    /* Disable TDG channel 0 */
    Tdg_Adc_Drv_DisableAndClearChannel(TDGx, TDGxw, TDG_ADC_DRV_CHANNEL_0);

    SchM_Exit_Adc_StopTdgConversion();

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    return Ret;
}

/**
 * @brief     Trigger the TDG with a software trigger.
 * @details   This function triggers the TDG with a software trigger.
 *            When the TDG is set to use the software trigger as input, calling this function
 *            triggers the TDG.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_SwTrigger(const uint32 Instance)
{
    Reg_Tdg_BfType *TDGx;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < TDG_ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
    TDGx = Tdg_Adc_Drv_TdgRegBfPtr[Instance];
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TDGx != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    /* Write 1 to trigger a software trigger */
    TDGx->TDG_CTRL1.SWTRG = 1U;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function handles TDG complete delay output interrupt.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_TcoIntHandler(const uint32 Instance)
{
    Reg_Tdg_WType *TDGxw;
    uint32         Status;
    uint32         Ctrl2Reg;
    uint32         ChanInx;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < TDG_ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
    TDGxw = Tdg_Adc_Drv_TdgRegWPtr[Instance];
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TDGxw != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    Ctrl2Reg = TDGxw->TDG_CTRL2;
    Status = TDGxw->TDG_STAT;
    Status &= Ctrl2Reg;
    for (ChanInx = 0; ChanInx < TDG_ADC_DRV_CHANNEL_NUM; ChanInx++)
    {
        if (TRUE == ((Status >> ChanInx) & 0x01U))
        {
            TDGxw->TDG_STAT = (uint32)0x01U << ChanInx;
            if (NULL_PTR != Tdg_Adc_Drv_StateArray[Instance].CompDelayNotifPtr)
            {
                Tdg_Adc_Drv_StateArray[Instance].CompDelayNotifPtr(ChanInx);
            }
        }
    }
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
}

/**
 * @brief     This function handles TDG sequence error interrupt.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_ErrIntHandler(const uint32 Instance)
{
    Reg_Tdg_WType *TDGxw;
    uint32         Status;
    uint32         Ctrl2Reg;

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < TDG_ADC_DRV_INSTANCE_NUM);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
    TDGxw = Tdg_Adc_Drv_TdgRegWPtr[Instance];
#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TDGxw != NULL_PTR);
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */

    Status = TDGxw->TDG_STAT;
    Ctrl2Reg = TDGxw->TDG_CTRL2;
    Status &= Ctrl2Reg;
    if (TRUE == ((Status >> (uint32)TDG_ADC_DRV_INT_ERR) & 0x01U))
    {
        TDGxw->TDG_STAT = (uint32)0x01U << (uint32)TDG_ADC_DRV_INT_ERR;
        if (NULL_PTR != Tdg_Adc_Drv_StateArray[Instance].ErrorNotifPtr)
        {
            Tdg_Adc_Drv_StateArray[Instance].ErrorNotifPtr();
        }
    }

#if (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == TDG_ADC_DRV_DEV_ERROR_DETECT) */
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Tdg_Adc_Drv */

/** @} end of group Adc_Module */
