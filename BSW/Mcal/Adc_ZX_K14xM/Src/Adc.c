/**************************************************************************************************/
/**
 * @file      : Adc.c
 * @brief     : Adc AUTOSAR level source file
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

/** @addtogroup Adc
 *  @brief Adc AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Adc.h"
#include "Adc_Drv.h"
#include "Tdg_Adc_Drv.h"
#if (ADC_DMA_USED == STD_ON)
    #include "Dma_Drv.h"
#endif
#include "SchM_Adc.h"
#include "Det.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define ADC_C_VENDOR_ID                   0x00B3U
#define ADC_C_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_C_AR_RELEASE_MINOR_VERSION    6U
#define ADC_C_AR_RELEASE_REVISION_VERSION 0U
#define ADC_C_SW_MAJOR_VERSION            1U
#define ADC_C_SW_MINOR_VERSION            2U
#define ADC_C_SW_PATCH_VERSION            2U

/* Check if current file and Adc.h are the same vendor */
#if (ADC_C_VENDOR_ID != ADC_VENDOR_ID)
    #error "Vendor ID of Adc.c and Adc.h are different"
#endif

/* Check if current file and Adc.h are the same Autosar version */
#if ((ADC_C_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) ||                           \
     (ADC_C_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION) ||                           \
     (ADC_C_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc.c and Adc.h are different"
#endif

/* Check if current file and Adc.h are the same Software version */
#if ((ADC_C_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION) ||                                           \
     (ADC_C_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION) ||                                           \
     (ADC_C_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
    #error "Software Version of Adc.c and Adc.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same vendor */
#if (ADC_C_VENDOR_ID != ADC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Adc.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same Autosar version */
#if ((ADC_C_AR_RELEASE_MAJOR_VERSION != ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (ADC_C_AR_RELEASE_MINOR_VERSION != ADC_DRV_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (ADC_C_AR_RELEASE_REVISION_VERSION != ADC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same Software version */
#if ((ADC_C_SW_MAJOR_VERSION != ADC_DRV_H_SW_MAJOR_VERSION) ||                                     \
     (ADC_C_SW_MINOR_VERSION != ADC_DRV_H_SW_MINOR_VERSION) ||                                     \
     (ADC_C_SW_PATCH_VERSION != ADC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Adc.c and Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same vendor */
#if (ADC_C_VENDOR_ID != TDG_ADC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Adc.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Autosar version */
#if ((ADC_C_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (ADC_C_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (ADC_C_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Software version */
#if ((ADC_C_SW_MAJOR_VERSION != TDG_ADC_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (ADC_C_SW_MINOR_VERSION != TDG_ADC_DRV_H_SW_MINOR_VERSION) ||                                 \
     (ADC_C_SW_PATCH_VERSION != TDG_ADC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Adc.c and Tdg_Adc_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (ADC_DMA_USED == STD_ON)
        /* Check if current file file and Dma_Drv.h are the same Autosar version */
        #if ((ADC_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
             (ADC_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Adc.c and Dma_Drv.h are different"
        #endif
    #endif /* (ADC_DMA_USED == STD_ON) */
    /* Check if current file and SchM_Adc.h are the same Autosar version */
    #if ((ADC_C_AR_RELEASE_MAJOR_VERSION != SCHM_ADC_H_AR_RELEASE_MAJOR_VERSION) ||                \
         (ADC_C_AR_RELEASE_MINOR_VERSION != SCHM_ADC_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Adc.c and SchM_Adc.h are different"
    #endif

    /* Check if current file and Det.h are the same Autosar version */
    #if ((ADC_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                       \
         (ADC_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Adc.c and Det.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/**
 * @brief Defines invalid channel index.
 *
 */
#define ADC_INVALID_CHANNEL_INDEX ((Adc_ChannelType)0xFFFFU)

#if ((ADC_DMA_USED == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
    /**
     * @brief Defines ADC conversion result mask.
     *
     */
    #define ADC_CONV_RESULT_MASK (0xFFFU)
#endif /* (ADC_DMA_USED == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define ADC_START_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"

/**
 * @brief   Pointer to ADC Global Configuration .
 *
 */
static const Adc_ConfigType *Adc_ConfigPtr[ADC_MAX_PARTITIONS];

#define ADC_STOP_SEC_VAR_CLEARED_PTR
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/**
 * @brief   Group status array
 */
Adc_GroupStatusType Adc_GroupStatus[ADC_MAX_GROUPS];

/**
 * @brief   Unit status array
 */
Adc_UnitStatusType Adc_UnitStatus[ADC_MAX_HWUNITS];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief   Global Driver Status.
 * @details Data structure containing the ADC driver status
 *          uninit, during init or already init.
 *
 */
static Adc_GlobalStateType Adc_GlobalState[ADC_MAX_PARTITIONS];
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#if (ADC_DMA_USED == STD_ON)
    #define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Adc_MemMap.h"

/**
 * @brief Dma channel transfer configuration
 */
static Dma_Drv_ChannelTransferConfigType Adc_DmaChannelTransferConfig;
/**
 * @brief Dma channel source configuration
 */
static Dma_Drv_AddrConfigType Adc_DmaChannelSourceConfig;
/**
 * @brief Dma channel destination configuration
 */
static Dma_Drv_AddrConfigType Adc_DmaChannelDestinationConfig;
/**
 * @brief Dma channel control configuration
 */
static Dma_Drv_TransferControlConfigType Adc_DmaChannelControlConfig;

    #define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Adc_MemMap.h"
#endif /* (ADC_DMA_USED == STD_ON) */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
LOCAL_INLINE uint8 Adc_GetBitShiftNums(Adc_Drv_ResolutionType Resolution);
#if (ADC_DMA_USED == STD_ON)
    #if (ADC_READ_GROUP_API == STD_ON)
LOCAL_INLINE uint16 Adc_GetDataMask(Adc_Drv_ResolutionType Resolution);
    #endif /* (ADC_READ_GROUP_API == STD_ON) */
LOCAL_INLINE void Adc_ConfigureDma(uint32 CoreId, uint8 Unit, const uint16 Group, uint8 ChannelNum,
                                   uint8 DmaChannel);
#endif /* (ADC_DMA_USED == STD_ON) */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckCalledGroup(uint32 CoreId, const Adc_GroupType Group,
                                                 uint8 ServiceId);
LOCAL_INLINE Std_ReturnType Adc_CheckInit(uint32 CoreId, const Adc_ConfigType *CfgPtr);
LOCAL_INLINE Std_ReturnType Adc_CheckSetupResultBuffer(
    uint32 CoreId, const Adc_GroupType Group, const Adc_ValueGroupType *const DataBufferPtr);

    #if (ADC_DEINIT_API == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckDeInit(uint32 CoreId);
    #endif /* (ADC_DEINIT_API == STD_ON) */

    #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckStartGroupConversion(uint32 CoreId, const Adc_GroupType Group);
LOCAL_INLINE Std_ReturnType Adc_CheckStopGroupConversion(uint32 CoreId, const Adc_GroupType Group);
    #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

    #if (ADC_READ_GROUP_API == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckReadGroup(uint32 CoreId, const Adc_GroupType Group,
                                               const Adc_ValueGroupType *const DataBufferPtr);
    #endif /* (ADC_READ_GROUP_API == STD_ON) */

    #if (ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckEnableHardwareTrigger(uint32              CoreId,
                                                           const Adc_GroupType Group);
LOCAL_INLINE Std_ReturnType Adc_CheckDisableHardwareTrigger(uint32              CoreId,
                                                            const Adc_GroupType Group);
    #endif /* (ADC_HW_TRIGGER_API == STD_ON) */

    #if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckEnableDisableGroupNotification(uint32              CoreId,
                                                                    const Adc_GroupType Group,
                                                                    uint8               ServiceId);
    #endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */

    #if (ADC_CALIBRATION == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckCalibrate(uint32 CoreId, const Adc_HwUnitType Unit);
    #endif /* (ADC_CALIBRATION == STD_ON) */
#endif

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckStartGroupConvNotBusy(uint32 CoreId, const Adc_HwUnitType Unit,
                                                           const Adc_GroupType Group);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if ((ADC_HW_TRIGGER_API == STD_ON) || (ADC_CALIBRATION == STD_ON) ||                              \
     ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&                                               \
      (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && (ADC_ENABLE_QUEUING == STD_OFF)))
LOCAL_INLINE Std_ReturnType Adc_CheckHWUnitBusy(const Adc_HwUnitType Unit, uint8 ServiceId);
#endif /* ((ADC_HW_TRIGGER_API == STD_ON) || (ADC_CALIBRATION == STD_ON) ||                        \
          ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&                                          \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) &&                                    \
          (ADC_ENABLE_QUEUING == STD_OFF))) */
#if ((ADC_DEINIT_API == STD_ON) || (ADC_CALIBRATION == STD_ON))
LOCAL_INLINE Std_ReturnType Adc_CheckGroupBusyStatus(uint32 CoreId, uint8 ServiceId);
#endif /* ((ADC_DEINIT_API == STD_ON) || (ADC_CALIBRATION == STD_ON)) */
LOCAL_INLINE void Adc_InitGroupsStatus(uint32 CoreId);
LOCAL_INLINE void Adc_InitUnitStatus(uint32 CoreId);
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&                                                \
     (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
LOCAL_INLINE Std_ReturnType Adc_InsertQueue(uint32 CoreId, const Adc_HwUnitType Unit,
                                            const Adc_GroupType Group);
#endif

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
LOCAL_INLINE void Adc_UpdateStartConversionStatus(uint32 CoreId, const Adc_HwUnitType Unit,
                                                  const Adc_GroupType Group);

LOCAL_INLINE Std_ReturnType Adc_StopSwGroupConversion(
    #if (ADC_ENABLE_QUEUING == STD_ON)
    Adc_QueueIndexType *RemovedPos,
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    uint32 CoreId, const Adc_HwUnitType Unit, const Adc_GroupType Group);

LOCAL_INLINE void Adc_UpdateStopConversionStatus(uint32 CoreId, const Adc_HwUnitType Unit,
                                                 const Adc_GroupType Group);
#endif

#if (ADC_READ_GROUP_API == STD_ON)
LOCAL_INLINE void Adc_UpdateReadGroupInterruptStatus(uint32 CoreId, const Adc_GroupType Group);

LOCAL_INLINE Std_ReturnType Adc_ReadGroupInterrupt(uint32 CoreId, const Adc_HwUnitType Unit,
                                                   const Adc_GroupType Group,
                                                   Adc_ValueGroupType *DataBufferPtr);
#endif /* (ADC_READ_GROUP_API == STD_ON) */

LOCAL_INLINE void Adc_UpdateAfterGetStreamStatus(uint32 CoreId, const Adc_GroupType Group);
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
LOCAL_INLINE Adc_ChannelType Adc_GetChannelIndex(uint32 CoreId, Adc_HwUnitType Unit,
                                                 Adc_ChannelType Channel);
LOCAL_INLINE boolean         Adc_CheckConversionValuesInRange(uint32 CoreId, Adc_HwUnitType Unit,
                                                              Adc_ChannelType    Channel,
                                                              Adc_ValueGroupType Value);
LOCAL_INLINE void Adc_HandleLimitCheckFail(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group);
    #if (ADC_DMA_USED == STD_ON)
LOCAL_INLINE Std_ReturnType Adc_CheckDmaConversionResult(uint32 CoreId, Adc_HwUnitType Unit,
                                                         Adc_GroupType Group);
    #endif /* (ADC_DMA_USED == STD_ON) */
#endif     /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
LOCAL_INLINE void Adc_InternalStartConversion(uint32 CoreId, const Adc_HwUnitType Unit,
                                              const Adc_GroupType Group);
LOCAL_INLINE void Adc_SwTriggerConversion(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group);
#if (ADC_ENABLE_QUEUING == STD_ON)
LOCAL_INLINE void Adc_RemoveFromQueue(const Adc_HwUnitType     Unit,
                                      const Adc_QueueIndexType CurQueueIndex);
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
LOCAL_INLINE Std_ReturnType Adc_CheckConversionResult(uint32 CoreId, Adc_HwUnitType Unit,
                                                      Adc_GroupType Group);
#if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
LOCAL_INLINE void Adc_CallNotification(uint32 CoreId, Adc_GroupType Group);
#endif /* ADC_GROUP_NOTIF_CAPABILITY == STD_ON */
LOCAL_INLINE void Adc_UpdateSwGroupState(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group);
LOCAL_INLINE void Adc_ProcessSwConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                             Adc_GroupType Group);
#if (ADC_DMA_USED == STD_ON)
LOCAL_INLINE void Adc_ProcessSwDmaConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                                Adc_GroupType Group);
#endif /* (ADC_DMA_USED == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE void Adc_UpdateHwGroupState(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group);
LOCAL_INLINE void Adc_ProcessHwConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                             Adc_GroupType Group);
    #if (ADC_DMA_USED == STD_ON)
