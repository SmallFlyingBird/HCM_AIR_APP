
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "SystemService_Interface.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

static uint16_t Saved_ChannelCurrent[MAX_CHANNLE_NUM];
static uint8_t Saved_ChannelPwm[MAX_CHANNLE_NUM];
static E_ChannelState Saved_ChannelState[MAX_CHANNLE_NUM];
uint8 g_DrvReInitMask=0;
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static void SaveBuckStateAndCloseBuck(void)
{
    uint8_t i = 0;
    for (i = 0; i < MAX_CHANNLE_NUM; i++)
    {
        Saved_ChannelCurrent[i] = Interface_GetChannelCurCurrent((E_ChannelID)i);
        Saved_ChannelPwm[i] = Interface_GetChannelCurPWM((E_ChannelID)i);
        Interface_GetChannelSwitchState((E_ChannelID)i, &Saved_ChannelState[i]);

        Interface_SetChannelSwitchState((E_ChannelID)i, CHANNEL_STATE_OFF);
        Interface_SetChannelPWM((E_ChannelID)i, 0);
        Interface_SetChannelCurrent((E_ChannelID)i, 0);
    }
}

static void ResumeBuckState(void)
{
    uint8_t i = 0;
    for (i = 0; i < MAX_CHANNLE_NUM; i++)
    {
        Interface_SetChannelPWM((E_ChannelID)i, Saved_ChannelPwm[i]);
        Interface_SetChannelCurrent((E_ChannelID)i, Saved_ChannelCurrent[i]);
        Interface_SetChannelSwitchState((E_ChannelID)i, Saved_ChannelState[i]);
    }
}

static void DrvReInit_MainFunc(uint8_t timebase)
{
    static uint16_t DrvReInitTimeTick = 0;
    Std_ReturnType rtval = E_OK;
    uint16_t BoostMaxVlotage = 0;
    E_ChannelID chindex = 0;

    DrvReInitTimeTick += timebase;

    if (DrvReInitTimeTick < 100)
        return;

    DrvReInitTimeTick = 0;

    if (g_DrvReInitMask != 0)
    {
        /*1.保存buck通道输出状态并关闭通道输出*/
        SaveBuckStateAndCloseBuck();
        rtval = Interface_BuckInit();
        if (rtval == E_OK)
        {
            ResumeBuckState();
        }
    }
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
void Interface_AddReInitDrvDevice(void)
{
    g_DrvReInitMask = 1;
}

void SystemService_MainFunction(uint8_t timebase)
{
    DrvReInit_MainFunc(timebase);
}
