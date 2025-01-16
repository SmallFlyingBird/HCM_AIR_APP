#ifndef _LINMANAGER_H_
#define _LINMANAGER_H_
#include "Platform_Types.h"

typedef union
{
    uint16 Light_Status;
    struct
    {
        uint8 LB_Ena     :1;
        uint8 HB_Ena     :1;
        uint8 Turn_Sts   :2;
        uint8 Turn_Act   :2;
        uint8 Pos_Ena    :1;
        uint8 Drl_Ena    :1;
        uint8 CROS_Ena   :1;
    }Bits;
}S_Lin_LControl;
typedef struct
{
    uint8 HSD1_Ena;
    uint8 HSD2_Ena;
    uint8 DCControl;
}S_Lin_HSDControl;

typedef union
{
    uint8 Buck_Error;
    struct
    {
        uint8 Buckx_OVER_TEMP_CONFIRMED : 1;
        uint8 OpenError  : 1;
        uint8 Short2Gnd  : 1;
        uint8 Buckx_InterError : 1;
        uint8 rcvd : 4;
    } bits;
} U_Buck_Error;


S_Lin_LControl Interface_Get_LinSignal(void);
uint8 LIN_SetFANSignal(void);
void Lin_Mainfunction(uint8 timebase);

#endif




