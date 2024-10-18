

#ifndef _DEBUG_MONI_H_
#define _DEBUG_MONI_H_

/* 0~63 */
typedef enum _Dmoni_
{
    D_NONE = 0,     /* 保留-模块控制 */
    D_EPTEST,       /* 电性能测试 */
    D_DEBUG_VAR,    /* 临时调试用，仅用于单功能的调试 */
    D_LIGHTING,     /* 点灯调试 */
    D_DERATING,     /* 降额监控 */
    D_MOTOR,        /* 电机监控 */
    D_AFS,
    D_VEHINFO,      /* 车辆信息 */
    D_AHBCOBJ,      /* AHBC Object */
}E_Dmoni_t;

extern unsigned char dmoni_rx[64][8];
extern unsigned char dmoni_tx[64][8];

#define DMONI_FUN(F)      (((dmoni_rx[F][0] & 0x7e) >> 1) == F)     /*  */
#define DMONI_SUB(F)       ((dmoni_rx[F][7] & 0x70) >> 4)           /*  */




extern 
void DMoni_Init(void);

extern 
void DMoni_Run1S(void);

extern
void DMoni_Run10ms(void);

#endif  /* _DEBUG_MONI_H_ */