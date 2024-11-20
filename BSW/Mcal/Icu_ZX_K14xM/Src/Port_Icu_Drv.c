/**************************************************************************************************/
/**
 * @file      : Port_Icu_Drv.c
 * @brief     : AUTOSAR Port Icu hardware driver source file
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

/** @addtogroup  Port_Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Port_Icu_Drv.h"
#include "Device_Regs.h"
#include "SchM_Icu.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define PORT_ICU_DRV_C_VENDOR_ID                   0x00B3U
#define PORT_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_ICU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_ICU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_ICU_DRV_C_SW_MAJOR_VERSION            1U
#define PORT_ICU_DRV_C_SW_MINOR_VERSION            2U
#define PORT_ICU_DRV_C_SW_PATCH_VERSION            2U

#if (PORT_ICU_DRV_C_VENDOR_ID != PORT_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Port_Icu_Drv.c and Port_Icu_Drv.h have different"
#endif

#if ((PORT_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != PORT_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != PORT_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Port_Icu_Drv.c and Port_Icu_Drv.h are different"
#endif

#if ((PORT_ICU_DRV_C_AR_RELEASE_REVISION_VERSION != PORT_ICU_DRV_H_AR_RELEASE_REVISION_VERSION) || \
        (PORT_ICU_DRV_C_SW_PATCH_VERSION != PORT_ICU_DRV_H_SW_PATCH_VERSION))
    #error "AutoSar version of Port_Icu_Drv.c and Port_Icu_Drv.h are different"
#endif


#if ((PORT_ICU_DRV_C_SW_MAJOR_VERSION != PORT_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (PORT_ICU_DRV_C_SW_MINOR_VERSION != PORT_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Port_Icu_Drv.c and Port_Icu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((PORT_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||     \
         (PORT_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Port_Icu_Drv.c and Device_Regs.h are different"
    #endif

    #if ((PORT_ICU_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_ICU_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (PORT_ICU_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_ICU_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Port_Icu_Drv.c and SchM_Icu.h are different"
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
 *  @brief PORT0 address array
 */
static Reg_Port_BfType *const Port_Icu_Drv_IcuRegBfPtr[PORT_ICU_DRV_INSTANCE_SUMCNT] = 
{
    (Reg_Port_BfType *)PORTA_BASE_ADDR, /*!< Port A base address */
    (Reg_Port_BfType *)PORTB_BASE_ADDR, /*!< Port B base address */
    (Reg_Port_BfType *)PORTC_BASE_ADDR, /*!< Port C base address */
    (Reg_Port_BfType *)PORTD_BASE_ADDR, /*!< Port D base address */
    (Reg_Port_BfType *)PORTE_BASE_ADDR  /*!< Port E base address */
};

/**
 *  @brief PORT0 address array
 */
static Reg_Port_WType *const Port_Icu_Drv_IcuRegWPtr[PORT_ICU_DRV_INSTANCE_SUMCNT] = 
{
    (Reg_Port_WType *)PORTA_BASE_ADDR, /*!< Port A base address */
    (Reg_Port_WType *)PORTB_BASE_ADDR, /*!< Port B base address */
    (Reg_Port_WType *)PORTC_BASE_ADDR, /*!< Port C base address */
    (Reg_Port_WType *)PORTD_BASE_ADDR, /*!< Port D base address */
    (Reg_Port_WType *)PORTE_BASE_ADDR  /*!< Port E base address */
};

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

static Port_Icu_Drv_ChannelStateType \
            Port_Icu_Drv_ChState[PORT_ICU_DRV_INSTANCE_SUMCNT][PORT_ICU_DRV_CHANNEL_SUMCNT];
static Port_Icu_Drv_InstanceStateType Port_Icu_Drv_InstState[PORT_ICU_DRV_INSTANCE_SUMCNT];

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

LOCAL_INLINE Port_Icu_Drv_ChannelStateType * Port_Icu_Drv_GetLocalChannelState(
                                                                    uint8 InstId, uint8 Channel)
{
    return (&Port_Icu_Drv_ChState[InstId][Channel]);
}

LOCAL_INLINE Port_Icu_Drv_InstanceStateType * Port_Icu_Drv_GetLocalInstanceState(uint8 InstId)
{
    return (&Port_Icu_Drv_InstState[InstId]);
}


