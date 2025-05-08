
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
#include "HcmPlatform.h"
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

/* These two(pwm and cur) are set as local variables will behave abnormally */
uint8 pwm=100;
uint16 cur=0;
uint16 EMCSet_Current[CHANNEL_NUM]={1000, 1000,600, 600,600,139};
uint16 EOLSet_Current[CHANNEL_NUM]={937, 937,735, 904,937,834};
void EOL_Light_Main(void)
{
	pwm = 100;
	cur = 0;

	uint8 FanOnFlag=0;
	if(1==Lighting_GetLinCtrl(E_LowBeam))/* CH1 CH1' on */
	{
		Pwm_HLCtrl_Enable();
		pwm=Interface_GetSignal_ChannelPwm(ChannelID1);
		cur=EOLSet_Current[ChannelID1];
		Interface_ChannelOpen(ChannelID1,cur,pwm);
		FanOnFlag=1;
	}
	else 
	{
		if(1==Lighting_GetLinCtrl(E_HighBeam)) /* CH1 on ,CH1' off */
		{
			Pwm_HLCtrl_Disable(); /* only disable */
			pwm=Interface_GetSignal_ChannelPwm(ChannelID1_Tap);
			cur=EOLSet_Current[ChannelID1_Tap];
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
		pwm=Interface_GetSignal_ChannelPwm(ChannelID2_Alt);
		cur=EOLSet_Current[ChannelID2_Alt];
		Interface_ChannelOpen(ChannelID2_Alt,cur,pwm);
		FanOnFlag=1;
	}
	else if(1==Lighting_GetLinCtrl(E_PositionLight))//CH2
	{
		Port_CH2_Enable(0);
		Port_CH2Alt_Disable();
		pwm=Interface_GetSignal_ChannelPwm(ChannelID2);
		cur=EOLSet_Current[ChannelID2];
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

	if((1==Lighting_GetLinCtrl(E_PositionLight))||(1==Lighting_GetLinCtrl(E_DaytimeRunningLight)))//CH4
	{
		pwm=Interface_GetSignal_ChannelPwm(ChannelID4);
		cur=EOLSet_Current[ChannelID4];
		Interface_ChannelOpen(ChannelID4,cur,pwm);
		FanOnFlag=1;
	}
	else
	{
		Interface_ChannelClose(ChannelID4);
	}
	if(1==Lighting_GetLinCtrl(E_FrontCrossLamp))//CH3
	{
		pwm=Interface_GetSignal_ChannelPwm(ChannelID3);
		cur=EOLSet_Current[ChannelID3];
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
}



void EMC_Light_Main(void)
{
	uint8 FanOnFlag=0;
	pwm = 100;
	cur = 0;

	if(1==Lighting_GetLinCtrl(E_LowBeam))/* CH1 CH1' on */
	{
		pwm=Interface_GetSignal_ChannelPwm(ChannelID1);
		cur = EMCSet_Current[ChannelID1];
		Interface_GetSignal_ChannelCurrent(ChannelID1);

		if(pwm == 0)
		{
			Pwm_HLCtrl_Disable();
			Interface_ChannelClose(ChannelID1);
			FanOnFlag=0;
		}
		else
		{
			Pwm_HLCtrl_Enable();
			Interface_ChannelOpen(ChannelID1,cur,pwm);
			FanOnFlag=1;
		}

	}
	else 
	{
		if(1==Lighting_GetLinCtrl(E_HighBeam)) /* CH1 on ,CH1' off */
		{
			Pwm_HLCtrl_Disable(); /* only disable */

			pwm=Interface_GetSignal_ChannelPwm(ChannelID1_Tap);

			cur= EMCSet_Current[ChannelID1_Tap];
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

		pwm=Interface_GetSignal_ChannelPwm(ChannelID2_Alt);

		cur= EMCSet_Current[ChannelID2_Alt];
		Interface_ChannelOpen(ChannelID2_Alt,cur,pwm);
		FanOnFlag=1;
	}
	else if(1==Lighting_GetLinCtrl(E_PositionLight))//CH2
	{
		Port_CH2_Enable(0);
		Port_CH2Alt_Disable();
		pwm=Interface_GetSignal_ChannelPwm(ChannelID2);
		cur= EMCSet_Current[ChannelID2];
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

	if((1==Lighting_GetLinCtrl(E_PositionLight))||(1==Lighting_GetLinCtrl(E_DaytimeRunningLight)))//CH4
	{
		pwm=Interface_GetSignal_ChannelPwm(ChannelID4);
		cur= EMCSet_Current[ChannelID4];
		Interface_ChannelOpen(ChannelID4,cur,pwm);
		FanOnFlag=1;
	}
	else
	{
		Interface_ChannelClose(ChannelID4);
	}
	if(1==Lighting_GetLinCtrl(E_FrontCrossLamp))//CH3
	{
		pwm=Interface_GetSignal_ChannelPwm(ChannelID3);
		cur= EMCSet_Current[ChannelID3];
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
}
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/






















