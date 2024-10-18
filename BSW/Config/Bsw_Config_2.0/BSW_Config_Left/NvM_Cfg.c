
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : NvM_Cfg.c                                                   **
**                                                                            **
**  Created on  : 2024/07/10 18:28:35                                 **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of NvM                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/ 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "NvM_Types.h"
#include "NvM_Cfg.h"

/********************************************************
 ****Container for NvmMultiBlockCallback
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(NvM_MultiBlockCallbackType, NVM_CONST) NvmMultiBlockCallback = NULL_PTR;
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

/* PRQA S 1504++ */ /* MISRA Rule 8.7 */
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[200];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[64];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[500];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer9[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer10[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer11[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer12[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer13[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer14[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer15[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer16[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer17[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer18[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer19[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer20[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer21[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer22[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer23[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer24[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer25[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer26[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer27[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer28[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer29[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer30[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer31[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer32[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer33[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer34[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer35[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer36[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer37[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer38[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer39[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer40[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer41[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer42[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer43[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer44[74];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer45[62];
/* PRQA S 1504-- */ /* MISRA Rule 8.7 */
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

/********************************************************
 ****Container for a management structure to configure the
composition of a given NVRAM Block Management Type.
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[NVM_BLOCK_NUM_ALL] =
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
{
    /*NvMBlock_ConfigID*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_REDUNDANT,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x3c,
       /*
        * Bit 0:NvmWriteBlockOnce
        * Bit 1:NvmBlockWriteProt
        * Bit 2:NvmCalcRamBlockCrc
        * Bit 3:NvmResistantToChangedSw
        * Bit 4:NvmSelectBlockForReadall
        * Bit 5:NvmSelectBlockForWriteall
        * Bit 6:NvMStaticBlockIDCheck
        * Bit 7:NvMWriteVerification
        * Bit 8:NvMBlockUseAutoValidation
        * Bit 9:NvMBlockUseCRCCompMechanism
        * Bit 10:NvMBlockUseSetRamBlockStatus
        * Bit 11:NvMBlockUseSyncMechanism
        * Bit 12:NvMBswMBlockStatusInformation
        */
        NVM_CRC16,    /*NvmBlockCRCType*/
        1,    /*NvmNvBlockBaseNumber*/
        2,    /*NvmNvBlockLength*/
        2,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer1),    /*NvmRamBlockDataAddress*/
        NULL_PTR,   /*NvmRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvmInitBlockCallback*/
        NULL_PTR,   /*NvmSingleBlockCallback*/
        NULL_PTR,   /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,   /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*Nvm_Block_DCM*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        3,    /*NvmNvBlockBaseNumber*/
        200,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer2),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvM_Block_NmHistory*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        44,    /*NvmNvBlockBaseNumber*/
        64,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer3),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_UDS_InternalData*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        2,    /*NvmNvBlockBaseNumber*/
        500,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer4),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_1*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        4,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer5),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_2*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        5,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer6),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_3*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        6,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer7),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_4*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        7,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer8),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_5*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        8,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer9),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_6*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        9,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer10),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_7*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        10,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer11),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_8*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        11,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer12),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_9*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        12,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer13),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_10*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        13,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer14),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_11*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        14,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer15),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_12*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        15,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer16),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_13*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        16,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer17),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_14*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        17,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer18),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_15*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        18,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer19),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_16*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        19,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer20),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_17*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        20,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer21),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_18*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        21,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer22),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_19*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        22,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer23),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_20*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        23,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer24),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_21*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        24,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer25),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_22*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        25,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer26),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_23*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        26,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer27),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_24*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        27,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer28),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_25*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        28,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer29),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_26*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        29,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer30),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_27*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        30,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer31),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_28*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        31,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer32),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_29*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        32,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer33),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_30*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        33,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer34),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_31*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        34,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer35),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_32*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        35,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer36),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_33*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        36,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer37),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_34*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        37,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer38),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_35*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        38,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer39),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_36*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        39,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer40),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_37*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        40,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer41),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_38*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        41,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer42),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_39*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        42,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer43),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_40*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        43,    /*NvmNvBlockBaseNumber*/
        74,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer44),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_LightShowExtFlag*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        45,    /*NvmNvBlockBaseNumber*/
        62,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432,0306++ */ /* MISRA Rule 20.7,Rule 11.4 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer45),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432,0306-- */ /* MISRA Rule 20.7,Rule 11.4 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
};
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
#define NVM_START_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
VAR(uint16, NVM_VAR_POWER_ON_INIT) NvM_PriorityTable[2][NVM_TABLE_SIZE_PRIORITY] =
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
{

    {
        0x0000U,0x0000U
    },
    {
        0x0000U,0x0000U
    }
};
#define NVM_STOP_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
#endif
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

