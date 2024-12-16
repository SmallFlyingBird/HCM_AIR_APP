/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-12 15:24:13>
 */
/*============================================================================*/


#ifndef DEM_CFG_H_
#define DEM_CFG_H_

/*******************************************************************************
**                       Version  information                                 **
*******************************************************************************/
#define DEM_CFG_H_AR_MAJOR_VERSION   4U
#define DEM_CFG_H_AR_MINOR_VERSION   2U
#define DEM_CFG_H_AR_PATCH_VERSION   2U
#define DEM_CFG_H_SW_MAJOR_VERSION   1U
#define DEM_CFG_H_SW_MINOR_VERSION   0U
#define DEM_CFG_H_SW_PATCH_VERSION   0U

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_CfgEnum.h"
/*******************************************************************************
*                          General Configuration
*******************************************************************************/
/* DemAvailabilitySupport type: Enum
#define DEM_EVENT_AVAILABILITY 1
#define DEM_NO_AVAILABILITY 2 */
#define DEM_AVAILABILITY_SUPPORT DEM_EVENT_AVAILABILITY

/* DemBswErrorBufferSize Range:0~255 */
#define DEM_BSW_ERROR_BUFFER_SIZE 80u

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
#define DEM_DEBOUNCE_TIME_BASED_SUPPORT STD_ON

/* DemDevErrorDetect Range: true or false */
#define DEM_DEV_ERROR_DETECT STD_OFF

/* DemEnvironmentDataCapture type: Enum
#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING 1
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING 2 */
#define DEM_ENVIRONMENT_DATA_CAPTURE DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING

/* DemEventCombinationSupport type: Enum
#define DEM_EVCOMB_DISABLED 1
#define DEM_EVCOMB_ONRETRIEVAL 2
#define DEM_EVCOMB_ONSTORAGE 3 */
#define DEM_EVENT_COMBINATION_SUPPORT DEM_EVCOMB_ONSTORAGE

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
#define DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER DEM_TRIGGER_ON_TEST_FAILED

/* DemGeneralInterfaceSupport Range: true or false */
#define DEM_GENERAL_INTERFACE_SUPPORT STD_OFF

/* DemImmediateNvStorageLimit Range:1~255 */
#define DEM_IMMEDIATE_NV_STORAGE_LIMIT 0xffu

/* DemMaxNumberEventEntryEventBuffer Range:1~250 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_EVENT_BUFFER 0u

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
#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW STD_ON

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
#define DEM_TYPE_OF_DTCSUPPORTED DEM_DTC_TRANSLATION_ISO15031_6

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
/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
/*DemDataElementClass*/
#define DEM_DATA_ELEMENT_CLASS_NUM  6

#define DEM_EXTERAL_DATA_ELEMENT_CLASS_NUM  5u

/*******************************************************************************
*                          Condition Configuration
*******************************************************************************/
/* DemOperationCycle 1-256 */
#define DEM_OPERATION_CYCLE_NUM 1u

#define DemOperationCycle_IG_ID 0u

/* DemEnableCondition 0-255 */
#define DEM_ENABLE_CONDITION_NUM 3u

#define EnableCondition_Voltage_ID 0u
#define EnableCondition_VehState_ID 1u
#define EnableCondition_Powered3S_ID 2u

/* DemEnableConditionGroup 0-255 */
#define DEM_ENABLE_CONDITION_GROUP_NUM 3u

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
#define DEM_DID_CLASS_NUM 1u

/* DemFreezeFrameClass 0-65535 */
#define DEM_FREEZE_FRAME_CLASS_NUM 1u

/* SUM(COUNT(DemFreezeFrameClass/DemDidClassRef)) */
#define DEM_DID_CLASS_REF_TOTAL_NUM 1u

/* DemFreezeFrameRecordClass 0-255 */
#define DEM_FREEZE_FRAME_RECORD_CLASS_NUM 1u

#define DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)) */
#define DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM 1

#if(DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
/* MAX(COUNT((DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)))  1-254 */
#define DEM_MAX_NUMBER_FF_RECORDS 1
#endif

/* DemPidClass 0-0xFFFF */
#define DEM_PID_CLASS_NUM 0u
#define DEM_PID_TOTAL_SIZE  0 /*total size of all pid*/

/* max value of PID and all ref freezeframe size) */
#define DEM_FREEZE_FRAME_MAX_LEN 1
/*******************************************************************************
*                          ExtendedData Configuration
*******************************************************************************/
/* DemExtendedDataRecordClass 0-253 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_NUM 1u

/* DemExtendedDataClass 0-* */
#define DEM_EXTENDED_DATA_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
#define DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM  1u

