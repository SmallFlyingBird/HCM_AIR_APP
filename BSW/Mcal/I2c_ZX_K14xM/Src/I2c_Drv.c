/**************************************************************************************************/
/**
 * @file      : I2c_Drv.c
 * @brief     : AUTOSAR I2c hardware driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  I2c_Module
 *  @{
 */

/** @addtogroup  I2c_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "I2c_Drv.h"
#include "Device_Regs.h"
#include "SchM_I2c.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define I2C_DRV_C_VENDOR_ID                   0x00B3U
#define I2C_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define I2C_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define I2C_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define I2C_DRV_C_SW_MAJOR_VERSION            1U
#define I2C_DRV_C_SW_MINOR_VERSION            2U
#define I2C_DRV_C_SW_PATCH_VERSION            2U

#if (I2C_DRV_C_VENDOR_ID != I2C_DRV_H_VENDOR_ID)
    #error "Vendor ID of I2c_Drv.c and I2c_Drv.h are different"
#endif

#if ((I2C_DRV_C_AR_RELEASE_MAJOR_VERSION != I2C_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (I2C_DRV_C_AR_RELEASE_MINOR_VERSION != I2C_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (I2C_DRV_C_AR_RELEASE_REVISION_VERSION != I2C_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of I2c_Drv.c and I2c_Drv.h are different"
#endif

#if ((I2C_DRV_C_SW_MAJOR_VERSION != I2C_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (I2C_DRV_C_SW_MINOR_VERSION != I2C_DRV_H_SW_MINOR_VERSION) ||                                 \
     (I2C_DRV_C_SW_PATCH_VERSION != I2C_DRV_H_SW_PATCH_VERSION))
    #error "Software version of I2c_Drv.c and I2c_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((I2C_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (I2C_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of I2c_Drv.c and Device_Regs.h are different"
    #endif

    #if ((I2C_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_I2C_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (I2C_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_I2C_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of I2c_Drv.c and SchM_I2c.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define I2C_DRV_CMD_RESTART_MASK ((uint32)0x400U)
#define I2C_DRV_CMD_STOP_MASK    ((uint32)0x200U)
#define I2C_DRV_CMD_READ_MASK    ((uint32)0x100U)
#define I2C_DRV_ERR_NACK_MASK                                                                      \
    (((uint32)0x01U << (uint32)I2C_DRV_ERR_DATA_NO_ACK) |                                          \
     ((uint32)0x01U << (uint32)I2C_DRV_ERR_7BIT_ADDR_NO_ACK) |                                     \
     ((uint32)0x01U << (uint32)I2C_DRV_ERR_10BIT_ADDR1_NO_ACK) |                                   \
     ((uint32)0x01U << (uint32)I2C_DRV_ERR_10BIT_ADDR2_NO_ACK))

/** @} end of group Private_MacroDefinition */

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
#define I2C_START_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

/**
 *  @brief I2C0, I2C1 address array
 */
static Reg_I2c_BfType *const I2c_Drv_I2cRegBfPtr[I2C_DRV_INSTANCE_NUM] = {
    (Reg_I2c_BfType *)I2C0_BASE_ADDR
#if (I2C_DRV_INSTANCE_NUM == 2U)
    ,
    (Reg_I2c_BfType *)I2C1_BASE_ADDR
#endif
};

/**
 *  @brief I2C0, I2C1 address array
 */
