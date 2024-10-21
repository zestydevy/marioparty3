#include "common.h"
#include "malloc.h"

/*
* Primary heap. Never reset during gameplay.
 */
extern HeapNode* perm_heap_addr;

/*
* Creates the "permanent" heap that is never reset.
* Called once during startup.
 */
HeapNode* HuMemHeapInitPerm(void *ptr, u32 size)
{
    perm_heap_addr = (HeapNode *)HuMemHeapInit(ptr, size);
}

/*
* Allocates memory in the permanent heap.
 */
void* HuMemMemoryAllocPerm(u32 size)
{
    HuMemMemoryAlloc(perm_heap_addr, size);
}

/*
* Frees a memory pointer in the permanent heap.
 */
void HuMemMemoryFreePerm(void *ptr)
{
    HuMemMemoryFree(ptr);
}

/*
* Resizes a previously allocated permanent heap buffer.
 */
void* HuMemMemoryReallocPerm(void *mem, u32 new_size)
{
    return (void *)HuMemMemoryRealloc(perm_heap_addr, mem, new_size);
}

/*
* Returns the total size of allocated buffers in the permanent heap.
 */
u32 HuMemHeapAllocPermSizeGet(void)
{
    return HuMemUsedMemorySizeGet(perm_heap_addr);
}

u32 HuMemUsedMemoryBlockGetPerm(void)
{
    return HuMemUsedMemoryBlockGet(perm_heap_addr);
}
