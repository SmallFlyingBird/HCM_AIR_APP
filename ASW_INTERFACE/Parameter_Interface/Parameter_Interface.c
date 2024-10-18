/*
 * Parameter_Interface.c
 *
 *  Created on: 2024骞�1鏈�10鏃�
 *      Author: mihuiliang
 */

#include "HcmPlatform.h"
#include "ParaMgr.h"

#include "Parameter_Interface.h"
/****************************************************************************************************/
/****************************************************************************************************/
/*******************************Title Page related Parameter*****************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint8 Get_Variant(void)
{
    return ParaMgr_Variant_B;
}

uint8 *Get_LeftPartNumber_Address(void)
{
    return (uint8 *)(&ParaMgr_Left_Part_Number_QW);
}

uint8 *Get_RightPartNumber_Address(void)
{
    return (uint8 *)(&ParaMgr_Right_Part_Number_QW);
}


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
	case E_LowBeamFlat:
		rtval = ParaMgr_Low_Beam_Flat_W;
		break;
	case E_LowBeamKink:
		rtval = ParaMgr_Low_Beam_Kink_W;
		break;
	case E_HighBeamSail:
		rtval = ParaMgr_High_Beam_Sail_W;
		break;
	case E_HighBeamSpot:
		rtval = ParaMgr_High_Beam_Spot_W;
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
	case E_DynamicLightCircuit:
		rtval = ParaMgr_Dynamic_Light_Circuit_W;
		break;
	case E_DC_Motor:
		rtval = ParaMgr_DCMotor_Supply_W;
		break;
	case E_LMM_Supply:
		rtval = ParaMgr_LMM_Supply_W;
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
	case ChannelID5:
		LightFunctionsMask = ParaMgr_CH5_LF_MASK_W;
		break;
	case ChannelID6:
		LightFunctionsMask = ParaMgr_CH6_LF_MASK_W;
		break;
	case ChannelID7:
		LightFunctionsMask = ParaMgr_CH7_LF_MASK_W;
		break;
	case ChannelID8:
		LightFunctionsMask = ParaMgr_CH8_LF_MASK_W;
		break;
	case ChannelID9:
		LightFunctionsMask = ParaMgr_CH9_LF_MASK_W;
		break;
	case ChannelID10:
		LightFunctionsMask = ParaMgr_CH10_LF_MASK_W;
		break;
	case ChannelID11:
		LightFunctionsMask = ParaMgr_CH11_LF_MASK_W;
		break;
	case ChannelID12:
		LightFunctionsMask = ParaMgr_CH12_LF_MASK_W;
		break;
	}

	return LightFunctionsMask;
}

uint16_t Get_LightN_1(void)
{
	return ParaMgr_LightN_1_W;
}


uint16_t Get_MatrixRealisation(void)
{
	return ParaMgr_Matrix_Realisation_W;
}

const uint8_t *Get_PixelNoforchannel(void)
{
	return ParaMgr_PixelNoforchannel_B;
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

/****************************************************************************************************/
/****************************************************************************************************/
/********************************TPSSetting related Parameter****************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8_t Get_pLMMADCID(void)
{
	return ParaMgr_TPS_pLMMADCID_B;
}

uint8_t Get_pLMMPWMTick(void)
{
	return ParaMgr_TPS_pLMMPWMTick_B;
}

uint8_t Get_pLMMCMWEN(void)
{
	return ParaMgr_TPS_pLMMCMWEN_B;
}

uint8_t Get_pLMMCMWTAP(void)
{
	return ParaMgr_TPS_pLMMCMWTAP_B;
}

const uint16_t *Get_LB_HB_PhsSft(uint8_t id)
{

	if (id == 0)
	{
		return ParaMgr_TPS1_PhsSft_W;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS2_PhsSft_W;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS3_PhsSft_W;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS4_PhsSft_W;
	}
	else if (id == 4)
	{
		return ParaMgr_TPS5_PhsSft_W;
	}
	else if (id == 5)
	{
		return ParaMgr_TPS6_PhsSft_W;
	}
	else if (id == 6)
	{
		return ParaMgr_TPS7_PhsSft_W;
	}
	return NULL;
}
const uint16_t *Get_TI_PhsSft(uint8_t id)
{

	if (id == 0)
	{
		return ParaMgr_TPS8_PhsSft_W;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS9_PhsSft_W;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS10_PhsSft_W;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS11_PhsSft_W;
	}
	return NULL;
}

const uint16_t *Get_DRL_POS_PhsSft(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS12_PhsSft_W;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS13_PhsSft_W;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS14_PhsSft_W;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS15_PhsSft_W;
	}
	return NULL;
}

const uint16_t *Get_Grille_PhsSft(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS16_PhsSft_W;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS17_PhsSft_W;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS18_PhsSft_W;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS19_PhsSft_W;
	}
	return NULL;
}

const uint16_t *Get_Logo_PhsSft(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS20_PhsSft_W;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS21_PhsSft_W;
	}
	return NULL;
}

const uint16_t *Get_Assistant_PhsSft(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS22_PhsSft_W;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS23_PhsSft_W;
	}
	return NULL;
}

const uint16_t *Get_FrontCross_PhsSft(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS24_PhsSft_W;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS25_PhsSft_W;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS26_PhsSft_W;
	}
	return NULL;
}

const uint8_t *Get_LB_HB_MatrixInfo(uint8_t id)
{

	if (id == 0)
	{
		return ParaMgr_TPS1_B;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS2_B;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS3_B;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS4_B;
	}
	else if (id == 4)
	{
		return ParaMgr_TPS5_B;
	}
	else if (id == 5)
	{
		return ParaMgr_TPS6_B;
	}
	else if (id == 6)
	{
		return ParaMgr_TPS7_B;
	}
	return NULL;
}
const uint8_t *Get_TI_MatrixInfo(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS8_B;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS9_B;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS10_B;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS11_B;
	}

	return NULL;
}
const uint8_t *Get_DRL_POS_MatrixInfo(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS12_B;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS13_B;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS14_B;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS15_B;
	}

	return NULL;
}

const uint8_t *Get_Grille_MatrixInfo(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS16_B;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS17_B;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS18_B;
	}
	else if (id == 3)
	{
		return ParaMgr_TPS19_B;
	}

	return NULL;
}

const uint8_t *Get_Logo_MatrixInfo(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS20_B;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS21_B;
	}
	return NULL;
}

const uint8_t *Get_Assistant_MatrixInfo(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS22_B;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS23_B;
	}
	return NULL;
}

const uint8_t *Get_FrontCross_MatrixInfo(uint8_t id)
{
	if (id == 0)
	{
		return ParaMgr_TPS24_B;
	}
	else if (id == 1)
	{
		return ParaMgr_TPS25_B;
	}
	else if (id == 2)
	{
		return ParaMgr_TPS26_B;
	}
	return NULL;
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
	case ChannelID5:
		rtval = ParaMgr_pCh5Ena_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pCh6Ena_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pCh7Ena_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pCh8Ena_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pCh9Ena_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pCh10Ena_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pCh11Ena_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pCh12Ena_B;
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
	case ChannelID5:
		rtval = ParaMgr_pCh5MinVolt_W;
		break;
	case ChannelID6:
		rtval = ParaMgr_pCh6MinVolt_W;
		break;
	case ChannelID7:
		rtval = ParaMgr_pCh7MinVolt_W;
		break;
	case ChannelID8:
		rtval = ParaMgr_pCh8MinVolt_W;
		break;
	case ChannelID9:
		rtval = ParaMgr_pCh9MinVolt_W;
		break;
	case ChannelID10:
		rtval = ParaMgr_pCh10MinVolt_W;
		break;
	case ChannelID11:
		rtval = ParaMgr_pCh11MinVolt_W;
		break;
	case ChannelID12:
		rtval = ParaMgr_pCh12MinVolt_W;
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
	case ChannelID5:
		rtval = ParaMgr_pCh5MaxVolt_W;
		break;
	case ChannelID6:
		rtval = ParaMgr_pCh6MaxVolt_W;
		break;
	case ChannelID7:
		rtval = ParaMgr_pCh7MaxVolt_W;
		break;
	case ChannelID8:
		rtval = ParaMgr_pCh8MaxVolt_W;
		break;
	case ChannelID9:
		rtval = ParaMgr_pCh9MaxVolt_W;
		break;
	case ChannelID10:
		rtval = ParaMgr_pCh10MaxVolt_W;
		break;
	case ChannelID11:
		rtval = ParaMgr_pCh11MaxVolt_W;
		break;
	case ChannelID12:
		rtval = ParaMgr_pCh12MaxVolt_W;
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
		rtval = ParaMgr_pLedNomCurrent_CH2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedNomCurrent_CH3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedNomCurrent_CH4_W;
		break;
	case ChannelID5:
		rtval = ParaMgr_pLedNomCurrent_CH5_W;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedNomCurrent_CH6_W;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedNomCurrent_CH7_W;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedNomCurrent_CH8_W;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedNomCurrent_CH9_W;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedNomCurrent_CH10_W;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedNomCurrent_CH11_W;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedNomCurrent_CH12_W;
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
		rtval = ParaMgr_pLedMinCurrent_CH2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedMinCurrent_CH3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedMinCurrent_CH4_W;
		break;
	case ChannelID5:
		rtval = ParaMgr_pLedMinCurrent_CH5_W;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedMinCurrent_CH6_W;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedMinCurrent_CH7_W;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedMinCurrent_CH8_W;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedMinCurrent_CH9_W;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedMinCurrent_CH10_W;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedMinCurrent_CH11_W;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedMinCurrent_CH12_W;
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
		rtval = ParaMgr_pLedMaxCurrent_CH2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedMaxCurrent_CH3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedMaxCurrent_CH4_W;
		break;
	case ChannelID5:
		rtval = ParaMgr_pLedMaxCurrent_CH5_W;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedMaxCurrent_CH6_W;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedMaxCurrent_CH7_W;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedMaxCurrent_CH8_W;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedMaxCurrent_CH9_W;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedMaxCurrent_CH10_W;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedMaxCurrent_CH11_W;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedMaxCurrent_CH12_W;
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
		rtval = ParaMgr_pLedPmaxPower_CH2_W;
		break;
	case ChannelID3:
		rtval = ParaMgr_pLedPmaxPower_CH3_W;
		break;
	case ChannelID4:
		rtval = ParaMgr_pLedPmaxPower_CH4_W;
		break;
	case ChannelID5:
		rtval = ParaMgr_pLedPmaxPower_CH5_W;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedPmaxPower_CH6_W;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedPmaxPower_CH7_W;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedPmaxPower_CH8_W;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedPmaxPower_CH9_W;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedPmaxPower_CH10_W;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedPmaxPower_CH11_W;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedPmaxPower_CH12_W;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerTemp1_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerTemp1_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerTemp1_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerTemp1_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerTemp1_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerTemp1_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerTemp1_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerTemp1_Ch12_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerTemp2_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerTemp2_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerTemp2_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerTemp2_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerTemp2_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerTemp2_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerTemp2_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerTemp2_Ch12_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerTemp3_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerTemp3_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerTemp3_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerTemp3_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerTemp3_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerTemp3_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerTemp3_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerTemp3_Ch12_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerTemp4_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerTemp4_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerTemp4_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerTemp4_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerTemp4_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerTemp4_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerTemp4_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerTemp4_Ch12_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerTemp5_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerTemp5_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerTemp5_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerTemp5_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerTemp5_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerTemp5_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerTemp5_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerTemp5_Ch12_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerPwrA_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerPwrA_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerPwrA_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerPwrA_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerPwrA_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerPwrA_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerPwrA_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerPwrA_Ch12_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerPwrB_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerPwrB_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerPwrB_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerPwrB_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerPwrB_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerPwrB_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerPwrB_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerPwrB_Ch12_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedDerPwrC_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedDerPwrC_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedDerPwrC_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedDerPwrC_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedDerPwrC_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedDerPwrC_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedDerPwrC_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedDerPwrC_Ch12_B;
		break;
	default:
		rtval = 0;
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
	else if (HsdID == 3)
	{
		return ParaMgr_pHSD3OLEnable_B;
	}
	else 
	{
		return 1;
	}
	
	return 1;
}

uint8_t Get_pHSDOLEnable(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS1:
			return ParaMgr_pHSD1OLEnable_B;
		case E_HSChannel_HS2:
			return ParaMgr_pHSD2OLEnable_B;
		case E_HSChannel_HS3:
			return ParaMgr_pHSD3OLEnable_B;
	}
}

uint8_t Get_pHSDIOutOC(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS1:
			return ParaMgr_pHSD1IOutOC_B;
		case E_HSChannel_HS2:
			return ParaMgr_pHSD2IOutOC_B;
		case E_HSChannel_HS3:
			return ParaMgr_pHSD3IOutOC_B;
	}
}

uint16_t Get_pIOutSCGHSD(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS1:
			return ParaMgr_pIOutSCGHSD1_W;
		case E_HSChannel_HS2:
			return ParaMgr_pIOutSCGHSD2_W;
		case E_HSChannel_HS3:
			return ParaMgr_pIOutSCGHSD3_W;
	}
}

uint8_t Get_pHSDMaxVolt(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS1:
			return ParaMgr_pHSD1MaxVolt_B;
		case E_HSChannel_HS2:
			return ParaMgr_pHSD2MaxVolt_B;
		case E_HSChannel_HS3:
			return ParaMgr_pHSD3MaxVolt_B;
	}
}

uint8_t Get_pHSDMinVolt(E_HSChannel HSDChannel)
{
	switch( HSDChannel )
	{
		case E_HSChannel_HS1:
			return ParaMgr_pHSD1MinVolt_B;
		case E_HSChannel_HS2:
			return ParaMgr_pHSD2MinVolt_B;
		case E_HSChannel_HS3:
			return ParaMgr_pHSD3MinVolt_B;
	}
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

/****************************************************************************************************/
/****************************************************************************************************/
/***********************************NTC related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint8_t Get_pLMMAddNTC_Mx1(void)
{
	return ParaMgr_pLMMAddNTC_Mx1_B;
}
uint8_t Get_pLMMAddNTC_Mx2(void)
{
	return ParaMgr_pLMMAddNTC_Mx2_B;
}
uint8_t Get_pLMMAdcPort_Mx1(void)
{
	return ParaMgr_pLMMAdcPort_Mx1_B;
}
uint8_t Get_pLMMAdcPort_Mx2(void)
{
	return ParaMgr_pLMMAdcPort_Mx2_B;
}
/*
 * return
 * 0 means invalied
 * 1 means -49
 * 2 means -48
 * 200 means 150
 *
 */
uint8_t GetNtcTempByRegisterVal(uint32 register_val, uint8_t ntctype)
{
	const uint32 *ntctmpdata;
	uint8_t i = 0;

	if (ntctype == 1)
		ntctmpdata = ParaMgr_NTCType1_DW;
	else if (ntctype == 2)
		ntctmpdata = ParaMgr_NTCType2_DW;
	else if (ntctype == 3)
		ntctmpdata = ParaMgr_NTCType3_DW;
	else if (ntctype == 4)
		ntctmpdata = ParaMgr_NTCType4_DW;
	else if (ntctype == 5)
		ntctmpdata = ParaMgr_NTCType5_DW;
	else
		return 0;

	for (i = 0; i < 198; i++)
	{
		if (register_val <= ntctmpdata[i] && register_val >= ntctmpdata[i + 1])
		{
			/*find temp*/
			return (i + 1);
		}
	}

	return 0;
}

uint8_t Get_pNtcSCAdc(uint8_t ntcindex)
{
	if (ntcindex == 1)
		return ParaMgr_pNtcSCAdc_Mx1_B;
	else if (ntcindex == 2)
		return ParaMgr_pNtcSCAdc_Mx2_B;
}

uint8_t Get_pNtcOCAdc(uint8_t ntcindex)
{
	if (ntcindex == 1)
		return ParaMgr_pNtcOCAdc_Mx1_B;
	else if (ntcindex == 2)
		return ParaMgr_pNtcOCAdc_Mx2_B;
}
/*
 *  MtxNtcIndex: 1 Matrix NTC type1; 2 Matrix NTC type2;
 *  return value :  Min 0   -> -50°
 *                  Max 200 -> 150°
 * 					0xFF means not finded
 */