LOCAL_INLINE void Adc_ProcessHwDmaConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                                Adc_GroupType Group);
    #endif /* (ADC_DMA_USED == STD_ON) */
#endif     /* (ADC_HW_TRIGGER_API == STD_ON) */
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief     This function get number of shift bits according to alignment
 *
 *
 * @param[in] Resolution: Adc resolution enum value
 *
 * @return    uint8: Number of bits shift
 */
LOCAL_INLINE uint8 Adc_GetBitShiftNums(Adc_Drv_ResolutionType Resolution)
{
    uint8 NumsBitShift;
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    switch (Resolution)
    {
        case ADC_DRV_RESOLUTION_8BIT:
            NumsBitShift = 8U;
            break;
        case ADC_DRV_RESOLUTION_10BIT:
            NumsBitShift = 6U;
            break;
        case ADC_DRV_RESOLUTION_12BIT:
            NumsBitShift = 4U;
            break;
        default:
            /* Default is 12 bits */
            NumsBitShift = 4U;
            break;
    }
#else
    NumsBitShift = 0U;
    (void)Resolution;
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */

    return NumsBitShift;
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief     This function get logic channel index from the physical channel id
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Unit: Adc Hardware Unit.
 * @param[in] Channel: channel assigned to a group.
 *
 * @return    Adc_ChannelType: Channel Index, if not found, return 0xFF.
 */
LOCAL_INLINE Adc_ChannelType Adc_GetChannelIndex(uint32 CoreId, Adc_HwUnitType Unit,
                                                 Adc_ChannelType Channel)
{
    const Adc_Drv_ChannelConfigType *ChannelConfigPtr;
    const uint8                      ChannelCount = Adc_ConfigPtr[CoreId]
                                   ->HWUnitConfigList[Unit]
                                   .HWUnitConfigPtr->AdcDrvConfigPtr->ConfiguredChannelCount;
    Adc_ChannelType ChannelIndex = ADC_INVALID_CHANNEL_INDEX;
    Adc_ChannelType Index;

    for (Index = 0; Index < (Adc_ChannelType)ChannelCount; Index++)
    {
        ChannelConfigPtr = &(Adc_ConfigPtr[CoreId]
                                 ->HWUnitConfigList[Unit]
                                 .HWUnitConfigPtr->AdcDrvConfigPtr->ChannelConfigList[Index]);
        if (Channel == (Adc_ChannelType)ChannelConfigPtr->Channel)
        {
            ChannelIndex = Index;
            break;
        }
    }
    return ChannelIndex;
}

/**
 * @brief     This function checks if conversion values are in the configured range.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Unit: Adc Hardware Unit.
 * @param[in] Channel:    channel assigned to a group.
 * @param[in] Value:           Adc conversion value.
 *
 * @return    boolean: Conversion value in range flag.
 * @retval    TRUE:    If conversion values are in the configured range.
 * @retval    FALSE:   If conversion values are not in the configured range.
 *
 */
LOCAL_INLINE boolean Adc_CheckConversionValuesInRange(uint32 CoreId, Adc_HwUnitType Unit,
                                                      Adc_ChannelType    Channel,
                                                      Adc_ValueGroupType Value)
{

    const Adc_ChannelLimitCheckType *LimitCheckCfgPtr;
    Adc_ChannelRangeSelectType       ChannelRange;
    Adc_ValueGroupType               LowLimit;
    Adc_ValueGroupType               HighLimit;
    boolean                          CheckResult = FALSE;
    Adc_ChannelType                  ChannelIndex;

    ChannelIndex = Adc_GetChannelIndex(CoreId, Unit, Channel);
    if (ADC_INVALID_CHANNEL_INDEX != ChannelIndex)
    {
        LimitCheckCfgPtr = &(Adc_ConfigPtr[CoreId]
                                 ->HWUnitConfigList[Unit]
                                 .HWUnitConfigPtr->ChannelLimitCheckingConfig[ChannelIndex]);
        ChannelRange = LimitCheckCfgPtr->ChannelRange;
        LowLimit = LimitCheckCfgPtr->ChannelLowLimit;
        HighLimit = LimitCheckCfgPtr->ChannelHighLimit;
        switch (ChannelRange)
        {
            case ADC_RANGE_ALWAYS:
            {
                CheckResult = TRUE;
                break;
            }
            case ADC_RANGE_BETWEEN:
            {
                if ((Value > LowLimit) && (Value <= HighLimit))
                {
                    CheckResult = TRUE;
                }
                break;
            }
            case ADC_RANGE_NOT_BETWEEN:
            {
                if ((Value > HighLimit) || (Value <= LowLimit))
                {
                    CheckResult = TRUE;
                }
                break;
            }
            case ADC_RANGE_NOT_OVER_HIGH:
            {
                if (Value <= HighLimit)
                {
                    CheckResult = TRUE;
                }
                break;
            }
            case ADC_RANGE_NOT_UNDER_LOW:
            {
                if (Value > LowLimit)
                {
                    CheckResult = TRUE;
                }
                break;
            }
            case ADC_RANGE_OVER_HIGH:
            {
                if (Value > HighLimit)
                {
                    CheckResult = TRUE;
                }
                break;
            }
            case ADC_RANGE_UNDER_LOW:
            {
                if (Value <= LowLimit)
                {
                    CheckResult = TRUE;
                }
                break;
            }
            default:
            {
                /* noting to do */
                break;
            }
        }
    }
    return CheckResult;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_DMA_USED == STD_ON)
    #if (ADC_READ_GROUP_API == STD_ON)
/**
 * @brief     This function gets data mask based on selected Adc resolution
 *
 * @param[in] Resolution: Adc resolution enum value
 *
 * @return    uint16: Data mask
 */
LOCAL_INLINE uint16 Adc_GetDataMask(Adc_Drv_ResolutionType Resolution)
{
    uint16 Mask;
    switch (Resolution)
    {
        case ADC_DRV_RESOLUTION_8BIT:
            Mask = 0xFFU;
            break;
        case ADC_DRV_RESOLUTION_10BIT:
            Mask = 0x3FFU;
            break;
        case ADC_DRV_RESOLUTION_12BIT:
            Mask = 0xFFFU;
            break;
        default:
            /* Default is 12 bits */
            Mask = 0xFFFU;
            break;
    }
    return Mask;
}
    #endif /* (ADC_READ_GROUP_API == STD_ON) */
/**
 * @brief     This function configures the DMA Transfer involved in the ADC conversion process.
 * @details   This function configures the Dma Drv to Transfer data
 *            from Data Register to Result Buffer.
 *            It should be called with the ADC Unit on standby
 *            (no ADC interrupt event allowed because
 *            its code is not protected by critical regions) - no conversions is ongoing.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Unit: The Adc Logical Unit Id.
 * @param[in] Group: Group number
 * @param[in] ChannelNum: Number of channels
 * @param[in] DmaChannel: Dma channel
 *
 * @return    None
 *
 * @pre  ADC Unit is in stand by, there is no ongoing conversion.
 */
LOCAL_INLINE void Adc_ConfigureDma(uint32 CoreId, uint8 Unit, const uint16 Group, uint8 ChannelNum,
                                   uint8 DmaChannel)
{
    Dma_Drv_ChannelTransferConfigType *DmaChlTransferCfgPtr = &Adc_DmaChannelTransferConfig;
    uint32                             DestAddr;
    uint16                             MinorLoopOffset;
    #if (STD_ON == ADC_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif /* (STD_ON == ADC_DEV_ERROR_DETECT) */

    #if (STD_ON == ADC_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Unit < ADC_MAX_HWUNITS);
    #endif /* (STD_ON == ADC_DEV_ERROR_DETECT) */

    DmaChlTransferCfgPtr->SourceConfig = &Adc_DmaChannelSourceConfig;
    DmaChlTransferCfgPtr->DestinationConfig = &Adc_DmaChannelDestinationConfig;
    DmaChlTransferCfgPtr->ControlConfig = &Adc_DmaChannelControlConfig;

    /* Disable request after done control */
    DmaChlTransferCfgPtr->ControlConfig->ReqDis = (boolean)TRUE;
    /* Transfer bytes number */
    DmaChlTransferCfgPtr->ControlConfig->TransferNum = 2U * (uint32)ChannelNum;
    /* Number of minor loop in a major loop: 1 */
    DmaChlTransferCfgPtr->ControlConfig->MinorLoopCnt = 1U;
    /* Address pointing to the source data */
    DmaChlTransferCfgPtr->SourceConfig->Addr = (uint32)Adc_Drv_GetDataAddress(Unit);
    /* Source address offset in minor loop */
    DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = (sint16)0U;
    /* Source address offset after a major loop done */
    DmaChlTransferCfgPtr->SourceConfig->MajorLoopOffset = (sint16)0U;
    /* Source data transfer size */
    DmaChlTransferCfgPtr->SourceConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;

    /* Address pointing to the destination data */
    DestAddr =
        (uint32)(&(Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ResultsBufferPtr[Group][0U]));
    DmaChlTransferCfgPtr->DestinationConfig->Addr = DestAddr;
    /* Destination address offset in minor loop */
    MinorLoopOffset = 2U * Adc_ConfigPtr[CoreId]->GroupConfigList[Group].NumSamples;
    DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = (sint16)MinorLoopOffset;
    /* Destination address offset after a major loop done */
    DmaChlTransferCfgPtr->DestinationConfig->MajorLoopOffset = -((sint16)2U * (sint16)ChannelNum);
    /* Destination data transfer size */
    DmaChlTransferCfgPtr->DestinationConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;
    /* DMA transfer configure */
    Dma_Drv_SetChannelTransferConfig((Dma_Drv_ChannelType)DmaChannel, DmaChlTransferCfgPtr);

    /* Enable dma channel request*/
    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)DmaChannel);

    #if (STD_ON == ADC_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif /* (STD_ON == ADC_DEV_ERROR_DETECT) */
}
#endif /* (ADC_DMA_USED == STD_ON) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief     This function check the validity of called group
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 * @param[in] ServiceId: Service Id of the caller function
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckCalledGroup(uint32 CoreId, const Adc_GroupType Group,
                                                 uint8 ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR == Adc_ConfigPtr[CoreId])
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, ServiceId, ADC_E_UNINIT);
    }
    else if (CoreId != Adc_ConfigPtr[CoreId]->CoreId)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, ServiceId, ADC_E_PARAM_CONFIG);
    }
    else if (ADC_MAX_GROUPS <= Group)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, ServiceId, ADC_E_PARAM_GROUP);
    }
    else
    {
        /* Nothing to do */
    }
    return Ret;
}

/**
 * @brief     This function check the input of Adc_Init .
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] CfgPtr: Pointer to the initial Configuration
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckInit(uint32 CoreId, const Adc_ConfigType *CfgPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (ADC_STATE_UNINIT != Adc_GlobalState[CoreId])
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_INIT,
                              (uint8)ADC_E_ALREADY_INITIALIZED);
    }
    #if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    else if (NULL_PTR != CfgPtr)
    #else
    else if (NULL_PTR == CfgPtr)
    #endif /* (ADC_PRECOMPILE_SUPPORT == STD_ON) */
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_INIT,
                              (uint8)ADC_E_PARAM_POINTER);
    }
    #if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    else if (CoreId != Adc_PreDefinedConfigPtr[CoreId]->CoreId)
    #else
    else if (CoreId != CfgPtr->CoreId)
    #endif /* (ADC_PRECOMPILE_SUPPORT == STD_ON) */
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_INIT,
                              (uint8)ADC_E_PARAM_POINTER);
    }
    else
    {
        /* Nothing to do */
    }
    return Ret;
}

