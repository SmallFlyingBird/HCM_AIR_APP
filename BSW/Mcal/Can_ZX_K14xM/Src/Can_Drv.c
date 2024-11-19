/***************************************************************************************************/
/**
 * @file      : Can_Drv.c
 * @brief     : Can low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Drv
 *  @brief Can low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Can_Drv.h"
#include "Device_Regs.h"
#include "SchM_Can.h"

#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
    #include "Dma_Drv.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CAN_DRV_C_VENDOR_ID                   0x00B3U
#define CAN_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define CAN_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define CAN_DRV_C_SW_MAJOR_VERSION            1U
#define CAN_DRV_C_SW_MINOR_VERSION            2U
#define CAN_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Can_Drv.h are of the same vendor */
#if (CAN_DRV_C_VENDOR_ID != CAN_DRV_H_VENDOR_ID)
    #error "Vendor ID of Can_Drv.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_DRV_C_AR_RELEASE_MAJOR_VERSION != CAN_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (CAN_DRV_C_AR_RELEASE_MINOR_VERSION != CAN_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (CAN_DRV_C_AR_RELEASE_REVISION_VERSION != CAN_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_Drv.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_DRV_C_SW_MAJOR_VERSION != CAN_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (CAN_DRV_C_SW_MINOR_VERSION != CAN_DRV_H_SW_MINOR_VERSION) ||                                 \
     (CAN_DRV_C_SW_PATCH_VERSION != CAN_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Can_Drv.c and Can_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are of the same Autosar version */
    #if ((CAN_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (CAN_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Can_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Can.h are of the same Autosar version */
    #if ((CAN_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_CAN_H_AR_RELEASE_MAJOR_VERSION) ||              \
         (CAN_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_CAN_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Can_Drv.c and SchM_Can.h are different"
    #endif
    #if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
        /* Check if current file and Dma_Drv.h are of the same Autosar version */
        #if ((CAN_DRV_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
             (CAN_DRV_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Can_Drv.c and Dma_Drv.h are different"
        #endif
    #endif
#endif

/** @defgroup CAN_Private_Defines
 *  @{
 */
#define CAN_DRV_ID_STD_MASK 0xDFFC0000U
#define CAN_DRV_ID_EXT_MASK 0xDFFFFFFFU

#define CAN_DRV_ESR1_BOFFINT_MASK  (0x4U)
#define CAN_DRV_CTRL1_BOFFMSK_MASK (0x8000U)

/* CAN FD extended Data length DLC encoding */
#define CAN_DRV_DLC_VALUE_12_BYTES 9U
#define CAN_DRV_DLC_VALUE_16_BYTES 10U
#define CAN_DRV_DLC_VALUE_20_BYTES 11U
#define CAN_DRV_DLC_VALUE_24_BYTES 12U
#define CAN_DRV_DLC_VALUE_32_BYTES 13U
#define CAN_DRV_DLC_VALUE_48_BYTES 14U
#define CAN_DRV_DLC_VALUE_64_BYTES 15U

/*copy to CAN Drv Configure*/

#define CAN_DRV_CAN05_MB_NUM           64U
#define CAN_DRV_CAN05_RAM_SIZE_IN_BYTE 1024U
#define CAN_DRV_CAN05_RAM_SIZE_IN_WORD (CAN_DRV_CAN05_RAM_SIZE_IN_BYTE >> 2U)
#define CAN_DRV_CAN67_MB_NUM           128U
#define CAN_DRV_CAN67_RAM_SIZE_IN_BYTE 2048U
#define CAN_DRV_CAN67_RAM_SIZE_IN_WORD (CAN_DRV_CAN67_RAM_SIZE_IN_BYTE >> 2U)


/**
 * @brief Default value for the CTRL2 register
 */
#define CAN_DRV_CTRL2_DEFAULT_VALUE ((uint32)0x00800000U)

/**
 * @brief Default Value for the CTRL1 register
 */
#define CAN_DRV_CTRL1_DEFAULT_VALUE ((uint32)0x00000000U)

/**
 * @brief Default Value for the CBT register
 */
#define CAN_DRV_CBT_DEFAULT_VALUE ((uint32)0x00000000U)

/**
 * @brief Default Value for the FDCTRL register
 */
#define CAN_DRV_FDCTRL_DEFAULT_VALUE ((uint32)0x80004100U)

/**
 * @brief Default Value for the FDCBT register
 */
#define CAN_DRV_FDCBT_DEFAULT_VALUE ((uint32)0x00000000U)


/*CAN FIFO Address*/
#define CAN_DRV_RAM_RX_FIFO_ADDR           0xA80U
#define CAN_DRV_RAM_RX_FIFO_LEN_IN_WORD    6U
#define CAN_DRV_RAM_MSK_ADDR               0xAA0U
#define CAN_DRV_RAM_MSK_LEN_IN_WORD        4U
#define CAN_DRV_RAM_RX_SMB_ADDR            0xAB0U
#define CAN_DRV_RAM_RX_SMB_LEN_IN_WORD     12U
#define CAN_DRV_RAM_FD_SCRATCH_ADDR        0xF28U
#define CAN_DRV_RAM_FD_SCRATCH_LEN_IN_WORD 54U

#define CAN_DRV_INT_MSK_BUS_OFF           ((uint32)1U << 15U)
#define CAN_DRV_INT_MSK_ERR               ((uint32)1U << 14U)
#define CAN_DRV_INT_MSK_TXW               ((uint32)1U << 11U)
#define CAN_DRV_INT_MSK_RXW               ((uint32)1U << 10U)
#define CAN_DRV_INT_MSK_BUS_OFF_DONE      ((uint32)1U << 30U)
#define CAN_DRV_INT_MSK_ERR_FAST          ((uint32)1U << 31U)
#define CAN_DRV_INT_MSK_HOST_MEM_ERR      ((uint32)1U << 19U)
#define CAN_DRV_INT_MSK_CAN_MEM_ERR       ((uint32)1U << 18U)
#define CAN_DRV_INT_MSK_COR_MEM_ERR       ((uint32)1U << 16U)
#define CAN_DRV_INT_MSK_PN_WAKEUP_MATCH   ((uint32)1U << 16U)
#define CAN_DRV_INT_MSK_PN_WAKEUP_TIMEOUT ((uint32)1U << 17U)
#define CAN_DRV_INT_MSK_MULTI_1                                                                    \
    (CAN_DRV_INT_MSK_BUS_OFF | CAN_DRV_INT_MSK_ERR | CAN_DRV_INT_MSK_TXW | CAN_DRV_INT_MSK_RXW)
#define CAN_DRV_INT_MSK_MULTI_2 (CAN_DRV_INT_MSK_BUS_OFF_DONE | CAN_DRV_INT_MSK_ERR_FAST)
#define CAN_DRV_INT_MSK_MULTI_ECC                                                                  \
    (CAN_DRV_INT_MSK_HOST_MEM_ERR | CAN_DRV_INT_MSK_CAN_MEM_ERR | CAN_DRV_INT_MSK_COR_MEM_ERR)
#define CAN_DRV_INT_MSK_MULTI_PN                                                                   \
    (CAN_DRV_INT_MSK_PN_WAKEUP_MATCH | CAN_DRV_INT_MSK_PN_WAKEUP_TIMEOUT)

#define CAN_DRV_INT_MSK_FLAG_BUS_OFF           ((uint32)1U << 2U)
#define CAN_DRV_INT_MSK_FLAG_ERR               ((uint32)1U << 1U)
#define CAN_DRV_INT_MSK_FLAG_TXW               ((uint32)1U << 17U)
#define CAN_DRV_INT_MSK_FLAG_RXW               ((uint32)1U << 16U)
#define CAN_DRV_INT_MSK_FLAG_BUS_OFF_DONE      ((uint32)1U << 19U)
#define CAN_DRV_INT_MSK_FLAG_ERR_FAST          ((uint32)1U << 20U)
#define CAN_DRV_INT_MSK_FLAG_SELF_WAKEUP       1U
#define CAN_DRV_INT_MSK_FLAG_HOST_MEM_ERR      ((uint32)1U << 19U)
#define CAN_DRV_INT_MSK_FLAG_CAN_MEM_ERR       ((uint32)1U << 18U)
#define CAN_DRV_INT_MSK_FLAG_COR_MEM_ERR       ((uint32)1U << 16U)
#define CAN_DRV_INT_MSK_FLAG_PN_WAKEUP_MATCH   ((uint32)1U << 16U)
#define CAN_DRV_INT_MSK_FLAG_PN_WAKEUP_TIMEOUT ((uint32)1U << 17U)
#define CAN_DRV_ECC_OVERRUN_ERROR_SHIFT        ((uint32)16U)

#define CAN_DRV_INT_MSK_FLAG_ALL_1                                                                 \
    (CAN_DRV_INT_MSK_FLAG_BUS_OFF | CAN_DRV_INT_MSK_FLAG_ERR | CAN_DRV_INT_MSK_FLAG_TXW |          \
     CAN_DRV_INT_MSK_FLAG_RXW | CAN_DRV_INT_MSK_FLAG_BUS_OFF_DONE |                                \
     CAN_DRV_INT_MSK_FLAG_ERR_FAST | CAN_DRV_INT_MSK_FLAG_SELF_WAKEUP)
#define CAN_DRV_INT_MSK_FLAG_ALL_ECC                                                               \
    (CAN_DRV_INT_MSK_FLAG_HOST_MEM_ERR | CAN_DRV_INT_MSK_FLAG_CAN_MEM_ERR |                        \
     CAN_DRV_INT_MSK_FLAG_COR_MEM_ERR)
#define CAN_DRV_INT_MSK_FLAG_ALL_PN                                                                \
    (CAN_DRV_INT_MSK_FLAG_PN_WAKEUP_MATCH | CAN_DRV_INT_MSK_FLAG_PN_WAKEUP_TIMEOUT)

#define CAN_DRV_CAL_RX_MB_STD_MASK(Mask)    ((Mask)&CAN_DRV_ID_STD_MASK)
#define CAN_DRV_CAL_RX_MB_EXT_MASK(Mask)    ((Mask)&CAN_DRV_ID_EXT_MASK)
#define CAN_DRV_RX_FIFO_OCUP_LAST_MB_NUM(x) (5U + ((((x) + 1U) * 8U) >> 2U))

#define CAN_DRV_SWAP_BYTES_IN_WORD_INDEX(index) (((index) & ~3U) + (3U - ((index)&3U)))
#define CAN_DRV_SWAP_BYTES_IN_WORD(a, b)        CAN_DRV_REV_BYTES_32(a, b)
#define CAN_DRV_REV_BYTES_32(a, b)                                                                 \
    ((b) = (((a)&0xFF000000U) >> 24U) | (((a)&0xFF0000U) >> 8U) | (((a)&0xFF00U) << 8U) |          \
           (((a)&0xFFU) << 24U))

#define CAN_DRV_RXFIFO_FRAME_AVAILABLE (5U)
#define CAN_DRV_RXFIFO_WARNING         (6U)
#define CAN_DRV_RXFIFO_OVERFLOW        (7U)

/*Cs Status*/
#define CAN_DRV_CS_CODE_MASK  ((uint32)0x0F000000U)
#define CAN_DRV_CS_CODE_SHIFT 24U

/* can error injection */
#define CAN_DRV_ERRINJECT_SIG_PARIYT   (0x00000001U)
#define CAN_DRV_ERRINJECT_SIG_DATA     (0x00000001U)
#define CAN_DRV_ERRINJECT_DEFAULT      (0x00000000U)

/*CAN transceiver delay compensation */
#define CAN_DRV_TDCEN_MASK                      (0x8000U)
#define CAN_DRV_TDCFAIL_MASK                    (0x4000U)
#define CAN_DRV_BIT_RATE_SWITCH_MASK            (0x80000000U)
#define CAN_DRV_TDCOFF_MASK                     ((uint32)0x1F00U)
#define CAN_DRV_TDCOFF_SHIFT                    ((uint32)8U)
#define CAN_DRV_TDCEN_SHIFT                     ((uint32)15U)
#define CAN_DRV_MB_REGION_0_SHIFT               ((uint32)16U)
#define CAN_DRV_MB_REGION_1_SHIFT               ((uint32)19U)
#define CAN_DRV_MB_REGION_2_SHIFT               ((uint32)22U)
#define CAN_DRV_MB_REGION_3_SHIFT               ((uint32)25U)
#define CAN_DRV_FDCTRL_MBDSR0_MASK              ((uint32)3U << CAN_DRV_MB_REGION_0_SHIFT)
#define CAN_DRV_FDCTRL_MBDSR1_MASK              ((uint32)3U << CAN_DRV_MB_REGION_1_SHIFT)
#define CAN_DRV_FDCTRL_MBDSR2_MASK              ((uint32)3U << CAN_DRV_MB_REGION_2_SHIFT)
#define CAN_DRV_FDCTRL_MBDSR3_MASK              ((uint32)3U << CAN_DRV_MB_REGION_3_SHIFT)
#define CAN_DRV_BIT_RATE_SWITCH_SHIFT           ((uint32)31U)
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

typedef enum
{
    CAN_DRV_GET_INT_FLAG = 0U, /* Get interrupt flag */
    CAN_DRV_GET_INT_STATUS     /* Get interrupt status */
} Can_Drv_GetIntType;

/**
 *  @brief message buffer struct
 */
typedef volatile struct
{
    union {
        struct
        {
            uint32 TIME_STAMP : 16; /* [15:0]                    */
            uint32 DLC        : 4;  /* [19:16]                   */
            uint32 RTR        : 1;  /* [20]                      */
            uint32 IDE        : 1;  /* [21]                      */
            uint32 SRR        : 1;  /* [22]                      */
            uint32 RSVD_23    : 1;  /* [23]                      */
            uint32 CODE       : 4;  /* [27:24]                   */
            uint32 RSVD_28    : 1;  /* [28]                      */
            uint32 ESI        : 1;  /* [29]                      */
            uint32 BRS        : 1;  /* [30]                      */
            uint32 EDL        : 1;  /* [31]                      */
        } BF;
        uint32 WORDVAL;
    } Config;

    /* 0x84*/
    union {
        struct
        {
            uint32 ID_EXTEND   : 18; /* [17:0]                    */
            uint32 ID_STANDARD : 11; /* [28:18]                   */
            uint32 PRIO        : 3;  /* [31:29]                   */
        } BF;
        uint32 WORDVAL;
    } Id;

    uint32 Data[16];
} Can_Drv_MbType;

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define CAN_START_SEC_CONST_PTR
#include "Can_MemMap.h"

static Reg_Can_BfType *const Can_Drv_CanRegBfPtr[CAN_DRV_TOTAL_NUM] = {
    (Reg_Can_BfType *)CAN0_BASE_ADDR, (Reg_Can_BfType *)CAN1_BASE_ADDR,
    (Reg_Can_BfType *)CAN2_BASE_ADDR, (Reg_Can_BfType *)CAN3_BASE_ADDR,
#if (CAN_DRV_TOTAL_NUM > 6)
    (Reg_Can_BfType *)CAN4_BASE_ADDR, (Reg_Can_BfType *)CAN5_BASE_ADDR,
    (Reg_Can_BfType *)CAN6_BASE_ADDR, (Reg_Can_BfType *)CAN7_BASE_ADDR,
#elif (CAN_DRV_TOTAL_NUM > 4)
    (Reg_Can_BfType *)CAN4_BASE_ADDR, (Reg_Can_BfType *)CAN5_BASE_ADDR,
#endif
};

static Reg_Can_WType *const Can_Drv_CanRegWPtr[CAN_DRV_TOTAL_NUM] = {
    (Reg_Can_WType *)CAN0_BASE_ADDR, (Reg_Can_WType *)CAN1_BASE_ADDR,
    (Reg_Can_WType *)CAN2_BASE_ADDR, (Reg_Can_WType *)CAN3_BASE_ADDR,
#if (CAN_DRV_TOTAL_NUM > 6)
    (Reg_Can_WType *)CAN4_BASE_ADDR, (Reg_Can_WType *)CAN5_BASE_ADDR,
    (Reg_Can_WType *)CAN6_BASE_ADDR, (Reg_Can_WType *)CAN7_BASE_ADDR,
#elif (CAN_DRV_TOTAL_NUM > 4)
    (Reg_Can_WType *)CAN4_BASE_ADDR, (Reg_Can_WType *)CAN5_BASE_ADDR,
#endif
};

#define CAN_STOP_SEC_CONST_PTR
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"
/* Pointer to runtime State structure.*/
static Can_Drv_StateType *Can_Drv_StatePtr[CAN_DRV_TOTAL_NUM];

#define CAN_STOP_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
static Dma_Drv_ChannelTransferConfigType Can_Drv_DmaTransferConfig[CAN_DRV_TOTAL_NUM];
static Dma_Drv_AddrConfigType Can_Drv_DmaSourceConfig[CAN_DRV_TOTAL_NUM];
static Dma_Drv_AddrConfigType Can_Drv_DmaDestinationConfig[CAN_DRV_TOTAL_NUM];
static Dma_Drv_TransferControlConfigType Can_Drv_DmaControlConfig[CAN_DRV_TOTAL_NUM];
#endif

#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"

static volatile uint32 Can_Drv_InterMaskBuff[CAN_DRV_TOTAL_NUM][CAN_DRV_FEATURE_MBDSR_COUNT];

#define CAN_STOP_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
static void Can_Drv_DmaHandle(uint8 Id);

static void Can_Drv_ConfigDma(uint8 Id);

static void Can_Drv_CallbackForDma(uint8 Id);

static void Can_Drv_ClearOutputRxFIFO(uint8 Id);

static void Can_Drv_CallbackForDmaError(uint8 Id);
#endif

static uint8 Can_Drv_GetMbNum(uint8 Id);

static void Can_Drv_CompleteRxFifoData(uint8 Id);

static Can_Drv_ControllerStatus Can_Drv_AbortRxTransfer(uint8 Id, uint8 MbIdx);

static Can_Drv_ControllerStatus Can_Drv_AbortTxTransfer(uint8 Id, uint8 MbIdx);

static Can_Drv_ControllerStatus Can_Drv_CheckMbId(uint8 Id, uint32 MbIdx);

static Can_Drv_ControllerStatus Can_Drv_CheckMbIdRange(uint8 Id, uint32 MbIdx);

static Can_Drv_ControllerStatus Can_Drv_ClearMessageBufferIntFlag(uint8 Id, uint32 MbIdx);

static void Can_Drv_ComputeDlcAndDataSize(uint32 DataLen, uint32 *DlcPtr, uint32 *DataSizePtr);

static uint8 Can_Drv_ComputePayloadSize(uint8 DlcValue);

static Can_Drv_ControllerStatus Can_Drv_Disable(uint8 Id);

static Can_Drv_ControllerStatus Can_Drv_Enable(uint8 Id);

static boolean Can_Drv_GetInterruptInfoFromBlock0(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType);

static boolean Can_Drv_GetMbInterruptStateFromBlock0(uint8 Id, uint32 MbIdx);

static boolean Can_Drv_GetMbInterruptStateFromBlock1(uint8 Id, uint32 MbIdx);

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64U)
static boolean Can_Drv_GetMbInterruptStateFromBlock2(uint8 Id, uint32 MbIdx);
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96U)
static boolean Can_Drv_GetMbInterruptStateFromBlock3(uint8 Id, uint32 MbIdx);
#endif

static boolean Can_Drv_GetInterruptInfoFromBlock1(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType);

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64U)
static boolean Can_Drv_GetInterruptInfoFromBlock2(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType);
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96U)
static boolean Can_Drv_GetInterruptInfoFromBlock3(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType);
#endif

static boolean Can_Drv_ReadMbInterruptStatus(uint8 Id, uint32 MbIdx);

static boolean Can_Drv_ProcessMbIrqSource(uint8 Id, uint32 StartMbIdx, uint32 EndMbIdx);

LOCAL_INLINE boolean Can_Drv_ReadMbInterruptFlag(uint8 Id, uint32 MbIdx);

static Can_Drv_ControllerStatus
Can_Drv_GetMbAddr(uint8 Id, uint8 MbIdx, Can_Drv_FdMbRegionType *Region, Can_Drv_MbType **Addr);

static uint32 Can_Drv_GetTimeStamp(uint8 Id, uint8 MbIdx);

static void Can_Drv_ComputeFifoModeATable(uint8 Id, uint32 Number,
                                          const Can_Drv_IdFilterType *IdFilterTable);

static void Can_Drv_ComputeFifoModeBTable(uint8 Id, uint32 Number,
                                          const Can_Drv_IdFilterType *IdFilterTable);

static void Can_Drv_ComputeFifoModeCTable(uint8 Id, uint32 Number,
                                          const Can_Drv_IdFilterType *IdFilterTable);

static void Can_Drv_ConfigRxFifoFilter(uint8 Id, Can_Drv_RxAcceptanceType Format,
                                       const Can_Drv_IdFilterType *IdFilterTable);

static void Can_Drv_UnmaskInterrupt(uint8 Id);

static void Can_Drv_MaskInterrupt(uint8 Id);

static void Can_Drv_ReadRxFifo(uint8 Id, Can_Drv_MsgBufType *MsgBuf);

static void Can_Drv_GetMsgBuff(uint8 Id, uint8 MbIdx, Can_Drv_MsgBufType *MsgBuf);

static uint32 Can_Drv_GetMsgBuffTimeStamp(uint8 Id, uint8 MbIdx);

static void Can_Drv_ProcessErrorIntConfigure(uint8 Id, uint32 Mask, boolean Enable);
static void Can_Drv_ProcessEccIntConfigure(uint8 Id, uint32 Mask, boolean Enable);
static Can_Drv_ControllerStatus Can_Drv_ExecuteSoftReset(uint8 Id);

static void Can_Drv_ClearRam(uint8 Id);

LOCAL_INLINE void Can_Drv_ResetConfiguration(uint8 Id);

static void Can_Drv_ConfigMbInterruptBlock0(uint8 Id, uint8 MbIdx, boolean Enable,
                                            boolean IsActive);

static void Can_Drv_ConfigMbInterruptBlock1(uint8 Id, uint8 MbIdx, boolean Enable,
                                            boolean IsActive);

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
static void Can_Drv_ConfigMbInterruptBlock2(uint8 Id, uint8 MbIdx, boolean Enable,
                                            boolean IsActive);
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
static void Can_Drv_ConfigMbInterruptBlock3(uint8 Id, uint8 MbIdx, boolean Enable,
                                            boolean IsActive);
#endif

static void Can_Drv_ConfigMbInterrupt(uint8 Id, uint8 MbIdx, boolean Enable, boolean IsActive);

static boolean Can_Drv_GetMbInterruptState(uint8 Id, uint8 MbIdx);

static Can_Drv_ControllerStatus Can_Drv_SetErrorInterruptState(uint8 Id, Can_Drv_IntType IntType,
                                                               boolean Enable);

static Can_Drv_ControllerStatus Can_Drv_SetRxMb(uint8 Id, uint8 MbIdx, Can_Drv_MsgIdType IdType,
                                                uint32 MsgId, uint32 Code);

static void Can_Drv_ProcessSetTxMbBuffer(Can_Drv_MbType                *MbAddr,
                                         const Can_Drv_MessageInfoType *MessageInfo, uint32 MsgId,
                                         const uint8 *MsgData, uint32 Code, uint8 LocalPrio);

static Can_Drv_ControllerStatus Can_Drv_SetTxMb(uint8 Id, uint8 MbIdx,
                                                const Can_Drv_MessageInfoType *MessageInfo,
                                                uint32 MsgId, const uint8 *MsgData, uint32 Code,
                                                uint8 LocalPrio);

static Can_Drv_ControllerStatus Can_Drv_ProcessTxMb(const Can_Drv_MbType *MbAddr, uint8 Id,
                                                    uint8                          MbIdx,
                                                    const Can_Drv_MessageInfoType *TxInfo,
                                                    boolean IsPolling, uint32 MsgId,
                                                    const uint8 *MsgData);

static Can_Drv_ControllerStatus Can_Drv_SetStandardBitTiming(uint8                        Id,
                                                             const Can_Drv_BitTimingType *TimeSeg);

static Can_Drv_ControllerStatus
Can_Drv_SetFdArbitrationBitTiming(uint8 Id, const Can_Drv_BitTimingType *TimeSeg);

static Can_Drv_ControllerStatus Can_Drv_ConfigFdDataBitTiming(uint8                        Id,
                                                              const Can_Drv_BitTimingType *TimeSeg);

static uint8 Can_Drv_GetPayloadSize(uint8 Id, Can_Drv_FdMbRegionType Region);

static uint8 Can_Drv_GetMaxMbNumLimit(uint8 Id);

static Can_Drv_ControllerStatus Can_Drv_EnterFreezeMode(uint8 Id);

static Can_Drv_ControllerStatus Can_Drv_ExitFreezeMode(uint8 Id);

static Can_Drv_ControllerStatus Can_Drv_SoftResetController(uint8 Id);

static void Can_Drv_SetGlobalConfig(uint8 Id, const Can_Drv_ConfigType *ConfigPtr);

