
#ifndef _LIGHTING_DRL_H_
#define _LIGHTING_DRL_H_


uint16 DRL_On(E_ChannelID id,uint16 cur,uint16 *sts);
void DRL_Off(E_ChannelID id);
uint16 DRL_RunMainFun(E_ChannelID id,uint16 cur,uint16 *sts);
#endif  /* _LIGHTING_DRL_H_ */

