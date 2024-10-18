

#ifndef _LGT_PARAMETERS_SIGNALS_H_
#define _LGT_PARAMETERS_SIGNALS_H_

#include "HcmPlatform.h"

extern Std_ReturnType get_si_ActnLB       (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnHB       (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnDRL      (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnPOS      (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnTIsts    (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnTIact    (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnGIRL     (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnLOGO     (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnASSI     (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnCROS     (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnCOR      (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnFOG      (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnWELC     (uint32_t * sig_val);

extern Std_ReturnType get_si_ActnTIseq    (uint32_t * sig_val);

extern Std_ReturnType get_si_ActnAHBC     (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnTOUR     (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnAFS      (uint32_t * sig_val);


extern Std_ReturnType get_si_ActnPOS_Dyn  (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnGIRL_Dyn (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnLOGO_Dyn (uint32_t * sig_val);
extern Std_ReturnType get_si_ActnCROS_Dyn (uint32_t * sig_val);

extern Std_ReturnType get_si_VehSpd       (uint16_t * sig_val);   /* 车速，0.01m/s */
extern Std_ReturnType get_si_VheUsage     (uint8_t  * sig_val);   /* 车辆模式 */


extern Std_ReturnType get_si_AHBCObj_CamSts (uint32_t * sig_val);   /*  */
extern Std_ReturnType get_si_AHBCObj_TooMany(uint32_t * sig_val);   /*  */
extern Std_ReturnType get_si_AHBCObj_LitArea(uint32_t * sig_val);   /*  */
extern Std_ReturnType get_si_AHBCObj_Classn (uint32_t * sig_val);   /*  */
extern Std_ReturnType get_si_AHBCObj_OnCmng (uint32_t * sig_val);   /*  */
extern Std_ReturnType get_si_AHBCObj_Dist   (uint16_t * sig_val);   /* 目标物距离，0.01m */


#endif  /* _LGT_PARAMETERS_SIGNALS_H_ */