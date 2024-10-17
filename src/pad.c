#include "common.h"
#include "siman.h"
#include "pad.h"

s32 HuPadInit(u16* channel)
{
    OSContStatus contStat[MAXCONTROLLERS];    // sp10
    u8 pattern;                               // sp20
    s16 i;

    osContInit(&D_800CE1A0, &pattern, contStat);
    
    D_800ABF84 = 0;
    D_800ABF82 = 0;
    D_800ABF80 = 0;
    gNumOfControllers = 0;

    for (i = 0; i < MAXCONTROLLERS; ++i)
    {
        if (((pattern >> i) & 1) && ((contStat[i].errno & CONT_NO_RESPONSE_ERROR) == 0)) {
            if (++gNumOfControllers == *channel) {
                break;
            }
        }

        D_800CDA7C[i] = 
        D_800D5558[i] = 
        D_800CBB66[i] = 
        D_800D1244[i] = 
            0;
        D_800D056A[i] = 
        D_800D1382[i] = 
            0;
        D_800D20A1[i] = 0;
        D_800CBB6E[i] = 0;
        D_800ABF8A[i] = 0;
        
    }
    
    osContSetCh(*channel);
    return 0;
}

s16 func_80008F3C_9B3C(s16 ch, s32 arg1)
{
    unkMesg siMesg;
    func_80051B0C_5270C(&siMesg, (HuSiFunc)&HuPadInit, &ch, 1);
    
    D_800ABF9C = 0;
    
    if (arg1 & 1) {
        func_800097D4_A3D4();
    }
    
    func_8000914C_9D4C(0x46, 0x46);
    osCreateMesgQueue(&D_800ABFA0, &D_800ABFB8, 1);
    osSendMesg(&D_800ABFA0, 0, 1);
    
    return gNumOfControllers;
}

// arg0 never used?
s32 func_80008FD4_9BD4(s32 arg0)
{
    osRecvMesg(&D_800ABFA0, 0, 1);
    
    if (D_800ABF80 < 8)
    {
        osSendMesg(&D_800ABFA0, 0, 1);
        osContStartReadData(&D_800CE1A0);
        osRecvMesg(&D_800CE1A0, 0, 1);
        osContGetReadData(&D_800ABE40[D_800ABF84* 4]);
        osRecvMesg(&D_800ABFA0, 0, 1);
        
        ++D_800ABF80;
        
        if (++D_800ABF84 >= 8) {
            D_800ABF84 = 0;
        }
    }
    
    osSendMesg(&D_800ABFA0, 0, 1);
    return 0;
}

INCLUDE_ASM(s32, "pad", func_800090D4_9CD4);

void func_8000914C_9D4C(s8 arg0, s8 arg1) {
    D_800ABF8E = arg0;
    D_800ABF8F = arg1;
}

s16 func_80009160_9D60(void)
{
    s16 i;
    s16 temp_s0;
    u16 temp_v0_3;
    OSContPad* pads;

    osRecvMesg(&D_800ABFA0, 0, 1);
    temp_s0 = D_800ABF80;

    if (temp_s0 != 0)
    {
        --D_800ABF80;
    
        pads = &D_800ABE40[D_800ABF82* 4];
        ++D_800ABF82;
        if (D_800ABF82 >= 8) {
            D_800ABF82 = 0;
        }

        for (i = 0; i < 4; ++i)
        {
            D_800ABF8A[i] = pads[i].errno != 8;
            temp_v0_3 = 
            D_800CDA7C[i] = pads[i].button;
            D_800D056A[i] =
            D_800CBB6E[i] = pads[i].stick_x;
            D_800D1382[i] =
            D_800D20A1[i] = pads[i].stick_y;
            D_800D5558[i] = temp_v0_3 & (temp_v0_3 ^ D_800CBB66[i]);
            if (D_800CBB66[i] == temp_v0_3) {
                    if (!(--D_800ABF86[i] & 0xFF)) {
                        D_800D1244[i] = temp_v0_3;
                        D_800ABF86[i] = 0xA;
                    } else {
                        D_800D1244[i] = 0;
                    }
            } 
            else {
                D_800D1244[i] = D_800D5558[i];
                D_800ABF86[i] = 0x1E;
            }

            if ((((u8)D_800CBB6E[i] + 9) & 0xFF) < 0x13U) {
                D_800CBB6E[i] = 0;
            } else if (D_800CBB6E[i] > D_800ABF8E) {
                D_800CBB6E[i] = D_800ABF8E;
            } else if (D_800CBB6E[i] < -D_800ABF8E) {
                D_800CBB6E[i] = -D_800ABF8E;
            }
            if ((((u8) D_800D20A1[i] + 9) & 0xFF) < 0x13U) {
                D_800D20A1[i] = 0;
            } else if (D_800D20A1[i] > D_800ABF8F) {
                D_800D20A1[i] = D_800ABF8F;
            } else {
                if (D_800D20A1[i] < -D_800ABF8F) {
                    D_800D20A1[i] = -D_800ABF8F;
                }
            }
            D_800CBB66[i] = temp_v0_3;
        }
    }
    osSendMesg(&D_800ABFA0, 0, 1);
    return temp_s0;
}

INCLUDE_ASM(s32, "pad", func_800094E4_A0E4);

void func_800097B8_A3B8(void) {
    func_80008FD4_9BD4(0);
}

void func_800097D4_A3D4(void) {
    if (D_800ABF9C != 0) {
        func_80009824_A424();
    }
    func_8005188C_5248C(&D_800ABF90, 0, &func_800097B8_A3B8);
    D_800ABF9C = 1;
}

void func_80009824_A424(void) {
    if (D_800ABF9C != 0) {
        func_80051968_52568(&D_800ABF90);
    }
    D_800ABF9C = 0;
}

s32 HuGetPadInserted(s16 padNum) {
    return D_800ABF8A[padNum];
}
