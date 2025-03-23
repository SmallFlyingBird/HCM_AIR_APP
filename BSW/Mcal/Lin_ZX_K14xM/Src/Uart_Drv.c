/**************************************************************************************************/
/**
 * @file      : Uart_Drv.c
 * @brief     : Lin low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Uart_Drv
 *  @brief Uart low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Uart_Drv.h"
#include "Device_Regs.h"
#include "SchM_Lin.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define UART_DRV_C_VENDOR_ID                   0x00B3U
#define UART_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define UART_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define UART_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define UART_DRV_C_SW_MAJOR_VERSION            1U
#define UART_DRV_C_SW_MINOR_VERSION            2U
#define UART_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Uart_Drv header file are of the same vendor */
#if (UART_DRV_H_VENDOR_ID != UART_DRV_C_VENDOR_ID)
    #error "Vendor ID of Uart_Drv.h and Uart_Drv.c are different"
#endif
/* Check if current file and Uart_Drv header file are of the same Autosar version */
#if ((UART_DRV_H_AR_RELEASE_MAJOR_VERSION != UART_DRV_C_AR_RELEASE_MAJOR_VERSION) ||               \
     (UART_DRV_H_AR_RELEASE_MINOR_VERSION != UART_DRV_C_AR_RELEASE_MINOR_VERSION) ||               \
     (UART_DRV_H_AR_RELEASE_REVISION_VERSION != UART_DRV_C_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Uart_Drv.h and Uart_Drv.c are different"
#endif
/* Check if current file and Uart_Drv header file are of the same Software version */
#if ((UART_DRV_H_SW_MAJOR_VERSION != UART_DRV_C_SW_MAJOR_VERSION) ||                               \
     (UART_DRV_H_SW_MINOR_VERSION != UART_DRV_C_SW_MINOR_VERSION) ||                               \
     (UART_DRV_H_SW_PATCH_VERSION != UART_DRV_C_SW_PATCH_VERSION))
    #error "Software Version of Uart_Drv.h and Uart_Drv.c are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((UART_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (UART_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Uart_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Lin.h are the same Autosar version */
    #if ((UART_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_LIN_H_AR_RELEASE_MAJOR_VERSION) ||           \
         (UART_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_LIN_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Uart_Drv.c and SchM_Lin.h are different"
    #endif
#endif


#define UART_DRV_INTSTA_IID_BYDET       0x07U


#define UART_DRV_LIN_SEND_BREAK_MIN 13U
#define UART_DRV_LIN_SEND_BREAK_THR 11U

#define UART_DRV_LIN_HEADER_DONE_FLG ((uint32)1U << 14U)
#define UART_DRV_LIN_RSP_DONE_FLAG   ((uint32)1U << 15U)
#define UART_DRV_LIN_TO_ERR          ((uint32)1U << 13U)
#define UART_DRV_LIN_CHECKSUM_ERR    ((uint32)1U << 12U)
#define UART_DRV_LIN_PID_ERR         ((uint32)1U << 11U)
#define UART_DRV_LIN_SYNC_FIELD_ERR  ((uint32)1U << 10U)
#define UART_DRV_LIN_ASYNC_INT_FLAG  ((uint32)1U << 9U)

#define UART_DRV_LSI_DR   (1U)
#define UART_DRV_LSI_OE   (1U << 1U)
#define UART_DRV_LSI_PE   (1U << 2U)
#define UART_DRV_LSI_FE   (1U << 3U)
#define UART_DRV_LSI_BI   (1U << 4U)
#define UART_DRV_LSI_RFE  (1U << 7U)

#if(STD_ON == UART_DRV_SOFTWARE_SIMULATION)
#define UART_DRV_LSI_RCVADDR  ((uint32)1U << 8U)
#endif



#define UART_DRV_LIN_HEADER_DONE_ERROR_FLAG                                                        \
    (UART_DRV_LIN_SYNC_FIELD_ERR | UART_DRV_LIN_PID_ERR | UART_DRV_LIN_TO_ERR)

#define UART_DRV_LIN_RSP_DONE_ERROR_FLAG                                                           \
    ( UART_DRV_LIN_CHECKSUM_ERR | UART_DRV_LIN_TO_ERR)

#define UART_LSI_INT_FLAG ( UART_DRV_LSI_PE | UART_DRV_LSI_FE | UART_DRV_LSI_BI \
                          | UART_DRV_LSI_RFE )

#define UART_DRV_ENABLE_FIFO   1U
#define UART_DRV_RESET_RX_FIFO (1U << 1U)
#define UART_DRV_RESET_TX_FIFO (1U << 2U)

#define UART_DRV_BREAKLEN(LEN)   \
 (((uint32)LEN) >= UART_DRV_LIN_SEND_BREAK_MIN) ? \
 (((uint32)LEN) - UART_DRV_LIN_SEND_BREAK_THR) : \
(UART_DRV_LIN_SEND_BREAK_MIN - UART_DRV_LIN_SEND_BREAK_THR)

/** @} end of Private_MacroDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

/* PB config: user config number of uart: UART_DRV_NUMBER_OF_INSTANCES_USED defined in cfg.c */
Uart_Drv_TransferConfigType Uart_Drv_TransferConfigArray[UART_DRV_NUMBER_OF_INSTANCES_USED];

#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_PTR
#include "Lin_MemMap.h"

/* Table to save LIN user config structure pointers */
static const Uart_Drv_ConfigType *Uart_Drv_ConfigArrayPtr[UART_DRV_INSTANCE_NUM];

/* global variable: each uart channel has one */
static Uart_Drv_TransferConfigType *Uart_Drv_TransferConfigArrayPtr[UART_DRV_INSTANCE_NUM];

#define LIN_STOP_SEC_VAR_CLEARED_PTR
#include "Lin_MemMap.h"


#define LIN_START_SEC_VAR_INIT_8
#include "Lin_MemMap.h"




#define LIN_STOP_SEC_VAR_INIT_8
#include "Lin_MemMap.h"


/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

/* Store uart data to send or receive */
static uint8 Uart_Drv_SduBufferArray[UART_DRV_INSTANCE_NUM][UART_DRV_LIN_MAX_DATA_LENGTH];
/* Configure wakeup byte because it depends on baudrate */
static uint8 Uart_Drv_WakeupSignalArray[UART_DRV_INSTANCE_NUM];

static uint8 Uart_Drv_WakeupDetectInvertArray[UART_DRV_INSTANCE_NUM];

/* slave autosync flag */
static uint8 Uart_Drv_SlaveAutosyncErrFlagArray[UART_DRV_INSTANCE_NUM];

#ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
/* Baud rate autosync flag */
static volatile uint8 Uart_Drv_BaudRateAutoSyncFlag[UART_DRV_INSTANCE_NUM];
#endif

/* Used to distinguish which modes require handle LineStatusIrqHandler in poll mode */
static volatile uint8 Uart_Drv_LineStatusFlag[UART_DRV_INSTANCE_NUM];


#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_32
#include "Lin_MemMap.h"

static uint32 Uart_Drv_LineStatusBufArray[UART_DRV_INSTANCE_NUM];
/* FIFO Control register buff */
static uint32 Uart_Drv_FifoBufArray[UART_DRV_INSTANCE_NUM];

static uint32 Uart_Drv_PollingFlagArray[UART_DRV_INSTANCE_NUM];


#define LIN_STOP_SEC_VAR_CLEARED_32
#include "Lin_MemMap.h"

#define LIN_START_SEC_CONST_PTR
#include "Lin_MemMap.h"

static Reg_Uart_BfType  * const Uart_Drv_UartRegBfPtr[UART_DRV_INSTANCE_NUM]=
{
  (Reg_Uart_BfType *)UART0_BASE_ADDR, (Reg_Uart_BfType *)UART1_BASE_ADDR,
  (Reg_Uart_BfType *)UART2_BASE_ADDR, (Reg_Uart_BfType *)UART3_BASE_ADDR,
  (Reg_Uart_BfType *)UART4_BASE_ADDR, (Reg_Uart_BfType *)UART5_BASE_ADDR,
};

static Reg_Uart_WType * const Uart_Drv_UartRegWPtr[UART_DRV_INSTANCE_NUM]=
{
  (Reg_Uart_WType *)UART0_BASE_ADDR, (Reg_Uart_WType *)UART1_BASE_ADDR,
  (Reg_Uart_WType *)UART2_BASE_ADDR, (Reg_Uart_WType *)UART3_BASE_ADDR,
  (Reg_Uart_WType *)UART4_BASE_ADDR, (Reg_Uart_WType *)UART5_BASE_ADDR,
};
#define LIN_STOP_SEC_CONST_PTR
#include "Lin_MemMap.h"

#define LIN_START_SEC_CONST_32
#include "Lin_MemMap.h"

static const uint32 Uart_Drv_InterruptMaskArray[] = 
{
    0x00000001U, /*!< UART_DRV_INT_RBFI */
    0x00000082U, /*!< UART_DRV_INT_TBEI */
    0x00000004U, /*!< UART_DRV_INT_LSI */
    0x00000008U, /*!< UART_DRV_INT_MODEM */
    0x00000000U, /*!< UART_DRV_INT_BYDET */
    0x00000001U, /*!< UART_DRV_INT_RCVRTO */
    0x00000100U, /*!< UART_DRV_INT_HEADER_DONE */
    0x00000200U, /*!< UART_DRV_INT_RSP_DONE */
    0x00000400U, /*!< UART_DRV_INT_ASYNC */
    0x0000078FU, /*!< UART_DRV_INT_ALL */
};

static const uint32 Uart_Drv_LineStatusTable[]=
{
    0x00000001U,           /*!< UART_LINESTA_DR */
    0x00000002U,           /*!< UART_LINESTA_OE */
    0x00000004U,           /*!< UART_LINESTA_PE */
    0x00000008U,           /*!< UART_LINESTA_FE */
    0x00000010U,           /*!< UART_LINESTA_BI */
    0x00000020U,           /*!< UART_LINESTA_THRE */
    0x00000040U,           /*!< UART_LINESTA_TEMT */
    0x00000080U,           /*!< UART_LINESTA_RFE */
    0x0000009eU,           /*!< UART_LINESTA_TRANS_ERR */
    0x00000100U,           /*!< UART_LINESTA_ADDR_RCVD */
    0x00000200U,           /*!< UART_LINESTA_ASYNC */
    0x00000400U,           /*!< UART_LINESTA_FIELD_ERR */
    0x00000800U,           /*!< UART_LINESTA_PID_ERR */
    0x00001000U,           /*!< UART_LINESTA_CHECKSUM_ERR */
    0x00002000U,           /*!< UART_LINESTA_TO_ERR */
    0x00004000U,           /*!< UART_LINESTA_HEADER_DONE */
    0x00008000U,           /*!< UART_LINESTA_RSP_DONE */
};

static const uint32 Uart_Drv_PollingMaskArray[] = 
{
    0x00000001U, /*!< UART_DRV_POLL_RBFI */
    0x00000002U, /*!< UART_DRV_POLL_HEADER_DONE */
    0x00000004U, /*!< UART_DRV_POLL_RSP_DONE */
    0x00000008U, /*!< UART_DRV_POLL_ASYNC */
    0x000000FFU, /*!< UART_DRV_POLL_ALL */
};


#define LIN_STOP_SEC_CONST_32
#include "Lin_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
static void Uart_Drv_ClearTransmission(uint8 InstanceId);
static void Uart_Drv_EnableInterrupts(uint8 InstanceId, Uart_Drv_IntType IntType,
                                                 boolean IntMask);
static uint32 Uart_Drv_GetAllLineStatus(uint8 InstanceId);
static void Uart_Drv_SendBytes(uint8 InstanceId, const uint8 Data[], uint8 Len);
static uint8 Uart_Drv_ReceiveByte(uint8 InstanceId);
static void Uart_Drv_ReceiveBytes(uint8 InstanceId, uint32 Length, uint8 Data[]);
static void Uart_Drv_EnableFifo(uint8 InstanceId);
static void Uart_Drv_DisableFifo(uint8 InstanceId);
 
static boolean Uart_Drv_GetBusyStatus(uint8 InstanceId);
static boolean Uart_Drv_WaitBusyClear(uint8 InstanceId);
static boolean Uart_Drv_WaitBreakFlagClear(uint8 InstanceId);
static boolean Uart_Drv_SendWakeupSignal(uint8 InstanceId, uint32 WakeupByte);
static uint8 Uart_Drv_ChecksumCalc(const uint8 *BufferPtr, const uint8 SizeBuffer,
                                       const uint8 Pid);
static void Uart_Drv_ProcessResponse(uint8 InstanceId, 
                                                const Uart_Drv_PduType *PduInfoPtr);
static void Uart_Drv_DetectBreak(uint8 InstanceId);
#if(STD_OFF == UART_DRV_SOFTWARE_SIMULATION)
#if (STD_ON == UART_DRV_MASTER_SUPPORT)
static void Uart_Drv_ReadbackMasterSync(uint8 InstanceId, uint8 Data);
static void Uart_Drv_ReadbackMasterPid(uint8 InstanceId, uint8 Data);
#endif
#endif
static void Uart_Drv_HandleHeaderDone(uint8 InstanceId);
static void Uart_Drv_HandleRespDone(uint8 InstanceId);
static void Uart_Drv_HandleRspErr(uint8 InstanceId);
static Uart_Drv_TransferStateType
Uart_Drv_MasterGetStatusAfterHeader(const uint8                InstanceId,
                                        Uart_Drv_NodeStateType NodeState);
static Uart_Drv_TransferStateType 
Uart_Drv_GetStatusWhenFrameError(const uint8 InstanceId);
static Uart_Drv_TransferStateType
Uart_Drv_GetStatusWhenNoEvent(Uart_Drv_NodeStateType NodeState);
static Uart_Drv_TransferStateType
Uart_Drv_GetStatusWhenReadbackError(const uint8 InstanceId);
static Uart_Drv_TransferStateType
Uart_Drv_GetStatusWhenTimeoutError(const uint8 InstanceId);
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
static void Uart_Drv_ReceiveSlavePid(uint8 InstanceId, uint8 Data);
static void Uart_Drv_ReceiveSlaveSync(uint8 InstanceId, uint8 Data);
#ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
static boolean Uart_Drv_ResetBaudrate(uint8 InstanceId, uint32 AdjustBaud);
#endif
#endif
/*SWS_Lin_00027*/
static void Uart_Drv_ReceiveOverrunError(const uint8 InstanceId);
static void Uart_Drv_CheckWakeupSignal(const uint8 InstanceId, const uint8 TmpByte);
static void Uart_Drv_FrameErrorIrqHandler(const uint8 InstanceId);
static void Uart_Drv_ReadbackResponseData(const uint8 InstanceId, uint8 DataByte);
static void Uart_Drv_FrameTransceiverIrqHandler(const uint8 InstanceId);
static void Uart_Drv_LineStatusIrqHandler(const uint8 InstanceId);
static void Uart_Drv_HandleHeaderDoneIrq(uint8 InstanceId);

#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
static void Uart_Drv_HandleSwSlaveTxResponseDone(uint8 InstanceId);
#endif

static void Uart_Drv_HandleResponseDoneIrq(uint8 InstanceId);  
static Uart_Drv_TransferStateType Uart_Drv_GetStatusWhenError(const uint8 InstanceId);
static void Uart_Drv_ResetRxFifo(uint8 InstanceId);
static void Uart_Drv_ResetTxFifo(uint8 InstanceId);
static void Uart_Drv_SendHeader(uint8          InstanceId,
                                         const Uart_Drv_PduType *PduInfoPtr);
