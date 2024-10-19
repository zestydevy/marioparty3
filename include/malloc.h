#ifndef __MALLOC_H
#define __MALLOC_H

#include <libultra.h>

typedef struct HeapNode {
/* 0x00 */ s32 size;
/* 0x04 */ u8 heap_constant;
/* 0x05 */ u8 active;
/* 0x08 */ struct HeapNode* prev;
/* 0x0C */ struct HeapNode* next;
} HeapNode;

void* HuMemHeapInit(void *ptr, u32 size);
void* HuMemMemoryAlloc(HeapNode *heap, s32 size);
void HuMemMemoryFree(void *ptr);
void* HuMemMemoryRealloc(HeapNode *heap, void *mem, u32 new_size);
u32 HuMemUsedMemorySizeGet(HeapNode *heap);
u32 HuMemUsedMemoryBlockGet(HeapNode *heap);
s32 HuMemMemoryAllocSizeGet(s32 value);

HeapNode* HuMemHeapInitPerm(void *ptr, u32 size);
void* HuMemMemoryAllocPerm(u32 size);
void HuMemMemoryFreePerm(void *ptr);
void* HuMemMemoryReallocPerm(void *mem, u32 new_size);
u32 HuMemHeapAllocPermSizeGet(void);
u32 HuMemUsedMemoryBlockGetPerm(void);

HeapNode* HuMemHeapInitTemp(void *ptr, u32 size);
void* HuMemMemoryAllocTemp(u32 size);
void HuMemMemoryFreeTemp(void *ptr);
void* HuMemMemoryReallocTemp(void *mem, u32 new_size);
u32 HuMemHeapAllocTempSizeGet(void);
u32 HuMemUsedMemoryBlockGetTemp(void);

#endif