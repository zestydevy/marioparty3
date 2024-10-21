#include "common.h"
#include "rom.h"
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

extern u8 D_800962F0_96EF0;
extern u32 rnd_seed;
extern OverlayTable overlay_table[];
extern UnkStruct D_800975F0_981F0[];
void func_800124BC_130BC(u8, UnkStruct*);
s32 Hu3DModelCreate(u8* arg0, u32 arg1);
void* ReadMainFS(s32);

INCLUDE_ASM(s32, "ovlman", func_8000B0A0_BCA0);

INCLUDE_ASM(s32, "ovlman", func_8000B0D4_BCD4);

INCLUDE_ASM(s32, "ovlman", func_8000B108_BD08);

s16 func_8000B13C_BD3C(s32 arg0) {
    return Hu3DModelCreate(ReadMainFS(arg0), 0x1D);
}

s32 rand8(void) {
    rnd_seed = rnd_seed* 0x41C64E6D + 0x3039;
    return ((rnd_seed + 1) >> 16) & 0xFF;
}

INCLUDE_ASM(s32, "ovlman", func_8000B1A0_BDA0);

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

INCLUDE_ASM(s32, "ovlman", func_8000B3C8_BFC8);

INCLUDE_ASM(s32, "ovlman", func_8000B460_C060);

INCLUDE_ASM(s32, "ovlman", func_8000B4B4_C0B4);

INCLUDE_ASM(s32, "ovlman", func_8000B4F8_C0F8);

INCLUDE_ASM(s32, "ovlman", func_8000B554_C154);

INCLUDE_ASM(s32, "ovlman", func_8000B5BC_C1BC);
