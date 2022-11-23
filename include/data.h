#ifndef __DATA_H
#define __DATA_H

#include "libultra.h"
#include "decode.h"

typedef enum
{
    DIR_COMMON = 0,
    DIR_ACT_TEST,
    DIR_MARIO,
    DIR_LUIGI,
    DIR_YOSHI,
    DIR_WARIO,
    DIR_DK,
    DIR_PEACH,
    DIR_WALUIGI,
    DIR_DAISY,
    DIR_MISC_MODELS,
    DIR_START_MENU = 16,
    DIR_BOOT,
    DIR_BOARD_DEFS = 19,
    DIR_BOARD_SEL,
    DIR_CREDITS = 22,
    DIR_STUBBED = 26,
} EDataDirs;

// 16 byte portion of a directory or file table, which is initially read from ROM.
struct mainfs_table_header {
    s32 count;
    s32 offsets[3]; // Enough to pad to size 16
};

typedef struct {
    u8 * file_bytes;
    s32 size;
    EDecodeType compression_type;
} HuFileInfo;

// deprecated!!
typedef struct
{
    s16 compType;
    u32 size;
    u8 * block;
    s16 unkC;
    s16 unkE;
    void * bytes;
    void * bytesCopy;
} HuFileInfoD;

void func_80009AC0_A6C0(u32 fsRomPtr);
void func_80009B64_A764(s32 type, s32 index, HuFileInfo * info);
void * HuReadFile(s32 dirAndFile);
void * HuDecodeFilePerm(s32 type, s32 index);
void * HuDecodeFileTemp(s32 type, s32 index);
void * func_80009E04_AA04(s32 type, s32 index, s32 tag);
void func_80009EAC_AAAC(s32 arg1, s32 arg2);

#endif