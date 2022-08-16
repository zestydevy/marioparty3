#include "common.h"
#include "mallocblock.h"

void func_80019980_1A580(HuAllocFunc malloc, HuFreeFunc free)
{
    HuMallocHeader * temp_v0;

    D_800D556C = malloc;
    D_800D135C = free;
    
    if (D_800A08A0_A14A0 != 0) {
        func_80019CEC_1A8EC();
    }
    
    temp_v0 = D_800D556C(sizeof(HuMallocHeader));
    D_800D03F4 = temp_v0;
    D_800D6B68 = temp_v0;
    
    temp_v0->data = NULL;
    temp_v0->unk6 = -1;
    temp_v0->prev = temp_v0;
    temp_v0->next = temp_v0;
    
    D_800C993C = 0;
}

void func_800199F8_1A5F8(s32 arg0) {
    func_80019A14_1A614(arg0, 0);
}

void * func_80019A14_1A614(s32 size, s16 arg1)
{
    s32 temp_s0;
    HuMallocHeader * temp_a1;
    HuMallocHeader * temp_v0;
    HuMallocHeader * temp_v1;

    temp_s0 = (size + 7) & ~7;
    temp_v0 = D_800D556C(temp_s0 + (s32)sizeof(HuMallocHeader));
    temp_v1 = (HuMallocHeader *)((s32)temp_v0 + temp_s0);
    
    temp_a1 = D_800D6B68;
    
    temp_v1->prev = temp_a1;
    temp_v1->next = temp_a1->next;
    temp_a1->next->prev = temp_v1;
    temp_a1->next = temp_v1;
    
    temp_v1->unk6 = arg1;
    temp_v1->size = temp_s0;
    temp_v1->data = temp_v0;
    temp_v1->unkC = D_800D20AC;
    
    return temp_v1->data;
}

void func_80019A98_1A698(void * arg0)
{
    HuMallocHeader * var_a0 = D_800D6B68->next;
    while (arg0 != var_a0->data)
    {
        var_a0 = var_a0->next;
        if (var_a0 == D_800D03F4) {
            return;
        } 
    }
    func_80019AF0_1A6F0(var_a0);
}

void func_80019AF0_1A6F0(HuMallocHeader * block)
{
    D_800D1238 = block;

    block->next->prev = block->prev;
    block->prev->next = block->next;

    D_800D135C(block->data);
}

void func_80019B34_1A734(s16 arg0)
{
    s16 temp_v0;
    HuMallocHeader * temp_s0;
    HuMallocHeader * temp_s0_2;
    HuMallocHeader * var_a0;

    for (var_a0 = D_800D6B68->next; var_a0 != D_800D03F4; var_a0 = var_a0->next) {
        temp_v0 = var_a0->unk6;
        if (temp_v0 == arg0) {
            if (temp_v0 != -1) {
                temp_s0 = var_a0->prev;
                func_80019AF0_1A6F0(var_a0);
                var_a0 = temp_s0;
            } else {
                if (--var_a0->unk4 == 0) {
                    temp_s0_2 = var_a0->prev;
                    func_80019AF0_1A6F0(var_a0);
                    var_a0 = temp_s0_2;
                    if (--D_800C993C <= 0) {
                        break;
                    }
                }
            }
        }
    }
}

void func_80019C00_1A800(void * arg0)
{
    HuMallocHeader * var_v1;

    var_v1 = D_800D6B68->next;
    while (arg0 != var_v1->data) {
        var_v1 = var_v1->next;
         if (var_v1 == D_800D03F4) { 
            return;    
        }
    }

    var_v1->unk6 = -1;
    var_v1->unk4 = D_800D1FF0 + 1;
    
    ++D_800C993C;
}

void func_80019C68_1A868(s16 arg0)
{
    HuMallocHeader * var_v1;

    var_v1 = D_800D6B68->next;
    while (var_v1 != D_800D03F4) {
        if (var_v1->unk6 == arg0) {
            var_v1->unk6 = -1;
            var_v1->unk4 = D_800D1FF0 + 1;
            ++D_800C993C;
        }
        var_v1 = var_v1->next;
    }
}

void func_80019CDC_1A8DC(void) {
    D_800A08A0_A14A0 = 1;
}

void func_80019CEC_1A8EC(void)
{
    HuMallocHeader * temp_s0;
    HuMallocHeader * var_a0;

    var_a0 = D_800D6B68->next;
    while (var_a0 != D_800D03F4)
    {
        temp_s0 = var_a0->prev;
        func_80019AF0_1A6F0(var_a0);
        var_a0 = temp_s0->next;
    }
    
    D_800D135C((void *)D_800D03F4);
    
    D_800C993C = 0;
    D_800A08A0_A14A0 = 0;
}

void func_80019D64_1A964(void)
{
    if (D_800A08A0_A14A0 != 0) {
        func_80019CEC_1A8EC();
    }
    else if (D_800C993C != 0) {
        func_80019B34_1A734(-1);
    }
}

s32 func_80019DB0_1A9B0(s16 arg0)
{
    HuMallocHeader * var_v1;
    s32 var_a1;

    var_v1 = D_800D6B68->next;
    var_a1 = 0;
    while (var_v1 != D_800D03F4) {
        if (var_v1->unk6 == arg0) {
            var_a1 += var_v1->size;
        }
        var_v1 = var_v1->next;
    }
    return var_a1;
}

s32 func_80019E04_1AA04(void)
{
    HuMallocHeader * var_v1;
    s32 temp_v0;
    s32 var_a0;

    var_v1 = D_800D6B68->next;
    var_a0 = 0;
    while (var_v1 != D_800D03F4) {
        temp_v0 = var_v1->size;
        var_v1 = var_v1->next;
        var_a0 += temp_v0;
    }
    return var_a0;
}

void func_80019E40_1AA40(void * arg0, s16 arg1)
{
    HuMallocHeader * var_v1;

    var_v1 = D_800D6B68->next;
    while (arg0 != var_v1->data) {
        var_v1 = var_v1->next;
        if (var_v1 == D_800D03F4) {
            return;
        }
    }
    var_v1->unk6 = arg1;
}

s32 func_80019E84_1AA84(void)
{
    HuMallocHeader * var_a0;
    s16 var_s0;
    s16 var_s1;
    s16 var_v1;
    s32 var_s2;

    var_a0 = D_800D6B68->next;
    var_s2 = 0;
    var_s1 = 0;
    while (var_a0 != D_800D03F4)
    {
        D_800C9950[var_s1] = var_a0->data;
        var_s2 += var_a0->size;
        var_a0 = var_a0->next;
        var_s1++;
    }

    if ((D_800A08A2_A14A2 != 0) && (D_800A08A2_A14A2 != var_s1)) {
        for (var_s0 = 0; var_s0 < var_s1; var_s0++) 
        {
            for (var_v1 = 0; var_v1 < D_800A08A2_A14A2; var_v1++) 
            {
                if (D_800D2140[var_v1] == D_800C9950[var_s0]) 
                    break;
            }
            if (var_v1 == D_800A08A2_A14A2) {
                osSyncPrintf("%x\n", D_800C9950[var_s0]);
            }
        }
    }

    D_800A08A2_A14A2 = var_s1;
    for (var_s0 = 0; var_s0 < var_s1; var_s0++) 
    {
        D_800D2140[var_s0] = D_800C9950[var_s0];
    }
    return var_s2;
}
