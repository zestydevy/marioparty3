#include "common.h"
#include "obj.h"

typedef struct CharPortraitRelated {
    s8 unk_00;
    s8 unk_01;
    char unk_02[2];
    char unk_04;
    u8 unk_05;
    s8 unk_06;
    s8 unk_07;
    s16 unk_08;
    char unk_09[0x26];
    s32 unk_30;
    char unk_34[0x32];
    u16 unk_66;
    s16 unk_68;
    char unk_6A[2];
} CharPortraitRelated; //sizeof 0x6C

void func_800F2E30_106A50(s32);
void func_800F39C0_1075E0(s32);
void func_800F3A80_1076A0(s32);
void func_800F3BD0_1077F0(s32);
void func_800F3D70_107990(s32);
void func_800F3E34_107A54(s32);
void func_800F3F0C_107B2C(s32);
void func_800F3FF4_107C14(s32);
void func_800F4798_1083B8(s32, s32);
void func_800F4874_108494(s32, s16, s16);
void func_80047B80_48780(Process*, s32);
void func_800F4190_107DB0(void);
void func_800F43FC_10801C(s32);
void func_800F3400_107020(void);
extern s16 D_80101794_1153B4[2][2];
extern s32 D_801055E8[];
extern CharPortraitRelated D_801057E0[4];
extern s32 D_80101780_1153A0;
extern s32 D_80101784_1153A4;
extern Process* D_80105580;
extern s16 D_801055C2;
extern s16 D_801055C4;
extern s16 D_801055FC[4];
extern s16 D_80105608[4][3];


INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F2E30_106A50);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3370_106F90);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3400_107020);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F39C0_1075E0);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3A80_1076A0);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3BD0_1077F0);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3D70_107990);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3E34_107A54);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3F0C_107B2C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F3FF4_107C14);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4190_107DB0);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4348_107F68);

void func_800F43FC_10801C(s32 arg0) {
    s32 i;
    CharPortraitRelated* temp_s2;

    temp_s2 = &D_801057E0[arg0];

    for (i = 0; i < 2; i++) {
        temp_s2->unk_02[i] = 0;
    }
    temp_s2->unk_66 = gPlayers[arg0].coins;
    temp_s2->unk_68 = gPlayers[arg0].stars;
    temp_s2->unk_05 = 0;
    temp_s2->unk_01 = -1;
    temp_s2->unk_07 = temp_s2->unk_06 = temp_s2->unk_08 = -1;
    temp_s2->unk_00 = 0;
    func_800F3D70_107990(arg0);
    func_800F4798_1083B8(arg0, 0);
    func_800F4874_108494(arg0, D_80101794_1153B4[arg0][0], D_80101794_1153B4[arg0][1]);
    func_800F39C0_1075E0(arg0);
    func_800F3A80_1076A0(arg0);
    func_800F3BD0_1077F0(arg0);
    func_800F3E34_107A54(arg0);
    func_800F3F0C_107B2C(arg0);
    func_800F3FF4_107C14(arg0);
    func_800F2E30_106A50(arg0);
    D_801055E8[arg0] = 0;
    temp_s2->unk_30 = 0;
}

void func_800F453C_10815C(void) {
    s32 i, j;

    func_800F4190_107DB0();
    for (i = 0; i < 4; i++) {
        func_800F43FC_10801C(i);
    }
    D_80105580 = HuObjPrcCreate(&func_800F3400_107020, 0, 0x2000, 0);
    func_80047B80_48780(D_80105580, 0x80);
    D_801055C4 = -1;
    D_801055C2 = -1;
    D_80101780_1153A0 = -1;
    D_80101784_1153A4 = -1;
    for (i = 0; i < 4; i++) {
        D_801055FC[i] = -1;
        for (j = 0; j < 3; j++) {
            D_80105608[i][j] = -1;
        }
    }
}

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F462C_10824C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4730_108350);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4798_1083B8);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F482C_10844C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4850_108470);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4874_108494);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4924_108544);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4960_108580);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F4994_1085B4);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5278_108E98);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F52C4_108EE4);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F53B4_108FD4);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F54FC_10911C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5644_109264);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F56A8_1092C8);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5828_109448);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F591C_10953C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F59B4_1095D4);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5BF4_109814);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5D44_109964);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5D60_109980);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5D78_109998);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5D8C_1099AC);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5DD8_1099F8);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5E24_109A44);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5E30_109A50);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5EF0_109B10);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5F4C_109B6C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5F60_109B80);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5F7C_109B9C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F5F98_109BB8);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F63F0_10A010);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F641C_10A03C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F64E4_10A104);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F66DC_10A2FC);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6724_10A344);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6748_10A368);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6780_10A3A0);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6848_10A468);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F688C_10A4AC);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F68E0_10A500);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6928_10A548);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F696C_10A58C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F69B0_10A5D0);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F69F8_10A618);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6A40_10A660);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6A88_10A6A8);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6AA4_10A6C4);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6AD0_10A6F0);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6BC4_10A7E4);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6E4C_10AA6C);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F6ECC_10AAEC);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F70F8_10AD18);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F7108_10AD28);

INCLUDE_ASM(s32, "overlays/shared_board/106A50", func_800F7114_10AD34);
