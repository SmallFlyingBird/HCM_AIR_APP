/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-09-18 10:04:43>
 */
/*============================================================================*/

#ifndef DEM_CFG_H_
#define DEM_CFG_H_

/*******************************************************************************
**                       Version  information                                 **
*******************************************************************************/
#define DEM_CFG_SW_MAJOR_VERSION   1U
#define DEM_CFG_SW_MINOR_VERSION   0U
#define DEM_CFG_SW_PATCH_VERSION   1U

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_Types.h"
#include "Dem_CfgEnum.h"
#include "Rte_Dem.h"

/*******************************************************************************
*                          General Configuration
*******************************************************************************/
/* DemAvailabilitySupport type: Enum
#define DEM_EVENT_AVAILABILITY 1
#define DEM_NO_AVAILABILITY 2 */
#define DEM_AVAILABILITY_SUPPORT DEM_NO_AVAILABILITY

/* DemBswErrorBufferSize Range:0~255 */
#define DEM_BSW_ERROR_BUFFER_SIZE 0u

/* DemClearDTCBehavior type: Enum
#define DEM_CLRRESP_NONVOLATILE_FINISH 1
#define DEM_CLRRESP_NONVOLATILE_TRIGGER 2
#define DEM_CLRRESP_VOLATILE 3 */
#define DEM_CLEAR_DTCBEHAVIOR DEM_CLRRESP_NONVOLATILE_TRIGGER

/* DemClearDTCLimitation type: Enum
#define DEM_ALL_SUPPORTED_DTCS 1
#define DEM_ONLY_CLEAR_ALL_DTCS 2 */
#define DEM_CLEAR_DTCLIMITATION DEM_ALL_SUPPORTED_DTCS

/* DemDebounceCounterBasedSupport Range: true or false */
#define DEM_DEBOUNCE_COUNTER_BASED_SUPPORT STD_ON

/* DemDebounceTimeBasedSupport Range: true or false */
#define DEM_DEBOUNCE_TIME_BASED_SUPPORT STD_OFF

/* DemDevErrorDetect Range: true or false */
#define DEM_DEV_ERROR_DETECT STD_ON

/* DemEnvironmentDataCapture type: Enum
#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING 1
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING 2 */
#define DEM_ENVIRONMENT_DATA_CAPTURE DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING

/* DemEventCombinationSupport type: Enum
#define DEM_EVCOMB_DISABLED 1
#define DEM_EVCOMB_ONRETRIEVAL 2
#define DEM_EVCOMB_ONSTORAGE 3 */
#define DEM_EVENT_COMBINATION_SUPPORT DEM_EVCOMB_DISABLED

/* DemEventDisplacementStrategy type: Enum
#define DEM_DISPLACEMENT_FULL 1
#define DEM_DISPLACEMENT_NONE 2
#define DEM_DISPLACEMENT_PRIO_OCC 3 */
#define DEM_EVENT_DISPLACEMENT_STRATEGY DEM_DISPLACEMENT_FULL

/* DemEventMemoryEntryStorageTrigger type: Enum
#define DEM_TRIGGER_ON_CONFIRMED 1
#define DEM_TRIGGER_ON_FDC_THRESHOLD 2
#define DEM_TRIGGER_ON_PENDING 3
#define DEM_TRIGGER_ON_TEST_FAILED 4 */
#define DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER DEM_TRIGGER_ON_FDC_THRESHOLD

/* DemGeneralInterfaceSupport Range: true or false */
#define DEM_GENERAL_INTERFACE_SUPPORT STD_OFF

/* DemImmediateNvStorageLimit Range:1~255 */
#define DEM_IMMEDIATE_NV_STORAGE_LIMIT 0xffu

/* DemMaxNumberEventEntryEventBuffer Range:1~250 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_EVENT_BUFFER 30u

/* DemMaxNumberPrestoredFF Range:0~255 */
#define DEM_MAX_NUMBER_PRESTORED_FF 0u

/* DemOccurrenceCounterProcessing type: Enum
#define DEM_PROCESS_OCCCTR_CDTC 1
#define DEM_PROCESS_OCCCTR_TF 2 */ /*the occurrence counter is only
triggered by the TestFailed bit (and the fault confirmation is not considered) This parameter is mandatory in case of J1939*/
#define DEM_OCCURRENCE_COUNTER_PROCESSING DEM_PROCESS_OCCCTR_CDTC

