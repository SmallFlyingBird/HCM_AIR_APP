
#include "Can.h"
#include "CanIf.h"

#include "HcmPlatform.h"
#include "GeneralFunction.h"

#include "DMoni.h"

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
uint32_t dmoni_rxcanid;
uint32_t dmoni_rxnumber;
uint8_t  dmoni_rxcanfr[8];

unsigned char dmoni_rx[64][8];
unsigned char dmoni_tx[64][8];

typedef struct _DmoniCtl_
{
    unsigned char rx8[8];
    unsigned char tx8[8];

    unsigned int    st_400ms;
    unsigned char   st_400msOffOn1  :1;

    /* 回复 */
    uint16_t    st_replay;  /* 500ms到计时，发送回复 */
    E_Dmoni_t   st_moni;    /* 当前接收的DMONI功能 */

}S_DmoniCtl_t;

static S_DmoniCtl_t dmonictl, *_ctl = 0;



void DMoni_Init(void)
{
    C_Memset_B((unsigned char*)(&dmonictl), 0, sizeof(S_DmoniCtl_t));

    dmoni_rxnumber = 0;
#if (HCM_LEFT_SIDE)
    dmoni_rxcanid = 0x596;
#else
    dmoni_rxcanid = 0x594;
#endif

#if 0
    /*  */
    dmoni_rx[D_EPTEST][0] = 0x02;
    dmoni_rx[D_EPTEST][1] = 0xFF;
    dmoni_rx[D_EPTEST][2] = 0xFF;
    dmoni_rx[D_EPTEST][3] = 0xFF;
    dmoni_rx[D_EPTEST][4] = 0x00;
    dmoni_rx[D_EPTEST][5] = 0x00;
    dmoni_rx[D_EPTEST][6] = 0x00;
    dmoni_rx[D_EPTEST][7] = 0x02;
#endif

    _ctl = (&dmonictl);
}

void DMoni_Run1S(void)
{
    E_Dmoni_t moni;
    uint8_t   opt;
    int i;

    if (_ctl == 0) { return; }

    if (dmoni_rxnumber == 0) { return; }

    /* 获取调试数据 */
    C_Memcpy_B(&(_ctl->rx8[0]), &(dmoni_rxcanfr[0]), 8);

    /* 接收校验后 赋值 */
    if (((_ctl->rx8[0] & 0x01) == (_ctl->rx8[7] & 0x01))  &&
        ((_ctl->rx8[0] & (0x01<<7)) == (_ctl->rx8[7] & (0x01<<7))))
    {
        
        moni = (_ctl->rx8[0] & 0x7e) >> 1;
        opt  = (_ctl->rx8[7] & 0x0e) >> 1;

        dmoni_tx[moni][0] = dmoni_rx[moni][0] = _ctl->rx8[0];
        dmoni_tx[moni][7] = dmoni_rx[moni][7] = _ctl->rx8[7];

        /* RX */
        switch(opt)
        {
        case 0: C_Memset_B(&(dmoni_rx[moni][0]), 0, 8);                        break; /* B7~B0 全部清零 */
        case 1: C_Memcpy_B(&(dmoni_rx[moni][1]), &(_ctl->rx8[1]), 6);          break; /* B6~B1 全部设置 */
        case 2: for (i=1; i<=6; i++) { dmoni_rx[moni][i] &= ~(_ctl->rx8[i]); } break; /* 掩码位清零，非掩码位不操作 */
        case 3: for (i=1; i<=6; i++) { dmoni_rx[moni][i] |= _ctl->rx8[i]; }    break; /* 掩码位置1， 非掩码位不操作 */
        default:;
        }

        /* TX */
        _ctl->st_replay = 500;
        _ctl->st_moni = moni;
    }

    dmoni_rxnumber = 0;
}

void DMoni_Run10ms(void)
{
    int i;
    uint8_t   opt;
    Can_PduType pdu;

    if (_ctl == 0) { return; }


    /*  */
    if (_ctl->st_400ms < 400) { _ctl->st_400msOffOn1 = 0; }
    else                      { _ctl->st_400msOffOn1 = 1; }
    /*  */
    opt = (dmoni_rx[D_EPTEST][7] & 0x0e) >> 1;
    if (opt == 4)
    {
        if (_ctl->st_400msOffOn1)
        { for (i=1; i<=6; i++) { dmoni_rx[D_EPTEST][i] |= _ctl->rx8[i]; } }
        else
        { for (i=1; i<=6; i++) { dmoni_rx[D_EPTEST][i] &= ~(_ctl->rx8[i]); } }
    }


    /*  */
    _ctl->st_400ms += 10;
    if (_ctl->st_400ms >= 800) { _ctl->st_400ms = 0; }



    /* 判断是否需要倒计时回复 */
    if(_ctl->st_replay > 0)
    {
        _ctl->st_replay = C_SubToMin_U16(_ctl->st_replay, 10);
        
        if (_ctl->st_replay == 0)   /* 减到0发送1次 */
        {
            C_Memcpy_B(&(_ctl->tx8[0]), dmoni_tx[_ctl->st_moni], 8);

            /* 发送调试数据 */
            pdu.id = 0x666;
            pdu.length = 8;
            pdu.swPduHandle = 0;
            pdu.sdu = _ctl->tx8;
#if (HCM_LEFT_SIDE)
            Can_Write(CanConf_CanHardwareObject_HcmltoEtcXCPFr01, &pdu);
#else
            Can_Write(CanConf_CanHardwareObject_HcmrtoEtcXCPFr01, &pdu);
#endif
        }
    }
}




#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */
