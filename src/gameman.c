#include "common.h"
#include "common_structs.h"
#include "gameman.h"
#include "malloc.h"
#include "pad.h"
#include "process.h"
#include "obj.h"

/* Hardcoded symbols */
extern void *D_1209850; // bin_strings_jp_ROM_START
extern void *D_1881C40; // bin_audio_mbf0_ROM_START
extern void *D_1A56870; // bin_audio_sbf0_ROM_START
extern void *D_1EFD040; // bin_audio_fxd0_ROM_START

struct str800D5298 {
    s32 unk0;
    s32 unk4;
    void *unk8; // mbf0 rom
    void *unkC; // sbf0 rom
    void *unk10; // fxd0 rom
    void *unk14; // audio ram location?
    s32 unk18; // audio ram size?
    s32 unks1C24[3];
    s32 unk28;
    s32 unk2C;
    s32 unks3040[5];
    s32 unk44;
    s32 unks4858[5];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
};
extern struct str800D5298 D_800D5298;


extern PlayerData gPlayers[4];

extern void *D_800CCF38;
extern u8 D_800CCF78[];
extern f32 D_800CD288[];
extern u16 D_800CD2F4;
extern s32 D_800CDD50;
extern f32 D_800CE1C8;

extern Process* D_800D0448;
extern u8 D_800D09A8;
extern Vec D_800D138C;

extern Process* D_800D170C;
extern u8 D_800D1710;
extern s16 D_800D1F36;

extern u16 D_800D4082;
extern Vec D_800D54F8[];

extern u16 D_800D6A56;
extern Vec D_800D6ABC;
extern Vec D_800D6AE0[];

extern u16 D_800A190C_A250C;
extern u16 D_800A190E_A250E;


extern void func_800007FC_13FC(struct str800D5298 *arg0);
extern void func_80000EA8_1AA8(struct str800D5298 *arg0);
extern void func_80000F30_1B30(u32 arg0);
u8 rand8(); //ovlman.h
extern void func_8000BA30_C630(); // esprite.h
extern void func_800143F0_14FF0();
extern void func_80014A3C_1563C(u32 arg0);
extern void func_8001A070_1AC70(void *arg0, void *arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5); // hmfman.h
extern void func_8001B0B4_1BCB4(void **arg0, u32 arg1); // hmfman.h
extern void func_8001BF90_1CB90(u32 arg0, u32 arg1); // hmfman.h
extern void func_800224BC_230BC();
extern void func_80035A50_36650(); // save.h
extern void func_80035C20_36820(s16 arg0, s16 arg1); // save.h
extern void func_80036380_36F80(void **arg0);

extern void func_8004DC00_4E800();
extern void func_8004DC98_4E898();
extern void func_8004F290_4FE90();
extern s32  func_8004FDC0_509C0();
extern void func_80050800_51400();
extern void func_80050E78_51A78(u32 arg0);
extern void func_80061B50_62750();
extern void func_80087A40_88640(PlayerData *arg0, u32 arg1, u32 arg2);

extern void Hu3DCamInit(u32 arg0);