/* DemOperationCycleStatusStorage Range: true or false */
#define DEM_OPERATION_CYCLE_STATUS_STORAGE STD_OFF

/*DemPTOSupport*/
#define DEM_PTO_SUPPORT STD_OFF

/* DemResetConfirmedBitOnOverflow Range: true or false */
#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW STD_OFF

/* DemGeneral/DemStatusBitHandlingTestFailedSinceLastClear
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT 1
#define DEM_STATUS_BIT_NORMAL 2 */
#define DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR DEM_STATUS_BIT_NORMAL

/* DemStatusBitStorageTestFailed Range: true or false */
#define DEM_STATUS_BIT_STORAGE_TEST_FAILED STD_OFF

/* DemSuppressionSupport type: Enum
#define DEM_DTC_SUPPRESSION 1
#define DEM_NO_SUPPRESSION 2 */
#define DEM_SUPPRESSION_SUPPORT DEM_DTC_SUPPRESSION

/* DemTaskTime */
#define DEM_TASK_TIME 10u

/* DemTriggerDcmReports Range: true or false */
#define DEM_TRIGGER_DCM_REPORTS STD_OFF

/* DemTriggerDltReports Range: true or false */
#define DEM_TRIGGER_DLT_REPORTS STD_OFF

/* DemTriggerFiMReports Range: true or false */
#define DEM_TRIGGER_FIM_REPORTS STD_OFF

/* DemTriggerMonitorInitBeforeClearOk Range: true or false */
#define DEM_TRIGGER_MONITOR_INIT_BEFORE_CLEAR_OK STD_OFF

/* DemTypeOfDTCSupported type: Enum
#define DEM_DTC_TRANSLATION_ISO11992_4 1
#define DEM_DTC_TRANSLATION_ISO14229_1 2
#define DEM_DTC_TRANSLATION_ISO15031_6 3
#define DEM_DTC_TRANSLATION_SAEJ1939_73 4
#define DEM_DTC_TRANSLATION_SAE_J2012_DA_DTCFORMAT_04 5 */
#define DEM_TYPE_OF_DTCSUPPORTED DEM_DTC_TRANSLATION_ISO11992_4

/* DemTypeOfFreezeFrameRecordNumeration type: Enum
#define DEM_FF_RECNUM_CALCULATED 1
#define DEM_FF_RECNUM_CONFIGURED 2 */
#define DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION DEM_FF_RECNUM_CONFIGURED

/* DemVersionInfoApi Range: true or false */
#define DEM_VERSION_INFO_API STD_OFF

/* COUNT(DemGeneral/DemCallbackDTCStatusChanged) 0-* */
#define DEM_CALLBACK_DTC_STATUS_CHANGED_NUM 0u

/* DemAgingRequieresTestedCycle Range: true or false */
#define DEM_AGING_REQUIERES_TESTED_CYCLE STD_ON

#define DEM_DEAL_MAINFUNCTION_ENABLE   STD_OFF

#define DEM_ENABLE_SOFT_FILTER_OF_PASS STD_OFF

#define DEM_NVRAM_DIVADED    STD_ON

/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
/*DemDataElementClass*/
#define DEM_DATA_ELEMENT_CLASS_NUM  18

#define DEM_EXTERAL_DATA_ELEMENT_CLASS_NUM  10u

/*******************************************************************************
*                          Condition Configuration
*******************************************************************************/
/* DemOperationCycle 1-256 */
#define DEM_OPERATION_CYCLE_NUM 2u

#define DemOperationCycle_No2_ID 0u
#define DemOperationCycle_No5_ID 1u

/* DemEnableCondition 0-255 */
#define DEM_ENABLE_CONDITION_NUM 43u

