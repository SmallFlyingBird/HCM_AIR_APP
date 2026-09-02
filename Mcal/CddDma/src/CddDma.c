/**
* @file    CddDma.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#include "Compiler.h"
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations List
 * PRQA S 0306 Rule 11.4: A conversion should not be performed between a pointer to object and an integer type.
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "CddDma.h"
#include "CddDma_Lld.h"
#include "SchM_CddDma.h"
#include "OsIf.h"

#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* CDDDMA_DEV_ERROR_DETECT == STD_ON */
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID_C                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION_C       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION_C    (0)
#define CDDDMA_SW_MAJOR_VERSION_C               (2)
#define CDDDMA_SW_MINOR_VERSION_C               (3)
#define CDDDMA_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CDDDMA header file are of the same vendor */
#if (CDDDMA_VENDOR_ID_C != CDDDMA_VENDOR_ID)
#error "CddDma.c and CddDma.h have different vendor ids"
#endif

/* Check if source file and CDDDMA header file are of the same Autosar version */
#if (( CDDDMA_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDDMA_AR_RELEASE_MINOR_VERSION_C != CDDDMA_AR_RELEASE_MINOR_VERSION) || \
      ( CDDDMA_AR_RELEASE_REVISION_VERSION_C != CDDDMA_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma.c and CddDma.h are different"
#endif

/* Check if source file and CDDDMA header file are of the same Software version */
#if (( CDDDMA_SW_MAJOR_VERSION_C != CDDDMA_SW_MAJOR_VERSION) || \
      ( CDDDMA_SW_MINOR_VERSION_C != CDDDMA_SW_MINOR_VERSION) || \
      ( CDDDMA_SW_PATCH_VERSION_C != CDDDMA_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma.c and CddDma.h are different"
#endif

/*==================================================================================================
                                                EXTERNAL VARIABLES
==================================================================================================*/
#if (CDDDMA_PRECOMPILE_SUPPORT == STD_ON)
extern const CddDma_ConfigType CddDma_PreCompileConfig;
#endif
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
 *                                          VARIATES
==================================================================================================*/

#define CDDDMA_START_SEC_VAR_INIT_UNSPECIFIED
#include "CddDma_MemMap.h"

CDDDMA_VAR static const CddDma_ConfigType *CddDma_ConfigPtr = NULL_PTR;

#define CDDDMA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CddDma_MemMap.h"

#define CDDDMA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddDma_MemMap.h"

/** @brief Global state to save information */
CDDDMA_VAR CddDma_ChannelStateType CddDma_State[CDDDMA_CHANNEL_CONFIG_COUNT];

#define CDDDMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddDma_MemMap.h"


/*==================================================================================================
 *                                   LOCAL FUNCTION DECLARATION
==================================================================================================*/

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define CDDDMA_START_SEC_CODE
#include "CddDma_MemMap.h"

#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0)
CDDDMA_FUNC static inline void Dma_Scts_ConfigSignalCount(CddDma_TransferConfigType *SctsConfigPtr,
        const CddDma_SoftwareCtsType *Scts, const boolean LoopMode)
{
    if (TRUE == LoopMode)
    {
        /* Link the software struct of CTS to itself */
        SctsConfigPtr->RamReloadEnable = TRUE;
        /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
         * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4
         */
        SctsConfigPtr->RamReloadNextDescAddr = (uint32)&Scts[0]; /* PRQA S 0306 */
    }
    else
    {
        SctsConfigPtr->RamReloadEnable = FALSE;
        SctsConfigPtr->RamReloadNextDescAddr = 0;
    }
    SctsConfigPtr->RamReloadIntEnable = TRUE;
}

CDDDMA_FUNC static inline void Dma_Scts_ConfigMultiCount(uint8 ReloadCount, CddDma_TransferConfigType *SctsConfigPtr,
        const CddDma_SoftwareCtsType *Scts, const uint8 CtsCount, const boolean LoopMode)
{
    if (ReloadCount < (CtsCount - 1U))
    {
        /* Link the software struct of CTS to next one */
        SctsConfigPtr->RamReloadIntEnable = FALSE;
        SctsConfigPtr->RamReloadEnable = TRUE;
        /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
         * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4
         */
        SctsConfigPtr->RamReloadNextDescAddr = (uint32) &Scts[ReloadCount + 1U]; /* PRQA S 0306 */
    }
    else
    {
        if (TRUE == LoopMode)
        {
            /* Link the last CTS's RamReloadNextDescAddr to the first one */
            SctsConfigPtr->RamReloadEnable = TRUE;
            /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
             * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4
             */
            SctsConfigPtr->RamReloadNextDescAddr = (uint32) &Scts[0]; /* PRQA S 0306 */
        }
        else
        {
            SctsConfigPtr->RamReloadEnable = FALSE;
            SctsConfigPtr->RamReloadNextDescAddr = 0;
        }
        SctsConfigPtr->RamReloadIntEnable = TRUE;
    }
}

CDDDMA_FUNC static inline void Dma_Scts_RamReloadConfig(const CddDma_RamReloadListType *List,
        CddDma_TransferConfigType *TransferConfig,
        CddDma_SoftwareCtsType *Scts, uint8 CtsCount, boolean LoopMode)
{
    CddDma_TransferConfigType SctsConfig = *TransferConfig;
    CddDma_TransferConfigType *SctsConfigPtr = TransferConfig;
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_00();
    for (uint8 ReloadCount = 0; ReloadCount < CtsCount; ++ReloadCount)
    {
        SctsConfig.SrcAddr = List[ReloadCount].SrcAddr;
        SctsConfig.DestAddr = List[ReloadCount].DestAddr;
        if (1U == CtsCount)
        {
            Dma_Scts_ConfigSignalCount(&SctsConfig, Scts, LoopMode);
        }
        else
        {
            Dma_Scts_ConfigMultiCount(ReloadCount, &SctsConfig, Scts, CtsCount, LoopMode);
        }
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dma_Lld_PushConfigToScts, &SctsConfig, &Scts[ReloadCount]);
#else
        Dma_Lld_PushConfigToScts(&SctsConfig, &Scts[ReloadCount]);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_00();
    /* Disable the interrupt and set the next ram reload addr to the original CTS*/
    SctsConfigPtr->RamReloadIntEnable = FALSE;
    SctsConfigPtr->RamReloadEnable = TRUE;
    /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
     * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4
     */
    SctsConfigPtr->RamReloadNextDescAddr = (uint32) &Scts[0];  /* PRQA S 0306 */
}
#endif

/*==================================================================================================
 *                                   GLOBAL FUNCTIONS
==================================================================================================*/

CDDDMA_FUNC void CddDma_Init(const CddDma_ConfigType *ConfigPtr)
{
    CddDma_ReturnType DmaIpStatus = DMA_IP_STATUS_SUCCESS;
#if (CDDDMA_PRECOMPILE_SUPPORT == STD_ON)
    CddDma_ConfigPtr = &CddDma_PreCompileConfig;
    (void)ConfigPtr;
#else
    CddDma_ConfigPtr = ConfigPtr;
#endif
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == CddDma_ConfigPtr)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_INIT, CDDDMA_E_INIT_FAILED);
    }
    else
    {
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON) */
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        DmaIpStatus = (CddDma_ReturnType)OsIf_Trusted_Call_Return1param(Dma_Lld_Init, CddDma_ConfigPtr);
#else
        DmaIpStatus = Dma_Lld_Init(CddDma_ConfigPtr);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
        if (DMA_IP_STATUS_SUCCESS != DmaIpStatus)
        {
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_INIT, CDDDMA_E_INIT_FAILED);
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON)*/
        }
        else
        {
            /* Do noting*/
        }
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    }
#endif  /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON) */
}