void func_8000E3C0_EFC0() {
    s32 i;

    HuPrcVSleep();

    func_8004F290_4FE90();

    D_800D138C.x = 325.0f;
    D_800D138C.y = 0.0f;
    D_800D138C.z = 0.0f;

    D_800CE1C8 = 2250.0f;

    D_800D6ABC.x =
    D_800D6ABC.y =
    D_800D6ABC.z = D_800D138C.y;

    for (i = 0; i < 4; i++) {
        D_800D6AE0[i].x = 325.0f;
        D_800D6AE0[i].y =
        D_800D6AE0[i].z = 0.0f;

        D_800CD288[i] = 2250.0f;

        D_800D54F8[i].x =
        D_800D54F8[i].y =
        D_800D54F8[i].z = 0.0f;
    }

    D_800D1710 = 3;
    D_800D4082 = 0x1000;
    D_800CD2F4 = 0x2004;
    D_800D6A56 = 0x180;
    func_80061B50_62750();
    func_8001A070_1AC70(&HuMemMemoryAllocPerm, &HuMemMemoryFreePerm, D_800D4082, D_800CD2F4, D_800D6A56, D_800D1710);
    Hu3DCamInit(1);
    func_8004DC00_4E800();
    func_80036380_36F80(&D_1209850); // strings
    D_800D1F36 = 0;

    do {
        if (HuGetPadInserted(D_800D1F36) != 0) {
            break;
        }
    } while (++D_800D1F36 < 4);

    if (D_800D1F36 == 4) {
        D_800D1F36 = -1;
    }

    HuMemHeapAllocPermSizeGet();
    D_800D0448 = HuPrcCreate(&func_8000E740_F340, 0xF000, 0x3000, 0);
    HuPrcCreate(&func_8000E78C_F38C, 0x4000, 0x3000, 0);
    D_800D170C = HuPrcCreate(&func_8000E7B8_F3B8, 0x1000, 0x3000, 0);

    {
        s32 temp_s0;

        temp_s0 = func_8004FDC0_509C0();
        func_80035A50_36650();
        func_8000E978_F578();
        func_80000EA8_1AA8(&D_800D5298);
        func_80050E78_51A78(0);
        func_80050800_51400();
        if (temp_s0 != 0) {
            omOvlCallEx(0x67, 0, 0x82);
        }
        else {
            omOvlCallEx(0x58, 0, 0x84);
        }
    }

    D_800D5298.unk8 = &D_1881C40;
    D_800D5298.unkC = &D_1A56870;
    D_800A190E_A250E = 0;
    D_800A190C_A250C = 0;
    D_800D5298.unk0 = 0x70418F;
    D_800D5298.unk10 = &D_1EFD040;
    D_800D5298.unk28 = 1;
    D_800D5298.unk2C = 0;
    D_800D5298.unk14 = (void *)0x802E0000;
    D_800D5298.unk18 = 0x80000;
    D_800D5298.unk5C = 0x6E;
    D_800D5298.unk60 = 0;
    D_800D5298.unk64 = 0;
    D_800D5298.unk68 = D_800CDD50;
    D_800D5298.unk44 = 0x3C;
    func_800007FC_13FC(&D_800D5298);

    if ((D_800D09A8 & 1) != 0) {
        func_80000F30_1B30(1);
    }
    else {
        func_80000F30_1B30(0);
    }

    HuPrcKill(HuPrcCurrentGet());

    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_8000E740_F340() {
    while (TRUE) {
        HuPrcVSleep();
        func_800224BC_230BC();
        func_800143F0_14FF0();
        func_8001BF90_1CB90(0x2000000, 0x3D0800);
        func_8004DC98_4E898();
    }
}

void func_8000E78C_F38C() {
    while (TRUE) {
        HuPrcVSleep();
        omMain();
    }
}


void func_8000E7B8_F3B8() {
    while (TRUE) {
        HuPrcVSleep();
        rand8();
        func_8000BA30_C630(); // esprite
        func_80014A3C_1563C(2);
        func_8001B0B4_1BCB4(&D_800CCF38, 2); // hmfman
    }
}

/* Initialize Players */
void func_8000E804_F404() {
    s32 i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        func_80087A40_88640(&gPlayers[i], 0, sizeof(PlayerData));
        if (HuGetPadInserted(i) != PAD_NOT_INSERTED) {
            D_800CCF78[i] = 0;
            gPlayers[i].flags &= 0xFE;
        }
        else {
            D_800CCF78[i] = 1;
            gPlayers[i].flags |= 0x01;
        }
        gPlayers[i].controller = i;
        gPlayers[i].coins = 10;
        gPlayers[i].bonusCoins = 0;
        gPlayers[i].id = i;
        gPlayers[i].cpuDifficulty = 0;
        gPlayers[i].stars = 0;
        gPlayers[i].minigameStar = 0;
        gPlayers[i].blueSpaceCount = 0;
        gPlayers[i].redSpaceCount = 0;
        gPlayers[i].happeningSpaceCount = 0;
    }
}

/* Initialize Game Save Data */
void func_8000E978_F578() {
    func_8000E804_F404();
    func_80035C20_36820(0, 0x64);
    func_80035C20_36820(1, 0xE10);
    func_80035C20_36820(2, 0xE10);
    func_80035C20_36820(3, 0x708);
    func_80035C20_36820(4, 0x3E8);
    func_80035C20_36820(5, 0xE10);
    func_80035C20_36820(6, 0xE10);
    func_80035C20_36820(7, 0xE10);
    func_80035C20_36820(8, 0);
    func_80035C20_36820(9, 0x1518);
}