#define Condition_ElectricalPower_Limited_ID 0u
#define Condition_UsageModeTransition_ID 1u
#define Condition_CarModeTransition_ID 2u
#define Condition_CarModes_ID 3u
#define Condition_Usage_Active_Driving_ID 4u
#define Condition_FAN_Active_ID 5u
#define Condition_Channel_1_On_ID 6u
#define Condition_Channel_1_Off_ID 7u
#define Condition_Channel_2_On_ID 8u
#define Condition_Channel_2_Off_ID 9u
#define Condition_Channel_3_On_ID 10u
#define Condition_Channel_3_Off_ID 11u
#define Condition_Channel_4_On_ID 12u
#define Condition_Channel_4_Off_ID 13u
#define Condition_Channel_5_On_ID 14u
#define Condition_Channel_5_Off_ID 15u
#define Condition_Channel_6_On_ID 16u
#define Condition_Channel_6_Off_ID 17u
#define Condition_Channel_7_On_ID 18u
#define Condition_Channel_7_Off_ID 19u
#define Condition_Channel_8_On_ID 20u
#define Condition_Channel_8_Off_ID 21u
#define Condition_Output_HSD1_On_ID 22u
#define Condition_pHSD1OLEnable_Set_0_ID 23u
#define Condition_Output_Fan_On_ID 24u
#define Condition_ExtrLiRlyPwrDwn_Set_0_ID 25u
#define Condition_V_ecu_ID 26u
#define Condition_EIPowerLevel_1_ID 27u
#define Condition_Channel_9_On_ID 28u
#define Condition_Channel_9_Off_ID 29u
#define Condition_Channel_10_On_ID 30u
#define Condition_Channel_10_Off_ID 31u
#define Condition_Channel_11_On_ID 32u
#define Condition_Channel_11_Off_ID 33u
#define Condition_Channel_12_On_ID 34u
#define Condition_Channel_12_Off_ID 35u
#define Condition_Output_HSD2_On_ID 36u
#define Condition_pHSD2OLEnable_Set_0_ID 37u
#define Condition_Output_HSD3_On_ID 38u
#define Condition_pHSD3OLEnable_Set_0_ID 39u
#define Condition_UBat_12V_ID 40u
#define Condition_Usgmod_Driving_ID 41u
#define Condition_UBat_9_16V_ID 42u

/* DemEnableConditionGroup 0-255 */
#define DEM_ENABLE_CONDITION_GROUP_NUM 41u

/* DemEnableCondition 0-255 */
#define DEM_STORAGE_CONDITION_NUM 0u

/* DemStorageConditionGroup 0-255 */
#define DEM_STORAGE_CONDITION_GROUP_NUM 0u
/*******************************************************************************
*                          FreezeFrame Configuration
*******************************************************************************/
#define DEM_FFPRESTORAGE_SUPPORT   STD_OFF

/* DemSPNClass 0-0xFFFF */
#define DEM_SPN_CLASS_NUM 0u

#define DEM_J1939_FREEZE_FRAME_CLASS_NUM 0u

#define DEM_SPN_CLASS_REF_TOTAL_NUM 0u

/* DemDidClass 0-0xFFFF */
#define DEM_DID_CLASS_NUM 7u

/* DemFreezeFrameClass 0-65535 */
#define DEM_FREEZE_FRAME_CLASS_NUM 1u

/* SUM(COUNT(DemFreezeFrameClass/DemDidClassRef)) */
#define DEM_DID_CLASS_REF_TOTAL_NUM 7u

/* DemFreezeFrameRecordClass 0-255 */
#define DEM_FREEZE_FRAME_RECORD_CLASS_NUM 2u

#define DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)) */
#define DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM 2u

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
/* MAX(COUNT((DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)))  1-254 */
#define DEM_MAX_NUMBER_FF_RECORDS 2u
#endif

/* DemPidClass 0-0xFFFF */
#define DEM_PID_CLASS_NUM 0u
#define DEM_PID_TOTAL_SIZE  0u /*total size of all pid*/

/* max value of PID and all ref freezeframe size) */
#define DEM_FREEZE_FRAME_MAX_LEN 18u
/*******************************************************************************
*                          ExtendedData Configuration
*******************************************************************************/
/* DemExtendedDataRecordClass 0-253 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_NUM 11u

/* DemExtendedDataClass 0-* */
#define DEM_EXTENDED_DATA_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
/* PRQA S 0791++ */ /* MISRA Rule 5.4 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM  11u
/* PRQA S 0791-- */ /* MISRA Rule 5.4 */

