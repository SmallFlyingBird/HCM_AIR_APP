#ifndef _LINMANAGER_H_
#define _LINMANAGER_H_
#include "Platform_Types.h"

typedef union
{
    uint8 Light_Status;
    struct
    {
        unsigned LB_Ena     :1;
        unsigned HB_Ena     :1;
        unsigned Turn_Ena   :1;
        unsigned Pos_Ena    :1;
        unsigned Drl_Ena    :1;
        unsigned CROS_Ena   :3;
    }Bits;
    uint8 HSD_Status;
}GS_LIN_CONTROL;

uint8 Get_BaseLight_Status(void);
void LIN_Analysis(uint8 timebase);
#endif


