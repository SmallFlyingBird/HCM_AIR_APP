/*************************************************************************************/
/**
 * @file      : Pwm_Drvw.c
 * @brief     : Pwm driver wrapper source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Drvw
 *  @brief Pwm driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pwm_Drvw.h"
#include "Mcpwm_Pwm_Drv.h"
#include "Tim_Pwm_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define PWM_DRVW_C_VENDOR_ID                   0x00B3U
#define PWM_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define PWM_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define PWM_DRVW_C_SW_MAJOR_VERSION            1U
#define PWM_DRVW_C_SW_MINOR_VERSION            2U
#define PWM_DRVW_C_SW_PATCH_VERSION            2U

/* Check if current file and Pwm_Drvw.h are the same vendor */
#if (PWM_DRVW_C_VENDOR_ID != PWM_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Drvw.c and Pwm_Drvw.h are different"
#endif
/* Check if current file and Pwm_Drvw.h are the same AutoSar version */
#if ((PWM_DRVW_C_AR_RELEASE_MAJOR_VERSION    != PWM_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_C_AR_RELEASE_MINOR_VERSION    != PWM_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_C_AR_RELEASE_REVISION_VERSION != PWM_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Drvw.c and Pwm_Drvw.h are different"
#endif
/* Check if current file and Pwm_Drvw.h are the same Software version */
#if ((PWM_DRVW_C_SW_MAJOR_VERSION != PWM_DRVW_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_C_SW_MINOR_VERSION != PWM_DRVW_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_C_SW_PATCH_VERSION != PWM_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Drvw.c and Pwm_Drvw.h are different"
#endif

/* Check if current file and Mcpwm_Pwm_Drv.h are the same vendor */
#if (PWM_DRVW_C_VENDOR_ID != MCPWM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Drvw.c and Mcpwm_Pwm_Drv.h are different"
#endif
/* Check if current file and Mcpwm_Pwm_Drv.h are the same AutoSar version */
#if ((PWM_DRVW_C_AR_RELEASE_MAJOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_C_AR_RELEASE_MINOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_C_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Drvw.c and Mcpwm_Pwm_Drv.h are different"
#endif
/* Check if current file and Mcpwm_Pwm_Drv.h are the same Software version */
#if ((PWM_DRVW_C_SW_MAJOR_VERSION != MCPWM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_C_SW_MINOR_VERSION != MCPWM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_C_SW_PATCH_VERSION != MCPWM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Drvw.c and Mcpwm_Pwm_Drv.h are different"
#endif

/* Check if current file and Tim_Pwm_Drv.h are the same vendor */
#if (PWM_DRVW_C_VENDOR_ID != TIM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Drvw.c and Tim_Pwm_Drv.h are different"
#endif
/* Check if current file and Tim_Pwm_Drv.h are the same AutoSar version */
#if ((PWM_DRVW_C_AR_RELEASE_MAJOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_C_AR_RELEASE_MINOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_C_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Drvw.c and Tim_Pwm_Drv.h are different"
#endif
/* Check if current file and Tim_Pwm_Drv.h are the same Software version */
#if ((PWM_DRVW_C_SW_MAJOR_VERSION != TIM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_C_SW_MINOR_VERSION != TIM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_C_SW_PATCH_VERSION != TIM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Drvw.c and Tim_Pwm_Drv.h are different"
#endif


/**
* @brief 100% duty cycle
*/
#define PWM_DRVW_DUTY_CYCLE_100           ((uint16)0x8000U)

/**
 * @brief Duty cycle calculate shift.
 */
#define PWM_DRVW_DUTY_CYCLE_CALC_SHIFT         (15UL)

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

/** @} end of group Private_VariableDefinition */


/** @defgroup Private_FunctionDeclaration
 *  @{
 */
