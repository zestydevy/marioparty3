#ifndef _OBJ_H
#define _OBJ_H

#include "common.h"
#include "common_structs.h"
#include "malloc.h"
#include "process.h"

typedef void (*HuObjFunc)(void * func);

typedef struct HuObjInfo 
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;

    HuObjFunc func;

    // Three HuVec3F groups (Scale?, Rotation?, Position?)
    HuVec3F unk18;
    HuVec3F unk24;
    HuVec3F unk30;

    u16 unk3C; // count of unk40
    s16 *unk40;
    u16 unk44; // count of unk48
    s16 *unk48;

    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    struct HuObjInfo * unk5C;
} HuObjInfo; // sizeof 0x60

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
    u16 * unk8;
    HuObjInfo ** objs;        // 000C
} HuObjUnk1;

void HuObjInit(s32 numOfObjs, s32 numOfPrcs);
HuObjInfo * HuObjCreate(s16 priority, u16 arg1, u16 arg2, s16 arg3, HuObjFunc func);
void HuObjRegister(HuObjInfo * obj);
void func_80047CDC_488DC(u16 arg0, HuObjInfo * obj);
Process* HuObjPrcCreate(process_func func, u16 priority, s32 stackSize, s32 extDataSize);
void func_80048054_48C54(void);

#endif