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
void SpiJob_Buck3Start(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS3,STD_LOW);
}
void SpiJob_Buck3End(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS3,STD_HIGH);
}
void SpiJob_Buck4Start(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS4,STD_LOW);
}
void SpiJob_Buck4End(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS4,STD_HIGH);
}
void SpiJob_BoostStart(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS_BOOST,STD_LOW);
}
void SpiJob_BoostEnd(void){
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS_BOOST,STD_HIGH);
}
void SpiJob_Motor1Start(void){
    Dio_WriteChannel(DioConf_DioChannel_CS_AFS,STD_LOW);
}
void SpiJob_Motor1End(void){
    Dio_WriteChannel(DioConf_DioChannel_CS_AFS,STD_HIGH);
}
void SpiJob_Motor2Start(void){
    Dio_WriteChannel(DioConf_DioChannel_CS_ALS,STD_LOW);
}
void SpiJob_Motor2End(void){
    Dio_WriteChannel(DioConf_DioChannel_CS_ALS,STD_HIGH);
}
