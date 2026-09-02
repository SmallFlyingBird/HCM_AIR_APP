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
**  FILENAME    : Rte_E2EXf_Cfg.h                                             **
**                                                                            **
**  Created on  : 2024/04/10 11:04:11                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef E2EXF_CFG_H_
#define E2EXF_CFG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2E_P01.h"
#include "TransformerTypes.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Config E2EXf Module Variant */
#define E2EXF_VARIANT_PC             VARIANT_PRE_COMPILE
#define E2EXF_VARIANT_LT             VARIANT_LINK_TIME
#define E2EXF_VARIANT_PB             VARIANT_POST_BUILD
#define E2EXF_VARIANT_CFG            VARIANT_LINK_TIME      /* Variant Config */
#define E2EXF_VERSION_INFO_API      STD_OFF
#define E2EXF_DEV_ERROR_DETECT      STD_ON
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif/* E2EXF_CFG_H_ */