static void Uart_Drv_IntHandlerWakeupSignal(uint8 InstanceId);
static void Uart_Drv_IntHandlerLineStatus(uint8 InstanceId);
static void Uart_Drv_IntHandlerHeaderDone(uint8 InstanceId);
static void Uart_Drv_IntHandlerResponseDone(uint8 InstanceId);
#if (STD_ON == UART_DRV_SOFTWARE_POLLING )
static void Uart_Drv_PollingHandlerWakeupSignal(uint8 InstanceId);
static void Uart_Drv_PollingHandlerLineStatus(uint8 InstanceId);
static void Uart_Drv_PollingHandlerHeaderDone(uint8 InstanceId);
static void Uart_Drv_PollingHandlerResponseDone(uint8 InstanceId);
#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
/**
 *
 * @brief      Clear lin transmission status.
 *
 * @param[in]  InstanceId:  Select the UART port.
 *
 * @return     none
 *
 */
static void Uart_Drv_ClearTransmission(uint8 InstanceId)
{
    Reg_Uart_BfType *UartBfPtr = Uart_Drv_UartRegBfPtr[InstanceId];
    /* response operation start/ header operation start */
    uint32 RspOpStart    = UartBfPtr->UART_LIN_CTL.RSP_OP_START;
    uint32 HeaderOpStart = UartBfPtr->UART_LIN_CTL.HEADER_OP_START;
    if ((RspOpStart != 0U) || (HeaderOpStart != 0U))
    {
        SchM_Enter_Lin_UartLinControlReg();        
        UartBfPtr->UART_LIN_CTL.RSP_OP_START = 0U;
        UartBfPtr->UART_LIN_CTL.HEADER_OP_START = 0U;        
        SchM_Exit_Lin_UartLinControlReg();        
    }
    else
    {
        /* Nothing to do */
    }
}

/**
 *
 * @brief      Mask/Unmask the UART interrupt.
 *
 * @param[in]  InstanceId:  Select the UART port.
 * @param[in]  IntType:  Specifies the interrupt type.
 * @param[in]  IntMask:  Enable/Disable Specified interrupt type.
 *
 * @return     None
 *
 */
static void Uart_Drv_EnableInterrupts(uint8 InstanceId, Uart_Drv_IntType IntType,
                                                 boolean IntMask)
{
    Reg_Uart_WType *UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];

    SchM_Enter_Lin_IntOperation();    
    if (0x1U == IntMask )
    {
        UartWPtr->UART_DLH_IER.UART_IER |= (Uart_Drv_InterruptMaskArray[IntType]);
    }
    else
    {
        UartWPtr->UART_DLH_IER.UART_IER &= (~(Uart_Drv_InterruptMaskArray[IntType]));
    }    
    SchM_Exit_Lin_IntOperation();
}

/**
 *
 * @brief      Get all Line Status.
 *
 * @param[in]  InstanceId:  Select the UART port.
 *
 * @return     The state value of UART Line Status register.
 *
 */
static uint32 Uart_Drv_GetAllLineStatus(uint8 InstanceId)
{
    const Reg_Uart_WType *UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];

    uint32 Ret;

    Ret = (uint32)UartWPtr->UART_LSR & (uint32)0xFFFF;

    return Ret;
}

/**
 *
 * @brief      Send one byte data to the UART peripheral.
 *
 * @param[in]  InstanceId:  Select the UART port.
 * @param[in]  Data[]:  The data to be send.
 * @param[in]  Len:  length.
 *
 * @return     None
 *
 */
static void Uart_Drv_SendBytes(uint8 InstanceId, const uint8 Data[], uint8 Len)
{
    Reg_Uart_WType *UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];
    uint32 Cnt;    
    for (Cnt = 0U; Cnt < Len; Cnt++)
    {
        UartWPtr->UART_RBR_THR_DLL.UART_THR = Data[Cnt];
    }    
    
}

/**
 *
 * @brief      Receive one byte data from the UART peripheral.
 *
 * @param[in]  InstanceId:  Select the UART port.
 *
 * @return     The received data.
 *
 */
static uint8 Uart_Drv_ReceiveByte(uint8 InstanceId)
{
    const Reg_Uart_BfType *UartBfPtr = Uart_Drv_UartRegBfPtr[InstanceId];
    /* Receive data */
    return (uint8)(UartBfPtr->UART_RBR_THR_DLL.UART_RBR.RBR_LSB);
}

/**
 *
 * @brief      Read received bytes from the RX FIFO.
 * @param[in]  InstanceId:  Select the UART port.
 * @param[in]  Length:  the number of bytes to be read. When call this function,
 *                      the user needs to make sure that the "length" is not
 *                      greater than the number of bytes that is available in
 *                      RX FIFO.
 * @param[out]  Data:  points to the memory where the data to be stored.
 *
 * @return     None
 *
 */
static void Uart_Drv_ReceiveBytes(uint8 InstanceId, uint32 Length, uint8 Data[])
{
    const Reg_Uart_BfType *UartBfPtr = Uart_Drv_UartRegBfPtr[InstanceId];
    uint32 Count;
    for (Count = 0U; Count < Length; Count++)
    {
        Data[Count] = (uint8)UartBfPtr->UART_RBR_THR_DLL.UART_RBR.RBR_LSB;
    }
}

/**
 *
 * @brief      Enable fifo.
 *
 * @param[in]  InstanceId:  Select the UART port.
 *
 * @return     None
 *
 */
static void Uart_Drv_EnableFifo(uint8 InstanceId)
{
    Reg_Uart_WType *UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];
    SchM_Enter_Lin_FifoOperation();    
    Uart_Drv_FifoBufArray[InstanceId] |= UART_DRV_ENABLE_FIFO;
    UartWPtr->UART_IIR_FCR.UART_FCR = Uart_Drv_FifoBufArray[InstanceId];    
    SchM_Exit_Lin_FifoOperation();
}

/**
 *
 * @brief      Disable fifo.
 *
 * @param[in]  InstanceId:  Select the UART port.
 *
 * @return     None
 *
 */
static void Uart_Drv_DisableFifo(uint8 InstanceId)
{
    Reg_Uart_WType *UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];

    SchM_Enter_Lin_FifoOperation();    
    Uart_Drv_FifoBufArray[InstanceId] &= ~UART_DRV_ENABLE_FIFO;
    UartWPtr->UART_IIR_FCR.UART_FCR = Uart_Drv_FifoBufArray[InstanceId];    
    SchM_Exit_Lin_FifoOperation();
}

/**
 *
 * @brief      Reset uart receive fifo.
 *
 * @param[in]  InstanceId:  Select the UART port.
 *
 * @return     None
 *
 */
static void Uart_Drv_ResetRxFifo(uint8 InstanceId)
{
    Reg_Uart_WType *UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];
    SchM_Enter_Lin_FifoOperation();    
    Uart_Drv_FifoBufArray[InstanceId] |= UART_DRV_RESET_RX_FIFO;
    UartWPtr->UART_IIR_FCR.UART_FCR = Uart_Drv_FifoBufArray[InstanceId];
    Uart_Drv_FifoBufArray[InstanceId] &= (~UART_DRV_RESET_RX_FIFO);    
    SchM_Exit_Lin_FifoOperation();
}

/**
 *
 * @brief      Reset uart tx fifo.
 *
 * @param[in]  InstanceId:  Select the UART port.
 *
 * @return     None
 *
 */
static void Uart_Drv_ResetTxFifo(uint8 InstanceId)
{
    Reg_Uart_WType *UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];
    SchM_Enter_Lin_FifoOperation();    
    Uart_Drv_FifoBufArray[InstanceId] |= UART_DRV_RESET_TX_FIFO;
    UartWPtr->UART_IIR_FCR.UART_FCR = Uart_Drv_FifoBufArray[InstanceId];
    Uart_Drv_FifoBufArray[InstanceId] &= (~UART_DRV_RESET_TX_FIFO);    
    SchM_Exit_Lin_FifoOperation();
}

/**
 * 
 * @brief      Get busy status.
 *
 * @param[in]  InstanceId:  UART peripheral selected.
 *
 * @return    boolean
 * @retval    - TRUE: Load complete
 * @retval    - FALSE:load fail
 *
 */
static boolean Uart_Drv_GetBusyStatus(uint8 InstanceId)
{
    const Reg_Uart_BfType *UartBfPtr = Uart_Drv_UartRegBfPtr[InstanceId];

    return (UartBfPtr->UART_USR.BUSY != 0U) ? TRUE : FALSE;
}

/**
 * 
 * @brief      Wait UART busy clear.
 *
 * @param[in]  InstanceId:  UART peripheral selected.
 *
 * @return    boolean
 * @retval    - TRUE: Busy state clear
 * @retval    - FALSE:Busy state set
 *
 */
static boolean Uart_Drv_WaitBusyClear(uint8 InstanceId)
{

    boolean Ret          = (boolean)FALSE;
    uint32  TimeoutTicks = 0u;
    uint32  CurrentTicks;
    uint32  ElapsedTicks = 0u;

    uint32 TotalElapsedTicks = 0u;
    (void)McalLib_GetCounterValue(UART_DRV_TIMEOUT_TYPE, &CurrentTicks);
    TimeoutTicks =
        McalLib_MicroSecToTicks(UART_DRV_TIMEOUT_TYPE, UART_DRV_TIMEOUT_VALUE_US) ;

    while (TotalElapsedTicks <= TimeoutTicks)
    {
        if (FALSE == Uart_Drv_GetBusyStatus(InstanceId))
        {
            Ret = (boolean)TRUE;
            break;
        }
        else
        {
            (void)Uart_Drv_ReceiveByte(InstanceId);
            Uart_Drv_ResetTxFifo(InstanceId);
        }

        (void)McalLib_GetElapsedValue(UART_DRV_TIMEOUT_TYPE, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
    }

    return Ret;
}

/**
 *
 * @brief      Wait wakeup signal flag clear.
 *
 * @param[in]  InstanceId:  UART peripheral selected.
 * @param[in]  WakeupByte: length.
 *
 * @return    boolean
 * @retval    - TRUE: break state clear
 * @retval    - FALSE:break state set
 *
 */
static boolean Uart_Drv_WaitBreakFlagClear(uint8 InstanceId)
{
    const Reg_Uart_BfType *UartBfPtr = Uart_Drv_UartRegBfPtr[InstanceId];
    
    boolean Ret          = (boolean)FALSE;
    uint32  TimeoutTicks = 0u;
    uint32  CurrentTicks;
    uint32  ElapsedTicks = 0u;

    uint32 TotalElapsedTicks = 0u;
    (void)McalLib_GetCounterValue(UART_DRV_TIMEOUT_TYPE, &CurrentTicks);
    TimeoutTicks =
        McalLib_MicroSecToTicks(UART_DRV_TIMEOUT_TYPE, UART_DRV_TIMEOUT_VALUE_US) ;

    while (TotalElapsedTicks <= TimeoutTicks)
    {
        if (0U == UartBfPtr->UART_LCR.BC)
        {
            Ret = (boolean)TRUE;
            break;
        }
        else
        {
            /* nothing to do */
        }

        (void)McalLib_GetElapsedValue(UART_DRV_TIMEOUT_TYPE, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
    }

    return Ret;
    
}

/**
 *
 * @brief      Send wake up signal.
 *
 * @param[in]  InstanceId:  UART peripheral selected.
 * @param[in]  WakeupByte: length.
 *
 * @return    boolean
 * @retval    - TRUE: send wakeup up signal successfully
 * @retval    - FALSE: some error
 *
 */
static boolean Uart_Drv_SendWakeupSignal(uint8 InstanceId, uint32 WakeupByte)
{
    Reg_Uart_BfType *UartBfPtr = Uart_Drv_UartRegBfPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    boolean Ret = FALSE;

    if (WakeupByte < 0x0BU)
    {
        /*Nothing to do*/
    }
    else
    {   
        if(TRUE == Uart_Drv_WaitBusyClear(InstanceId))
        {
            SchM_Enter_Lin_UartLcr();
            UartBfPtr->UART_LCR.LBKM  = (uint32)WakeupByte - 0xBU;
            UartBfPtr->UART_LCR.LBKEN = 0x1U;
            /* send break characters */
            UartBfPtr->UART_LCR.BC = 0x1U;
            SchM_Exit_Lin_UartLcr();
            if(TRUE == Uart_Drv_WaitBreakFlagClear(InstanceId))
            {
                SchM_Enter_Lin_UartLcr();
                /* break length */
                UartBfPtr->UART_LCR.LBKM = UART_DRV_BREAKLEN((ConfigPtr->BreakLen));
                SchM_Exit_Lin_UartLcr();
                Ret = TRUE;
            }
            
        }
        else
        {
            /* Nothing to do */
        }
        
    }

    return Ret;
}

/**
 *
 * @brief       It checks the parity bits or computes the parity bits.
 *
 * @param[in]   Pid: PID byte in case of checking parity bits or ID byte in case of making parity
 *              bits.
 * @param[in]   ParityType: 1 for Checking parity bits, 0 for making parity bits
 *
 * @return uint8 -   Value has 8 bit:
 * @retval 0xFF :    Parity bits are incorrect,
 * @retval Other   : Checking parity bits are correct,return PID.
 *
 */
uint8 Uart_Drv_ParityCalc(const uint8 Pid, const Uart_Drv_ParityType ParityType)
{
    uint8  Ret = 0xFFU;
    uint32 Temp0;
    uint32 Temp1;
    uint32 TempPid;

    Temp0 = (uint32)Pid & (uint32)UART_DRV_LIN_FRAME_ID_MASK;
    
    Temp1 = (uint32)Pid & (uint32)UART_DRV_LIN_FRAME_ID_MASK;
    
    Temp1 = ~((((Temp1 >> 1U) &((uint32)0x1U)) ^((Temp1 >> 3U) & ((uint32)0x1U)) \
    ^ ((Temp1 >> 4U) & ((uint32)0x1U)) ^ ((Temp1 >> 5U) ) ));

    Temp0 = (Temp0 & ((uint32)0x1U)) ^((Temp0 >> 1U) & ((uint32)0x1U)) ^ \
      ((Temp0 >> 2U) & ((uint32)0x1U)) ^ ((Temp0 >> 4U) & ((uint32)0x1U) );
      
    TempPid = ((Temp1 <<(uint32)7U) & 0x80U) | (Temp0 << (uint32)6U)  |
             ((uint32)Pid & (uint32)UART_DRV_LIN_FRAME_ID_MASK);

    if (UART_DRV_SOFTWARE_CHECK_PARITY == ParityType)
    {
        if (Pid == TempPid)
        {
            Ret = Pid;
        }
        else
        {
            Ret = 0xFFU;
        }
    }
    else
    {
        Ret = (uint8)TempPid;
    }
      
    return Ret;
}

/**
 *
 * @brief       Calculate protected identifier of frame.
 *
 * @param[in]   BufferPtr: Data.
 * @param[in]   SizeBuffer: Size of data.
 * @param[in]   Pid: pid.
 *
 * @return      checksum value
 *
 */
static uint8 Uart_Drv_ChecksumCalc(const uint8 *BufferPtr, const uint8 SizeBuffer,
                                       const uint8 Pid)
{
    uint8  Length;
    uint16 TempChecksum = 0U;
    uint8 Ret; 
    /* For PID is 0x3C (ID 0x3C) or 0x7D (ID 0x3D) or 0xFE (ID 0x3E) or 0xBF (ID 0x3F)
     * apply classic checksum and apply enhanced checksum for other PID */
    if ((0x3CU != Pid) && (0x7DU != Pid) && (0xFEU != Pid) && (0xBFU != Pid))
    {
        /* For PID other than 0x3C, 0x7D, 0xFE and 0xBF: Add PID in checksum calculation */
        TempChecksum = Pid;
    }
    else
    {
        TempChecksum = 0U;
    }
    for (Length = 0U; Length < SizeBuffer; Length++)
    {
        TempChecksum += BufferPtr[Length];
        if (TempChecksum > 0xFFU)
        {
            TempChecksum -= 0xFFU;
        }
    }
    Ret = (uint8)(~TempChecksum);
    /* Return reversed checksum */
    return Ret;
}

/**
 *
 * @brief       Slave process response.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   PduInfoPtr: Pointer to PDU containing the PID, checksum model, response
 *              type, Dl and SDU data pointer.
 *
 * @return      None
 *
 */
static void Uart_Drv_ProcessResponse(uint8 InstanceId,const Uart_Drv_PduType *PduInfoPtr)
{   
    uint8 Index;
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    Reg_Uart_BfType                 *UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];



#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
if(UART_DRV_FRAMERESPONSE_TX == PduInfoPtr->Drc)
{
    UartBfPtr->UART_LIN_PID_VALUE.PID = PduInfoPtr->Pid & 0x3FU;
    UartBfPtr->UART_LIN_CTL.LIN_MODE = 0U;
    UartBfPtr->UART_LIN_CTL.MASTER_MODE = 0U;   
}
else
{
    UartBfPtr->UART_LIN_PID_VALUE.PID = PduInfoPtr->Pid & 0x3FU;
    UartBfPtr->UART_LIN_CTL.LIN_MODE = 1U;
    UartBfPtr->UART_LIN_CTL.MASTER_MODE = 0U;   
}
#endif
    if (UART_DRV_FRAMERESPONSE_TX == PduInfoPtr->Drc)
    {
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
        /* Copy data to buffer */
        for (Index = 0U; Index < PduInfoPtr->Dl; Index++)
        {
            Uart_Drv_SduBufferArray[InstanceId][Index] = PduInfoPtr->SduPtr[Index];
        }
        if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
        {
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, TRUE);
        }
        else
        {
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        ((Uart_Drv_PollingMaskArray[UART_DRV_INT_RBFI]));
        }
        SchM_Enter_Lin_GlobalChecksum();
        CrtTransferCfgPtr->Checksum =
        (UART_DRV_CLASSIC_CS == PduInfoPtr->Cs) ? 0x00U : PduInfoPtr->Pid;
        CrtTransferCfgPtr->Checksum = Uart_Drv_ChecksumCalc(PduInfoPtr->SduPtr, PduInfoPtr->Dl,
                                                                CrtTransferCfgPtr->Checksum);
        SchM_Exit_Lin_GlobalChecksum();
        CrtTransferCfgPtr->TxBuff = &Uart_Drv_SduBufferArray[InstanceId][0U];
        CrtTransferCfgPtr->TxSize = PduInfoPtr->Dl + 1U;
        CrtTransferCfgPtr->RxSize = 0U;     
        CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SEND_RESPONSE;
        CrtTransferCfgPtr->IsBusBusy        = (boolean)TRUE;
        Uart_Drv_DisableFifo(InstanceId);
    #if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    #ifdef UART_DRV_SIMULATION_SLAVE_START_TIMEOUT_NOTIFY
        UART_DRV_SIMULATION_SLAVE_START_TIMEOUT_NOTIFY(InstanceId,
        Uart_Drv_ConfigArrayPtr[InstanceId]->ResponseTimeoutValue*(CrtTransferCfgPtr->TxSize),
        UART_DRV_EVENT_SEND_RESPONSE);
    #endif
#endif
#endif
        CrtTransferCfgPtr->CntByte = 0U;
        Uart_Drv_SendBytes(InstanceId,CrtTransferCfgPtr->TxBuff,(uint8) 1U);
#else
        /* Copy data to buffer */
        for (Index = 0U; Index < PduInfoPtr->Dl; Index++)
        {
            Uart_Drv_SduBufferArray[InstanceId][Index] = PduInfoPtr->SduPtr[Index];
        }
        if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
        {
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RSP_DONE, TRUE);
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, TRUE);
        }
        else
        {
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        ((Uart_Drv_PollingMaskArray[UART_DRV_POLL_RSP_DONE]));
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        ((Uart_Drv_PollingMaskArray[UART_DRV_INT_RBFI]));
        }
        SchM_Enter_Lin_GlobalChecksum();
        CrtTransferCfgPtr->Checksum =
        (UART_DRV_CLASSIC_CS == PduInfoPtr->Cs) ? 0x00U : PduInfoPtr->Pid;
        CrtTransferCfgPtr->Checksum = Uart_Drv_ChecksumCalc(PduInfoPtr->SduPtr, PduInfoPtr->Dl,
                                                                CrtTransferCfgPtr->Checksum);
        SchM_Exit_Lin_GlobalChecksum();
        CrtTransferCfgPtr->TxBuff = &Uart_Drv_SduBufferArray[InstanceId][0U];
        CrtTransferCfgPtr->TxSize = PduInfoPtr->Dl + 1U;
        CrtTransferCfgPtr->RxSize = 0U;       
        SchM_Enter_Lin_UartChecksumReg();
        UartBfPtr->UART_LIN_CHECKSUM.CHECKSUM_TYPE = (uint8)PduInfoPtr->Cs;
        SchM_Exit_Lin_UartChecksumReg();

        CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SEND_RESPONSE;
        CrtTransferCfgPtr->IsBusBusy        = (boolean)TRUE;
            
        Uart_Drv_ClearTransmission(InstanceId);
        /* enable fifo  */
        Uart_Drv_EnableFifo(InstanceId);
        Uart_Drv_ResetTxFifo(InstanceId);
        if(TRUE == Uart_Drv_GetBusyStatus(InstanceId))
        {
            Uart_Drv_ResetTxFifo(InstanceId);
        }
        SchM_Enter_Lin_UartLinRspLenReg(); 
        UartBfPtr->UART_LIN_RSP_LENGTH.RSP_LENGTH = PduInfoPtr->Dl;
        SchM_Exit_Lin_UartLinRspLenReg(); 
