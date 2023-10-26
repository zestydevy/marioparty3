#include "common.h"

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonMaskIdleThreadInts);

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonGetTCB);

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonStopUserThreads);

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonListThreads);

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonGetThreadStatus);

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonThreadStatus);

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonStopThread);

INCLUDE_ASM(s32, "libultra/rmon/rmontask", __rmonRunThread);
