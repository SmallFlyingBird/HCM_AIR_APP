/*
 * LowBeam.h
 *
 *  Created on: 2024/03/11
 *      Author: SiboWANG
 */

#ifndef LOWBEAM_LOWBEAM_H_
#define LOWBEAM_LOWBEAM_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Platform_Types.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef struct LowBeam_Light_Info{
	// E_Light_Function_Status	Low_Beam_Function_Status;
	// E_Light_Function_Error_Status Low_Beam_Function_Error_Status;
	uint32 Low_Beam_Light_On_Time;
	uint16 HWRT_Channels_Current_Info[12];
}S_LowBeam_Light_Info;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
void Low_Beam_MainFunction(uint8 timebase);
#endif /* HARDWARETEST_HWRT_H_ */
