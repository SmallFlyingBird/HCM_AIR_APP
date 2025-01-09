#include "LinManager.h"
#include "Ex_Lin.h"
#include "ComSignal_Interface.h"
#include "HcmPlatform.h"
#include "Lighting.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
typedef union
{
    uint16 Light_Status;
    struct
    {
        uint8    StsLB       :2;
        uint8    StsTI       :2;
        uint8    StsPOS      :2;
        uint8    StsHB       :2;
        uint8    StsDRL      :2;
        uint8    StsCORN     :2;
        uint8    StsCROS     :2;
        uint8    StsWELC     :2;
    }Bits;
}S_Lin_LgtFb_t;
S_Lin_LgtFb_t lightsts;

extern uint8 *ExLin_ControlBuffPtr;
S_Lin_LControl gs_lin_ctrl;
S_Lin_HSDControl gs_lin_hsdctrl;
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

void LIN_Analysis_Fun(void)
{    
//Basic light signal
    gs_lin_ctrl.Bits.LB_Ena=Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam();//近光
    gs_lin_ctrl.Bits.HB_Ena=Interface_GetSignal_ActnOfLedHiBeam(); //远光
    gs_lin_ctrl.Bits.CROS_Ena=Interface_GetSignal_ActnOfLedFrntCrossLamp();//贯穿灯
    gs_lin_ctrl.Bits.Pos_Ena=Interface_GetSignal_ActnOfLedPosnLamp(); //位置
    gs_lin_ctrl.Bits.Drl_Ena=Interface_GetSignal_ActnOfLedDaytiRunngLamp(); //日行
    gs_lin_ctrl.Bits.Turn_Act=Interface_GetSignal_ActvnOfIndcrIndcrOut(); //转向1
    gs_lin_ctrl.Bits.Turn_Sts=Interface_GetSignal_IndcrSts();//转向2
    if( gs_lin_ctrl.Bits.Turn_Act==gs_lin_ctrl.Bits.Turn_Sts)//系统需求：两个信号一致，信号有效
    {
    #ifdef HCM_AIR_LEFT
        gs_lin_ctrl.Bits.Turn_Act=gs_lin_ctrl.Bits.Turn_Act&0x01;  
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x01;  
    #elif HCM_AIR_RIGHT
        gs_lin_ctrl.Bits.Turn_Act=gs_lin_ctrl.Bits.Turn_Act&0x02; 
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x02; 
    #endif
    }
    else
    {
        gs_lin_ctrl.Bits.Turn_Act=0;
        gs_lin_ctrl.Bits.Turn_Sts=0;
    }
}

S_Lin_LControl Interface_Get_LinSignal(void)
{
    return gs_lin_ctrl;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
//返回风扇打开信号
uint8 Get_FAN_Signal(void)
{
    return gs_lin_hsdctrl.HSD1_Ena;
}

// #include "DTC_Interface.h"
// //测试代码
// uint16 buckvolbuf[6]={0};
// sint16 bucktempbuf[2]={0};
// uint8 lin_powererr=0;
// uint16 kl56vol111=0;
// U_Buck_Error buckerror[6];
// uint8 ldoerr=0;
// uint8 buckovervolflag=0;
extern Frame_HcmlZcud_Lin2Fr01 Frame_Hcml;
void LIN_SetDTC_Fun(void)
{
    lightsts.Light_Status=Lighting_Rek_Fun();
    Frame_Hcml.Byte0.Bits.StsOfLedCornrgLampwithLINLe = lightsts.Bits.StsCORN;
    Frame_Hcml.Byte0.Bits.StsOfLedDaytiRunngLampWithLINLe = lightsts.Bits.StsDRL;
    Frame_Hcml.Byte0.Bits.StsOfLedFrntFogLampWithLINLe = 0;
    Frame_Hcml.Byte0.Bits.StsOfLedFrntPosnLampWithLINLe = lightsts.Bits.StsPOS;

    Frame_Hcml.Byte1.Bits.StsOfLedFrntTurnIndcrWithLINLe = lightsts.Bits.StsTI;
    Frame_Hcml.Byte1.Bits.StsOfLedHiBeamWithLINLe = lightsts.Bits.StsHB;
    Frame_Hcml.Byte1.Bits.StsOfLedLoBeamWithLINLe = lightsts.Bits.StsLB;
    Frame_Hcml.Byte1.Bits.StsOfWelGbyFrntWithLINLe = lightsts.Bits.StsWELC;

    Frame_Hcml.Byte6.Bits.ErrRespHCML =0;

    Frame_Hcml.HCML2DTCGroup1 = 0;
    Frame_Hcml.HCML2DTCGroup2 = 0;
    Frame_Hcml.HCML2DTCGroup3 = 0;   
    Frame_Hcml.HCML2DTCGroup4 = 0;
// 直流电机需要有对应的报文控制。收到报文后，MCU的对应PWM口占空比对应不同电压的直流电机信号，使得电机调节循环伸缩 
}

void Lin_Mainfunction(uint8 timebase)
{
    LIN_Analysis_Fun();
    LIN_SetDTC_Fun();
}


