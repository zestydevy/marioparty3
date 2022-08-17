#include "common.h"
#include "rom.h"
#include "malloc.h"
#include "mallocblock.h"
#include "data.h"
#include "decode.h"

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

extern u32 D_800ABFC0; // FS ROM location
extern u32 D_800ABFC4; // Directory count
extern s32 *D_800ABFC8; // Directory offset table pointer.

extern u32 D_800ABFCC; // FS ROM location (copy)
extern u32 D_800ABFD0; // Directory count (copy)
extern s32 *D_800ABFD4; // Directory offset table pointer (copy)

extern struct mainfs_table_header D_800ABFE0;

void func_80009AC0_A6C0(u32 fsRomPtr)
{
    s32 dirTblSize;
    struct mainfs_table_header *mainfs_table_header;

    D_800ABFC0 = fsRomPtr;
    mainfs_table_header = &D_800ABFE0;

    HuRomDmaRead(fsRomPtr, mainfs_table_header, 16);

    D_800ABFC4 = mainfs_table_header->count;
    dirTblSize = mainfs_table_header->count * 4;
    D_800ABFC8 = (s32 *)HuMemMemoryAllocPerm(dirTblSize);

    HuRomDmaRead(fsRomPtr + 4, D_800ABFC8, dirTblSize);

    D_800ABFCC = D_800ABFC0;
    D_800ABFD0 = D_800ABFC4;
    D_800ABFD4 = D_800ABFC8;
}

void func_80009B64_A764(s32 type, s32 index, struct mainfs_entry_info * info)
{
    struct mainfs_table_header * mainfs_table_header;

    mainfs_table_header = &D_800ABFE0;

    switch (type) {
        case 0x2F:
            info->file_bytes = (u8 *)D_800ABFC0 + D_800ABFC8[index];
            break;
        case 0x2E:
            info->file_bytes = (u8 *)D_800ABFCC + D_800ABFD4[index];
            break;
    }

    HuRomDmaRead(info->file_bytes, mainfs_table_header, 16);

    info->file_bytes += 8;
    info->size = mainfs_table_header->count;
    info->compression_type = mainfs_table_header->offsets[0];
}

/**
 * Reads a file from the main filesystem and decodes it.
 * File is in the permanent heap.
 */
void * HuReadFile(s32 dirAndFile)
{
    u32 dir;
    u32 file;

    dir = dirAndFile >> 16;
    file = dirAndFile & 0xFFFF;

    if (dir < D_800ABFC4) {
        func_80009EAC_AAAC(0x2F, dir);

        if (file < D_800ABFD0) {
            return HuDecodeFilePerm(0x2E, file);
        }
    }

    return NULL;
}

INCLUDE_ASM(s32, "data", func_80009C74_A874);

INCLUDE_ASM(s32, "data", func_80009CD8_A8D8);

/**
 * Read file, allocate space in perm heap, decode it.
 */
void * HuDecodeFilePerm(s32 type, s32 index) {
    struct mainfs_entry_info info;
    void * ret;

    func_80009B64_A764(type, index, &info);
    ret = HuMemMemoryAllocPerm((info.size + 1) & -2);
    if (ret != NULL) {
        HuDecode(info.file_bytes, ret, info.size, info.compression_type);
    }
    return ret;
}

/**
 * Read file, allocate space in temp heap, decode it.
 */
void * HuDecodeFileTemp(s32 type, s32 index) {
    struct mainfs_entry_info info;
    void * ret;

    func_80009B64_A764(type, index, &info);
    ret = HuMemMemoryAllocTemp((info.size + 1) & -2);
    if (ret != NULL) {
        HuDecode(info.file_bytes, ret, info.size, info.compression_type);
    }
    return ret;
}

void * func_80009E04_AA04(s32 type, s32 index, s16 arg2) {
    struct mainfs_entry_info sp10;
    void * temp_v0;

    func_80009B64_A764(type, index, &sp10);
    temp_v0 = HuMemAllocTag((sp10.size + 1) & ~1, arg2);
    if (temp_v0 != 0) {
        HuDecode(sp10.file_bytes, temp_v0, sp10.size, sp10.compression_type);
    }
    return temp_v0;
}

INCLUDE_ASM(s32, "data", func_80009E6C_AA6C);

INCLUDE_ASM(s32, "data", func_80009E8C_AA8C);

typedef struct
{
    s32 tablePtr;
    s32 unk0004;    // not used
    s32 unk0008;    // not used
    s32 unk000C;    // not used
} HuDataInfo;

void func_80009EAC_AAAC(s32 arg1, s32 arg2)
{
    u32 temp_s0_2;
    struct mainfs_table_header * fsHeader;
    HuDataInfo info;

    info.tablePtr = D_800ABFC0 + D_800ABFC8[arg2];
    
    if (D_800ABFCC != info.tablePtr) {
        if (D_800ABFCC != D_800ABFC0) {
            HuMemMemoryFreePerm(D_800ABFD4);
        }
        
        D_800ABFCC = info.tablePtr;
        
        fsHeader = &D_800ABFE0;
        HuRomDmaRead((s32) D_800ABFCC, fsHeader, 16);
        
        D_800ABFD0 = D_800ABFE0.count;
        temp_s0_2 = D_800ABFD0 * 4;
        D_800ABFD4 = HuMemMemoryAllocPerm(temp_s0_2);
        HuRomDmaRead((u32) (info.tablePtr + 4), D_800ABFD4, (s32) temp_s0_2);
    }
}

INCLUDE_ASM(s32, "data", func_80009F64_AB64);

INCLUDE_ASM(s32, "data", func_80009FF8_ABF8);

INCLUDE_ASM(s32, "data", func_8000A028_AC28);

INCLUDE_ASM(s32, "data", func_8000A0D4_ACD4);

INCLUDE_ASM(s32, "data", func_8000A150_AD50);
