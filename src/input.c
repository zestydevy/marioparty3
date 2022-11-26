#include "common.h"
#include "input.h"

// -----------------------------------------------------------------

void func_80009880_A480(void)
{
    s16 i;
    for (i = 0; i < MAXCONTROLLERS; ++i) {
        D_800D5546[i] = 
        D_800D1350[i] = 
        D_800C9520[i] = 
        D_800D0590[i] = 
        D_800D10F8[i] = 0;
    }
}

// -----------------------------------------------------------------

void func_800098FC_A4FC(void)
{
    s16 i;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_7;
    u16 var_a2;
    s8 temp_v0_2;
    s8 temp_v0_4;

    for (i = 0; i < MAXCONTROLLERS; ++i)
    {
        D_800D1350[i] = D_800D5546[i];
        var_a2 = D_800CDA7C[i];
        temp_v0_2 = D_800CBB6E[i];
        temp_v0_3 = ((temp_v0_2 >> 7) | 1);
        
        if (((temp_v0_2 * temp_v0_3) - 0x1E) > 0) {
            if (temp_v0_3 > 0) {
                var_a2 = (var_a2 & 0xFDFF) | 0x100;
            } else {
                var_a2 = (var_a2 & 0xFEFF) | 0x200;
            }
        }
        
        temp_v0_4 = D_800D20A1[i];
        temp_v0_5 = ((temp_v0_4 >> 7) | 1);
        
        if (((temp_v0_4 * temp_v0_5) - 0x1E) > 0) {
            if (temp_v0_5 > 0) {
                var_a2 = (var_a2 & 0xFBFF) | 0x800;
            } else {
                var_a2 = (var_a2 & 0xF7FF) | 0x400;
            }
        }
        
        D_800D5546[i] = var_a2;
        D_800C9520[i] = var_a2 & (var_a2 ^ D_800D1350[i]);
        
        if ((var_a2 & 0xFFFF) != D_800D1350[i]) {
            D_800D10F8[i] = 0xA;
            D_800D0590[i] = D_800C9520[i];
        } else {
            if (D_800D10F8[i] > 0) {
                D_800D10F8[i] = D_800D10F8[i] - 1;
                D_800D0590[i] = D_800C9520[i];
            } else {
                D_800D10F8[i] = 1;
                D_800D0590[i] = var_a2;
            }
        }
    }
}

// -----------------------------------------------------------------