#if (STD_OFF == UART_DRV_SOFTWARE_SIMULATION)
        Uart_Drv_SendBytes(InstanceId,Uart_Drv_SduBufferArray[InstanceId],(uint8) PduInfoPtr->Dl);
#else
        Uart_Drv_SendBytes(InstanceId,CrtTransferCfgPtr->TxBuff,(uint8) 1U);
#endif
        SchM_Enter_Lin_UartLinControlReg();       
          
        /* tx response */
        UartBfPtr->UART_LIN_CTL.RSP_DIR = 1U; 
        /* start send responses */
        UartBfPtr->UART_LIN_CTL.RSP_OP_START = 1U;          
        SchM_Exit_Lin_UartLinControlReg();
        CrtTransferCfgPtr->CntByte = 0U;
#endif
    }
    else if (UART_DRV_FRAMERESPONSE_RX == PduInfoPtr->Drc)
    {

        if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
        {
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RSP_DONE, TRUE);
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, FALSE);
        }
        else
        {
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        ((Uart_Drv_PollingMaskArray[UART_DRV_POLL_RSP_DONE]));
            Uart_Drv_PollingFlagArray[InstanceId] &= 
                        (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]));
        }
        /* Clear rx buffer */
        for (Index = 0U; Index < UART_DRV_LIN_MAX_DATA_LENGTH; Index++)
        {
            Uart_Drv_SduBufferArray[InstanceId][Index] = 0U;
        }
        CrtTransferCfgPtr->TxSize = 0U;
        CrtTransferCfgPtr->RxSize = PduInfoPtr->Dl + 1U;
        SchM_Enter_Lin_UartChecksumReg();
        UartBfPtr->UART_LIN_CHECKSUM.CHECKSUM_TYPE = (uint32)PduInfoPtr->Cs;
        SchM_Exit_Lin_UartChecksumReg();

        CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_RECV_RESPONSE;
        CrtTransferCfgPtr->IsBusBusy        = (boolean)TRUE;
            
        Uart_Drv_ClearTransmission(InstanceId);
        /******************************/
        
        Uart_Drv_EnableFifo(InstanceId);
        Uart_Drv_ResetRxFifo(InstanceId);
        SchM_Enter_Lin_UartLinRspLenReg(); 
        UartBfPtr->UART_LIN_RSP_LENGTH.RSP_LENGTH = PduInfoPtr->Dl;
        SchM_Exit_Lin_UartLinRspLenReg(); 
        SchM_Enter_Lin_UartLinControlReg(); 
        UartBfPtr->UART_LIN_CTL.RSP_DIR = 0U;
        UartBfPtr->UART_LIN_CTL.RSP_OP_START = 1U;
        SchM_Exit_Lin_UartLinControlReg();
        CrtTransferCfgPtr->CntByte = 0U;
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
    #if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
        #ifdef UART_DRV_SIMULATION_SLAVE_START_TIMEOUT_NOTIFY
            UART_DRV_SIMULATION_SLAVE_START_TIMEOUT_NOTIFY(InstanceId,
            Uart_Drv_ConfigArrayPtr[InstanceId]->ResponseTimeoutValue*(CrtTransferCfgPtr->RxSize),
            UART_DRV_EVENT_RECEIVE_RESPONSE);
        #endif
    #endif
#endif

    }
    else
    {
        CrtTransferCfgPtr->TxSize = 0U;
        CrtTransferCfgPtr->RxSize = 0U;
        Uart_Drv_SetIdleState(InstanceId);
        CrtTransferCfgPtr->CntByte = 0U;
    }
    
}

/**
 *
 * @brief       Only master will detect break.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
static void Uart_Drv_DetectBreak(uint8 InstanceId)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
    uint8 ErrorFlage= 0U;
#endif
    
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    #if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
    Reg_Uart_BfType *UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
    #endif
    if (UART_DRV_NODE_MASTER == ConfigPtr->NodeType)
    {
        (void)Uart_Drv_ReceiveByte(InstanceId);

        if (UART_DRV_NODE_STATE_SEND_BREAK_FIELD == CrtTransferCfgPtr->CurrentNodeState)
        {
            CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SEND_SYNC;
        }
    }
    else
    {
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
        
        (void)Uart_Drv_ReceiveByte(InstanceId);
        if (UART_DRV_NODE_STATE_IDLE != CrtTransferCfgPtr->CurrentNodeState)
        {
            #if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
                #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
                        UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
                #endif
            #endif
            if((UART_DRV_NODE_STATE_SEND_RESPONSE == CrtTransferCfgPtr->CurrentNodeState) ||
                         (UART_DRV_NODE_STATE_RECV_RESPONSE == CrtTransferCfgPtr->CurrentNodeState))
            {
                ErrorFlage = 1U;
                CrtTransferCfgPtr->CurrentEventId  = UART_DRV_EVENT_FRAME_ERROR;
                if (NULL_PTR != ConfigPtr->LinCallbackPtr)
                {
                    ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
                }
            }
            Uart_Drv_SetIdleState(InstanceId);
        }
        CrtTransferCfgPtr->IsBusBusy = TRUE;
        if (UART_DRV_NODE_STATE_IDLE == CrtTransferCfgPtr->CurrentNodeState)
        {
            CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_RECV_BREAK;
        }
        UartBfPtr->UART_LCR_EXT.DLS_E = 0x0U;   
    #ifdef UART_DRV_SLAVE_HEADER_TIMEOUT_NOTIFIY
        UART_DRV_SLAVE_HEADER_TIMEOUT_NOTIFIY(InstanceId);
    #endif
    #ifdef UART_DRV_SLAVE_START_AUTOSYNC_NOTIFY
        UART_DRV_SLAVE_START_AUTOSYNC_NOTIFY(InstanceId);
    #endif
if(0U == ErrorFlage)
{
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
#ifdef UART_DRV_SIMULATION_SLAVE_START_TIMEOUT_NOTIFY
            UART_DRV_SIMULATION_SLAVE_START_TIMEOUT_NOTIFY(InstanceId,ConfigPtr->HeaderTimer,
                                                            UART_DRV_EVENT_RECEIVE_HEADER);
#endif
#endif
}
#endif
    }
}

#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
/**
 *
 * @brief       Slave reset baudrate.
 *
 * @param[in]    InstanceId: LIN channel to be addressed.
 * @param[in]    AdjustBaud: new baudrate
 *
 * @return    boolean
 * @retval    - TRUE: reset baudrate successfully
 * @retval    - FALSE: reset baudrate error
 *
 */
#ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
static boolean Uart_Drv_ResetBaudrate(uint8 InstanceId, uint32 AdjustBaud)
{
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    Reg_Uart_BfType *UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
    uint32 IntegerDiv; 
    uint32 FractionalDiv;
    boolean Ret = TRUE;

    if(TRUE == Uart_Drv_WaitBusyClear(InstanceId))
    {
        /* Enable DLAB to set baud rate */
        UartBfPtr->UART_LCR.DLAB = 0x01U;
        /* get integer baudrate divisor*/
        IntegerDiv = (ConfigPtr->ChannelClock)/(16U * AdjustBaud);

        /* Config the DLL and DLH registers */
        UartBfPtr->UART_RBR_THR_DLL.UART_DLL.DL_L = IntegerDiv & 0xFFU;
        UartBfPtr->UART_DLH_IER.UART_DLH.DL_H = (IntegerDiv >> 0x08U)& 0xFFU;

        /* config fractional divisor */
        FractionalDiv = (ConfigPtr->ChannelClock)%(16U * AdjustBaud);
        FractionalDiv /= AdjustBaud;
        UartBfPtr->UART_FD.FD = FractionalDiv;

        /* Disable DLAB */
        UartBfPtr->UART_LCR.DLAB = 0x0U;
    }
    else
    {
        Ret = FALSE;
    }

    return Ret;
}
#endif
/**
 *
 * @brief       Slave has received break field and check sync field.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]    Data: receive sync field.
 *
 * @return      None
 *
 */
static void Uart_Drv_ReceiveSlaveSync(uint8 InstanceId, uint8 Data)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
#ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
    boolean SyncFlag = FALSE;
    boolean Ret= TRUE;
#endif
    
#ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
    uint32 Baudrate = 0U;
#endif

    if (0x55U == Data)
    {
        CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_RECV_SYNC;
        #ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
        UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY(InstanceId, &SyncFlag, &Baudrate);
        if((TRUE == SyncFlag) && (0U == Uart_Drv_BaudRateAutoSyncFlag[InstanceId]))
        {
            Ret = Uart_Drv_ResetBaudrate(InstanceId, Baudrate);
            if(TRUE == Ret)
            {
                Uart_Drv_BaudRateAutoSyncFlag[InstanceId] = 1U;
            }
        }
        #endif
    }
    else
    {
        #if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
            #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
                    UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
            #endif
    #endif
        #ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
        UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY(InstanceId, &SyncFlag, &Baudrate);
        if(FALSE == SyncFlag)
        #endif
        {
            CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_RECV_HEADER_ERR;
            Uart_Drv_SetIdleState(InstanceId);

            if (NULL_PTR != ConfigPtr->LinCallbackPtr)
            {
                ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
            }
        }
        #ifdef UART_DRV_SLAVE_STOP_AUTOSYNC_NOTIFY
        else
        {
                Ret = Uart_Drv_ResetBaudrate(InstanceId, Baudrate);
                if(TRUE == Ret)
                {
                    Uart_Drv_BaudRateAutoSyncFlag[InstanceId] = 1U;
                }
                CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_RECV_HEADER_ERR;
                Uart_Drv_SetIdleState(InstanceId);

                if (NULL_PTR != ConfigPtr->LinCallbackPtr)
                {
                    ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
                }
 
        }
        #endif

    }
}

