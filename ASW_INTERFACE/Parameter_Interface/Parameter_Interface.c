#include "HcmPlatform.h"
#include "ParaMgr.h"
#include "Parameter_Interface.h"
/****************************************************************************************************/
/****************************************************************************************************/
/********************************Mapping related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint16_t GetChannelMaskByLightFunction(Light_Functions lf)
{
	uint16_t rtval = 0;
	switch (lf)
	{
	case E_LowBeamKink:
		rtval = ParaMgr_Low_Beam_Flat_W;
		break;
	case E_HighBeamSpot:
		rtval = ParaMgr_High_Beam_Sail_W;
		break;
	case E_DaytimeRunningLight:
		rtval = ParaMgr_Daytime_Running_Light_W;
		break;
	case E_PositionLight:
		rtval = ParaMgr_Position_Light_W;
		break;
	case E_TurnIndicator:
		rtval = ParaMgr_Turn_Indicator_W;
		break;
	case E_CorneringLight:
		rtval = ParaMgr_Cornering_Light_W;
		break;
	case E_FogLamp:
		rtval = ParaMgr_Fog_Lamp_W;
		break;
	case E_LogoLamp:
		rtval = ParaMgr_Logo_Lamp_W;
		break;
	case E_FrontCrossLamp:
		rtval = ParaMgr_Front_Cross_Lamp_W;
		break;
	case E_GrilleLamp:
		rtval = ParaMgr_Grille_Lamp_W;
		break;
	case E_AssistantLight:
		rtval = ParaMgr_Assistant_Light_W;
		break;
	case E_Fan2:
		rtval = ParaMgr_Fan2_W;
		break;
	case E_SideMarkerLamp:
		rtval = ParaMgr_Side_Marker_Lamp_W;
		break;
	case E_DC_Motor:
		rtval = ParaMgr_DCMotor_Supply_W;
		break;
	}
	return rtval;
}


/*找到通道所对应的灯具功能的掩码*/
uint16_t GetLightFunctionsMaskByChNo(E_ChannelID channelno)
{
	uint16_t LightFunctionsMask = 0;
	switch (channelno)
	{
	case ChannelID1:
		LightFunctionsMask = ParaMgr_CH1_LF_MASK_W;
		break;
	case ChannelID2:
		LightFunctionsMask = ParaMgr_CH2_LF_MASK_W;
		break;
	case ChannelID3:
		LightFunctionsMask = ParaMgr_CH3_LF_MASK_W;
		break;
	case ChannelID4:
		LightFunctionsMask = ParaMgr_CH4_LF_MASK_W;
		break;
	case ChannelID1_Tap:
		LightFunctionsMask = ParaMgr_CH1Tap_LF_MASK_W;
		break;
	case ChannelID2_Alt:
		LightFunctionsMask = ParaMgr_CH2Alt_LF_MASK_W;
		break;
	}
	return LightFunctionsMask;
}

uint16_t Get_DRL_TI_surfaces_Near(void)
{
	return ParaMgr_DRL_TI_surfaces_Near_W;
}

uint16_t Get_DRL_TI_surfaces_apparent(void)
{
	return ParaMgr_DRL_TI_surfaces_apparent_W;
}

uint16_t Get_POS_TI_surfaces_apparent(void)
{
	return ParaMgr_POS_TI_surfaces_apparent_W;
}

uint16_t Get_LightN_1(void)
{
	return ParaMgr_LightN_1_W;
}
/****************************************************************************************************/
/****************************************************************************************************/
/*****************************ChnConfig_Derating related Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8_t Get_pChannelEnable(E_ChannelID index)
{
	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pCh1Ena_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pCh2Ena_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pCh3Ena_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pCh4Ena_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pCh1_TapEna_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pCh2_AltEna_B;
		break;
	default:
		rtval = 0x0;
		break;
	}
	return rtval;
}

/*return voltage*10v  */
uint16_t Get_pLedUminVoltage(E_ChannelID index)
{
	uint16_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pCh1MinVolt_W;
		break;
	case ChannelID2:
		rtval = ParaMgr_pCh2MinVolt_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pCh3MinVolt_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pCh4MinVolt_W;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pCh1_TapMinVolt_W;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pCh2_AltMinVolt_W;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}

