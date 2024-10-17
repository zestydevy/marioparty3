#include "common.h"
#include "obj.h"

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
void func_80047B38_48738(HuObjInfo *, s32);                      /* extern */
void func_8004DEC8_4EAC8(s16);                         /* extern */
void func_80106D7C_3D505C();                           /* extern */
extern u16 D_800A1760_A2360;
extern s16 D_800A1786_A2386;
extern s8 D_800CD280;
//these probably take omObjData* as args
void func_8004B340_4BF40(void*);
void func_80105B38_3D3E18(void*);
void func_80106898_3D4B78(void*);
void func_80106DF8_3D50D8(void*);

void func_801059A0_3D3C80(void)
{
    Hu3DCamInit(1);
    Hu3DAnimInit(1);
    func_800142A0_14EA0(0x19);
    HuObjInit(0x33, 0);
    func_80047B38_48738(HuObjCreate(0x7FDA, 0, 0, -1, &func_8004B340_4BF40), 0xA0);
    
    if (D_800A1760_A2360 != 0) {
        D_800A1760_A2360 = 0;
        func_8004DEC8_4EAC8(D_800A1786_A2386);
        D_800A1786_A2386 = -1;
    }
    HuObjCreate(0x2710, 0, 0, -1, &func_80106DF8_3D50D8);
    func_80019490_1A090(3);
    func_80019514_1A114(0, 0x78, 0x78, 0x78);
    func_80019514_1A114(1, 0x40, 0x40, 0x60);
    func_80019568_1A168(1, -100.0f, 100.0f, 100.0f);
    func_80019514_1A114(2, 0, 0, 0);
    func_80019514_1A114(3, 0, 0, 0);
    func_80106D7C_3D505C();
    HuObjCreate(0x7D0, 0xA, 0xA, -1, &func_80105B38_3D3E18);
    HuObjCreate(0x7D0, 0, 0, -1, &func_80106898_3D4B78);
    HuWipeFadeIn(0, 0x10);
    
    D_800CD280 = 1;
    
    func_8001F38C_1FF8C(0xC0, 0xE0, 0xFF);
    func_80045C2C_4682C();
}

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_80105B38_3D3E18);

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_80105C4C_3D3F2C);

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_8010654C_3D482C);

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_80106764_3D4A44);

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_80106898_3D4B78);

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_80106D7C_3D505C);

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_80106DF8_3D50D8);

INCLUDE_ASM(s32, "overlays/test_anim1/test_anim1", func_80106E54_3D5134);
