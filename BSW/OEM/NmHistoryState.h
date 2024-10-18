
#ifndef NM_HISTORY_STATE
#define NM_HISTORY_STATE

#include "Std_Types.h"


#ifdef GEELY20_SPECIFICATION_USED

/******************************************************************************
**                      Global Symbols                                       **
******************************************************************************/

/* nm state history value define */
/* Off */
#define NHS_STATE_OFF                               ((uint8)0x01u)
/* BusSleepMode */
#define NHS_STATE_BUSSLEEPMODE                      ((uint8)0x02u)
/* repeat message state */
#define NHS_STATE_REPEATMESSAGESTATE                ((uint8)0x04u)
/* normal operation state */
#define NHS_STATE_NORMALOPERATIONTATE               ((uint8)0x05u)
/* ready sleep state */
#define NHS_STATE_READYSLEEPSTATE                   ((uint8)0x06u)
/* prepare bus sleep mode */
#define NHS_STATE_PREPAREBUSSLEEPMODE               ((uint8)0x07u)
/* CANSM Bus off recovery Level 1 */
#define NHS_STATE_BUSOFF_REC_LEVEL1                 ((uint8)0x08u)
/* CANSM Bus off recovery Level 2 */
#define NHS_STATE_BUSOFF_REC_LEVEL2                 ((uint8)0x09u)

#define NHS_BUFFER_SIZE                                10u

#define NM_CUSTOM_TIMERSTAMP

#define LOCAL_NODE_REALTIMESTAMP_SUPPORT			STD_ON

#define CAR_GLOBAL_TIMESTAMP_SUPPORT				STD_OFF

#define NM_CUSTOM_SUPPORT_NVM

extern uint32 CarGlobalTimeStamp;

#if defined(NM_CUSTOM_TIMERSTAMP)
#if(STD_ON == LOCAL_NODE_REALTIMESTAMP_SUPPORT)
uint32 GetNmHistoryTimeStamps(void);
void NmHistoryState_MainFunction(void);
void NmHistory_UpdateTimeStamps(uint32 TimeStamp);
#endif
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */

void NmHistoryState_PreInit(void);
void NmHistoryState_DeInit(void);
void NmHistoryState_NodifyState(uint8 state);
void NmNmHistoryState_NodifyBusOff(boolean busOffState);

#if defined(NM_CUSTOM_SUPPORT_NVM)
void NmHistoryState_NvmReadyInit(void);
#endif/* defined(NM_CUSTOM_SUPPORT_NVM) */


Std_ReturnType NmHistoryState_BaseDidReadLen(uint16* lenPtr);
Std_ReturnType NmHistoryState_BaseDidReadBuf(uint8* bufPtr);

#endif/* defined(SAS_009_19_JL_NM_CUSTOM) */
#endif/* NM_HISTORY_STATE */
