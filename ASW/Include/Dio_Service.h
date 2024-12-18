#ifndef DIO_SERVICE_H
#define DIO_SERVICE_H

void Port_Init_All(void);

void Boost_Disable(void);
void Boost_Enable(void);

void Port_TL_Enable(void) ;
void Port_TL_Disable(void);

void Port_DrlPos_Enable(void) ;
void Port_DrlPos_Disable(void);

void Port_FAN_Enable(void) ;

void Port_FAN_Disable(void) ;

void Port_DC_Enable(void) ;
void Port_DC_Disable(void) ;

uint8 Port_Read_LR(void)  ;

#endif
