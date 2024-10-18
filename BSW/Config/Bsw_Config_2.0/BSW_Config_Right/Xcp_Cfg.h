/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Xcp_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-09-12 17:56:44>
 */
/*============================================================================*/

#ifndef  XCP_CFG_H
#define  XCP_CFG_H
/*Bus Interface Select*/
#define XCP_ON_CCD_ENABLE           STD_OFF
#define XCP_ON_ETHERNET_ENABLE      STD_OFF
#define XCP_ON_FLEXRAY_ENABLE       STD_OFF
#define XCP_ON_CAN_ENABLE           STD_ON
#include "Xcp_GenericTypes.h"

/*Available resource & protection.*/
#define XCP_RESOURCE                (0u|XCP_PL_DAQ|XCP_PL_CAL|XCP_PL_PGM)
#define XCP_PROTECTION              (0u)

#define XCP_BUS_TX_POLLING_MODE     STD_OFF
#define XCP_TANSFER_TIME_OUT        3u

/*SET_REQUEST related.*/
#define XCP_CAL_STORE_SUPPORT       STD_OFF
#define XCP_DAQ_STORE_SUPPORT       STD_OFF
#define XCP_RESUME_SUPPORT          STD_OFF
#define XCP_BIT_STIM_SUPPORT        STD_OFF

#define XCP_MAX_CTO                    8u
#define XCP_MAX_DTO                 8u
#define XCP_CTO_BUFFER_SIZE         8u
#define XCP_DTO_BUFFER_SIZE         XCP_MAX_DTO

/*General configuration.*/
#define XCP_MAIN_FUNCTION_PERIOD    10u
#define XCP_DEV_ERROR_DETECT        STD_OFF
#define XCP_VERSION_INFO_API        STD_OFF
#define XCP_SUPPRESS_TX_SUPPORTED   STD_OFF
#define XCP_MEASUREMENT_POLLING_SUPPORT STD_OFF

/*PGM characteristic.*/
#define XCP_FLS_MIN_WRITE_SIZE      16u
#define XCP_FLS_HEADER              "Fls.h"
#define XCP_MAX_CTO_PGM             XCP_MAX_CTO
#define XCP_FLS_BASEADDR            ((uint32)0x0u)
#define Xcp_FlsAddressType            Fls_AddressType
#define Xcp_FlsLengthType            Fls_LengthType

#define XCP_PGM_FILLER                      0xffu
#define XCP_PGM_REQRETRIE                   0x03u
#define XCP_MAX_SECTOR                      0x1u
#define MAX_SECTOR_NAME_LENGTH                 32u

/*CAL & PAG characteristic.*/
#define XCP_MAX_SEGMENT             1u
#define XCP_PAG_SUPPORT             STD_ON
#define XCP_SWITCH_PAG_SUPPORT      STD_ON
    #define XCP_RAM_PAGE_NUM            0u
    #define XCP_FLASH_PAGE_NUM          1u
#define XCP_PAGE_BUF0_SIZE 0x2000u

/*DAQ characteristic.*/
#define XCP_DAQ_CONFIG_TYPE             XCP_DAQ_STATIC
#define XCP_IDENTIFICATION_FIELD_TYPE   XCP_PID_ABSOLUTE
#define XCP_PID_OFF_SUPPORT             STD_OFF
#define XCP_PRESCALER_SUPPORTED            STD_ON
#define XCP_DAQ_PRIORITY_SUPPORT        STD_OFF
#define XCP_DAQ_OVL_INDICATION            XCP_DAQ_OVL_NO_INDIC
#define XCP_PID_OVFLOW                     0x80u
#define XCP_MAX_WRITEDAQ_SIZE        7u

#define XCP_MIN_DAQ                    0u
#define XCP_MAX_DAQ                 1u
#define XCP_ODT_ENTRY_SIZE_STIM     0u
#define XCP_ODT_ENTRY_SIZE_DAQ      7u

