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
**  FILENAME    : Rte_E2EXf_LCfg.c                                            **
**                                                                            **
**  Created on  : 2024/04/22 11:37:58                                         **
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
#include "Rte_E2EXf_LCfg.h"
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
/* PRQA S 0779 ++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(EndToEndTransformationDescriptionType_PROFILE_01, E2EXF_CONST) EndToEndTransformationDescription_0 =
{
    8,            /*counterOffset*/
    0,            /*crcOffset*/
    ALL16BIT,    /*dataIdMode*/
    12,            /*dataIdNibbleOffset*/
    3,            /*maxDeltaCounter*/
    0,            /*maxErrorStateInit*/
    3,            /*maxErrorStateInvalid*/
    3,            /*maxErrorStateValid*/
    2,            /*maxNoNewOrRepeatedData*/
    1,            /*minOkStateInit*/
    1,            /*minOkStateInvalid*/
    1,            /*minOkStateValid*/
    R4_2,            /*profileBehavior*/
    "PROFILE_01",    /*PROFILE_01*/
    1,            /*syncCounterInit*/
    0,            /*upperHeaderBitsToShift*/
    1,            /*windowSizeInit*/
    3,            /*windowSizeValid*/
    1,            /*windowSizeInvalid*/
    TRUE        /*clearFromValidToInvalid*/
};
#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(EndToEndTransformationDescriptionType_PROFILE_01, E2EXF_CONST) EndToEndTransformationDescription_1 =
{
    8,            /*counterOffset*/
    0,            /*crcOffset*/
    ALL16BIT,    /*dataIdMode*/
    12,            /*dataIdNibbleOffset*/
    3,            /*maxDeltaCounter*/
    1,            /*maxErrorStateInit*/
    3,            /*maxErrorStateInvalid*/
    3,            /*maxErrorStateValid*/
    2,            /*maxNoNewOrRepeatedData*/
    1,            /*minOkStateInit*/
    1,            /*minOkStateInvalid*/
    1,            /*minOkStateValid*/
    R4_2,            /*profileBehavior*/
    "PROFILE_01",    /*PROFILE_01*/
    1,            /*syncCounterInit*/
    0,            /*upperHeaderBitsToShift*/
    3,            /*windowSizeInit*/
    3,            /*windowSizeValid*/
    3,            /*windowSizeInvalid*/
    TRUE        /*clearFromValidToInvalid*/
};
#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(EndToEndTransformationDescriptionType_PROFILE_01, E2EXF_CONST) EndToEndTransformationDescription_2 =
{
    8,            /*counterOffset*/
    0,            /*crcOffset*/
    NOTUSED,    /*dataIdMode*/
    12,            /*dataIdNibbleOffset*/
    6,            /*maxDeltaCounter*/
    0,            /*maxErrorStateInit*/
    3,            /*maxErrorStateInvalid*/
    3,            /*maxErrorStateValid*/
    5,            /*maxNoNewOrRepeatedData*/
    1,            /*minOkStateInit*/
    1,            /*minOkStateInvalid*/
    1,            /*minOkStateValid*/
    R4_2,            /*profileBehavior*/
    "PROFILE_01",    /*PROFILE_01*/
    1,            /*syncCounterInit*/
    0,            /*upperHeaderBitsToShift*/
    1,            /*windowSizeInit*/
    3,            /*windowSizeValid*/
    1,            /*windowSizeInvalid*/
    TRUE        /*clearFromValidToInvalid*/
};
#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"



static CONST(EndToEndTransformationISignalPropsType_PROFILE_01, E2EXF_CONST) EndToEndTransformationISignalProps_ActnOfLedLoBeam_BGM_HCML =
{
    0x441,            /*dataId*/
    24,            /*dataLength*/
};

static CONST(EndToEndTransformationISignalPropsType_PROFILE_01, E2EXF_CONST) EndToEndTransformationISignalProps_ActvnOfIndcr_BGM_HCML =
{
    0x9e,            /*dataId*/
    24,            /*dataLength*/
};

static CONST(EndToEndTransformationISignalPropsType_PROFILE_01, E2EXF_CONST) EndToEndTransformationISignalProps_LvlgSwtSetReq_BGM_HCML =
{
    0x00,            /*dataId*/
    24,            /*dataLength*/
};


#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
static CONST(E2EXf_ConfigType_PROFILE_01, E2EXF_CONST) E2ETransformer_profile01[3] =
{
    {
       &TransformationTechnology_ActnOfLedLoBeam_BGM_HCML,
       &EndToEndTransformationISignalProps_ActnOfLedLoBeam_BGM_HCML,
       NULL_PTR
    },

    {
       &TransformationTechnology_ActvnOfIndcr_BGM_HCML,
       &EndToEndTransformationISignalProps_ActvnOfIndcr_BGM_HCML,
       NULL_PTR
    },

    {
       &TransformationTechnology_LvlgSwtSetReq_BGM_HCML,
       &EndToEndTransformationISignalProps_LvlgSwtSetReq_BGM_HCML,
       NULL_PTR
    },

};

CONST(E2EXf_ConfigType, E2EXF_CONST) E2EXf_Config =
{
    E2ETransformer_profile01,
};

/* PRQA S 0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */

