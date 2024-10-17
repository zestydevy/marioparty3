#include "common.h"

extern u8 D_800CD0C0[];
extern s32 D_800BBAA0;
extern s32 D_800BBAA4;
extern char D_800A7B40_A8740[];
extern s32 D_800BBAA0;
extern s32 D_800BBAA4;
extern u8 D_800CD0C0[];

void func_8004F83C_5043C(s32);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F290_4FE90);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F504_50104);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F524_50124);

INCLUDE_ASM(s32, "unknown/4FE90", SavePlayerStruct);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F564_50164);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F584_50184);

s32 SaveFileEncode(s32 arg0, u8* arg1) {
    s32 phi_s0;
    s16 phi_v1_2;
    u8* phi_s2_2;
    s16 i, j, k, l;

    for (l = 0; l < 220; l++) {
        D_800CD0C0[l] = 0;
    }

    D_800BBAA4 = 0;
    D_800BBAA0 = 0;

    while (*arg1 != 0) {
        for (phi_s2_2 = (u8*)(arg0 + arg1[2]), i = 0; i < arg1[1]; i++) {
            if (arg1[0] >= 0x11U) {
                for (j = 0; j < (arg1[0] >> 3); j++, phi_s2_2++) {
                    phi_s0 = *phi_s2_2;
                    for (k = 0; k < 8; k++, phi_s0 *= 2) {
                        func_8004F83C_5043C(phi_s0 & 0x80);
                    }
                }
                continue;
            } else {
                if (arg1[0] >= 9U) {
                    phi_s0 = *phi_s2_2 << (0x10 - arg1[0]);
                    phi_v1_2 = arg1[0] - 8;
                    for (k = 0; k < phi_v1_2; k++, phi_s0 *=2) {
                        func_8004F83C_5043C(phi_s0 & 0x80);
                    }
                    phi_s2_2++;
                    phi_s0 = *phi_s2_2;
                    phi_v1_2 = 8;
                } else {
                    phi_s0 = *phi_s2_2 << (8 - arg1[0]);
                    phi_v1_2 = arg1[0];
                }
                for (k = 0; k < phi_v1_2; k++, phi_s0 *= 2) {
                    func_8004F83C_5043C(phi_s0 & 0x80);
                }     
            }
            phi_s2_2++;
        }
        arg1 += 3;
        if (arg1[0] == 0) {
            break;
        }
    }
    

    D_800CD0C0[D_800BBAA0] <<= 8 - D_800BBAA4;
    if (D_800BBAA4 == 0) {
        D_800BBAA0--;
    }
    if (D_800BBAA0 >= 0xDD) {
        osSyncPrintf(D_800A7B40_A8740);
    }
    return D_800BBAA0 + 1;
}

void func_8004F83C_5043C(s32 arg0) {
    D_800CD0C0[D_800BBAA0] *= 2;
    D_800CD0C0[D_800BBAA0] |= arg0 ? 1 : 0;
    
    if (++D_800BBAA4 >= 8) {
        D_800BBAA0++;
        D_800BBAA4 = 0;
    }
}

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F8BC_504BC);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F90C_5050C);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F95C_5055C);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F9AC_505AC);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004F9FC_505FC);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004FA4C_5064C);

INCLUDE_ASM(s32, "unknown/4FE90", func_8004FC84_50884);
