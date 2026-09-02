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
**  FILENAME    : MemIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/06/04 15:53:52                                 **
**  Author      :                                                             **
**  Vendor      : isoft                                                       **
**  DESCRIPTION : MemIf pre compile globle macro define                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/    
#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H

/*==============================================================================
*                                        INCLUDE FILES
==============================================================================*/
#include "MemIf_Types.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define MEMIF_CFG_SW_MAJOR_VERSION  2U
#define MEMIF_CFG_SW_MINOR_VERSION  0U
#define MEMIF_CFG_SW_PATCH_VERSION  0U

#define MEMIF_NUMBER_OF_DEVICES     (1u)

/* MemIf036, the identifier is not specified */
#define MEMIF_BROADCAST_ID (0xFFu)

#define MEMIF_VERSION_INFO_API  (STD_OFF)
#define MEMIF_CFG_USE_FCT_API   (STD_ON)

/* preprocessor switch for DET */
#define MEMIF_DEV_ERROR_DETECT (STD_ON)

extern CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES];

#endif  /* MEMIF_CFG_H */
