#include "common.h"

typedef struct unk_struct {
f32 unk0;
f32 unk4;
f32 unk8;
f32 unkC;
f32 unk10;
f32 unk14;
f32 unk18;
f32 unk1C;
f32 unk20;
f32 unk24;
f32 unk28;
f32 unk2C;
f32 unk30;
char unk_34[0x1C];
f32 unk_50;
char unk_44[0x1DC];
} unk_struct;

extern unk_struct* D_800A0550_A1150;
typedef f32 Matrix4f[4][4];

f32 func_8008E3F0_8EFF0(f32);
f32 func_8008EF20_8FB20(f32);
void guLookAtF(f32 mf[4][4], f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);

INCLUDE_ASM(s32, "12E20", Hu3DCamInit);

INCLUDE_ASM(s32, "12E20", func_800123F4_12FF4);

INCLUDE_ASM(s32, "12E20", func_80012408_13008);

INCLUDE_ASM(s32, "12E20", func_8001247C_1307C);

INCLUDE_ASM(s32, "12E20", func_800124BC_130BC);

INCLUDE_ASM(s32, "12E20", func_80012508_13108);

INCLUDE_ASM(s32, "12E20", func_80012564_13164);

INCLUDE_ASM(s32, "12E20", func_80012640_13240);

INCLUDE_ASM(s32, "12E20", func_800127C4_133C4);

INCLUDE_ASM(s32, "12E20", func_80012888_13488);

INCLUDE_ASM(s32, "12E20", func_800128BC_134BC);

INCLUDE_ASM(s32, "12E20", func_800128EC_134EC);

void func_8001291C_1351C(s16 index, Vec3f *arg1, Vec2f *arg2) { //Convert3Dto2D
    Matrix4f sp28;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f30;
    unk_struct *temp_s0;
    
    temp_s0 = &D_800A0550_A1150[index];
    guLookAtF(sp28, temp_s0->unk10, temp_s0->unk14, temp_s0->unk18, temp_s0->unk1C, temp_s0->unk20, temp_s0->unk24, temp_s0->unk28, temp_s0->unk2C, temp_s0->unk30);
    temp_f30 = arg1->x;
    temp_f28 = arg1->y;
    temp_f2 = arg1->z;
    temp_f30 -= temp_s0->unk10;
    temp_f28 -= temp_s0->unk14;
    temp_f2 -= temp_s0->unk18;
    temp_f24 = ((temp_f30 * sp28[0][0]) + (temp_f28 * sp28[1][0])) + (temp_f2 * sp28[2][0]);
    temp_f22 = ((temp_f30 * sp28[0][1]) + (temp_f28 * sp28[1][1])) + (temp_f2 * sp28[2][1]);
    temp_f20 = ((temp_f30 * sp28[0][2]) + (temp_f28 * sp28[1][2])) + (temp_f2 * sp28[2][2]);
    temp_f30 = func_8008EF20_8FB20(temp_s0->unk_50 / 2.0f) / func_8008E3F0_8EFF0(temp_s0->unk_50 / 2.0f) * temp_f20 * (4.0f / 3.0f);
    temp_f28 =  (func_8008EF20_8FB20(temp_s0->unk_50 / 2.0f) / func_8008E3F0_8EFF0(temp_s0->unk_50 / 2.0f)) * temp_f20;
    arg2->x = (temp_f24 * (160.0f / (-temp_f30))) + 160.0f;
    arg2->y = ((temp_f22 * (120.0f / temp_f28)) + 120.0f);
}

INCLUDE_ASM(s32, "12E20", func_80012B14_13714);

INCLUDE_ASM(s32, "12E20", func_80012D0C_1390C);

INCLUDE_ASM(s32, "12E20", func_80012E54_13A54);

INCLUDE_ASM(s32, "12E20", func_80013320_13F20);

INCLUDE_ASM(s32, "12E20", func_80013350_13F50);
