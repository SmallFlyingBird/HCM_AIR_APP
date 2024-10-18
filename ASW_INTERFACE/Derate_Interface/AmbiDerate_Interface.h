/**
 * @file AmbiDerate_Interface.h
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-04-28
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-04-28 <td>0.1     <td>QinHaigang <td>
 * </table>
 */

#ifndef _AMBIDERATE_INTERFACE_H_
#define _AMBIDERATE_INTERFACE_H_



/**
 * @brief 
 * 
 * @param  
 * @return 
 */
extern 
uint8_t Interface_GetDerateRatioOfAmbi(void);



extern 
void AmbiDerateMainFunction(uint8_t timebase);



#endif  /* _AMBIDERATE_INTERFACE_H_ */