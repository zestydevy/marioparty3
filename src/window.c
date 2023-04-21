#include "common.h"

typedef struct TextWindow {
/* 0x00 */ u8 unk_00;
/* 0x01 */ char unk_01[3];
/* 0x04 */ char unk_04;
/* 0x05 */ u8 unk_05;
/* 0x06 */ char unk_06[0x0A];
/* 0x10 */ u8 unk_10;
/* 0x11 */ char unk_11[3];
/* 0x14 */ char unk_14[4];
/* 0x18 */ s16 unk_18;
/* 0x1A */ s16 unk_1A;
/* 0x1C */ char unk_1C[0x10];
/* 0x2C */ s16 unk_2C;
/* 0x2E */ s16 unk_2E;
/* 0x30 */ char unk_30[4];
/* 0x34 */ s16 unk_34;
/* 0x36 */ char unk_36[0x77];
/* 0xAD */ s8 usingStringIDBool[5]; //unknown size
/* 0xB2 */ s8 unk_B2[6]; //unknown size
/* 0xB8 */ s32 unk_B8[4];
/* 0xC8 */ char unk_C8[0x1B4];
} TextWindow; //sizeof 0x27C

extern TextWindow* D_800CC69C;

s32 func_800364DC_370DC(u32);
void func_800365E8_371E8(u32);

INCLUDE_ASM(s32, "window", func_8005A0F0_5ACF0);

INCLUDE_ASM(s32, "window", func_8005A32C_5AF2C);

INCLUDE_ASM(s32, "window", func_8005A37C_5AF7C);

INCLUDE_ASM(s32, "window", func_8005A3C0_5AFC0);

INCLUDE_ASM(s32, "window", func_8005A428_5B028);

INCLUDE_ASM(s32, "window", func_8005A51C_5B11C);

INCLUDE_ASM(s32, "window", func_8005A54C_5B14C);

INCLUDE_ASM(s32, "window", func_8005A580_5B180);

INCLUDE_ASM(s32, "window", func_8005A5B0_5B1B0);

INCLUDE_ASM(s32, "window", func_8005A5EC_5B1EC);

INCLUDE_ASM(s32, "window", func_8005A61C_5B21C);

INCLUDE_ASM(s32, "window", func_8005A674_5B274);

INCLUDE_ASM(s32, "window", func_8005A6B0_5B2B0);

INCLUDE_ASM(s32, "window", func_8005A968_5B568);

INCLUDE_ASM(s32, "window", func_8005B040_5BC40);

INCLUDE_ASM(s32, "window", func_8005B238_5BE38);

INCLUDE_ASM(s32, "window", func_8005B43C_5C03C);

INCLUDE_ASM(s32, "window", func_8005B5EC_5C1EC);

INCLUDE_ASM(s32, "window", func_8005B614_5C214);

INCLUDE_ASM(s32, "window", func_8005B63C_5C23C);

INCLUDE_ASM(s32, "window", func_8005B68C_5C28C);

void func_8005B6BC_5C2BC(s16 win_id, u32 arg1, s8 arg2) {
    TextWindow* textWindow = &D_800CC69C[win_id];

    if (textWindow->unk_B8[arg2] != 0) {
        if (textWindow->usingStringIDBool[arg2] != 0) {
            func_800365E8_371E8(textWindow->unk_B8[arg2]);
        }
    }
    if (0x80000000 < arg1) {
        textWindow->usingStringIDBool[arg2] = 0;
        textWindow->unk_B8[arg2] = arg1;
    } else {
        textWindow->usingStringIDBool[arg2] = 1;
        textWindow->unk_B8[arg2] = func_800364DC_370DC(arg1);
    }
    textWindow->unk_B2[arg2] = -1;
}

INCLUDE_ASM(s32, "window", func_8005B7B8_5C3B8);

INCLUDE_ASM(s32, "window", func_8005B8F8_5C4F8);

INCLUDE_ASM(s32, "window", func_8005B974_5C574);

INCLUDE_ASM(s32, "window", func_8005BA28_5C628);

INCLUDE_ASM(s32, "window", func_8005BA54_5C654);

INCLUDE_ASM(s32, "window", func_8005BA90_5C690);

INCLUDE_ASM(s32, "window", func_8005BB18_5C718);

INCLUDE_ASM(s32, "window", func_8005BBC0_5C7C0);

INCLUDE_ASM(s32, "window", func_8005BCA4_5C8A4);

INCLUDE_ASM(s32, "window", func_8005BDA8_5C9A8);

INCLUDE_ASM(s32, "window", func_8005BDFC_5C9FC);

INCLUDE_ASM(s32, "window", func_8005BE30_5CA30);

INCLUDE_ASM(s32, "window", func_8005BEE0_5CAE0);

INCLUDE_ASM(s32, "window", func_8005BF70_5CB70);

INCLUDE_ASM(s32, "window", func_8005C02C_5CC2C);

INCLUDE_ASM(s32, "window", func_8005C060_5CC60);

