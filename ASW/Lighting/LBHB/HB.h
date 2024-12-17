/**
 * @file HB.h
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
#ifndef _HB_LIGHTING_H_
#define _HB_LIGHTING_H_


/**
 * @brief HB initialize
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void HB_Init(void);

/**
 * @brief HB exit
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void HB_Exit(void);

/**
 * @brief HB cycle run stage0
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void HB_Run_(uint16_t ms);

/**
 * @brief HB cycle run stage1
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void HB_Run_On(void);

#endif  /* _HB_LIGHTING_H_ */

