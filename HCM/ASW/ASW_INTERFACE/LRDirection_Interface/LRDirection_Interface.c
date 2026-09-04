
#include "LRDirection_Interface.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "PduR_Callout.h"
#include "DTC_Interface.h"
#include "DID_Interface.h"

static E_LR_DIRECTION g_LRDirection = DIRECTION_UNKOWM;
static E_LR_DIRECTIONCMP Cmp_LRDirection = DIRECTION_SAME;

void DirectionInterface_Init(void)
{
    uint16 DelayCounter = 1000;
    uint8 SampleTimes;
    Dio_LevelType tempLevel = 0;
    E_LR_DIRECTION LRDirection_DID = DIRECTION_UNKOWM;
/* Ӳ�߷��� */
    g_LRDirection = DIRECTION_RIGHT;
    for (SampleTimes = 0; SampleTimes < 10; SampleTimes++)
    {
        tempLevel += (uint8)Dio_ReadChannel(DioConf_DioChannel_LR_Identify);
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
/* 437C���� */
    if(PduR_GetLightSide()==DIRECTION_RIGHT)
    {
        LRDirection_DID = DIRECTION_RIGHT;
    }
    else if(PduR_GetLightSide()==DIRECTION_LEFT)
    {
        LRDirection_DID = DIRECTION_LEFT;
    }

    if(LRDirection_DID != g_LRDirection)
    {
        Cmp_LRDirection = DIRECTION_DIF;
        Interface_SetSystemError(E_SystemErrorType_LeftRightError,1);
        Interface_SetD900Data( LR_Detection , STATE_ERROR);
    }
    else
    {
        Interface_SetD900Data( LR_Detection , STATE_OK);
    }
}

uint8 Interface_GetLRDirection(void)
{
    return g_LRDirection;
}

uint8 Interface_GetLRDirectionCmp(void)
{
    return Cmp_LRDirection;
}

