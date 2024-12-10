/*
 * AdcDev_Interface.c
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AdcDrv.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_ADC_Dev* g_S_ADC_Dev_Header=NULL;

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
static S_ADC_Dev* GetAdcDevByAdcFunction(E_AdcFunction AdcFunction)
{
	S_ADC_Dev* tmp=g_S_ADC_Dev_Header;

	while (tmp!=NULL)
	{
		if(tmp->AdcFunction == AdcFunction)
			return tmp;

		tmp=tmp->ptNext;
	}

	return NULL;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

Std_ReturnType Interface_GetAdcDigitalValue(E_AdcFunction AdcFunction,uint32* DigitalValue)
{
	S_ADC_Dev* tmp=NULL;
	S_DigitalValueDataSrc DigitalValueDataSrc;
	S_AdcDevDataPackets AdcDevDataPackets;

	tmp=GetAdcDevByAdcFunction(AdcFunction);

	if(tmp == NULL)
		return E_NOT_OK;

	DigitalValueDataSrc.AdcFunction=AdcFunction;
	DigitalValueDataSrc.AdcDigitalValue=0;

	AdcDevDataPackets.AdcDevDataType=E_AdcDevDataType_DigitalValue;
	AdcDevDataPackets.datasrc=(void *)(&DigitalValueDataSrc);

	if(tmp->Read((void *)(&AdcDevDataPackets)) == E_OK)
	{
		*DigitalValue=DigitalValueDataSrc.AdcDigitalValue;

		return E_OK;
	}

	return E_NOT_OK;
}

Std_ReturnType AdcDev_Interface_Mainfunction(uint8_t timebase)
{
	CddDriver_AdcMainfunction();
}
Std_ReturnType AdcDev_Register(S_ADC_Dev* Drv_Dev)
{
	S_ADC_Dev* tmp=g_S_ADC_Dev_Header;

	if(g_S_ADC_Dev_Header==NULL)
	{
		g_S_ADC_Dev_Header=Drv_Dev;
		g_S_ADC_Dev_Header->ptNext=NULL;
	}else
	{
		while(tmp->ptNext!=NULL)
			tmp=tmp->ptNext;
		tmp->ptNext=Drv_Dev;
		Drv_Dev->ptNext=NULL;
	}
	return E_OK;
}
