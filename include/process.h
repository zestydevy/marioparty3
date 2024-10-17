#ifndef __PROCESS_H
#define __PROCESS_H

#include "libultra.h"

typedef struct jump_buf
{
    u32* sp;
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

typedef struct Process {
    /*0x00*/ struct Process *next;
    /*0x04*/ struct Process *youngest_child;
    /*0x08*/ struct Process *oldest_child;
    /*0x0C*/ struct Process *relative;
    /*0x10*/ struct Process *parent_oldest_child;
    /*0x14*/ struct Process *new_process;
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
} Process;

void HuPrcSysInit();
void HuPrcLink(Process**root, Process*process);
void HuPrcUnlink(Process**root, Process*process);
Process* HuPrcCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size);
void HuPrcChildLink(Process*process, Process*child);
void HuPrcChildUnlink(Process*process);
Process* HuPrcCreateChild(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, Process* parent);
void HuPrcChildWait();
Process* HuPrcCurrentGet();
s32 HuPrcChildGet(Process*process);
s32 HuPrcStatKill(Process*process);
void HuPrcKill(Process*process);
void HuPrcChildKill(Process*process);
void HuPrcTerminate(Process*process);
void HuPrcExit();
void HuPrcSleep(s32 time);
void HuPrcVSleep();
void HuPrcAwake(Process*process);
void HuPrcDtor(Process*process, process_func destructor);
void HuPrcCurrentDtor(process_func destructor);
void* HuPrcAllocMem(s32 size);
void HuPrcFreeMem(void *ptr);

#endif