/*return voltage*10v  */
uint16_t Get_pLedUmaxVoltage(E_ChannelID index)
{
	uint16_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pCh1MaxVolt_W;
		break;
	case ChannelID2:
		rtval = ParaMgr_pCh2MaxVolt_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pCh3MaxVolt_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pCh4MaxVolt_W;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pCh1_TapMaxVolt_W;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pCh2_AltMaxVolt_W;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}


uint16_t Get_pLedNormalCurrent(E_ChannelID index)
{
	uint16_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedNomCurrent_CH1_W;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedNomCurrent_Ch2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedNomCurrent_Ch3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedNomCurrent_Ch4_W;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedNomCurrent_Ch1_Tap_W;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedNomCurrent_Ch2_Alt_W;
		break;
	default:
		rtval = 0xFFFF;
		break;
	}
	return rtval;
}

uint16_t Get_pLedMinCurrent(E_ChannelID index)
{
	uint16_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedMinCurrent_CH1_W;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedMinCurrent_Ch2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedMinCurrent_Ch3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedMinCurrent_Ch4_W;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedMinCurrent_Ch1_Tap_W;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedMinCurrent_Ch2_Alt_W;
		break;
	default:
		rtval = 0xFFFF;
		break;
	}

	return rtval;
}

uint16_t Get_pLedMaxCurrent(E_ChannelID index)
{
	uint16_t rtval = 0;

	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedMaxCurrent_CH1_W;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedMaxCurrent_Ch2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedMaxCurrent_Ch3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedMaxCurrent_Ch4_W;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedMaxCurrent_Ch1_Tap_W;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedMaxCurrent_Ch2_Alt_W;
		break;
	default:
		rtval = 0xFFFF;
		break;
	}

	return rtval;
}

uint16_t Get_pLedPmaxPower(E_ChannelID index)
{
	uint16_t rtval = 0;

	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedPmaxPower_CH1_W;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedPmaxPower_Ch2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedPmaxPower_Ch3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedPmaxPower_Ch4_W;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedPmaxPower_Ch1_Tap_W;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedPmaxPower_Ch2_Alt_W;
		break;
	default:
		rtval = 0xFFFF;
		break;
	}

	return rtval;
}

/*
 *  return 0 means -40°
 *  return 1 means -39°
 */
uint8_t Get_pLedDerTemp1(E_ChannelID index)
{
	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerTemp1_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerTemp1_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerTemp1_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerTemp1_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerTemp1_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerTemp1_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}

uint8_t Get_pLedDerTemp2(E_ChannelID index)
{

	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerTemp2_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerTemp2_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerTemp2_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerTemp2_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerTemp2_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerTemp2_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}
	return rtval;
}

uint8_t Get_pLedDerTemp3(E_ChannelID index)
{
	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerTemp3_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerTemp3_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerTemp3_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerTemp3_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerTemp3_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerTemp3_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}
	return rtval;
}

uint8_t Get_pLedDerTemp4(E_ChannelID index)
{
	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerTemp4_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerTemp4_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerTemp4_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerTemp4_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerTemp4_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerTemp4_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}

uint8_t Get_pLedDerTemp5(E_ChannelID index)
{
	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerTemp5_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerTemp5_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerTemp5_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerTemp5_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerTemp5_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerTemp5_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}
	return rtval;
}

uint8_t Get_pLedDerPwrA(E_ChannelID channelno)
{
	uint8_t rtval = 0;
	switch (channelno)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerPwrA_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerPwrA_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerPwrA_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerPwrA_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerPwrA_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerPwrA_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}
	return rtval;
}

