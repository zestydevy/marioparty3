#include "common.h"

#include "process.h"
#include "malloc.h"

extern jmp_buf process_jmp_buf;
extern Process* top_process;
extern Process* current_process;
extern s16 process_count;

// pointer to where HuPrcVSleep was called
extern u32 sPrcSleepLoc;

void HuPrcSysInit()
{
    process_count = 0;
    top_process = NULL;
}

void HuPrcLink(Process** root, Process* process)
{
    Process* src_process = *root;
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

void HuPrcUnlink(Process** root, Process* process)
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

Process* HuPrcCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size)
{
    HeapNode *process_heap;
    Process* process;
    s32 alloc_size;

    if (stack_size == 0) {
        stack_size = 2048;
    }

    alloc_size = HuMemMemoryAllocSizeGet(sizeof(Process))
        + HuMemMemoryAllocSizeGet(stack_size)
        + HuMemMemoryAllocSizeGet(extra_data_size);

    process_heap = (HeapNode *)HuMemMemoryAllocPerm(alloc_size);
    if (process_heap == NULL) {
        return NULL;
    }
    HuMemHeapInit(process_heap, alloc_size);

    process = (Process*)HuMemMemoryAlloc(process_heap, sizeof(Process));
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

void HuPrcChildLink(Process* process, Process* child)
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

void HuPrcChildUnlink(Process* process)
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

Process* HuPrcCreateChild(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, Process* parent)
{
    Process* child = HuPrcCreate(func, priority, stack_size, extra_data_size);
    HuPrcChildLink(parent, child);
    return child;
}

void HuPrcChildWait()
{
    Process* process = HuPrcCurrentGet();
    if (process->oldest_child)
    {
        process->exec_mode = EXEC_PROCESS_WATCH;
        if (!setjmp(&process->prc_jump))
        {
            longjmp(&process_jmp_buf, 1);
        }
    }
}

Process* HuPrcCurrentGet()
{
    return current_process;
}

s32 HuPrcChildGet(Process* process)
{
    s32 i;
    Process* curr_child = process->oldest_child;
    i = 0;
    while (curr_child)
    {
        curr_child = curr_child->parent_oldest_child;
        i++;
    }
    return i;
}

s32 HuPrcStatKill(Process* process)
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

void HuPrcKill(Process* process)
{
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    HuPrcStatKill(process);
}

void HuPrcChildKill(Process* process)
{
    Process* curr_child = process->oldest_child;
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

void HuPrcTerminate(Process* process)
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
    Process* process = HuPrcCurrentGet();
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    HuPrcTerminate(process);
}

void HuPrcSleep(s32 time)
{
    Process* process = HuPrcCurrentGet();
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

void HuPrcAwake(Process* process)
{
    process->sleep_time = 0;
}

void HuPrcDtor(Process* process, process_func destructor)
{
    process->destructor = destructor;
}

void HuPrcCurrentDtor(process_func destructor)
{
    Process* process = HuPrcCurrentGet();
    HuPrcDtor(process, destructor);
}

void HuPrcCall(s32 time)
 {
    Process* cur_proc_local;
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
    Process* process = HuPrcCurrentGet();
    return (void *)HuMemMemoryAlloc((HeapNode *)process->heap, size);
}

void HuPrcFreeMem(void *ptr)
{
    HuMemMemoryFree(ptr);
}
