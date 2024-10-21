#ifndef _OBJ_H
#define _OBJ_H

#include "common.h"
#include "common_structs.h"
#include "malloc.h"
#include "process.h"

typedef void (*HuObjFunc)(void* func);

typedef struct omObjData {
/* 0x00 */ u16 stat;
/* 0x02 */ s16 next_idx_alloc;
/* 0x04 */ s16 prio;
/* 0x06 */ s16 prev;
/* 0x08 */ s16 next;
/* 0x0A */ s16 next_idx;
/* 0x0C */ s16 group;
/* 0x0E */ s16 group_idx;
/* 0x10 */ s32 unk_10;
/* 0x14 */ void* func_ptr;
/* 0x18 */ Vec trans;
/* 0x24 */ Vec rot;
/* 0x30 */ Vec scale;
/* 0x3C */ u16 mdlcnt;
// /* 0x3E */ char unk_3E[2];
/* 0x40 */ s16* model;
/* 0x44 */ u16 mtncnt;
// /* 0x46 */ char unk_46[2];
/* 0x48 */ s16* motion;
/* 0x4C */ u32 work[4];
/* 0x5C */ void* unk_5C;
} omObjData; //sizeof 0x60

typedef struct
{
    u16 unk0;                   // 0000
    u16 unk2;                   // 0002
    Process* prc;       // 0004
    process_func unk8;          // 0008
} HuObjUnk0;

typedef struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16* unk8;
    omObjData** objs;        // 000C
} HuObjUnk1;

void omPrcSetStatBit(Process*, s32);
void omPrcResetStatBit(Process*, s32);
s32 omOvlGotoEx(s32, s16, u16);
s32 omOvlReturnEx(s16 level);
void omInitObjMan(s32 numOfObjs, s32 numOfPrcs);
void omInsertObj(omObjData * obj);
void func_80047CDC_488DC(u16 arg0, omObjData * obj);
Process* omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize);
void omDestroyPrcObj(void);
omObjData* omAddObj(s16 priority, u16 arg1, u16 arg2, s16 arg3, HuObjFunc func);
s32 omOvlCallEx(s32 arg0, s16 arg1, u16 arg2);
void omMain(void);
void omDestroyObjMan(void);

#endif
