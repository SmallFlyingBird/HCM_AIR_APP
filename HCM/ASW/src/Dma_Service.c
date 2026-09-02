
#include "Std_Types.h"
uint8 uart0_done = 0;
void DMA_CH13_Major_Finish(void){
    uart0_done = 1;
}

void DMA_CH15_Major_Finish(void){
    /*uart1_done = 1;*/
}