#include "LinManager.h"
#include "DrvTps2HB35.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

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
typedef enum{
	FAN_ON=1,
	DCMO_ON=2,
	FAN_OFF=4,
    DCMO_OFF=8,
}LIN_ChaStatus;

extern uint8 *ExLin_ControlBuffPtr;
GS_LIN_CONTROL gs_lin_control;
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
void LIN_LightAnalysis(uint8 *temp)
{    
    if((temp[0]&0x02)!=0)//贯穿灯亮
    {
        gs_lin_control.Bits.CROS_Ena=1; 
    }
    else if((temp[0]&0x02)==0)//贯穿灯灭
    {
       gs_lin_control.Bits.CROS_Ena=0;  
    }

    if((temp[3]&0x01)!=0)//近光 亮
    {
        gs_lin_control.Bits.LB_Ena=1; 
    }
    else if((temp[3]&0x01)==0)//近光 灭
    {
        gs_lin_control.Bits.LB_Ena=0;  //CH1  近光、远光
    }

    if((temp[3]&0x02)!=0)//远光开
    {
        gs_lin_control.Bits.HB_Ena=1;
    }
    else if((temp[3]&0x02)==0)//远光关
    {
        gs_lin_control.Bits.HB_Ena=0;
    }
   
    if(((temp[3]&0x04)!=0)||((temp[3]&0x08)!=0))//位置 开
    {
        gs_lin_control.Bits.Pos_Ena=1;
    } 
    else if(((temp[3]&0x04)==0)&&((temp[3]&0x08)==0))//位置
    {
        gs_lin_control.Bits.Pos_Ena=0;
    } 

    if((temp[3]&0x10)!=0)//转向打开
    {
        gs_lin_control.Bits.Turn_Ena=1;
    }
    else if((temp[3]&0x10)==0)//转向关
    {
        gs_lin_control.Bits.Turn_Ena =0;
    }
}

//返回报文接收到的点灯信号
uint8 Get_BaseLight_Status(void)
{
    return gs_lin_control.Light_Status;
}
void LIN_HSDAnalysis(uint8 *temp)
{
    static uint8 rev_fan=0;
    if(temp[0]&0x01==1)//HS1开
    {
        rev_fan=1;
        gs_lin_control.HSD_Status=1;
        FAN_Open();
    }
    else if(rev_fan==1)
    {
        gs_lin_control.HSD_Status=1;
        FAN_Close();
    }
    if(temp[1]&0x01==1)//HS2开
    {
        
        DC_Motor_Open();
    }
    else
    {
        DC_Motor_Close();
    }
}

void LIN_Analysis(uint8 timebase)
{
    uint8 temp[8]={0};
    for (uint8 i = 0; i < 8;i++)
    {
        temp[i] = ExLin_ControlBuffPtr[i];
    }
    LIN_LightAnalysis(&temp[0]);
    LIN_HSDAnalysis(&temp[0]);
}


void LIN_ErrSend(uint8 timebase)
{
        // ExLin_SetDTC(DTC_Highside1_Error,Over_Current); //LIN 读温度
    // ExLin_SetStatus(STATUS_BUCK_Temp,tempbuf[0]);
    // ExLin_SetStatus(STATUS_BUCK_Voltage,volbuf[0]);//传递BUCK1 CH1电压
}

