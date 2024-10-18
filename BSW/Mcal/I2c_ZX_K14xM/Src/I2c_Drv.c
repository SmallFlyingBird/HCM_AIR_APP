/**************************************************************************************************/
/**
 * @file      : I2c_Drv.c
 * @brief     : AUTOSAR I2c hardware driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  I2c_Module
 *  @{
 */

/** @addtogroup  I2c_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
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
#define I2C_DRV_C_SW_PATCH_VERSION            1U

#if (I2C_DRV_C_VENDOR_ID != I2C_DRV_H_VENDOR_ID)
    #error "Vendor ID I2c_Drv.c and I2c_Drv.h have different"
#endif

#if ((I2C_DRV_C_AR_RELEASE_MAJOR_VERSION != I2C_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (I2C_DRV_C_AR_RELEASE_MINOR_VERSION != I2C_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of I2c_Drv.c and I2c_Drv.h are different"
#endif

#if ((I2C_DRV_C_SW_MAJOR_VERSION != I2C_DRV_H_SW_MAJOR_VERSION) || \
        (I2C_DRV_C_SW_MINOR_VERSION != I2C_DRV_H_SW_MINOR_VERSION))
    #error "Software version of I2c_Drv.c and I2c_Drv.h are different"
#endif

#if ((I2C_DRV_C_AR_RELEASE_REVISION_VERSION != I2C_DRV_H_AR_RELEASE_REVISION_VERSION) || \
        (I2C_DRV_C_SW_PATCH_VERSION != I2C_DRV_H_SW_PATCH_VERSION))
    #error "Software version of I2c_Drv.c and I2c_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((I2C_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||     \
         (I2C_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of I2c_Drv.c and Device_Regs.h are different"
    #endif

    #if ((I2C_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_I2C_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (I2C_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_I2C_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of I2c_Drv.c and SchM_I2c.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

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
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_I2c_BfType *const I2c_Drv_I2cRegBfPtr[I2C_DRV_INSTANCE_SUMCNT] = 
{
   (Reg_I2c_BfType *)I2C0_BASE_ADDR
#if(I2C_DRV_INSTANCE_SUMCNT == 2U) 
   ,(Reg_I2c_BfType *)I2C1_BASE_ADDR
#endif
};

/**
 *  @brief I2C0, I2C1 address array
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_I2c_WType *const I2c_Drv_I2cRegWPtr[I2C_DRV_INSTANCE_SUMCNT] = 
{
   (Reg_I2c_WType *)I2C0_BASE_ADDR 
#if(I2C_DRV_INSTANCE_SUMCNT == 2U) 
   ,(Reg_I2c_WType *)I2C1_BASE_ADDR
#endif
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

static I2c_Drv_MasterStateType I2c_Drv_MasterState[I2C_DRV_INSTANCE_SUMCNT];
static I2c_Drv_SlaveStateType  I2c_Drv_SlaveState[I2C_DRV_INSTANCE_SUMCNT];

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

static const uint32 I2c_Drv_IntEnableTable[]=
{
    0x00000001U,               /*!< I2C_DRV_INT_GEN_CALL */
    0x00000002U,               /*!< I2C_DRV_INT_TX_OVER */
    0x00000004U,               /*!< I2C_DRV_INT_ERROR_ABORT */
    0x00000008U,               /*!< I2C_DRV_INT_ACTIVITY */
    0x00000010U,               /*!< I2C_DRV_INT_STOP_DET */
    0x00000020U,               /*!< I2C_DRV_INT_START_DET */
    0x00400000U,               /*!< I2C_DRV_INT_RD_REQ */
    0x00800000U,               /*!< I2C_DRV_INT_RX_DONE */
    0x01000000U,               /*!< I2C_DRV_INT_RX_UNDER */
    0x02000000U,               /*!< I2C_DRV_INT_RX_OVER */
    0x04000000U,               /*!< I2C_DRV_INT_RESTART_DET */
    0x08000000U,               /*!< I2C_DRV_SCL_STUCK_AT_LOW */
    0x40000000U,               /*!< I2C_DRV_INT_RX_FULL */
    0x80000000U,               /*!< I2C_DRV_INT_TX_EMPTY */
    0xCFC0003FU                /*!< I2C_DRV_INT_ALL */
};

/**
 *  @brief I2C interrupt array
 */
static const uint32 I2c_Drv_IntTable[]=
{
    0U,1U,2U,3U,4U,5U,22U,23U,24U,25U,26U,27U,30U,31U
};

#define I2C_STOP_SEC_CONST_32
#include "I2c_MemMap.h"

/** @} end of group Private_ConstDefinition */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

static void I2c_Drv_SlaveEvent(I2c_Drv_IdType InstId, I2c_Drv_SlaveEventType Event)
{
    const I2c_Drv_SlaveStateType * SlaveState;

    SlaveState = &I2c_Drv_SlaveState[InstId];

    if((I2C_DRV_SLAVE_EVENT_UNDERRUN == Event) || (I2C_DRV_SLAVE_EVENT_OVERRUN == Event) ||
                                                 (I2C_DRV_SLAVE_EVENT_DMA_TRANSFER_ERROR == Event))
    {
        if(NULL_PTR != SlaveState->I2cErrCallback)
        {   
            SlaveState->I2cErrCallback((uint8)Event, (uint8)InstId);
        }
    }
    else /* No error Event has occurred */
    {
        if(NULL_PTR != SlaveState->I2cCallback)
        {   
            SlaveState->I2cCallback((uint8)Event, (uint8)InstId);
        }
    }
}

static void I2c_Drv_MasterEvent(I2c_Drv_IdType InstId, I2c_Drv_MasterEventType Event)
{
    const I2c_Drv_MasterStateType * MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    if((I2C_DRV_MASTER_EVENT_NACK == Event) || (I2C_DRV_MASTER_EVENT_TRANSFER_ERROR == Event) ||
                                             (I2C_DRV_MASTER_EVENT_DMA_TRANSFER_ERROR == Event))
    {

        if(NULL_PTR != MasterState->I2cErrCallback)
        {   
            MasterState->I2cErrCallback((uint8)Event, (uint8)InstId);
        }
    }
    else /* No error Event has occurred */
    {
        if(NULL_PTR != MasterState->I2cCallback)
        {   
            MasterState->I2cCallback((uint8)Event, (uint8)InstId);
        }
    }
}

LOCAL_INLINE void I2c_Drv_SetModuleModSelect(I2c_Drv_IdType InstId, I2c_Drv_ModeType ModuleType)
{
    const I2c_Drv_MasterStateType * MasterState;
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    
    MasterState = &I2c_Drv_MasterState[InstId];

    if(I2C_DRV_MASTER_MODE == ModuleType)
    {
        /* Disable slave */
        I2Cx->I2C_CONFIG1.SLAVE_MODE_DIS = 1U;
        /* Enable master */
        I2Cx->I2C_CONFIG1.MASTER_MODE_EN = 1U;
    }
    else
    {
        /* Enable slave */
        I2Cx->I2C_CONFIG1.SLAVE_MODE_DIS = 0U;
        /* Disable master */
        I2Cx->I2C_CONFIG1.MASTER_MODE_EN = 0U;
    }

    I2Cx->I2C_CONFIG1.MASTER_RESTART_EN = ((FALSE == MasterState->SendStop)? 1UL : 0UL);
}

