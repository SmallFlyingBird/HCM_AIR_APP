
#ifndef _LIGHTING_IOCTR_ASW_H_
#define _LIGHTING_IOCTR_ASW_H_

typedef struct _DiagIOCtr_CHN_
{
    uint8_t     ctr;    /*0:Release; 2:Freeze; 3:Set; Oth:n/a (E_IOCtrType)*/
    uint8_t     mask;   /*0x40:set cur; 0x80: set pwm*/
    uint8_t     pwm;
    uint16_t    cur;
}S_DiagIOCtr_CHN_t;

extern 
S_DiagIOCtr_CHN_t diagioctr_chn[MAX_CHANNLE_NUM];


#define MAX_ADBPIXNUM     (84)

typedef struct _DiagIOCtr_ADBPIX_
{
    uint8_t     ctr;    /*0:Release; 2:Freeze; 3:Set; Oth:n/a (E_IOCtrType)*/
    uint8_t     mask[(MAX_ADBPIXNUM/8)+1];  /*bit==1: set; bit==0: not set*/
    uint8_t     pix[MAX_ADBPIXNUM];
}S_DiagIOCtr_ADBPIX_t;

extern
S_DiagIOCtr_ADBPIX_t diagioctr_adbpix;

#endif  /*_LIGHTING_IOCTR_ASW_H_*/