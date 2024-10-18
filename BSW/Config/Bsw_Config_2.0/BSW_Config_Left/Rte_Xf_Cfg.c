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
**  FILENAME    : Rte_Xf_Cfg.c                                                **
**                                                                            **
**  Created on  : 2024/04/10 11:04:11                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_Xf_Cfg.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_VehSpdLgt_BCM_HCML =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_0,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_ActvnOfIndcr_BGM_HCML =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_1,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_VehModMngtGlbSafe1_BGM_HCML =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_2,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_ActnOfLedLoBeam_BGM_HCML =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_3,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_OutdBri_RLSM_HCML =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_4,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_SteerWhlSnsr =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_5,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_AccrPedlRat =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_6,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_BrkPedlSnsr =
{
    {
        16,            /*HeaderLength*/
        FALSE            /*InPlace*/
    },
    FALSE,                /*NeedsOriginalData*/
    "E2E",            /*Protocol*/
    &EndToEndTransformationDescription_7,
    SAFETY,            /*TransformerClass*/
    "1.0.0",            /*Version*/
};
#define RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