/**
 * @brief      Check whether status flag is set or not for given status type
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  ConfigSStatusType:  Specified status type.
 *             - I2C_DRV_MST_ACTIVITY
 *             - I2C_DRV_SLV_ACTIVITY
 *             - I2C_DRV_TXFIFO_EMPTY_MASTER_HOLD
 *             - I2C_DRV_TXFIFO_EMPTY_SLAVE_HOLD
 *             - I2C_DRV_RXFIFO_FULL_MASTER_HOLD
 *             - I2C_DRV_RXFIFO_FULL_SLAVE_HOLD
 *             - I2C_DRV_STATUS_TFNF
 *             - I2C_DRV_STATUS_TFE,
 *             - I2C_DRV_STATUS_RFNE,
 *             - I2C_DRV_STATUS_RFF,
 *             - I2C_DRV_SDA_ERR_RECOVER_STUCK_LOW,
 *             - I2C_DRV_SLAVE_IS_DISABLED_UNDER_ACT
 *             - I2C_DRV_SLAVE_RX_DATA_DISCARD
 *             - I2C_DRV_ENABLE
 *
 * @return     The status flag of spi status register.
 *             - SET
 *             - RESET
 *
 */
static boolean I2c_Drv_GetCurrentStatus(I2c_Drv_IdType InstId, I2c_Drv_ConfigStatusType ConfigStatusType)
{
    uint32 BitStatus;
    const Reg_I2c_WType * I2CWx;

    I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    BitStatus = (((I2CWx->I2C_STATUS1) &
                     (0x01UL << (uint32)ConfigStatusType)) >> (uint32)ConfigStatusType);
    return (BitStatus == 1U) ? TRUE:FALSE;
}

/**
 * @brief      Check whether error status flag is set or not
 *
 * @param[in]  InstId: Select the I2C port.
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
 *             - I2C_DRV_ERR_MASTER_ABRT
 *             - I2C_DRV_ERR_MASTER_DIS
 *             - I2C_DRV_ERR_SLAVE_ARBLOST
 *             - I2C_DRV_ERR_MASTER_LOST
 *             - I2C_DRV_ERR_SLAVE_READ_REQ
 *             - I2C_DRV_ERR_SLAVE_FLUSH_TXFIFO
 *             - I2C_DRV_ERR_SDA_LOW_TIMEOUT
 *
 * @return     The status flag of error status register.
 *             - SET
 *             - RESET
 *
 */
static boolean I2c_Drv_GetErrorStatus(I2c_Drv_IdType InstId, I2c_Drv_ErrorStatusType ErrorType)
{
    uint32 bitStatus;
    const Reg_I2c_WType * I2CWx;

    I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    bitStatus = (((I2CWx->I2C_ERROR_STATUS) &
                        (0x01UL <<(uint32)ErrorType)) >> (uint32)ErrorType);
    return (bitStatus == 1U) ? TRUE:FALSE;
}

/**
 * @brief      Check whether interrupt status flag is set or not for given
 *             interrupt type
 *
 * @param[in]  InstId: Select the I2C port.
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
 * @return     The status flag of interrupt status register.
 *             - SET
 *             - RESET
 *
 */
static boolean I2c_Drv_GetIntStatus(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType)
{
    uint32 IntBitStatus;
    const Reg_I2c_WType * I2CWx;

    I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    IntBitStatus = (((I2CWx->I2C_STATUS0) &
                    (0x01UL << (uint32)I2c_Drv_IntTable[IntType])) >>
                    (uint32)I2c_Drv_IntTable[IntType]);

    return (IntBitStatus == 1U) ? TRUE:FALSE;
}

/**
 * @brief      Clear specified interrupt type
 *
 * @param[in]  InstId: Select the I2C port.
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
 *
 * @return none
 *
 */
static void I2c_Drv_ClearInt(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType)
{
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
#endif

    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    I2CWx->I2C_STATUS0 = I2c_Drv_IntEnableTable[IntType];

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Enable/Disable specified interrupt type
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  IntType:  Specified interrupt type.
 * @param[in]  IntMask:  Interrupt enable/disable type.
 *
 * @return  none
 *
 */
static void I2c_Drv_SetInterrupt(I2c_Drv_IdType InstId, I2c_Drv_IntType IntType, boolean IntMask)
{

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
#endif

    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    if(FALSE == IntMask )
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
 * @brief      Master end transfer.
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return     none
 *
 */
static void I2c_Drv_MasterEndTransfer(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_ALL, FALSE);

    MasterState->DataBuffer = NULL_PTR;
    MasterState->BufferSize = 0U;
    MasterState->I2cIdle = TRUE;
}

/**
 * @brief      Send one byte when i2c as a master.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  RestartStopType: Specified restart,Stop type.
 *             - I2C_DRV_RESTART_AND_STOP_DISABLE
 *             - I2C_DRV_STOP_EN
 *             - I2C_DRV_RESTART_EN
 *
 * @return     none
 *
 */
static void I2c_Drv_MasterSendByte(I2c_Drv_IdType InstId, I2c_Drv_RestartStopType RestartStopType)
{
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    I2c_Drv_MasterStateType * MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];
    
    if((FALSE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_DATA_NO_ACK)))
    {    /* Send one byte */
        I2CWx->I2C_COMMAND_DATA = ((uint32)(RestartStopType) << 0x9UL) |
            (((uint32)MasterState->DataBuffer[0]));

        MasterState->BufferSize--;

        if(0U != MasterState->BufferSize)
        {
            MasterState->DataBuffer++;
        }
    }
}

/**
 * @brief      Receive data from slave and store it when i2c as a master.
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return     none
 *
 */
static void I2c_Drv_MasterReceiveByte(I2c_Drv_IdType InstId)
{
    const Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    I2c_Drv_MasterStateType * MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];
    
    /* Read one byte */
    MasterState->DataBuffer[0U] = ((uint8)(I2CWx->I2C_COMMAND_DATA & 0xFFUL));

    MasterState->BufferSize--;
    if(0U != MasterState->BufferSize)
    {
        MasterState->DataBuffer++;
    }
}

/**
 * @brief      the I2c slave receive data.
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return     none
 *
 */
static uint8 I2c_Drv_ReceiveByte(I2c_Drv_IdType InstId)
{
    const Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    /* Read one byte */
    return ((uint8)(I2CWx->I2C_COMMAND_DATA & 0xFFUL));
}

/**
 * @brief      the master generate stop event.
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return     none
 *
 */
static void I2c_Drv_MasterGenerateStopEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

     /* Master End Transfer */
    I2c_Drv_MasterSendByte(InstId, I2C_DRV_STOP_EN);

    MasterState->Status = I2C_DRV_RECEIVED_NACK_STATUS;

    I2c_Drv_MasterEndTransfer(InstId);

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_NACK);
#else
    I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_END_TRANSFER);
#endif

}

/**
 * @brief      Get the addr receive ack.
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return     none
 *
 */
static inline boolean I2c_Drv_GetReceivedACK(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;
    boolean RetValue = FALSE;

    MasterState = &I2c_Drv_MasterState[InstId];

    if(TRUE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_DATA_NO_ACK))
    {
        MasterState->Status = I2C_DRV_ERROR_STATUS;
        RetValue = FALSE;
    }
    else
    {
        if(TRUE == MasterState->AddrBitMode)
        {
            if(TRUE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_7BIT_ADDR_NO_ACK))
            {
                MasterState->Status = I2C_DRV_ERROR_STATUS;
                RetValue = FALSE;
            }
            else
            {
                RetValue = TRUE;

            }
        }
        else
        {
            if(TRUE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_10BIT_ADDR1_NO_ACK))
            {
                MasterState->Status = I2C_DRV_ERROR_STATUS;
                RetValue = FALSE;
            }
            else
            {
                RetValue = TRUE;

            }

        }

    }

    return RetValue;
}


/**
 * @brief      Set the master last byte transmitted.
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return     none
 *
 */
