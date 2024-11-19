/**************************************************************************************************/
/**
 * @file      : Ocu_Drvw.c
 * @brief     : Ocu driver wrapper source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Ocu_Drvw
 *  @brief Ocu driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Ocu_Drvw.h"
#include "Tim_Ocu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define OCU_DRVW_C_VENDOR_ID                   0x00B3U
#define OCU_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define OCU_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define OCU_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define OCU_DRVW_C_SW_MAJOR_VERSION            1U
#define OCU_DRVW_C_SW_MINOR_VERSION            2U
#define OCU_DRVW_C_SW_PATCH_VERSION            2U

#if (OCU_DRVW_C_VENDOR_ID != OCU_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Ocu_Drvw.c and Ocu_Drvw.h are different"
#endif

/* Check if  source file and Ocu_Drvw.h file are of the same Autosar version */
#if ((OCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != OCU_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (OCU_DRVW_C_AR_RELEASE_MINOR_VERSION != OCU_DRVW_H_AR_RELEASE_MINOR_VERSION) ||               \
     (OCU_DRVW_C_AR_RELEASE_REVISION_VERSION != OCU_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu_Drvw.c and Ocu_Drvw.h are different"
#endif

/* Check if source file and Ocu_Drvw.h file are of the same Software version */
#if ((OCU_DRVW_C_SW_MAJOR_VERSION != OCU_DRVW_H_SW_MAJOR_VERSION) ||                               \
     (OCU_DRVW_C_SW_MINOR_VERSION != OCU_DRVW_H_SW_MINOR_VERSION) ||                               \
     (OCU_DRVW_C_SW_PATCH_VERSION != OCU_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu_Drvw.c and Ocu_Drvw.h are different"
#endif

/* Check if current file and Tim_Ocu_Drv.h are the same vendor */
#if (OCU_DRVW_C_VENDOR_ID != TIM_OCU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Ocu_Drvw.c and Tim_Ocu_Drv.h are different"
#endif
/* Check if current file and Tim_Ocu_Drv.h are the same Autosar version */
#if ((OCU_DRVW_C_AR_RELEASE_MAJOR_VERSION != TIM_OCU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (OCU_DRVW_C_AR_RELEASE_MINOR_VERSION != TIM_OCU_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (OCU_DRVW_C_AR_RELEASE_REVISION_VERSION != TIM_OCU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu_Drvw.c and Tim_Ocu_Drv.h are different"
#endif
/* Check if current file and Tim_Ocu_Drv.h are the same Software version */
#if ((OCU_DRVW_C_SW_MAJOR_VERSION != TIM_OCU_DRV_H_SW_MAJOR_VERSION) ||                               \
     (OCU_DRVW_C_SW_MINOR_VERSION != TIM_OCU_DRV_H_SW_MINOR_VERSION) ||                               \
     (OCU_DRVW_C_SW_PATCH_VERSION != TIM_OCU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu_Drvw.c and Tim_Ocu_Drv.h are different"
#endif
/** @} end of Private_MacroDefinition */

#define OCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

/**
 * @brief Ocu wrapper level configuration structure
 */
static const Ocu_Drvw_ConfigType *Ocu_Drvw_GlobalConfig[OCU_MAX_PARTITIONS];

#define OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"
/**
 * @brief      Service to process ocu logic channel to hardware channel
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[out]  InstNum: Instance number
 * @param[out]  ChNum: Channel number
 * @return     None
 */
static Std_ReturnType Ocu_Drvw_ChannelProcess(uint16 NumChannel, uint8 *InstNum, uint8 *ChNum);
#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"
/**
 * @brief      Service to process ocu logic channel to hardware channel
 * 
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[out]  InstNum: Instance number
 * @param[out]  ChNum: Channel number
 * @return     None
 */
static Std_ReturnType Ocu_Drvw_ChannelProcess(uint16 NumChannel, uint8 *InstNum, uint8 *ChNum)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    const Tim_Ocu_Drv_ModuleConfigType  *TimModuleConfigTypePtr;
    const Tim_Ocu_Drv_ChannelConfigType *TimChannelConfigPtr;
    uint8 CoreId = (uint8)Ocu_GetCoreId();

    /* Channel Index in the TIM specific configuration table */
    uint16 ChannelIdx =
        (*Ocu_Drvw_GlobalConfig[CoreId]->ChannelsConfigPtr)[NumChannel].ChannelIndex;

    if (OCU_DRVW_TIM_CHANNEL ==
        (*Ocu_Drvw_GlobalConfig[CoreId]->ChannelsConfigPtr)[NumChannel].ChannelHwType)
    {
        TimModuleConfigTypePtr = Ocu_Drvw_GlobalConfig[CoreId]->ModuleConfigPtr;
        TimChannelConfigPtr = &(*TimModuleConfigTypePtr->ChannelsConfig)[ChannelIdx];

        /* Get TIM channel and instance numbers from Hw Channel Id */
        *InstNum = Tim_Ocu_Drv_GetInstanceNum(TimChannelConfigPtr->OcuHwChannel);
        *ChNum = Tim_Ocu_Drv_GetChannelNum(TimChannelConfigPtr->OcuHwChannel);
    }
    else
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    return Ret;
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
 * @brief     OCU Driver wrapper initialization.
 * 
 * @param[in] Ocu_Drvw_Config: Pointer to wrapper configuration set
 *
 * @return    None
 */
void Ocu_Drvw_Init(const Ocu_Drvw_ConfigType *const Ocu_Drvw_Config)
{
    uint8 CoreId = (uint8)Ocu_GetCoreId();
#if (STD_ON == OCU_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == OCU_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != Ocu_Drvw_Config);
    MCALLIB_DEV_ASSERT(NULL_PTR == Ocu_Drvw_GlobalConfig[CoreId]);
    MCALLIB_DEV_ASSERT(NULL_PTR != Ocu_Drvw_Config->ModuleConfigPtr);
#endif
    Ocu_Drvw_GlobalConfig[CoreId] = Ocu_Drvw_Config;
    Tim_Ocu_Drv_Init(Ocu_Drvw_GlobalConfig[CoreId]->ModuleConfigPtr);
#if (STD_ON == OCU_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#if (OCU_DRVW_DEINIT_API == STD_ON)
/**
 * @brief     OCU Driver wrapper deinitialization.
 * 
 * @param[in] Ocu_Drvw_Config: Pointer to wrapper configuration set
 *
 * @return    None
 */
void Ocu_Drvw_DeInit(const Ocu_Drvw_ConfigType *const Ocu_Drvw_Config)
{
    uint8 CoreId = (uint8)Ocu_GetCoreId();
#if (STD_ON == OCU_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == OCU_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != Ocu_Drvw_Config);
    MCALLIB_DEV_ASSERT(Ocu_Drvw_Config == Ocu_Drvw_GlobalConfig[CoreId]);
    MCALLIB_DEV_ASSERT(NULL_PTR != Ocu_Drvw_Config->ModuleConfigPtr);
#endif
    /* TIM wrapper level deinit function */
    Tim_Ocu_Drv_DeInit();
    Ocu_Drvw_GlobalConfig[CoreId] = NULL_PTR;
#if (STD_ON == OCU_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}
#endif /* OCU_DRVW_DEINIT_API */

/**
 * @brief      Service to start an OCU channel in wrapper level.
 *             This function  start an OCU channel by 
 *             allowing all compare match configured actions to be performed.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_StartChannel(uint16 NumChannel)
{
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        Tim_Ocu_Drv_StartChannel(InstNum, ChNum);
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief      Service to stop an OCU channel in wrapper level.
 *             This function stop an OCU channel by 
 *             halting compare match configured actions for this channel.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_StopChannel(uint16 NumChannel)
{
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        Tim_Ocu_Drv_StopChannel(InstNum, ChNum);
    }
    else
    {
        /* do nothing */
    }
}

#if (STD_ON == OCU_DRVW_SET_PIN_STATE_API)
/**
 * @brief      Service to set immediately the level of the pin associated to an OCU channel in 
 *             wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  PinState: Ocu channel pin state after init or deinit
 *
 * @return     None
 */
void Ocu_Drvw_SetPinState(uint16 NumChannel, OCU_DRVW_PIN_STATE_TYPE PinState)
{
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        Tim_Ocu_Drv_SetPinState(InstNum, ChNum, PinState);
    }
    else
    {
        /* do nothing */
    }
}
#endif

#if (OCU_DRVW_SET_PIN_ACTION_API == STD_ON)
/**
 * @brief      Service to indicate the driver what shall be done automatically by 
 *             hardware (if supported) upon compare match in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  PinAction: Ocu channel action after compare match
 *
 * @return     None
 */
void Ocu_Drvw_SetPinAction(uint16 NumChannel, OCU_DRVW_PIN_ACTION_TYPE PinAction)
{
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        Tim_Ocu_Drv_SetPinAction(InstNum, ChNum, PinAction);
    }
    else
    {
        /* do nothing */
    }
}
#endif

#if (OCU_DRVW_GET_COUNTER_API == STD_ON)
/**
 * @brief      Service to read the current value of the counter in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     uint16
 * @retval  RetCntVal: Content of the counter in ticks
 */
uint16 Ocu_Drvw_GetCounter(uint16 NumChannel)
{
    uint16 RetCntVal = 0U;
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        RetCntVal = (uint16)Tim_Ocu_Drv_GetCounter(InstNum);
    }
    else
    {
        /* do nothing */
    }

    return RetCntVal;
}

