#ifndef __MALLOC_H
#define __MALLOC_H

#include <libultra.h>

struct heap_node
{
    s32 size;                   // 0000
    u8 heap_constant;           // 0004
    u8 used; // bool            // 0005
    struct heap_node *prev;     // 0008
    struct heap_node *next;     // 000C
};

void * HuMemHeapInit(void *ptr, u32 size);
void * HuMemMemoryAlloc(struct heap_node *heap, s32 size);
void HuMemMemoryFree(void *ptr);
void * HuMemMemoryRealloc(struct heap_node *heap, void *mem, u32 new_size);
u32 HuMemHeapAllocSizeGet(struct heap_node *heap);
u32 HuMemUsedMemoryBlockGet(struct heap_node *heap);
s32 HuMemMemoryAllocSizeGet(s32 value);

struct heap_node * HuMemHeapInitPerm(void *ptr, u32 size);
void * HuMemMemoryAllocPerm(u32 size);
void HuMemMemoryFreePerm(void *ptr);
void * HuMemMemoryReallocPerm(void *mem, u32 new_size);
u32 HuMemHeapAllocPermSizeGet(void);
u32 HuMemUsedMemoryBlockGetPerm(void);

struct heap_node * HuMemHeapInitTemp(void *ptr, u32 size);
void * HuMemMemoryAllocTemp(u32 size);
void HuMemMemoryFreeTemp(void *ptr);
void * HuMemMemoryReallocTemp(void *mem, u32 new_size);
u32 HuMemHeapAllocTempSizeGet(void);
u32 HuMemUsedMemoryBlockGetTemp(void);

#endif