static void I2c_Drv_MasterLastByteTransmitted(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    if (TRUE == MasterState->SendStop)
    {
        /* Generate stop signal */
        I2c_Drv_MasterSendByte(InstId, I2C_DRV_STOP_EN);
        MasterState->StopGenerated = TRUE;
        MasterState->Status = I2C_DRV_SUCCESS_STATUS;

        I2c_Drv_MasterEndTransfer(InstId);

        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_END_TRANSFER);
    }
    else
    {
        if(TRUE == MasterState->RestartSendData)
        {
            I2c_Drv_MasterSendByte(InstId, I2C_DRV_RESTART_AND_STOP_DISABLE);
            MasterState->RestartGenerated = TRUE;
        }
        else
        {
            I2c_Drv_MasterSendByte(InstId, I2C_DRV_RESTART_EN);
        }
        /* Generate repeated start and end transfer */
        MasterState->StopGenerated = FALSE;
    }
}

/**
 * @brief      This function I2c master transmit data 
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_MasterTransmitDataEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    /* Last byte transmitted */
    if((0U == MasterState->BufferSize))
    {
        if(TRUE == MasterState->RestartGenerated)                    
        {
            I2CWx->I2C_COMMAND_DATA = ((uint32)(I2C_DRV_RESTART_EN) << 0x9UL) | (0x100UL);

            I2c_Drv_MasterEndTransfer(InstId);

            MasterState->Status = I2C_DRV_SUCCESS_STATUS;

            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_RESTART_TRANSFER);
        }
        else
        {
            MasterState->Status = I2C_DRV_ERROR_STATUS;
                                
            I2c_Drv_MasterEndTransfer(InstId);

            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_TRANSFER_ERROR);
        }
    }
    else if ((1U == MasterState->BufferSize))
    {
        I2c_Drv_MasterLastByteTransmitted(InstId);
    }
    else
    {
        /* Receive acknowledge */
        if (TRUE == I2c_Drv_GetReceivedACK(InstId))
        {
            I2c_Drv_MasterSendByte(InstId, I2C_DRV_RESTART_AND_STOP_DISABLE);
        }
        else
        {
            I2c_Drv_MasterGenerateStopEvent(InstId);
        }
    }
}

static void I2c_Drv_MasterSend(I2c_Drv_IdType InstId)
{
    const Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    if(FALSE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_DATA_NO_ACK))
    {
        if((TRUE == I2c_Drv_GetCurrentStatus(InstId, I2C_DRV_STATUS_TFNF)) && 
                                (I2C_DRV_TX_FIFO_CNT > (uint32)I2Cx->I2C_TX_FIFO_CNT.TX_FIFO_CNT))
        {
            I2c_Drv_MasterTransmitDataEvent(InstId);
        }
    }
}

static void I2c_Drv_MasterReceiveDataEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];
    
    if (TRUE == MasterState->SendStop)
    {
        I2c_Drv_MasterReceiveByte(InstId);
        /* Generate Stop Signal */

        I2CWx->I2C_COMMAND_DATA = ((uint32)(I2C_DRV_STOP_EN) << 0x9UL) | (0x100UL);

        MasterState->StopGenerated = TRUE;
    }
    else
    {
        /* Generate repeated start */
        I2c_Drv_MasterReceiveByte(InstId);
        MasterState->StopGenerated = FALSE;
    }

    /* End transfer here in case of repeated start */
    if(0U == MasterState->BufferSize)
    {

        MasterState->Status = I2C_DRV_SUCCESS_STATUS;

        I2c_Drv_MasterEndTransfer(InstId);

        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_END_TRANSFER);

    }
}

static void I2c_Drv_MasterReceive(I2c_Drv_IdType InstId)
{
    const I2c_Drv_MasterStateType * MasterState;
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];

    if((FALSE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_DATA_NO_ACK)))
    {
        if(TRUE == I2c_Drv_GetCurrentStatus(InstId, I2C_DRV_STATUS_RFNE))
        {
            /* Last byte transmitted */
            if ((1U == MasterState->BufferSize) && (FALSE == MasterState->SendData))
            {
                /* Read data  */
                I2c_Drv_MasterReceiveDataEvent(InstId);  

                if (TRUE == (MasterState->StopGenerated))
                {
                    /* Disable the I2C */
                    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;
                }
            }
            else
            { 
                I2c_Drv_MasterReceiveByte(InstId);

                I2CWx->I2C_COMMAND_DATA = 
                                ((uint32)(I2C_DRV_RESTART_AND_STOP_DISABLE) << 0x9UL) | (0x100UL);
            }  
        }

    }
}

/**
 * @brief      Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  I2cPhyUnitCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
static I2c_Drv_ChannelStateType I2c_Drv_SetMasterGlobalConfig(I2c_Drv_IdType InstId)
{
    const I2c_Drv_MasterStateType * MasterState;
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

    MasterState = &I2c_Drv_MasterState[InstId];

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(MasterState != NULL_PTR);
#endif


    if (TRUE == I2c_Drv_GetIntStatus(InstId, I2C_DRV_INT_STOP_DET))
    {
        /* detection generate stop signal disable i2c*/
        I2Cx->I2C_CONFIG0.MODULE_EN = 0U;
    }

    /* Select master mode */
    I2c_Drv_SetModuleModSelect(InstId, I2C_DRV_MASTER_MODE);

    /* Set I2C start its transfer in 7 or 10 bits address mode */
    I2Cx->I2C_CONFIG1.MASTER_10BIT_ADDR_SEL = 
            (uint32)(MasterState->AddrBitMode);

    /* Set Receive FIFO threshold level */
    I2Cx->I2C_RXFIFO_WATER_MARK.RXFIFO_WATER_MARK = MasterState->RxFifoWaterMark;
    /* Set Transmit FIFO threshold level */
    I2Cx->I2C_TXFIFO_WATER_MARK.TXFIFO_WATER_MARK = MasterState->TxFifoWaterMark;

    /* Set the target address */
    I2Cx->I2C_DEST_ADDR.DEST_ADDR = (uint32)MasterState->OwnSlaveAddr;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return I2C_DRV_SUCCESS_STATUS;
}

static void I2c_Drv_MasterTransferData(I2c_Drv_IdType InstId)
{
    uint32 CurrentTicks = 0u;  /* initialize current counter */
    uint32 ElapsedTicks = 0u;    /* elapse elapsed time */
    uint32 TotalElapsedTicks = 0U; /* total elapsed time*/
    uint32 TimeoutTicks = McalLib_MicroSecToTicks(I2C_DRV_TIMEOUT_TYPE, I2C_DRV_TIMEOUT);

    I2c_Drv_MasterStateType * MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];

    (void)McalLib_GetCounterValue(I2C_DRV_TIMEOUT_TYPE, &CurrentTicks);

    do
    {
        if(TRUE == MasterState->SendData)
        {
            /* Master send data */
            I2c_Drv_MasterSend(InstId);
        }
        else
        {
            /* Master receive data */
            I2c_Drv_MasterReceive(InstId);
        }
        (void)McalLib_GetElapsedValue(I2C_DRV_TIMEOUT_TYPE, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;

    }while((I2C_DRV_BUSY_STATUS == MasterState->Status) && (TotalElapsedTicks < TimeoutTicks));

    if(TotalElapsedTicks >= TimeoutTicks)
    {
        MasterState->Status = I2C_DRV_TIMEOUT_STATUS;
    }
}

