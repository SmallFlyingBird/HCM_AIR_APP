#ifndef _CHARGE__H_
#define _CHARGE__H_


typedef enum{
    step1 =1,
    step2 =2,
    step3 =3,
    step4 =4,
    step5 =5,
    step6 =6,
    step7 =7,
    step8 =8,
    step9 =9,
    step10 =10,
}pr_ChargeStep_t;

#define Dynamic_Light_Pattern_TOTAL_Steps		(uint8)10

typedef enum{
    mode1 =1,
    mode2 =2,
    mode3 =3,
}pr_ChargeMode_t;

typedef struct 
{
    pr_ChargeStep_t pr_ChargeStep;
    pr_ChargeMode_t pr_ChargeMode; 
    uint16 OffsTiPm;
    uint16 ConTiPrm;
    uint8 LowBriPrm;
    uint8 UpperBriPrm;   
}pr_Charge_Group;
#endif  /* _LIGHTING__H_ */


