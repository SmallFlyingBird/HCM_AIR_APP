#ifndef DIO_SERVICE_H
#define DIO_SERVICE_H

void Port_Init_All(void);

void Boost_Disable(void);
void Boost_Enable(void);

void Port_CH2Alt_Enable(uint8 flag);
void Port_CH2Alt_Disable(void);

void Port_CH2_Enable(uint8 flag);
void Port_CH2_Disable(void);

void Port_FAN_Enable(void) ;

void Port_FAN_Disable(void) ;

void Port_DC_Enable(void) ;
void Port_DC_Disable(void) ;

#endif
