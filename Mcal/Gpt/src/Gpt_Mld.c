/**
 * @file    Gpt_Mld.c
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr, Ptmr, Tmr, Rtc
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
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 4322 Rule 10.5: The value of an expression should not be cast to an inappropriate essential type.
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Mld.h"
#if (GPT_TMR_MODULE_USED == STD_ON)
#include "Gpt_Lld_Tmr.h"
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
#include "Gpt_Lld_Ptmr.h"
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
#include "Gpt_Lld_Lptmr.h"
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
#include "Gpt_Lld_Rtc.h"
#endif
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
#include "OsIf.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_MLD_VENDOR_ID_C                      (180)
#define GPT_MLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_MLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_MLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_MLD_SW_MAJOR_VERSION_C               (2)
#define GPT_MLD_SW_MINOR_VERSION_C               (3)
#define GPT_MLD_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT_MLD header file are of the same vendor */
#if (GPT_MLD_VENDOR_ID_C != GPT_MLD_VENDOR_ID)
#error "Gpt_Mld.c and Gpt_Mld.h have different vendor ids"
#endif

/* Check if source file and GPT_MLD header file are of the same Autosar version */
#if ((GPT_MLD_AR_RELEASE_MAJOR_VERSION_C != GPT_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_MLD_AR_RELEASE_MINOR_VERSION_C != GPT_MLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_MLD_AR_RELEASE_REVISION_VERSION_C != GPT_MLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Mld.c and Gpt_Mld.h are different"
#endif

