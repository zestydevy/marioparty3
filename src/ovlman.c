#include "common.h"
#include "rom.h"
typedef struct OverlayInfo {
    u8 *rom_start;
    u8 *rom_end;
    u8 *ram_start;
    u8 *code_start;
    u8 *code_end;
    u8 *data_start;
    u8 *data_end;
    u8 *bss_start;
    u8 *bss_end;
} OverlayInfo; // sizeof 0x24

extern u8 D_800962F0_96EF0;
extern u32 rnd_seed;
extern OverlayInfo overlay_table[];

s32 Hu3DModelCreate(u8* arg0, u32 arg1);
void* ReadMainFS(s32);

INCLUDE_ASM(s32, "ovlman", func_8000B0A0_BCA0);

INCLUDE_ASM(s32, "ovlman", func_8000B0D4_BCD4);

INCLUDE_ASM(s32, "ovlman", func_8000B108_BD08);

s16 func_8000B13C_BD3C(s32 arg0) {
    return Hu3DModelCreate(ReadMainFS(arg0), 0x1D);
}

u8 rand8(void) {
    rnd_seed = rnd_seed * 0x41C64E6D + 0x3039;
    return (rnd_seed + 1) >> 16;
}

INCLUDE_ASM(s32, "ovlman", func_8000B1A0_BDA0);

// copies in an overlay and clears bss region.
void LoadOverlay(s32 overlayIndex) {
    u8 *rom_start;
    u8 *rom_end;
    u8 *bss_start;
    u8 *bss_end;
    u8 *temp;

    rom_start = overlay_table[overlayIndex].rom_start;
    rom_end = overlay_table[overlayIndex].rom_end;
    bss_start = overlay_table[overlayIndex].bss_start;
    bss_end = overlay_table[overlayIndex].bss_end;

    HuRomDmaCodeRead(rom_start, overlay_table[overlayIndex].ram_start, rom_end - rom_start);

    temp = bss_start;
    while (bss_start < bss_end) {
        *(temp++) = 0;
        bss_start++;
    }

    D_800962F0_96EF0 = 0;
}

INCLUDE_ASM(s32, "ovlman", func_8000B364_BF64);

INCLUDE_ASM(s32, "ovlman", func_8000B3C8_BFC8);

INCLUDE_ASM(s32, "ovlman", func_8000B460_C060);

INCLUDE_ASM(s32, "ovlman", func_8000B4B4_C0B4);

INCLUDE_ASM(s32, "ovlman", func_8000B4F8_C0F8);

INCLUDE_ASM(s32, "ovlman", func_8000B554_C154);

INCLUDE_ASM(s32, "ovlman", func_8000B5BC_C1BC);
