/**
 * @file    Pwm_Lld_Etmr.C
 * @version V2.3.0
 *
 * @brief   YUNTU Pwm_Mld module interface
 * @details API implementation for Pwm_Mld driver
 *
 * @addtogroup PWM_MLD_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR, MPWM
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                         INCLUDE FILES
=================================================================================================*/
#include "Pwm_Mld.h"
#if (PWM_ETMR_USED == STD_ON)
#include "Pwm_Lld_Etmr.h"
#endif
#if (PWM_MPWM_USED == STD_ON)
#include "Pwm_Lld_Mpwm.h"
#endif
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
#include "OsIf.h"
#endif

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_MLD_VENDOR_ID_C                      (180)
#define PWM_MLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PWM_MLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define PWM_MLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define PWM_MLD_SW_MAJOR_VERSION_C               (2)
#define PWM_MLD_SW_MINOR_VERSION_C               (3)
#define PWM_MLD_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Mld.c and Pwm_Mld.h are of the same vendor */
#if (PWM_MLD_VENDOR_ID_C != PWM_MLD_VENDOR_ID)
#error "Pwm_Mld.c and Pwm_Mld.h have different vendor ids"
#endif
/* Check if Pwm_Mld.c and Pwm_Mld.h are of the same Autosar version */
#if ((PWM_MLD_AR_RELEASE_MAJOR_VERSION_C != PWM_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_MINOR_VERSION_C != PWM_MLD_AR_RELEASE_MINOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_REVISION_VERSION_C != PWM_MLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Mld.c and Pwm_Mld.h are different"
#endif
/* Check if Pwm_Mld.c and Pwm_Mld.h are of the same Software version */
#if ((PWM_MLD_SW_MAJOR_VERSION_C != PWM_MLD_SW_MAJOR_VERSION) || \
     (PWM_MLD_SW_MINOR_VERSION_C != PWM_MLD_SW_MINOR_VERSION) || \
     (PWM_MLD_SW_PATCH_VERSION_C != PWM_MLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Mld.c and Pwm_Mld.h are different"
#endif

#if (PWM_ETMR_USED == STD_ON)
/* Check if Pwm_Mld.c and Pwm_Lld_Etmr.h are of the same vendor */
#if (PWM_MLD_VENDOR_ID_C != PWM_LLD_ETMR_VENDOR_ID)
#error "Pwm_Mld.c and Pwm_Lld_Etmr.h have different vendor ids"
#endif
/* Check if Pwm_Mld.c and Pwm_Lld_Etmr.h are of the same Autosar version */
#if ((PWM_MLD_AR_RELEASE_MAJOR_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_MINOR_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_REVISION_VERSION_C != PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Mld.c and Pwm_Lld_Etmr.h are different"
#endif
/* Check if Pwm_Mld.c and Pwm_Lld_Etmr.h are of the same Software version */
#if ((PWM_MLD_SW_MAJOR_VERSION_C != PWM_LLD_ETMR_SW_MAJOR_VERSION) || \
     (PWM_MLD_SW_MINOR_VERSION_C != PWM_LLD_ETMR_SW_MINOR_VERSION) || \
     (PWM_MLD_SW_PATCH_VERSION_C != PWM_LLD_ETMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Mld.c and Pwm_Lld_Etmr.h are different"
#endif
#endif /* PWM_ETMR_USED == STD_ON */

#if (PWM_MPWM_USED == STD_ON)
/* Check if Pwm_Mld.c and Pwm_Lld_Mpwm.h are of the same vendor */
#if (PWM_MLD_VENDOR_ID_C != PWM_LLD_MPWM_VENDOR_ID)
#error "Pwm_Mld.c and Pwm_Lld_Mpwm.h have different vendor ids"
#endif
/* Check if Pwm_Mld.c and Pwm_Lld_Mpwm.h are of the same Autosar version */
#if ((PWM_MLD_AR_RELEASE_MAJOR_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_MINOR_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_MLD_AR_RELEASE_REVISION_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Mld.c and Pwm_Lld_Mpwm.h are different"
#endif
/* Check if Pwm_Mld.c and Pwm_Lld_Mpwm.h are of the same Software version */
#if ((PWM_MLD_SW_MAJOR_VERSION_C != PWM_LLD_MPWM_SW_MAJOR_VERSION) || \
     (PWM_MLD_SW_MINOR_VERSION_C != PWM_LLD_MPWM_SW_MINOR_VERSION) || \
     (PWM_MLD_SW_PATCH_VERSION_C != PWM_LLD_MPWM_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Mld.c and Pwm_Lld_Mpwm.h are different"
#endif
#endif /* PWM_MPWM_USED == STD_ON */

/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 * @brief       This function initializes the PWM MLD instance.
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_InitInstance(const Pwm_Mld_InstCfgType *const InstCfg)
{
    switch (InstCfg->InstType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_INST_ETMR:
            if (NULL_PTR != InstCfg->EtmrInstCfg)
            {
                /* Call eTMR LLD initialize instances */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call2params
                (
                    Pwm_Lld_Etmr_InitInstance,
                    InstCfg->InstId,
                    InstCfg->EtmrInstCfg
                );
#else
                Pwm_Lld_Etmr_InitInstance
                (
                    InstCfg->InstId,
                    InstCfg->EtmrInstCfg
                );
#endif
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_INST_MPWM:
            /* Do nothing. */
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}

/**
 * @brief       This function initializes the PWM MLD channel.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_InitChannel(const Pwm_Mld_ChCfgType *const ChCfg)
{
    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            if (NULL_PTR != ChCfg->EtmrChCfg)
            {
                /* Call eTMR LLD initialize function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call2params
                (
                    Pwm_Lld_Etmr_InitChannel,
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg
                );
#else
                Pwm_Lld_Etmr_InitChannel
                (
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg
                );
#endif
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            if (NULL_PTR != ChCfg->MpwmChCfg)
            {
                /* Call MPWM LLD initialize function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call2params
                (
                    Pwm_Lld_Mpwm_InitChannel,
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg
                );
#else
                Pwm_Lld_Mpwm_InitChannel
                (
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg
                );
#endif
            }
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}

#if (PWM_DEINIT_API == STD_ON)
/**
 * @brief       This function de-initializes the PWM MLD instance.
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_DeInitInstance(const Pwm_Mld_InstCfgType *const InstCfg)
{
    switch (InstCfg->InstType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_INST_ETMR:
            if (NULL_PTR != InstCfg->EtmrInstCfg)
            {
                /* Call eTMR LLD initialize instances */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call1param
                (
                    Pwm_Lld_Etmr_DeInitInstance,
                    InstCfg->InstId
                );
#else
                Pwm_Lld_Etmr_DeInitInstance
                (
                    InstCfg->InstId
                );
#endif
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_INST_MPWM:
            /* Do nothing. */
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}

/**
 * @brief       This function de-initializes the specified PWM MLD channel.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_DeInitChannel(const Pwm_Mld_ChCfgType *const ChCfg)
{
    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            if (NULL_PTR != ChCfg->EtmrChCfg)
            {
                /* Call eTMR LLD de-initialize channel function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call2params
                (
                    Pwm_Lld_Etmr_DeInitChannel,
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg
                );
#else
                Pwm_Lld_Etmr_DeInitChannel
                (
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg
                );
#endif
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            if (NULL_PTR != ChCfg->MpwmChCfg)
            {
                /* Call MPWM LLD de-initialize channel function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call2params
                (
                    Pwm_Lld_Mpwm_DeInitChannel,
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg
                );
#else
                Pwm_Lld_Mpwm_DeInitChannel
                (
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg
                );
#endif
            }
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}
#endif /* PWM_DEINIT_API == STD_ON */

#if (PWM_SET_DUTY_CYCLE == STD_ON)
/**
 * @brief       This function sets the duty cycle of the specified PWM MLD channel.
 * @param[in]   DutyCycle The duty cycle value.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_SetDutyCycle(uint16 DutyCycle, const Pwm_Mld_ChCfgType *const ChCfg)
{
    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            if (NULL_PTR != ChCfg->EtmrChCfg)
            {
                /* Call eTMR LLD set duty cycle function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call3params
                (
                    Pwm_Lld_Etmr_SetDutyCycle,
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg->ChannelId,
                    DutyCycle
                );
#else
                Pwm_Lld_Etmr_SetDutyCycle
                (
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg->ChannelId,
                    DutyCycle
                );
#endif
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            if (NULL_PTR != ChCfg->MpwmChCfg)
            {
                /* Call MPWM LLD set duty cycle function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call3params
                (
                    Pwm_Lld_Mpwm_SetDutyCycle,
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg->ChannelId,
                    DutyCycle
                );
#else
                Pwm_Lld_Mpwm_SetDutyCycle
                (
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg->ChannelId,
                    DutyCycle
                );
#endif
            }
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}
#endif

#if (PWM_SET_PERIOD_AND_DUTY == STD_ON)
/**
 * @brief       This function sets the period and duty cycle of the specified PWM MLD channel.
 * @param[in]   Period The period value.
 * @param[in]   DutyCycle The duty cycle value.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_SetPeriodAndDuty
(
    Pwm_PeriodType Period,
    uint16 DutyCycle,
    const Pwm_Mld_ChCfgType *const ChCfg
)
{
    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            if (NULL_PTR != ChCfg->EtmrChCfg)
            {
                /* Call eTMR LLD set period and duty cycle function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call4params
                (
                    Pwm_Lld_Etmr_SetPeriodAndDuty,
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg->ChannelId,
                    Period,
                    DutyCycle
                );
#else
                Pwm_Lld_Etmr_SetPeriodAndDuty
                (
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg->ChannelId,
                    Period,
                    DutyCycle
                );
#endif
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            if (NULL_PTR != ChCfg->MpwmChCfg)
            {
                /* Call MPWM LLD set period and duty cycle function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call4params
                (
                    Pwm_Lld_Mpwm_SetPeriodAndDuty,
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg->ChannelId,
                    Period,
                    DutyCycle
                );
#else
                Pwm_Lld_Mpwm_SetPeriodAndDuty
                (
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg->ChannelId,
                    Period,
                    DutyCycle
                );
#endif
            }
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}
#endif

#if (PWM_SET_OUTPUT_TO_IDLE == STD_ON)
/**
 * @brief       This function sets the output to idle state.
 * @param[in]   IdleState The output state.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Mld_SetOutputToIdle
(
    Pwm_OutputStateType IdleState,
    const Pwm_Mld_ChCfgType *const ChCfg
)
{
    (void)IdleState;
    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            if (NULL_PTR != ChCfg->EtmrChCfg)
            {
                /* Call eTMR LLD set output to idle function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call3params
                (
                    Pwm_Lld_Etmr_SetOutputToIdle,
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg->ChannelId,
                    ChCfg->EtmrChCfg->IdleState
                );
#else
                Pwm_Lld_Etmr_SetOutputToIdle
                (
                    ChCfg->ChInstId,
                    ChCfg->EtmrChCfg->ChannelId,
                    ChCfg->EtmrChCfg->IdleState
                );
#endif
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            if (NULL_PTR != ChCfg->MpwmChCfg)
            {
                /* Call MPWM LLD set output to idle function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call3params
                (
                    Pwm_Lld_Mpwm_SetOutputToIdle,
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg->ChannelId,
                    ChCfg->MpwmChCfg->IdleState
                );
#else
                Pwm_Lld_Mpwm_SetOutputToIdle
                (
                    ChCfg->ChInstId,
                    ChCfg->MpwmChCfg->ChannelId,
                    ChCfg->MpwmChCfg->IdleState
                );
#endif
            }
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}
#endif

#if (PWM_GET_OUTPUT_STATE == STD_ON)
/**
 * @brief       This function gets the output state of the specified PWM MLD channel.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      The output state.
 * @retval      PWM_LOW The output is low.
 * @retval      PWM_HIGH The output is high.
 */
PWM_FUNC Pwm_OutputStateType Pwm_Mld_GetOutputState(const Pwm_Mld_ChCfgType *const ChCfg)
{
    Pwm_OutputStateType Ret = PWM_LOW;
#if (PWM_ETMR_USED == STD_ON)
    Pwm_Lld_Etmr_OutputStateType EtmrOutputState;
#endif
#if (PWM_MPWM_USED == STD_ON)
    Pwm_Lld_Mpwm_OutputStateType MpwmOutputState;
#endif

    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            if (NULL_PTR != ChCfg->EtmrChCfg)
            {
                /* Call eTMR LLD get output state function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                EtmrOutputState = (Pwm_Lld_Etmr_OutputStateType)OsIf_Trusted_Call_Return2param
                                  (
                                      Pwm_Lld_Etmr_GetOutputState,
                                      ChCfg->ChInstId,
                                      ChCfg->EtmrChCfg->ChannelId
                                  );
#else
                EtmrOutputState = Pwm_Lld_Etmr_GetOutputState
                                  (
                                      ChCfg->ChInstId,
                                      ChCfg->EtmrChCfg->ChannelId
                                  );
#endif
                /* Convert output state */
                if (PWM_LLD_ETMR_OUTPUT_STATE_LOW == EtmrOutputState)
                {
                    Ret = PWM_LOW;
                }
                else
                {
                    Ret = PWM_HIGH;
                }
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            if (NULL_PTR != ChCfg->MpwmChCfg)
            {
                /* Call MPWM LLD get output state function */
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
                MpwmOutputState = (Pwm_Lld_Mpwm_OutputStateType)OsIf_Trusted_Call_Return2param
                                  (
                                      Pwm_Lld_Mpwm_GetOutputState,
                                      ChCfg->ChInstId,
                                      ChCfg->MpwmChCfg->ChannelId
                                  );
#else
                MpwmOutputState = Pwm_Lld_Mpwm_GetOutputState
                                  (
                                      ChCfg->ChInstId,
                                      ChCfg->MpwmChCfg->ChannelId
                                  );
#endif
                /* Convert output state */
                if (PWM_LLD_MPWM_OUTPUT_STATE_LOW == MpwmOutputState)
                {
                    Ret = PWM_LOW;
                }
                else
                {
                    Ret = PWM_HIGH;
                }
            }
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }

    return Ret;
}
#endif

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
 * @brief       This function is used to update the dead time at runtime for Pwm channels.
 * @param[in]   DeadTimeTicks dead time value
 * @param[in]   ChCfg Pointer to PWM top configuration structure
 * @return      void
 */
void Pwm_Mld_SetChannelDeadTime(uint16 DeadTimeTicks, const Pwm_Mld_ChCfgType *const ChCfg)
{
    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
#ifdef PWM_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call3params
            (
                Pwm_Lld_Etmr_SetChannelDeadTime,
                ChCfg->ChInstId,
                ChCfg->EtmrChCfg->ChannelId,
                DeadTimeTicks
            );
#else
            Pwm_Lld_Etmr_SetChannelDeadTime
            (
                ChCfg->ChInstId,
                ChCfg->EtmrChCfg->ChannelId,
                DeadTimeTicks
            );
#endif
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            /* Do nothing. */
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            /* Do nothing. */
            break;
    }
}
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
#if (PWM_SET_OUTPUT_TO_IDLE == STD_ON)
/**
 * @brief       This function will check the validation when calling the Pwm_SetOutputToIdle api.
 * @param[in]   ChCfg Pointer to PWM top configuration structure
 * @return      Std_ReturnType
 * @retval      E_NOT_OK Set output to idle is not valid
 * @retval      E_OK Set output to idle is valid
 */
PWM_FUNC Std_ReturnType Pwm_Mld_ValidateSetOutPutToIdle(const Pwm_Mld_ChCfgType *const ChCfg)
{
    Std_ReturnType Ret;

    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            Ret = E_OK;
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            Ret = E_OK;
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            Ret = E_NOT_OK;
            break;
    }

    return Ret;
}
#endif

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
 * @brief       This function will check validate operation mode of current channel to use
 *              dead time feature.
 * @param[in]   ChCfg Pointer to PWM top configuration structure
 * @return      Std_ReturnType
 * @retval      E_NOT_OK Current channel mode is invalid
 * @retval      E_OK Current channel mode is valid
 */
PWM_FUNC Std_ReturnType Pwm_Mld_ValidateDeadTime(const Pwm_Mld_ChCfgType *const ChCfg)
{
    Std_ReturnType Ret = E_NOT_OK;

    switch (ChCfg->ChType)
    {
#if (PWM_ETMR_USED == STD_ON)
        case PWM_MLD_CHN_ETMR:
            if (PWM_LLD_ETMR_MODE_COMPLEMENTARY == ChCfg->EtmrChCfg->ChMode)
            {
                Ret = E_OK;
            }
            break;
#endif /* PWM_ETMR_USED == STD_ON */
#if (PWM_MPWM_USED == STD_ON)
        case PWM_MLD_CHN_MPWM:
            Ret = E_NOT_OK;
            break;
#endif /* PWM_MPWM_USED == STD_ON */
        default:
            Ret = E_NOT_OK;
            break;
    }

    return Ret;
}
#endif
#endif /* PWM_DEV_ERROR_DETECT == STD_ON */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