/**
 *
 * @brief       Slave check pid and prepare response.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]    Data: receive sync field.
 *
 * @return      None
 *
 */
static void Uart_Drv_ReceiveSlavePid(uint8 InstanceId, uint8 Data)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];

    /* Check the received PID */
    CrtTransferCfgPtr->CurrentPid = Uart_Drv_ParityCalc(Data, UART_DRV_SOFTWARE_CHECK_PARITY);
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
            UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
    #endif
#endif

    if (0xFFU != CrtTransferCfgPtr->CurrentPid)
    {
        /* slave receive header successfully */
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_RECV_HEADER_OK;
        CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_RECV_HEADER;
        CrtTransferCfgPtr->IsBusBusy = FALSE;
        /*********************CHANGE TO LIN MODE*******************************/

        if (NULL_PTR != ConfigPtr->LinCallbackPtr)
        {
            ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
        }
    }
    else
    {
        /* header error: pid error*/
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_RECV_HEADER_ERR;
        Uart_Drv_SetIdleState(InstanceId);
        if (NULL_PTR != ConfigPtr->LinCallbackPtr)
        {
            ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
        }
    }

}

#endif

#if(STD_OFF == UART_DRV_SOFTWARE_SIMULATION)

#if (STD_ON == UART_DRV_MASTER_SUPPORT)

/**
 *
 * @brief       Master check readback sync field and prepare send pid.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]    Data: receive sync field.
 *
 * @return      None
 *
 */
/* SWS_Lin_00240 */
static void Uart_Drv_ReadbackMasterSync(uint8 InstanceId, uint8 Data)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];

    if (0x55U == Data)
    {
        CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SEND_PID;
    }
    else
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_READBACK_ERROR;

        Uart_Drv_SetIdleState(InstanceId);

        if (NULL_PTR != ConfigPtr->LinCallbackPtr)
        {
            ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
        }
    }
}

/**
 *
 * @brief       Master check readback pid  and prepare response.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   Data: receive sync field.
 *
 * @return      None
 *
 */
/* SWS_Lin_00240 */
static void Uart_Drv_ReadbackMasterPid(uint8 InstanceId, uint8 Data)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];

    if (Data == CrtTransferCfgPtr->CurrentPid)
    {        
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_SEND_HEADER_OK;   
    }
    else
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_READBACK_ERROR;
        Uart_Drv_SetIdleState(InstanceId);
        if (NULL_PTR != ConfigPtr->LinCallbackPtr)
        {
            ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
        }
    }
}
#endif
#endif
/**
 *
 * @brief       Lin handle header done.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
static void Uart_Drv_HandleHeaderDone(uint8 InstanceId)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    Reg_Uart_BfType *UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
    
    if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
    {
        Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_HEADER_DONE, (boolean)FALSE);
    }
    else
    {
        Uart_Drv_PollingFlagArray[InstanceId] &= 
                        (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_HEADER_DONE]));
    }

    if(UART_DRV_NODE_MASTER == ConfigPtr->NodeType)
    {
        if( UART_DRV_EVENT_READBACK_ERROR != CrtTransferCfgPtr->CurrentEventId )
        {
            if (CrtTransferCfgPtr->TxSize > 0U)
            {
                if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
                {
                    Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RSP_DONE, (boolean)TRUE);
                }
                else
                {
                    Uart_Drv_PollingFlagArray[InstanceId] |= 
                        ((Uart_Drv_PollingMaskArray[UART_DRV_POLL_RSP_DONE]));
                }

                CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SEND_RESPONSE;

                Uart_Drv_ClearTransmission(InstanceId);
                /* enable fifo  */
                Uart_Drv_EnableFifo(InstanceId);
                Uart_Drv_ResetTxFifo(InstanceId);
                if(TRUE == Uart_Drv_GetBusyStatus(InstanceId))
                {
                    Uart_Drv_ResetTxFifo(InstanceId);
                }
                UartBfPtr->UART_LIN_RSP_LENGTH.RSP_LENGTH = 
                                                           (uint32)CrtTransferCfgPtr->TxSize - 0x1U;

                Uart_Drv_SendBytes(InstanceId, Uart_Drv_SduBufferArray[InstanceId], 
                                               (CrtTransferCfgPtr->TxSize - 1U));

                /* interrupt operation */            
                /* tx response */
                UartBfPtr->UART_LIN_CTL.RSP_DIR = 1U;
                /* start send responses */
                UartBfPtr->UART_LIN_CTL.RSP_OP_START = 1U;
                        
            }
            else if (CrtTransferCfgPtr->RxSize > 0U)
            {
                CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_RECV_RESPONSE;
                if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
                {
                    Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, (boolean)FALSE);
                    Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RSP_DONE, (boolean)TRUE);
                }
                else
                {
                    Uart_Drv_PollingFlagArray[InstanceId] &= 
                        (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]));
                    Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_RSP_DONE]);
                }
                Uart_Drv_ClearTransmission(InstanceId);
                Uart_Drv_EnableFifo(InstanceId);
                Uart_Drv_ResetRxFifo(InstanceId);
                
                /* interrupt operation */
                UartBfPtr->UART_LIN_RSP_LENGTH.RSP_LENGTH = 
                                     (uint32)CrtTransferCfgPtr->RxSize - 0x1U;
                UartBfPtr->UART_LIN_CTL.RSP_DIR = 0U;
                UartBfPtr->UART_LIN_CTL.RSP_OP_START = 1U;            
            }
            else
            {
                /* ignore the response */
                CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_TX_COMPLETED;
                /* Slave to slave frame, ignor data, master enter into idle state*/
                Uart_Drv_SetIdleState(InstanceId);
            }
        }
    }
    else if(UART_DRV_NODE_SLAVE == ConfigPtr->NodeType)
    {
#if (STD_OFF == UART_DRV_SOFTWARE_SIMULATION)
        CrtTransferCfgPtr->CurrentPid = UartBfPtr->UART_LIN_PID_VALUE.PID;    
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_RECV_HEADER_OK;
        CrtTransferCfgPtr->IsBusBusy = (boolean)FALSE;
        Uart_Drv_ResetRxFifo(InstanceId);               
#endif
    }
    else
    {
        /* Nothing to do */
    }
}

/**
 *
 * @brief       Lin handle response done without error.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
static void Uart_Drv_HandleRespDone(uint8 InstanceId)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    /*if lin receive response*/
    if(CrtTransferCfgPtr->RxSize > 0U)
    {
      
        Uart_Drv_ReceiveBytes(InstanceId, ((uint32)CrtTransferCfgPtr->RxSize - 0x1U), 
                              Uart_Drv_SduBufferArray[InstanceId]);
        /****************note: checksum****************/
        CrtTransferCfgPtr->Checksum = Uart_Drv_ReceiveByte(InstanceId);
        CrtTransferCfgPtr->RxBuff = &Uart_Drv_SduBufferArray[InstanceId][0U];
        CrtTransferCfgPtr->CurrentEventId   = UART_DRV_EVENT_RX_COMPLETED;
    }
    else/*lin send response */
    {
        if(UART_DRV_EVENT_READBACK_ERROR != CrtTransferCfgPtr->CurrentEventId )
        {
            CrtTransferCfgPtr->CurrentEventId   = UART_DRV_EVENT_TX_COMPLETED;
        }

    }
    Uart_Drv_SetIdleState(InstanceId);
}

/**
 *
 * @brief       Lin handle response error.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
static void Uart_Drv_HandleRspErr(uint8 InstanceId)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];

    while(1U == (Uart_Drv_GetAllLineStatus(InstanceId) & UART_DRV_LSI_DR))
    {
        Uart_Drv_SduBufferArray[InstanceId][CrtTransferCfgPtr->CntByte] = 
                                                             Uart_Drv_ReceiveByte(InstanceId);
        CrtTransferCfgPtr->CntByte++;
    }
    if( 0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_TO_ERR))
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_TIMEOUT_ERROR;
    }
    else if(0U!= (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_CHECKSUM_ERR))
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_CHECKSUM_ERROR;        
    }
    else
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_FRAME_ERROR;
    }
    Uart_Drv_SetIdleState(InstanceId);
}

/**
 *
 * @brief       Get master current status after successfully send header.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   NodeState: Master status.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval      UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval      UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
static Uart_Drv_TransferStateType 
Uart_Drv_MasterGetStatusAfterHeader(const uint8 InstanceId,
                                                    Uart_Drv_NodeStateType NodeState)
{
    Uart_Drv_TransferStateType Ret = UART_DRV_STATE_NOT_OK;

    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];

    if ((UART_DRV_NODE_STATE_SEND_RESPONSE == NodeState) || (UART_DRV_NODE_STATE_SEND_PID == NodeState))
    {
        Ret = UART_DRV_STATE_TX_BUSY;
    }
    else if (UART_DRV_NODE_STATE_RECV_RESPONSE == NodeState)
    {
        if (CrtTransferCfgPtr->CntByte != 0U)
        {
            Ret = UART_DRV_STATE_RX_BUSY;
        }
        else
        {
            Ret = UART_DRV_STATE_RX_NO_RESPONSE;
        }
    }
    else
    {
        /*  Nothing to do*/
    }

    return Ret;
}

/**
 *
 * @brief       Get node status current status when overrun and frame error.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval      UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval      UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
static Uart_Drv_TransferStateType 
Uart_Drv_GetStatusWhenFrameError(const uint8 InstanceId)
{
    Uart_Drv_TransferStateType Ret = UART_DRV_STATE_NOT_OK;

    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];

    switch (CrtTransferCfgPtr->PreviousNodeState)
    {
        case UART_DRV_NODE_STATE_SEND_RESPONSE:
            Ret = UART_DRV_STATE_TX_ERROR;
            break;
        case UART_DRV_NODE_STATE_RECV_RESPONSE:
            Ret = UART_DRV_STATE_RX_ERROR;
            break;
        case UART_DRV_NODE_STATE_RECV_HEADER:
        case UART_DRV_NODE_STATE_RECV_BREAK:
        case UART_DRV_NODE_STATE_RECV_SYNC:
            Ret = UART_DRV_STATE_RX_HEADER_ERROR;
            break;
        case UART_DRV_NODE_STATE_SEND_SYNC:
        case UART_DRV_NODE_STATE_SEND_PID:
        case UART_DRV_NODE_STATE_SEND_BREAK_FIELD:
            Ret = UART_DRV_STATE_TX_HEADER_ERROR;
            break;
        default:
	        /*nothing to do*/
            break;
    }

    return Ret;
}

/**
 *
 * @brief       Get node status current status when overrun and frame error.
 *
 * @param[in]   NodeState: node status.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval      UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval     UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
static Uart_Drv_TransferStateType 
Uart_Drv_GetStatusWhenNoEvent(Uart_Drv_NodeStateType NodeState)
{
    Uart_Drv_TransferStateType Ret = UART_DRV_STATE_NOT_OK;
    switch (NodeState)
    {
        case UART_DRV_NODE_STATE_SEND_BREAK_FIELD:
        case UART_DRV_NODE_STATE_SEND_SYNC:
        case UART_DRV_NODE_STATE_SEND_PID:
            Ret = UART_DRV_STATE_TX_BUSY;
            break;

        case UART_DRV_NODE_STATE_IDLE:
            Ret = UART_DRV_STATE_OPERATIONAL;
            break;

        case UART_DRV_NODE_STATE_SLEEP_MODE:
            Ret = UART_DRV_STATE_SLEEP;
            break;

        default:
            Ret = UART_DRV_STATE_NOT_OK;
            break;
    }

    return Ret;
}

/**
 *
 * @brief       Get node status current status when receive timeout.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval      UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval      UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
static Uart_Drv_TransferStateType 
Uart_Drv_GetStatusWhenTimeoutError(const uint8 InstanceId)
{
    Uart_Drv_TransferStateType Ret = UART_DRV_STATE_NOT_OK;
    /* Get the current LIN state of this UART instance. */
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];

    switch (CrtTransferCfgPtr->PreviousNodeState)
    {
        /* If the node is RECEIVING DATA */
        case UART_DRV_NODE_STATE_RECV_RESPONSE:
            if ( CrtTransferCfgPtr->CntByte > 0U)
            {
                Ret = UART_DRV_STATE_RX_ERROR;
            }
            else
            {
                Ret = UART_DRV_STATE_RX_NO_RESPONSE;
            }
            break;

        case UART_DRV_NODE_STATE_RECV_HEADER:
        case UART_DRV_NODE_STATE_RECV_SYNC:
        case UART_DRV_NODE_STATE_RECV_BREAK:
            Ret = UART_DRV_STATE_RX_HEADER_ERROR;
            break;
        case UART_DRV_NODE_STATE_SEND_BREAK_FIELD:
        case UART_DRV_NODE_STATE_SEND_SYNC:
        case UART_DRV_NODE_STATE_SEND_PID:
            Ret = UART_DRV_STATE_TX_HEADER_ERROR;
            break;
            
        case UART_DRV_NODE_STATE_SEND_RESPONSE:
            Ret = UART_DRV_STATE_TX_ERROR;
            break;
        default:
	        /*nothing to do*/
            break;
    }

    return Ret;
}

/**
 *
 * @brief       Get node status current status when readback data error.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval      UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval     UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
static Uart_Drv_TransferStateType 
Uart_Drv_GetStatusWhenReadbackError(const uint8 InstanceId)
{
    Uart_Drv_TransferStateType Ret = UART_DRV_STATE_NOT_OK;
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];

    if (UART_DRV_NODE_STATE_SEND_RESPONSE == CrtTransferCfgPtr->PreviousNodeState)
    {
        Ret = UART_DRV_STATE_TX_ERROR;
    }
    else if ((UART_DRV_NODE_STATE_SEND_PID == CrtTransferCfgPtr->PreviousNodeState) ||
             (UART_DRV_NODE_STATE_SEND_SYNC == CrtTransferCfgPtr->PreviousNodeState))
    {
        Ret = UART_DRV_STATE_TX_HEADER_ERROR;
    }
    else
    {
        /*Nothing to do*/
    }

    return Ret;
}

/**
 *
 * @brief       Lin node receive overrun error.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
static void Uart_Drv_ReceiveOverrunError(const uint8 InstanceId)
{
    /* Get the current LIN state of this UART instance. */
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    (void)Uart_Drv_ReceiveByte(InstanceId);
    Uart_Drv_SetIdleState(InstanceId);

    CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_RX_OVERRUN_ERROR;

    if (NULL_PTR != ConfigPtr->LinCallbackPtr)
    {
        ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
    }
}

/**
 *
 * @brief       Check wakeup signal.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   TmpByte: receive data.
 *
 * @return      None
 *
 */
static void Uart_Drv_CheckWakeupSignal(const uint8 InstanceId, const uint8 TmpByte)
{
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
                            Uart_Drv_TransferConfigArrayPtr[InstanceId];
    uint8 Temp = Uart_Drv_WakeupDetectInvertArray[InstanceId] & TmpByte;

    if (0U == Temp)
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_WAKEUP_SIGNAL;

        if (FALSE == CrtTransferCfgPtr->IsBusBusy)
        {
            if (NULL_PTR != ConfigPtr->LinCallbackPtr)
            {
                ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
            }
            Uart_Drv_SetIdleState(InstanceId);          
        }
        else
        {
            Uart_Drv_SetIdleState(InstanceId);
        }
    }
    else
    {
        CrtTransferCfgPtr->IsBusBusy = (boolean)FALSE;
    }
}