static Reg_I2c_WType *const I2c_Drv_I2cRegWPtr[I2C_DRV_INSTANCE_NUM] = {
    (Reg_I2c_WType *)I2C0_BASE_ADDR
#if (I2C_DRV_INSTANCE_NUM == 2U)
    ,
    (Reg_I2c_WType *)I2C1_BASE_ADDR
#endif
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

static I2c_Drv_MasterStateType I2c_Drv_MasterState[I2C_DRV_INSTANCE_NUM];
static I2c_Drv_SlaveStateType  I2c_Drv_SlaveState[I2C_DRV_INSTANCE_NUM];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/** @defgroup Private_ConstDefinition
 *  @{
 */
#define I2C_START_SEC_CONST_32
#include "I2c_MemMap.h"

/**
 *  @brief I2C interrupt enable array
 */
static const uint32 I2c_Drv_IntEnableTable[(uint32)I2C_DRV_INT_ALL + 1U] = {
    0x00000001U, /*!< I2C_DRV_INT_GEN_CALL */
    0x00000002U, /*!< I2C_DRV_INT_TX_OVER */
    0x00000004U, /*!< I2C_DRV_INT_ERROR_ABORT */
    0x00000008U, /*!< I2C_DRV_INT_ACTIVITY */
    0x00000010U, /*!< I2C_DRV_INT_STOP_DET */
    0x00000020U, /*!< I2C_DRV_INT_START_DET */
    0x00400000U, /*!< I2C_DRV_INT_RD_REQ */
    0x00800000U, /*!< I2C_DRV_INT_RX_DONE */
    0x01000000U, /*!< I2C_DRV_INT_RX_UNDER */
    0x02000000U, /*!< I2C_DRV_INT_RX_OVER */
    0x04000000U, /*!< I2C_DRV_INT_RESTART_DET */
    0x08000000U, /*!< I2C_DRV_SCL_STUCK_AT_LOW */
    0x40000000U, /*!< I2C_DRV_INT_RX_FULL */
    0x80000000U, /*!< I2C_DRV_INT_TX_EMPTY */
    0xCFC0003FU  /*!< I2C_DRV_INT_ALL */
};

#define I2C_STOP_SEC_CONST_32
#include "I2c_MemMap.h"

/** @} end of group Private_ConstDefinition */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
static void I2c_Drv_SlaveEvent(I2c_Drv_IdType InstId, I2c_Drv_SlaveEventType Event);
static void I2c_Drv_MasterEvent(I2c_Drv_IdType InstId, I2c_Drv_MasterEventType Event);
LOCAL_INLINE void I2c_Drv_ClearInt(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType);
LOCAL_INLINE void I2c_Drv_SetInterrupt(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType,
                                       boolean IntEnable);
LOCAL_INLINE void I2c_Drv_ClearErrorStatusAll(I2c_Drv_IdType InstId);
LOCAL_INLINE boolean I2c_Drv_GetReceivedAck(I2c_Drv_IdType InstId);
LOCAL_INLINE uint32 I2c_Drv_GetRestartStopCmd(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterEndTransfer(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterSendByteEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterReadCmdEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterReceiveByteEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_SetMasterGlobalConfig(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterHandleDataEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterHandleErrorAbortEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterHandleErrorEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterHandleFinishEvent(I2c_Drv_IdType InstId);
static boolean I2c_Drv_MasterHandleEventBlocking(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterTransmitDataBlocking(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterSendHandler(I2c_Drv_IdType InstId, uint32 IntStatus);
static void I2c_Drv_MasterReceiveHandler(I2c_Drv_IdType InstId, uint32 IntStatus);
static void I2c_Drv_MasterIntHandler(I2c_Drv_IdType InstId);
static void I2c_Drv_SlaveSendByteEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_SlaveReceiveByteEvent(I2c_Drv_IdType InstId);
static void I2c_Drv_SlaveIntHandler(I2c_Drv_IdType InstId);
static void I2c_Drv_MasterInit(const I2c_Drv_IdType            InstId,
                               const I2c_Drv_MasterConfigType *MasterCfgPtr);
static void I2c_Drv_SlaveInit(const I2c_Drv_IdType           InstId,
                              const I2c_Drv_SlaveConfigType *SlaveCfgPtr);
static void I2c_Drv_MasterDeInit(const I2c_Drv_IdType InstId);
static void I2c_Drv_SlaveDeInit(const I2c_Drv_IdType InstId);
#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief     This function notify slave event to user through callback.
 * @param[in] InstId: Select the I2C instance id.
 * @param[in] Event: Slave event type.
 *
 * @return    None
 */
static void I2c_Drv_SlaveEvent(I2c_Drv_IdType InstId, I2c_Drv_SlaveEventType Event)
{
    const I2c_Drv_SlaveStateType *SlaveState;

    SlaveState = &I2c_Drv_SlaveState[InstId];

    if ((I2C_DRV_SLAVE_EVENT_RX_FULL == Event) || (I2C_DRV_SLAVE_EVENT_TX_EMPTY == Event) ||
        (I2C_DRV_SLAVE_EVENT_STOP == Event) || (I2C_DRV_SLAVE_EVENT_RESTART == Event))
    {
        if (NULL_PTR != SlaveState->I2cCallback)
        {
            SlaveState->I2cCallback((uint8)Event, (uint8)InstId);
        }
    }
    else /* Some error event has occurred */
    {
        if (NULL_PTR != SlaveState->I2cErrCallback)
        {
            SlaveState->I2cErrCallback((uint8)Event, (uint8)InstId);
        }
    }
}

/**
 * @brief     This function notify master event to user through callback.
 * @param[in] InstId: Select the I2C instance id.
 * @param[in] Event: Master event type.
 *
 * @return    None
 */
static void I2c_Drv_MasterEvent(I2c_Drv_IdType InstId, I2c_Drv_MasterEventType Event)
{
    const I2c_Drv_MasterStateType *MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    if ((I2C_DRV_MASTER_EVENT_END_TRANSFER == Event) ||
        (I2C_DRV_MASTER_EVENT_RESTART_TRANSFER == Event))
    {
        if (NULL_PTR != MasterState->I2cCallback)
        {
            MasterState->I2cCallback((uint8)Event, (uint8)InstId);
        }
    }
    else /* Some error event has occurred */
    {
        if (NULL_PTR != MasterState->I2cErrCallback)
        {
            MasterState->I2cErrCallback((uint8)Event, (uint8)InstId);
        }
    }
}

/**
 * @brief      Clear specified interrupt type
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  IntType:  Specified interrupt type.
 *             - I2C_DRV_INT_GEN_CALL
 *             - I2C_DRV_INT_TX_OVER
 *             - I2C_DRV_INT_ERROR_ABORT
 *             - I2C_DRV_INT_ACTIVITY
 *             - I2C_DRV_INT_STOP_DET
 *             - I2C_DRV_INT_START_DET
 *             - I2C_DRV_INT_RD_REQ
 *             - I2C_DRV_INT_RX_DONE
 *             - I2C_DRV_INT_RX_UNDER
 *             - I2C_DRV_INT_RX_OVER
 *             - I2C_DRV_INT_RESTART_DET
 *             - I2C_DRV_INT_SCL_STUCK_AT_LOW
 *             - I2C_DRV_INT_ALL
 *
 * @return     None
 *
 */
LOCAL_INLINE void I2c_Drv_ClearInt(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType)
{
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
#endif

    Reg_I2c_WType *I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    I2CWx->I2C_STATUS0 = I2c_Drv_IntEnableTable[IntType];

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Enable/Disable specified interrupt type
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  IntType:  Specified interrupt type.
 * @param[in]  IntEnable:  Interrupt enable/disable type.
 *
 * @return     None
 *
 */
LOCAL_INLINE void I2c_Drv_SetInterrupt(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType,
                                       boolean IntEnable)
{

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
#endif

    Reg_I2c_WType *I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    if (FALSE == IntEnable)
    {
        I2CWx->I2C_INT_ENABLE &= (~I2c_Drv_IntEnableTable[IntType]);
    }
    else
    {
        I2CWx->I2C_INT_ENABLE |= I2c_Drv_IntEnableTable[IntType];
    }

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Clear all error status .
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return none
 *
 */
LOCAL_INLINE void I2c_Drv_ClearErrorStatusAll(I2c_Drv_IdType InstId)
{
    volatile uint32 DummyData;
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
#endif

    const Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    /* Dummy read to clear all error status */
    DummyData = I2Cx->I2C_RD_CLR_ERR_STATUS.CLR_ERR;
    (void)DummyData;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Get the addr/data receive ack.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     boolean: any NACK flag is set or not
 * @retval     TRUE: no NACK error is presented.
 * @retval     FALSE: any NACK error is presented.
 */
LOCAL_INLINE boolean I2c_Drv_GetReceivedAck(I2c_Drv_IdType InstId)
{
    const Reg_I2c_WType *I2CWx;
    I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    return (0U == ((I2CWx->I2C_ERROR_STATUS) & I2C_DRV_ERR_NACK_MASK)) ? TRUE : FALSE;
}

/**
 * @brief      Get restart and stop cmd mask of current data request(master send or read command).
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     Restart and Stop cmd mask of register I2C_COMMAND_DATA.
 * @retval     - 0x0U: restart disabled and stop disabled
 * @retval     - 0x200U: restart disabled and stop enabled
 * @retval     - 0x400U: restart enabled and stop disabled
 * @retval     - 0x600U: restart enabled and stop enabled
 *
 */
LOCAL_INLINE uint32 I2c_Drv_GetRestartStopCmd(I2c_Drv_IdType InstId)
{
    uint32 RestartStopCmd = 0U;

    I2c_Drv_MasterStateType *MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];

    /* The first byte with (re)start condition. */
    if (MasterState->TotalBufferSize == MasterState->RemainingSize)
    {
        RestartStopCmd |= I2C_DRV_CMD_RESTART_MASK;
    }
    /* The last byte with stop condition, note that the last byte can also be the first byte. */
    if ((1U == MasterState->RemainingSize) && (TRUE == MasterState->SendStop))
    {
        RestartStopCmd |= I2C_DRV_CMD_STOP_MASK;
    }

    return RestartStopCmd;
}

/**
 * @brief      Master end transfer.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterEndTransfer(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType *MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_ALL, FALSE);
    I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);

    MasterState->DataBuffer = NULL_PTR;
    MasterState->RemainingSize = 0U;
    MasterState->I2cIdle = TRUE;
}

/**
 * @brief      This function sends one byte according to current remaining size.
 *             This function is used for both sync mode and async mode.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterSendByteEvent(I2c_Drv_IdType InstId)
{
    uint32                   RestartStopCmd;
    Reg_I2c_WType           *I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    I2c_Drv_MasterStateType *MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    if ((MasterState->RemainingSize > 0U) &&
        (MasterState->RemainingSize <= MasterState->TotalBufferSize))
    {
        RestartStopCmd = I2c_Drv_GetRestartStopCmd(InstId);
        /* Send one byte */
        I2CWx->I2C_COMMAND_DATA = RestartStopCmd | (((uint32)MasterState->DataBuffer[0]));

        MasterState->RemainingSize--;
        if (0U != MasterState->RemainingSize)
        {
            MasterState->DataBuffer++;
        }
    }
    else
    {
        /* Defensive programming for overflow, should never get here in normal */
    }
}

/**
 * @brief      This function sends one read command according to current remaining size.
 *             This function is used for both sync mode and async mode.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterReadCmdEvent(I2c_Drv_IdType InstId)
{
    uint32                   RestartStopCmd;
    Reg_I2c_WType           *I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    I2c_Drv_MasterStateType *MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Send next read command except for the last byte received. */
    if ((MasterState->RemainingSize > 0U) &&
        (MasterState->RemainingSize <= MasterState->TotalBufferSize))
    {
        RestartStopCmd = I2c_Drv_GetRestartStopCmd(InstId);
        /* Set read command */
        I2CWx->I2C_COMMAND_DATA = RestartStopCmd | I2C_DRV_CMD_READ_MASK;
        MasterState->RemainingSize--;
    }
    else
    {
        /* Defensive programming for overflow, should never get here in normal */
    }
}

/**
 * @brief      This function read one byte from RxFIFO.
 *             This function is used for both sync mode and async mode.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterReceiveByteEvent(I2c_Drv_IdType InstId)
{
    Reg_I2c_WType           *I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    I2c_Drv_MasterStateType *MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    if (MasterState->RemainingSize <= MasterState->TotalBufferSize)
    {
        /* Read one byte to buffer */
        MasterState->DataBuffer[0U] = ((uint8)(I2CWx->I2C_COMMAND_DATA & 0xFFUL));
        MasterState->DataBuffer++;
        MasterState->ReceivedSize++;
    }
    else
    {
        /* Defensive programming for overflow, should never get here in normal */
    }
}

/**
 * @brief      Initialize a hardware I2c instance to be prepared for data transmission.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_SetMasterGlobalConfig(I2c_Drv_IdType InstId)
{
    const I2c_Drv_MasterStateType *MasterState;
    Reg_I2c_BfType                *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

    MasterState = &I2c_Drv_MasterState[InstId];

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(MasterState != NULL_PTR);
#endif

    SchM_Enter_I2c_SetMasterGlobalConfig();
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;
    /* Set I2C start its transfer in 7 or 10 bits address mode */
    I2Cx->I2C_CONFIG1.MASTER_10BIT_ADDR_SEL = (uint32)(MasterState->AddrBitMode);
    /* Set the target address */
    I2Cx->I2C_DEST_ADDR.DEST_ADDR = (uint32)MasterState->SlaveAddr;
    /* Enable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 1U;
    SchM_Exit_I2c_SetMasterGlobalConfig();

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Handle data transfer event in sync mode.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterHandleDataEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType *MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];

    const Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    if (TRUE == MasterState->SendData)
    {
        if (1U == I2Cx->I2C_STATUS1.TXFIO_IS_NOT_FULL)
        {
            I2c_Drv_MasterSendByteEvent(InstId);
        }
    }
    else /* FALSE == MasterState->SendData */
    {
        if (1U == I2Cx->I2C_STATUS1.RXFIFO_IS_NOT_EMPTY)
        {
            I2c_Drv_MasterReceiveByteEvent(InstId);
        }
        if (1U == I2Cx->I2C_STATUS1.TXFIO_IS_NOT_FULL)
        {
            I2c_Drv_MasterReadCmdEvent(InstId);
        }
    }
}

/**
 * @brief      Handle error abort interrupt event.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterHandleErrorAbortEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType *MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];

    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    if (1U == I2Cx->I2C_ERROR_STATUS.ERR_SDA_LOW_TIMEOUT)
    {
        SchM_Enter_I2c_I2cConfig0Reg();
        /* Trigger start SDA recover mechanism */
        I2Cx->I2C_CONFIG0.SDA_RECOVER_EN = 1U;
        SchM_Exit_I2c_I2cConfig0Reg();

        MasterState->Status = I2C_DRV_ERROR_STATUS;
        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_TRANSFER_ERROR);
    }
    else if (FALSE == I2c_Drv_GetReceivedAck(InstId))
    {
        MasterState->Status = I2C_DRV_RECEIVED_NACK_STATUS;
        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_NACK);
    }
    else
    /* other error types, which can be handled by user */
    {
        MasterState->Status = I2C_DRV_ERROR_STATUS;
        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_TRANSFER_ERROR);
    }
    I2c_Drv_ClearErrorStatusAll(InstId);
}

