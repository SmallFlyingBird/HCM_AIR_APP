/**
 * @file LB.h
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
 * <tr><td>2024-05-06 <td>0.1     <td>QinHaigang <td>First
 * </table>
 */
#ifndef _LB_LIGHTING_H_
#define _LB_LIGHTING_H_


/**
 * @brief LB initialize
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void LB_Init(void);

/**
 * @brief LB exit
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void LB_Exit(void);

/**
 * @brief LB cycle run stage0
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void LB_Run_(uint16_t ms);

/**
 * @brief LB cycle run stage1
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void LB_Run_On(void);

#endif  /* _LB_LIGHTING_H_ */
