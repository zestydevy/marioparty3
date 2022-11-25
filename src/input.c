#include "common.h"

extern s16 D_800C9520[];
extern s16 D_800D0590[];
extern s16 D_800D10F8[];
extern s16 D_800D1350[];
extern s16 D_800D5546[];

void func_80009880_A480(void)
{
    s16 i;

    for (i = 0; i < 4; ++i) {
        D_800D5546[i] = 
        D_800D1350[i] = 
        D_800C9520[i] = 
        D_800D0590[i] = 
        D_800D10F8[i] = 0;
    }
}

INCLUDE_ASM(s32, "input", func_800098FC_A4FC);
