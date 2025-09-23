#ifndef _LIGHTING__H_
#define _LIGHTING__H_

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
    uint8    EnaWELC     :1;     /* WELCome light */
    uint8    EnaGoodBye  :1;     /* goodbye light */
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
 * @brief Lighting Act Status Feedback (see E_LgtSts_t define)
 */
typedef enum _LgtSts_
{
    STS_OFF = 0,    /* off */
    STS_ON,         /* on */
    STS_ERR,        /* error */
    STS_Res         /* reserve */
}E_LgtSts_t;

typedef enum DtcSts
{
    DTC_Noerr = 0,
    DTC_Error
} E_DTCsts;

typedef union
{
    uint32 Light_Status;
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
        uint8    StsFOG      :2;
        uint8    StsADS      :2;
    }Bits;
}S_LgtStsFb_t;

void SetLgtStsFb_Status(E_LgtSts_t sts, Light_Functions lightType);
void SetDTCGroup_LB(E_DTCsts sts);
void SetDTCGroup_HB(E_DTCsts sts);
void SetDTCGroup_POS(E_DTCsts sts);
void SetDTCGroup_IND(E_DTCsts sts);
void SetDTCGroup_DRL(E_DTCsts sts);
void SetDTCGroup_FOG(E_DTCsts sts);
void SetDTCGroup_CROS(E_DTCsts sts);
void SetDTCGroup_CORN(E_DTCsts sts);

uint8 GetLgtStsFb(Light_Functions lightType);
uint8 GetLgtStsEna_WELC(void);
uint8 GetLgtStsEna_GDY (void);
uint8 GetLgtStsEna_Charge(void);
uint8 GetDTCGroup_LB(void);
uint8 GetDTCGroup_HB(void);
uint8 GetDTCGroup_POS(void);
uint8 GetDTCGroup_IND(void);
uint8 GetDTCGroup_DRL(void);
uint8 GetDTCGroup_FOG(void);
uint8 GetDTCGroup_CROS(void);
uint8 GetDTCGroup_CORN(void);

void ClearDTCGroup(void);

uint8 Lighting_GetAct(Light_Functions lf);
uint32 Lighting_Rek_Fun(void);
Std_ReturnType Light_Manager(uint8 timebase);
void Lighting_Init(void);
Std_ReturnType ReadBack_LightStatus(uint16 *bufsts);
Std_ReturnType Lighting_SetPwmRamp(Light_Functions lf);
uint16 Interface_GetSignal_ChannelCurrent(uint8 chid);
Std_ReturnType Interface_GetSignal_ChannelPwm(uint8 chid);
E_LgtSts_t Interface_GetLightChannelStateSwitch(E_ChannelID id);
void Interface_SetLightChannelStateSwitch(E_ChannelID id,E_LgtSts_t state);
void Interface_SwitchBoost(uint8 tmp);
void SetLgtStsEna_DynLight(uint8 WelEna, uint8 GdyEna, uint8 ChargeEna);
#endif  /* _LIGHTING__H_ */