/* MAX(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
#define DEM_EXTENDED_DATA_MAX_REF_NUM 11u

/* MAX(SUM(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef/DataSize)) */
#define DEM_EXTENDED_DATA_MAX_LEN 17u
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/
/* DemGroupOfDTC 0-255 */
#define DEM_GROUP_OF_DTC_NUM 0u

#define DEM_DTC_REF_EMISSION_NUM  0u

/* DemDTC 0-65535 */
#define DEM_DTC_NUM 135u

#define DEM_WWWOBD_NUM 0u

/* DemDTCAttributes 0-65535 */
#define DEM_DTC_ATTRIBUTES_NUM 12u

/* DemDtcStatusAvailabilityMask Range:0~255 */
#define DEM_DTC_STATUS_AVAILABILITY_MASK 0xffu

#define DEM_J1939_NODE_NUM 0u
#define DEM_J1939_NODEID_MAX_NUM  0u

/* DemObdDTC 0-65535 */
#define DEM_OBD_DTC_NUM 0u

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CALCULATED)
/* MAX(DemConfigSet/DemDTCAttributes/DemMaxNumberFreezeFrameRecords) */
#define DEM_MAX_NUMBER_FF_RECORDS 0u
#endif

/*******************************************************************************
*                          Indicator Configuration
*******************************************************************************/
/* DemIndicator 0..255 */
#define DEM_INDICATOR_NUM 0u

/*DemMILIndicatorRef*/
#define DEM_MALFUNCTION_LAMP_INDICATOR DemIndicator_INVALID

/*DemProtectLampIndicatorRef */
#define DEM_PROTECT_LAMP_INDICATOR DemIndicator_INVALID

/*DemRedStopLampIndicatorRef */
#define DEM_RED_STOP_LAMP_INDICATOR DemIndicator_INVALID

/*DemAmberWarningLampIndicatorRef */
#define DEM_AMBER_WARING_LAMP_INDICATOR DemIndicator_INVALID

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemIndicatorAttribute)) */
#define DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM 0u

/*******************************************************************************
*                          Debounce Configuration
*******************************************************************************/
/* DemDebounceCounterBasedClass 0-65535 */
#define DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM 13u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE ((DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased)
 *         && DemDebounceCounterBased/DemDebounceCounterBasedClassRef/DemDebounceCounterStorage == true) */
#define DEM_DEBOUNCE_COUNTER_STORAGE_NUM 0u

/* DemDebounceTimeBaseClass 0-65535 */
#define DEM_DEBOUNCE_TIME_BASE_CLASS_NUM 0u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceTimeBase) */
#define DEM_DEBOUNCE_TIME_BASED_EVENT_NUM 0u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased) */
#define DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM 135u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceMonitorInternal) */
#define DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM 0u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackEventStatusChanged))) */
#define DEM_CALLBACK_EVENT_STATUS_CHANGED_TOTAL_NUM 0u

/*******************************************************************************
*                          Event Configuration
*******************************************************************************/
/*DemComponentClass*/
#define DEM_COMPONENT_NUM 0u

#define DEM_IMMEDITE_CHILD_COMPONENT_MAX_NUM  0u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackClearEventAllowed))) */
#define DEM_CALLBACK_CLEAR_EVENT_ALLOWED_TOTAL_NUM 0u

/* DemEventParameter 1-65535 */
#define DEM_EVENT_PARAMETER_NUM 135u

