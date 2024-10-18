

#include "Uart.h"
#include "Port.h"
#include "CDD_Dma.h"
#include "Dma_Drv.h"
#include "Dio.h"
/* Uart configuration*/
static const UART_Config_t Tps92662uartConfig = 
{
   
    .baudRate = 500000,               /* buard rate */
    .dataBits = UART_DATABITS_8,    /* data size */
    .parity = UART_PARITY_NONE,     /* parity */
    .stopBits = UART_STOPBITS_1,    /* stop bit */
    .autoFlowControl = DISABLE,     /* flow control */
    .oscFreq = 24000000             /* EB mcu mode uart clock*/
};

static const UART_Config_t Max25608uartConfig = 
{
   
    .baudRate = 500000,               /* buard rate */
    .dataBits = UART_DATABITS_8,    /* data size */
    .parity = UART_PARITY_EVEN,     /* parity */
    .stopBits = UART_STOPBITS_1P5_2,    /* stop bit */
    .autoFlowControl = DISABLE,     /* flow control */
    .oscFreq = 24000000             /* EB mcu mode uart clock*/
};

/* uart fifo config */
static const UART_FIFOConfig_t fifoConfig = 
{   
    .fifoEnable = ENABLE,               /* Enable FIFO */
    .txFifoReset = ENABLE,              /* Reset tx FIFO */
    .rxFifoReset = ENABLE,              /* Reset rx FIFO */
    .fifoTet = UART_TX_FIFO_QUARTER,       /* FIFO 1/4 full */
    .fifoRt = UART_RX_FIFO_CHAR_1      
 
};

/*
static UART_IdleDetectConfig_t IdleDetectConfig=
{
    .Cmd = ENABLE,
    .len = UART_IDLE_DETECT_LENGTH_64
};
*/
/**
 * @brief Source buffer.
*/
/*#pragma location = 0x20000000 */
static uint8 Uart1_TxBuffer[30];
static uint8 Uart1_RxBuffer[30];

static uint8 Uart0_TxBuffer[30];
static uint8 Uart0_RxBuffer[30];

/**
 * @brief     Uart0 initialization
 *      
 */
void Uart0Drv_Init(uint8 type)
{
    /*Port_Cfg.h*/
    /*first pinmux as gpio*/
    Port_SetPinMode(PortConf_PortPin_CAN_RX_S, PORT_PIN_MODE_GPIO);  
    Port_SetPinMode(PortConf_PortPin_CAN_TX_S, PORT_PIN_MODE_GPIO);
    /*When UART re-open after close, need to check and clear busy status*/
    while(SUCC !=UART_WaitBusyClear(UART0_ID, 7000))
    {
        (void)UART_ReceiveByte(UART0_ID);
    }
    if(0==type){
        UART_Init(UART0_ID,&Tps92662uartConfig);
    }else{
        UART_Init(UART0_ID,&Max25608uartConfig);
    }

    /*uart fifo config */
    UART_FIFOConfig(UART0_ID, &fifoConfig);
    
    /*UART_IdleDetectConfig(UART0_ID,&IdleDetectConfig);*/

    Dma_SetDestAddr(DMA_LOGIC_CH_0, 0x4006A000);  /*uart0 tx*/
    Dma_SetSourceAddr(DMA_LOGIC_CH_1, 0x4006A000);/*uart0 Rx*/
    UART_EmptyRxFifo(UART0_ID);
    /*pinmux as uart pin*/
    Port_SetPinMode(PortConf_PortPin_CAN_RX_S, PORT_DRV_PIN_MODE_ALT5);  
    Port_SetPinMode(PortConf_PortPin_CAN_TX_S, PORT_DRV_PIN_MODE_ALT5);

}
/**
 * @brief     Uart1 initialization
 *      
 */
