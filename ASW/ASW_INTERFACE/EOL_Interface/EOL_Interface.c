
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "EOL_Interface.h"
#include "ParaMgr.h"
#include "Dio_Service.h"
#include "Dio.h"
#include "Channel_Interface.h"
#include "LinManager.h"
#include "Pwm_service.h"
#include "Rte_Dcm.h"
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


void Interface_SetFanSwitchOff(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);
}
void Interface_SetFanSwitchOn(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);
}

void EOL_Light_Main(void)
{
	uint8 pwm=100;
	uint16 cur=0;
	#if HARDWARE_TEST
	uint16 EOLSet_Current[CHANNEL_NUM]={1000, 1000,600, 600,600,139};
	uint8 FanOnFlag=0;
	if(1==Lighting_GetLinCtrl(E_LowBeam))/* CH1 CH1' on */
	{
		Pwm_HLCtrl_Enable();
		#if DERATE_FUNCTION
		pwm=Interface_GetSignal_ChannelPwm(ChannelID1);
		#endif
		cur=EOLSet_Current[ChannelID1]*CHANNELDRATE;
		Interface_ChannelOpen(ChannelID1,cur,pwm);
		FanOnFlag=1;
	}
	else 
	{
		if(1==Lighting_GetLinCtrl(E_HighBeam)) /* CH1 on ,CH1' off */
		{
			Pwm_HLCtrl_Disable(); /* only disable */
			#if DERATE_FUNCTION
			pwm=Interface_GetSignal_ChannelPwm(ChannelID1_Tap);
			#endif
			cur=EOLSet_Current[ChannelID1_Tap]*CHANNELDRATE;
			Interface_ChannelOpen(ChannelID1_Tap,cur,pwm);
			FanOnFlag=1;
		}
		else
		{
			Pwm_HLCtrl_Enable();
			Interface_ChannelClose(ChannelID1_Tap);
			Interface_ChannelClose(ChannelID1);
		}
	}
	if(1==Lighting_GetLinCtrl(E_TurnIndicator))//CH2'
	{
		Port_CH2Alt_Enable(0);
		Port_CH2_Disable();
		#if DERATE_FUNCTION
		pwm=Interface_GetSignal_ChannelPwm(ChannelID2_Alt);
		#endif
		cur=EOLSet_Current[ChannelID2_Alt]*CHANNELDRATE;
		Interface_ChannelOpen(ChannelID2_Alt,cur,pwm);
		FanOnFlag=1;
	}
	else if(1==Lighting_GetLinCtrl(E_PositionLight))//CH2
	{
		Port_CH2_Enable(0);
		Port_CH2Alt_Disable();
		#if DERATE_FUNCTION
		pwm=Interface_GetSignal_ChannelPwm(ChannelID2);
		#endif
		cur=EOLSet_Current[ChannelID2]*CHANNELDRATE;
		Interface_ChannelOpen(ChannelID2,cur,pwm);
		FanOnFlag=1;
	}
	else
	{
		Port_CH2_Disable();
		Port_CH2Alt_Disable();
		Interface_ChannelClose(ChannelID2);
		Interface_ChannelClose(ChannelID2_Alt);
	}

	if(1==Lighting_GetLinCtrl(E_PositionLight))//CH4
	{
		#if DERATE_FUNCTION
		pwm=Interface_GetSignal_ChannelPwm(ChannelID4);
		#endif
		cur=EOLSet_Current[ChannelID4]*CHANNELDRATE;
		Interface_ChannelOpen(ChannelID4,cur,pwm);
		FanOnFlag=1;
	}
	else
	{
		Interface_ChannelClose(ChannelID4);
	}
	if(1==Lighting_GetLinCtrl(E_FrontCrossLamp))//CH3
	{
		#if DERATE_FUNCTION
		pwm=Interface_GetSignal_ChannelPwm(ChannelID3);
		#endif
		cur=EOLSet_Current[ChannelID3]*CHANNELDRATE;
		Interface_ChannelOpen(ChannelID3,cur,pwm);
		FanOnFlag=1;
	}
	else
	{
		Interface_ChannelClose(ChannelID3);
	}
	if(FanOnFlag==1)
	{
		Port_FAN_Enable(); 
		Boost_Enable();
	}
	else
	{
		Port_FAN_Disable(); 
		Boost_Disable();
	}
#elif NORMAL_CODE
	uint16 EOLSet_Current[CHANNEL_NUM]={937, 937,735, 904,937,834};

	if(1==Lighting_GetLinCtrl(E_LowBeam))/* CH1 CH1' on */
	{
		Pwm_HLCtrl_Enable();
		Interface_ChannelOpen(ChannelID1,EOLSet_Current[ChannelID1],pwm);
	}
	else 
	{
		if(Interface_EOLGetCH1B_Switch()==1) /* CH1 on ,CH1' off */
		{
			Pwm_HLCtrl_Disable(); /* only disable */
			Interface_ChannelOpen(ChannelID1_Tap,EOLSet_Current[ChannelID1_Tap],pwm);
		}
		else
		{
			Pwm_HLCtrl_Enable();
			Interface_ChannelClose(ChannelID1_Tap);
			Interface_ChannelClose(ChannelID1);
		}
	}
	if(1==Lighting_GetLinCtrl(E_TurnIndicator))//CH2'
	{
		Port_CH2Alt_Enable(0);
		Port_CH2_Disable();
		Interface_ChannelOpen(ChannelID2_Alt,EOLSet_Current[ChannelID2_Alt],pwm);
	}
	else if(1==Lighting_GetLinCtrl(E_PositionLight))//CH2
	{
		Port_CH2_Enable(0);
		Port_CH2Alt_Disable();
		Interface_ChannelOpen(ChannelID2,EOLSet_Current[ChannelID2],pwm);
	}
	else
	{
		Port_CH2_Disable();
		Port_CH2Alt_Disable();
		Interface_ChannelClose(ChannelID2);
		Interface_ChannelClose(ChannelID2_Alt);
	}

	if(1==Lighting_GetLinCtrl(E_PositionLight))//CH4
	{
		Interface_ChannelOpen(ChannelID4,EOLSet_Current[ChannelID4],pwm);
	}
	else
	{
		Interface_ChannelClose(ChannelID4);
	}
	if(1==Lighting_GetLinCtrl(E_HighBeam))//CH3
	{
		Interface_ChannelOpen(ChannelID3,EOLSet_Current[ChannelID3],pwm);
	}
	else
	{
		Interface_ChannelClose(ChannelID3);
	}
	#endif
}


/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/






















