/**************************************************************************************************/
/**
 * @file      : Icu_Drvw.c
 * @brief     : AUTOSAR Icu drvw driver source file
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

/** @addtogroup  Icu_Drvw
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Icu_Drvw.h"
#include "Tim_Icu_Drv.h"
#include "Cmp_Icu_Drv.h"
#include "Port_Icu_Drv.h"

#if ((ICU_DRVW_TIMESTAMP_DMA_USE == STD_ON) || (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE))
    #include "Dma_Drv.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ICU_DRVW_C_VENDOR_ID                   0x00B3U
#define ICU_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define ICU_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define ICU_DRVW_C_SW_MAJOR_VERSION            1U
#define ICU_DRVW_C_SW_MINOR_VERSION            2U
#define ICU_DRVW_C_SW_PATCH_VERSION            1U

#if (ICU_DRVW_C_VENDOR_ID != ICU_DRVW_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw.c and Icu_Drvw.h have different"
#endif
                    
#if ((ICU_DRVW_C_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_C_AR_RELEASE_MINOR_VERSION != ICU_DRVW_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw.c and Icu_Drvw.h are different"
#endif

#if ((ICU_DRVW_C_AR_RELEASE_REVISION_VERSION != ICU_DRVW_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_DRVW_C_SW_PATCH_VERSION != ICU_DRVW_H_SW_PATCH_VERSION))
    #error "AutoSar version of Icu_Drvw.c and Icu_Drvw.h are different"
#endif        
                    
#if ((ICU_DRVW_C_SW_MAJOR_VERSION != ICU_DRVW_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_C_SW_MINOR_VERSION != ICU_DRVW_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw.c and Icu_Drvw.h are different"
#endif

#if (ICU_DRVW_C_VENDOR_ID != TIM_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw.c and Tim_Icu_Drv.h have different"
#endif
                    
#if ((ICU_DRVW_C_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_C_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw.c and Tim_Icu_Drv.h are different"
#endif
                    
#if ((ICU_DRVW_C_SW_MAJOR_VERSION != TIM_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_C_SW_MINOR_VERSION != TIM_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw.c and Tim_Icu_Drv.h are different"
#endif

#if (ICU_DRVW_C_VENDOR_ID != CMP_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw.c and Cmp_Icu_Drv.h have different"
#endif
                    
#if ((ICU_DRVW_C_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_C_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw.c and Cmp_Icu_Drv.h are different"
#endif
                    
#if ((ICU_DRVW_C_SW_MAJOR_VERSION != CMP_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_C_SW_MINOR_VERSION != CMP_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw.c and Cmp_Icu_Drv.h are different"
#endif

#if (ICU_DRVW_C_VENDOR_ID != PORT_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw.c and Port_Icu_Drv.h have different"
#endif
                    
#if ((ICU_DRVW_C_AR_RELEASE_MAJOR_VERSION != PORT_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_C_AR_RELEASE_MINOR_VERSION != PORT_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw.c and Port_Icu_Drv.h are different"
#endif
                    
#if ((ICU_DRVW_C_SW_MAJOR_VERSION != PORT_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_C_SW_MINOR_VERSION != PORT_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw.c and Port_Icu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((ICU_DRVW_TIMESTAMP_DMA_USE == STD_ON) || (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE))
        /* Check if Adc_Drvw.h file and Dma_Drv.h are the same Autosar version */
        #if ((ICU_DRVW_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) ||        \
             (ICU_DRVW_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Drvw.c and Dma_Drv.h are different"
        #endif
    #endif /* (ICU_DRVW_TIMESTAMP_DMA_USE == STD_ON) || (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE) */
#endif     /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

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
#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

/**
 * @brief Variable storing the current state of Icu Timestamp DMA config  
 */
#if ((STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE) && (STD_ON == ICU_DRVW_TIMESTAMP_API))
static Dma_Drv_ChannelTransferConfigType Icu_Drvw_TsDmaTransferConfig;
static Dma_Drv_AddrConfigType Icu_Drvw_TsDmaSourceConfig;
static Dma_Drv_AddrConfigType Icu_Drvw_TsDmaDestinationConfig;
static Dma_Drv_TransferControlConfigType Icu_Drvw_TsDmaControlConfig;
static Dma_Drv_ChannelGlobalConfigType   Icu_Drvw_TsDmaChannelGlobalConfig;
static Dma_Drv_RequestConfigType Icu_Drvw_TsDmaRequestConfig;
static Dma_Drv_PriorityConfigType Icu_Drvw_TsDmaPriorityConfig;
#endif

/**
 * @brief Variable storing the current state of Icu Signal Measurement DMA config  
 */
#if ((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE) && (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_API))
static Dma_Drv_ChannelTransferConfigType Icu_Drvw_SigMeasDmaTransferConfig;
static Dma_Drv_AddrConfigType Icu_Drvw_SigMeasDmaSourceConfig;
static Dma_Drv_AddrConfigType Icu_Drvw_SigMeasDmaDestinationConfig;
static Dma_Drv_TransferControlConfigType Icu_Drvw_SigMeasDmaControlConfig;
static Dma_Drv_ChannelGlobalConfigType   Icu_Drvw_SigMeasDmaChannelGlobalConfig;
static Dma_Drv_RequestConfigType Icu_Drvw_SigMeasDmaRequestConfig;
static Dma_Drv_PriorityConfigType Icu_Drvw_SigMeasDmaPriorityConfig;
#endif

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

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Initialize a hardware Icu Instance
 *
 * @param[in]  IcuInstSumNum: Number of instances to be configured
 * @param[in]  IcuHwInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void Icu_Drvw_Init(uint32 IcuInstSumNum, const Icu_Drvw_HwInstanceConfigType (* IcuHwInstCfgPtr)[])
{
    uint32 Loop;

    for(Loop = 0U; Loop < IcuInstSumNum; Loop++)
    {
        if (ICU_DRVW_INSTANCE_TIM == (*IcuHwInstCfgPtr)[Loop].InstModule)
        {
            (void)Tim_Icu_Drv_Init((Tim_Icu_Drv_IdType)((*IcuHwInstCfgPtr)[Loop].InstId), 
                                        (*IcuHwInstCfgPtr)[Loop].InstanceConfig.TimIcuInstCfgPtr);
        }
        else if (ICU_DRVW_INSTANCE_PORT == (*IcuHwInstCfgPtr)[Loop].InstModule)
        {
            (void)Port_Icu_Drv_Init((Port_Icu_Drv_IdType)((*IcuHwInstCfgPtr)[Loop].InstId), 
                            (*IcuHwInstCfgPtr)[Loop].InstanceConfig.PortIcuInstCfgPtr);
        }
        else if (ICU_DRVW_INSTANCE_CMP == (*IcuHwInstCfgPtr)[Loop].InstModule)
        {
            (void)Cmp_Icu_Drv_Init((Cmp_Icu_Drv_IdType)((*IcuHwInstCfgPtr)[Loop].InstId), 
                                        (*IcuHwInstCfgPtr)[Loop].InstanceConfig.CmpIcuInstCfgPtr);
        }
        else
        {
            /*do nothing*/
        }
    }
}

#if (STD_ON == ICU_DRVW_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  IcuInstSumNum: Number of instances to be configured
 * @param[in]  IcuHwInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void Icu_Drvw_DeInit(uint32 IcuInstSumNum, const Icu_Drvw_HwInstanceConfigType (* IcuHwInstCfgPtr)[])
{
    uint32 Loop;

    for(Loop = 0U; Loop < IcuInstSumNum; Loop++)
    {
        if (ICU_DRVW_INSTANCE_TIM == (*IcuHwInstCfgPtr)[Loop].InstModule)
        {
            (void)Tim_Icu_Drv_DeInit((Tim_Icu_Drv_IdType)((*IcuHwInstCfgPtr)[Loop].InstId));
        }
        else if (ICU_DRVW_INSTANCE_PORT == (*IcuHwInstCfgPtr)[Loop].InstModule)
        {
            (void)Port_Icu_Drv_DeInit((Port_Icu_Drv_IdType)((*IcuHwInstCfgPtr)[Loop].InstId));
        }
        else if (ICU_DRVW_INSTANCE_CMP == (*IcuHwInstCfgPtr)[Loop].InstModule)
        {
            (void)Cmp_Icu_Drv_DeInit((Cmp_Icu_Drv_IdType)((*IcuHwInstCfgPtr)[Loop].InstId));
        }
        else
        {
            /*do nothing*/
        }
    }
}
#endif

#if (STD_ON == ICU_DRVW_SET_MODE_API)
/**
 * @brief      Put the Channel in a reduce power state
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_SetSleepMode(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint32 Channel;
    uint8 InstId;
    Icu_Drvw_InstanceType ChModule;

    InstId = DrvwHwChCfgPtr->InstId;
    ChModule = DrvwHwChCfgPtr->ChModule;
    
    switch(ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
            Channel = DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId;
            Tim_Icu_Drv_SetChannelSleepMode((Tim_Icu_Drv_IdType)InstId,
                                             (Tim_Icu_Drv_ChannelIdType)Channel);
            break;
            
        case ICU_DRVW_INSTANCE_PORT:
            Channel = DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId;
            Port_Icu_Drv_SetChannelSleepMode((Port_Icu_Drv_IdType)InstId,
                                             (Port_Icu_Drv_GpioNoType)Channel);
            break;

        case ICU_DRVW_INSTANCE_CMP:
            Cmp_Icu_Drv_SetChannelSleepMode((Cmp_Icu_Drv_IdType)InstId);      
            break;

        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      Put the Channel in normal state
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_SetNormalMode(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint32 Channel;
    uint8 InstId;
    Icu_Drvw_InstanceType ChModule;

    InstId = DrvwHwChCfgPtr->InstId;
    ChModule = DrvwHwChCfgPtr->ChModule;
    
    switch(ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
            Channel = DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId;
            Tim_Icu_Drv_SetChannelNormalMode((Tim_Icu_Drv_IdType)InstId,
                                             (Tim_Icu_Drv_ChannelIdType)Channel);
            break;
            
        case ICU_DRVW_INSTANCE_PORT:
            Channel = DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId;
            Port_Icu_Drv_SetChannelNormalMode((Port_Icu_Drv_IdType)InstId,
                                    (Port_Icu_Drv_GpioNoType)Channel);
            break;

        case ICU_DRVW_INSTANCE_CMP:
            Cmp_Icu_Drv_SetChannelNormalMode((Cmp_Icu_Drv_IdType)InstId);       
            break;

        default:
            /* Do nothing */
            break;
    }
}
#endif

