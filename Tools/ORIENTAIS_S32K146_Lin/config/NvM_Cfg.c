
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
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
**  Created on  : 2024/12/16 14:21:14                                 **
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

#include "Rte_Diag.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#define NVM_CFG_C_AR_MAJOR_VERSION 4U
#define NVM_CFG_C_AR_MINOR_VERSION 2U
#define NVM_CFG_C_AR_PATCH_VERSION 2U

/********************************************************
 ****Container for NvmMultiBlockCallback
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
CONST(NvM_MultiBlockCallbackType, NVM_CONST) NvmMultiBlockCallback = Rte_NvMNotifyJobFinished_MultiBlock;
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer9[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer10[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer11[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer12[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer13[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer14[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer15[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer16[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer17[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer18[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer19[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer20[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer21[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer22[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer23[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer24[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer25[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer26[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer27[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer28[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer29[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer30[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer31[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer32[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer33[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer34[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer35[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer36[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer37[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer38[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer39[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer40[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer41[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer42[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer43[200];
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

/********************************************************
 ****Container for a management structure to configure the
composition of a given NVRAM Block Management Type.
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h" 
CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[NVM_BLOCK_NUM_ALL] = 
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
        0,    /*NvMMaxNumOfReadRetries*/
        0,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer1),    /*NvmRamBlockDataAddress*/
        NULL_PTR,   /*NvmRomBlockDataAddress*/
        NULL_PTR,   /*NvmInitBlockCallback*/
        NULL_PTR,   /*NvmSingleBlockCallback*/
        NULL_PTR,   /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,   /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DCMSec*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer2),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        Rte_NvMNotifyJobFinished_NvMBlock_DCMSec,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_0*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer3),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_1*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer4),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_2*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer5),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_3*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer6),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_4*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer7),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_5*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer8),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_6*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer9),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_7*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer10),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_8*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer11),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_9*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer12),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_10*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer13),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_11*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer14),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_12*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer15),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_13*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer16),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_14*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer17),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_15*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer18),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_16*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer19),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_17*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer20),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_18*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer21),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_19*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer22),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_20*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer23),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_21*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer24),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_22*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer25),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_23*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer26),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_24*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer27),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_25*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer28),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_26*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer29),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_27*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer30),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_28*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer31),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_29*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer32),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_30*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer33),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_31*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer34),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_32*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer35),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_33*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer36),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_34*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer37),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_35*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer38),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_36*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer39),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_37*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer40),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_DemVersion*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer41),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEntry_OBD*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        32,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer42),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_DemEventInfo*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x18,
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
        200,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        1,    /*NvMMaxNumOfReadRetries*/
        1,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer43),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
};
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#if((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
#define NVM_START_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
VAR(uint16, NVM_VAR_POWER_ON_INIT) NvM_PriorityTable[2][NVM_TABLE_SIZE_PRIORITY] =
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

