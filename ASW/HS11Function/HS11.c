#include "HcmPlatform.h"
#include "Std_Types.h"
#include "McalLib.h"
#include "Channel_Interface.h"

void HS11MainFuncion(uint8 *CanReceiveData)
{
    uint16_t channelMask;
    uint8_t i = 0;
    uint8 id = 0;
    uint8 function = 0;
    static uint8 DRLStatus = 0;
    static uint16 FunOpenCurrent[12] = {968, 934, 185, 963, 66, 0, 0, 0, 0, 0, 0, 0};

    channelMask = (((uint16_t)CanReceiveData[1]) << 8) + ((uint16_t)CanReceiveData[0]);

    for (function = 0; function <= 4; function++)
    {
        switch (function)
        {
            /*LB*/
        case 0:
            if (CanReceiveData[0] != 0)
            {
                Interface_SetChannelPWM(ChannelID1, 100);
                Interface_SetChannelCurrent(ChannelID1, FunOpenCurrent[function]);
                Interface_SetChannelSwitchState(ChannelID1, CHANNEL_STATE_ON);
            }
            else
            {
                Interface_SetChannelSwitchState(ChannelID1, CHANNEL_STATE_OFF);
            }
            break;
            /*ADB*/
        case 1:
            if (CanReceiveData[1] != 0)
            {
                Interface_SetChannelPWM(ChannelID2, 100);
                Interface_SetChannelCurrent(ChannelID2, FunOpenCurrent[function]);
                Interface_SetChannelSwitchState(ChannelID2, CHANNEL_STATE_ON);
            }
            else
            {
                Interface_SetChannelSwitchState(ChannelID2, CHANNEL_STATE_OFF);
            }
            break;
        /*PL_Up and TI*/
        case 2:
/*status managent*/
#if 1
            if (CanReceiveData[2] > 2)
            {
                CanReceiveData[2] = 0;
            }
            if (DRLStatus == 0)
            {
                DRLStatus = CanReceiveData[2];
            }
            else if (DRLStatus != CanReceiveData[2])
            {
                DRLStatus = 0;
            }
            else
            {
                DRLStatus = CanReceiveData[2];
            }

            if (DRLStatus == 1)
            {
                Interface_SetChannelPWM(ChannelID3, 100);
                Interface_SetChannelPWM(ChannelID4, 100);
                Interface_SetChannelPWM(ChannelID5, 100);
                Interface_SetChannelCurrent(ChannelID3, FunOpenCurrent[function]);
                Interface_SetChannelCurrent(ChannelID4, FunOpenCurrent[function]);
                Interface_SetChannelCurrent(ChannelID5, FunOpenCurrent[function]);
                Interface_SetChannelSwitchState(ChannelID3, CHANNEL_STATE_ON);
                Interface_SetChannelSwitchState(ChannelID4, CHANNEL_STATE_ON);
                Interface_SetChannelSwitchState(ChannelID5, CHANNEL_STATE_ON);
            }
            else if (DRLStatus == 2)
            {
                Interface_SetChannelPWM(ChannelID3, 100);
                Interface_SetChannelPWM(ChannelID4, 100);
                Interface_SetChannelPWM(ChannelID5, 100);
                Interface_SetChannelCurrent(ChannelID3, FunOpenCurrent[function]);
                Interface_SetChannelCurrent(ChannelID4, FunOpenCurrent[function]);
                Interface_SetChannelCurrent(ChannelID5, FunOpenCurrent[function]);
                Interface_SetChannelSwitchState(ChannelID3, CHANNEL_STATE_ON);
                Interface_SetChannelSwitchState(ChannelID4, CHANNEL_STATE_ON);
                Interface_SetChannelSwitchState(ChannelID5, CHANNEL_STATE_ON);
            }
            else
            {
                Interface_SetChannelSwitchState(ChannelID3, CHANNEL_STATE_OFF);
                Interface_SetChannelSwitchState(ChannelID4, CHANNEL_STATE_OFF);
                Interface_SetChannelSwitchState(ChannelID5, CHANNEL_STATE_OFF);
            }

#endif
            break;
            /*Corner lamp*/
        case 3:
            if (CanReceiveData[3] != 0)
            {
                Interface_SetChannelPWM(ChannelID6, 100);
                Interface_SetChannelCurrent(ChannelID6, FunOpenCurrent[function]);
                Interface_SetChannelSwitchState(ChannelID6, CHANNEL_STATE_ON);
            }
            else
            {
                Interface_SetChannelSwitchState(ChannelID6, CHANNEL_STATE_OFF);
            }
            break;
            /*PL_Dowm*/
        case 4:
            if (CanReceiveData[4] != 0)
            {
                for (i = 0; i < 5; i++)
                {
                    ChannelPWMDataSrc[i] = 0;
                }
                for (i = 5; i < 11; i++)
                {
                    ChannelPWMDataSrc[i] = 100;
                }

                // Interface_SetMatrixChipChannelPwm(1, ChannelPWMDataSrc);
                // Interface_SetMatrixChipChannelPwm(2, ChannelPWMDataSrc);
                Interface_SetChannelPWM(ChannelID7, 100);
                Interface_SetChannelPWM(ChannelID8, 100);
                Interface_SetChannelCurrent(ChannelID7, FunOpenCurrent[function]);
                Interface_SetChannelCurrent(ChannelID8, FunOpenCurrent[function]);
                Interface_SetChannelSwitchState(ChannelID7, CHANNEL_STATE_ON);
                Interface_SetChannelSwitchState(ChannelID8, CHANNEL_STATE_ON);
            }
            else
            {
                Interface_SetChannelSwitchState(ChannelID7, CHANNEL_STATE_OFF);
                Interface_SetChannelSwitchState(ChannelID8, CHANNEL_STATE_OFF);
            }

            break;
        }
    }
}
