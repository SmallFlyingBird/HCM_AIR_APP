#ifndef _LIGHTING__H_
#define _LIGHTING__H_

typedef enum{
	E_LB=1,
	E_HB=2,
	E_DRL=1,
	E_POS=2,
	E_TI=4,
}CH_LightOn; //用于标志某个通道打开某个灯,4个通道接了6个通道的灯，需要打开某个通道后关闭对应通道的灯

typedef enum _LgtAct_
{
    ACT_OFF = 0,    /* off */
    ACT_ON          /* on */
}E_LgtAct_t;

typedef union _DisSrc_
{
    struct {
    uint8_t sp_los     :1;     /* Power supply KL15/KL56 Lost one */
    uint8_t sp_ouv     :1;     /* Power supply over/under voltage */
    uint8_t ot_chn     :1;     /* Buck Over Temperature */
    uint8_t ot_led     :1;     /* Led board Over Temperature */
    uint8_t ot_amb     :1;     /* Ambient Temperature Over */
    uint8_t mo_N_1     :1;     /* N-1 mode */
    uint8_t ns_busoff  :1;     /* net bus off */
    } bits;
    uint8_t val;
}U_DisSrc_t;

/**
 * @brief Lighting Function Enable Flag (see E_LgtEna_t define)
 */
typedef struct _LgtFuncEna_
{
    uint8    EnaLB       :1;     /* Low Beam */
    uint8    EnaTI       :1;     /* Trun Indicator */
    uint8    EnaPOS      :1;     /* POSition light */
    uint8    EnaHB       :1;     /* Hight Beam */
    uint8    EnaDRL      :1;     /* Day Running Light */
    uint8    EnaCROS     :1;     /* front CROSS lamp */
    uint8    EnaWELC     :1;     /* WELCome/goodbye light */

    uint8    EnaPOS_Dyn  :1;     /* POSition light   Dynamic */
    uint8    EnaCROS_Dyn :1;     /* front CROSS lamp Dynamic */
}S_LgtFuncEna_t;

typedef struct _PR_POSDRLTL_
{
    uint16   Pr_DRL_TI_surfaces_Near_W      ;  // 日行 转向 近发光面 
    uint16   Pr_DRL_TI_surfaces_apparent_W  ;  // 日行 转向 共发光面
    uint16   Pr_POS_TI_surfaces_apparent_W  ;  // 位置 转向 工发光面
}PR_POSDRLTL;

/**
 * @brief Lighting Act Instruction (see E_LgtAct_t define)
 */
typedef struct _LgtActSignal_
{
    uint8    ActLB       :1;
    uint8    ActTIsts    :1;
    uint8    ActTIact    :1;
    uint8    ActPOS      :1;
    uint8    ActHB       :1;
    uint8    ActDRL      :1;
    uint8    ActCROS     :1;
}S_LgtActIns_t;

/**
 * @brief Lighting Act Status Feedback (see E_LgtSts_t define)
 */
typedef enum _LgtSts_
{
    STS_OFF = 0,    /* off */
    STS_ON,         /* on */
    STS_ERR,        /* error */
    STS_Res         /* reserve */
}E_LgtSts_t;

typedef union
{
    uint16 Light_Status;
    struct
    {
        uint8    StsLB       :2;
        uint8    StsTI       :2;
        uint8    StsPOS      :2;
        uint8    StsHB       :2;
        uint8    StsDRL      :2;
        uint8    StsCORN     :2;
        uint8    StsCROS     :2;
        uint8    StsWELC     :2;
    }Bits;
}S_LgtStsFb_t;

void SetLgtStsFb_LB  (E_LgtSts_t sts);
void SetLgtStsFb_TI  (E_LgtSts_t sts);
void SetLgtStsFb_POS (E_LgtSts_t sts);
void SetLgtStsFb_HB  (E_LgtSts_t sts);
void SetLgtStsFb_DRL (E_LgtSts_t sts);
void SetLgtStsFb_CORN(E_LgtSts_t sts);
void SetLgtStsFb_CROS(E_LgtSts_t sts);
void SetLgtStsFb_WELC(E_LgtSts_t sts);

uint8 Lighting_GetAct(Light_Functions lf);
uint16 Lighting_Rek_Fun(void);
Std_ReturnType Light_Manager(uint8 timebase);
Std_ReturnType Lighting_Init(void);
Std_ReturnType ReadBack_LightStatus(uint16 *bufsts);
Std_ReturnType Lighting_SetPwmRamp(Light_Functions lf);
#endif  /* _LIGHTING__H_ */