/**
 * @brief      Handle error interrupt event in sync mode.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterHandleErrorEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType *MasterState;
    Reg_I2c_BfType          *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];

    if (1U == I2Cx->I2C_STATUS0.SCL_STUCK_AT_LOW)
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_SCL_STUCK_AT_LOW);

        if (0U == I2Cx->I2C_STATUS1.TXFIFO_EMPTY_MASTER_HOLD)
        {
            MasterState->Status = I2C_DRV_TIMEOUT_STATUS;
            /* SCL low timeout due to external pull-down of the bus or timing exception, I2C master
             * system reset is required. */
            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_STUCK_LOW_TIMEOUT);
        }
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
        else
        {
            /* SCL low timeout due to master hold bus, notify and continue transmission */
            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_HOLD_LOW_TIMEOUT);
        }
#endif /* STD_ON == I2C_DRV_DEV_ERROR_DETECT */
    }
    else if (1U == I2Cx->I2C_STATUS0.ERROR_ABORT)
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ERROR_ABORT);

        I2c_Drv_MasterHandleErrorAbortEvent(InstId);
    }
    else
    {
        /* Do nothing */
    }
}

/**
 * @brief      Handle data transfer finish event in sync mode.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterHandleFinishEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType *MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];

    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    if (((0U == MasterState->RemainingSize) && (TRUE == MasterState->SendData)) ||
        ((MasterState->ReceivedSize>=MasterState->TotalBufferSize)&&(FALSE==MasterState->SendData)))
    {
        if (TRUE == MasterState->SendStop)
        {
            /* wait here for stop condition */
            if (1U == I2Cx->I2C_STATUS0.STOP_DETECT)
            {
                MasterState->Status = I2C_DRV_SUCCESS_STATUS;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Wait here for master hold. Also check START_DETECT flag to avoid reading
             * TXFIFO_EMPTY_MASTER_HOLD of last byte. */
            if ((1U == I2Cx->I2C_STATUS0.START_DETECT) &&
                (1U == I2Cx->I2C_STATUS1.TXFIFO_EMPTY_MASTER_HOLD))
            {
                MasterState->Status = I2C_DRV_SUCCESS_STATUS;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
        /* There is still data in buffer when sending or the buffer is not full when receiving */
    }
}

/**
 * @brief      Loop to handle events until completion or an error occurs.
 *             This is part of the function I2c_Drv_MasterTransmitDataBlocking().
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     boolean: result status
 * @retval     TRUE: complete successfully
 * @retval     FALSE: some error occurs
 *
 */
static boolean I2c_Drv_MasterHandleEventBlocking(I2c_Drv_IdType InstId)
{
    boolean RetVal;
    uint32  CurrentTicks = 0U;      /* initialize current counter */
    uint32  ElapsedTicks = 0U;      /* elapse elapsed time */
    uint32  TotalElapsedTicks = 0U; /* total elapsed time*/
    uint32  TimeoutTicks = McalLib_MicroSecToTicks(I2C_DRV_TIMEOUT_TYPE, I2C_DRV_TIMEOUT);

    I2c_Drv_MasterStateType *MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];

    (void)McalLib_GetCounterValue(I2C_DRV_TIMEOUT_TYPE, &CurrentTicks);
    I2c_Drv_MasterHandleErrorEvent(InstId);
    do
    {
        I2c_Drv_MasterHandleDataEvent(InstId);

        I2c_Drv_MasterHandleFinishEvent(InstId);
        /* Handle error event after finish event to ensure NACK detected. */
        /* Ensure no extra operations when error event happened */
        I2c_Drv_MasterHandleErrorEvent(InstId);

        (void)McalLib_GetElapsedValue(I2C_DRV_TIMEOUT_TYPE, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
    }
    while ((I2C_DRV_BUSY_STATUS == MasterState->Status) && (TotalElapsedTicks < TimeoutTicks));

    RetVal = (TotalElapsedTicks >= TimeoutTicks) ? FALSE : TRUE;

    return RetVal;
}

