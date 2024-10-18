/**
 * @file TurnIndicator.h
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
#ifndef _TURN_INDICATOR_H_
#define _TURN_INDICATOR_H_

/**
 * @brief TI module Initialize
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
int TI_Init(void);

/**
 * @brief TI module Exit
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
int TI_Exit(void);

/**
 * @brief TI module cycle Run
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
int TI_Run(uint32_t ms);



#endif  /* _TURN_INDICATOR_H_ */