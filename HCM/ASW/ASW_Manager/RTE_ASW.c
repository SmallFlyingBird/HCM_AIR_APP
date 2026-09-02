#include "RTE_ASW.h"
#include "Dio_Service.h"
#include "Com_Cfg.h"
void RTE_ASW_AllLightOff(void)
{
    /* turn off all channel */
    for (uint8 channelid = 0; channelid < CHANNEL_NUM; channelid++)
    {
        Interface_ChannelClose(channelid);
    }

    for (uint8 i = 0; i < 5; i++)
    {
        SetLgtStsFb_Status(STS_OFF,i);
    }

    SetLgtStsFb_Status(STS_OFF,9);

    /* boost status off */
    Boost_Disable();

}

void RTE_ASW_ClearSignals(void)
{
    Com_ClearAllSignals();
}