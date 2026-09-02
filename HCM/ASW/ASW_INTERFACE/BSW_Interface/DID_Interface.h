#ifndef DID_INTERFACE_H_
#define DID_INTERFACE_H_
#include "HcmPlatform.h"

typedef enum{
    WDG_Safety_SPI =0,       /* SPI丢通信 */          
    NTC1_SCG         ,           
    NTC1_SCB         ,           
    NTC1_OL          ,          
    NTC2_SCG         ,           
    NTC2_SCB         ,           
    NTC2_OL          ,          
    NTC3_SCG         ,           
    NTC3_SCB         ,           
    NTC3_OL          ,          
    NTC4_SCG         ,       //10    
    NTC4_SCB         ,           
    NTC4_OL          ,          
    NTC5_SCG         ,           
    NTC5_SCB         ,           
    NTC5_OL          ,//=15  
    Rcod1_Fail       ,
    Rcod2_Fail       ,       
    Rcod3_Fail       ,                
    LR_Detection     ,     /* 左右识别线 */      
    Channel1_SCG =20 ,               
    Channel1_SCB     ,               
    Channel1_OL      ,              
    Channel1_UV      ,              
    Channel2_SCG     ,               
    Channel2_SCB     ,               
    Channel2_OL      ,              
    Channel2_UV      ,              
    Channel3_SCG     ,               
    Channel3_SCB     ,               
    Channel3_OL  =30 ,              
    Channel3_UV      ,              
    Channel4_SCG     ,               
    Channel4_SCB     ,               
    Channel4_OL      ,              
    Channel4_UV      ,              
    Channel5_SCG     ,               
    Channel5_SCB     ,               
    Channel5_OL      ,              
    Channel5_UV      ,              
    Channel6_SCG     ,//40               
    Channel6_SCB     ,               
    Channel6_OL      ,              
    Channel6_UV      ,              
    HSD1_SCG         ,           
    HSD1_SCB_OL      ,              
    HSD2_SCG         ,           
    HSD2_SCB_OL      ,              
    HSD3_SCG         ,           
    HSD3_SCB_OL      ,              
    In_LED_driver    ,     /*=50 内部LED驱动：limphome */                    
    Side_Detection   ,     /*内部引导加载程序（Bootloader）和应用程序检测到与NVRAM（易失性存储器）编码值不一致。先不加。  */                   
    LB_E2E_failure   ,
    TI_E2E_failure   ,
    CC_OverRange     ,     /* 2025.12.16 437C电流值超范围 100~1500mA */               
    DC_Motor_Fail    ,
    KL56_Too_High    ,                          
    KL56_Too_Low     ,                        
    Parameter_Fail   ,     /* NA */
    CalData_fail     ,     /* NA */
    D900_NUM         ,
}E_D900_Type;


typedef enum{
    STATE_OK =0 ,                 
    STATE_ERROR ,           
}Error_Type;

void DID_Interface_Read_4359to435F(E_ChannelID id,uint8 *data);
void DID_Interface_Read_43CF(uint8 *data);
void DID_Interface_Read_43D2(uint8 *data);
void DID_Interface_Read_43DA(uint8 *data);
void DID_Interface_Read_4351(uint8 *data);
void DID_Interface_Read_D900(uint8 *data);
void Interface_SetD900Data(E_D900_Type type,Error_Type error);
uint8 Interface_ReadDIDData(E_D900_Type type);

#endif


