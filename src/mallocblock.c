#include "common.h"
#include "mallocblock.h"

void HuMemInit(HuAllocFunc malloc, HuFreeFunc free)
{
    HuMallocHeader * newBlock;

    gMallocFunc = malloc;
    gFreeFunc = free;
    
    if (gHuMemIsDirty) {
        HuMemFreeAll();
    }
    
    newBlock = gMallocFunc(sizeof(HuMallocHeader));
    gLastMallocBlock = newBlock;
    gFirstMallocBlock = newBlock;
    
    newBlock->data = NULL;
    newBlock->tag = -1;
    newBlock->prev = newBlock;
    newBlock->next = newBlock;
    
    D_800C993C = 0;
}

void HuMemAlloc(s32 size) {
    HuMemAllocTag(size, 0);
}

void * HuMemAllocTag(s32 size, s16 tag)
{
    s32 alignedSize;
    void * data;
    HuMallocHeader * firstBlk;
    HuMallocHeader * newBlk;

    alignedSize = (size + 7) & ~7;
    data = gMallocFunc(alignedSize + sizeof(HuMallocHeader));
    newBlk = (HuMallocHeader *)((s32)data + alignedSize);
    
    firstBlk = gFirstMallocBlock;
    
    newBlk->prev = firstBlk;
    newBlk->next = firstBlk->next;
    firstBlk->next->prev = newBlk;
    firstBlk->next = newBlk;
    
    newBlk->tag = tag;
    newBlk->size = alignedSize;
    newBlk->data = data;
    newBlk->unkC = D_800D20AC;
    
    return newBlk->data;
}

void HuMemFree(void * data)
{
    HuMallocHeader * block = gFirstMallocBlock->next;
    while (data != block->data)
    {
        block = block->next;
        if (block == gLastMallocBlock) {
            return;
        } 
    }
    HuMemBlockFree(block);
}

void HuMemBlockFree(HuMallocHeader * block)
{
    gLastFreedBlock = block;

    block->next->prev = block->prev;
    block->prev->next = block->next;

    gFreeFunc(block->data);
}

void HuMemFreeAllWithTag(s16 tag)
{
    HuMallocHeader * prevBlk;
    HuMallocHeader * block;

    for (block = gFirstMallocBlock->next; block != gLastMallocBlock; block = block->next)
    {
        if (block->tag == tag)
        {
            if (block->tag != -1) {
                prevBlk = block->prev;
                HuMemBlockFree(block);
                block = prevBlk;
            } else {
                if (--block->unk4 == 0) 
                {
                    prevBlk = block->prev;
                    HuMemBlockFree(block);
                    block = prevBlk;
                    
                    if (--D_800C993C <= 0) {
                        break;
                    }
                }
            }
        }
    }
}

void func_80019C00_1A800(void * data)
{
    HuMallocHeader * block;

    block = gFirstMallocBlock->next;
    while (data != block->data) {
        block = block->next;
         if (block == gLastMallocBlock) { 
            return;    
        }
    }

    block->tag = -1;
    block->unk4 = D_800D1FF0 + 1;
    
    ++D_800C993C;
}

void func_80019C68_1A868(s16 arg0)
{
    HuMallocHeader * block;

    block = gFirstMallocBlock->next;
    while (block != gLastMallocBlock) 
    {
        if (block->tag == arg0) {
            block->tag = -1;
            block->unk4 = D_800D1FF0 + 1;
            ++D_800C993C;
        }
        block = block->next;
    }
}

void HuMemSetDirty(void) {
    gHuMemIsDirty = TRUE;
}

void HuMemFreeAll(void)
{
    HuMallocHeader * prevBlk;
    HuMallocHeader * block;

    block = gFirstMallocBlock->next;
    while (block != gLastMallocBlock)
    {
        prevBlk = block->prev;
        HuMemBlockFree(block);
        block = prevBlk->next;
    }
    
    gFreeFunc((void *)gLastMallocBlock);
    
    D_800C993C = 0;
    gHuMemIsDirty = FALSE;
}

void HuMemCleanUp(void)
{
    if (gHuMemIsDirty) {
        HuMemFreeAll();
    }
    else if (D_800C993C != 0) {
        HuMemFreeAllWithTag(-1);
    }
}

s32 HuMemGetSizeTag(s16 tag)
{
    HuMallocHeader * block;
    s32 size;

    block = gFirstMallocBlock->next;
    size = 0;
    while (block != gLastMallocBlock) {
        if (block->tag == tag) {
            size += block->size;
        }
        block = block->next;
    }
    return size;
}

s32 HuMemGetSize(void)
{
    HuMallocHeader * block;
    s32 size;

    block = gFirstMallocBlock->next;
    size = 0;
    while (block != gLastMallocBlock) {
        size += block->size;
        block = block->next;
    }
    return size;
}

void HuMemSetTag(void * data, s16 tag)
{
    HuMallocHeader * block;

    block = gFirstMallocBlock->next;
    while (data != block->data) {
        block = block->next;
        if (block == gLastMallocBlock) {
            return;
        }
    }
    block->tag = tag;
}

s32 HuMemDebugCheck(void)
{
    HuMallocHeader * block;
    s16 i;
    s16 count;
    s16 var_v1;
    s32 size;

    block = gFirstMallocBlock->next;
    size = 0;
    count = 0;
    while (block != gLastMallocBlock)
    {
        D_800C9950[count] = block->data;
        size += block->size;
        block = block->next;
        count++;
    }

    if ((D_800A08A2_A14A2 != 0) && (D_800A08A2_A14A2 != count)) {
        for (i = 0; i < count; i++) 
        {
            for (var_v1 = 0; var_v1 < D_800A08A2_A14A2; var_v1++) 
            {
                if (D_800D2140[var_v1] == D_800C9950[i]) 
                    break;
            }
            if (var_v1 == D_800A08A2_A14A2) {
                osSyncPrintf("%x\n", D_800C9950[i]);
            }
        }
    }

    D_800A08A2_A14A2 = count;
    for (i = 0; i < count; i++) 
    {
        D_800D2140[i] = D_800C9950[i];
    }
    return size;
}