static Can_Drv_ControllerStatus Can_Drv_SetBaudRate(uint8 Id, const Can_Drv_ConfigType *ConfigPtr);

static Can_Drv_ControllerStatus Can_Drv_SetFifoParameter(uint8                     Id,
                                                         const Can_Drv_ConfigType *ConfigPtr);

static Can_Drv_ControllerStatus Can_Drv_SetMode(uint8 Id, const Can_Drv_ConfigType *ConfigPtr);

static Can_Drv_ControllerStatus Can_Drv_InitHandle(uint8 Id, const Can_Drv_ConfigType *ConfigPtr);

static Can_Drv_ControllerStatus Can_Drv_SetOperationMode(uint8 Id, Can_Drv_ModeType Mode);

static void Can_Drv_RxFifoIrqHandler(uint8 Id, uint8 MbIdx);

static void Can_Drv_UnlockRxMsgBuff(uint8 Id);

static void Can_Drv_RxMbIrqHandler(uint8 Id, uint8 MbIdx);

static void Can_Drv_TxMbIrqHandler(uint8 Id, uint8 MbIdx);

static void Can_Drv_ProcessMbAbnormalInter(uint8 Id, boolean IsAbnormal, uint32 StartMbIdx,
                                           uint32 EndMbIdx);

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
/**
 * @brief     This function is used for dma processing.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 */
static void Can_Drv_DmaHandle(uint8 Id)
{
    Can_Drv_StateType *StatePtr = Can_Drv_StatePtr[Id];
    uint32                   Tmp1 = 0U;
    uint32                   Tmp2 = 0U;
    Can_Drv_MsgBufType      *DmaMessagePtr;

    DmaMessagePtr = StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr;
    Tmp1 = (uint32)((uint32)DmaMessagePtr->Data[0U] | ((uint32)DmaMessagePtr->Data[1U] << 8U) |
                    ((uint32)DmaMessagePtr->Data[2U] << 16U) |
                    ((uint32)DmaMessagePtr->Data[3U] << 24U));

    Tmp2 = (uint32)((uint32)DmaMessagePtr->Data[4U] | ((uint32)DmaMessagePtr->Data[5U] << 8U) |
                    ((uint32)DmaMessagePtr->Data[6U] << 16U) |
                    ((uint32)DmaMessagePtr->Data[7U] << 24U));
    /* Adjust the ID if it is not extended */
    if (0U == ((DmaMessagePtr->Cs) & 0x00200000U))
    {
        DmaMessagePtr->MsgId = (DmaMessagePtr->MsgId >> 18U);
    }

    /* Extract the Data length */
    DmaMessagePtr->DataLen = (uint8)((DmaMessagePtr->Cs & 0x000F0000U) >> 16);
    /* Extract the Time Stamp */
    DmaMessagePtr->TimeStamp = (uint32)(DmaMessagePtr->Cs & 0x0000FFFFU);

    /* Reverse the endianness */
    CAN_DRV_SWAP_BYTES_IN_WORD(Tmp1, Tmp1);
    DmaMessagePtr->Data[0U] = (uint8)(Tmp1 & 0xFFU);
    DmaMessagePtr->Data[1U] = (uint8)(Tmp1 >> 8U);
    DmaMessagePtr->Data[2U] = (uint8)(Tmp1 >> 16U);
    DmaMessagePtr->Data[3U] = (uint8)(Tmp1 >> 24U);
    CAN_DRV_SWAP_BYTES_IN_WORD(Tmp2, Tmp2);
    DmaMessagePtr->Data[4U] = (uint8)(Tmp2 & 0xFFU);
    DmaMessagePtr->Data[5U] = (uint8)(Tmp2 >> 8U);
    DmaMessagePtr->Data[6U] = (uint8)(Tmp2 >> 16U);
    DmaMessagePtr->Data[7U] = (uint8)(Tmp2 >> 24U);
    
}

/**
 * @brief     This function configures the RX DMA channels according to current transfer
 * configuration.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
static void Can_Drv_ConfigDma(uint8 Id)
{
    const Can_Drv_StateType           *StatePtr = Can_Drv_StatePtr[Id];
    Dma_Drv_ChannelTransferConfigType *DmaTransferConfigPtr = &Can_Drv_DmaTransferConfig[Id];
    DmaTransferConfigPtr->SourceConfig = &Can_Drv_DmaSourceConfig[Id];
    DmaTransferConfigPtr->DestinationConfig = &Can_Drv_DmaDestinationConfig[Id];
    DmaTransferConfigPtr->ControlConfig = &Can_Drv_DmaControlConfig[Id];

    /* source address */
    DmaTransferConfigPtr->SourceConfig->Addr = (((uint32)Can_Drv_CanRegBfPtr[Id]) + (uint32)0x80UL);
    /* source minorloop offset */
    DmaTransferConfigPtr->SourceConfig->MinorLoopOffset = (sint16)4U;
    /* source majorloop offset */
    DmaTransferConfigPtr->SourceConfig->MajorLoopOffset = (sint16)0U;
    /* source transfer size */
    DmaTransferConfigPtr->SourceConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_4BYTE;

    /* destination address */
    DmaTransferConfigPtr->DestinationConfig->Addr =
        (uint32)(StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr);
    /* destination minor loop offset */
    DmaTransferConfigPtr->DestinationConfig->MinorLoopOffset = (sint16)4U;
    /* destination major loop offset */
    DmaTransferConfigPtr->DestinationConfig->MajorLoopOffset = (sint16)0U;
    /* destination transfer size */
    DmaTransferConfigPtr->DestinationConfig->TransferSize = DMA_DRV_TRANSFER_SIZE_4BYTE;
    /* transfer number in a minor loop */
    DmaTransferConfigPtr->ControlConfig->TransferNum = 16U;
    /* minor loop count in a major loop */
    DmaTransferConfigPtr->ControlConfig->MinorLoopCnt = 1U;
    /* auto disable request control */
    DmaTransferConfigPtr->ControlConfig->ReqDis = (boolean)TRUE;

    /* DMA transfer configure */
    Dma_Drv_SetChannelTransferConfig((Dma_Drv_ChannelType)StatePtr->RxFifoDMAChannel,
                                     (Dma_Drv_ChannelTransferConfigType *)DmaTransferConfigPtr);
    /* Enable dma Channel request*/
    Dma_Drv_EnableChannelRequest((Dma_Drv_ChannelType)StatePtr->RxFifoDMAChannel);
}

/**
 * @brief     DMA callback function.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 */
static void Can_Drv_CallbackForDma(uint8 Id)
{
    Can_Drv_CompleteRxFifoData(Id);
}

/**
 * @brief     DMA error callback function.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 */
static void Can_Drv_CallbackForDmaError(uint8 Id)
{
    Can_Drv_StateType *StatePtr;
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];

    StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State = CAN_DRV_STATE_DMA_ERROR;
    /* Clear fifo message*/
    StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr = NULL_PTR;

    if (StatePtr->IrqCallback != NULL_PTR)
    {
        StatePtr->IrqCallback(Id, CAN_DRV_DMA_ERROR, CAN_DRV_RXFIFO_START_INDEX, StatePtr);
    }
    
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Clear output of rx fifo.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     None
 *
 */
static void Can_Drv_ClearOutputRxFIFO(uint8 Id)
{
    Reg_Can_WType                 *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    const volatile Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    uint8 Index = 0U;

    if (TRUE == Can_Drv_ReadMbInterruptFlag(Id, CAN_DRV_RXFIFO_FRAME_AVAILABLE))
    {
        (void)Can_Drv_EnterFreezeMode(Id);

        CanRegisterWPtr->CAN_IFLAG1 = 0x01;

        if (1U == (CanRegisterBfPtr->CAN_MCR.DMAE))
        {
            do
            {
                /* DMA reading process must end by reading address 0x8c  */
              (void)CanRegisterBfPtr->CAN_MB[0].CAN_MB_DATA47.DATA_BYTE47;
                Index++;
            }
            while ((TRUE == Can_Drv_ReadMbInterruptFlag(Id, CAN_DRV_RXFIFO_FRAME_AVAILABLE)) &&
                   (Index <= (uint8)12U)); /* avoid blocking */
        }

        (void)Can_Drv_ClearMessageBufferIntFlag(Id, CAN_DRV_RXFIFO_FRAME_AVAILABLE);
        (void)Can_Drv_ClearMessageBufferIntFlag(Id, CAN_DRV_RXFIFO_WARNING);
        (void)Can_Drv_ClearMessageBufferIntFlag(Id, CAN_DRV_RXFIFO_OVERFLOW);

        /* Return CAN to normal Mode */
        (void)Can_Drv_ExitFreezeMode(Id);
    }
}
#endif

/**
 * @brief      Returns the maximum number of MB of the given controller.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     uint8: Number of the given controller message buffers.
 *
 */
static uint8 Can_Drv_GetMbNum(uint8 Id)
{
    uint8 CanMbNumber = 0U;

    if (Id < (uint8)CAN_DRV_ID_6)
    {
        CanMbNumber = (uint8)CAN_DRV_CAN05_MB_NUM;
    }
    else
    {
        CanMbNumber = (uint8)CAN_DRV_CAN67_MB_NUM;
    }

    return CanMbNumber;
}

/**
 * @brief      Finish up a receive by completing the process of receiving
 *             rx fifo Data and disabling the interrupt.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     None
 *
 */
static void Can_Drv_CompleteRxFifoData(uint8 Id)
{
    Can_Drv_StateType *StatePtr;
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    if (CAN_DRV_RXFIFO_INTERRUPTS == StatePtr->TransferType)
    {
        /* Disable RX FIFO interrupts*/
        Can_Drv_ConfigMbInterrupt(Id, CAN_DRV_RXFIFO_FRAME_AVAILABLE, (boolean)FALSE,
                                  StatePtr->InterEn);
        Can_Drv_ConfigMbInterrupt(Id, CAN_DRV_RXFIFO_WARNING, (boolean)FALSE, StatePtr->InterEn);
        Can_Drv_ConfigMbInterrupt(Id, CAN_DRV_RXFIFO_OVERFLOW, (boolean)FALSE,
                                  StatePtr->InterEn); /* Clear fifo message*/
    }
#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
    else if (CAN_DRV_RXFIFO_DMA == StatePtr->TransferType)
    {
        Can_Drv_DmaHandle(Id);
    }
    else
    {
        /* Nothing to do */
    }
#endif
    /* Clear fifo message*/
    StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr = NULL_PTR;

#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
    StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State = CAN_DRV_STATE_IDLE;
    if ((StatePtr->IrqCallback != NULL_PTR) && (CAN_DRV_RXFIFO_DMA == StatePtr->TransferType))
    {
        StatePtr->IrqCallback(Id, CAN_DRV_DMA_COMPLETE, CAN_DRV_RXFIFO_START_INDEX, StatePtr);
    }
#else
    StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State = CAN_DRV_STATE_IDLE;
#endif
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Aborts transfer for Rx normal or legacy fifo if enabled.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Transfer for Rx normal or legacy fifo aborted success.
 * @retval     CAN_DRV_ERROR: Transfer for Rx normal or legacy fifo aborted failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_AbortRxTransfer(uint8 Id, uint8 MbIdx)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_FdMbRegionType         Region;
    Can_Drv_MbType                *MbAddrPtr;
    /* Variable of return Status. */
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    const Can_Drv_StateType *StatePtr = Can_Drv_StatePtr[Id];

    if (TRUE == StatePtr->RxFifoEn)
    {
#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
        if ((CAN_DRV_RXFIFO_START_INDEX == MbIdx) && (CAN_DRV_RXFIFO_DMA == StatePtr->TransferType))
        {
            Dma_Drv_DisableChannelRequest((Dma_Drv_ChannelType)(StatePtr->RxFifoDMAChannel));
        }
#endif
        if (MbIdx <= CAN_DRV_RX_FIFO_OCUP_LAST_MB_NUM(CanRegisterBfPtr->CAN_CTRL2.RFFN))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }

    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        if (CAN_DRV_ERROR == Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddrPtr))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
        else
        {
            if (CAN_DRV_ERROR == Can_Drv_CheckMbId(Id, MbIdx))
            {
                ReturnValue = CAN_DRV_ERROR;
            }
            else
            {
                MbAddrPtr->Config.BF.CODE = (uint32)CAN_DRV_MB_RX_INACTIVE;
                MbAddrPtr->Config.BF.CODE = (uint32)CAN_DRV_MB_RX_EMPTY;
            }
        }
    }

    /* Clear message buffer Flag */
    (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

    return ReturnValue;
}

/**
 * @brief      Aborts transfer for Tx.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Tx transfer aborted success.
 * @retval     CAN_DRV_ERROR: Tx transfer aborted failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_AbortTxTransfer(uint8 Id, uint8 MbIdx)
{
    Can_Drv_FdMbRegionType   Region;
    Can_Drv_MbType          *MbAddrPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   Code = (uint32)CAN_DRV_MB_TX_INACTIVE;
    uint32                   TimeElapsedValue = 0U;
    uint32                   TimeCounter = 0U;
    uint32                   CurrentValue;
    uint32                   CanTimeoutDuration;

    if (CAN_DRV_ERROR == Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddrPtr))
    {
        ReturnValue = CAN_DRV_ERROR;
    }
    else
    {
        if (CAN_DRV_ERROR == Can_Drv_CheckMbId(Id, MbIdx))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
        else
        {
            MbAddrPtr->Config.BF.CODE = (uint32)CAN_DRV_MB_TX_ABORT;
            CanTimeoutDuration =
                McalLib_MicroSecToTicks(CAN_DRV_SERVICE_TIMEOUT_TYPE, CAN_DRV_TIMEOUT_DURATION);
            /* Wait for the transmission was aborted or transmitted */
            (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);
            while (FALSE == Can_Drv_ReadMbInterruptFlag(Id, MbIdx))
            {
                (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                              &TimeElapsedValue);
                TimeCounter += TimeElapsedValue;
                if (TimeCounter > CanTimeoutDuration)
                {
                    ReturnValue = CAN_DRV_ERROR;
                    break;
                }
            }

            if (CAN_DRV_SUCCESS == ReturnValue)
            {
                Code = MbAddrPtr->Config.BF.CODE;
            }

            if ((uint32)CAN_DRV_MB_TX_INACTIVE == Code)
            {
                ReturnValue = CAN_DRV_ERROR;
            }
            else if ((uint32)CAN_DRV_MB_TX_ABORT == Code)
            {
                ReturnValue = CAN_DRV_SUCCESS;
            }
            else
            {
                ReturnValue = CAN_DRV_SUCCESS;
            }
        }
    }

    /* Clear message buffer Flag */
    (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

    return ReturnValue;
}

/**
 * @brief      Checks if the given MB index is valid.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: The given MB index is valid.
 * @retval     CAN_DRV_ERROR: The given MB index is not valid.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_CheckMbId(uint8 Id, uint32 MbIdx)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_SUCCESS;
    uint8                          CanMBNumber = Can_Drv_GetMbNum(Id);

    if ((MbIdx > CanRegisterBfPtr->CAN_MCR.MAXMB) || (MbIdx >= CanMBNumber))
    {
        ReturnValue = CAN_DRV_ERROR;
    }

    if (CanRegisterBfPtr->CAN_MCR.RFEN != 0U)
    {
        if (MbIdx <= CAN_DRV_RX_FIFO_OCUP_LAST_MB_NUM((uint32)CanRegisterBfPtr->CAN_CTRL2.RFFN))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }

    return ReturnValue;
}

/**
 * @brief      Checks if the given MB index is out of range.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: The given MB index is not out of range.
 * @retval     CAN_DRV_ERROR: The given MB index is out of range.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_CheckMbIdRange(uint8 Id, uint32 MbIdx)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_SUCCESS;

    if ((MbIdx > CanRegisterBfPtr->CAN_MCR.MAXMB) || (MbIdx >= Can_Drv_GetMbNum(Id)))
    {
        ReturnValue = CAN_DRV_ERROR;
    }

    return ReturnValue;
}

/**
 * @brief     Clears MB interrupt flag.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: MB interrupt flag cleared success.
 * @retval     CAN_DRV_ERROR: MB interrupt flag cleared failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_ClearMessageBufferIntFlag(uint8 Id, uint32 MbIdx)
{
    Reg_Can_WType           *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   Flag = ((uint32)1U << (MbIdx % 32U));

    if (MbIdx < 32U)
    {
        CanRegisterWPtr->CAN_IFLAG1 = Flag;
    }
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32)
    else if (MbIdx < 64U)
    {
        CanRegisterWPtr->CAN_IFLAG2 = Flag;
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
    else if (MbIdx < 96U)
    {
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            CanRegisterWPtr->CAN_IFLAG3 = Flag;
        }
        else
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
    else if (MbIdx < 128U)
    {
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            CanRegisterWPtr->CAN_IFLAG4 = Flag;
        }
        else
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }
#endif
    else
    {
        ReturnValue = CAN_DRV_ERROR;
    }

    return ReturnValue;
}

/**
 * @brief       Computes the DLC field value.
 *
 * @param[in]   DataLen: Data length.
 * @param[out]  DlcPtr: Pointer to store DLC.
 * @param[out]  DataSizePtr: Pointer to store frame data size.
 *
 * @return      None
 *
 */
static void Can_Drv_ComputeDlcAndDataSize(uint32 DataLen, uint32 *DlcPtr, uint32 *DataSizePtr)
{
    uint32 DlcVal = 0U;
    uint32 DataSizeVal = 0U;

#if (STD_ON == CAN_DRV_FEATURE_HAS_FD)
    if (DataLen <= 8U)
    {
        DlcVal = DataLen;
        DataSizeVal = DataLen;
    }
    else if (DataLen <= 12U)
    {
        DlcVal = CAN_DRV_DLC_VALUE_12_BYTES;
        DataSizeVal = 12U;
    }
    else if (DataLen <= 16U)
    {
        DlcVal = CAN_DRV_DLC_VALUE_16_BYTES;
        DataSizeVal = 16U;
    }
    else if (DataLen <= 20U)
    {
        DlcVal = CAN_DRV_DLC_VALUE_20_BYTES;
        DataSizeVal = 20U;
    }
    else if (DataLen <= 24U)
    {
        DlcVal = CAN_DRV_DLC_VALUE_24_BYTES;
        DataSizeVal = 24U;
    }
    else if (DataLen <= 32U)
    {
        DlcVal = CAN_DRV_DLC_VALUE_32_BYTES;
        DataSizeVal = 32U;
    }
    else if (DataLen <= 48U)
    {
        DlcVal = CAN_DRV_DLC_VALUE_48_BYTES;
        DataSizeVal = 48U;
    }
    else
    {
        DlcVal = CAN_DRV_DLC_VALUE_64_BYTES;
        DataSizeVal = 64U;
    }
#else
    DlcVal = DataLen;
    DataSizeVal = DataLen;
#endif
    if (DlcPtr != NULL_PTR)
    {
        *DlcPtr = DlcVal;
    }

    if (DataSizePtr != NULL_PTR)
    {
        *DataSizePtr = DataSizeVal;
    }
}

/**
 * @brief      Computes the maximum Payload size (in bytes), given a DLC field Value
 *
 * @param[in]  DlcValue: Data length code.
 *
 * @return     uint8: Payload size.
 *
 */
static uint8 Can_Drv_ComputePayloadSize(uint8 DlcValue)
{
    uint8 Ret = 0U;

    if (DlcValue <= 8U)
    {
        Ret = DlcValue;
    }
#if (CAN_DRV_FEATURE_HAS_FD)
    else
    {
        switch (DlcValue)
        {
            case CAN_DRV_DLC_VALUE_12_BYTES:
                Ret = 12U;
                break;
            case CAN_DRV_DLC_VALUE_16_BYTES:
                Ret = 16U;
                break;
            case CAN_DRV_DLC_VALUE_20_BYTES:
                Ret = 20U;
                break;
            case CAN_DRV_DLC_VALUE_24_BYTES:
                Ret = 24U;
                break;
            case CAN_DRV_DLC_VALUE_32_BYTES:
                Ret = 32U;
                break;
            case CAN_DRV_DLC_VALUE_48_BYTES:
                Ret = 48U;
                break;
            case CAN_DRV_DLC_VALUE_64_BYTES:
                Ret = 64U;
                break;
            default:
                /* The argument is not a valid DLC size */
                break;
        }
    }
#endif
    return Ret;
}

/**
 * @brief      Disables controller.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Controller disabled success.
 * @retval     CAN_DRV_ERROR: Controller disabled failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_Disable(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   TimeElapsedValue = 0U;
    uint32                   TimeCounter = 0U;
    uint32                   CurrentValue;
    uint32                   CanTimeoutDuration;

    if (0U == CanRegisterBfPtr->CAN_MCR.MDIS)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_DisableModule();
        /* Clock Disable (module) */
        CanRegisterBfPtr->CAN_MCR.MDIS = 1;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_DisableModule();

        CanTimeoutDuration =
            McalLib_MicroSecToTicks(CAN_DRV_SERVICE_TIMEOUT_TYPE, CAN_DRV_TIMEOUT_DURATION);
        /* Wait for entering into the Low-Power Mode */
        (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);
        while (0U == CanRegisterBfPtr->CAN_MCR.LPMACK)
        {
            (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                          &TimeElapsedValue);
            TimeCounter += TimeElapsedValue;
            if (TimeCounter > CanTimeoutDuration)
            {
                ReturnValue = CAN_DRV_ERROR;
                break;
            }
        }
    }

    return ReturnValue;
}

/**
 * @brief      Enables controller.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Controller enabled success.
 * @retval     CAN_DRV_ERROR: Controller enabled failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_Enable(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   TimeElapsedValue = 0U;
    uint32                   TimeCounter = 0U;
    uint32                   CurrentValue;
    uint32                   CanTimeoutDuration;

    if (CanRegisterBfPtr->CAN_MCR.LPMACK != 0U)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_CanMcrReg();
        CanRegisterBfPtr->CAN_MCR.MDIS = 0U;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_CanMcrReg();

        CanTimeoutDuration =
            McalLib_MicroSecToTicks(CAN_DRV_SERVICE_TIMEOUT_TYPE, CAN_DRV_TIMEOUT_DURATION);
        /* Wait for entering in a Low Power mode */
        (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);

        while (0U != CanRegisterBfPtr->CAN_MCR.LPMACK)
        {
            (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                          &TimeElapsedValue);
            TimeCounter += TimeElapsedValue;
            if (TimeCounter > CanTimeoutDuration)
            {
                ReturnValue = CAN_DRV_ERROR;
                break;
            }
        }
    }

    return ReturnValue;
}

/**
 * @brief      Gets MB interrupt flag or interrupt status from block0.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  IntType: Interrupt type.
 *
 * @return     boolean
 * @retval     TRUE: The given interrupt type state is SET.
 * @retval     FALSE: The given interrupt type state is NOT SET.
 */
static boolean Can_Drv_GetInterruptInfoFromBlock0(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       RetStatus = 0U;
    uint32                        Mask = 0U;

    if (CAN_DRV_GET_INT_STATUS == IntType)
    {
        Mask = CanRegisterWPtr->CAN_IMASK1;
        RetStatus = (((CanRegisterWPtr->CAN_IFLAG1 & Mask) & (1UL << MbIdx)) != 0U) ? TRUE : FALSE;
    }
    else
    {
        RetStatus = ((CanRegisterWPtr->CAN_IFLAG1 & (1UL << MbIdx)) != 0U) ? TRUE : FALSE;
    }

    return RetStatus;
}

/**
 * @brief      Gets MB interrupt mask from block 0.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: MB interrupt is enabled.
 * @retval     FALSE: MB interrupt is disabled.
 *
 */
static boolean Can_Drv_GetMbInterruptStateFromBlock0(uint8 Id, uint32 MbIdx)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       MaskStatus = 0U;

    MaskStatus = ((CanRegisterWPtr->CAN_IMASK1 & (1UL << MbIdx)) != 0U) ? TRUE : FALSE;

    return MaskStatus;
}

/**
 * @brief      Gets MB interrupt mask from block 1.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: MB interrupt is enabled.
 * @retval     FALSE: MB interrupt is disabled.
 *
 */
static boolean Can_Drv_GetMbInterruptStateFromBlock1(uint8 Id, uint32 MbIdx)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       MaskStatus = 0U;

    MaskStatus = ((CanRegisterWPtr->CAN_IMASK2 & (1UL << (MbIdx - 32U))) != 0U) ? TRUE : FALSE;

    return MaskStatus;
}

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64U)
/**
 * @brief      Gets MB interrupt mask from block 2.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: MB interrupt is enabled.
 * @retval     FALSE: MB interrupt is disabled.
 *
 */
static boolean Can_Drv_GetMbInterruptStateFromBlock2(uint8 Id, uint32 MbIdx)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       MaskStatus = 0U;

    MaskStatus = ((CanRegisterWPtr->CAN_IMASK3 & (1UL << (MbIdx - 64U))) != 0U) ? TRUE : FALSE;

    return MaskStatus;
}
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96U)
/**
 * @brief      Gets MB interrupt mask from block 3.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: MB interrupt is enabled.
 * @retval     FALSE: MB interrupt is disabled.
 *
 */