static void Pwm_Drvw_ForceMcpwmOutputToLowLevel(boolean Force,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
                                
static void Pwm_Drvw_ForceTimOutputToLowLevel(boolean Force,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
                                
static void Pwm_Drvw_InitMcpwmIdleState(Pwm_Drvw_OutputStateType State,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

static void Pwm_Drvw_InitTimIdleState(Pwm_Drvw_OutputStateType State,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

#if ((PWM_DRVW_DEV_ERROR_DETECT == STD_ON) && (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON))
static Std_ReturnType Pwm_Drvw_CheckMcpwmDefaultDutyPhaseShiftParams(uint16 DutyCycle,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

static Std_ReturnType Pwm_Drvw_CheckTimDefaultDutyPhaseShiftParams(uint16 DutyCycle,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
                                     
/**
* @brief        This function will check phase shift ticks and duty cycle per unit value
*
* @param[in]    DutyCyclePu         Duty Cycle value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            Params is invalid
* @retval       E_OK                Params is valid
*
*/
static Std_ReturnType Pwm_Drvw_CheckDefaultDutyPhaseShiftParams(uint16 DutyCyclePu,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

#endif
/** @} end of group Private_FunctionDeclaration */


/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#if (PWM_DRVW_FORCE_OUTPUT_TO_LOW_LEVEL_API == STD_ON)
/**
* @brief        This function is used to ForceOutputToLowLevel function only if the channel is a
*               MCPWM channel
*
* @param[in]    Force              Flag to state if force to zero should be applied or not
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
static void Pwm_Drvw_ForceMcpwmOutputToLowLevel(boolean Force,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    boolean ForceEnable = Force;
    Mcpwm_Pwm_Drv_PolarityType PolCh = ChnConfigPtr->McpwmChConfig->Polarity;
    Mcpwm_Pwm_Drv_OutputStateType OutputState =  (MCPWM_PWM_DRV_POL_LOW == PolCh)? 
                                   MCPWM_PWM_DRV_OUTPUT_STATE_HIGH : MCPWM_PWM_DRV_OUTPUT_STATE_LOW;              
    uint8 ModuleId =  ChnConfigPtr->ChnHwId;
    uint8 ChannelId =  ChnConfigPtr->McpwmChConfig->ChannelId;

    if (MCPWM_PWM_DRV_CHANNEL_OUTPUT_FORCED != Mcpwm_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId))
    {
        if(TRUE == ForceEnable)
        {
            Mcpwm_Pwm_Drv_SetCurrentChannelState(ModuleId, ChannelId,MCPWM_PWM_DRV_CHANNEL_OUTPUT_FORCED);
        }
    }
    else
    {
        if(FALSE == ForceEnable)
        {
            Mcpwm_Pwm_Drv_RevertCurrentChannelState(ModuleId, ChannelId);
            if (MCPWM_PWM_DRV_CHANNEL_IDLE == Mcpwm_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId))
            {
                OutputState = Mcpwm_Pwm_Drv_GetIdleState(ModuleId, ChannelId);
                ForceEnable = TRUE;
            }
        }
    }

    Mcpwm_Pwm_Drv_SwOutputControl(ModuleId,ChannelId,OutputState,ForceEnable);               
}

/**
* @brief        This function is used to ForceOutputToLowLevel function only if the channel is a
*               Tim channel
*
* @param[in]    Force              Flag to state if force to zero should be applied or not
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
static void Pwm_Drvw_ForceTimOutputToLowLevel(boolean                            Force,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    boolean ForceEnable = Force;
    Tim_Pwm_Drv_PolarityType PolCh = ChnConfigPtr->TimChConfig->Polarity;
    Tim_Pwm_Drv_OutputStateType OutputState =  (TIM_PWM_DRV_POL_LOW == PolCh)? 
                                   TIM_PWM_DRV_OUTPUT_STATE_HIGH : TIM_PWM_DRV_OUTPUT_STATE_LOW;          
    uint8 ModuleId =  ChnConfigPtr->ChnHwId;
    uint8 ChannelId =  ChnConfigPtr->TimChConfig->ChannelId;

    if (TIM_PWM_DRV_CHANNEL_OUTPUT_FORCED != Tim_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId))
    {
        if(TRUE == ForceEnable)
        {
            Tim_Pwm_Drv_SetCurrentChannelState(ModuleId, ChannelId,TIM_PWM_DRV_CHANNEL_OUTPUT_FORCED);
        }
    }
    else
    {
        if(FALSE == ForceEnable)
        {
            Tim_Pwm_Drv_RevertCurrentChannelState(ModuleId, ChannelId);
            if (TIM_PWM_DRV_CHANNEL_IDLE == Tim_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId))
            {
                OutputState = Tim_Pwm_Drv_GetIdleState(ModuleId, ChannelId);;
                ForceEnable = TRUE;
            }
        }
    }

    Tim_Pwm_Drv_SwOutputControl(ModuleId,ChannelId,OutputState,ForceEnable);               
}
#endif /* PWM_DRVW_FORCE_OUTPUT_TO_LOW_LEVEL_API */

/**
* @brief        This function is used to init channel idle state only if the channel is a
*               Mcpwm channel
*
* @param[in]    State              Channel idle state
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
static void Pwm_Drvw_InitMcpwmIdleState(Pwm_Drvw_OutputStateType State,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    Mcpwm_Pwm_Drv_PolarityType Polarity = ChnConfigPtr->McpwmChConfig->Polarity;

    Mcpwm_Pwm_Drv_InitOffValue(ModuleId, ChannelId, (Mcpwm_Pwm_Drv_OutputStateType)State);

    if(MCPWM_PWM_DRV_POL_HIGH == Polarity)
    {
        Mcpwm_Pwm_Drv_InitIdleState(ModuleId, ChannelId, (Mcpwm_Pwm_Drv_OutputStateType)State);
    }
    else
    {
        if(PWM_DRVW_LOW == State)
        {
            Mcpwm_Pwm_Drv_InitIdleState(ModuleId, ChannelId, MCPWM_PWM_DRV_OUTPUT_STATE_HIGH);
        }
        else
        {
            Mcpwm_Pwm_Drv_InitIdleState(ModuleId, ChannelId, MCPWM_PWM_DRV_OUTPUT_STATE_LOW);
        }
    }
}

/**
* @brief        This function is used to init channel idle state only if the channel is a
*               Tim channel
*
* @param[in]    State              Channel idle state
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
static void Pwm_Drvw_InitTimIdleState(Pwm_Drvw_OutputStateType State,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    Tim_Pwm_Drv_PolarityType Polarity = ChnConfigPtr->TimChConfig->Polarity;

    if(TIM_PWM_DRV_POL_HIGH == Polarity)
    {
        Tim_Pwm_Drv_InitIdleState(ModuleId, ChannelId, (Tim_Pwm_Drv_OutputStateType)State);
    }
    else
    {
        if(PWM_DRVW_LOW == State)
        {
            Tim_Pwm_Drv_InitIdleState(ModuleId, ChannelId, TIM_PWM_DRV_OUTPUT_STATE_HIGH);
        }
        else
        {
            Tim_Pwm_Drv_InitIdleState(ModuleId, ChannelId, TIM_PWM_DRV_OUTPUT_STATE_LOW);
        }
    }
}

#if ((PWM_DRVW_DEV_ERROR_DETECT == STD_ON) && (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON))
/**
* @brief        This function will check phase shift ticks and duty cycle per unit value only if the 
*               channel is a Mcpwm channel
*
* @param[in]    DutyCycle           Duty Cycle value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            Params is invalid
* @retval       E_OK                Params is valid
*
*/
static Std_ReturnType Pwm_Drvw_CheckMcpwmDefaultDutyPhaseShiftParams(uint16 DutyCycle,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint16 CnVValue = 0U;
    uint16 CurrentPeriod;
    uint16 DutyTicks;
    uint16 PhaseShiftTicks;

    uint8 ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
    if(0U == (ChannelId % 2U))
    {
        if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == \
                            ChnConfigPtr->McpwmChConfig->ChannelMode)
        {
            PhaseShiftTicks = ChnConfigPtr->McpwmChConfig->PairCfg->PhaseShiftValue;
            CurrentPeriod = Mcpwm_Pwm_Drv_GetPeriod(ModuleId, ChannelId);
            DutyTicks = (uint16)((uint32)((uint32)CurrentPeriod * DutyCycle) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);
            if ((MCPWM_PWM_DRV_MAX_DUTY_CYCLE != DutyCycle) && (0U != DutyCycle))
            {
                CnVValue = PhaseShiftTicks + DutyTicks;

                if ((CnVValue <= PhaseShiftTicks) || (CurrentPeriod <= CnVValue))
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
            }
        }
    }

    return RetVal;
}

/**
* @brief        This function will check phase shift ticks and duty cycle per unit value only if the 
*               channel is a Tim channel
*
* @param[in]    DutyCycle           Duty Cycle value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            Params is invalid
* @retval       E_OK                Params is valid
*
*/
static Std_ReturnType Pwm_Drvw_CheckTimDefaultDutyPhaseShiftParams(uint16 DutyCycle,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint16 CnVValue = 0U;
    uint16 CurrentPeriod;
    uint16 DutyTicks;
    uint16 PhaseShiftTicks;

    uint8 ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
    if(0U == (ChannelId % 2U))
    {
        if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == \
                                ChnConfigPtr->TimChConfig->ChannelMode)
        {
            PhaseShiftTicks = ChnConfigPtr->TimChConfig->PairCfg->PhaseShiftValue;
            CurrentPeriod = Tim_Pwm_Drv_GetPeriod(ModuleId);
            DutyTicks = (uint16)((uint32)((uint32)CurrentPeriod * DutyCycle) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);
            if ((TIM_PWM_DRV_MAX_DUTY_CYCLE != DutyCycle) && (0U != DutyCycle))
            {
                CnVValue = PhaseShiftTicks + DutyTicks;

                if ((CnVValue <= PhaseShiftTicks) || (CurrentPeriod <= CnVValue))
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
            }
        }
    }        

    return RetVal;
}

/**
* @brief        This function will check phase shift ticks and duty cycle per unit value
*
* @param[in]    DutyCyclePu         Duty Cycle value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            Params is invalid
* @retval       E_OK                Params is valid
*
*/
static Std_ReturnType Pwm_Drvw_CheckDefaultDutyPhaseShiftParams(uint16 DutyCyclePu,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(DutyCyclePu > PWM_DRVW_DUTY_CYCLE_100)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        uint16 DutyCycle = PWM_DRVW_DUTY_CYCLE_100 - DutyCyclePu;
        switch (ChnConfigPtr->ChnHwType)
        {
        case PWM_DRVW_HW_MCPWM:
            RetVal = Pwm_Drvw_CheckMcpwmDefaultDutyPhaseShiftParams(DutyCycle,ChnConfigPtr);
            break;

        case PWM_DRVW_HW_TIM:
            RetVal = Pwm_Drvw_CheckTimDefaultDutyPhaseShiftParams(DutyCycle,ChnConfigPtr); 
            break;
        
        default:
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return RetVal;
}
#endif

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
/**
* @brief        This function is used to Init the corresponding physical pwm module.
*
* @param[in]    HwCfgPtr       Pointer to Pwm module configuration structure
*
* @return       void
*/
void Pwm_Drvw_Init(const Pwm_Drvw_HwConfigType * const HwCfgPtr)
{
    uint8 ModuleId = HwCfgPtr->HwId;
    
    if(PWM_DRVW_HW_MCPWM == HwCfgPtr->HwType)
    {
        if(NULL_PTR != HwCfgPtr->McpwmHwConfig)
        {
            Mcpwm_Pwm_Drv_Init(ModuleId, HwCfgPtr->McpwmHwConfig);
        }
    }
    else if(PWM_DRVW_HW_TIM == HwCfgPtr->HwType)
    {
        if(NULL_PTR != HwCfgPtr->TimHwConfig)
        {
            Tim_Pwm_Drv_Init(ModuleId, HwCfgPtr->TimHwConfig);
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

/**
* @brief        This function is used to set default duty cycle to corresponding physical channel.
*
* @param[in]    DutyCyclePu    Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr   Pointer to Pwm channel configuration structure
*
* @return       void
*/
void Pwm_Drvw_SetDefaultDutyCycle(uint16 DutyCyclePu,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint32 DutyCycleTicks = 0U;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;

#if ((PWM_DRVW_DEV_ERROR_DETECT == STD_ON) && (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON))
    Std_ReturnType RetVal = Pwm_Drvw_CheckDefaultDutyPhaseShiftParams(DutyCyclePu, ChnConfigPtr);
    if((Std_ReturnType)E_OK == RetVal)
    {
#endif       
        if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
        {
            ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
            DutyCycleTicks = (uint32)Mcpwm_Pwm_Drv_GetPeriod(ModuleId, ChannelId) * (uint32)DutyCyclePu;
            DutyCycleTicks = DutyCycleTicks >> PWM_DRVW_DUTY_CYCLE_CALC_SHIFT;
        
            /* Call Mcpwm function */
            Mcpwm_Pwm_Drv_SetDutyCycle (ModuleId, ChannelId, (uint16)DutyCycleTicks, FALSE);
        }
        else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
        {
            ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
            DutyCycleTicks = (uint32)Tim_Pwm_Drv_GetPeriod(ModuleId) * (uint32)DutyCyclePu;
            DutyCycleTicks = DutyCycleTicks >> PWM_DRVW_DUTY_CYCLE_CALC_SHIFT;
        
            /* Call Tim function */
            Tim_Pwm_Drv_SetDutyCycle (ModuleId, ChannelId, (uint16)DutyCycleTicks, FALSE);
        }
        else
        {
            /* Nothing to do. */
            (void)DutyCycleTicks;
            (void)DutyCyclePu; 
        } 
#if ((PWM_DRVW_DEV_ERROR_DETECT == STD_ON) && (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON))
    }
#endif
}

/**
* @brief        This function is used to update the default dutycycle to physical register.
*
* @param[in]    ModuleId       Id to Pwm module to be synchronized 
* @param[in]    HwType         HW module type
*
* @return       void
*/
void Pwm_Drvw_SyncDefaultDutyCycle(uint8 ModuleId, Pwm_Drvw_HwType HwType)
{
    if(PWM_DRVW_HW_MCPWM == HwType)
    {
        Mcpwm_Pwm_Drv_SoftwareUpdate(ModuleId);
    }
    else if(PWM_DRVW_HW_TIM == HwType)
    {
        Tim_Pwm_Drv_SoftwareUpdate(ModuleId);
    }
    else
    {
        /* Nothing to do. */
    } 
}

/**
* @brief        This function is used to start the counters of the corresponding physical pwm module
*
* @param[in]    HwCfgPtr       Pointer to Pwm module configuration structure
*
* @return       void
*/
void Pwm_Drvw_StartInstance(const Pwm_Drvw_HwConfigType * const HwCfgPtr)
{
    uint8 ModuleId = HwCfgPtr->HwId;
    
    if(PWM_DRVW_HW_MCPWM == HwCfgPtr->HwType)
    {
        if(NULL_PTR != HwCfgPtr->McpwmHwConfig)
        {
            Mcpwm_Pwm_Drv_InitInstanceStart(ModuleId, HwCfgPtr->McpwmHwConfig->InstanceCfg);
        }
    }
    else if(PWM_DRVW_HW_TIM == HwCfgPtr->HwType)
    {
        if(NULL_PTR != HwCfgPtr->TimHwConfig)
        {
            Tim_Pwm_Drv_InitInstanceStart(ModuleId, HwCfgPtr->TimHwConfig->InstanceCfg);
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

#if (PWM_DRVW_DE_INIT_API == STD_ON)
/**
* @brief        This function is used to deinitialize the corresponding pwm physical module.
*
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*/
void Pwm_Drvw_DeInit(const Pwm_Drvw_HwConfigType * const HwCfgPtr)
{
    uint8 ModuleId = HwCfgPtr->HwId;
    
    if(PWM_DRVW_HW_MCPWM == HwCfgPtr->HwType)
    {
        Mcpwm_Pwm_Drv_DeInit(ModuleId);
    }
    else if(PWM_DRVW_HW_TIM == HwCfgPtr->HwType)
    {
        Tim_Pwm_Drv_DeInit(ModuleId);
    }
    else
    {
        /* Nothing to do. */
    }
}
#endif /* PWM_DRVW_DE_INIT_API */

#if (PWM_DRVW_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        This function is used to set the duty cycle to corresponding pwm channel 
*
* @param[in]    DutyCyclePu      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr      Pointer to Pwm channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_OK: Set duty cycle successfully.
* @retval       E_NOT_OK: Set duty cycle failed. 
*
*/
Std_ReturnType Pwm_Drvw_SetDutyCycle(uint16 DutyCyclePu,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId = 0U;
    uint32 DutyCycleTicks = 0;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->McpwmChConfig)
        {
            ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
            DutyCycleTicks = Mcpwm_Pwm_Drv_GetPeriod(ModuleId, ChannelId);
            DutyCycleTicks = (uint16)(((uint32)DutyCycleTicks * DutyCyclePu) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);

#if (PWM_DRVW_DUTYCYCLE_UPDATED_ENDPERIOD == STD_ON)
            Mcpwm_Pwm_Drv_SetDutyCycle(ModuleId, ChannelId,(uint16)DutyCycleTicks,TRUE);
#else
            Mcpwm_Pwm_Drv_SetDutyCycle(ModuleId, ChannelId,(uint16)DutyCycleTicks,FALSE);
            Mcpwm_Pwm_Drv_UpdateNow(ModuleId);
#endif
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->TimChConfig)
        {
            ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
            DutyCycleTicks = Tim_Pwm_Drv_GetPeriod(ModuleId);
            DutyCycleTicks = (uint16)(((uint32)DutyCycleTicks * DutyCyclePu) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);

            if((TIM_PWM_DRV_MODE_CENTER_ALIGNED == Tim_Pwm_Drv_GetChannelMode(ModuleId, ChannelId)) \
                                        && (DutyCycleTicks >= PWM_DRVW_DUTY_CYCLE_100))
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
#if (PWM_DRVW_DUTYCYCLE_UPDATED_ENDPERIOD == STD_ON)
                Tim_Pwm_Drv_SetDutyCycle(ModuleId, ChannelId, (uint16)DutyCycleTicks, TRUE);
#else
                Tim_Pwm_Drv_SetDutyCycle(ModuleId, ChannelId, (uint16)DutyCycleTicks, FALSE);
                Tim_Pwm_Drv_UpdateNow(ModuleId);
#endif
            }
        }
    }
    else
    {
        /* Nothing to do. */
    }

    return RetVal;
}
#endif /* PWM_DRVW_SET_DUTY_CYCLE_API */

#if (PWM_DRVW_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief      This function is used to set Period and Duty for the corresponding PwmChannel
*
* @param[in]    Period         Period ticks value for this channel
* @param[in]    DutyCyclePu    Duty cycle pu value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr   Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_OK: Set duty cycle successfully.
* @retval       E_NOT_OK: Set duty cycle failed. 
*
*/
Std_ReturnType Pwm_Drvw_SetPeriodAndDuty(Pwm_Drvw_PeriodType Period, uint16 DutyCyclePu,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint16 DutyCycleTicks = (uint16)(((uint32)Period * DutyCyclePu) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);
    
    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->McpwmChConfig)
        {
            ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;

#if (PWM_DRVW_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON)
            Mcpwm_Pwm_Drv_SetPeriodAndDuty(ModuleId, ChannelId, Period, DutyCycleTicks,TRUE);
#else
            Mcpwm_Pwm_Drv_SetPeriodAndDuty(ModuleId, ChannelId, Period, DutyCycleTicks,FALSE);
            Mcpwm_Pwm_Drv_UpdateNow(ModuleId);
#endif                                                                         
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->TimChConfig)
        {
            ChannelId = ChnConfigPtr->TimChConfig->ChannelId;

            if((TIM_PWM_DRV_MODE_CENTER_ALIGNED == Tim_Pwm_Drv_GetChannelMode(ModuleId, ChannelId))
                                                    && (DutyCycleTicks >= PWM_DRVW_DUTY_CYCLE_100))
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
#if (PWM_DRVW_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON)
                Tim_Pwm_Drv_SetPeriodAndDuty(ModuleId, ChannelId, Period, DutyCycleTicks, TRUE);
#else
                Tim_Pwm_Drv_SetPeriodAndDuty(ModuleId, ChannelId, Period, DutyCycleTicks, FALSE);
                Tim_Pwm_Drv_UpdateNow(ModuleId);
#endif
            }
        }
    }
    else
    {
        /* Nothing to do. */
    }

    return RetVal;
}
#endif /* PWM_DRVW_SET_PERIOD_AND_DUTY_API */

#if (PWM_DRVW_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        This function is used to set Output To Idle function for the corresponding PwmChannel
*
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_SetOutputToIdle(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;

    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        if (MCPWM_PWM_DRV_CHANNEL_RUNNING == Mcpwm_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId))
        {
            Mcpwm_Pwm_Drv_OutputStateType SwCtrlValue = Mcpwm_Pwm_Drv_GetIdleState(ModuleId, ChannelId);
            Mcpwm_Pwm_Drv_SetCurrentChannelState(ModuleId,ChannelId,MCPWM_PWM_DRV_CHANNEL_IDLE);
            Mcpwm_Pwm_Drv_SwOutputControl(ModuleId,ChannelId,SwCtrlValue,TRUE);
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
        if (TIM_PWM_DRV_CHANNEL_RUNNING == Tim_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId))
        {            
            Tim_Pwm_Drv_OutputStateType SwCtrlValue = Tim_Pwm_Drv_GetIdleState(ModuleId, ChannelId);
            Tim_Pwm_Drv_SetCurrentChannelState(ModuleId,ChannelId,TIM_PWM_DRV_CHANNEL_IDLE);
            Tim_Pwm_Drv_SwOutputControl(ModuleId,ChannelId,SwCtrlValue,TRUE);
        }
    }
    else
    {
        /* Nothing to do. */
    }
}
#endif /* PWM_DRVW_SET_OUTPUT_TO_IDLE_API */

#if (PWM_DRVW_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        This function is used to Get Output State for the corresponding PwmChannel
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Pwm_Drvw_OutputStateType
* @retval       HIGH: Current output state is high
* @retval       LOW: Current output state is low
*
*/
Pwm_Drvw_OutputStateType Pwm_Drvw_GetOutputState(
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Pwm_Drvw_OutputStateType RetVal = PWM_DRVW_LOW;   
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId = 0;

    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->McpwmChConfig)
        {
            ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
            Mcpwm_Pwm_Drv_OutputStateType PwmOutputState = \
                Mcpwm_Pwm_Drv_GetOutputState(ModuleId, ChannelId);
            
            RetVal =  (MCPWM_PWM_DRV_OUTPUT_STATE_LOW == PwmOutputState)? \
                       PWM_DRVW_LOW : PWM_DRVW_HIGH;
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->TimChConfig)
        {
            ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
            Tim_Pwm_Drv_OutputStateType PwmOutputState = \
                Tim_Pwm_Drv_GetOutputState(ModuleId, ChannelId);
            
            RetVal =  (TIM_PWM_DRV_OUTPUT_STATE_LOW == PwmOutputState)? \
                       PWM_DRVW_LOW : PWM_DRVW_HIGH;
        }
    }
    else
    {
        /* Nothing to do. */
    }

    return RetVal;

}
#endif /* PWM_DRVW_GET_OUTPUT_STATE_API */

#if (PWM_DRVW_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief      This function is used to DisableNotification for the corresponding PwmChannel
*
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_DisableNotification(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId =  ChnConfigPtr->ChnHwId;
    uint8 ChannelId;
    
    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->McpwmChConfig)
        {
            ChannelId =  ChnConfigPtr->McpwmChConfig->ChannelId;
            Mcpwm_Pwm_Drv_DisableNotification(ModuleId, ChannelId);
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->TimChConfig)
        {
            ChannelId =  ChnConfigPtr->TimChConfig->ChannelId;
            Tim_Pwm_Drv_DisableNotification(ModuleId, ChannelId);
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

/**
* @brief      This function is used to EnableNotification for the corresponding  PwmChannel
*
* @param[in]    Notification       Notification edge type to be enabled
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_EnableNotification(Pwm_Drvw_EdgeNotificationType Notification,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId =  ChnConfigPtr->ChnHwId;
    uint8 ChannelId;

    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->McpwmChConfig)
        {
            ChannelId =  ChnConfigPtr->McpwmChConfig->ChannelId;
            Mcpwm_Pwm_Drv_EnableNotification(ModuleId,ChannelId,(Mcpwm_Pwm_Drv_EdgeNotifType)Notification);
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->TimChConfig)
        {
            ChannelId =  ChnConfigPtr->TimChConfig->ChannelId;
            Tim_Pwm_Drv_EnableNotification(ModuleId,ChannelId,(Tim_Pwm_Drv_EdgeNotifType)Notification);
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

/**
* @brief        This feature will check whether the current channel supports the selected 
*               notification edge type.
*
* @param[in]    Notification       Notification edge type to be enabled
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            The selected notification edge type is not supported.
* @retval       E_OK                The selected notification edge type is supported.
*
*/
Std_ReturnType Pwm_Drvw_CheckEdgeNotificationType(Pwm_Drvw_EdgeNotificationType Notification,
                                       const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint8 ModuleId =  ChnConfigPtr->ChnHwId;
    uint8 ChannelId;

    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->McpwmChConfig)
        {
            ChannelId =  ChnConfigPtr->McpwmChConfig->ChannelId;
            Mcpwm_Pwm_Drv_ChannelModeType Mode = Mcpwm_Pwm_Drv_GetChannelMode(ModuleId, ChannelId);
            if(((MCPWM_PWM_DRV_MODE_CENTER_ALIGNED != Mode) && \
                (MCPWM_PWM_DRV_MODE_COMBINE_SYM_CENTER_ALIGNED != Mode)) || \
                (Notification == PWM_DRVW_BOTH_EDGES))
            {
                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        if (NULL_PTR != ChnConfigPtr->TimChConfig)
        {
            ChannelId =  ChnConfigPtr->TimChConfig->ChannelId;
            Tim_Pwm_Drv_ChannelModeType Mode = Tim_Pwm_Drv_GetChannelMode(ModuleId, ChannelId);
            if((Mode != TIM_PWM_DRV_MODE_CENTER_ALIGNED) || (Notification == PWM_DRVW_BOTH_EDGES))
            {
                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }
    else
    {
        /* Nothing to do. */
    }

    return RetVal;
}
#endif /* PWM_DRVW_NOTIFICATION_SUPPORTED */

#if (PWM_DRVW_GET_CHANNEL_DUTYCYCLE_API == STD_ON)
/**
* @brief        This function is used to get current duty cycle of the channel 
*
* @param[in]    ChnConfigPtr    Pointer to PWM channel configuration structure
*
* @return       uint16          DutyCyclePu of the specified logic channel
*/
uint16 Pwm_Drvw_GetChannelDutyCycle(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint16 DutyCyclePu = (uint16)0U;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;

    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        DutyCyclePu = Mcpwm_Pwm_Drv_GetChannelDutyCycle(ModuleId,ChannelId);
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
        DutyCyclePu = Tim_Pwm_Drv_GetChannelDutyCycle(ModuleId,ChannelId);
    }
    else
    {
        /* Nothing to do. */
    }

    return DutyCyclePu;
}
#endif /* PWM_DRVW_GET_CHANNEL_DUTYCYCLE_API */

#if (PWM_DRVW_FORCE_OUTPUT_TO_LOW_LEVEL_API == STD_ON)
/**
* @brief        This function is used to force the output to a low level function.
*
* @param[in]    Force              Flag to state if force to zero should be applied or not
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_ForceOutputToLowLevel(boolean Force,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        Pwm_Drvw_ForceMcpwmOutputToLowLevel(Force,ChnConfigPtr);
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        Pwm_Drvw_ForceTimOutputToLowLevel(Force,ChnConfigPtr);
    }
    else
    {
        /* Nothing to do. */
    }            
}
#endif /* PWM_DRVW_FORCE_OUTPUT_TO_LOW_LEVEL_API */

#if (PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON)
/**
* @brief        This function is used to update the deadtime ticks at runtime for Pwm channels.     
*
* @param[in]    DeadTimeTicks       dead Time value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK            Deadtime ticks is invalid
* @retval       E_OK                Deadtime ticks is valid
*
*/
Std_ReturnType Pwm_Drvw_SetChannelDeadTimeTicks(uint16 DeadTimeTicks,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;

    if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        if ((DeadTimeTicks > 0U) && (DeadTimeTicks < 4096U))
        {
            RetVal = (Std_ReturnType)E_OK;
            uint8 ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
            Mcpwm_Pwm_Drv_SetChannelDeadTime(ModuleId, ChannelId, DeadTimeTicks);
        }        
    }
    else if (PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        if ((DeadTimeTicks > 0U) && (DeadTimeTicks < 64U))
        {
            RetVal = (Std_ReturnType)E_OK;
            Tim_Pwm_Drv_SetCounterDeadTime(ModuleId,DeadTimeTicks);
        }       
    }
    else
    {
        /* Nothing to do. */
    }

    return RetVal;
}

#endif /* PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API */

#if (PWM_DRVW_SYNC_UPDATE_API == STD_ON)
    #if (PWM_DRVW_WRITE_DUTY_CYCLE_TO_BUFFER_API == STD_ON)
/**
* @brief        This function is used to write dutycycle to buffer register.
*
* @param[in]    DutyCyclePu      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr     Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK            The Idle state is not ready
* @retval       E_OK                The Idle state is ready
*
*/
Std_ReturnType Pwm_Drvw_WriteDutyCycleToBuffer(uint16 DutyCyclePu,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 DutyCycleTicks = 0U;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;

    if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        DutyCycleTicks = (uint32)Mcpwm_Pwm_Drv_GetPeriod(ModuleId, ChannelId) * (uint32)DutyCyclePu;
        DutyCycleTicks = DutyCycleTicks >> PWM_DRVW_DUTY_CYCLE_CALC_SHIFT;
        
        /* Call MCPWM function */
        Mcpwm_Pwm_Drv_SetDutyCycle(ModuleId, ChannelId, (uint16)DutyCycleTicks, FALSE);
    }
    else if (PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
        DutyCycleTicks = (uint32)Tim_Pwm_Drv_GetPeriod(ModuleId) * (uint32)DutyCyclePu;
        DutyCycleTicks = DutyCycleTicks >> PWM_DRVW_DUTY_CYCLE_CALC_SHIFT;

        if((TIM_PWM_DRV_MODE_CENTER_ALIGNED == Tim_Pwm_Drv_GetChannelMode(ModuleId, ChannelId)) && \
                                       (DutyCycleTicks >= PWM_DRVW_DUTY_CYCLE_100))
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Call TIM function */
            Tim_Pwm_Drv_SetDutyCycle(ModuleId, ChannelId, (uint16)DutyCycleTicks, FALSE);
        }
    }
    else
    {
        (void)DutyCycleTicks;
        (void)DutyCyclePu; 
    }

    return RetVal;
}
    #endif /* PWM_DRVW_WRITE_DUTY_CYCLE_TO_BUFFER_API */

    #if (PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API == STD_ON)