/**
 * @brief     This function check the input of Adc_SetupResultBuffer.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 * @param[in] DataBufferPtr: Pointer to Data Buffer
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckSetupResultBuffer(
    uint32 CoreId, const Adc_GroupType Group, const Adc_ValueGroupType *const DataBufferPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_SETUP_RESULT_BUFFER);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (NULL_PTR == DataBufferPtr)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_SETUP_RESULT_BUFFER, (uint8)ADC_E_PARAM_POINTER);
        }
        else
        {
            /* Nothing to do */
        }
    }

    return Ret;
}
    #if (ADC_DEINIT_API == STD_ON)
/**
 * @brief     This function check the input of Adc_DeInit.
 *
 * @param[in] CoreId: Current Core Id
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckDeInit(uint32 CoreId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (ADC_STATE_UNINIT == Adc_GlobalState[CoreId])
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_DEINIT,
                              (uint8)ADC_E_UNINIT);
    }
    else if (CoreId != Adc_ConfigPtr[CoreId]->CoreId)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_DEINIT,
                              (uint8)ADC_E_PARAM_CONFIG);
    }
    else
    {
        /* Nothing to do */
    }

    return Ret;
}
    #endif /* (ADC_DEINIT_API == STD_ON) */

    #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
 * @brief     This function check the input of Adc_StartGroupConversion.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckStartGroupConversion(uint32 CoreId, const Adc_GroupType Group)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_START_GROUP_CONVERSION);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (NULL_PTR == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ResultsBufferPtr[Group])
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_START_GROUP_CONVERSION,
                                  (uint8)ADC_E_BUFFER_UNINIT);
        }
        else if (ADC_TRIGG_SRC_SW != Adc_ConfigPtr[CoreId]->GroupConfigList[Group].TriggerSource)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_START_GROUP_CONVERSION,
                                  (uint8)ADC_E_WRONG_TRIGG_SRC);
        }
        else
        {
            /* Nothing to do */
        }
    }

    return Ret;
}

/**
 * @brief     This function check the input of Adc_StopGroupConversion.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckStopGroupConversion(uint32 CoreId, const Adc_GroupType Group)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_STOP_GROUP_CONVERSION);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (ADC_TRIGG_SRC_SW != Adc_ConfigPtr[CoreId]->GroupConfigList[Group].TriggerSource)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_STOP_GROUP_CONVERSION,
                                  (uint8)ADC_E_WRONG_TRIGG_SRC);
        }
        else
        {
            /* Nothing to do */
        }
    }

    return Ret;
}
    #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

    #if (ADC_READ_GROUP_API == STD_ON)
/**
 * @brief     This function check the input of Adc_ReadGroup.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 * @param[in] DataBufferPtr: Pointer to Data Buffer
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckReadGroup(uint32 CoreId, const Adc_GroupType Group,
                                               const Adc_ValueGroupType *const DataBufferPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_READ_GROUP);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (NULL_PTR == DataBufferPtr)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_READ_GROUP,
                                  (uint8)ADC_E_PARAM_POINTER);
        }
        else
        {
            /* Nothing to do */
        }
    }

    return Ret;
}
    #endif /* (ADC_READ_GROUP_API == STD_ON) */

    #if (ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief     This function check the input of Adc_EnableHardwareTrigger.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckEnableHardwareTrigger(uint32 CoreId, const Adc_GroupType Group)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_ENABLE_HARDWARE_TRIGGER);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (NULL_PTR == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ResultsBufferPtr[Group])
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_ENABLE_HARDWARE_TRIGGER,
                                  (uint8)ADC_E_BUFFER_UNINIT);
        }
        else if (ADC_TRIGG_SRC_SW == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].TriggerSource)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_ENABLE_HARDWARE_TRIGGER,
                                  (uint8)ADC_E_WRONG_TRIGG_SRC);
        }
        else if (ADC_CONV_MODE_CONTINUOUS ==
                 (Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode))
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_ENABLE_HARDWARE_TRIGGER,
                                  (uint8)ADC_E_WRONG_CONV_MODE);
        }
        else
        {
            /* Nothing to do */
        }
    }

    return Ret;
}

/**
 * @brief     This function check the input of Adc_DisableHardwareTrigger.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckDisableHardwareTrigger(uint32              CoreId,
                                                            const Adc_GroupType Group)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_DISABLE_HARDWARE_TRIGGER);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (ADC_TRIGG_SRC_SW == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].TriggerSource)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_DISABLE_HARDWARE_TRIGGER,
                                  (uint8)ADC_E_WRONG_TRIGG_SRC);
        }
        else if (ADC_CONV_MODE_CONTINUOUS ==
                 (Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode))
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U,
                                  (uint8)ADC_SID_DISABLE_HARDWARE_TRIGGER,
                                  (uint8)ADC_E_WRONG_CONV_MODE);
        }
        else
        {
            /* Nothing to do */
        }
    }

    return Ret;
}
    #endif /* (ADC_HW_TRIGGER_API == STD_ON) */

    #if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
/**
 * @brief     This function check the input of Adc_EnableGroupNotification and
 * Adc_DisableGroupNotification.
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Group: Group Id
 * @param[in] ServiceId: Service Id of the caller function
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckEnableDisableGroupNotification(uint32              CoreId,
                                                                    const Adc_GroupType Group,
                                                                    uint8               ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Adc_CheckCalledGroup(CoreId, Group, ServiceId);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (NULL_PTR == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].Notification)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ServiceId,
                                  (uint8)ADC_E_NOTIF_CAPABILITY);
        }
    }

    return Ret;
}
    #endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */

    #if (ADC_CALIBRATION == STD_ON)
/**
 * @brief     This function check the input of Adc_Calibrate
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Unit: Hardware unit
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckCalibrate(uint32 CoreId, const Adc_HwUnitType Unit)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR == Adc_ConfigPtr[CoreId])
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_CALIBRATE,
                              (uint8)ADC_E_UNINIT);
    }
    else if (Unit >= ADC_MAX_HWUNITS)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_CALIBRATE,
                              (uint8)ADC_E_PARAM_UNIT);
    }
    else if (CoreId != Adc_ConfigPtr[CoreId]->CoreId)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_CALIBRATE,
                              (uint8)ADC_E_PARAM_CONFIG);
    }
    else if (NULL_PTR == Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_CALIBRATE,
                              (uint8)ADC_E_PARAM_CONFIG);
    }
    else
    {
        /* Nothing to do */
    }

    return Ret;
}
    #endif /* (ADC_CALIBRATION == STD_ON) */

/**
 * @brief     This function check the input of Adc_SelfTest
 *
 * @param[in] CoreId: Current Core Id
 * @param[in] Unit: Hardware unit
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Valid
 * @retval    E_NOT_OK:       Invalid
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckSelfTest(uint32 CoreId, const Adc_HwUnitType Unit)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR == Adc_ConfigPtr[CoreId])
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_SELF_TEST,
                              (uint8)ADC_E_UNINIT);
    }
    else if (Unit >= ADC_MAX_HWUNITS)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_SELF_TEST,
                              (uint8)ADC_E_PARAM_UNIT);
    }
    else if (CoreId != Adc_ConfigPtr[CoreId]->CoreId)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_SELF_TEST,
                              (uint8)ADC_E_PARAM_CONFIG);
    }
    else if (NULL_PTR == Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_SID_SELF_TEST,
                              (uint8)ADC_E_PARAM_CONFIG);
    }
    else
    {
        /* Nothing to do */
    }

    return Ret;
}
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

/**
 * @brief     This function check if given HW Unit is busy.
 *
 * @param[in] Unit:  Hardware Unit
 * @param[in] Group: Group Id
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           HW Unit is not busy
 * @retval    E_NOT_OK:       HW Unit is busy
 */
LOCAL_INLINE Std_ReturnType Adc_CheckHWUnitBusy(const Adc_HwUnitType Unit, uint8 ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (((Adc_QueueIndexType)0U < Adc_UnitStatus[Unit].SwNormalQueueIndex)
#if (ADC_HW_TRIGGER_API == STD_ON)
        || (ADC_INVALID_HW_GROUP_ID != Adc_UnitStatus[Unit].OngoingHwGroup)
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    )
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U, ServiceId, ADC_E_BUSY);
    }
    return Ret;
}

/**
 * @brief     This function check if all the groups are busy.
 *
 * @param[in] CoreId:  Current Core Id
 * @param[in] ServiceId: Service Id of called function
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Group is not busy
 * @retval    E_NOT_OK:       group is busy
 */
LOCAL_INLINE Std_ReturnType Adc_CheckGroupBusyStatus(uint32 CoreId, uint8 ServiceId)
{
    Adc_StatusType ConvStatus;
    Adc_GroupType  Index;
    Adc_GroupType  GroupId;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    for (Index = 0U; Index < (Adc_GroupType)Adc_ConfigPtr[CoreId]->GroupCount; Index++)
    {
        GroupId = Adc_ConfigPtr[CoreId]->GroupConfigList[Index].GroupId;
        ConvStatus = Adc_GroupStatus[GroupId].ConvStatus;
        /*  Check if ADC is still converting */
        if ((ADC_IDLE != ConvStatus) && (ADC_STREAM_COMPLETED != ConvStatus))
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U, ServiceId,
                                         (uint8)ADC_E_BUSY);
            break;
        }
    }
    return Ret;
}

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
 * @brief     This function check the state of a group when start group conversion.
 *
 * @param[in] CoreId:  Current Core Id
 * @param[in] Unit:  Hardware Unit
 * @param[in] Group:  Group id
 * @param[in] ServiceId: Service Id of called function
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Group is not busy
 * @retval    E_NOT_OK:       Group is busy
 */
LOCAL_INLINE Std_ReturnType Adc_CheckStartGroupConvNotBusy(uint32 CoreId, const Adc_HwUnitType Unit,
                                                           const Adc_GroupType Group)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    #if ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE
    boolean            FoundFlag = FALSE;
    Adc_QueueIndexType Index = 0U;
    Adc_QueueIndexType QueueIdx;
    #endif
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || (ADC_ENABLE_QUEUING != STD_OFF)
    boolean        CanStoppedFlag = FALSE;
    Adc_StatusType ConvStatus;
    if ((ADC_CONV_MODE_ONESHOT == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode) ||
        ((ADC_CONV_MODE_CONTINUOUS == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode) &&
         (ADC_ACCESS_MODE_STREAMING == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AccessMode) &&
         (ADC_STREAM_BUFFER_LINEAR == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].BufferMode)))
    {
        /* The current group can be implicitly stopped */
        CanStoppedFlag = TRUE;
    }
    #endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || (ADC_ENABLE_QUEUING !=         \
              STD_OFF) */

    #if (ADC_HW_TRIGGER_API == STD_ON)
    if (ADC_INVALID_HW_GROUP_ID != Adc_UnitStatus[Unit].OngoingHwGroup)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                     (uint8)ADC_SID_START_GROUP_CONVERSION, (uint8)ADC_E_BUSY);
    }
    else
    {
    #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
        #if (ADC_ENABLE_QUEUING == STD_OFF)
    Ret = Adc_CheckHWUnitBusy(Unit, ADC_SID_START_GROUP_CONVERSION);
        #else  /* ADC_ENABLE_QUEUING == STD_ON */
    ConvStatus = Adc_GroupStatus[Group].ConvStatus;
    if ((FALSE == CanStoppedFlag) && (ADC_IDLE != ConvStatus))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                     (uint8)ADC_SID_START_GROUP_CONVERSION, (uint8)ADC_E_BUSY);
    }
    else if ((TRUE == CanStoppedFlag) && (ADC_IDLE != ConvStatus) &&
             (ADC_STREAM_COMPLETED != ConvStatus))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                     (uint8)ADC_SID_START_GROUP_CONVERSION, (uint8)ADC_E_BUSY);
    }
    else if (ADC_QUEUE_MAX_QUEUE_DEPTH <= Adc_UnitStatus[Unit].SwNormalQueueIndex)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                     (uint8)ADC_SID_START_GROUP_CONVERSION,
                                     (uint8)ADC_E_QUEUE_FULL);
    }
    else
    {
        /* Nothing to do */
    }
        #endif /* ADC_ENABLE_QUEUING */

    #else  /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
    if (Adc_UnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
    {
        for (Index = 0U; Index < Adc_UnitStatus[Unit].SwNormalQueueIndex; Index++)
        {
            if (Group == Adc_UnitStatus[Unit].SwNormalQueue[Index])
            {
                FoundFlag = TRUE;
                break;
            }
        }
    }
    QueueIdx = Adc_UnitStatus[Unit].SwNormalQueueIndex;
    ConvStatus = Adc_GroupStatus[Group].ConvStatus;
    if ((((Group == Adc_UnitStatus[Unit].SwNormalQueue[0U]) &&
          (QueueIdx > (Adc_QueueIndexType)0U)) ||
         (TRUE == FoundFlag)) &&
        (FALSE == CanStoppedFlag))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                     (uint8)ADC_SID_START_GROUP_CONVERSION, (uint8)ADC_E_BUSY);
    }
    else if (((ConvStatus != ADC_IDLE) && (ConvStatus != ADC_STREAM_COMPLETED)) &&
             (TRUE == CanStoppedFlag))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                     (uint8)ADC_SID_START_GROUP_CONVERSION, (uint8)ADC_E_BUSY);
    }
    else if (ADC_QUEUE_MAX_QUEUE_DEPTH <= Adc_UnitStatus[Unit].SwNormalQueueIndex)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                     (uint8)ADC_SID_START_GROUP_CONVERSION,
                                     (uint8)ADC_E_QUEUE_FULL);
    }
    else
    {
        /* Nothing to do */
    }
    #endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
    #if (ADC_HW_TRIGGER_API == STD_ON)
    }
    #endif /* (ADC_HW_TRIGGER_API == STD_ON) */

    return Ret;
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

