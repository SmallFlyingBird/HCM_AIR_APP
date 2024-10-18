

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dio.h"
#include "Dio_Service.h"

void initializePort(void){
    /**
     * SBC_EN:
     * STD_HIGH: Enable
     * STD_LOW: Disable
    */
    Dio_WriteChannel(DioConf_DioChannel_SBC_EN,STD_HIGH);
    /**
     * SBC_STB: 
     * STD_HIGH: Normal mode or listen-only
     * STD_LOW: GO-TO-SLEEP or Standby mode*/
    Dio_WriteChannel(DioConf_DioChannel_SBC_STB,STD_HIGH);

    /**
     * Motor_DrvOFF: 
     * STD_HIGH: Disable device outputs
     * STD_LOW: Enable device outputs*/
    Dio_WriteChannel(DioConf_DioChannel_MotorOut_Con_ALS, STD_HIGH);
    /**
     * Motor_DrvOFF: 
     * STD_HIGH: Disable device outputs
     * STD_LOW: Enable device outputs*/
    Dio_WriteChannel(DioConf_DioChannel_MotorOut_Con_AFS, STD_HIGH);

    /**
     * Limp_Con:
     * STD_HIGH: disable BOOST limp home
     * STD_LOW: 
    */
    Dio_WriteChannel(DioConf_DioChannel_LIMP_CON,STD_HIGH);


    /**
     * EN_92682: 
     * STD_HIGH: Normal mode 
     * STD_LOW: DISABLE 92682*/
    Dio_WriteChannel(DioConf_DioChannel_EN_92682,STD_HIGH);

        /**
     * SPI_XXX: 
     * STD_HIGH: SPI PCS Idle   
     * STD_LOW: Do not set SPI PCS Low in init process
     * */
    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS1,STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS2,STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS3,STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS4,STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS_BOOST,STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_CS_AFS,STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_CS_ALS,STD_HIGH);

}
