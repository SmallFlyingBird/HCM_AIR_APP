// /*
//  * MotorDrvDev_Interface.c
//  *
//  *  Created on: 2024Äê1ÔÂ11ÈÕ
//  *      Author: mihuiliang
//  */

// /****************************************************************
//  *                                                              *
//  *                     Include Files                            *
//  *                                                              *
//  ****************************************************************/
// #include "MotorDrvDev_Interface.h"


// /****************************************************************
//  *                                                              *
//  *                  Global Private Variable Define              *
//  *                                                              *
//  ****************************************************************/
// static S_MotorDrv_Dev* g_S_MotorDrv_Dev_Header=NULL;

// /****************************************************************
//  *                                                              *
//  *                   Private Functions Define                   *
//  *                                                              *
//  ****************************************************************/


// /****************************************************************
//  *                                                              *
//  *                   Global Functions Define                    *
//  *                                                              *
//  ****************************************************************/

// S_MotorDrv_Dev* GetMotorDrvByMotorTpye(E_MotorTpye MotorType)
// {
// 	S_MotorDrv_Dev* tmp=g_S_MotorDrv_Dev_Header;
// 	while(tmp!=NULL)
// 	{
// 		if(tmp->MotorType == MotorType )
// 			return tmp;
// 		tmp=tmp->ptNext;
// 	}
// 	return NULL;
// }
// Std_ReturnType MotorDrvDev_Register(S_MotorDrv_Dev* Drv_Dev)
// {
// 	S_MotorDrv_Dev* tmp=g_S_MotorDrv_Dev_Header;

// 	if(g_S_MotorDrv_Dev_Header==NULL)
// 	{
// 		g_S_MotorDrv_Dev_Header=Drv_Dev;
// 		g_S_MotorDrv_Dev_Header->ptNext=NULL;
// 	}else
// 	{
// 		while(tmp->ptNext!=NULL)
// 			tmp=tmp->ptNext;
// 		tmp->ptNext=Drv_Dev;
// 		Drv_Dev->ptNext=NULL;
// 	}
// 	return E_OK;
// }
