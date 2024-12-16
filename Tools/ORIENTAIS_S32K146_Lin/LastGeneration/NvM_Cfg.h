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
**  FILENAME    : NvM_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2024/12/12 15:24:14                                 **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of NvM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef NVM_CFG_H
#define NVM_CFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#define NVM_CFG_H_AR_MAJOR_VERSION 4U
#define NVM_CFG_H_AR_MINOR_VERSION 2U
#define NVM_CFG_H_AR_PATCH_VERSION 2U

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define NVM_API_CONFIG_CLASS                            NVM_API_CONFIG_CLASS_3
#define NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION        STD_OFF
#define NVM_BSWM_SINGLEBLOCK_JOBSTATUS_INFORMATION      STD_OFF
#define NVM_COMPILED_CONFIG_ID                          (0x3u)
#define NVM_CRC_NUM_OF_BYTES                              (0x80u)        
#define NVM_DATASET_SELECTION_BITS                      (0x8u)
#define NVM_DEV_ERROR_DETECT                            STD_ON
#define NVM_DRV_MODE_SWITCH                                 STD_ON
#define NVM_DYNAMIC_CONFIGURATION                         STD_OFF
#define NVM_JOB_PRIORITIZATION                            STD_OFF
#define NVM_POLLING_MODE                                STD_OFF
#define NVM_REPEAT_MIRROR_OPERATIONS                      (0x0u)
#define NVM_SET_RAM_BLOCK_STATUS_API                    STD_OFF
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE                    (0x0u)
#define NVM_SIZE_STANDARD_JOB_QUEUE                        (0x2au)
#define NVM_VERSION_INFO_API                            STD_OFF
#define NVM_INCLUDE_CRC                                 STD_ON
#define NVM_CRC_TYPE_8                                  STD_OFF
#define NVM_CRC_TYPE_16                                 STD_ON
#define NVM_CRC_TYPE_32                                 STD_OFF
#define NVM_DEM_PRODUCTION_ERROR_DETECT                    STD_OFF


/*The following definitions used to index NVM block for SW */
#define NvMBlock_DCMSec               2
#define NvMBlock_DemEntry_0               3
#define NvMBlock_DemEntry_1               4
#define NvMBlock_DemEntry_2               5
#define NvMBlock_DemEntry_3               6
#define NvMBlock_DemEntry_4               7
#define NvMBlock_DemEntry_5               8
#define NvMBlock_DemEntry_6               9
#define NvMBlock_DemEntry_7               10
#define NvMBlock_DemEntry_8               11
#define NvMBlock_DemEntry_9               12
#define NvMBlock_DemEntry_10               13
#define NvMBlock_DemEntry_11               14
#define NvMBlock_DemEntry_12               15
#define NvMBlock_DemEntry_13               16
#define NvMBlock_DemEntry_14               17
#define NvMBlock_DemEntry_15               18
#define NvMBlock_DemEntry_16               19
#define NvMBlock_DemEntry_17               20
#define NvMBlock_DemEntry_18               21
#define NvMBlock_DemEntry_19               22
#define NvMBlock_DemEntry_20               23
#define NvMBlock_DemEntry_21               24
#define NvMBlock_DemEntry_22               25
#define NvMBlock_DemEntry_23               26
#define NvMBlock_DemEntry_24               27
#define NvMBlock_DemEntry_25               28
#define NvMBlock_DemEntry_26               29
#define NvMBlock_DemEntry_27               30
#define NvMBlock_DemEntry_28               31
#define NvMBlock_DemEntry_29               32
#define NvMBlock_DemEntry_30               33
#define NvMBlock_DemEntry_31               34
#define NvMBlock_DemEntry_32               35
#define NvMBlock_DemEntry_33               36
#define NvMBlock_DemEntry_34               37
#define NvMBlock_DemEntry_35               38
#define NvMBlock_DemEntry_36               39
#define NvMBlock_DemEntry_37               40
#define NvMBlock_DemEntry_DemVersion               41
#define NvMBlock_DemEntry_OBD               42
#define NvMBlock_DemEventInfo               43

/*The total number of user configured*/
#define NVM_BLOCK_NUM_ALL                                 43
#define NVM_REDUNDANT_ALL                                  1

#define NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR                2U

#define NVM_MAX_LENGTH_NV_BLOCK                            200U
#define NVM_MAX_LENGTH_REDUNDANT_BLOCK                    2U

#if((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON == NVM_JOB_PRIORITIZATION))
/*The total number of different priority*/
#define NVM_TOTAL_NUM_DIFF_PRI                             NVM_TABLE_SIZE_PRIORITY
#endif

#if(STD_ON==NVM_JOB_PRIORITIZATION)
/* The priority table size*/
#define NVM_TABLE_SIZE_PRIORITY                          2U
#endif

#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer9[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer10[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer11[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer12[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer13[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer14[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer15[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer16[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer17[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer18[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer19[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer20[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer21[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer22[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer23[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer24[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer25[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer26[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer27[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer28[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer29[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer30[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer31[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer32[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer33[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer34[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer35[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer36[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer37[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer38[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer39[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer40[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer41[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer42[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer43[200];
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

#endif /* End of NVM_CFG_H*/
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

