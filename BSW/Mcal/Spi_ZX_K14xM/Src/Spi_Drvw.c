/**************************************************************************************************/
/**
 * @file      : Spi_Drvw.c
 * @brief     : Spi driver wrapper source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drvw
 *  @brief Spi driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_Drvw.h"
#include "Spi_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_DRVW_C_VENDOR_ID                   0x00B3U
#define SPI_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRVW_C_SW_MAJOR_VERSION            1U
#define SPI_DRVW_C_SW_MINOR_VERSION            2U
#define SPI_DRVW_C_SW_PATCH_VERSION            1U

/* Check if current file and Spi_Drvw.h are the same vendor */
#if (SPI_DRVW_C_VENDOR_ID != SPI_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Autosar version */
#if ((SPI_DRVW_C_AR_RELEASE_MAJOR_VERSION != SPI_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SPI_DRVW_C_AR_RELEASE_MINOR_VERSION != SPI_DRVW_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SPI_DRVW_C_AR_RELEASE_REVISION_VERSION != SPI_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drvw.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Software version */
#if ((SPI_DRVW_C_SW_MAJOR_VERSION != SPI_DRVW_H_SW_MAJOR_VERSION) ||                               \
     (SPI_DRVW_C_SW_MINOR_VERSION != SPI_DRVW_H_SW_MINOR_VERSION) ||                               \
     (SPI_DRVW_C_SW_PATCH_VERSION != SPI_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drvw.c and Spi_Drvw.h are different"
#endif

/* Check if current file and Spi_Drv.h are the same vendor */
#if (SPI_DRVW_C_VENDOR_ID != SPI_DRV_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Autosar version */
#if ((SPI_DRVW_C_AR_RELEASE_MAJOR_VERSION != SPI_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                \
     (SPI_DRVW_C_AR_RELEASE_MINOR_VERSION != SPI_DRV_H_AR_RELEASE_MINOR_VERSION) ||                \
     (SPI_DRVW_C_AR_RELEASE_REVISION_VERSION != SPI_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drvw.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Software version */
#if ((SPI_DRVW_C_SW_MAJOR_VERSION != SPI_DRV_H_SW_MAJOR_VERSION) ||                                \
     (SPI_DRVW_C_SW_MINOR_VERSION != SPI_DRV_H_SW_MINOR_VERSION) ||                                \
     (SPI_DRVW_C_SW_PATCH_VERSION != SPI_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drvw.c and Spi_Drv.h are different"
#endif
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
#define SPI_START_SEC_VAR_CLEARED_8
#include "Spi_MemMap.h"
/**
 * @brief Mapping between Spi channel id and instance id
 */
static Spi_Drvw_HWUnitType Spi_Drvw_PhyUnitToHWUnitMapping[SPI_DRV_HWUNITS_COUNT];
static uint8               Spi_Drvw_HWUnitToPhyUnitMapping[SPI_DRV_MAX_CFG_HWUNITS];

#define SPI_STOP_SEC_VAR_CLEARED_8
#include "Spi_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"

extern Spi_Drv_TransferConfigType *Spi_Drv_TransferConfigPtrArray[SPI_DRV_HWUNITS_COUNT];

#define SPI_STOP_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
extern void Spi_ChannelEndCallback(Spi_Drvw_HWUnitType HwUnit, boolean JobResultOK);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
static void Spi_Drvw_ChannelEndCallback(uint8 Instance, Spi_Drv_EventType Event);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief     Callback function for end of channel transfer.
 *
 * @param[in] Instance: Instance of SPI physical unit
 * @param[in] Event: Callback Event
 *
 * @return    None
 */
static void Spi_Drvw_ChannelEndCallback(uint8 Instance, Spi_Drv_EventType Event)
{
    Spi_Drvw_HWUnitType HwUnit = Spi_Drvw_PhyUnitToHWUnitMapping[Instance];
    boolean             JobResultOk;

    if (SPI_DRV_EVENT_FAULT != Event)
    {
        JobResultOk = (boolean)TRUE;
    }
    else
    {
        JobResultOk = (boolean)FALSE;
    }
    (void)Spi_ChannelEndCallback(HwUnit, JobResultOk);
}
#endif /* ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2)) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
/**
 * @brief     The function initialize the given SPI HW Unit.
 *
 * @param[in] HWUnit: Id of Spi HW Unit
 * @param[in] HWUnitCfgPtr: pointer to the SPI HW Unit Configuration
 *
 * @return    None
 */
void Spi_Drvw_Init(const Spi_Drvw_HWUnitType HWUnit, const Spi_Drvw_HWUnitConfigType *HWUnitCfgPtr)
{
#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != HWUnitCfgPtr);
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

    Spi_Drvw_PhyUnitToHWUnitMapping[HWUnitCfgPtr->Instance] = HWUnit;
    Spi_Drvw_HWUnitToPhyUnitMapping[HWUnit] = HWUnitCfgPtr->Instance;
    (void)Spi_Drv_Init(HWUnitCfgPtr->PhyUnitConfigPtr);

#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */
}

/**
 * @brief     The function de-initialize the given SPI HW Unit.
 *
 * @param[in] HWUnit: Id of SPI HW Unit
 *
 * @return    None
 */
void Spi_Drvw_DeInit(Spi_Drvw_HWUnitType HWUnit)
{
    uint8 Instance = Spi_Drvw_HWUnitToPhyUnitMapping[HWUnit];

    (void)Spi_Drv_DeInit(Instance);
}

/**
 * @brief   The function processes synchronous or asynchronous transmission of one channel.
 *
 * @param[in] ChannelCfgPtr: Pointer to channel configuration
 * @param[in] ExternalDeviceCfgPtr: Pointer to external device configuration
 * @param[in] IsFirstChannel: first channel of job or not
 * @param[in] IsLastChannel: last channel of job or not
 * @param[in] IsSync: synchronous or asynchronous transmission. TRUE is Sync, and FALSE is Async.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Channel transmission successfully
 * @retval    E_NOT_OK: Channel transmission failed
 *
 */
Std_ReturnType
Spi_Drvw_TransmitChannel(const Spi_Drvw_ChannelConfigType        *ChannelCfgPtr,
                         const Spi_Drvw_ExternalDeviceConfigType *ExternalDeviceCfgPtr,
                         const boolean IsFirstChannel, const boolean IsLastChannel,
                         const boolean IsSync)
{
    uint8                             Instance;
    Spi_Drvw_DataBufferType          *RxBuffer;
    Spi_Drvw_DataBufferType          *TxBuffer;
    Spi_Drvw_NumberOfDataType         DataNum;
    const Spi_Drv_ExternalDeviceType *DrvExternalDevicePtr;
    Std_ReturnType                    Ret = (Std_ReturnType)E_OK;

#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ChannelCfgPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != ExternalDeviceCfgPtr);
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

    Instance = ExternalDeviceCfgPtr->Instance;

#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != Spi_Drv_TransferConfigPtrArray[Instance]);
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

    Spi_Drv_TransferConfigPtrArray[Instance]->FirstTransferFlag = (boolean)IsFirstChannel;
    if (TRUE == IsLastChannel)
    {
        Spi_Drv_TransferConfigPtrArray[Instance]->ContinueTransferFlag = (boolean)FALSE;
    }
    else
    {
        Spi_Drv_TransferConfigPtrArray[Instance]->ContinueTransferFlag = (boolean)TRUE;
    }

    DrvExternalDevicePtr = ExternalDeviceCfgPtr->DrvExternalDeviceConfigPtr;

    Ret = Spi_Drv_SetDeviceParams(DrvExternalDevicePtr, ChannelCfgPtr->FrameSize,
                                  ChannelCfgPtr->Lsb, ChannelCfgPtr->DefaultTransmitValue);
    if (E_NOT_OK != Ret)
    {
#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
        MCALLIB_DEV_ASSERT(NULL_PTR != ChannelCfgPtr->ChannelState);
        MCALLIB_DEV_ASSERT(NULL_PTR != ChannelCfgPtr->BufferDescriptor);
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

        DataNum = ChannelCfgPtr->ChannelState->Length;
        RxBuffer = ChannelCfgPtr->BufferDescriptor->RxBuffer;
        if (0u != (ChannelCfgPtr->ChannelState->Flags & SPI_DRVW_CHANNEL_FLAG_TX_DEFAULT))
        {
            TxBuffer = NULL_PTR;
        }
        else
        {
            TxBuffer = ChannelCfgPtr->BufferDescriptor->TxBuffer;
        }
        if (TRUE == IsSync)
        {
            Ret = Spi_Drv_SyncTransmit(DrvExternalDevicePtr, TxBuffer, RxBuffer, DataNum,
                                       SPI_DRV_TIMEOUT_COUNTER);
        }
        else
        {
#if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
            (void)Spi_Drv_AsyncTransmit(DrvExternalDevicePtr, TxBuffer, RxBuffer, DataNum,
                                        &Spi_Drvw_ChannelEndCallback);
#endif /* ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2)) */
        }
    }

#if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */
    return Ret;
}

#if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief     The function polls to process asynchronous transmission.
 *
 * @param[in] HWUnit: Id of SPI HW Unit
 *
 * @return    None
 *
 */
void Spi_Drvw_PollAsyncTransmit(Spi_Drvw_HWUnitType HWUnit)
{
    uint8 Instance = Spi_Drvw_HWUnitToPhyUnitMapping[HWUnit];

    #if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

    #if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != Spi_Drv_TransferConfigPtrArray[Instance]);
    #endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */

    if (SPI_DRV_POLLING == Spi_Drv_TransferConfigPtrArray[Instance]->AsyncMode)
    {
        Spi_Drv_PollAsyncTransmit(Instance);
    }

    #if (STD_ON == SPI_DRVW_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif /* (STD_ON == SPI_DRVW_DEV_ERROR_DETECT) */
}

/**
 * @brief     The function configures transfer mode as polling or interrupt.
 *
 * @param[in] HWUnit: Id of Spi HW Unit
 * @param[in] Mode: set polling or interrupt mode
 *
 * @return    None
 *
 */
void Spi_Drvw_SetAsyncMode(Spi_Drvw_HWUnitType HWUnit, Spi_Drvw_AsyncModeType Mode)
{
    uint8 Instance = Spi_Drvw_HWUnitToPhyUnitMapping[HWUnit];
    if (SPI_DRVW_POLLING_MODE == Mode)
    {
        (void)Spi_Drv_SetAsyncMode(Instance, SPI_DRV_POLLING);
    }
    else if (SPI_DRVW_INTERRUPT_MODE == Mode)
    {
        (void)Spi_Drv_SetAsyncMode(Instance, SPI_DRV_INTERRUPT);
    }
    else
    {
        /* Nothing to do */
    }
}
#endif

#if ((SPI_DRVW_SLAVE_SUPPORT == STD_ON) && (SPI_DRVW_CANCEL_API == STD_ON))
    #if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief     The function cancels transmission of slave mode.
 *
 * @param[in] HWUnit: Id of Spi HW Unit
 *
 * @return    None
 */
void Spi_Drvw_SlaveCancel(const Spi_Drvw_HWUnitType HWUnit)
{
    uint8 Instance = Spi_Drvw_HWUnitToPhyUnitMapping[HWUnit];
    Spi_Drv_Cancel(Instance);
}
    #endif
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Drvw */

/** @} end of group Spi_Module */