static boolean Can_Drv_GetMbInterruptStateFromBlock3(uint8 Id, uint32 MbIdx)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       MaskStatus = 0U;

    MaskStatus = ((CanRegisterWPtr->CAN_IMASK4 & (1UL << (MbIdx - 96U))) != 0U) ? TRUE : FALSE;

    return MaskStatus;
}
#endif

/**
 * @brief      Get MB interrupt flag or interrupt status from block1.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  IntType: Interrupt type.
 *
 * @return     boolean
 * @retval     TRUE: The given interrupt type state is SET.
 * @retval     FALSE: The given interrupt type state is NOT SET.
 *
 */
static boolean Can_Drv_GetInterruptInfoFromBlock1(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       RetStatus = 0U;
    uint32                        Mask = 0U;

    if (CAN_DRV_GET_INT_STATUS == IntType)
    {
        Mask = CanRegisterWPtr->CAN_IMASK2;
        RetStatus =
            (((CanRegisterWPtr->CAN_IFLAG2 & Mask) & (1UL << (MbIdx - 32U))) != 0U) ? TRUE : FALSE;
    }
    else
    {
        RetStatus = ((CanRegisterWPtr->CAN_IFLAG2 & (1UL << (MbIdx - 32U))) != 0U) ? TRUE : FALSE;
    }

    return RetStatus;
}

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64U)
/**
 * @brief      Get MB interrupt flag or interrupt status from block2.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  IntType: Interrupt type.
 *
 * @return     boolean
 * @retval     TRUE: The given interrupt type state is SET.
 * @retval     FALSE: The given interrupt type state is NOT SET.
 *
 */
static boolean Can_Drv_GetInterruptInfoFromBlock2(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       RetStatus = 0U;
    uint32                        Mask = 0U;

    if (CAN_DRV_GET_INT_STATUS == IntType)
    {
        Mask = CanRegisterWPtr->CAN_IMASK3;
        RetStatus =
            (((CanRegisterWPtr->CAN_IFLAG3 & Mask) & (1UL << (MbIdx - 64U))) != 0U) ? TRUE : FALSE;
    }
    else
    {
        RetStatus = ((CanRegisterWPtr->CAN_IFLAG3 & (1UL << (MbIdx - 64U))) != 0U) ? TRUE : FALSE;
    }

    return RetStatus;
}
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96U)
/**
 * @brief      Get MB interrupt flag or interrupt status from block3.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  IntType: Interrupt type.
 *
 * @return     boolean
 * @retval     TRUE: The given interrupt type state is SET.
 * @retval     FALSE: The given interrupt type state is NOT SET.
 *
 */
static boolean Can_Drv_GetInterruptInfoFromBlock3(uint8 Id, uint32 MbIdx,
                                                  Can_Drv_GetIntType IntType)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    boolean                       RetStatus = 0U;
    uint32                        Mask = 0U;

    if (CAN_DRV_GET_INT_STATUS == IntType)
    {
        Mask = CanRegisterWPtr->CAN_IMASK4;
        RetStatus =
            (((CanRegisterWPtr->CAN_IFLAG4 & Mask) & (1UL << (MbIdx - 96U))) != 0U) ? TRUE : FALSE;
    }
    else
    {
        RetStatus = ((CanRegisterWPtr->CAN_IFLAG4 & (1UL << (MbIdx - 96U))) != 0U) ? TRUE : FALSE;
    }

    return RetStatus;
}
#endif

/**
 * @brief      Reads MB interrupt status.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: The corresponding message buffer interrupt is SET.
 * @retval     FALSE: The corresponding message buffer interrupt is NOT SET.
 */
static boolean Can_Drv_ReadMbInterruptStatus(uint8 Id, uint32 MbIdx)
{
    boolean IntStatus = FALSE;

    if (MbIdx < 32U)
    {
        IntStatus = Can_Drv_GetInterruptInfoFromBlock0(Id, MbIdx, CAN_DRV_GET_INT_STATUS);
    }
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32U)
    else if (MbIdx < 64U)
    {
        IntStatus = Can_Drv_GetInterruptInfoFromBlock1(Id, MbIdx, CAN_DRV_GET_INT_STATUS);
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64U)
    else if ((MbIdx < 96U) && (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id)))
    {
        IntStatus = Can_Drv_GetInterruptInfoFromBlock2(Id, MbIdx, CAN_DRV_GET_INT_STATUS);
    }
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96U)
    else
    {
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            IntStatus = Can_Drv_GetInterruptInfoFromBlock3(Id, MbIdx, CAN_DRV_GET_INT_STATUS);
        }
    }
#endif

    return IntStatus;
}

/**
 * @brief    Function process Message Buffer Interrupt.
 *
 * @param[in] Id: Channel id.
 * @param[in] StartMbIdx: The start message buffer id.
 * @param[in] EndMbIdx: The end message buffer id.
 *
 * @return    boolean
 * @retval    TRUE: A spurious interrupt generated.
 * @retval    FALSE: No spurious interrupt generated.
 *
 */
static boolean Can_Drv_ProcessMbIrqSource(uint8 Id, uint32 StartMbIdx, uint32 EndMbIdx)
{
    uint32                   MbIdx = 0U;
    boolean                  InterFlag = 0;
    const Can_Drv_StateType *StatePtr = Can_Drv_StatePtr[Id];
    boolean                  IsSpuriousInt = (boolean)TRUE;

    uint32 MbCounter = EndMbIdx;

    InterFlag = Can_Drv_ReadMbInterruptStatus(Id, MbCounter);

    while ((0U == InterFlag) && (MbCounter > StartMbIdx))
    {
        MbCounter--;
        InterFlag = Can_Drv_ReadMbInterruptStatus(Id, MbCounter);
    }

    /* Check Tx/Rx interrupt Flag and clear the interrupt */
    if (InterFlag != 0U)
    {
        /* Set interrupt flag valid */
        IsSpuriousInt = (boolean)FALSE;
        MbIdx = MbCounter;

        if ((TRUE == StatePtr->RxFifoEn) && (MbCounter <= CAN_DRV_RXFIFO_OVERFLOW))
        {
            Can_Drv_RxFifoIrqHandler(Id, (uint8)MbCounter);
            MbIdx = (uint32)CAN_DRV_RXFIFO_START_INDEX;
        }
        else
        {
            /* Check mailbox Status */
            if (CAN_DRV_STATE_RX == StatePtr->Mb[MbIdx].State)
            {
                Can_Drv_RxMbIrqHandler(Id, (uint8)MbCounter);
            }
            else if (CAN_DRV_STATE_TX == StatePtr->Mb[MbIdx].State)
            {
                /* Transmit State */
                Can_Drv_TxMbIrqHandler(Id, (uint8)MbCounter);
            }
            else
            {
                /* Nothing to do */
            }
        }

        InterFlag = Can_Drv_ReadMbInterruptStatus(Id, MbCounter);
        /* Check for spurious interrupt */
        if (InterFlag != 0U)
        {
            if (CAN_DRV_STATE_IDLE == StatePtr->Mb[MbIdx].State)
            {
                /*clear interrupt */
                (void)Can_Drv_ClearMessageBufferIntFlag(Id, (uint8)MbCounter);
            }
        }
    }

    return IsSpuriousInt;
}

/**
 * @brief      Returns MB interrupt flag.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: The corresponding buffer has successfully completed transmission or reception.
 * @retval     FALSE: The corresponding buffer has no occurrence of successfully completed
 * transmission or reception.
 *
 */
LOCAL_INLINE boolean Can_Drv_ReadMbInterruptFlag(uint8 Id, uint32 MbIdx)
{
    boolean IntFlag = 0U;

    if (MbIdx < 32U)
    {
        IntFlag = Can_Drv_GetInterruptInfoFromBlock0(Id, MbIdx, CAN_DRV_GET_INT_FLAG);
    }
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32U)
    else if (MbIdx < 64U)
    {
        IntFlag = Can_Drv_GetInterruptInfoFromBlock1(Id, MbIdx, CAN_DRV_GET_INT_FLAG);
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64U)
    else if ((MbIdx < 96U) && (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id)))
    {
        IntFlag = Can_Drv_GetInterruptInfoFromBlock2(Id, MbIdx, CAN_DRV_GET_INT_FLAG);
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96U)
    else
    {
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            IntFlag = Can_Drv_GetInterruptInfoFromBlock3(Id, MbIdx, CAN_DRV_GET_INT_FLAG);
        }
    }
#endif

    return IntFlag;
}

/**
 * @brief      Gets the start address of a MB.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Region: Pointer to store the region number.
 * @param[in]  Addr: Pointer to store the address of a buffer.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Get the start address of a buffer success.
 * @retval     CAN_DRV_ERROR: Get the start address of a buffer failed.
 *
 */
static Can_Drv_ControllerStatus
Can_Drv_GetMbAddr(uint8 Id, uint8 MbIdx, Can_Drv_FdMbRegionType *Region, Can_Drv_MbType **Addr)
{
    const volatile Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint8                         PayloadSize;
    uint8                         ConfigFieldSize = 8U;
    uint32                        RamBlockSize = 512U;
    uint32                        RamBlockOffset = 0U;
    uint32                        MbSize, RegionMaxMbNum = 0U;
    uint32                        MbOffset;
    Can_Drv_FdMbRegionType        MaxRegionIndex;
    uint32                        MaxRamSize;
    Can_Drv_ControllerStatus      Res = CAN_DRV_SUCCESS;
    uint32                        Index;

    if (NULL_PTR != Region)
    {
        *Region = CAN_DRV_CAN_FD_MB_REGION_0;
    }

    MaxRegionIndex = ((uint32)Id < (uint32)CAN_DRV_ID_6) ? CAN_DRV_CAN_FD_MB_REGION_1
                                                         : CAN_DRV_CAN_FD_MB_REGION_3;

    for (Index = 0U; Index <= (uint32)MaxRegionIndex; Index++)
    {
        MbIdx -= (uint8)RegionMaxMbNum;

        PayloadSize = Can_Drv_GetPayloadSize(Id, (Can_Drv_FdMbRegionType)Index);
        MbSize = (uint32)PayloadSize + (uint32)ConfigFieldSize;
        RegionMaxMbNum = RamBlockSize / MbSize;

        if (NULL_PTR != Region)
        {
            *Region = (Can_Drv_FdMbRegionType)Index;
        }

        if (MbIdx < RegionMaxMbNum)
        {
            /* Multiply the MB index by the MB size (in words) */
            MbOffset = RamBlockOffset + (uint32)(MbIdx * MbSize);

            *Addr = (Can_Drv_MbType *)((uint32) & (CanRegisterWPtr->CAN_MB[0]) + MbOffset);
            break;
        }
        else
        {
            RamBlockOffset += 512U;
        }
    }
    MaxRamSize = ((uint32)Id < (uint32)CAN_DRV_ID_6) ? CAN_DRV_CAN05_RAM_SIZE_IN_BYTE
                                                     : CAN_DRV_CAN67_RAM_SIZE_IN_BYTE;
    if (RamBlockOffset >= MaxRamSize)
    {
        Res = CAN_DRV_ERROR;
    }

    return Res;
}

/**
 * @brief      Returns a message buffer timestamp value.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     uint32: Free-Running counter time stamp.
 *
 */
static uint32 Can_Drv_GetTimeStamp(uint8 Id, uint8 MbIdx)
{
    Can_Drv_FdMbRegionType Region;
    Can_Drv_MbType        *MbAddr;
    uint32                 Temp = 0U;

    if (CAN_DRV_SUCCESS == Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddr))
    {
        Temp = MbAddr->Config.BF.TIME_STAMP;
    }

    return Temp;
}

/**
 * @brief      Calculates the filter Table value of each filter mode A.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Number: Filter number
 * @param[in]  IdFilterTable: Pointer to store the message id filter table.
 *
 * @note
 *       The number of elements in the ID filter table is defined by the
 *       following formula:
 *       - for Format A: the number of Rx FIFO ID filters
 *
 *       Each Element in the ID filter table specifies an ID to be used as
 *       acceptance criteria for the FIFO as follows:
 *       - for Format A: In the standard frame Format, bits 10 to 0 of the ID
 *         are used for frame identification. In the extended frame Format, bits
 *         28 to 0 are used.
 *
 * @return     None
 *
 */
static void Can_Drv_ComputeFifoModeATable(uint8 Id, uint32 Number,
                                          const Can_Drv_IdFilterType *IdFilterTable)
{
    uint32           Index;
    uint32           Val;
    Reg_Can_WType   *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    volatile uint32 *Table;

    Table = (volatile uint32 *)&(CanRegisterWPtr->CAN_MB[6U].MB0);
    for (Index = 0U; Index < Number; Index++)
    {
        Val = 0U;

        if (TRUE == IdFilterTable[Index].IsRemoteFrame)
        {
            Val = (uint32)1U << 31U;
        }

        if (TRUE == IdFilterTable[Index].IsExtendedFrame)
        {
            Val |= (uint32)1U << 30U;
            Table[Index] = Val | ((IdFilterTable[Index].Id << 1U) & 0x3FFFFFFFU);
        }
        else
        {
            Table[Index] = Val | ((IdFilterTable[Index].Id << 19U) & 0x3FFFFFFFU);
        }
    }
}

/**
 * @brief      Calculate the filter Table value of each filter mode B.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Number: Filter number
 * @param[in]  IdFilterTable: Pointer to store the message id filter table.
 *
 * @note
 *       The number of elements in the ID filter table is defined by the
 *       following formula:
 *       - for Format B: twice the number of Rx FIFO ID filters
 *       The user must provide the exact number of elements in order to avoid
 *       any misconfiguration.
 *
 *       Each Element in the ID filter table specifies an ID to be used as
 *       acceptance criteria for the FIFO as follows:
 *       - for Format B: In the standard frame Format, bits 10 to 0 of the ID
 *         are used for frame identification. In the extended frame Format, only
 *         the 14 most significant bits (28 to 15) of the ID are compared to the
 *         14 most significant bits (28 to 15) of the received ID.
 *
 * @return     None
 *
 */
static void Can_Drv_ComputeFifoModeBTable(uint8 Id, uint32 Number,
                                          const Can_Drv_IdFilterType *IdFilterTable)
{
    uint32           Index;
    uint32           TableIndex;
    uint32           Val1 = 0;
    uint32           Val2;
    Reg_Can_WType   *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    volatile uint32 *Table;
    Table = (volatile uint32 *)&(CanRegisterWPtr->CAN_MB[6].MB0);

    TableIndex = 0U;
    for (Index = 0U; Index < Number; Index++)
    {
        Val1 = 0U;
        Val2 = 0U;

        if (TRUE == IdFilterTable[TableIndex].IsRemoteFrame)
        {
            Val1 = 1UL << 31U;
        }

        if (TRUE == IdFilterTable[TableIndex + 1U].IsRemoteFrame)
        {
            Val2 = 1UL << 15U;
        }

        if (TRUE == IdFilterTable[TableIndex].IsExtendedFrame)
        {
            Val1 |= 1UL << 30U;

            Table[Index] = Val1 | (((IdFilterTable[TableIndex].Id & 0x1FFF8000U) >> 15) << 16);
        }
        else
        {
            Table[Index] = Val1 | ((IdFilterTable[TableIndex].Id & 0x7FFU) << 19);
        }

        if (TRUE == IdFilterTable[TableIndex + 1U].IsExtendedFrame)
        {
            Val2 |= 1UL << 14U;

            Table[Index] |= Val2 | ((IdFilterTable[TableIndex + 1U].Id & 0x1FFF8000U) >> 15U);
        }
        else
        {
            Table[Index] |= Val2 + ((IdFilterTable[TableIndex + 1U].Id & 0x7FFU) << 3U);
        }

        TableIndex = TableIndex + 2U;
    }
}

/**
 * @brief      Calculates the filter Table value of each filter mode B.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Number: Filter number
 * @param[in]  IdFilterTable: Pointer to store the message id filter table.
 *
 * @note
 *       - for Format C: four times the number of Rx FIFO ID filters
 *       The user must provide the exact number of elements in order to avoid
 *       any misconfiguration.
 *
 *       Each Element in the ID filter table specifies an ID to be used as
 *       acceptance criteria for the FIFO as follows:
 *       - for Format C: In both standard and extended frame formats, only the 8
 *         most significant bits(10 to 3 for standard, 28 to 21 for extended) of
 *         the ID are compared to the 8 most significant bits (10 to 3 for
 *         standard, 28 to 21 for extended) of the received ID.
 *
 * @return     None
 *
 */
static void Can_Drv_ComputeFifoModeCTable(uint8 Id, uint32 Number,
                                          const Can_Drv_IdFilterType *IdFilterTable)
{
    uint32           Index;
    uint32           TableIndex;
    Reg_Can_WType   *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    volatile uint32 *Table;

    Table = (volatile uint32 *)&(CanRegisterWPtr->CAN_MB[6].MB0);
    TableIndex = 0U;
    for (Index = 0U; Index < Number; Index++)
    {
        if (TRUE == IdFilterTable[TableIndex].IsExtendedFrame)
        {
            Table[Index] |= (((IdFilterTable[TableIndex].Id & 0x1FE00000U) >> 21U) << 24U);
        }
        else
        {
            Table[Index] |= (((IdFilterTable[TableIndex].Id & 0x7F8U) >> 3U) << 24U);
        }

        if (TRUE == IdFilterTable[TableIndex + 1U].IsExtendedFrame)
        {
            Table[Index] |= (((IdFilterTable[TableIndex + 1U].Id & 0x1FE00000U) >> 21U) << 16U);
        }
        else
        {
            Table[Index] |= (((IdFilterTable[TableIndex + 1U].Id & 0x7F8U) >> 3U) << 16U);
        }

        if (TRUE == IdFilterTable[TableIndex + 2U].IsExtendedFrame)
        {
            Table[Index] |= (((IdFilterTable[TableIndex + 2U].Id & 0x1FE00000U) >> 21U) << 8U);
        }
        else
        {
            Table[Index] |= (((IdFilterTable[TableIndex + 2U].Id & 0x7F8U) >> 3U) << 8U);
        }

        if (TRUE == IdFilterTable[TableIndex + 3U].IsExtendedFrame)
        {
            Table[Index] |= ((IdFilterTable[TableIndex + 3U].Id & 0x1FE00000U) >> 21U);
        }
        else
        {
            Table[Index] |= ((IdFilterTable[TableIndex + 3U].Id & 0x7F8U) >> 3U);
        }

        TableIndex = TableIndex + 4U;
    }
}

/**
 * @brief      Configure RX FIFO ID filter table elements
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Format: the ID filter Format
 * @param[in]  IdFilterTable: Pointer to store the message id filter table.
 *
 * @note
 *       The number of elements in the ID filter table is defined by the
 *       following formula:
 *       - for Format A: the number of Rx FIFO ID filters
 *       - for Format B: twice the number of Rx FIFO ID filters
 *       - for Format C: four times the number of Rx FIFO ID filters
 *
 * @return     None
 *
 */
static void Can_Drv_ConfigRxFifoFilter(uint8 Id, Can_Drv_RxAcceptanceType Format,
                                       const Can_Drv_IdFilterType *IdFilterTable)
{
    Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint8           FilterNum = 0U;
    FilterNum = ((uint8)(CanRegisterBfPtr->CAN_CTRL2.RFFN) + (uint8)1U) << 3u;

    /* init operation, clear RX FIFO */
    CanRegisterWPtr->CAN_IFLAG1 = 1U;

    switch (Format)
    {
        case CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_A:
            SchM_Enter_Can_CanMcrReg();
            /* One full ID (standard and extended) per ID Filter Table Element.*/
            CanRegisterBfPtr->CAN_MCR.IDAM = (uint32)Format;
            SchM_Exit_Can_CanMcrReg();
            Can_Drv_ComputeFifoModeATable(Id, FilterNum, IdFilterTable);
            break;
        case CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_B:
            /* Two full standard IDs or two partial 14-bit (standard and extended) IDs*/
            SchM_Enter_Can_CanMcrReg();
            /* per ID Filter Table Element.*/
            CanRegisterBfPtr->CAN_MCR.IDAM = (uint32)Format;
            SchM_Exit_Can_CanMcrReg();
            Can_Drv_ComputeFifoModeBTable(Id, FilterNum, IdFilterTable);
            break;
        case CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_C:
            SchM_Enter_Can_CanMcrReg();
            /* Four partial 8-bit Standard IDs per ID Filter Table Element.*/
            CanRegisterBfPtr->CAN_MCR.IDAM = (uint32)Format;
            SchM_Exit_Can_CanMcrReg();
            Can_Drv_ComputeFifoModeCTable(Id, FilterNum, IdFilterTable);
            break;
        case CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_D:
            SchM_Enter_Can_CanMcrReg();
            /* All frames rejected.*/
            CanRegisterBfPtr->CAN_MCR.IDAM = (uint32)Format;
            SchM_Exit_Can_CanMcrReg();
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief      Unmasks the message buffers interrupt.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     None
 *
 */
static void Can_Drv_UnmaskInterrupt(uint8 Id)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];

    CanRegisterWPtr->CAN_IMASK1 = Can_Drv_InterMaskBuff[Id][0U];
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32)
    CanRegisterWPtr->CAN_IMASK2 = Can_Drv_InterMaskBuff[Id][1U];
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
    if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
    {
        CanRegisterWPtr->CAN_IMASK3 = Can_Drv_InterMaskBuff[Id][2U];
    }
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
    if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
    {
        CanRegisterWPtr->CAN_IMASK4 = Can_Drv_InterMaskBuff[Id][3U];
    }
#endif
}

/**
 * @brief      Masks the message buffers interrupt.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     None
 *
 */
static void Can_Drv_MaskInterrupt(uint8 Id)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];

    CanRegisterWPtr->CAN_IMASK1 = 0U;
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32)
    CanRegisterWPtr->CAN_IMASK2 = 0U;
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
    if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
    {
        CanRegisterWPtr->CAN_IMASK3 = 0U;
    }
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
    if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
    {
        CanRegisterWPtr->CAN_IMASK4 = 0U;
    }
#endif
}

/**
 * @brief      Gets a message buffer field value.
 *
 * @param[in]  Id: Channel id.
 * @param[out] MsgBuf: Pointer to the address where the message stored.
 *
 * @return     None
 *
 */