CDDDMA_FUNC void CddDma_DeInit(void)
{
    if (NULL_PTR != CddDma_ConfigPtr)
    {
        /* Deinitialize the DMA controller and release all DMA channels*/
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(Dma_Lld_Deinit);
#else
        Dma_Lld_Deinit();
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
        CddDma_ConfigPtr = NULL_PTR;
    }
    else
    {
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_DEINIT, CDDDMA_E_UNINIT);
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON)*/
    }
}

CDDDMA_FUNC StatusType CddDma_SetLogicChannelTransfer(CddDma_ChannelType VirtualChannel, uint32 SrcAddr, uint32 DestAddr, \
        const CddDma_TransferConfigType *TransferConfig)
{
    StatusType ReStatus = E_NOT_OK;
    CddDma_TransferConfigType ChannelTransferConfig;
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    else if (DMA_CHN_UNINIT == CddDma_State[VirtualChannel].Status)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_UNINIT);
    }
    else if (CddDma_State[VirtualChannel].ChannelEnable != TRUE)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_NOT_INIT_FAILED);
    }
    else if (CddDma_State[VirtualChannel].Status != DMA_CHN_NORMAL)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_UNINIT);
    }
    else if (NULL_PTR == TransferConfig)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_PARAM_POINTER);
    }
    else
    {
        if (((uint32)0 == SrcAddr) || ((uint32)0 == DestAddr))
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_ADDR_INVALID_FAILED);
        }
        else if ((TRUE == TransferConfig->RamReloadEnable) && ((TransferConfig->RamReloadNextDescAddr & ALIGNED_32B_MASK) != 0U))
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_RAMRELOAD_ADDR_UNALIGNED);
        }
        /* Check that the address are aligned*/
        else if (((SrcAddr % (1U << TransferConfig->SrcTransferSize)) != 0U) || \
                 ((DestAddr % (1U << TransferConfig->DestTransferSize)) != 0U))
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_ADDR_UNALIGNED);
        }
        else if (((TransferConfig->TransferLoopByteCount % (1U << TransferConfig->SrcTransferSize)) != 0U) || \
                 ((TransferConfig->TransferLoopByteCount % (1U << TransferConfig->DestTransferSize)) != 0U))
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_TRANSFER, CDDDMA_E_LOOPCOUNT_INVALID);
        }
        else
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON)*/
        {
            ChannelTransferConfig = *TransferConfig;
            ChannelTransferConfig.SrcAddr = SrcAddr;
            ChannelTransferConfig.DestAddr = DestAddr;
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
            ReStatus = OsIf_Trusted_Call_Return2param(Dma_Lld_SetChannelTransfer, VirtualChannel, &ChannelTransferConfig);
#else
            ReStatus = Dma_Lld_SetChannelTransfer(VirtualChannel, &ChannelTransferConfig);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
        }
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON)*/
    return ReStatus;
}