/**
 * @brief     This function initializes the group status.
 *
 * @param[in] CoreId: Current CoreID
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_InitGroupsStatus(uint32 CoreId)
{
    Adc_GroupType GroupCnt = 0U;
    Adc_GroupType GroupId = 0U;

    for (GroupCnt = 0U; GroupCnt < Adc_ConfigPtr[CoreId]->GroupCount; GroupCnt++)
    {
        GroupId = Adc_ConfigPtr[CoreId]->GroupConfigList[GroupCnt].GroupId;
        Adc_GroupStatus[GroupId].ConvStatus = ADC_IDLE;
        Adc_GroupStatus[GroupId].AlreadyConverted = ADC_NOT_YET_CONVERTED;

        Adc_GroupStatus[GroupId].ResultIndex = 0U;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        Adc_GroupStatus[GroupId].LimitCheckFailed = FALSE;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
        Adc_GroupStatus[GroupId].HwTriggering = ADC_HWTRIGGER_DISABLED;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
        Adc_GroupStatus[GroupId].Notification = ADC_NOTIFICATION_DISABLED;
#endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */
        Adc_Drv_InitGroupConfig(GroupId,
                                Adc_ConfigPtr[CoreId]->GroupConfigList[GroupCnt].AdcGroupConfigPtr);
        Tdg_Adc_Drv_InitGroupConfig(
            GroupId, Adc_ConfigPtr[CoreId]->GroupConfigList[GroupCnt].TdgGroupConfigPtr);
    }
}

/**
 * @brief     This function initializes the HW Unit status .
 *
 * @param[in] CoreId: Current CoreID
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_InitUnitStatus(uint32 CoreId)
{
    Adc_HwUnitType     Unit = 0U;
    Adc_QueueIndexType QueueIdx = 0U;

    (void)CoreId;
    for (Unit = 0U; Unit < ADC_MAX_HWUNITS; Unit++)
    {
        Adc_UnitStatus[Unit].SwNormalQueueIndex = 0U;

        for (QueueIdx = 0U; QueueIdx < ADC_QUEUE_MAX_QUEUE_DEPTH; QueueIdx++)
        {
            Adc_UnitStatus[Unit].SwNormalQueue[QueueIdx] = 0U;
        }
#if (ADC_HW_TRIGGER_API == STD_ON)
        Adc_UnitStatus[Unit].OngoingHwGroup = ADC_INVALID_HW_GROUP_ID;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    }
}

/**
 * @brief     This function calls driver interfaces to start a conversion.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit.
 * @param[in] Group:  Group id.
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_InternalStartConversion(uint32 CoreId, const Adc_HwUnitType Unit,
                                              const Adc_GroupType Group)
{
    uint8 ChannelNum = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AssignedChannelCount;
    const ADC_Drv_PositiveChannelType *ChannelList =
        Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AssignedChannelList;

#if (ADC_DMA_USED == STD_ON)
    if ((uint8)ADC_DRV_DMA ==
        Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->TransferMode)
    {
        /* Setting for DMA transfer */
        Adc_ConfigureDma(CoreId, Unit, Group, ChannelNum,
                         Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->DmaChannel);
    }
#endif /* (ADC_DMA_USED == STD_ON) */

    /* Configure adc register to start conversion */
    (void)Adc_Drv_StartConversion(Unit, Group, ChannelNum, ChannelList);
    /* Configure tdg register to start conversion */
    (void)Tdg_Adc_Drv_StartConversion(Unit, Group);
}
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&                                                \
     (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
/**
 * @brief     This function inserts a group into the queue.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit.
 * @param[in] Group:  Group id.
 *
 * @return    None
 */
LOCAL_INLINE Std_ReturnType Adc_InsertQueue(uint32 CoreId, const Adc_HwUnitType Unit,
                                            const Adc_GroupType Group)
{
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;
    #if (ADC_QUEUE_MAX_QUEUE_DEPTH != 1U)
    Adc_QueueIndexType QueueTemp = 0U;
    /* If new group has higher priority than current ongoing group, ongoing group will not be
     * aborted, new group will be inserted into the right position behind ongoing group(i.e.
     * position 0). That is the reason position start from 1. */
    Adc_QueueIndexType    Position = 1U;
    Adc_GroupPriorityType Priority = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].Priority;
    Adc_QueueIndexType    QueueIdx = Adc_UnitStatus[Unit].SwNormalQueueIndex;

    /* Find the position to insert new group. */
    if (1U < QueueIdx)
    {
        while (Adc_ConfigPtr[CoreId]
                   ->GroupConfigList[(Adc_UnitStatus[Unit].SwNormalQueue[Position])]
                   .Priority >= Priority)
        {
            Position++;
            if (Position >= QueueIdx)
            {
                break;
            }
        }
    }
    else
    {
        /* If there is only one group in queue, new group will be inserted into position 1. */
    }

    /* Insert new group into queue. */
    if (QueueIdx > Position)
    {
        for (QueueTemp = QueueIdx; QueueTemp > Position; QueueTemp--)
        {
            Adc_UnitStatus[Unit].SwNormalQueue[QueueTemp] =
                (Adc_GroupType)Adc_UnitStatus[Unit].SwNormalQueue[QueueTemp - 1U];
        }
    }
    Adc_UnitStatus[Unit].SwNormalQueue[Position] = Group;
    Adc_UnitStatus[Unit].SwNormalQueueIndex++;

    Status = (Std_ReturnType)E_OK;
    #endif

    return Status;
}
#endif /* ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) && (ADC_PRIORITY_IMPLEMENTATION !=          \
          ADC_PRIORITY_NONE)) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
 * @brief     This function update queue before start a group conversion.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit.
 * @param[in] Group:  Group id.
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_UpdateStartConversionStatus(uint32 CoreId, const Adc_HwUnitType Unit,
                                                  const Adc_GroupType Group)
{
    /* First available slot in the Queue */
    Adc_QueueIndexType QueueIdx = 0U;
    Std_ReturnType     Ret = (Std_ReturnType)E_OK;

    Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
    Adc_GroupStatus[Group].ResultIndex = 0U;

    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    SchM_Enter_Adc_SwNormalQueueUpdate();
    QueueIdx = Adc_UnitStatus[Unit].SwNormalQueueIndex;
    if (QueueIdx > (Adc_QueueIndexType)0U)
    {
        Ret = Adc_InsertQueue(CoreId, Unit, Group);

        if ((Std_ReturnType)E_NOT_OK == Ret)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                         (uint8)ADC_SID_START_GROUP_CONVERSION,
                                         (uint8)ADC_E_QUEUE_FULL);
        }
    }
    SchM_Exit_Adc_SwNormalQueueUpdate();
    #else /* ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE */
        #if (ADC_ENABLE_QUEUING == STD_ON) && (ADC_QUEUE_MAX_QUEUE_DEPTH != 1U)
    SchM_Enter_Adc_SwNormalQueueUpdate();
    QueueIdx = Adc_UnitStatus[Unit].SwNormalQueueIndex;
    if (QueueIdx > (Adc_QueueIndexType)0U)
    {
        Adc_UnitStatus[Unit].SwNormalQueue[QueueIdx] = Group;
        Adc_UnitStatus[Unit].SwNormalQueueIndex++;
    }
    SchM_Exit_Adc_SwNormalQueueUpdate();
        #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    #endif     /* ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE */

    SchM_Enter_Adc_SwNormalQueueUpdate();
    QueueIdx = Adc_UnitStatus[Unit].SwNormalQueueIndex;
    #if (ADC_ENABLE_QUEUING == STD_ON)
    if ((Adc_UnitStatus[Unit].SwNormalQueue[0U] == Group) || (0U == QueueIdx))
    {
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
        if (0U == QueueIdx)
        {
            Adc_UnitStatus[Unit].SwNormalQueue[0U] = Group;
            Adc_UnitStatus[Unit].SwNormalQueueIndex++;
        }
        SchM_Exit_Adc_SwNormalQueueUpdate();

        Adc_InternalStartConversion(CoreId, Unit, Group);

    #if (ADC_ENABLE_QUEUING == STD_ON)
    }
    else
    {
        SchM_Exit_Adc_SwNormalQueueUpdate();
    }
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    (void)Ret;
}

/**
 * @brief      This function stop the current software group conversion.
 *
 * @param[out] RemovedPos: The removed position in queue.
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit.
 * @param[in] Group:  Group id.
 *
 * @return     Std_ReturnType
 *
 */
LOCAL_INLINE Std_ReturnType Adc_StopSwGroupConversion(
    #if (ADC_ENABLE_QUEUING == STD_ON)
    Adc_QueueIndexType *RemovedPos,
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    uint32 CoreId, const Adc_HwUnitType Unit, const Adc_GroupType Group)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    #if (ADC_ENABLE_QUEUING == STD_ON)
    Adc_QueueIndexType QueueIdx;
    Adc_QueueIndexType NumOfQueue;
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

    (void)CoreId;

    #if (ADC_ENABLE_QUEUING == STD_ON)
    *RemovedPos = Adc_UnitStatus[Unit].SwNormalQueueIndex;
    NumOfQueue = Adc_UnitStatus[Unit].SwNormalQueueIndex;
    for (QueueIdx = 0U; QueueIdx < NumOfQueue; QueueIdx++)
    {
        if (Group == Adc_UnitStatus[Unit].SwNormalQueue[QueueIdx])
        {
            *RemovedPos = QueueIdx;

            if ((Adc_QueueIndexType)0U == QueueIdx)
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
            {
                (void)Tdg_Adc_Drv_StopConversion(Unit);
                (void)Adc_Drv_StopConversion(Unit);
            }
    #if (ADC_ENABLE_QUEUING == STD_ON)
            Adc_RemoveFromQueue(Unit, QueueIdx);
        }
    }
    #else
    Adc_UnitStatus[Unit].SwNormalQueueIndex = 0U;
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

    return Ret;
}

