#include "common.h"

#include "process.h"
#include "malloc.h"

extern jmp_buf process_jmp_buf;
extern struct process *top_process;
extern struct process *current_process;
extern s16 process_count;

// pointer to where HuPrcVSleep was called
extern s32 * sPrcSleepLoc;

void HuPrcSysInit()
{
    process_count = 0;
    top_process = NULL;
}

void HuPrcLink(struct process **root, struct process *process)
{
    struct process *src_process = *root;
    if (src_process != NULL && (src_process->priority >= process->priority))
    {
        while (src_process->next != NULL)
        {
            if (src_process->next->priority < process->priority)
            {
                break;
            }
            src_process = src_process->next;
        }

        process->next = src_process->next;
        process->youngest_child = src_process;
        src_process->next = process;
        if (process->next)
        {
            process->next->youngest_child = process;
        }
    }
    else
    {
        process->next = (*root);
        process->youngest_child = NULL;
        *root = process;
        if (src_process != NULL)
        {
            src_process->youngest_child = process;
        }
    }
}

void HuPrcUnlink(struct process **root, struct process *process)
{
    if (process->next)
    {
        process->next->youngest_child = process->youngest_child;
    }
    if (process->youngest_child)
    {
        process->youngest_child->next = process->next;
    }
    else
    {
        *root = process->next;
    }
}

struct process * HuPrcCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size)
{
    struct heap_node *process_heap;
    struct process *process;
    s32 alloc_size;

    if (stack_size == 0) {
        stack_size = 2048;
    }

    alloc_size = HuMemMemoryAllocSizeGet(sizeof(struct process))
        + HuMemMemoryAllocSizeGet(stack_size)
        + HuMemMemoryAllocSizeGet(extra_data_size);

    process_heap = (struct heap_node *)HuMemMemoryAllocPerm(alloc_size);
    if (process_heap == NULL) {
        return NULL;
    }
    HuMemHeapInit(process_heap, alloc_size);

    process = (struct process *)HuMemMemoryAlloc(process_heap, sizeof(struct process));
    process->heap = process_heap;
    process->exec_mode = EXEC_PROCESS_DEFAULT;
    process->stat = 0;
    process->priority = priority;
    process->sleep_time = 0;
    process->base_sp = HuMemMemoryAlloc(process_heap, stack_size) + stack_size - 8;
    process->prc_jump.func = func;
    process->prc_jump.sp = process->base_sp;
    process->destructor = NULL;
    process->user_data = NULL;
    process->dtor_idx = 0;
    HuPrcLink(&top_process, process);
    process->oldest_child = NULL;
    process->relative = NULL;
    process_count++;
    return process;
}

void HuPrcChildLink(struct process *process, struct process *child)
{
    HuPrcChildUnlink(child);
    if (process->oldest_child)
    {
        process->oldest_child->new_process = child;
    }
    child->parent_oldest_child = process->oldest_child;
    child->new_process = NULL;
    process->oldest_child = child;
    child->relative = process;
}

void HuPrcChildUnlink(struct process *process)
{
    if (process->relative)
    {
        if (process->parent_oldest_child)
        {
            process->parent_oldest_child->new_process = process->new_process;
        }
        if (process->new_process)
        {
            process->new_process->parent_oldest_child = process->parent_oldest_child;
        }
        else
        {
            process->relative->oldest_child = process->parent_oldest_child;
        }
        process->relative = NULL;
    }
}

struct process * HuPrcCreateChild(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, struct process * parent)
{
    struct process * child = HuPrcCreate(func, priority, stack_size, extra_data_size);
    HuPrcChildLink(parent, child);
    return child;
}

void HuPrcChildWait()
{
    struct process *process = HuPrcGetCurrent();
    if (process->oldest_child)
    {
        process->exec_mode = EXEC_PROCESS_WATCH;
        if (!setjmp(&process->prc_jump))
        {
            longjmp(&process_jmp_buf, 1);
        }
    }
}

struct process * HuPrcGetCurrent()
{
    return current_process;
}

