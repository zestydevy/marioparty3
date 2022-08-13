#ifndef __ROM_H
#define __ROM_H

#include <libultra.h>


s32 HuStartDma(OSIoMesg * msg, u8 pri, s32 direction, u32 src, void * dest, u32 size, OSMesgQueue * retQueue);
s32 HuRomDmaRead(void * src, void * dest, s32 size);
s32 HuRomDmaCodeRead(void * src, void * dest, s32 size);

#endif