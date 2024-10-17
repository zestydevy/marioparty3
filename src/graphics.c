#include "common.h"
#include "graphics.h"

extern swapChainTaskQueue swapChainTask;
extern OSThread swapChainThread;
extern u8 swapChainStack[];

extern graphicsMessage gMesgRingBuffer[0x40];
extern s16 ringBufferIndex;

extern void **frameBufferPool;
extern u16 frameBufferCount;
extern u16 frameBufferSegmentID;

extern u64 *gThreadOutStackSize;
extern u64 *gThreadYieldStack;
extern u64 *gThreadOutStack;
extern u64 *gThread3Stack;

extern u8 rspBootAddressStart;
extern u8 rspBootAddressEnd;
extern Gfx gTaskDataPointers[];

extern s32 D_800CC0A4;
extern void *nextFrameBuffer;
extern void *currFrameBuffer;

extern s32 *gUCodeAddresses;
extern u32 D_800B19A0; // message count?


extern OSMesgQueue gSwapChainMesgQueue;
extern void* gSwapChainInitMesg;
extern s16 gSwapChainMesgTotal;

extern OSMesgQueue gMesgQueue;
extern void* gMesgQueueInitMesg;

extern u32 D_800D2094; // Unk
extern OSMesgQueue D_800CC3C0; // Another system's message queue

/* Initialize Graphics SwapChain */

void func_8000EA10_F610(void **arg1, s32 arg2, s32 arg3, u64 **arg4, s32 *arg5) {
    func_8000F024_FC24(arg1, arg2, arg3);
    func_8000F04C_FC4C(arg4);
    func_8000F088_FC88(arg5);
    func_8000F094_FC94(0);

    swapChainTask.mesgQueue.mtqueue = (OSThread*) &gMesgQueue;
    swapChainTask.task.t.type = 1;
    swapChainTask.task.t.flags = 2;
    swapChainTask.task.t.ucode_boot = (u64*) &rspBootAddressStart;
    swapChainTask.task.t.ucode_boot_size = (s32) (&rspBootAddressEnd - &rspBootAddressStart);
    swapChainTask.task.t.ucode_size = 0x1000;
    swapChainTask.task.t.ucode_data_size = 0x800;
    swapChainTask.task.t.dram_stack_size = 0x400;
    swapChainTask.task.t.data_ptr = (u64*) &gTaskDataPointers;
    swapChainTask.task.t.data_size = 2;
    swapChainTask.task.t.yield_data_size = 0xC00;

    gSwapChainMesgTotal = 0;
    ringBufferIndex = 0;
    D_800CC0A4 = 0;
    nextFrameBuffer = 0;
    currFrameBuffer = 0;
    osCreateMesgQueue(&gSwapChainMesgQueue, &gSwapChainInitMesg, 0x40);
    osCreateMesgQueue(&gMesgQueue, &gMesgQueueInitMesg, 8);
    osCreateThread(&swapChainThread, 0x10, &func_8000EBEC_F7EC, NULL, &swapChainStack, 0x64);
    osStartThread(&swapChainThread);
}

// INCLUDE_ASM(s32, "graphics", func_8000EB60_F760);
/* Retrieve available frame buffer (triple buffering?) */
void *func_8000EB60_F760(void) {
    void *current;
    void *next;
    void *fBuffer;
    s16 i;

    current = osViGetCurrentFramebuffer();
    next = osViGetNextFramebuffer();
    
    for (i = 0; i < frameBufferCount; i++) {
        fBuffer = frameBufferPool[i];
        if (fBuffer != current) {
            if (fBuffer != next) {
                return fBuffer;
            }
        }
    }
    return NULL;
}

