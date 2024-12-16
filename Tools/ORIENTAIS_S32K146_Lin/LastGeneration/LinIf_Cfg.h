/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinIf_Cfg.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of LinIf                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

#ifndef LINIF_CFG_H
#define LINIF_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Switch to enable/disable the APIs LinIf_CancelTransmit/LinTp_CancelReceive */
#define LINIF_CANCEL_TRANSMIT_SUPPORTED STD_OFF

/* Switches the Development Error Detection ON or OFF */
#define LINIF_DEV_ERROR_DETECT          STD_OFF

/* Switches the multiple drivers ON or OFF */
#define LINIF_MULTIPLE_DRIVER_SUPPORT   STD_OFF

/* Switches the multiple transceiver drivers ON or OFF */
#define LINIF_MULTIPLE_TRCV_DRIVER_SUPPORT STD_OFF

/* States if the node configuration commands Assign NAD and Conditional Change NAD are supported. */
#define LINIF_NC_OPTIONAL_REQUEST_SUPPORTED STD_OFF
  
#if 0
/* This parameter contains the name of the callout function that is called after
 * a response error signal change. Only applicable for LIN slave nodes.*/
#define LinIfResponseErrorSignalChangedCallout  NULL_PTR

/* This parameter contains the name of the callout function that is called when 
 * a save configuration node configuration command is processed by this slave
 * node. The service is only supported when this parameter is configured.
 * Only applicable for LIN slave nodes.*/
#define LinIfSaveConfigurationCallout  NULL_PTR
#endif

/* Switches the TP ON or OFF */
#define LINIF_TP_SUPPORTED              STD_ON

/* States if transceiver driver support is included in the LIN Interface or not. */
#define LINIF_TRCV_DRIVER_SUPPORTED     STD_OFF

/* Switches the LinIf_GetVersionInfo function ON or OFF */
#define LINIF_VERSION_INFO_API          STD_OFF

/* Null-schedule index */
#define LINIF_NULL_SCHEDULE_INDEX       0u


#define LINIF_NUMBER_OF_CHANNELS        1u

#define LINIF_MASTER_CHANNEL_NUMBER     0u
#define LINIF_SLAVE_CHANNEL_NUMBER      1u
#define LINIF_MASTER_FRAME_NUM          0u
#define LINIF_SLAVE_FRAME_NUM           5u

/* When processing the go-to-sleep command,After this time MainFunction shall call
   the function Lin_GetStatus to check the bus state */
#define LINIF_SLEEP_MODE_FRAME_DELAY    0u

#define LINIF_LIN_CHANNEL_WAKEUP_SUPPORT        STD_OFF

#define LINIF_LIN_TRCV_WAKEUP_SUPPORT            STD_OFF

#define LINIF_WAKEUP_SUPPORT            STD_OFF           

#define LINIF_SLAVE_SUPPORT      STD_ON
#define LINIF_MASTER_SUPPORT      STD_OFF

/* If set to true, enables the LinTp_ChangeParameterRequest Api for this Module. */
#define LINTP_CHANGE_PARAMETER_API        STD_OFF

/* Switches the LinTp_GetVersionInfo function ON or OFF */
#define LINTP_VERSION_INFO_API            STD_OFF

#define LINTP_PADDING_VALUE             0xff

#define LINTP_NUMBER_OF_CHANNELS             1

#define LINTP_MASTER_CHANNEL_NUMBER           0

#define LINTP_SLAVE_CHANNEL_NUMBER            1

#define LINIF_TXPDU_RLM_RS_BCM_01      0

#define LINTP_RXPDU_RLM_RS_MasterReq      0
#define LINTP_RXPDU_RLM_RS_MasterReq_Fun      1

#define LINTP_TXPDU_RLM_RS_SlaveResp      0

#endif /* LINIF_CFG_H */