/**
* @brief        This function is used to write period and dutycycle to buffer register
*
* @param[in]    Period           Period value for this channel
* @param[in]    DutyCyclePu      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr     Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_OK: Set duty cycle successfully.
* @retval       E_NOT_OK: Set duty cycle failed.
*
*/
Std_ReturnType Pwm_Drvw_WritePeriodAndDutyToBuffer(Pwm_Drvw_PeriodType Period, uint16 DutyCyclePu,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    
    uint16 DutyCycleTicks = (uint16)(((uint32)Period * DutyCyclePu) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);
    
    if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    { 
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;       
        Mcpwm_Pwm_Drv_SetPeriodAndDuty(ModuleId, ChannelId, Period, DutyCycleTicks, FALSE);
    }
    else if (PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    { 
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;

        if((TIM_PWM_DRV_MODE_CENTER_ALIGNED == Tim_Pwm_Drv_GetChannelMode(ModuleId, ChannelId))
                                                    && (DutyCycleTicks >= PWM_DRVW_DUTY_CYCLE_100))
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Tim_Pwm_Drv_SetPeriodAndDuty(ModuleId, ChannelId, Period, DutyCycleTicks, FALSE);
        }
    }
    else
    {
        /* Nothing to do. */
        (void)DutyCycleTicks;
        (void)DutyCyclePu;
        (void)Period;
    }

    return RetVal;
}
    #endif /* PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API */

    #if (PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON)
