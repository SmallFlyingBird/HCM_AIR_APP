/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dio.h"
#include "Spi_Service.h"

void SpiJob_Buck1Start(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS1,STD_LOW);
}
void SpiJob_Buck1End(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS1,STD_HIGH);
}
void SpiJob_Buck2Start(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS2,STD_LOW);
}
void SpiJob_Buck2End(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS2,STD_HIGH);
}
