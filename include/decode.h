#ifndef __DECODE_H
#define __DECODE_H

#include "libultra.h"

typedef enum
{
    DECODE_NONE = 0,
    DECODE_LZ,              // lzss
    DECODE_SLIDE,           // yaz0/szs
    DECODE_FSLIDE,          // yaz0/szs, no loopback
    DECODE_FSLIDE_2,        // yaz0/szs, no loopback
    DECODE_RLE              // custom rle variant
} EDecodeType;

struct decode_struct {
    u16 chunkLen;
    s16 pad;
    u8* src;
    u8* dest;
    u32 len;
};

void HuDecodeNone(struct decode_struct* decode);
void HuDecodeLZ(struct decode_struct* decode);
void HuDecodeSlide(struct decode_struct* decode);
void HuDecodeFslide(struct decode_struct* decode);
void HuDecodeRLE(struct decode_struct* decode);
void HuDecode(void* src, void* dest, s32 len, EDecodeType decodeType);

#endif