/**
 * @brief     Clear all error status .
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */
static void I2c_Drv_ClearErrorStatusAll(I2c_Drv_IdType InstId)
{
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
#endif

    const Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    volatile uint32 dummyData;
    /* Dummy read to clear all error status */
    dummyData = I2Cx->I2C_RD_CLR_ERR_STATUS.CLR_ERR;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This function handles I2c master start transmit configuration
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_MasterStartTransmitConfig(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;
    MasterState = &I2c_Drv_MasterState[InstId];
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    /* Send master */
    (void)I2c_Drv_SetMasterGlobalConfig(InstId);
   
    /* Enable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 1U;

    if(1U == MasterState->BufferSize)
    {
        if (TRUE == MasterState->SendStop)
        {
            /* Generate stop signal */
            I2c_Drv_MasterSendByte(InstId, I2C_DRV_STOP_EN);
            MasterState->StopGenerated = TRUE;
        }
        else
        {
            if(TRUE == MasterState->RestartSendData)
            {
                I2c_Drv_MasterSendByte(InstId, I2C_DRV_RESTART_AND_STOP_DISABLE);

                I2CWx->I2C_COMMAND_DATA = 
                            ((uint32)(I2C_DRV_RESTART_EN) << 0x9UL) | (0x100UL);

                MasterState->RestartGenerated = TRUE;
            }
            else
            {
                I2c_Drv_MasterSendByte(InstId, I2C_DRV_RESTART_EN);
            }
            /* Generate repeated start and end transfer */
            MasterState->StopGenerated = FALSE;
        } 

        I2c_Drv_MasterEndTransfer(InstId);

        MasterState->Status = I2C_DRV_SUCCESS_STATUS;

        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_END_TRANSFER);

        MasterState->RestartGenerated = TRUE;
    }
    else
    {
        I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_START_DET, TRUE);
        I2c_Drv_MasterSendByte(InstId, I2C_DRV_RESTART_AND_STOP_DISABLE);
    }
}

static void I2c_Drv_MasterHandleErrIntEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];

    if (TRUE == MasterState->SendData)
    {     
        if(TRUE == I2c_Drv_GetCurrentStatus(InstId, I2C_DRV_SDA_ERR_RECOVER_STUCK_LOW))
        {
            I2c_Drv_MasterEndTransfer(InstId);

            MasterState->Status = I2C_DRV_TIMEOUT_STATUS;

            I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_PIN_LOW_TIMEOUT);
        }

        if (TRUE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_SDA_LOW_TIMEOUT))
        {

            I2Cx->I2C_CONFIG0.SDA_RECOVER_EN = (uint32)1U;
            I2c_Drv_ClearErrorStatusAll(InstId);
        }
    }
}

/**
 * @brief      This function handles I2c master mode transmit interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_MasterTransmitHandler(I2c_Drv_IdType InstId)
{
    I2c_Drv_MasterStateType * MasterState;
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    uint32 IntStatus;

    IntStatus = I2CWx->I2C_STATUS0;
    /* get status */  
    IntStatus &= I2CWx->I2C_INT_ENABLE;
    /* Clear the interrupt status */
    I2CWx->I2C_STATUS0 = IntStatus;
    /* Master Mode */

    MasterState = &I2c_Drv_MasterState[InstId];

    I2c_Drv_MasterHandleErrIntEvent(InstId);

    if((IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_SCL_STUCK_AT_LOW]) != 0U)
    {
        I2c_Drv_MasterEndTransfer(InstId);

        MasterState->Status = I2C_DRV_TIMEOUT_STATUS;

        I2c_Drv_MasterEvent(InstId, I2C_DRV_MASTER_EVENT_PIN_LOW_TIMEOUT);
    }

    if((IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_START_DET]) != 0U)
    {
        I2Cx->I2C_CONFIG1.TXFIFO_EMPTY_EN = (uint32)I2C_DRV_TX_BUFFER;

        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_TX_EMPTY, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_START_DET, FALSE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_SCL_STUCK_AT_LOW, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_STOP_DET, TRUE);
    }

    if(0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_TX_EMPTY]))
    {
        if((FALSE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_DATA_NO_ACK)) && 
                                (I2C_DRV_TX_FIFO_CNT > (uint32)I2Cx->I2C_TX_FIFO_CNT.TX_FIFO_CNT))
        {
            I2c_Drv_MasterTransmitDataEvent(InstId);
        }
    }


    if((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_STOP_DET])))
    {
        /* Disable the I2C */
        I2Cx->I2C_CONFIG0.MODULE_EN = 0U;
    }

}

/**
 * @brief      This function handles I2c master mode receive data interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_MasterReceiveHandler(I2c_Drv_IdType InstId)
{
    const I2c_Drv_MasterStateType * MasterState;
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    uint32 IntStatus;

    IntStatus = I2CWx->I2C_STATUS0;
    /* get status */  
    IntStatus &= I2CWx->I2C_INT_ENABLE;
    /* Clear the interrupt status */
    I2CWx->I2C_STATUS0 = IntStatus;
    /* Master Mode */
    MasterState = &I2c_Drv_MasterState[InstId];

    if((IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_START_DET]) != 0U)
    {
        I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_RX_FULL, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_START_DET, FALSE);
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_START_DET);
    }

    if(0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RX_FULL]))
    {
        if(FALSE == I2c_Drv_GetErrorStatus(InstId, I2C_DRV_ERR_DATA_NO_ACK))
        {
            /* Last byte received */
            if ((1U == MasterState->BufferSize) && (FALSE == MasterState->SendData))
            {
                /* Read data  */
                I2c_Drv_MasterReceiveDataEvent(InstId);  
            }
            else
            {
                I2c_Drv_MasterReceiveByte(InstId);

                I2CWx->I2C_COMMAND_DATA = 
                                ((uint32)(I2C_DRV_RESTART_AND_STOP_DISABLE) << 0x9UL) | (0x100UL);
            }
        }
    }
}

/**
 * @brief      This function handles I2c master mode interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_MasterIntHandler(I2c_Drv_IdType InstId)
{
    const I2c_Drv_MasterStateType * MasterState;

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Check the mode - receive or transmit */
    if (TRUE == MasterState->SendData)
    {
        I2c_Drv_MasterTransmitHandler(InstId);
    }
    else
    {
        I2c_Drv_MasterReceiveHandler(InstId);
    }
}

/**
 * @brief      This function handles I2c slave mode transmit data interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_SlaveHandleTransmitDataEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType * SlaveState;
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];

    SlaveState = &I2c_Drv_SlaveState[InstId];

    if (TRUE == SlaveState->TxUnderrunWarning)
    {
        /* Another Tx event after underflow warning means the dummy char was sent */
        SlaveState->Status = I2C_DRV_TX_UNDERRUN_STATUS;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)

        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_UNDERRUN);
#endif
    }

    if (0U == SlaveState->BufferSize)
    {
        SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
        /* Out of data, call callback to allow user to provide a new buffer */
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_TX_EMPTY);
    }

    if (0U == SlaveState->BufferSize)
    {
        /*
        * Still no data, record tx underflow event and send dummy char.
        * Special case after the last tx byte: the device will ask for more data
        * but the dummy char will not be sent if NACK and then STOP condition are
        * received from master. So only record a "warning" for now.
        */
        SlaveState->TxUnderrunWarning = TRUE;

        I2CWx->I2C_COMMAND_DATA = (uint32)0xFF;

    }
    else
    {
        SlaveState->TxUnderrunWarning = FALSE;
        SlaveState->Status = I2C_DRV_BUSY_STATUS;
        SlaveState->I2cChannelCallback((uint8)InstId, (uint8)I2C_DRV_STATE_SEND);

        /* Send one byte */
        I2CWx->I2C_COMMAND_DATA = (uint32)SlaveState->DataBuffer[0];
        SlaveState->BufferSize--;
        if(0U != SlaveState->BufferSize)
        {
            SlaveState->DataBuffer++;
        }
    }
}

