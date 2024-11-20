/**************************************************************************************************/
/**
 * @file      : Dma_Drv.c
 * @brief     : Dma_Drv driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup  Dma_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Dma_Drv.h"
#include "Device_Regs.h"
#include "SchM_Dma.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define DMA_DRV_C_VENDOR_ID                   0x00B3U
#define DMA_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define DMA_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define DMA_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define DMA_DRV_C_SW_MAJOR_VERSION            1U
#define DMA_DRV_C_SW_MINOR_VERSION            2U
#define DMA_DRV_C_SW_PATCH_VERSION            2U


#if (DMA_DRV_C_VENDOR_ID != DMA_DRV_H_VENDOR_ID)
    #error "Vendor ID of Dma_Drv.c and Dma_Drv.h are different"
#endif

#if ((DMA_DRV_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (DMA_DRV_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (DMA_DRV_C_AR_RELEASE_REVISION_VERSION != DMA_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Dma_Drv.c and Dma_Drv.h are different"
#endif

#if ((DMA_DRV_C_SW_MAJOR_VERSION != DMA_DRV_H_SW_MAJOR_VERSION) || \
    (DMA_DRV_C_SW_MINOR_VERSION != DMA_DRV_H_SW_MINOR_VERSION) || \
    (DMA_DRV_C_SW_PATCH_VERSION != DMA_DRV_H_SW_PATCH_VERSION))
    #error "Software version of Dma_Drv.c and Dma_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE

    #if ((DMA_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (DMA_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Dma_Drv.c and Device_Regs.h are different"
    #endif

    #if ((DMA_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_DMA_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (DMA_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_DMA_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Dma_Drv.c and SchM_Dma.h are different"
    #endif


#endif

#define DMA_DRV_CHANNEL0_MASK           (0x00000001U)
#define DMA_DRV_CHANNEL1_MASK           (0x00000002U)
#define DMA_DRV_CHANNEL2_MASK           (0x00000004U)
#define DMA_DRV_CHANNEL3_MASK           (0x00000008U)
#define DMA_DRV_CHANNEL4_MASK           (0x00000010U)
#define DMA_DRV_CHANNEL5_MASK           (0x00000020U)
#define DMA_DRV_CHANNEL6_MASK           (0x00000040U)
#define DMA_DRV_CHANNEL7_MASK           (0x00000080U)
#define DMA_DRV_CHANNEL8_MASK           (0x00000100U)
#define DMA_DRV_CHANNEL9_MASK           (0x00000200U)
#define DMA_DRV_CHANNEL10_MASK          (0x00000400U)
#define DMA_DRV_CHANNEL11_MASK          (0x00000800U)
#define DMA_DRV_CHANNEL12_MASK          (0x00001000U)
#define DMA_DRV_CHANNEL13_MASK          (0x00002000U)
#define DMA_DRV_CHANNEL14_MASK          (0x00004000U)
#define DMA_DRV_CHANNEL15_MASK          (0x00008000U)

#define DMA_DRV_CHANNEL_PRI_MASK        ((uint32)0x0000000FU)
#define DMA_DRV_CHANNEL_PRI_SHIFT(x)    ((uint32)(24U - (((uint32)(x) & 0x03U) << 3U)))
#define DMA_DRV_CHANNEL_PREEMPT_SHIFT(x) ((uint32)(30U - (((uint32)(x) & 0x03U) << 3U)))


#define DMA_DRV_GCC_WPEN0_MASK          (0x80808000U)
#define DMA_DRV_GCC_WPEN1_MASK          (0x80800080U)
#define DMA_DRV_GCC_WPEN2_MASK          (0x80008080U)
#define DMA_DRV_GCC_WPEN3_MASK          (0x00808080U)
#define DMA_DRV_GCC_WPEN03_MASK         (0x00808000U)
#define DMA_DRV_GCC_WPEN23_MASK         (0x00008080U)
#define DMA_DRV_GCC_CACES_MASK          (0x00400000U)
#define DMA_DRV_GCC_SCSTART_MASK        (0x00000F00U)
#define DMA_DRV_GCC_CCIS_MASK           (0x0F000000U)
#define DMA_DRV_GCC_CCES_MASK           (0x000F0000U)
#define DMA_DRV_GCC_CCDONE_MASK         (0x0000000FU)
#define DMA_DRV_GCC_CCIES_MASK          (0x0F0F0000U)
#define DMA_DRV_GCC_SCSTART_SHIFT       (8U)
#define DMA_DRV_GCC_CCES_SHIFT          (16U)
#define DMA_DRV_GCC_CCIS_SHIFT          (24U)

#define DMA_DRV_SPIN_WRITE_TIMEOUT      (100U)
#if (STD_ON == DMA_DRV_REQUEST_HALT_SUPPORT)
#define DMA_DRV_WAIT_BUSY_TIMEOUT       (100U)
#else
#define DMA_DRV_CH_GROUP_SHIFT          (3U)
#define DMA_DRV_CH_GROUP_MASK           (7U)
#endif

#define DMA_DRV_SADDR_OFFSET            (0U)
#define DMA_DRV_SADDR_WIDTH             (32U)
#define DMA_DRV_DADDR_OFFSET            (0U)
#define DMA_DRV_DADDR_WIDTH             (32U)
#define DMA_DRV_SAOFF_OFFSET            (0U)
#define DMA_DRV_SAOFF_WIDTH             (16U)
#define DMA_DRV_DAOFF_OFFSET            (16U)
#define DMA_DRV_DAOFF_WIDTH             (16U)
#define DMA_DRV_MLSAOFF_OFFSET          (0U)
#define DMA_DRV_MLSAOFF_WIDTH           (16U)
#define DMA_DRV_MLDAOFF_OFFSET          (16U)
#define DMA_DRV_MLDAOFF_WIDTH           (16U)
#define DMA_DRV_NUM_OFFSET              (0U)
#define DMA_DRV_NUM_WIDTH               (32U)
#define DMA_DRV_INTE_OFFSET             (1U)
#define DMA_DRV_INTE_WIDTH              (1U)
#define DMA_DRV_REQDIS_OFFSET           (3U)
#define DMA_DRV_REQDIS_WIDTH            (1U)
#define DMA_DRV_DSIZE_OFFSET            (16U)
#define DMA_DRV_DSIZE_WIDTH             (2U)
#define DMA_DRV_SSIZE_OFFSET            (24U)
#define DMA_DRV_SSIZE_WIDTH             (2U)
#define DMA_DRV_MLSTA_OFFSET            (16U)

/** @} end of Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */


