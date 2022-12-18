#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include <libultra.h>


typedef struct {
    s32 unk00;
    u16 unk04;
    s32 unk08;
    OSMesgQueue *unk0C;
    s32 unk10; // OSMesg to send to unk0C
} graphicsMessage; // OSMesg

typedef struct combinedStruct {
    OSTask task;
    OSMesgQueue mesgQueue;
} swapChainTaskQueue;

void func_8000F024_FC24(void**, u16, u16); // Init graphics frame buffer pool                        
void func_8000F04C_FC4C(u64**); // Set gThreadStacks
void func_8000F088_FC88(s32*); // Set graphics state
void func_8000F094_FC94(u32); // Set unk swap chain state
void func_8000EBEC_F7EC(void*); // Swap Chain Loop

/* TODO: Where is the libultra header for this? */
extern void		*osViGetCurrentFramebuffer(void);
extern void		*osViGetNextFramebuffer(void);
extern void		osViSwapBuffer(void *);
extern void		osViBlack(u8);
extern void		osViSetYScale(f32);

// TODO: Move to respective header files
typedef struct {
    s32 unk00;
    OSMesgQueue *unk04;
    s32 unk08;
} unkSchedStruct;

typedef struct {
    u8 unk00[0x20];
} unkGraphicsMessage2; // OSMesg


void func_800511C4_51DC4(unkSchedStruct*, OSMesgQueue*, s32);
void func_8004D85C_4E45C();
void func_8004D878_4E478();


#endif