/* Check if source file and GPT_MLD header file are of the same Software version */
#if ((GPT_MLD_SW_MAJOR_VERSION_C != GPT_MLD_SW_MAJOR_VERSION) || \
     (GPT_MLD_SW_MINOR_VERSION_C != GPT_MLD_SW_MINOR_VERSION) || \
     (GPT_MLD_SW_PATCH_VERSION_C != GPT_MLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Mld.c and Gpt_Mld.h are different"
#endif

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

extern GPT_VAR Gpt_ModeType Gpt_Mode;

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief       Initializes the Tmr Mld driver.
 */
#if (GPT_TMR_MODULE_USED == STD_ON)
GPT_FUNC static void Gpt_Mld_TmrChannelInit(const Gpt_ChannelConfigType *GptChannelConfigPtr, Tmr_ChannelConfigType *TmrChannelConfig)
{
    TmrChannelConfig->HwInstanceId = GptChannelConfigPtr->GptHwChannelConfig->HwInstanceId;
    TmrChannelConfig->HwChannelId = GptChannelConfigPtr->GptHwChannelConfig->HwChannelId;
    /*
     * MR12 RULE 10.2 VIOLATION : In order to make the code of each layer have better readability,
     * the CountMode of Gpt_ChannelModeType passed in the top layer is converted to the CountMode
     * of Tmr_ChannelModeType in the LLd layer. The contents of both enumerated types are CONTINUOUS
     * and ONESHOT, so this writing has no effect on the running of the code.
     */
    TmrChannelConfig->CountMode = (Tmr_ChannelModeType)GptChannelConfigPtr->CountMode;    /* PRQA S 4322 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    TmrChannelConfig->EnableNotification = FALSE;
    TmrChannelConfig->NotificationPtr = GptChannelConfigPtr->NotificationPtr;
#else
    TmrChannelConfig->EnableNotification = FALSE;
    TmrChannelConfig->NotificationPtr = NULL_PTR;
#endif
    Gpt_Lld_Tmr_InitChannel(TmrChannelConfig);
}
#endif

/**
 * @brief       Initializes the Ptmr Mld Channel.
 */
#if (GPT_PTMR_MODULE_USED == STD_ON)
GPT_FUNC static void Gpt_Mld_PtmrChannelInit(const Gpt_ChannelConfigType *GptChannelConfigPtr, Ptmr_ChannelConfigType *PtmrChannelConfig)
{
    PtmrChannelConfig->HwInstanceId = GptChannelConfigPtr->GptHwChannelConfig->HwInstanceId;
    PtmrChannelConfig->HwChannelId = GptChannelConfigPtr->GptHwChannelConfig->HwChannelId;
    /*
     * MR12 RULE 10.2 VIOLATION : In order to make the code of each layer have better readability,
     * the CountMode of Gpt_ChannelModeType passed in the top layer is converted to the CountMode
     * of Ptmr_ChannelModeType in the LLd layer. The contents of both enumerated types are CONTINUOUS
     * and ONESHOT, so this writing has no effect on the running of the code.
     */
    PtmrChannelConfig->CountMode = (Ptmr_ChannelModeType)GptChannelConfigPtr->CountMode;    /* PRQA S 4322 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    PtmrChannelConfig->EnableNotification = FALSE;
    PtmrChannelConfig->NotificationPtr = GptChannelConfigPtr->NotificationPtr;
#else
    PtmrChannelConfig->EnableNotification = FALSE;
    PtmrChannelConfig->NotificationPtr = NULL_PTR;

#endif
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Gpt_Lld_Ptmr_InitChannel,(PtmrChannelConfig));
#else
    Gpt_Lld_Ptmr_InitChannel(PtmrChannelConfig);
#endif
}
#endif

/**
 * @brief       Initializes the Lptmr Mld driver.
 */
#if (GPT_LPTMR_MODULE_USED == STD_ON)
GPT_FUNC static void Gpt_Mld_LptmrInit(const Gpt_ChannelConfigType *GptChannelConfigPtr, Lptmr_ConfigType *LptmrConfig)
{
    /*
     * MR12 RULE 10.2 VIOLATION : In order to make the code of each layer have better readability,
     * the CountMode of Gpt_ChannelModeType passed in the top layer is converted to the CountMode
     * of Lptmr_ModeType in the LLd layer. The contents of both enumerated types are CONTINUOUS
     * and ONESHOT, so this writing has no effect on the running of the code.
     */
    LptmrConfig->CountMode = (Lptmr_ModeType)GptChannelConfigPtr->CountMode;    /* PRQA S 4322 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    LptmrConfig->EnableNotification = FALSE;
    LptmrConfig->NotificationPtr = GptChannelConfigPtr->NotificationPtr;
#else
    LptmrConfig->EnableNotification = FALSE;
    LptmrConfig->NotificationPtr = NULL_PTR;
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    LptmrConfig->EnableWakeup = FALSE;
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    LptmrConfig->WakeupSource = GptChannelConfigPtr->WakeupSource;
#endif
#endif
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Gpt_Lld_Lptmr_Init,(LptmrConfig));
#else
    Gpt_Lld_Lptmr_Init(LptmrConfig);
#endif
}
#endif

/**
 * @brief       Initializes the Rtc Mld driver.
 */
#if (GPT_RTC_MODULE_USED == STD_ON)
GPT_FUNC static void Gpt_Mld_RtcInit(const Gpt_ChannelConfigType *GptChannelConfigPtr, Rtc_ConfigType *RtcConfig)
{
    /*
     * MR12 RULE 10.2 VIOLATION : In order to make the code of each layer have better readability,
     * the CountMode of Gpt_ChannelModeType passed in the top layer is converted to the CountMode
     * of Rtc_ModeType in the LLd layer. The contents of both enumerated types are CONTINUOUS
     * and ONESHOT, so this writing has no effect on the running of the code.
     */
    RtcConfig->CountMode = (Rtc_ModeType)GptChannelConfigPtr->CountMode;    /* PRQA S 4322 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    RtcConfig->EnableNotification = FALSE;
    RtcConfig->NotificationPtr = GptChannelConfigPtr->NotificationPtr;
#else
    RtcConfig->EnableNotification = FALSE;
    RtcConfig->NotificationPtr = NULL_PTR;
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    RtcConfig->EnableWakeup = FALSE;
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    RtcConfig->WakeupSource = GptChannelConfigPtr->WakeupSource;
#endif
#endif
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Gpt_Lld_Rtc_Init,(RtcConfig));
#else
    Gpt_Lld_Rtc_Init(RtcConfig);
#endif
}
#endif

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief        Initializes the GPT Instances.
* @param[in]    configPtr    Pointer to the Gpt configuration structure.
* @return       void
*/
GPT_FUNC void Gpt_Mld_InitInstances(const Gpt_ConfigType * ConfigPtr)
{
    for (uint16 InstanceIndex = 0; InstanceIndex < ConfigPtr->UsedInstanceCount; ++InstanceIndex)
    {
        switch ((*(ConfigPtr->InstanceConfig))[InstanceIndex].InstanceType)
        {
#if (GPT_PTMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_PTMR:
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_Ptmr_InitInstance, (((*(ConfigPtr->InstanceConfig))[InstanceIndex]).PtmrInstCfg));
#else
            Gpt_Lld_Ptmr_InitInstance(((*(ConfigPtr->InstanceConfig))[InstanceIndex]).PtmrInstCfg);
#endif
            break;
        }
#endif
#if (GPT_TMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_TMR:
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_Tmr_InitInstance, (*(ConfigPtr->InstanceConfig))[InstanceIndex].TmrInstCfg);
            OsIf_Trusted_Call1param(Gpt_Lld_Tmr_Start, (*(ConfigPtr->InstanceConfig))[InstanceIndex].HwInstanceId);
#else
            Gpt_Lld_Tmr_InitInstance((*(ConfigPtr->InstanceConfig))[InstanceIndex].TmrInstCfg);
            Gpt_Lld_Tmr_Start((*(ConfigPtr->InstanceConfig))[InstanceIndex].HwInstanceId);
#endif
            break;
        }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_LptmrInitInstance, (*(ConfigPtr->InstanceConfig))[InstanceIndex].LptmrInstCfg);
#else
            Gpt_Lld_LptmrInitInstance((*(ConfigPtr->InstanceConfig))[InstanceIndex].LptmrInstCfg);
#endif
            break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_RtcInitInstance, (*(ConfigPtr->InstanceConfig))[InstanceIndex].RtcInstCfg);
#else
            Gpt_Lld_RtcInitInstance((*(ConfigPtr->InstanceConfig))[InstanceIndex].RtcInstCfg);
#endif
            break;
#endif
        /*GCOVR_EXCL_START*/
        /*This branch cannot be executed due to parameter limitations*/
        default:
            /* Do nothing. */
            break;
        /*GCOVR_EXCL_STOP*/
        }
    }
}

