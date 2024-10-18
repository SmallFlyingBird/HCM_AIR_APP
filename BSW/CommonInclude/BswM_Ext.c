/*
 * BswM_Ext.c
 *
 *  Created on: 2019��3��7��
 *      Author: Administrator
 */
#include "BswM.h"
#include "EcuM.h"
#include "EcuM_Externals.h"
#include "FreeRTimer.h"
#include "Can_GeneralTypes.h"
#include "Rte_BswM_Type.h"
#include "NmHistoryState.h"

void Communication_ON(void)
{
    BswM_RequestMode(66u, GENERIC_COMCONTROL_ON);
}

void Communication_OFF(void)
{
    BswM_RequestMode(66u, GENERIC_COMCONTROL_OFF);
}

void BswM_CanTrcv_ModeShift(void)
{
	/*comment because the whole circle needs to keep Trcv normal,except going to sleep*/
	/* CanTrcv_SetOpMode(0, CANTRCV_TRCVMODE_NORMAL); */
}

void BswM_AllowECU_Sleep(void)
{
	BswM_RequestMode(95u, GENERIC_ECU_SLEEP_ALLOWED);
}

void BswM_NotAllowECU_Sleep(void)
{
	BswM_RequestMode(95u, GENERIC_ECU_SLEEP_NOT_ALLOWED);
}


void WakeupSource_Disable(void)
{
	EcuM_DisableWakeupSources(EcuMWakeupSource_ByCAN);

}

void WakeupSource_Enable(void)
{
	EcuM_EnableWakeupSources(EcuMWakeupSource_ByCAN);
	/*CanTrcv_SetOpMode(0, CANTRCV_TRCVMODE_STANDBY);*/
}


void GenericSwitch_CanSmBusOff_NoCom_CanChannel_0(void)
{
     BswM_RequestMode(240u, GENERIC_CANSMBUSOFF_NO_COM);
}

void GenericSwitch_CanSmBusOff_BusOffSilent_CanChannel_0(void)
{
    BswM_RequestMode(240u, GENERIC_CANSMBUSOFF_BUSOFF_SILENT);
}

void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_CAN(void)
{
    EcuM_ClearWakeupEvent(EcuMWakeupSource_ByCAN);
}


void User_Dem_Init(void)
{

     /*Dem_Init(&DemPbCfg);*/
}


void BSW_User_Shutdown(void)
{
	/*Dcm_DiagStorageRequiredBeforeReset(FALSE);*/
#ifdef DCM_DDDID_STORAGE_BLOCKID
    /*NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);*/
	/*NvM_WriteAll();*/
#endif
#ifdef GEELY_SPECIFICATION_USED
        NmHistoryState_DeInit();
#endif
}

static boolean EcuMRunTrigFlag = FALSE;
void BswM_EcuM_RequestRun(void)
{
    if(TRUE != EcuMRunTrigFlag)
    {
    	EcuMRunTrigFlag = TRUE;
        EcuM_RequestRUN(0u);
    }
}

void BswM_EcuM_ReleaseRun(void)
{
    if(FALSE != EcuMRunTrigFlag)
    {
    	EcuMRunTrigFlag = FALSE;
        EcuM_ReleaseRUN(0u);
    }
}


void BswM_EcuM_RequestPostRun(void)
{
	EcuM_RequestPOST_RUN(0u);

	BswM_AllowECU_Sleep();
}

void BswM_EcuM_ReleasePostRun(void)
{
	EcuM_ReleasePOST_RUN(0u);
}


