#ifndef _SIMAN_H
#define _SIMAN_H

#include <libultra.h>

#define HOS_PRIORITY_SIMGR 0x5A

typedef s32 (*HuSiFuncVoid)(void);
typedef s32 (*HuSiFunc)(void *);

typedef struct functionListEntryt {
    struct functionListEntryt *child;
    HuSiFuncVoid func;
    s16 type;
} functionListEntry;

typedef struct {
    HuSiFunc func;
    //functionListEntry *pFuncListEntry;
    void* arg;
    s32 ret;
    OSMesgQueue *recvQueue;
} unkMesg;

typedef struct {
    s32 unk0[4];
    unkMesg* unkMsg;
} unkMesgWrapper;

void func_80051750_52350(void);
functionListEntry ** func_800517F4_523F4(functionListEntry* entry);
s32 func_8005182C_5242C(functionListEntry* node);
void func_8005188C_5248C(functionListEntry* entry, s16 type, void* func);
s32 func_800518FC_524FC(functionListEntry* arg0);
void func_80051968_52568(void* entry);
void func_800519D0_525D0(s16 type);
s32 func_80051B0C_5270C(unkMesg* siMessg, HuSiFunc func, void* arg, s32 type);
void func_800511C4_51DC4(unkMesgWrapper*, OSMesgQueue*, s32);
void func_80051A44_52644(void* arg0);

extern void *D_800BCD00;
extern void *D_800BCD80;
extern OSThread D_800BCE00;

extern functionListEntry *D_800BD7B0;
extern functionListEntry *D_800BD7B4;

extern OSMesgQueue D_800CE1A0;
extern OSMesgQueue D_800D1220;

#endif