#define DemEventParameter_0x505547  1u
#define DemEventParameter_0x90E714  2u
#define DemEventParameter_0x95B219  3u
#define DemEventParameter_0x95B319  4u
#define DemEventParameter_0x957011  5u
#define DemEventParameter_0x957015  6u
#define DemEventParameter_0x957911  7u
#define DemEventParameter_0x957915  8u
#define DemEventParameter_0x957A11  9u
#define DemEventParameter_0x957A15  10u
#define DemEventParameter_0x957E11  11u
#define DemEventParameter_0x957E15  12u
#define DemEventParameter_0x959011  13u
#define DemEventParameter_0x959015  14u
#define DemEventParameter_0x95A214  15u
#define DemEventParameter_0x95A301  16u
#define DemEventParameter_0x95A323  17u
#define DemEventParameter_0x95A324  18u
#define DemEventParameter_0x95A401  19u
#define DemEventParameter_0x95A771  20u
#define DemEventParameter_0x95A801  21u
#define DemEventParameter_0x95A813  22u
#define DemEventParameter_0x95A863  23u
#define DemEventParameter_0x95A901  24u
#define DemEventParameter_0x95A913  25u
#define DemEventParameter_0x95A963  26u
#define DemEventParameter_0x95AA11  27u
#define DemEventParameter_0x95AA12  28u
#define DemEventParameter_0x95AA13  29u
#define DemEventParameter_0x95AB11  30u
#define DemEventParameter_0x95AB12  31u
#define DemEventParameter_0x95AB13  32u
#define DemEventParameter_0x95AC11  33u
#define DemEventParameter_0x95AC12  34u
#define DemEventParameter_0x95AC13  35u
#define DemEventParameter_0x95AD11  36u
#define DemEventParameter_0x95AD12  37u
#define DemEventParameter_0x95AD13  38u
#define DemEventParameter_0x95AE11  39u
#define DemEventParameter_0x95AE12  40u
#define DemEventParameter_0x95AE13  41u
#define DemEventParameter_0x95AF11  42u
#define DemEventParameter_0x95AF12  43u
#define DemEventParameter_0x95AF13  44u
#define DemEventParameter_0x95B011  45u
#define DemEventParameter_0x95B012  46u
#define DemEventParameter_0x95B013  47u
#define DemEventParameter_0x95B111  48u
#define DemEventParameter_0x95B112  49u
#define DemEventParameter_0x95B113  50u
#define DemEventParameter_0x95B211  51u
#define DemEventParameter_0x95B215  52u
#define DemEventParameter_0x95B311  53u
#define DemEventParameter_0x95B315  54u
#define DemEventParameter_0x95B411  55u
#define DemEventParameter_0x95B415  56u
#define DemEventParameter_0x95D096  57u
#define DemEventParameter_0x95D196  58u
#define DemEventParameter_0x95D296  59u
#define DemEventParameter_0x95D309  60u
#define DemEventParameter_0x95D511  61u
#define DemEventParameter_0x95D512  62u
#define DemEventParameter_0x95B419  63u
#define DemEventParameter_0x960221  64u
#define DemEventParameter_0x961021  65u
#define DemEventParameter_0x961121  66u
#define DemEventParameter_0x961221  67u
#define DemEventParameter_0x961321  68u
#define DemEventParameter_0x961421  69u
#define DemEventParameter_0x961521  70u
#define DemEventParameter_0x961621  71u
#define DemEventParameter_0x968711  72u
#define DemEventParameter_0x968712  73u
#define DemEventParameter_0x968713  74u
#define DemEventParameter_0x968721  75u
#define DemEventParameter_0x968A11  76u
#define DemEventParameter_0x968A12  77u
#define DemEventParameter_0x968A13  78u
#define DemEventParameter_0x968A21  79u
#define DemEventParameter_0x96F511  80u
#define DemEventParameter_0x96F512  81u
#define DemEventParameter_0x96F513  82u
#define DemEventParameter_0x96F521  83u
#define DemEventParameter_0x96F611  84u
#define DemEventParameter_0x96F612  85u
#define DemEventParameter_0x96F613  86u
#define DemEventParameter_0x96F621  87u
#define DemEventParameter_0x982111  88u
#define DemEventParameter_0x982115  89u
#define DemEventParameter_0x982341  90u
#define DemEventParameter_0x9DFB01  91u
#define DemEventParameter_0xC03788  92u
#define DemEventParameter_0xD00246  93u
#define DemEventParameter_0xD00544  94u
#define DemEventParameter_0xE01449  95u
#define DemEventParameter_0xE01498  96u
#define DemEventParameter_0xE10156  97u
#define DemEventParameter_0xE79982  98u
#define DemEventParameter_0xE79A82  99u
#define DemEventParameter_0xED3E82  100u
#define DemEventParameter_0xED3E83  101u
#define DemEventParameter_0xED5A82  102u
#define DemEventParameter_0xED5A83  103u
#define DemEventParameter_0xED8B82  104u
#define DemEventParameter_0xED8B83  105u
#define DemEventParameter_0xED8C82  106u
#define DemEventParameter_0xED8C83  107u
#define DemEventParameter_0xEE0368  108u
#define DemEventParameter_0xEE0468  109u
#define DemEventParameter_0xEF0F86  110u
#define DemEventParameter_0xEF1068  111u
#define DemEventParameter_0xEF1168  112u
#define DemEventParameter_0xEF7001  113u
#define DemEventParameter_0xEF7101  114u
#define DemEventParameter_0xD66419  115u
#define DemEventParameter_0xF0001C  116u
#define DemEventParameter_0xF00362  117u
#define DemEventParameter_0xEF0E86  118u
#define DemEventParameter_0xEF7201  119u
#define DemEventParameter_0xD14B51  120u
#define DemEventParameter_0xD14C51  121u
#define DemEventParameter_0xEF1086  122u
#define DemEventParameter_0xEF1186  123u
#define DemEventParameter_0xE30057  124u
#define DemEventParameter_0x961087  125u
#define DemEventParameter_0x961187  126u
#define DemEventParameter_0x961287  127u
#define DemEventParameter_0x961387  128u
#define DemEventParameter_0x961487  129u
#define DemEventParameter_0x961587  130u
#define DemEventParameter_0x961687  131u
#define DemEventParameter_0x968787  132u
#define DemEventParameter_0x968A87  133u
#define DemEventParameter_0x96F587  134u
#define DemEventParameter_0x96F687  135u
/*******************************************************************************
*                          Memory Configuration
*******************************************************************************/
/* COUNT(DemGeneral/Dem<xx>Memory) */
#define DEM_MEM_DEST_TOTAL_NUM 1u

