#include "common.h"
#include "malloc.h"

#define HEAP_CONSTANT 0xA5
#define MIN_ALLOC_SIZE 16

#define MIN_HEAP_NODE_SIZE sizeof(struct heap_node) + MIN_ALLOC_SIZE

extern s32 D_800A0530;

/*
 * Creates an empty heap of a given size.
 */
void * HuMemHeapInit(void * ptr, u32 size)
{
    struct heap_node * heap = (struct heap_node *)ptr;
    heap->size = size;
    heap->heap_constant = HEAP_CONSTANT;
    heap->used = 0;
    heap->prev = ptr;
    heap->next = ptr;
    return heap;
}

/*
 * Allocates the requested size of memory in the given heap.
 */
void * HuMemMemoryAlloc(struct heap_node * heap, s32 size)
{
    struct heap_node * cur_heap;
    struct heap_node * new_heap_temp;

    size = size + 0x1F;
    size = size & -16;

    cur_heap = heap;
    do
    {
        if (!cur_heap->used)
        {
            if (cur_heap->size >= size)
            {
                if ((u32)(cur_heap->size - size) > MIN_HEAP_NODE_SIZE)
                {
                    new_heap_temp = ((void *)cur_heap) + size;
                    new_heap_temp->size = cur_heap->size - size;
                    new_heap_temp->heap_constant = HEAP_CONSTANT;
                    new_heap_temp->used = FALSE;

                    cur_heap->next->prev = new_heap_temp;
                    new_heap_temp->next = cur_heap->next;
                    cur_heap->next = new_heap_temp;
                    new_heap_temp->prev = cur_heap;
                    cur_heap->size = size;
                }

                cur_heap->used = TRUE;
                return (void *)cur_heap + sizeof(struct heap_node);
            }
        }

        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    D_800A0530 = 0x10000;
    return NULL;
}

/*
 * Frees the given heap memory pointer.
 */
void HuMemMemoryFree(void *ptr)
{
    struct heap_node *given_heap;
    struct heap_node *heap_other;

    if (ptr == NULL)
    {
        return;
    }

    given_heap = (struct heap_node *)(ptr - sizeof(struct heap_node));
    if (given_heap->heap_constant != HEAP_CONSTANT)
    {
        D_800A0530 = 0x10001;
        return;
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"

    heap_other = given_heap->prev;
    if (((u32)heap_other < (u32)given_heap) && !heap_other->used)
    {
        given_heap->next->prev = heap_other;
        given_heap->prev->next = given_heap->next;
        given_heap->prev->size += given_heap->size;
        given_heap = given_heap->prev;
    }

    heap_other = given_heap->next;
    if (((u32)given_heap < (u32)heap_other) && !heap_other->used)
    {
        heap_other->next->prev = given_heap;
        given_heap->size += given_heap->next->size;
        given_heap->next = given_heap->next->next;
    }

#pragma GCC diagnostic pop

    given_heap->used = FALSE;
}

/*
 * Resizes a previously allocated buffer in a heap.
 */
void * HuMemMemoryRealloc(struct heap_node *heap, void *mem, u32 new_size)
{
    void *ret;
    struct heap_node *given_heap;
    struct heap_node *new_heap;
    s32 temp;

    given_heap = (struct heap_node *)(mem - sizeof(struct heap_node));
    temp = new_size + 0x1F;
    temp = temp & -16;

    if (given_heap->size >= temp)
    {
        if ((u32)(given_heap->size - temp) > MIN_HEAP_NODE_SIZE)
        {
            new_heap = (void *)given_heap + temp;
            new_heap->size = given_heap->size - temp;
            new_heap->heap_constant = HEAP_CONSTANT;
            new_heap->used = FALSE;
            given_heap->next->prev = new_heap;
            new_heap->next = given_heap->next;
            given_heap->next = new_heap;
            new_heap->prev = given_heap;
            given_heap->size = temp;
        }

        return (void *)given_heap + sizeof(struct heap_node);
    }
    else
    {
        ret = HuMemMemoryAlloc(heap, new_size);
        if (ret != NULL)
        {
            bcopy(mem, ret, given_heap->size - sizeof(struct heap_node));
            HuMemMemoryFree(mem);
        }

        return ret;
    }

    return NULL;
}

/*
 * Returns the total size of allocated buffers in a heap.
 */
u32 HuMemHeapAllocSizeGet(struct heap_node * heap)
{
    struct heap_node *cur_heap;
    u32 total_size;

    cur_heap = heap;
    total_size = 0;
    do
    {
        if (cur_heap->used == TRUE)
        {
            total_size += cur_heap->size;
        }
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return total_size;
}

/*
 * Counts the number of used nodes in the heap's doubly linked list.
 */
u32 HuMemUsedMemoryBlockGet(struct heap_node *heap)
{
    struct heap_node *cur_heap;
    u32 count_free;

    cur_heap = heap;
    count_free = 0;
    do
    {
        count_free += (cur_heap->used ^ TRUE) == FALSE ? 1 : 0;
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return count_free;
}

/*
 * Rounds a value up to align by 16.
 */
s32 HuMemMemoryAllocSizeGet(s32 value)
{
    return (value + 0x1F) & -16;
}
