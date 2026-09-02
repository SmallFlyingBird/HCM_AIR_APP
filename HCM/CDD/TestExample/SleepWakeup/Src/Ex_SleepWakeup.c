#include "Ex_SleepWakeup.h"
// #include "Platform.h"
#include "Dio.h"
#include "Wdg.h"
#include "PowerSupply_Interface.h"
#include "LinIf.h"

#define COM_HIGH_VOLTAGE 18
#define COM_LOW_VOLTAGE 8
#define COM_VOLTAGE_DELTA 0.1

static uint8 errorflag = 0;
void Ex_SleepWakeupInit(void)
{
    Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
}

void PowerManagerMainFunction(void)
{
    double voltage = 0;
    
    if ( Interface_GetKL56Voltage(&voltage) == E_OK) /* KL56 value */
    {
        if ((voltage > (COM_HIGH_VOLTAGE + COM_VOLTAGE_DELTA)) || (voltage < (COM_LOW_VOLTAGE - COM_VOLTAGE_DELTA)))
        {
            /**************************ERROR VOLTAGE****************************/
            if(!errorflag)
            {
                errorflag = 1;
                LinIf_GotoSleep(0);
            }
        }
        else if ((voltage < (COM_HIGH_VOLTAGE-COM_VOLTAGE_DELTA)) && (voltage > (COM_LOW_VOLTAGE+COM_VOLTAGE_DELTA)))
        {
            /**************************NORMAL **********************************/
            if(errorflag)
            {
                errorflag = 0;
                LinIf_Wakeup(0);
            }
        }
        else
        {
            /* NO ACT */
        }
    }
}


void WDT_Service(void)
{
    Wdg_Service();
    Dio_FlipChannel(DioConf_DioChannel_WD_Feed);
}

