#include "common.h"
#include "rom.h"

extern OSPiHandle * osCartRomInit(void);

extern OSPiHandle * D_800CDD50;
extern OSMesgQueue D_800B29F0;
extern void* D_800B2A08;
extern void* D_800CCFA8;
extern OSMesgQueue D_800D6B28;

void func_8004D9A0_4E5A0(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800D6B28, &D_800CCFA8, 0x2A);
    D_800CDD50 = osCartRomInit();
    osCreateMesgQueue(&D_800B29F0, &D_800B2A08, 0xA);
}

s32 HuStartDma(OSIoMesg * msg, u8 pri, s32 direction, u32 src, void * dest, u32 size, OSMesgQueue * retQueue) {
    msg->hdr.pri = pri;
    msg->hdr.retQueue = retQueue;
    msg->dramAddr = dest;
    msg->devAddr = src;
    msg->size = size;
    return osEPiStartDma(D_800CDD50, msg, direction);
}

s32 HuRomDmaRead(u32 src, void * dest, s32 size)
{
    OSIoMesg msg;
    s32 var_s1;
    u32 var_v1;
    s32 err;

    osInvalDCache(dest, OS_DCACHE_ROUNDUP_SIZE(size));

    var_s1 = 0;
    while (size > 0)
    {
        var_v1 = size;
        if (size >= 0x4001) {
            var_v1 = 0x4000;
        }
        err = HuStartDma(&msg, 0, 0, src + var_s1, dest + var_s1, var_v1, &D_800B29F0);

        if (err != 0) {
            return err;
        } 
            
        osRecvMesg(&D_800B29F0, 0, 1);
        size -= 0x4000;   
        var_s1 += 0x4000;
        
    }
    return err;
}

s32 HuRomDmaCodeRead(u32 src, void * dest, s32 size)
{
    OSIoMesg msg;
    s32 var_s1;
    u32 var_v1;
    s32 err;

    osInvalICache(dest, OS_DCACHE_ROUNDUP_SIZE(size));
    osInvalDCache(dest, OS_DCACHE_ROUNDUP_SIZE(size));

    var_s1 = 0;
    while (size > 0)
    {
        var_v1 = size;
        if (size >= 0x4001) {
            var_v1 = 0x4000;
        }
        err = HuStartDma(&msg, 0, 0, src + var_s1, dest + var_s1, var_v1, &D_800B29F0);

        if (err != 0) {
            return err;
        } 
            
        osRecvMesg(&D_800B29F0, 0, 1);
        size -= 0x4000;   
        var_s1 += 0x4000;
        
    }
    return err;
}