uint8_t Get_pLedDerPwrB(E_ChannelID channelno)
{
	uint8_t rtval = 0;
	switch (channelno)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerPwrB_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerPwrB_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerPwrB_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerPwrB_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerPwrB_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerPwrB_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}
uint8_t Get_pLedDerPwrC(E_ChannelID channelno)
{
	uint8_t rtval = 0;
	switch (channelno)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedDerPwrC_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedDerPwrC_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedDerPwrC_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedDerPwrC_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedDerPwrC_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedDerPwrC_Ch2_Alt_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}

uint8_t Get_pLedDerMinCurrLoBeamFlat(void)
{
	return ParaMgr_pLedDerMinCurrLoBeamFlat_B;
}

uint8_t Get_pLedDerMinCurrDirIndcr(void)
{
	return ParaMgr_pLedDerMinCurrDirIndcr_B;
}

uint8_t Get_pLedDerTempHys(void)
{
	return ParaMgr_pLedDerTempHys_B;
}
/*
 * return
 * 0 means invalied
 * 1 means -49
 * 2 means -48
 * 160 means 150
 * 参数配置表 温度范围  -49℃~29℃ 70℃~150℃
 *           对应序号    1 ~ 79   80 ~ 160
 */
uint8_t GetNtcTempByRegisterVal(uint32 register_val, uint8_t ntctype)
{
	const uint32 *ntctmpdata;
	uint8_t i = 0;

	if (ntctype == 1)
		ntctmpdata = ParaMgr_NTCType1_DW;
	else if (ntctype == 2)
		ntctmpdata = ParaMgr_NTCType2_DW;
	else
		return 0;

	for (i = 0; i < 160; i++)
	{
		if (register_val <= ntctmpdata[i] && register_val >= ntctmpdata[i + 1])
		{
			/*find temp*/		
			if(i<=79)
			{
				return (i + 1);
			}
			else
			{
				return (i + 41);
			}
			
		}
	}

	return 0;
}

/*
 *  MtxNtcIndex: 1 Matrix NTC type1; 2 Matrix NTC type2;
 *  return value :  Min 0   -> -50°
 *                  Max 200 -> 150°
 * 					0xFF means not finded
 */
uint8_t GetNtcTempByMatrixADCVal(uint8_t adcval, uint8 MtxNtcIndex)
{
	uint8 matrixntctype;
	if (MtxNtcIndex != 1 && MtxNtcIndex != 2)
		return 0xFF;

	if (MtxNtcIndex == 1)
	{
		matrixntctype = Get_pNtcType(6);
	}
	else
	{
		matrixntctype = Get_pNtcType(7);
	}
	return 0xFF;
}

/*
 * return 0 means -50锟斤拷      --->min
 * return 50 means 0锟斤拷
 * return 100 means 50锟斤拷
 * return 150 means 100锟斤拷
 * return 200 means 150锟斤拷	--->max
 *
 */