/**
* @brief        This function set phase shift value and also force duty cycle to 50%. The output 
*               will take effect after Pwm_SyncUpdate be called.
*
* @param[in]    Period             Period value for this channel
* @param[in]    PhaseShiftTicks    Phase shift ticks value
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_WritePhaseShiftTicksToBuffer(uint16 Period, uint16 PhaseShiftTicks,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;

    if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {     
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        Mcpwm_Pwm_Drv_SetPhaseShift(ModuleId, ChannelId, Period, PhaseShiftTicks, FALSE);
    }
    else if (PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {     
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
        Tim_Pwm_Drv_SetPhaseShift(ModuleId, ChannelId, Period, PhaseShiftTicks, FALSE);
    }
    else
    {
        /* Nothing to do. */
        (void)PhaseShiftTicks;
        (void)Period;
    }
}
    #endif /* PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API */

/**
* @brief        This function will allow synchronized loading of the duty registers for 
*               all the channels of a given module
*
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_SyncUpdate(const Pwm_Drvw_HwConfigType * HwCfgPtr)
{
    uint8 ModuleId = HwCfgPtr->HwId;
    Pwm_Drvw_HwType HwType = HwCfgPtr->HwType;

    if(PWM_DRVW_HW_MCPWM == HwType)
    {
        Mcpwm_Pwm_Drv_SyncUpdate(ModuleId);
    }
    else if(PWM_DRVW_HW_TIM == HwType)
    {
        Tim_Pwm_Drv_SyncUpdate(ModuleId);
    }
    else
    {
        /* Nothing to do. */
    }
}
#endif /* PWM_DRVW_SYNC_UPDATE_API */

