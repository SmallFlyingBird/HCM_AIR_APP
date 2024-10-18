
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HallSensor.h"
#include "AdcDev_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
#if HALLSENSOR_FEEDBACK_FILTER_ENABLE
static S_HallSensorInfo gs_HallSensorInfo[HALLSENSOR_MAX_NUM];
#endif
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

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/


Std_ReturnType HallSensorInf_GetHallSensorFeedBack(E_HallSensorFeedBackType * HallSensorFeedBackType)
{
    Std_ReturnType rtval = E_OK;
    uint32_t DigitalValue;
#if HALLSENSOR_FEEDBACK_FILTER_ENABLE
#else
    rtval|=Interface_GetAdcDigitalValue(E_AdcFunction_HallIn,&DigitalValue);
    if(rtval == E_OK)
    {
        if(DigitalValue <= HALLSENSOR_SHORT2GND_THRESHOLD)
        {
            *HallSensorFeedBackType=E_HallSensorFeedBackType_Short2Gnd;
        }   
        else if(DigitalValue <= HALLSENSOR_LOWLEVEL_THRESHOLD) 
        {
            *HallSensorFeedBackType=E_HallSensorFeedBackType_LowLevel;
        }
        else if(DigitalValue <= HALLSENSOR_HIGHLEVEL_THRESHOLD)
        {
            *HallSensorFeedBackType=E_HallSensorFeedBackType_UnknowLevel;
        }
        else if(DigitalValue <= HALLSENSOR_OPEN_THRESHOLD)
        {
            *HallSensorFeedBackType=E_HallSensorFeedBackType_HighLevel;
        }
        else
        {
             *HallSensorFeedBackType=E_HallSensorFeedBackType_Open;
        }
    }
#endif
    return rtval;
}


#if HALLSENSOR_FEEDBACK_FILTER_ENABLE
void HallSensorInf_Mainfunction(uint8_t timebase)
{

}
#endif