/* MAX(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
#define DEM_EXTENDED_DATA_MAX_REF_NUM 1u

/* MAX(SUM(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef/DataSize)) */
#define DEM_EXTENDED_DATA_MAX_LEN 13u
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/
/* DemGroupOfDTC 0-255 */
#define DEM_GROUP_OF_DTC_NUM 1u

#define DEM_DTC_REF_EMISSION_NUM  0u

/* DemDTC 0-65535 */
#define DEM_DTC_NUM 52u

#define DEM_WWWOBD_NUM 0u

/* DemDTCAttributes 0-65535 */
#define DEM_DTC_ATTRIBUTES_NUM 1u

/* DemDtcStatusAvailabilityMask Range:0~255 */
#define DEM_DTC_STATUS_AVAILABILITY_MASK 0x9u

#define DEM_J1939_NODE_NUM 0u
#define DEM_J1939_NODEID_MAX_NUM  0u

/* DemObdDTC 0-65535 */
#define DEM_OBD_DTC_NUM 0u

#if(DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CALCULATED)
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
#define DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM 1u

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
#define DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM 1u

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

#define DEM_IMMEDITE_CHILD_COMPONENT_MAX_NUM  1u


/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackClearEventAllowed))) */
#define DEM_CALLBACK_CLEAR_EVENT_ALLOWED_TOTAL_NUM 0u

/* DemEventParameter 1-65535 */
#define DEM_EVENT_PARAMETER_NUM 52u

#define Low_Beam_BIN_resistor  1u
#define High_Beam_BIN_resistor  2u
#define FogOrCorner_BIN_resistor  3u
#define DRLOrTI_NTC_resistor  4u
#define FogOrCorner_NTC_resistor  5u
#define High_Beam_NTC_resistor  6u
#define Low_Beam_NTC_resistor  7u
#define High_Beam_Led_open  8u
#define High_Beam_Led_short  9u
#define Low_Beam_Led_open  10u
#define Low_Beam_Led_short  11u
#define FogOrCorner_Led_open  12u
#define FogOrCorner_Led_short  13u
#define DRLOrPO_Led_open  14u
#define DRLOrPO_Led_short  15u
#define TL_Led_open  16u
#define TL_Led_short  17u
#define BUCK1Low_Beam_lost_Com  18u
#define BUCK2High_Beam_lost_Com  19u
#define DRLOrPO_led_driver_lost_Com  20u
#define TL_led_driver_lost_Com  21u
#define Leveling_motor_open_circuit  22u
#define Leveling_motor_short_circuit  23u
#define Leveling_motor_ThermalShutdown  24u
#define Leveling_motor_stall  25u
#define Leveling_motor_driver_lost_Com  26u
#define SBC_input_undervoltage  27u
#define SBC_input_overvoltage  28u
#define DEM5VUnderOrOvervoltage  29u
#define BUCK1_V5A_undervoltage  30u
#define BUCK1_driver  31u
#define BUCK1_COMP_overvoltage  32u
#define BUCK1_outputLow_Beam_undervoltage  33u
#define BUCK1_outputLow_Beam_overvoltage  34u
#define BUCK2_V5A_undervoltage  35u
#define BUCK2_driver  36u
#define BUCK2_COMP_overvoltage  37u
#define Program_flow  38u
#define Boost_ouput_overvoltage  39u
#define Boost_ouput_undervoltage  40u
#define Boost_driver  41u
#define HideSide_ouput_overcurrent  42u
#define KL15_voltage_less_than_7V  43u
#define KL15_voltage_more_than_18V  44u
#define Lost_Com_with_BCM_FLM0xDC  45u
#define Lost_Com_with_BGW_LI0x2FC  46u
#define Lost_Com_with_CDC_HU_070x2AC  47u
#define CRC_with_BCM_FLM0xDC  48u
#define Message_counter_witth_BCM_FLM0xDC  49u
#define CAN_bus_off  50u
#define HideSide_ouput_shorterror  51u
#define HideSide_ouput_openerror  52u
/*******************************************************************************
*                          Memory Configuration
*******************************************************************************/
/* COUNT(DemGeneral/Dem<xx>Memory) */
#define DEM_MEM_DEST_TOTAL_NUM 1u

/* MAX(DemGeneral/Dem<XX>Memory/DemMaxNumberEventEntry<XX>) */
#define DEM_MEM_DEST_MAX_ENTRY_NUM 38u

/* DemMaxNumberEventEntryPermanent Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT 0u

/* DemPrimaryMemory 1-1 */
/* DemMaxNumberEventEntryPrimary Range:1~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY 38u

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


#define DEM_SECONDARY_FUNCTIONID_REF_MAX_NUM  2u

#define DEM_RATIO_NUM 0u

#define DEM_DTR_NUM 0u

/*******************************************************************************
*                          J1939 Configuration
*******************************************************************************/
#define DEM_J1939_SUPPORT STD_OFF

#endif /* DEM_CFG_H_ */
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

