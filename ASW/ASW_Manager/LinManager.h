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
}GS_LIN_LCONTROL;
typedef struct
{
    uint8 HSD1_Ena;
    uint8 HSD2_Ena;
    uint8 DCControl;
}GS_LIN_HSDCONTROL;

uint8 Get_BaseLight_Signal(void);
uint8 Get_FAN_Signal(void);
uint8 Get_DCMotor_Signal(void);
uint8 Get_DCMControl_Signal(void);
void Lin_Mainfunction(uint8 timebase);
//测试代码
typedef union
{
    uint8 Buck_Error;
    struct
    {
        uint8 Buckx_OVER_TEMP_CONFIRMED : 1;
        uint8 OpenError  : 1;
        uint8 Short2Gnd  : 1;
        uint8 Buckx_InterError : 1;
        // uint8_t Boostx_InterError : 1;
        uint8 rcvd : 4;
    } bits;
} U_Buck_Error;



#endif


