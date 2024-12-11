
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "LRDirection_Interface.h"
#include "DID_Interface.h"
#include "DTC_Interface.h"
#include "Dio.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static E_LR_DIRECTION g_LRDirection = DIRECTION_UNKOWM;
static E_LR_PIN_STATE sg_e_lrpinstate = LR_PIN_STATE_UNKOWN;
static E_LR_DIRECTION g_LRDirection_ForRoutinue = DIRECTION_UNKOWM;

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

E_LR_DIRECTION Interface_DirectionDection_StartRoutine(void)
{
    E_LR_DIRECTION lrdirection = DIRECTION_RIGHT;
    uint8_t SampleTimes;
    Dio_LevelType tempLevel = 0;
    uint32_t DelayCounter = 1000;

    for (SampleTimes = 0; SampleTimes < 10; SampleTimes++)
    {
        tempLevel += (uint8)Dio_ReadChannel(0x06);
        while (DelayCounter > 1)
        {
            DelayCounter--;
        }
        if (tempLevel > 6)
        {
            lrdirection = DIRECTION_LEFT;
            break;
        }
    }
    g_LRDirection_ForRoutinue = lrdirection;
    return lrdirection;
}

Std_ReturnType Interface_DirectionDection_StopRoutine(void)
{
    return E_OK;
}

Std_ReturnType Interface_DirectionDection_RequestRoutineResult(E_LR_DIRECTION *result)
{

    *result = g_LRDirection_ForRoutinue;
    return E_OK;
}

E_LR_DIRECTION Interface_GetAppLRDection(void)
{
    return g_LRDirection;
}

E_LR_DIRECTION Interface_GetBootLRDection(void)
{
#if 0
    DcmDspDataStruct *SharedData = (DcmDspDataStruct *)FL_BOOT_SHARE_DID_ADDRESS;

    if (SharedData->LeftRightFlag == SIDE_DETECT_LEFT_PBL)
        return  DIRECTION_LEFT;
    else if(SharedData->LeftRightFlag == SIDE_DETECT_RIGHT_PBL)
        return  DIRECTION_RIGHT; 
    else 
        return DIRECTION_UNKOWM;
#endif
    return DIRECTION_UNKOWM;
}

uint8_t DirectionInterface_Init(void)
{
#if 0
    uint32_t DelayCounter = 1000;
    uint8_t SampleTimes;
    Dio_LevelType tempLevel = 0;
    uint32_t signalval;
    DcmDspDataStruct *SharedData = (DcmDspDataStruct *)FL_BOOT_SHARE_DID_ADDRESS;

    g_LRDirection = DIRECTION_RIGHT;
    sg_e_lrpinstate = LR_PIN_STATE_SHORT2GND;

    for (SampleTimes = 0; SampleTimes < 10; SampleTimes++)
    {
        tempLevel += (uint8)Dio_ReadChannel(0x06);
        while (DelayCounter > 1)
        {
            DelayCounter--;
        }
        if (tempLevel > 6)
        {
            g_LRDirection = DIRECTION_LEFT;
            sg_e_lrpinstate = LR_PIN_STATE_OPENORSHORT2VCC;
            break;
        }
    }

    Interface_GetDidSignalData(DIDSIGNALNAME_ID_SideOfVehicle, &signalval);
    if (g_LRDirection == DIRECTION_LEFT)
    {
        if (signalval != 0x01)
        {
            Interface_SetSystemError(E_SystemErrorType_LeftRightMismatch, 1);
        }
        else if (SharedData->LeftRightFlag != SIDE_DETECT_LEFT_PBL)
        {
            Interface_SetSystemError(E_SystemErrorType_LeftRightMismatch, 1);
        }
        else
        {
            Interface_SetSystemError(E_SystemErrorType_LeftRightMismatch, 0);
        }
    }
    else if (g_LRDirection == DIRECTION_RIGHT)
    {
        if (signalval != 0x02)
        {
            Interface_SetSystemError(E_SystemErrorType_LeftRightMismatch, 1);
        }
        else if (SharedData->LeftRightFlag != SIDE_DETECT_RIGHT_PBL)
        {
            Interface_SetSystemError(E_SystemErrorType_LeftRightMismatch, 1);
        }
        else
        {
            Interface_SetSystemError(E_SystemErrorType_LeftRightMismatch, 0);
        }
    }
#endif
    return 0;
}