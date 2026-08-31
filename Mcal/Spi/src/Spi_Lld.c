/**
* @file    Spi_Lld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Spi_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
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
 * PRQA S 3678 Rule 8.13: A pointer should point to a const-qualified type whenever possible.
 * PRQA S 3673 Rule 8.13: A pointer should point to a const-qualified type whenever possible.
 * PRQA S 0326 Rule 11.6: A cast shall not b e performed between pointer to void and an arithmetic type.
 * PRQA S 3006 Dir 4.3:   Assembly language shall be encapsulated and isolated.
 * PRQA S 4543 Rule 10.1: Operands shall not be of an inappropriate essential type.
 * PRQA S 0306 Rule 11.4: A conversion should not be performed between a pointer to object and an integer type.
 * PRQA S 0489 Rule 18.4: The +, -, += and -= operators sho uld not be applied to an expression of pointer type.
 * PRQA S 0488 Rule 18.4: The +, -, += and -= operators sho uld not be applied to an expression of pointer type
 * PRQA S 0310 Rule 11.3: A cast shall not be performed between a pointer to object type and a pointer to a diff erect object type.
 * PRQA S 3305 Rule 11.3: A cast shall not be performed between a pointer to object type and a pointer to a diff erect object type.
 * PRQA S 2985 Rule 2.2:  The operation here is redundant as the result's Value is always that of the left-hand operand.
 */

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"
#include "Spi.h"
#include "Spi_Lld_Reg.h"
#include "Spi_Lld.h"
#include "SchM_Spi.h"
#include "OsIf.h"

#if (SPI_DMA_USED == STD_ON)
#include "CddDma.h"
#include "CddDma_Cfg.h"
#endif

#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_LLD_VENDOR_ID_C                      (180)
#define SPI_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define SPI_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define SPI_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define SPI_LLD_SW_MAJOR_VERSION_C               (2)
#define SPI_LLD_SW_MINOR_VERSION_C               (3)
#define SPI_LLD_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SPI_LLD header file are of the same vendor */
#if (SPI_LLD_VENDOR_ID_C != SPI_LLD_VENDOR_ID)
#error "Spi_Lld.c and Spi_Lld.h have different vendor ids"
#endif

