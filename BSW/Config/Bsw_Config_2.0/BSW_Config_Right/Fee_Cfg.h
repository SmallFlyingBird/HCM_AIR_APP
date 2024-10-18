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
**  FILENAME    : Fee_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2024/07/10 15:36:06                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of Fee                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic R19_11                               **
**                                                                            **
*******************************************************************************/
#ifndef  FEE_CFG_H
#define  FEE_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fee_Types.h"
/*Callback header include*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define FEE_CFG_H_AR_MAJOR_VERSION    4u
#define FEE_CFG_H_AR_MINOR_VERSION    5u
#define FEE_CFG_H_AR_PATCH_VERSION    0u
#define FEE_CFG_H_SW_MAJOR_VERSION    2u
#define FEE_CFG_H_SW_MINOR_VERSION    0u
#define FEE_CFG_H_SW_PATCH_VERSION    0u
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define FEE_DEV_ERROR_DETECT                         STD_ON

#define FEE_MAINFUNCTION_PERIOD                      10u

#define FEE_NVMJOBEND_NOTIFICATION

#define FEE_NVMJOBERROR_NOTIFICATION

#define FEE_POLLING_MODE                             STD_ON

#define FEE_SET_MODE_SUPPORTED                       STD_OFF

#define FEE_VERSION_INFO_API                         STD_OFF

#define FEE_VIRTUALPAGE_SIZE                         16u

#define FEE_CANCEL_API                               STD_OFF

#define FEE_BLOCK_MAX                                46u

#define FEE_BANK_NUM                                 2u

#define FEE_ERASED_VALUE                             0xffu

#define FEE_BUFFER_SIZE                              512u

#define FEE_INITERROR_NOTIFICATION

#define FEE_BLANK_CHECK_API                          STD_OFF

#define FEE_FLASHDRV_NUM                             1u

#define FEE_BANK_HEADER_SIZE                         32u

#define FEE_PAGE_DIRECT_WRITE_SUPPORT                STD_OFF

#define FEE_BLOCK_HEADER_SIZE                        48u

#endif