#endif /* OCU_DRVW_GET_COUNTER_API */

#if (OCU_DRVW_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/**
 * @brief      Service to set the value of the channel threshold using an absolute input data in 
 *             wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  ReferenceValue: Value given by the upper layer and used as a base to determine 
 *                             whether to call the notification before the function exits or not.
 * @param[in]  AbsoluteValue: Value to compare with the content of the counter. This value is in 
 *                            ticks.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:   The compare match will occur in this interval.
 * @retval     TIM_OCU_DRV_OUT_INTERVAL:  The compare match will occur out this interval.
 */
OCU_DRVW_RETURN_TYPE Ocu_Drvw_SetAbsoluteThreshold(uint16 NumChannel, uint16 ReferenceValue,
                                              uint16 AbsoluteValue)
{
    OCU_DRVW_RETURN_TYPE RetVal = TIM_OCU_DRV_IN_INTERVAL;
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        RetVal = Tim_Ocu_Drv_SetAbsoluteThreshold(InstNum, ChNum, (Tim_Ocu_Drv_ValueType)ReferenceValue,
                                            (Tim_Ocu_Drv_ValueType)AbsoluteValue);
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}
#endif /* OCU_DRVW_SET_ABSOLUTE_THRESHOLD_API */

#if (OCU_DRVW_SET_RELATIVE_THRESHOLD_API == STD_ON)
/**
 * @brief      Service to set the value of the channel threshold relative to the current value of 
 *             the counter in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  RelativeValue: Value to use for computing the new threshold.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:   The compare match will occur in this interval.
 * @retval     TIM_OCU_DRV_OUT_INTERVAL:  The compare match will occur out this interval.
 */
