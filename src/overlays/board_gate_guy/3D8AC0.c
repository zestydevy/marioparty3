#include "GateGuy.h"
#include "math.h"

void func_801059D0_3D8AC0(void) {
    D_800CDD58 = 1;
    D_800D037C = 0;
    func_80047B80_48780(HuPrcGetCurrent(), 0x80);
    func_80100CEC(gPlayers[gCurrentPlayerIndex].controller);
    func_80047BAC_487AC(HuPrcGetCurrent(), 0x80);
    D_800CDD58 = 0;
    D_800D037C = 1;
}

void func_80105A58_3D8B48(void) {
    while (func_800E88FC() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_80119470 = func_800E1824(0, 0xA0, 1);
    D_80119474 = func_800E1824(0xD, 0xAE, 1);
    D_80119478 = func_800E1824(1, 0xBC, 1);
    D_8011947C = func_800E1824(3, 0xCA, 1);
    HuPrcSleep(3);
    D_800CDD58 = 1;
    D_800D51F8 = 1;
}

void func_80105B10_3D8C00(void) {
    D_800CDD58 = 0;
    D_800D51F8 = 0;
    func_800E1854(D_80119470);
    func_800E1854(D_80119474);
    func_800E1854(D_80119478);
    func_800E1854(D_8011947C);
}

void func_80105B64_3D8C54(void) {
    D_800CD059 = 0;
    HuObjInit(0xA, 0);
    func_80048228_48E28(0x5A, 0, 0x4190);
}

void func_80105B9C_3D8C8C(void) {
    s8 sp10;
    s8 sp11;

    HuObjInit(0xA, 0);
    func_800E94D0();
    func_800E9B10(0x13, 0x241);
    func_800E9F4C(0x1C, &sp10, &sp11);
    func_800ECD0C(0, sp10, sp11);
    func_800E9F4C(0x1B, &sp10, &sp11);
    func_800ECD0C(1, sp10, sp11);
    gPlayers[0].unk1ChainIndex = -1;
    gPlayers[0].unk1SpaceIndex = -1;
    gPlayers[1].unk1ChainIndex = -1;
    gPlayers[1].unk1SpaceIndex = -1;
    func_800E9D9C();
    func_800E9564();
    D_800CD0B0.unk_04 = 5;
    D_800CD0B0.unk_02 = 0;
    func_800EA760();
    func_8004819C_48D9C(1);
}

void func_80105C64_3D8D54(s32 arg0, s32 arg1, unkStruct01* arg2) {
    f32 temp_f20;

    func_800EB708(arg0, arg1, arg2);
    temp_f20 = func_800D76D0(arg2) + 15.0f;
    arg2->unk_00 = HuMathSin(temp_f20);
    arg2->unk_08 = HuMathCos(temp_f20);
}

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80105CC0_3D8DB0);

void* func_80105EB0_3D8FA0(unkStruct04* arg0) {
    unkStruct03* temp_v0;
    unkStruct02* temp_v0_2;

    temp_v0 = func_80047EA0_48AA0(&func_80105CC0_3D8DB0, 0xA, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->unk_18, sizeof(unkStruct02));
    temp_v0->unk_8C = temp_v0_2;
    temp_v0_2->unk_00.x = arg0->unk_0C.x;
    temp_v0_2->unk_00.y = arg0->unk_0C.y;
    temp_v0_2->unk_00.z = arg0->unk_0C.z;
    return temp_v0;
}

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80105F20_3D9010);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801060D0_3D91C0);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010615C_3D924C);

void func_80106240_3D9330(void) {
    func_800FC8C4(&D_80105540);
}

void func_80106260_3D9350(s32 arg0, unkStruct05* arg1, s32 arg2, f32 arg3) {
    arg3 = arg3 + 0.5f;
    if (arg2 & 9) {
        func_800EC1E4(&D_80105540, arg0 + 0xC, &D_80105540, arg3);
    } else {
        func_800EC1E4(&D_80105540, arg1->unk_24 + 0xC, &D_80105540, arg3);
    }
}

void func_801062C0_3D93B0(s32 arg0, unkStruct05* arg1, s32 arg2, f32 arg3) {
    if (arg2 & 9) {
        func_800EBF2C(&D_80105540, arg0 + 0xC, &D_80105540);
    } else {
        func_800EBF2C(&D_80105540, arg1->unk_24 + 0xC, &D_80105540);
    }
}

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80106308_3D93F8);

