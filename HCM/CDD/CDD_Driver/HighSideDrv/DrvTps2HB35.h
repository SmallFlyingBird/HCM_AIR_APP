#ifndef CDD_DRIVER_HIGHSIDEDRV_DRVTPS2HB35_H_
#define CDD_DRIVER_HIGHSIDEDRV_DRVTPS2HB35_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "AdcDev_Interface.h"
#include "HighSide_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define HSD_CHANNEL_SIZE 2
#define ADC_BUFFER_SIZE 5 //采多少次ADC值 用来求均值


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
	uint16_t OverCurrentThreshold;
    uint32_t HsdFD_ADCVAL;
    uint32_t CurrentUpdateIndex;    /*记录电流更新次数，每更新一次CurrentUpdateIndex++*/
    uint32_t DiagPreCurrentIndex;   /*上一次诊断时刻，电流的Index值*/
}S_ChannelInfo;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
void CddDriver_DrvTps2HB35Init(void);
uint8 Interface_GetHSChannelDiagInfo(E_HSChannel hsdid);
#endif /* CDD_DRIVER_HIGHSIDEDRV_DRVTPS2HB35_H_ */