INCLUDE_ASM(s32, "window", func_8005C154_5CD54);

INCLUDE_ASM(s32, "window", func_8005C190_5CD90);

INCLUDE_ASM(s32, "window", func_8005CC18_5D818);

INCLUDE_ASM(s32, "window", func_8005CC3C_5D83C);

INCLUDE_ASM(s32, "window", func_8005CCF0_5D8F0);

INCLUDE_ASM(s32, "window", func_8005CD38_5D938);

INCLUDE_ASM(s32, "window", func_8005CD84_5D984);

INCLUDE_ASM(s32, "window", func_8005CE10_5DA10);

INCLUDE_ASM(s32, "window", func_8005CEB0_5DAB0);

INCLUDE_ASM(s32, "window", func_8005CF94_5DB94);

INCLUDE_ASM(s32, "window", func_8005CFE0_5DBE0);

INCLUDE_ASM(s32, "window", func_8005D294_5DE94);

INCLUDE_ASM(s32, "window", func_8005D2D4_5DED4);

INCLUDE_ASM(s32, "window", func_8005D2FC_5DEFC);

INCLUDE_ASM(s32, "window", func_8005D30C_5DF0C);

INCLUDE_ASM(s32, "window", func_8005D83C_5E43C);

INCLUDE_ASM(s32, "window", func_8005DAA4_5E6A4);

INCLUDE_ASM(s32, "window", func_8005DC94_5E894);

INCLUDE_ASM(s32, "window", func_8005DD14_5E914);

INCLUDE_ASM(s32, "window", func_8005DD54_5E954);

INCLUDE_ASM(s32, "window", func_8005DDDC_5E9DC);

INCLUDE_ASM(s32, "window", func_8005E0C0_5ECC0);

INCLUDE_ASM(s32, "window", func_8005E1A8_5EDA8);

INCLUDE_ASM(s32, "window", func_8005E1D8_5EDD8);

INCLUDE_ASM(s32, "window", func_8005E348_5EF48);

INCLUDE_ASM(s32, "window", func_8005EEE4_5FAE4);

INCLUDE_ASM(s32, "window", func_8005F364_5FF64);

INCLUDE_ASM(s32, "window", func_8005F524_60124);

INCLUDE_ASM(s32, "window", func_8005F698_60298);

INCLUDE_ASM(s32, "window", func_8005F744_60344);

INCLUDE_ASM(s32, "window", func_8005F784_60384);

INCLUDE_ASM(s32, "window", func_8005F7F4_603F4);

INCLUDE_ASM(s32, "window", func_8005F904_60504);

INCLUDE_ASM(s32, "window", func_8005F918_60518);

INCLUDE_ASM(s32, "window", func_8005FA90_60690);

INCLUDE_ASM(s32, "window", func_8005FBA4_607A4);

INCLUDE_ASM(s32, "window", func_8005FBF8_607F8);

INCLUDE_ASM(s32, "window", func_8005FE54_60A54);

INCLUDE_ASM(s32, "window", func_8005FE90_60A90);

INCLUDE_ASM(s32, "window", func_8005FFA8_60BA8);

INCLUDE_ASM(s32, "window", func_800600C0_60CC0);

INCLUDE_ASM(s32, "window", func_8006010C_60D0C);

void func_80060144_60D44(void) {
}

INCLUDE_ASM(s32, "window", func_8006014C_60D4C);

INCLUDE_ASM(s32, "window", func_80060174_60D74);

INCLUDE_ASM(s32, "window", func_800601BC_60DBC);

INCLUDE_ASM(s32, "window", func_8006022C_60E2C);

INCLUDE_ASM(s32, "window", func_80060290_60E90);

INCLUDE_ASM(s32, "window", func_8006034C_60F4C);

INCLUDE_ASM(s32, "window", func_80060388_60F88);

INCLUDE_ASM(s32, "window", func_80060394_60F94);

INCLUDE_ASM(s32, "window", func_800604A8_610A8);

INCLUDE_ASM(s32, "window", func_800605A4_611A4);

INCLUDE_ASM(s32, "window", func_80060848_61448);

INCLUDE_ASM(s32, "window", func_80060858_61458);

INCLUDE_ASM(s32, "window", func_80060880_61480);

INCLUDE_ASM(s32, "window", func_80060C14_61814);

INCLUDE_ASM(s32, "window", func_80060DEC_619EC);

INCLUDE_ASM(s32, "window", func_80060EA8_61AA8);

INCLUDE_ASM(s32, "window", func_8006105C_61C5C);

INCLUDE_ASM(s32, "window", func_800610E0_61CE0);

INCLUDE_ASM(s32, "window", func_80061100_61D00);

INCLUDE_ASM(s32, "window", func_80061188_61D88);

INCLUDE_ASM(s32, "window", func_80061388_61F88);

INCLUDE_ASM(s32, "window", func_800615B8_621B8);

INCLUDE_ASM(s32, "window", func_80061934_62534);

INCLUDE_ASM(s32, "window", func_80061A5C_6265C);