#define DMA_START_SEC_CONST_PTR
#include "Dma_MemMap.h"

static Reg_Dma_BfType * const Dma_Drv_DmaRegBfPtr = (Reg_Dma_BfType *)DMA_BASE_ADDR;
static Reg_Dma_WType  * const Dma_Drv_DmaRegWPtr = (Reg_Dma_WType *)DMA_BASE_ADDR;
static Reg_Dmamux_BfType * const Dma_Drv_DmamuxRegBfPtr = (Reg_Dmamux_BfType *)DMAMUX_BASE_ADDR;

#define DMA_STOP_SEC_CONST_PTR
#include "Dma_MemMap.h"

#define DMA_START_SEC_CONST_32
#include "Dma_MemMap.h"

/*! @brief dma channel mask array */
static const uint32 Dma_Drv_ChannelMaskArray[] =
{
    DMA_DRV_CHANNEL0_MASK,
    DMA_DRV_CHANNEL1_MASK,
    DMA_DRV_CHANNEL2_MASK,
    DMA_DRV_CHANNEL3_MASK,
    DMA_DRV_CHANNEL4_MASK,
    DMA_DRV_CHANNEL5_MASK,
    DMA_DRV_CHANNEL6_MASK,
    DMA_DRV_CHANNEL7_MASK,
    DMA_DRV_CHANNEL8_MASK,
    DMA_DRV_CHANNEL9_MASK,
    DMA_DRV_CHANNEL10_MASK,
    DMA_DRV_CHANNEL11_MASK,
    DMA_DRV_CHANNEL12_MASK,
    DMA_DRV_CHANNEL13_MASK,
    DMA_DRV_CHANNEL14_MASK,
    DMA_DRV_CHANNEL15_MASK
};

static const uint32 Dma_Drv_GccWpenMaskArray[] =
{
    DMA_DRV_GCC_WPEN2_MASK,
    DMA_DRV_GCC_WPEN3_MASK,
    DMA_DRV_GCC_WPEN23_MASK
};

static const uint32 Dma_Drv_GccClearChannelsMaskArray[] =
{
    DMA_DRV_GCC_CCES_MASK,
    DMA_DRV_GCC_CCIS_MASK,
    DMA_DRV_GCC_CCIES_MASK
};

#define DMA_STOP_SEC_CONST_32
#include "Dma_MemMap.h"

#define DMA_START_SEC_VAR_CLEARED_PTR
#include "Dma_MemMap.h"

static Dma_Drv_ErrIntCallbackType Dma_Drv_ErrIsrCbPtr;
static Dma_Drv_CallbackType Dma_Drv_IsrCbPtr;

#define DMA_STOP_SEC_VAR_CLEARED_PTR
#include "Dma_MemMap.h"

#define DMA_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dma_MemMap.h"

/**
 * @brief DMAMUX software request source flag mark array. 
*/
static boolean Dma_Drv_SwReqSrcFlag[DMA_DRV_CHANNEL_NUM];

#define DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dma_MemMap.h"


/** @} end of group Private_VariableDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
LOCAL_INLINE Std_ReturnType Dma_Drv_SpinWriteRegister(volatile uint32 * RegAddr, uint32 BitOffset,
                                                            uint32 BitWidth, uint32 Value);
LOCAL_INLINE Std_ReturnType Dma_Drv_SpinWriteMinorLoopNum(Dma_Drv_ChannelType Channel, uint32 Num);
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

/** @} end of group Private_FunctionDeclaration */


/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/**
 * @brief Loop write register until written successfully. DMA channel related registers cannot be
 *  written while any DMA channel is transferring data, which is designed in Z20K14xMC DMA hardware.
 *  This function is a workaround to avoid unexpected register write failures. 
 * @param[in] RegAddr: Register address to write.
 * @param[in] BitOffset: Register bit offset to write based on register address. range [0,31].
 * @param[in] BitWidth: Bit width to write based on register offset. BitWidth + BitOffset <= 32.
 * @param[in] Value: Target value to be written, should be within "BitWidth" bit width.
 * 
 * @return    Std_ReturnType: the write operation result
 * @retval    E_OK: write successful
 * @retval    E_NOT_OK: write failed
 */
LOCAL_INLINE Std_ReturnType Dma_Drv_SpinWriteRegister(volatile uint32 * RegAddr, uint32 BitOffset,
                                                            uint32 BitWidth, uint32 Value)
{
    uint32 RegValue = 0U;
    uint32 RegMask = 0U;
    uint32 RegValueMasked = 0U;
    uint32 Counter = 0U;
    Std_ReturnType RetVal = E_OK;

    RegValue = *RegAddr;
    RegMask = ((1UL << BitWidth) - 1UL) << BitOffset;
    RegValue &= (~RegMask);
    RegValue |= ((Value & ((1UL << BitWidth) - 1UL)) << BitOffset);
    *RegAddr = RegValue;
    RegValueMasked = RegValue & RegMask;
    /* Loop write until success */
    while (((*RegAddr) & RegMask) != RegValueMasked)
    {
        *RegAddr = RegValue;
        if (Counter > DMA_DRV_SPIN_WRITE_TIMEOUT)
        {
            RetVal = E_NOT_OK;
            break;
        }
        Counter++;
    }
    return RetVal;
}