/**
 * @brief      Send or receive data in data buffer until completion or an error occurs.
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterTransmitDataBlocking(I2c_Drv_IdType InstId)
{
    boolean TransmitFinished;
    I2c_Drv_MasterEventType  Event;
    I2c_Drv_MasterStateType *MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];
    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    TransmitFinished = I2c_Drv_MasterHandleEventBlocking(InstId);
    I2c_Drv_MasterEndTransfer(InstId);

    if (FALSE == TransmitFinished)
    {
        SchM_Enter_I2c_I2cConfig0Reg();
        /* Release the I2C bus after current byte transfer is finished. */
        I2Cx->I2C_CONFIG0.MASTER_ABORT = 1U;
        SchM_Exit_I2c_I2cConfig0Reg();
        MasterState->Status = I2C_DRV_TIMEOUT_STATUS;
        /* Completion of data buffer transfer is not done, a transfer error event is generated. */
        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_TRANSFER_ERROR);
    }
    else if (I2C_DRV_SUCCESS_STATUS == MasterState->Status)
    {
        Event = (TRUE == MasterState->SendStop) ? I2C_DRV_MASTER_EVENT_END_TRANSFER
                                                : I2C_DRV_MASTER_EVENT_RESTART_TRANSFER;
        I2c_Drv_MasterEvent(InstId, Event);
    }
    else
    {
        /* Do nothing, Other error events are notified as soon as they are detected. */
    }
}

/**
 * @brief      This function handles I2c master mode send data interrupts
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  IntStatus: Enabled interrupt status register value.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterSendHandler(I2c_Drv_IdType InstId, uint32 IntStatus)
{
    I2c_Drv_MasterStateType *MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Handle TX_EMPTY interrupt */
    if (0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_TX_EMPTY]))
    {
        /* No NACK check is required here, since it is handled as soon as NACK interrupt occurs. */
        if (MasterState->RemainingSize > 0U)
        {
            I2c_Drv_MasterSendByteEvent(InstId);
        }
        else /* 0U == MasterState->RemainingSize */
        {
            /* Leave error interrupts enabled to ensure NACK interrupt can be generated. */
            I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_TX_EMPTY, FALSE);
            if (FALSE == MasterState->SendStop)
            {
                MasterState->I2cIdle = TRUE;
                MasterState->Status = I2C_DRV_SUCCESS_STATUS;
                I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_RESTART_TRANSFER);
            }
            else
            {
                /* Do nothing, end transfer event is called at stop interrupt when sending stop */
            }
        }
    }
}

/**
 * @brief      This function handles I2c master mode receive data interrupts
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  IntStatus: Enabled interrupt status register value.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterReceiveHandler(I2c_Drv_IdType InstId, uint32 IntStatus)
{
    I2c_Drv_MasterStateType *MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Handle TX_EMPTY interrupt */
    if (0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_TX_EMPTY]))
    {
        if (MasterState->RemainingSize > 0U)
        {
            I2c_Drv_MasterReadCmdEvent(InstId);
        }
        else /* 0U == MasterState->RemainingSize */
        {
            I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_TX_EMPTY, FALSE);
        }
    }

    /* Handle RX_FULL interrupt */
    if (0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RX_FULL]))
    {
        /* No NACK check is required here, since received data has been stored in RxFIFO. */
        I2c_Drv_MasterReceiveByteEvent(InstId);
        /* Last byte has been received */
        if (MasterState->ReceivedSize >= MasterState->TotalBufferSize)
        {
            I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_RX_FULL, FALSE);
            if (FALSE == MasterState->SendStop)
            {
                MasterState->I2cIdle = TRUE;
                MasterState->Status = I2C_DRV_SUCCESS_STATUS;
                I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_RESTART_TRANSFER);
            }
            else
            {
                /* Do nothing, end transfer event is called at stop interrupt when sending stop */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
}

/**
 * @brief      This function handles I2c master mode interrupt
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return none
 *
 */
static void I2c_Drv_MasterIntHandler(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType *MasterState;
    Reg_I2c_WType           *I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    Reg_I2c_BfType          *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    uint32                   IntStatus;
    MasterState = &I2c_Drv_MasterState[InstId];

    /* Get status */
    IntStatus = I2CWx->I2C_STATUS0;
    /* Check enabled interrupt status */
    IntStatus &= I2CWx->I2C_INT_ENABLE;
    /* Clear the interrupt status */
    I2CWx->I2C_STATUS0 = IntStatus;
    /* Master Mode */

    /* Check the mode - receive or send */
    if (TRUE == MasterState->SendData)
    {
        I2c_Drv_MasterSendHandler(InstId, IntStatus);
    }
    else
    {
        I2c_Drv_MasterReceiveHandler(InstId, IntStatus);
    }

    /* Handle stuck at low interrupt */
    if ((IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_SCL_STUCK_AT_LOW]) != 0U)
    {
        if (0U == I2Cx->I2C_STATUS1.TXFIFO_EMPTY_MASTER_HOLD)
        {
            I2c_Drv_MasterEndTransfer(InstId);
            MasterState->Status = I2C_DRV_TIMEOUT_STATUS;
            /* SCL low timeout due to external pull-down of the bus or timing exception, I2C master
             * system reset is required. */
            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_STUCK_LOW_TIMEOUT);
        }
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
        else
        {
            /* SCL low timeout due to master hold bus, notify and continue transmission */
            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_HOLD_LOW_TIMEOUT);
        }
#endif /* STD_ON == I2C_DRV_DEV_ERROR_DETECT */
    }

    /* Handle error abort interrupt */
    if ((IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_ERROR_ABORT]) != 0U)
    {
        I2c_Drv_MasterEndTransfer(InstId);
        I2c_Drv_MasterHandleErrorAbortEvent(InstId);
    }

    /* Handle stop detect interrupt */
    if ((IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_STOP_DET]) != 0U)
    {
        if (I2C_DRV_BUSY_STATUS == MasterState->Status)
        {
            I2c_Drv_MasterEndTransfer(InstId);
            MasterState->Status = I2C_DRV_SUCCESS_STATUS;
            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_END_TRANSFER);
        }
        else
        {
            /* Do nothing, this case is handled in error abort interrupt */
        }
    }
}

/**
 * @brief      This function handles I2c slave mode send byte event
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_SlaveSendByteEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType *SlaveState;
    Reg_I2c_WType          *I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    SlaveState = &I2c_Drv_SlaveState[InstId];

    if (0U == SlaveState->RemainingSize)
    {
        SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
        /* Out of data, call callback to allow user to provide a new buffer */
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_TX_EMPTY);
        SlaveState->Status = I2C_DRV_BUSY_STATUS;
    }

    if (0U == SlaveState->RemainingSize)
    {
        /* Still no data, record tx underflow event and send dummy char. */
        SlaveState->Status = I2C_DRV_TX_UNDERRUN_STATUS;
        I2CWx->I2C_COMMAND_DATA = (uint32)SlaveState->PaddingData;
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_UNDERRUN);
#endif
    }
    else /* SlaveState->RemainingSize > 0U */
    {
        if (NULL_PTR != SlaveState->DataBuffer)
        {
            /* Send one byte */
            I2CWx->I2C_COMMAND_DATA = (uint32)SlaveState->DataBuffer[0];
            SlaveState->RemainingSize--;
            if (0U != SlaveState->RemainingSize)
            {
                SlaveState->DataBuffer++;
            }
            else
            {
                SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
            }
        }
    }
}

