#include "RTE_ASW.h"


void RTE_ASW_AllLightOff(void)
{
    /* turn off all channel */
    for (uint8 channelid = 0; channelid < CHANNEL_NUM; channelid++)
    {
        Interface_ChannelClose(channelid);
    }
    /* buck status off */
    Interface_SwitchBoost(STS_OFF);


    for (uint8 i = 0; i < 5; i++)
    {
        SetLgtStsFb_Status(STS_OFF,i);
    }

    SetLgtStsFb_Status(STS_OFF,9);

}