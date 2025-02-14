#ifndef _LINMANAGER_H_
#define _LINMANAGER_H_
#include "Platform_Types.h"
#include "HcmPlatform.h"
#include "Lighting.h"
#include "Com.h"
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

void Lin_Mainfunction(uint8 timebase);
uint8 Lighting_GetLinCtrl(Light_Functions lf);
uint8 Interface_GetSignal_PosnLampDyn(void);
uint8 Interface_GetSignal_ClrDTCOfLINHCM(void);
uint8 Interface_GetSignal_LvlgSwtSetReqLvlgSwtSetReq(void);

#endif




