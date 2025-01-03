/**
 * @file LossDerate_Interface.h
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-05-07
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-05-07 <td>0.1     <td>QinHaigang <td>
 * </table>
 */

#ifndef _LOSSDERATE_INTERFACE_H_
#define _LOSSDERATE_INTERFACE_H_

typedef union _DerateLightFlg_
{
    struct {
    uint16_t    D00_LB      :1;     /* 00 Low Beam */
    uint16_t    D01_TI      :1;     /* 01 Trun Indicator */
    uint16_t    D02_POS     :1;     /* 02 POSition light */
    uint16_t    D03_SML     :1;     /* 03 Side Marker Light */
    uint16_t    D04_HB      :1;     /* 04 Hight Beam */
    uint16_t    D05_DRL     :1;     /* 05 Day Running Light */
    uint16_t    D06_CORN    :1;     /* 06 CORNering */
    uint16_t    D07_FOG     :1;     /* 07 FOG (AWL) */
    uint16_t    D08_CROS    :1;     /* 08 front CROSS lamp */
    uint16_t    D09_GRIL    :1;     /* 09 GRILle light */
    uint16_t    D10_LOGO    :1;     /* 10 LOGO light */
    uint16_t    D11_WELC    :1;     /* 11 WELCome/goodbye light */
    uint16_t    D12_SHOW    :1;     /* 12 light SHOW */
    }           bit;
    uint16      val;
}S_DerateLight_t;

typedef enum _DerateLightPri_
{
    D00_LB      = 0,                /* 00 Low Beam */
    D01_TI      ,                   /* 01 Trun Indicator */
    D02_POS     ,                   /* 02 POSition light */
    D03_SML     ,                   /* 03 Side Marker Light */
    D04_HB      ,                   /* 04 Hight Beam */
    D05_DRL     ,                   /* 05 Day Running Light */
    D06_CORN    ,                   /* 06 CORNering */
    D07_FOG     ,                   /* 07 FOG (AWL) */
    D08_CROS    ,                   /* 08 front CROSS lamp */
    D09_GRIL    ,                   /* 09 GRILle light */
    D10_LOGO    ,                   /* 10 LOGO light */
    D11_WELC    ,                   /* 11 WELCome/goodbye light */
    D12_SHOW    ,                   /* 12 light SHOW */
    NUM_DER_LGT                     /* Number of Derate Lighting */
}E_DerateLight_t;


extern 
uint8_t Interface_GetChannelDerateRatioOfLoss(E_ChannelID id);

extern 
uint16_t Interface_GetDerateLightChannelMask(E_DerateLight_t dl);

extern 
int Interface_IsLoss(void);

extern 
void LossDerateMainFunction(uint8_t timebase, S_DerateLight_t dlf);

#endif  /* _LOSSDERATE_INTERFACE_H_ */