
#include "LRDirection_Interface.h"
#include "Dio.h"
#include "Dio_Cfg.h"

static E_LR_DIRECTION g_LRDirection = DIRECTION_UNKOWM;

uint8 DirectionInterface_Init(void)
{
    uint16 DelayCounter = 1000;
    uint8 SampleTimes;
    Dio_LevelType tempLevel = 0;

    g_LRDirection = DIRECTION_RIGHT;
    for (SampleTimes = 0; SampleTimes < 10; SampleTimes++)
    {
        tempLevel += (uint8)Dio_ReadChannel(DioConf_DioChannel_L_R_Identify_To_MCU);
        while (DelayCounter > 1)
        {
            DelayCounter--;
        }
        if (tempLevel > 6)
        {
            g_LRDirection = DIRECTION_LEFT;
            break;
        }
    }
}