#include "common.h"
#include "rom.h"

#define HAS_TEXT_SECTION 1
#define HAS_DATA_SECTION 2
#define HAS_BSS_SECTION 4
typedef struct OverlayTable {
/* 0x00 */ u8* romStart;
/* 0x04 */ u8* romEnd;
/* 0x08 */ u8* vramStart;
/* 0x0C */ u8* textVramStart;
/* 0x10 */ u8* textVramEnd;
/* 0x14 */ u8* dataVramStart;
/* 0x18 */ u8* dataVramEnd;
/* 0x1C */ u8* bssVramStart;
/* 0x20 */ u8* bssVramEnd;
} OverlayTable; //sizeof 0x24

typedef struct UnkStruct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    f32 unk_0C;
} UnkStruct;

typedef struct UnkOvlMan {
    char unk_00[0x48];
    s16* unk_48;
} UnkOvlMan;

extern OverlayTable overlay_table[];
extern OverlayTable overlay_table2[];
extern u8 D_800962F0_96EF0;
extern u32 rnd_seed;
extern UnkStruct D_800975F0_981F0[];
extern Vec D_80097560_98160[];
extern Vec D_800975A8_981A8[];
extern s16 gNumOfControllers;

s16 Hu3DModelCreate(void*, s32);
void* HuReadFileTag(s32 dirAndFile, s32 tag);
s16 func_8000B13C_BD3C(s32);
void func_800124BC_130BC(u8, UnkStruct*);
void* ReadMainFS(s32);
void func_80012508_13108(u8, Vec*, Vec*);
void HuMemMemoryFreePerm(void *ptr);
void* ReadMainFS(s32 dirAndFile);
s32 func_8001443C_1503C(void*, s32, u8);
s32 func_800323CC_32FCC(s32, void*, s32, s32);

u16 func_8000B0A0_BCA0(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(ReadMainFS(arg0), arg1);
}

u16 func_8000B0D4_BCD4(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(ReadMainFS(arg0), arg1);
}

u16 func_8000B108_BD08(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(ReadMainFS(arg0), arg1);
}

s16 func_8000B13C_BD3C(s32 arg0) {
    return Hu3DModelCreate(ReadMainFS(arg0), 0x1D);
}

s32 rand8(void) {
    rnd_seed = rnd_seed* 0x41C64E6D + 0x3039;
    return ((rnd_seed + 1) >> 16) & 0xFF;
}

//checks if the overlay has a text, data, and bss section and dmas/clears the region if so
void func_8000B1A0_BDA0(s32 arg0, u8 sectionFlags) {
    u8* textVramEnd;
    u8* textVramStart;
    u8* romStart;
    u8* dataVramStart;
    u8* dataVramEnd;
    u8* bss_end;
    u8* bss_start;
    u8* curBssAddr;
    u8* textStart;
    u8* tmp;

    romStart = overlay_table2[arg0].romStart;
    textVramStart = overlay_table2[arg0].textVramStart;
    textVramEnd = overlay_table2[arg0].textVramEnd;
    dataVramStart = overlay_table2[arg0].dataVramStart;
    dataVramEnd = overlay_table2[arg0].dataVramEnd;
    bss_start = overlay_table2[arg0].bssVramStart;
    bss_end = overlay_table2[arg0].bssVramEnd;
    textStart = overlay_table2[arg0].vramStart;
    if (sectionFlags & HAS_TEXT_SECTION) {
        HuRomDmaCodeRead(romStart, textStart, textVramEnd - textVramStart);
    }
    if (sectionFlags & HAS_DATA_SECTION) {
        HuRomDmaCodeRead(romStart + (textVramEnd - textVramStart), dataVramStart, dataVramEnd - dataVramStart);
    }
    if (sectionFlags & HAS_BSS_SECTION) {
        curBssAddr = tmp = bss_start;
        while (tmp < bss_end) {
            *curBssAddr++ = 0;
            tmp++;
        }
    }
}

// copies in an overlay and clears bss region.
void LoadOverlay(s32 overlayIndex) {
    u8* rom_start;
    u8* rom_end;
    u8* bss_start;
    u8* bss_end;
    u8* curBssAddr;

    rom_start = overlay_table[overlayIndex].romStart;
    rom_end = overlay_table[overlayIndex].romEnd;
    bss_start = overlay_table[overlayIndex].bssVramStart;
    bss_end = overlay_table[overlayIndex].bssVramEnd;

    HuRomDmaCodeRead(rom_start, overlay_table[overlayIndex].vramStart, rom_end - rom_start);

    curBssAddr = bss_start;
    while (bss_start < bss_end) {
        *curBssAddr++ = 0;
        bss_start++;
    }

    D_800962F0_96EF0 = 0;
}

void func_8000B364_BF64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 temp = arg0;
    D_800975F0_981F0[temp].unk_00 = arg1;
    D_800975F0_981F0[temp].unk_04 = arg2;
    D_800975F0_981F0[temp].unk_08 = arg3;
    D_800975F0_981F0[temp].unk_0C = arg4;
    func_800124BC_130BC(arg0, &D_800975F0_981F0[temp]);
}

void func_8000B3C8_BFC8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 temp = arg0;

    D_80097560_98160[temp].x = arg1;
    D_80097560_98160[temp].y = arg2;
    D_80097560_98160[temp].z = arg3;

    D_800975A8_981A8[temp].x = arg4;
    D_800975A8_981A8[temp].y = arg5;
    D_800975A8_981A8[temp].z = arg6;

    func_80012508_13108(arg0, &D_80097560_98160[temp], &D_800975A8_981A8[temp]);
}

void func_8000B460_C060(UnkOvlMan* arg0, u16 arg1, s32 arg2) {
    s16 temp_v0;

    temp_v0 = func_8000B13C_BD3C(arg2);
    if ((temp_v0 >= 0)) {
        arg0->unk_48[arg1] = temp_v0;
    }
}

s8 func_8000B4B4_C0B4(void) {
    s8 temp_v1;

    if (gNumOfControllers > D_800962F0_96EF0) {
        temp_v1 = D_800962F0_96EF0++;
    } else {
        temp_v1 = -1;
    }
    return temp_v1;
}

u16 func_8000B4F8_C0F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    void* temp_v0;

    temp_v0 = ReadMainFS(arg0);
    temp_s0 = func_8001443C_1503C(temp_v0, arg1, arg2);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

s16 func_8000B554_C154(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    void* temp_v0;

    temp_v0 = ReadMainFS(arg1);
    temp_s0 = func_800323CC_32FCC(arg0, temp_v0, 0, arg2);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

s16 func_8000B5BC_C1BC(s32 arg0) {
    return Hu3DModelCreate(HuReadFileTag(arg0, 0x7918), 0);
}