/**
 * @brief       Initializes the GPT MLD driver.
* @param[in]    GptChannelConfigPtr    Pointer to the Gpt channel configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_Init(const Gpt_ChannelConfigType *GptChannelConfigPtr)
{
#if (GPT_TMR_MODULE_USED == STD_ON)
    Tmr_ChannelConfigType TmrChannelConfig;
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    Ptmr_ChannelConfigType PtmrChannelConfig;
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    Lptmr_ConfigType LptmrConfig;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    Rtc_ConfigType RtcConfig;
#endif
    /* channel initialization */
    switch (GptChannelConfigPtr->GptHwChannelConfig->InstanceType)
    {
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
        Gpt_Mld_LptmrInit(GptChannelConfigPtr, &LptmrConfig);
        break;
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
        Gpt_Mld_PtmrChannelInit(GptChannelConfigPtr, &PtmrChannelConfig);
        break;
#endif
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
        Gpt_Mld_TmrChannelInit(GptChannelConfigPtr, &TmrChannelConfig);
        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
        Gpt_Mld_RtcInit(GptChannelConfigPtr, &RtcConfig);
        break;
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Do nothing. */
        break;
    /*GCOVR_EXCL_STOP*/
    }
} /* Gpt_Mld_Init */

/**
 * @brief       De-Initializes the GPT MLD driver.
 * @param[in]   configPtr    Pointer to the Gpt configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Mld_DeInit(const Gpt_ConfigType *ConfigPtr)
{
    for (uint8 InstanceIndex = 0; InstanceIndex < ConfigPtr->UsedInstanceCount; ++InstanceIndex)
    {
        switch ((*(ConfigPtr->InstanceConfig))[InstanceIndex].InstanceType)
        {
#if (GPT_PTMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_PTMR:
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_Ptmr_DeInitInstance, (*(ConfigPtr->InstanceConfig))[InstanceIndex].HwInstanceId);
#else
            Gpt_Lld_Ptmr_DeInitInstance((*(ConfigPtr->InstanceConfig))[InstanceIndex].HwInstanceId);
#endif
            break;
        }
#endif
#if (GPT_TMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_TMR:
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_Tmr_DeInitInstance, (*(ConfigPtr->InstanceConfig))[InstanceIndex].HwInstanceId);
#else
            Gpt_Lld_Tmr_DeInitInstance((*(ConfigPtr->InstanceConfig))[InstanceIndex].HwInstanceId);
#endif
            break;
        }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_Lptmr_DeInit, 0U);
#else
            Gpt_Lld_Lptmr_DeInit(0U);
#endif
            break;
#endif

#if (GPT_RTC_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Gpt_Lld_Rtc_DeInit, 0U);
#else
            Gpt_Lld_Rtc_DeInit(0U);
#endif
            break;
#endif
        /*GCOVR_EXCL_START*/
        /*This branch cannot be executed due to parameter limitations*/
        default:
            /* Do nothing. */
            break;
        /*GCOVR_EXCL_STOP*/
        }
    }

    for (uint8 ChannelIndex = 0U; ChannelIndex < ConfigPtr->UsedChannelCount; ++ChannelIndex)
    {
        switch ((*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->InstanceType)
        {
#if (GPT_PTMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_PTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Ptmr_DeInitChannel,
                                     (*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwInstanceId,
                                     (*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwChannelId);
#else
            Gpt_Lld_Ptmr_DeInitChannel((*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwInstanceId,
                                       (*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwChannelId);
#endif
            break;
#endif
#if (GPT_TMR_MODULE_USED == STD_ON)
        case GPT_HW_MODULE_TMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Tmr_DeInitChannel,
                                     (*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwInstanceId,
                                     (*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwChannelId);
#else
            Gpt_Lld_Tmr_DeInitChannel((*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwInstanceId,
                                      (*(ConfigPtr->ChannelConfig))[ChannelIndex].GptHwChannelConfig->HwChannelId);
#endif
            break;
#endif
        default:
            /* Do nothing. */
            break;
        }
    }
} /* Gpt_Mld_DeInit */

/**
 * @brief       Starts a GPT MLD timer channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @param[in]   Value Target time in number of ticks.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_StartTimer(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr, Gpt_ValueType Value)
{
    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call3params(Gpt_Lld_Tmr_StartChannel,
                                 GptHwChannelConfigPtr->HwInstanceId,
                                 GptHwChannelConfigPtr->HwChannelId,
                                 ((Tmr_ValueType)Value));
#else
        Gpt_Lld_Tmr_StartChannel(GptHwChannelConfigPtr->HwInstanceId,
                                 GptHwChannelConfigPtr->HwChannelId,
                                 (Tmr_ValueType)Value);
#endif
        break;
    }
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call3params(Gpt_Lld_Ptmr_StartChannel,
                                 GptHwChannelConfigPtr->HwInstanceId,
                                 GptHwChannelConfigPtr->HwChannelId,
                                 (Ptmr_ValueType)Value);
#else
        Gpt_Lld_Ptmr_StartChannel(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId, (Ptmr_ValueType)Value);
#endif
        break;
    }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Gpt_Lld_Lptmr_StartTimer,((Lptmr_ValueType)Value));
#else
        Gpt_Lld_Lptmr_StartTimer((Lptmr_ValueType)Value);
#endif
        break;
#endif
#if (GPT_ETMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_ETMR:
        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Gpt_Lld_Rtc_StartTimer,((Rtc_ValueType)Value));
#else
        Gpt_Lld_Rtc_StartTimer((Rtc_ValueType)Value);
#endif
        break;
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Nothing to do. */
        break;
    /*GCOVR_EXCL_STOP*/
    }
}

/**
 * @brief       Stops a GPT MLD timer channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Mld_StopTimer(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
    /* If the function Gpt_StopTimer is called on a channel in state "initialized", "stopped"
       or "expired", the function shall not raise a development error.
       Trace : SWS_Gpt_00099 */
    /* If the function Gpt_StopTimer is called on a channel in state
       "initialized", "stopped" or "expired", the function shall leave without any action
       Trace : SWS_Gpt_00344 */

    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
    {
        /* Only "channel state in "running", stoptimer function action */
        if (TMR_CHANNEL_STATE_RUNNING == Gpt_Lld_Tmr_GetTimerState(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId))
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Tmr_StopChannel, GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#else
            Gpt_Lld_Tmr_StopChannel(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        }
        break;
    }
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
    {
        /* Only "channel state in "running", stoptimer function action */
        if (PTMR_CHANNEL_STATE_RUNNING == Gpt_Lld_Ptmr_GetTimerState(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId))
        {

#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Ptmr_StopChannel, GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#else
            Gpt_Lld_Ptmr_StopChannel(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        }
        break;
    }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
        /* Only "channel state in "running", stoptimer function action */
        if (LPTMR_STATE_RUNNING == Gpt_Lld_Lptmr_GetTimerState())
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call(Gpt_Lld_Lptmr_StopTimer);
#else
            Gpt_Lld_Lptmr_StopTimer();
#endif
        }
        break;
#endif
#if (GPT_ETMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_ETMR:
        ModuleChannelCount = ETMR_CHANNEL_COUNT;
        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
        /* Only "channel state in "running", stoptimer function action */
        if (RTC_STATE_RUNNING == Gpt_Lld_Rtc_GetTimerState())
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call(Gpt_Lld_Rtc_StopTimer);
#else
            Gpt_Lld_Rtc_StopTimer();
#endif
        }
        break;
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Nothing to do. */
        break;
    /*GCOVR_EXCL_STOP*/
    }
}

