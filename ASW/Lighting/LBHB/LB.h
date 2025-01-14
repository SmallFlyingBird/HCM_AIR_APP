
#ifndef _LB_LIGHTING_H_
#define _LB_LIGHTING_H_




void LB_On(E_ChannelID id,uint16 cur);
void LB_Off(E_ChannelID id);
uint16 LB_RunMainFun(E_ChannelID id,uint16 cur,uint8 SwitchOn,uint16 *sts);




#endif  