/* Check if source file and SPI_LLD header file are of the same Autosar version */
#if ((SPI_LLD_AR_RELEASE_MAJOR_VERSION_C != SPI_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_LLD_AR_RELEASE_MINOR_VERSION_C != SPI_LLD_AR_RELEASE_MINOR_VERSION) || \
     (SPI_LLD_AR_RELEASE_REVISION_VERSION_C != SPI_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Lld.c and Spi_Lld.h are different"
#endif

/* Check if source file and SPI_LLD header file are of the same Software version */
#if ((SPI_LLD_SW_MAJOR_VERSION_C != SPI_LLD_SW_MAJOR_VERSION) || \
     (SPI_LLD_SW_MINOR_VERSION_C != SPI_LLD_SW_MINOR_VERSION) || \
     (SPI_LLD_SW_PATCH_VERSION_C != SPI_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Lld.c and Spi_Lld.h are different"
#endif

/* Check if source file and SPI_Lld_Reg header file are of the same vendor */
#if (SPI_LLD_VENDOR_ID_C != SPI_LLD_REG_VENDOR_ID)
#error "Spi_Lld.c and Spi_Lld_Reg.h have different vendor ids"
#endif

/* Check if source file and SPI_Lld_Reg header file are of the same Autosar version */
#if ((SPI_LLD_AR_RELEASE_MAJOR_VERSION_C != SPI_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_LLD_AR_RELEASE_MINOR_VERSION_C != SPI_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
     (SPI_LLD_AR_RELEASE_REVISION_VERSION_C != SPI_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Lld.c and Spi_Lld_Reg.h are different"
#endif

/* Check if source file and SPI_Lld_Reg header file are of the same Software version */
#if ((SPI_LLD_SW_MAJOR_VERSION_C != SPI_LLD_REG_SW_MAJOR_VERSION) || \
     (SPI_LLD_SW_MINOR_VERSION_C != SPI_LLD_REG_SW_MINOR_VERSION) || \
     (SPI_LLD_SW_PATCH_VERSION_C != SPI_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Lld.c and Spi_Lld_Reg.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/* Pointer to runtime state structure.*/
SPI_VAR static Spi_StateType *Spi_StatePtrs[SPI_MAX_HW_UNIT_USED] = {0};
SPI_VAR static Spi_StateType Spi_States[SPI_MAX_HW_UNIT_USED] = {0};

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_16
#include "Spi_MemMap.h"

/* Used to indicates external device that current transmiting.*/
SPI_VAR static volatile Spi_HWUnitType TransmitHwUnit[SPI_INSTANCE_COUNT] = SPI_HWUNIT_INIT;

#define SPI_STOP_SEC_VAR_INIT_16
#include "Spi_MemMap.h"

#if (SPI_DMA_USED == STD_ON)
extern const CddDma_TransferConfigType *DmaChannelTransferConfigArray[CDDDMA_TRANSFER_CONFIG_COUNT];
#endif
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_32
#include "Spi_MemMap.h"

/* Defines constant Value arrays for the baud rate pre-scalar values.*/
SPI_CONST static const uint32 BaudratePrescaler[SPI_FUNCTION_CLK_DIV_COUNT] = { 1, 2, 4, 8, 16, 32, 64, 128 };

#define SPI_STOP_SEC_CONST_32
#include "Spi_MemMap.h"

/*==================================================================================================
 *                            SPI_DMA_USED          LOCAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/* MR12 RULE 8.13 VIOLATION: A pointer should point to a const-qualified type whenever possible.
 * In this specific case, needs using this Value for tessy unit test, thus, couldn't adhere to M3CM Rule-8.13
 */
SPI_VAR static volatile SPI_Type *Spi_BasePtrs[SPI_INSTANCE_COUNT] =  SPI_BASE_PTRS; /*PRQA S 3678*/
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#if (SPI_DMA_USED == STD_ON)
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

SPI_VAR static CddDma_TransferConfigType DmaTxTransferConfig;
SPI_VAR static CddDma_TransferConfigType DmaRxTransferConfig;

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

SPI_FUNC static Std_ReturnType Spi_Lld_AbortTransfer(uint8 Instance);
SPI_FUNC static void Spi_Lld_ReadRXBuffer(uint8 Instance);
SPI_FUNC static void Spi_Lld_FillupTxBuffer(uint8 Instance);
SPI_FUNC static void Spi_JobTransferFinished(const Spi_JobConfigType *JobConfigPtr);

/* previous declaration.*/
#ifdef SPI0
SPI_FUNC ISR(SPI0_IRQHandler);
#endif
#ifdef SPI1
SPI_FUNC ISR(SPI1_IRQHandler);
#endif
#ifdef SPI2
SPI_FUNC ISR(SPI2_IRQHandler);
#endif
#ifdef SPI3
SPI_FUNC ISR(SPI3_IRQHandler);
#endif
#ifdef SPI4
SPI_FUNC ISR(SPI4_IRQHandler);
#endif
#ifdef SPI5
SPI_FUNC ISR(SPI5_IRQHandler);
#endif
#ifdef SPI6
SPI_FUNC ISR(SPI6_IRQHandler);
#endif
#ifdef SPI7
SPI_FUNC ISR(SPI7_IRQHandler);
#endif
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/


/*!
 * @brief   Reads TX COUNT form the FIFO Status Register.
 * @details This function reads the TX COUNT field  from the FIFO Status Register (FSR).
 *
 * @param[in] Base The Module Base pointer of type SPI_Type.
 *
 * @return The data read from the FIFO Status Register
 */
SPI_FUNC LOCAL_INLINE uint32 Spi_Lld_ReadTxCount(volatile const SPI_Type *Base)
{
    return ((Base->TXFIFO & SPI_TXFIFO_COUNT_MASK) >> SPI_TXFIFO_COUNT_SHIFT);
}

/*!
 * @brief   Reads RX COUNT form the FIFO Status Register.
 * @details This function reads the RX COUNT field from the FIFO Status Register (FSR).
 *
 * @param[in] Base Module Base pointer of type SPI_Type.
 *
 * @return The data readed from the FIFO Status Register
 */
SPI_FUNC LOCAL_INLINE uint32 Spi_Lld_ReadRxCount(volatile const SPI_Type *Base)
{
    return ((Base->RXFIFO & SPI_RXFIFO_COUNT_MASK) >> SPI_RXFIFO_COUNT_SHIFT);
}

/*!
 * @brief   Gets the SPI status flag state.
 * @details This function returns the state of one of the SPI status flags as requested by the user.
 *
 * @param[in] Base       Module Base pointer of type SPI_Type.
 * @param[in] StatusFlag The status flag, of type spi_status_flag_t
 *
 * @return State of the status flag: asserted (true) or not-asserted (false)
 */
SPI_FUNC LOCAL_INLINE boolean Spi_Lld_GetStatusFlag(volatile const SPI_Type *Base, Spi_StatusFlagType StatusFlag)
{
    return (boolean)(((Base->STS) >> (uint8)StatusFlag) & 1U);
}

/*!
 * @brief   Configures the SPI interrupts.
 * @details This function is configure the SPI module's source of the interrupt
 *
 * @param[in] Base         Module Base pointer of type SPI_Type.
 * @param[in] InterruptSrc The interrupt source, of type Spi_StatusFlagType
 * @param[in] Enable       Enable (true) or disable (false) the interrupt source
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_SetIntMode(volatile SPI_Type *Base,
        Spi_StatusFlagType InterruptSrc, boolean Enable)
{
    if (TRUE == Enable)
    {
        Base->INTE |= (uint32)1U << (uint8)InterruptSrc;
    }
    else
    {
        Base->INTE &= ~((uint32)1U << (uint8)InterruptSrc);
    }
}

/*!
 * @brief   Gets the SPI interrupt status.
 * @details This function returns the state of one of the SPI interrupt enable status
 *
 * @param[in] Base Module Base pointer of type SPI_Type.
 *
 * @return State of the interrupt enable status
 * @retval TRUE  At last of one Interrupt is enabled
 * @retval FALSE All Interrupts are disabled
 */
SPI_FUNC LOCAL_INLINE boolean Spi_Lld_GetAllIntStatus(volatile const SPI_Type *Base)
{
    boolean RetVal = FALSE;
    uint32 Status = Base->INTE;
    if ((Status & (uint32)SPI_ALL_INTERRUPT) != 0U)
    {
        RetVal = TRUE;
    }
    return RetVal;
}

#if (SPI_DMA_USED == STD_ON)
/*!
 * @brief   Sets the SPI Receive Data DMA configuration (Enable or disable).
 * @details This function is to set the SPI RX DMA configuration
 *
 * @param[in] Base   Module Base pointer of type SPI_Type.
 * @param[in] Enable Enable (true) or disable (false) the RX DMA request
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_SetRxDmaCmd(volatile SPI_Type *Base, boolean Enable)
{
    (Base->CTRL) = (Base->CTRL & (~SPI_CTRL_RXDMAEN_MASK)) | ((uint32) Enable << SPI_CTRL_RXDMAEN_SHIFT);
}

/*!
 * @brief   Sets the SPI Transmit Data DMA configuration (Enable or disable).
 * @details This function is to set the SPI TX DMA configuration
 *
 * @param[in] Base   Module Base pointer of type SPI_Type.
 * @param[in] Enable Enable (true) or disable (false) the TX DMA request
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_SetTxDmaCmd(volatile SPI_Type *Base, boolean Enable)
{
    Base->CTRL = (Base->CTRL & (~SPI_CTRL_TXDMAEN_MASK)) | ((uint32) Enable << SPI_CTRL_TXDMAEN_SHIFT);
}
#endif /* (SPI_DMA_USED == STD_ON) */

/*!
 * @brief   This function clears the state of one of the SPI status flags as requested
 * @details This function clears the state of one of the SPI status flags as requested by the user.
 *
 * @param[in] Base       Module Base pointer of type SPI_Type.
 * @param[in] StatusFlag Status flags of STS register which need to be cleared
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_ClearStatusFlag(volatile SPI_Type *Base, Spi_StatusFlagType StatusFlag)
{
    if (StatusFlag == SPI_ALL_STATUS)
    {
        Base->STS |= (uint32)SPI_ALL_STATUS;
    }
    else
    {
        Base->STS |= ((uint32)1U << (uint32)StatusFlag);
    }
}
/*!
 * @brief   Sets the RX FIFO watermark values.
 * @details function is to set the RX FIFO watermarks.
 *
 * @param[in] Base    Module Base pointer of type SPI_Type.
 * @param[in] RxWater The RX FIFO watermark Value
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_SetRxWatermarks(volatile  SPI_Type *Base, uint32 RxWater)
{
    uint32 SpiTmp = Base->RXFIFO;
    SpiTmp &= ~SPI_RXFIFO_WATER_MASK;
    SpiTmp |= ((RxWater & SPI_RXFIFO_WATER_MASK) << SPI_RXFIFO_WATER_SHIFT); /*PRQA S 2985*/
    Base->RXFIFO = SpiTmp;
}

/*!
 * @brief   Sets the TX FIFO watermark values.
 * @details This function is to set the TX FIFO watermarks.
 *
 * @param[in] Base    Module Base pointer of type SPI_Type.
 * @param[in] TxWater The TX FIFO watermark Value
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_SetTxWatermarks(volatile SPI_Type *Base, uint32 TxWater)
{
    uint32 SpiTmp = Base->TXFIFO;
    SpiTmp &= ~SPI_TXFIFO_WATER_MASK;
    SpiTmp |= ((TxWater & SPI_TXFIFO_WATER_MASK) << SPI_TXFIFO_WATER_SHIFT); /*PRQA S 2985*/
    Base->TXFIFO = SpiTmp;
}

/*!
 * @brief   Flushes the SPI FIFOs.
 * @details This function is to reset the address pointer of the TX/RX FIFO
 *
 * @param[in] Base        Module Base pointer of type SPI_Type.
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_SetFlushFifoCmd(volatile SPI_Type *Base)
{
    Base->TXFIFO |= (uint32)1U << SPI_TXFIFO_RESET_SHIFT;
    Base->RXFIFO |= (uint32)1U << SPI_TXFIFO_RESET_SHIFT;
}

/*!
 * @brief   Clear CONT bit form continues mode.
 * @details This function clears the CONT bit from the continues mode.
 *
 * @param[in] Base Module base pointer of type SPI_Type.
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void SPI_Lld_ClearContBit(volatile SPI_Type *Base)
{
    (Base->TXCFG) = ((Base->TXCFG) & (~SPI_TXCFG_CONT_MASK));
}

/*!
 * @brief   Clear CONTC bit form TCR Register.
 * @details This function clears the CONTC bit from the Transmit Command Register (TCR).
 *
 * @param[in] Base Module Base pointer of type SPI_Type.
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_ClearContCBit(volatile SPI_Type *Base)
{
    Base->TXCFG = ((Base->TXCFG) & (~SPI_TXCFG_CONTC_MASK));
}

/*!
 * @brief   Set CONTC bit form TCR Register.
 * @details This function sets the CONTC bit from the Transmit Command Register (TCR).
 *
 * @param[in] Base Module Base pointer of type SPI_Type.
 *
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_SetContCBit(volatile SPI_Type *Base)
{
    Base->TXCFG = ((Base->TXCFG) | SPI_TXCFG_CONTC_MASK);
}

/**
 * @brief   Sets the SPI receive data mask.
 *
 * @param[in] Base Module Base pointer of type SPI_Type.
 * @param[in] Enable Enable (true) or disable (false) the Rx mask request
 * @return void
 */
SPI_FUNC LOCAL_INLINE void Spi_Lld_RxMaskSet(volatile SPI_Type *Base, boolean Enable)
{
    (Base->TXCFG) = (Base->TXCFG & (~SPI_TXCFG_MSKRX_MASK)) | ((uint32) Enable << SPI_TXCFG_MSKRX_SHIFT);
}

/**
 * @brief   Get the SPI Instance's TXCFG register configuration status.
 * @details The value configured to the TXCFG register can only be read after the APB bus is synchronized. Otherwise, other registers of the SPI
 *          need to be read before reading TXCFG to ensure write command synchronization. Otherwise, TXCFG cannot read the correct value.
 *
 *          The reason is that when the function clock is lower than the bus clock, writing will be slower than reading time, and the TXCFG register
 *          of the current IP needs to operate other registers to achieve synchronization with the APB bus, otherwise the value written to TXCFG will
 *          never be read correctly.
 *
 * @param[in] Base Module Base pointer of type SPI_Type.
 * @param[in] DesiredData The desired data to be compared with the TXCFG register.
 * @return void
 */
SPI_FUNC LOCAL_INLINE boolean Spi_Lld_GetTXCFGConfigStatus(volatile const SPI_Type *Base, uint32 DesiredData)
{
    uint32 RegCfgData = 0U;
    boolean RetVal = FALSE;
    RegCfgData = Base->MATCH0;
    (void)RegCfgData;
    RegCfgData = Base->TXCFG;
    if (RegCfgData == DesiredData)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
 * @brief            Service for SPI de-initialization.
 * @details          This function de-initializes the SPI micro controller module
 *
 * @param[in] Instance The Instance of the SPI module
 * @return             Std_ReturnType
 * @retval E_OK        de-initialisation command has been accepted
 * @retval E_NOT_OK    de-initialisation command has not been accepted
 */
SPI_FUNC Std_ReturnType Spi_Lld_DeInit(uint8 Instance)
{
    Std_ReturnType RtnTemp = E_OK;
    {
        /*Asserted a software reset*/
        SPI_REST_VIA_IPC->CTRL[Instance] |= (uint32)IPC_CTRL_SWRESET_MASK;
        /*De-assert the software reset*/
        SPI_REST_VIA_IPC->CTRL[Instance] &= (uint32)(~IPC_CTRL_SWRESET_MASK);
        Spi_StatePtrs[Instance] = NULL_PTR;
    }
    return RtnTemp;
}

/**
* @brief   This function is called to release the jobs at the end of an async sequence transmission.
* @details Mark the linked sequence for all jobs as NULL_PTR.
*
* @param[in] RemainingJobs The starting job
* @param[in] SequencePtr   The pointer of sequence configuration
*
* @pre  Pre-compile Parameter SPI_CANCEL_API shall be STD_ON.
*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_CANCEL_API == STD_ON)
SPI_FUNC LOCAL_INLINE void Spi_UnlockRemainingJobs(Spi_JobType RemainingJobs, const Spi_SequenceConfigType *SequencePtr)
{
    Spi_JobType NumJobsInSeq = SequencePtr->NumJobs;
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06();
    for (Spi_JobType JobIdx = NumJobsInSeq - RemainingJobs; JobIdx < NumJobsInSeq; ++JobIdx)
    {
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        Spi_JobState[SequencePtr->JobIndexListPtr[JobIdx]].AsyncCrtSequenceStatePtr = NULL_PTR;
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06();
}
#endif /* (SPI_CANCEL_API == STD_ON) */
#endif /* (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) */

/**
* @brief  This function is calculate absolute difference between two numbers.
*
* @param[in] A  Number A
* @param[in] B  Number B
*
* @return absolute Value between two numbers
*/
SPI_FUNC LOCAL_INLINE uint32 Spi_Lld_GetAbsoluteDiffValue(uint32 A, uint32 B)
{
    uint32 AbsValue = 0;
    if (A > B)
    {
        AbsValue = A - B;
    }
    else
    {
        AbsValue = B - A;
    }
    return AbsValue;
}

/**
* @brief   Sets the SPI baud rate in bits per second.
* @details This function takes in the desired bitsPerSec (baud rate) and calculates the nearest
*          possible baud rate, and returns the calculated baud rate in bits-per-second.
*
* @param[in]    BitsPerSec      The desired baud rate
* @param[in]    SourceClockInHz The frequency in Hz of the SPI module source clock
* @param[inout] DivPtr          The best Scaler Value for user to use later
* @param[inout] PrescalePtr     The best Prescaler Value for user to use later
*
* @return The actual calculated baud rate
*/
SPI_FUNC static uint32 Spi_Lld_GetPreScalerAndDiv(uint32 BitsPerSec, uint32 SourceClockInHz,
        uint32 *DivPtr, uint32 *PrescalePtr)
{
    uint32 BestFreq = 0xFFFFFFFFU;
    uint32 BestScaler = 0U;
    uint32 BestPrescaler = 0U;
    uint32 Freq1 = 0U;
    uint32 Freq2 = 0U;
    uint8  Scaler = 0U;
    uint32 Low = 0U;
    uint32 High = 0U;
    uint32 TempBestFreq = 0U;
    uint32 TempBestScaler = 0U;
    for (uint8 Prescaler = 0; Prescaler < (uint8)SPI_FUNCTION_CLK_DIV_COUNT; ++Prescaler)
    {
        Low = 0U;
        High = SPI_MAX_SCALER_VALUE;
        /* Implement golden section search algorithm */
        do
        {
            Scaler = (uint8)((Low + High) / 2U);
            Freq1 = SourceClockInHz / (BaudratePrescaler[Prescaler] * (Scaler + (uint32)SPI_SCALER_OFFSET));
            if (Spi_Lld_GetAbsoluteDiffValue(BitsPerSec, BestFreq) > Spi_Lld_GetAbsoluteDiffValue(BitsPerSec, Freq1))
            {
                BestFreq = Freq1;
            }
            if (Freq1 < BitsPerSec)
            {
                High = Scaler;
            }
            else
            {
                Low = Scaler;
            }
        } while ((High - Low) > 1U);
        /* Evaluate last 2 Scaler values */
        Freq1 = SourceClockInHz / (BaudratePrescaler[Prescaler] * (Low + (uint32)SPI_SCALER_OFFSET));
        Freq2 = SourceClockInHz / (BaudratePrescaler[Prescaler] * (High + (uint32)SPI_SCALER_OFFSET));
        if (Spi_Lld_GetAbsoluteDiffValue(BitsPerSec, Freq1) > Spi_Lld_GetAbsoluteDiffValue(BitsPerSec, Freq2))
        {
            TempBestFreq = Freq2;
            TempBestScaler = High;
        }
        else
        {
            TempBestFreq = Freq1;
            TempBestScaler = Low;
        }
        if (Spi_Lld_GetAbsoluteDiffValue(BitsPerSec, BestFreq) >= Spi_Lld_GetAbsoluteDiffValue(BitsPerSec, TempBestFreq))
        {
            BestFreq = TempBestFreq;
            BestScaler = TempBestScaler;
            BestPrescaler = Prescaler;
        }
        /* If current frequency is equal to target frequency  stop the search */
        if (BestFreq == BitsPerSec)
        {
            break;
        }
    }
    /* return the best Prescaler Value for user to use later */
    *PrescalePtr = BestPrescaler;
    /* return the best Scaler Value for user to use later */
    *DivPtr = BestScaler;
    /* return the actual calculated baud rate */
    return BestFreq;
}

/**
* @brief   This function is configures the SPI peripheral module
*
* @param[in] HWUnit   The index of the SPI peripheral configuration unit(external device unit)
* @param[in] Instance The Instance of the SPI module
*
* @return             Std_ReturnType
* @retval E_OK        The configuration succeeded
*/
SPI_FUNC static Std_ReturnType Spi_Lld_PeripheralConfig(uint8 ExternalDevice, uint8 Instance)
{
    Spi_HWUnitType HWUnit = Spi_ConfigPtr->ExternalDeviceConfigPtr[ExternalDevice].HWUnitId;
    /* Instantiate local variable of type spi_master_state_t and point to global state */
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[HWUnit];
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    const Spi_ExternalDeviceConfigType *SpiHwUnitConfigPtr = &Spi_ConfigPtr->ExternalDeviceConfigPtr[ExternalDevice];
    Std_ReturnType RtnTemp = E_OK;
    uint32 Value = 0U;
    uint32 PreScale = 0;
    uint32 DivScale = 0;
    uint32 PcsPolarity = 0;
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07();
    /* Store data to SpiState*/
    SpiStatePtr->PcsPolarity = SpiHwUnitConfigPtr->PcsPolarity;
    SpiStatePtr->DualEn = SpiHwUnitConfigPtr->DualEn;
    SpiStatePtr->BaudRate = SpiHwUnitConfigPtr->BaudRate;
    SpiStatePtr->ClkPhase = SpiHwUnitConfigPtr->ClkPhase;
    SpiStatePtr->ClkPolarity = SpiHwUnitConfigPtr->ClkPolarity;
    SpiStatePtr->SrcClk = SpiHwUnitConfigPtr->SrcClk;
    SpiStatePtr->TimeClkToCs = SpiHwUnitConfigPtr->TimeClkToCs;
    SpiStatePtr->TimeCsToClk = SpiHwUnitConfigPtr->TimeCsToClk;
    SpiStatePtr->TimeCsToCs = SpiHwUnitConfigPtr->TimeCsToCs;
    SpiStatePtr->WhichPcs = SpiHwUnitConfigPtr->WhichPcs;
    SpiStatePtr->IsSync = SpiHwUnitConfigPtr->IsSync;
    SpiStatePtr->IsPcsContinuous = SpiHwUnitConfigPtr->IsPcsContinuous;
    SpiStatePtr->PinConfig = SpiHwUnitConfigPtr->PinConfig;
    SpiStatePtr->SamplePoint = SpiHwUnitConfigPtr->SamplePoint;
#if (SPI_SLAVE_SUPPORT == STD_ON)
    SpiStatePtr->SlaveMode = SpiHwUnitConfigPtr->SlaveMode;
#endif
#if (SPI_DMA_USED == STD_ON)
    SpiStatePtr->DmaUsed = SpiHwUnitConfigPtr->UseDma;
#endif
    if (TRUE == SpiHwUnitConfigPtr->IsSync)
    {
        SpiStatePtr->TransferUsing = SPI_USING_POLLING;
    }
    else /* Async transfer mode*/
    {
        if (TRUE == SpiStatePtr->TransferUsingInterruptEn)
        {
            SpiStatePtr->TransferUsing = SPI_USING_INTERRUPTS;
        }
        else
        {
            SpiStatePtr->TransferUsing = SPI_USING_POLLING;
        }
#if (SPI_DMA_USED == STD_ON)
        if (TRUE == SpiHwUnitConfigPtr->UseDma)
        {
            SpiStatePtr->RxDMAChannel = SpiHwUnitConfigPtr->RxDmaChannel;
            SpiStatePtr->TxDMAChannel = SpiHwUnitConfigPtr->TxDmaChannel;
            DmaTxTransferConfig = *DmaChannelTransferConfigArray[SpiStatePtr->TxDMAChannel];
            DmaRxTransferConfig = *DmaChannelTransferConfigArray[SpiStatePtr->RxDMAChannel];
        }
#endif
    }
    /* Disable fault interrupts sources */
    Spi_Lld_SetIntMode(Base, SPI_TRANSMIT_ERROR, FALSE);
    Spi_Lld_SetIntMode(Base, SPI_RECEIVE_ERROR, FALSE);
    /* Disable the TDF and RDF interrupt. */
    Spi_Lld_SetIntMode(Base, SPI_TX_DATA_FLAG, FALSE);
    Spi_Lld_SetIntMode(Base, SPI_RX_DATA_FLAG, FALSE);
    /* Get the PC's polarity of the instance*/
    PcsPolarity = (Base->CTRL & SPI_CTRL_CSPOL_MASK) >> SPI_CTRL_CSPOL_SHIFT;
    /* Set SPI ctrl register*/
    Value = SPI_CTRL_CSPOL(PcsPolarity) | SPI_CTRL_CSDEN(SpiStatePtr->DualEn) |
            SPI_CTRL_PINCFG(SpiStatePtr->PinConfig) | SPI_CTRL_SPDEN(SpiStatePtr->SamplePoint);
    /*Enable SPI and set SPI working mode*/
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if (TRUE == SpiStatePtr->SlaveMode)
    {
        Value = (Value & ~(SPI_CTRL_EN_MASK | SPI_CTRL_MODE_MASK)) | SPI_CTRL_EN(1) | SPI_CTRL_MODE(0);
    }
    else
    {
#endif
        Value = (Value & ~(SPI_CTRL_EN_MASK | SPI_CTRL_MODE_MASK)) | SPI_CTRL_EN(1) | SPI_CTRL_MODE(1); /*PRQA S 2985*/
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif
    Base->CTRL = Value;
#if (SPI_SLAVE_SUPPORT == STD_ON)
    /*Slave mode does not need to configure the clock*/
    if (FALSE == SpiStatePtr->SlaveMode)
    {
#endif
        (void)Spi_Lld_GetPreScalerAndDiv(SpiStatePtr->BaudRate, SpiStatePtr->SrcClk, &DivScale, &PreScale);
        /* Save PreScale and DivScale.*/
        SpiStatePtr->PreScale = PreScale;
        SpiStatePtr->DivScale = DivScale;
        /* Set SPI CLK*/
        Value = SPI_CLK_PCSSCK(SpiStatePtr->TimeCsToClk) | SPI_CLK_SCKPCS(SpiStatePtr->TimeClkToCs) | /*PRQA S 2985*/
                SPI_CLK_DIV(DivScale) | SPI_CLK_FMDLY(SpiStatePtr->TimeCsToCs); /*PRQA S 2985*/
        Base->CLK = Value;
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif
    /* Clear SPI STS*/
    Base->STS = 0U;
    /* Set SPI TXFIFO*/
    SpiStatePtr->FifoSize = (uint8)(1U << ((Base->TXFIFO & SPI_TXFIFO_SIZE_MASK) >> SPI_TXFIFO_SIZE_SHIFT));
    /* Clean RX and TX buffers */
    Base->TXFIFO |= (uint32)1 << SPI_TXFIFO_RESET_SHIFT;
    Base->RXFIFO |= (uint32)1 << SPI_TXFIFO_RESET_SHIFT;
    /* The second writing is used to avoid the case when one word is still in shifter. */
    Base->TXFIFO |= (uint32)1 << SPI_TXFIFO_RESET_SHIFT;
    Base->RXFIFO |= (uint32)1 << SPI_TXFIFO_RESET_SHIFT;
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07();
    return RtnTemp;
}

/*!
 * @brief   Disable the TEIE interrupts at the end of a transfer.
 * @details Disable the interrupts and clear the status for transmit/receive errors.
 *
 * @param[in] Instance The index of the SPI module
 *
 * @return void
 */
SPI_FUNC static void Spi_Lld_DisableTEIEInterrupts(uint8 Instance)
{
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    Spi_Lld_SetIntMode(Base, SPI_TRANSMIT_ERROR, FALSE);
    Spi_Lld_SetIntMode(Base, SPI_RECEIVE_ERROR, FALSE);
    Spi_Lld_ClearStatusFlag(Base, SPI_TRANSMIT_ERROR);
    Spi_Lld_ClearStatusFlag(Base, SPI_RECEIVE_ERROR);
}

/*!
 * @brief   Finish up a transfer.
 * @details Cleans up after a transfer is complete. Interrupts are disabled, and the SPI module
 *          is disabled. This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The index of the SPI module
 *
 * @return void
 */
SPI_FUNC static void Spi_Lld_CompleteTransfer(uint8 Instance)
{
    /* instantiate local variable of type dspi_master_state_t and point to global state */
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    volatile SPI_Type *BasePtr = Spi_BasePtrs[Instance];
    /* The transfer is complete.*/
    SpiStatePtr->IsTransferInProgress = FALSE;
#if (SPI_DMA_USED == STD_ON)
    if (TRUE == SpiStatePtr->DmaUsed)
    {
        /* Disable SPI DMA request */
        Spi_Lld_SetRxDmaCmd(BasePtr, FALSE);
        Spi_Lld_SetTxDmaCmd(BasePtr, FALSE);
#if (SPI_SLAVE_SUPPORT == STD_ON)
        if (TRUE == SpiStatePtr->SlaveMode)
        {
            Spi_Lld_SetIntMode(BasePtr, SPI_FRAME_COMPLETE, FALSE);
            Spi_Lld_ClearStatusFlag(BasePtr, SPI_FRAME_COMPLETE);
        }
#endif
    }
    else
#endif /* SPI_DMA_USED == STD_ON*/
    {
        /* Disable (clear) interrupt requests */
        Spi_Lld_SetIntMode(BasePtr, SPI_RX_DATA_FLAG, FALSE);
        Spi_Lld_SetIntMode(BasePtr, SPI_TX_DATA_FLAG, FALSE);
    }
    Spi_Lld_DisableTEIEInterrupts(Instance);
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if (FALSE == SpiStatePtr->SlaveMode)
    {
#endif
        Spi_Lld_SetIntMode(BasePtr, SPI_TRANSFER_COMPLETE, FALSE);
        Spi_Lld_ClearStatusFlag(BasePtr, SPI_TRANSFER_COMPLETE);
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif
}

#if (SPI_DMA_USED == STD_ON)
/*!
 * @brief   If errors are detected during DMA transfer the Error interrupt will be trigger, if DMA error interrupt is enabled.
 * @details main purpose of this function is to check DMA errors on Tx/Rx channel
 *
 * @param[in] Parameter The parameters to be used in the callback function, here used for index of the SPI module
 *
 * @return void
 */
/* MR12 RULE 8.13 VIOLATION: A pointer should point to a const-qualified type whenever possible.
 * In this specific case, to avoid introducing more problems, thus, couldn't adhere to M3CM Rule-8.13
 */
SPI_FUNC static void Spi_Lld_DmaTransferError(void *Parameter) /*PRQA S 3673*/
{
    /* MR12 RULE 11.6 VIOLATION: Cast between a pointer to void and an integral type.
     * In this specific case, needs to convert the Parameter to Instance, thus, couldn't adhere to M3CM Rule-11.6
     */
    uint8 Instance = (uint8)((uint32) Parameter); /*PRQA S 0326*/
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    (void)Spi_Lld_AbortTransfer(Instance);
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08();
    SpiStatePtr->CurrentJobPtr->JobStatePtr->AsyncCrtSequenceStatePtr->Result = SPI_SEQ_FAILED;
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
}

/*!
 * @brief   This function will process RX DMA transfer complete interrupt.
 * @details main purpose of this function is to create a function compatible with DMA callback type
 *
 * @param[in] Parameter The parameters to be used in the callback function, here used for index of the SPI module
 *
 * @return void
 */
/* MR12 RULE 8.13 VIOLATION: A pointer should point to a const-qualified type whenever possible.
 * In this specific case, to avoid introducing more problems, thus, couldn't adhere to M3CM Rule-8.13
 */
SPI_FUNC static void Spi_Lld_CompleteDmaRx(void *Parameter) /*PRQA S 3673*/
{
    /* MR12 RULE 11.6 VIOLATION: Cast between a pointer to void and an integral type.
     * In this specific case, needs to convert the Parameter to Instance, thus, couldn't adhere to M3CM Rule-11.6
     */
    uint8 Instance = (uint8)((uint32) Parameter); /*PRQA S 0326*/
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    SpiStatePtr->RxCount = 0;
    SpiStatePtr->TransferStatus = SPI_TRANSFER_OK;
#if (SPI_SLAVE_SUPPORT == STD_ON)
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    if (TRUE == SpiStatePtr->SlaveMode)
    {
        /*Mask Rx to discard receive data*/
        Spi_Lld_RxMaskSet(Base, TRUE);
        Spi_Lld_SetIntMode(Base, SPI_FRAME_COMPLETE, TRUE);
    }
#else
    (void)Instance;
#endif
}

/*!
 * @brief   This function will process TX DMA transfer complete interrupt.
 * @details main purpose of this function is to create a function compatible with DMA callback type
 *
 * @param[in] Parameter The parameters to be used in the callback function, here used for index of the SPI module
 *
 * @return void
 */
/* MR12 RULE 8.13 VIOLATION: A pointer should point to a const-qualified type whenever possible.
 * In this specific case, to avoid introducing more problems, thus, couldn't adhere to M3CM Rule-8.13
 */
SPI_FUNC static void Spi_Lld_CompleteDmaTx(void *Parameter) /*PRQA S 3673*/
{
    /* MR12 RULE 11.6 VIOLATION: Cast between a pointer to void and an integral type.
     * In this specific case, needs to convert the Parameter to Instance, thus, couldn't adhere to M3CM Rule-11.6
     */
    uint8 Instance = (uint8)((uint32) Parameter); /*PRQA S 0326*/
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if (FALSE == SpiStatePtr->SlaveMode)
    {
#endif
        if (TRUE == SpiStatePtr->IsPcsContinuous)
        {
            Spi_Lld_ClearContCBit(Base);
        }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif
    SpiStatePtr->TxCount = 0;
    SpiStatePtr->TransferStatus = SPI_TRANSFER_OK;
    /* Enable transfer complete flag interrupt to catch the end of the transfer. */
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if (FALSE == SpiStatePtr->SlaveMode)
    {
#endif
        Spi_Lld_SetIntMode(Base, SPI_TRANSFER_COMPLETE, TRUE);
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif
}
#endif

/*!
 * @brief   This function configures the parameters of SPI transfer and receive
 *
 * @param[in] Instance  The index of the SPI module
 * @param[in] ChannelId Channel Id
 *
 * @return              Std_ReturnType
 * @retval E_OK         The configuration succeeded
 */
/* MR12 DIR 4.3 VIOLATION: The function 'Spi_Lld_ChannelConfig' contains a mixture of in-line assembler statements and C statements.
 * In this specific case, due to the need for Low-level hardware access or specific performance requirements,
 * we had to use inline assembly code alongside C statements, thus, couldn't adhere to this rule.
 */
SPI_FUNC static Std_ReturnType Spi_Lld_ChannelConfig(uint8 Instance, Spi_ChannelType ChannelId) /* PRQA S 3006 */
{
    volatile SPI_Type *BasePtr = Spi_BasePtrs[Instance];
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    const Spi_ChannelConfigType *ChannelConfigPtr = &Spi_ConfigPtr->ChannelConfigPtr[ChannelId];
    Std_ReturnType RtnTemp = E_OK;
    uint32 TxCfgValue = 0;
    uint32 TimeOut = 500;
    uint8 TxCfgSyncMaxTime = 100;
#if (SPI_DMA_USED == STD_ON)
    CddDma_TransferSizeType DmaTransferSize;
#endif
    /* Set inner config for channel config*/
    SpiStatePtr->DefaultValue = ChannelConfigPtr->DefaultValue;
    SpiStatePtr->LsbFirst = (((uint8)LSB_FIRST == ChannelConfigPtr->MsbOrLsbFirst) ? TRUE : FALSE);
    if (1U == (Spi_ChannelState[ChannelId].Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
    {
        SpiStatePtr->TxBuffPtr = (const Spi_DataBufferType *)&ChannelConfigPtr->DefaultValue;
        SpiStatePtr->TxCount = sizeof(uint32);
    }
    else
    {
        SpiStatePtr->TxBuffPtr = ChannelConfigPtr->BufferDescriptorPtr->BufferTXPtr;
        SpiStatePtr->TxCount = Spi_ChannelState[ChannelId].Length;
    }
    SpiStatePtr->RxBuffPtr = ChannelConfigPtr->BufferDescriptorPtr->BufferRXPtr;
    SpiStatePtr->RxCount = SpiStatePtr->TxCount;
    SpiStatePtr->BitsPerFrame = ChannelConfigPtr->DataWidth;
    /*For continuous mode an extra word must be written to negate the PCS */
    if (TRUE == SpiStatePtr->IsPcsContinuous)
    {
        SpiStatePtr->TxCount += 1U;
    }
    /* Calculate the bytes/frame for spiState->bytesPerFrame. */
    SpiStatePtr->BytesPerFrame = (uint16)((SpiStatePtr->BitsPerFrame + 7U) / 8U);
    /* Due to DMA limitations frames of 3 bytes/frame will be internally handled as 4 bytes/frame. */
    if (3U == SpiStatePtr->BytesPerFrame)
    {
        SpiStatePtr->BytesPerFrame = 4U;
    }
    else
    {
        /* The code doesn't run here, because the max size of BitsPerFrame is 32*/
    }
    /* Wait until the SPI is idle */
    do
    {
        --TimeOut;     /*Waiting for ~5us*/
        /*GCOVR_EXCL_START */
        if (0U == TimeOut)
        {
            /*The code cannot running here when spi instance is normally*/
            RtnTemp = E_NOT_OK;
            break;
        }
        /*GCOVR_EXCL_STOP */
    } while (SPI_STS_BUSY_MASK == (BasePtr->STS & SPI_STS_BUSY_MASK));
    /* Set channel config*/
    TxCfgValue = SPI_TXCFG_CPOL(SpiStatePtr->ClkPolarity) | SPI_TXCFG_CPHA(SpiStatePtr->ClkPhase) | /*PRQA S 2985*/
                 SPI_TXCFG_PCS(SpiStatePtr->WhichPcs) | SPI_TXCFG_WIDTH(0) | /*PRQA S 2985*/
                 SPI_TXCFG_PRESCALE(SpiStatePtr->PreScale) | SPI_TXCFG_LSBF(SpiStatePtr->LsbFirst) |
                 SPI_TXCFG_FRAMESZ(SpiStatePtr->BitsPerFrame - (uint32)1U) | SPI_TXCFG_CONT(SpiStatePtr->IsPcsContinuous); /*PRQA S 2985*/
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if (TRUE == SpiStatePtr->SlaveMode)
    {
        /*In slave mode CONT bit should be cleared*/
        TxCfgValue &= ~SPI_TXCFG_CONT_MASK;
    }
#endif
    BasePtr->TXCFG = TxCfgValue;
    /* The value configured to the TXCFG register can only be read after the APB bus is synchronized. Otherwise, other registers of the SPI
     * need to be read before reading TXCFG to ensure write command synchronization. Otherwise, TXCFG cannot read the correct value.
     *
     * The reason is that when the function clock is lower than the bus clock, writing will be slower than reading time, and the TXCFG register of
     * the current IP needs to operate other registers to achieve synchronization with the APB bus, otherwise the value written to TXCFG will never
     * be read correctly.
     */
    do
    {
        --TxCfgSyncMaxTime;
        if (0U == TxCfgSyncMaxTime)
        {
            RtnTemp = E_NOT_OK;
            break;
        }
    } while (FALSE == Spi_Lld_GetTXCFGConfigStatus(BasePtr, TxCfgValue));
    if (TRUE == SpiStatePtr->IsPcsContinuous)
    {
        Spi_Lld_SetContCBit(BasePtr);
    }
    /* Clear all interrupts sources */
    Spi_Lld_ClearStatusFlag(BasePtr, SPI_ALL_STATUS);
    /* Configure Rx watermarks */
    Spi_Lld_SetRxWatermarks(BasePtr, 0U);
    /* Configure Tx watermarks */
    Spi_Lld_SetTxWatermarks(BasePtr, 2U);
    /* Async transfer mode*/
    if (FALSE == SpiStatePtr->IsSync)
    {
#if (SPI_DMA_USED == STD_ON)
        if (TRUE == SpiStatePtr->DmaUsed)
        {
#if (SPI_SLAVE_SUPPORT == STD_ON)
            if (TRUE == SpiStatePtr->SlaveMode)
            {
                Spi_Lld_SetTxWatermarks(BasePtr, 0U);
            }
#endif
            /* Enable SPI dma request*/
            Spi_Lld_SetRxDmaCmd(BasePtr, TRUE);
            Spi_Lld_SetTxDmaCmd(BasePtr, TRUE);
            /*DMA transfer configuration for block size, TransferSize and trigger count*/
            switch (SpiStatePtr->BytesPerFrame)
            {
                case 1:
                    DmaTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
                    break;
                case 2:
                    DmaTransferSize = DMA_TRANSFER_SIZE_2_BYTE;
                    break;
                case 4:
                    DmaTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
                    break;
                default:
                    DmaTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
                    break;
            }
            /* DMA TX channel configure*/
            if (SPI_USING_POLLING == SpiStatePtr->TransferUsing)
            {
                DmaTxTransferConfig.ChannelPollingMode = TRUE;
                Spi_Lld_SetIntMode(BasePtr, SPI_TRANSMIT_ERROR, FALSE);
            }
            else
            {
                DmaTxTransferConfig.ChannelPollingMode = FALSE;
                Spi_Lld_SetIntMode(BasePtr, SPI_TRANSMIT_ERROR, TRUE);
            }
            DmaTxTransferConfig.SrcTransferSize = DmaTransferSize;
            DmaTxTransferConfig.DestTransferSize = DmaTransferSize;
            /* MR12 RULE 10.1 VIOLATION: Operands shall not be of an inappropriate essential type.
             * The type of srcOffset is signed short, thus, couldn't adhere to M3CM Rule-10.1
             */
            DmaTxTransferConfig.SrcOffset = (sint16)(1 << (uint16)DmaTransferSize); /*PRQA S 4390, 4543*/
            DmaTxTransferConfig.DestOffset = 0;
            DmaTxTransferConfig.TransferLoopByteCount = (uint32) 1 << (uint32)DmaTransferSize;
            if (1U == (Spi_ChannelState[ChannelId].Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
            {
                DmaTxTransferConfig.TriggerCount = sizeof(uint32);
            }
            else
            {
                DmaTxTransferConfig.TriggerCount = (uint32)Spi_ChannelState[ChannelId].Length / ((uint32) 1U << (uint32)DmaTransferSize);
            }
            /*Check if the byte count is valid*/
            if (0U == DmaTxTransferConfig.TriggerCount)
            {
                RtnTemp = E_NOT_OK;
            }
            else
            {
                /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type.
                 * In this specific case, needs to obtain the integer Value of the Base address, thus, couldn't adhere to M3CM Rule-11.4
                 */
                (void)CddDma_SetLogicChannelTransfer(SpiStatePtr->TxDMAChannel, (uint32) SpiStatePtr->TxBuffPtr, /*PRQA S 0306*/\
                                                     (uint32)&BasePtr->DATA, &DmaTxTransferConfig); /*PRQA S 0306*/
                /* MR12 RULE 11.6 VIOLATION: Cast between a pointer to void and an integral type. In this specific case,
                 * needs to convert the Instance into a pointer type, thus, couldn't adhere to M3CM Rule-11.6
                 */
                CddDma_InstallCallback(SpiStatePtr->TxDMAChannel, Spi_Lld_CompleteDmaTx, (void *)((uint32)Instance)); /*PRQA S 0326*/
                CddDma_InstallErrorCallback(SpiStatePtr->TxDMAChannel, Spi_Lld_DmaTransferError, (void *)((uint32)Instance)); /*PRQA S 0326*/
                if (NULL_PTR != SpiStatePtr->RxBuffPtr)
                {
                    /* DMA RX channel configure*/
                    if (SPI_USING_POLLING == SpiStatePtr->TransferUsing)
                    {
                        DmaRxTransferConfig.ChannelPollingMode = TRUE;
                        Spi_Lld_SetIntMode(BasePtr, SPI_RECEIVE_ERROR, FALSE);
                    }
                    else
                    {
                        DmaRxTransferConfig.ChannelPollingMode = FALSE;
                        Spi_Lld_SetIntMode(BasePtr, SPI_RECEIVE_ERROR, TRUE);
                    }
                    DmaRxTransferConfig.SrcTransferSize = DmaTransferSize;
                    DmaRxTransferConfig.DestTransferSize = DmaTransferSize;
                    DmaRxTransferConfig.SrcOffset = 0;
                    /* MR12 RULE 10.1 VIOLATION: Operands shall not be of an inappropriate essential type.
                     * The type of srcOffset is signed short, thus, couldn't adhere to M3CM Rule-10.1
                     */
                    DmaRxTransferConfig.DestOffset = (sint16)(1 << (uint16)DmaTransferSize); /*PRQA S 4390, 4543*/
                    DmaRxTransferConfig.TransferLoopByteCount = (uint32) 1 << (uint32)DmaTransferSize;
                    DmaRxTransferConfig.TriggerCount = SpiStatePtr->RxCount / ((uint32)1U << (uint16)DmaTransferSize);
                    /*Check if the byte count is valid*/
                    if (0U == DmaRxTransferConfig.TriggerCount)
                    {
                        RtnTemp = E_NOT_OK;
                    }
                    else
                    {
                        /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type.
                         * In this specific case, needs to obtain the integer Value of the Base address, thus, couldn't adhere to M3CM Rule-11.4
                         */
                        (void)CddDma_SetLogicChannelTransfer(SpiStatePtr->RxDMAChannel, (uint32) & (BasePtr->DATA), /*PRQA S 0306*/\
                                                             (uint32)SpiStatePtr->RxBuffPtr, &DmaRxTransferConfig); /*PRQA S 0306*/
                        /* MR12 RULE 11.6 VIOLATION: Cast between a pointer to void and an integral type.
                         * In this specific case, needs to convert the Instance into a pointer type, thus, couldn't adhere to M3CM Rule-11.6
                         */
                        CddDma_InstallCallback(SpiStatePtr->RxDMAChannel, Spi_Lld_CompleteDmaRx, (void *)((uint32)Instance)); /*PRQA S 0326*/
                        CddDma_InstallErrorCallback(SpiStatePtr->RxDMAChannel, Spi_Lld_DmaTransferError, (void *)((uint32)Instance)); /*PRQA S 0326*/
                        CddDma_StartChannel(SpiStatePtr->RxDMAChannel);
                    }
                }
                else
                {
                    SpiStatePtr->RxCount = 0;
                    Spi_Lld_SetRxDmaCmd(BasePtr, FALSE);
                    Spi_Lld_RxMaskSet(BasePtr, TRUE);
                }
                CddDma_StartChannel(SpiStatePtr->TxDMAChannel);
            }
        }
        else
        {
            if (SPI_USING_INTERRUPTS == SpiStatePtr->TransferUsing)
            {
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_14();
                /* Enable fault interrupts sources */
                Spi_Lld_SetIntMode(BasePtr, SPI_TRANSMIT_ERROR, TRUE);
                if (SpiStatePtr->RxBuffPtr != NULL_PTR)
                {
                    Spi_Lld_SetIntMode(BasePtr, SPI_RECEIVE_ERROR, TRUE);
                }
#if (SPI_SLAVE_SUPPORT == STD_ON)
                if (TRUE == SpiStatePtr->SlaveMode)
                {
                    Spi_Lld_SetTxWatermarks(BasePtr, 0U);
                }
#endif
                /* Enable RDF interrupt if RX buffer is not NULL. */
                if (SpiStatePtr->RxBuffPtr != NULL_PTR)
                {
                    Spi_Lld_SetIntMode(BasePtr, SPI_RX_DATA_FLAG, TRUE);
                }
                else
                {
                    SpiStatePtr->RxCount = 0;
                    Spi_Lld_SetRxDmaCmd(BasePtr, FALSE);
                    Spi_Lld_RxMaskSet(BasePtr, TRUE);
                }
                /* Enable the TDF and RDF interrupt. */
                Spi_Lld_SetIntMode(BasePtr, SPI_TX_DATA_FLAG, TRUE);
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_14();
            }
        }
#else    /* SPI_DMA_USED == STD_OFF*/
        if (SPI_USING_INTERRUPTS == SpiStatePtr->TransferUsing)
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_14();
            /* Enable fault interrupts sources */
            Spi_Lld_SetIntMode(BasePtr, SPI_TRANSMIT_ERROR, TRUE);
            if (SpiStatePtr->RxBuffPtr != NULL_PTR)
            {
                Spi_Lld_SetIntMode(BasePtr, SPI_RECEIVE_ERROR, TRUE);
            }
#if (SPI_SLAVE_SUPPORT == STD_ON)
            if (SpiStatePtr->SlaveMode == TRUE)
            {
                Spi_Lld_SetTxWatermarks(BasePtr, 0U);
            }
#endif
            /* Enable RDF interrupt if RX buffer is not NULL. */
            if (SpiStatePtr->RxBuffPtr != NULL_PTR)
            {
                Spi_Lld_SetIntMode(BasePtr, SPI_RX_DATA_FLAG, TRUE);
            }
            else
            {
                SpiStatePtr->RxCount = 0;
#if (SPI_DMA_USED == STD_ON)
                Spi_Lld_SetRxDmaCmd(BasePtr, FALSE);
#endif
                Spi_Lld_RxMaskSet(BasePtr, TRUE);
            }
            /* Enable the TDF and RDF interrupt. */
            Spi_Lld_SetIntMode(BasePtr, SPI_TX_DATA_FLAG, TRUE);
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_14();
        }
#endif /* SPI_DMA_USED == STD_ON*/
    }
    else
    {
        if (NULL_PTR == SpiStatePtr->RxBuffPtr)
        {
            SpiStatePtr->RxCount = 0;
            Spi_Lld_RxMaskSet(BasePtr, TRUE);
        }
    }
    return RtnTemp;
}

/*!
 * @brief  This function transmit data by Sync transmit mode.
 *
 * @param[in] Instance  The index of the SPI module
 *
 * @return              Std_ReturnType
 * @retval E_OK         Transmission has been completed successfully
 * @retval E_NOT_OK     Error occurs during transmission
 */
SPI_FUNC static Std_ReturnType Spi_Lld_SyncTransferChannel(uint8 Instance)
{
    /* Instantiate local variable of type spi_state_t and point to global state */
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    Std_ReturnType RtnTemp = E_OK;
    uint32 TimeOutValue = (uint32)SPI_TIMEOUT_VALUE;
    while ((SpiStatePtr->TxCount > 0U) && (E_OK == RtnTemp))
    {
        /* If an error is detected the transfer will be aborted */
        if ((Spi_Lld_GetStatusFlag(Base, SPI_TRANSMIT_ERROR) != 0U) && \
                (SpiStatePtr->TxBuffPtr != NULL_PTR))
        {
            (void)Spi_Lld_AbortTransfer(Instance);
            Base->STS |= ((uint32)1U << (uint32)SPI_TRANSMIT_ERROR);
            SpiStatePtr->TransferStatus = SPI_TRANSMIT_FAIL;
            RtnTemp = E_NOT_OK;
        }
        else if ((Spi_Lld_GetStatusFlag(Base, SPI_RECEIVE_ERROR) != 0U) && \
                 (SpiStatePtr->RxBuffPtr != NULL_PTR))
        {
            (void)Spi_Lld_AbortTransfer(Instance);
            Base->STS |= ((uint32)1U << (uint32)SPI_RECEIVE_ERROR);
            SpiStatePtr->TransferStatus = SPI_RECEIVE_FAIL;
            RtnTemp = E_NOT_OK;
        }
        else
        {
            /* Check read buffer only if there are remaining bytes to read. */
            if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_RX_DATA_FLAG)) && (SpiStatePtr->RxCount != (uint16)0))
            {
                Spi_Lld_ReadRXBuffer(Instance);
            }
            /* Transmit data */
            if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_TX_DATA_FLAG)) && (SpiStatePtr->TxCount != (uint16)0))
            {
                Spi_Lld_FillupTxBuffer(Instance);
            }
        }
        --TimeOutValue;
        if ((uint32)0U == TimeOutValue)
        {
            (void)Spi_Lld_AbortTransfer(Instance);
            SpiStatePtr->TransferStatus = SPI_TRANSFER_TIMEOUT;
            RtnTemp = E_NOT_OK;
        }
    }
    if (E_OK == RtnTemp)
    {
        TimeOutValue = (uint32)SPI_TIMEOUT_VALUE;
        while (SpiStatePtr->RxCount > 0U)
        {
            /* Check read buffer only if there are remaining bytes to read. */
            if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_RX_DATA_FLAG)) && (SpiStatePtr->RxCount != (uint16)0))
            {
                Spi_Lld_ReadRXBuffer(Instance);
            }
            --TimeOutValue;
            if ((uint32)0U == TimeOutValue)
            {
                SpiStatePtr->TransferStatus = SPI_TRANSFER_TIMEOUT;
                RtnTemp = E_NOT_OK;
                break;
            }
        }
    }
    return RtnTemp;
}

/*!
 * @brief  This function transmit Jobs in a sequence by Sync transmit mode.
 *
 * @param[in] Job       ID of the scheduled job
 *
 * @return              Std_ReturnType
 * @retval E_OK         Transmission has been completed successfully
 * @retval E_NOT_OK     Error occurs during transmission
 */
#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)
SPI_FUNC static Std_ReturnType Spi_Lld_SyncTransmitJob(Spi_JobType Job)
{
    Spi_ChannelType ChannelInJob = 0;
    Spi_HWUnitType HwUnit = Spi_ConfigPtr->JobConfigPtr[Job].HWUnit;
    uint8 Instance;
    const Spi_JobConfigType *JobConfigPtr = NULL_PTR;
    Std_ReturnType RtnTemp = E_OK;
    Instance = Spi_ConfigPtr->HWUnitConfigPtr[HwUnit].Instance;
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09();
    /* Setting the index of HWunit to global content*/
    TransmitHwUnit[Instance] = HwUnit;
    /* Initialize the SPI peripheral module*/
    (void)Spi_Lld_PeripheralConfig(Spi_ConfigPtr->JobConfigPtr[Job].ExternalDeviceId, Instance);
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();
    JobConfigPtr = &Spi_ConfigPtr->JobConfigPtr[Job];
    for (Spi_ChannelType ChannelId = 0; ChannelId < JobConfigPtr->NumChannels; ++ChannelId)
    {
        ChannelInJob = JobConfigPtr->ChannelLinkPtr[ChannelId];
        RtnTemp = Spi_Lld_ChannelConfig(Instance, ChannelInJob);
        if (E_OK == RtnTemp)
        {
            /* transfer channel*/
            RtnTemp = Spi_Lld_SyncTransferChannel(Instance);
            if (E_OK != RtnTemp)
            {
                RtnTemp = E_NOT_OK;
            }
        }
    }
    return RtnTemp;
}
#endif


/*!
 * @brief   This function terminates an interrupt driven asynchronous transfer early
 * @details During an a-sync (non-blocking) transfer, the user has the option to terminate the transfer early
 *          if the transfer is still in progress.
 * @param[in] Instance   The index of the SPI module
 *
 * @return              Std_ReturnType
 * @retval E_OK         Stop the transfer successful
 */
SPI_FUNC static Std_ReturnType Spi_Lld_AbortTransfer(uint8 Instance)
{
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    /* Stop the running transfer*/
    Spi_Lld_CompleteTransfer(Instance);
    Spi_Lld_SetFlushFifoCmd(Base);
    /* The second flush command is used to avoid the case when one word is still in shifter. */
    Spi_Lld_SetFlushFifoCmd(Base);
    return E_OK;
}

/*!
 * @brief   Read all data from RX FIFO
 * @details This function will read all data from RX FIFO and will transfer this information in
 *          RX software buffer.
 *
 * @param[in] Instance The index of the SPI module
 *
 * @return void
 */
SPI_FUNC static void Spi_Lld_ReadRXBuffer(uint8 Instance)
{
    /* Instantiate local variable of type spi_state_t and point to global state */
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    const volatile  SPI_Type *BasePtr = Spi_BasePtrs[Instance];
    uint32 ReceivedWord;
    uint16 NumOfBytes;
    uint8 FilledSpace = (uint8)Spi_Lld_ReadRxCount(BasePtr);
    while (FilledSpace != 0U)
    {
        ReceivedWord = BasePtr->DATA;
        /* Get the number of bytes which can be read from this 32 bites */
        if ((SpiStatePtr->BytesPerFrame - SpiStatePtr->RxFrameCnt) <= (uint16)4)
        {
            NumOfBytes = (uint16)(SpiStatePtr->BytesPerFrame - SpiStatePtr->RxFrameCnt);
        }
        else
        {
            NumOfBytes = 4U;
        }
        /* Generate the word which will be write in buffer. */
        if (SpiStatePtr->RxBuffPtr != NULL_PTR)
        {
            for (uint16 DataWriteCount = 0; DataWriteCount < NumOfBytes; ++DataWriteCount)
            {
                *(SpiStatePtr->RxBuffPtr) = (uint8)(ReceivedWord >> (DataWriteCount * 8U));
                ++SpiStatePtr->RxBuffPtr;
            }
        }
        else
        {
            /* Discard the received data. */
        }
        /* Update the number of bytes which were received in this frame. */
        switch (SpiStatePtr->BytesPerFrame)
        {
            case 1:
                SpiStatePtr->RxFrameCnt = (uint16)(((uint32)SpiStatePtr->RxFrameCnt + NumOfBytes) & 0x00U);
                break;
            case 2:
                SpiStatePtr->RxFrameCnt = (uint16)(((uint32)SpiStatePtr->RxFrameCnt + NumOfBytes) & 0x01U);
                break;
            default:
                SpiStatePtr->RxFrameCnt = (uint16)(((uint32)SpiStatePtr->RxFrameCnt + NumOfBytes) & 0x03U);
                break;
        }
        /* Update internal variable used in transmission. */
        SpiStatePtr->RxCount = (uint16)(SpiStatePtr->RxCount - NumOfBytes);
        /* Verify if all bytes were sent. */
        if (0U == SpiStatePtr->RxCount)
        {
            break;
        }
        FilledSpace = (uint8)(FilledSpace - 1U);
    }
}

/*!
 * @brief   Fill up the TX FIFO with data.
 * @details This function fills up the TX FIFO with data based on the bytes/frame.
 *
 * @param[in] Instance The index of the SPI unit
 *
 * @return void
 */
SPI_FUNC static void Spi_Lld_FillupTxBuffer(uint8 Instance)
{
    /* Instantiate local variable of type spi_master_state_t and point to global state. */
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    volatile SPI_Type *BasePtr = Spi_BasePtrs[Instance];
    uint32 WordToSend = 0;
    uint16 NumOfBytes;
    uint8 AvailableSpace = (uint8)(SpiStatePtr->FifoSize - (uint8)Spi_Lld_ReadTxCount(BasePtr));
    /* Fill the TX buffer. */
    while (AvailableSpace != 0U)
    {
        if ((TRUE == SpiStatePtr->IsPcsContinuous) && (1U == SpiStatePtr->TxCount))
        {
            /* Disable continuous PCS */
            Spi_Lld_ClearContCBit(BasePtr);
            SPI_Lld_ClearContBit(BasePtr);
            SpiStatePtr->TxCount  = 0U;
            AvailableSpace = 0U;
        }
        else
        {
            /* Get the number of bytes which can be written in a single 32 bits word. */
            if ((SpiStatePtr->BytesPerFrame - SpiStatePtr->TxFrameCnt) <= (uint16)4)
            {
                NumOfBytes = (uint16)(SpiStatePtr->BytesPerFrame - SpiStatePtr->TxFrameCnt);
            }
            else
            {
                NumOfBytes = 4U;
            }
            switch (SpiStatePtr->BytesPerFrame)
            {
                case 1:
                    WordToSend = *(SpiStatePtr->TxBuffPtr);
                    /* MR12 RULE 18.4 VIOLATION: The integer Value 1 is being added or subtracted from a pointer.
                     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
                     */
                    SpiStatePtr->TxBuffPtr +=  sizeof(uint8); /*PRQA S 0489*/
                    SpiStatePtr->TxFrameCnt = (uint16)(((uint32)SpiStatePtr->TxFrameCnt + NumOfBytes) & 0x00U);
                    break;
                case 2:
                    /* MR12 RULE 11.3 VIOLATION: Casting to different object pointer type.
                     * In this specific case, needs to obtain the bit width for transmission, thus, couldn't adhere to M3CM Rule-11.3
                     */
                    WordToSend = *((const uint16 *)(SpiStatePtr->TxBuffPtr)); /*PRQA S 0310, 3305*/
                    /* MR12 RULE 18.4 VIOLATION: The integer Value 1 is being added or subtracted from a pointer.
                     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
                     */
                    SpiStatePtr->TxBuffPtr += sizeof(uint16); /*PRQA S 0488*/
                    SpiStatePtr->TxFrameCnt = (uint16)(((uint32)SpiStatePtr->TxFrameCnt + NumOfBytes) & 0x01U);
                    break;
                default:
                    /* MR12 RULE 11.3 VIOLATION: Casting to different object pointer type.
                     * In this specific case, needs to obtain the bit width for transmission, thus, couldn't adhere to M3CM Rule-11.3
                     */
                    WordToSend = *((const uint32 *)(SpiStatePtr->TxBuffPtr)); /*PRQA S 0310, 3305*/
                    /* MR12 RULE 18.4 VIOLATION: The integer Value 1 is being added or subtracted from a pointer.
                     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
                     */
                    SpiStatePtr->TxBuffPtr += sizeof(uint32); /*PRQA S 0488*/
                    SpiStatePtr->TxFrameCnt = (uint16)(((uint32)SpiStatePtr->TxFrameCnt + NumOfBytes) & 0x03U);
                    break;
            }
            /* Writes data into the TX data buffer.*/
            BasePtr->DATA = WordToSend;
            /* Update internal variable used in transmission. */
            SpiStatePtr->TxCount = (uint16)(SpiStatePtr->TxCount - NumOfBytes);
            /* Verify if all bytes were send. */
            if (0U == SpiStatePtr->TxCount)
            {
                break;
            }
            AvailableSpace = (uint8)(AvailableSpace - 1U);
        }
    }
}

/*!
 * @brief   Interrupt handler for SPI master mode.
 * @details This handler uses the buffers stored in the spi_state_t structs to transfer data.
 *
 * @param[in] Instance The index of the SPI module
 *
 * @return void
 */
SPI_FUNC static void SPI_Lld_IRQHandler(uint8 Instance)
{
    /* Instantiate local variable of type spi_state_t and point to global state */
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    /*the interrupt of spi in slave mode will pending itself, so it may triggers one more*/
    if (SPI_HW_UNIT_TRANSMIT_FINISHED == TransmitHwUnit[Instance])
    {
        /*An unexpected interrupt */
    }
    else if ((SpiStatePtr->TransferUsing == SPI_USING_INTERRUPTS) && (FALSE == Spi_Lld_GetAllIntStatus(Base)))
    {
        /*An unexpected interrupt. Do nothing */
    }
    else
    {
        /* If an error is detected the transfer will be aborted */
        /* GCOVR_EXCL_START */
        if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_TRANSMIT_ERROR)) && (SpiStatePtr->TxBuffPtr != NULL_PTR))
        {
            (void)Spi_Lld_AbortTransfer(Instance);
            Base->STS |= ((uint32)1U << (uint32)SPI_TRANSMIT_ERROR);
            SpiStatePtr->TransferStatus = SPI_TRANSMIT_FAIL;
            SpiStatePtr->CurrentJobPtr->JobStatePtr->Result = SPI_JOB_FAILED;
            Spi_JobTransferFinished(SpiStatePtr->CurrentJobPtr);
        }
        else if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_RECEIVE_ERROR)) && (SpiStatePtr->RxBuffPtr != NULL_PTR))
        {
            (void)Spi_Lld_AbortTransfer(Instance);
            Base->STS |= ((uint32)1U << (uint32)SPI_RECEIVE_ERROR);
            SpiStatePtr->TransferStatus = SPI_RECEIVE_FAIL;
            SpiStatePtr->CurrentJobPtr->JobStatePtr->Result = SPI_JOB_FAILED;
            Spi_JobTransferFinished(SpiStatePtr->CurrentJobPtr);
        }
        /* GCOVR_EXCL_STOP */
        else
        {
            /* RECEIVE IRQ handler: Check read buffer only if there are remaining bytes to read. */
            if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_RX_DATA_FLAG)) && (SpiStatePtr->RxCount != (uint16)0))
            {
                Spi_Lld_ReadRXBuffer(Instance);
            }
            /* Transmit data */
            if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_TX_DATA_FLAG)) && (SpiStatePtr->TxCount != (uint16)0))
            {
                Spi_Lld_FillupTxBuffer(Instance);
            }
