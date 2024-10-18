
/**************************************************************************************************/
/**
 * @file      : Can_Drv_PBcfg.c  
 * @brief     : Can low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Drv_Configuration
 *  @brief Can low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


    

#include "Can_Drv.h"
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
    #include "Dma_Drv.h"
#endif


/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CAN_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define CAN_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define CAN_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define CAN_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define CAN_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define CAN_DRV_PBCFG_C_SW_PATCH_VERSION            1U


/* Check if current file and Can_drv header file are of the same vendor */
#if (CAN_DRV_PBCFG_C_VENDOR_ID != CAN_DRV_H_VENDOR_ID)
    #error "Vendor id of Can_Drv_PBcfg.c and Can_Drv.h are different "
#endif

#if ((CAN_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION   != CAN_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != CAN_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (CAN_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != CAN_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Can_Drv_PBcfg.c  and Can_Drv.h are different"
#endif

#if ((CAN_DRV_PBCFG_C_SW_MAJOR_VERSION != CAN_DRV_H_SW_MAJOR_VERSION) || \
     (CAN_DRV_PBCFG_C_SW_MINOR_VERSION != CAN_DRV_H_SW_MINOR_VERSION) || \
     (CAN_DRV_PBCFG_C_SW_PATCH_VERSION != CAN_DRV_H_SW_PATCH_VERSION) \
    )
    #error "AutoSar Version of Can_Drv_PBcfg.c  and Can_Drv.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against current file and Dma_Drv.h */
    #if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
        #if ((CAN_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION   != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
            (CAN_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != DMA_DRV_H_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version of Can_Drv_PBcfg.c and Dma_Drv.h are different"
        #endif
    #endif
#endif

/** @} end of Private_MacroDefinition */



/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

extern void Can_MbIrqCallback(uint8 Instance, Can_Drv_IntType InterType, uint32 MbIdx,
                       const Can_Drv_StateType * StatePtr);
extern void Can_ErrorIrqCallback(uint8 Id, Can_Drv_IntType InterType, uint32 Data);

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
/** @} end of group Public_FunctionDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"




const Can_Drv_ConfigType Can_Drv_CtrlConfig[1U]=
{
    /* Can Hardware Channel CAN_6 */
    {
        /* The maximum number of Message Buffers .MbMaxNum*/
        (uint8)73U,(boolean)FALSE,
        /*The number of RX FIFO ID filters needed.RxFifoIdFilterNum */
        (Can_Drv_RxFifoFilterNumType)0U,
        /* Specifies if the Rx FIFO uses interrupts or DMA .TransferType */
        CAN_DRV_RXFIFO_INTERRUPTS,
        /* CAN operation modes .Mode */
        CAN_DRV_MODE_NORMAL,
        /*   Enable of BitRate Switch support for FD frames .BitRateSwitch */
        (boolean)FALSE,
        /* The bitrate used for standard frames or for the arbitration phase of FD frames .BitTiming */
        {
            (uint8)6U,
            (uint8)3U,
            (uint8)2U,
            (uint16)4U,
            (uint8)2U
        },
        
        (boolean)FALSE,
        
        
        {
            CAN_DRV_OBJECT_PL_8,
            CAN_DRV_OBJECT_PL_8,
            CAN_DRV_OBJECT_PL_8,
            CAN_DRV_OBJECT_PL_8
        },
        
        {
            (uint8)6U,
            (uint8)3U,
            (uint8)2U,
            (uint16)4U,
            (uint8)2U
        },
        
        (uint32)((0x00000000U)),
        #if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* Specifies the DMA Channel number to be used for DMA transfers. */
        (uint8)0U,
        #endif
        /* Controller Callback .Callback */
        Can_MbIrqCallback,
        /* Error Callback .ErrorCallback */
        Can_ErrorIrqCallback
    }
};



#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */


#ifdef __cplusplus
}
#endif

/** @} end of group Can_Drv_Configuration */

/** @} end of group Can_Module */