uint8_t GetNtcTempByMatrixADCVal(uint8_t adcval, uint8 MtxNtcIndex)
{
	const uint8 *tmpaddr = NULL;
	uint8 i = 0;
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

	if (matrixntctype == 6)
		tmpaddr = ParaMgr_MatrixNTCtype1_B;
	else
		tmpaddr = ParaMgr_MatrixNTCtype2_B;

	for (i = 0; i < 256; i++)
	{
		if (adcval == ParaMgr_pADCVal1_B[i])
		{
			return tmpaddr[i];
		}
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
	case 7:
		rtval = ParaMgr_pNtcFaultTemp_Mx1_B;
		break;
	case 8:
		rtval = ParaMgr_pNtcFaultTemp_Mx2_B;
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
	case 6: /*Matrix Ntc1*/
		rtval = ParaMgr_pNtcType_Mx1_B;
		break;
	case 7: /*Matrix Ntc2*/
		rtval = ParaMgr_pNtcType_Mx2_B;
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
	case ChannelID5:
		rtval = ParaMgr_pLedChToNtc_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pLedChToNtc_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pLedChToNtc_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pLedChToNtc_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pLedChToNtc_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pLedChToNtc_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pLedChToNtc_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pLedChToNtc_Ch12_B;
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
	else
	{
		if (index == 1)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_1_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_1_W;
			}
		}
		else if (index == 2)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_2_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_2_W;
			}
		}
		else if (index == 3)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_3_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_3_W;
			}
		}
		else if (index == 4)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_4_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_4_W;
			}
		}
		else if (index == 5)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_5_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_5_W;
			}
		}
		else if (index == 6)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_6_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_6_W;
			}
		}
		else if (index == 7)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_7_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_7_W;
			}
		}
		else if (index == 8)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_8_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_8_W;
			}
		}
		else if (index == 9)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_9_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_9_W;
			}
		}
		else if (index == 10)
		{
			if (pBinSrcCh == 1)
			{
				rtval = ParaMgr_pCodeLMMRcodCur1_10_W;
			}
			else if (pBinSrcCh == 2)
			{
				rtval = ParaMgr_pCodeLMMRcodCur2_10_W;
			}
		}
	}

	return rtval;
}

/*
 *  MtxRcodIndex: 1 MtxRcodIndex1; 2 MtxRcodIndex2;
 *  return 0Xffff means did not find related current through Register
 */
uint16_t GetRcodCurrentByMatrixADCVal(uint16_t adcval, uint8 MtxRcodIndex)
{
	if (MtxRcodIndex != 1 && MtxRcodIndex != 2)
		return 0xFFFF;

	if (adcval < ParaMgr_pcodeLMMAdcFieldL_1_W)
		return 0xFFFF;
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_1_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_1_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_1_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_1_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_2_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_2_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_2_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_2_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_3_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_3_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_3_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_3_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_4_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_4_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_4_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_4_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_5_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_5_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_5_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_5_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_6_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_6_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_6_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_6_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_7_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_7_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_7_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_7_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_8_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_8_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_8_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_8_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_9_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_9_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_9_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_9_W;
	}
	else if (adcval >= ParaMgr_pcodeLMMAdcFieldL_10_W && adcval <= ParaMgr_pcodeLMMAdcFieldH_10_W)
	{
		if (MtxRcodIndex == 1)
			return ParaMgr_pCodeLMMRcodCur1_10_W;
		else
			return ParaMgr_pCodeLMMRcodCur2_10_W;
	}
	return 0xFFFF;
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
	case ChannelID5:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pDefaultRcodIndexCh_Ch12_B;
		break;
	default:
		rtval = 0xFF;
		break;
	}

	return rtval;
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
uint8_t Get_pLMMAddRcod1(void)
{
	return ParaMgr_pLMMAddRcod1_B;
}

uint8_t Get_pLMMAdcPortRcod1(void)
{
	return ParaMgr_pLMMAdcPortRcod1_B;
}
uint8_t Get_pLMMAddRcod2(void)
{
	return ParaMgr_pLMMAddRcod2_B;
}
uint8_t Get_pLMMAdcPortRcod2(void)
{
	return ParaMgr_pLMMAdcPortRcod2_B;
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
	case ChannelID5:
		rtval = ParaMgr_pBinSrcCh_Ch5_B;
		break;
	case ChannelID6:
		rtval = ParaMgr_pBinSrcCh_Ch6_B;
		break;
	case ChannelID7:
		rtval = ParaMgr_pBinSrcCh_Ch7_B;
		break;
	case ChannelID8:
		rtval = ParaMgr_pBinSrcCh_Ch8_B;
		break;
	case ChannelID9:
		rtval = ParaMgr_pBinSrcCh_Ch9_B;
		break;
	case ChannelID10:
		rtval = ParaMgr_pBinSrcCh_Ch10_B;
		break;
	case ChannelID11:
		rtval = ParaMgr_pBinSrcCh_Ch11_B;
		break;
	case ChannelID12:
		rtval = ParaMgr_pBinSrcCh_Ch12_B;
		break;
	default:
		rtval = 0xFF;
		break;
	}

	return rtval;
}

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************AFS related Parameter*********************************************/
/****************************************************************************************************/
/****************************************************************************************************/
const uint8_t * Get_pLowBeamPWMPixel_P(void)      { return ParaMgr_pLowBeamPWMPixel_B; }
const uint8_t * Get_pTownLightPWMPixel_P(void)    { return ParaMgr_pTownLightPWMPixel_B; }
const uint8_t * Get_pMotorWayPWMPixel_P(void)     { return ParaMgr_pMotorWayPWMPixel_B; }
const uint8_t * Get_pCountryLightPWMPixel_P(void) { return ParaMgr_pCountryLightPWMPixel_B; }
const uint8_t * Get_pWeatherLightPWMPixel_P(void) { return ParaMgr_pWeatherLightPWMPixel_B; }
const uint8_t * Get_pLHTPWMPixel_P(void)          { return ParaMgr_pLHTPWMPixel_B; }

const uint8_t * Get_pLowBeamPWMPixel_R_P(void)      { return ParaMgr_pLowBeamPWMPixel_R_B; }
const uint8_t * Get_pTownLightPWMPixel_R_P(void)    { return ParaMgr_pTownLightPWMPixel_R_B; }
const uint8_t * Get_pMotorWayPWMPixel_R_P(void)     { return ParaMgr_pMotorWayPWMPixel_R_B; }
const uint8_t * Get_pCountryLightPWMPixel_R_P(void) { return ParaMgr_pCountryLightPWMPixel_R_B; }
const uint8_t * Get_pWeatherLightPWMPixel_R_P(void) { return ParaMgr_pWeatherLightPWMPixel_R_B; }
const uint8_t * Get_pLHTPWMPixel_R_P(void)          { return ParaMgr_pLHTPWMPixel_R_B; }

uint8_t Get_pLowBeamPWMPixel(uint8_t pixelNum)
{
	return ParaMgr_pLowBeamPWMPixel_B[pixelNum];
}

uint8_t Get_pHighBeamPWMPixel(uint8_t pixelNum)
{
	return ParaMgr_pHighBeamPWMPixel_B[pixelNum];
}

uint8_t Get_pTownLightPWMPixel(uint8_t pixelNum)
{
	return ParaMgr_pTownLightPWMPixel_B[pixelNum];
}

uint8_t Get_pMotorWayPWMPixel(uint8_t pixelNum)
{
	return ParaMgr_pMotorWayPWMPixel_B[pixelNum];
}

uint8_t Get_pCountryLightPWMPixel(uint8_t pixelNum)
{
	return ParaMgr_pCountryLightPWMPixel_B[pixelNum];
}

uint8_t Get_pWeatherLightPWMPixel(uint8_t pixelNum)
{
	return ParaMgr_pWeatherLightPWMPixel_B[pixelNum];
}

uint8_t Get_pLHTPWMPixel(uint8_t pixelNum)
{
	return ParaMgr_pLHTPWMPixel_B[pixelNum];
}

uint8_t Get_pLowBeamPWMPixel_R(uint8_t pixelNum)
{
	return ParaMgr_pLowBeamPWMPixel_R_B[pixelNum];
}

uint8_t Get_pHighBeamPWMPixel_R(uint8_t pixelNum)
{
	return ParaMgr_pHighBeamPWMPixel_R_B[pixelNum];
}

uint8_t Get_pTownLightPWMPixel_R(uint8_t pixelNum)
{
	return ParaMgr_pTownLightPWMPixel_R_B[pixelNum];
}

uint8_t Get_pMotorWayPWMPixel_R(uint8_t pixelNum)
{
	return ParaMgr_pMotorWayPWMPixel_R_B[pixelNum];
}

uint8_t Get_pCountryLightPWMPixel_R(uint8_t pixelNum)
{
	return ParaMgr_pCountryLightPWMPixel_R_B[pixelNum];
}

uint8_t Get_pWeatherLightPWMPixel_R(uint8_t pixelNum)
{
	return ParaMgr_pWeatherLightPWMPixel_R_B[pixelNum];
}

uint8_t Get_pLHTPWMPixel_R(uint8_t pixelNum)
{
	return ParaMgr_pLHTPWMPixel_R_B[pixelNum];
}

uint16  Get_ParaMgr_pSpdThd1OfAfs(void)
{
	return ParaMgr_pSpdThd1OfAfs_W;
}

uint16  Get_ParaMgr_pSpdThd2OfAfs(void)
{
	return ParaMgr_pSpdThd2OfAfs_W;
}

uint16  Get_ParaMgr_pSpdThd3OfAfs(void)
{
	return ParaMgr_pSpdThd3OfAfs_W;
}

uint8  Get_ParaMgr_pSpdzoneOfAfsHys(void)
{
	return ParaMgr_pSpdzoneOfAfsHys_B;
}

uint8  Get_ParaMgr_pTownLightEn(void)
{
	return ParaMgr_pTownLightEn_B;
}

uint8  Get_ParaMgr_pCountryLightEn(void)
{
	return ParaMgr_pCountryLightEn_B;
}

uint8  Get_ParaMgr_pAWLightEn(void)
{
	return ParaMgr_pAWLightEn_B;
}

uint8  Get_ParaMgr_pMotorwayLightEn(void)
{
	return ParaMgr_pMotorwayLightEn_B;
}

uint8  Get_ParaMgr_pTouristMod(void)
{
	return ParaMgr_pTouristMod_B;
}

uint8  Get_ParaMgr_pTownLightLoBeamFlatInt(void)
{
	return ParaMgr_pTownLightLoBeamFlatInt_B;
}

uint8  Get_ParaMgr_pTownLightLoBeamKinkInt(void)
{
	return ParaMgr_pTownLightLoBeamKinkInt_B;
}

uint8  Get_ParaMgr_pAWLLoBeamFlatInt(void)
{
	return ParaMgr_pAWLLoBeamFlatInt_B;
}

uint8  Get_ParaMgr_pAWLLoBeamKinkInt(void)
{
	return ParaMgr_pAWLLoBeamKinkInt_B;
}

uint8  Get_ParaMgr_pMotorwayLoBeamFlatInt(void)
{
	return ParaMgr_pMotorwayLoBeamFlatInt_B;
}

uint8  Get_ParaMgr_pMotorwayLoBeamKinkInt(void)
{
	return ParaMgr_pMotorwayLoBeamKinkInt_B;
}

uint8  Get_ParaMgr_pCountryLoBeamFlatInt(void)
{
	return ParaMgr_pCountryLoBeamFlatInt_B;
}

uint8  Get_ParaMgr_pCountryLoBeamKinkInt(void)
{
	return ParaMgr_pCountryLoBeamKinkInt_B;
}

uint8  Get_ParaMgr_pTownCornerLightPWM(void)
{
	return ParaMgr_pTownCornerLightPWM_B;
}

uint16  Get_ParaMgr_pMotorwayChngOvrTime(void)
{
	return ParaMgr_pMotorwayChngOvrTime_W;
}

uint16  Get_ParaMgr_pCountryChngOvrTime(void)
{
	return ParaMgr_pCountryChngOvrTime_W;
}

uint16  Get_ParaMgr_pTownChngOvrTime(void)
{
	return ParaMgr_pTownChngOvrTime_W;
}

uint16  Get_ParaMgr_pAWLChngOvrTime(void)
{
	return ParaMgr_pAWLChngOvrTime_W;
}

uint16  Get_ParaMgr_pTourMdChngOvrTime(void)
{
	return ParaMgr_pTourMdChngOvrTime_W;
}

uint16  Get_ParaMgr_pLoBeamChngOvrTime(void)
{
	return ParaMgr_pLoBeamChngOvrTime_W;
}

uint8  Get_ParaMgr_pTownLightCornerLight(void)
{
	return ParaMgr_pTownLightCornerLight_B;
}

uint8  Get_ParaMgr_pAWLLightFogLight(void)
{
	return ParaMgr_pAWLLightFogLight_B;
}

uint16  Get_ParaMgr_pAWLOffsetLeftLvl_deg(void)
{
	return ParaMgr_pAWLOffsetLeftLvl_deg_W;
}

uint16  Get_ParaMgr_pAWLOffsetRightLvl_deg(void)
{
	return ParaMgr_pAWLOffsetRightLvl_deg_W;
}

uint16  Get_ParaMgr_pCountryOffsetLeftLvl_deg(void)
{
	return ParaMgr_pCountryOffsetLeftLvl_deg_W;
}

uint16  Get_ParaMgr_pCountryOffsetRightLvl_deg(void)
{
	return ParaMgr_pCountryOffsetRightLvl_deg_W;
}

uint16  Get_ParaMgr_pMotorwayOffsetLeftLvl_deg(void)
{
	return ParaMgr_pMotorwayOffsetLeftLvl_deg_W;
}

uint16  Get_ParaMgr_pMotorwayOffsetRightLvl_deg(void)
{
	return ParaMgr_pMotorwayOffsetRightLvl_deg_W;
}

uint16  Get_ParaMgr_pTownOffsetLeftLvl_deg(void)
{
	return ParaMgr_pTownOffsetLeftLvl_deg_W;
}

uint16  Get_ParaMgr_pTownOffsetRightLvl_deg(void)
{
	return ParaMgr_pTownOffsetRightLvl_deg_W;
}

uint16  Get_ParaMgr_pTownOffsetLeftDBL_deg(void)
{
	return ParaMgr_pTownOffsetLeftDBL_deg_W;
}

uint16  Get_ParaMgr_pTownOffsetRightDBL_deg(void)
{
	return ParaMgr_pTownOffsetRightDBL_deg_W;
}

uint16  Get_ParaMgr_pCountryOffsetLeftDBL_deg(void)
{
	return ParaMgr_pCountryOffsetLeftDBL_deg_W;
}

uint16  Get_ParaMgr_pCountryOffsetRightDBL_deg(void)
{
	return ParaMgr_pCountryOffsetRightDBL_deg_W;
}

uint16  Get_ParaMgr_pMotorwayOffsetLeftDBL_deg(void)
{
	return ParaMgr_pMotorwayOffsetLeftDBL_deg_W;
}

uint16  Get_ParaMgr_pMotorwayOffsetRightDBL_deg(void)
{
	return ParaMgr_pMotorwayOffsetRightDBL_deg_W;
}

uint16  Get_ParaMgr_pAWLOffsetLeftDBL_deg(void)
{
	return ParaMgr_pAWLOffsetLeftDBL_deg_W;
}

uint16  Get_ParaMgr_pAWLOffsetRightDBL_deg(void)
{
	return ParaMgr_pAWLOffsetRightDBL_deg_W;
}

const
uint8  Get_ParaMgr_pAFSLightDRL(void)
{
	return ParaMgr_pAFSLightDRL_deg_B;
}

const
uint16 Get_ParaMgr_pAFSDRLPWM(void)
{
	return ParaMgr_pAFSDRLPWM_deg_W;
}

const
uint8 *Get_pLowBeamPWMPixel_head(void)
{
	return ParaMgr_pLowBeamPWMPixel_B;
}

const
uint8 *Get_pHighBeamPWMPixel_B_head(void)
{
	return ParaMgr_pHighBeamPWMPixel_B;
}

const
uint8 *Get_pTownLightPWMPixel_head(void)
{
	return ParaMgr_pTownLightPWMPixel_B;
}

const
uint8 *Get_pMotorWayPWMPixel_head(void)
{
	return ParaMgr_pMotorWayPWMPixel_B;
}