unkStruct03* func_8010645C_3D954C(s32 arg0, s32 arg1) {
    unkStruct03* temp_v0;
    unkStruct06* temp_v0_2;

    temp_v0 = func_80047EA0_48AA0(&func_80106308_3D93F8, 0xA, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->unk_18, sizeof(unkStruct06));
    temp_v0->unk_8C = temp_v0_2;
    temp_v0_2->unk_00 = arg0;
    temp_v0_2->unk_04 = arg1;
    return temp_v0;
}

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801064C8_3D95B8);

void* func_80106740_3D9830(s32 arg0) {
    object* temp_v0;

    temp_v0 = func_800D8010(arg0 & 0xFF, 0);
    func_8001C258_1CE58(*temp_v0->unk3C->unk40, 0x180, 0);
    func_8001C8E4_1D4E4(*temp_v0->unk3C->unk40, 0x1800);
    func_8001C448_1D048(*temp_v0->unk3C->unk40);
    func_800D8944(temp_v0);
    func_800D8F0C(temp_v0);
    func_8001C814_1D414(*temp_v0->unk3C->unk40, 2, 1);
    return temp_v0;
}

void func_801067D4_3D98C4(object* arg0, HuVec3F * arg1) {
    func_800D8E88();
    func_8001C814_1D414(*arg0->unk3C->unk40, 3, 0);
    HuVecCopy3F(&arg0->coords, arg1);
}

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80106828_3D9918);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80107188_3DA278);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801079B8_3DAAA8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80107EBC_3DAFAC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801084A4_3DB594);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80108550_3DB640);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80109404_3DC4F4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80109888_3DC978);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010A210_3DD300);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010AAB0_3DDBA0);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010AD48_3DDE38);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010AFB4_3DE0A4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010B130_3DE220);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010B480_3DE570);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010B4C0_3DE5B0);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010B528_3DE618);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010B53C_3DE62C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010B54C_3DE63C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010BCD4_3DEDC4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010CE68_3DFF58);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010D424_3E0514);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010D95C_3E0A4C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010D9F4_3E0AE4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DA84_3E0B74);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DB00_3E0BF0);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DB2C_3E0C1C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DC04_3E0CF4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DCA8_3E0D98);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DD3C_3E0E2C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DDEC_3E0EDC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010DF68_3E1058);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E008_3E10F8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E1B4_3E12A4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E2CC_3E13BC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E2F8_3E13E8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E348_3E1438);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E3F8_3E14E8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E574_3E1664);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E614_3E1704);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E7C0_3E18B0);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E8D8_3E19C8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E904_3E19F4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010E954_3E1A44);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010EA74_3E1B64);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010EAD4_3E1BC4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010EB44_3E1C34);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010EB88_3E1C78);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010EC78_3E1D68);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010ED20_3E1E10);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010EDA0_3E1E90);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010EFBC_3E20AC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010F12C_3E221C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8010F99C_3E2A8C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80110068_3E3158);

void func_80110B7C_3E3C6C(void) {
    unkStruct07* temp_s0;

    temp_s0 = func_800F375C(-1);
    if (func_800F3750() == 0 && !(temp_s0->unk_17 & 4)) {
        func_800F38DC(-1, -1, 2);
        func_80110068_3E3158(0);
    }
}

void func_80110BD8_3E3CC8(void) {
    unkStruct07* temp_s0;

    temp_s0 = func_800F375C(-1);
    if ((func_800F3750() == 1) && !(temp_s0->unk_17 & 4)) {
        func_800F38DC(-1, -1, 2);
        func_80110068_3E3158(1);
    }
}

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80110C3C_3E3D2C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80111DFC_3E4EEC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801123E8_3E54D8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801124D8_3E55C8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80112514_3E5604);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80112590_3E5680);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801125CC_3E56BC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8011264C_3E573C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801129C8_3E5AB8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80112BB4_3E5CA4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80112DA0_3E5E90);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801135D8_3E66C8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801138D0_3E69C0);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8011390C_3E69FC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80113CAC_3E6D9C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801147FC_3E78EC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80115850_3E8940);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801159F8_3E8AE8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80116484_3E9574);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80117480_3EA570);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80117624_3EA714);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801179AC_3EAA9C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80117D3C_3EAE2C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80117DDC_3EAECC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80117E7C_3EAF6C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80117ED8_3EAFC8);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80117FFC_3EB0EC);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80118058_3EB148);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80118178_3EB268);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801181C4_3EB2B4);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80118210_3EB300);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_8011825C_3EB34C);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801182A8_3EB398);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_801182E4_3EB3D4);

void func_80118320_3EB410(void) {
}

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80118328_3EB418);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80118414_3EB504);

INCLUDE_ASM(s32, "overlays/board_gate_guy/3D8AC0", func_80118530_3EB620);
