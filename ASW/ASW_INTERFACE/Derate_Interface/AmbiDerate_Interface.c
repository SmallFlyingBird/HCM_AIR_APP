
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AmbiDerate_Interface.h"
#include "NtcRcod_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

#define EnviromentTempNumMax      30
#define E_TEMPDERATE_START        140
#define E_TEMPDERATE_STOP         155
#define E_LOWEST_PWM              55

sint16 enviromenttemp=0; //return the temp+50

uint16 EnviromentTempList[EnviromentTempNumMax][2]=
{
/* temp   ADC_vol */ 
    {-40 ,4087 },
    {20  ,3800 },
    {25  ,3723 },
    {30  ,3612 },
    {35  ,3523 },
    {40  ,3399 },
    {45  ,3258 },
    {50  ,3102 },
    {55  ,2932 },
    {60  ,2750 },
    {65  ,2560 },
    {70  ,2365 },
    {75  ,2169 },
    {80  ,1976 },
    {85  ,1789 },
    {90  ,1610 },
    {95  ,1443 },
    {100 ,1287 },
    {105 ,1144 },
    {110 ,1015 },
    {115 ,898  },
    {120 ,794  },
    {125 ,701  },
    {130 ,619  },
    {135 ,546  },
    {140 ,482  },
    {145 ,426  },
    {150 ,377  },
    {155, 326  },
    {160, 274  }
};



/* ===================================Enviroment NTC================================================== */
/* return the real temp+50 (temp from -49 to 149)*/
sint16 NTC_Calculate_Enviroment_Temp(void)
{
    uint8 i =0;
    uint16 datatmp;
    sint16 temperature = 160;
    Interface_GetAdcDigitalValue(E_AdcFunction_NTC7, &datatmp);

    if(datatmp>EnviromentTempList[0][1])
    {
        temperature = (-40);
    }
    else
    {
        for (i = 0; i < EnviromentTempNumMax; i++)
        {
            if (datatmp < EnviromentTempList[i][1] && datatmp >= EnviromentTempList[i + 1][1])
            {         
                temperature = EnviromentTempList[i][0];
                break;
            }
        }
    }

    /*return the temp value*/
    return temperature;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

uint8 AmbiDerateMainFunction(void)
{
    uint8 derate=0;
    enviromenttemp=NTC_Calculate_Enviroment_Temp();/*get the temp */
/* 环境温度降额策略：
按90度-105度环境温度，电源NTC采集温度140-155度（超过155度，只保留近光灯），输出功率由100%降到55%，折合降额比例为3%/℃，单步降额1%，每100ms降额一次 */
    if((enviromenttemp>=E_TEMPDERATE_START)&&(enviromenttemp<=E_TEMPDERATE_STOP))/* linear derate */
    {
        derate = (E_TEMPDERATE_STOP-enviromenttemp)*((100-E_LOWEST_PWM)/(E_TEMPDERATE_STOP-E_TEMPDERATE_START))+55;
    }
    else if(enviromenttemp > E_TEMPDERATE_STOP)
    {
        derate = 0;
    }
    else
    {
        derate = 100;
    }

    /* derate: the persent of current output that should be achieced */
    return derate;
}
 

sint16 Interface_GetEnviroment(void)
{
    return enviromenttemp;
}










