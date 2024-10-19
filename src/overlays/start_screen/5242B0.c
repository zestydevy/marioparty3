#include "common.h"

Process* omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize);
extern Process* D_80114EA0;
void func_80105FC0_5245F0(void*);
void func_801061C0_5247F0(void);

void func_80105C80_5242B0(void) {
    func_801061C0_5247F0();
}

void func_80105C9C_5242CC(void) {
    func_80105C80_5242B0();
    D_80114EA0 = omAddPrcObj(&func_80105FC0_5245F0, 0x5000, 0x800, 0);
}

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_80105CD8_524308);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_80105D14_524344);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_80105D6C_52439C);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_80105F68_524598);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_80105FC0_5245F0);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_80106188_5247B8);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_801061C0_5247F0);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_801061CC_5247FC);

INCLUDE_ASM(s32, "overlays/start_screen/5242B0", func_801061D8_524808);