const
uint8 *Get_pCountryLightPWMPixel_head(void)
{
	return ParaMgr_pCountryLightPWMPixel_B;
}

const
uint8 *Get_pWeatherLightPWMPixel_head(void)
{
	return ParaMgr_pWeatherLightPWMPixel_B;
}

const
uint8 *Get_pLHTPWMPixel_head(void)
{
	return ParaMgr_pLHTPWMPixel_B;
}

const
uint8 *Get_pLowBeamPWMPixel_R_head(void)
{
	return ParaMgr_pLowBeamPWMPixel_R_B;
}

const
uint8 *Get_pHighBeamPWMPixel_R_B_head(void)
{
	return ParaMgr_pHighBeamPWMPixel_R_B;
}

const
uint8 *Get_pTownLightPWMPixel_R_head(void)
{
	return ParaMgr_pTownLightPWMPixel_R_B;
}

const
uint8 *Get_pMotorWayPWMPixel_R_head(void)
{
	return ParaMgr_pMotorWayPWMPixel_R_B;
}

const
uint8 *Get_pCountryLightPWMPixel_R_head(void)
{
	return ParaMgr_pCountryLightPWMPixel_R_B;
}

const
uint8 *Get_pWeatherLightPWMPixel_R_head(void)
{
	return ParaMgr_pWeatherLightPWMPixel_R_B;
}

const
uint8 *Get_pLHTPWMPixel_R_head(void)
{
	return ParaMgr_pLHTPWMPixel_R_B;
}


/****************************************************************************************************/
/****************************************************************************************************/
/**********************************DBLLvlAHB related Parameter***************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint16_t g_LvlAccArray[MAX_LVL_ACC];
uint16_t g_LvlBrakeArray[MAX_LVL_BRAKE];

uint16_t g_SvlAccArray[MAX_SVL_ACC];
uint16_t g_SvlBrakeArray[MAX_SVL_BRAKE];
/*******************************************************************Light Function: Type**************************************************************/
/*
 * vehicle LVL type, 0=LVL not available, 1=manual LVL, 2=automatic LVL, 3=reserved
 */
uint8_t Get_pVehLvLType(void)
{
	return ParaMgr_pVehLvLType_B;
}
/*
 * Type of Realisation of DBL function:
 *  0: DBL not avaiable, 1: DBL in Stepper motor w/o Hall sensor , 2: DBL in Stepper motor with Hall sensor  , 3: DBL in matrix
 *  pVehDBLType==4 :DBL with cornering light (static bending light)
 *pVehDBLType==5 :DBL in swiveling motor (without hall sensor) with cornering lamp
 *pVehDBLType==6 :DBL in swiveling motor with hallsensor with cornering lamp
 *pVehDBLType==7 :DBL in matrix with cornering lamp.
 *
 */
uint8_t Get_pVehDBLType(void)
{
	return ParaMgr_pVehDBLType_B;
}
/*
 *Swiveling: sensor availability and type [1 = not used; 2 = hall@5V; 4 = hall@12V; 8 = inductive@5V; 16 = inductive@12V; other = Invalid]
 */
uint8_t Get_pSensorType(void)
{
	return ParaMgr_pSensorType_B;
}
/*Automatic driving beam configuration paramter. One of: 0=No Glare Free HB; 1=AHB; 2=AHB2; 3=ADB*/
uint8_t Get_pAHBCType(void)
{
	return ParaMgr_pAHBCTyp_B;
}
/*******************************************************************Light Function: Leveling*************************************************************/
uint8_t Get_pLVLPlsbltyChckEna(void)
{
	return ParaMgr_pLVLPlsbltyChckEna_B;
}
uint8_t Get_pLvlPlsbltyErrChckTime(void)
{
	return ParaMgr_pLvlPlsbltyErrChckTime_B;
}
uint8_t Get_pLvlPlsbltyOkChckTime(void)
{
	return ParaMgr_pLvlPlsbltyOkChckTime_B;
}

/* range:(-10) - (+10)  HS*/
sint8_t Get_pLVLOffset(void)
{
	return ((sint8_t)ParaMgr_pLVLOffset_B - 10);
}
/* range:(-10.00) - (+10.00)  HS*/
double Get_pLVLSafetyposdeg(void)
{
	return ((double)ParaMgr_pLVLSafetyposdeg_W * 0.01 - 10);
}
/* range:(-1000) - (+1000)  HS*/
int16_t Get_pLVLSafetyposHS(void)
{
	return ((int16_t)ParaMgr_pLVLSafetyposHS_W - 1000);
}

/* range:0.0 - 25.5 v*/
double Get_pLvlHoldMinVolt(void)
{
	return (((double)ParaMgr_pLvlHoldMinVolt_B) * 0.1);
}

/* range:0.0 - 25.5 v*/
double Get_pLvlRunMinVolt(void)
{
	return (((double)ParaMgr_pLvlRunMinVolt_B) * 0.1);
}

/* range:0.0 - 25.5 v*/
double Get_pLvlRunMaxVolt(void)
{
	return (((double)ParaMgr_pLvlRunMaxVolt_B) * 0.1);
}

/* range:0.0 - 25.5 v*/
double Get_pLvlHoldMaxVolt(void)
{
	return (((double)ParaMgr_pLvlHoldMaxVolt_B) * 0.1);
}

uint8_t Get_LeLamp_pLvlPolSeq(void)
{
	return ParaMgr_LeLamp_pLvlPolSeq0_B;
}

uint8_t Get_RiLamp_pLvlPolSeq(void)
{
	return ParaMgr_RiLamp_pLvlPolSeq1_B;
}
/* range:-1000 - 0 HS*/
sint16_t Get_LeLamp_pLvlLimBotPos(void)
{
	return (((sint16_t)ParaMgr_LeLamp_pLvlLimBotPos0_W) - 1000);
}
/* range:-1000 - 0 HS*/
sint16_t Get_RiLamp_pLvlLimBotPos(void)
{
	return (((sint16_t)ParaMgr_RiLamp_pLvlLimBotPos1_W) - 1000);
}
/* range:-1000 - 0 HS*/
sint16_t Get_LeLamp_pLvlBotPos(void)
{
	return (((sint16_t)ParaMgr_LeLamp_pLvlBotPos0_W) - 1000);
}
/* range:-1000 - 0 HS*/
sint16_t Get_RiLamp_pLvlBotPos(void)
{
	return (((sint16_t)ParaMgr_RiLamp_pLvlBotPos1_W) - 1000);
}
/* range:0 - 1000 HS*/
sint16_t Get_LeLamp_pLvlTopPos(void)
{
	return ((sint16_t)ParaMgr_LeLamp_pLvlTopPos0_W);
}
/* range:0 - 1000 HS*/
sint16_t Get_RiLamp_pLvlTopPos(void)
{
	return ((sint16_t)ParaMgr_RiLamp_pLvlTopPos1_W);
}
/* range:0 - 1000 HS*/
sint16_t Get_LeLamp_pLvlLimTopPos(void)
{
	return ((sint16_t)ParaMgr_LeLamp_pLvlLimTopPos0_W);
}
/* range:0 - 1000 HS*/
sint16_t Get_RiLamp_pLvlLimTopPos(void)
{
	return ((sint16_t)ParaMgr_RiLamp_pLvlLimTopPos1_W);
}

/* range:-1000 - 1000 HS*/
sint16_t Get_LeLamp_pLvlDfltPosLe(void)
{
	return (((sint16_t)ParaMgr_LeLamp_pLvlDfltPosLe_W) - 1000);
}
/* range:-1000 - 1000 HS*/
sint16_t Get_RiLamp_pLvlDfltPosRi(void)
{
	return (((sint16_t)ParaMgr_RiLamp_pLvlDfltPosRi_W) - 1000);
}
/* range:0 - 30 HS*/
uint8_t Get_pLvlCorStepsNum(void)
{
	return ParaMgr_pLvlCorStepsNum_B;
}
/* range:0 - 65535 HS/rad*/
uint16_t Get_pLvlHsPerRad(void)
{
	return ParaMgr_pLvlHsPerRad_W;
}
/* range:-10.00 - 10.00 deg*/
double Get_LeLamp_pLvlDfltPosLe_deg(void)
{
	return ((double)ParaMgr_LeLamp_pLvlDfltPosLe_deg_W * 0.01 - 10);
}
/* range:-10.00 - 10.00 deg*/
double Get_RiLamp_pLvlDfltPosRi_deg(void)
{
	return ((double)ParaMgr_RiLamp_pLvlDfltPosRi_deg_W * 0.01 - 10);
}
/* range:-45.00 - 45.00 deg*/
double Get_LeLamp_pLvlBotPosdeg(void)
{
	return ((double)ParaMgr_LeLamp_pLvlBotPos_deg0_W * 0.01 - 45);
}
/* range:-45.00 - 45.00 deg*/
double Get_RiLamp_pLvlBotPosdeg(void)
{
	return ((double)ParaMgr_RiLamp_pLvlBotPos_deg1_W * 0.01 - 45);
}

/* range:-45.00 - 45.00 deg*/
double Get_LeLamp_pLvlTopPosdeg(void)
{
	return ((double)ParaMgr_LeLamp_pLvlTopPos_deg0_W * 0.01 - 45);
}
/* range:-45.00 - 45.00 deg*/
double Get_RiLamp_pLvlTopPosdeg(void)
{
	return ((double)ParaMgr_RiLamp_pLvlTopPos_deg1_W * 0.01 - 45);
}

uint8_t Get_pLvlVmaxLowTemp(void)
{
	return (ParaMgr_pLvlVmaxLowTemp_B + 1);
}
uint8_t Get_pLvlVmaxNorm(void)
{
	return (ParaMgr_pLvlVmaxNorm_B + 1);
}
uint8_t Get_pLvlVmaxRef(void)
{
	return (ParaMgr_pLvlVmaxRef_B + 1);
}
uint16_t Get_pLvlIrunLowTemp(void)
{
	return ParaMgr_pLvlIrunLowTemp_W;
}
uint16_t Get_pLvlIrunNorm(void)
{
	return ParaMgr_pLvlIrunNorm_W;
}
uint16_t Get_pLvlIrunRef(void)
{
	return ParaMgr_pLvlIrunRef_W;
}

uint16_t Get_pLvlIholdLowTemp(void)
{
	return ParaMgr_pLvlIholdLowTemp_W;
}

uint16_t Get_pLvlIholdNorm(void)
{
	return ParaMgr_pLvlIholdNorm_W;
}
/*return range: 0- 1275 s*/
uint16_t Get_pLvlLowTempHeatupTime(void)
{
	return ParaMgr_pLvlLowTempHeatupTime_W;
}
/*return range: -50- 200 °C*/
sint16_t Get_pLvlLowTempThreshold(void)
{
	return ((sint16_t)(ParaMgr_pLvlLowTempThreshold_B)-50);
}
uint16_t Get_pLvlPreTime(void)
{
	return ParaMgr_pLvlPreTime_W;
}

uint16_t Get_pLvlPostTime(void)
{
	return ParaMgr_pLvlPostTime_W;
}
uint16_t Get_pLvlUsageInterval(void)
{
	return ParaMgr_pLvlUsageInterval_W;
}
uint8_t Get_pLvlNormUsage(void)
{
	return ParaMgr_pLvlNormUsage_B;
}

uint8_t Get_pLvlOverUsage(void)
{
	return ParaMgr_pLvlOverUsage_B;
}

uint8_t Get_pLvlMinDistStart(void)
{
	return ParaMgr_pLvlMinDistStart_B;
}

uint8_t Get_pLvlMinDistTime(void)
{
	return ParaMgr_pLvlMinDistTime_B;
}
uint8_t Get_pLvlFilterTime(void)
{
	return ParaMgr_pLvlFilterTime_B;
}

uint8_t Get_pLvlStepMode(void)
{
	return ParaMgr_pLvlStepMode_B;
}

uint16_t *Get_pLvlAccArray(void)
{
	g_LvlAccArray[0] = ParaMgr_pLvlAcc0_W;
	g_LvlAccArray[1] = ParaMgr_pLvlAcc1_W;
	g_LvlAccArray[2] = ParaMgr_pLvlAcc2_W;
	g_LvlAccArray[3] = ParaMgr_pLvlAcc3_W;
	g_LvlAccArray[4] = ParaMgr_pLvlAcc4_W;
	g_LvlAccArray[5] = ParaMgr_pLvlAcc5_W;
	g_LvlAccArray[6] = ParaMgr_pLvlAcc6_W;
	g_LvlAccArray[7] = ParaMgr_pLvlAcc7_W;
	g_LvlAccArray[8] = ParaMgr_pLvlAcc8_W;
	g_LvlAccArray[9] = ParaMgr_pLvlAcc9_W;
	g_LvlAccArray[10] = ParaMgr_pLvlAcc10_W;
	g_LvlAccArray[11] = ParaMgr_pLvlAcc11_W;
	g_LvlAccArray[12] = ParaMgr_pLvlAcc12_W;
	g_LvlAccArray[13] = ParaMgr_pLvlAcc13_W;
	g_LvlAccArray[14] = ParaMgr_pLvlAcc14_W;
	g_LvlAccArray[15] = ParaMgr_pLvlAcc15_W;
	g_LvlAccArray[16] = ParaMgr_pLvlAcc16_W;
	g_LvlAccArray[17] = ParaMgr_pLvlAcc17_W;
	g_LvlAccArray[18] = ParaMgr_pLvlAcc18_W;
	g_LvlAccArray[19] = ParaMgr_pLvlAcc19_W;

	return g_LvlAccArray;
}

uint16_t *Get_pLvlBrakeArray(void)
{
	g_LvlBrakeArray[0] = ParaMgr_pLvlBrake0_W;
	g_LvlBrakeArray[1] = ParaMgr_pLvlBrake1_W;
	g_LvlBrakeArray[2] = ParaMgr_pLvlBrake2_W;
	g_LvlBrakeArray[3] = ParaMgr_pLvlBrake3_W;
	g_LvlBrakeArray[4] = ParaMgr_pLvlBrake4_W;
	g_LvlBrakeArray[5] = ParaMgr_pLvlBrake5_W;
	g_LvlBrakeArray[6] = ParaMgr_pLvlBrake6_W;
	g_LvlBrakeArray[7] = ParaMgr_pLvlBrake7_W;
	g_LvlBrakeArray[8] = ParaMgr_pLvlBrake8_W;
	g_LvlBrakeArray[9] = ParaMgr_pLvlBrake9_W;
	g_LvlBrakeArray[10] = ParaMgr_pLvlBrake10_W;
	g_LvlBrakeArray[11] = ParaMgr_pLvlBrake11_W;
	g_LvlBrakeArray[12] = ParaMgr_pLvlBrake12_W;
	g_LvlBrakeArray[13] = ParaMgr_pLvlBrake13_W;
	g_LvlBrakeArray[14] = ParaMgr_pLvlBrake14_W;
	g_LvlBrakeArray[15] = ParaMgr_pLvlBrake15_W;
	g_LvlBrakeArray[16] = ParaMgr_pLvlBrake16_W;
	g_LvlBrakeArray[17] = ParaMgr_pLvlBrake17_W;
	g_LvlBrakeArray[18] = ParaMgr_pLvlBrake18_W;
	g_LvlBrakeArray[19] = ParaMgr_pLvlBrake19_W;

	return g_LvlBrakeArray;
}