static void Can_Drv_ReadRxFifo(uint8 Id, Can_Drv_MsgBufType *MsgBuf)
{
    /* Pointer to the Can register structure. */
    const volatile Reg_Can_WType  *CanRegisterWPtr;
    uint8                          Index;
    uint32                         DataIndex;
    uint8                          TmpNum;
    uint8                          TmpIndex;
    uint8                          PayloadSize;
    const volatile Can_Drv_MbType *MbAddr;
    const volatile uint8          *MbData;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(MsgBuf != NULL_PTR);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];

    MbAddr = (Can_Drv_MbType *)(uint32) & (CanRegisterWPtr->CAN_MB[0].MB0);
    PayloadSize = Can_Drv_ComputePayloadSize((uint8)(MbAddr->Config.BF.DLC));
    if (PayloadSize > Can_Drv_GetPayloadSize(Id, CAN_DRV_CAN_FD_MB_REGION_0))
    {
        PayloadSize = Can_Drv_GetPayloadSize(Id, CAN_DRV_CAN_FD_MB_REGION_0);
    }

    MsgBuf->DataLen = PayloadSize;
    MsgBuf->Cs = MbAddr->Config.WORDVAL;
    MsgBuf->TimeStamp = (uint32)(MsgBuf->Cs & 0xFFFFU);
    if (MbAddr->Config.BF.IDE != 0U)
    {
        MsgBuf->MsgId = MbAddr->Id.WORDVAL & CAN_DRV_ID_EXT_MASK;
    }
    else
    {
        MsgBuf->MsgId = MbAddr->Id.BF.ID_STANDARD;
    }

    TmpNum = PayloadSize / 4U;
    for (Index = 0U; Index < TmpNum; Index += 1U)
    {
        DataIndex = (uint32)Index * 4U;
        MsgBuf->Data[DataIndex] = (uint8)((MbAddr->Data[Index] & 0xFF000000U) >> 24U);
        MsgBuf->Data[DataIndex + 1U] = (uint8)((MbAddr->Data[Index] & 0xFF0000U) >> 16U);
        MsgBuf->Data[DataIndex + 2U] = (uint8)((MbAddr->Data[Index] & 0xFF00U) >> 8U);
        MsgBuf->Data[DataIndex + 3U] = (uint8)(MbAddr->Data[Index] & 0xFFU);
    }
    MbData = (const volatile uint8 *)(&MbAddr->Data[0]);
    for (Index = TmpNum * 4U; Index < PayloadSize; Index++)
    {
        TmpIndex = CAN_DRV_SWAP_BYTES_IN_WORD_INDEX(Index) & 0x3FU;
        /* Max allowed Value for index is 63 */
        MsgBuf->Data[Index] = MbData[TmpIndex];
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Gets a message buffer field value.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[out] MsgBuf: Pointer to the address where the message stored.
 *
 * @return     None
 *
 */
static void Can_Drv_GetMsgBuff(uint8 Id, uint8 MbIdx, Can_Drv_MsgBufType *MsgBuf)
{
    const volatile Reg_Can_WType *CanRegisterWPtr;
    uint8                         Index;
    uint8                         DataIndex;
    uint8                         TmpNum;
    uint8                         TmpIndex;
    uint8                         PayloadSize;
    Can_Drv_FdMbRegionType        Region;
    Can_Drv_MbType               *MbAddr;
    const volatile uint8         *MbData;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(MsgBuf != NULL_PTR);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    (void)Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddr);

    MbData = (volatile uint8 *)(&MbAddr->Data[0]);

    /* Lock the mailbox by reading it */
    (void)(MbAddr->Config.WORDVAL);

    PayloadSize = Can_Drv_ComputePayloadSize((uint8)(MbAddr->Config.BF.DLC));
    if (PayloadSize > Can_Drv_GetPayloadSize(Id, Region))
    {
        PayloadSize = Can_Drv_GetPayloadSize(Id, Region);
    }

    MsgBuf->DataLen = PayloadSize;
    MsgBuf->Cs = MbAddr->Config.WORDVAL;
    MsgBuf->TimeStamp = (uint32)(MsgBuf->Cs & 0x0000FFFFU);

    if (0U != MbAddr->Config.BF.IDE)
    {
        MsgBuf->MsgId = MbAddr->Id.WORDVAL & CAN_DRV_ID_EXT_MASK;
    }
    else
    {
        MsgBuf->MsgId = MbAddr->Id.BF.ID_STANDARD;
    }

    TmpNum = PayloadSize / 4U;
    for (Index = 0U; Index < TmpNum; Index += 1U)
    {
        DataIndex = (Index * 4U);
        MsgBuf->Data[DataIndex] = (uint8)((MbAddr->Data[Index] & 0xFF000000U) >> 24U);
        MsgBuf->Data[DataIndex + 1U] = (uint8)((MbAddr->Data[Index] & 0xFF0000U) >> 16U);
        MsgBuf->Data[DataIndex + 2U] = (uint8)((MbAddr->Data[Index] & 0xFF00U) >> 8U);
        MsgBuf->Data[DataIndex + 3U] = (uint8)(MbAddr->Data[Index] & 0xFFU);
    }

    for (Index = TmpNum * 4U; Index < PayloadSize; Index++)
    {
        TmpIndex = CAN_DRV_SWAP_BYTES_IN_WORD_INDEX(Index) & 0x3FU;
        /* Max allowed Value for index is 63 */
        MsgBuf->Data[Index] = MbData[TmpIndex];
    }

    /* Unlock the mailbox by reading the free running timer */
    (void)CanRegisterWPtr->CAN_TIMER;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Gets a message buffer time stamp.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     uint32: Time stamp.
 *
 */
static uint32 Can_Drv_GetMsgBuffTimeStamp(uint8 Id, uint8 MbIdx)
{
    Can_Drv_FdMbRegionType Region;
    Can_Drv_MbType        *MbAddr;
    uint32                 TimeStamp = 0U;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    (void)Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddr);
    TimeStamp = (uint32)((MbAddr->Config.WORDVAL) & 0x0000FFFFU);

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return TimeStamp;
}

/**
 * @brief      Processes configure error interrupt.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Mask: Error interrupt mask.
 * @param[in]  Enable: Enable/Disable interrupt.
 *
 * @return     None
 *
 */
static void Can_Drv_ProcessErrorIntConfigure(uint8 Id, uint32 Mask, boolean Enable)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint32         Temp = Mask;

    if (TRUE == Enable)
    {
#if (STD_ON == CAN_DRV_FEATURE_HAS_FD)
        if (CAN_DRV_INT_MSK_ERR_FAST == Mask)
        {
            Temp = ~Temp;
            SchM_Enter_Can_CanCtl2Reg();
            CanRegisterWPtr->CAN_CTRL2 = (CanRegisterWPtr->CAN_CTRL2 & Temp) | Mask;
            SchM_Exit_Can_CanCtl2Reg();
        }
        else
#endif
        {
            SchM_Enter_Can_CanCtl1Reg();
            (CanRegisterWPtr->CAN_CTRL1) = ((CanRegisterWPtr->CAN_CTRL1) | (Mask));
            SchM_Exit_Can_CanCtl1Reg();
        }
    }
    else
    {
#if (STD_ON == CAN_DRV_FEATURE_HAS_FD)
        if (CAN_DRV_INT_MSK_ERR_FAST == Mask)
        {
            Temp = ~Temp;
            SchM_Enter_Can_CanCtl2Reg();
            CanRegisterWPtr->CAN_CTRL2 = (CanRegisterWPtr->CAN_CTRL2 & Temp);
            SchM_Exit_Can_CanCtl2Reg();
        }
        else
#endif
        {
            Temp = Mask;
            SchM_Enter_Can_CanCtl1Reg();
            (CanRegisterWPtr->CAN_CTRL1) = ((CanRegisterWPtr->CAN_CTRL1) & ~(Temp));
            SchM_Exit_Can_CanCtl1Reg();
        }
    }
}

/**
 * @brief      Processes configure ecc interrupt.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Mask: Error interrupt mask.
 * @param[in]  Enable: Enable/Disable interrupt.
 *
 * @return     None
 *
 */
static void Can_Drv_ProcessEccIntConfigure(uint8 Id, uint32 Mask, boolean Enable)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    
    SchM_Enter_Can_CanCtl2Reg();
    CanRegisterBfPtr->CAN_CTRL2.ECRWRE = 1U;
    SchM_Exit_Can_CanCtl2Reg();

    SchM_Enter_Can_CanMecrReg();
    if (TRUE == Enable)
    {
        if ((uint32)CAN_DRV_INT_HOST_MEM_ERR == Mask)
        {
            CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0U;
            CanRegisterWPtr->CAN_MECR |= CAN_DRV_INT_MSK_HOST_MEM_ERR;
        }
        else if((uint32)CAN_DRV_INT_MEM_ERR == Mask)
        {
            CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0U;
            CanRegisterWPtr->CAN_MECR |= CAN_DRV_INT_MSK_CAN_MEM_ERR;
        }
        else
        {
            CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0U;
            CanRegisterWPtr->CAN_MECR |= CAN_DRV_INT_MSK_COR_MEM_ERR;
        }
    }
    else
    {
        if ((uint32)CAN_DRV_INT_HOST_MEM_ERR == Mask)
        {
            CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0U;
            CanRegisterWPtr->CAN_MECR &= ~CAN_DRV_INT_MSK_HOST_MEM_ERR;
        }
        else if((uint32)CAN_DRV_INT_MEM_ERR == Mask)
        {
            CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0U;
            CanRegisterWPtr->CAN_MECR &= ~ CAN_DRV_INT_MSK_CAN_MEM_ERR;
        }
        else
        {
            CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0U;
            CanRegisterWPtr->CAN_MECR &= ~ CAN_DRV_INT_MSK_COR_MEM_ERR;
        }
    }
    SchM_Exit_Can_CanMecrReg();
}

/**
 * @brief      Executes controller soft reset.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Controller soft reset executed success.
 * @retval     CAN_DRV_ERROR:   Controller soft reset executed failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_ExecuteSoftReset(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   TimeElapsedValue = 0U;
    uint32                   TimeCounter = 0U;
    uint32                   CurrentValue;
    uint32                   CanTimeoutDuration =
        McalLib_MicroSecToTicks(CAN_DRV_SERVICE_TIMEOUT_TYPE, CAN_DRV_TIMEOUT_DURATION);

    SchM_Enter_Can_CanMcrReg();
    CanRegisterBfPtr->CAN_MCR.SOFTRST = 1U;
    SchM_Exit_Can_CanMcrReg();

    /* Wait for the CAN reset complete */
    (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);
    while (CanRegisterBfPtr->CAN_MCR.SOFTRST != 0U)
    {
        (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                      &TimeElapsedValue);
        TimeCounter += TimeElapsedValue;
        if (TimeCounter > CanTimeoutDuration)
        {
            ReturnValue = CAN_DRV_ERROR;
            break;
        }
    }

    return ReturnValue;
}

/**
 * @brief      Clears CAN memory positions that require initialization.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     None
 */
static void Can_Drv_ClearRam(uint8 Id)
{
    Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Reg_Can_WType  *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint32          DataByte;
    uint32          RamSize;
    uint32          RxImrSize;
    /*pointer MB address  */
    volatile uint32 *RAM = &(CanRegisterWPtr->CAN_MB[0].MB0);

    if ((uint32)Id < (uint32)CAN_DRV_ID_6)
    {
        RamSize = CAN_DRV_CAN05_RAM_SIZE_IN_WORD;
        RxImrSize = CAN_DRV_CAN05_MB_NUM;
    }
    else
    {
        RamSize = CAN_DRV_CAN67_RAM_SIZE_IN_WORD;
        RxImrSize = CAN_DRV_CAN67_MB_NUM;
    }

    CanRegisterBfPtr->CAN_CTRL2.WRMFRZ = 1;
    /* Clear MB Region */
    for (DataByte = 0U; DataByte < RamSize; DataByte++)
    {
        RAM[DataByte] = 0x0U;
    }

    RAM = &(CanRegisterWPtr->CAN_RXIMR[0]);

    /* Clear RXIMR Region */
    for (DataByte = 0; DataByte < RxImrSize; DataByte++)
    {
        RAM[DataByte] = 0xFFFFFFFFU;
    }

    /* init Mask */
    CanRegisterWPtr->CAN_RXMGMSK = 0xFFFFFFFFU;
    CanRegisterWPtr->CAN_RX14MASK = 0xFFFFFFFFU;
    CanRegisterWPtr->CAN_RX15MASK = 0xFFFFFFFFU;

    /* RX FIFO global Mask */
    CanRegisterWPtr->CAN_RXFGMASK = 0xFFFFFFFFU;

    /* RX FIFO */
    RAM = (volatile uint32 *)((uint32)Can_Drv_CanRegBfPtr[Id] + CAN_DRV_RAM_RX_FIFO_ADDR);
    for (DataByte = 0U; DataByte < CAN_DRV_RAM_RX_FIFO_LEN_IN_WORD; DataByte++)
    {
        RAM[DataByte] = 0U;
    }

    /* RXMGMASK, RXFGMASK, RX14MSK, RX15MASK */
    RAM = (volatile uint32 *)((uint32)Can_Drv_CanRegBfPtr[Id] + CAN_DRV_RAM_MSK_ADDR);
    for (DataByte = 0U; DataByte < CAN_DRV_RAM_MSK_LEN_IN_WORD; DataByte++)
    {
        RAM[DataByte] = 0xFFFFFFFFU;
    }

    /* Rx_SMB0, Rx_SMB1 */
    RAM = (volatile uint32 *)((uint32)Can_Drv_CanRegBfPtr[Id] + CAN_DRV_RAM_RX_SMB_ADDR);
    for (DataByte = 0U; DataByte < CAN_DRV_RAM_RX_SMB_LEN_IN_WORD; DataByte++)
    {
        RAM[DataByte] = 0U;
    }

    /* CAN-FD scratch memory */
    RAM = (volatile uint32 *)((uint32)Can_Drv_CanRegBfPtr[Id] + CAN_DRV_RAM_FD_SCRATCH_ADDR);
    for (DataByte = 0U; DataByte < CAN_DRV_RAM_FD_SCRATCH_LEN_IN_WORD; DataByte++)
    {
        RAM[DataByte] = 0U;
    }

    /* Set to maintain the write access restrictions */
    CanRegisterBfPtr->CAN_CTRL2.WRMFRZ = 0U;
}

/**
 * @brief      Resets controller configuration.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     None
 *
 */
LOCAL_INLINE void Can_Drv_ResetConfiguration(uint8 Id)
{
    Reg_Can_WType  *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    CanRegisterWPtr->CAN_IMASK1 = 0x00U;
    CanRegisterWPtr->CAN_IFLAG1 = (uint32)(0xFFFFFFFFU);
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32)
    CanRegisterWPtr->CAN_IMASK2 = 0x00U;
    CanRegisterWPtr->CAN_IFLAG2 = (uint32)(0xFFFFFFFFU);
#endif
    if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
    {
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
        CanRegisterWPtr->CAN_IMASK3 = 0x00U;
        CanRegisterWPtr->CAN_IFLAG3 = (uint32)(0xFFFFFFFFU);
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
        CanRegisterWPtr->CAN_IMASK4 = 0x00U;
        CanRegisterWPtr->CAN_IFLAG4 = (uint32)(0xFFFFFFFFU);
#endif
    }

    CanRegisterWPtr->CAN_FDCBT = CAN_DRV_FDCBT_DEFAULT_VALUE;
    CanRegisterWPtr->CAN_FDCTRL = CAN_DRV_FDCTRL_DEFAULT_VALUE;
    CanRegisterWPtr->CAN_CBT = CAN_DRV_CBT_DEFAULT_VALUE;
    SchM_Enter_Can_CanCtl1Reg();
    CanRegisterWPtr->CAN_CTRL1 &= ~CAN_DRV_INT_MSK_MULTI_1;
    SchM_Exit_Can_CanCtl1Reg();

    SchM_Enter_Can_CanCtl2Reg();
    CanRegisterWPtr->CAN_CTRL2 &= ~CAN_DRV_INT_MSK_MULTI_2;
    CanRegisterBfPtr->CAN_CTRL2.ECRWRE = 1U;
    SchM_Exit_Can_CanCtl2Reg();
    SchM_Enter_Can_CanMecrReg();
    CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0U;
    CanRegisterWPtr->CAN_MECR &= ~CAN_DRV_INT_MSK_MULTI_ECC;
    SchM_Exit_Can_CanMecrReg();
    SchM_Enter_Can_CanMcrReg();
    CanRegisterBfPtr->CAN_MCR.WAKMSK = 0;
    CanRegisterBfPtr->CAN_MCR.WRNEN = 0U;
    SchM_Exit_Can_CanMcrReg();
    CanRegisterWPtr->CAN_ERRSR = (CAN_DRV_INT_MSK_FLAG_ALL_ECC | (CAN_DRV_INT_MSK_FLAG_ALL_ECC >> CAN_DRV_ECC_OVERRUN_ERROR_SHIFT));
    CanRegisterWPtr->CAN_CTRL1_PN &= ~CAN_DRV_INT_MSK_MULTI_PN;
    CanRegisterWPtr->CAN_CTRL2 = CAN_DRV_CTRL2_DEFAULT_VALUE;
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_ESR1_DEFAULT_VALUE;
    CanRegisterWPtr->CAN_ECR = CAN_DRV_ECR_DEFAULT_VALUE;
    CanRegisterWPtr->CAN_TIMER = CAN_DRV_TIMER_DEFAULT_VALUE;
    CanRegisterWPtr->CAN_CTRL1 = CAN_DRV_CTRL1_DEFAULT_VALUE;
    CanRegisterWPtr->CAN_MCR = CAN_DRV_MCR_DEFAULT_VALUE;
}

/**
 * @brief      Enables/Disables interrupt of message buffer 0 ~ 31.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Enable: Enable/Disable.
 * @param[in]  IsActive: Interrupt status(active/inactive).
 *
 * @return     None
 *
 */
static void Can_Drv_ConfigMbInterruptBlock0(uint8 Id, uint8 MbIdx, boolean Enable, boolean IsActive)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint32         Temp = 1UL << (MbIdx % 32U);

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_InterMaskBuff();

    if (TRUE == Enable)
    {
        Can_Drv_InterMaskBuff[Id][0U] = ((Can_Drv_InterMaskBuff[Id][0U]) | (Temp));
        if (TRUE == IsActive)
        {
            CanRegisterWPtr->CAN_IMASK1 = Can_Drv_InterMaskBuff[Id][0U];
        }
    }
    else
    {
        Can_Drv_InterMaskBuff[Id][0U] = ((Can_Drv_InterMaskBuff[Id][0U]) & ~(Temp));
        CanRegisterWPtr->CAN_IMASK1 = Can_Drv_InterMaskBuff[Id][0U];
    }
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_InterMaskBuff();
}

/**
 * @brief      Enables/Disables interrupt of message buffer 32 ~ 63.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Enable: Enable/Disable.
 * @param[in]  IsActive: Interrupt status(active/inactive).
 *
 * @return     None
 *
 */
static void Can_Drv_ConfigMbInterruptBlock1(uint8 Id, uint8 MbIdx, boolean Enable, boolean IsActive)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint32         Temp = 1UL << (MbIdx % 32U);

    if (TRUE == Enable)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_InterMaskBuff();
        Can_Drv_InterMaskBuff[Id][1U] = ((Can_Drv_InterMaskBuff[Id][1U]) | (Temp));
        if (TRUE == IsActive)
        {
            CanRegisterWPtr->CAN_IMASK2 = Can_Drv_InterMaskBuff[Id][1U];
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_InterMaskBuff();
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_InterMaskBuff();
        Can_Drv_InterMaskBuff[Id][1U] = ((Can_Drv_InterMaskBuff[Id][1U]) & ~(Temp));
        CanRegisterWPtr->CAN_IMASK2 = Can_Drv_InterMaskBuff[Id][1U];
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_InterMaskBuff();
    }
}

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
/**
 * @brief      Enables/Disables interrupt of message buffer 64 ~ 95.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Enable: Enable/Disable.
 * @param[in]  IsActive: Interrupt status(active/inactive).
 *
 * @return     None
 *
 */
static void Can_Drv_ConfigMbInterruptBlock2(uint8 Id, uint8 MbIdx, boolean Enable, boolean IsActive)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint32         Temp = 1UL << (MbIdx % 32U);

    if (TRUE == Enable)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_InterMaskBuff();
        Can_Drv_InterMaskBuff[Id][2U] = ((Can_Drv_InterMaskBuff[Id][2U]) | (Temp));
        if (TRUE == IsActive)
        {
            CanRegisterWPtr->CAN_IMASK3 = Can_Drv_InterMaskBuff[Id][2U];
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_InterMaskBuff();
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_InterMaskBuff();
        Can_Drv_InterMaskBuff[Id][2U] = ((Can_Drv_InterMaskBuff[Id][2U]) & ~(Temp));
        CanRegisterWPtr->CAN_IMASK3 = Can_Drv_InterMaskBuff[Id][2U];
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_InterMaskBuff();
    }
}
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
/**
 * @brief      Enables/Disables interrupt of message buffer 96 ~ 127.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Enable: Enable/Disable.
 * @param[in]  IsActive: Interrupt status(active/inactive).
 *
 * @return     None
 *
 */
static void Can_Drv_ConfigMbInterruptBlock3(uint8 Id, uint8 MbIdx, boolean Enable, boolean IsActive)
{
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    uint32         Temp = 1UL << (MbIdx % 32U);

    if (TRUE == Enable)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_InterMaskBuff();
        Can_Drv_InterMaskBuff[Id][3U] = ((Can_Drv_InterMaskBuff[Id][3U]) | (Temp));
        if (TRUE == IsActive)
        {
            CanRegisterWPtr->CAN_IMASK4 = Can_Drv_InterMaskBuff[Id][3U];
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_InterMaskBuff();
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_InterMaskBuff();
        Can_Drv_InterMaskBuff[Id][3U] = ((Can_Drv_InterMaskBuff[Id][3U]) & ~(Temp));
        CanRegisterWPtr->CAN_IMASK4 = Can_Drv_InterMaskBuff[Id][3U];
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_InterMaskBuff();
    }
}
#endif

/**
 * @brief      Configures the corresponding message buffer interrupt.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Enable: Enable/Disable.
 * @param[in]  IsActive: Interrupt status(active/inactive)
 *
 * @return     None
 *
 */
static void Can_Drv_ConfigMbInterrupt(uint8 Id, uint8 MbIdx, boolean Enable, boolean IsActive)
{
    if (MbIdx < 32U)
    {
        Can_Drv_ConfigMbInterruptBlock0(Id, MbIdx, Enable, IsActive);
    }
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32)
    else if (MbIdx < 64U)
    {
        Can_Drv_ConfigMbInterruptBlock1(Id, MbIdx, Enable, IsActive);
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
    else if ((MbIdx < 96U) && (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id)))
    {
        Can_Drv_ConfigMbInterruptBlock2(Id, MbIdx, Enable, IsActive);
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
    else if ((MbIdx >= 96U) && (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id)))
    {
        Can_Drv_ConfigMbInterruptBlock3(Id, MbIdx, Enable, IsActive);
    }
#endif
    else
    {
        /* Nothing to do */
    }
}

/**
 * @brief      Returns MB interrupt state(enabled/disabled).
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: The corresponding MB interrupt is enabled.
 * @retval     FALSE: The corresponding MB interrupt is disabled.
 *
 */
static boolean Can_Drv_GetMbInterruptState(uint8 Id, uint8 MbIdx)
{
    boolean IntState = FALSE;

    if (MbIdx < 32U)
    {
        IntState = Can_Drv_GetMbInterruptStateFromBlock0(Id, MbIdx);
    }
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32U)
    else if (MbIdx < 64U)
    {
        IntState = Can_Drv_GetMbInterruptStateFromBlock1(Id, MbIdx);
    }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64U)
    else if ((MbIdx < 96U) && (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id)))
    {
        IntState = Can_Drv_GetMbInterruptStateFromBlock2(Id, MbIdx);
    }
#endif /* CAN_DRV_FEATURE_MAX_MB_NUM > 64U */
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96U)
    else
    {
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            IntState = Can_Drv_GetMbInterruptStateFromBlock3(Id, MbIdx);
        }
    }
#endif

    return IntState;
}

/**
 * @brief      Enables/Disables specify error interrupt.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  IntType: Error interrupt type.
 * @param[in]  Enable: Enable/Disable.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Error interrupt enabled/disabled success.
 * @retval     CAN_DRV_ERROR:  Error interrupt enabled/disabled failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetErrorInterruptState(uint8 Id, Can_Drv_IntType IntType,
                                                               boolean Enable)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

    switch (IntType)
    {
        case CAN_DRV_INT_BUS_OFF:
        {
            Can_Drv_ProcessErrorIntConfigure(Id, CAN_DRV_INT_MSK_BUS_OFF, Enable);
            break;
        }
        case CAN_DRV_INT_ERR:
        {
            Can_Drv_ProcessErrorIntConfigure(Id, CAN_DRV_INT_MSK_ERR, Enable);
            break;
        }
        case CAN_DRV_INT_ERR_FAST:
        {
            Can_Drv_ProcessErrorIntConfigure(Id, CAN_DRV_INT_MSK_ERR_FAST, Enable);
            break;
        }
        case CAN_DRV_INT_HOST_MEM_ERR:
        {
            Can_Drv_ProcessEccIntConfigure(Id, (uint32)CAN_DRV_INT_HOST_MEM_ERR, Enable);
            break;
        }
        case CAN_DRV_INT_MEM_ERR:
        {
            Can_Drv_ProcessEccIntConfigure(Id, (uint32)CAN_DRV_INT_MEM_ERR, Enable);
            break;
        }
        case CAN_DRV_INT_COR_MEM_ERR:
        {
            Can_Drv_ProcessEccIntConfigure(Id, (uint32)CAN_DRV_INT_COR_MEM_ERR, Enable);
            break;
        }
        default:
        {
            /* Nothing to do */
            break;
        }
    }

    return ReturnValue;
}

/**
 * @brief      Sets Rx message buffer(IDE, CODE, Message id...).
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  IdType: Type of message ID (standard or extended).
 * @param[in]  MsgId: Message ID
 * @param[in]  Code: MB code.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx message buffer set success.
 * @retval     CAN_DRV_ERROR: Rx message buffer set failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetRxMb(uint8 Id, uint8 MbIdx, Can_Drv_MsgIdType IdType,
                                                uint32 MsgId, uint32 Code)
{
    Can_Drv_FdMbRegionType   Region;
    Can_Drv_MbType          *MbAddr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

    if (CAN_DRV_ERROR == Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddr))
    {
        ReturnValue = CAN_DRV_ERROR;
    }
    else
    {
        if (CAN_DRV_ERROR == Can_Drv_CheckMbId(Id, MbIdx))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
        else
        {
            MbAddr->Config.WORDVAL = 0;
            MbAddr->Id.WORDVAL = 0;
            /* Set the ID according to the Format structure */
            if (CAN_DRV_MSG_ID_EXT == IdType)
            {
                /* ID [28-0] */
                MbAddr->Id.WORDVAL = MsgId & CAN_DRV_ID_EXT_MASK;
                /* Set IDE */
                MbAddr->Config.BF.IDE = 1;
                /* Clear SRR bit */
                MbAddr->Config.BF.SRR = 0;
            }
            else if (CAN_DRV_MSG_ID_STD == IdType)
            {
                /* ID[28-18] */
                MbAddr->Id.BF.ID_STANDARD = MsgId;
                /* clear IDE  */
                MbAddr->Config.BF.IDE = 0;
                /* Clear SRR bit */
                MbAddr->Config.BF.SRR = 0;
            }
            else
            {
                /* Nothing to do */
            }

            if (Code != ((uint32)CAN_DRV_NOT_USED))
            {
                MbAddr->Config.BF.CODE = Code;
            }
        }
    }

    return ReturnValue;
}

