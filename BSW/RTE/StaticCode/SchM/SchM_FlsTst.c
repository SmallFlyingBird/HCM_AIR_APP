

#include "SchM_FlsTst.h"
#include "Std_Types.h"

FUNC(void, RTE_CODE) SchM_Enter_FlsTst_RAMTST_EXCLUSIVE_AREA(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_FlsTst_RAMTST_EXCLUSIVE_AREA(void)
{
    ResumeAllInterrupts();
}