/**
 * @brief Loop write register DMA_ITER until written successfully.
 *  This function is a workaround to avoid unexpected register write failures. 
 *  And to determine whether DMA_ITERn.MLITER is configured successfully, an additional criterion
 *  is required: DMA ITERn.MLSTA is refreshed to the DMA_ITERn.MLITER value.

 * @param[in] Channel: Dma channel id.
 * @param[in] Num: Total number of minor loop in a major loop.
 * 
 * @return    Std_ReturnType: the write operation result
 * @retval    E_OK: write successful
 * @retval    E_NOT_OK: write failed
 */
LOCAL_INLINE Std_ReturnType Dma_Drv_SpinWriteMinorLoopNum(Dma_Drv_ChannelType Channel, uint32 Num)
{
    uint32 TargetRegValue = Num | (Num << DMA_DRV_MLSTA_OFFSET);
    uint32 Counter = 0U;
    Std_ReturnType RetVal = E_OK;
    volatile uint32 * RegAddr = &Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_ITER;

    *RegAddr = Num;
    /* Loop write until success */
    while ((*RegAddr) != TargetRegValue)
    {
        *RegAddr = Num;
        if (Counter > DMA_DRV_SPIN_WRITE_TIMEOUT)
        {
            RetVal = E_NOT_OK;
            break;
        }
        Counter++;
    }
    return RetVal;
}
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
/** @} end of group Private_FunctionDefinition */


/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"

/**
 * @brief      Get last error channel id.
 *
 * @param[in]  ErrStateRegVal: Last DMA error status register value.
 *
 * @return     Channel where the last error occurred.
 * @retval     DMA_DRV_PHYS_CH_0
 * @retval     DMA_DRV_PHYS_CH_1
 * @retval     DMA_DRV_PHYS_CH_2
 * @retval     ...
 * @retval     DMA_DRV_PHYS_CH_15
 *
 */
Dma_Drv_ChannelType Dma_Drv_GetLastErrorChannel(uint16 ErrStateRegVal)
{
    uint16 RetVal;
    RetVal = ((ErrStateRegVal >> 8U) & 0xFU);
    return (Dma_Drv_ChannelType)RetVal;
}

/**
 * @brief      Register dma transfer done callback function.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  MajorIntCallback: Done callback function.
 *
 * @return     None.
 *
 */
void Dma_Drv_InitDoneIrqHandle(const Dma_Drv_ChannelType Channel, Dma_Drv_CallbackType MajorIntCallback)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    Dma_Drv_IsrCbPtr = MajorIntCallback;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Halt dma.
 *
 * @param[in]  Cmd: Halt control.
 *                  - DMA_DRV_HALT_ON: Stall the dma start a new channels for transfer.
 *                  - DMA_DRV_HALT_OFF: Dma is not stall.
 *
 * @return     None.
 *
 */
void Dma_Drv_HaltControl(Dma_Drv_HaltType Cmd)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Cmd <= DMA_DRV_HALT_ON);
#endif
    SchM_Enter_Dma_DmaConfig();
    Dma_Drv_DmaRegBfPtr->DMA_CONF.HALT = (uint32)Cmd;
    SchM_Exit_Dma_DmaConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Enable dma channel request.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_EnableChannelRequest(Dma_Drv_ChannelType Channel)
{
#if (STD_ON == DMA_DRV_REQUEST_HALT_SUPPORT)
    uint32 DmaBaseAddr = DMA_BASE_ADDR;
    (void)DmaBaseAddr;
#else /* STD_OFF == DMA_DRV_REQUEST_HALT_SUPPORT */
    uint8 * DmaRequestEnableRegPtr = (uint8 *)(&Dma_Drv_DmaRegWPtr->DMA_DMAE);
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif

    SchM_Enter_Dma_ChannelRequest();
#if (STD_ON == DMA_DRV_REQUEST_HALT_SUPPORT)
    ASMV_KEYWORD(
        "PUSH {R0-R2}\n"
        "MOV R1, %1\n"
        "LDR R0, [R1]\n"
        "ORR R0, R0, #1\n"
        "STR R0, [R1]\n"
        "MOV R2, %2\n"
        "DMA_ECR_CHECK_BUSY:\n"
        "LDR R0, [R1]\n"
        "TST R0, #0x40\n"
        "BEQ DMA_ECR_EXIT_CHECK_BUSY\n"
        "SUB R2, R2, #1\n"
        "CMP R2, #0\n"
        "BNE DMA_ECR_CHECK_BUSY\n"
        "B DMA_ECR_EXIT_ENABLE_CHANNEL\n"
        "DMA_ECR_EXIT_CHECK_BUSY:\n"
        "LDR R0, [R1, #4]\n"
        "MOV R2, #1\n"
        "LSL R2, R2, %0\n"
        "ORR R0, R0, R2\n"
        "STR R0, [R1, #4]\n"
        "DMA_ECR_EXIT_ENABLE_CHANNEL:\n"
        "LDR R0, [R1]\n"
        "BIC R0, R0, #1\n"
        "STR R0, [R1]\n"
        "POP {R0-R2}\n"
        ::"r"(Channel), "r"(DmaBaseAddr), "I"(DMA_DRV_WAIT_BUSY_TIMEOUT):"r0","r1","r2","memory"
    );
#else /* STD_OFF == DMA_DRV_REQUEST_HALT_SUPPORT */
    DmaRequestEnableRegPtr[(uint32)Channel >> DMA_DRV_CH_GROUP_SHIFT]
        |= (uint8)(1UL << ((uint32)Channel & DMA_DRV_CH_GROUP_MASK));
#endif
    SchM_Exit_Dma_ChannelRequest();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}