/**
 *
 * @brief       Lin node receive frame error handlers.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
static void Uart_Drv_FrameErrorIrqHandler(const uint8 InstanceId)
{

    Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];

#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
    const Reg_Uart_BfType *UartBfPtr;  
    UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
    if(1U == UartBfPtr->UART_LCR_EXT.DLS_E)
    {
        (void)Uart_Drv_ReceiveByte(InstanceId);
    }
    else
    {
        if(UART_DRV_NODE_STATE_RECV_BREAK != CrtTransferCfgPtr->CurrentNodeState)
        {
            (void)Uart_Drv_ReceiveByte(InstanceId);
            Uart_Drv_SetIdleState(InstanceId);
            CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_FRAME_ERROR;
            if (NULL_PTR != ConfigPtr->LinCallbackPtr)
            {
                ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
            }
            
        }
        else
        {
            Uart_Drv_ReceiveSlaveSync(InstanceId,Uart_Drv_ReceiveByte(InstanceId));
        }
    }
#else
    (void)Uart_Drv_ReceiveByte(InstanceId);

    Uart_Drv_SetIdleState(InstanceId);
    CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_FRAME_ERROR;
    if (UART_DRV_NODE_SLAVE == ConfigPtr->NodeType)
    {
        if (NULL_PTR != ConfigPtr->LinCallbackPtr)
        {
            ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
        }
    }
#endif
}

/**
 *
 * @brief       Lin node send response data.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   DataByte: receive data.
 *
 * @return      None
 *
 */
/* SWS_Lin_00240,  */
static void Uart_Drv_ReadbackResponseData(const uint8 InstanceId, uint8 DataByte)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];   
    const Uart_Drv_ConfigType *ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];

    uint8   RestSize;
    boolean TmpCheckSumAndSize;
    boolean TmpBuffAndSize;
    RestSize = (uint8)(CrtTransferCfgPtr->TxSize - CrtTransferCfgPtr->CntByte);
    TmpCheckSumAndSize = (boolean)((1U == RestSize) && (CrtTransferCfgPtr->Checksum != DataByte));
    TmpBuffAndSize = (boolean)((DataByte != *CrtTransferCfgPtr->TxBuff) && (1U != RestSize));

    if ((TRUE == TmpBuffAndSize) || (TRUE == TmpCheckSumAndSize))
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_READBACK_ERROR;
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)

#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
                UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
    #endif
#endif

        Uart_Drv_ResetRxFifo(InstanceId);
        Uart_Drv_ResetTxFifo(InstanceId);
        Uart_Drv_DisableFifo(InstanceId);
#endif

        Uart_Drv_SetIdleState(InstanceId);

        if (NULL_PTR != ConfigPtr->LinCallbackPtr)
        {
            ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
        }
#if (STD_ON == UART_DRV_SOFTWARE_POLLING )
       /*when  rx and tx fifo internal data disorder and unable to automatically
         recover due to being interrupted for a long time while processing the 
         send response data program.*/
        Uart_Drv_ResetRxFifo(InstanceId);
        Uart_Drv_ResetTxFifo(InstanceId);
#endif

    }
    else
    {
        CrtTransferCfgPtr->TxBuff++;
        CrtTransferCfgPtr->CntByte++;
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)

    RestSize = (uint8)(CrtTransferCfgPtr->TxSize - CrtTransferCfgPtr->CntByte);
    if(RestSize > 1U)
    {
        Uart_Drv_SendBytes(InstanceId,CrtTransferCfgPtr->TxBuff,(uint8) 1U);
    }
    else if(1U == RestSize)
    {
        Uart_Drv_SendBytes(InstanceId,&CrtTransferCfgPtr->Checksum,(uint8) 1U);
    }
    else
    {
        Uart_Drv_HandleSwSlaveTxResponseDone(InstanceId);
    }

#endif


    }
}

/**
 *
 * @brief       Used for interrupt to send and receive frame.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
static void Uart_Drv_FrameTransceiverIrqHandler(const uint8 InstanceId)
{
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr =Uart_Drv_TransferConfigArrayPtr[InstanceId];
    uint8 Data =0U;
#if(STD_OFF == UART_DRV_SOFTWARE_SIMULATION)
    /*Distinguish sending and receiving two different situations because 
      readback error or receive response data empty will happen in Lin poll mode */
    if(CrtTransferCfgPtr->TxSize > 0U  )
    {
        Data =  Uart_Drv_ReceiveByte(InstanceId);
    }
        
    switch (CrtTransferCfgPtr->CurrentNodeState)
    {
#if (STD_ON == UART_DRV_MASTER_SUPPORT)
        case UART_DRV_NODE_STATE_SEND_SYNC:
            if(CrtTransferCfgPtr->TxSize > 0U )
            {
                Uart_Drv_ReadbackMasterSync(InstanceId, Data);
            }
            else
            {
                Uart_Drv_ReadbackMasterSync(InstanceId, Uart_Drv_ReceiveByte(InstanceId));
            }
            break;

        case UART_DRV_NODE_STATE_SEND_PID:
            if(CrtTransferCfgPtr->TxSize > 0U )
            {
                Uart_Drv_ReadbackMasterPid(InstanceId, Data);
            }
            else
            {
                Uart_Drv_ReadbackMasterPid(InstanceId, Uart_Drv_ReceiveByte(InstanceId));
            }
            break;
#endif
        case UART_DRV_NODE_STATE_SEND_RESPONSE:
            Uart_Drv_ReadbackResponseData(InstanceId, Data);
            break;
        default:
            if(0U == CrtTransferCfgPtr->TxSize  )
            {
                (void)Uart_Drv_ReceiveByte(InstanceId);
            }
            
            break;
    }
#else
    if(CrtTransferCfgPtr->TxSize > 0U  )
    {
        Data =  Uart_Drv_ReceiveByte(InstanceId);
    }
    switch (CrtTransferCfgPtr->CurrentNodeState)
    {
        case UART_DRV_NODE_STATE_SEND_RESPONSE:
            if(CrtTransferCfgPtr->TxSize > 0U )
            {
                Uart_Drv_ReadbackResponseData(InstanceId, Data);
            }
            else
            {
                Uart_Drv_ReadbackResponseData(InstanceId, Uart_Drv_ReceiveByte(InstanceId));
            }   
            break;
        case UART_DRV_NODE_STATE_RECV_BREAK:
            if(CrtTransferCfgPtr->TxSize > 0U )
            {
                Uart_Drv_ReceiveSlaveSync(InstanceId,Data);
            }
            else
            {
                Uart_Drv_ReceiveSlaveSync(InstanceId, Uart_Drv_ReceiveByte(InstanceId));
            }
            break;
        case UART_DRV_NODE_STATE_RECV_SYNC:
            if(CrtTransferCfgPtr->TxSize > 0U )
            {
                Uart_Drv_ReceiveSlavePid(InstanceId, Data);
            }
            else
            {
                Uart_Drv_ReceiveSlavePid(InstanceId, Uart_Drv_ReceiveByte(InstanceId));
            }
            break;
        default:
            if(0U == CrtTransferCfgPtr->TxSize  )
            {
               (void)Uart_Drv_ReceiveByte(InstanceId);
            }
            
            break;
    }
#endif

}

/**
 *
 * @brief       When lin eventId shows error will call this api.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @retval    Uart_Drv_TransferStateType.
 * @retval    UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval    UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval    UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval    UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval    UART_DRV_STATE_RX_HEADER_OK
 * @retval    UART_DRV_STATE_RX_HEADER_ERROR
 * @retval    UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval    UART_DRV_STATE_SLEEP: Sleep state operation,
 *              in this state wake-up detection from slave nodes is enabled;
 * @retval    UART_DRV_STATE_RX_HEADER_OK: Slave received a correct header;
 * @retval    UART_DRV_STATE_RX_HEADER_ERROR: Erroneous header reception of slave.
 *
 */
static Uart_Drv_TransferStateType Uart_Drv_GetStatusWhenError(const uint8 InstanceId)
{
    Uart_Drv_TransferStateType  Ret = UART_DRV_STATE_NOT_OK;
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];

    switch (CrtTransferCfgPtr->CurrentEventId)
    {
        case UART_DRV_EVENT_RX_OVERRUN_ERROR:
            /* fall-through */
        case UART_DRV_EVENT_FRAME_ERROR:
            /* Found cause of the error from header or reponse */
            Ret = Uart_Drv_GetStatusWhenFrameError(InstanceId);
            break;

        case UART_DRV_EVENT_TIMEOUT_ERROR:
            /* Call Uart_Drv_GetStatusWhenTimeoutError to get status from time out error event */
            Ret = Uart_Drv_GetStatusWhenTimeoutError(InstanceId);
            break;

        case UART_DRV_EVENT_READBACK_ERROR:
            /* Call Uart_Drv_GetStatusWhenReadbackError to get status from readback error event */
            Ret = Uart_Drv_GetStatusWhenReadbackError(InstanceId);
            break;

        case UART_DRV_EVENT_CHECKSUM_ERROR:
            /* Received checksum byte is incorrect */
            Ret = UART_DRV_STATE_RX_ERROR;
            break;

        default:
            Ret = UART_DRV_STATE_NOT_OK;
            break;
    }
    return Ret;
}

/**
 *
 * @brief      This function is used to handle master process and readback.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_LineStatusIrqHandler(const uint8 InstanceId)
{    
    /* line status: break interrupt and frame error bit set represent break*/
    if ((UART_DRV_LSI_BI | UART_DRV_LSI_FE) == (Uart_Drv_LineStatusBufArray[InstanceId] & 
                                                              (UART_DRV_LSI_BI | UART_DRV_LSI_FE)))
    {
        /* detect break */
        Uart_Drv_DetectBreak(InstanceId);
    }
    else
    {
        if (0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LSI_OE))
        {
        
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
            UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
    #endif
#endif
            /* overrun */
            Uart_Drv_ReceiveOverrunError(InstanceId);
        }
        else if (0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_LSI_INT_FLAG))
        {
        
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
            UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
    #endif
#endif
            /* other frame error handler */
            Uart_Drv_FrameErrorIrqHandler(InstanceId);
        }
#if(STD_ON == UART_DRV_SOFTWARE_SIMULATION)
        else if(UART_DRV_LSI_RCVADDR == (uint32)(Uart_Drv_LineStatusBufArray[InstanceId] & 
                                                                            UART_DRV_LSI_RCVADDR))
        {
            (void)Uart_Drv_ReceiveByte(InstanceId);
        }
#endif
        else
        {
            /* frame send or receive*/
            Uart_Drv_FrameTransceiverIrqHandler(InstanceId);
        }
    }

}

/**
 *
 * @brief      This function is used to handle lin header done.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_HandleHeaderDoneIrq(uint8 InstanceId)
{
    const Uart_Drv_ConfigType   *ConfigPtr= Uart_Drv_ConfigArrayPtr[InstanceId];
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    if(UART_DRV_NODE_MASTER == ConfigPtr->NodeType)
    {
        if( 0U == (Uart_Drv_LineStatusBufArray[InstanceId] & (UART_DRV_LSI_OE| UART_LSI_INT_FLAG | 
                                                               UART_DRV_LIN_HEADER_DONE_ERROR_FLAG)))
        {
            Uart_Drv_HandleHeaderDone(InstanceId);
        }
        else
        {
            (void)Uart_Drv_ReceiveByte(InstanceId);
            CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_FRAME_ERROR;
            CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SEND_PID;
            Uart_Drv_SetIdleState(InstanceId);
        }
    }
    else
    {
        if( 0U == (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_HEADER_DONE_ERROR_FLAG))
        {
            Uart_Drv_HandleHeaderDone(InstanceId);
        }
        else
        {
            /* only slave header error */
            CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_RECV_HEADER_ERR;
            /* Set slave autosync failed flag */
            if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_SYNC_FIELD_ERR))
            {
                Uart_Drv_SlaveAutosyncErrFlagArray[InstanceId] = TRUE;
            }
            Uart_Drv_SetIdleState(InstanceId);
        }
    }
    if (NULL_PTR != ConfigPtr->LinCallbackPtr)
    {
        ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
    }
}

#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
/**
 *
 * @brief      This function is used to handle tx response done.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_HandleSwSlaveTxResponseDone(uint8 InstanceId)
{
    const Uart_Drv_ConfigType   *ConfigPtr= Uart_Drv_ConfigArrayPtr[InstanceId];
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];

#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
        UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
    #endif
#endif
    CrtTransferCfgPtr->CurrentEventId   = UART_DRV_EVENT_TX_COMPLETED;
    Uart_Drv_SetIdleState(InstanceId);
    if (NULL_PTR != ConfigPtr->LinCallbackPtr)
    {
        ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
    }

}
#endif

/**
 *
 * @brief      This function is used to handle lin response done.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_HandleResponseDoneIrq(uint8 InstanceId)
{
    const Uart_Drv_ConfigType   *ConfigPtr= Uart_Drv_ConfigArrayPtr[InstanceId];
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];

#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)
    #ifdef UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY
        UART_DRV_SIMULATION_SLAVE_STOP_TIMEOUT_NOTIFY(InstanceId);
    #endif
#endif
    if(CrtTransferCfgPtr->CntByte != CrtTransferCfgPtr->TxSize)
    {
        CrtTransferCfgPtr->CurrentEventId = UART_DRV_EVENT_CHECKSUM_ERROR;
        Uart_Drv_SetIdleState(InstanceId);
    }
    else if( 0U == (Uart_Drv_LineStatusBufArray[InstanceId] & 
                                            (UART_DRV_LIN_RSP_DONE_ERROR_FLAG | UART_LSI_INT_FLAG)))
    {
        /* Handle response done: transmit response and receive response ok */
        Uart_Drv_HandleRespDone(InstanceId);
    }
    else
    {
        /* only receive response will enter here */
        Uart_Drv_HandleRspErr(InstanceId);
    }
    if (NULL_PTR != ConfigPtr->LinCallbackPtr)
    {
        ConfigPtr->LinCallbackPtr(InstanceId, CrtTransferCfgPtr);
    }
}

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Private_FunctionDefinition */


/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/**
 *
 * @brief      Initializes the UART.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  UartConfig:  Pointer to a UART configuration structure.
 *
 * @return     None
 *
 */
