/*
 * AppCommonFunction.h
 *
 *  Created on: 2024/03/08
 *      Author: SiboWANG
 */

#ifndef GENERAL_APPCOMMONFUNCTION_H_
#define GENERAL_APPCOMMONFUNCTION_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Platform_Types.h"
#include "HcmPlatform.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
typedef enum{
	E_Light_Function_Status_OFF_Sts=0,
	E_Light_Function_Status_ON_Sts,
	E_Light_Function_Status_ERR_Sts,
	E_Light_Function_Status_RESD_Sts,
}E_Light_Function_Status;

typedef enum{
	E_Light_Function_Error_Status_NoError=0,
	E_Light_Function_Error_Status_Error,
}E_Light_Function_Error_Status;

typedef enum{
    E_Low_Beam_ID=0,

    E_Total_Light_Function_ID,
}E_Light_Function_ID;
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
void App_HCM_MainFunction(uint8_t timebase);

#endif /* HARDWARETEST_HWRT_H_ */
