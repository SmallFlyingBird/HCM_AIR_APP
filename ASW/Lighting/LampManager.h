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

typedef struct _LF_Err_
{
    uint16_t    chnErr;         /* 通道故障掩码 */
    uint16_t    ntcErr;         /* 温度故障掩码 */
    uint16_t    binErr;         /* RBIN故障掩码 */
}S_LF_Err_T;


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







