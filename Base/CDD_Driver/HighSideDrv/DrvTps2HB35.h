/*
 * DrvTps2HB35.h
 *
 *  Created on: 2024��2��21��
 *      Author: mihuiliang
 */

#ifndef CDD_DRIVER_HIGHSIDEDRV_DRVTPS2HB35_H_
#define CDD_DRIVER_HIGHSIDEDRV_DRVTPS2HB35_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "AdcDev_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define MAX_HSDDRV_NUM 1
#define HSD_CHANNEL_SIZE 2
#define ADC_BUFFER_SIZE 5


#define HSCHANNEL_SHORT2GND_VAL_12ADBIT	    			3276

#define HSCHANNEL_OVERCURRENT_VAL_3A_12ADBIT			1228 /*3A*/
#define HSCHANNEL_OVERCURRENT_VAL_2_5A_12ADBIT			1025 /*2.5A*/
#define HSCHANNEL_OVERCURRENT_VAL_1A_12ADBIT			410 /*1A*/
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum{
	HSD_Diag_Step_SetDiagMUX=1,
	HSD_Diag_Step_GetADVal=2,
}HSD_Diag_Step;

typedef enum{
	HS_OFF=0,
	HS_ON=1,
	HS_Fault=2,
}HS_ChannelState;

typedef struct{
    HS_ChannelState ChannelState;
	E_AdcAccuracy AdcAccuracy ;
	uint16_t OverCurrentThreshold;
    uint32_t HsdFD_ADCVAL;
    uint32_t Adc_width;
}S_ChannelInfo;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType CddDriver_DrvTps2HB35Init(void);
#endif /* CDD_DRIVER_HIGHSIDEDRV_DRVTPS2HB35_H_ */
