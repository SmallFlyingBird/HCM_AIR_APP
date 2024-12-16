/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Callout.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-12 15:33:32>
 */
/*============================================================================*/

#include "Dcm_Internal.h"

/** The physical memory location of boot request flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_BOOT_MODE        	/*TODO：need to add address*/
/** The physical memory location of application software update flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_APPL_UPDATE      /*TODO：need to add address*/	

Std_ReturnType Dcm_SetProgConditions(
Dcm_OpStatusType OpStatus,
Dcm_ProgConditionsType * ProgConditions
)
{
    /*TODO：Set ReProgramingRequest Flag*/
	/*e.g*/
	/*(*(uint8 *)FL_BOOT_MODE) = 0x2A;*/
    return E_OK;
}

Dcm_EcuStartModeType Dcm_GetProgConditions(
Dcm_ProgConditionsType * ProgConditions
)
{
	/*TODO：check ApplUpdated*/
	/*e.g*/
    /*if (0xD5 == (*(uint8*)FL_APPL_UPDATE))*/
    /*{*/
    /*    ProgConditions->ApplUpdated = TRUE;*/
    /*    (*(uint8*) FL_APPL_UPDATE) = 0x00;/*clear App updata flag*/
    /*    return DCM_WARM_START;*/
    /*}*/
    return DCM_COLD_START;
}


void Rte_EnableAllDtcsRecord(void)
{
   /*The update of the DTC status bit information shall continue once a ControlDTCSetting request is performed
     with sub-function set to on or a session layer timeout occurs (server transitions to defaultSession. */
    /* (void)Dem_EnableDTCStorage(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);*/
}