s32 HuPrcChildGet(struct process *process)
{
    s32 i;
    struct process *curr_child = process->oldest_child;
    i = 0;
    while (curr_child)
    {
        curr_child = curr_child->parent_oldest_child;
        i++;
    }
    return i;
}

s32 HuPrcStatKill(struct process *process)
{
    if (process->exec_mode != EXEC_PROCESS_DEAD)
    {
        HuPrcAwake(process);
        process->exec_mode = EXEC_PROCESS_DEAD;
        return 0;
    }
    else
    {
        return -1;
    }
}

void HuPrcKill(struct process *process)
{
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    HuPrcStatKill(process);
}

void HuPrcChildKill(struct process *process)
{
    struct process *curr_child = process->oldest_child;
    while (curr_child != NULL)
    {
        if (curr_child->oldest_child != NULL) {
            HuPrcChildKill(curr_child);
        }
        HuPrcStatKill(curr_child);
        curr_child = curr_child->parent_oldest_child;
    }
    process->oldest_child = NULL;
}

void HuPrcTerminate(struct process *process)
{
    if (process->destructor)
    {
        process->destructor();
    }
    HuPrcUnlink(&top_process, process);
    process_count--;
    longjmp(&process_jmp_buf, 2);
}

void HuPrcExit()
{
    struct process *process = HuPrcGetCurrent();
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    HuPrcTerminate(process);
}

void HuPrcSleep(s32 time)
{
    struct process *process = HuPrcGetCurrent();
    if (time != 0 && process->exec_mode != EXEC_PROCESS_DEAD)
    {
        process->exec_mode = EXEC_PROCESS_SLEEPING;
        process->sleep_time = time;
    }
    if (!setjmp(&process->prc_jump))
    {
        longjmp(&process_jmp_buf, 1);
    }
}

void HuPrcVSleep()
{
    HuPrcSleep(0);
}

void HuPrcAwake(struct process *process)
{
    process->sleep_time = 0;
}

void HuPrcDtor(struct process *process, process_func destructor)
{
    process->destructor = destructor;
}

void HuPrcCurrentDtor(process_func destructor)
{
    struct process *process = HuPrcGetCurrent();
    HuPrcDtor(process, destructor);
}

void HuPrcCall(s32 time)
 {
    struct process *cur_proc_local;
    s32 ret;

    current_process = top_process;
    ret = setjmp(&process_jmp_buf);
    while (1)
    {
        switch (ret)
        {
            case 2:
                HuMemMemoryFreePerm(current_process->heap);
                current_process = current_process->next;
                break;
            case 1:
                current_process = current_process->next;
                break;
        }

        cur_proc_local = current_process;
        if (cur_proc_local == 0)
        {
            break;
        }

        sPrcSleepLoc = current_process->prc_jump.sp[10];
         
        if ((cur_proc_local->stat & 0x1))
        {
            if (cur_proc_local->exec_mode != 3)
            {
                ret = 1;
                continue;
            }
        }

        switch (cur_proc_local->exec_mode)
        {
            case EXEC_PROCESS_SLEEPING:
                if (cur_proc_local->sleep_time > 0 && (cur_proc_local->sleep_time -= time) <= 0)
                {
                    cur_proc_local->sleep_time = 0;
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                }
                ret = 1;
                break;

            case EXEC_PROCESS_WATCH:
                if (cur_proc_local->oldest_child != 0)
                {
                    ret = 1;
                }
                else
                {
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                    ret = 0;
                }
                break;

            case EXEC_PROCESS_DEAD:
                cur_proc_local->prc_jump.func = HuPrcExit;

            case 0:
                longjmp(&cur_proc_local->prc_jump, 1);
                break;
        }
    }
}

void * HuPrcAllocMem(s32 size)
{
    struct process *process = HuPrcGetCurrent();
    return (void *)HuMemMemoryAlloc((struct heap_node *)process->heap, size);
}

void HuPrcFreeMem(void *ptr)
{
    HuMemMemoryFree(ptr);
}