#if (PWM_DRVW_SET_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function set phase shift value and also force duty cycle to 50%. The output 
*               will effect immediately after calling this function.
*
* @param[in]    Period              Period value for this channel
* @param[in]    PhaseShiftTicks     Phase shift value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_SetPhaseShiftTicks(uint16 Period, uint16 PhaseShiftTicks,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;
    
    if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        Mcpwm_Pwm_Drv_SetPhaseShift(ModuleId, ChannelId, Period, PhaseShiftTicks, TRUE);
    }
    else if (PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
        Tim_Pwm_Drv_SetPhaseShift(ModuleId, ChannelId, Period, PhaseShiftTicks, TRUE);
    }
    else
    {
        /* Nothing to do. */
        (void)Period;
        (void)PhaseShiftTicks;     
    }
}
#endif /* PWM_DRVW_SET_PHASE_SHIFT_TICKS_API */

#if (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized 
*               base on API parameter SyncUpdate)
*
* @param[in]    DutyCyclePu               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShiftTicks           Phase shift value 
* @param[in]    ChnConfigPtr              Pointer to PWM channel configuration structure
* @param[in]    SyncUpdate                
*                      TRUE               calling Pwm_SyncUpdate Effective.
                       FALSE              Effective immediately
*
* @return       void
*
*/
void Pwm_Drvw_SetDutyPhaseShiftTicks(uint16 DutyCyclePu, uint16 PhaseShiftTicks,
                 const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr, boolean SyncUpdate)
{

    uint16 DutyCycleTicks = 0U;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;
    if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        DutyCycleTicks = Mcpwm_Pwm_Drv_GetPeriod(ModuleId, ChannelId);
        DutyCycleTicks = (uint16)(((uint32)DutyCycleTicks * DutyCyclePu) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT); 
        
        /* Call MCPWM function */
        Mcpwm_Pwm_Drv_SetDutyPhaseShift(ModuleId,ChannelId,DutyCycleTicks,PhaseShiftTicks,SyncUpdate);
    }
    else if (PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
        DutyCycleTicks = Tim_Pwm_Drv_GetPeriod(ModuleId);
        DutyCycleTicks = (uint16)(((uint32)DutyCycleTicks * DutyCyclePu) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT); 
        
        /* Call Tim function */
        Tim_Pwm_Drv_SetDutyPhaseShift(ModuleId,ChannelId,DutyCycleTicks,PhaseShiftTicks,SyncUpdate);
    }
    else
    {
        /* Nothing to do. */
        (void)DutyCycleTicks;
        (void)DutyCyclePu;
        (void)PhaseShiftTicks; 
        (void)SyncUpdate; 
    }
}
#endif /* PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API */

