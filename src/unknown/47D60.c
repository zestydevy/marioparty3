#include "common.h"

void func_8000BA00_C600(void);                             /* extern */
void func_800166D0_172D0(void);                            /* extern */
void func_8001AFE4_1BBE4(void);                            /* extern */
void func_80021AF4_226F4(void);                            /* extern */
void func_80037190_37D90(void);                            /* extern */
void omDestroyObjMan(void);                                /* extern */
extern s8 D_800A1762_A2362;
extern u16 D_800B23C0;
extern u16 D_800CD050;
extern s8 D_800CD280;
s32 omOvlGotoEx(s32, s16, u16);
extern s16 omovlhisidx;
extern omOvlHisData omovlhis[12];

typedef struct OverlayInfo {
    u8 *rom_start;
    u8 *rom_end;
    u8 *ram_start;
    u8 *code_start;
    u8 *code_end;
    u8 *data_start;
    u8 *data_end;
    u8 *bss_start;
    u8 *bss_end;
} OverlayInfo; // sizeof 0x24

INCLUDE_ASM(s32, "unknown/47D60", omInitObjMan);

INCLUDE_ASM(s32, "unknown/47D60", omDestroyObjMan);

INCLUDE_ASM(s32, "unknown/47D60", omAddObj);

INCLUDE_ASM(s32, "unknown/47D60", omSetObjPrio);

INCLUDE_ASM(s32, "unknown/47D60", omInsertObj);

INCLUDE_ASM(s32, "unknown/47D60", omDelObj);

INCLUDE_ASM(s32, "unknown/47D60", omSetStat);

INCLUDE_ASM(s32, "unknown/47D60", omSetStatBit);

INCLUDE_ASM(s32, "unknown/47D60", omResetStatBit);

INCLUDE_ASM(s32, "unknown/47D60", omPrcSetStat);

INCLUDE_ASM(s32, "unknown/47D60", omPrcSetStatBit);

INCLUDE_ASM(s32, "unknown/47D60", omPrcResetStatBit);

INCLUDE_ASM(s32, "unknown/47D60", omSetTra);

INCLUDE_ASM(s32, "unknown/47D60", omSetRot);

INCLUDE_ASM(s32, "unknown/47D60", omSetSca);

INCLUDE_ASM(s32, "unknown/47D60", func_80047C0C_4880C);

INCLUDE_ASM(s32, "unknown/47D60", func_80047CDC_488DC);

INCLUDE_ASM(s32, "unknown/47D60", func_80047D4C_4894C);

INCLUDE_ASM(s32, "unknown/47D60", func_80047DBC_489BC);

INCLUDE_ASM(s32, "unknown/47D60", func_80047DD4_489D4);

INCLUDE_ASM(s32, "unknown/47D60", func_80047DFC_489FC);

INCLUDE_ASM(s32, "unknown/47D60", func_80047E5C_48A5C);

INCLUDE_ASM(s32, "unknown/47D60", func_80047E90_48A90);

INCLUDE_ASM(s32, "unknown/47D60", omAddPrcObj);

INCLUDE_ASM(s32, "unknown/47D60", func_80047F50_48B50);

INCLUDE_ASM(s32, "unknown/47D60", omDelPrcObj);

INCLUDE_ASM(s32, "unknown/47D60", omDestroyPrcObj);

INCLUDE_ASM(s32, "unknown/47D60", omPrcSetDestructor);

s32 omOvlCallEx(s32 arg0, s16 arg1, u16 arg2) {
    omOvlHisData* history;
    s32 ret;

    if (omovlhisidx < ARRAY_COUNT(omovlhis)) {
        history = &omovlhis[++omovlhisidx];
        history->overlayID = arg0;
        history->event = arg1;
        history->stat = arg2;
        omOvlGotoEx(arg0, arg1, arg2);
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 omOvlReturnEx(s16 level) {
    omovlhisidx -= level;
    
    if (omovlhisidx < 0) {
        omovlhisidx = 0;
        omOvlGotoEx(omovlhis[0].overlayID, omovlhis[0].event, omovlhis[0].stat);
        return 0;
    }
    omOvlGotoEx(omovlhis[omovlhisidx].overlayID, omovlhis[omovlhisidx].event, omovlhis[omovlhisidx].stat);
    return 1;
}

INCLUDE_ASM(s32, "unknown/47D60", omOvlGotoEx);

void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat) {
    s32 ovlhisIndex = omovlhisidx - arg0;
    omOvlHisData* history;
    
    if (ovlhisIndex >= 0) {
        history = &omovlhis[ovlhisIndex];
        history->overlayID = overlay;
        history->event = event;
        history->stat = stat;
    }
}

void omOvlKill(void) {
    D_800A1762_A2362 = 4;
    D_800B23C0 = D_800CD050;
    func_80037190_37D90();
    func_8001AFE4_1BBE4();
    func_80021AF4_226F4();
    omDestroyObjMan();
    func_8000BA00_C600();
    func_800166D0_172D0();
    D_800CD280 = 1;
}

INCLUDE_ASM(s32, "unknown/47D60", omMain);

INCLUDE_ASM(s32, "unknown/47D60", func_80048E88_49A88);

INCLUDE_ASM(s32, "unknown/47D60", func_80048EE8_49AE8);

INCLUDE_ASM(s32, "unknown/47D60", func_800499B0_4A5B0);

INCLUDE_ASM(s32, "unknown/47D60", func_80049F98_4AB98);

INCLUDE_ASM(s32, "unknown/47D60", func_80049FB8_4ABB8);

INCLUDE_ASM(s32, "unknown/47D60", func_8004A0E0_4ACE0);

INCLUDE_ASM(s32, "unknown/47D60", func_8004A208_4AE08);

INCLUDE_ASM(s32, "unknown/47D60", func_8004A354_4AF54);

INCLUDE_ASM(s32, "unknown/47D60", func_8004A444_4B044);

INCLUDE_ASM(s32, "unknown/47D60", func_8004A468_4B068);

INCLUDE_ASM(s32, "unknown/47D60", func_8004A49C_4B09C);
