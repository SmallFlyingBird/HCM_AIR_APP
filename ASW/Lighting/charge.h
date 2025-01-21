#ifndef _CHARGE__H_
#define _CHARGE__H_


typedef enum{
    step1 =0,
    step2 =1,
    step3 =2,
    step4 =3,
    step5 =4,
    step6 =5,
    step7 =6,
    step8 =7,
    step9 =8,
    step10 =9,
}pr_ChargeStep_t;

#define Dynamic_Light_Pattern_TOTAL_Steps		(uint8)10

typedef enum{
    mode_none =0,
    mode1 =1,
    mode2 =2,
    mode3 =3,
}pr_ChargeMode_t;

typedef struct 
{
    pr_ChargeMode_t pr_ChargeMode; 
    uint16 OffsTiPm;
    uint16 ConTiPrm;
    uint8 LowBriPrm;
    uint8 UpperBriPrm;   
}pr_Charge_Group;

void Charge_Init(void);
uint16 Charge_MainFunction(E_ChannelID id,uint8 timebase);

#endif  /* _LIGHTING__H_ */