/*Event configuration.*/
#define EventChannel_0              0u
#define MAX_EVCH_NAME_LENGTH        32u
#define XCP_MAX_EVENT_CHANNEL       1u
#define XCP_EVCHBUFFER_0_DEPTH      16u
/*TimeStamp configuration.*/
#define XCP_TIMESTAMP_TYPE          XCP_TS_NO_TS
#define XCP_INTERLEAVED_MODE        STD_OFF
/*Blcok Mode.*/
#define XCP_SLAVE_BLOCK_MODE        STD_OFF
#define XCP_MASTER_BLOCK_MODE       STD_OFF
#define XCP_CAN_MAX_DLC_REQUIRED    STD_ON
#define XCP_CAN_MAX_DLC              8u
/*Optional command.*/
#define XCP_GET_COMM_MODE_INFO              STD_ON
#define XCP_GET_ID                          STD_ON
#define XCP_NUM_OF_ID                       0x1u
/*STD*/
#define XCP_SET_REQUEST                        STD_ON
#define XCP_SEED_AND_UNLOCK                 STD_ON
#define XCP_SET_MTA                            STD_ON
#define XCP_UPLOAD                          STD_ON
#define XCP_SHORT_UPLOAD                    STD_ON
#define XCP_BUILD_CHECKSUM                  STD_ON
#define XCP_MAX_CHECKSUM_SIZE               0x100u
#define XCP_TRANSPORT_LAYER_CMD             STD_ON
#define    XCP_GET_SLAVE_ID                    STD_OFF
#define    XCP_GET_DAQ_ID                      STD_OFF
#define    XCP_SET_DAQ_ID                      STD_OFF
#define XCP_USER_CMD                        STD_OFF
/*CAL*/
#define XCP_DOWNLOAD_NEXT                    STD_OFF
#define XCP_DOWNLOAD_MAX                    STD_ON
#define XCP_SHORT_DOWNLOAD                    STD_ON
#define XCP_MODIFY_BITS                     STD_ON
#define XCP_SET_CAL_PAGE                    XCP_PAG_SUPPORT
#define XCP_GET_CAL_PAGE                    XCP_PAG_SUPPORT
#define XCP_GET_PAG_PROCESSOR_INFO          STD_OFF
#define XCP_GET_SEGMENT_INFO                STD_OFF
#define XCP_GET_PAGE_INFO                   STD_OFF
#define XCP_SET_SEGMENT_MODE                STD_OFF
#define XCP_GET_SEGMENT_MODE                STD_OFF
#define XCP_COPY_CAL_PAGE                   STD_OFF
/*DAQ*/
#define XCP_WRITE_DAQ_MULTIPLE              STD_OFF
#define XCP_READ_DAQ                        STD_ON
#define XCP_GET_DAQ_CLOCK                   STD_OFF
#define XCP_GET_DAQ_PROCESSOR_INFO          STD_ON
#define XCP_GET_DAQ_RESOLUTION_INFO         STD_ON
#define XCP_GET_DAQ_LIST_MODE               STD_ON
#define XCP_GET_DAQ_EVENT_INFO              STD_ON
#define XCP_GET_DAQ_LIST_INFO               STD_OFF
/*PGM*/
#define XCP_PROGRAM_NEXT                    STD_OFF
#define XCP_GET_SECTOR_INFO                 STD_OFF
#define XCP_GET_PGM_PROCESSOR_INFO          STD_ON
#define XCP_PROGRAM_PREPARE                 STD_OFF
#define XCP_PROGRAM_FORMAT                  STD_ON
#define XCP_PROGRAM_MAX                     STD_OFF
#define XCP_PROGRAM_VERIFY                  STD_OFF

#define XCP_CHECK_MEA_ADDR                  STD_OFF

typedef VAR(uint8,TYPEDEF)           Xcp_DaqNumType;
#define XCP_ADDR_GRANULARITY         XCP_AG_BYTE

#define XCP_AG                       (0x01u)

typedef VAR(uint8,TYPEDEF)           Xcp_AGType;

#define XCP_RX_PDU_NUMBER_MAX        1u
#define XCP_EtcToHcmlXcpPdu01                                                  0u

#define XCP_TX_PDU_NUMBER_MAX        1u
#define XCP_HcmlToEtcXcpPdu01                                                  0u

#endif  /* endof XCP_CFG_H */

/*=======[E N D   O F   F I L E]==============================================*/