/**
 * @brief       Checks if the channel is valid.
 * @param[in]   configPtr Pointer to the Gpt configuration structure.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      Std_ReturnType
 * @retval      E_OK Channel is valid
 * @retval      E_NOT_OK Channel is not valid
 */
GPT_FUNC Std_ReturnType Gpt_Mld_CheckChannel(const Gpt_ConfigType *ConfigPtr, uint16 Channel)
{
    Std_ReturnType CheckResult = (Std_ReturnType)E_NOT_OK;

    if (Channel < ConfigPtr->UsedChannelCount)
    {
        CheckResult = (Std_ReturnType)E_OK;
    }

    return CheckResult;
}

/**
 * @brief       Returns the status of the GPT channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      Gpt_ChannelStatusType
 * @retval      GPT_STATUS_RUNNING Channel is running
 * @retval      GPT_STATUS_STOPPED Channel is stopped
 * @retval      GPT_STATUS_EXPIRED Channel is expired
 */
GPT_FUNC Gpt_ChannelStatusType Gpt_Mld_GetChannelState(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
    Gpt_ChannelStatusType ChannelState = GPT_STATUS_UNINITIALIZED;
    uint8 State = 0U;

    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
    {
        State = (uint8)Gpt_Lld_Tmr_GetTimerState(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
        ChannelState = (Gpt_ChannelStatusType)State;
        break;
    }
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
    {
        State = (uint8)Gpt_Lld_Ptmr_GetTimerState(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
        ChannelState = (Gpt_ChannelStatusType)State;
        break;
    }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
        State = (uint8)Gpt_Lld_Lptmr_GetTimerState();
        ChannelState = (Gpt_ChannelStatusType)State;
        break;
#endif
#if (GPT_ETMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_ETMR:
        (void)State;
        (void)ChannelState;
        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
        State = (uint8)Gpt_Lld_Rtc_GetTimerState();
        ChannelState = (Gpt_ChannelStatusType)State;
        break;
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Nothing to do. */
        (void)State;
        (void)ChannelState;
        break;
    /*GCOVR_EXCL_STOP*/
    }

    return ChannelState;
}

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief       Enables the interrupt notification for a channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Mld_EnableNotification(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
    {
        if(GPT_MODE_NORMAL == Gpt_Mode)
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Tmr_EnableNotification, GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#else
            Gpt_Lld_Tmr_EnableNotification(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        }
        break;
    }
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
    {
        if(GPT_MODE_NORMAL == Gpt_Mode)
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Ptmr_EnableNotification, GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#else
            Gpt_Lld_Ptmr_EnableNotification(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        }
        break;
    }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Lptmr_EnNotification);
#else
        Gpt_Lld_Lptmr_EnNotification();
#endif
        break;
#endif
#if (GPT_ETMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_ETMR:

        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Rtc_EnableNotification);