/**
 * @brief      Disable dma channel request.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_DisableChannelRequest(Dma_Drv_ChannelType Channel)
{
#if (STD_ON == DMA_DRV_REQUEST_HALT_SUPPORT)
    uint32 DmaBaseAddr = DMA_BASE_ADDR;
    (void)DmaBaseAddr;
#else /* STD_OFF == DMA_DRV_REQUEST_HALT_SUPPORT */
    uint8 * DmaRequestEnableRegPtr = (uint8 *)(&Dma_Drv_DmaRegWPtr->DMA_DMAE);
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    SchM_Enter_Dma_ChannelRequest();
#if (STD_ON == DMA_DRV_REQUEST_HALT_SUPPORT)
    ASMV_KEYWORD(
        "PUSH {R0-R2}\n"
        "MOV R1, %1\n"
        "LDR R0, [R1]\n"
        "ORR R0, R0, #1\n"
        "STR R0, [R1]\n"
        "MOV R2, %2\n"
        "DMA_DCR_CHECK_BUSY:\n"
        "LDR R0, [R1]\n"
        "TST R0, #0x40\n"
        "BEQ DMA_DCR_EXIT_CHECK_BUSY\n"
        "SUB R2, R2, #1\n"
        "CMP R2, #0\n"
        "BNE DMA_DCR_CHECK_BUSY\n"
        "B DMA_DCR_EXIT_DISABLE_CHANNEL\n"
        "DMA_DCR_EXIT_CHECK_BUSY:\n"
        "LDR R0, [R1, #4]\n"
        "MOV R2, #1\n"
        "LSL R2, R2, %0\n"
        "BIC R0, R0, R2\n"
        "STR R0, [R1, #4]\n"
        "DMA_DCR_EXIT_DISABLE_CHANNEL:\n"
        "LDR R0, [R1]\n"
        "BIC R0, R0, #1\n"
        "STR R0, [R1]\n"
        "POP {R0-R2}\n"
        ::"r"(Channel), "r"(DmaBaseAddr), "I"(DMA_DRV_WAIT_BUSY_TIMEOUT):"r0","r1","r2","memory"
    );
#else /* STD_OFF == DMA_DRV_REQUEST_HALT_SUPPORT */
    DmaRequestEnableRegPtr[(uint32)Channel >> DMA_DRV_CH_GROUP_SHIFT]
        &= (uint8)(~(1UL << ((uint32)Channel & DMA_DRV_CH_GROUP_MASK)));
#endif
    SchM_Exit_Dma_ChannelRequest();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Clear channel int flag.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  IntType: Int type.
 *                      - DMA_DRV_INT_ERROR: Error interrupt.
 *                      - DMA_DRV_INT_DONE: Done interrupt.
 *                      - DMA_DRV_INT_ALL: All interrupts.
 *
 * @return     None.
 *
 */
void Dma_Drv_ClearIntStatus(Dma_Drv_ChannelType Channel, Dma_Drv_IntType IntType)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(IntType <= DMA_DRV_INT_ALL);
#endif

    SchM_Enter_Dma_ClearIntStatus();
    Dma_Drv_DmaRegWPtr->DMA_GCC = Dma_Drv_GccWpenMaskArray[IntType] |
                ((((uint32)Channel << DMA_DRV_GCC_CCES_SHIFT) |
                   ((uint32)Channel << DMA_DRV_GCC_CCIS_SHIFT)) &
                  Dma_Drv_GccClearChannelsMaskArray[IntType]);
    SchM_Exit_Dma_ClearIntStatus();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Get dma busy status.
 *
 * @param[in]  None.
 *
 * @return     Busy status.
 * @retval     TRUE: Is busy.
 * @retval     FALSE: Not busy.
 */
boolean Dma_Drv_GetBusyStatus(void)
{
    return ((boolean)Dma_Drv_DmaRegBfPtr->DMA_CONF.BUSY);
}

/**
 * @brief      Get dma halt status.
 *
 * @param[in]  None.
 *
 * @return     Whether dma halt is asserted or not.
 * @retval     TRUE: Is halted.
 * @retval     FALSE: Not halted.
 *
 */
boolean Dma_Drv_GetHaltStatus(void)
{
    return ((boolean)Dma_Drv_DmaRegBfPtr->DMA_CONF.HALT);
}

/**
 * @brief      Get dma channel error status.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     Whether dma channel error status is asserted or not.
 * @retval     TRUE: Dma channel configuration error.
 * @retval     FALSE: Dma channel no configuration error.
 *
*/
boolean Dma_Drv_GetChannelErrorStatus(Dma_Drv_ChannelType Channel)
{
    boolean Status = (boolean)0U;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    Status = (boolean)((Dma_Drv_DmaRegWPtr->DMA_CES & (0x1UL << (uint32)Channel)) != 0U);
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/**
 * @brief      Get dma all channel error status.
 *
 * @param[in]  None.
 *
 * @return     Dma error status. Each bit represents a channel.
 *
 */
uint16 Dma_Drv_GetAllChannelsErrorStatus(void)
{
    return ((uint16)(Dma_Drv_DmaRegWPtr->DMA_CES));
}

/**
 * @brief      Set dma source address.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Address: Dma transfer source address.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetSourceAddr(Dma_Drv_ChannelType Channel, uint32 Address)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_SADDR,
        DMA_DRV_SADDR_OFFSET, DMA_DRV_SADDR_WIDTH, Address);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set dma source transfer size.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Size: Dma source transfer size.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetSourceTransferSize(Dma_Drv_ChannelType Channel,
                                                 Dma_Drv_TransferSizeType Size)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(Size <= DMA_DRV_TRANSFER_SIZE_4BYTE);
#endif

    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
        DMA_DRV_SSIZE_OFFSET, DMA_DRV_SSIZE_WIDTH, (uint32)Size);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set dma destination address.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Address: Dma transfer destination address.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetDestAddr(Dma_Drv_ChannelType Channel, uint32 Address)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif

    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_DADDR,
        DMA_DRV_DADDR_OFFSET, DMA_DRV_DADDR_WIDTH, Address);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set dma source address offset in minor loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma source address offset in minor loop.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMinorLoopSrcOffset(Dma_Drv_ChannelType Channel, sint16 Offset)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif

    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_AOFF,
        DMA_DRV_SAOFF_OFFSET, DMA_DRV_SAOFF_WIDTH, (uint32)Offset);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set dma destination address offset in minor loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma destination address offset in minor loop.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMinorLoopDestOffset(Dma_Drv_ChannelType Channel, sint16 Offset)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_AOFF,
        DMA_DRV_DAOFF_OFFSET, DMA_DRV_DAOFF_WIDTH, (uint32)Offset);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set dma source address offset after a major loop done.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma source address offset after a major loop done.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMajorLoopSrcOffset(Dma_Drv_ChannelType Channel, sint16 Offset)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif

    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_MLAOFF,
        DMA_DRV_MLSAOFF_OFFSET, DMA_DRV_MLSAOFF_WIDTH, (uint32)Offset);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set dma destination address offset after a major loop done.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Offset: Dma destination address offset after a major loop done.
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMajorLoopDestOffset(Dma_Drv_ChannelType Channel, sint16 Offset)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_MLAOFF,
        DMA_DRV_MLDAOFF_OFFSET, DMA_DRV_MLDAOFF_WIDTH, (uint32)Offset);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set total number of minor loop in a major loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Num: number of minor loop in a major loop
 *
 * @return     None.
 *
 */
void Dma_Drv_SetMinorLoopNum(Dma_Drv_ChannelType Channel, uint16 Num)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteMinorLoopNum(Channel, (uint32)Num);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}
/**
 * @brief      Get number of minor loop that not finished in one major loop.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return number of rest minor loop in a major loop.
 *
 */
