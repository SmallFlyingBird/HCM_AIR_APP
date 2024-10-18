/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2024)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    :  OEM_HeaderFile.h                                          **
**                                                                           **
**  Created on  : 2024				                                         **
**  Author      : penfei.zhu                                                 **
**  Vendor      :                                                            **
**  DESCRIPTION : OEM requirement header file manage                         **
**                                                                           **
**  SPECIFICATION(S) :  								                     **
**                                                                           **
**************************************************************************** */

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>       <DATE>       <AUTHOR>       <REVISION LOG>
 *   V1.0.0        2024-5-7    Youfeng,Ji   add GEELY20 header file.
 *******************************************************************************/

#ifndef OEM_OEM_HEADERFILE_H_
#define OEM_OEM_HEADERFILE_H_

/*==============================================================================================================================*/
/*============	this macro GEELY20_SPECIFICATION_USED is definitely important	====================================================*/
/*============  Suggest this macro GEELY20_SPECIFICATION_USED be set by compiler to avoid to handle include files issues	========*/
/*============	#define GEELY20_SPECIFICATION_USED ===============================================================================*/
/*==============================================================================================================================*/

#define GEELY20_SPECIFIC_DIAGNOSTIC_REQUIREMENT


#ifdef GEELY20_SPECIFIC_DIAGNOSTIC_REQUIREMENT
/*#include "GEELY20_Diagnostic.h"*/
#endif

#endif /* OEM_OEM_HEADERFILE_H_ */