/**
 * @brief      Processes set Tx message buffer.
 *
 * @param[out] MbAddr: Pointer to store the message buffer address.
 * @param[in]  MessageInfo: Message info.
 * @param[in]  MsgId: Message id.
 * @param[in]  MsgData: Message data.
 * @param[in]  Code: MB code.
 * @param[in]  LocalPrio: Local priority.
 *
 * @return     None
 *
 */
static void Can_Drv_ProcessSetTxMbBuffer(Can_Drv_MbType                *MbAddr,
                                         const Can_Drv_MessageInfoType *MessageInfo, uint32 MsgId,
                                         const uint8 *MsgData, uint32 Code, uint8 LocalPrio)
{
    uint8           Cnt;
    uint8           DataIndex;
    uint8           TmpNum;
    uint8           TmpIndex;
    uint32          Dlc;
    uint32          DataSize;
    volatile uint8 *MbData;

    /*Clean up the arbitration field area and set TxMB Inactive*/
    MbAddr->Config.BF.CODE = (uint32)CAN_DRV_MB_TX_INACTIVE;
    MbData = (volatile uint8 *)(&MbAddr->Data[0]);

    Can_Drv_ComputeDlcAndDataSize(MessageInfo->DataLen, &Dlc, &DataSize);
    /* Copy user's buffer into the message buffer Data area */
    if (MsgData != NULL_PTR)
    {
        TmpNum = (uint8)(MessageInfo->DataLen / 4U);
        for (Cnt = 0; Cnt < TmpNum; Cnt += 1U)
        {
            DataIndex = (Cnt * 4U);
            MbAddr->Data[Cnt] =
                ((uint32)MsgData[DataIndex] << 24U) | ((uint32)MsgData[DataIndex + 1U] << 16U) |
                ((uint32)MsgData[DataIndex + 2U] << 8U) | (uint32)MsgData[DataIndex + 3U];
        }

        for (Cnt = TmpNum * 4U; Cnt < MessageInfo->DataLen; Cnt++)
        {
            TmpIndex = CAN_DRV_SWAP_BYTES_IN_WORD_INDEX(Cnt) & 0x3FU;
            MbData[TmpIndex] = MsgData[Cnt];
        }
        /* Add padding, if needed */
        for (Cnt = MessageInfo->DataLen; Cnt < (uint8)DataSize; Cnt++)
        {
            TmpIndex = CAN_DRV_SWAP_BYTES_IN_WORD_INDEX(Cnt) & 0x3FU;
            MbData[TmpIndex] = MessageInfo->FdPadding;
        }
    }

    MbAddr->Config.WORDVAL = 0;
    MbAddr->Id.WORDVAL = 0;
    /* set DLC */
    MbAddr->Config.BF.DLC = Dlc;

    /* Set the ID according the Format structure */
    if (CAN_DRV_MSG_ID_EXT == MessageInfo->IdType)
    {
        /* ID [28-0] */
        MbAddr->Id.WORDVAL = MsgId & CAN_DRV_ID_EXT_MASK;
        MbAddr->Id.BF.PRIO = LocalPrio;
        /* Set IDE */
        MbAddr->Config.BF.IDE = 1;
        /* Set SRR bit */
        MbAddr->Config.BF.SRR = 1;
    }
    else if (CAN_DRV_MSG_ID_STD == MessageInfo->IdType)
    {
        /* ID[28-18] */
        MbAddr->Id.BF.ID_STANDARD = MsgId;
        MbAddr->Id.BF.PRIO = LocalPrio;

        /* clear IDE  */
        MbAddr->Config.BF.IDE = 0;
        /* Clear SRR bit */
        MbAddr->Config.BF.SRR = 0;
    }
    else
    {
        /* Nothing to do */
    }

    if (MessageInfo->RemoteFlag == TRUE)
    {
        /* Set RTR bit */
        MbAddr->Config.BF.RTR = 1;
    }

    /* Reset the Code */
    MbAddr->Config.BF.CODE = 0;

    if (TRUE == MessageInfo->FdEn)
    {
        MbAddr->Config.BF.EDL = 1;
    }

    MbAddr->Config.BF.BRS = (uint32)(MessageInfo->BrsEn);

    /* Set the Code */
    MbAddr->Config.BF.CODE = Code;
}

/**
 * @brief      Sets TX message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  MessageInfo: Message info.
 * @param[in]  MsgId: Message ID.
 * @param[in]  MsgData: Message data.
 * @param[in]  Code: MB code.
 * @param[in]  LocalPrio: Local priority.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Tx message buffer set success.
 * @retval     CAN_DRV_ERROR: Tx message buffer set failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetTxMb(uint8 Id, uint8 MbIdx,
                                                const Can_Drv_MessageInfoType *MessageInfo,
                                                uint32 MsgId, const uint8 *MsgData, uint32 Code,
                                                uint8 LocalPrio)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint8                    CanPayload;
    Can_Drv_FdMbRegionType   Region;
    Can_Drv_MbType          *MbAddr;
    Reg_Can_BfType          *CanRegisterBfPtr;
    Reg_Can_WType          *CanRegisterWPtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(MessageInfo != NULL_PTR);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    if (CAN_DRV_ERROR == Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddr))
    {
        ReturnValue = CAN_DRV_ERROR;
    }
    else
    {
        if (MessageInfo->DataLen > 64U)
        {
            ReturnValue = CAN_DRV_ERROR;
        }
        else
        {
            CanPayload = Can_Drv_GetPayloadSize(Id, Region);
            if ((CAN_DRV_SUCCESS == Can_Drv_CheckMbId(Id, MbIdx)) &&
                (MessageInfo->DataLen <= CanPayload))
            {
                if ((CanRegisterBfPtr->CAN_MCR.FDEN != 0U) && (MessageInfo->BrsEn == TRUE))
                {
                    CanRegisterWPtr->CAN_FDCTRL = ((CanRegisterWPtr->CAN_FDCTRL & (~CAN_DRV_TDCFAIL_MASK)) | 
                    ((uint32)1U << CAN_DRV_BIT_RATE_SWITCH_SHIFT));
                }
                Can_Drv_ProcessSetTxMbBuffer(MbAddr, MessageInfo, MsgId, MsgData, Code, LocalPrio);
            }
            else
            {
                ReturnValue = CAN_DRV_ERROR;
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      The function is used to process the sending of CAN message.
 *
 * @param[in]  MbAddr: Message buffer address.
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  TxInfo: TX MB info.
 * @param[in]  IsPolling: Polling status.
 * @param[in]  MsgId: Message id.
 * @param[in]  MsgData: Message data.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Message sent out success.
 * @retval     CAN_DRV_ERROR: Message buffer is invalid.
 * @retval     CAN_DRV_ENTER_BUSY: The message buffer is not valid state.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_ProcessTxMb(const Can_Drv_MbType *MbAddr, uint8 Id,
                                                    uint8                          MbIdx,
                                                    const Can_Drv_MessageInfoType *TxInfo,
                                                    boolean IsPolling, uint32 MsgId,
                                                    const uint8 *MsgData)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    Can_Drv_StateType       *StatePtr = Can_Drv_StatePtr[Id];
    uint32                   Code;

    /*mailbox Code */
    Code = MbAddr->Config.BF.CODE;
    if ((StatePtr->Mb[MbIdx].State != CAN_DRV_STATE_IDLE) ||
        ((Code != (uint32)CAN_DRV_MB_RX_INACTIVE) && (Code != (uint32)CAN_DRV_MB_TX_INACTIVE) &&
         (Code != (uint32)CAN_DRV_MB_TX_ABORT)))
    {
        ReturnValue = CAN_DRV_ENTER_BUSY;
    }
    else
    {
        /* Clear message buffer Flag */
        (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

        StatePtr->Mb[MbIdx].State = CAN_DRV_STATE_TX;
        StatePtr->Mb[MbIdx].RemoteFlag = TxInfo->RemoteFlag;
        StatePtr->Mb[MbIdx].TimeStamp = 0U;
        StatePtr->Mb[MbIdx].IsPolling = IsPolling;

        ReturnValue = Can_Drv_SetTxMb(Id, MbIdx, TxInfo, MsgId, MsgData,
                                      (uint32)CAN_DRV_MB_TX_DATA_REMOTE, 0);
#if (CAN_DRV_MB_INTERRUPT_SUPPORT == STD_ON)
        if ((CAN_DRV_SUCCESS == ReturnValue) && (FALSE == IsPolling))
        {
            /* Enable message buffer interrupt*/
            Can_Drv_ConfigMbInterrupt(Id, MbIdx, (boolean)TRUE, StatePtr->InterEn);
        }
#endif
    }

    return ReturnValue;
}

/**
 * @brief      Sets the CAN bit timing for standard frames or the arbitration
 *             phase of FD frames.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  TimeSeg: Pointer to store the settings of CAN bit timing.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: CAN bit timing for standard frames or the arbitration phase of FD
 * frames set success.
 * @retval     CAN_DRV_ERROR: The settings of CAN bit timing are invalid.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetStandardBitTiming(uint8                        Id,
                                                             const Can_Drv_BitTimingType *TimeSeg)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnVal = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (CAN_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(TimeSeg != NULL_PTR);
#endif

    /* Check the validation of time segments*/
    if ((0U == TimeSeg->PropSeg) || (0U == TimeSeg->PhaseSeg1) || (TimeSeg->PhaseSeg2 < 1U) ||
        (0U == TimeSeg->PreDivider) || (0U == TimeSeg->RJumpWidth))
    {
        ReturnVal = CAN_DRV_ERROR;
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_SetStandardBitTiming();
        CanRegisterBfPtr->CAN_CTRL1.PROPSEG = TimeSeg->PropSeg - 1U;
        CanRegisterBfPtr->CAN_CTRL1.PSEG2 = TimeSeg->PhaseSeg2 - 1U;
        CanRegisterBfPtr->CAN_CTRL1.PSEG1 = TimeSeg->PhaseSeg1 - 1U;
        CanRegisterBfPtr->CAN_CTRL1.PRESDIV = TimeSeg->PreDivider - 1U;
        CanRegisterBfPtr->CAN_CTRL1.RJW = TimeSeg->RJumpWidth - 1U;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_SetStandardBitTiming();
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnVal;
}

/**
 * @brief      Sets the CAN bit timing for the arbitration phase of FD frames of CAN.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  TimeSeg: Pointer to store the settings of the arbitration phase of FD frames of CAN.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: The arbitration phase of FD frames set success.
 * @retval     CAN_DRV_ERROR: The settings of the arbitration phase of FD frames are invalid.
 *
 */
static Can_Drv_ControllerStatus
Can_Drv_SetFdArbitrationBitTiming(uint8 Id, const Can_Drv_BitTimingType *TimeSeg)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnVal = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (CAN_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(TimeSeg != NULL_PTR);
#endif

    /* Check the validation of time segments */
    if ((0U == TimeSeg->PropSeg) || (0U == TimeSeg->PhaseSeg1) || (TimeSeg->PhaseSeg2 < 1U) ||
        (0U == TimeSeg->PreDivider) || (0U == TimeSeg->RJumpWidth))
    {
        ReturnVal = CAN_DRV_ERROR;
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_SetFdArbitrationBitTiming();
        CanRegisterBfPtr->CAN_CBT.EPROPSEG = TimeSeg->PropSeg - 1U;
        CanRegisterBfPtr->CAN_CBT.EPSEG2 = TimeSeg->PhaseSeg2 - 1U;
        CanRegisterBfPtr->CAN_CBT.EPSEG1 = TimeSeg->PhaseSeg1 - 1U;
        CanRegisterBfPtr->CAN_CBT.EPRESDIV = TimeSeg->PreDivider - 1U;
        CanRegisterBfPtr->CAN_CBT.ERJW = TimeSeg->RJumpWidth - 1U;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_SetFdArbitrationBitTiming();
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnVal;
}

/**
 * @brief      Sets the CAN bit timing for the data phase of FD frames of CAN.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  TimeSeg: Pointer to store the settings of data phase of FD frames.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: The data phase of FD frames set success.
 * @retval     CAN_DRV_ERROR: The settings of data phase of FD frames are invalid.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_ConfigFdDataBitTiming(uint8                        Id,
                                                              const Can_Drv_BitTimingType *TimeSeg)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnVal = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (CAN_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(TimeSeg != NULL_PTR);
#endif

    /* Check the validation of time segments */
    if ((0U == TimeSeg->PropSeg) || (0U == TimeSeg->PhaseSeg1) || (TimeSeg->PhaseSeg2 < 1U) ||
        (0U == TimeSeg->PreDivider) || (0U == TimeSeg->RJumpWidth))
    {
        ReturnVal = CAN_DRV_ERROR;
    }
    else
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_ConfigFdDataBitTiming();
        CanRegisterBfPtr->CAN_FDCBT.FPROPSEG = TimeSeg->PropSeg;
        CanRegisterBfPtr->CAN_FDCBT.FPSEG2 = TimeSeg->PhaseSeg2 - 1U;
        CanRegisterBfPtr->CAN_FDCBT.FPSEG1 = TimeSeg->PhaseSeg1 - 1U;
        CanRegisterBfPtr->CAN_FDCBT.FPRESDIV = TimeSeg->PreDivider - 1U;
        CanRegisterBfPtr->CAN_FDCBT.FRJW = TimeSeg->RJumpWidth - 1U;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_ConfigFdDataBitTiming();
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnVal;
}

/**
 * @brief      Returns the payload size.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Region: CAN FD MB region.
 *
 * @return     uint8: Payload size.
 *
 */
static uint8 Can_Drv_GetPayloadSize(uint8 Id, Can_Drv_FdMbRegionType Region)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    uint32                         PayloadSize = 0U;

    /* The standard Payload size is 8 bytes */
    if (CanRegisterBfPtr->CAN_MCR.FDEN != 0U)
    {
        switch (Region)
        {
            case CAN_DRV_CAN_FD_MB_REGION_0:
                PayloadSize = 1UL << (CanRegisterBfPtr->CAN_FDCTRL.MBDSR0 + 3U);
                break;
            case CAN_DRV_CAN_FD_MB_REGION_1:
                PayloadSize = 1UL << (CanRegisterBfPtr->CAN_FDCTRL.MBDSR1 + 3U);
                break;
            case CAN_DRV_CAN_FD_MB_REGION_2:
                PayloadSize = 1UL << (CanRegisterBfPtr->CAN_FDCTRL.MBDSR2 + 3U);
                break;
            case CAN_DRV_CAN_FD_MB_REGION_3:
                PayloadSize = 1UL << (CanRegisterBfPtr->CAN_FDCTRL.MBDSR3 + 3U);
                break;
            default:
                /* Nothing to do */
                break;
        }
    }
    else
    {
        PayloadSize = 8U;
    }

    return (uint8)PayloadSize;
}

/**
 * @brief      Gets the maximun MB number.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     uint8: Number of the maximum message buffer.
 *
 */
static uint8 Can_Drv_GetMaxMbNumLimit(uint8 Id)
{
    uint32 PayloadSize;
    uint8  ConfigFieldSize = 8U;
    uint32 RamBlockSize = 512U;
    uint32 MbSize;
    uint32 TotalMbNum;

    PayloadSize = Can_Drv_GetPayloadSize(Id, CAN_DRV_CAN_FD_MB_REGION_0);
    MbSize = PayloadSize + ConfigFieldSize;
    TotalMbNum = RamBlockSize / MbSize;

    PayloadSize = Can_Drv_GetPayloadSize(Id, CAN_DRV_CAN_FD_MB_REGION_1);
    MbSize = PayloadSize + ConfigFieldSize;
    TotalMbNum += (RamBlockSize / MbSize);

    if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
    {
        PayloadSize = Can_Drv_GetPayloadSize(Id, CAN_DRV_CAN_FD_MB_REGION_2);
        MbSize = PayloadSize + ConfigFieldSize;
        TotalMbNum += (RamBlockSize / MbSize);

        PayloadSize = Can_Drv_GetPayloadSize(Id, CAN_DRV_CAN_FD_MB_REGION_3);
        MbSize = PayloadSize + ConfigFieldSize;
        TotalMbNum += (RamBlockSize / MbSize);
    }

    return (uint8)TotalMbNum;
}

/**
 * @brief      Enters into freeze mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Enter into freeze mode success.
 * @retval     CAN_DRV_ERROR: Enter into freeze mode failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_EnterFreezeMode(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   TimeElapsedValue = 0U;
    uint32                   TimeCounter = 0U;
    uint32                   CurrentValue;
    uint32                   CanTimeoutDuration;

    if (0U == CanRegisterBfPtr->CAN_MCR.FRZACK)
    {
        CanTimeoutDuration =
            McalLib_MicroSecToTicks(CAN_DRV_SERVICE_TIMEOUT_TYPE, CAN_DRV_TIMEOUT_DURATION);

        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_CanMcrReg();
        CanRegisterBfPtr->CAN_MCR.FRZ = 1U;
        CanRegisterBfPtr->CAN_MCR.HALT = 1U;
        if (CanRegisterBfPtr->CAN_MCR.MDIS != 0U)
        {
            CanRegisterBfPtr->CAN_MCR.MDIS = 0U;
        }
        SchM_Exit_Can_CanMcrReg();
        /* End critical section: implementation depends on integrator */

        /* Wait for entering into disable mode */
        (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);

        while (0U == CanRegisterBfPtr->CAN_MCR.NOTRDY)
        {
            (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                          &TimeElapsedValue);
            TimeCounter += TimeElapsedValue;
            if (TimeCounter > CanTimeoutDuration)
            {
                ReturnValue = CAN_DRV_ERROR;
                break;
            }
        }

        TimeCounter = 0;
        /* Wait for entering into freeze mode */
        (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);
        while ((0U == CanRegisterBfPtr->CAN_MCR.FRZACK) && (CAN_DRV_SUCCESS == ReturnValue))
        {
            (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                          &TimeElapsedValue);
            TimeCounter += TimeElapsedValue;
            if (TimeCounter > CanTimeoutDuration)
            {
                ReturnValue = CAN_DRV_ERROR;
                break;
            }
        }
    }

    return ReturnValue;
}

/**
 * @brief      Exits from freeze mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Exit from freeze mode success.
 * @retval     CAN_DRV_ERROR: Exit from freeze mode failed
 *
 */
static Can_Drv_ControllerStatus Can_Drv_ExitFreezeMode(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   TimeElapsedValue = 0U;
    uint32                   TimeCounter = 0U;
    uint32                   CurrentValue;
    uint32                   CanTimeoutDuration;

    CanTimeoutDuration =
        McalLib_MicroSecToTicks(CAN_DRV_SERVICE_TIMEOUT_TYPE, CAN_DRV_TIMEOUT_DURATION);
    /*Exit Freeze Mode*/
    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_CanMcrReg();
    CanRegisterBfPtr->CAN_MCR.HALT = 0U;
    CanRegisterBfPtr->CAN_MCR.FRZ = 0U;
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_CanMcrReg();

    /* Wait for exit from the Freeze Mode */
    (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);
    while (1U == CanRegisterBfPtr->CAN_MCR.FRZACK)
    {
        (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                        &TimeElapsedValue);
        TimeCounter += TimeElapsedValue;
        if (TimeCounter > CanTimeoutDuration)
        {
            ReturnValue = CAN_DRV_ERROR;
            break;
        }
    }

    return ReturnValue;
}

/**
 * @brief      Soft resets controller.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Reset controller success.
 * @retval     CAN_DRV_ERROR: Reset controller failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SoftResetController(uint8 Id)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_SUCCESS;

    /* Enable this channel if needed */
    if (1U == CanRegisterBfPtr->CAN_MCR.MDIS)
    {
        ReturnValue = Can_Drv_Enable(Id);
    }

    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        ReturnValue = Can_Drv_ExecuteSoftReset(Id);
    }

    return ReturnValue;
}

/**
 * @brief      This function will configure CAN global parameters with provided parameters.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  ConfigPtr: Pointer to store the controller global parameters.
 *
 * @return     None
 *
 */
static void Can_Drv_SetGlobalConfig(uint8 Id, const Can_Drv_ConfigType *ConfigPtr)
{
    Reg_Can_BfType *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    /*Edge Filter Disable set*/
    if (CAN_DRV_EDFLTDIS == ((ConfigPtr->CtrlConfig) & CAN_DRV_EDFLTDIS))
    {
        CanRegisterBfPtr->CAN_CTRL2.EDFLTDIS = 1U;
    }
    else
    {
        CanRegisterBfPtr->CAN_CTRL2.EDFLTDIS = 0U;
    }

    /* enables the CAN FD protocol according to ISO specification (ISO 11898-1)*/
    if (CAN_DRV_ISOCANFDEN == ((ConfigPtr->CtrlConfig) & CAN_DRV_ISOCANFDEN))
    {
        CanRegisterBfPtr->CAN_CTRL2.ISOCANFDEN = 1U;
    }
    else
    {
        CanRegisterBfPtr->CAN_CTRL2.ISOCANFDEN = 0U;
    }

    /*Protocol Exception set*/
    if (CAN_DRV_PREXCEN == ((ConfigPtr->CtrlConfig) & CAN_DRV_PREXCEN))
    {
        CanRegisterBfPtr->CAN_CTRL2.PREXCEN = 1U;
    }
    else
    {
        CanRegisterBfPtr->CAN_CTRL2.PREXCEN = 0U;
    }

    /* SWS_Can_00274: Disable automatic bus-off recovery */
    CanRegisterBfPtr->CAN_CTRL1.BOFFREC = 1U;

    /*CAN Bit Sampling.*/
    if (CAN_DRV_SMP == ((ConfigPtr->CtrlConfig) & CAN_DRV_SMP))
    {
        CanRegisterBfPtr->CAN_CTRL1.SMP = 1U;
    }
    else
    {
        CanRegisterBfPtr->CAN_CTRL1.SMP = 0U;
    }

    /*Lowest Buffer Transmitted First.*/
    if (CAN_DRV_LBUF == ((ConfigPtr->CtrlConfig) & CAN_DRV_LBUF))
    {
        CanRegisterBfPtr->CAN_CTRL1.LBUF = 1U;
    }
    else
    {
        CanRegisterBfPtr->CAN_CTRL1.LBUF = 0U;
    }

    /* Disable the self reception feature if CAN is not in loopback Mode. */
    if (ConfigPtr->Mode != CAN_DRV_MODE_LOOPBACK)
    {
        CanRegisterBfPtr->CAN_MCR.SRXDIS = 1U;
    }
}

/**
 * @brief      Sets baudrate parameters of the given controller.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  ConfigPtr: Pointer to store the baudrate configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Baudrate set success.
 * @retval     CAN_DRV_SUCCESS: Baudrate set failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetBaudRate(uint8 Id, const Can_Drv_ConfigType *ConfigPtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_FEATURE_HAS_FD)
    Reg_Can_WType *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];

    if (TRUE == ConfigPtr->FdEn)
    {
        /* set Payload */
        CanRegisterWPtr->CAN_FDCTRL &= ~(CAN_DRV_TDCFAIL_MASK | CAN_DRV_FDCTRL_MBDSR0_MASK | CAN_DRV_FDCTRL_MBDSR1_MASK);
        CanRegisterWPtr->CAN_FDCTRL = ((CanRegisterWPtr->CAN_FDCTRL & (~CAN_DRV_TDCFAIL_MASK)) |        
        ((((uint32)ConfigPtr->Payload.Block0) << CAN_DRV_MB_REGION_0_SHIFT) & CAN_DRV_FDCTRL_MBDSR0_MASK) | 
        ((((uint32)ConfigPtr->Payload.Block1) << CAN_DRV_MB_REGION_1_SHIFT)& CAN_DRV_FDCTRL_MBDSR1_MASK));

        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            CanRegisterWPtr->CAN_FDCTRL &= ~(CAN_DRV_TDCFAIL_MASK | CAN_DRV_FDCTRL_MBDSR2_MASK | CAN_DRV_FDCTRL_MBDSR3_MASK);
            CanRegisterWPtr->CAN_FDCTRL = ((CanRegisterWPtr->CAN_FDCTRL & (~CAN_DRV_TDCFAIL_MASK)) |        
            ((((uint32)ConfigPtr->Payload.Block2) << CAN_DRV_MB_REGION_2_SHIFT) & CAN_DRV_FDCTRL_MBDSR2_MASK) | 
            ((((uint32)ConfigPtr->Payload.Block3) << CAN_DRV_MB_REGION_3_SHIFT)& CAN_DRV_FDCTRL_MBDSR3_MASK));
        }

        /* set CanFd timing */
        if (CAN_DRV_ERROR == Can_Drv_SetFdArbitrationBitTiming(Id, &(ConfigPtr->BitTiming)))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
        else
        {
            ReturnValue = Can_Drv_ConfigFdDataBitTiming(Id, &(ConfigPtr->BitTimingFdData));
        }
    }
    else
    {
        /* set standard timing */
        if (CAN_DRV_ERROR == Can_Drv_SetStandardBitTiming(Id, &(ConfigPtr->BitTiming)))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }
#else
    /* set standard timing */
    if (CAN_DRV_ERROR == Can_Drv_SetStandardBitTiming(Id, &(ConfigPtr->BitTiming)))
    {
        ReturnValue = CAN_DRV_ERROR;
    }
#endif

    return ReturnValue;
}

/**
 * @brief      Configs FIFO and DMA mode of the given controller.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  ConfigPtr: Pointer to store the FIFO configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: FIFO and DMA set success.
 * @retval     CAN_DRV_ERROR: FIFO and DMA set failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetFifoParameter(uint8                     Id,
                                                         const Can_Drv_ConfigType *ConfigPtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

#if (STD_ON == CAN_DRV_RX_FIFO_ENABLE)
    /* Config RX FIFO */
    if (TRUE == ConfigPtr->RxFifoEn)
    {
        if (TRUE == ConfigPtr->FdEn)
        {
            ReturnValue = CAN_DRV_ERROR;
        }
        else
        {
            SchM_Enter_Can_CanMcrReg();
            /* Enable RX FIFO */
            CanRegisterBfPtr->CAN_MCR.RFEN = 1;
            SchM_Exit_Can_CanMcrReg();
            /* Set the number of the RX FIFO filters needed */
            CanRegisterBfPtr->CAN_CTRL2.RFFN = (uint32)(ConfigPtr->RxFifoIdFilterNum);

    #if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
            if (CAN_DRV_RXFIFO_DMA == ConfigPtr->TransferType)
            {
                SchM_Enter_Can_CanMcrReg();
                CanRegisterBfPtr->CAN_MCR.DMAE = 1;
                SchM_Exit_Can_CanMcrReg();
            }
            else
    #endif
            {
                SchM_Enter_Can_CanMcrReg();
                CanRegisterBfPtr->CAN_MCR.DMAE = 0;
                SchM_Exit_Can_CanMcrReg();
            }
        }
    }
    else
    {
        SchM_Enter_Can_CanMcrReg();
        /* Disable RX FIFO */
        CanRegisterBfPtr->CAN_MCR.RFEN = 0;
        SchM_Exit_Can_CanMcrReg();
        if (CAN_DRV_RXFIFO_DMA == ConfigPtr->TransferType)
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }
#else
    SchM_Enter_Can_CanMcrReg();
    /* Disable RX FIFO */
    CanRegisterBfPtr->CAN_MCR.RFEN = 0;
    SchM_Exit_Can_CanMcrReg();
    if (CAN_DRV_RXFIFO_DMA == ConfigPtr->TransferType)
    {
        ReturnValue = CAN_DRV_ERROR;
    }
#endif

    return ReturnValue;
}

/**
 * @brief      Sets controller operation mode(Normal, Freeze, Loop-Back, Listen only and Disabled).
 *
 * @param[in]  Id: Channel id.
 * @param[in]  ConfigPtr: Pointer to store the controller configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Set mode success.
 * @retval     CAN_DRV_ERROR: Set mode failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetMode(uint8 Id, const Can_Drv_ConfigType *ConfigPtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    if ((ConfigPtr->MbMaxNum > Can_Drv_GetMaxMbNumLimit(Id)) ||
        (ConfigPtr->MbMaxNum > Can_Drv_GetMbNum(Id)))
    {
        ReturnValue = CAN_DRV_ERROR;
    }
    else
    {
        CanRegisterBfPtr->CAN_MCR.MAXMB = ConfigPtr->MbMaxNum - 1U;
        /* CAN is able to enter into doze Mode when received entering wait-Mode request */
        CanRegisterBfPtr->CAN_MCR.DOZE = 1U;
        ReturnValue = Can_Drv_SetOperationMode(Id, ConfigPtr->Mode);

        if (CAN_DRV_SUCCESS == ReturnValue)
        {
            /* In case of entering into freeze mode this time, no need exit from freeze mode. */
            if (ConfigPtr->Mode != CAN_DRV_MODE_FREEZE)
            {
                if (CAN_DRV_SUCCESS != Can_Drv_ExitFreezeMode(Id))
                {
                    ReturnValue = CAN_DRV_ERROR;
                }
            }
        }
    }

    return ReturnValue;
}

/**
 * @brief      Initializes the CAN controller.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  ConfigPtr: Pointer to store the controller configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: The CAN controller initialized success.
 * @retval     CAN_DRV_ERROR: The CAN controller initialized failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_InitHandle(uint8 Id, const Can_Drv_ConfigType *ConfigPtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    Reg_Can_WType           *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    ReturnValue = Can_Drv_SoftResetController(Id);

    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        CanRegisterBfPtr->CAN_MCR.AEN = 1U;

        /* Clear ram */
        Can_Drv_ClearRam(Id);

        /* Disable all MB interrupts */
        CanRegisterWPtr->CAN_IMASK1 = 0U;
        /* Clear all MB interrupt flags */
        CanRegisterWPtr->CAN_IFLAG1 = 0xFFFFFFFFU;
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32)
        /* Disable all MB interrupts */
        CanRegisterWPtr->CAN_IMASK2 = 0U;
        /* Clear all MB interrupt flags */
        CanRegisterWPtr->CAN_IFLAG2 = 0xFFFFFFFFU;
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            /* Disable all MB interrupts */
            CanRegisterWPtr->CAN_IMASK3 = 0U;
            /* Clear all MB interrupt flags */
            CanRegisterWPtr->CAN_IFLAG3 = 0xFFFFFFFFU;
        }
#endif
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            /* Disable all MB interrupts */
            CanRegisterWPtr->CAN_IMASK4 = 0U;
            /* Clear all MB interrupt flags */
            CanRegisterWPtr->CAN_IFLAG4 = 0xFFFFFFFFU;
        }
#endif

        /* Clear all error interrupt flags */
        CanRegisterWPtr->CAN_ESR1 = CAN_DRV_INT_MSK_FLAG_ALL_1;
        CanRegisterWPtr->CAN_ERRSR = CAN_DRV_INT_MSK_FLAG_ALL_ECC;
        CanRegisterWPtr->CAN_WU_MTC = CAN_DRV_INT_MSK_FLAG_ALL_PN;
        /* clear registers which are not effected by soft reset */
        CanRegisterWPtr->CAN_CTRL1 = CAN_DRV_CTRL1_DEFAULT_VALUE;
        CanRegisterWPtr->CAN_CTRL2 = CAN_DRV_CTRL2_DEFAULT_VALUE;
        CanRegisterWPtr->CAN_CBT = CAN_DRV_CBT_DEFAULT_VALUE;

#if (STD_ON == CAN_DRV_FEATURE_HAS_FD)
        CanRegisterWPtr->CAN_FDCBT = CAN_DRV_FDCBT_DEFAULT_VALUE;
        CanRegisterWPtr->CAN_FDCTRL = CAN_DRV_FDCTRL_DEFAULT_VALUE;
        /* set FD */
        CanRegisterBfPtr->CAN_MCR.FDEN = (uint32)(ConfigPtr->FdEn);
        /* Enable the use of extended bit time definitions */
        CanRegisterBfPtr->CAN_CBT.BTF = (uint32)(ConfigPtr->FdEn);

        /* Disable Transmission Delay Compensation by default */
        CanRegisterWPtr->CAN_FDCTRL = ((CanRegisterWPtr->CAN_FDCTRL) & 
           (~(CAN_DRV_TDCFAIL_MASK | ((uint32)1U << CAN_DRV_TDCEN_SHIFT))));
        /*Set Bit Rate Switch*/
        CanRegisterWPtr->CAN_FDCTRL &= (~(CAN_DRV_TDCFAIL_MASK | 
        CAN_DRV_BIT_RATE_SWITCH_MASK));
        CanRegisterWPtr->CAN_FDCTRL = 
        ((CanRegisterWPtr->CAN_FDCTRL) & (~(CAN_DRV_TDCFAIL_MASK ))) | 
        (((uint32)(ConfigPtr->BitRateSwitch) << CAN_DRV_BIT_RATE_SWITCH_SHIFT));
#endif
        Can_Drv_SetGlobalConfig(Id, ConfigPtr);

        if (CAN_DRV_SUCCESS == Can_Drv_SetBaudRate(Id, ConfigPtr))
        {
            if (CAN_DRV_ERROR == Can_Drv_SetFifoParameter(Id, ConfigPtr))
            {
                ReturnValue = CAN_DRV_ERROR;
            }
            else
            {
                ReturnValue = Can_Drv_SetMode(Id, ConfigPtr);
            }
        }
        else
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }

    return ReturnValue;
}

/**
 * @brief      Sets operation mode.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Mode: Operation mode.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Set operation mode success.
 * @retval     CAN_DRV_ERROR: Set operation mode failed.
 *
 */
static Can_Drv_ControllerStatus Can_Drv_SetOperationMode(uint8 Id, Can_Drv_ModeType Mode)
{
    Reg_Can_BfType          *CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Reg_Can_WType          *CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

    switch (Mode)
    {
        case CAN_DRV_MODE_NORMAL:
            CanRegisterBfPtr->CAN_CTRL1.LOM = 0;
            CanRegisterBfPtr->CAN_CTRL1.LPB = 0;
            CanRegisterBfPtr->CAN_MCR.SUPV = 0;
            break;
        case CAN_DRV_MODE_LISTEN_ONLY:
            CanRegisterBfPtr->CAN_CTRL1.LOM = 1;
            break;
        case CAN_DRV_MODE_LOOPBACK:
            CanRegisterBfPtr->CAN_CTRL1.LOM = 0;
            CanRegisterBfPtr->CAN_CTRL1.LPB = 1;
            CanRegisterBfPtr->CAN_MCR.SRXDIS = 0;
            CanRegisterWPtr->CAN_FDCTRL &=  (~(CAN_DRV_TDCFAIL_MASK | \
                          ((uint32)1U << CAN_DRV_TDCEN_SHIFT)));
            break;
        case CAN_DRV_MODE_FREEZE:
            if (CAN_DRV_SUCCESS != Can_Drv_EnterFreezeMode(Id))
            {
                ReturnValue = CAN_DRV_ERROR;
            }
            break;
        case CAN_DRV_MODE_DISABLE:
            CanRegisterBfPtr->CAN_MCR.MDIS = 1;
            break;
        default:
            ReturnValue = CAN_DRV_ERROR;
            break;
    }

    return ReturnValue;
}

/**
 * @brief      Rx FIFO interrupt handler.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
static void Can_Drv_RxFifoIrqHandler(uint8 Id, uint8 MbIdx)
{
    Can_Drv_MsgBufType Data;
    Can_Drv_StateType *StatePtr = Can_Drv_StatePtr[Id];

        
    if (CAN_DRV_RXFIFO_FRAME_AVAILABLE == MbIdx)
    {
        if (CAN_DRV_STATE_RX == StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State)
        {
            if(NULL_PTR == StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr)
            {
                StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr = &Data;
            }
            /* Read a frame in RX FIFO. */
            Can_Drv_ReadRxFifo(Id, StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr);
            /*clear interrupt Status*/
            (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

            StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State = CAN_DRV_STATE_IDLE;

            if (StatePtr->IrqCallback != NULL_PTR)
            {
                StatePtr->IrqCallback(Id, CAN_DRV_INT_RXFIFO_FRAME, CAN_DRV_RXFIFO_START_INDEX,
                                      StatePtr);
            }

            if (CAN_DRV_STATE_IDLE == StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State)
            {
                /* reset to default Value */
                StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].IsPolling = (boolean)TRUE;
                /* Complete receive Data */
                Can_Drv_CompleteRxFifoData(Id);
            }
        }
    }
    else if (CAN_DRV_RXFIFO_WARNING == MbIdx)
    {
        /*clear interrupt Status*/
        (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

        if (StatePtr->IrqCallback != NULL_PTR)
        {
            StatePtr->IrqCallback(Id, CAN_DRV_INT_RXFIFO_WARNING, CAN_DRV_RXFIFO_START_INDEX,
                                  StatePtr);
        }

    }
    else if (CAN_DRV_RXFIFO_OVERFLOW == MbIdx)
    {
        /*clear interrupt Status*/
        (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

        if (StatePtr->IrqCallback != NULL_PTR)
        {
            StatePtr->IrqCallback(Id, CAN_DRV_INT_RXFIFO_OVERFLOW, CAN_DRV_RXFIFO_START_INDEX,
                                  StatePtr);
        }
    }
    else
    {
        /* Nothing to do */
    }
}

/**
 * @brief      Unlocks Tx message buffer.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     None
 *
 */
static void Can_Drv_UnlockRxMsgBuff(uint8 Id)
{
    const volatile Reg_Can_WType *CanRegisterWPtr;

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    /* Unlock the mailbox by reading the free running timer */
    (void)CanRegisterWPtr->CAN_TIMER;
}

/**
 * @brief      Rx MB interrupt handler.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
static void Can_Drv_RxMbIrqHandler(uint8 Id, uint8 MbIdx)
{
    Can_Drv_MsgBufType Data;
    Can_Drv_StateType *StatePtr = Can_Drv_StatePtr[Id];
    boolean            CurInterStatus = (boolean)FALSE;

    if (NULL_PTR == StatePtr->Mb[MbIdx].MbMessagePtr)
    {
        StatePtr->Mb[MbIdx].MbMessagePtr = &Data;
    }

    /* Get a message buffer field values.*/
    Can_Drv_GetMsgBuff(Id, MbIdx, StatePtr->Mb[MbIdx].MbMessagePtr);

    /* Clear message buffer Flag */
    (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

    StatePtr->Mb[MbIdx].State = CAN_DRV_STATE_IDLE;

    CurInterStatus = StatePtr->Mb[MbIdx].IsPolling;

    if (StatePtr->IrqCallback != NULL_PTR)
    {
        StatePtr->IrqCallback(Id, CAN_DRV_INT_MB_RECEIVE, MbIdx, StatePtr);
    }

    if (FALSE == StatePtr->Mb[MbIdx].IsPolling)
    {
        if (CAN_DRV_STATE_IDLE == StatePtr->Mb[MbIdx].State)
        {
            StatePtr->Mb[MbIdx].IsPolling = (boolean)TRUE;
            Can_Drv_ConfigMbInterrupt(Id, MbIdx, (boolean)FALSE, StatePtr->InterEn);
        }
    }
    else
    {
        if (FALSE == CurInterStatus)
        {
            Can_Drv_ConfigMbInterrupt(Id, MbIdx, (boolean)FALSE, StatePtr->InterEn);
        }
    }
}

/**
 * @brief      Tx MB interrupt handler.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
static void Can_Drv_TxMbIrqHandler(uint8 Id, uint8 MbIdx)
{
    Can_Drv_StateType *StatePtr = Can_Drv_StatePtr[Id];
    boolean            CurInterStatus = (boolean)FALSE;
    Can_Drv_MsgBufType Data;

    if (TRUE == StatePtr->Mb[MbIdx].RemoteFlag)
    {
        /* Get a message buffer field values.*/
        StatePtr->Mb[MbIdx].MbMessagePtr = &Data;
        Can_Drv_GetMsgBuff(Id, MbIdx, StatePtr->Mb[MbIdx].MbMessagePtr);

        /* If the frame was a remote frame, clear the Flag only if the response was
           not received yet. If the response was received, leave the Flag set in order
           to be handled when the user calls CAN_DRV_RxMessageBuffer. */
        if ((uint32)CAN_DRV_MB_RX_EMPTY ==
            (((StatePtr->Mb[MbIdx].MbMessagePtr)->Cs & CAN_DRV_CS_CODE_MASK) >>
             CAN_DRV_CS_CODE_SHIFT))
        {
            (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);
        }
    }
    else
    {
        StatePtr->Mb[MbIdx].TimeStamp = Can_Drv_GetMsgBuffTimeStamp(Id, MbIdx);
        Can_Drv_UnlockRxMsgBuff(Id);
        (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);
    }

    StatePtr->Mb[MbIdx].State = CAN_DRV_STATE_IDLE;

    CurInterStatus = StatePtr->Mb[MbIdx].IsPolling;

    if (StatePtr->IrqCallback != NULL_PTR)
    {
        StatePtr->IrqCallback(Id, CAN_DRV_MB_TRANSMIT, MbIdx, StatePtr);
    }

    if (FALSE == StatePtr->Mb[MbIdx].IsPolling)
    {
        if (CAN_DRV_STATE_IDLE == StatePtr->Mb[MbIdx].State)
        {
            StatePtr->Mb[MbIdx].IsPolling = (boolean)TRUE;
            /* Disable the transmitter Data register empty interrupt for case: Mb is interrupt (it
             * was not use in above callback with the same index) */
            Can_Drv_ConfigMbInterrupt(Id, MbIdx, (boolean)FALSE, StatePtr->InterEn);
        }
    }
    else
    {
        if (FALSE == CurInterStatus)
        {
            Can_Drv_ConfigMbInterrupt(Id, MbIdx, (boolean)FALSE, StatePtr->InterEn);
        }
    }
}

/**
 * @brief     Abnormal interrupt handler.
 *
 * @param[in] Id: Channel id.
 * @param[in] IsAbnormal: Abnormal interrupt flag.
 * @param[in] StartMbIdx: Start message buffer.
 * @param[in] EndMbIdx: End message buffer.
 *
 * @return    None
 *
 */