/* MAX(DemGeneral/Dem<XX>Memory/DemMaxNumberEventEntry<XX>) */
#define DEM_MEM_DEST_MAX_ENTRY_NUM 40u

/* DemMaxNumberEventEntryPermanent Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT 0u

/* DemPrimaryMemory 1-1 */
/* DemMaxNumberEventEntryPrimary Range:1~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY 40u

/* DemMirrorMemory 0-1 */
/* DemMaxNumberEventEntryMirror Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIRROR  0u

/*DemMaxNumberEventEntryUserDefined*/

/*DemUserDefinedMemoryIdentifier*/

/* COUNT(DemGeneral/DemNvRamBlockId) */
#define DEM_NVRAM_BLOCKID_NUM 41

/* MAX(DemConfigSet/DemDTCAttributes/DemMemoryDestinationRef) 0~2 */
#define DEM_MEM_DEST_MAX_NUM_OF_DTC 1u /* DemMemoryDestinationRef 0-2 */
/*******************************************************************************
*                          OBD Configuration
*******************************************************************************/
/*DemOBDSupport
 * #define DEM_OBD_DEP_SEC_ECU 1
#define DEM_OBD_MASTER_ECU 2
#define DEM_OBD_NO_OBD_SUPPORT 3
#define DEM_OBD_PRIMARY_ECU 4*/
#define DEM_OBD_SUPPORT DEM_OBD_NO_OBD_SUPPORT

#define DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM 0u

#define DEM_SECONDARY_FUNCTIONID_REF_MAX_NUM  2u

#define DEM_RATIO_NUM 0u

#define DEM_DTR_NUM 0u

/*******************************************************************************
*                          J1939 Configuration
*******************************************************************************/
#define DEM_J1939_SUPPORT STD_OFF

/*******************************************************************************
*                          Optimization Configuration
*******************************************************************************/
#define DEM_OCC6EANLE STD_ON
#define DEM_OCC4EANLE STD_ON
#define DEM_CYCLESSINCEFRISTFAILEDEANLE STD_ON
#define DEM_CYCLESSINCELASTFAILEDEANLE STD_ON
#define DEM_TRIGGERONFDCTHRESHOLDEANLE STD_ON
#define DEM_TRIGGERONTESTFAILEDEANLE STD_OFF
#define DEM_TRIGGERONPENDINGEDEANLE STD_OFF
#define DEM_TRIGGERONCONFIRMEDEDEANLE STD_ON
#define DEM_TRIGGERONPASSEDEANLE STD_OFF
#define DEM_TRIGGERONMIRROREANLE STD_OFF
#define DEM_ONEDTCMAPPINGMUTILEVENT STD_OFF

#endif /* DEM_CFG_H_ */
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

