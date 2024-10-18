#ifndef _HALLSENSOR_H_
#define _HALLSENSOR_H_
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
#define HALLSENSOR_MAX_NUM 1

#define HALLSENSOR_FEEDBACK_FILTER_ENABLE 0
#if HALLSENSOR_FEEDBACK_FILTER_ENABLE
#define HALLSENSOR_FEEDBACK_FILTER_BUFFERSIZE 5
#endif

/*The HallSensor is considered as short to gnd,when feedback is less than this micro*/
#define HALLSENSOR_SHORT2GND_THRESHOLD	  164	/*0.2v*/

/*The HallSensor is considered as low level,when feedback is less than this micro and more then HALLSENSOR_SHORT2GND_THRESHOLD*/
#define HALLSENSOR_LOWLEVEL_THRESHOLD	  1229	/*1.5v*/

/*The HallSensor is considered as unknow level,when feedback is less than this micro and more then HALLSENSOR_LOWLEVEL_THRESHOLD*/
#define HALLSENSOR_HIGHLEVEL_THRESHOLD	  3686	/*4.5v*/

/*
 *The HallSensor is considered as High level,when feedback is less than this micro and more then HALLSENSOR_HIGHLEVEL_THRESHOLD
 *The HallSensor is considered as open,when feedback is more than this micro 
 */
#define HALLSENSOR_OPEN_THRESHOLD	  	  3931	/*4.8v*/

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum{
    E_HallSensorFeedBackType_LowLevel=0,
    E_HallSensorFeedBackType_HighLevel,
    E_HallSensorFeedBackType_UnknowLevel,
    E_HallSensorFeedBackType_Short2Gnd,
    E_HallSensorFeedBackType_Open,
}E_HallSensorFeedBackType;

/*pSvlSensorEdge*/
typedef enum{
    E_HallSensorPolarity_Unkown=0,
    E_HallSensorPolarity_MotorDirPinLow_AS_LowLevel=1,
    E_HallSensorPolarity_MotorDirPinLow_AS_HighLevel=2,
}E_HallSensorPolarity;


typedef enum{
    E_HallMotorFDMoveDir_Unkown=0,
    E_HallMotorFDMoveDir_LowLevel2HighLevel=1,
    E_HallMotorFDMoveDir_HighLevel2LowLevel=2,
}E_HallMotorFDMoveDir;

typedef enum{
    E_HallMotorPosMoveDir_Unkown=0,
    E_HallMotorPosMoveDir_LowPosl2HighPos=1,
    E_HallMotorPosMoveDir_HighPosl2LowPos=2,
}E_HallMotorPosMoveDir;


typedef struct HallSensorInfo{
#if HALLSENSOR_FEEDBACK_FILTER_ENABLE
    uint32_t FeedBackMeanValue;
    uint8_t FeedBackBufferReadIndex;
    uint8_t FirstCaculateConplete;
    uint32_t FeedBackBuffer[HALLSENSOR_FEEDBACK_FILTER_BUFFERSIZE];
#endif
    E_HallSensorPolarity HallSensorPolarity;
    E_HallMotorFDMoveDir HallMotorFDMoveDir;
    E_HallMotorPosMoveDir HallMotorPosMoveDir;
    sint16 HallSwingLowPos;
    sint16 HallSwingHighPos;
}S_HallSensorInfo;



/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/*
 *Function: Get HallSensor Feedback value
 *Std_ReturnType:  E_NOT_OK :ADC not complete 
 *Parameter:
 */
Std_ReturnType HallSensorInf_GetHallSensorFeedBack(E_HallSensorFeedBackType * HallSensorFeedBackType);
#endif