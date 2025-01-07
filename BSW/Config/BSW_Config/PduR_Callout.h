
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

#if (STD_ON == APPL_RESPONSE_1002_IN_BOOT_AFTER_RESET)
typedef enum
{
    FLAG_NONE = 0,
    FLAG_NEED_RESPONSE = 1,
    FLAG_ROUTING_SEND = 2,
    FLAG_ROUTING_CONFIRM = 3,
    FLAG_RESPONSE_SENDED = 4
} SEND_1002_FLAGType;
#endif

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#endif  /* end of PDUR_H */