uint8_t Get_pNtcFaultTemp(uint8_t ntcid)
{
	uint8_t rtval = 0;
	switch (ntcid)
	{
	case 1:
		rtval = ParaMgr_pNtcFaultTemp_1_B;
		break;
	case 2:
		rtval = ParaMgr_pNtcFaultTemp_2_B;
		break;
	case 3:
		rtval = ParaMgr_pNtcFaultTemp_3_B;
		break;
	case 4:
		rtval = ParaMgr_pNtcFaultTemp_4_B;
		break;
	case 5:
		rtval = ParaMgr_pNtcFaultTemp_5_B;
		break;
    case 6:
		rtval = ParaMgr_pNtcFaultTemp_6_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}

uint8_t Get_pNtcType(uint8_t ntcid)
{
	uint8_t rtval = 0;
	switch (ntcid)
	{
	case 1:
		rtval = ParaMgr_pNtcType_1_B;
		break;
	case 2:
		rtval = ParaMgr_pNtcType_2_B;
		break;
	case 3:
		rtval = ParaMgr_pNtcType_3_B;
		break;
	case 4:
		rtval = ParaMgr_pNtcType_4_B;
		break;
	case 5:
		rtval = ParaMgr_pNtcType_5_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}

uint8_t Get_pLedChToNtc(E_ChannelID index)
{
	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pLedChToNtc_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pLedChToNtc_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedChToNtc_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedChToNtc_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pLedChToNtc_Ch5_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pLedChToNtc_Ch6_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}

/****************************************************************************************************/
/****************************************************************************************************/
/***********************************Rcod related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint8_t Get_pRcodEnable(void)
{
	return ParaMgr_pRcodEnable_B;
}

/*
 * IsMatrixIndex=0
 *  pBinSrcCh 1->Rcod1 2->Rcod2 3->Rcod3
 * IsMatrixIndex=1
 *  pBinSrcCh 1->MtxRcod1 2->MtxRcod2
 */

uint16_t GetRcodCurrentByRcodIndex(uint8_t index, uint8_t pBinSrcCh, uint8_t IsMatrixIndex)
{
	uint16_t rtval = 0xFFFF;
	if (IsMatrixIndex == 0)
	{
		if (index == 1)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_1_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_1_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_1_W;
			}
		}
		else if (index == 2)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_2_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_2_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_2_W;
			}
		}
		else if (index == 3)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_3_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_3_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_3_W;
			}
		}
		else if (index == 4)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_4_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_4_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_4_W;
			}
		}
		else if (index == 5)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_5_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_5_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_5_W;
			}
		}
		else if (index == 6)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_6_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_6_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_6_W;
			}
		}
		else if (index == 7)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_7_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_7_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_7_W;
			}
		}
		else if (index == 8)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_8_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_8_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_8_W;
			}
		}
		else if (index == 9)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_9_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_9_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_9_W;
			}
		}
		else if (index == 10)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLedCurrent1_10_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLedCurrent2_10_W;
			}
			else if (pBinSrcCh == 3)
			{
				rtval = ParaMgr_pCodeLedCurrent3_10_W;
			}
		}
	}

	return rtval;
}

/*
 *  pBinSrcCh: 1 Rcod1; 2 Rcod2; 3 Rcod3;
 *  return 0Xffff means did not find related current through Register
 */
uint16_t GetRcodCurrentByRegisterVal(uint32 register_val, uint8_t pBinSrcCh)
{
	uint16_t rtval = 0xFFFF;
	uint32 register_val_cmp;
	register_val_cmp = register_val;

	if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_1_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_1_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_1_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_1_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_1_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_2_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_2_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_2_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_2_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_2_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_3_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_3_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_3_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_3_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_3_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_4_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_4_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_4_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_4_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_4_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_5_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_5_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_5_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_5_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_5_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_6_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_6_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_6_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_6_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_6_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_7_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_7_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_7_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_7_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_7_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_8_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_8_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_8_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_8_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_8_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_9_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_9_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_9_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_9_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_9_W;
		}
	}
	else if (register_val_cmp >= (uint32_t)ParaMgr_pCodeRefFieldL_10_W && register_val_cmp <= (uint32_t)ParaMgr_pCodeRefFieldH_10_W)
	{
		if (pBinSrcCh == 1)
		{
			rtval = ParaMgr_pCodeLedCurrent1_10_W;
		}
		else if (pBinSrcCh == 2)
		{
			rtval = ParaMgr_pCodeLedCurrent2_10_W;
		}
		else if (pBinSrcCh == 3)
		{
			rtval = ParaMgr_pCodeLedCurrent3_10_W;
		}
	}

	return rtval;
}

uint8_t Get_pDefaultRcodIndexChByChannelID(E_ChannelID index)
{
	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch2_Alt_B;
		break;
	default:
		rtval = 0xFF;
		break;
	}

	return rtval;
}

