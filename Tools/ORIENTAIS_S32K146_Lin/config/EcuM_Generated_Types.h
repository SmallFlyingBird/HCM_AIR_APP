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
**  FILENAME    : EcuM_Generated_Types.h                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :  contains generated type declarations that fulfill the      **
**                 forward declarations in EcuM.h                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/


#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*Configured wakeup source symbols in this ECU configuration*/
#define ECUM_WKSOURCE(sourceId) (uint32)((uint32)0x01u << (sourceId))
/* EcuMWakeupSource_Lin */
#define EcuMWakeupSource_Lin_WKSID        ECUM_WKSOURCE(7)
/*Alarm wakeup source, if EcuMAlarmWakeupSource configured*/
#define ECUM_WKSOURCE_ALARMCLOCK  ECUM_WKSOURCE(8)
#define ECUM_MCU_MODE_NORMAL    null
#define ECUM_MCU_MODE_HALT      255

#define ECUM_MCU_MODE_POLL  0xff

#define ECUM_WKSTATUS_DISABLED  0xff

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*********************Generated Configuration Types***************************/
/*Generated Post-build configuration pointer types for configured modules
 * containing the PB configure pointer for every module need PB configure data*/
typedef struct
{
	P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) bswMPbCfg;
} EcuM_GenBSWPbCfgType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/


#endif /* ECUM_GENERATED_TYPES_H */

