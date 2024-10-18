/***************************************************************************************************/
/**
 * @file      : Can_Irq.c
 * @brief     : Can Interrupt source file
 *                - Platform: Z20K14xM
 *                - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Can_Module
 *  @{
 */

/** @addtogroup Can_Irq
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Can.h"
#include "Can_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CAN_IRQ_C_VENDOR_ID                   0x00B3U
#define CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define CAN_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define CAN_IRQ_C_SW_MAJOR_VERSION            1U
#define CAN_IRQ_C_SW_MINOR_VERSION            2U
#define CAN_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Can.h are the same vendor */
#if (CAN_IRQ_C_VENDOR_ID != CAN_VENDOR_ID)
    #error "Vendor ID of  Can_Irq.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Autosar version */
#if ((CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION) ||                       \
     (CAN_IRQ_C_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION) ||                       \
     (CAN_IRQ_C_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Can_Irq.c and Can.h are different"
#endif

/* Check if current file and Can.h are of the same Software version */
#if ((CAN_IRQ_C_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION) ||                                       \
     (CAN_IRQ_C_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION) ||                                       \
     (CAN_IRQ_C_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
    #error "Software Version of Can_Irq.c and Can.h are different"
#endif

/* Check if current file and Can_Drv.h are the same vendor */
#if (CAN_IRQ_C_VENDOR_ID != CAN_DRV_H_VENDOR_ID)
    #error "Vendor ID of  Can_Irq.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION != CAN_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (CAN_IRQ_C_AR_RELEASE_MINOR_VERSION != CAN_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (CAN_IRQ_C_AR_RELEASE_REVISION_VERSION != CAN_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Can_Irq.c and Can_Drv.h are different"
#endif

/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_IRQ_C_SW_MAJOR_VERSION != CAN_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (CAN_IRQ_C_SW_MINOR_VERSION != CAN_DRV_H_SW_MINOR_VERSION) ||                                 \
     (CAN_IRQ_C_SW_PATCH_VERSION != CAN_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Can_Irq.c and Can_Drv.h are different"
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

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (CAN_DRV_MB_INTERRUPT_SUPPORT == STD_ON)
void Can_MbIrqCallback(uint8 Instance, Can_Drv_IntType InterType, uint32 MbIdx,
                       const Can_Drv_StateType *StatePtr);

/**
 * @brief     This function processes message buffer interrupt.
 *
 * @param[in] Instance: Hardware channel id.
 * @param[in] InterType: Interrupt Type
 * @param[in] MbIdx:  Message buffer id.
 * @param[in] StatePtr: Pointer to store the controller state.
 * 
 * @return    None
 *
 */
void Can_MbIrqCallback(uint8 Instance, Can_Drv_IntType InterType, uint32 MbIdx,
                       const Can_Drv_StateType *StatePtr)
{

    #if (CAN_DRV_MB_INTERRUPT_SUPPORT == STD_ON)
    /* This callback  used for mailbox interrupt */
    if (FALSE == (StatePtr->Mb[MbIdx].IsPolling))
    {
        switch (InterType)
        {
            case CAN_DRV_MB_TRANSMIT:
            {
                Can_ProcessMbCommonInterrupt(Instance, (uint8)MbIdx, CAN_OBJ_TRANSMIT);
                break;
            }
            case CAN_DRV_INT_MB_RECEIVE:
            {
                Can_ProcessMbCommonInterrupt(Instance, (uint8)MbIdx, CAN_OBJ_RECEIVE);
                break;
            }
            case CAN_DRV_INT_RXFIFO_FRAME:
            {
                Can_ProcessMbCommonInterrupt(Instance, (uint8)MbIdx, CAN_OBJ_FIFO);
                break;
            }
            case CAN_DRV_INT_RXFIFO_WARNING:
            {
                Can_ProcessMbCommonInterrupt(Instance, CAN_DRV_RXFIFO_WARNING, CAN_OBJ_FIFO);
                break;
            }
            case CAN_DRV_INT_RXFIFO_OVERFLOW:
            {
                Can_ProcessMbCommonInterrupt(Instance, CAN_DRV_RXFIFO_OVERFLOW, CAN_OBJ_FIFO);
                break;
            }
            default:
            {
                /* Nothing to do */
                break;
            }
        }
    }
    #endif
    #if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
    else if ((CAN_DRV_DMA_COMPLETE == InterType) || (CAN_DRV_DMA_ERROR == InterType))
    {
        Can_ProcessRxFiFoDmaInterrupt(Instance, InterType);
    }
    else
    {
        /* Nothing to do */
    }
    #endif
}
#endif

void Can_ErrorIrqCallback(uint8 Instance, Can_Drv_IntType InterType, uint32 Data);
/**
 * @brief     This function processes error interrupt.
 *
 * @param[in] Instance: Hardware channel id.
 * @param[in] InterType: Interrupt type
 * @param[in] Data: Error status.
 * 
 * @return    None
 *
 */
void Can_ErrorIrqCallback(uint8 Instance, Can_Drv_IntType InterType, uint32 Data)
{
    switch (InterType)
    {
#if (CAN_DRV_ERROR_INTERRUPT_SUPPORT == STD_ON)
        case CAN_DRV_INT_ERR:
        {
            Can_ProcessErrorInterrupt(Instance, (boolean)FALSE, Data);
            break;
        }
    #if (CAN_DRV_FD_MODE_ENABLE == STD_ON)
        case CAN_DRV_INT_ERR_FAST:
        {
            Can_ProcessErrorInterrupt(Instance, (boolean)TRUE, Data);
            break;
        }
    #endif
#endif
        /* this function is called for bus off */
        case CAN_DRV_INT_BUS_OFF:
        {
            Can_ProcessBusOffInterrupt(Instance);
            break;
        }
#if (CAN_WAKEUP_SUPPORT == STD_ON)
        case CAN_DRV_INT_SELF_WAKEUP:
        {
            Can_ProcessSelfWakeup(Instance);
            break;
        }
#endif

        case CAN_DRV_INT_HOST_MEM_ERR:
        case CAN_DRV_INT_MEM_ERR:
        case CAN_DRV_INT_COR_MEM_ERR:
        {
#if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
            Can_ProcessEccInterrupt(Instance, (uint32)InterType, Data);
#endif
            break;
        }

        default:
        {
            /* Nothing to do */
            break;
        }
    }
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Can_Irq */

/** @} end of group Can_Module */