/**
 * @brief     This function update queue before start a group conversion.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit.
 * @param[in] Group:  Group id.
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_UpdateStopConversionStatus(uint32 CoreId, const Adc_HwUnitType Unit,
                                                 const Adc_GroupType Group)
{
    #if (ADC_ENABLE_QUEUING == STD_ON)
    Adc_QueueIndexType RemovedPos = 0U;
    Std_ReturnType     Ret = (Std_ReturnType)E_OK;
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    Adc_GroupConvModeType    ConvMode;
    Adc_GroupAccessModeType  AccessMode;
    Adc_StreamBufferModeType BufferMode;
    Adc_StatusType           ConvStatus;

    ConvMode = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode;
    AccessMode = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AccessMode;
    BufferMode = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].BufferMode;
    ConvStatus = Adc_GroupStatus[Group].ConvStatus;

    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    Adc_GroupStatus[Group].LimitCheckFailed = FALSE;
    #endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
    Adc_GroupStatus[Group].ResultIndex = 0U;
    #if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
    Adc_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
    #endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */
    if (((ADC_CONV_MODE_ONESHOT == ConvMode) ||
         ((ADC_ACCESS_MODE_STREAMING == AccessMode) && (ADC_STREAM_BUFFER_LINEAR == BufferMode))) &&
        (ADC_STREAM_COMPLETED == ConvStatus))
    {
        Adc_GroupStatus[Group].ConvStatus = ADC_IDLE;
    }
    else
    {
    #if (ADC_ENABLE_QUEUING == STD_ON)
        Ret = Adc_StopSwGroupConversion(&RemovedPos, CoreId, Unit, Group);
    #else
        (void)Adc_StopSwGroupConversion(CoreId, Unit, Group);
    #endif /* ADC_ENABLE_QUEUING == STD_ON */

        Adc_GroupStatus[Group].ConvStatus = ADC_IDLE;

    #if (ADC_ENABLE_QUEUING == STD_ON)
        if ((Adc_QueueIndexType)0U == RemovedPos)
        {
            if (Adc_UnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
            {
                Adc_InternalStartConversion(CoreId, Unit, Adc_UnitStatus[Unit].SwNormalQueue[0U]);
            }
        }
        if ((Std_ReturnType)E_NOT_OK == Ret)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                         (uint8)ADC_SID_STOP_GROUP_CONVERSION,
                                         (uint8)ADC_E_TIMEOUT);
        }
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    }
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
/**
 * @brief     This function update for group read when interrupt is used.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Group:  Group id.
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_UpdateReadGroupInterruptStatus(uint32 CoreId, const Adc_GroupType Group)
{
    /* The following code has been added to respect the State Diagram of Streaming Access Mode */
    if (ADC_COMPLETED == Adc_GroupStatus[Group].ConvStatus)
    {
        Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
    }
    else if (ADC_STREAM_COMPLETED == Adc_GroupStatus[Group].ConvStatus)
    {
        /* Follow AutoSar State Diagram */
        if (ADC_TRIGG_SRC_SW == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].TriggerSource)
        {
            if ((ADC_CONV_MODE_ONESHOT == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode) ||
                ((ADC_CONV_MODE_CONTINUOUS ==
                  Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode) &&
                 (ADC_ACCESS_MODE_STREAMING ==
                  Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AccessMode) &&
                 (ADC_STREAM_BUFFER_LINEAR ==
                  Adc_ConfigPtr[CoreId]->GroupConfigList[Group].BufferMode)))
            {
                /* SWS_Adc_00330, SWS_Adc_00221 */
                Adc_GroupStatus[Group].ConvStatus = ADC_IDLE;
            }
            else
            {
                /* Continuous single access or circular streaming buffer mode */
                Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
            }
        }
    #if (ADC_HW_TRIGGER_API == STD_ON)
        else
        {
            if ((ADC_ACCESS_MODE_STREAMING ==
                 Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AccessMode) &&
                (ADC_STREAM_BUFFER_LINEAR ==
                 Adc_ConfigPtr[CoreId]->GroupConfigList[Group].BufferMode))
            {
                Adc_GroupStatus[Group].ConvStatus = ADC_IDLE;
            }
            else
            {
                Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
            }
        }
    #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    }
    else
    {
        /* Nothing to do */
    }
}

/**
 * @brief     This function group read when interrupt is used.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit: Hardware Unit
 * @param[in] Group:  Group id.
 * @param[in] DataBufferPtr: Pointer to a buffer which will be filled by the conversion results.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:           Successful.
 * @retval    E_NOT_OK:       Failed.
 *
 */
LOCAL_INLINE Std_ReturnType Adc_ReadGroupInterrupt(uint32 CoreId, const Adc_HwUnitType Unit,
                                                   const Adc_GroupType Group,
                                                   Adc_ValueGroupType *DataBufferPtr)
{
    Std_ReturnType             Ret = (Std_ReturnType)E_OK;
    const Adc_GroupConfigType *GroupCfgPtr = &(Adc_ConfigPtr[CoreId]->GroupConfigList[Group]);
    Adc_StreamNumSampleType    ResultIndex = 0U;
    const Adc_ValueGroupType  *ResultPtr = NULL_PTR;
    uint8                      Index;
    uint16                     ResultOffset;
    Adc_ChannelIndexType       ChannelCount;
    #if (ADC_DMA_USED == STD_ON)
    uint8 TransferMode =
        Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->TransferMode;
    Adc_Drv_ResolutionType Resolution;
    uint16                 DmaBufferMask;
    #endif /* (ADC_DMA_USED == STD_ON) */

    if (ADC_BUSY != Adc_GroupStatus[Group].ConvStatus)
    {
        /* Get index of last completed sample */
        ResultIndex = Adc_GroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1U;
        if ((Adc_StreamNumSampleType)0U == Adc_GroupStatus[Group].ResultIndex)
        {
            ResultIndex = GroupCfgPtr->NumSamples - (Adc_StreamNumSampleType)1U;
        }
        ResultPtr = (Adc_ValueGroupType *)(&(GroupCfgPtr->ResultsBufferPtr[Group][ResultIndex]));
        ResultOffset = GroupCfgPtr->NumSamples;
        ChannelCount = GroupCfgPtr->AssignedChannelCount;

    #if (ADC_DMA_USED == STD_ON)
        if ((uint8)ADC_DRV_DMA == TransferMode)
        {
            Resolution = Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->Resolution;
            DmaBufferMask = Adc_GetDataMask(Resolution);
        }
    #endif /* (ADC_DMA_USED == STD_ON) */

        /* Copy results of last conversion from streaming buffer to internal buffer */
        for (Index = 0U; Index < ChannelCount; Index++)
        {
    #if (ADC_DMA_USED == STD_ON)
            if ((uint8)ADC_DRV_DMA == TransferMode)
            {
                DataBufferPtr[Index] = (Adc_ValueGroupType)((*ResultPtr) & DmaBufferMask);
            }
            else
    #endif /* (ADC_DMA_USED == STD_ON) */
            {
                DataBufferPtr[Index] = (*ResultPtr);
            }
            ResultPtr = &(ResultPtr[ResultOffset]);
        }
    }
    else
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    return Ret;
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

/**
 * @brief     This function update status after get stream last pointer operation.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Group:  Group id.
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_UpdateAfterGetStreamStatus(uint32 CoreId, const Adc_GroupType Group)
{
    if (ADC_COMPLETED == Adc_GroupStatus[Group].ConvStatus)
    {
        Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
    }
    else if (ADC_STREAM_COMPLETED == Adc_GroupStatus[Group].ConvStatus)
    {
        /* Follow AUTOSAR State Diagram */
        if (ADC_TRIGG_SRC_SW == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].TriggerSource)
        {
            if ((ADC_CONV_MODE_ONESHOT == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode) ||
                ((ADC_CONV_MODE_CONTINUOUS ==
                  Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode) &&
                 (ADC_ACCESS_MODE_STREAMING ==
                  Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AccessMode) &&
                 (ADC_STREAM_BUFFER_LINEAR ==
                  Adc_ConfigPtr[CoreId]->GroupConfigList[Group].BufferMode)))
            {
                Adc_GroupStatus[Group].ConvStatus = ADC_IDLE;
            }
            else
            {
                /* Continuous single access or circular streaming buffer mode */
                Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
            }
        }
#if (STD_ON == ADC_HW_TRIGGER_API)
        else
        {
            /* Hw Trigger */
            if ((ADC_ACCESS_MODE_STREAMING ==
                 Adc_ConfigPtr[CoreId]->GroupConfigList[Group].AccessMode) &&
                (ADC_STREAM_BUFFER_LINEAR ==
                 Adc_ConfigPtr[CoreId]->GroupConfigList[Group].BufferMode))
            {
                Adc_GroupStatus[Group].ConvStatus = ADC_IDLE;
            }
            else
            {
                /* Single access mode or circular streaming buffer mode */
                Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
            }
        }
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
    }
    else
    {
        /* Nothing to do */
    }
}

#if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
/**
 * @brief     This function checks and calls group notification
 * @details   This function checks and calls group notification
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Group:  The group to be converted
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_CallNotification(uint32 CoreId, Adc_GroupType Group)
{
    if ((ADC_NOTIFICATION_ENABLED == Adc_GroupStatus[Group].Notification) &&
        (NULL_PTR != Adc_ConfigPtr[CoreId]->GroupConfigList[Group].Notification))
    {
        Adc_ConfigPtr[CoreId]->GroupConfigList[Group].Notification();
    }
}
#endif /* ADC_GROUP_NOTIF_CAPABILITY == STD_ON */

#if (ADC_ENABLE_QUEUING == STD_ON)
/**
 * @brief     This function performs the dequeue operation on the internal ADC queue.
 *
 * @param[in] Unit: Hardware Unit.
 * @param[in] CurQueueIndex   The current queue index.
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_RemoveFromQueue(const Adc_HwUnitType     Unit,
                                      const Adc_QueueIndexType CurQueueIndex)
{
    Adc_QueueIndexType PositionIndex = 0U;
    Adc_QueueIndexType NumOfQueue = 0U;

    SchM_Enter_Adc_SwNormalQueueUpdate();
    NumOfQueue = Adc_UnitStatus[Unit].SwNormalQueueIndex;
    if ((Adc_QueueIndexType)1U < NumOfQueue)
    {
        for (PositionIndex = (CurQueueIndex + 1U); PositionIndex < NumOfQueue; PositionIndex++)
        {
            Adc_UnitStatus[Unit].SwNormalQueue[PositionIndex - 1U] =
                (Adc_GroupType)Adc_UnitStatus[Unit].SwNormalQueue[PositionIndex];
        }
        Adc_UnitStatus[Unit].SwNormalQueueIndex--;
    }
    else
    {
        Adc_UnitStatus[Unit].SwNormalQueueIndex = 0U;
    }
    SchM_Exit_Adc_SwNormalQueueUpdate();
}
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

/**
 * @brief     This function checks conversion results
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Adc Logical Unit Id
 * @param[in] Group:  The group to be converted
 *
 * @return    None
 */
LOCAL_INLINE Std_ReturnType Adc_CheckConversionResult(uint32 CoreId, Adc_HwUnitType Unit,
                                                      Adc_GroupType Group)
{

    Std_ReturnType             Ret = (Std_ReturnType)E_OK;
    const Adc_GroupConfigType *GroupCfgPtr = &(Adc_ConfigPtr[CoreId]->GroupConfigList[Group]);
    Adc_StreamNumSampleType    SampleNum;
    Adc_ValueGroupType        *ResultsBufferPtr = GroupCfgPtr->ResultsBufferPtr[Group];
    Adc_ValueGroupType        *DataPtr;
    uint16                     ConvResult;
    uint16                     ConvResultRaw;
    uint8                      Index;
    Adc_Drv_ResolutionType     Resolution =
        Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->Resolution;
    uint8 BitShiftNum = Adc_GetBitShiftNums(Resolution);
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    Adc_ChannelType Channel;
    boolean         ResultInRange = (boolean)FALSE;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

    DataPtr = &(ResultsBufferPtr[Adc_GroupStatus[Group].ResultIndex]);
    SampleNum = GroupCfgPtr->NumSamples;

    for (Index = 0; Index < GroupCfgPtr->AssignedChannelCount; Index++)
    {
        ConvResultRaw = Adc_Drv_GetConvData(Unit);
        ConvResult = ConvResultRaw << (BitShiftNum);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        if (TRUE == GroupCfgPtr->GroupLimitcheck)
        {
            Channel = (Adc_ChannelType)GroupCfgPtr->AssignedChannelList[Index];
            ResultInRange = Adc_CheckConversionValuesInRange(CoreId, Unit, Channel, ConvResultRaw);
            if (TRUE == ResultInRange)
            {
                DataPtr[(Index * SampleNum)] = ConvResult;
            }
            else
            {
                Ret = E_NOT_OK;
                break;
            }
        }
        else
        {
            DataPtr[(Index * SampleNum)] = ConvResult;
        }
#else
        DataPtr[(Index * SampleNum)] = ConvResult;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        Adc_GroupStatus[Group].LimitCheckFailed = FALSE;
    }
    else
    {
        Adc_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
        Adc_GroupStatus[Group].LimitCheckFailed = TRUE;
    }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

    return Ret;
}

