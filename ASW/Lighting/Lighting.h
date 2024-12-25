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
 * @brief Lighting Act Instruction
 */
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
typedef struct _LgtStsFb_
{
    uint8    StsLB       :2;
    uint8    StsTI       :2;
    uint8    StsPOS      :2;
    uint8    StsHB       :2;
    uint8    StsDRL      :2;
    uint8    StsCORN     :2;
    uint8    StsCROS     :2;
    uint8    StsWELC     :2;
}S_LgtStsFb_t;


void Light_Manager(uint8 timebase);
void Lighting_Init(void);

#endif  /* _LIGHTING__H_ */