static void Can_Drv_ProcessMbAbnormalInter(uint8 Id, boolean IsAbnormal, uint32 StartMbIdx,
                                           uint32 EndMbIdx)
{
    uint32             MbCounter = 0;
    uint32             InterFlag = 0;
    boolean            CanIntMask = FALSE;
    uint32             MbIdx = 0U;
    Can_Drv_StateType *StatePtr = Can_Drv_StatePtr[Id];

    if (TRUE == IsAbnormal)
    {
        /* Process spurious interrupt */
        for (MbCounter = StartMbIdx; MbCounter <= EndMbIdx; MbCounter++)
        {
            CanIntMask = Can_Drv_GetMbInterruptState(Id, (uint8)MbCounter);
            InterFlag = Can_Drv_ReadMbInterruptFlag(Id, MbCounter);
            if (((uint8)0U != InterFlag) && (FALSE == CanIntMask))
            {
                MbIdx = MbCounter;
                if ((TRUE == StatePtr->RxFifoEn) && (MbCounter <= CAN_DRV_RXFIFO_OVERFLOW))
                {
                    MbIdx = (uint32)CAN_DRV_RXFIFO_START_INDEX;
                }
                if ((FALSE == StatePtr->Mb[MbIdx].IsPolling))
                {
                    /*clear interrupt */
                    (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbCounter);
                    if (CAN_DRV_STATE_TX == StatePtr->Mb[MbIdx].State)
                    {
                        /* reset to default State */
                        StatePtr->Mb[MbIdx].State = CAN_DRV_STATE_IDLE;
                        StatePtr->Mb[MbIdx].IsPolling = (boolean)TRUE;
                    }
                }
            }
        }
    }
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

/**
* @brief      This function cancels transmission of the given MB.

* @param[in]  Id: Channel id.
* @param[in]  MbIdx: Message buffer id.
*
* @return     Can_Drv_ControllerStatus
* @retval     CAN_DRV_SUCCESS: Abort command success
* @retval     CAN_DRV_ERROR:  Abort command error
* @retval     CAN_DRV_ENTER_BUSY: Abort command busy
* @retval     CAN_DRV_NO_TRANSMIT:  command is idle

*/
Can_Drv_ControllerStatus Can_Drv_AbortTransfer(uint8 Id, uint8 MbIdx)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    Can_Drv_StateType       *StatePtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    if (Can_Drv_CheckMbIdRange(Id, MbIdx) != CAN_DRV_SUCCESS)
    {
        ReturnValue = CAN_DRV_ERROR;
    }
    else
    {
        if (CAN_DRV_STATE_IDLE == StatePtr->Mb[MbIdx].State)
        {
            ReturnValue = CAN_DRV_NO_TRANSMIT;
        }
        else
        {
            /*clear interrupt Status*/
            Can_Drv_ConfigMbInterrupt(Id, MbIdx, (boolean)FALSE, StatePtr->InterEn);
            if (CAN_DRV_STATE_TX == StatePtr->Mb[MbIdx].State)
            {
                ReturnValue = Can_Drv_AbortTxTransfer(Id, MbIdx);
            }
            else if (CAN_DRV_STATE_RX == StatePtr->Mb[MbIdx].State)
            {
                (void)Can_Drv_AbortRxTransfer(Id, MbIdx);
            }
            else
            {
                /* Nothing to do */
            }

            StatePtr->Mb[MbIdx].State = CAN_DRV_STATE_IDLE;
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Configures a Rx message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  IdType: Message type (standard or extended).
 * @param[in]  MsgId: Message id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Configure command success
 * @retval     CAN_DRV_ERROR:  Configure command error
 * @retval     CAN_DRV_ENTER_BUSY: Configure command busy
 * @retval     CAN_DRV_NO_TRANSMIT:  idle Status
 *
 */
Can_Drv_ControllerStatus Can_Drv_ConfigRxMb(uint8 Id, uint8 MbIdx, Can_Drv_MsgIdType IdType,
                                            uint32 MsgId)
{
    Can_Drv_ControllerStatus Result = CAN_DRV_ERROR;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    /* Clear the message buffer Flag if previous remained triggered */
    if (CAN_DRV_SUCCESS == Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx))
    {
        /* Initialize rx Mb*/
        if (CAN_DRV_SUCCESS == Can_Drv_SetRxMb(Id, MbIdx, IdType, MsgId, (uint32)CAN_DRV_NOT_USED))
        {
            /* Initialize receive MB*/
            if (CAN_DRV_SUCCESS ==
                Can_Drv_SetRxMb(Id, MbIdx, IdType, MsgId, (uint32)CAN_DRV_MB_RX_INACTIVE))
            {
                /* Clear the message buffer Flag if previous remained triggered*/
                if (CAN_DRV_SUCCESS == Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx))
                {
                    Result = Can_Drv_SetRxMb(Id, MbIdx, IdType, MsgId, (uint32)CAN_DRV_MB_RX_EMPTY);
                }
            }
        }
    }
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Result;
}

/**
 * @brief      Initializes controller.
 *
 * @param[in]  Id: Channel id.
 * @param[out] CanStatePtr: Channel configuration.
 * @param[in]  CanConfigPtr: Controller configuration parameters.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Channel initialized success.
 * @retval     CAN_DRV_ERROR: Channel initialized failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_Init(uint8 Id, Can_Drv_StateType *CanStatePtr,
                                      const Can_Drv_ConfigType *CanConfigPtr)
{
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_SUCCESS;
    const volatile Reg_Can_BfType *CanRegisterBfPtr = NULL_PTR;
    uint32                         MbIndex;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(CanStatePtr != NULL_PTR);
    MCALLIB_DEV_ASSERT(CanConfigPtr != NULL_PTR);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    ReturnValue = Can_Drv_InitHandle(Id, CanConfigPtr);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        for (MbIndex = 0; MbIndex <= (uint8)(CanRegisterBfPtr->CAN_MCR.MAXMB); MbIndex++)
        {
            CanStatePtr->Mb[MbIndex].IsPolling = (boolean)TRUE;
            CanStatePtr->Mb[MbIndex].MbMessagePtr = NULL_PTR;
            CanStatePtr->Mb[MbIndex].State = CAN_DRV_STATE_IDLE;
            CanStatePtr->Mb[MbIndex].TimeStamp = 0U;
            CanStatePtr->Mb[MbIndex].RemoteFlag = (boolean)FALSE;
        }

        CanStatePtr->TransferType = CanConfigPtr->TransferType;

        CanStatePtr->IrqCallback = CanConfigPtr->IrqCallback;
        CanStatePtr->ErrCallback = CanConfigPtr->ErrCallback;
        CanStatePtr->RxFifoEn = CanConfigPtr->RxFifoEn;
        CanStatePtr->MaxMbNumber = CanConfigPtr->MbMaxNum;
        CanStatePtr->InterEn = (boolean)TRUE;
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
        CanStatePtr->RxFifoDMAChannel = CanConfigPtr->RxFifoDMAChannel;
#endif
        /* set current State pointer */
        Can_Drv_StatePtr[Id] = CanStatePtr;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
  * @brief      De-inits the CAN peripheral. This function disables all CAN
                interrupts, and Disable the CAN
  *
  * @param[in]  Id: Channel id.
  *
  * @return     Can_Drv_ControllerStatus
  * @retval     CAN_DRV_SUCCESS: DeInit command success
  * @retval     CAN_DRV_ERROR:  DeInit command error
  *
  */
Can_Drv_ControllerStatus Can_Drv_Deinit(uint8 Id)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_ERROR;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    ReturnValue = Can_Drv_EnterFreezeMode(Id);

    /* Reset all registers setting */
    Can_Drv_ResetConfiguration(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        ReturnValue = Can_Drv_Disable(Id);
        /* clear current State pointer */
        Can_Drv_StatePtr[Id] = NULL_PTR;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Disables MB interrupts of the given controller.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: MB interrupts of the given controller disabled success.
 * @retval     CAN_DRV_ERROR: MB interrupts of the given controller disabled failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_DisableMbInterrupts(uint8 Id)
{
    Reg_Can_WType                 *CanRegisterWPtr;
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_ERROR;
    Can_Drv_StateType             *StatePtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    StatePtr = Can_Drv_StatePtr[Id];

    if (0U == CanRegisterBfPtr->CAN_MCR.MDIS)
    {
        CanRegisterWPtr->CAN_IMASK1 = 0U;
#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 32)
        CanRegisterWPtr->CAN_IMASK2 = 0U;
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 64)
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            CanRegisterWPtr->CAN_IMASK3 = 0U;
        }
#endif

#if (CAN_DRV_SUPPORT_MAX_MB_NUM > 96)
        if (((uint8)CAN_DRV_ID_6 == Id) || ((uint8)CAN_DRV_ID_7 == Id))
        {
            CanRegisterWPtr->CAN_IMASK4 = 0U;
        }
#endif
        StatePtr->InterEn = (boolean)FALSE;
        ReturnValue = CAN_DRV_SUCCESS;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      This function receives a CAN frame into a configured message buffer via normal mode.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  DataPtr: Pointer to store the received data.
 * @param[in]  IsPolling: Polling mode/Interrupt mode.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Receive can frame success
 * @retval     CAN_DRV_ERROR:   Receive can frame has not been accepted.
 *
 */
Can_Drv_ControllerStatus Can_Drv_Receive(uint8 Id, uint8 MbIdx, Can_Drv_MsgBufType *DataPtr,
                                         boolean IsPolling)
{

    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    Can_Drv_StateType       *StatePtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    if (Can_Drv_CheckMbIdRange(Id, MbIdx) != CAN_DRV_SUCCESS)
    {
        ReturnValue = CAN_DRV_ERROR;
    }
    else
    {
        if (StatePtr->Mb[MbIdx].State != CAN_DRV_STATE_IDLE)
        {
            ReturnValue = (Can_Drv_ControllerStatus)CAN_DRV_ENTER_BUSY;
        }
        else
        {
            StatePtr->Mb[MbIdx].State = CAN_DRV_STATE_RX;
            StatePtr->Mb[MbIdx].MbMessagePtr = DataPtr;
            StatePtr->Mb[MbIdx].IsPolling = IsPolling;
        }
    }

#if (CAN_DRV_MB_INTERRUPT_SUPPORT == STD_ON)
    if ((CAN_DRV_SUCCESS == ReturnValue) && (FALSE == IsPolling))
    {
        /* Enable MB interrupt*/
        Can_Drv_ConfigMbInterrupt(Id, MbIdx, (boolean)TRUE, StatePtr->InterEn);
    }
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      This function receives a CAN frame into a configured message buffer via FIFO mode.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  DataPtr: Pointer to store the received data.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS:  Receive can frame success
 * @retval     CAN_DRV_ERROR:   Receive can frame has not been accepted.
 * @retval     CAN_DRV_ENTER_BUSY:   Receive Status is busy
 *
 */
Can_Drv_ControllerStatus Can_Drv_RxFIFO(uint8 Id, Can_Drv_MsgBufType *DataPtr)
{
    Can_Drv_ControllerStatus resultVal = CAN_DRV_ERROR;
    Can_Drv_StateType       *StatePtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    if (TRUE == StatePtr->RxFifoEn)
    {
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
        if (CAN_DRV_RXFIFO_DMA == StatePtr->TransferType)
        {
            if (CAN_DRV_STATE_DMA_ERROR == StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State)
            {
                Can_Drv_ClearOutputRxFIFO(Id);

                /* Change Status of MB to be reconfigured with DMA transfer */
                StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State = CAN_DRV_STATE_IDLE;
            }
        }
#endif
        /* Start receiving mailbox */
        if (StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State != CAN_DRV_STATE_IDLE)
        {
            resultVal = (Can_Drv_ControllerStatus)CAN_DRV_ENTER_BUSY;
        }
        else
        {
            resultVal = CAN_DRV_SUCCESS;
            StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].State = CAN_DRV_STATE_RX;
            StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].MbMessagePtr = DataPtr;
            if (CAN_DRV_RXFIFO_POLLING == StatePtr->TransferType)
            {
                StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].IsPolling = (boolean)TRUE;
            }
            else if (CAN_DRV_RXFIFO_INTERRUPTS == StatePtr->TransferType)
            {
                StatePtr->Mb[CAN_DRV_RXFIFO_START_INDEX].IsPolling = (boolean)FALSE;
                /* Enable RX FIFO interrupts*/
                Can_Drv_ConfigMbInterrupt(Id, CAN_DRV_RXFIFO_FRAME_AVAILABLE, (boolean)TRUE,
                                          StatePtr->InterEn);
                Can_Drv_ConfigMbInterrupt(Id, CAN_DRV_RXFIFO_WARNING, (boolean)TRUE,
                                          StatePtr->InterEn);
                Can_Drv_ConfigMbInterrupt(Id, CAN_DRV_RXFIFO_OVERFLOW, (boolean)TRUE,
                                          StatePtr->InterEn);
            }
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
            else if (CAN_DRV_RXFIFO_DMA == StatePtr->TransferType)
            {
                Can_Drv_ConfigDma(Id);
            }
#endif
            else
            {
                /* Nothing to do */
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return resultVal;
}

/**
 * @brief     Clears error status.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Mask: error Mask
 *
 * @return     None
 *
 */
void Can_Drv_ClearErrorStatus(uint8 Id, uint32 Mask)
{
    Reg_Can_WType *CanRegisterWPtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    CanRegisterWPtr->CAN_ESR1 = Mask;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Enables controller interrupts.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Interrupts enabled success.
 * @retval     CAN_DRV_ERROR: The controller is not enabled.
 *
 */
Can_Drv_ControllerStatus Can_Drv_EnableInterrupts(uint8 Id)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    Can_Drv_ControllerStatus       ReturnVal = CAN_DRV_ERROR;
    Can_Drv_StateType             *StatePtr;
    uint32                         Disable;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    StatePtr = Can_Drv_StatePtr[Id];
    Disable = CanRegisterBfPtr->CAN_MCR.MDIS;
    if (0U == Disable)
    {
        Can_Drv_UnmaskInterrupt(Id);
        StatePtr->InterEn = (boolean)TRUE;
        ReturnVal = CAN_DRV_SUCCESS;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnVal;
}

/**
 * @brief      Disables controller interrupts.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Interrupts disabled success.
 * @retval     CAN_DRV_ERROR: The controller is not enabled.
 *
 */
Can_Drv_ControllerStatus Can_Drv_DisableInterrupts(uint8 Id)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    Can_Drv_StateType             *StatePtr;
    uint32                         Disable;
    Can_Drv_ControllerStatus       ReturnVal = CAN_DRV_ERROR;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    StatePtr = Can_Drv_StatePtr[Id];
    Disable = CanRegisterBfPtr->CAN_MCR.MDIS;

    if (0U == Disable)
    {
        Can_Drv_MaskInterrupt(Id);
        StatePtr->InterEn = (boolean)FALSE;
        ReturnVal = CAN_DRV_SUCCESS;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnVal;
}

/**
 * @brief     Gets controller fault confinement state.
 *
 * @param[in] Id: Channel id.
 *
 * @return    uint32: Controller fault confinement state.
 * @retval    0x00: Error active.
 * @retval    0x01: Error passive.
 * @retval    0x1X: Bus off.
 *
 */
uint32 Can_Drv_GetControllerErrorState(uint8 Id)
{
    uint32                         Temp = 0U;
    const volatile Reg_Can_BfType *CanRegisterBfPtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Temp = CanRegisterBfPtr->CAN_ESR1.FLTCONF;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();

#endif

    return Temp;
}

/**
 * @brief      Returns controller Rx error counter.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     uint32: Rx error counter.
 *
 */
uint32 Can_Drv_GetControllerRxErrorCounter(uint8 Id)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    uint32                         Temp = 0U;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Temp = (uint32)(CanRegisterBfPtr->CAN_ECR.RXERRCNT);

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Temp;
}

/**
 * @brief     Returns controller Tx error counter.
 *
 * @param[in] Id: Channel id.
 *
 * @return    uint32: Tx error counter.
 *
 */
uint32 Can_Drv_GetControllerTxErrorCounter(uint8 Id)
{
    uint32                         Temp = 0U;
    const volatile Reg_Can_BfType *CanRegisterBfPtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Temp = (uint32)(CanRegisterBfPtr->CAN_ECR.TXERRCNT);

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Temp;
}

/**
 * @brief      Returns mailbox transfer status.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Data transferred success.
 * @retval     CAN_DRV_ERROR: Data transferred failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_GetTransferStatus(uint8 Id, uint8 MbIdx)
{
    const Can_Drv_StateType *StatePtr;
    Can_Drv_ControllerStatus ReturnVal = CAN_DRV_ERROR;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];

    if (CAN_DRV_ERROR == Can_Drv_CheckMbIdRange(Id, MbIdx))
    {
        ReturnVal = CAN_DRV_ERROR;
    }
    else
    {
        if (CAN_DRV_STATE_IDLE == StatePtr->Mb[MbIdx].State)
        {
            ReturnVal = CAN_DRV_SUCCESS;
        }
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if (CAN_DRV_STATE_DMA_ERROR == StatePtr->Mb[MbIdx].State)
        {
            ReturnVal = CAN_DRV_ERROR;
        }
#endif
        else
        {
            ReturnVal = CAN_DRV_ENTER_BUSY;
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnVal;
}

/**
 * @brief      Manually recovers from bus-off if possible.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Recover from bus off state success.
 * @retval     CAN_DRV_ERROR: Recover from bus off state failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_ManualBusOffRecovery(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
    uint32                   TimeElapsedValue = 0U;
    uint32                   TimeCounter = 0U;
    uint32                   CurrentValue;
    uint32                   CanTimeoutDuration;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    /* Recover from bus-off when Automatic recovering from Bus Off State disabled. */
    if (1U == CanRegisterBfPtr->CAN_CTRL1.BOFFREC)
    {
        /* return success if the controller is not in bus-off */
        if (((CanRegisterBfPtr->CAN_ESR1.FLTCONF) & CAN_DRV_ESR1_FLTCONF_BUS_OFF) != 0U)
        {
            SchM_Enter_Can_RecoveryBusOff();

            /* Negate to recover from bus-off */
            CanRegisterBfPtr->CAN_CTRL1.BOFFREC = 0U;

            /* re-assert to disable bus-off auto reocvery */
            CanRegisterBfPtr->CAN_CTRL1.BOFFREC = 1U;

            SchM_Exit_Can_RecoveryBusOff();
            /* Wait till exit bus-off */
            CanTimeoutDuration =
                McalLib_MicroSecToTicks(CAN_DRV_SERVICE_TIMEOUT_TYPE, CAN_DRV_TIMEOUT_DURATION);

            (void)McalLib_GetCounterValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue);
            while (((CanRegisterBfPtr->CAN_ESR1.FLTCONF) & CAN_DRV_ESR1_FLTCONF_BUS_OFF) != 0U)
            {
                (void)McalLib_GetElapsedValue(CAN_DRV_SERVICE_TIMEOUT_TYPE, &CurrentValue,
                                              &TimeElapsedValue);
                TimeCounter += TimeElapsedValue;
                if (TimeCounter > CanTimeoutDuration)
                {
                    ReturnValue = CAN_DRV_ERROR;
                    break;
                }
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Processes the transmission of the corresponding message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
void Can_Drv_WriteMainFunction(uint8 Id, uint8 MbIdx)
{
    Can_Drv_StateType            *StatePtr;
    const volatile Reg_Can_WType *CanRegisterWPtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    if (TRUE == Can_Drv_ReadMbInterruptFlag(Id, MbIdx))
    {
        StatePtr->Mb[MbIdx].TimeStamp = Can_Drv_GetTimeStamp(Id, MbIdx);
        /*read time*/
        (void)CanRegisterWPtr->CAN_TIMER;
        /*clear interrupt Flag*/
        (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);
        /*change to Idle Status*/
        StatePtr->Mb[MbIdx].State = CAN_DRV_STATE_IDLE;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Processes the reception of the corresponding message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
void Can_Drv_ReadMainFunction(const uint8 Id, uint8 MbIdx)
{
    const Can_Drv_StateType *StatePtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    /*check md index*/
    if (CAN_DRV_SUCCESS == Can_Drv_CheckMbIdRange(Id, MbIdx))
    {
        if ((TRUE == StatePtr->RxFifoEn) && (MbIdx <= CAN_DRV_RXFIFO_OVERFLOW))
        {
            /* just process available  fifo event only */
            if ((uint8)CAN_DRV_RXFIFO_START_INDEX == MbIdx)
            {
                if (TRUE == Can_Drv_ReadMbInterruptFlag(Id, CAN_DRV_RXFIFO_FRAME_AVAILABLE))
                {
                    Can_Drv_RxFifoIrqHandler(Id, CAN_DRV_RXFIFO_FRAME_AVAILABLE);
                }
            }
        }
        else
        {
            if (TRUE == Can_Drv_ReadMbInterruptFlag(Id, MbIdx))
            {
                /* Check mailbox completed reception */
                if (CAN_DRV_STATE_RX == StatePtr->Mb[MbIdx].State)
                {
                    Can_Drv_RxMbIrqHandler(Id, MbIdx);
                }
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Processes bus off event.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Bus off event processed successfully.
 * @retval     CAN_DRV_ERROR: Bus off event processed failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_BusOffMainFunction(uint8 Id)
{
    Reg_Can_WType                 *CanRegisterWPtr;
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_ERROR;
    const Can_Drv_StateType       *StatePtr;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    StatePtr = Can_Drv_StatePtr[Id];
    if (0U != (CanRegisterBfPtr->CAN_ESR1.FLTCONF & 0x02U))
    {
        if (NULL_PTR != StatePtr->ErrCallback)
        {
            StatePtr->ErrCallback(Id, CAN_DRV_INT_BUS_OFF, CanRegisterWPtr->CAN_ESR1);
        }
        /* Clear BusOff Status Flag */
        CanRegisterWPtr->CAN_ESR1 = (uint32)(CAN_DRV_INT_MSK_FLAG_BUS_OFF);

        ReturnValue = CAN_DRV_SUCCESS;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Processes wakeup event.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Wakeup event processed successfully.
 * @retval     CAN_DRV_ERROR: Wakeup event processed failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_WakeupMainFunction(uint8 Id)
{
    Reg_Can_WType           *CanRegisterWPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_ERROR;
    const Can_Drv_StateType *StatePtr;
    uint32                   Status;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    StatePtr = Can_Drv_StatePtr[Id];
    Status = CanRegisterWPtr->CAN_ESR1;
    /* clear int Status */
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_INT_MSK_FLAG_SELF_WAKEUP;

    if (NULL_PTR != StatePtr)
    {
        if ((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_SELF_WAKEUP)))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_SELF_WAKEUP, Status);
            }
            ReturnValue = CAN_DRV_SUCCESS;
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Configures error interrupt(enable/disable).
 *
 * @param[in]  Id: Channel id.
 * @param[in]  IntType: Error interrupt type.
 * @param[in]  Enable: Enable/Disable.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Error interrupt configured success.
 * @retval     CAN_DRV_ERROR:  Error interrupt configured failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_ConfigErrorInterrupt(uint8 Id, Can_Drv_IntType IntType,
                                                      boolean Enable)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_SUCCESS;
    uint8                          Disabled;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    Disabled = (uint8)CanRegisterBfPtr->CAN_MCR.MDIS;

    if (1U == Disabled)
    {
        ReturnValue = Can_Drv_Enable(Id);
    }

    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        ReturnValue = Can_Drv_SetErrorInterruptState(Id, IntType, Enable);
    }

    if (1U == Disabled)
    {
        if (CAN_DRV_SUCCESS != Can_Drv_Disable(Id))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Sets CAN standard bit timing.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  RatePtr: Pointer to store the bit timing settings.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: CAN standard bit timing set success.
 * @retval     CAN_DRV_ERROR: CAN standard bit timing set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetStdBitTiming(uint8 Id, const Can_Drv_BitTimingType *RatePtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(RatePtr != NULL_PTR);
#endif

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        (void)Can_Drv_SetStandardBitTiming(Id, RatePtr);

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief     Sets CANFD arbitration phase.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  RatePtr: Pointer to store the CANFD bit timing configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: CANFD arbitration phase set success.
 * @retval     CAN_DRV_ERROR: CANFD arbitration phase set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetFdArbBitTiming(uint8 Id, const Can_Drv_BitTimingType *RatePtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(RatePtr != NULL_PTR);
#endif

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        (void)Can_Drv_SetFdArbitrationBitTiming(Id, RatePtr);

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Sets CANFD data phase.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  RatePtr: Pointer to store the CANFD bit timing configuration.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: CANFD data phase set success.
 * @retval     CAN_DRV_ERROR: CANFD data phase set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetFdDataBitTiming(uint8 Id, const Can_Drv_BitTimingType *RatePtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(RatePtr != NULL_PTR);
#endif

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        (void)Can_Drv_ConfigFdDataBitTiming(Id, RatePtr);

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Enables/Disables individual Rx masking and queue.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MaskType: Rx mask type.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Enables/Disables individual Rx masking and queue success.
 * @retval     CAN_DRV_ERROR: Enables/Disables individual Rx masking and queue failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetRxMaskType(uint8 Id, Can_Drv_RxMaskType MaskType)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif
    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_CanMcrReg();
        CanRegisterBfPtr->CAN_MCR.IRMQ = (uint32)MaskType;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_CanMcrReg();

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Returns MB interrupt flag.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     boolean
 * @retval     TRUE: The corresponding buffer has successfully completed transmission or reception.
 * @retval     FALSE: The corresponding buffer has no occurrence of successfully completed
 * transmission or reception.
 *
 */
boolean Can_Drv_GetMbInterruptFlag(uint8 Id, uint8 MbIdx)
{
    boolean ReturnVal = TRUE;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    ReturnVal = Can_Drv_ReadMbInterruptFlag(Id, MbIdx);

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnVal;
}

/**
 * @brief     Clears MB interrupt flag.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 *
 * @return     None
 *
 */
void Can_Drv_ClearMbIntStatus(uint8 Id, uint8 MbIdx)
{
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (CAN_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbIdx);

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Checks whether the channel is in started mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     boolean
 * @retval     TRUE: The channel is in started mode.
 * @retval     FALSE: The channel is not in started mode.
 *
 */
boolean Can_Drv_CheckStartedMode(uint8 Id)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    boolean                        Temp = (boolean)FALSE;
    uint8                          CanLpmackSts = 0;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    CanLpmackSts = (uint8)CanRegisterBfPtr->CAN_MCR.LPMACK;
    if ((0U == (CanRegisterBfPtr->CAN_MCR.FRZACK)) && (0U == CanLpmackSts))
    {
        Temp = (boolean)TRUE;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Temp;
}

/**
 * @brief      Checks whether the channel is in stopped mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @retval     TRUE: The channel is in stopped mode.
 * @retval     FALSE: The channel is not in stopped mode.
 *
 */
boolean Can_Drv_CheckStoppedMode(uint8 Id)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    boolean                        Temp = (boolean)FALSE;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    if (1U == (CanRegisterBfPtr->CAN_MCR.LPMACK))
    {
        Temp = (boolean)TRUE;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Temp;
}

/**
 * @brief      Sets the channel to started mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Mode transmission succeed.
 * @retval     CAN_DRV_ERROR: Mode transmission failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetStartMode(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (CAN_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_CanMcrReg();
    /* Enable can Module */
    CanRegisterBfPtr->CAN_MCR.MDIS = 0U;
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_CanMcrReg();
    ReturnValue = Can_Drv_ExitFreezeMode(Id);

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Sets the channel to stop mode.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: The controller set to stop mode succeed.
 * @retval     CAN_DRV_ERROR: The controller set to stop mode failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetStopMode(uint8 Id)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (CAN_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        ReturnValue = Can_Drv_Disable(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Configures Rx FIFO filters.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Element: Acceptance type.
 * @param[in]  FilterTablePtr: Pointer to store the filter table.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx FIFO filter configured succeed.
 * @retval     CAN_DRV_ERROR: Rx FIFO filter configured failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_ConfigRxFifo(uint8 Id, Can_Drv_RxAcceptanceType Element,
                                              const Can_Drv_IdFilterType *FilterTablePtr)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        Can_Drv_ConfigRxFifoFilter(Id, Element, FilterTablePtr);

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      This function sends out a CAN frame using a configured message buffer.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  TxInfoPtr: Tx message info.
 * @param[in]  IsPolling: Polling mode or not.
 * @param[in]  MsgId: Message id.
 * @param[in]  MsgDataPtr: Pointer to store the message data.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Message sent out succeed.
 * @retval     CAN_DRV_ERROR: Message buffer is invalid.
 * @retval     CAN_DRV_ENTER_BUSY: The message buffer is in invalid state.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SendData(uint8 Id, uint8 MbIdx,
                                          const Can_Drv_MessageInfoType *TxInfoPtr,
                                          boolean IsPolling, uint32 MsgId, const uint8 *MsgDataPtr)
{
    const volatile Reg_Can_BfType *CanRegisterBfPtr;
    Can_Drv_ControllerStatus       ReturnValue = CAN_DRV_SUCCESS;
    Can_Drv_FdMbRegionType         Region;
    Can_Drv_MbType                *MbAddrPtr;
    uint32                         ListenMode;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
    MCALLIB_DEV_ASSERT(TxInfoPtr != NULL_PTR);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    ListenMode = CanRegisterBfPtr->CAN_CTRL1.LOM;
    if (0U == ListenMode)
    {
        if (CAN_DRV_ERROR == Can_Drv_GetMbAddr(Id, MbIdx, &Region, &MbAddrPtr))
        {
            ReturnValue = CAN_DRV_ERROR;
        }
        else
        {
            if (CAN_DRV_ERROR == Can_Drv_CheckMbId(Id, MbIdx))
            {
                ReturnValue = CAN_DRV_ERROR;
            }
            else
            {
                ReturnValue = Can_Drv_ProcessTxMb(MbAddrPtr, Id, MbIdx, TxInfoPtr, IsPolling, MsgId,
                                                  MsgDataPtr);
            }
        }
    }
    else
    {
        ReturnValue = CAN_DRV_ERROR;
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Sets Rx MB individual mask.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  IdType: Message type(standard or extended).
 * @param[in]  MbIdx: Message buffer id.
 * @param[in]  Mask: Mask Value. 11-bit standard Mask or 29-bit extended Mask
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx MB individual mask set succeed.
 * @retval     CAN_DRV_ERROR: Rx MB individual mask set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetRxIndividualMask(uint8 Id, Can_Drv_MsgIdType IdType,
                                                     uint32 MbIdx, uint32 Mask)
{
    Reg_Can_WType           *CanRegisterWPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    if (Can_Drv_CheckMbId(Id, MbIdx) != CAN_DRV_SUCCESS)
    {
        ReturnValue = CAN_DRV_ERROR;
    }
    else
    {
        ReturnValue = Can_Drv_EnterFreezeMode(Id);

        if (CAN_DRV_SUCCESS == ReturnValue)
        {
            if (IdType == CAN_DRV_MSG_ID_STD)
            {
                CanRegisterWPtr->CAN_RXIMR[MbIdx] = CAN_DRV_CAL_RX_MB_STD_MASK(Mask);
            }
            else
            {
                CanRegisterWPtr->CAN_RXIMR[MbIdx] = CAN_DRV_CAL_RX_MB_EXT_MASK(Mask);
            }

            ReturnValue = Can_Drv_ExitFreezeMode(Id);
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return ReturnValue;
}

/**
 * @brief      Sets Rx FIFO global Mask. It masks the Rx FIFO ID Filter Table
 *             elements that do not have a corresponding individual Mask.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Mask:Mask Value. Its Format depends on the RX FIFO Id filter Format.
               It should be set as follows:

              Format A ID Mask:
                bit31 | bit30 |      bit29 ... 1             | bit0
                RTR   | IDE(0)| IDmask(std:29-19, ext:29-1)  | reserved

              Format B ID Mask:
                bit31 | bit30 |       bit29 ... 16         | bit 15 | bit 14 | bit13 ... 0
                RTR   | IDE   | ID0(std:29-19, ext:29-16)  | RTR    | IDE    | ID1(std:13-3,
 ext:13-0)

              Format C ID Mask:
                bit31...bit 24 | bit23...bit16 |  bit15 ...bit8 | bit7 ... bit0
                IDmask0        | IDmask1       |    IDmask2     |    IDmask3

 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx FIFO global mask set succeed.
 * @retval     CAN_DRV_ERROR: Rx FIFO global mask set failed.
 *
*/
Can_Drv_ControllerStatus Can_Drv_SetRxFifoGlobalMask(uint8 Id, uint32 Mask)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        if (0U != CanRegisterBfPtr->CAN_MCR.RFEN)
        {
            SchM_Enter_Can_CanRxmgMskReg();
            CanRegisterBfPtr->CAN_RXFGMASK.FGM = Mask;
            SchM_Exit_Can_CanRxmgMskReg();
        }

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Enables EACEN(Entire Frame Arbitration Field Comparison Enable for Rx mailboxes).
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Enable EACEN succeed.
 * @retval     CAN_DRV_ERROR: Enable EACEN failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_EnableArbitrationFiledCompare(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    ReturnValue = Can_Drv_EnterFreezeMode(Id);

    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        CanRegisterBfPtr->CAN_CTRL2.EACEN = 1U;

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Sets Rx FIFO individual Mask for the specific ID filter table element.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  ElementIdx: ID filter table Element index. It indicates which
 *                         filter table Element the Mask is corresponding to.
 *                         It should not exceeds the MB number that is occupied
 *                         by Rx FIFO.
 * @param[in]  Mask: Mask Value. Its Format depends on the RX FIFO Id filter Format.
               It should be set as follows:

              Format A ID Mask:
                bit31 | bit30 |      bit29 ... 1             | bit0
                RTR   | IDE(0)| IDmask(std:29-19, ext:29-1)  | reserved

              Format B ID Mask:
                bit31 | bit30 |       bit29 ... 16           | bit 15 | bit 14 | bit13 ... 0
                RTR   | IDE   | IDmask0(std:29-19, ext:29-16)| RTR    | IDE    |
 IDmask1(std:13-3, ext:13-0) In the extended frame Format B, IDmask0/IDmask1 corresponds to the
 14 most significant bits of the received ID

              Format C ID Mask:
                bit31...bit 24 | bit23...bit16 |  bit15 ...bit8 | bit7 ... bit0
                IDmask0        | IDmask1       |    IDmask2     |    IDmask3
              For Format C IDmask corresponds to the 8 most significant bits of
              the received ID

 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Rx FIFO individual mask set succeed.
 * @retval     CAN_DRV_ERROR: Rx FIFO individual mask set failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetRxFifoIndividualMask(uint8 Id, uint32 ElementIdx, uint32 Mask)
{
    Reg_Can_WType           *CanRegisterWPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        CanRegisterWPtr->CAN_RXIMR[ElementIdx] = Mask;

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Enables the Transceiver Delay Compensation feature in CAN FD Mode
 *             and sets the Transceiver Delay Compensation Offset (Offset Value
 *             to be added to the measured transceiver's loop delay in order to
 *             define the position of the delayed comparison point when bit Rate
 *             switching is active).
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Enable: Offset Enable Status
 * @param[in]  Offset: Transceiver Delay Compensation Offset
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Enable TDC feature and set TDC offset success.
 * @retval     CAN_DRV_ERROR: Enable TDC feature and set TDC offset failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetFdTdc(uint8 Id, boolean Enable, uint8 Offset)
{
    Reg_Can_WType          *CanRegisterWPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    ReturnValue = Can_Drv_EnterFreezeMode(Id);

    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_ConfigFdCompensation();
        CanRegisterWPtr->CAN_FDCTRL &= (~(CAN_DRV_TDCFAIL_MASK | 
        CAN_DRV_TDCEN_MASK|CAN_DRV_TDCOFF_MASK));
        CanRegisterWPtr->CAN_FDCTRL = 
        (CanRegisterWPtr->CAN_FDCTRL & (~CAN_DRV_TDCFAIL_MASK)) | 
        (((uint32)Enable << CAN_DRV_TDCEN_SHIFT) & CAN_DRV_TDCEN_MASK) | 
        (((uint32)Offset << CAN_DRV_TDCOFF_SHIFT) & CAN_DRV_TDCOFF_MASK);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_ConfigFdCompensation();

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Sets Tx Arbitration Start Delay.
 *
 * @param[in]  Id: Channel id.
 * @param[in]  Value: Delay Value
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Sets Tx Arbitration Start Delay success.
 * @retval     CAN_DRV_ERROR: Sets Tx Arbitration Start Delay failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_SetTxArbitrationDelay(uint8 Id, uint8 Value)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    ReturnValue = Can_Drv_EnterFreezeMode(Id);

    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_SetTxArbitrationDelay();
        CanRegisterBfPtr->CAN_CTRL2.TASD = (uint32)Value;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_SetTxArbitrationDelay();

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Enable self wakeup function.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Self wakeup enabled succeed.
 * @retval     CAN_DRV_ERROR: Self wakeup enabled failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_EnableSelfWakeup(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    ReturnValue = Can_Drv_EnterFreezeMode(Id);
    if (CAN_DRV_SUCCESS == ReturnValue)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_SetSelfWakeup();
        /* enable self wakeup */
        CanRegisterBfPtr->CAN_MCR.SLFWAK = 1;
        CanRegisterBfPtr->CAN_MCR.WAKSRC = 1;
        CanRegisterBfPtr->CAN_MCR.WAKMSK = 1;
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_SetSelfWakeup();

        ReturnValue = Can_Drv_ExitFreezeMode(Id);
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Disables self wakeup function.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: Self wakeup disabled succeed.
 * @retval     CAN_DRV_ERROR: Self wakeup disabled failed.
 *
 */
Can_Drv_ControllerStatus Can_Drv_DisableSelfWakeup(uint8 Id)
{
    Reg_Can_BfType          *CanRegisterBfPtr;
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_SUCCESS;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_SetSelfWakeup();
    /* disable self wakeup */
    CanRegisterBfPtr->CAN_MCR.SLFWAK = 0;
    CanRegisterBfPtr->CAN_MCR.WAKMSK = 0;
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_SetSelfWakeup();

    ReturnValue = Can_Drv_Disable(Id);

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief      Inject correctable error.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: succeed.
 * @retval     CAN_DRV_ERROR: failed.
 *
 * @note       It is suggested that disable CAN ecc interrupt(including NVIC in 
 *             platform and CanEccEnable function) when call this function.
 */
Can_Drv_ControllerStatus Can_Drv_InjectCorrectableAddress(uint8 Id)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_ERROR;
    Reg_Can_BfType *CanRegisterBfPtr ;  
    Reg_Can_WType *CanRegisterWPtr ;
    uint32 const volatile* CanReadRam;
    uint32 CanReadAddr;
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    /*Enable write Configure */
    CanRegisterBfPtr->CAN_CTRL2.ECRWRE = 1;    
    CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0;
    
    /*Injection Enable*/
    CanRegisterBfPtr->CAN_MECR.HAERRI   = 1;
    CanRegisterBfPtr->CAN_MECR.FAERRIE  = 1;

    /*enter freeze mode*/
    if(CAN_DRV_SUCCESS == Can_Drv_EnterFreezeMode(Id))
    {
        /*Write-Access To Memory In Freeze Mode */
        CanRegisterBfPtr->CAN_CTRL2.WRMFRZ = 1;

        CanRegisterBfPtr->CAN_ERRIAR.INJADDR_H = ( (uint32)0xE0>> 2U);
        /*Injection Data Error*/
        CanRegisterBfPtr->CAN_ERRIDPR.DFLIP = CAN_DRV_ERRINJECT_SIG_DATA;
        CanReadRam = (uint32 *)((uint32)CanRegisterBfPtr + 0x80U + 0xE0U);
        (void)*CanReadRam;
        /*check correctable error was detected*/
        if(1U == CanRegisterBfPtr->CAN_ERRSR.CEIF)
        {
            CanReadAddr = CanRegisterBfPtr->CAN_RERRAR.ERRADDR;
            if( 0xE0U == CanReadAddr)
            {
                /*A correctable error was detected.*/
                ReturnValue = CAN_DRV_SUCCESS;
            }
            CanRegisterWPtr->CAN_ERRSR = CAN_DRV_INT_MSK_FLAG_COR_MEM_ERR;
        }
        
        /*Disable Data Error Injection*/
        CanRegisterBfPtr->CAN_ERRIDPR.DFLIP = CAN_DRV_ERRINJECT_DEFAULT;

        if(CAN_DRV_SUCCESS == ReturnValue)
        {            
            /*Injection Parity Error*/
            CanRegisterBfPtr->CAN_ERRIPPR.PFLIP0 = CAN_DRV_ERRINJECT_SIG_PARIYT;

            CanReadRam = (uint32 *)((uint32)CanRegisterBfPtr + 0x80U + 0xE0U);
            (void)*CanReadRam;
            ReturnValue = CAN_DRV_ERROR;

            if(1U == CanRegisterBfPtr->CAN_ERRSR.CEIF)
            {
                CanReadAddr = CanRegisterBfPtr->CAN_RERRAR.ERRADDR;
                if( 0xE0U == CanReadAddr)
                {
                    /*A correctable error was detected*/
                    ReturnValue = CAN_DRV_SUCCESS;
                }
                CanRegisterWPtr->CAN_ERRSR = CAN_DRV_INT_MSK_FLAG_COR_MEM_ERR;
            }

            CanRegisterBfPtr->CAN_ERRIPPR.PFLIP0 =  CAN_DRV_ERRINJECT_DEFAULT;
            CanRegisterBfPtr->CAN_ERRIAR.INJADDR_H = 0U;
        }
        
        CanRegisterBfPtr->CAN_CTRL2.WRMFRZ = 0;
        /*Disable Injection Enable*/
        CanRegisterBfPtr->CAN_MECR.ECRWRDIS  = 0;
        CanRegisterBfPtr->CAN_MECR.HAERRI  = 0;
        CanRegisterBfPtr->CAN_MECR.FAERRIE = 0;
        CanRegisterBfPtr->CAN_CTRL2.ECRWRE = 0;
        CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 1;
        
        if(CAN_DRV_SUCCESS == ReturnValue)
        {
            ReturnValue = Can_Drv_ExitFreezeMode(Id);
        }
        else
        {
            (void)Can_Drv_ExitFreezeMode(Id);
        }
        
    }
        
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    
    return ReturnValue;

}

/**
 * @brief      Inject non-correctable error.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: succeed.
 * @retval     CAN_DRV_ERROR: failed.
 *
 * @note       It is suggested that disable CAN ecc interrupt(including NVIC in 
 *             platform and CanEccEnable function) when call this function.
 */
Can_Drv_ControllerStatus Can_Drv_InjectAddress(uint8 Id)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_ERROR;
    Reg_Can_BfType *CanRegisterBfPtr ;  
    uint32 const volatile* CanReadRam;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    uint32 *const ShcsrAddr = (uint32 *)0xE000ED24U;
    uint32 ShcsrOriginalVal = *ShcsrAddr;

    /*Enable bus fault handler*/
    *ShcsrAddr |= 0x70000U;

    CanRegisterBfPtr = Can_Drv_CanRegBfPtr[Id];
    /*Enable write Configure */
    CanRegisterBfPtr->CAN_CTRL2.ECRWRE = 1;    
    CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 0;
    
    /*Injection Enable*/
    CanRegisterBfPtr->CAN_MECR.HAERRI   = 1;
    CanRegisterBfPtr->CAN_MECR.FAERRIE  = 1;

    /*enter freeze mode*/
    if(CAN_DRV_SUCCESS == Can_Drv_EnterFreezeMode(Id))
    {
        /*Write-Access To Memory In Freeze Mode */
        CanRegisterBfPtr->CAN_CTRL2.WRMFRZ = 1;

        CanRegisterBfPtr->CAN_ERRIAR.INJADDR_H = ( (uint32)0xE0>> 2U);
        /*Injection Data and parity Error*/
        CanRegisterBfPtr->CAN_ERRIDPR.DFLIP = CAN_DRV_ERRINJECT_SIG_DATA;
        CanRegisterBfPtr->CAN_ERRIPPR.PFLIP0 = CAN_DRV_ERRINJECT_SIG_PARIYT;
        CanReadRam = (uint32 *)((uint32)CanRegisterBfPtr + 0x80U + 0xE0U);
        (void)*CanReadRam;
        
        /*recovery  original value*/
        *ShcsrAddr = ShcsrOriginalVal;

        ReturnValue = Can_Drv_ExitFreezeMode(Id);        
    }
        
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    
    return ReturnValue;
}

/**
 * @brief      Clear injection error.
 *
 * @param[in]  Id: Channel id.
 *
 * @return     Can_Drv_ControllerStatus
 * @retval     CAN_DRV_SUCCESS: succeed.
 * @retval     CAN_DRV_ERROR: failed.
 *
 * @note       It is suggested that disable CAN ecc interrupt(including NVIC in 
 *             platform and CanEccEnable function) when call this function.
 */
Can_Drv_ControllerStatus Can_Drv_ClearInjection(uint8 Id)
{
    Can_Drv_ControllerStatus ReturnValue = CAN_DRV_ERROR;
    Reg_Can_BfType *CanRegisterBfPtr;  
    Reg_Can_WType *CanRegisterWPtr;  
    uint32 CanReadAddr;
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif
    CanRegisterBfPtr =Can_Drv_CanRegBfPtr[Id];
    CanRegisterWPtr =Can_Drv_CanRegWPtr[Id];

    /*check ecc error was detected*/
    if((1U == CanRegisterBfPtr->CAN_ERRSR.FANCEIF) || 
    (1U == CanRegisterBfPtr->CAN_ERRSR.HANCEIF))
    {
        CanReadAddr = CanRegisterBfPtr->CAN_RERRAR.ERRADDR;
        if( 0xE0U == CanReadAddr)
        {
            /* ecc error was detected.*/
            ReturnValue = CAN_DRV_SUCCESS;
        }
        
        /*clear Non-Correctable error interrupt flag */
        CanRegisterWPtr->CAN_ERRSR = (CAN_DRV_INT_MSK_FLAG_HOST_MEM_ERR | CAN_DRV_INT_MSK_FLAG_CAN_MEM_ERR);
        /*Disable Data and parity Error Injection*/
        CanRegisterBfPtr->CAN_ERRIDPR.DFLIP = CAN_DRV_ERRINJECT_DEFAULT;
        CanRegisterBfPtr->CAN_ERRIPPR.PFLIP0 = CAN_DRV_ERRINJECT_DEFAULT;
        
        CanRegisterBfPtr->CAN_ERRIAR.INJADDR_H = 0U;
        CanRegisterBfPtr->CAN_CTRL2.WRMFRZ = 0;
        /*Disable Injection Enable*/
        CanRegisterBfPtr->CAN_MECR.ECRWRDIS  = 0;
        CanRegisterBfPtr->CAN_MECR.HAERRI  = 0;
        CanRegisterBfPtr->CAN_MECR.FAERRIE = 0;
        CanRegisterBfPtr->CAN_CTRL2.ECRWRE = 0;
        CanRegisterBfPtr->CAN_MECR.ECRWRDIS = 1;
    }
    
#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return ReturnValue;
}

/**
 * @brief     MB interrupt handler.
 *
 * @param[in] Id: Channel id.
 * @param[in] StartMbIdx: Start message buffer.
 * @param[in] EndMbIdx: End message buffer.
 *
 * @return    None
 *
 */
void Can_Drv_IntHandler(uint8 Id, uint32 StartMbIdx, uint32 EndMbIdx)
{
    const Can_Drv_StateType *StatePtr;
    /* is sprrious interrupt */
    boolean IsSpuriousInt = (boolean)TRUE;
    uint32  MbCounter = EndMbIdx;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    if (NULL_PTR != StatePtr)
    {

        IsSpuriousInt = Can_Drv_ProcessMbIrqSource(Id, StartMbIdx, EndMbIdx);
        /* Expectation is that ISR just process one Object (Tx, Rx normal, Rx legacy fifo) when
         * ISR triggered */
        Can_Drv_ProcessMbAbnormalInter(Id, IsSpuriousInt, StartMbIdx, EndMbIdx);
    }
    else
    {
        /* Clear all interrupt flags when driver is not initialized */
        for (MbCounter = StartMbIdx; MbCounter <= EndMbIdx; MbCounter++)
        {
            /* clear the MB Flag */
            (void)Can_Drv_ClearMessageBufferIntFlag(Id, MbCounter);
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Bus off interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_BusOffIntHandler(uint8 Id)
{
    const Can_Drv_StateType *StatePtr;
    Reg_Can_WType           *CanRegisterWPtr;
    uint32                   CanIntMask = 0U;
    uint32                   Status;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Status = CanRegisterWPtr->CAN_ESR1;

    /* clear int Status */
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_ESR1_BOFFINT_MASK;

    if (NULL_PTR != StatePtr)
    {
        CanIntMask = CanRegisterWPtr->CAN_CTRL1 & ((uint32)CAN_DRV_CTRL1_BOFFMSK_MASK);
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_ESR1_BOFFINT_MASK))) &&
            ((uint32)0U != CanIntMask))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_BUS_OFF, Status);
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     TX warning interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_TxWarnIntHandler(uint8 Id)
{
    const Can_Drv_StateType *StatePtr;
    Reg_Can_WType           *CanRegisterWPtr;
    uint32                   Status;
    uint32                   CanIntMask = 0U;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Status = CanRegisterWPtr->CAN_ESR1;
    /* clear int Status */
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_INT_MSK_FLAG_TXW;

    if (NULL_PTR != StatePtr)
    {

        CanIntMask = CanRegisterWPtr->CAN_CTRL1 & ((uint32)CAN_DRV_INT_MSK_TXW);
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_TXW))) &&
            ((uint32)0U != CanIntMask))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_TXW, Status);
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     RX warning interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_RxWarnIntHandler(uint8 Id)
{
    const Can_Drv_StateType *StatePtr;
    Reg_Can_WType           *CanRegisterWPtr;
    uint32                   Status;
    uint32                   CanIntMask = 0U;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Status = CanRegisterWPtr->CAN_ESR1;
    /* clear int Status */
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_INT_MSK_FLAG_RXW;

    if (NULL_PTR != StatePtr)
    {
        CanIntMask = CanRegisterWPtr->CAN_CTRL1 & ((uint32)CAN_DRV_INT_MSK_RXW);
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_RXW))) &&
            ((uint32)0U != CanIntMask))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_RXW, Status);
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Error interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_ErrorIntHandler(uint8 Id)
{

    const Can_Drv_StateType *StatePtr;
    Reg_Can_WType           *CanRegisterWPtr;
    uint32                   Status;
    uint32                   CanIntMask = 0U;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Status = CanRegisterWPtr->CAN_ESR1;

    /* clear int Status */
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_INT_MSK_FLAG_ERR;

    if (NULL_PTR != StatePtr)
    {
        CanIntMask = CanRegisterWPtr->CAN_CTRL1 & ((uint32)CAN_DRV_INT_MSK_ERR);
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_ERR))) &&
            ((uint32)0U != CanIntMask))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_ERR, Status);
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Error fast interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_FdErrorIntHandler(uint8 Id)
{
    const Can_Drv_StateType *StatePtr;
    Reg_Can_WType           *CanRegisterWPtr;
    uint32                   Status;
    uint32                   CanIntMask = 0U;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Status = CanRegisterWPtr->CAN_ESR1;
    /* clear int Status */
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_INT_MSK_FLAG_ERR_FAST;

    if (NULL_PTR != StatePtr)
    {
        CanIntMask = CanRegisterWPtr->CAN_CTRL2 & ((uint32)CAN_DRV_INT_MSK_ERR_FAST);
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_ERR_FAST))) &&
            ((uint32)0U != CanIntMask))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_ERR_FAST, Status);
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Self wakeup interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_WakeUpIntHandler(uint8 Id)
{
    const Can_Drv_StateType *StatePtr;
    Reg_Can_WType           *CanRegisterWPtr;
    uint32                   Status;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Status = CanRegisterWPtr->CAN_ESR1;
    /* clear int Status */
    CanRegisterWPtr->CAN_ESR1 = CAN_DRV_INT_MSK_FLAG_SELF_WAKEUP;

    if (NULL_PTR != StatePtr)
    {
        if ((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_SELF_WAKEUP)))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_SELF_WAKEUP, Status);
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     ECC error interrupt handler.
 *
 * @param[in] Id: Channel id.
 *
 * @return    None
 *
 */
void Can_Drv_EccIntHandler(uint8 Id)
{
    const Can_Drv_StateType *StatePtr;
    Reg_Can_WType           *CanRegisterWPtr;
    uint32                   Status;

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Id < CAN_DRV_TOTAL_NUM);
#endif

    StatePtr = Can_Drv_StatePtr[Id];
    CanRegisterWPtr = Can_Drv_CanRegWPtr[Id];
    Status = CanRegisterWPtr->CAN_ERRSR;
    /* only check enabled interrupts */
    Status = Status & (CanRegisterWPtr->CAN_MECR & CAN_DRV_INT_MSK_FLAG_ALL_ECC);
    /* clear int Status */
    CanRegisterWPtr->CAN_ERRSR = Status;
    
    /*clear status */
    CanRegisterWPtr->CAN_ERRSR = (Status >> CAN_DRV_ECC_OVERRUN_ERROR_SHIFT);
    
    if (NULL_PTR != StatePtr)
    {
        /* Host Access With Non-Correctable Error Interrupt */
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_HOST_MEM_ERR))))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_HOST_MEM_ERR, Status);
            }
        }
        /* CAN Access With Non-Correctable Error Interrupt */
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_CAN_MEM_ERR))))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_MEM_ERR, Status);
            }
        }
        /* Correctable Error Interrupt */
        if (((uint32)0U != (Status & ((uint32)CAN_DRV_INT_MSK_FLAG_COR_MEM_ERR))))
        {
            if (NULL_PTR != StatePtr->ErrCallback)
            {
                StatePtr->ErrCallback(Id, CAN_DRV_INT_COR_MEM_ERR, Status);
            }
        }
    }

