#ifndef _LIGHTING_POS_H_
#define _LIGHTING_POS_H_


uint16 POS_On(E_ChannelID id,uint16 *sts);
void POS_Off(E_ChannelID id);
uint16 POS_RunMainFun(E_ChannelID id,uint16 *sts);

#endif  /* _LIGHTING_POS_H_ */

