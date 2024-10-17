#include "common.h"

extern u8 D_80097710_98310[];
extern u8 D_800D0450[];
extern OSMesgQueue D_800CE1A0;
extern u8 D_800AC7F0;
extern u8 D_800AC7F1;
s32 func_8000C9C8_D5C8(s8);
extern u8 D_800D0E50[];
void func_8000CA64_D664(void);
//some kind of osEepromLongWrite wrapper?
s32 func_8000CB30_D730(OSMesgQueue* arg0, u8 arg1, u8* arg2, s32 arg3);
typedef struct UnkEepStruct {
    char unk_00[0x10];
} UnkEepStruct;

s32 GetEepType(s8** arg0) {
    s16 eepromProbeResult;
    s32 var_s1;
    s16 i;

    D_800AC7F0 = 0;
    D_800AC7F1 = 0xFF;
    var_s1 = 0;
    eepromProbeResult = osEepromProbe(&D_800CE1A0);
    if ((eepromProbeResult) == 0) {
        for (i = 0; i < 4; i++) {
            eepromProbeResult = osEepromProbe(&D_800CE1A0);
            if (eepromProbeResult != 0) {
                break;
            }
        }

        ASSERT(i != 4);
    }

    ASSERT(eepromProbeResult == EEPROM_TYPE_16K);

    if (osEepromLongRead(&D_800CE1A0, 0, D_800D0E50, EEPROM_BLOCK_SIZE) != 0) {
        return EEPROM_TYPE_16K;
    }

    i = 0;
    if (D_80097710_98310[i] != 0) {
        while (1) {
            if (D_800D0E50[i] != D_80097710_98310[i]) {
                var_s1 = 1;
                //Write "HUDSON\0\0" header
                for (i = 0; i < 8; i++) {
                    D_800D0E50[i] = D_80097710_98310[i];
                }

                for (i = 0; i < EEPROM_BLOCK_SIZE; i++) {
                    D_800D0E50[i] = D_80097710_98310[i];
                }
                
                func_8000CA64_D664();
                func_8000CB30_D730(&D_800CE1A0, 1, D_800D0450, 0x18);
                
                for (i = 0; i < 3; i++) {
                    if (func_8000C9C8_D5C8(i)) {
                        return EEPROM_TYPE_16K;
                    }
                }
                
                for (i = 0; i < 8; i++) {
                    D_800D0E50[i] = D_80097710_98310[i];
                }
                
                if (func_8000CB30_D730(&D_800CE1A0, 0, D_800D0E50, 8) == 0) {
                    **arg0 = var_s1;
                    return 0;
                }
                return EEPROM_TYPE_16K;
            }      
            i++;
            if (D_80097710_98310[i] == 0) {
                break;
            }
        }
    }
    **arg0 = var_s1;
    return 0;
}

typedef struct unkfunc_8001AFD8 {
    s16 unk0;
    struct unkfunc_8001AFD8* unk4; //is this correct?
    s16 unk8;
} unkfunc_8001AFD8;

typedef struct unkfunc_8007EE0C {
    void* GetEepTypeFunc; //func pointer
    unkfunc_8001AFD8* unk4; //is this correct?
    s32 unk8;
    OSMesgQueue* mesgQueue;
} unkfunc_8007EE0C;

typedef struct UnkEep {
    u16 unk0;
    char unk2[2];
    u8* unk4;
    u16 unk8;
} UnkEep;

s32 func_80051B0C_5270C(unkfunc_8007EE0C* arg0, void* GetEepType, UnkEep** arg2, s32 arg3);

s32 func_8000C4AC_D0AC(unkfunc_8001AFD8* arg0) {
    unkfunc_8007EE0C sp10;
    unkfunc_8001AFD8* sp20 = arg0; //?

    return func_80051B0C_5270C(&sp10, &GetEepType, &sp20, 1);
}

INCLUDE_ASM(s32, "eeprom", func_8000C4DC_D0DC);

INCLUDE_ASM(s32, "eeprom", func_8000C538_D138);

INCLUDE_ASM(s32, "eeprom", func_8000C638_D238);

INCLUDE_ASM(s32, "eeprom", func_8000C6C0_D2C0);

INCLUDE_ASM(s32, "eeprom", func_8000C7A0_D3A0);

INCLUDE_ASM(s32, "eeprom", func_8000C7F4_D3F4);

INCLUDE_ASM(s32, "eeprom", func_8000C8F0_D4F0);

INCLUDE_ASM(s32, "eeprom", func_8000C954_D554);

INCLUDE_ASM(s32, "eeprom", func_8000C9C8_D5C8);

INCLUDE_ASM(s32, "eeprom", func_8000CA3C_D63C);

INCLUDE_ASM(s32, "eeprom", func_8000CA64_D664);

INCLUDE_ASM(s32, "eeprom", func_8000CA8C_D68C);

INCLUDE_ASM(s32, "eeprom", func_8000CAC0_D6C0);

u16 GetSaveFileChecksum(u8* data, u16 startIndex, u16 size) {
    u16 checksum = 0;
    u16 remainingBytes = size - 1;

    while (size--) {
        checksum += data[startIndex];
        startIndex += 1;
        remainingBytes += 0xFFFF;
    }

    return ~checksum;
}

s32 func_8000CB30_D730(OSMesgQueue* arg0, u8 arg1, u8* arg2, s32 arg3) {
    UnkEepStruct sp10;

    osEepromLongRead(arg0, (arg1 ^ 1), (u8*)&sp10, 8);
    return osEepromLongWrite(arg0, arg1, arg2, arg3);
}