/**
 * @brief      This function handles I2c slave mode receive byte interrupt
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_SlaveReceiveByteEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType *SlaveState = &I2c_Drv_SlaveState[InstId];
    const Reg_I2c_WType    *I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    if (0U == SlaveState->RemainingSize)
    {
        SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
        /* No more room for data, call callback to allow user to provide a new buffer */
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_RX_FULL);
        SlaveState->Status = I2C_DRV_BUSY_STATUS;
    }

    if (0U == SlaveState->RemainingSize)
    {
        /* Still no room for data, record rx overrun event and dummy read data */
        SlaveState->Status = I2C_DRV_RX_OVERRUN_STATUS;
        (void)(I2CWx->I2C_COMMAND_DATA);
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_OVERRUN);
#endif
    }
    else /* SlaveState->RemainingSize > 0U */
    {
        if (NULL_PTR != SlaveState->DataBuffer)
        {
            SlaveState->DataBuffer[0U] = ((uint8)(I2CWx->I2C_COMMAND_DATA & 0xFFUL));
            SlaveState->RemainingSize--;
            if (0U != SlaveState->RemainingSize)
            {
                SlaveState->DataBuffer++;
            }
            else
            {
                SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
            }
        }
    }
}

/**
 * @brief      This function handles I2c slave mode interrupt
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_SlaveIntHandler(I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType *SlaveState;
    Reg_I2c_WType          *I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    uint32                  IntStatus;

    IntStatus = I2CWx->I2C_STATUS0;
    /* get status */
    IntStatus &= I2CWx->I2C_INT_ENABLE;
    /* Clear the interrupt status */
    I2CWx->I2C_STATUS0 = IntStatus;

    SlaveState = &I2c_Drv_SlaveState[InstId];

    if (0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_START_DET]))
    {
        /* Setup slave buffer will be abandoned in busy status after this status switch. */
        SlaveState->Status = I2C_DRV_BUSY_STATUS;
    }

    if (0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_STOP_DET]))
    {
        /* Report success if no error was recorded */
        SlaveState->Status = I2C_DRV_SUCCESS_STATUS;

        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_STOP);
    }

    if ((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RESTART_DET])))
    {
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_RESTART);
    }

    if ((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RX_FULL])))
    {
        I2c_Drv_SlaveReceiveByteEvent(InstId);
    }

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    if ((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RX_OVER])))
    {
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_OVERRUN);
    }
#endif

    if ((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RD_REQ])))
    {
        I2c_Drv_SlaveSendByteEvent(InstId);
    }
}

/**
 * @brief      Initialize I2c master configuration
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  MasterCfgPtr: Pointer to structure which contains driver master configuration data
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterInit(const I2c_Drv_IdType            InstId,
                               const I2c_Drv_MasterConfigType *MasterCfgPtr)
{
    I2c_Drv_MasterStateType *MasterState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(MasterCfgPtr != NULL_PTR);
#endif

    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Initialize driver status structure */
    MasterState->DataBuffer = NULL_PTR;
    MasterState->RemainingSize = 0U; /* 0 means no buffer */
    MasterState->ReceivedSize = 0U;
    MasterState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    MasterState->I2cIdle = TRUE;                  /* default state */
    MasterState->SlaveAddr = 0U;
    MasterState->AddrBitMode = FALSE;
    MasterState->SpeedMode = MasterCfgPtr->SpeedMode;

    MasterState->I2cCallback = MasterCfgPtr->I2cCallback;       /* I2c Callback */
    MasterState->I2cErrCallback = MasterCfgPtr->I2cErrCallback; /* ErrCallback */

    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;

    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_ALL, FALSE);
    I2c_Drv_ClearErrorStatusAll(InstId);
    I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);

    I2Cx->I2C_CONFIG1.SPEED_SEL = ((uint32)(MasterCfgPtr->SpeedMode)) & 0x3U;

    switch (MasterCfgPtr->SpeedMode)
    {
        case I2C_DRV_SPEED_STANDARD:
            I2Cx->I2C_STD_SCL_HCNT.STD_SCL_HCNT = (uint32)MasterCfgPtr->SclHighCount;
            I2Cx->I2C_STD_SCL_LCNT.STD_SCL_LCNT = (uint32)MasterCfgPtr->SclLowCount;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_FAST:
            I2Cx->I2C_FST_SCL_HCNT.FST_SCL_HCNT = (uint32)MasterCfgPtr->SclHighCount;
            I2Cx->I2C_FST_SCL_LCNT.FST_SCL_LCNT = (uint32)MasterCfgPtr->SclLowCount;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_HIGH:
            I2Cx->I2C_HS_SCL_HCNT.HS_SCL_HCNT = (uint32)MasterCfgPtr->SclHighCount;
            I2Cx->I2C_HS_SCL_LCNT.HS_SCL_LCNT = (uint32)MasterCfgPtr->SclLowCount;
            I2Cx->I2C_HS_SPKCNT.HS_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            I2Cx->I2C_CONFIG0.H_MCODE = (uint8)MasterCfgPtr->MCode;
            break;

        case I2C_DRV_SPEED_FAST_PLUS:
            I2Cx->I2C_FST_SCL_HCNT.FST_SCL_HCNT = (uint32)MasterCfgPtr->SclHighCount;
            I2Cx->I2C_FST_SCL_LCNT.FST_SCL_LCNT = (uint32)MasterCfgPtr->SclLowCount;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            break;

        default:
            /* Do nothing */
            break;
    }

    /* I2C bus stuck low detection feature in master mode */
    I2Cx->I2C_CONFIG0.MASTER_BUS_RECOVER_EN = 1U;
    /* I2C restart feature in master mode */
    I2Cx->I2C_CONFIG1.MASTER_RESTART_EN = 1U;
    /* When TXFIFO_EMPTY_EN = 0: TXFIFO_EMPTY bit is set when the FIFO count is at or below the
     * threshold value I2C_TXFIFO_WATER_MARK. */
    I2Cx->I2C_CONFIG1.TXFIFO_EMPTY_EN = 0U;

    I2Cx->I2C_SCL_LOW_TIMEOUT.SCL_LOW_TIMEOUT = (uint32)MasterCfgPtr->SclLowTimeout;
    I2Cx->I2C_SDA_LOW_TIMEOUT.SDA_LOW_TIMEOUT = (uint32)MasterCfgPtr->SdaLowTimeout;

    I2Cx->I2C_SDA_HOLD_TIMING.SDA_RX_HOLD_TIMING =
        MasterCfgPtr->I2cSdaHoldTiming.SdaReceiveHoldTime;
    I2Cx->I2C_SDA_HOLD_TIMING.SDA_TX_HOLD_TIMING =
        MasterCfgPtr->I2cSdaHoldTiming.SdaTransmitHoldTime;

    /* Set Receive FIFO threshold level. Once RXFIFO entries number reaches or exceeds
     * (RXFIFO_WATER_MARK+1), I2C will assert RXFIFO full flag. */
    I2Cx->I2C_RXFIFO_WATER_MARK.RXFIFO_WATER_MARK = 0U;
    /* Set Transmit FIFO threshold level. Once TXFIFO entries number reaches or falls below
     * TXFIFO_WATER_MARK, I2C will assert TXFIFO empty flag. */
    I2Cx->I2C_TXFIFO_WATER_MARK.TXFIFO_WATER_MARK = 0U;

    /* Disable slave */
    I2Cx->I2C_CONFIG1.SLAVE_MODE_DIS = 1U;
    /* Enable master */
    I2Cx->I2C_CONFIG1.MASTER_MODE_EN = 1U;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Initialize I2c slave configuration
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  SlaveCfgPtr: Pointer to structure which contains driver slave configuration data
 *
 * @return     None
 *
 */