#if (SPI_SLAVE_SUPPORT == STD_ON)
            if (TRUE == SpiStatePtr->SlaveMode)
            {
                if ((uint16)0 == SpiStatePtr->RxCount)
                {
                    /*Mask Rx to discard receive data*/
                    Spi_Lld_RxMaskSet(Base, TRUE);
                    /* Disable RX flag. Software buffer is empty.*/
                    Spi_Lld_SetIntMode(Base, SPI_RX_DATA_FLAG, FALSE);
                    /* Check if we're done with this transfer.*/
                    if ((uint16)0 == SpiStatePtr->TxCount)
                    {
                        Spi_Lld_CompleteTransfer(Instance);
                        if (SpiStatePtr->RemainingChannelsTX > 0U)
                        {
                            ++SpiStatePtr->CurrentChannelIndexPointerRX;
                            ++SpiStatePtr->CurrentChannelIndexPointerTX;
                            --SpiStatePtr->RemainingChannelsRX;
                            --SpiStatePtr->RemainingChannelsTX;
                            (void)Spi_Lld_ChannelConfig(Instance, *(SpiStatePtr->CurrentChannelIndexPointerTX));
                        }
                        else
                        {
                            Spi_JobTransferFinished(SpiStatePtr->CurrentJobPtr);
                        }
                    }
                }
            }
            else
            {
#endif
                if ((uint16)0 == SpiStatePtr->TxCount)
                {
                    /* Disable TX flag. Software buffer is empty.*/
                    Spi_Lld_SetIntMode(Base, SPI_TX_DATA_FLAG, FALSE);
                    if (SpiStatePtr->TransferUsing == SPI_USING_INTERRUPTS)
                    {
                        Spi_Lld_SetIntMode(Base, SPI_TRANSFER_COMPLETE, TRUE);
                    }
                    /* Check if we're done with this transfer.*/
                    if (((uint16)0U == SpiStatePtr->RxCount) && (TRUE == Spi_Lld_GetStatusFlag(Base, SPI_TRANSFER_COMPLETE))) /*PRQA S 3415*/
                    {
                        Spi_Lld_CompleteTransfer(Instance);
                        if (SpiStatePtr->RemainingChannelsTX > 0U)
                        {
                            ++SpiStatePtr->CurrentChannelIndexPointerRX;
                            ++SpiStatePtr->CurrentChannelIndexPointerTX;
                            --SpiStatePtr->RemainingChannelsRX;
                            --SpiStatePtr->RemainingChannelsTX;
                            (void)Spi_Lld_ChannelConfig(Instance, *(SpiStatePtr->CurrentChannelIndexPointerTX));
                        }
                        else
                        {
                            Spi_JobTransferFinished(SpiStatePtr->CurrentJobPtr);
                        }
                    }
                }
#if (SPI_SLAVE_SUPPORT == STD_ON)
            }
