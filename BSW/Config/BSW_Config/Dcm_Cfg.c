
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
**  FILENAME    : Dcm_Cfg.c                                                   **
**                                                                            **
**  Created on  : 2023/11/22 15:52:23                                         **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS services
**   which used for bootloader project                                        **
**                                                                            **
**  SPECIFICATION(S) :   UDS Service - ISO14229                               **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230817    long.zhu          Initial Version
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_Dsp.h"
#include "Dcm_Cfg.h"
#include "Rte_Dcm.h"
#include "HcmPlatform.h"
#include "Os_User.h"

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
const Dcm_SessionType Dcm_ServiceTable_0x10_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x10_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x11_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x11_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x22_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x22_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x27_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x27_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x2e_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x2e_Security[1] = {DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x31_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x31_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x3e_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x3e_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_ServiceTableType Dcm_ServiceTable[DCM_SERVICE_NUM] =
{
    /* SID, funcAddrSupport,  sessionSupp,      ServiceFct,  pendingFct */
    /* @type:uint8 range:0x00~0xFF note:select unique service Id */
    /* @type:boolean range:TRUE,FALSE note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:API range:NONE note:auto generate */
    /* @type:API range:NONE note:auto generate */
    {
        0x10u,
        DCM_PHYSICAL_ADDRESSING|DCM_FUNCTIONAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x10_Session,
        2u,
        Dcm_ServiceTable_0x10_Security,
        &Dcm_RecvMsg10,
        NULL_PTR
    },
    {
        0x11u,
        DCM_PHYSICAL_ADDRESSING|DCM_FUNCTIONAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x11_Session,
        2u,
        Dcm_ServiceTable_0x11_Security,
        &Dcm_RecvMsg11,
        NULL_PTR
    },
    {
        0x22u,
        DCM_PHYSICAL_ADDRESSING|DCM_FUNCTIONAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x22_Session,
        2u,
        Dcm_ServiceTable_0x22_Security,
        &Dcm_RecvMsg22,
        NULL_PTR
    },
    {
        0x27u,
        DCM_PHYSICAL_ADDRESSING|DCM_FUNCTIONAL_ADDRESSING,
        1u,
        Dcm_ServiceTable_0x27_Session,
        2u,
        Dcm_ServiceTable_0x27_Security,
        &Dcm_RecvMsg27,
        NULL_PTR
    },
#if (DCM_WRITEDID_NUM > 0U)
	{
        0x2eu,
        DCM_PHYSICAL_ADDRESSING|DCM_FUNCTIONAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x2e_Session,
		1u,
        Dcm_ServiceTable_0x2e_Security,
        &Dcm_RecvMsg2E, 
        &Dcm_Pending2E
    },
#endif
    {
        0x31u,
        DCM_PHYSICAL_ADDRESSING|DCM_FUNCTIONAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x31_Session,
        2u,
        Dcm_ServiceTable_0x31_Security,
        &Dcm_RecvMsg31,
        &Dcm_Pending31
    },
    {
        0x3eu,
        DCM_PHYSICAL_ADDRESSING|DCM_FUNCTIONAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x3e_Session,
        2u,
        Dcm_ServiceTable_0x3e_Security,
        &Dcm_RecvMsg3E,
        NULL_PTR
    },
};

#if (DCM_SESSION_NUM > 0u)
/* For 10 Service */
const Dcm_SessionType Dcm_ServiceTable_0x1_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x1_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/
const Dcm_SessionType Dcm_ServiceTable_0x2_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x2_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/
const Dcm_SessionType Dcm_ServiceTable_0x3_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x3_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SessionRowType Dcm_SessionRow[DCM_SESSION_NUM] =
{
    /* sessionType, sessionSupp, securitySupp */
    /* @type:uint8 range:0x00~0xFF note:select unique session value */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    {
        DCM_SESSION_DEFAULT,
        2u,
        Dcm_ServiceTable_0x1_Session,
        2u,
        Dcm_ServiceTable_0x1_Security,
    },
    {
        DCM_SESSION_PROGRAMMING,
        2u,
        Dcm_ServiceTable_0x2_Session,
        2u,
        Dcm_ServiceTable_0x2_Security,
    },
    {
        DCM_SESSION_EXTEND,
        2u,
        Dcm_ServiceTable_0x3_Session,
        2u,
        Dcm_ServiceTable_0x3_Security,
    },
};
#endif

const Dcm_SessionType Dcm_ResetRow_Hard_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ResetRow_Hard_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_ResetRowType Dcm_ResetRow[DCM_RESET_NUM] =
{
    /* resetType, sessionSupp, securitySupp */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    {
        DCM_HARD_RESET,
        2u,
        Dcm_ResetRow_Hard_Session,
        2u,
        Dcm_ResetRow_Hard_Security,
    },
};

#if ((DCM_READDID_NUM > 0))

const Dcm_SecurityType Dcm_ReadDidRow_Security_0[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_ReadDidRowType Dcm_ReadDidRow[DCM_READDID_NUM] =
{
	/* Standard DID Start */
    {
		0x4351u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x4351_ReadData
	},
	{
		0x4359u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x4359_ReadData
	},
	{
		0x435Bu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x435B_ReadData
	},
	{
		0x435Cu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x435C_ReadData
	},
	{
		0x435Du,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x435D_ReadData
	},
	{
		0x435Eu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x435E_ReadData
	},
	{
		0x435Fu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x435F_ReadData
	},
	{
		0x437Cu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x437C_ReadData
	},
    {
		0x43CFu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x43CF_ReadData
	},
	{
		0x43D2u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x43D2_ReadData
	},
	{
		0x43DAu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0x43DA_ReadData
	},
    {
		0xB107u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xB107_ReadData
    },
    {
		0xB108u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xB108_ReadData
    },
    {
		0xD0B5u,
        2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xD0B5_ReadData
	},  
    {
		0xF120u,
        2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF120_ReadData
	},  
    {
		0xF121u,
        2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF121_ReadData
	},
	{
		0xF125u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF125_ReadData
	},
    {
        0xF12Au,
        2U,
		Dcm_ReadDidRow_Security_0,
        &Rte_Dcm_0xF12A_ReadData
    },
    {
        0xF12Bu,
        2U,
		Dcm_ReadDidRow_Security_0,
        &Rte_Dcm_0xF12B_ReadData
    },
	{
		0xF12Eu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF12E_ReadData
	},
	{
		0xF186u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF186_ReadData
	},
	{
		0xF18Au,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF18A_ReadData
	},
	{
		0xF18Cu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF18C_ReadData
	},
	{
		0xF1A0u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF1A0_ReadData
	},
	{
		0xF1A1u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF1A1_ReadData
	},
	{
		0xF1A5u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF1A5_ReadData
	},
	{
		0xF1AAu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF1AA_ReadData
	},
	{
		0xF1ABu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF1AB_ReadData
	},
	{
		0xF1AEu,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xF1AE_ReadData
	},
	// {
	// 	0xF1F0u,
	// 	2U,
	// 	Dcm_ReadDidRow_Security_0,
	// 	&Rte_Dcm_0xF1F0_ReadData
	// },
	// {
	// 	0xF1F1u,
	// 	2U,
	// 	Dcm_ReadDidRow_Security_0,
	// 	&Rte_Dcm_0xF1F1_ReadData
	// },
	{
		0xD900u,
		2U,
		Dcm_ReadDidRow_Security_0,
		&Rte_Dcm_0xD900_ReadData
	},
	/* Standard DID End */
};
#endif

const Dcm_SessionType Dcm_SecurityRow_Level1_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_SecurityRow_Level1_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_SecurityRowType Dcm_SecurityRow[DCM_SECURITY_NUM] =
{
    /* seedId,
     * keyId,
     * secAccessLevel,
     * sessionSupp,
     * securitySupp
     * function :generateSeed
     * function :compareKey
     * */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:define range:DCM_SECURITY_LEV1~DCM_SECURITY_LEV2 note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    /* @type:API range:NONE note:input APIname */
    /* @type:API range:NONE note:input APIname */
    {
        0x1u,
        DCM_27_RANDOMMSG_LEN,
        0x2u,
        DCM_27_SENDKEY_LENGTH,
        DCM_SECURITY_LEV1,
        1u,
        Dcm_SecurityRow_Level1_Session,
        2u,
        Dcm_SecurityRow_Level1_Security,
        Rte_Dcm_27_GenerateSeed,
        Rte_Dcm_27_CompareKey
    }
};

#if (DCM_WRITEDID_NUM > 0u)

const Dcm_SecurityType Dcm_WriteDidRow_Security_0[1] = {DCM_SECURITY_LEV1};/*PRQA S 3408*/

const Dcm_WriteDidRowType Dcm_WriteDidRow[DCM_WRITEDID_NUM] =
{
    /* DID,  dataLength,securitySupp,writeDataFct */
    /* @type:uint16 range:0x0000~0xFFFF note:NONE */
    /* @type:uint16 range:0x0001~0xFFFF note:NONE */
    /* @type:uint8 range:security value note:select defined security value */
    /* @type:API range:NONE note:input APIname */
    {
        (uint16)0xF1AA,
        (uint16)16U,
        1u,
        Dcm_WriteDidRow_Security_0,
        &FL_WriteDidF1AA
    },
    {
        (uint16)0xF1AB,
        (uint16)16U,
        1u,
        Dcm_WriteDidRow_Security_0,
        &FL_WriteDidF1AB
    },
    {
        (uint16)0xF18C,
        (uint16)16U,
        1u,
        Dcm_WriteDidRow_Security_0,
        &FL_WriteDidF18C
    },
};
#endif

#if (DCM_ROUTINE_CONTROL_NUM > 0u)

const Dcm_SessionType Dcm_RoutineCtrlRow_Session_0[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_RoutineCtrlRow_Security_0[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV1};/*PRQA S 3408*/
const Dcm_RoutineControlType Dcm_RoutineCtrlRow_RoutineControl_0[1] = {DCM_START_ROUTINE};/*PRQA S 3408*/

const Dcm_RoutineControlRowType Dcm_RoutineControlRow[DCM_ROUTINE_CONTROL_NUM] =
{
    /* routineId,optionLength,funcAddrSupp,sessionSupp,    securitySupp,routineControl */
    /* @type:uint16 range:0x0000~0xFFFF note:select unique routine Id */
    /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
    /* @type:boolean range:TRUE,FALSE note:auto generate */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    /* @type:API range:NONE note:auto generate */
    {
        (uint16)0x0206u,
        (uint16)0x0u,
        2u,
        Dcm_RoutineCtrlRow_Session_0,
        2u,
        Dcm_RoutineCtrlRow_Security_0,
        1u,
        Dcm_RoutineCtrlRow_RoutineControl_0,
        &Rte_Dcm_CheckProgrammingPreConditions_0x0206,
        NULL_PTR
    }
};
#endif
/*for debug*/
//const Dcm_SecurityType Dcm_DownloadRow_Security[1] = {DCM_SECURITY_LOCKED};/*PRQA S 3408*///DCM_SECURITY_LEV1
const Dcm_SecurityType Dcm_DownloadRow_Security[1] = {DCM_SECURITY_LEV1};


const Dcm_DownloadRowType Dcm_DownloadRow[DCM_DOWNLOADROW_NUM] =
{
    /* dataformatId
     * addrAndLenFormatId
     * securitySupp */
    /* @type:uint8 range:security value note:select defined security value */
	{
        0x0u,
        0x44u,
        1u,
        Dcm_DownloadRow_Security
	},
	{
		0x10u,
		0x44u,
		1u,
		Dcm_DownloadRow_Security
	}
};

const Dcm_testPresentRowType Dcm_testPresentRow[DCM_TESTPRESENT_NUM] =
{
    /* testPresentSupp */
    /* @type:uint8 range:zeroSubFunc value note:select defined zeroSubFunc value */
    {
        0u
    }
};

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
