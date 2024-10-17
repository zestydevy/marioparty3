#include "common.h"
#include "common_structs.h"

PlayerData* GetPlayerStruct(s32 playerIndex);

s16 GetCurrentPlayerIndex(void) {
    return gCurrentPlayerIndex;
}

PlayerData* GetPlayerStruct(s32 playerIndex) {
    if (playerIndex < 0) {
        playerIndex = GetCurrentPlayerIndex();
    }
    return &gPlayers[playerIndex];
}

s32 func_800F217C_105D9C(s16 arg0) {
    return arg0 == gCurrentPlayerIndex;
}

s32 func_800F2198_105DB8(s16 arg0) {
    return GetPlayerStruct(arg0)->flags & 1;
}

void AdjustPlayerCoins(s32 playerIndex, s32 coinsToAdd) {
    PlayerData* player;

    player = GetPlayerStruct(playerIndex);
    player->coins += coinsToAdd;
    if (player->coins >= 1000) {
        player->coins = 999;
    }
    if (player->coins < 0) {
        player->coins = 0;
    }
    if (player->maxCoins <= player->coins) {
        player->maxCoins = player->coins;
    }
}

s32 PlayerHasCoins(s32 playerIndex, s32 arg1) {
    return (GetPlayerStruct(playerIndex)->coins < arg1) ^ 1;
}

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2260_105E80);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F22C0_105EE0);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2304_105F24);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2388_105FA8);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F244C_10606C);

void func_800F2484_1060A4(void) {
}

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F248C_1060AC);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F24FC_10611C);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F25B4_1061D4);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F25D8_1061F8);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2624_106244);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2660_106280);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2690_1062B0);

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F26E8_106308);

void func_800F27C4_1063E4(void) {
}
