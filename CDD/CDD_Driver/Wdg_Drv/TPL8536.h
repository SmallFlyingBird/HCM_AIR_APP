#ifndef TPL8536_H
#define TPL8536_H

#include "Std_Types.h"
#include "WdgIf.h"

extern boolean Wdg_feed_flag;
extern uint16 ExWdg_Timer_20ms;
extern uint16 ExWdgTimeout;
void ExWdg_SetTriggerCondition(uint16 Timeout);
Std_ReturnType ExWdg_SetMode(WdgIf_ModeType Mode);

#endif