uint8_t Get_pHSDxOLEnable(uint8_t HsdID)
{
	if(HsdID == 1 )
	{
		return ParaMgr_pHSD1OLEnable_B;
	}
	else if(HsdID == 2)
	{
		return ParaMgr_pHSD2OLEnable_B;
	}	
	return 1;
}

uint8_t Get_pHSDIOutOC(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS0:
			return ParaMgr_pHSD1IOutOC_B;
		case E_HSChannel_HS1:
			return ParaMgr_pHSD2IOutOC_B;
	}
}

uint16_t Get_pIOutSCGHSD(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS0:
			return ParaMgr_pIOutSCGHSD1_W;
		case E_HSChannel_HS1:
			return ParaMgr_pIOutSCGHSD2_W;
	}
}

uint8_t Get_pHSDMaxVolt(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS0:
			return ParaMgr_pHSD1MaxVolt_B;
		case E_HSChannel_HS1:
			return ParaMgr_pHSD2MaxVolt_B;
	}
}

uint8_t Get_pHSDMinVolt(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS0:
			return ParaMgr_pHSD1MinVolt_B;
		case E_HSChannel_HS1:
			return ParaMgr_pHSD2MinVolt_B;
	}
}
/*
 * return 0: No
 * return 1: NTC1
 * return 2: NTC2
 * retrun 3: NTC3
 * return 4: NTC4
 * return 5: NTC5
 */
uint8_t Get_pBinRcodToNTC(uint8 Rcod)
{
	uint8_t rtval = 0;
	switch (Rcod)
	{
	case 1:
		rtval = ParaMgr_pBinRcod1NTC_B;
		break;
	case 2:
		rtval = ParaMgr_pBinRcod2NTC_B;
		break;
	case 3:
		rtval = ParaMgr_pBinRcod3NTC_B;
		break;
	default:
		rtval = 0;
		break;
	}

	return rtval;
}
/*
 * return 0: No Rcod
 * return 1: Rcod1
 * return 2: Rcod2
 * retrun 3: Rcod3
 * return 4: MtxRcod1
 * return 5: MtxRcod2
 */
uint8_t Get_pBinSrcChByChannelID(E_ChannelID index)
{

	uint8_t rtval = 0;
	switch (index)
	{
	case ChannelID1:
		rtval = ParaMgr_pBinSrcCh_Ch1_B;
		break;
	case ChannelID2:
		rtval = ParaMgr_pBinSrcCh_Ch2_B;
		break;
	case ChannelID3:
		rtval = ParaMgr_pBinSrcCh_Ch3_B;
		break;
	case ChannelID4:
		rtval = ParaMgr_pBinSrcCh_Ch4_B;
		break;
	case ChannelID1_Tap:
		rtval = ParaMgr_pBinSrcCh_Ch1_Tap_B;
		break;
	case ChannelID2_Alt:
		rtval = ParaMgr_pBinSrcCh_Ch2_Alt_B;
		break;
	default:
		rtval = 0xFF;
		break;
	}

	return rtval;
}

/*******************************************************************Light Function: Type**************************************************************/
/*
 * vehicle LVL type, 0=LVL not available, 1=manual LVL, 2=automatic LVL, 3=reserved
 */
uint8_t Get_pVehLvLType(void)
{
	return ParaMgr_pVehLvLType_B;
}
/*Automatic driving beam configuration paramter. One of: 0=No Glare Free HB; 1=AHB; 2=AHB2; 3=ADB*/
uint8_t Get_pAHBCType(void)
{
	return ParaMgr_pAHBCTyp_B;
}