static void I2c_Drv_SlaveInit(const I2c_Drv_IdType           InstId,
                              const I2c_Drv_SlaveConfigType *SlaveCfgPtr)
{
    I2c_Drv_SlaveStateType *SlaveState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(SlaveCfgPtr != NULL_PTR);
#endif
    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    SlaveState = &I2c_Drv_SlaveState[InstId];

    /* Initialize driver status structure */
    SlaveState->DataBuffer = NULL_PTR;
    SlaveState->RemainingSize = 0U;              /* 0 means no buffer */
    SlaveState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    SlaveState->AddrBitMode = SlaveCfgPtr->AddrBitMode;
    SlaveState->SlaveAddr = SlaveCfgPtr->SlaveAddr;
    SlaveState->SpeedMode = SlaveCfgPtr->SpeedMode;
    SlaveState->PaddingData = SlaveCfgPtr->PaddingData;
    SlaveState->I2cCallback = SlaveCfgPtr->I2cCallback;       /* I2c Callback */
    SlaveState->I2cErrCallback = SlaveCfgPtr->I2cErrCallback; /* ErrCallback */

    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;

    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_ALL, FALSE);
    I2c_Drv_ClearErrorStatusAll(InstId);
    I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);

    I2Cx->I2C_CONFIG1.SPEED_SEL = ((uint32)(SlaveCfgPtr->SpeedMode)) & 0x3U;

    switch (SlaveCfgPtr->SpeedMode)
    {
        case I2C_DRV_SPEED_STANDARD:
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)SlaveCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_FAST:
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)SlaveCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_HIGH:
            I2Cx->I2C_HS_SPKCNT.HS_SPKLEN = (uint32)SlaveCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_FAST_PLUS:
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)SlaveCfgPtr->SpikeSuppressionLimit;
            break;

        default:
            /* Do nothing */
            break;
    }

    I2Cx->I2C_SDA_HOLD_TIMING.SDA_RX_HOLD_TIMING =
        (uint32)SlaveCfgPtr->I2cSdaHoldTiming.SdaReceiveHoldTime;
    I2Cx->I2C_SDA_HOLD_TIMING.SDA_TX_HOLD_TIMING =
        (uint32)SlaveCfgPtr->I2cSdaHoldTiming.SdaTransmitHoldTime;

    I2Cx->I2C_SDA_SETUP_TIMING.SDA_SETUP_TIMING = (uint8)SlaveCfgPtr->SdaSetupTime;

    /* Set the slave own address */
    I2Cx->I2C_SLAVE_ADDR.SLV_ADDR = (uint32)SlaveState->SlaveAddr;
    /* Set the slave address bit mode */
    I2Cx->I2C_CONFIG1.SLAVE_10BIT_ADDR_SEL = (uint32)SlaveState->AddrBitMode;

    /* Set Receive FIFO threshold level. Once RXFIFO entries number reaches or exceeds
     * (RXFIFO_WATER_MARK+1), I2C will assert RXFIFO full flag. */
    I2Cx->I2C_RXFIFO_WATER_MARK.RXFIFO_WATER_MARK = 0U;
    /* Set Transmit FIFO threshold level. Once TXFIFO entries number reaches or falls below
     * TXFIFO_WATER_MARK, I2C will assert TXFIFO empty flag. */
    I2Cx->I2C_TXFIFO_WATER_MARK.TXFIFO_WATER_MARK = 0U;
    /* It allows generating STOP_DETECT interrupt flag only when the slave address matches. */
    I2Cx->I2C_CONFIG1.SLAVE_STOP_DET_EN = 1U;

    /* Enable slave */
    I2Cx->I2C_CONFIG1.SLAVE_MODE_DIS = 0U;
    /* Disable master */
    I2Cx->I2C_CONFIG1.MASTER_MODE_EN = 0U;

    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_RX_FULL, TRUE);
    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_RD_REQ, TRUE);
    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_START_DET, TRUE);
    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_RESTART_DET, TRUE);
    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_STOP_DET, TRUE);
    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_RX_OVER, TRUE);

    /* Enable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 1U;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      de-Initialize I2c Master configuration
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_MasterDeInit(const I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType *MasterState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
#endif

    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    MasterState = &I2c_Drv_MasterState[InstId];

    /* Disable all interrupts to avoid more interrupts during deinitialization */
    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_ALL, FALSE);

    /* Generate STOP condition and release I2C bus after current byte transmission */
    I2Cx->I2C_CONFIG0.MASTER_ABORT = 1U;

    I2c_Drv_ClearErrorStatusAll(InstId);
    I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);

    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;

    /* De-Initialize driver status structure */
    MasterState->DataBuffer = NULL_PTR;
    MasterState->RemainingSize = 0U; /* 0 means no buffer */
    MasterState->ReceivedSize = 0U;
    MasterState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    MasterState->I2cIdle = TRUE;                  /* default state */
    MasterState->SlaveAddr = 0U;
    MasterState->AddrBitMode = FALSE;
    MasterState->SpeedMode = I2C_DRV_SPEED_STANDARD;

    MasterState->I2cCallback = NULL_PTR;    /* I2c Callback */
    MasterState->I2cErrCallback = NULL_PTR; /* ErrCallback */

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      de-Initialize I2c slave configuration
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     None
 *
 */
static void I2c_Drv_SlaveDeInit(const I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType *SlaveState;
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
#endif
    SlaveState = &I2c_Drv_SlaveState[InstId];
    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_ALL, FALSE);
    I2c_Drv_ClearErrorStatusAll(InstId);
    I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);

    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;

    SlaveState->DataBuffer = NULL_PTR;
    SlaveState->RemainingSize = 0U;              /* 0 means no buffer */
    SlaveState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    SlaveState->AddrBitMode = FALSE;
    SlaveState->SlaveAddr = 0U;
    SlaveState->SpeedMode = I2C_DRV_SPEED_STANDARD;
    SlaveState->I2cCallback = NULL_PTR;    /* I2c Callback */
    SlaveState->I2cErrCallback = NULL_PTR; /* ErrCallback */

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief      Set transmit request configurations.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  RequestParam: Pointer to structure for request parameters.
 *
 * @return     None
 *
 */
