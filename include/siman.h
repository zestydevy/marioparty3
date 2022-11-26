#ifndef _SIMAN_H
#define _SIMAN_H

#include <libultra.h>

#define HOS_PRIORITY_SIMGR 0x5A

typedef struct functionListEntryt {
    struct functionListEntryt *child;
    void (*pFunc) ();
    s16 type;
} functionListEntry;

typedef struct {
    s32 (*pFunc) (functionListEntry*);
    functionListEntry *pFuncListEntry;
    s32 ret;
    OSMesgQueue *recvQueue;
} unkMesg;

typedef struct {
    s32 unk0[4];
    unkMesg* unkMsg;
} unkMesgWrapper;

void func_800511C4_51DC4(unkMesgWrapper*, OSMesgQueue*, s32);
void func_80051A44_52644(void * arg0);

extern void *D_800BCD00;
extern void *D_800BCD80;
extern OSThread D_800BCE00;

extern functionListEntry *D_800BD7B0;
extern functionListEntry *D_800BD7B4;

extern OSMesgQueue D_800CE1A0;
extern OSMesgQueue D_800D1220;

#endif