uint8_t  Get_pDCMotrCntrlSCG(void)     { return  ParaMgr_pDCMotrCntrlSCG_B; }
uint8_t  Get_pDCMotrCntrlSCB(void)     { return  ParaMgr_pDCMotrCntrlSCB_B; }
uint16_t Get_pIOutStallDCMotrHSD(void) { return  ParaMgr_pIOutStallDCMotrHSD_W; }
uint8_t  Get_pManLvlDCPos1(void)       { return  ParaMgr_pManLvlDCPos1_B; }
uint8_t  Get_pManLvlDCPos2(void)       { return  ParaMgr_pManLvlDCPos2_B; }
uint8_t  Get_pManLvlDCPos3(void)       { return  ParaMgr_pManLvlDCPos3_B; }
uint8_t  Get_pManLvlDCPos4(void)       { return  ParaMgr_pManLvlDCPos4_B; }
uint8_t  Get_pManLvlDCPos5(void)       { return  ParaMgr_pManLvlDCPos5_B; }
uint8_t  Get_pLVLSafetyPosDC(void)     { return  ParaMgr_pLVLSafetyPosDC_B; }
uint8_t  Get_pDCMotrCntrlLowrThd(void) { return  ParaMgr_pDCMotrCntrlLowrThd_B; }
uint8_t  Get_pDCMotrCntrlUpprThd(void) { return  ParaMgr_pDCMotrCntrlUpprThd_B; }
uint16_t Get_pDCMotrDeactDlyTi(void)   { return  ParaMgr_pDCMotrDeactDlyTi_W; }

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Light Control related Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint16_t Get_pLedTimeUpPosTi(void)
{
	return ParaMgr_pLedTimeUpPosTi_W;
}

uint8_t Get_pLedIntensityPos(void)
{
	return ParaMgr_pLedIntensityPos_B;
}

uint8_t Get_pLedIntensityPosTi(void)
{
	return ParaMgr_pLedIntensityPosTi_B;
}

uint16_t Get_pLedTimeUpDrlTi(void)
{
	return ParaMgr_pLedTimeUpDrlTi_W;
}

uint8_t Get_pLedIntensityDrlTi(void)
{
	return ParaMgr_pLedIntensityDrlTi_B;
}

uint8_t Get_pLedIntensityDrlTi40mm(void)
{
	return ParaMgr_pLedIntensityDrlTi40mm_B;
}

uint8_t Get_pLedSeqTiHwl(void)
{
	return ParaMgr_pLedSeqTiHwl_B;
}

uint8_t Get_pLedONDelay(Light_Functions lf)
{
	uint8_t rtval;

	switch (lf)
	{
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOnDelay_B;
		break;

	case E_HighBeamSpot:
		rtval = ParaMgr_pLedHiBeamOnDelay_B;
		break;

	case E_PositionLight:
		rtval = ParaMgr_pLedPosOnDelay_B;
		break;

	case E_FogLamp:
		rtval = ParaMgr_pLedFogOnDelay_B;
		break;

	case E_DaytimeRunningLight:
		rtval = ParaMgr_pLedDRLOnDelay_B;
		break;

	case E_TurnIndicator:
#if HCM_LEFT_SIDE
		rtval = ParaMgr_LeLamp_pLedDirIndcrBeamOnDelayLe_B;
#else
		rtval = ParaMgr_RiLamp_pLedDirIndcrBeamOnDelayRi_B;
#endif
		break;

	case E_CorneringLight:
		rtval = ParaMgr_pLedCornrgOnDelay_B;
		break;

	case E_LogoLamp:
		rtval = ParaMgr_pLedLogoOnDelay_B;
		break;

	case E_FrontCrossLamp:
		rtval = ParaMgr_pLedFrntCrossOnDelay_B;
		break;

	case E_GrilleLamp:
		rtval = ParaMgr_pLedGrilleOnDelay_B;
		break;
	}

	return rtval;
}