/**
 * @brief      set the type of activation
 *
 * @param[in]  ActiveEdge: the type of activation for the ICU Channel 
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_SetActivationCondition(ICU_DRVW_ACTIVATION_TYPE ActiveEdge, 
                                                const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint32 Channel;
    uint8 InstId;
    Icu_Drvw_InstanceType ChModule;

    InstId = DrvwHwChCfgPtr->InstId;
    ChModule = DrvwHwChCfgPtr->ChModule;

    switch(ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Channel = DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId;
            if (ICU_DRVW_RISING_EDGE == ActiveEdge)
            {
                Tim_Icu_Drv_SetActivationCondition((Tim_Icu_Drv_IdType)InstId, 
                                                (Tim_Icu_Drv_ChannelIdType)Channel, 
                                                 TIM_ICU_DRV_INPUT_RISING_EDGE);
            }
            else if (ICU_DRVW_FALLING_EDGE == ActiveEdge)
            {
                Tim_Icu_Drv_SetActivationCondition((Tim_Icu_Drv_IdType)InstId, 
                                                (Tim_Icu_Drv_ChannelIdType)Channel, 
                                                 TIM_ICU_DRV_INPUT_FALLING_EDGE);
            }
            else if (ICU_DRVW_BOTH_EDGES == ActiveEdge)
            {
                Tim_Icu_Drv_SetActivationCondition((Tim_Icu_Drv_IdType)InstId, 
                                                (Tim_Icu_Drv_ChannelIdType)Channel, 
                                                 TIM_ICU_DRV_INPUT_BOTH_EDGES);
            }
            else
            {
                /*do nothing*/
            }
            
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            Channel = DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId;
            if (ICU_DRVW_RISING_EDGE == ActiveEdge)
            {
                Port_Icu_Drv_SetActivationCondition((Port_Icu_Drv_IdType)InstId, 
                                                (Port_Icu_Drv_GpioNoType)Channel, 
                                                 PORT_ICU_DRV_INPUT_RISING_EDGE);
            }
            else if (ICU_DRVW_FALLING_EDGE == ActiveEdge)
            {
                Port_Icu_Drv_SetActivationCondition((Port_Icu_Drv_IdType)InstId, 
                                                (Port_Icu_Drv_GpioNoType)Channel, 
                                                 PORT_ICU_DRV_INPUT_FALLING_EDGE);
            }
            else if (ICU_DRVW_BOTH_EDGES == ActiveEdge)
            {
                Port_Icu_Drv_SetActivationCondition((Port_Icu_Drv_IdType)InstId, 
                                                (Port_Icu_Drv_GpioNoType)Channel, 
                                                 PORT_ICU_DRV_INPUT_BOTH_EDGES);
            }
            else
            {
                /*do nothing*/
            }
            
            break;
            
        case ICU_DRVW_INSTANCE_CMP:
            if (ICU_DRVW_RISING_EDGE == ActiveEdge)
            {
                Cmp_Icu_Drv_SetActivationCondition((Cmp_Icu_Drv_IdType)InstId,  
                                                 CMP_ICU_DRV_INPUT_RISING_EDGE);
            }
            else if (ICU_DRVW_FALLING_EDGE == ActiveEdge)
            {
                Cmp_Icu_Drv_SetActivationCondition((Cmp_Icu_Drv_IdType)InstId, 
                                                 CMP_ICU_DRV_INPUT_FALLING_EDGE);
            }
            else if (ICU_DRVW_BOTH_EDGES == ActiveEdge)
            {
                Cmp_Icu_Drv_SetActivationCondition((Cmp_Icu_Drv_IdType)InstId,  
                                                 CMP_ICU_DRV_INPUT_BOTH_EDGES);
            }
            else
            {
                /*do nothing*/
            }
            
            break;
        
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      Disable Notification for timestamp
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_DisableNotification(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint32 Channel;
    uint8 InstId;
    Icu_Drvw_InstanceType ChModule;

    InstId = DrvwHwChCfgPtr->InstId;
    ChModule = DrvwHwChCfgPtr->ChModule;

    switch(ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Channel = DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId;
            Tim_Icu_Drv_DisableNotification((Tim_Icu_Drv_IdType)InstId,
                                         (Tim_Icu_Drv_ChannelIdType)Channel);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            Channel = DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId;
            Port_Icu_Drv_DisableNotification((Port_Icu_Drv_IdType)InstId,
                                         (Port_Icu_Drv_GpioNoType)Channel);
            break;
            
        case ICU_DRVW_INSTANCE_CMP:
            Cmp_Icu_Drv_DisableNotification((Cmp_Icu_Drv_IdType)InstId);
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      Enable Notification for timestamp
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_EnableNotification(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint32 Channel;
    uint8 InstId;
    Icu_Drvw_InstanceType ChModule;

    InstId = DrvwHwChCfgPtr->InstId;
    ChModule = DrvwHwChCfgPtr->ChModule;

    switch(ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Channel = DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId;
            Tim_Icu_Drv_EnableNotification((Tim_Icu_Drv_IdType)InstId,
                                         (Tim_Icu_Drv_ChannelIdType)Channel);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            Channel = DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId;
            Port_Icu_Drv_EnableNotification((Port_Icu_Drv_IdType)InstId,
                                         (Port_Icu_Drv_GpioNoType)Channel);
            break;
            
        case ICU_DRVW_INSTANCE_CMP:
            Cmp_Icu_Drv_EnableNotification((Cmp_Icu_Drv_IdType)InstId);        
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

#if (STD_ON == ICU_DRVW_GET_INPUT_STATE_API)
/**
 * @brief      Service that returns the state of input Channel
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return whetner An active edge has been detected
 *
 */
boolean Icu_Drvw_GetInputState(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    boolean RetVal = (boolean)FALSE;

    if (ICU_DRVW_INSTANCE_TIM == DrvwHwChCfgPtr->ChModule)
    {
        RetVal = Tim_Icu_Drv_GetInputState((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)(DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId));
    }
    else if (ICU_DRVW_INSTANCE_PORT == DrvwHwChCfgPtr->ChModule)
    {
        RetVal = Port_Icu_Drv_GetInputState((Port_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
            (Port_Icu_Drv_GpioNoType)(DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId));
    }
    else if (ICU_DRVW_INSTANCE_CMP == DrvwHwChCfgPtr->ChModule)
    {
        RetVal = Cmp_Icu_Drv_GetInputState((Cmp_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId);
    }
    else
    {
        /*do nothing*/
    }
    
    return RetVal;
}
#endif

#if (((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_API) && (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE)) || \
     ((STD_ON == ICU_DRVW_TIMESTAMP_API) && (STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE)))
/**
 * @brief      Service that return the address of capture register
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return address of capture register
 *
 */     
uint32 Icu_Drvw_GetCounterAddr(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint32 RetVal = 0U;

    if (ICU_DRVW_INSTANCE_TIM == DrvwHwChCfgPtr->ChModule)
    {
        RetVal = Tim_Icu_Drv_GetCounterAddr((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId,
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
    }
    else if (ICU_DRVW_INSTANCE_PORT == DrvwHwChCfgPtr->ChModule)
    {
    }
    else if (ICU_DRVW_INSTANCE_CMP == DrvwHwChCfgPtr->ChModule)
    {
        /*do nothing*/
    }
    else
    {
        /*do nothing*/
    }
    
    return RetVal;
}
#endif

#if ((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE))
/**
 * @brief     This function enable channel request of DMA.
 *
 * @param[in] DmaChannel: dma channel id
 *
 * @return    None
 *
 */
void Icu_Drvw_EnableDmaChannelRequest(uint32 DmaChannel)
{
    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)DmaChannel);
}

/**
 * @brief     This function disable channel request of DMA.
 *
 * @param[in] DmaChannel: dma channel id
 *
 * @return    None
 *
 */
void Icu_Drvw_DisableDmaChannelRequest(uint32 DmaChannel)
{
    Dma_Drv_DisableChannelRequest((Dma_Drv_ChannelType)DmaChannel);
}

/**
 * @brief      set dma destination address Function
 *
 * @param[in]  DmaChId: dma channel id
 * @param[in]  Address: dma transfer destination address
 *
 * @return none.
 *
 */
void Icu_Drvw_SetDmaDestAddr(const uint32 DmaChId, uint32 Address)
{
    Dma_Drv_SetDestAddr((Dma_Drv_ChannelType)DmaChId, (uint32)Address);
}

/**
 * @brief      set total number of minor loop in a major loop Function
 *
 * @param[in]  DmaChId: dma channel id
 * @param[in]  Num: number of minor loop in a major loop
 *
 * @return none.
 *
 */
void Icu_Drvw_SetDmaMinorLoopNum(const uint32 DmaChId, uint16 Num)
{
    Dma_Drv_SetMinorLoopNum((Dma_Drv_ChannelType)DmaChId, Num);
}

#endif

/**
 * @brief      This function starts the capturing of timer values on the edges
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  IcuInstSumNum:    number of driver instances configured 
 *
 * @return none
 *
 */
#if ((STD_ON == ICU_DRVW_TIMESTAMP_API) && (STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE))
void Icu_Drvw_TimestampDmaGlobalConfig(const uint32 DmaChId, 
                            const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint32 IcuInstSumNum)
{
    Dma_Drv_ChannelGlobalConfigType   *DmaChlGlobalCfgPtr = &Icu_Drvw_TsDmaChannelGlobalConfig;
    uint32 PhsyChId;

    DmaChlGlobalCfgPtr->RequestConfig = &Icu_Drvw_TsDmaRequestConfig;
    DmaChlGlobalCfgPtr->PriorityConfig = &Icu_Drvw_TsDmaPriorityConfig;
    PhsyChId = DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId;
    DmaChlGlobalCfgPtr->RequestConfig->MuxReqSrc = 
    (Dma_Drv_RequestSourceType)(DMA_DRV_REQ_TIM0_CHANNEL0 + (PhsyChId + (IcuInstSumNum * 8)));
    /* Set request enable */
    DmaChlGlobalCfgPtr->RequestConfig->ReqEn = (boolean)TRUE;
    /* Mask Error interrupt */
    DmaChlGlobalCfgPtr->ErrIntEn = (boolean)FALSE;
    /* DMA channel priority */
    DmaChlGlobalCfgPtr->PriorityConfig->Priority = DMA_DRV_PRIORITY_LEVEL_0;
    /* Disable preemption */
    DmaChlGlobalCfgPtr->PriorityConfig->PreemptionDis = (boolean)FALSE;
    /* Disable suspend */
    DmaChlGlobalCfgPtr->PriorityConfig->SuspendEn = (boolean)FALSE;
    /* set DMA channel global configuration */
    Dma_Drv_SetChannelGlobalConfig((Dma_Drv_ChannelType)DmaChId, DmaChlGlobalCfgPtr);
}

/**
 * @brief      This function config icu dma transfer configuration parameter
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  BufferSize:     Size of the external buffer
 * @param[in]  NotifyInterval: Notification interval
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 *
 * @return none
 *
 */
void Icu_Drvw_TimestampDmaTransferConfig(const uint32 DmaChId, 
                            const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint16 BufferSize, 
                               uint16 NotifyInterval, uint16 * BufferPtr)
{
    Dma_Drv_ChannelTransferConfigType   *DmaChlTransferCfgPtr = &Icu_Drvw_TsDmaTransferConfig;
    DmaChlTransferCfgPtr->SourceConfig = Icu_Drvw_TsDmaSourceConfig;
    DmaChlTransferCfgPtr->DestinationConfig = Icu_Drvw_TsDmaDestinationConfig;
    DmaChlTransferCfgPtr->ControlConfig = Icu_Drvw_TsDmaControlConfig;

    if(ICU_DRVW_INVALID_DMACHANNEL != DmaChId)
    {
        /* Address pointing to the source data */
        DmaChlTransferCfgPtr->SourceConfig->Addr = (uint32)Icu_Drvw_GetCounterAddr(DrvwHwChCfgPtr);
        /* Address pointing to the destination data */
        DmaChlTransferCfgPtr->DestinationConfig->Addr = (uint32)BufferPtr;
        /* Number of minor loop in a major loop: 1 */
        if ((BufferSize <= NotifyInterval) || (0U == NotifyInterval))
        {
            DmaChlTransferCfgPtr->ControlConfig->MinorLoopCnt = (uint16)BufferSize;
        }
        else
        {
            DmaChlTransferCfgPtr->ControlConfig->MinorLoopCnt = (uint16)NotifyInterval;
        }
        /* Source address offset in minor loop */
        DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = 0U;
        /* Destination address offset in minor loop */
        DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = 2;
        /* Source address offset after a major loop done */
        DmaChlTransferCfgPtr->SourceConfig->MajorLoopOffset = 0;
        /* Destination address offset after a major loop done */
        DmaChlTransferCfgPtr->DestinationConfig->MajorLoopOffset = 0U;
        /* Source data transfer size */
        DmaChlTransferCfgPtr->SourceConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;
        /* Destination data transfer size */
        DmaChlTransferCfgPtr->DestinationConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;
        /* Transfer bytes number */
        DmaChlTransferCfgPtr->ControlConfig->TransferNum = 2U;
        /* Disable request after done control */
        DmaChlTransferCfgPtr->ControlConfig->ReqDis = (boolean)TRUE;
        /* DMA transfer configure */
        Dma_Drv_SetChannelTransferConfig((Dma_Drv_ChannelType)DmaChId, DmaChlTransferCfgPtr);

        /* Enable dma channel request*/
        Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)DmaChId);
    }
}

/**
 * @brief      This function config icu dma transfer configuration parameter
 * @param[in]  DmaChId: dma channel id
 * @param[in]  ParamArray:     Pointer to a Array 
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_GetDmaTimestampIndex(const uint32 DmaChId, uint32 * ParamArray, 
                                            const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Dma_Drv_ChannelTransferConfigType   *DmaChlTransferCfgPtr = &Icu_Drvw_TsDmaTransferConfig;

            ParamArray[0] = DmaChlTransferCfgPtr->ControlConfig->MinorLoopCnt;
            ParamArray[1] = Dma_Drv_GetRestMinorLoopNum((Dma_Drv_ChannelType)DmaChId);
        }
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }

}

#endif


#if ((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_API) && (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE))

/**
 * @brief      This function starts the capturing of timer values on the edges
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  IcuInstSumNum:    number of driver instances configured 
 *
 * @return none
 *
 */
void Icu_Drvw_SignalMeasurementDmaGlobalConfig(const uint32 DmaChId, 
                            const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint32 IcuInstSumNum)
{
    Dma_Drv_ChannelGlobalConfigType   *DmaChlGlobalCfgPtr = &Icu_Drvw_SigMeasDmaChannelGlobalConfig;
    uint32 PhsyChId;

    DmaChlGlobalCfgPtr->RequestConfig = &Icu_Drvw_SigMeasDmaRequestConfig;
    DmaChlGlobalCfgPtr->PriorityConfig = &Icu_Drvw_SigMeasDmaPriorityConfig;
    PhsyChId = DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId;
    DmaChlGlobalCfgPtr->RequestConfig->MuxReqSrc = 
    (Dma_Drv_RequestSourceType)(DMA_DRV_REQ_TIM0_CHANNEL0 + (PhsyChId + (IcuInstSumNum * 8U)));
    /* Set request enable */
    DmaChlGlobalCfgPtr->RequestConfig->ReqEn = (boolean)TRUE;
    /* Mask Error interrupt */
    DmaChlGlobalCfgPtr->ErrIntEn = (boolean)FALSE;
    /* DMA channel priority */
    DmaChlGlobalCfgPtr->PriorityConfig->Priority = DMA_DRV_PRIORITY_LEVEL_0;
    /* Disable preemption */
    DmaChlGlobalCfgPtr->PriorityConfig->PreemptionDis = (boolean)FALSE;
    /* Disable suspend */
    DmaChlGlobalCfgPtr->PriorityConfig->SuspendEn = (boolean)FALSE;
    /* set DMA channel global configuration */

    Dma_Drv_SetChannelGlobalConfig((Dma_Drv_ChannelType)DmaChId, DmaChlGlobalCfgPtr);
}

/**
 * @brief      This function starts the capturing of timer values on the edges
 * @param[in]  DmaChId: dma channel id
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 *
 * @return none
 *
 */

void Icu_Drvw_SignalMeasurementDmaTransferConfig(const uint32 DmaChId, 
                         const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, volatile uint16 * BufferPtr)
{
    Dma_Drv_ChannelTransferConfigType *DmaChlTransferCfgPtr = &Icu_Drvw_SigMeasDmaTransferConfig;
    DmaChlTransferCfgPtr->SourceConfig = Icu_Drvw_SigMeasDmaSourceConfig;
    DmaChlTransferCfgPtr->DestinationConfig = Icu_Drvw_SigMeasDmaDestinationConfig;
    DmaChlTransferCfgPtr->ControlConfig = Icu_Drvw_SigMeasDmaControlConfig;

    /* Address pointing to the source data */
    DmaChlTransferCfgPtr->SourceConfig->Addr = (uint32)Icu_Drvw_GetCounterAddr(DrvwHwChCfgPtr);
    /* Address pointing to the destination data */
    DmaChlTransferCfgPtr->DestinationConfig->Addr = (uint32)(BufferPtr);
    /* Number of minor loop in a major loop: 1 */
    DmaChlTransferCfgPtr->ControlConfig->MinorLoopCnt = 1U;
    /* Source address offset in minor loop */
    DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = 0U;
    /* Destination address offset in minor loop */
    DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = 2U;
    /* Source address offset after a major loop done */
    DmaChlTransferCfgPtr->SourceConfig->MajorLoopOffset = 0U;
    /* Destination address offset after a major loop done */
    DmaChlTransferCfgPtr->DestinationConfig->MajorLoopOffset = 0;
    /* Source data transfer size */
    DmaChlTransferCfgPtr->SourceConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;
    /* Destination data transfer size */
    DmaChlTransferCfgPtr->DestinationConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;
    /* Transfer bytes number */
    DmaChlTransferCfgPtr->ControlConfig->TransferNum = 2U;
    /* Disable request after done control */
    DmaChlTransferCfgPtr->ControlConfig->ReqDis = (boolean)TRUE;
    /* DMA transfer configure */
    Dma_Drv_SetChannelTransferConfig((Dma_Drv_ChannelType)DmaChId, DmaChlTransferCfgPtr);
}

#endif    


#if (STD_ON == ICU_DRVW_TIMESTAMP_API)
/**
 * @brief      This function starts the capturing of timer values on the edges
 *
 * @param[in]  DrvwHwChCfgPtr:     configuration of the Channel
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 * @param[in]  BufferSize:     Size of the external buffer
 * @param[in]  NotifyInterval: Notification interval
 *
 * @return none
 *
 */
void Icu_Drvw_StartTimestamp(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, uint16 * BufferPtr, 
                                     uint16 BufferSize, uint16 NotifyInterval)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_StartTimestamp((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId, 
                                     BufferPtr, BufferSize, NotifyInterval);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function stops the capturing of timer values on the edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_StopTimestamp(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_StopTimestamp((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function read the timestamp index of the given Channel
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return the timestamp index
 *
 */
uint16 Icu_Drvw_GetTimestampIndex(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint16 TsIdx = 0U;

    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            TsIdx = Tim_Icu_Drv_GetTimestampIndex((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }

    return TsIdx;
}
#endif

#if (STD_OFF == ICU_DRVW_OVERFLOW_NOTIFICATION_API)
#if ((STD_ON == ICU_DRVW_EDGE_COUNT_API) || (STD_ON == ICU_DRVW_TIMESTAMP_API) || \
     (STD_ON == ICU_DRVW_GETTIMEELAPSED_API) || (STD_ON == ICU_DRVW_GET_DUTYCYCLE_VALUES_API))
/**
 * @brief      The function get the state of the overflow flag
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return whether the overflow flag has been set
 *
 */
boolean Icu_Drvw_GetOvfState(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    boolean OvfState = (boolean)FALSE;

    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            OvfState = Tim_Icu_Drv_GetOvfState((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }

    return OvfState;
}
#endif
#endif

#if (STD_ON == ICU_DRVW_EDGE_COUNT_API)
/**
 * @brief      This function resets the value of the counted edges to zero
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_ResetEdgeCount(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_ResetEdgeCount((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function enables the counting of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_EnableEdgeCount(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            (void)Tim_Icu_Drv_EnableEdgeCount((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function is reentrant and disables the counting of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_DisableEdgeCount(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_DisableEdgeCount((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function reads the number of counted edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return Number of the counted edges
 *
 */
uint16 Icu_Drvw_GetEdgeNumbers(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint16 EdgeNum = 0U;

    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            EdgeNum = Tim_Icu_Drv_GetEdgeNumbers((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
    
    return EdgeNum;
}
#endif

#if (STD_ON == ICU_DRVW_EDGE_DETECT_API)
/**
 * @brief      This function enables or re-enables the detection of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_EnableEdgeDetection(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_EnableEdgeDetection((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            Port_Icu_Drv_EnableEdgeDetection((Port_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Port_Icu_Drv_GpioNoType)DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId);
            break;

        case ICU_DRVW_INSTANCE_CMP:
            Cmp_Icu_Drv_EnableEdgeDetection((Cmp_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId);
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function disables the detection of edges
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_DisableEdgeDetection(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_DisableEdgeDetection((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            Port_Icu_Drv_DisableEdgeDetection((Port_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Port_Icu_Drv_GpioNoType)DrvwHwChCfgPtr->ChannelConfig.PortIcuChCfgPtr->PhsyChId);
            break;

        case ICU_DRVW_INSTANCE_CMP:
            Cmp_Icu_Drv_DisableEdgeDetection((Cmp_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId);
            break;
            
        default:
            /* Do nothing */
            break;
    }
}
#endif

#if (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_API)
/**
 * @brief      This function starts the measurement of signals
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_StartSignalMeasurement(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_StartSignalMeasurement((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function stops the measurement of signals
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return none
 *
 */
void Icu_Drvw_StopSignalMeasurement(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_StopSignalMeasurement((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}
#endif

#if (STD_ON == ICU_DRVW_GET_TIMEELAPSED_API)
/**
 * @brief      This function reads the elapsed Signal Low, High or Period Time
 *
 * @param[in]  DrvwHwChCfgPtr: configuration of the Channel
 *
 * @return elapsed time
 *
 */
Icu_Drvw_ValueType Icu_Drvw_GetTimeElapsed(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr)
{
    uint16 TimeElapsed = 0U;
    
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            TimeElapsed = Tim_Icu_Drv_GetTimeElapsed((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
    
    return (Icu_Drvw_ValueType)TimeElapsed;
}
#endif

#if (STD_ON == ICU_DRVW_GET_DUTYCYCLE_VALUES_API)
/**
 * @brief      This function reads the coherent active time and period time
 *
 * @param[in]  DrvwHwChCfgPtr:  configuration of the Channel
 * @param[out] DutyCyclePtr : Pointer to a buffer where the results (high time 
 *                          and period time) shall be placed 
 *
 * @return none
 *
 */
void Icu_Drvw_GetDutyCycleValues(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, 
                                           Tim_Icu_Drv_DutyCycleType* DutyCyclePtr)
{
   
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_GetDutyCycleValues((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId, 
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId, 
                                         DutyCyclePtr);

            
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}
#endif

#if (STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE)
/**
 * @brief      This function store the active time and period time
 *
 * @param[in]  DrvwHwChCfgPtr  : configuration of the Channel
 * @param[in]  PulseValue  : active time
 * @param[in]  PeriodValue : period time
 *
 * @return none
 *
 */
void Icu_Drvw_SetSignalMeasurementValue(const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr, 
                                                    Icu_Drvw_ValueType PulseValue,
                                                    Icu_Drvw_ValueType PeriodValue)
{
    switch(DrvwHwChCfgPtr->ChModule)
    {
        case ICU_DRVW_INSTANCE_TIM:
        {
            Tim_Icu_Drv_SetSignalMeasurementValue((Tim_Icu_Drv_IdType)DrvwHwChCfgPtr->InstId,
                (Tim_Icu_Drv_ChannelIdType)DrvwHwChCfgPtr->ChannelConfig.TimIcuChCfgPtr->PhsyChId, 
                                                PulseValue, PeriodValue);
            break;
        }
        
        case ICU_DRVW_INSTANCE_PORT:
            break;

        case ICU_DRVW_INSTANCE_CMP:
            break;
            
        default:
            /* Do nothing */
            break;
    }
}
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"                                                               

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu_Drvw */
/** @} end of group Icu_Module */


