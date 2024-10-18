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
**  FILENAME    : Rte_BswM_Type.h                                             **
**                                                                            **
**  Created on  : 2016-11-7                                                   **                                                                                                                                                                   **
**  Author      : stanleyluo                                                  **
**  Vendor      :                                                             **
**  DESCRIPTION :  Common types for BSWM and RTE                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/




#ifndef RTE_BSWM_TYPE_H
#define RTE_BSWM_TYPE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_Type.h"
#include "Rte_BswM_Type.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*Error during task creation*/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*This type identifies the modes that can be requested by BswM Users*/
/*typedef uint8 BswM_ModeType;*/

/*This type identifies the mode group that can be managed by a BswM*/
/*(obsolete) StatusRevisionBegin=4.2.2*/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define GENERIC_CANSMBUSOFF_NO_COM 						0
#define GENERIC_CANSMBUSOFF_BUSOFF_SILENT				1

#define GENERIC_COMCONTROL_ON      				        1
#define GENERIC_COMCONTROL_OFF              			0

#define GENERIC_ECU_SLEEP_ALLOWED 			            1
#define GENERIC_ECU_SLEEP_NOT_ALLOWED               	0

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/


#endif /* RTE_BSWM_TYPE_H */