#else
        Gpt_Lld_Rtc_EnableNotification();
#endif
        break;
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Nothing to do. */
        break;
    /*GCOVR_EXCL_STOP*/
    }
}

/**
 * @brief       Disables the interrupt notification for a channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Mld_DisableNotification(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
    {
        if(GPT_MODE_NORMAL == Gpt_Mode)
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Tmr_DisableNotification, GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#else
            Gpt_Lld_Tmr_DisableNotification(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        }
        break;
    }
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
    {
        if(GPT_MODE_NORMAL == Gpt_Mode)
        {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(Gpt_Lld_Ptmr_DisNotification, GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#else
            Gpt_Lld_Ptmr_DisNotification(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        }
        break;
    }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Lptmr_DisNotification);
#else
        Gpt_Lld_Lptmr_DisNotification();
#endif
        break;
    }
#endif
#if (GPT_ETMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_ETMR:

        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Rtc_DisableNotification);
#else
        Gpt_Lld_Rtc_DisableNotification();
#endif
        break;
    }
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Nothing to do. */
        break;
    /*GCOVR_EXCL_STOP*/
    }
}
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Disables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Mld_DisableWakeup(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Lptmr_DisableWakeup);
#else
        Gpt_Lld_Lptmr_DisableWakeup();
#endif
        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Rtc_DisableWakeup);
