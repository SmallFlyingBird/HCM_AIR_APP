

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dio.h"
#include "Dio_Service.h"

void Boost_Enable(void)      { Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_LOW); } //Boost使能输出
void Boost_Disable(void)     { Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_HIGH);} //Boost不使能输出

void Port_CH2Alt_Enable(void)    { Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_HIGH); } //打开TL使能
void Port_CH2Alt_Disable(void)   { Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW);  } //关闭TL使能

void Port_CH2_Enable(void)   { Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_HIGH); } //打开DRL使能
void Port_CH2_Disable(void)  { Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW);  } //关闭DRL使能

void Port_FAN_Enable(void)   { Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH); } //打开FAN使能
void Port_FAN_Disable(void)  { Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);  } //关闭FAN使能

void Port_DC_Enable(void)    { Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_HIGH); } //打开DC使能
void Port_DC_Disable(void)   { Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);  } //关闭DC使能


void Port_Init_All(void)
{
    Boost_Disable();
    Port_CH2Alt_Disable();  
    Port_CH2_Disable(); 
    Port_FAN_Disable();  
    Port_DC_Disable();  
}



