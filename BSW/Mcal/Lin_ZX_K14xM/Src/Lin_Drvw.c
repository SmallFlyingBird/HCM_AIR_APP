/**************************************************************************************************/
/**
 * @file      : Lin_Drvw.c
 * @brief     : Lin driver wrapper source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Lin_Module
 *  @{
 */

/** @defgroup Lin_Drvw
 *  @brief Lin driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin_Drvw.h"
#include "Uart_Drv.h"
#if (STD_ON == LIN_DRVW_WAKEUP_DETECTION )
#include "EcuM.h"
#endif
/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define LIN_DRVW_C_VENDOR_ID                   0x00B3U
#define LIN_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define LIN_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define LIN_DRVW_C_SW_MAJOR_VERSION            1U
#define LIN_DRVW_C_SW_MINOR_VERSION            2U
#define LIN_DRVW_C_SW_PATCH_VERSION            1U

/* Check if current file and Lin_Drvw header file are of the same vendor */
#if (LIN_DRVW_C_VENDOR_ID != LIN_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Lin_Drvw.c and Lin_Drvw.h are different"
#endif

/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_DRVW_C_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_DRVW_C_AR_RELEASE_MINOR_VERSION != LIN_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (LIN_DRVW_C_AR_RELEASE_REVISION_VERSION != LIN_DRVW_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Lin_Drvw.c and Lin_Drvw.h are different"
#endif

/* Check if current file and Lin_Drvw header file are of the same Software version */
#if ((LIN_DRVW_C_SW_MAJOR_VERSION != LIN_DRVW_H_SW_MAJOR_VERSION) || \
     (LIN_DRVW_C_SW_MINOR_VERSION != LIN_DRVW_H_SW_MINOR_VERSION) || \
     (LIN_DRVW_C_SW_PATCH_VERSION != LIN_DRVW_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Lin_Drvw.c and Lin_Drvw.h are different"
#endif

/* Check if current file and Uart_Drv header file are of the same vendor */
#if (LIN_DRVW_C_VENDOR_ID != UART_DRV_H_VENDOR_ID)
    #error "Vendor ID of Lin_Drvw.c and Uart_Drv.h are different"
#endif
/* Check if current file and Uart_Drv_Types header file are of the same Autosar version */
#if ((LIN_DRVW_C_AR_RELEASE_MAJOR_VERSION != UART_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (LIN_DRVW_C_AR_RELEASE_MINOR_VERSION != UART_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (LIN_DRVW_C_AR_RELEASE_REVISION_VERSION != UART_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Drvw.c and Uart_Drv.h are different"
#endif
/* Check if current file and Uart_Drv header file are of the same Software version */
#if ((LIN_DRVW_C_SW_MAJOR_VERSION != UART_DRV_H_SW_MAJOR_VERSION) ||                               \
     (LIN_DRVW_C_SW_MINOR_VERSION != UART_DRV_H_SW_MINOR_VERSION) ||                               \
     (LIN_DRVW_C_SW_PATCH_VERSION != UART_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Lin_Drvw.c and Uart_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
#if (STD_ON  == LIN_DRVW_WAKEUP_DETECTION)
    #if ((LIN_DRVW_C_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) ||                 \
         (LIN_DRVW_C_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Lin_Drvw.c and EcuM.h are different"
    #endif
#endif
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 * @brief        Sleep command frame
 */
#define LIN_DRVW_SLEEP_COMMAND_DATA                                                                \
    {                                                                                              \
        0x00U, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU                                     \
    }

/**
 * @brief        ID used in Gotosleep command transfer.
 */
#define LIN_DRVW_SLEEP_COMMAND_PID ((uint8)0x3CU)

/**
 * @brief        Number bytes of sleep data frame.
 */
#define LIN_DRVW_SLEEP_COMMAND_DATA_LENGTH ((uint8)8U)

/**
 * @brief        Number bytes of Lin data frame.
 */
#define LIN_DRVW_MAX_FRAME_LENGTH      ((uint8)8U)
/** @} end of Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define LIN_START_SEC_VAR_CLEARED_BOOLEAN
#include "Lin_MemMap.h"

/**
 * @brief          Wakeup flags
 */
static volatile boolean Lin_Drvw_WakeupFlagArray[LIN_DRVW_INSTANCE_NUM];

#define LIN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_PTR
#include "Lin_MemMap.h"
/**
 * @brief          Global configuration array.
 */
static const Lin_Drvw_HwConfigType *Lin_Drvw_HwChannelsConfigPtr[LIN_DRVW_NUMBER_OF_INSTANCES_USED];

#define LIN_STOP_SEC_VAR_CLEARED_PTR
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

/**
 * @brief          Logic and physic channel map
 */
static uint8 Lin_Drvw_HwMappingArray[LIN_DRVW_INSTANCE_NUM];

/**
 * @brief          LIN tx command type variable.
 */
static volatile uint8 Lin_Drvw_TransmitCommandArray[LIN_DRVW_NUMBER_OF_INSTANCES_USED];

#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

#if (STD_ON == LIN_DRVW_MASTER_SUPPORT )
#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"
/**
 * @brief          Lin driver status.
 */
/* Pointer to current status*/
static Lin_StatusType Lin_Drvw_Status[] = {LIN_NOT_OK,LIN_TX_OK,LIN_TX_BUSY,LIN_TX_HEADER_ERROR,
LIN_TX_ERROR,LIN_RX_OK,LIN_RX_BUSY,LIN_RX_ERROR,LIN_RX_NO_RESPONSE,LIN_OPERATIONAL,LIN_CH_SLEEP,
LIN_NOT_OK,LIN_NOT_OK};

#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"
#endif

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define LIN_START_SEC_CODE

#include "Lin_MemMap.h"
#if (STD_ON == LIN_DRVW_SLAVE_SUPPORT )
static void Lin_Drvw_OperateSlaveResponse(const uint8                            InstanceId,
                                      const Uart_Drv_TransferConfigType *TransferPtr);
static void Lin_Drvw_IndicationSlaveError(const uint8 InstanceId);
#endif

#if (STD_ON == LIN_DRVW_MASTER_SUPPORT )
static Std_ReturnType Lin_Drvw_CheckPdu(const Lin_PduType *PduInfoPtr);
#endif
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (STD_ON == LIN_DRVW_SLAVE_SUPPORT )
/**
 * @brief       Get slave response from the upper layer.
 *
 * @param[in]   InstanceId: LIN hardware number.
 * @param[in]   TransferPtr: Uart_Lin driver state structure.
 *
 * @return      None
 *
 */
/*SWS_Lin_00053, SWS_Lin_00235 */
static void Lin_Drvw_OperateSlaveResponse(const uint8                            InstanceId,
                                      const Uart_Drv_TransferConfigType *TransferPtr)
{
    NetworkHandleType          Channel = (NetworkHandleType)Lin_Drvw_HwMappingArray[InstanceId];
    uint8          SduBuf[LIN_DRVW_MAX_FRAME_LENGTH];
    Lin_PduType    LinPdu;
    Uart_Drv_PduType    UartPdu;
    LinPdu.Pid    = TransferPtr->CurrentPid;    
    LinPdu.Drc    = LIN_FRAMERESPONSE_IGNORE;
    LinPdu.SduPtr = &SduBuf[0];
    LinPdu.Cs = LIN_CLASSIC_CS;
    LinPdu.Dl = 8U;
    Std_ReturnType Ret = E_NOT_OK;
    Ret = LinIf_HeaderIndication(Channel, &LinPdu);

    if ((uint8)E_OK == Ret)
    {        
        if(LIN_FRAMERESPONSE_TX == LinPdu.Drc)
        {  
            UartPdu.Drc = UART_DRV_FRAMERESPONSE_TX;
            Lin_Drvw_TransmitCommandArray[Channel] = LIN_DRVW_TX_COMMAND_SLAVE_RES;
        }
        else if (LIN_FRAMERESPONSE_RX == LinPdu.Drc)
        {
            UartPdu.Drc = UART_DRV_FRAMERESPONSE_RX;
            Lin_Drvw_TransmitCommandArray[Channel] = LIN_DRVW_TX_COMMAND_MASTER_RES;
        }
        else
        {
            UartPdu.Drc = UART_DRV_FRAMERESPONSE_IGNORE;
        }
    }
    else
    {
        /*Nothing to do*/
    }
	if( LIN_ENHANCED_CS == LinPdu.Cs)
	{
		UartPdu.Cs = (Uart_Drv_FrameCsModelType)UART_DRV_ENHANCED_CS;
	}
	else
	{
		UartPdu.Cs = (Uart_Drv_FrameCsModelType)UART_DRV_CLASSIC_CS;
	}
    
    UartPdu.Dl = LinPdu.Dl;
    UartPdu.Pid = LinPdu.Pid;
    UartPdu.SduPtr = LinPdu.SduPtr;
    if(UART_DRV_STATUS_SUCCESS != Uart_Drv_SendFrame(InstanceId, &UartPdu))
    {
        (void)Uart_Drv_StopTransfer(InstanceId);
    }
}
#endif


/**
 *
 * @brief      LIN notifies to lin interface to about slave error.
 *
 *
 * @param[in]  InstanceId: LIN hardware number.
 *
 * @return     None.
 *
 */
#if (STD_ON == LIN_DRVW_SLAVE_SUPPORT )
static void Lin_Drvw_IndicationSlaveError(const uint8 InstanceId)
{
    uint8                          *DummyBuffPtr;
    NetworkHandleType Channel  = (NetworkHandleType)Lin_Drvw_HwMappingArray[InstanceId];
    Uart_Drv_TransferStateType SlaveStatus = Uart_Drv_GetSlaveStatus(InstanceId, &DummyBuffPtr);
    (void)DummyBuffPtr;

    switch (SlaveStatus)
    {

        case UART_DRV_STATE_RX_HEADER_ERROR:
            /* [SWS_Lin_00235] only for slave node*/  
            LinIf_LinErrorIndication(Channel, LIN_ERR_HEADER);
            break;

        case UART_DRV_STATE_TX_ERROR:
            LinIf_LinErrorIndication(Channel, LIN_ERR_RESP_DATABIT);
            break;

        case UART_DRV_STATE_RX_ERROR:
            LinIf_LinErrorIndication(Channel, LIN_ERR_INC_RESP);
            break;

        case UART_DRV_STATE_RX_NO_RESPONSE:
            LinIf_LinErrorIndication(Channel, LIN_ERR_NO_RESP);
            break;
        default:
	   /* nothing to do */
            break;
    }
}
#endif


#if (STD_ON == LIN_DRVW_MASTER_SUPPORT )
/**
 *
 * @brief       Check Pdu. 
 *
 * @param[in]   PduInfoPtr: Pointer to PDU containing the PID, checksum model, response
 *              type, Dl and SDU data pointer.
 *
 * @return      Std_ReturnType
 * @retval      -E_NOT_OK: Pdu is invalid
 * @retval      -E_OK:no error
 *
 */
static Std_ReturnType Lin_Drvw_CheckPdu(const Lin_PduType *PduInfoPtr)
{
    Std_ReturnType RetVal = E_OK;
    uint8 TempRet;

    TempRet = (uint8)((PduInfoPtr->Dl > 8U) || ( 0U == PduInfoPtr->Dl ));

    if (TRUE == TempRet)
    {
        RetVal = (uint8)E_NOT_OK;
    }
    else
    {
        TempRet = Uart_Drv_ParityCalc(PduInfoPtr->Pid, UART_DRV_SOFTWARE_CHECK_PARITY);
        /* Check Pid */
        if (0xFFU == TempRet)
        {
            RetVal = (uint8)E_NOT_OK;
        }
        else
        {
            /* Nothing to do */
        }
    }
    return RetVal;
}
#endif
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
 * @brief       Initialize a LIN channel.
 *
 * @param[in]   Channel: initial channel.
 * @param[in]   HwUnitConfigPtr: Global configuration pointer.
 *
 * @return      None
 *
 */
void Lin_Drvw_ChannelInit(uint8 Channel, const Lin_Drvw_HwConfigType *HwUnitConfigPtr)
{
    uint8 LinId = HwUnitConfigPtr->LinHwChannel;
    const Uart_Drv_ConfigType *TempPtr;

    Lin_Drvw_HwChannelsConfigPtr[Channel] = HwUnitConfigPtr;

    TempPtr = HwUnitConfigPtr->DrvConfig;
    (void)Uart_Drv_Init(LinId, TempPtr);

    Lin_Drvw_HwMappingArray[LinId] = Channel;

    (void)Uart_Drv_GoToSleepInternal(LinId);

    Lin_Drvw_TransmitCommandArray[Channel] = LIN_DRVW_TX_COMMAND_NO;
}

/**
 *
 * @brief       The function check wakeup.
 *
 * @param[in]   Channel: initial channel.
 *
 * @return      Std_ReturnType.
 * @retval      -E_OK:If the LIN Channel has the wake up flag set and the wake up ISR disabled
 * @retval      -E_NOT_OK:Otherwise.
 *
 */
Std_ReturnType Lin_Drvw_CheckWakeup(uint8 Channel)
{
    Std_ReturnType RetVal = (uint8)E_NOT_OK;

    if (TRUE == Lin_Drvw_WakeupFlagArray[Channel])
    {
        RetVal = (uint8)E_OK;
        Lin_Drvw_WakeupFlagArray[Channel] = FALSE;      
    }
    else
    {
        /*Nothing to do*/
    }

    return RetVal;
}

#if (STD_ON == LIN_DRVW_MASTER_SUPPORT )
/**
 *
 * @brief       The function get status of LIN node or frame
 *
 * @param[in]   Channel: LIN channel to be addressed.
 * @param[in]   LinSduPtr: pointer to  memory mapped LIN hardware receive buffer
 *                       where the current SDU is stored.
 *
 * @return      Lin_StatusType
 * @retval      LIN_NOT_OK - Development or production error occurred.
 * @retval      LIN_TX_OK - Successful transmission.
 * @retval      LIN_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval      LIN_TX_HEADER_ERROR: Erroneous header transmission such as:
 *                  - Mismatch between sent and read back data
 *   		        - Identifier parity error or Physical bus error
 * @retval	    LIN_TX_ERROR: Erroneous response transmission such as:
 *			        - Mismatch between sent and read back data
 *			        - Physical bus error
 * @retval	    LIN_RX_OK: Reception of correct response.
 * @retval	    LIN_RX_BUSY: Ongoing reception: at least one response byte has been received,
 *              but the checksum byte has not been received.
 * @retval	    LIN_RX_ERROR: Erroneous response reception such as:
 *			        - Framing error
 *			        - Overrun error
 *			        - Checksum error or Short response
 * @retval	    LIN_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval	    LIN_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *               from the LIN_CH_SLEEP and no data has been sent.
 * @retval	    LIN_CH_SLEEP: Sleep state operation;
 *              in this state wake-up detection from slave nodes is enabled.
 *
 */
Lin_StatusType Lin_Drvw_GetStatus(uint8 Channel, uint8 **LinSduPtr)
{
    uint8 LinId = Lin_Drvw_HwChannelsConfigPtr[Channel]->LinHwChannel;
    Uart_Drv_TransferStateType UartStatus;
    Lin_StatusType RetVal;

    UartStatus = Uart_Drv_GetMasterStatus(LinId, LinSduPtr);
    RetVal = Lin_Drvw_Status[UartStatus];

    return RetVal;
}

/**
 *
 * @brief       This API command the node to go to sleep, which ID = 0x3C.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      Std_ReturnType
 * @retval      -E_NOT_OK:n case of a time-out situation only.
 * @retval      -E_OK:no error.
 * @retval      -LIN_DRVW_TIMEOUT_ERROR: timeout
 *
 */
Std_ReturnType Lin_Drvw_GoToSleep(uint8 Channel)
{
    Std_ReturnType RetVal = (uint8)E_NOT_OK;
    Uart_Drv_StatusType TempRet;
    uint8          LinId  = Lin_Drvw_HwChannelsConfigPtr[Channel]->LinHwChannel;
    Uart_Drv_PduType    SleepPdu; 
    uint8 LinSleepCommand[LIN_DRVW_SLEEP_COMMAND_DATA_LENGTH] = LIN_DRVW_SLEEP_COMMAND_DATA;

    /* Prepare sleep data */
    SleepPdu.SduPtr = &LinSleepCommand[0];
    SleepPdu.Dl     = LIN_DRVW_SLEEP_COMMAND_DATA_LENGTH;
    SleepPdu.Cs     = UART_DRV_CLASSIC_CS;
    SleepPdu.Drc    = UART_DRV_FRAMERESPONSE_TX;
    SleepPdu.Pid    = LIN_DRVW_SLEEP_COMMAND_PID;

    TempRet = Uart_Drv_StopTransfer(LinId);

    if (UART_DRV_STATUS_BUSY == TempRet)
    {
        RetVal = (uint8)LIN_DRVW_TIMEOUT_ERROR;
    }
    else if(UART_DRV_STATUS_SUCCESS == TempRet)
    {
        TempRet = Uart_Drv_SendFrame(LinId, &SleepPdu);
        if (UART_DRV_STATUS_SUCCESS == TempRet)
        {
            Lin_Drvw_TransmitCommandArray[Channel] = LIN_DRVW_TX_COMMAND_SLEEP;
            RetVal                                  = (uint8)E_OK;
        }
        else
        {
            /*Nothing to do*/
        }
    }
    else
    {
        /* Nothing to do */
    }

    return RetVal;
}

/**
 *
 * @brief       Send LIN frame
 *
 * @param[in]   Channel: LIN channel to be addressed.
 * @param[in]   PduInfoPtr: Pointer to PDU containing the PID, checksum model, response
 *              type, Dl and SDU data pointer.
 *
 * @return      Std_ReturnType
 * @retval      -E_NOT_OK:n case of a time-out situation only.
 * @retval      -E_OK:no error.
 * @retval      -LIN_DRVW_TIMEOUT_ERROR: timeout
 *
 */
Std_ReturnType Lin_Drvw_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr)
{
    Std_ReturnType RetVal = (uint8)E_NOT_OK;
    uint8          LinId  = Lin_Drvw_HwChannelsConfigPtr[Channel]->LinHwChannel;
    Lin_FrameResponseType TempDrc;
    Uart_Drv_StatusType TempRet = Uart_Drv_StopTransfer(LinId);
    Uart_Drv_PduType PduPtr;
	if(LIN_ENHANCED_CS == PduInfoPtr->Cs)
	{
		PduPtr.Cs = (Uart_Drv_FrameCsModelType)UART_DRV_ENHANCED_CS;
	}
	else
	{
		PduPtr.Cs = (Uart_Drv_FrameCsModelType)UART_DRV_CLASSIC_CS;
	}
    
    PduPtr.Dl = PduInfoPtr->Dl;
    PduPtr.Pid = PduInfoPtr->Pid;
    PduPtr.Drc = (Uart_Drv_FrameResponseType)PduInfoPtr->Drc;
    PduPtr.SduPtr = PduInfoPtr->SduPtr;

    if (UART_DRV_STATUS_SUCCESS == TempRet)
    {
        RetVal = Lin_Drvw_CheckPdu(PduInfoPtr);
    }
    else if(UART_DRV_STATUS_BUSY == TempRet)
    {
        RetVal = (uint8)LIN_DRVW_TIMEOUT_ERROR;
    }
    else
    {
        /* Nothing to do */
    }

    if ((uint8)E_OK == (uint8)RetVal)
    { 
        TempRet = Uart_Drv_SendFrame(LinId, &PduPtr);
        RetVal = (uint8)TempRet;
    }

    if ((uint8)E_OK == RetVal)
    {
        TempDrc = PduInfoPtr->Drc;
        switch(TempDrc)
        {
            case LIN_FRAMERESPONSE_RX:
                Lin_Drvw_TransmitCommandArray[Channel] = LIN_DRVW_TX_COMMAND_SLAVE_RES;
                break;
            case LIN_FRAMERESPONSE_TX:
                Lin_Drvw_TransmitCommandArray[Channel] = LIN_DRVW_TX_COMMAND_MASTER_RES;
                break;
            case LIN_FRAMERESPONSE_IGNORE:
                Lin_Drvw_TransmitCommandArray[Channel] = LIN_DRVW_TX_COMMAND_SLAVE_TO_SLAVE;
                break;
            default:
   	            /*nothing to do*/
                break;
        }

    }

    return RetVal;
}

#endif /* ( STD_ON == LIN_DRVW_MASTER_SUPPORT) */

/**
 *
 * @brief       This API set channel to sleep state and wait wakeup signal.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      Std_ReturnType
 * @retval      -E_NOT_OK:n case of a time-out situation only.
 * @retval      -E_OK:no error.
 * @retval      -LIN_DRVW_TIMEOUT_ERROR: timeout
 *
 */
Std_ReturnType Lin_Drvw_GoToSleepInternal(uint8 Channel)
{
    Std_ReturnType RetVal = (uint8)E_NOT_OK;
    uint8          LinId  = Lin_Drvw_HwChannelsConfigPtr[Channel]->LinHwChannel;
    Uart_Drv_StatusType TempRet;
    TempRet = Uart_Drv_StopTransfer(LinId);

    if (UART_DRV_STATUS_SUCCESS == TempRet)
    {
        (void)Uart_Drv_GoToSleepInternal(LinId);
        RetVal = (uint8)E_OK;        
    }
    else if(UART_DRV_STATUS_BUSY == TempRet)
    {
        RetVal = (uint8)LIN_DRVW_TIMEOUT_ERROR;
    }
    else
    {
        /*Nothing to do*/
    }

    return RetVal;
}

/**
 *
 * @brief       Sends a wake up signal to the LIN bus.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      None.
 *
 */
Std_ReturnType Lin_Drvw_Wakeup(const uint8 Channel)
{
    uint8 LinId = Lin_Drvw_HwChannelsConfigPtr[Channel]->LinHwChannel;

    return (Std_ReturnType)Uart_Drv_Wakeup(LinId);
    
}

/**
 *
 * @brief       Set instance to idle state.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      None.
 *
 */
void Lin_Drvw_WakeupInternal(uint8 Channel)
{
    uint8 LinId = Lin_Drvw_HwChannelsConfigPtr[Channel]->LinHwChannel;

    (void)Uart_Drv_SetIdleState(LinId);
}

#if (STD_ON == LIN_DRVW_SOFTWARE_POLLING )
/**
 *
 * @brief       Lin poll handle line state.
 *
 * @param[in]   Channel: LIN channel to be addressed.
 *
 * @return      None.
 *
 */
void Lin_Drvw_Poll(uint8 Channel)
{
    uint8 LinId = Lin_Drvw_HwChannelsConfigPtr[Channel]->LinHwChannel;
    Uart_Drv_PollingHandler(LinId);
}

#endif

/**
 *
 * @brief          LIN master callback.
 *
 * @param[in]      InstanceId: LIN hardware number.
 * @param[in]      StateStructPtr: Uart Lin driver state structure.
 *
 * @return         None.
 *
 */
/* SWS_Lin_00176 */
void Lin_Drvw_MasterCallback(const uint8 InstanceId, 
                             const Uart_Drv_TransferConfigType *StateStructPtr)
{
    uint8 Channel = Lin_Drvw_HwMappingArray[InstanceId];
    Uart_Drv_EventIdType NodeEventId = StateStructPtr->CurrentEventId;
    switch (NodeEventId)
    {       
        case UART_DRV_EVENT_TX_COMPLETED:            
            if (LIN_DRVW_TX_COMMAND_SLEEP == Lin_Drvw_TransmitCommandArray[Channel])
            {
                (void)Uart_Drv_GoToSleepInternal(InstanceId);
            }            
            break;

        case UART_DRV_EVENT_TIMEOUT_ERROR:            
        case UART_DRV_EVENT_READBACK_ERROR:
        case UART_DRV_EVENT_RX_OVERRUN_ERROR:             
            if (LIN_DRVW_TX_COMMAND_SLEEP == Lin_Drvw_TransmitCommandArray[Channel])
            {
                (void)Uart_Drv_StopTransfer(InstanceId);
                (void)Uart_Drv_GoToSleepInternal(InstanceId);
            }            
            break;

        case UART_DRV_EVENT_WAKEUP_SIGNAL:
            Lin_Drvw_WakeupFlagArray[Channel] = TRUE;
#if (STD_ON == LIN_DRVW_WAKEUP_DETECTION )
            if (TRUE == Lin_Drvw_HwChannelsConfigPtr[Channel]->LinChannelWakeupSupport)
            {
                EcuM_CheckWakeup(Lin_Drvw_HwChannelsConfigPtr[Channel]->LinChannelEcuMWakeupSource);
            }
#endif
            break;

        case UART_DRV_EVENT_RX_COMPLETED:  
        case UART_DRV_EVENT_CHECKSUM_ERROR:  
        case UART_DRV_EVENT_FRAME_ERROR:  
        case UART_DRV_NO_EVENT:
        default:            
	   /*nothing to do*/
            break;
    }
}

#if (STD_ON == LIN_DRVW_SLAVE_SUPPORT )
/**
 *
 * @brief          LIN slave callback.
 *
 * @param[in]      InstanceId: LIN hardware number.
 * @param[in]      StateStructPtr: Uart Lin driver state structure.
 *
 * @return         None.
 *
 */
/* SWS_Lin_00235, SWS_Lin_00176 */
void Lin_Drvw_SlaveCallback(const uint8 InstanceId, 
                                      const Uart_Drv_TransferConfigType *StateStructPtr)
{
    uint8 Channel = Lin_Drvw_HwMappingArray[InstanceId];
    Uart_Drv_EventIdType NodeEventId = StateStructPtr->CurrentEventId;
    switch (NodeEventId)
    {
        case UART_DRV_EVENT_RECV_HEADER_OK:
            Lin_Drvw_OperateSlaveResponse(InstanceId, StateStructPtr);
            break;

        case UART_DRV_EVENT_TX_COMPLETED:
            LinIf_TxConfirmation((NetworkHandleType)Channel);
            break;
        case UART_DRV_EVENT_RX_COMPLETED:
            (void)LinIf_RxIndication((NetworkHandleType)Channel, StateStructPtr->RxBuff);
            break;
        case UART_DRV_EVENT_TIMEOUT_ERROR:
        case UART_DRV_EVENT_READBACK_ERROR:  
        case UART_DRV_EVENT_RECV_HEADER_ERR:           
        case UART_DRV_EVENT_RX_OVERRUN_ERROR:            
            Lin_Drvw_IndicationSlaveError(InstanceId);   
            (void)Uart_Drv_StopTransfer(InstanceId);         
            break;
        case UART_DRV_EVENT_FRAME_ERROR:
            if (UART_DRV_NODE_STATE_RECV_HEADER == StateStructPtr->PreviousNodeState)
            {
                LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_HEADER);
            }
            else
            {
                LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_STOPBIT);
            }

            (void)Uart_Drv_StopTransfer(InstanceId);            
            break;
        case UART_DRV_EVENT_CHECKSUM_ERROR:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_CHKSUM);
            (void)Uart_Drv_StopTransfer(InstanceId);      
            break;

        case UART_DRV_EVENT_WAKEUP_SIGNAL:            
#if (STD_ON == LIN_DRVW_WAKEUP_DETECTION )
            if (TRUE == Lin_Drvw_HwChannelsConfigPtr[Channel]->LinChannelWakeupSupport)
            {
                EcuM_CheckWakeup(Lin_Drvw_HwChannelsConfigPtr[Channel]->LinChannelEcuMWakeupSource);
            }
#endif
            Lin_Drvw_WakeupFlagArray[Channel] = TRUE;
            break;

        case UART_DRV_NO_EVENT:      
        default:            
	   /*nothing to do*/
            break;
    }
}
#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Public_FunctionDefinition */
#ifdef __cplusplus
}
#endif

/** @} end of group Lin_Drvw */

/** @} end of group Lin_Module */
