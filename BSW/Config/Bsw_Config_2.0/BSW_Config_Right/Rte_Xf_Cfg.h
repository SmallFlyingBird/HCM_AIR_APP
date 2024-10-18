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
**  FILENAME    :  Rte_Xf_Cfg.h                                               **
**                                                                            **
**  Created on  : 2024/04/10 11:04:11                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef XF_CFG_H_
#define XF_CFG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "TransformerTypes.h"
#include "Rte_E2EXf_LCfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */       
#define IN_PLACE_IGVEHSPDLGT        STD_OFF
#define IN_PLACE_IGACTVNOFINDCR        STD_OFF
#define IN_PLACE_IGVEHMODMNGTGLBSAFE1        STD_OFF
#define IN_PLACE_IGACTNOFLEDLOBEAM        STD_OFF
#define IN_PLACE_IGOUTDBRI        STD_OFF
#define IN_PLACE_IGSTEERWHLSNSR        STD_OFF
#define IN_PLACE_IGACCRPEDLRAT        STD_OFF
#define IN_PLACE_IGBRKPEDLSNSR        STD_OFF
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_VehSpdLgt_BCM_HCML;
extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_ActvnOfIndcr_BGM_HCML;
extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_VehModMngtGlbSafe1_BGM_HCML;
extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_ActnOfLedLoBeam_BGM_HCML;
extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_OutdBri_RLSM_HCML;
extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_SteerWhlSnsr;
extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_AccrPedlRat;
extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_BrkPedlSnsr;

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif/* XF_CFG_H_ */

