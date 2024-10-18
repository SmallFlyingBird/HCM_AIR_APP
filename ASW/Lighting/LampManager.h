/**
 * @file LampManager.h
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
#ifndef _LAMP_MANAGER_H_
#define _LAMP_MANAGER_H_


/**
 * @brief 支持Light_Functions功能数量，在HcmPlatform.h中有定义
 */
#define E_LightFunc_Num    E_DynamicLightCircuit


/**
 * @brief 灯光控制的状态信息
 * 
 */
typedef struct _LF_Info_
{
    uint8_t     being   :1;     /* 是否存在 */
    uint8_t     res_b8  :7;     /* 保留 */
    uint8_t     lednum;         /* 包含LED数量，通道和矩阵掩码相与的数量 */
    uint8_t     ledlamp;        /* 所在灯组的LED数量（即所在组的所有编号LED的数量） */
    uint8_t     res_B4;         /* 保留 */
    uint16_t    chnMask;        /* 控制通道掩码 */
    uint16_t    mtxMask;        /* 带矩阵的控制通道掩码 */
}S_LF_Info_T;

typedef struct _LF_Err_
{
    uint16_t    chnErr;         /* 通道故障掩码 */
    uint16_t    mtxErr;         /* 矩阵故障掩码 */
    uint16_t    ntcErr;         /* 温度故障掩码 */
    uint16_t    binErr;         /* RBIN故障掩码 */
}S_LF_Err_T;

/**
 * @brief 获取灯光控制的状态信息
 * 
 * @param lgt 灯光功能号
 * @param info 灯光控制状态信息
 * @return 0：成功；非0：失败
 */
extern int lampM_GetLampInfo(Light_Functions lgt, S_LF_Info_T *info);

/**
 * @brief 获取一个灯光控制通道的所有像素的ID号
 * 
 * @param lgt 灯光功能号
 * @param mask 灯光控制通道掩码（从掩码低位往高位，仅取一个通道有效标识）
 * @param id 用于存储所选通道的所有像素ID号，12字节，ID号0表示无像素定义
 * @return 0：成功；非0：失败
 */
extern int lampM_GetLampChnPixId(Light_Functions lgt, uint16_t mask, uint8_t *id);

/**
 * @brief 设置灯光控制通道的占空比、点亮时间和熄灭时间
 * 
 * @param lgt  灯光功能号
 * @param mask 控制通道掩码，参考Mapping配置页
 *            （忽略非该灯光功能的位，控制所有通道可输入0xFFFF，输入0x0000则不设置）
 * @param perc 控制通道占空比，0~100
 * @param ton  控制通道占空比0->100完整上升时间，用于计算斜率，单位ms
 * @param toff 控制通道占空比100->0完整下降时间，用于计算斜率，单位ms
 * @return 0：成功；非0：失败
 */
extern int LampM_SetLampChn(Light_Functions lgt, uint16_t mask,
                            uint8_t perc, uint16_t ton, uint16_t toff);

/**
 * @brief 设置灯光控制像素的占空比、点亮时间和熄灭时间
 * 
 * @param lgt   灯光功能号
 * @param pixid 控制像素ID号，即配置的ID号
 * @param perc  控制像素占空比，0~100
 * @param ton   控制像素占空比0->100完整上升时间，用于计算斜率，单位ms
 * @param toff  控制像素占空比100->0完整下降时间，用于计算斜率，单位ms
 * @return 0：成功；非0：失败
 */
extern int LampM_SetLampPix(Light_Functions lgt, uint8_t pixid, 
                            uint8_t perc, uint16_t ton, uint16_t toff);

/**
 * @brief 取得灯光控制通道相关错误(实时错误)
 * 
 * @param err 指向获取故障数据的存放地址
 * @return 0：成功；非0：失败
 */
extern int LampM_GetLampBaseErr(S_LF_Err_T *err);

/**
 * @brief 取得灯光控制通道相关错误(已报DTC错误)
 * 
 * @param err 指向获取故障数据的存放地址
 * @return 0：成功；非0：失败
 */
extern int LampM_GetLampBaseErr_DTC(S_LF_Err_T *err);

/**
 * @brief 设置LB相关通道忽略欠压故障
 * 
 * @param spe 0：不设置；非0：设置
 */
extern void LampM_Specal_LB(uint8_t spe);

/**
 * @brief set TI Special
 * 
 * @param spe 0: not set; 1: set
 */
extern void LampM_Specal_TI(uint8_t spe);


/**
 * @brief 灯光控制模块初始化
 */
extern void LampM_Init(void);

/**
 * @brief 灯光控制模块退出
 */
extern void LampM_Exit(void);

/**
 * @brief 灯光控制模块运行周期调用
 * 
 * @param ms 周期调用间隔时间，单位ms
 */
extern  void LampM_Run(uint32_t ms);


/**
 * @brief 批量字节设置
 * 
 * @param s 字节首地址
 * @param v 字节值
 * @param n 字节数量
 * @return 
 */
extern
int C_Memset_B(unsigned char *s, unsigned char v, unsigned int n);

/**
 * @brief 批量字节拷贝
 * 
 * @param d 拷贝目标字节首地址
 * @param s 拷贝源字节首地址
 * @param n 拷贝字节数量
 * @return 
 */
extern
int C_Memcpy_B(unsigned char *d, unsigned char *s, unsigned int n);

#endif  /* _LAMP_MANAGER_H_ */