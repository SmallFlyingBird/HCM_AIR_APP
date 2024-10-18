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

#define DEBUG_LIGHTING_XXX          (0) /* 调试总开关 */
#if (DEBUG_LIGHTING_XXX)
#define DEBUG_LIGHTING_LB           (0)
#define DEBUG_LIGHTING_HB           (0)
#define DEBUG_LIGHTING_AHB          (0)
#define DEBUG_LIGHTING_AHB2         (0)
#define DEBUG_LIGHTING_AFS          (0)
#define DEBUG_LIGHTING_ADB_HB       (0)
#define DEBUG_LIGHTING_TI           (0)
#define DEBUG_LIGHTING_DRL          (0)
#define DEBUG_LIGHTING_POS          (1)
#define DEBUG_LIGHTING_GRIL         (0)
#define DEBUG_LIGHTING_LAMPMANAGER  (0) /* 0:正式逻辑，取配置及降额电流; 1:强制固定电流，不降额 */
#define DEBUG_LIGHTING_LM_READ      (0)
#endif  /* DEBUG_LIGHTING_XXX */

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
 * @brief Car Usage-Mode (car net signal)
 */
typedef enum _UseMode_
{
    UM_ABDND   = 0x00,  /* Abandoned */
    UM_INACTV  = 0x01,  /* Inactive */
    UM_CNVINC  = 0x02,  /* Convenience */
    UM_ACTV    = 0x0B,  /* Active */
    UM_DRVG    = 0x0D   /* Driving */
}E_UseMode_t;


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


typedef enum _vcew_
{
    VCEW_U = 0, /* 无模式 */
    VCEW_V,     /* 城市模式TOW */
    VCEW_C,     /* 乡村模式CON */
    VCEW_E,     /* 高速模式MOT */
    VCEW_W      /* 天气模式AWL */
}E_VCEW_t;

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


