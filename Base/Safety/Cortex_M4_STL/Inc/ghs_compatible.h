
#include "arm_ghs.h"

#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE                        static __inline
#endif

#define __get_IPSR()    __MRS(__IPSR)

#define __disable_irq()   __DI()

