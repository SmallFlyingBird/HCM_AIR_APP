/*
 * AdcDrv.c
 *
 *  Created on: 2024��2��19��
 *      Author: mihuiliang
 */



/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AdcDrv.h"
#include "HcmPlatform.h"
#include "Adc.h"
#include "Adc_Cfg.h"
#include "Adc_Types.h"
#include "SafetyDrv.h"


/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static Std_ReturnType AdcDrv_Write(void *ptr);
static Std_ReturnType AdcDrv_Read(void *ptr);


static uint16_t AdcConvertBuffer[MAX_ADC_DRV_NUM];

static S_ADC_Dev gs_ADC_Dev[MAX_ADC_DRV_NUM]={
		{.AdcFunction=E_AdcFunction_NTC1,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_NTC2,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_NTC3,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_NTC4,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_NTC5,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_NTC6,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_KL15,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_KL56,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_NTC7,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_DcCtr,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_HSD1FB,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_HSD2FB,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_5vDet,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_HallIn,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},
		{.AdcFunction=E_AdcFunction_FanCtr,.AdcAccuracy=E_AdcAccuracy_Bit12,.Write=AdcDrv_Write,.Read=AdcDrv_Read,.ptNext=NULL},

};

static S_ADCDrvInfo ADCDrvInfoConfig[MAX_ADC_DRV_NUM]={
		{.AdcFunction=E_AdcFunction_NTC1,			.BufferIndex=5,},
		{.AdcFunction=E_AdcFunction_NTC2,			.BufferIndex=6,},
		{.AdcFunction=E_AdcFunction_NTC3,			.BufferIndex=7,},
		{.AdcFunction=E_AdcFunction_NTC4,			.BufferIndex=10,},
		{.AdcFunction=E_AdcFunction_NTC5,			.BufferIndex=8,},
		{.AdcFunction=E_AdcFunction_NTC6,			.BufferIndex=9,},
		{.AdcFunction=E_AdcFunction_DcCtr,			.BufferIndex=1,},
		{.AdcFunction=E_AdcFunction_FanCtr,			.BufferIndex=2,},
		{.AdcFunction=E_AdcFunction_HSD1FB,			.BufferIndex=4,},
		{.AdcFunction=E_AdcFunction_5vDet,			.BufferIndex=0,},
		{.AdcFunction=E_AdcFunction_HallIn,			.BufferIndex=3,},
		{.AdcFunction=E_AdcFunction_HSD2FB,			.BufferIndex=12,},
		{.AdcFunction=E_AdcFunction_KL15,			.BufferIndex=13,},
		{.AdcFunction=E_AdcFunction_KL56,			.BufferIndex=14,},
		{.AdcFunction=E_AdcFunction_NTC7,			.BufferIndex=15,},		
};
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
static S_ADC_Dev* Get_ADC_Dev(E_AdcFunction AdcFunction)
{
	uint8_t i=0;

	for(i=0;i<MAX_ADC_DRV_NUM;i++)
	{
		if(gs_ADC_Dev[i].AdcFunction == AdcFunction)
			return &gs_ADC_Dev[i];
	}

	return NULL;
}

static S_ADCDrvInfo* Get_ADCDrvInfo(E_AdcFunction AdcFunction)
{
	uint8_t i=0;

	for(i=0;i<MAX_ADC_DRV_NUM;i++)
	{
		if(ADCDrvInfoConfig[i].AdcFunction == AdcFunction)
			return &ADCDrvInfoConfig[i];
	}

	return NULL;
}

static Std_ReturnType Get_AdcDigitalValue(S_DigitalValueDataSrc *DigitalValueDataSrc)
{
	Std_ReturnType rtval=E_OK;

	S_ADCDrvInfo* pttmp=NULL;

	pttmp=Get_ADCDrvInfo(DigitalValueDataSrc->AdcFunction);

	if(pttmp == NULL)
		return E_NOT_OK;

	if(pttmp->BufferIndex >= MAX_ADC_DRV_NUM)
		return E_NOT_OK; /*overflow*/

	if(AdcConvertBuffer[pttmp->BufferIndex]==0xFFFFFFFF)
	{
		/*Adc convert not complete*/
		return E_NOT_OK;
	}
	else
	{
		DigitalValueDataSrc->AdcDigitalValue=AdcConvertBuffer[pttmp->BufferIndex];
	}

	return rtval;
}