#else
        Gpt_Lld_Rtc_DisableWakeup();
#endif
        break;
#endif
    default:
        /* Nothing to do. */
        break;
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}

/**
 * @brief       Enables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Mld_EnableWakeup(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Lptmr_EnableWakeup);
#else
        Gpt_Lld_Lptmr_EnableWakeup();
#endif
        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Gpt_Lld_Rtc_EnableWakeup);
#else
        Gpt_Lld_Rtc_EnableWakeup();
#endif
        break;
#endif
    default:
        /* Nothing to do. */
        break;
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}

/**
 * @brief       Sets the operation mode of the GPT.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    OsIf_Trusted_Call1param(Gpt_Lld_Lptmr_SetMode,Mode);
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    OsIf_Trusted_Call1param(Gpt_Lld_Ptmr_SetMode,Mode);
#endif
#if (GPT_TMR_MODULE_USED == STD_ON)
    OsIf_Trusted_Call1param(Gpt_Lld_Tmr_SetMode,Mode);
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    OsIf_Trusted_Call1param(Gpt_Lld_Rtc_SetMode,Mode);
#endif
#else
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    Gpt_Lld_Lptmr_SetMode(Mode);
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    Gpt_Lld_Ptmr_SetMode(Mode);
#endif
#if (GPT_TMR_MODULE_USED == STD_ON)
    Gpt_Lld_Tmr_SetMode(Mode);
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    Gpt_Lld_Rtc_SetMode(Mode);
#endif
#endif
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}

/**
 * @brief       Checks if a wakeup capable GPT channel is the source for a wakeup event and calls
 *              the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel
 *              wakeup event.
 * @param[in]   WakeupSource Information on wakeup source to be checked. The associated GPT channel
 *              can be determined from configuration data.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_LPTMR_MODULE_USED == STD_ON)
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Gpt_Lld_Lptmr_CheckWakeup,WakeupSource);
#else
    Gpt_Lld_Lptmr_CheckWakeup(WakeupSource);
#endif
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Gpt_Lld_Rtc_CheckWakeup,WakeupSource);
#else
    Gpt_Lld_Rtc_CheckWakeup(WakeupSource);
#endif
#endif
#endif /* GPT_REPORT_WAKEUP_SOURCE == STD_ON */
}
#endif /*GPT_WAKEUP_FUNCTIONALITY_API*/

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief       Returns the time already elapsed.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      Gpt_ValueType
 */
