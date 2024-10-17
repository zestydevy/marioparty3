#include "common.h"

extern s8 gTotalTurns;
extern s8 gCurrentTurn;
u8 rand8(void);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECAD0_1006F0);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECB14_100734);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECB58_100778);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECB90_1007B0);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECBD0_1007F0);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECC0C_10082C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECC28_100848);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECC54_100874);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECD00_100920);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECDD4_1009F4);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECE4C_100A6C);

s16 RNGPercentChance(s8 arg0) {
    u8 randByte = rand8();
    s32 chance = arg0;
    
    return (randByte* 99 >> 8) < chance;
}

s16 GetTurnsElapsed(void) {
    return (gTotalTurns - gCurrentTurn) + 1;
}

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECF18_100B38);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECF9C_100BBC);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECFC8_100BE8);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED128_100D48);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED1E4_100E04);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED20C_100E2C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED290_100EB0);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED35C_100F7C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED410_101030);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED518_101138);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED5E0_101200);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED694_1012B4);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED75C_10137C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED810_101430);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED91C_10153C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED998_1015B8);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED9F8_101618);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800EDA58_101678);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800EDAF0_101710);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800EDB98_1017B8);
