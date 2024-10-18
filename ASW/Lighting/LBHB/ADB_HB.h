

#ifndef _LIGHTING_ADB_HB_H_
#define _LIGHTING_ADB_HB_H_


/**
 * @brief ADB模块初始化
 */
void ADB_HB_Init(void);

/**
 * @brief ADB模块退出
 */
void ADB_HB_Exit(void);

/**
 * @brief ADB模块点灯运行(10ms)
 */
void ADB_HB_Run_(uint16_t ms);

/**
 * @brief ADB模块点灯运行(10ms)
 */
void ADB_HB_Run_On(void);


#endif  /* _LIGHTING_ADB_HB_H_ */