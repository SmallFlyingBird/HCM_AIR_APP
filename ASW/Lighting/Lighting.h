/**
 * @file Lighting.h
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-05-06 <td>0.1     <td>QinHaigang <td>
 * </table>
 */
#ifndef _LIGHTING__H_
#define _LIGHTING__H_

/**
 * @brief Lighting's L/R flag
 */
typedef enum _FlgLR_
{
    LR_LE = 0,
    LR_RI
}E_FlgLR_t;

extern 
E_FlgLR_t Get_FlgLR(void);

/**
 * @brief Lighting Function Enable Flag
 */
typedef enum _LgtEna_
{
    ENA_OFF = 0,    /* disable */
    ENA_ON          /* enable */
}E_LgtEna_t;

/**
 * @brief Lighting Act Instruction
 */
typedef enum _LgtAct_
{
    ACT_OFF = 0,    /* off */
    ACT_ON          /* on */
}E_LgtAct_t;

/**
 * @brief Lighting Act Status Feedback
 */
typedef enum _LgtSts_
{
    STS_OFF = 0,    /* off */
    STS_ON,         /* on */
    STS_ERR,        /* error */
    STS_Res         /* reserve */
}E_LgtSts_t;

typedef enum _camsts_
{
    CAM_IDLE = 0,   /* Idel */
    CAM_NOR,        /* Normal */
    CAM_BLOCK,      /* Blocking */
    CAM_UNK         /* Unknown */
}E_CAMSTS_t;

typedef enum _sigsts_
{
    SST_INI = 0,    /*  */
    SST_OK,
    SST_E_CRC,      /* 校验错误 */
    SST_E_CNT,      /* 计数错误 */
    SST_E_OVR,      /* 超时错误 */
}E_SST_t;

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
    uint32_t    EnaLB       :1;     /* Low Beam */
    uint32_t    EnaTI       :1;     /* Trun Indicator */
    uint32_t    EnaPOS      :1;     /* POSition light */
    uint32_t    EnaHB       :1;     /* Hight Beam */
    uint32_t    EnaDRL      :1;     /* Day Running Light */
    uint32_t    EnaCROS     :1;     /* front CROSS lamp */
    uint32_t    EnaWELC     :1;     /* WELCome/goodbye light */

    uint32_t    EnaPOS_Dyn  :1;     /* POSition light   Dynamic */
    uint32_t    EnaCROS_Dyn :1;     /* front CROSS lamp Dynamic */

    uint32_t    res         :13;
}S_LgtFuncEna_t;

/**
 * @brief Lighting Act Instruction (see E_LgtAct_t define)
 */
typedef struct _LgtActSignal_
{
    uint32_t    ActLB       :1;
    uint32_t    ActTIsts    :1;
    uint32_t    ActTIact    :1;
    uint32_t    ActTInoseq  :1;
    uint32_t    ActPOS      :1;
    uint32_t    ActHB       :1;
    uint32_t    ActDRL      :1;
    uint32_t    ActCROS     :1;
    uint32_t    ActWELC     :1;
    uint32_t    res         :10;
}S_LgtActIns_t;

/**
 * @brief Lighting Act Status Feedback (see E_LgtSts_t define)
 */
typedef struct _LgtStsFb_
{
    uint32_t    StsLB       :2;
    uint32_t    StsTI       :2;
    uint32_t    StsPOS      :2;
    uint32_t    StsHB       :2;
    uint32_t    StsDRL      :2;
    uint32_t    StsCORN     :2;
    uint32_t    StsCROS     :2;
    uint32_t    StsWELC     :2;

    uint32_t    res         :31;
}S_LgtStsFb_t;


/**
 * @brief Get S_LgtFuncEna_t data
 * 
 * @param ena, pointer to S_LgtFuncEna_t data for Get
 * @return 0:OK; not 0:Error
 */
extern 
int GetLgtFuncEna(S_LgtFuncEna_t *ena);

/**
 * @brief Get U_DisSrc_t data
 * 
 * @param ds, pointer to U_DisSrc_t data for Get
 * @return 0:OK; not 0:Error
 */
extern void GetLgtFuncDisSrc_LB       (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_TI       (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_POS      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_HB       (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_DRL      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_CROS     (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_WELC     (U_DisSrc_t *ds);

extern void GetLgtFuncDisSrc_POS_Dyn  (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_CROS_Dyn (U_DisSrc_t *ds);

/**
 * @brief Get S_LgtActIns_t data
 * 
 * @param act: pointer to S_LgtActIns_t data for Get
 * @return 0:OK; not 0:Error
 */
extern 
int GetLgtActIns(S_LgtActIns_t *act);

/**
 * @brief Get S_LgtStsFb_t data
 * 
 * @param sts: pointer to S_LgtStsFb_t data for Get
 * @return 0:OK; not 0:Error
 */
extern 
int GetLgtStsFb(S_LgtStsFb_t *sts);

extern void SetLgtStsFb_LB  (E_LgtSts_t sts);
extern void SetLgtStsFb_TI  (E_LgtSts_t sts);
extern void SetLgtStsFb_POS (E_LgtSts_t sts);
extern void SetLgtStsFb_HB  (E_LgtSts_t sts);
extern void SetLgtStsFb_DRL (E_LgtSts_t sts);
extern void SetLgtStsFb_CORN(E_LgtSts_t sts);
extern void SetLgtStsFb_CROS(E_LgtSts_t sts);
extern void SetLgtStsFb_WELC(E_LgtSts_t sts);

/* 在当前开命令周期内 设置禁止 */
extern void SetLgtOnDis_LB  (void);
extern void SetLgtOnDis_TI  (void);
extern void SetLgtOnDis_POS (void);
extern void SetLgtOnDis_HB  (void);
extern void SetLgtOnDis_DRL (void);
extern void SetLgtOnDis_CORN(void);
extern void SetLgtOnDis_CROS(void);
extern void SetLgtOnDis_WELC(void);


#define FEEDERR_LATE    (0) /* 故障确认后再反馈 */


void Light_Manager(uint8 timebase);
void Light_Parameter_Init(void);

#endif  /* _LIGHTING__H_ */


