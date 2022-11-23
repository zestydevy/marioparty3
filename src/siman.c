#include "common.h"
#include "siman.h"

// TODO: find SI thread stack size
void func_80051750_52350(void) {
    D_800BD7B0 = 0;
    D_800BD7B4 = 0;
    osCreateMesgQueue(&D_800CE1A0, &D_800BCD00, 32);
    osSetEventMesg(OS_EVENT_SI, &D_800CE1A0, (OSMesg)32);
    osCreateMesgQueue(&D_800D1220, &D_800BCD80, 32);
    osCreateThread(&D_800BCE00, 0x14, func_80051A44_52644, NULL, &D_800BD7B0, HOS_PRIORITY_SIMGR);
    osStartThread(&D_800BCE00);
}


s32 * func_800517F4_523F4(Hu523F4_0 * arg0) {
    switch (arg0->unk8) {
    case 0:
        return &D_800BD7B0;
    case 1:
        return &D_800BD7B4;
    default:
        return NULL;
    }
}

INCLUDE_ASM(s32, "siman", func_8005182C_5242C);

INCLUDE_ASM(s32, "siman", func_8005188C_5248C);

INCLUDE_ASM(s32, "siman", func_800518FC_524FC);

INCLUDE_ASM(s32, "siman", func_80051968_52568);

INCLUDE_ASM(s32, "siman", func_800519D0_525D0);

INCLUDE_ASM(void, "siman", func_80051A44_52644, void * arg0);

INCLUDE_ASM(s32, "siman", func_80051B0C_5270C);
