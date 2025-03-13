

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dio.h"
#include "Dio_Service.h"

typedef struct DioControl
{
    struct {
    uint8 CH2Status      :1;      
    uint8 CH2AltStatus   :1;   
    uint8 BoostENStatus  :1;  
    uint8 FanENStatus    :1;    
    uint8 DCENStatus     :1;     
    uint8 rev            :3;            
    } bits;
    uint8 val;
} DioControl;
static DioControl S_DioControl={STD_LOW,STD_LOW,STD_LOW,STD_LOW,STD_LOW};
void Boost_Enable(void)         
{ 
    if(S_DioControl.bits.BoostENStatus==STD_HIGH)
    {
        S_DioControl.bits.BoostENStatus=STD_LOW;
        Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_LOW); 
    }
} //open boost
void Boost_Disable(void)        
{ 
    if(S_DioControl.bits.BoostENStatus==STD_LOW)
    {
        S_DioControl.bits.BoostENStatus=STD_HIGH;
        Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_HIGH);
    }
} //close boost

//open CH2
void Port_CH2_Enable(uint8 flag)    
{  
    if((S_DioControl.bits.CH2Status==STD_LOW)&&(flag==0))
    {
        S_DioControl.bits.CH2Status=STD_HIGH;
        Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_HIGH);  
    }  
} 

//close CH2
void Port_CH2_Disable(void)     
{
    if(S_DioControl.bits.CH2Status==STD_HIGH)
    {
        S_DioControl.bits.CH2Status=STD_LOW;
        Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW);   
    }
} 

//open  CH2Alt
void Port_CH2Alt_Enable(uint8 flag)   
{
    if((S_DioControl.bits.CH2AltStatus==STD_LOW)&&(flag==0))
    {
        S_DioControl.bits.CH2AltStatus=STD_HIGH;
        Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_HIGH); 
    }
} 

//close CH2Alt
void Port_CH2Alt_Disable(void)  
{ 
    if(S_DioControl.bits.CH2AltStatus==STD_HIGH)
    {
        S_DioControl.bits.CH2AltStatus=STD_LOW;
        Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW); 
    } 
} 
//open  HSD1
void Port_FAN_Enable(void)      
{
    if(S_DioControl.bits.FanENStatus==STD_LOW)
    {
        S_DioControl.bits.FanENStatus=STD_HIGH;
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);
    } 
}  

//close HSD1
void Port_FAN_Disable(void)     
{ 
    if(S_DioControl.bits.FanENStatus==STD_HIGH)
    {
        S_DioControl.bits.FanENStatus=STD_LOW;
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);  
    }
}  

  //open  HSD2 
void Port_DC_Enable(void)       
{ 
    if(S_DioControl.bits.DCENStatus==STD_LOW)
    {
        S_DioControl.bits.DCENStatus=STD_HIGH;
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_HIGH); 
    }
}  

//close HSD2
void Port_DC_Disable(void)      
{ 
    if(S_DioControl.bits.DCENStatus==STD_HIGH)
    {
        S_DioControl.bits.DCENStatus=STD_LOW;
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);  
    }
}  


void Port_Init_All(void)
{
    Boost_Disable();
    Port_CH2Alt_Disable();  
    Port_CH2_Disable(); 
    Port_FAN_Enable();  
    Port_DC_Disable();  
}