uint8_t Get_pLvlstalldetethreshold(void)
{
	return ParaMgr_pLvlstalldetethreshold_B;
}
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos1(void)
{
	return ((sint16_t)ParaMgr_pManLvlAgPos1_W - 1000);
}
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos2(void)
{
	return ((sint16_t)ParaMgr_pManLvlAgPos2_W - 1000);
}
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos3(void)
{
	return ((sint16_t)ParaMgr_pManLvlAgPos3_W - 1000);
}
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos4(void)
{
	return ((sint16_t)ParaMgr_pManLvlAgPos4_W - 1000);
}
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos5(void)
{
	return ((sint16_t)ParaMgr_pManLvlAgPos5_W - 1000);
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

/*******************************************************************Light Function: DBL*************************************************************/
/*
 * Attention: The return value is typeof uint16,the actual degree is  (ParaMgr_pSvlDfltPosdeg_W * 0.01 -50)
 */

uint8_t  Get_pDBCntrPxlBttmRow(void)     {return ParaMgr_pDBCntrPxlBttmRow_B;}
uint8_t  Get_pDBCntrPxlMddlRow(void)     {return ParaMgr_pDBCntrPxlMddlRow_B;}
uint8_t  Get_pDBCntrPxlTopRow(void)      {return ParaMgr_pDBCntrPxlTopRow_B;}
uint8_t  Get_pDBLeEdgePxlHLBttmRow(void) {return ParaMgr_pDBLeEdgePxlHLBttmRow_B;}
uint8_t  Get_pDBRiEdgePxlHLBttmRow(void) {return ParaMgr_pDBRiEdgePxlHLBttmRow_B;}
uint8_t  Get_pDBLeEdgePxlHLMddlRow(void) {return ParaMgr_pDBLeEdgePxlHLMddlRow_B;}
uint8_t  Get_pDBRiEdgePxlHLMddlRow(void) {return ParaMgr_pDBRiEdgePxlHLMddlRow_B;}
uint8_t  Get_pDBLeEdgePxlHLTopRow(void)  {return ParaMgr_pDBLeEdgePxlHLTopRow_B;}
uint8_t  Get_pDBRiEdgePxlHLTopRow(void)  {return ParaMgr_pDBRiEdgePxlHLTopRow_B;}
uint8_t  Get_pDBLeLimBttmRow(void)       {return ParaMgr_pDBLeLimBttmRow_B;}
uint8_t  Get_pDBRiLimBttmRow(void)       {return ParaMgr_pDBRiLimBttmRow_B;}
uint8_t  Get_pDBLeLimMddlRow(void)       {return ParaMgr_pDBLeLimMddlRow_B;}
uint8_t  Get_pDBRiLimMddlRow(void)       {return ParaMgr_pDBRiLimMddlRow_B;}
uint8_t  Get_pDBLeLimTopRow(void)        {return ParaMgr_pDBLeLimTopRow_B;}
uint8_t  Get_pDBRiLimTopRow(void)        {return ParaMgr_pDBRiLimTopRow_B;}
uint16_t Get_pDBTrnsntime(void)          {return ParaMgr_pDBTrnsntime_W;}
uint16_t Get_pDBPxlShiftDlyTime(void)    {return ParaMgr_pDBPxlShiftDlyTime_W;}

uint16_t Get_SvlDfltPosdeg(void)
{
	return ParaMgr_pSvlDfltPosdeg_W;
}

/*return range :-50.00 - 50.00 deg*/
double Get_LeLamp_SvlLePosdeg(void)
{
	return (double)(((double)ParaMgr_pSvlLePos0deg_W) * 0.01 - 50);
}
/*return range :-50.00 - 50.00 deg*/
double Get_RiLamp_SvlLePosdeg(void)
{
	return (double)(((double)ParaMgr_pSvlLePos1deg_W) * 0.01 - 50);
}
/*return range :-50.00 - 50.00 deg*/
double Get_LeLamp_SvlRiPosdeg(void)
{
	return (double)(((double)ParaMgr_pSvlRiPos0deg_W) * 0.01 - 50);
}
/*return range :-50.00 - 50.00 deg*/
double Get_RiLamp_SvlRiPosdeg(void)
{
	return (double)(((double)ParaMgr_pSvlRiPos1deg_W) * 0.01 - 50);
}
/*return range :0 - 25.5 v*/
double Get_pSvlHoldMinVolt(void)
{
	return ((double)ParaMgr_pSvlHoldMinVolt_B * 0.1);
}
/*return range :0 - 25.5 v*/
double Get_pSvlRunMinVolt(void)
{
	return ((double)ParaMgr_pSvlRunMinVolt_B * 0.1);
}
/*return range :0 - 25.5 v*/
double Get_pSvlRunMaxVolt(void)
{
	return ((double)ParaMgr_pSvlRunMaxVolt_B * 0.1);
}
/*return range :0 - 25.5 v*/
double Get_pSvlHoldMaxVolt(void)
{
	return ((double)ParaMgr_pSvlHoldMaxVolt_B * 0.1);
}
uint8_t Get_LeLamp_pSvlPolSeq(void)
{
	return ParaMgr_pSvlPolSeq0_B;
}
uint8_t Get_RiLamp_pSvlPolSeq(void)
{
	return ParaMgr_pSvlPolSeq1_B;
}
uint8_t Get_LeLamp_pSvlRefDirection(void)
{
	return ParaMgr_pSvlRefDirection0_B;
}
uint8_t Get_RiLamp_pSvlRefDirection(void)
{
	return ParaMgr_pSvlRefDirection1_B;
}
/*return range : -1500 - 0 HS*/
sint16_t Get_LeLamp_SvlLeftBlockPos(void)
{
	return ((sint16_t)ParaMgr_pSvlLimLePos0_W - 1500);
}
/*return range : -1500 - 0 HS*/
sint16_t Get_RiLamp_SvlLeftBlockPos(void)
{
	return ((sint16_t)ParaMgr_pSvlLimLePos1_W - 1500);
}
/*return range : -1500 - 0 HS*/
sint16_t Get_LeLamp_SvlLeftLogicPos(void)
{
	return ((sint16_t)ParaMgr_pSvlLePos0_W - 1500);
}
/*return range : -1500 - 0 HS*/
sint16_t Get_RiLamp_SvlLeftLogicPos(void)
{
	return ((sint16_t)ParaMgr_pSvlLePos1_W - 1500);
}
/*return range : 0 - 1500 HS*/
sint16_t Get_LeLamp_SvlRightLogicPos(void)
{
	return ((sint16_t)ParaMgr_pSvlRiPos0_W);
}
/*return range : 0 - 1500 HS*/
sint16_t Get_RiLamp_SvlRightLogicPos(void)
{
	return ((sint16_t)ParaMgr_pSvlRiPos1_W);
}
/*return range : 0 - 1500 HS*/
sint16_t Get_LeLamp_SvlRightBlockPos(void)
{
	return ((sint16_t)ParaMgr_pSvlLimRiPos0_W);
}
/*return range : 0 - 1500 HS*/
sint16_t Get_RiLamp_SvlRightBlockPos(void)
{
	return ((sint16_t)ParaMgr_pSvlLimRiPos1_W);
}
/*return range : -1500 - 1500 HS*/
sint16_t Get_pSvlDfltPos(void)
{
	return ((sint16_t)ParaMgr_pSvlDfltPos_W - 1500);
}
uint8_t Get_pSvlCorStepsNum(void)
{
	return ParaMgr_pSvlCorStepsNum_B;
}
/*return range : -1500 - 1500 HS*/
sint16_t Get_LeLamp_pSvlSensorPos(void)
{
	return (sint16_t)(((sint16_t)ParaMgr_pSvlSensorPos0_W) - 1500);
}
/*return range : -1500 - 1500 HS*/
sint16_t Get_RiLamp_pSvlSensorPos(void)
{
	return (sint16_t)(((sint16_t)ParaMgr_pSvlSensorPos1_W) - 1500);
}
uint8_t Get_LeLamp_pSvlSensorEdge(void)
{
	return ParaMgr_pSvlSensorEdge0_B;
}
uint8_t Get_RiLamp_pSvlSensorEdge(void)
{
	return ParaMgr_pSvlSensorEdge1_B;
}
/*
 * return 1:sensor input no inversion
 * return 2:sensor input inversion
 */
uint8_t Get_LeLamp_pSvlSensorInv(void)
{
	return ParaMgr_pSvlSensorInv0_B;
}
/*
 * return 1:sensor input no inversion
 * return 2:sensor input inversion
 */
uint8_t Get_RiLamp_pSvlSensorInv(void)
{
	return ParaMgr_pSvlSensorInv1_B;
}

uint8_t Get_pSvlSensorTol(void)
{
	return ParaMgr_pSvlSensorTol_B;
}

uint8_t Get_pSvlSensorRange(void)
{
	return ParaMgr_pSvlSensorRange_B;
}

uint8_t Get_pSvlMaxCorNum(void)
{
	return ParaMgr_pSvlMaxCorNum_B;
}

uint8_t Get_pSvlVmaxLowTemp(void)
{
	return (ParaMgr_pSvlVmaxLowTemp_B + 1);
}
uint8_t Get_pSvlVmaxNorm(void)
{
	return (ParaMgr_pSvlVmaxNorm_B + 1);
}
uint8_t Get_pSvlVmaxRef(void)
{
	return (ParaMgr_pSvlVmaxRef_B + 1);
}

uint16_t Get_pSvlIrunLowTemp(void)
{
	return ParaMgr_pSvlIrunLowTemp_W;
}
uint16_t Get_pSvlIrunNorm(void)
{
	return ParaMgr_pSvlIrunNorm_W;
}
uint16_t Get_pSvlIrunRef(void)
{
	return ParaMgr_pSvlIrunRef_W;
}
uint16_t Get_pSvlIholdLowTemp(void)
{
	return ParaMgr_pSvlIholdLowTemp_W;
}

uint16_t Get_pSvlIholdNorm(void)
{
	return ParaMgr_pSvlIholdNorm_W;
}
uint16_t Get_pSvlLowTempHeatupTime(void)
{
	return ParaMgr_pSvlLowTempHeatupTime_W;
}
/*return range: -50 - 200 °C*/
sint16_t Get_pSvlLowTempThreshold(void)
{
	return (sint16_t)ParaMgr_pSvlLowTempThreshold_B - 50;
}
uint16_t Get_pSvlPreTime(void)
{
	return ParaMgr_pSvlPreTime_W;
}
uint16_t Get_pSvlPostTime(void)
{
	return ParaMgr_pSvlPostTime_W;
}
uint16_t Get_pSvlUsageInterval(void)
{
	return ParaMgr_pSvlUsageInterval_W;
}
uint8_t Get_pSvlOverUsage(void)
{
	return ParaMgr_pSvlOverUsage_B;
}
uint8_t Get_pSvlNormUsage(void)
{
	return ParaMgr_pSvlNormUsage_B;
}

uint8_t Get_pSvlMinDistStart(void)
{
	return ParaMgr_pSvlMinDistStart_B;
}
uint8_t Get_pSvlMinDistTime(void)
{
	return ParaMgr_pSvlMinDistTime_B;
}

uint8_t Get_pSvlStepMode(void)
{
	return ParaMgr_pSvlStepMode_B;
}
uint16_t Get_pSvlHsPerRad(void)
{
	return ParaMgr_pSvlHsPerRad_W;
}

uint16_t *Get_pSvlAccArray(void)
{
	g_SvlAccArray[0] = ParaMgr_pSvlAcc0_W;
	g_SvlAccArray[1] = ParaMgr_pSvlAcc1_W;
	g_SvlAccArray[2] = ParaMgr_pSvlAcc2_W;
	g_SvlAccArray[3] = ParaMgr_pSvlAcc3_W;
	g_SvlAccArray[4] = ParaMgr_pSvlAcc4_W;
	g_SvlAccArray[5] = ParaMgr_pSvlAcc5_W;
	g_SvlAccArray[6] = ParaMgr_pSvlAcc6_W;
	g_SvlAccArray[7] = ParaMgr_pSvlAcc7_W;
	g_SvlAccArray[8] = ParaMgr_pSvlAcc8_W;
	g_SvlAccArray[9] = ParaMgr_pSvlAcc9_W;
	g_SvlAccArray[10] = ParaMgr_pSvlAcc10_W;
	g_SvlAccArray[11] = ParaMgr_pSvlAcc11_W;
	g_SvlAccArray[12] = ParaMgr_pSvlAcc12_W;
	g_SvlAccArray[13] = ParaMgr_pSvlAcc13_W;
	g_SvlAccArray[14] = ParaMgr_pSvlAcc14_W;
	g_SvlAccArray[15] = ParaMgr_pSvlAcc15_W;
	g_SvlAccArray[16] = ParaMgr_pSvlAcc16_W;
	g_SvlAccArray[17] = ParaMgr_pSvlAcc17_W;
	g_SvlAccArray[18] = ParaMgr_pSvlAcc18_W;
	g_SvlAccArray[19] = ParaMgr_pSvlAcc19_W;
	g_SvlAccArray[20] = ParaMgr_pSvlAcc20_W;
	g_SvlAccArray[21] = ParaMgr_pSvlAcc21_W;
	g_SvlAccArray[22] = ParaMgr_pSvlAcc22_W;
	g_SvlAccArray[23] = ParaMgr_pSvlAcc23_W;
	g_SvlAccArray[24] = ParaMgr_pSvlAcc24_W;
	g_SvlAccArray[25] = ParaMgr_pSvlAcc25_W;
	g_SvlAccArray[26] = ParaMgr_pSvlAcc26_W;
	g_SvlAccArray[27] = ParaMgr_pSvlAcc27_W;
	g_SvlAccArray[28] = ParaMgr_pSvlAcc28_W;
	g_SvlAccArray[29] = ParaMgr_pSvlAcc29_W;
	g_SvlAccArray[30] = ParaMgr_pSvlAcc30_W;
	g_SvlAccArray[31] = ParaMgr_pSvlAcc31_W;

	return g_SvlAccArray;
}

uint16_t *Get_pSvlBrakeArray(void)
{
	g_SvlBrakeArray[0] = ParaMgr_pSvlBrake0_W;
	g_SvlBrakeArray[1] = ParaMgr_pSvlBrake1_W;
	g_SvlBrakeArray[2] = ParaMgr_pSvlBrake2_W;
	g_SvlBrakeArray[3] = ParaMgr_pSvlBrake3_W;
	g_SvlBrakeArray[4] = ParaMgr_pSvlBrake4_W;
	g_SvlBrakeArray[5] = ParaMgr_pSvlBrake5_W;
	g_SvlBrakeArray[6] = ParaMgr_pSvlBrake6_W;
	g_SvlBrakeArray[7] = ParaMgr_pSvlBrake7_W;
	g_SvlBrakeArray[8] = ParaMgr_pSvlBrake8_W;
	g_SvlBrakeArray[9] = ParaMgr_pSvlBrake9_W;
	g_SvlBrakeArray[10] = ParaMgr_pSvlBrake10_W;
	g_SvlBrakeArray[11] = ParaMgr_pSvlBrake11_W;
	g_SvlBrakeArray[12] = ParaMgr_pSvlBrake12_W;
	g_SvlBrakeArray[13] = ParaMgr_pSvlBrake13_W;
	g_SvlBrakeArray[14] = ParaMgr_pSvlBrake14_W;
	g_SvlBrakeArray[15] = ParaMgr_pSvlBrake15_W;
	g_SvlBrakeArray[16] = ParaMgr_pSvlBrake16_W;
	g_SvlBrakeArray[17] = ParaMgr_pSvlBrake17_W;
	g_SvlBrakeArray[18] = ParaMgr_pSvlBrake18_W;
	g_SvlBrakeArray[19] = ParaMgr_pSvlBrake19_W;
	g_SvlBrakeArray[20] = ParaMgr_pSvlBrake20_W;
	g_SvlBrakeArray[21] = ParaMgr_pSvlBrake21_W;
	g_SvlBrakeArray[22] = ParaMgr_pSvlBrake22_W;
	g_SvlBrakeArray[23] = ParaMgr_pSvlBrake23_W;
	g_SvlBrakeArray[24] = ParaMgr_pSvlBrake24_W;
	g_SvlBrakeArray[25] = ParaMgr_pSvlBrake25_W;
	g_SvlBrakeArray[26] = ParaMgr_pSvlBrake26_W;
	g_SvlBrakeArray[27] = ParaMgr_pSvlBrake27_W;
	g_SvlBrakeArray[28] = ParaMgr_pSvlBrake28_W;
	g_SvlBrakeArray[29] = ParaMgr_pSvlBrake29_W;
	g_SvlBrakeArray[30] = ParaMgr_pSvlBrake30_W;
	g_SvlBrakeArray[31] = ParaMgr_pSvlBrake31_W;
	return g_SvlBrakeArray;
}
uint8_t Get_pSvlstalldetethreshold(void)
{
	return ParaMgr_pSvlstalldetethreshold_B;
}

/*******************************************************************Light Function: AHB&AHB2*************************************************************/
/*
 */

uint16_t Get_pAHBCDistOfHiBeam(void) { return ParaMgr_pAHBCDistOfHiBeam_W; }

uint16_t Get_pAHB2OncmngDist1(void)	{ return ParaMgr_pAHB2OncmngDist1_W; }
uint16_t Get_pAHB2OncmngDist2(void)	{ return ParaMgr_pAHB2OncmngDist2_W; }
uint16_t Get_pAHB2OncmngDist3(void)	{ return ParaMgr_pAHB2OncmngDist3_W; }
uint16_t Get_pAHB2OncmngDist4(void)	{ return ParaMgr_pAHB2OncmngDist4_W; }
uint16_t Get_pAHB2OncmngDist5(void)	{ return ParaMgr_pAHB2OncmngDist5_W; }
uint16_t Get_pAHB2OncmngDist6(void)	{ return ParaMgr_pAHB2OncmngDist6_W; }
uint16_t Get_pAHB2OncmngDist7(void)	{ return ParaMgr_pAHB2OncmngDist7_W; }
uint16_t Get_pAHB2OncmngDist8(void)	{ return ParaMgr_pAHB2OncmngDist8_W; }
uint16_t Get_pAHB2OncmngDist9(void)	{ return ParaMgr_pAHB2OncmngDist9_W; }

uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist1(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist1_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist2(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist2_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist3(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist3_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist4(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist4_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist5(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist5_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist6(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist6_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist7(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist7_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist8(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist8_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist9(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist9_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist10(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2OncmngDist10_W; }

uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist1(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist1_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist2(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist2_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist3(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist3_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist4(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist4_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist5(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist5_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist6(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist6_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist7(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist7_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist8(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist8_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist9(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist9_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist10(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2OncmngDist10_W; }

uint16_t Get_pAHB2PrecdngDist1(void) { return ParaMgr_pAHB2PrecdngDist1_W; }
uint16_t Get_pAHB2PrecdngDist2(void) { return ParaMgr_pAHB2PrecdngDist2_W; }
uint16_t Get_pAHB2PrecdngDist3(void) { return ParaMgr_pAHB2PrecdngDist3_W; }
uint16_t Get_pAHB2PrecdngDist4(void) { return ParaMgr_pAHB2PrecdngDist4_W; }
uint16_t Get_pAHB2PrecdngDist5(void) { return ParaMgr_pAHB2PrecdngDist5_W; }
uint16_t Get_pAHB2PrecdngDist6(void) { return ParaMgr_pAHB2PrecdngDist6_W; }
uint16_t Get_pAHB2PrecdngDist7(void) { return ParaMgr_pAHB2PrecdngDist7_W; }
uint16_t Get_pAHB2PrecdngDist8(void) { return ParaMgr_pAHB2PrecdngDist8_W; }
uint16_t Get_pAHB2PrecdngDist9(void) { return ParaMgr_pAHB2PrecdngDist9_W; }

uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist1(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist1_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist2(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist2_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist3(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist3_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist4(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist4_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist5(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist5_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist6(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist6_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist7(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist7_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist8(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist8_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist9(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist9_W; }
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist10(void) { return ParaMgr_LeLamp_pLVLOffsetLeAHB2PrecdngDist10_W; }

uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist1(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist1_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist2(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist2_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist3(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist3_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist4(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist4_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist5(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist5_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist6(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist6_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist7(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist7_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist8(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist8_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist9(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist9_W; }
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist10(void) { return ParaMgr_RiLamp_pLVLOffsetRiAHB2PrecdngDist10_W; }

uint16_t Get_pAHB2FrznTi(void) { return ParaMgr_pAHB2FrznTi_W; }

uint8_t Get_pAHB2SftyMrgnOncmngVrtcl  (void) { return ParaMgr_pAHB2SftyMrgnOncmngVrtcl_B;   }
uint8_t Get_pAHB2SftyMrgnPrecedngVrtcl(void) { return ParaMgr_pAHB2SftyMrgnPrecedngVrtcl_B; }

uint8_t Get_pAHB2LightLoBeamFlatInt(void) { return ParaMgr_pAHB2LightLoBeamFlatInt_B; }
uint8_t Get_pAHB2LightLoBeamKinkInt(void) { return ParaMgr_pAHB2LightLoBeamKinkInt_B; }
uint8_t Get_pAHB2LightHiBeamSpotInt(void) { return ParaMgr_pAHB2LightHiBeamSpotInt_B; }
uint8_t Get_pAHB2LightHiBeamSailInt(void) { return ParaMgr_pAHB2LightHiBeamSailInt_B; }

uint16_t Get_pAHB2ChngOvrTime(void) { return ParaMgr_pAHB2ChngOvrTime_W; }

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

uint16_t Get_pSTITime(void)
{
	return ParaMgr_pSTITime_W;
}

uint8_t Get_pVariantTyp(void)
{
	return ParaMgr_pVariantTyp_B;
}
uint8_t Get_pLedSeqTiHwl(void)
{
	return ParaMgr_pLedSeqTiHwl_B;
}

uint8_t Get_pLegalRequirement(void)
{
	return ParaMgr_pLegalRequirement_B;
}
uint8_t Get_pLMMBaudRateSet(void)
{
	return ParaMgr_pLMMBaudRateSet_B;
}


uint8_t Get_pFrntCrossAvl(void)
{
	return ParaMgr_pFrntCrossAvl_B;
}

uint8_t Get_pGrilleAvl(void)
{
	return ParaMgr_pGrilleAvl_B;
}

uint8_t Get_pFssRelFailSvlDflt(void)
{
	return ParaMgr_pFssRelFailSvlDflt_B;
}

uint8_t Get_pLedIntensPosLDuty(void)
{
	return ParaMgr_pLedIntensPosLDuty_B;
}

uint8_t Get_pLedIntensGrillLDuty(void)
{
	return ParaMgr_pLedIntensGrillLDuty_B;
}

uint8_t Get_pLedIntensConerLDuty(void)
{
	return ParaMgr_pLedIntensConerLDuty_B;
}

uint8_t Get_pLedIntensFogLDuty(void)
{
	return ParaMgr_pLedIntensFogLDuty_B;
}

uint8_t Get_pLedIntensCrossLDuty(void)
{
	return ParaMgr_pLedIntensCrossLDuty_B;
}


uint8_t Get_pLedGamma(void)
{
	return ParaMgr_pLedGamma_B;
}

uint8_t Get_pLedONDelay(Light_Functions lf)
{
	uint8_t rtval;

	switch (lf)
	{
	case E_LowBeamFlat:
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOnDelay_B;
		break;

	case E_HighBeamSail:
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
	case E_LowBeamFlat:
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOFFDelay_B;
		break;

	case E_HighBeamSail:
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
	case E_LowBeamFlat:
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOnRampTi_W;
		break;

	case E_HighBeamSail:
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
	case E_LowBeamFlat:
	case E_LowBeamKink:
		rtval = ParaMgr_pLedLoBeamOFFRampTi_W;
		break;

	case E_HighBeamSail:
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

uint16_t Get_pVehHeadlampOverhang(void)
{
    return ParaMgr_pVehHeadlampOverhang_W;
}

uint16_t Get_pVehHeadlampHeight(void)
{
    return ParaMgr_pVehHeadlampHeight_W;
}

uint16_t Get_pVehWheelBase(void)
{
    return ParaMgr_pVehWheelBase_W;
}

uint8_t Get_pLogoLowbeamPOS(void)
{
    return ParaMgr_pLogoLowbeamPOS_B;
}

uint8_t Get_pFrontCrossPositionlamp(void)
{
    return ParaMgr_pFrontCrossPositionlamp_B;
}

uint8_t Get_pSBLCornerLightPWM(void)
{
    return ParaMgr_pSBLCornerLightPWM_B;
}

uint8_t Get_pPincodeEnable(void)
{
    return ParaMgr_pPincodeEnable_B;
}

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************LED Groups related Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/

const uint8 *Get_pTIPixelToLedUnitAddress(void)
{
	return ParaMgr_pTIPixelToLedUnit_B;
}


/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Fan Parameter*****************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint16_t Get_pFanToChannel(void)        { return ParaMgr_pFanToChannel_W; }
uint16_t Get_pFanOnLedCh(void)          { return ParaMgr_pFanOnLedCh_W; }
uint8_t  Get_pFanNumber(void)           { return ParaMgr_pFanNumber_B; }
uint8_t  Get_pFanAmbTempHys(void)       { return ParaMgr_pFanAmbTempHys_B; }
uint8_t  Get_pFanLedTempHys(void)       { return ParaMgr_pFanLedTempHys_B; }
uint8_t  Get_pFanControlPin(void)       { return ParaMgr_pFanControlPin_B; }
uint16_t Get_pFanSupInrushTime(void)    { return ParaMgr_pFanSupInrushTime_W; }
uint16_t Get_pFanNomCurrent(void)       { return ParaMgr_pFanNomCurrent_W; }
uint8_t  Get_pFanNomCurTol(void)        { return ParaMgr_pFanNomCurTol_B; }
uint16_t Get_pFanLockDebTime(void)      { return ParaMgr_pFanLockDebTime_W; }
uint8_t  Get_pFanMaxVolt(void)          { return ParaMgr_pFanMaxVolt_B; }
uint8_t  Get_pFanMinVolt(void)          { return ParaMgr_pFanMinVolt_B; }
uint8_t  Get_pFanDiagInputType(void)    { return ParaMgr_pFanDiagInputType_B; }
uint8_t  Get_pFanLockProtOnTime0(void)  { return ParaMgr_pFanLockProtOnTime0_B; }
uint8_t  Get_pFanLockProtOnTime1(void)  { return ParaMgr_pFanLockProtOnTime1_B; }
uint8_t  Get_pFanLockProtTimeTol0(void) { return ParaMgr_pFanLockProtTimeTol0_B; }
uint8_t  Get_pFanLockProtTimeTol1(void) { return ParaMgr_pFanLockProtTimeTol1_B; }
uint8_t  Get_pFanLockRetryOffTime(void) { return ParaMgr_pFanLockRetryOffTime_B; }
uint8_t  Get_pFanFaultSignal(void)      { return ParaMgr_pFanFaultSignal_B; }
uint8_t  Get_pFanCoolLedTempLo(void)    { return ParaMgr_pFanCoolLedTempLo_B; }
uint8_t  Get_pFanCoolLedTempHi(void)    { return ParaMgr_pFanCoolLedTempHi_B; }
uint8_t  Get_pFanCoolPowerLo(void)      { return ParaMgr_pFanCoolPowerLo_B; }
uint8_t  Get_pFanCoolPowerHi(void)      { return ParaMgr_pFanCoolPowerHi_B; }
uint8_t  Get_pFanDefAmbTempLo(void)     { return ParaMgr_pFanDefAmbTempLo_B; }
uint8_t  Get_pFanDefAmbTempHi(void)     { return ParaMgr_pFanDefAmbTempHi_B; }
uint8_t  Get_pFanDefPowerLo(void)       { return ParaMgr_pFanDefPowerLo_B; }
uint8_t  Get_pFanDefPowerHi(void)       { return ParaMgr_pFanDefPowerHi_B; }
uint8_t  Get_pFanDefLightFct(void)      { return ParaMgr_pFanDefLightFct_B; }
uint8_t  Get_pFanDeiAmbTempLo(void)     { return ParaMgr_pFanDeiAmbTempLo_B; }
uint8_t  Get_pFanDeiAmbTempHi(void)     { return ParaMgr_pFanDeiAmbTempHi_B; }
uint8_t  Get_pFanDeiPowerLo(void)       { return ParaMgr_pFanDeiPowerLo_B; }
uint8_t  Get_pFanDeiPowerHi(void)       { return ParaMgr_pFanDeiPowerHi_B; }
uint8_t  Get_pFanDeiLightFct(void)      { return ParaMgr_pFanDeiLightFct_B; }
uint8_t  Get_pFan2CoolLedTempLo(void)   { return ParaMgr_pFan2CoolLedTempLo_B; }


/****************************************************************************************************/
/****************************************************************************************************/
/******************************************ADB Parameter*********************************************/
/****************************************************************************************************/
/****************************************************************************************************/

const uint16_t * Get_pPixelLeft_LeftBdr(void)   { return ParaMgr_LeLamp_pPixelLeft_LeftBdr_W; }
const uint16_t * Get_pPixelLeft_RightBdr(void)  { return ParaMgr_LeLamp_pPixelLeft_RightBdr_W; }
const uint16_t * Get_pPixelRight_LeftBdr(void)  { return ParaMgr_RiLamp_pPixelRight_LeftBdr_W; }
const uint16_t * Get_pPixelRight_RightBdr(void) { return ParaMgr_RiLamp_pPixelRight_RightBdr_W; }


void  Get_ParaMgr_pFanADBleEna_B( uint8* ADBangletemp )
{
	uint8 i=0;
	for(i=0;i<84;i++)
	{
		ADBangletemp[i]=ParaMgr_LeLamp_pADBPxlLeftEna_B[i];
		
	}
}

void  Get_ParaMgr_pFanADBriEna_B( uint8* ADBangletemp )
{
	uint16 i=0;
	for(i=0;i<84;i++)
	{
		ADBangletemp[i]=ParaMgr_RiLamp_pADBPxlRightEna_B[i];
		
	}
}

void  Get_ParaMgr_pFanADBlepPixel_LeftBdrl( uint16* ADBangletemp )
{
	uint16 i=0;
	for(i=0;i<84;i++)
	{
		ADBangletemp[i]=ParaMgr_LeLamp_pPixelLeft_LeftBdr_W[i];
		
	}
}
void  Get_ParaMgr_pFanADBlepPixel_RightBdr( uint16* ADBangletemp )
{
		uint16 i=0;
	for(i=0;i<84;i++)
	{
		ADBangletemp[i]=ParaMgr_LeLamp_pPixelLeft_RightBdr_W[i];
	}
}

void  Get_ParaMgr_pFanADBripPixel_LeftBdrl( uint16* ADBangletemp )
{
		uint16 i=0;
	for(i=0;i<84;i++)
	{
		ADBangletemp[i]=ParaMgr_RiLamp_pPixelRight_LeftBdr_W[i];
	}
}
void  Get_ParaMgr_pFanADBripPixel_RightBdr( uint16* ADBangletemp )
{
		uint16 i=0;
	for(i=0;i<84;i++)
	{
		ADBangletemp[i]=ParaMgr_RiLamp_pPixelRight_RightBdr_W[i];
	}
}

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Dynamic Light Pattern Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*LED Groups*/
uint8 Get_Dynamic_Light_Function_GroupFunc_ByGroup(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_Group1Func_B;
		case Group2:
			return ParaMgr_Group2Func_B;
		case Group3:
			return ParaMgr_Group3Func_B;
		case Group4:
			return ParaMgr_Group4Func_B;
		case Group5:
			return ParaMgr_Group5Func_B;
		case Group6:
			return ParaMgr_Group6Func_B;
		case Group7:
			return ParaMgr_Group7Func_B;
		case Group8:
			return ParaMgr_Group8Func_B;
		case Group9:
			return ParaMgr_Group9Func_B;
		case Group10:
			return ParaMgr_Group10Func_B;
		case Group11:
			return ParaMgr_Group11Func_B;
		case Group12:
			return ParaMgr_Group12Func_B;
		case Group13:
			return ParaMgr_Group13Func_B;
		case Group14:
			return ParaMgr_Group14Func_B;
		case Group15:
			return ParaMgr_Group15Func_B;
		case Group16:
			return ParaMgr_Group16Func_B;
		case Group17:
			return ParaMgr_Group17Func_B;
		case Group18:
			return ParaMgr_Group18Func_B;
		case Group19:
			return ParaMgr_Group19Func_B;
		case Group20:
			return ParaMgr_Group20Func_B;
		case Group21:
			return ParaMgr_Group21Func_B;
		case Group22:
			return ParaMgr_Group22Func_B;
		case Group23:
			return ParaMgr_Group23Func_B;
		case Group24:
			return ParaMgr_Group24Func_B;
	}
}

const uint8 *Get_Dynamic_Light_Function_GroupPixel_Info_ByGroup(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_Group1Pixel_B;
		case Group2:
			return ParaMgr_Group2Pixel_B;
		case Group3:
			return ParaMgr_Group3Pixel_B;
		case Group4:
			return ParaMgr_Group4Pixel_B;
		case Group5:
			return ParaMgr_Group5Pixel_B;
		case Group6:
			return ParaMgr_Group6Pixel_B;
		case Group7:
			return ParaMgr_Group7Pixel_B;
		case Group8:
			return ParaMgr_Group8Pixel_B;
		case Group9:
			return ParaMgr_Group9Pixel_B;
		case Group10:
			return ParaMgr_Group10Pixel_B;
		case Group11:
			return ParaMgr_Group11Pixel_B;
		case Group12:
			return ParaMgr_Group12Pixel_B;
		case Group13:
			return ParaMgr_Group13Pixel_B;
		case Group14:
			return ParaMgr_Group14Pixel_B;
		case Group15:
			return ParaMgr_Group15Pixel_B;
		case Group16:
			return ParaMgr_Group16Pixel_B;
		case Group17:
			return ParaMgr_Group17Pixel_B;
		case Group18:
			return ParaMgr_Group18Pixel_B;
		case Group19:
			return ParaMgr_Group19Pixel_B;
		case Group20:
			return ParaMgr_Group20Pixel_B;
		case Group21:
			return ParaMgr_Group21Pixel_B;
		case Group22:
			return ParaMgr_Group22Pixel_B;
		case Group23:
			return ParaMgr_Group23Pixel_B;
		case Group24:
			return ParaMgr_Group24Pixel_B;
	}
    return NULL;
}

const uint8 *Get_Dynamic_Light_Function_GroupChannel_Info_ByGroup(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_Group1Ch_B;
		case Group2:
			return ParaMgr_Group2Ch_B;
		case Group3:
			return ParaMgr_Group3Ch_B;
		case Group4:
			return ParaMgr_Group4Ch_B;
		case Group5:
			return ParaMgr_Group5Ch_B;
		case Group6:
			return ParaMgr_Group6Ch_B;
		case Group7:
			return ParaMgr_Group7Ch_B;
		case Group8:
			return ParaMgr_Group8Ch_B;
		case Group9:
			return ParaMgr_Group9Ch_B;
		case Group10:
			return ParaMgr_Group10Ch_B;
		case Group11:
			return ParaMgr_Group11Ch_B;
		case Group12:
			return ParaMgr_Group12Ch_B;
		case Group13:
			return ParaMgr_Group13Ch_B;
		case Group14:
			return ParaMgr_Group14Ch_B;
		case Group15:
			return ParaMgr_Group15Ch_B;
		case Group16:
			return ParaMgr_Group16Ch_B;
		case Group17:
			return ParaMgr_Group17Ch_B;
		case Group18:
			return ParaMgr_Group18Ch_B;
		case Group19:
			return ParaMgr_Group19Ch_B;
		case Group20:
			return ParaMgr_Group20Ch_B;
		case Group21:
			return ParaMgr_Group21Ch_B;
		case Group22:
			return ParaMgr_Group22Ch_B;
		case Group23:
			return ParaMgr_Group23Ch_B;
		case Group24:
			return ParaMgr_Group24Ch_B;
	}
    return NULL;
}

uint8 Get_Dynamic_Light_Function_p_WelGbyPatten(void)
{
	return ParaMgr_pWelGbyPatten_B;
}

uint8 Get_Dynamic_Light_Function_p_ParaMgr_pWaitmode(void)
{
	return ParaMgr_pWaitmode_B;
}

/*WelGby Pattern*/
uint8 Get_Dynamic_Light_Function_pWelMotorEN_B(void)
{
	return ParaMgr_pWelMotorEn_B;
}

uint16 Get_Dynamic_Light_Function_pWelLevMotorTime_W(void)
{
	return ParaMgr_pWelLevMotorTime_W;
}

uint16 Get_Dynamic_Light_Function_pWelSwivMotorTime_W(void)
{
	return ParaMgr_pWelSwivMotorTime_W;
}

uint32 Get_Dynamic_Light_Function_pELCWelcomeTimeout_DW(void)
{
	return ParaMgr_pELCWelComeTimeout_DW;
}

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
		case Group9:
			return ParaMgr_pWelcomP1G9ModeLowBri_B;
		case Group10:
			return ParaMgr_pWelcomP1G10ModeLowBri_B;
		case Group11:
			return ParaMgr_pWelcomP1G11ModeLowBri_B;
		case Group12:
			return ParaMgr_pWelcomP1G12ModeLowBri_B;
		case Group13:
			return ParaMgr_pWelcomP1G13ModeLowBri_B;
		case Group14:
			return ParaMgr_pWelcomP1G14ModeLowBri_B;
		case Group15:
			return ParaMgr_pWelcomP1G15ModeLowBri_B;
		case Group16:
			return ParaMgr_pWelcomP1G16ModeLowBri_B;
		case Group17:
			return ParaMgr_pWelcomP1G17ModeLowBri_B;
		case Group18:
			return ParaMgr_pWelcomP1G18ModeLowBri_B;
		case Group19:
			return ParaMgr_pWelcomP1G19ModeLowBri_B;
		case Group20:
			return ParaMgr_pWelcomP1G20ModeLowBri_B;
		case Group21:
			return ParaMgr_pWelcomP1G21ModeLowBri_B;
		case Group22:
			return ParaMgr_pWelcomP1G22ModeLowBri_B;
		case Group23:
			return ParaMgr_pWelcomP1G23ModeLowBri_B;
		case Group24:
			return ParaMgr_pWelcomP1G24ModeLowBri_B;
	}
    return NULL;
}

const uint8 *Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_pWelcomP1G1ModeLowBri_B;
		case Group2:
			return ParaMgr_HCMR_pWelcomP1G2ModeLowBri_B;
		case Group3:
			return ParaMgr_HCMR_pWelcomP1G3ModeLowBri_B;
		case Group4:
			return ParaMgr_HCMR_pWelcomP1G4ModeLowBri_B;
		case Group5:
			return ParaMgr_HCMR_pWelcomP1G5ModeLowBri_B;
		case Group6:
			return ParaMgr_HCMR_pWelcomP1G6ModeLowBri_B;
		case Group7:
			return ParaMgr_HCMR_pWelcomP1G7ModeLowBri_B;
		case Group8:
			return ParaMgr_HCMR_pWelcomP1G8ModeLowBri_B;
		case Group9:
			return ParaMgr_HCMR_pWelcomP1G9ModeLowBri_B;
		case Group10:
			return ParaMgr_HCMR_pWelcomP1G10ModeLowBri_B;
		case Group11:
			return ParaMgr_HCMR_pWelcomP1G11ModeLowBri_B;
		case Group12:
			return ParaMgr_HCMR_pWelcomP1G12ModeLowBri_B;
		case Group13:
			return ParaMgr_HCMR_pWelcomP1G13ModeLowBri_B;
		case Group14:
			return ParaMgr_HCMR_pWelcomP1G14ModeLowBri_B;
		case Group15:
			return ParaMgr_HCMR_pWelcomP1G15ModeLowBri_B;
		case Group16:
			return ParaMgr_HCMR_pWelcomP1G16ModeLowBri_B;
		case Group17:
			return ParaMgr_HCMR_pWelcomP1G17ModeLowBri_B;
		case Group18:
			return ParaMgr_HCMR_pWelcomP1G18ModeLowBri_B;
		case Group19:
			return ParaMgr_HCMR_pWelcomP1G19ModeLowBri_B;
		case Group20:
			return ParaMgr_HCMR_pWelcomP1G20ModeLowBri_B;
		case Group21:
			return ParaMgr_HCMR_pWelcomP1G21ModeLowBri_B;
		case Group22:
			return ParaMgr_HCMR_pWelcomP1G22ModeLowBri_B;
		case Group23:
			return ParaMgr_HCMR_pWelcomP1G23ModeLowBri_B;
		case Group24:
			return ParaMgr_HCMR_pWelcomP1G24ModeLowBri_B;
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
		case Group9:
			return ParaMgr_pWelcomP1G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_pWelcomP1G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_pWelcomP1G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_pWelcomP1G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_pWelcomP1G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_pWelcomP1G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_pWelcomP1G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_pWelcomP1G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_pWelcomP1G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_pWelcomP1G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_pWelcomP1G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_pWelcomP1G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_pWelcomP1G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_pWelcomP1G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_pWelcomP1G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_pWelcomP1G24OffTiConTiUpBri_W;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_pWelcomP1G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_HCMR_pWelcomP1G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_HCMR_pWelcomP1G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_HCMR_pWelcomP1G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_HCMR_pWelcomP1G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_HCMR_pWelcomP1G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_HCMR_pWelcomP1G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_HCMR_pWelcomP1G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_HCMR_pWelcomP1G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_HCMR_pWelcomP1G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_HCMR_pWelcomP1G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_HCMR_pWelcomP1G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_HCMR_pWelcomP1G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_HCMR_pWelcomP1G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_HCMR_pWelcomP1G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_HCMR_pWelcomP1G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_HCMR_pWelcomP1G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_HCMR_pWelcomP1G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_HCMR_pWelcomP1G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_HCMR_pWelcomP1G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_HCMR_pWelcomP1G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_HCMR_pWelcomP1G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_HCMR_pWelcomP1G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_HCMR_pWelcomP1G24OffTiConTiUpBri_W;
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
		case Group9:
			return ParaMgr_pWelcomP2G9ModeLowBri_B;
		case Group10:
			return ParaMgr_pWelcomP2G10ModeLowBri_B;
		case Group11:
			return ParaMgr_pWelcomP2G11ModeLowBri_B;
		case Group12:
			return ParaMgr_pWelcomP2G12ModeLowBri_B;
		case Group13:
			return ParaMgr_pWelcomP2G13ModeLowBri_B;
		case Group14:
			return ParaMgr_pWelcomP2G14ModeLowBri_B;
		case Group15:
			return ParaMgr_pWelcomP2G15ModeLowBri_B;
		case Group16:
			return ParaMgr_pWelcomP2G16ModeLowBri_B;
		case Group17:
			return ParaMgr_pWelcomP2G17ModeLowBri_B;
		case Group18:
			return ParaMgr_pWelcomP2G18ModeLowBri_B;
		case Group19:
			return ParaMgr_pWelcomP2G19ModeLowBri_B;
		case Group20:
			return ParaMgr_pWelcomP2G20ModeLowBri_B;
		case Group21:
			return ParaMgr_pWelcomP2G21ModeLowBri_B;
		case Group22:
			return ParaMgr_pWelcomP2G22ModeLowBri_B;
		case Group23:
			return ParaMgr_pWelcomP2G23ModeLowBri_B;
		case Group24:
			return ParaMgr_pWelcomP2G24ModeLowBri_B;
	}
    return NULL;
}

const uint8 *Get_Dynamic_Light_Function_pWelcomP2ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_pWelcomP2G1ModeLowBri_B;
		case Group2:
			return ParaMgr_HCMR_pWelcomP2G2ModeLowBri_B;
		case Group3:
			return ParaMgr_HCMR_pWelcomP2G3ModeLowBri_B;
		case Group4:
			return ParaMgr_HCMR_pWelcomP2G4ModeLowBri_B;
		case Group5:
			return ParaMgr_HCMR_pWelcomP2G5ModeLowBri_B;
		case Group6:
			return ParaMgr_HCMR_pWelcomP2G6ModeLowBri_B;
		case Group7:
			return ParaMgr_HCMR_pWelcomP2G7ModeLowBri_B;
		case Group8:
			return ParaMgr_HCMR_pWelcomP2G8ModeLowBri_B;
		case Group9:
			return ParaMgr_HCMR_pWelcomP2G9ModeLowBri_B;
		case Group10:
			return ParaMgr_HCMR_pWelcomP2G10ModeLowBri_B;
		case Group11:
			return ParaMgr_HCMR_pWelcomP2G11ModeLowBri_B;
		case Group12:
			return ParaMgr_HCMR_pWelcomP2G12ModeLowBri_B;
		case Group13:
			return ParaMgr_HCMR_pWelcomP2G13ModeLowBri_B;
		case Group14:
			return ParaMgr_HCMR_pWelcomP2G14ModeLowBri_B;
		case Group15:
			return ParaMgr_HCMR_pWelcomP2G15ModeLowBri_B;
		case Group16:
			return ParaMgr_HCMR_pWelcomP2G16ModeLowBri_B;
		case Group17:
			return ParaMgr_HCMR_pWelcomP2G17ModeLowBri_B;
		case Group18:
			return ParaMgr_HCMR_pWelcomP2G18ModeLowBri_B;
		case Group19:
			return ParaMgr_HCMR_pWelcomP2G19ModeLowBri_B;
		case Group20:
			return ParaMgr_HCMR_pWelcomP2G20ModeLowBri_B;
		case Group21:
			return ParaMgr_HCMR_pWelcomP2G21ModeLowBri_B;
		case Group22:
			return ParaMgr_HCMR_pWelcomP2G22ModeLowBri_B;
		case Group23:
			return ParaMgr_HCMR_pWelcomP2G23ModeLowBri_B;
		case Group24:
			return ParaMgr_HCMR_pWelcomP2G24ModeLowBri_B;
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
		case Group9:
			return ParaMgr_pWelcomP2G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_pWelcomP2G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_pWelcomP2G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_pWelcomP2G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_pWelcomP2G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_pWelcomP2G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_pWelcomP2G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_pWelcomP2G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_pWelcomP2G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_pWelcomP2G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_pWelcomP2G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_pWelcomP2G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_pWelcomP2G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_pWelcomP2G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_pWelcomP2G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_pWelcomP2G24OffTiConTiUpBri_W;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pWelcomP2OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_pWelcomP2G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_HCMR_pWelcomP2G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_HCMR_pWelcomP2G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_HCMR_pWelcomP2G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_HCMR_pWelcomP2G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_HCMR_pWelcomP2G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_HCMR_pWelcomP2G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_HCMR_pWelcomP2G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_HCMR_pWelcomP2G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_HCMR_pWelcomP2G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_HCMR_pWelcomP2G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_HCMR_pWelcomP2G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_HCMR_pWelcomP2G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_HCMR_pWelcomP2G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_HCMR_pWelcomP2G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_HCMR_pWelcomP2G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_HCMR_pWelcomP2G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_HCMR_pWelcomP2G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_HCMR_pWelcomP2G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_HCMR_pWelcomP2G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_HCMR_pWelcomP2G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_HCMR_pWelcomP2G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_HCMR_pWelcomP2G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_HCMR_pWelcomP2G24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Welcome 3*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP3ModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pWelcomP3G1ModeLowBri_B;
		case Group2:
			return ParaMgr_pWelcomP3G2ModeLowBri_B;
		case Group3:
			return ParaMgr_pWelcomP3G3ModeLowBri_B;
		case Group4:
			return ParaMgr_pWelcomP3G4ModeLowBri_B;
		case Group5:
			return ParaMgr_pWelcomP3G5ModeLowBri_B;
		case Group6:
			return ParaMgr_pWelcomP3G6ModeLowBri_B;
		case Group7:
			return ParaMgr_pWelcomP3G7ModeLowBri_B;
		case Group8:
			return ParaMgr_pWelcomP3G8ModeLowBri_B;
		case Group9:
			return ParaMgr_pWelcomP3G9ModeLowBri_B;
		case Group10:
			return ParaMgr_pWelcomP3G10ModeLowBri_B;
		case Group11:
			return ParaMgr_pWelcomP3G11ModeLowBri_B;
		case Group12:
			return ParaMgr_pWelcomP3G12ModeLowBri_B;
		case Group13:
			return ParaMgr_pWelcomP3G13ModeLowBri_B;
		case Group14:
			return ParaMgr_pWelcomP3G14ModeLowBri_B;
		case Group15:
			return ParaMgr_pWelcomP3G15ModeLowBri_B;
		case Group16:
			return ParaMgr_pWelcomP3G16ModeLowBri_B;
		case Group17:
			return ParaMgr_pWelcomP3G17ModeLowBri_B;
		case Group18:
			return ParaMgr_pWelcomP3G18ModeLowBri_B;
		case Group19:
			return ParaMgr_pWelcomP3G19ModeLowBri_B;
		case Group20:
			return ParaMgr_pWelcomP3G20ModeLowBri_B;
		case Group21:
			return ParaMgr_pWelcomP3G21ModeLowBri_B;
		case Group22:
			return ParaMgr_pWelcomP3G22ModeLowBri_B;
		case Group23:
			return ParaMgr_pWelcomP3G23ModeLowBri_B;
		case Group24:
			return ParaMgr_pWelcomP3G24ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pWelcomP3OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pWelcomP3G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_pWelcomP3G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_pWelcomP3G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_pWelcomP3G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_pWelcomP3G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_pWelcomP3G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_pWelcomP3G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_pWelcomP3G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_pWelcomP3G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_pWelcomP3G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_pWelcomP3G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_pWelcomP3G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_pWelcomP3G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_pWelcomP3G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_pWelcomP3G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_pWelcomP3G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_pWelcomP3G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_pWelcomP3G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_pWelcomP3G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_pWelcomP3G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_pWelcomP3G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_pWelcomP3G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_pWelcomP3G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_pWelcomP3G24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Goodbye 1*/
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP1ModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pGoodbyeP1G1ModeLowBri_B;
		case Group2:
			return ParaMgr_pGoodbyeP1G2ModeLowBri_B;
		case Group3:
			return ParaMgr_pGoodbyeP1G3ModeLowBri_B;
		case Group4:
			return ParaMgr_pGoodbyeP1G4ModeLowBri_B;
		case Group5:
			return ParaMgr_pGoodbyeP1G5ModeLowBri_B;
		case Group6:
			return ParaMgr_pGoodbyeP1G6ModeLowBri_B;
		case Group7:
			return ParaMgr_pGoodbyeP1G7ModeLowBri_B;
		case Group8:
			return ParaMgr_pGoodbyeP1G8ModeLowBri_B;
		case Group9:
			return ParaMgr_pGoodbyeP1G9ModeLowBri_B;
		case Group10:
			return ParaMgr_pGoodbyeP1G10ModeLowBri_B;
		case Group11:
			return ParaMgr_pGoodbyeP1G11ModeLowBri_B;
		case Group12:
			return ParaMgr_pGoodbyeP1G12ModeLowBri_B;
		case Group13:
			return ParaMgr_pGoodbyeP1G13ModeLowBri_B;
		case Group14:
			return ParaMgr_pGoodbyeP1G14ModeLowBri_B;
		case Group15:
			return ParaMgr_pGoodbyeP1G15ModeLowBri_B;
		case Group16:
			return ParaMgr_pGoodbyeP1G16ModeLowBri_B;
		case Group17:
			return ParaMgr_pGoodbyeP1G17ModeLowBri_B;
		case Group18:
			return ParaMgr_pGoodbyeP1G18ModeLowBri_B;
		case Group19:
			return ParaMgr_pGoodbyeP1G19ModeLowBri_B;
		case Group20:
			return ParaMgr_pGoodbyeP1G20ModeLowBri_B;
		case Group21:
			return ParaMgr_pGoodbyeP1G21ModeLowBri_B;
		case Group22:
			return ParaMgr_pGoodbyeP1G22ModeLowBri_B;
		case Group23:
			return ParaMgr_pGoodbyeP1G23ModeLowBri_B;
		case Group24:
			return ParaMgr_pGoodbyeP1G24ModeLowBri_B;
	}
    return NULL;
}

const uint8 *Get_Dynamic_Light_Function_pGoodbyeP1ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_pGoodbyeP1G1ModeLowBri_B;
		case Group2:
			return ParaMgr_HCMR_pGoodbyeP1G2ModeLowBri_B;
		case Group3:
			return ParaMgr_HCMR_pGoodbyeP1G3ModeLowBri_B;
		case Group4:
			return ParaMgr_HCMR_pGoodbyeP1G4ModeLowBri_B;
		case Group5:
			return ParaMgr_HCMR_pGoodbyeP1G5ModeLowBri_B;
		case Group6:
			return ParaMgr_HCMR_pGoodbyeP1G6ModeLowBri_B;
		case Group7:
			return ParaMgr_HCMR_pGoodbyeP1G7ModeLowBri_B;
		case Group8:
			return ParaMgr_HCMR_pGoodbyeP1G8ModeLowBri_B;
		case Group9:
			return ParaMgr_HCMR_pGoodbyeP1G9ModeLowBri_B;
		case Group10:
			return ParaMgr_HCMR_pGoodbyeP1G10ModeLowBri_B;
		case Group11:
			return ParaMgr_HCMR_pGoodbyeP1G11ModeLowBri_B;
		case Group12:
			return ParaMgr_HCMR_pGoodbyeP1G12ModeLowBri_B;
		case Group13:
			return ParaMgr_HCMR_pGoodbyeP1G13ModeLowBri_B;
		case Group14:
			return ParaMgr_HCMR_pGoodbyeP1G14ModeLowBri_B;
		case Group15:
			return ParaMgr_HCMR_pGoodbyeP1G15ModeLowBri_B;
		case Group16:
			return ParaMgr_HCMR_pGoodbyeP1G16ModeLowBri_B;
		case Group17:
			return ParaMgr_HCMR_pGoodbyeP1G17ModeLowBri_B;
		case Group18:
			return ParaMgr_HCMR_pGoodbyeP1G18ModeLowBri_B;
		case Group19:
			return ParaMgr_HCMR_pGoodbyeP1G19ModeLowBri_B;
		case Group20:
			return ParaMgr_HCMR_pGoodbyeP1G20ModeLowBri_B;
		case Group21:
			return ParaMgr_HCMR_pGoodbyeP1G21ModeLowBri_B;
		case Group22:
			return ParaMgr_HCMR_pGoodbyeP1G22ModeLowBri_B;
		case Group23:
			return ParaMgr_HCMR_pGoodbyeP1G23ModeLowBri_B;
		case Group24:
			return ParaMgr_HCMR_pGoodbyeP1G24ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pGoodbyeP1OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pGoodbyeP1G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_pGoodbyeP1G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_pGoodbyeP1G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_pGoodbyeP1G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_pGoodbyeP1G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_pGoodbyeP1G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_pGoodbyeP1G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_pGoodbyeP1G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_pGoodbyeP1G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_pGoodbyeP1G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_pGoodbyeP1G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_pGoodbyeP1G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_pGoodbyeP1G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_pGoodbyeP1G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_pGoodbyeP1G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_pGoodbyeP1G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_pGoodbyeP1G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_pGoodbyeP1G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_pGoodbyeP1G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_pGoodbyeP1G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_pGoodbyeP1G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_pGoodbyeP1G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_pGoodbyeP1G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_pGoodbyeP1G24OffTiConTiUpBri_W;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pGoodbyeP1OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_pGoodbyeP1G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_HCMR_pGoodbyeP1G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_HCMR_pGoodbyeP1G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_HCMR_pGoodbyeP1G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_HCMR_pGoodbyeP1G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_HCMR_pGoodbyeP1G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_HCMR_pGoodbyeP1G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_HCMR_pGoodbyeP1G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_HCMR_pGoodbyeP1G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_HCMR_pGoodbyeP1G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_HCMR_pGoodbyeP1G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_HCMR_pGoodbyeP1G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_HCMR_pGoodbyeP1G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_HCMR_pGoodbyeP1G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_HCMR_pGoodbyeP1G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_HCMR_pGoodbyeP1G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_HCMR_pGoodbyeP1G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_HCMR_pGoodbyeP1G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_HCMR_pGoodbyeP1G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_HCMR_pGoodbyeP1G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_HCMR_pGoodbyeP1G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_HCMR_pGoodbyeP1G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_HCMR_pGoodbyeP1G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_HCMR_pGoodbyeP1G24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Goodbye 2*/
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP2ModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_GoodbyeP2G1ModeLowBri_B;
		case Group2:
			return ParaMgr_GoodbyeP2G2ModeLowBri_B;
		case Group3:
			return ParaMgr_GoodbyeP2G3ModeLowBri_B;
		case Group4:
			return ParaMgr_GoodbyeP2G4ModeLowBri_B;
		case Group5:
			return ParaMgr_GoodbyeP2G5ModeLowBri_B;
		case Group6:
			return ParaMgr_GoodbyeP2G6ModeLowBri_B;
		case Group7:
			return ParaMgr_GoodbyeP2G7ModeLowBri_B;
		case Group8:
			return ParaMgr_GoodbyeP2G8ModeLowBri_B;
		case Group9:
			return ParaMgr_GoodbyeP2G9ModeLowBri_B;
		case Group10:
			return ParaMgr_GoodbyeP2G10ModeLowBri_B;
		case Group11:
			return ParaMgr_GoodbyeP2G11ModeLowBri_B;
		case Group12:
			return ParaMgr_GoodbyeP2G12ModeLowBri_B;
		case Group13:
			return ParaMgr_GoodbyeP2G13ModeLowBri_B;
		case Group14:
			return ParaMgr_GoodbyeP2G14ModeLowBri_B;
		case Group15:
			return ParaMgr_GoodbyeP2G15ModeLowBri_B;
		case Group16:
			return ParaMgr_GoodbyeP2G16ModeLowBri_B;
		case Group17:
			return ParaMgr_GoodbyeP2G17ModeLowBri_B;
		case Group18:
			return ParaMgr_GoodbyeP2G18ModeLowBri_B;
		case Group19:
			return ParaMgr_GoodbyeP2G19ModeLowBri_B;
		case Group20:
			return ParaMgr_GoodbyeP2G20ModeLowBri_B;
		case Group21:
			return ParaMgr_GoodbyeP2G21ModeLowBri_B;
		case Group22:
			return ParaMgr_GoodbyeP2G22ModeLowBri_B;
		case Group23:
			return ParaMgr_GoodbyeP2G23ModeLowBri_B;
		case Group24:
			return ParaMgr_GoodbyeP2G24ModeLowBri_B;
	}
    return NULL;
}

const uint8 *Get_Dynamic_Light_Function_pGoodbyeP2ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_GoodbyeP2G1ModeLowBri_B;
		case Group2:
			return ParaMgr_HCMR_GoodbyeP2G2ModeLowBri_B;
		case Group3:
			return ParaMgr_HCMR_GoodbyeP2G3ModeLowBri_B;
		case Group4:
			return ParaMgr_HCMR_GoodbyeP2G4ModeLowBri_B;
		case Group5:
			return ParaMgr_HCMR_GoodbyeP2G5ModeLowBri_B;
		case Group6:
			return ParaMgr_HCMR_GoodbyeP2G6ModeLowBri_B;
		case Group7:
			return ParaMgr_HCMR_GoodbyeP2G7ModeLowBri_B;
		case Group8:
			return ParaMgr_HCMR_GoodbyeP2G8ModeLowBri_B;
		case Group9:
			return ParaMgr_HCMR_GoodbyeP2G9ModeLowBri_B;
		case Group10:
			return ParaMgr_HCMR_GoodbyeP2G10ModeLowBri_B;
		case Group11:
			return ParaMgr_HCMR_GoodbyeP2G11ModeLowBri_B;
		case Group12:
			return ParaMgr_HCMR_GoodbyeP2G12ModeLowBri_B;
		case Group13:
			return ParaMgr_HCMR_GoodbyeP2G13ModeLowBri_B;
		case Group14:
			return ParaMgr_HCMR_GoodbyeP2G14ModeLowBri_B;
		case Group15:
			return ParaMgr_HCMR_GoodbyeP2G15ModeLowBri_B;
		case Group16:
			return ParaMgr_HCMR_GoodbyeP2G16ModeLowBri_B;
		case Group17:
			return ParaMgr_HCMR_GoodbyeP2G17ModeLowBri_B;
		case Group18:
			return ParaMgr_HCMR_GoodbyeP2G18ModeLowBri_B;
		case Group19:
			return ParaMgr_HCMR_GoodbyeP2G19ModeLowBri_B;
		case Group20:
			return ParaMgr_HCMR_GoodbyeP2G20ModeLowBri_B;
		case Group21:
			return ParaMgr_HCMR_GoodbyeP2G21ModeLowBri_B;
		case Group22:
			return ParaMgr_HCMR_GoodbyeP2G22ModeLowBri_B;
		case Group23:
			return ParaMgr_HCMR_GoodbyeP2G23ModeLowBri_B;
		case Group24:
			return ParaMgr_HCMR_GoodbyeP2G24ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pGoodbyeP2OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_GoodbyeP2G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_GoodbyeP2G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_GoodbyeP2G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_GoodbyeP2G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_GoodbyeP2G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_GoodbyeP2G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_GoodbyeP2G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_GoodbyeP2G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_GoodbyeP2G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_GoodbyeP2G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_GoodbyeP2G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_GoodbyeP2G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_GoodbyeP2G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_GoodbyeP2G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_GoodbyeP2G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_GoodbyeP2G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_GoodbyeP2G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_GoodbyeP2G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_GoodbyeP2G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_GoodbyeP2G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_GoodbyeP2G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_GoodbyeP2G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_GoodbyeP2G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_GoodbyeP2G24OffTiConTiUpBri_W;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pGoodbyeP2OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_HCMR_GoodbyeP2G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_HCMR_GoodbyeP2G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_HCMR_GoodbyeP2G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_HCMR_GoodbyeP2G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_HCMR_GoodbyeP2G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_HCMR_GoodbyeP2G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_HCMR_GoodbyeP2G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_HCMR_GoodbyeP2G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_HCMR_GoodbyeP2G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_HCMR_GoodbyeP2G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_HCMR_GoodbyeP2G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_HCMR_GoodbyeP2G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_HCMR_GoodbyeP2G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_HCMR_GoodbyeP2G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_HCMR_GoodbyeP2G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_HCMR_GoodbyeP2G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_HCMR_GoodbyeP2G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_HCMR_GoodbyeP2G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_HCMR_GoodbyeP2G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_HCMR_GoodbyeP2G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_HCMR_GoodbyeP2G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_HCMR_GoodbyeP2G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_HCMR_GoodbyeP2G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_HCMR_GoodbyeP2G24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Goodbye 3*/
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP3ModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_GoodbyeP3G1ModeLowBri_B;
		case Group2:
			return ParaMgr_GoodbyeP3G2ModeLowBri_B;
		case Group3:
			return ParaMgr_GoodbyeP3G3ModeLowBri_B;
		case Group4:
			return ParaMgr_GoodbyeP3G4ModeLowBri_B;
		case Group5:
			return ParaMgr_GoodbyeP3G5ModeLowBri_B;
		case Group6:
			return ParaMgr_GoodbyeP3G6ModeLowBri_B;
		case Group7:
			return ParaMgr_GoodbyeP3G7ModeLowBri_B;
		case Group8:
			return ParaMgr_GoodbyeP3G8ModeLowBri_B;
		case Group9:
			return ParaMgr_GoodbyeP3G9ModeLowBri_B;
		case Group10:
			return ParaMgr_GoodbyeP3G10ModeLowBri_B;
		case Group11:
			return ParaMgr_GoodbyeP3G11ModeLowBri_B;
		case Group12:
			return ParaMgr_GoodbyeP3G12ModeLowBri_B;
		case Group13:
			return ParaMgr_GoodbyeP3G13ModeLowBri_B;
		case Group14:
			return ParaMgr_GoodbyeP3G14ModeLowBri_B;
		case Group15:
			return ParaMgr_GoodbyeP3G15ModeLowBri_B;
		case Group16:
			return ParaMgr_GoodbyeP3G16ModeLowBri_B;
		case Group17:
			return ParaMgr_GoodbyeP3G17ModeLowBri_B;
		case Group18:
			return ParaMgr_GoodbyeP3G18ModeLowBri_B;
		case Group19:
			return ParaMgr_GoodbyeP3G19ModeLowBri_B;
		case Group20:
			return ParaMgr_GoodbyeP3G20ModeLowBri_B;
		case Group21:
			return ParaMgr_GoodbyeP3G21ModeLowBri_B;
		case Group22:
			return ParaMgr_GoodbyeP3G22ModeLowBri_B;
		case Group23:
			return ParaMgr_GoodbyeP3G23ModeLowBri_B;
		case Group24:
			return ParaMgr_GoodbyeP3G24ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pGoodbyeP3OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_GoodbyeP3G1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_GoodbyeP3G2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_GoodbyeP3G3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_GoodbyeP3G4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_GoodbyeP3G5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_GoodbyeP3G6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_GoodbyeP3G7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_GoodbyeP3G8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_GoodbyeP3G9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_GoodbyeP3G10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_GoodbyeP3G11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_GoodbyeP3G12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_GoodbyeP3G13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_GoodbyeP3G14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_GoodbyeP3G15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_GoodbyeP3G16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_GoodbyeP3G17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_GoodbyeP3G18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_GoodbyeP3G19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_GoodbyeP3G20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_GoodbyeP3G21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_GoodbyeP3G22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_GoodbyeP3G23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_GoodbyeP3G24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Waitmode*/
const uint8 *Get_Dynamic_Light_Function_pWaitModeModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_WaitmodeP1G1ModeLowBri_B;
			break;
		case Group2:
			return ParaMgr_WaitmodeP1G2ModeLowBri_B;
			break;
		case Group3:
			return ParaMgr_WaitmodeP1G3ModeLowBri_B;
			break;
		case Group4:
			return ParaMgr_WaitmodeP1G4ModeLowBri_B;
			break;
		case Group5:
			return ParaMgr_WaitmodeP1G5ModeLowBri_B;
			break;
		case Group6:
			return ParaMgr_WaitmodeP1G6ModeLowBri_B;
			break;
		case Group7:
			return ParaMgr_WaitmodeP1G7ModeLowBri_B;
			break;
		case Group8:
			return ParaMgr_WaitmodeP1G8ModeLowBri_B;
			break;
		case Group9:
			return ParaMgr_WaitmodeP1G9ModeLowBri_B;
			break;
		case Group10:
			return ParaMgr_WaitmodeP1G10ModeLowBri_B;
			break;
		case Group11:
			return ParaMgr_WaitmodeP1G11ModeLowBri_B;
			break;
		case Group12:
			return ParaMgr_WaitmodeP1G12ModeLowBri_B;
			break;
		case Group13:
			return ParaMgr_WaitmodeP1G13ModeLowBri_B;
			break;
		case Group14:
			return ParaMgr_WaitmodeP1G14ModeLowBri_B;
			break;
		case Group15:
			return ParaMgr_WaitmodeP1G15ModeLowBri_B;
			break;
		case Group16:
			return ParaMgr_WaitmodeP1G16ModeLowBri_B;
			break;
		case Group17:
			return ParaMgr_WaitmodeP1G17ModeLowBri_B;
			break;
		case Group18:
			return ParaMgr_WaitmodeP1G18ModeLowBri_B;
			break;
		case Group19:
			return ParaMgr_WaitmodeP1G19ModeLowBri_B;
			break;
		case Group20:
			return ParaMgr_WaitmodeP1G20ModeLowBri_B;
			break;
		case Group21:
			return ParaMgr_WaitmodeP1G21ModeLowBri_B;
			break;
		case Group22:
			return ParaMgr_WaitmodeP1G22ModeLowBri_B;
			break;
		case Group23:
			return ParaMgr_WaitmodeP1G23ModeLowBri_B;
			break;
		case Group24:
			return ParaMgr_WaitmodeP1G24ModeLowBri_B;
			break;
	}

}

const uint16 *Get_Dynamic_Light_Function_pWaitModeOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_WaitmodeP1G1OffTiConTiUpBri_W;
			break;
		case Group2:
			return ParaMgr_WaitmodeP1G2OffTiConTiUpBri_W;
			break;
		case Group3:
			return ParaMgr_WaitmodeP1G3OffTiConTiUpBri_W;
			break;
		case Group4:
			return ParaMgr_WaitmodeP1G4OffTiConTiUpBri_W;
			break;
		case Group5:
			return ParaMgr_WaitmodeP1G5OffTiConTiUpBri_W;
			break;
		case Group6:
			return ParaMgr_WaitmodeP1G6OffTiConTiUpBri_W;
			break;
		case Group7:
			return ParaMgr_WaitmodeP1G7OffTiConTiUpBri_W;
			break;
		case Group8:
			return ParaMgr_WaitmodeP1G8OffTiConTiUpBri_W;
			break;
		case Group9:
			return ParaMgr_WaitmodeP1G9OffTiConTiUpBri_W;
			break;
		case Group10:
			return ParaMgr_WaitmodeP1G10OffTiConTiUpBri_W;
			break;
		case Group11:
			return ParaMgr_WaitmodeP1G11OffTiConTiUpBri_W;
			break;
		case Group12:
			return ParaMgr_WaitmodeP1G12OffTiConTiUpBri_W;
			break;
		case Group13:
			return ParaMgr_WaitmodeP1G13OffTiConTiUpBri_W;
			break;
		case Group14:
			return ParaMgr_WaitmodeP1G14OffTiConTiUpBri_W;
			break;
		case Group15:
			return ParaMgr_WaitmodeP1G15OffTiConTiUpBri_W;
			break;
		case Group16:
			return ParaMgr_WaitmodeP1G16OffTiConTiUpBri_W;
			break;
		case Group17:
			return ParaMgr_WaitmodeP1G17OffTiConTiUpBri_W;
			break;
		case Group18:
			return ParaMgr_WaitmodeP1G18OffTiConTiUpBri_W;
			break;
		case Group19:
			return ParaMgr_WaitmodeP1G19OffTiConTiUpBri_W;
			break;
		case Group20:
			return ParaMgr_WaitmodeP1G20OffTiConTiUpBri_W;
			break;
		case Group21:
			return ParaMgr_WaitmodeP1G21OffTiConTiUpBri_W;
			break;
		case Group22:
			return ParaMgr_WaitmodeP1G22OffTiConTiUpBri_W;
			break;
		case Group23:
			return ParaMgr_WaitmodeP1G23OffTiConTiUpBri_W;
			break;
		case Group24:
			return ParaMgr_WaitmodeP1G24OffTiConTiUpBri_W;
			break;
	}

}

/*Car Approach Pattern*/
uint8 Get_Dynamic_Light_Function_pCarAppMotorEN_B(void)
{
	return ParaMgr_pCarAppMotorEn_B;
}

uint16 Get_Dynamic_Light_Function_pCarAppLevMotorTime_W(void)
{
	return ParaMgr_pCarAppLevMotorTime_W;
}

uint16 Get_Dynamic_Light_Function_pCarAppSwivMotorTime_W(void)
{
	return ParaMgr_pCarAppSwivMotorTime_W;
}

uint16 Get_Dynamic_Light_Function_pLedApprLightDimOnTi_W(void)
{
	return ParaMgr_pLedApprLightDimOnTi_W;
}

/*Car Approach*/
const uint8 *Get_Dynamic_Light_Function_pApproachModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pApproachG1ModeLowBri_B;
		case Group2:
			return ParaMgr_pApproachG2ModeLowBri_B;
		case Group3:
			return ParaMgr_pApproachG3ModeLowBri_B;
		case Group4:
			return ParaMgr_pApproachG4ModeLowBri_B;
		case Group5:
			return ParaMgr_pApproachG5ModeLowBri_B;
		case Group6:
			return ParaMgr_pApproachG6ModeLowBri_B;
		case Group7:
			return ParaMgr_pApproachG7ModeLowBri_B;
		case Group8:
			return ParaMgr_pApproachG8ModeLowBri_B;
		case Group9:
			return ParaMgr_pApproachG9ModeLowBri_B;
		case Group10:
			return ParaMgr_pApproachG10ModeLowBri_B;
		case Group11:
			return ParaMgr_pApproachG11ModeLowBri_B;
		case Group12:
			return ParaMgr_pApproachG12ModeLowBri_B;
		case Group13:
			return ParaMgr_pApproachG13ModeLowBri_B;
		case Group14:
			return ParaMgr_pApproachG14ModeLowBri_B;
		case Group15:
			return ParaMgr_pApproachG15ModeLowBri_B;
		case Group16:
			return ParaMgr_pApproachG16ModeLowBri_B;
		case Group17:
			return ParaMgr_pApproachG17ModeLowBri_B;
		case Group18:
			return ParaMgr_pApproachG18ModeLowBri_B;
		case Group19:
			return ParaMgr_pApproachG19ModeLowBri_B;
		case Group20:
			return ParaMgr_pApproachG20ModeLowBri_B;
		case Group21:
			return ParaMgr_pApproachG21ModeLowBri_B;
		case Group22:
			return ParaMgr_pApproachG22ModeLowBri_B;
		case Group23:
			return ParaMgr_pApproachG23ModeLowBri_B;
		case Group24:
			return ParaMgr_pApproachG24ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pApproachOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pApproachG1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_pApproachG2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_pApproachG3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_pApproachG4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_pApproachG5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_pApproachG6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_pApproachG7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_pApproachG8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_pApproachG9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_pApproachG10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_pApproachG11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_pApproachG12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_pApproachG13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_pApproachG14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_pApproachG15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_pApproachG16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_pApproachG17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_pApproachG18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_pApproachG19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_pApproachG20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_pApproachG21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_pApproachG22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_pApproachG23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_pApproachG24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*HomeSafety*/
const uint8 *Get_Dynamic_Light_Function_pHomeSafetyModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pHomeSafetyG1ModeLowBri_B;
		case Group2:
			return ParaMgr_pHomeSafetyG2ModeLowBri_B;
		case Group3:
			return ParaMgr_pHomeSafetyG3ModeLowBri_B;
		case Group4:
			return ParaMgr_pHomeSafetyG4ModeLowBri_B;
		case Group5:
			return ParaMgr_pHomeSafetyG5ModeLowBri_B;
		case Group6:
			return ParaMgr_pHomeSafetyG6ModeLowBri_B;
		case Group7:
			return ParaMgr_pHomeSafetyG7ModeLowBri_B;
		case Group8:
			return ParaMgr_pHomeSafetyG8ModeLowBri_B;
		case Group9:
			return ParaMgr_pHomeSafetyG9ModeLowBri_B;
		case Group10:
			return ParaMgr_pHomeSafetyG10ModeLowBri_B;
		case Group11:
			return ParaMgr_pHomeSafetyG11ModeLowBri_B;
		case Group12:
			return ParaMgr_pHomeSafetyG12ModeLowBri_B;
		case Group13:
			return ParaMgr_pHomeSafetyG13ModeLowBri_B;
		case Group14:
			return ParaMgr_pHomeSafetyG14ModeLowBri_B;
		case Group15:
			return ParaMgr_pHomeSafetyG15ModeLowBri_B;
		case Group16:
			return ParaMgr_pHomeSafetyG16ModeLowBri_B;
		case Group17:
			return ParaMgr_pHomeSafetyG17ModeLowBri_B;
		case Group18:
			return ParaMgr_pHomeSafetyG18ModeLowBri_B;
		case Group19:
			return ParaMgr_pHomeSafetyG19ModeLowBri_B;
		case Group20:
			return ParaMgr_pHomeSafetyG20ModeLowBri_B;
		case Group21:
			return ParaMgr_pHomeSafetyG21ModeLowBri_B;
		case Group22:
			return ParaMgr_pHomeSafetyG22ModeLowBri_B;
		case Group23:
			return ParaMgr_pHomeSafetyG23ModeLowBri_B;
		case Group24:
			return ParaMgr_pHomeSafetyG24ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pHomeSafetyOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pHomeSafetyG1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_pHomeSafetyG2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_pHomeSafetyG3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_pHomeSafetyG4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_pHomeSafetyG5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_pHomeSafetyG6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_pHomeSafetyG7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_pHomeSafetyG8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_pHomeSafetyG9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_pHomeSafetyG10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_pHomeSafetyG11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_pHomeSafetyG12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_pHomeSafetyG13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_pHomeSafetyG14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_pHomeSafetyG15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_pHomeSafetyG16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_pHomeSafetyG17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_pHomeSafetyG18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_pHomeSafetyG19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_pHomeSafetyG20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_pHomeSafetyG21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_pHomeSafetyG22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_pHomeSafetyG23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_pHomeSafetyG24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Car Locator*/
const uint8 *Get_Dynamic_Light_Function_pLocatorModeLowBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pLocatorG1ModeLowBri_B;
		case Group2:
			return ParaMgr_pLocatorG2ModeLowBri_B;
		case Group3:
			return ParaMgr_pLocatorG3ModeLowBri_B;
		case Group4:
			return ParaMgr_pLocatorG4ModeLowBri_B;
		case Group5:
			return ParaMgr_pLocatorG5ModeLowBri_B;
		case Group6:
			return ParaMgr_pLocatorG6ModeLowBri_B;
		case Group7:
			return ParaMgr_pLocatorG7ModeLowBri_B;
		case Group8:
			return ParaMgr_pLocatorG8ModeLowBri_B;
		case Group9:
			return ParaMgr_pLocatorG9ModeLowBri_B;
		case Group10:
			return ParaMgr_pLocatorG10ModeLowBri_B;
		case Group11:
			return ParaMgr_pLocatorG11ModeLowBri_B;
		case Group12:
			return ParaMgr_pLocatorG12ModeLowBri_B;
		case Group13:
			return ParaMgr_pLocatorG13ModeLowBri_B;
		case Group14:
			return ParaMgr_pLocatorG14ModeLowBri_B;
		case Group15:
			return ParaMgr_pLocatorG15ModeLowBri_B;
		case Group16:
			return ParaMgr_pLocatorG16ModeLowBri_B;
		case Group17:
			return ParaMgr_pLocatorG17ModeLowBri_B;
		case Group18:
			return ParaMgr_pLocatorG18ModeLowBri_B;
		case Group19:
			return ParaMgr_pLocatorG19ModeLowBri_B;
		case Group20:
			return ParaMgr_pLocatorG20ModeLowBri_B;
		case Group21:
			return ParaMgr_pLocatorG21ModeLowBri_B;
		case Group22:
			return ParaMgr_pLocatorG22ModeLowBri_B;
		case Group23:
			return ParaMgr_pLocatorG23ModeLowBri_B;
		case Group24:
			return ParaMgr_pLocatorG24ModeLowBri_B;
	}
    return NULL;
}

const uint16 *Get_Dynamic_Light_Function_pLocatorOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO)
{
	switch(Group_NO)
	{
		case Group1:
			return ParaMgr_pLocatorG1OffTiConTiUpBri_W;
		case Group2:
			return ParaMgr_pLocatorG2OffTiConTiUpBri_W;
		case Group3:
			return ParaMgr_pLocatorG3OffTiConTiUpBri_W;
		case Group4:
			return ParaMgr_pLocatorG4OffTiConTiUpBri_W;
		case Group5:
			return ParaMgr_pLocatorG5OffTiConTiUpBri_W;
		case Group6:
			return ParaMgr_pLocatorG6OffTiConTiUpBri_W;
		case Group7:
			return ParaMgr_pLocatorG7OffTiConTiUpBri_W;
		case Group8:
			return ParaMgr_pLocatorG8OffTiConTiUpBri_W;
		case Group9:
			return ParaMgr_pLocatorG9OffTiConTiUpBri_W;
		case Group10:
			return ParaMgr_pLocatorG10OffTiConTiUpBri_W;
		case Group11:
			return ParaMgr_pLocatorG11OffTiConTiUpBri_W;
		case Group12:
			return ParaMgr_pLocatorG12OffTiConTiUpBri_W;
		case Group13:
			return ParaMgr_pLocatorG13OffTiConTiUpBri_W;
		case Group14:
			return ParaMgr_pLocatorG14OffTiConTiUpBri_W;
		case Group15:
			return ParaMgr_pLocatorG15OffTiConTiUpBri_W;
		case Group16:
			return ParaMgr_pLocatorG16OffTiConTiUpBri_W;
		case Group17:
			return ParaMgr_pLocatorG17OffTiConTiUpBri_W;
		case Group18:
			return ParaMgr_pLocatorG18OffTiConTiUpBri_W;
		case Group19:
			return ParaMgr_pLocatorG19OffTiConTiUpBri_W;
		case Group20:
			return ParaMgr_pLocatorG20OffTiConTiUpBri_W;
		case Group21:
			return ParaMgr_pLocatorG21OffTiConTiUpBri_W;
		case Group22:
			return ParaMgr_pLocatorG22OffTiConTiUpBri_W;
		case Group23:
			return ParaMgr_pLocatorG23OffTiConTiUpBri_W;
		case Group24:
			return ParaMgr_pLocatorG24OffTiConTiUpBri_W;
	}
    return NULL;
}

/*Light Show*/
const uint32 Get_Dynamic_Light_Function_ParaMgr_pELCTimeout_DW(void)
{
	return ParaMgr_pELCTimeout_DW;
}