/**
 * @brief      This function handles I2c slave mode receive data interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_SlaveHandleReceiveDataEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType * SlaveState;

    SlaveState = &I2c_Drv_SlaveState[InstId];

    if (0U == SlaveState->BufferSize)
    {
        SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
        /* No more room for data, call callback to allow user to provide a new buffer */
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_RX_FULL);
    }

    if (0U == SlaveState->BufferSize)
    {
        /* Still no room for data, record rx overrun event and dummy read data */
        SlaveState->Status = I2C_DRV_RX_OVERRUN_STATUS;

        (void)I2c_Drv_ReceiveByte(InstId);

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_OVERRUN);
#endif
    }
    else
    {
        SlaveState->Status = I2C_DRV_BUSY_STATUS;
        SlaveState->I2cChannelCallback((uint8)InstId, (uint8)I2C_DRV_STATE_RECEIVE);

        SlaveState->DataBuffer[0U] = I2c_Drv_ReceiveByte(InstId);
        SlaveState->BufferSize--;
        if(0U != SlaveState->BufferSize)
        {
            SlaveState->DataBuffer++;
        }
    }
}

/**
 * @brief      This function handles I2c slave receive data overflow interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_SlaveHandleReceiveDataOverFlowEvent(I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType * SlaveState;
    uint8 OverFlowLoop = 0U;

    SlaveState = &I2c_Drv_SlaveState[InstId];

    if (0U == SlaveState->BufferSize)
    {
        SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
        /* No more room for data, call callback to allow user to provide a new buffer */
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_RX_FULL);
    }

    if (0U == SlaveState->BufferSize)
    {
        /* Still no room for data, record rx overrun event and dummy read data */
        SlaveState->Status = I2C_DRV_RX_OVERRUN_STATUS;
        (void)I2c_Drv_ReceiveByte(InstId);

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_OVERRUN);
#endif
    }
    else
    {
        if(SlaveState->BufferSize > I2C_DRV_RX_FIFO_CNT)
        {
            SlaveState->Status = I2C_DRV_BUSY_STATUS;

            for(OverFlowLoop = 0U; OverFlowLoop < I2C_DRV_RX_FIFO_CNT; OverFlowLoop++)
            {
                SlaveState->DataBuffer[0U] = I2c_Drv_ReceiveByte(InstId);
                SlaveState->BufferSize--;
                if(0U != SlaveState->BufferSize)
                {
                    SlaveState->DataBuffer++;
                }
            }
        }
        else
        {
            SlaveState->Status = I2C_DRV_RX_OVERRUN_STATUS;

            for(OverFlowLoop = 0U; OverFlowLoop < SlaveState->BufferSize; OverFlowLoop++)
            {
                SlaveState->DataBuffer[0U] = I2c_Drv_ReceiveByte(InstId);
                SlaveState->BufferSize--;
                if(0U != SlaveState->BufferSize)
                {
                    SlaveState->DataBuffer++;
                }
            }

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
            I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_OVERRUN);
#endif
        }
    }
}

/**
 * @brief      This function handles I2c slave mode interrupt
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */ 
static void I2c_Drv_SlaveIntHandler(I2c_Drv_IdType InstId)
{
    I2c_Drv_SlaveStateType * SlaveState;
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    uint32 IntStatus;

    IntStatus = I2CWx->I2C_STATUS0;
    /* get status */  
    IntStatus &= I2CWx->I2C_INT_ENABLE;
    /* Clear the interrupt status */
    I2CWx->I2C_STATUS0 = IntStatus;

    SlaveState = &I2c_Drv_SlaveState[InstId];
   
    if((IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_START_DET]) != 0U)
    {   
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_RX_FULL, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_RD_REQ, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_RESTART_DET, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_STOP_DET, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_RX_OVER, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_RX_DONE, TRUE);
        I2c_Drv_SetInterrupt(InstId,I2C_DRV_INT_START_DET, FALSE);
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_START_DET);
    }

    if(0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_STOP_DET]))
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);
        if (I2C_DRV_BUSY_STATUS == SlaveState->Status)
        {
            /* Report success if no error was recorded */
            SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
        }
        /* Slave end transfer handler. */

        I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_STOP);
    }

    if((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RESTART_DET])))
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);
        if (I2C_DRV_BUSY_STATUS == SlaveState->Status)
        {
            /* Report success if no error was recorded */
            SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
            I2c_Drv_SlaveEvent(InstId, I2C_DRV_SLAVE_EVENT_RESTART);
        }
    }

    if((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RX_DONE])))
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_ALL);
        if (I2C_DRV_BUSY_STATUS == SlaveState->Status)
        {
            /* Report success if no error was recorded */
            SlaveState->Status = I2C_DRV_SUCCESS_STATUS;
        }
    }

    if((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RX_FULL])))
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_RX_FULL);
        I2c_Drv_SlaveHandleReceiveDataEvent(InstId); 
    }

    if((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RX_OVER])))
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_RX_OVER);
        I2c_Drv_SlaveHandleReceiveDataOverFlowEvent(InstId); 
    }

    if((0U != (IntStatus & I2c_Drv_IntEnableTable[I2C_DRV_INT_RD_REQ])))
    {
        I2c_Drv_ClearInt(InstId, I2C_DRV_INT_RD_REQ);
        I2c_Drv_SlaveHandleTransmitDataEvent(InstId);
    }


}

/**
 * @brief      Initialize I2c master configuration
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  MasterCfgPtr: Pointer that contains driver master configuration data 
 *
 * @return none
 *
 */    
