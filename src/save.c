#include "common.h"
#include "pad.h"

extern u8 D_800CD0B6[];

typedef struct
{
    u8 unk0;
    s32 unk4;
    s32 unk8;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
} HuSave00;

extern u8 D_800CC0C8[];
extern HuSave00 D_800CD059;
extern s32 D_800D0308;
extern s8 D_800CD068;
extern u8 D_800CC0DE[];
extern u8 D_800CC153[];
extern u16 D_800CC0CA[];

extern s32 D_800B1A30;

s32 func_80035EB0_36AB0(s32 arg0);

void func_80035A50_36650(void) {
    u8 * ptr = (u8 *)&D_800CC0C8;
    
    bzero(&D_800CC0C8, 0xA4);
    bzero(&D_800D0308, 0x74);
    
    ptr[0] = 0x91;
    D_800CD059.unk0 = 0;
    D_800CD059.unkF = 0;
}

void func_80035AA8_366A8(s8 arg0) {
    D_800CD068 = arg0;
}

// bit position to byte + bit position
void func_80035AB4_366B4(s16 bitPos, s16 * byteIdx, s16 * bitIdx) {
    s16 pos;

    if (bitPos < 0 && D_800CD068 > 0) {
       pos = D_800CD068 - 1;
    } else {
        if (bitPos < 0) {
            pos = 0;
        } else {
            pos = bitPos;
        }
    }
    
    *byteIdx = pos / 8;
    *bitIdx  = pos % 8;
}

// set bit
void func_80035B2C_3672C(s16 bitPos) {
    s16 outBytePos;
    s16 outBitPos;

    func_80035AB4_366B4(bitPos, &outBytePos, &outBitPos);
    D_800CC0DE[outBytePos] |= (1 << outBitPos);
}

// clear bit
void func_80035B80_36780(s16 bitPos) {
    s16 outBytePos;
    s16 outBitPos;

    func_80035AB4_366B4(bitPos, &outBytePos, &outBitPos);
    D_800CC0DE[outBytePos] &= ~(1 << outBitPos);
}

// check bit
s32 func_80035BD8_367D8(s16 arg0) {
    s16 sp10;
    s16 sp12;

    func_80035AB4_366B4(arg0, &sp10, &sp12);
    return D_800CC0DE[sp10] & (1 << sp12);
}

void func_80035C20_36820(s16 arg0, s16 arg1) {
    if (func_80035EB0_36AB0(0xF) == 0) {
        D_800CC0CA[arg0] = arg1;
    }
}

u16 func_80035C6C_3686C(s16 arg0) {
    return D_800CC0CA[arg0];
}

void func_80035C84_36884(s8 arg0) {
    D_800CD059.unk0 = arg0;
}

INCLUDE_ASM(s32, "save", func_80035C90_36890);

INCLUDE_ASM(s32, "save", func_80035CF8_368F8);

INCLUDE_ASM(s32, "save", func_80035D1C_3691C);

INCLUDE_ASM(s32, "save", func_80035DA4_369A4);

INCLUDE_ASM(s32, "save", func_80035E3C_36A3C);

INCLUDE_ASM(s32, "save", func_80035E60_36A60);

INCLUDE_ASM(s32, "save", func_80035E88_36A88);

s32 func_80035EB0_36AB0(s32 arg0) {
    return D_800CC153[arg0 / 8] & (1 << (arg0 % 8));
}

INCLUDE_ASM(s32, "save", func_80035EF4_36AF4);

INCLUDE_ASM(s32, "save", func_80035F44_36B44);

s32 _CheckFlag(s32 input) {
    s32 byteValue;
    s32 adjustedIndex;
    s32 byteIndex;
    s32 bitIndex;
    s32 mask;

    byteValue = D_800CD0B6[input / 8];

    if (input >= 0) {
        adjustedIndex = input;
    } else {
        adjustedIndex = input + 7;
    }

    // Calculate the byte index (divide by 8)
    byteIndex = adjustedIndex >> 3;

    // Calculate the bit index
    bitIndex = input - (byteIndex << 3);

    mask = (1 << bitIndex);

    return byteValue & mask;
}


void _SetFlag(s32 input) {
    s32 adjustedInput;
    s32 byteIndex;
    s32 bitIndex;

    // Adjust input if negative to handle division by 8 correctly
    if (input < 0) {
        adjustedInput = input + 7;
    } else {
        adjustedInput = input;
    }
    
    // Calculate the byte index in the array
    byteIndex = adjustedInput >> 3; // Same as dividing by 8
    
    // Temporary variable to handle bit position calculation
    bitIndex = input;
    
    if (input < 0) {
        bitIndex = input + 7;
    }
    
    // Calculate the bit position within the byte
    bitIndex = bitIndex >> 3 << 3;
    
    // Set the specific bit in the byte at byteIndex
    D_800CD0B6[byteIndex] = D_800CD0B6[byteIndex] | (1 << (input - (bitIndex)));
}

void _ClearFlag(s32 input) {
    s32 adjustedInput;
    s32 byteIndex;
    s32 bitIndex;

    // Adjust input if negative to handle division by 8 correctly
    if (input < 0) {
        adjustedInput = input + 7;
    } else {
        adjustedInput = input;
    }
    
    // Calculate the byte index in the array
    byteIndex = adjustedInput >> 3; // Same as dividing by 8
    
    // Temporary variable to handle bit position calculation
    bitIndex = input;
    
    if (input < 0) {
        bitIndex = input + 7;
    }
    
    // Calculate the bit position within the byte
    bitIndex = bitIndex >> 3 << 3;
    
    // Set the specific bit in the byte at byteIndex
    D_800CD0B6[byteIndex] = D_800CD0B6[byteIndex] & ~(1 << (input - (bitIndex)));
}

void HuSaveSetPadIsInserted(void)
{
    if (HuGetPadInserted(0) != FALSE)
    {
        D_800B1A30 = TRUE;
        return;
    }
    D_800B1A30 = FALSE;
}

INCLUDE_ASM(s32, "save", func_800360B8_36CB8);
