#include "common.h"
#include "rom.h"
#include "decode.h"

void HuDecodeNone(struct decode_struct * decode)
{
    s32 copyLen;

    while (decode->len)
    {
        if (decode->len < 1024) {
            copyLen = (decode->len + 1) & 0xFFFFFFFE;
            decode->len = 0;
        }
        else {
            copyLen = 1024;
            decode->len -= 1024;
        }
        HuRomDmaRead(decode->src, decode->dest, copyLen);
        decode->src += copyLen;
        decode->dest += copyLen;
    }
}

INCLUDE_ASM(void, "decode", HuDecodeLZ, struct decode_struct * decode);

void HuDecodeSlide(struct decode_struct * decode)
{
    s32 codeWordBitsRemaining;
    s32 curCodeWord;
    u8 *destOrig;

    // Advance past the first 4 bytes.
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;

    codeWordBitsRemaining = 0;
    curCodeWord = 0;
    destOrig = decode->dest;

    while (decode->len != 0) {
        // Read a new code word.
        if (codeWordBitsRemaining == 0) {
            {
                u32 chunkByte1, chunkByte2, chunkByte3, chunkByte4;

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte1 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte2 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte3 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte4 = D_800ABFF0[decode->chunkLen++];

                curCodeWord = (chunkByte1 << 24) + (chunkByte2 << 16) + (chunkByte3 << 8) + chunkByte4;
                codeWordBitsRemaining = 32;
            }
        }

        if (curCodeWord < 0) {
            {
                u32 nextByte;

                // Copy the next byte from the source to the destination.
                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                nextByte = D_800ABFF0[decode->chunkLen++];

                *(decode->dest++) = nextByte;
                decode->len--;
            }
        }
        else {
            {
                u32 back, back2, count;
                u8 *ptr;

                // Interpret the next two bytes as a distance to travel backwards and a
                // a length to read.
                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back2 = D_800ABFF0[decode->chunkLen++];

                back2 = (back << 8) + (back2 & 0xFFFFFFFFFFFFFFFF); // Unlikely, but matching.
                count = (back << 8) >> 12;
                back2 &= 0xFFF;
                ptr = decode->dest - back2;
                if (count == 0) {
                    if (decode->chunkLen >= 1024) {
                        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                        decode->src += 1024;
                        decode->chunkLen = 0;
                    }

                    count = 0x12;
                    count += D_800ABFF0[decode->chunkLen++];
                }
                else {
                    count += 2;
                }
                decode->len -= count;

                while (count != 0) {
                    if (ptr - 1 < destOrig) {
                        *(decode->dest++) = 0;
                    }
                    else {
                        *(decode->dest++) = *(ptr - 1);
                    }
                    count--;
                    ptr++;
                }
            }
        }

        curCodeWord <<= 1;
        codeWordBitsRemaining--;
    }
}

void HuDecodeFslide(struct decode_struct *decode)
{
    s32 codeWordBitsRemaining;
    s32 curCodeWord;
    u8 *destOrig;

    // Advance past the first 4 bytes.
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;

    codeWordBitsRemaining = 0;
    curCodeWord = 0;

    destOrig = decode->dest;

    while (decode->len != 0) {
        // Read a new code word.
        if (codeWordBitsRemaining == 0) {
            {
                u32 chunkByte1, chunkByte2, chunkByte3, chunkByte4;

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte1 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte2 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte3 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte4 = D_800ABFF0[decode->chunkLen++];

                curCodeWord = (chunkByte1 << 24) + (chunkByte2 << 16) + (chunkByte3 << 8) + chunkByte4;
                codeWordBitsRemaining = 32;
            }
        }

        if (curCodeWord < 0) {
            {
                u32 nextByte;

                // Copy the next byte from the source to the destination.
                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                nextByte = D_800ABFF0[decode->chunkLen++];

                *(decode->dest++) = nextByte;
                decode->len--;
            }
        }
        else {
            {
                u32 back, back2, count;
                u8 *ptr;

                // Interpret the next two bytes as a distance to travel backwards and a
                // a length to read.
                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back2 = D_800ABFF0[decode->chunkLen++];

                back2 = (back << 8) + (back2 & 0xFFFFFFFFFFFFFFFF); // Unlikely, but matching.
                count = (back << 8) >> 12;
                back2 &= 0xFFF;
                ptr = decode->dest - back2;
                if (count == 0) {
                    if (decode->chunkLen >= 1024) {
                        HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                        decode->src += 1024;
                        decode->chunkLen = 0;
                    }

                    count = 0x12;
                    count += D_800ABFF0[decode->chunkLen++];
                }
                else {
                    count += 2;
                }
                decode->len -= count;

                while (count != 0) {
                    *(decode->dest++) = *(ptr - 1);
                    count--;
                    ptr++;
                }
            }
        }

        curCodeWord <<= 1;
        codeWordBitsRemaining--;
    }
}

void HuDecodeRLE(struct decode_struct * decode)
{
    s32 curCodeByte;
    s32 i;
    s32 byteValue;

    while (decode->len != 0) {
        if (decode->chunkLen >= 1024) {
            HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
            decode->src += 1024;
            decode->chunkLen = 0;
        }

        curCodeByte = D_800ABFF0[decode->chunkLen++];
        if (curCodeByte < 0x80) {
            // No sign bit means we repeat the next byte n times.
            if (decode->chunkLen >= 1024) {
                HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }

            byteValue = D_800ABFF0[decode->chunkLen++];

            for (i = 0; i < curCodeByte; i++) {
                *(decode->dest++) = byteValue;
            }
        }
        else {
            // Having the sign bit means we read the next n bytes from the input.
            curCodeByte = curCodeByte - 0x80;

            for (i = 0; i < curCodeByte; i++) {
                if (decode->chunkLen >= 1024) {
                    HuRomDmaRead(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }

                byteValue = D_800ABFF0[decode->chunkLen++];
                *(decode->dest++) = byteValue;
            }
        }

        decode->len -= curCodeByte;
    }
}

void HuDecode(void * src, void * dest, s32 len, EDecodeType decodeType)
{
    struct decode_struct decodeStruct;
    struct decode_struct * decodePtr = &decodeStruct;
    decodeStruct.src = (u8 *)src;
    decodeStruct.dest = (u8 *)dest;
    decodeStruct.len = len;
    decodeStruct.chunkLen = 1024;

    switch (decodeType)
    {
        case DECODE_NONE:
            HuDecodeNone(decodePtr);
            break;

        case DECODE_LZ:
            HuDecodeLZ(decodePtr);
            break;

        case DECODE_SLIDE:
            HuDecodeSlide(decodePtr);
            break;

        case DECODE_FSLIDE:
        case DECODE_FSLIDE_2:
            HuDecodeFslide(decodePtr);
            break;

        case DECODE_RLE:
            HuDecodeRLE(decodePtr);
            break;

        default:
            break;
    }
}