void Uart_Drv_UartModeInit(Uart_Drv_IdType UartId,
                                    const Uart_Drv_InitConfigType* UartConfig)
{
    uint32 IntegerDiv; 
    uint32 FractionalDiv;
    uint32 ClkFreq = UartConfig->OscFreq;
    Reg_Uart_BfType *UartBfPtr;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];
  /************Configure the Baud Rate*********************************/

    /* Enable DLAB to set baud rate */
    UartBfPtr->UART_LCR.DLAB = 0x01U;

    /* get integer baudrate divisor*/
    IntegerDiv = ClkFreq/(16U * UartConfig->BaudRate);

    /* Config the DLL and DLH registers */
    UartBfPtr->UART_RBR_THR_DLL.UART_DLL.DL_L = IntegerDiv & 0xFFU;
    UartBfPtr->UART_DLH_IER.UART_DLH.DL_H = (IntegerDiv >> 0x08U)& 0xFFU;

    /* calculate fractional divisor
       divisor = clkFreq/(16*baudrate) = BRDI +BRDF
       FD = BRDF*2^4 = 16* BRDF
       BRDF = clkFreq%(16*baudrate)/(16*baudrate)
       FD = clkFreq%(16*baudrate)*16/(16*baudrate)
          = clkFreq%(16*baudrate)/baudrate  */
    FractionalDiv = ClkFreq%(16U * UartConfig->BaudRate);
    FractionalDiv /= UartConfig->BaudRate;
    UartBfPtr->UART_FD.FD = FractionalDiv;

    /* Disable DLAB */
    UartBfPtr->UART_LCR.DLAB = 0x0U;

    if(UART_DRV_PARITY_NONE == UartConfig->Parity)
    {
        UartBfPtr->UART_LCR.PEN = 0x0U;
    }
    else if(UART_DRV_PARITY_ODD == UartConfig->Parity)
    {
        UartBfPtr->UART_LCR.PEN = 0x1U;
        UartBfPtr->UART_LCR.EPS = 0U;
    }
    else
    {
        UartBfPtr->UART_LCR.PEN = 0x1U;
        UartBfPtr->UART_LCR.EPS = 1U;
    }

    /* Set UART Data Length and stop bit */
    if(UART_DRV_DATABITS_9 == UartConfig->DataBits)
    {
       UartBfPtr->UART_LCR_EXT.DLS_E = 0x1U;
    }
    else
    {
        UartBfPtr->UART_LCR.DLS = (uint32)UartConfig->DataBits ;
    }
    /* Set UART  stop bit */
    UartBfPtr->UART_LCR.STOP = (uint32)UartConfig->StopBits;

    /***********Configure auto flow  *******************/
    UartBfPtr->UART_AFCR.AFCE = (uint32)UartConfig->AutoFlowControl;

    if(TRUE == UartConfig->AutoFlowControl)
    {
        UartBfPtr->UART_AFCR.RTS = 1U;
    }
    else
    {
        UartBfPtr->UART_AFCR.RTS = 0U;
    }
}

/**
 *
 * @brief      Set UART rts enable .
 *
 * @param[in]  UartId:  UART peripheral selected.
 * @param[in]  NewState: Enable/Disable function state.
 *
 * @return     None
 *
 */
void Uart_Drv_RtsEnable(Uart_Drv_IdType UartId, boolean NewState)
{
    Reg_Uart_BfType *UartBfPtr;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];
    UartBfPtr->UART_AFCR.RTS = (uint32)NewState;
}

/**
 *
 * @brief      idle detect config.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  Config: config idle detect. 
 *
 * @return     None
 *
 */
void Uart_Drv_IdleDetectConfig( Uart_Drv_IdType UartId, 
                                            const Uart_Drv_IdleDetectConfigType *Config)
{
    Reg_Uart_BfType *UartBfPtr;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];
        
    UartBfPtr->UART_LCR.IDLE_DET_LENGTH = (uint32)Config->Len;
    UartBfPtr->UART_LCR.IDLE_DET_EN = (uint32)Config->Cmd;
}

/**
 *
 * @brief      Config UART FIFO function.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  FifoConfig:  Pointer to a FIFO configuration.
 *
 * @return     None
 *
 */
void Uart_Drv_FifoConfig(Uart_Drv_IdType UartId, const Uart_Drv_FifoConfigType* FifoConfig)
{
    uint32 RegValue;
    Reg_Uart_WType *UartWPtr;
    UartWPtr  = Uart_Drv_UartRegWPtr[UartId];

    RegValue =((((uint32)(FifoConfig->FifoRt) & 0x03U) << 6U)
                    | (((uint32)(FifoConfig->FifoTet) & 0x03U) << 4U)
                    | (((uint32)(FifoConfig->TxFifoReset) & 0x01U) << 2U)
                    | (((uint32)(FifoConfig->RxFifoReset) & 0x01U) << 1U)
                    | ((uint32)(FifoConfig->FifoEnable) & 0x01U));

    UartWPtr->UART_IIR_FCR.UART_FCR = RegValue;
    
    Uart_Drv_FifoBufArray[UartId] = RegValue; 
    Uart_Drv_FifoBufArray[UartId] &= (~(UART_DRV_RESET_RX_FIFO | UART_DRV_RESET_TX_FIFO));
}

/**
 *
 * @brief      Get current value of Line Status register.
 *
 * @param[in]  UartId:  Select the UART port, should be UART0_ID, UART1_ID,
 *                      UART2_ID, UART3_ID, UART4_ID, UART5_ID.
 * @param[in]  LineStatus:
 *                       - UART_DRV_LINESTA_DR
 *                       - UART_DRV_LINESTA_OE
 *                       - UART_DRV_LINESTA_PE
 *                       - UART_DRV_LINESTA_FE
 *                       - UART_DRV_LINESTA_BI
 *                       - UART_DRV_LINESTA_THRE
 *                       - UART_DRV_LINESTA_TEMT
 *                       - UART_DRV_LINESTA_RFE
 *                       - UART_DRV_LINESTA_TRANS_ERR
 *                       - UART_DRV_LINESTA_ADDR_RCVD
 *                       - UART_DRV_LINESTA_ASYNC
 *                       - UART_DRV_LINESTA_FIELD_ERR
 *                       - UART_DRV_LINESTA_PID_ERR
 *                       - UART_DRV_LINESTA_CHECKSUM_ERR
 *                       - UART_DRV_LINESTA_TO_ERR
 *                       - UART_DRV_LINESTA_HEADER_DONE
 *                       - UART_DRV_LINESTA_RSP_DONE
 * 
 * @note       This function returns only one line status. However,  once call 
 *             this function, all line status will be cleared. If user
 *             needs to read more than one line status, it is suggested to use 
 *             Uart_Drv_GetAllLineStatus() to get all line status and handle them 
 *             one by one.
 *
 * @return     The state value of UART Line Status register.
 *
 */
boolean Uart_Drv_GetLineStatus(Uart_Drv_IdType UartId, Uart_Drv_LineStatusType LineStatus)
{
    boolean BitStatus;
    const Reg_Uart_WType *UartWPtr;
    UartWPtr  = Uart_Drv_UartRegWPtr[UartId];

    BitStatus = (((UartWPtr->UART_LSR & Uart_Drv_LineStatusTable[LineStatus]) != 0U) 
                  ? TRUE : FALSE);

    return BitStatus;
}

/**
 *
 * @brief      Set receive 9 bits data mode 0.
 *
 * @param[in]  UartId: Select the UART port.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM0Rx(Uart_Drv_IdType UartId)
{
    Reg_Uart_BfType *UartBfPtr;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];
    if((uint32)1U == UartBfPtr->UART_LCR_EXT.DLS_E)
    {   /* Receive mode 0 */
        UartBfPtr->UART_LCR_EXT.ADDR_MATCH = 0x0U;        
    }
    else
    {
        /* none */
    }
}

/**
 *
 * @brief      Program the address of  receive 9 bits data, mode 1.
 *
 * @param[in]  UartId: Select the UART port.
 * @param[in]  Addr: set address.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM1SetAddr(Uart_Drv_IdType UartId, uint8 Addr)
{
    Reg_Uart_BfType *UartBfPtr;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];
    /* set address in rar */
    UartBfPtr->UART_RAR.RAR = Addr;
}

/**
 *
 * @brief      Select 9 bits hardware receive mode 1.
 *
 * @param[in]  UartId: Select the UART port.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsHWRecvEnable(Uart_Drv_IdType UartId)
{
    Reg_Uart_BfType *UartBfPtr;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];
    UartBfPtr->UART_LCR_EXT.ADDR_MATCH = 0x1U;
}

/**
 *
 * @brief      Receive address from the UART peripheral, mode 1.
 *
 * @param[in]  UartId: Select the UART port.
 *
 * @return     The received address.
 *
 */
uint16 Uart_Drv_9BitsM1RxAddr(Uart_Drv_IdType UartId)
{
    const Reg_Uart_BfType *UartBfPtr;
    const Reg_Uart_WType *UartWPtr;
    uint16 Ret;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];    
    UartWPtr  = Uart_Drv_UartRegWPtr[UartId];
    uint8 Rxaddr;
    uint32 RegData;

    RegData = (uint32)UartWPtr->UART_RBR_THR_DLL.UART_RBR;
    Rxaddr = (uint8)UartBfPtr->UART_RAR.RAR;    

    if(0x100U == (RegData & 0x100U))
    {
        if(Rxaddr == (RegData & 0xFFU))
        {
            Ret = (uint16)RegData;
        }
        else
        {
            Ret = (uint16)FALSE;
        }
    }
    else
    {
        Ret = (uint16)FALSE;
    }
    return Ret;
}

/**
 *
 * @brief      Receive one byte data from the UART peripheral, mode 1.
 *
 * @param[in]  UartId:  Select the UART port.
 *
 * @return     The received data.
 *
 */
uint16 Uart_Drv_9BitsM1RxData(Uart_Drv_IdType UartId)
{
    uint16 Ret;
    uint32 RegData;    
    const Reg_Uart_WType *UartWPtr;  
    UartWPtr  = Uart_Drv_UartRegWPtr[UartId];
    RegData = (uint32)UartWPtr->UART_RBR_THR_DLL.UART_RBR;
    
    if(0U == (RegData & 0x100U))
    {
        Ret = (uint16)(RegData & 0xFFU);
    }
    else
    {
        Ret = 0x1FF;
    }

    return Ret;
}

/**
 *
 * @brief      Program the transmit target address, 9bits, mode 0.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  Addr:  program the address.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM0SetAddr(Uart_Drv_IdType UartId, uint8 Addr)
{
    Reg_Uart_BfType *UartBfPtr;  
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId]; 
    /* transmit mode 0 */
    if(0x1U == UartBfPtr->UART_LCR_EXT.DLS_E)
    {
        UartBfPtr->UART_LCR_EXT.TRANSMIST_MODE = 0x0U;
        UartBfPtr->UART_TAR.TAR = (uint32)Addr;
    }
}

/**
 *
 * @brief      Set send address bit, mode 0.
 *
 * @param[in]  UartId:  Select the UART port.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM0SendAddr(Uart_Drv_IdType UartId)
{
    Reg_Uart_BfType *UartBfPtr;  
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId]; 
    UartBfPtr->UART_LCR_EXT.SEND_ADDR = 0x1U;
}

/**
 *
 * @brief      Send 9 bits data to the UART peripheral, mode 1.
 *
 * @param[in]  UartId:  Select the UART port.
 * @param[in]  Data:  The data to be sent.
 *
 * @return     None
 *
 */
void Uart_Drv_9BitsM1TxData(Uart_Drv_IdType UartId, uint16 Data)
{
    Reg_Uart_BfType *UartBfPtr;
    Reg_Uart_WType *UartWPtr;
    UartBfPtr  = Uart_Drv_UartRegBfPtr[UartId];    
    UartWPtr  = Uart_Drv_UartRegWPtr[UartId];
    /* transmit mode 1 */
    if((uint32)1U == UartBfPtr->UART_LCR_EXT.DLS_E)
    {
        UartBfPtr->UART_LCR_EXT.TRANSMIST_MODE = 0x1U;
        /* Send data */
        UartWPtr->UART_RBR_THR_DLL.UART_THR = ((uint32)Data) & 0x1FFU;
    }
}

/**
 *
 * @brief       Initialize a LIN channel.
 *
 * @param[in]   InstanceId: initial channel.
 * @param[in]   ConfigPtr: initial configuration.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
/* SWS_Lin_00008, SWS_Lin_00190 */
Uart_Drv_StatusType Uart_Drv_Init(uint8 InstanceId, const Uart_Drv_ConfigType *ConfigPtr)
{
    Uart_Drv_StatusType          Ret = UART_DRV_STATUS_SUCCESS;
    Reg_Uart_BfType *UartBfPtr;
    const Reg_Uart_WType  *UartWPtr;
    volatile uint32 DummyData;
#if (STD_OFF == UART_DRV_SOFTWARE_SIMULATION)
    uint32 RspOpStart;
    uint32 HeaderOpStart;
#endif
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigPtr);
    MCALLIB_DEV_ASSERT((uint8)InstanceId == ConfigPtr->InstanceId);    
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
    UartWPtr = Uart_Drv_UartRegWPtr[InstanceId];
    Uart_Drv_ConfigArrayPtr[InstanceId] = ConfigPtr;

    if (FALSE == Uart_Drv_WaitBusyClear(InstanceId))
    {
        Ret = UART_DRV_STATUS_ERROR;
    }
    else
    {        
        DummyData = UartWPtr->UART_LSR;
        DummyData = UartWPtr->UART_MSR;
        DummyData = UartWPtr->UART_RBR_THR_DLL.UART_RBR;
        UartBfPtr->UART_LCR.DLAB = 0x01U;
        /* Config the DLL and DLH registers */
        UartBfPtr->UART_RBR_THR_DLL.UART_DLL.DL_L = (ConfigPtr->BaudRateDivisor) & 0xFFU;
        UartBfPtr->UART_DLH_IER.UART_DLH.DL_H     = ((ConfigPtr->BaudRateDivisor) >> 0x08U) & 0xFFU;
        UartBfPtr->UART_FD.FD = (ConfigPtr->FranctionDivisor);
        /* Disable DLAB */
        UartBfPtr->UART_LCR.DLAB = 0x0U;
        /* select 8 bit transmit */
        /* no parity */
        UartBfPtr->UART_LCR.PEN = 0x0U;
        /* 8 bits */
        UartBfPtr->UART_LCR.DLS = 0x3U;        
        /* 1 stop bit */
        UartBfPtr->UART_LCR.STOP = 0x0U;
        UartBfPtr->UART_LCR.DEBUG_EN = 1U;
        UartBfPtr->UART_AFCR.RTS = 0x0U;
        /* break */
        UartBfPtr->UART_LCR.LBKM = UART_DRV_BREAKLEN((ConfigPtr->BreakLen));
        /* disable FIFO in LIN mode */
        Uart_Drv_DisableFifo(InstanceId);
        /* DISABLE ALL INTERRUPT */
        Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_ALL, (boolean)FALSE);
        /* clean all polling flag */
        Uart_Drv_PollingFlagArray[InstanceId] &= 
                    (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_ALL]));
#if (STD_OFF == UART_DRV_SOFTWARE_SIMULATION)
        /* config LIN mode */
        UartBfPtr->UART_LIN_CTL.LIN_MODE = 1U;
        UartBfPtr->UART_LIN_CTL.MASTER_MODE = (uint32)ConfigPtr->NodeType;
        /* auto sync */
        UartBfPtr->UART_LCR.AUTO_SYNC_EN = (uint32)ConfigPtr->AutosyncEnable;
        
        /* Check if the current node is slave */
        if (UART_DRV_NODE_SLAVE == ConfigPtr->NodeType)
        { /* slave start receive header and enable header done interrupt */
            RspOpStart    = UartBfPtr->UART_LIN_CTL.RSP_OP_START;            
            HeaderOpStart = UartBfPtr->UART_LIN_CTL.HEADER_OP_START;
            /* check if UART is busy */
            if ((RspOpStart != 0U) || (HeaderOpStart != 0U))
            {
                Ret = UART_DRV_STATUS_ERROR;
            }
            if(1U == ConfigPtr->AutosyncEnable)
            {
                Uart_Drv_SlaveAutosyncErrFlagArray[InstanceId] = FALSE;
            }
            Uart_Drv_LineStatusFlag[InstanceId] =0U;
        }
        else
        {
            Uart_Drv_LineStatusFlag[InstanceId] =1U;
        }

		/* Add Filter Function */
		#ifdef LeftAir
		UartBfPtr->UART_LIN_PID_FILTER_0.FID0 = 0x01;
		#endif
		#ifdef RightAir
		UartBfPtr->UART_LIN_PID_FILTER_0.FID0 = 0x02;
		#endif
		UartBfPtr->UART_LIN_PID_FILTER_0.FID1 = 0x03;
		UartBfPtr->UART_LIN_PID_FILTER_0.FID2 = 0x04;
		UartBfPtr->UART_LIN_PID_FILTER_0.FID3 = 0x3C;
		UartBfPtr->UART_LIN_PID_FILTER_1.FID4 = 0x3D;
		UartBfPtr->UART_LIN_PID_FILTER_CTRL.FID_MASK = 0x1F;
		UartBfPtr->UART_LIN_PID_FILTER_CTRL.LIN_FILTER_EN = TRUE;
		
