#ifndef _STARSLIGHT_H_
#define _STARSLIGHT_H_


typedef enum{
	HWOUT1 = 0,
	HWOUT2 = 1,
}E_HwOutID;


void Interface_StarsLight_Ctrl(E_HwOutID id,uint8 per) ;
Std_ReturnType StarsLight_RunMainFun(void);

#endif  


