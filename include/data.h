#ifndef __DATA_H
#define __DATA_H

#include "libultra.h"
#include "decode.h"

typedef enum
{
    ARCHIVE_CACHED = 0x2E,
    ARCHIVE_DIRECT,
} EArchiveType;

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
typedef struct {
    s32 count;
    s32 offsets[3]; // Enough to pad to size 16
} HuArchive;

typedef struct {
    u8* bytes;
    s32 size;
    EDecodeType compType;
} HuFileInfo;

// deprecated!!
typedef struct
{
    s16 compType;
    u32 size;
    u8* block;
    s16 unkC;
    s16 unkE;
    void* bytes;
    void* bytesCopy;
} HuFileInfoD;

extern u8* gArchiveRomAddr; // FS ROM location
extern u32 gArchiveDirCount; // Directory count
extern s32* gArchiveTblAddr; // Directory offset table pointer.

extern u8* gArchiveRomAddrCopy; // FS ROM location (copy)
extern u32 gArchiveDirCountCopy; // Directory count (copy)
extern s32* gArchiveTblAddrCopy; // Directory offset table pointer (copy)

extern HuArchive gArchive;

void HuInitArchive(u8* fsRomPtr);
void HuInitFileInfo(EArchiveType type, s32 index, HuFileInfo* info);
void* Hu3DModelCreate(s32 dirAndFile);
void* HuDecodeFilePerm(EArchiveType type, s32 index);
void* HuDecodeFileTemp(EArchiveType type, s32 index);
void* HuDecodeFileTag(EArchiveType type, s32 index, s32 tag);
void HuInitDirectory(EArchiveType type, s32 dir);

#endif