uint16 Dma_Drv_GetRestMinorLoopNum(Dma_Drv_ChannelType Channel)
{
    uint16 LoopNum = 0;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    LoopNum = (uint16)Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_ITER.MLSTA;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return LoopNum;
}


/**
 * @brief      Set dma destination transfer size.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Size: dma destination transfer size
 *
 * @return     None.
 *
 */
void Dma_Drv_SetDestTransferSize(Dma_Drv_ChannelType Channel,
                                             Dma_Drv_TransferSizeType Size)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(Size <= DMA_DRV_TRANSFER_SIZE_4BYTE);
#endif
    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
        DMA_DRV_DSIZE_OFFSET, DMA_DRV_DSIZE_WIDTH, (uint32)Size);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Set dma transfer num of bytes in a minor loop.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Num: dma transfer num of bytes in a minor loop
 *
 * @return     None.
 *
 */
void Dma_Drv_SetTransferByteNum(Dma_Drv_ChannelType Channel, uint32 Num)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif

    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_NUM,
        DMA_DRV_NUM_OFFSET, DMA_DRV_NUM_WIDTH, Num);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Disables/enables the DMA request after the transfer complete.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  Cmd: disable request after done
 *                  - TRUE: disables the DMA request after the transfer complete
 *                  - FALSE: enables the DMA request after the transfer complete
 *
 * @return     None.
 *
 */
void Dma_Drv_SetDisableRequestAfterDone(Dma_Drv_ChannelType Channel, boolean Cmd)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(Cmd <= TRUE);
#endif
    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
        DMA_DRV_REQDIS_OFFSET, DMA_DRV_REQDIS_WIDTH, (uint32)Cmd);
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Software trigger one channel dma transfer.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_TriggerChannelStart(Dma_Drv_ChannelType Channel)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    Dma_Drv_DmaRegWPtr->DMA_GCC = DMA_DRV_GCC_WPEN1_MASK | \
        (((uint32)Channel << DMA_DRV_GCC_SCSTART_SHIFT) & DMA_DRV_GCC_SCSTART_MASK);
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Get channel busy status.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     Whether a channel is busy or not.
 * @retval     TRUE: Is busy.
 * @retval     FALSE: Not busy.
 *
 */
