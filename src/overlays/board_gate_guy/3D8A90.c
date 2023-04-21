#include "GateGuy.h"

typedef struct board_overlay_entrypoint {
    s16 index;
    void* fn;
} board_overlay_entrypoint;

extern board_overlay_entrypoint D_801186E0_3EB7D0[];

void func_801059A0_3D8A90(void) {
    func_800359E0_365E0(&D_801186E0_3EB7D0, D_800A1764_A2364);
}
