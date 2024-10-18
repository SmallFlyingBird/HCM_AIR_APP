/**************************************************************************************************/
/**
 * @file      : Spi_Drv.c
 * @brief     : Spi low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drv
 *  @brief Spi low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_Drv.h"
#include "SchM_Spi.h"
#if (STD_ON == SPI_DRV_DMA_USED)
    #include "Dma_Drv.h"
#endif
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_DRV_C_VENDOR_ID                   0x00B3U
#define SPI_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRV_C_SW_MAJOR_VERSION            1U
#define SPI_DRV_C_SW_MINOR_VERSION            2U
#define SPI_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Spi_Drv.h are the same vendor */
#if (SPI_DRV_C_VENDOR_ID != SPI_DRV_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drv.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Autosar version */
#if ((SPI_DRV_C_AR_RELEASE_MAJOR_VERSION != SPI_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (SPI_DRV_C_AR_RELEASE_MINOR_VERSION != SPI_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (SPI_DRV_C_AR_RELEASE_REVISION_VERSION != SPI_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_Drv.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Software version */
#if ((SPI_DRV_C_SW_MAJOR_VERSION != SPI_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (SPI_DRV_C_SW_MINOR_VERSION != SPI_DRV_H_SW_MINOR_VERSION) ||                                 \
     (SPI_DRV_C_SW_PATCH_VERSION != SPI_DRV_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_Drv.c and Spi_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((SPI_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (SPI_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Spi_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Spi.h are the same Autosar version */
    #if ((SPI_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_SPI_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (SPI_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_SPI_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Spi_Drv.c and SchM_Spi.h are different"
    #endif

    #if (STD_ON == SPI_DRV_DMA_USED)
        /* Check if current file and Dma_Drv.h are the same Autosar version */
        #if ((SPI_DRV_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
             (SPI_DRV_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Spi_Drv.c and Dma_Drv.h are different"
        #endif
    #endif /* (STD_ON == SPI_DRV_DMA_USED) */
#endif     /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define SPI_DRV_REG_DMACR_RDMAE_POS  (0U)
#define SPI_DRV_REG_DMACR_RDMAE_MASK (1U << SPI_DRV_REG_DMACR_RDMAE_POS)
#define SPI_DRV_REG_DMACR_RDMAE(x)                                                                 \
    (((uint32)(((uint32)(x)) << SPI_DRV_REG_DMACR_RDMAE_POS)) & SPI_DRV_REG_DMACR_RDMAE_MASK)

#define SPI_DRV_REG_DMACR_TDMAE_POS  (1U)
#define SPI_DRV_REG_DMACR_TDMAE_MASK (1U << SPI_DRV_REG_DMACR_TDMAE_POS)
#define SPI_DRV_REG_DMACR_TDMAE(x)                                                                 \
    (((uint32)(((uint32)(x)) << SPI_DRV_REG_DMACR_TDMAE_POS)) & SPI_DRV_REG_DMACR_TDMAE_MASK)

/**
 *  @brief Defines SPI macro
*/
#define     SPI_DRV_SLAVE_MODE                 (0U)   /*!< Slave mode */
#define     SPI_DRV_MASTER_MODE                (1U)   /*!< Master mode */
#define     SPI_DRV_TMOD_TRANSMIT_RECEIVE      (0U)   /*!< Both Transmit & receive */
#define     SPI_DRV_INTERRUPT_TXE              (0U)   /*!< Transmit FIFO empty interrupt */
#define     SPI_DRV_INTERRUPT_RXF              (4U)   /*!< Received FIFO full interrupt */
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"

extern Spi_Drv_TransferConfigType *Spi_Drv_TransferConfigPtrArray[SPI_DRV_HWUNITS_COUNT];

#define SPI_STOP_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"

Spi_Drv_TransferConfigType *Spi_Drv_TransferConfigPtrArray[SPI_DRV_HWUNITS_COUNT];

#define SPI_STOP_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

Spi_Drv_DeviceParamType Spi_Drv_DeviceParamArray[SPI_DRV_MAX_CFG_DEVICES];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_CONST_PTR
#include "Spi_MemMap.h"

/**
 *  @brief Defines SPI register address
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason. */
static Reg_Spi_BfType *const Spi_Drv_SpiRegBfPtr[SPI_DRV_HWUNITS_COUNT] = {
    (Reg_Spi_BfType *)SPI0_BASE_ADDR, /*!< SPI0 base address */
    (Reg_Spi_BfType *)SPI1_BASE_ADDR, /*!< SPI1 base address */
    (Reg_Spi_BfType *)SPI2_BASE_ADDR, /*!< SPI2 base address */
    (Reg_Spi_BfType *)SPI3_BASE_ADDR  /*!< SPI3 base address */
};

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
 The following four lines of code also violate this rule with the same reason. */
static Reg_Spi_WType *const Spi_Drv_SpiRegWPtr[SPI_DRV_HWUNITS_COUNT] = {
    (Reg_Spi_WType *)SPI0_BASE_ADDR, /*!< SPI0 base address */
    (Reg_Spi_WType *)SPI1_BASE_ADDR, /*!< SPI1 base address */
    (Reg_Spi_WType *)SPI2_BASE_ADDR, /*!< SPI2 base address */
    (Reg_Spi_WType *)SPI3_BASE_ADDR  /*!< SPI3 base address */
};

#if (STD_ON == SPI_DRV_DMA_USED)
static const uint8 Spi_Drv_RxDmaReqSource[SPI_DRV_HWUNITS_COUNT] = {
    (uint8)DMA_DRV_REQ_SPI0_RX, /*!< DMA source of SPI0 RX */
    (uint8)DMA_DRV_REQ_SPI1_RX, /*!< DMA source of SPI1 RX */
    (uint8)DMA_DRV_REQ_SPI2_RX, /*!< DMA source of SPI1 RX */
    (uint8)DMA_DRV_REQ_SPI3_RX  /*!< DMA source of SPI1 RX */
};

static const uint8 Spi_Drv_TxDmaReqSource[SPI_DRV_HWUNITS_COUNT] = {
    (uint8)DMA_DRV_REQ_SPI0_TX, /*!< DMA source of SPI0 TX */
    (uint8)DMA_DRV_REQ_SPI1_TX, /*!< DMA source of SPI1 TX */
    (uint8)DMA_DRV_REQ_SPI2_TX, /*!< DMA source of SPI2 TX */
    (uint8)DMA_DRV_REQ_SPI3_TX  /*!< DMA source of SPI3 TX */
};
#endif

#define SPI_STOP_SEC_CONST_PTR
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
static Spi_Drv_TransferConfigType Spi_Drv_TransferConfigArray[SPI_DRV_HWUNITS_COUNT];

#if (STD_ON == SPI_DRV_DMA_USED)
static Dma_Drv_ChannelTransferConfigType Spi_Drv_DmaChannelTransferConfig;
static Dma_Drv_AddrConfigType Spi_Drv_DmaChannelSourceConfig;
static Dma_Drv_AddrConfigType Spi_Drv_DmaChannelDestinationConfig;
static Dma_Drv_TransferControlConfigType Spi_Drv_DmaChannelControlConfig;
static Dma_Drv_ChannelGlobalConfigType   Spi_Drv_DmaChannelGlobalConfig;
static Dma_Drv_RequestConfigType Spi_Drv_DmaChannelRequestConfig;
static Dma_Drv_PriorityConfigType Spi_Drv_DmaChannelPriorityConfig;
#endif
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#if (STD_ON == SPI_DRV_DMA_USED)
    #define SPI_START_SEC_VAR_CLEARED_32
    #include "Spi_MemMap.h"
static uint32 Spi_Drv_DmaDiscardData;
    #define SPI_STOP_SEC_VAR_CLEARED_32
    #include "Spi_MemMap.h"
#endif
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

LOCAL_INLINE void Spi_Drv_ReadFifo(uint8 Instance, uint8 ReadNum);
LOCAL_INLINE void Spi_Drv_WriteFifo(uint8 Instance, uint8 WriteNum);
static void       Spi_Drv_TransferFinished(uint8 Instance);
static void       Spi_Drv_ProcessAsyncTransfer(uint8 Instance);
static void       Spi_Drv_UpdateTxTransfer(uint8 Instance, uint8 *TxBuffer, uint8 FrameSize,
                                           boolean TxLsb, uint16 FrameNum);
static void Spi_Drv_InitTxTransfer(uint8 Instance, uint8 *TxBuffer, uint8 FrameSize, boolean TxLsb,
                                   uint16 FrameNum);
static void Spi_Drv_InitRxTransfer(uint8 Instance, uint8 *RxBuffer, uint8 FrameSize,
                                   uint16 FrameNum);
#if (STD_ON == SPI_DRV_DMA_USED)
static void Spi_Drv_ConfigDmaTx(uint8 Instance);
static void Spi_Drv_ConfigDmaRx(uint8 Instance);
static void Spi_Drv_ContinueDmaTxTransfer(uint8 Instance);
static void Spi_Drv_ContinueDmaRxTransfer(uint8 Instance);
static void Spi_Drv_FinishDmaTxTransfer(const uint8 Instance);
#endif
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
static void Spi_Drv_CheckDataLength(uint32 FrameSzie, uint16 Length);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
/**
 * @brief     This function checks the validation of data length
 * @details   This function checks the validation of data length
 *
 * @param[in] FrameSzie: Frame size.
 * @param[in] Length: Data Length.
 * 
 * @return     None
 */
static void Spi_Drv_CheckDataLength(uint32 FrameSzie, uint16 Length)
{
    MCALLIB_DEV_ASSERT_START();

    if (FrameSzie > 16u)
    {
        /* check if Length mod 4 equals 0*/
        MCALLIB_DEV_ASSERT(0U == ((uint32)Length & 3U)); 
    }
    else if (FrameSzie > 8u)
    {
        /* check if Length mod 2 equals 0*/
        MCALLIB_DEV_ASSERT(0U == ((uint32)Length & 1U));
    }
    else
    {
        /* Nothing to do */
    }
    MCALLIB_DEV_ASSERT_END();
}
#endif

/**
 * @brief     This function will update transfer state for data transmit.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @param[in] TxBuffer: pointer to transmit buffer.
 * @param[in] FrameSize: frame size.
 * @param[in] TxLsb: Lsb or not.
 * @param[in] FrameNum: Number of Data to be transmit.
 *
 * @return    None
 */
static void Spi_Drv_UpdateTxTransfer(uint8 Instance, uint8 *TxBuffer, uint8 FrameSize,
                                     boolean TxLsb, uint16 FrameNum)
{
    Reg_Spi_BfType             *BaseBf;
    Spi_Drv_TransferConfigType *TransferCfgPtr;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseBf != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    /* update frame size if frame size has changed */
    if (BaseBf->SPI_CTRLR0.DFS_32 != ((uint32)FrameSize - 1U))
    {
        BaseBf->SPI_SSENR.SPI_EN = FALSE;
        BaseBf->SPI_CTRLR0.DFS_32 = FrameSize - 1U;
        BaseBf->SPI_SSENR.SPI_EN = TRUE;
    }
    /* Update TransferCfgPtr structure. */
    TransferCfgPtr->TxLsb = TxLsb;
    TransferCfgPtr->FrameSize = FrameSize;
    TransferCfgPtr->TxIndex = 0u;
    TransferCfgPtr->TxBuffer = TxBuffer;

    if (FrameSize < 9u)
    {
        TransferCfgPtr->ExpectWriteNum = FrameNum;
    }
    else if (FrameSize < 17u)
    {
        TransferCfgPtr->ExpectWriteNum = FrameNum >> 1U;
    }
    else
    {
        TransferCfgPtr->ExpectWriteNum = FrameNum >> 2U;
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function will initialize state for data transmit.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @param[in] TxBuffer: pointer to transmit buffer.
 * @param[in] FrameSize: frame size.
 * @param[in] TxLsb: Lsb or not.
 * @param[in] FrameNum: Number of Data to be transmit.
 *
 * @return    None
 */
static void Spi_Drv_InitTxTransfer(uint8 Instance, uint8 *TxBuffer, uint8 FrameSize, boolean TxLsb,
                                   uint16 FrameNum)
{
    Reg_Spi_BfType             *BaseBf;
    Spi_Drv_TransferConfigType *TransferCfgPtr;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseBf != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    SchM_Enter_Spi_InitTxTransfer();

    BaseBf->SPI_SSENR.SPI_EN = FALSE;

    /* Disable DMA requests */
    BaseBf->SPI_DMACR.TDMAE = FALSE;
    BaseBf->SPI_DMACR.RDMAE = FALSE;

    /* Set SPI Master/Slave mode */
#if (STD_ON == SPI_DRV_SLAVE_SUPPORT)
    if (TRUE == TransferCfgPtr->PhyUnitConfig->SlaveMode)
    {
        BaseBf->SPI_CTRLR0.MST_MODE = (uint32)SPI_DRV_SLAVE_MODE;
    }
    else
#endif
    {
        BaseBf->SPI_CTRLR0.MST_MODE = (uint32)SPI_DRV_MASTER_MODE;
    }
    /* Set SPI clock divider */
    BaseBf->SPI_BAUDR.SCKDV = TransferCfgPtr->ExternalDevice->ClockDivider;
    /* Set data frame size */
    BaseBf->SPI_CTRLR0.DFS_32 = FrameSize - 1U;
    /* Set serial clock phase */
    BaseBf->SPI_CTRLR0.SCPH = (uint32)TransferCfgPtr->ExternalDevice->ClockPhase;
    /* Set clock polarity */
    BaseBf->SPI_CTRLR0.SCPOL = (uint32)TransferCfgPtr->ExternalDevice->ClockPolarity;
    /* Set transfer mode */
    BaseBf->SPI_CTRLR0.TMOD = (uint32)SPI_DRV_TMOD_TRANSMIT_RECEIVE;
    /* Set transmit FIFO threshold level */
    BaseBf->SPI_FTLR.TFT = (uint32)SPI_DRV_FIFO_SIZE - (uint32)1U;
    /* Set receive FIFO threshold level */
    BaseBf->SPI_FTLR.RFT = 0U;
    /* Select SPI slave */
    BaseBf->SPI_SSENR.SER = (uint32)TransferCfgPtr->ExternalDevice->CsIdentifier;
    /* Enable SPI */
    BaseBf->SPI_SSENR.SPI_EN = TRUE;

    SchM_Exit_Spi_InitTxTransfer();

    /* Update TransferCfgPtr structure. */
    TransferCfgPtr->TxLsb = TxLsb;
    TransferCfgPtr->FrameSize = FrameSize;
    TransferCfgPtr->TxIndex = 0u;
    TransferCfgPtr->TxBuffer = TxBuffer;

    if (FrameSize < 9u)
    {
        TransferCfgPtr->ExpectWriteNum = FrameNum;
    }
    else if (FrameSize < 17u)
    {
        TransferCfgPtr->ExpectWriteNum = FrameNum >> 1U;
    }
    else
    {
        TransferCfgPtr->ExpectWriteNum = FrameNum >> 2u;
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function will initialize state for data receive.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @param[in] RxBuffer: Pointer to receive buffer.
 * @param[in] FrameSize: Frame size.
 * @param[in] FrameNum: Number of Data to be received.
 *
 * @return    None
 */
static void Spi_Drv_InitRxTransfer(uint8 Instance, uint8 *RxBuffer, uint8 FrameSize,
                                   uint16 FrameNum)
{
    Spi_Drv_TransferConfigType *TransferCfgPtr;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif
    TransferCfgPtr->RxIndex = 0u;
    TransferCfgPtr->RxBuffer = RxBuffer;
    if (FrameSize < 9u)
    {
        TransferCfgPtr->ExpectReadNum = FrameNum;
    }
    else if (FrameSize < 17u)
    {
        TransferCfgPtr->ExpectReadNum = FrameNum >> 1U;
    }
    else
    {
        TransferCfgPtr->ExpectReadNum = FrameNum >> 2U;
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function reads Data from FIFO.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @param[in] ReadNum: Number of Data to be read from FIFO.
 *
 * @return    None
 */
LOCAL_INLINE void Spi_Drv_ReadFifo(uint8 Instance, uint8 ReadNum)
{
    const Reg_Spi_WType                *BaseW;
    const Spi_Drv_TransferConfigType *TransferCfgPtr;
    uint32                      Data;
    uint8                       Index;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    if (NULL_PTR != TransferCfgPtr->RxBuffer)
    {
        if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 9u)
        {
            for (Index = 0; Index < ReadNum; Index++)
            {
                Data = BaseW->SPI_DR_LOW;
                *((uint8 *)(&TransferCfgPtr->RxBuffer[TransferCfgPtr->RxIndex + Index])) =
                    (uint8)Data;
            }
        }
        else if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 17u)
        {
            for (Index = 0; Index < ReadNum; Index++)
            {
                Data = BaseW->SPI_DR_LOW;
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint16*, no side effects 
                    forseen by violating this rule. */
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint16*, no side effects 
                    forseen by violating this rule. */
                *((uint16 *)(&TransferCfgPtr->RxBuffer[2u * (TransferCfgPtr->RxIndex + Index)])) =
                    (uint16)Data;
            }
        }
        else
        {
            for (Index = 0; Index < ReadNum; Index++)
            {
                Data = BaseW->SPI_DR_LOW;
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint32*, no side effects 
                    forseen by violating this rule. */
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint32*, no side effects 
                    forseen by violating this rule. */
                *((uint32 *)(&TransferCfgPtr->RxBuffer[4u * (TransferCfgPtr->RxIndex + Index)])) =
                    (uint32)Data;
            }
        }
    }
    else
    {
        for (Index = 0; Index < ReadNum; Index++)
        {
            /* Discard read data */
            (void)BaseW->SPI_DR_LOW;
        }
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function writes Data into FIFO.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @param[in] WriteNum: Number of Data to be written into FIFO.
 *
 * @return    void
 */
LOCAL_INLINE void Spi_Drv_WriteFifo(uint8 Instance, uint8 WriteNum)
{
    Reg_Spi_WType                       *BaseW;
    const Spi_Drv_TransferConfigType    *TransferCfgPtr;
    uint32                      Data;
    uint8                       Index;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    if (NULL_PTR != TransferCfgPtr->TxBuffer)
    {
        if (TransferCfgPtr->FrameSize < 9u)
        {
            for (Index = 0; Index < WriteNum; Index++)
            {
                Data = *((uint8 *)(&TransferCfgPtr->TxBuffer[TransferCfgPtr->TxIndex + Index]));
                BaseW->SPI_DR_LOW = Data;
            }
        }
        else if (TransferCfgPtr->FrameSize < 17u)
        {
            for (Index = 0; Index < WriteNum; Index++)
            {
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint16*, no side effects 
                    forseen by violating this rule. */
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint16*, no side effects 
                    forseen by violating this rule. */
                Data = *(
                    (uint16 *)(&TransferCfgPtr->TxBuffer[2u * (TransferCfgPtr->TxIndex + Index)]));
                BaseW->SPI_DR_LOW = Data;
            }
        }
        else
        {
            for (Index = 0; Index < WriteNum; Index++)
            {
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint32*, no side effects 
                    forseen by violating this rule. */
                /* MISRA2012 Rule-11.3 violation: casting uint8* data to uint32*, no side effects 
                    forseen by violating this rule. */
                Data = *(
                    (uint32 *)(&TransferCfgPtr->TxBuffer[4u * (TransferCfgPtr->TxIndex + Index)]));
                BaseW->SPI_DR_LOW = Data;
            }
        }
    }
    else
    {
        /* Send default data if TxBuffer is NULL */
        Data = TransferCfgPtr->ExternalDevice->DeviceParamPtr->DefaultData;
        for (Index = 0; Index < WriteNum; Index++)
        {
            BaseW->SPI_DR_LOW = Data;
        }
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function will finish transfer of a channel.
 *
 * @param[in] Instance: SPI peripheral instance number.
 *
 * @return    None
 */
static void Spi_Drv_TransferFinished(uint8 Instance)
{
    Spi_Drv_TransferConfigType *TransferCfgPtr;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    TransferCfgPtr->Status = SPI_DRV_IDLE;
    if (TransferCfgPtr->Callback != NULL_PTR)
    {
        TransferCfgPtr->Callback(Instance, SPI_DRV_EVENT_SUCCESS);
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function process transfer of synchronous mode.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @param[in] Timeout: Timeout value for synchronous transfer.
 * @return     Std_ReturnType
 * @retval     E_OK:      Successfully.
 * @retval     E_NOT_OK:  Timeout
 */
static Std_ReturnType Spi_Drv_ProcessSyncTransfer(uint8 Instance, uint32 TimeOut)
{
    const Reg_Spi_BfType       *BaseBf;
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    uint8                       WriteNum;
    uint8                       ReadNum;
    uint32                      CurrentTicks = 0u;
    uint32                      ElapsedTicks = 0u;
    uint32                      TotalElapsedTicks = 0u;
    uint32         TimeoutTicks = McalLib_MicroSecToTicks(SPI_DRV_TIMEOUT_METHOD, TimeOut);
    boolean        TxDoneFlag = FALSE;
    Std_ReturnType Ret = E_OK;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != BaseBf);
    MCALLIB_DEV_ASSERT(NULL_PTR != TransferCfgPtr);
#endif
    (void)McalLib_GetCounterValue(SPI_DRV_TIMEOUT_METHOD, &CurrentTicks);
    while (TransferCfgPtr->RxIndex != TransferCfgPtr->ExpectReadNum)
    {
        /* Read available Data in fifo. */
        ReadNum = (uint8)BaseBf->SPI_FLR.RXTFL;
        if (ReadNum != 0u)
        {
            if (ReadNum > (TransferCfgPtr->ExpectReadNum - TransferCfgPtr->RxIndex))
            {
                ReadNum = (uint8)(TransferCfgPtr->ExpectReadNum - TransferCfgPtr->RxIndex);
            }
            /* Read Data from RX FIFO */
            Spi_Drv_ReadFifo(Instance, ReadNum);
            TransferCfgPtr->RxIndex += ReadNum;
            TransferCfgPtr->CurrentTxFifoSlot += ReadNum;
            TotalElapsedTicks = 0u;
        }

        /* Push Data until HW fifo is full or transfer is done. */
        if ((TransferCfgPtr->CurrentTxFifoSlot != 0u) && (TxDoneFlag != TRUE))
        {
            if (TransferCfgPtr->ExpectWriteNum != TransferCfgPtr->TxIndex)
            {
                WriteNum = TransferCfgPtr->CurrentTxFifoSlot;
                if (WriteNum > (TransferCfgPtr->ExpectWriteNum - TransferCfgPtr->TxIndex))
                {
                    WriteNum = (uint8)(TransferCfgPtr->ExpectWriteNum - TransferCfgPtr->TxIndex);
                }
                /* write Data into TX FIFO */
                Spi_Drv_WriteFifo(Instance, WriteNum);
                TransferCfgPtr->TxIndex += WriteNum;
                TransferCfgPtr->CurrentTxFifoSlot -= WriteNum;
                TotalElapsedTicks = 0u;
            }
            else
            {
                if (TRUE == TransferCfgPtr->NextTransferConfigAvailable)
                {
                    TransferCfgPtr->FirstTransferFlag = FALSE;
                    TransferCfgPtr->NextTransferConfigAvailable = FALSE;
                }
                else
                {
                    TxDoneFlag = TRUE;
                }
            }
        }
        (void)McalLib_GetElapsedValue(SPI_DRV_TIMEOUT_METHOD, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
        /*Z20K14xM_MCAL_SAD_Spi_00006*/
        if (TotalElapsedTicks >= TimeoutTicks)
        {
            Ret = E_NOT_OK;
            break;
        }
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 * @brief     This function process transfer of asynchronous mode.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @return    None
 */
static void Spi_Drv_ProcessAsyncTransfer(uint8 Instance)
{
    const Reg_Spi_BfType             *BaseBf;
    Reg_Spi_WType                     *BaseW;
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    uint8                       WriteNum = 0u;
    uint8                       ReadNum = 0u;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseBf != NULL_PTR);
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    if (SPI_DRV_BUSY == TransferCfgPtr->Status)
    {
        ReadNum = (uint8)BaseBf->SPI_FLR.RXTFL;
        if (ReadNum != 0u)
        {
            if (ReadNum > (TransferCfgPtr->ExpectReadNum - TransferCfgPtr->RxIndex))
            {
                ReadNum = (uint8)(TransferCfgPtr->ExpectReadNum - TransferCfgPtr->RxIndex);
            }
            Spi_Drv_ReadFifo(Instance, ReadNum);
            TransferCfgPtr->RxIndex += ReadNum;
            TransferCfgPtr->CurrentTxFifoSlot += ReadNum;
        }

        if ((TransferCfgPtr->CurrentTxFifoSlot != 0u) && (TransferCfgPtr->TxDoneFlag != TRUE))
        {
            if (TransferCfgPtr->ExpectWriteNum != TransferCfgPtr->TxIndex)
            {
                WriteNum = TransferCfgPtr->CurrentTxFifoSlot;
                if (WriteNum > (TransferCfgPtr->ExpectWriteNum - TransferCfgPtr->TxIndex))
                {
                    WriteNum = (uint8)(TransferCfgPtr->ExpectWriteNum - TransferCfgPtr->TxIndex);
                }
                Spi_Drv_WriteFifo(Instance, WriteNum);
                TransferCfgPtr->TxIndex += WriteNum;
                TransferCfgPtr->CurrentTxFifoSlot -= WriteNum;
            }
            else
            {
                if (TRUE == TransferCfgPtr->NextTransferConfigAvailable)
                {
                    TransferCfgPtr->FirstTransferFlag = FALSE;
                    TransferCfgPtr->NextTransferConfigAvailable = FALSE;
                }
                else
                {
                    TransferCfgPtr->TxDoneFlag = TRUE;
                    /* Disable TXE interrupts */
                    BaseW->SPI_IER &= ~((uint32)0x01U << (uint8)SPI_DRV_INTERRUPT_TXE);
                }
            }
        }

        if (TransferCfgPtr->RxIndex == TransferCfgPtr->ExpectReadNum)
        {
            /* Disable all interrupts */
            BaseW->SPI_IER = 0U;
            Spi_Drv_TransferFinished(Instance);
        }
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#if (STD_ON == SPI_DRV_DMA_USED)
/**
 * @brief     This function configures the TX DMA channels
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @return    None
 */
static void Spi_Drv_ConfigDmaTx(uint8 Instance)
{
    Dma_Drv_ChannelTransferConfigType *DmaChlTransferCfgPtr = &Spi_Drv_DmaChannelTransferConfig;
    Dma_Drv_ChannelGlobalConfigType   *DmaChlGlobalCfgPtr = &Spi_Drv_DmaChannelGlobalConfig;
    const Reg_Spi_WType                 *BaseW;
    Reg_Spi_BfType                      *BaseBf;
    Spi_Drv_TransferConfigType        *TransferCfgPtr;
    uint16                             DmaMaxWriteNum = 0U;
    uint32                             DmaTransferNumAdapter = 0U;
    uint16                             DmaMinorLoopCnt = 0U;
    
    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
    #endif
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
    #endif

    DmaMaxWriteNum = TransferCfgPtr->ExpectWriteNum;
    if (SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT < DmaMaxWriteNum)
    {
        DmaMaxWriteNum = SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT;
    }
#if (STD_OFF == SPI_DRV_DMA_PATCH_ENABLED)
     DmaTransferNumAdapter = 1U;
     DmaMinorLoopCnt = DmaMaxWriteNum;
#else
    /*Special handle for errata: DMA.1: Incorrect trigger when DMA is used to transfer peripheral 
    data;If only one read or write operation is performed in a minor loop, the DMA transfer may 
    be triggered incorrectly*/
    if((1U == (DmaMaxWriteNum % 2U)) && (DmaMaxWriteNum > 3U))
    {
        DmaMaxWriteNum = DmaMaxWriteNum - 3U;
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxWriteNum >> 1U;
    }
    else if(3U == DmaMaxWriteNum)
    {
        DmaTransferNumAdapter = 3U;
        DmaMinorLoopCnt = 1U;
    }
    else if(1U == DmaMaxWriteNum)
    {
        DmaTransferNumAdapter = 1U;
        DmaMinorLoopCnt = 1U;
    }
    else
    {
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxWriteNum >> 1U;
    }
#endif

    /* Set transmit request level */
    BaseBf->SPI_DMATDLR.DMATDL = 0U;

    /* Update buffers index */
    TransferCfgPtr->TxIndex = DmaMaxWriteNum;

    DmaChlGlobalCfgPtr->RequestConfig = &Spi_Drv_DmaChannelRequestConfig;
    DmaChlGlobalCfgPtr->PriorityConfig = &Spi_Drv_DmaChannelPriorityConfig;
    /* Select Spi Tx as the DMA request */
    DmaChlGlobalCfgPtr->RequestConfig->MuxReqSrc =
        (Dma_Drv_RequestSourceType)(Spi_Drv_TxDmaReqSource[Instance]);
    /* Set request enable */
    DmaChlGlobalCfgPtr->RequestConfig->ReqEn = (boolean)TRUE;
    /* Mask Error interrupt */
    DmaChlGlobalCfgPtr->ErrIntEn = (boolean)FALSE;
    /* Mask done interrupt */
    DmaChlGlobalCfgPtr->MajorIntEn = (boolean)FALSE;
    /* DMA channel priority */
    DmaChlGlobalCfgPtr->PriorityConfig->Priority = (sint8)DMA_DRV_PRIORITY_LEVEL_0;
    /* Disable preemption */
    DmaChlGlobalCfgPtr->PriorityConfig->PreemptionDis = (boolean)TRUE;
    /* Disable suspend */
    DmaChlGlobalCfgPtr->PriorityConfig->SuspendEn = (boolean)FALSE;
    /* set DMA channel global configuration */
    Dma_Drv_SetChannelGlobalConfig((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel,
                                   DmaChlGlobalCfgPtr);

    DmaChlTransferCfgPtr->SourceConfig = &Spi_Drv_DmaChannelSourceConfig;
    DmaChlTransferCfgPtr->DestinationConfig = &Spi_Drv_DmaChannelDestinationConfig;
    DmaChlTransferCfgPtr->ControlConfig = &Spi_Drv_DmaChannelControlConfig;

    if (TransferCfgPtr->FrameSize < 9U)
    {
        DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = (sint16)1U; /* src offset is 1 byte */
        /* Source data transfer size */
        DmaChlTransferCfgPtr->SourceConfig->TransferSize =
            DMA_DRV_TRANSFER_SIZE_1BYTE; /* 1 bytes src transfer size */
        /* Destination data transfer size */
        DmaChlTransferCfgPtr->DestinationConfig->TransferSize =
            DMA_DRV_TRANSFER_SIZE_1BYTE; /* 1 bytes src transfer size */
        /* Transfer bytes number */
        DmaChlTransferCfgPtr->ControlConfig->TransferNum =
            DmaTransferNumAdapter; /* bytes to transfer for each request */
    }
    else if (TransferCfgPtr->FrameSize < 17U)
    {
        DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = (sint16)2U; /* src offset is 2 bytes */
        /* Source data transfer size */
        DmaChlTransferCfgPtr->SourceConfig->TransferSize =
            DMA_DRV_TRANSFER_SIZE_2BYTE; /* 2 bytes src transfer size */
        /* Destination data transfer size */
        DmaChlTransferCfgPtr->DestinationConfig->TransferSize =
            DMA_DRV_TRANSFER_SIZE_2BYTE; /* 2 bytes src transfer size */
        /* Transfer bytes number */
        DmaChlTransferCfgPtr->ControlConfig->TransferNum =
            DmaTransferNumAdapter << 1U; /* bytes to transfer for each request */
    }
    else
    {
        DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = (sint16)4U; /* src offset is 4 bytes */
        /* Source data transfer size */
        DmaChlTransferCfgPtr->SourceConfig->TransferSize =
            DMA_DRV_TRANSFER_SIZE_4BYTE; /* 4 bytes src transfer size */
        /* Destination data transfer size */
        DmaChlTransferCfgPtr->DestinationConfig->TransferSize =
            DMA_DRV_TRANSFER_SIZE_4BYTE; /* 4 bytes src transfer size */
        /* Transfer bytes number */
        DmaChlTransferCfgPtr->ControlConfig->TransferNum =
            DmaTransferNumAdapter << 2U; /* bytes to transfer for each request */
    }
    /* Address pointing to the source data */
    if (NULL_PTR == TransferCfgPtr->TxBuffer)
    {
        /* send default Data */
        /* MISRA2012 Rule-11.4 violation: Convert a pointer of data address to an integral type of
        DMA address, no side effects forseen by violating this rule. */
        DmaChlTransferCfgPtr->SourceConfig->Addr =
            (uint32)&TransferCfgPtr->ExternalDevice->DeviceParamPtr->DefaultData;
        DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = (sint16)0U; /* src offset is 0 byte */
    }
    else
    {
        /* MISRA2012 Rule-11.4 violation: Convert a pointer of data address to an integral type of
        DMA address, no side effects forseen by violating this rule. */
        DmaChlTransferCfgPtr->SourceConfig->Addr =
            (uint32)TransferCfgPtr->TxBuffer; /* src address read */
    }

    /* Address pointing to the destination data */
    /* MISRA2012 Rule-11.4 violation: Convert a pointer of data address to an integral type of
    DMA address, no side effects forseen by violating this rule. */
    DmaChlTransferCfgPtr->DestinationConfig->Addr = (uint32)&BaseW->SPI_DR_LOW;
    /* Number of minor loop in a major loop */
    DmaChlTransferCfgPtr->ControlConfig->MinorLoopCnt = DmaMinorLoopCnt;
    /* Destination address offset in minor loop */
    DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = (sint16)0U;
    /* Source address offset after a major loop done */
    DmaChlTransferCfgPtr->SourceConfig->MajorLoopOffset = (sint16)0U;
    /* Destination address offset after a major loop done */
    DmaChlTransferCfgPtr->DestinationConfig->MajorLoopOffset = (sint16)0U;
    /* Enable request after done control */
    DmaChlTransferCfgPtr->ControlConfig->ReqDis = (boolean)TRUE;
    /* set DMA channel transfer configuration */
    Dma_Drv_SetChannelTransferConfig(
        (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel, DmaChlTransferCfgPtr);
    /* Enable dma channel request*/
    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel);

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif
}

/**
 * @brief     This function configures the RX DMA channels
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @return    None
 */
static void Spi_Drv_ConfigDmaRx(uint8 Instance)
{
    Dma_Drv_ChannelTransferConfigType *DmaChlTransferCfgPtr = &Spi_Drv_DmaChannelTransferConfig;
    Dma_Drv_ChannelGlobalConfigType   *DmaChlGlobalCfgPtr = &Spi_Drv_DmaChannelGlobalConfig;
    const Reg_Spi_WType                 *BaseW;
    Reg_Spi_BfType                    *BaseBf;
    Spi_Drv_TransferConfigType        *TransferCfgPtr;
    uint16                             DmaMaxReadNum = 0U;
    uint32                             DmaTransferNumAdapter = 0U;
    uint16                             DmaMinorLoopCnt = 0U;
    uint32                             DmaReceiveReqLevel = 0U;

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
    #endif
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
    #endif

    DmaMaxReadNum = TransferCfgPtr->ExpectReadNum;

    if (SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT < DmaMaxReadNum)
    {
        DmaMaxReadNum = SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT;
    }
#if (STD_OFF == SPI_DRV_DMA_PATCH_ENABLED)
    DmaTransferNumAdapter = 1U;
    DmaMinorLoopCnt = DmaMaxReadNum;
    DmaReceiveReqLevel = 0U;
#else
    /*Special handle for errata: DMA.1: Incorrect trigger when DMA is used to transfer peripheral 
    data;If only one read or write operation is performed in a minor loop, the DMA transfer may 
    be triggered incorrectly*/
    if((1U == (DmaMaxReadNum % 2U)) && (DmaMaxReadNum > 3U))
    {
        DmaMaxReadNum = DmaMaxReadNum - 3U;
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxReadNum >> 1U;
        DmaReceiveReqLevel = 1U;
    }
    else if(3U == DmaMaxReadNum)
    {
        DmaTransferNumAdapter = 3U;
        DmaMinorLoopCnt = 1U;
        DmaReceiveReqLevel = 2U;
    }
    else if(1U == DmaMaxReadNum)
    {
        DmaTransferNumAdapter = 1U;
        DmaMinorLoopCnt = 1U;
        DmaReceiveReqLevel = 0U;
    }
    else
    {
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxReadNum >> 1U;
        DmaReceiveReqLevel = 1U;
    }
#endif
    /* Set receive request level */
    BaseBf->SPI_DMARDLR.DMARDL = DmaReceiveReqLevel;

    /* Update buffers index */
    TransferCfgPtr->RxIndex = DmaMaxReadNum;

    DmaChlGlobalCfgPtr->RequestConfig = &Spi_Drv_DmaChannelRequestConfig;
    DmaChlGlobalCfgPtr->PriorityConfig = &Spi_Drv_DmaChannelPriorityConfig;
    /* Select Spi Rx as the DMA request */
    DmaChlGlobalCfgPtr->RequestConfig->MuxReqSrc =
        (Dma_Drv_RequestSourceType)(Spi_Drv_RxDmaReqSource[Instance]);
    /* Set request enable */
    DmaChlGlobalCfgPtr->RequestConfig->ReqEn = (boolean)TRUE;
    /* Mask Error interrupt */
    DmaChlGlobalCfgPtr->ErrIntEn = (boolean)FALSE;
    /* Mask done interrupt */
    DmaChlGlobalCfgPtr->MajorIntEn = (boolean)FALSE;
    /* DMA channel priority */
    DmaChlGlobalCfgPtr->PriorityConfig->Priority = (sint8)DMA_DRV_PRIORITY_LEVEL_1;
    /* Disable preemption */
    DmaChlGlobalCfgPtr->PriorityConfig->PreemptionDis = (boolean)TRUE;
    /* Disable suspend */
    DmaChlGlobalCfgPtr->PriorityConfig->SuspendEn = (boolean)FALSE;
    /* set DMA channel global configuration */
    Dma_Drv_SetChannelGlobalConfig((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel,
                                   DmaChlGlobalCfgPtr);

    DmaChlTransferCfgPtr->SourceConfig = &Spi_Drv_DmaChannelSourceConfig;
    DmaChlTransferCfgPtr->DestinationConfig = &Spi_Drv_DmaChannelDestinationConfig;
    DmaChlTransferCfgPtr->ControlConfig = &Spi_Drv_DmaChannelControlConfig;

    if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 9U)
    {
        /* dest offset is 1 byte */
        DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = (sint16)1U;
        /* Source data transfer size, 1 bytes src transfer size*/
        DmaChlTransferCfgPtr->SourceConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_1BYTE;
        /* Destination data transfer size, 1 bytes src transfer size */
        DmaChlTransferCfgPtr->DestinationConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_1BYTE;
        /* Transfer bytes number for each request */
        DmaChlTransferCfgPtr->ControlConfig->TransferNum = DmaTransferNumAdapter;
    }
    else if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 17U)
    {
        /* dest offset is 2 bytes */
        DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = (sint16)2U;
        /* Source data transfer size, 2 bytes src transfer size */
        DmaChlTransferCfgPtr->SourceConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;
        /* Destination data transfer size, 2 bytes src transfer size */
        DmaChlTransferCfgPtr->DestinationConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_2BYTE;
        /* Transfer bytes number for each request */
        DmaChlTransferCfgPtr->ControlConfig->TransferNum = DmaTransferNumAdapter << 1U;
    }
    else
    {
        /* dest offset is 4 bytes */
        DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = (sint16)4U;
        /* Source data transfer size, 4 bytes dest transfer size */
        DmaChlTransferCfgPtr->SourceConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_4BYTE;
        /* Destination data transfer size, 4 bytes src transfer size */
        DmaChlTransferCfgPtr->DestinationConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_4BYTE;
        /* Transfer bytes number for each request */
        DmaChlTransferCfgPtr->ControlConfig->TransferNum = DmaTransferNumAdapter << 2U;
    }
    /* Address pointing to the source data */
    if (NULL_PTR == TransferCfgPtr->RxBuffer)
    {
        /* dest address read */
        /* MISRA2012 Rule-11.4 violation: Convert a pointer of data address to an integral type of
        DMA address, no side effects forseen by violating this rule. */
        DmaChlTransferCfgPtr->DestinationConfig->Addr = (uint32)&Spi_Drv_DmaDiscardData;
        /* dest offset is 0 byte */
        DmaChlTransferCfgPtr->DestinationConfig->MinorLoopOffset = (sint16)0U;
    }
    else
    {
        /* dest address read */
        /* MISRA2012 Rule-11.4 violation: Convert a pointer of data address to an integral type of
        DMA address, no side effects forseen by violating this rule. */
        DmaChlTransferCfgPtr->DestinationConfig->Addr = (uint32)TransferCfgPtr->RxBuffer;
    }

    /* Address pointing to the source data */
    /* MISRA2012 Rule-11.4 violation: Convert a pointer of data address to an integral type of
    DMA address, no side effects forseen by violating this rule. */
    DmaChlTransferCfgPtr->SourceConfig->Addr = (uint32)&BaseW->SPI_DR_LOW;
    /* Number of minor loop in a major loop */
    DmaChlTransferCfgPtr->ControlConfig->MinorLoopCnt = DmaMinorLoopCnt;
    /* source address offset in minor loop */
    DmaChlTransferCfgPtr->SourceConfig->MinorLoopOffset = (sint16)0U;
    /* Source address offset after a major loop done */
    DmaChlTransferCfgPtr->SourceConfig->MajorLoopOffset = (sint16)0U;
    /* Destination address offset after a major loop done */
    DmaChlTransferCfgPtr->DestinationConfig->MajorLoopOffset = (sint16)0U;
    /* Enable request after done control */
    DmaChlTransferCfgPtr->ControlConfig->ReqDis = (boolean)TRUE;
    /* set DMA channel transfer configuration */
    Dma_Drv_SetChannelTransferConfig(
        (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel, DmaChlTransferCfgPtr);

    /* Enable dma channel request */
    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel);

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif
}

/**
 * @brief     This function configures the TX DMA channel to continue transfer.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @return    None
 */
static void Spi_Drv_ContinueDmaTxTransfer(uint8 Instance)
{
    Reg_Spi_BfType              *BaseBf;
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    uint16                      DmaMaxWriteNum = 0U;
    uint32                      DmaTransferNumAdapter = 0U;
    uint16                      DmaMinorLoopCnt = 0U;
    uint32                      DmaTransferReqLevel = 0U;
    uint32                      DmaTransferNum = 0U;

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
    #endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
    #endif

    DmaMaxWriteNum = TransferCfgPtr->ExpectWriteNum - TransferCfgPtr->TxIndex;

    if (SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT < DmaMaxWriteNum)
    {
        DmaMaxWriteNum = SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT;
    }
#if (STD_OFF == SPI_DRV_DMA_PATCH_ENABLED)
    DmaTransferNumAdapter = 1U;
    DmaMinorLoopCnt = DmaMaxWriteNum;
    DmaTransferReqLevel = 0U;
#else
    /*Special handle for errata: DMA.1: Incorrect trigger when DMA is used to transfer peripheral 
    data;If only one read or write operation is performed in a minor loop, the DMA transfer may 
    be triggered incorrectly*/
    if((1U == (DmaMaxWriteNum % 2U)) && (DmaMaxWriteNum > 3U))
    {
        DmaMaxWriteNum = DmaMaxWriteNum - 3U;
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxWriteNum >> 1U;
        DmaTransferReqLevel = 2U;
    }
    else if(3U == DmaMaxWriteNum)
    {
        DmaTransferNumAdapter = 3U;
        DmaMinorLoopCnt = 1U;
        DmaTransferReqLevel = 1U;
    }
    else if(1U == DmaMaxWriteNum)
    {
        DmaTransferNumAdapter = 1U;
        DmaMinorLoopCnt = 1U;
        DmaTransferReqLevel = 3U;
    }
    else
    {
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxWriteNum >> 1U;
        DmaTransferReqLevel = 2U;
    }
#endif
    /* Set receive request level */
    BaseBf->SPI_DMATDLR.DMATDL = DmaTransferReqLevel;

    TransferCfgPtr->TxIndex += DmaMaxWriteNum;

    if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 9U)
    {
        /* Transfer bytes number for each request */
        DmaTransferNum = DmaTransferNumAdapter;
    }
    else if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 17U)
    {
        /* Transfer bytes number for each request */
        DmaTransferNum = DmaTransferNumAdapter * 2U;
    }
    else
    {
        /* Transfer bytes number for each request */
        DmaTransferNum = DmaTransferNumAdapter * 4U;
    }

    Dma_Drv_SetMinorLoopNum((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel, DmaMinorLoopCnt);
    Dma_Drv_SetTransferByteNum((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel, DmaTransferNum);

    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel);

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif
}

/**
 * @brief     This function configures the RX DMA channel to continue transfer.
 *
 * @param[in] Instance: SPI peripheral instance number.
 *
 * @return    None
 */
static void Spi_Drv_ContinueDmaRxTransfer(uint8 Instance)
{
    Reg_Spi_BfType                    *BaseBf;
    Spi_Drv_TransferConfigType        *TransferCfgPtr;
    uint16                             DmaMaxReadNum = 0U;
    uint32                             DmaTransferNumAdapter = 0U;
    uint16                             DmaMinorLoopCnt = 0U;
    uint32                             DmaReceiveReqLevel = 0U;
    uint32                             DmaTransferNum = 0U;

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
    #endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
    #endif

    DmaMaxReadNum = TransferCfgPtr->ExpectReadNum - TransferCfgPtr->RxIndex;

    if (SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT < DmaMaxReadNum)
    {
        DmaMaxReadNum = SPI_DRV_MAX_DMA_MINOR_LOOP_COUNT;
    }
#if (STD_OFF == SPI_DRV_DMA_PATCH_ENABLED)
    DmaTransferNumAdapter = 1U;
    DmaMinorLoopCnt = DmaMaxReadNum;
    DmaReceiveReqLevel = 0U;
#else
    /*Special handle for errata: DMA.1: Incorrect trigger when DMA is used to transfer peripheral 
    data;If only one read or write operation is performed in a minor loop, the DMA transfer may 
    be triggered incorrectly*/
    if((1U == (DmaMaxReadNum % 2U)) && (DmaMaxReadNum > 3U))
    {
        DmaMaxReadNum = DmaMaxReadNum - 3U;
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxReadNum >> 1U;
        DmaReceiveReqLevel = 1U;
    }
    else if(3U == DmaMaxReadNum)
    {
        DmaTransferNumAdapter = 3U;
        DmaMinorLoopCnt = 1U;
        DmaReceiveReqLevel = 2U;
    }
    else if(1U == DmaMaxReadNum)
    {
        DmaTransferNumAdapter = 1U;
        DmaMinorLoopCnt = 1U;
        DmaReceiveReqLevel = 0U;
    }
    else
    {
        DmaTransferNumAdapter = 2U;
        DmaMinorLoopCnt = DmaMaxReadNum >> 1U;
        DmaReceiveReqLevel = 1U;
    }
#endif
    /* Set receive request level */
    BaseBf->SPI_DMARDLR.DMARDL = DmaReceiveReqLevel;

    TransferCfgPtr->RxIndex += DmaMaxReadNum;

    if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 9U)
    {
        /* Transfer bytes number for each request */
        DmaTransferNum = DmaTransferNumAdapter;
    }
    else if (TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize < 17U)
    {
        /* Transfer bytes number for each request */
        DmaTransferNum = DmaTransferNumAdapter << 1U;
    }
    else
    {
        /* Transfer bytes number for each request */
        DmaTransferNum = DmaTransferNumAdapter << 2U;
    }

    Dma_Drv_SetMinorLoopNum((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel, DmaMinorLoopCnt);
    Dma_Drv_SetTransferByteNum((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel, DmaTransferNum);

    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel);

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif
}

/**
 * @brief     This function finish DMA transfer.
 *
 * @param[in] Instance: SPI peripheral instance number.
 *
 * @return    None
 */
static void Spi_Drv_FinishDmaTxTransfer(const uint8 Instance)
{
    Spi_Drv_TransferConfigType *TransferCfgPtr;

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
    #endif

    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
    #endif
    if (TRUE == TransferCfgPtr->NextTransferConfigAvailable)
    {
        TransferCfgPtr->FirstTransferFlag = FALSE;
        TransferCfgPtr->NextTransferConfigAvailable = FALSE;
    }

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif
}
#endif /* STD_ON == SPI_DRV_DMA_USED */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @brief     The function initializes the SPI hardware unit of a given configuration.
 *
 * @param[in] PhyUnitConfigPtr: Pointer to the SPI HW Unit configuration
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_Init(const Spi_Drv_PhyUnitConfigType *PhyUnitConfigPtr)
{
    Reg_Spi_BfType             *BaseBf;
    Reg_Spi_WType              *BaseW;
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    Std_ReturnType              Ret = E_OK;
    uint8                       Instance = 0u;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(PhyUnitConfigPtr != NULL_PTR);
#endif
    Instance = PhyUnitConfigPtr->Instance;
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    Spi_Drv_TransferConfigPtrArray[Instance] = &Spi_Drv_TransferConfigArray[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseBf != NULL_PTR);
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif
    TransferCfgPtr->PhyUnitConfig = PhyUnitConfigPtr;
    TransferCfgPtr->ContinueTransferFlag = FALSE;
    TransferCfgPtr->FirstTransferFlag = TRUE;
    /* Set Status to idle */
    TransferCfgPtr->Status = SPI_DRV_IDLE;
    (void)Spi_Drv_SetAsyncMode(Instance, PhyUnitConfigPtr->AsyncMode);

    /* Disable all interrupts */
    BaseW->SPI_IER = 0U;
    BaseBf->SPI_SSENR.SPI_EN = FALSE;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief     The function de-initializes the SPI hardware unit.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_DeInit(uint8 Instance)
{
    Reg_Spi_BfType                   *BaseBf;
    const Spi_Drv_TransferConfigType *TransferCfgPtr;
    Std_ReturnType                    Ret = E_OK;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != BaseBf);
    MCALLIB_DEV_ASSERT(NULL_PTR != TransferCfgPtr);
#endif
    if (SPI_DRV_BUSY == TransferCfgPtr->Status)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        /* Disable Spi hardware. */
        BaseBf->SPI_SSENR.SPI_EN = 0U;
        Spi_Drv_TransferConfigPtrArray[Instance] = NULL_PTR;
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief     This function updates Frame Size, default data and Lsb of a given external device.
 *
 * @param[in] DevicePtr: Pointer to the external device configuration
 * @param[in] FrameSize: Frame Size
 * @param[in] Lsb: Lsb or Msb first
 * @param[in] DefaultData: Default data of transmission
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully
 * @retval    E_NOT_OK: Failed
 */
Std_ReturnType Spi_Drv_SetDeviceParams(const Spi_Drv_ExternalDeviceType *DevicePtr, uint8 FrameSize,
                                       boolean Lsb, uint32 DefaultData)
{
    const Spi_Drv_TransferConfigType *TransferCfgPtr;
    Std_ReturnType                    Ret = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != DevicePtr);
#endif
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[DevicePtr->Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != TransferCfgPtr);
#endif
    if (TransferCfgPtr->Status != SPI_DRV_BUSY)
    {
        DevicePtr->DeviceParamPtr->FrameSize = FrameSize;
        DevicePtr->DeviceParamPtr->Lsb = Lsb;
        DevicePtr->DeviceParamPtr->DefaultData = DefaultData;
        Ret = E_OK;
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief     The function initializes a synchronous transmission.
 *
 * @param[in] ExternalDevice: Pointer to the external device configuration
 * @param[in] TxBuffer: Pointer to Tx buffer
 * @param[in,out] RxBuffer: Pointer to Rx buffer
 * @param[in] Length: Number of bytes to be sent
 * @param[in] TimeOut: Wait time to avoid end loop
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_SyncTransmit(const Spi_Drv_ExternalDeviceType *ExternalDevice,
                                    uint8 *TxBuffer, uint8 *RxBuffer, uint16 Length, uint32 TimeOut)
{
    Reg_Spi_WType              *BaseW;
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    Std_ReturnType              Ret = E_OK;
    uint8                       Instance = 0u;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ExternalDevice);
    MCALLIB_DEV_ASSERT(0U != Length);
    MCALLIB_DEV_ASSERT(0U != TimeOut);
    Spi_Drv_CheckDataLength(ExternalDevice->DeviceParamPtr->FrameSize, Length);
#endif
    Instance = ExternalDevice->Instance;
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    SchM_Enter_Spi_UpdateTransferStatus();
    if (SPI_DRV_BUSY == TransferCfgPtr->Status)
    {
        SchM_Exit_Spi_UpdateTransferStatus();
        Ret = E_NOT_OK;
    }
    else
    {
        TransferCfgPtr->Status = SPI_DRV_BUSY;
        SchM_Exit_Spi_UpdateTransferStatus();

        TransferCfgPtr->ExternalDevice = ExternalDevice;
        /* Update TransferCfgPtr structure. */
        TransferCfgPtr->NextTransferConfigAvailable = TransferCfgPtr->ContinueTransferFlag;
        /* Disable all interrupts */
        BaseW->SPI_IER = 0U;
        if (TRUE == TransferCfgPtr->FirstTransferFlag)
        {
            /* Reset current FIFO slots */
            TransferCfgPtr->CurrentTxFifoSlot = SPI_DRV_FIFO_SIZE;
            Spi_Drv_InitTxTransfer(Instance, TxBuffer,
                                   TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize,
                                   TransferCfgPtr->ExternalDevice->DeviceParamPtr->Lsb, Length);
        }
        else
        {
            Spi_Drv_UpdateTxTransfer(Instance, TxBuffer,
                                     TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize,
                                     TransferCfgPtr->ExternalDevice->DeviceParamPtr->Lsb, Length);
        }
        Spi_Drv_InitRxTransfer(Instance, RxBuffer,
                               TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize, Length);

        Ret = Spi_Drv_ProcessSyncTransfer(Instance, TimeOut);

        if (E_OK != Ret)
        {
            TransferCfgPtr->Status = SPI_DRV_FAULT;
        }
        else
        {
            TransferCfgPtr->Status = SPI_DRV_IDLE;
        }
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief     The function initializes a asynchronous transmission.
 *
 * @param[in] ExternalDevice: Pointer to the external device configuration
 * @param[in] TxBuffer: Pointer to Tx buffer
 * @param[in,out] RxBuffer: Pointer to Rx buffer
 * @param[in] Length: Number of bytes to be sent
 * @param[in] EndCallback: Callback function at the end of transfer.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_AsyncTransmit(const Spi_Drv_ExternalDeviceType *ExternalDevice,
                                     uint8 *TxBuffer, uint8 *RxBuffer, uint16 Length,
                                     Spi_Drv_CallbackType EndCallback)
{
    Reg_Spi_WType              *BaseW;
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    Std_ReturnType              Status = E_OK;
    uint8                       Instance = 0u;
#if (STD_ON == SPI_DRV_DMA_USED)
    boolean DmaIntEnabled = FALSE;
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(ExternalDevice != NULL_PTR);
    MCALLIB_DEV_ASSERT(0U != Length);
    Spi_Drv_CheckDataLength(ExternalDevice->DeviceParamPtr->FrameSize, Length);
#endif
    Instance = ExternalDevice->Instance;
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    SchM_Enter_Spi_UpdateTransferStatus();
    if (SPI_DRV_BUSY == TransferCfgPtr->Status)
    {
        SchM_Exit_Spi_UpdateTransferStatus();
        Status = E_NOT_OK;
    }
    else
    {
        TransferCfgPtr->Status = SPI_DRV_BUSY;
        SchM_Exit_Spi_UpdateTransferStatus();
        TransferCfgPtr->ExternalDevice = ExternalDevice;

        /* Update TransferCfgPtr structure. */
        TransferCfgPtr->Callback = EndCallback;
        TransferCfgPtr->NextTransferConfigAvailable = TransferCfgPtr->ContinueTransferFlag;

        /* Reset TX done flag */
        TransferCfgPtr->TxDoneFlag = FALSE;

        /* Spi hardware configuration */
        if (TRUE == TransferCfgPtr->FirstTransferFlag)
        {
            /* Update current FIFO slots are available to fill .*/
            TransferCfgPtr->CurrentTxFifoSlot = SPI_DRV_FIFO_SIZE;
            /* In setting up Transmit command register, the RXMSK is also cleared */
            Spi_Drv_InitTxTransfer(Instance, TxBuffer,
                                   TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize,
                                   TransferCfgPtr->ExternalDevice->DeviceParamPtr->Lsb, Length);
        }
        else
        {

            Spi_Drv_UpdateTxTransfer(
                Instance, TxBuffer, TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize,
                TransferCfgPtr->ExternalDevice->DeviceParamPtr->Lsb, Length);
            
        }
        Spi_Drv_InitRxTransfer(Instance, RxBuffer,
                               TransferCfgPtr->ExternalDevice->DeviceParamPtr->FrameSize, Length);

#if (STD_ON == SPI_DRV_DMA_USED)
        if (FALSE == TransferCfgPtr->PhyUnitConfig->DmaUsed)
#endif
        {
            switch (TransferCfgPtr->AsyncMode)
            {
                case SPI_DRV_POLLING:
                    /* Disable all interrupts. */
                    BaseW->SPI_IER = 0U;
                    break;
                case SPI_DRV_INTERRUPT:
                    SchM_Enter_Spi_WriteInterruptMaskReg();
                    BaseW->SPI_IER |= (uint32)0x01U << (uint8)SPI_DRV_INTERRUPT_TXE;
                    BaseW->SPI_IER |= (uint32)0x01U << (uint8)SPI_DRV_INTERRUPT_RXF;
                    SchM_Exit_Spi_WriteInterruptMaskReg();
                    break;
                default:
                    /* nothing to do */
                    break;
            }
        }
#if (STD_ON == SPI_DRV_DMA_USED)
        else
        {
            /* Disable all interrupts */
            BaseW->SPI_IER = 0U;

            /* Call function to configure TX DMA channel */
            Spi_Drv_ConfigDmaTx(Instance);

            /* Call function to configure RX DMA channel*/
            Spi_Drv_ConfigDmaRx(Instance);

            /* Activate TX DMA and RX DMA interrupt
            in interrupt mode or disable then in polling mode. */
            switch (TransferCfgPtr->AsyncMode)
            {
                case SPI_DRV_POLLING:
                    /* Disable DMA major interrupt. */
                    DmaIntEnabled = FALSE;
                    break;
                case SPI_DRV_INTERRUPT:
                    /* Enable DMA major interrupt. */
                    DmaIntEnabled = TRUE;
                    break;
                default:
                    /* Nothing to do */
                    break;
            }
            Dma_Drv_ControlInt((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel,
                               DMA_DRV_INT_DONE, DmaIntEnabled);
            Dma_Drv_ControlInt((Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel,
                               DMA_DRV_INT_DONE, DmaIntEnabled);

            /* Enable Dma requests */
            BaseW->SPI_DMACR = SPI_DRV_REG_DMACR_TDMAE(1) | SPI_DRV_REG_DMACR_RDMAE(1);
        }
#endif
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Status;
}

/**
 * @brief     This function polls the SPI interrupts for asynchronous transmission.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    None
 */
void Spi_Drv_PollAsyncTransmit(uint8 Instance)
{
    const Reg_Spi_WType                 *BaseW;
    const Spi_Drv_TransferConfigType  *TransferCfgPtr;
    boolean                           RawIntTxeStatus;
    boolean                           RawIntRxfStatus;
#if (STD_ON == SPI_DRV_DMA_USED)
    boolean                           DmaRxDoneStatus;
    boolean                           DmaTxDoneStatus;
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif
    if (SPI_DRV_POLLING == TransferCfgPtr->AsyncMode)
    {
#if (STD_ON == SPI_DRV_DMA_USED)
        if (FALSE == TransferCfgPtr->PhyUnitConfig->DmaUsed)
#endif
        {
            RawIntTxeStatus =
                (boolean)((BaseW->SPI_ISR >> ((uint32)SPI_DRV_INTERRUPT_TXE + 16U)) & 1U);
            RawIntRxfStatus =
                (boolean)((BaseW->SPI_ISR >> ((uint32)SPI_DRV_INTERRUPT_RXF + 16U)) & 1U);
            if (((TRUE == RawIntTxeStatus) && (0U != TransferCfgPtr->CurrentTxFifoSlot)) ||
                (TRUE == RawIntRxfStatus))
            {
                Spi_Drv_ProcessAsyncTransfer(Instance);
            }
        }
#if (STD_ON == SPI_DRV_DMA_USED)
        else
        {
            DmaRxDoneStatus = Dma_Drv_GetDoneStatus(
                            (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel);
            DmaTxDoneStatus = Dma_Drv_GetDoneStatus(
                            (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel);

            if ((TRUE == DmaRxDoneStatus) && (TRUE == DmaTxDoneStatus))
            {
                (void)Dma_Drv_ClearDoneStatus(
                    (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel);
                Spi_Drv_DmaTxIntHandler(Instance);
                
                (void)Dma_Drv_ClearDoneStatus(
                    (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel);
                Spi_Drv_DmaRxIntHandler(Instance);

            }
        }
#endif
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function set polling or interrupt mode for asynchronous transmission.
 *
 * @param[in] Instance: SPI peripheral instance number
 * @param[in] Mode: Polling or Interrupt mode.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_SetAsyncMode(uint8 Instance, Spi_Drv_AsyncModeType Mode)
{
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    Std_ReturnType              Ret = E_OK;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != TransferCfgPtr);
#endif
    if (TransferCfgPtr->Status != SPI_DRV_BUSY)
    {
        TransferCfgPtr->AsyncMode = Mode;
    }
    else
    {
        Ret = E_NOT_OK;
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief     This function cancels current asynchronous transmission.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    None
 */
void Spi_Drv_Cancel(uint8 Instance)
{
    Spi_Drv_TransferConfigType *TransferCfgPtr;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != TransferCfgPtr);
#endif
    SchM_Enter_Spi_UpdateTransferStatus();
    if (SPI_DRV_BUSY == TransferCfgPtr->Status)
    {
        /* @todo: cancel handling to be added */
#if (STD_ON == SPI_DRV_DMA_USED)
        if (TRUE == TransferCfgPtr->PhyUnitConfig->DmaUsed)
        {
            Dma_Drv_DisableChannelRequest(
                (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->RxDmaChannel);
            Dma_Drv_DisableChannelRequest(
                (Dma_Drv_ChannelType)TransferCfgPtr->PhyUnitConfig->TxDmaChannel);
        }
#endif
        TransferCfgPtr->Status = SPI_DRV_IDLE;
    }
    SchM_Exit_Spi_UpdateTransferStatus();

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function gets status of hardware unit.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    Spi_Drv_StatusType
 * @retval    SPI_DRV_UNINIT
 * @retval    SPI_DRV_IDLE
 * @retval    SPI_DRV_BUSY
 * @retval    SPI_DRV_FAULT
 */
Spi_Drv_StatusType Spi_Drv_GetStatus(uint8 Instance)
{
    const Spi_Drv_TransferConfigType *TransferCfgPtr;
    Spi_Drv_StatusType                Status = SPI_DRV_UNINIT;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
#endif

    Status = TransferCfgPtr->Status;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/**
 * @brief     This function processes SPI ISR.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    None
 */
void Spi_Drv_IntHandler(uint8 Instance)
{
    const Reg_Spi_BfType                   *BaseBf;
    const Reg_Spi_WType                    *BaseW;
    boolean                           IntTxeStatus;
    boolean                           IntRxfStatus;

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
#endif
    BaseBf = Spi_Drv_SpiRegBfPtr[Instance];
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseBf != NULL_PTR);
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
#endif

    IntTxeStatus = (boolean)((BaseW->SPI_ISR >> (uint32)SPI_DRV_INTERRUPT_TXE) & 1U);
    IntRxfStatus = (boolean)((BaseW->SPI_ISR >> (uint32)SPI_DRV_INTERRUPT_RXF) & 1U);
    if ((TRUE == IntTxeStatus) || (TRUE == IntRxfStatus))
    {
        Spi_Drv_ProcessAsyncTransfer(Instance);
    }
    else
    {
        (void)BaseBf->SPI_ICR.ICR;
    }

#if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#if (STD_ON == SPI_DRV_DMA_USED)
/**
 * @brief     This function process DMA interrupt when Tx transfer is completed.
 *
 * @param[in] Instance: SPI peripheral instance number.
 *
 * @return    None
 */
void Spi_Drv_DmaTxIntHandler(uint8 Instance)
{
    const Spi_Drv_TransferConfigType *TransferCfgPtr;

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
    #endif
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
    #endif

    if (SPI_DRV_BUSY == TransferCfgPtr->Status)
    {
        if (TransferCfgPtr->ExpectWriteNum != TransferCfgPtr->TxIndex)
        {
            /* Transfer is not finished, continue once last Rx finished */

        }
        else
        {
            Spi_Drv_FinishDmaTxTransfer(Instance);
        }
    }
    else
    {
        /* Nothing to do */
    }

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif
}

/**
 * @brief     This function process DMA interrupt when Rx transfer is completed.
 *
 * @param[in] Instance: SPI peripheral instance number.
 *
 * @return    None
 */
void Spi_Drv_DmaRxIntHandler(uint8 Instance)
{
    Reg_Spi_WType              *BaseW;
    Spi_Drv_TransferConfigType *TransferCfgPtr;
    boolean                     EndOfTransferFlag = FALSE;

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    #endif

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Instance < SPI_DRV_HWUNITS_COUNT);
    #endif
    BaseW = Spi_Drv_SpiRegWPtr[Instance];
    TransferCfgPtr = Spi_Drv_TransferConfigPtrArray[Instance];
    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(BaseW != NULL_PTR);
    MCALLIB_DEV_ASSERT(TransferCfgPtr != NULL_PTR);
    #endif

    if (SPI_DRV_BUSY == TransferCfgPtr->Status)
    {
        if (TransferCfgPtr->ExpectReadNum != TransferCfgPtr->RxIndex)
        {
            /* Transfer is not finished, continue once last Rx finished */
            Spi_Drv_ContinueDmaRxTransfer(Instance);
            Spi_Drv_ContinueDmaTxTransfer(Instance);
        }
        else
        {
            EndOfTransferFlag = TRUE;
        }

        if (TRUE == EndOfTransferFlag)
        {
            /* Disable DMA requests. */
            BaseW->SPI_DMACR = SPI_DRV_REG_DMACR_TDMAE(0) | SPI_DRV_REG_DMACR_RDMAE(0);
            TransferCfgPtr->Status = SPI_DRV_IDLE;
            if (TransferCfgPtr->Callback != NULL_PTR)
            {
                TransferCfgPtr->Callback(Instance, SPI_DRV_EVENT_SUCCESS);
            }
        }
    }
    else
    {
        /* Nothing to do */
    }

    #if (STD_ON == SPI_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
    #endif
}
#endif /* STD_ON == SPI_DRV_DMA_USED */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Drv */

/** @} end of group Spi_Module */
