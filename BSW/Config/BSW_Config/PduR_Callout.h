
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : PduR_Callout.h                                                  **
**                                                                            **
**  Created on  : 2023/09/15 16:21:42                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   NONE                                                 **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20230818   long.zhu          Initial Version
 */

#ifndef  PDUR_PDUR_CALLOUT_H
#define  PDUR_PDUR_CALLOUT_H

/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "ComStack_Types.h"
#include "PduR_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define BL_BUS_MODE_NONE    0x00000000u
#define BL_BUS_MODE_ETH     0x12345678u
#define BL_BUS_MODE_CAN     0x87654321u
#define BL_BUS_MODE_LIN     0x12344321u

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
uint8 PduR_GetDirection(void);
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#endif  /* end of PDUR_H */