static I2c_Drv_ChannelStateType I2c_Drv_MasterInit(const uint32 InstId, 
                                          const I2c_Drv_MasterConfigType * MasterCfgPtr)
{
    I2c_Drv_MasterStateType * MasterState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(MasterCfgPtr != NULL_PTR);
#endif

    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Initialize driver status structure */
    MasterState->DataBuffer = NULL_PTR; 
    MasterState->BufferSize = 0U;   /* 0 means no buffer */
    MasterState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    MasterState->I2cIdle = TRUE;    /* default state */  
    MasterState->OwnSlaveAddr = 0U; 
    MasterState->AddrBitMode = TRUE;  
    MasterState->SpeedMode = MasterCfgPtr->SpeedMode;
    MasterState->RestartGenerated = FALSE;
    MasterState->StopGenerated = FALSE; 
    MasterState->RxFifoWaterMark = 0U;
    MasterState->TxFifoWaterMark = 0U;

    MasterState->I2cChannelCallback = MasterCfgPtr->I2cChannelCallback;  /* callback */
    MasterState->I2cCallback = MasterCfgPtr->I2cCallback;  /* I2c Callback */
    MasterState->I2cErrCallback = MasterCfgPtr->I2cErrCallback;  /* ErrCallback */

    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;
    
    I2c_Drv_SetInterrupt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL, FALSE);
    I2c_Drv_ClearErrorStatusAll((I2c_Drv_IdType)InstId);
    I2c_Drv_ClearInt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL);

    I2Cx->I2C_CONFIG1.SPEED_SEL = ((uint32)(MasterCfgPtr->SpeedMode))&0x3U;

    switch(MasterCfgPtr->SpeedMode)
    {
        case I2C_DRV_SPEED_STANDARD:
            I2Cx->I2C_STD_SCL_HCNT.STD_SCL_HCNT = (uint32)MasterCfgPtr->SclHcnt;
            I2Cx->I2C_STD_SCL_LCNT.STD_SCL_LCNT = (uint32)MasterCfgPtr->SclLcnt;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_FAST:
            I2Cx->I2C_FST_SCL_HCNT.FST_SCL_HCNT = (uint32)MasterCfgPtr->SclHcnt;
            I2Cx->I2C_FST_SCL_LCNT.FST_SCL_LCNT = (uint32)MasterCfgPtr->SclLcnt;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_HIGH:
            I2Cx->I2C_HS_SCL_HCNT.HS_SCL_HCNT = (uint32)MasterCfgPtr->SclHcnt;
            I2Cx->I2C_HS_SCL_LCNT.HS_SCL_LCNT = (uint32)MasterCfgPtr->SclLcnt;
            I2Cx->I2C_HS_SPKCNT.HS_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            I2Cx->I2C_CONFIG0.H_MCODE = (uint8)MasterCfgPtr->Mcode;
            break;

        case I2C_DRV_SPEED_FAST_PLUS:
            I2Cx->I2C_FST_SCL_HCNT.FST_SCL_HCNT = (uint32)MasterCfgPtr->SclHcnt;
            I2Cx->I2C_FST_SCL_LCNT.FST_SCL_LCNT = (uint32)MasterCfgPtr->SclLcnt;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)MasterCfgPtr->SpikeSuppressionLimit;
            break;

        default:
            /* Do nothing */
            break;
    }
    /* I2C bus recover feature in master mode */
    I2Cx->I2C_CONFIG0.MASTER_BUS_RECOVER_EN = (uint32)1U;  

    I2Cx->I2C_SCL_LOW_TIMEOUT.SCL_LOW_TIMEOUT = (uint32)MasterCfgPtr->SclLowTimeout;
    I2Cx->I2C_SDA_LOW_TIMEOUT.SDA_LOW_TIMEOUT = (uint32)MasterCfgPtr->SdaLowTimeout;

    I2Cx->I2C_SDA_HOLD_TIMING.SDA_RX_HOLD_TIMING =
                                                 MasterCfgPtr->I2cSdaHoldTiming.SdaReceiveHoldTime;
    I2Cx->I2C_SDA_HOLD_TIMING.SDA_TX_HOLD_TIMING = 
                                                MasterCfgPtr->I2cSdaHoldTiming.SdaTransmitHoldTime;            

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    
    return I2C_DRV_SUCCESS_STATUS;
}

/**
 * @brief      Initialize I2c slave configuration
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  SlaveCfgPtr: Pointer that contains driver slave configuration data 
 *
 * @return none
 *
 */    
static I2c_Drv_ChannelStateType I2c_Drv_SlaveInit(const uint32 InstId, 
                                          const I2c_Drv_SlaveConfigType * SlaveCfgPtr)
{
    I2c_Drv_SlaveStateType * SlaveState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(SlaveCfgPtr != NULL_PTR);
#endif
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    SlaveState = &I2c_Drv_SlaveState[InstId];

    /* Initialize driver status structure */
    SlaveState->Direction = I2C_DRV_SEND_DATA;
    SlaveState->DataBuffer = NULL_PTR; 
    SlaveState->BufferSize = 0U;   /* 0 means no buffer */
    SlaveState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    SlaveState->I2cIdle = TRUE;    /* default state */  
    SlaveState->AddrBitMode = SlaveCfgPtr->AddrBitMode;  
    SlaveState->OwnSlaveAddr = SlaveCfgPtr->OwnSlaveAddr;
    SlaveState->SpeedMode = SlaveCfgPtr->SpeedMode; 
    SlaveState->I2cChannelCallback = SlaveCfgPtr->I2cChannelCallback;  /* callback */
    SlaveState->I2cCallback = SlaveCfgPtr->I2cCallback;  /* I2c Callback */
    SlaveState->I2cErrCallback = SlaveCfgPtr->I2cErrCallback;  /* ErrCallback */

    SlaveState->RxFifoWaterMark = 0U;
    SlaveState->TxFifoWaterMark = 0U;

    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;

    I2c_Drv_SetInterrupt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL, FALSE);
    I2c_Drv_ClearErrorStatusAll((I2c_Drv_IdType)InstId);
    I2c_Drv_ClearInt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL);

    I2Cx->I2C_CONFIG1.SPEED_SEL = ((uint32)(SlaveCfgPtr->SpeedMode))&0x3U;

    switch(SlaveCfgPtr->SpeedMode)
    {
        case I2C_DRV_SPEED_STANDARD:
            I2Cx->I2C_STD_SCL_HCNT.STD_SCL_HCNT = (uint32)SlaveCfgPtr->SclHcnt;
            I2Cx->I2C_STD_SCL_LCNT.STD_SCL_LCNT = (uint32)SlaveCfgPtr->SclLcnt;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)SlaveCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_FAST:
            I2Cx->I2C_FST_SCL_HCNT.FST_SCL_HCNT = (uint32)SlaveCfgPtr->SclHcnt;
            I2Cx->I2C_FST_SCL_LCNT.FST_SCL_LCNT = (uint32)SlaveCfgPtr->SclLcnt;
            I2Cx->I2C_FSTD_SPKCNT.FSTD_SPKLEN = (uint32)SlaveCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_HIGH:
            I2Cx->I2C_HS_SCL_HCNT.HS_SCL_HCNT = (uint32)SlaveCfgPtr->SclHcnt;
            I2Cx->I2C_HS_SCL_LCNT.HS_SCL_LCNT = (uint32)SlaveCfgPtr->SclLcnt;
            I2Cx->I2C_HS_SPKCNT.HS_SPKLEN = (uint32)SlaveCfgPtr->SpikeSuppressionLimit;
            break;

        case I2C_DRV_SPEED_FAST_PLUS:
            I2Cx->I2C_FST_SCL_HCNT.FST_SCL_HCNT = (uint32)SlaveCfgPtr->SclHcnt;
            I2Cx->I2C_FST_SCL_LCNT.FST_SCL_LCNT = (uint32)SlaveCfgPtr->SclLcnt;
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

    /* Set the slave target address */
    I2Cx->I2C_SLAVE_ADDR.SLV_ADDR = (uint32)SlaveState->OwnSlaveAddr;
    /* Set the slave address bit */
    I2Cx->I2C_CONFIG1.SLAVE_10BIT_ADDR_SEL = (uint32)SlaveState->AddrBitMode;

   /* Select slave mode */
    I2c_Drv_SetModuleModSelect((I2c_Drv_IdType)InstId, I2C_DRV_SLAVE_MODE);

    I2c_Drv_SetInterrupt((I2c_Drv_IdType)InstId,I2C_DRV_INT_START_DET, TRUE);

    /* Enable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 1U;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    
    return I2C_DRV_SUCCESS_STATUS; 
}

/**
 * @brief      de-Initialize I2c Master configuration
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */    
static I2c_Drv_ChannelStateType I2c_Drv_MasterDeInit(const uint32 InstId)
{
    I2c_Drv_MasterStateType * MasterState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
#endif

    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    MasterState = &I2c_Drv_MasterState[InstId];
    
    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;


    I2Cx->I2C_CONFIG0.SDA_RECOVER_EN = 0U;
    I2Cx->I2C_CONFIG0.MASTER_BUS_RECOVER_EN = 0U;
    I2Cx->I2C_CONFIG1.MASTER_RESTART_EN  = 0U;
    I2Cx->I2C_CONFIG1.TXFIFO_EMPTY_EN = 0U;

    /* De-Initialize driver status structure */
    MasterState->DataBuffer = NULL_PTR; 
    MasterState->BufferSize = 0U;   /* 0 means no buffer */
    MasterState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    MasterState->I2cIdle = TRUE;    /* default state */  
    MasterState->OwnSlaveAddr = 0U; 
    MasterState->AddrBitMode = TRUE;  
    MasterState->SpeedMode = I2C_DRV_SPEED_STANDARD;
    MasterState->RestartGenerated = FALSE;
    MasterState->RxFifoWaterMark = 0U;
    MasterState->TxFifoWaterMark = 0U;

    MasterState->I2cCallback = NULL_PTR;  /* I2c Callback */
    MasterState->I2cErrCallback = NULL_PTR;  /* ErrCallback */

    I2c_Drv_ClearErrorStatusAll((I2c_Drv_IdType)InstId);
    I2c_Drv_ClearInt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL);
    I2c_Drv_SetInterrupt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL, FALSE);

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return I2C_DRV_SUCCESS_STATUS;
}

