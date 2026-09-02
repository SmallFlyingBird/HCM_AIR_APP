#include "Adc.h"
#include "Adc_Cfg.h"
#include "Adc_Types.h"

/**
 * @brief definition for length of ADC result buffer
 */
#define EX_ADC_RESULT_BUFFER_LENGTH (6U)

/**
 * @brief definition for length of ADC result buffer
 */
#define EX_ADC_MAX_CFG_CHANNEL_COUNT (6U)

/**
 * @brief Notification flag
 */
static unsigned long Ex_Adc_NotifFlag = 0;




void Ex_Adc_UseCase_01(void);