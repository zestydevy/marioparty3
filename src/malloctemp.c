#include "common.h"
#include "malloc.h"

/*
* Temporary heap. Reset occasionally during gameplay.
 */

extern struct heap_node* temp_heap_addr;

/*
* Creates the temporary heap.
 */
struct heap_node* HuMemHeapInitTemp(void *ptr, u32 size)
{
    temp_heap_addr = (struct heap_node *)HuMemHeapInit(ptr, size);
}

/*
* Allocates memory in the Tempanent heap.
 */
void* HuMemMemoryAllocTemp(u32 size)
{
    HuMemMemoryAlloc(temp_heap_addr, size);
}

/*
* Frees a memory pointer in the Tempanent heap.
 */
void HuMemMemoryFreeTemp(void *ptr)
{
    HuMemMemoryFree(ptr);
}

/*
* Resizes a previously allocated Tempanent heap buffer.
 */
void* HuMemMemoryReallocTemp(void *mem, u32 new_size)
{
    return (void *)HuMemMemoryRealloc(temp_heap_addr, mem, new_size);
}

/*
* Returns the total size of allocated buffers in the Tempanent heap.
 */
u32 HuMemHeapAllocTempSizeGet(void)
{
    return HuMemHeapAllocSizeGet(temp_heap_addr);
}

u32 HuMemUsedMemoryBlockGetTemp(void)
{
    return HuMemUsedMemoryBlockGet(temp_heap_addr);
}
