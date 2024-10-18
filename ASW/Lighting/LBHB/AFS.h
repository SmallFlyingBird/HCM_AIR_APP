/**
 * @file AFS.h
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-09-27 <td>0.1     <td>QinHaigang <td>First
 * </table>
 */

#ifndef _LIGHTING_AFS__H_
#define _LIGHTING_AFS__H_

/**
 * @group LGT.ADV.AFS.RUN
 * @{
 */

extern 
void AFS_Init(void);

extern 
void AFS_Exit(void);

extern 
void AFS_Run_(uint16_t ms);

extern 
void AFS_Run_On(void);

/**
 * @}
 */

/**
 * @group LGT.ADV.AFS.APP
 * @{
 */


/**
 * @brief Get Current AFS LB C/V/E/W mode
 * 
 * @return E_VCEW_t C/V/E/W mode
 */
extern E_VCEW_t  AFS_Get_cvew(void);

/**
 * @brief Get Current AFS LB Pix Percent head
 * 
 * @return uint8_t* AFS LB Pix Percent head
 */
extern const uint8_t * AFS_Get_PixPercHead(void);

/**
 * @}
 */

#endif  /* _LIGHTING_AFS__H_ */