/**
 * @file LightingASW.h
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
#ifndef _LIGHTING_ASW_H_
#define _LIGHTING_ASW_H_

/**
 * @brief Lighting Initialize (call once)
 */
extern 
void Lighting_Init(void);

/**
 * @brief Lighting Exit (call once)
 */
extern 
void Lighting_Exit(void);

/**
 * @brief Lighting Run (call cycle 10ms)
 */
extern 
void Lighting_Run10ms(void);

#endif  /* _LIGHTING_ASW_H_ */