
#ifndef _LIGHTING_DRL_H_
#define _LIGHTING_DRL_H_


/**
 * @brief DRL Module Initialize
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void DRL_Init(void);

/**
 * @brief DRL Module Exit
 * 
 * @return 0:OK; not 0:ERROR
 */
extern 
void DRL_Exit(void);

/**
 * @brief DRL cycle run stage0
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void DRL_Run_(unsigned int ms);

/**
 * @brief DRL cycle run stage1
 * 
 * @param ms: call cycle (ms)
 * @return 0:OK; not 0:ERROR
 */
extern 
void DRL_Run_On(void);


#endif  /* _LIGHTING_DRL_H_ */