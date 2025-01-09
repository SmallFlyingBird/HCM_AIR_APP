#include "HcmPlatform.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "FrontCrossLamp.h"



void CROS_On(E_ChannelID id,uint16 cur)
{
    Interface_ChannelOpen(id,cur);
}

void CROS_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}