boolean Dma_Drv_GetChannelBusyStatus(Dma_Drv_ChannelType Channel)
{
    boolean Status = (boolean)1U;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    Status = ((boolean)(0x1U == Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_CS.BUSY));
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/**
 * @brief      Get channel done flag.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     Whether a channel done flag is asserted or not.
 * @retval     TRUE: Done flag is asserted.
 * @retval     FALSE: Done flag is not asserted.
 *
 */
boolean Dma_Drv_GetDoneStatus(Dma_Drv_ChannelType Channel)
{
    boolean Status = (boolean)0U;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    Status = ((boolean)(0x1U == Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_CS.DONE));

#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}


/**
 * @brief      Initialize Dma HW module global configuration.
 *
 * @param[in]  ModuleCfgPtr: Pointer to configuration.
 *
 * @return     None.
 *
 */
void Dma_Drv_Init(const Dma_Drv_ConfigType * ModuleCfgPtr)
{
    if( NULL_PTR != ModuleCfgPtr )
    {
        SchM_Enter_Dma_DmaConfig();
        Dma_Drv_DmaRegBfPtr->DMA_CONF.HOEE = (uint32)ModuleCfgPtr->ErrHalt;
        Dma_Drv_DmaRegBfPtr->DMA_CONF.DBGE = (uint32)ModuleCfgPtr->DebugHalt;
        Dma_Drv_DmaRegBfPtr->DMA_CONF.RRCAE = (uint32)ModuleCfgPtr->RoundRobin;
        SchM_Exit_Dma_DmaConfig();
    }
}

/**
 * @brief      Clear channel done flag.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_ClearDoneStatus(Dma_Drv_ChannelType Channel)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif
    Dma_Drv_DmaRegWPtr->DMA_GCC = DMA_DRV_GCC_WPEN0_MASK | (uint32)Channel;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Config Dma transfer configuration parameter.
 *
 * @param[in]   Channel: Dma channel id.
 * @param[in]   ChTransCfgPtr: Pointer to transfer configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_SetChannelTransferConfig(const Dma_Drv_ChannelType Channel,
                                     const Dma_Drv_ChannelTransferConfigType * ChTransCfgPtr)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(NULL_PTR != ChTransCfgPtr);
#endif
    /* channel transfer configuration */
    
    SchM_Enter_Dma_DmaChConfig();
    if (NULL_PTR != ChTransCfgPtr->SourceConfig)
    {
        /* SetHwSourceAddr */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_SADDR,
            DMA_DRV_SADDR_OFFSET, DMA_DRV_SADDR_WIDTH, ChTransCfgPtr->SourceConfig->Addr);
        /* SetHwSourceTransferSize */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
            DMA_DRV_SSIZE_OFFSET, DMA_DRV_SSIZE_WIDTH, (uint32)ChTransCfgPtr->SourceConfig->TransferSize);
        /* SetHwMinorLoopSrcOffset */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_AOFF,
            DMA_DRV_SAOFF_OFFSET, DMA_DRV_SAOFF_WIDTH, (uint32)ChTransCfgPtr->SourceConfig->MinorLoopOffset);
        /* SetHwMajorLoopSrcOffset */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_MLAOFF,
            DMA_DRV_MLSAOFF_OFFSET, DMA_DRV_MLSAOFF_WIDTH, (uint32)ChTransCfgPtr->SourceConfig->MajorLoopOffset);
    }
    if (NULL_PTR != ChTransCfgPtr->DestinationConfig)
    {
        /* SetHwDestinationAddr */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_DADDR,
            DMA_DRV_DADDR_OFFSET, DMA_DRV_DADDR_WIDTH, ChTransCfgPtr->DestinationConfig->Addr);
        /* SetHwDestinationTransferSize */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
            DMA_DRV_DSIZE_OFFSET, DMA_DRV_DSIZE_WIDTH, (uint32)ChTransCfgPtr->DestinationConfig->TransferSize);
        /* SetHwMinorLoopDestOffset */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_AOFF,
            DMA_DRV_DAOFF_OFFSET, DMA_DRV_DAOFF_WIDTH, (uint32)ChTransCfgPtr->DestinationConfig->MinorLoopOffset);
        /* SetHwMajorLoopDestOffset */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_MLAOFF,
            DMA_DRV_MLDAOFF_OFFSET, DMA_DRV_MLDAOFF_WIDTH, (uint32)ChTransCfgPtr->DestinationConfig->MajorLoopOffset);
    }
    if (NULL_PTR != ChTransCfgPtr->ControlConfig)
    {
        /* SetHwMinorLoopCnt */
        (void)Dma_Drv_SpinWriteMinorLoopNum(Channel, (uint32)ChTransCfgPtr->ControlConfig->MinorLoopCnt);
        /* SetHwTransferNum */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_NUM,
            DMA_DRV_NUM_OFFSET, DMA_DRV_NUM_WIDTH, ChTransCfgPtr->ControlConfig->TransferNum);
        /* SetHwAutoDisRequest */
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
            DMA_DRV_REQDIS_OFFSET, DMA_DRV_REQDIS_WIDTH, ChTransCfgPtr->ControlConfig->ReqDis);
    }
    SchM_Exit_Dma_DmaChConfig();
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Config Dma channel global configuration parameter.
 *
 * @param[in]   Channel: Dma channel id.
 * @param[in]   ChGlobalCfgPtr: Pointer to global configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_SetChannelGlobalConfig(const Dma_Drv_ChannelType Channel,
                                     const Dma_Drv_ChannelGlobalConfigType * ChGlobalCfgPtr)
{
    uint32 RegValue;
    volatile uint32 * PriRegBasePtr = NULL_PTR;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(NULL_PTR != ChGlobalCfgPtr);
#endif
    if (NULL_PTR != ChGlobalCfgPtr->RequestConfig)
    {
        Dma_Drv_SwReqSrcFlag[Channel] =
            (boolean)(DMA_DRV_REQ_SOFTWARE == ChGlobalCfgPtr->RequestConfig->MuxReqSrc);
        SchM_Enter_Dma_DmamuxChCfg();
        /* ControlHwMuxChannel */
        Dma_Drv_DmamuxRegBfPtr->DMA_MUX_CH_CFG[Channel].ENABLE =
            ChGlobalCfgPtr->RequestConfig->ReqEn;
        /* SelectHwMuxSource*/
        Dma_Drv_DmamuxRegBfPtr->DMA_MUX_CH_CFG[Channel].SRC_MUX =
            (uint8)ChGlobalCfgPtr->RequestConfig->MuxReqSrc;
        SchM_Exit_Dma_DmamuxChCfg();
    }

    /* ControlHwErrInt*/
    SchM_Enter_Dma_DmaEie();
    RegValue = Dma_Drv_DmaRegWPtr->DMA_EIE;
    RegValue &= ~Dma_Drv_ChannelMaskArray[Channel];
    RegValue |= (uint32)(ChGlobalCfgPtr->ErrIntEn) << (uint32)Channel;
    Dma_Drv_DmaRegWPtr->DMA_EIE = RegValue;
    SchM_Exit_Dma_DmaEie();

    /* SetHwMajorDoneInt*/
    SchM_Enter_Dma_DmaChConfig();
    (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
        DMA_DRV_INTE_OFFSET, DMA_DRV_INTE_WIDTH, ChGlobalCfgPtr->MajorIntEn);
    SchM_Exit_Dma_DmaChConfig();

    if (NULL_PTR != ChGlobalCfgPtr->PriorityConfig)
    {
        /* SetHwPriority*/
        SchM_Enter_Dma_DmaCprio();
        PriRegBasePtr = (volatile uint32 *)((uint32)(&(Dma_Drv_DmaRegWPtr ->DMA_CPRI0))
                                        + (((uint32)Channel >> 0x2U) << 0x2U));

        RegValue = *PriRegBasePtr;
        RegValue &= ~(DMA_DRV_CHANNEL_PRI_MASK << DMA_DRV_CHANNEL_PRI_SHIFT(Channel));
        RegValue |= (uint32)(ChGlobalCfgPtr->PriorityConfig->Priority) << \
            DMA_DRV_CHANNEL_PRI_SHIFT(Channel);

        /* SetHwPreemption*/
        RegValue &= ~(0x1UL << DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel));
        RegValue |= ((uint32)(ChGlobalCfgPtr->PriorityConfig->PreemptionDis) & 0x1U) << \
            DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel);

        /* SetHwSuspend*/
        RegValue &= ~(0x2UL << DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel));
        RegValue |= ((uint32)(ChGlobalCfgPtr->PriorityConfig->SuspendEn) & 0x1U) << \
            (DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel) + 1U);
        *PriRegBasePtr = RegValue;
        SchM_Exit_Dma_DmaCprio();
    }

