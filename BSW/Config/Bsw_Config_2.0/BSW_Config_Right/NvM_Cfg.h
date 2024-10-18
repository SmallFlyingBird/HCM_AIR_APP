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
**  FILENAME    : NvM_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2024/07/10 18:28:35                                 **
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
#define NVM_CFG_SW_MAJOR_VERSION 2U
#define NVM_CFG_SW_MINOR_VERSION 0U
#define NVM_CFG_SW_PATCH_VERSION 0U

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
#define NVM_COMPILED_CONFIG_ID                          (0xaabbu)
#define NVM_CRC_NUM_OF_BYTES                              (0x80u)
#define NVM_DATASET_SELECTION_BITS                      (0x8u)
#define NVM_DEV_ERROR_DETECT                            STD_OFF
#define NVM_DRV_MODE_SWITCH                                 STD_OFF
#define NVM_DYNAMIC_CONFIGURATION                         STD_OFF
#define NVM_JOB_PRIORITIZATION                            STD_OFF
#define NVM_POLLING_MODE                                STD_ON
#define NVM_REPEAT_MIRROR_OPERATIONS                      (0x5u)
#define NVM_SET_RAM_BLOCK_STATUS_API                    STD_ON
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE                    (0x0u)
#define NVM_SIZE_STANDARD_JOB_QUEUE                        (0x32u)
#define NVM_VERSION_INFO_API                            STD_OFF
#define NVM_INCLUDE_CRC                                 STD_ON
#define NVM_CRC_TYPE_8                                  STD_OFF
#define NVM_CRC_TYPE_16                                 STD_ON
#define NVM_CRC_TYPE_32                                 STD_OFF
#define NVM_DEM_PRODUCTION_ERROR_DETECT                    STD_OFF

#define NVM_DEM_E_HARDWARE                                STD_OFF
#define NVM_DEM_E_INTEGRITY_FAILED                        STD_OFF
#define NVM_DEM_E_LOSS_OF_REDUNDANCY                      STD_OFF
#define NVM_DEM_E_REQ_FAILED                              STD_OFF
#define NVM_DEM_E_VERIFY_FAILED                           STD_OFF
#define NVM_DEM_E_WRITE_PROTECTED                         STD_OFF
#define NVM_DEM_E_WRONG_BLOCK_ID                          STD_OFF

/*The following definitions used to index NVM block for SW */
#define Nvm_Block_DCM               2U
#define NvM_Block_NmHistory               3U
#define NvMBlock_UDS_InternalData               4U
#define NvMBlock_EventEntryPrimary_1               5U
#define NvMBlock_EventEntryPrimary_2               6U
#define NvMBlock_EventEntryPrimary_3               7U
#define NvMBlock_EventEntryPrimary_4               8U
#define NvMBlock_EventEntryPrimary_5               9U
#define NvMBlock_EventEntryPrimary_6               10U
#define NvMBlock_EventEntryPrimary_7               11U
#define NvMBlock_EventEntryPrimary_8               12U
#define NvMBlock_EventEntryPrimary_9               13U
#define NvMBlock_EventEntryPrimary_10               14U
#define NvMBlock_EventEntryPrimary_11               15U
#define NvMBlock_EventEntryPrimary_12               16U
#define NvMBlock_EventEntryPrimary_13               17U
#define NvMBlock_EventEntryPrimary_14               18U
#define NvMBlock_EventEntryPrimary_15               19U
#define NvMBlock_EventEntryPrimary_16               20U
#define NvMBlock_EventEntryPrimary_17               21U
#define NvMBlock_EventEntryPrimary_18               22U
#define NvMBlock_EventEntryPrimary_19               23U
#define NvMBlock_EventEntryPrimary_20               24U
#define NvMBlock_EventEntryPrimary_21               25U
#define NvMBlock_EventEntryPrimary_22               26U
#define NvMBlock_EventEntryPrimary_23               27U
#define NvMBlock_EventEntryPrimary_24               28U
#define NvMBlock_EventEntryPrimary_25               29U
#define NvMBlock_EventEntryPrimary_26               30U
#define NvMBlock_EventEntryPrimary_27               31U
#define NvMBlock_EventEntryPrimary_28               32U
#define NvMBlock_EventEntryPrimary_29               33U
#define NvMBlock_EventEntryPrimary_30               34U
#define NvMBlock_EventEntryPrimary_31               35U
#define NvMBlock_EventEntryPrimary_32               36U
#define NvMBlock_EventEntryPrimary_33               37U
#define NvMBlock_EventEntryPrimary_34               38U
#define NvMBlock_EventEntryPrimary_35               39U
#define NvMBlock_EventEntryPrimary_36               40U
#define NvMBlock_EventEntryPrimary_37               41U
#define NvMBlock_EventEntryPrimary_38               42U
#define NvMBlock_EventEntryPrimary_39               43U
#define NvMBlock_EventEntryPrimary_40               44U
#define NvMBlock_LightShowExtFlag               45U

/*The total number of user configured*/
#define NVM_BLOCK_NUM_ALL                                 45
#define NVM_REDUNDANT_ALL                                  1

#define NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR                0U

#define NVM_MAX_LENGTH_NV_BLOCK                            500U
#define NVM_MAX_LENGTH_REDUNDANT_BLOCK                    2U

#if (STD_ON==NVM_JOB_PRIORITIZATION)
/* The priority table size*/
#define NVM_TABLE_SIZE_PRIORITY                          2U
/*The total number of different priority*/
#define NVM_TOTAL_NUM_DIFF_PRI                             NVM_TABLE_SIZE_PRIORITY
#endif

extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[200];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[64];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[500];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer9[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer10[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer11[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer12[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer13[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer14[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer15[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer16[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer17[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer18[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer19[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer20[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer21[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer22[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer23[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer24[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer25[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer26[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer27[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer28[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer29[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer30[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer31[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer32[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer33[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer34[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer35[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer36[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer37[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer38[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer39[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer40[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer41[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer42[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer43[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer44[74];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer45[62];

#endif /* End of NVM_CFG_H*/
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