static Std_ReturnType AdcDrv_Write(void *ptr)
{
	Std_ReturnType rtval=E_OK;

	return rtval;
}
static Std_ReturnType AdcDrv_Read(void *ptr)
{
	Std_ReturnType rtval=E_OK;
	S_AdcDevDataPackets *AdcDevDataPackets;

	AdcDevDataPackets=(S_AdcDevDataPackets *)ptr;

	switch(AdcDevDataPackets->AdcDevDataType)
	{
		case E_AdcDevDataType_DigitalValue:
			rtval|=Get_AdcDigitalValue((S_DigitalValueDataSrc*)(AdcDevDataPackets->datasrc));
		break;
	}

	return rtval;
}

static void AdcDrv_StartGroupConversion(void) 
{
	uint16_t AdcConverTimeoutADC0_Group_0, AdcConverTimeoutADC0_Group_1, AdcConverTimeoutADC1_Group_0;
	AdcConverTimeoutADC0_Group_0 = AdcConverTimeoutADC0_Group_1 = AdcConverTimeoutADC1_Group_0 = 0x1fff;

	Safety_TdgOutputCheckStart(AdcConf_AdcGroup_Adc0_Group_0);
	Adc_StartGroupConversion(AdcConf_AdcGroup_Adc0_Group_0);
	while ((Adc_GetGroupStatus(AdcConf_AdcGroup_Adc0_Group_0) != ADC_STREAM_COMPLETED) && (AdcConverTimeoutADC0_Group_0 != 0)) {
		AdcConverTimeoutADC0_Group_0--;
	}

	Safety_TdgOutputCheckStart(AdcConf_AdcGroup_Adc0_Group_1);
	Adc_StartGroupConversion(AdcConf_AdcGroup_Adc0_Group_1);
	while ((Adc_GetGroupStatus(AdcConf_AdcGroup_Adc0_Group_1) != ADC_STREAM_COMPLETED) && (AdcConverTimeoutADC0_Group_1 != 0)) {
		AdcConverTimeoutADC0_Group_1--;
	}

	Safety_TdgOutputCheckStart(AdcConf_AdcGroup_Adc1_Group_0);
	Adc_StartGroupConversion(AdcConf_AdcGroup_Adc1_Group_0);
    while ((Adc_GetGroupStatus(AdcConf_AdcGroup_Adc1_Group_0) != ADC_STREAM_COMPLETED) && (AdcConverTimeoutADC1_Group_0 != 0)) {
		AdcConverTimeoutADC1_Group_0--;
	}

	if (AdcConverTimeoutADC0_Group_0 == 0 || AdcConverTimeoutADC0_Group_1 == 0 || AdcConverTimeoutADC1_Group_0 ==0)
	{
		Safety_SetTestRes(SAFETY_ADC_TIMEOUT, SAFETY_ERROR);
	} else {
		Safety_SetTestRes(SAFETY_ADC_TIMEOUT, SAFETY_NORMAL);
	}
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

Std_ReturnType CddDriver_GetAdcRes(uint8_t indx, uint16* DigitalValue)
{
	if(indx >= MAX_ADC_DRV_NUM){
		return E_NOT_OK;
	}
	
	*DigitalValue = AdcConvertBuffer[indx];
	return E_OK;
}

Std_ReturnType CddDriver_AdcDrvInit(void)
{
	Std_ReturnType rtval=E_OK;
	uint8_t i=0;

	for(i=0;i<MAX_ADC_DRV_NUM;i++)
	{
		rtval|=AdcDev_Register(&gs_ADC_Dev[i]);
		AdcConvertBuffer[i]=0xFFFFFFFF;
	}
#if (ADC_CALIBRATION == STD_ON)
    Adc_Calibrate(0);
    Adc_Calibrate(1);
#endif
    Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc0_Group_0,&AdcConvertBuffer[0]);
	Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc0_Group_1,&AdcConvertBuffer[ADC0_GROUP0_NUM]);
	Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc1_Group_0,&AdcConvertBuffer[(ADC0_GROUP0_NUM+ADC0_GROUP1_NUM)]);
    Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc0_Group_0);
    Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc0_Group_1);
    Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc1_Group_0);

	AdcDrv_StartGroupConversion();

	return rtval;
}

void CddDriver_AdcMainfunction(void){
	AdcDrv_StartGroupConversion();
}