GPT_FUNC Gpt_ValueType Gpt_Mld_GetTimeElapsed(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
    Gpt_ValueType TimeElapsed = 0;

    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeElapsed = (Gpt_ValueType)OsIf_Trusted_Call_Return2param(Gpt_Lld_Tmr_GetChTimeElapsed,
                      GptHwChannelConfigPtr->HwInstanceId,
                      GptHwChannelConfigPtr->HwChannelId);
#else
        TimeElapsed = (Gpt_ValueType)Gpt_Lld_Tmr_GetChTimeElapsed(GptHwChannelConfigPtr->HwInstanceId,
                      GptHwChannelConfigPtr->HwChannelId);
#endif
        break;
    }
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeElapsed = (Gpt_ValueType)OsIf_Trusted_Call_Return2param(Gpt_Lld_Ptmr_GetChTimeElapsed,
                      GptHwChannelConfigPtr->HwInstanceId,
                      GptHwChannelConfigPtr->HwChannelId);
#else
        TimeElapsed = (Gpt_ValueType)Gpt_Lld_Ptmr_GetChTimeElapsed(GptHwChannelConfigPtr->HwInstanceId,
                      GptHwChannelConfigPtr->HwChannelId);
#endif
        break;
    }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeElapsed = (Gpt_ValueType)OsIf_Trusted_Call_Return(Gpt_Lld_Lptmr_GetTimeElapsed);
#else
        TimeElapsed = (Gpt_ValueType)Gpt_Lld_Lptmr_GetTimeElapsed();
#endif
        break;
#endif
#if (GPT_ETMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_ETMR:

        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeElapsed = (Gpt_ValueType)OsIf_Trusted_Call_Return(Gpt_Lld_Rtc_GetTimeElapsed);
#else
        TimeElapsed = (Gpt_ValueType)Gpt_Lld_Rtc_GetTimeElapsed();
#endif
        break;
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Nothing to do. */
        break;
    /*GCOVR_EXCL_STOP*/
    }

    return TimeElapsed;
}
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief       Returns the time remaining until the target time is reached.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware channel configuration structure
 * @return      Gpt_ValueType
 */
GPT_FUNC Gpt_ValueType Gpt_Mld_GetTimeRemaining(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr)
{
    Gpt_ValueType TimeRemaining = 0;

    switch (GptHwChannelConfigPtr->InstanceType)
    {
#if (GPT_TMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_TMR:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeRemaining = (Gpt_ValueType)OsIf_Trusted_Call_Return2param(Gpt_Lld_Tmr_GetChTimeRemaining,
                        GptHwChannelConfigPtr->HwInstanceId,
                        GptHwChannelConfigPtr->HwChannelId);
#else
        TimeRemaining = Gpt_Lld_Tmr_GetChTimeRemaining(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        break;
    }
#endif
#if (GPT_PTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_PTMR:
    {
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeRemaining = (Gpt_ValueType)OsIf_Trusted_Call_Return2param(Gpt_Lld_Ptmr_GetChTimeRemaining,
                        GptHwChannelConfigPtr->HwInstanceId,
                        GptHwChannelConfigPtr->HwChannelId);
#else
        TimeRemaining = Gpt_Lld_Ptmr_GetChTimeRemaining(GptHwChannelConfigPtr->HwInstanceId, GptHwChannelConfigPtr->HwChannelId);
#endif
        break;
    }
#endif
#if (GPT_LPTMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_LPTMR:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeRemaining = (Gpt_ValueType)OsIf_Trusted_Call_Return(Gpt_Lld_Lptmr_GetTimeRemaining);
#else
        TimeRemaining = Gpt_Lld_Lptmr_GetTimeRemaining();
#endif
        break;
#endif
#if (GPT_ETMR_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_ETMR:
        break;
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
    case GPT_HW_MODULE_RTC:
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
        TimeRemaining = (Gpt_ValueType)OsIf_Trusted_Call_Return(Gpt_Lld_Rtc_GetTimeRemaining);
#else
        TimeRemaining = Gpt_Lld_Rtc_GetTimeRemaining();
#endif
        break;
#endif
    /*GCOVR_EXCL_START*/
    /*This branch cannot be executed due to parameter limitations*/
    default:
        /* Nothing to do. */
        break;
    /*GCOVR_EXCL_STOP*/
    }

    return TimeRemaining;
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