void I2c_Drv_SetRequestConfig(const I2c_Drv_IdType InstId, I2c_Drv_RequestType *RequestParam)
{
    I2c_Drv_MasterStateType *MasterState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(RequestParam != NULL_PTR);
    MCALLIB_DEV_ASSERT(RequestParam->TargetAddr <= I2C_DRV_MAX_ADDR);
    MCALLIB_DEV_ASSERT(RequestParam->BufferPtr != NULL_PTR);
    MCALLIB_DEV_ASSERT(RequestParam->BufferSize > 0U);
#endif

    /* Copy parameters to driver state structure */
    MasterState = &I2c_Drv_MasterState[InstId];
    MasterState->SlaveAddr = RequestParam->TargetAddr;
    MasterState->AddrBitMode = RequestParam->AddrBitMode;
    MasterState->DataBuffer = RequestParam->BufferPtr;
    MasterState->RemainingSize = RequestParam->BufferSize;
    MasterState->TotalBufferSize = RequestParam->BufferSize;
    MasterState->SendData = RequestParam->SendData;
    MasterState->SendStop = RequestParam->SendStop;
    MasterState->ReceivedSize = 0U;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer to structure which contains driver configuration data
 *
 * @return     None
 *
 */
void I2c_Drv_Init(const I2c_Drv_IdType InstId, const I2c_Drv_PhyUnitConfigType *I2cPhyUnitCfgPtr)
{
    if (I2C_DRV_MASTER_MODE == I2cPhyUnitCfgPtr->MasterSlaveMode)
    {
        I2c_Drv_MasterInit(InstId, I2cPhyUnitCfgPtr->MasterCfgPtr);
    }
    else
    {
        I2c_Drv_SlaveInit(InstId, I2cPhyUnitCfgPtr->SlaveCfgPtr);
    }
}

/**
 * @brief      De-Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer to structure which contains driver configuration data
 *
 * @return     None
 *
 */
void I2c_Drv_DeInit(const I2c_Drv_IdType InstId, const I2c_Drv_PhyUnitConfigType *I2cPhyUnitCfgPtr)
{
    if (I2C_DRV_MASTER_MODE == I2cPhyUnitCfgPtr->MasterSlaveMode)
    {
        I2c_Drv_MasterDeInit(InstId);
    }
    else
    {
        I2c_Drv_SlaveDeInit(InstId);
    }
}

/**
 * @brief      This function send or receive data.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  Blocking: Select blocking or non-blocking method
 *             - TRUE: Blocking method, used for sync transmit
 *             - FALSE: Non-blocking method, used for async transmit
 *
 * @return     I2c_Drv_StatusType
 * @retval     I2C_DRV_SUCCESS_STATUS  Success
 * @retval     I2C_DRV_ERROR_STATUS    Error
 * @retval     I2C_DRV_BUSY_STATUS     Busy
 *
 */
I2c_Drv_StatusType I2c_Drv_MasterTransmitData(const I2c_Drv_IdType InstId, boolean Blocking)
{
    I2c_Drv_MasterStateType *MasterState;
    I2c_Drv_StatusType       ReturnStatus = I2C_DRV_SUCCESS_STATUS;
    Reg_I2c_BfType          *I2Cx;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
#endif
    MasterState = &I2c_Drv_MasterState[InstId];
    I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    /* SDA_ERR_RECOVER_STUCK_LOW flag bit will not reset when I2C module is disabled, and once
           this bit is set, I2C master system reset is required. */
    if (1U == I2Cx->I2C_STATUS1.SDA_ERR_RECOVER_STUCK_LOW)
    {
        MasterState->Status = I2C_DRV_ERROR_STATUS;
        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_STUCK_LOW_TIMEOUT);
        ReturnStatus = I2C_DRV_ERROR_STATUS;
    }
    else
    {
        /* Check if driver is busy */
        if (FALSE == MasterState->I2cIdle)
        {
            ReturnStatus = I2C_DRV_BUSY_STATUS;
        }
        else
        {
            MasterState->I2cIdle = FALSE;
            MasterState->Status = I2C_DRV_BUSY_STATUS;

            /* Set target slave address and address bit mode and enable I2c instance */
            I2c_Drv_SetMasterGlobalConfig(InstId);

            if (TRUE == Blocking)
            {
                /* Start data transmission blocking */
                I2c_Drv_MasterTransmitDataBlocking(InstId);

                ReturnStatus = MasterState->Status;
            }
            else
            {
                I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_STOP_DET, TRUE);
                I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_SCL_STUCK_AT_LOW, TRUE);
                I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_ERROR_ABORT, TRUE);
                if (FALSE == MasterState->SendData)
                {
                    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_RX_FULL, TRUE);
                }
                I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_TX_EMPTY, TRUE);
            }
        }
    }
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return ReturnStatus;
}

/**
 * @brief      This function sets slave receive or send data.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  TxBuffer: Pointer to the buffer-array
 * @param[in]  TxSize: Size of the external buffer
 *
 * @return     None
 *
 */
