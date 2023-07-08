#include "common.h"
#include "process.h"

void Hu3DAnimInit(s32);                                  /* extern */
void Hu3DCamInit(s32);                                   /* extern */
void HuObjInit(s32, s32);                                  /* extern */
void HuWipeFadeIn(s32, s32);                               /* extern */
void func_800142A0_14EA0(s32);                           /* extern */
void func_80019490_1A090(s32);                           /* extern */
void func_80019514_1A114(s32, s32, s32, s32);                  /* extern */
void func_80019568_1A168(s32, f32, f32, f32);                  /* extern */
void func_8001F38C_1FF8C(s32, s32, s32);                     /* extern */
void func_80045C2C_4682C();                            /* extern */
s32 func_80047620_48220(s32, s32, s32, s32, s32*);            /* extern */
void func_80047B38_48738(s32, s32);                      /* extern */
void func_8004DEC8_4EAC8(s16);                         /* extern */
void func_80106D7C_3D505C();                           /* extern */
extern u16 D_800A1760_A2360;
extern s16 D_800A1786_A2386;
extern s8 D_800CD280;
extern void func_8004B340_4BF40;
extern void func_80105B38_3D3E18;
extern void func_80106898_3D4B78;
extern void func_80106DF8_3D50D8;

extern s32 func_8000B838_C438(s32);
extern s32 InitEspriteSlot(s32, s32, s32);
extern void func_8000BBD4_C7D4(s32, s32, s32);
extern void func_8000BB54_C754(s32);
extern void func_8000BCC8_C8C8(s32, s32);
extern void func_800EC9DC(s32, char *, s32, s32, s32, s32, s32);

typedef struct HuObj {
    /*0x00*/ struct HuObj * prev;
    /*0x04*/ struct HuObj * next;
    /*0x08*/ s8 pad1[2];
    /*0x0A*/ u16 unka;

    /*0x0C*/ HuVec3F coords;

    /*0x18*/ f32 rot1;
    f32 rot2;
    f32 rot3;

    /*0x24*/ f32 unk36;
    f32 unk40;
    f32 unk44;

    /*0x30*/ f32 unk48;
    f32 funk52;
    f32 funk56;

    void *unk60;
    void *unk64;
    s8 pad5[2];
    s16 unk70;
} HuObj;

static HuObj * mario;
char *message = "Hello World" "\xFF";
char buff[200];

extern HuObj * func_800D90C8(s32, s32 *);
extern void func_80089A20_8A620(HuVec3F *, HuVec3F *);
extern void func_800D9B54(HuObj *);
extern void func_800EC9DC();
extern void func_800EC6EC();

void func__801059A0_3D3C80(void)
{
    HuVec3F marioPos = {0.0f, 0.0f, 0.0f};
    
    Hu3DCamInit(1);
    Hu3DAnimInit(1);
    func_800142A0_14EA0(0x19);
    HuObjInit(0x33, 0);
    func_80047B38_48738(func_80047620_48220(0x7FDA, 0, 0, -1, &func_8004B340_4BF40), 0xA0);
    
    if (D_800A1760_A2360 != 0) {
        D_800A1760_A2360 = 0;
        func_8004DEC8_4EAC8(D_800A1786_A2386);
        D_800A1786_A2386 = -1;
    }
    func_80047620_48220(0x2710, 0, 0, -1, &func_80106DF8_3D50D8);
    func_80019490_1A090(3);
    func_80019514_1A114(0, 0x78, 0x78, 0x78);
    func_80019514_1A114(1, 0x40, 0x40, 0x60);
    func_80019568_1A168(1, -100.0f, 100.0f, 100.0f);
    func_80019514_1A114(2, 0, 0, 0);
    func_80019514_1A114(3, 0, 0, 0);
    func_80106D7C_3D505C();
    func_80047620_48220(0x7D0, 0xA, 0xA, -1, &func_80105B38_3D3E18);
    func_80047620_48220(0x7D0, 0, 0, -1, &func_80106898_3D4B78);

    {
    s32 s0 = func_8000B838_C438(0x00330004);
    s32 s1 = InitEspriteSlot(s0, 0, 1);
    func_8000BBD4_C7D4(s1, 320 / 2, 240 / 2);
    func_8000BB54_C754(s1);
    func_8000BCC8_C8C8(s1, 0xFFFF);
    }

    HuWipeFadeIn(2, 0x30);
    
    D_800CD280 = 1;
    
    func_8001F38C_1FF8C(184, 134, 249);
    func_80045C2C_4682C();

    HuAudSeqPlay(3);

    //mario = func_800D90C8(1, NULL);
    //mario->unka |= 4;
    //func_80089A20_8A620(&mario->coords, &marioPos);
    //func_800D9B54(mario);

    //func_800EC9DC(-1, message, 0, 0, 0, 0, 0);

    while (TRUE) {
        sprintf(buff, "MARIO PARTY 3 - ZEST WAS HERE :)");
        HuDrawTextDbg(0x18, 0xD6, &buff);
        HuPrcVSleep();
    }
}