/**
 * @brief      de-Initialize I2c slave configuration
 *
 * @param[in]  InstId: Select the I2C port.
 *
 * @return none
 *
 */    
static I2c_Drv_ChannelStateType I2c_Drv_SlaveDeInit(const uint32 InstId)
{
    I2c_Drv_SlaveStateType * SlaveState;
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
#endif
    SlaveState = &I2c_Drv_SlaveState[InstId];
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    /* Disable the I2C */
    I2Cx->I2C_CONFIG0.MODULE_EN = 0U;

    SlaveState->Direction = I2C_DRV_SEND_DATA;
    SlaveState->DataBuffer = NULL_PTR; 
    SlaveState->BufferSize = 0U;   /* 0 means no buffer */
    SlaveState->Status = I2C_DRV_SUCCESS_STATUS; /* default status */
    SlaveState->I2cIdle = TRUE;    /* default state */  
    SlaveState->AddrBitMode = 0U;  
    SlaveState->OwnSlaveAddr = 0U;  
    SlaveState->SpeedMode = I2C_DRV_SPEED_STANDARD; 
    SlaveState->I2cCallback = NULL_PTR;  /* I2c Callback */
    SlaveState->I2cErrCallback = NULL_PTR;  /* ErrCallback */

    SlaveState->RxFifoWaterMark = 0U;
    SlaveState->TxFifoWaterMark = 0U;
    
    I2c_Drv_ClearErrorStatusAll((I2c_Drv_IdType)InstId);
    I2c_Drv_ClearInt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL);
    I2c_Drv_SetInterrupt((I2c_Drv_IdType)InstId, I2C_DRV_INT_ALL, FALSE);

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
    return I2C_DRV_SUCCESS_STATUS;
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
 * @brief      Set the target address .
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TargetAddr: The target address for any master transaction.
 * @param[in]  AddrBitMode: The I2C start its transfer in 7 or 10 bits address mode.
 * @param[in]  RestartSendData: The Restart direction of the data. Can be either Send or Receive.
 *
 * @return     none
 *
 */
void I2c_Drv_SetRequestConfig(const I2c_Drv_IdType InstId, 
                                                uint16 TargetAddr, 
                                                boolean AddrBitMode, 
                                                boolean RestartSendData)
{
    I2c_Drv_MasterStateType * MasterState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(TargetAddr < I2C_DRV_DEST_ADDR);
#endif

    MasterState = &I2c_Drv_MasterState[InstId];
    MasterState->OwnSlaveAddr = (uint32)TargetAddr;
    MasterState->AddrBitMode = AddrBitMode;
    MasterState->RestartSendData = RestartSendData;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void I2c_Drv_Init(const I2c_Drv_IdType InstId, const I2c_Drv_PhyUnitConfigType * I2cPhyUnitCfgPtr)
{
    if(I2C_DRV_MASTER_MODE == I2cPhyUnitCfgPtr->MasterSlaveMode)
    {
        (void)I2c_Drv_MasterInit((uint32)InstId, I2cPhyUnitCfgPtr->MasterCfgPtr);
    }
    else
    {
        (void)I2c_Drv_SlaveInit((uint32)InstId, I2cPhyUnitCfgPtr->SlaveCfgPtr);
    }

}

/**
 * @brief      De-Initialize a hardware I2c Instance
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  I2cPhyUnitCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
void I2c_Drv_DeInit(const I2c_Drv_IdType InstId, const I2c_Drv_PhyUnitConfigType * I2cPhyUnitCfgPtr)
{
    if(I2C_DRV_MASTER_MODE == I2cPhyUnitCfgPtr->MasterSlaveMode)
    {
        (void)I2c_Drv_MasterDeInit((uint32)InstId);
    }
    else
    {
         (void)I2c_Drv_SlaveDeInit((uint32)InstId);
    }

}

/**
 * @brief      This function transmission data i2c blocking.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TxBuffer: Pointer to the buffer-array 
 * @param[in]  TxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterSendDataBlocking(const I2c_Drv_IdType InstId,
                                                           uint8 * TxBuffer,
                                                           uint32 TxSize,
                                                           boolean SendStop)
{
    I2c_Drv_MasterStateType * MasterState;
    I2c_Drv_ChannelStateType ReturnStatus = I2C_DRV_SUCCESS_STATUS;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(TxBuffer != NULL_PTR);
    MCALLIB_DEV_ASSERT(TxSize > 0U);
#endif

    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Check if driver is busy */
    if(FALSE == MasterState->I2cIdle)
    {
        ReturnStatus = I2C_DRV_BUSY_STATUS;
    }
    else
    {
        /* Copy parameters to drive state structure */
        MasterState->DataBuffer = TxBuffer;
        MasterState->BufferSize = TxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->Status = I2C_DRV_BUSY_STATUS;
        MasterState->SendData = TRUE;
        MasterState->SendStop = (TRUE == SendStop) ? 0U : 1U;

        /* Set Receive FIFO threshold level */
        MasterState->RxFifoWaterMark = 3;
        /* Set Transmit FIFO threshold level */ 
        MasterState->TxFifoWaterMark = 3;
        
        /* Send Address */
        (void)I2c_Drv_SetMasterGlobalConfig(InstId);

        /* Enable the I2C */
        I2Cx->I2C_CONFIG0.MODULE_EN = 1U;

        /* Master transfer data */
        I2c_Drv_MasterTransferData(InstId);

        ReturnStatus = MasterState->Status;
    }
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

     return ReturnStatus;
}

/**
 * @brief      This function receive data i2c blocking.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  RxBuff: Pointer to the buffer-array 
 * @param[in]  RxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterReceiveDataBlocking(const I2c_Drv_IdType InstId,
                                                           uint8 * RxBuff,
                                                           uint32 RxSize,
                                                           boolean SendStop)
{
    I2c_Drv_MasterStateType * MasterState;
    I2c_Drv_ChannelStateType ReturnStatus = I2C_DRV_SUCCESS_STATUS;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(RxBuff != NULL_PTR);
    MCALLIB_DEV_ASSERT(RxSize > 0U);
#endif
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    MasterState = &I2c_Drv_MasterState[InstId];

    /* Check if driver is busy */
    if(FALSE == MasterState->I2cIdle)
    {
        ReturnStatus = I2C_DRV_BUSY_STATUS;
    }
    else
    {
        /* Copy parameters to driver state structure */
        MasterState->DataBuffer = RxBuff;
        MasterState->BufferSize = RxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->Status = I2C_DRV_BUSY_STATUS;
        MasterState->SendData = FALSE;
        MasterState->SendStop = (TRUE == SendStop) ? 0U : 1U;

        /* Set Receive FIFO threshold level */
        MasterState->RxFifoWaterMark = 3;
        /* Set Transmit FIFO threshold level */ 
        MasterState->TxFifoWaterMark = 3;

        (void)I2c_Drv_SetMasterGlobalConfig(InstId);
               
        /* Enable the I2C */
        I2Cx->I2C_CONFIG0.MODULE_EN = 1U;

        if(FALSE == MasterState->RestartGenerated)
        {
            /* Master receive data */
            I2CWx->I2C_COMMAND_DATA = 
                            ((uint32)(I2C_DRV_RESTART_AND_STOP_DISABLE) << 0x9UL) | (0x100UL);
        }
        else
        {
            MasterState->RestartGenerated = FALSE;
        }

        I2c_Drv_MasterTransferData(InstId);

        ReturnStatus = MasterState->Status;
    }
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif 
    return ReturnStatus;
}