#if (STD_ON == CAN_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     CAN DMA callback function.
 *
 * @param[in] None
 *
 * @return    None
 */
#if (STD_ON == CAN_DRV_FEATURE_HAS_DMA_ENABLE)
    #if (STD_ON == CAN_DRV_0_ENABLE)
void Can_Drv_0_IntHandler(uint32 LogicChIndex);
void Can_Drv_0_DmaErrorHandler(uint32 LogicChIndex);
    #endif
    #if (STD_ON == CAN_DRV_1_ENABLE)
void Can_Drv_1_IntHandler(uint32 LogicChIndex);
void Can_Drv_1_DmaErrorHandler(uint32 LogicChIndex);
    #endif
    #if (STD_ON == CAN_DRV_2_ENABLE)
void Can_Drv_2_IntHandler(uint32 LogicChIndex);
void Can_Drv_2_DmaErrorHandler(uint32 LogicChIndex);
    #endif
    #if (STD_ON == CAN_DRV_3_ENABLE)
void Can_Drv_3_IntHandler(uint32 LogicChIndex);
void Can_Drv_3_DmaErrorHandler(uint32 LogicChIndex);
    #endif
    #if (STD_ON == CAN_DRV_4_ENABLE)
void Can_Drv_4_IntHandler(uint32 LogicChIndex);
void Can_Drv_4_DmaErrorHandler(uint32 LogicChIndex);
    #endif
    #if (STD_ON == CAN_DRV_5_ENABLE)
void Can_Drv_5_IntHandler(uint32 LogicChIndex);
void Can_Drv_5_DmaErrorHandler(uint32 LogicChIndex);
    #endif
    #if (STD_ON == CAN_DRV_6_ENABLE)
void Can_Drv_6_IntHandler(uint32 LogicChIndex);
void Can_Drv_6_DmaErrorHandler(uint32 LogicChIndex);
    #endif
    #if (STD_ON == CAN_DRV_7_ENABLE)
void Can_Drv_7_IntHandler(uint32 LogicChIndex);
void Can_Drv_7_DmaErrorHandler(uint32 LogicChIndex);
    #endif
#endif

#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
    #if (STD_ON == CAN_DRV_0_ENABLE)
void Can_Drv_0_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(0);
}
void Can_Drv_0_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(0);
}
    #endif
    #if (STD_ON == CAN_DRV_1_ENABLE)
void Can_Drv_1_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(1);
}
void Can_Drv_1_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(1);
}
    #endif
    #if (STD_ON == CAN_DRV_2_ENABLE)
void Can_Drv_2_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(2);
}
void Can_Drv_2_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(2);
}
    #endif
    #if (STD_ON == CAN_DRV_3_ENABLE)
void Can_Drv_3_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(3);
}
void Can_Drv_3_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(3);
}
    #endif
    #if (STD_ON == CAN_DRV_4_ENABLE)
void Can_Drv_4_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(4);
}
void Can_Drv_4_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(4);
}
    #endif
    #if (STD_ON == CAN_DRV_5_ENABLE)
void Can_Drv_5_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(5);
}
void Can_Drv_5_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(5);
}
    #endif
    #if (STD_ON == CAN_DRV_6_ENABLE)
void Can_Drv_6_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(6);
}
void Can_Drv_6_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(6);
}
    #endif
    #if (STD_ON == CAN_DRV_7_ENABLE)
void Can_Drv_7_IntHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDma(7);
}
void Can_Drv_7_DmaErrorHandler(uint32 LogicChIndex)
{
    (void)LogicChIndex;
    Can_Drv_CallbackForDmaError(7);
}
    #endif
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Can_Drv */

/** @} end of group Can_Module */