void I2c_Drv_SetupSlaveBuffer(const I2c_Drv_IdType InstId, uint8 *TxBuff, uint32 TxSize)
{
    I2c_Drv_SlaveStateType *SlaveState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(TxBuff != NULL_PTR);
    MCALLIB_DEV_ASSERT(TxSize > 0U);
#endif

    SlaveState = &I2c_Drv_SlaveState[InstId];

    SlaveState->DataBuffer = TxBuff;
    SlaveState->RemainingSize = TxSize;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Return the current status
 *
 * @param[in]  InstId: Select the I2C instance id.
 *
 * @return     I2c_Drv_StatusType: current status
 * @retval     I2C_DRV_SUCCESS_STATUS
 * @retval     I2C_DRV_ERROR_STATUS
 * @retval     I2C_DRV_BUSY_STATUS
 * @retval     I2C_DRV_TIMEOUT_STATUS
 * @retval     I2C_DRV_RECEIVED_NACK_STATUS
 * @retval     I2C_DRV_TX_UNDERRUN_STATUS
 * @retval     I2C_DRV_RX_OVERRUN_STATUS
 */
I2c_Drv_StatusType I2c_Drv_GetStatus(const I2c_Drv_IdType InstId)
{
    const I2c_Drv_MasterStateType *MasterState;
    const I2c_Drv_SlaveStateType  *SlaveState;
    const Reg_I2c_BfType          *I2Cx;
    I2c_Drv_StatusType             PhyStatus = I2C_DRV_ERROR_STATUS;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
#endif
    I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    if (1U == I2Cx->I2C_CONFIG1.MASTER_MODE_EN)
    {
        /* master mode */
        MasterState = &I2c_Drv_MasterState[InstId];
        PhyStatus = MasterState->Status;
    }
    else
    {
        /* slave mode */
        SlaveState = &I2c_Drv_SlaveState[InstId];
        PhyStatus = SlaveState->Status;
    }

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return PhyStatus;
}

/**
 * @brief      This function handles I2c interrupt
 *
 * @param[in]  InstId: The I2C instance id.
 *
 * @return     None
 *
 */
void I2c_Drv_ChIntHandler(I2c_Drv_IdType InstId)
{
    const Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    /* Check if is master or slave module */
    if (0U == I2Cx->I2C_CONFIG1.MASTER_MODE_EN)
    {
        I2c_Drv_SlaveIntHandler(InstId);
    }
    else
    {
        I2c_Drv_MasterIntHandler(InstId);
    }
}

/**
 * @brief      This function set SCL stuck at low timeout value.
 *             This function will disable I2C module first and may disrupt ongoing transmissions.
 *             Therefore, it is recommended to call this function when I2C status is idle.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  TimeoutValue: SCL stuck at low timeout value.
 *             I2C module generates the SCL_STUCK_AT_LOW interrupt to indicate SCL stuck at low if
 *             it detects the SCL stuck at low for the I2C_SCL_LOW_TIMEOUT in units of I2C function
 *             clock period.
 *
 * @return     None
 *
 */
void I2C_Drv_SetSclHoldLowTimeout(I2c_Drv_IdType InstId, uint32 TimeoutValue)
{
    boolean         IsModuleEnabled;
    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    Reg_I2c_WType  *I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    SchM_Enter_I2c_I2cConfig0Reg();
    IsModuleEnabled = (1U == I2Cx->I2C_CONFIG0.MODULE_EN) ? TRUE : FALSE;

    /* Disable the I2C first if enabled. */
    if (TRUE == IsModuleEnabled)
    {
        I2Cx->I2C_CONFIG0.MODULE_EN = 0U;
    }
    I2CWx->I2C_SCL_LOW_TIMEOUT = TimeoutValue;

    /* Recover to original module enable configuration. */
    if (TRUE == IsModuleEnabled)
    {
        I2Cx->I2C_CONFIG0.MODULE_EN = 1U;
    }
    SchM_Exit_I2c_I2cConfig0Reg();
}

/**
 * @brief      This function set SDA stuck at low timeout value.
 *             This function will disable I2C module first and may disrupt ongoing transmissions.
 *             Therefore, it is recommended to call this function when I2C status is idle.
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  TimeoutValue: SDA stuck at low timeout value.
 *             I2C module initiates the recovery of SDA line through enabling the SDA_RECOVER_EN bit
 *             if it detects the SDA stuck at low for the I2C_SDA_LOW_TIMEOUT in units of I2C
 *             function clock period.
 *
 * @return     None
 *
 */
void I2C_Drv_SetSdaHoldLowTimeout(I2c_Drv_IdType InstId, uint32 TimeoutValue)
{
    boolean         IsModuleEnabled;
    Reg_I2c_BfType *I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    Reg_I2c_WType  *I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    SchM_Enter_I2c_I2cConfig0Reg();
    IsModuleEnabled = (1U == I2Cx->I2C_CONFIG0.MODULE_EN) ? TRUE : FALSE;

    /* Disable the I2C first if enabled. */
    if (TRUE == IsModuleEnabled)
    {
        I2Cx->I2C_CONFIG0.MODULE_EN = 0U;
    }
    I2CWx->I2C_SDA_LOW_TIMEOUT = TimeoutValue;

    /* Recover to original module enable configuration. */
    if (TRUE == IsModuleEnabled)
    {
        I2Cx->I2C_CONFIG0.MODULE_EN = 1U;
    }
    SchM_Exit_I2c_I2cConfig0Reg();
}

/**
 * @brief      Check whether interrupt status flag is set or not for given interrupt type
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  IntType:  Specified interrupt type.
 *             - I2C_DRV_INT_GEN_CALL
 *             - I2C_DRV_INT_TX_OVER
 *             - I2C_DRV_INT_ERROR_ABORT
 *             - I2C_DRV_INT_ACTIVITY
 *             - I2C_DRV_INT_STOP_DET
 *             - I2C_DRV_INT_START_DET
 *             - I2C_DRV_INT_RD_REQ
 *             - I2C_DRV_INT_RX_DONE
 *             - I2C_DRV_INT_RX_UNDER
 *             - I2C_DRV_INT_RX_OVER
 *             - I2C_DRV_INT_RESTART_DET
 *             - I2C_DRV_SCL_STUCK_AT_LOW
 *             - I2C_DRV_INT_RX_FULL
 *             - I2C_DRV_INT_TX_EMPTY
 *
 * @return     boolean: The status flag of interrupt status register.
 * @retval     TRUE: Specified interrupt status flag is set.
 * @retval     FALSE: Specified interrupt status flag is reset.
 *
 */
boolean I2c_Drv_GetIntStatus(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType)
{
    boolean              IntStatus = FALSE;
    const Reg_I2c_WType *I2CWx;
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT((uint32)InstId < I2C_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT((uint32)IntType < (uint32)I2C_DRV_INT_ALL);
#endif
    I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    IntStatus = (0U != (I2CWx->I2C_STATUS0 & I2c_Drv_IntEnableTable[IntType])) ? TRUE : FALSE;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return IntStatus;
}

/**
 * @brief      Check whether status flag is set or not for given status type
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  ConfigStatusType:  Specified status type.
 *             - I2C_DRV_MST_ACTIVITY
 *             - I2C_DRV_SLV_ACTIVITY
 *             - I2C_DRV_TXFIFO_EMPTY_MASTER_HOLD
 *             - I2C_DRV_TXFIFO_EMPTY_SLAVE_HOLD
 *             - I2C_DRV_RXFIFO_FULL_MASTER_HOLD
 *             - I2C_DRV_RXFIFO_FULL_SLAVE_HOLD
 *             - I2C_DRV_STATUS_TFNF
 *             - I2C_DRV_STATUS_TFE
 *             - I2C_DRV_STATUS_RFNE
 *             - I2C_DRV_STATUS_RFF
 *             - I2C_DRV_SDA_ERR_RECOVER_STUCK_LOW
 *             - I2C_DRV_SLAVE_IS_DISABLED_UNDER_ACT
 *             - I2C_DRV_SLAVE_RX_DATA_DISCARD
 *             - I2C_DRV_ENABLE
 *
 * @return     boolean: The status flag of I2C status register.
 * @retval     TRUE: Specified status flag is set.
 * @retval     FALSE: Specified status flag is reset.
 *
 */
boolean I2c_Drv_GetCurrentStatus(I2c_Drv_IdType InstId, I2c_Drv_ConfigStatusType ConfigStatusType)
{
    const Reg_I2c_WType *I2CWx;
    I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    return (0U != ((I2CWx->I2C_STATUS1) & (0x01UL << (uint32)ConfigStatusType))) ? TRUE : FALSE;
}

/**
 * @brief      Check whether error status flag is set or not
 *
 * @param[in]  InstId: Select the I2C instance id.
 * @param[in]  ErrorType:  Specified abort type.
 *             - I2C_DRV_ERR_GEN_CALL_NO_ACK
 *             - I2C_DRV_ERR_GEN_CALL_READ
 *             - I2C_DRV_ERR_START_BYTE_ACK_DET
 *             - I2C_DRV_ERR_SBYTE_NORSTRT
 *             - I2C_DRV_ERR_H_NO_RSTRT
 *             - I2C_DRV_ERR_H_MCODE_ACK_DET
 *             - I2C_DRV_ERR_7BIT_ADDR_NO_ACK
 *             - I2C_DRV_ERR_10BIT_ADDR1_NO_ACK
 *             - I2C_DRV_ERR_10BIT_ADDR2_NO_ACK
 *             - I2C_DRV_ERR_10BIT_READ_NO_RSTRT
 *             - I2C_DRV_ERR_DATA_NO_ACK
 *             - I2C_DRV_ERR_MASTER_LOST
 *             - I2C_DRV_ERR_MASTER_DIS
 *             - I2C_DRV_ERR_SLAVE_ARBLOST
 *             - I2C_DRV_ERR_MASTER_ABRT
 *             - I2C_DRV_ERR_SLAVE_READ_REQ
 *             - I2C_DRV_ERR_SLAVE_FLUSH_TXFIFO
 *             - I2C_DRV_ERR_SDA_LOW_TIMEOUT
 *
 * @return     boolean: The status flag of error status register.
 * @retval     TRUE: Specified error status flag is set.
 * @retval     FALSE: Specified error status flag is reset.
 *
 */
boolean I2c_Drv_GetErrorStatus(I2c_Drv_IdType InstId, I2c_Drv_ErrorStatusType ErrorType)
{
    const Reg_I2c_WType *I2CWx;
    I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    return (0U != ((I2CWx->I2C_ERROR_STATUS) & (0x01UL << (uint32)ErrorType))) ? TRUE : FALSE;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c_Drv */
/** @} end of group I2c_Module */
