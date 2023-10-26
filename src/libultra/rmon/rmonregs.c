#include "common.h"

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonGetGRegisters);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonSetGRegisters);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonGetFRegisters);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonSetFRegisters);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", rmonGetRcpRegister);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonGetSRegs);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonSetSRegs);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonGetVRegs);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonSetVRegs);

INCLUDE_ASM(s32, "libultra/rmon/rmonregs", __rmonGetRegisterContents);
