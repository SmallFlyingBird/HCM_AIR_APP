#include "Max25608.h"
#include "Max25608_Interface.h"
#include "MatrixChip_Interface.h"
#include "Std_Types.h"

#define MAX25608_INTERFACE_C_HIGH_VERSION     0
#define MAX25608_INTERFACE_C_MIDDLE_VERSION   0
#define MAX25608_INTERFACE_C_LOW_VERSION      0


/**
 * Now attmpt to create config thing.
*/

Max25608_MaritxSettingType LMMMaritxConfig[12]={
    {
        .isEnable=1,
        .Type=1,
        .Addr=0,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=1,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=2,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=3,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=4,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=5,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=6,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=7,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=8,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=9,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=10,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    },
        {
        .isEnable=1,
        .Type=1,
        .Addr=11,
        .SlewRate=3,
        .ClkSel=0,
        .OpenTh=0,
        .ShortTh=0,
        .PHASE={0,50,100,150,200,250,0,1,2,3,4,5},
        .FailSafetyEnState=0x55
    }

};

Max25608_GlobalParaSettingType GlobalSetting={
    .pMaxLMMPWMDimFreq=2,
    .pMaxLMMWdgCfg=0x0,
};

/*used for store all LMM PHASE and duty cycle, neeed link to LMM device id*/
uint8 arr_Max25608DutyCycle[MAX_NUMBER_OF_MAX25608][12]={{0,},};
uint8 arr_Max25608Phase[MAX_NUMBER_OF_MAX25608][12]={{0,},};

/**used for mapping device_id and array, the array index is deviceID,
 * the content is PHASE or PWM specific array index*/
uint8 device_Mapping[16];
/**/
Std_ReturnType LMM_Max25608_InitFun(void){
    Max25608_MaritxSettingType *LMMConfig;
    /*used for return status val*/
    Std_ReturnType res=E_OK;
    /*used for LMM device transmit type*/
    Max25608_TransType device={
        .is25608b=0,
        .uartNum=0
    };
    /*used for get para to init LMM*/
    Max25608_GlobalParaSettingType *LMMGlobalConfig;
    /**
     * @todo: check para and GET parameters from tables, now is using global variable.
     * 
    */
    LMMGlobalConfig=&GlobalSetting;
    LMMConfig=LMMMaritxConfig;

    /*init all LMM store data*/
    uint8 number=0;uint8 ch=0;
    for(number=0;number<MAX_NUMBER_OF_MAX25608;number++){
        if(LMMConfig[number].isEnable!=0){

            /*set global settings*/
            res |=Max25608_SetLowDutyTh(&device,0,LMMConfig[number].Addr,LMMGlobalConfig->pMaxLMMLowPWMTh);
            res |=Max25608_SetUartCNFG(&device,0,LMMConfig[number].Addr,0,LMMGlobalConfig->pMaxLMMWdgCfg);

            device_Mapping[LMMConfig[number].Addr]=number;
            /*store phase*/
            /*clean dutycycle */
            for(ch=0;ch<12;ch++){
                arr_Max25608DutyCycle[number][ch]=0;
                arr_Max25608Phase[number][ch]=LMMMaritxConfig[number].PHASE[ch];
                res |=Max25608_SetPSFT(&device,0,0,ch,arr_Max25608Phase[number][ch]);
            }
            device.is25608b=LMMConfig[number].Type;
            /*set CNFG1*/
            res |=Max25608_SetCNFG1(
                &device,
                0,
                LMMConfig[number].Addr,
                LMMConfig[number].ClkSel,
                LMMGlobalConfig->pMaxLMMPWMDimFreq,
                LMMConfig[number].SlewRate,
                LMMConfig[number].OpenTh
            );
            /*set CNFG2 to 4*/
            res |=Max25608_SetCNFG2to4(&device,0,LMMConfig[number].Addr,2,LMMConfig[number].ShortTh);
            res |=Max25608_SetCNFG2to4(&device,0,LMMConfig[number].Addr,3,LMMConfig[number].ShortTh);
            res |=Max25608_SetCNFG2to4(&device,0,LMMConfig[number].Addr,4,LMMConfig[number].ShortTh);
            res |=Max25608_SetWDGFailSafeState(&device,0,LMMConfig[number].Addr,LMMConfig[number].FailSafetyEnState);
        }
            /*init finished, set SW_GO*/
        res |=Max25608_SetSWGO(&device,0,LMMConfig[number].Addr,1);
    }

    return res;
}

Std_ReturnType LMM_Max25608_SetPWM(uint8 device_id,S_ChannelPWMDataSrc *dataPtr){
    Std_ReturnType res=E_OK;
    /*used for LMM device transmit type*/
    Max25608_TransType device;
    /*used for cycling*/
    uint8 ch=0;
    /*compared every store pwm and input pwm. if there are not matched, change it*/
    for(ch=0;ch<12;ch++){
        
    }
    
    return res;
}

Std_ReturnType LMM_Max25608_DeInitFun(){
    Std_ReturnType res=E_OK;
    return res;
}

Std_ReturnType LMM_Max25608_ReadFun(S_MatrixTripDataPackets *dataPtr){
    Std_ReturnType res=E_OK;
    switch (dataPtr->DataType)
    {
    case E_MatrixTripDataType_PwmValue/* constant-expression */:
        
        /* code */
        break;
    
    default:
        break;
    }

    return res;
}

Std_ReturnType LMM_Max25608_WriteFun(S_MatrixTripDataPackets *dataPackets){
    Std_ReturnType res=E_OK;
    Max25608_TransType device;
    
    switch (dataPackets->DataType)
    {
    case E_MatrixTripDataType_PwmValue/* constant-expression */:
        
        /* code */
        break;
    
    default:
        break;
    }

    return res;
}

Std_ReturnType LMM_Max25608_MainFunction(void){
    uint8 id;
    Std_ReturnType res=E_OK;
    Max25608_TransType device={
        .is25608b=0,
        .uartNum=0
    };
    for(id=0;id<MAX_NUMBER_OF_MAX25608;id++){
        res |= Max25608_GetDeviceInfo(&device,id,NULL_PTR,NULL_PTR);
    }
    
}