/**
 * @brief     This function triggers a new conversion.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Adc Logical Unit Id
 * @param[in] Group:  The group to be converted
 *
 * @return    None
 *
 */
LOCAL_INLINE void Adc_SwTriggerConversion(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group)
{
#if (ADC_DMA_USED == STD_ON)
    const Adc_GroupConfigType *GroupCfgPtr;
    uint16                     ResultIndex;
    uint32                     DmaDestAddr;
    uint8                      DmaChannel;
    uint8                      TransferMode =
        Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->TransferMode;
#endif /* (ADC_DMA_USED == STD_ON) */

#if (ADC_DMA_USED == STD_ON)
    if ((uint8)ADC_DRV_DMA == TransferMode)
    {
        /* Dma need to be re-init for next result index */
        ResultIndex = Adc_GroupStatus[Group].ResultIndex;
        GroupCfgPtr = &(Adc_ConfigPtr[CoreId]->GroupConfigList[Group]);
        DmaDestAddr = (uint32)(&(GroupCfgPtr->ResultsBufferPtr[Group][ResultIndex]));
        DmaChannel = Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->DmaChannel;
        /* Update DMA configuration for new samples */
        Dma_Drv_SetDestAddr((Dma_Drv_ChannelType)DmaChannel, DmaDestAddr);
        Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)DmaChannel);
    }
#else
    (void)CoreId;
    (void)Group;
#endif /* (ADC_DMA_USED == STD_ON) */

    Tdg_Adc_Drv_SwTrigger(Unit);
}

#if (ADC_DMA_USED == STD_ON)
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief     This function checks the conversion result when Limit Check and DMA are enabled.
 * @details   This function checks the conversion result when Limit Check and DMA are enabled.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Adc Logical Unit Id
 * @param[in] Group:  The group to be converted
 *
 * @return    Std_ReturnType
 *
 */
LOCAL_INLINE Std_ReturnType Adc_CheckDmaConversionResult(uint32 CoreId, Adc_HwUnitType Unit,
                                                         Adc_GroupType Group)
{
    Std_ReturnType             Ret = (Std_ReturnType)E_OK;
    const Adc_GroupConfigType *GroupCfgPtr = &(Adc_ConfigPtr[CoreId]->GroupConfigList[Group]);
    uint16                     ResultIndex = Adc_GroupStatus[Group].ResultIndex;
    Adc_ValueGroupType        *DataPtr = &(GroupCfgPtr->ResultsBufferPtr[Group][ResultIndex]);
    Adc_ChannelType            Channel = (Adc_ChannelType)(GroupCfgPtr->AssignedChannelList[0]);

    if ((TRUE == GroupCfgPtr->GroupLimitcheck))
    {
        if (FALSE == Adc_CheckConversionValuesInRange(CoreId, Unit, Channel,
                                                      (DataPtr[0] & ADC_CONV_RESULT_MASK)))
        {
            Adc_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
            Adc_GroupStatus[Group].LimitCheckFailed = TRUE;
            DataPtr[0] = 0U;
            Ret = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Adc_GroupStatus[Group].LimitCheckFailed = FALSE;
        }
    }

    return Ret;
}
    #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif     /* (ADC_DMA_USED == STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief     This function handles the case where conversion check fails
 * @details   This function stop all ongoing conversions, clears channel
 *            configurations and conversion complete flag if the one shot
 *            mode is selected, but reconfigures hardware if continuous mode
 *            is selected for the group.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:        Adc Logical Unit Id
 * @param[in] Group:       Selected group Id
 *
 * @return    None
 */
LOCAL_INLINE void Adc_HandleLimitCheckFail(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group)
{
    if (ADC_CONV_MODE_CONTINUOUS == Adc_ConfigPtr[CoreId]->GroupConfigList[Group].ConvMode)
    {
        Adc_SwTriggerConversion(CoreId, Unit, Group);
    }
    else
    {
        (void)Tdg_Adc_Drv_StopConversion(Unit);
        (void)Adc_Drv_StopConversion(Unit);
    }
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
 * @brief     This function updates state of software conversion according to AutoSar diagrams
 *
 * @param[in] CoreId:       Current CoreID
 * @param[in] Unit:         Hardware Unit
 * @param[in] Group:        Group Id
 *
 * @return    None
 */
LOCAL_INLINE void Adc_UpdateSwGroupState(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group)
{
    const Adc_GroupConfigType *GroupCfgPtr =
        &(Adc_ConfigPtr[CoreId]->GroupConfigList[Group]); /* Pointer to AdcGroup */
    uint32 CurrentSampleCount = Adc_GroupStatus[Group].ResultIndex;
#if ((ADC_ENABLE_QUEUING == STD_ON) && (ADC_ENABLE_START_STOP_GROUP_API == STD_ON))
    Adc_GroupType NewGroup;
#endif
    Adc_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    /* Change when configuration is ADC streaming access mode */
    if (ADC_BUSY == Adc_GroupStatus[Group].ConvStatus)
    {
        Adc_GroupStatus[Group].ConvStatus = ADC_COMPLETED;
    }

    if (CurrentSampleCount >= GroupCfgPtr->NumSamples)
    {
        /* Change to stream complete according to AutoSar diagram */
        Adc_GroupStatus[Group].ConvStatus = ADC_STREAM_COMPLETED;

        if (((ADC_STREAM_BUFFER_LINEAR == GroupCfgPtr->BufferMode) &&
             (ADC_ACCESS_MODE_STREAMING == GroupCfgPtr->AccessMode)) ||
            (ADC_CONV_MODE_ONESHOT == GroupCfgPtr->ConvMode))
        {
            /* Update queue and execute new start conversion request from queue if available */
#if (ADC_ENABLE_QUEUING == STD_ON)
            /* Remove current request element in queue */
            Adc_RemoveFromQueue(Unit, 0U);
    #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
            if (Adc_UnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
            {
                NewGroup = Adc_UnitStatus[Unit].SwNormalQueue[0U];

                Adc_InternalStartConversion(CoreId, Unit, NewGroup);
            }
    #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#else
            Adc_UnitStatus[Unit].SwNormalQueueIndex = (Adc_QueueIndexType)0;
#endif /* ADC_ENABLE_QUEUING == STD_ON */
        }
        else
        {
            /* Restart new continuous conversion for single mode or circular buffer streaming */
            Adc_GroupStatus[Group].ResultIndex = 0U;
            Adc_SwTriggerConversion(CoreId, Unit, Group);
        }
    }
    else
    {
        /* Need to restart conversion until buffer is full */
        Adc_SwTriggerConversion(CoreId, Unit, Group);
    }

#if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
    /* Implement user notification function if available */
    Adc_CallNotification(CoreId, Group);
#endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */
}

/**
 * @brief     This function handles conversion ending routines when DMA transfer is selected.
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit
 * @param[in] Group:  Group Id
 *
 * @return    None
 */
LOCAL_INLINE void Adc_ProcessSwConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                             Adc_GroupType Group)
{
    /* Limit checking */
    if ((Std_ReturnType)E_OK == Adc_CheckConversionResult(CoreId, Unit, Group))
    {
        Adc_GroupStatus[Group].ResultIndex++;

        /* Update state following AutoSar diagrams */
        Adc_UpdateSwGroupState(CoreId, Unit, Group);
    }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    else
    {
        Adc_HandleLimitCheckFail(CoreId, Unit, Group);
    }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}

#if (ADC_DMA_USED == STD_ON)
/**
 * @brief     This function handles conversion ending routines
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Adc Logical Unit Id
 * @param[in] Group:  Selected group Id
 *
 * @return    None
 */
LOCAL_INLINE void Adc_ProcessSwDmaConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                                Adc_GroupType Group)
{
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_CheckDmaConversionResult(CoreId, Unit, Group))
    #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    {
        Adc_GroupStatus[Group].ResultIndex++;
        Adc_UpdateSwGroupState(CoreId, Unit, Group);
    }
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    else
    {
        Adc_HandleLimitCheckFail(CoreId, Unit, Group);
    }
    #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif /* (ADC_DMA_USED == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief     This function updates state of hardware conversion according to AutoSar diagrams
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit
 * @param[in] Group:  Group Id
 *
 * @return    None
 */
LOCAL_INLINE void Adc_UpdateHwGroupState(uint32 CoreId, Adc_HwUnitType Unit, Adc_GroupType Group)
{
    const Adc_GroupConfigType *GroupCfgPtr =
        &(Adc_ConfigPtr[CoreId]->GroupConfigList[Group]); /* Pointer to AdcGroup */
    uint32 CurrentSampleCount;
    #if (ADC_DMA_USED == STD_ON)
    uint8 TransferMode =
        Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->TransferMode;
    uint32 DmaDestAddr;
    uint8  DmaChannel;
    uint16 ResultIndex;
    #endif /* (ADC_DMA_USED == STD_ON) */

    Adc_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    if (ADC_BUSY == Adc_GroupStatus[Group].ConvStatus)
    {
        Adc_GroupStatus[Group].ConvStatus = ADC_COMPLETED;
    }

    CurrentSampleCount = Adc_GroupStatus[Group].ResultIndex;

    if (CurrentSampleCount >= GroupCfgPtr->NumSamples)
    {
        Adc_GroupStatus[Group].ConvStatus = ADC_STREAM_COMPLETED;

        if ((ADC_STREAM_BUFFER_LINEAR == GroupCfgPtr->BufferMode) &&
            (ADC_ACCESS_MODE_STREAMING == GroupCfgPtr->AccessMode))
        {
            Adc_Drv_DisableCompInterrupt(Unit);
    #if (ADC_DMA_USED == STD_ON)
            if ((uint8)ADC_DRV_DMA == TransferMode)
            {
                Adc_Drv_DisableDma(Unit);
            }
    #endif /* (ADC_DMA_USED == STD_ON) */
        }
        else
        {
            Adc_GroupStatus[Group].ResultIndex = 0U;
    #if (ADC_DMA_USED == STD_ON)
            /* ADC_ACCESS_MODE_STREAMING && ADC_STREAM_BUFFER_CIRCULAR */
            if ((ADC_STREAM_BUFFER_CIRCULAR == GroupCfgPtr->BufferMode) &&
                (ADC_ACCESS_MODE_STREAMING == GroupCfgPtr->AccessMode))
            {
                if ((uint8)ADC_DRV_DMA == TransferMode)
                {
                    ResultIndex = Adc_GroupStatus[Group].ResultIndex;
                    DmaDestAddr = (uint32)(&(GroupCfgPtr->ResultsBufferPtr[Group][ResultIndex]));
                    DmaChannel =
                        Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->DmaChannel;
                    Dma_Drv_SetDestAddr((Dma_Drv_ChannelType)DmaChannel, DmaDestAddr);
                    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)DmaChannel);
                }
            }
    #endif /* (ADC_DMA_USED == STD_ON) */
        }
    }
    else
    {
    #if (ADC_DMA_USED == STD_ON)
        if ((uint8)ADC_DRV_DMA == TransferMode)
        {
            ResultIndex = Adc_GroupStatus[Group].ResultIndex;
            DmaDestAddr = (uint32)(&(GroupCfgPtr->ResultsBufferPtr[Group][ResultIndex]));
            DmaChannel = Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->DmaChannel;
            Dma_Drv_SetDestAddr((Dma_Drv_ChannelType)DmaChannel, DmaDestAddr);
            Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)DmaChannel);
        }
    #endif /* (ADC_DMA_USED == STD_ON) */
    }

    #if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
    Adc_CallNotification(CoreId, Group);
    #endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */
}