uint8_t Get_pLedOFFDelay(Light_Functions lf)
{
	uint8_t rtval = 0;
	switch (lf)
	{
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOFFDelay_B;
		break;

	case E_HighBeamSpot:
		rtval = ParaMgr_pLedHiBeamOFFDelay_B;
		break;

	case E_PositionLight:
		rtval = ParaMgr_pLedPosOFFDelay_B;
		break;

	case E_FogLamp:
		rtval = ParaMgr_pLedFogOFFDelay_B;
		break;

	case E_DaytimeRunningLight:
		rtval = ParaMgr_pLedDRLOFFDelay_B;
		break;

	case E_TurnIndicator:
#if HCM_LEFT_SIDE
		rtval = ParaMgr_LeLamp_pLedDirIndcrBeamOFFDelayLe_B;
#else
		rtval = ParaMgr_RiLamp_pLedDirIndcrBeamOFFDelayRi_B;
#endif
		break;

	case E_CorneringLight:
		rtval = ParaMgr_pLedCornrgOFFDelay_B;
		break;

	case E_LogoLamp:
		rtval = ParaMgr_pLedLogoOFFDelay_B;
		break;

	case E_FrontCrossLamp:
		rtval = ParaMgr_pLedFrntCrossOFFDelay_B;
		break;

	case E_GrilleLamp:
		rtval = ParaMgr_pLedGrilleOFFDelay_B;
		break;
	}

	return rtval;
}

uint16_t Get_pLedOnRampTi(Light_Functions lf)
{
	uint16_t rtval = 0;
	switch (lf)
	{
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOnRampTi_W;
		break;

	case E_HighBeamSpot:
		rtval = ParaMgr_pLedHiBeamOnRampTi_W;
		break;

	case E_PositionLight:
		rtval = ParaMgr_pLedPosLiOnRampTi_W;
		break;

	case E_FogLamp:
		rtval = ParaMgr_pLedFogLiOnRampTi_W;
		break;

	case E_DaytimeRunningLight:
		rtval = ParaMgr_pLedDRLOnRampTi_W;
		break;

	case E_TurnIndicator:
#if HCM_LEFT_SIDE
		rtval = ParaMgr_pLedDirIndcrOnRampTi_W;
#else
		rtval = ParaMgr_pLedDirIndcrOnRampTi_W;
#endif
		break;

	case E_CorneringLight:
		rtval = ParaMgr_pLedCornrgOnRampTi_W;
		break;

	case E_LogoLamp:
		rtval = ParaMgr_pLedLogoLiOnRampTi_W;
		break;

	case E_FrontCrossLamp:
		rtval = ParaMgr_pLedFrntCrossLiOnRampTi_W;
		break;

	case E_GrilleLamp:
		rtval = ParaMgr_pLedGrilleLiOnRampTi_W;
		break;
	}

	return rtval;
}

uint16_t Get_pLedOffRampTi(Light_Functions lf)
{
	uint16_t rtval = 0;
	switch (lf)
	{
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOFFRampTi_W;
		break;

	case E_HighBeamSpot:
		rtval = ParaMgr_pLedHiBeamOFFRampTi_W;
		break;

	case E_PositionLight:
		rtval = ParaMgr_pLedPosLiOFFRampTi_W;
		break;

	case E_FogLamp:
		rtval = ParaMgr_pLedFogLiOFFRampTi_W;
		break;

	case E_DaytimeRunningLight:
		rtval = ParaMgr_pLedDRLOFFRampTi_W;
		break;

	case E_TurnIndicator:
#if HCM_LEFT_SIDE
		rtval = ParaMgr_pLedDirIndcrOFFRampTi_W;
#else
		rtval = ParaMgr_pLedDirIndcrOFFRampTi_W;
#endif
		break;

	case E_CorneringLight:
		rtval = ParaMgr_pLedCornrgOFFRampTi_W;
		break;

	case E_LogoLamp:
		rtval = ParaMgr_pLedLogoLiOFFRampTi_W;
		break;

	case E_FrontCrossLamp:
		rtval = ParaMgr_pLedFrntCrossLiOFFRampTi_W;
		break;

	case E_GrilleLamp:
		rtval = ParaMgr_pLedGrilleLiOFFRampTi_W;
		break;
	}

	return rtval;
}


