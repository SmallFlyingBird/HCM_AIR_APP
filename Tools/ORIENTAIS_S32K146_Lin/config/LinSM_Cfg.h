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
**  FILENAME    : LinSM_Cfg.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of LinSM                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

#ifndef LINSM_CFG_H
#define LIMSM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* configuration variants */
#define LINSM_VARIANT_PC    VARIANT_PRE_COMPILE
#define LINSM_VARIANT_LT    VARIANT_LINK_TIME
#define LINSM_VARIANT_PB    VARIANT_POST_BUILD

/* configuration variants switch */
#define LINSM_VARIANT_CFG     LINSM_VARIANT_PC

/*Switches the Default Error Tracer (Det) detection and notification ON or OFF.*/
#define LINSM_DEV_ERROR_DETECT             STD_OFF

/*Fixed period that the MainFunction shall be called.*/
#define LINSM_MAIN_PROCESSING_PERIOD       10u 

/*Switches the LinSM_GetVersionInfo function ON or OFF.*/
#define LINSM_VERSION_INFO_API             STD_OFF

/* channel number */
#define LINSM_CHANNEL_NUM                  2u

/* switch for LinSMTransceiverPassiveMode */
/* The APIs LinIf_SetTrcvMode() will only be called when this parameter is enabled.*/
#define LINSM_TRANSCEIVER_PASSIVER_MODE_SUPPORT    STD_OFF

/* Indiacate wheater support MASTER/SLAVE node */        
#define LINSM_MASTER_NODE_SUPPORT                   STD_OFF
#define LINSM_SLAVE_NODE_SUPPORT                    STD_ON


/* Null-schedule index */
#define LINSM_NULL_SCHEDULE_INDEX           0u

#endif /* LINSM_CFG_H */


