#include "Dma_Drv.h"
#include "Std_Types.h"
#include "McalLib.h"
#include "CDD_Dma.h"

void Uart_Abort(uint8 uartchannel,uint8 isReceive) /* ch0 uart0rx,ch1 uart1rx */
{
#if 0
    if(uartchannel == 0)  /* uart0  */
    {
        if(1 == isReceive){
            /*uart0 receive channel*/
            Dma_EnableChannelHwRequest(DMA_LOGIC_CH_1,FALSE);
        }else{
            /*uart0 transmit channel*/
            Dma_EnableChannelHwRequest(DMA_LOGIC_CH_0,FALSE);
        }
    }
    else if(uartchannel == 1) /* uart1  */
    {
        if(1 == isReceive){
            /*uart1 ch transmit*/
            Dma_EnableChannelHwRequest(DMA_LOGIC_CH_3,FALSE);
        }else{
            Dma_EnableChannelHwRequest(DMA_LOGIC_CH_2,FALSE);
        }
    }  
#endif
}


void Uart_GetStatus(uint8 ch, uint8 isReceive, Dma_ChannelStatusType * StatusPtr) /*ch0 uart0tx,ch1 uart1tx */
{
#if 0

    if(ch == 0)  /* uart0 tx */
    {
        if(1 == isReceive){
            Dma_GetChannelStatus(DMA_LOGIC_CH_1,StatusPtr);
        }else{
            Dma_GetChannelStatus(DMA_LOGIC_CH_0,StatusPtr);
        }
    }
    else if(ch == 1) /* uart1 tx */
    {
        if(1 == isReceive){
            Dma_GetChannelStatus(DMA_LOGIC_CH_3,StatusPtr);
        }else{
            Dma_GetChannelStatus(DMA_LOGIC_CH_2,StatusPtr);
        }
    }  
#endif
}

void Uart_GetRxStatus(uint8 ch, Dma_ChannelStatusType * StatusPtr) /* ch0 uart0rx,ch1 uart1rx */
{
#if 0
    if(ch == 0)  /* uart0 rx */
    {

        Dma_GetChannelStatus(DMA_LOGIC_CH_1,StatusPtr);

    }
    else if(ch == 1) /* uart1 rx */
    {
        Dma_GetChannelStatus(DMA_LOGIC_CH_3,StatusPtr);
    }  
#endif
}