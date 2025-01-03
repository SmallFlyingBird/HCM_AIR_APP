
#ifndef UART_H
#define UART_H

#include "uart_drv.h"
#include "Dma_Drv.h"
#include "Std_Types.h"
#include "McalLib.h"
#include "CDD_Dma.h"
void Uart1Drv_Init(uint8 type);
void Uart0Drv_Init(uint8 type);
Std_ReturnType Uart_AsyncSend(uint8 ch,uint8 *data,uint8 len);
Std_ReturnType Uart_AsyncReceive(uint8 ch,uint8 *data,uint8 len);
void Uart_GetStatus(uint8 ch, uint8 isReceive, Dma_ChannelStatusType * StatusPtr);
void Uart_Abort(uint8 uartchannel,uint8 isReceive);
#endif