#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Get dma last error status.
 *
 * @param[in]  None.
 *
 * @return     Last dma error type and channel id.
 *
 */
uint16 Dma_Drv_GetLastErrorStatus(void)
{
    return ((uint16)(Dma_Drv_DmaRegWPtr->DMA_ES & 0xFFFFU));
}

/**
 * @brief      Set channel int mask.
 *
 * @param[in]  Channel: Dma channel id.
 * @param[in]  IntType: Int type.
 *                      - DMA_DRV_INT_ERROR: error interrupt.
 *                      - DMA_DRV_INT_DONE: done interrupt.
 *                      - DMA_DRV_INT_ALL: all interrupt.
 * @param[in]  Control: Int enable.
 *                      - TRUE: Enable.
 *                      - FALSE: Disable.
 *
 * @return     None.
 *
 */
void Dma_Drv_ControlInt(Dma_Drv_ChannelType Channel, Dma_Drv_IntType IntType,
                                    boolean Control)
{
    uint32 RegValue;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(Control <= TRUE);
#endif
    switch (IntType)
    {
        case DMA_DRV_INT_ERROR:
            SchM_Enter_Dma_DmaEie();
            RegValue = Dma_Drv_DmaRegWPtr->DMA_EIE;
            RegValue &= ~Dma_Drv_ChannelMaskArray[Channel];
            RegValue |= (uint32)Control << (uint32)Channel;
            Dma_Drv_DmaRegWPtr->DMA_EIE = RegValue;
            SchM_Exit_Dma_DmaEie();
            break;

        case DMA_DRV_INT_DONE:
            SchM_Enter_Dma_DmaChConfig();
            (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
                DMA_DRV_INTE_OFFSET, DMA_DRV_INTE_WIDTH, (uint32)Control);
            SchM_Exit_Dma_DmaChConfig();
            break;

        case DMA_DRV_INT_ALL:
            SchM_Enter_Dma_DmaEie();
            RegValue = Dma_Drv_DmaRegWPtr->DMA_EIE;
            RegValue &= ~Dma_Drv_ChannelMaskArray[Channel];
            RegValue |= (uint32)Control << (uint32)Channel;
            Dma_Drv_DmaRegWPtr->DMA_EIE = RegValue;
            SchM_Exit_Dma_DmaEie();
            SchM_Enter_Dma_DmaChConfig();
            (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
                DMA_DRV_INTE_OFFSET, DMA_DRV_INTE_WIDTH, (uint32)Control);
            SchM_Exit_Dma_DmaChConfig();
            break;

        default:
            /*Do nothing*/
            break;
    }
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      DMA error interrupt handler.
 *
 * @param[in]  None.
 *
 * @return     None.
 *
 */
void Dma_Drv_ErrorIntHandler(void)
{
    uint32 Status;
    uint32 PhysChId;

    Status = Dma_Drv_DmaRegWPtr->DMA_CES;
    Status &= Dma_Drv_DmaRegWPtr->DMA_EIE;
    /* clear error status*/
    Dma_Drv_DmaRegWPtr->DMA_GCC = (DMA_DRV_GCC_WPEN2_MASK | DMA_DRV_GCC_CACES_MASK);

    for (PhysChId = (uint32)DMA_DRV_PHYS_CH_0; PhysChId < DMA_DRV_CHANNEL_NUM; PhysChId++)
    {
        if ((Status & Dma_Drv_ChannelMaskArray[PhysChId]) != 0U)
        {
            if(Dma_Drv_ErrIsrCbPtr != NULL_PTR)
            {
                Dma_Drv_ErrIsrCbPtr((Dma_Drv_ChannelType)PhysChId);
            }
            else
            {
                Dma_Drv_DmaRegWPtr->DMA_EIE &= ~Dma_Drv_ChannelMaskArray[PhysChId];
            }
        }
    }

}

/**
 * @brief      DMA done interrupt handle.
 *
 * @param[in]  Channel: Dma channel id.
 *
 * @return     None.
 *
 */
void Dma_Drv_DoneIntHandler(Dma_Drv_ChannelType Channel)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
#endif

    /* clear interrupt status */
    Dma_Drv_DmaRegWPtr->DMA_GCC = DMA_DRV_GCC_WPEN03_MASK | \
        (((uint32)Channel << DMA_DRV_GCC_CCIS_SHIFT) & DMA_DRV_GCC_CCIS_MASK) | \
        ((uint32)Channel  & DMA_DRV_GCC_CCDONE_MASK);

    if(NULL_PTR != Dma_Drv_IsrCbPtr )
    {
        Dma_Drv_IsrCbPtr(Channel);
    }
    else
    {
        (void)Dma_Drv_SpinWriteRegister(&Dma_Drv_DmaRegWPtr->DMA_CH_CONFIG[Channel].DMA_CS,
            DMA_DRV_INTE_OFFSET, DMA_DRV_INTE_WIDTH, 0U);
    }
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Install error interrupt callback function.
 *
 * @param[in]  CbFunPtr: Error interrupt callback function.
 *
 * @return     None.
 *
 */
void Dma_Drv_InstallErrIntCallbackFunc(Dma_Drv_ErrIntCallbackType CbFunPtr)
{
    if( NULL_PTR != CbFunPtr )
    {
        Dma_Drv_ErrIsrCbPtr = CbFunPtr;
    }
}

/**
 * @brief       Get Dma transfer configuration parameter.
 *
 * @param[in]   Channel: Dma channel id.
 * @param[out]  ChTransCfgPtr: Pointer to transfer configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_GetChannelTransferConfig(Dma_Drv_ChannelType Channel,
                                    const Dma_Drv_ChannelTransferConfigType * ChTransCfgPtr)
{
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(NULL_PTR != ChTransCfgPtr);
#endif
    if (NULL_PTR != ChTransCfgPtr->SourceConfig)
    {
        /* GetHwSourceAddr */
        ChTransCfgPtr->SourceConfig->Addr = Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_SADDR.SADDR;
        /* GetHwSourceTransferSize */
        ChTransCfgPtr->SourceConfig->TransferSize = 
            (Dma_Drv_TransferSizeType)Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_CS.SSIZE;
        /* GetHwMinorLoopSrcOffset */
        ChTransCfgPtr->SourceConfig->MinorLoopOffset =
            Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_AOFF.SAOFF;
        /* GetHwMajorLoopSrcOffset */
        ChTransCfgPtr->SourceConfig->MajorLoopOffset =
            Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_MLAOFF.MLSAOFF;
    }
    if (NULL_PTR != ChTransCfgPtr->DestinationConfig)
    {
        /* GetHwDestinationAddr */
        ChTransCfgPtr->DestinationConfig->Addr =
            Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_DADDR.DADDR;
        /* GetHwDestinationTransferSize */
        ChTransCfgPtr->DestinationConfig->TransferSize =
            (Dma_Drv_TransferSizeType)Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_CS.DSIZE;
        /* GetHwMinorLoopDestOffset */
        ChTransCfgPtr->DestinationConfig->MinorLoopOffset =
            Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_AOFF.DAOFF;
        /* GetHwMajorLoopDestOffset */
        ChTransCfgPtr->DestinationConfig->MajorLoopOffset =
            Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_MLAOFF.MLDAOFF;
    }
    if (NULL_PTR != ChTransCfgPtr->ControlConfig)
    {
        /* GetHwMinorLoopCnt */
        ChTransCfgPtr->ControlConfig->MinorLoopCnt =
            Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_ITER.MLITER;
        /* GetHwTransferNum */
        ChTransCfgPtr->ControlConfig->TransferNum =
            Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_NUM.NUM;
        /* GetHwAutoDisRequest */
        ChTransCfgPtr->ControlConfig->ReqDis =
            (boolean)Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_CS.REQDIS;
    }
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Get Dma channel global configuration parameter.
 *
 * @param[in]   Channel: Dma channel id.
 * @param[out]  ChGlobalCfgPtr: Pointer to global configuration.
 *
 * @return      None.
 *
 */
