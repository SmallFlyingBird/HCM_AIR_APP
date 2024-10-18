/**
 * @file OUVDerate_Interface.h
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-05-07
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-05-07 <td>0.1     <td>QinHaigang <td>
 * </table>
 */
#ifndef _OUVDERATE_INTERFACE_H_
#define _OUVDERATE_INTERFACE_H_

extern 
uint8_t Interface_GetDerateRatioOfOUV(void);

extern 
void OUVDerateMainFunction(uint8_t timebase);

#endif  /* _OUVDERATE_INTERFACE_H_ */