/**
 * @brief      This function receive data i2c block.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  RxBuff: Pointer to the buffer-array 
 * @param[in]  RxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterReceiveData(const I2c_Drv_IdType InstId,
                                                      uint8 *RxBuff,
                                                      uint32 RxSize,
                                                      boolean SendStop)
{
    I2c_Drv_MasterStateType * MasterState;
    I2c_Drv_ChannelStateType ReturnStatus = I2C_DRV_SUCCESS_STATUS;


#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(RxBuff != NULL_PTR);
    MCALLIB_DEV_ASSERT(RxSize > 0U);
#endif
    Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];
    Reg_I2c_WType * I2CWx = I2c_Drv_I2cRegWPtr[InstId];
    MasterState = &I2c_Drv_MasterState[InstId];

    /* Check if driver is busy */
    if(FALSE == MasterState->I2cIdle)
    {
        ReturnStatus = I2C_DRV_BUSY_STATUS;
    }
    else
    {
        /* Copy parameters to driver state structure */
        MasterState->DataBuffer = RxBuff;
        MasterState->BufferSize = RxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->Status = I2C_DRV_BUSY_STATUS;
        MasterState->SendData = FALSE;
        MasterState->SendStop = (TRUE == SendStop) ? 0U : 1U;

        /* Set Receive FIFO threshold level */
        MasterState->RxFifoWaterMark = 0;
        /* Set Transmit FIFO threshold level */ 
        MasterState->TxFifoWaterMark = 0;

        (void)I2c_Drv_SetMasterGlobalConfig(InstId);
        
        I2c_Drv_SetInterrupt(InstId, I2C_DRV_INT_START_DET, TRUE);     
        
        /* Enable the I2C */
        I2Cx->I2C_CONFIG0.MODULE_EN = 1U;

        if(FALSE == MasterState->RestartGenerated)
        {
            /* Master receive data */
            I2CWx->I2C_COMMAND_DATA = 
                            ((uint32)(I2C_DRV_RESTART_AND_STOP_DISABLE) << 0x9UL) | (0x100UL);
        }
        else
        {
            MasterState->RestartGenerated = FALSE;
        }
    }
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif 
    return ReturnStatus;
}

/**
 * @brief      This function receive data i2c block.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TxBuffer: Pointer to the buffer-array 
 * @param[in]  TxSize: Size of the external buffer
 * @param[in]  SendStop: Stop and restart generated
 *
 * @return I2c_Drv_ChannelStateType
 * @retval I2C_DRV_SUCCESS_STATUS  Success
 * @retval I2C_DRV_ERROR_STATUS    Error
 * @retval I2C_DRV_BUSY_STATUS     Busy
 * 
 */
I2c_Drv_ChannelStateType I2c_Drv_MasterSendData(const I2c_Drv_IdType InstId,
                                                uint8 * TxBuffer,
                                                uint32 TxSize,
                                                boolean SendStop)
{
    I2c_Drv_MasterStateType * MasterState;
    I2c_Drv_ChannelStateType ReturnStatus = I2C_DRV_SUCCESS_STATUS;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(TxBuffer != NULL_PTR);
    MCALLIB_DEV_ASSERT(TxSize > 0U);
#endif

    MasterState = &I2c_Drv_MasterState[InstId];

    /* Check if driver is busy */
    if(FALSE == MasterState->I2cIdle)
    {
        ReturnStatus = I2C_DRV_BUSY_STATUS;
    }
    else
    {
        /* Copy parameters to drive state structure */
        MasterState->DataBuffer = TxBuffer;
        MasterState->BufferSize = TxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->Status = I2C_DRV_BUSY_STATUS;
        MasterState->SendData = TRUE;
        MasterState->SendStop = (TRUE == SendStop) ? 0U : 1U;
        MasterState->RestartGenerated = FALSE;
        /* Set Receive FIFO threshold level */
        MasterState->RxFifoWaterMark = 0;
        /* Set Transmit FIFO threshold level */ 
        MasterState->TxFifoWaterMark = 0;

        /* Send master */
        I2c_Drv_MasterStartTransmitConfig(InstId);

    }
    
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif 
     return ReturnStatus;
}

/**
 * @brief      This function set slave receive or send data.
 *
 * @param[in]  InstId: Select the I2C port.
 * @param[in]  TxBuffer: Pointer to the buffer-array 
 * @param[in]  TxSize: Size of the external buffer
 *
 * @return I2c_Drv_StatusType
 * @retval I2C_DRV_STATE_IDLE  Success
 * 
 */
I2c_Drv_StatusType I2c_Drv_SetupSlaveBuffer(const I2c_Drv_IdType InstId,
                                                        uint8 *TxBuff,
                                                        uint32 TxSize)
{
    I2c_Drv_SlaveStateType *SlaveState;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
    MCALLIB_DEV_ASSERT(TxBuff != NULL_PTR);
    MCALLIB_DEV_ASSERT(TxSize > 0U);
#endif

    SlaveState = &I2c_Drv_SlaveState[InstId];

    SlaveState->DataBuffer = TxBuff;
    SlaveState->BufferSize = TxSize;
   
#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif 

    return I2C_DRV_STATE_IDLE;
}

/**
 * @brief      return the current status
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
I2c_Drv_ChannelStateType I2c_Drv_GetStatus(const I2c_Drv_IdType InstId, 
                                                const I2c_Drv_PhyUnitConfigType * I2cPhyUnitCfgPtr)
{
    const I2c_Drv_MasterStateType * MasterState;
    const I2c_Drv_SlaveStateType * SlaveState;
    I2c_Drv_ChannelStateType PhyStatus = I2C_DRV_SUCCESS_STATUS;

#if (STD_ON == I2C_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(I2C_DRV_INSTANCE_SUMCNT > (uint32)InstId);
#endif

    if(I2C_DRV_MASTER_MODE == I2cPhyUnitCfgPtr->MasterSlaveMode)
    {
        MasterState = &I2c_Drv_MasterState[InstId];

        PhyStatus = MasterState->Status;
    }
    else
    {
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
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void I2c_Drv_ChIntHandler(I2c_Drv_IdType InstId)
{

    const I2c_Drv_MasterStateType * MasterState;
    const I2c_Drv_SlaveStateType * SlaveState;
    const Reg_I2c_BfType * I2Cx = I2c_Drv_I2cRegBfPtr[InstId];

    MasterState = &I2c_Drv_MasterState[InstId];
    SlaveState = &I2c_Drv_SlaveState[InstId];

    /* Check if the driver has been initialized */
    if((NULL_PTR != MasterState->DataBuffer) || (NULL_PTR != SlaveState->DataBuffer))
    {
        /* Check if is master or slave module */
        if (FALSE == I2Cx->I2C_CONFIG1.MASTER_MODE_EN)
        {
            I2c_Drv_SlaveIntHandler(InstId);
        }
        else
        {
            I2c_Drv_MasterIntHandler(InstId);
        }
    }
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c_Drv */
/** @} end of group I2c_Module */

