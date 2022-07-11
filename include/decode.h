#ifndef __DECODE_H
#define __DECODE_H

#include "libultra.h"

typedef enum
{
    DECODE_NONE = 0,
    DECODE_LZ,
    DECODE_YAZ0,
    DECODE_TYPE3,
    DECODE_TYPE4,
    DECODE_RLE
} EDecodeType;

void HuDecode(void * src, void * dest, s32 len, EDecodeType decodeType);

#endif