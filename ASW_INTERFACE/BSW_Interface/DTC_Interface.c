#include "DTC_Interface.h"

/***************************************************************通道类故障***************************************************************/
// const uint8 gMap_ChannelShort2GndError[MAX_CHANNLE_NUM] = {0};
// const uint8 gMap_ChannelShort2VccError[MAX_CHANNLE_NUM] = {0};
// const uint8 gMap_ChannelOpenError[MAX_CHANNLE_NUM] = {0};
// const uint8 gMap_ChannelUVError[MAX_CHANNLE_NUM] = {0};
uint8 gMap_ChShort2GndError[MAX_CHANNLE_NUM] = {0};
uint8 gMap_ChShort2VccError[MAX_CHANNLE_NUM] = {0};
uint8 gMap_ChOpenError[MAX_CHANNLE_NUM] = {0};
uint8 gMap_ChUVError[MAX_CHANNLE_NUM] = {0};
/***************************************************************通道类故障***************************************************************/
void Interface_SetDtcChannelError(E_ChannelID index, E_ChannelErrorType errortype, uint8 val)
{
    switch (errortype)
    {
    case E_CAHNNEL_OPEN:
        if (val)
        {
            gMap_ChOpenError[index]=val;
        }
        else
        {
            gMap_ChOpenError[index]=0;
        }
        break;
    case E_CAHNNEL_SHORT2GND:
        if (val)
        {
            gMap_ChShort2GndError[index]=val;
        }
        else
        {
            gMap_ChShort2GndError[index]=0;
        }
        break;
    case E_CAHNNEL_SHORT2VCC:
        if (val)
        {
            gMap_ChShort2VccError[index]=val;
        }
        else
        {
            gMap_ChShort2VccError[index]=0;
        }
        break;
    case E_CAHNNEL_UNVOL:
        if (val)
        {
            gMap_ChUVError[index]=val;
        }
        else
        {
            gMap_ChUVError[index]=0;
        }
        break;
    }
}

//获取灯的通道故障
uint8 Interface_GetDtcLightChannelError(E_ChannelID chid, E_ChannelErrorType errortype, uint8 val)
{
    uint8 chmask=0;
    if((gMap_ChOpenError[chid]||gMap_ChShort2GndError[chid]||gMap_ChShort2VccError[chid]||gMap_ChUVError[chid])!=0)
    {
        return 1;
    }
}