#endif
        }
    }
}
/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function will schedule a job for a given HW unit.
* @details If the HWUnit is not busy, the transfer is started and the HW unit is
*          marked as busy.
*          If the HWUnit is not busy (another job is in progress), the new job is
*          scheduled in a waiting job list, according to its Priority.
*
* @param[in] HWUnitQueuePtr  HW Unit to be used by the job
* @param[in] Job             ID of the scheduled job
* @param[in] JobConfigPtr    Configuration of the scheduled job
*
* @return void
*
* @pre  Pre-compile Parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
SPI_FUNC void  Spi_ScheduleJob(Spi_HWUnitQueueType *HWUnitQueuePtr, Spi_JobType Job, const Spi_JobConfigType *JobConfigPtr)
{
    sint8 Priority;
    Spi_JobType *JobListTailPtr = NULL_PTR;
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_10();
    if (SPI_IDLE == HWUnitQueuePtr->Status)
    {
        /* idle unit => the job can be started */
        HWUnitQueuePtr->Status = SPI_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_10();
        /* mark the job as pending */
        Spi_JobState[Job].Result = SPI_JOB_PENDING;
        Spi_Lld_AsyncTransmitJob(JobConfigPtr);
    }
    else
    {
        /* add the job to the scheduling corresponding queue */
        /* retrieve the tail of the scheduling queue for the job Priority */
        Priority = JobConfigPtr->Priority;
        JobListTailPtr = &HWUnitQueuePtr->ScheduledJobsListTail[Priority];
        if (SPI_JOB_NULL == *JobListTailPtr)
        {
            /* the list is empty => set also the head of the list */
            HWUnitQueuePtr->ScheduledJobsListHead[Priority] = Job;
        }
        else
        {
            /* add the item at the end of the list */
            Spi_JobState[*JobListTailPtr].AsyncNextJob = Job;
        }
        /* set the new tail of the list */
        *JobListTailPtr = Job;
        /* the new item will be the last element in the list */
        Spi_JobState[Job].AsyncNextJob = SPI_JOB_NULL;
        if (HWUnitQueuePtr->MaxScheduledPriority < Priority)
        {
            HWUnitQueuePtr->MaxScheduledPriority = Priority;
        }
        else
        {
            /* Do nothing */
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_10();
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function is called after a Job has been executed.
* @details The function calls Job and Sequence end notifications and schedules
*          the next job of the sequence or on the liberated HW Unit.
*
* @param[in] JobConfigPtr   The just transmitted job pointer.
*
* @return void
*
* @pre  Pre-compile Parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
* @implements Spi_JobTransferFinished_Activity
*/
SPI_FUNC static void Spi_JobTransferFinished(const Spi_JobConfigType *JobConfigPtr)
{
    Spi_HWUnitType HwUnit = JobConfigPtr->HWUnit;
    Spi_HWUnitQueueType *HWUnitQueuePtr = &Spi_HwUnitQueues[HwUnit];
    Spi_JobStateType *JobStatePtr = JobConfigPtr->JobStatePtr;
    Spi_SequenceStateType *SequenceStatePtr;
    const Spi_SequenceConfigType *SequenceCfgPtr;
    const Spi_JobType *JobPtr;
    const Spi_JobConfigType *JobTransferPtr;
    Spi_JobType Job;
    uint8 Instance;
    Instance = Spi_ConfigPtr->HWUnitConfigPtr[HwUnit].Instance;
    if (SPI_JOB_OK != JobStatePtr->Result)
    {
        SequenceStatePtr = JobStatePtr->AsyncCrtSequenceStatePtr;
        SequenceCfgPtr = SequenceStatePtr->SequencePtr;
        if (SPI_JOB_FAILED == JobStatePtr->Result)
        {
            /* Job failed => sequence failed */
            SequenceStatePtr->Result = SPI_SEQ_FAILED;
        }
        else
        {
            /* set job result OK */
            JobStatePtr->Result = SPI_JOB_OK;
        }
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_11();
        /* Release the index which used by external device unit */
        TransmitHwUnit[Instance] = SPI_HW_UNIT_TRANSMIT_FINISHED;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        /* unlink the job from its sequence */
        JobStatePtr->AsyncCrtSequenceStatePtr = NULL_PTR;
        /* Perform job EndNotification (if there is one) */
        if (NULL_PTR != JobConfigPtr->JobEndNotification)
        {
            JobConfigPtr->JobEndNotification();
        }
        else
        {
            /* Do nothing */
        }
#if (SPI_CANCEL_API == STD_ON)
        /* Check if current sequence has been cancelled */
        if ((SPI_SEQ_CANCELLED == SequenceStatePtr->Result) || (SPI_SEQ_FAILED == SequenceStatePtr->Result))
#else
        if (SPI_SEQ_FAILED == SequenceStatePtr->Result)
#endif
        {
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_CANCEL_API == STD_ON)
            /* unlock jobs */
            Spi_UnlockRemainingJobs(SequenceStatePtr->RemainingJobs, SequenceCfgPtr);
#endif
#endif
#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            if (SPI_SEQ_FAILED == SequenceStatePtr->Result)
            {
                /* Report to DEM */
                Spi_180_DemReportStatus(DEM_EVENT_STATUS_FAILED);
            }
            else
            {
                /* Report to DEM */
                Spi_180_DemReportStatus(DEM_EVENT_STATUS_PASSED);
            }
#endif
            if (NULL_PTR != SequenceCfgPtr->SeqEndNotification)
            {
                SequenceCfgPtr->SeqEndNotification();
            }
            else
            {
                /* Do nothing */
            }
            Spi_ScheduleNextJob(HWUnitQueuePtr);
        }
        else
        {
            /* Check if this job is the last one */
            if (0u == SequenceStatePtr->RemainingJobs)
            {
                /* Reset sequence state */
                SequenceStatePtr->Result = SPI_SEQ_OK;
#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                /* Report to DEM */
                Spi_180_DemReportStatus(DEM_EVENT_STATUS_PASSED);
#endif
                /* SeqEndNotification */
                if (NULL_PTR != SequenceCfgPtr->SeqEndNotification)
                {
                    SequenceCfgPtr->SeqEndNotification();
                }
                else
                {
                    /* Do nothing */
                }
                Spi_ScheduleNextJob(HWUnitQueuePtr);
            }
            else
            {
                /* advance to the next job */
                /*
                * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                ++SequenceStatePtr->CurrentJobIndexPtr;
                JobPtr = SequenceStatePtr->CurrentJobIndexPtr;
                Job = *JobPtr;
                --SequenceStatePtr->RemainingJobs;
                /*
                * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                JobTransferPtr = &Spi_ConfigPtr->JobConfigPtr[Job];
                if (HwUnit != JobTransferPtr->HWUnit)
                {
                    /* schedule the next job on the new SPI unit */
                    Spi_ScheduleJob(&Spi_HwUnitQueues[JobTransferPtr->HWUnit], Job, JobTransferPtr);
                    /* transmit the next scheduled job on the current SPI unit */
                    Spi_ScheduleNextJob(HWUnitQueuePtr);
                }
                else
                {
                    /* the next job uses the same SPI unit */
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
                    if (TRUE == SequenceCfgPtr->Interruptible)
                    {
                        /* if the sequence is interruptible, then schedule the next job */
                        /* SPI is marked as BUSY => the new job is scheduled only */
                        Spi_ScheduleJob(HWUnitQueuePtr, Job, JobTransferPtr);
                        /* run the first eligible job */
                        Spi_ScheduleNextJob(HWUnitQueuePtr);
                    }
                    else
#endif
                    {
                        /* non-interruptible sequence => start transmission without scheduling */
                        /* mark the job as pending */
                        Spi_JobState[Job].Result = SPI_JOB_PENDING;
                        Spi_Lld_AsyncTransmitJob(JobTransferPtr);
                    }
                }
            }
        }
    }
    else
    {
        /* Do nothing*/
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/**
* @brief    This function is used to initializes the global state pointer
*
* @param[in] HWUnit   The index of the SPI external device configuration unit
*
* @return             Std_ReturnType
* @retval E_OK        The configuration succeeded
*/
SPI_FUNC Std_ReturnType Spi_Lld_GlobalStateInit(Spi_HWUnitType HWUnit)
{
    /* Instantiate local variable of type spi_state_t and point to global state */
    Spi_StateType *SpiStatePtr = &Spi_States[HWUnit];
    SpiStatePtr->TransferUsingInterruptEn = FALSE;
    /*Initialize global state pointer*/
    Spi_StatePtrs[HWUnit] = SpiStatePtr;
    return E_OK;
}

/**
 * @brief    Configures the desired SPI PCS polarity.
 *
 * @param[in]  ConfigPtr The configuration pointer
 * @param[in]  JobId     The index of the job
 *
 * @return void
 */
SPI_FUNC void Spi_Lld_SetPcsPolarityMode(const Spi_ConfigType *ConfigPtr, Spi_JobType JobId)
{
    uint8 Instance;
    Spi_WhichPcsType WhichPcs;
    Spi_PcsPolarityType Polarity;
    uint32 TempRegValue;
    Instance = ConfigPtr->HWUnitConfigPtr[ConfigPtr->JobConfigPtr[JobId].HWUnit].Instance;
    WhichPcs = ConfigPtr->ExternalDeviceConfigPtr[ConfigPtr->JobConfigPtr[JobId].ExternalDeviceId].WhichPcs;
    Polarity = ConfigPtr->ExternalDeviceConfigPtr[ConfigPtr->JobConfigPtr[JobId].ExternalDeviceId].PcsPolarity;
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    TempRegValue = (Base->CTRL & SPI_CTRL_CSPOL_MASK) >> SPI_CTRL_CSPOL_SHIFT;
    /* Clear the PCS polarity bit */
    TempRegValue &= ~((uint32)1U << (uint8)WhichPcs);
    /* Set the PCS polarity bit */
    TempRegValue |= (uint32)Polarity << (uint8)WhichPcs;
    Base->CTRL = SPI_CTRL_CSPOL(TempRegValue);
}

/**
 * @brief  This function updates the asynchronous mechanism mode for the specified SPI module.
 *
 * @param[in]  HwUnit The index of the SPI external device configuration unit
 * @param[in]  Mode   new mode needs to be configured (interrupt or polling)
 *
 * @return           Std_ReturnType
 * @retval E_OK      The command ended successfully
 */
#if(SPI_LEVEL_DELIVERED == LEVEL2)
SPI_FUNC void Spi_Lld_SetAsyncMode(const Spi_HWUnitType HwUnit, Spi_AsyncModeType Mode)
{
    Spi_StateType *SpiStatePtr = NULL_PTR;
    /*initialize pointer*/
    SpiStatePtr = &Spi_States[HwUnit];
    /*set Async mode*/
    SpiStatePtr->AsyncMode = Mode;
    /*Set transfer using medium , according to asynchronous mode*/
    switch (Mode)
    {
        case SPI_POLLING_MODE:
            SpiStatePtr->TransferUsing = SPI_USING_POLLING;
            SpiStatePtr->TransferUsingInterruptEn = FALSE;
            break;
        case SPI_INTERRUPT_MODE:
            SpiStatePtr->TransferUsing = SPI_USING_INTERRUPTS;
            SpiStatePtr->TransferUsingInterruptEn = TRUE;
            break;
        default:
            /*Do nothing*/
            break;
    }
}
#endif /*(SPI_LEVEL_DELIVERED == LEVEL2) */



/**
 * @brief  This function used to get the current job of the sequence and transmit it with the asynchronous mechanism mode.
 *
 * @param[in]  JobConfigPtr The just transmitted job pointer.
 *
 * @return void
 */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
SPI_FUNC void Spi_Lld_AsyncTransmitJob(const Spi_JobConfigType *JobConfigPtr)
{
    uint8 Instance;
    Spi_StateType *SpiStatePtr = &Spi_States[JobConfigPtr->HWUnit];
    /* start job notification to assert the non-cs pin,
        when non-cs pin is used as chip select*/
    if (NULL_PTR != JobConfigPtr->JobStartNotification)
    {
        JobConfigPtr->JobStartNotification();
    }
    else
    {
        /* Do nothing */
    }
    Instance = Spi_ConfigPtr->HWUnitConfigPtr[JobConfigPtr->HWUnit].Instance;
    /* Initialize the SPI peripheral module*/
    (void)Spi_Lld_PeripheralConfig(JobConfigPtr->ExternalDeviceId, Instance);
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_12();
    /* Setting the index of HWunit to global content*/
    TransmitHwUnit[Instance] = JobConfigPtr->HWUnit;
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_12();
    SpiStatePtr->CurrentJobPtr = JobConfigPtr;
    SpiStatePtr->CurrentChannelIndexPointerRX = JobConfigPtr->ChannelLinkPtr;
    SpiStatePtr->CurrentChannelIndexPointerTX = JobConfigPtr->ChannelLinkPtr;
    SpiStatePtr->RemainingChannelsRX = JobConfigPtr->NumChannels - (Spi_ChannelType)1u;
    SpiStatePtr->RemainingChannelsTX = JobConfigPtr->NumChannels - (Spi_ChannelType)1u;
    (void)Spi_Lld_ChannelConfig(Instance, SpiStatePtr->CurrentChannelIndexPointerTX[0]);
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/**
 * @brief  This function is used for synchronous transmission of a given sequence.
 * @details
 * @param[in] Sequence         Sequence ID.
 *
* @return                      Std_ReturnType
* @retval E_OK                 Transmission has been completed successfully
* @retval E_NOT_OK             Transmission command has not been accepted
*/
#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)
SPI_FUNC Std_ReturnType Spi_Lld_SyncTransmit(Spi_SequenceType Sequence)
{
    const Spi_JobType *JobIndexList = NULL_PTR;
    Spi_JobType JobInSeq = 0;
    Std_ReturnType RtnTemp = E_OK;
    uint8 Instance;
    JobIndexList = Spi_ConfigPtr->SequenceConfigPtr[Sequence].JobIndexListPtr;
    for (Spi_JobType JobIndex = 0; JobIndex < Spi_ConfigPtr->SequenceConfigPtr[Sequence].NumJobs; ++JobIndex)
    {
        /* Get the job id */
        JobInSeq = Spi_ConfigPtr->SequenceConfigPtr[Sequence].JobIndexListPtr[JobIndex];
        /* Set the job status as pending */
        Spi_JobState[JobInSeq].Result = SPI_JOB_PENDING;
        /* Perform job StartNotification (if there is one) */
        if (NULL_PTR != Spi_ConfigPtr->JobConfigPtr[JobInSeq].JobStartNotification)
        {
            Spi_ConfigPtr->JobConfigPtr[JobInSeq].JobStartNotification();
        }
        else
        {
            /* Do nothing */
        }
        /* Mark HWUnit as busy */
        Spi_HwUnitQueues[Spi_ConfigPtr->JobConfigPtr[*JobIndexList].HWUnit].Status = SPI_BUSY;
        /* Synchronous transmission for a Job*/
        RtnTemp = Spi_Lld_SyncTransmitJob(JobInSeq);
        /* release HWUnit */
        Spi_HwUnitQueues[Spi_ConfigPtr->JobConfigPtr[*JobIndexList].HWUnit].Status = SPI_IDLE;
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_13();
        Instance = Spi_ConfigPtr->HWUnitConfigPtr[Spi_ConfigPtr->JobConfigPtr[*JobIndexList].HWUnit].Instance;
        TransmitHwUnit[Instance] = SPI_HW_UNIT_TRANSMIT_FINISHED;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_13();
        if (E_OK == RtnTemp)
        {
            /* Set the job status as OK */
            Spi_JobState[JobInSeq].Result = SPI_JOB_OK;
            /* Perform job EndNotification (if there is one) */
            if (NULL_PTR != Spi_ConfigPtr->JobConfigPtr[JobInSeq].JobEndNotification)
            {
                Spi_ConfigPtr->JobConfigPtr[JobInSeq].JobEndNotification();
            }
        }
        else
        {
            /* Transmission failed */
            for (Spi_JobType JobFailedIndex = JobIndex; JobFailedIndex < Spi_ConfigPtr->SequenceConfigPtr[Sequence].NumJobs; ++JobFailedIndex)
            {
                JobInSeq = Spi_ConfigPtr->SequenceConfigPtr[Sequence].JobIndexListPtr[JobFailedIndex];
                /* Set the job status as FAILED */
                Spi_JobState[JobInSeq].Result = SPI_JOB_FAILED;
                /* Perform job EndNotification (if there is one) */
                if (NULL_PTR != Spi_ConfigPtr->JobConfigPtr[JobInSeq].JobEndNotification)
                {
                    Spi_ConfigPtr->JobConfigPtr[JobInSeq].JobEndNotification();
                }
            }
            break;
        }
    }
    return RtnTemp;
}
#endif /*#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)*/

/*!
 * @brief   Asynchronously polling SPI interrupts and call ISR if appropriate.
 * @details This function shall asynchronously poll SPI interrupts and call
 *          ISR if appropriate.
 *
 * @param[in] Instance The index of the SPI module
 *
 * @return void
 */
SPI_FUNC void Spi_Lld_IrqPolling(uint8 Instance)
{
    Spi_StateType *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
#if (SPI_DMA_USED == STD_ON)
    CddDma_ChannelStatusReturnType DmaChnStatus;
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
#endif
    if (SpiStatePtr->TransferUsing == SPI_USING_POLLING)
    {
#if (SPI_DMA_USED == STD_ON)
        if (FALSE == SpiStatePtr->DmaUsed)
#endif
        {
            SPI_Lld_IRQHandler(Instance);
        }
#if (SPI_DMA_USED == STD_ON)
        else
        {
            if (SpiStatePtr->RxBuffPtr != NULL_PTR)
            {
                CddDma_GetChannelStatus(SpiStatePtr->RxDMAChannel, &DmaChnStatus);
                if (TRUE == DmaChnStatus.Done)
                {
#if (SPI_SLAVE_SUPPORT == STD_ON)
                    if (TRUE == SpiStatePtr->SlaveMode)
                    {
                        /*Mask Rx to discard receive data*/
                        Spi_Lld_RxMaskSet(Base, TRUE);
                    }
#endif
                    CddDma_ClearChannelDoneStatus(SpiStatePtr->RxDMAChannel);
                    CddDma_StopChannel(SpiStatePtr->RxDMAChannel);
                    SpiStatePtr->RxCount = 0;
                }
                if (DmaChnStatus.Errors != 0U)
                {
                    CddDma_StopChannel(SpiStatePtr->RxDMAChannel);
                    SpiStatePtr->TransferStatus = SPI_RECEIVE_FAIL;
                    SpiStatePtr->CurrentJobPtr->JobStatePtr->AsyncCrtSequenceStatePtr->Result = SPI_SEQ_FAILED;
                }
            }
            CddDma_GetChannelStatus(SpiStatePtr->TxDMAChannel, &DmaChnStatus);
            if (TRUE == DmaChnStatus.Done)
            {
#if (SPI_SLAVE_SUPPORT == STD_ON)
                if (FALSE == SpiStatePtr->SlaveMode)
                {
#endif
                    if (TRUE == SpiStatePtr->IsPcsContinuous)
                    {
                        Spi_Lld_ClearContCBit(Base);
                    }
#if (SPI_SLAVE_SUPPORT == STD_ON)
                }
#endif
                CddDma_ClearChannelDoneStatus(SpiStatePtr->TxDMAChannel);
                CddDma_StopChannel(SpiStatePtr->TxDMAChannel);
                SpiStatePtr->TxCount = 0;
                SpiStatePtr->TransferStatus = SPI_TRANSFER_OK;
            }
            if (DmaChnStatus.Errors != 0U)
            {
                CddDma_StopChannel(SpiStatePtr->TxDMAChannel);
                SpiStatePtr->TransferStatus = SPI_TRANSMIT_FAIL;
                SpiStatePtr->CurrentJobPtr->JobStatePtr->AsyncCrtSequenceStatePtr->Result = SPI_SEQ_FAILED;
            }
#if (SPI_SLAVE_SUPPORT == STD_ON)
            if (TRUE == SpiStatePtr->SlaveMode)
            {
                if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_FRAME_COMPLETE)) && ((uint16)0 == SpiStatePtr->RxCount))
                {
                    Spi_Lld_CompleteTransfer(Instance);
                    if (SpiStatePtr->RemainingChannelsTX > 0U)
                    {
                        ++SpiStatePtr->CurrentChannelIndexPointerRX;
                        ++SpiStatePtr->CurrentChannelIndexPointerTX;
                        --SpiStatePtr->RemainingChannelsRX;
                        --SpiStatePtr->RemainingChannelsTX;
                        (void)Spi_Lld_ChannelConfig(Instance, *(SpiStatePtr->CurrentChannelIndexPointerTX));
                    }
                    else
                    {
                        Spi_JobTransferFinished(SpiStatePtr->CurrentJobPtr);
                    }
                }
            }
            else
            {
#endif
                if ((TRUE == Spi_Lld_GetStatusFlag(Base, SPI_TRANSFER_COMPLETE)) && ((uint16)0 == SpiStatePtr->RxCount))
                {
                    Spi_Lld_CompleteTransfer(Instance);
                    if (SpiStatePtr->RemainingChannelsTX > 0U)
                    {
                        ++SpiStatePtr->CurrentChannelIndexPointerRX;
                        ++SpiStatePtr->CurrentChannelIndexPointerTX;
                        --SpiStatePtr->RemainingChannelsRX;
                        --SpiStatePtr->RemainingChannelsTX;
                        (void)Spi_Lld_ChannelConfig(Instance, *(SpiStatePtr->CurrentChannelIndexPointerTX));
                    }
                    else
                    {
                        Spi_JobTransferFinished(SpiStatePtr->CurrentJobPtr);
                    }
                }
#if (SPI_SLAVE_SUPPORT == STD_ON)
            }
#endif
        }
#endif
    }
}

#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))

SPI_FUNC LOCAL_INLINE void Spi_Lld_SlaveInstanceCancel(uint8 Instance, uint8 HwUnit)
{
    volatile SPI_Type *Base = Spi_BasePtrs[Instance];
    Spi_HWUnitQueueType *HWUnitQueuePtr = &Spi_HwUnitQueues[HwUnit];
#if (SPI_DMA_USED == STD_ON)
    Spi_StateType const *SpiStatePtr = Spi_StatePtrs[TransmitHwUnit[Instance]];
#endif /*SPI_DMA_USED == STD_ON*/
    if (HWUnitQueuePtr->Status == SPI_BUSY)
    {
        /*Mask Rx to discard receive data*/
        Spi_Lld_RxMaskSet(Base, TRUE);
#if (SPI_DMA_USED == STD_ON)
        if (TRUE == SpiStatePtr->DmaUsed)
        {
            /*Disable all DMA request*/
            CddDma_StopChannel(SpiStatePtr->RxDMAChannel);
            CddDma_StopChannel(SpiStatePtr->TxDMAChannel);
        }
#endif /*SPI_DMA_USED == STD_ON*/
    }
    HWUnitQueuePtr->Status = SPI_IDLE;
}

/**
 * @brief   This function is used to cancel the current slave transmission.
 *
 * @param[in] JobConfig Pointer to the job configuration
 *
 * @return void
 */
SPI_FUNC void Spi_Lld_SlaveCancel(const Spi_JobConfigType *JobConfig)
{
    boolean IsSlaveMode;
    uint8 Instance;
    IsSlaveMode = Spi_ConfigPtr->ExternalDeviceConfigPtr[JobConfig->ExternalDeviceId].SlaveMode;
    Instance = Spi_ConfigPtr->HWUnitConfigPtr[JobConfig->HWUnit].Instance;
    if (TRUE == IsSlaveMode)
    {
        Spi_Lld_SlaveInstanceCancel(Instance, JobConfig->HWUnit);
        Spi_JobTransferFinished(JobConfig);
    }
}
#endif /*#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))*/
#endif /*#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))*/

#ifdef SPI0
/*!
 * @brief This function is the implementation of SPI0 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI0_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_0);
}
#endif

#ifdef SPI1
/*!
 * @brief This function is the implementation of SPI1 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI1_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_1);
}
#endif

#ifdef SPI2
/*!
 * @brief This function is the implementation of SPI2 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI2_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_2);
}
#endif

#ifdef SPI3
/*!
 * @brief This function is the implementation of SPI3 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI3_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_3);
}
#endif

#ifdef SPI4
/*!
 * @brief This function is the implementation of SPI4 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI4_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_4);
}
#endif

#ifdef SPI5
/*!
 * @brief This function is the implementation of SPI5 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI5_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_5);
}
#endif

/*GCOVR_EXCL_START */
/*The instance of spi6 and spi7 are not tested due to JTAG port conflict, but they are tested by the released demo*/
#ifdef SPI6
/*!
 * @brief This function is the implementation of SPI6 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI6_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_6);
}
#endif

#ifdef SPI7
/*!
 * @brief This function is the implementation of SPI7 handler named in startup code.
 *
 */
SPI_FUNC ISR(SPI7_IRQHandler)
{
    SPI_Lld_IRQHandler((uint8)SPI_7);
}
#endif
/*GCOVR_EXCL_STOP */
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Spi_Lld.c */

