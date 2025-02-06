
#ifndef _TURN_INDICATOR_H_
#define _TURN_INDICATOR_H_

Std_ReturnType TI_On(E_ChannelID id,uint16 cur,uint16 *sts);
Std_ReturnType TI_Off(E_ChannelID id);
uint16 TI_RunMainFun(E_ChannelID id,uint16 cur,uint16 *sts);


#endif  /* _TURN_INDICATOR_H_ */


