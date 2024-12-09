/*
 * AdcDev_Interface.h
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_ADC_INTERFACE_ADCDEV_INTERFACE_H_
#define ASW_INTERFACE_ADC_INTERFACE_ADCDEV_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
/*�汾�� 0.0.0*/
#define ADCDEV_INTERFACE_VERSION_HIGH_BYTE 		0
#define ADCDEV_INTERFACE_VERSION_MIDDLE_BYTE 	0
#define ADCDEV_INTERFACE_VERSION_LOW_BYTE 		0

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum{
	E_AdcFunction_NTC1=0,
	E_AdcFunction_NTC2,
	E_AdcFunction_NTC3,
	E_AdcFunction_NTC4,
	E_AdcFunction_NTC5,
	E_AdcFunction_NTC6,

	E_AdcFunction_HSD1FB,
	E_AdcFunction_DcCtr,
	E_AdcFunction_BoostOut,
	E_AdcFunction_NTC7,
	E_AdcFunction_LeftRightSide,
	E_AdcFunction_HSD2FB,

	E_AdcFunction_KL56,
	// E_AdcFunction_KL15,
	E_AdcFunction_5vDet,
	E_AdcFunction_HallIn,
	E_AdcFunction_FanCtr,
	
}E_AdcFunction;

typedef enum{
	E_AdcAccuracy_Bit12,
}E_AdcAccuracy;

typedef enum{
	E_AdcDevDataType_DigitalValue=0,
}E_AdcDevDataType;

typedef struct DigitalValueAdcDataSrc{
	E_AdcFunction AdcFunction;
	uint32_t AdcDigitalValue;										/*����ֵ*/
}S_DigitalValueDataSrc;

typedef struct AdcDevDataPackets{
	E_AdcDevDataType AdcDevDataType;
	void * datasrc;
}S_AdcDevDataPackets;

typedef struct ADC_Dev{
	E_AdcFunction AdcFunction;
	E_AdcAccuracy AdcAccuracy;
	Std_ReturnType (*Write)(void *ptr);
	Std_ReturnType (*Read)(void *ptr);
	struct ADC_Dev *ptNext;
}S_ADC_Dev;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_GetAdcAccuracy(E_AdcFunction AdcFunction,E_AdcAccuracy* AdcAccuracy);
Std_ReturnType Interface_GetAdcDigitalValue(E_AdcFunction AdcFunction,uint32* DigitalValue);
Std_ReturnType AdcDev_Interface_Mainfunction(uint8_t timebase);
Std_ReturnType AdcDev_Register(S_ADC_Dev* Drv_Dev);

#endif /* ASW_INTERFACE_ADC_INTERFACE_ADCDEV_INTERFACE_H_ */
