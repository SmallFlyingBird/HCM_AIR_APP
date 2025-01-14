#ifndef _HB_LIGHTING_H_
#define _HB_LIGHTING_H_


void HB_On(E_ChannelID id,uint16 cur);
void HB_Off(E_ChannelID id);
uint16 HB_RunMainFun(E_ChannelID id,uint16 cur,uint8 SwitchOn,uint16 *sts);


#endif


