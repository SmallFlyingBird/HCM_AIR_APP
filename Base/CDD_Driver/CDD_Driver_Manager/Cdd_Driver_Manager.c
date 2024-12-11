/*
 * Cdd_Driver_Manager.c
 *
 *  Created on: 2024��2��17��
 *      Author: mihuiliang
 */


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "PulseGeneratorDrv.h"
#include "AdcDrv.h"
#include "DrvTps2HB35.h"
#include "BD18397_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/


/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType CDD_Init(void)
{
	Std_ReturnType rtval=E_OK;
	rtval|=CddDriver_DrvTps2HB35Init();
	rtval|=CddDriver_PulseGeneratorInit(); //电机任务启动
	rtval|=CddDriver_AdcDrvInit();
	rtval|=CddDriver_18397Init();
	return rtval;
}
