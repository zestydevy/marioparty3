#include "common.h"

INCLUDE_ASM(s32, "libultra/os/timerintr", __osTimerServicesInit);

INCLUDE_ASM(s32, "libultra/os/timerintr", __osTimerInterrupt);

INCLUDE_ASM(s32, "libultra/os/timerintr", __osSetTimerIntr);

INCLUDE_ASM(s32, "libultra/os/timerintr", __osInsertTimer);
