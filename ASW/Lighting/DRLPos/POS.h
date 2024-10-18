

#ifndef _LIGHTING_POS_H_
#define _LIGHTING_POS_H_


/**
 * @brief POS Module Initialize
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void POS_Init(void);

/**
 * @brief POS Module Exit
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void POS_Exit(void);

/**
 * @brief POS cycle run stage0
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void POS_Run_(unsigned int ms);

/**
 * @brief POS cycle run stage1
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void POS_Run_On(void);



#endif  /* _LIGHTING_POS_H_ */