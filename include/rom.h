#ifndef __ROM_H
#define __ROM_H

#include <libultra.h>


s32 func_8004D9F8_4E5F8(OSIoMesg * msg, u8 arg1, s32 arg2, u32 arg3, void * arg4, u32 arg5, OSMesgQueue * arg6);
s32 HuRomDmaRead(u32 src, void * dest, s32 size);
s32 HuRomDmaCodeRead(u32 src, void * dest, s32 size);

#endif