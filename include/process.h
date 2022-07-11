#ifndef __PROCESS_H
#define __PROCESS_H

#include "libultra.h"

typedef struct jump_buf
{
    u32 * sp;
    void *func;
    u32 regs[21];
} jmp_buf;

extern s32 setjmp(jmp_buf *jump_buf);
extern s32 longjmp(jmp_buf *jump_buf, s32 val);

#define EXEC_PROCESS_DEFAULT 0
#define EXEC_PROCESS_SLEEPING 1
#define EXEC_PROCESS_WATCH 2
#define EXEC_PROCESS_DEAD 3

typedef void (*process_func)();

struct process
{
    /*0x00*/ struct process *next;
    /*0x04*/ struct process *youngest_child;
    /*0x08*/ struct process *oldest_child;
    /*0x0C*/ struct process *relative;
    /*0x10*/ struct process *parent_oldest_child;
    /*0x14*/ struct process *new_process;
    /*0x18*/ void *heap;
    /*0x1C*/ u16 exec_mode;
    /*0x1E*/ u16 stat;
    /*0x20*/ u16 priority;
    /*0x22*/ s16 dtor_idx;
    /*0x24*/ s32 sleep_time;
    /*0x28*/ void *base_sp;
    /*0x2C*/ jmp_buf prc_jump;
    /*0x88*/ process_func destructor;
    /*0x8C*/ void *user_data;
};

void HuPrcSysInit();
void HuPrcLink(struct process **root, struct process *process);
void HuPrcUnlink(struct process **root, struct process *process);
struct process * HuPrcCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size);
void HuPrcChildLink(struct process *process, struct process *child);
void HuPrcChildUnlink(struct process *process);
struct process * HuPrcCreateChild(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, struct process * parent);
void HuPrcChildWait();
struct process * HuPrcGetCurrent();
s32 HuPrcChildGet(struct process *process);
s32 HuPrcStatKill(struct process *process);
void HuPrcKill(struct process *process);
void HuPrcChildKill(struct process *process);
void HuPrcTerminate(struct process *process);
void HuPrcExit();
void HuPrcSleep(s32 time);
void HuPrcVSleep();
void HuPrcAwake(struct process *process);
void HuPrcDtor(struct process *process, process_func destructor);
void HuPrcCurrentDtor(process_func destructor);
void * HuPrcAllocMem(s32 size);
void HuPrcFreeMem(void *ptr);

#endif