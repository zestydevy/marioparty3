#ifndef _SIMAN_H
#define _SIMAN_H

#include <libultra.h>

#define HOS_PRIORITY_SIMGR 0x5A

typedef struct
{
    s32 unk0;
    s32 unk4;
    s16 unk8;
} Hu523F4_0;

void func_80051A44_52644(void * arg0);                   /* extern */
s32 * func_800517F4_523F4(Hu523F4_0 * arg0);
extern void *D_800BCD00;
extern void *D_800BCD80;
extern OSThread D_800BCE00;
extern s32 D_800BD7B0;
extern s32 D_800BD7B4;
extern OSMesgQueue D_800CE1A0;
extern OSMesgQueue D_800D1220;

#endif