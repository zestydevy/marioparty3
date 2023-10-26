#include "common.h"

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonSetBreak);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonListBreak);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonClearBreak);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonGetBranchTarget);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonSetSingleStep);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonGetExceptionStatus);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonHitBreak);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonHitSpBreak);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", __rmonHitCpuFault);

INCLUDE_ASM(s32, "libultra/rmon/rmonbrk", rmonFindFaultedThreads);