#else/*STD_ON == UART_DRV_SOFTWARE_SIMULATION*/
        if (UART_DRV_NODE_MASTER == ConfigPtr->NodeType)
        {
            UartBfPtr->UART_LIN_CTL.LIN_MODE = 1U;
            UartBfPtr->UART_LIN_CTL.MASTER_MODE = (uint32)ConfigPtr->NodeType;
        }
        if(1U == ConfigPtr->AutosyncEnable)
        {
            Uart_Drv_SlaveAutosyncErrFlagArray[InstanceId] = FALSE;
        }
        Uart_Drv_LineStatusFlag[InstanceId] = 1U;
#endif

        Uart_Drv_WakeupSignalArray[InstanceId]       = ConfigPtr->WakeupByte;
#if (STD_ON == UART_DRV_WAKEUP_DETECTION )
        Uart_Drv_WakeupDetectInvertArray[InstanceId] = ConfigPtr->CalWakeupLen;
#endif

        Uart_Drv_TransferConfigArrayPtr[InstanceId] = ConfigPtr->TransferConfigPtr;
        Uart_Drv_TransferConfigArrayPtr[InstanceId]->IsBusBusy = (boolean)FALSE;
        Uart_Drv_TransferConfigArrayPtr[InstanceId]->CurrentEventId = UART_DRV_NO_EVENT;
        Uart_Drv_TransferConfigArrayPtr[InstanceId]->CurrentNodeState =
        UART_DRV_NODE_STATE_IDLE;
#if (STD_ON == UART_DRV_SOFTWARE_POLLING )
        Uart_Drv_TransferConfigArrayPtr[InstanceId]->PollMode = UART_DRV_POLLING;
#else
        Uart_Drv_TransferConfigArrayPtr[InstanceId]->PollMode = UART_DRV_INTERRUPT;
#endif

    }
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
    return Ret;
}

/**
 *
 * @brief       Deinit a LIN channel.
 *
 * @param[in]   InstanceId: initial channel.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_Deinit(uint8 InstanceId)
{
    Uart_Drv_StatusType          Ret = UART_DRV_STATUS_SUCCESS;
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if ( STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
#if ( STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    if (TRUE == CrtTransferCfgPtr->IsBusBusy)
    {
        Ret = UART_DRV_STATUS_ERROR;
    }
    else
    {
        if (FALSE == Uart_Drv_WaitBusyClear(InstanceId))
        {
            Ret = UART_DRV_STATUS_ERROR;
        }
        else
        {
            CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_UNINIT;
        }
        Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_ALL, (boolean)FALSE);
        Uart_Drv_ResetRxFifo(InstanceId);
        Uart_Drv_ResetTxFifo(InstanceId);
        if(1U == (Uart_Drv_GetAllLineStatus(InstanceId) & UART_DRV_LSI_DR))
        {
            (void)Uart_Drv_ReceiveByte(InstanceId);
        }
        
         /* clean all polling flag */
        Uart_Drv_PollingFlagArray[InstanceId] &= 
                    (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_ALL]));
        Uart_Drv_TransferConfigArrayPtr[InstanceId] = NULL_PTR;
    }
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 *
 * @brief       Get master status
 *
 * @param[in]   InstanceId: LIN ID
 * @param[in]   LinSduPtr: pointer to  memory mapped LIN hardware receive buffer
 *                       where the current SDU is stored.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval	    UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval	    UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
 /* SWS_Lin_00240 */
Uart_Drv_TransferStateType Uart_Drv_GetMasterStatus(uint8 InstanceId, uint8 **LinSduPtr)
{
    Uart_Drv_TransferStateType  Ret = UART_DRV_STATE_NOT_OK;
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    Uart_Drv_NodeStateType     CrtNodeState;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
    MCALLIB_DEV_ASSERT(NULL_PTR != LinSduPtr);   
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);    
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtNodeState = CrtTransferCfgPtr->CurrentNodeState;

    switch (CrtTransferCfgPtr->CurrentEventId)
    {  
        case UART_DRV_EVENT_SEND_HEADER_OK:
            Ret = Uart_Drv_MasterGetStatusAfterHeader(InstanceId, CrtNodeState);
            break;

        case UART_DRV_EVENT_WAKEUP_SIGNAL:
            Ret = UART_DRV_STATE_OPERATIONAL;
            break;

        case UART_DRV_EVENT_TX_COMPLETED:
            Ret = UART_DRV_STATE_TX_OK;
            break;

        case UART_DRV_EVENT_RX_COMPLETED:
            Ret        = UART_DRV_STATE_RX_OK;
            *LinSduPtr = Uart_Drv_SduBufferArray[InstanceId];
            break;

        case UART_DRV_NO_EVENT:
            Ret = Uart_Drv_GetStatusWhenNoEvent(CrtNodeState);
            break;

        default:
            Ret = Uart_Drv_GetStatusWhenError(InstanceId);
            break;
    }
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 *
 * @brief       Get slave status.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   LinSduPtr: pointer to  memory mapped LIN hardware receive buffer
 *                       where the current SDU is stored.
 *
 * @return      Uart_Drv_TransferStateType
 * @retval      UART_DRV_STATE_NOT_OK - Development or production error occurred.
 * @retval      UART_DRV_STATE_TX_OK - Successful transmission.
 * @retval      UART_DRV_STATE_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      UART_DRV_STATE_TX_HEADER_ERROR: Erroneous header transmission such as:
 *              - Mismatch between sent and read back data
 *   		    - Identifier parity error or Physical bus error
 * @retval	    UART_DRV_STATE_TX_ERROR: Erroneous response transmission such as:
 *			    - Mismatch between sent and read back data
 *			    - Physical bus error
 * @retval	    UART_DRV_STATE_RX_OK: Reception of correct response.
 * @retval	    UART_DRV_STATE_RX_BUSY: Ongoing reception: at least one response byte has been 
 *              received, but the checksum byte has not been received.
 * @retval	    UART_DRV_STATE_RX_ERROR: Erroneous response reception such as:
 *			    - Framing error
 *			    - Overrun error
 *			    - Checksum error or Short response
 * @retval	    UART_DRV_STATE_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval      UART_DRV_STATE_RX_HEADER_OK
 * @retval      UART_DRV_STATE_RX_HEADER_ERROR
 * @retval	    UART_DRV_STATE_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval	    UART_DRV_STATE_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
 /* SWS_Lin_00240 */
Uart_Drv_TransferStateType Uart_Drv_GetSlaveStatus(uint8 InstanceId, uint8 **LinSduPtr)
{
    Uart_Drv_TransferStateType  Ret = UART_DRV_STATE_NOT_OK;
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    Uart_Drv_NodeStateType     CrtNodeState;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
    MCALLIB_DEV_ASSERT(NULL_PTR != LinSduPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtNodeState = CrtTransferCfgPtr->CurrentNodeState;

    switch (CrtTransferCfgPtr->CurrentEventId)
    {
        case UART_DRV_EVENT_RECV_HEADER_ERR:
            Ret = UART_DRV_STATE_RX_HEADER_ERROR;
            break;

        case UART_DRV_EVENT_RECV_HEADER_OK:
            Ret = UART_DRV_STATE_RX_HEADER_OK;
            break;
        case UART_DRV_EVENT_WAKEUP_SIGNAL:
            Ret = UART_DRV_STATE_OPERATIONAL;
            break;

        case UART_DRV_EVENT_TX_COMPLETED:
            Ret = UART_DRV_STATE_TX_OK;
            break;

        case UART_DRV_EVENT_RX_COMPLETED:
            Ret        = UART_DRV_STATE_RX_OK;
            *LinSduPtr = Uart_Drv_SduBufferArray[InstanceId];
            break;

        case UART_DRV_NO_EVENT:
            Ret = Uart_Drv_GetStatusWhenNoEvent(CrtNodeState);
            break;

        default:
            Ret = Uart_Drv_GetStatusWhenError(InstanceId);
            break;
    }
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 *
 * @brief       Send Lin header.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   PduInfoPtr: Pointer to PDU containing the PID, checksum model, response
 *              type, Dl and SDU data pointer.
 *
 * @return      None
 *
 */
static void Uart_Drv_SendHeader(uint8 InstanceId, const Uart_Drv_PduType *PduInfoPtr)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    const Uart_Drv_ConfigType *ConfigPtr;
    Reg_Uart_BfType *UartBfPtr;
    uint8 Index;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if ( STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
    MCALLIB_DEV_ASSERT(NULL_PTR != PduInfoPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
#if ( STD_ON == UART_DRV_DEV_ERROR_DETECT )
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */    
    CrtTransferCfgPtr->CurrentPid = PduInfoPtr->Pid;

    if (UART_DRV_FRAMERESPONSE_TX == PduInfoPtr->Drc)
    {
        /* Copy data to buffer */
        for (Index = 0U; Index < PduInfoPtr->Dl; Index++)
        {
            Uart_Drv_SduBufferArray[InstanceId][Index] = PduInfoPtr->SduPtr[Index];
        }
        SchM_Enter_Lin_GlobalChecksum();
        CrtTransferCfgPtr->Checksum =
        (UART_DRV_CLASSIC_CS == PduInfoPtr->Cs) ? 0x00U : PduInfoPtr->Pid;
        CrtTransferCfgPtr->Checksum = Uart_Drv_ChecksumCalc(PduInfoPtr->SduPtr, PduInfoPtr->Dl,
                                                                CrtTransferCfgPtr->Checksum);
        SchM_Exit_Lin_GlobalChecksum();
        CrtTransferCfgPtr->TxBuff = &Uart_Drv_SduBufferArray[InstanceId][0U];
        CrtTransferCfgPtr->TxSize = PduInfoPtr->Dl + 1U;
        CrtTransferCfgPtr->RxSize = 0U;       
        SchM_Enter_Lin_UartChecksumReg();
        UartBfPtr->UART_LIN_CHECKSUM.CHECKSUM_TYPE = (uint8)PduInfoPtr->Cs;
        SchM_Exit_Lin_UartChecksumReg();
    }
    else if (UART_DRV_FRAMERESPONSE_RX == PduInfoPtr->Drc)
    {
        /* Clear rx buffer */
        for (Index = 0U; Index < UART_DRV_LIN_MAX_DATA_LENGTH; Index++)
        {
            Uart_Drv_SduBufferArray[InstanceId][Index] = 0U;
        }
        CrtTransferCfgPtr->TxSize = 0U;
        CrtTransferCfgPtr->RxSize = PduInfoPtr->Dl + 1U;
        SchM_Enter_Lin_UartChecksumReg();
        UartBfPtr->UART_LIN_CHECKSUM.CHECKSUM_TYPE = (uint32)PduInfoPtr->Cs;
        SchM_Exit_Lin_UartChecksumReg();
    }
    else
    {
        CrtTransferCfgPtr->TxSize = 0U;
        CrtTransferCfgPtr->RxSize = 0U;
    }

    CrtTransferCfgPtr->CntByte = 0U;

    CrtTransferCfgPtr->CurrentEventId = UART_DRV_NO_EVENT;
    CrtTransferCfgPtr->IsBusBusy        = (boolean)TRUE;
    CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SEND_BREAK_FIELD;

    Uart_Drv_ClearTransmission(InstanceId);
    SchM_Enter_Lin_PrepareSendData();
    UartBfPtr->UART_LIN_DEL_LENGTH.LIN_DEL_LENGTH = ConfigPtr->DelLen - 1U;
    UartBfPtr->UART_LIN_PID_VALUE.PID = CrtTransferCfgPtr->CurrentPid;
    SchM_Exit_Lin_PrepareSendData();
    
    SchM_Enter_Lin_UartLinControlReg();    
    UartBfPtr->UART_LIN_CTL.MASTER_MODE = 1U;
    /* master start to send */
    UartBfPtr->UART_LIN_CTL.HEADER_OP_START = 1U;
    SchM_Exit_Lin_UartLinControlReg();    
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 *
 * @brief       LIN master send header or slave send response.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 * @param[in]   PduInfoPtr: Pointer to PDU containing the PID, checksum model, response
 *              type, Dl and SDU data pointer.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR,
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_SendFrame(uint8                       InstanceId,
                                               const Uart_Drv_PduType *PduInfoPtr)
{
    Uart_Drv_StatusType          Ret = UART_DRV_STATUS_SUCCESS;
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    const Uart_Drv_ConfigType *ConfigPtr;

    boolean CheckDl;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
    
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
    MCALLIB_DEV_ASSERT(NULL_PTR != PduInfoPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CheckDl = (boolean)((0x0U == PduInfoPtr->Dl) || (0x8U < PduInfoPtr->Dl)); 
    if ( UART_DRV_NODE_STATE_SLEEP_MODE == CrtTransferCfgPtr->CurrentNodeState )
    {
        Ret = UART_DRV_STATUS_ERROR;
    }
    else
    {
        if (TRUE == CrtTransferCfgPtr->IsBusBusy)
        {
            Ret = UART_DRV_STATUS_BUSY;
        }
        else
        {
           if(UART_DRV_NODE_MASTER == ConfigPtr->NodeType)
           {
                /* master send header */
                Uart_Drv_SendHeader(InstanceId, (const Uart_Drv_PduType *)PduInfoPtr);
           }
           else
           {
                if(TRUE == CheckDl)
                {
                    Ret = UART_DRV_STATUS_ERROR;
                }
                else
                {
                    /* only slave enter here process response */
                    Uart_Drv_ProcessResponse(InstanceId, (const Uart_Drv_PduType *)PduInfoPtr);
                }
                
           }
        }
    }
 #if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 *
 * @brief       Stop transmission, abort on-going transmission/reception.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR,
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_StopTransfer(const uint8 InstanceId)
{
    Uart_Drv_StatusType                  Ret          = UART_DRV_STATUS_ERROR;
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr =Uart_Drv_TransferConfigArrayPtr[InstanceId];

    if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
    {
        Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_ALL, (boolean)FALSE);
    }
    else
    {
        Uart_Drv_PollingFlagArray[InstanceId] &= 
                    (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_ALL]));
    }

    Uart_Drv_ClearTransmission(InstanceId);
    if(TRUE == Uart_Drv_WaitBusyClear(InstanceId))
    {
        Ret = UART_DRV_STATUS_SUCCESS;
    }
    else
    {
        Ret = UART_DRV_STATUS_BUSY;
    }

    Uart_Drv_SetIdleState(InstanceId);
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 *
 * @brief       This API command the node to go to sleep, which ID = 0x3C, without sending a go to
 *              sleep command on the bus.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_StatusType
 * @retval      -UART_DRV_STATUS_SUCCESS
 * @retval      -UART_DRV_STATUS_ERROR
 * @retval      -UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_GoToSleepInternal(uint8 InstanceId)
{
    Uart_Drv_StatusType Ret = UART_DRV_STATUS_SUCCESS;

    Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    const Uart_Drv_ConfigType *ConfigPtr;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr =
        Uart_Drv_TransferConfigArrayPtr[InstanceId];
    ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */

    if (TRUE == CrtTransferCfgPtr->IsBusBusy)
    {
        Ret = UART_DRV_STATUS_ERROR;
    }
    else
    {
        if (UART_DRV_NODE_STATE_SLEEP_MODE != CrtTransferCfgPtr->CurrentNodeState)
        {
            CrtTransferCfgPtr->CurrentEventId = UART_DRV_NO_EVENT;
            CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_SLEEP_MODE;
            if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
            {
                Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_ALL, (boolean)FALSE);
                Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_ASYNC, (boolean)TRUE);
            }
            else
            {
                Uart_Drv_PollingFlagArray[InstanceId] &= 
                    (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_ALL]));
                Uart_Drv_PollingFlagArray[InstanceId] |= 
                     (Uart_Drv_PollingMaskArray[UART_DRV_POLL_ASYNC]);
                
            }
            if( UART_DRV_NODE_MASTER == ConfigPtr->NodeType)
            {
                if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
                {
                    Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, (boolean)TRUE);
                }
                else
                {
                    Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]);
                }
            }
            else
            {
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION)
                if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
                {
                    Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, (boolean)TRUE);
                }
                else
                {
                    Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]);
                }