CDDDMA_FUNC void CddDma_StartChannel(CddDma_ChannelType VirtualChannel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_START_CHANNEL, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    /* Check current channel of DMA must be initialed */
    else if (FALSE == CddDma_State[VirtualChannel].ChannelEnable)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_START_CHANNEL, CDDDMA_E_NOT_INIT_FAILED);
    }
    else
#endif
    {
        /* Enable requests for current channel */
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dma_Lld_SetDmaRequestCmd, VirtualChannel, TRUE);
#else
        Dma_Lld_SetDmaRequestCmd(VirtualChannel, TRUE);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC void CddDma_StopChannel(CddDma_ChannelType VirtualChannel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_STOP_CHANNEL, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    /* Check current channel of DMA must be initialed */
    else if (FALSE == CddDma_State[VirtualChannel].ChannelEnable)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_STOP_CHANNEL, CDDDMA_E_NOT_INIT_FAILED);
    }
    else
#endif
    {
        /* Disable requests for current channel */
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dma_Lld_SetDmaRequestCmd, VirtualChannel, FALSE);
#else
        Dma_Lld_SetDmaRequestCmd(VirtualChannel, FALSE);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC void CddDma_SoftTrigger(CddDma_ChannelType VirtualChannel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_SOFT_TRIGGER, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    /* Check current channel of DMA must be initialed */
    else if (FALSE == CddDma_State[VirtualChannel].ChannelEnable)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_SOFT_TRIGGER, CDDDMA_E_NOT_INIT_FAILED);
    }
    else
#endif
    {
        /* Triggers a sw request for the current channel. */
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Dma_Lld_TriggerChannelStart, VirtualChannel);
#else
        Dma_Lld_TriggerChannelStart(VirtualChannel);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0)