void Dma_Drv_GetChannelGlobalConfig(Dma_Drv_ChannelType Channel,
                                    Dma_Drv_ChannelGlobalConfigType * ChGlobalCfgPtr)
{
    uint32 RegValue;
    uint32 PriorityRegValue;
    const volatile uint32 * PriRegBasePtr = NULL_PTR;
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(Channel <= DMA_DRV_PHYS_CH_15);
    MCALLIB_DEV_ASSERT(NULL_PTR != ChGlobalCfgPtr);
#endif
    if (NULL_PTR != ChGlobalCfgPtr->RequestConfig)
    {
        /* GetHwMuxChannelControl */
        ChGlobalCfgPtr->RequestConfig->ReqEn =
            (boolean)Dma_Drv_DmamuxRegBfPtr->DMA_MUX_CH_CFG[Channel].ENABLE;
        if ((boolean)FALSE == Dma_Drv_SwReqSrcFlag[Channel])
        {
            /* GetHwMuxSource*/
            ChGlobalCfgPtr->RequestConfig->MuxReqSrc =
                (Dma_Drv_RequestSourceType)Dma_Drv_DmamuxRegBfPtr->DMA_MUX_CH_CFG[Channel].SRC_MUX;
        }
        else
        {
            ChGlobalCfgPtr->RequestConfig->MuxReqSrc = DMA_DRV_REQ_SOFTWARE;
        }
    }

    /* GetHwErrIntControl*/
    RegValue = Dma_Drv_DmaRegWPtr->DMA_EIE;
    RegValue &= Dma_Drv_ChannelMaskArray[Channel];
    ChGlobalCfgPtr->ErrIntEn = (RegValue != 0U) ? TRUE : FALSE;

    /* GetHwMajorDoneInt*/
    ChGlobalCfgPtr->MajorIntEn = (boolean)Dma_Drv_DmaRegBfPtr->DMA_CH_CONFIG[Channel].DMA_CS.INTE;

    if (NULL_PTR != ChGlobalCfgPtr->PriorityConfig)
    {
        PriRegBasePtr = (volatile uint32 *)((uint32)(&(Dma_Drv_DmaRegWPtr ->DMA_CPRI0))
                                        + (((uint32)Channel >> 0x2U) << 0x2U));

        PriorityRegValue = *PriRegBasePtr;
        RegValue = PriorityRegValue;
        RegValue &= (DMA_DRV_CHANNEL_PRI_MASK << DMA_DRV_CHANNEL_PRI_SHIFT(Channel));
        ChGlobalCfgPtr->PriorityConfig->Priority =
            (uint8)(RegValue >> DMA_DRV_CHANNEL_PRI_SHIFT(Channel));

        /* GetHwPreemption*/
        RegValue = PriorityRegValue;
        RegValue &= (0x1UL << DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel));
        ChGlobalCfgPtr->PriorityConfig->PreemptionDis =
            (boolean)(RegValue >> DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel));

        /* GetHwSuspend*/
        RegValue = PriorityRegValue;
        RegValue &= (0x2UL << DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel));
        ChGlobalCfgPtr->PriorityConfig->SuspendEn =
            (boolean)(RegValue >> (DMA_DRV_CHANNEL_PREEMPT_SHIFT(Channel) + 1U));
    }
#if (STD_ON == DMA_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"


/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma */
/** @} end of group Dma_Module */