#if (PWM_DRVW_ENABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function enables trigger generation for specific source
*               Bit 0~7   Channel 0~7 Trigger Enable
*               Bit 8     Initialization Trigger Enable
*
* @param[in]    TrigMask       bit mask will be clear.
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_EnableTriggerOutput(uint16 TrigMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr)
{
    switch(HwCfgPtr->HwType)
    {
        case PWM_DRVW_HW_MCPWM:
            Mcpwm_Pwm_Drv_EnableTrigger(HwCfgPtr->HwId, (uint32)TrigMask);
            break;
            
        case PWM_DRVW_HW_TIM:
            Tim_Pwm_Drv_EnableTrigger(HwCfgPtr->HwId, (uint32)TrigMask);
            break;
            
        case PWM_DRVW_HW_NONE:
            break;
            
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_DRVW_ENABLE_TRIGGER_OUTPUT_API */

#if (PWM_DRVW_DISABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function disables trigger generation for specific source
*               
* @param[in]    TrigMask       bit mask will be clear for MCPWM_EXTTRIG.
*                                - Bit 0~7   Channel 0~7 Trigger Enable
*                                - Bit 8     Initialization Trigger Enable
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_DisableTriggerOutput(uint16 TrigMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr)
{
    switch(HwCfgPtr->HwType)
    {
        case PWM_DRVW_HW_MCPWM:
            Mcpwm_Pwm_Drv_DisableTrigger(HwCfgPtr->HwId, (uint32)TrigMask);
            break;
            
        case PWM_DRVW_HW_TIM:
            Tim_Pwm_Drv_DisableTrigger(HwCfgPtr->HwId, (uint32)TrigMask);
            break;
            
        case PWM_DRVW_HW_NONE:
            break;
            
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_DRVW_DISABLE_TRIGGER_OUTPUT_API */

#if (PWM_DRVW_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to their inactive state
*
* @param[in]    ChannelMask    bit mask will be set for MCPWM_OUTMASK.
*                                - Bit 0~7   Channel 0~7 Output Mask
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_MaskOutputs(uint8 ChannelMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr)
{
    switch(HwCfgPtr->HwType)
    {
        case PWM_DRVW_HW_MCPWM:
            Mcpwm_Pwm_Drv_MaskOutputChannels(HwCfgPtr->HwId, (uint32)ChannelMask);
            break;
            
        case PWM_DRVW_HW_TIM:
            Tim_Pwm_Drv_MaskOutputChannels(HwCfgPtr->HwId, (uint32)ChannelMask);
            break;
            
        case PWM_DRVW_HW_NONE:
            break;
            
        default:
            /* Nothing to do. */
            break;
    }
}

/**
* @brief        This function puts channels output to normal operation state
*
* @param[in]    ChannelMask    bit mask will be set for MCPWM_OUTMASK.
*                                - Bit 0~7   Channel 0~7 Output Mask
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_UnMaskOutputs(uint8 ChannelMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr)
{
    switch(HwCfgPtr->HwType)
    {
        case PWM_DRVW_HW_MCPWM:
            Mcpwm_Pwm_Drv_UnMaskOutputChannels(HwCfgPtr->HwId, (uint32)ChannelMask);
            break;
            
        case PWM_DRVW_HW_TIM:
            Tim_Pwm_Drv_UnMaskOutputChannels(HwCfgPtr->HwId, (uint32)ChannelMask);
            break;
            
        case PWM_DRVW_HW_NONE:
            break;
            
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_DRVW_ENABLE_MASKING_OPERATIONS */

/**
* @brief        This function will call CheckIdleState function of all configured hardware channels
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK            The Idle state is not ready
* @retval       E_OK                The Idle state is ready
*
*/
Std_ReturnType Pwm_Drvw_CheckIdleState(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint8 ChannelId;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if (PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        Mcpwm_Pwm_Drv_ChannelStateType Pwm_State = Mcpwm_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId);
        if(MCPWM_PWM_DRV_CHANNEL_RUNNING == Pwm_State)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }

#if (PWM_DRVW_NOTIFICATION_SUPPORTED == STD_ON)
        Mcpwm_Pwm_Drv_EdgeInterruptType Pwm_Notif = Mcpwm_Pwm_Drv_GetNotifFlag(ModuleId,ChannelId);
        if(MCPWM_PWM_DRV_NO_EDGE != Pwm_Notif)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif /* PWM_DRVW_NOTIFICATION_SUPPORTED */
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        ChannelId = ChnConfigPtr->TimChConfig->ChannelId;
        Tim_Pwm_Drv_ChannelStateType Pwm_State = Tim_Pwm_Drv_GetCurrentChannelState(ModuleId,ChannelId);
        if(TIM_PWM_DRV_CHANNEL_RUNNING == Pwm_State)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }

#if (PWM_DRVW_NOTIFICATION_SUPPORTED == STD_ON)
        Tim_Pwm_Drv_EdgeInterruptType Pwm_Notif = Tim_Pwm_Drv_GetNotifFlag(ModuleId,ChannelId);
        if(TIM_PWM_DRV_NO_EDGE != Pwm_Notif)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif /* PWM_DRVW_NOTIFICATION_SUPPORTED */
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}

#if (PWM_DRVW_LOW_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        This function will call SetPowerState function of all configured hardware modules
*
* @param[in]    HwCfgPtr        Pointer to PWM module configuration structure
* @param[in]    PowerState      Target power mode
*
* @return       void
*
*/
void Pwm_Drvw_SetPowerState(const Pwm_Drvw_HwConfigType * const HwCfgPtr,
                                                        Pwm_Drvw_PowerStateType PowerState)
{
    switch(HwCfgPtr->HwType)
    {
        case PWM_DRVW_HW_MCPWM:
            if (NULL_PTR != HwCfgPtr->McpwmHwConfig)
            {
                if (PWM_DRVW_FULL_POWER == PowerState)
                {
                    Mcpwm_Pwm_Drv_SetPowerState(HwCfgPtr->HwId,MCPWM_PWM_DRV_FULL_POWER);
                }
                else
                {
                    Mcpwm_Pwm_Drv_SetPowerState(HwCfgPtr->HwId,MCPWM_PWM_DRV_LOW_POWER);
                }
            }
            break;

        case PWM_DRVW_HW_TIM:
            if (NULL_PTR != HwCfgPtr->TimHwConfig)
            {
                if (PWM_DRVW_FULL_POWER == PowerState)
                {
                    Tim_Pwm_Drv_SetPowerState(HwCfgPtr->HwId,TIM_PWM_DRV_FULL_POWER);
                }
                else
                {
                    Tim_Pwm_Drv_SetPowerState(HwCfgPtr->HwId,TIM_PWM_DRV_LOW_POWER);
                }
            }
            break;

        case PWM_DRVW_HW_NONE:
        default:
            (void)PowerState;
            break;
    }
}
#endif /* PWM_DRVW_LOW_POWER_STATE_SUPPORTED */

#if (PWM_DRVW_MAX_PERIOD_PLAUSABILITY == STD_ON)
    #if ((PWM_DRVW_SET_PERIOD_AND_DUTY_API               == STD_ON) || \
         (PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API   == STD_ON) || \
         (PWM_DRVW_SET_PHASE_SHIFT_TICKS_API             == STD_ON) || \
         (PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON))
/**
* @brief        Get the maximum period in physical hardware channels.
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       uint32              Max period value
*
*/
uint32 Pwm_Drvw_GetMaxPeriodValue(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    uint32 RetVal;

    switch(ChnConfigPtr->ChnHwType)
    {

        case PWM_DRVW_HW_MCPWM:
            RetVal = (uint32)65534U;
            break;

        case PWM_DRVW_HW_TIM:
            RetVal = (uint32)65534U;
            break;
            
        case PWM_DRVW_HW_NONE:
        default:
            RetVal = (uint32)65535U;
            break;
    }

    return RetVal;
}
    #endif /* (PWM_DRVW_SET_PERIOD_AND_DUTY_API || PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API || \
               PWM_DRVW_SET_PHASE_SHIFT_TICKS_API || PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API) */
