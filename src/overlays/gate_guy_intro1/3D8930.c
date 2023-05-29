#include "common.h"

typedef struct board_overlay_entrypoint {
    s16 index;
    void* fn;
} board_overlay_entrypoint;

void func_800359E0_365E0(void*, s16);
extern s16 D_800A1764_A2364;
extern board_overlay_entrypoint D_80105AE0_3D8A70[];

void func_801059A0_3D8930(void) {
    //func_800359E0_365E0 is ExecBoardScene from mp1
    func_800359E0_365E0(D_80105AE0_3D8A70, D_800A1764_A2364);
}