#if (STD_ON == PORT_ICU_DRV_EDGE_DETECT_API)
LOCAL_INLINE void Port_Icu_Drv_LocalNotifyEvent(uint8 InstId, uint8 Channel)
{
    const Port_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Port_Icu_Drv_GetLocalChannelState(InstId, Channel);

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

#if (STD_ON == PORT_ICU_DRV_DEINIT_API)
LOCAL_INLINE void Port_Icu_Drv_LocalClearChannelState(uint8 InstId, uint8 Channel)
{
    Port_Icu_Drv_ChannelStateType * ChStatePtr;

    ChStatePtr = Port_Icu_Drv_GetLocalChannelState(InstId, Channel);

    ChStatePtr->ActiveEdge = PORT_ICU_DRV_INPUT_DISABLED;
    ChStatePtr->CallbackFun = NULL_PTR;
    ChStatePtr->ChNotificationFun = NULL_PTR;
    ChStatePtr->CallbackParam = 0U;
    ChStatePtr->NotifyEnable = (boolean)FALSE;
}
#endif

LOCAL_INLINE void Port_Icu_Drv_LocalDisableInterrupt(uint8 InstId, uint8 Channel)
{
    Reg_Port_BfType * PORTx;
    Reg_Port_WType * PORTWx;

    PORTx  = Port_Icu_Drv_IcuRegBfPtr[InstId];
    PORTWx  = Port_Icu_Drv_IcuRegWPtr[InstId];

    if (PORTx->PORTx_PCRn[Channel].LK == 1U)
    {
        PORTWx->PORTx_PCRn[Channel] = 0x5B000000U;
    }

    PORTx->PORTx_PCRn[Channel].IRQC = (uint32)PORT_ICU_DRV_INPUT_DISABLED;

    PORTx->PORTx_PCRn[Channel].ISF = 0x01U;
    PORTx->PORTx_PCRn[Channel].LK = 1U;
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
 * @brief      Initialize a hardware Icu port Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  PortIcuInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
Port_Icu_Drv_StatusType Port_Icu_Drv_Init(Port_Icu_Drv_IdType InstId, 
                                          const Port_Icu_Drv_InstanceConfigType * PortIcuInstCfgPtr)
{
    const Port_Icu_Drv_ChannelConfigType * ChCfgPtr;
    Port_Icu_Drv_ChannelStateType * ChStatePtr;
    Port_Icu_Drv_InstanceStateType * InstStatePtr;
    uint8 Loop;
    uint32 PhsyChId;

    Port_Icu_Drv_StatusType RetVal = PORT_ICU_DRV_STATUS_SUCCESS;

    InstStatePtr = Port_Icu_Drv_GetLocalInstanceState((uint8)InstId);

    if (FALSE == InstStatePtr->InstInitFlag)
    {
        for (Loop = 0U; Loop < PortIcuInstCfgPtr->ChSumNum ; Loop++)
        {
            ChCfgPtr = &(*PortIcuInstCfgPtr->ChCfgPtr)[Loop];
            PhsyChId = ChCfgPtr->PhsyChId;
            
            ChStatePtr = Port_Icu_Drv_GetLocalChannelState((uint8)InstId, (uint8)PhsyChId);
            ChStatePtr->CallbackFun = ChCfgPtr->CallbackFun;
            ChStatePtr->CallbackParam = ChCfgPtr->CallbackParam;    
            ChStatePtr->ActiveEdge = ChCfgPtr->ActiveEdge;  
            ChStatePtr->NotifyEnable = (boolean)FALSE;    
#if (STD_ON == PORT_ICU_DRV_GET_INPUT_STATE_API)
            ChStatePtr->InputStatus = (boolean)FALSE;
#endif 
            Port_Icu_Drv_LocalDisableInterrupt((uint8)InstId, (uint8)PhsyChId);
        }

        InstStatePtr->InstInitFlag = (boolean)TRUE;
    }
    else
    {
        RetVal = PORT_ICU_DRV_STATUS_ERROR;
    }
    
    return RetVal;
}

#if (STD_ON == PORT_ICU_DRV_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
Port_Icu_Drv_StatusType Port_Icu_Drv_DeInit (Port_Icu_Drv_IdType InstId)
{
    Port_Icu_Drv_InstanceStateType * InstStatePtr;
    Port_Icu_Drv_StatusType RetVal = PORT_ICU_DRV_STATUS_SUCCESS;
    uint32 Channel;

    InstStatePtr = Port_Icu_Drv_GetLocalInstanceState((uint8)InstId);


    if (TRUE == InstStatePtr->InstInitFlag)
    {
        for (Channel = 0U; Channel < PORT_ICU_DRV_CHANNEL_SUMCNT; Channel++)
        {

            Port_Icu_Drv_LocalDisableInterrupt((uint8)InstId, (uint8)Channel);
            Port_Icu_Drv_LocalClearChannelState((uint8)InstId, (uint8)Channel);
        }
        InstStatePtr->InstInitFlag = (boolean)FALSE;

    }
    else
    {
        RetVal = PORT_ICU_DRV_STATUS_ERROR;
    }
    

    return RetVal;

}
#endif

/**
 * @brief      The function that sets up the activation condition
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 * @param[in]  ActiveEdge: edge activation type used 
 *
 * @return none
 *
 */
void Port_Icu_Drv_SetActivationCondition(Port_Icu_Drv_IdType InstId,
                                            Port_Icu_Drv_GpioNoType Channel,  
                                                   Port_Icu_Drv_EdgeAlignmentModeType ActiveEdge)
{


    Port_Icu_Drv_ChannelStateType * ChStatePtr;



    ChStatePtr = Port_Icu_Drv_GetLocalChannelState((uint8)InstId, (uint8)Channel);
    SchM_Enter_Icu_PortSetActiveEdge();

    ChStatePtr->ActiveEdge = ActiveEdge;

    SchM_Exit_Icu_PortSetActiveEdge();

}

/**
 * @brief      The function disable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 *
 * @return none
 *
 */
void Port_Icu_Drv_DisableNotification(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel)
{
    Port_Icu_Drv_ChannelStateType * ChStatePtr;
    SchM_Enter_Icu_PortSetChannelState();
    ChStatePtr = Port_Icu_Drv_GetLocalChannelState((uint8)InstId, (uint8)Channel);
    ChStatePtr->NotifyEnable = (boolean)FALSE;
    SchM_Exit_Icu_PortSetChannelState();
}

/**
 * @brief      The function enable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 *
 * @return none
 *
 */
void Port_Icu_Drv_EnableNotification(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel)
{
    Port_Icu_Drv_ChannelStateType * ChStatePtr;
    SchM_Enter_Icu_PortSetChannelState();
    ChStatePtr = Port_Icu_Drv_GetLocalChannelState((uint8)InstId, (uint8)Channel);
    ChStatePtr->NotifyEnable = (boolean)TRUE;
    SchM_Exit_Icu_PortSetChannelState();
}

#if (STD_ON == PORT_ICU_DRV_GET_INPUT_STATE_API)
/**
 * @brief      The function get input state of the Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 *
 * @return input state
 *
 */
boolean Port_Icu_Drv_GetInputState(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel)
{

    boolean RetVal = (boolean)FALSE;
    Port_Icu_Drv_ChannelStateType * ChStatePtr;
    SchM_Enter_Icu_PortGetInputState();
    ChStatePtr = Port_Icu_Drv_GetLocalChannelState((uint8)InstId, (uint8)Channel);
    RetVal = ChStatePtr->InputStatus;
    ChStatePtr->InputStatus = (boolean)FALSE;
    SchM_Exit_Icu_PortGetInputState();
    return RetVal;
}
#endif

#if (STD_ON == PORT_ICU_DRV_EDGE_DETECT_API)
/**
 * @brief      This function enable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 *
 * @return none
 *
 */
void Port_Icu_Drv_EnableEdgeDetection(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel)
{
    Port_Icu_Drv_ChannelStateType * ChStatePtr;
    Reg_Port_BfType * PORTx;
    Reg_Port_WType * PORTWx;
    PORTx = Port_Icu_Drv_IcuRegBfPtr[InstId];
    PORTWx  = Port_Icu_Drv_IcuRegWPtr[InstId];
    ChStatePtr = Port_Icu_Drv_GetLocalChannelState((uint8)InstId, (uint8)Channel);
    SchM_Enter_Icu_PortSetChannelState();
    if (PORTx->PORTx_PCRn[Channel].LK == 1U)
    {
        PORTWx->PORTx_PCRn[Channel] = 0x5B000000U;
    }
    PORTx->PORTx_PCRn[(uint32)Channel].ISF = 0x01U;
    PORTx->PORTx_PCRn[(uint32)Channel].IRQC =(uint32)ChStatePtr->ActiveEdge;
    PORTx->PORTx_PCRn[Channel].LK =1U;
    SchM_Exit_Icu_PortSetChannelState();
#if(STD_ON == PORT_ICU_DRV_GET_INPUT_STATE_API)
    ChStatePtr->InputStatus = (boolean)FALSE; 
#endif
}

/**
 * @brief      This function disable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 *
 * @return none
 *
 */
void Port_Icu_Drv_DisableEdgeDetection(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel)
{
    SchM_Enter_Icu_PortSetActiveEdge();

    Port_Icu_Drv_LocalDisableInterrupt((uint8)InstId, (uint8)Channel);
  
    SchM_Exit_Icu_PortSetActiveEdge();
}
#endif

#if (STD_ON == PORT_ICU_DRV_SET_MODE_API)
/**
 * @brief      Sets hardware Channel into SLEEP mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used 
 *
 * @return none
 *
 */
void Port_Icu_Drv_SetChannelSleepMode(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel)
{
    Reg_Port_BfType * PORTx;
    Reg_Port_WType * PORTWx;

    PORTx  = Port_Icu_Drv_IcuRegBfPtr[InstId];
    PORTWx  = Port_Icu_Drv_IcuRegWPtr[InstId];

    SchM_Enter_Icu_PortSetChannelState();
    if (PORTx->PORTx_PCRn[Channel].LK == 1U)
    {
        PORTWx->PORTx_PCRn[Channel] = 0x5B000000U;
    } 
    PORTx->PORTx_PCRn[(uint32)Channel].IRQC = (uint32)PORT_ICU_DRV_INPUT_DISABLED;
    PORTx->PORTx_PCRn[(uint32)Channel].ISF = 0x01U;
    PORTx->PORTx_PCRn[Channel].LK = 1U;
    SchM_Exit_Icu_PortSetChannelState();
}

/**
 * @brief      Sets hardware Channel into NORMAL mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used 
 *
 * @return none
 *
 */
void Port_Icu_Drv_SetChannelNormalMode(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel)
{
    Reg_Port_BfType * PORTx;
    Reg_Port_WType * PORTWx;   
    PORTx = Port_Icu_Drv_IcuRegBfPtr[InstId];
    PORTWx  = Port_Icu_Drv_IcuRegWPtr[InstId];
    SchM_Enter_Icu_PortSetChannelState();
    if (PORTx->PORTx_PCRn[Channel].LK == 1U)
    {
        PORTWx->PORTx_PCRn[Channel] = 0x5B000000U;
    } 
    PORTx->PORTx_PCRn[(uint32)Channel].ISF = 0x01U;
    PORTx->PORTx_PCRn[Channel].LK = 1U;
    SchM_Exit_Icu_PortSetChannelState();
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
void Port_Icu_Drv_ChIntHandler(Port_Icu_Drv_IdType InstId)
{
    Reg_Port_WType * PORTWx;
    uint32 status;
    uint32 Channel;
    #if (STD_ON == PORT_ICU_DRV_GET_INPUT_STATE_API)
    Port_Icu_Drv_ChannelStateType * ChStatePtr;
    #endif
    PORTWx = Port_Icu_Drv_IcuRegWPtr[InstId];
    status = PORTWx->PORTx_IRQFLG;
    PORTWx->PORTx_IRQFLG = status;
    for (Channel = 0U; (uint32)Channel < PORT_ICU_DRV_CHANNEL_SUMCNT; Channel++)
    {
        if ((uint32)0U != (status & ((uint32)1U << Channel)))
        { 
#if (STD_ON == PORT_ICU_DRV_GET_INPUT_STATE_API)
            ChStatePtr = Port_Icu_Drv_GetLocalChannelState((uint8)InstId, (uint8)Channel);
            ChStatePtr->InputStatus = (boolean)TRUE;
#endif
#if (STD_ON == PORT_ICU_DRV_EDGE_DETECT_API)
            Port_Icu_Drv_LocalNotifyEvent((uint8)InstId, (uint8)Channel);
#endif
        }
    }               
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu_Drv */
/** @} end of group Icu_Module */