#endif /* PWM_DRVW_MAX_PERIOD_PLAUSABILITY */

#if (PWM_DRVW_DEV_ERROR_DETECT == STD_ON)
    #if (PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON)
/**
* @brief        This function will check operation mode of current channel to use deadtime feature.
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK        Current channel DeadTime mode is invalid
* @retval       E_OK            Current channel DeadTime mode is valid
*
*/
Std_ReturnType Pwm_Drvw_CheckDeadTimeMode(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{

    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    
    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {        
        const Mcpwm_Pwm_Drv_PairChannelCfgType* McpwmPairCfg = 
            ((const Mcpwm_Pwm_Drv_ChannelConfigType*) ChnConfigPtr->McpwmChConfig)->PairCfg;

        if(NULL_PTR != McpwmPairCfg)
        {
            if((TRUE == McpwmPairCfg->DeadTimeEnable))
            {
                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {         
        const Tim_Pwm_Drv_PairChannelCfgType* TimPairCfg = 
            ((const Tim_Pwm_Drv_ChannelConfigType*) ChnConfigPtr->TimChConfig)->PairCfg;

        if(NULL_PTR != TimPairCfg)
        {
            if((TRUE == TimPairCfg->DeadTimeEnable))
            {
                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }
    else
    {
        /* Nothing to do. */
    }

    return RetVal;
}

    #endif /* PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API */

    #if (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function will check phase shift ticks and duty cycle per unit value
*
* @param[in]    PhaseShiftTicks     Phase shift ticks value
* @param[in]    DutyCyclePu         Duty Cycle value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            Params is invalid
* @retval       E_OK                Params is valid
*
*/
Std_ReturnType Pwm_Drvw_CheckSetDutyPhaseShiftParams(uint16 PhaseShiftTicks, uint16 DutyCyclePu,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint8 ModuleId = ChnConfigPtr->ChnHwId;
    uint16 CnVValue = 0U;
    uint16 CurrentPeriod;
    uint16 DutyTicks;
    uint16 DutyCycle = PWM_DRVW_DUTY_CYCLE_100 - DutyCyclePu;

    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {    
        uint8 ChannelId = ChnConfigPtr->McpwmChConfig->ChannelId;
        CurrentPeriod = Mcpwm_Pwm_Drv_GetPeriod(ModuleId, ChannelId);
        DutyTicks = (uint16)((uint32)((uint32)CurrentPeriod * DutyCycle) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);
        if ((MCPWM_PWM_DRV_MAX_DUTY_CYCLE != DutyCyclePu) && (0U != DutyCyclePu))
        {
            CnVValue = PhaseShiftTicks + DutyTicks;

            if ((CnVValue > PhaseShiftTicks) && (CurrentPeriod > CnVValue))
            {
                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }
    else
    {
        CurrentPeriod = Tim_Pwm_Drv_GetPeriod(ModuleId);
        DutyTicks = (uint16)((uint32)((uint32)CurrentPeriod * DutyCycle) >> 
                                                            PWM_DRVW_DUTY_CYCLE_CALC_SHIFT);
        if ((TIM_PWM_DRV_MAX_DUTY_CYCLE != DutyCyclePu) && (0U != DutyCyclePu))
        {
            CnVValue = PhaseShiftTicks + DutyTicks;

            if ((CnVValue > PhaseShiftTicks) && (CurrentPeriod > CnVValue))
            {
                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }

    return RetVal;
}
    #endif /* PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API */
#endif /* PWM_DRVW_DEV_ERROR_DETECT */

/**
* @brief        This function is used to init the idle output state of Hardware.
*
* @param[in]    State The output idle state of the hardware channel 
* @param[in]    ChnConfigPtr Pointer to Pwm channel configuration structure
*
* @return       void
*/
void Pwm_Drvw_InitIdleState(Pwm_Drvw_OutputStateType State,
                                     const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr)
{  
    if(PWM_DRVW_HW_MCPWM == ChnConfigPtr->ChnHwType)
    {    
        Pwm_Drvw_InitMcpwmIdleState(State, ChnConfigPtr);
    }
    else if(PWM_DRVW_HW_TIM == ChnConfigPtr->ChnHwType)
    {
        Pwm_Drvw_InitTimIdleState(State, ChnConfigPtr);
    }
    else
    {
        /* Nothing to do. */
    }
}

/** @} end of group Public_FunctionDefinition */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Pwm_Drvw */

/** @} end of group Pwm_Module */