/**
 * @brief     This function handles conversion ending routines
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit
 * @param[in] Group:  Group Id
 *
 * @return    None
 */
LOCAL_INLINE void Adc_ProcessHwConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                             Adc_GroupType Group)
{
    /* Limit checking */
    if ((Std_ReturnType)E_OK == Adc_CheckConversionResult(CoreId, Unit, Group))
    {
        Adc_GroupStatus[Group].ResultIndex++;

        /* Update state following AutoSar diagrams */
        Adc_UpdateHwGroupState(CoreId, Unit, Group);
    }
}

    #if (ADC_DMA_USED == STD_ON)
/**
 * @brief     This function handles conversion ending routines
 *
 * @param[in] CoreId: Current CoreID
 * @param[in] Unit:   Hardware Unit
 * @param[in] Group:  Group Id
 *
 * @return    None
 */
LOCAL_INLINE void Adc_ProcessHwDmaConversionEnd(uint32 CoreId, Adc_HwUnitType Unit,
                                                Adc_GroupType Group)
{
        #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_CheckDmaConversionResult(CoreId, Unit, Group))
        #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    {
        Adc_GroupStatus[Group].ResultIndex++;

        /* Update state following AutoSar diagrams */
        Adc_UpdateHwGroupState(CoreId, Unit, Group);
    }
}
    #endif /* (ADC_DMA_USED == STD_ON) */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/**
 * @brief     This function processes conversion end handling.
 *
 * @param[in] HWUnit:   Adc hardware unit Id
 *
 * @return    None
 */