/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Fan Parameter*****************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint16_t Get_pFanToChannel(void)        { return ParaMgr_pFanToChannel_W; }
uint16_t Get_pFanOnLedCh(void)          { return ParaMgr_pFanOnLedCh_W; }
uint8_t  Get_pFanLedTempHys(void)       { return ParaMgr_pFanLedTempHys_B; }
uint16_t Get_pFanSupInrushTime(void)    { return ParaMgr_pFanSupInrushTime_W; }
uint16_t Get_pFanNomCurrent(void)       { return ParaMgr_pFanNomCurrent_W; }
uint8_t  Get_pFanNomCurTol(void)        { return ParaMgr_pFanNomCurTol_B; }
uint16_t Get_pFanLockDebTime(void)      { return ParaMgr_pFanLockDebTime_W; }
uint8_t  Get_pFanLockProtOnTime0(void)  { return ParaMgr_pFanLockProtOnTime0_B; }
uint8_t  Get_pFanLockProtTimeTol0(void) { return ParaMgr_pFanLockProtTimeTol0_B; }
uint8_t  Get_pFanLockRetryOffTime(void) { return ParaMgr_pFanLockRetryOffTime_B; }
uint8_t  Get_pFanFaultSignal(void)      { return ParaMgr_pFanFaultSignal_B; }
uint8_t  Get_pFanCoolLedTempLo(void)    { return ParaMgr_pFanCoolLedTempLo_B; }
uint8_t  Get_pFanCoolLedTempHi(void)    { return ParaMgr_pFanCoolLedTempHi_B; }
uint8_t  Get_pFanCoolPowerLo(void)      { return ParaMgr_pFanCoolPowerLo_B; }
uint8_t  Get_pFanCoolPowerHi(void)      { return ParaMgr_pFanCoolPowerHi_B; }
uint8_t  Get_pFanNumber(void)           { return ParaMgr_pFanNumber_B; }
uint8_t  Get_pFanControlPin(void)       { return ParaMgr_pFanControlPinl_B; }
uint8_t  Get_pFanDiagInputType(void)    { return ParaMgr_pFanDiagInputType_B; }

/*Welcome 1*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pWelcomP1G1ModeLowBri_B;
		case Group2:
			return ParaMgr_pWelcomP1G2ModeLowBri_B;
		case Group3:
			return ParaMgr_pWelcomP1G3ModeLowBri_B;
		case Group4:
			return ParaMgr_pWelcomP1G4ModeLowBri_B;
		case Group5:
			return ParaMgr_pWelcomP1G5ModeLowBri_B;
		case Group6:
			return ParaMgr_pWelcomP1G6ModeLowBri_B;
		case Group7:
			return ParaMgr_pWelcomP1G7ModeLowBri_B;
		case Group8:
			return ParaMgr_pWelcomP1G8ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pWelcomP1G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_pWelcomP1G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_pWelcomP1G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_pWelcomP1G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_pWelcomP1G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_pWelcomP1G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_pWelcomP1G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_pWelcomP1G8OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Welcome 2*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP2ModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pWelcomP2G1ModeLowBri_B;
		case Group2:
			return ParaMgr_pWelcomP2G2ModeLowBri_B;
		case Group3:
			return ParaMgr_pWelcomP2G3ModeLowBri_B;
		case Group4:
			return ParaMgr_pWelcomP2G4ModeLowBri_B;
		case Group5:
			return ParaMgr_pWelcomP2G5ModeLowBri_B;
		case Group6:
			return ParaMgr_pWelcomP2G6ModeLowBri_B;
		case Group7:
			return ParaMgr_pWelcomP2G7ModeLowBri_B;
		case Group8:
			return ParaMgr_pWelcomP2G8ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pWelcomP2OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pWelcomP2G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_pWelcomP2G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_pWelcomP2G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_pWelcomP2G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_pWelcomP2G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_pWelcomP2G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_pWelcomP2G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_pWelcomP2G8OffTiConTiUpBri_W;
	}
    return NULL;
}

