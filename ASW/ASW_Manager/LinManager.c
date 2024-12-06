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
uint8 lin_rev_buf[8]={0};
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
    if((temp[3]&0x20)!=0)//贯穿灯亮
    {
        gs_lin_control.Bits.CROS_Ena=1; 
    }
    else if((temp[3]&0x20)==0)//贯穿灯灭
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
        gs_lin_hsdcontrol.DCControl=temp[2];
    }
    else
    {
        gs_lin_hsdcontrol.HSD2_Ena=0;
    }
    
//直流电机需要有对应的报文控制。收到报文后，MCU的对应PWM口占空比对应不同电压的直流电机信号，使得电机调节循环伸缩 
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

void LIN_Analysis_Fun(void)
{
    for (uint8 i = 0; i < 8;i++)
    {
        lin_rev_buf[i] = ExLin_ControlBuffPtr[i];
    }
    LIN_LightAnalysis(&lin_rev_buf[0]);
    LIN_HSDAnalysis(&lin_rev_buf[0]);
}
#include "DTC_Interface.h"
//测试代码
uint16 buckvolbuf[6]={0};
sint16 bucktempbuf[2]={0};
uint8 lin_powererr=0;
uint16 kl56vol111=0;
uint8 buckerrbuf[6]={0};
uint8 ldoerr=0;
uint8 losscommunicate=0;
uint8 buckovervolflag=0;
void LIN_SetDTC_Fun(void)
{
    ExLin_DTCstatus buckerr[6];
//故障
    // ExLin_SetDTC(DTC_Power_Error,lin_powererr);  //KL56状态  过/欠压(欠压+对地短路)/正常
    // ExLin_SetDTC(DTC_HSD1_Error,STATUS_OFF);  //风扇故障 没有 //SNS检测电压大于1.5V报过流故障;开路，短路故障也需要进行上报。
    // ExLin_SetDTC(DTC_HSD2_Error,STATUS_OFF);  //电机故障 没有 // 检测直流电机故障状态

    // ExLin_SetDTC(DTC_BUCK_Error,buckovervolflag); //BUCK对应通道设置过压阈值（48V），过压报过压故障
    // ExLin_SetDTC(DTC_LDO_Error,STATUS_OFF); //LDO错误
    // ExLin_SetDTC(DTC_Communication_Error,losscommunicate);//BUCK通信丢失

    // ExLin_SetDTC(DTC_BUCK0CH1_Error,buckerr[0].Buck_Error);//BUCK通道支持短路、过压、开路上报；
    // ExLin_SetDTC(DTC_BUCK0CH2_Error,buckerr[1].Buck_Error);
    // ExLin_SetDTC(DTC_BUCK0CH3_Error,buckerr[2].Buck_Error);
    // ExLin_SetDTC(DTC_BUCK1CH1_Error,buckerr[3].Buck_Error);
    // ExLin_SetDTC(DTC_BUCK1CH2_Error,buckerr[4].Buck_Error);
    // ExLin_SetDTC(DTC_BUCK1CH3_Error,buckerr[5].Buck_Error);
    ExLin_SetDTC(DTC_Power_Error,1);  //KL56状态  过/欠压(欠压+对地短路)/正常
    ExLin_SetDTC(DTC_HSD1_Error,1);  //风扇故障 没有 //SNS检测电压大于1.5V报过流故障;开路，短路故障也需要进行上报。
    ExLin_SetDTC(DTC_HSD2_Error,1);  //电机故障 没有 // 检测直流电机故障状态

    ExLin_SetDTC(DTC_BUCK_Error,1); //BUCK对应通道设置过压阈值（48V），过压报过压故障
    ExLin_SetDTC(DTC_LDO_Error,1); //LDO错误
    ExLin_SetDTC(DTC_Communication_Error,1);//BUCK通信丢失

    ExLin_SetDTC(DTC_BUCK0CH1_Error,1);//BUCK通道支持短路、过压、开路上报；
    ExLin_SetDTC(DTC_BUCK0CH2_Error,1);
    ExLin_SetDTC(DTC_BUCK0CH3_Error,1);
    ExLin_SetDTC(DTC_BUCK1CH1_Error,1);
    ExLin_SetDTC(DTC_BUCK1CH2_Error,1);
    ExLin_SetDTC(DTC_BUCK1CH3_Error,1);
//状态值
    // ExLin_SetStatus(STATUS_BUCK0_Temp,bucktempbuf[0]); //BUCK自身温度读取与措施，需要上报温度报文
    // ExLin_SetStatus(STATUS_BUCK1_Temp,bucktempbuf[1]);

    // ExLin_SetStatus(STATUS_BUCK0CH1_Voltage,buckvolbuf[0]);//BUCK需要读取输出电压，需要上报电压报文
    // ExLin_SetStatus(STATUS_BUCK0CH2_Voltage,buckvolbuf[1]);
    // ExLin_SetStatus(STATUS_BUCK0CH3_Voltage,buckvolbuf[2]);
    // ExLin_SetStatus(STATUS_BUCK0CH1_Voltage,buckvolbuf[3]);
    // ExLin_SetStatus(STATUS_BUCK0CH2_Voltage,buckvolbuf[4]);
    // ExLin_SetStatus(STATUS_BUCK0CH3_Voltage,buckvolbuf[5]);

    // ExLin_SetStatus(STATUS_KL56_Voltage,kl56vol111);
    // ExLin_SetStatus(STATUS_LDO_Voltage,ldoerr);
    ExLin_SetStatus(STATUS_BUCK0_Temp,123); //BUCK自身温度读取与措施，需要上报温度报文
    ExLin_SetStatus(STATUS_BUCK1_Temp,123);
    ExLin_SetStatus(STATUS_BUCK0CH1_Voltage,123);//BUCK需要读取输出电压，需要上报电压报文
    ExLin_SetStatus(STATUS_BUCK0CH2_Voltage,123);
    ExLin_SetStatus(STATUS_BUCK0CH1_Voltage,123);
    ExLin_SetStatus(STATUS_BUCK0CH2_Voltage,123);
    ExLin_SetStatus(STATUS_KL56_Voltage,123);
    ExLin_SetStatus(STATUS_LDO_Voltage,12);

//直流电机需要有对应的报文控制。收到报文后，MCU的对应PWM口占空比对应不同电压的直流电机信号，使得电机调节循环伸缩 
}

void Lin_Mainfunction(uint8 timebase)
{
    LIN_Analysis_Fun();
    LIN_SetDTC_Fun();
}


