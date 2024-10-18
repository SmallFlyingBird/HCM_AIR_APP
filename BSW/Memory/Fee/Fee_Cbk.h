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
**  FILENAME    : Fee_Cbk.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Callback API declaration of FEE                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform  R19_11                     **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef FEE_CBK_H
#define FEE_CBK_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
BEGIN_C_DECLS

FUNC(void, FEE_CODE) Fee_JobEndNotification(void);

FUNC(void, FEE_CODE) Fee_JobErrorNotification(void);

END_C_DECLS

#endif /* FEE_CBK_H */