void Adc_ProcessConversionEndInterrupt(const uint8 HWUnit)
{
    const volatile uint32 CoreId = Adc_GetCoreID();
    Adc_GroupType         SwGroupId = Adc_UnitStatus[HWUnit].SwNormalQueue[0U];
#if (ADC_HW_TRIGGER_API == STD_ON)
    Adc_GroupType HwGroupId = Adc_UnitStatus[HWUnit].OngoingHwGroup;

    /* Check if requests are available in queue */
    if (ADC_INVALID_HW_GROUP_ID != HwGroupId)
    {
        if (ADC_IDLE != Adc_GroupStatus[HwGroupId].ConvStatus)
        {
            Adc_ProcessHwConversionEnd(CoreId, HWUnit, HwGroupId);
        }
    }
    else
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    {
        if (Adc_UnitStatus[HWUnit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
        {
            Adc_ProcessSwConversionEnd(CoreId, HWUnit, SwGroupId);
        }
    }
}

#if (ADC_DMA_USED == STD_ON)
/**
 * @brief     This function processes conversion end handling for DMA used.
 *
 * @param[in] HWUnit:   Adc hardware unit Id
 *
 * @return    None
 */
void Adc_ProcessDmaConversionEndInterrupt(const uint8 HWUnit)
{
    const volatile uint32 CoreId = Adc_GetCoreID();
    Adc_GroupType         SwGroupId = Adc_UnitStatus[HWUnit].SwNormalQueue[0U];
    #if (ADC_HW_TRIGGER_API == STD_ON)
    Adc_GroupType HwGroupId = Adc_UnitStatus[HWUnit].OngoingHwGroup;

    /* Check if requests are available in queue */
    if (ADC_INVALID_HW_GROUP_ID != HwGroupId)
    {
        if (ADC_IDLE != Adc_GroupStatus[HwGroupId].ConvStatus)
        {
            Adc_ProcessHwDmaConversionEnd(CoreId, HWUnit, HwGroupId);
        }
    }
    else
    #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    {
        if (Adc_UnitStatus[HWUnit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
        {
            Adc_ProcessSwDmaConversionEnd(CoreId, HWUnit, SwGroupId);
        }
    }
}
#endif /* (ADC_DMA_USED == STD_ON) */

/**
 * @brief     Initializes the ADC hardware units and driver..
 * @details   This function initializes the ADC hardware units and driver.
 *            - Service ID: 0x00
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] ConfigPtr   Pointer to configuration set in Variant PB (Variant PC requires a
 * NULL_PTR).
 * @return    None
 */
/* SWS_Adc_00365, SWS_Adc_00246, SWS_Adc_00056, SWS_Adc_00054 */
void Adc_Init(const Adc_ConfigType *ConfigPtr)
{
    uint32         CoreId;
    Adc_HwUnitType Unit;
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    CoreId = (uint32)Adc_GetCoreID();

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckInit(CoreId, ConfigPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
        (void)ConfigPtr;
        Adc_ConfigPtr[CoreId] = Adc_PreDefinedConfigPtr[CoreId];
#else
    Adc_ConfigPtr[CoreId] = ConfigPtr;
#endif /* (ADC_PRECOMPILE_SUPPORT == STD_ON) */
        Adc_InitUnitStatus(CoreId);
        Adc_InitGroupsStatus(CoreId);
        for (Unit = 0U; Unit < ADC_MAX_HWUNITS; Unit++)
        {
            if (NULL_PTR != Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr)
            {
                Adc_Drv_Init(
                    Unit,
                    Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->AdcDrvConfigPtr);
                Tdg_Adc_Drv_Init(
                    Unit,
                    Adc_ConfigPtr[CoreId]->HWUnitConfigList[Unit].HWUnitConfigPtr->TdgDrvConfigPtr);
            }
        }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Adc_GlobalState[CoreId] = ADC_STATE_IDLE;
    }
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief     Initializes the group specific ADC result buffer pointer
 * @details   Initializes ADC driver with the group specific result buffer
 *            start address where the conversion results will be stored.
 *            The application has to ensure that the application buffer,
 *            where pDataBufferPtr points to, can hold all the conversion
 *            results of the specified group. The initialization with
 *            Adc_SetupResultBuffer is required after reset, before a group
 *            conversion can be started.
 *            - Service ID: 0x0C
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 * @param[in] DataBufferPtr: Pointer to result data buffer
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Result buffer pointer initialized correctly.
 *            E_NOT_OK:       Operation failed or development error occurred.
 */
/* SWS_Adc_00419, SWS_Adc_00420 */
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType *const DataBufferPtr)
{
    uint32                     CoreId;
    Std_ReturnType             Ret = (Std_ReturnType)E_OK;
    const Adc_GroupConfigType *GroupCfgPtr = NULL_PTR;

    CoreId = (uint32)Adc_GetCoreID();
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckSetupResultBuffer(CoreId, Group, DataBufferPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        if (ADC_IDLE != Adc_GroupStatus[Group].ConvStatus)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                         (uint8)ADC_SID_SETUP_RESULT_BUFFER, (uint8)ADC_E_BUSY);
        }
        else
        {
            GroupCfgPtr = &Adc_ConfigPtr[CoreId]->GroupConfigList[Group];
            GroupCfgPtr->ResultsBufferPtr[Group] = DataBufferPtr;
        }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    return Ret;
}

#if (ADC_DEINIT_API == STD_ON)
/**
 * @brief     Returns all ADC HW Units to a state comparable to their power on reset state.
 *            - Service ID: 0x01
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @return    None
 */
/* SWS_Adc_00366, SWS_Adc_00111 */
void Adc_DeInit(void)
{
    uint32         CoreId;
    Adc_HwUnitType Unit;
    Adc_GroupType  GroupIndex;
    Adc_GroupType  GroupId;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    CoreId = (uint32)Adc_GetCoreID();
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckDeInit(CoreId);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Ret = Adc_CheckGroupBusyStatus(CoreId, ADC_SID_DEINIT);
        if ((Std_ReturnType)E_NOT_OK != Ret)
        {
            for (Unit = 0U; Unit < ADC_MAX_HWUNITS; Unit++)
            {
                Adc_Drv_DeInit(Unit);
                Tdg_Adc_Drv_DeInit(Unit);
            }
            for (GroupIndex = 0U; GroupIndex < (Adc_GroupType)Adc_ConfigPtr[CoreId]->GroupCount;
                 GroupIndex++)
            {
                GroupId = Adc_ConfigPtr[CoreId]->GroupConfigList[GroupIndex].GroupId;
                Adc_ConfigPtr[CoreId]->GroupConfigList[GroupIndex].ResultsBufferPtr[GroupId] =
                    NULL_PTR;
    #if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
                Adc_GroupStatus[GroupId].Notification = ADC_NOTIFICATION_DISABLED;
    #endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */
            }
            Adc_ConfigPtr[CoreId] = NULL_PTR;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
            Adc_GlobalState[CoreId] = ADC_STATE_UNINIT;
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
 * @brief     Starts the conversion of all channels of the requested ADC Channel group.
 *            - Service ID: 0x02
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
/* SWS_Adc_00367, SWS_Adc_00356, SWS_Adc_00156, SWS_Adc_00061, SWS_Adc_00413 */
void Adc_StartGroupConversion(Adc_GroupType Group)
{
    volatile uint32 CoreId;
    Adc_HwUnitType  Unit = 0U;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    CoreId = (uint32)Adc_GetCoreID();
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckStartGroupConversion(CoreId, Group);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Unit = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].HwUnitId;
        if ((Std_ReturnType)E_NOT_OK != Adc_CheckStartGroupConvNotBusy(CoreId, Unit, Group))
        {
            Adc_UpdateStartConversionStatus(CoreId, Unit, Group);
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief     Stops the conversion of requested ADC Channel group.
 *            - Service ID: 0x03
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
/* SWS_Adc_00368, SWS_Adc_00356, SWS_Adc_00413 */
void Adc_StopGroupConversion(Adc_GroupType Group)
{
    Adc_HwUnitType  Unit = 0U;
    volatile uint32 CoreId;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    CoreId = (uint32)Adc_GetCoreID();
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckStopGroupConversion(CoreId, Group);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

        if (ADC_IDLE == Adc_GroupStatus[Group].ConvStatus)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                         (uint8)ADC_SID_STOP_GROUP_CONVERSION, (uint8)ADC_E_IDLE);
        }
        else
        {
            Unit = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].HwUnitId;
            Adc_UpdateStopConversionStatus(CoreId, Unit, Group);
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
/**
 * @brief     Reads the group conversion results.
 * @details   Reads the group conversion results of the last completed
 *            conversion round of the requested group and stores the
 *            channel values starting at the DataBufferPtr address.
 *            The group channel values are stored in ascending channel
 *            number order (in contrast to the storage layout of the
 *            result buffer if streaming access is configured).
 *            - Service ID: 0x04
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 * @param[in] DataBufferPtr:  ADC results of all channels of the selected group
 *                             are stored in the data buffer addressed with the pointer.
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK: results are available and written to the data buffer.
 *            E_NOT_OK: no results are available or development error occurred.
 */
/* SWS_Adc_00369, SWS_Adc_00383, SWS_Adc_00503, SWS_Adc_00447 */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr)
{
    volatile uint32 CoreId;
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;
    Adc_HwUnitType  Unit;

    CoreId = (uint32)Adc_GetCoreID();
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckReadGroup(CoreId, Group, DataBufferPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

        if ((ADC_IDLE == Adc_GroupStatus[Group].ConvStatus) &&
            (ADC_NOT_YET_CONVERTED == Adc_GroupStatus[Group].AlreadyConverted))
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                         (uint8)ADC_SID_READ_GROUP, (uint8)ADC_E_IDLE);
        }
        else
        {
            Unit = (Adc_ConfigPtr[CoreId]->GroupConfigList[Group]).HwUnitId;

            Ret = Adc_ReadGroupInterrupt(CoreId, Unit, Group, DataBufferPtr);
            if ((Std_ReturnType)E_OK == Ret)
            {
                Adc_UpdateReadGroupInterruptStatus(CoreId, Group);
            }
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    return Ret;
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief     Enables the hardware trigger for the requested ADC Channel group.
 *            - Service ID: 0x05
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
/* SWS_Adc_00370, SWS_Adc_00114, SWS_Adc_00114, SWS_Adc_00413 */
void Adc_EnableHardwareTrigger(Adc_GroupType Group)
{
    uint32         CoreId;
    Adc_HwUnitType Unit = 0U;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    CoreId = (uint32)Adc_GetCoreID();
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckEnableHardwareTrigger(CoreId, Group);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Unit = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].HwUnitId;

        Ret = Adc_CheckHWUnitBusy(Unit, ADC_SID_ENABLE_HARDWARE_TRIGGER);

        if ((Std_ReturnType)E_NOT_OK != Ret)
        {
            /* Update status before enable hardware trigger */
            Adc_UnitStatus[Unit].OngoingHwGroup = Group;
            Adc_GroupStatus[Group].ConvStatus = ADC_BUSY;
            Adc_GroupStatus[Group].HwTriggering = ADC_HWTRIGGER_ENABLED;
            Adc_GroupStatus[Group].ResultIndex = 0U;

            Adc_InternalStartConversion(CoreId, Unit, Group);
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief     Disables the hardware trigger for the requested ADC Channel group.
 *            - Service ID: 0x06
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
/* SWS_Adc_00371, SWS_Adc_00413, SWS_Adc_00145 */
void Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
    volatile uint32 CoreId;
    Adc_HwUnitType  Unit = 0U;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    #endif

    CoreId = (uint32)Adc_GetCoreID();
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckDisableHardwareTrigger(CoreId, Group);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        if (ADC_HWTRIGGER_DISABLED == Adc_GroupStatus[Group].HwTriggering)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                         (uint8)ADC_SID_DISABLE_HARDWARE_TRIGGER,
                                         (uint8)ADC_E_IDLE);
        }
        else
        {
            Unit = Adc_ConfigPtr[CoreId]->GroupConfigList[Group].HwUnitId;

            /* Update status before disable hardware trigger */
    #if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
            Adc_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
    #endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */
            Adc_GroupStatus[Group].ConvStatus = ADC_IDLE;
            Adc_GroupStatus[Group].HwTriggering = ADC_HWTRIGGER_DISABLED;
            Adc_UnitStatus[Unit].OngoingHwGroup = ADC_INVALID_HW_GROUP_ID;

            (void)Tdg_Adc_Drv_StopConversion(Unit);
            (void)Adc_Drv_StopConversion(Unit);
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
/**
 * @brief     Enables the notification mechanism for the requested ADC Channel group.
 *            - Service ID: 0x07
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
/* SWS_Adc_00372, SWS_Adc_00413, SWS_Adc_00057 */
void Adc_EnableGroupNotification(Adc_GroupType Group)
{
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;
    volatile uint32 CoreId;
    CoreId = (uint32)Adc_GetCoreID();
    Ret = Adc_CheckEnableDisableGroupNotification(CoreId, Group, ADC_SID_ENABLE_GROUP_NOTIFICATION);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Adc_GroupStatus[Group].Notification = ADC_NOTIFICATION_ENABLED;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief     Disables the notification mechanism for the requested ADC Channel group.
 *            - Service ID: 0x08
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
/* SWS_Adc_00373, SWS_Adc_00413, SWS_Adc_00416, SWS_Adc_00058 */
void Adc_DisableGroupNotification(Adc_GroupType Group)
{
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;
    volatile uint32 CoreId;

    CoreId = (uint32)Adc_GetCoreID();
    Ret =
        Adc_CheckEnableDisableGroupNotification(CoreId, Group, ADC_SID_DISABLE_GROUP_NOTIFICATION);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Adc_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (ADC_GROUP_NOTIF_CAPABILITY == STD_ON) */

/**
 * @brief     Returns the conversion status of the requested ADC Channel group.
 *            - Service ID: 0x09
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    Adc_StatusType: Conversion status for the requested group.
 */
/* SWS_Adc_00374, SWS_Adc_00140, SWS_Adc_00503, SWS_Adc_00413, SWS_Adc_00220 */
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
{
    Adc_StatusType Status = ADC_IDLE;
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;
    volatile uint32 CoreId;
    CoreId = (uint32)Adc_GetCoreID();
    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_GET_GROUP_STATUS);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Status = Adc_GroupStatus[Group].ConvStatus;
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    return (Status);
}

/**
 * @brief      Returns the number of valid samples per channel.
 * @details    Returns the number of valid samples per channel, stored in the result buffer.
 *             Reads a pointer, pointing to a position in the group result buffer.
 *             With the pointer position, the results of all group channels of
 *             the last completed conversion round can be accessed. With the pointer and
 *             the return value, all valid group conversion results can be accessed
 *             (the user has to take the layout of the result buffer into account).
 *             - Service ID: 0x0B
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 * @param[out] PtrToSamplePtr: Pointer to result buffer pointer.
 *
 * @return     Adc_StreamNumSampleType Number of valid samples per channel.
 * @retval     =0: in case of errors.
 * @retval     >0: Number of valid samples per channel.
 */
/* SWS_Adc_00375, SWS_Adc_00382, SWS_Adc_00387, SWS_Adc_00215, SWS_Adc_00302, SWS_Adc_00218 */
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType        Group,
                                                 Adc_ValueGroupType **PtrToSamplePtr)
{
    volatile uint32            CoreId = (uint32)Adc_GetCoreID();
    const Adc_GroupConfigType *GroupCfgPtr;
    /* Number of samples to return */
    Adc_StreamNumSampleType NumberOfResults = 0U;
    Adc_StreamNumSampleType ResultIndex = 0U;
    Adc_StatusType          ConvStatus;
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    *PtrToSamplePtr = NULL_PTR;
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckCalledGroup(CoreId, Group, ADC_SID_GET_GROUP_STATUS);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        GroupCfgPtr = &(Adc_ConfigPtr[CoreId]->GroupConfigList[Group]);
        ConvStatus = Adc_GroupStatus[Group].ConvStatus;

        if (ADC_IDLE == ConvStatus)
        {
            (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                         (uint8)ADC_SID_GET_STREAM_LAST_POINTER, (uint8)ADC_E_IDLE);
        }
        else
        {
            if (ADC_BUSY != ConvStatus)
            {
                if ((Adc_StreamNumSampleType)0U == Adc_GroupStatus[Group].ResultIndex)
                {
                    ResultIndex = GroupCfgPtr->NumSamples - (Adc_StreamNumSampleType)1U;
                    NumberOfResults = GroupCfgPtr->NumSamples;
                }
                else
                {
                    ResultIndex = Adc_GroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1U;
                    NumberOfResults = Adc_GroupStatus[Group].ResultIndex;
                }

                *PtrToSamplePtr =
                    (Adc_ValueGroupType *)(&(GroupCfgPtr->ResultsBufferPtr[Group][ResultIndex]));
                Adc_UpdateAfterGetStreamStatus(CoreId, Group);
            }
        }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    return (NumberOfResults);
}

#if (ADC_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *            - Service ID: 0x0A
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] versionInfo: Pointer to where to store the version information of this module.
 *
 * @return    None
 */
/* SWS_Adc_00376 */
void Adc_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, ADC_SID_GET_VERSION_INFO,
                              ADC_E_PARAM_POINTER);
    }
    else
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        (versioninfo)->vendorID = (uint16)ADC_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)ADC_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)ADC_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)ADC_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)ADC_SW_PATCH_VERSION;

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (ADC_VERSION_INFO_API == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
/**
 * @brief     This function calibrates the ADC HW unit and updates calibration related registers.
 *            - Service ID: 0x60
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Unit: Hardware Unit. Range: 0..1
 *
 * @return     Std_ReturnType: Calibration result.
 * @retval     E_OK: Successfully.
 * @retval     E_NOT_OK: Failed.
 */
Std_ReturnType Adc_Calibrate(Adc_HwUnitType Unit)
{
    volatile uint32 CoreId;
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;

    CoreId = (uint32)Adc_GetCoreID();
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckCalibrate(CoreId, Unit);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Ret = Adc_CheckHWUnitBusy(Unit, ADC_SID_CALIBRATE);
        if ((Std_ReturnType)E_NOT_OK != Ret)
        {
            Ret = Adc_CheckGroupBusyStatus(CoreId, ADC_SID_CALIBRATE);
            if ((Std_ReturnType)E_NOT_OK != Ret)
            {
                Ret = Adc_Drv_Calibrate(Unit);
                if ((Std_ReturnType)E_OK != Ret)
                {
                    (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                                 (uint8)ADC_SID_CALIBRATE, (uint8)ADC_E_TIMEOUT);
                }
            }
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    return Ret;
}
#endif /* ADC_CALIBRATION == STD_ON */

/**
 * @brief     This function performs self test of ADC.
 *            - Service ID: 0x61
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Unit: Hardware Unit. Range: 0..1
 *
 * @return     Std_ReturnType: Self test result.
 * @retval     E_OK: Successfully.
 * @retval     E_NOT_OK: Failed.
 */
Std_ReturnType Adc_SelfTest(Adc_HwUnitType Unit)
{
    volatile uint32 CoreId;
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;

    CoreId = (uint32)Adc_GetCoreID();
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_CheckSelfTest(CoreId, Unit);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        Ret = Adc_CheckHWUnitBusy(Unit, ADC_SID_SELF_TEST);
        if ((Std_ReturnType)E_NOT_OK != Ret)
        {
            Ret = Adc_CheckGroupBusyStatus(CoreId, ADC_SID_SELF_TEST);
            if ((Std_ReturnType)E_NOT_OK != Ret)
            {
                Ret = Adc_Drv_SelfTest(Unit);
                if ((Std_ReturnType)E_OK != Ret)
                {
                    (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U,
                                                 (uint8)ADC_SID_SELF_TEST, (uint8)ADC_E_TIMEOUT);
                }
            }
        }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    return Ret;
}

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
 * @brief      Enters the already prepared power state.
 *
 * @details    This API configures the Adc module so that it enters the already prepared power
 *             state, chosen between a predefined set of configured ones.
 *             - Service ID: 0x10
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Result: Pointer to a variable to store the result of this function.
 *
 * @return     Std_ReturnType: Standard return type.
 * @retval     E_OK:           Power Mode changed.
 * @retval     E_NOT_OK:       Request rejected.
 */
/* SWS_Adc_00475, SWS_Adc_00481 */
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    return Ret;
}

/**
 * @brief      Get the current power state of the ADC HW unit.
 *
 * @details    This API returns the current power state of the ADC HW unit.
 *             - Service ID: 0x11
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[out] CurrentPowerState: The current power mode of the ADC HW Unit is returned in this
 *             parameter
 * @param[out] Result: Pointer to a variable to store the result of this function
 *
 * @return     Std_ReturnType  Standard return type.
 * @retval     E_OK:           Mode could be read.
 * @retval     E_NOT_OK:       Service is rejected.
 */
/* SWS_Adc_00476 */
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType              *CurrentPowerState,
                                        Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    return Ret;
}

/**
 * @brief      Get the target power state of the ADC HW unit.
 *
 * @details    This API returns the target power state of the ADC HW unit.
 *             - Service ID: 0x12
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[out] TargetPowerState: The Target power mode of the ADC HW Unit is returned in this
 *             parameter.
 * @param[out] Result: Pointer to a variable to store the result of this function.
 *
 * @return     Std_ReturnType  Standard return type.
 * @retval     E_OK:           Mode could be read.
 * @retval     E_NOT_OK:       Service is rejected.
 */
/* SWS_Adc_00477 */
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType              *TargetPowerState,
                                       Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    return Ret;
}

/**
 * @brief      Starts the needed process to allow the ADC HW module to enter the requested power
 *             state.
 *
 * @details    This API starts the needed process to allow the ADC HW module to enter the requested
 *             power state.
 *             - Service ID: 0x13
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  PowerState      The target power state intended to be attained.
 * @param[out] Result          Pointer to a variable to store the result of this function.
 *
 * @return     Std_ReturnType  Standard return type.
 * @retval     E_OK:           Mode could be read.
 * @retval     E_NOT_OK:       Service is rejected.
 */
/* SWS_Adc_00478 */
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType               PowerState,
                                     Adc_PowerStateRequestResultType *Result)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    return Ret;
}
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc */

/** @} end of group Adc_Module */
