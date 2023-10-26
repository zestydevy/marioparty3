#include "common.h"

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonWriteWordTo);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonReadWordAt);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonMemcpy);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonCopyWords);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonReadMem);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonWriteMem);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonListProcesses);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonLoadProgram);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonGetExeName);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonGetRegionCount);

INCLUDE_ASM(s32, "libultra/rmon/rmonmem", __rmonGetRegions);
