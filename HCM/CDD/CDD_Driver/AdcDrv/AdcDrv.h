/*
 * AdcDrv.h
 *
 *  Created on: 2024��2��19��
 *      Author: mihuiliang
 */

#ifndef CDD_DRIVER_ADCDRV_ADCDRV_H_
#define CDD_DRIVER_ADCDRV_ADCDRV_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AdcDev_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define ADC0_GROUP0_NUM 6
#define ADC0_GROUP1_NUM 6
#define ADC1_GROUP0_NUM 6

#define MAX_ADC_DRV_NUM 18

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef struct ADCDrvInfo{
	E_AdcFunction AdcFunction;
	uint8_t BufferIndex;
}S_ADCDrvInfo;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType CddDriver_AdcDrvInit(void);
void CddDriver_AdcMainfunction(void);
Std_ReturnType CddDriver_GetAdcRes(uint8_t indx, uint16* DigitalValue);
Std_ReturnType Adc_LDOStatusRead(void);
void CddDriver_SetGroup2SimulationValue(uint32_t value);
uint32_t CddDriver_GetGroup2SimulationValue(void);
#endif /* CDD_DRIVER_ADCDRV_ADCDRV_H_ */