#endif
            }

        }
    }
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 *
 * @brief       Sends a wake up signal to the LIN bus.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      Uart_Drv_StatusType.
 * @retval       UART_DRV_STATUS_SUCCESS
 * @retval       UART_DRV_STATUS_ERROR
 * @retval       UART_DRV_STATUS_BUSY
 *
 */
Uart_Drv_StatusType Uart_Drv_Wakeup(const uint8 InstanceId)
{
    Uart_Drv_StatusType Ret = UART_DRV_STATUS_SUCCESS;

    Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Check if current instance is already de-initialized or is gated.*/
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */

    if ((TRUE == CrtTransferCfgPtr->IsBusBusy) ||
        (UART_DRV_NODE_STATE_SLEEP_MODE != CrtTransferCfgPtr->CurrentNodeState))
    {
        Ret = UART_DRV_STATUS_ERROR;
    }
    else
    {
        CrtTransferCfgPtr->IsBusBusy = (boolean)TRUE;
       
        if (FALSE == Uart_Drv_SendWakeupSignal(InstanceId, Uart_Drv_WakeupSignalArray[InstanceId]))
        {
            Ret = UART_DRV_STATUS_ERROR;
        }
    }
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Ret;
}

/**
 *
 * @brief       Set channel to operation state.
 *
 * @param[in]   InstanceId: LIN channel to be addressed.
 *
 * @return      None
 *
 */
void Uart_Drv_SetIdleState(const uint8 InstanceId)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    const Uart_Drv_ConfigType   *ConfigPtr;
    Reg_Uart_BfType *UartBfPtr;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */

    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    ConfigPtr = Uart_Drv_ConfigArrayPtr[InstanceId];
    UartBfPtr = Uart_Drv_UartRegBfPtr[InstanceId];
    (void)UartBfPtr->UART_IIR_FCR.UART_IIR.IID;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    Uart_Drv_LineStatusBufArray[InstanceId] = Uart_Drv_GetAllLineStatus(InstanceId);

    if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
    {
     /* DISABLE ALL interrupt */
        Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_ALL, (boolean)FALSE);
    }
    else
    {
        Uart_Drv_PollingFlagArray[InstanceId] &= 
                    (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_ALL]));
    }
    Uart_Drv_ClearTransmission(InstanceId);
    Uart_Drv_ResetRxFifo(InstanceId);
    Uart_Drv_ResetTxFifo(InstanceId);
    Uart_Drv_DisableFifo(InstanceId);
    if (UART_DRV_NODE_SLAVE == ConfigPtr->NodeType)
    {        
        if(TRUE == Uart_Drv_SlaveAutosyncErrFlagArray[InstanceId])
        {
    #if (STD_ON == UART_DRV_AUTOSYNC_ENABLED)
    #ifdef UART_DRV_RECOVERY_AUTOSYNC_ERROR_START_NOTIFY
            UART_DRV_RECOVERY_AUTOSYNC_ERROR_START_NOTIFY();
    #endif
    #endif
            if(TRUE == Uart_Drv_WaitBusyClear(InstanceId))
            {
                UartBfPtr->UART_LCR.DLAB = 0x01U;
                /* Config the DLL and DLH registers */
                UartBfPtr->UART_RBR_THR_DLL.UART_DLL.DL_L = (ConfigPtr->BaudRateDivisor) & 0xFFU;
                UartBfPtr->UART_DLH_IER.UART_DLH.DL_H = 
                                                    ((ConfigPtr->BaudRateDivisor) >> 0x08U) & 0xFFU;
                UartBfPtr->UART_FD.FD = (ConfigPtr->FranctionDivisor);
                /* Disable DLAB */
                UartBfPtr->UART_LCR.DLAB = 0x0U;
                Uart_Drv_SlaveAutosyncErrFlagArray[InstanceId] = FALSE;
            }
    #if (STD_ON == UART_DRV_AUTOSYNC_ENABLED)
    #ifdef UART_DRV_RECOVERY_AUTOSYNC_ERROR_STOP_NOTIFY
            UART_DRV_RECOVERY_AUTOSYNC_ERROR_STOP_NOTIFY();
    #endif
    #endif        
        }
        
                
#if (STD_OFF == UART_DRV_SOFTWARE_SIMULATION)  
        if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
        {
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_HEADER_DONE, (boolean)TRUE);
        }
        else
        {
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_HEADER_DONE]);
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]);
        }
        SchM_Enter_Lin_UartLinControlReg();                  
        /* start to receive header */
        UartBfPtr->UART_LIN_CTL.HEADER_OP_START = 1U;        
        SchM_Exit_Lin_UartLinControlReg();
#else
        UartBfPtr->UART_LIN_CTL.LIN_MODE = 0U;
        UartBfPtr->UART_LCR_EXT.DLS_E = 1U;        
        if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
        {
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, (boolean)TRUE);
        }
        else
        {
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]);
        }
#endif
    }
    else if(UART_DRV_NODE_MASTER == ConfigPtr->NodeType)
    {
        if(UART_DRV_INTERRUPT == CrtTransferCfgPtr->PollMode)
        {
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_HEADER_DONE, (boolean)TRUE);
            Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_RBFI, (boolean)TRUE);
        }
        else
        {
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_HEADER_DONE]);
            Uart_Drv_PollingFlagArray[InstanceId] |= 
                        (Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]);
        }
    }    
    else
    {
        /*Nothing to do*/
    }

    CrtTransferCfgPtr->PreviousNodeState = CrtTransferCfgPtr->CurrentNodeState;
    CrtTransferCfgPtr->CurrentNodeState = UART_DRV_NODE_STATE_IDLE;
    CrtTransferCfgPtr->IsBusBusy = (boolean)FALSE;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 *
 * @brief      This function is called by Lin ISRs for handle Wakeup Signal.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_IntHandlerWakeupSignal(uint8 InstanceId)
{
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & (uint32)UART_DRV_LIN_ASYNC_INT_FLAG ))
    {
        Uart_Drv_EnableInterrupts(InstanceId, UART_DRV_INT_ASYNC, (boolean)FALSE);
        if(UART_DRV_NODE_STATE_SLEEP_MODE == CrtTransferCfgPtr->CurrentNodeState)
        {
            Uart_Drv_CheckWakeupSignal(InstanceId, (Uart_Drv_ReceiveByte(InstanceId)));
        }
    }
}

/**
 *
 * @brief      This function is called by Lin ISRs for handle Line Status.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_IntHandlerLineStatus(uint8 InstanceId)
{
    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LSI_DR))
    {
        /* Handle frame: master process and slave readback or slave is sw lin*/
        Uart_Drv_LineStatusIrqHandler(InstanceId); 
    }
}

/**
 *
 * @brief      This function is called by Lin ISRs for handle Header Done.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_IntHandlerHeaderDone(uint8 InstanceId)
{
    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_HEADER_DONE_FLG))
    {
        Uart_Drv_HandleHeaderDoneIrq(InstanceId);  
    }
}

/**
 *
 * @brief      This function is called by Lin ISRs for handle Response Done.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
static void Uart_Drv_IntHandlerResponseDone(uint8 InstanceId)
{
    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_RSP_DONE_FLAG))
    {
        Uart_Drv_HandleResponseDoneIrq(InstanceId);  
    }
}

/**
 *
 * @brief      This function is called by Lin ISRs.
 *
 * @param[in]  InstanceId: Lin peripheral instance number.
 *
 * @return     None
 *
 */
/*SWS_Lin_00156*/
void Uart_Drv_IntHandler(uint8 InstanceId)
{
    const Reg_Uart_BfType *UartBfPtr;  
    const Reg_Uart_WType *UartWPtr ;      
    uint32         IntId;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
    UartWPtr  = Uart_Drv_UartRegWPtr[InstanceId];
    Uart_Drv_LineStatusBufArray[InstanceId] = Uart_Drv_GetAllLineStatus(InstanceId);
    
    /* clear iid  */
    IntId = UartBfPtr->UART_IIR_FCR.UART_IIR.IID;
    
    if(1U == UartBfPtr->UART_DLH_IER.UART_IER.ASYNC_INT_EN)
    {
        Uart_Drv_IntHandlerWakeupSignal(InstanceId);
    }
    if (1U == UartBfPtr->UART_DLH_IER.UART_IER.ERBFI)
    {            
        Uart_Drv_IntHandlerLineStatus(InstanceId);
    }
    /* master enable header done interrupt and slave is hardware lin  */
    if (1U == UartBfPtr->UART_DLH_IER.UART_IER.HEADER_DONE_INT_EN) 
    {
        Uart_Drv_IntHandlerHeaderDone(InstanceId);
    }
    if(1U == UartBfPtr->UART_DLH_IER.UART_IER.RSP_DONE_INT_EN)
    {
        Uart_Drv_IntHandlerResponseDone(InstanceId);
    }
    else
    {
        /*Nothing to do*/
    }        
    if(UART_DRV_INTSTA_IID_BYDET == IntId)
    {
        (void)UartWPtr->UART_USR;
    }

    Uart_Drv_LineStatusBufArray[InstanceId] = 0;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}


#if (STD_ON == UART_DRV_SOFTWARE_POLLING )
/**
 *
 * @brief      This function is polling handle wakeup signal.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
static void Uart_Drv_PollingHandlerWakeupSignal(uint8 InstanceId)
{
    const Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];

    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & (uint32)UART_DRV_LSI_DR ))
    {
        Uart_Drv_PollingFlagArray[InstanceId] &= 
                        (~(Uart_Drv_PollingMaskArray[UART_DRV_POLL_ASYNC]));
        if(UART_DRV_NODE_STATE_SLEEP_MODE == CrtTransferCfgPtr->CurrentNodeState)
        {
            Uart_Drv_CheckWakeupSignal(InstanceId, (Uart_Drv_ReceiveByte(InstanceId)));
        }
    }
}

/**
 *
 * @brief      This function is polling handle Line Status.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
static void Uart_Drv_PollingHandlerLineStatus(uint8 InstanceId)
{
    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LSI_DR))
    {
        /* Handle frame: master process and slave readback or slave is sw lin*/
        if(1U == Uart_Drv_LineStatusFlag[InstanceId])
        {
            Uart_Drv_LineStatusIrqHandler(InstanceId); 
        }
        else
        {
            /* HW salve not handle detect break,only handle readback */
            Uart_Drv_FrameTransceiverIrqHandler(InstanceId);
        }
    }
}

/**
 *
 * @brief      This function is polling handle Header Done.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
static void Uart_Drv_PollingHandlerHeaderDone(uint8 InstanceId)
{
    /* master enable header done interrupt and slave is hardware lin  */
    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_HEADER_DONE_FLG))
    {
        Uart_Drv_HandleHeaderDoneIrq(InstanceId);  
    }
}


/**
 *
 * @brief      This function is polling handle Header Done.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
static void Uart_Drv_PollingHandlerResponseDone(uint8 InstanceId)
{
    if(0U != (Uart_Drv_LineStatusBufArray[InstanceId] & UART_DRV_LIN_RSP_DONE_FLAG))
    {
        Uart_Drv_HandleResponseDoneIrq(InstanceId);
    }
}

/**
 *
 * @brief      This function is polling handle status flag.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
void Uart_Drv_PollingHandler(uint8 InstanceId)
{
    const Reg_Uart_BfType *UartBfPtr;
    const Reg_Uart_WType *UartWPtr ;
    uint32 IntId;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */

    UartBfPtr  = Uart_Drv_UartRegBfPtr[InstanceId];
    UartWPtr  = Uart_Drv_UartRegWPtr[InstanceId];
    Uart_Drv_LineStatusBufArray[InstanceId] = Uart_Drv_GetAllLineStatus(InstanceId);
    if(0U != (Uart_Drv_PollingFlagArray[InstanceId] & 
                Uart_Drv_PollingMaskArray[UART_DRV_POLL_ASYNC]))
    {
        Uart_Drv_PollingHandlerWakeupSignal(InstanceId);
    }
    if(0U != (Uart_Drv_PollingFlagArray[InstanceId]&Uart_Drv_PollingMaskArray[UART_DRV_POLL_RBFI]))
    {
        Uart_Drv_PollingHandlerLineStatus(InstanceId);
    }
    if(0U != (Uart_Drv_PollingFlagArray[InstanceId] & 
                Uart_Drv_PollingMaskArray[UART_DRV_POLL_HEADER_DONE]))
    {
        Uart_Drv_PollingHandlerHeaderDone(InstanceId);
    }
    if(0U != (Uart_Drv_PollingFlagArray[InstanceId]&
                Uart_Drv_PollingMaskArray[UART_DRV_POLL_RSP_DONE]))
    {
        Uart_Drv_PollingHandlerResponseDone(InstanceId);
    }

    /* clear iid  */
    IntId = UartBfPtr->UART_IIR_FCR.UART_IIR.IID;
    if(UART_DRV_INTSTA_IID_BYDET == IntId)
    {
        (void)UartWPtr->UART_USR;
    }

    Uart_Drv_LineStatusBufArray[InstanceId] = 0;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}
#endif


#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT )
/**
 *
 * @brief      Set Lin software simulation status to idle.
 *
 * @param[in]  InstanceId: Lin peripheral instance number
 *
 * @return     None
 *
 */
void Uart_Drv_SetSimulationStatusToIdle(const uint8 InstanceId)
{
    Uart_Drv_TransferConfigType *CrtTransferCfgPtr;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    /* Assert parameters. */
    MCALLIB_DEV_ASSERT(UART_DRV_INSTANCE_NUM > InstanceId);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */
    CrtTransferCfgPtr = Uart_Drv_TransferConfigArrayPtr[InstanceId];
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT )
    /* Check if current instance is already de-initialized or is gated.*/
    MCALLIB_DEV_ASSERT(NULL_PTR != CrtTransferCfgPtr);
#endif /* (STD_ON == UART_DRV_DEV_ERROR_DETECT ) */

    Uart_Drv_SetIdleState(InstanceId);
    CrtTransferCfgPtr->CurrentEventId = UART_DRV_NO_EVENT;
    CrtTransferCfgPtr->CntByte = 0U;
    CrtTransferCfgPtr->TxSize = 0U;
    CrtTransferCfgPtr->RxSize = 0U;
    CrtTransferCfgPtr->IsBusBusy = 0U;
    CrtTransferCfgPtr->CurrentPid = 0U;
#if (STD_ON == UART_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Public_FunctionDefinition */




#ifdef __cplusplus
}
#endif /* UART_DRV_C */


/** @} end of group Uart_Drv */

/** @} end of group Lin_Module */
