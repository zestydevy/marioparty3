#ifndef __MALLOCBLOCK_H
#define __MALLOCBLOCK_H

#include "libultra.h"

typedef struct HuMallocHeader
{
    void * data;                    // 0000
    u8 unk4;                        // 0004
    u8 unk5;                        // 0005
    s16 unk6;                       // 0006
    s32 size;                       // 0008
    s32 unkC;                       // 000C
    struct HuMallocHeader * prev;   // 0010
    struct HuMallocHeader * next;   // 0014
} HuMallocHeader;

typedef HuMallocHeader *(*HuAllocFunc)(u32 size);
typedef void (*HuFreeFunc)(void * ptr);

extern s16 D_800A08A0_A14A0;
extern s16 D_800A08A2_A14A2;

extern s16 D_800C993C;
extern void * D_800C9950[];

extern HuMallocHeader * D_800D03F4;
extern void (*D_800D135C)(void * ptr);
extern HuMallocHeader * D_800D1238;
extern u8 D_800D1FF0;
extern s32 D_800D20AC;
extern void * D_800D2140[];
extern HuAllocFunc D_800D556C;
extern HuMallocHeader * D_800D6B68;


void func_80019980_1A580(HuAllocFunc malloc, HuFreeFunc free);
void func_800199F8_1A5F8(s32 arg0);
void * func_80019A14_1A614(s32 size, s16 arg1);
void func_80019A98_1A698(void * arg0);
void func_80019AF0_1A6F0(HuMallocHeader * block);
void func_80019B34_1A734(s16 arg0);
void func_80019C00_1A800(void * arg0);
void func_80019C68_1A868(s16 arg0);
void func_80019CDC_1A8DC(void);
void func_80019CEC_1A8EC(void);
void func_80019D64_1A964(void);

#endif