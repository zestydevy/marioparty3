#include "common.h"
#include "malloc.h"

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

INCLUDE_ASM(s32, "data", func_800098FC_A4FC);

// TODO: this is a file break for data.c

// 16 byte portion of a directory or file table, which is initially read from ROM.
struct mainfs_table_header {
    s32 count;
    s32 offsets[3]; // Enough to pad to size 16
};

struct mainfs_entry_info {
    u8 * file_bytes;
    s32 size;
    s32 compression_type;
};

extern void *D_800ABFC0; // FS ROM location
extern u32 D_800ABFC4; // Directory count
extern s32 *D_800ABFC8; // Directory offset table pointer.

extern void *D_800ABFCC; // FS ROM location (copy)
extern u32 D_800ABFD0; // Directory count (copy)
extern s32 *D_800ABFD4; // Directory offset table pointer (copy)

extern struct mainfs_table_header D_800ABFE0;

INCLUDE_ASM(s32, "data", func_80009AC0_A6C0);

INCLUDE_ASM(s32, "data", func_80009B64_A764);

INCLUDE_ASM(s32, "data", func_80009C10_A810);

INCLUDE_ASM(s32, "data", func_80009C74_A874);

INCLUDE_ASM(s32, "data", func_80009CD8_A8D8);

INCLUDE_ASM(s32, "data", func_80009D4C_A94C);

INCLUDE_ASM(s32, "data", func_80009DA8_A9A8);

INCLUDE_ASM(s32, "data", func_80009E04_AA04);

INCLUDE_ASM(s32, "data", func_80009E6C_AA6C);

INCLUDE_ASM(s32, "data", func_80009E8C_AA8C);

INCLUDE_ASM(s32, "data", func_80009EAC_AAAC);

INCLUDE_ASM(s32, "data", func_80009F64_AB64);

INCLUDE_ASM(s32, "data", func_80009FF8_ABF8);

INCLUDE_ASM(s32, "data", func_8000A028_AC28);

INCLUDE_ASM(s32, "data", func_8000A0D4_ACD4);

INCLUDE_ASM(s32, "data", func_8000A150_AD50);
