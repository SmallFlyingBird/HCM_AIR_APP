#include "LinManager.h"
#include "Ex_Lin.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
extern uint8 *ExLin_ControlBuffPtr;
GS_LIN_LCONTROL gs_lin_control;
GS_LIN_HSDCONTROL gs_lin_hsdcontrol;
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

void LIN_HSDAnalysis(uint8 *temp)
{
    static uint8 rev_fan=0;
    if(temp[0]&0x01==1)//HS1开
    {
        rev_fan=1;
        gs_lin_hsdcontrol.HSD1_Ena=1;
    }
    else if(rev_fan==1)
    {
        gs_lin_hsdcontrol.HSD1_Ena=0;
    }
    if(temp[1]&0x01==1)//HS2开
    {
        gs_lin_hsdcontrol.HSD2_Ena=1;
    }
    else
    {
        gs_lin_hsdcontrol.HSD2_Ena=0;
    }
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
//返回报文接收到的点灯信号
uint8 Get_BaseLight_Signal(void)
{
    return gs_lin_control.Light_Status;
}
//返回风扇打开信号
uint8 Get_FAN_Signal(void)
{
    return gs_lin_hsdcontrol.HSD1_Ena;
}
//返回电机打开信号
uint8 Get_DCMotor_Signal(void)
{
    return gs_lin_hsdcontrol.HSD2_Ena;
}

void LIN_Analysis(void)
{
    uint8 temp[8]={0};
    for (uint8 i = 0; i < 8;i++)
    {
        temp[i] = ExLin_ControlBuffPtr[i];
    }
    LIN_LightAnalysis(&temp[0]);
    LIN_HSDAnalysis(&temp[0]);
}

//测试代码
uint16 volbuf[6]={0};
sint16 tempbuf[2]={0};
uint8 lin_powererr[4]={0};
void LIN_ErrSend(void)
{
//上报KL56状态 uint8 lin_powererr[4]={0};
    ExLin_SetDTC(DTC_Power_Error,Over_Voltage); 
// 高边过流点设置为3A,即对应的SNS检测电压大于1.5V报过流故障;开路，短路故障也需要进行上报。
//直流电机需要有对应的报文控制。收到报文后，MCU的对应PWM口占空比对应不同电压的直流电机信号，使得电机调节循环伸缩 
// 检测直流电机故障状态
//BUCK自身温度读取与措施，需要上报温度报文
//BUCK需要读取输出电压，需要上报电压报文
//BUCK对应通道设置过压阈值（48V），过压报过压故障
//BUCK通道支持短路、过压、开路上报；
    // ExLin_SetDTC(DTC_Highside1_Error,STATUS_OFF); 
    
    // ExLin_SetDTC(DTC_Communication_Error,Over_Current); 
    // ExLin_SetDTC(DTC_DCmotor_Error,Over_Current); 

    // ExLin_SetStatus(STATUS_BUCK_Temp,tempbuf[0]);
    // ExLin_SetStatus(STATUS_BUCK_Voltage,volbuf[0]);//传递BUCK1 CH1电压
}

void Lin_Mainfunction(uint8 timebase)
{
    LIN_Analysis();
    LIN_ErrSend();
}