CDDDMA_FUNC void CddDma_ChannelRamReloadConfig(CddDma_ChannelType VirtualChannel, const CddDma_RamReloadListType *List,
        CddDma_TransferConfigType *TransferConfig,
        CddDma_SoftwareCtsType *Scts, uint8 CtsCount, boolean LoopMode)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    /* Check current channel of DMA must be initialed */
    else if (FALSE == CddDma_State[VirtualChannel].ChannelEnable)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_NOT_INIT_FAILED);
    }
    else if (DMA_CHN_UNINIT == CddDma_State[VirtualChannel].Status)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_UNINIT);
    }
    else
    {
        if (NULL_PTR == List)
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_PARAM_POINTER);
        }
        else if (0U == CtsCount)
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_OUT_OF_RANGE_FAILED);
        }
        /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
         * needs to obtain the integer value of the Scts address, thus, couldn't adhere to M3CM Rule-11.4
         */
        else if (((uint32)Scts & ALIGNED_32B_MASK) != 0U) /* PRQA S 0306 */
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_OUT_OF_RANGE_FAILED);
        }
        else if (NULL_PTR == TransferConfig)
        {
            (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                                  CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_PARAM_POINTER);
        }
        else
#endif
        {
            Dma_Scts_RamReloadConfig(List, TransferConfig, Scts, CtsCount, LoopMode);
        }
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

CDDDMA_FUNC void CddDma_InstallCallback(CddDma_ChannelType VirtualChannel, CddDma_CallbackType Callback, void *Parameter)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_INSTALL_CALLBACK, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    /* Check current channel of DMA must be initialed */
    else if (FALSE == CddDma_State[VirtualChannel].ChannelEnable)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_INSTALL_CALLBACK, CDDDMA_E_NOT_INIT_FAILED);
    }
    /* Check the Parameter of Callback is valid*/
    else if (NULL_PTR == Callback)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_INSTALL_CALLBACK, CDDDMA_E_PARAM_POINTER);
    }
    else
#endif
    {
        Dma_Lld_InstallCallback(VirtualChannel, Callback, Parameter);
    }
}

CDDDMA_FUNC void CddDma_InstallErrorCallback(CddDma_ChannelType VirtualChannel, CddDma_CallbackType Callback, void *Parameter)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_INSTALL_ERROR_CALLBACK, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    /* Check current channel of DMA must be initialed */
    else if (FALSE == CddDma_State[VirtualChannel].ChannelEnable)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_INSTALL_ERROR_CALLBACK, CDDDMA_E_NOT_INIT_FAILED);
    }
    /* Check the Parameter of Callback is valid*/
    else if (NULL_PTR == Callback)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_INSTALL_ERROR_CALLBACK, CDDDMA_E_PARAM_POINTER);
    }
    else
#endif
    {
        Dma_Lld_InstallErrorCallback(VirtualChannel, Callback, Parameter);
    }
}

CDDDMA_FUNC void CddDma_GetChannelStatus(CddDma_ChannelType VirtualChannel, CddDma_ChannelStatusReturnType *ChannelStatus)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_GET_CHANNEL_STATUS, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    /* Check current channel of DMA must be initialed */
    else if (NULL_PTR == ChannelStatus)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_GET_CHANNEL_STATUS, CDDDMA_E_NOT_INIT_FAILED);
    }
    else
#endif
    {
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dma_Lld_GetChannelStatus, VirtualChannel, ChannelStatus);
#else
        Dma_Lld_GetChannelStatus(VirtualChannel, ChannelStatus);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC void CddDma_ClearChannelDoneStatus(CddDma_ChannelType VirtualChannel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_CLEAR_CHANNEL_DONE_STATUS, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    else
#endif
    {
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Dma_Lld_ClearChannelDoneStatus, VirtualChannel);
#else
        Dma_Lld_ClearChannelDoneStatus(VirtualChannel);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC uint32 CddDma_GetChannelRemainingTriggerCount(CddDma_ChannelType VirtualChannel)
{
    uint32 RemainingCount = 0U;
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= VirtualChannel)
    {
        (void)Det_ReportError((uint16)CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID,
                              CDDDMA_SID_GET_REMAINING_TRIGGER_COUNT, CDDDMA_E_OUT_OF_RANGE_FAILED);
    }
    else
#endif
    {
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        RemainingCount = OsIf_Trusted_Call_Return1param(Dma_Lld_GetRemainingTriggerCount, VirtualChannel);
#else
        RemainingCount = Dma_Lld_GetRemainingTriggerCount(VirtualChannel);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
    return RemainingCount;
}

#define CDDDMA_STOP_SEC_CODE
#include "CddDma_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file CddDma.c */