typedef struct _AHBCObj_
{
    /* 信号不可信标识，0:可信; 1:不可信 */
    uint8_t e_Classn    :1;
    uint8_t e_OnCmng    :1;
    uint8_t e_Dist      :1;
    uint8_t e_res       :5;

    /* 主信号 */
    uint8_t CamSts      :2;     /* CameraStsforAHBC (E_CAMSTS_t) */
    uint8_t TooMany     :1;     /* TooManyCars      (0:No; 1:Yes) */
    uint8_t LitArea     :1;     /* LitArea          (0:No; 1:Yes) */

    /* 辅助信号 */
    uint8_t Classn      :3;     /* AdbClassn        (0:No; Other:Yes) */
    uint8_t B0_res1     :1;
    uint8_t OnCmng      :2;     /* 0:IDLE; 1:OnComming; 2:Preceding; 3:Others */
    uint8_t B1_res6     :6;

    uint16_t Dist;              /* AdbAbsDist       (0.01m) */


}S_AHBCObj_t;

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
    uint8_t ns_vhespd  :1;     /* net VehSpd signal error */
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
    uint32_t    EnaSML      :1;     /* Side Marker Light */
    uint32_t    EnaHB       :1;     /* Hight Beam */
    uint32_t    EnaDRL      :1;     /* Day Running Light */
    uint32_t    EnaCORN     :1;     /* CORNering */
    uint32_t    EnaFOG      :1;     /* FOG (AWL) */
    uint32_t    EnaCROS     :1;     /* front CROSS lamp */
    uint32_t    EnaGRIL     :1;     /* GRILle light */
    uint32_t    EnaLOGO     :1;     /* LOGO light */
    uint32_t    EnaWELC     :1;     /* WELCome/goodbye light */

    uint32_t    EnaMHL      :1;
    uint32_t    EnaAHL      :1;
    uint32_t    EnaDBL      :1;
    uint32_t    EnaAHBC     :1;
    uint32_t    EnaTOUR     :1;
    uint32_t    EnaAFS      :1;

    uint32_t    EnaPOS_Dyn  :1;     /* POSition light   Dynamic */
    uint32_t    EnaGRIL_Dyn :1;     /* GRILle light     Dynamic */
    uint32_t    EnaLOGO_Dyn :1;     /* LOGO light       Dynamic */
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
    uint32_t    ActSML      :1;
    uint32_t    ActHB       :1;
    uint32_t    ActDRL      :1;
    uint32_t    ActCORN     :1;
    uint32_t    ActFOG      :1;
    uint32_t    ActCROS     :1;
    uint32_t    ActGRIL     :1;
    uint32_t    ActLOGO     :1;
    uint32_t    ActWELC     :1;

    uint32_t    ActAHBC     :1;
    uint32_t    ActTOUR     :1;
    uint32_t    ActAFS      :1;
    uint32_t    ActWipr     :1;

    uint32_t    ActPOS_Dyn  :1;     /* POSition light   Dynamic */
    uint32_t    ActGRIL_Dyn :1;     /* GRILle light     Dynamic */
    uint32_t    ActLOGO_Dyn :1;     /* LOGO light       Dynamic */
    uint32_t    ActCROS_Dyn :1;     /* front CROSS lamp Dynamic */

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
    uint32_t    StsSML      :2;
    uint32_t    StsHB       :2;
    uint32_t    StsDRL      :2;
    uint32_t    StsCORN     :2;
    uint32_t    StsFOG      :2;
    uint32_t    StsCROS     :2;
    uint32_t    StsGRIL     :2;
    uint32_t    StsLOGO     :2;
    uint32_t    StsWELC     :2;

    uint32_t    StsAHBC     :2;
    uint32_t    StsTOUR     :2;
    uint32_t    StsAFS      :2;
    uint32_t    StsAFS_vcew :3; /* 0:Unknown; 1:V-town; 2:Country; 3:E-motorway; 4:Weather */
    
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
extern void GetLgtFuncDisSrc_SML      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_HB       (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_DRL      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_CORN     (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_FOG      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_CROS     (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_GRIL     (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_LOGO     (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_WELC     (U_DisSrc_t *ds);

extern void GetLgtFuncDisSrc_MHL      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_AHL      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_DBL      (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_AHBC     (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_TOUR     (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_AFS      (U_DisSrc_t *ds);

extern void GetLgtFuncDisSrc_POS_Dyn  (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_GRIL_Dyn (U_DisSrc_t *ds);
extern void GetLgtFuncDisSrc_LOGO_Dyn (U_DisSrc_t *ds);
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
extern void SetLgtStsFb_SML (E_LgtSts_t sts);
extern void SetLgtStsFb_HB  (E_LgtSts_t sts);
extern void SetLgtStsFb_DRL (E_LgtSts_t sts);
extern void SetLgtStsFb_CORN(E_LgtSts_t sts);
extern void SetLgtStsFb_FOG (E_LgtSts_t sts);
extern void SetLgtStsFb_CROS(E_LgtSts_t sts);
extern void SetLgtStsFb_GRIL(E_LgtSts_t sts);
extern void SetLgtStsFb_LOGO(E_LgtSts_t sts);
extern void SetLgtStsFb_WELC(E_LgtSts_t sts);

extern void SetLgtStsFb_AHBC(E_LgtSts_t sts);
extern void SetLgtStsFb_TOUR(E_LgtSts_t sts);
extern void SetLgtStsFb_AFS (E_LgtSts_t sts);

extern void SetLgtStsFb_AFS_VCEW (E_VCEW_t  vcew);

/* 在当前开命令周期内 设置禁止 */
extern void SetLgtOnDis_LB  (void);
extern void SetLgtOnDis_TI  (void);
extern void SetLgtOnDis_POS (void);
extern void SetLgtOnDis_SML (void);
extern void SetLgtOnDis_HB  (void);
extern void SetLgtOnDis_DRL (void);
extern void SetLgtOnDis_CORN(void);
extern void SetLgtOnDis_FOG (void);
extern void SetLgtOnDis_CROS(void);
extern void SetLgtOnDis_GRIL(void);
extern void SetLgtOnDis_LOGO(void);
extern void SetLgtOnDis_WELC(void);

extern void SetLgtOnDis_AHBC(void);
extern void SetLgtOnDis_TOUR(void);
extern void SetLgtOnDis_AFS (void);

/* 0.01 m/s */
extern uint16_t Get_VehSpd(void);

/* 车辆模式, <0x08:unactive; >0x08:active */
extern E_UseMode_t Get_VehMode(void);


extern void Get_AHBCObj(S_AHBCObj_t *obj);


#define FEEDERR_LATE    (0) /* 故障确认后再反馈 */

#endif  /* _LIGHTING__H_ */