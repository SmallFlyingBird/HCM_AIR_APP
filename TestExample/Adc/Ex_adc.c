#include "Ex_adc.h"

/**
 * @brief Buffer used to setup ADC result buffer
 */
unsigned short Ex_Adc_ResultBuffer_1[EX_ADC_RESULT_BUFFER_LENGTH];
unsigned short Ex_Adc_ResultBuffer_2[EX_ADC_RESULT_BUFFER_LENGTH];
unsigned short Ex_Adc_ResultBuffer_3[EX_ADC_RESULT_BUFFER_LENGTH];

/**
 * @brief Buffer used to read ADC group
 */
unsigned short Ex_Adc_ReadGroupBuffer_1[EX_ADC_MAX_CFG_CHANNEL_COUNT];
unsigned short Ex_Adc_ReadGroupBuffer_2[EX_ADC_MAX_CFG_CHANNEL_COUNT];
unsigned short Ex_Adc_ReadGroupBuffer_3[EX_ADC_MAX_CFG_CHANNEL_COUNT];

/**
 * @brief     Callback function for ADC group 0.
 *
 */
void Ex_Adc_GroupNotification_0(void)
{
    Ex_Adc_NotifFlag++;
}

/**
 * @brief     Callback function for ADC group 1.
 *
 */
void Ex_Adc_GroupNotification_1(void)
{
    Ex_Adc_NotifFlag++;
}

/**
 * @brief     Callback function for ADC group 2.
 *
 */
void Ex_Adc_GroupNotification_2(void)
{
    Ex_Adc_NotifFlag++;
}

/**
 * @brief     This function clears all the data of given buffer data to zero.
 *
 * @param[in] BufferPtr: pointer to buffer to be cleared
 * @param[in] Size: size of buffer to be cleared
 */
static void Ex_Adc_ClearBuffer(unsigned short *BufferPtr, unsigned long Size)
{
    unsigned long Index;
    for (Index = 0; Index < Size; Index++)
    {
        BufferPtr[Index] = 0U;
    }
}
/**
 * @brief     This use case will start three groups with software priority mechanism enabled,
conversion results will be read into user buffer when conversion is completed.
 * 3 groups configured as software trigger,  one-shot, single access mode.
 *
 */
void Ex_Adc_UseCase_01(void)
{
    Ex_Adc_NotifFlag = 0U;
    Ex_Adc_ClearBuffer(Ex_Adc_ResultBuffer_1, EX_ADC_RESULT_BUFFER_LENGTH);
    Ex_Adc_ClearBuffer(Ex_Adc_ResultBuffer_2, EX_ADC_RESULT_BUFFER_LENGTH);
    Ex_Adc_ClearBuffer(Ex_Adc_ResultBuffer_3, EX_ADC_RESULT_BUFFER_LENGTH);
    Ex_Adc_ClearBuffer(Ex_Adc_ReadGroupBuffer_1, EX_ADC_MAX_CFG_CHANNEL_COUNT);
    Ex_Adc_ClearBuffer(Ex_Adc_ReadGroupBuffer_2, EX_ADC_MAX_CFG_CHANNEL_COUNT);
    Ex_Adc_ClearBuffer(Ex_Adc_ReadGroupBuffer_3, EX_ADC_MAX_CFG_CHANNEL_COUNT);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc0_Group_0, Ex_Adc_ResultBuffer_1);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc0_Group_1, Ex_Adc_ResultBuffer_2);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc1_Group_0, Ex_Adc_ResultBuffer_3);
    Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc0_Group_0);
    Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc0_Group_1);
    Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc1_Group_0);
    Adc_StartGroupConversion(AdcConf_AdcGroup_Adc0_Group_0);
    Adc_StartGroupConversion(AdcConf_AdcGroup_Adc0_Group_1);
    Adc_StartGroupConversion(AdcConf_AdcGroup_Adc1_Group_0);

    while (ADC_STREAM_COMPLETED != Adc_GetGroupStatus(AdcConf_AdcGroup_Adc0_Group_0))
        ;
    while (ADC_STREAM_COMPLETED != Adc_GetGroupStatus(AdcConf_AdcGroup_Adc0_Group_1))
        ;
    while (ADC_STREAM_COMPLETED != Adc_GetGroupStatus(AdcConf_AdcGroup_Adc1_Group_0))
        ;

    Adc_ReadGroup(AdcConf_AdcGroup_Adc0_Group_0, Ex_Adc_ReadGroupBuffer_1);
    Adc_ReadGroup(AdcConf_AdcGroup_Adc0_Group_1, Ex_Adc_ReadGroupBuffer_2);
    Adc_ReadGroup(AdcConf_AdcGroup_Adc1_Group_0, Ex_Adc_ReadGroupBuffer_3);

    while (ADC_IDLE != Adc_GetGroupStatus(AdcConf_AdcGroup_Adc0_Group_0))
        ;
    while (ADC_IDLE != Adc_GetGroupStatus(AdcConf_AdcGroup_Adc0_Group_1))
        ;
    while (ADC_IDLE != Adc_GetGroupStatus(AdcConf_AdcGroup_Adc1_Group_0))
        ;
}