

#include "SchM_RamTst.h"
#include "Std_Types.h"

FUNC(void, RTE_CODE) SchM_Enter_RamTst_RAMTST_EXCLUSIVE_AREA(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_RamTst_RAMTST_EXCLUSIVE_AREA(void)
{
    ResumeAllInterrupts();
}
