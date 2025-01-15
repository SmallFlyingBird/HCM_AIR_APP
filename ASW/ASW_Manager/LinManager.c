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
    gs_lin_ctrl.Bits.LB_Ena=Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam();
    gs_lin_ctrl.Bits.HB_Ena=Interface_GetSignal_ActnOfLedHiBeam(); 
    gs_lin_ctrl.Bits.CROS_Ena=Interface_GetSignal_ActnOfLedFrntCrossLamp();
    gs_lin_ctrl.Bits.Pos_Ena=Interface_GetSignal_ActnOfLedPosnLamp(); 
    gs_lin_ctrl.Bits.Drl_Ena=Interface_GetSignal_ActnOfLedDaytiRunngLamp(); 
    gs_lin_ctrl.Bits.Turn_Act=Interface_GetSignal_ActvnOfIndcrIndcrOut(); 
    gs_lin_ctrl.Bits.Turn_Sts=Interface_GetSignal_IndcrSts();
    if( gs_lin_ctrl.Bits.Turn_Act==gs_lin_ctrl.Bits.Turn_Sts)
    {
    #ifdef HCM_AIR_LEFT
        gs_lin_ctrl.Bits.Turn_Act=gs_lin_ctrl.Bits.Turn_Act&0x01;  
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x01;  
    #elif HCM_AIR_RIGHT
        gs_lin_ctrl.Bits.Turn_Act=gs_lin_ctrl.Bits.Turn_Act&0x02; 
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x02; 
    #endif
    }
    else if((gs_lin_ctrl.Bits.Turn_Act==0)&&(gs_lin_ctrl.Bits.Turn_Sts!=0))//系统需求：两个信号一致，信号有效
    {
    #ifdef HCM_AIR_LEFT  
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x01;  
    #elif HCM_AIR_RIGHT
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
//read back FAN LIN signal
uint8 LIN_SetFANSignal(void)
{
    return gs_lin_hsdctrl.HSD1_Ena;
}

void LIN_SetDTC_Fun(void)
{
    Frame_HcmlZcud_Lin2Fr01 * pt;
    
    lightsts.Light_Status=Lighting_Rek_Fun();

    pt = ExLin_SetFrame_HcmlZcud_Lin2Fr01();
    pt->Byte0.Bits.StsOfLedCornrgLampwithLINLe = lightsts.Bits.StsCORN;
    pt->Byte0.Bits.StsOfLedDaytiRunngLampWithLINLe = lightsts.Bits.StsDRL;
    pt->Byte0.Bits.StsOfLedFrntFogLampWithLINLe = 0;
    pt->Byte0.Bits.StsOfLedFrntPosnLampWithLINLe = lightsts.Bits.StsPOS;

    pt->Byte1.Bits.StsOfLedFrntTurnIndcrWithLINLe = lightsts.Bits.StsTI;
    pt->Byte1.Bits.StsOfLedHiBeamWithLINLe = lightsts.Bits.StsHB;
    pt->Byte1.Bits.StsOfLedLoBeamWithLINLe = lightsts.Bits.StsLB;
    pt->Byte1.Bits.StsOfWelGbyFrntWithLINLe = lightsts.Bits.StsWELC;
    
    pt->Byte6.Bits.ErrRespHCML =0;

    pt->HCML2DTCGroup1 = 0;
    pt->HCML2DTCGroup2 = 0;
    pt->HCML2DTCGroup3 = 0;
    pt->HCML2DTCGroup4 = 0;
}

void Lin_Mainfunction(uint8 timebase)
{
    LIN_Analysis_Fun();
    LIN_SetDTC_Fun();
}