OCU_DRVW_RETURN_TYPE Ocu_Drvw_SetRelativeThreshold(uint16 NumChannel, uint16 RelativeValue)
{
    OCU_DRVW_RETURN_TYPE RetVal = TIM_OCU_DRV_IN_INTERVAL;
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        RetVal = Tim_Ocu_Drv_SetRelativeThreshold(InstNum, ChNum, (Tim_Ocu_Drv_ValueType)RelativeValue);
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}
#endif /* OCU_DRVW_SET_RELATIVE_THRESHOLD_API */

#if ((OCU_DRVW_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_DRVW_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
/**
 * @brief      Service to read the max value of the counter in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     uint16
 * @retval  RetMaxCntVal: max value of the counter in ticks
 */
uint16 Ocu_Drvw_GetMaxCounterValue(uint16 NumChannel)
{
    uint16 RetMaxCntVal = 0U;
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        RetMaxCntVal = Tim_Ocu_Drv_GetMaxCounterValue(InstNum, ChNum);
    }
    else
    {
        /* do nothing */
    }

    return RetMaxCntVal;
}
#endif

#if (STD_ON == OCU_DRVW_NOTIFICATION_SUPPORTED)
/**
 * @brief      This service is used to disable notifications from an OCU channel in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_DisableNotification(uint16 NumChannel)
{
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        Tim_Ocu_Drv_DisableNotification(InstNum, ChNum);
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief      This service is used to enable notifications from an OCU channel in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_EnableNotification(uint16 NumChannel)
{
    /* TIM channel and instance numbers */
    uint8 InstNum;
    uint8 ChNum;
    if ((Std_ReturnType)E_OK == Ocu_Drvw_ChannelProcess(NumChannel, &InstNum, &ChNum))
    {
        Tim_Ocu_Drv_EnableNotification(InstNum, ChNum);
    }
    else
    {
        /* do nothing */
    }
}
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Ocu_Drvw */

/** @} end of group Ocu_Module */