void Uart1Drv_Init(uint8 type)
{
    /*Port_Cfg.h*/
    /*first pinmux as gpio*/
    Port_SetPinMode(PortConf_PortPin_CAN_RX_S_ADB_Master, PORT_PIN_MODE_GPIO);  
    Port_SetPinMode(PortConf_PortPin_CAN_TX_S_ADB_Master, PORT_PIN_MODE_GPIO);

    /*When UART re-open after close, need to check and clear busy status*/
    while(SUCC !=UART_WaitBusyClear(UART1_ID, 7000))
    {
        (void)UART_ReceiveByte(UART1_ID);
    }
    if(0==type){
        UART_Init(UART1_ID,&Tps92662uartConfig);
    }else{
        UART_Init(UART1_ID,&Max25608uartConfig);
    }
    /*uart fifo config */
    UART_FIFOConfig(UART1_ID, &fifoConfig);
    
    
    /*UART_IdleDetectConfig(UART1_ID,&IdleDetectConfig);*/
    

    Dma_SetDestAddr(DMA_LOGIC_CH_2, 0x4006B000);  /*uart1 tx*/
    Dma_SetSourceAddr(DMA_LOGIC_CH_3, 0x4006B000);/*uart1 Rx*/
 
    /*pinmux as uart pin*/
    Port_SetPinMode(PortConf_PortPin_CAN_RX_S_ADB_Master, PORT_DRV_PIN_MODE_ALT2);  
    Port_SetPinMode(PortConf_PortPin_CAN_TX_S_ADB_Master, PORT_DRV_PIN_MODE_ALT2);
    
    
}


Std_ReturnType Uart_AsyncSend(uint8 ch,uint8 *data,uint8 len) /*ch0 uart0tx,ch1 uart1tx*/
{
    if(ch == 0)  /*uart0 tx*/
    {
        Dma_SetSourceAddr(DMA_LOGIC_CH_0, (uint32)data);
        Dma_Drv_SetMinorLoopNum(DMA_DRV_PHYS_CH_12, len);
        Dma_EnableChannelHwRequest(DMA_LOGIC_CH_0,TRUE);

    }
    else if(ch == 1)
    {
        Dma_SetSourceAddr(DMA_LOGIC_CH_2, (uint32)data);
        Dma_Drv_SetMinorLoopNum(DMA_DRV_PHYS_CH_14, len);
        Dma_EnableChannelHwRequest(DMA_LOGIC_CH_2,TRUE);
    }
    return E_OK;

}


Std_ReturnType Uart_AsyncReceive(uint8 ch,uint8 *data,uint8 len) /*ch0 uart0rx,ch1 uart1rx*/
{
/*
    uint8 MinorLoopNum = (len >> 2);
    if(len - (MinorLoopNum<<2))
        MinorLoopNum++;
*/
    if(ch == 0)  /*uart0 rx */
    {
        Dma_SetDestAddr(DMA_LOGIC_CH_1, (uint32)data);
        Dma_Drv_SetMinorLoopNum(DMA_DRV_PHYS_CH_13, len);
        UART_ResetRxFifo(UART0_ID);
        Dma_EnableChannelHwRequest(DMA_LOGIC_CH_1,TRUE);

    }
    else if(ch == 1) /*uart1 rx */
    {
        Dma_SetDestAddr(DMA_LOGIC_CH_3, (uint32)data);
        Dma_Drv_SetMinorLoopNum(DMA_DRV_PHYS_CH_15, len);
        UART_ResetRxFifo(UART1_ID);
        Dma_EnableChannelHwRequest(DMA_LOGIC_CH_3,TRUE);
    }
    
    return E_OK;
    
}


void uart_test(void)
{
    uint8 i=0;
    for( i= 0; i < 30; i++)
    {
        Uart1_TxBuffer[i] = i;
        Uart1_RxBuffer[i] = i;
    }
    Uart_AsyncReceive(1,Uart1_RxBuffer,8);
    Uart_AsyncSend(1,Uart1_TxBuffer,30);
}