/* Swap Chain Loop */
void func_8000EBEC_F7EC(void* arg0) {
    unkSchedStruct sp10;
    OSMesgQueue mesgQueue;
    unkGraphicsMessage2 sp38;
    unkSchedStruct sp58;
    OSMesgQueue mesgQueue2;
    unkGraphicsMessage2 sp68;
    graphicsMessage* recvdMesg;
    void* pAvailableFrameBuffer;
    s32 var_s4;
    u32 i;

    swapChainTaskQueue *pSwapChain;
    OSTask *pTask;

    recvdMesg = NULL;
    pSwapChain = &swapChainTask;
    pTask = &swapChainTask.task;
    var_s4 = 0;

    osCreateMesgQueue(&mesgQueue, (OSMesg*) &sp38, 8);
    func_800511C4_51DC4(&sp10, &mesgQueue, 1);
    osCreateMesgQueue(&mesgQueue2, (OSMesg*) &sp68, 8);
    func_800511C4_51DC4(&sp58, &mesgQueue2, 2);
    
    while (TRUE) {
        do {
            recvmesg:
            osRecvMesg(&mesgQueue, NULL, 1);
            if (osRecvMesg(&mesgQueue2, NULL, 0) == 0) { while (TRUE); } // Infinite loop?
            if ((D_800D2094 - var_s4) < D_800B19A0) {
                goto recvmesg;
            }
    
            var_s4 = D_800D2094;
            func_8004D85C_4E45C();
            pAvailableFrameBuffer = (void *) func_8000EB60_F760();
        } while (pAvailableFrameBuffer == NULL);

        currFrameBuffer = nextFrameBuffer;
        nextFrameBuffer = pAvailableFrameBuffer;

        /* Need redundant do for regalloc? */
        do { do {

            osRecvMesg(&gSwapChainMesgQueue, (OSMesg) &recvdMesg, 1);
            if (osRecvMesg(&mesgQueue2, NULL, 0) == 0) {
                while (TRUE);
            } else {
                u32 intMask;
                Gfx *dl = gTaskDataPointers;
                gSPSegment(dl++, frameBufferSegmentID, pAvailableFrameBuffer);
                gSPBranchList(dl++, recvdMesg->unk00);
                pSwapChain->mesgQueue.fullqueue = (void *) recvdMesg->unk08;
                pTask->t.dram_stack = gThread3Stack;
                pTask->t.output_buff = gThreadOutStack;
                pTask->t.output_buff_size = gThreadOutStackSize;
                pTask->t.yield_data_ptr = gThreadYieldStack;
                pTask->t.ucode =      (u64 *) *(   (recvdMesg->unk04* 2)      + gUCodeAddresses); // offset     (data pairs?)
                pTask->t.ucode_data = (u64 *) *( ( (recvdMesg->unk04* 2) | 1) + gUCodeAddresses); // offset + 1
    
                osSendMesg(&D_800CC3C0, (OSMesg) pSwapChain, 1);
                osRecvMesg(&gMesgQueue, NULL, 1);
    
                intMask = osSetIntMask(1);
                gSwapChainMesgTotal -= 1;
                osSetIntMask(intMask);
    
                if (recvdMesg->unk0C != NULL) {
                    osSendMesg(recvdMesg->unk0C, (OSMesg) recvdMesg->unk10, 1);
                }            
            }

        } while (!((s32) recvdMesg->unk08 & 1)); } while (FALSE);
    
        for (i = 1; i < D_800B19A0; i++) {
            osRecvMesg(&mesgQueue, NULL, 1);
        }
    
        osViSwapBuffer(pAvailableFrameBuffer);
        if (D_800CC0A4 == 0) {
            if (osRecvMesg(&mesgQueue2, NULL, 0) == 0) { while (TRUE); }
            osViSetYScale(1.0f);
            osViBlack(0);
        }
        D_800CC0A4++;
        func_8004D878_4E478(); // empty function
    }
}

/* Retrieve graphics OSMesg from ring buffer */
graphicsMessage* func_8000EF10_FB10(void) {
    if (ringBufferIndex >= 0x40) {
        ringBufferIndex = 0;
    }
    return &gMesgRingBuffer[ringBufferIndex++];
}

/* Send graphics OSMesg */
u8 func_8000EF64_FB64(s32 arg0, u16 arg1, s32 arg2, OSMesgQueue *arg3, s32 arg4) {
    graphicsMessage* mesg;
    u32 intMask;

    if (gSwapChainMesgTotal >= 0x40) {
        return FALSE;
    }

    intMask = osSetIntMask(1);
    gSwapChainMesgTotal++;
    osSetIntMask(intMask);
    mesg = func_8000EF10_FB10();

    /* Initialize message. */
    mesg->unk00 = arg0;
    mesg->unk04 = arg1;
    mesg->unk08 = arg2;
    mesg->unk0C = arg3;
    mesg->unk10 = arg4;

    osSendMesg(&gSwapChainMesgQueue, mesg, 1);
    return TRUE;
}

/* Init graphics frame buffer pool */
void func_8000F024_FC24(void **pool, u16 size, u16 segment) {
    frameBufferPool = pool;
    frameBufferCount = size;
    frameBufferSegmentID = segment;
}

/* Reset frame buffer pool size. (Switch between double and triple buffering) */
void func_8000F040_FC40(u16 size) {
    frameBufferCount = size;
}

/* Initialize gThreadStacks */
void func_8000F04C_FC4C(u64 **threadStacks) {
    gThread3Stack = *threadStacks++;
    gThreadOutStack = *threadStacks++;
    gThreadOutStackSize = *threadStacks++;
    gThreadYieldStack = *threadStacks;
}

/* Set pointer to swapchain task's ucode addresses */
void func_8000F088_FC88(s32 *uCodeAdresses) {
    gUCodeAddresses = uCodeAdresses;
}

/* Swap chain state set? */
void func_8000F094_FC94(u32 arg0) {
    D_800B19A0 = arg0;
}
