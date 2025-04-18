
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "EOL_Interface.h"
#include "ParaMgr.h"
#include "Dio_Service.h"
#include "Dio.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
/* set the EOL Channel to light */
const uint16 EOLSet_Low_Beam_Flat_W = 1;
const uint16 EOLSet_High_Beam_Sail_W = 16;
const uint16 EOLSet_Daytime_Running_Light_W = 36;
const uint16 EOLSet_Position_Light_W = 36;
const uint16 EOLSet_Turn_Indicator_W = 8;
const uint16 EOLSet_DCMotor_Supply_W = 128;

/* set the EOL Channel current to light */
const uint16 EOLSet_Current_CH1_W = 937;
const uint16 EOLSet_Current_Ch1_Tap_W = 937;
const uint16 EOLSet_Current_Ch2_W = 735;
const uint16 EOLSet_Current_Ch2_Alt_W = 904;
const uint16 EOLSet_Current_Ch3_W = 937;
const uint16 EOLSet_Current_Ch4_W = 834;
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

uint16_t Interface_EOLGetChannelMaskByLightFunction(Light_Functions lf)
{
	uint16_t rtval = 0;
	switch (lf)
	{
	case E_LowBeam:
		rtval = EOLSet_Low_Beam_Flat_W;
		break;
	case E_HighBeam:
		rtval = EOLSet_High_Beam_Sail_W;
		break;
	case E_DaytimeRunningLight:
		rtval = EOLSet_Daytime_Running_Light_W;
		break;
	case E_PositionLight:
		rtval = EOLSet_Position_Light_W;
		break;
	case E_TurnIndicator:
		rtval = EOLSet_Turn_Indicator_W;
		break;
	case E_DC_Motor:
		rtval = EOLSet_DCMotor_Supply_W;
		break;
	}
	return rtval;
}

uint16_t Interface_GetEOLChannelTableNormalCurrent(E_ChannelID id)
{
    uint16_t rtval = 0;
	switch (id)
	{
	case ChannelID1:
		rtval = EOLSet_Current_CH1_W;
		break;
	case ChannelID1_Tap:
		rtval = EOLSet_Current_Ch1_Tap_W;
		break;
	case ChannelID2:
		rtval = EOLSet_Current_Ch2_W;
		break;
	case ChannelID2_Alt:
		rtval = EOLSet_Current_Ch2_Alt_W;
		break;
	case ChannelID3:
		rtval = EOLSet_Current_Ch3_W;
		break;
	case ChannelID4:
		rtval = EOLSet_Current_Ch4_W;
		break;
	}
	return rtval;
}


void Interface_SetFanSwitchOff(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);
}
void Interface_SetFanSwitchOn(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);
}
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/






















